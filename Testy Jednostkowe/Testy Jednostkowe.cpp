#include "../lab2/ITemperatureSensor.h"
#include "../lab2/IValveController.h"
#include"temperature_sensor_mock.h"
#include"IValveTester.h"
#include<iostream>
#include<vector>

using namespace std;

//#include "temperature_sensor.h"
//#include "valve_controller.h"
int main(int argc, char* argv[])
{
   
    temperature_sensor_mock tempSensor;
    ValveController valveController;
    valveController.setTempSensor(&tempSensor);
    // 19   20   21    20    20    19   19   20   21
    // true true false false false true true true false

    ValveTester valveTester(&valveController);







    
    //EXPECTED TEMP 20
    vector<bool> expectedPosition1 = { true, true, false, false, false,false,false, true, true, true, false };
    vector<int> testTemperatures1 = { 19, 20, 21, 20, 20,20,20, 19, 19, 20, 21 };
    //EXPECTED TEMP 20
    vector<bool> expectedPosition2 = { true, true, false,false,false,false,false, false, false,false, true, true, true, false };
    vector<int> testTemperatures2 = { 19, 20, 21,21,21,21, 20, 20,20,20, 19, 19, 20, 21 };





    //EXPECTED TEMP 50
    vector<bool> expectedPosition3 = { 1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,1,0 };
    vector<int> testTemperatures3 = { 44,45,46,47,48,49,50,51,51,51,51,50,50,50,49,49,49,50,50,51 };

   

    //błędne case żeby pokazać że błędny się wykrywają//

    //EXPECTED TEMP 50
    //                                                                     v tutaj trzeba zmienić na 0;
    vector<bool> expectedPosition4 = { 1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,1,0 };
    vector<int> testTemperatures4 = { 40,42,44,47,48,49,50,51,52,51,51,50,50,50,49,49,49,50,51,51 };

    /*
    * Test #4 Incorrect work of ValveController while validating on array id :18
    * 
    * Żeby to naprawić trzeba dać zamiast przedostatniej 1 - 0
    */
    

    //EXPECTED TEMP NULL
    vector<bool> expectedPosition5 = { 1,0,1,0,1 };
    vector<int> testTemperatures5 = { true };

    //EXPECTED TEMP 5
    vector<bool> expectedPosition6 = { 1,1,0,0,0,0,0 };

    vector<int> testTemperatures6 = { 5,6,5,6,5,5,5 };





    ////// TEST SETS

    vector<vector<int>>TEST_TEMPERATURES = { testTemperatures1,testTemperatures2,testTemperatures3,testTemperatures4,testTemperatures5,testTemperatures6 };
    vector<vector<bool>>EXPECTED_POSITIONS = { expectedPosition1,expectedPosition2,expectedPosition3,expectedPosition4,expectedPosition5,expectedPosition6 };

    vector<int>EXPECTED_TEMPS = { 20,20,50,50,NULL,6 };

    //sprawdzanie odpowiedniej liczby zbiorow testowych:


    try
    {
        if (TEST_TEMPERATURES.size() != EXPECTED_POSITIONS.size()) {
            throw exception("Different numbers of TEMPERATURES and POSITIONS sets!");
        }
        if (TEST_TEMPERATURES.size() != EXPECTED_TEMPS.size()) {
            throw exception("Different numbers of TEMPERATURES and EXPECTED TEMPS sets!");
        }
        if (EXPECTED_POSITIONS.size() != EXPECTED_TEMPS.size()) {
            throw exception("Different numbers of POSITIONS and EXPECTED TEMPS sets!");
        }
    }
    catch (const std::exception& ex)
    {
        cout << ex.what();
    }


    // testowanie


    cout << "\n\n==============START TESTING==============\n\n";

    for (int i = 0; i < TEST_TEMPERATURES.size(); i++) {
        try
        {
            valveController.setExpectedTemp(EXPECTED_TEMPS[i]);
            valveTester.validate(TEST_TEMPERATURES[i], EXPECTED_POSITIONS[i]);

        }
        catch (const std::exception& ex)
        {
            cout << ex.what();
        }
        catch (const std::string& ex) {
            cout << ex;
        }
        
    }
    cout << "\n\n===============END TESTING===============\n\n";

    return 0;
}

