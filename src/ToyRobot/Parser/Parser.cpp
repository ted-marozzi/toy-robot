#include <iostream>
#include <sstream>

#include "Parser.hpp"

namespace Robot
{

    const std::vector<std::string> Parser::Split(const std::string &text, const char &delim) const
    {
        std::string line;
        std::vector<std::string> vec;
        std::stringstream ss{text};
        while (std::getline(ss, line, delim))
        {
            vec.push_back(line);
        }
        return vec;
    }

    std::unique_ptr<ICommand> Parser::ParseCommandLine(const std::string& input, std::unique_ptr<CommandFactory> &commandFactory) const
    {
        std::string inputToUpperCase{ input };
        // Not case sensitive so convert to upper case
        for (auto &c : inputToUpperCase)
        {
            c = toupper(c);
        }

        // Split command and args
        auto command_line = Split(inputToUpperCase, ' ');

        // No args
        if (command_line.size() <= 0 || command_line.size() >= 3)
        {
            // Invalid
            std::cout << "Invalid Format, please enter commands in the format COMMAND or COMMAND arg1,arg2\n";
            return nullptr;
        }

        auto command_name_input = command_line[0];
        auto arguments = command_line.size() == 2 ? Split(command_line[1], ',') : std::vector<std::string>{};
        // Commands
        if (command_name_input == "PLACE")
        {
            if (!CheckNumberOfArguments(command_name_input, arguments.size(), 3))
            {
                return nullptr;
            }
            int x = 0, y = 0;

            try
            {
                x = ParseInt("X", arguments[0]);
                y = ParseInt("Y", arguments[1]);
            }
            catch (std::invalid_argument e)
            {
                std::cout << e.what();
                return nullptr;
            }

            std::string facing = arguments[2];
            return commandFactory->CreatePlaceCommand(x, y, facing);
        }
        else if (command_name_input == "RIGHT")
        {
            return commandFactory->CreateRightCommand();
        }
        else if (command_name_input == "LEFT")
        {
            return commandFactory->CreateLeftCommand();
        }
        else if (command_name_input == "MOVE")
        {
            return commandFactory->CreateMoveCommand();
        }
        else if (command_name_input == "REPORT")
        {
            return commandFactory->CreateReportCommand();
        }
        else if (command_name_input == "TABLE")
        {
            return commandFactory->CreateTableCommand();
        }

        // Invalid command
        std::cout << "Command not found\n\n";
        return nullptr;
    }

    bool Parser::CheckNumberOfArguments(const std::string &command_name, const int providedNumberOfArguments, const int expectedNumberOfArguments) const
    {
        if (providedNumberOfArguments != expectedNumberOfArguments)
        {
            std::cout << "The " << command_name << " command takes " << expectedNumberOfArguments << " but you provided " << providedNumberOfArguments << ".\n\n";
            return false;
        }
        return true;
    }

    int Parser::ParseInt(const std::string &parameterName, const std::string &intString) const
    {
        int intValue = 0;
        try
        {
            intValue = std::stoi(intString);
        }
        catch (std::invalid_argument _)
        {
            throw std::invalid_argument("Failed to parse the " + parameterName + ".\nPlease provide an integer.");
        }

        return intValue;
    }

}
