#include "EventManager.h"

void EventManager::pushStandardEvent(int id, const std::string& desc, int severity) {
    standardEventQueue.push({id, desc, severity});
}

void EventManager::pushEmergencyOverride(int id, const std::string& desc, int severity) {
    emergencyOverrideStack.push({id, desc, severity});
}

void EventManager::processNextStandardEvent() {
    if (!standardEventQueue.empty()) {
        CityEvent e = standardEventQueue.front();
        standardEventQueue.pop();
        std::cout << "[FIFO Standard Event Processed] ID: " << e.eventID << " - " << e.description << "\n";
    } else {
        std::cout << "No standard events in queue.\n";
    }
}

void EventManager::processNextEmergencyOverride() {
    if (!emergencyOverrideStack.empty()) {
        CityEvent e = emergencyOverrideStack.top();
        emergencyOverrideStack.pop();
        std::cout << "[LIFO Emergency Override Resolved] ID: " << e.eventID << " - " << e.description << "\n";
    } else {
        std::cout << "No emergency overrides pending.\n";
    }
}

bool EventManager::hasEmergencies() const { return !emergencyOverrideStack.empty(); }
bool EventManager::hasStandardEvents() const { return !standardEventQueue.empty(); }

void EventManager::displayQueues() const {
    std::cout << "Active Emergencies Stack Size: " << emergencyOverrideStack.size() << "\n";
    std::cout << "Standard Event Queue Size: " << standardEventQueue.size() << "\n";
}