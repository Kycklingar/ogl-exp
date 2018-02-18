#include "command.h"
#include "../player/player.h"

class Inputter
{
public:
    void Move(float x)
    {
        X += x;
    }
    float X, Y;
};

class MoveLeft : public ICommand
{
public:
    MoveLeft(Player *player){_player = player;}
    void Execute()
    {
        _player->MoveLeft();
    }
private:
    Player *_player;
};

class MoveRight : public ICommand
{
public:
    MoveRight(Player *player){_player = player;}
    void Execute()
    {
        _player->MoveRight();
    }
private:
    Player *_player;
};