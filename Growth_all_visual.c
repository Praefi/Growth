
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
//#include <windows.h>	// look at Growth.h
#include <ctype.h>

#ifdef _WIN32
#include <windows.h>
#endif

// #define VERBOSE
// #define Contact_mistake_search
// #define Quidditch_mistake_search

#include "Growth_all_Def.h"
#include "Growth_all_Vektor.h"
#include "Growth_all_Initialisierung.h"
#include "Growth_all_set.h"
#include "Growth_all_get.h"
#include "Growth_all_visual.h"
#include "Growth_all_show.h"

void Square_color_interpretation (Growth_Player* Growth_players, unsigned int geben, unsigned int number_of_players, unsigned int square_number) {
	
	if (Growth_players[0].color == 1) {
		if (square_number != 0) {
			if (square_number <= number_of_players) {
				for (unsigned int p=1; p<=number_of_players; p++) {
					if (Growth_players[p].id == square_number) {
						set_terminal_color (Growth_players[p].color);
					}
				}
			} else {
				if (square_number == 11) {
					set_terminal_color (Growth_players[1].color);
				} else if (square_number == oeluem) {
					set_terminal_color (Growth_players[geben].color);
				} else if (square_number == dogum) {
					set_terminal_color (Growth_players[geben].color);
				} else if (square_number == bir_sey) {
					set_terminal_color (cNORMAL);
				} else if ((square_number >= Roses_0)&&(square_number <= Roses_6)) {
					set_terminal_color (cNORMAL);
				} else if (square_number == Quaffel) {
					set_terminal_color (cRED);
				} else if (square_number == Klatscher) {
					set_terminal_color (cGRAY);
				} else if (square_number == Schnatz) {
					set_terminal_color (cWHITE);
				} else if ((square_number == Treiber_1)||(square_number == Jaeger_1)||(square_number == Sucher_1)||(square_number == Hueter_1)||(square_number == Torring_1)) {
					if (Growth_players[1].color == cLIGHT_MAGENTA) {
						set_terminal_color (cLIGHT_RED);
					} else if (Growth_players[1].color == cLIGHT_CYAN) {
						set_terminal_color (cLIGHT_BLUE);
					} else if (Growth_players[1].color == cYELLOW) {
						set_terminal_color (cBROWN);
					} else if (Growth_players[1].color == cLIGHT_GREEN) {
						set_terminal_color (cGREEN);
					}
				} else if ((square_number == Treiber_2)||(square_number == Jaeger_2)||(square_number == Sucher_2)||(square_number == Hueter_2)||(square_number == Torring_2)) {
					if (Growth_players[2].color == cLIGHT_MAGENTA) {
						set_terminal_color (cLIGHT_RED);
					} else if (Growth_players[2].color == cLIGHT_CYAN) {
						set_terminal_color (cLIGHT_BLUE);
					} else if (Growth_players[2].color == cYELLOW) {
						set_terminal_color (cBROWN);
					} else if (Growth_players[2].color == cLIGHT_GREEN) {
						set_terminal_color (cGREEN);
					}
				} else {
					set_terminal_color (cBROWN);
				}
			}
		}
	}
}

void get_colors (Growth_Player* Growth_players, unsigned int number_of_players, unsigned int gamemode_played, unsigned int AOP) {

	unsigned int Color_choice[13], input;
	input = 0;
	unsigned_int_array_null_initialisierung (Color_choice, 12);


	if (Growth_players[0].color == 1) {
		
		for (unsigned int p=1; p<=AOP; p++) {
			set_player_color (Growth_players, p, cNORMAL);
		}
		Growth_players[0].color = 0;
		printf("	That caused a reset of the chosen colors. \n");
	
	} else {

		printf("	This only works if the number of players is correct! \n");
		printf("	Going here again will lead to a reset of the chosen colors! \n");
		if (gamemode_played == Quidditch) {
			printf("	Your choice will be the color of your house.\n");
		}
		printf(" \n");

		for (unsigned int p=1; p<=number_of_players; ++p) {
			Growth_Player* current_player = &Growth_players[p];
			unsigned int curr_id = current_player->id;

			if (curr_id != p) {
				puts("BOESER FEHLER");
			}

			if (input != 14) {
				printf("	Choose your color, Spieler %u . \n", curr_id);
			}

			while ((input == 0)||(input > 14)||((Color_choice[input-1] != 0)&&(Color_choice[input-1] != curr_id))) {		//pere[] wird zweckentfremdet, da hier noch nicht in Gebrauch, und jetzt ausgetauscht durch Color_choice
				printf(" \n");
				if (gamemode_played != Quidditch) {
					if (Color_choice[0] == 0) {
						set_terminal_color(cWHITE);
						printf("	1) white. \n");
					}
					if (Color_choice[1] == 0) {
						set_terminal_color(cLIGHT_GRAY);
						printf("	2) lightgrey. \n");
					}
					if (Color_choice[2] == 0) {
						set_terminal_color(cGRAY);
						printf("	3) darkgrey. \n");
					}
				}
				
				if (Color_choice[3] == 0) {
					set_terminal_color(cLIGHT_MAGENTA);
					printf("	4) lightmagenta. \n");
				}
				
				if (gamemode_played != Quidditch) {
					if (Color_choice[4] == 0) {
						set_terminal_color(cLIGHT_RED);
						printf("	5) lightred. \n");
					}
					if (Color_choice[5] == 0) {
						set_terminal_color(cRED);
						printf("	6) red. \n");
					}
				}
				
				if (Color_choice[6] == 0) {
					set_terminal_color(cLIGHT_CYAN);
					printf("	7) lightcyan. \n");
				}
				
				if (gamemode_played != Quidditch) {
					if (Color_choice[7] == 0) {
						set_terminal_color(cCYAN);
						printf("	8) cyan. \n");
					}
					if (Color_choice[8] == 0) {
						set_terminal_color(cLIGHT_BLUE);
						printf("	9) lightblue. \n");
					}
					if (Color_choice[9] == 0) {
						set_terminal_color(cBLUE);
						printf("	10) blue. \n");
					}
				}
				
				if (Color_choice[10] == 0) {
					set_terminal_color(cYELLOW);
					printf("	11) yellow. \n");
				}
				if (Color_choice[11] == 0) {
					set_terminal_color(cLIGHT_GREEN);
					printf("	12) lightgreen. \n");
				}
				
				if (gamemode_played != Quidditch) {
					if (Color_choice[12] == 0) {
						set_terminal_color(cGREEN);
						printf("	13) green. \n");
					}
				}
				set_terminal_color(cNORMAL);	//normal, maybe calling a normal color (done).

				printf(" \n");
				printf(" \n");
				printf("	Back: 14 \n");
				printf(" \n");
				input = get_unsigned_numeric_input_with_not_more_than_2_letters ();
				
				if (gamemode_played == Quidditch) {	//because the forbidden colors aren't house-colors
					if ((input != 4)&&(input != 7)&&(input != 11)&&(input != 12)) {
						input = 0;
					}
				}
				if ((input != 0)&&(input <= 13)&&(Color_choice[input-1] == 0)) {
					current_player->color = input;
					if (input == cWHITE) {
						set_player_color (Growth_players, curr_id, cWHITE);
					} else if (input == cLIGHT_GRAY) {
						set_player_color (Growth_players, curr_id, cLIGHT_GRAY);
					} else if (input == cGRAY) {
						set_player_color (Growth_players, curr_id, cGRAY);
					} else if (input == cLIGHT_MAGENTA) {
						set_player_color (Growth_players, curr_id, cLIGHT_MAGENTA);
					} else if (input == cLIGHT_RED) {
						set_player_color (Growth_players, curr_id, cLIGHT_RED);
					} else if (input == cRED) {
						set_player_color (Growth_players, curr_id, cRED);
					} else if (input == cLIGHT_CYAN) {
						set_player_color (Growth_players, curr_id, cLIGHT_CYAN);
					} else if (input == cCYAN) {
						set_player_color (Growth_players, curr_id, cCYAN);
					} else if (input == cLIGHT_BLUE) {
						set_player_color (Growth_players, curr_id, cLIGHT_BLUE);
					} else if (input == cBLUE) {
						set_player_color (Growth_players, curr_id, cBLUE);
					} else if (input == cYELLOW) {
						set_player_color (Growth_players, curr_id, cYELLOW);
					} else if (input == cLIGHT_GREEN) {
						set_player_color (Growth_players, curr_id, cLIGHT_GREEN);
					} else if (input == cGREEN) {
						set_player_color (Growth_players, curr_id, cGREEN);
					}
					Color_choice[input-1] = p;
				}
			}
		}
		Growth_players[0].color = 1;
	}
	unsigned_int_array_null_initialisierung (Color_choice, 12);
}

void set_terminal_color (Color color) {

		switch(color) {
		case cWHITE:
		{
			#ifdef _WIN32
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+15);
			#else
				printf("\x1B[37m");
			#endif
			break;
		}
		
		case cLIGHT_GRAY:
		{
			#ifdef _WIN32
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+7);
			#else
				printf("\x0B[37m");
			#endif
			break;
		}
		
		case cGRAY:
		{
			#ifdef _WIN32
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+8);
			#else
				printf("\x1B[0m");
			#endif
			break;
		}
		
		case cLIGHT_MAGENTA:
		{
			#ifdef _WIN32
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+13);
			#else
				printf("\x1B[35m");
			#endif
			break;
		}
		case cLIGHT_RED:
		{
			#ifdef _WIN32
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+12);
			#else
				printf("\x1B[31m");
			#endif
			break;
		}
		case cRED:
		{
			#ifdef _WIN32
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+4);
			#else
				printf("\x0B[31m");
			#endif
			break;
		}
		case cLIGHT_CYAN:
		{
			#ifdef _WIN32
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+11);
			#else
				printf("\x1B[36m");
			#endif
			break;
		}
		case cCYAN:
		{
			#ifdef _WIN32
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+3);
			#else
				printf("\x0B[36m");
			#endif
			break;
		}
		case cLIGHT_BLUE:
		{
			#ifdef _WIN32
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+9);
			#else
				printf("\x1B[34m");
			#endif
			break;
		}
		case cBLUE:
		{
			#ifdef _WIN32
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+1);
			#else
				printf("\x0B[34m");
			#endif
			break;
		}
		
		case cYELLOW:
		{
			#ifdef _WIN32
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+14);
			#else
				printf("\x1B[33m");
			#endif
			break;
		}
		
		case cLIGHT_GREEN:
		{
			#ifdef _WIN32
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+10);
			#else
				printf("\x1B[32m");
			#endif
			break;
		}
		
		case cGREEN:
		{
			#ifdef _WIN32
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+2);
			#else
				printf("\x0B[32m");
			#endif
			break;
		}
		
		case cBROWN:
		{
			#ifdef _WIN32
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+6);
			#else
				printf("\x1B[0m");
			#endif
			break;
		}
		
		default:
		{
			#ifdef _WIN32
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+7);
			#else
				printf("\x1B[0m");
			#endif
			break;
		}
		}
}

void set_player_color (Growth_Player* Growth_players, unsigned int id, Color color) {
	Growth_players[id].color = color;
}
