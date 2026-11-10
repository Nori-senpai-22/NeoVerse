#ifndef ENGINEER_H
#define ENGINEER_H

#include <string>
#include <vector>

class Engineer {
private:
    std::string engineerID;
    std::string username;
    std::string encryptedPassword; // SHA-256 hex digest
    std::string clearanceLevel;    // Low, Medium, High

    static std::string hashPassword(const std::string& pwd);

public:
    Engineer(std::string id, std::string uname, std::string pwd, std::string clearance);

    std::string getEngineerID() const;
    std::string getUsername() const;
    std::string getClearanceLevel() const;
    bool authenticate(const std::string& uname, const std::string& pwd) const;

    // 3 attempts; returns true on success
    static bool loginSystem(const std::vector<Engineer>& engineers);

    // Clearance gate for privileged actions
    static bool hasClearance(const Engineer& eng, const std::string& required);
};

#endif