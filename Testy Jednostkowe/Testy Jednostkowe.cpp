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
   
    temperature_sensor_mock tempSensor;
    ValveController valveController;
    valveController.setTempSensor(&tempSensor);
    // 19   20   21    20    20    19   19   20   21
    // true true false false false true true true false

    ValveTester valveTester(&valveController);







    valveController.setExpectedTemp(20);
    
    vector<bool> expectedPosition1 = { true, true, false, false, false,false,false, true, true, true, false };
    vector<int> testTemperatures1 = { 19, 20, 21, 20, 20,20,20, 19, 19, 20, 21 };


    vector<bool> expectedPosition2 = { true, true, false,false,false,false,false, false, false,false, true, true, true, false };
    vector<int> testTemperatures2 = { 19, 20, 21,21,21,21, 20, 20,20,20, 19, 19, 20, 21 };


    

    valveTester.validate(testTemperatures1, expectedPosition1);
    cout << "\n\n\n---------------------------------------------------------------------------------------\n\n\n";
    valveTester.validate(testTemperatures2, expectedPosition2);


    cout << "\n\n\n---------------------------------------------------------------------------------------\n\n\n";



    valveController.setExpectedTemp(50);

    vector<bool> expectedPosition3 = { 1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,0 };
    vector<int> testTemperatures3 = { 44,45,46,47,48,49,50,51,51,51,51,50,50,50,49,49,49,50,50,51 };

    valveTester.validate(testTemperatures3, expectedPosition3);
}