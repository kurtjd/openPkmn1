#include "sprite.h"

static void sprite_init(Sprite* sprite, Texture* texture, SDL_Rect* frames)
{
	if (!sprite || !texture || !frames)
		return;

	sprite->texture = texture;
	sprite->frames = frames;
}

void sprite_render(Sprite* sprite, int x, int y, int frame_on)
{
	texture_render(sprite->texture, x, y, &sprite->frames[frame_on]);
}

void sprites_initAll(Sprite* sprites, Texture* spritesheet, SDL_Rect sprite_frames[][SPRITE_MAX_FRAMES], const int NUM_SPRITES)
{
	for (int i = 0; i < NUM_SPRITES; i++)
		sprite_init(&sprites[i], spritesheet, sprite_frames[i]);
}
