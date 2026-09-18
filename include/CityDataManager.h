#ifndef CITY_DATA_MANAGER_H
#define CITY_DATA_MANAGER_H

#include <vector>
#include <list>
#include <string>
#include <iostream>

struct SensorReading {
    int timestamp;
    std::string sensorType;
    double value;
};

class CityDataManager {
private:
    std::vector<SensorReading> sensorReadings; // Fast random access
    std::list<std::string> historicalLogs;     // Unbounded dynamic growth

public:
    void addSensorReading(int time, const std::string& type, double val);
    void removeOutdatedSensorReading(int thresholdTime);
    void displaySensorReadings() const;

    void addHistoricalLog(const std::string& logEntry);
    void displayHistoricalLogs() const;

    // STL Algorithm integration methods
    void sortReadings();
    void analyzeReadings() const;
    int countCriticalAlerts(double threshold) const;
};

#endif