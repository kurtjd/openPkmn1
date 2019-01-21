#include "map.h"

void map_load(TileType map[MAP_MAX_HEIGHT][MAP_MAX_WIDTH])
{
	// Eventually load map externally. For now test map is defined in main()
}

void map_tiles_to_objects(TileType map[MAP_MAX_HEIGHT][MAP_MAX_WIDTH], GameObject* gameobjects, Tile* gametiles, Sprite* gamesprites)
{
	int tile_on = 0;
	for (int y = 0; y < MAP_MAX_HEIGHT; y++)
	{
		for (int x = 0; x < MAP_MAX_WIDTH; x++)
		{
			int xpos = x * TILE_SIZE;
			int ypos = y * TILE_SIZE;
			TileType tiletype = map[y][x];
			Sprite* sprite = &gamesprites[tiletype];
			Tile* tile = &gametiles[tiletype];

			gameobject_init(&gameobjects[tile_on], xpos, ypos, sprite, tile);
			tile_on++;
		}
	}
}
