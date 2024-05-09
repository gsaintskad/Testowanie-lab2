#include "ValveController.h"

#include<iostream>

ValveController::ValveController()
{
}

ValveController::ValveController(ITemperatureSensor* tS)
{
   

    this->tempSensor = tS;
}

/*
    * Dodatkowo sterownik zaworu do swojego działania potrzebuje informacji o aktualnej temperaturze.
    * W tym celu należy mu wstrzyknąć (Dependency Injection) obiekt czujnika temperatury.
    */
void ValveController::setTempSensor(ITemperatureSensor* temperatureSensor)
{
    this->tempSensor = temperatureSensor;
}


//setExpectedTemperature - podajemy tutaj temperaturę jaką chcemy osiągnąć w pomieszczeniu.
void ValveController::setExpectedTemp(int expectedTemp)
{
    this->expectedTemperature = expectedTemp;
    this->isOpen = 0;
}



//<19 - otwarty, 20 - otwarty, 20 - otwarty, 21 - zamknięty, 20 - zamknięty, 20 - zamknięty, 19 - otwarty>

//openValve - wywołanie tej metody informuje nas czy należy otworzyć albo zamknąć obwód grzewczy
bool ValveController::openValve()
{

    if (this->tempSensor == nullptr) {

        // rzucam string żeby w blok try catch w openValve obsługiwał tylko ten przewidziany wypadek
        throw std::string("TemperatureSensor hasn`t been installed.");
    }

   

    int recievedTemp = tempSensor->getTemperature();
    
    if (recievedTemp > this->expectedTemperature) {
        this->isOpen = false;
    }
    else if (recievedTemp < this->expectedTemperature)
    {
        this->isOpen = true;
    }

    return this->isOpen;
}

