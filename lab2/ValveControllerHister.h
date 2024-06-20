#pragma once
#include "ValveController.h"
#include <string>

class ValveControllerHister : public ValveController
{
public: 
	ValveControllerHister();
	bool openValve() override;
	void setTempSensor(ITemperatureSensor* temperatureSensor) override;
	
private:
	unsigned short int CallNumber=0;

};

