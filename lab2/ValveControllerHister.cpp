#include "ValveControllerHister.h"

#include<iostream>

bool ValveControllerHister::openValve()
{
    if (this->tempSensor == nullptr) {

        // rzucam string żeby w blok try catch w openValve obsługiwał tylko ten przewidziany wypadek
        throw std::string("TemperatureSensor hasn`t been installed.");
    }



    int recievedTempValues[5] = {};

    if (this->IsTheCallFirst) {

        recievedTempValues[4]= this->tempSensor->getTemperature();
        this->IsTheCallFirst = false;

    }
    else {

        for (int i = 0; i < 5; i++) {
            recievedTempValues[i] = this->tempSensor->getTemperature();
        }

    }

    if (recievedTempValues[4] > this->expectedTemperature) {
        this->isOpen = false;
    }
    else if (recievedTempValues[4] < this->expectedTemperature)
    {
        this->isOpen = true;
    }

    
    
    
   





    return this->isOpen;
}

void ValveControllerHister::setTempSensor(ITemperatureSensor* temperatureSensor)
{
    
    this->tempSensor = temperatureSensor;
    this->IsTheCallFirst = 0;
}
