#include "ValveControllerHister.h"
#include <fstream> 
#include<iostream>


bool ValveControllerHister::openValve()
{
    //  std::ofstream outputFile("example.txt");




    if (this->tempSensor == nullptr) {

        // rzucam string żeby w blok try catch w openValve obsługiwał tylko ten przewidziany wypadek
        throw std::string("TemperatureSensor hasn`t been installed.");
    }


    int recievedTemp = tempSensor->getTemperature();


    if (this->CallNumber%5 == 0) {
        if (recievedTemp > this->expectedTemperature) {
            this->isOpen = false;
        }
        else if (recievedTemp < this->expectedTemperature)
        {
            this->isOpen = true;
        }
    }

    this->CallNumber++;





    return this->isOpen;
}

void ValveControllerHister::setTempSensor(ITemperatureSensor* temperatureSensor)
{
    
    this->tempSensor = temperatureSensor;
    this->CallNumber=0;
}

