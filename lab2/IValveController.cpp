#include "IValveController.h"

void ValveController::setTempSensor(ITemperatureSensor* temperatureSensor)
{
}



//setExpectedTemperature - podajemy tutaj temperaturę jaką chcemy osiągnąć w pomieszczeniu.
void ValveController::setExpectedTemp(int expectedTemp)
{
}



//openValve - wywołanie tej metody informuje nas czy należy otworzyć albo zamknąć obwód grzewczy
bool ValveController::openValve()
{
	return false;
}
