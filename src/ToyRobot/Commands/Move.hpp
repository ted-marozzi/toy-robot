#pragma once

#include <string>
#include <memory>
#include "../ToyRobot.hpp"
#include "ICommand.hpp"

namespace Robot
{
    class Move : public ICommand
    {
    public:
        Move(std::shared_ptr<ITable> table) : m_table{ table } {};
        virtual void Execute(ToyRobot &toyRobot) const override;
    private:
        std::shared_ptr<ITable> m_table;
    };
}
