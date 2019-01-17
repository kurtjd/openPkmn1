#ifndef TEXTURE_H
#define TEXTURE_H

#include <SDL2/SDL.h>
#include "display_globals.h"

typedef struct
{
	int width;
	int height;
	int layer; // Which layer this gets drawn to.

	SDL_Texture* texture;
	SDL_Renderer* renderer;
} Texture;

// Loads all textures from a list of files into an array.
bool textures_loadAll(Texture* textures[], SDL_Renderer* renderer, const char* texture_file_list[], size_t numtextures);

// Frees all textures.
void textures_freeAll(Texture* textures[], size_t numtextures);

// Initializes a texture with an image and associates a renderer to it as well as setting a color as transparent.
SDL_Texture* texture_init(Texture* texture, SDL_Renderer* renderer, const char* filepath, int layer, bool colorkeyon, int r, int g, int b);

// Destroys and frees a texture.
void texture_free(Texture* texture);

// Loads an image into a texture and sets a color to be transparent.
SDL_Texture* texture_loadFromFile(Texture* texture, const char* filepath, int layer, bool colorkeyon, int r, int g, int b);

// Renders the texture to its associated renderer. If provided a clip, only render that part.
void texture_render(Texture* texture, int x, int y, SDL_Rect* clip);

#endif
