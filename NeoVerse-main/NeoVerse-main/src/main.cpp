#include <iostream>
#include <vector>
#include <memory>
#include <list>
#include <limits>
#include "Engineer.h"
#include "CityComponent.h"
#include "CityDataManager.h"
#include "EventManager.h"
#include "FileManager.h"

static int nextEventID = 600;

static void printMenu() {
    std::cout << "\n===== NEOVERSE MENU =====\n"
              << " 1. Add sensor reading\n"
              << " 2. Remove outdated sensor readings\n"
              << " 3. Display sensor readings\n"
              << " 4. Sort & analyze readings\n"
              << " 5. Count critical alerts\n"
              << " 6. Add historical log\n"
              << " 7. Display historical logs\n"
              << " 8. Add standard event\n"
              << " 9. Add emergency override\n"
              << "10. Process next emergency\n"
              << "11. Process next standard event\n"
              << "12. Process events by minimum severity\n"
              << "13. Show queues / load report\n"
              << "14. Export sensor readings to CSV\n"
              << "15. Save engineers & logs\n"
              << " 0. Exit\n"
              << "Choice: ";
}

int main() {
    std::vector<Engineer> staff = {
        Engineer("ENG001", "alex_sys", "secure123", "High"),
        Engineer("ENG002", "sarah_ai", "neo2035",   "Medium")
    };

    if (!Engineer::loginSystem(staff)) {
        return 0;
    }

    // Clearance usage demonstration
    bool privileged = false;
    for (const auto& e : staff) {
        if (e.getUsername() == "alex_sys") privileged = Engineer::hasClearance(e, "High");
    }
    if (!privileged) {
        std::cout << "Note: Limited mode (no High-clearance engineer found).\n";
    }

    CityDataManager dataManager;
    EventManager    eventMgr;

    // Seed data
    dataManager.addSensorReading(1001, "Temperature", 38.5);
    dataManager.addSensorReading(1002, "Radiation",   12.1);
    dataManager.addSensorReading(1003, "TrafficDensity", 85.0);
    dataManager.addHistoricalLog("AI Control Core online initialized at sector 4.");

    // Components (polymorphism demo, run at end)
    std::vector<std::unique_ptr<CityComponent>> cityComponents;
    cityComponents.push_back(std::make_unique<PowerSystem>(101, "Main Grid", 450.0));
    cityComponents.push_back(std::make_unique<TransportSystem>(102, "Hyperway Alpha", 1200));
    cityComponents.push_back(std::make_unique<HealthSystem>(103, "Central Hospital Node", 15));
    cityComponents.push_back(std::make_unique<SecuritySystem>(104, "Perimeter Firewall", 3));

    int choice = -1;
    while (choice != 0) {
        printMenu();
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
        case 1: {
            int ts; std::string type; double val;
            std::cout << "Timestamp: "; std::cin >> ts;
            std::cout << "Sensor type: "; std::cin >> type;
            std::cout << "Value: "; std::cin >> val;
            dataManager.addSensorReading(ts, type, val);
            break;
        }
        case 2: {
            int thr;
            std::cout << "Remove readings with timestamp < : ";
            std::cin >> thr;
            dataManager.removeOutdatedSensorReading(thr);
            break;
        }
        case 3: dataManager.displaySensorReadings(); break;
        case 4:
            dataManager.sortReadings();
            dataManager.displaySensorReadings();
            dataManager.analyzeReadings();
            break;
        case 5: {
            double thr;
            std::cout << "Threshold: "; std::cin >> thr;
            std::cout << "Critical alerts: "
                      << dataManager.countCriticalAlerts(thr) << "\n";
            break;
        }
        case 6: {
            std::string log;
            std::cout << "Log entry: ";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::getline(std::cin, log);
            dataManager.addHistoricalLog(log);
            break;
        }
        case 7: dataManager.displayHistoricalLogs(); break;
        case 8: {
            std::string desc; int sev, typeIdx;
            std::cout << "Description: ";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::getline(std::cin, desc);
            std::cout << "Severity (1-5): "; std::cin >> sev;
            std::cout << "Type (0=Power,1=Transport,2=Health,3=Security): ";
            std::cin >> typeIdx;
            eventMgr.pushStandardEvent(nextEventID++, desc, sev,
                                       static_cast<EventType>(typeIdx));
            break;
        }
        case 9: {
            std::string desc, code; int sev, typeIdx;
            std::cout << "Description: ";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::getline(std::cin, desc);
            std::cout << "Severity (1-5): "; std::cin >> sev;
            std::cout << "Type (0=Power,1=Transport,2=Health,3=Security): ";
            std::cin >> typeIdx;
            std::cout << "Emergency code: "; std::cin >> code;
            eventMgr.pushEmergencyOverride(nextEventID++, desc, sev,
                                           static_cast<EventType>(typeIdx), code);
            break;
        }
        case 10: eventMgr.processNextEmergencyOverride(); break;
        case 11: eventMgr.processNextStandardEvent();     break;
        case 12: {
            int minSev;
            std::cout << "Minimum severity: "; std::cin >> minSev;
            eventMgr.processEventsByMinSeverity(minSev);
            break;
        }
        case 13:
            eventMgr.displayQueues();
            eventMgr.printLoadReport();
            break;
        case 14:
            FileManager::exportCSV("readings.csv", dataManager.getReadings());
            break;
        case 15:
            FileManager::saveEngineers("engineers.dat", staff);
            FileManager::saveLogs("city_logs.dat",
                std::list<std::string>{"Log 1: System Boot", "Log 2: Nominal Run"});
            FileManager::loadConfig("config.txt");
            break;
        case 0:
            std::cout << "Exiting NeoVerse.\n";
            break;
        default:
            std::cout << "Unknown choice.\n";
        }
    }

    std::cout << "\n--- City Component Status ---\n";
    for (const auto& comp : cityComponents) {
        std::cout << comp->getStatus() << "\n";
        comp->processEvent();
    }

    return 0;
}