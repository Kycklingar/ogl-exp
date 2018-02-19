#include "command.h"
#include "../player/player.h"
#include <iostream>

class MoveLeft : public ICommand
{
public:
    MoveLeft(Player *player){_player = player;}
    void ExecuteDown()
    {
        // _player->MoveLeftDown();
        _player->_xDir += -1.0f;
    }
    void ExecuteUp()
    {
        // _player->MoveLeftUp();
        _player->_xDir -= -1.0f;        
    }
private:
    Player *_player;
};

class MoveRight : public ICommand
{
public:
    MoveRight(Player *player){_player = player;}
    void ExecuteDown()
    {
        // _player->MoveRightDown();
        _player->_xDir += 1.0f;
    }
    void ExecuteUp()
    {
        // _player->MoveRightUp();
        _player->_xDir -= 1.0f;
    }
private:
    Player *_player;
};

class MoveUp : public ICommand
{
public:
    MoveUp(Player *player){_player = player;}
    void ExecuteDown()
    {
        std::cout << "UPD" << std::endl;
        _player->_yDir += 1.0f;
    }
    void ExecuteUp()
    {
        std::cout << "UPU" << std::endl;
        _player->_yDir -= 1.0f;
    }
private:
    Player *_player;
};

class MoveDown : public ICommand
{
public:
    MoveDown(Player *player){_player = player;}
    void ExecuteDown()
    {
        _player->_yDir += -1.0f;
    }
    void ExecuteUp()
    {
        _player->_yDir -= -1.0f;
    }
private:
    Player *_player;
};