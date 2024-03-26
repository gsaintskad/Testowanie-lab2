#include "ITemperatureSensor.h"
#include "IValveController.h"

//#include "temperature_sensor.h"
//#include "valve_controller.h"
int main(int argc, char* argv[])
{
    UTTemperatureSensor tempSensor;
    ValveController valveController;
    valveController.setTempSensor(&tempSensor);
    valveController.setExpectedTemp(20);
    // 19   20   21    20    20    19   19   20   21
    // true true false false false true true true false
//    for (;;) // sprawdzamy kolejne kroki scenariusza testowego
//    {
//        if (valveController.openValve() != expectedPosition)
//        {
//            // błąd
//        }
//    }
//}
