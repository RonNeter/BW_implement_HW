#ifndef IMPLEMENT_CONTROLLER_H
#define IMPLEMENT_CONTROLLER_H

#include "Implement.h"

#define MIN_IMPLEMENT_FUEL_LEVEL (20.0f) // minimal fuel level allowed in implement
#define MAX_IMPLEMENTS (3U)              // Max number if implements allowed in the system

// Implement controller gives an API for all basic implement functions
class ImplementController
{
private:
    Implement *implements[MAX_IMPLEMENTS];
    int implementCount;

public:
    ImplementController();
    void addImplement(Implement *implement);
    void turnOnImplement(int id);
    void turnOffImplement(int id);
    void checkFuelLevels();
    void reportTelemetry();
};

#endif // IMPLEMENT_CONTROLLER_H
