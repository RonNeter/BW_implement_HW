#ifndef COMMUNICATION_DRIVERS_H
#define COMMUNICATION_DRIVERS_H

#include <Arduino.h>
#include <Wire.h>
#include <CAN.h>

#define IMPLEMENT_ON_CMD (0x01)  // comm command to turn on the implement
#define IMPLEMENT_OFF_CMD (0x00) // comm command to turn on the implement

// Enum for implement status
enum class ImplementStatus
{
    OFF,
    ON
};

// Abstract base class for communication drivers
class CommunicationDriver
{
public:
    virtual void sendCommand(uint8_t command) = 0;
    virtual void readTelemetry(float &fuelLevel, ImplementStatus &statusRx) = 0;
};

class SerialDriver : public CommunicationDriver
{
public:
    void sendCommand(uint8_t command) override;
    void readTelemetry(float &fuelLevel, ImplementStatus &statusRx) override;
};

class CANDriver : public CommunicationDriver
{
public:
    void sendCommand(uint8_t command) override;
    void readTelemetry(float &fuelLevel, ImplementStatus &statusRx) override;
};

class I2CDriver : public CommunicationDriver
{
private:
    uint8_t address;

public:
    I2CDriver(uint8_t addr);
    void sendCommand(uint8_t command) override;
    void readTelemetry(float &fuelLevel, ImplementStatus &statusRx) override;
};

#endif // COMMUNICATION_DRIVERS_H
