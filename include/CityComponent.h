#ifndef CITY_COMPONENT_H
#define CITY_COMPONENT_H

#include <string>

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

class PowerSystem : public CityComponent {
private:
    double powerLevel; // percentage or megawatts
public:
    PowerSystem(int id, std::string name, double power);
    void supplyPower();
    void processEvent() override;
    std::string getStatus() const override;
};

class TransportSystem : public CityComponent {
private:
    int trafficFlow; // vehicles per minute
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
    int threatLevel; // 1 to 10
public:
    SecuritySystem(int id, std::string name, int threat);
    void monitorCity();
    void processEvent() override;
    std::string getStatus() const override;
};

#endif