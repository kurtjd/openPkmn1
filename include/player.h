#ifndef PLAYER_H
#define PLAYER_H

#define PLAYER_NAME_MAX_LEN 7
#define PLAYER_START_CASH 3000

#include <stdbool.h>
#include "game_globals.h"
#include "pkmntext.h"
#include "sprite.h"

typedef struct
{
	PkmnText name[PLAYER_NAME_MAX_LEN + 1];
	int pokedollars;
	int time_played;
	bool badges[NUM_BADGES];

	Sprite* sprite;
} Player;

// Initializes a player with default stats
void player_init(Player* player, Sprite* sprite);

#endif
