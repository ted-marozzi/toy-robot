#pragma once
#include <string>
#include <memory>
#include "Parser/IParser.hpp"
#include "Commands/ICommand.hpp"
#include "Commands/CommandFactory.hpp"

namespace Robot
{
    class ICommand;
    class IParser;
    class CommandFactory;
    class ToyRobot
    {
    public:
        ToyRobot(std::unique_ptr<IParser> parser, std::unique_ptr<CommandFactory> command_factory)
            : m_parser{std::move(parser)},
              m_commandFactory{std::move(command_factory)}{};
        ~ToyRobot() {}
        void Introduction() const;
        void Help() const;
        void TurnOn();
        int m_x = -1, m_y = -1;
        std::string m_facing;
    private:
        std::unique_ptr<IParser> m_parser;
        std::unique_ptr<CommandFactory> m_commandFactory;
    };
}
