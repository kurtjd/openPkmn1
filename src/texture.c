#include <stdbool.h>
#include <SDL2/SDL_image.h>
#include "texture.h"

bool textures_loadAll(Texture* textures[], SDL_Renderer* renderer, const char* texture_file_list[], size_t numtextures)
{
	for (size_t i = 0; i < numtextures; i++)
	{
		textures[i] = malloc(sizeof *textures[i]);

		if (!(textures[i]))
			return false;

		if (!(texture_init(textures[i], renderer, texture_file_list[i])))
			return false;
	}

	return true;
}

void textures_freeAll(Texture* textures[], size_t numtextures)
{
	for (size_t i = 0; i < numtextures; i++)
	{
		if (textures[i])
		{
			texture_free(textures[i]);
			free(textures[i]);
			textures[i] = NULL;
		}
	}
}

SDL_Texture* texture_init(Texture* texture, SDL_Renderer* renderer, const char* filepath)
{
	texture->texture = NULL;
	texture->renderer = renderer;

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
	// Clear the previous texture.
	texture_free(texture);

	SDL_Texture* newtexture = NULL;
	SDL_Surface* surface = IMG_Load(filepath);

	if (surface)
	{
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
