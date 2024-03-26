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
}

//<19 - otwarty, 20 - otwarty, 20 - otwarty, 21 - zamknięty, 20 - zamknięty, 20 - zamknięty, 19 - otwarty>

//openValve - wywołanie tej metody informuje nas czy należy otworzyć albo zamknąć obwód grzewczy
bool ValveController::openValve(int expectedTemp)
{
    int recievedTemp = tempSensor->getTemperature();
 
  
    bool isOpened = expectedTemp >= recievedTemp;
    
    
    std::cout <<"\n----------------------------\n" 
        << "Recived temperature : " << recievedTemp
        << "\nExpected temperature : " << expectedTemp
        << "\n----------------------------\n";
   
    if (isOpened && !(recievedTemp < tempSensor->getPreviousTemp())) {
        std::cout << 1<<std::endl;
        return true;
    }
    else {
        std::cout << 0 << std::endl;
        return false;
    }
   
}
