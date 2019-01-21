#ifndef GAME_GLOBALS_H
#define GAME_GLOBALS_H

#define MAX_GAME_OBJECTS 500
#define NUM_BADGES 8

typedef enum
{
	STATE_TITLESCR,
	STATE_NEWGAME,
	STATE_OVERWORLD,
	STATE_MENU,
	STATE_BATTLE
} GameState;

// Yeah game state is global deal with it
extern GameState GAME_STATE;

#endif
