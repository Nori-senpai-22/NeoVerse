#ifndef EVENT_MANAGER_H
#define EVENT_MANAGER_H

#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <iostream>
#include "CityComponent.h"

class EventManager {
private:
    std::queue<Event> standardEventQueue;
    std::stack<EmergencyEvent> emergencyOverrideStack;

    // Section 6 statistics
    std::vector<EmergencyEvent> resolvedEmergencies;
    std::vector<double> responseTimesSeconds;

public:
    void pushStandardEvent(int id, const std::string& desc, int severity, EventType t);
    void pushEmergencyOverride(int id, const std::string& desc, int severity,
                               EventType t, const std::string& code);

    void processNextStandardEvent();
    void processNextEmergencyOverride();

    bool hasEmergencies() const;
    bool hasStandardEvents() const;

    void processEventsByMinSeverity(int minSeverity);

    void displayQueues() const;

    // Section 6 reports
    std::string mostCommonEmergencyType() const;
    double averageResponseTimeSeconds() const;
    void printLoadReport() const;
};

#endif