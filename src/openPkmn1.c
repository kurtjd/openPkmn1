#include <stdio.h>
#include <stdbool.h>
#include "SDL_helper_funcs.h"
#include "texture.h"
#include "sprite.h"
#include "display_globals.h"
#include "player.h"

int main(void)
{
	bool userquit = 0; // Whether or not user has quit application
	
	// Initialize game window and renderer.
	SDL_Window* gamewindow;
	SDL_Renderer* gamerenderer;
	SDL_Init_Full(&gamewindow, &gamerenderer, SCREEN_TITLE, SCREEN_WIDTH, SCREEN_HEIGHT); 

	// Load and intialize the spritesheet texture.
	Texture spritesheet;
	texture_init(&spritesheet, gamerenderer, TEXTURE_FILE_PATH);

	// Define all sprites and their frames.
	// Manually define for now. Eventually frames will be defined in an editor and loaded from a data file.
	SDL_Rect sprite_frames[][SPRITE_MAX_FRAMES] = {
		{{111, 268, 15, 17}, {50, 60, 10, 10}} // Player character
	};
	const int NUM_SPRITES = (sizeof sprite_frames) / (sizeof *sprite_frames);
	Sprite* gamesprites[NUM_SPRITES];
	sprites_initAll(gamesprites, &spritesheet, sprite_frames, NUM_SPRITES);
	
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

			// Eventually handle game states here...
			switch (GAME_STATE)
			{

			}
		}

		SDL_RenderClear(gamerenderer);
		// Render testing here

		// End render testing here
		SDL_RenderPresent(gamerenderer);
	}

	sprites_freeAll(gamesprites, NUM_SPRITES);
	texture_free(&spritesheet);
	SDL_Close(&gamewindow, &gamerenderer);

	return 0;
}
