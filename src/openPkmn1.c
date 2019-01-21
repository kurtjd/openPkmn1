#include <stdio.h>
#include <stdbool.h>
#include "SDL_helper_funcs.h"
#include "display_globals.h"
#include "game_globals.h"
#include "texture.h"
#include "sprite.h"
#include "map.h"
#include "gameobject.h"

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
		// Tiles
		{{151, 2, 16, 16}}, //TILE_BLANK
		{{166, 18, 16, 16}}, //TILE_LIGHT_GRASS_1

		// NPCs
		{{111, 268, 15, 17}, {50, 60, 10, 10}} // NPC_PLAYER (oxymoron I know)
	};
	const int NUM_SPRITES = (sizeof sprite_frames) / (sizeof *sprite_frames);
	Sprite gamesprites[NUM_SPRITES];
	sprites_initAll(gamesprites, &spritesheet, sprite_frames, NUM_SPRITES);

	// Define and initialize all tiles.
	// These will also be defined in the editor.
	Tile gametiles[] = {
		{TILE_BLANK, false, false, false, false},
		{TILE_LIGHT_GRASS_1, false, false, false, false}
	};

	// A map is a 2D array of tiles. Right now define map manually but eventually load maps from data file.
	TileType map[MAP_MAX_HEIGHT][MAP_MAX_WIDTH] = {
		{TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK},
		{TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK},
		{TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK},
		{TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK},
		{TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK},
		{TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK},
		{TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK},
		{TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK},
		{TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK},
		{TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK},
		{TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK},
		{TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK},
		{TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK},
		{TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK},
		{TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK, TILE_LIGHT_GRASS_1, TILE_BLANK}
	};
	//map_load(map);

	// Holds all GameObjects that need to be handled for current section of game.
	GameObject gameobjects[MAX_GAME_OBJECTS];
	gameobjects_init_all(gameobjects);

	// Create tile game objects from the map.
	map_tiles_to_objects(map, gameobjects, gametiles, gamesprites);

	// Player character
	//gameobject_init(&gameobjects[MAP_MAX_HEIGHT * MAP_MAX_WIDTH], (SCREEN_WIDTH / 2) - 14, (SCREEN_HEIGHT / 2) - 16, &gamesprites[2], NULL);
	
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
		gameobjects_render_all(gameobjects);
		// End render testing here
		SDL_RenderPresent(gamerenderer);
	}

	//sprites_freeAll(gamesprites, NUM_SPRITES);
	texture_free(&spritesheet);
	SDL_Close(&gamewindow, &gamerenderer);

	return 0;
}
