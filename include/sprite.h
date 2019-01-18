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

	// The number of frames associated with this sprite for animation.
	int num_frames;
	
	// Current frame sprite is showing.
	int frame_on;

	// A list of rectangles for each frame of animation.
	SDL_Rect* frames;
} Sprite;

void sprite_init(Sprite* sprite, Texture* texture, SDL_Rect frames[], int num_frames);

void sprite_render(Sprite* sprite);

void sprite_free(Sprite* sprite);

#endif
