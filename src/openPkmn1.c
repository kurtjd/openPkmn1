#include <stdio.h>
#include <stdbool.h>
#include "SDL_helper_funcs.h"
#include "display_globals.h"
#include "player.h"

int main(void)
{
	bool userquit = 0; // Whether or not user has quit application

	Player player;
	player_init(&player);
	char playername[8];
	pkmntext_copyToStr(playername, player.name);
	printf("%s\n", playername);

	SDL_Window* gamewindow;
	SDL_Init_Full(&gamewindow, SCREEN_TITLE, SCREEN_WIDTH, SCREEN_HEIGHT); 

	while (!userquit)
	{
		SDL_SetFrameLimit(FPS);

		SDL_Event e;
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
				userquit = true;
		}
	}

	SDL_Close(&gamewindow);

	return 0;
}
