#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <GL/glu.h>

#include "header/inputter.h"
#include "header/controll.h"
#include "player/player.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

SDL_Window *gWindow = NULL;
SDL_GLContext gGlContext;

GLfloat rotation;

Inputter inp;
MoveLeft *left;
MoveRight *right;
Controll ctrl;

Player player;

void SetupController()
{
    left = new MoveLeft(&player);
    right = new MoveRight(&player);
}

void SetOpenGLVersion()
{
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
}

void DisplayInitGL()
{
    glShadeModel(GL_SMOOTH);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

int Display_SetViewport(int width, int height)
{
    GLfloat ratio;

    if(height == 0)
    {
        height = 1;
    }

    ratio = GLfloat(width) / GLfloat(height);
    glViewport(0, 0, GLsizei(width), GLsizei(height));
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(45.0f, ratio, 0.1f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    return true;
}

void Display_Render()
{
    glLoadIdentity();
    
    glTranslated(inp.X, 0.0f, -6.0f);
    glRotatef(rotation, 0.0f, 0.0f, 1.0f);

    //glRotatef(-rotation, 0.0f, 0.0f, 1.0f);
    glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3f(0.0f, 1.0f, 0.0f);
        glColor3f(0.0f, 1.0f, 0.0f);        
        glVertex3f(-1.0f, -1.0f, 0.0f);
        glColor3f(0.0f, 0.0f, 1.0f);        
        glVertex3f(1.0f, -1.0f, 0.0f);
    glEnd();

    player.draw();

    // glLoadIdentity();

    // glTranslatef(2.0f, 0.0f, -6.0f);
    // glRotatef(rotation, 0.0f, 0.0f, 1.0f);
    // glColor3f(1.0f, 1.0f, 1.0f);
    

    // glBegin(GL_QUADS);
    //     glVertex3f(-1.0f, 1.0f, 0.0f);
    //     glVertex3f(1.0f, 1.0f, 0.0f);
    //     glVertex3f(1.0f, -1.0f, 0.0f);
    //     glVertex3f(-1.0f, -1.0f, 0.0f);
    // glEnd();
    rotation += 1.0f;
}

void close()
{
    SDL_DestroyWindow(gWindow);
    gWindow == NULL;

    delete(left);
    delete(right);

    SDL_Quit();
}

int main(int argc, char *argv[])
{
    // initialize sdl
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "SDL cannot init with error " << SDL_GetError() << std::endl;
        return -1;
    }

    //set opengl version to use int this program
    SetOpenGLVersion();

    gWindow = SDL_CreateWindow(
        "Opengl",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        SCREEN_WIDTH, SCREEN_HEIGHT,
        SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN
    );
    if (gWindow == NULL)
    {
        std::cout << "Cannot create window with error " << SDL_GetError() << std::endl;
        return -1;
    }

    //create opengl context
    gGlContext = SDL_GL_CreateContext(gWindow);
    if(gGlContext == NULL)
    {
        std::cout << "Cannot create OpenGL context with error " << SDL_GetError() << std::endl;
        return -1;
    }

    //initialize opengl
    DisplayInitGL();
    //set camera
    Display_SetViewport(SCREEN_WIDTH, SCREEN_HEIGHT);

    SetupController();

    bool quit = false;

    SDL_Event sdlEvent;

    while(!quit)
    {
        while(SDL_PollEvent(&sdlEvent) != 0)
        {
            switch(sdlEvent.type)
            {
                case SDL_KEYDOWN:
                    switch(sdlEvent.key.keysym.sym)
                    {
                        case SDLK_LEFT:
                            ctrl.StoreAndExecute(leftDown);
                        break;
                        case SDLK_RIGHT:
                            ctrl.StoreAndExecute(rightDown);
                        break;
                    }
                break;
                case SDL_KEYUP:
                    switch(sdlEvent.key.keysym.sym)
                    {
                        case SDLK_LEFT:
                            ctrl.StoreAndExecute(leftUp);
                        break;
                        case SDLK_RIGHT:
                            ctrl.StoreAndExecute(rightUp);
                        break;
                    }
                break;
                case SDL_QUIT:
                    quit = true;
                break;
            }
        }

        //clear the bg color and depth buffer
        //glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        //render stuff here
        Display_Render();

        //swap window inorder to update opengl
        SDL_GL_SwapWindow(gWindow);

        SDL_Delay(16);
    }

    //clear resources
    close();

    return 0;
}