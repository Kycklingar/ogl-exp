#include <vector>
#include "command.h"

class Controll
{
public:
    void StoreAndExecute(ICommand *command)
    {
        if(command)
        {
            _commands.push_back(command);
            command->Execute();
        }
    }

private:
    std::vector<ICommand *> _commands;
};