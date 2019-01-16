#ifndef SDL_HELPER_FUNCS_H
#define SDL_HELPER_FUNCS_H

#include <stdbool.h>
#include <SDL2/SDL.h>

// Handles initializing SDL and all error checking
bool SDL_Init_Full(SDL_Window** window, SDL_Renderer** renderer, const char* wintitle, int width, int height);

// Handles cleaning up all SDL related things after application close
void SDL_Close(SDL_Window** window, SDL_Renderer** renderer);

// Limits application to desired framerate in Frames Per Second (FPS)
void SDL_SetFrameLimit(int framerate);

#endif
