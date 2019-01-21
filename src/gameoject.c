#include "gameobject.h"
#include "game_globals.h"

void gameobject_init(GameObject* go, int x, int y, Sprite* sprite, Tile* tile)
{
	if (go)
	{
		go->x = x;
		go->y = y;
		go->frame_on = 0;
		go->sprite = sprite;
		go->tile = tile;
	}
}

void gameobject_render(GameObject* go)
{
	sprite_render(go->sprite, go->x, go->y, go->frame_on);
}

void gameobjects_init_all(GameObject* gameobjects)
{
	for (int i = 0; i < MAX_GAME_OBJECTS; i++)
		gameobject_init(&gameobjects[i], 0, 0, NULL, NULL);
}

void gameobjects_render_all(GameObject* gameobjects)
{
	// The gameobjects array might not actually be full, so the first instance of one without a sprite is the end.
	for (int i = 0; gameobjects[i].sprite != NULL; i++)
		gameobject_render(&gameobjects[i]);
}
