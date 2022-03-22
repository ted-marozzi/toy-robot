#pragma once
#include <vector>
#include "../Commands/ICommand.hpp"
#include "../Commands/CommandFactory.hpp"

namespace Robot {
    class ICommand;
    class CommandFactory;

    class IParser {
    public:
        virtual std::unique_ptr<ICommand> ParseCommandLine(const std::string& input, std::unique_ptr<CommandFactory> &commandFactory) const = 0;
    };
}
