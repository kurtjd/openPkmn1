#ifndef POKEMON_H
#define POKEMON_H

#define PKMN_NAME_MAX_LEN 12
#define PKMN_NICKNAME_MAX_LEN 12
#define PKMN_DESC_MAX_LEN 50

typedef struct
{
	int pokedex_number;
	char name[PKMN_NAME_MAX_LEN];

	// IE: Charmander->Lizard, Squirtle->Tiny Turtle. Not to be confused with personal nickname for owned Pokemon.
	char nickname[PKMN_NICKNAME_MAX_LEN];

	int height_in;
	int weight_lbs;
	char description[PKMN_DESC_MAX_LEN];
} Pokemon;

#endif
