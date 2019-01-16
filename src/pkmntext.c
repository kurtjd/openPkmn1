#include "pkmntext.h"

#define ASCII_UPPER_A 65
#define ASCII_ZERO 48

static char pkmntext_toChar(PkmnText pkmnchar)
{
	char realchar;

	// If a letter or number, add the difference between the ASCII value of A or 0 and the Pkmn value of A or 0
	if (pkmnchar >= PKMN_CHAR_UPPER_A && pkmnchar <= PKMN_CHAR_LOWER_Z)
		realchar = (pkmnchar + (ASCII_UPPER_A - PKMN_CHAR_UPPER_A));
	else if (pkmnchar >= PKMN_CHAR_ZERO && pkmnchar <= PKMN_CHAR_NINE)
		realchar = (pkmnchar + (ASCII_ZERO - PKMN_CHAR_ZERO));

	// If punctuation, manually convert to correct char. If special char, convert all to blank space.
	else
	{
		switch (pkmnchar)
		{
			case PKMN_CHAR_OPEN_PAREN:
				realchar = '(';
				break;
			case PKMN_CHAR_CLOSE_PAREN:
				realchar = ')';
				break;
			case PKMN_CHAR_COLON:
				realchar = ':';
				break;
			case PKMN_CHAR_SEMICOLON:
				realchar = ';';
				break;
			case PKMN_CHAR_OPEN_BRAK:
				realchar = '[';
				break;
			case PKMN_CHAR_CLOSE_BRAK:
				realchar = ']';
				break;
			case PKMN_CHAR_APOS:
				realchar = '\'';
				break;
			case PKMN_CHAR_DASH:
				realchar = '-';
				break;
			case PKMN_CHAR_QUESTION:
				realchar = '?';
				break;
			case PKMN_CHAR_EXCLAM:
				realchar = '!';
				break;
			case PKMN_CHAR_DOT:
				realchar = '.';
				break;
			case PKMN_CHAR_SLASH:
				realchar = '/';
				break;
			case PKMN_CHAR_COMMA:
				realchar = ',';
				break;
			case PKMN_CHAR_NULL:
				realchar = '\0';
				break;
			case PKMN_CHAR_SPACE:
			case PKMN_CHAR_ACCENT_E:
			case PKMN_CHAR_APOS_S:
			case PKMN_CHAR_PK:
			case PKMN_CHAR_MN:
			case PKMN_CHAR_MALE:
			case PKMN_CHAR_FEMALE:
			case PKMN_CHAR_POKEDOLLARS:
				realchar = ' ';
				break;

			default:
				break;
		}
	}

	return realchar;
}

static PkmnText pkmntext_fromChar(char realchar)
{
	PkmnText pkmnchar;
	
	// If a letter or number, subtract the difference between the ASCII value of A or 0 and the Pkmn value of A or 0
	if (realchar >= 'A' && realchar <= 'z')
		pkmnchar = (realchar - (ASCII_UPPER_A - PKMN_CHAR_UPPER_A));
	else if (pkmnchar >= PKMN_CHAR_ZERO && pkmnchar <= PKMN_CHAR_NINE)
		realchar = (pkmnchar - (ASCII_ZERO - PKMN_CHAR_ZERO));
	
	// If punctuation, manually convert to correct char. Since character string can't have special chars, we don't need to handle them.
	else
	{
		switch (realchar)
		{
			case '(':
				pkmnchar = PKMN_CHAR_OPEN_PAREN;
				break;
			case ')':
				pkmnchar = PKMN_CHAR_CLOSE_PAREN;
				break;
			case ':':
				pkmnchar = PKMN_CHAR_COLON;
				break;
			case ';':
				pkmnchar = PKMN_CHAR_SEMICOLON;
				break;
			case '[':
				pkmnchar = PKMN_CHAR_OPEN_BRAK;
				break;
			case ']':
				pkmnchar = PKMN_CHAR_CLOSE_BRAK;
				break;
			case '\'':
				pkmnchar = PKMN_CHAR_APOS;
				break;
			case '-':
				pkmnchar = PKMN_CHAR_DASH;
				break;
			case '?':
				pkmnchar = PKMN_CHAR_QUESTION;
				break;
			case '!':
				pkmnchar = PKMN_CHAR_EXCLAM;
				break;
			case '.':
				pkmnchar = PKMN_CHAR_DOT;
				break;
			case '/':
				pkmnchar = PKMN_CHAR_SLASH;
				break;
			case ',':
				pkmnchar = PKMN_CHAR_COMMA;
				break;
			case ' ':
				pkmnchar = PKMN_CHAR_SPACE;
				break;
			case '\0':
				pkmnchar = PKMN_CHAR_NULL;
				break;
			default:
				break;
		}
	}

	return pkmnchar;
}

void pkmntext_copyToStr(char* dest, PkmnText* src)
{
	while (*dest++ = pkmntext_toChar(*src++));
}

void pkmntext_copyFromStr(PkmnText* dest, char* src)
{
	while (*dest++ = pkmntext_fromChar(*src++));
}
