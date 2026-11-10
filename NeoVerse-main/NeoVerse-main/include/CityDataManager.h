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
    std::vector<SensorReading> sensorReadings;
    std::list<std::string> historicalLogs;

public:
    void addSensorReading(int time, const std::string& type, double val);
    void removeOutdatedSensorReading(int thresholdTime);
    void displaySensorReadings() const;

    void addHistoricalLog(const std::string& logEntry);
    void displayHistoricalLogs() const;

    void sortReadings();
    void analyzeReadings() const;
    int countCriticalAlerts(double threshold) const;

    // NEW: expose readings for CSV export
    const std::vector<SensorReading>& getReadings() const { return sensorReadings; }
};

#endif