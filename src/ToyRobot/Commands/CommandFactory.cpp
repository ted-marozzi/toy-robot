#include <iostream>
#include "CommandFactory.hpp"
#include "Move.hpp"
#include "Left.hpp"
#include "Right.hpp"
#include "Place.hpp"
#include "Report.hpp"

namespace Robot
{
    void CommandFactory::ListCommands() const
    {
        std::cout << "The following commands are avaliable:\n"
                  << "PLACE X,Y,FACING\n"
                  << "MOVE\n"
                  << "LEFT\n"
                  << "RIGHT\n"
                  << "REPORT\n"
                  << "\n";
    }

    std::unique_ptr<ICommand> CommandFactory::CreateMoveCommand() const
    {
        return std::make_unique<Move>();
    }

    std::unique_ptr<ICommand> CommandFactory::CreateReportCommand() const
    {
        return std::make_unique<Report>();
    }

    std::unique_ptr<ICommand> CommandFactory::CreateLeftCommand() const
    {
        return std::make_unique<Left>();
    }

    std::unique_ptr<ICommand> CommandFactory::CreateRightCommand() const
    {
        return std::make_unique<Right>();
    }

    std::unique_ptr<ICommand> CommandFactory::CreatePlaceCommand(int x, int y, std::string facing) const
    {
        return std::make_unique<Place>(x, y, facing);
    }
}