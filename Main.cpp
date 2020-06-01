// GameSDL2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "CommonFuncion.h"
#include "BaseObjec.h"
#undef main


BaseObject g_background;
bool InitData()
{
    bool success = true;
    int ret = SDL_Init(SDL_INIT_VIDEO);
    if (ret < 0)
    {
        return false;
    }

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

    g_window = SDL_CreateWindow("Game Cpp SDL 2.0",
                                SDL_WINDOWPOS_UNDEFINED, 
                                SDL_WINDOWPOS_UNDEFINED, 
                                screen_width, 
                                screen_height, 
                                SDL_WINDOW_SHOWN);
    
    if (g_window==NULL)
    {
        success = false;
    }
    else
    {
        g_screen = SDL_CreateRenderer(g_window, -1, SDL_RENDERER_ACCELERATED);
        if (g_screen==NULL)
        {
            success = false;
        }
        else
        {
            SDL_SetRenderDrawColor(g_screen, render_draw_color, render_draw_color, render_draw_color, render_draw_color);
            int imgFlags = IMG_INIT_PNG;
            if (!(IMG_Init(imgFlags) && imgFlags))
            {
                success = false;

            }
        }
    }
    return success;
}

bool LoadBackground()
{
    bool ret = g_background.LoadImg("img//background.png",g_screen);
    if (!ret)
    {
        return false;
    }
    
    return true;
}

void close()
{
    g_background.Free();

    SDL_DestroyRenderer(g_screen);
    g_screen = NULL;

    SDL_DestroyWindow(g_window);
    g_window = NULL;

    IMG_Quit();
    SDL_Quit();
}

int main(int argc, char* argv[])
{
    if (InitData() == false)
    {
        return -1;
    }

    if (LoadBackground() == false)
    {
        return -1;
    }

    bool is_quit = false;
    while (!is_quit)
    {
        while (SDL_PollEvent(&g_event) != 0)
        {
            if (g_event.type == SDL_QUIT)
            {
                is_quit = true;
            }
        }
        SDL_SetRenderDrawColor(g_screen, render_draw_color, render_draw_color, render_draw_color, render_draw_color);
        SDL_RenderClear(g_screen);

        g_background.Render(g_screen, NULL);

        SDL_RenderPresent(g_screen);


    }

    close();
    return 0;
}
