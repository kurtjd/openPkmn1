#include <SDL2/SDL_image.h>
#include "SDL_helper_funcs.h"

bool SDL_Init_Full(SDL_Window** window, SDL_Renderer** renderer, const char* wintitle, int width, int height)
{
	if (SDL_Init(SDL_INIT_VIDEO) >= 0)
	{
		*window = SDL_CreateWindow(wintitle, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
		if(!(*window))
		{
			printf("Could not create SDL window because %s\n", SDL_GetError());
			return false;
		}

		// Obviously want hardware acceleration, but do not want vSync because we use max framerate.
		*renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED);
		if(*renderer)
		{
			// Basically gives a black background whenever SDL_RenderClear is called
			SDL_SetRenderDrawColor(*renderer, 0x00, 0x00, 0x00, 0x00);

			// Uses bitwise AND to check if the image types we want to work with can be initialized.
			// For now just PNGs
			int imgflags = IMG_INIT_PNG;
			if (!(IMG_Init(imgflags) & imgflags))
			{
				printf("SDL_Image could not initialize because %s\n", SDL_GetError());
				return false;
			}
		}
		else
		{
			printf("Could not create renderer because %s\n", SDL_GetError());
			return false;
		}
	}
	else
	{
		printf("Could not initialize SDL because %s\n", SDL_GetError());
		return false;
	}

	return true;
}

void SDL_Close(SDL_Window** window, SDL_Renderer** renderer)
{
	SDL_DestroyRenderer(*renderer);
	*renderer = NULL;
	SDL_DestroyWindow(*window);
	*window = NULL;

	IMG_Quit();
	SDL_Quit();
}

void SDL_SetFrameLimit(int framerate)
{
	// This is static because we don't want it reset every frame.
	static int prevtime = 0;
	int ticks_per_frame = 1000 / framerate;
	int frametime = SDL_GetTicks() - prevtime;
	
	// If the current frame went too fast, delay the app to limit framerate
	if (frametime < ticks_per_frame)
		SDL_Delay(ticks_per_frame - frametime);
	
	prevtime = SDL_GetTicks();
}
