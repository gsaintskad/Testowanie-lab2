#include "IValveTester.h"


unsigned int ValveTester::testID = 0;

ValveTester::ValveTester(IValveController* valveController)
{
    this->valveController = valveController;
}

ValveTester::~ValveTester()
{
}

bool ValveTester::validate(const std::vector<int>& TemperatureScript, const std::vector<bool>& EstimatedPositions)
{
    
    std::cout << "\nTest #" <<++testID<<"\t";
    if (TemperatureScript.size() != EstimatedPositions.size()) {
        throw std::exception("Different sizes of testing arrays!\n");
    }


    this->valveController->setTemperatures(TemperatureScript);

    for (int i = 0; i < EstimatedPositions.size(); i++){
        bool ValveControllerResult = this->valveController->openValve();

        if (ValveControllerResult != EstimatedPositions[i]) {

          
            throw std::string("Incorrect work of ValveController while validating on array id :"+std::to_string(i)+"\n");
        }
        
    }



    std::cout <<"complete succesfully!\n";

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

myException::myException(std::string s)
{
    this->toWhat = s;
}

std::string myException::what()
{
    return toWhat;
}
