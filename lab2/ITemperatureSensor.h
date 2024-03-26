#pragma once
#include<vector>
class ITemperatureSensor
{
public:
    virtual int getTemperature() = 0;
    virtual int getPreviousTemp() = 0;
};

class UTTemperatureSensor : public ITemperatureSensor
{
private:
    std::vector<int> testTemperatures = { 19, 20, 21, 20, 20, 19, 19, 20, 21 };
    int i = 0;
public:
    int getTemperature() override {
        return testTemperatures[i++];
    }
    int getPreviousTemp() override {
        return testTemperatures[i - 1];
    }

};