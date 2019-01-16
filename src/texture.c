#include <stdbool.h>
#include <SDL2/SDL_image.h>
#include "texture.h"

SDL_Texture* texture_init(Texture* texture, SDL_Renderer* renderer, const char* filepath)
{
	texture_initSetCK(texture, renderer, filepath, false, 0, 0, 0);
}

SDL_Texture* texture_initSetCK(Texture* texture, SDL_Renderer* renderer, const char* filepath, bool colorkeyon, int r, int g, int b)
{
	texture_free(texture);

	texture->renderer = renderer;

	if (colorkeyon)
		texture_loadFromFileSetCK(texture, filepath, true, r, g, b);
	else
		texture_loadFromFile(texture, filepath);

	return texture->texture;
}

void texture_free(Texture* texture)
{
	if(texture && texture->texture)
	{
		SDL_DestroyTexture(texture->texture);
		texture->texture = NULL;
		texture->width = 0;
		texture->height = 0;
	}
}

SDL_Texture* texture_loadFromFile(Texture* texture, const char* filepath)
{
	texture_loadFromFileSetCK(texture, filepath, false, 0, 0, 0);
}

SDL_Texture* texture_loadFromFileSetCK(Texture* texture, const char* filepath, bool colorkeyon, int r, int g, int b)
{
	// Clear the previous texture.
	texture_free(texture);

	SDL_Texture* newtexture = NULL;
	SDL_Surface* surface = IMG_Load(filepath);

	if (surface)
	{
		if (colorkeyon)
		{
			if (SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, r, g, b)) < 0)
				printf("Could not set color key because %s\n", SDL_GetError());
		}

		newtexture = SDL_CreateTextureFromSurface(texture->renderer, surface);

		if (!newtexture)
			printf("Unable to create texture from %s because %s\n", filepath, SDL_GetError());

		texture->width = surface->w;
		texture->height = surface->h;

		SDL_FreeSurface(surface);
	}
	else
		printf("Unable to load %s because %s\n", filepath, SDL_GetError());

	texture->texture = newtexture;

	return texture->texture;
}

void texture_render(Texture* texture, int x, int y, SDL_Rect* clip)
{
	SDL_Rect renderrect = {x, y, texture->width, texture->height};

	// If a clip rect was provided, only render that part of the texture. If not, render whole thing.
	if (clip)
	{
		renderrect.w = clip->w;
		renderrect.h = clip->h;
	}

	SDL_RenderCopy(texture->renderer, texture->texture, clip, &renderrect);
}
