#include "SDL_helper_funcs.h"

bool SDL_Init_Full(SDL_Window** window, char *wintitle, int width, int height)
{
	if (SDL_Init(SDL_INIT_VIDEO) >= 0)
	{
		*window = SDL_CreateWindow(wintitle, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);

		if(!(*window))
			return 0;
	}
	else
		return 0;

	return 1;
}

void SDL_Close(SDL_Window** window)
{
	SDL_DestroyWindow(*window);
	*window = NULL;

	SDL_Quit();
}

void SDL_SetFrameLimit(int framerate)
{
	static int prevtime = 0;
	int ticks_per_frame = 1000 / framerate;
	int frametime = SDL_GetTicks() - prevtime;
	
	if (frametime < ticks_per_frame)
		SDL_Delay(ticks_per_frame - frametime);
	
	prevtime = SDL_GetTicks();
}
