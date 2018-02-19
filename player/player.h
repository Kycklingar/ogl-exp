#ifndef PLAYER
#define PLAYER

class Player
{
public:
    Player();
    ~Player();
    void draw();

    float _xDir;
    float _yDir;

private:
    float x, y;
    float _xVel, _yVel;

    enum STATE
    {
        IDLE,
        MOVING
    };
    STATE _state;
};

#endif