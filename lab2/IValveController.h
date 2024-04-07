#pragma once
#include "ITemperatureSensor.h"

class IValveController
{
public:
    /*
    * Dodatkowo sterownik zaworu do swojego działania potrzebuje informacji o aktualnej temperaturze.
    * W tym celu należy mu wstrzyknąć (Dependency Injection) obiekt czujnika temperatury.
    */
    virtual void setTempSensor(ITemperatureSensor* temperatureSensor) = 0;

    //setExpectedTemperature - podajemy tutaj temperaturę jaką chcemy osiągnąć w pomieszczeniu.
    virtual void setExpectedTemp(int expectedTemp) = 0;


    //openValve - wywołanie tej metody informuje nas czy należy otworzyć albo zamknąć obwód grzewczy
    virtual bool openValve() = 0;

    
};



