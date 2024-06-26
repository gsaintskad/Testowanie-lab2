#pragma once
#include"IValveController.h"
#include"ITemperatureSensor.h"
class ValveController:public IValveController
{
public:
    ValveController();
    ValveController(ITemperatureSensor* tS);
    virtual void setTempSensor(ITemperatureSensor* temperatureSensor) override;
    virtual void setExpectedTemp(int expectedTemp) override;
    virtual bool openValve() override;



protected:

    ITemperatureSensor* tempSensor;
    int expectedTemperature;
    bool isOpen;

};

