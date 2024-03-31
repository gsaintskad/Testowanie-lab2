#include "IValveController.h"
#include<iostream>

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
    this->isTempReached = 0;
}



//<19 - otwarty, 20 - otwarty, 20 - otwarty, 21 - zamknięty, 20 - zamknięty, 20 - zamknięty, 19 - otwarty>

//openValve - wywołanie tej metody informuje nas czy należy otworzyć albo zamknąć obwód grzewczy
bool ValveController::openValve()
{
    int recievedTemp = tempSensor->getTemperature();
   
    if (this->isTempReached) {
        this->isTempReached = recievedTemp >= this->expectedTemperature;

    }
    
    bool isOpen = (recievedTemp <= this->expectedTemperature) && !this->isTempReached;
    std::cout <<"\n-----------------------------------"
        << "\nRecived temperature: " << recievedTemp
        << "\n IsOpen: " << isOpen 
        << "\n IsTempReached: " << this->isTempReached;
    
    
    if (this->isTempReached) return false;

    if (isOpen) {


        return true;
    }
    else {
        this->isTempReached = 1;
        return false;
    }

  
   
  
  
   
}

