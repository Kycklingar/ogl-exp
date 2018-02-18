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
    glTranslatef(0.0f, 0.0f, -6.0f);
    glBegin(GL_TRIANGLES);

    if (_state == MOVING)
    {
        glColor3f(1.0f, 0.0f, 0.0f);
    }
    else
    {
        glColor3f(0.0f, 1.0f, 0.0f);
    }

    glVertex3f(x-0.1f, y-0.1f, 0.0f);
    glVertex3f(x+0.1f, y-0.1f, 0.0f);
    glVertex3f(x, y+0.1f, 0.0f);
    glEnd();
}

void Player::MoveLeft()
{
    x -= 0.1f;
}

void Player::MoveRight()
{
    x += 0.1f;
}