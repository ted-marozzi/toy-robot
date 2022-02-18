#pragma once

#include <memory>

namespace Robot
{
    class Command;
    class ToyRobot
    {
    public:
        const std::string Introduction();
        const std::string ListCommands();
        void ParseInput();
        std::shared_ptr<Command> ParseCommand(std::string line);
        std::unique_ptr<Command> ParseUniqueCommand(std::string line);
    };
}
