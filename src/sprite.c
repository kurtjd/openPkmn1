#include "sprite.h"

void sprite_init(Sprite* sprite, Texture* texture, SDL_Rect frames[], int num_frames)
{
	if (!sprite || !texture || !frames)
		return;

	sprite->x = 0;
	sprite->y = 0;
	sprite->texture = texture;
	sprite->num_frames = num_frames;
	sprite->frame_on = 0;
	sprite->frames = calloc(sprite->num_frames, sizeof *frames);

	for (int i = 0; i < num_frames; i++)
		sprite->frames[i] = frames[i];
}

void sprite_render(Sprite* sprite)
{
	texture_render(sprite->texture, sprite->x, sprite->y, &sprite->frames[sprite->frame_on]);
}

void sprite_free(Sprite* sprite)
{
	free(sprite->frames);
	sprite->frames = NULL;
	sprite->texture = NULL;
}
