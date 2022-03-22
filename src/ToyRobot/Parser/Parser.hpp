#pragma once
#include <vector>
#include <string>
#include "IParser.hpp"
#include "../Commands/ICommand.hpp"

namespace Robot
{
    class Parser : public IParser
    {
    public:
        std::unique_ptr<ICommand> ParseCommandLine(const std::string& input, std::unique_ptr<CommandFactory>& commandFactory) const override;
    private:
        const std::vector<std::string> Split(const std::string &text, const char &delim) const;
        bool CheckNumberOfArguments(const std::string &command_name, const int providedNumberOfArguments, const int expectedNumberOfArguments) const;
        int ParseInt(const std::string &parameterName, const std::string &intString, int minValue, int maxValue) const;
    };
}
