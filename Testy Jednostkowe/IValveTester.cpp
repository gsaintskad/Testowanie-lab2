#include "IValveTester.h"


ValveTester::ValveTester(IValveController* valveController)
{
    this->valveController = valveController;
}

ValveTester::~ValveTester()
{
}

bool ValveTester::validate(const std::vector<int>& TemperatureScript, const std::vector<bool>& EstimatedPositions)
{
    if (TemperatureScript.size() != EstimatedPositions.size()) {
        throw std::exception("Different sizes of testing arrays!");
    }


    this->valveController->setTemperatures(TemperatureScript);

    for (int i = 0; i < EstimatedPositions.size(); i++) {
        if (this->valveController->openValve() != EstimatedPositions[i]) {
            return false;
        }
        
    }


    return true;
    
}

//bool ValveTester::validate(ValveController* valveController)
//{
//    /*for (int i = 0; i < expectedPosition.size(); i++)
//    {
//        if (valveController.openValve() != expectedPosition[i]) {
//            cout << "Vlave controller is working uncorrectly !" << endl;
//        }
//    }*/
//}
