#include "EventManager.h"
#include <map>
#include <algorithm>
#include <ctime>

void EventManager::pushStandardEvent(int id, const std::string& desc, int severity, EventType t) {
    standardEventQueue.emplace(id, desc, severity, t);
}

void EventManager::pushEmergencyOverride(int id, const std::string& desc, int severity,
                                         EventType t, const std::string& code) {
    emergencyOverrideStack.emplace(id, desc, severity, t, code);
}

void EventManager::processNextStandardEvent() {
    if (!standardEventQueue.empty()) {
        Event e = standardEventQueue.front();
        standardEventQueue.pop();
        e.display();
    } else {
        std::cout << "No standard events in queue.\n";
    }
}

void EventManager::processNextEmergencyOverride() {
    if (!emergencyOverrideStack.empty()) {
        EmergencyEvent e = emergencyOverrideStack.top();
        emergencyOverrideStack.pop();
        e.display();

        resolvedEmergencies.push_back(e);
        double elapsed = std::difftime(std::time(nullptr), e.getTimestamp());
        responseTimesSeconds.push_back(elapsed);
    } else {
        std::cout << "No emergency overrides pending.\n";
    }
}

bool EventManager::hasEmergencies() const { return !emergencyOverrideStack.empty(); }
bool EventManager::hasStandardEvents() const { return !standardEventQueue.empty(); }

void EventManager::processEventsByMinSeverity(int minSeverity) {
    std::stack<EmergencyEvent> temp;
    int processed = 0;
    while (!emergencyOverrideStack.empty()) {
        EmergencyEvent e = emergencyOverrideStack.top();
        emergencyOverrideStack.pop();
        if (e.getSeverity() >= minSeverity) {
            e.display();
            resolvedEmergencies.push_back(e);
            responseTimesSeconds.push_back(
                std::difftime(std::time(nullptr), e.getTimestamp()));
            ++processed;
        } else {
            temp.push(e);
        }
    }
    while (!temp.empty()) {
        emergencyOverrideStack.push(temp.top());
        temp.pop();
    }
    if (processed == 0) {
        std::cout << "No emergencies met the minimum severity.\n";
    }
}

void EventManager::displayQueues() const {
    std::cout << "Active Emergencies Stack Size: " << emergencyOverrideStack.size() << "\n";
    std::cout << "Standard Event Queue Size: " << standardEventQueue.size() << "\n";
}

std::string EventManager::mostCommonEmergencyType() const {
    std::map<std::string, int> counts;
    for (const auto& e : resolvedEmergencies) {
        counts[e.getTypeName()]++;
    }
    if (counts.empty()) return "None";

    auto it = std::max_element(counts.begin(), counts.end(),
        [](const std::pair<const std::string, int>& a,
           const std::pair<const std::string, int>& b) { return a.second < b.second; });
    return it->first + " (" + std::to_string(it->second) + ")";
}

double EventManager::averageResponseTimeSeconds() const {
    if (responseTimesSeconds.empty()) return 0.0;
    double sum = 0.0;
    for (double t : responseTimesSeconds) sum += t;
    return sum / static_cast<double>(responseTimesSeconds.size());
}

void EventManager::printLoadReport() const {
    std::cout << "\n=== SECTION 6: LOAD & RESPONSE REPORT ===\n";
    std::cout << "Resolved emergencies: " << resolvedEmergencies.size() << "\n";
    std::cout << "Most common emergency type: " << mostCommonEmergencyType() << "\n";
    std::cout << "Average response time: "
              << averageResponseTimeSeconds() << " seconds\n";
}