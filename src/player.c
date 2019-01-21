#include "player.h"

// Sets the player's default name
static void player_name_init(Player *player)
{
	// The Pkmn Trainer who started it all...
	player->name[0] = PKMN_CHAR_UPPER_R;
	player->name[1] = PKMN_CHAR_UPPER_E;
	player->name[2] = PKMN_CHAR_UPPER_D;

	// Fill the rest of name with null characters
	for (int i = 3; i < (PLAYER_NAME_MAX_LEN + 1); i++)
		player->name[i] = PKMN_CHAR_NULL;
}

// Sets all player badges to false because he hasn't earned any yet
static void player_badges_init(Player* player)
{
	for (int i = 0; i < NUM_BADGES; i++)
		player->badges[i] = false;
}

void player_init(Player* player)
{
	player_name_init(player);
	player->pokedollars = PLAYER_START_CASH;
	player->time_played = 0;
	player_badges_init(player);
}
