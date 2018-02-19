#ifndef ICOMMAND
#define ICOMMAND

class ICommand
{
public:
    virtual void ExecuteDown() = 0;
    virtual void ExecuteUp() = 0;
};

#endif