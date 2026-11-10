#include "CityComponent.h"
#include <iostream>
#include <iomanip>

CityComponent::CityComponent(int id, std::string compName)
    : componentID(id), name(compName), activeState(true) {}

void CityComponent::activate() { activeState = true; }
void CityComponent::deactivate() { activeState = false; }

std::string CityComponent::getStatus() const {
    return name + " is " + (activeState ? "ACTIVE" : "INACTIVE");
}

int CityComponent::getComponentID() const { return componentID; }
std::string CityComponent::getName() const { return name; }

// PowerSystem implementation
PowerSystem::PowerSystem(int id, std::string name, double power)
    : CityComponent(id, name), powerLevel(power) {}

void PowerSystem::supplyPower() { std::cout << "Supplying " << powerLevel << "MW of grid power.\n"; }
void PowerSystem::processEvent() { std::cout << "[PowerSystem] Processing energy fluctuation grid-wide.\n"; }
std::string PowerSystem::getStatus() const {
    return CityComponent::getStatus() + " | Power Level: " + std::to_string(powerLevel) + "MW";
}

// TransportSystem implementation
TransportSystem::TransportSystem(int id, std::string name, int flow)
    : CityComponent(id, name), trafficFlow(flow) {}

void TransportSystem::manageTraffic() { std::cout << "Managing autonomous traffic routing. Flow: " << trafficFlow << " v/m.\n"; }
void TransportSystem::processEvent() { std::cout << "[TransportSystem] Rerouting traffic around gridlock.\n"; }
std::string TransportSystem::getStatus() const {
    return CityComponent::getStatus() + " | Traffic Flow: " + std::to_string(trafficFlow) + " v/m";
}

// HealthSystem implementation
HealthSystem::HealthSystem(int id, std::string name, int hospitals)
    : CityComponent(id, name), hospitalCnt(hospitals) {}

void HealthSystem::provideCare() { std::cout << "Dispatching medical drones across " << hospitalCnt << " nodes.\n"; }
void HealthSystem::processEvent() { std::cout << "[HealthSystem] Emergency medical dispatch triggered.\n"; }
std::string HealthSystem::getStatus() const {
    return CityComponent::getStatus() + " | Active Hospitals: " + std::to_string(hospitalCnt);
}

// SecuritySystem implementation
SecuritySystem::SecuritySystem(int id, std::string name, int threat)
    : CityComponent(id, name), threatLevel(threat) {}

void SecuritySystem::monitorCity() { std::cout << "Monitoring security perimeters. Threat Level: " << threatLevel << "/10\n"; }
void SecuritySystem::processEvent() { std::cout << "[SecuritySystem] Lockdown protocols evaluated.\n"; }
std::string SecuritySystem::getStatus() const {
    return CityComponent::getStatus() + " | Threat Index: " + std::to_string(threatLevel);
}

// ---- Event implementation ----
Event::Event(int id, const std::string& desc, int sev, EventType t)
    : eventID(id), description(desc), severity(sev), type(t), timestamp(std::time(nullptr)) {}

int Event::getEventID() const { return eventID; }
std::string Event::getDescription() const { return description; }
int Event::getSeverity() const { return severity; }
EventType Event::getType() const { return type; }
std::time_t Event::getTimestamp() const { return timestamp; }

std::string Event::getTypeName() const {
    switch (type) {
        case EventType::POWER:     return "Power";
        case EventType::TRANSPORT: return "Transport";
        case EventType::HEALTH:    return "Health";
        case EventType::SECURITY:  return "Security";
    }
    return "Unknown";
}

void Event::display() const {
    std::tm* tmPtr = std::localtime(&timestamp);
    std::cout << "[Event " << eventID << "] (" << getTypeName() << ", sev "
              << severity << ") " << description;
    if (tmPtr) {
        std::cout << " @ " << std::put_time(tmPtr, "%Y-%m-%d %H:%M:%S");
    }
    std::cout << "\n";
}

EmergencyEvent::EmergencyEvent(int id, const std::string& desc, int sev,
                               EventType t, const std::string& code)
    : Event(id, desc, sev, t), emergencyCode(code) {}

std::string EmergencyEvent::getEmergencyCode() const { return emergencyCode; }

void EmergencyEvent::display() const {
    std::tm* tmPtr = std::localtime(&timestamp);
    std::cout << "[EMERGENCY " << eventID << " / " << emergencyCode << "] ("
              << getTypeName() << ", sev " << severity << ") " << description;
    if (tmPtr) {
        std::cout << " @ " << std::put_time(tmPtr, "%Y-%m-%d %H:%M:%S");
    }
    std::cout << "\n";
}