#include "CityDataManager.h"
#include <algorithm>

void CityDataManager::addSensorReading(int time, const std::string& type, double val) {
    sensorReadings.push_back({time, type, val});
}

void CityDataManager::removeOutdatedSensorReading(int thresholdTime) {
    sensorReadings.erase(
        std::remove_if(sensorReadings.begin(), sensorReadings.end(), [thresholdTime](const SensorReading& r) {
            return r.timestamp < thresholdTime;
        }),
        sensorReadings.end()
    );
}

void CityDataManager::displaySensorReadings() const {
    std::cout << "\n--- Sensor Readings (Vector Container) ---\n";
    for (const auto& r : sensorReadings) {
        std::cout << "Time: " << r.timestamp << " | Type: " << r.sensorType << " | Value: " << r.value << "\n";
    }
}

void CityDataManager::addHistoricalLog(const std::string& logEntry) {
    historicalLogs.push_back(logEntry);
}

void CityDataManager::displayHistoricalLogs() const {
    std::cout << "\n--- Historical City Logs (Linked List Container) ---\n";
    for (const auto& log : historicalLogs) {
        std::cout << "[LOG]: " << log << "\n";
    }
}

void CityDataManager::sortReadings() {
    std::sort(sensorReadings.begin(), sensorReadings.end(), [](const SensorReading& a, const SensorReading& b) {
        return a.value < b.value;
    });
}

void CityDataManager::analyzeReadings() const {
    if (sensorReadings.empty()) return;
    auto minIt = std::min_element(sensorReadings.begin(), sensorReadings.end(), [](const SensorReading& a, const SensorReading& b) {
        return a.value < b.value;
    });
    auto maxIt = std::max_element(sensorReadings.begin(), sensorReadings.end(), [](const SensorReading& a, const SensorReading& b) {
        return a.value < b.value;
    });
    std::cout << "Lowest Sensor Value: " << minIt->value << " (" << minIt->sensorType << ")\n";
    std::cout << "Highest Sensor Value: " << maxIt->value << " (" << maxIt->sensorType << ")\n";
}

int CityDataManager::countCriticalAlerts(double threshold) const {
    return std::count_if(sensorReadings.begin(), sensorReadings.end(), [threshold](const SensorReading& r) {
        return r.value > threshold;
    });
}