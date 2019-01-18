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

	// Define all textures and load them into memory.
	const char* texture_file_list[] = {
		"sprites/chars_overworld.png",
		"sprites/tileset.png"
	};
	const size_t NUM_TEXTURES = ((sizeof texture_file_list) / (sizeof *texture_file_list));
	Texture* gametextures[NUM_TEXTURES];
	textures_loadAll(gametextures, gamerenderer, texture_file_list, NUM_TEXTURES);

	// Define all sprites and load them into memory.
	// Going to need a better system here. Work in progress.
	// Right now just a test to create a sprite for player.
	Sprite player;
	SDL_Rect player_frames[] = {{111, 268, 15, 17}};
	sprite_init(&player, gametextures[0], player_frames, (sizeof player_frames) / (sizeof *player_frames));

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
		sprite_render(&player);
		// End render testing here
			
		SDL_RenderPresent(gamerenderer);
	}

	sprite_free(&player); // Free test sprite.
	textures_freeAll(gametextures, NUM_TEXTURES);
	SDL_Close(&gamewindow, &gamerenderer);

	return 0;
}
