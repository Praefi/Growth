#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
//#include <windows.h>	// look at Growth.h
#include <ctype.h>
#include "Growth_all.h"

// anscheinend kehren die gestorbenen zurück in das Standartspiel bei gamemode_played 6 (aktuell ?)

// struct realize_modifications_variables {};
unsigned int Fakultaet (unsigned int);

unsigned int letters_4;
unsigned int letters_2;

unsigned int Liz_max;
unsigned int anything; //Die Variable für alles Mögliche

time_t time_of_the_start;

int Vektor_counter;
int Spielfeld_counter;

int main (void) {

	time_of_the_start = time(NULL);
	
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
	unsigned int figures, allocation, iteration, journey, undead_duration, opague, inverted, addition, assassin, avalanche;	//options, selected with beginningmenu
	unsigned int rtc, spf, scwhp, hboa;	// Gamemode: Hunt
	unsigned int NOSV, AOP;		//number of saved variables; amount of players
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
	
	playtime = 1;	//playing a game after a game after...

	NOSV = 91;	//Number_of_saved_variables, drücke abhängig von AOP aus, go on
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
		limits.new = 0;		//if
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

					printf("	%u. Tutorial\n	%u. Classic\n	%u. Collect\n	%u. Contact\n	%u. Fall\n	%u. Fight\n	%u. Hunt\n	%u. Race\n	%u. Rain\n	%u. Arena\n   	%u. Ulcer\n    	%u. Dynamic\n     	%u. Survive\n     	%u. Sand\n     	%u. Quidditch\n  \n", Tutorial, Classic, Collect, Contact, Fall, Fight, Hunt, Race, Rain, Arena, Ulcer, Dynamic, Survive, Sand, Quidditch);	//mehr-gamemode_played
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
				limits.new = Initialisierung_limits_new (gamemode_played);
				m = Initialisierung_m (gamemode_played);
				n = Initialisierung_n (gamemode_played);

				while (beginningmenu != oStart){

					printf("	%u. Start game\n \n	%u. Game size\n	%u. Journey\n	%u. Tactics\n	%u. Random\n	%u. Limits\n	%u. Time\n	%u. Color\n	%u. Opague\n	%u. undead\n	%u. Figures\n	%u. Allocation\n	%u. Cards\n	%u. Inverted\n	%u. Addition\n	%u. Projection\n	%u. Assassin\n	%u. Permutations\n	%u. Avalanche\n	%u. KI\n	%u. Number of players\n  \n	%u. Back\n \n", oStart, oSize, oJourney, oTactics, oRandom, oLimits, oTime, oColor, oOpague, oUndead, oFigures, oAllocation, oCards, oInverted, oAddition, oProjection, oAssassin, oPermutations, oAvalanche, oBack-2, oBack-1, oBack);	//synchronisiere stets oBack mit beginningmenu
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
						printf("	%u. Quidditch-team-abilities\n", oBack+2);	//go on
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

							printf("	Random activated \n");
							printf("	Please get all a number from 0 to %u, not the same, it will have no effect further on. \n", number_of_players-1);
							printf("	Give me three random numbers from 1 to 60 \n");
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
						if ((gamemode_played == Classic)||(gamemode_played == Collect)) {
							printf("	Change limits.new: 1 \n	Change limits.at_all: 2 \n	Change both: 3 \n");
							lim = get_unsigned_numeric_input_with_not_more_than_1_letter ();
							printf("\n");

							if (lim == 1){
								printf("	limits.new:		(normal: 10) \n");
								limits.new = get_unsigned_numeric_input_with_not_more_than_2_letters ();
								printf("\n");
							}
							if (lim == 2){
								printf("	limits.at_all:		(normal: 20) \n");
								limits.at_all = get_unsigned_numeric_input_with_not_more_than_2_letters ();
								printf("\n");
							}
							if (lim == 3){
								printf("	limits.new:				(normal: 10) \n	limits.at_all:				(normal: 20) \n");
								letters_4 = get_unsigned_numeric_input_with_not_more_than_letters_4_for_splitting();
								limits.new = split_unsigned_numeric_input_with_letters_4 (letters_4, 0);
								limits.at_all = split_unsigned_numeric_input_with_letters_4 (letters_4, 1);
								printf("\n");
							}
						} else if (gamemode_played == Contact) {
							printf("	limits.new: 1		limits.at_all: 2		both: 3\n");
							lim = get_unsigned_numeric_input_with_not_more_than_1_letter ();

							if (lim == 1){
								printf("	limits.new:      (normal: 15) \n");
								limits.new = get_unsigned_numeric_input_with_not_more_than_2_letters ();
							}
							if (lim == 2){
								printf("	limits.at_all:       (normal: 30) \n");
								limits.at_all = get_unsigned_numeric_input_with_not_more_than_2_letters ();
							}
							if (lim == 3){
								printf("	limits.new:				(normal: 15) \n	limits.at_all:				(normal: 30) \n");
								letters_4 = get_unsigned_numeric_input_with_not_more_than_letters_4_for_splitting();
								limits.new = split_unsigned_numeric_input_with_letters_4 (letters_4, 0);
								limits.at_all = split_unsigned_numeric_input_with_letters_4 (letters_4, 1);
							}
						} else if ((gamemode_played == Fall)||(gamemode_played == Race)||(gamemode_played == Rain)) {
							printf("	limits.new: 1		limits.at_all: 2		both: 3\n");
							lim = get_unsigned_numeric_input_with_not_more_than_1_letter ();

							if (lim == 1){
								printf("	limits.new:      (normal: 7) \n");
								limits.new = get_unsigned_numeric_input_with_not_more_than_2_letters ();
							}
							if (lim == 2){
								printf("	limits.at_all:       (normal: 14) \n");
								limits.at_all = get_unsigned_numeric_input_with_not_more_than_2_letters ();
							}
							if (lim == 3){
								printf("	limits.new:				(normal: 7) \n	limits.at_all:				(normal: 14) \n");
								letters_4 = get_unsigned_numeric_input_with_not_more_than_letters_4_for_splitting();
								limits.new = split_unsigned_numeric_input_with_letters_4 (letters_4, 0);
								limits.at_all = split_unsigned_numeric_input_with_letters_4 (letters_4, 1);
							}
						} else if (gamemode_played == Fight) {
							printf("	limits.new: 1		limits.at_all: 2		both: 3\n");
							lim = get_unsigned_numeric_input_with_not_more_than_1_letter ();

							if (lim == 1){
								printf("	limits.new:      (normal: 5) \n");
								limits.new = get_unsigned_numeric_input_with_not_more_than_2_letters ();
							}
							if (lim == 2){
								printf("	limits.at_all:       (normal: 10) \n");
								limits.at_all = get_unsigned_numeric_input_with_not_more_than_2_letters ();
							}
							if (lim == 3){
								printf("	limits.new:				(normal: 5) \n	limits.at_all:				(normal: 10) \n");
								letters_4 = get_unsigned_numeric_input_with_not_more_than_letters_4_for_splitting();
								limits.new = split_unsigned_numeric_input_with_letters_4 (letters_4, 0);
								limits.at_all = split_unsigned_numeric_input_with_letters_4 (letters_4, 1);
							}
						} else if (gamemode_played == Hunt) {
							printf("	The limits of the hunted one will be calculated seperatly.\n");
							printf("	limits.new: 1		limits.at_all: 2		both: 3\n");
							lim = get_unsigned_numeric_input_with_not_more_than_1_letter ();

							if (lim == 1){
								printf("	limits.new:      (normal: 6) \n");
								limits.new = get_unsigned_numeric_input_with_not_more_than_2_letters ();
							}
							if (lim == 2){
								printf("	limits.at_all:       (normal: 12) \n");
								limits.at_all = get_unsigned_numeric_input_with_not_more_than_2_letters ();
							}
							if (lim == 3){
								printf("	limits.new:				(normal: 6) \n	limits.at_all:				(normal: 12) \n");
								letters_4 = get_unsigned_numeric_input_with_not_more_than_letters_4_for_splitting();
								limits.new = split_unsigned_numeric_input_with_letters_4 (letters_4, 0);
								limits.at_all = split_unsigned_numeric_input_with_letters_4 (letters_4, 1);
							}
						} else if (gamemode_played == Arena) {
							printf("	limits.new can change with your ability.\n");
							printf("	limits.new: 1		limits.at_all: 2		both: 3\n");
							lim = get_unsigned_numeric_input_with_not_more_than_1_letter ();

							if (lim == 1){
								printf("	limits.new:      (normal: 8) \n");
								limits.new = get_unsigned_numeric_input_with_not_more_than_2_letters ();
							}
							if (lim == 2){
								printf("	limits.at_all:       (normal: 16) \n");
								limits.at_all = get_unsigned_numeric_input_with_not_more_than_2_letters ();
							}
							if (lim == 3){
								printf("	limits.new:				(normal: 8) \n	limits.at_all:				(normal: 16) \n");
								letters_4 = get_unsigned_numeric_input_with_not_more_than_letters_4_for_splitting();
								limits.new = split_unsigned_numeric_input_with_letters_4 (letters_4, 0);
								limits.at_all = split_unsigned_numeric_input_with_letters_4 (letters_4, 1);
							}
						} else if (gamemode_played == Ulcer) {
							printf("	Ulcer is unlimited.\n");

						} else if (gamemode_played == Dynamic) {
							printf("	This only works if the number of players is correct! \n");

							printf("	limits.new: 1		limits.at_all: 2		both: 3\n");
							lim = get_unsigned_numeric_input_with_not_more_than_1_letter ();

							if (lim == 1){

								printf("	limits.new:      (normal: 10) \n");
								limits.new = get_unsigned_numeric_input_with_not_more_than_2_letters ();

							}
							if (lim == 2){

								printf("	limits.at_all:       (normal: 20) \n");
								limits.at_all = get_unsigned_numeric_input_with_not_more_than_2_letters ();

							}
							if (lim == 3){

								printf("	limits.new:				(normal: 10) \n	limits.at_all:				(normal: 20) \n");
								letters_4 = get_unsigned_numeric_input_with_not_more_than_letters_4_for_splitting();
								limits.new = split_unsigned_numeric_input_with_letters_4 (letters_4, 0);
								limits.at_all = split_unsigned_numeric_input_with_letters_4 (letters_4, 1);
							}
						} else if (gamemode_played == Survive) {
							printf("	Survive is unlimited.\n");

						} else if (gamemode_played == Sand) {
							printf("	This only works if the number of players is correct! \n");

							printf("	limits.new: 1		limits.at_all: 2		both: 3\n");
							lim = get_unsigned_numeric_input_with_not_more_than_1_letter ();

							if (lim == 1){

								printf("	limits.new:      (normal: 7) \n");
								limits.new = get_unsigned_numeric_input_with_not_more_than_2_letters ();

							}
							if (lim == 2){

								printf("	limits.at_all:       (normal: 14) \n");
								limits.at_all = get_unsigned_numeric_input_with_not_more_than_2_letters ();

							}
							if (lim == 3){

								printf("	limits.new:				(normal: 7) \n	limits.at_all:				(normal: 14) \n");
								letters_4 = get_unsigned_numeric_input_with_not_more_than_letters_4_for_splitting();
								limits.new = split_unsigned_numeric_input_with_letters_4 (letters_4, 0);
								limits.at_all = split_unsigned_numeric_input_with_letters_4 (letters_4, 1);
							}
						} else if (gamemode_played == Quidditch) {
							printf("	limits.new: 1		limits.at_all: 2		both: 3\n");
							lim = get_unsigned_numeric_input_with_not_more_than_1_letter ();

							if (lim == 1){

								printf("	limits.new:      (normal: 20) \n");
								limits.new = get_unsigned_numeric_input_with_not_more_than_2_letters ();

							}
							if (lim == 2){

								printf("	limits.at_all:       (normal: 40) \n");
								limits.at_all = get_unsigned_numeric_input_with_not_more_than_2_letters ();

							}
							if (lim == 3){

								printf("	limits.new:				(normal: 20) \n	limits.at_all:				(normal: 40) \n");
								letters_4 = get_unsigned_numeric_input_with_not_more_than_letters_4_for_splitting();
								limits.new = split_unsigned_numeric_input_with_letters_4 (letters_4, 0);
								limits.at_all = split_unsigned_numeric_input_with_letters_4 (letters_4, 1);
							}
						}
						if (limits.new > limits.at_all) {
							limits.new = limits.at_all;
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
							if ((gamemode_played == Classic)||(gamemode_played == Collect)) {
								printf("	Choose the limit of time:         (normal: 20sec) \n");
								ttt = get_unsigned_numeric_input_with_not_more_than_2_letters ();
								if (ttt == 0) {
									printf("	That's impossible! You'll take 20sec. \n");
									ttt = 20;
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

							} else if ((gamemode_played == Contact)||(gamemode_played == Arena)||(gamemode_played == Dynamic)||(gamemode_played == Quidditch)) {
								printf("	Choose the limit of time:         (normal: 30sec) \n");
								ttt = get_unsigned_numeric_input_with_not_more_than_2_letters ();
								if (ttt == 0) {
									printf("	That's impossible! You'll take 30sec. \n");
									ttt = 30;
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

							} else if ((gamemode_played == Fall)||(gamemode_played == Race)||(gamemode_played == Rain)||(gamemode_played == Ulcer)||(gamemode_played == Survive)) {
								printf("	Choose the limit of time:         (normal: 25sec) \n");
								ttt = get_unsigned_numeric_input_with_not_more_than_2_letters ();
								if (ttt == 0) {
									printf("	That's impossible! You'll take 25sec. \n");
									ttt = 25;
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
							} else if (gamemode_played == Fight) {
								printf("	Choose the limit of time:         (normal: 15sec) \n");
								ttt = get_unsigned_numeric_input_with_not_more_than_2_letters ();
								if (ttt == 0) {
									printf("	That's impossible! You'll take 15sec. \n");
									ttt = 15;
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

							} else if (gamemode_played == Hunt) {
								printf("	The hunted one will get a 10sec bonus. \n");
								printf("	The time for choosing his heart is unlimited. \n");
								printf("	\n");
								printf("	Choose the limit of time:         (normal: 35sec) \n");
								ttt = get_unsigned_numeric_input_with_not_more_than_2_letters ();
								if (ttt == 0) {
									printf("	That's impossible! You'll take 35sec. \n");
									ttt = 35;
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

						printf("	Every movement of a square owned by a player caused by gamemode-special actions will reduce its allocation to 1 \n");

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
					
					if ((beginningmenu == oBack+1)&&(gamemode_played == Quidditch)) {
						printf("	Klatscher-fly-distance:		(normal: 3) \n");
						Qoa->Klatscher_fly_distance = get_unsigned_numeric_input_with_not_more_than_1_letter ();
						
						printf("	Schnatz-fly-distance:		(normal: 3) \n");
						Qoa->Schnatz_fly_distance = get_unsigned_numeric_input_with_not_more_than_1_letter ();
						
						while ((Qoa->Schnatz_appearence_factor%10 < Qoa->Schnatz_appearence_factor/10)||(Qoa->Schnatz_appearence_factor == 0)) {
							printf("	Schnatz-appearence-factor:		(normal: 13 [read as 1/3]) \n");
							Qoa->Schnatz_appearence_factor = get_unsigned_numeric_input_with_not_more_than_2_letters ();
						}
						
						while ((Qoa->Schnatz_disappearence_factor%10 < Qoa->Schnatz_disappearence_factor/10)||(Qoa->Schnatz_disappearence_factor == 0)) {
							printf("	Schnatz-disappearence-factor:		(normal: 23 [read as 2/3]) \n");
							Qoa->Schnatz_disappearence_factor = get_unsigned_numeric_input_with_not_more_than_2_letters ();
						}
					}
					
					if ((beginningmenu == oBack+2)&&(gamemode_played == Quidditch)) {
						for (unsigned int p=1; p<=number_of_players; p++) {
							printf("	Player %u, please create a selection of Team-abilities, everyone wil be able to take it. \n", p);
							
							printf("	Jaeger-fly-distance:		(normal: 3) \n");
							Qta[p].Jaeger_fly_distance = get_unsigned_numeric_input_with_not_more_than_1_letter ();
							
							printf("	Jaeger-throw-distance:		(normal: 3) \n");
							Qta[p].Jaeger_throw_distance = get_unsigned_numeric_input_with_not_more_than_1_letter ();
							
							printf("	Hueter-fly-distance:		(normal: 2) \n");
							Qta[p].Hueter_fly_distance = get_unsigned_numeric_input_with_not_more_than_1_letter ();
							
							printf("	Hueter-throw-distance:		(normal: 3) \n");
							Qta[p].Hueter_throw_distance = get_unsigned_numeric_input_with_not_more_than_1_letter ();
							
							printf("	Treiber-fly-distance:		(normal: 3) \n");
							Qta[p].Treiber_fly_distance = get_unsigned_numeric_input_with_not_more_than_1_letter ();
							
							printf("	Treiber-hit-distance:		(normal: 3) \n");
							Qta[p].Treiber_hit_distance = get_unsigned_numeric_input_with_not_more_than_1_letter ();
							
							printf("	Sucher-fly-distance:		(normal: 3) \n");
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

					if (beginningmenu == Numberofplayers){
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
							if (gamemode_played == Classic) {	//checklist
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
							} else if (gamemode_played == Fight) {
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
						printf("	Schnatz-appearence-factor:	%u \n", Qoa->Schnatz_appearence_factor);
						printf("	Schnatz-disappearence-factor:	%u \n", Qoa->Schnatz_disappearence_factor);
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
					printf("	limits.new:    %u \n	limits.at_all: %u \n", limits.new, limits.at_all);
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

			//Startmenü, Ende

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
			same[18] = limits.new;
			same[19] = limits.at_all;
			same[20] = ulcer_lifes[2];
			same[21] = points_for_win;
			same[22] = freq;
			same[23] = use_number;
			same[24] = number_of_players;
			same[25] = rtc;
			same[26] = spf;
			same[27] = ulcer_lifes[0];
			same[28] = 0; // same[28] = hboa;
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

	// printf("	Existing Fields: %d \n ", Spielfeld_counter);	//test
	// printf("	Existing Vektors: %d \n ", Vektor_counter);	//test
	// printf("	\n ");
	// printf("	#line 1k, 23\n");	//test
	// scanf("%u", &pause);	//test

	return 0;
}
