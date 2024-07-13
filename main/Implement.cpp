#include "Implement.h"

// Implement base class
Implement::Implement(CommunicationDriver *commDriver) : driver(commDriver) {}

void Implement::turnOn()
{
    driver->sendCommand(IMPLEMENT_ON_CMD); // Example command for "TURN_ON"
    statusTx = ImplementStatus::ON;
}

void Implement::turnOff()
{
    driver->sendCommand(IMPLEMENT_ON_CMD); // Example command for "TURN_OFF"
    statusTx = ImplementStatus::OFF;
}

void Implement::getTelemetry()
{
    driver->readTelemetry(fuelLevel, statusRx);
}

float Implement::getFuelLevel()
{
    return fuelLevel;
}

ImplementStatus Implement::getStatus()
{
    return statusRx;
}

// ImplementA
ImplementA::ImplementA(CommunicationDriver *commDriver) : Implement(commDriver) {}

// Example of a specific control algorithm for the specific Implement
void ImplementA::implementAlgo()
{
}

// Example of a get data function that return the data for a specific implement
ImplementA::ImplementA_data ImplementA::implementGetData()
{
    return data;
}

// Example of a set function for a specific implement
void ImplementA ::implementSetSpeed(uint8_t speedReq)
{
    speed = speedReq;
}

// ImplementB
ImplementB::ImplementB(CommunicationDriver *commDriver) : Implement(commDriver) {}
