#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../lab2/ValveController.h"

class TemperatureSensorMOCK:public ITemperatureSensor {
public:
	MOCK_METHOD(int, getTemperature, (),(override));
};

ValveController valveController;
TEST(ValeConrollerTests, exmpTemp20_1) {
    TemperatureSensorMOCK* tempSensor=new TemperatureSensorMOCK();
    valveController.setTempSensor(tempSensor);
    valveController.setExpectedTemp(20);

    std::vector<int> temperatures = { 19, 20, 21, 20, 20,20,20, 19, 19, 20, 21 };
    std::vector<bool> expectedPositions = { true, true, false, false, false,false,false, true, true, true, false };
   
    ::testing::Sequence seq;
    for (size_t i = 0; i < temperatures.size(); ++i) {
        EXPECT_CALL(*tempSensor, getTemperature()).InSequence(seq).WillOnce(::testing::Return(temperatures[i]));
        bool expected = expectedPositions[i];
        bool actual = valveController.openValve();
        EXPECT_EQ(actual, expected) << "Failure at position " << i + 1;
    }

    delete tempSensor;
}

TEST(ValeConrollerTests, exmpTemp20_2) {
    TemperatureSensorMOCK* tempSensor = new TemperatureSensorMOCK();
    valveController.setTempSensor(tempSensor);

    valveController.setExpectedTemp(20);

    std::vector<int> temperatures = { 19, 20, 21,21,21,21, 20, 20,20,20, 19, 19, 20, 21 };
    std::vector<bool> expectedPositions = { true, true, false,false,false,false,false, false, false,false, true, true, true, false };

    ::testing::Sequence seq;

    for (size_t i = 0; i < temperatures.size(); ++i) {
        EXPECT_CALL(*tempSensor, getTemperature()).InSequence(seq).WillOnce(::testing::Return(temperatures[i]));
        bool expected = expectedPositions[i];
        bool actual = valveController.openValve();
        EXPECT_EQ(actual, expected) << "Failure at position " << i + 1;
    }
    delete tempSensor;
}


TEST(ValeConrollerTests, exmpTemp50_1) {
    TemperatureSensorMOCK* tempSensor = new TemperatureSensorMOCK();
    valveController.setTempSensor(tempSensor);

    valveController.setExpectedTemp(50);

    std::vector<int> temperatures = { 44,45,46,47,48,49,50,51,51,51,51,50,50,50,49,49,49,50,50,51 };
    std::vector<bool> expectedPositions = { 1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,1,0 };

    ::testing::Sequence seq;
    for (size_t i = 0; i < temperatures.size(); ++i) {
        EXPECT_CALL(*tempSensor, getTemperature()).InSequence(seq).WillOnce(::testing::Return(temperatures[i]));
        bool expected = expectedPositions[i];
        bool actual = valveController.openValve();
        EXPECT_EQ(actual, expected) << "Failure at position " << i + 1;
    }

    delete tempSensor;
}
TEST(ValeConrollerTests, exmpTemp50_2) {
    TemperatureSensorMOCK* tempSensor = new TemperatureSensorMOCK();
    valveController.setTempSensor(tempSensor);
    valveController.setExpectedTemp(50);

    std::vector<int> temperatures = { 40,42,44,47,48,49,50,51,52,51,51,50,50,50,49,49,49,50,51,51 };
    std::vector<bool> expectedPositions = { 1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,0,0 };

    ::testing::Sequence seq;
    for (size_t i = 0; i < temperatures.size(); ++i) {
        EXPECT_CALL(*tempSensor, getTemperature()).InSequence(seq).WillOnce(::testing::Return(temperatures[i]));
        bool expected = expectedPositions[i];
        bool actual = valveController.openValve();
        EXPECT_EQ(actual, expected) << "Failure at position " << i + 1;
    }
    delete tempSensor;
}

TEST(ValeConrollerTests, MissingTempSensor) {
    TemperatureSensorMOCK* tempSensor = nullptr;
    valveController.setTempSensor(tempSensor);
    valveController.setExpectedTemp(50);

    std::vector<int> temperatures = { 40,42,44,47,48,49,50,51,52,51,51,50,50,50,49,49,49,50,51,51 };
    std::vector<bool> expectedPositions = { 1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,0,0 };

    try
    {

        valveController.openValve();
    }
    catch (const std::string ex) // rzucam string żeby w blok try catch w openValve obsługiwał tylko ten przewidziany wypadek
    {
        std::cout << ex << std::endl;
    }
   
   
}