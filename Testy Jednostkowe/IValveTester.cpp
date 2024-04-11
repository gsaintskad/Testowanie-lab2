#include "IValveTester.h"




ValveTester::ValveTester(IValveController* valveController)
{
    this->valveController = valveController;
}



ValveTester::~ValveTester()
{
}

bool ValveTester::validate(const std::vector<bool>& EstimatedPositions)
{
    
   
   


   

    for (int i = 0; i < EstimatedPositions.size(); i++){
        bool ValveControllerResult = this->valveController->openValve();

        if (ValveControllerResult != EstimatedPositions[i]) {
            throw std::string("Incorrect work of ValveController while validating on array id :"+std::to_string(i)+"\n");
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

