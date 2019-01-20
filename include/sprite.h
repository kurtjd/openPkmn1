#ifndef SPRITE_H
#define SPRITE_H

#include "texture.h"

typedef struct
{
	// The sprite's current x and y positions.
	int x;
	int y;

	// The texture associated with this sprite.
	Texture* texture;

	// Current frame sprite is showing.
	int frame_on;

	// The animation speed. The higher the num, the slower.
	// It represents how many render frames a single animation frame should last on screen.
	int anim_speed;

	// A list of rectangles for each frame of animation.
	SDL_Rect* frames;
} Sprite;

static void sprite_init(Sprite* sprite, Texture* texture, SDL_Rect* frames, int anim_speed);

static void sprite_free(Sprite* sprite);

void sprite_render(Sprite* sprite);

void sprites_initAll(Sprite** sprites, Texture* spritesheet, SDL_Rect sprite_frames[][SPRITE_MAX_FRAMES], const int NUM_SPRITES);

void sprites_freeAll(Sprite** sprites, const int NUM_SPRITES);

#endif
