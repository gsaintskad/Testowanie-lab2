#include "temperature_sensor_mock.h"

//void temperature_sensor_mock::setTemperatures(std::vector<int> TestTemperatures)
//{ 
//
//
//	
//}

int temperature_sensor_mock::getTemperature()
{
    if (!(i < testTemperatures.size())) {
        throw std::exception("i is out of range testTemperaturesSet.");
    }
    return testTemperatures[i++];
}

void temperature_sensor_mock::setTemperatures(std::vector<int> newTemperatures)
{
    testTemperatures = newTemperatures;
    i = 0;
}
