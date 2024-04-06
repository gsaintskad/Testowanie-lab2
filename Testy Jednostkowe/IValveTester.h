#pragma once
#include"../lab2/IValveController.h"
#include<vector>
#include<iostream>
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
	static unsigned int testID;

	// Inherited via IValveTester


	// Inherited via IValveTester

};


class myException :public std::exception {
public:
	myException(std::string s);
	std::string what();
private:
	std::string toWhat;

};




