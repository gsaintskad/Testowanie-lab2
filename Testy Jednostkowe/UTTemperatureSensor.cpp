#include "UTTemperatureSensor.h"
int UTTemperatureSensor::getTemperature(){
    return testTemperatures[i++];
}