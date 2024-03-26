#pragma once
#include "ITemperatureSensor.h"

class IValveController
{
public:
    virtual void setTempSensor(ITemperatureSensor* temperatureSensor) = 0;

    //setExpectedTemperature - podajemy tutaj temperaturę jaką chcemy osiągnąć w pomieszczeniu.
    virtual void setExpectedTemp(int expectedTemp) = 0;


    //openValve - wywołanie tej metody informuje nas czy należy otworzyć albo zamknąć obwód grzewczy
    virtual bool openValve() = 0;
};

class ValveController : public IValveController
{
public:
    virtual void setTempSensor(ITemperatureSensor* temperatureSensor) override;
    virtual void setExpectedTemp(int expectedTemp) override;
    virtual bool openValve() override;
private:
    ITemperatureSensor* tempSensor;
};

