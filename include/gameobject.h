#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "sprite.h"
#include "tile.h"

typedef struct
{
	// Things all GameObjects will have.
	int x;
	int y;
	int frame_on;
	Sprite* sprite;

	// Things some GameObjects will have. If they do not, the value will be set to NULL.
	Tile* tile;
} GameObject;

void gameobject_init(GameObject* go, int x, int y, Sprite* sprite, Tile* tile);

void gameobject_render(GameObject* go);

void gameobjects_init_all(GameObject* gameobjects);

void gameobjects_render_all(GameObject* gameobjects);

#endif
