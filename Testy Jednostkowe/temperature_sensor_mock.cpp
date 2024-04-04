#include "temperature_sensor_mock.h"

//void temperature_sensor_mock::setTemperatures(std::vector<int> TestTemperatures)
//{ 
//
//
//	
//}

int temperature_sensor_mock::getTemperature()
{
    return testTemperatures[i++];
}

void temperature_sensor_mock::setTemperatures(std::vector<int> newTemperatures)
{
    testTemperatures = newTemperatures;
    i = 0;
}
