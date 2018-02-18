#ifndef PLAYER
#define PLAYER

class Player
{
public:
    Player();
    ~Player();
    void draw();
    void MoveRight();
    void MoveLeft();
private:
    float x, y;
    enum STATE
    {
        IDLE,
        MOVING
    };
    STATE _state;
};

#endif