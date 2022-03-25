#include <iostream>
#include <string>
#include <iterator>

#include "ToyRobot.hpp"
#include "ToyRobot.hpp"
#include "Commands/CommandFactory.hpp"

namespace Robot
{

    void ToyRobot::Introduction() const
    {
        std::cout << "Hi, I am a Toy Robot\n";
    }

    void ToyRobot::Help() const
    {
        m_commandFactory->ListCommands();
    }

    void ToyRobot::TurnOn()
    {
        Introduction();
        Help();

        // Read commands in line by line
        for (std::string line; std::getline(std::cin, line);)
        {
            // Let the robot interpret the commands
            auto command = m_parser->ParseCommandLine(line, m_commandFactory);

            // Unrecognised command
            if (!command)
            {
                Help();
                continue;
            }

            command->Execute(*this);
        }
    }
}
