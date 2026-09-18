#include "Engineer.h"
#include <iostream>
#include <algorithm>

Engineer::Engineer(std::string id, std::string uname, std::string pwd, std::string clearance)
    : engineerID(id), username(uname), encryptedPassword(pwd), clearanceLevel(clearance) {}

std::string Engineer::getEngineerID() const { return engineerID; }
std::string Engineer::getUsername() const { return username; }
std::string Engineer::getClearanceLevel() const { return clearanceLevel; }

bool Engineer::authenticate(const std::string& uname, const std::string& pwd) const {
    return (username == uname && encryptedPassword == pwd);
}

bool Engineer::loginSystem(const std::vector<Engineer>& engineers) {
    std::string uname, pwd;
    std::cout << "=== NEOVERSE AI CONTROL CORE LOGIN ===\n";
    std::cout << "Username: ";
    std::cin >> uname;
    std::cout << "Password: ";
    std::cin >> pwd;

    // Using <algorithm> to search for valid credentials
    auto it = std::find_if(engineers.begin(), engineers.end(), [&uname, &pwd](const Engineer& eng) {
        return eng.authenticate(uname, pwd);
    });

    if (it != engineers.end()) {
        std::cout << "Login Successful! Welcome, Engineer " << it->getUsername() 
                  << " [Clearance: " << it->getClearanceLevel() << "]\n";
        return true;
    } else {
        std::cout << "Access Denied: Invalid credentials.\n";
        return false;
    }
}