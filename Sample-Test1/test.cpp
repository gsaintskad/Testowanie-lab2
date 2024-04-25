#include "gtest/gtest.h"
#include"gmock/gmock.h"
#include"../lab2/ValveController.h"

class gmockTemperatureSensor : public ITemperatureSensor {
	// Inherited via ITemperatureSensor
	int getTemperature() override
	{
		return 0;
	}
};

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}