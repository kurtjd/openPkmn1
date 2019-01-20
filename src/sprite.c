#include "sprite.h"

static void sprite_init(Sprite* sprite, Texture* texture, SDL_Rect* frames, int anim_speed)
{
	if (!sprite || !texture || !frames)
		return;

	sprite->x = 0;
	sprite->y = 0;
	sprite->texture = texture;
	sprite->anim_speed = anim_speed;
	sprite->frame_on = 0;
	sprite->frames = frames;
}

static void sprite_free(Sprite* sprite)
{
	sprite->frames = NULL;
	sprite->texture = NULL;
}

void sprite_render(Sprite* sprite)
{
	texture_render(sprite->texture, sprite->x, sprite->y, &sprite->frames[sprite->frame_on]);
}

void sprites_initAll(Sprite** sprites, Texture* spritesheet, SDL_Rect sprite_frames[][SPRITE_MAX_FRAMES], const int NUM_SPRITES)
{
	for (int i = 0; i < NUM_SPRITES; i++)
	{
		Sprite* sprite = malloc(sizeof *sprite);
		sprite_init(sprite, spritesheet, sprite_frames[i], 1);
		sprites[i] = sprite;
	}
}

void sprites_freeAll(Sprite** sprites, const int NUM_SPRITES)
{
	for (int i = 0; i < NUM_SPRITES; i++)
	{
		sprite_free(sprites[i]);
		sprites[i] = NULL;
		free(sprites[i]);
	}
}
