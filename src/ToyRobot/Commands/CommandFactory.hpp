#pragma once
#include <memory>
#include "ICommand.hpp"

namespace Robot
{
    class ICommand;
    class CommandFactory
    {
    public:
        std::unique_ptr<ICommand> CreateMoveCommand() const;
        std::unique_ptr<ICommand> CreateReportCommand() const;
        std::unique_ptr<ICommand> CreateLeftCommand() const;
        std::unique_ptr<ICommand> CreateRightCommand() const;
        std::unique_ptr<ICommand> CreatePlaceCommand(int x, int y, std::string facing) const;
        void ListCommands() const;
    };
} // namespace Robot
