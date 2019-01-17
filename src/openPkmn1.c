#include <stdio.h>
#include <stdbool.h>
#include "SDL_helper_funcs.h"
#include "texture.h"
#include "display_globals.h"
#include "player.h"

int main(void)
{
	bool userquit = 0; // Whether or not user has quit application
	
	SDL_Window* gamewindow;
	SDL_Renderer* gamerenderer;

	const char* texture_file_list[] = {
		"sprites/chars_overworld.png",
		"sprites/tileset.png"
	};
	const size_t NUM_TEXTURES = (sizeof texture_file_list / sizeof *texture_file_list);
	Texture* gametextures[NUM_TEXTURES];

	SDL_Init_Full(&gamewindow, &gamerenderer, SCREEN_TITLE, SCREEN_WIDTH, SCREEN_HEIGHT); 
	textures_loadAll(gametextures, gamerenderer, texture_file_list, NUM_TEXTURES);

	while (!userquit)
	{
		SDL_SetFrameLimit(FPS);

		SDL_Event e;
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
			{
				userquit = true;
				break;
			}

			switch (GAME_STATE)
			{

			}
		}

		SDL_RenderClear(gamerenderer);
		// Render textures here
		SDL_RenderPresent(gamerenderer);
	}

	textures_freeAll(gametextures, NUM_TEXTURES);
	SDL_Close(&gamewindow, &gamerenderer);

	return 0;
}
