#pragma once
#include "../lab2/ITemperatureSensor.h"
class UTTemperatureSensor :public ITemperatureSensor
{
private:
    std::vector<int> testTemperatures = { 19, 20, 21, 20, 20,20,20, 19, 19, 20, 21 };
    int i = 0;
public:
    int getTemperature() override;
};

