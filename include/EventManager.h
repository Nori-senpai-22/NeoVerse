#ifndef EVENT_MANAGER_H
#define EVENT_MANAGER_H

#include <queue>
#include <stack>
#include <string>
#include <iostream>

struct CityEvent {
    int eventID;
    std::string description;
    int severity; // 1 (Low) to 5 (Critical)
};

class EventManager {
private:
    std::queue<CityEvent> standardEventQueue; // FIFO
    std::stack<CityEvent> emergencyOverrideStack; // LIFO

public:
    void pushStandardEvent(int id, const std::string& desc, int severity);
    void pushEmergencyOverride(int id, const std::string& desc, int severity);

    void processNextStandardEvent();
    void processNextEmergencyOverride();

    bool hasEmergencies() const;
    bool hasStandardEvents() const;
    
    void displayQueues() const;
};

#endif