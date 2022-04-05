#pragma once
#include <memory>
#include "ICommand.hpp"
#include "../Table/ITable.hpp"

namespace Robot
{
    class ICommand;
    class CommandFactory
    {
    public:
        CommandFactory(std::shared_ptr<ITable> table) : m_table{table} {};
        std::unique_ptr<ICommand> CreateMoveCommand() const;
        std::unique_ptr<ICommand> CreateTableCommand() const;
        std::unique_ptr<ICommand> CreateReportCommand() const;
        std::unique_ptr<ICommand> CreateLeftCommand() const;
        std::unique_ptr<ICommand> CreateRightCommand() const;
        std::unique_ptr<ICommand> CreatePlaceCommand(int x, int y, std::string facing) const;
        void ListCommands() const;
    private:
        std::shared_ptr<ITable> m_table;
    };
} // namespace Robot
