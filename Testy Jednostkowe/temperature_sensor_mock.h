#pragma once
#include<vector>
#include"../lab2/ITemperatureSensor.h"
class temperature_sensor_mock : public ITemperatureSensor
{
public:


	bool operator==(const temperature_sensor_mock& other) const
	{
		return false;
	}

	// Inherited via ITemperatureSensor
	int getTemperature() override;
	void setTemperatures(std::vector<int> newTemperatures);
private:
	std::vector<int> testTemperatures;
	int i=0;
};

