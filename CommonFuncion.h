#ifndef COMMON_FUNCION_H
#define COMMON_FUNCION_H

#include <windows.h>
#include <string>
#include <SDL.h>
#include <SDL_image.h>	//library image
#include <SDL_mixer.h> //library audio
#include <SDL_ttf.h> //library text

static SDL_Window* g_window = NULL;
static SDL_Renderer* g_screen = NULL;
static SDL_Event g_event;

//screen
const int screen_width = 1280;
const int screen_height = 640;
const int screen_bpp = 32;

const int color_key_red = 167;
const int color_key_green = 175;
const int color_key_blue = 180;

const int render_draw_color = 255;

#endif


