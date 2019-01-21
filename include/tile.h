#ifndef TILE_H
#define TILE_H

// The length of a side of a tile in pixels.

#include <stdbool.h>
#include "sprite.h"

typedef enum
{
	TILE_BLANK,
	TILE_LIGHT_GRASS_1
} TileType;

typedef struct
{
	TileType type;
	bool is_wall;
	bool is_door;
	bool is_sign;
	bool is_habitat;
} Tile;

#endif
