#pragma once
#include<iostream>
#include<string>
#include<vector>

class Commands
{
public:
	static void add(std::vector<std::string>& args)
	{
		std::cout << "add command!" << std::endl;
	}
	static void sub(std::vector<std::string>& args)
	{
		std::cout << "sub command!" << std::endl;
	}
	static void exit(std::vector<std::string>& args)
	{
		std::cout << "Bye!" << std::endl;
	}
};