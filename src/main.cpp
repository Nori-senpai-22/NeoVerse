#include <iostream>
#include <vector>
#include <memory>
#include "Engineer.h"
#include "CityComponent.h"
#include "CityDataManager.h"
#include "EventManager.h"
#include "FileManager.h"

int main() {
    // 1. Initialise Engineers for Authentication
    std::vector<Engineer> staff = {
        Engineer("ENG001", "alex_sys", "secure123", "High"),
        Engineer("ENG002", "sarah_ai", "neo2035", "Medium")
    };

    // Run Login System
    if (!Engineer::loginSystem(staff)) {
        return 0; // Terminate if authentication fails
    }

    // 2. City Data Management Demonstration
    CityDataManager dataManager;
    dataManager.addSensorReading(1001, "Temperature", 38.5);
    dataManager.addSensorReading(1002, "Radiation", 12.1);
    dataManager.addSensorReading(1003, "TrafficDensity", 85.0);

    dataManager.addHistoricalLog("AI Control Core online initialized at sector 4.");
    dataManager.addHistoricalLog("Power fluctuation detected in downtown node.");

    dataManager.displaySensorReadings();
    dataManager.displayHistoricalLogs();

    // Run STL algorithm operations
    dataManager.analyzeReadings();
    std::cout << "Critical Alerts Count (> 30.0): " << dataManager.countCriticalAlerts(30.0) << "\n";

    // 3. Object-Oriented Component Architecture & Polymorphism
    std::vector<std::unique_ptr<CityComponent>> cityComponents;
    cityComponents.push_back(std::make_unique<PowerSystem>(101, "Main Grid", 450.0));
    cityComponents.push_back(std::make_unique<TransportSystem>(102, "Hyperway Alpha", 1200));
    cityComponents.push_back(std::make_unique<HealthSystem>(103, "Central Hospital Node", 15));
    cityComponents.push_back(std::make_unique<SecuritySystem>(104, "Perimeter Firewall", 3));

    std::cout << "\n--- City Component Status & Polymorphic Event Processing ---\n";
    for (const auto& comp : cityComponents) {
        std::cout << comp->getStatus() << "\n";
        comp->processEvent(); // Polymorphic call
    }

    // 4. Event Processing (Queue vs Stack)
    EventManager eventMgr;
    eventMgr.pushStandardEvent(501, "Routine traffic update received.", 1);
    eventMgr.pushStandardEvent(502, "Municipal lighting cycle shift.", 1);

    eventMgr.pushEmergencyOverride(901, "CRITICAL: Power grid overload in sector 7!", 5);
    eventMgr.pushEmergencyOverride(902, "CRITICAL: Perimeter breach detected!", 5);

    std::cout << "\n--- Processing Events (LIFO Emergency Overrides First) ---\n";
    while (eventMgr.hasEmergencies()) {
        eventMgr.processNextEmergencyOverride();
    }

    while (eventMgr.hasStandardEvents()) {
        eventMgr.processNextStandardEvent();
    }

    // 5. File Persistence
    FileManager::saveEngineers("engineers.dat", staff);
    FileManager::saveLogs("city_logs.dat", std::list<std::string>{"Log 1: System Boot", "Log 2: Nominal Run"});
    FileManager::loadConfig("config.txt");

    std::cout << "\nNeoVerse Simulation Session Completed Successfully.\n";
    return 0;
}