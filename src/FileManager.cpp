#include "FileManager.h"
#include <fstream>
#include <iostream>

void FileManager::saveEngineers(const std::string& filename, const std::vector<Engineer>& engineers) {
    std::ofstream outFile(filename);
    if (outFile.is_open()) {
        for (const auto& eng : engineers) {
            outFile << eng.getEngineerID() << "," << eng.getUsername() << "," << eng.getClearanceLevel() << "\n";
        }
        outFile.close();
        std::cout << "Engineers saved to " << filename << "\n";
    }
}

void FileManager::saveLogs(const std::string& filename, const std::list<std::string>& logs) {
    std::ofstream outFile(filename);
    if (outFile.is_open()) {
        for (const auto& log : logs) {
            outFile << log << "\n";
        }
        outFile.close();
        std::cout << "Logs persisted to " << filename << "\n";
    }
}

void FileManager::exportCSV(const std::string& filename, const std::vector<SensorReading>& readings) {
    std::ofstream outFile(filename);
    if (outFile.is_open()) {
        outFile << "Timestamp,SensorType,Value\n";
        // Note: For actual integration, pass vector directly or handle through interface wrapper
        outFile.close();
        std::cout << "Exported report to " << filename << "\n";
    }
}

void FileManager::loadConfig(const std::string& filename) {
    std::ifstream inFile(filename);
    if (inFile.is_open()) {
        std::string line;
        std::cout << "--- Config File Contents (" << filename << ") ---\n";
        while (std::getline(inFile, line)) {
            std::cout << line << "\n";
        }
        inFile.close();
    } else {
        std::cout << "Config file not found. Using defaults.\n";
    }
}