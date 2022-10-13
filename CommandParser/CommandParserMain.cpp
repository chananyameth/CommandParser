#include<iostream>
#include<exception>
#include<string>
#include<vector>
#include"CommandsLibrary.h"

void parseCommand(std::vector<std::string>& args)
{
	try
	{
		std::string addCommand = "add";
		std::string subCommand = "sub";
		std::string exitCommand = "exit";

		if (args.size() == 0) {
			// do nothing
		}
		else if (args[0] == addCommand) {
			Commands::add(args);
		}
		else if (args[0] == subCommand) {
			Commands::sub(args);
		}
		else if (args[0] == exitCommand) {
			Commands::exit(args);
		}
		else {
			std::cout << "Invalid command" << std::endl;
		}
	}
	catch (std::exception e) {
		std::cout << e.what() << std::endl;
	}
	catch (std::string s) {
		std::cout << s << std::endl;
	}
	catch (...) {
		std::cout << "Invalid command" << std::endl;
	}
}

void processInput(std::string& inputLine, std::vector<std::string>& args)
{
	// split the input into seperate args (by spaces and tabs)
	for (int i = 0; i < inputLine.length(); ++i)
		if (inputLine[i] == '\t')
			inputLine[i] = ' ';
	args.clear();
	int start = -1, end = 0;
	while (end != inputLine.length())
	{
		std::string arg = "";

		end = inputLine.find_first_of(' ', start + 1);
		if (end == -1) // space not found
			end = inputLine.length();

		arg = inputLine.substr(start + 1, end - start - 1);
		if (arg != "") // ignore empty args (or multiple spaces)
			args.push_back(arg);
		start = end;
	}
}

int main()
{
	std::string inputLine;
	std::vector<std::string> args;

	do
	{
		std::cout << "> ";
		std::getline(std::cin, inputLine);

		processInput(inputLine, args);
		parseCommand(args);

	} while (inputLine.substr(inputLine.find_first_not_of(' ')) != "exit"); // ignore leading spaces or tabs

	system("pause");
	return 0;
}