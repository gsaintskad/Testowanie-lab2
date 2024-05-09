#pragma once
#include "ValveController.h"
#include <string>

class ValveControllerHister : public ValveController
{
public: 
	bool openValve() override;
	void setTempSensor(ITemperatureSensor* temperatureSensor) override;
	
private:
	bool IsTheCallFirst = true;
};

