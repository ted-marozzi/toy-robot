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
        ToyRobot(std::unique_ptr<IParser> parser) : m_parser{std::move(parser)} {}
        ~ToyRobot() {}
        void Introduction() const;
        void Help() const;
        void ParseInput();
        int m_x, m_y;
        std::string m_facing;
    private:
        std::unique_ptr<IParser> m_parser;
        std::unique_ptr<CommandFactory> m_command_factory{};
    };
}
