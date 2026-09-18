#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <string>
#include <vector>
#include "Engineer.h"
#include "CityDataManager.h"

class FileManager {
public:
    static void saveEngineers(const std::string& filename, const std::vector<Engineer>& engineers);
    static void saveLogs(const std::string& filename, const std::list<std::string>& logs);
    static void exportCSV(const std::string& filename, const std::vector<SensorReading>& readings);
    static void loadConfig(const std::string& filename);
};

#endif