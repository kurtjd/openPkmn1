#ifndef TEXTURE_H
#define TEXTURE_H

#include <SDL2/SDL.h>

typedef struct
{
	int width;
	int height;

	SDL_Texture* texture;
	SDL_Renderer* renderer;
} Texture;

// Initializes a texture with an image and associates a renderer to it.
SDL_Texture* texture_init(Texture* texture, SDL_Renderer* renderer, const char* filepath);

// Initializes a texture with an image and associates a renderer to it as well as setting a color as transparent.
SDL_Texture* texture_initSetCK(Texture* texture, SDL_Renderer* renderer, const char* filepath, bool colorkeyon, int r, int g, int b);

// Destroys and frees a texture.
void texture_free(Texture* texture);

// Loads an image into a texture.
SDL_Texture* texture_loadFromFile(Texture* texture, const char* filepath);

// Loads an image into a texture and sets a color to be transparent.
SDL_Texture* texture_loadFromFileSetCK(Texture* texture, const char* filepath, bool colorkeyon, int r, int g, int b);

// Renders the texture to its associated renderer. If provided a clip, only render that part.
void texture_render(Texture* texture, int x, int y, SDL_Rect* clip);

#endif
