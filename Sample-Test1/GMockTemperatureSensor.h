#pragma once

#include"../lab2/ITemperatureSensor.h"
#include "gtest/gtest.h"
#include"gmock/gmock.h"
class GMockTemperatureSensor : public ITemperatureSensor
{
public:
	MOCK_METHOD(int, getTemperature, (),override);
};

