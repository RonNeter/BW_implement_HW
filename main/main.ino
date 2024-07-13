#include <Arduino.h>
#include "CommunicationDrivers.h"
#include "Implement.h"
#include "ImplementController.h"

ImplementController controller;
String userRequest;

void setup()
{
    Serial.begin(9600);
    // Initialize I2C
    Wire.begin();
    // Initialize CAN
    CAN.begin(500E3); // baud rate of 500 kbps

    // Create Communication Drivers
    SerialDriver serialDriver;
    CANDriver canDriver;
    I2CDriver i2cDriver(0x68); // Example I2C address

    // Create Implements
    ImplementA *implementA = new ImplementA(&serialDriver);
    ImplementB *implementB1 = new ImplementB(&canDriver);
    ImplementB *implementB2 = new ImplementB(&i2cDriver);

    // Add Implements to controller
    controller.addImplement(implementA);
    controller.addImplement(implementB1);
    controller.addImplement(implementB2);

    // Turning on implements by ID
    controller.turnOnImplement(0);
    controller.turnOnImplement(1);
    controller.turnOnImplement(2);
}

void loop()
{
    // Example of checking fuel levels and reporting telemetry
    controller.checkFuelLevels();
    controller.reportTelemetry();

    delay(1000); // report status over can every seconds and make sure fuel level is ok
}
