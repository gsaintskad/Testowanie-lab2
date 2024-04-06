#pragma once
#include"../lab2/IValveController.h"
#include<vector>
#include<string>
class IValveTester
{
public:
	virtual bool validate(const std::vector<int>& TemperatureScript, const std::vector<bool>& EstimatedPositions) = 0;
};

class ValveTester: public IValveTester
{
public:
	ValveTester(IValveController* valveController);
	bool validate(const std::vector<int>& TemperatureScript, const std::vector<bool>& EstimatedPositions) override;
	~ValveTester();

//	bool validate() override;

private:
	IValveController* valveController=nullptr;

	// Inherited via IValveTester


	// Inherited via IValveTester

};
class ValveTesterException : public std::exception{
public:
	std::string what(); 
	ValveTesterException(int id, int recievedTemp, bool isOpen, bool isTempReached);
private:
	int test_index;
	int recievedTemp;
	bool isOpen;
	bool isTempReached;
};





