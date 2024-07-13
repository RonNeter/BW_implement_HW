#ifndef IMPLEMENT_H
#define IMPLEMENT_H

#include "CommunicationDrivers.h"

// Base Implement class
class Implement
{
protected:
    CommunicationDriver *driver;
    float fuelLevel;
    ImplementStatus statusRx; // recieved status
    ImplementStatus statusTx; // transmited status

public:
    Implement(CommunicationDriver *commDriver);
    virtual void turnOn();
    virtual void turnOff();
    virtual void getTelemetry();
    float getFuelLevel();
    ImplementStatus getStatus();
};

// Specific Implement classes
// exemple if specific implements that each can have its own functions and data structures but each has the same basic functions (on/off, get telemetry and )
class ImplementA : public Implement
{
protected:
    struct ImplementA_data
    {
        uint8_t var1;
        float var2;
    } data;
    uint8_t speed;

public:
    ImplementA(CommunicationDriver *commDriver);
    void implementAlgo();
    struct ImplementA_data implementGetData();
    void implementSetSpeed(uint8_t speedReq);
};

class ImplementB : public Implement
{
public:
    ImplementB(CommunicationDriver *commDriver);
};

#endif // IMPLEMENT_H
