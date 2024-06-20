#include "ValveControllerHister.h"
#include <fstream> 
#include<iostream>


ValveControllerHister::ValveControllerHister()
{
    this->isOpen = 0;


}

bool ValveControllerHister::openValve()
{
    //  std::ofstream outputFile("example.txt");




    if (this->tempSensor == nullptr) {

        // rzucam string żeby w blok try catch w openValve obsługiwał tylko ten przewidziany wypadek
        throw std::string("TemperatureSensor hasn`t been installed.");
    }


    int recievedTemp = tempSensor->getTemperature();

    this->CallNumber++;

    if (this->CallNumber >= 5) {
        if (recievedTemp > this->expectedTemperature && this->isOpen) {
            this->isOpen = false;
            this->CallNumber = 0;
        }
        else if (recievedTemp < this->expectedTemperature && !this->isOpen)
        {
            this->isOpen = true;
            this->CallNumber = 0;
        }
    }






    return this->isOpen;
}

void ValveControllerHister::setTempSensor(ITemperatureSensor* temperatureSensor)
{
    
    this->tempSensor = temperatureSensor;
    this->CallNumber=0;
}

