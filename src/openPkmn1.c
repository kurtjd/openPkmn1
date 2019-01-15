#include <stdio.h>
#include "SDL_helper_funcs.h"
#include "game_global_constants.h"

int main(void)
{
	SDL_Window* gamewindow;

	SDL_Init_Full(&gamewindow, SCREEN_TITLE, SCREEN_WIDTH, SCREEN_HEIGHT); 

	SDL_Delay(2000);

	SDL_Close(&gamewindow);

	return 0;
}
