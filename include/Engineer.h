#ifndef ENGINEER_H
#define ENGINEER_H

#include <string>
#include <vector>

class Engineer {
private:
    std::string engineerID;
    std::string username;
    std::string encryptedPassword;
    std::string clearanceLevel; // Low, Medium, High

public:
    Engineer(std::string id, std::string uname, std::string pwd, std::string clearance);

    std::string getEngineerID() const;
    std::string getUsername() const;
    std::string getClearanceLevel() const;
    bool authenticate(const std::string& uname, const std::string& pwd) const;

    // Static login manager using <algorithm> and vector
    static bool loginSystem(const std::vector<Engineer>& engineers);
};

#endif