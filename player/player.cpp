#include "player.h"
// #include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
// #include <GL/glu.h>


Player::Player()
{
    x = 0.0f;
    y = 0.0f;
    return;
}

Player::~Player()
{
    return;
}

void Player::draw()
{

    glLoadIdentity();
    glTranslatef(x, y, -6.0f);
    glBegin(GL_TRIANGLES);

    if (_state == MOVING)
    {
        glColor3f(1.0f, 0.0f, 0.0f);
    }
    else
    {
        glColor3f(0.0f, 1.0f, 0.0f);
    }

    glVertex3f(-0.1f, -0.1f, 0.0f);
    glVertex3f(0.1f, -0.1f, 0.0f);
    glVertex3f(0.0f, 0.1f, 0.0f);
    glEnd();
}

// Player::Update(float deltaTime)
// {
//     _xVel += _xDir / 50.0f;
//     if(_xVel > 0.1f)
//         _xVel = 0.1f;
//     if(_xVel < -0.1f)
//         _xVel = -0.1f;
//     x += _xVel;
//     _xVel *= 0.50;
//     if(_xVel < 0.0001f && _xVel > -0.0001f)
//         _xVel = 0.0f;

//     _yVel += _yDir / 50.0f;
//     if(_yVel > 0.1f)
//         _yVel = 0.1f;
//     if(_yVel < -0.1f)
//         _yVel = -0.1f;
//     y += _yVel;
//     _yVel *= 0.50;
//     if(_yVel < 0.0001f && _yVel > -0.0001f)
//         _yVel = 0.0f;
// }
