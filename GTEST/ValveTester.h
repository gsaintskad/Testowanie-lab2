#pragma once

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../lab2/ValveControllerHister.h"
class ValveTester : public ::testing::Test
{
protected:
    void SetUp() override;

    void TearDown() override;

private:
    IValveController* valveController=nullptr;


public:


};


