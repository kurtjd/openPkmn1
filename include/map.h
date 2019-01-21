#ifndef MAP_H
#define MAP_H

#include "display_globals.h"
#include "tile.h"
#include "gameobject.h"

// The map dimensions in tiles
#define MAP_WIDTH (SCREEN_WIDTH / TILE_SIZE)
#define MAP_HEIGHT (SCREEN_HEIGHT / TILE_SIZE)

// Max size of the map in tiles
#define MAP_MAX_WIDTH 15
#define MAP_MAX_HEIGHT 15

void map_load(TileType map[MAP_MAX_HEIGHT][MAP_MAX_WIDTH]);

// Converts each tile in map to gameobject.
void map_tiles_to_objects(TileType map[MAP_MAX_HEIGHT][MAP_MAX_WIDTH], GameObject* gameobjects, Tile* gametiles, Sprite* gamesprites);

#endif
