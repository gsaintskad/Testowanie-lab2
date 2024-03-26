#include "ITemperatureSensor.h"
#include "IValveController.h"
#include<iostream>
#include<vector>

using namespace std;

//#include "temperature_sensor.h"
//#include "valve_controller.h"
int main(int argc, char* argv[])
{
    int expectedTemp = 20;
    UTTemperatureSensor tempSensor;
    ValveController valveController;
    valveController.setTempSensor(&tempSensor);
    valveController.setExpectedTemp(expectedTemp);
    // 19   20   21    20    20    19   19   20   21
    // true true false false false true true true false
    vector<bool> expectedPosition = { true, true, false, false, false, true, true, true, false };

    //for each(;;) // sprawdzamy kolejne kroki scenariusza testowego
    //{
    //    if (valveController.openValve(expectedTemp) != expectedPosition)
    //    {
    //        // błąd
    //    }
    //}
    for(int i=0;i<expectedPosition.size();i++)
    {
        if (valveController.openValve() != expectedPosition[i]) {
            cout << "Vlave controller is working uncorrectly !" << endl;
        }
    }
}
