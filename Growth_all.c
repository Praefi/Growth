
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
//#include <windows.h>	// look at Growth.h
#include <ctype.h>

#ifdef _WIN32
#include <windows.h>
#endif

#define VERBOSE
#define Contact_mistake_search
#define Quidditch_mistake_search
#define Aufraeumphase_mistake_search

#include "Growth_all_Def.h"
#include "Growth_all_Vektor.h"
#include "Growth_all_Initialisierung.h"
#include "Growth_all_show.h"
#include "Growth_all_set.h"
#include "Growth_all_visual.h"
#include "Growth_all_opague.h"
#include "Growth_all_get.h"
#include "Growth_all_Development.h"
#include "Growth_all_actions.h"
#include "Growth_all_gamemode_specials.h"
#include "Growth_all_options_specials.h"
#include "Growth_all_KI.h"
#include "Growth_all.h"

// anscheinend kehren die gestorbenen zurück in das Standartspiel bei gamemode_played 6 (aktuell ?)

// struct realize_modifications_variables {};

unsigned int letters_4;
unsigned int letters_2;

unsigned int AOP;

unsigned int Liz_max;
unsigned int anything; //Die Variable für alles Mögliche

time_t time_of_the_start;

int Vektor_counter;
int Spielfeld_counter;

int main (void) {

	time_of_the_start = time(NULL);
	// printf("time_of_the_start = %lu \n", time_of_the_start);	//test
	
	//printf ("	ok 1 \n");	//test
	//Spielfeld test_;	//test
	//printf ("	ok 1.1 \n");	//test

	unsigned int m, n;	//Höhe, Breite
	unsigned int number_of_players;	//spielende Spieler
	unsigned int lim;
	unsigned int fall_controll, turns_per_drop, speed_of_fall, points_for_win;	//Gamemode = Fall
	unsigned int freq;	//Gamemode = Race
	unsigned int rain, rain_drops, rain_obj, rain_speed;	//Gamemode = Rain
	unsigned int playtime;	//Navigationsparameter
	unsigned int opt, use_number, num_temp, tac, cards;	//How to get the numbers, and to controll them
	unsigned int figures, allocation, iteration, journey, undead_duration, opague, inverted, addition, assassin, avalanche, spreading, invisible, roses, partition;	//options, selected with beginningmenu
	unsigned int rtc, spf, scwhp, hboa;	// Gamemode: Hunt
	unsigned int NOSV;		//number of saved variables; amount of players
	unsigned int range, strength;		//Gamemode = Dynamic

	//sort the variables, done

	//scanf("%u", &pause); //test
	//printf ("	ok 2 \n");	//test

	unsigned int ttt, warning_system;		//time-to-think, Verstöße bestrafen
	unsigned int exclude_counter, rtp, information_code[4];	//rounds-to-play, 0 == rtc, 1 == spf, 2 == hboa, 3 == scwhp (gamemode_played == Hunt)
	unsigned int* same;	//immer aktualisieren
	int erd;	//erdbeschleunigung
	unsigned int intensity_minimum, intensity_loss_per_line_multiplication;	//option: projection
	unsigned int amount_of_permutation_number_b, amount_of_permutation_number_c, permutation_number_b, permutation_number_c;	//option: permutations

	AOP = 9;	//Amount Of Players, needed so early - look at the following lines

	Growth_Player Growth_players[AOP+1];
	Limits limits;

	for (unsigned int i = 1; i <= AOP; ++i) {
		Growth_players[i].id = i;
	}

	unsigned int number_[AOP+1];
	//unsigned int same_counter;

	time_t time3;

	unsigned int ability[AOP+1], ulcer_start[AOP+1], ulcer_lifes[AOP+1];	//ulcer_start==Are you on the field

	unsigned int beginningmenu, gamemode_played;
	
	//gamemode_played == Hunt, geben == 1: information_code: [0]=0, [1]=1, [2]=1, [3]=0

	//Benutzbar, aber benutzt:	unsigned int:	number_[AOP]
	//Benutzbar, und unbenutzt:	unsigned int:   number_[5-(AOP-1)]		int (in int-Vektor): dynamic_pointer_save[p][0] (p=0,1,2,3)
	// used unusually ges numbers 1010,2020,3030,4040,5050,6060,7070,8080,9090
	// 10, 20, 30, 40, 50, 60, 70, 80, 90 ausschließlich im Spielfeldrand
	//used Field[0]: (1,0), (0,0), (0,1), (0,n-1), (m-1,n-1), (m-1,0)
	// >=10000 nur bei undead, sonst muss undead_duration der show_field mitgegeben werden.

	Vektor_counter = 0;	//global
	Spielfeld_counter = 0;	//global
	pause = 0;	//global
	
	playtime = 1;	//playing a game, after a game, after...

	NOSV = 94;	//Number_of_saved_variables, drücke abhängig von AOP aus, go on
	//same_counter = 0;     //for variable length of same

	same = unsigned_int_Vektor_Create (NOSV);

	//scanf("%u", &pause); //test
	//printf("%u \n", same[0]);	//test
	//printf ("	ok 3 \n");	//test

	while (playtime != 0) {		// Außenschleife für mehrere Spiele hintereinander

		unsigned int* level;	//für KI
		unsigned int* position;		// "*" bezieht sich auf "position", nicht auf "unsigned int" !!!!
	
		Quidditch_setup* Qs;
		Quidditch_team_abilities* Qta;
		Quidditch_object_abilities* Qoa;
	
		//scanf("%u", &pause); //test
		//printf ("	ok 3.1 \n");	//test

		Qta = Quidditch_team_abilities_Vektor_Create (7);	//Normal, default_1, default_2, Gryffindor, Hufflepuff, Ravenclaw, Slytherin
		Qoa = Quidditch_object_abilities_Vektor_Create (1);
		Qs = Quidditch_setup_Vektor_Create (1);
		
		Initialisierung_Qoa (Qoa);
		
		level =  unsigned_int_Vektor_Create (AOP+1);

		position = unsigned_int_Vektor_Create (2);

		//scanf("%u", &pause); //test
		//printf ("	ok 4 \n");	//test

		//playtime should start here, done

		number_of_players = 2;	//normally

		//scanf("%u", &pause); //test
		//printf ("	ok 5 \n");	//test

		m = 0;	//
		n = 0;	//

		letters_4 = 0;
		letters_2 = 0;

		Liz_max = 0;//KI-matters
		anything = 0;	//global

		rain_speed = 1;		//Rain
		rain_obj = 0;
		rain = Push;
		rain_drops = 1;

		freq = 6;	//Race

		figures = 0;	//options
		undead_duration = 0;
		allocation = 0;
		inverted = 0;
		addition = 0;
		assassin = 0;
		avalanche = 0;
		spreading = 0;
		invisible = 0;
		roses = 0;
		partition = 0;

		fall_controll = 0;	//Fall
		points_for_win = 3;
		turns_per_drop = 3;
		speed_of_fall = 1;

		iteration = 0;		//eine Iteration-Option, go on

		strength = 1;

		range = 1;	//Dynamic parameter
		erd = 1;

		intensity_minimum = 0;	//projection
		intensity_loss_per_line_multiplication = 0;
		direction = undefined;

		amount_of_permutation_number_b = 0;	//permutations
		amount_of_permutation_number_c = 0;
		permutation_number_b = 0;
		permutation_number_c = 0;

		//scanf("%u", &pause); //test
		//printf ("	ok 5.1 \n");	//test

		lim = 0;
		opt = 0;
		cards = 0;
		tac = 0;
		journey = 0;

		num_temp = 0;
		limits.yeni = 0;		//if
		limits.at_all = 0;		//if

		use_number = 1;

		beginningmenu = oBack;	//auch hier
		gamemode_played = Invalid;	//Stets synchronisieren mit dem letzten Spielmodus

		scwhp = 1;
		spf = 5;
		rtc = 30;

		hboa = 1;

		ttt = 0;	//time to think
		warning_system = 0;

		exclude_counter = 0;

		rtp = 30;

		opague = 0;

		//scanf("%u", &pause); //test
		//printf ("	ok 5.2 \n");	//test

		//scanf("%u", &pause); //test
		//printf ("	ok 5.3 \n");	//test

		unsigned_int_array_null_initialisierung (information_code, 3);

		//scanf("%u", &pause); //test
		//printf ("	ok 5.4 \n");	//test

		//int_array_null_initialisierung (dynamic_pointer, 7);	//already null

		//[0] = s_horizontal
		//[1] = s_vertikal

		//[2] = v_horizontal
		//[3] = v_vertikal

		//[4] = a_horizontal
		//[5] = a_vertikal

		//[6] = y_horizontal
		//[7] = y_vertikal

		Initialisierung_Arrays_1 (AOP, ability, ulcer_lifes, number_);

		tac = 1;	//quick start, the following colors are Quidditch-compatible
		Growth_players[0].color = 1;
		Growth_players[1].color = cLIGHT_MAGENTA; //lightmagenta
		Growth_players[2].color = cYELLOW; //yellow
		
		for (unsigned int p=3; p<=AOP; p++) {	//normally to avoid black as color
			Growth_players[p].color = cNORMAL;
		}
		//scanf("%u", &pause); //test
		//printf ("	ok 5.5 \n");	//test

		Initialisierung_Qta (Qta);
		
		if (same[0] == 0) {

			//Startmenü, Anfang

			if (playtime != 10) {
				printf("\n");
				printf("	Welcome to >Growth<. Have a nice game. \n");
				printf("\n");
			}

			//scanf("%u", &pause); //test
			//printf ("	ok 6 \n");	//test

			while (beginningmenu == oBack) {

				// scanf("%u", &pause); //test
				// printf ("	ok 7 \n");	//test
				while (gamemode_played >= Invalid) {

					printf("	Choose your gamemode\n  \n");

					// enum: gamemode_played[done], (traps, bombs, waves, done), in menu (about the game, limits, hints, numbers), beginningmenu done   //go on

					printf("	%u. Tutorial\n	%u. Classic\n	%u. Collect\n	%u. Contact\n	%u. Fall\n	%u. Fight\n	%u. Hunt\n	%u. Race\n	%u. Rain\n	%u. Arena\n   	%u. Ulcer\n    	%u. Dynamic\n     	%u. Survive\n     	%u. Sand\n     	%u. Quidditch\n     	%u. Duell\n  \n", Tutorial, Classic, Collect, Contact, Fall, Fight, Hunt, Race, Rain, Arena, Ulcer, Dynamic, Survive, Sand, Quidditch, Duell);	//mehr-gamemode_played
					gamemode_played = get_unsigned_numeric_input_with_not_more_than_2_letters ();
					printf("\n");
					//Players?

					if (gamemode_played == Tutorial) {
						Time_for_a_Tutorial (AOP, level, information_code, position, Growth_players);

						gamemode_played = Invalid;
					}
				}

				Initialisierung (gamemode_played, information_code);
				limits.at_all = Initialisierung_limits_at_all (gamemode_played);
				limits.yeni = Initialisierung_limits_yeni (gamemode_played);
				m = Initialisierung_m (gamemode_played);
				n = Initialisierung_n (gamemode_played);

				while (beginningmenu != oStart){

					printf("	%u. Start game\n \n	%u. Game size\n	%u. Journey\n	%u. Tactics\n	%u. Random\n	%u. Limits\n	%u. Time\n	%u. Color\n	%u. Opague\n	%u. undead\n	%u. Figures\n	%u. Allocation\n	%u. Cards\n	%u. Inverted\n	%u. Addition\n	%u. Projection\n	%u. Assassin\n	%u. Permutations\n	%u. Avalanche\n	%u. Spreading\n	%u. Invisible\n	%u. Roses\n	%u. Partition\n	%u. KI\n	%u. Number of players\n  \n	%u. Back\n \n", oStart, oSize, oJourney, oTactics, oRandom, oLimits, oTime, oColor, oOpague, oUndead, oFigures, oAllocation, oCards, oInverted, oAddition, oProjection, oAssassin, oPermutations, oAvalanche, oSpreading, oInvisible, oRoses, oPartition, oBack-2, oBack-1, oBack);	//synchronisiere stets oBack mit beginningmenu
					if (gamemode_played == Fall) {
						printf("	%u. Points for win\n", oBack+1);
						printf("	%u. Turns per drop\n", oBack+2);
						printf("	%u. Speed of the #-square\n", oBack+3);
					} else if (gamemode_played == Hunt) {
						printf("	%u. Hunt-conditions\n", oBack+1);
					} else if (gamemode_played == Race) {
						printf("	%u. Frequence\n", oBack+1);
					} else if (gamemode_played == Rain) {
						printf("	%u. Rain-Modus\n", oBack+1);
					} else if (gamemode_played == Arena) {
						printf("	%u. Abilities\n", oBack+1);
						printf("	%u. Rounds to play\n", oBack+2);
					} else if (gamemode_played == Ulcer) {
						printf("	%u. Lifes\n", oBack+1);
						printf("	%u. Rounds to play\n", oBack+2);
						printf("	%u. K.O.-Mode\n", oBack+4);
					} else if (gamemode_played == Dynamic) {
						printf("	%u. Gravity\n", oBack+1);
						printf("	%u. Range\n", oBack+2);
						printf("	%u. Coefficient\n", oBack+3);
					} else if (gamemode_played == Survive) {
						printf("	%u. obstacles\n", oBack+1);
					} else if (gamemode_played == Sand) {
						printf("	%u. Gravity\n", oBack+1);
						printf("	%u. Speed\n", oBack+2);
						printf("	%u. Period\n", oBack+3);
					} else if (gamemode_played == Quidditch) {
						printf("	%u. Quidditch-object-abilities\n", oBack+1);
						printf("	%u. Quidditch-team-abilities\n", oBack+2);
					}

					printf("\n");
					beginningmenu = get_unsigned_numeric_input_with_not_more_than_2_letters ();
					printf("\n");

					if (beginningmenu == oStart){
						printf("	Let's start! \n");
					}

					if (beginningmenu == oSize){
						if (gamemode_played == Quidditch) {
							printf("	Quidditch-Fields have static lengths.\n");
						} else {
							
							printf("	This only works if the number of players is correct! \n");
							
							m = get_m (gamemode_played, number_of_players);
							n = get_n (gamemode_played, number_of_players);
						}
					}

					if (beginningmenu == oJourney){
						if (journey != 0){
							journey = 0;
							printf("	Journey deactivated \n");
						} else if (journey == 0){
							journey = 1;
							printf("	Journey activated \n");
						}
						printf("\n");
					}

					if (beginningmenu == oTactics){
						opt = 0;
						cards = 0;

						if (tac != 0) {
							printf("	Tactics-mode reseted! \n");
							printf(" \n");
							tac = 0;
						} else {
							printf("	Do not activate Random or Cards, it will replace the Tactics-Mode! \n");
							printf("	Stack of every number until refresh: \n");
							tac = get_unsigned_numeric_input_with_not_more_than_2_letters ();
							printf("\n");
						}
					}

					if (beginningmenu == oRandom) {
						tac = 0;
						cards = 0;

						if (opt != 0) {
							printf("	Random-mode reseted! \n");
							printf(" \n");
							opt = 0;
						} else {
							printf("	Do not activate Tactics or Cards, it will replace the Random-Mode! \n");
							printf("	This only works if the number of players is correct! \n");
							printf("	Random activated \n\n");
							
							printf("	Please get all a number from 0 to %u, not the same, it will have no effect further on. \n", number_of_players-1);
							printf("	Give me three random numbers from 1 to 60: \n");
							number_[1] = get_unsigned_numeric_input_with_not_more_than_2_letters ();
							number_[2] = get_unsigned_numeric_input_with_not_more_than_2_letters ();
							number_[3] = get_unsigned_numeric_input_with_not_more_than_2_letters ();
							if ((number_[1]==0)||(number_[2]==0)||(number_[3]==0)||(number_[1]>60)||(number_[2]>60)||(number_[3]>60)){
								printf("	You missed the assertion(s) !!! \n");
							} else {
								printf("	Give me another random number from 1 to 60 \n");
								number_[4] = get_unsigned_numeric_input_with_not_more_than_2_letters ();
								if ((number_[4]<1)||(number_[4]>60)){
									printf("	You missed the assertion(s) !!! \n");
								} else {
									number_[4] = ((number_[4]%6)+1)%3 + 1;
									if (number_[4] == 1){
										num_temp = (number_[1] % 2)+(number_[2] % 3)+2*(number_[3] % 3);
										if (num_temp <= 1){
											use_number = 1;
										} else if (num_temp >= 6){
											use_number = 6;
										} else {
											use_number = num_temp;
										}
									}
									if (number_[4] == 2){
										num_temp = (number_[2] % 2)+(number_[1] % 3)+2*(number_[3] % 3);
										if (num_temp <= 1){
											use_number = 1;
										} else if (num_temp >= 6){
											use_number = 6;
										} else {
											use_number = num_temp;
										}
									}
									if (number_[4] == 3){
										num_temp = (number_[3] % 2)+(number_[1] % 3)+2*(number_[2] % 3);
										if (num_temp <= 1){
											use_number = 1;
										} else if (num_temp >= 6){
											use_number = 6;
										} else {
											use_number = num_temp;
										}
									}

									unsigned int Row[number_of_players];
									unsigned_int_array_null_initialisierung (Row, number_of_players-1);

									unsigned int Verteilung;
									Verteilung = (number_[1] + number_[2] + number_[3] + number_[4])%(number_of_players);
									for (unsigned int y = 0; y < number_of_players; y+=1){
										Row[y] = Verteilung;
										if (number_of_players == 9){
											Verteilung = (4*Verteilung + 8)%9;
										} else if (number_of_players == 2){
											Verteilung = (3*Verteilung + 1)%2;
										} else if (number_of_players == 3){
											Verteilung = (4*Verteilung + 2)%3;
										} else if (number_of_players == 4){
											Verteilung = (5*Verteilung + 1)%4;
										} else if (number_of_players == 5){
											Verteilung = (6*Verteilung + 3)%5;
										} else if (number_of_players == 6){
											Verteilung = (7*Verteilung + 1)%6;
										} else if (number_of_players == 7){
											Verteilung = (8*Verteilung + 4)%7;
										} else if (number_of_players == 8){
											Verteilung = (5*Verteilung + 7)%8;
										}

									}
									for (unsigned int y=0; y < number_of_players; y+=1){
										if (Row[y] == 0){
											if (gamemode_played == Hunt) {
												printf("	%u = Player 1, you will be hunted. (##) \n", y);
											} else if (gamemode_played == Arena) {
												printf("	%u = Player 1. \n", y);
											} else {
												printf("	%u = Player 1, (11) \n", y);
											}
										} else if (Row[y] == 1){
											if (gamemode_played == Hunt) {
												printf("	%u = Player 2, (AA) \n", y);
											} else if (gamemode_played == Arena) {
												printf("	%u = Player 2. \n", y);
											} else {
												printf("	%u = Player 2, (22) \n", y);
											}
										} else if (Row[y] == 2){
											if (gamemode_played == Hunt) {
												printf("	%u = Player 3, (BB) \n", y);
											} else if (gamemode_played == Arena) {
												printf("	%u = Player 3. \n", y);
											} else {
												printf("	%u = Player 3, (33) \n", y);
											}
										} else if (Row[y] == 3){
											if (gamemode_played == Hunt) {
												printf("	%u = Player 4, (CC) \n", y);
											} else if (gamemode_played == Arena) {
												printf("	%u = Player 4. \n", y);
											} else {
												printf("	%u = Player 4, (44) \n", y);
											}
										} else if (Row[y] == 4){
											if (gamemode_played == Hunt) {
												printf("	%u = Player 5, (DD) \n", y);
											} else if (gamemode_played == Arena) {
												printf("	%u = Player 5. \n", y);
											} else {
												printf("	%u = Player 5, (55) \n", y);
											}
										} else if (Row[y] == 5){
											if (gamemode_played == Hunt) {
												printf("	%u = Player 6, (EE) \n", y);
											} else if (gamemode_played == Arena) {
												printf("	%u = Player 6. \n", y);
											} else {
												printf("	%u = Player 6, (66) \n", y);
											}
										} else if (Row[y] == 6){
											if (gamemode_played == Hunt) {
												printf("	%u = Player 7, (GG) \n", y);
											} else if (gamemode_played == Arena) {
												printf("	%u = Player 7. \n", y);
											} else {
												printf("	%u = Player 7, (77) \n", y);
											}
										} else if (Row[y] == 7){
											if (gamemode_played == Hunt) {
												printf("	%u = Player 8, (HH) \n", y);
											} else if (gamemode_played == Arena) {
												printf("	%u = Player 8. \n", y);
											} else {
												printf("	%u = Player 8, (88) \n", y);
											}
										} else if (Row[y] == 8){
											if (gamemode_played == Hunt) {
												printf("	%u = Player 9, (II) \n", y);
											} else if (gamemode_played == Arena) {
												printf("	%u = Player 9. \n", y);
											} else {
												printf("	%u = Player 9, (99) \n", y);
											}
										}
									}
								}
							}
							opt = 5;
						}
					}

					if (beginningmenu == oLimits){	//checklist
							printf("	This only works if the number of players is correct! \n");

						if ((gamemode_played == Classic)||(gamemode_played == Collect)) {
							printf("	Change limits.yeni: 1 \n	Change limits.at_all: 2 \n	Change both: 3 \n");
							lim = get_unsigned_numeric_input_with_not_more_than_1_letter ();
							printf("\n");

							if (lim == 1){
								printf("	limits.yeni:		(normal: 10) \n");
								limits.yeni = get_unsigned_numeric_input_with_not_more_than_2_letters ();
								printf("\n");
							}
							if (lim == 2){
								printf("	limits.at_all:		(normal: 20) \n");
								limits.at_all = get_unsigned_numeric_input_with_not_more_than_2_letters ();
								printf("\n");
							}
							if (lim == 3){
								printf("	limits.yeni:				(normal: 10) \n	limits.at_all:				(normal: 20) \n");
								letters_4 = get_unsigned_numeric_input_with_not_more_than_letters_4_for_splitting();
								limits.yeni = split_unsigned_numeric_input_with_letters_4 (letters_4, 0);
								limits.at_all = split_unsigned_numeric_input_with_letters_4 (letters_4, 1);
								printf("\n");
							}
						} else if (gamemode_played == Contact) {
							printf("	limits.yeni: 1		limits.at_all: 2		both: 3\n");
							lim = get_unsigned_numeric_input_with_not_more_than_1_letter ();

							if (lim == 1){
								printf("	limits.yeni:      (normal: 15) \n");
								limits.yeni = get_unsigned_numeric_input_with_not_more_than_2_letters ();
							}
							if (lim == 2){
								printf("	limits.at_all:       (normal: 30) \n");
								limits.at_all = get_unsigned_numeric_input_with_not_more_than_2_letters ();
							}
							if (lim == 3){
								printf("	limits.yeni:				(normal: 15) \n	limits.at_all:				(normal: 30) \n");
								letters_4 = get_unsigned_numeric_input_with_not_more_than_letters_4_for_splitting();
								limits.yeni = split_unsigned_numeric_input_with_letters_4 (letters_4, 0);
								limits.at_all = split_unsigned_numeric_input_with_letters_4 (letters_4, 1);
							}
						} else if ((gamemode_played == Fall)||(gamemode_played == Race)||(gamemode_played == Rain)) {
							printf("	limits.yeni: 1		limits.at_all: 2		both: 3\n");
							lim = get_unsigned_numeric_input_with_not_more_than_1_letter ();

							if (lim == 1){
								printf("	limits.yeni:      (normal: 7) \n");
								limits.yeni = get_unsigned_numeric_input_with_not_more_than_2_letters ();
							}
							if (lim == 2){
								printf("	limits.at_all:       (normal: 14) \n");
								limits.at_all = get_unsigned_numeric_input_with_not_more_than_2_letters ();
							}
							if (lim == 3){
								printf("	limits.yeni:				(normal: 7) \n	limits.at_all:				(normal: 14) \n");
								letters_4 = get_unsigned_numeric_input_with_not_more_than_letters_4_for_splitting();
								limits.yeni = split_unsigned_numeric_input_with_letters_4 (letters_4, 0);
								limits.at_all = split_unsigned_numeric_input_with_letters_4 (letters_4, 1);
							}
						} else if ((gamemode_played == Fight)||(gamemode_played == Duell)) {
							printf("	limits.yeni: 1		limits.at_all: 2		both: 3\n");
							lim = get_unsigned_numeric_input_with_not_more_than_1_letter ();

							if (lim == 1){
								printf("	limits.yeni:      (normal: 5) \n");
								limits.yeni = get_unsigned_numeric_input_with_not_more_than_2_letters ();
							}
							if (lim == 2){
								printf("	limits.at_all:       (normal: 10) \n");
								limits.at_all = get_unsigned_numeric_input_with_not_more_than_2_letters ();
							}
							if (lim == 3){
								printf("	limits.yeni:				(normal: 5) \n	limits.at_all:				(normal: 10) \n");
								letters_4 = get_unsigned_numeric_input_with_not_more_than_letters_4_for_splitting();
								limits.yeni = split_unsigned_numeric_input_with_letters_4 (letters_4, 0);
								limits.at_all = split_unsigned_numeric_input_with_letters_4 (letters_4, 1);
							}
						} else if (gamemode_played == Hunt) {
							printf("	The limits of the hunted one will be calculated seperatly.\n");
							printf("	limits.yeni: 1		limits.at_all: 2		both: 3\n");
							lim = get_unsigned_numeric_input_with_not_more_than_1_letter ();

							if (lim == 1){
								printf("	limits.yeni:      (normal: 6) \n");
								limits.yeni = get_unsigned_numeric_input_with_not_more_than_2_letters ();
							}
							if (lim == 2){
								printf("	limits.at_all:       (normal: 12) \n");
								limits.at_all = get_unsigned_numeric_input_with_not_more_than_2_letters ();
							}
							if (lim == 3){
								printf("	limits.yeni:				(normal: 6) \n	limits.at_all:				(normal: 12) \n");
								letters_4 = get_unsigned_numeric_input_with_not_more_than_letters_4_for_splitting();
								limits.yeni = split_unsigned_numeric_input_with_letters_4 (letters_4, 0);
								limits.at_all = split_unsigned_numeric_input_with_letters_4 (letters_4, 1);
							}
						} else if (gamemode_played == Arena) {
							printf("	limits.yeni can change with your ability.\n");
							printf("	limits.yeni: 1		limits.at_all: 2		both: 3\n");
							lim = get_unsigned_numeric_input_with_not_more_than_1_letter ();

							if (lim == 1){
								printf("	limits.yeni:      (normal: 8) \n");
								limits.yeni = get_unsigned_numeric_input_with_not_more_than_2_letters ();
							}
							if (lim == 2){
								printf("	limits.at_all:       (normal: 16) \n");
								limits.at_all = get_unsigned_numeric_input_with_not_more_than_2_letters ();
							}
							if (lim == 3){
								printf("	limits.yeni:				(normal: 8) \n	limits.at_all:				(normal: 16) \n");
								letters_4 = get_unsigned_numeric_input_with_not_more_than_letters_4_for_splitting();
								limits.yeni = split_unsigned_numeric_input_with_letters_4 (letters_4, 0);
								limits.at_all = split_unsigned_numeric_input_with_letters_4 (letters_4, 1);
							}
						} else if (gamemode_played == Ulcer) {
							printf("	Ulcer is unlimited.\n");

						} else if (gamemode_played == Dynamic) {
							printf("	limits.yeni: 1		limits.at_all: 2		both: 3\n");
							lim = get_unsigned_numeric_input_with_not_more_than_1_letter ();

							if (lim == 1){

								printf("	limits.yeni:      (normal: 10) \n");
								limits.yeni = get_unsigned_numeric_input_with_not_more_than_2_letters ();

							}
							if (lim == 2){

								printf("	limits.at_all:       (normal: 20) \n");
								limits.at_all = get_unsigned_numeric_input_with_not_more_than_2_letters ();

							}
							if (lim == 3){

								printf("	limits.yeni:				(normal: 10) \n	limits.at_all:				(normal: 20) \n");
								letters_4 = get_unsigned_numeric_input_with_not_more_than_letters_4_for_splitting();
								limits.yeni = split_unsigned_numeric_input_with_letters_4 (letters_4, 0);
								limits.at_all = split_unsigned_numeric_input_with_letters_4 (letters_4, 1);
							}
						} else if (gamemode_played == Survive) {
							printf("	Survive is unlimited.\n");

						} else if (gamemode_played == Sand) {
							printf("	limits.yeni: 1		limits.at_all: 2		both: 3\n");
							lim = get_unsigned_numeric_input_with_not_more_than_1_letter ();

							if (lim == 1){

								printf("	limits.yeni:      (normal: 7) \n");
								limits.yeni = get_unsigned_numeric_input_with_not_more_than_2_letters ();

							}
							if (lim == 2){

								printf("	limits.at_all:       (normal: 14) \n");
								limits.at_all = get_unsigned_numeric_input_with_not_more_than_2_letters ();

							}
							if (lim == 3){

								printf("	limits.yeni:				(normal: 7) \n	limits.at_all:				(normal: 14) \n");
								letters_4 = get_unsigned_numeric_input_with_not_more_than_letters_4_for_splitting();
								limits.yeni = split_unsigned_numeric_input_with_letters_4 (letters_4, 0);
								limits.at_all = split_unsigned_numeric_input_with_letters_4 (letters_4, 1);
							}
						} else if (gamemode_played == Quidditch) {
							printf("	limits.yeni: 1		limits.at_all: 2		both: 3\n");
							lim = get_unsigned_numeric_input_with_not_more_than_1_letter ();

							if (lim == 1){

								printf("	limits.yeni:      (normal: 45) \n");
								limits.yeni = get_unsigned_numeric_input_with_not_more_than_2_letters ();

							}
							if (lim == 2){

								printf("	limits.at_all:       (normal: 90) \n");
								limits.at_all = get_unsigned_numeric_input_with_not_more_than_2_letters ();

							}
							if (lim == 3){

								printf("	limits.yeni:				(normal: 45) \n	limits.at_all:				(normal: 90) \n");
								letters_4 = get_unsigned_numeric_input_with_not_more_than_letters_4_for_splitting();
								limits.yeni = split_unsigned_numeric_input_with_letters_4 (letters_4, 0);
								limits.at_all = split_unsigned_numeric_input_with_letters_4 (letters_4, 1);
							}
						}
						if (limits.yeni > limits.at_all) {
							limits.yeni = limits.at_all;
						}
					}

					if (beginningmenu == oTime) {	//checklist
						if (ttt != 0) {
							ttt = 0;
							warning_system = 0;

							printf("	The time for your turn is unlimited. \n");
						} else {
							printf("	Limit the time of each turn to make the game faster. \n");
							printf("	You should add a bonus of 10sec if you want to play in the tactics-mode. \n");
							printf("\n");
							
							unsigned int ttt_normal;
							ttt_normal = 0;
							
							if ((gamemode_played == Classic)||(gamemode_played == Collect)) {
								ttt_normal = 20;
							} else if ((gamemode_played == Contact)||(gamemode_played == Arena)||(gamemode_played == Dynamic)||(gamemode_played == Quidditch)) {
								ttt_normal = 30;
							} else if ((gamemode_played == Fall)||(gamemode_played == Race)||(gamemode_played == Rain)||(gamemode_played == Ulcer)||(gamemode_played == Survive)) {
								ttt_normal = 25;
							} else if (gamemode_played == Fight) {
								ttt_normal = 15;
							} else if ((gamemode_played == Hunt)||(gamemode_played == Duell)) {
								ttt_normal = 35;
							}
							
							if (gamemode_played == Hunt) {
								printf("	The hunted one will get a 10sec bonus. \n");
								printf("	The time for choosing his heart is unlimited. \n");
								printf("	\n");
							}
							
							printf("	Choose the limit of time:         (normal: %usec) \n", ttt_normal);
							ttt = get_unsigned_numeric_input_with_not_more_than_2_letters ();
							if (ttt == 0) {
								printf("	That's impossible! You'll take %usec. \n", ttt_normal);
								ttt = ttt_normal;
							}
						
							
							printf("\n");
							printf("\n");

							printf("	Choose the penalty:     relaxed: 1,   normal: 2,  serious: 3,   strict: 4,  hard: 5,  elite: 6,   no mercy: 7 \n");
							warning_system = get_unsigned_numeric_input_with_not_more_than_1_letter ();
							if ((warning_system == 0)||(warning_system > 7)) {
								printf("	Let's say normal. \n");
								warning_system = 2;
							}
							printf("\n");
							printf("\n");

						}

					}

					if (beginningmenu == oColor) {
						get_colors (Growth_players, number_of_players, gamemode_played, AOP);
					}

					if (beginningmenu == oOpague) {
						anything = 0;
						if (opague == 0) {

							printf("	Going here again will lead to a return to normal visibility! \n");
							printf(" \n");
							while ((opague != 11)&&(opague != 12)&&(opague != 21)&&(opague != 22)) {		//4-Mode-Opague

								opague = 0;
								anything = 0;

								printf("  Use the #Surrounding or the #near-by additional to the place itself? \n\n");
								printf("  #Surrounding: 1			#near-by: 2 \n");

								anything = get_unsigned_numeric_input_with_not_more_than_1_letter ();

								printf("  Show even or uneven counts? \n\n");
								printf("  Uneven: 1		Even: 2	\n");

								opague = get_unsigned_numeric_input_with_not_more_than_1_letter ();

								opague += 10*anything;
							}

						} else if (opague >= 1) {
							printf("	Returned to normal visibility! \n");
							printf(" \n");
							opague = 0;
						}
						anything = 0;
					}

					if (beginningmenu == oUndead) {

						if (undead_duration != 0) {
							printf("	undead-mode reseted! \n");
							printf(" \n");
							undead_duration = 0;
						} else {
							printf("	Going here again will reset the undead-mode! \n");
							printf("	How many turns the undead-square should survive? \n");
							undead_duration = get_unsigned_numeric_input_with_not_more_than_2_letters ();
						}
					}

					if (beginningmenu == oFigures) {

						if (figures != 0) {
							printf("	Figures-mode reseted! \n");
							printf(" \n");
							figures = 0;
						} else {
							printf("	Going here again will reset the Figures-mode! \n");
							figures = 1;	//make a selection possible, go on

							show_figures ();
						}
					}

					if (beginningmenu == oAllocation) {

						printf("	Every movement of a square owned by a player caused by gamemode-special actions will reduce its allocation to 1. \n");

						if (allocation != 0) {
							printf("	Allocation-mode reseted! \n");
							printf(" \n");
							allocation = 0;
						} else {
							printf("	Going here again will reset the Allocation-mode! \n");
							printf("	Maximum of possession? (<100)\n");

							allocation = get_unsigned_numeric_input_with_not_more_than_2_letters ();

							if (allocation == 0) {
								printf("	That's not possible !!! \n");
							}
						}
					}

					if (beginningmenu == oCards) {
						tac = 0;
						opt = 0;

						if (cards != 0) {
							printf("	Cards-mode reseted! \n");
							printf(" \n");
							cards = 0;
						} else {
							printf("	Do not activate Tactics or Random, it will replace the Cards-Mode! \n");
							printf("	This only works if the number of players is correct! \n");
							printf("	Going here again will reset the Cards-mode! \n");

							time3 = time(NULL);
							cards = 1;
						}

					}

					if (beginningmenu == oInverted) {

						if (inverted != 0) {
							printf("	Inverted-mode reseted! \n");
							printf(" \n");
							inverted = 0;
						} else {
							printf("	Going here again will reset the Inverted-mode! \n");
							printf("	Inverted overrides the limits of development! \n");
							inverted = 1;
						}
					}

					if (beginningmenu == oAddition) {

						if (addition != 0) {
							printf("	Addition-mode reseted! \n");
							printf(" \n");
							addition = 0;
						} else {
							printf("	Going here again will reset the Addition-mode! \n");
							printf("	Addition overrides the limits of development! \n");
							addition = 1;
						}
					}

					if (beginningmenu == oProjection) {

						if (intensity_loss_per_line_multiplication != 0) {
							printf("	Projection-mode reseted! \n");
							printf(" \n");
							intensity_loss_per_line_multiplication = 0;
							intensity_minimum = 0;
							direction = undefined;
						} else {
							printf("	Going here again will reset the Projection-mode! \n");
							printf("	Projection overrides the limits of development! \n \n");
							printf("	Loss of intensity per line passed in per cent: 0<Loss<100		(normal: 40) \n");
							anything = 0;
							anything = get_unsigned_numeric_input_with_not_more_than_2_letters ();

							if (anything == 0) {
								printf("	Than you should not use this option, you will get 40. \n \n");
								anything = 40;
							}

							// printf("anything = %u \n", anything);	//test

							intensity_loss_per_line_multiplication = 100 - anything;
							anything = 0;

							printf("	Minimum of intensity in per cent:  0=<Minimum<1000		(normal: %u) \n \n", intensity_loss_per_line_multiplication);
							intensity_minimum = get_unsigned_numeric_input_with_not_more_than_3_letters ();

							direction = undefined;
							while ((direction != Horizontal)&&(direction != Vertikal)&&(direction != Changing)) {
								printf("	Direction of projection:\n		Horizontal = 0 \n		Vertikal = 1\n		Changing = 2 \n");
								direction = get_unsigned_numeric_input_with_not_more_than_1_letter ();
							}

						}
					}

					if (beginningmenu == oAssassin) {

						if (assassin != 0) {
							printf("	Assassin-mode reseted! \n");
							printf(" \n");
							assassin = 0;
						} else {
							printf("	Going here again will reset the Assassin-mode! \n");
							assassin = 1;
						}
					}

					if (beginningmenu == oPermutations) {

						if ((amount_of_permutation_number_b != 0)||(amount_of_permutation_number_c != 0)) {
							printf("	Permutations-mode reseted! \n");
							printf(" \n");
							amount_of_permutation_number_b = 0;
							amount_of_permutation_number_c = 0;
							permutation_number_b = 0;
							permutation_number_c = 0;
						} else {
							printf("	Going here again will reset the Permutations-mode! \n\n");

							while ((permutation_number_c <= permutation_number_b)||(permutation_number_b == 0)||(permutation_number_c >= 10)) {

								printf("	Choose two numbers b,c with 0<b<c<10 and probably ggT(b,c) = 1. \n");
								printf("	b: \n	c: \n");

								letters_2 = get_unsigned_numeric_input_with_not_more_than_letters_2_for_splitting ();
								permutation_number_b = split_unsigned_numeric_input_with_letters_2 (letters_2, 0);
								permutation_number_c = split_unsigned_numeric_input_with_letters_2 (letters_2, 1);

								// printf("	permutation_number_b = %u \n", permutation_number_b);	//test
								// printf("	permutation_number_c = %u \n", permutation_number_c);	//test
							}

							get_two_amounts_for_permutations (&amount_of_permutation_number_b, &amount_of_permutation_number_c, m, n, permutation_number_b, permutation_number_c);

							// printf("	amount_of_permutation_number_b = %u \n", amount_of_permutation_number_b);	//test
							// printf("	amount_of_permutation_number_c = %u \n", amount_of_permutation_number_c);	//test

							if ((amount_of_permutation_number_b == 0)&&(amount_of_permutation_number_c == 0)) {
								permutation_number_b = 0;
								permutation_number_c = 0;
								printf("	Try again, it doesn't fit. \n");
							}
						}
					}

					if (beginningmenu == oAvalanche){
						if (avalanche != 0){
							avalanche = 0;
							printf("	Avalanche deactivated \n");
						} else if (avalanche == 0){
							avalanche = 1;
							printf("	Avalanche activated \n");
						}
						printf("\n");
					}
					
					if (beginningmenu == oSpreading){
						if (spreading != 0){
							spreading = 0;
							printf("	Spreading deactivated \n");
						} else if (spreading == 0){
							spreading = 1;
							printf("	Spreading overrides the limits of development! \n");
							printf("	Spreading activated \n");
						}
						printf("\n");
					}
					
					if (beginningmenu == oInvisible){
						if (invisible != 0){
							invisible = 0;
							printf("	Invisible deactivated \n");
						} else if (invisible == 0){
							invisible = 1;
							printf("	Invisible activated \n");
						}
						printf("\n");
					}
					
					if (beginningmenu == oRoses){
						if (roses != 0){
							roses = 0;
							printf("	Roses deactivated \n");
						} else if (roses == 0){
							roses = 1;
							printf("	Played together with undead duration roses will have no effect! \n");
							printf("	Roses activated \n");
						}
						printf("\n");
					}
					
					if (beginningmenu == oPartition) {

						printf("	Every movement of a square owned by a player is counted as if the square has been produced during the development. \n");

						if (partition != 0) {
							printf("	Partition-mode reseted! \n");
							printf(" \n");
							partition = 0;
						} else {
							printf("	Going here again will reset the Partition-mode! \n");
							printf("	Maximum of partition-number (<100) or unlimited partition-number (1) ? \n");

							partition = get_unsigned_numeric_input_with_not_more_than_2_letters ();

							if (partition == 0) {
								printf("	That's not possible !!! \n");
							}
						}
					}

					if ((beginningmenu == oBack+1)&&(gamemode_played == Fall)){
						printf("	Points for win: (0<...<10)			(normal: 3) \n");
						points_for_win = get_unsigned_numeric_input_with_not_more_than_1_letter ();

						if ((points_for_win == 0) || (points_for_win >= 10)) {
							printf("	You missed the assertion(s) !!! \n");
							points_for_win = 3;
						}

					}
					if ((beginningmenu == oBack+2)&&(gamemode_played == Fall)){
						printf("	Turns per drop: (>=2)			(normal: 3) \n");
						turns_per_drop = get_unsigned_numeric_input_with_not_more_than_1_letter ();

						if (turns_per_drop < 2) {
							printf("	You missed the assertion(s) !!! \n");
							turns_per_drop = 3;
						}

					}
					if ((beginningmenu == oBack+3)&&(gamemode_played == Fall)){
						printf("	Speed of the #-square:  (>0)		(normal: 1) \n");
						speed_of_fall = get_unsigned_numeric_input_with_not_more_than_1_letter ();

						if (speed_of_fall == 0) {
							printf("	You missed the assertion(s) !!! \n");
							speed_of_fall = 1;
						}
					}
					if ((beginningmenu == oBack+1)&&(gamemode_played == Hunt)){
						printf("	Rounds to catch? >=5			(normal: 30) \n");
						rtc = get_unsigned_numeric_input_with_not_more_than_2_letters ();
						if (rtc < 5) {
							printf("	You missed the assertion(s) !!! \n");
							rtc = 30;
						}

						printf("	Show-Position-Frequence in Rounds:			(normal: 5) \n");
						spf = get_unsigned_numeric_input_with_not_more_than_1_letter ();
						if (spf < 1) {
							printf("	You missed the assertion(s) !!! \n");
							spf = 5;
						}

						printf("	Show the heart_block or all?:     (normal: all) \n		heart_block: 0 \n		all: 1 \n		\n");
						hboa = get_unsigned_numeric_input_with_not_more_than_1_letter ();
						if (hboa >= 2) {
							printf("	You missed the assertion(s) !!! \n");
							hboa = 1;
						}

						printf("	Show Contact with hunted person:    (normal: 1) \n		No: 0 \n		Always: 1 \n		\n");
						scwhp = get_unsigned_numeric_input_with_not_more_than_1_letter ();
						if (scwhp > 1) {
							printf("	You missed the assertion(s) !!! \n");
							scwhp = 1;
						}

						if (hboa == 0) {
							information_code[2] = 2;
						} else if (hboa == 1) {
							information_code[2] = 1;
						}

						if (scwhp == 1) {
							information_code[3] = 1;
						} else {
							information_code[3] = 0;
						}

					}
					if ((beginningmenu == oBack+1)&&(gamemode_played == Arena)) {

						if (number_of_players != AOP) {
							printf("	This only works if the number of players is correct! \n");
							printf("\n");
							printf("	Going here again will lead to a reset of the exclusion! \n");
						} else {
							printf("	Sorry, you can't exclude any ability, because you need all of them. \n");
						}

						printf(" \n");
						for (unsigned int p=0; p<=AOP; p+=1) {
							ability[p] = 0;
						}

						anything = 0;
						while (((anything == 0)||(anything > 10))&&(exclude_counter < (AOP-number_of_players))) {
							printf("	Which ability do you want to exclude? \n");
							printf(" \n");

							show_abilities (ability);

							printf(" \n");
							printf(" \n");
							if ((ability[1] == 100)||(ability[2] == 100)||(ability[3] == 100)||(ability[4] == 100)||(ability[5] == 100)||(ability[6] == 100)||(ability[7] == 100)||(ability[8] == 100)||(ability[9] == 100)) {
								printf("	Which ability do you want to include? \n");
							}
							printf(" \n");

							show_abilities (ability);

							printf(" \n");
							printf(" \n");
							printf("	Back: 10 \n");
							printf(" \n");
							anything = get_unsigned_numeric_input_with_not_more_than_1_letter ();

							for (unsigned int u=0; u<=AOP; u++) {
								if ((anything == u)&&(ability[u] == 0)) {
									ability[u] = 100;
									exclude_counter += 1;
									anything = 0;
								} else if ((anything == u)&&(ability[u] == 100)) {
									ability[u] = 0;
									exclude_counter -= 1;
									anything = 0;
								}
							}
						}

					}
					
					if ((beginningmenu == oBack+1)&&(gamemode_played == Quidditch)) {	//always synchronisate with (Initialisierung: ... in .h)
						printf("	Klatscher-fly-distance:		(normal: 4) \n");
						Qoa->Klatscher_fly_distance = get_unsigned_numeric_input_with_not_more_than_1_letter ();
						
						printf("	Schnatz-fly-distance:		(normal: 6) \n");
						Qoa->Schnatz_fly_distance = get_unsigned_numeric_input_with_not_more_than_1_letter ();
						
						while ((Qoa->Schnatz_appearence_factor%10 < Qoa->Schnatz_appearence_factor/10)||(Qoa->Schnatz_appearence_factor == 0)) {
							printf("	Schnatz-appearence-factor:		(normal: 25 [read as 2/5]) \n");
							Qoa->Schnatz_appearence_factor = get_unsigned_numeric_input_with_not_more_than_2_letters ();
						}
						
						while ((Qoa->Schnatz_disappearence_factor%10 < Qoa->Schnatz_disappearence_factor/10)||(Qoa->Schnatz_disappearence_factor == 0)) {
							printf("	Schnatz-disappearence-factor:		(normal: 12 [read as 1/2]) \n");
							Qoa->Schnatz_disappearence_factor = get_unsigned_numeric_input_with_not_more_than_2_letters ();
						}
					}
					
					if ((beginningmenu == oBack+2)&&(gamemode_played == Quidditch)) {	//always synchronisate with (Initialisierung: ... in .h)
						for (unsigned int p=1; p<=number_of_players; p++) {
							printf("	Player %u, please create a selection of Team-abilities, everyone wil be able to take it. \n", p);
							unsigned int normal_value;
							normal_value = 5;
							
							printf("	Jaeger-fly-distance:		(normal: %u) \n", normal_value);
							Qta[p].Jaeger_fly_distance = get_unsigned_numeric_input_with_not_more_than_1_letter ();
							
							printf("	Jaeger-throw-distance:		(normal: %u) \n", normal_value);
							Qta[p].Jaeger_throw_distance = get_unsigned_numeric_input_with_not_more_than_1_letter ();
							
							printf("	Hueter-fly-distance:		(normal: %u) \n", normal_value-1);
							Qta[p].Hueter_fly_distance = get_unsigned_numeric_input_with_not_more_than_1_letter ();
							
							printf("	Hueter-throw-distance:		(normal: %u) \n", normal_value);
							Qta[p].Hueter_throw_distance = get_unsigned_numeric_input_with_not_more_than_1_letter ();
							
							printf("	Treiber-fly-distance:		(normal: %u) \n", normal_value);
							Qta[p].Treiber_fly_distance = get_unsigned_numeric_input_with_not_more_than_1_letter ();
							
							printf("	Treiber-hit-distance:		(normal: %u) \n", normal_value);
							Qta[p].Treiber_hit_distance = get_unsigned_numeric_input_with_not_more_than_1_letter ();
							
							printf("	Sucher-fly-distance:		(normal: %u) \n", normal_value);
							Qta[p].Sucher_fly_distance = get_unsigned_numeric_input_with_not_more_than_1_letter ();
						}
					}
					
					if (beginningmenu == KI) {
						anything = 0;
						while (anything == 0) {
							printf("	Which player should be a KI? \n");
							for (unsigned int p=1; p<=number_of_players; p++) {
								if (level[p] == human) {
									printf("	Player %u: %u \n", p, p);
								}
							}
							printf(" \n");

							printf("	Which player should be human again? \n");
							for (unsigned int p=1; p<=number_of_players; p++) {
								if (level[p] != human) {
									printf("	Player %u (level: %u): %u \n", p, level[p], p);
								}
							}
							printf(" \n");
							printf("	Continue: 0 \n");
							printf(" \n");
							anything = get_unsigned_numeric_input_with_not_more_than_1_letter ();

							if (anything == 0) {
								anything = 10;
							} else if (anything <= number_of_players) {
								if (level[anything] == human) {
									number_[AOP] = 0;
									while ((number_[AOP] == 0)||(number_[AOP] >= level_majorante)) {
										printf("	Level of this KI?		(0<x<%u) (0 < Uma(=%u) < Hera(=%u) < Liz(=%u) < Coco(=%u) < Jill(=%u) < Natalie(=%u) < Delilag(=%u) < Yasmin(=%u) < %u according to Contact) \n", level_majorante, Uma, Hera, Liz, Coco, Jill, Natalie, Delilag, Yasmin, level_majorante);
										number_[AOP] = get_unsigned_numeric_input_with_not_more_than_1_letter ();
									}
									level[anything] = number_[AOP];
									number_[AOP] = 0;
								} else if (level[anything] != human) {
									level[anything] = human;
								}
								anything = 0;
							} else {
								anything = 0;
							}
						}
						anything = 0;
					}

					if (beginningmenu == Numberofplayers){	//checklist
						if (gamemode_played == Quidditch) {
							printf("	Every player is going to controll one team.\n	Therefore Quidditch can be played if, and only if there are two players.\n");
						} else {
							Growth_players[0].color = 0;

							number_of_players = 0;

							if (gamemode_played == Survive) {
								while ((number_of_players < 1) || (number_of_players > AOP)){
									printf("	Number of players?		(1 - 9) \n");
									number_of_players = get_unsigned_numeric_input_with_not_more_than_1_letter ();	//watch out, if AOP gets >= 10
								}
							} else {
								while ((number_of_players < 2) || (number_of_players > AOP)){
									printf("	Number of players?		(2 - 9) \n");
									number_of_players = get_unsigned_numeric_input_with_not_more_than_1_letter ();	//watch out, if AOP gets >= 10
								}
							}
							if (gamemode_played == Classic) {
								if (number_of_players == 2) {
									m = Initialisierung_m (gamemode_played);
									n = Initialisierung_n (gamemode_played);
								} else {
									m = 10 +2;
									n = 3*((number_of_players+3)/2) +2;
								}
							} else if (gamemode_played == Collect) {
								if (number_of_players == 2) {
									m = Initialisierung_m (gamemode_played);
									n = Initialisierung_n (gamemode_played);
								} else {
									m = 9 +2;
									n = 4+(4*number_of_players)-1 +2;
								}
							} else if (gamemode_played == Contact) {
								if (number_of_players == 2) {
									m = Initialisierung_m (gamemode_played);
									n = Initialisierung_n (gamemode_played);
								} else {
									m = 10+(number_of_players-2) +2;
									n = 8*((number_of_players+1)/2) +2;
								}
							} else if (gamemode_played == Fall) {
								if (number_of_players == 2) {
									m = Initialisierung_m (gamemode_played);
									n = Initialisierung_n (gamemode_played);
								} else {
									m = 6+2*(((number_of_players+1)/2)-1) +2;
									n = 5*2*((number_of_players+1)/2)+1 +2;
								}
							} else if ((gamemode_played == Fight)||(gamemode_played == Duell)) {
								if (number_of_players == 2) {
									m = Initialisierung_m (gamemode_played);
									n = Initialisierung_n (gamemode_played);
								} else {
									m = 6 +2;
									n = 6+4*((number_of_players+1-2)/2) +2;
								}
							} else if (gamemode_played == Race) {
								if (number_of_players == 2) {
									m = Initialisierung_m (gamemode_played);
									n = Initialisierung_n (gamemode_played);
								} else {
									m = 4*number_of_players-1 +2;
									n = 19 +2;
								}
							} else if (gamemode_played == Rain) {
								if (number_of_players == 2) {
									m = Initialisierung_m (gamemode_played);
									n = Initialisierung_n (gamemode_played);
								} else {
									m = 6 +2;
									n = 7*number_of_players-1 +2;
								}
							} else if (gamemode_played == Hunt) {
								if (number_of_players == 2) {
									m = Initialisierung_m (gamemode_played);
									n = Initialisierung_n (gamemode_played);
								} else {
									m = 2*number_of_players + 1 + 2;
									if ((number_of_players == 4)||(number_of_players == 5)||(number_of_players == 9)) {
										m+=2;
									} else if (number_of_players == 8) {
										m--;
									}
									n = 3*number_of_players + 2;
									if ((number_of_players == 4)||(number_of_players == 5)||(number_of_players == 6)||(number_of_players == 7)) {
										n-=((number_of_players+1)/3);
									} else if (number_of_players == 9) {
										n+=(4-3*(number_of_players%3)-10*(number_of_players/7));
									}
								}
							} else if (gamemode_played == Arena) {
								if (number_of_players == 2) {
									m = Initialisierung_m (gamemode_played);
									n = Initialisierung_n (gamemode_played);
								} else {
									m = 6 + number_of_players + (number_of_players-1)/3 - number_of_players/7 + number_of_players/8 - number_of_players/9 + 2;
									n = 6 + number_of_players + (number_of_players-1)/3 - number_of_players/7 + number_of_players/8 - number_of_players/9 + 2;
								}
							} else if (gamemode_played == Ulcer) {
								if (number_of_players == 2) {
									m = Initialisierung_m (gamemode_played);
									n = Initialisierung_n (gamemode_played);
								} else {
									m = 5 + number_of_players + 2;
									n = 5 + number_of_players + 2;
									if (number_of_players == 3) {
										m--;
										n--;
									}
								}
							} else if (gamemode_played == Dynamic) {
								if (number_of_players == 2) {
									m = Initialisierung_m (gamemode_played);
									n = Initialisierung_n (gamemode_played);
								} else {
									m = 9 + 2*(number_of_players/4) + 4*(number_of_players/6) + 2;
									n = 11 + 4*(number_of_players/5) + 2*(number_of_players/8) + 2;
								}
							} else if (gamemode_played == Survive) {
								m = 9 + number_of_players + 2;
								n = 9 + number_of_players + 2;

								if ((number_of_players == 5)||(number_of_players == 7)) {
									m++;
									n++;
								} else if (number_of_players == 9) {
									m--;
									n--;
								}
							} else if (gamemode_played == Sand) {
								if (number_of_players == 2) {
									m = Initialisierung_m (gamemode_played);
									n = Initialisierung_n (gamemode_played);
								} else {
									m = 5+number_of_players + 2;
									n = 3+4*(number_of_players-1)+ 1/(number_of_players*number_of_players) + 2;
								}
							}
						}
					} else if ((beginningmenu == oBack+2)&&((gamemode_played == Arena)||(gamemode_played == Ulcer))) {
						printf("	Rounds to play:       (normal: 30) \n");
						rtp = get_unsigned_numeric_input_with_not_more_than_2_letters ();
						if (rtp == 0) {
							rtp = 30;
						}
						if (gamemode_played == Ulcer) {
							printf("	K.O.-Mode deactivated \n");
							ulcer_start[0] = 0;
						}
					} else if ((beginningmenu == oBack+1)&&(gamemode_played == Race)){
						printf("	Frequence:      (normal: 6) \n");
						freq = get_unsigned_numeric_input_with_not_more_than_1_letter ();
					} else if ((beginningmenu == oBack+1)&&(gamemode_played == Rain)){
						printf("	Only Object:  yes [1]		no [0] \n");
						rain_obj = get_unsigned_numeric_input_with_not_more_than_1_letter ();
						if ((rain_obj != 1)&&(rain_obj != 0)) {
							printf("	You missed the assertion(s) !!! \n");
							rain_obj = 0;
						}

						printf("	Raindrops per turn:		1,  2,  4,  5,  6   ? \n");
						rain_drops = get_unsigned_numeric_input_with_not_more_than_1_letter ();
						if ((rain_drops == 0) || (rain_drops > 6) || (rain_drops == 3)){
							printf("	You missed the assertion(s) !!! \n");
							rain_drops = 1;
						}
						printf("\n");

						printf("	Characteristics of the Raindrops: \n");
						printf("		Push: 1 \n		Destroy: 2 \n		Explode: 3 \n		Transform: 4 \n		Teleport: 5 \n		Mixed: 6 \n");
						rain = get_unsigned_numeric_input_with_not_more_than_1_letter ();
						if (rain == 3){
							printf("		Explode: 31		or		Explode & survival: 32 \n");
							rain = get_unsigned_numeric_input_with_not_more_than_2_letters ();
						}
						printf("\n");
						if ((rain == 0)||(rain > 6)) {
							printf("	You missed the assertion(s) !!! \n");
							rain = Push;
						}

						printf("	Distance in squares the rain should Fall per turn:      (<=6), 0 = 0,5 \n");
						rain_speed = get_unsigned_numeric_input_with_not_more_than_1_letter ();
						if (rain_speed > 6){
							printf("	You missed the assertion(s) !!! \n");
							rain_speed = 1;
						}
						printf("\n");
					} else if ((beginningmenu == oBack+1)&&(gamemode_played == Ulcer)) {

						printf("	This only works if the number of players is correct! \n");
						printf("\n");
						printf("	Choose the amount of lifes. \n");
						for (unsigned int p=1; p<=number_of_players; p+=1) {
							printf("\n");
							printf("	Lifes PLayer: %u		(normal %u) \n", p, p-1);
							ulcer_lifes[p] = get_unsigned_numeric_input_with_not_more_than_1_letter ();
							printf("\n");
						}
					} else if ((beginningmenu == oBack+3)&&(gamemode_played == Ulcer)) {
						if (ulcer_start[0] == 0) {
							printf("	K.O.-Mode activated. \n");
							printf("	Rounds are unlimited. \n");

							rtp = 0;
							ulcer_start[0] = 1;
						} else if (ulcer_start[0] == 1) {
							printf("	K.O.-Mode deactivated. \n");
							ulcer_start[0] = 0;
						}

					} else if ((beginningmenu == oBack+1)&&(gamemode_played == Dynamic)) {
						printf("	The Gravity is pulling down the object. \n");
						printf("	Gravity:	-5 to 5		(normal: 1) \n");
						erd = get_signed_numeric_input_with_not_more_than_1_letter ();
						if ((erd < -5)||(erd > 5)) {
							printf("	That makes no sense, i will give you the 1. \n");
							erd = 1;
						}
					} else if ((beginningmenu == oBack+2)&&(gamemode_played == Dynamic)) {
						printf("	The Range of the impact moving the object. \n");
						printf("	Range:	0-5		(normal: 1) \n");
						range = get_unsigned_numeric_input_with_not_more_than_1_letter ();
						if (range > 5) {
							printf("	That makes no sense, i will give you the 1. \n");
							range = 1;
						}
					} else if ((beginningmenu == oBack+4)&&(gamemode_played == Dynamic)) {
						printf("	The Coefficient influences the way and strength of the impact moving the object. \n");
						printf("	Coefficient:	0-5		(normal: 1) \n");
						strength = get_unsigned_numeric_input_with_not_more_than_1_letter ();
						if (strength > 5) {
							printf("	That makes no sense, i will give you the 1. \n");
							strength = 1;
						}
					} else if ((beginningmenu == oBack+1)&&(gamemode_played == Survive)) {
						for (unsigned int p=1; p<=3; p+=1) {
							information_code[p] = 2;
						}
						printf("	Do you want to play with: \n");

						while (information_code[1]>1) {
							printf("	-Traps:		Yes: 1		No: 0 \n");
							information_code[1] = get_unsigned_numeric_input_with_not_more_than_1_letter ();
						}
						while (information_code[2]>1) {
							printf("	-Bombs:		Yes: 1		No: 0 \n");
							information_code[2] = get_unsigned_numeric_input_with_not_more_than_1_letter ();
						}
						while (information_code[3]>1) {
							printf("	-Waves:		Yes: 1		No: 0 \n");
							information_code[3] = get_unsigned_numeric_input_with_not_more_than_1_letter ();
						}
					} else if ((beginningmenu == oBack+1)&&(gamemode_played == Sand)) {
						printf("	Where to start falling? \n");
						printf("	Top: 1		Bottom: 2 \n");
						information_code[1] = get_unsigned_numeric_input_with_not_more_than_1_letter ();

						if ((information_code[1] == 0)||(information_code[1] > 2)) {
							printf("	You missed the assertion(s) !!! \n");
							information_code[1] = 1;
						}
					} else if ((beginningmenu == oBack+2)&&(gamemode_played == Sand)) {
						printf("	How many squares falling? \n");
						information_code[2] = get_unsigned_numeric_input_with_not_more_than_2_letters ();

					} else if ((beginningmenu == oBack+4)&&(gamemode_played == Sand)) {
						printf("	After how many rounds falling? (>0)\n");
						information_code[3] = get_unsigned_numeric_input_with_not_more_than_2_letters ();

						if (information_code[3] == 0) {
							printf("	You missed the assertion(s) !!! \n");
							information_code[3] = 2;
						}
					} else if (beginningmenu == oBack){	//auch hier!
						gamemode_played = Invalid;
						break;
					}
					printf("\n");

					printf("	Your chosen set-up: \n");
					printf("\n");
					printf("	Gamemode:");
					if (gamemode_played == Classic) {
						printf(" Classic \n ");
					} else if (gamemode_played == Collect) {
						printf(" Collect \n ");
					} else if (gamemode_played == Contact) {
						printf(" Contact \n ");
					} else if (gamemode_played == Fall) {
						printf(" Fall \n ");
						printf("	Points for win: %u \n", points_for_win);
						printf("	Turns per drop: %u \n", turns_per_drop);
						printf("	Speed of the #-square: %u \n", speed_of_fall);
					} else if (gamemode_played == Fight) {
						printf(" Fight \n ");
					} else if (gamemode_played == Hunt) {
						printf(" Hunt \n ");
						printf("	Rounds to catch: %u \n", rtc);
						printf("	Show-Position-Frequence in Rounds: %u \n", spf);
						printf("	What to show: ");
						if (information_code[2] == 2) {
							printf(" heart-block \n");
						} else if (information_code[2] == 1) {
							printf(" all \n");
						}
						printf("	Show Contact with hunted person: ");
						if (information_code[3] == 0) {
							printf(" No \n");
						} else if (information_code[3] == 1) {
							printf(" Yes \n");
						}
					} else if (gamemode_played == Race) {
						printf(" Race \n ");
						printf("	Frequence: %u \n", freq);
					} else if (gamemode_played == Rain) {
						printf(" Rain \n ");
						printf("	Only Object: ");
						if (rain_obj == 1) {
							printf("	yes \n");
						} else if (rain_obj == 0) {
							printf("	no \n");
						}
						printf("	Raindrops per turn: %u \n", rain_drops);
						printf("	Characteristics of the Raindrops: ");
						if (rain == Push) {
							printf("	Push: 1 \n");
						} else if (rain == Destroy_rain) {
							printf("	Destroy: 2 \n");
						} else if (rain == Explode) {
							printf("	Explode: 3 \n");
						} else if (rain == Explode_and_survival) {
							printf("	Explode & survival: 3 \n");
						} else if (rain == Transform) {
							printf("	Transform: 4 \n");
						} else if (rain == Teleport) {
							printf("	Teleport: 5 \n");
						} else if (rain == Mixed) {
							printf("	Mixed: 6 \n");
						}
						if (rain_speed == 0) {
							printf("	Distance in squares: 0,5 \n");
						} else {
							printf("	Distance in squares: %u \n", rain_speed);
						}
					} else if (gamemode_played == Arena) {
						printf(" Arena \n ");
						printf(" \n ");
						printf("	Excluded abilities: \n");
						printf(" \n");

						if (ability[1] == 100) {
							printf("	Ultra light. \n");
						}
						if (ability[2] == 100) {
							printf("	Light. \n");
						}
						if (ability[3] == 100) {
							printf("	Anti. \n");
						}
						if (ability[4] == 100) {
							printf("	Cornered. \n");
						}
						if (ability[5] == 100) {
							printf("	Inhibitor. \n");
						}
						if (ability[6] == 100) {
							printf("	Shield. \n");
						}
						if (ability[7] == 100) {
							printf("	Poisoning. \n");
						}
						if (ability[8] == 100) {
							printf("	Pressure. \n");
						}
						if (ability[9] == 100) {
							printf("	Electric. \n");
						}
						if (exclude_counter == 0) {
							printf("	No ability excluded. \n");
						}
					} else if (gamemode_played == Ulcer) {
						printf(" Ulcer \n ");
						for (unsigned int p=1; p<=number_of_players; p+=1) {
							printf(" \n ");
							printf("	Lifes player %u: %u \n ", p, ulcer_lifes[p]);
						}
					} else if (gamemode_played == Dynamic) {
						printf(" Dynamic \n ");
						printf("	Gravity: %d \n", erd);
						printf("	range: %u \n", range);
						printf("	Coefficient: %u \n", strength);
					} else if (gamemode_played == Survive) {
						printf(" Survive \n ");
						printf("	Traps: ");
						if (information_code[1] == 1) {
							printf("	yes \n");
						} else if (information_code[1]== 0) {
							printf("	no \n");
						}
						printf("	Bombs: ");
						if (information_code[2] == 1) {
							printf("	yes \n");
						} else if (information_code[2]== 0) {
							printf("	no \n");
						}
						printf("	Waves: ");
						if (information_code[3] == 1) {
							printf("	yes \n");
						} else if (information_code[3]== 0) {
							printf("	no \n");
						}
					} else if (gamemode_played == Sand) {
						printf(" Sand \n ");
						printf("	Gravity begins at the: ");
						if (information_code[1] == 1) {
							printf("	Top \n");
						} else if (information_code[1]== 2) {
							printf("	Bottom \n");
						}
						printf("	Speed : %u \n", information_code[2]);
						printf("	Period: %u \n", information_code[3]);
					} else if (gamemode_played == Quidditch) {
						printf(" Quidditch \n ");
						printf("	Klatscher-fly-distance:	%u \n", Qoa->Klatscher_fly_distance);
						printf("	Schnatz-fly-distance:	%u \n", Qoa->Schnatz_fly_distance);
						printf("	Schnatz-appearence-factor:	%u	to read as %u/%u \n", Qoa->Schnatz_appearence_factor, Qoa->Schnatz_appearence_factor/10, Qoa->Schnatz_appearence_factor%10);
						printf("	Schnatz-disappearence-factor:	%u	to read as %u/%u \n", Qoa->Schnatz_disappearence_factor, Qoa->Schnatz_disappearence_factor/10, Qoa->Schnatz_disappearence_factor%10);
					}
					printf("	Number of players: %u \n", number_of_players);
					printf(" \n ");
					printf(" \n");
					printf("	Zeilen: %u \n	Spalten:%u \n", m-2, n-2);
					printf(" \n");
					if (journey != 0){
						printf("	Journey   activated \n");
					} else if (journey == 0){
						printf("	Journey deactivated \n");
					}
					printf(" \n");
					if (gamemode_played == Ulcer) {
						if (ulcer_start[0] == 1){
							printf("	K.O.-Mode   activated. \n");
						} else if (ulcer_start[0] == 0){
							printf("	K.O.-Mode deactivated \n");
						}

						printf(" \n");
					}

					if (ttt == 0) {
						printf("	Time	deactivated \n");
					} else if (ttt != 0) {
						printf("	Time    activated \n");
					}
					printf("\n");

					if (opague != 0){
						printf("	Opague   activated \n");
						printf(" \n");

						if (opague >= 20) {		//4-Mode-Opague
							printf("	Use the #near-by. \n");
						} else if (opague >= 10) {
							printf("	Use the #Surrounding. \n");
						}
						if (opague % 10 == 1) {
							printf("	Show uneven counts. \n");
						}
						if (opague % 10 == 2) {
							printf("	Show   even counts. \n");
						}
					} else {
						printf("	Opague  deactivated \n");
					}
					printf(" \n");

					if (undead_duration == 0) {
						printf("	undead	deactivated \n");
					} else if (undead_duration != 0) {
						printf("	undead    activated \n");
					}
					printf("\n");

					if (figures == 0) {
						printf("	Figures	deactivated \n");
					} else if (figures != 0) {
						printf("	Figures   activated \n");
					}
					printf("\n");

					if (allocation == 0) {
						printf("	Allocation deactivated \n");
					} else if (allocation != 0) {
						printf("	Allocation   activated \n");
					}
					printf("\n");

					if (inverted == 0) {
						printf("	Inverted deactivated \n");
					} else if (inverted != 0) {
						printf("	Inverted   activated \n");
					}
					printf("\n");

					if (addition == 0) {
						printf("	Addition deactivated \n");
					} else if (addition != 0) {
						printf("	Addition   activated \n");
					}
					printf("\n");

					if (intensity_loss_per_line_multiplication == 0) {
						printf("	Projection deactivated \n");
					} else if (intensity_loss_per_line_multiplication != 0) {
						printf("	Projection   activated \n");
					}
					printf("\n");

					if (assassin == 0) {
						printf("	Assassin deactivated \n");
					} else if (assassin != 0) {
						printf("	Assassin   activated \n");
					}
					printf("\n");

					if ((amount_of_permutation_number_b == 0)&&(amount_of_permutation_number_c == 0)) {
						printf("	Permutations deactivated \n");
					} else if ((amount_of_permutation_number_b != 0)||(amount_of_permutation_number_c != 0)) {
						printf("	Permutations   activated \n");
					}
					printf("\n");

					if (avalanche == 0) {
						printf("	Avalanche deactivated \n");
					} else if (avalanche != 0) {
						printf("	Avalanche   activated \n");
					}
					printf("\n");
					
					if (spreading == 0) {
						printf("	Spreading deactivated \n");
					} else if (spreading != 0) {
						printf("	Spreading   activated \n");
					}
					printf("\n");
					
					if (invisible == 0) {
						printf("	Invisible deactivated \n");
					} else if (invisible != 0) {
						printf("	Invisible   activated \n");
					}
					printf("\n");
					
					if (roses == 0) {
						printf("	Roses deactivated \n");
					} else if (roses != 0) {
						printf("	Roses   activated \n");
					}
					printf("\n");
					
					if (partition == 0) {
						printf("	Partition deactivated \n");
					} else if (partition != 0) {
						printf("	Partition   activated \n");
					}
					printf("\n");
					
					if (opt == 5) {
						printf("	Random    activated \n");
					} else if (opt == 0) {
						printf("	Random  deactivated \n");
					}
					printf(" \n");
					if (tac != 0){
						printf("	Tactics   activated,  stack = %u \n", tac);
					} else {
						printf("	Tactics deactivated \n");
					}
					printf(" \n");
					if (cards != 0){
						printf("	Cards     activated \n");
					} else {
						printf("	Cards   deactivated \n");
					}
					printf(" \n");
					printf("	With KI's: ");
					for (unsigned int p=1; p<=number_of_players; p++) {
						if (level[p] != 0){
							level[0] = 1;
						}
						break;
					}
					if (level[0] == 1) {
						printf("Yes \n");
					} else {
						printf("No \n");
					}
					level[0] = 0;
					printf(" \n");
					printf("	limits.yeni:    %u \n	limits.at_all: %u \n", limits.yeni, limits.at_all);
					printf("	(sometimes only for the journey!) \n");
					printf("\n");

					printf("	Colored squares:	");
					if (Growth_players[0].color == 1) {
						printf("yes \n");
					} else if (Growth_players[0].color == 0) {
						printf("no \n");
					}
					if (beginningmenu != 1) {
						printf("\n");
						printf("	... until now.\n");
						printf("\n");
					} else {
						printf(" \n");
						printf(" \n");
						printf(" \n");
						printf(" \n");
						printf(" Have a good game. \n");
						printf(" \n");

						if (gamemode_played == Arena) {
							choose_your_ability (number_of_players, ability, Growth_players, 0);
						}
					}
					printf("\n");
					printf("\n");
				}
			}

			// scanf("%u", &pause);	//test
			// printf("	#line 2k, before same \n");	//test

			// Startmenü, Ende

			same[0] = 0;
			same[1] = m;
			same[2] = n;
			same[3] = journey;
			same[4] = tac;
			same[5] = gamemode_played;
			same[6] = fall_controll;
			same[7] = turns_per_drop;
			same[8] = speed_of_fall;
			same[9] = avalanche;
			same[10] = ulcer_lifes[1];
			same[11] = rain;
			same[12] = rain_drops;
			same[13] = rain_obj;
			same[14] = rain_speed;
			same[15] = opt;
			same[16] = range;
			same[17] = strength;
			same[18] = limits.yeni;
			same[19] = limits.at_all;
			same[20] = ulcer_lifes[2];
			same[21] = points_for_win;
			same[22] = freq;
			same[23] = use_number;
			same[24] = number_of_players;
			same[25] = rtc;
			same[26] = spf;
			same[27] = ulcer_lifes[0];
			same[28] = roses; // same[28] = hboa;
			same[29] = ttt;
			same[30] = ulcer_lifes[3];
			same[31] = warning_system;
			same[32] = exclude_counter;
			same[33] = rtp;
			same[34] = information_code[0];
			same[35] = information_code[1];
			same[36] = information_code[2];
			same[37] = information_code[3];
			same[38] = ability[0];
			same[39] = ability[1];
			same[40] = ulcer_lifes[4];
			same[41] = ability[2];
			same[42] = ability[3];
			same[43] = ability[4];
			same[44] = ability[5];
			same[45] = ability[6];
			same[46] = ability[7];
			same[47] = ability[8];
			same[48] = ability[9];
			same[49] = Growth_players[0].color;
			same[50] = ulcer_lifes[5];
			same[51] = Growth_players[1].color;
			same[52] = Growth_players[2].color;
			same[53] = Growth_players[3].color;
			same[54] = Growth_players[4].color;
			same[55] = Growth_players[5].color;
			same[56] = Growth_players[6].color;
			same[57] = Growth_players[7].color;
			same[58] = Growth_players[8].color;
			same[59] = Growth_players[9].color;
			same[60] = ulcer_lifes[6];
			same[61] = ulcer_lifes[7];
			same[62] = ulcer_lifes[8];
			same[63] = ulcer_lifes[9];
			same[64] = opague;
			same[65] = number_[3];
			same[66] = number_[4];
			if (erd < 0) {	//int - unsigned int_Komplikationen
				for (unsigned int r=5; r>0; r-=1) {
					if (erd == -abs(r)) {
						same[67] = 10*r;
						break;
					}
				}

			} else {
				same[67] = erd;
			}
			same[68] = undead_duration;
			same[69] = figures;
			same[70] = allocation;
			same[71] = cards;
			same[72] = inverted;
			same[73] = addition;
			same[74] = intensity_minimum;
			same[75] = intensity_loss_per_line_multiplication;
			same[76] = direction;
			same[77] = assassin;
			same[78] = permutation_number_c;
			same[79] = permutation_number_b;
			same[80] = amount_of_permutation_number_c;
			same[81] = amount_of_permutation_number_b;
			same[82] = level[1];
			same[83] = level[2];
			same[84] = level[3];
			same[85] = level[4];
			same[86] = level[5];
			same[87] = level[6];
			same[88] = level[7];
			same[89] = level[8];
			same[90] = level[9];
			same[91] = spreading;
			same[92] = invisible;
			same[93] = partition;

		}
		
		if ((same[5] == Quidditch)&&(Growth_players[0].color == 0)) {	//we need house-colors
			same[49] = 1;
			same[51] = cLIGHT_MAGENTA; //lightmagenta
			same[52] = cYELLOW; //yellow
		}
		
		if (same[5] == Quidditch) {
			Initialisierung_Qs (Qs, Qta, Qoa, Growth_players);
		}
		
		// for (unsigned int p=0; p<=NOSV-1; p++) {
			// printf("same[%u] = %u \n", p, same[p]);	//test
		// }
	
		//start of playing/the first print of a field

		//	same, Field, position, AOP,   real (evet or hayir) for while{}
		playing_a_game (same, position, AOP, time3, &playtime, NOSV, Qs);
		
		Quidditch_team_abilities_Vektor_Destroy (Qta);
		Quidditch_object_abilities_Vektor_Destroy (Qoa);
		Quidditch_setup_Vektor_Destroy (Qs);	//Problem with Qoa_Destroying?
		
	}

	unsigned_int_Vektor_Destroy (same);
	
	#ifdef Aufraeumphase_mistake_search
		printf("	Existing Fields: %d \n ", Spielfeld_counter);	//test
		printf("	Existing Vektors: %d \n ", Vektor_counter);	//test
		printf("	\n ");
		printf("	#line 1k, 24\n");	//test
		scanf("%u", &pause);	//test
	#endif
	

	return 0;
}



void playing_a_game (unsigned int* same, unsigned int* position, unsigned int AOP, time_t time3, unsigned int* playtime, unsigned int NOSV, Quidditch_setup* Qs) {

	Realize_modifications_variables* rmv;	//realize_modifications_variables (rmv), contains both copied and new variables

	Spielfeld Field;	//cons_field in Field, cons_journey in Journey_o.field, Field[0]==Das Spielfeld, Journey_o.field[0]==Das Journeyfeld
	Spielfeld Sf_permutations;	//Permutations-Spielfeld
	Spielfeld numbers_of_, stack_of_;	//ruck muss raus, done, numbers_of_==statistics, numbers_of_[geben][0]==Matchballs etc., stack_of_==stack of tac

	unsigned int g, survive_different;	//it is time to play, and to play different
	unsigned int w, d, e;	// Evolutionsparameter
	unsigned int player_counter, round_counter;	//Ausgeschiedene Spieler und Rundenanzahl
	unsigned int round_counter_before;	//A signal of going further or back
	unsigned int controll_1, controll_2;	// just to controll something
	unsigned int menuoperator;	// Navigationsparameter
	unsigned int all_turns_correction;	// die Züge an die aktuelle Spieleranzahl anpassen
	unsigned int sup_num, suprise;	// specialeffectssuprise;
	unsigned int KI_decision;	//choice of where to keep/produce made by a KI

	unsigned int cons[AOP+1], pere[AOP+1], win_condition[AOP+1], var_[AOP+1], ges[AOP+1], out_counter[AOP+1], geben;	//saved numbers, penalty-reminder, Spielereingabevariable, Anzahl der Spielsteine, Are you out of play, aktiver Spieler

	unsigned int* Points;		//undecided, 1, 2

	time_t time1, time2, time4;
	double time_warning;
	double time_saver;

	int* dynamic_pointer;	//Dynamic direction
	int** dynamic_pointer_save;	//saved Dynamic direction
	// unsigned int** sigmas_for_permutation_number_c;	//permutations in Permutations, in struct
	// unsigned int** sigmas_for_permutation_number_b;	//permutations in Permutations, in struct


	// copies of the same-variables following

	unsigned int m, n;	//Field: height and length
	unsigned int opt, tac, cards, use_number;	//how to get the actions: random, tactical, mixed in cards, rmv->use_number shows possible actions
	unsigned int rain;	//Gamemode: Rain
	unsigned int gamemode_played, number_of_players;	//the played gamemode, how many players are playing
	unsigned int freq;	// Race
	// unsigned int permutation_number_c, permutation_number_b, amount_of_permutation_number_c, amount_of_permutation_number_b;	// Permutation matters, now in a struct called Collector_of_permutation
	unsigned int rtp;	//rounds to play - used in Ulcer/Arena
	unsigned int rtc, spf;	// Gamemode: Hunt
	unsigned int exclude_counter;	//Gamemode: Arena

	unsigned int ulcer_lifes[AOP+1], ulcer_start[AOP+1], information_code[4], ability[AOP+1];	//how many lifes in Ulcer, some necessary information about gamemodes, abilities in Arena
	unsigned int level[AOP+1];		// Colors for players, the level of the KI's
	unsigned int number_[AOP+1];	//numbers to confuse the random and for the statistics
	int erd; // Gamemode: Dynamic
	
	Special_Fields Opague_o, Journey_o, Roses_o;	// add in set_Spielfeld_Eintrag and show_field, save for each player, go back?
	Special_Fields_Collector* sfc;
	Growth_Player Growth_players[AOP+1];	//id and color
	Limits limits;	//the limits
	Num_num num;	//remix the random
	Evolution evolution;	//Fields for born/dying squares
	Earth_impact impact_tuple;
	Single_option_representives single_option_representives;	// Modifications, Projection matters
	Time_matters time_matters;	// Time-limits and the penalties
	
	Moveable_objects_condition* Moc_Klatscher;	//Quidditch balls
	Moveable_objects_condition* Moc_Quaffel;
	Moveable_objects_condition* Moc_Schnatz;
	
	// Duell_Specials* Duell_specials;	// not working yet, deactivated anywhere
	
	rmv = Realize_modifications_variables_Vektor_Create(1);
	sfc = Special_Fields_Collector_Vektor_Create (1);
	
	w = 3;
	d = 2;
	e = 3;

	Points = unsigned_int_Vektor_Create (3);	//possible to modify

	num.bir = 0;
	num.iki = 0;
	num.uec = 0;

	menuoperator = 0;

	controll_1 = 0;
	controll_2 = 0;

	round_counter_before = 0;
	round_counter = 0;

	time_warning = 0.0;
	time_saver = 0.0;

	player_counter = 0;

	Initialisierung_Arrays_2 (AOP, pere, ges, var_, ulcer_start, win_condition, out_counter, number_, cons);

	survive_different = 0;

	all_turns_correction = 0;	//for mechanisms based on turns of the players, if a player is out

	suprise = 0;
	sup_num = 0;

	KI_decision = 0;
	level[0] = 0;

	same[0] = 0;
	m = same[1];
	n = same[2];
	Journey_o.characterization = same[3];
	tac = same[4];
	gamemode_played = same[5];
	ulcer_lifes[1] = same[10];
	rain = same[11];
	opt = same[15];
	impact_tuple.range = same[16];
	impact_tuple.strength = same[17];
	limits.yeni = same[18];
	limits.at_all = same[19];
	ulcer_lifes[2] = same[20];
	freq = same[22];
	use_number = same[23];
	number_of_players = same[24];
	rtc = same[25];
	spf = same[26];
	ulcer_lifes[0] = same[27];
	Roses_o.characterization = same[28];	// hboa = same[28];
	time_matters.ttt = same[29];
	ulcer_lifes[3] = same[30];
	time_matters.warning_system = same[31];
	exclude_counter = same[32];
	rtp = same[33];
	information_code[0] = same[34];
	information_code[1] = same[35];
	information_code[2] = same[36];
	information_code[3] = same[37];
	ability[0] = same[38];
	ability[1] = same[39];
	ulcer_lifes[4] = same[40];
	ability[2] = same[41];
	ability[3] = same[42];
	ability[4] = same[43];
	ability[5] = same[44];
	ability[6] = same[45];
	ability[7] = same[46];
	ability[8] = same[47];
	ability[9] = same[48];
	Growth_players[0].color = same[49];
	ulcer_lifes[5] = same[50];
	Growth_players[1].color = same[51];
	Growth_players[2].color = same[52];
	Growth_players[3].color = same[53];
	Growth_players[4].color = same[54];
	Growth_players[5].color = same[55];
	Growth_players[6].color = same[56];
	Growth_players[7].color = same[57];
	Growth_players[8].color = same[58];
	Growth_players[9].color = same[59];
	ulcer_lifes[6] = same[60];
	ulcer_lifes[7] = same[61];
	ulcer_lifes[8] = same[62];
	ulcer_lifes[9] = same[63];
	Opague_o.characterization  = same[64];
	number_[3] = same[65];
	number_[4] = same[66];
	if (same[67] >= 10) {	//-1 --> 10, -2 --> 20, ...
		erd = -1 * (same[67]/10);
	} else {
		erd = same[67];
	}
	single_option_representives.undead_duration = same[68];
	sfc->Allocation_o.characterization = same[70];
	cards = same[71];
	single_option_representives.inverted = same[72];
	single_option_representives.addition = same[73];
	single_option_representives.intensity_loss_per_line_multiplication = same[75];
	direction = same[76];
	rmv->Collector_of_permutation.permutation_number_c = same[78];
	rmv->Collector_of_permutation.permutation_number_b = same[79];
	rmv->Collector_of_permutation.amount_of_permutation_number_c = same[80];
	rmv->Collector_of_permutation.amount_of_permutation_number_b = same[81];
	level[1] = same[82];
	level[2] = same[83];
	level[3] = same[84];
	level[4] = same[85];
	level[5] = same[86];
	level[6] = same[87];
	level[7] = same[88];
	level[8] = same[89];
	level[9] = same[90];
	single_option_representives.spreading = same[91];
	single_option_representives.invisible = same[92];
	sfc->Partition_o.characterization = same[93];
	
	for (unsigned int p=1; p<=number_of_players; p++) {
		Growth_players[p].id = p;
	}
	
	time3 = time(NULL);	//because of cards
	
	evolution.nl = Spielfeld_Create (m, n, number_of_players);	//the order is (1, 2, 3) ==> [3][1][2]
	evolution.od = Spielfeld_Create (m, n, number_of_players);

	dynamic_pointer = int_Vektor_Create (8);
	dynamic_pointer_save = int_2dim_Vektor_Create (number_of_players+1, 4);

	if (rmv->Collector_of_permutation.permutation_number_b == 0) {
		rmv->Collector_of_permutation.permutation_number_c = 1;
	}
	rmv->Collector_of_permutation.sigmas_c = unsigned_int_2dim_Vektor_Create (Fakultaet(rmv->Collector_of_permutation.permutation_number_c - 1), rmv->Collector_of_permutation.permutation_number_c);
	if (rmv->Collector_of_permutation.permutation_number_b == 0) {
		rmv->Collector_of_permutation.permutation_number_c = 0;
	}

	if (rmv->Collector_of_permutation.permutation_number_c == 0) {
		rmv->Collector_of_permutation.permutation_number_b = 1;
	}
	rmv->Collector_of_permutation.sigmas_b = unsigned_int_2dim_Vektor_Create (Fakultaet(rmv->Collector_of_permutation.permutation_number_b - 1), rmv->Collector_of_permutation.permutation_number_b);
	if (rmv->Collector_of_permutation.permutation_number_c == 0) {
		rmv->Collector_of_permutation.permutation_number_b = 0;
	}
	
	Journey_o.field = Spielfeld_Create (m, n, number_of_players);	//gamemode_played 11 journey, done
	
	Opague_o.field = Spielfeld_Create (m, n, 0);
	
	sfc->Allocation_o.field = Spielfeld_Create (m, n, number_of_players+2);
	sfc->Partition_o.field = Spielfeld_Create (m, n, number_of_players+2);
	
	Roses_o.field = Spielfeld_Create (m, n, 0);
	
	// scanf("%u", &pause);	//test
	// printf("	#line 2k, after Allocation_o.field \n");	//test

	Sf_permutations = Spielfeld_Create (m, n, 0);

	// scanf("%u", &pause);	//test
	// printf("	#line 2k, after Sf_permutations \n");	//test

	if (rmv->Collector_of_permutation.permutation_number_b == 0) {
		rmv->Collector_of_permutation.amount_of_permutation_number_c = 1;
		rmv->Collector_of_permutation.permutation_number_c = 1;
	}
	rmv->Collector_of_permutation.areas_c = Spielfeld_Create (rmv->Collector_of_permutation.permutation_number_c, 2, rmv->Collector_of_permutation.amount_of_permutation_number_c-1);
	if (rmv->Collector_of_permutation.permutation_number_b == 0) {
		rmv->Collector_of_permutation.amount_of_permutation_number_c = 0;
		rmv->Collector_of_permutation.permutation_number_c = 0;
	}

	// scanf("%u", &pause);	//test
	// printf("	#line 2k, between the Collectors \n");	//test

	if (rmv->Collector_of_permutation.permutation_number_c == 0) {
		rmv->Collector_of_permutation.amount_of_permutation_number_b = 1;
		rmv->Collector_of_permutation.permutation_number_b = 1;
	}
	rmv->Collector_of_permutation.areas_b = Spielfeld_Create (rmv->Collector_of_permutation.permutation_number_b, 2, rmv->Collector_of_permutation.amount_of_permutation_number_b-1);
	if (rmv->Collector_of_permutation.permutation_number_c == 0) {
		rmv->Collector_of_permutation.amount_of_permutation_number_b = 0;
		rmv->Collector_of_permutation.permutation_number_b = 0;
	}

	// scanf("%u", &pause);	//test
	// printf("	#line 2k, before Field \n");	//test

	Field = Spielfeld_Create (m, n, number_of_players);

	// scanf("%u", &pause);	//test
	// printf("	#line 2k, before start_normal \n");	//test

	start_normal (Field, m, n, gamemode_played, number_of_players, 0, Opague_o.field, sfc, single_option_representives.inverted);

	// show_field (number_of_players, single_option_representives.invisible, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, 0, Growth_players, 0, sfc);	//test, geben durch 0 ersetzt

	// scanf("%u", &pause);	//test
	// printf("	#line 2022, before numbers_of_ \n");	//test
	// printf("	AOP= %u \n", AOP);	//test
	// printf("	number_of_players= %u \n", number_of_players);	//test

	// scanf("%u", &pause);	//test
	// Spielfeld FieldTest;
	// FieldTest = (unsigned int **) calloc(1, sizeof(unsigned int*));
	// printf("Checkpoint: 1	\n ");	//test
	// FieldTest[0] = (unsigned int **) calloc(1, sizeof(unsigned int*));
	// printf("Checkpoint: 2	\n ");	//test
	// FieldTest[0][0] = (unsigned int *) calloc(1, sizeof(unsigned int));
	// printf("Checkpoint: 3	\n ");	//test


	numbers_of_ = Spielfeld_Create (7, 1, number_of_players);
	stack_of_ = Spielfeld_Create (7, 1, number_of_players);

	// scanf("%u", &pause);	//test
	// printf("	#line 2k, before tac \n");	//test

	//before this line no not-trivial-definitions
	
	limits.at_all_saver = limits.at_all;

	reset_of_ges (ges, number_of_players);
	ges_counter (Field, m, n, ges, number_of_players);
	
	// printf("Checkpoint: a	\n ");	//test
	
	// Initialisation of rmv
	rmv->win_condition = unsigned_int_Vektor_Create(AOP+1);
	rmv->numbers_of_ = Spielfeld_Create (7, 1, number_of_players);
	rmv->same = unsigned_int_Vektor_Create(NOSV);
	rmv->var_ = unsigned_int_Vektor_Create(AOP+1);
	rmv->Points =  unsigned_int_Vektor_Create(AOP+1);
	rmv->ulcer_start = unsigned_int_Vektor_Create(AOP+1);
	rmv->ulcer_lifes = unsigned_int_Vektor_Create(AOP+1);
	rmv->out_counter = unsigned_int_Vektor_Create(AOP+1);

	// setting rmv
	for (unsigned int p=0; p<=NOSV-1; p++) {
		rmv->same[p] = same[p];	//static during the game
	}
	for (unsigned int p=0; p<=number_of_players; p++) {
		for (unsigned int i=0; i<=6; i++) {
			rmv->numbers_of_[p][i][0] = numbers_of_[p][i][0];
		}
	}
	
	for (unsigned int p=0; p<=AOP; p++) {
		rmv->win_condition[p] = win_condition[p];
		rmv->var_[p] = var_[p];
		rmv->Points[p] = Points[p];
		rmv->ulcer_start[p] = ulcer_start[p];
		rmv->ulcer_lifes[p] = ulcer_lifes[p];
		rmv->out_counter[p] = out_counter[p];

	}
	// printf("Checkpoint: h	\n ");	//test
	
	rmv->AOP = AOP;	//static during the game
	rmv->freq = freq;	//static during the game
	rmv->player_counter = player_counter;
	rmv->all_turns_correction = all_turns_correction;
	rmv->use_number = use_number;
	rmv->round_counter = round_counter;
	rmv->rtc = rtc;	//static during the game
	rmv->rtp = rtp;	//static during the game
	// rmv->Collector_of_permutation = Collector_of_permutation;	//static during the game, already made for each component
	
	// printf("Checkpoint: i	\n ");	//test
	
	Moc_Quaffel = Moveable_objects_condition_Vektor_Create (1);
	Moc_Schnatz = Moveable_objects_condition_Vektor_Create (1);
	Moc_Klatscher = Moveable_objects_condition_Vektor_Create (2);
	Initialisierung_Moc (Moc_Quaffel, Moc_Schnatz, Moc_Klatscher, m, n);
	
	Localization_of_Moc (Field, m, n, Moc_Quaffel, Moc_Schnatz, Moc_Klatscher);	//better save than sorry. (Field before Moc)
	
	if (sfc->Allocation_o.characterization != 0) {	//in functions (Initialisierung), go on
		for (unsigned int i=1; i<=m-2; i++) {
			for (unsigned int j=1; j<=n-2; j++) {
				if ((Field[0][i][j] != 0)&&(Field[0][i][j] <= number_of_players)) {
					set_Spielfeld_Eintrag (Field, 0, Opague_o.field, gamemode_played, sfc, number_of_players, sfc->Allocation_o.field, 0, i, j, 1);	//geben durch 0 ersetzt
				}
			}
		}
	}
	if (sfc->Partition_o.characterization != 0) {
		for (unsigned int i=1; i<=m-2; i++) {
			for (unsigned int j=1; j<=n-2; j++) {
				if ((Field[0][i][j] != 0)&&(Field[0][i][j] <= number_of_players)) {
					set_Spielfeld_Eintrag (Field, 0, Opague_o.field, gamemode_played, sfc, number_of_players, sfc->Partition_o.field, 0, i, j, 1);	//geben durch 0 ersetzt
				}
			}
		}
	}

	if (tac != 0){
		for (unsigned int p=1; p<=number_of_players; p+=1){
			for (unsigned int q=1; q<=6; q+=1){
				stack_of_[p][q][0] = tac;
			}
		}

	} else if (cards != 0) {
		time1 = time(NULL);
		printf("	How many cards to own (1<...<100)?\n");

		cards = get_unsigned_numeric_input_with_not_more_than_2_letters ();

		if (cards == 0) {
			printf("	That's not possible, you will take 6 !!! \n");
			cards = 6;
		}
		time2 = time(NULL);
		time_saver = difftime(time2, time1);

		// printf("	Zeitdifferenz12: %f \n", time_saver);	//test
		// scanf("%lf", &time_saver);

		anything = 0;
		unsigned int c = 0;
		unsigned int x = 0;
		while (anything == 0) {
			c += 1;
			if ((time_saver) <= 1.0*c) {
				anything = (c%6)+1;
			}
		}
		c = 0;

		time_saver = difftime(time1, time3);

		// printf("	Zeitdifferenz31: %f \n", time_saver);	//test
		// scanf("%lf", &time_saver);

		while (x == 0) {
			c += 1;
			if ((time_saver) <= 1.0*c) {
				x = (c%6)+1;
			}
		}

		for (unsigned int q=1; q<=cards; q++) {
			for (unsigned int p=1; p<=number_of_players; p++) {
				stack_of_[p][((((anything+(((p*q)/3)%6)+1)%6)+1)*(((x+q/5)%6)+1))%7][0] += 1;	// %7 weil das Ergebnis nicht durch 7 teilbar
			}
		}

		// for (unsigned f=1; f<=number_of_players; f++) {	//test
			// printf("Spieler %u:", f);
			// for (unsigned int g=1; g<=6; g++) {
				// printf("	[%u]=%u", g, stack_of_[f][g][0]);
			// }
			// printf("\n");
		// }

		c = 0;
		x = 0;
		anything = 0;
		time1 = 0;
		time2 = 0;
		time3 = 0;
		time_saver = 0.0;
	}

	level[0] = 0;
	for (unsigned int p=1; p<=number_of_players; p++) {
		if (level[p] == human) {
			level[0] = 1;
			break;
		}
	}
	if (level[0] == 1) {
		for (unsigned int p=1; p<=number_of_players; p++) {	//make it better, go on
			if (level[p] != human) {
				level[0] = 2;
				while ((level[0] != 0)&&(level[0] != 1)) {
					printf("	Skip between KI's: \n");
					printf("		Yes: 1		No: 0 \n");
					level[0] = get_unsigned_numeric_input_with_not_more_than_1_letter();
				}
				break;
			}
		}
	} else {
		level[0] = 2;
		while ((level[0] != 0)&&(level[0] != 1)) {
			printf("	Skip between KI's: \n");
			printf("		Yes: 1		No: 0 \n");
			level[0] = get_unsigned_numeric_input_with_not_more_than_1_letter();
		}
		if (level[0] == 0) {
			level[0] = 5;
		}
	}

	if ((rmv->Collector_of_permutation.amount_of_permutation_number_b != 0)||(rmv->Collector_of_permutation.amount_of_permutation_number_c != 0)) {
		translate_permutations_amounts_to_permutations_areas (Sf_permutations, m, n, rmv->Collector_of_permutation);

		// scanf("%u", &pause);	//test
		// printf("	#line 2k, after translate_permutations_amounts_to_permutations_areas \n");	//test

		// show_field (number_of_players, single_option_representives.invisible, level, Sf_permutations, Opague_o.field, Sf_permutations, m, n, gamemode_played, information_code, 0, Growth_players, 0, sfc);	//test

		get_sigmas_for_permutation_number (rmv->Collector_of_permutation.sigmas_c, rmv->Collector_of_permutation.permutation_number_c);

		// scanf("%u", &pause);	//test
		// printf("	#line 2k, after get_sigmas_for_permutation_number (c) \n");	//test

		get_sigmas_for_permutation_number (rmv->Collector_of_permutation.sigmas_b, rmv->Collector_of_permutation.permutation_number_b);
	}

	if (gamemode_played == Arena) {	//abilities in information_code
		information_code[1] = ability[5];
		information_code[2] = ability[7];
		information_code[3] = ability[8];

		if ((ability[1] != 0)&&(ability[1] != 100)) {
			Field[0][1][0] = 10*ability[1];
		}
		if ((ability[2] != 0)&&(ability[2] != 100)) {
			Field[0][0][0] = 10*ability[2];
		}
		if ((ability[3] != 0)&&(ability[3] != 100)) {
			Field[0][0][1] = 10*ability[3];
		}
		if ((ability[4] != 0)&&(ability[4] != 100)) {
			Field[0][0][n-1] = 10*ability[4];
		}
		if ((ability[6] != 0)&&(ability[6] != 100)) {
			Field[0][m-1][n-1] = 10*ability[6];
		}
		if ((ability[9] != 0)&&(ability[9] != 100)) {
			Field[0][m-1][0] = 10*ability[9];
		}

	}

	g = 1;

	if (gamemode_played == Survive) {
		while ((survive_different == 0)||(survive_different > 60)){
			printf("	Please give me a number between 1 and 60. \n");
			survive_different = get_unsigned_numeric_input_with_not_more_than_2_letters ();
		}
	}
	
	
	if (gamemode_played == Duell) {
		
		// unsigned int number_of_abilities;	//0<number_of_abilities<10
		// Spielfeld list_of_taken_abilities;
		// unsigned int* list_of_all_abilities;
		
		// Duell_specials->number_of_abilities = 0;
		// while (Duell_specials->number_of_abilities == 0) {
			// printf("	With how many abilities do you want to play? (0<x<10)\n");
			// Duell_specials->number_of_abilities = get_unsigned_numeric_input_with_not_more_than_1_letter ();
		// }
		// printf("	Duell_specials:  number_of_abilities\n");	//test
		
		// Duell_specials_Initialisation (Duell_specials, number_of_players);
		// printf("	Duell_specials:  Initialisierung\n");	//test
		
		// Initialisierung_Duell_abilities (Duell_specials->list_of_all_abilities);
		// printf("	Duell_specials:  Initialisierung abilities\n");	//test
		
		// Duell_ability_choice (Growth_players, number_of_players, Duell_specials);
		// printf("	Duell_specials:  ability-choice\n");	//test
	} else {
		// Duell_specials->number_of_abilities = 3;
		// Duell_specials_Initialisation (Duell_specials, number_of_players);
	}
	
	if (gamemode_played == Rain) {
		show_field (number_of_players, single_option_representives.invisible, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, 0, Growth_players, 0, sfc);	// geben mit 0 ersetzt
	}

	printf("gamemode_played = %u \n", gamemode_played);	//test
	
	while (g != 0) {	//start of the turns

		// printf("gamemode_played = %u \n", gamemode_played);	//test
		// printf("g = %u \n", g);	//test
	
		if (rmv->player_counter == number_of_players) {	//Notbremse, kein Spieler spielt mehr
			break;
		}

		geben = ((g-1)%number_of_players)+1;	//aktiver Spieler, an Anzahl der Züge gekoppelt

		if (time_matters.ttt != 0) {	//reset of the time
			time_warning = 0.0;
			time_saver = 0.0;
		}

		// scanf("%u", &pause);	//test
		// printf("	#line 2k, after geben-def \n");	//test

		// printf("	test \n");
		// show_field (number_of_players, single_option_representives.invisible, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, sfc);	//test
		// printf("	test \n");

		round_counter_before = rmv->round_counter;
		rmv->round_counter = 0;
		for (unsigned int p=1; p<=g; p+=number_of_players) {
			rmv->round_counter += 1;
		}
		
		for (unsigned int i=1; i<=m-2; i++) {	//update of scf->Partition_o.field[1] 
			for (unsigned int j=1; j<=n-2; j++) {
				set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, sfc, number_of_players, sfc->Partition_o.field, 1, i, j, sfc->Partition_o.field[0][i][j]);
			}
		}
		
		// show_field (number_of_players, single_option_representives.invisible, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, sfc);	//test
		
		survive_obstacles_generator (gamemode_played, rmv->round_counter, round_counter_before, information_code, Field, geben, sfc, number_of_players, Opague_o, Sf_permutations, AOP, level, Growth_players, m, n, survive_different, ges, rmv->var_, g, rmv->use_number, tac, time_matters.ttt, single_option_representives);

		Dynamic_ball_movement (Field, Opague_o, m, n, geben, sfc, number_of_players, level, Sf_permutations, information_code, Growth_players, gamemode_played, dynamic_pointer, erd, position, g, ges, impact_tuple, rmv, single_option_representives);
		// these two modifications do not belong to realize_modifications

		if (gamemode_played == Hunt) {	//Hunt-Formalitäten

			if (rmv->round_counter == (rtc - 1)) {
				rmv->numbers_of_[1][0][0] = 1;
			} else if ((rmv->round_counter == rtc)&&(geben == number_of_players)) {
				printf(" \n ");
				printf(" \n ");
				printf(" Ready for the last round? \n ");
				printf(" \n ");
				printf(" \n ");
			}

			if (rmv->round_counter%spf == 0) {
				information_code[1] = 1;
			} else {
				information_code[1] = 0;
			}
		}

		if ((gamemode_played == Arena)||(gamemode_played == Ulcer)) {	//last round
			if ((rmv->round_counter == rtp)&&(geben == number_of_players)) {
				printf(" \n ");
				printf(" \n ");
				printf(" Ready for the last round? \n ");
				printf(" \n ");
				printf(" \n ");
			}
		}

		// printf("\n");	//test
		// printf("	information_code: [0]=%u,	[1]=%u,	[2]=%u,	[3]=%u	\n", information_code[0], information_code[1], information_code[2], information_code[3]);
		// printf("\n");

		//previous if(geben == 1){}

		if (Opague_o.characterization >= 1) {
			opague_builder (Field, Opague_o, m, n, geben, AOP, sfc, number_of_players, gamemode_played);
		}

		if ((time_matters.ttt != 0)&&(pere[geben] == 100)) {
			g+=1;
			continue;
		}

		if (ges[geben] == 1010*geben) {	//Überspringen, wenn ausgeschieden	(//mehr-gamemode_played)

			rmv->all_turns_correction += 1;
			rmv->var_[geben] = 0;		//eigentlich rmv->var_[geben] = 1010*geben, done, undone because only if rmv->var_[0] == 1 somebody goes back

			for (unsigned int i=1; i<m-1; i+=1){
				for (unsigned int j=1; j<n-1; j+=1){

					for (unsigned int p=0; p<=number_of_players; p+=1) {	//missed to include the 0, that caused not-wanted-revives.
						if (Field[p][i][j] == geben) {
							set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, sfc, number_of_players, Field, p, i, j, 0);
						}
						if (Journey_o.characterization != 0){
							if (Journey_o.field[p][i][j] == geben) {
								set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, sfc, number_of_players, Journey_o.field, p, i, j, 0);
							}
						}
					}
					if (Journey_o.characterization != 0) {
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, sfc, number_of_players, Journey_o.field, geben, i, j, Journey_o.field[Vorganger(geben, number_of_players)][i][j]);
					}
					set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, sfc, number_of_players, Field, geben, i, j, Field[Vorganger(geben, number_of_players)][i][j]);
				}
			}
			cons[geben] = cons[Vorganger(geben, number_of_players)];

			if (gamemode_played == Dynamic){
				for (unsigned int p=2; p<=5; p+=1) {
					dynamic_pointer_save[Vorganger(geben, number_of_players)][p-2] = dynamic_pointer_save[geben][p-2]; // if geben == 1 => number_of_players, sonst geben-1	(maybe a function), done
				}
			}	//KI testing... warning ?

			if (rmv->var_[0] == 1) {	//if "go back" is used
				g-=1;
				rmv->var_[geben] = 1010*geben;
				rmv->all_turns_correction -= 1;
			} else {
				g+=1;
			}
			continue;
		}

		if ((gamemode_played == Ulcer)&&(rmv->ulcer_start[geben] == missing)) {	//not on the field yet

			rmv->all_turns_correction += 1;

			if (rmv->var_[0] == 1) {	//if "go back" is used
				g-=1;
				rmv->var_[geben] = 1010*geben;
				rmv->all_turns_correction -= 1;
			} else {
				g+=1;
			}
			continue;
		}

		if ((level[0] != 5)&&(level[0] != 0)&&(level[geben] != human)) {
			unsigned int necessary;
			necessary = 0;
			is_it_necessary (level, ges, &necessary, geben, number_of_players);
			if (necessary == 1) {
				level[0] = 3;
			} else {
				level[0] = 1;
			}
		}

		if (level[0] <= 2) {
			for (unsigned int yer=0; yer<=5; yer++) {
				printf("\n");
			}
		}
		printf("	Round: %u \n", rmv->round_counter);
		printf("\n");

		// if (rmv->round_counter >= 66) {	//test
			// level[0] = 0;	//test
			// printf("Have a look\n");	//test
			// show_field (number_of_players, single_option_representives.invisible, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, sfc);	//test
			// scanf("%u", &pause);	//test
			// level[0] = 3;	//test
		// }	//test
		
		if (sfc->Partition_o.characterization != 0) {
			printf("	Partition-number: %u \n", sfc->Partition_o.characterization);
		}
		if (sfc->Allocation_o.characterization != 0) {
			printf("	Allocation-number: %u \n", sfc->Allocation_o.characterization);
		}
		if (Journey_o.characterization != 0) {
			if (gamemode_played == Race) {	//journey-frequence
				anything = 2*freq;
			} else {
				anything = (10*(number_of_players - rmv->player_counter) - 1);
			}

			printf("	All turns until the journey starts: %u \n", (anything - ((g-rmv->all_turns_correction-1)%anything)));

			anything = 0;
		}
		if (single_option_representives.intensity_loss_per_line_multiplication != 0) {
			if (gamemode_played == Race) {	//journey-frequence
				anything = 2*freq-2;
			} else {
				anything = (9*(number_of_players - rmv->player_counter) - 1);
			}

			printf("	All turns until the projection starts: %u \n", (anything - ((g-rmv->all_turns_correction-1)%anything)));

			anything = 0;
		}
		if ((rmv->Collector_of_permutation.amount_of_permutation_number_b != 0)||(rmv->Collector_of_permutation.amount_of_permutation_number_c != 0)) {
			if (gamemode_played == Race) {	//journey-frequence
				anything = 2*freq-3;
			} else {
				anything = (8*(number_of_players - rmv->player_counter) - 1);
			}

			printf("	All turns until the permutation starts: %u \n", (anything - ((g-rmv->all_turns_correction-1)%anything)));

			anything = 0;
		}

		if (gamemode_played == Race) {
			printf("	All turns until the wall moves forward: %u \n", (freq - ((g-1)%freq)));
		} else if (gamemode_played == Sand) {
			printf("	All turns until the squares will fall down: %u \n", (number_of_players - rmv->player_counter)*information_code[3] - ((g-rmv->all_turns_correction-1)%((number_of_players - rmv->player_counter)*information_code[3])));
		}

		w = 3;
		d = 2;
		e = 3;

		if (gamemode_played == Arena) {	//Arena-abilities werden eingesetzt

			for (unsigned int i=1; i<=AOP; i+=1) {
				if (ability[i] == geben) {
					information_code[0] = i;
				}
			}
			if (ability[1] == geben) {
				w = 1;
				d = 0;
				e = 1;
			} else if (ability[2] == geben) {
				w = 2;
				d = 1;
				e = 2;
			} else if (ability[3] == geben) {
				w = 4;
				d = 1;
				e = 4;	//abweichende e-definition
			} else if (ability[AOP] == geben) {
				
				Opague_show_controll (level, Field, Opague_o, m, n, geben, AOP, sfc, number_of_players, gamemode_played, single_option_representives.invisible, Sf_permutations, information_code, Growth_players);
				
				for (unsigned int i=1; i<m-1; i+=1){	//push of electric
					for (unsigned int j=1; j<n-1; j+=1){
						if (Field[0][i][j] == geben) {
							if ((Field[0][i+1][j] != 0)&&(Field[0][i+1][j] != geben)&&((i+2) <= (m-2))) {
								if (Field[0][i+2][j] == 0) {
									set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, sfc, number_of_players, Field, 0, i+2, j, Field[0][i+1][j]);
									set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, sfc, number_of_players, Field, 0, i+1, j, 0);
								}
							}
							if ((Field[0][i-1][j] != 0)&&(Field[0][i-1][j] != geben)&&((i-2) >= 1)) {
								if (Field[0][i-2][j] == 0) {
									set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, sfc, number_of_players, Field, 0, i-2, j, Field[0][i-1][j]);
									set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, sfc, number_of_players, Field, 0, i-1, j, 0);
								}
							}
							if ((Field[0][i][j-1] != 0)&&(Field[0][i][j-1] != geben)&&((j-2) >= 1)) {
								if (Field[0][i][j-2] == 0) {
									set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, sfc, number_of_players, Field, 0, i, j-2, Field[0][i][j-1]);
									set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, sfc, number_of_players, Field, 0, i, j-1, 0);
								}
							}
							if ((Field[0][i][j+1] != 0)&&(Field[0][i][j+1] != geben)&&((j+2) <= (n-2))) {
								if (Field[0][i][j+2] == 0) {
									set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, sfc, number_of_players, Field, 0, i, j+2, Field[0][i][j+1]);
									set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, sfc, number_of_players, Field, 0, i, j+1, 0);
								}
							}
						}
					}
				}
			}
		}	// Done : index, show_field, rmv->var_ == min_1,	start_normal, dies, != 6, hint, new_life, old_dying, ability_used_counter,    übertragen: /  to do:	/	yes!

		if ((gamemode_played == Ulcer)&&(geben != 1)) {
			w = 2;
			d = 1;
			e = 2;
		}

		if (gamemode_played == Arena) {	//light und ultra_light erhalten gekürzte limits.at_all, beim Rest wird der richtige Wert eingesetzt
			if (information_code[0] == 1) {
				limits.at_all = limits.at_all_saver-2;
			} else if (information_code[0] == 2) {
				limits.at_all = limits.at_all_saver-1;
			} else {
				limits.at_all = limits.at_all_saver;
			}
		}

		if (time_matters.ttt != 0) {		//Strafen wegen der Zeit
			if ((pere[geben] != 0)&&(time_matters.warning_system <= 5)&&((pere[geben]+time_matters.warning_system) == 7)) {
				g += 1;
				printf(" \n ");
				printf("	You got a penalty. \n ");
				printf(" \n ");
				pere[geben] = 0;
				continue;
			} else if ((pere[geben] != 0)&&(time_matters.warning_system != 0)&&(((time_matters.warning_system <= 5)&&((pere[geben]+time_matters.warning_system) == 8))||((time_matters.warning_system == 6)&&(pere[geben] == 1)))) {
				old_dying (Field, Field, m, n, d, e, gamemode_played, information_code, geben, evolution.od, w, sfc, Opague_o.field, number_of_players, Roses_o);
				change (Field, level, Sf_permutations, Field, evolution, m, n, gamemode_played, number_of_players, ges, geben, sfc, Opague_o.field, information_code, Growth_players, single_option_representives, Roses_o);  //Change befreit
				g += 1;
				printf(" \n ");
				printf("	You got a penalty. \n ");
				printf(" \n ");
				pere[geben] = 0;
				continue;
			} else if (((time_matters.warning_system <= 5)&&((time_matters.warning_system + pere[geben]) >= 9))||((time_matters.warning_system >= 6)&&((time_matters.warning_system + pere[geben]) >= 8))) {
				printf("	Niederlage: Spieler %u \n ", geben);
				for (unsigned int i=1; i<m-1; i+=1){
					for (unsigned int j=1; j<n-1; j+=1){
						if (Field[0][i][j] == geben) {
							set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, sfc, number_of_players, Field, 0, i, j, 0);
						}
					}
				}
				ges[geben] = 1010*geben;
				rmv->player_counter += 1;
				pere[geben] = 100;
				g += 1;
				continue;
			}
		}

		if (rmv->var_[geben] == 1010*geben) {
			rmv->use_number = cons[geben];
			if (opt == 5) {
				Square_color_interpretation (Growth_players, geben, number_of_players, geben);
				printf("	Player %u ,do you want to keep your number (%u) or do you want to get the next one? \n", geben, cons[geben]);
				set_terminal_color (cNORMAL);
				printf("	Keep the number:  1 \n");
				printf("	Get the next one:	2 \n");
				anything = get_unsigned_numeric_input_with_not_more_than_1_letter ();

				if (anything == 2) {
					rmv->use_number = random_number (num, rmv->use_number, g, rmv->var_, number_);
				} else if (anything != 1) {
					printf("	Well, you keep your number, but next time please take an option i offered. \n\n");
				}
				anything = 0;
			} else if (cards != 0) {
				Square_color_interpretation (Growth_players, geben, number_of_players, geben);
				printf("	Player %u ,do you want to keep your Card (%u) or do you want to get the next one? \n", geben, cons[geben]);
				set_terminal_color (cNORMAL);
				printf("	Keep the number:  1 \n");
				printf("	Get the next one:	2 \n");
				anything = get_unsigned_numeric_input_with_not_more_than_1_letter ();

				if (anything == 2) {
					rmv->use_number = random_number (num, rmv->use_number, g, rmv->var_, number_);
				} else if (anything != 1) {
					printf("	Well, you keep your card, but next time please take an option i offered. \n\n");
				}
				anything = 0;
			}
		}

		if (rmv->var_[Nachfolger(geben, number_of_players)] == 1010*(Nachfolger(geben, number_of_players))){		//geben%number_of_players+1 ist der Nachfolger von geben.
			if (tac != 0) {
				stack_of_[geben][number_[geben]][0] += 1;
				rmv->numbers_of_[geben][number_[geben]][0] -= 1;
			} else if (opt == 5) {
				rmv->use_number = cons[geben];
				rmv->numbers_of_[geben][rmv->use_number][0] -= 1;
			} else if (cards != 0) {
				stack_of_[geben][number_[geben]][0] += 1;
				rmv->numbers_of_[geben][number_[geben]][0] -= 1;
			} else {
				rmv->numbers_of_[geben][number_[geben]][0] -= 1;
			}

		} else if ((cards != 0)&&(rmv->var_[geben] != 1010)) {	//if you thought about ending the game
			stack_of_[geben][rmv->use_number][0] += 1;	//Drawing a card
		}


		if ((tac != 0)&&((stack_of_[geben][1][0]+stack_of_[geben][2][0]+stack_of_[geben][3][0]+stack_of_[geben][4][0]+stack_of_[geben][5][0]+stack_of_[geben][6][0]) == 0)){
			for (unsigned int p=1; p<=6; p+=1){
				stack_of_[geben][p][0] = tac;
			}
		}

		menuoperator = 1;		//Ende der Vorbereitung

		// printf("2. g = %u \n", g);	//test
	
		//#-start
		while (menuoperator != 0) {		//Beginn des Zuges

			if (level[0] == 5) {	//show only one field for each player, if every player is a KI but you want to see what is happening
				level[0] = 2;
			}
			if (gamemode_played != Rain) {
				
				Opague_show_controll (level, Field, Opague_o, m, n, geben, AOP, sfc, number_of_players, gamemode_played, single_option_representives.invisible, Sf_permutations, information_code, Growth_players);
				
			}
			if (level[0] == 2) {
				level[0] = 5;
			}

			if (gamemode_played == Fall) {
				printf("\n");
				printf("	Points player %u:   %u Point(s) \n", geben, rmv->Points[geben]);
			} else if (gamemode_played == Ulcer) {
				printf("\n");
				printf("	Lifes player %u:  %u Life(s) \n", geben, rmv->ulcer_lifes[geben]);
			} else if (gamemode_played == Dynamic) {
				printf("	\n");
				printf("	Geschwindigkeit:  Zeile: %d,  Spalte: %d \n", dynamic_pointer[2], dynamic_pointer[3]);
				printf("	Beschleunigung:   Zeile: %d,  Spalte: %d \n", dynamic_pointer[4], dynamic_pointer[5]);
				printf("	\n");
			} else if (gamemode_played == Quidditch) {
				printf("\n");
				printf("	Points player %u:   %u Points \n", geben, Qs->Points[geben]);
			}

			printf("\n");

			show_whose_turn (gamemode_played, geben, ability, Growth_players, level, number_of_players);

			if ((cards != 0)&&(rmv->var_[Nachfolger(geben, number_of_players)] != 1010*(Nachfolger(geben, number_of_players)))) {
				printf("	You draw a %u. \n\n", rmv->use_number);
			} else if ((cards != 0)&&(rmv->var_[Nachfolger(geben, number_of_players)] == 1010*(Nachfolger(geben, number_of_players)))) {
				printf("	You still draw a %u. \n\n", cons[geben]);
			}

			if ((tac != 0)||(cards != 0)){
				printf("	Your stack of numbers:	\n	1) [%u],  2) [%u],  3) [%u],  \n\n	4) [%u],  5) [%u],  6) [%u], \n", stack_of_[geben][1][0], stack_of_[geben][2][0], stack_of_[geben][3][0], stack_of_[geben][4][0], stack_of_[geben][5][0], stack_of_[geben][6][0]);
				printf("\n");
				printf("\n");
			}

			if (opt == 5){		//random number
				printf("	Your number: %u ", rmv->use_number);
				printf("\n");
				printf("\n");
				//##
			}

			//#-end

			if ((time_matters.ttt != 0)&&(time_saver == 0.0)) {
				time1 = time(NULL);
			}

			if (level[geben] == human) {
				show_options_of_actions (gamemode_played, information_code, geben);

				rmv->var_[geben] = get_unsigned_numeric_input_with_not_more_than_3_letters ();
		
				// printf("Checkpoint: rmv->var_[geben] =  %u\n", rmv->var_[geben]);	//test
		
			} else {
				// rmv->use_number = 5;	//KI testing... warning

				turn_of_KI_random (Qs, Moc_Quaffel, Moc_Schnatz, Moc_Klatscher, &KI_decision, Field, m, n, geben, Opague_o, sfc, Sf_permutations, ges, Growth_players, number_of_players, gamemode_played, information_code, level, limits, single_option_representives, rain, rmv, Roses_o);

				// rmv->var_[geben] = 51;	//KI testing... warning

			}

			if (rmv->var_[geben] == 10){
				if (time_matters.ttt != 0) {
					time3 = time(NULL);
				}

				while (menuoperator != 7) {
					printf("\n");
					printf("\n");
					printf("	About the game: 1 \n	Statistics: 2 \n	The numbers: 3 \n	The limits: 4 \n	Get Hints: 5 \n	Suprise: 6 \n	Quit Menu: 7 \n");
					menuoperator = get_unsigned_numeric_input_with_not_more_than_1_letter();

					if (menuoperator == 1){
						About_the_game (gamemode_played, geben, limits, number_of_players, freq, w, d, e);

					} else if (menuoperator == 2){
						printf("\n");
						printf("	turns at all: %u \n", g);

						show_statistics (number_of_players, gamemode_played, rmv->numbers_of_, rmv->Points, exclude_counter, rmv->ulcer_lifes, ges, pere, ability, time_matters.ttt, Qs);

					} else if (menuoperator == 3){

						show_the_numbers (gamemode_played, w, d, e, geben);

					} else if (menuoperator == 4){
						if ((gamemode_played != Ulcer)&&(gamemode_played != Survive)) {
							printf("	Limit of development:	%u \n", limits.yeni);
							if (gamemode_played != Contact) {
								printf("	Limit in total:		%u \n", limits.at_all);
							}
						}
					} else if (menuoperator == 5){

						get_hints (level, Sf_permutations, gamemode_played, Field, geben, w, d, e, m, n, information_code, Opague_o, Growth_players, AOP, sfc, number_of_players, single_option_representives);

						//show_field (number_of_players, single_option_representives.invisible, level, Sf_permutations, Opague_o.field, hint, m, n, gamemode_played, information_code, geben, Growth_players, 0, sfc);		//teste die destroy-funktion für Spielfelder, done
					} else if (menuoperator == 6){

						if (suprise == 0) {
							for (unsigned int i=1; i<m-1; i+=1){
								for (unsigned int j=1; j<n-1; j+=1){

									set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, sfc, number_of_players, Field, geben, i, j, Field[0][i][j]);

									if (Journey_o.characterization != 0){
										set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, sfc, number_of_players, Journey_o.field, geben, i, j, Journey_o.field[0][i][j]);
									}
								}
							}
							sup_num = rmv->use_number;
						}

						while (menuoperator != 1) {

							printf("	Creator menu.   Change number: 1	Suprise: 2	Suprise undo: 3	Back: 4 \n");
							anything = get_unsigned_numeric_input_with_not_more_than_1_letter ();
							if (anything == 1){
								printf("	number = ? \n");
								rmv->use_number = get_unsigned_numeric_input_with_not_more_than_1_letter();
							} else if (anything == 2){

								printf("\n");
								suprise = get_unsigned_numeric_input_with_not_more_than_2_letters();

								if (suprise == 31){
									for (unsigned int i=2; i<m-2; i+=1){
										for (unsigned int j=1; j<n-1; j+=1){
											if (Field[0][i][j] != 0){
												if (Field[0][i][j] == geben){
													set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, sfc, number_of_players, Field, 0, i, j, Nachfolger(geben, number_of_players));
												} else if (Field[0][i][j] == Nachfolger(geben, number_of_players)){
													set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, sfc, number_of_players, Field, 0, i, j, geben);
												}
											}
										}
									}
								}

								if (suprise == 257642){
									printf("\n");
									printf("	This game and it's C-Code is created and written by Kjell Lewandowski, born 06.03.1998, Germany.\n");
									printf("	Date: 10.10.2017 \n");
									printf("\n");
								}

								if (suprise == 13){
									for (unsigned int i=1; i<m-1; i+=1){
										for (unsigned int j=1; j<n-1; j+=1){
											if (Field[0][i][j] == Nachfolger(geben, number_of_players)){
												set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, sfc, number_of_players, Field, 0, i, j, 0);
											}
											if (i == (m-2)){
												set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, sfc, number_of_players, Field, geben, m-2, j, Nachfolger(geben, number_of_players));
											}
										}
									}
								}

							} else if (anything == 3){
								rmv->use_number = sup_num;
							} else if (anything == 4){
								menuoperator = 1;
							} else {
								printf("	Invalid comment \n");
							}
						}
					}

				}		// menuoperator = 7

				if (level[0] == 5) {
					level[0] = 2;
				}
				if (gamemode_played == Rain) {		//##
					
					Opague_show_controll (level, Field, Opague_o, m, n, geben, AOP, sfc, number_of_players, gamemode_played, single_option_representives.invisible, Sf_permutations, information_code, Growth_players);
				
					printf("\n");

				}
				if (level[0] == 2) {
					level[0] = 5;
				}

				if (time_matters.ttt != 0) {
					time4 = time(NULL);
					time_saver += difftime(time4, time3);
				}
			}		//Menu-end.

			menuoperator = 0;

			if (rmv->var_[geben] == 10) {
				menuoperator = 1;
				rmv->var_[geben] = 5;		//## to avoid the mistake-note by closing the menu
			}

			if (((tac != 0)||(cards != 0))&&(rmv->var_[geben] <= min_1)&&(rmv->var_[geben] > 10)){
				unsigned int tac_controll;	//also used for cards
				tac_controll = 0;
				if (((rmv->var_[geben]%10) > 2)||((rmv->var_[geben]%10) == 0)){
					rmv->var_[geben] = 7;
					menuoperator = 1;
				} else {
					for (unsigned int z=rmv->var_[geben]; z>2; z-=10){
						tac_controll += 1;
					}
					if (stack_of_[geben][tac_controll][0] == 0){
						rmv->var_[geben] = 7;
						menuoperator = 1;
					} else {
						stack_of_[geben][tac_controll][0] -= 1;		//Die tac/cards-Abrechnung
					}
				}
			} else if (((tac != 0)||(cards != 0))&&(rmv->var_[geben] != 100)&&(rmv->var_[geben] != 1010*geben)&&(rmv->var_[geben] != 0)&&(rmv->var_[geben] != 5)) {
				rmv->var_[geben] = 7;
			}
			//tac/cards-mode

			if (opt == 5){
				controll_1 = 10+rmv->use_number;
				controll_2 = 11+rmv->use_number;

				for (unsigned int i=0; i<rmv->use_number-1; i+=1){
					controll_1 += 9;
					controll_2 += 9;
				}

				if (rmv->var_[geben] == 0){
					controll_1 = 0;
					controll_2 = 0;
				}
				if (rmv->var_[geben] == 100){
					controll_1 = 100;
					controll_2 = 100;
				}
				if (rmv->var_[geben] == 1010*geben){
					controll_1 = 1010*geben;
					controll_2 = 1010*geben;
				}
			}

			if (((rmv->var_[geben] > 0)&&(rmv->var_[geben] < 10))||(((opt == 5)&&(rmv->var_[geben] != controll_1))&&((opt == 5)&&(rmv->var_[geben] != controll_2)))){

				if (rmv->var_[geben] != 5) {		//#-start
					printf("	You made a mistake, try again: \n");
					printf("\n");
					printf("\n");
				} else {
					printf("	You closed the menu. \n");
					printf("\n");
					printf("\n");
				}		//#-end

				//enough

				menuoperator = 1;	//menuoperator = 1 : Back to while(menuoperator!=0)
			}

		}     // menuoperator = 0

		suprise = 0;

		if (rmv->var_[geben] == 0){
			printf("	Do you really want to end the game ? \n");
			printf("	Yes: 0		No: 1 \n");
			anything = get_unsigned_numeric_input_with_not_more_than_1_letter ();
			if (anything == 0){
				break;
			} else if (anything == 1){
				anything = 0;
				// rmv->var_[geben] = 1010;
				continue;	//g+=1 is at the end, so there is no need to reduce g
			} else {
				printf("	0 or 1, it is so difficult to understand? \n");
				printf("	Well, it seems I have to end it by myself... \n");
				break;
			}
		} else {

			// printf("Checkpoint: rmv->var_[geben] accepted \n");	//test

			if (rmv->var_[geben] == 100){		//1, 2, 3,... durch "geben" ersetzen, done

				rmv->var_[0] = 1;

				if (gamemode_played == Dynamic) {
					for (unsigned int p=2; p<=5; p+=1) {

						dynamic_pointer[p] = dynamic_pointer_save[Vorganger(geben, number_of_players)][p-2];	//if

					}
				}
				if (cards != 0) {
					stack_of_[geben][rmv->use_number][0] -= 1;
				}

				cons[geben] = rmv->use_number;

				for (unsigned int i=1; i<m-1; i+=1){
					for (unsigned int j=1; j<n-1; j+=1){

						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, sfc, number_of_players, Field, 0, i, j, Field[Vorganger(geben, number_of_players)][i][j]);
						
						if (sfc->Allocation_o.characterization != 0) {
							set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, sfc, number_of_players, sfc->Allocation_o.field, 0, i, j, sfc->Allocation_o.field[Vorganger(geben, number_of_players)+2][i][j]);	//+2 wegen Having_too_muchverschiebung
						}
						
						if (sfc->Partition_o.characterization != 0) {
							set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, sfc, number_of_players, sfc->Partition_o.field, 0, i, j, sfc->Partition_o.field[Vorganger(geben, number_of_players)+2][i][j]);	//+2 wegen Having_too_muchverschiebung
						}
						
						if (Journey_o.characterization != 0){
							set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, sfc, number_of_players, Journey_o.field, 0, i, j, Journey_o.field[Vorganger(geben, number_of_players)][i][j]);
						}

					}
				}

				
				Opague_show_controll (level, Field, Opague_o, m, n, geben, AOP, sfc, number_of_players, gamemode_played, single_option_representives.invisible, Sf_permutations, information_code, Growth_players);
				
				g-=1;
				rmv->var_[geben] = 1010*geben;
				if (gamemode_played == Ulcer) {
					rmv->ulcer_lifes[geben] += 1;
					rmv->ulcer_start[geben] = missing;
				}
				continue;
			} else {

				if (rmv->var_[Nachfolger(geben, number_of_players)] != 1010*(Nachfolger(geben, number_of_players))){

					for (unsigned int i=1; i<m-1; i+=1){
						for (unsigned int j=1; j<n-1; j+=1){
							set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, sfc, number_of_players, Field, geben, i, j, Field[0][i][j]);

							if (sfc->Allocation_o.characterization != 0) {
								set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, sfc, number_of_players, sfc->Allocation_o.field, geben+2, i, j, sfc->Allocation_o.field[0][i][j]);	//geben+2 wegen indexverschiebung
							}

							if (sfc->Partition_o.characterization != 0) {
								set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, sfc, number_of_players, sfc->Partition_o.field, geben+2, i, j, sfc->Partition_o.field[0][i][j]);	//geben+2 wegen indexverschiebung
							}

							if (Journey_o.characterization != 0){
								set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, sfc, number_of_players, Journey_o.field, geben, i, j, Journey_o.field[0][i][j]);
							}
						}
					} //KI testing... warning ?

					if (gamemode_played == Dynamic) {
						for (unsigned int p=2; p<=5; p+=1) {
							dynamic_pointer_save[geben][p-2] = dynamic_pointer[p];
						}
					}
				}

				rmv->var_[0] = 0;

				// printf("3. g = %u \n", g);	//test
	
				if (rmv->var_[geben] < 50){	//KI has [no need] to do this, it has!

					// printf("Checkpoint: rmv->var_[geben]<50 accepted \n");	//test

					if (rmv->var_[geben] == Plus_){
						rmv->numbers_of_[geben][1][0] += 1;
						if (level[geben] == human) {
							Plus (level, Sf_permutations, m, n, geben, Field, limits.at_all, gamemode_played, information_code, number_of_players, Growth_players, Opague_o, sfc, single_option_representives);
						}
					} else if (rmv->var_[geben] == Minus_) {
						rmv->numbers_of_[geben][1][0] += 1;
						if (level[geben] == human) {
							Minus (level, Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Growth_players, Opague_o, sfc, number_of_players, single_option_representives);
						}
					} else if (rmv->var_[geben] == Move_2) {
						rmv->numbers_of_[geben][2][0] += 1;
						if (level[geben] == human) {
							Move (level, Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Growth_players, Opague_o, sfc, number_of_players, single_option_representives);
						}
					} else if (rmv->var_[geben] == Move_4) {
						rmv->numbers_of_[geben][4][0] += 1;
						if (level[geben] == human) {
							Move (level, Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Growth_players, Opague_o, sfc, number_of_players, single_option_representives);
						}
					} else if (rmv->var_[geben] == Change_) {
						rmv->numbers_of_[geben][2][0] += 1;
						if (level[geben] == human) {
							Change (level, Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Growth_players, Opague_o, position, sfc, number_of_players, single_option_representives);
						}
					} else if (rmv->var_[geben] == Destroy_) {
						rmv->numbers_of_[geben][3][0] += 1;
						if (level[geben] == human) {
							Destroy (level, Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Growth_players, Opague_o, sfc, number_of_players, single_option_representives);
						}
					} else if (rmv->var_[geben] == Boost_) {
						rmv->numbers_of_[geben][4][0] += 1;
					} else if (rmv->var_[geben] == Revive_) {
						rmv->numbers_of_[geben][3][0] += 1;
					}
				} else {

					// printf("Checkpoint: rmv->var_[geben]>50 accepted \n");	//test
					// printf("Checkpoint: rmv->var_[geben]>50 (1) \n");	//test

					if (rmv->var_[geben] == new_4_5){rmv->numbers_of_[geben][5][0] += 1; w += 1;}		//w
					// printf("Checkpoint: rmv->var_[geben]>50 (2) \n");	//test
			
					if (rmv->var_[geben] == new_2){rmv->numbers_of_[geben][5][0] += 1; w -= 1;}		//w
					// printf("Checkpoint: rmv->var_[geben]>50 (3) \n");	//test
			
					if (rmv->var_[geben] == max_4){rmv->numbers_of_[geben][6][0] += 1; e += 1;}		//e
					// printf("Checkpoint: rmv->var_[geben]>50 (4) \n");	//test
			
					if (rmv->var_[geben] == min_1){
						// printf("Checkpoint: rmv->var_[geben]>50 (5) \n");	//test
						rmv->numbers_of_[geben][6][0] += 1;
						// printf("Checkpoint: rmv->var_[geben]>50 (6) \n");	//test
						if (d != 0) {
							d -= 1;
							// printf("Checkpoint: rmv->var_[geben]>50 (7) \n");	//test
						} else {
							d = 10;
							// printf("Checkpoint: rmv->var_[geben]>50 (8) \n");	//test
						}
					}		//d
				
					// printf("Checkpoint: rmv->var_[geben]>50 (9) \n");	//test
			
				}
		
				// printf("Checkpoint: functions accepted \n");	//test
		
				if (time_matters.ttt != 0) {
					time2 = time(NULL);		//wirklich die eingabe abwarten, done
					time_warning = ((difftime(time2, time1)) - time_saver);

					///printf("	time_warning: %f \n", time_warning);		//test

					if ((pere[geben] != 0)&&((pere[geben] + time_matters.warning_system) <= 6)) {
						if (pere[geben] == 1) {
							if (time_matters.warning_system <= 2) {
								time_warning += 1.0;
							} else if (time_matters.warning_system == 3) {
								time_warning += 2.0;
							} else if (time_matters.warning_system == 4) {
								time_warning += 3.0;
							} else if (time_matters.warning_system == 5) {
								time_warning += 5.0;
							}
						} else if (pere[geben] == 2) {
							if (time_matters.warning_system == 1) {
								time_warning += 2.0;
							} else if (time_matters.warning_system == 2) {
								time_warning += 3.0;
							} else if (time_matters.warning_system == 3) {
								time_warning += 5.0;
							} else if (time_matters.warning_system == 4) {
								time_warning += 6.0;
							}
						} else if (pere[geben] == 3) {
							if (time_matters.warning_system == 1) {
								time_warning += 3.0;
							} else if (time_matters.warning_system == 2) {
								time_warning += 5.0;
							} else if (time_matters.warning_system == 3) {
								time_warning += 8.0;
							}
						} else if (pere[geben] == 4) {
							if (time_matters.warning_system == 1) {
								time_warning += 4.0;
							} else if (time_matters.warning_system == 2) {
								time_warning += 7.0;
							}
						} else if (pere[geben] == 5) {
							if (time_matters.warning_system == 1) {
								time_warning += 5.0;
							}
						}
					}

					if ((gamemode_played == Hunt)&&(geben == 1)) {	//keep it
						if (time_warning > 10.0) {	//hunted one bonus
							time_warning -= 10.0;
						} else {
							time_warning = 0.0;
						}
					}
					if (time_warning > (1.0*time_matters.ttt)) {
						pere[0] += 1;
						printf("	You took too much time! %f sec more than you should. \n", (time_warning-1.0*time_matters.ttt) );
						printf(" \n");
						for (unsigned int p=16; p>=1; p-=3) {	//index_verschiebung
							if ((time_warning-1.0*time_matters.ttt) > 1.0*(p-1)) {
								pere[geben] = (((p-1)/3) + 1);
								break;
							}
						}
					} else {
						pere[geben] = 0;
					}
					//printf("	pere[%u]: %u \n", geben, pere[geben] );	//test
				}
		
				// printf("4. g = %u \n", g);	//test
				
				for (unsigned int i=1; i<=m-2; i++) {	//update of scf->Partition_o.field[1] 
					for (unsigned int j=1; j<=n-2; j++) {
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, sfc, number_of_players, sfc->Partition_o.field, 1, i, j, sfc->Partition_o.field[0][i][j]);
					}
				}
				
				//development_start
		
				// printf("Checkpoint: development_start \n");	//test
		
				basic_development (Field, Field, m, n, geben, Opague_o.field, sfc, Sf_permutations, ges, Growth_players, number_of_players, gamemode_played, information_code, level, w, d, e, rmv->var_[geben], evolution, &num, &g, Journey_o, limits, single_option_representives, Roses_o, position, &KI_decision, rain, evet);

				// printf("Checkpoint: development_end \n");	//test
		
				// printf("5. g = %u \n", g);	//test
	
				// development_end
		
				// printf("Checkpoint: realize_modifications_start \n");	//test
		
				realize_modifications (Qs, Moc_Schnatz, Moc_Quaffel, Moc_Klatscher, Field, Field, Opague_o, sfc, Sf_permutations, ges, &g, m, n, geben, number_of_players, gamemode_played, level, information_code, Growth_players, Journey_o, rain, single_option_representives, rmv, limits, evet);
				
				// printf("Checkpoint: realize_modifications_end \n");	//test
		
				// printf("6. g = %u \n", g);	//test
	
				if (rmv->var_[Nachfolger(geben, number_of_players)] != 1010*(Nachfolger(geben, number_of_players))) {
					cons[geben] = rmv->use_number;
				}

				rmv->use_number = random_number (num, rmv->use_number, g, rmv->var_, number_);

				if ((opt != 5)&&(rmv->var_[geben] <= min_1)){
					controll_1 = 0;
					for (unsigned int z=rmv->var_[geben]; z>2; z-=10){
						controll_1 += 1;
					}
					number_[geben] = controll_1;
					controll_1 = 0;
				}
			}
		}

		//normal_end
		// printf("Checkpoint: normal_end \n");	//test
		// printf("7.g = %u \n", g);	//test
		
		//end of sections of geben, but geben is still active	//try to put the following section befor this, transfer the undone of special action under "Go back" to the main if. go on
		if (level[0] <= 2) {
			printf("\n");
		}

		// printf("	Existing Fields: %d \n ", Spielfeld_counter);	//test
		// printf("	Existing Vektors: %d \n ", Vektor_counter);	//test
		// printf("	\n ");
		// printf("	#line 4k, geben=%u \n", geben);	//test

		if (gamemode_played == Ulcer) {
			if (rmv->ulcer_start[0] == 100) {
				for (unsigned int p=1; p<=number_of_players; p+=1) {
					if (rmv->out_counter[p] == 0) {
						rmv->out_counter[p] = 1;
						break;
					}
				}
			}
			rmv->ulcer_start[0] = 0;
			printf("	Who`s still alive? \n");

			for (unsigned int p=1; p<=number_of_players; p+=1) {
				for (unsigned int r=1; r<=number_of_players; r+=1) {
					if (rmv->out_counter[r] == p) {
						rmv->ulcer_lifes[p] = 1000;
					break;
					}
				}

				if (rmv->ulcer_lifes[p] != 1000) {
					printf("	Spieler %u \n", p);
				} else {
					rmv->ulcer_lifes[p] = 0;
				}
			}

			printf("\n");
			printf("\n");

			printf("	Top Ulcer: \n");
			for (unsigned int p=1; p<=number_of_players; p+=1) {
				if (rmv->out_counter[1] == 0) {
					printf("		All were bad. \n");
					break;
				}

				if (rmv->out_counter[p] != 0) {
					if (rmv->out_counter[p] < number_of_players) {	//It is < and not <=, because the first one has not the aim to kill the last player
					printf("		No.%u: %u \n", p-rmv->ulcer_start[0], rmv->out_counter[p]+1);
					} else {
						rmv->ulcer_start[0] = 1;
					}
				}
			}
			printf("\n");
			printf("\n");

			printf("	Lifes: \n");
			for (unsigned int p=1; p<=number_of_players; p+=1) {
				printf("		Spieler %u: %u life(s) left.\n", p, rmv->ulcer_lifes[p]);
			}
			printf("\n");
			printf("\n");
		}
		
		if (g == 0) {
			break;
		} else {
			g += 1;
		}
	}

	level[0] = 0;

	printf(" \n");
	printf("	Show statistics:	yes: 1		no: 0 \n");
	anything = get_unsigned_numeric_input_with_not_more_than_1_letter ();
	if (anything == 1){
		printf("	\n");
		show_statistics (number_of_players, gamemode_played, rmv->numbers_of_, rmv->Points, exclude_counter, rmv->ulcer_lifes, ges, pere, ability, time_matters.ttt, Qs);

	}

	if (gamemode_played == Hunt) {
		for (unsigned int p=0; p<=3; p+=1) {
			information_code[p] = 1;
		}
	}

	printf("\n");
	printf("	Round: %u \n", rmv->round_counter);
	printf("\n");

	show_field (number_of_players, single_option_representives.invisible, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, sfc);

	printf("	\n ");
	printf("	\n ");
	printf("	Do you want to play another match?	\n		Yes: 1		No:  0 ");
	*playtime = get_unsigned_numeric_input_with_not_more_than_1_letter ();
	if (*playtime == 0) {
		printf("				     ___ \n ");
	} else if (*playtime > 1) {
		printf("	it was a -1-, wasn't it?");
	}
	if (*playtime >= 1) {
		*playtime = 10;

		printf(" \n ");
		printf(" \n ");

		printf("	Do you want to play a revanche? \n ");
		printf("	yes: 1		No: 0 \n ");
		same[0] = get_unsigned_numeric_input_with_not_more_than_1_letter ();

		// printf("	same[0] = %u \n", same[0]);	//test

		if (same[0] > 1) {
			printf("	it was a -1-, wasn't it?");
			same[0] = 1;

		}
		if (same[0] == 1) {
			same[23] = rmv->use_number;
		}
		printf("	\n ");
		printf("	\n ");
		printf("	\n ");
		printf("	\n ");

	}

	// Aufräumphase !!!

	#ifdef Aufraeumphase_mistake_search
		printf("	Existing Fields: %d \n ", Spielfeld_counter);	//test
		printf("	Existing Vektors: %d \n ", Vektor_counter);	//test
	#endif
	
	int_Vektor_Destroy (dynamic_pointer);
	
	#ifdef Aufraeumphase_mistake_search
		printf("	Existing Fields: %d \n ", Spielfeld_counter);	//test
		printf("	Existing Vektors: %d \n ", Vektor_counter);	//test
		printf("	\n ");
		printf("	#line 3k, 1\n");	//test
		scanf("%u", &pause);	//test
	#endif
	
	unsigned_int_Vektor_Destroy (Points);
	unsigned_int_Vektor_Destroy (rmv->Points);
	
	// unsigned_int_2dim_Vektor_Destroy (Duell_specials->list_of_all_abilities, reloader+1);
	
	#ifdef Aufraeumphase_mistake_search
		printf("	Existing Fields: %d \n ", Spielfeld_counter);	//test
		printf("	Existing Vektors: %d \n ", Vektor_counter);	//test
		printf("	\n ");
		printf("	#line 3k, 2\n");	//test
		scanf("%u", &pause);	//test
	#endif

	int_2dim_Vektor_Destroy (dynamic_pointer_save, number_of_players+1);
	
	#ifdef Aufraeumphase_mistake_search
		printf("	Existing Fields: %d \n ", Spielfeld_counter);	//test
		printf("	Existing Vektors: %d \n ", Vektor_counter);	//test
		printf("	\n ");
		printf("	#line 3k, 3\n");	//test
		scanf("%u", &pause);	//test
	#endif

	unsigned_int_Vektor_Destroy (position);

	#ifdef Aufraeumphase_mistake_search
		printf("	Existing Fields: %d \n ", Spielfeld_counter);	//test
		printf("	Existing Vektors: %d \n ", Vektor_counter);	//test
		printf("	\n ");
		printf("	#line 3k, 4\n");	//test
		scanf("%u", &pause);	//test
	#endif

	Spielfeld_Destroy (Field, m, number_of_players);

	#ifdef Aufraeumphase_mistake_search
		printf("	Existing Fields: %d \n ", Spielfeld_counter);	//test
		printf("	Existing Vektors: %d \n ", Vektor_counter);	//test
		printf("	\n ");
		printf("	#line 3k, 5\n");	//test
		scanf("%u", &pause);	//test
	#endif

	Spielfeld_Destroy (evolution.od, m, number_of_players);

	#ifdef Aufraeumphase_mistake_search
		printf("	Existing Fields: %d \n ", Spielfeld_counter);	//test
		printf("	Existing Vektors: %d \n ", Vektor_counter);	//test
		printf("	\n ");
		printf("	#line 3k, 6\n");	//test
		scanf("%u", &pause);	//test
	#endif

	Spielfeld_Destroy (evolution.nl, m, number_of_players);

	#ifdef Aufraeumphase_mistake_search
		printf("	Existing Fields: %d \n ", Spielfeld_counter);	//test
		printf("	Existing Vektors: %d \n ", Vektor_counter);	//test
		printf("	\n ");
		printf("	#line 3k, 7\n");	//test
		scanf("%u", &pause);	//test
	#endif

	Spielfeld_Destroy (Opague_o.field, m, 0);

	#ifdef Aufraeumphase_mistake_search
		printf("	Existing Fields: %d \n ", Spielfeld_counter);	//test
		printf("	Existing Vektors: %d \n ", Vektor_counter);	//test
		printf("	\n ");
		printf("	#line 3k, 8\n");	//test
		scanf("%u", &pause);	//test
	#endif

	Spielfeld_Destroy (numbers_of_, 7, number_of_players);
	Spielfeld_Destroy (rmv->numbers_of_, 7, number_of_players);
	
	#ifdef Aufraeumphase_mistake_search
		printf("	Existing Fields: %d \n ", Spielfeld_counter);	//test
		printf("	Existing Vektors: %d \n ", Vektor_counter);	//test
		printf("	\n ");
		printf("	#line 3k, 9\n");	//test
		scanf("%u", &pause);	//test
	#endif

	Spielfeld_Destroy (stack_of_, 7, number_of_players);
	// Spielfeld_Destroy (Duell_specials->list_of_taken_abilities, Duell_specials->number_of_abilities, number_of_players);
	
	#ifdef Aufraeumphase_mistake_search
		printf("	Existing Fields: %d \n ", Spielfeld_counter);	//test
		printf("	Existing Vektors: %d \n ", Vektor_counter);	//test
		printf("	\n ");
		printf("	#line 3k, 10\n");	//test
		scanf("%u", &pause);	//test
	#endif

	Spielfeld_Destroy (Journey_o.field, m, number_of_players);

	#ifdef Aufraeumphase_mistake_search
		printf("	Existing Fields: %d \n ", Spielfeld_counter);	//test
		printf("	Existing Vektors: %d \n ", Vektor_counter);	//test
		printf("	\n ");
		printf("	#line 3k, 11\n");	//test
		scanf("%u", &pause);	//test
	#endif

	Spielfeld_Destroy (sfc->Allocation_o.field, m, number_of_players+2);
	Spielfeld_Destroy (sfc->Partition_o.field, m, number_of_players+2);

	#ifdef Aufraeumphase_mistake_search
		printf("	Existing Fields: %d \n ", Spielfeld_counter);	//test
		printf("	Existing Vektors: %d \n ", Vektor_counter);	//test
		printf("	\n ");
		printf("	#line 3k, 12\n");	//test
		scanf("%u", &pause);	//test
	#endif

	Spielfeld_Destroy (Sf_permutations, m, 0);
	Spielfeld_Destroy (Roses_o.field, m, 0);
	
	#ifdef Aufraeumphase_mistake_search
		printf("	Existing Fields: %d \n ", Spielfeld_counter);	//test
		printf("	Existing Vektors: %d \n ", Vektor_counter);	//test
		printf("	\n ");
		printf("	#line 3k, 13\n");	//test
		scanf("%u", &pause);	//test
	#endif
	
	if (rmv->Collector_of_permutation.permutation_number_b == 0) {
		rmv->Collector_of_permutation.amount_of_permutation_number_c = 1;
		rmv->Collector_of_permutation.permutation_number_c = 1;
	}
	Spielfeld_Destroy (rmv->Collector_of_permutation.areas_c, rmv->Collector_of_permutation.permutation_number_c, rmv->Collector_of_permutation.amount_of_permutation_number_c-1);
	if (rmv->Collector_of_permutation.permutation_number_b == 0) {
		rmv->Collector_of_permutation.amount_of_permutation_number_c = 0;
		rmv->Collector_of_permutation.permutation_number_c = 0;
	}

	#ifdef Aufraeumphase_mistake_search
		printf("	Existing Fields: %d \n ", Spielfeld_counter);	//test
		printf("	Existing Vektors: %d \n ", Vektor_counter);	//test
		printf("	\n ");
		printf("	#line 3k, 14\n");	//test
		scanf("%u", &pause);	//test
	#endif

	if (rmv->Collector_of_permutation.permutation_number_c == 0) {
		rmv->Collector_of_permutation.amount_of_permutation_number_b = 1;
		rmv->Collector_of_permutation.permutation_number_b = 1;
	}
	Spielfeld_Destroy (rmv->Collector_of_permutation.areas_b, rmv->Collector_of_permutation.permutation_number_b, rmv->Collector_of_permutation.amount_of_permutation_number_b-1);
	if (rmv->Collector_of_permutation.permutation_number_c == 0) {
		rmv->Collector_of_permutation.amount_of_permutation_number_b = 0;
		rmv->Collector_of_permutation.permutation_number_b = 0;
	}
	
	#ifdef Aufraeumphase_mistake_search
		printf("	Existing Fields: %d \n ", Spielfeld_counter);	//test
		printf("	Existing Vektors: %d \n ", Vektor_counter);	//test
		printf("	\n ");
		printf("	#line 3k, 15\n");	//test
		scanf("%u", &pause);	//test
	#endif

	if (rmv->Collector_of_permutation.permutation_number_b == 0) {
		rmv->Collector_of_permutation.permutation_number_c = 1;
	}
	unsigned_int_2dim_Vektor_Destroy (rmv->Collector_of_permutation.sigmas_c, Fakultaet(rmv->Collector_of_permutation.permutation_number_c - 1));
	if (rmv->Collector_of_permutation.permutation_number_b == 0) {
		rmv->Collector_of_permutation.permutation_number_c = 0;
	}

	#ifdef Aufraeumphase_mistake_search
		printf("	Existing Fields: %d \n ", Spielfeld_counter);	//test
		printf("	Existing Vektors: %d \n ", Vektor_counter);	//test
		printf("	\n ");
		printf("	#line 3k, 15.1\n");	//test
		scanf("%u", &pause);	//test
	#endif

	if (rmv->Collector_of_permutation.permutation_number_c == 0) {
		rmv->Collector_of_permutation.permutation_number_b = 1;
	}
	unsigned_int_2dim_Vektor_Destroy (rmv->Collector_of_permutation.sigmas_b, Fakultaet(rmv->Collector_of_permutation.permutation_number_b - 1));
	if (rmv->Collector_of_permutation.permutation_number_c == 0) {
		rmv->Collector_of_permutation.permutation_number_b = 0;
	}

	#ifdef Aufraeumphase_mistake_search
		printf("	Existing Fields: %d \n ", Spielfeld_counter);	//test
		printf("	Existing Vektors: %d \n ", Vektor_counter);	//test
		printf("	\n ");
		printf("	#line 3k, 15.2\n");	//test
		scanf("%u", &pause);	//test
	#endif

	unsigned_int_Vektor_Destroy (level);

	#ifdef Aufraeumphase_mistake_search
		printf("	Existing Fields: %d \n ", Spielfeld_counter);	//test
		printf("	Existing Vektors: %d \n ", Vektor_counter);	//test
		printf("	\n ");
		printf("	#line 3k, 16\n");	//test
		scanf("%u", &pause);	//test
	#endif

	unsigned_int_Vektor_Destroy (rmv->win_condition);

	#ifdef Aufraeumphase_mistake_search
		printf("	Existing Fields: %d \n ", Spielfeld_counter);	//test
		printf("	Existing Vektors: %d \n ", Vektor_counter);	//test
		printf("	\n ");
		printf("	#line 3k, 17\n");	//test
		scanf("%u", &pause);	//test
	#endif

	unsigned_int_Vektor_Destroy (rmv->var_);

	#ifdef Aufraeumphase_mistake_search
		printf("	Existing Fields: %d \n ", Spielfeld_counter);	//test
		printf("	Existing Vektors: %d \n ", Vektor_counter);	//test
		printf("	\n ");
		printf("	#line 3k, 18\n");	//test
		scanf("%u", &pause);	//test
	#endif

	unsigned_int_Vektor_Destroy (rmv->ulcer_start);

	#ifdef Aufraeumphase_mistake_search
		printf("	Existing Fields: %d \n ", Spielfeld_counter);	//test
		printf("	Existing Vektors: %d \n ", Vektor_counter);	//test
		printf("	\n ");
		printf("	#line 3k, 19\n");	//test
		scanf("%u", &pause);	//test
	#endif

	unsigned_int_Vektor_Destroy (rmv->ulcer_lifes);

	#ifdef Aufraeumphase_mistake_search
		printf("	Existing Fields: %d \n ", Spielfeld_counter);	//test
		printf("	Existing Vektors: %d \n ", Vektor_counter);	//test
		printf("	\n ");
		printf("	#line 3k, 20\n");	//test
		scanf("%u", &pause);	//test
	#endif

	unsigned_int_Vektor_Destroy (rmv->out_counter);

	#ifdef Aufraeumphase_mistake_search
		printf("	Existing Fields: %d \n ", Spielfeld_counter);	//test
		printf("	Existing Vektors: %d \n ", Vektor_counter);	//test
		printf("	\n ");
		printf("	#line 3k, 21\n");	//test
		scanf("%u", &pause);	//test
	#endif

	unsigned_int_Vektor_Destroy (rmv->same);

	#ifdef Aufraeumphase_mistake_search
		printf("	Existing Fields: %d \n ", Spielfeld_counter);	//test
		printf("	Existing Vektors: %d \n ", Vektor_counter);	//test
		printf("	\n ");
		printf("	#line 3k, 22\n");	//test
		scanf("%u", &pause);	//test
	#endif

	Realize_modifications_variables_Vektor_Destroy (rmv);
	Special_Fields_Collector_Vektor_Destroy (sfc);

	#ifdef Aufraeumphase_mistake_search
		printf("	Existing Fields: %d \n ", Spielfeld_counter);	//test
		printf("	Existing Vektors: %d \n ", Vektor_counter);	//test
		printf("	\n ");
		printf("	#line 3k, 22.1\n");	//test
		scanf("%u", &pause);	//test
	#endif

	Moveable_objects_condition_Vektor_Destroy (Moc_Klatscher);
	Moveable_objects_condition_Vektor_Destroy (Moc_Quaffel);
	Moveable_objects_condition_Vektor_Destroy (Moc_Schnatz);
	
	// free(Duell_specials);
	// Duell_specials = NULL;
	
	#ifdef Aufraeumphase_mistake_search
		printf("	Existing Fields: %d \n ", Spielfeld_counter);	//test
		printf("	Existing Vektors: %d \n ", Vektor_counter);	//test
		printf("	\n ");
		printf("	#line 3k, 23\n");	//test
		scanf("%u", &pause);	//test
	#endif


}

void get_hints (unsigned int* level, Spielfeld Sf_permutations, unsigned int gamemode_played, Spielfeld Field, unsigned int geben, unsigned int w, unsigned int d, unsigned int e, unsigned int m, unsigned int n, unsigned int* information_code, Special_Fields Opague_o, Growth_Player* Growth_players, unsigned int AOP, Special_Fields_Collector* sfc, unsigned int number_of_players, Single_option_representives single_option_representives) {

	Spielfeld hint;
	unsigned int b, a, menuoperator;
	hint = Spielfeld_Create (m, n, 0);

	b = 0;
	a = 0;
	menuoperator = 0;

	for (unsigned int i=1; i<(m-1); i+=1){
		for (unsigned int j=1; j<(n-1); j+=1){
			if (Field[0][i][j] == geben){
				set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, sfc, number_of_players, hint, 0, i, j, geben);
			} else if (Field[0][i][j] != 0){
				set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, sfc, number_of_players, hint, 0, i, j, bir_sey);
			}
		}
	}

	printf("	New: 1 \n	Dying: 2 \n	Both: 3 \n");
	menuoperator = get_unsigned_numeric_input_with_not_more_than_1_letter ();

	if ((menuoperator == 2)||(menuoperator == 3)){
		for (unsigned int i=1; i<(m-1); i+=1){
			for (unsigned int j=1; j<(n-1); j+=1){
				if (Field[0][i][j] == geben){
					a = 0;
					for (unsigned int h=(i-1); h<=(i+1); h+=1){
						for (unsigned int k=(j-1); k<=(j+1); k+=1){
							if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
								if (Field[0][h][k] == geben){
									a += 1;
								}
							}
						}
					}
					if ((a > e+1) || (a <= d)){
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, sfc, number_of_players, hint, 0, i, j, oeluem);
					}
				}
			}
		}
	}

	if ((menuoperator == 1)||(menuoperator == 3)){
		for (unsigned int i=1; i<(m-1); i+=1){
			for (unsigned int j=1; j<(n-1); j+=1){
				if (Field[0][i][j] == 0){
					b = 0;
					for (unsigned int h=(i-1); h<=(i+1); h+=1){
						for (unsigned int k=(j-1); k<=(j+1); k+=1){
							if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
								if (Field[0][h][k] == geben){
									b += 1;
								}
							}
						}
					}
					if (b == w){
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, sfc, number_of_players, hint, 0, i, j, dogum);
					}
				}
			}
		}
	}

	Opague_show_controll (level, Field, Opague_o, m, n, geben, AOP, sfc, number_of_players, gamemode_played, single_option_representives.invisible, Sf_permutations, information_code, Growth_players);
	
	Spielfeld_Destroy (hint, m, 0);

}

void About_the_game (unsigned int gamemode_played, unsigned int geben, Limits limits, unsigned int number_of_players, unsigned int freq, unsigned int w, unsigned int d, unsigned int e) {	//checklist

	if (gamemode_played == Classic) {
		printf("	How to win?   Own a square on your last line or force your opponents to lose all his/her ones.\n");
	} else if (gamemode_played == Collect) {
		printf("	How to win?   Be at 2 of the 3 targets with three of your squares near-by.\n");
	} else if (gamemode_played == Contact) {
		printf("	How to win?   Take over all your opponents' squares by winning Contact-battles.\n");
		printf("	Contact-battles?  All near-by squares in a row with the Contact-square build a chain, beat your opponents in the length.\n");
	} else if (gamemode_played == Fall) {
		printf("	How to win?   Get more points than your opponents.\n");
		printf("	Note:	Touch the #-square in the near-by to move it to the opposite side of touch. \n");
	} else if ((gamemode_played == Fight)||(gamemode_played == Duell)) {
		printf("	How to win?   Force your opponents to lose all his/her squares.\n");
	} else if (gamemode_played == Hunt) {
		if (geben == 1) {
			printf("	How to win?   Protect your heart-block in a way that no enemy can touch it.\n");
		} else {
			printf("	How to win?   Touch the heart-block of the hunted one before it disappears.\n");
		}
	} else if (gamemode_played == Race) {
		printf("	How to win?   Reach the end of the field or force your opponents to lose all his/her ones.\n");
		printf("	Note:	Every %u turn(s) in total the #-line will go ahead and destroys everything in it's way.\n Also you are not allowed to cross the mid-line. \n", freq);
	} else if (gamemode_played == Rain) {
		printf("	How to win?   Reach [1][7]");
		for (unsigned int p=2; p<=number_of_players; p++) {
			printf(" or [1][%u]", (p-1)*7);
		}
		printf(" of the field or force your opponents to lose all his/her squares.\n");
		printf("	Note:	Falling down the #-squares will push, destroy, explode, or teleport, transform into yours by contact. \n");
	} else if ((gamemode_played == Arena)||(gamemode_played == Ulcer)) {	//10
		printf("	How to win?   Force your opponents to lose all his/her squares while keeping yours alive by using your special abilities.\n");
	} else if (gamemode_played == Dynamic) {
		printf("	How to win?   Push the ball towards your opponent's side.\n");
	} else if (gamemode_played == Survive) {
		printf("	How to win?   Stay alive by avoiding traps, waves and bombs.\n");
	} else if (gamemode_played == Sand) {
		printf("	How to win?   Reach the topline, your squares keep falling.\n");
	} else if (gamemode_played == Quidditch) {
		printf("	How to win?   Get more points as your opponent. Every goal with a Quaffel worths 10 points, catching the Schnatz gives you 150 points and ends the game.\n");
		printf("	Note:	Teammembers can move through changing position with one of your squares in its reach.\n	In the Near-by of objects, no living square is going to die.\n	In the Near-by of a Jaeger/Hueter the Quaffel is possessed and follows the movements of it's owner or can be thrown.\n	Passing this area the Quaffel stops during it's throw.\n \n If a Sucher flys through the Schnatz, it is caught.\n \n	If a Klatscher hits a target, the position of the target will change.\n ");
	}
	printf("	Surrounding:	The 8 squares around another, at the edge 5, in the corners 3, are called #surrounding. \n");
	printf("	near-by:	The 4 squares around another, at the edge 3, in the corners 2, are called #near-by. \n");
	printf("	Standard actions:	(After your choice of number and not influencing each other) \n	-Development:	If it is your turn and a free square has exactly %u of yours surrounding it, you will own it.\n", w);
	printf("	-Losses:  If it is your turn and a square of yours is surrounded by less than %u or more than %u of yours,\n			it will be set free.\n", d, e);	//10
	if ((gamemode_played == Hunt)&&(geben == 1)) {	//If geben == 1
		printf("	Limits:   Your development is limited by %u per round, your units in total by %u per round. \n", (limits.yeni+(number_of_players-3)), (limits.at_all+(2*(number_of_players-3))));
	} else if ((gamemode_played == Ulcer)||(gamemode_played == Survive)) {
		printf("	Limits:   This gamemode is unlimited. \n");
	} else if (gamemode_played == Contact) {
		printf("	Limits:   Your development is limited by %u per round. \n", limits.yeni);
	} else {
		printf("	Limits:   Your development is limited by %u per round, your units in total by %u per round. \n", limits.yeni, limits.at_all);
	}

}

void Time_for_a_Tutorial (unsigned int AOP, unsigned int* level, unsigned int* information_code, unsigned int* position, Growth_Player* Growth_players) {

	unsigned int m, n, w, d, e, geben, number_of_players, input, gamemode_played, rain, g;
	Limits limits;	//just a copy
	unsigned int ges[AOP+1];
	unsigned int* KI_decision;
	Spielfeld Test_field;
	Special_Fields Test_special_fields;
	Special_Fields_Collector* Test_sfc;
	Single_option_representives test_single_options;
	Evolution evolution;
	Num_num num;

	w = 3;
	d = 2;
	e = 3;
	m = 10;
	n = 10;
	geben = 1;
	number_of_players = 2;
	input = 0;
	gamemode_played = Tutorial;
	limits.at_all = 100;
	limits.yeni = 100;
	rain = 0;
	num.bir = 0;
	num.iki = 0;
	num.uec = 0;
	g = 0;
	Test_special_fields.characterization = 0;
	test_single_options.undead_duration = 0;
	test_single_options.inverted = 0;
	test_single_options.addition = 0;
	test_single_options.intensity_loss_per_line_multiplication = 0;
	
	KI_decision = unsigned_int_Vektor_Create (1);
	Test_field = Spielfeld_Create (m, n, 1);
	evolution.nl = Spielfeld_Create (m, n, number_of_players);
	evolution.od = Spielfeld_Create (m, n, number_of_players);
	Test_special_fields.field = Spielfeld_Create (m, n, number_of_players+2);
	Test_sfc = Special_Fields_Collector_Vektor_Create (1);
	
	for (unsigned int p=0; p<=AOP; p++) {
		ges[p] = 1;
	}

	start_normal (Test_field, m, n, gamemode_played, number_of_players, geben, Test_field, Test_sfc, 0);
	synchronisation_Test_field (Test_field, m, n, 1, 0);

	input = 1;
	while (input != 0) {
		printf("	At first you need to type a zero (0) and click 'Enter' to get to the next step of the Tutorial. The signal for doing this is '?0?' at the end of the text.	?0?\n");
		input = get_unsigned_numeric_input_with_not_more_than_1_letter ();
		printf(" \n");
	}

	input = 1;
	while (input != 0) {
		printf("	The game is played in rounds on a field of squares. A square can be owned by a player or be dead. At the beginning of each game you get a couple of squares you own.	?0?\n");
		input = get_unsigned_numeric_input_with_not_more_than_1_letter ();
		printf(" \n");
	}

	input = 1;
	while (input != 0) {
		printf("	If it is your turn, you can improve the situation of your squares by using actions. \n	Normally you can choose between two options, but in this Tutorial we only learn what these options can do.	?0?\n");
		input = get_unsigned_numeric_input_with_not_more_than_1_letter ();
		printf(" \n");
	}

	input = 1;
	while (input != 0) {
		printf("	After making a decision, your organism of squares will evolve in the following way: Every dead squares with exactly 3 of your squares in its surrounding of 8 squares will be owned by you. \n	Every square of yours having less than 2 or more than 3 own squares in its surrounding will turn into a dead square. \n	There are no effects between the single steps of evolving. \n	Let's have a look on the field we are working with...	?0?\n");
		input = get_unsigned_numeric_input_with_not_more_than_1_letter ();
		printf(" \n");
	}

	show_field (number_of_players, 0, level, Test_field, Test_field, Test_field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Test_sfc);

	input = 1;
	while (input != 0) {
		printf("	If you get asked for the position of a square you are interacting with, you write at first the line (yy) and than the other component of its position (xx). \n	If a part of the position is just a single letter, than you write a zero before the letter. \n	After that you click 'Enter'. \n	For example the squares of player 2 would be called 0401, 0402, 0501, 0502.	?0?\n");
		input = get_unsigned_numeric_input_with_not_more_than_1_letter ();
		printf(" \n");
	}

	input = 1;
	while (input != 0) {
		printf("	Well, now you are prepared for a match. The word before every new comment is the name of the action you will use.	?0?\n");
		input = get_unsigned_numeric_input_with_not_more_than_1_letter ();
		printf(" \n");
	}

	input = 1;
	while (input != 0) {
		show_field (number_of_players, 0, level, Test_field, Test_field, Test_field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Test_sfc);
		printf("	Plus: Set a square on 0405.\n");

		Plus (level, Test_field, m, n, geben, Test_field, limits.at_all, gamemode_played, information_code, number_of_players, Growth_players, Test_special_fields, Test_sfc, test_single_options);

		if (Test_field[0][4][5] != geben) {
			input = 1;
			synchronisation_Test_field (Test_field, m, n, 0, 1);
		} else {
			input = 0;
		}
	}
	basic_development (Test_field, Test_field, m, n, geben, Test_field, Test_sfc, Test_field, ges, Growth_players, number_of_players, gamemode_played, information_code, level, w, d, e, Plus_, evolution, &num, &g, Test_special_fields, limits, test_single_options, Test_special_fields, position, KI_decision, rain, hayir);
	synchronisation_Test_field (Test_field, m, n, 1, 0);

	input = 1;
	while (input != 0) {
		show_field (number_of_players, 0, level, Test_field, Test_field, Test_field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Test_sfc);
		printf("	Minus: Delete your square on 0605.\n");

		Minus (level, Test_field, m, n, geben, Test_field, gamemode_played, information_code, Growth_players, Test_special_fields, Test_sfc, number_of_players, test_single_options);

		if (Test_field[0][6][5] != 0) {
			input = 1;
			synchronisation_Test_field (Test_field, m, n, 0, 1);
		} else {
			input = 0;
		}
	}
	basic_development (Test_field, Test_field, m, n, geben, Test_field, Test_sfc, Test_field, ges, Growth_players, number_of_players, gamemode_played, information_code, level, w, d, e, Minus_, evolution, &num, &g, Test_special_fields, limits, test_single_options, Test_special_fields, position, KI_decision, rain, hayir);
	synchronisation_Test_field (Test_field, m, n, 1, 0);

	input = 1;
	while (input != 0) {
		show_field (number_of_players, 0, level, Test_field, Test_field, Test_field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Test_sfc);
		printf("	Move: Move your square on 0605 to 0604.\n");

		Move (level, Test_field, m, n, geben, Test_field, gamemode_played, information_code, Growth_players, Test_special_fields, Test_sfc, number_of_players, test_single_options);

		if ((Test_field[0][6][5] != 0)||(Test_field[0][6][4] != geben)) {
			input = 1;
			synchronisation_Test_field (Test_field, m, n, 0, 1);
		} else {
			input = 0;
		}
	}
	basic_development (Test_field, Test_field, m, n, geben, Test_field, Test_sfc, Test_field, ges, Growth_players, number_of_players, gamemode_played, information_code, level, w, d, e, Move_2, evolution, &num, &g, Test_special_fields, limits, test_single_options, Test_special_fields, position, KI_decision, rain, hayir);
	synchronisation_Test_field (Test_field, m, n, 1, 0);

	input = 1;
	while (input != 0) {
		show_field (number_of_players, 0, level, Test_field, Test_field, Test_field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Test_sfc);
		printf("	Change: Change your square on 0503 with the square of the enemy on 0502.\n");

		Change (level, Test_field, m, n, geben, Test_field, gamemode_played, information_code, Growth_players, Test_special_fields, position, Test_sfc, number_of_players, test_single_options);

		if ((Test_field[0][5][2] != geben)||(Test_field[0][5][3] != 2)) {
			input = 1;
			synchronisation_Test_field (Test_field, m, n, 0, 1);
		} else {
			input = 0;
		}
	}
	basic_development (Test_field, Test_field, m, n, geben, Test_field, Test_sfc, Test_field, ges, Growth_players, number_of_players, gamemode_played, information_code, level, w, d, e, Change_, evolution, &num, &g, Test_special_fields, limits, test_single_options, Test_special_fields, position, KI_decision, rain, hayir);
	synchronisation_Test_field (Test_field, m, n, 1, 0);

	input = 1;
	while (input != 0) {
		show_field (number_of_players, 0, level, Test_field, Test_field, Test_field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Test_sfc);
		printf("	Destroy: Destroy the square of the enemy on 0503.\n");

		Destroy (level, Test_field, m, n, geben, Test_field, gamemode_played, information_code, Growth_players, Test_special_fields, Test_sfc, number_of_players, test_single_options);

		if (Test_field[0][5][3] != 0) {
			input = 1;
			synchronisation_Test_field (Test_field, m, n, 0, 1);
		} else {
			input = 0;
		}
	}
	basic_development (Test_field, Test_field, m, n, geben, Test_field, Test_sfc, Test_field, ges, Growth_players, number_of_players, gamemode_played, information_code, level, w, d, e, Destroy_, evolution, &num, &g, Test_special_fields, limits, test_single_options, Test_special_fields, position, KI_decision, rain, hayir);
	synchronisation_Test_field (Test_field, m, n, 1, 0);

	input = 1;
	while (input != 0) {
		show_field (number_of_players, 0, level, Test_field, Test_field, Test_field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Test_sfc);
		printf("	Boost: The next action of you will be a Boost, \n	that means the squares of the enemy which are touching you with at least one full side will count as your own squares according to the development, not for the decision which squares of yours have to die.	?0?\n");
		input = get_unsigned_numeric_input_with_not_more_than_1_letter ();
		printf(" \n");
	}
	basic_development (Test_field, Test_field, m, n, geben, Test_field, Test_sfc, Test_field, ges, Growth_players, number_of_players, gamemode_played, information_code, level, w, d, e, Boost_, evolution, &num, &g, Test_special_fields, limits, test_single_options, Test_special_fields, position, KI_decision, rain, hayir);
	synchronisation_Test_field (Test_field, m, n, 1, 0);

	input = 1;
	while (input != 0) {
		show_field (number_of_players, 0, level, Test_field, Test_field, Test_field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Test_sfc);
		printf("	Move: Move your square on 0703 to 0603.\n");

		Move (level, Test_field, m, n, geben, Test_field, gamemode_played, information_code, Growth_players, Test_special_fields, Test_sfc, number_of_players, test_single_options);

		if ((Test_field[0][7][3] != 0)||(Test_field[0][6][3] != geben)) {
			input = 1;
			synchronisation_Test_field (Test_field, m, n, 0, 1);
		} else {
			input = 0;
		}
	}
	basic_development (Test_field, Test_field, m, n, geben, Test_field, Test_sfc, Test_field, ges, Growth_players, number_of_players, gamemode_played, information_code, level, w, d, e, Move_4, evolution, &num, &g, Test_special_fields, limits, test_single_options, Test_special_fields, position, KI_decision, rain, hayir);
	synchronisation_Test_field (Test_field, m, n, 1, 0);

	input = 1;
	while (input != 0) {
		show_field (number_of_players, 0, level, Test_field, Test_field, Test_field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Test_sfc);
		printf("	2-new: The next action of you will be a 2-new, means you are getting dead squares which have 2 instead of 3 squares of yours in its surrounding.	?0?\n");
		input = get_unsigned_numeric_input_with_not_more_than_1_letter ();
		printf(" \n");
	}
	w = 2;
	basic_development (Test_field, Test_field, m, n, geben, Test_field, Test_sfc, Test_field, ges, Growth_players, number_of_players, gamemode_played, information_code, level, w, d, e, new_2, evolution, &num, &g, Test_special_fields, limits, test_single_options, Test_special_fields, position, KI_decision, rain, hayir);
	synchronisation_Test_field (Test_field, m, n, 1, 0);
	w = 3;

	input = 1;
	while (input != 0) {
		show_field (number_of_players, 0, level, Test_field, Test_field, Test_field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Test_sfc);
		printf("	Revive: The next action of you will be a Revive, means the squares of yours that died and have no squares in its surrounding, which were owned by you before and are still living, will be yours again.	?0?\n");
		input = get_unsigned_numeric_input_with_not_more_than_1_letter ();
		printf(" \n");
	}
	basic_development (Test_field, Test_field, m, n, geben, Test_field, Test_sfc, Test_field, ges, Growth_players, number_of_players, gamemode_played, information_code, level, w, d, e, Revive_, evolution, &num, &g, Test_special_fields, limits, test_single_options, Test_special_fields, position, KI_decision, rain, hayir);
	synchronisation_Test_field (Test_field, m, n, 1, 0);

	input = 1;
	while (input != 0) {
		show_field (number_of_players, 0, level, Test_field, Test_field, Test_field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Test_sfc);
		printf("	4/5-new: The next action of you will be a 4/5-new, means you are getting dead squares which have 4 or 5 instead of 3 squares of yours in its surrounding.	?0?\n");
		input = get_unsigned_numeric_input_with_not_more_than_1_letter ();
		printf(" \n");
	}
	w = 4;
	basic_development (Test_field, Test_field, m, n, geben, Test_field, Test_sfc, Test_field, ges, Growth_players, number_of_players, gamemode_played, information_code, level, w, d, e, new_4_5, evolution, &num, &g, Test_special_fields, limits, test_single_options, Test_special_fields, position, KI_decision, rain, hayir);
	synchronisation_Test_field (Test_field, m, n, 1, 0);
	w = 3;

	input = 1;
	while (input != 0) {
		show_field (number_of_players, 0, level, Test_field, Test_field, Test_field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Test_sfc);
		printf("	4-max: The next action of you will be a 4-max, means squares of yours can have up to 4 instead of 3 squares of yours in its surrounding and will still survive.	?0?\n");
		input = get_unsigned_numeric_input_with_not_more_than_1_letter ();
		printf(" \n");
	}
	e = 4;
	basic_development (Test_field, Test_field, m, n, geben, Test_field, Test_sfc, Test_field, ges, Growth_players, number_of_players, gamemode_played, information_code, level, w, d, e, max_4, evolution, &num, &g, Test_special_fields, limits, test_single_options, Test_special_fields, position, KI_decision, rain, hayir);
	synchronisation_Test_field (Test_field, m, n, 1, 0);
	e = 3;

	input = 1;
	while (input != 0) {
		show_field (number_of_players, 0, level, Test_field, Test_field, Test_field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Test_sfc);
		printf("	1-min: The next action of you will be a 1-min, means squares of yours can have down to 1 instead of 2 squares of yours in its surrounding and will still survive.	?0?\n");
		input = get_unsigned_numeric_input_with_not_more_than_1_letter ();
		printf(" \n");
	}
	d = 1;
	basic_development (Test_field, Test_field, m, n, geben, Test_field, Test_sfc, Test_field, ges, Growth_players, number_of_players, gamemode_played, information_code, level, w, d, e, min_1, evolution, &num, &g, Test_special_fields, limits, test_single_options, Test_special_fields, position, KI_decision, rain, hayir);
	synchronisation_Test_field (Test_field, m, n, 1, 0);
	d = 2;

	show_field (number_of_players, 0, level, Test_field, Test_field, Test_field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Test_sfc);
	printf(" \n");

	Spielfeld_Destroy (evolution.nl, m, number_of_players);
	Spielfeld_Destroy (evolution.od, m, number_of_players);
	Spielfeld_Destroy (Test_field, m, 1);
	Spielfeld_Destroy (Test_special_fields.field, m, number_of_players+2);
	unsigned_int_Vektor_Destroy (KI_decision);
	Special_Fields_Collector_Vektor_Destroy (Test_sfc);
}

void synchronisation_Test_field (Spielfeld Test_field, unsigned int m, unsigned int n, unsigned int to, unsigned int from) {

	// printf("synchronisation_Test_field ok.1\n");	//test

	for (unsigned int i=1; i<=m-2; i++) {
		for (unsigned int j=1; j<=n-2; j++) {
			Test_field[to][i][j] = Test_field[from][i][j];
		}
	}
}


