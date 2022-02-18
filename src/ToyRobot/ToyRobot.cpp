#include <iostream>
#include <string>
#include <memory>
#include <bits/stdc++.h>
#include <sstream>
#include "ToyRobot.hpp"
#include "Commands/Place.hpp"
#include "Commands/Command.hpp"

namespace Robot
{
    // We can either use a shared pointer if the commands are stateless, given we pass an actor in I think the command itself
    // will be stateless
    std::unordered_map<std::string, std::shared_ptr<Command>> COMMAND_MAP = {{"PLACE", std::make_shared<Place>()}};

    // Or return the make_unique function if we want to create a new unique pointer for every command instance.
    std::unordered_map<std::string, std::function<std::unique_ptr<Command>(void)>> COMMAND_MAP_UNIQUE = {{"PLACE", std::make_unique<Place>}};

    const std::string ToyRobot::Introduction()
    {
        return "Hi, I am a Toy Robot\n";
    }

    const std::string ToyRobot::ListCommands()
    {
        std::stringstream command_ss;
        command_ss << "The following commands are avaliable:\n";
        for (auto const &pair : COMMAND_MAP)
        {
            command_ss << pair.first << "\n";
        }
        return command_ss.str();
    }

    void ToyRobot::ParseInput()
    {
        std::cout << Introduction() << ListCommands();

        // Read commands in line by line
        for (std::string line; std::getline(std::cin, line);)
        {
            // Let the robot interpret the commands
            auto command = ParseCommand(line);
            // Unrecognised command
            if (!command)
            {
                std::cout << "Invalid command: " << line << "\n";
                continue;
            }

            command->Execute(*this);
        }
    }

    std::shared_ptr<Command> ToyRobot::ParseCommand(std::string line)
    {
        return COMMAND_MAP[line];
    }

    std::unique_ptr<Command> ToyRobot::ParseUniqueCommand(std::string line)
    {
        auto command_ptr = COMMAND_MAP_UNIQUE[line];
        // If the command function is found then execute it
        return command_ptr ? command_ptr() : nullptr;
    }
}
