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
	SDL_Init_Full(&gamewindow, &gamerenderer, SCREEN_TITLE, SCREEN_WIDTH, SCREEN_HEIGHT); 

	Texture pkmntrnr;
	texture_initSetCK(&pkmntrnr, gamerenderer, "sprites/chars_overworld.png", true, 0, 0xFF, 0);
	SDL_Rect pkmntrnr_rect = {112, 268, 16, 18};

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
		texture_render(&pkmntrnr, (SCREEN_WIDTH / 2) - 8, (SCREEN_HEIGHT / 2) - 9, &pkmntrnr_rect);
		SDL_RenderPresent(gamerenderer);
	}
	printf("%s", SDL_GetError());

	texture_free(&pkmntrnr);
	SDL_Close(&gamewindow, &gamerenderer);

	return 0;
}
