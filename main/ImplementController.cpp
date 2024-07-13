#include "ImplementController.h"

ImplementController::ImplementController() : implementCount(0) {}

// Add implement to the implement array (could also use a different data structure)
void ImplementController::addImplement(Implement *implement)
{
    if (implementCount < MAX_IMPLEMENTS)
    {
        implements[implementCount++] = implement;
    }
    else
    {
        Serial.println("Implement array is full!");
    }
}

// Turn implement on
void ImplementController::turnOnImplement(int id)
{
    if (id >= 0 && id < implementCount)
    {
        implements[id]->turnOn();
    }
    else
    {
        Serial.println("Invalid Implement ID!");
    }
}

// Turn implement off
void ImplementController::turnOffImplement(int id)
{
    if (id >= 0 && id < implementCount)
    {
        implements[id]->turnOff();
    }
    else
    {
        Serial.println("Invalid Implement ID!");
    }
}

// Checks fuel level and shuts implement off if fuel level is to low
void ImplementController::checkFuelLevels()
{
    for (int i = 0; i < implementCount; i++)
    {
        implements[i]->getTelemetry();
        if (implements[i]->getFuelLevel() <= MIN_IMPLEMENT_FUEL_LEVEL)
        {
            implements[i]->turnOff();
        }
    }
}

// Reports telemetry over serial comm
void ImplementController::reportTelemetry()
{
    for (int i = 0; i < implementCount; i++)
    {
        Serial.print("Implement ");
        Serial.print(i);
        Serial.print(" Status: ");
        Serial.print(implements[i]->getStatus() == ImplementStatus::ON ? "On" : "Off");
        Serial.print(", Fuel Level: ");
        Serial.println(implements[i]->getFuelLevel());
    }
}
