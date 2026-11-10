#ifndef CITY_COMPONENT_H
#define CITY_COMPONENT_H

#include <string>
#include <ctime>

// Abstract Base Class demonstrating Polymorphism & Encapsulation
class CityComponent {
protected:
    int componentID;
    std::string name;
    bool activeState;

public:
    CityComponent(int id, std::string compName);
    virtual ~CityComponent() = default;

    virtual void activate();
    virtual void deactivate();
    virtual std::string getStatus() const;
    virtual void processEvent() = 0; // Pure virtual function

    int getComponentID() const;
    std::string getName() const;
};

// ---- Event hierarchy ----
enum class EventType { POWER = 0, TRANSPORT = 1, HEALTH = 2, SECURITY = 3 };

class Event {
protected:
    int eventID;
    std::string description;
    int severity;        // 1 (Low) to 5 (Critical)
    EventType type;
    std::time_t timestamp;

public:
    Event(int id, const std::string& desc, int sev, EventType t);
    virtual ~Event() = default;

    int getEventID() const;
    std::string getDescription() const;
    int getSeverity() const;
    EventType getType() const;
    std::time_t getTimestamp() const;
    std::string getTypeName() const;

    virtual void display() const;
};

class EmergencyEvent : public Event {
private:
    std::string emergencyCode;
public:
    EmergencyEvent(int id, const std::string& desc, int sev, EventType t,
                   const std::string& code);
    void display() const override;
    std::string getEmergencyCode() const;
};

class PowerSystem : public CityComponent {
private:
    double powerLevel;
public:
    PowerSystem(int id, std::string name, double power);
    void supplyPower();
    void processEvent() override;
    std::string getStatus() const override;
};

class TransportSystem : public CityComponent {
private:
    int trafficFlow;
public:
    TransportSystem(int id, std::string name, int flow);
    void manageTraffic();
    void processEvent() override;
    std::string getStatus() const override;
};

class HealthSystem : public CityComponent {
private:
    int hospitalCnt;
public:
    HealthSystem(int id, std::string name, int hospitals);
    void provideCare();
    void processEvent() override;
    std::string getStatus() const override;
};

class SecuritySystem : public CityComponent {
private:
    int threatLevel;
public:
    SecuritySystem(int id, std::string name, int threat);
    void monitorCity();
    void processEvent() override;
    std::string getStatus() const override;
};

#endif