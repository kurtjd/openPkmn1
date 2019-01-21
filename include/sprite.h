#ifndef SPRITE_H
#define SPRITE_H

#include "texture.h"

typedef struct
{
	// The texture associated with this sprite.
	Texture* texture;

	// A list of rectangles for each frame of animation.
	SDL_Rect* frames;
} Sprite;

static void sprite_init(Sprite* sprite, Texture* texture, SDL_Rect* frames);

void sprite_render(Sprite* sprite, int x, int y, int frame_on);

void sprites_initAll(Sprite* sprites, Texture* spritesheet, SDL_Rect sprite_frames[][SPRITE_MAX_FRAMES], const int NUM_SPRITES);

#endif
