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

std::string ValveTesterException::what()
{
   
    return std::string("\nComparing temperatures index : " + this->test_index) + std::string("\nRecived temperature: " + std::to_string(recievedTemp) + "\n IsOpen: " + std::to_string(isOpen) + "\n IsTempReached: " + std::to_string(isTempReached));
    
}

ValveTesterException::ValveTesterException(int id, int recievedTemp, bool isOpen, bool isTempReached)
{
    this->test_index = id;
    this->isTempReached = isTempReached;
    this->isOpen = isOpen;
    this->recievedTemp = recievedTemp;
}

