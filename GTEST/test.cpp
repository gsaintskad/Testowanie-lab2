#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../lab2/ValveControllerHister.h"
#include <fstream>

class TemperatureSensorMOCK:public ITemperatureSensor {
public:
	MOCK_METHOD(int, getTemperature, (),(override));
};
//class TemperatureSensorHisterMOCK :public ITemperatureSensor {
//public:
//    using vectINT = std::vector<int>;
//    MOCK_METHOD(vectINT, getTemperatureHister, ());
//};

ValveController valveController;
TEST(ValveConrollerTests, exmpTemp20_1) {
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

TEST(ValveConrollerTests, exmpTemp20_2) {
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


TEST(ValveConrollerTests, exmpTemp50_1) {
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
TEST(ValveConrollerTests, exmpTemp50_2) {
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

TEST(ValveConrollerMissingTempSensorTest, MissingTempSensor) {
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

TEST(ValveConrollerHisterezaTests, Histereza20Short) {
    ValveControllerHister valveControllerH;
    TemperatureSensorMOCK* tempSensor = new TemperatureSensorMOCK();
    valveControllerH.setTempSensor(tempSensor);
    valveControllerH.setExpectedTemp(20);

    std::vector<int> temperatures = { 19, 20, 21,21,21,21 };
    std::vector<bool> expectedPositions = { true,true,true,true,true, false };

    ::testing::Sequence seq;
    for (size_t i = 0; i < temperatures.size(); ++i) {
        EXPECT_CALL(*tempSensor, getTemperature()).InSequence(seq).WillOnce(::testing::Return(temperatures[i]));
        bool expected = expectedPositions[i];
        bool actual = valveControllerH.openValve();
        EXPECT_EQ(actual, expected) << "Failure at position " << i + 1;
    }
    delete tempSensor;
}
TEST(ValveConrollerHisterezaTests, Histereza20Long) {
    ValveControllerHister valveControllerH;
    TemperatureSensorMOCK* tempSensor = new TemperatureSensorMOCK();
    valveControllerH.setTempSensor(tempSensor);
    valveControllerH.setExpectedTemp(20);
          
    std::vector<int> temperatures = { 19, 20, 21,21,21,21,20,19,18,17,17,17,17,19,20,20 };
    std::vector<bool> expectedPositions = { true,true,true,true,true, false,false,false,false,false,true,true,true,true,true,true,false };

    ::testing::Sequence seq;
    for (size_t i = 0; i < temperatures.size(); ++i) {
        EXPECT_CALL(*tempSensor, getTemperature()).InSequence(seq).WillOnce(::testing::Return(temperatures[i]));
        bool expected = expectedPositions[i];
        bool actual = valveControllerH.openValve();
        EXPECT_EQ(actual, expected) << "Failure at position " << i + 1;
    }
    delete tempSensor;
}