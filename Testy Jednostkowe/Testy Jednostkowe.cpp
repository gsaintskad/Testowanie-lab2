#include "../lab2/ITemperatureSensor.h"
#include "../lab2/IValveController.h"
#include"temperature_sensor_mock.h"
#include"IValveTester.h"
#include<iostream>
#include<vector>

using namespace std;

//#include "temperature_sensor.h"
//#include "valve_controller.h"
int main(int argc, char* argv[])
{
    int expectedTemp = 20;
    temperature_sensor_mock tempSensor;
    ValveController valveController;
    valveController.setTempSensor(&tempSensor);
    valveController.setExpectedTemp(expectedTemp);
    // 19   20   21    20    20    19   19   20   21
    // true true false false false true true true false
    vector<bool> expectedPosition1 = { true, true, false, false, false,false,false, true, true, true, false };
    vector<int> testTemperatures1 = { 19, 20, 21, 20, 20,20,20, 19, 19, 20, 21 };

    ValveTester valveTester(&valveController);
    
    valveTester.validate(testTemperatures1, expectedPosition1);
}
