#include "CommunicationDrivers.h"

// In the communication drivers, I have assumed for this example that the Telemetry info will be a 8bit long data frame in which the
// first bit will represent on/off status and the last 7 bits the fuel precentage

// SerialDriver
void SerialDriver::sendCommand(uint8_t command)
{
    Serial.write(command);
}

void SerialDriver::readTelemetry(float &fuelLevel, ImplementStatus &statusRx)
{
    if (Serial.available())
    {
        uint8_t message = Serial.read();
        statusRx = (message & 0x80) ? ImplementStatus::ON : ImplementStatus::OFF; // First bit
        fuelLevel = message & 0x7F;                                               // Last 7 bits
    }
}

// CANDriver
void CANDriver::sendCommand(uint8_t command)
{
    CAN.beginPacket(0x100); // Example CAN ID
    CAN.write(command);
    CAN.endPacket();
}

void CANDriver::readTelemetry(float &fuelLevel, ImplementStatus &statusRx)
{
    if (CAN.parsePacket())
    {
        uint8_t message = CAN.read();
        statusRx = (message & 0x80) ? ImplementStatus::ON : ImplementStatus::OFF; // First bit
        fuelLevel = message & 0x7F;                                               // Last 7 bits
    }
}

// I2CDriver
I2CDriver::I2CDriver(uint8_t addr) : address(addr) {}

void I2CDriver::sendCommand(uint8_t command)
{
    Wire.beginTransmission(address);
    Wire.write(command);
    Wire.endTransmission();
}

void I2CDriver::readTelemetry(float &fuelLevel, ImplementStatus &statusRx)
{
    Wire.requestFrom(address, (uint8_t)1);
    if (Wire.available())
    {
        uint8_t message = Wire.read();
        statusRx = (message & 0x80) ? ImplementStatus::ON : ImplementStatus::OFF; // First bit
        fuelLevel = message & 0x7F;                                               // Last 7 bits
    }
}
