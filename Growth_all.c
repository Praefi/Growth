#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <windows.h>

// anscheinend kehren die gestorbenen zurück in das Standartspiel bei gamemode 6 (aktuell ?)

typedef unsigned int** Spielfeld;

Spielfeld Spielfeld_Create (unsigned int, unsigned int);			//mxn, m >= 6 (+2), n gerade, n >= 4 (+2)		Original: m = 10 (+2), n = 6 (+2)
Spielfeld start_normal (Spielfeld, unsigned int, unsigned int, unsigned int, unsigned int);

unsigned int* unsigned_int_Vektor_Create (unsigned int);
int* int_Vektor_Create (unsigned int );

Spielfeld new_life_1 (Spielfeld, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int*);
Spielfeld old_dying_1 (Spielfeld, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int*);
Spielfeld change_1 (Spielfeld, Spielfeld, Spielfeld, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int*);

Spielfeld new_life_2 (Spielfeld, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int*);
Spielfeld old_dying_2 (Spielfeld, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int*);
Spielfeld change_2 (Spielfeld, Spielfeld, Spielfeld, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int*);

Spielfeld new_life_3 (Spielfeld, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int*);
Spielfeld old_dying_3 (Spielfeld, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int*);
Spielfeld change_3 (Spielfeld, Spielfeld, Spielfeld, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int*);

Spielfeld new_life_4 (Spielfeld, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int*);
Spielfeld old_dying_4 (Spielfeld, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int*);
Spielfeld change_4 (Spielfeld, Spielfeld, Spielfeld, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int*);

Spielfeld new_life_5 (Spielfeld, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int*);
Spielfeld old_dying_5 (Spielfeld, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int*);
Spielfeld change_5 (Spielfeld, Spielfeld, Spielfeld, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int*);

Spielfeld new_life_6 (Spielfeld, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int*);
Spielfeld old_dying_6 (Spielfeld, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int*);
Spielfeld change_6 (Spielfeld, Spielfeld, Spielfeld, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int*);

Spielfeld new_life_7 (Spielfeld, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int*);
Spielfeld old_dying_7 (Spielfeld, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int*);
Spielfeld change_7 (Spielfeld, Spielfeld, Spielfeld, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int*);

Spielfeld new_life_8 (Spielfeld, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int*);
Spielfeld old_dying_8 (Spielfeld, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int*);
Spielfeld change_8 (Spielfeld, Spielfeld, Spielfeld, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int*);

Spielfeld new_life_9 (Spielfeld, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int*);
Spielfeld old_dying_9 (Spielfeld, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int*);
Spielfeld change_9 (Spielfeld, Spielfeld, Spielfeld, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int*);

void show_field (Spielfeld, unsigned int, unsigned int, unsigned int, unsigned int*, unsigned int, unsigned int*);

void Spielfeld_Destroy (Spielfeld, unsigned int);

void Plus (unsigned int, unsigned int, unsigned int, Spielfeld, unsigned int, unsigned int, unsigned int*, unsigned int, unsigned int*, unsigned int, Spielfeld);
void Minus (unsigned int, unsigned int, unsigned int, Spielfeld, unsigned int, unsigned int*, unsigned int*, unsigned int, Spielfeld);
void Move (unsigned int, unsigned int, unsigned int, Spielfeld, unsigned int, unsigned int*, unsigned int*, unsigned int, Spielfeld);
void Change (unsigned int, unsigned int, unsigned int, Spielfeld, unsigned int, unsigned int*, unsigned int*, unsigned int, Spielfeld, unsigned int*);
void Destroy (unsigned int, unsigned int, unsigned int, Spielfeld, unsigned int, unsigned int*, unsigned int*, unsigned int, Spielfeld);
void Revive_1 (unsigned int, unsigned int, Spielfeld, Spielfeld);
void Revive_2 (unsigned int, unsigned int, Spielfeld, Spielfeld);
void Revive_3 (unsigned int, unsigned int, Spielfeld, Spielfeld);
void Revive_4 (unsigned int, unsigned int, Spielfeld, Spielfeld);
void Revive_5 (unsigned int, unsigned int, Spielfeld, Spielfeld);
void Revive_6 (unsigned int, unsigned int, Spielfeld, Spielfeld);
void Revive_7 (unsigned int, unsigned int, Spielfeld, Spielfeld);
void Revive_8 (unsigned int, unsigned int, Spielfeld, Spielfeld);
void Revive_9 (unsigned int, unsigned int, Spielfeld, Spielfeld);
void Boost (unsigned int, Spielfeld, unsigned int, unsigned int, Spielfeld, unsigned int);

Spielfeld Index_1 (unsigned int, unsigned int, unsigned int, unsigned int, Spielfeld, Spielfeld, Spielfeld, unsigned int, unsigned int, unsigned int);
Spielfeld Index_2 (unsigned int, unsigned int, unsigned int, unsigned int, Spielfeld, Spielfeld, Spielfeld, unsigned int, unsigned int, unsigned int);
Spielfeld Index_1_col (unsigned int, unsigned int, unsigned int, unsigned int, Spielfeld, Spielfeld, Spielfeld, unsigned int, unsigned int, unsigned int);
Spielfeld Index_2_col (unsigned int, unsigned int, unsigned int, unsigned int, Spielfeld, Spielfeld, Spielfeld, unsigned int, unsigned int, unsigned int);
Spielfeld Index_1_con (unsigned int, unsigned int, unsigned int, unsigned int, Spielfeld, Spielfeld, unsigned int);
Spielfeld Index_2_con (unsigned int, unsigned int, unsigned int, unsigned int, Spielfeld, Spielfeld, unsigned int);
Spielfeld Index_1_fal (unsigned int, unsigned int, unsigned int, unsigned int, Spielfeld, Spielfeld, Spielfeld, unsigned int, unsigned int, unsigned int);
Spielfeld Index_2_fal (unsigned int, unsigned int, unsigned int, unsigned int, Spielfeld, Spielfeld, Spielfeld, unsigned int, unsigned int, unsigned int);
Spielfeld Index_1_fig (unsigned int, unsigned int, unsigned int, unsigned int, Spielfeld, Spielfeld, Spielfeld, unsigned int, unsigned int, unsigned int);
Spielfeld Index_2_fig (unsigned int, unsigned int, unsigned int, unsigned int, Spielfeld, Spielfeld, Spielfeld, unsigned int, unsigned int, unsigned int);
Spielfeld Index_1_race (unsigned int, unsigned int, unsigned int, unsigned int, Spielfeld, Spielfeld, Spielfeld, unsigned int, unsigned int, unsigned int);
Spielfeld Index_2_race (unsigned int, unsigned int, unsigned int, unsigned int, Spielfeld, Spielfeld, Spielfeld, unsigned int, unsigned int, unsigned int);
Spielfeld Index_1_rain (unsigned int, unsigned int, unsigned int, unsigned int, Spielfeld, Spielfeld, Spielfeld, unsigned int, unsigned int, unsigned int, unsigned int);
Spielfeld Index_2_rain (unsigned int, unsigned int, unsigned int, unsigned int, Spielfeld, Spielfeld, Spielfeld, unsigned int, unsigned int, unsigned int, unsigned int);
Spielfeld Index_1_hunt (unsigned int, unsigned int, unsigned int, unsigned int, Spielfeld, Spielfeld, unsigned int, unsigned int, unsigned int, Spielfeld, unsigned int);
Spielfeld Index_other_hunt (unsigned int, unsigned int, unsigned int, unsigned int, Spielfeld, unsigned int, unsigned int, Spielfeld, unsigned int);
Spielfeld Index_are (unsigned int, unsigned int, unsigned int, unsigned int, Spielfeld, Spielfeld, unsigned int, unsigned int, unsigned int, Spielfeld, unsigned int, unsigned int, unsigned int, unsigned int);
Spielfeld Index_dyn (unsigned int, unsigned int, unsigned int, unsigned int, Spielfeld, Spielfeld, unsigned int, unsigned int, unsigned int, Spielfeld, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int*);

Spielfeld opague_builder (Spielfeld, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);

unsigned int random_number (unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int*, unsigned int, unsigned int);

void battle (unsigned int, unsigned int, Spielfeld, unsigned int);
unsigned int chain_count (unsigned int, unsigned int, Spielfeld, Spielfeld, unsigned int, unsigned int);

void touch (Spielfeld, unsigned int, unsigned int, unsigned int, Spielfeld, Spielfeld);

void ahead (Spielfeld, unsigned int, unsigned int);

void choose_heart (Spielfeld, unsigned int, unsigned int);
void heart_ground (unsigned int, unsigned int, Spielfeld, Spielfeld);

int sgn (int);
void Reflection (int*, unsigned int, int);
void impact_y_semi_square (unsigned int, unsigned int, unsigned int*, unsigned int, unsigned int, int*, Spielfeld);	// unsigned int** wird zu Spielfeld

int main (void) {
	
	//printf ("	ok 1 \n");	//test
	
	
	Spielfeld Sf, Sf_nl_1, Sf_nl_2, Sf_od_1, Sf_od_2, cons_field_1, cons_field_2, Sf_journey, cons_journey_1, cons_journey_2, Sf_opague;	//ruck muss raus, done
	unsigned int m, n, geben, ent, controll_1, controll_2, journey, tac, playtime;
	unsigned int beginningmenu, gamemode, fall_controll, fall_back, turns_per_drop, speed_of_fall, count_freq, rain, rain_drops, rain_save, rain_obj, rain_speed, rain_speed_save;
	unsigned int w, d, e, opt, siz_m, siz_n, limit_new, limit_at_all, lim, suprise, sup_num, menuoperator, points_for_win, freq;
	unsigned int number_1, number_2, number_3, number_4, number_5, number_6, number_7, number_8, number_9, use_number, num_1, num_2, num_3, num_temp, number_rain;
	unsigned int A[7], B[7], C[6], D[6], P[3];		//Variablen für Schleifen vorbereiten, go on
	unsigned int count_new, einmal, boost_hunt_activator, zeitgewinner;
	unsigned int nosv, aop;		//number of saved variables; amount of players
	unsigned int range, d_wert, indikator1, indikator2, indikator3, space_i, space_j, controll, iteration;
	//unsigned int cons[1]_fort, cons[2]_fort, cons[3]_fort, cons[4]_fort, cons[5]_fort, cons[6]_fort, cons[7]_fort, cons[8]_fort, cons[9]_fort;
	
	//scanf("%u", &w); //test
	//printf ("	ok 2 \n");	//test
	
	unsigned int number_of_players, rtc, spf, scwhp, round_counter, round_counter_before, hboa, precounter, opague;
	unsigned int ttt, warning_system, back_opt, exclude_counter, player_counter, rtp, limit_at_all_saver, information_code[4];	//time-to-think, rounds-to-play, 0 == rtc, 1 == spf, 2 == hboa, 3 == scwhp (gamemode == 6)
	unsigned int pere[10], ability[10], Colored[10], ulcer_start[10], ulcer_lifes[10], out_counter[10], Color_choice[13];		// penalty-reminder
	unsigned int* same;	//immer aktualisieren
	unsigned int* position;		// "*" bezieht sich auf "position", nicht auf "unsigned int" !!!!
	int erd;
	int* dynamic_pointer;
	int** dynamic_pointer_save;
	//unsigned int position[1], position[0];
	
	unsigned int ges[10], var_[10], cons[10];
	//unsigned int same_counter;
	
	//same: 0, m, n, journey, tac, gamemode, fall_controll, turns_per_drop, speed_of_fall, count_freq, rain, rain_drops, rain_obj, rain_speed,	//14
	//		opt, siz_m, siz_n, limit_new, limit_at_all, points_for_win, freq, use_number,	//8
	//		number_of_players, rtc, spf, scwhp, hboa, ttt, warning_system, exclude_counter, rtp, information_code[4], ability[10], Colored[10], ulcer_lifes[10] ohne [0]	//42
	
	double time_saver, time_warning;
	
	time_t time1, time2, time3, time4;
	
	//gamemode == 6, geben == 1: information_code: [0]=0, [1]=1, [2]=1, [3]=0, [4]=0
	
	//Benutzbar, aber benutzt:	unsigned int: lim, suprise, 
	//Benutzbar, und unbenutzt:	unsigned int: 	(cons[0]?)		int (in int-Vektor): dynamic_pointer_save[p][0] (p=0,1,2,3)
	// used field numbers: 1,2,3,4,5,6,7,8,9,10,11,15,16,17,20,30,40,50,60,70,71,74,75,77,80,81,82,83,84,90,101,202,303,404,505,606,707,808,909
	// used unusually ges numbers 1010,2020,3030,4040,5050,6060,7070,8080,9090
	// 10, 20, 30, 40, 50, 60, 70, 80, 90 ausschließlich im Spielfeldrand
	//used Sf: (1,0), (0,0), (0,1), (0,n-1), (m-1,n-1), (m-1,0)
	
	playtime = 1;
	
	aop = 9;
	nosv = 70;
	//same_counter = 0; 		//for variable length of same
	
	dynamic_pointer = int_Vektor_Create (8);
	
	dynamic_pointer_save = calloc(aop+1, sizeof(int*));
	for (unsigned int i=0; i<=aop; i+=1) {
		dynamic_pointer_save[i] = calloc(4, sizeof(int));
	}
	
	position = calloc(2, sizeof(unsigned int));
	position[0] = 0;
	position[1] = 0;
	
	same = unsigned_int_Vektor_Create (nosv);		//go on
	for (unsigned int p=0; p<=(nosv-1); p+=1) {
		same[p] = 0;
	}
	
	unsigned int AA[7], CC[6];
	Spielfeld Sf_nl_3, Sf_od_3;
	Spielfeld cons_journey_3, cons_field_3;
	
	unsigned int BB[7], DD[6];
	Spielfeld Sf_nl_4, Sf_od_4;
	Spielfeld cons_journey_4, cons_field_4;
	
	unsigned int AAA[7], CCC[6];
	Spielfeld Sf_nl_5, Sf_od_5;
	Spielfeld cons_journey_5, cons_field_5;
	
	unsigned int BBB[7], DDD[6];
	Spielfeld Sf_nl_6, Sf_od_6;
	Spielfeld cons_journey_6, cons_field_6;
	
	unsigned int AAAA[7], CCCC[6];
	Spielfeld Sf_nl_7, Sf_od_7;
	Spielfeld cons_journey_7, cons_field_7;
	
	unsigned int BBBB[7], DDDD[6];
	Spielfeld Sf_nl_8, Sf_od_8;
	Spielfeld cons_journey_8, cons_field_8;
	
	unsigned int AAAAA[7], CCCCC[6];
	Spielfeld Sf_nl_9, Sf_od_9;
	Spielfeld cons_journey_9, cons_field_9;
	
	/*
	cons_fort[1] = 0;
	cons_fort[2] = 0;
	cons_fort[3] = 0;
	cons_fort[4] = 0;
	cons_fort[5] = 0;
	cons_fort[6] = 0;
	cons_fort[7] = 0;
	cons_fort[8] = 0;
	cons_fort[9] = 0;
	*/
	
	//scanf("%u", &w); //test
	//printf("%u \n", same[0]);	//test
	//printf ("	ok 3 \n");	//test
	
	while (playtime != 0){		// Außenschleife für mehrere Spiele hintereinander
		
		for (unsigned int p=0; p<=6; p+=1){
			A[p] = 0;
			B[p] = 0;
		}
		for (unsigned int p=0; p<=5; p+=1){
			C[p] = 0;
			D[p] = 0;
		}
		for (unsigned int p=0; p<=2; p+=1){
			P[p] = 0;		//possible to modify
		}
		for (unsigned int p=0; p<=3; p+=1){
			information_code[p] = 0;
		}
		
		//scanf("%u", &w); //test
		//printf ("	ok 4 \n");	//test
		
		for (unsigned int p=0; p<=6; p+=1) {
			AA[p] = 0;
			BB[p] = 0;
			AAA[p] = 0;
			BBB[p] = 0;
			AAAA[p] = 0;
			BBBB[p] = 0;
			AAAAA[p] = 0;
		}
		for (unsigned int p=0; p<=5; p+=1) {
			CC[p] = 0;
			DD[p] = 0;
			CCC[p] = 0;
			DDD[p] = 0;
			CCCC[p] = 0;
			DDDD[p] = 0;
			CCCCC[p] = 0;
		}
		
		//playtime should start here
		
		number_5 = 0;
		number_6 = 0;
		number_7 = 0;
		number_8 = 0;
		number_9 = 0;
		
		number_of_players = 2;
		
		//scanf("%u", &w); //test
		//printf ("	ok 5.1 \n");	//test
		
		m = 0;	//
		n = 0;	//
		
		rain_speed = 1;
		rain_speed_save = 0;
		rain_obj = 0;
		rain = 1;		//Push
		rain_drops = 1;
		rain_save = 0;
		freq = 6;
		
		fall_back = 0;
		fall_controll = 0;
		points_for_win = 3;
		turns_per_drop = 3;
		speed_of_fall = 1;
		
		iteration = 0;		//eine Iteration-Option, go on
		controll = 0;
		space_i = 0;
		space_j = 0;
		indikator1 = 0;		//für horizontal
		indikator2 = 0;		//für vertikal
		indikator3 = 0;
		d_wert = 1;
		
		range = 1;
		erd = 1;
		
		//scanf("%u", &w); //test
		//printf ("	ok 5.2 \n");	//test
		
		dynamic_pointer[0] = 0;	//s_horizontal
		dynamic_pointer[1] = 0;	//s_vertikal
		
		dynamic_pointer[2] = 0;	//v_horizontal
		dynamic_pointer[3] = 0;	//v_vertikal
		
		for (unsigned int p=0; p<=aop; p+=1) {
			dynamic_pointer_save[p][0] = 0;
			dynamic_pointer_save[p][1] = 0;
		}
		
		dynamic_pointer[4] = 0;	//a_horizontal
		dynamic_pointer[5] = 0;	//a_vertikal
		
		for (unsigned int p=0; p<=aop; p+=1) {
			dynamic_pointer_save[p][2] = 0;
			dynamic_pointer_save[p][3] = 0;
		}
		
		dynamic_pointer[6] = 0;	//y_horizontal
		dynamic_pointer[7] = 0;	//y_vertikal
		
		lim = 0;
		opt = 0;
		tac = 0;
		journey = 0;
		siz_m = 0;		//	
		siz_n = 0;		//
		number_1 = 0;
		number_2 = 0;
		number_3 = 0;
		number_4 = 0;
		ent = 0;
		num_temp = 0;
		limit_new = 0;		//if
		limit_at_all = 0;		//if
		w = 3;
		d = 2;
		e = 3;
		sup_num = 0;
		use_number = 1;
		back_opt = 10;
		beginningmenu = back_opt;	//auch hier
		gamemode = 0;
		menuoperator = 0;
		suprise = 0;
		
		scwhp = 1;
		spf = 5;
		rtc = 30;
		round_counter = 0;
		round_counter_before = 0;
		
		hboa = 1;
		precounter = 0;
		
		ttt = 0;
		time_warning = 0.0;
		time_saver = 0.0;
		warning_system = 0;
		
		exclude_counter = 0;
		
		player_counter = 0;
		rtp = 30;
		limit_at_all_saver = 0;
		
		opague = 0;
		
		//scanf("%u", &w); //test
		//printf ("	ok 5.3 \n");	//test
		
		for (unsigned int p=0; p<=9; p+=1) {
			pere[p] = 0;
			ability[p] = 0;
			Colored[p] = 0;
			ulcer_start[p] = 0;
			ulcer_lifes[p] = 0;
			out_counter[p] = 0;
			ges[p] = 0;
			var_[p] = 0;
			cons[p] = 0;
		}
		
		//scanf("%u", &w); //test
		//printf ("	ok 5.4 \n");	//test
		
		for (unsigned int p=1; p<=9; p+=1) {
			ulcer_lifes[p] = p-1;
		}
		
		//scanf("%u", &w); //test
		//printf ("	ok 5.5 \n");	//test
		
		if (same[0] == 0) {
			
			//Startmenü, Anfang
			
			if (playtime != 10) {
				printf("\n");
				printf("	Welcome to >Growth<. Have a nice game. \n");
				printf("\n");
			}
			
			//scanf("%u", &w); //test
			//printf ("	ok 6 \n");	//test
			
			while (beginningmenu == back_opt) {
				
				//scanf("%u", &w); //test
				//printf ("	ok 7 \n");	//test
				while ((gamemode < 1) || (gamemode > 12)) {
					
					printf("	Choose your gamemode\n  \n");

					
					printf("	Classic: 1\n	Collect: 2\n	Contact: 3\n	Fall   : 4\n	Fight  : 5\n	Hunt   : 6\n	Race   : 7\n	Rain   : 8\n	Arena  : 9\n  	Ulcer  : 10\n   	Dynamic: 11\n   	Survive: 12\n  \n");
					scanf("%u", &gamemode);
					printf("\n");
					//Players?
				}
				
				if (gamemode == 1) {
					m = 12;
					n = 8;
					siz_m = 10;
					siz_n = 6;
					limit_at_all = 20;
					limit_new = 10;
				} else if (gamemode == 2) {
					m = 11;
					n = 13;
					siz_m = 9;
					siz_n = 11;
					limit_at_all = 20;
					limit_new = 10;
				} else if (gamemode == 3) {
					m = 12;
					n = 18;
					siz_m = 10;
					siz_n = 16;
					limit_at_all = 30;
					limit_new = 15;
				} else if (gamemode == 4) {
					m = 8;
					n = 13;
					siz_m = 6;
					siz_n = 11;
					limit_at_all = 14;
					limit_new = 7;
				} else if (gamemode == 5) {
					m = 8;
					n = 8;
					siz_m = 6;
					siz_n = 6;
					limit_at_all = 10;
					limit_new = 5;
				} else if (gamemode == 6) {
					m = 9;
					n = 11;
					siz_m = 7;
					siz_n = 9;
					limit_at_all = 12;
					limit_new = 6;
				} else if (gamemode == 7) {
					m = 9;
					n = 21;
					siz_m = 7;
					siz_n = 19;
					limit_at_all = 14;
					limit_new = 7;
				} else if (gamemode == 8) {
					m = 8;
					n = 15;
					siz_m = 6;
					siz_n = 13;
					limit_at_all = 14;
					limit_new = 7;
				} else if (gamemode == 9) {
					m = 9;
					n = 9;
					siz_m = 7;
					siz_n = 7;
					limit_at_all = 16;
					limit_new = 8;
				} else if (gamemode == 10) {
					m = 8;
					n = 8;
					siz_m = 6;
					siz_n = 6;
					limit_at_all = 16;
					limit_new = 8;
				} else if (gamemode == 11) {
					m = 9;
					n = 13;
					siz_m = 7;
					siz_n = 11;
					limit_at_all = 20;
					limit_new = 10;
				} else if (gamemode == 12) {
					m = 13;
					n = 13;
					siz_m = 11;
					siz_n = 11;
					limit_at_all = 20;
					limit_new = 10;
					
					for (unsigned int p=1; p<=3; p+=1) {
						information_code[p] = 1;
					}
				}
				
				while (beginningmenu != 1){
			
					printf("	Start game: 1\n \n	Game size : 2\n	Journey   : 3\n	Tactics   : 4\n	Random    : 5\n	Limits    : 6\n 	Time	  : 7\n 	Color	  : 8\n 	Opague	  : 9\n \n	Back      : %u\n \n", back_opt);	//synchronisiere stets back mit beginningmenu
					if (gamemode == 4) {
						printf("	Points for win: %u \n", back_opt+1);
						printf("	Turns per drop: %u \n", back_opt+2);
						printf("	Speed of the #-square : %u \n", back_opt+3);
					}
					if (gamemode == 6) {
						printf("	Hunt-conditions: %u \n", back_opt+1);
						printf("	Number of players: %u \n", back_opt+2);	// synchronisiere diese ebenfalls
					}
					if (gamemode == 7) {
						printf("	Frequence : %u \n", back_opt+1);
					}
					if (gamemode == 8) {
						printf("	Rain-Modus: %u \n", back_opt+1);
					}
					if (gamemode == 9) {
						printf("	Abilities : %u \n", back_opt+1);
						printf("	Number of players: %u \n", back_opt+2);
						printf("	Rounds to play	 : %u \n", back_opt+3);
					}
					if (gamemode == 10) {
						printf("	Lifes	  : %u \n", back_opt+1);
						printf("	Number of players: %u \n", back_opt+2);
						printf("	Rounds to play	 : %u \n", back_opt+3);
						printf("	K.O.-Mode : %u \n", back_opt+4);
					}
					if (gamemode == 11) {
						printf("	Gravity	  : %u \n", back_opt+1);
						printf("	Number of players: %u \n", back_opt+2);
						printf("	Range	  : %u \n", back_opt+3);
						printf("	Coefficient : %u \n", back_opt+4);
					}
					if (gamemode == 12) {
						printf("	obstacles  : %u \n", back_opt+1);
						printf("	Number of players: %u \n", back_opt+2);
					}
					
					printf("\n");
					scanf("%u", &beginningmenu);
					printf("\n");
				
					if (beginningmenu == 1){
						printf("	Let's start! \n");
					}
				
					if (beginningmenu == 2){
						if ((gamemode == 6)||(gamemode == 9)||(gamemode == 10)||(gamemode == 11)||(gamemode == 12)) {
							printf("	This only works if the number of players is correct! \n");
						}
						
						if (gamemode == 1){
							printf(" Zeilen: >=6				(normal: 10) \n Spalten: >=4, mod2==0				(normal: 6) \n");
							scanf("%u %u", &siz_m, &siz_n);
							printf("\n");
						
							if ((siz_m<6)||(siz_n<4)||(siz_n%2==1)){
								printf("	You missed the assertions !!! \n");
								printf("\n");
								siz_m = 10;
								siz_n = 6;
							} else {
								m = siz_m + 2;
								n = siz_n + 2;
							}
						} else if (gamemode == 2) {
							printf(" Zeilen: >=7, mod2==1				(normal: 9) \n Spalten: >=7, mod2==1				(normal: 11) \n");
							scanf("%u %u", &siz_m, &siz_n);
							printf("\n");
						
							if ((siz_m<7)||(siz_n<7)||(siz_n%2==0)||(siz_m%2==0)){
								printf("	You missed the assertions !!! \n");
								printf("\n");
								siz_m = 9;
								siz_n = 11;
							} else {
								m = siz_m + 2;
								n = siz_n + 2;
							}
						} else if (gamemode == 3) {
							printf(" Zeilen: >=6				(normal: 10) \n Spalten: >=4, mod2==0				(normal: 16) \n");
							scanf("%u %u", &siz_m, &siz_n);
							printf("\n");
						
							if ((siz_m<6)||(siz_n<4)||(siz_n%2==1)){
								printf("	You missed the assertions !!! \n");
								printf("\n");
								siz_m = 10;
								siz_n = 16;
							} else {
								m = siz_m + 2;
								n = siz_n + 2;
							}
						} else if (gamemode == 4) {
							printf(" Zeilen: >=3				(normal: 6) \n Spalten: >=7, mod2==1				(normal: 11) \n");
							scanf("%u %u", &siz_m, &siz_n);
							printf("\n");
						
							if ((siz_m<3)||(siz_n<7)||(siz_n%2==0)){
								printf("	You missed the assertions !!! \n");
								printf("\n");
								siz_m = 6;
								siz_n = 11;
							} else {
								m = siz_m + 2;
								n = siz_n + 2;
							}
						} else if (gamemode == 5) {
							printf(" Zeilen: >=6				(normal: 6) \n Spalten: >=4, mod2==0				(normal: 6) \n");
							scanf("%u %u", &siz_m, &siz_n);
							printf("\n");
						
							if ((siz_m<6)||(siz_n<4)||(siz_n%2==1)){
								printf("	You missed the assertions !!! \n");
								printf("\n");
								siz_m = 6;
								siz_n = 6;
							} else {
								m = siz_m + 2;
								n = siz_n + 2;
							}
						} else if (gamemode == 6) {
							if (number_of_players == 2) {
								printf(" Zeilen: >=3, mod2==1				(normal: 7) \n Spalten: >=7, mod2==1				(normal: 9) \n");
								scanf("%u %u", &siz_m, &siz_n);
								printf("\n");
							
								if ((siz_m<3)||(siz_n<7)||(siz_m%2==0)||(siz_n%2==0)){
									printf("	You missed the assertions !!! \n");
									printf("\n");
									siz_m = 7;
									siz_n = 9;
								} else {
									m = siz_m + 2;
									n = siz_n + 2;
								}
							} else if (number_of_players == 3) {
								printf(" Zeilen: >=3, mod2==1				(normal: 7) \n Spalten: >=9, mod2==1				(normal: 13) \n");
								scanf("%u %u", &siz_m, &siz_n);
								printf("\n");
							
								if ((siz_m<3)||(siz_n<9)||(siz_m%2==0)||(siz_n%2==0)){
									printf("	You missed the assertions !!! \n");
									printf("\n");
									siz_m = 7;
									siz_n = 13;
								} else {
									m = siz_m + 2;
									n = siz_n + 2;
								}
							} else if (number_of_players == 4) {
								printf(" Zeilen: >=7, mod2==1				(normal: 10) \n Spalten: >=9, mod2==1				(normal: 13) \n");
								scanf("%u %u", &siz_m, &siz_n);
								printf("\n");
							
								if ((siz_m<7)||(siz_n<9)||(siz_m%2==0)||(siz_n%2==0)){
									printf("	You missed the assertions !!! \n");
									printf("\n");
									siz_m = 11;
									siz_n = 13;
								} else {
									m = siz_m + 2;
									n = siz_n + 2;
								}
							} else if (number_of_players == 5) {
								printf(" Zeilen: >=9, mod2==1				(normal: 13) \n Spalten: >=9, mod2==1				(normal: 13) \n");
								scanf("%u %u", &siz_m, &siz_n);
								printf("\n");
							
								if ((siz_m<9)||(siz_n<9)||(siz_m%2==0)||(siz_n%2==0)){
									printf("	You missed the assertions !!! \n");
									printf("\n");
									siz_m = 13;
									siz_n = 13;
								} else {
									m = siz_m + 2;
									n = siz_n + 2;
								}
							} else if (number_of_players == 6) {
								printf(" Zeilen: >=9, mod2==1				(normal: 13) \n Spalten: >=10, mod2==0				(normal: 16) \n");
								scanf("%u %u", &siz_m, &siz_n);
								printf("\n");
							
								if ((siz_m<9)||(siz_n<10)||(siz_m%2==0)||(siz_n%2==1)){
									printf("	You missed the assertions !!! \n");
									printf("\n");
									siz_m = 13;
									siz_n = 16;
								} else {
									m = siz_m + 2;
									n = siz_n + 2;
								}
							} else if (number_of_players == 7) {
								printf(" Zeilen: >=9, mod2==1				(normal: 15) \n Spalten: >=13, mod2==1				(normal: 19) \n");
								scanf("%u %u", &siz_m, &siz_n);
								printf("\n");
							
								if ((siz_m<9)||(siz_n<13)||(siz_m%2==0)||(siz_n%2==0)){
									printf("	You missed the assertions !!! \n");
									printf("\n");
									siz_m = 15;
									siz_n = 19;
								} else {
									m = siz_m + 2;
									n = siz_n + 2;
								}
							} else if (number_of_players == 8) {
								printf(" Zeilen: >=10, mod2==0				(normal: 16) \n Spalten: >=13, mod2==1				(normal: 21) \n");
								scanf("%u %u", &siz_m, &siz_n);
								printf("\n");
							
								if ((siz_m<9)||(siz_n<13)||(siz_m%2==1)||(siz_n%2==0)){
									printf("	You missed the assertions !!! \n");
									printf("\n");
									siz_m = 16;
									siz_n = 21;
								} else {
									m = siz_m + 2;
									n = siz_n + 2;
								}
							} else if (number_of_players == 9) {
								printf(" Zeilen: >=13, mod2==1				(normal: 21) \n Spalten: >=13, mod2==1				(normal: 21) \n");
								scanf("%u %u", &siz_m, &siz_n);
								printf("\n");
							
								if ((siz_m<9)||(siz_n<13)||(siz_m%2==0)||(siz_n%2==0)){
									printf("	You missed the assertions !!! \n");
									printf("\n");
									siz_m = 21;
									siz_n = 21;
								} else {
									m = siz_m + 2;
									n = siz_n + 2;
								}
							}
						} else if (gamemode == 7) {
							printf(" Zeilen: >=7				(normal: 7) \n Spalten: >=5, mod2==1				(normal: 19) \n");
							scanf("%u %u", &siz_m, &siz_n);
							printf("\n");
						
							if ((siz_m<7)||(siz_n<5)||(siz_n%2==0)){
								printf("	You missed the assertions !!! \n");
								printf("\n");
								siz_m = 7;
								siz_n = 19;
							} else {
								m = siz_m + 2;
								n = siz_n + 2;
							}
						} else if (gamemode == 8) {
							printf(" Zeilen: >=3				(normal: 6) \n");
							scanf("%u", &siz_m);
							printf("\n");
						
							if (siz_m<3){
								printf("	You missed the assertions !!! \n");
								printf("\n");
								siz_m = 6;
							} else {
								m = siz_m + 2;
							}
						} else if (gamemode == 9) {
							if (number_of_players == 2) {
								printf(" Zeilen: >=3, mod2==1				(normal: 7) \n Spalten: >=7, mod2==1				(normal: 7) \n");
								scanf("%u %u", &siz_m, &siz_n);
								printf("\n");
							
								if ((siz_m<3)||(siz_n<7)||(siz_m%2==0)||(siz_n%2==0)){
									printf("	You missed the assertions !!! \n");
									printf("\n");
									siz_m = 7;
									siz_n = 7;
								} else {
									m = siz_m + 2;
									n = siz_n + 2;
								}
							} else if (number_of_players == 3) {
								printf(" Zeilen: >=7, mod2==1				(normal: 7) \n Spalten: >=7, mod2==1				(normal: 7) \n");
								scanf("%u %u", &siz_m, &siz_n);
								printf("\n");
							
								if ((siz_m<7)||(siz_n<7)||(siz_m%2==0)||(siz_n%2==0)){
									printf("	You missed the assertions !!! \n");
									printf("\n");
									siz_m = 7;
									siz_n = 7;
								} else {
									m = siz_m + 2;
									n = siz_n + 2;
								}
							} else if (number_of_players == 4) {
								printf(" Zeilen: >=9, mod2==1				(normal: 9) \n Spalten: >=9, mod2==1				(normal: 9) \n");
								scanf("%u %u", &siz_m, &siz_n);
								printf("\n");
							
								if ((siz_m<9)||(siz_n<9)||(siz_m%2==0)||(siz_n%2==0)){
									printf("	You missed the assertions !!! \n");
									printf("\n");
									siz_m = 9;
									siz_n = 9;
								} else {
									m = siz_m + 2;
									n = siz_n + 2;
								}
							} else if (number_of_players == 5) {
								printf(" Zeilen: >=8, mod2==0				(normal: 10) \n Spalten: >=8, mod2==0				(normal: 10) \n");
								scanf("%u %u", &siz_m, &siz_n);
								printf("\n");
							
								if ((siz_m<8)||(siz_n<8)||(siz_m%2==1)||(siz_n%2==1)){
									printf("	You missed the assertions !!! \n");
									printf("\n");
									siz_m = 10;
									siz_n = 10;
								} else {
									m = siz_m + 2;
									n = siz_n + 2;
								}
							} else if (number_of_players == 6) {
								printf(" Zeilen: >=7, mod2==1				(normal: 11) \n Spalten: >=13, mod2==1				(normal: 11) \n");
								scanf("%u %u", &siz_m, &siz_n);
								printf("\n");
							
								if ((siz_m<7)||(siz_n<13)||(siz_m%2==0)||(siz_n%2==0)){
									printf("	You missed the assertions !!! \n");
									printf("\n");
									siz_m = 11;
									siz_n = 11;
								} else {
									m = siz_m + 2;
									n = siz_n + 2;
								}
							} else if (number_of_players == 7) {
								printf(" Zeilen: >=8, mod2==0				(normal: 12) \n Spalten: >=12, mod2==0				(normal: 12) \n");
								scanf("%u %u", &siz_m, &siz_n);
								printf("\n");
							
								if ((siz_m<4)||(siz_n<12)||(siz_m%2==1)||(siz_n%2==1)){
									printf("	You missed the assertions !!! \n");
									printf("\n");
									siz_m = 12;
									siz_n = 12;
								} else {
									m = siz_m + 2;
									n = siz_n + 2;
								}
							} else if (number_of_players == 8) {
								printf(" Zeilen: >=12, mod2==0				(normal: 14) \n Spalten: >=12, mod2==0				(normal: 14) \n");
								scanf("%u %u", &siz_m, &siz_n);
								printf("\n");
							
								if ((siz_m<12)||(siz_n<12)||(siz_m%2==1)||(siz_n%2==1)){
									printf("	You missed the assertions !!! \n");
									printf("\n");
									siz_m = 14;
									siz_n = 14;
								} else {
									m = siz_m + 2;
									n = siz_n + 2;
								}
							} else if (number_of_players == 9) {
								printf(" Zeilen: >=12, mod2==0				(normal: 14) \n Spalten: >=12, mod2==0				(normal: 14) \n");
								scanf("%u %u", &siz_m, &siz_n);
								printf("\n");
							
								if ((siz_m<12)||(siz_n<12)||(siz_m%2==1)||(siz_n%2==1)){
									printf("	You missed the assertions !!! \n");
									printf("\n");
									siz_m = 14;
									siz_n = 14;
								} else {
									m = siz_m + 2;
									n = siz_n + 2;
								}
							}
						} else if (gamemode == 10) {
							if (number_of_players == 2) {
								printf(" Zeilen: >=6				(normal: 6) \n Spalten: >=6				(normal: 6) \n");
								scanf("%u %u", &siz_m, &siz_n);
								printf("\n");
							
								if ((siz_m<6)||(siz_n<6)){
									printf("	You missed the assertions !!! \n");
									printf("\n");
									siz_m = 6;
									siz_n = 6;
								} else {
									m = siz_m + 2;
									n = siz_n + 2;
								}
							} else if (number_of_players == 3) {
								printf(" Zeilen: >=7				(normal: 7) \n Spalten: >=7				(normal: 7) \n");
								scanf("%u %u", &siz_m, &siz_n);
								printf("\n");
							
								if ((siz_m<7)||(siz_n<7)){
									printf("	You missed the assertions !!! \n");
									printf("\n");
									siz_m = 7;
									siz_n = 7;
								} else {
									m = siz_m + 2;
									n = siz_n + 2;
								}
							} else if (number_of_players == 4) {
								printf(" Zeilen: >=9				(normal: 9) \n Spalten: >=9				(normal: 9) \n");
								scanf("%u %u", &siz_m, &siz_n);
								printf("\n");
							
								if ((siz_m<9)||(siz_n<9)){
									printf("	You missed the assertions !!! \n");
									printf("\n");
									siz_m = 9;
									siz_n = 9;
								} else {
									m = siz_m + 2;
									n = siz_n + 2;
								}
							} else if (number_of_players == 5) {
								printf(" Zeilen: >=10				(normal: 10) \n Spalten: >=10				(normal: 10) \n");
								scanf("%u %u", &siz_m, &siz_n);
								printf("\n");
							
								if ((siz_m<10)||(siz_n<10)){
									printf("	You missed the assertions !!! \n");
									printf("\n");
									siz_m = 10;
									siz_n = 10;
								} else {
									m = siz_m + 2;
									n = siz_n + 2;
								}
							} else if (number_of_players == 6) {
								printf(" Zeilen: >=11				(normal: 11) \n Spalten: >=11				(normal: 11) \n");
								scanf("%u %u", &siz_m, &siz_n);
								printf("\n");
							
								if ((siz_m<11)||(siz_n<11)){
									printf("	You missed the assertions !!! \n");
									printf("\n");
									siz_m = 11;
									siz_n = 11;
								} else {
									m = siz_m + 2;
									n = siz_n + 2;
								}
							} else if (number_of_players == 7) {
								printf(" Zeilen: >=12				(normal: 12) \n Spalten: >=12				(normal: 12) \n");
								scanf("%u %u", &siz_m, &siz_n);
								printf("\n");
							
								if ((siz_m<12)||(siz_n<12)){
									printf("	You missed the assertions !!! \n");
									printf("\n");
									siz_m = 12;
									siz_n = 12;
								} else {
									m = siz_m + 2;
									n = siz_n + 2;
								}
							} else if (number_of_players == 8) {
								printf(" Zeilen: >=13				(normal: 13) \n Spalten: >=13				(normal: 13) \n");
								scanf("%u %u", &siz_m, &siz_n);
								printf("\n");
							
								if ((siz_m<13)||(siz_n<13)){
									printf("	You missed the assertions !!! \n");
									printf("\n");
									siz_m = 13;
									siz_n = 13;
								} else {
									m = siz_m + 2;
									n = siz_n + 2;
								}
							} else if (number_of_players == 9) {
								printf(" Zeilen: >=14				(normal: 14) \n Spalten: >=14				(normal: 14) \n");
								scanf("%u %u", &siz_m, &siz_n);
								printf("\n");
							
								if ((siz_m<14)||(siz_n<14)){
									printf("	You missed the assertions !!! \n");
									printf("\n");
									siz_m = 14;
									siz_n = 14;
								} else {
									m = siz_m + 2;
									n = siz_n + 2;
								}
							}
							
						} else if (gamemode == 11) {
							if (number_of_players == 2) {
								printf(" Zeilen: >=3, mod2==1				(normal: 7) \n Spalten: >=7, mod2==1				(normal: 11) \n");
								scanf("%u %u", &siz_m, &siz_n);
								printf("\n");
							
								if ((siz_m<3)||(siz_n<7)||(siz_m%2==0)||(siz_n%2==0)){
									printf("	You missed the assertions !!! \n");
									printf("\n");
									siz_m = 7;
									siz_n = 11;
								} else {
									m = siz_m + 2;
									n = siz_n + 2;
								}
							} else if (number_of_players == 3) {
								printf(" Zeilen: >=5, mod2==1				(normal: 9) \n Spalten: >=7, mod2==1				(normal: 11) \n");
								scanf("%u %u", &siz_m, &siz_n);
								printf("\n");
							
								if ((siz_m<5)||(siz_n<7)||(siz_m%2==0)||(siz_n%2==0)){
									printf("	You missed the assertions !!! \n");
									printf("\n");
									siz_m = 9;
									siz_n = 11;
								} else {
									m = siz_m + 2;
									n = siz_n + 2;
								}
							} else if (number_of_players == 4) {
								printf(" Zeilen: >=7, mod2==1				(normal: 11) \n Spalten: >=7, mod2==1				(normal: 11) \n");
								scanf("%u %u", &siz_m, &siz_n);
								printf("\n");
							
								if ((siz_m<7)||(siz_n<7)||(siz_m%2==0)||(siz_n%2==0)){
									printf("	You missed the assertions !!! \n");
									printf("\n");
									siz_m = 11;
									siz_n = 11;
								} else {
									m = siz_m + 2;
									n = siz_n + 2;
								}
							} else if (number_of_players == 5) {
								printf(" Zeilen: >=7, mod2==1				(normal: 11) \n Spalten: >=7, mod2==1				(normal: 15) \n");
								scanf("%u %u", &siz_m, &siz_n);
								printf("\n");
							
								if ((siz_m<7)||(siz_n<7)||(siz_m%2==0)||(siz_n%2==0)){
									printf("	You missed the assertions !!! \n");
									printf("\n");
									siz_m = 11;
									siz_n = 15;
								} else {
									m = siz_m + 2;
									n = siz_n + 2;
								}
							} else if (number_of_players == 6) {
								printf(" Zeilen: >=9, mod2==1				(normal: 15) \n Spalten: >=9, mod2==1				(normal: 15) \n");
								scanf("%u %u", &siz_m, &siz_n);
								printf("\n");
							
								if ((siz_m<9)||(siz_n<9)||(siz_m%2==0)||(siz_n%2==0)){
									printf("	You missed the assertions !!! \n");
									printf("\n");
									siz_m = 15;
									siz_n = 15;
								} else {
									m = siz_m + 2;
									n = siz_n + 2;
								}
							} else if (number_of_players == 7) {
								printf(" Zeilen: >=9, mod2==1				(normal: 15) \n Spalten: >=9, mod2==1				(normal: 15) \n");
								scanf("%u %u", &siz_m, &siz_n);
								printf("\n");
							
								if ((siz_m<9)||(siz_n<9)||(siz_m%2==0)||(siz_n%2==0)){
									printf("	You missed the assertions !!! \n");
									printf("\n");
									siz_m = 15;
									siz_n = 15;
								} else {
									m = siz_m + 2;
									n = siz_n + 2;
								}
							} else if (number_of_players == 8) {
								printf(" Zeilen: >=9, mod2==1				(normal: 17) \n Spalten: >=9, mod2==1				(normal: 17) \n");
								scanf("%u %u", &siz_m, &siz_n);
								printf("\n");
							
								if ((siz_m<9)||(siz_n<9)||(siz_m%2==0)||(siz_n%2==0)){
									printf("	You missed the assertions !!! \n");
									printf("\n");
									siz_m = 17;
									siz_n = 17;
								} else {
									m = siz_m + 2;
									n = siz_n + 2;
								}
							} else if (number_of_players == 9) {
								printf(" Zeilen: >=11, mod2==1				(normal: 17) \n Spalten: >=11, mod2==1				(normal: 17) \n");
								scanf("%u %u", &siz_m, &siz_n);
								printf("\n");
							
								if ((siz_m<11)||(siz_n<11)||(siz_m%2==0)||(siz_n%2==0)){
									printf("	You missed the assertions !!! \n");
									printf("\n");
									siz_m = 17;
									siz_n = 17;
								} else {
									m = siz_m + 2;
									n = siz_n + 2;
								}
							}
						} else if (gamemode == 12) {
							if (number_of_players == 1) {
								printf(" Zeilen: >=3				(normal: 10) \n Spalten: >=3				(normal: 10) \n");
								scanf("%u %u", &siz_m, &siz_n);
								printf("\n");
							
								if ((siz_m<3)||(siz_n<3)){
									printf("	You missed the assertions !!! \n");
									printf("\n");
									siz_m = 10;
									siz_n = 10;
								} else {
									m = siz_m + 2;
									n = siz_n + 2;
								}
							} else if (number_of_players == 2) {
								printf(" Zeilen: >=3				(normal: 11) \n Spalten: >=6				(normal: 11) \n");
								scanf("%u %u", &siz_m, &siz_n);
								printf("\n");
							
								if ((siz_m<3)||(siz_n<6)){
									printf("	You missed the assertions !!! \n");
									printf("\n");
									siz_m = 11;
									siz_n = 11;
								} else {
									m = siz_m + 2;
									n = siz_n + 2;
								}
							} else if (number_of_players == 3) {
								printf(" Zeilen: >=6				(normal: 12) \n Spalten: >=6				(normal: 12) \n");
								scanf("%u %u", &siz_m, &siz_n);
								printf("\n");
							
								if ((siz_m<6)||(siz_n<6)){
									printf("	You missed the assertions !!! \n");
									printf("\n");
									siz_m = 12;
									siz_n = 12;
								} else {
									m = siz_m + 2;
									n = siz_n + 2;
								}
							} else if (number_of_players == 4) {
								printf(" Zeilen: >=6				(normal: 13) \n Spalten: >=6				(normal: 13) \n");
								scanf("%u %u", &siz_m, &siz_n);
								printf("\n");
							
								if ((siz_m<6)||(siz_n<6)){
									printf("	You missed the assertions !!! \n");
									printf("\n");
									siz_m = 13;
									siz_n = 13;
								} else {
									m = siz_m + 2;
									n = siz_n + 2;
								}
							} else if (number_of_players == 5) {
								printf(" Zeilen: >=7, mod2==1				(normal: 15) \n Spalten: >=7, mod2==1				(normal: 15) \n");
								scanf("%u %u", &siz_m, &siz_n);
								printf("\n");
							
								if ((siz_m<7)||(siz_n<7)||(siz_m%2==0)||(siz_n%2==0)){
									printf("	You missed the assertions !!! \n");
									printf("\n");
									siz_m = 15;
									siz_n = 15;
								} else {
									m = siz_m + 2;
									n = siz_n + 2;
								}
							} else if (number_of_players == 6) {
								printf(" Zeilen: >=9, mod2==1				(normal: 15) \n Spalten: >=6				(normal: 15) \n");
								scanf("%u %u", &siz_m, &siz_n);
								printf("\n");
							
								if ((siz_m<9)||(siz_n<6)||(siz_m%2==0)){
									printf("	You missed the assertions !!! \n");
									printf("\n");
									siz_m = 15;
									siz_n = 15;
								} else {
									m = siz_m + 2;
									n = siz_n + 2;
								}
							} else if (number_of_players == 7) {
								printf(" Zeilen: >=9, mod2==1				(normal: 17) \n Spalten: >=9, mod2==1				(normal: 17) \n");
								scanf("%u %u", &siz_m, &siz_n);
								printf("\n");
							
								if ((siz_m<9)||(siz_n<9)||(siz_m%2==0)||(siz_n%2==0)){
									printf("	You missed the assertions !!! \n");
									printf("\n");
									siz_m = 17;
									siz_n = 17;
								} else {
									m = siz_m + 2;
									n = siz_n + 2;
								}
							} else if (number_of_players == 8) {
								printf(" Zeilen: >=9, mod2==1				(normal: 17) \n Spalten: >=9, mod2==1				(normal: 17) \n");
								scanf("%u %u", &siz_m, &siz_n);
								printf("\n");
							
								if ((siz_m<9)||(siz_n<9)||(siz_m%2==0)||(siz_n%2==0)){
									printf("	You missed the assertions !!! \n");
									printf("\n");
									siz_m = 17;
									siz_n = 17;
								} else {
									m = siz_m + 2;
									n = siz_n + 2;
								}
							} else if (number_of_players == 9) {
								printf(" Zeilen: >=9, mod2==1				(normal: 17) \n Spalten: >=9, mod2==1				(normal: 17) \n");
								scanf("%u %u", &siz_m, &siz_n);
								printf("\n");
							
								if ((siz_m<9)||(siz_n<9)||(siz_m%2==0)||(siz_n%2==0)){
									printf("	You missed the assertions !!! \n");
									printf("\n");
									siz_m = 17;
									siz_n = 17;
								} else {
									m = siz_m + 2;
									n = siz_n + 2;
								}
							}
						}
					}
				
					if (beginningmenu == 3){		//Growth
						if (journey == 1){
							journey = 0;
							printf("	journey deactivated \n");
						} else if (journey == 0){
							journey = 1;
							printf("	journey activated \n");
						}
						printf("\n");
					}
					
					if (beginningmenu == 4){
						opt = 0;
						printf("	Do not activate Random, it will replace the Tactics-Mode! \n");
						printf("	Stack of every number until refresh: \n");
						scanf("%u", &tac);
						printf("\n");
					}
				
					if ((beginningmenu == 5)&&(gamemode != 6)&&(gamemode != 9)&&(gamemode != 10)&(gamemode != 11)&(gamemode != 12)){
						
						tac = 0;
						printf("	Do not activate Tactics, it will replace the Random-Mode! \n");
						printf("	Random activated \n");
						printf("	A Player :	Give me three random numbers from 1 to 60 \n");
						scanf("%u %u %u", &number_1, &number_2, &number_3);
						printf("\n");
						if ((number_1==0)||(number_2==0)||(number_3==0)||(number_1>60)||(number_2>60)||(number_3>60)){
							printf("	You missed the assertions !!! \n");
							printf("\n");
							beginningmenu = 0;
						} else {
							printf("\n");
							printf("	The other Player :	Give me a random number from 1 to 60 \n");
							scanf("%u", &number_4);
							printf("\n");
							if ((number_4<1)||(number_4>60)){
								printf("	You missed the assertions !!! \n");
								printf("\n");
								beginningmenu = 0;
							} else {
								number_4 = ((number_4%6)+1)%3 + 1;
								if (number_4 == 1){
									num_temp = (number_1 % 2)+(number_2 % 3)+2*(number_3 % 3);
									if (num_temp <= 1){
										use_number = 1;
									} else if (num_temp >= 6){
										use_number = 6;
									} else {
										use_number = num_temp;
									}
								}
								if (number_4 == 2){
									num_temp = (number_2 % 2)+(number_1 % 3)+2*(number_3 % 3);
									if (num_temp <= 1){
										use_number = 1;
									} else if (num_temp >= 6){
										use_number = 6;
									} else {
										use_number = num_temp;
									}
								}
								if (number_4 == 3){
									num_temp = (number_3 % 2)+(number_1 % 3)+2*(number_2 % 3);
									if (num_temp <= 1){
										use_number = 1;
									} else if (num_temp >= 6){
										use_number = 6;
									} else {
										use_number = num_temp;
									}
								}
							
								opt = 5;
							}
						}
						
						
					} else if ((beginningmenu == 5)&&((gamemode == 6)||(gamemode == 9)||(gamemode == 10)||(gamemode == 11)||(gamemode == 12))) {
						tac = 0;
						
						printf("	This only works if the number of players is correct! \n");
						
						printf("	Random activated \n");
						printf("	Please get all a number from 0 to %u, not the same, it will have no effect further on. \n", number_of_players-1);
						printf("	Give me three random numbers from 1 to 60 \n");
						scanf("%u %u %u", &number_1, &number_2, &number_3);
						if ((number_1==0)||(number_2==0)||(number_3==0)||(number_1>60)||(number_2>60)||(number_3>60)){
							printf("	You missed the assertions !!! \n");
						} else {
							printf("	Give me another random number from 1 to 60 \n");
							scanf("%u", &number_4);
							if ((number_4<1)||(number_4>60)){
								printf("	You missed the assertions !!! \n");
							} else {
								number_4 = ((number_4%6)+1)%3 + 1;
								if (number_4 == 1){
									num_temp = (number_1 % 2)+(number_2 % 3)+2*(number_3 % 3);
									if (num_temp <= 1){
										use_number = 1;
									} else if (num_temp >= 6){
										use_number = 6;
									} else {
										use_number = num_temp;
									}
								}
								if (number_4 == 2){
									num_temp = (number_2 % 2)+(number_1 % 3)+2*(number_3 % 3);
									if (num_temp <= 1){
										use_number = 1;
									} else if (num_temp >= 6){
										use_number = 6;
									} else {
										use_number = num_temp;
									}
								}
								if (number_4 == 3){
									num_temp = (number_3 % 2)+(number_1 % 3)+2*(number_2 % 3);
									if (num_temp <= 1){
										use_number = 1;
									} else if (num_temp >= 6){
										use_number = 6;
									} else {
										use_number = num_temp;
									}
								}
								unsigned int Row[number_of_players];
								for (unsigned int y = 0; y < number_of_players; y+=1){
									Row[y] = 0;
								}
								unsigned int Verteilung;
								Verteilung = (number_1 + number_2 + number_3 + number_4)%(number_of_players);
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
										if (gamemode == 6) {
											printf("	%u = Player 1, you will be hunted. (##) \n", y);
										} else if (gamemode == 9) {
											printf("	%u = Player 1. \n", y);
										} else if ((gamemode == 10)||(gamemode == 11)||(gamemode == 12)) {
											printf("	%u = Player 1, (11) \n", y);
										}
									} else if (Row[y] == 1){
										if (gamemode == 6) {
											printf("	%u = Player 2, (AA) \n", y);
										} else if (gamemode == 9) {
											printf("	%u = Player 2. \n", y);
										} else if ((gamemode == 10)||(gamemode == 11)||(gamemode == 12)) {
											printf("	%u = Player 2, (22) \n", y);
										}
									} else if (Row[y] == 2){
										if (gamemode == 6) {
											printf("	%u = Player 3, (BB) \n", y);
										} else if (gamemode == 9) {
											printf("	%u = Player 3. \n", y);
										} else if ((gamemode == 10)||(gamemode == 11)||(gamemode == 12)) {
											printf("	%u = Player 3, (33) \n", y);
										}
									} else if (Row[y] == 3){
										if (gamemode == 6) {
											printf("	%u = Player 4, (CC) \n", y);
										} else if (gamemode == 9) {
											printf("	%u = Player 4. \n", y);
										} else if ((gamemode == 10)||(gamemode == 11)||(gamemode == 12)) {
											printf("	%u = Player 4, (44) \n", y);
										}
									} else if (Row[y] == 4){
										if (gamemode == 6) {
											printf("	%u = Player 5, (DD) \n", y);
										} else if (gamemode == 9) {
											printf("	%u = Player 5. \n", y);
										} else if ((gamemode == 10)||(gamemode == 11)||(gamemode == 12)) {
											printf("	%u = Player 5, (55) \n", y);
										}
									} else if (Row[y] == 5){
										if (gamemode == 6) {
											printf("	%u = Player 6, (EE) \n", y);
										} else if (gamemode == 9) {
											printf("	%u = Player 6. \n", y);
										} else if ((gamemode == 10)||(gamemode == 11)||(gamemode == 12)) {
											printf("	%u = Player 6, (66) \n", y);
										}
									} else if (Row[y] == 6){
										if (gamemode == 6) {
											printf("	%u = Player 7, (GG) \n", y);
										} else if (gamemode == 9) {
											printf("	%u = Player 7. \n", y);
										} else if ((gamemode == 10)||(gamemode == 11)||(gamemode == 12)) {
											printf("	%u = Player 7, (77) \n", y);
										}
									} else if (Row[y] == 7){
										if (gamemode == 6) {
											printf("	%u = Player 8, (HH) \n", y);
										} else if (gamemode == 9) {
											printf("	%u = Player 8. \n", y);
										} else if ((gamemode == 10)||(gamemode == 11)||(gamemode == 12)) {
											printf("	%u = Player 8, (88) \n", y);
										}
									} else if (Row[y] == 8){
										if (gamemode == 6) {
											printf("	%u = Player 9, (II) \n", y);
										} else if (gamemode == 9) {
											printf("	%u = Player 9. \n", y);
										} else if ((gamemode == 10)||(gamemode == 11)||(gamemode == 12)) {
											printf("	%u = Player 9, (99) \n", y);
										}
									}
								}
							}
						}
						opt = 5;
						
					}
					
					if (beginningmenu == 6){
						if ((gamemode == 1)||(gamemode == 2)) {
							printf("	limit_new < limit_at_all - 4 	!	\n");
							printf("	Change limit_new: 1 \n	Change limit_at_all: 2 \n	Change both: 3 \n");
							scanf("%u", &lim);
							printf("\n");
						
							if (lim == 1){
								printf("	limit_new:		(normal: 10) \n");
								scanf("%u", &limit_new);
								printf("\n");
							}
							if (lim == 2){
								printf("	limit_at_all:		(normal: 20) \n");
								scanf("%u", &limit_at_all);
								printf("\n");
							}
							if (lim == 3){
								printf("	limit_new:				(normal: 10) \n	limit_at_all:				(normal: 20) \n");
								scanf("%u %u", &limit_new, &limit_at_all);
								printf("\n");
							}
							if (limit_new >= limit_at_all - 4) {
								limit_at_all = limit_new + 5;
							}
							
						} else if (gamemode == 3) {
							printf("	limit_new: 1		limit_at_all: 2		both: 3\n");
							scanf("%u", &lim);
							
							if (lim == 1){
								printf("	limit_new: 			(normal: 15) \n");
								scanf("%u", &limit_new);
							}
							if (lim == 2){
								printf("	limit_at_all: 			(normal: 30) \n");
								scanf("%u", &limit_at_all);
							}
							if (lim == 3){
								printf("	limit_new:				(normal: 15) \n	limit_at_all:				(normal: 30) \n");
								scanf("%u %u", &limit_new, &limit_at_all);
							}
						} else if ((gamemode == 4)||(gamemode == 7)||(gamemode == 8)) {
							printf("	limit_new < limit_at_all - 4 	!	\n");
							printf("	limit_new: 1		limit_at_all: 2		both: 3\n");
							scanf("%u", &lim);
							
							if (lim == 1){
								printf("	limit_new: 			(normal: 7) \n");
								scanf("%u", &limit_new);
							}
							if (lim == 2){
								printf("	limit_at_all: 			(normal: 14) \n");
								scanf("%u", &limit_at_all);
							}
							if (lim == 3){
								printf("	limit_new:				(normal: 7) \n	limit_at_all:				(normal: 14) \n");
								scanf("%u %u", &limit_new, &limit_at_all);
							}
							if (limit_new >= limit_at_all - 4) {
								limit_at_all = limit_new + 5;
							}
						} else if (gamemode == 5) {
							printf("	limit_new < limit_at_all - 4 	!	\n");
							printf("	limit_new: 1		limit_at_all: 2		both: 3\n");
							scanf("%u", &lim);
							
							if (lim == 1){
								printf("	limit_new: 			(normal: 5) \n");
								scanf("%u", &limit_new);
							}
							if (lim == 2){
								printf("	limit_at_all: 			(normal: 10) \n");
								scanf("%u", &limit_at_all);
							}
							if (lim == 3){
								printf("	limit_new:				(normal: 5) \n	limit_at_all:				(normal: 10) \n");
								scanf("%u %u", &limit_new, &limit_at_all);
							}
							if (limit_new >= limit_at_all - 4) {
								limit_at_all = limit_new + 5;
							}
						} else if (gamemode == 6) {
							printf("	The limits of the hunted one will be calculated seperatly.\n");
							printf("	limit_new < limit_at_all - 4 	!	\n");
							printf("	limit_new: 1		limit_at_all: 2		both: 3\n");
							scanf("%u", &lim);
							
							if (lim == 1){
								printf("	limit_new: 			(normal: 6) \n");
								scanf("%u", &limit_new);
							}
							if (lim == 2){
								printf("	limit_at_all: 			(normal: 12) \n");
								scanf("%u", &limit_at_all);
							}
							if (lim == 3){
								printf("	limit_new:				(normal: 6) \n	limit_at_all:				(normal: 12) \n");
								scanf("%u %u", &limit_new, &limit_at_all);
							}
							if (limit_new >= limit_at_all - 4) {
								limit_at_all = limit_new + 5;
							}
						} else if (gamemode == 9) {
							printf("	limit_new can change with your ability.\n");
							printf("	limit_new < limit_at_all - 4 	!	\n");
							printf("	limit_new: 1		limit_at_all: 2		both: 3\n");
							scanf("%u", &lim);
							
							if (lim == 1){
								printf("	limit_new: 			(normal: 8) \n");
								scanf("%u", &limit_new);
							}
							if (lim == 2){
								printf("	limit_at_all: 			(normal: 16) \n");
								scanf("%u", &limit_at_all);
							}
							if (lim == 3){
								printf("	limit_new:				(normal: 8) \n	limit_at_all:				(normal: 16) \n");
								scanf("%u %u", &limit_new, &limit_at_all);
							}
							if (limit_new >= limit_at_all - 4) {
								limit_at_all = limit_new + 5;
							}
							
						} else if (gamemode == 10) {
							printf("	Ulcer is unlimited.\n");
							
						} else if (gamemode == 11) {
							printf("	This only works if the number of players is correct! \n");
							
							printf("	limit_new < limit_at_all - 4 	!	\n");
							printf("	limit_new: 1		limit_at_all: 2		both: 3\n");
							scanf("%u", &lim);
							
							if (lim == 1){
								
								printf("	limit_new: 			(normal: 10) \n");
								scanf("%u", &limit_new);
								
							}
							if (lim == 2){
								
								printf("	limit_at_all: 			(normal: 20) \n");
								scanf("%u", &limit_at_all);
								
							}
							if (lim == 3){
								
								printf("	limit_new:				(normal: 10) \n	limit_at_all:				(normal: 20) \n");
								scanf("%u %u", &limit_new, &limit_at_all);
								
							}
							if (limit_new >= limit_at_all - 4) {
								limit_at_all = limit_new + 5;
							}
						} else if (gamemode == 12) {
							printf("	Survive is unlimited.\n");
							
						}
						
					}
					
					if (beginningmenu == 7) {
						if (ttt != 0) {
							ttt = 0;
							warning_system = 0;
							
							printf("	The time for your turn is unlimited. \n");
						} else {
							printf("	Limit the time of each turn to make the game faster. \n");
							printf("	You should add a bonus of 10sec if you want to play in the tactics-mode. \n");
							printf("\n");
							if ((gamemode == 1)||(gamemode == 2)) {
								printf("	Choose the limit of time: 				(normal: 20sec) \n");
								scanf("%u", &ttt);
								if (ttt == 0) {
									printf("	That's impossible! You'll take 20sec. \n");
									ttt = 20;
								}
								printf("\n");
								printf("\n");
								
								printf("	Choose the penalty: 		relaxed: 1, 	normal: 2, 	serious: 3, 	strict: 4, 	hard: 5, 	elite: 6, 	no mercy: 7 \n");
								scanf("%u", &warning_system);
								if ((warning_system == 0)||(warning_system > 7)) {
									printf("	Let's say normal. \n");
									warning_system = 2;
								}
								printf("\n");
								printf("\n");
								
							} else if ((gamemode == 3)||(gamemode == 9)||(gamemode == 11)) {
								printf("	Choose the limit of time: 				(normal: 30sec) \n");
								scanf("%u", &ttt);
								if (ttt == 0) {
									printf("	That's impossible! You'll take 30sec. \n");
									ttt = 30;
								}
								printf("\n");
								printf("\n");
								
								printf("	Choose the penalty: 		relaxed: 1, 	normal: 2, 	serious: 3, 	strict: 4, 	hard: 5, 	elite: 6, 	no mercy: 7 \n");
								scanf("%u", &warning_system);
								if ((warning_system == 0)||(warning_system > 7)) {
									printf("	Let's say normal. \n");
									warning_system = 2;
								}
								printf("\n");
								printf("\n");
								
							} else if ((gamemode == 4)||(gamemode == 7)||(gamemode == 8)||(gamemode == 10)||(gamemode == 12)) {
								printf("	Choose the limit of time: 				(normal: 25sec) \n");
								scanf("%u", &ttt);
								if (ttt == 0) {
									printf("	That's impossible! You'll take 25sec. \n");
									ttt = 25;
								}
								printf("\n");
								printf("\n");
								
								printf("	Choose the penalty: 		relaxed: 1, 	normal: 2, 	serious: 3, 	strict: 4, 	hard: 5, 	elite: 6, 	no mercy: 7 \n");
								scanf("%u", &warning_system);
								if ((warning_system == 0)||(warning_system > 7)) {
									printf("	Let's say normal. \n");
									warning_system = 2;
								}
								printf("\n");
								printf("\n");
							} else if (gamemode == 5) {
								printf("	Choose the limit of time: 				(normal: 15sec) \n");
								scanf("%u", &ttt);
								if (ttt == 0) {
									printf("	That's impossible! You'll take 15sec. \n");
									ttt = 15;
								}
								printf("\n");
								printf("\n");
								
								printf("	Choose the penalty: 		relaxed: 1, 	normal: 2, 	serious: 3, 	strict: 4, 	hard: 5, 	elite: 6, 	no mercy: 7 \n");
								scanf("%u", &warning_system);
								if ((warning_system == 0)||(warning_system > 7)) {
									printf("	Let's say normal. \n");
									warning_system = 2;
								}
								printf("\n");
								printf("\n");
								
							} else if (gamemode == 6) {
								printf("	The hunted one will get a 10sec bonus. \n");
								printf("	The time for choosing his heart is unlimited. \n");
								printf("	\n");
								printf("	Choose the limit of time: 				(normal: 35sec) \n");
								scanf("%u", &ttt);
								if (ttt == 0) {
									printf("	That's impossible! You'll take 35sec. \n");
									ttt = 35;
								}
								printf("\n");
								printf("\n");
								
								printf("	Choose the penalty: 		relaxed: 1, 	normal: 2, 	serious: 3, 	strict: 4, 	hard: 5, 	elite: 6, 	no mercy: 7 \n");
								scanf("%u", &warning_system);
								if ((warning_system == 0)||(warning_system > 7)) {
									printf("	Let's say normal. \n");
									warning_system = 2;
								}
								printf("\n");
								printf("\n");
							}
						}
						
					}
					
					if (beginningmenu == 8) {
						lim = 0;
						
						if ((gamemode == 6)||(gamemode == 9)||(gamemode == 10)||(gamemode == 11)||(gamemode == 12)) {
							printf("	This only works if the number of players is correct! \n");
						}
						
						printf("	Going here again will lead to a reset of the chosen colors! \n");
						printf(" \n");
						for (unsigned int p=0; p<=9; p+=1) {
							Colored[p] = 0;
						}
						for (unsigned int p=0; p<=12; p+=1) {
							Color_choice[p] = 0;
						}
						for (unsigned int p=1; p<=number_of_players; p+=1) {
							if (lim != 14) {
								printf("	Choose your color, Spieler %u . \n", p);
							}
							
							while ((lim == 0)||(lim > 14)||((Color_choice[lim-1] != 0)&&(Color_choice[lim-1] != p))) {		//pere[] wird zweckentfremdet, da hier noch nicht in Gebrauch, und jetzt ausgetauscht durch Color_choice
								printf(" \n");
								if (Color_choice[0] == 0) {
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+15);
									printf("	1) white. \n");
								}
								if (Color_choice[1] == 0) {
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+7);
									printf("	2) lightgrey. \n");
								}
								if (Color_choice[2] == 0) {
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+8);
									printf("	3) darkgrey. \n");
								}
								if (Color_choice[3] == 0) {
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+13);
									printf("	4) lightmagenta. \n");
								}
								if (Color_choice[4] == 0) {
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+12);
									printf("	5) lightred. \n");
								}
								if (Color_choice[5] == 0) {
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+4);
									printf("	6) red. \n");
								}
								if (Color_choice[6] == 0) {
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+11);
									printf("	7) lightcyan. \n");
								}
								if (Color_choice[7] == 0) {
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+3);
									printf("	8) cyan. \n");
								}
								if (Color_choice[8] == 0) {
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+9);
									printf("	9) lightblue. \n");
								}
								if (Color_choice[9] == 0) {
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+1);
									printf("	10) blue. \n");
								}
								if (Color_choice[10] == 0) {
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+14);
									printf("	11) yellow. \n");
								}
								if (Color_choice[11] == 0) {
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+10);
									printf("	12) lightgreen. \n");
								}
								if (Color_choice[12] == 0) {
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+2);
									printf("	13) green. \n");
								}
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+7);
								
								printf(" \n");
								printf(" \n");
								printf("	Back: 14 \n");
								printf(" \n");
								scanf("%u", &lim);
								if ((lim != 0)&&(lim <= 13)&&(Color_choice[lim-1] == 0)) {
									if (lim == 1) {
										Colored[p] = 15;	//change 6, brown, back to 7, grey, done	//maybe 6 is white	//now white, 15
										
									} else if (lim == 2) {
										Colored[p] = 7;
										
									} else if (lim == 3) {
										Colored[p] = 8;
										
									} else if (lim == 4) {
										Colored[p] = 13;
										
									} else if (lim == 5) {
										Colored[p] = 12;
										
									} else if (lim == 6) {
										Colored[p] = 4;
										
									} else if (lim == 7) {
										Colored[p] = 11;
										
									} else if (lim == 8) {
										Colored[p] = 3;
										
									} else if (lim == 9) {
										Colored[p] = 9;
										
									} else if (lim == 10) {
										Colored[p] = 1;
										
									} else if (lim == 11) {
										Colored[p] = 14;
										
									} else if (lim == 12) {
										Colored[p] = 10;
										
									} else if (lim == 13) {
										Colored[p] = 2;
										
									}
									
									Color_choice[lim-1] = p;
								}
							}
						}
						Colored[0] = 1;
						
						for (unsigned int p=0; p<=12; p+=1) {
							Color_choice[p] = 0;
						}
					}
					
					if (beginningmenu == 9) {
						
						lim = 0;
						
						if (opague == 0) {
							
							printf("	Going here again will lead to a return to normal visibility! \n");
							printf(" \n");
							while ((opague != 11)&&(opague != 12)&&(opague != 21)&&(opague != 22)) {		//4-Mode-Opague
								
								opague = 0;
								lim = 0;
								
								printf(" 	Use the #Surrounding or the #near-by additional to the place itself? \n\n");
								printf(" 	#Surrounding: 1			#near-by: 2 \n");
								
								scanf("%u", &lim);
								
								
								printf(" 	Show even or uneven counts? \n\n");
								printf(" 	Uneven: 1		Even: 2	\n");
								
								scanf("%u", &opague);
								
								opague += 10*lim;
							}
							
						} else if (opague >= 1) {
							printf("	Returned to normal visibility! \n");
							printf(" \n");
							opague = 0;
						}
						
						lim = 0;
					}
					
					if ((beginningmenu == back_opt+1)&&(gamemode == 4)){
						printf("	Points for win: (>0)			(normal: 3) \n");
						scanf("%u", &points_for_win);
						
						if (points_for_win == 0) {
							printf("	You missed the assertions !!! \n");
							points_for_win = 3;
						}
						
					}
					if ((beginningmenu == back_opt+2)&&(gamemode == 4)){
						printf("	Turns per drop: (>=2)			(normal: 3) \n");
						scanf("%u", &turns_per_drop);
						
						if (turns_per_drop < 2) {
							printf("	You missed the assertions !!! \n");
							turns_per_drop = 3;
						}
						
					}
					if ((beginningmenu == back_opt+3)&&(gamemode == 4)){
						printf("	Speed of the #-square: 	(>0)		(normal: 1) \n");
						scanf("%u", &speed_of_fall);
						
						if (speed_of_fall == 0) {
							printf("	You missed the assertions !!! \n");
							speed_of_fall = 1;
						}
					}
					if ((beginningmenu == back_opt+1)&&(gamemode == 6)){
						printf("	Rounds to catch? >=5			(normal: 30) \n");
						scanf("%u", &rtc);
						if (rtc < 5) {
							printf("	You missed the assertions !!! \n");
							rtc = 30;
						}
						
						printf("	Show-Position-Frequence in Rounds:			(normal: 5) \n");
						scanf("%u", &spf);
						if (spf < 1) {
							printf("	You missed the assertions !!! \n");
							spf = 5;
						}
						
						printf("	Show the heart_block or all?: 		(normal: all) \n		heart_block: 0 \n		all: 1 \n		\n");
						scanf("%u", &hboa);
						if (hboa >= 2) {
							printf("	You missed the assertions !!! \n");
							hboa = 1;
						}
						
						printf("	Show contact with hunted person: 		(normal: 1) \n		No: 0 \n		Only if necessary : 1 \n		Always: 2 \n		\n");
						scanf("%u", &scwhp);
						if (scwhp > 2) {
							printf("	You missed the assertions !!! \n");
							scwhp = 1;
						}
					}
					if ((beginningmenu == back_opt+1)&&(gamemode == 9)) {
						if (number_of_players != 9) {
							printf("	This only works if the number of players is correct! \n");
							printf("\n");
							printf("	Going here again will lead to a reset of the exclusion! \n");
						} else {
							printf("	Sorry, you can't exclude any ability, because you need all of them. \n");
						}
						
						printf(" \n");
						for (unsigned int p=0; p<=9; p+=1) {
							ability[p] = 0;
						}
						
						lim = 0;
						while (((lim == 0)||(lim > 10))&&(exclude_counter < (aop-number_of_players))) {
							printf("	Which ability do you want to exclude? \n");
							printf(" \n");
							if (ability[1] == 0) {
								printf("	Ultra light: 1 \n");
							}
							if (ability[2] == 0) {
								printf("	Light	   : 2 \n");
							}
							if (ability[3] == 0) {
								printf("	Anti	   : 3 \n");
							}
							if (ability[4] == 0) {
								printf("	Cornered   : 4 \n");
							}
							if (ability[5] == 0) {
								printf("	Inhibitor  : 5 \n");
							}
							if (ability[6] == 0) {
								printf("	Shield	   : 6 \n");
							}
							if (ability[7] == 0) {
								printf("	Poisoning  : 7 \n");
							}
							if (ability[8] == 0) {
								printf("	Pressure   : 8 \n");
							}
							if (ability[9] == 0) {
								printf("	Electric   : 9 \n");
							}
							printf(" \n");
							printf(" \n");
							if ((ability[1] == 100)||(ability[2] == 100)||(ability[3] == 100)||(ability[4] == 100)||(ability[5] == 100)||(ability[6] == 100)||(ability[7] == 100)||(ability[8] == 100)||(ability[9] == 100)) {
								printf("	Which ability do you want to include? \n");
							}
							printf(" \n");
							if (ability[1] == 100) {
								printf("	Ultra light: 1 \n");
							}
							if (ability[2] == 100) {
								printf("	Light	   : 2 \n");
							}
							if (ability[3] == 100) {
								printf("	Anti	   : 3 \n");
							}
							if (ability[4] == 100) {
								printf("	Cornered   : 4 \n");
							}
							if (ability[5] == 100) {
								printf("	Inhibitor  : 5 \n");
							}
							if (ability[6] == 100) {
								printf("	Shield	   : 6 \n");
							}
							if (ability[7] == 100) {
								printf("	Poisoning  : 7 \n");
							}
							if (ability[8] == 100) {
								printf("	Pressure   : 8 \n");
							}
							if (ability[9] == 100) {
								printf("	Electric   : 9 \n");
							}
							printf(" \n");
							printf(" \n");
							printf("	Back: 10 \n");
							printf(" \n");
							scanf("%u", &lim);
							
							if ((lim == 1)&&(ability[1] == 0)) {
								ability[1] = 100;
								exclude_counter += 1;
								lim = 0;
							} else if ((lim == 1)&&(ability[1] == 100)) {
								ability[1] = 0;
								exclude_counter -= 1;
								lim = 0;
							} else if ((lim == 2)&&(ability[2] == 0)) {
								ability[2] = 100;
								exclude_counter += 1;
								lim = 0;
							} else if ((lim == 2)&&(ability[2] == 100)) {
								ability[2] = 0;
								exclude_counter -= 1;
								lim = 0;
							} else if ((lim == 3)&&(ability[3] == 0)) {
								ability[3] = 100;
								exclude_counter += 1;
								lim = 0;
							} else if ((lim == 3)&&(ability[3] == 100)) {
								ability[3] = 0;
								exclude_counter -= 1;
								lim = 0;
							} else if ((lim == 4)&&(ability[4] == 0)) {
								ability[4] = 100;
								exclude_counter += 1;
								lim = 0;
							} else if ((lim == 4)&&(ability[4] == 100)) {
								ability[4] = 0;
								exclude_counter -= 1;
								lim = 0;
							} else if ((lim == 5)&&(ability[5] == 0)) {
								ability[5] = 100;
								exclude_counter += 1;
								lim = 0;
							} else if ((lim == 5)&&(ability[5] == 100)) {
								ability[5] = 0;
								exclude_counter -= 1;
								lim = 0;
							} else if ((lim == 6)&&(ability[6] == 0)) {
								ability[6] = 100;
								exclude_counter += 1;
								lim = 0;
							} else if ((lim == 6)&&(ability[6] == 100)) {
								ability[6] = 0;
								exclude_counter -= 1;
								lim = 0;
							} else if ((lim == 7)&&(ability[7] == 0)) {
								ability[7] = 100;
								exclude_counter += 1;
								lim = 0;
							} else if ((lim == 7)&&(ability[7] == 100)) {
								ability[7] = 0;
								exclude_counter -= 1;
								lim = 0;
							} else if ((lim == 8)&&(ability[8] == 0)) {
								ability[8] = 100;
								exclude_counter += 1;
								lim = 0;
							} else if ((lim == 8)&&(ability[8] == 100)) {
								ability[8] = 0;
								exclude_counter -= 1;
								lim = 0;
							} else if ((lim == 9)&&(ability[9] == 0)) {
								ability[9] = 100;
								exclude_counter += 1;
								lim = 0;
							} else if ((lim == 9)&&(ability[9] == 100)) {
								ability[9] = 0;
								exclude_counter -= 1;
								lim = 0;
							}
						}
						
					}
					if ((beginningmenu == back_opt+2)&&((gamemode == 6)||(gamemode == 9)||(gamemode == 10)||(gamemode == 11))){
						printf("	Number of players?		(2 - 9) \n");
						scanf("%u", &number_of_players);
						
						while ((number_of_players < 2) || (number_of_players > 9)){
							printf("	Number of players?		(2 - 9) \n");
							scanf("%u", &number_of_players);
						}
						
						if (gamemode == 6) {
							if (number_of_players == 3){
								
								siz_m = 7;
								siz_n = 13;
								m = siz_m + 2;
								n = siz_n + 2;
							}
							if (number_of_players == 4){
							
								siz_m = 11;
								siz_n = 13;
								m = siz_m + 2;
								n = siz_n + 2;
							}
							if (number_of_players == 5){
								
								siz_m = 13;
								siz_n = 13;
								m = siz_m + 2;
								n = siz_n + 2;
							}
							if (number_of_players == 6){
								
								siz_m = 13;
								siz_n = 16;
								m = siz_m + 2;
								n = siz_n + 2;
							}
							if (number_of_players == 7){
								
								siz_m = 15;
								siz_n = 19;
								m = siz_m + 2;
								n = siz_n + 2;
							}
							if (number_of_players == 8){
								
								siz_m = 16;
								siz_n = 21;
								m = siz_m + 2;
								n = siz_n + 2;
							}
							if (number_of_players == 9){
								
								siz_m = 21;
								siz_n = 21;
								m = siz_m + 2;
								n = siz_n + 2;
							}
						} else if (gamemode == 9) {
							
							if (number_of_players == 3){
								
								siz_m = 9;
								siz_n = 9;
								m = siz_m + 2;
								n = siz_n + 2;
							}
							if (number_of_players == 4){
								
								siz_m = 11;
								siz_n = 11;
								m = siz_m + 2;
								n = siz_n + 2;
							}
							if (number_of_players == 5){
								
								siz_m = 12;
								siz_n = 12;
								m = siz_m + 2;
								n = siz_n + 2;
							}
							if (number_of_players == 6){
								
								siz_m = 13;
								siz_n = 13;
								m = siz_m + 2;
								n = siz_n + 2;
							}
							if (number_of_players == 7){
								
								siz_m = 14;
								siz_n = 14;
								m = siz_m + 2;
								n = siz_n + 2;
							}
							if (number_of_players == 8){
								
								siz_m = 16;
								siz_n = 16;
								m = siz_m + 2;
								n = siz_n + 2;
							}
							if (number_of_players == 9){
								
								siz_m = 16;
								siz_n = 16;
								m = siz_m + 2;
								n = siz_n + 2;
							}
						} else if (gamemode == 10) {
							
							if (number_of_players == 3){
								
								siz_m = 7;
								siz_n = 7;
								m = siz_m + 2;
								n = siz_n + 2;
							}
							if (number_of_players == 4){
								
								siz_m = 9;
								siz_n = 9;
								m = siz_m + 2;
								n = siz_n + 2;
							}
							if (number_of_players == 5){
								
								siz_m = 10;
								siz_n = 10;
								m = siz_m + 2;
								n = siz_n + 2;
							}
							if (number_of_players == 6){
								
								siz_m = 11;
								siz_n = 11;
								m = siz_m + 2;
								n = siz_n + 2;
							}
							if (number_of_players == 7){
								
								siz_m = 12;
								siz_n = 12;
								m = siz_m + 2;
								n = siz_n + 2;
							}
							if (number_of_players == 8){
								
								siz_m = 13;
								siz_n = 13;
								m = siz_m + 2;
								n = siz_n + 2;
							}
							if (number_of_players == 9){
								
								siz_m = 14;
								siz_n = 14;
								m = siz_m + 2;
								n = siz_n + 2;
							}
						} else if (gamemode == 11) {
							
							if (number_of_players == 3){
								
								siz_m = 9;
								siz_n = 11;
								m = siz_m + 2;
								n = siz_n + 2;
							}
							if (number_of_players == 4){
								
								siz_m = 11;
								siz_n = 11;
								m = siz_m + 2;
								n = siz_n + 2;
							}
							if (number_of_players == 5){
								
								siz_m = 11;
								siz_n = 15;
								m = siz_m + 2;
								n = siz_n + 2;
							}
							if (number_of_players == 6){
								
								siz_m = 15;
								siz_n = 15;
								m = siz_m + 2;
								n = siz_n + 2;
							}
							if (number_of_players == 7){
								
								siz_m = 15;
								siz_n = 15;
								m = siz_m + 2;
								n = siz_n + 2;
							}
							if (number_of_players == 8){
								
								siz_m = 17;
								siz_n = 17;
								m = siz_m + 2;
								n = siz_n + 2;
							}
							if (number_of_players == 9){
								
								siz_m = 17;
								siz_n = 17;
								m = siz_m + 2;
								n = siz_n + 2;
							}
						}
						
						for (unsigned int p=0; p<=5; p+=1){
							
							if (number_of_players >= 3){
								AA[p] = 0;
								CC[p] = 0;
							}
							if (number_of_players >= 4){
								BB[p] = 0;
								DD[p] = 0;
							}
							if (number_of_players >= 5){
								AAA[p] = 0;
								CCC[p] = 0;
							}
							if (number_of_players >= 6){
								BBB[p] = 0;
								DDD[p] = 0;
							}
							if (number_of_players >= 7){
								AAAA[p] = 0;
								CCCC[p] = 0;
							}
							if (number_of_players >= 8){
								BBBB[p] = 0;
								DDDD[p] = 0;
							}
							if (number_of_players == 9){
								AAAAA[p] = 0;
								CCCCC[p] = 0;
							}
						}
						
					}
					if ((beginningmenu == back_opt+2)&&((gamemode == 12))){
						printf("	Number of players?		(1 - 9) \n");
						scanf("%u", &number_of_players);
						
						while ((number_of_players < 1) || (number_of_players > 9)){
							printf("	Number of players?		(1 - 9) \n");
							scanf("%u", &number_of_players);
						}
						
						if (gamemode == 12) {
							if (number_of_players == 1){
								
								siz_m = 10;
								siz_n = 10;
								m = siz_m + 2;
								n = siz_n + 2;
							}
							if (number_of_players == 2){
								
								siz_m = 11;
								siz_n = 11;
								m = siz_m + 2;
								n = siz_n + 2;
							}
							if (number_of_players == 3){
								
								siz_m = 12;
								siz_n = 12;
								m = siz_m + 2;
								n = siz_n + 2;
							}
							if (number_of_players == 4){
								
								siz_m = 13;
								siz_n = 13;
								m = siz_m + 2;
								n = siz_n + 2;
							}
							if (number_of_players == 5){
								
								siz_m = 15;
								siz_n = 15;
								m = siz_m + 2;
								n = siz_n + 2;
							}
							if (number_of_players == 6){
								
								siz_m = 15;
								siz_n = 15;
								m = siz_m + 2;
								n = siz_n + 2;
							}
							if (number_of_players == 7){
								
								siz_m = 17;
								siz_n = 17;
								m = siz_m + 2;
								n = siz_n + 2;
							}
							if (number_of_players == 8){
								
								siz_m = 17;
								siz_n = 17;
								m = siz_m + 2;
								n = siz_n + 2;
							}
							if (number_of_players == 9){
								
								siz_m = 17;
								siz_n = 17;
								m = siz_m + 2;
								n = siz_n + 2;
							}
						}
						
						for (unsigned int p=0; p<=5; p+=1){
							
							if (number_of_players >= 3){
								AA[p] = 0;
								CC[p] = 0;
							}
							if (number_of_players >= 4){
								BB[p] = 0;
								DD[p] = 0;
							}
							if (number_of_players >= 5){
								AAA[p] = 0;
								CCC[p] = 0;
							}
							if (number_of_players >= 6){
								BBB[p] = 0;
								DDD[p] = 0;
							}
							if (number_of_players >= 7){
								AAAA[p] = 0;
								CCCC[p] = 0;
							}
							if (number_of_players >= 8){
								BBBB[p] = 0;
								DDDD[p] = 0;
							}
							if (number_of_players == 9){
								AAAAA[p] = 0;
								CCCCC[p] = 0;
							}
						}
						
					}
					if ((beginningmenu == back_opt+3)&&((gamemode == 9)||(gamemode == 10))) {
						printf("	Rounds to play: 			(normal: 30) \n");
						scanf("%u", &rtp);
						if (rtp == 0) {
							rtp = 30;
						}
						if (gamemode == 10) {
							printf("	K.O.-Mode deactivated \n");
							ulcer_start[0] = 0;
						}
					}
					if ((beginningmenu == back_opt+1)&&(gamemode == 7)){
						printf("	Frequence: 			(normal: 6) \n");
						scanf("%u", &freq);
					}
					if ((beginningmenu == back_opt+1)&&(gamemode == 8)){
						printf("	Only Object: 	yes [1]		no [0] \n");
						scanf("%u", &rain_obj);
						if ((rain_obj != 1)&&(rain_obj != 0)) {
							printf("	You missed the assertions !!! \n");
							rain_obj = 0;
						}
						
						printf("	Raindrops per turn:		1, 	2, 	4, 	5, 	6 	? \n");
						scanf("%u", &rain_drops);
						if ((rain_drops == 0) || (rain_drops > 6) || (rain_drops == 3)){
							printf("	You missed the assertions !!! \n");
							rain_drops = 1;
						}
						printf("\n");
						
						printf("	Characteristics of the Raindrops: \n");
						printf("		Push: 1 \n		Destroy: 2 \n		Explode: 3 \n		Transform: 4 \n		Teleport: 5 \n		Mixed: 6 \n");
						scanf("%u", &rain);
						if (rain == 3){
							printf("		Explode: 31		or		Explode & survival: 32 \n");
							scanf("%u", &rain);
						}
						printf("\n");
						if ((rain == 0)||(rain > 6)) {
							printf("	You missed the assertions !!! \n");
							rain = 1;
						}
						
						printf("	Distance in squares the rain should fall per turn:  		(<=6), 0 = 0,5 \n");
						scanf("%u", &rain_speed);
						if (rain_speed > 6){
							printf("	You missed the assertions !!! \n");
							rain_speed = 1;
						}
						printf("\n");
					}
					
					if ((beginningmenu == back_opt+1)&&(gamemode == 10)) {
						
						printf("	This only works if the number of players is correct! \n");
						printf("\n");
						printf("	Chose the amount of lifes. \n");
						for (unsigned int p=1; p<=number_of_players; p+=1) {
							printf("\n");
							printf("	Lifes PLayer: %u		(normal %u) \n", p, p-1);
							scanf("%u", &lim);
							ulcer_lifes[p] = lim;
							printf("\n");
						}
					}
					if ((beginningmenu == back_opt+4)&&(gamemode == 10)) {
						if (ulcer_start[0] == 0) {
							printf("	K.O.-Mode activated. \n");
							printf("	Rounds are unlimited. \n");
							
							rtp = 0;
							ulcer_start[0] = 1;
						} else if (ulcer_start[0] == 1) {
							printf("	K.O.-Mode deactivated. \n");
							ulcer_start[0] = 0;
						}
						
					}
					/*
					printf("	Gravity	  : %u \n", back_opt+1);
					printf("	Number of players: %u \n", back_opt+2);
					printf("	Range	 : %u \n", back_opt+3);
					printf("	Coefficient : %u \n", back_opt+4);
					*/
					if ((beginningmenu == back_opt+1)&&(gamemode == 11)) {
						printf("	The Gravity is pulling down the object. \n");
						printf("	Gravity:	-5 to 5		(normal: 1) \n");
						scanf("%d", &erd);
						if ((erd < -5)||(erd > 5)) {
							printf("	That makes no sense, i will give you the 1. \n");
							erd = 1;
						}
					}
					if ((beginningmenu == back_opt+3)&&(gamemode == 11)) {
						printf("	The Range of the impact moving the object. \n");
						printf("	Range:	0-5		(normal: 1) \n");
						scanf("%u", &range);
						if (range > 5) {
							printf("	That makes no sense, i will give you the 1. \n");
							range = 1;
						}
					}
					if ((beginningmenu == back_opt+4)&&(gamemode == 11)) {
						printf("	The Coefficient influences the way and strength of the impact moving the object. \n");
						printf("	Coefficient:	0-5		(normal: 1) \n");
						scanf("%u", &d_wert);
						if (d_wert > 5) {
							printf("	That makes no sense, i will give you the 1. \n");
							d_wert = 1;
						}
					}
					
					if ((beginningmenu == back_opt+1)&&(gamemode == 12)) {
						for (unsigned int p=1; p<=3; p+=1) {
							information_code[p] = 2;
						}
						printf("	Do you want to play with: \n");
						
						while (information_code[1]>1) {
							printf("	-Traps:		Yes: 1		No: 0 \n");
							scanf("%u", &information_code[1]);
						}
						while (information_code[2]>1) {
							printf("	-Bombs:		Yes: 1		No: 0 \n");
							scanf("%u", &information_code[2]);
						}
						while (information_code[3]>1) {
							printf("	-Waves:		Yes: 1		No: 0 \n");
							scanf("%u", &information_code[3]);
						}
					}
					if (beginningmenu == back_opt){	//auch hier!
						gamemode = 0;
						break;
					}
					printf("\n");
				
					printf("	Your chosen set-up: \n");
					printf("\n");
					printf("	Gamemode:");
					if (gamemode == 1) {
						printf(" Classic \n ");
					} else if (gamemode == 2) {
						printf(" Collect \n ");
					} else if (gamemode == 3) {
						printf(" Contact \n ");
					} else if (gamemode == 4) {
						printf(" Fall \n ");
						printf("	Points for win: %u \n", points_for_win);
						printf("	Turns per drop: %u \n", turns_per_drop);
						printf("	Speed of the #-square: %u \n", speed_of_fall);
					} else if (gamemode == 5) {
						printf(" Fight \n ");
					} else if (gamemode == 6) {
						printf(" Hunt \n ");
						printf("	Rounds to catch: %u \n", rtc);
						printf("	Show-Position-Frequence in Rounds: %u \n", spf);
						printf("	What to show: ");
						if (hboa == 0) {
							printf(" heart-block \n");
						} else if (hboa == 1) {
							printf(" all \n");
						}
						printf("	Show contact with hunted person: ");
						if (scwhp == 0) {
							printf(" No \n");
						} else if (scwhp == 1) {
							printf(" Only if necessary \n");
						} else if (scwhp == 2) {
							printf(" Permanent \n");
						}
						printf("	Number of players: %u \n", number_of_players);
					} else if (gamemode == 7) {
						printf(" Race \n ");
						printf("	Frequence: %u \n", freq);
					} else if (gamemode == 8) {
						printf(" Rain \n ");
						printf("	Only Object: ");
						if (rain_obj == 1) {
							printf("	yes \n");
						} else if (rain_obj == 0) {
							printf("	no \n");
						}
						printf("	Raindrops per turn: %u \n", rain_drops);
						printf("	Characteristics of the Raindrops: ");
						if (rain == 1) {
							printf("	Push: 1 \n");
						} else if (rain == 2) {
							printf("	Destroy: 2 \n");
						} else if (rain == 31) {
							printf("	Explode: 3 \n");
						} else if (rain == 32) {
							printf("	Explode & survival: 3 \n");
						} else if (rain == 4) {
							printf("	Transform: 4 \n");
						} else if (rain == 5) {
							printf("	Teleport: 5 \n");
						} else if (rain == 6) {
							printf("	Mixed: 6 \n");
						}
						if (rain_speed == 0) {
							printf("	Distance in squares: 0,5 \n");
						} else {
							printf("	Distance in squares: %u \n", rain_speed);
						}
						
					} else if (gamemode == 9) {
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
							printf("	No Ability excluded. \n");
						}
						printf("	Number of players: %u \n", number_of_players);
					} else if (gamemode == 10) {
						printf(" Ulcer \n ");
						for (unsigned int p=1; p<=number_of_players; p+=1) {
							printf(" \n ");
							printf("	Lifes player %u: %u \n ", p, ulcer_lifes[p]);
						}
						printf("	Number of players: %u \n", number_of_players);
					} else if (gamemode == 11) {
						printf(" Dynamic \n ");
						printf("	Gravity: %d \n", erd);
						printf("	range: %u \n", range);
						printf("	Coefficient: %u \n", d_wert);
						printf("	Number of players: %u \n", number_of_players);
					} else if (gamemode == 12) {
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
						printf("	Number of players: %u \n", number_of_players);
					}
					printf(" \n ");
					printf(" \n");
					printf(" 	Zeilen:  %u \n	Spalten: %u \n", siz_m, siz_n);
					printf(" \n");
					if (journey == 1){
						printf("	journey   activated \n");
					}
					if (journey == 0){
						printf("	journey deactivated \n");
					}
					printf(" \n");
					if (tac != 0){
						printf("	Tactics   activated, 	stack = %u \n", tac);	
					} else {
						printf("	Tactics deactivated \n");	
					}
					printf(" \n");
					if (opague != 0){
						printf("	opague   activated \n");
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
						printf("	opague  deactivated \n");	
					}
					printf(" \n");
					
					if (gamemode == 10) {
						if (ulcer_start[0] == 1){
							printf("	K.O.-Mode   activated. \n");	
						} else if (ulcer_start[0] == 0){
							printf("	K.O.-Mode deactivated \n");	
						}
						
						printf(" \n");
					}
					
					if (ttt == 0) {
						printf("	time	deactivated \n");
					} else if (ttt != 0) {
						printf("	time	  activated \n");
					}
					printf("\n");
					
					if (opt == 5) {
						printf("	Random    activated \n");
						if ((gamemode != 6)&&(gamemode != 9)&&(gamemode != 10)&&(gamemode != 11)&&(gamemode != 12)) {
							if ((number_1 + number_3) % 4 <= 1){
								printf("\n");
								printf("	A Player: Spieler 1	\n	The other Player: Spieler 2 \n");
								printf("\n");
							} else {
								printf("\n");
								printf("	The other Player: Spieler 1	\n	A Player: Spieler 2 \n");
								printf("\n");
							}
						}
						
					} else if (opt == 0) {
						printf("	Random  deactivated \n");
					}
					printf(" \n");
					printf("	limit_new:    %u \n	limit_at_all: %u \n", limit_new, limit_at_all);
					printf("	(sometimes only for the journey!) \n");
					printf("\n");
					
					printf("	Colored squares:	");
					if (Colored[0] == 1) {
						printf("yes \n");
					} else if (Colored[0] == 0) {
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
						
						if (gamemode == 9) {
							for (unsigned int p=1; p<=number_of_players; p+=1) {
								lim = 0;
								printf(" \n");
								printf(" \n");
								while ((lim == 0)||(lim > 9)||((ability[lim] != 0)&&(ability[lim] != p))) {
									if (Colored[0] == 1) {
										SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+Colored[p]);
									}
									printf("	Spieler %u, please choose your ability:	\n", p);
									if (Colored[0] == 1) {
										SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+7);
									}
									printf(" \n");
									if (ability[1] == 0) {
										printf("	Ultra light: 1 \n");
									}
									if (ability[2] == 0) {
										printf("	Light	   : 2 \n");
									}
									if (ability[3] == 0) {
										printf("	Anti	   : 3 \n");
									}
									if (ability[4] == 0) {
										printf("	Cornered   : 4 \n");
									}
									if (ability[5] == 0) {
										printf("	Inhibitor  : 5 \n");
									}
									if (ability[6] == 0) {
										printf("	Shield	   : 6 \n");
									}
									if (ability[7] == 0) {
										printf("	Poisoning  : 7 \n");
									}
									if (ability[8] == 0) {
										printf("	Pressure   : 8 \n");
									}
									if (ability[9] == 0) {
										printf("	Electric   : 9 \n");
									}
									
									scanf("%u", &lim);
									
									if ((ability[lim] == 0)&&(lim != 0)&&(lim <= 9)) {
										ability[lim] = p;
										if ((lim <= 4)||(lim == 6)) {
											ability[0] += 1;
										}
									}
									printf(" \n");
									printf(" \n");
								}					
							}
						}
					}
					printf("\n");
					printf("\n");
				}
			}
			
			
					//Startmenü, Ende
					
			same[0] = 0;
			same[1] = m;
			same[2] = n;
			same[3] = journey;
			same[4] = tac;
			same[5] = gamemode;
			same[6] = fall_controll;
			same[7] = turns_per_drop;
			same[8] = speed_of_fall;
			same[9] = count_freq;
			same[10] = ulcer_lifes[1];
			same[11] = rain;
			same[12] = rain_drops;
			same[13] = rain_obj;
			same[14] = rain_speed;
			same[15] = opt;
			same[16] = siz_m;
			same[17] = siz_n;
			same[18] = limit_new;
			same[19] = limit_at_all;
			same[20] = ulcer_lifes[2];
			same[21] = points_for_win;
			same[22] = freq;
				//same[23] ist schon belegt
			same[24] = number_of_players;
			same[25] = rtc;
			same[26] = spf;
			same[27] = scwhp;
			same[28] = hboa;
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
			same[49] = Colored[0];
			same[50] = ulcer_lifes[5];
			same[51] = Colored[1];
			same[52] = Colored[2];
			same[53] = Colored[3];
			same[54] = Colored[4];
			same[55] = Colored[5];
			same[56] = Colored[6];
			same[57] = Colored[7];
			same[58] = Colored[8];
			same[59] = Colored[9];
			same[60] = ulcer_lifes[6];
			same[61] = ulcer_lifes[7];
			same[62] = ulcer_lifes[8];
			same[63] = ulcer_lifes[9];
			same[64] = opague;
			same[65] = number_3;
			same[66] = number_4;
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
			same[68] = range;
			same[69] = d_wert;
			
		} else if (same[0] == 1) {
			same[0] = 0;
			m = same[1];
			n = same[2];
			journey = same[3];
			tac = same[4];
			gamemode = same[5];
			fall_controll = same[6];
			turns_per_drop = same[7];
			speed_of_fall = same[8];
			count_freq = same[9];
			ulcer_lifes[1] = same[10];
			rain = same[11];
			rain_drops = same[12];
			rain_obj = same[13];
			rain_speed = same[14];
			opt = same[15];
			siz_m = same[16];
			siz_n = same[17];
			limit_new = same[18];
			limit_at_all = same[19];
			ulcer_lifes[2] = same[20];
			points_for_win = same[21];
			freq = same[22];
			use_number = same[23];
			number_of_players = same[24];
			rtc = same[25];
			spf = same[26];
			scwhp = same[27];
			hboa = same[28];
			ttt = same[29];
			ulcer_lifes[3] = same[30];
			warning_system = same[31];
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
			Colored[0] = same[49];
			ulcer_lifes[5] = same[50];
			Colored[1] = same[51];
			Colored[2] = same[52];
			Colored[3] = same[53];
			Colored[4] = same[54];
			Colored[5] = same[55];
			Colored[6] = same[56];
			Colored[7] = same[57];
			Colored[8] = same[58];
			Colored[9] = same[59];
			ulcer_lifes[6] = same[60];
			ulcer_lifes[7] = same[61];
			ulcer_lifes[8] = same[62];
			ulcer_lifes[9] = same[63];
			opague = same[64];
			number_3 = same[65];
			number_4 = same[66];
			if (same[67] >= 10) {	//-1 --> 10, -2 --> 20, ...
				erd = -1 * (same[67]/10);
			} else {
				erd = same[67];
			}
			range = same[68];
			d_wert = same[69];
		}
		
		
		if (journey == 1){		//gamemode 11 journey, done
			Sf_journey = Spielfeld_Create (m, n);
			cons_journey_1 = Spielfeld_Create (m, n);
			if (number_of_players >= 2){
				cons_journey_2 = Spielfeld_Create (m, n);
			}
			if (number_of_players >= 3){
				cons_journey_3 = Spielfeld_Create (m, n);
			}
			if (number_of_players >= 4){
				cons_journey_4 = Spielfeld_Create (m, n);
			}
			if (number_of_players >= 5){
				cons_journey_5 = Spielfeld_Create (m, n);
			}
			if (number_of_players >= 6){
				cons_journey_6 = Spielfeld_Create (m, n);
			}
			if (number_of_players >= 7){
				cons_journey_7 = Spielfeld_Create (m, n);
			}
			if (number_of_players >= 8){
				cons_journey_8 = Spielfeld_Create (m, n);
			}
			if (number_of_players == 9){
				cons_journey_9 = Spielfeld_Create (m, n);
			}
			
		}
		if (tac != 0){
			for (unsigned int p=0; p<=5; p+=1){
				C[p] = tac;
				D[p] = tac;
			}
		}
		
		Sf_opague = Spielfeld_Create (m, n);
		
		cons_field_1 = Spielfeld_Create (m, n);
		Sf_nl_1 = Spielfeld_Create(m, n);
		Sf_od_1 = Spielfeld_Create(m, n);
		if (number_of_players >= 2){
			cons_field_2 = Spielfeld_Create (m, n);
			Sf_nl_2 = Spielfeld_Create(m, n);
			Sf_od_2 = Spielfeld_Create(m, n);
		}
		if (number_of_players >= 3){
			cons_field_3 = Spielfeld_Create (m, n);
			Sf_nl_3 = Spielfeld_Create(m, n);
			Sf_od_3 = Spielfeld_Create(m, n);
		}
		if (number_of_players >= 4){
			cons_field_4 = Spielfeld_Create (m, n);
			Sf_nl_4 = Spielfeld_Create(m, n);
			Sf_od_4 = Spielfeld_Create(m, n);
		}
		if (number_of_players >= 5){
			cons_field_5 = Spielfeld_Create (m, n);
			Sf_nl_5 = Spielfeld_Create(m, n);
			Sf_od_5 = Spielfeld_Create(m, n);
		}
		if (number_of_players >= 6){
			cons_field_6 = Spielfeld_Create (m, n);
			Sf_nl_6 = Spielfeld_Create(m, n);
			Sf_od_6 = Spielfeld_Create(m, n);
		}
		if (number_of_players >= 7){
			cons_field_7 = Spielfeld_Create (m, n);
			Sf_nl_7 = Spielfeld_Create(m, n);
			Sf_od_7 = Spielfeld_Create(m, n);
		}
		if (number_of_players >= 8){
			cons_field_8 = Spielfeld_Create (m, n);
			Sf_nl_8 = Spielfeld_Create(m, n);
			Sf_od_8 = Spielfeld_Create(m, n);
		}
		if (number_of_players >= 9){
			cons_field_9 = Spielfeld_Create (m, n);
			Sf_nl_9 = Spielfeld_Create(m, n);
			Sf_od_9 = Spielfeld_Create(m, n);
		}
		
		
		Sf = Spielfeld_Create (m, n);
		Sf = start_normal (Sf, m, n, gamemode, number_of_players);
		
		if (gamemode == 8) {
			show_field (Sf, m, n, gamemode, information_code, geben, Colored);
		}
		
		count_freq = 1;
		
		if (gamemode == 9) {
			information_code[1] = ability[5];
			information_code[2] = ability[7];
			information_code[3] = ability[8];
			
			if ((ability[1] != 0)&&(ability[1] != 100)) {
				Sf[1][0] = 10*ability[1];
			}
			if ((ability[2] != 0)&&(ability[2] != 100)) {
				Sf[0][0] = 10*ability[2];
			}
			if ((ability[3] != 0)&&(ability[3] != 100)) {
				Sf[0][1] = 10*ability[3];
			}
			if ((ability[4] != 0)&&(ability[4] != 100)) {
				Sf[0][n-1] = 10*ability[4];
			}
			if ((ability[6] != 0)&&(ability[6] != 100)) {
				Sf[m-1][n-1] = 10*ability[6];
			}
			if ((ability[9] != 0)&&(ability[9] != 100)) {
				Sf[m-1][0] = 10*ability[9];
			}
			
		}
		
		limit_at_all_saver = limit_at_all;
		
		if ((gamemode == 10)||(gamemode == 11)||(gamemode == 12)) {
			information_code[0] = number_of_players;
		}
		
		unsigned int g, survive_different;
		g = 1;
		survive_different = 0;
		
		if (gamemode == 12) {
			while ((survive_different == 0)||(survive_different > 60)){
				printf("	Please give me a number between 1 and 60. \n");
				scanf("%u", &survive_different);
			}
		}
		
		while (g != 0){
			Spielfeld temp;
			
			zeitgewinner = 0;
			boost_hunt_activator = 0;
			einmal = 0;
			
			if (player_counter == number_of_players) {	//Notbremse
				break;
			}
			
			if (gamemode == 11) {
				controll = 0;
				for (unsigned int i=1; i<m-1; i+=1) {
					for (unsigned int j=1; j<n-1; j+=1) {
						if (Sf[i][j] == 77) {
							position[0] = j;
							position[1] = i;
							controll = 1;
						}
						if (controll == 1) {
							break;
						}
					}
					if (controll == 1) {
						break;
					}
				}
				controll = 0;
				
			}
			
			if (ttt != 0) {
				time_warning = 0.0;
				time_saver = 0.0;
			}
			
			geben = ((g-1)%number_of_players)+1;
			
			/* printf("	test \n");
			show_field (Sf, m, n, gamemode, information_code, geben, Colored);	//test
			printf("	test \n"); */
			round_counter_before = round_counter;
			round_counter = 0;
			for (unsigned int p=1; p<=g; p+=number_of_players) {
				round_counter += 1;
			}
			if ((gamemode == 12)&&(round_counter == round_counter_before+1)) {
				
				//printf("in the obstacles-generator \n");	//test
				
				if ((round_counter % 5 == 0)&&(information_code[3] >= 1)) {	//delete Waves
					for (unsigned int i=1; i<m-1; i+=1){
						for (unsigned int j=1; j<n-1; j+=1){
							if (Sf[i][j] == 75) {
								Sf[i][j] = 0;
							}
						}
					}
				}
				
				if (opague >= 1) {
					Sf_opague = opague_builder (Sf, m, n, geben, opague, aop);
				}
				
				if (opague >= 1) {
					show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
				} else {
					show_field (Sf, m, n, gamemode, information_code, geben, Colored);
				}
				
				for (unsigned int i=1; i<m-1; i+=1){
					for (unsigned int j=1; j<n-1; j+=1){
						
						if (information_code[2] >= 1) {	//Bombs
							if (Sf[i][j] == 84) {
								Sf[i][j] = 83;
							} else if (Sf[i][j] == 83) {
								Sf[i][j] = 82;
							} else if (Sf[i][j] == 82) {
								Sf[i][j] = 81;
							} else if (Sf[i][j] == 81) {
								for (unsigned int h=i-1; h<=i+1; h+=1){
									for (unsigned int k=j-1; k<=j+1; k+=1){
										if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
											Sf[h][k] = 0;
										}
									}
								}
							}
						}
						if (information_code[3] >= 1) {	//Waves
							if (((Sf[i-1][j] == 75)&&(Sf[i+1][j] != 75)&&(Sf[i][j+1] != 75)&&(Sf[i][j-1] != 75))||((Sf[i-1][j] != 75)&&(Sf[i+1][j] == 75)&&(Sf[i][j+1] != 75)&&(Sf[i][j-1] != 75))||((Sf[i-1][j] != 75)&&(Sf[i+1][j] != 75)&&(Sf[i][j+1] == 75)&&(Sf[i][j-1] != 75))||((Sf[i-1][j] != 75)&&(Sf[i+1][j] != 75)&&(Sf[i][j+1] != 75)&&(Sf[i][j-1] == 75))) {
								Sf[i][j] = 74;
							}
						}
					}
				}
				
				for (unsigned int i=1; i<m-1; i+=1){
					for (unsigned int j=1; j<n-1; j+=1){
						if (Sf[i][j] == 75) {
							Sf[i][j] = 0;
						}
					}
				}
				for (unsigned int i=1; i<m-1; i+=1){
					for (unsigned int j=1; j<n-1; j+=1){
						if (Sf[i][j] == 74) {
							Sf[i][j] = 75;
						}
					}
				}
				
				if ((round_counter % 5 == 0)&&(information_code[1] >= 1)) {	//Traps amount per round
					information_code[1] += 1;
				}
				if ((round_counter % 10 == 0)&&(information_code[2] >= 1)) {	//Bombs amount per round
					information_code[2] += 1;
				}
				if ((round_counter % 15 == 0)&&(information_code[3] >= 1)) {	//Waves amount per 5 rounds
					information_code[3] += 1;
				}
				
				if ((round_counter % 5 == 1)&&(information_code[3] >= 1)) {	//new Waves
					for (unsigned int p=1; p<=information_code[3]; p+=1) {
						unsigned int i;
						unsigned int j;
						i = ((survive_different%10)+ges[1]+ges[3]+ges[5]+ges[7]+ges[9]+var_[2]+var_[4]+var_[6]+var_[8]+Colored[1]+Colored[3]+Colored[5]+Colored[7]+Colored[9]+7*p+g+2*use_number+tac)%(m-2) + 1;
						j = ((survive_different%6)+ges[2]+ges[4]+ges[6]+ges[8]+var_[1]+var_[3]+var_[5]+var_[7]+var_[9]+Colored[0]+Colored[2]+Colored[4]+Colored[6]+Colored[8]+11*p+g+3*use_number+ttt)%(n-2) + 1;
						Sf[i][j] = 75;
					}
				}
				if (information_code[1] >= 1) {	//new Traps
					for (unsigned int p=1; p<=information_code[1]; p+=1) {
						unsigned int i;
						unsigned int j;
						i = ((survive_different%5)+ges[1]+ges[3]+ges[5]+ges[7]+ges[9]+var_[2]+var_[4]+var_[6]+var_[8]+Colored[1]+Colored[3]+Colored[5]+Colored[7]+Colored[9]+3*p+g+use_number+tac)%(m-2) + 1;
						j = ((survive_different%12)+ges[2]+ges[4]+ges[6]+ges[8]+var_[1]+var_[3]+var_[5]+var_[7]+var_[9]+Colored[0]+Colored[2]+Colored[4]+Colored[6]+Colored[8]+6*p+g+2*use_number+ttt)%(n-2) + 1;
						Sf[i][j] = 71;
					}
				}
				if (information_code[2] >= 1) {	//new Bombs
					for (unsigned int p=1; p<=information_code[2]; p+=1) {
						unsigned int i;
						unsigned int j;
						i = ((survive_different%15)+ges[1]+ges[3]+ges[5]+ges[7]+ges[9]+var_[2]+var_[4]+var_[6]+var_[8]+Colored[1]+Colored[3]+Colored[5]+Colored[7]+Colored[9]+8*p+g+3*use_number+tac)%(m-2) + 1;
						j = ((survive_different%4)+ges[2]+ges[4]+ges[6]+ges[8]+var_[1]+var_[3]+var_[5]+var_[7]+var_[9]+Colored[0]+Colored[2]+Colored[4]+Colored[6]+Colored[8]+5*p+g+use_number+ttt)%(n-2) + 1;
						Sf[i][j] = 84;
					}
				}
				
			}
			
			if ((gamemode == 11)&&((g-1)%number_of_players == 0)&&(var_[2] != 1010)) {	//Object-77 movement
				
				if (opague >= 1) {
					show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
				} else {
					show_field (Sf, m, n, gamemode, information_code, geben, Colored);
				}
				
				dynamic_pointer[6] = 0;		//impact y_horizontal
				dynamic_pointer[7] = 0;		//impact y_vertikal
				
				dynamic_pointer[0] = dynamic_pointer[4] + dynamic_pointer[2];	//aus "sgn(a)*a^2" mach "a", done
				dynamic_pointer[1] = dynamic_pointer[5] + dynamic_pointer[3];
				
				dynamic_pointer[2] += dynamic_pointer[4];
				dynamic_pointer[3] += dynamic_pointer[5];
				
				impact_y_semi_square (m, n, position, d_wert, range, dynamic_pointer, Sf);
				
				dynamic_pointer[4] += dynamic_pointer[6];
				dynamic_pointer[5] += dynamic_pointer[7] + erd;
				
				while (abs(dynamic_pointer[1])+abs(dynamic_pointer[0]) != 0){
					/*
					printf("	Test-print \n");
					show_field (Sf, m, n, gamemode, information_code, geben, Colored);		//test
					printf("	Test-print \n");
					printf("	\n");
					printf("	indikator1: %u \n", indikator1);
					printf("	indikator2: %u \n", indikator2);
					printf("	sgn(dynamic_pointer[0]): %d \n", sgn(dynamic_pointer[0]));
					printf("	sgn(dynamic_pointer[1]): %d \n", sgn(dynamic_pointer[1]));
					printf("	position[0]: %u \n", position[0]);
					printf("	position[1]: %u \n", position[1]);
					
					printf("	\n");
					printf("	Object position: (%u, %u) \n", position[1], position[0]);
					printf("	Weg s: (%d, %d) \n", dynamic_pointer[1], dynamic_pointer[0]);
					printf("	Geschw. v: (%d, %d) \n", dynamic_pointer[3], dynamic_pointer[2]);
					printf("	Beschl. a: (%d, %d) \n", dynamic_pointer[5], dynamic_pointer[4]);
					printf("	Impact  y(+erd): (%d, %d) \n", dynamic_pointer[7]+erd, dynamic_pointer[6]);
					printf("	ffffffff\n");
					printf("	\n");	//test
					//*/
					iteration += 1;
					
					if (position[0] == 1) {	//links
						if ((number_of_players == 2)||(number_of_players == 3)||(number_of_players == 4)||(number_of_players == 5)) {
							for (unsigned int i=1; i<m-1; i+=1) {
								for (unsigned int j=1; j<n-1; j+=1) {
									if (Sf[i][j] == 1) {
										Sf[i][j] = 0;
									}
								}
							}
							if (ges[1] != 1010) {
								printf("	Player 1, you are out \n");
								ges[1] = 1010;
								player_counter += 1;
							}
							
						} else if (number_of_players == 6) {
							for (unsigned int i=1; i<m-1; i+=1) {
								for (unsigned int j=1; j<n-1; j+=1) {
									if ((Sf[i][j] == 1)||(Sf[i][j] == 4)) {
										Sf[i][j] = 0;
									}
								}
							}
							if (ges[1] != 1010) {
								printf("	Player 1, you are out \n");
								ges[1] = 1010;
								player_counter += 1;
							}
							if (ges[4] != 4040) {
								printf("	Player 4, you are out \n");
								ges[4] = 4040;
								player_counter += 1;
							}
							
						} else if ((number_of_players == 7)||(number_of_players == 8)) {
							for (unsigned int i=1; i<m-1; i+=1) {
								for (unsigned int j=1; j<n-1; j+=1) {
									if ((Sf[i][j] == 1)||(Sf[i][j] == 5)) {
										Sf[i][j] = 0;
									}
								}
							}
							if (ges[1] != 1010) {
								printf("	Player 1, you are out \n");
								ges[1] = 1010;
								player_counter += 1;
							}
							if (ges[5] != 5050) {
								printf("	Player 5, you are out \n");
								ges[5] = 5050;
								player_counter += 1;
							}
							
						} else if (number_of_players == 9) {
							for (unsigned int i=1; i<m-1; i+=1) {
								for (unsigned int j=1; j<n-1; j+=1) {
									if ((Sf[i][j] == 1)||(Sf[i][j] == 4)||(Sf[i][j] == 7)) {
										Sf[i][j] = 0;
									}
								}
							}
							if (ges[1] != 1010) {
								printf("	Player 1, you are out \n");
								ges[1] = 1010;
								player_counter += 1;
							}
							if (ges[4] != 4040) {
								printf("	Player 4, you are out \n");
								ges[4] = 4040;
								player_counter += 1;
							}
							if (ges[7] != 7070) {
								printf("	Player 7, you are out \n");
								ges[7] = 7070;
								player_counter += 1;
							}
						}
						
					} else if (position[1] == 1) {	//oben
						if ((number_of_players == 3)||(number_of_players == 4)||(number_of_players == 5)||(number_of_players == 7)) {
							for (unsigned int i=1; i<m-1; i+=1) {
								for (unsigned int j=1; j<n-1; j+=1) {
									if (Sf[i][j] == 2) {
										Sf[i][j] = 0;
									}
								}
							}
							if (ges[2] != 2020) {
								printf("	Player 2, you are out \n");
								ges[2] = 2020;
								player_counter += 1;
							}
							
						} else if (number_of_players == 6) {
							for (unsigned int i=1; i<m-1; i+=1) {
								for (unsigned int j=1; j<n-1; j+=1) {
									if ((Sf[i][j] == 2)||(Sf[i][j] == 5)) {
										Sf[i][j] = 0;
									}
								}
							}
							
							if (ges[2] != 2020) {
								printf("	Player 2, you are out \n");
								ges[2] = 2020;
								player_counter += 1;
							}
							if (ges[5] != 5050) {
								printf("	Player 5, you are out \n");
								ges[5] = 5050;
								player_counter += 1;
							}
							
						} else if (number_of_players == 8) {
							for (unsigned int i=1; i<m-1; i+=1) {
								for (unsigned int j=1; j<n-1; j+=1) {
									if ((Sf[i][j] == 2)||(Sf[i][j] == 6)) {
										Sf[i][j] = 0;
									}
								}
							}
							
							if (ges[2] != 2020) {
								printf("	Player 2, you are out \n");
								ges[2] = 2020;
								player_counter += 1;
							}
							if (ges[6] != 6060) {
								printf("	Player 6, you are out \n");
								ges[6] = 6060;
								player_counter += 1;
							}
							
						} else if (number_of_players == 9) {
							for (unsigned int i=1; i<m-1; i+=1) {
								for (unsigned int j=1; j<n-1; j+=1) {
									if ((Sf[i][j] == 2)||(Sf[i][j] == 5)||(Sf[i][j] == 8)) {
										Sf[i][j] = 0;
									}
								}
							}
							if (ges[2] != 2020) {
								printf("	Player 2, you are out \n");
								ges[2] = 2020;
								player_counter += 1;
							}
							if (ges[5] != 5050) {
								printf("	Player 5, you are out \n");
								ges[5] = 5050;
								player_counter += 1;
							}
							if (ges[8] != 8080) {
								printf("	Player 8, you are out \n");
								ges[8] = 8080;
								player_counter += 1;
							}
						}
						
					} else if (position[0] == n-2) {	//rechts
						if ((number_of_players == 3)||(number_of_players == 4)||(number_of_players == 5)) {
							for (unsigned int i=1; i<m-1; i+=1) {
								for (unsigned int j=1; j<n-1; j+=1) {
									if (Sf[i][j] == 3) {
										Sf[i][j] = 0;
									}
								}
							}
							if (ges[3] != 3030) {
								printf("	Player 3, you are out \n");
								ges[3] = 3030;
								player_counter += 1;
							}
							
						} else if ((number_of_players == 6)||(number_of_players == 7)) {
							for (unsigned int i=1; i<m-1; i+=1) {
								for (unsigned int j=1; j<n-1; j+=1) {
									if ((Sf[i][j] == 3)||(Sf[i][j] == 6)) {
										Sf[i][j] = 0;
									}
								}
							}
							
							if (ges[3] != 3030) {
								printf("	Player 3, you are out \n");
								ges[3] = 3030;
								player_counter += 1;
							}
							if (ges[6] != 6060) {
								printf("	Player 6, you are out \n");
								ges[6] = 6060;
								player_counter += 1;
							}
							
						} else if (number_of_players == 8) {
							for (unsigned int i=1; i<m-1; i+=1) {
								for (unsigned int j=1; j<n-1; j+=1) {
									if ((Sf[i][j] == 3)||(Sf[i][j] == 7)) {
										Sf[i][j] = 0;
									}
								}
							}
							if (ges[3] != 3030) {
								printf("	Player 3, you are out \n");
								ges[3] = 3030;
								player_counter += 1;
							}
							if (ges[7] != 7070) {
								printf("	Player 7, you are out \n");
								ges[7] = 7070;
								player_counter += 1;
							}
							
						} else if (number_of_players == 2) {
							for (unsigned int i=1; i<m-1; i+=1) {
								for (unsigned int j=1; j<n-1; j+=1) {
									if (Sf[i][j] == 2) {
										Sf[i][j] = 0;
									}
								}
							}
							if (ges[2] != 2020) {
								printf("	Player 2, you are out \n");
								ges[2] = 2020;
								player_counter += 1;
							}
							
						} else if (number_of_players == 9) {
							for (unsigned int i=1; i<m-1; i+=1) {
								for (unsigned int j=1; j<n-1; j+=1) {
									if ((Sf[i][j] == 3)||(Sf[i][j] == 6)||(Sf[i][j] == 9)) {
										Sf[i][j] = 0;
									}
								}
							}
							if (ges[3] != 3030) {
								printf("	Player 3, you are out \n");
								ges[3] = 3030;
								player_counter += 1;
							}
							if (ges[6] != 6060) {
								printf("	Player 6, you are out \n");
								ges[6] = 6060;
								player_counter += 1;
							}
							if (ges[9] != 9090) {
								printf("	Player 9, you are out \n");
								ges[9] = 9090;
								player_counter += 1;
							}
							
						}
						
					} else if (position[1] == m-2) {		//unten
						if (number_of_players == 4) {
							for (unsigned int i=1; i<m-1; i+=1) {
								for (unsigned int j=1; j<n-1; j+=1) {
									if (Sf[i][j] == 4) {
										Sf[i][j] = 0;
									}
								}
							}
							if (ges[4] != 4040) {
								printf("	Player 4, you are out \n");
								ges[4] = 4040;
								player_counter += 1;
							}
							
						} else if (number_of_players == 5) {
							for (unsigned int i=1; i<m-1; i+=1) {
								for (unsigned int j=1; j<n-1; j+=1) {
									if ((Sf[i][j] == 4)||(Sf[i][j] == 5)) {
										Sf[i][j] = 0;
									}
								}
							}
							if (ges[4] != 4040) {
								printf("	Player 4, you are out \n");
								ges[4] = 4040;
								player_counter += 1;
							}
							if (ges[5] != 5050) {
								printf("	Player 5, you are out \n");
								ges[5] = 5050;
								player_counter += 1;
							}
							
						} else if (number_of_players == 7) {
							for (unsigned int i=1; i<m-1; i+=1) {
								for (unsigned int j=1; j<n-1; j+=1) {
									if ((Sf[i][j] == 4)||(Sf[i][j] == 7)) {
										Sf[i][j] = 0;
									}
								}
							}
							if (ges[4] != 4040) {
								printf("	Player 4, you are out \n");
								ges[4] = 4040;
								player_counter += 1;
							}
							if (ges[7] != 7070) {
								printf("	Player 7, you are out \n");
								ges[7] = 7070;
								player_counter += 1;
							}
							
						} else if (number_of_players == 8) {
							for (unsigned int i=1; i<m-1; i+=1) {
								for (unsigned int j=1; j<n-1; j+=1) {
									if ((Sf[i][j] == 4)||(Sf[i][j] == 8)) {
										Sf[i][j] = 0;
									}
								}
							}
							if (ges[4] != 4040) {
								printf("	Player 4, you are out \n");
								ges[4] = 4040;
								player_counter += 1;
							}
							if (ges[8] != 8080) {
								printf("	Player 8, you are out \n");
								ges[8] = 8080;
								player_counter += 1;
							}
							
						}
						
					}
					
					indikator1 = 0;		
					indikator2 = 0;		//Staffelung: grösser im Betrag 1, anderer nur geblockt 3, anderer reflektiert 5, anderer Null-Betrag 5		3 und 5 und 5 schließen sich aus
					
					controll = 0;
					
					if (abs(dynamic_pointer[0])>abs(dynamic_pointer[1])) {	//indikator1, position[0], dynamic_pointer[0] horizontal
						indikator1 += 1;
					} else if (abs(dynamic_pointer[0])<abs(dynamic_pointer[1])) {
						indikator2 += 1;
					}
					
					if (sgn(dynamic_pointer[0])>0) {	//Betrag = 0 wird verhindert
						for (unsigned int j=position[0]+1; j<n-1; j+=1) {
							if ((Sf[position[1]][j] == 0)&&(position[0]+1 < n-1)) {
								space_j = j;
								if (j != position[0]+1) {
									indikator2 += 3;
								}
								controll = 1;
								break;
							}
						}
						if ((indikator2 < 3)&&(controll != 1)) {
							indikator2 += 5;
						}
					} else if (sgn(dynamic_pointer[0])<0) {
						for (unsigned int j=position[0]-1; j>0; j-=1) {
							if ((Sf[position[1]][j] == 0)&&(position[0]-1 > 0)) {
								space_j = j; 
								if (j != position[0]-1) {
									indikator2 += 3;
								}
								controll = 1;
								break;
							}
						}
						if ((indikator2 < 3)&&(controll != 1)) {
							indikator2 += 5;
						}
					} else if (sgn(dynamic_pointer[0]) == 0) {
						indikator2 += 5;
					}
					controll = 0;
					
					if (sgn(dynamic_pointer[1])>0) {	//Betrag = 0 wird verhindert
						for (unsigned int i=position[1]+1; i<m-1; i+=1) {
							if ((Sf[i][position[0]] == 0)&&(position[1]+1 < m-1)) {
								space_i = i;
								if (i != position[1]+1) {
									indikator1 += 3;
								}
								controll = 1;
								break;
							}
						}
						if ((indikator1 < 3)&&(controll != 1)) {
							indikator1 += 5;
						}
					} else if (sgn(dynamic_pointer[1])<0) {
						for (unsigned int i=position[1]-1; i>0; i-=1) {
							if ((Sf[i][position[0]] == 0)&&(position[1]-1 > 0)) {
								space_i = i;
								if (i != position[1]-1) {
									indikator1 += 3;
								}
								controll = 1;
								break;
							}
						}
						if ((indikator1 < 3)&&(controll != 1)) {
							indikator1 += 5;
						}
					} else if (sgn(dynamic_pointer[1]) == 0) {	//Betrag = 0 hier angenommen
						indikator1 += 5;
					}
					controll = 0;
					
					
					if ((abs(dynamic_pointer[0]) == abs(dynamic_pointer[1])) && (indikator3 == 0)) {	//Betrag gleich, indikator3 = 1 zeigt kein Fortschritt auf diesem Weg.
						
						if (sgn(dynamic_pointer[0]) == sgn(dynamic_pointer[1])) {	//Vorzeichen gleich
							
							if (sgn(dynamic_pointer[0])>0) {	//Vorzeichen positiv
								
								if ((position[0] +1 < n-1) && (position[1] +1 < m-1) && (Sf[position[1] +1][position[0] +1] == 0)) {	//Noch im Spielfeld? Ja und diagonal ist frei
									
									Sf[position[1] +1][position[0] +1] = 77;
									Sf[position[1]][position[0]] = 0;
									position[1] += 1;
									position[0] += 1;
									dynamic_pointer[0] -= 1;
									dynamic_pointer[1] -= 1;
									
								} else if ((position[0] +1 >= n-1) && (position[1] +1 >= m-1)) { //beide nein
									
									Reflection (dynamic_pointer, 0, erd);
									Reflection (dynamic_pointer, 1, erd);
									
									continue;
									
								} else if (position[0]+1 >= n-1) {	//horizontal nein
									
									Reflection (dynamic_pointer, 0, erd);
									
									continue;
									
								} else if (position[1]+1 >= m-1) {	//vertikal nein
									
									Reflection (dynamic_pointer, 1, erd);
									
									continue;
									
								} else {
									indikator3 = 1;
									continue;
								}
								
							} else if (sgn(dynamic_pointer[0])<0) {	//Vorzeichen negativ
								
								if ((position[0]-1 > 0) && (position[1]-1 > 0) && (Sf[position[1]-1][position[0]-1] == 0)) {	//Noch im Spielfeld? Ja und diagonal ist frei
									
									Sf[position[1]-1][position[0]-1] = 77;
									Sf[position[1]][position[0]] = 0;
									position[1] -= 1;
									position[0] -= 1;
									dynamic_pointer[0] += 1;
									dynamic_pointer[1] += 1;
									
								} else if ((position[0]-1 == 0) && (position[1]-1 == 0)) { //beide nein
									
									Reflection (dynamic_pointer, 0, erd);
									Reflection (dynamic_pointer, 1, erd);
									
									continue;
									
								} else if (position[0]-1 == 0) {	//horizontal nein
									
									Reflection (dynamic_pointer, 0, erd);
									
									continue;
									
								} else if (position[1]-1 == 0) {	//vertikal nein
									
									Reflection (dynamic_pointer, 1, erd);
									
									continue;
									
								} else {
									indikator3 = 1;
									continue;
								}
								
							}
							
						} else {	//unterschiedliches Vorzeichen
							
							if (sgn(dynamic_pointer[0])>0) {	//Vorzeichen horizontal positiv
							
								if ((position[0]+1 < n-1) && (position[1]-1 > 0) && (Sf[position[1]-1][position[0]+1] == 0)) {	//Noch im Spielfeld? Ja und diagonal ist frei
									
									Sf[position[1]-1][position[0]+1] = 77;
									Sf[position[1]][position[0]] = 0;
									position[1] -= 1;
									position[0] += 1;
									dynamic_pointer[0] -= 1;
									dynamic_pointer[1] += 1;
									
								} else if ((position[0]+1 >= n-1) && (position[1]-1 == 0)) { //beide nein
									
									Reflection (dynamic_pointer, 0, erd);
									Reflection (dynamic_pointer, 1, erd);
									
									continue;
									
								} else if (position[0]+1 >= n-1) {	//horizontal nein
									
									Reflection (dynamic_pointer, 0, erd);
									
									continue;
									
								} else if (position[1]-1 == 0) {	//vertikal nein
									
									Reflection (dynamic_pointer, 1, erd);
									
									continue;
									
								} else {
									indikator3 = 1;
									continue;
								}
								
							}  else if (sgn(dynamic_pointer[0])<0) {	//Vorzeichen horizontal negativ
								
								if ((position[0]-1 > 0) && (position[1]+1 < m-1) && (Sf[position[1]+1][position[0]-1] == 0)) {	//Noch im Spielfeld? Ja und diagonal ist frei
									
									Sf[position[1]+1][position[0]-1] = 77;
									Sf[position[1]][position[0]] = 0;
									position[1] += 1;
									position[0] -= 1;
									dynamic_pointer[0] += 1;
									dynamic_pointer[1] -= 1;
									
								} else if ((position[0]-1 == 0) && (position[1]+1 >= m-1)) { //beide nein
									
									Reflection (dynamic_pointer, 0, erd);
									Reflection (dynamic_pointer, 1, erd);
									
									continue;
									
								} else if (position[0] -1 == 0) {	//horizontal nein
									
									Reflection (dynamic_pointer, 0, erd);
									
									continue;
									
								} else if (position[1] +1 >= m-1) {	//vertikal nein
									
									Reflection (dynamic_pointer, 1, erd);
									
									continue;
									
								} else {
									indikator3 = 1;
									continue;
								}
								
							} 
							
						}
						
					} else if (indikator1 >= indikator2) {	//partielle Durchführung, außer bei doppelter Reflektion, nimm s_horizontal = dynamic_pointer[0]
						if (indikator2 >= 5) {
							
							if (abs(dynamic_pointer[0]) > 0) {
								Reflection (dynamic_pointer, 0, erd);
							}
							if (abs(dynamic_pointer[1]) > 0) {
								Reflection (dynamic_pointer, 1, erd);
							}
							
							continue;
							
						} else if (indikator2 >= 3) {	//moveable crash, um Reflection zu verhindern
							
							if (sgn(dynamic_pointer[0])>0) {
								for (unsigned int r=space_j; r>position[0]; r-=1) {
									Sf[position[1]][r] = Sf[position[1]][r-1];
								}
								Sf[position[1]][position[0]] = 0;
								position[0] += 1;
								dynamic_pointer[0] -= 1;
								dynamic_pointer[2] -= 1;
								dynamic_pointer[4] -= 1;
								
								if (dynamic_pointer[0] != 0) {
									dynamic_pointer[0] -= 1;
								}
								
							} else if (sgn(dynamic_pointer[0])<0) {
								for (unsigned int r=space_j; r<position[0]; r+=1) {
									Sf[position[1]][r] = Sf[position[1]][r+1];
								}
								Sf[position[1]][position[0]] = 0;
								position[0] -= 1;
								dynamic_pointer[0] += 1;
								dynamic_pointer[2] += 1;
								dynamic_pointer[4] += 1;
								
								if (dynamic_pointer[0] != 0) {
									dynamic_pointer[0] += 1;
								}
							}
							
						} else {		//freier Schritt
							if (sgn(dynamic_pointer[0])>0) {
								
								Sf[position[1]][position[0]+1] = 77;
								Sf[position[1]][position[0]] = 0;
								dynamic_pointer[0] -= 1;
								position[0] += 1;
								
							} else if (sgn(dynamic_pointer[0])<0) {
								
								Sf[position[1]][position[0]-1] = 77;
								Sf[position[1]][position[0]] = 0;
								dynamic_pointer[0] += 1;
								position[0] -= 1;
							
							}		//Diagonal-Schritt mit partieller Reflection entzieht sich dem freien Schritt
						}
						
					} else if (indikator2 >= indikator1) {	//partielle Durchführung, außer bei doppelter Reflektion, nimm s_vertikal = dynamic_pointer[1]
						if (indikator1 >= 5) {
							
							if (abs(dynamic_pointer[0]) > 0) {
								Reflection (dynamic_pointer, 0, erd);
							}
							if (abs(dynamic_pointer[1]) > 0) {
								Reflection (dynamic_pointer, 1, erd);
							}
							/*
							printf("	\n");	//test
							printf("	indikator1: %u \n", indikator1);
							printf("	indikator2: %u \n", indikator2);
							printf("	sgn(dynamic_pointer[0]): %d \n", sgn(dynamic_pointer[0]));
							printf("	sgn(dynamic_pointer[1]): %d \n", sgn(dynamic_pointer[1]));
							printf("	position[0]: %u \n", position[0]);
							printf("	position[1]: %u \n", position[1]);
							
							printf("	\n");
							printf("	Object position: (%u, %u) \n", position[1], position[0]);
							printf("	Weg s: (%d, %d) \n", dynamic_pointer[1], dynamic_pointer[0]);
							printf("	Geschw. v: (%d, %d) \n", dynamic_pointer[3], dynamic_pointer[2]);
							printf("	Beschl. a: (%d, %d) \n", dynamic_pointer[5], dynamic_pointer[4]);
							printf("	Impact  y(+erd): (%d, %d) \n", dynamic_pointer[7]+erd, dynamic_pointer[6]);
							printf("	######\n");
							printf("	\n");
							//*/
							continue;
							
						} else if (indikator1 >= 3) {	//moveable crash, um Reflection zu verhindern
							
							if (sgn(dynamic_pointer[1])>0) {
								for (unsigned int r=space_i; r>position[1]; r-=1) {
									Sf[r][position[0]] = Sf[r-1][position[0]];
								}
								Sf[position[1]][position[0]] = 0;
								position[1] += 1;
								dynamic_pointer[1] -= 1;
								dynamic_pointer[3] -= 1;
								dynamic_pointer[5] -= 1;
								
								if (dynamic_pointer[1] != 0) {
									dynamic_pointer[1] -= 1;
								}
								
							} else if (sgn(dynamic_pointer[1])<0) {
								for (unsigned int r=space_i; r<position[1]; r+=1) {
									Sf[r][position[0]] = Sf[r+1][position[0]];
								}
								Sf[position[1]][position[0]] = 0;
								position[1] -= 1;
								dynamic_pointer[1] += 1;
								dynamic_pointer[3] += 1;
								dynamic_pointer[5] += 1;
								
								if (dynamic_pointer[1] != 0) {
									dynamic_pointer[1] += 1;
								}
							}
							
						} else {		//freier Schritt
							if (sgn(dynamic_pointer[1])>0) {
								
								Sf[position[1]+1][position[0]] = 77;
								Sf[position[1]][position[0]] = 0;
								dynamic_pointer[1] -= 1;
								position[1] += 1;
								
							} else if (sgn(dynamic_pointer[1])<0) {
								
								Sf[position[1]-1][position[0]] = 77;
								Sf[position[1]][position[0]] = 0;
								dynamic_pointer[1] += 1;
								position[1] -= 1;
								
							}
						}
						
					}
					
					if (position[0] == 1) {	//links
						if ((number_of_players == 2)||(number_of_players == 3)||(number_of_players == 4)||(number_of_players == 5)) {
							for (unsigned int i=1; i<m-1; i+=1) {
								for (unsigned int j=1; j<n-1; j+=1) {
									if (Sf[i][j] == 1) {
										Sf[i][j] = 0;
									}
								}
							}
							if (ges[1] != 1010) {
								printf("	Player 1, you are out \n");
								ges[1] = 1010;
								player_counter += 1;
							}
							
						} else if (number_of_players == 6) {
							for (unsigned int i=1; i<m-1; i+=1) {
								for (unsigned int j=1; j<n-1; j+=1) {
									if ((Sf[i][j] == 1)||(Sf[i][j] == 4)) {
										Sf[i][j] = 0;
									}
								}
							}
							if (ges[1] != 1010) {
								printf("	Player 1, you are out \n");
								ges[1] = 1010;
								player_counter += 1;
							}
							if (ges[4] != 4040) {
								printf("	Player 4, you are out \n");
								ges[4] = 4040;
								player_counter += 1;
							}
							
						} else if ((number_of_players == 7)||(number_of_players == 8)) {
							for (unsigned int i=1; i<m-1; i+=1) {
								for (unsigned int j=1; j<n-1; j+=1) {
									if ((Sf[i][j] == 1)||(Sf[i][j] == 5)) {
										Sf[i][j] = 0;
									}
								}
							}
							if (ges[1] != 1010) {
								printf("	Player 1, you are out \n");
								ges[1] = 1010;
								player_counter += 1;
							}
							if (ges[5] != 5050) {
								printf("	Player 5, you are out \n");
								ges[5] = 5050;
								player_counter += 1;
							}
							
						} else if (number_of_players == 9) {
							for (unsigned int i=1; i<m-1; i+=1) {
								for (unsigned int j=1; j<n-1; j+=1) {
									if ((Sf[i][j] == 1)||(Sf[i][j] == 4)||(Sf[i][j] == 7)) {
										Sf[i][j] = 0;
									}
								}
							}
							if (ges[1] != 1010) {
								printf("	Player 1, you are out \n");
								ges[1] = 1010;
								player_counter += 1;
							}
							if (ges[4] != 4040) {
								printf("	Player 4, you are out \n");
								ges[4] = 4040;
								player_counter += 1;
							}
							if (ges[7] != 7070) {
								printf("	Player 7, you are out \n");
								ges[7] = 7070;
								player_counter += 1;
							}
						}
						
					} else if (position[1] == 1) {	//oben
						if ((number_of_players == 3)||(number_of_players == 4)||(number_of_players == 5)||(number_of_players == 7)) {
							for (unsigned int i=1; i<m-1; i+=1) {
								for (unsigned int j=1; j<n-1; j+=1) {
									if (Sf[i][j] == 2) {
										Sf[i][j] = 0;
									}
								}
							}
							if (ges[2] != 2020) {
								printf("	Player 2, you are out \n");
								ges[2] = 2020;
								player_counter += 1;
							}
							
						} else if (number_of_players == 6) {
							for (unsigned int i=1; i<m-1; i+=1) {
								for (unsigned int j=1; j<n-1; j+=1) {
									if ((Sf[i][j] == 2)||(Sf[i][j] == 5)) {
										Sf[i][j] = 0;
									}
								}
							}
							
							if (ges[2] != 2020) {
								printf("	Player 2, you are out \n");
								ges[2] = 2020;
								player_counter += 1;
							}
							if (ges[5] != 5050) {
								printf("	Player 5, you are out \n");
								ges[5] = 5050;
								player_counter += 1;
							}
							
						} else if (number_of_players == 8) {
							for (unsigned int i=1; i<m-1; i+=1) {
								for (unsigned int j=1; j<n-1; j+=1) {
									if ((Sf[i][j] == 2)||(Sf[i][j] == 6)) {
										Sf[i][j] = 0;
									}
								}
							}
							
							if (ges[2] != 2020) {
								printf("	Player 2, you are out \n");
								ges[2] = 2020;
								player_counter += 1;
							}
							if (ges[6] != 6060) {
								printf("	Player 6, you are out \n");
								ges[6] = 6060;
								player_counter += 1;
							}
							
						} else if (number_of_players == 9) {
							for (unsigned int i=1; i<m-1; i+=1) {
								for (unsigned int j=1; j<n-1; j+=1) {
									if ((Sf[i][j] == 2)||(Sf[i][j] == 5)||(Sf[i][j] == 8)) {
										Sf[i][j] = 0;
									}
								}
							}
							if (ges[2] != 2020) {
								printf("	Player 2, you are out \n");
								ges[2] = 2020;
								player_counter += 1;
							}
							if (ges[5] != 5050) {
								printf("	Player 5, you are out \n");
								ges[5] = 5050;
								player_counter += 1;
							}
							if (ges[8] != 8080) {
								printf("	Player 8, you are out \n");
								ges[8] = 8080;
								player_counter += 1;
							}
						}		//lesezeichen, outcounter
						
					} else if (position[0] == n-2) {	//rechts
						if ((number_of_players == 3)||(number_of_players == 4)||(number_of_players == 5)) {
							for (unsigned int i=1; i<m-1; i+=1) {
								for (unsigned int j=1; j<n-1; j+=1) {
									if (Sf[i][j] == 3) {
										Sf[i][j] = 0;
									}
								}
							}
							if (ges[3] != 3030) {
								printf("	Player 3, you are out \n");
								ges[3] = 3030;
								player_counter += 1;
							}
							
						} else if ((number_of_players == 6)||(number_of_players == 7)) {
							for (unsigned int i=1; i<m-1; i+=1) {
								for (unsigned int j=1; j<n-1; j+=1) {
									if ((Sf[i][j] == 3)||(Sf[i][j] == 6)) {
										Sf[i][j] = 0;
									}
								}
							}
							
							if (ges[3] != 3030) {
								printf("	Player 3, you are out \n");
								ges[3] = 3030;
								player_counter += 1;
							}
							if (ges[6] != 6060) {
								printf("	Player 6, you are out \n");
								ges[6] = 6060;
								player_counter += 1;
							}
							
						} else if (number_of_players == 8) {
							for (unsigned int i=1; i<m-1; i+=1) {
								for (unsigned int j=1; j<n-1; j+=1) {
									if ((Sf[i][j] == 3)||(Sf[i][j] == 7)) {
										Sf[i][j] = 0;
									}
								}
							}
							if (ges[3] != 3030) {
								printf("	Player 3, you are out \n");
								ges[3] = 3030;
								player_counter += 1;
							}
							if (ges[7] != 7070) {
								printf("	Player 7, you are out \n");
								ges[7] = 7070;
								player_counter += 1;
							}
							
						} else if (number_of_players == 2) {
							for (unsigned int i=1; i<m-1; i+=1) {
								for (unsigned int j=1; j<n-1; j+=1) {
									if (Sf[i][j] == 2) {
										Sf[i][j] = 0;
									}
								}
							}
							if (ges[2] != 2020) {
								printf("	Player 2, you are out \n");
								ges[2] = 2020;
								player_counter += 1;
							}
							
						} else if (number_of_players == 9) {
							for (unsigned int i=1; i<m-1; i+=1) {
								for (unsigned int j=1; j<n-1; j+=1) {
									if ((Sf[i][j] == 3)||(Sf[i][j] == 6)||(Sf[i][j] == 9)) {
										Sf[i][j] = 0;
									}
								}
							}
							if (ges[3] != 3030) {
								printf("	Player 3, you are out \n");
								ges[3] = 3030;
								player_counter += 1;
							}
							if (ges[6] != 6060) {
								printf("	Player 6, you are out \n");
								ges[6] = 6060;
								player_counter += 1;
							}
							if (ges[9] != 9090) {
								printf("	Player 9, you are out \n");
								ges[9] = 9090;
								player_counter += 1;
							}
						}
						
					} else if (position[1] == m-2) {		//unten
						if (number_of_players == 4) {
							for (unsigned int i=1; i<m-1; i+=1) {
								for (unsigned int j=1; j<n-1; j+=1) {
									if (Sf[i][j] == 4) {
										Sf[i][j] = 0;
									}
								}
							}
							if (ges[4] != 4040) {
								printf("	Player 4, you are out \n");
								ges[4] = 4040;
								player_counter += 1;
							}
							
						} else if (number_of_players == 5) {
							for (unsigned int i=1; i<m-1; i+=1) {
								for (unsigned int j=1; j<n-1; j+=1) {
									if ((Sf[i][j] == 4)||(Sf[i][j] == 5)) {
										Sf[i][j] = 0;
									}
								}
							}
							if (ges[4] != 4040) {
								printf("	Player 4, you are out \n");
								ges[4] = 4040;
								player_counter += 1;
							}
							if (ges[5] != 5050) {
								printf("	Player 5, you are out \n");
								ges[5] = 5050;
								player_counter += 1;
							}
							
						} else if (number_of_players == 7) {
							for (unsigned int i=1; i<m-1; i+=1) {
								for (unsigned int j=1; j<n-1; j+=1) {
									if ((Sf[i][j] == 4)||(Sf[i][j] == 7)) {
										Sf[i][j] = 0;
									}
								}
							}
							if (ges[4] != 4040) {
								printf("	Player 4, you are out \n");
								ges[4] = 4040;
								player_counter += 1;
							}
							if (ges[7] != 7070) {
								printf("	Player 7, you are out \n");
								ges[7] = 7070;
								player_counter += 1;
							}
							
						} else if (number_of_players == 8) {
							for (unsigned int i=1; i<m-1; i+=1) {
								for (unsigned int j=1; j<n-1; j+=1) {
									if ((Sf[i][j] == 4)||(Sf[i][j] == 8)) {
										Sf[i][j] = 0;
									}
								}
							}
							if (ges[4] != 4040) {
								printf("	Player 4, you are out \n");
								ges[4] = 4040;
								player_counter += 1;
							}
							if (ges[8] != 8080) {
								printf("	Player 8, you are out \n");
								ges[8] = 8080;
								player_counter += 1;
							}
							
						}
						
					}
					
					if ((abs(dynamic_pointer[1])+abs(dynamic_pointer[0])) == 0) {
						
						/*
						printf("	\n");	//test
						printf("	Object position: (%u, %u) \n", position[1], position[0]);
						printf("	Weg s: (%d, %d) \n", dynamic_pointer[1], dynamic_pointer[0]);
						printf("	Geschw. v: (%d, %d) \n", dynamic_pointer[3], dynamic_pointer[2]);
						printf("	Beschl. a: (%d, %d) \n", dynamic_pointer[5], dynamic_pointer[4]);
						printf("	Impact  y(+erd): (%d, %d) \n", dynamic_pointer[7]+erd, dynamic_pointer[6]);
						printf("	bbbbbbb\n");
						//*/
						break;
					}
					
					indikator3 = 0;
					
					//Feintuning
					
					dynamic_pointer[6] = 0;		//impact y_horizontal
					dynamic_pointer[7] = 0;		//impact y_vertikal
					
					impact_y_semi_square (m, n, position, d_wert, range, dynamic_pointer, Sf);
					
					if (sgn(dynamic_pointer[2] < 0)) {		//horizontal (ohne erd)
						if (sgn(dynamic_pointer[6]) > 0) {
							for (int r=1; r<=abs(erd); r+=1) {
								dynamic_pointer[2] += 1;
								if (dynamic_pointer[2] == 0) {
									break;
								}
							}
						}
					} else if (sgn(dynamic_pointer[2] > 0)) {		//dynamic_pointer[2] = v_horizontal
						if (sgn(dynamic_pointer[6]) < 0) {
							for (int r=1; r<=abs(erd); r+=1) {
								dynamic_pointer[2] -= 1;
								if (dynamic_pointer[2] == 0) {
									break;
								}
							}
						}
					}
					
					if (sgn(dynamic_pointer[4] < 0)) {		//horizontal (ohne erd)
						if (sgn(dynamic_pointer[6]) > 0) {
							for (int r=1; r<=abs(erd); r+=1) {
								dynamic_pointer[4] += 1;
								if (dynamic_pointer[4] == 0) {
									break;
								}
							}
							
							if ((abs(dynamic_pointer[4]) < abs(dynamic_pointer[6])) && (sgn(dynamic_pointer[4]) == sgn(dynamic_pointer[0]))&&(sgn(dynamic_pointer[0]) != 0)) {	//s_horizontal-Verringerung
								
								for (int r=1; r<=(abs(dynamic_pointer[6])-abs(dynamic_pointer[4])); r+=1) {
									dynamic_pointer[0] += 1;
									if (dynamic_pointer[0] == 0) {
										break;
									}
								}
							}
						}
						
					} else if (sgn(dynamic_pointer[4] > 0)) {		//dynamic_pointer[4] = a_horizontal
						if (sgn(dynamic_pointer[6]) < 0) {
							for (int r=1; r<=abs(erd); r+=1) {
								dynamic_pointer[4] -= 1;
								if (dynamic_pointer[4] == 0) {
									break;
								}
							}
							
							if ((abs(dynamic_pointer[4]) < abs(dynamic_pointer[6])) && (sgn(dynamic_pointer[4]) == sgn(dynamic_pointer[0]))&&(sgn(dynamic_pointer[0]) != 0)) {
								
								for (int r=1; r<=(abs(dynamic_pointer[6])-abs(dynamic_pointer[4])); r+=1) {	//s_horizontal-Verringerung
									dynamic_pointer[0] -= 1;
									if (dynamic_pointer[0] == 0) {
										break;
									}
								}
							}
						}
						
					} else if ((sgn(dynamic_pointer[4]) == 0) && (sgn(dynamic_pointer[2]) != 0) && (sgn(dynamic_pointer[6]) != 0)) {
						
						if (sgn(dynamic_pointer[6]) < sgn(dynamic_pointer[2])) {
							
							if ((0 < abs(dynamic_pointer[6])) && (sgn(dynamic_pointer[2]) == sgn(dynamic_pointer[0]))) {
								
								for (int r=1; r<=(abs(dynamic_pointer[6])-abs(dynamic_pointer[4])); r+=1) {	//s_horizontal-Verringerung
									dynamic_pointer[0] -= 1;
									if (dynamic_pointer[0] == 0) {
										break;
									}
								}
							}
							
						} else if (sgn(dynamic_pointer[6]) > sgn(dynamic_pointer[2])) {
							
							if ((0 < abs(dynamic_pointer[6])) && (sgn(dynamic_pointer[2]) == sgn(dynamic_pointer[0]))) {	//s_horizontal-Verringerung
								
								for (int r=1; r<=(abs(dynamic_pointer[6])-abs(dynamic_pointer[4])); r+=1) {
									dynamic_pointer[0] += 1;
									if (dynamic_pointer[0] == 0) {
										break;
									}
								}
							}
						}
						
					}
					
					
					
					
					if (sgn(dynamic_pointer[3] < 0)) {		//vertikal (mit erd)
						if (sgn(dynamic_pointer[7]+erd) > 0) {
							for (int r=1; r<=abs(erd); r+=1) {
								dynamic_pointer[3] += 1;
								if (dynamic_pointer[3] == 0) {
									break;
								}
							}
						}
					} else if (sgn(dynamic_pointer[3] > 0)) {		//dynamic_pointer[3] = v_vertikal
						if (sgn(dynamic_pointer[7]+erd) < 0) {	//<= wegen-erd-Kompensierung, zurückgenommen wegen eventuell negativer erd
							for (int r=1; r<=abs(erd); r+=1) {
								dynamic_pointer[3] -= 1;
								if (dynamic_pointer[3] == 0) {
									break;
								}
							}
						}
					}
					
					if (sgn(dynamic_pointer[5] < 0)) {		//vertikal (mit erd)
						if (sgn(dynamic_pointer[7]+erd) > 0) {
							for (int r=1; r<=abs(erd); r+=1) {
								dynamic_pointer[5] += 1;
								if (dynamic_pointer[5] == 0) {
									break;
								}
							}
							
							if ((abs(dynamic_pointer[5]) < abs(dynamic_pointer[7]+erd))&&(sgn(dynamic_pointer[5]) == sgn(dynamic_pointer[1]))&&(sgn(dynamic_pointer[1]) != 0)) {	//s_vertikal-Verringerung
								
								for (int r=1; r<=(abs(dynamic_pointer[7]+erd)-abs(dynamic_pointer[5])); r+=1) {
									dynamic_pointer[1] += 1;
									if (dynamic_pointer[1] == 0) {
										break;
									}
								}
							}
						}
						
					} else if (sgn(dynamic_pointer[5] > 0)) {		//dynamic_pointer[5] = a_vertikal
						if (sgn(dynamic_pointer[7]+erd) < 0) {	//<= wegen-erd-Kompensierung, zurückgenommen wegen eventuell negativer erd
							for (int r=1; r<=abs(erd); r+=1) {
								dynamic_pointer[5] -= 1;
								if (dynamic_pointer[5] == 0) {
									break;
								}
							}
							
							if ((abs(dynamic_pointer[5]) < abs(dynamic_pointer[7]+erd)) && (sgn(dynamic_pointer[5]) == sgn(dynamic_pointer[1]))&&(sgn(dynamic_pointer[1]) != 0)) {
								
								for (int r=1; r<=(abs(dynamic_pointer[7]+erd)-abs(dynamic_pointer[5])); r+=1) {	//s_vertikal-Verringerung
									dynamic_pointer[1] -= 1;
									if (dynamic_pointer[1] == 0) {
										break;
									}
								}
							}
						}
						
					} else if ((sgn(dynamic_pointer[5]) == 0) && (sgn(dynamic_pointer[3]) != 0) && (sgn(dynamic_pointer[7]+erd) != 0)) {
						
						if (sgn(dynamic_pointer[7]+erd) < sgn(dynamic_pointer[3])) {
							
							if ((0 < abs(dynamic_pointer[7]+erd)) && (sgn(dynamic_pointer[3]) == sgn(dynamic_pointer[1]))) {
								
								for (int r=1; r<=(abs(dynamic_pointer[7]+erd)-abs(dynamic_pointer[5])); r+=1) {	//s_vertikal-Verringerung
									dynamic_pointer[1] -= 1;
									if (dynamic_pointer[1] == 0) {
										break;
									}
								}
							}
							
						} else if (sgn(dynamic_pointer[7]+erd) > sgn(dynamic_pointer[3])) {
							
							if ((0 < abs(dynamic_pointer[7]+erd)) && (sgn(dynamic_pointer[3]) == sgn(dynamic_pointer[1]))) {	//s_vertikal-Verringerung
								
								for (int r=1; r<=(abs(dynamic_pointer[7]+erd)-abs(dynamic_pointer[5])); r+=1) {
									dynamic_pointer[1] += 1;
									if (dynamic_pointer[1] == 0) {
										break;
									}
								}
							}
						}
						
					}
					
					if ((sgn(dynamic_pointer[0]) > 0)&&(sgn(dynamic_pointer[2]) >= 0)&&(sgn(dynamic_pointer[4]) < 0)) {		//a_horizontal-verringerung
						dynamic_pointer[4] += 1;
					} else if ((sgn(dynamic_pointer[0]) < 0)&&(sgn(dynamic_pointer[2]) <= 0)&&(sgn(dynamic_pointer[4]) > 0)) {
						dynamic_pointer[4] -= 1;
					}
					
					if ((sgn(dynamic_pointer[1]) > 0)&&(sgn(dynamic_pointer[3]) >= 0)&&(sgn(dynamic_pointer[5]) < 0)) {		//a_vertikal-verringerung
						dynamic_pointer[5] += 1;
					} else if ((sgn(dynamic_pointer[1]) < 0)&&(sgn(dynamic_pointer[3]) <= 0)&&(sgn(dynamic_pointer[5]) > 0)) {
						dynamic_pointer[5] -= 1;
					}
					
					/*
					printf("	\n");	//test
					printf("	indikator1: %u \n", indikator1);
					printf("	indikator2: %u \n", indikator2);
					printf("	sgn(dynamic_pointer[0]): %d \n", sgn(dynamic_pointer[0]));
					printf("	sgn(dynamic_pointer[1]): %d \n", sgn(dynamic_pointer[1]));
					printf("	position[0]: %u \n", position[0]);
					printf("	position[1]: %u \n", position[1]);
					
					printf("	\n");
					printf("	Object position: (%u, %u) \n", position[1], position[0]);
					printf("	Weg s: (%d, %d) \n", dynamic_pointer[1], dynamic_pointer[0]);
					printf("	Geschw. v: (%d, %d) \n", dynamic_pointer[3], dynamic_pointer[2]);
					printf("	Beschl. a: (%d, %d) \n", dynamic_pointer[5], dynamic_pointer[4]);
					printf("	Impact  y(+erd): (%d, %d) \n", dynamic_pointer[7]+erd, dynamic_pointer[6]);
					printf("	\n");
					printf("	\n");
					*/
					
						//beschleunigung abbremsen, falls sgn(s)==sgn(v)!=sgn(a), done
					
				}	//komplette durchrechnung
				
			}
			
			if (gamemode == 11) {	//Ausscheiden der Teams?
				if (position[0] == 1) {	//links
					if ((number_of_players == 2)||(number_of_players == 3)||(number_of_players == 4)||(number_of_players == 5)) {
						for (unsigned int i=1; i<m-1; i+=1) {
							for (unsigned int j=1; j<n-1; j+=1) {
								if (Sf[i][j] == 1) {
									Sf[i][j] = 0;
								}
							}
						}
						if (ges[1] != 1010) {
							printf("	Player 1, you are out \n");
							ges[1] = 1010;
							player_counter += 1;
						}
						
					} else if (number_of_players == 6) {
						for (unsigned int i=1; i<m-1; i+=1) {
							for (unsigned int j=1; j<n-1; j+=1) {
								if ((Sf[i][j] == 1)||(Sf[i][j] == 4)) {
									Sf[i][j] = 0;
								}
							}
						}
						if (ges[1] != 1010) {
							printf("	Player 1, you are out \n");
							ges[1] = 1010;
							player_counter += 1;
						}
						if (ges[4] != 4040) {
							printf("	Player 4, you are out \n");
							ges[4] = 4040;
							player_counter += 1;
						}
						
					} else if ((number_of_players == 7)||(number_of_players == 8)) {
						for (unsigned int i=1; i<m-1; i+=1) {
							for (unsigned int j=1; j<n-1; j+=1) {
								if ((Sf[i][j] == 1)||(Sf[i][j] == 5)) {
									Sf[i][j] = 0;
								}
							}
						}
						if (ges[1] != 1010) {
							printf("	Player 1, you are out \n");
							ges[1] = 1010;
							player_counter += 1;
						}
						if (ges[5] != 5050) {
							printf("	Player 5, you are out \n");
							ges[5] = 5050;
							player_counter += 1;
						}
						
					} else if (number_of_players == 9) {
						for (unsigned int i=1; i<m-1; i+=1) {
							for (unsigned int j=1; j<n-1; j+=1) {
								if ((Sf[i][j] == 1)||(Sf[i][j] == 4)||(Sf[i][j] == 7)) {
									Sf[i][j] = 0;
								}
							}
						}
						if (ges[1] != 1010) {
							printf("	Player 1, you are out \n");
							ges[1] = 1010;
							player_counter += 1;
						}
						if (ges[4] != 4040) {
							printf("	Player 4, you are out \n");
							ges[4] = 4040;
							player_counter += 1;
						}
						if (ges[7] != 7070) {
							printf("	Player 7, you are out \n");
							ges[7] = 7070;
							player_counter += 1;
						}
					}
					
				} else if (position[1] == 1) {	//oben
					if ((number_of_players == 3)||(number_of_players == 4)||(number_of_players == 5)||(number_of_players == 7)) {
						for (unsigned int i=1; i<m-1; i+=1) {
							for (unsigned int j=1; j<n-1; j+=1) {
								if (Sf[i][j] == 2) {
									Sf[i][j] = 0;
								}
							}
						}
						if (ges[2] != 2020) {
							printf("	Player 2, you are out \n");
							ges[2] = 2020;
							player_counter += 1;
						}
						
					} else if (number_of_players == 6) {
						for (unsigned int i=1; i<m-1; i+=1) {
							for (unsigned int j=1; j<n-1; j+=1) {
								if ((Sf[i][j] == 2)||(Sf[i][j] == 5)) {
									Sf[i][j] = 0;
								}
							}
						}
						
						if (ges[2] != 2020) {
							printf("	Player 2, you are out \n");
							ges[2] = 2020;
							player_counter += 1;
						}
						if (ges[5] != 5050) {
							printf("	Player 5, you are out \n");
							ges[5] = 5050;
							player_counter += 1;
						}
						
					} else if (number_of_players == 8) {
						for (unsigned int i=1; i<m-1; i+=1) {
							for (unsigned int j=1; j<n-1; j+=1) {
								if ((Sf[i][j] == 2)||(Sf[i][j] == 6)) {
									Sf[i][j] = 0;
								}
							}
						}
						
						if (ges[2] != 2020) {
							printf("	Player 2, you are out \n");
							ges[2] = 2020;
							player_counter += 1;
						}
						if (ges[6] != 6060) {
							printf("	Player 6, you are out \n");
							ges[6] = 6060;
							player_counter += 1;
						}
						
					} else if (number_of_players == 9) {
						for (unsigned int i=1; i<m-1; i+=1) {
							for (unsigned int j=1; j<n-1; j+=1) {
								if ((Sf[i][j] == 2)||(Sf[i][j] == 5)||(Sf[i][j] == 8)) {
									Sf[i][j] = 0;
								}
							}
						}
						if (ges[2] != 2020) {
							printf("	Player 2, you are out \n");
							ges[2] = 2020;
							player_counter += 1;
						}
						if (ges[5] != 5050) {
							printf("	Player 5, you are out \n");
							ges[5] = 5050;
							player_counter += 1;
						}
						if (ges[8] != 8080) {
							printf("	Player 8, you are out \n");
							ges[8] = 8080;
							player_counter += 1;
						}
					}
					
				} else if (position[0] == n-2) {	//rechts
					if ((number_of_players == 3)||(number_of_players == 4)||(number_of_players == 5)) {
						for (unsigned int i=1; i<m-1; i+=1) {
							for (unsigned int j=1; j<n-1; j+=1) {
								if (Sf[i][j] == 3) {
									Sf[i][j] = 0;
								}
							}
						}
						if (ges[3] != 3030) {
							printf("	Player 3, you are out \n");
							ges[3] = 3030;
							player_counter += 1;
						}
						
					} else if ((number_of_players == 6)||(number_of_players == 7)) {
						for (unsigned int i=1; i<m-1; i+=1) {
							for (unsigned int j=1; j<n-1; j+=1) {
								if ((Sf[i][j] == 3)||(Sf[i][j] == 6)) {
									Sf[i][j] = 0;
								}
							}
						}
						
						if (ges[3] != 3030) {
							printf("	Player 3, you are out \n");
							ges[3] = 3030;
							player_counter += 1;
						}
						if (ges[6] != 6060) {
							printf("	Player 6, you are out \n");
							ges[6] = 6060;
							player_counter += 1;
						}
						
					} else if (number_of_players == 8) {
						for (unsigned int i=1; i<m-1; i+=1) {
							for (unsigned int j=1; j<n-1; j+=1) {
								if ((Sf[i][j] == 3)||(Sf[i][j] == 7)) {
									Sf[i][j] = 0;
								}
							}
						}
						if (ges[3] != 3030) {
							printf("	Player 3, you are out \n");
							ges[3] = 3030;
							player_counter += 1;
						}
						if (ges[7] != 7070) {
							printf("	Player 7, you are out \n");
							ges[7] = 7070;
							player_counter += 1;
						}
						
					} else if (number_of_players == 2) {
						for (unsigned int i=1; i<m-1; i+=1) {
							for (unsigned int j=1; j<n-1; j+=1) {
								if (Sf[i][j] == 2) {
									Sf[i][j] = 0;
								}
							}
						}
						if (ges[2] != 2020) {
							printf("	Player 2, you are out \n");
							ges[2] = 2020;
							player_counter += 1;
						}
						
					} else if (number_of_players == 9) {
						for (unsigned int i=1; i<m-1; i+=1) {
							for (unsigned int j=1; j<n-1; j+=1) {
								if ((Sf[i][j] == 3)||(Sf[i][j] == 6)||(Sf[i][j] == 9)) {
									Sf[i][j] = 0;
								}
							}
						}
						if (ges[3] != 3030) {
							printf("	Player 3, you are out \n");
							ges[3] = 3030;
							player_counter += 1;
						}
						if (ges[6] != 6060) {
							printf("	Player 6, you are out \n");
							ges[6] = 6060;
							player_counter += 1;
						}
						if (ges[9] != 9090) {
							printf("	Player 9, you are out \n");
							ges[9] = 9090;
							player_counter += 1;
						}
						
					}
					
				} else if (position[1] == m-2) {		//unten
					if (number_of_players == 4) {
						for (unsigned int i=1; i<m-1; i+=1) {
							for (unsigned int j=1; j<n-1; j+=1) {
								if (Sf[i][j] == 4) {
									Sf[i][j] = 0;
								}
							}
						}
						if (ges[4] != 4040) {
							printf("	Player 4, you are out \n");
							ges[4] = 4040;
							player_counter += 1;
						}
						
					} else if (number_of_players == 5) {
						for (unsigned int i=1; i<m-1; i+=1) {
							for (unsigned int j=1; j<n-1; j+=1) {
								if ((Sf[i][j] == 4)||(Sf[i][j] == 5)) {
									Sf[i][j] = 0;
								}
							}
						}
						if (ges[4] != 4040) {
							printf("	Player 4, you are out \n");
							ges[4] = 4040;
							player_counter += 1;
						}
						if (ges[5] != 5050) {
							printf("	Player 5, you are out \n");
							ges[5] = 5050;
							player_counter += 1;
						}
						
					} else if (number_of_players == 7) {
						for (unsigned int i=1; i<m-1; i+=1) {
							for (unsigned int j=1; j<n-1; j+=1) {
								if ((Sf[i][j] == 4)||(Sf[i][j] == 7)) {
									Sf[i][j] = 0;
								}
							}
						}
						if (ges[4] != 4040) {
							printf("	Player 4, you are out \n");
							ges[4] = 4040;
							player_counter += 1;
						}
						if (ges[7] != 7070) {
							printf("	Player 7, you are out \n");
							ges[7] = 7070;
							player_counter += 1;
						}
						
					} else if (number_of_players == 8) {
						for (unsigned int i=1; i<m-1; i+=1) {
							for (unsigned int j=1; j<n-1; j+=1) {
								if ((Sf[i][j] == 4)||(Sf[i][j] == 8)) {
									Sf[i][j] = 0;
								}
							}
						}
						if (ges[4] != 4040) {
							printf("	Player 4, you are out \n");
							ges[4] = 4040;
							player_counter += 1;
						}
						if (ges[8] != 8080) {
							printf("	Player 8, you are out \n");
							ges[8] = 8080;
							player_counter += 1;
						}
						
					}
					
				}
			}
			
			if (gamemode == 6) {	//hunt-Formalitäten
				/* test
				printf("\n");
				printf("	hboa=%u	\n", hboa);
				printf("\n");
				*/
				if (hboa == 0) {
					information_code[2] = 2;
				} else if (hboa == 1) {
					information_code[2] = 1;
				}
				
				if (round_counter == (rtc - 1)) {
					A[0] = 1;
				} else if ((round_counter == rtc)&&(geben == number_of_players)) {
					printf(" \n ");
					printf(" \n ");
					printf(" Ready for the last round? \n ");
					printf(" \n ");
					printf(" \n ");
				}
				
				if (round_counter%spf == 0) {
					information_code[1] = 1;
				} else {
					information_code[1] = 0;
				}
			}
			
			if ((gamemode == 9)||(gamemode == 10)) {	//last round
				if ((round_counter == rtp)&&(geben == number_of_players)) {
					printf(" \n ");
					printf(" \n ");
					printf(" Ready for the last round? \n ");
					printf(" \n ");
					printf(" \n ");
				}
			}
			
			/* test
			printf("\n");
			printf("	information_code: [0]=%u,	[1]=%u,	[2]=%u,	[3]=%u	\n", information_code[0], information_code[1], information_code[2], information_code[3]);
			printf("\n");
			*/
			
			temp = Spielfeld_Create (m, n);
			
			if ((journey == 1)&&((gamemode == 1)||(gamemode == 2)||(gamemode == 3))){	//journey-frequence
				printf("	All turns until the journey starts: %u \n", (19 - ((g-1)%19)));
				printf("\n");
			} else if ((journey == 1)&&((gamemode == 5)||(gamemode == 8))) {
				printf("	All turns until the journey starts: %u \n", (15 - ((g-1)%15)));
				printf("\n");
			} else if ((journey == 1)&&(gamemode == 7)) {
				printf("	All turns until the journey starts: %u \n", ((2*freq) - ((g-1)%(2*freq))));
				printf("\n");
			} else if ((journey == 1)&&((gamemode == 6)||(gamemode == 9)||(gamemode == 10)||(gamemode == 11)||(gamemode == 12))) {	//10
				printf("	All turns until the journey starts: %u \n", ((10*(number_of_players-player_counter) - 1) - ((g-1)%(10*(number_of_players-player_counter) - 1))));
				printf("\n");
			}
			
			if (gamemode == 7) {
				printf("	All turns until the wall moves forward: %u \n", (freq - ((g-1)%freq)));
				printf("\n");
			}
			
			printf("\n");
			printf("	Round: %u \n", round_counter);
			printf("\n");
			
			if (geben == 1) {
				
				if (opague >= 1) {
					Sf_opague = opague_builder (Sf, m, n, geben, opague, aop);
					
				}
				
				if ((ttt != 0)&&(pere[geben] == 100)) {
					g+=1;
					continue;
				}
				
				if ((ges[geben] == 1010)&&((gamemode == 6)||(gamemode == 9)||(gamemode == 10)||(gamemode == 11)||(gamemode == 12))) {	//10	//Überspringen, wenn ausgeschieden
					g+=1;
					var_[geben] = 1010;		//eigentlich var_[geben] = 1010*geben;
					for (unsigned int i=1; i<m-1; i+=1){
						for (unsigned int j=1; j<n-1; j+=1){
							if (journey == 1){
								if (Sf_journey[i][j] == geben) {
									Sf_journey[i][j] = 0;
								}
							}
							if (number_of_players == 2) {	//number_of_players = 1 kann hier nicht auftreten
								cons_field_1[i][j] = cons_field_2[i][j];
								cons[geben] = cons[2];	// = vorgänger
								if (journey == 1){
									cons_journey_1[i][j] = cons_journey_2[i][j];
								}
								for (unsigned int p=2; p<=5; p+=1) {
									
									dynamic_pointer_save[2][p-2] = dynamic_pointer_save[geben][p-2]; // if geben == 1 => number_of_players, sonst geben-1	(maybe a function)
									
								}
							} else if (number_of_players == 3) {
								cons_field_1[i][j] = cons_field_3[i][j];
								cons[1] = cons[3];
								if (journey == 1){
									cons_journey_1[i][j] = cons_journey_3[i][j];
								}
								for (unsigned int p=2; p<=5; p+=1) {
									
									dynamic_pointer_save[3][p-2] = dynamic_pointer_save[1][p-2];
									
								}
							} else if (number_of_players == 4) {
								cons_field_1[i][j] = cons_field_4[i][j];
								cons[1] = cons[4];
								if (journey == 1){
									cons_journey_1[i][j] = cons_journey_4[i][j];
								}
								for (unsigned int p=2; p<=5; p+=1) {
									
									dynamic_pointer_save[4][p-2] = dynamic_pointer_save[1][p-2];
									
								}
							} else if (number_of_players == 5) {
								cons_field_1[i][j] = cons_field_5[i][j];
								cons[1] = cons[5];
								if (journey == 1){
									cons_journey_1[i][j] = cons_journey_5[i][j];
								}
								for (unsigned int p=2; p<=5; p+=1) {
									
									dynamic_pointer_save[5][p-2] = dynamic_pointer_save[1][p-2];
									
								}
							} else if (number_of_players == 6) {
								cons_field_1[i][j] = cons_field_6[i][j];
								cons[1] = cons[6];
								if (journey == 1){
									cons_journey_1[i][j] = cons_journey_6[i][j];
								}
								for (unsigned int p=2; p<=5; p+=1) {
									
									dynamic_pointer_save[6][p-2] = dynamic_pointer_save[1][p-2];
									
								}
							} else if (number_of_players == 7) {
								cons_field_1[i][j] = cons_field_7[i][j];
								cons[1] = cons[7];
								if (journey == 1){
									cons_journey_1[i][j] = cons_journey_7[i][j];
								}
								for (unsigned int p=2; p<=5; p+=1) {
									
									dynamic_pointer_save[7][p-2] = dynamic_pointer_save[1][p-2];
									
								}
							} else if (number_of_players == 8) {
								cons_field_1[i][j] = cons_field_8[i][j];
								cons[1] = cons[8];
								if (journey == 1){
									cons_journey_1[i][j] = cons_journey_8[i][j];
								}
								for (unsigned int p=2; p<=5; p+=1) {
									
									dynamic_pointer_save[8][p-2] = dynamic_pointer_save[1][p-2];
									
								}
							} else if (number_of_players == 9) {
								cons_field_1[i][j] = cons_field_9[i][j];
								cons[1] = cons[9];
								if (journey == 1){
									cons_journey_1[i][j] = cons_journey_9[i][j];
								}
								for (unsigned int p=2; p<=5; p+=1) {
									
									dynamic_pointer_save[9][p-2] = dynamic_pointer_save[1][p-2];
									
								}
							}
						}
					}
					if (var_[0] == 1) {
						g-=2;
					}
					continue;
				}
				
				w = 3;
				d = 2;
				e = 3;
				
				if (gamemode == 9) {	//arena-abilities werden eingesetzt
				
					for (unsigned int i=4; i<=aop-1; i+=1) {
						if (ability[i] == geben) {
							information_code[0] = i;
						}
					}
					
					if (ability[1] == geben) {
						w = 1;
						d = 0;
						e = 1;
						information_code[0] = 1;
					} else if (ability[2] == geben) {
						w = 2;
						d = 1;
						e = 2;
						information_code[0] = 2;
					} else if (ability[3] == geben) {
						w = 4;
						d = 1;
						e = 4;	//abweichende e-definition
						information_code[0] = 3;
					} else if (ability[9] == geben) {
						information_code[0] = 9;
					
						if (opague >= 1) {
							show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
						} else {
							show_field (Sf, m, n, gamemode, information_code, geben, Colored);
						}
						
						for (unsigned int i=1; i<m-1; i+=1){
							for (unsigned int j=1; j<n-1; j+=1){
								if (Sf[i][j] == geben) {
									if ((Sf[i+1][j] != 0)&&(Sf[i+1][j] != geben)&&((i+2) <= (m-2))) {
										if (Sf[i+2][j] == 0) {
											Sf[i+2][j] = Sf[i+1][j];
											Sf[i+1][j] = 0;
										}
									}
									if ((Sf[i-1][j] != 0)&&(Sf[i-1][j] != geben)&&((i-2) >= 1)) {
										if (Sf[i-2][j] == 0) {
											Sf[i-2][j] = Sf[i-1][j];
											Sf[i-1][j] = 0;
										}
									}
									if ((Sf[i][j-1] != 0)&&(Sf[i][j-1] != geben)&&((j-2) >= 1)) {
										if (Sf[i][j-2] == 0) {
											Sf[i][j-2] = Sf[i][j-1];
											Sf[i][j-1] = 0;
										}
									}
									if ((Sf[i][j+1] != 0)&&(Sf[i][j+1] != geben)&&((j+2) <= (n-2))) {
										if (Sf[i][j+2] == 0) {
											Sf[i][j+2] = Sf[i][j+1];
											Sf[i][j+1] = 0;
										}
									}
								}
							}
						}
					}
				}	// Done : index, show_field, var == 62,	start_normal, dies, != 6, hint, new_life, old_dying, ability_used_counter, 	  übertragen: /	 to do:	/	yes!
				
				if (gamemode == 9) {	//light und ultra_light erhalten gekürzte limit_at_all, beim Rest wird der richte Wert eingesetzt
					if (information_code[0] == 1) {
						limit_at_all = limit_at_all_saver-2;
					} else if (information_code[0] == 2) {
						limit_at_all = limit_at_all_saver-1;
					} else {
						limit_at_all = limit_at_all_saver;
					}
				}
				
				if (ttt != 0) {		//Strafen wegen der Zeit
					if ((pere[geben] != 0)&&(warning_system <= 5)&&((pere[geben]+warning_system) == 7)) {
						g += 1;
						printf(" \n ");
						printf("	You got a penalty. \n ");
						printf(" \n ");
						pere[geben] = 0;
						continue;
					} else if ((pere[geben] != 0)&&(warning_system != 0)&&(((warning_system <= 5)&&((pere[geben]+warning_system) == 8))||((warning_system == 6)&&(pere[geben] == 1)))) {
						Sf_od_1 = old_dying_1 (Sf, m, n, d, e, gamemode, information_code);
						Sf = change_1 (Sf, Sf_nl_1, Sf_od_1, m, n, gamemode, number_of_players, ges); 	//Change befreit
						g += 1;
						printf(" \n ");
						printf("	You got a penalty. \n ");
						printf(" \n ");
						pere[geben] = 0;
						continue;
					} else if (((warning_system <= 5)&&((warning_system + pere[geben]) >= 9))||((warning_system >= 6)&&((warning_system + pere[geben]) >= 8))) {
						printf("	Niederlage: Spieler %u \n ", geben);
						for (unsigned int i=1; i<m-1; i+=1){
							for (unsigned int j=1; j<n-1; j+=1){
								if (Sf[i][j] == geben) {
									Sf[i][j] = 0;
								}
							}
						}
						ges[geben] = 1010*geben;
						player_counter += 1;
						pere[geben] = 100;
						g += 1;
						continue;
					}
				}
				
				if (var_[geben] == 1010) {
					use_number = cons[geben];
					if (opt == 5) {
					
						printf("	Player %u ,do you want to keep your number (%u) or do you want to get the next one? \n", geben, cons[geben]);
						printf("	Keep the number: 	1 \n");
						printf("	Get the next one:	2 \n");
						scanf("%u", &lim);
						
						if (lim == 2) {
							use_number = random_number (num_1, num_2, num_3, use_number, g, var_, number_3, number_4);
						} else if (lim != 1) {
							printf("	Well, you keep your number, but next time please take an option i offered. \n\n");
						}
						lim = 0;
					
					}
				}
				
				if (var_[geben%number_of_players+1] == 1010){		//geben%number_of_players+1 ist der Nachfolger von geben.
					if (tac != 0) {
						if (number_1 <= 5){
							C[number_1] += 1;
						} else if (number_1 == 6){
							C[0] += 1;
						}
					} else if (opt == 5) {
						A[use_number] -= 1;
					} else {
						A[number_1] -= 1;
					}
					
				}
				
				if ((tac != 0)&&((C[1]+C[2]+C[3]+C[4]+C[5]+C[0]) == 0)){
					for (unsigned int p=0; p<=5; p+=1){
						C[p] = tac;
					}
				}
				
				menuoperator = 1;		//Ende der Vorbereitung
				
				//#-start
				while (menuoperator != 0) {		//Beginn des Zuges
					
					if (gamemode != 8) {
						if (opague >= 1) {
							show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
						} else {
							show_field (Sf, m, n, gamemode, information_code, geben, Colored);
						}
					}
					
					if (gamemode == 4) {
						printf("\n");
						printf("	Points player %u: 	%u Point(s) \n", geben, P[geben]);
					}
					
					if (gamemode == 10) {
						printf("\n");
						printf("	Lifes player %u: 	%u Life(s) \n", geben, ulcer_lifes[1]);
					}
					
					if (gamemode == 11) {
						printf("	\n");
						printf("	Geschwindigkeit: 	Zeile: %d, 	Spalte: %d \n", dynamic_pointer[2], dynamic_pointer[3]);
						printf("	Beschleunigung: 	Zeile: %d, 	Spalte: %d \n", dynamic_pointer[4], dynamic_pointer[5]);
						printf("	\n");
					}
					
					printf("\n");
					
					if (Colored[0] == 1) {
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+Colored[geben]);
					}
					
					if ((gamemode != 6)&&(gamemode != 9)&&(gamemode != 10)&&(gamemode != 11)&&(gamemode != 12)){	//10
						printf("	Am Zug: Spieler %u (**)	\n", geben);	//if
					} else if (gamemode == 6) {
						printf("	Am Zug: Spieler %u (##)	\n", geben);	//if
					} else if (gamemode == 9) {
						if (ability[1] == geben) {
							printf("	Am Zug: Spieler %u (UU)	\n", geben);
						} else if (ability[2] == geben) {
							printf("	Am Zug: Spieler %u (LL)	\n", geben);
						} else if (ability[3] == geben) {
							printf("	Am Zug: Spieler %u (AA)	\n", geben);
						} else if (ability[4] == geben) {
							printf("	Am Zug: Spieler %u (CC)	\n", geben);
						} else if (ability[5] == geben) {
							printf("	Am Zug: Spieler %u (II)	\n", geben);
						} else if (ability[6] == geben) {
							printf("	Am Zug: Spieler %u (SS)	\n", geben);
						} else if (ability[7] == geben) {
							printf("	Am Zug: Spieler %u (PP)	\n", geben);
						} else if (ability[8] == geben) {
							printf("	Am Zug: Spieler %u (HH)	\n", geben);
						} else if (ability[9] == geben) {
							printf("	Am Zug: Spieler %u (EE)	\n", geben);
						}
					} else if ((gamemode == 10)||(gamemode == 11)||(gamemode == 12)) {	//10
						printf("	Am Zug: Spieler %u (%u%u)	\n", geben, geben, geben);
					}
					
					if (Colored[0] == 1) {
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+7);
					}
					
					printf("\n");
					
					if (tac != 0){
						printf("	Your stack of numbers:	\n	1) [%u],		2) [%u],		3) [%u], \n\n	4) [%u],		5) [%u],		6) [%u],\n", C[1], C[2], C[3], C[4], C[5], C[0]);
						printf("\n");
						printf("\n");
					}
					
					if (opt == 5){		//random number
						printf("	Your number: %u ", use_number);
						printf("\n");
						printf("\n");
										//##
					}
					
					//#-end
					
					printf("	1) Plus:	11	Minus:	12 \n");
					printf("	2) Move:	21	Change:	22 \n");
					printf("	3) Destroy:	31	Revive:	32 \n");
					printf("	4) Move:	41	Boost:	42 \n");
					if (((gamemode != 9)&&(gamemode != 10))||((gamemode == 10)&&(geben == 1))) {	//10
						printf("	5) 4/5-new:	51	2-new:	52 \n");
						printf("	6) 4-max:	61	1-min:	62 \n");
					} else if (gamemode == 9) {
						if (information_code[0] == 1) {
							printf("	5) 2/3-new:	51	0-new:	52 \n");
							printf("	6) 2-max:	61	-1-min:	62 \n");
						} else if (information_code[0] == 2) {
							printf("	5) 3/4-new:	51	1-new:	52 \n");
							printf("	6) 3-max:	61	0-min:	62 \n");
						} else if (information_code[0] == 3) {
							printf("	5) 5/6-new:	51	3-new:	52 \n");
							printf("	6) 5-max:	61	0-min:	62 \n");
						} else {
							printf("	5) 4/5-new:	51	2-new:	52 \n");
							printf("	6) 4-max:	61	1-min:	62 \n");
						}
					} else if ((gamemode == 10)&&(geben != 1)) {	//10
						printf("	5) 3/4-new:	51	1-new:	52 \n");
						printf("	6) 3-max:	61	0-min:	62 \n");
					}
					printf("							\n");
					printf("		Go back: 100 \n");
					printf("		Menu: 10 \n");
					printf("		End game: 0 \n");
					if ((ttt != 0)&&(time_saver == 0.0)) {
						time1 = time(NULL);
					}
					scanf("%u", &var_[geben]);
					
					//printf("	Checkpoint: var_[geben] \n");	//test
					
					if (var_[geben] == 10){
						if (ttt != 0) {
							time3 = time(NULL);
						}
						
						while (menuoperator != 7) {
							printf("\n");
							printf("\n");
							printf("	About the game: 1 \n	Statistics: 2 \n	The numbers: 3 \n	The limits: 4 \n	Get Hints: 5 \n	Suprise: 6 \n	Quit Menu: 7 \n");
							scanf("%u", &menuoperator);
							
							if (menuoperator == 1){
								if (gamemode == 1) {
									printf("	How to win? 	Own a square on your last line or force your opponent to lose all his/her ones.\n");
								} else if (gamemode == 2) {
									printf("	How to win? 	Be at 2 of the 3 targets with three of your squares near-by.\n");
								} else if (gamemode == 3) {
									printf("	How to win? 	Take over all your opponent's squares by winning contact-battles.\n");
									printf("	Contact-battles? 	All near-by squares in a row with the contact-square build a chain, beat your opponent in the length.\n");
								} else if (gamemode == 4) {
									printf("	How to win? 	Get more points than your opponent.\n");
									printf("	Note:	Touch the #-square in the near-by to move it to the opposite side. \n");
								} else if (gamemode == 5) {
									printf("	How to win? 	Force your opponent to lose all his/her squares.\n");
								} else if (gamemode == 6) {
									if (geben == 1) {
										printf("	How to win? 	Protect your heart-block so no enemy can touch it.\n");
									} else {
										printf("	How to win? 	Catch the heart-block of the hunted one before it disappears.\n");
									}
								} else if (gamemode == 7) {
									printf("	How to win? 	Reach the end of the field or force your opponent to lose all his/her ones.\n");
									printf("	Note:	Every %u turns in total the #-line will go ahead and destroys everything in it's way.\n Also you are not allowed to cross the mid-line. \n", freq);
								} else if (gamemode == 8) {
									printf("	How to win? 	Reach [1][7] of the field or force your opponent to lose all his/her squares.\n");
									printf("	Note:	Falling down the #-squares will push, destroy, explode, or teleport, transform into yours by contact. \n");
								} else if ((gamemode == 9)||(gamemode == 10)) {	//10
									printf("	How to win? 	Force your opponent to lose all his/her squares while keeping yours alive.\n");
								} else if (gamemode == 11) {
									printf("	How to win? 	Push the ball against your opponent's side.\n");
								} else if (gamemode == 12) {
									printf("	How to win? 	Stay alive.\n");
								}
								printf("	Surrounding:	The 8 squares around another, at the edge 5, in the corners 3, are called #surrounding. \n");
								printf("	near-by:	The 4 squares around another, at the edge 3, in the corners 2, are called #near-by. \n");
								printf("	Standard actions:	(After your choice of number and not influencing each other) \n	-Development:	If it is your turn and a free square has exactly %u of yours surrounding it, you will own it.\n", w);
								printf("	-Losses: 	If it is your turn and a square of yours is surrounded by less than %u or more than %u of yours,\n			it will be set free.\n", d, e);	//10
								if (gamemode == 6) {	//If geben == 1
									printf("	Limits: 	Your development is limited by %u per round, your units in total by %u per round. \n", (limit_new+(number_of_players-3)), (limit_at_all+(2*(number_of_players-3))));
								} else if ((gamemode == 10)||(gamemode == 12)) {
									printf("	Limits: 	This gamemode is unlimited. \n");
								} else if (gamemode == 3) {
									printf("	Limits: 	Your development is limited by %u per round. \n", limit_new);
								} else if (gamemode != 6) {
									printf("	Limits: 	Your development is limited by %u per round, your units in total by %u per round. \n", limit_new, limit_at_all);
								}
							}
					
							if (menuoperator == 2){
								printf("\n");
								printf("	turns at all: %u \n", g);
								printf("\n");
								printf("	Numbers of player %u: \n", geben);
								printf("		#1 = %u \n", A[1]);
								printf("		#2 = %u \n", A[2]);
								printf("		#3 = %u \n", A[3]);
								printf("		#4 = %u \n", A[4]);
								printf("		#5 = %u \n", A[5]);
								printf("		#6 = %u \n", A[6]);
								printf("\n");
								if (number_of_players >= 2) {
									printf("	Numbers of player 2: \n");
									printf("		#1 = %u \n", B[1]);
									printf("		#2 = %u \n", B[2]);
									printf("		#3 = %u \n", B[3]);
									printf("		#4 = %u \n", B[4]);
									printf("		#5 = %u \n", B[5]);
									printf("		#6 = %u \n", B[6]);
									printf("\n");
								}
								if (number_of_players >= 3){
									printf("	Numbers of player 3: \n");
									printf("		#1 = %u \n", AA[1]);
									printf("		#2 = %u \n", AA[2]);
									printf("		#3 = %u \n", AA[3]);
									printf("		#4 = %u \n", AA[4]);
									printf("		#5 = %u \n", AA[5]);
									printf("		#6 = %u \n", AA[6]);
									printf("\n");
								}
								if (number_of_players >= 4){
									printf("	Numbers of player 4: \n");
									printf("		#1 = %u \n", BB[1]);
									printf("		#2 = %u \n", BB[2]);
									printf("		#3 = %u \n", BB[3]);
									printf("		#4 = %u \n", BB[4]);
									printf("		#5 = %u \n", BB[5]);
									printf("		#6 = %u \n", BB[6]);
									printf("\n");
								}
								if (number_of_players >= 5){
									printf("	Numbers of player 5: \n");
									printf("		#1 = %u \n", AAA[1]);
									printf("		#2 = %u \n", AAA[2]);
									printf("		#3 = %u \n", AAA[3]);
									printf("		#4 = %u \n", AAA[4]);
									printf("		#5 = %u \n", AAA[5]);
									printf("		#6 = %u \n", AAA[6]);
									printf("\n");
								}
								if (number_of_players >= 6){
									printf("	Numbers of player 6: \n");
									printf("		#1 = %u \n", BBB[1]);
									printf("		#2 = %u \n", BBB[2]);
									printf("		#3 = %u \n", BBB[3]);
									printf("		#4 = %u \n", BBB[4]);
									printf("		#5 = %u \n", BBB[5]);
									printf("		#6 = %u \n", BBB[6]);
									printf("\n");
								}
								if (number_of_players >= 7){
									printf("	Numbers of player 7: \n");
									printf("		#1 = %u \n", AAAA[1]);
									printf("		#2 = %u \n", AAAA[2]);
									printf("		#3 = %u \n", AAAA[3]);
									printf("		#4 = %u \n", AAAA[4]);
									printf("		#5 = %u \n", AAAA[5]);
									printf("		#6 = %u \n", AAAA[6]);
									printf("\n");
								}
								if (number_of_players >= 8){
									printf("	Numbers of player 8: \n");
									printf("		#1 = %u \n", BBBB[1]);
									printf("		#2 = %u \n", BBBB[2]);
									printf("		#3 = %u \n", BBBB[3]);
									printf("		#4 = %u \n", BBBB[4]);
									printf("		#5 = %u \n", BBBB[5]);
									printf("		#6 = %u \n", BBBB[6]);
									printf("\n");
								}
								if (number_of_players == 9){
									printf("	Numbers of player 9: \n");
									printf("		#1 = %u \n", AAAAA[1]);
									printf("		#2 = %u \n", AAAAA[2]);
									printf("		#3 = %u \n", AAAAA[3]);
									printf("		#4 = %u \n", AAAAA[4]);
									printf("		#5 = %u \n", AAAAA[5]);
									printf("		#6 = %u \n", AAAAA[6]);
									printf("\n");
								}
								
								if ((gamemode == 1)||(gamemode == 6)||(gamemode == 7)||(gamemode == 8)) {
									printf("	Matchballs player %u: 	%u \n", geben, A[0]);
									printf("	Matchballs player 2: 	%u \n", B[0]);
									if (gamemode == 6) {
										if (number_of_players >= 3){printf("	Matchballs player 3: 	%u \n", AA[0]);}
										if (number_of_players >= 4){printf("	Matchballs player 4: 	%u \n", BB[0]);}
										if (number_of_players >= 5){printf("	Matchballs player 5: 	%u \n", AAA[0]);}
										if (number_of_players >= 6){printf("	Matchballs player 6: 	%u \n", BBB[0]);}
										if (number_of_players >= 7){printf("	Matchballs player 7: 	%u \n", AAAA[0]);}
										if (number_of_players >= 8){printf("	Matchballs player 8: 	%u \n", BBBB[0]);}
										if (number_of_players >= 9){printf("	Matchballs player 9: 	%u \n", AAAAA[0]);}
									}
								} else if (gamemode == 2) {
									printf("	Squares collected by player %u: 	%u \n", geben, A[0]);
									printf("	Squares collected by player 2: 	%u \n", B[0]);
								} else if (gamemode == 3) {
									printf("	Times with squares <= 5, player %u: 	%u \n", geben, A[0]);
									printf("	Times with squares <= 5, player 2: 	%u \n", B[0]);
								} else if (gamemode == 4) {
									printf("	Points player %u: 		%u \n", geben, P[1]);
									printf("	Points Player 2: 		%u \n", P[2]);
									printf("	Turns with more points player %u: 	%u \n", geben, A[0]);
									printf("	Turns with more points player 2: 	%u \n", B[0]);
									printf("	Number of not decided #-squares: 	%u \n", P[0]);
								} else if (gamemode == 5) {
									printf("	Times with squares < 5, player %u: 	%u \n", geben, A[0]);
									printf("	Times with squares < 5, player 2: 	%u \n", B[0]);
								} else if (gamemode == 9) {
									printf("	Number of excluded abilites: 	%u \n", exclude_counter);
									printf("	Offensive abilities taken: 	%u \n", number_of_players-ability[0]);
									printf("	Defensive abilities taken: 	%u \n", ability[0]);
								} else if (gamemode == 10) {	//10
									for (unsigned int p=1; p<=number_of_players; p+=1) {
										if ((ges[p] < 1000)&&(ges[p] != 0)) {
											printf("		Spieler %u: %u life(s) left.\n", p, ulcer_lifes[p]);
										}
									}
								} else if (gamemode == 11) {	//mehr-gamemode
									for (unsigned int p=1; p<=number_of_players; p+=1) {
										if ((ges[p] > 1000)||(ges[p] == 0)) {
											printf("	Spieler %u: is out.\n", p);
										} else if (ges[p] < 1000) {
											printf("	Spieler %u: You own %u squares.\n", p, ges[p]);
										}
									}
								} else if (gamemode == 12) {
									for (unsigned int p=1; p<=number_of_players; p+=1) {
										if ((ges[p] > 1000)||(ges[p] == 0)) {
											printf("	Spieler %u: is out.\n", p);
										} else if (ges[p] < 1000) {
											printf("	Spieler %u: You own %u squares.\n", p, ges[p]);
										}
									}
								}
								if (ttt != 0) {
									printf("	Number of penalties given until now: %u \n", pere[0]);
								}
							}
							
							if (menuoperator == 3){
								if ((gamemode != 10)&&(gamemode != 12)) {
									printf("	Plus: Change a free square in the surrounding of yours in one of yours.\n");
								} else {
									printf("	Plus: Change a square in the surrounding of yours in one of yours.\n");
								}
								printf("	Minus: Delete one of your squares.\n");
								printf("	Move: The position of one of yours will change with a free, near-by square.\n");
								printf("	Revive: Your lost squares having no living squares of yours surrounding them at the beginning of your turn,\n		will be revived.\n");
								printf("	%u/%u-new: A free square has to be surrounded by %u or %u of yours during the development.\n", w+1, w+2, w+1, w+2);
								printf("	%u-new: A free square has to be surrounded by %u of yours during the development.\n", w-1, w-1);
								printf("	%u-max: A square of yours will survive even by %u of your squares surrounding it.\n", e+1, e+1);
								if (d == 0) {
									printf("	-1-min: A square of yours will survive even by only -1 of your squares surrounding it.\n");
								} else {
									printf("	%u-min: A square of yours will survive even by only %u of your squares surrounding it.\n", d-1, d-1);
								}
								
								if ((gamemode == 1)||(gamemode == 2)||(gamemode == 4)||(gamemode == 5)||(gamemode == 7)||(gamemode == 9)||(gamemode == 10)) {	//10
									printf("	Change: A square of yours and a near-by square of your enemy will change positions.\n");
									printf("	Destroy: Delete a near-by square of your enemy.\n");
									printf("	Boost: Use all near-by squares of your enemy as your own for the development.\n");
									
								} else if (gamemode == 3) {
									printf("	Change: A square of yours and a square of your enemy in the surrounding will change positions.\n");
									printf("	Destroy: Delete a surrounding square of your enemy.\n");
									printf("	Boost: Use all surrounding squares of your enemy as your own for the development.\n");
									
								} else if (gamemode == 8) {
									printf("	Change: A square of yours and a near-by #-square will change positions.\n");
									printf("	Destroy: Delete a square of your enemy, but not in the last two lines.\n");
									printf("	Boost: Use all near-by #-squares as your own for the development.\n");
									
								} else if (gamemode == 6) {
									if (geben == 1) {
										printf("	Change: The heart-block and a square of yours will change positions.\n");
										printf("	Destroy: Delete a square of your enemy.\n");
										printf("	Boost: Touching the heart_block no square of yours can die.\n");
									} else {
										printf("	Change: A square of yours and a near-by square of the hunted one will change positions.\n");
										printf("	Destroy: Delete a near-by square of your enemy.\n");
										printf("	Boost: Use all near-by squares of the hunted one as your own for the development.\n");
									}
									
								} else if (gamemode == 11) {
									printf("	Change: A square of yours and a near-by square of your enemy or the near-by ball will change positions.\n");
									printf("	Destroy: Delete a near-by square of your enemy.\n");
									printf("	Boost: Use all near-by squares of your enemy and the near-by ball as your own for the development.\n");
								} else if (gamemode == 12) {
									printf("	Change: A square of yours and a near-by square of your enemy or a near-by object will change positions.\n");
									printf("	Destroy: Delete a near-by square of your enemy or a near-by object.\n");
									printf("	Boost: Use all near-by squares of your enemy and near-by objects as your own for the development.\n");
								}
								
								printf("\n");
							}
							
							if (menuoperator == 4){
								if ((gamemode != 10)&&(gamemode != 12)) {
									printf("	Limit of development:	%u \n", limit_new);
									if (gamemode != 3) {
										printf("	Limit in total:		%u \n", limit_at_all);
										printf("	Limit in total with >2-new< taken: %u -0/-1/-2/-3/-4.\n", limit_at_all);
									}
								}
							}
							
							if (menuoperator == 5){
								Spielfeld hint;
								unsigned int b, a;
								hint = Spielfeld_Create (m, n);
								printf("	New: 1 \n	Dying: 2 \n	Both: 3 \n");
								scanf("%u", &menuoperator);
								
								for (unsigned int i=1; i<(m-1); i+=1){
									for (unsigned int j=1; j<(n-1); j+=1){
										if ((gamemode != 6)&&(gamemode != 9)&&(gamemode != 10)&&(gamemode != 11)&&(gamemode != 12)) {	//10
											if (Sf[i][j] == geben){
												hint[i][j] = geben;
											} else if (Sf[i][j] == (geben%2)+1){
												hint[i][j] = (geben%2)+1;
											} else if (Sf[i][j] == 7){
												hint[i][j] = 7;
											}
										} else if ((gamemode == 6)||(gamemode == 9)||(gamemode == 10)) {	//10
											if (Sf[i][j] == geben){
												hint[i][j] = geben;
											} else if (Sf[i][j] != 0){
												hint[i][j] = 17;
											}
										} else if (gamemode == 11) {
											if (Sf[i][j] == geben){
												hint[i][j] = geben;
											} else if (Sf[i][j] == 77){
												hint[i][j] = 77;
											} else if (Sf[i][j] != 0){
												hint[i][j] = 17;
											}
										} else if (gamemode == 12) {
											if (Sf[i][j] == geben){
												hint[i][j] = geben;
											} else if (Sf[i][j] == 81){
												hint[i][j] = 81;
											} else if (Sf[i][j] == 82){
												hint[i][j] = 82;
											} else if (Sf[i][j] == 83){
												hint[i][j] = 83;
											} else if (Sf[i][j] == 84){
												hint[i][j] = 84;
											} else if (Sf[i][j] == 75){
												hint[i][j] = 75;
											} else if (Sf[i][j] == 71){
												hint[i][j] = 71;
											} else if (Sf[i][j] != 0){
												hint[i][j] = 17;
											}
										}
									}
								}
								
								if ((menuoperator == 2)||(menuoperator == 3)){
									for (unsigned int i=1; i<(m-1); i+=1){
										for (unsigned int j=1; j<(n-1); j+=1){
											if (Sf[i][j] == geben){
												a = 0;
												for (unsigned int h=(i-1); h<=(i+1); h+=1){
													for (unsigned int k=(j-1); k<=(j+1); k+=1){
														if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
															if (Sf[h][k] == geben){
																a += 1;
															}
														}
													}
												}
												if ((a > e+1) || (a <= d)){
													hint[i][j] = 16;
												}
											}
										}
									}
								}
								
								if ((menuoperator == 1)||(menuoperator == 3)){
									for (unsigned int i=1; i<(m-1); i+=1){
										for (unsigned int j=1; j<(n-1); j+=1){
											if (Sf[i][j] == 0){
												b = 0;
												for (unsigned int h=(i-1); h<=(i+1); h+=1){
													for (unsigned int k=(j-1); k<=(j+1); k+=1){
														if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
															if (Sf[h][k] == geben){
																b += 1;
															}
														}
													}
												}
												if (b == w){
													hint[i][j] = 15;
												}
											}
										}
									}
								}
								
								if (opague >= 1) {
									Sf_opague = opague_builder (hint, m, n, geben, opague, aop);
								}
								
								if (opague >= 1) {
									show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
								} else {
									show_field (hint, m, n, gamemode, information_code, geben, Colored);
								}
								
								if (opague >= 1) {
									Sf_opague = opague_builder (Sf, m, n, geben, opague, aop);
								}
								menuoperator = 1;
								Spielfeld_Destroy (hint, m);
								
								//show_field (hint, m, n, gamemode, information_code, geben, Colored);		//teste die desrtoy-funktion für Spielfelder, done
							}
							
							if (menuoperator == 6){
								if (suprise == 0) {
									for (unsigned int i=1; i<m-1; i+=1){
										for (unsigned int j=1; j<n-1; j+=1){
											
											cons_field_1[i][j] = Sf[i][j];
											
											if (journey == 1){
												cons_journey_1[i][j] = Sf_journey[i][j];
											}
										}
									}
									sup_num = use_number;
								}
								
								while (menuoperator != 1) {
						
									printf("	Creator menu. 	Change number: 1	Suprise: 2	Suprise undo: 3	Back: 4 \n");
									scanf ("%u", &lim);
									if (lim == 1){
										printf("	number = ? \n");
										scanf ("%u", &use_number);
									} else if (lim == 2){
								
										printf("\n");
										scanf("%u", &suprise);
								
										if (suprise == 31){
											for (unsigned int i=2; i<m-2; i+=1){
												for (unsigned int j=1; j<n-1; j+=1){
													if (Sf[i][j] != 0){
														if (Sf[i][j] == geben){
															Sf[i][j] = geben%number_of_players+1;
														} else if (Sf[i][j] == geben%number_of_players+1){
															Sf[i][j] = geben;
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
													if (Sf[i][j] == geben%number_of_players+1){
														Sf[i][j] = 0;
													}
													if (i == (m-2)){
														Sf[m-2][j] = geben%number_of_players+1;
													}
												}
											}
										}
								
									} else if (lim == 3){
										for (unsigned int i=1; i<m-1; i+=1){
											for (unsigned int j=1; j<n-1; j+=1){
												Sf[i][j] = cons_field_1[i][j];
												if (journey == 1){
													Sf_journey[i][j] = cons_journey_1[i][j];
												}
											}
										}
										use_number = sup_num;
									} else if (lim == 4){
										menuoperator = 1;
									} else {
										printf("	Invalid comment");
									}
								}
							}
							
						}		// menuoperator = 7
						
						if (gamemode == 8) {		//##
							if (opague >= 1) {
								show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
							} else {
								show_field (Sf, m, n, gamemode, information_code, geben, Colored);
							}	//show_field über menuoperator = 7 und stack und so löschen, (verschiebe menuoperator!=0 - Schleife) ,done
							
							printf("\n");
						
						}
						
						if (ttt != 0) {
							time4 = time(NULL);
							time_saver += difftime(time4, time3);
						}
					}		//Menu-end.
					
					menuoperator = 0;
					
					if (var_[geben] == 10) {
						menuoperator = 1;
						var_[geben] = 5;		//## to avoid the mistake-note by closing the menu
					}
					
					if ((tac != 0)&&(var_[geben] <= 62)&&(var_[geben] > 10)){
						unsigned int tac_controll;
						tac_controll = 0;
						if (((var_[geben]%10) > 2)||((var_[geben]%10) == 0)){
							var_[geben] = 7;
							menuoperator = 1;
						} else {
							for (unsigned int z=var_[geben]; z>2; z-=10){
								tac_controll += 1;
							}
							if (tac_controll == 6){
								tac_controll = 0;
							}
							if (C[tac_controll] == 0){
								var_[geben] = 7;
								menuoperator = 1;
							} else {
								C[tac_controll] -= 1;		//Die tac-Abrechnung
							}
						}
					} else if ((tac != 0)&&(var_[geben] != 100)&&(var_[geben] != 1010)&&(var_[geben] != 0)&&(var_[geben] != 5)) {
						var_[geben] = 7;
					}		
					//tac-mode
					
					if (opt == 5){
						controll_1 = 10+use_number;
						controll_2 = 11+use_number;
					
						for (unsigned int i=0; i<use_number-1; i+=1){
							controll_1 += 9;
							controll_2 += 9;
						}
					
						if (var_[geben] == 0){
							controll_1 = 0;
							controll_2 = 0;
						}
						if (var_[geben] == 100){
							controll_1 = 100;
							controll_2 = 100;
						}
						if (var_[geben] == 1010){
							controll_1 = 1010;
							controll_2 = 1010;
						}
					}
					
					if (((var_[geben] > 0)&&(var_[geben] < 10))||(((opt == 5)&&(var_[geben] != controll_1))&&((opt == 5)&&(var_[geben] != controll_2)))){
						
						if (var_[geben] != 5) {		//#-start
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
					
				} 		// menuoperator = 0 

				suprise = 0;
				
				if (var_[geben] == 0){
					printf("	Do you really want to end the game ? \n");
					printf("	Yes: 0		No: 1 \n");
					scanf("%u", &lim);
					if (lim == 0){
						break;
					} else if (lim == 1){
						lim = 0;
						continue;
					} else {
						printf("	0 or 1, it is so difficult to understand? \n");
						printf("	Well, it seems I have to end it by myself... \n");
						break;
					}
				} else {
					
					//printf("	Checkpoint: var_[1] accepted \n");	//test
					
					if (var_[geben] == 100){		//1, 2, 3,... durch "geben" ersetzen, go on
						
						var_[0] = 1;
						
						if (gamemode == 11) {
							for (unsigned int p=2; p<=5; p+=1) {
								
								dynamic_pointer[p] = dynamic_pointer_save[number_of_players][p-2];	//if geben == 1, else geben-1
								
							}
						}
						
						cons[geben] = use_number;
						
						for (unsigned int i=1; i<m-1; i+=1){
							for (unsigned int j=1; j<n-1; j+=1){
								
								if (number_of_players == 1) {
									Sf[i][j] = cons_field_1[i][j];
									
									if (journey == 1){
										Sf_journey[i][j] = cons_journey_1[i][j];
									}
								} else if (number_of_players == 2) {
									Sf[i][j] = cons_field_2[i][j];
									
									if (journey == 1){
										Sf_journey[i][j] = cons_journey_2[i][j];
									}
								} else if (number_of_players == 3) {
									Sf[i][j] = cons_field_3[i][j];
									
									if (journey == 1){
										Sf_journey[i][j] = cons_journey_3[i][j];
									}
								} else if (number_of_players == 4) {
									Sf[i][j] = cons_field_4[i][j];
									
									if (journey == 1){
										Sf_journey[i][j] = cons_journey_4[i][j];
									}
								} else if (number_of_players == 5) {
									Sf[i][j] = cons_field_5[i][j];
									
									if (journey == 1){
										Sf_journey[i][j] = cons_journey_5[i][j];
									}
								} else if (number_of_players == 6) {
									Sf[i][j] = cons_field_6[i][j];
									
									if (journey == 1){
										Sf_journey[i][j] = cons_journey_6[i][j];
									}
								} else if (number_of_players == 7) {
									Sf[i][j] = cons_field_7[i][j];
									
									if (journey == 1){
										Sf_journey[i][j] = cons_journey_7[i][j];
									}
								} else if (number_of_players == 8) {
									Sf[i][j] = cons_field_8[i][j];
									
									if (journey == 1){
										Sf_journey[i][j] = cons_journey_8[i][j];
									}
								} else if (number_of_players == 9) {
									Sf[i][j] = cons_field_9[i][j];
									
									if (journey == 1){
										Sf_journey[i][j] = cons_journey_9[i][j];
									}
								}
							}
						}
						
						if (opague >= 1) {
							Sf_opague = opague_builder (Sf, m, n, geben, opague, aop);
						}
						
						if (opague >= 1) {
							show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
						} else {
							show_field (Sf, m, n, gamemode, information_code, geben, Colored);
						}
						
						g-=1;
						var_[geben] = 1010;
						if (gamemode == 10) {
							ulcer_lifes[geben] += 1;
							ulcer_start[geben] = 0;
						}
						continue;
					} else {
						
						if (var_[geben%number_of_players+1] != 1010){
							
							for (unsigned int i=1; i<m-1; i+=1){
								for (unsigned int j=1; j<n-1; j+=1){
									cons_field_1[i][j] = Sf[i][j];
									if (journey == 1){
										cons_journey_1[i][j] = Sf_journey[i][j];
									}
								}
							}
							
						}
						
						var_[0] = 0;
						
						if (var_[geben] < 50){
		
							if (var_[geben] == 11){A[1] += 1; Plus (m, n, geben, Sf, limit_at_all, gamemode, information_code, number_of_players, Colored, opague, Sf_opague);}
							if (var_[geben] == 12){A[1] += 1; Minus (m, n, geben, Sf, gamemode, information_code, Colored, opague, Sf_opague);}
							if (var_[geben] == 21){A[2] += 1; Move (m, n, geben, Sf, gamemode, information_code, Colored, opague, Sf_opague);}
							if (var_[geben] == 41){A[4] += 1; Move (m, n, geben, Sf, gamemode, information_code, Colored, opague, Sf_opague);}
							if (var_[geben] == 22){A[2] += 1; Change (m, n, geben, Sf, gamemode, information_code, Colored, opague, Sf_opague, position);}
							if (var_[geben] == 31){A[3] += 1; Destroy (m, n, geben, Sf, gamemode, information_code, Colored, opague, Sf_opague);}
							if (var_[geben] == 42){
								A[4] += 1;
								if (gamemode != 6) {
									Boost (geben, Sf, m, n, temp, gamemode);
								} else if (gamemode == 6) {
									boost_hunt_activator = 1;
								}
							}
						} else {
							if (var_[geben] == 51){A[5] += 1; w += 1;}		//w
							if (var_[geben] == 52){A[5] += 1; w -= 1;}		//w
							if (var_[geben] == 61){A[6] += 1; e += 1;}		//e
							if (var_[geben] == 62){A[6] += 1; if (d != 0) {d -= 1;} else {d = 10;}}		//d
						}
						
						if (ttt != 0) {
							time2 = time(NULL);		//wirklich die eingabe abwarten, done
							time_warning = ((difftime(time2, time1)) - time_saver);
							
							//printf("	time_warning: %f \n", time_warning);		//test
							
							if ((pere[geben] != 0)&&((pere[geben] + warning_system) <= 6)) {
								if (pere[geben] == 1) {
									if (warning_system <= 2) {
										time_warning += 1.0;
									} else if (warning_system == 3) {
										time_warning += 2.0;
									} else if (warning_system == 4) {
										time_warning += 3.0;
									} else if (warning_system == 5) {
										time_warning += 5.0;
									}
								} else if (pere[geben] == 2) {
									if (warning_system == 1) {
										time_warning += 2.0;
									} else if (warning_system == 2) {
										time_warning += 3.0;
									} else if (warning_system == 3) {
										time_warning += 5.0;
									} else if (warning_system == 4) {
										time_warning += 6.0;
									}
								} else if (pere[geben] == 3) {
									if (warning_system == 1) {
										time_warning += 3.0;
									} else if (warning_system == 2) {
										time_warning += 5.0;
									} else if (warning_system == 3) {
										time_warning += 8.0;
									}
								} else if (pere[geben] == 4) {
									if (warning_system == 1) {
										time_warning += 4.0;
									} else if (warning_system == 2) {
										time_warning += 7.0;
									}
								} else if (pere[geben] == 5) {
									if (warning_system == 1) {
										time_warning += 5.0;
									}
								}
							}
							
							if ((gamemode == 6)&&(geben == 1)) {	//keep it
								if (time_warning > 10.0) {	//hunted one bonus
									time_warning -= 10.0;
								} else {
									time_warning = 0.0;
								}
							}
							if (time_warning > (1.0*ttt)) {
								pere[0] += 1;
								printf("	You took too much time! %f sec more than you should. \n", (time_warning-1.0*ttt) );
								printf(" \n");
								for (unsigned int p=16; p>=1; p-=3) {	//index_verschiebung
									if ((time_warning-1.0*ttt) > 1.0*(p-1)) {
										pere[geben] = (((p-1)/3) + 1);
										break;
									}
								}
							} else {
								pere[geben] = 0;
							}
							//printf("	pere[%u]: %u \n", geben, pere[geben] );	//test
						}
						
						Sf_nl_1 = new_life_1 (Sf, m, n, w, gamemode, information_code);
						
						//show_field (Sf_nl_1, m, n, gamemode, information_code, geben);	// test
						
						if (gamemode == 6) {
							
							precounter = 0;
							for (unsigned int i=1; i<m-1; i+=1){
								for (unsigned int j=1; j<n-1; j+=1){
									if (Sf[i][j] == 11){
										if (Sf_nl_1[i][j-1] > 1) {
											printf (" Sieg: Spieler %u \n", Sf_nl_1[i][j-1]);
											precounter += 1;
										}
										if (Sf_nl_1[i][j+1] > 1) {
											if (precounter == 0) {
												printf (" Sieg: Spieler %u \n", Sf_nl_1[i][j+1]);
											}
											precounter += 1;
										}
										if (Sf_nl_1[i-1][j] > 1) {
											if (precounter == 0) {
												printf (" Sieg: Spieler %u \n", Sf_nl_1[i-1][j]);
											}
											precounter += 1;
										}
										if (Sf_nl_1[i+1][j] > 1) {
											if (precounter == 0) {
												printf (" Sieg: Spieler %u \n", Sf_nl_1[i+1][j]);
											}
											precounter += 1;
										}
										if (precounter == 2) {
											printf(" Double-catch! \n");
										}
										if (precounter == 3) {
											printf(" TRIPLE-catch!! \n");
										}
										if (precounter == 4) {
											printf(" QUADRO-CATCH!!! \n");
										}
										break;
									}
								}
								if (precounter > 0) {
									break;
								}
							}
							if (precounter > 0) {
								for (unsigned int i=1; i<m-1; i+=1){
									for (unsigned int j=1; j<n-1; j+=1){
										if (Sf_nl_1[i][j] == geben) {
											Sf[i][j] = geben;
										}
									}
								}
								show_field (Sf, m, n, gamemode, information_code, geben, Colored);
								break;
							}
						}
				
						controll = 0;
						if (gamemode == 7) {
							for (unsigned int i=1; i<=(m-1)/2; i+=1){		//Spiel-Ende?
								if ((Sf_nl_1[i][n-2] == geben)||(Sf[i][n-2] == geben)){
									for (unsigned int k=1; k<m-1; k+=1){
										if (Sf_nl_1[k][n-2] == geben){
											Sf[k][n-2] = geben;
										}
									}
									show_field (Sf, m, n, gamemode, information_code, geben, Colored);
									printf("	Sieg:	Spieler %u \n", geben);
									controll = 1;
								}
							}
							if (controll == 1){
								break;
							}
						}
						controll = 0;
						
						num_1 = 0;
						for (unsigned int i=1; i<m-1; i+=1){
							for (unsigned int j=1; j<n-1; j+=1){
								if (Sf_nl_1[i][j] == geben){
									num_1 += 1;
								}
							}
						}
						

						if (gamemode != 6) {	//wegen hunted one, if (geben != 1)

							if (var_[geben] == 42){
								for (unsigned int i=1; i<m-1; i+=1){
									for (unsigned int j=1; j<n-1; j+=1){
										if (gamemode == 8) {
											if (temp[i][j] == geben){
												Sf[i][j] = 0;
											}
										} else if ((gamemode == 9)||(gamemode == 10)||(gamemode == 11)||(gamemode == 12)) {	//mehr-gamemode
											if (temp[i][j] != 0){
												Sf[i][j] = temp[i][j];
											}
										} else if ((gamemode != 8)&&(gamemode != 9)&&(gamemode != 10)&&(gamemode != 11)&&(gamemode != 12)) {	//10
											if (temp[i][j] == 1){
												Sf[i][j] = 2;
											}
										}
									}
								}
							}
						}
						
						controll = 0;
						if (gamemode == 1){
							
							for (unsigned int letzte=1; letzte<n-1; letzte+=1){		//Spiel-Ende? If, because different 

								if (Sf[m-2][letzte] == geben){
									printf("	Sieg:	Spieler %u \n", geben);
									show_field (Sf, m, n, gamemode, information_code, geben, Colored);
									controll = 1;
									break;
								}
							}
							if (controll == 1){
								break;
							}
						}
						controll = 0;
						
						Spielfeld_Destroy (temp, m);
					
						Sf_od_1 = old_dying_1 (Sf, m, n, d, e, gamemode, information_code);	// , geben)
						
						if ((boost_hunt_activator == 1)&&(gamemode == 6)) {	//&&geben == 1
							for (unsigned int i=1; i<m-1; i+=1){
								for (unsigned int j=1; j<n-1; j+=1){
									if (Sf[i][j] == 11){
										Sf_od_1[i-1][j] = 0;
										Sf_od_1[i][j-1] = 0;
										Sf_od_1[i+1][j] = 0;
										Sf_od_1[i][j+1] = 0;
										
										boost_hunt_activator = 0;
										break;
									}
								}
								if (boost_hunt_activator == 0) {
									break;
								}
							}
						}
						
						if (journey == 1){
							unsigned int journey_max;
							journey_max = 0;
							for (unsigned int i=1; i<m-1; i+=1){
								for (unsigned int j=1; j<n-1; j+=1){
									if (Sf_journey[i][j] == geben){
										journey_max += 1;
									}
								}
							}
							for (unsigned int i=1; i<m-1; i+=1){
								for (unsigned int j=1; j<n-1; j+=1){
									if ((Sf_od_1[i][j] == 101*geben) && (Sf_journey[i][j] == 0) && (journey_max >= limit_at_all)){
										for (unsigned int u=0; u<(m-1); u+=1){
											for (unsigned int o=1; o<(n-1); o+=1){
												if ((Sf_journey[u][o] == geben)&&((u+o)%2 == 0)){
													Sf_journey[u][o] = 0;
													journey_max -= 1;
													if (journey_max < limit_at_all){
														break;
													}
												}
											}
											if (journey_max < limit_at_all){
												break;
											}
										}
										
									}
									if ((Sf_od_1[i][j] == 101*geben) && (Sf_journey[i][j] == 0) && (journey_max < limit_at_all)){
										Sf_journey[i][j] = geben;
										journey_max += 1;
									}
								}
							}
							journey_max = 0;
							
						}
					  
						if (var_[geben] == 32){A[3] += 1; Revive_1(m, n, Sf_od_1, Sf);}	//, geben)
						
						num_2 = 0;
						for (unsigned int i=1; i<m-1; i+=1){
							for (unsigned int j=1; j<n-1; j+=1){
								if (Sf_od_1[i][j] == 101*geben){
									num_2 += 1;
								}
							}
						}
					
						count_new = 0;
						
						for (unsigned int i=1; i<m-1; i+=1){
							for (unsigned int j=1; j<n-1; j+=1){
								if (Sf_nl_1[i][j] == geben){
									count_new += 1;
								}
							}
						}
						
						ent = limit_new;
						
						for (unsigned int i=1; i<m-1; i+=1){
							for (unsigned int j=1; j<n-1; j+=1){
								if ((Sf[i][j] == geben) && (Sf_od_1[i][j] == 0)){
									zeitgewinner += 1;
								}
							}
						}
						
						//printf("	ent: %u \n ", ent);
						if ((gamemode == 6)&&(count_new > (limit_new + (number_of_players-3)))) {		//geben = 1 erforderlich
							Sf_nl_1 = Index_1_hunt (ent, count_new, m, n, Sf_nl_1, Sf_od_1, limit_new, limit_at_all, zeitgewinner, Sf, number_of_players);
							
						} else if (count_new > limit_new){		//Abfrage auf max. 10 neue Steine, normalerweise
							if (gamemode == 1) {
								Sf_nl_1 = Index_1 (ent, count_new, m, n, Sf, Sf_nl_1, Sf_od_1, limit_new, limit_at_all, zeitgewinner);	//, geben)
							} else if (gamemode == 2) {
								Sf_nl_1 = Index_1_col (ent, count_new, m, n, Sf, Sf_nl_1, Sf_od_1, limit_new, limit_at_all, zeitgewinner);	
							} else if (gamemode == 3) {
								Sf_nl_1 = Index_1_con (ent, count_new, m, n, Sf, Sf_nl_1, limit_new);
							} else if (gamemode == 4) {
								Sf_nl_1 = Index_1_fal (ent, count_new, m, n, Sf, Sf_nl_1, Sf_od_1, limit_new, limit_at_all, zeitgewinner);	
							} else if (gamemode == 5) {
								Sf_nl_1 = Index_1_fig (ent, count_new, m, n, Sf, Sf_nl_1, Sf_od_1, limit_new, limit_at_all, zeitgewinner);	
							} else if (gamemode == 7) {
								Sf_nl_1 = Index_1_race (ent, count_new, m, n, Sf, Sf_nl_1, Sf_od_1, limit_new, limit_at_all, zeitgewinner);	
							} else if (gamemode == 8) {
								Sf_nl_1 = Index_1_rain (ent, count_new, m, n, Sf, Sf_nl_1, Sf_od_1, limit_new, limit_at_all, rain, zeitgewinner);	
							} else if (gamemode == 9) {
								Sf_nl_1 = Index_are (ent, count_new, m, n, Sf_nl_1, Sf_od_1, limit_new, limit_at_all, zeitgewinner, Sf, w, d, e, geben);
							} else if (gamemode == 10) {	//10
								count_new = 0;
							} else if (gamemode == 11) {
								Sf_nl_1 = Index_dyn (ent, count_new, m, n, Sf_nl_1, Sf_od_1, limit_new, limit_at_all, zeitgewinner, Sf, w, d, e, geben, position);	//Index_dyn done
							} else if (gamemode == 12) {
								count_new = 0;
							}
						
						}
						ent = 0;
						count_new = 0;
					
						num_3 = 0;
						for (unsigned int i=1; i<m-1; i+=1){
							for (unsigned int j=1; j<n-1; j+=1){
								if (((Sf[i][j] == geben) && (Sf_od_1[i][j] == 0)) || (Sf_nl_1[i][j] == geben)){
									count_new += 1;
									num_3 += 1;
								}
							}
						}
						
						if (gamemode == 6) {	//count the heart, if geben == 1
							count_new += 1;
							num_3 += 1;
						}
						
						ent = limit_at_all;
						
						if ((gamemode == 1)||(gamemode == 2)||(gamemode == 4)||(gamemode == 5)||(gamemode == 7)||(gamemode == 8)) {
							
							if (var_[geben] == 52){
								lim = 0;
								for (unsigned int i=1; i<m-1; i+=1){
									for (unsigned int j=1; j<n-1; j+=1){
										if ((Sf[i][j] == geben) && (Sf_od_1[i][j] == 0)){
											lim += 1;
										}
									}
								}
								ent = lim;
								lim = 0;
								for (unsigned int i=1; i<m-1; i+=1){
									for (unsigned int j=1; j<n-1; j+=1){
										if (Sf[i][j] == geben%number_of_players+1){
											lim += 1;
										}
									}
								}
								if ((lim <= limit_new) && (ent < (limit_at_all - 1))){
									if (ent >= (limit_at_all - 3)){
										ent = limit_at_all - 1;
									} else if (ent >= (limit_at_all - 5)){
										ent = limit_at_all - 2;
									} else if (ent >= (limit_at_all - 7)){
										ent = limit_at_all - 3;
									} else if (ent >= (limit_at_all - 10)){
										ent = limit_at_all - 4;
									} else {
										ent = limit_at_all;
									}
								} else {
									ent = limit_at_all;
								}
								lim = 0;
							}
						}
						if ((gamemode == 6)&&(count_new > (limit_at_all + (2*(number_of_players-3))))) {
							Sf_nl_1 = Index_1_hunt (ent, count_new, m, n, Sf_nl_1, Sf_od_1, limit_new, limit_at_all, zeitgewinner, Sf, number_of_players);
							
						} else if (count_new > ent){		//Abfrage auf insgesamt max. 20 Steine, normalerweise
							if (gamemode == 1) {
								Sf_nl_1 = Index_1 (ent, count_new, m, n, Sf, Sf_nl_1, Sf_od_1, limit_new, limit_at_all, zeitgewinner);	
							} else if (gamemode == 2) {
								Sf_nl_1 = Index_1_col (ent, count_new, m, n, Sf, Sf_nl_1, Sf_od_1, limit_new, limit_at_all, zeitgewinner);	// ,geben)
							} else if (gamemode == 3) {
								count_new = 0;
							} else if (gamemode == 4) {
								Sf_nl_1 = Index_1_fal (ent, count_new, m, n, Sf, Sf_nl_1, Sf_od_1, limit_new, limit_at_all, zeitgewinner);	
							} else if (gamemode == 5) {
								Sf_nl_1 = Index_1_fig (ent, count_new, m, n, Sf, Sf_nl_1, Sf_od_1, limit_new, limit_at_all, zeitgewinner);	
							} else if (gamemode == 7) {
								Sf_nl_1 = Index_1_race (ent, count_new, m, n, Sf, Sf_nl_1, Sf_od_1, limit_new, limit_at_all, zeitgewinner);	
							} else if (gamemode == 8) {
								Sf_nl_1 = Index_1_rain (ent, count_new, m, n, Sf, Sf_nl_1, Sf_od_1, limit_new, limit_at_all, rain, zeitgewinner);	
							} else if (gamemode == 9) {
								Sf_nl_1 = Index_are (ent, count_new, m, n, Sf_nl_1, Sf_od_1, limit_new, limit_at_all, zeitgewinner, Sf, w, d, e, geben);
							} else if (gamemode == 10) {	//10
								count_new = 0;
							} else if (gamemode == 11) {
								Sf_nl_1 = Index_dyn (ent, count_new, m, n, Sf_nl_1, Sf_od_1, limit_new, limit_at_all, zeitgewinner, Sf, w, d, e, geben, position);
							} else if (gamemode == 12) {
								count_new = 0;
							}
						
						}
						
						zeitgewinner = 0;
						ent = 0;
						
						if (gamemode == 4) {
							touch (Sf, m, n, geben, Sf_nl_1, Sf_nl_2);
						}
						
						Sf = change_1 (Sf, Sf_nl_1, Sf_od_1, m, n, gamemode, number_of_players, ges); 	//Change befreit, ,geben)
						
						/*
						get_sequence (Spielfeld Sf, Spielfeld Sf_nl_, Spielfeld Sf_od_, unsigned int m, unsigned int n, unsigned int w, unsigned int d, unsigned int e, unsigned int gamemode, unsigned int* information_code, unsigned int number_of_players, unsigned int ges, unsigned int opague, Spielfeld Sf_opague, Spielfeld sequence, unsigned int seq_max, unsigned int nosv);
						
						if (sequence[0][0] > 0) {
							
							sequence[0][0] = 100;
							
							if (opague >= 1) {
								show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
							} else {
								show_field (Sf, m, n, gamemode, information_code, geben, Colored);
							}
							
							while (sequence[0][0] == 100) {
								printf("\n");
								printf("	How long should be your sequence from now on? \n");
								for (unsigned int p=0; p<seq_max; p+=1) {
									printf("	Length of [%u]: 	%u left \n", p, sequence[geben][p]);
								}
								printf("\n");
								scanf("%u", &sequence[0][0]);
								if ((sequence[0][0] >= seq_max)||(sequence[geben][sequence[0][0]] == 0)) {
									sequence[0][0] = 100;
									printf("	You made a mistake. \n");
								} else {
									sequence[geben][sequence[0][0]] -= 1;
									
									for (unsigned int p=1; p<=sequence[0][0]; p+=1) {		//Index?
										
										Sf_nl_1 = new_life_1 (Sf, m, n, w, gamemode, information_code);		//let Index go over it, even without reason? What will Index do? Nothing, i guess...
										Sf_od_1 = old_dying_1 (Sf, m, n, d, e, gamemode, information_code);
										Sf = change_1 (Sf, Sf_nl_1, Sf_od_1, m, n, gamemode, number_of_players, ges); 	//Change befreit
										
										if (p == sequence[0][0]) {
											if (opague >= 1) {
												show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
											} else {
												show_field (Sf, m, n, gamemode, information_code, geben, Colored);
											}
										}
									}
								}
							}
							
							sequence[0][1] = 0;
							for (unsigned int p=0; p<seq_max; p+=1) {
								sequence[0][1] += sequence[geben][p];
							}
							if (sequence[0][1] == 0) {
								for (unsigned int p=seq_max; p>0; p-=1) {
									sequence[geben][seq_max-p] = same[nosv-p+1];	//put nosv-Wert +10
								}
							}
							sequence[0][1] = 0;
							
							
							//seq_max, sequence[10][10], go on
						
						}*/
						
						if (gamemode == 6) {	//if geben == 1
							if (opague >= 1) {
								show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
							} else {
								show_field (Sf, m, n, gamemode, information_code, geben, Colored);
							}
							printf("\n");
							printf("\n");
							choose_heart (Sf, m, n);
							printf("\n");
						}
						
						if (gamemode == 1) {	//if, because different
							for (unsigned int j=1; j<n-1; j+=1){
								if (Sf[m-3][j] == geben){
									A[0] += 1;
									break;
								}
							}
						} else if (gamemode == 2) {
							for (unsigned int j=2; j<n-1; j+=((n-1)/2)-2){		//collect-Bed. prüfen
								unsigned int a;
								a = 0;
								if (Sf[((m-1)/2)][j] == 7){
									if (Sf[((m-1)/2)-1][j]==geben){a += 1;}
									if (Sf[((m-1)/2)+1][j]==geben){a += 1;}
									if (Sf[(m-1)/2][j-1]==geben){a += 1;}
									if (Sf[(m-1)/2][j+1]==geben){a += 1;}
									if (a >= 3){
										A[0] += 1;
										Sf[((m-1)/2)][j] = geben;
									}
								}
							}
							if (A[0] == 2){
								printf("\n");
								printf("	Sieg: Spieler %u \n", geben);
								printf("\n");
								show_field (Sf, m, n, gamemode, information_code, geben, Colored);
								break;
							}
						}
						
						if (gamemode == 6) {	//if geben==1
							for (unsigned int p=0; p<=3; p+=1) {
								information_code[p] = 0;
							}
							/* test
							printf("\n");
							printf("	hboa=%u	\n", hboa);
							printf("\n");
							*/
							if (opague >= 1) {
								show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
							} else {
								show_field (Sf, m, n, gamemode, information_code, geben, Colored);
							}
						
						}
						
						if ((gamemode == 6)&&(geben == number_of_players)) {
							lim = 1;
							printf("	\n");
							if (opague >= 1) {
								show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
							} else {
								show_field (Sf, m, n, gamemode, information_code, geben, Colored);
							}
							printf("	\n");
							while (lim == 1) {
								printf("	\n");
								printf("	\n");
								printf("	Are you ready to make your turn? \n");
								printf("	Yes: 1 \n");
								printf("	\n");
								printf("	\n");
								scanf("%u", &lim);
								
								if (lim != 1) {
									lim = 1;
								} else {
									lim = 0;
								}
							}
						}
						if (gamemode == 6) {
							information_code[3] = 0;
						}
						
						if (gamemode == 6) {
							for (unsigned int s = 1; s <= 20; s+=1) {	//Abstandhalter
								printf(" \n");
							}
						}
						
						controll = 0;
						if (gamemode == 1) {
							for (unsigned int letzte=1; letzte<n-1; letzte+=1){		//Spiel-Ende?	if, because different
								if (Sf[m-2][letzte] == 1){
									printf("	Sieg:	Spieler %u \n", geben);
									controll = 1;
									break;
								}
							}
							if (controll == 1){
								break;
							}
						}
						controll = 0;
						
						if (gamemode == 3) {
							if (opague >= 1) {
								show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
							} else {
								show_field (Sf, m, n, gamemode, information_code, geben, Colored);
							}
							battle (m, n, Sf, geben);
						}
						
						if (var_[geben%number_of_players+1] != 1010) {
							cons[geben] = use_number;
							
							if (gamemode == 11) {
								for (unsigned int p=2; p<=5; p+=1) {
									
									dynamic_pointer_save[geben][p-2] = dynamic_pointer[p];
									
								}
							}
							
						}
						
						use_number = random_number (num_1, num_2, num_3, use_number, g, var_, number_3, number_4);
						
						if ((opt != 5)&&(var_[geben] <= 62)){
							controll_1 = 0;
							for (unsigned int z=var_[geben]; z>2; z-=10){
								controll_1 += 1;
							}
							number_1 = controll_1;
							controll_1 = 0;
						}
					}
				}
			
			} else if (geben == 2) {		//2.Spieler
				
				if (opague >= 1) {
					Sf_opague = opague_builder (Sf, m, n, geben, opague, aop);
					
				}
				
				if ((ttt != 0)&&(pere[geben] == 100)) {
					g += 1;
					continue;
				}
				
				if ((gamemode == 10)&&(ulcer_start[2] == 0)) {
					if (opague >= 1) {
						show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
					} else {
						show_field (Sf, m, n, gamemode, information_code, geben, Colored);
					}
					g += 1;
					continue;
				}
				
				if ((ges[2] == 2020)&&((gamemode == 6)||(gamemode == 9)||(gamemode == 10)||(gamemode == 11)||(gamemode == 12))) {	//mehr-gamemode
					g += 1;
					var_[2] = 2020;
					cons[2] = cons[1];
					for (unsigned int i=1; i<m-1; i+=1){
						for (unsigned int j=1; j<n-1; j+=1){
							cons_field_2[i][j] = cons_field_1[i][j];
							
							if (journey == 1){
								cons_journey_2[i][j] = cons_journey_1[i][j];
								
								if (Sf_journey[i][j] == 2) {
									Sf_journey[i][j] = 0;
								}
							}
							if (gamemode == 11) {	//mehr-gamemode
								for (unsigned int p=2; p<=5; p+=1) {
									
									dynamic_pointer_save[2][p-2] = dynamic_pointer_save[1][p-2];
									
								}
							}
							
						}
					}
					if (var_[0] == 1) {
						g-=2;
					}
					continue;
				}
				
				w = 3;
				d = 2;
				e = 3;
				if (gamemode == 9) {
					if (ability[1] == geben) {
						w = 1;
						d = 0;
						e = 1;
						information_code[0] = 1;
					} else if (ability[2] == geben) {
						w = 2;
						d = 1;
						e = 2;
						information_code[0] = 2;
					} else if (ability[3] == geben) {
						w = 4;
						d = 1;
						e = 4;	//abweichende e-definition
						information_code[0] = 3;
					} else if (ability[4] == geben) {
						information_code[0] = 4;
					} else if (ability[5] == geben) {
						information_code[0] = 5;
					} else if (ability[6] == geben) {
						information_code[0] = 6;
					} else if (ability[7] == geben) {
						information_code[0] = 7;
					} else if (ability[8] == geben) {
						information_code[0] = 8;
					} else if (ability[9] == geben) {
						information_code[0] = 9;
						
						if (opague >= 1) {
							show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
						} else {
							show_field (Sf, m, n, gamemode, information_code, geben, Colored);
						}
						
						for (unsigned int i=1; i<m-1; i+=1){
							for (unsigned int j=1; j<n-1; j+=1){
								if (Sf[i][j] == geben) {
									if ((Sf[i+1][j] != 0)&&(Sf[i+1][j] != geben)&&((i+2) <= (m-2))) {
										if (Sf[i+2][j] == 0) {
											Sf[i+2][j] = Sf[i+1][j];
											Sf[i+1][j] = 0;
										}
									}
									if ((Sf[i-1][j] != 0)&&(Sf[i-1][j] != geben)&&((i-2) >= 1)) {
										if (Sf[i-2][j] == 0) {
											Sf[i-2][j] = Sf[i-1][j];
											Sf[i-1][j] = 0;
										}
									}
									if ((Sf[i][j-1] != 0)&&(Sf[i][j-1] != geben)&&((j-2) >= 1)) {
										if (Sf[i][j-2] == 0) {
											Sf[i][j-2] = Sf[i][j-1];
											Sf[i][j-1] = 0;
										}
									}
									if ((Sf[i][j+1] != 0)&&(Sf[i][j+1] != geben)&&((j+2) <= (n-2))) {
										if (Sf[i][j+2] == 0) {
											Sf[i][j+2] = Sf[i][j+1];
											Sf[i][j+1] = 0;
										}
									}
								}
							}
						}
					}
				}
				
				if (gamemode == 10) {
					w = 2;
					d = 1;
					e = 2;
				}
				
				if (gamemode == 9) {
					if (information_code[0] == 1) {
						limit_at_all = limit_at_all_saver-2;
					} else if (information_code[0] == 2) {
						limit_at_all = limit_at_all_saver-1;
					} else {
						limit_at_all = limit_at_all_saver;
					}
				}
				
				if (ttt != 0) {
					if ((pere[geben] != 0)&&(warning_system <= 5)&&((pere[geben]+warning_system) == 7)) {
						g += 1;
						printf(" \n ");
						printf("	You got a penalty. \n ");
						printf(" \n ");
						pere[geben] = 0;
						continue;
					} else if ((pere[geben] != 0)&&(warning_system != 0)&&(((warning_system <= 5)&&((pere[geben]+warning_system) == 8))||((warning_system == 6)&&(pere[geben] == 1)))) {
						Sf_od_2 = old_dying_2 (Sf, m, n, d, e, gamemode, information_code);
						Sf = change_2 (Sf, Sf_nl_2, Sf_od_2, m, n, gamemode, number_of_players, ges); 	//Change befreit
						g += 1;
						printf(" \n ");
						printf("	You got a penalty. \n ");
						printf(" \n ");
						pere[geben] = 0;
						continue;
					} else if (((warning_system <= 5)&&((warning_system + pere[geben]) >= 9))||((warning_system >= 6)&&((warning_system + pere[geben]) >= 8))) {
						printf("	Niederlage: Spieler 2 \n ");
						for (unsigned int i=1; i<m-1; i+=1){
							for (unsigned int j=1; j<n-1; j+=1){
								if (Sf[i][j] == 2) {
									Sf[i][j] = 0;
								}
							}
						}
						ges[2] = 2020;
						player_counter += 1;
						pere[geben] = 100;
						g += 1;
						continue;
					}
				}
				
				if (var_[geben] == 1010) {
					use_number = cons[geben];
					if (opt == 5) {
					
						printf("	Player %u ,do you want to keep your number (%u) or do you want to get the next one? \n", geben, cons[geben]);
						printf("	Keep the number: 	1 \n");
						printf("	Get the next one:	2 \n");
						scanf("%u", &lim);
						
						if (lim == 2) {
							use_number = random_number (num_1, num_2, num_3, use_number, g, var_, number_3, number_4);
						} else if (lim != 1) {
							printf("	Well, you keep your number, but next time please take an option i offered. \n\n");
						}
						lim = 0;
					
					}
				}
				
				if (var_[geben%number_of_players+1] == 1010){		//geben%number_of_players+1 ist der Nachfolger von geben.
					if (tac != 0) {
						if (number_2 <= 5){
							D[number_2] += 1;
						} else if (number_2 == 6){
							D[0] += 1;
						}
					} else if (opt == 5) {
						B[use_number] -= 1;
					} else {
						B[number_2] -= 1;
					}
					
				}
				
				if ((tac != 0)&&((D[1]+D[2]+D[3]+D[4]+D[5]+D[0]) == 0)){
					for (unsigned int p=0; p<=5; p+=1){
						D[p] = tac;
					}
				}
				
				menuoperator = 1;
				
				while (menuoperator != 0) {
				
					if (gamemode != 8) {
						if (opague >= 1) {
							show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
						} else {
							show_field (Sf, m, n, gamemode, information_code, geben, Colored);
						}
					}
					
					if ((gamemode == 6)&&(((scwhp == 1)&&((opt == 0)||((use_number == 2)||(use_number == 3)||(use_number == 4)))&&((tac == 0)||((D[2] != 0)||(D[3] != 0)||(D[4] != 0))))||(scwhp == 2))) {	//show contect bedingungen
						
						information_code[3] = 1;
						
						if (opague >= 1) {
							show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
						} else {
							show_field (Sf, m, n, gamemode, information_code, geben, Colored);
						}
						//printf("	opt,tac \n");	//test
					}
					
					if (gamemode == 4) {
						printf("\n");
						printf("	Points player 2: 	%u Point(s) \n", P[geben]);
					}
					
					if (gamemode == 10) {
						printf("\n");
						printf("	Lifes player 2: 	%u Life(s) \n", ulcer_lifes[2]);
					}
					
					if (gamemode == 11) {
						printf("	\n");
						printf("	Geschwindigkeit: 	Zeile: %d, 	Spalte: %d \n", dynamic_pointer[2], dynamic_pointer[3]);
						printf("	Beschleunigung: 	Zeile: %d, 	Spalte: %d \n", dynamic_pointer[4], dynamic_pointer[5]);
						printf("	\n");
					}
					
					printf("\n");
					
					if (Colored[0] == 1) {
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+Colored[geben]);
					}
					
					if ((gamemode != 6)&&(gamemode != 9)&&(gamemode != 10)&&(gamemode != 11)) {
						printf("	Am Zug: Spieler 2 (OO)	\n");
					} else if (gamemode == 6) {
						printf("	Am Zug: Spieler 2 (AA)	\n");
					} else if (gamemode == 9) {
						if (ability[1] == geben) {
							printf("	Am Zug: Spieler 2 (UU)	\n");
						} else if (ability[2] == geben) {
							printf("	Am Zug: Spieler 2 (LL)	\n");
						} else if (ability[3] == geben) {
							printf("	Am Zug: Spieler 2 (AA)	\n");
						} else if (ability[4] == geben) {
							printf("	Am Zug: Spieler 2 (CC)	\n");
						} else if (ability[5] == geben) {
							printf("	Am Zug: Spieler 2 (II)	\n");
						} else if (ability[6] == geben) {
							printf("	Am Zug: Spieler 2 (SS)	\n");
						} else if (ability[7] == geben) {
							printf("	Am Zug: Spieler 2 (PP)	\n");
						} else if (ability[8] == geben) {
							printf("	Am Zug: Spieler 2 (HH)	\n");
						} else if (ability[9] == geben) {
							printf("	Am Zug: Spieler 2 (EE)	\n");
						}
					} else if ((gamemode == 10)||(gamemode == 11)||(gamemode == 12)) {	//mehr-gamemode
						printf("	Am Zug: Spieler 2 (22)	\n");
					}
					
					if (Colored[0] == 1) {
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+7);
					}
					
					printf("\n");
					
					if (tac != 0){
						printf("	Your stack of numbers:	\n	1) [%u],		2) [%u],		3) [%u], \n\n	4) [%u],		5) [%u],		6) [%u],\n", D[1], D[2], D[3], D[4], D[5], D[0]);
						printf("\n");
						printf("\n");
					}
					
					if (opt == 5){		//random number
						printf("	Your number: %u ", use_number);
						printf("\n");
						printf("\n");
						
					}
					
					printf("	1) Plus:	11	Minus: 	12 \n");
					printf("	2) Move:	21	Change: 22 \n");
					printf("	3) Destroy:	31	Revive: 32 \n");
					printf("	4) Move:	41	Boost: 	42 \n");
					if (((gamemode != 9)&&(gamemode != 10))||((gamemode == 10)&&(geben == 1))) {
						printf("	5) 4/5-new:	51	2-new:	52 \n");
						printf("	6) 4-max:	61	1-min:	62 \n");
					} else if (gamemode == 9) {
						if (information_code[0] == 1) {
							printf("	5) 2/3-new:	51	0-new:	52 \n");
							printf("	6) 2-max:	61	-1-min:	62 \n");
						} else if (information_code[0] == 2) {
							printf("	5) 3/4-new:	51	1-new:	52 \n");
							printf("	6) 3-max:	61	0-min:	62 \n");
						} else if (information_code[0] == 3) {
							printf("	5) 5/6-new:	51	3-new:	52 \n");
							printf("	6) 5-max:	61	0-min:	62 \n");
						} else {
							printf("	5) 4/5-new:	51	2-new:	52 \n");
							printf("	6) 4-max:	61	1-min:	62 \n");
						}
					} else if ((gamemode == 10)&&(geben != 1)) {
						printf("	5) 3/4-new:	51	1-new:	52 \n");
						printf("	6) 3-max:	61	0-min:	62 \n");
					}
					printf("							\n");
					printf("		Go back: 100 \n");
					printf("		Menu: 10 \n");
					printf("		End game: 0 \n");
					if ((ttt != 0)&&(time_saver == 0.0)) {
						time1 = time(NULL);
					}
					scanf("%u", &var_[2]);
					
					if (var_[2] == 10){
						if (ttt != 0) {
							time3 = time(NULL);
						}
						while (menuoperator != 7) {
							printf("\n");
							printf("\n");
							printf("	About the game: 1 \n	Statistics: 2 \n	The numbers: 3 \n	The limits: 4 \n	Get Hints: 5 \n	Suprise: 6 \n	Quit Menu: 7 \n");
							scanf("%u", &menuoperator);
							
							if (menuoperator == 1){
								if (gamemode == 1) {
									printf("	How to win? 	Own a square on your last line or force your opponent to lose all his/her ones.\n");
								} else if (gamemode == 2) {
									printf("	How to win? 	Be at 2 of the 3 targets with three of your squares near-by.\n");
								} else if (gamemode == 3) {
									printf("	How to win? 	Take over all your opponent's squares by winning contact-battles.\n");
									printf("	Contact-battles? 	All near-by squares in a row with the contact-square build a chain, beat your opponent in the length.\n");
								} else if (gamemode == 4) {
									printf("	How to win? 	Get more points than your opponent.\n");
									printf("	Note:	Touch the #-square in the near-by to move it to the opposite side. \n");
								} else if (gamemode == 5) {
									printf("	How to win? 	Force your opponent to lose all his/her squares.\n");
								} else if (gamemode == 6) {
									if (geben == 1) {
										printf("	How to win? 	Protect your heart-block so no enemy can touch it.\n");
									} else {
										printf("	How to win? 	Catch the heart-block of the hunted one before it disappears.\n");
									}
								} else if (gamemode == 7) {
									printf("	How to win? 	Reach the end of the field or force your opponent to lose all his/her ones.\n");
									printf("	Note:	Every %u turns in total the #-line will go ahead and destroys everything in it's way.\n Also you are not allowed to cross the mid-line. \n", freq);
								} else if (gamemode == 8) {
									printf("	How to win? 	Reach [1][7] of the field or force your opponent to lose all his/her squares.\n");
									printf("	Note:	Falling down the #-squares will push, destroy, explode, or teleport, transform into yours by contact. \n");
								} else if ((gamemode == 9)||(gamemode == 10)) {
									printf("	How to win? 	Force your opponent to lose all his/her squares while keeping yours alive.\n");
								} else if (gamemode == 11) {
									printf("	How to win? 	Push the ball against your opponent's side.\n");
								} else if (gamemode == 12) {	//mehr-gamemode
									printf("	How to win? 	Stay alive.\n");
								}
								printf("	Surrounding:	The 8 squares around another, at the edge 5, in the corners 3, are called #surrounding. \n");
								printf("	near-by:	The 4 squares around another, at the edge 3, in the corners 2, are called #near-by. \n");
								printf("	Standard actions:	(After your choice of number and not influencing each other) \n	-Development:	If it is your turn and a free square has exactly 3 of yours surrounding it, you will own it.\n");
								printf("	-Losses: 	If it is your turn and a square of yours is surrounded by less than %u or more than %u of yours,\n			it will be set free.\n", d, e);
								if ((gamemode == 10)||(gamemode == 12)) {	//mehr-gamemode
									printf("	Limits: 	This gamemode is unlimited. \n");
								} else if (gamemode == 3) {
									printf("	Limits: 	Your development is limited by %u per round. \n", limit_new);
								} else {
									printf("	Limits: 	Your development is limited by %u per round, your units in total by %u per round. \n", limit_new, limit_at_all);
								}
							}
							
							if (menuoperator == 2){
								printf("\n");
								printf("	turns at all: %u \n", g);
								printf("\n");
								printf("	Numbers of player 1: \n");
								printf("		#1 = %u \n", A[1]);
								printf("		#2 = %u \n", A[2]);
								printf("		#3 = %u \n", A[3]);
								printf("		#4 = %u \n", A[4]);
								printf("		#5 = %u \n", A[5]);
								printf("		#6 = %u \n", A[6]);
								printf("\n");
								if (number_of_players >= 2) {	//mehr-gamemode
									printf("	Numbers of player 2: \n");
									printf("		#1 = %u \n", B[1]);
									printf("		#2 = %u \n", B[2]);
									printf("		#3 = %u \n", B[3]);
									printf("		#4 = %u \n", B[4]);
									printf("		#5 = %u \n", B[5]);
									printf("		#6 = %u \n", B[6]);
									printf("\n");
								}
								if (number_of_players >= 3){	//mehr-gamemode
									printf("	Numbers of player 3: \n");
									printf("		#1 = %u \n", AA[1]);
									printf("		#2 = %u \n", AA[2]);
									printf("		#3 = %u \n", AA[3]);
									printf("		#4 = %u \n", AA[4]);
									printf("		#5 = %u \n", AA[5]);
									printf("		#6 = %u \n", AA[6]);
									printf("\n");
								}
								if (number_of_players >= 4){
									printf("	Numbers of player 4: \n");
									printf("		#1 = %u \n", BB[1]);
									printf("		#2 = %u \n", BB[2]);
									printf("		#3 = %u \n", BB[3]);
									printf("		#4 = %u \n", BB[4]);
									printf("		#5 = %u \n", BB[5]);
									printf("		#6 = %u \n", BB[6]);
									printf("\n");
								}
								if (number_of_players >= 5){
									printf("	Numbers of player 5: \n");
									printf("		#1 = %u \n", AAA[1]);
									printf("		#2 = %u \n", AAA[2]);
									printf("		#3 = %u \n", AAA[3]);
									printf("		#4 = %u \n", AAA[4]);
									printf("		#5 = %u \n", AAA[5]);
									printf("		#6 = %u \n", AAA[6]);
									printf("\n");
								}
								if (number_of_players >= 6){
									printf("	Numbers of player 6: \n");
									printf("		#1 = %u \n", BBB[1]);
									printf("		#2 = %u \n", BBB[2]);
									printf("		#3 = %u \n", BBB[3]);
									printf("		#4 = %u \n", BBB[4]);
									printf("		#5 = %u \n", BBB[5]);
									printf("		#6 = %u \n", BBB[6]);
									printf("\n");
								}
								if (number_of_players >= 7){
									printf("	Numbers of player 7: \n");
									printf("		#1 = %u \n", AAAA[1]);
									printf("		#2 = %u \n", AAAA[2]);
									printf("		#3 = %u \n", AAAA[3]);
									printf("		#4 = %u \n", AAAA[4]);
									printf("		#5 = %u \n", AAAA[5]);
									printf("		#6 = %u \n", AAAA[6]);
									printf("\n");
								}
								if (number_of_players >= 8){
									printf("	Numbers of player 8: \n");
									printf("		#1 = %u \n", BBBB[1]);
									printf("		#2 = %u \n", BBBB[2]);
									printf("		#3 = %u \n", BBBB[3]);
									printf("		#4 = %u \n", BBBB[4]);
									printf("		#5 = %u \n", BBBB[5]);
									printf("		#6 = %u \n", BBBB[6]);
									printf("\n");
								}
								if (number_of_players == 9){
									printf("	Numbers of player 9: \n");
									printf("		#1 = %u \n", AAAAA[1]);
									printf("		#2 = %u \n", AAAAA[2]);
									printf("		#3 = %u \n", AAAAA[3]);
									printf("		#4 = %u \n", AAAAA[4]);
									printf("		#5 = %u \n", AAAAA[5]);
									printf("		#6 = %u \n", AAAAA[6]);
									printf("\n");
								}
								
								if ((gamemode == 1)||(gamemode == 6)||(gamemode == 7)||(gamemode == 8)) {
									printf("	Matchballs player 1: 	%u \n", A[0]);
									printf("	Matchballs player 2: 	%u \n", B[0]);
									if (gamemode == 6) {
										if (number_of_players >= 3){printf("	Matchballs player 3: 	%u \n", AA[0]);}
										if (number_of_players >= 4){printf("	Matchballs player 4: 	%u \n", BB[0]);}
										if (number_of_players >= 5){printf("	Matchballs player 5: 	%u \n", AAA[0]);}
										if (number_of_players >= 6){printf("	Matchballs player 6: 	%u \n", BBB[0]);}
										if (number_of_players >= 7){printf("	Matchballs player 7: 	%u \n", AAAA[0]);}
										if (number_of_players >= 8){printf("	Matchballs player 8: 	%u \n", BBBB[0]);}
										if (number_of_players == 9){printf("	Matchballs player 9: 	%u \n", AAAAA[0]);}
									}
								} else if (gamemode == 2) {
									printf("	Squares collected by player 1: 	%u \n", A[0]);
									printf("	Squares collected by player 2: 	%u \n", B[0]);
								} else if (gamemode == 3) {
									printf("	Times with squares <= 5, player 1: 	%u \n", A[0]);
									printf("	Times with squares <= 5, player 2: 	%u \n", B[0]);
								} else if (gamemode == 4) {
									printf("	Points player 1: 		%u \n", P[1]);
									printf("	Points Player 2: 		%u \n", P[2]);
									printf("	Turns with more points player 1: 	%u \n", A[0]);
									printf("	Turns with more points player 2: 	%u \n", B[0]);
									printf("	Number of not decided #-squares: 	%u \n", P[0]);
								} else if (gamemode == 3) {
									printf("	Times with squares < 5, player 1: 	%u \n", A[0]);
									printf("	Times with squares < 5, player 2: 	%u \n", B[0]);
								} else if (gamemode == 9) {
									printf("	Number of excluded abilites: 	%u \n", exclude_counter);
									printf("	Offensive abilities taken: 	%u \n", number_of_players-ability[0]);
									printf("	Defensive abilities taken: 	%u \n", ability[0]);
								} else if (gamemode == 10) {
									for (unsigned int p=1; p<=number_of_players; p+=1) {
										printf("		Spieler %u: %u life(s) left.\n", p, ulcer_lifes[p]);
									}
								} else if (gamemode == 11) {	//mehr-gamemode
									for (unsigned int p=1; p<=number_of_players; p+=1) {
										if ((ges[p] > 1000)||(ges[p] == 0)) {
											printf("	Spieler %u: is out.\n", p);
										} else if (ges[p] < 1000) {
											printf("	Spieler %u: You own %u squares.\n", p, ges[p]);
										}
									}
								} else if (gamemode == 12) {
									for (unsigned int p=1; p<=number_of_players; p+=1) {
										if ((ges[p] > 1000)||(ges[p] == 0)) {
											printf("	Spieler %u: is out.\n", p);
										} else if (ges[p] < 1000) {
											printf("	Spieler %u: You own %u squares.\n", p, ges[p]);
										}
									}
								}
								
								if (ttt != 0) {
									printf("	Number of penalties given until	now: %u \n", pere[0]);
								}
							}
							
							if (menuoperator == 3){
								if ((gamemode != 10)&&(gamemode != 12)) {
									printf("	Plus: Change a free square in the surrounding of yours in one of yours.\n");
								} else {
									printf("	Plus: Change a square in the surrounding of yours in one of yours.\n");
								}
								printf("	Minus: Delete one of your squares.\n");
								printf("	Move: The position of one of yours will change with a free, near-by square.\n");
								printf("	Revive: Your lost squares having no living squares of yours surrounding them at the beginning of your turn,\n		will be revived.\n");
								printf("	%u/%u-new: A free square has to be surrounded by %u or %u of yours during the development.\n", w+1, w+2, w+1, w+2);
								printf("	%u-new: A free square has to be surrounded by %u of yours during the development.\n", d, d);
								printf("	%u-max: A square of yours will survive even by %u of your squares surrounding it.\n", e+1, e+1);
								if (d == 0) {
									printf("	-1-min: A square of yours will survive even by only -1 of your squares surrounding it.\n");
								} else {
									printf("	%u-min: A square of yours will survive even by only %u of your squares surrounding it.\n", d-1, d-1);
								}
								
								if ((gamemode == 1)||(gamemode == 2)||(gamemode == 4)||(gamemode == 5)||(gamemode == 7)||(gamemode == 9)||(gamemode == 10)) {
									printf("	Change: A square of yours and a near-by square of your enemy will change positions.\n");
									printf("	Destroy: Delete a near-by square of your enemy.\n");
									printf("	Boost: Use all near-by squares of your enemy as your own for the development.\n");
									
								} else if (gamemode == 3) {
									
									printf("	Change: A square of yours and a square of your enemy in the surrounding will change positions.\n");
									printf("	Destroy: Delete a surrounding square of your enemy.\n");
									printf("	Boost: Use all surrounding squares of your enemy as your own for the development.\n");
									
								} else if (gamemode == 8) {
									printf("	Change: A square of yours and a near-by #-square will change positions.\n");
									printf("	Destroy: Delete a square of your enemy, but not in the last two lines.\n");
									printf("	Boost: Use all near-by #-squares as your own for the development.\n");
									
								} else if (gamemode == 6) {
									if (geben == 1) {
										printf("	Change: The heart-block and a square of yours will change positions.\n");
										printf("	Destroy: Delete a square of your enemy.\n");
										printf("	Boost: Touching the heart_block no square of yours can die.\n");
									} else {
										printf("	Change: A square of yours and a near-by square of the hunted one will change positions.\n");
										printf("	Destroy: Delete a near-by square of your enemy.\n");
										printf("	Boost: Use all near-by squares of the hunted one as your own for the development.\n");
									}
									
								} else if (gamemode == 11) {	//mehr-gamemode
									printf("	Change: A square of yours and a near-by square of your enemy or the near-by ball will change positions.\n");
									printf("	Destroy: Delete a near-by square of your enemy.\n");
									printf("	Boost: Use all near-by squares of your enemy and the near-by ball as your own for the development.\n");
								} else if (gamemode == 12) {
									printf("	Change: A square of yours and a near-by square of your enemy or a near-by object will change positions.\n");
									printf("	Destroy: Delete a near-by square of your enemy or a near-by object.\n");
									printf("	Boost: Use all near-by squares of your enemy and near-by objects as your own for the development.\n");
								}
								
								printf("\n");
							}
							
							if (menuoperator == 4){	//mehr-gamemode
								if ((gamemode != 10)&&(gamemode != 12)) {
									printf("	Limit of development:	%u \n", limit_new);
									if (gamemode != 3) {
										printf("	Limit in total:		%u \n", limit_at_all);
										printf("	Limit in total with >2-new< taken: %u -0/-1/-2/-3/-4.\n", limit_at_all);
									}
								}
							}
							
							if (menuoperator == 5){
								Spielfeld hint;
								unsigned int b, a;
								hint = Spielfeld_Create (m, n);
								printf("	New: 1 \n	Dying: 2 \n	Both: 3 \n");
								scanf("%u", &menuoperator);
								
								for (unsigned int i=1; i<(m-1); i+=1){
									for (unsigned int j=1; j<(n-1); j+=1){
										if ((gamemode != 6)&&(gamemode != 9)&&(gamemode != 10)&&(gamemode != 11)&&(gamemode != 12)) {	//mehr-gamemode
											if (Sf[i][j] == geben){
												hint[i][j] = geben;
											} else if (Sf[i][j] == (geben%2)+1){
												hint[i][j] = (geben%2)+1;
											} else if (Sf[i][j] == 7){
												hint[i][j] = 7;
											} 
										} else if ((gamemode == 6)||(gamemode == 9)||(gamemode == 10)) {	//10
											if (Sf[i][j] == geben){
												hint[i][j] = geben;
											} else if (Sf[i][j] != 0){
												hint[i][j] = 17;
											}
										} else if (gamemode == 11) {
											if (Sf[i][j] == geben){
												hint[i][j] = geben;
											} else if (Sf[i][j] == 77){
												hint[i][j] = 77;
											} else if (Sf[i][j] != 0){
												hint[i][j] = 17;
											}
										} else if (gamemode == 12) {	//mehr-gamemode
											if (Sf[i][j] == geben){
												hint[i][j] = geben;
											} else if (Sf[i][j] == 81){
												hint[i][j] = 81;
											} else if (Sf[i][j] == 82){
												hint[i][j] = 82;
											} else if (Sf[i][j] == 83){
												hint[i][j] = 83;
											} else if (Sf[i][j] == 84){
												hint[i][j] = 84;
											} else if (Sf[i][j] == 75){
												hint[i][j] = 75;
											} else if (Sf[i][j] == 71){
												hint[i][j] = 71;
											} else if (Sf[i][j] != 0){
												hint[i][j] = 17;
											}
										}
									}
								}
								
								if ((menuoperator == 2)||(menuoperator == 3)){
									for (unsigned int i=1; i<(m-1); i+=1){
										for (unsigned int j=1; j<(n-1); j+=1){
											if (Sf[i][j] == geben){
												a = 0;
												for (unsigned int h=(i-1); h<=(i+1); h+=1){
													for (unsigned int k=(j-1); k<=(j+1); k+=1){
														if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
															if (Sf[h][k] == geben){
																a += 1;
															}
														}
													}
												}
												if ((a > 4) || (a < 3)){
													hint[i][j] = 16;
												}
											}
										}
									}
								}
								
								if ((menuoperator == 1)||(menuoperator == 3)){
									for (unsigned int i=1; i<(m-1); i+=1){
										for (unsigned int j=1; j<(n-1); j+=1){
											if (Sf[i][j] == 0){
												b = 0;
												for (unsigned int h=(i-1); h<=(i+1); h+=1){
													for (unsigned int k=(j-1); k<=(j+1); k+=1){
														if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
															if (Sf[h][k] == geben){
																b += 1;
															}
														}
													}
												}
												if (b == 3){
													hint[i][j] = 15;
												}
											}
										}
									}
								}
						
								if (opague >= 1) {
									Sf_opague = opague_builder (hint, m, n, geben, opague, aop);
								}
								
								if (opague >= 1) {
									show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
								} else {
									show_field (hint, m, n, gamemode, information_code, geben, Colored);
								}
								
								if (opague >= 1) {
									Sf_opague = opague_builder (Sf, m, n, geben, opague, aop);
								}
								menuoperator = 1;
								Spielfeld_Destroy (hint, m);
							}
							// 2
							if (menuoperator == 6){
								if (suprise == 0) {
									for (unsigned int i=1; i<m-1; i+=1){
										for (unsigned int j=1; j<n-1; j+=1){
											cons_field_2[i][j] = Sf[i][j];
											
											if (journey == 1){
												cons_journey_2[i][j] = Sf_journey[i][j];
											}
										}
									}
									sup_num = use_number;
								}
								
								while (menuoperator != 1) {
						
									printf("	Creator menu. 	Change number: 1	Suprise: 2	Suprise undo: 3	Back: 4 \n");
									scanf ("%u", &lim);
									if (lim == 1){
										printf("	number = ? \n");
										scanf ("%u", &use_number);
									} else if (lim == 2){
								
										printf("\n");
										scanf("%u", &suprise);
								
										if (suprise == 31){
											for (unsigned int i=2; i<m-2; i+=1){
												for (unsigned int j=1; j<n-1; j+=1){
													if (Sf[i][j] != 0){
														if (Sf[i][j] == 1){
															Sf[i][j] = 2;
														} else if (Sf[i][j] == 2){
															Sf[i][j] = 1;
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
								
										if(suprise == 13){
											for (unsigned int i=1; i<m-1; i+=1){
												for (unsigned int j=1; j<n-1; j+=1){
													if (Sf[i][j] == 2){
														Sf[i][j] = 0;
													}
													if (i == (m-2)){
														Sf[m-2][j] = 2;
													}
												}
											}
										}
								
									} else if (lim == 3){
										for (unsigned int i=1; i<m-1; i+=1){
											for (unsigned int j=1; j<n-1; j+=1){
												Sf[i][j] = cons_field_2[i][j];
												
												if (journey == 1){
													Sf_journey[i][j] = cons_journey_2[i][j];
												}
											}
										}
										use_number = sup_num;
									} else if (lim == 4){
										menuoperator = 1;
									} else {
										printf("	Invalid comment");
									}
								}
							}
						}	// menuoperator = 7
						
						if (gamemode == 8) {
							if (opague >= 1) {
								show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
							} else {
								show_field (Sf, m, n, gamemode, information_code, geben, Colored);
							}
							
							printf("\n");
						
						}
						
						if (ttt != 0) {
							time4 = time(NULL);
							time_saver += difftime(time4, time3);
						}
					}	//Menu-end
					
					menuoperator = 0;
					if (var_[2] == 10) {
						menuoperator = 1;
						var_[2] = 5;
					}
					
					if ((tac != 0)&&(var_[2] <= 62)&&(var_[2] > 10)){
						unsigned int tac_controll;
						tac_controll = 0;
						if (((var_[2]%10) > 2)||((var_[2]%10) == 0)){
							var_[2] = 7;
							menuoperator = 1;
						} else {
							for (unsigned int z=var_[2]; z>2; z-=10){
								tac_controll += 1;
							}
							if (tac_controll == 6){
								tac_controll = 0;
							}
							if (D[tac_controll] == 0){
								var_[2] = 7;
								menuoperator = 1;
							} else {
								D[tac_controll] -= 1;
							}
						}
					} else if ((tac != 0)&&(var_[2] != 100)&&(var_[2] != 1010)&&(var_[2] != 0)) {
						var_[2] = 7;
					}		
					//tac-mode
					
					if (opt == 5){
						controll_1 = 10+use_number;
						controll_2 = 11+use_number;
					
						for (unsigned int i=0; i<use_number-1; i+=1){
							controll_1 += 9;
							controll_2 += 9;
						}
					
						if (var_[2] == 0){
							controll_1 = 0;
							controll_2 = 0;
						}
						if (var_[2] == 100){
							controll_1 = 100;
							controll_2 = 100;
						}
						if (var_[2] == 1010){
							controll_1 = 1010;
							controll_2 = 1010;
						}
					}
					//
					if (((var_[2] > 0)&&(var_[2] < 10))||(((opt == 5)&&(var_[2] != controll_1))&&((opt == 5)&&(var_[2] != controll_2)))){
						
						if (var_[2] != 5) {
							printf("	You made a mistake, try again: \n");
							printf("\n");
							printf("\n");
						} else {
							printf("	You closed the menu. \n");
							printf("\n");
							printf("\n");
						}
						
						//enough
						
						menuoperator = 1;
					}
					
				}		// menuoperator = 0
				
				
				suprise = 0;
				
				if (var_[2] == 0){
					printf("	Do you really want to end the game ? \n");
					printf("	Yes: 0		No: 1 \n");
					scanf("%u", &lim);
					if (lim == 0){
						break;
					} else if (lim == 1){
						continue;
					} else {
						printf("	0 or 1, it is so difficult to understand? \n");
						printf("	Well, it seems I have to end it by myself... \n");
						break;
					}	
				} else {
					
					if (var_[2] == 100){
						
						var_[0] = 1;
						
						for (unsigned int i=1; i<m-1; i+=1){
							for (unsigned int j=1; j<n-1; j+=1){
								Sf[i][j] = cons_field_1[i][j];
								if (journey == 1){
									Sf_journey[i][j] = cons_journey_1[i][j];
								}
							}
						}
						
						if (opague >= 1) {
							Sf_opague = opague_builder (Sf, m, n, geben, opague, aop);
						}
						
						if (opague >= 1) {
							show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
						} else {
							show_field (Sf, m, n, gamemode, information_code, geben, Colored);
						}
						
						cons[geben] = use_number;
						
						use_number = cons[1];
						
						if (gamemode == 11) {	//mehr-gamemode
							for (unsigned int p=2; p<=5; p+=1) {
								
								dynamic_pointer[p] = dynamic_pointer_save[1][p-2];
								
							}
						}
						
						g-=1;
						var_[2] = 1010;
						if (gamemode == 10) {
							ulcer_lifes[2] += 1;
							ulcer_start[2] = 0;
						}
						continue;
					} else {
						
						if (number_of_players == 2) {
							
							if (var_[1] != 1010){
								for (unsigned int i=1; i<m-1; i+=1){
									for (unsigned int j=1; j<n-1; j+=1){
										cons_field_2[i][j] = Sf[i][j];
										
										if (journey == 1){
											cons_journey_2[i][j] = Sf_journey[i][j];
										}
									}
								}
							}
						} else if (number_of_players >= 3) {
							if (var_[3] != 1010){
								for (unsigned int i=1; i<m-1; i+=1){
									for (unsigned int j=1; j<n-1; j+=1){
										cons_field_2[i][j] = Sf[i][j];
										
										if (journey == 1){
											cons_journey_2[i][j] = Sf_journey[i][j];
										}
									}
								}
							}
						}
						
						var_[0] = 0;
						
						if (var_[2] < 50){
							
							if (var_[2] == 11){B[1] += 1; Plus (m, n, geben, Sf, limit_at_all, gamemode, information_code, number_of_players, Colored, opague, Sf_opague);}
							if (var_[2] == 12){B[1] += 1; Minus (m, n, geben, Sf, gamemode, information_code, Colored, opague, Sf_opague);}
							if (var_[2] == 21){B[2] += 1; Move (m, n, geben, Sf, gamemode, information_code, Colored, opague, Sf_opague);}
							if (var_[2] == 41){B[4] += 1; Move (m, n, geben, Sf, gamemode, information_code, Colored, opague, Sf_opague);}
							if (var_[2] == 22){B[2] += 1; Change (m, n, geben, Sf, gamemode, information_code, Colored, opague, Sf_opague, position);}
							if (var_[2] == 31){B[3] += 1; Destroy (m, n, geben, Sf, gamemode, information_code, Colored, opague, Sf_opague);}
							if (var_[2] == 42){
								B[4] += 1; 
								Boost (geben, Sf, m, n, temp, gamemode);
							}
						} else {
							if (var_[2] == 51){B[5] += 1; w += 1;}		//w
							if (var_[2] == 52){B[5] += 1; w -= 1;}		//w
							if (var_[2] == 61){B[6] += 1; e += 1;}		//e
							if (var_[2] == 62){B[6] += 1; if (d != 0) {d -= 1;} else {d = 10;}}		//d
						}		//printf("ok(1376)");
						
						if (ttt != 0) {
							time2 = time(NULL);
							time_warning = ((difftime(time2, time1)) - time_saver);
							
							//printf("	time_warning: %f \n", time_warning);		//test
							
							if ((pere[geben] != 0)&&((pere[geben] + warning_system) <= 6)) {
								if (pere[geben] == 1) {
									if (warning_system <= 2) {
										time_warning += 1.0;
									} else if (warning_system == 3) {
										time_warning += 2.0;
									} else if (warning_system == 4) {
										time_warning += 3.0;
									} else if (warning_system == 5) {
										time_warning += 5.0;
									}
								} else if (pere[geben] == 2) {
									if (warning_system == 1) {
										time_warning += 2.0;
									} else if (warning_system == 2) {
										time_warning += 3.0;
									} else if (warning_system == 3) {
										time_warning += 5.0;
									} else if (warning_system == 4) {
										time_warning += 6.0;
									}
								} else if (pere[geben] == 3) {
									if (warning_system == 1) {
										time_warning += 3.0;
									} else if (warning_system == 2) {
										time_warning += 5.0;
									} else if (warning_system == 3) {
										time_warning += 8.0;
									}
								} else if (pere[geben] == 4) {
									if (warning_system == 1) {
										time_warning += 4.0;
									} else if (warning_system == 2) {
										time_warning += 7.0;
									}
								} else if (pere[geben] == 5) {
									if (warning_system == 1) {
										time_warning += 5.0;
									}
								}
							}
							
							if (time_warning > (1.0*ttt)) {
								pere[0] += 1;
								printf("	You took too much time! %f sec more than you should. \n", (time_warning-1.0*ttt) );
								printf(" \n");
								for (unsigned int p=16; p>=1; p-=3) {	//index_verschiebung
									if ((time_warning-1.0*ttt) > 1.0*(p-1)) {
										pere[geben] = (((p-1)/3) + 1);
										break;
									}
								}
							} else {
								pere[geben] = 0;
							}
						}
						
						Sf_nl_2 = new_life_2 (Sf, m, n, w, gamemode, information_code);		//printf("ok(1378)");
						
						if (gamemode == 6) {
							
							precounter = 0;
							for (unsigned int i=1; i<m-1; i+=1){
								for (unsigned int j=1; j<n-1; j+=1){
									if (Sf[i][j] == 11){
										if (Sf_nl_2[i][j-1] > 1) {
											printf (" Sieg: Spieler %u \n", Sf_nl_2[i][j-1]);
											precounter += 1;
										}
										if (Sf_nl_2[i][j+1] > 1) {
											if (precounter == 0) {
												printf (" Sieg: Spieler %u \n", Sf_nl_2[i][j+1]);
											}
											precounter += 1;
										}
										if (Sf_nl_2[i-1][j] > 1) {
											if (precounter == 0) {
												printf (" Sieg: Spieler %u \n", Sf_nl_2[i-1][j]);
											}
											precounter += 1;
										}
										if (Sf_nl_2[i+1][j] > 1) {
											if (precounter == 0) {
												printf (" Sieg: Spieler %u \n", Sf_nl_2[i+1][j]);
											}
											precounter += 1;
										}
										if (precounter == 2) {
											printf(" Double-catch! \n");
										}
										if (precounter == 3) {
											printf(" TRIPLE-catch!! \n");
										}
										if (precounter == 4) {
											printf(" QUADRO-CATCH!!! \n");
										}
										break;
									}
								}
								if (precounter > 0) {
									break;
								}
							}
							if (precounter > 0) {
								for (unsigned int i=1; i<m-1; i+=1){
									for (unsigned int j=1; j<n-1; j+=1){
										if (Sf_nl_2[i][j] == geben) {
											Sf[i][j] = geben;
										}
									}
								}
								show_field (Sf, m, n, gamemode, information_code, geben, Colored);
								break;
							}
						}
						
						controll = 0;
						if (gamemode == 7) {
							for (unsigned int i=(m-2); i>=(m-1)/2; i-=1){		//Spiel-Ende?
								if ((Sf_nl_2[i][n-2] == 2)||(Sf[i][n-2] == 2)){
									for (unsigned int k=(m-2); k>=1; k-=1){
										if (Sf_nl_2[k][n-2] == 2){
											Sf[k][n-2] = 2;
										}
									}
									show_field (Sf, m, n, gamemode, information_code, geben, Colored);
									printf("	Sieg:	Spieler 2 \n");
									controll = 1;
								}
							}
							if (controll == 1){
								break;
							}
						}
						controll = 0;
						
						num_1 = 0;
						for (unsigned int i=1; i<m-1; i+=1){
							for (unsigned int j=1; j<n-1; j+=1){
								if (Sf_nl_2[i][j] == 2){
									num_1 += 1;
								}
							}
						}		//printf("ok(1387)");	
					
						
						if (var_[2] == 42){
							for (unsigned int i=1; i<m-1; i+=1){
								for (unsigned int j=1; j<n-1; j+=1){
									if (gamemode == 8) {
										if (temp[i][j] == 2){
											Sf[i][j] = 0;
										}
									} else if ((gamemode == 9)||(gamemode == 10)||(gamemode == 11)||(gamemode == 12)) {	//mehr-gamemode
										if (temp[i][j] != 0){
											Sf[i][j] = temp[i][j];
										}
									} else if ((gamemode != 8)&&(gamemode != 9)&&(gamemode != 10)&&(gamemode != 11)&&(gamemode != 12)) {	//10
										if (temp[i][j] == 2){
											Sf[i][j] = 1;
										}
									}
								}
							}
						}		//printf("ok(1398)");	
						
						controll = 0;
						if (gamemode == 1){
							for (unsigned int erste=1; erste<n-1; erste+=1){		//printf("ok(1400)");		//Spiel-Ende?
								if (Sf[1][erste] == 2){
									printf("	Sieg:	Spieler 2 \n");
									show_field (Sf, m, n, gamemode, information_code, geben, Colored);
									controll = 1;		//printf("ok(1404)");
									break;
								}
							}
							if (controll == 1){
								break;		//printf("ok(1409)");
							}		//printf("ok(1410)");
						}
						controll = 0;
						
						Spielfeld_Destroy (temp, m);		//printf("ok(1412)");
					
						Sf_od_2 = old_dying_2 (Sf, m, n, d, e, gamemode, information_code);		//printf("ok(1414)");
						
						if (journey == 1){
							unsigned int journey_max;
							journey_max = 0;
							for (unsigned int i=1; i<m-1; i+=1){
								for (unsigned int j=1; j<n-1; j+=1){
									if (Sf_journey[i][j] == 2){
										journey_max += 1;
									}
								}
							}
							for (unsigned int i=1; i<m-1; i+=1){
								for (unsigned int j=1; j<n-1; j+=1){
									if ((Sf_od_2[i][j] == 202) && (Sf_journey[i][j] == 0) && (journey_max >= limit_at_all)){
										for (unsigned int u=(m-2); u>0; u-=1){
											for (unsigned int o=1; o<(n-1); o+=1){
												if ((Sf_journey[u][o] == 2)&&((u+o)%2 == 0)){
													Sf_journey[u][o] = 0;
													journey_max -= 1;
													if (journey_max < limit_at_all){
														break;
													}
												}
											}
											if (journey_max < limit_at_all){
												break;
											}
										}
										
									}
									if ((Sf_od_2[i][j] == 202) && (Sf_journey[i][j] == 0) && (journey_max < limit_at_all)){
										Sf_journey[i][j] = 2;
										journey_max += 1;
									}
								}
							}
							journey_max = 0;
						}
						
						if (var_[2] == 32){B[3] += 1; Revive_2(m, n, Sf_od_2, Sf);}
						
						num_2 = 0;
						for (unsigned int i=1; i<m-1; i+=1){
							for (unsigned int j=1; j<n-1; j+=1){
								if (Sf_od_2[i][j] == 202){
									num_2 += 1;
								}
							}
						}
					
						count_new = 0;
						for (unsigned int i=1; i<m-1; i+=1){
							for (unsigned int j=1; j<n-1; j+=1){
								if (Sf_nl_2[i][j] == 2){
									count_new += 1;
								}
							}
						}
						ent = limit_new;		//printf("ok(1473)");
						
						for (unsigned int i=1; i<m-1; i+=1){
							for (unsigned int j=1; j<n-1; j+=1){
								if ((Sf[i][j] == 2) && (Sf_od_2[i][j] == 0)){
									zeitgewinner += 1;
								}
							}
						}
						
						if (count_new > limit_new){		//Abfrage auf max. 10 neue Steine
							if (gamemode == 1) {
								Sf_nl_2 = Index_2 (ent, count_new, m, n, Sf, Sf_nl_2, Sf_od_2, limit_new, limit_at_all, zeitgewinner);	
							} else if (gamemode == 2) {
								Sf_nl_2 = Index_2_col (ent, count_new, m, n, Sf, Sf_nl_2, Sf_od_2, limit_new, limit_at_all, zeitgewinner);	
							} else if (gamemode == 3) {
								Sf_nl_2 = Index_2_con (ent, count_new, m, n, Sf, Sf_nl_2, limit_new);
							} else if (gamemode == 4) {
								Sf_nl_2 = Index_2_fal (ent, count_new, m, n, Sf, Sf_nl_2, Sf_od_2, limit_new, limit_at_all, zeitgewinner);	
							} else if (gamemode == 5) {
								Sf_nl_2 = Index_2_fig (ent, count_new, m, n, Sf, Sf_nl_2, Sf_od_2, limit_new, limit_at_all, zeitgewinner);	
							} else if (gamemode == 6) {
								Sf_nl_2 = Index_other_hunt (ent, count_new, m, n, Sf_nl_2, geben, zeitgewinner, Sf, limit_at_all);	
							} else if (gamemode == 7) {
								Sf_nl_2 = Index_2_race (ent, count_new, m, n, Sf, Sf_nl_2, Sf_od_2, limit_new, limit_at_all, zeitgewinner);	
							} else if (gamemode == 8) {
								Sf_nl_2 = Index_2_rain (ent, count_new, m, n, Sf, Sf_nl_2, Sf_od_2, limit_new, limit_at_all, rain, zeitgewinner);	
							} else if (gamemode == 9) {
								Sf_nl_2 = Index_are (ent, count_new, m, n, Sf_nl_2, Sf_od_2, limit_new, limit_at_all, zeitgewinner, Sf, w, d, e, geben);
							} else if (gamemode == 10) {
								count_new = 0;
							} else if (gamemode == 11) {
								Sf_nl_2 = Index_dyn (ent, count_new, m, n, Sf_nl_2, Sf_od_2, limit_new, limit_at_all, zeitgewinner, Sf, w, d, e, geben, position);
							} else if (gamemode == 12) {	//mehr-gamemode
								count_new = 0;
							}
						
						}
						ent = 0;
						count_new = 0;		//printf("ok(1478)");
					
						num_3 = 0;
						for (unsigned int i=1; i<m-1; i+=1){
							for (unsigned int j=1; j<n-1; j+=1){
								if (((Sf[i][j] == 2) && (Sf_od_2[i][j] == 0)) || (Sf_nl_2[i][j] == 2)){
									count_new += 1;
									num_3 += 1;
								}
							}
						}
						
						ent = limit_at_all;
						if ((gamemode == 1)||(gamemode == 2)||(gamemode == 4)||(gamemode == 5)||(gamemode == 7)||(gamemode == 8)) {
							
							if (var_[2] == 52){
											//printf("ok(1492)");
								lim = 0;
								for (unsigned int i=1; i<m-1; i+=1){
									for (unsigned int j=1; j<n-1; j+=1){
										if ((Sf[i][j] == 2) && (Sf_od_2[i][j] == 0)){
											lim += 1;
										}
									}
								}
											//printf("ok(1501)");
								ent = lim;
											//printf("ok(1503)");
								lim = 0;
								for (unsigned int i=1; i<m-1; i+=1){
									for (unsigned int j=1; j<n-1; j+=1){
										if (Sf[i][j] == 1){
											lim += 1;
										}
									}
								}			//printf("ok(1511)");
							
							
								if ((lim <= limit_new) && (ent < (limit_at_all - 1))){
									if (ent >= (limit_at_all - 3)){
										ent = limit_at_all - 1;
									} else if (ent >= (limit_at_all - 5)){
										ent = limit_at_all - 2;
									} else if (ent >= (limit_at_all - 7)){
										ent = limit_at_all - 3;
									} else if (ent >= (limit_at_all - 10)){
										ent = limit_at_all - 4;
									} else {
										ent = limit_at_all;
									}		//printf("ok(1523)");
								} else {		//printf("ok(1524)");
									ent = limit_at_all;
								}
								lim = 0;
											//printf("ok(1528)");
							}
						}
						
						if (count_new > ent){		//Abfrage auf insgesamt max. 20 Steine, normalerweise
							if (gamemode == 1) {
								Sf_nl_2 = Index_2 (ent, count_new, m, n, Sf, Sf_nl_2, Sf_od_2, limit_new, limit_at_all, zeitgewinner);	
							} else if (gamemode == 2) {
								Sf_nl_2= Index_2_col  (ent, count_new, m, n, Sf, Sf_nl_2, Sf_od_2, limit_new, limit_at_all, zeitgewinner);	
							} else if (gamemode == 3) {
								count_new = 0;
							} else if (gamemode == 4) {
								Sf_nl_2 = Index_2_fal (ent, count_new, m, n, Sf, Sf_nl_2, Sf_od_2, limit_new, limit_at_all, zeitgewinner);	
							} else if (gamemode == 5) {
								Sf_nl_2 = Index_2_fig (ent, count_new, m, n, Sf, Sf_nl_2, Sf_od_2, limit_new, limit_at_all, zeitgewinner);	
							} else if (gamemode == 6) {
								Sf_nl_2 = Index_other_hunt (ent, count_new, m, n, Sf_nl_2, geben, zeitgewinner, Sf, limit_at_all);	
							} else if (gamemode == 7) {
								Sf_nl_2 = Index_2_race (ent, count_new, m, n, Sf, Sf_nl_2, Sf_od_2, limit_new, limit_at_all, zeitgewinner);	
							} else if (gamemode == 8) {
								Sf_nl_2 = Index_2_rain (ent, count_new, m, n, Sf, Sf_nl_2, Sf_od_2, limit_new, limit_at_all, rain, zeitgewinner);	
							} else if (gamemode == 9) {
								Sf_nl_2 = Index_are (ent, count_new, m, n, Sf_nl_2, Sf_od_2, limit_new, limit_at_all, zeitgewinner, Sf, w, d, e, geben);	
							} else if (gamemode == 10) {
								count_new = 0;
							} else if (gamemode == 11) {
								Sf_nl_2 = Index_dyn (ent, count_new, m, n, Sf_nl_2, Sf_od_2, limit_new, limit_at_all, zeitgewinner, Sf, w, d, e, geben, position);
							} else if (gamemode == 12) {	//mehr-gamemode
								count_new = 0;
							}
						
						}
						ent = 0;
						zeitgewinner = 0;
						
						if (gamemode == 4) {
							touch (Sf, m, n, geben, Sf_nl_1, Sf_nl_2);
						}
						
						Sf = change_2 (Sf, Sf_nl_2, Sf_od_2, m, n, gamemode, number_of_players, ges);
						
						if (gamemode == 1) {
							for (unsigned int j=1; j<n-1; j+=1){
								if (Sf[2][j] == 2){
									B[0] += 1;
									break;
								}
							} 
						} else if (gamemode == 2) {
							for (unsigned int j=2; j<n-1; j+=((n-1)/2)-2){		//collect-Bed. prüfen
								unsigned int b;
								b = 0;
								if (Sf[((m-1)/2)][j] == 7){
									if (Sf[((m-1)/2)-1][j]==2){b += 1;}
									if (Sf[((m-1)/2)+1][j]==2){b += 1;}
									if (Sf[(m-1)/2][j-1]==2){b += 1;}
									if (Sf[(m-1)/2][j+1]==2){b += 1;}
									if (b >= 3){
										B[0] += 1;
										Sf[((m-1)/2)][j] = 2;
									}
								}
							}
							if (B[0] == 2){
								printf("\n");
								printf("	Sieg: Spieler 2 \n");
								printf("\n");
								show_field (Sf, m, n, gamemode, information_code, geben, Colored);
								break;
							}
						}
						
						if ((gamemode == 6)&&(geben == number_of_players)) {
							lim = 1;
							printf("	\n");
							if (opague >= 1) {
								show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
							} else {
								show_field (Sf, m, n, gamemode, information_code, geben, Colored);
							}
							printf("	\n");
							while (lim == 1) {
								printf("	\n");
								printf("	\n");
								printf("	Are you ready to make your turn? \n");
								printf("	Yes: 1 \n");
								printf("	\n");
								printf("	\n");
								scanf("%u", &lim);
								
								if (lim != 1) {
									lim = 1;
								} else {
									lim = 0;
								}
							}
						}
						if (gamemode == 6) {
							information_code[3] = 0;
						}
						
						controll = 0;
						if (gamemode == 1) {
							for (unsigned int erste=1; erste<n-1; erste+=1){		//Spiel-Ende?
								if (Sf[1][erste] == 2){
									printf("	Sieg:	Spieler 2 \n");
									controll = 1;
									break;
								}
							}
							if (controll == 1){
								break;
							}
						}
						controll = 0;
						
						if (gamemode == 3) {
							if (opague >= 1) {
								show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
							} else {
								show_field (Sf, m, n, gamemode, information_code, geben, Colored);
							}
							battle (m, n, Sf, geben);
						}
						
						if (number_of_players == 2) {
							if (var_[1] != 1010) {
								cons[2] = use_number;
								
								if (gamemode == 11) {	//mehr-gamemode
									for (unsigned int p=2; p<=5; p+=1) {
										
										dynamic_pointer_save[2][p-2] = dynamic_pointer[p];
										
									}
								}
								
							}
							
						} else if (number_of_players >= 3) {
							if (var_[3] != 1010) {
								cons[2] = use_number;
								
								if (gamemode == 11) {	//mehr-gamemode
									for (unsigned int p=2; p<=5; p+=1) {
										
										dynamic_pointer_save[2][p-2] = dynamic_pointer[p];
										
									}
								}
								
							}
							
						}
						
						use_number = random_number (num_1, num_2, num_3, use_number, g, var_, number_3, number_4);
						
						if ((opt != 5)&&(var_[2] <= 62)){
							controll_2 = 0;
							for (unsigned int z=var_[2]; z>2; z-=10){
								controll_2 += 1;
							}
							number_2 = controll_2;
							//printf("%u \n", number_2);
							controll_2 = 0;
						}
					}
				}	//{}ausfindig machen		Original Ende
				
				
			} else if (geben == 3) {		//following players
				
				if (opague >= 1) {
					Sf_opague = opague_builder (Sf, m, n, geben, opague, aop);
					
				}
				
				if ((ttt != 0)&&(pere[geben] == 100)) {
					g += 1;
					continue;
				}
				
				if ((gamemode == 10)&&(ulcer_start[3] == 0)) {
					if (opague >= 1) {
						show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
					} else {
						show_field (Sf, m, n, gamemode, information_code, geben, Colored);
					}
					g += 1;
					continue;
				}
				
				if ((ges[3] == 3030)&&((gamemode == 6)||(gamemode == 9)||(gamemode == 10)||(gamemode == 11)||(gamemode == 12))) {	//mehr-gamemode
					g+=1;
					var_[3] = 3030;
					cons[3] = cons[2];
					for (unsigned int i=1; i<m-1; i+=1){
						for (unsigned int j=1; j<n-1; j+=1){
							cons_field_3[i][j] = cons_field_2[i][j];
							if (journey == 1){
								cons_journey_3[i][j] = cons_journey_2[i][j];
								
								if (Sf_journey[i][j] == 3) {
									Sf_journey[i][j] = 0;
								}
							}
							if (gamemode == 11) {	//mehr-gamemode
								for (unsigned int p=2; p<=5; p+=1) {
									
									dynamic_pointer_save[2][p-2] = dynamic_pointer_save[3][p-2];
									
								}
							}
						}
					}
					if (var_[0] == 1) {
						g-=2;
					}
					continue;
				}
				
				w = 3;
				d = 2;
				e = 3;
				if (gamemode == 9) {
					if (ability[1] == geben) {
						w = 1;
						d = 0;
						e = 1;
						information_code[0] = 1;
					} else if (ability[2] == geben) {
						w = 2;
						d = 1;
						e = 2;
						information_code[0] = 2;
					} else if (ability[3] == geben) {
						w = 4;
						d = 1;
						e = 4;	//abweichende e-definition
						information_code[0] = 3;
					} else if (ability[4] == geben) {
						information_code[0] = 4;
					} else if (ability[5] == geben) {
						information_code[0] = 5;
					} else if (ability[6] == geben) {
						information_code[0] = 6;
					} else if (ability[7] == geben) {
						information_code[0] = 7;
					} else if (ability[8] == geben) {
						information_code[0] = 8;
					} else if (ability[9] == geben) {
						information_code[0] = 9;
						
						if (opague >= 1) {
							show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
						} else {
							show_field (Sf, m, n, gamemode, information_code, geben, Colored);
						}
						
						for (unsigned int i=1; i<m-1; i+=1){
							for (unsigned int j=1; j<n-1; j+=1){
								if (Sf[i][j] == geben) {
									if ((Sf[i+1][j] != 0)&&(Sf[i+1][j] != geben)&&((i+2) <= (m-2))) {
										if (Sf[i+2][j] == 0) {
											Sf[i+2][j] = Sf[i+1][j];
											Sf[i+1][j] = 0;
										}
									}
									if ((Sf[i-1][j] != 0)&&(Sf[i-1][j] != geben)&&((i-2) >= 1)) {
										if (Sf[i-2][j] == 0) {
											Sf[i-2][j] = Sf[i-1][j];
											Sf[i-1][j] = 0;
										}
									}
									if ((Sf[i][j-1] != 0)&&(Sf[i][j-1] != geben)&&((j-2) >= 1)) {
										if (Sf[i][j-2] == 0) {
											Sf[i][j-2] = Sf[i][j-1];
											Sf[i][j-1] = 0;
										}
									}
									if ((Sf[i][j+1] != 0)&&(Sf[i][j+1] != geben)&&((j+2) <= (n-2))) {
										if (Sf[i][j+2] == 0) {
											Sf[i][j+2] = Sf[i][j+1];
											Sf[i][j+1] = 0;
										}
									}
								}
							}
						}
					}
				}
				
				if (gamemode == 10) {
					w = 2;
					d = 1;
					e = 2;
				}
				
				if (gamemode == 9) {
					if (information_code[0] == 1) {
						limit_at_all = limit_at_all-2;
					} else if (information_code[0] == 2) {
						limit_at_all = limit_at_all-1;
					} else {
						limit_at_all = limit_at_all_saver;
					}
				}
				
				if (ttt != 0) {
					if ((pere[geben] != 0)&&(warning_system <= 5)&&((pere[geben]+warning_system) == 7)) {
						g += 1;
						printf(" \n ");
						printf("	You got a penalty. \n ");
						printf(" \n ");
						pere[geben] = 0;
						continue;
					} else if ((pere[geben] != 0)&&(warning_system != 0)&&(((warning_system <= 5)&&((pere[geben]+warning_system) == 8))||((warning_system == 6)&&(pere[geben] == 1)))) {
						Sf_od_3 = old_dying_3 (Sf, m, n, d, e, gamemode, information_code);
						Sf = change_3 (Sf, Sf_nl_3, Sf_od_3, m, n, gamemode, number_of_players, ges); 	//Change befreit
						g += 1;
						printf(" \n ");
						printf("	You got a penalty. \n ");
						printf(" \n ");
						pere[geben] = 0;
						continue;
					} else if (((warning_system <= 5)&&((warning_system + pere[geben]) >= 9))||((warning_system >= 6)&&((warning_system + pere[geben]) >= 8))) {
						printf("	Niederlage: Spieler 3 \n ");
						for (unsigned int i=1; i<m-1; i+=1){
							for (unsigned int j=1; j<n-1; j+=1){
								if (Sf[i][j] == 3) {
									Sf[i][j] = 0;
								}
							}
						}
						ges[3] = 3030;
						player_counter += 1;
						pere[geben] = 100;
						g += 1;
						continue;
					}
				}
				
				if (var_[geben] == 1010) {
					use_number = cons[geben];
					if (opt == 5) {
					
						printf("	Player %u ,do you want to keep your number (%u) or do you want to get the next one? \n", geben, cons[geben]);
						printf("	Keep the number: 	1 \n");
						printf("	Get the next one:	2 \n");
						scanf("%u", &lim);
						
						if (lim == 2) {
							use_number = random_number (num_1, num_2, num_3, use_number, g, var_, number_3, number_4);
						} else if (lim != 1) {
							printf("	Well, you keep your number, but next time please take an option i offered. \n\n");
						}
						lim = 0;
					
					}
				}
				
				if (var_[geben%number_of_players+1] == 1010){		//geben%number_of_players+1 ist der Nachfolger von geben.
					if (tac != 0) {
						if (number_3 <= 5){
							CC[number_3] += 1;
						} else if (number_3 == 6){
							CC[0] += 1;
						}
					} else if (opt == 5) {
						AA[use_number] -= 1;
					} else {
						AA[number_3] -= 1;
					}
					
				}
				
				if ((tac != 0)&&((CC[1]+CC[2]+CC[3]+CC[4]+CC[5]+CC[0]) == 0)){
					for (unsigned int p=0; p<=5; p+=1){
						CC[p] = tac;
					}
				}

				menuoperator = 1;
				
				while (menuoperator != 0) {
						
					if (gamemode != 8) {
						if (opague >= 1) {
							show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
						} else {
							show_field (Sf, m, n, gamemode, information_code, geben, Colored);
						}
					}
					
					if ((gamemode == 6)&&(((scwhp == 1)&&((opt == 0)||((use_number == 2)||(use_number == 3)||(use_number == 4)))&&((tac == 0)||((CC[2] != 0)||(CC[3] != 0)||(CC[4] != 0))))||(scwhp == 2))) {
						
						information_code[3] = 1;
						
						if (opague >= 1) {
							show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
						} else {
							show_field (Sf, m, n, gamemode, information_code, geben, Colored);
						}
					}
					
					if (gamemode == 4) {
						printf("\n");
						printf("	Points player 2: 	%u Point(s) \n", P[geben]);	// possible to modify
					}
					
					if (gamemode == 10) {
						printf("\n");
						printf("	Lifes player 3: 	%u Life(s) \n", ulcer_lifes[3]);
					}
					
					if (gamemode == 11) {
						printf("	\n");
						printf("	Geschwindigkeit: 	Zeile: %d, 	Spalte: %d \n", dynamic_pointer[2], dynamic_pointer[3]);
						printf("	Beschleunigung: 	Zeile: %d, 	Spalte: %d \n", dynamic_pointer[4], dynamic_pointer[5]);
						printf("	\n");
					}
					
					printf("\n");
					
					if (Colored[0] == 1) {
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+Colored[geben]);
					}
					
					if ((gamemode != 6)&&(gamemode != 9&&(gamemode != 10)&&(gamemode != 11))) {
						printf("	Am Zug: Spieler 2 (OO)	\n");	//possible to modify
					} else if (gamemode == 6) {
						printf("	Am Zug: Spieler 3 (BB)	\n");
					} else if (gamemode == 9) {
						if (ability[1] == geben) {
							printf("	Am Zug: Spieler 3 (UU)	\n");
						} else if (ability[2] == geben) {
							printf("	Am Zug: Spieler 3 (LL)	\n");
						} else if (ability[3] == geben) {
							printf("	Am Zug: Spieler 3 (AA)	\n");
						} else if (ability[4] == geben) {
							printf("	Am Zug: Spieler 3 (CC)	\n");
						} else if (ability[5] == geben) {
							printf("	Am Zug: Spieler 3 (II)	\n");
						} else if (ability[6] == geben) {
							printf("	Am Zug: Spieler 3 (SS)	\n");
						} else if (ability[7] == geben) {
							printf("	Am Zug: Spieler 3 (PP)	\n");
						} else if (ability[8] == geben) {
							printf("	Am Zug: Spieler 3 (HH)	\n");
						} else if (ability[9] == geben) {
							printf("	Am Zug: Spieler 3 (EE)	\n");
						}
					} else if ((gamemode == 10)||(gamemode == 11)||(gamemode == 12)) {	//mehr-gamemode
						printf("	Am Zug: Spieler 3 (33)	\n");
					}
					
					if (Colored[0] == 1) {
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+7);
					}
					
					printf("\n");
					
					if (tac != 0){
						printf("	Your stack of numbers:	\n	1) [%u],		2) [%u],		3) [%u], \n\n	4) [%u],		5) [%u],		6) [%u],\n", CC[1], CC[2], CC[3], CC[4], CC[5], CC[0]);
						printf("\n");
						printf("\n");
					}
					
					if (opt == 5){		//random number
						printf("	Your number: %u ", use_number);
						printf("\n");
						printf("\n");
						
					}
				
					
					printf("	1) Plus:	11	Minus: 	12 \n");
					printf("	2) Move:	21	Change: 22 \n");
					printf("	3) Destroy:	31	Revive: 32 \n");
					printf("	4) Move:	41	Boost: 	42 \n");
					if (((gamemode != 9)&&(gamemode != 10))||((gamemode == 10)&&(geben == 1))) {
						printf("	5) 4/5-new:	51	2-new:	52 \n");
						printf("	6) 4-max:	61	1-min:	62 \n");
					} else if (gamemode == 9) {
						if (information_code[0] == 1) {
							printf("	5) 2/3-new:	51	0-new:	52 \n");
							printf("	6) 2-max:	61	-1-min:	62 \n");
						} else if (information_code[0] == 2) {
							printf("	5) 3/4-new:	51	1-new:	52 \n");
							printf("	6) 3-max:	61	0-min:	62 \n");
						} else if (information_code[0] == 3) {
							printf("	5) 5/6-new:	51	3-new:	52 \n");
							printf("	6) 5-max:	61	0-min:	62 \n");
						} else {
							printf("	5) 4/5-new:	51	2-new:	52 \n");
							printf("	6) 4-max:	61	1-min:	62 \n");
						}
					} else if ((gamemode == 10)&&(geben != 1)) {
						printf("	5) 3/4-new:	51	1-new:	52 \n");
						printf("	6) 3-max:	61	0-min:	62 \n");
					}
					printf("							\n");
					printf("		Go back: 100 \n");
					printf("		Menu: 10 \n");
					printf("		End game: 0 \n");
					if ((ttt != 0)&&(time_saver == 0.0)) {
						time1 = time(NULL);
					}
					scanf("%u", &var_[3]);
					
					if (var_[3] == 10){
						if (ttt != 0) {
							time3 = time(NULL);
						}
						while (menuoperator != 7) {
							printf("\n");
							printf("\n");
							printf("	About the game: 1 \n	Statistics: 2 \n	The numbers: 3 \n	The limits: 4 \n	Get Hints: 5 \n	Suprise: 6 \n	Quit Menu: 7 \n");
							scanf("%u", &menuoperator);
							
							if (menuoperator == 1){
								if (gamemode == 1) {
									printf("	How to win? 	Own a square on your last line or force your opponent to lose all his/her ones.\n");
								} else if (gamemode == 2) {
									printf("	How to win? 	Be at 2 of the 3 targets with three of your squares near-by.\n");
								} else if (gamemode == 3) {
									printf("	How to win? 	Take over all your opponent's squares by winning contact-battles.\n");
									printf("	Contact-battles? 	All near-by squares in a row with the contact-square build a chain, beat your opponent in the length.\n");
								} else if (gamemode == 4) {
									printf("	How to win? 	Get more points than your opponent.\n");
									printf("	Note:	Touch the #-square in the near-by to move it to the opposite side. \n");
								} else if (gamemode == 5) {
									printf("	How to win? 	Force your opponent to lose all his/her squares.\n");
								} else if (gamemode == 6) {
									if (geben == 1) {
										printf("	How to win? 	Protect your heart-block so no enemy can touch it.\n");
									} else {
										printf("	How to win? 	Catch the heart-block of the hunted one before it disappears.\n");
									}
								} else if (gamemode == 7) {
									printf("	How to win? 	Reach the end of the field or force your opponent to lose all his/her ones.\n");
									printf("	Note:	Every %u turns in total the #-line will go ahead and destroys everything in it's way.\n Also you are not allowed to cross the mid-line. \n", freq);
								} else if (gamemode == 8) {
									printf("	How to win? 	Reach [1][7] of the field or force your opponent to lose all his/her squares.\n");
									printf("	Note:	Falling down the #-squares will push, destroy, explode, or teleport, transform into yours by contact. \n");
								} else if ((gamemode == 9)||(gamemode == 10)) {
									printf("	How to win? 	Force your opponent to lose all his/her squares while keeping yours alive.\n");
								} else if (gamemode == 11) {
									printf("	How to win? 	Push the ball against your opponent's side.\n");
								} else if (gamemode == 12) {	//mehr-gamemode
									printf("	How to win? 	Stay alive.\n");
								}
								printf("	Surrounding:	The 8 squares around another, at the edge 5, in the corners 3, are called #surrounding. \n");
								printf("	near-by:	The 4 squares around another, at the edge 3, in the corners 2, are called #near-by. \n");
								printf("	Standard actions:	(After your choice of number and not influencing each other) \n	-Development:	If it is your turn and a free square has exactly 3 of yours surrounding it, you will own it.\n");
								printf("	-Losses: 	If it is your turn and a square of yours is surrounded by less than %u or more than %u of yours,\n			it will be set free.\n", d, e);
								if ((gamemode == 10)||(gamemode == 12)) {	//mehr-gamemode
									printf("	Limits: 	This gamemode is unlimited. \n");
								} else if (gamemode == 3) {
									printf("	Limits: 	Your development is limited by %u per round. \n", limit_new);
								} else {
									printf("	Limits: 	Your development is limited by %u per round, your units in total by %u per round. \n", limit_new, limit_at_all);
								}
							}
							
							if (menuoperator == 2){
								printf("\n");
								printf("	turns at all: %u \n", g);
								printf("\n");
								printf("	Numbers of player 1: \n");
								printf("		#1 = %u \n", A[1]);
								printf("		#2 = %u \n", A[2]);
								printf("		#3 = %u \n", A[3]);
								printf("		#4 = %u \n", A[4]);
								printf("		#5 = %u \n", A[5]);
								printf("		#6 = %u \n", A[6]);
								printf("\n");
								if (number_of_players >= 2) {	//mehr-gamemode
									printf("	Numbers of player 2: \n");
									printf("		#1 = %u \n", B[1]);
									printf("		#2 = %u \n", B[2]);
									printf("		#3 = %u \n", B[3]);
									printf("		#4 = %u \n", B[4]);
									printf("		#5 = %u \n", B[5]);
									printf("		#6 = %u \n", B[6]);
									printf("\n");
								}
								
								if (number_of_players >= 3){	//mehr-gamemode
									printf("	Numbers of player 3: \n");
									printf("		#1 = %u \n", AA[1]);
									printf("		#2 = %u \n", AA[2]);
									printf("		#3 = %u \n", AA[3]);
									printf("		#4 = %u \n", AA[4]);
									printf("		#5 = %u \n", AA[5]);
									printf("		#6 = %u \n", AA[6]);
									printf("\n");
								}
								if (number_of_players >= 4){
									printf("	Numbers of player 4: \n");
									printf("		#1 = %u \n", BB[1]);
									printf("		#2 = %u \n", BB[2]);
									printf("		#3 = %u \n", BB[3]);
									printf("		#4 = %u \n", BB[4]);
									printf("		#5 = %u \n", BB[5]);
									printf("		#6 = %u \n", BB[6]);
									printf("\n");
								}
								if (number_of_players >= 5){
									printf("	Numbers of player 5: \n");
									printf("		#1 = %u \n", AAA[1]);
									printf("		#2 = %u \n", AAA[2]);
									printf("		#3 = %u \n", AAA[3]);
									printf("		#4 = %u \n", AAA[4]);
									printf("		#5 = %u \n", AAA[5]);
									printf("		#6 = %u \n", AAA[6]);
									printf("\n");
								}
								if (number_of_players >= 6){
									printf("	Numbers of player 6: \n");
									printf("		#1 = %u \n", BBB[1]);
									printf("		#2 = %u \n", BBB[2]);
									printf("		#3 = %u \n", BBB[3]);
									printf("		#4 = %u \n", BBB[4]);
									printf("		#5 = %u \n", BBB[5]);
									printf("		#6 = %u \n", BBB[6]);
									printf("\n");
								}
								if (number_of_players >= 7){
									printf("	Numbers of player 7: \n");
									printf("		#1 = %u \n", AAAA[1]);
									printf("		#2 = %u \n", AAAA[2]);
									printf("		#3 = %u \n", AAAA[3]);
									printf("		#4 = %u \n", AAAA[4]);
									printf("		#5 = %u \n", AAAA[5]);
									printf("		#6 = %u \n", AAAA[6]);
									printf("\n");
								}
								if (number_of_players >= 8){
									printf("	Numbers of player 8: \n");
									printf("		#1 = %u \n", BBBB[1]);
									printf("		#2 = %u \n", BBBB[2]);
									printf("		#3 = %u \n", BBBB[3]);
									printf("		#4 = %u \n", BBBB[4]);
									printf("		#5 = %u \n", BBBB[5]);
									printf("		#6 = %u \n", BBBB[6]);
									printf("\n");
								}
								if (number_of_players == 9){
									printf("	Numbers of player 9: \n");
									printf("		#1 = %u \n", AAAAA[1]);
									printf("		#2 = %u \n", AAAAA[2]);
									printf("		#3 = %u \n", AAAAA[3]);
									printf("		#4 = %u \n", AAAAA[4]);
									printf("		#5 = %u \n", AAAAA[5]);
									printf("		#6 = %u \n", AAAAA[6]);
									printf("\n");
								}
								
								if ((gamemode == 1)||(gamemode == 6)||(gamemode == 7)||(gamemode == 8)) {
									printf("	Matchballs player 1: 	%u \n", A[0]);
									printf("	Matchballs player 2: 	%u \n", B[0]);
									if (gamemode == 6) {
										if (number_of_players >= 3){printf("	Matchballs player 3: 	%u \n", AA[0]);}
										if (number_of_players >= 4){printf("	Matchballs player 4: 	%u \n", BB[0]);}
										if (number_of_players >= 5){printf("	Matchballs player 5: 	%u \n", AAA[0]);}
										if (number_of_players >= 6){printf("	Matchballs player 6: 	%u \n", BBB[0]);}
										if (number_of_players >= 7){printf("	Matchballs player 7: 	%u \n", AAAA[0]);}
										if (number_of_players >= 8){printf("	Matchballs player 8: 	%u \n", BBBB[0]);}
										if (number_of_players == 9){printf("	Matchballs player 9: 	%u \n", AAAAA[0]);}
									}
								} else if (gamemode == 2) {
									printf("	Squares collected by player 1: 	%u \n", A[0]);
									printf("	Squares collected by player 2: 	%u \n", B[0]);
								} else if (gamemode == 3) {
									printf("	Times with squares <= 5, player 1: 	%u \n", A[0]);
									printf("	Times with squares <= 5, player 2: 	%u \n", B[0]);
								} else if (gamemode == 4) {
									printf("	Points player 1: 		%u \n", P[1]);
									printf("	Points Player 2: 		%u \n", P[2]);
									printf("	Turns with more points player 1: 	%u \n", A[0]);
									printf("	Turns with more points player 2: 	%u \n", B[0]);
									printf("	Number of not decided #-squares: 	%u \n", P[0]);
								} else if (gamemode == 3) {
									printf("	Times with squares < 5, player 1: 	%u \n", A[0]);
									printf("	Times with squares < 5, player 2: 	%u \n", B[0]);
								} else if (gamemode == 9) {
									printf("	Number of excluded abilites: 	%u \n", exclude_counter);
									printf("	Offensive abilities taken: 	%u \n", number_of_players-ability[0]);
									printf("	Defensive abilities taken: 	%u \n", ability[0]);
								} else if (gamemode == 10) {
									for (unsigned int p=1; p<=number_of_players; p+=1) {
										printf("		Spieler %u: %u life(s) left.\n", p, ulcer_lifes[p]);
									}
								} else if (gamemode == 11) {	//mehr-gamemode
									for (unsigned int p=1; p<=number_of_players; p+=1) {
										if ((ges[p] > 1000)||(ges[p] == 0)) {
											printf("	Spieler %u: is out.\n", p);
										} else if (ges[p] < 1000) {
											printf("	Spieler %u: You own %u squares.\n", p, ges[p]);
										}
									}
								} else if (gamemode == 12) {
									for (unsigned int p=1; p<=number_of_players; p+=1) {
										if ((ges[p] > 1000)||(ges[p] == 0)) {
											printf("	Spieler %u: is out.\n", p);
										} else if (ges[p] < 1000) {
											printf("	Spieler %u: You own %u squares.\n", p, ges[p]);
										}
									}
								}
								
								if (ttt != 0) {
									printf("	Number of penalties given until	now: %u \n", pere[0]);
								}
							}
							
							if (menuoperator == 3){
								if ((gamemode != 10)&&(gamemode != 12)) {
									printf("	Plus: Change a free square in the surrounding of yours in one of yours.\n");
								} else {
									printf("	Plus: Change a square in the surrounding of yours in one of yours.\n");
								}
								printf("	Minus: Delete one of your squares.\n");
								printf("	Move: The position of one of yours will change with a free, near-by square.\n");
								printf("	Revive: Your lost squares having no living squares of yours surrounding them at the beginning of your turn,\n		will be revived.\n");
								printf("	%u/%u-new: A free square has to be surrounded by %u or %u of yours during the development.\n", w+1, w+2, w+1, w+2);
								printf("	%u-new: A free square has to be surrounded by %u of yours during the development.\n", d, d);
								printf("	%u-max: A square of yours will survive even by %u of your squares surrounding it.\n", e+1, e+1);
								if (d == 0) {
									printf("	-1-min: A square of yours will survive even by only -1 of your squares surrounding it.\n");
								} else {
									printf("	%u-min: A square of yours will survive even by only %u of your squares surrounding it.\n", d-1, d-1);
								}
								
								if ((gamemode == 1)||(gamemode == 2)||(gamemode == 4)||(gamemode == 5)||(gamemode == 7)||(gamemode == 9)||(gamemode == 10)) {
									printf("	Change: A square of yours and a near-by square of your enemy will change positions.\n");
									printf("	Destroy: Delete a near-by square of your enemy.\n");
									printf("	Boost: Use all near-by squares of your enemy as your own for the development.\n");
									
								} else if (gamemode == 3) {
									
									printf("	Change: A square of yours and a square of your enemy in the surrounding will change positions.\n");
									printf("	Destroy: Delete a surrounding square of your enemy.\n");
									printf("	Boost: Use all surrounding squares of your enemy as your own for the development.\n");
									
								} else if (gamemode == 8) {
									printf("	Change: A square of yours and a near-by #-square will change positions.\n");
									printf("	Destroy: Delete a square of your enemy, but not in the last two lines.\n");
									printf("	Boost: Use all near-by #-squares as your own for the development.\n");
									
								} else if (gamemode == 6) {
									if (geben == 1) {
										printf("	Change: The heart-block and a square of yours will change positions.\n");
										printf("	Destroy: Delete a square of your enemy.\n");
										printf("	Boost: Touching the heart_block no square of yours can die.\n");
									} else {
										printf("	Change: A square of yours and a near-by square of the hunted one will change positions.\n");
										printf("	Destroy: Delete a near-by square of your enemy.\n");
										printf("	Boost: Use all near-by squares of the hunted one as your own for the development.\n");
									}
									
								} else if (gamemode == 11) {	//mehr-gamemode
									printf("	Change: A square of yours and a near-by square of your enemy or the near-by ball will change positions.\n");
									printf("	Destroy: Delete a near-by square of your enemy.\n");
									printf("	Boost: Use all near-by squares of your enemy and the near-by ball as your own for the development.\n");
								} else if (gamemode == 12) {
									printf("	Change: A square of yours and a near-by square of your enemy or a near-by object will change positions.\n");
									printf("	Destroy: Delete a near-by square of your enemy or a near-by object.\n");
									printf("	Boost: Use all near-by squares of your enemy and near-by objects as your own for the development.\n");
								}
								
								printf("\n");
							}
							
							if (menuoperator == 4){	//mehr-gamemode
								if ((gamemode != 10)&&(gamemode != 12)) {
									printf("	Limit of development:	%u \n", limit_new);
									if (gamemode != 3) {
										printf("	Limit in total:		%u \n", limit_at_all);
										printf("	Limit in total with >2-new< taken: %u -0/-1/-2/-3/-4.\n", limit_at_all);
									}
								}
							}
							
							if (menuoperator == 5){
								Spielfeld hint;
								unsigned int b, a;
								hint = Spielfeld_Create (m, n);
								printf("	New: 1 \n	Dying: 2 \n	Both: 3 \n");
								scanf("%u", &menuoperator);
								
								for (unsigned int i=1; i<(m-1); i+=1){
									for (unsigned int j=1; j<(n-1); j+=1){
										if ((gamemode != 6)&&(gamemode != 9)&&(gamemode != 10)&&(gamemode != 11)&&(gamemode != 12)){	//mehr-gamemode
											if (Sf[i][j] == geben){
												hint[i][j] = geben;
											} else if (Sf[i][j] == (geben%2)+1){
												hint[i][j] = (geben%2)+1;
											} else if (Sf[i][j] == 7){
												hint[i][j] = 7;
											} 
										} else if ((gamemode == 6)||(gamemode == 9)||(gamemode == 10)) {	//10
											if (Sf[i][j] == geben){
												hint[i][j] = geben;
											} else if (Sf[i][j] != 0){
												hint[i][j] = 17;
											}
										} else if (gamemode == 11) {
											if (Sf[i][j] == geben){
												hint[i][j] = geben;
											} else if (Sf[i][j] == 77){
												hint[i][j] = 77;
											} else if (Sf[i][j] != 0){
												hint[i][j] = 17;
											}
										} else if (gamemode == 12) {	//mehr-gamemode
											if (Sf[i][j] == geben){
												hint[i][j] = geben;
											} else if (Sf[i][j] == 81){
												hint[i][j] = 81;
											} else if (Sf[i][j] == 82){
												hint[i][j] = 82;
											} else if (Sf[i][j] == 83){
												hint[i][j] = 83;
											} else if (Sf[i][j] == 84){
												hint[i][j] = 84;
											} else if (Sf[i][j] == 75){
												hint[i][j] = 75;
											} else if (Sf[i][j] == 71){
												hint[i][j] = 71;
											} else if (Sf[i][j] != 0){
												hint[i][j] = 17;
											}
										}
									}
								}
								
								if ((menuoperator == 2)||(menuoperator == 3)){
									for (unsigned int i=1; i<(m-1); i+=1){
										for (unsigned int j=1; j<(n-1); j+=1){
											if (Sf[i][j] == geben){
												a = 0;
												for (unsigned int h=(i-1); h<=(i+1); h+=1){
													for (unsigned int k=(j-1); k<=(j+1); k+=1){
														if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
															if (Sf[h][k] == geben){
																a += 1;
															}
														}
													}
												}
												if ((a > 4) || (a < 3)){
													hint[i][j] = 16;
												}
											}
										}
									}
								}
								
								if ((menuoperator == 1)||(menuoperator == 3)){
									for (unsigned int i=1; i<(m-1); i+=1){
										for (unsigned int j=1; j<(n-1); j+=1){
											if (Sf[i][j] == 0){
												b = 0;
												for (unsigned int h=(i-1); h<=(i+1); h+=1){
													for (unsigned int k=(j-1); k<=(j+1); k+=1){
														if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
															if (Sf[h][k] == geben){
																b += 1;
															}
														}
													}
												}
												if (b == 3){
													hint[i][j] = 15;
												}
											}
										}
									}
								}
						
								if (opague >= 1) {
									Sf_opague = opague_builder (hint, m, n, geben, opague, aop);
								}
								
								if (opague >= 1) {
									show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
								} else {
									show_field (hint, m, n, gamemode, information_code, geben, Colored);
								}
								
								if (opague >= 1) {
									Sf_opague = opague_builder (Sf, m, n, geben, opague, aop);
								}
								menuoperator = 1;
								Spielfeld_Destroy (hint, m);
							}
							// 2
							if (menuoperator == 6){
								if (suprise == 0) {
									for (unsigned int i=1; i<m-1; i+=1){
										for (unsigned int j=1; j<n-1; j+=1){
											cons_field_3[i][j] = Sf[i][j];
											
											if (journey == 1){
												cons_journey_3[i][j] = Sf_journey[i][j];
											}
										}
									}
									sup_num = use_number;
								}
								
								while (menuoperator != 1) {
						
									printf("	Creator menu. 	Change number: 1	Suprise: 2	Suprise undo: 3	Back: 4 \n");
									scanf ("%u", &lim);
									if (lim == 1){
										printf("	number = ? \n");
										scanf ("%u", &use_number);
									} else if (lim == 2){
								
										printf("\n");
										scanf("%u", &suprise);
								
										if (suprise == 31){
											for (unsigned int i=2; i<m-2; i+=1){
												for (unsigned int j=1; j<n-1; j+=1){
													if (Sf[i][j] != 0){
														if (Sf[i][j] == 1){
															Sf[i][j] = 3;
														} else if (Sf[i][j] == 3){
															Sf[i][j] = 1;
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
								
										if(suprise == 13){
											for (unsigned int i=1; i<m-1; i+=1){
												for (unsigned int j=1; j<n-1; j+=1){
													if (Sf[i][j] == 3){
														Sf[i][j] = 0;
													}
													if (i == (m-2)){
														Sf[m-2][j] = 3;
													}
												}
											}
										}
								
									} else if (lim == 3){
										for (unsigned int i=1; i<m-1; i+=1){
											for (unsigned int j=1; j<n-1; j+=1){
												Sf[i][j] = cons_field_3[i][j];
												
												if (journey == 1){
													Sf_journey[i][j] = cons_journey_3[i][j];
												}
											}
										}
										use_number = sup_num;
									} else if (lim == 4){
										menuoperator = 1;
									} else {
										printf("	Invalid comment");
									}
								}
							}
						}	// menuoperator = 7
						
						if (gamemode == 8) {
							if (opague >= 1) {
								show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
							} else {
								show_field (Sf, m, n, gamemode, information_code, geben, Colored);
							}	//show_field über menuoperator = 7 und stack und so löschen, (verschiebe menuoperator!=0 - Schleife), done
							
							printf("\n");
						
						}
						
						if (ttt != 0) {
							time4 = time(NULL);
							time_saver += difftime(time4, time3);
						}
					}	//Menu-end
					
					menuoperator = 0;
					
					if (var_[3] == 10) {
						menuoperator = 1;
						var_[3] = 5;
					}
					
					if ((tac != 0)&&(var_[3] <= 62)&&(var_[3] > 10)){
						unsigned int tac_controll;
						tac_controll = 0;
						if (((var_[3]%10) > 2)||((var_[3]%10) == 0)){
							var_[3] = 7;
							menuoperator = 1;
						} else {
							for (unsigned int z=var_[3]; z>2; z-=10){
								tac_controll += 1;
							}
							if (tac_controll == 6){
								tac_controll = 0;
							}
							if (CC[tac_controll] == 0){
								var_[3] = 7;
								menuoperator = 1;
							} else {
								CC[tac_controll] -= 1;
							}
						}
					} else if ((tac != 0)&&(var_[3] != 100)&&(var_[3] != 1010)&&(var_[3] != 0)) {
						var_[3] = 7;
					}		
					//tac-mode
					
					if (opt == 5){
						controll_1 = 10+use_number;
						controll_2 = 11+use_number;
					
						for (unsigned int i=0; i<use_number-1; i+=1){
							controll_1 += 9;
							controll_2 += 9;
						}
					
						if (var_[3] == 0){
							controll_1 = 0;
							controll_2 = 0;
						}
						if (var_[3] == 100){
							controll_1 = 100;
							controll_2 = 100;
						}
						if (var_[3] == 1010){
							controll_1 = 1010;
							controll_2 = 1010;
						}
					}
					//
					if (((var_[3] > 0)&&(var_[3] < 10))||(((opt == 5)&&(var_[3] != controll_1))&&((opt == 5)&&(var_[3] != controll_2)))){
						
						if (var_[3] != 5) {
							printf("	You made a mistake, try again: \n");
							printf("\n");
							printf("\n");
						} else {
							printf("	You closed the menu. \n");
							printf("\n");
							printf("\n");
						}
						
						//enough
						
						menuoperator = 1;
					}
					
				}		// menuoperator = 0
				
				//printf("ok 1 \n");
				
				suprise = 0;
				
				if (var_[3] == 0){
					printf("	Do you really want to end the game ? \n");
					printf("	Yes: 0		No: 1 \n");
					scanf("%u", &lim);
					if (lim == 0){
						break;
					} else if (lim == 1){
						continue;
					} else {
						printf("	0 or 1, it is so difficult to understand? \n");
						printf("	Well, it seems I have to end it by myself... \n");
						break;
					}	
				} else {
					
					//printf("ok 1.1 \n");
					
					if (var_[3] == 100){		//gamemode 6 modify, done
						
						var_[0] = 1;
						
						for (unsigned int i=1; i<m-1; i+=1){
							for (unsigned int j=1; j<n-1; j+=1){
								Sf[i][j] = cons_field_2[i][j];
								
								if (journey == 1){
									Sf_journey[i][j] = cons_journey_2[i][j];
								}
							}
						}
						
						if (opague >= 1) {
							Sf_opague = opague_builder (Sf, m, n, geben, opague, aop);
						}
						
						if (opague >= 1) {
							show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
						} else {
							show_field (Sf, m, n, gamemode, information_code, geben, Colored);
						}
						
						cons[geben] = use_number;
						
						use_number = cons[2];
						
						if (gamemode == 11) {	//mehr-gamemode
							for (unsigned int p=2; p<=5; p+=1) {
								
								dynamic_pointer[p] = dynamic_pointer_save[2][p-2];
								
							}
						}
						
						g-=1;
						var_[3] = 1010;
						if (gamemode == 10) {
							ulcer_lifes[3] += 1;
							ulcer_start[3] = 0;
						}
						continue;
					} else {
						
						//printf("ok 1.2 \n");
						
						if (number_of_players == 3) {
							
							
							//printf("ok 1.3 a\n");
							
							if (var_[1] != 1010){
								
								//printf("ok 1.4 a\n");
								
								for (unsigned int i=1; i<m-1; i+=1){
									for (unsigned int j=1; j<n-1; j+=1){
										cons_field_3[i][j] = Sf[i][j];
										
										if (journey == 1){
											cons_journey_3[i][j] = Sf_journey[i][j];
										}
									}
								}
								
								//printf("ok 1.5 a\n");
								
							}
						} else if (number_of_players >= 4) {
							if (var_[4] != 1010){
								for (unsigned int i=1; i<m-1; i+=1){
									for (unsigned int j=1; j<n-1; j+=1){
										cons_field_3[i][j] = Sf[i][j];
										
										if (journey == 1){
											cons_journey_3[i][j] = Sf_journey[i][j];
										}
									}
								}
							}
						}
						
						//printf("ok 2 \n");
						
						var_[0] = 0;
						
						if (var_[3] < 50){
							
							if (var_[3] == 11){AA[1] += 1; Plus (m, n, geben, Sf, limit_at_all, gamemode, information_code, number_of_players, Colored, opague, Sf_opague);}
							if (var_[3] == 12){AA[1] += 1; Minus (m, n, geben, Sf, gamemode, information_code, Colored, opague, Sf_opague);}
							if (var_[3] == 21){AA[2] += 1; Move (m, n, geben, Sf, gamemode, information_code, Colored, opague, Sf_opague);}
							if (var_[3] == 41){AA[4] += 1; Move (m, n, geben, Sf, gamemode, information_code, Colored, opague, Sf_opague);}
							if (var_[3] == 22){AA[2] += 1; Change (m, n, geben, Sf, gamemode, information_code, Colored, opague, Sf_opague, position);}
							if (var_[3] == 31){AA[3] += 1; Destroy (m, n, geben, Sf, gamemode, information_code, Colored, opague, Sf_opague);}
							if (var_[3] == 42){
								AA[4] += 1; 
								Boost (geben, Sf, m, n, temp, gamemode);
							}
						} else {
							if (var_[3] == 51){AA[5] += 1; w += 1;}		//w
							if (var_[3] == 52){AA[5] += 1; w -= 1;}		//w
							if (var_[3] == 61){AA[6] += 1; e += 1;}		//e
							if (var_[3] == 62){AA[6] += 1; if (d != 0) {d -= 1;} else {d = 10;}}		//d
						}		//printf("ok(6186)");
						
						if (ttt != 0) {
							time2 = time(NULL);
							time_warning = ((difftime(time2, time1)) - time_saver);
							
							//printf("	time_warning: %f \n", time_warning);		//test
							
							if ((pere[geben] != 0)&&((pere[geben] + warning_system) <= 6)) {
								if (pere[geben] == 1) {
									if (warning_system <= 2) {
										time_warning += 1.0;
									} else if (warning_system == 3) {
										time_warning += 2.0;
									} else if (warning_system == 4) {
										time_warning += 3.0;
									} else if (warning_system == 5) {
										time_warning += 5.0;
									}
								} else if (pere[geben] == 2) {
									if (warning_system == 1) {
										time_warning += 2.0;
									} else if (warning_system == 2) {
										time_warning += 3.0;
									} else if (warning_system == 3) {
										time_warning += 5.0;
									} else if (warning_system == 4) {
										time_warning += 6.0;
									}
								} else if (pere[geben] == 3) {
									if (warning_system == 1) {
										time_warning += 3.0;
									} else if (warning_system == 2) {
										time_warning += 5.0;
									} else if (warning_system == 3) {
										time_warning += 8.0;
									}
								} else if (pere[geben] == 4) {
									if (warning_system == 1) {
										time_warning += 4.0;
									} else if (warning_system == 2) {
										time_warning += 7.0;
									}
								} else if (pere[geben] == 5) {
									if (warning_system == 1) {
										time_warning += 5.0;
									}
								}
							}
							
							if (time_warning > (1.0*ttt)) {
								pere[0] += 1;
								printf("	You took too much time! %f sec more than you should. \n", (time_warning-1.0*ttt) );
								printf(" \n");
								for (unsigned int p=16; p>=1; p-=3) {	//index_verschiebung
									if ((time_warning-1.0*ttt) > 1.0*(p-1)) {
										pere[geben] = (((p-1)/3) + 1);
										break;
									}
								}
							} else {
								pere[geben] = 0;
							}
						}
				
						Sf_nl_3 = new_life_3 (Sf, m, n, w, gamemode, information_code);		//printf("ok(6258)");
						
						if (gamemode == 6) {
							
							precounter = 0;
							for (unsigned int i=1; i<m-1; i+=1){
								for (unsigned int j=1; j<n-1; j+=1){
									if (Sf[i][j] == 11){
										if (Sf_nl_3[i][j-1] > 1) {
											printf (" Sieg: Spieler %u \n", Sf_nl_3[i][j-1]);
											precounter += 1;
										}
										if (Sf_nl_3[i][j+1] > 1) {
											if (precounter == 0) {
												printf (" Sieg: Spieler %u \n", Sf_nl_3[i][j+1]);
											}
											precounter += 1;
										}
										if (Sf_nl_3[i-1][j] > 1) {
											if (precounter == 0) {
												printf (" Sieg: Spieler %u \n", Sf_nl_3[i-1][j]);
											}
											precounter += 1;
										}
										if (Sf_nl_3[i+1][j] > 1) {
											if (precounter == 0) {
												printf (" Sieg: Spieler %u \n", Sf_nl_3[i+1][j]);
											}
											precounter += 1;
										}
										if (precounter == 2) {
											printf(" Double-catch! \n");
										}
										if (precounter == 3) {
											printf(" TRIPLE-catch!! \n");
										}
										if (precounter == 4) {
											printf(" QUADRO-CATCH!!! \n");
										}
										break;
									}
								}
								if (precounter > 0) {
									break;
								}
							}
							if (precounter > 0) {
								for (unsigned int i=1; i<m-1; i+=1){
									for (unsigned int j=1; j<n-1; j+=1){
										if (Sf_nl_3[i][j] == geben) {
											Sf[i][j] = geben;
										}
									}
								}
								show_field (Sf, m, n, gamemode, information_code, geben, Colored);
								break;
							}
						}
						controll = 0;
						if (gamemode == 7) {
							for (unsigned int i=(m-2); i>=(m-1)/2; i-=1){		//Spiel-Ende?
								if ((Sf_nl_3[i][n-2] == 3)||(Sf[i][n-2] == 3)){
									for (unsigned int k=(m-2); k>=1; k-=1){
										if (Sf_nl_3[k][n-2] == 3){
											Sf[k][n-2] = 3;
										}
									}
									show_field (Sf, m, n, gamemode, information_code, geben, Colored);
									printf("	Sieg:	Spieler 3 \n");
									controll = 1;
								}
							}
							if (controll == 1){
								break;
							}
						}	// possible to modify
						controll = 0;
						
						num_1 = 0;
						for (unsigned int i=1; i<m-1; i+=1){
							for (unsigned int j=1; j<n-1; j+=1){
								if (Sf_nl_3[i][j] == 3){
									num_1 += 1;
								}
							}
						}		//printf("ok(1387)");	
					
						if (var_[3] == 42){
							for (unsigned int i=1; i<m-1; i+=1){
								for (unsigned int j=1; j<n-1; j+=1){
									if (gamemode == 8) {
										if (temp[i][j] == 3){
											Sf[i][j] = 0;
										}
									} else if ((gamemode == 9)||(gamemode == 10)||(gamemode == 11)||(gamemode == 12)) {	//mehr-gamemode
										if (temp[i][j] != 0){
											Sf[i][j] = temp[i][j];
										}
									} else if (gamemode == 6) {	//10
										if (temp[i][j] == 3){
											Sf[i][j] = 1;
										}
									}
								}
							}
						}		//printf("ok(1398)");	
						// possible to modify
						
						controll = 0;
						
						if (gamemode == 1){	// possible to modify
							for (unsigned int erste=1; erste<n-1; erste+=1){		//printf("ok(1400)");		//Spiel-Ende?
								if (Sf[1][erste] == 3){
									printf("	Sieg:	Spieler 3 \n");
									show_field (Sf, m, n, gamemode, information_code, geben, Colored);
									controll = 1;		//printf("ok(1404)");
									break;
								}
							}
							if (controll == 1){
								break;		//printf("ok(1409)");
							}		//printf("ok(1410)");
						}
						controll = 0;
						
						Spielfeld_Destroy (temp, m);		//printf("ok(1412)");
					
						Sf_od_3 = old_dying_3 (Sf, m, n, d, e, gamemode, information_code);		//printf("ok6383");
						
						if (journey == 1){
							unsigned int journey_max;
							journey_max = 0;
							for (unsigned int i=1; i<m-1; i+=1){
								for (unsigned int j=1; j<n-1; j+=1){
									if (Sf_journey[i][j] == 3){
										journey_max += 1;
									}
								}
							}
							for (unsigned int i=1; i<m-1; i+=1){
								for (unsigned int j=1; j<n-1; j+=1){
									if ((Sf_od_3[i][j] == 303) && (Sf_journey[i][j] == 0) && (journey_max >= limit_at_all)){
										for (unsigned int u=(m-2); u>0; u-=1){
											for (unsigned int o=1; o<(n-1); o+=1){
												if ((Sf_journey[u][o] == 3)&&((u+o)%2 == 0)){
													Sf_journey[u][o] = 0;
													journey_max -= 1;
													if (journey_max < limit_at_all){
														break;
													}
												}
											}
											if (journey_max < limit_at_all){
												break;
											}
										}
										
									}
									if ((Sf_od_3[i][j] == 303) && (Sf_journey[i][j] == 0) && (journey_max < limit_at_all)){
										Sf_journey[i][j] = 3;
										journey_max += 1;
									}
								}
							}
							journey_max = 0;
						}
						
						if (var_[3] == 32){AA[3] += 1; Revive_3(m, n, Sf_od_3, Sf);}
						
						num_2 = 0;
						for (unsigned int i=1; i<m-1; i+=1){
							for (unsigned int j=1; j<n-1; j+=1){
								if (Sf_od_3[i][j] == 303){
									num_2 += 1;
								}
							}
						}
					
						count_new = 0;
						for (unsigned int i=1; i<m-1; i+=1){
							for (unsigned int j=1; j<n-1; j+=1){
								if (Sf_nl_3[i][j] == 3){
									count_new += 1;
								}
							}
						}
						ent = limit_new;		//printf("ok(1473)");
						
						for (unsigned int i=1; i<m-1; i+=1){
							for (unsigned int j=1; j<n-1; j+=1){
								if ((Sf[i][j] == 3) && (Sf_od_3[i][j] == 0)){
									zeitgewinner += 1;
								}
							}
						}
						
						if (count_new > limit_new){		//Abfrage auf max. 10 neue Steine
							/*if (gamemode == 1) {
								Sf_nl_3 = Index_3 (ent, count_new, m, n, Sf, Sf_nl_3, Sf_od_3, limit_new, limit_at_all, zeitgewinner);	
							} else if (gamemode == 2) {
								Sf_nl_3 = Index_3_col (ent, count_new, m, n, Sf, Sf_nl_3, Sf_od_3, limit_new, limit_at_all, zeitgewinner);	
							} else if (gamemode == 3) {
								Sf_nl_3 = Index_3_con (ent, count_new, m, n, Sf, Sf_nl_3, limit_new);
							} else if (gamemode == 4) {
								Sf_nl_3 = Index_3_fal (ent, count_new, m, n, Sf, Sf_nl_3, Sf_od_3, limit_new, limit_at_all, zeitgewinner);	
							} else if (gamemode == 5) {
								Sf_nl_3 = Index_3_fig (ent, count_new, m, n, Sf, Sf_nl_3, Sf_od_3, limit_new, limit_at_all, zeitgewinner);	
							} else if (gamemode == 7) {
								Sf_nl_3 = Index_3_race (ent, count_new, m, n, Sf, Sf_nl_3, Sf_od_3, limit_new, limit_at_all, zeitgewinner);	
							} else if (gamemode == 8) {
								Sf_nl_3 = Index_3_rain (ent, count_new, m, n, Sf, Sf_nl_3, Sf_od_3, limit_new, limit_at_all, rain, zeitgewinner);	
							}*/
							if (gamemode == 6) {
								Sf_nl_3 = Index_other_hunt (ent, count_new, m, n, Sf_nl_3, geben, zeitgewinner, Sf, limit_at_all);	
							} else if (gamemode == 9) {
								Sf_nl_3 = Index_are (ent, count_new, m, n, Sf_nl_3, Sf_od_3, limit_new, limit_at_all, zeitgewinner, Sf, w, d, e, geben);
							} else if (gamemode == 10) {
								count_new = 0;
							} else if (gamemode == 11) {
								Sf_nl_3 = Index_dyn (ent, count_new, m, n, Sf_nl_3, Sf_od_3, limit_new, limit_at_all, zeitgewinner, Sf, w, d, e, geben, position);
							} else if (gamemode == 12) {	//mehr-gamemode
								count_new = 0;
							}
						
						}
						ent = 0;
						count_new = 0;		//printf("ok(1478)");
					
						num_3 = 0;
						for (unsigned int i=1; i<m-1; i+=1){
							for (unsigned int j=1; j<n-1; j+=1){
								if (((Sf[i][j] == 3) && (Sf_od_3[i][j] == 0)) || (Sf_nl_3[i][j] == 3)){
									count_new += 1;
									num_3 += 1;
								}
							}
						}
						
						ent = limit_at_all;
						if ((gamemode == 1)||(gamemode == 2)||(gamemode == 4)||(gamemode == 5)||(gamemode == 7)||(gamemode == 8)) {
							
							if (var_[3] == 52){
											//printf("ok(1492)");
								lim = 0;
								for (unsigned int i=1; i<m-1; i+=1){
									for (unsigned int j=1; j<n-1; j+=1){
										if ((Sf[i][j] == 3) && (Sf_od_3[i][j] == 0)){
											lim += 1;
										}
									}
								}
											//printf("ok(1501)");
								ent = lim;
											//printf("ok(1503)");
								lim = 0;
								for (unsigned int i=1; i<m-1; i+=1){
									for (unsigned int j=1; j<n-1; j+=1){
										if (Sf[i][j] == 1){
											lim += 1;
										}
									}
								}			//printf("ok(1511)");
							
							
								if ((lim <= limit_new) && (ent < (limit_at_all - 1))){
									if (ent >= (limit_at_all - 3)){
										ent = limit_at_all - 1;
									} else if (ent >= (limit_at_all - 5)){
										ent = limit_at_all - 2;
									} else if (ent >= (limit_at_all - 7)){
										ent = limit_at_all - 3;
									} else if (ent >= (limit_at_all - 10)){
										ent = limit_at_all - 4;
									} else {
										ent = limit_at_all;
									}		//printf("ok(1523)");
								} else {		//printf("ok(1524)");
									ent = limit_at_all;
								}
								lim = 0;
											//printf("ok(1528)");
							}
						}	// possible to modify
						
						if (count_new > ent){		//Abfrage auf insgesamt max. 20 Steine, normalerweise
							/*if (gamemode == 1) {
								Sf_nl_3 = Index_3 (ent, count_new, m, n, Sf, Sf_nl_3, Sf_od_3, limit_new, limit_at_all, zeitgewinner);	
							} else if (gamemode == 2) {
								Sf_nl_3= Index_3_col  (ent, count_new, m, n, Sf, Sf_nl_3, Sf_od_3, limit_new, limit_at_all, zeitgewinner);	
							} else if (gamemode == 3) {
								count_new = 0;
							} else if (gamemode == 4) {
								Sf_nl_3 = Index_3_fal (ent, count_new, m, n, Sf, Sf_nl_3, Sf_od_3, limit_new, limit_at_all, zeitgewinner);	
							} else if (gamemode == 5) {
								Sf_nl_3 = Index_3_fig (ent, count_new, m, n, Sf, Sf_nl_3, Sf_od_3, limit_new, limit_at_all, zeitgewinner);	
							} else if (gamemode == 7) {
								Sf_nl_3 = Index_3_race (ent, count_new, m, n, Sf, Sf_nl_3, Sf_od_3, limit_new, limit_at_all, zeitgewinner);	
							} else if (gamemode == 8) {
								Sf_nl_3 = Index_3_rain (ent, count_new, m, n, Sf, Sf_nl_3, Sf_od_3, limit_new, limit_at_all, rain, zeitgewinner);	
							}*/
							if (gamemode == 6) {
								Sf_nl_3 = Index_other_hunt (ent, count_new, m, n, Sf_nl_3, geben, zeitgewinner, Sf, limit_at_all);	
							} else if (gamemode == 9) {
								Sf_nl_3 = Index_are (ent, count_new, m, n, Sf_nl_3, Sf_od_3, limit_new, limit_at_all, zeitgewinner, Sf, w, d, e, geben);	
							} else if (gamemode == 10) {
								count_new = 0;
							} else if (gamemode == 11) {
								Sf_nl_3 = Index_dyn (ent, count_new, m, n, Sf_nl_3, Sf_od_3, limit_new, limit_at_all, zeitgewinner, Sf, w, d, e, geben, position);
							} else if (gamemode == 12) {	//mehr-gamemode
								count_new = 0;
							}
						
						}
						ent = 0;
						zeitgewinner = 0;
						
						if (gamemode == 4) {
							touch (Sf, m, n, geben, Sf_nl_1, Sf_nl_2);	//possible to modify
						}
						
						Sf = change_3 (Sf, Sf_nl_3, Sf_od_3, m, n, gamemode, number_of_players, ges);
						
						if (gamemode == 1) {
							for (unsigned int j=1; j<n-1; j+=1){	//possible to modify
								if (Sf[2][j] == 2){
									B[0] += 1;
									break;
								}
							} 
						} else if (gamemode == 2) {	//possible to modify
							for (unsigned int j=2; j<n-1; j+=((n-1)/2)-2){		//collect-Bed. prüfen
								unsigned int b;
								b = 0;
								if (Sf[((m-1)/2)][j] == 7){
									if (Sf[((m-1)/2)-1][j]==2){b += 1;}
									if (Sf[((m-1)/2)+1][j]==2){b += 1;}
									if (Sf[(m-1)/2][j-1]==2){b += 1;}
									if (Sf[(m-1)/2][j+1]==2){b += 1;}
									if (b >= 3){
										B[0] += 1;
										Sf[((m-1)/2)][j] = 2;
									}
								}
							}
							if (B[0] == 2){
								printf("\n");
								printf("	Sieg: Spieler 2 \n");
								printf("\n");
								show_field (Sf, m, n, gamemode, information_code, geben, Colored);
								break;
							}
						}
						
						if ((gamemode == 6)&&(geben == number_of_players)) {
							lim = 1;
							printf("	\n");
							if (opague >= 1) {
								show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
							} else {
								show_field (Sf, m, n, gamemode, information_code, geben, Colored);
							}
							printf("	\n");
							while (lim == 1) {
								printf("	\n");
								printf("	\n");
								printf("	Are you ready to make your turn? \n");
								printf("	Yes: 1 \n");
								printf("	\n");
								printf("	\n");
								scanf("%u", &lim);
								
								if (lim != 1) {
									lim = 1;
								} else {
									lim = 0;
								}
							}
						}
						if (gamemode == 6) {
							information_code[3] = 0;
						}
						controll = 0;
						
						if (gamemode == 1) {	//possible to modify
							for (unsigned int erste=1; erste<n-1; erste+=1){		//Spiel-Ende?
								if (Sf[1][erste] == 2){
									printf("	Sieg:	Spieler 2 \n");
									controll = 1;
									break;
								}
							}
							if (controll == 1){
								break;
							}
						}
						controll = 0;
						
						if (gamemode == 3) {	//possible to modify
							if (opague >= 1) {
								show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
							} else {
								show_field (Sf, m, n, gamemode, information_code, geben, Colored);
							}
							battle (m, n, Sf, geben);
						}
						
						if (number_of_players == 3) {// gamemode 6 modify, done!
							if (var_[1] != 1010) {
								cons[3] = use_number;
								
								if (gamemode == 11) {	//mehr-gamemode
									for (unsigned int p=2; p<=5; p+=1) {
										
										dynamic_pointer_save[3][p-2] = dynamic_pointer[p];
										
									}
								}
								
							}
							
						} else if (number_of_players >= 4) {
							if (var_[4] != 1010) {
								cons[3] = use_number;
								
								if (gamemode == 11) {	//mehr-gamemode
									for (unsigned int p=2; p<=5; p+=1) {
										
										dynamic_pointer_save[3][p-2] = dynamic_pointer[p];
										
									}
								}
								
							}
							
						}
						
						use_number = random_number (num_1, num_2, num_3, use_number, g, var_, number_3, number_4);
						
						if ((opt != 5)&&(var_[3] <= 62)){
							controll_2 = 0;
							for (unsigned int z=var_[3]; z>2; z-=10){
								controll_2 += 1;
							}
							number_3 = controll_2;
							//printf("%u \n", number_3);
							controll_2 = 0;
						}
					}
				}	//{}ausfindig machen
			} else if (geben == 4) {		//following players
				
				if (opague >= 1) {
					Sf_opague = opague_builder (Sf, m, n, geben, opague, aop);
					
				}
				
				if ((ttt != 0)&&(pere[geben] == 100)) {
					g += 1;
					continue;
				}
				
				if ((gamemode == 10)&&(ulcer_start[4] == 0)) {
					if (opague >= 1) {
						show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
					} else {
						show_field (Sf, m, n, gamemode, information_code, geben, Colored);
					}
					g += 1;
					continue;
				}
				
				if ((ges[4] == 4040)&&((gamemode == 6)||(gamemode == 9)||(gamemode == 10)||(gamemode == 11)||(gamemode == 12))) {	//mehr-gamemode
					g+=1;
					var_[4] = 4040;
					cons[4] = cons[3];
					for (unsigned int i=1; i<m-1; i+=1){
						for (unsigned int j=1; j<n-1; j+=1){
							cons_field_4[i][j] = cons_field_3[i][j];
							if (journey == 1){
								cons_journey_4[i][j] = cons_journey_3[i][j];
								
								if (Sf_journey[i][j] == 4) {
									Sf_journey[i][j] = 0;
								}
							}
							if (gamemode == 11) {	//mehr-gamemode
								for (unsigned int p=2; p<=5; p+=1) {
									
									dynamic_pointer_save[4][p-2] = dynamic_pointer_save[3][p-2];
									
								}
							}
						}
					}
					if (var_[0] == 1) {
						g-=2;
					}
					continue;
				}
				
				w = 3;
				d = 2;
				e = 3;
				if (gamemode == 9) {
					if (ability[1] == geben) {
						w = 1;
						d = 0;
						e = 1;
						information_code[0] = 1;
					} else if (ability[2] == geben) {
						w = 2;
						d = 1;
						e = 2;
						information_code[0] = 2;
					} else if (ability[3] == geben) {
						w = 4;
						d = 1;
						e = 4;	//abweichende e-definition
						information_code[0] = 3;
					} else if (ability[4] == geben) {
						information_code[0] = 4;
					} else if (ability[5] == geben) {
						information_code[0] = 5;
					} else if (ability[6] == geben) {
						information_code[0] = 6;
					} else if (ability[7] == geben) {
						information_code[0] = 7;
					} else if (ability[8] == geben) {
						information_code[0] = 8;
					} else if (ability[9] == geben) {
						information_code[0] = 9;
						
						if (opague >= 1) {
							show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
						} else {
							show_field (Sf, m, n, gamemode, information_code, geben, Colored);
						}
						
						for (unsigned int i=1; i<m-1; i+=1){
							for (unsigned int j=1; j<n-1; j+=1){
								if (Sf[i][j] == geben) {
									if ((Sf[i+1][j] != 0)&&(Sf[i+1][j] != geben)&&((i+2) <= (m-2))) {
										if (Sf[i+2][j] == 0) {
											Sf[i+2][j] = Sf[i+1][j];
											Sf[i+1][j] = 0;
										}
									}
									if ((Sf[i-1][j] != 0)&&(Sf[i-1][j] != geben)&&((i-2) >= 1)) {
										if (Sf[i-2][j] == 0) {
											Sf[i-2][j] = Sf[i-1][j];
											Sf[i-1][j] = 0;
										}
									}
									if ((Sf[i][j-1] != 0)&&(Sf[i][j-1] != geben)&&((j-2) >= 1)) {
										if (Sf[i][j-2] == 0) {
											Sf[i][j-2] = Sf[i][j-1];
											Sf[i][j-1] = 0;
										}
									}
									if ((Sf[i][j+1] != 0)&&(Sf[i][j+1] != geben)&&((j+2) <= (n-2))) {
										if (Sf[i][j+2] == 0) {
											Sf[i][j+2] = Sf[i][j+1];
											Sf[i][j+1] = 0;
										}
									}
								}
							}
						}
					}
				}
				
				if (gamemode == 10) {
					w = 2;
					d = 1;
					e = 2;
				}
				
				if (gamemode == 9) {
					if (information_code[0] == 1) {
						limit_at_all = limit_at_all-2;
					} else if (information_code[0] == 2) {
						limit_at_all = limit_at_all-1;
					} else {
						limit_at_all = limit_at_all_saver;
					}
				}
				
				if (ttt != 0) {
					if ((pere[geben] != 0)&&(warning_system <= 5)&&((pere[geben]+warning_system) == 7)) {
						g += 1;
						printf(" \n ");
						printf("	You got a penalty. \n ");
						printf(" \n ");
						pere[geben] = 0;
						continue;
					} else if ((pere[geben] != 0)&&(warning_system != 0)&&(((warning_system <= 5)&&((pere[geben]+warning_system) == 8))||((warning_system == 6)&&(pere[geben] == 1)))) {
						Sf_od_4 = old_dying_4 (Sf, m, n, d, e, gamemode, information_code);
						Sf = change_4 (Sf, Sf_nl_4, Sf_od_4, m, n, gamemode, number_of_players, ges); 	//Change befreit
						g += 1;
						printf(" \n ");
						printf("	You got a penalty. \n ");
						printf(" \n ");
						pere[geben] = 0;
						continue;
					} else if (((warning_system <= 5)&&((warning_system + pere[geben]) >= 9))||((warning_system >= 6)&&((warning_system + pere[geben]) >= 8))) {
						printf("	Niederlage: Spieler 4 \n ");
						for (unsigned int i=1; i<m-1; i+=1){
							for (unsigned int j=1; j<n-1; j+=1){
								if (Sf[i][j] == 4) {
									Sf[i][j] = 0;
								}
							}
						}
						ges[4] = 4040;
						player_counter += 1;
						pere[geben] = 100;
						g += 1;
						continue;
					}
				}
				
				if (var_[geben] == 1010) {
					use_number = cons[geben];
					if (opt == 5) {
					
						printf("	Player %u ,do you want to keep your number (%u) or do you want to get the next one? \n", geben, cons[geben]);
						printf("	Keep the number: 	1 \n");
						printf("	Get the next one:	2 \n");
						scanf("%u", &lim);
						
						if (lim == 2) {
							use_number = random_number (num_1, num_2, num_3, use_number, g, var_, number_3, number_4);
						} else if (lim != 1) {
							printf("	Well, you keep your number, but next time please take an option i offered. \n\n");
						}
						lim = 0;
					
					}
				}
				
				if (var_[geben%number_of_players+1] == 1010){		//geben%number_of_players+1 ist der Nachfolger von geben.
					if (tac != 0) {
						if (number_4 <= 5){
							DD[number_4] += 1;
						} else if (number_4 == 6){
							DD[0] += 1;
						}
					} else if (opt == 5) {
						BB[use_number] -= 1;
					} else {
						BB[number_4] -= 1;
					}
					
				}
				
				if ((tac != 0)&&((DD[1]+DD[2]+DD[3]+DD[4]+DD[5]+DD[0]) == 0)){
					for (unsigned int p=0; p<=5; p+=1){
						DD[p] = tac;
					}
				}
				
				menuoperator = 1;
				
				
				
				while (menuoperator != 0) {
					
					if (gamemode != 8) {
						if (opague >= 1) {
							show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
						} else {
							show_field (Sf, m, n, gamemode, information_code, geben, Colored);
						}
					}
					
					if ((gamemode == 6)&&(((scwhp == 1)&&((opt == 0)||((use_number == 2)||(use_number == 3)||(use_number == 4)))&&((tac == 0)||((DD[2] != 0)||(DD[3] != 0)||(DD[4] != 0))))||(scwhp == 2))) {
						
						information_code[3] = 1;
						
						if (opague >= 1) {
							show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
						} else {
							show_field (Sf, m, n, gamemode, information_code, geben, Colored);
						}
					}
					
					if (gamemode == 4) {
						printf("\n");
						printf("	Points player 4: 	%u Point(s) \n", P[geben]);
					}
					
					if (gamemode == 10) {
						printf("\n");
						printf("	Lifes player 4: 	%u Life(s) \n", ulcer_lifes[4]);
					}
					
					if (gamemode == 11) {
						printf("	\n");
						printf("	Geschwindigkeit: 	Zeile: %d, 	Spalte: %d \n", dynamic_pointer[2], dynamic_pointer[3]);
						printf("	Beschleunigung: 	Zeile: %d, 	Spalte: %d \n", dynamic_pointer[4], dynamic_pointer[5]);
						printf("	\n");
					}
					
					printf("\n");
					
					if (Colored[0] == 1) {
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+Colored[geben]);
					}
					
					if ((gamemode != 6)&&(gamemode != 9)&&(gamemode != 10)&&(gamemode != 11)&&(gamemode != 12)){	//mehr-gamemode
						printf("	Am Zug: Spieler 2 (OO)	\n");	// possible to modify
					} else if (gamemode == 6) {
						printf("	Am Zug: Spieler 4 (CC)	\n");
					} else if (gamemode == 9) {
						if (ability[1] == geben) {
							printf("	Am Zug: Spieler 4 (UU)	\n");
						} else if (ability[2] == geben) {
							printf("	Am Zug: Spieler 4 (LL)	\n");
						} else if (ability[3] == geben) {
							printf("	Am Zug: Spieler 4 (AA)	\n");
						} else if (ability[4] == geben) {
							printf("	Am Zug: Spieler 4 (CC)	\n");
						} else if (ability[5] == geben) {
							printf("	Am Zug: Spieler 4 (II)	\n");
						} else if (ability[6] == geben) {
							printf("	Am Zug: Spieler 4 (SS)	\n");
						} else if (ability[7] == geben) {
							printf("	Am Zug: Spieler 4 (PP)	\n");
						} else if (ability[8] == geben) {
							printf("	Am Zug: Spieler 4 (HH)	\n");
						} else if (ability[9] == geben) {
							printf("	Am Zug: Spieler 4 (EE)	\n");
						}
					} else if ((gamemode == 10)||(gamemode == 11)||(gamemode == 12)) {	//mehr-gamemode
						printf("	Am Zug: Spieler 4 (44)	\n");
					}
					
					if (Colored[0] == 1) {
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+7);
					}
					
					printf("\n");
					
					if (tac != 0){
						printf("	Your stack of numbers:	\n	1) [%u],		2) [%u],		3) [%u], \n\n	4) [%u],		5) [%u],		6) [%u],\n", DD[1], DD[2], DD[3], DD[4], DD[5], DD[0]);
						printf("\n");
						printf("\n");
					}
					
					if (opt == 5){		//random number
						printf("	Your number: %u ", use_number);
						printf("\n");
						printf("\n");
						
					}
					
					printf("	1) Plus:	11	Minus: 	12 \n");
					printf("	2) Move:	21	Change: 22 \n");
					printf("	3) Destroy:	31	Revive: 32 \n");
					printf("	4) Move:	41	Boost: 	42 \n");
					if (((gamemode != 9)&&(gamemode != 10))||((gamemode == 10)&&(geben == 1))) {
						printf("	5) 4/5-new:	51	2-new:	52 \n");
						printf("	6) 4-max:	61	1-min:	62 \n");
					} else if (gamemode == 9) {
						if (information_code[0] == 1) {
							printf("	5) 2/3-new:	51	0-new:	52 \n");
							printf("	6) 2-max:	61	-1-min:	62 \n");
						} else if (information_code[0] == 2) {
							printf("	5) 3/4-new:	51	1-new:	52 \n");
							printf("	6) 3-max:	61	0-min:	62 \n");
						} else if (information_code[0] == 3) {
							printf("	5) 5/6-new:	51	3-new:	52 \n");
							printf("	6) 5-max:	61	0-min:	62 \n");
						} else {
							printf("	5) 4/5-new:	51	2-new:	52 \n");
							printf("	6) 4-max:	61	1-min:	62 \n");
						}
					} else if ((gamemode == 10)&&(geben != 1)) {
						printf("	5) 3/4-new:	51	1-new:	52 \n");
						printf("	6) 3-max:	61	0-min:	62 \n");
					}
					printf("							\n");
					printf("		Go back: 100 \n");
					printf("		Menu: 10 \n");
					printf("		End game: 0 \n");
					if ((ttt != 0)&&(time_saver == 0.0)) {
						time1 = time(NULL);
					}
					scanf("%u", &var_[4]);
					
					if (var_[4] == 10){		//new_life wird übersprungen, done
						if (ttt != 0) {
							time3 = time(NULL);
						}
						while (menuoperator != 7) {
							printf("\n");
							printf("\n");
							printf("	About the game: 1 \n	Statistics: 2 \n	The numbers: 3 \n	The limits: 4 \n	Get Hints: 5 \n	Suprise: 6 \n	Quit Menu: 7 \n");
							scanf("%u", &menuoperator);
							
							if (menuoperator == 1){
								if (gamemode == 1) {
									printf("	How to win? 	Own a square on your last line or force your opponent to lose all his/her ones.\n");
								} else if (gamemode == 2) {
									printf("	How to win? 	Be at 2 of the 3 targets with three of your squares near-by.\n");
								} else if (gamemode == 3) {
									printf("	How to win? 	Take over all your opponent's squares by winning contact-battles.\n");
									printf("	Contact-battles? 	All near-by squares in a row with the contact-square build a chain, beat your opponent in the length.\n");
								} else if (gamemode == 4) {
									printf("	How to win? 	Get more points than your opponent.\n");
									printf("	Note:	Touch the #-square in the near-by to move it to the opposite side. \n");
								} else if (gamemode == 5) {
									printf("	How to win? 	Force your opponent to lose all his/her squares.\n");
								} else if (gamemode == 6) {
									if (geben == 1) {
										printf("	How to win? 	Protect your heart-block so no enemy can touch it.\n");
									} else {
										printf("	How to win? 	Catch the heart-block of the hunted one before it disappears.\n");
									}
								} else if (gamemode == 7) {
									printf("	How to win? 	Reach the end of the field or force your opponent to lose all his/her ones.\n");
									printf("	Note:	Every %u turns in total the #-line will go ahead and destroys everything in it's way.\n Also you are not allowed to cross the mid-line. \n", freq);
								} else if (gamemode == 8) {
									printf("	How to win? 	Reach [1][7] of the field or force your opponent to lose all his/her squares.\n");
									printf("	Note:	Falling down the #-squares will push, destroy, explode, or teleport, transform into yours by contact. \n");
								} else if ((gamemode == 9)||(gamemode == 10)) {
									printf("	How to win? 	Force your opponent to lose all his/her squares while keeping yours alive.\n");
								} else if (gamemode == 11) {
									printf("	How to win? 	Push the ball against your opponent's side.\n");
								} else if (gamemode == 12) {	//mehr-gamemode
									printf("	How to win? 	Stay alive.\n");
								}
								printf("	Surrounding:	The 8 squares around another, at the edge 5, in the corners 3, are called #surrounding. \n");
								printf("	near-by:	The 4 squares around another, at the edge 3, in the corners 2, are called #near-by. \n");
								printf("	Standard actions:	(After your choice of number and not influencing each other) \n	-Development:	If it is your turn and a free square has exactly 3 of yours surrounding it, you will own it.\n");
								printf("	-Losses: 	If it is your turn and a square of yours is surrounded by less than %u or more than %u of yours,\n			it will be set free.\n", d, e);
								if ((gamemode == 10)||(gamemode == 12)) {	//mehr-gamemode
									printf("	Limits: 	This gamemode is unlimited. \n");
								} else if (gamemode == 3) {
									printf("	Limits: 	Your development is limited by %u per round. \n", limit_new);
								} else {
									printf("	Limits: 	Your development is limited by %u per round, your units in total by %u per round. \n", limit_new, limit_at_all);
								}
							}
							
							if (menuoperator == 2){
								printf("\n");
								printf("	turns at all: %u \n", g);
								printf("\n");
								printf("	Numbers of player 1: \n");
								printf("		#1 = %u \n", A[1]);
								printf("		#2 = %u \n", A[2]);
								printf("		#3 = %u \n", A[3]);
								printf("		#4 = %u \n", A[4]);
								printf("		#5 = %u \n", A[5]);
								printf("		#6 = %u \n", A[6]);
								printf("\n");
								if (number_of_players >= 2) {	//mehr-gamemode
									printf("	Numbers of player 2: \n");
									printf("		#1 = %u \n", B[1]);
									printf("		#2 = %u \n", B[2]);
									printf("		#3 = %u \n", B[3]);
									printf("		#4 = %u \n", B[4]);
									printf("		#5 = %u \n", B[5]);
									printf("		#6 = %u \n", B[6]);
									printf("\n");
								}
								
								if (number_of_players >= 3){	//mehr-gamemode
									printf("	Numbers of player 3: \n");
									printf("		#1 = %u \n", AA[1]);
									printf("		#2 = %u \n", AA[2]);
									printf("		#3 = %u \n", AA[3]);
									printf("		#4 = %u \n", AA[4]);
									printf("		#5 = %u \n", AA[5]);
									printf("		#6 = %u \n", AA[6]);
									printf("\n");
								}
								if (number_of_players >= 4){
									printf("	Numbers of player 4: \n");
									printf("		#1 = %u \n", BB[1]);
									printf("		#2 = %u \n", BB[2]);
									printf("		#3 = %u \n", BB[3]);
									printf("		#4 = %u \n", BB[4]);
									printf("		#5 = %u \n", BB[5]);
									printf("		#6 = %u \n", BB[6]);
									printf("\n");
								}
								if (number_of_players >= 5){
									printf("	Numbers of player 5: \n");
									printf("		#1 = %u \n", AAA[1]);
									printf("		#2 = %u \n", AAA[2]);
									printf("		#3 = %u \n", AAA[3]);
									printf("		#4 = %u \n", AAA[4]);
									printf("		#5 = %u \n", AAA[5]);
									printf("		#6 = %u \n", AAA[6]);
									printf("\n");
								}
								if (number_of_players >= 6){
									printf("	Numbers of player 6: \n");
									printf("		#1 = %u \n", BBB[1]);
									printf("		#2 = %u \n", BBB[2]);
									printf("		#3 = %u \n", BBB[3]);
									printf("		#4 = %u \n", BBB[4]);
									printf("		#5 = %u \n", BBB[5]);
									printf("		#6 = %u \n", BBB[6]);
									printf("\n");
								}
								if (number_of_players >= 7){
									printf("	Numbers of player 7: \n");
									printf("		#1 = %u \n", AAAA[1]);
									printf("		#2 = %u \n", AAAA[2]);
									printf("		#3 = %u \n", AAAA[3]);
									printf("		#4 = %u \n", AAAA[4]);
									printf("		#5 = %u \n", AAAA[5]);
									printf("		#6 = %u \n", AAAA[6]);
									printf("\n");
								}
								if (number_of_players >= 8){
									printf("	Numbers of player 8: \n");
									printf("		#1 = %u \n", BBBB[1]);
									printf("		#2 = %u \n", BBBB[2]);
									printf("		#3 = %u \n", BBBB[3]);
									printf("		#4 = %u \n", BBBB[4]);
									printf("		#5 = %u \n", BBBB[5]);
									printf("		#6 = %u \n", BBBB[6]);
									printf("\n");
								}
								if (number_of_players == 9){
									printf("	Numbers of player 9: \n");
									printf("		#1 = %u \n", AAAAA[1]);
									printf("		#2 = %u \n", AAAAA[2]);
									printf("		#3 = %u \n", AAAAA[3]);
									printf("		#4 = %u \n", AAAAA[4]);
									printf("		#5 = %u \n", AAAAA[5]);
									printf("		#6 = %u \n", AAAAA[6]);
									printf("\n");
								}
								
								if ((gamemode == 1)||(gamemode == 6)||(gamemode == 7)||(gamemode == 8)) {
									printf("	Matchballs player 1: 	%u \n", A[0]);
									printf("	Matchballs player 2: 	%u \n", B[0]);
									if (gamemode == 6) {
										if (number_of_players >= 3){printf("	Matchballs player 3: 	%u \n", AA[0]);}
										if (number_of_players >= 4){printf("	Matchballs player 4: 	%u \n", BB[0]);}
										if (number_of_players >= 5){printf("	Matchballs player 5: 	%u \n", AAA[0]);}
										if (number_of_players >= 6){printf("	Matchballs player 6: 	%u \n", BBB[0]);}
										if (number_of_players >= 7){printf("	Matchballs player 7: 	%u \n", AAAA[0]);}
										if (number_of_players >= 8){printf("	Matchballs player 8: 	%u \n", BBBB[0]);}
										if (number_of_players == 9){printf("	Matchballs player 9: 	%u \n", AAAAA[0]);}
									}
								} else if (gamemode == 2) {
									printf("	Squares collected by player 1: 	%u \n", A[0]);
									printf("	Squares collected by player 2: 	%u \n", B[0]);
								} else if (gamemode == 3) {
									printf("	Times with squares <= 5, player 1: 	%u \n", A[0]);
									printf("	Times with squares <= 5, player 2: 	%u \n", B[0]);
								} else if (gamemode == 4) {
									printf("	Points player 1: 		%u \n", P[1]);
									printf("	Points Player 2: 		%u \n", P[2]);
									printf("	Turns with more points player 1: 	%u \n", A[0]);
									printf("	Turns with more points player 2: 	%u \n", B[0]);
									printf("	Number of not decided #-squares: 	%u \n", P[0]);
								} else if (gamemode == 3) {
									printf("	Times with squares < 5, player 1: 	%u \n", A[0]);
									printf("	Times with squares < 5, player 2: 	%u \n", B[0]);
								} else if (gamemode == 9) {
									printf("	Number of excluded abilites: 	%u \n", exclude_counter);
									printf("	Offensive abilities taken: 	%u \n", number_of_players-ability[0]);
									printf("	Defensive abilities taken: 	%u \n", ability[0]);
								} else if (gamemode == 10) {
									for (unsigned int p=1; p<=number_of_players; p+=1) {
										printf("		Spieler %u: %u life(s) left.\n", p, ulcer_lifes[p]);
									}
								} else if (gamemode == 11) {	//mehr-gamemode
									for (unsigned int p=1; p<=number_of_players; p+=1) {
										if ((ges[p] > 1000)||(ges[p] == 0)) {
											printf("	Spieler %u: is out.\n", p);
										} else if (ges[p] < 1000) {
											printf("	Spieler %u: You own %u squares.\n", p, ges[p]);
										}
									}
								} else if (gamemode == 12) {
									for (unsigned int p=1; p<=number_of_players; p+=1) {
										if ((ges[p] > 1000)||(ges[p] == 0)) {
											printf("	Spieler %u: is out.\n", p);
										} else if (ges[p] < 1000) {
											printf("	Spieler %u: You own %u squares.\n", p, ges[p]);
										}
									}
								}
								
								if (ttt != 0) {
									printf("	Number of penalties given until	now: %u \n", pere[0]);
								}
							}
							
							if (menuoperator == 3){
								if ((gamemode != 10)&&(gamemode != 12)) {
									printf("	Plus: Change a free square in the surrounding of yours in one of yours.\n");
								} else {
									printf("	Plus: Change a square in the surrounding of yours in one of yours.\n");
								}
								printf("	Minus: Delete one of your squares.\n");
								printf("	Move: The position of one of yours will change with a free, near-by square.\n");
								printf("	Revive: Your lost squares having no living squares of yours surrounding them at the beginning of your turn,\n		will be revived.\n");
								printf("	%u/%u-new: A free square has to be surrounded by %u or %u of yours during the development.\n", w+1, w+2, w+1, w+2);
								printf("	%u-new: A free square has to be surrounded by %u of yours during the development.\n", d, d);
								printf("	%u-max: A square of yours will survive even by %u of your squares surrounding it.\n", e+1, e+1);
								if (d == 0) {
									printf("	-1-min: A square of yours will survive even by only -1 of your squares surrounding it.\n");
								} else {
									printf("	%u-min: A square of yours will survive even by only %u of your squares surrounding it.\n", d-1, d-1);
								}
								
								if ((gamemode == 1)||(gamemode == 2)||(gamemode == 4)||(gamemode == 5)||(gamemode == 7)||(gamemode == 9)||(gamemode == 10)) {
									printf("	Change: A square of yours and a near-by square of your enemy will change positions.\n");
									printf("	Destroy: Delete a near-by square of your enemy.\n");
									printf("	Boost: Use all near-by squares of your enemy as your own for the development.\n");
									
								} else if (gamemode == 3) {
									
									printf("	Change: A square of yours and a square of your enemy in the surrounding will change positions.\n");
									printf("	Destroy: Delete a surrounding square of your enemy.\n");
									printf("	Boost: Use all surrounding squares of your enemy as your own for the development.\n");
									
								} else if (gamemode == 8) {
									printf("	Change: A square of yours and a near-by #-square will change positions.\n");
									printf("	Destroy: Delete a square of your enemy, but not in the last two lines.\n");
									printf("	Boost: Use all near-by #-squares as your own for the development.\n");
									
								} else if (gamemode == 6) {
									if (geben == 1) {
										printf("	Change: The heart-block and a square of yours will change positions.\n");
										printf("	Destroy: Delete a square of your enemy.\n");
										printf("	Boost: Touching the heart_block no square of yours can die.\n");
									} else {
										printf("	Change: A square of yours and a near-by square of the hunted one will change positions.\n");
										printf("	Destroy: Delete a near-by square of your enemy.\n");
										printf("	Boost: Use all near-by squares of the hunted one as your own for the development.\n");
									}
									
								} else if (gamemode == 11) {	//mehr-gamemode
									printf("	Change: A square of yours and a near-by square of your enemy or the near-by ball will change positions.\n");
									printf("	Destroy: Delete a near-by square of your enemy.\n");
									printf("	Boost: Use all near-by squares of your enemy and the near-by ball as your own for the development.\n");
								} else if (gamemode == 12) {
									printf("	Change: A square of yours and a near-by square of your enemy or a near-by object will change positions.\n");
									printf("	Destroy: Delete a near-by square of your enemy or a near-by object.\n");
									printf("	Boost: Use all near-by squares of your enemy and near-by objects as your own for the development.\n");
								}
								
								printf("\n");
							}
							
							if (menuoperator == 4){	//mehr-gamemode
								if ((gamemode != 10)&&(gamemode != 12)) {
									printf("	Limit of development:	%u \n", limit_new);
									if (gamemode != 3) {
										printf("	Limit in total:		%u \n", limit_at_all);
										printf("	Limit in total with >2-new< taken: %u -0/-1/-2/-3/-4.\n", limit_at_all);
									}
								}
							}
							
							if (menuoperator == 5){
								Spielfeld hint;
								unsigned int b, a;
								hint = Spielfeld_Create (m, n);
								printf("	New: 1 \n	Dying: 2 \n	Both: 3 \n");
								scanf("%u", &menuoperator);
								
								for (unsigned int i=1; i<(m-1); i+=1){
									for (unsigned int j=1; j<(n-1); j+=1){
										if ((gamemode != 6)&&(gamemode != 9)&&(gamemode != 10)&&(gamemode != 11)&&(gamemode != 12)){	//mehr-gamemode
											if (Sf[i][j] == geben){
												hint[i][j] = geben;
											} else if (Sf[i][j] == (geben%2)+1){
												hint[i][j] = (geben%2)+1;
											} else if (Sf[i][j] == 7){
												hint[i][j] = 7;
											} 
										} else if ((gamemode == 6)||(gamemode == 9)||(gamemode == 10)) {	//10
											if (Sf[i][j] == geben){
												hint[i][j] = geben;
											} else if (Sf[i][j] != 0){
												hint[i][j] = 17;
											}
										} else if (gamemode == 11) {
											if (Sf[i][j] == geben){
												hint[i][j] = geben;
											} else if (Sf[i][j] == 77){
												hint[i][j] = 77;
											} else if (Sf[i][j] != 0){
												hint[i][j] = 17;
											}
										} else if (gamemode == 12) {	//mehr-gamemode
											if (Sf[i][j] == geben){
												hint[i][j] = geben;
											} else if (Sf[i][j] == 81){
												hint[i][j] = 81;
											} else if (Sf[i][j] == 82){
												hint[i][j] = 82;
											} else if (Sf[i][j] == 83){
												hint[i][j] = 83;
											} else if (Sf[i][j] == 84){
												hint[i][j] = 84;
											} else if (Sf[i][j] == 75){
												hint[i][j] = 75;
											} else if (Sf[i][j] == 71){
												hint[i][j] = 71;
											} else if (Sf[i][j] != 0){
												hint[i][j] = 17;
											}
										}
									}
								}
								
								if ((menuoperator == 2)||(menuoperator == 3)){
									for (unsigned int i=1; i<(m-1); i+=1){
										for (unsigned int j=1; j<(n-1); j+=1){
											if (Sf[i][j] == geben){
												a = 0;
												for (unsigned int h=(i-1); h<=(i+1); h+=1){
													for (unsigned int k=(j-1); k<=(j+1); k+=1){
														if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
															if (Sf[h][k] == geben){
																a += 1;
															}
														}
													}
												}
												if ((a > 4) || (a < 3)){
													hint[i][j] = 16;
												}
											}
										}
									}
								}
								
								if ((menuoperator == 1)||(menuoperator == 3)){
									for (unsigned int i=1; i<(m-1); i+=1){
										for (unsigned int j=1; j<(n-1); j+=1){
											if (Sf[i][j] == 0){
												b = 0;
												for (unsigned int h=(i-1); h<=(i+1); h+=1){
													for (unsigned int k=(j-1); k<=(j+1); k+=1){
														if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
															if (Sf[h][k] == geben){
																b += 1;
															}
														}
													}
												}
												if (b == 3){
													hint[i][j] = 15;
												}
											}
										}
									}
								}
						
								if (opague >= 1) {
									Sf_opague = opague_builder (hint, m, n, geben, opague, aop);
								}
								
								if (opague >= 1) {
									show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
								} else {
									show_field (hint, m, n, gamemode, information_code, geben, Colored);
								}
								
								if (opague >= 1) {
									Sf_opague = opague_builder (Sf, m, n, geben, opague, aop);
								}
								menuoperator = 1;
								Spielfeld_Destroy (hint, m);
							}
							// 2
							if (menuoperator == 6){
								if (suprise == 0) {
									for (unsigned int i=1; i<m-1; i+=1){
										for (unsigned int j=1; j<n-1; j+=1){
											cons_field_4[i][j] = Sf[i][j];
											
											if (journey == 1){
												cons_journey_4[i][j] = Sf_journey[i][j];
											}
										}
									}
									sup_num = use_number;
								}
								
								while (menuoperator != 1) {
						
									printf("	Creator menu. 	Change number: 1	Suprise: 2	Suprise undo: 3	Back: 4 \n");
									scanf ("%u", &lim);
									if (lim == 1){
										printf("	number = ? \n");
										scanf ("%u", &use_number);
									} else if (lim == 2){
								
										printf("\n");
										scanf("%u", &suprise);
								
										if (suprise == 31){
											for (unsigned int i=2; i<m-2; i+=1){
												for (unsigned int j=1; j<n-1; j+=1){
													if (Sf[i][j] != 0){
														if (Sf[i][j] == 1){
															Sf[i][j] = 4;
														} else if (Sf[i][j] == 4){
															Sf[i][j] = 1;
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
								
										if(suprise == 13){
											for (unsigned int i=1; i<m-1; i+=1){
												for (unsigned int j=1; j<n-1; j+=1){
													if (Sf[i][j] == 4){
														Sf[i][j] = 0;
													}
													if (i == (m-2)){
														Sf[m-2][j] = 4;
													}
												}
											}
										}
								
									} else if (lim == 3){
										for (unsigned int i=1; i<m-1; i+=1){
											for (unsigned int j=1; j<n-1; j+=1){
												Sf[i][j] = cons_field_4[i][j];
												
												if (journey == 1){
													Sf_journey[i][j] = cons_journey_4[i][j];
												}
											}
										}
										use_number = sup_num;
									} else if (lim == 4){
										menuoperator = 1;
									} else {
										printf("	Invalid comment");
									}
								}
							}
						}	// menuoperator = 7
						
						if (gamemode == 8) {
							if (opague >= 1) {
								show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
							} else {
								show_field (Sf, m, n, gamemode, information_code, geben, Colored);
							}	//show_field über menuoperator = 7 und stack und so löschen, (verschiebe menuoperator!=0 - Schleife), done
							
							printf("\n");
						
						}
						
						if (ttt != 0) {
							time4 = time(NULL);
							time_saver += difftime(time4, time3);
						}
					}	//Menu-end
					
					menuoperator = 0;
					
					if (var_[4] == 10) {
						menuoperator = 1;
						var_[4] = 5;
					}
					
					if ((tac != 0)&&(var_[4] <= 62)&&(var_[4] > 10)){
						unsigned int tac_controll;
						tac_controll = 0;
						if (((var_[4]%10) > 2)||((var_[4]%10) == 0)){
							var_[4] = 7;
							menuoperator = 1;
						} else {
							for (unsigned int z=var_[4]; z>2; z-=10){
								tac_controll += 1;
							}
							if (tac_controll == 6){
								tac_controll = 0;
							}
							if (DD[tac_controll] == 0){
								var_[4] = 7;
								menuoperator = 1;
							} else {
								DD[tac_controll] -= 1;
							}
						}
					} else if ((tac != 0)&&(var_[4] != 100)&&(var_[4] != 1010)&&(var_[4] != 0)) {
						var_[4] = 7;
					}		
					//tac-mode
					
					if (opt == 5){
						controll_1 = 10+use_number;
						controll_2 = 11+use_number;
					
						for (unsigned int i=0; i<use_number-1; i+=1){
							controll_1 += 9;
							controll_2 += 9;
						}
					
						if (var_[4] == 0){
							controll_1 = 0;
							controll_2 = 0;
						}
						if (var_[4] == 100){
							controll_1 = 100;
							controll_2 = 100;
						}
						if (var_[4] == 1010){
							controll_1 = 1010;
							controll_2 = 1010;
						}
					}
					//
					if (((var_[4] > 0)&&(var_[4] < 10))||(((opt == 5)&&(var_[4] != controll_1))&&((opt == 5)&&(var_[4] != controll_2)))){
						
						if (var_[4] != 5) {
							printf("	You made a mistake, try again: \n");
							printf("\n");
							printf("\n");
						} else {
							printf("	You closed the menu. \n");
							printf("\n");
							printf("\n");
						}
						//enough
						
						menuoperator = 1;
					}
					
				}		// menuoperator = 0
				
				
				suprise = 0;
				
				if (var_[4] == 0){
					printf("	Do you really want to end the game ? \n");
					printf("	Yes: 0		No: 1 \n");
					scanf("%u", &lim);
					if (lim == 0){
						break;
					} else if (lim == 1){
						continue;
					} else {
						printf("	0 or 1, it is so difficult to understand? \n");
						printf("	Well, it seems I have to end it by myself... \n");
						break;
					}	
				} else {
					
					if (var_[4] == 100){		//gamemode 6 modify, done
						
						var_[0] = 1;
						
						for (unsigned int i=1; i<m-1; i+=1){
							for (unsigned int j=1; j<n-1; j+=1){
								Sf[i][j] = cons_field_3[i][j];
								
								if (journey == 1){
									Sf_journey[i][j] = cons_journey_3[i][j];
								}
							}
						}
						
						if (opague >= 1) {
							Sf_opague = opague_builder (Sf, m, n, geben, opague, aop);
						}
						
						if (opague >= 1) {
							show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
						} else {
							show_field (Sf, m, n, gamemode, information_code, geben, Colored);
						}
						
						cons[geben] = use_number;
						
						use_number = cons[3];
						
						if (gamemode == 11) {	//mehr-gamemode
							for (unsigned int p=2; p<=5; p+=1) {
								
								dynamic_pointer[p] = dynamic_pointer_save[3][p-2];
								
							}
						}
						
						g-=1;
						var_[4] = 1010;
						if (gamemode == 10) {
							ulcer_lifes[4] += 1;
							ulcer_start[4] = 0;
						}
						continue;
					} else {
						
						if (number_of_players == 4) {
							
							if (var_[1] != 1010){
								for (unsigned int i=1; i<m-1; i+=1){
									for (unsigned int j=1; j<n-1; j+=1){
										cons_field_4[i][j] = Sf[i][j];
										
										if (journey == 1){
											cons_journey_4[i][j] = Sf_journey[i][j];
										}
									}
								}
							}
						} else if (number_of_players >= 5) {
							if (var_[5] != 1010){
								for (unsigned int i=1; i<m-1; i+=1){
									for (unsigned int j=1; j<n-1; j+=1){
										cons_field_4[i][j] = Sf[i][j];
										
										if (journey == 1){
											cons_journey_4[i][j] = Sf_journey[i][j];
										}
									}
								}
							}
						}
						
						var_[0] = 0;
						
						if (var_[4] < 50){
							
							if (var_[4] == 11){BB[1] += 1; Plus (m, n, geben, Sf, limit_at_all, gamemode, information_code, number_of_players, Colored, opague, Sf_opague);}
							if (var_[4] == 12){BB[1] += 1; Minus (m, n, geben, Sf, gamemode, information_code, Colored, opague, Sf_opague);}
							if (var_[4] == 21){BB[2] += 1; Move (m, n, geben, Sf, gamemode, information_code, Colored, opague, Sf_opague);}
							if (var_[4] == 41){BB[4] += 1; Move (m, n, geben, Sf, gamemode, information_code, Colored, opague, Sf_opague);}
							if (var_[4] == 22){BB[2] += 1; Change (m, n, geben, Sf, gamemode, information_code, Colored, opague, Sf_opague, position);}
							if (var_[4] == 31){BB[3] += 1; Destroy (m, n, geben, Sf, gamemode, information_code, Colored, opague, Sf_opague);}
							if (var_[4] == 42){
								BB[4] += 1; 
								Boost (geben, Sf, m, n, temp, gamemode);
							}
						} else {
							if (var_[4] == 51){BB[5] += 1; w += 1;}		//w
							if (var_[4] == 52){BB[5] += 1; w -= 1;}		//w
							if (var_[4] == 61){BB[6] += 1; e += 1;}		//e
							if (var_[4] == 62){BB[6] += 1; if (d != 0) {d -= 1;} else {d = 10;}}		//d
						}		//printf("ok(1376)");
						
						if (ttt != 0) {
							time2 = time(NULL);
							time_warning = ((difftime(time2, time1)) - time_saver);
							
							//printf("	time_warning: %f \n", time_warning);		//test
							
							if ((pere[geben] != 0)&&((pere[geben] + warning_system) <= 6)) {
								if (pere[geben] == 1) {
									if (warning_system <= 2) {
										time_warning += 1.0;
									} else if (warning_system == 3) {
										time_warning += 2.0;
									} else if (warning_system == 4) {
										time_warning += 3.0;
									} else if (warning_system == 5) {
										time_warning += 5.0;
									}
								} else if (pere[geben] == 2) {
									if (warning_system == 1) {
										time_warning += 2.0;
									} else if (warning_system == 2) {
										time_warning += 3.0;
									} else if (warning_system == 3) {
										time_warning += 5.0;
									} else if (warning_system == 4) {
										time_warning += 6.0;
									}
								} else if (pere[geben] == 3) {
									if (warning_system == 1) {
										time_warning += 3.0;
									} else if (warning_system == 2) {
										time_warning += 5.0;
									} else if (warning_system == 3) {
										time_warning += 8.0;
									}
								} else if (pere[geben] == 4) {
									if (warning_system == 1) {
										time_warning += 4.0;
									} else if (warning_system == 2) {
										time_warning += 7.0;
									}
								} else if (pere[geben] == 5) {
									if (warning_system == 1) {
										time_warning += 5.0;
									}
								}
							}
							
							if (time_warning > (1.0*ttt)) {
								pere[0] += 1;
								printf("	You took too much time! %f sec more than you should. \n", (time_warning-1.0*ttt) );
								printf(" \n");
								for (unsigned int p=16; p>=1; p-=3) {	//index_verschiebung
									if ((time_warning-1.0*ttt) > 1.0*(p-1)) {
										pere[geben] = (((p-1)/3) + 1);
										break;
									}
								}
							} else {
								pere[geben]	 = 0;
							}
						}
					
						Sf_nl_4 = new_life_4 (Sf, m, n, w, gamemode, information_code);		//printf("ok(1378)");
						
						//printf("Test-print \n");	//test
						//show_field (Sf_nl_4, m, n, gamemode, information_code, geben, Colored);	//test
						
						if (gamemode == 6) {
							
							precounter = 0;
							for (unsigned int i=1; i<m-1; i+=1){
								for (unsigned int j=1; j<n-1; j+=1){
									if (Sf[i][j] == 11){
										if (Sf_nl_3[i][j-1] > 1) {
											printf (" Sieg: Spieler %u \n", Sf_nl_3[i][j-1]);
											precounter += 1;
										}
										if (Sf_nl_3[i][j+1] > 1) {
											if (precounter == 0) {
												printf (" Sieg: Spieler %u \n", Sf_nl_3[i][j+1]);
											}
											precounter += 1;
										}
										if (Sf_nl_3[i-1][j] > 1) {
											if (precounter == 0) {
												printf (" Sieg: Spieler %u \n", Sf_nl_3[i-1][j]);
											}
											precounter += 1;
										}
										if (Sf_nl_3[i+1][j] > 1) {
											if (precounter == 0) {
												printf (" Sieg: Spieler %u \n", Sf_nl_3[i+1][j]);
											}
											precounter += 1;
										}
										if (precounter == 2) {
											printf(" Double-catch! \n");
										}
										if (precounter == 3) {
											printf(" TRIPLE-catch!! \n");
										}
										if (precounter == 4) {
											printf(" QUADRO-CATCH!!! \n");
										}
										break;
									}
								}
								if (precounter > 0) {
									break;
								}
							}
							if (precounter > 0) {
								for (unsigned int i=1; i<m-1; i+=1){
									for (unsigned int j=1; j<n-1; j+=1){
										if (Sf_nl_3[i][j] == geben) {
											Sf[i][j] = geben;
										}
									}
								}
								show_field (Sf, m, n, gamemode, information_code, geben, Colored);
								break;
							}
						}
						controll = 0;
						
						if (gamemode == 7) {	// possible to modify
							for (unsigned int i=(m-2); i>=(m-1)/2; i-=1){		//Spiel-Ende?
								if ((Sf_nl_4[i][n-2] == 4)||(Sf[i][n-2] == 4)){
									for (unsigned int k=(m-2); k>=1; k-=1){
										if (Sf_nl_4[k][n-2] == 4){
											Sf[k][n-2] = 4;
										}
									}
									show_field (Sf, m, n, gamemode, information_code, geben, Colored);
									printf("	Sieg:	Spieler 4 \n");
									controll = 1;
								}
							}
							if (controll == 1){
								break;
							}
						}
						controll = 0;
						
						num_1 = 0;
						for (unsigned int i=1; i<m-1; i+=1){
							for (unsigned int j=1; j<n-1; j+=1){
								if (Sf_nl_4[i][j] == 4){
									num_1 += 1;
								}
							}
						}		//printf("ok(1387)");	
					
						if (var_[4] == 42){
							for (unsigned int i=1; i<m-1; i+=1){
								for (unsigned int j=1; j<n-1; j+=1){
									if (gamemode == 8) {
										if (temp[i][j] == 4){
											Sf[i][j] = 0;
										}
									} else if ((gamemode == 9)||(gamemode == 10)||(gamemode == 11)||(gamemode == 12)) {	//mehr-gamemode
										if (temp[i][j] != 0){
											Sf[i][j] = temp[i][j];
										}
									} else if (gamemode == 6) {	//10
										if (temp[i][j] == 4){
											Sf[i][j] = 1;
										}
									}							
								}
							}
						}		//printf("ok(1398)");	
						// possible to modify
						
						controll = 0;
						if (gamemode == 1){	// possible to modify
							for (unsigned int erste=1; erste<n-1; erste+=1){		//printf("ok(1400)");		//Spiel-Ende?
								if (Sf[1][erste] == 4){
									printf("	Sieg:	Spieler 4 \n");
									show_field (Sf, m, n, gamemode, information_code, geben, Colored);
									controll = 1;		//printf("ok(1404)");
									break;
								}
							}
							if (controll == 1){
								break;		//printf("ok(1409)");
							}		//printf("ok(1410)");
						}
						controll = 0;
						
						Spielfeld_Destroy (temp, m);		//printf("ok(1412)");
					
						Sf_od_4 = old_dying_4 (Sf, m, n, d, e, gamemode, information_code);		//printf("ok(1414)");
						
						if (journey == 1){
							unsigned int journey_max;
							journey_max = 0;
							for (unsigned int i=1; i<m-1; i+=1){
								for (unsigned int j=1; j<n-1; j+=1){
									if (Sf_journey[i][j] == 4){
										journey_max += 1;
									}
								}
							}
							for (unsigned int i=1; i<m-1; i+=1){
								for (unsigned int j=1; j<n-1; j+=1){
									if ((Sf_od_4[i][j] == 404) && (Sf_journey[i][j] == 0) && (journey_max >= limit_at_all)){
										for (unsigned int u=(m-2); u>0; u-=1){
											for (unsigned int o=1; o<(n-1); o+=1){
												if ((Sf_journey[u][o] == 4)&&((u+o)%2 == 0)){
													Sf_journey[u][o] = 0;
													journey_max -= 1;
													if (journey_max < limit_at_all){
														break;
													}
												}
											}
											if (journey_max < limit_at_all){
												break;
											}
										}
										
									}
									if ((Sf_od_4[i][j] == 404) && (Sf_journey[i][j] == 0) && (journey_max < limit_at_all)){
										Sf_journey[i][j] = 4;
										journey_max += 1;
									}
								}
							}
							journey_max = 0;
						}
						
						if (var_[4] == 32){BB[3] += 1; Revive_4(m, n, Sf_od_4, Sf);}
						
						num_2 = 0;
						for (unsigned int i=1; i<m-1; i+=1){
							for (unsigned int j=1; j<n-1; j+=1){
								if (Sf_od_4[i][j] == 404){
									num_2 += 1;
								}
							}
						}
					
						count_new = 0;
						for (unsigned int i=1; i<m-1; i+=1){
							for (unsigned int j=1; j<n-1; j+=1){
								if (Sf_nl_4[i][j] == 4){
									count_new += 1;
								}
							}
						}
						ent = limit_new;		//printf("ok(1473)");
						
						for (unsigned int i=1; i<m-1; i+=1){
							for (unsigned int j=1; j<n-1; j+=1){
								if ((Sf[i][j] == 4) && (Sf_od_4[i][j] == 0)){
									zeitgewinner += 1;
								}
							}
						}
						
						if (count_new > limit_new){		//Abfrage auf max. 10 neue Steine
							/*if (gamemode == 1) {
								Sf_nl_4 = Index_4 (ent, count_new, m, n, Sf, Sf_nl_4, Sf_od_4, limit_new, limit_at_all, zeitgewinner);	
							} else if (gamemode == 2) {
								Sf_nl_4 = Index_4_col (ent, count_new, m, n, Sf, Sf_nl_4, Sf_od_4, limit_new, limit_at_all, zeitgewinner);	
							} else if (gamemode == 3) {
								Sf_nl_4 = Index_4_con (ent, count_new, m, n, Sf, Sf_nl_4, limit_new);
							} else if (gamemode == 4) {
								Sf_nl_4 = Index_4_fal (ent, count_new, m, n, Sf, Sf_nl_4, Sf_od_4, limit_new, limit_at_all, zeitgewinner);	
							} else if (gamemode == 5) {
								Sf_nl_4 = Index_4_fig (ent, count_new, m, n, Sf, Sf_nl_4, Sf_od_4, limit_new, limit_at_all, zeitgewinner);	
							} else if (gamemode == 7) {
								Sf_nl_4 = Index_4_race (ent, count_new, m, n, Sf, Sf_nl_4, Sf_od_4, limit_new, limit_at_all, zeitgewinner);	
							} else if (gamemode == 8) {
								Sf_nl_4 = Index_4_rain (ent, count_new, m, n, Sf, Sf_nl_4, Sf_od_4, limit_new, limit_at_all, rain, zeitgewinner);	
							}*/
							if (gamemode == 6) {
								Sf_nl_4 = Index_other_hunt (ent, count_new, m, n, Sf_nl_4, geben, zeitgewinner, Sf, limit_at_all);	
							} else if (gamemode == 9) {
								Sf_nl_4 = Index_are (ent, count_new, m, n, Sf_nl_4, Sf_od_4, limit_new, limit_at_all, zeitgewinner, Sf, w, d, e, geben);
							} else if (gamemode == 10) {
								count_new = 0;
							} else if (gamemode == 11) {
								Sf_nl_4 = Index_dyn (ent, count_new, m, n, Sf_nl_4, Sf_od_4, limit_new, limit_at_all, zeitgewinner, Sf, w, d, e, geben, position);
							} else if (gamemode == 12) {	//mehr-gamemode
								count_new = 0;
							}
						
						}
						ent = 0;
						count_new = 0;		//printf("ok(1478)");
					
						num_3 = 0;
						for (unsigned int i=1; i<m-1; i+=1){
							for (unsigned int j=1; j<n-1; j+=1){
								if (((Sf[i][j] == 4) && (Sf_od_4[i][j] == 0)) || (Sf_nl_4[i][j] == 4)){
									count_new += 1;
									num_3 += 1;
								}
							}
						}
						
						ent = limit_at_all;
						if ((gamemode == 1)||(gamemode == 2)||(gamemode == 4)||(gamemode == 5)||(gamemode == 7)||(gamemode == 8)) {
							
							if (var_[4] == 52){
											//printf("ok(1492)");
								lim = 0;
								for (unsigned int i=1; i<m-1; i+=1){
									for (unsigned int j=1; j<n-1; j+=1){
										if ((Sf[i][j] == 4) && (Sf_od_4[i][j] == 0)){
											lim += 1;
										}
									}
								}
											//printf("ok(1501)");
								ent = lim;
											//printf("ok(1503)");
								lim = 0;
								for (unsigned int i=1; i<m-1; i+=1){
									for (unsigned int j=1; j<n-1; j+=1){
										if (Sf[i][j] == 1){
											lim += 1;
										}
									}
								}			//printf("ok(1511)");
							
							
								if ((lim <= limit_new) && (ent < (limit_at_all - 1))){
									if (ent >= (limit_at_all - 3)){
										ent = limit_at_all - 1;
									} else if (ent >= (limit_at_all - 5)){
										ent = limit_at_all - 2;
									} else if (ent >= (limit_at_all - 7)){
										ent = limit_at_all - 3;
									} else if (ent >= (limit_at_all - 10)){
										ent = limit_at_all - 4;
									} else {
										ent = limit_at_all;
									}		//printf("ok(1523)");
								} else {		//printf("ok(1524)");
									ent = limit_at_all;
								}
								lim = 0;
											//printf("ok(1528)");
							}
						}	// possible to modify
						
						if (count_new > ent){		//Abfrage auf insgesamt max. 20 Steine, normalerweise
							/*if (gamemode == 1) {
								Sf_nl_4 = Index_4 (ent, count_new, m, n, Sf, Sf_nl_4, Sf_od_4, limit_new, limit_at_all, zeitgewinner);	
							} else if (gamemode == 2) {
								Sf_nl_4= Index_4_col  (ent, count_new, m, n, Sf, Sf_nl_4, Sf_od_4, limit_new, limit_at_all, zeitgewinner);	
							} else if (gamemode == 3) {
								count_new = 0;
							} else if (gamemode == 4) {
								Sf_nl_4 = Index_4_fal (ent, count_new, m, n, Sf, Sf_nl_4, Sf_od_4, limit_new, limit_at_all, zeitgewinner);	
							} else if (gamemode == 5) {
								Sf_nl_4 = Index_4_fig (ent, count_new, m, n, Sf, Sf_nl_4, Sf_od_4, limit_new, limit_at_all, zeitgewinner);	
							} else if (gamemode == 7) {
								Sf_nl_4 = Index_4_race (ent, count_new, m, n, Sf, Sf_nl_4, Sf_od_4, limit_new, limit_at_all, zeitgewinner);	
							} else if (gamemode == 8) {
								Sf_nl_4 = Index_4_rain (ent, count_new, m, n, Sf, Sf_nl_4, Sf_od_4, limit_new, limit_at_all, rain, zeitgewinner);	
							}*/
							if (gamemode == 6) {
								Sf_nl_4 = Index_other_hunt (ent, count_new, m, n, Sf_nl_4, geben, zeitgewinner, Sf, limit_at_all);	
							} else if (gamemode == 9) {
								Sf_nl_4 = Index_are (ent, count_new, m, n, Sf_nl_4, Sf_od_4, limit_new, limit_at_all, zeitgewinner, Sf, w, d, e, geben);	
							} else if (gamemode == 10) {
								count_new = 0;
							} else if (gamemode == 11) {
								Sf_nl_4 = Index_dyn (ent, count_new, m, n, Sf_nl_4, Sf_od_4, limit_new, limit_at_all, zeitgewinner, Sf, w, d, e, geben, position);
							} else if (gamemode == 12) {	//mehr-gamemode
								count_new = 0;
							}
						
						}
						ent = 0;
						zeitgewinner = 0;

						if (gamemode == 4) {
							touch (Sf, m, n, geben, Sf_nl_1, Sf_nl_2);	//possible to modify
						}
						
						Sf = change_4 (Sf, Sf_nl_4, Sf_od_4, m, n, gamemode, number_of_players, ges);
						
						if (gamemode == 1) {
							for (unsigned int j=1; j<n-1; j+=1){	//possible to modify
								if (Sf[2][j] == 2){
									B[0] += 1;
									break;
								}
							} 
						} else if (gamemode == 2) {	//possible to modify
							for (unsigned int j=2; j<n-1; j+=((n-1)/2)-2){		//collect-Bed. prüfen
								unsigned int b;
								b = 0;
								if (Sf[((m-1)/2)][j] == 7){
									if (Sf[((m-1)/2)-1][j]==2){b += 1;}
									if (Sf[((m-1)/2)+1][j]==2){b += 1;}
									if (Sf[(m-1)/2][j-1]==2){b += 1;}
									if (Sf[(m-1)/2][j+1]==2){b += 1;}
									if (b >= 3){
										B[0] += 1;
										Sf[((m-1)/2)][j] = 2;
									}
								}
							}
							if (B[0] == 2){
								printf("\n");
								printf("	Sieg: Spieler 2 \n");
								printf("\n");
								show_field (Sf, m, n, gamemode, information_code, geben, Colored);
								break;
							}
						}
						
						if ((gamemode == 6)&&(geben == number_of_players)) {
							lim = 1;
							printf("	\n");
							if (opague >= 1) {
								show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
							} else {
								show_field (Sf, m, n, gamemode, information_code, geben, Colored);
							}
							printf("	\n");
							while (lim == 1) {
								printf("	\n");
								printf("	\n");
								printf("	Are you ready to make your turn? \n");
								printf("	Yes: 1 \n");
								printf("	\n");
								printf("	\n");
								scanf("%u", &lim);
								
								if (lim != 1) {
									lim = 1;
								} else {
									lim = 0;
								}
							}
						}
						if (gamemode == 6) {
							information_code[3] = 0;
						}
						
						controll = 0;
						if (gamemode == 1) {	//possible to modify
							for (unsigned int erste=1; erste<n-1; erste+=1){		//Spiel-Ende?
								if (Sf[1][erste] == 2){
									printf("	Sieg:	Spieler 2 \n");
									controll = 1;
									break;
								}
							}
							if (controll == 1){
								break;
							}
						}
						controll = 0;
						
						if (gamemode == 3) {	//possible to modify
							if (opague >= 1) {
								show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
							} else {
								show_field (Sf, m, n, gamemode, information_code, geben, Colored);
							}
							battle (m, n, Sf, geben);
						}
						
						if (number_of_players == 4) {// gamemode 6 modify, done!
							if (var_[1] != 1010) {
								cons[4] = use_number;
								
								if (gamemode == 11) {	//mehr-gamemode
									for (unsigned int p=2; p<=5; p+=1) {
										
										dynamic_pointer_save[4][p-2] = dynamic_pointer[p];
										
									}
								}
								
							}
						} else if (number_of_players >= 5) {
							if (var_[5] != 1010) {
								cons[4] = use_number;
								
								if (gamemode == 11) {	//mehr-gamemode
									for (unsigned int p=2; p<=5; p+=1) {
										
										dynamic_pointer_save[4][p-2] = dynamic_pointer[p];
										
									}
								}
								
							}
						}
						
						use_number = random_number (num_1, num_2, num_3, use_number, g, var_, number_3, number_4);
						
						if ((opt != 5)&&(var_[4] <= 62)){
							controll_2 = 0;
							for (unsigned int z=var_[4]; z>2; z-=10){
								controll_2 += 1;
							}
							number_4 = controll_2;
							//printf("%u \n", number_4);
							controll_2 = 0;
						}
					}
				}	//{}ausfindig machen
			} else if (geben == 5) {		//following players
				
				if (opague >= 1) {
					Sf_opague = opague_builder (Sf, m, n, geben, opague, aop);
					
				}
				
				if ((ttt != 0)&&(pere[geben] == 100)) {
					g += 1;
					continue;
				}
				
				if ((gamemode == 10)&&(ulcer_start[5] == 0)) {
					if (opague >= 1) {
						show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
					} else {
						show_field (Sf, m, n, gamemode, information_code, geben, Colored);
					}
					g += 1;
					continue;
				}
				
				if ((ges[5] == 5050)&&((gamemode == 6)||(gamemode == 9)||(gamemode == 10)||(gamemode == 11)||(gamemode == 12))) {	//mehr-gamemode
					g+=1;
					var_[5] = 5050;
					cons[5] = cons[4];
					for (unsigned int i=1; i<m-1; i+=1){
						for (unsigned int j=1; j<n-1; j+=1){
							cons_field_5[i][j] = cons_field_4[i][j];
							if (journey == 1){
								cons_journey_5[i][j] = cons_journey_4[i][j];
								
								if (Sf_journey[i][j] == 5) {
									Sf_journey[i][j] = 0;
								}
							}
							if (gamemode == 11) {	//mehr-gamemode
								for (unsigned int p=2; p<=5; p+=1) {
									
									dynamic_pointer_save[5][p-2] = dynamic_pointer_save[4][p-2];
									
								}
							}
						}
					}
					if (var_[0] == 1) {
						g-=2;
					}
					continue;
				}
				
				w = 3;
				d = 2;
				e = 3;
				if (gamemode == 9) {
					if (ability[1] == geben) {
						w = 1;
						d = 0;
						e = 1;
						information_code[0] = 1;
					} else if (ability[2] == geben) {
						w = 2;
						d = 1;
						e = 2;
						information_code[0] = 2;
					} else if (ability[3] == geben) {
						w = 4;
						d = 1;
						e = 4;	//abweichende e-definition
						information_code[0] = 3;
					} else if (ability[4] == geben) {
						information_code[0] = 4;
					} else if (ability[5] == geben) {
						information_code[0] = 5;
					} else if (ability[6] == geben) {
						information_code[0] = 6;
					} else if (ability[7] == geben) {
						information_code[0] = 7;
					} else if (ability[8] == geben) {
						information_code[0] = 8;
					} else if (ability[9] == geben) {
						information_code[0] = 9;
						
						if (opague >= 1) {
							show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
						} else {
							show_field (Sf, m, n, gamemode, information_code, geben, Colored);
						}
						
						for (unsigned int i=1; i<m-1; i+=1){
							for (unsigned int j=1; j<n-1; j+=1){
								if (Sf[i][j] == geben) {
									if ((Sf[i+1][j] != 0)&&(Sf[i+1][j] != geben)&&((i+2) <= (m-2))) {
										if (Sf[i+2][j] == 0) {
											Sf[i+2][j] = Sf[i+1][j];
											Sf[i+1][j] = 0;
										}
									}
									if ((Sf[i-1][j] != 0)&&(Sf[i-1][j] != geben)&&((i-2) >= 1)) {
										if (Sf[i-2][j] == 0) {
											Sf[i-2][j] = Sf[i-1][j];
											Sf[i-1][j] = 0;
										}
									}
									if ((Sf[i][j-1] != 0)&&(Sf[i][j-1] != geben)&&((j-2) >= 1)) {
										if (Sf[i][j-2] == 0) {
											Sf[i][j-2] = Sf[i][j-1];
											Sf[i][j-1] = 0;
										}
									}
									if ((Sf[i][j+1] != 0)&&(Sf[i][j+1] != geben)&&((j+2) <= (n-2))) {
										if (Sf[i][j+2] == 0) {
											Sf[i][j+2] = Sf[i][j+1];
											Sf[i][j+1] = 0;
										}
									}
								}
							}
						}
					}
				}
				
				if (gamemode == 10) {
					w = 2;
					d = 1;
					e = 2;
				}
				
				if (gamemode == 9) {
					if (information_code[0] == 1) {
						limit_at_all = limit_at_all-2;
					} else if (information_code[0] == 2) {
						limit_at_all = limit_at_all-1;
					} else {
						limit_at_all = limit_at_all_saver;
					}
				}
				
				if (ttt != 0) {
					if ((pere[geben] != 0)&&(warning_system <= 5)&&((pere[geben]+warning_system) == 7)) {
						g += 1;
						printf(" \n ");
						printf("	You got a penalty. \n ");
						printf(" \n ");
						pere[geben] = 0;
						continue;
					} else if ((pere[geben] != 0)&&(warning_system != 0)&&(((warning_system <= 5)&&((pere[geben]+warning_system) == 8))||((warning_system == 6)&&(pere[geben] == 1)))) {
						Sf_od_5 = old_dying_5 (Sf, m, n, d, e, gamemode, information_code);
						Sf = change_5 (Sf, Sf_nl_5, Sf_od_5, m, n, gamemode, number_of_players, ges); 	//Change befreit
						g += 1;
						printf(" \n ");
						printf("	You got a penalty. \n ");
						printf(" \n ");
						pere[geben] = 0;
						continue;
					} else if (((warning_system <= 5)&&((warning_system + pere[geben]) >= 9))||((warning_system >= 6)&&((warning_system + pere[geben]) >= 8))) {
						printf("	Niederlage: Spieler 5 \n ");
						for (unsigned int i=1; i<m-1; i+=1){
							for (unsigned int j=1; j<n-1; j+=1){
								if (Sf[i][j] == 5) {
									Sf[i][j] = 0;
								}
							}
						}
						ges[5] = 5050;
						player_counter += 1;
						pere[geben] = 100;
						g += 1;
						continue;
					}
				}
				
				if (var_[geben] == 1010) {
					use_number = cons[geben];
					if (opt == 5) {
					
						printf("	Player %u ,do you want to keep your number (%u) or do you want to get the next one? \n", geben, cons[geben]);
						printf("	Keep the number: 	1 \n");
						printf("	Get the next one:	2 \n");
						scanf("%u", &lim);
						
						if (lim == 2) {
							use_number = random_number (num_1, num_2, num_3, use_number, g, var_, number_3, number_4);
						} else if (lim != 1) {
							printf("	Well, you keep your number, but next time please take an option i offered. \n\n");
						}
						lim = 0;
					
					}
				}
				
				if (var_[geben%number_of_players+1] == 1010){		//geben%number_of_players+1 ist der Nachfolger von geben.
					if (tac != 0) {
						if (number_5 <= 5){
							CCC[number_5] += 1;
						} else if (number_5 == 6){
							CCC[0] += 1;
						}
					} else if (opt == 5) {
						AAA[use_number] -= 1;
					} else {
						AAA[number_5] -= 1;
					}
					
				}
				
				if ((tac != 0)&&((CCC[1]+CCC[2]+CCC[3]+CCC[4]+CCC[5]+CCC[0]) == 0)){
					for (unsigned int p=0; p<=5; p+=1){
						CCC[p] = tac;
					}
				}
				
				menuoperator = 1;
				
				
				while (menuoperator != 0) {
						
					if (gamemode != 8) {
						if (opague >= 1) {
							show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
						} else {
							show_field (Sf, m, n, gamemode, information_code, geben, Colored);
						}
					}
					
					if ((gamemode == 6)&&(((scwhp == 1)&&((opt == 0)||((use_number == 2)||(use_number == 3)||(use_number == 4)))&&((tac == 0)||((CCC[2] != 0)||(CCC[3] != 0)||(CCC[4] != 0))))||(scwhp == 2))) {
						
						information_code[3] = 1;
						
						if (opague >= 1) {
							show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
						} else {
							show_field (Sf, m, n, gamemode, information_code, geben, Colored);
						}
					}
					
					if (gamemode == 4) {
						printf("\n");
						printf("	Points player 5: 	%u Point(s) \n", P[geben]);
					}	// possible to modify
					
					if (gamemode == 10) {
						printf("\n");
						printf("	Lifes player 5: 	%u Life(s) \n", ulcer_lifes[5]);
					}
					
					if (gamemode == 11) {
						printf("	\n");
						printf("	Geschwindigkeit: 	Zeile: %d, 	Spalte: %d \n", dynamic_pointer[2], dynamic_pointer[3]);
						printf("	Beschleunigung: 	Zeile: %d, 	Spalte: %d \n", dynamic_pointer[4], dynamic_pointer[5]);
						printf("	\n");
					}
					
					printf("\n");
					
					if (Colored[0] == 1) {
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+Colored[geben]);
					}
					
					if ((gamemode != 6)&&(gamemode != 9)&&(gamemode != 10)&&(gamemode != 11)&&(gamemode != 12)){	//mehr-gamemode
						printf("	Am Zug: Spieler 2 (OO)	\n");	// possible to modify
					} else if (gamemode == 6) {
						printf("	Am Zug: Spieler 5 (DD)	\n");
					} else if (gamemode == 9) {
						if (ability[1] == geben) {
							printf("	Am Zug: Spieler 5 (UU)	\n");
						} else if (ability[2] == geben) {
							printf("	Am Zug: Spieler 5 (LL)	\n");
						} else if (ability[3] == geben) {
							printf("	Am Zug: Spieler 5 (AA)	\n");
						} else if (ability[4] == geben) {
							printf("	Am Zug: Spieler 5 (CC)	\n");
						} else if (ability[5] == geben) {
							printf("	Am Zug: Spieler 5 (II)	\n");
						} else if (ability[6] == geben) {
							printf("	Am Zug: Spieler 5 (SS)	\n");
						} else if (ability[7] == geben) {
							printf("	Am Zug: Spieler 5 (PP)	\n");
						} else if (ability[8] == geben) {
							printf("	Am Zug: Spieler 5 (HH)	\n");
						} else if (ability[9] == geben) {
							printf("	Am Zug: Spieler 5 (EE)	\n");
						}
					} else if ((gamemode == 10)||(gamemode == 11)||(gamemode == 12)) {	//mehr-gamemode
						printf("	Am Zug: Spieler 5 (55)	\n");
					}
					
					if (Colored[0] == 1) {
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+7);
					}
					
					printf("\n");
					
					if (tac != 0){
						printf("	Your stack of numbers:	\n	1) [%u],		2) [%u],		3) [%u], \n\n	4) [%u],		5) [%u],		6) [%u],\n", CCC[1], CCC[2], CCC[3], CCC[4], CCC[5], CCC[0]);
						printf("\n");
						printf("\n");
					}
					
					if (opt == 5){		//random number
						printf("	Your number: %u ", use_number);
						printf("\n");
						printf("\n");
						
					}
					
					printf("	1) Plus:	11	Minus: 	12 \n");
					printf("	2) Move:	21	Change: 22 \n");
					printf("	3) Destroy:	31	Revive: 32 \n");
					printf("	4) Move:	41	Boost: 	42 \n");
					if (((gamemode != 9)&&(gamemode != 10))||((gamemode == 10)&&(geben == 1))) {
						printf("	5) 4/5-new:	51	2-new:	52 \n");
						printf("	6) 4-max:	61	1-min:	62 \n");
					} else if (gamemode == 9) {
						if (information_code[0] == 1) {
							printf("	5) 2/3-new:	51	0-new:	52 \n");
							printf("	6) 2-max:	61	-1-min:	62 \n");
						} else if (information_code[0] == 2) {
							printf("	5) 3/4-new:	51	1-new:	52 \n");
							printf("	6) 3-max:	61	0-min:	62 \n");
						} else if (information_code[0] == 3) {
							printf("	5) 5/6-new:	51	3-new:	52 \n");
							printf("	6) 5-max:	61	0-min:	62 \n");
						} else {
							printf("	5) 4/5-new:	51	2-new:	52 \n");
							printf("	6) 4-max:	61	1-min:	62 \n");
						}
					} else if ((gamemode == 10)&&(geben != 1)) {
						printf("	5) 3/4-new:	51	1-new:	52 \n");
						printf("	6) 3-max:	61	0-min:	62 \n");
					}
					printf("							\n");
					printf("		Go back: 100 \n");
					printf("		Menu: 10 \n");
					printf("		End game: 0 \n");
					if ((ttt != 0)&&(time_saver == 0.0)) {
						time1 = time(NULL);
					}
					scanf("%u", &var_[5]);
					
					if (var_[5] == 10){
						if (ttt != 0) {
							time3 = time(NULL);
						}
						while (menuoperator != 7) {
							printf("\n");
							printf("\n");
							printf("	About the game: 1 \n	Statistics: 2 \n	The numbers: 3 \n	The limits: 4 \n	Get Hints: 5 \n	Suprise: 6 \n	Quit Menu: 7 \n");
							scanf("%u", &menuoperator);
							
							if (menuoperator == 1){
								if (gamemode == 1) {
									printf("	How to win? 	Own a square on your last line or force your opponent to lose all his/her ones.\n");
								} else if (gamemode == 2) {
									printf("	How to win? 	Be at 2 of the 3 targets with three of your squares near-by.\n");
								} else if (gamemode == 3) {
									printf("	How to win? 	Take over all your opponent's squares by winning contact-battles.\n");
									printf("	Contact-battles? 	All near-by squares in a row with the contact-square build a chain, beat your opponent in the length.\n");
								} else if (gamemode == 4) {
									printf("	How to win? 	Get more points than your opponent.\n");
									printf("	Note:	Touch the #-square in the near-by to move it to the opposite side. \n");
								} else if (gamemode == 5) {
									printf("	How to win? 	Force your opponent to lose all his/her squares.\n");
								} else if (gamemode == 6) {
									if (geben == 1) {
										printf("	How to win? 	Protect your heart-block so no enemy can touch it.\n");
									} else {
										printf("	How to win? 	Catch the heart-block of the hunted one before it disappears.\n");
									}
								} else if (gamemode == 7) {
									printf("	How to win? 	Reach the end of the field or force your opponent to lose all his/her ones.\n");
									printf("	Note:	Every %u turns in total the #-line will go ahead and destroys everything in it's way.\n Also you are not allowed to cross the mid-line. \n", freq);
								} else if (gamemode == 8) {
									printf("	How to win? 	Reach [1][7] of the field or force your opponent to lose all his/her squares.\n");
									printf("	Note:	Falling down the #-squares will push, destroy, explode, or teleport, transform into yours by contact. \n");
								} else if ((gamemode == 9)||(gamemode == 10)) {
									printf("	How to win? 	Force your opponent to lose all his/her squares while keeping yours alive.\n");
								} else if (gamemode == 11) {
									printf("	How to win? 	Push the ball against your opponent's side.\n");
								} else if (gamemode == 12) {	//mehr-gamemode
									printf("	How to win? 	Stay alive.\n");
								}
								printf("	Surrounding:	The 8 squares around another, at the edge 5, in the corners 3, are called #surrounding. \n");
								printf("	near-by:	The 4 squares around another, at the edge 3, in the corners 2, are called #near-by. \n");
								printf("	Standard actions:	(After your choice of number and not influencing each other) \n	-Development:	If it is your turn and a free square has exactly 3 of yours surrounding it, you will own it.\n");
								printf("	-Losses: 	If it is your turn and a square of yours is surrounded by less than %u or more than %u of yours,\n			it will be set free.\n", d, e);
								if ((gamemode == 10)||(gamemode == 12)) {	//mehr-gamemode
									printf("	Limits: 	This gamemode is unlimited. \n");
								} else if (gamemode == 3) {
									printf("	Limits: 	Your development is limited by %u per round. \n", limit_new);
								} else {
									printf("	Limits: 	Your development is limited by %u per round, your units in total by %u per round. \n", limit_new, limit_at_all);
								}
							}
							
							if (menuoperator == 2){
								printf("\n");
								printf("	turns at all: %u \n", g);
								printf("\n");
								printf("	Numbers of player 1: \n");
								printf("		#1 = %u \n", A[1]);
								printf("		#2 = %u \n", A[2]);
								printf("		#3 = %u \n", A[3]);
								printf("		#4 = %u \n", A[4]);
								printf("		#5 = %u \n", A[5]);
								printf("		#6 = %u \n", A[6]);
								printf("\n");
								if (number_of_players >= 2) {	//mehr-gamemode
									printf("	Numbers of player 2: \n");
									printf("		#1 = %u \n", B[1]);
									printf("		#2 = %u \n", B[2]);
									printf("		#3 = %u \n", B[3]);
									printf("		#4 = %u \n", B[4]);
									printf("		#5 = %u \n", B[5]);
									printf("		#6 = %u \n", B[6]);
									printf("\n");
								}
								if (number_of_players >= 3){	//mehr-gamemode
									printf("	Numbers of player 3: \n");
									printf("		#1 = %u \n", AA[1]);
									printf("		#2 = %u \n", AA[2]);
									printf("		#3 = %u \n", AA[3]);
									printf("		#4 = %u \n", AA[4]);
									printf("		#5 = %u \n", AA[5]);
									printf("		#6 = %u \n", AA[6]);
									printf("\n");
								}
								if (number_of_players >= 4){
									printf("	Numbers of player 4: \n");
									printf("		#1 = %u \n", BB[1]);
									printf("		#2 = %u \n", BB[2]);
									printf("		#3 = %u \n", BB[3]);
									printf("		#4 = %u \n", BB[4]);
									printf("		#5 = %u \n", BB[5]);
									printf("		#6 = %u \n", BB[6]);
									printf("\n");
								}
								if (number_of_players >= 5){
									printf("	Numbers of player 5: \n");
									printf("		#1 = %u \n", AAA[1]);
									printf("		#2 = %u \n", AAA[2]);
									printf("		#3 = %u \n", AAA[3]);
									printf("		#4 = %u \n", AAA[4]);
									printf("		#5 = %u \n", AAA[5]);
									printf("		#6 = %u \n", AAA[6]);
									printf("\n");
								}
								if (number_of_players >= 6){
									printf("	Numbers of player 6: \n");
									printf("		#1 = %u \n", BBB[1]);
									printf("		#2 = %u \n", BBB[2]);
									printf("		#3 = %u \n", BBB[3]);
									printf("		#4 = %u \n", BBB[4]);
									printf("		#5 = %u \n", BBB[5]);
									printf("		#6 = %u \n", BBB[6]);
									printf("\n");
								}
								if (number_of_players >= 7){
									printf("	Numbers of player 7: \n");
									printf("		#1 = %u \n", AAAA[1]);
									printf("		#2 = %u \n", AAAA[2]);
									printf("		#3 = %u \n", AAAA[3]);
									printf("		#4 = %u \n", AAAA[4]);
									printf("		#5 = %u \n", AAAA[5]);
									printf("		#6 = %u \n", AAAA[6]);
									printf("\n");
								}
								if (number_of_players >= 8){
									printf("	Numbers of player 8: \n");
									printf("		#1 = %u \n", BBBB[1]);
									printf("		#2 = %u \n", BBBB[2]);
									printf("		#3 = %u \n", BBBB[3]);
									printf("		#4 = %u \n", BBBB[4]);
									printf("		#5 = %u \n", BBBB[5]);
									printf("		#6 = %u \n", BBBB[6]);
									printf("\n");
								}
								if (number_of_players == 9){
									printf("	Numbers of player 9: \n");
									printf("		#1 = %u \n", AAAAA[1]);
									printf("		#2 = %u \n", AAAAA[2]);
									printf("		#3 = %u \n", AAAAA[3]);
									printf("		#4 = %u \n", AAAAA[4]);
									printf("		#5 = %u \n", AAAAA[5]);
									printf("		#6 = %u \n", AAAAA[6]);
									printf("\n");
								}
								
								if ((gamemode == 1)||(gamemode == 6)||(gamemode == 7)||(gamemode == 8)) {
									printf("	Matchballs player 1: 	%u \n", A[0]);
									printf("	Matchballs player 2: 	%u \n", B[0]);
									if (gamemode == 6) {
										if (number_of_players >= 3){printf("	Matchballs player 3: 	%u \n", AA[0]);}
										if (number_of_players >= 4){printf("	Matchballs player 4: 	%u \n", BB[0]);}
										if (number_of_players >= 5){printf("	Matchballs player 5: 	%u \n", AAA[0]);}
										if (number_of_players >= 6){printf("	Matchballs player 6: 	%u \n", BBB[0]);}
										if (number_of_players >= 7){printf("	Matchballs player 7: 	%u \n", AAAA[0]);}
										if (number_of_players >= 8){printf("	Matchballs player 8: 	%u \n", BBBB[0]);}
										if (number_of_players == 9){printf("	Matchballs player 9: 	%u \n", AAAAA[0]);}
									}
								} else if (gamemode == 2) {
									printf("	Squares collected by player 1: 	%u \n", A[0]);
									printf("	Squares collected by player 2: 	%u \n", B[0]);
								} else if (gamemode == 3) {
									printf("	Times with squares <= 5, player 1: 	%u \n", A[0]);
									printf("	Times with squares <= 5, player 2: 	%u \n", B[0]);
								} else if (gamemode == 4) {
									printf("	Points player 1: 		%u \n", P[1]);
									printf("	Points Player 2: 		%u \n", P[2]);
									printf("	Turns with more points player 1: 	%u \n", A[0]);
									printf("	Turns with more points player 2: 	%u \n", B[0]);
									printf("	Number of not decided #-squares: 	%u \n", P[0]);
								} else if (gamemode == 3) {
									printf("	Times with squares < 5, player 1: 	%u \n", A[0]);
									printf("	Times with squares < 5, player 2: 	%u \n", B[0]);
								} else if (gamemode == 9) {
									printf("	Number of excluded abilites: 	%u \n", exclude_counter);
									printf("	Offensive abilities taken: 	%u \n", number_of_players-ability[0]);
									printf("	Defensive abilities taken: 	%u \n", ability[0]);
								} else if (gamemode == 10) {
									for (unsigned int p=1; p<=number_of_players; p+=1) {
										printf("		Spieler %u: %u life(s) left.\n", p, ulcer_lifes[p]);
									}
								} else if (gamemode == 11) {	//mehr-gamemode
									for (unsigned int p=1; p<=number_of_players; p+=1) {
										if ((ges[p] > 1000)||(ges[p] == 0)) {
											printf("	Spieler %u: is out.\n", p);
										} else if (ges[p] < 1000) {
											printf("	Spieler %u: You own %u squares.\n", p, ges[p]);
										}
									}
								} else if (gamemode == 12) {
									for (unsigned int p=1; p<=number_of_players; p+=1) {
										if ((ges[p] > 1000)||(ges[p] == 0)) {
											printf("	Spieler %u: is out.\n", p);
										} else if (ges[p] < 1000) {
											printf("	Spieler %u: You own %u squares.\n", p, ges[p]);
										}
									}
								}
								
								if (ttt != 0) {
									printf("	Number of penalties given until	now: %u \n", pere[0]);
								}
							}
							
							if (menuoperator == 3){
								if ((gamemode != 10)&&(gamemode != 12)) {
									printf("	Plus: Change a free square in the surrounding of yours in one of yours.\n");
								} else {
									printf("	Plus: Change a square in the surrounding of yours in one of yours.\n");
								}
								printf("	Minus: Delete one of your squares.\n");
								printf("	Move: The position of one of yours will change with a free, near-by square.\n");
								printf("	Revive: Your lost squares having no living squares of yours surrounding them at the beginning of your turn,\n		will be revived.\n");
								printf("	%u/%u-new: A free square has to be surrounded by %u or %u of yours during the development.\n", w+1, w+2, w+1, w+2);
								printf("	%u-new: A free square has to be surrounded by %u of yours during the development.\n", d, d);
								printf("	%u-max: A square of yours will survive even by %u of your squares surrounding it.\n", e+1, e+1);
								if (d == 0) {
									printf("	-1-min: A square of yours will survive even by only -1 of your squares surrounding it.\n");
								} else {
									printf("	%u-min: A square of yours will survive even by only %u of your squares surrounding it.\n", d-1, d-1);
								}
								
								if ((gamemode == 1)||(gamemode == 2)||(gamemode == 4)||(gamemode == 5)||(gamemode == 7)||(gamemode == 9)||(gamemode == 10)) {
									printf("	Change: A square of yours and a near-by square of your enemy will change positions.\n");
									printf("	Destroy: Delete a near-by square of your enemy.\n");
									printf("	Boost: Use all near-by squares of your enemy as your own for the development.\n");
									
								} else if (gamemode == 3) {
									
									printf("	Change: A square of yours and a square of your enemy in the surrounding will change positions.\n");
									printf("	Destroy: Delete a surrounding square of your enemy.\n");
									printf("	Boost: Use all surrounding squares of your enemy as your own for the development.\n");
									
								} else if (gamemode == 8) {
									printf("	Change: A square of yours and a near-by #-square will change positions.\n");
									printf("	Destroy: Delete a square of your enemy, but not in the last two lines.\n");
									printf("	Boost: Use all near-by #-squares as your own for the development.\n");
									
								} else if (gamemode == 6) {
									if (geben == 1) {
										printf("	Change: The heart-block and a square of yours will change positions.\n");
										printf("	Destroy: Delete a square of your enemy.\n");
										printf("	Boost: Touching the heart_block no square of yours can die.\n");
									} else {
										printf("	Change: A square of yours and a near-by square of the hunted one will change positions.\n");
										printf("	Destroy: Delete a near-by square of your enemy.\n");
										printf("	Boost: Use all near-by squares of the hunted one as your own for the development.\n");
									}
									
								} else if (gamemode == 11) {	//mehr-gamemode
									printf("	Change: A square of yours and a near-by square of your enemy or the near-by ball will change positions.\n");
									printf("	Destroy: Delete a near-by square of your enemy.\n");
									printf("	Boost: Use all near-by squares of your enemy and the near-by ball as your own for the development.\n");
								} else if (gamemode == 12) {
									printf("	Change: A square of yours and a near-by square of your enemy or a near-by object will change positions.\n");
									printf("	Destroy: Delete a near-by square of your enemy or a near-by object.\n");
									printf("	Boost: Use all near-by squares of your enemy and near-by objects as your own for the development.\n");
								}
								
								printf("\n");
							}
							
							if (menuoperator == 4){	//mehr-gamemode
								if ((gamemode != 10)&&(gamemode != 12)) {
									printf("	Limit of development:	%u \n", limit_new);
									if (gamemode != 3) {
										printf("	Limit in total:		%u \n", limit_at_all);
										printf("	Limit in total with >2-new< taken: %u -0/-1/-2/-3/-4.\n", limit_at_all);
									}
								}
							}
							
							if (menuoperator == 5){
								Spielfeld hint;
								unsigned int b, a;
								hint = Spielfeld_Create (m, n);
								printf("	New: 1 \n	Dying: 2 \n	Both: 3 \n");
								scanf("%u", &menuoperator);
								
								for (unsigned int i=1; i<(m-1); i+=1){
									for (unsigned int j=1; j<(n-1); j+=1){
										if ((gamemode != 6)&&(gamemode != 9)&&(gamemode != 10)&&(gamemode != 11)&&(gamemode != 12)){	//mehr-gamemode
											if (Sf[i][j] == geben){
												hint[i][j] = geben;
											} else if (Sf[i][j] == (geben%2)+1){
												hint[i][j] = (geben%2)+1;
											} else if (Sf[i][j] == 7){
												hint[i][j] = 7;
											} 
										} else if ((gamemode == 6)||(gamemode == 9)||(gamemode == 10)) {	//10
											if (Sf[i][j] == geben){
												hint[i][j] = geben;
											} else if (Sf[i][j] != 0){
												hint[i][j] = 17;
											}
										} else if (gamemode == 11) {
											if (Sf[i][j] == geben){
												hint[i][j] = geben;
											} else if (Sf[i][j] == 77){
												hint[i][j] = 77;
											} else if (Sf[i][j] != 0){
												hint[i][j] = 17;
											}
										} else if (gamemode == 12) {	//mehr-gamemode
											if (Sf[i][j] == geben){
												hint[i][j] = geben;
											} else if (Sf[i][j] == 81){
												hint[i][j] = 81;
											} else if (Sf[i][j] == 82){
												hint[i][j] = 82;
											} else if (Sf[i][j] == 83){
												hint[i][j] = 83;
											} else if (Sf[i][j] == 84){
												hint[i][j] = 84;
											} else if (Sf[i][j] == 75){
												hint[i][j] = 75;
											} else if (Sf[i][j] == 71){
												hint[i][j] = 71;
											} else if (Sf[i][j] != 0){
												hint[i][j] = 17;
											}
										}
									}
								}
								
								if ((menuoperator == 2)||(menuoperator == 3)){
									for (unsigned int i=1; i<(m-1); i+=1){
										for (unsigned int j=1; j<(n-1); j+=1){
											if (Sf[i][j] == geben){
												a = 0;
												for (unsigned int h=(i-1); h<=(i+1); h+=1){
													for (unsigned int k=(j-1); k<=(j+1); k+=1){
														if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
															if (Sf[h][k] == geben){
																a += 1;
															}
														}
													}
												}
												if ((a > 4) || (a < 3)){
													hint[i][j] = 16;
												}
											}
										}
									}
								}
								
								if ((menuoperator == 1)||(menuoperator == 3)){
									for (unsigned int i=1; i<(m-1); i+=1){
										for (unsigned int j=1; j<(n-1); j+=1){
											if (Sf[i][j] == 0){
												b = 0;
												for (unsigned int h=(i-1); h<=(i+1); h+=1){
													for (unsigned int k=(j-1); k<=(j+1); k+=1){
														if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
															if (Sf[h][k] == geben){
																b += 1;
															}
														}
													}
												}
												if (b == 3){
													hint[i][j] = 15;
												}
											}
										}
									}
								}
								
								if (opague >= 1) {
									Sf_opague = opague_builder (hint, m, n, geben, opague, aop);
								}
								
								if (opague >= 1) {
									show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
								} else {
									show_field (hint, m, n, gamemode, information_code, geben, Colored);
								}
								
								if (opague >= 1) {
									Sf_opague = opague_builder (Sf, m, n, geben, opague, aop);
								}
								
								menuoperator = 1;
								Spielfeld_Destroy (hint, m);
							}
							// 2
							if (menuoperator == 6){
								if (suprise == 0) {
									for (unsigned int i=1; i<m-1; i+=1){
										for (unsigned int j=1; j<n-1; j+=1){
											cons_field_5[i][j] = Sf[i][j];
											
											if (journey == 1){
												cons_journey_5[i][j] = Sf_journey[i][j];
											}
										}
									}
									sup_num = use_number;
								}
								
								while (menuoperator != 1) {
						
									printf("	Creator menu. 	Change number: 1	Suprise: 2	Suprise undo: 3	Back: 4 \n");
									scanf ("%u", &lim);
									if (lim == 1){
										printf("	number = ? \n");
										scanf ("%u", &use_number);
									} else if (lim == 2){
								
										printf("\n");
										scanf("%u", &suprise);
								
										if (suprise == 31){
											for (unsigned int i=2; i<m-2; i+=1){
												for (unsigned int j=1; j<n-1; j+=1){
													if (Sf[i][j] != 0){
														if (Sf[i][j] == 1){
															Sf[i][j] = 5;
														} else if (Sf[i][j] == 5){
															Sf[i][j] = 1;
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
								
										if(suprise == 13){
											for (unsigned int i=1; i<m-1; i+=1){
												for (unsigned int j=1; j<n-1; j+=1){
													if (Sf[i][j] == 5){
														Sf[i][j] = 0;
													}
													if (i == (m-2)){
														Sf[m-2][j] = 5;
													}
												}
											}
										}
								
									} else if (lim == 3){
										for (unsigned int i=1; i<m-1; i+=1){
											for (unsigned int j=1; j<n-1; j+=1){
												Sf[i][j] = cons_field_5[i][j];
												
												if (journey == 1){
													Sf_journey[i][j] = cons_journey_5[i][j];
												}
											}
										}
										use_number = sup_num;
									} else if (lim == 4){
										menuoperator = 1;
									} else {
										printf("	Invalid comment");
									}
								}
							}
						}	// menuoperator = 7
						
						if (gamemode == 8) {
							if (opague >= 1) {
								show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
							} else {
								show_field (Sf, m, n, gamemode, information_code, geben, Colored);
							}	//show_field über menuoperator = 7 und stack und so löschen, (verschiebe menuoperator!=0 - Schleife), done
							
							printf("\n");
						
						}
						
						if (ttt != 0) {
							time4 = time(NULL);
							time_saver += difftime(time4, time3);
						}
					}	//Menu-end
					
					menuoperator = 0;
					if (var_[5] == 10) {
						menuoperator = 1;
						var_[5] = 5;
					}
					
					if ((tac != 0)&&(var_[5] <= 62)&&(var_[5] > 10)){
						unsigned int tac_controll;
						tac_controll = 0;
						if (((var_[5]%10) > 2)||((var_[5]%10) == 0)){
							var_[5] = 7;
							menuoperator = 1;
						} else {
							for (unsigned int z=var_[5]; z>2; z-=10){
								tac_controll += 1;
							}
							if (tac_controll == 6){
								tac_controll = 0;
							}
							if (CCC[tac_controll] == 0){
								var_[5] = 7;
								menuoperator = 1;
							} else {
								CCC[tac_controll] -= 1;
							}
						}
					} else if ((tac != 0)&&(var_[5] != 100)&&(var_[5] != 1010)&&(var_[5] != 0)) {
						var_[5] = 7;
					}		
					//tac-mode
					
					if (opt == 5){
						controll_1 = 10+use_number;
						controll_2 = 11+use_number;
					
						for (unsigned int i=0; i<use_number-1; i+=1){
							controll_1 += 9;
							controll_2 += 9;
						}
					
						if (var_[5] == 0){
							controll_1 = 0;
							controll_2 = 0;
						}
						if (var_[5] == 100){
							controll_1 = 100;
							controll_2 = 100;
						}
						if (var_[5] == 1010){
							controll_1 = 1010;
							controll_2 = 1010;
						}
					}
					//
					if (((var_[5] > 0)&&(var_[5] < 10))||(((opt == 5)&&(var_[5] != controll_1))&&((opt == 5)&&(var_[5] != controll_2)))){
						
						if (var_[5] != 5) {
							printf("	You made a mistake, try again: \n");
							printf("\n");
							printf("\n");
						} else {
							printf("	You closed the menu. \n");
							printf("\n");
							printf("\n");
						}
						
						//enough
						
						menuoperator = 1;
					}
					
				}		// menuoperator = 0
				
				
				suprise = 0;
				
				if (var_[5] == 0){
					printf("	Do you really want to end the game ? \n");
					printf("	Yes: 0		No: 1 \n");
					scanf("%u", &lim);
					if (lim == 0){
						break;
					} else if (lim == 1){
						continue;
					} else {
						printf("	0 or 1, it is so difficult to understand? \n");
						printf("	Well, it seems I have to end it by myself... \n");
						break;
					}	
				} else {
					
					if (var_[5] == 100){		//gamemode 6 modify, done
						
						var_[0] = 1;
						
						for (unsigned int i=1; i<m-1; i+=1){
							for (unsigned int j=1; j<n-1; j+=1){
								Sf[i][j] = cons_field_4[i][j];
								
								if (journey == 1){
									Sf_journey[i][j] = cons_journey_4[i][j];
								}
							}
						}
						
						if (opague >= 1) {
							Sf_opague = opague_builder (Sf, m, n, geben, opague, aop);
						}
						
						if (opague >= 1) {
							show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
						} else {
							show_field (Sf, m, n, gamemode, information_code, geben, Colored);
						}
						
						cons[geben] = use_number;
						
						use_number = cons[4];
						
						if (gamemode == 11) {	//mehr-gamemode
							for (unsigned int p=2; p<=5; p+=1) {
								
								dynamic_pointer[p] = dynamic_pointer_save[4][p-2];
								
							}
						}
						
						g-=1;
						var_[5] = 1010;
						if (gamemode == 10) {
							ulcer_lifes[5] += 1;
							ulcer_start[5] = 0;
						}
						continue;
					} else {
						
						if (number_of_players == 5) {
							
							if (var_[1] != 1010){
								for (unsigned int i=1; i<m-1; i+=1){
									for (unsigned int j=1; j<n-1; j+=1){
										cons_field_5[i][j] = Sf[i][j];
										
										if (journey == 1){
											cons_journey_5[i][j] = Sf_journey[i][j];
										}
									}
								}
							}
						} else if (number_of_players >= 6) {
							if (var_[6] != 1010){
								for (unsigned int i=1; i<m-1; i+=1){
									for (unsigned int j=1; j<n-1; j+=1){
										cons_field_5[i][j] = Sf[i][j];
										
										if (journey == 1){
											cons_journey_5[i][j] = Sf_journey[i][j];
										}
									}
								}
							}
						}
						
						var_[0] = 0;
						
						if (var_[5] < 50){
							
							if (var_[5] == 11){AAA[1] += 1; Plus (m, n, geben, Sf, limit_at_all, gamemode, information_code, number_of_players, Colored, opague, Sf_opague);}
							if (var_[5] == 12){AAA[1] += 1; Minus (m, n, geben, Sf, gamemode, information_code, Colored, opague, Sf_opague);}
							if (var_[5] == 21){AAA[2] += 1; Move (m, n, geben, Sf, gamemode, information_code, Colored, opague, Sf_opague);}
							if (var_[5] == 41){AAA[4] += 1; Move (m, n, geben, Sf, gamemode, information_code, Colored, opague, Sf_opague);}
							if (var_[5] == 22){AAA[2] += 1; Change (m, n, geben, Sf, gamemode, information_code, Colored, opague, Sf_opague, position);}
							if (var_[5] == 31){AAA[3] += 1; Destroy (m, n, geben, Sf, gamemode, information_code, Colored, opague, Sf_opague);}
							if (var_[5] == 42){
								AAA[4] += 1; 
								Boost (geben, Sf, m, n, temp, gamemode);
							}
						} else {
							if (var_[5] == 51){AAA[5] += 1; w += 1;}		//w
							if (var_[5] == 52){AAA[5] += 1; w -= 1;}		//w
							if (var_[5] == 61){AAA[6] += 1; e += 1;}		//e
							if (var_[5] == 62){AAA[6] += 1; if (d != 0) {d -= 1;} else {d = 10;}}		//d
						}		//printf("ok(1376)");
						
						if (ttt != 0) {
							time2 = time(NULL);
							time_warning = ((difftime(time2, time1)) - time_saver);
							
							//printf("	time_warning: %f \n", time_warning);		//test
							
							if ((pere[geben] != 0)&&((pere[geben] + warning_system) <= 6)) {
								if (pere[geben] == 1) {
									if (warning_system <= 2) {
										time_warning += 1.0;
									} else if (warning_system == 3) {
										time_warning += 2.0;
									} else if (warning_system == 4) {
										time_warning += 3.0;
									} else if (warning_system == 5) {
										time_warning += 5.0;
									}
								} else if (pere[geben] == 2) {
									if (warning_system == 1) {
										time_warning += 2.0;
									} else if (warning_system == 2) {
										time_warning += 3.0;
									} else if (warning_system == 3) {
										time_warning += 5.0;
									} else if (warning_system == 4) {
										time_warning += 6.0;
									}
								} else if (pere[geben] == 3) {
									if (warning_system == 1) {
										time_warning += 3.0;
									} else if (warning_system == 2) {
										time_warning += 5.0;
									} else if (warning_system == 3) {
										time_warning += 8.0;
									}
								} else if (pere[geben] == 4) {
									if (warning_system == 1) {
										time_warning += 4.0;
									} else if (warning_system == 2) {
										time_warning += 7.0;
									}
								} else if (pere[geben] == 5) {
									if (warning_system == 1) {
										time_warning += 5.0;
									}
								}
							}
							
							if (time_warning > (1.0*ttt)) {
								pere[0] += 1;
								printf("	You took too much time! %f sec more than you should. \n", (time_warning-1.0*ttt) );
								printf(" \n");
								for (unsigned int p=16; p>=1; p-=3) {	//index_verschiebung
									if ((time_warning-1.0*ttt) > 1.0*(p-1)) {
										pere[geben] = (((p-1)/3) + 1);
										break;
									}
								}
							} else {
								pere[geben] = 0;
							}
						}
						
						Sf_nl_5 = new_life_5 (Sf, m, n, w, gamemode, information_code);		//printf("ok(1378)");
						
						///printf("Test-print \n");	//test
						//show_field (Sf_nl_5, m, n, gamemode, information_code, geben, Colored);	//test
						
						if (gamemode == 6) {
							
							precounter = 0;
							for (unsigned int i=1; i<m-1; i+=1){
								for (unsigned int j=1; j<n-1; j+=1){
									if (Sf[i][j] == 11){
										if (Sf_nl_3[i][j-1] > 1) {
											printf (" Sieg: Spieler %u \n", Sf_nl_3[i][j-1]);
											precounter += 1;
										}
										if (Sf_nl_3[i][j+1] > 1) {
											if (precounter == 0) {
												printf (" Sieg: Spieler %u \n", Sf_nl_3[i][j+1]);
											}
											precounter += 1;
										}
										if (Sf_nl_3[i-1][j] > 1) {
											if (precounter == 0) {
												printf (" Sieg: Spieler %u \n", Sf_nl_3[i-1][j]);
											}
											precounter += 1;
										}
										if (Sf_nl_3[i+1][j] > 1) {
											if (precounter == 0) {
												printf (" Sieg: Spieler %u \n", Sf_nl_3[i+1][j]);
											}
											precounter += 1;
										}
										if (precounter == 2) {
											printf(" Double-catch! \n");
										}
										if (precounter == 3) {
											printf(" TRIPLE-catch!! \n");
										}
										if (precounter == 4) {
											printf(" QUADRO-CATCH!!! \n");
										}
										break;
									}
								}
								if (precounter > 0) {
									break;
								}
							}
							if (precounter > 0) {
								for (unsigned int i=1; i<m-1; i+=1){
									for (unsigned int j=1; j<n-1; j+=1){
										if (Sf_nl_3[i][j] == geben) {
											Sf[i][j] = geben;
										}
									}
								}
								show_field (Sf, m, n, gamemode, information_code, geben, Colored);
								break;
							}
						}
						
						controll = 0;
						if (gamemode == 7) {	// possible to modify
							for (unsigned int i=(m-2); i>=(m-1)/2; i-=1){		//Spiel-Ende?
								if ((Sf_nl_5[i][n-2] == 5)||(Sf[i][n-2] == 5)){
									for (unsigned int k=(m-2); k>=1; k-=1){
										if (Sf_nl_5[k][n-2] == 5){
											Sf[k][n-2] = 5;
										}
									}
									show_field (Sf, m, n, gamemode, information_code, geben, Colored);
									printf("	Sieg:	Spieler 5 \n");
									controll = 1;
								}
							}
							if (controll == 1){
								break;
							}
						}
						controll = 0;
						
						num_1 = 0;
						for (unsigned int i=1; i<m-1; i+=1){
							for (unsigned int j=1; j<n-1; j+=1){
								if (Sf_nl_5[i][j] == 5){
									num_1 += 1;
								}
							}
						}		//printf("ok(1387)");	
					
						if (var_[5] == 42){
							for (unsigned int i=1; i<m-1; i+=1){
								for (unsigned int j=1; j<n-1; j+=1){
									if (gamemode == 8) {
										if (temp[i][j] == 5){
											Sf[i][j] = 0;
										}
									}  else if ((gamemode == 9)||(gamemode == 10)||(gamemode == 11)||(gamemode == 12)) {	//mehr-gamemode
										if (temp[i][j] != 0){
											Sf[i][j] = temp[i][j];
										}
									} else if (gamemode == 6) {	//10
										if (temp[i][j] == 5){
											Sf[i][j] = 1;
										}
									}
								}
							}
						}		//printf("ok(1398)");	
							// possible to modify
						
						controll = 0;
						if (gamemode == 1){	// possible to modify
							for (unsigned int erste=1; erste<n-1; erste+=1){		//printf("ok(1400)");		//Spiel-Ende?
								if (Sf[1][erste] == 5){
									printf("	Sieg:	Spieler 5 \n");
									show_field (Sf, m, n, gamemode, information_code, geben, Colored);
									controll = 1;		//printf("ok(1404)");
									break;
								}
							}
							if (controll == 1){
								break;		//printf("ok(1409)");
							}		//printf("ok(1410)");
						}
						controll = 0;
						
						Spielfeld_Destroy (temp, m);		//printf("ok(1412)");
					
						Sf_od_5 = old_dying_5 (Sf, m, n, d, e, gamemode, information_code);		//printf("ok(1414)");
						
						if (journey == 1){
							unsigned int journey_max;
							journey_max = 0;
							for (unsigned int i=1; i<m-1; i+=1){
								for (unsigned int j=1; j<n-1; j+=1){
									if (Sf_journey[i][j] == 5){
										journey_max += 1;
									}
								}
							}
							for (unsigned int i=1; i<m-1; i+=1){
								for (unsigned int j=1; j<n-1; j+=1){
									if ((Sf_od_5[i][j] == 505) && (Sf_journey[i][j] == 0) && (journey_max >= limit_at_all)){
										for (unsigned int u=(m-2); u>0; u-=1){
											for (unsigned int o=1; o<(n-1); o+=1){
												if ((Sf_journey[u][o] == 5)&&((u+o)%2 == 0)){
													Sf_journey[u][o] = 0;
													journey_max -= 1;
													if (journey_max < limit_at_all){
														break;
													}
												}
											}
											if (journey_max < limit_at_all){
												break;
											}
										}
										
									}
									if ((Sf_od_5[i][j] == 505) && (Sf_journey[i][j] == 0) && (journey_max < limit_at_all)){
										Sf_journey[i][j] = 5;
										journey_max += 1;
									}
								}
							}
							journey_max = 0;
						}
						
						if (var_[5] == 32){AAA[3] += 1; Revive_5(m, n, Sf_od_5, Sf);}
						
						num_2 = 0;
						for (unsigned int i=1; i<m-1; i+=1){
							for (unsigned int j=1; j<n-1; j+=1){
								if (Sf_od_5[i][j] == 505){
									num_2 += 1;
								}
							}
						}
					
						count_new = 0;
						for (unsigned int i=1; i<m-1; i+=1){
							for (unsigned int j=1; j<n-1; j+=1){
								if (Sf_nl_5[i][j] == 5){
									count_new += 1;
								}
							}
						}
						ent = limit_new;		//printf("ok(1473)");
						
						for (unsigned int i=1; i<m-1; i+=1){
							for (unsigned int j=1; j<n-1; j+=1){
								if ((Sf[i][j] == 5) && (Sf_od_5[i][j] == 0)){
									zeitgewinner += 1;
								}
							}
						}
						
						if (count_new > limit_new){		//Abfrage auf max. 10 neue Steine
							/*if (gamemode == 1) {
								Sf_nl_5 = Index_5 (ent, count_new, m, n, Sf, Sf_nl_5, Sf_od_5, limit_new, limit_at_all, zeitgewinner);	
							} else if (gamemode == 2) {
								Sf_nl_5 = Index_5_col (ent, count_new, m, n, Sf, Sf_nl_5, Sf_od_5, limit_new, limit_at_all, zeitgewinner);	
							} else if (gamemode == 3) {
								Sf_nl_5 = Index_5_con (ent, count_new, m, n, Sf, Sf_nl_5, limit_new);
							} else if (gamemode == 4) {
								Sf_nl_5 = Index_5_fal (ent, count_new, m, n, Sf, Sf_nl_5, Sf_od_5, limit_new, limit_at_all, zeitgewinner);	
							} else if (gamemode == 5) {
								Sf_nl_5 = Index_5_fig (ent, count_new, m, n, Sf, Sf_nl_5, Sf_od_5, limit_new, limit_at_all, zeitgewinner);	
							} else if (gamemode == 7) {
								Sf_nl_5 = Index_5_race (ent, count_new, m, n, Sf, Sf_nl_5, Sf_od_5, limit_new, limit_at_all, zeitgewinner);	
							} else if (gamemode == 8) {
								Sf_nl_5 = Index_5_rain (ent, count_new, m, n, Sf, Sf_nl_5, Sf_od_5, limit_new, limit_at_all, rain, zeitgewinner);	
							}*/
							if (gamemode == 6) {
								Sf_nl_5 = Index_other_hunt (ent, count_new, m, n, Sf_nl_5, geben, zeitgewinner, Sf, limit_at_all);	
							} else if (gamemode == 9) {
								Sf_nl_5 = Index_are (ent, count_new, m, n, Sf_nl_5, Sf_od_5, limit_new, limit_at_all, zeitgewinner, Sf, w, d, e, geben);
							} else if (gamemode == 10) {
								count_new = 0;
							} else if (gamemode == 11) {
								Sf_nl_5 = Index_dyn (ent, count_new, m, n, Sf_nl_5, Sf_od_5, limit_new, limit_at_all, zeitgewinner, Sf, w, d, e, geben, position);
							} else if (gamemode == 12) {	//mehr-gamemode
								count_new = 0;
							}
						
						}
						ent = 0;
						count_new = 0;		//printf("ok(1478)");
					
						num_3 = 0;
						for (unsigned int i=1; i<m-1; i+=1){
							for (unsigned int j=1; j<n-1; j+=1){
								if (((Sf[i][j] == 5) && (Sf_od_5[i][j] == 0)) || (Sf_nl_5[i][j] == 5)){
									count_new += 1;
									num_3 += 1;
								}
							}
						}
						
						ent = limit_at_all;
						if ((gamemode == 1)||(gamemode == 2)||(gamemode == 4)||(gamemode == 5)||(gamemode == 7)||(gamemode == 8)) {
							
							if (var_[5] == 52){
											//printf("ok(1492)");
								lim = 0;
								for (unsigned int i=1; i<m-1; i+=1){
									for (unsigned int j=1; j<n-1; j+=1){
										if ((Sf[i][j] == 5) && (Sf_od_5[i][j] == 0)){
											lim += 1;
										}
									}
								}
											//printf("ok(1501)");
								ent = lim;
											//printf("ok(1503)");
								lim = 0;
								for (unsigned int i=1; i<m-1; i+=1){
									for (unsigned int j=1; j<n-1; j+=1){
										if (Sf[i][j] == 1){
											lim += 1;
										}
									}
								}			//printf("ok(1511)");
							
							
								if ((lim <= limit_new) && (ent < (limit_at_all - 1))){
									if (ent >= (limit_at_all - 3)){
										ent = limit_at_all - 1;
									} else if (ent >= (limit_at_all - 5)){
										ent = limit_at_all - 2;
									} else if (ent >= (limit_at_all - 7)){
										ent = limit_at_all - 3;
									} else if (ent >= (limit_at_all - 10)){
										ent = limit_at_all - 4;
									} else {
										ent = limit_at_all;
									}		//printf("ok(1523)");
								} else {		//printf("ok(1524)");
									ent = limit_at_all;
								}
								lim = 0;
											//printf("ok(1528)");
							}
						}	// possible to modify
						
						if (count_new > ent){		//Abfrage auf insgesamt max. 20 Steine, normalerweise
							/*if (gamemode == 1) {
								Sf_nl_5 = Index_5 (ent, count_new, m, n, Sf, Sf_nl_5, Sf_od_5, limit_new, limit_at_all, zeitgewinner);	
							} else if (gamemode == 2) {
								Sf_nl_5= Index_5_col  (ent, count_new, m, n, Sf, Sf_nl_5, Sf_od_5, limit_new, limit_at_all, zeitgewinner);	
							} else if (gamemode == 3) {
								count_new = 0;
							} else if (gamemode == 4) {
								Sf_nl_5 = Index_5_fal (ent, count_new, m, n, Sf, Sf_nl_5, Sf_od_5, limit_new, limit_at_all, zeitgewinner);	
							} else if (gamemode == 5) {
								Sf_nl_5 = Index_5_fig (ent, count_new, m, n, Sf, Sf_nl_5, Sf_od_5, limit_new, limit_at_all, zeitgewinner);	
							} else if (gamemode == 7) {
								Sf_nl_5 = Index_5_race (ent, count_new, m, n, Sf, Sf_nl_5, Sf_od_5, limit_new, limit_at_all, zeitgewinner);	
							} else if (gamemode == 8) {
								Sf_nl_5 = Index_5_rain (ent, count_new, m, n, Sf, Sf_nl_5, Sf_od_5, limit_new, limit_at_all, rain, zeitgewinner);	
							}*/
							if (gamemode == 6) {
								Sf_nl_5 = Index_other_hunt (ent, count_new, m, n, Sf_nl_5, geben, zeitgewinner, Sf, limit_at_all);	
							} else if (gamemode == 9) {
								Sf_nl_5 = Index_are (ent, count_new, m, n, Sf_nl_5, Sf_od_5, limit_new, limit_at_all, zeitgewinner, Sf, w, d, e, geben);	
							} else if (gamemode == 10) {
								count_new = 0;
							} else if (gamemode == 11) {
								Sf_nl_5 = Index_dyn (ent, count_new, m, n, Sf_nl_5, Sf_od_5, limit_new, limit_at_all, zeitgewinner, Sf, w, d, e, geben, position);
							} else if (gamemode == 12) {	//mehr-gamemode
								count_new = 0;
							}
						
						}
						ent = 0;
						zeitgewinner = 0;
						
						if (gamemode == 4) {
							touch (Sf, m, n, geben, Sf_nl_1, Sf_nl_2);	//possible to modify
						}
						
						Sf = change_5 (Sf, Sf_nl_5, Sf_od_5, m, n, gamemode, number_of_players, ges);
						
						if (gamemode == 1) {
							for (unsigned int j=1; j<n-1; j+=1){	//possible to modify
								if (Sf[2][j] == 2){
									B[0] += 1;
									break;
								}
							} 
						} else if (gamemode == 2) {	//possible to modify
							for (unsigned int j=2; j<n-1; j+=((n-1)/2)-2){		//collect-Bed. prüfen
								unsigned int b;
								b = 0;
								if (Sf[((m-1)/2)][j] == 7){
									if (Sf[((m-1)/2)-1][j]==2){b += 1;}
									if (Sf[((m-1)/2)+1][j]==2){b += 1;}
									if (Sf[(m-1)/2][j-1]==2){b += 1;}
									if (Sf[(m-1)/2][j+1]==2){b += 1;}
									if (b >= 3){
										B[0] += 1;
										Sf[((m-1)/2)][j] = 2;
									}
								}
							}
							if (B[0] == 2){
								printf("\n");
								printf("	Sieg: Spieler 2 \n");
								printf("\n");
								show_field (Sf, m, n, gamemode, information_code, geben, Colored);
								break;
							}
						}
						
						
						if ((gamemode == 6)&&(geben == number_of_players)) {
							lim = 1;
							printf("	\n");
							if (opague >= 1) {
								show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
							} else {
								show_field (Sf, m, n, gamemode, information_code, geben, Colored);
							}
							printf("	\n");
							while (lim == 1) {
								printf("	\n");
								printf("	\n");
								printf("	Are you ready to make your turn? \n");
								printf("	Yes: 1 \n");
								printf("	\n");
								printf("	\n");
								scanf("%u", &lim);
								
								if (lim != 1) {
									lim = 1;
								} else {
									lim = 0;
								}
							}
						}
						if (gamemode == 6) {
							information_code[3] = 0;
						}
						
						controll = 0;
						if (gamemode == 1) {	//possible to modify
							for (unsigned int erste=1; erste<n-1; erste+=1){		//Spiel-Ende?
								if (Sf[1][erste] == 2){
									printf("	Sieg:	Spieler 2 \n");
									controll = 1;
									break;
								}
							}
							if (controll == 1){
								break;
							}
						}
						controll = 0;
						
						if (gamemode == 3) {	//possible to modify
							if (opague >= 1) {
								show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
							} else {
								show_field (Sf, m, n, gamemode, information_code, geben, Colored);
							}
							battle (m, n, Sf, geben);
						}
						
						if (number_of_players == 5) {// gamemode 6 modify, done!
							if (var_[1] != 1010) {
								cons[5] = use_number;
								
								if (gamemode == 11) {	//mehr-gamemode
									for (unsigned int p=2; p<=5; p+=1) {
										
										dynamic_pointer_save[5][p-2] = dynamic_pointer[p];
										
									}
								}
								
							}
						} else if (number_of_players >= 6) {
							if (var_[6] != 1010) {
								cons[5] = use_number;
								
								if (gamemode == 11) {	//mehr-gamemode
									for (unsigned int p=2; p<=5; p+=1) {
										
										dynamic_pointer_save[5][p-2] = dynamic_pointer[p];
										
									}
								}
								
							}
						}
						
						use_number = random_number (num_1, num_2, num_3, use_number, g, var_, number_3, number_4);
						
						if ((opt != 5)&&(var_[5] <= 62)){
							controll_2 = 0;
							for (unsigned int z=var_[5]; z>2; z-=10){
								controll_2 += 1;
							}
							number_5 = controll_2;
							//printf("%u \n", number_5);
							controll_2 = 0;
						}
					}
				}	//{}ausfindig machen
			} else if (geben == 6) {		//following players
				
				if (opague >= 1) {
					Sf_opague = opague_builder (Sf, m, n, geben, opague, aop);
					
				}
				
				if ((ttt != 0)&&(pere[geben] == 100)) {
					g += 1;
					continue;
				}
				
				if ((gamemode == 10)&&(ulcer_start[6] == 0)) {
					if (opague >= 1) {
						show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
					} else {
						show_field (Sf, m, n, gamemode, information_code, geben, Colored);
					}
					g += 1;
					continue;
				}
				
				if ((ges[6] == 6060)&&((gamemode == 6)||(gamemode == 9)||(gamemode == 10)||(gamemode == 11)||(gamemode == 12))) {	//mehr-gamemode
					g+=1;
					var_[6] = 6060;
					cons[6] = cons[5];
					for (unsigned int i=1; i<m-1; i+=1){
						for (unsigned int j=1; j<n-1; j+=1){
							cons_field_6[i][j] = cons_field_5[i][j];
							if (journey == 1){
								cons_journey_6[i][j] = cons_journey_5[i][j];
								
								if (Sf_journey[i][j] == 6) {
									Sf_journey[i][j] = 0;
								}
							}
							if (gamemode == 11) {	//mehr-gamemode
								for (unsigned int p=2; p<=5; p+=1) {
									
									dynamic_pointer_save[6][p-2] = dynamic_pointer_save[5][p-2];
									
								}
							}
						}
					}
					if (var_[0] == 1) {
						g-=2;
					}
					continue;
				}
				
				w = 3;
				d = 2;
				e = 3;
				if (gamemode == 9) {
					if (ability[1] == geben) {
						w = 1;
						d = 0;
						e = 1;
						information_code[0] = 1;
					} else if (ability[2] == geben) {
						w = 2;
						d = 1;
						e = 2;
						information_code[0] = 2;
					} else if (ability[3] == geben) {
						w = 4;
						d = 1;
						e = 4;	//abweichende e-definition
						information_code[0] = 3;
					} else if (ability[4] == geben) {
						information_code[0] = 4;
					} else if (ability[5] == geben) {
						information_code[0] = 5;
					} else if (ability[6] == geben) {
						information_code[0] = 6;
					} else if (ability[7] == geben) {
						information_code[0] = 7;
					} else if (ability[8] == geben) {
						information_code[0] = 8;
					} else if (ability[9] == geben) {
						information_code[0] = 9;
						
						if (opague >= 1) {
							show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
						} else {
							show_field (Sf, m, n, gamemode, information_code, geben, Colored);
						}
						
						for (unsigned int i=1; i<m-1; i+=1){
							for (unsigned int j=1; j<n-1; j+=1){
								if (Sf[i][j] == geben) {
									if ((Sf[i+1][j] != 0)&&(Sf[i+1][j] != geben)&&((i+2) <= (m-2))) {
										if (Sf[i+2][j] == 0) {
											Sf[i+2][j] = Sf[i+1][j];
											Sf[i+1][j] = 0;
										}
									}
									if ((Sf[i-1][j] != 0)&&(Sf[i-1][j] != geben)&&((i-2) >= 1)) {
										if (Sf[i-2][j] == 0) {
											Sf[i-2][j] = Sf[i-1][j];
											Sf[i-1][j] = 0;
										}
									}
									if ((Sf[i][j-1] != 0)&&(Sf[i][j-1] != geben)&&((j-2) >= 1)) {
										if (Sf[i][j-2] == 0) {
											Sf[i][j-2] = Sf[i][j-1];
											Sf[i][j-1] = 0;
										}
									}
									if ((Sf[i][j+1] != 0)&&(Sf[i][j+1] != geben)&&((j+2) <= (n-2))) {
										if (Sf[i][j+2] == 0) {
											Sf[i][j+2] = Sf[i][j+1];
											Sf[i][j+1] = 0;
										}
									}
								}
							}
						}
					}
				}
				
				if (gamemode == 10) {
					w = 2;
					d = 1;
					e = 2;
				}
				
				if (gamemode == 9) {
					if (information_code[0] == 1) {
						limit_at_all = limit_at_all-2;
					} else if (information_code[0] == 2) {
						limit_at_all = limit_at_all-1;
					} else {
						limit_at_all = limit_at_all_saver;
					}
				}
				
				if (ttt != 0) {
					if ((pere[geben] != 0)&&(warning_system <= 5)&&((pere[geben]+warning_system) == 7)) {
						g += 1;
						printf(" \n ");
						printf("	You got a penalty. \n ");
						printf(" \n ");
						pere[geben] = 0;
						continue;
					} else if ((pere[geben] != 0)&&(warning_system != 0)&&(((warning_system <= 5)&&((pere[geben]+warning_system) == 8))||((warning_system == 6)&&(pere[geben] == 1)))) {
						Sf_od_6 = old_dying_6 (Sf, m, n, d, e, gamemode, information_code);
						Sf = change_6 (Sf, Sf_nl_6, Sf_od_6, m, n, gamemode, number_of_players, ges); 	//Change befreit
						g += 1;
						printf(" \n ");
						printf("	You got a penalty. \n ");
						printf(" \n ");
						pere[geben] = 0;
						continue;
					} else if (((warning_system <= 5)&&((warning_system + pere[geben]) >= 9))||((warning_system >= 6)&&((warning_system + pere[geben]) >= 8))) {
						printf("	Niederlage: Spieler 6 \n ");
						for (unsigned int i=1; i<m-1; i+=1){
							for (unsigned int j=1; j<n-1; j+=1){
								if (Sf[i][j] == 6) {
									Sf[i][j] = 0;
								}
							}
						}
						ges[6] = 6060;
						player_counter += 1;
						pere[geben] = 100;
						g += 1;
						continue;
					}
				}
				
				if (var_[geben] == 1010) {
					use_number = cons[geben];
					if (opt == 5) {
					
						printf("	Player %u ,do you want to keep your number (%u) or do you want to get the next one? \n", geben, cons[geben]);
						printf("	Keep the number: 	1 \n");
						printf("	Get the next one:	2 \n");
						scanf("%u", &lim);
						
						if (lim == 2) {
							use_number = random_number (num_1, num_2, num_3, use_number, g, var_, number_3, number_4);
						} else if (lim != 1) {
							printf("	Well, you keep your number, but next time please take an option i offered. \n\n");
						}
						lim = 0;
					
					}
				}
				
				if (var_[geben%number_of_players+1] == 1010){		//geben%number_of_players+1 ist der Nachfolger von geben.
					if (tac != 0) {
						if (number_6 <= 5){
							DDD[number_6] += 1;
						} else if (number_6 == 6){
							DDD[0] += 1;
						}
					} else if (opt == 5) {
						BBB[use_number] -= 1;
					} else {
						BBB[number_6] -= 1;
					}
					
				}
				
				if ((tac != 0)&&((DDD[1]+DDD[2]+DDD[3]+DDD[4]+DDD[5]+DDD[0]) == 0)){
					for (unsigned int p=0; p<=5; p+=1){
						DDD[p] = tac;
					}
				}
				
				menuoperator = 1;
				
				
				while (menuoperator != 0) {
						
					if (gamemode != 8) {
						if (opague >= 1) {
							show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
						} else {
							show_field (Sf, m, n, gamemode, information_code, geben, Colored);
						}
					}
					
					if ((gamemode == 6)&&(((scwhp == 1)&&((opt == 0)||((use_number == 2)||(use_number == 3)||(use_number == 4)))&&((tac == 0)||((DDD[2] != 0)||(DDD[3] != 0)||(DDD[4] != 0))))||(scwhp == 2))) {
						
						information_code[3] = 1;
						
						if (opague >= 1) {
							show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
						} else {
							show_field (Sf, m, n, gamemode, information_code, geben, Colored);
						}
					}
					
					if (gamemode == 4) {
						printf("\n");
						printf("	Points player 6: 	%u Point(s) \n", P[geben]);
					}	// possible to modify
					
					if (gamemode == 10) {
						printf("\n");
						printf("	Lifes player 6: 	%u Life(s) \n", ulcer_lifes[6]);
					}
					
					if (gamemode == 11) {
						printf("	\n");
						printf("	Geschwindigkeit: 	Zeile: %d, 	Spalte: %d \n", dynamic_pointer[2], dynamic_pointer[3]);
						printf("	Beschleunigung: 	Zeile: %d, 	Spalte: %d \n", dynamic_pointer[4], dynamic_pointer[5]);
						printf("	\n");
					}
					
					printf("\n");
					
					if (Colored[0] == 1) {
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+Colored[geben]);
					}
					
					if ((gamemode != 6)&&(gamemode != 9)&&(gamemode != 10)&&(gamemode != 11)&&(gamemode != 12)){	//mehr-gamemode
						printf("	Am Zug: Spieler 2 (OO)	\n");	// possible to modify
					} else if (gamemode == 6) {
						printf("	Am Zug: Spieler 6 (EE)	\n");
					} else if (gamemode == 9) {
						if (ability[1] == geben) {
							printf("	Am Zug: Spieler 6 (UU)	\n");
						} else if (ability[2] == geben) {
							printf("	Am Zug: Spieler 6 (LL)	\n");
						} else if (ability[3] == geben) {
							printf("	Am Zug: Spieler 6 (AA)	\n");
						} else if (ability[4] == geben) {
							printf("	Am Zug: Spieler 6 (CC)	\n");
						} else if (ability[5] == geben) {
							printf("	Am Zug: Spieler 6 (II)	\n");
						} else if (ability[6] == geben) {
							printf("	Am Zug: Spieler 6 (SS)	\n");
						} else if (ability[7] == geben) {
							printf("	Am Zug: Spieler 6 (PP)	\n");
						} else if (ability[8] == geben) {
							printf("	Am Zug: Spieler 6 (HH)	\n");
						} else if (ability[9] == geben) {
							printf("	Am Zug: Spieler 6 (EE)	\n");
						}
					} else if ((gamemode == 10)||(gamemode == 11)||(gamemode == 12)) {	//mehr-gamemode
						printf("	Am Zug: Spieler 6 (66)	\n");
					}
					
					if (Colored[0] == 1) {
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+7);
					}
					
					printf("\n");
					
					if (tac != 0){
						printf("	Your stack of numbers:	\n	1) [%u],		2) [%u],		3) [%u], \n\n	4) [%u],		5) [%u],		6) [%u],\n", DDD[1], DDD[2], DDD[3], DDD[4], DDD[5], DDD[0]);
						printf("\n");
						printf("\n");
					}
					
					if (opt == 5){		//random number
						printf("	Your number: %u ", use_number);
						printf("\n");
						printf("\n");
						
					}
					
					printf("	1) Plus:	11	Minus: 	12 \n");
					printf("	2) Move:	21	Change: 22 \n");
					printf("	3) Destroy:	31	Revive: 32 \n");
					printf("	4) Move:	41	Boost: 	42 \n");
					if (((gamemode != 9)&&(gamemode != 10))||((gamemode == 10)&&(geben == 1))) {
						printf("	5) 4/5-new:	51	2-new:	52 \n");
						printf("	6) 4-max:	61	1-min:	62 \n");
					} else if (gamemode == 9) {
						if (information_code[0] == 1) {
							printf("	5) 2/3-new:	51	0-new:	52 \n");
							printf("	6) 2-max:	61	-1-min:	62 \n");
						} else if (information_code[0] == 2) {
							printf("	5) 3/4-new:	51	1-new:	52 \n");
							printf("	6) 3-max:	61	0-min:	62 \n");
						} else if (information_code[0] == 3) {
							printf("	5) 5/6-new:	51	3-new:	52 \n");
							printf("	6) 5-max:	61	0-min:	62 \n");
						} else {
							printf("	5) 4/5-new:	51	2-new:	52 \n");
							printf("	6) 4-max:	61	1-min:	62 \n");
						}
					} else if ((gamemode == 10)&&(geben != 1)) {
						printf("	5) 3/4-new:	51	1-new:	52 \n");
						printf("	6) 3-max:	61	0-min:	62 \n");
					}
					printf("							\n");
					printf("		Go back: 100 \n");
					printf("		Menu: 10 \n");
					printf("		End game: 0 \n");
					if ((ttt != 0)&&(time_saver == 0.0)) {
						time1 = time(NULL);
					}
					scanf("%u", &var_[6]);
					
					if (var_[6] == 10){
						if (ttt != 0) {
							time3 = time(NULL);
						}
						while (menuoperator != 7) {
							
							printf("\n");
							printf("\n");
							printf("	About the game: 1 \n	Statistics: 2 \n	The numbers: 3 \n	The limits: 4 \n	Get Hints: 5 \n	Suprise: 6 \n	Quit Menu: 7 \n");
							scanf("%u", &menuoperator);
							
							if (menuoperator == 1){
								if (gamemode == 1) {
									printf("	How to win? 	Own a square on your last line or force your opponent to lose all his/her ones.\n");
								} else if (gamemode == 2) {
									printf("	How to win? 	Be at 2 of the 3 targets with three of your squares near-by.\n");
								} else if (gamemode == 3) {
									printf("	How to win? 	Take over all your opponent's squares by winning contact-battles.\n");
									printf("	Contact-battles? 	All near-by squares in a row with the contact-square build a chain, beat your opponent in the length.\n");
								} else if (gamemode == 4) {
									printf("	How to win? 	Get more points than your opponent.\n");
									printf("	Note:	Touch the #-square in the near-by to move it to the opposite side. \n");
								} else if (gamemode == 5) {
									printf("	How to win? 	Force your opponent to lose all his/her squares.\n");
								} else if (gamemode == 6) {
									if (geben == 1) {
										printf("	How to win? 	Protect your heart-block so no enemy can touch it.\n");
									} else {
										printf("	How to win? 	Catch the heart-block of the hunted one before it disappears.\n");
									}
								} else if (gamemode == 7) {
									printf("	How to win? 	Reach the end of the field or force your opponent to lose all his/her ones.\n");
									printf("	Note:	Every %u turns in total the #-line will go ahead and destroys everything in it's way.\n Also you are not allowed to cross the mid-line. \n", freq);
								} else if (gamemode == 8) {
									printf("	How to win? 	Reach [1][7] of the field or force your opponent to lose all his/her squares.\n");
									printf("	Note:	Falling down the #-squares will push, destroy, explode, or teleport, transform into yours by contact. \n");
								} else if ((gamemode == 9)||(gamemode == 10)) {
									printf("	How to win? 	Force your opponent to lose all his/her squares while keeping yours alive.\n");
								} else if (gamemode == 11) {
									printf("	How to win? 	Push the ball against your opponent's side.\n");
								} else if (gamemode == 12) {	//mehr-gamemode
									printf("	How to win? 	Stay alive.\n");
								}
								printf("	Surrounding:	The 8 squares around another, at the edge 5, in the corners 3, are called #surrounding. \n");
								printf("	near-by:	The 4 squares around another, at the edge 3, in the corners 2, are called #near-by. \n");
								printf("	Standard actions:	(After your choice of number and not influencing each other) \n	-Development:	If it is your turn and a free square has exactly 3 of yours surrounding it, you will own it.\n");
								printf("	-Losses: 	If it is your turn and a square of yours is surrounded by less than %u or more than %u of yours,\n			it will be set free.\n", d, e);
								if ((gamemode == 10)||(gamemode == 12)) {	//mehr-gamemode
									printf("	Limits: 	This gamemode is unlimited. \n");
								} else if (gamemode == 3) {
									printf("	Limits: 	Your development is limited by %u per round. \n", limit_new);
								} else {
									printf("	Limits: 	Your development is limited by %u per round, your units in total by %u per round. \n", limit_new, limit_at_all);
								}
							}
							
							if (menuoperator == 2){
								printf("\n");
								printf("	turns at all: %u \n", g);
								printf("\n");
								printf("	Numbers of player 1: \n");
								printf("		#1 = %u \n", A[1]);
								printf("		#2 = %u \n", A[2]);
								printf("		#3 = %u \n", A[3]);
								printf("		#4 = %u \n", A[4]);
								printf("		#5 = %u \n", A[5]);
								printf("		#6 = %u \n", A[6]);
								printf("\n");
								if (number_of_players >= 2) {	//mehr-gamemode
									printf("	Numbers of player 2: \n");
									printf("		#1 = %u \n", B[1]);
									printf("		#2 = %u \n", B[2]);
									printf("		#3 = %u \n", B[3]);
									printf("		#4 = %u \n", B[4]);
									printf("		#5 = %u \n", B[5]);
									printf("		#6 = %u \n", B[6]);
									printf("\n");
								}
								
								if (number_of_players >= 3){	//mehr-gamemode
									printf("	Numbers of player 3: \n");
									printf("		#1 = %u \n", AA[1]);
									printf("		#2 = %u \n", AA[2]);
									printf("		#3 = %u \n", AA[3]);
									printf("		#4 = %u \n", AA[4]);
									printf("		#5 = %u \n", AA[5]);
									printf("		#6 = %u \n", AA[6]);
									printf("\n");
								}
								if (number_of_players >= 4){
									printf("	Numbers of player 4: \n");
									printf("		#1 = %u \n", BB[1]);
									printf("		#2 = %u \n", BB[2]);
									printf("		#3 = %u \n", BB[3]);
									printf("		#4 = %u \n", BB[4]);
									printf("		#5 = %u \n", BB[5]);
									printf("		#6 = %u \n", BB[6]);
									printf("\n");
								}
								if (number_of_players >= 5){
									printf("	Numbers of player 5: \n");
									printf("		#1 = %u \n", AAA[1]);
									printf("		#2 = %u \n", AAA[2]);
									printf("		#3 = %u \n", AAA[3]);
									printf("		#4 = %u \n", AAA[4]);
									printf("		#5 = %u \n", AAA[5]);
									printf("		#6 = %u \n", AAA[6]);
									printf("\n");
								}
								if (number_of_players >= 6){
									printf("	Numbers of player 6: \n");
									printf("		#1 = %u \n", BBB[1]);
									printf("		#2 = %u \n", BBB[2]);
									printf("		#3 = %u \n", BBB[3]);
									printf("		#4 = %u \n", BBB[4]);
									printf("		#5 = %u \n", BBB[5]);
									printf("		#6 = %u \n", BBB[6]);
									printf("\n");
								}
								if (number_of_players >= 7){
									printf("	Numbers of player 7: \n");
									printf("		#1 = %u \n", AAAA[1]);
									printf("		#2 = %u \n", AAAA[2]);
									printf("		#3 = %u \n", AAAA[3]);
									printf("		#4 = %u \n", AAAA[4]);
									printf("		#5 = %u \n", AAAA[5]);
									printf("		#6 = %u \n", AAAA[6]);
									printf("\n");
								}
								if (number_of_players >= 8){
									printf("	Numbers of player 8: \n");
									printf("		#1 = %u \n", BBBB[1]);
									printf("		#2 = %u \n", BBBB[2]);
									printf("		#3 = %u \n", BBBB[3]);
									printf("		#4 = %u \n", BBBB[4]);
									printf("		#5 = %u \n", BBBB[5]);
									printf("		#6 = %u \n", BBBB[6]);
									printf("\n");
								}
								if (number_of_players == 9){
									printf("	Numbers of player 9: \n");
									printf("		#1 = %u \n", AAAAA[1]);
									printf("		#2 = %u \n", AAAAA[2]);
									printf("		#3 = %u \n", AAAAA[3]);
									printf("		#4 = %u \n", AAAAA[4]);
									printf("		#5 = %u \n", AAAAA[5]);
									printf("		#6 = %u \n", AAAAA[6]);
									printf("\n");
								}
								
								if ((gamemode == 1)||(gamemode == 6)||(gamemode == 7)||(gamemode == 8)) {
									printf("	Matchballs player 1: 	%u \n", A[0]);
									printf("	Matchballs player 2: 	%u \n", B[0]);
									if (gamemode == 6) {
										if (number_of_players >= 3){printf("	Matchballs player 3: 	%u \n", AA[0]);}
										if (number_of_players >= 4){printf("	Matchballs player 4: 	%u \n", BB[0]);}
										if (number_of_players >= 5){printf("	Matchballs player 5: 	%u \n", AAA[0]);}
										if (number_of_players >= 6){printf("	Matchballs player 6: 	%u \n", BBB[0]);}
										if (number_of_players >= 7){printf("	Matchballs player 7: 	%u \n", AAAA[0]);}
										if (number_of_players >= 8){printf("	Matchballs player 8: 	%u \n", BBBB[0]);}
										if (number_of_players == 9){printf("	Matchballs player 9: 	%u \n", AAAAA[0]);}
									}
								} else if (gamemode == 2) {
									printf("	Squares collected by player 1: 	%u \n", A[0]);
									printf("	Squares collected by player 2: 	%u \n", B[0]);
								} else if (gamemode == 3) {
									printf("	Times with squares <= 5, player 1: 	%u \n", A[0]);
									printf("	Times with squares <= 5, player 2: 	%u \n", B[0]);
								} else if (gamemode == 4) {
									printf("	Points player 1: 		%u \n", P[1]);
									printf("	Points Player 2: 		%u \n", P[2]);
									printf("	Turns with more points player 1: 	%u \n", A[0]);
									printf("	Turns with more points player 2: 	%u \n", B[0]);
									printf("	Number of not decided #-squares: 	%u \n", P[0]);
								} else if (gamemode == 3) {
									printf("	Times with squares < 5, player 1: 	%u \n", A[0]);
									printf("	Times with squares < 5, player 2: 	%u \n", B[0]);
								} else if (gamemode == 9) {
									printf("	Number of excluded abilites: 	%u \n", exclude_counter);
									printf("	Offensive abilities taken: 	%u \n", number_of_players-ability[0]);
									printf("	Defensive abilities taken: 	%u \n", ability[0]);
								} else if (gamemode == 10) {
									for (unsigned int p=1; p<=number_of_players; p+=1) {
										printf("		Spieler %u: %u life(s) left.\n", p, ulcer_lifes[p]);
									}
								} else if (gamemode == 11) {	//mehr-gamemode
									for (unsigned int p=1; p<=number_of_players; p+=1) {
										if ((ges[p] > 1000)||(ges[p] == 0)) {
											printf("	Spieler %u: is out.\n", p);
										} else if (ges[p] < 1000) {
											printf("	Spieler %u: You own %u squares.\n", p, ges[p]);
										}
									}
								} else if (gamemode == 12) {
									for (unsigned int p=1; p<=number_of_players; p+=1) {
										if ((ges[p] > 1000)||(ges[p] == 0)) {
											printf("	Spieler %u: is out.\n", p);
										} else if (ges[p] < 1000) {
											printf("	Spieler %u: You own %u squares.\n", p, ges[p]);
										}
									}
								}
								
								if (ttt != 0) {
									printf("	Number of penalties given until	now: %u \n", pere[0]);
								}
							}
							
							if (menuoperator == 3){
								if ((gamemode != 10)&&(gamemode != 12)) {
									printf("	Plus: Change a free square in the surrounding of yours in one of yours.\n");
								} else {
									printf("	Plus: Change a square in the surrounding of yours in one of yours.\n");
								}
								printf("	Minus: Delete one of your squares.\n");
								printf("	Move: The position of one of yours will change with a free, near-by square.\n");
								printf("	Revive: Your lost squares having no living squares of yours surrounding them at the beginning of your turn,\n		will be revived.\n");
								printf("	%u/%u-new: A free square has to be surrounded by %u or %u of yours during the development.\n", w+1, w+2, w+1, w+2);
								printf("	%u-new: A free square has to be surrounded by %u of yours during the development.\n", d, d);
								printf("	%u-max: A square of yours will survive even by %u of your squares surrounding it.\n", e+1, e+1);
								if (d == 0) {
									printf("	-1-min: A square of yours will survive even by only -1 of your squares surrounding it.\n");
								} else {
									printf("	%u-min: A square of yours will survive even by only %u of your squares surrounding it.\n", d-1, d-1);
								}
								
								if ((gamemode == 1)||(gamemode == 2)||(gamemode == 4)||(gamemode == 5)||(gamemode == 7)||(gamemode == 9)||(gamemode == 10)) {
									printf("	Change: A square of yours and a near-by square of your enemy will change positions.\n");
									printf("	Destroy: Delete a near-by square of your enemy.\n");
									printf("	Boost: Use all near-by squares of your enemy as your own for the development.\n");
									
								} else if (gamemode == 3) {
									
									printf("	Change: A square of yours and a square of your enemy in the surrounding will change positions.\n");
									printf("	Destroy: Delete a surrounding square of your enemy.\n");
									printf("	Boost: Use all surrounding squares of your enemy as your own for the development.\n");
									
								} else if (gamemode == 8) {
									printf("	Change: A square of yours and a near-by #-square will change positions.\n");
									printf("	Destroy: Delete a square of your enemy, but not in the last two lines.\n");
									printf("	Boost: Use all near-by #-squares as your own for the development.\n");
									
								} else if (gamemode == 6) {
									if (geben == 1) {
										printf("	Change: The heart-block and a square of yours will change positions.\n");
										printf("	Destroy: Delete a square of your enemy.\n");
										printf("	Boost: Touching the heart_block no square of yours can die.\n");
									} else {
										printf("	Change: A square of yours and a near-by square of the hunted one will change positions.\n");
										printf("	Destroy: Delete a near-by square of your enemy.\n");
										printf("	Boost: Use all near-by squares of the hunted one as your own for the development.\n");
									}
									
								} else if (gamemode == 11) {	//mehr-gamemode
									printf("	Change: A square of yours and a near-by square of your enemy or the near-by ball will change positions.\n");
									printf("	Destroy: Delete a near-by square of your enemy.\n");
									printf("	Boost: Use all near-by squares of your enemy and the near-by ball as your own for the development.\n");
								} else if (gamemode == 12) {
									printf("	Change: A square of yours and a near-by square of your enemy or a near-by object will change positions.\n");
									printf("	Destroy: Delete a near-by square of your enemy or a near-by object.\n");
									printf("	Boost: Use all near-by squares of your enemy and near-by objects as your own for the development.\n");
								}
								
								printf("\n");
							}
							
							if (menuoperator == 4){	//mehr-gamemode
								if ((gamemode != 10)&&(gamemode != 12)) {
									printf("	Limit of development:	%u \n", limit_new);
									if (gamemode != 3) {
										printf("	Limit in total:		%u \n", limit_at_all);
										printf("	Limit in total with >2-new< taken: %u -0/-1/-2/-3/-4.\n", limit_at_all);
									}
								}
							}
							
							if (menuoperator == 5){
								Spielfeld hint;
								unsigned int b, a;
								hint = Spielfeld_Create (m, n);
								printf("	New: 1 \n	Dying: 2 \n	Both: 3 \n");
								scanf("%u", &menuoperator);
								
								for (unsigned int i=1; i<(m-1); i+=1){
									for (unsigned int j=1; j<(n-1); j+=1){
										if ((gamemode != 6)&&(gamemode != 9)&&(gamemode != 10)&&(gamemode != 11)&&(gamemode != 12)){	//mehr-gamemode
											if (Sf[i][j] == geben){
												hint[i][j] = geben;
											} else if (Sf[i][j] == (geben%2)+1){
												hint[i][j] = (geben%2)+1;
											} else if (Sf[i][j] == 7){
												hint[i][j] = 7;
											} 
										} else if ((gamemode == 6)||(gamemode == 9)||(gamemode == 10)) {	//10
											if (Sf[i][j] == geben){
												hint[i][j] = geben;
											} else if (Sf[i][j] != 0){
												hint[i][j] = 17;
											}
										} else if (gamemode == 11) {
											if (Sf[i][j] == geben){
												hint[i][j] = geben;
											} else if (Sf[i][j] == 77){
												hint[i][j] = 77;
											} else if (Sf[i][j] != 0){
												hint[i][j] = 17;
											}
										} else if (gamemode == 12) {	//mehr-gamemode
											if (Sf[i][j] == geben){
												hint[i][j] = geben;
											} else if (Sf[i][j] == 81){
												hint[i][j] = 81;
											} else if (Sf[i][j] == 82){
												hint[i][j] = 82;
											} else if (Sf[i][j] == 83){
												hint[i][j] = 83;
											} else if (Sf[i][j] == 84){
												hint[i][j] = 84;
											} else if (Sf[i][j] == 75){
												hint[i][j] = 75;
											} else if (Sf[i][j] == 71){
												hint[i][j] = 71;
											} else if (Sf[i][j] != 0){
												hint[i][j] = 17;
											}
										}
									}
								}
								
								if ((menuoperator == 2)||(menuoperator == 3)){
									for (unsigned int i=1; i<(m-1); i+=1){
										for (unsigned int j=1; j<(n-1); j+=1){
											if (Sf[i][j] == geben){
												a = 0;
												for (unsigned int h=(i-1); h<=(i+1); h+=1){
													for (unsigned int k=(j-1); k<=(j+1); k+=1){
														if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
															if (Sf[h][k] == geben){
																a += 1;
															}
														}
													}
												}
												if ((a > 4) || (a < 3)){
													hint[i][j] = 16;
												}
											}
										}
									}
								}
								
								if ((menuoperator == 1)||(menuoperator == 3)){
									for (unsigned int i=1; i<(m-1); i+=1){
										for (unsigned int j=1; j<(n-1); j+=1){
											if (Sf[i][j] == 0){
												b = 0;
												for (unsigned int h=(i-1); h<=(i+1); h+=1){
													for (unsigned int k=(j-1); k<=(j+1); k+=1){
														if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
															if (Sf[h][k] == geben){
																b += 1;
															}
														}
													}
												}
												if (b == 3){
													hint[i][j] = 15;
												}
											}
										}
									}
								}
						
								if (opague >= 1) {
									Sf_opague = opague_builder (hint, m, n, geben, opague, aop);
								}
								
								if (opague >= 1) {
									show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
								} else {
									show_field (hint, m, n, gamemode, information_code, geben, Colored);
								}
								
								if (opague >= 1) {
									Sf_opague = opague_builder (Sf, m, n, geben, opague, aop);
								}
								
								menuoperator = 1;
								Spielfeld_Destroy (hint, m);
							}
							// 2
							if (menuoperator == 6){
								if (suprise == 0) {
									for (unsigned int i=1; i<m-1; i+=1){
										for (unsigned int j=1; j<n-1; j+=1){
											cons_field_6[i][j] = Sf[i][j];
											
											if (journey == 1){
												cons_journey_6[i][j] = Sf_journey[i][j];
											}
										}
									}
									sup_num = use_number;
								}
								
								while (menuoperator != 1) {
						
									printf("	Creator menu. 	Change number: 1	Suprise: 2	Suprise undo: 3	Back: 4 \n");
									scanf ("%u", &lim);
									if (lim == 1){
										printf("	number = ? \n");
										scanf ("%u", &use_number);
									} else if (lim == 2){
								
										printf("\n");
										scanf("%u", &suprise);
								
										if (suprise == 31){
											for (unsigned int i=2; i<m-2; i+=1){
												for (unsigned int j=1; j<n-1; j+=1){
													if (Sf[i][j] != 0){
														if (Sf[i][j] == 1){
															Sf[i][j] = 6;
														} else if (Sf[i][j] == 6){
															Sf[i][j] = 1;
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
								
										if(suprise == 13){
											for (unsigned int i=1; i<m-1; i+=1){
												for (unsigned int j=1; j<n-1; j+=1){
													if (Sf[i][j] == 6){
														Sf[i][j] = 0;
													}
													if (i == (m-2)){
														Sf[m-2][j] = 6;
													}
												}
											}
										}
								
									} else if (lim == 3){
										for (unsigned int i=1; i<m-1; i+=1){
											for (unsigned int j=1; j<n-1; j+=1){
												Sf[i][j] = cons_field_6[i][j];
												
												if (journey == 1){
													Sf_journey[i][j] = cons_journey_6[i][j];
												}
											}
										}
										use_number = sup_num;
									} else if (lim == 4){
										menuoperator = 1;
									} else {
										printf("	Invalid comment");
									}
								}
							}
						}	// menuoperator = 7
						
						if (gamemode == 8) {
							if (opague >= 1) {
								show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
							} else {
								show_field (Sf, m, n, gamemode, information_code, geben, Colored);
							}	//show_field über menuoperator = 7 und stack und so löschen, (verschiebe menuoperator!=0 - Schleife), done
							
							printf("\n");
						
						}
						
						if (ttt != 0) {
							time4 = time(NULL);
							time_saver += difftime(time4, time3);
						}
					}	//Menu-end
					
					menuoperator = 0;
					
					if (var_[6] == 10) {
						menuoperator = 1;
						var_[6] = 5;
					}
					
					if ((tac != 0)&&(var_[6] <= 62)&&(var_[6] > 10)){
						unsigned int tac_controll;
						tac_controll = 0;
						if (((var_[6]%10) > 2)||((var_[6]%10) == 0)){
							var_[6] = 7;
							menuoperator = 1;
						} else {
							for (unsigned int z=var_[6]; z>2; z-=10){
								tac_controll += 1;
							}
							if (tac_controll == 6){
								tac_controll = 0;
							}
							if (DDD[tac_controll] == 0){
								var_[6] = 7;
								menuoperator = 1;
							} else {
								DDD[tac_controll] -= 1;
							}
						}
					} else if ((tac != 0)&&(var_[6] != 100)&&(var_[6] != 1010)&&(var_[6] != 0)) {
						var_[6] = 7;
					}		
					//tac-mode
					
					if (opt == 5){
						controll_1 = 10+use_number;
						controll_2 = 11+use_number;
					
						for (unsigned int i=0; i<use_number-1; i+=1){
							controll_1 += 9;
							controll_2 += 9;
						}
					
						if (var_[6] == 0){
							controll_1 = 0;
							controll_2 = 0;
						}
						if (var_[6] == 100){
							controll_1 = 100;
							controll_2 = 100;
						}
						if (var_[6] == 1010){
							controll_1 = 1010;
							controll_2 = 1010;
						}
					}
					//
					if (((var_[6] > 0)&&(var_[6] < 10))||(((opt == 5)&&(var_[6] != controll_1))&&((opt == 5)&&(var_[6] != controll_2)))){
						
						if (var_[6] != 5) {
							printf("	You made a mistake, try again: \n");
							printf("\n");
							printf("\n");
						} else {
							printf("	You closed the menu. \n");
							printf("\n");
							printf("\n");
						}
						
						//enough
						
						menuoperator = 1;
					}
					
				}		// menuoperator = 0
				
				suprise = 0;
				
				if (var_[6] == 0){
					printf("	Do you really want to end the game ? \n");
					printf("	Yes: 0		No: 1 \n");
					scanf("%u", &lim);
					if (lim == 0){
						break;
					} else if (lim == 1){
						continue;
					} else {
						printf("	0 or 1, it is so difficult to understand? \n");
						printf("	Well, it seems I have to end it by myself... \n");
						break;
					}	
				} else {
					
					if (var_[6] == 100){		//gamemode 6 modify, done
						
						var_[0] = 1;
						
						for (unsigned int i=1; i<m-1; i+=1){
							for (unsigned int j=1; j<n-1; j+=1){
								Sf[i][j] = cons_field_5[i][j];
								
								if (journey == 1){
									Sf_journey[i][j] = cons_journey_5[i][j];
								}
							}
						}
						
						if (opague >= 1) {
							Sf_opague = opague_builder (Sf, m, n, geben, opague, aop);
						}
						
						if (opague >= 1) {
							show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
						} else {
							show_field (Sf, m, n, gamemode, information_code, geben, Colored);
						}
						
						cons[geben] = use_number;
						
						use_number = cons[5];
						
						if (gamemode == 11) {	//mehr-gamemode
							for (unsigned int p=2; p<=5; p+=1) {
								
								dynamic_pointer[p] = dynamic_pointer_save[5][p-2];
								
							}
						}
						
						g-=1;
						var_[6] = 1010;
						if (gamemode == 10) {
							ulcer_lifes[6] += 1;
							ulcer_start[6] = 0;
						}
						continue;
					} else {
						
						if (number_of_players == 6) {
							
							if (var_[1] != 1010){
								for (unsigned int i=1; i<m-1; i+=1){
									for (unsigned int j=1; j<n-1; j+=1){
										cons_field_6[i][j] = Sf[i][j];
										
										if (journey == 1){
											cons_journey_6[i][j] = Sf_journey[i][j];
										}
									}
								}
							}
						} else if (number_of_players >= 7) {
							if (var_[7] != 1010){
								for (unsigned int i=1; i<m-1; i+=1){
									for (unsigned int j=1; j<n-1; j+=1){
										cons_field_6[i][j] = Sf[i][j];
										
										if (journey == 1){
											cons_journey_6[i][j] = Sf_journey[i][j];
										}
									}
								}
							}
						}
						
						var_[0] = 0;
						
						if (var_[6] < 50){
							
							if (var_[6] == 11){BBB[1] += 1; Plus (m, n, geben, Sf, limit_at_all, gamemode, information_code, number_of_players, Colored, opague, Sf_opague);}
							if (var_[6] == 12){BBB[1] += 1; Minus (m, n, geben, Sf, gamemode, information_code, Colored, opague, Sf_opague);}
							if (var_[6] == 21){BBB[2] += 1; Move (m, n, geben, Sf, gamemode, information_code, Colored, opague, Sf_opague);}
							if (var_[6] == 41){BBB[4] += 1; Move (m, n, geben, Sf, gamemode, information_code, Colored, opague, Sf_opague);}
							if (var_[6] == 22){BBB[2] += 1; Change (m, n, geben, Sf, gamemode, information_code, Colored, opague, Sf_opague, position);}
							if (var_[6] == 31){BBB[3] += 1; Destroy (m, n, geben, Sf, gamemode, information_code, Colored, opague, Sf_opague);}
							if (var_[6] == 42){
								BBB[4] += 1; 
								Boost (geben, Sf, m, n, temp, gamemode);
							}
						} else {
							if (var_[6] == 51){BBB[5] += 1; w += 1;}		//w
							if (var_[6] == 52){BBB[5] += 1; w -= 1;}		//w
							if (var_[6] == 61){BBB[6] += 1; e += 1;}		//e
							if (var_[6] == 62){BBB[6] += 1; if (d != 0) {d -= 1;} else {d = 10;}}		//d
						}		//printf("ok(1376)");
						
						if (ttt != 0) {
							time2 = time(NULL);
							time_warning = ((difftime(time2, time1)) - time_saver);
							
							//printf("	time_warning: %f \n", time_warning);		//test
							
							if ((pere[geben] != 0)&&((pere[geben] + warning_system) <= 6)) {
								if (pere[geben] == 1) {
									if (warning_system <= 2) {
										time_warning += 1.0;
									} else if (warning_system == 3) {
										time_warning += 2.0;
									} else if (warning_system == 4) {
										time_warning += 3.0;
									} else if (warning_system == 5) {
										time_warning += 5.0;
									}
								} else if (pere[geben] == 2) {
									if (warning_system == 1) {
										time_warning += 2.0;
									} else if (warning_system == 2) {
										time_warning += 3.0;
									} else if (warning_system == 3) {
										time_warning += 5.0;
									} else if (warning_system == 4) {
										time_warning += 6.0;
									}
								} else if (pere[geben] == 3) {
									if (warning_system == 1) {
										time_warning += 3.0;
									} else if (warning_system == 2) {
										time_warning += 5.0;
									} else if (warning_system == 3) {
										time_warning += 8.0;
									}
								} else if (pere[geben] == 4) {
									if (warning_system == 1) {
										time_warning += 4.0;
									} else if (warning_system == 2) {
										time_warning += 7.0;
									}
								} else if (pere[geben] == 5) {
									if (warning_system == 1) {
										time_warning += 5.0;
									}
								}
							}
							
							if (time_warning > (1.0*ttt)) {
								pere[0] += 1;
								printf("	You took too much time! %f sec more than you should. \n", (time_warning-1.0*ttt) );
								printf(" \n");
								for (unsigned int p=16; p>=1; p-=3) {	//index_verschiebung
									if ((time_warning-1.0*ttt) > 1.0*(p-1)) {
										pere[geben] = (((p-1)/3) + 1);
										break;
									}
								}
							} else {
								pere[geben] = 0;
							}
						}
						
						Sf_nl_6 = new_life_6 (Sf, m, n, w, gamemode, information_code);		//printf("ok(1378)");
						
						if (gamemode == 6) {
							
							precounter = 0;
							for (unsigned int i=1; i<m-1; i+=1){
								for (unsigned int j=1; j<n-1; j+=1){
									if (Sf[i][j] == 11){
										if (Sf_nl_3[i][j-1] > 1) {
											printf (" Sieg: Spieler %u \n", Sf_nl_3[i][j-1]);
											precounter += 1;
										}
										if (Sf_nl_3[i][j+1] > 1) {
											if (precounter == 0) {
												printf (" Sieg: Spieler %u \n", Sf_nl_3[i][j+1]);
											}
											precounter += 1;
										}
										if (Sf_nl_3[i-1][j] > 1) {
											if (precounter == 0) {
												printf (" Sieg: Spieler %u \n", Sf_nl_3[i-1][j]);
											}
											precounter += 1;
										}
										if (Sf_nl_3[i+1][j] > 1) {
											if (precounter == 0) {
												printf (" Sieg: Spieler %u \n", Sf_nl_3[i+1][j]);
											}
											precounter += 1;
										}
										if (precounter == 2) {
											printf(" Double-catch! \n");
										}
										if (precounter == 3) {
											printf(" TRIPLE-catch!! \n");
										}
										if (precounter == 4) {
											printf(" QUADRO-CATCH!!! \n");
										}
										break;
									}
								}
								if (precounter > 0) {
									break;
								}
							}
							if (precounter > 0) {
								for (unsigned int i=1; i<m-1; i+=1){
									for (unsigned int j=1; j<n-1; j+=1){
										if (Sf_nl_3[i][j] == geben) {
											Sf[i][j] = geben;
										}
									}
								}
								show_field (Sf, m, n, gamemode, information_code, geben, Colored);
								break;
							}
						}
						
						controll = 0;
						if (gamemode == 7) {	// possible to modify
							for (unsigned int i=(m-2); i>=(m-1)/2; i-=1){		//Spiel-Ende?
								if ((Sf_nl_6[i][n-2] == 6)||(Sf[i][n-2] == 6)){
									for (unsigned int k=(m-2); k>=1; k-=1){
										if (Sf_nl_6[k][n-2] == 6){
											Sf[k][n-2] = 6;
										}
									}
									show_field (Sf, m, n, gamemode, information_code, geben, Colored);
									printf("	Sieg:	Spieler 6 \n");
									controll = 1;
								}
							}
							if (controll == 1){
								break;
							}
						}
						controll = 0;
						
						num_1 = 0;
						for (unsigned int i=1; i<m-1; i+=1){
							for (unsigned int j=1; j<n-1; j+=1){
								if (Sf_nl_6[i][j] == 6){
									num_1 += 1;
								}
							}
						}		//printf("ok(1387)");	
					
						if (var_[6] == 42){
							for (unsigned int i=1; i<m-1; i+=1){
								for (unsigned int j=1; j<n-1; j+=1){
									if (gamemode == 8) {
										if (temp[i][j] == 6){
											Sf[i][j] = 0;
										}
									} else if ((gamemode == 9)||(gamemode == 10)||(gamemode == 11)||(gamemode == 12)) {	//mehr-gamemode
										if (temp[i][j] != 0){
											Sf[i][j] = temp[i][j];
										}
									} else if (gamemode == 6) {	//10
										if (temp[i][j] == 6){
											Sf[i][j] = 1;
										}
									}
								}
							}
						}		//printf("ok(1398)");	
						// possible to modify
						
						controll = 0;
						if (gamemode == 1){
							for (unsigned int erste=1; erste<n-1; erste+=1){		//printf("ok(1400)");		//Spiel-Ende?
								if (Sf[1][erste] == 6){
									printf("	Sieg:	Spieler 6 \n");
									show_field (Sf, m, n, gamemode, information_code, geben, Colored);
									controll = 1;		//printf("ok(1404)");
									break;
								}
							}
							if (controll == 1){
								break;		//printf("ok(1409)");
							}		//printf("ok(1410)");
						}	// possible to modify
						controll = 0;
						
						Spielfeld_Destroy (temp, m);		//printf("ok(1412)");
					
						Sf_od_6 = old_dying_6 (Sf, m, n, d, e, gamemode, information_code);		//printf("ok(1414)");
						
						if (journey == 1){
							unsigned int journey_max;
							journey_max = 0;
							for (unsigned int i=1; i<m-1; i+=1){
								for (unsigned int j=1; j<n-1; j+=1){
									if (Sf_journey[i][j] == 6){
										journey_max += 1;
									}
								}
							}
							for (unsigned int i=1; i<m-1; i+=1){
								for (unsigned int j=1; j<n-1; j+=1){
									if ((Sf_od_6[i][j] == 606) && (Sf_journey[i][j] == 0) && (journey_max >= limit_at_all)){
										for (unsigned int u=(m-2); u>0; u-=1){
											for (unsigned int o=1; o<(n-1); o+=1){
												if ((Sf_journey[u][o] == 6)&&((u+o)%2 == 0)){
													Sf_journey[u][o] = 0;
													journey_max -= 1;
													if (journey_max < limit_at_all){
														break;
													}
												}
											}
											if (journey_max < limit_at_all){
												break;
											}
										}
										
									}
									if ((Sf_od_6[i][j] == 606) && (Sf_journey[i][j] == 0) && (journey_max < limit_at_all)){
										Sf_journey[i][j] = 6;
										journey_max += 1;
									}
								}
							}
							journey_max = 0;
						}
						
						if (var_[6] == 32){BBB[3] += 1; Revive_6(m, n, Sf_od_6, Sf);}
						
						num_2 = 0;
						for (unsigned int i=1; i<m-1; i+=1){
							for (unsigned int j=1; j<n-1; j+=1){
								if (Sf_od_6[i][j] == 606){
									num_2 += 1;
								}
							}
						}
					
						count_new = 0;
						for (unsigned int i=1; i<m-1; i+=1){
							for (unsigned int j=1; j<n-1; j+=1){
								if (Sf_nl_6[i][j] == 6){
									count_new += 1;
								}
							}
						}
						ent = limit_new;		//printf("ok(1473)");
						
						for (unsigned int i=1; i<m-1; i+=1){
							for (unsigned int j=1; j<n-1; j+=1){
								if ((Sf[i][j] == 6) && (Sf_od_6[i][j] == 0)){
									zeitgewinner += 1;
								}
							}
						}
						
						if (count_new > limit_new){		//Abfrage auf max. 10 neue Steine
							/*if (gamemode == 1) {
								Sf_nl_6 = Index_6 (ent, count_new, m, n, Sf, Sf_nl_6, Sf_od_6, limit_new, limit_at_all, zeitgewinner);	
							} else if (gamemode == 2) {
								Sf_nl_6 = Index_6_col (ent, count_new, m, n, Sf, Sf_nl_6, Sf_od_6, limit_new, limit_at_all, zeitgewinner);	
							} else if (gamemode == 3) {
								Sf_nl_6 = Index_6_con (ent, count_new, m, n, Sf, Sf_nl_6, limit_new);
							} else if (gamemode == 4) {
								Sf_nl_6 = Index_6_fal (ent, count_new, m, n, Sf, Sf_nl_6, Sf_od_6, limit_new, limit_at_all, zeitgewinner);	
							} else if (gamemode == 5) {
								Sf_nl_6 = Index_6_fig (ent, count_new, m, n, Sf, Sf_nl_6, Sf_od_6, limit_new, limit_at_all, zeitgewinner);	
							} else if (gamemode == 7) {
								Sf_nl_6 = Index_6_race (ent, count_new, m, n, Sf, Sf_nl_6, Sf_od_6, limit_new, limit_at_all, zeitgewinner);	
							} else if (gamemode == 8) {
								Sf_nl_6 = Index_6_rain (ent, count_new, m, n, Sf, Sf_nl_6, Sf_od_6, limit_new, limit_at_all, rain, zeitgewinner);	
							}*/
							if (gamemode == 6) {
								Sf_nl_6 = Index_other_hunt (ent, count_new, m, n, Sf_nl_6, geben, zeitgewinner, Sf, limit_at_all);	
							} else if (gamemode == 9) {
								Sf_nl_6 = Index_are (ent, count_new, m, n, Sf_nl_6, Sf_od_6, limit_new, limit_at_all, zeitgewinner, Sf, w, d, e, geben);
							} else if (gamemode == 10) {
								count_new = 0;
							} else if (gamemode == 11) {
								Sf_nl_6 = Index_dyn (ent, count_new, m, n, Sf_nl_6, Sf_od_6, limit_new, limit_at_all, zeitgewinner, Sf, w, d, e, geben, position);
							} else if (gamemode == 12) {	//mehr-gamemode
								count_new = 0;
							}
						
						}
						ent = 0;
						count_new = 0;		//printf("ok(1478)");
					
						num_3 = 0;
						for (unsigned int i=1; i<m-1; i+=1){
							for (unsigned int j=1; j<n-1; j+=1){
								if (((Sf[i][j] == 6) && (Sf_od_6[i][j] == 0)) || (Sf_nl_6[i][j] == 6)){
									count_new += 1;
									num_3 += 1;
								}
							}
						}
						
						ent = limit_at_all;
						if ((gamemode == 1)||(gamemode == 2)||(gamemode == 4)||(gamemode == 5)||(gamemode == 7)||(gamemode == 8)) {
							
							if (var_[6] == 52){
											//printf("ok(1492)");
								lim = 0;
								for (unsigned int i=1; i<m-1; i+=1){
									for (unsigned int j=1; j<n-1; j+=1){
										if ((Sf[i][j] == 6) && (Sf_od_6[i][j] == 0)){
											lim += 1;
										}
									}
								}
											//printf("ok(1501)");
								ent = lim;
											//printf("ok(1503)");
								lim = 0;
								for (unsigned int i=1; i<m-1; i+=1){
									for (unsigned int j=1; j<n-1; j+=1){
										if (Sf[i][j] == 1){
											lim += 1;
										}
									}
								}			//printf("ok(1511)");
							
							
								if ((lim <= limit_new) && (ent < (limit_at_all - 1))){
									if (ent >= (limit_at_all - 3)){
										ent = limit_at_all - 1;
									} else if (ent >= (limit_at_all - 5)){
										ent = limit_at_all - 2;
									} else if (ent >= (limit_at_all - 7)){
										ent = limit_at_all - 3;
									} else if (ent >= (limit_at_all - 10)){
										ent = limit_at_all - 4;
									} else {
										ent = limit_at_all;
									}		//printf("ok(1523)");
								} else {		//printf("ok(1524)");
									ent = limit_at_all;
								}
								lim = 0;
											//printf("ok(1528)");
							}
						}	// possible to modify
						
						if (count_new > ent){		//Abfrage auf insgesamt max. 20 Steine, normalerweise
							/*if (gamemode == 1) {
								Sf_nl_6 = Index_6 (ent, count_new, m, n, Sf, Sf_nl_6, Sf_od_6, limit_new, limit_at_all, zeitgewinner);	
							} else if (gamemode == 2) {
								Sf_nl_6= Index_6_col  (ent, count_new, m, n, Sf, Sf_nl_6, Sf_od_6, limit_new, limit_at_all, zeitgewinner);	
							} else if (gamemode == 3) {
								count_new = 0;
							} else if (gamemode == 4) {
								Sf_nl_6 = Index_6_fal (ent, count_new, m, n, Sf, Sf_nl_6, Sf_od_6, limit_new, limit_at_all, zeitgewinner);	
							} else if (gamemode == 5) {
								Sf_nl_6 = Index_6_fig (ent, count_new, m, n, Sf, Sf_nl_6, Sf_od_6, limit_new, limit_at_all, zeitgewinner);	
							} else if (gamemode == 7) {
								Sf_nl_6 = Index_6_race (ent, count_new, m, n, Sf, Sf_nl_6, Sf_od_6, limit_new, limit_at_all, zeitgewinner);	
							} else if (gamemode == 8) {
								Sf_nl_6 = Index_6_rain (ent, count_new, m, n, Sf, Sf_nl_6, Sf_od_6, limit_new, limit_at_all, rain, zeitgewinner);	
							}*/
							if (gamemode == 6) {
								Sf_nl_6 = Index_other_hunt (ent, count_new, m, n, Sf_nl_6, geben, zeitgewinner, Sf, limit_at_all);	
							} else if (gamemode == 9) {
								Sf_nl_6 = Index_are (ent, count_new, m, n, Sf_nl_6, Sf_od_6, limit_new, limit_at_all, zeitgewinner, Sf, w, d, e, geben);	
							} else if (gamemode == 10) {
								count_new = 0;
							} else if (gamemode == 11) {
								Sf_nl_6 = Index_dyn (ent, count_new, m, n, Sf_nl_6, Sf_od_6, limit_new, limit_at_all, zeitgewinner, Sf, w, d, e, geben, position);
							} else if (gamemode == 12) {	//mehr-gamemode
								count_new = 0;
							}
						
						}
						ent = 0;
						zeitgewinner = 0;

						if (gamemode == 4) {
							touch (Sf, m, n, geben, Sf_nl_1, Sf_nl_2);	//possible to modify
						}
						
						Sf = change_6 (Sf, Sf_nl_6, Sf_od_6, m, n, gamemode, number_of_players, ges);
						
						if (gamemode == 1) {
							for (unsigned int j=1; j<n-1; j+=1){	//possible to modify
								if (Sf[2][j] == 2){
									B[0] += 1;
									break;
								}
							} 
						} else if (gamemode == 2) {	//possible to modify
							for (unsigned int j=2; j<n-1; j+=((n-1)/2)-2){		//collect-Bed. prüfen
								unsigned int b;
								b = 0;
								if (Sf[((m-1)/2)][j] == 7){
									if (Sf[((m-1)/2)-1][j]==2){b += 1;}
									if (Sf[((m-1)/2)+1][j]==2){b += 1;}
									if (Sf[(m-1)/2][j-1]==2){b += 1;}
									if (Sf[(m-1)/2][j+1]==2){b += 1;}
									if (b >= 3){
										B[0] += 1;
										Sf[((m-1)/2)][j] = 2;
									}
								}
							}
							if (B[0] == 2){
								printf("\n");
								printf("	Sieg: Spieler 2 \n");
								printf("\n");
								show_field (Sf, m, n, gamemode, information_code, geben, Colored);
								break;
							}
						}
						
						
						if ((gamemode == 6)&&(geben == number_of_players)) {
							lim = 1;
							printf("	\n");
							if (opague >= 1) {
								show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
							} else {
								show_field (Sf, m, n, gamemode, information_code, geben, Colored);
							}
							printf("	\n");
							while (lim == 1) {
								printf("	\n");
								printf("	\n");
								printf("	Are you ready to make your turn? \n");
								printf("	Yes: 1 \n");
								printf("	\n");
								printf("	\n");
								scanf("%u", &lim);
								
								if (lim != 1) {
									lim = 1;
								} else {
									lim = 0;
								}
							}
						}
						if (gamemode == 6) {
							information_code[3] = 0;
						}
						
						controll = 0;
						if (gamemode == 1) {	//possible to modify
							for (unsigned int erste=1; erste<n-1; erste+=1){		//Spiel-Ende?
								if (Sf[1][erste] == 2){
									printf("	Sieg:	Spieler 2 \n");
									controll = 1;
									break;
								}
							}
							if (controll == 1){
								break;
							}
						}
						controll = 0;
						
						if (gamemode == 3) {	//possible to modify
							if (opague >= 1) {
								show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
							} else {
								show_field (Sf, m, n, gamemode, information_code, geben, Colored);
							}
							battle (m, n, Sf, geben);
						}
						
						if (number_of_players == 6) {// gamemode 6 modify, done!
							if (var_[1] != 1010) {
								cons[6] = use_number;
								
								if (gamemode == 11) {	//mehr-gamemode
									for (unsigned int p=2; p<=5; p+=1) {
										
										dynamic_pointer_save[6][p-2] = dynamic_pointer[p];
										
									}
								}
								
							}
						} else if (number_of_players >= 7) {
							if (var_[7] != 1010) {
								cons[6] = use_number;
								
								if (gamemode == 11) {	//mehr-gamemode
									for (unsigned int p=2; p<=5; p+=1) {
										
										dynamic_pointer_save[6][p-2] = dynamic_pointer[p];
										
									}
								}
								
							}
						}
						
						use_number = random_number (num_1, num_2, num_3, use_number, g, var_, number_3, number_4);
						
						if ((opt != 5)&&(var_[6] <= 62)){
							controll_2 = 0;
							for (unsigned int z=var_[6]; z>2; z-=10){
								controll_2 += 1;
							}
							number_6 = controll_2;
							//printf("%u \n", number_6);
							controll_2 = 0;
						}
					}
				}	//{}ausfindig machen
			} else if (geben == 7) {		//following players
				
				if (opague >= 1) {
					Sf_opague = opague_builder (Sf, m, n, geben, opague, aop);
					
				}
				
				if ((ttt != 0)&&(pere[geben] == 100)) {
					g += 1;
					continue;
				}
				
				if ((gamemode == 10)&&(ulcer_start[7] == 0)) {
					if (opague >= 1) {
						show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
					} else {
						show_field (Sf, m, n, gamemode, information_code, geben, Colored);
					}
					g += 1;
					continue;
				}
				
				if ((ges[7] == 7070)&&((gamemode == 6)||(gamemode == 9)||(gamemode == 10)||(gamemode == 11)||(gamemode == 12))) {	//mehr-gamemode
					g+=1;
					var_[7] = 7070;
					cons[7] = cons[6];
					for (unsigned int i=1; i<m-1; i+=1){
						for (unsigned int j=1; j<n-1; j+=1){
							cons_field_7[i][j] = cons_field_6[i][j];
							if (journey == 1){
								cons_journey_7[i][j] = cons_journey_6[i][j];
								
								if (Sf_journey[i][j] == 7) {
									Sf_journey[i][j] = 0;
								}
							}
							if (gamemode == 11) {	//mehr-gamemode
								for (unsigned int p=2; p<=5; p+=1) {
									
									dynamic_pointer_save[7][p-2] = dynamic_pointer_save[6][p-2];
									
								}
							}
						}
					}
					if (var_[0] == 1) {
						g-=2;
					}
					continue;
				}
				
				w = 3;
				d = 2;
				e = 3;
				if (gamemode == 9) {
					if (ability[1] == geben) {
						w = 1;
						d = 0;
						e = 1;
						information_code[0] = 1;
					} else if (ability[2] == geben) {
						w = 2;
						d = 1;
						e = 2;
						information_code[0] = 2;
					} else if (ability[3] == geben) {
						w = 4;
						d = 1;
						e = 4;	//abweichende e-definition
						information_code[0] = 3;
					} else if (ability[4] == geben) {
						information_code[0] = 4;
					} else if (ability[5] == geben) {
						information_code[0] = 5;
					} else if (ability[6] == geben) {
						information_code[0] = 6;
					} else if (ability[7] == geben) {
						information_code[0] = 7;
					} else if (ability[8] == geben) {
						information_code[0] = 8;
					} else if (ability[9] == geben) {
						information_code[0] = 9;
						
						if (opague >= 1) {
							show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
						} else {
							show_field (Sf, m, n, gamemode, information_code, geben, Colored);
						}
						
						for (unsigned int i=1; i<m-1; i+=1){
							for (unsigned int j=1; j<n-1; j+=1){
								if (Sf[i][j] == geben) {
									if ((Sf[i+1][j] != 0)&&(Sf[i+1][j] != geben)&&((i+2) <= (m-2))) {
										if (Sf[i+2][j] == 0) {
											Sf[i+2][j] = Sf[i+1][j];
											Sf[i+1][j] = 0;
										}
									}
									if ((Sf[i-1][j] != 0)&&(Sf[i-1][j] != geben)&&((i-2) >= 1)) {
										if (Sf[i-2][j] == 0) {
											Sf[i-2][j] = Sf[i-1][j];
											Sf[i-1][j] = 0;
										}
									}
									if ((Sf[i][j-1] != 0)&&(Sf[i][j-1] != geben)&&((j-2) >= 1)) {
										if (Sf[i][j-2] == 0) {
											Sf[i][j-2] = Sf[i][j-1];
											Sf[i][j-1] = 0;
										}
									}
									if ((Sf[i][j+1] != 0)&&(Sf[i][j+1] != geben)&&((j+2) <= (n-2))) {
										if (Sf[i][j+2] == 0) {
											Sf[i][j+2] = Sf[i][j+1];
											Sf[i][j+1] = 0;
										}
									}
								}
							}
						}
					}
				}
				
				if (gamemode == 10) {
					w = 2;
					d = 1;
					e = 2;
				}
				
				if (gamemode == 9) {
					if (information_code[0] == 1) {
						limit_at_all = limit_at_all-2;
					} else if (information_code[0] == 2) {
						limit_at_all = limit_at_all-1;
					} else {
						limit_at_all = limit_at_all_saver;
					}
				}
				
				if (ttt != 0) {
					if ((pere[geben] != 0)&&(warning_system <= 5)&&((pere[geben]+warning_system) == 7)) {
						g += 1;
						printf(" \n ");
						printf("	You got a penalty. \n ");
						printf(" \n ");
						pere[geben] = 0;
						continue;
					} else if ((pere[geben] != 0)&&(warning_system != 0)&&(((warning_system <= 5)&&((pere[geben]+warning_system) == 8))||((warning_system == 6)&&(pere[geben] == 1)))) {
						Sf_od_7 = old_dying_7 (Sf, m, n, d, e, gamemode, information_code);
						Sf = change_7 (Sf, Sf_nl_7, Sf_od_7, m, n, gamemode, number_of_players, ges); 	//Change befreit
						g += 1;
						printf(" \n ");
						printf("	You got a penalty. \n ");
						printf(" \n ");
						pere[geben] = 0;
						continue;
					} else if (((warning_system <= 5)&&((warning_system + pere[geben]) >= 9))||((warning_system >= 6)&&((warning_system + pere[geben]) >= 8))) {
						printf("	Niederlage: Spieler 7 \n ");
						for (unsigned int i=1; i<m-1; i+=1){
							for (unsigned int j=1; j<n-1; j+=1){
								if (Sf[i][j] == 7) {
									Sf[i][j] = 0;
								}
							}
						}
						ges[7] = 7070;
						player_counter += 1;
						pere[geben] = 100;
						g += 1;
						continue;
					}
				}
				
				if (var_[geben] == 1010) {
					use_number = cons[geben];
					if (opt == 5) {
					
						printf("	Player %u ,do you want to keep your number (%u) or do you want to get the next one? \n", geben, cons[geben]);
						printf("	Keep the number: 	1 \n");
						printf("	Get the next one:	2 \n");
						scanf("%u", &lim);
						
						if (lim == 2) {
							use_number = random_number (num_1, num_2, num_3, use_number, g, var_, number_3, number_4);
						} else if (lim != 1) {
							printf("	Well, you keep your number, but next time please take an option i offered. \n\n");
						}
						lim = 0;
					
					}
				}
				
				if (var_[geben%number_of_players+1] == 1010){		//geben%number_of_players+1 ist der Nachfolger von geben.
					if (tac != 0) {
						if (number_7 <= 5){
							CCCC[number_7] += 1;
						} else if (number_7 == 6){
							CCCC[0] += 1;
						}
					} else if (opt == 5) {
						AAAA[use_number] -= 1;
					} else {
						AAAA[number_7] -= 1;
					}
					
				}
				
				if ((tac != 0)&&((CCCC[1]+CCCC[2]+CCCC[3]+CCCC[4]+CCCC[5]+CCCC[0]) == 0)){
					for (unsigned int p=0; p<=5; p+=1){
						CCCC[p] = tac;
					}
				}
				
				menuoperator = 1;
				
				
				while (menuoperator != 0) {
					
					if (gamemode != 8) {
						if (opague >= 1) {
							show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
						} else {
							show_field (Sf, m, n, gamemode, information_code, geben, Colored);
						}
					}
					
					if ((gamemode == 6)&&(((scwhp == 1)&&((opt == 0)||((use_number == 2)||(use_number == 3)||(use_number == 4)))&&((tac == 0)||((CCCC[2] != 0)||(CCCC[3] != 0)||(CCCC[4] != 0))))||(scwhp == 2))) {
						
						information_code[3] = 1;
						
						if (opague >= 1) {
							show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
						} else {
							show_field (Sf, m, n, gamemode, information_code, geben, Colored);
						}
					}
					
					if (gamemode == 4) {
						printf("\n");
						printf("	Points player 7: 	%u Point(s) \n", P[geben]);
					}	// possible to modify
					
					if (gamemode == 10) {
						printf("\n");
						printf("	Lifes player 7: 	%u Life(s) \n", ulcer_lifes[7]);
					}
					
					if (gamemode == 11) {
						printf("	\n");
						printf("	Geschwindigkeit: 	Zeile: %d, 	Spalte: %d \n", dynamic_pointer[2], dynamic_pointer[3]);
						printf("	Beschleunigung: 	Zeile: %d, 	Spalte: %d \n", dynamic_pointer[4], dynamic_pointer[5]);
						printf("	\n");
					}
					
					printf("\n");
					
					if (Colored[0] == 1) {
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+Colored[geben]);
					}
					
					if ((gamemode != 6)&&(gamemode != 9)&&(gamemode != 10)&&(gamemode != 11)&&(gamemode != 12)){	//mehr-gamemode
						printf("	Am Zug: Spieler 2 (OO)	\n");	// possible to modify
					} else if (gamemode == 6) {
						printf("	Am Zug: Spieler 7 (GG)	\n");
					} else if (gamemode == 9) {
						if (ability[1] == geben) {
							printf("	Am Zug: Spieler 7 (UU)	\n");
						} else if (ability[2] == geben) {
							printf("	Am Zug: Spieler 7 (LL)	\n");
						} else if (ability[3] == geben) {
							printf("	Am Zug: Spieler 7 (AA)	\n");
						} else if (ability[4] == geben) {
							printf("	Am Zug: Spieler 7 (CC)	\n");
						} else if (ability[5] == geben) {
							printf("	Am Zug: Spieler 7 (II)	\n");
						} else if (ability[6] == geben) {
							printf("	Am Zug: Spieler 7 (SS)	\n");
						} else if (ability[7] == geben) {
							printf("	Am Zug: Spieler 7 (PP)	\n");
						} else if (ability[8] == geben) {
							printf("	Am Zug: Spieler 7 (HH)	\n");
						} else if (ability[9] == geben) {
							printf("	Am Zug: Spieler 7 (EE)	\n");
						}
					} else if ((gamemode == 10)||(gamemode == 11)||(gamemode == 12)) {	//mehr-gamemode
						printf("	Am Zug: Spieler 7 (77)	\n");
					}
					
					if (Colored[0] == 1) {
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+7);
					}
					
					printf("\n");
					
					if (tac != 0){
						printf("	Your stack of numbers:	\n	1) [%u],		2) [%u],		3) [%u], \n\n	4) [%u],		5) [%u],		6) [%u],\n", CCCC[1], CCCC[2], CCCC[3], CCCC[4], CCCC[5], CCCC[0]);
						printf("\n");
						printf("\n");
					}
					
					if (opt == 5){		//random number
						printf("	Your number: %u ", use_number);
						printf("\n");
						printf("\n");
						
					}
					
					printf("	1) Plus:	11	Minus: 	12 \n");
					printf("	2) Move:	21	Change: 22 \n");
					printf("	3) Destroy:	31	Revive: 32 \n");
					printf("	4) Move:	41	Boost: 	42 \n");
					if (((gamemode != 9)&&(gamemode != 10))||((gamemode == 10)&&(geben == 1))) {
						printf("	5) 4/5-new:	51	2-new:	52 \n");
						printf("	6) 4-max:	61	1-min:	62 \n");
					} else if (gamemode == 9) {
						if (information_code[0] == 1) {
							printf("	5) 2/3-new:	51	0-new:	52 \n");
							printf("	6) 2-max:	61	-1-min:	62 \n");
						} else if (information_code[0] == 2) {
							printf("	5) 3/4-new:	51	1-new:	52 \n");
							printf("	6) 3-max:	61	0-min:	62 \n");
						} else if (information_code[0] == 3) {
							printf("	5) 5/6-new:	51	3-new:	52 \n");
							printf("	6) 5-max:	61	0-min:	62 \n");
						} else {
							printf("	5) 4/5-new:	51	2-new:	52 \n");
							printf("	6) 4-max:	61	1-min:	62 \n");
						}
					} else if ((gamemode == 10)&&(geben != 1)) {
						printf("	5) 3/4-new:	51	1-new:	52 \n");
						printf("	6) 3-max:	61	0-min:	62 \n");
					}
					printf("							\n");
					printf("		Go back: 100 \n");
					printf("		Menu: 10 \n");
					printf("		End game: 0 \n");
					if ((ttt != 0)&&(time_saver == 0.0)) {
						time1 = time(NULL);
					}
					scanf("%u", &var_[7]);
					
					if (var_[7] == 10){
						if (ttt != 0) {
							time3 = time(NULL);
						}
						while (menuoperator != 7) {
							printf("\n");
							printf("\n");
							printf("	About the game: 1 \n	Statistics: 2 \n	The numbers: 3 \n	The limits: 4 \n	Get Hints: 5 \n	Suprise: 6 \n	Quit Menu: 7 \n");
							scanf("%u", &menuoperator);
							
							if (menuoperator == 1){
								if (gamemode == 1) {
									printf("	How to win? 	Own a square on your last line or force your opponent to lose all his/her ones.\n");
								} else if (gamemode == 2) {
									printf("	How to win? 	Be at 2 of the 3 targets with three of your squares near-by.\n");
								} else if (gamemode == 3) {
									printf("	How to win? 	Take over all your opponent's squares by winning contact-battles.\n");
									printf("	Contact-battles? 	All near-by squares in a row with the contact-square build a chain, beat your opponent in the length.\n");
								} else if (gamemode == 4) {
									printf("	How to win? 	Get more points than your opponent.\n");
									printf("	Note:	Touch the #-square in the near-by to move it to the opposite side. \n");
								} else if (gamemode == 5) {
									printf("	How to win? 	Force your opponent to lose all his/her squares.\n");
								} else if (gamemode == 6) {
									if (geben == 1) {
										printf("	How to win? 	Protect your heart-block so no enemy can touch it.\n");
									} else {
										printf("	How to win? 	Catch the heart-block of the hunted one before it disappears.\n");
									}
								} else if (gamemode == 7) {
									printf("	How to win? 	Reach the end of the field or force your opponent to lose all his/her ones.\n");
									printf("	Note:	Every %u turns in total the #-line will go ahead and destroys everything in it's way.\n Also you are not allowed to cross the mid-line. \n", freq);
								} else if (gamemode == 8) {
									printf("	How to win? 	Reach [1][7] of the field or force your opponent to lose all his/her squares.\n");
									printf("	Note:	Falling down the #-squares will push, destroy, explode, or teleport, transform into yours by contact. \n");
								} else if ((gamemode == 9)||(gamemode == 10)) {
									printf("	How to win? 	Force your opponent to lose all his/her squares while keeping yours alive.\n");
								} else if (gamemode == 11) {
									printf("	How to win? 	Push the ball against your opponent's side.\n");
								} else if (gamemode == 12) {	//mehr-gamemode
									printf("	How to win? 	Stay alive.\n");
								}
								printf("	Surrounding:	The 8 squares around another, at the edge 5, in the corners 3, are called #surrounding. \n");
								printf("	near-by:	The 4 squares around another, at the edge 3, in the corners 2, are called #near-by. \n");
								printf("	Standard actions:	(After your choice of number and not influencing each other) \n	-Development:	If it is your turn and a free square has exactly 3 of yours surrounding it, you will own it.\n");
								printf("	-Losses: 	If it is your turn and a square of yours is surrounded by less than %u or more than %u of yours,\n			it will be set free.\n", d, e);
								if ((gamemode == 10)||(gamemode == 12)) {	//mehr-gamemode
									printf("	Limits: 	This gamemode is unlimited. \n");
								} else if (gamemode == 3) {
									printf("	Limits: 	Your development is limited by %u per round. \n", limit_new);
								} else {
									printf("	Limits: 	Your development is limited by %u per round, your units in total by %u per round. \n", limit_new, limit_at_all);
								}						
							}
							if (menuoperator == 2){
								printf("\n");
								printf("	turns at all: %u \n", g);
								printf("\n");
								printf("	Numbers of player 1: \n");
								printf("		#1 = %u \n", A[1]);
								printf("		#2 = %u \n", A[2]);
								printf("		#3 = %u \n", A[3]);
								printf("		#4 = %u \n", A[4]);
								printf("		#5 = %u \n", A[5]);
								printf("		#6 = %u \n", A[6]);
								printf("\n");
								if (number_of_players >= 2) {	//mehr-gamemode
									printf("	Numbers of player 2: \n");
									printf("		#1 = %u \n", B[1]);
									printf("		#2 = %u \n", B[2]);
									printf("		#3 = %u \n", B[3]);
									printf("		#4 = %u \n", B[4]);
									printf("		#5 = %u \n", B[5]);
									printf("		#6 = %u \n", B[6]);
									printf("\n");
								}
								if (number_of_players >= 3){	//mehr-gamemode
									printf("	Numbers of player 3: \n");
									printf("		#1 = %u \n", AA[1]);
									printf("		#2 = %u \n", AA[2]);
									printf("		#3 = %u \n", AA[3]);
									printf("		#4 = %u \n", AA[4]);
									printf("		#5 = %u \n", AA[5]);
									printf("		#6 = %u \n", AA[6]);
									printf("\n");
								}
								if (number_of_players >= 4){
									printf("	Numbers of player 4: \n");
									printf("		#1 = %u \n", BB[1]);
									printf("		#2 = %u \n", BB[2]);
									printf("		#3 = %u \n", BB[3]);
									printf("		#4 = %u \n", BB[4]);
									printf("		#5 = %u \n", BB[5]);
									printf("		#6 = %u \n", BB[6]);
									printf("\n");
								}
								if (number_of_players >= 5){
									printf("	Numbers of player 5: \n");
									printf("		#1 = %u \n", AAA[1]);
									printf("		#2 = %u \n", AAA[2]);
									printf("		#3 = %u \n", AAA[3]);
									printf("		#4 = %u \n", AAA[4]);
									printf("		#5 = %u \n", AAA[5]);
									printf("		#6 = %u \n", AAA[6]);
									printf("\n");
								}
								if (number_of_players >= 6){
									printf("	Numbers of player 6: \n");
									printf("		#1 = %u \n", BBB[1]);
									printf("		#2 = %u \n", BBB[2]);
									printf("		#3 = %u \n", BBB[3]);
									printf("		#4 = %u \n", BBB[4]);
									printf("		#5 = %u \n", BBB[5]);
									printf("		#6 = %u \n", BBB[6]);
									printf("\n");
								}
								if (number_of_players >= 7){
									printf("	Numbers of player 7: \n");
									printf("		#1 = %u \n", AAAA[1]);
									printf("		#2 = %u \n", AAAA[2]);
									printf("		#3 = %u \n", AAAA[3]);
									printf("		#4 = %u \n", AAAA[4]);
									printf("		#5 = %u \n", AAAA[5]);
									printf("		#6 = %u \n", AAAA[6]);
									printf("\n");
								}
								if (number_of_players >= 8){
									printf("	Numbers of player 8: \n");
									printf("		#1 = %u \n", BBBB[1]);
									printf("		#2 = %u \n", BBBB[2]);
									printf("		#3 = %u \n", BBBB[3]);
									printf("		#4 = %u \n", BBBB[4]);
									printf("		#5 = %u \n", BBBB[5]);
									printf("		#6 = %u \n", BBBB[6]);
									printf("\n");
								}
								if (number_of_players == 9){
									printf("	Numbers of player 9: \n");
									printf("		#1 = %u \n", AAAAA[1]);
									printf("		#2 = %u \n", AAAAA[2]);
									printf("		#3 = %u \n", AAAAA[3]);
									printf("		#4 = %u \n", AAAAA[4]);
									printf("		#5 = %u \n", AAAAA[5]);
									printf("		#6 = %u \n", AAAAA[6]);
									printf("\n");
								}
								
								if ((gamemode == 1)||(gamemode == 6)||(gamemode == 7)||(gamemode == 8)) {
									printf("	Matchballs player 1: 	%u \n", A[0]);
									printf("	Matchballs player 2: 	%u \n", B[0]);
									if (gamemode == 6) {
										if (number_of_players >= 3){printf("	Matchballs player 3: 	%u \n", AA[0]);}
										if (number_of_players >= 4){printf("	Matchballs player 4: 	%u \n", BB[0]);}
										if (number_of_players >= 5){printf("	Matchballs player 5: 	%u \n", AAA[0]);}
										if (number_of_players >= 6){printf("	Matchballs player 6: 	%u \n", BBB[0]);}
										if (number_of_players >= 7){printf("	Matchballs player 7: 	%u \n", AAAA[0]);}
										if (number_of_players >= 8){printf("	Matchballs player 8: 	%u \n", BBBB[0]);}
										if (number_of_players == 9){printf("	Matchballs player 9: 	%u \n", AAAAA[0]);}
									}
								} else if (gamemode == 2) {
									printf("	Squares collected by player 1: 	%u \n", A[0]);
									printf("	Squares collected by player 2: 	%u \n", B[0]);
								} else if (gamemode == 3) {
									printf("	Times with squares <= 5, player 1: 	%u \n", A[0]);
									printf("	Times with squares <= 5, player 2: 	%u \n", B[0]);
								} else if (gamemode == 4) {
									printf("	Points player 1: 		%u \n", P[1]);
									printf("	Points Player 2: 		%u \n", P[2]);
									printf("	Turns with more points player 1: 	%u \n", A[0]);
									printf("	Turns with more points player 2: 	%u \n", B[0]);
									printf("	Number of not decided #-squares: 	%u \n", P[0]);
								} else if (gamemode == 3) {
									printf("	Times with squares < 5, player 1: 	%u \n", A[0]);
									printf("	Times with squares < 5, player 2: 	%u \n", B[0]);
								} else if (gamemode == 9) {
									printf("	Number of excluded abilites: 	%u \n", exclude_counter);
									printf("	Offensive abilities taken: 	%u \n", number_of_players-ability[0]);
									printf("	Defensive abilities taken: 	%u \n", ability[0]);
								} else if (gamemode == 10) {
									for (unsigned int p=1; p<=number_of_players; p+=1) {
										printf("		Spieler %u: %u life(s) left.\n", p, ulcer_lifes[p]);
									}
								} else if (gamemode == 11) {	//mehr-gamemode
									for (unsigned int p=1; p<=number_of_players; p+=1) {
										if ((ges[p] > 1000)||(ges[p] == 0)) {
											printf("	Spieler %u: is out.\n", p);
										} else if (ges[p] < 1000) {
											printf("	Spieler %u: You own %u squares.\n", p, ges[p]);
										}
									}
								} else if (gamemode == 12) {
									for (unsigned int p=1; p<=number_of_players; p+=1) {
										if ((ges[p] > 1000)||(ges[p] == 0)) {
											printf("	Spieler %u: is out.\n", p);
										} else if (ges[p] < 1000) {
											printf("	Spieler %u: You own %u squares.\n", p, ges[p]);
										}
									}
								}
								
								if (ttt != 0) {
									printf("	Number of penalties given until	now: %u \n", pere[0]);
								}
							}
							
							if (menuoperator == 3){
								if ((gamemode != 10)&&(gamemode != 12)) {
									printf("	Plus: Change a free square in the surrounding of yours in one of yours.\n");
								} else {
									printf("	Plus: Change a square in the surrounding of yours in one of yours.\n");
								}
								printf("	Minus: Delete one of your squares.\n");
								printf("	Move: The position of one of yours will change with a free, near-by square.\n");
								printf("	Revive: Your lost squares having no living squares of yours surrounding them at the beginning of your turn,\n		will be revived.\n");
								printf("	%u/%u-new: A free square has to be surrounded by %u or %u of yours during the development.\n", w+1, w+2, w+1, w+2);
								printf("	%u-new: A free square has to be surrounded by %u of yours during the development.\n", d, d);
								printf("	%u-max: A square of yours will survive even by %u of your squares surrounding it.\n", e+1, e+1);
								if (d == 0) {
									printf("	-1-min: A square of yours will survive even by only -1 of your squares surrounding it.\n");
								} else {
									printf("	%u-min: A square of yours will survive even by only %u of your squares surrounding it.\n", d-1, d-1);
								}
								
								if ((gamemode == 1)||(gamemode == 2)||(gamemode == 4)||(gamemode == 5)||(gamemode == 7)||(gamemode == 9)||(gamemode == 10)) {
									printf("	Change: A square of yours and a near-by square of your enemy will change positions.\n");
									printf("	Destroy: Delete a near-by square of your enemy.\n");
									printf("	Boost: Use all near-by squares of your enemy as your own for the development.\n");
									
								} else if (gamemode == 3) {
									
									printf("	Change: A square of yours and a square of your enemy in the surrounding will change positions.\n");
									printf("	Destroy: Delete a surrounding square of your enemy.\n");
									printf("	Boost: Use all surrounding squares of your enemy as your own for the development.\n");
									
								} else if (gamemode == 8) {
									printf("	Change: A square of yours and a near-by #-square will change positions.\n");
									printf("	Destroy: Delete a square of your enemy, but not in the last two lines.\n");
									printf("	Boost: Use all near-by #-squares as your own for the development.\n");
									
								} else if (gamemode == 6) {
									if (geben == 1) {
										printf("	Change: The heart-block and a square of yours will change positions.\n");
										printf("	Destroy: Delete a square of your enemy.\n");
										printf("	Boost: Touching the heart_block no square of yours can die.\n");
									} else {
										printf("	Change: A square of yours and a near-by square of the hunted one will change positions.\n");
										printf("	Destroy: Delete a near-by square of your enemy.\n");
										printf("	Boost: Use all near-by squares of the hunted one as your own for the development.\n");
									}
									
								} else if (gamemode == 11) {	//mehr-gamemode
									printf("	Change: A square of yours and a near-by square of your enemy or the near-by ball will change positions.\n");
									printf("	Destroy: Delete a near-by square of your enemy.\n");
									printf("	Boost: Use all near-by squares of your enemy and the near-by ball as your own for the development.\n");
								} else if (gamemode == 12) {
									printf("	Change: A square of yours and a near-by square of your enemy or a near-by object will change positions.\n");
									printf("	Destroy: Delete a near-by square of your enemy or a near-by object.\n");
									printf("	Boost: Use all near-by squares of your enemy and near-by objects as your own for the development.\n");
								}
								
								printf("\n");
							}
							
							if (menuoperator == 4){	//mehr-gamemode
								if ((gamemode != 10)&&(gamemode != 12)) {
									printf("	Limit of development:	%u \n", limit_new);
									if (gamemode != 3) {
										printf("	Limit in total:		%u \n", limit_at_all);
										printf("	Limit in total with >2-new< taken: %u -0/-1/-2/-3/-4.\n", limit_at_all);
									}
								}
							}
							
							if (menuoperator == 5){
								Spielfeld hint;
								unsigned int b, a;
								hint = Spielfeld_Create (m, n);
								printf("	New: 1 \n	Dying: 2 \n	Both: 3 \n");
								scanf("%u", &menuoperator);
								
								for (unsigned int i=1; i<(m-1); i+=1){
									for (unsigned int j=1; j<(n-1); j+=1){
										if ((gamemode != 6)&&(gamemode != 9)&&(gamemode != 10)&&(gamemode != 11)&&(gamemode != 12)){	//mehr-gamemode
											if (Sf[i][j] == geben){
												hint[i][j] = geben;
											} else if (Sf[i][j] == (geben%2)+1){
												hint[i][j] = (geben%2)+1;
											} else if (Sf[i][j] == 7){
												hint[i][j] = 7;
											} 
										} else if ((gamemode == 6)||(gamemode == 9)||(gamemode == 10)) {	//10
											if (Sf[i][j] == geben){
												hint[i][j] = geben;
											} else if (Sf[i][j] != 0){
												hint[i][j] = 17;
											}
										} else if (gamemode == 11) {
											if (Sf[i][j] == geben){
												hint[i][j] = geben;
											} else if (Sf[i][j] == 77){
												hint[i][j] = 77;
											} else if (Sf[i][j] != 0){
												hint[i][j] = 17;
											}
										} else if (gamemode == 12) {	//mehr-gamemode
											if (Sf[i][j] == geben){
												hint[i][j] = geben;
											} else if (Sf[i][j] == 81){
												hint[i][j] = 81;
											} else if (Sf[i][j] == 82){
												hint[i][j] = 82;
											} else if (Sf[i][j] == 83){
												hint[i][j] = 83;
											} else if (Sf[i][j] == 84){
												hint[i][j] = 84;
											} else if (Sf[i][j] == 75){
												hint[i][j] = 75;
											} else if (Sf[i][j] == 71){
												hint[i][j] = 71;
											} else if (Sf[i][j] != 0){
												hint[i][j] = 17;
											}
										}
									}
								}
								
								if ((menuoperator == 2)||(menuoperator == 3)){
									for (unsigned int i=1; i<(m-1); i+=1){
										for (unsigned int j=1; j<(n-1); j+=1){
											if (Sf[i][j] == geben){
												a = 0;
												for (unsigned int h=(i-1); h<=(i+1); h+=1){
													for (unsigned int k=(j-1); k<=(j+1); k+=1){
														if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
															if (Sf[h][k] == geben){
																a += 1;
															}
														}
													}
												}
												if ((a > 4) || (a < 3)){
													hint[i][j] = 16;
												}
											}
										}
									}
								}
								
								if ((menuoperator == 1)||(menuoperator == 3)){
									for (unsigned int i=1; i<(m-1); i+=1){
										for (unsigned int j=1; j<(n-1); j+=1){
											if (Sf[i][j] == 0){
												b = 0;
												for (unsigned int h=(i-1); h<=(i+1); h+=1){
													for (unsigned int k=(j-1); k<=(j+1); k+=1){
														if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
															if (Sf[h][k] == geben){
																b += 1;
															}
														}
													}
												}
												if (b == 3){
													hint[i][j] = 15;
												}
											}
										}
									}
								}
						
								if (opague >= 1) {
									Sf_opague = opague_builder (hint, m, n, geben, opague, aop);
								}
								
								if (opague >= 1) {
									show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
								} else {
									show_field (hint, m, n, gamemode, information_code, geben, Colored);
								}
								
								if (opague >= 1) {
									Sf_opague = opague_builder (Sf, m, n, geben, opague, aop);
								}
								
								menuoperator = 1;
								Spielfeld_Destroy (hint, m);
							}
							// 2
							if (menuoperator == 6){
								if (suprise == 0) {
									for (unsigned int i=1; i<m-1; i+=1){
										for (unsigned int j=1; j<n-1; j+=1){
											cons_field_7[i][j] = Sf[i][j];
											
											if (journey == 1){
												cons_journey_7[i][j] = Sf_journey[i][j];
											}
										}
									}
									sup_num = use_number;
								}
								
								while (menuoperator != 1) {
						
									printf("	Creator menu. 	Change number: 1	Suprise: 2	Suprise undo: 3	Back: 4 \n");
									scanf ("%u", &lim);
									if (lim == 1){
										printf("	number = ? \n");
										scanf ("%u", &use_number);
									} else if (lim == 2){
								
										printf("\n");
										scanf("%u", &suprise);
								
										if (suprise == 31){
											for (unsigned int i=2; i<m-2; i+=1){
												for (unsigned int j=1; j<n-1; j+=1){
													if (Sf[i][j] != 0){
														if (Sf[i][j] == 1){
															Sf[i][j] = 7;
														} else if (Sf[i][j] == 7){
															Sf[i][j] = 1;
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
													if (Sf[i][j] == 7){
														Sf[i][j] = 0;
													}
													if (i == (m-2)){
														Sf[m-2][j] = 7;
													}
												}
											}
										}
								
									} else if (lim == 3){
										for (unsigned int i=1; i<m-1; i+=1){
											for (unsigned int j=1; j<n-1; j+=1){
												Sf[i][j] = cons_field_7[i][j];
												
												if (journey == 1){
													Sf_journey[i][j] = cons_journey_7[i][j];
												}
											}
										}
										use_number = sup_num;
									} else if (lim == 4){
										menuoperator = 1;
									} else {
										printf("	Invalid comment");
									}
								}
							}
						}	// menuoperator = 7
						
						if (gamemode == 8) {
							if (opague >= 1) {
								show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
							} else {
								show_field (Sf, m, n, gamemode, information_code, geben, Colored);
							}	//show_field über menuoperator = 7 und stack und so löschen, (verschiebe menuoperator!=0 - Schleife), done
							
							printf("\n");
						
						}
						
						if (ttt != 0) {
							time4 = time(NULL);
							time_saver += difftime(time4, time3);
						}
					}	//Menu-end
					
					menuoperator = 0;
					
					if (var_[7] == 10) {
						menuoperator = 1;
						var_[7] = 5;
					}
					
					if ((tac != 0)&&(var_[7] <= 62)&&(var_[7] > 10)){
						unsigned int tac_controll;
						tac_controll = 0;
						if (((var_[7]%10) > 2)||((var_[7]%10) == 0)){
							var_[7] = 7;
							menuoperator = 1;
						} else {
							for (unsigned int z=var_[7]; z>2; z-=10){
								tac_controll += 1;
							}
							if (tac_controll == 6){
								tac_controll = 0;
							}
							if (CCCC[tac_controll] == 0){
								var_[7] = 7;
								menuoperator = 1;
							} else {
								CCCC[tac_controll] -= 1;
							}
						}
					} else if ((tac != 0)&&(var_[7] != 100)&&(var_[7] != 1010)&&(var_[7] != 0)) {
						var_[7] = 7;
					}		
					//tac-mode
					
					if (opt == 5){
						controll_1 = 10+use_number;
						controll_2 = 11+use_number;
					
						for (unsigned int i=0; i<use_number-1; i+=1){
							controll_1 += 9;
							controll_2 += 9;
						}
					
						if (var_[7] == 0){
							controll_1 = 0;
							controll_2 = 0;
						}
						if (var_[7] == 100){
							controll_1 = 100;
							controll_2 = 100;
						}
						if (var_[7] == 1010){
							controll_1 = 1010;
							controll_2 = 1010;
						}
					}
					//
					if (((var_[7] > 0)&&(var_[7] < 10))||(((opt == 5)&&(var_[7] != controll_1))&&((opt == 5)&&(var_[7] != controll_2)))){
						
						if (var_[7] != 5) {
							printf("	You made a mistake, try again: \n");
							printf("\n");
							printf("\n");
						} else {
							printf("	You closed the menu. \n");
							printf("\n");
							printf("\n");
						}
						
						//enough
						
						menuoperator = 1;
					}
					
				}		// menuoperator = 0
				
				
				suprise = 0;
				
				if (var_[7] == 0){
					printf("	Do you really want to end the game ? \n");
					printf("	Yes: 0		No: 1 \n");
					scanf("%u", &lim);
					if (lim == 0){
						break;
					} else if (lim == 1){
						continue;
					} else {
						printf("	0 or 1, it is so difficult to understand? \n");
						printf("	Well, it seems I have to end it by myself... \n");
						break;
					}	
				} else {
					
					if (var_[7] == 100){		//gamemode 6 modify, done
						
						var_[0] = 1;
						
						for (unsigned int i=1; i<m-1; i+=1){
							for (unsigned int j=1; j<n-1; j+=1){
								Sf[i][j] = cons_field_6[i][j];
								
								if (journey == 1){
									Sf_journey[i][j] = cons_journey_6[i][j];
								}
							}
						}
						
						if (opague >= 1) {
							Sf_opague = opague_builder (Sf, m, n, geben, opague, aop);
						}
						
						if (opague >= 1) {
							show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
						} else {
							show_field (Sf, m, n, gamemode, information_code, geben, Colored);
						}
						
						cons[geben] = use_number;
						
						use_number = cons[6];
						
						if (gamemode == 11) {	//mehr-gamemode
							for (unsigned int p=2; p<=5; p+=1) {
								
								dynamic_pointer[p] = dynamic_pointer_save[6][p-2];
								
							}
						}
						
						g-=1;
						var_[7] = 1010;
						if (gamemode == 10) {
							ulcer_lifes[7] += 1;
							ulcer_start[7] = 0;
						}
						continue;
					} else {
						
						if (number_of_players == 7) {
							
							if (var_[1] != 1010){
								for (unsigned int i=1; i<m-1; i+=1){
									for (unsigned int j=1; j<n-1; j+=1){
										cons_field_7[i][j] = Sf[i][j];
										
										if (journey == 1){
											cons_journey_7[i][j] = Sf_journey[i][j];
										}
									}
								}
							}
						} else if (number_of_players >= 8) {
							if (var_[8] != 1010){
								for (unsigned int i=1; i<m-1; i+=1){
									for (unsigned int j=1; j<n-1; j+=1){
										cons_field_7[i][j] = Sf[i][j];
										
										if (journey == 1){
											cons_journey_7[i][j] = Sf_journey[i][j];
										}
									}
								}
							}
						}
						
						var_[0] = 0;
						
						if (var_[7] < 50){
							
							if (var_[7] == 11){AAAA[1] += 1; Plus (m, n, geben, Sf, limit_at_all, gamemode, information_code, number_of_players, Colored, opague, Sf_opague);}
							if (var_[7] == 12){AAAA[1] += 1; Minus (m, n, geben, Sf, gamemode, information_code, Colored, opague, Sf_opague);}
							if (var_[7] == 21){AAAA[2] += 1; Move (m, n, geben, Sf, gamemode, information_code, Colored, opague, Sf_opague);}
							if (var_[7] == 41){AAAA[4] += 1; Move (m, n, geben, Sf, gamemode, information_code, Colored, opague, Sf_opague);}
							if (var_[7] == 22){AAAA[2] += 1; Change (m, n, geben, Sf, gamemode, information_code, Colored, opague, Sf_opague, position);}
							if (var_[7] == 31){AAAA[3] += 1; Destroy (m, n, geben, Sf, gamemode, information_code, Colored, opague, Sf_opague);}
							if (var_[7] == 42){
								AAAA[4] += 1; 
								Boost (geben, Sf, m, n, temp, gamemode);
							}
						} else {
							if (var_[7] == 51){AAAA[5] += 1; w += 1;}		//w
							if (var_[7] == 52){AAAA[5] += 1; w -= 1;}		//w
							if (var_[7] == 61){AAAA[6] += 1; e += 1;}		//e
							if (var_[7] == 62){AAAA[6] += 1; if (d != 0) {d -= 1;} else {d = 10;}}		//d
						}		//printf("ok(1376)");
						
						if (ttt != 0) {
							time2 = time(NULL);
							time_warning = ((difftime(time2, time1)) - time_saver);
							
							//printf("	time_warning: %f \n", time_warning);		//test
							
							if ((pere[geben] != 0)&&((pere[geben] + warning_system) <= 6)) {
								if (pere[geben] == 1) {
									if (warning_system <= 2) {
										time_warning += 1.0;
									} else if (warning_system == 3) {
										time_warning += 2.0;
									} else if (warning_system == 4) {
										time_warning += 3.0;
									} else if (warning_system == 5) {
										time_warning += 5.0;
									}
								} else if (pere[geben] == 2) {
									if (warning_system == 1) {
										time_warning += 2.0;
									} else if (warning_system == 2) {
										time_warning += 3.0;
									} else if (warning_system == 3) {
										time_warning += 5.0;
									} else if (warning_system == 4) {
										time_warning += 6.0;
									}
								} else if (pere[geben] == 3) {
									if (warning_system == 1) {
										time_warning += 3.0;
									} else if (warning_system == 2) {
										time_warning += 5.0;
									} else if (warning_system == 3) {
										time_warning += 8.0;
									}
								} else if (pere[geben] == 4) {
									if (warning_system == 1) {
										time_warning += 4.0;
									} else if (warning_system == 2) {
										time_warning += 7.0;
									}
								} else if (pere[geben] == 5) {
									if (warning_system == 1) {
										time_warning += 5.0;
									}
								}
							}
							
							if (time_warning > (1.0*ttt)) {
								pere[0] += 1;
								printf("	You took too much time! %f sec more than you should. \n", (time_warning-1.0*ttt) );
								printf(" \n");
								for (unsigned int p=16; p>=1; p-=3) {	//index_verschiebung
									if ((time_warning-1.0*ttt) > 1.0*(p-1)) {
										pere[geben] = (((p-1)/3) + 1);
										break;
									}
								}
							} else {
								pere[geben] = 0;
							}
						}
				
						Sf_nl_7 = new_life_7 (Sf, m, n, w, gamemode, information_code);		//printf("ok(1378)");
						
						if (gamemode == 6) {
							
							precounter = 0;
							for (unsigned int i=1; i<m-1; i+=1){
								for (unsigned int j=1; j<n-1; j+=1){
									if (Sf[i][j] == 11){
										if (Sf_nl_3[i][j-1] > 1) {
											printf (" Sieg: Spieler %u \n", Sf_nl_3[i][j-1]);
											precounter += 1;
										}
										if (Sf_nl_3[i][j+1] > 1) {
											if (precounter == 0) {
												printf (" Sieg: Spieler %u \n", Sf_nl_3[i][j+1]);
											}
											precounter += 1;
										}
										if (Sf_nl_3[i-1][j] > 1) {
											if (precounter == 0) {
												printf (" Sieg: Spieler %u \n", Sf_nl_3[i-1][j]);
											}
											precounter += 1;
										}
										if (Sf_nl_3[i+1][j] > 1) {
											if (precounter == 0) {
												printf (" Sieg: Spieler %u \n", Sf_nl_3[i+1][j]);
											}
											precounter += 1;
										}
										if (precounter == 2) {
											printf(" Double-catch! \n");
										}
										if (precounter == 3) {
											printf(" TRIPLE-catch!! \n");
										}
										if (precounter == 4) {
											printf(" QUADRO-CATCH!!! \n");
										}
										break;
									}
								}
								if (precounter > 0) {
									break;
								}
							}
							if (precounter > 0) {
								for (unsigned int i=1; i<m-1; i+=1){
									for (unsigned int j=1; j<n-1; j+=1){
										if (Sf_nl_3[i][j] == geben) {
											Sf[i][j] = geben;
										}
									}
								}
								show_field (Sf, m, n, gamemode, information_code, geben, Colored);
								break;
							}
						}
						
						controll = 0;
						if (gamemode == 7) {	// possible to modify
							for (unsigned int i=(m-2); i>=(m-1)/2; i-=1){		//Spiel-Ende?
								if ((Sf_nl_7[i][n-2] == 7)||(Sf[i][n-2] == 7)){
									for (unsigned int k=(m-2); k>=1; k-=1){
										if (Sf_nl_7[k][n-2] == 7){
											Sf[k][n-2] = 7;
										}
									}
									show_field (Sf, m, n, gamemode, information_code, geben, Colored);
									printf("	Sieg:	Spieler 7 \n");
									controll = 1;
								}
							}
							if (controll == 1){
								break;
							}
						}
						controll = 0;
						
						num_1 = 0;
						for (unsigned int i=1; i<m-1; i+=1){
							for (unsigned int j=1; j<n-1; j+=1){
								if (Sf_nl_7[i][j] == 7){
									num_1 += 1;
								}
							}
						}		//printf("ok(1387)");	
					
						if (var_[7] == 42){
							for (unsigned int i=1; i<m-1; i+=1){
								for (unsigned int j=1; j<n-1; j+=1){
									if (gamemode == 8) {
										if (temp[i][j] == 7){
											Sf[i][j] = 0;
										}
									} else if ((gamemode == 9)||(gamemode == 10)||(gamemode == 11)||(gamemode == 12)) {	//mehr-gamemode
										if (temp[i][j] != 0){
											Sf[i][j] = temp[i][j];
										}
									} else if (gamemode == 6) {	//10
										if (temp[i][j] == 7){
											Sf[i][j] = 1;
										}
									}
								}
							}
						}		//printf("ok(1398)");	
						// possible to modify
						
						controll = 0;
						if (gamemode == 1){
							for (unsigned int erste=1; erste<n-1; erste+=1){		//printf("ok(1400)");		//Spiel-Ende?
								if (Sf[1][erste] == 7){
									printf("	Sieg:	Spieler 7 \n");
									show_field (Sf, m, n, gamemode, information_code, geben, Colored);
									controll = 1;		//printf("ok(1404)");
									break;
								}
							}
							if (controll == 1){
								break;		//printf("ok(1409)");
							}		//printf("ok(1410)");
						}	// possible to modify
						controll = 0;
						
						Spielfeld_Destroy (temp, m);		//printf("ok(1412)");
					
						Sf_od_7 = old_dying_7 (Sf, m, n, d, e, gamemode, information_code);		//printf("ok(1414)");
						
						if (journey == 1){
							unsigned int journey_max;
							journey_max = 0;
							for (unsigned int i=1; i<m-1; i+=1){
								for (unsigned int j=1; j<n-1; j+=1){
									if (Sf_journey[i][j] == 7){
										journey_max += 1;
									}
								}
							}
							for (unsigned int i=1; i<m-1; i+=1){
								for (unsigned int j=1; j<n-1; j+=1){
									if ((Sf_od_7[i][j] == 707) && (Sf_journey[i][j] == 0) && (journey_max >= limit_at_all)){
										for (unsigned int u=(m-2); u>0; u-=1){
											for (unsigned int o=1; o<(n-1); o+=1){
												if ((Sf_journey[u][o] == 7)&&((u+o)%2 == 0)){
													Sf_journey[u][o] = 0;
													journey_max -= 1;
													if (journey_max < limit_at_all){
														break;
													}
												}
											}
											if (journey_max < limit_at_all){
												break;
											}
										}
										
									}
									if ((Sf_od_7[i][j] == 707) && (Sf_journey[i][j] == 0) && (journey_max < limit_at_all)){
										Sf_journey[i][j] = 7;
										journey_max += 1;
									}
								}
							}
							journey_max = 0;
						}
						
						if (var_[7] == 32){AAAA[3] += 1; Revive_7(m, n, Sf_od_7, Sf);}
						
						num_2 = 0;
						for (unsigned int i=1; i<m-1; i+=1){
							for (unsigned int j=1; j<n-1; j+=1){
								if (Sf_od_7[i][j] == 707){
									num_2 += 1;
								}
							}
						}
					
						count_new = 0;
						for (unsigned int i=1; i<m-1; i+=1){
							for (unsigned int j=1; j<n-1; j+=1){
								if (Sf_nl_7[i][j] == 7){
									count_new += 1;
								}
							}
						}
						ent = limit_new;		//printf("ok(1473)");
						
						for (unsigned int i=1; i<m-1; i+=1){
							for (unsigned int j=1; j<n-1; j+=1){
								if ((Sf[i][j] == 7) && (Sf_od_7[i][j] == 0)){
									zeitgewinner += 1;
								}
							}
						}
						
						if (count_new > limit_new){		//Abfrage auf max. 10 neue Steine
							/*if (gamemode == 1) {
								Sf_nl_7 = Index_7 (ent, count_new, m, n, Sf, Sf_nl_7, Sf_od_7, limit_new, limit_at_all, zeitgewinner);	
							} else if (gamemode == 2) {
								Sf_nl_7 = Index_7_col (ent, count_new, m, n, Sf, Sf_nl_7, Sf_od_7, limit_new, limit_at_all, zeitgewinner);	
							} else if (gamemode == 3) {
								Sf_nl_7 = Index_7_con (ent, count_new, m, n, Sf, Sf_nl_7, limit_new);
							} else if (gamemode == 4) {
								Sf_nl_7 = Index_7_fal (ent, count_new, m, n, Sf, Sf_nl_7, Sf_od_7, limit_new, limit_at_all, zeitgewinner);	
							} else if (gamemode == 5) {
								Sf_nl_7 = Index_7_fig (ent, count_new, m, n, Sf, Sf_nl_7, Sf_od_7, limit_new, limit_at_all, zeitgewinner);	
							} else if (gamemode == 7) {
								Sf_nl_7 = Index_7_race (ent, count_new, m, n, Sf, Sf_nl_7, Sf_od_7, limit_new, limit_at_all, zeitgewinner);	
							} else if (gamemode == 8) {
								Sf_nl_7 = Index_7_rain (ent, count_new, m, n, Sf, Sf_nl_7, Sf_od_7, limit_new, limit_at_all, rain, zeitgewinner);	
							}*/
							if (gamemode == 6) {
								Sf_nl_7 = Index_other_hunt (ent, count_new, m, n, Sf_nl_7, geben, zeitgewinner, Sf, limit_at_all);	
							} else if (gamemode == 9) {
								Sf_nl_7 = Index_are (ent, count_new, m, n, Sf_nl_7, Sf_od_7, limit_new, limit_at_all, zeitgewinner, Sf, w, d, e, geben);
							} else if (gamemode == 10) {
								count_new = 0;
							} else if (gamemode == 11) {
								Sf_nl_7 = Index_dyn (ent, count_new, m, n, Sf_nl_7, Sf_od_7, limit_new, limit_at_all, zeitgewinner, Sf, w, d, e, geben, position);
							} else if (gamemode == 12) {	//mehr-gamemode
								count_new = 0;
							}
							
						}
						ent = 0;
						count_new = 0;		//printf("ok(1478)");
					
						num_3 = 0;
						for (unsigned int i=1; i<m-1; i+=1){
							for (unsigned int j=1; j<n-1; j+=1){
								if (((Sf[i][j] == 7) && (Sf_od_7[i][j] == 0)) || (Sf_nl_7[i][j] == 7)){
									count_new += 1;
									num_3 += 1;
								}
							}
						}
						
						ent = limit_at_all;
						if ((gamemode == 1)||(gamemode == 2)||(gamemode == 4)||(gamemode == 5)||(gamemode == 7)||(gamemode == 8)) {
							
							if (var_[7] == 52){
											//printf("ok(1492)");
								lim = 0;
								for (unsigned int i=1; i<m-1; i+=1){
									for (unsigned int j=1; j<n-1; j+=1){
										if ((Sf[i][j] == 7) && (Sf_od_7[i][j] == 0)){
											lim += 1;
										}
									}
								}
											//printf("ok(1501)");
								ent = lim;
											//printf("ok(1503)");
								lim = 0;
								for (unsigned int i=1; i<m-1; i+=1){
									for (unsigned int j=1; j<n-1; j+=1){
										if (Sf[i][j] == 1){
											lim += 1;
										}
									}
								}			//printf("ok(1511)");
							
							
								if ((lim <= limit_new) && (ent < (limit_at_all - 1))){
									if (ent >= (limit_at_all - 3)){
										ent = limit_at_all - 1;
									} else if (ent >= (limit_at_all - 5)){
										ent = limit_at_all - 2;
									} else if (ent >= (limit_at_all - 7)){
										ent = limit_at_all - 3;
									} else if (ent >= (limit_at_all - 10)){
										ent = limit_at_all - 4;
									} else {
										ent = limit_at_all;
									}		//printf("ok(1523)");
								} else {		//printf("ok(1524)");
									ent = limit_at_all;
								}
								lim = 0;
											//printf("ok(1528)");
							}
						}	// possible to modify
						
						if (count_new > ent){		//Abfrage auf insgesamt max. 20 Steine, normalerweise
							/*if (gamemode == 1) {
								Sf_nl_7 = Index_7 (ent, count_new, m, n, Sf, Sf_nl_7, Sf_od_7, limit_new, limit_at_all, zeitgewinner);	
							} else if (gamemode == 2) {
								Sf_nl_7= Index_7_col  (ent, count_new, m, n, Sf, Sf_nl_7, Sf_od_7, limit_new, limit_at_all, zeitgewinner);	
							} else if (gamemode == 3) {
								count_new = 0;
							} else if (gamemode == 4) {
								Sf_nl_7 = Index_7_fal (ent, count_new, m, n, Sf, Sf_nl_7, Sf_od_7, limit_new, limit_at_all, zeitgewinner);	
							} else if (gamemode == 5) {
								Sf_nl_7 = Index_7_fig (ent, count_new, m, n, Sf, Sf_nl_7, Sf_od_7, limit_new, limit_at_all, zeitgewinner);	
							} else if (gamemode == 7) {
								Sf_nl_7 = Index_7_race (ent, count_new, m, n, Sf, Sf_nl_7, Sf_od_7, limit_new, limit_at_all, zeitgewinner);	
							} else if (gamemode == 8) {
								Sf_nl_7 = Index_7_rain (ent, count_new, m, n, Sf, Sf_nl_7, Sf_od_7, limit_new, limit_at_all, rain, zeitgewinner);	
							}*/
							if (gamemode == 6) {
								Sf_nl_7 = Index_other_hunt (ent, count_new, m, n, Sf_nl_7, geben, zeitgewinner, Sf, limit_at_all);	
							} else if (gamemode == 9) {
								Sf_nl_7 = Index_are (ent, count_new, m, n, Sf_nl_7, Sf_od_7, limit_new, limit_at_all, zeitgewinner, Sf, w, d, e, geben);	
							} else if (gamemode == 10) {
								count_new = 0;
							} else if (gamemode == 11) {
								Sf_nl_7 = Index_dyn (ent, count_new, m, n, Sf_nl_7, Sf_od_7, limit_new, limit_at_all, zeitgewinner, Sf, w, d, e, geben, position);
							} else if (gamemode == 12) {	//mehr-gamemode
								count_new = 0;
							}
						}
						ent = 0;
						zeitgewinner = 0;

						if (gamemode == 4) {
							touch (Sf, m, n, geben, Sf_nl_1, Sf_nl_2);	//possible to modify
						}
						
						Sf = change_7 (Sf, Sf_nl_7, Sf_od_7, m, n, gamemode, number_of_players, ges);
						
						if (gamemode == 1) {
							for (unsigned int j=1; j<n-1; j+=1){	//possible to modify
								if (Sf[2][j] == 2){
									B[0] += 1;
									break;
								}
							} 
						} else if (gamemode == 2) {	//possible to modify
							for (unsigned int j=2; j<n-1; j+=((n-1)/2)-2){		//collect-Bed. prüfen
								unsigned int b;
								b = 0;
								if (Sf[((m-1)/2)][j] == 7){
									if (Sf[((m-1)/2)-1][j]==2){b += 1;}
									if (Sf[((m-1)/2)+1][j]==2){b += 1;}
									if (Sf[(m-1)/2][j-1]==2){b += 1;}
									if (Sf[(m-1)/2][j+1]==2){b += 1;}
									if (b >= 3){
										B[0] += 1;
										Sf[((m-1)/2)][j] = 2;
									}
								}
							}
							if (B[0] == 2){
								printf("\n");
								printf("	Sieg: Spieler 2 \n");
								printf("\n");
								show_field (Sf, m, n, gamemode, information_code, geben, Colored);
								break;
							}
						}
						
						
						if ((gamemode == 6)&&(geben == number_of_players)) {
							lim = 1;
							printf("	\n");
							if (opague >= 1) {
								show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
							} else {
								show_field (Sf, m, n, gamemode, information_code, geben, Colored);
							}
							printf("	\n");
							while (lim == 1) {
								printf("	\n");
								printf("	\n");
								printf("	Are you ready to make your turn? \n");
								printf("	Yes: 1 \n");
								printf("	\n");
								printf("	\n");
								scanf("%u", &lim);
								
								if (lim != 1) {
									lim = 1;
								} else {
									lim = 0;
								}
							}
						}
						if (gamemode == 6) {
							information_code[3] = 0;
						}
						
						controll = 0;
						if (gamemode == 1) {	//possible to modify
							for (unsigned int erste=1; erste<n-1; erste+=1){		//Spiel-Ende?
								if (Sf[1][erste] == 2){
									printf("	Sieg:	Spieler 2 \n");
									controll = 1;
									break;
								}
							}
							if (controll == 1){
								break;
							}
						}
						controll = 0;
						
						if (gamemode == 3) {	//possible to modify
							if (opague >= 1) {
								show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
							} else {
								show_field (Sf, m, n, gamemode, information_code, geben, Colored);
							}
							battle (m, n, Sf, geben);
						}
						
						if (number_of_players == 7) {// gamemode 6 modify, done!
							if (var_[1] != 1010) {
								cons[7] = use_number;
								
								if (gamemode == 11) {	//mehr-gamemode
									for (unsigned int p=2; p<=5; p+=1) {
										
										dynamic_pointer_save[7][p-2] = dynamic_pointer[p];
										
									}
								}
								
							}
						} else if (number_of_players >= 8) {
							if (var_[8] != 1010) {
								cons[7] = use_number;
								
								if (gamemode == 11) {	//mehr-gamemode
									for (unsigned int p=2; p<=5; p+=1) {
										
										dynamic_pointer_save[7][p-2] = dynamic_pointer[p];
										
									}
								}
								
							}
						}
						
						use_number = random_number (num_1, num_2, num_3, use_number, g, var_, number_3, number_4);
						
						if ((opt != 5)&&(var_[7] <= 62)){
							controll_2 = 0;
							for (unsigned int z=var_[7]; z>2; z-=10){
								controll_2 += 1;
							}
							number_7 = controll_2;
							//printf("%u \n", number_7);
							controll_2 = 0;
						}
					}
				}	//{}ausfindig machen
			} else if (geben == 8) {		//following players
				
				if (opague >= 1) {
					Sf_opague = opague_builder (Sf, m, n, geben, opague, aop);
					
				}
				
				if ((ttt != 0)&&(pere[geben] == 100)) {
					g += 1;
					continue;
				}
				
				if ((gamemode == 10)&&(ulcer_start[8] == 0)) {
					if (opague >= 1) {
						show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
					} else {
						show_field (Sf, m, n, gamemode, information_code, geben, Colored);
					}
					g += 1;
					continue;
				}
				
				if ((ges[8] == 8080)&&((gamemode == 6)||(gamemode == 9)||(gamemode == 10)||(gamemode == 11)||(gamemode == 12))) {	//mehr-gamemode
					g+=1;
					var_[8] = 8080;
					cons[8] = cons[7];
					for (unsigned int i=1; i<m-1; i+=1){
						for (unsigned int j=1; j<n-1; j+=1){
							cons_field_8[i][j] = cons_field_7[i][j];
							if (journey == 1){
								cons_journey_8[i][j] = cons_journey_7[i][j];
								
								if (Sf_journey[i][j] == 8) {
									Sf_journey[i][j] = 0;
								}
							}
							if (gamemode == 11) {	//mehr-gamemode
								for (unsigned int p=2; p<=5; p+=1) {
									
									dynamic_pointer_save[8][p-2] = dynamic_pointer_save[7][p-2];
									
								}
							}
						}
					}
					if (var_[0] == 1) {
						g-=2;
					}
					continue;
				}
				
				w = 3;
				d = 2;
				e = 3;
				if (gamemode == 9) {
					if (ability[1] == geben) {
						w = 1;
						d = 0;
						e = 1;
						information_code[0] = 1;
					} else if (ability[2] == geben) {
						w = 2;
						d = 1;
						e = 2;
						information_code[0] = 2;
					} else if (ability[3] == geben) {
						w = 4;
						d = 1;
						e = 4;	//abweichende e-definition
						information_code[0] = 3;
					} else if (ability[4] == geben) {
						information_code[0] = 4;
					} else if (ability[5] == geben) {
						information_code[0] = 5;
					} else if (ability[6] == geben) {
						information_code[0] = 6;
					} else if (ability[7] == geben) {
						information_code[0] = 7;
					} else if (ability[8] == geben) {
						information_code[0] = 8;
					} else if (ability[9] == geben) {
						information_code[0] = 9;
						
						if (opague >= 1) {
							show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
						} else {
							show_field (Sf, m, n, gamemode, information_code, geben, Colored);
						}
						
						for (unsigned int i=1; i<m-1; i+=1){
							for (unsigned int j=1; j<n-1; j+=1){
								if (Sf[i][j] == geben) {
									if ((Sf[i+1][j] != 0)&&(Sf[i+1][j] != geben)&&((i+2) <= (m-2))) {
										if (Sf[i+2][j] == 0) {
											Sf[i+2][j] = Sf[i+1][j];
											Sf[i+1][j] = 0;
										}
									}
									if ((Sf[i-1][j] != 0)&&(Sf[i-1][j] != geben)&&((i-2) >= 1)) {
										if (Sf[i-2][j] == 0) {
											Sf[i-2][j] = Sf[i-1][j];
											Sf[i-1][j] = 0;
										}
									}
									if ((Sf[i][j-1] != 0)&&(Sf[i][j-1] != geben)&&((j-2) >= 1)) {
										if (Sf[i][j-2] == 0) {
											Sf[i][j-2] = Sf[i][j-1];
											Sf[i][j-1] = 0;
										}
									}
									if ((Sf[i][j+1] != 0)&&(Sf[i][j+1] != geben)&&((j+2) <= (n-2))) {
										if (Sf[i][j+2] == 0) {
											Sf[i][j+2] = Sf[i][j+1];
											Sf[i][j+1] = 0;
										}
									}
								}
							}
						}
					}
				}
				
				if (gamemode == 10) {
					w = 2;
					d = 1;
					e = 2;
				}
				
				if (gamemode == 9) {
					if (information_code[0] == 1) {
						limit_at_all = limit_at_all-2;
					} else if (information_code[0] == 2) {
						limit_at_all = limit_at_all-1;
					} else {
						limit_at_all = limit_at_all_saver;
					}
				}
				
				if (ttt != 0) {
					if ((pere[geben] != 0)&&(warning_system <= 5)&&((pere[geben]+warning_system) == 7)) {
						g += 1;
						printf(" \n ");
						printf("	You got a penalty. \n ");
						printf(" \n ");
						pere[geben] = 0;
						continue;
					} else if ((pere[geben] != 0)&&(warning_system != 0)&&(((warning_system <= 5)&&((pere[geben]+warning_system) == 8))||((warning_system == 6)&&(pere[geben] == 1)))) {
						Sf_od_8 = old_dying_8 (Sf, m, n, d, e, gamemode, information_code);
						Sf = change_8 (Sf, Sf_nl_8, Sf_od_8, m, n, gamemode, number_of_players, ges); 	//Change befreit
						g += 1;
						printf(" \n ");
						printf("	You got a penalty. \n ");
						printf(" \n ");
						pere[geben] = 0;
						continue;
					} else if (((warning_system <= 5)&&((warning_system + pere[geben]) >= 9))||((warning_system >= 6)&&((warning_system + pere[geben]) >= 8))) {
						printf("	Niederlage: Spieler 8 \n ");
						for (unsigned int i=1; i<m-1; i+=1){
							for (unsigned int j=1; j<n-1; j+=1){
								if (Sf[i][j] == 8) {
									Sf[i][j] = 0;
								}
							}
						}
						ges[8] = 8080;
						player_counter += 1;
						pere[geben] = 100;
						g += 1;
						continue;
					}
				}
				
				if (var_[geben] == 1010) {
					use_number = cons[geben];
					if (opt == 5) {
					
						printf("	Player %u ,do you want to keep your number (%u) or do you want to get the next one? \n", geben, cons[geben]);
						printf("	Keep the number: 	1 \n");
						printf("	Get the next one:	2 \n");
						scanf("%u", &lim);
						
						if (lim == 2) {
							use_number = random_number (num_1, num_2, num_3, use_number, g, var_, number_3, number_4);
						} else if (lim != 1) {
							printf("	Well, you keep your number, but next time please take an option i offered. \n\n");
						}
						lim = 0;
					
					}
				}
				
				if (var_[geben%number_of_players+1] == 1010){		//geben%number_of_players+1 ist der Nachfolger von geben.
					if (tac != 0) {
						if (number_8 <= 5){
							DDDD[number_8] += 1;
						} else if (number_8 == 6){
							DDDD[0] += 1;
						}
					} else if (opt == 5) {
						BBBB[use_number] -= 1;
					} else {
						BBBB[number_8] -= 1;
					}
					
				}
				
				if ((tac != 0)&&((DDDD[1]+DDDD[2]+DDDD[3]+DDDD[4]+DDDD[5]+DDDD[0]) == 0)){
					for (unsigned int p=0; p<=5; p+=1){
						DDDD[p] = tac;
					}
				}
				
				menuoperator = 1;
				
				
				while (menuoperator != 0) {
					
					if (gamemode != 8) {
						if (opague >= 1) {
							show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
						} else {
							show_field (Sf, m, n, gamemode, information_code, geben, Colored);
						}
					}
					
					if ((gamemode == 6)&&(((scwhp == 1)&&((opt == 0)||((use_number == 2)||(use_number == 3)||(use_number == 4)))&&((tac == 0)||((DDDD[2] != 0)||(DDDD[3] != 0)||(DDDD[4] != 0))))||(scwhp == 2))) {
						
						information_code[3] = 1;
						
						if (opague >= 1) {
							show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
						} else {
							show_field (Sf, m, n, gamemode, information_code, geben, Colored);
						}
					}
					
					if (gamemode == 4) {
						printf("\n");
						printf("	Points player 8: 	%u Point(s) \n", P[geben]);
					}	// possible to modify
					
					if (gamemode == 10) {
						printf("\n");
						printf("	Lifes player 8: 	%u Life(s) \n", ulcer_lifes[8]);
					}
					
					if (gamemode == 11) {
						printf("	\n");
						printf("	Geschwindigkeit: 	Zeile: %d, 	Spalte: %d \n", dynamic_pointer[2], dynamic_pointer[3]);
						printf("	Beschleunigung: 	Zeile: %d, 	Spalte: %d \n", dynamic_pointer[4], dynamic_pointer[5]);
						printf("	\n");
					}
					
					printf("\n");
					
					if (Colored[0] == 1) {
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+Colored[geben]);
					}
					
					if ((gamemode != 6)&&(gamemode != 9)&&(gamemode != 10)&&(gamemode != 11)&&(gamemode != 12)){	//mehr-gamemode
						printf("	Am Zug: Spieler 2 (OO)	\n");	// possible to modify
					} else if (gamemode == 6) {
						printf("	Am Zug: Spieler 8 (HH)	\n");
					} else if (gamemode == 9) {
						if (ability[1] == geben) {
							printf("	Am Zug: Spieler 8 (UU)	\n");
						} else if (ability[2] == geben) {
							printf("	Am Zug: Spieler 8 (LL)	\n");
						} else if (ability[3] == geben) {
							printf("	Am Zug: Spieler 8 (AA)	\n");
						} else if (ability[4] == geben) {
							printf("	Am Zug: Spieler 8 (CC)	\n");
						} else if (ability[5] == geben) {
							printf("	Am Zug: Spieler 8 (II)	\n");
						} else if (ability[6] == geben) {
							printf("	Am Zug: Spieler 8 (SS)	\n");
						} else if (ability[7] == geben) {
							printf("	Am Zug: Spieler 8 (PP)	\n");
						} else if (ability[8] == geben) {
							printf("	Am Zug: Spieler 8 (HH)	\n");
						} else if (ability[9] == geben) {
							printf("	Am Zug: Spieler 8 (EE)	\n");
						}
					} else if ((gamemode == 10)||(gamemode == 11)||(gamemode == 12)) {	//mehr-gamemode
						printf("	Am Zug: Spieler 8 (88)	\n");
					}
					
					if (Colored[0] == 1) {
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+7);
					}
					
					printf("\n");
					
					if (tac != 0){
						printf("	Your stack of numbers:	\n	1) [%u],		2) [%u],		3) [%u], \n\n	4) [%u],		5) [%u],		6) [%u],\n", DDDD[1], DDDD[2], DDDD[3], DDDD[4], DDDD[5], DDDD[0]);
						printf("\n");
						printf("\n");
					}
					
					if (opt == 5){		//random number
						printf("	Your number: %u ", use_number);
						printf("\n");
						printf("\n");
						
					}
					
					printf("	1) Plus:	11	Minus: 	12 \n");
					printf("	2) Move:	21	Change: 22 \n");
					printf("	3) Destroy:	31	Revive: 32 \n");
					printf("	4) Move:	41	Boost: 	42 \n");
					if (((gamemode != 9)&&(gamemode != 10))||((gamemode == 10)&&(geben == 1))) {
						printf("	5) 4/5-new:	51	2-new:	52 \n");
						printf("	6) 4-max:	61	1-min:	62 \n");
					} else if (gamemode == 9) {
						if (information_code[0] == 1) {
							printf("	5) 2/3-new:	51	0-new:	52 \n");
							printf("	6) 2-max:	61	-1-min:	62 \n");
						} else if (information_code[0] == 2) {
							printf("	5) 3/4-new:	51	1-new:	52 \n");
							printf("	6) 3-max:	61	0-min:	62 \n");
						} else if (information_code[0] == 3) {
							printf("	5) 5/6-new:	51	3-new:	52 \n");
							printf("	6) 5-max:	61	0-min:	62 \n");
						} else {
							printf("	5) 4/5-new:	51	2-new:	52 \n");
							printf("	6) 4-max:	61	1-min:	62 \n");
						}
					} else if ((gamemode == 10)&&(geben != 1)) {
						printf("	5) 3/4-new:	51	1-new:	52 \n");
						printf("	6) 3-max:	61	0-min:	62 \n");
					}
					printf("							\n");
					printf("		Go back: 100 \n");
					printf("		Menu: 10 \n");
					printf("		End game: 0 \n");
					if ((ttt != 0)&&(time_saver == 0.0)) {
						time1 = time(NULL);
					}
					scanf("%u", &var_[8]);
					
					if (var_[8] == 10){
						if (ttt != 0) {
							time3 = time(NULL);
						}
						while (menuoperator != 7) {
							printf("\n");
							printf("\n");
							printf("	About the game: 1 \n	Statistics: 2 \n	The numbers: 3 \n	The limits: 4 \n	Get Hints: 5 \n	Suprise: 6 \n	Quit Menu: 7 \n");
							scanf("%u", &menuoperator);
							
							if (menuoperator == 1){
								if (gamemode == 1) {
									printf("	How to win? 	Own a square on your last line or force your opponent to lose all his/her ones.\n");
								} else if (gamemode == 2) {
									printf("	How to win? 	Be at 2 of the 3 targets with three of your squares near-by.\n");
								} else if (gamemode == 3) {
									printf("	How to win? 	Take over all your opponent's squares by winning contact-battles.\n");
									printf("	Contact-battles? 	All near-by squares in a row with the contact-square build a chain, beat your opponent in the length.\n");
								} else if (gamemode == 4) {
									printf("	How to win? 	Get more points than your opponent.\n");
									printf("	Note:	Touch the #-square in the near-by to move it to the opposite side. \n");
								} else if (gamemode == 5) {
									printf("	How to win? 	Force your opponent to lose all his/her squares.\n");
								} else if (gamemode == 6) {
									if (geben == 1) {
										printf("	How to win? 	Protect your heart-block so no enemy can touch it.\n");
									} else {
										printf("	How to win? 	Catch the heart-block of the hunted one before it disappears.\n");
									}
								} else if (gamemode == 7) {
									printf("	How to win? 	Reach the end of the field or force your opponent to lose all his/her ones.\n");
									printf("	Note:	Every %u turns in total the #-line will go ahead and destroys everything in it's way.\n Also you are not allowed to cross the mid-line. \n", freq);
								} else if (gamemode == 8) {
									printf("	How to win? 	Reach [1][7] of the field or force your opponent to lose all his/her squares.\n");
									printf("	Note:	Falling down the #-squares will push, destroy, explode, or teleport, transform into yours by contact. \n");
								} else if ((gamemode == 9)||(gamemode == 10)) {
									printf("	How to win? 	Force your opponent to lose all his/her squares while keeping yours alive.\n");
								} else if (gamemode == 11) {
									printf("	How to win? 	Push the ball against your opponent's side.\n");
								} else if (gamemode == 12) {	//mehr-gamemode
									printf("	How to win? 	Stay alive.\n");
								}
								printf("	Surrounding:	The 8 squares around another, at the edge 5, in the corners 3, are called #surrounding. \n");
								printf("	near-by:	The 4 squares around another, at the edge 3, in the corners 2, are called #near-by. \n");
								printf("	Standard actions:	(After your choice of number and not influencing each other) \n	-Development:	If it is your turn and a free square has exactly 3 of yours surrounding it, you will own it.\n");
								printf("	-Losses: 	If it is your turn and a square of yours is surrounded by less than %u or more than %u of yours,\n			it will be set free.\n", d, e);
								if ((gamemode == 10)||(gamemode == 12)) {	//mehr-gamemode
									printf("	Limits: 	This gamemode is unlimited. \n");
								} else if (gamemode == 3) {
									printf("	Limits: 	Your development is limited by %u per round. \n", limit_new);
								} else {
									printf("	Limits: 	Your development is limited by %u per round, your units in total by %u per round. \n", limit_new, limit_at_all);
								}
							}
							
							if (menuoperator == 2){
								printf("\n");
								printf("	turns at all: %u \n", g);
								printf("\n");
								printf("	Numbers of player 1: \n");
								printf("		#1 = %u \n", A[1]);
								printf("		#2 = %u \n", A[2]);
								printf("		#3 = %u \n", A[3]);
								printf("		#4 = %u \n", A[4]);
								printf("		#5 = %u \n", A[5]);
								printf("		#6 = %u \n", A[6]);
								printf("\n");
								if (number_of_players >= 2) {	//mehr-gamemode
									printf("	Numbers of player 2: \n");
									printf("		#1 = %u \n", B[1]);
									printf("		#2 = %u \n", B[2]);
									printf("		#3 = %u \n", B[3]);
									printf("		#4 = %u \n", B[4]);
									printf("		#5 = %u \n", B[5]);
									printf("		#6 = %u \n", B[6]);
									printf("\n");
								}
								if (number_of_players >= 3){	//mehr-gamemode
									printf("	Numbers of player 3: \n");
									printf("		#1 = %u \n", AA[1]);
									printf("		#2 = %u \n", AA[2]);
									printf("		#3 = %u \n", AA[3]);
									printf("		#4 = %u \n", AA[4]);
									printf("		#5 = %u \n", AA[5]);
									printf("		#6 = %u \n", AA[6]);
									printf("\n");
								}
								if (number_of_players >= 4){
									printf("	Numbers of player 4: \n");
									printf("		#1 = %u \n", BB[1]);
									printf("		#2 = %u \n", BB[2]);
									printf("		#3 = %u \n", BB[3]);
									printf("		#4 = %u \n", BB[4]);
									printf("		#5 = %u \n", BB[5]);
									printf("		#6 = %u \n", BB[6]);
									printf("\n");
								}
								if (number_of_players >= 5){
									printf("	Numbers of player 5: \n");
									printf("		#1 = %u \n", AAA[1]);
									printf("		#2 = %u \n", AAA[2]);
									printf("		#3 = %u \n", AAA[3]);
									printf("		#4 = %u \n", AAA[4]);
									printf("		#5 = %u \n", AAA[5]);
									printf("		#6 = %u \n", AAA[6]);
									printf("\n");
								}
								if (number_of_players >= 6){
									printf("	Numbers of player 6: \n");
									printf("		#1 = %u \n", BBB[1]);
									printf("		#2 = %u \n", BBB[2]);
									printf("		#3 = %u \n", BBB[3]);
									printf("		#4 = %u \n", BBB[4]);
									printf("		#5 = %u \n", BBB[5]);
									printf("		#6 = %u \n", BBB[6]);
									printf("\n");
								}
								if (number_of_players >= 7){
									printf("	Numbers of player 7: \n");
									printf("		#1 = %u \n", AAAA[1]);
									printf("		#2 = %u \n", AAAA[2]);
									printf("		#3 = %u \n", AAAA[3]);
									printf("		#4 = %u \n", AAAA[4]);
									printf("		#5 = %u \n", AAAA[5]);
									printf("		#6 = %u \n", AAAA[6]);
									printf("\n");
								}
								if (number_of_players >= 8){
									printf("	Numbers of player 8: \n");
									printf("		#1 = %u \n", BBBB[1]);
									printf("		#2 = %u \n", BBBB[2]);
									printf("		#3 = %u \n", BBBB[3]);
									printf("		#4 = %u \n", BBBB[4]);
									printf("		#5 = %u \n", BBBB[5]);
									printf("		#6 = %u \n", BBBB[6]);
									printf("\n");
								}
								if (number_of_players == 9){
									printf("	Numbers of player 9: \n");
									printf("		#1 = %u \n", AAAAA[1]);
									printf("		#2 = %u \n", AAAAA[2]);
									printf("		#3 = %u \n", AAAAA[3]);
									printf("		#4 = %u \n", AAAAA[4]);
									printf("		#5 = %u \n", AAAAA[5]);
									printf("		#6 = %u \n", AAAAA[6]);
									printf("\n");
								}
								
								if ((gamemode == 1)||(gamemode == 6)||(gamemode == 7)||(gamemode == 8)) {
									printf("	Matchballs player 1: 	%u \n", A[0]);
									printf("	Matchballs player 2: 	%u \n", B[0]);
									if (gamemode == 6) {
										if (number_of_players >= 3){printf("	Matchballs player 3: 	%u \n", AA[0]);}
										if (number_of_players >= 4){printf("	Matchballs player 4: 	%u \n", BB[0]);}
										if (number_of_players >= 5){printf("	Matchballs player 5: 	%u \n", AAA[0]);}
										if (number_of_players >= 6){printf("	Matchballs player 6: 	%u \n", BBB[0]);}
										if (number_of_players >= 7){printf("	Matchballs player 7: 	%u \n", AAAA[0]);}
										if (number_of_players >= 8){printf("	Matchballs player 8: 	%u \n", BBBB[0]);}
										if (number_of_players == 9){printf("	Matchballs player 9: 	%u \n", AAAAA[0]);}
									}
								} else if (gamemode == 2) {
									printf("	Squares collected by player 1: 	%u \n", A[0]);
									printf("	Squares collected by player 2: 	%u \n", B[0]);
								} else if (gamemode == 3) {
									printf("	Times with squares <= 5, player 1: 	%u \n", A[0]);
									printf("	Times with squares <= 5, player 2: 	%u \n", B[0]);
								} else if (gamemode == 4) {
									printf("	Points player 1: 		%u \n", P[1]);
									printf("	Points Player 2: 		%u \n", P[2]);
									printf("	Turns with more points player 1: 	%u \n", A[0]);
									printf("	Turns with more points player 2: 	%u \n", B[0]);
									printf("	Number of not decided #-squares: 	%u \n", P[0]);
								} else if (gamemode == 3) {
									printf("	Times with squares < 5, player 1: 	%u \n", A[0]);
									printf("	Times with squares < 5, player 2: 	%u \n", B[0]);
								} else if (gamemode == 9) {
									printf("	Number of excluded abilites: 	%u \n", exclude_counter);
									printf("	Offensive abilities taken: 	%u \n", number_of_players-ability[0]);
									printf("	Defensive abilities taken: 	%u \n", ability[0]);
								} else if (gamemode == 10) {
									for (unsigned int p=1; p<=number_of_players; p+=1) {
										printf("		Spieler %u: %u life(s) left.\n", p, ulcer_lifes[p]);
									}
								} else if (gamemode == 11) {	//mehr-gamemode
									for (unsigned int p=1; p<=number_of_players; p+=1) {
										if ((ges[p] > 1000)||(ges[p] == 0)) {
											printf("	Spieler %u: is out.\n", p);
										} else if (ges[p] < 1000) {
											printf("	Spieler %u: You own %u squares.\n", p, ges[p]);
										}
									}
								} else if (gamemode == 12) {
									for (unsigned int p=1; p<=number_of_players; p+=1) {
										if ((ges[p] > 1000)||(ges[p] == 0)) {
											printf("	Spieler %u: is out.\n", p);
										} else if (ges[p] < 1000) {
											printf("	Spieler %u: You own %u squares.\n", p, ges[p]);
										}
									}
								}
								
								if (ttt != 0) {
									printf("	Number of penalties given until	now: %u \n", pere[0]);
								}
							}
							
							if (menuoperator == 3){
								if ((gamemode != 10)&&(gamemode != 12)) {
									printf("	Plus: Change a free square in the surrounding of yours in one of yours.\n");
								} else {
									printf("	Plus: Change a square in the surrounding of yours in one of yours.\n");
								}
								printf("	Minus: Delete one of your squares.\n");
								printf("	Move: The position of one of yours will change with a free, near-by square.\n");
								printf("	Revive: Your lost squares having no living squares of yours surrounding them at the beginning of your turn,\n		will be revived.\n");
								printf("	%u/%u-new: A free square has to be surrounded by %u or %u of yours during the development.\n", w+1, w+2, w+1, w+2);
								printf("	%u-new: A free square has to be surrounded by %u of yours during the development.\n", d, d);
								printf("	%u-max: A square of yours will survive even by %u of your squares surrounding it.\n", e+1, e+1);
								if (d == 0) {
									printf("	-1-min: A square of yours will survive even by only -1 of your squares surrounding it.\n");
								} else {
									printf("	%u-min: A square of yours will survive even by only %u of your squares surrounding it.\n", d-1, d-1);
								}
								
								if ((gamemode == 1)||(gamemode == 2)||(gamemode == 4)||(gamemode == 5)||(gamemode == 7)||(gamemode == 9)||(gamemode == 10)) {
									printf("	Change: A square of yours and a near-by square of your enemy will change positions.\n");
									printf("	Destroy: Delete a near-by square of your enemy.\n");
									printf("	Boost: Use all near-by squares of your enemy as your own for the development.\n");
									
								} else if (gamemode == 3) {
									
									printf("	Change: A square of yours and a square of your enemy in the surrounding will change positions.\n");
									printf("	Destroy: Delete a surrounding square of your enemy.\n");
									printf("	Boost: Use all surrounding squares of your enemy as your own for the development.\n");
									
								} else if (gamemode == 8) {
									printf("	Change: A square of yours and a near-by #-square will change positions.\n");
									printf("	Destroy: Delete a square of your enemy, but not in the last two lines.\n");
									printf("	Boost: Use all near-by #-squares as your own for the development.\n");
									
								} else if (gamemode == 6) {
									if (geben == 1) {
										printf("	Change: The heart-block and a square of yours will change positions.\n");
										printf("	Destroy: Delete a square of your enemy.\n");
										printf("	Boost: Touching the heart_block no square of yours can die.\n");
									} else {
										printf("	Change: A square of yours and a near-by square of the hunted one will change positions.\n");
										printf("	Destroy: Delete a near-by square of your enemy.\n");
										printf("	Boost: Use all near-by squares of the hunted one as your own for the development.\n");
									}
									
								} else if (gamemode == 11) {	//mehr-gamemode
									printf("	Change: A square of yours and a near-by square of your enemy or the near-by ball will change positions.\n");
									printf("	Destroy: Delete a near-by square of your enemy.\n");
									printf("	Boost: Use all near-by squares of your enemy and the near-by ball as your own for the development.\n");
								} else if (gamemode == 12) {
									printf("	Change: A square of yours and a near-by square of your enemy or a near-by object will change positions.\n");
									printf("	Destroy: Delete a near-by square of your enemy or a near-by object.\n");
									printf("	Boost: Use all near-by squares of your enemy and near-by objects as your own for the development.\n");
								}
								
								printf("\n");
							}
							
							if (menuoperator == 4){	//mehr-gamemode
								if ((gamemode != 10)&&(gamemode != 12)) {
									printf("	Limit of development:	%u \n", limit_new);
									if (gamemode != 3) {
										printf("	Limit in total:		%u \n", limit_at_all);
										printf("	Limit in total with >2-new< taken: %u -0/-1/-2/-3/-4.\n", limit_at_all);
									}
								}
							}
							
							if (menuoperator == 5){
								Spielfeld hint;
								unsigned int b, a;
								hint = Spielfeld_Create (m, n);
								printf("	New: 1 \n	Dying: 2 \n	Both: 3 \n");
								scanf("%u", &menuoperator);
								
								for (unsigned int i=1; i<(m-1); i+=1){
									for (unsigned int j=1; j<(n-1); j+=1){
										if ((gamemode != 6)&&(gamemode != 9)&&(gamemode != 10)&&(gamemode != 11)&&(gamemode != 12)){	//mehr-gamemode
											if (Sf[i][j] == geben){
												hint[i][j] = geben;
											} else if (Sf[i][j] == (geben%2)+1){
												hint[i][j] = (geben%2)+1;
											} else if (Sf[i][j] == 7){
												hint[i][j] = 7;
											} 
										} else if ((gamemode == 6)||(gamemode == 9)||(gamemode == 10)) {	//10
											if (Sf[i][j] == geben){
												hint[i][j] = geben;
											} else if (Sf[i][j] != 0){
												hint[i][j] = 17;
											}
										} else if (gamemode == 11) {
											if (Sf[i][j] == geben){
												hint[i][j] = geben;
											} else if (Sf[i][j] == 77){
												hint[i][j] = 77;
											} else if (Sf[i][j] != 0){
												hint[i][j] = 17;
											}
										} else if (gamemode == 12) {	//mehr-gamemode
											if (Sf[i][j] == geben){
												hint[i][j] = geben;
											} else if (Sf[i][j] == 81){
												hint[i][j] = 81;
											} else if (Sf[i][j] == 82){
												hint[i][j] = 82;
											} else if (Sf[i][j] == 83){
												hint[i][j] = 83;
											} else if (Sf[i][j] == 84){
												hint[i][j] = 84;
											} else if (Sf[i][j] == 75){
												hint[i][j] = 75;
											} else if (Sf[i][j] == 71){
												hint[i][j] = 71;
											} else if (Sf[i][j] != 0){
												hint[i][j] = 17;
											}
										}
									}
								}
								
								if ((menuoperator == 2)||(menuoperator == 3)){
									for (unsigned int i=1; i<(m-1); i+=1){
										for (unsigned int j=1; j<(n-1); j+=1){
											if (Sf[i][j] == geben){
												a = 0;
												for (unsigned int h=(i-1); h<=(i+1); h+=1){
													for (unsigned int k=(j-1); k<=(j+1); k+=1){
														if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
															if (Sf[h][k] == geben){
																a += 1;
															}
														}
													}
												}
												if ((a > 4) || (a < 3)){
													hint[i][j] = 16;
												}
											}
										}
									}
								}
								
								if ((menuoperator == 1)||(menuoperator == 3)){
									for (unsigned int i=1; i<(m-1); i+=1){
										for (unsigned int j=1; j<(n-1); j+=1){
											if (Sf[i][j] == 0){
												b = 0;
												for (unsigned int h=(i-1); h<=(i+1); h+=1){
													for (unsigned int k=(j-1); k<=(j+1); k+=1){
														if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
															if (Sf[h][k] == geben){
																b += 1;
															}
														}
													}
												}
												if (b == 3){
													hint[i][j] = 15;
												}
											}
										}
									}
								}
						
								if (opague >= 1) {
									Sf_opague = opague_builder (hint, m, n, geben, opague, aop);
								}
								
								if (opague >= 1) {
									show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
								} else {
									show_field (hint, m, n, gamemode, information_code, geben, Colored);
								}
								
								if (opague >= 1) {
									Sf_opague = opague_builder (Sf, m, n, geben, opague, aop);
								}
								
								menuoperator = 1;
								Spielfeld_Destroy (hint, m);
							}
							// 2
							if (menuoperator == 6){
								if (suprise == 0) {
									for (unsigned int i=1; i<m-1; i+=1){
										for (unsigned int j=1; j<n-1; j+=1){
											cons_field_8[i][j] = Sf[i][j];
											
											if (journey == 1){
												cons_journey_8[i][j] = Sf_journey[i][j];
											}
										}
									}
									sup_num = use_number;
								}
								
								while (menuoperator != 1) {
						
									printf("	Creator menu. 	Change number: 1	Suprise: 2	Suprise undo: 3	Back: 4 \n");
									scanf ("%u", &lim);
									if (lim == 1){
										printf("	number = ? \n");
										scanf ("%u", &use_number);
									} else if (lim == 2){
								
										printf("\n");
										scanf("%u", &suprise);
								
										if (suprise == 31){
											for (unsigned int i=2; i<m-2; i+=1){
												for (unsigned int j=1; j<n-1; j+=1){
													if (Sf[i][j] != 0){
														if (Sf[i][j] == 1){
															Sf[i][j] = 8;
														} else if (Sf[i][j] == 8){
															Sf[i][j] = 1;
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
								
										if(suprise == 13){
											for (unsigned int i=1; i<m-1; i+=1){
												for (unsigned int j=1; j<n-1; j+=1){
													if (Sf[i][j] == 8){
														Sf[i][j] = 0;
													}
													if (i == (m-2)){
														Sf[m-2][j] = 8;
													}
												}
											}
										}
								
									} else if (lim == 3){
										for (unsigned int i=1; i<m-1; i+=1){
											for (unsigned int j=1; j<n-1; j+=1){
												Sf[i][j] = cons_field_8[i][j];
												
												if (journey == 1){
													Sf_journey[i][j] = cons_journey_8[i][j];
												}
											}
										}
										use_number = sup_num;
									} else if (lim == 4){
										menuoperator = 1;
									} else {
										printf("	Invalid comment");
									}
								}
							}
						}	// menuoperator = 7
						
						if (gamemode == 8) {
							if (opague >= 1) {
								show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
							} else {
								show_field (Sf, m, n, gamemode, information_code, geben, Colored);
							}	//show_field über menuoperator = 7 und stack und so löschen, (verschiebe menuoperator!=0 - Schleife), done
							
							printf("\n");
						
						}
						
						if (ttt != 0) {
							time4 = time(NULL);
							time_saver += difftime(time4, time3);
						}
					}	//Menu-end
					
					menuoperator = 0;
					
					if (var_[8] == 10) {
						menuoperator = 1;
						var_[8] = 5;
					}
					
					if ((tac != 0)&&(var_[8] <= 62)&&(var_[8] > 10)){
						unsigned int tac_controll;
						tac_controll = 0;
						if (((var_[8]%10) > 2)||((var_[8]%10) == 0)){
							var_[8] = 7;
							menuoperator = 1;
						} else {
							for (unsigned int z=var_[8]; z>2; z-=10){
								tac_controll += 1;
							}
							if (tac_controll == 6){
								tac_controll = 0;
							}
							if (DDDD[tac_controll] == 0){
								var_[8] = 7;
								menuoperator = 1;
							} else {
								DDDD[tac_controll] -= 1;
							}
						}
					} else if ((tac != 0)&&(var_[8] != 100)&&(var_[8] != 1010)&&(var_[8] != 0)) {
						var_[8] = 7;
					}		
					//tac-mode
					
					if (opt == 5){
						controll_1 = 10+use_number;
						controll_2 = 11+use_number;
					
						for (unsigned int i=0; i<use_number-1; i+=1){
							controll_1 += 9;
							controll_2 += 9;
						}
					
						if (var_[8] == 0){
							controll_1 = 0;
							controll_2 = 0;
						}
						if (var_[8] == 100){
							controll_1 = 100;
							controll_2 = 100;
						}
						if (var_[8] == 1010){
							controll_1 = 1010;
							controll_2 = 1010;
						}
					}
					//
					if (((var_[8] > 0)&&(var_[8] < 10))||(((opt == 5)&&(var_[8] != controll_1))&&((opt == 5)&&(var_[8] != controll_2)))){
						
						if (var_[8] != 5) {
							printf("	You made a mistake, try again: \n");
							printf("\n");
							printf("\n");
						} else {
							printf("	You closed the menu. \n");
							printf("\n");
							printf("\n");
						}
						
						//enough
						
						menuoperator = 1;
					}
					
				}		// menuoperator = 0
				
				suprise = 0;
				
				if (var_[8] == 0){
					printf("	Do you really want to end the game ? \n");
					printf("	Yes: 0		No: 1 \n");
					scanf("%u", &lim);
					if (lim == 0){
						break;
					} else if (lim == 1){
						continue;
					} else {
						printf("	0 or 1, it is so difficult to understand? \n");
						printf("	Well, it seems I have to end it by myself... \n");
						break;
					}	
				} else {
					
					if (var_[8] == 100){		//gamemode 6 modify, done
						
						var_[0] = 1;
						
						for (unsigned int i=1; i<m-1; i+=1){
							for (unsigned int j=1; j<n-1; j+=1){
								Sf[i][j] = cons_field_7[i][j];
								
								if (journey == 1){
									Sf_journey[i][j] = cons_journey_7[i][j];
								}
							}
						}
						
						if (opague >= 1) {
							Sf_opague = opague_builder (Sf, m, n, geben, opague, aop);
						}
						
						if (opague >= 1) {
							show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
						} else {
							show_field (Sf, m, n, gamemode, information_code, geben, Colored);
						}
						
						cons[geben] = use_number;
						
						use_number = cons[7];
						
						if (gamemode == 11) {	//mehr-gamemode
							for (unsigned int p=2; p<=5; p+=1) {
								
								dynamic_pointer[p] = dynamic_pointer_save[7][p-2];
								
							}
						}
						
						g-=1;
						var_[8] = 1010;
						if (gamemode == 10) {
							ulcer_lifes[8] += 1;
							ulcer_start[8] = 0;
						}
						continue;
					} else {
						
						if (number_of_players == 8) {
							
							if (var_[1] != 1010){
								for (unsigned int i=1; i<m-1; i+=1){
									for (unsigned int j=1; j<n-1; j+=1){
										cons_field_8[i][j] = Sf[i][j];
										
										if (journey == 1){
											cons_journey_8[i][j] = Sf_journey[i][j];
										}
									}
								}
							}
						} else if (number_of_players == 9) {
							if (var_[9] != 1010){
								for (unsigned int i=1; i<m-1; i+=1){
									for (unsigned int j=1; j<n-1; j+=1){
										cons_field_8[i][j] = Sf[i][j];
										
										if (journey == 1){
											cons_journey_8[i][j] = Sf_journey[i][j];
										}
									}
								}
							}
						}
						
						var_[0] = 0;
						
						if (var_[8] < 50){
							
							if (var_[8] == 11){BBBB[1] += 1; Plus (m, n, geben, Sf, limit_at_all, gamemode, information_code, number_of_players, Colored, opague, Sf_opague);}
							if (var_[8] == 12){BBBB[1] += 1; Minus (m, n, geben, Sf, gamemode, information_code, Colored, opague, Sf_opague);}
							if (var_[8] == 21){BBBB[2] += 1; Move (m, n, geben, Sf, gamemode, information_code, Colored, opague, Sf_opague);}
							if (var_[8] == 41){BBBB[4] += 1; Move (m, n, geben, Sf, gamemode, information_code, Colored, opague, Sf_opague);}
							if (var_[8] == 22){BBBB[2] += 1; Change (m, n, geben, Sf, gamemode, information_code, Colored, opague, Sf_opague, position);}
							if (var_[8] == 31){BBBB[3] += 1; Destroy (m, n, geben, Sf, gamemode, information_code, Colored, opague, Sf_opague);}
							if (var_[8] == 42){
								BBBB[4] += 1; 
								Boost (geben, Sf, m, n, temp, gamemode);
							}
						} else {
							if (var_[8] == 51){BBBB[5] += 1; w += 1;}		//w
							if (var_[8] == 52){BBBB[5] += 1; w -= 1;}		//w
							if (var_[8] == 61){BBBB[6] += 1; e += 1;}		//e
							if (var_[8] == 62){BBBB[6] += 1; if (d != 0) {d -= 1;} else {d = 10;}}		//d
						}		//printf("ok(1376)");
						
						if (ttt != 0) {
							time2 = time(NULL);
							time_warning = ((difftime(time2, time1)) - time_saver);
							
							//printf("	time_warning: %f \n", time_warning);		//test
							
							if ((pere[geben] != 0)&&((pere[geben] + warning_system) <= 6)) {
								if (pere[geben] == 1) {
									if (warning_system <= 2) {
										time_warning += 1.0;
									} else if (warning_system == 3) {
										time_warning += 2.0;
									} else if (warning_system == 4) {
										time_warning += 3.0;
									} else if (warning_system == 5) {
										time_warning += 5.0;
									}
								} else if (pere[geben] == 2) {
									if (warning_system == 1) {
										time_warning += 2.0;
									} else if (warning_system == 2) {
										time_warning += 3.0;
									} else if (warning_system == 3) {
										time_warning += 5.0;
									} else if (warning_system == 4) {
										time_warning += 6.0;
									}
								} else if (pere[geben] == 3) {
									if (warning_system == 1) {
										time_warning += 3.0;
									} else if (warning_system == 2) {
										time_warning += 5.0;
									} else if (warning_system == 3) {
										time_warning += 8.0;
									}
								} else if (pere[geben] == 4) {
									if (warning_system == 1) {
										time_warning += 4.0;
									} else if (warning_system == 2) {
										time_warning += 7.0;
									}
								} else if (pere[geben] == 5) {
									if (warning_system == 1) {
										time_warning += 5.0;
									}
								}
							}
							
							if (time_warning > (1.0*ttt)) {
								pere[0] += 1;
								printf("	You took too much time! %f sec more than you should. \n", (time_warning-1.0*ttt) );
								printf(" \n");
								for (unsigned int p=16; p>=1; p-=3) {	//index_verschiebung
									if ((time_warning-1.0*ttt) > 1.0*(p-1)) {
										pere[geben] = (((p-1)/3) + 1);
										break;
									}
								}
							} else {
								pere[geben] = 0;
							}
						}
						
						Sf_nl_8 = new_life_8 (Sf, m, n, w, gamemode, information_code);		//printf("ok(1378)");
						
						if (gamemode == 6) {
							
							precounter = 0;
							for (unsigned int i=1; i<m-1; i+=1){
								for (unsigned int j=1; j<n-1; j+=1){
									if (Sf[i][j] == 11){
										if (Sf_nl_3[i][j-1] > 1) {
											printf (" Sieg: Spieler %u \n", Sf_nl_3[i][j-1]);
											precounter += 1;
										}
										if (Sf_nl_3[i][j+1] > 1) {
											if (precounter == 0) {
												printf (" Sieg: Spieler %u \n", Sf_nl_3[i][j+1]);
											}
											precounter += 1;
										}
										if (Sf_nl_3[i-1][j] > 1) {
											if (precounter == 0) {
												printf (" Sieg: Spieler %u \n", Sf_nl_3[i-1][j]);
											}
											precounter += 1;
										}
										if (Sf_nl_3[i+1][j] > 1) {
											if (precounter == 0) {
												printf (" Sieg: Spieler %u \n", Sf_nl_3[i+1][j]);
											}
											precounter += 1;
										}
										if (precounter == 2) {
											printf(" Double-catch! \n");
										}
										if (precounter == 3) {
											printf(" TRIPLE-catch!! \n");
										}
										if (precounter == 4) {
											printf(" QUADRO-CATCH!!! \n");
										}
										break;
									}
								}
								if (precounter > 0) {
									break;
								}
							}
							if (precounter > 0) {
								for (unsigned int i=1; i<m-1; i+=1){
									for (unsigned int j=1; j<n-1; j+=1){
										if (Sf_nl_3[i][j] == geben) {
											Sf[i][j] = geben;
										}
									}
								}
								show_field (Sf, m, n, gamemode, information_code, geben, Colored);
								break;
							}
						}
						
						controll = 0;
						if (gamemode == 7) {	// possible to modify
							for (unsigned int i=(m-2); i>=(m-1)/2; i-=1){		//Spiel-Ende?
								if ((Sf_nl_8[i][n-2] == 8)||(Sf[i][n-2] == 8)){
									for (unsigned int k=(m-2); k>=1; k-=1){
										if (Sf_nl_8[k][n-2] == 8){
											Sf[k][n-2] = 8;
										}
									}
									show_field (Sf, m, n, gamemode, information_code, geben, Colored);
									printf("	Sieg:	Spieler 8 \n");
									controll = 1;
								}
							}
							if (controll == 1){
								break;
							}
						}
						controll = 0;
						
						num_1 = 0;
						for (unsigned int i=1; i<m-1; i+=1){
							for (unsigned int j=1; j<n-1; j+=1){
								if (Sf_nl_8[i][j] == 8){
									num_1 += 1;
								}
							}
						}		//printf("ok(1387)");	
					
						if (var_[8] == 42){
							for (unsigned int i=1; i<m-1; i+=1){
								for (unsigned int j=1; j<n-1; j+=1){
									if (gamemode == 8) {
										if (temp[i][j] == 8){
											Sf[i][j] = 0;
										}
									} else if ((gamemode == 9)||(gamemode == 10)||(gamemode == 11)||(gamemode == 12)) {	//mehr-gamemode
										if (temp[i][j] != 0){
											Sf[i][j] = temp[i][j];
										}
									} else if (gamemode == 6) {	//10
										if (temp[i][j] == 8){
											Sf[i][j] = 1;
										}
									}
								}
							}
						}		//printf("ok(1398)");	
						// possible to modify
						
						controll = 0;
						if (gamemode == 1){	// possible to modify
							for (unsigned int erste=1; erste<n-1; erste+=1){		//printf("ok(1400)");		//Spiel-Ende?
								if (Sf[1][erste] == 8){
									printf("	Sieg:	Spieler 8 \n");
									show_field (Sf, m, n, gamemode, information_code, geben, Colored);
									controll = 1;		//printf("ok(1404)");
									break;
								}
							}
							if (controll == 1){
								break;		//printf("ok(1409)");
							}		//printf("ok(1410)");
						}
						controll = 0;
						
						Spielfeld_Destroy (temp, m);		//printf("ok(1412)");
					
						Sf_od_8 = old_dying_8 (Sf, m, n, d, e, gamemode, information_code);		//printf("ok(1414)");
						
						if (journey == 1){
							unsigned int journey_max;
							journey_max = 0;
							for (unsigned int i=1; i<m-1; i+=1){
								for (unsigned int j=1; j<n-1; j+=1){
									if (Sf_journey[i][j] == 8){
										journey_max += 1;
									}
								}
							}
							for (unsigned int i=1; i<m-1; i+=1){
								for (unsigned int j=1; j<n-1; j+=1){
									if ((Sf_od_8[i][j] == 808) && (Sf_journey[i][j] == 0) && (journey_max >= limit_at_all)){
										for (unsigned int u=(m-2); u>0; u-=1){
											for (unsigned int o=1; o<(n-1); o+=1){
												if ((Sf_journey[u][o] == 8)&&((u+o)%2 == 0)){
													Sf_journey[u][o] = 0;
													journey_max -= 1;
													if (journey_max < limit_at_all){
														break;
													}
												}
											}
											if (journey_max < limit_at_all){
												break;
											}
										}
										
									}
									if ((Sf_od_8[i][j] == 808) && (Sf_journey[i][j] == 0) && (journey_max < limit_at_all)){
										Sf_journey[i][j] = 8;
										journey_max += 1;
									}
								}
							}
							journey_max = 0;
						}
						
						if (var_[8] == 32){BBBB[3] += 1; Revive_8(m, n, Sf_od_8, Sf);}
						
						num_2 = 0;
						for (unsigned int i=1; i<m-1; i+=1){
							for (unsigned int j=1; j<n-1; j+=1){
								if (Sf_od_8[i][j] == 808){
									num_2 += 1;
								}
							}
						}
					
						count_new = 0;
						for (unsigned int i=1; i<m-1; i+=1){
							for (unsigned int j=1; j<n-1; j+=1){
								if (Sf_nl_8[i][j] == 8){
									count_new += 1;
								}
							}
						}
						ent = limit_new;		//printf("ok(1473)");
						
						for (unsigned int i=1; i<m-1; i+=1){
							for (unsigned int j=1; j<n-1; j+=1){
								if ((Sf[i][j] == 8) && (Sf_od_8[i][j] == 0)){
									zeitgewinner += 1;
								}
							}
						}
						
						if (count_new > limit_new){		//Abfrage auf max. 10 neue Steine
							/*if (gamemode == 1) {
								Sf_nl_8 = Index_8 (ent, count_new, m, n, Sf, Sf_nl_8, Sf_od_8, limit_new, limit_at_all, zeitgewinner);	
							} else if (gamemode == 2) {
								Sf_nl_8 = Index_8_col (ent, count_new, m, n, Sf, Sf_nl_8, Sf_od_8, limit_new, limit_at_all, zeitgewinner);	
							} else if (gamemode == 3) {
								Sf_nl_8 = Index_8_con (ent, count_new, m, n, Sf, Sf_nl_8, limit_new);
							} else if (gamemode == 4) {
								Sf_nl_8 = Index_8_fal (ent, count_new, m, n, Sf, Sf_nl_8, Sf_od_8, limit_new, limit_at_all, zeitgewinner);	
							} else if (gamemode == 5) {
								Sf_nl_8 = Index_8_fig (ent, count_new, m, n, Sf, Sf_nl_8, Sf_od_8, limit_new, limit_at_all, zeitgewinner);	
							} else if (gamemode == 7) {
								Sf_nl_8 = Index_8_race (ent, count_new, m, n, Sf, Sf_nl_8, Sf_od_8, limit_new, limit_at_all, zeitgewinner);	
							} else if (gamemode == 8) {
								Sf_nl_8 = Index_8_rain (ent, count_new, m, n, Sf, Sf_nl_8, Sf_od_8, limit_new, limit_at_all, rain, zeitgewinner);	
							}*/
							if (gamemode == 6) {
								Sf_nl_8 = Index_other_hunt (ent, count_new, m, n, Sf_nl_8, geben, zeitgewinner, Sf, limit_at_all);	
							} else if (gamemode == 9) {
								Sf_nl_8 = Index_are (ent, count_new, m, n, Sf_nl_8, Sf_od_8, limit_new, limit_at_all, zeitgewinner, Sf, w, d, e, geben);
							} else if (gamemode == 10) {
								count_new = 0;
							} else if (gamemode == 11) {
								Sf_nl_8 = Index_dyn (ent, count_new, m, n, Sf_nl_8, Sf_od_8, limit_new, limit_at_all, zeitgewinner, Sf, w, d, e, geben, position);
							} else if (gamemode == 12) {	//mehr-gamemode
								count_new = 0;
							}
						
						}
						ent = 0;
						count_new = 0;		//printf("ok(1478)");
					
						num_3 = 0;
						for (unsigned int i=1; i<m-1; i+=1){
							for (unsigned int j=1; j<n-1; j+=1){
								if (((Sf[i][j] == 8) && (Sf_od_8[i][j] == 0)) || (Sf_nl_8[i][j] == 8)){
									count_new += 1;
									num_3 += 1;
								}
							}
						}
						
						ent = limit_at_all;
						if ((gamemode == 1)||(gamemode == 2)||(gamemode == 4)||(gamemode == 5)||(gamemode == 7)||(gamemode == 8)) {
							
							if (var_[8] == 52){
											//printf("ok(1492)");
								lim = 0;
								for (unsigned int i=1; i<m-1; i+=1){
									for (unsigned int j=1; j<n-1; j+=1){
										if ((Sf[i][j] == 8) && (Sf_od_8[i][j] == 0)){
											lim += 1;
										}
									}
								}
											//printf("ok(1501)");
								ent = lim;
											//printf("ok(1503)");
								lim = 0;
								for (unsigned int i=1; i<m-1; i+=1){
									for (unsigned int j=1; j<n-1; j+=1){
										if (Sf[i][j] == 1){
											lim += 1;
										}
									}
								}			//printf("ok(1511)");
							
							
								if ((lim <= limit_new) && (ent < (limit_at_all - 1))){
									if (ent >= (limit_at_all - 3)){
										ent = limit_at_all - 1;
									} else if (ent >= (limit_at_all - 5)){
										ent = limit_at_all - 2;
									} else if (ent >= (limit_at_all - 7)){
										ent = limit_at_all - 3;
									} else if (ent >= (limit_at_all - 10)){
										ent = limit_at_all - 4;
									} else {
										ent = limit_at_all;
									}		//printf("ok(1523)");
								} else {		//printf("ok(1524)");
									ent = limit_at_all;
								}
								lim = 0;
											//printf("ok(1528)");
							}
						}	// possible to modify
						
						if (count_new > ent){		//Abfrage auf insgesamt max. 20 Steine, normalerweise
							/*if (gamemode == 1) {
								Sf_nl_8 = Index_8 (ent, count_new, m, n, Sf, Sf_nl_8, Sf_od_8, limit_new, limit_at_all, zeitgewinner);	
							} else if (gamemode == 2) {
								Sf_nl_8= Index_8_col  (ent, count_new, m, n, Sf, Sf_nl_8, Sf_od_8, limit_new, limit_at_all, zeitgewinner);	
							} else if (gamemode == 3) {
								count_new = 0;
							} else if (gamemode == 4) {
								Sf_nl_8 = Index_8_fal (ent, count_new, m, n, Sf, Sf_nl_8, Sf_od_8, limit_new, limit_at_all, zeitgewinner);	
							} else if (gamemode == 5) {
								Sf_nl_8 = Index_8_fig (ent, count_new, m, n, Sf, Sf_nl_8, Sf_od_8, limit_new, limit_at_all, zeitgewinner);	
							} else if (gamemode == 7) {
								Sf_nl_8 = Index_8_race (ent, count_new, m, n, Sf, Sf_nl_8, Sf_od_8, limit_new, limit_at_all, zeitgewinner);	
							} else if (gamemode == 8) {
								Sf_nl_8 = Index_8_rain (ent, count_new, m, n, Sf, Sf_nl_8, Sf_od_8, limit_new, limit_at_all, rain, zeitgewinner);	
							}*/
							if (gamemode == 6) {
								Sf_nl_8 = Index_other_hunt (ent, count_new, m, n, Sf_nl_8, geben, zeitgewinner, Sf, limit_at_all);	
							} else if (gamemode == 9) {
								Sf_nl_8 = Index_are (ent, count_new, m, n, Sf_nl_8, Sf_od_8, limit_new, limit_at_all, zeitgewinner, Sf, w, d, e, geben);	
							} else if (gamemode == 10) {
								count_new = 0;
							} else if (gamemode == 11) {
								Sf_nl_8 = Index_dyn (ent, count_new, m, n, Sf_nl_8, Sf_od_8, limit_new, limit_at_all, zeitgewinner, Sf, w, d, e, geben, position);
							} else if (gamemode == 12) {	//mehr-gamemode
								count_new = 0;
							}
						
						}
						ent = 0;
						zeitgewinner = 0;

						if (gamemode == 4) {
							touch (Sf, m, n, geben, Sf_nl_1, Sf_nl_2);	//possible to modify
						}
						
						Sf = change_8 (Sf, Sf_nl_8, Sf_od_8, m, n, gamemode, number_of_players, ges);
						
						if (gamemode == 1) {
							for (unsigned int j=1; j<n-1; j+=1){	//possible to modify
								if (Sf[2][j] == 2){
									B[0] += 1;
									break;
								}
							} 
						} else if (gamemode == 2) {	//possible to modify
							for (unsigned int j=2; j<n-1; j+=((n-1)/2)-2){		//collect-Bed. prüfen
								unsigned int b;
								b = 0;
								if (Sf[((m-1)/2)][j] == 7){
									if (Sf[((m-1)/2)-1][j]==2){b += 1;}
									if (Sf[((m-1)/2)+1][j]==2){b += 1;}
									if (Sf[(m-1)/2][j-1]==2){b += 1;}
									if (Sf[(m-1)/2][j+1]==2){b += 1;}
									if (b >= 3){
										B[0] += 1;
										Sf[((m-1)/2)][j] = 2;
									}
								}
							}
							if (B[0] == 2){
								printf("\n");
								printf("	Sieg: Spieler 2 \n");
								printf("\n");
								show_field (Sf, m, n, gamemode, information_code, geben, Colored);
								break;
							}
						}
						
						if ((gamemode == 6)&&(geben == number_of_players)) {
							lim = 1;
							printf("	\n");
							if (opague >= 1) {
								show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
							} else {
								show_field (Sf, m, n, gamemode, information_code, geben, Colored);
							}
							printf("	\n");
							while (lim == 1) {
								printf("	\n");
								printf("	\n");
								printf("	Are you ready to make your turn? \n");
								printf("	Yes: 1 \n");
								printf("	\n");
								printf("	\n");
								scanf("%u", &lim);
								
								if (lim != 1) {
									lim = 1;
								} else {
									lim = 0;
								}
							}
						}
						if (gamemode == 6) {
							information_code[3] = 0;
						}
						
						controll = 0;
						if (gamemode == 1) {	//possible to modify
							for (unsigned int erste=1; erste<n-1; erste+=1){		//Spiel-Ende?
								if (Sf[1][erste] == 2){
									printf("	Sieg:	Spieler 2 \n");
									controll = 1;
									break;
								}
							}
							if (controll == 1){
								break;
							}
						}
						controll = 0;
						
						if (gamemode == 3) {	//possible to modify
							if (opague >= 1) {
								show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
							} else {
								show_field (Sf, m, n, gamemode, information_code, geben, Colored);
							}
							battle (m, n, Sf, geben);
						}
						
						if (number_of_players == 8) {// gamemode 6 modify, done!
							if (var_[1] != 1010) {
								cons[8] = use_number;
								
								if (gamemode == 11) {	//mehr-gamemode
									for (unsigned int p=2; p<=5; p+=1) {
										
										dynamic_pointer_save[8][p-2] = dynamic_pointer[p];
										
									}
								}
								
							}
						} else if (number_of_players == 9) {
							if (var_[9] != 1010) {
								cons[8] = use_number;
								
								if (gamemode == 11) {	//mehr-gamemode
									for (unsigned int p=2; p<=5; p+=1) {
										
										dynamic_pointer_save[8][p-2] = dynamic_pointer[p];
										
									}
								}
								
							}
						}
						
						use_number = random_number (num_1, num_2, num_3, use_number, g, var_, number_3, number_4);
						
						if ((opt != 5)&&(var_[8] <= 62)){
							controll_2 = 0;
							for (unsigned int z=var_[8]; z>2; z-=10){
								controll_2 += 1;
							}
							number_8 = controll_2;
							//printf("%u \n", number_8);
							controll_2 = 0;
						}
					}
				}	//{}ausfindig machen
			} else if (geben == 9) {		//following players
				
				if (opague >= 1) {
					Sf_opague = opague_builder (Sf, m, n, geben, opague, aop);
					
				}
				
				if ((ttt != 0)&&(pere[geben] == 100)) {
					g += 1;
					continue;
				}
				
				if ((gamemode == 10)&&(ulcer_start[9] == 0)) {
					if (opague >= 1) {
						show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
					} else {
						show_field (Sf, m, n, gamemode, information_code, geben, Colored);
					}
					g += 1;
					continue;
				}
				
				if ((ges[9] == 9090)&&((gamemode == 6)||(gamemode == 9)||(gamemode == 10)||(gamemode == 11)||(gamemode == 12))) {	//mehr-gamemode
					g+=1;
					var_[9] = 9090;
					cons[9] = cons[8];
					for (unsigned int i=1; i<m-1; i+=1){
						for (unsigned int j=1; j<n-1; j+=1){
							cons_field_9[i][j] = cons_field_8[i][j];
							if (journey == 1){
								cons_journey_9[i][j] = cons_journey_8[i][j];
								
								if (Sf_journey[i][j] == 9) {
									Sf_journey[i][j] = 0;
								}
							}
							if (gamemode == 11) {	//mehr-gamemode
								for (unsigned int p=2; p<=5; p+=1) {
									
									dynamic_pointer_save[9][p-2] = dynamic_pointer_save[8][p-2];
									
								}
							}
						}
					}
					if (var_[0] == 1) {
						g-=2;
					}
					continue;
				}
				
				w = 3;
				d = 2;
				e = 3;
				if (gamemode == 9) {
					if (ability[1] == geben) {
						w = 1;
						d = 0;
						e = 1;
						information_code[0] = 1;
					} else if (ability[2] == geben) {
						w = 2;
						d = 1;
						e = 2;
						information_code[0] = 2;
					} else if (ability[3] == geben) {
						w = 4;
						d = 1;
						e = 4;	//abweichende e-definition
						information_code[0] = 3;
					} else if (ability[4] == geben) {
						information_code[0] = 4;
					} else if (ability[5] == geben) {
						information_code[0] = 5;
					} else if (ability[6] == geben) {
						information_code[0] = 6;
					} else if (ability[7] == geben) {
						information_code[0] = 7;
					} else if (ability[8] == geben) {
						information_code[0] = 8;
					} else if (ability[9] == geben) {
						information_code[0] = 9;
						
						if (opague >= 1) {
							show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
						} else {
							show_field (Sf, m, n, gamemode, information_code, geben, Colored);
						}
						
						for (unsigned int i=1; i<m-1; i+=1){
							for (unsigned int j=1; j<n-1; j+=1){
								if (Sf[i][j] == geben) {
									if ((Sf[i+1][j] != 0)&&(Sf[i+1][j] != geben)&&((i+2) <= (m-2))) {
										if (Sf[i+2][j] == 0) {
											Sf[i+2][j] = Sf[i+1][j];
											Sf[i+1][j] = 0;
										}
									}
									if ((Sf[i-1][j] != 0)&&(Sf[i-1][j] != geben)&&((i-2) >= 1)) {
										if (Sf[i-2][j] == 0) {
											Sf[i-2][j] = Sf[i-1][j];
											Sf[i-1][j] = 0;
										}
									}
									if ((Sf[i][j-1] != 0)&&(Sf[i][j-1] != geben)&&((j-2) >= 1)) {
										if (Sf[i][j-2] == 0) {
											Sf[i][j-2] = Sf[i][j-1];
											Sf[i][j-1] = 0;
										}
									}
									if ((Sf[i][j+1] != 0)&&(Sf[i][j+1] != geben)&&((j+2) <= (n-2))) {
										if (Sf[i][j+2] == 0) {
											Sf[i][j+2] = Sf[i][j+1];
											Sf[i][j+1] = 0;
										}
									}
								}
							}
						}
					}
				}
				
				if (gamemode == 10) {
					w = 2;
					d = 1;
					e = 2;
				}
				
				if (gamemode == 9) {
					if (information_code[0] == 1) {
						limit_at_all = limit_at_all-2;
					} else if (information_code[0] == 2) {
						limit_at_all = limit_at_all-1;
					} else {
						limit_at_all = limit_at_all_saver;
					}
				}
				
				if (ttt != 0) {
					if ((pere[geben] != 0)&&(warning_system <= 5)&&((pere[geben]+warning_system) == 7)) {
						g += 1;
						printf(" \n ");
						printf("	You got a penalty. \n ");
						printf(" \n ");
						pere[geben] = 0;
						continue;
					} else if ((pere[geben] != 0)&&(warning_system != 0)&&(((warning_system <= 5)&&((pere[geben]+warning_system) == 8))||((warning_system == 6)&&(pere[geben] == 1)))) {
						Sf_od_9 = old_dying_9 (Sf, m, n, d, e, gamemode, information_code);
						Sf = change_9 (Sf, Sf_nl_9, Sf_od_9, m, n, gamemode, number_of_players, ges); 	//Change befreit
						g += 1;
						printf(" \n ");
						printf("	You got a penalty. \n ");
						printf(" \n ");
						pere[geben] = 0;
						continue;
					} else if (((warning_system <= 5)&&((warning_system + pere[geben]) >= 9))||((warning_system >= 6)&&((warning_system + pere[geben]) >= 8))) {
						printf("	Niederlage: Spieler 9 \n ");
						for (unsigned int i=1; i<m-1; i+=1){
							for (unsigned int j=1; j<n-1; j+=1){
								if (Sf[i][j] == 9) {
									Sf[i][j] = 0;
								}
							}
						}
						ges[9] = 9090;
						player_counter += 1;
						pere[geben] = 100;
						g += 1;
						continue;
					}
				}
				
				if (var_[geben] == 1010) {
					use_number = cons[geben];
					if (opt == 5) {
					
						printf("	Player %u ,do you want to keep your number (%u) or do you want to get the next one? \n", geben, cons[geben]);
						printf("	Keep the number: 	1 \n");
						printf("	Get the next one:	2 \n");
						scanf("%u", &lim);
						
						if (lim == 2) {
							use_number = random_number (num_1, num_2, num_3, use_number, g, var_, number_3, number_4);
						} else if (lim != 1) {
							printf("	Well, you keep your number, but next time please take an option i offered. \n\n");
						}
						lim = 0;
					
					}
				}
				
				if (var_[geben%number_of_players+1] == 1010){		//geben%number_of_players+1 ist der Nachfolger von geben.
					if (tac != 0) {
						if (number_9 <= 5){
							CCCCC[number_9] += 1;
						} else if (number_9 == 6){
							CCCCC[0] += 1;
						}
					} else if (opt == 5) {
						AAAAA[use_number] -= 1;
					} else {
						AAAAA[number_9] -= 1;
					}
					
				}
				
				if ((tac != 0)&&((CCCCC[1]+CCCCC[2]+CCCCC[3]+CCCCC[4]+CCCCC[5]+CCCCC[0]) == 0)){
					for (unsigned int p=0; p<=5; p+=1){
						CCCCC[p] = tac;
					}
				}
				
				menuoperator = 1;
				
				while (menuoperator != 0) {
						
					if (gamemode != 8) {
						if (opague >= 1) {
							show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
						} else {
							show_field (Sf, m, n, gamemode, information_code, geben, Colored);
						}
					}
					
					if ((gamemode == 6)&&(((scwhp == 1)&&((opt == 0)||((use_number == 2)||(use_number == 3)||(use_number == 4)))&&((tac == 0)||((CCCCC[2] != 0)||(CCCCC[3] != 0)||(CCCCC[4] != 0))))||(scwhp == 2))) {
						
						information_code[3] = 1;
						
						if (opague >= 1) {
							show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
						} else {
							show_field (Sf, m, n, gamemode, information_code, geben, Colored);
						}
					}
					
					if (gamemode == 4) {
						printf("\n");
						printf("	Points player 2: 	%u Point(s) \n", P[geben]); 	//possible to modify
					}
					
					if (gamemode == 10) {
						printf("\n");
						printf("	Lifes player 9: 	%u Life(s) \n", ulcer_lifes[9]);
					}
					
					if (gamemode == 11) {
						printf("	\n");
						printf("	Geschwindigkeit: 	Zeile: %d, 	Spalte: %d \n", dynamic_pointer[2], dynamic_pointer[3]);
						printf("	Beschleunigung: 	Zeile: %d, 	Spalte: %d \n", dynamic_pointer[4], dynamic_pointer[5]);
						printf("	\n");
					}
					
					printf("\n");
					
					if (Colored[0] == 1) {
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+Colored[geben]);
					}
					
					if ((gamemode != 6)&&(gamemode != 9)&&(gamemode != 10)&&(gamemode != 11)&&(gamemode != 12)){	//mehr-gamemode
						printf("	Am Zug: Spieler 2 (OO)	\n");	//possible to modify
					} else if (gamemode == 6) {
						printf("	Am Zug: Spieler 9 (II)	\n");
					} else if (gamemode == 9) {
						if (ability[1] == geben) {
							printf("	Am Zug: Spieler 9 (UU)	\n");
						} else if (ability[2] == geben) {
							printf("	Am Zug: Spieler 9 (LL)	\n");
						} else if (ability[3] == geben) {
							printf("	Am Zug: Spieler 9 (AA)	\n");
						} else if (ability[4] == geben) {
							printf("	Am Zug: Spieler 9 (CC)	\n");
						} else if (ability[5] == geben) {
							printf("	Am Zug: Spieler 9 (II)	\n");
						} else if (ability[6] == geben) {
							printf("	Am Zug: Spieler 9 (SS)	\n");
						} else if (ability[7] == geben) {
							printf("	Am Zug: Spieler 9 (PP)	\n");
						} else if (ability[8] == geben) {
							printf("	Am Zug: Spieler 9 (HH)	\n");
						} else if (ability[9] == geben) {
							printf("	Am Zug: Spieler 9 (EE)	\n");
						}
					} else if ((gamemode == 10)||(gamemode == 11)||(gamemode == 12)) {	//mehr-gamemode
						printf("	Am Zug: Spieler 9 (99)	\n");
					}
					
					if (Colored[0] == 1) {
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+7);
					}
					
					printf("\n");
					
					if (tac != 0){
						printf("	Your stack of numbers:	\n	1) [%u],		2) [%u],		3) [%u], \n\n	4) [%u],		5) [%u],		6) [%u],\n", CCCCC[1], CCCCC[2], CCCCC[3], CCCCC[4], CCCCC[5], CCCCC[0]);
						printf("\n");
						printf("\n");
					}
					
					if (opt == 5){		//random number
						printf("	Your number: %u ", use_number);
						printf("\n");
						printf("\n");
						
					}
					
					printf("	1) Plus:	11	Minus: 	12 \n");
					printf("	2) Move:	21	Change: 22 \n");
					printf("	3) Destroy:	31	Revive: 32 \n");
					printf("	4) Move:	41	Boost: 	42 \n");
					if (((gamemode != 9)&&(gamemode != 10))||((gamemode == 10)&&(geben == 1))) {
						printf("	5) 4/5-new:	51	2-new:	52 \n");
						printf("	6) 4-max:	61	1-min:	62 \n");
					} else if (gamemode == 9) {
						if (information_code[0] == 1) {
							printf("	5) 2/3-new:	51	0-new:	52 \n");
							printf("	6) 2-max:	61	-1-min:	62 \n");
						} else if (information_code[0] == 2) {
							printf("	5) 3/4-new:	51	1-new:	52 \n");
							printf("	6) 3-max:	61	0-min:	62 \n");
						} else if (information_code[0] == 3) {
							printf("	5) 5/6-new:	51	3-new:	52 \n");
							printf("	6) 5-max:	61	0-min:	62 \n");
						} else {
							printf("	5) 4/5-new:	51	2-new:	52 \n");
							printf("	6) 4-max:	61	1-min:	62 \n");
						}
					} else if ((gamemode == 10)&&(geben != 1)) {
						printf("	5) 3/4-new:	51	1-new:	52 \n");
						printf("	6) 3-max:	61	0-min:	62 \n");
					}
					printf("							\n");
					printf("		Go back: 100 \n");
					printf("		Menu: 10 \n");
					printf("		End game: 0 \n");
					if ((ttt != 0)&&(time_saver == 0.0)) {
						time1 = time(NULL);
					}
					scanf("%u", &var_[9]);
					
					if (var_[9] == 10){
						if (ttt != 0) {
							time3 = time(NULL);
						}
						while (menuoperator != 7) {
							printf("\n");
							printf("\n");
							printf("	About the game: 1 \n	Statistics: 2 \n	The numbers: 3 \n	The limits: 4 \n	Get Hints: 5 \n	Suprise: 6 \n	Quit Menu: 7 \n");
							scanf("%u", &menuoperator);
							
							if (menuoperator == 1){
								if (gamemode == 1) {
									printf("	How to win? 	Own a square on your last line or force your opponent to lose all his/her ones.\n");
								} else if (gamemode == 2) {
									printf("	How to win? 	Be at 2 of the 3 targets with three of your squares near-by.\n");
								} else if (gamemode == 3) {
									printf("	How to win? 	Take over all your opponent's squares by winning contact-battles.\n");
									printf("	Contact-battles? 	All near-by squares in a row with the contact-square build a chain, beat your opponent in the length.\n");
								} else if (gamemode == 4) {
									printf("	How to win? 	Get more points than your opponent.\n");
									printf("	Note:	Touch the #-square in the near-by to move it to the opposite side. \n");
								} else if (gamemode == 5) {
									printf("	How to win? 	Force your opponent to lose all his/her squares.\n");
								} else if (gamemode == 6) {
									if (geben == 1) {
										printf("	How to win? 	Protect your heart-block so no enemy can touch it.\n");
									} else {
										printf("	How to win? 	Catch the heart-block of the hunted one before it disappears.\n");
									}
								} else if (gamemode == 7) {
									printf("	How to win? 	Reach the end of the field or force your opponent to lose all his/her ones.\n");
									printf("	Note:	Every %u turns in total the #-line will go ahead and destroys everything in it's way.\n Also you are not allowed to cross the mid-line. \n", freq);
								} else if (gamemode == 8) {
									printf("	How to win? 	Reach [1][7] of the field or force your opponent to lose all his/her squares.\n");
									printf("	Note:	Falling down the #-squares will push, destroy, explode, or teleport, transform into yours by contact. \n");
								} else if ((gamemode == 9)||(gamemode == 10)) {
									printf("	How to win? 	Force your opponent to lose all his/her squares while keeping yours alive.\n");
								} else if (gamemode == 11) {
									printf("	How to win? 	Push the ball against your opponent's side.\n");
								} else if (gamemode == 12) {	//mehr-gamemode
									printf("	How to win? 	Stay alive.\n");
								}
								printf("	Surrounding:	The 8 squares around another, at the edge 5, in the corners 3, are called #surrounding. \n");
								printf("	near-by:	The 4 squares around another, at the edge 3, in the corners 2, are called #near-by. \n");
								printf("	Standard actions:	(After your choice of number and not influencing each other) \n	-Development:	If it is your turn and a free square has exactly 3 of yours surrounding it, you will own it.\n");
								printf("	-Losses: 	If it is your turn and a square of yours is surrounded by less than %u or more than %u of yours,\n			it will be set free.\n", d, e);
								if ((gamemode == 10)||(gamemode == 12)) {	//mehr-gamemode
									printf("	Limits: 	This gamemode is unlimited. \n");
								} else if (gamemode == 3) {
									printf("	Limits: 	Your development is limited by %u per round. \n", limit_new);
								} else {
									printf("	Limits: 	Your development is limited by %u per round, your units in total by %u per round. \n", limit_new, limit_at_all);
								}
							}
							
							if (menuoperator == 2){
								printf("\n");
								printf("	turns at all: %u \n", g);
								printf("\n");
								printf("	Numbers of player 1: \n");
								printf("		#1 = %u \n", A[1]);
								printf("		#2 = %u \n", A[2]);
								printf("		#3 = %u \n", A[3]);
								printf("		#4 = %u \n", A[4]);
								printf("		#5 = %u \n", A[5]);
								printf("		#6 = %u \n", A[6]);
								printf("\n");
								if (number_of_players >= 2) {	//mehr-gamemode
									printf("	Numbers of player 2: \n");
									printf("		#1 = %u \n", B[1]);
									printf("		#2 = %u \n", B[2]);
									printf("		#3 = %u \n", B[3]);
									printf("		#4 = %u \n", B[4]);
									printf("		#5 = %u \n", B[5]);
									printf("		#6 = %u \n", B[6]);
									printf("\n");
								}
								if (number_of_players >= 3){	//mehr-gamemode
									printf("	Numbers of player 3: \n");
									printf("		#1 = %u \n", AA[1]);
									printf("		#2 = %u \n", AA[2]);
									printf("		#3 = %u \n", AA[3]);
									printf("		#4 = %u \n", AA[4]);
									printf("		#5 = %u \n", AA[5]);
									printf("		#6 = %u \n", AA[6]);
									printf("\n");
								}
								if (number_of_players >= 4){
									printf("	Numbers of player 4: \n");
									printf("		#1 = %u \n", BB[1]);
									printf("		#2 = %u \n", BB[2]);
									printf("		#3 = %u \n", BB[3]);
									printf("		#4 = %u \n", BB[4]);
									printf("		#5 = %u \n", BB[5]);
									printf("		#6 = %u \n", BB[6]);
									printf("\n");
								}
								if (number_of_players >= 5){
									printf("	Numbers of player 5: \n");
									printf("		#1 = %u \n", AAA[1]);
									printf("		#2 = %u \n", AAA[2]);
									printf("		#3 = %u \n", AAA[3]);
									printf("		#4 = %u \n", AAA[4]);
									printf("		#5 = %u \n", AAA[5]);
									printf("		#6 = %u \n", AAA[6]);
									printf("\n");
								}
								if (number_of_players >= 6){
									printf("	Numbers of player 6: \n");
									printf("		#1 = %u \n", BBB[1]);
									printf("		#2 = %u \n", BBB[2]);
									printf("		#3 = %u \n", BBB[3]);
									printf("		#4 = %u \n", BBB[4]);
									printf("		#5 = %u \n", BBB[5]);
									printf("		#6 = %u \n", BBB[6]);
									printf("\n");
								}
								if (number_of_players >= 7){
									printf("	Numbers of player 7: \n");
									printf("		#1 = %u \n", AAAA[1]);
									printf("		#2 = %u \n", AAAA[2]);
									printf("		#3 = %u \n", AAAA[3]);
									printf("		#4 = %u \n", AAAA[4]);
									printf("		#5 = %u \n", AAAA[5]);
									printf("		#6 = %u \n", AAAA[6]);
									printf("\n");
								}
								if (number_of_players >= 8){
									printf("	Numbers of player 8: \n");
									printf("		#1 = %u \n", BBBB[1]);
									printf("		#2 = %u \n", BBBB[2]);
									printf("		#3 = %u \n", BBBB[3]);
									printf("		#4 = %u \n", BBBB[4]);
									printf("		#5 = %u \n", BBBB[5]);
									printf("		#6 = %u \n", BBBB[6]);
									printf("\n");
								}
								if (number_of_players == 9){
									printf("	Numbers of player 9: \n");
									printf("		#1 = %u \n", AAAAA[1]);
									printf("		#2 = %u \n", AAAAA[2]);
									printf("		#3 = %u \n", AAAAA[3]);
									printf("		#4 = %u \n", AAAAA[4]);
									printf("		#5 = %u \n", AAAAA[5]);
									printf("		#6 = %u \n", AAAAA[6]);
									printf("\n");
								}
								
								if ((gamemode == 1)||(gamemode == 6)||(gamemode == 7)||(gamemode == 8)) {
									printf("	Matchballs player 1: 	%u \n", A[0]);
									printf("	Matchballs player 2: 	%u \n", B[0]);
									if (gamemode == 6) {
										if (number_of_players >= 3){printf("	Matchballs player 3: 	%u \n", AA[0]);}
										if (number_of_players >= 4){printf("	Matchballs player 4: 	%u \n", BB[0]);}
										if (number_of_players >= 5){printf("	Matchballs player 5: 	%u \n", AAA[0]);}
										if (number_of_players >= 6){printf("	Matchballs player 6: 	%u \n", BBB[0]);}
										if (number_of_players >= 7){printf("	Matchballs player 7: 	%u \n", AAAA[0]);}
										if (number_of_players >= 8){printf("	Matchballs player 8: 	%u \n", BBBB[0]);}
										if (number_of_players == 9){printf("	Matchballs player 9: 	%u \n", AAAAA[0]);}
									}
								} else if (gamemode == 2) {
									printf("	Squares collected by player 1: 	%u \n", A[0]);
									printf("	Squares collected by player 2: 	%u \n", B[0]);
								} else if (gamemode == 3) {
									printf("	Times with squares <= 5, player 1: 	%u \n", A[0]);
									printf("	Times with squares <= 5, player 2: 	%u \n", B[0]);
								} else if (gamemode == 4) {
									printf("	Points player 1: 		%u \n", P[1]);
									printf("	Points Player 2: 		%u \n", P[2]);
									printf("	Turns with more points player 1: 	%u \n", A[0]);
									printf("	Turns with more points player 2: 	%u \n", B[0]);
									printf("	Number of not decided #-squares: 	%u \n", P[0]);
								} else if (gamemode == 3) {
									printf("	Times with squares < 5, player 1: 	%u \n", A[0]);
									printf("	Times with squares < 5, player 2: 	%u \n", B[0]);
								} else if (gamemode == 9) {
									printf("	Number of excluded abilites: 	%u \n", exclude_counter);
									printf("	Offensive abilities taken: 	%u \n", number_of_players-ability[0]);
									printf("	Defensive abilities taken: 	%u \n", ability[0]);
								} else if (gamemode == 10) {
									for (unsigned int p=1; p<=number_of_players; p+=1) {
										printf("		Spieler %u: %u life(s) left.\n", p, ulcer_lifes[p]);
									}
								} else if (gamemode == 11) {	//mehr-gamemode
									for (unsigned int p=1; p<=number_of_players; p+=1) {
										if ((ges[p] > 1000)||(ges[p] == 0)) {
											printf("	Spieler %u: is out.\n", p);
										} else if (ges[p] < 1000) {
											printf("	Spieler %u: You own %u squares.\n", p, ges[p]);
										}
									}
								} else if (gamemode == 12) {
									for (unsigned int p=1; p<=number_of_players; p+=1) {
										if ((ges[p] > 1000)||(ges[p] == 0)) {
											printf("	Spieler %u: is out.\n", p);
										} else if (ges[p] < 1000) {
											printf("	Spieler %u: You own %u squares.\n", p, ges[p]);
										}
									}
								}
								
								if (ttt != 0) {
									printf("	Number of penalties given until	now: %u \n", pere[0]);
								}
							}
							
							if (menuoperator == 3){
								if ((gamemode != 10)&&(gamemode != 12)) {
									printf("	Plus: Change a free square in the surrounding of yours in one of yours.\n");
								} else {
									printf("	Plus: Change a square in the surrounding of yours in one of yours.\n");
								}
								printf("	Minus: Delete one of your squares.\n");
								printf("	Move: The position of one of yours will change with a free, near-by square.\n");
								printf("	Revive: Your lost squares having no living squares of yours surrounding them at the beginning of your turn,\n		will be revived.\n");
								printf("	%u/%u-new: A free square has to be surrounded by %u or %u of yours during the development.\n", w+1, w+2, w+1, w+2);
								printf("	%u-new: A free square has to be surrounded by %u of yours during the development.\n", d, d);
								printf("	%u-max: A square of yours will survive even by %u of your squares surrounding it.\n", e+1, e+1);
								if (d == 0) {
									printf("	-1-min: A square of yours will survive even by only -1 of your squares surrounding it.\n");
								} else {
									printf("	%u-min: A square of yours will survive even by only %u of your squares surrounding it.\n", d-1, d-1);
								}
								
								if ((gamemode == 1)||(gamemode == 2)||(gamemode == 4)||(gamemode == 5)||(gamemode == 7)||(gamemode == 9)||(gamemode == 10)) {
									printf("	Change: A square of yours and a near-by square of your enemy will change positions.\n");
									printf("	Destroy: Delete a near-by square of your enemy.\n");
									printf("	Boost: Use all near-by squares of your enemy as your own for the development.\n");
									
								} else if (gamemode == 3) {
									
									printf("	Change: A square of yours and a square of your enemy in the surrounding will change positions.\n");
									printf("	Destroy: Delete a surrounding square of your enemy.\n");
									printf("	Boost: Use all surrounding squares of your enemy as your own for the development.\n");
									
								} else if (gamemode == 8) {
									printf("	Change: A square of yours and a near-by #-square will change positions.\n");
									printf("	Destroy: Delete a square of your enemy, but not in the last two lines.\n");
									printf("	Boost: Use all near-by #-squares as your own for the development.\n");
									
								} else if (gamemode == 6) {
									if (geben == 1) {
										printf("	Change: The heart-block and a square of yours will change positions.\n");
										printf("	Destroy: Delete a square of your enemy.\n");
										printf("	Boost: Touching the heart_block no square of yours can die.\n");
									} else {
										printf("	Change: A square of yours and a near-by square of the hunted one will change positions.\n");
										printf("	Destroy: Delete a near-by square of your enemy.\n");
										printf("	Boost: Use all near-by squares of the hunted one as your own for the development.\n");
									}
									
								} else if (gamemode == 11) {	//mehr-gamemode
									printf("	Change: A square of yours and a near-by square of your enemy or the near-by ball will change positions.\n");
									printf("	Destroy: Delete a near-by square of your enemy.\n");
									printf("	Boost: Use all near-by squares of your enemy and the near-by ball as your own for the development.\n");
								} else if (gamemode == 12) {
									printf("	Change: A square of yours and a near-by square of your enemy or a near-by object will change positions.\n");
									printf("	Destroy: Delete a near-by square of your enemy or a near-by object.\n");
									printf("	Boost: Use all near-by squares of your enemy and near-by objects as your own for the development.\n");
								}
								
								printf("\n");
							}
							
							if (menuoperator == 4){	//mehr-gamemode
								if ((gamemode != 10)&&(gamemode != 12)) {
									printf("	Limit of development:	%u \n", limit_new);
									if (gamemode != 3) {
										printf("	Limit in total:		%u \n", limit_at_all);
										printf("	Limit in total with >2-new< taken: %u -0/-1/-2/-3/-4.\n", limit_at_all);
									}
								}
							}
							
							if (menuoperator == 5){
								Spielfeld hint;
								unsigned int b, a;
								hint = Spielfeld_Create (m, n);
								printf("	New: 1 \n	Dying: 2 \n	Both: 3 \n");
								scanf("%u", &menuoperator);
								
								for (unsigned int i=1; i<(m-1); i+=1){
									for (unsigned int j=1; j<(n-1); j+=1){
										if ((gamemode != 6)&&(gamemode != 9)&&(gamemode != 10)&&(gamemode != 11)&&(gamemode != 12)) {	//mehr-gamemode
											if (Sf[i][j] == geben){
												hint[i][j] = geben;
											} else if (Sf[i][j] == (geben%2)+1){
												hint[i][j] = (geben%2)+1;
											} else if (Sf[i][j] == 7){
												hint[i][j] = 7;
											} 
										} else if ((gamemode == 6)||(gamemode == 9)||(gamemode == 10)) {	//10
											if (Sf[i][j] == geben){
												hint[i][j] = geben;
											} else if (Sf[i][j] != 0){
												hint[i][j] = 17;
											}
										} else if (gamemode == 11) {
											if (Sf[i][j] == geben){
												hint[i][j] = geben;
											} else if (Sf[i][j] == 77){
												hint[i][j] = 77;
											} else if (Sf[i][j] != 0){
												hint[i][j] = 17;
											}
										} else if (gamemode == 12) {	//mehr-gamemode
											if (Sf[i][j] == geben){
												hint[i][j] = geben;
											} else if (Sf[i][j] == 81){
												hint[i][j] = 81;
											} else if (Sf[i][j] == 82){
												hint[i][j] = 82;
											} else if (Sf[i][j] == 83){
												hint[i][j] = 83;
											} else if (Sf[i][j] == 84){
												hint[i][j] = 84;
											} else if (Sf[i][j] == 75){
												hint[i][j] = 75;
											} else if (Sf[i][j] == 71){
												hint[i][j] = 71;
											} else if (Sf[i][j] != 0){
												hint[i][j] = 17;
											}
										}
									}
								}
								
								if ((menuoperator == 2)||(menuoperator == 3)){
									for (unsigned int i=1; i<(m-1); i+=1){
										for (unsigned int j=1; j<(n-1); j+=1){
											if (Sf[i][j] == geben){
												a = 0;
												for (unsigned int h=(i-1); h<=(i+1); h+=1){
													for (unsigned int k=(j-1); k<=(j+1); k+=1){
														if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
															if (Sf[h][k] == geben){
																a += 1;
															}
														}
													}
												}
												if ((a > 4) || (a < 3)){
													hint[i][j] = 16;
												}
											}
										}
									}
								}
								
								if ((menuoperator == 1)||(menuoperator == 3)){
									for (unsigned int i=1; i<(m-1); i+=1){
										for (unsigned int j=1; j<(n-1); j+=1){
											if (Sf[i][j] == 0){
												b = 0;
												for (unsigned int h=(i-1); h<=(i+1); h+=1){
													for (unsigned int k=(j-1); k<=(j+1); k+=1){
														if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
															if (Sf[h][k] == geben){
																b += 1;
															}
														}
													}
												}
												if (b == 3){
													hint[i][j] = 15;
												}
											}
										}
									}
								}
						
								if (opague >= 1) {
									Sf_opague = opague_builder (hint, m, n, geben, opague, aop);
								}
								
								if (opague >= 1) {
									show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
								} else {
									show_field (hint, m, n, gamemode, information_code, geben, Colored);
								}
								
								if (opague >= 1) {
									Sf_opague = opague_builder (Sf, m, n, geben, opague, aop);
								}
								
								menuoperator = 1;
								Spielfeld_Destroy (hint, m);
							}
							// 2
							if (menuoperator == 6){
								if (suprise == 0) {
									for (unsigned int i=1; i<m-1; i+=1){
										for (unsigned int j=1; j<n-1; j+=1){
											cons_field_9[i][j] = Sf[i][j];
											
											if (journey == 1){
												cons_journey_9[i][j] = Sf_journey[i][j];
											}
										}
									}
									sup_num = use_number;
								}
								
								while (menuoperator != 1) {
						
									printf("	Creator menu. 	Change number: 1	Suprise: 2	Suprise undo: 3	Back: 4 \n");
									scanf ("%u", &lim);
									if (lim == 1){
										printf("	number = ? \n");
										scanf ("%u", &use_number);
									} else if (lim == 2){
								
										printf("\n");
										scanf("%u", &suprise);
								
										if (suprise == 31){
											for (unsigned int i=2; i<m-2; i+=1){
												for (unsigned int j=1; j<n-1; j+=1){
													if (Sf[i][j] != 0){
														if (Sf[i][j] == 1){
															Sf[i][j] = 9;
														} else if (Sf[i][j] == 9){
															Sf[i][j] = 1;
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
								
										if(suprise == 13){
											for (unsigned int i=1; i<m-1; i+=1){
												for (unsigned int j=1; j<n-1; j+=1){
													if (Sf[i][j] == 9){
														Sf[i][j] = 0;
													}
													if (i == (m-2)){
														Sf[m-2][j] = 9;
													}
												}
											}
										}
								
									} else if (lim == 3){
										for (unsigned int i=1; i<m-1; i+=1){
											for (unsigned int j=1; j<n-1; j+=1){
												Sf[i][j] = cons_field_9[i][j];
												
												if (journey == 1){
													Sf_journey[i][j] = cons_journey_9[i][j];
												}
											}
										}
										use_number = sup_num;
									} else if (lim == 4){
										menuoperator = 1;
									} else {
										printf("	Invalid comment");
									}
								}
							}
						}	// menuoperator = 7
						
						if (gamemode == 8) {
							if (opague >= 1) {
								show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
							} else {
								show_field (Sf, m, n, gamemode, information_code, geben, Colored);
							}	//show_field über menuoperator = 7 und stack und so löschen, (verschiebe menuoperator!=0 - Schleife), done
							
							printf("\n");
						
						}
						
						if (ttt != 0) {
							time4 = time(NULL);
							time_saver += difftime(time4, time3);
						}
					}	//Menu-end
					
					menuoperator = 0;
					
					if (var_[9] == 10) {
						menuoperator = 1;
						var_[9] = 5;
					}
					
					if ((tac != 0)&&(var_[9] <= 62)&&(var_[9] > 10)){
						unsigned int tac_controll;
						tac_controll = 0;
						if (((var_[9]%10) > 2)||((var_[9]%10) == 0)){
							var_[9] = 7;
							menuoperator = 1;
						} else {
							for (unsigned int z=var_[9]; z>2; z-=10){
								tac_controll += 1;
							}
							if (tac_controll == 6){
								tac_controll = 0;
							}
							if (CCCCC[tac_controll] == 0){
								var_[9] = 7;
								menuoperator = 1;
							} else {
								CCCCC[tac_controll] -= 1;
							}
						}
					} else if ((tac != 0)&&(var_[9] != 100)&&(var_[9] != 1010)&&(var_[9] != 0)) {
						var_[9] = 7;
					}		
					//tac-mode
					
					if (opt == 5){
						controll_1 = 10+use_number;
						controll_2 = 11+use_number;
					
						for (unsigned int i=0; i<use_number-1; i+=1){
							controll_1 += 9;
							controll_2 += 9;
						}
					
						if (var_[9] == 0){
							controll_1 = 0;
							controll_2 = 0;
						}
						if (var_[9] == 100){
							controll_1 = 100;
							controll_2 = 100;
						}
						if (var_[9] == 1010){
							controll_1 = 1010;
							controll_2 = 1010;
						}
					}
					//
					if (((var_[9] > 0)&&(var_[9] < 10))||(((opt == 5)&&(var_[9] != controll_1))&&((opt == 5)&&(var_[9] != controll_2)))){
						
						if (var_[9] != 5) {
							printf("	You made a mistake, try again: \n");
							printf("\n");
							printf("\n");
						} else {
							printf("	You closed the menu. \n");
							printf("\n");
							printf("\n");
						}
						
						//enough
						
						menuoperator = 1;
					}
					
				}		// menuoperator = 0
				
				
				suprise = 0;
				
				if (var_[9] == 0){
					printf("	Do you really want to end the game ? \n");
					printf("	Yes: 0		No: 1 \n");
					scanf("%u", &lim);
					if (lim == 0){
						break;
					} else if (lim == 1){
						continue;
					} else {
						printf("	0 or 1, it is so difficult to understand? \n");
						printf("	Well, it seems I have to end it by myself... \n");
						break;
					}	
				} else {
					
					if (var_[9] == 100){		//gamemode 6 modify, done
						
						var_[0] = 1;
						
						for (unsigned int i=1; i<m-1; i+=1){
							for (unsigned int j=1; j<n-1; j+=1){
								Sf[i][j] = cons_field_8[i][j];
								
								if (journey == 1){
									Sf_journey[i][j] = cons_journey_8[i][j];
								}
							}
						}
						
						if (opague >= 1) {
							Sf_opague = opague_builder (Sf, m, n, geben, opague, aop);
						}
						
						if (opague >= 1) {
							show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
						} else {
							show_field (Sf, m, n, gamemode, information_code, geben, Colored);
						}
						
						cons[geben] = use_number;
						
						use_number = cons[8];
						
						if (gamemode == 11) {	//mehr-gamemode
							for (unsigned int p=2; p<=5; p+=1) {
								
								dynamic_pointer[p] = dynamic_pointer_save[8][p-2];
								
							}
						}
						
						g-=1;
						var_[9] = 1010;
						if (gamemode == 10) {
							ulcer_lifes[9] += 1;
							ulcer_start[9] = 0;
						}
						continue;
					} else {
						
						if (var_[1] != 1010){
							for (unsigned int i=1; i<m-1; i+=1){
								for (unsigned int j=1; j<n-1; j+=1){
									cons_field_9[i][j] = Sf[i][j];
									
									if (journey == 1){
										cons_journey_9[i][j] = Sf_journey[i][j];
									}
								}
							}
						}
						
						var_[0] = 0;
						
						if (var_[9] < 50){
							
							if (var_[9] == 11){AAAAA[1] += 1; Plus (m, n, geben, Sf, limit_at_all, gamemode, information_code, number_of_players, Colored, opague, Sf_opague);}
							if (var_[9] == 12){AAAAA[1] += 1; Minus (m, n, geben, Sf, gamemode, information_code, Colored, opague, Sf_opague);}
							if (var_[9] == 21){AAAAA[2] += 1; Move (m, n, geben, Sf, gamemode, information_code, Colored, opague, Sf_opague);}
							if (var_[9] == 41){AAAAA[4] += 1; Move (m, n, geben, Sf, gamemode, information_code, Colored, opague, Sf_opague);}
							if (var_[9] == 22){AAAAA[2] += 1; Change (m, n, geben, Sf, gamemode, information_code, Colored, opague, Sf_opague, position);}
							if (var_[9] == 31){AAAAA[3] += 1; Destroy (m, n, geben, Sf, gamemode, information_code, Colored, opague, Sf_opague);}
							if (var_[9] == 42){
								AAAAA[4] += 1; 
								Boost (geben, Sf, m, n, temp, gamemode);
							}
						} else {
							if (var_[9] == 51){AAAAA[5] += 1; w += 1;}		//w
							if (var_[9] == 52){AAAAA[5] += 1; w -= 1;}		//w
							if (var_[9] == 61){AAAAA[6] += 1; e += 1;}		//e
							if (var_[9] == 62){AAAAA[6] += 1; if (d != 0) {d -= 1;} else {d = 10;}}		//d
						}		//printf("ok(1376)");
						
						if (ttt != 0) {
							time2 = time(NULL);
							time_warning = ((difftime(time2, time1)) - time_saver);
							
							//printf("	time_warning: %f \n", time_warning);		//test
							
							if ((pere[geben] != 0)&&((pere[geben] + warning_system) <= 6)) {
								if (pere[geben] == 1) {
									if (warning_system <= 2) {
										time_warning += 1.0;
									} else if (warning_system == 3) {
										time_warning += 2.0;
									} else if (warning_system == 4) {
										time_warning += 3.0;
									} else if (warning_system == 5) {
										time_warning += 5.0;
									}
								} else if (pere[geben] == 2) {
									if (warning_system == 1) {
										time_warning += 2.0;
									} else if (warning_system == 2) {
										time_warning += 3.0;
									} else if (warning_system == 3) {
										time_warning += 5.0;
									} else if (warning_system == 4) {
										time_warning += 6.0;
									}
								} else if (pere[geben] == 3) {
									if (warning_system == 1) {
										time_warning += 3.0;
									} else if (warning_system == 2) {
										time_warning += 5.0;
									} else if (warning_system == 3) {
										time_warning += 8.0;
									}
								} else if (pere[geben] == 4) {
									if (warning_system == 1) {
										time_warning += 4.0;
									} else if (warning_system == 2) {
										time_warning += 7.0;
									}
								} else if (pere[geben] == 5) {
									if (warning_system == 1) {
										time_warning += 5.0;
									}
								}
							}
							
							if (time_warning > (1.0*ttt)) {
								pere[0] += 1;
								printf("	You took too much time! %f sec more than you should. \n", (time_warning-1.0*ttt) );
								printf(" \n");
								for (unsigned int p=16; p>=1; p-=3) {	//index_verschiebung
									if ((time_warning-1.0*ttt) > 1.0*(p-1)) {
										pere[geben] = (((p-1)/3) + 1);
										break;
									}
								}
							} else {
								pere[geben] = 0;
							}
						}
				
						Sf_nl_9 = new_life_9 (Sf, m, n, w, gamemode, information_code);		//printf("ok(1378)");
						
						if (gamemode == 6) {
							
							precounter = 0;
							for (unsigned int i=1; i<m-1; i+=1){
								for (unsigned int j=1; j<n-1; j+=1){
									if (Sf[i][j] == 11){
										if (Sf_nl_3[i][j-1] > 1) {
											printf (" Sieg: Spieler %u \n", Sf_nl_3[i][j-1]);
											precounter += 1;
										}
										if (Sf_nl_3[i][j+1] > 1) {
											if (precounter == 0) {
												printf (" Sieg: Spieler %u \n", Sf_nl_3[i][j+1]);
											}
											precounter += 1;
										}
										if (Sf_nl_3[i-1][j] > 1) {
											if (precounter == 0) {
												printf (" Sieg: Spieler %u \n", Sf_nl_3[i-1][j]);
											}
											precounter += 1;
										}
										if (Sf_nl_3[i+1][j] > 1) {
											if (precounter == 0) {
												printf (" Sieg: Spieler %u \n", Sf_nl_3[i+1][j]);
											}
											precounter += 1;
										}
										if (precounter == 2) {
											printf(" Double-catch! \n");
										}
										if (precounter == 3) {
											printf(" TRIPLE-catch!! \n");
										}
										if (precounter == 4) {
											printf(" QUADRO-CATCH!!! \n");
										}
										break;
									}
								}
								if (precounter > 0) {
									break;
								}
							}
							if (precounter > 0) {
								for (unsigned int i=1; i<m-1; i+=1){
									for (unsigned int j=1; j<n-1; j+=1){
										if (Sf_nl_3[i][j] == geben) {
											Sf[i][j] = geben;
										}
									}
								}
								show_field (Sf, m, n, gamemode, information_code, geben, Colored);
								break;
							}
						}
						
						controll = 0;
						if (gamemode == 7) {	// possible to modify
							for (unsigned int i=(m-2); i>=(m-1)/2; i-=1){		//Spiel-Ende?
								if ((Sf_nl_9[i][n-2] == 2)||(Sf[i][n-2] == 9)){
									for (unsigned int k=(m-2); k>=1; k-=1){
										if (Sf_nl_9[k][n-2] == 9){
											Sf[k][n-2] = 9;
										}
									}
									show_field (Sf, m, n, gamemode, information_code, geben, Colored);
									printf("	Sieg:	Spieler 9 \n");
									controll = 1;
								}
							}
							if (controll == 1){
								break;
							}
						}
						controll = 0;
						
						num_1 = 0;
						for (unsigned int i=1; i<m-1; i+=1){
							for (unsigned int j=1; j<n-1; j+=1){
								if (Sf_nl_9[i][j] == 9){
									num_1 += 1;
								}
							}
						}		//printf("ok(1387)");	
					
						if (var_[9] == 42){
							for (unsigned int i=1; i<m-1; i+=1){
								for (unsigned int j=1; j<n-1; j+=1){
									if (gamemode == 8) {
										if (temp[i][j] == 9){
											Sf[i][j] = 0;
										}
									} else if ((gamemode == 9)||(gamemode == 10)||(gamemode == 11)||(gamemode == 12)) {	//mehr-gamemode
										if (temp[i][j] != 0){
											Sf[i][j] = temp[i][j];
										}
									} else if (gamemode == 6) {	//10
										if (temp[i][j] == 9){
											Sf[i][j] = 1;
										}
									}
								}
							}
						}		//printf("ok(1398)");	
						// possible to modify
						
						controll = 0;
						if (gamemode == 1){	// possible to modify
							for (unsigned int erste=1; erste<n-1; erste+=1){		//printf("ok(1400)");		//Spiel-Ende?
								if (Sf[1][erste] == 9){
									printf("	Sieg:	Spieler 9 \n");
									show_field (Sf, m, n, gamemode, information_code, geben, Colored);
									controll = 1;		//printf("ok(1404)");
									break;
								}
							}
							if (controll == 1){
								break;		//printf("ok(1409)");
							}		//printf("ok(1410)");
						}
						controll = 0;
						
						Spielfeld_Destroy (temp, m);		//printf("ok(1412)");
					
						Sf_od_9 = old_dying_9 (Sf, m, n, d, e, gamemode, information_code);		//printf("ok(1414)");
						
						if (journey == 1){
							unsigned int journey_max;
							journey_max = 0;
							for (unsigned int i=1; i<m-1; i+=1){
								for (unsigned int j=1; j<n-1; j+=1){
									if (Sf_journey[i][j] == 9){
										journey_max += 1;
									}
								}
							}
							for (unsigned int i=1; i<m-1; i+=1){
								for (unsigned int j=1; j<n-1; j+=1){
									if ((Sf_od_9[i][j] == 909) && (Sf_journey[i][j] == 0) && (journey_max >= limit_at_all)){
										for (unsigned int u=(m-2); u>0; u-=1){
											for (unsigned int o=1; o<(n-1); o+=1){
												if ((Sf_journey[u][o] == 9)&&((u+o)%2 == 0)){
													Sf_journey[u][o] = 0;
													journey_max -= 1;
													if (journey_max < limit_at_all){
														break;
													}
												}
											}
											if (journey_max < limit_at_all){
												break;
											}
										}
										
									}
									if ((Sf_od_9[i][j] == 909) && (Sf_journey[i][j] == 0) && (journey_max < limit_at_all)){
										Sf_journey[i][j] = 9;
										journey_max += 1;
									}
								}
							}
							journey_max = 0;
						}
						
						if (var_[9] == 32){AAAAA[3] += 1; Revive_9(m, n, Sf_od_9, Sf);}
						
						num_2 = 0;
						for (unsigned int i=1; i<m-1; i+=1){
							for (unsigned int j=1; j<n-1; j+=1){
								if (Sf_od_9[i][j] == 909){
									num_2 += 1;
								}
							}
						}
					
						count_new = 0;
						for (unsigned int i=1; i<m-1; i+=1){
							for (unsigned int j=1; j<n-1; j+=1){
								if (Sf_nl_9[i][j] == 9){
									count_new += 1;
								}
							}
						}
						ent = limit_new;		//printf("ok(1473)");
						
						for (unsigned int i=1; i<m-1; i+=1){
							for (unsigned int j=1; j<n-1; j+=1){
								if ((Sf[i][j] == 9) && (Sf_od_9[i][j] == 0)){
									zeitgewinner += 1;
								}
							}
						}
						
						if (count_new > limit_new){		//Abfrage auf max. 10 neue Steine
							/*if (gamemode == 1) {
								Sf_nl_9 = Index_9 (ent, count_new, m, n, Sf, Sf_nl_9, Sf_od_9, limit_new, limit_at_all, zeitgewinner);	
							} else if (gamemode == 2) {
								Sf_nl_9 = Index_9_col (ent, count_new, m, n, Sf, Sf_nl_9, Sf_od_9, limit_new, limit_at_all, zeitgewinner);	
							} else if (gamemode == 3) {
								Sf_nl_9 = Index_9_con (ent, count_new, m, n, Sf, Sf_nl_9, limit_new);
							} else if (gamemode == 4) {
								Sf_nl_9 = Index_9_fal (ent, count_new, m, n, Sf, Sf_nl_9, Sf_od_9, limit_new, limit_at_all, zeitgewinner);	
							} else if (gamemode == 5) {
								Sf_nl_9 = Index_9_fig (ent, count_new, m, n, Sf, Sf_nl_9, Sf_od_9, limit_new, limit_at_all, zeitgewinner);	
							} else if (gamemode == 7) {
								Sf_nl_9 = Index_9_race (ent, count_new, m, n, Sf, Sf_nl_9, Sf_od_9, limit_new, limit_at_all, zeitgewinner);	
							} else if (gamemode == 8) {
								Sf_nl_9 = Index_9_rain (ent, count_new, m, n, Sf, Sf_nl_9, Sf_od_9, limit_new, limit_at_all, rain, zeitgewinner);	
							}*/
							if (gamemode == 6) {
								Sf_nl_9 = Index_other_hunt (ent, count_new, m, n, Sf_nl_9, geben, zeitgewinner, Sf, limit_at_all);	
							} else if (gamemode == 9) {
								Sf_nl_9 = Index_are (ent, count_new, m, n, Sf_nl_9, Sf_od_9, limit_new, limit_at_all, zeitgewinner, Sf, w, d, e, geben);
							} else if (gamemode == 10) {
								count_new = 0;
							} else if (gamemode == 11) {
								Sf_nl_9 = Index_dyn (ent, count_new, m, n, Sf_nl_9, Sf_od_9, limit_new, limit_at_all, zeitgewinner, Sf, w, d, e, geben, position);
							} else if (gamemode == 12) {	//mehr-gamemode
								count_new = 0;
							}
						
						}
						ent = 0;
						count_new = 0;		//printf("ok(1478)");
					
						num_3 = 0;
						for (unsigned int i=1; i<m-1; i+=1){
							for (unsigned int j=1; j<n-1; j+=1){
								if (((Sf[i][j] == 9) && (Sf_od_9[i][j] == 0)) || (Sf_nl_9[i][j] == 9)){
									count_new += 1;
									num_3 += 1;
								}
							}
						}
						
						ent = limit_at_all;
						if ((gamemode == 1)||(gamemode == 2)||(gamemode == 4)||(gamemode == 5)||(gamemode == 7)||(gamemode == 8)) {
							
							if (var_[9] == 52){
											//printf("ok(1492)");
								lim = 0;
								for (unsigned int i=1; i<m-1; i+=1){
									for (unsigned int j=1; j<n-1; j+=1){
										if ((Sf[i][j] == 9) && (Sf_od_9[i][j] == 0)){
											lim += 1;
										}
									}
								}
											//printf("ok(1501)");
								ent = lim;
											//printf("ok(1503)");
								lim = 0;
								for (unsigned int i=1; i<m-1; i+=1){
									for (unsigned int j=1; j<n-1; j+=1){
										if (Sf[i][j] == 1){
											lim += 1;
										}
									}
								}			//printf("ok(1511)");
							
							
								if ((lim <= limit_new) && (ent < (limit_at_all - 1))){
									if (ent >= (limit_at_all - 3)){
										ent = limit_at_all - 1;
									} else if (ent >= (limit_at_all - 5)){
										ent = limit_at_all - 2;
									} else if (ent >= (limit_at_all - 7)){
										ent = limit_at_all - 3;
									} else if (ent >= (limit_at_all - 10)){
										ent = limit_at_all - 4;
									} else {
										ent = limit_at_all;
									}		//printf("ok(1523)");
								} else {		//printf("ok(1524)");
									ent = limit_at_all;
								}
								lim = 0;
											//printf("ok(1528)");
							}
						}	// possible to modify
						
						if (count_new > ent){		//Abfrage auf insgesamt max. 20 Steine, normalerweise
							/*if (gamemode == 1) {
								Sf_nl_9 = Index_9 (ent, count_new, m, n, Sf, Sf_nl_9, Sf_od_9, limit_new, limit_at_all, zeitgewinner);	
							} else if (gamemode == 2) {
								Sf_nl_9= Index_9_col  (ent, count_new, m, n, Sf, Sf_nl_9, Sf_od_9, limit_new, limit_at_all, zeitgewinner);	
							} else if (gamemode == 3) {
								count_new = 0;
							} else if (gamemode == 4) {
								Sf_nl_9 = Index_9_fal (ent, count_new, m, n, Sf, Sf_nl_9, Sf_od_9, limit_new, limit_at_all, zeitgewinner);	
							} else if (gamemode == 5) {
								Sf_nl_9 = Index_9_fig (ent, count_new, m, n, Sf, Sf_nl_9, Sf_od_9, limit_new, limit_at_all, zeitgewinner);	
							} else if (gamemode == 7) {
								Sf_nl_9 = Index_9_race (ent, count_new, m, n, Sf, Sf_nl_9, Sf_od_9, limit_new, limit_at_all, zeitgewinner);	
							} else if (gamemode == 8) {
								Sf_nl_9 = Index_9_rain (ent, count_new, m, n, Sf, Sf_nl_9, Sf_od_9, limit_new, limit_at_all, rain, zeitgewinner);	
							}*/
							if (gamemode == 6) {
								Sf_nl_9 = Index_other_hunt (ent, count_new, m, n, Sf_nl_9, geben, zeitgewinner, Sf, limit_at_all);	
							} else if (gamemode == 9) {
								Sf_nl_9 = Index_are (ent, count_new, m, n, Sf_nl_9, Sf_od_9, limit_new, limit_at_all, zeitgewinner, Sf, w, d, e, geben);
							} else if (gamemode == 10) {
								count_new = 0;
							} else if (gamemode == 11) {
								Sf_nl_9 = Index_dyn (ent, count_new, m, n, Sf_nl_9, Sf_od_9, limit_new, limit_at_all, zeitgewinner, Sf, w, d, e, geben, position);
							} else if (gamemode == 12) {	//mehr-gamemode
								count_new = 0;
							}
						
						}
						ent = 0;
						zeitgewinner = 0;

						if (gamemode == 4) {
							touch (Sf, m, n, geben, Sf_nl_1, Sf_nl_2);	//possible to modify
						}	// possible to modify
						
						Sf = change_9 (Sf, Sf_nl_9, Sf_od_9, m, n, gamemode, number_of_players, ges);
						
						if (gamemode == 1) {
							for (unsigned int j=1; j<n-1; j+=1){	//possible to modify
								if (Sf[2][j] == 2){
									B[0] += 1;
									break;
								}
							} 
						} else if (gamemode == 2) {	//possible to modify
							for (unsigned int j=2; j<n-1; j+=((n-1)/2)-2){		//collect-Bed. prüfen
								unsigned int b;
								b = 0;
								if (Sf[((m-1)/2)][j] == 7){
									if (Sf[((m-1)/2)-1][j]==2){b += 1;}
									if (Sf[((m-1)/2)+1][j]==2){b += 1;}
									if (Sf[(m-1)/2][j-1]==2){b += 1;}
									if (Sf[(m-1)/2][j+1]==2){b += 1;}
									if (b >= 3){
										B[0] += 1;
										Sf[((m-1)/2)][j] = 2;
									}
								}
							}
							if (B[0] == 2){
								printf("\n");
								printf("	Sieg: Spieler 2 \n");
								printf("\n");
								show_field (Sf, m, n, gamemode, information_code, geben, Colored);
								break;
							}
						}
						
						if ((gamemode == 6)&&(geben == number_of_players)) {
							lim = 1;
							printf("	\n");
							if (opague >= 1) {
								show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
							} else {
								show_field (Sf, m, n, gamemode, information_code, geben, Colored);
							}
							printf("	\n");
							while (lim == 1) {
								printf("	\n");
								printf("	\n");
								printf("	Are you ready to make your turn? \n");
								printf("	Yes: 1 \n");
								printf("	\n");
								printf("	\n");
								scanf("%u", &lim);
								
								if (lim != 1) {
									lim = 1;
								} else {
									lim = 0;
								}
							}
						}
						if (gamemode == 6) {
							information_code[3] = 0;
						}
						
						controll = 0;
						if (gamemode == 1) {	//possible to modify
							for (unsigned int erste=1; erste<n-1; erste+=1){		//Spiel-Ende?
								if (Sf[1][erste] == 2){
									printf("	Sieg:	Spieler 2 \n");
									controll = 1;
									break;
								}
							}
							if (controll == 1){
								break;
							}
						}
						controll = 0;
						
						if (gamemode == 3) {	//possible to modify
							if (opague >= 1) {
								show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
							} else {
								show_field (Sf, m, n, gamemode, information_code, geben, Colored);
							}
							battle (m, n, Sf, geben);
						}
						
						if (number_of_players == 9) {// gamemode 6 modify, done!
							if (var_[1] != 1010) {
								cons[9] = use_number;
								
								if (gamemode == 11) {	//mehr-gamemode
									for (unsigned int p=2; p<=5; p+=1) {
										
										dynamic_pointer_save[9][p-2] = dynamic_pointer[p];
										
									}
								}
								
							}
						}
						
						use_number = random_number (num_1, num_2, num_3, use_number, g, var_, number_3, number_4);
						
						if ((opt != 5)&&(var_[9] <= 62)){
							controll_2 = 0;
							for (unsigned int z=var_[9]; z>2; z-=10){
								controll_2 += 1;
							}
							number_9 = controll_2;
							//printf("%u \n", number_9);
							controll_2 = 0;
						}
					}
				}	//{}ausfindig machen		(?)
			}
			
			printf("\n");
			
			if (gamemode == 8) {
				
				Sf_opague = opague_builder (Sf, m, n, (geben % 2)+1, opague, aop);	//possible to modify
				
				if (opague >= 1) {
					show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
				} else {
					show_field (Sf, m, n, gamemode, information_code, geben, Colored);
				}
			
				printf("\n");
				printf("\n");
				printf("\n");
				printf("\n");
				printf("\n");
				printf("\n");
				printf("\n");
				
				if (rain == 1){
					printf("		Rain-Characteristics: Push \n");
				} else if (rain == 2){
					printf("		Rain-Characteristics: Destroy \n");
				} else if (rain == 31){
					printf("		Rain-Characteristics: Explode \n");
				} else if (rain == 32){
					printf("		Rain-Characteristics: Explode & survival \n");
				} else if (rain == 4){
					printf("		Rain-Characteristics: Transform \n");
				} else if (rain == 5){
					printf("		Rain-Characteristics: Teleport \n");
				} else if (rain == 6){
					printf("		Rain-Characteristics: Mixed \n");
				}
				
				number_rain = use_number;
				
				if ((rain_speed == 0) && (((g-1)%4) >= 2)){
					printf("	\n");
					printf("	Falling slowly...\n");
					printf("	\n");
					if (opague >= 1) {
						show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
					} else {
						show_field (Sf, m, n, gamemode, information_code, geben, Colored);
					}
				} else {
					if (rain_speed == 0){
						rain_speed_save = 1;
						rain_speed = 1;
					}
				
					for (unsigned int r=1; r<=rain_speed; r+=1){
						if (rain == 6){
							rain_save = 6;
							if (number_rain == 1){
								rain = 1;
							} else if (number_rain == 2){
								rain = 2;
							} else if (number_rain == 3){
								rain = 31;
							} else if (number_rain == 4){
								rain = 4;
							} else if (number_rain == 5){
								rain = 5;
							} else if (number_rain == 6){
								rain = 32;
							}
						}
						if (geben == 1){
							for (unsigned int i=m-2; i>0; i-=1){
								for (unsigned int j=0; j<((n-1)/2); j+=1){
									if (Sf[i][j] == 7){
										if (Sf[i+1][j] != 0){
											
											if (rain == 1){
												unsigned int mem;
												mem = i;
												while ((Sf[i+1][j] != 0)&&((i+1)<=(m-2))){
													if ((i+1)<=(m-2)){
														Sf[mem][j] = Sf[i+1][j];
													}
													
													if (i == mem) {
														
														if ((Sf[mem+2][j] == 0)&&((mem+2)<=(m-2))) {
															Sf[mem+2][j] = Sf[mem][j];
															break;
														} else if ((Sf[mem+2][j] != 0)&&((mem+2)<=(m-2))) {
															Sf[mem+1][j] = Sf[mem+2][j];
															Sf[mem+2][j] = Sf[mem][j];
															if ((Sf[mem+3][j] == 0)&&((mem+3)<=(m-2))) {
																Sf[mem+3][j] = Sf[mem+1][j];
															}
														}
														
														i += 2;
													} else {
														
														i += 1;
														
														Sf[i][j] = Sf[mem+1][j];
														
														if ((Sf[i+1][j] == 0)&&((i+1)<=(m-2))){
															Sf[i+1][j] = Sf[mem][j];
															break;
														}
														Sf[mem+1][j] = Sf[mem][j];
														
													}
												}
												i = mem;
												Sf[i][j] = 0;
												if (i < (m-2)) {
													Sf[i+1][j] = 7;
												}
												
											} else if (rain == 2){
												Sf[i+1][j] = 7;
												Sf[i][j] = 0;
											} else if (rain == 31){
												for (unsigned int h=i; h<=i+2; h+=1){
													for (unsigned int k=j-1; k<=j+1; k+=1){
														if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
															Sf[h][k] = 0;
														}
													}
												}
											} else if (rain == 32){
												for (unsigned int h=i; h<=i+2; h+=1){
													for (unsigned int k=j-1; k<=j+1; k+=1){
														if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
															if (Sf[h][k] == 7){
																Sf[h][k] = geben;
															} else {
																Sf[h][k] = 0;
															}
														}
													}
												}
												Sf[i][j] = 0;
												Sf[i+1][j] = geben;
											} else if (rain == 4){
												if((Sf[i-1][j] == geben)||(Sf[i+1][j] == geben)||(Sf[i][j-1] == geben)||(Sf[i][j+1] == geben)){
													Sf[i][j] = geben;
												} else {
													if (i != (m-2)){
														Sf[i+1][j] = 7;
													}
													Sf[i][j] = 0;									
												}
											} else if (rain == 5){
												
												if (Sf[i+1][j] == geben){
													Sf[i-1][j] = geben;
													Sf[i+1][j] = 0;
												} else if (Sf[i][j-1] == geben){
													Sf[i][j+1] = geben;
													Sf[i][j-1] = 0;
												} else if ((Sf[i][j+1] == geben) && (((Sf[i][j+2] != 7) || (Sf[i+1][j+2] != geben)) && (Sf[i-1][j+1] != 7))){
													Sf[i][j-1] = geben;
													Sf[i][j+1] = 0;
												} else if ((Sf[i-1][j] == geben) && (Sf[i-2][j] != 7) && (Sf[i-1][j-1] != 7)){   
													Sf[i+1][j] = geben;
													Sf[i-1][j] = 0;
												}
												Sf[i+1][j] = 7;
												Sf[i][j] = 0;
											}
										} else {
											
											if (rain == 5){
												if (Sf[i+1][j] == geben){
													Sf[i-1][j] = geben;
													Sf[i+1][j] = 0;
												} else if (Sf[i][j-1] == geben){
													Sf[i][j+1] = geben;
													Sf[i][j-1] = 0;
												} else if ((Sf[i][j+1] == geben) && (((Sf[i][j+2] != 7) || (Sf[i+1][j+2] != geben)) && (Sf[i-1][j+1] != 7))){
													Sf[i][j-1] = geben;
													Sf[i][j+1] = 0;
												} else if ((Sf[i-1][j] == geben) && (Sf[i-2][j] != 7) && (Sf[i-1][j-1] != 7)){   
													Sf[i+1][j] = geben;
													Sf[i-1][j] = 0;
												}
											}
											if (rain == 4){
												if((Sf[i-1][j] == geben)||(Sf[i+1][j] == geben)||(Sf[i][j-1] == geben)||(Sf[i][j+1] == geben)){
													Sf[i][j] = geben;
												} else {
													if (i != (m-2)){
														Sf[i+1][j] = 7;
													}
													Sf[i][j] = 0;									
												}
											} else {
												if (i != (m-2)){
													Sf[i+1][j] = 7;
												}
												Sf[i][j] = 0;
											}
										}
									}
								}
							}
							if (rain_drops == 1){
								Sf[1][number_rain] = 7;
							} else if (rain_drops == 2){
								Sf[1][number_rain] = 7;
								Sf[1][((n-1)/2)-number_rain] = 7;
							} else if (rain_drops == 4){
								for (unsigned int s=0; s<(n-1)/2; s+=1){
									if ((s != number_rain)&&(s != ((n-1)/2)-number_rain)){
										Sf[1][s] = 7;
									}
								}
							} else if (rain_drops == 5){
								for (unsigned int s=0; s<(n-1)/2; s+=1){
									if (s != number_rain){
										Sf[1][s] = 7;
									}
								}
							} else if (rain_drops == 6){
								for (unsigned int s=0; s<(n-1)/2; s+=1){
									Sf[1][s] = 7;
								}
							}
							
						} else if (geben == 2) {
							for (unsigned int i=m-2; i>0; i-=1){
								for (unsigned int j=(n-2); j>((n-1)/2); j-=1){
									if (Sf[i][j] == 7){
										if (Sf[i+1][j] != 0){
											
											if (rain == 1){
												unsigned int mem;
												mem = i;
												while ((Sf[i+1][j] != 0)&&((i+1)<=(m-2))){
													if ((i+1)<=(m-2)){
														Sf[mem][j] = Sf[i+1][j];
													}
													
													if (i == mem) {
														
														if ((Sf[mem+2][j] == 0)&&((mem+2)<=(m-2))) {
															Sf[mem+2][j] = Sf[mem][j];
															break;
														} else if ((Sf[mem+2][j] != 0)&&((mem+2)<=(m-2))) {
															Sf[mem+1][j] = Sf[mem+2][j];
															Sf[mem+2][j] = Sf[mem][j];
															if ((Sf[mem+3][j] == 0)&&((mem+3)<=(m-2))) {
																Sf[mem+3][j] = Sf[mem+1][j];
															}
														}
														
														i += 2;
													} else {
														
														i += 1;
														
														Sf[i][j] = Sf[mem+1][j];
														
														if ((Sf[i+1][j] == 0)&&((i+1)<=(m-2))){
															Sf[i+1][j] = Sf[mem][j];
															break;
														}
														Sf[mem+1][j] = Sf[mem][j];
														
													}
												}
												i = mem;
												Sf[i][j] = 0;
												if (i < (m-2)) {
													Sf[i+1][j] = 7;
												}
											} else if (rain == 2){
												Sf[i+1][j] = 7;
												Sf[i][j] = 0;
											} else if (rain == 31){
												for (unsigned int h=i; h<=i+2; h+=1){
													for (unsigned int k=j-1; k<=j+1; k+=1){
														if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
															Sf[h][k] = 0;
														}
													}
												}
											} else if (rain == 32){
												for (unsigned int h=i; h<=i+2; h+=1){
													for (unsigned int k=j-1; k<=j+1; k+=1){
														if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
															if (Sf[h][k] == 7){
																Sf[h][k] = geben;
															} else {
																Sf[h][k] = 0;
															}
														}
													}
												}
												Sf[i][j] = 0;
												Sf[i+1][j] = geben;
											} else if (rain == 4){
												if((Sf[i-1][j] == geben)||(Sf[i+1][j] == geben)||(Sf[i][j-1] == geben)||(Sf[i][j+1] == geben)){
													Sf[i][j] = geben;
												} else {
													if (i != (m-2)){
														Sf[i+1][j] = 7;
													}
													Sf[i][j] = 0;									
												}
											} else if (rain == 5){
												if (Sf[i+1][j] == geben){
													Sf[i-1][j] = geben;
													Sf[i+1][j] = 0;						
												} else if (Sf[i][j+1] == geben){
													Sf[i][j-1] = geben;
													Sf[i][j+1] = 0;	
												} else if ((Sf[i][j-1] == geben) && ((Sf[i][j-2] != 7)||(Sf[i+1][j-2] != geben)) &&(Sf[i-1][j-1] != 7)){
													Sf[i][j+1] = geben;
													Sf[i][j-1] = 0;
												} else if ((Sf[i-1][j] == geben) && (Sf[i-2][j] != 7) && (Sf[i-1][j+1] != 7)){
													Sf[i+1][j] = geben;
													Sf[i-1][j] = 0;
												}
												Sf[i+1][j] = 7;
												Sf[i][j] = 0;
											}
										} else {
											
											if (rain == 5){
												 if (Sf[i][j+1] == geben){
													Sf[i][j-1] = geben;
													Sf[i][j+1] = 0;	
												} else if ((Sf[i][j-1] == geben) && ((Sf[i][j-2] != 7)||(Sf[i+1][j-2] != geben)) &&(Sf[i-1][j-1] != 7)){
													Sf[i][j+1] = geben;
													Sf[i][j-1] = 0;
												} else if ((Sf[i-1][j] == geben) && (Sf[i-2][j] != 7) && (Sf[i-1][j+1] != 7)){
													Sf[i+1][j] = geben;
													Sf[i-1][j] = 0;
												}
											}
											
											if (rain == 4){
												if((Sf[i-1][j] == geben)||(Sf[i][j-1] == geben)||(Sf[i][j+1] == geben)){
													Sf[i][j] = geben;
												} else {
													if (i != (m-2)){
														Sf[i+1][j] = 7;
													}
													Sf[i][j] = 0;									
												}
											} else {
												if (i != (m-2)){
													Sf[i+1][j] = 7;
												}
												Sf[i][j] = 0;
											}
										}
									}
								}
							}
							if (rain_drops == 1){
								Sf[1][n-(1+number_rain)] = 7;
							} else if (rain_drops == 2){
								Sf[1][n-(1+number_rain)] = 7;
								Sf[1][((n-1)/2)+number_rain] = 7;
							} else if (rain_drops == 4){
								for (unsigned int s=(n+1)/2; s<(n-1); s+=1){
									if ((s != (n-(1+number_rain)))&&(s != (((n-1)/2)+number_rain))){
										Sf[1][s] = 7;
									}
								}
							} else if (rain_drops == 5){
								for (unsigned int s=(n+1)/2; s<(n-1); s+=1){
									if (s != (n-(1+number_rain))){
										Sf[1][s] = 7;
									}
								}
							} else if (rain_drops == 6){
								for (unsigned int s=(n+1)/2; s<(n-1); s+=1){
									Sf[1][s] = 7;
								}
							}
							
						}
						number_rain = (number_rain%6) + 1;
						if (opague >= 1) {
							show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
						} else {
							show_field (Sf, m, n, gamemode, information_code, geben, Colored);
						}
						if (rain_save == 6){
							rain = 6;
						}
					}
				
				}	//speed = 0,5 (=0)
				
				if (rain_speed_save == 1){
					rain_speed_save = 0;
					rain_speed = 0;
				}
				
				for (unsigned int j=0; j<n; j+=1){
					Sf[0][j] = 0;
					Sf[m-1][j] = 0;
				}
				for (unsigned int i=0; i<m; i+=1){
					Sf[i][0] = 0;
					Sf[i][n-1] = 0;
				}
				
				printf("\n");
				printf("		Get: [1][7] \n");
				printf("\n");
				
				if (Sf[1][((n-1)/2)] != 0){
					show_field (Sf, m, n, gamemode, information_code, geben, Colored);
					if (Sf[1][((n-1)/2)] == 1){
						printf ("	Sieg: 	Spieler 1 \n");
					} else if (Sf[1][((n-1)/2)] == 2){
						printf ("	Sieg: 	Spieler 2 \n");
					}
					break;
				}
				
				if ((Sf[1][((n-3)/2)] == 1)||(Sf[1][((n+1)/2)] == 1)||(Sf[2][((n-1)/2)] == 1)){
					A[0] += 1;
				}
				if ((Sf[1][((n-3)/2)] == 2)||(Sf[1][((n+1)/2)] == 2)||(Sf[2][((n-1)/2)] == 2)){
					B[0] += 1;
				}
				
				for (unsigned int i=1; i<m-1; i+=1){
					for (unsigned int j=1; j<n-1; j+=1){
						if (Sf[i][j] == 2){
							ges[2] += 1;
						}
					}
				}
				if (ges[2] == 0){
					if (rain_obj == 1){
						Sf[m-3][n-3] = 2;
						Sf[m-3][n-2] = 2;
						Sf[m-2][n-3] = 2;
					} else {
						printf("	Sieg:	Spieler 1 \n");
						break;
					}
					
				}
				ges[2] = 0;
				
				
				for (unsigned int i=1; i<m-1; i+=1){
					for (unsigned int j=1; j<n-1; j+=1){
						if (Sf[i][j] == 1){
							ges[1] += 1;
						}
					}
				}
				if (ges[1] == 0){
					if (rain_obj == 1){
						Sf[m-3][2] = 1;
						Sf[m-3][1] = 1;
						Sf[m-2][2] = 1;
					} else {
						printf("	Sieg:	Spieler 2 \n");
						break;
					}
					
				}
				ges[1] = 0;
			}
			
			if ((gamemode == 1)||(gamemode == 2)||(gamemode == 3)) {
				if (journey == 1){
					if (((g-1)%19) == 18){
						printf (" \n");
						printf (" \n");
						printf ("	It is time for a journey... \n");
						printf (" \n");
						for (unsigned int i=1; i<m-1; i+=1){
							for (unsigned int j=1; j<n-1; j+=1){
								if (Sf[i][j] != 7) {
									
									Sf[i][j] = Sf_journey[i][j];
									Sf_journey[i][j] = 0;
									
								} else if (Sf[i][j] == 7) {
									Sf_journey[i][j] = 0;
								}
							}
						}
						show_field (Sf, m, n, gamemode, information_code, geben, Colored);
					}
				}
			}
			if ((gamemode == 5)||(gamemode == 8)) {
				if (journey == 1){
					if (((g-1)%15) == 14){
						printf (" \n");
						printf (" \n");
						printf ("	It is time for a journey... \n");
						printf (" \n");
						for (unsigned int i=1; i<m-1; i+=1){
							for (unsigned int j=1; j<n-1; j+=1){
								Sf[i][j] = Sf_journey[i][j];
								Sf_journey[i][j] = 0;
							}
						}
						show_field (Sf, m, n, gamemode, information_code, geben, Colored);
					}
				}
			}
			
			
			if (gamemode == 7) {
				if (journey == 1){
					if (((g-1)%(2*freq)) == (2*freq-1)){
						printf (" \n");
						printf (" \n");
						printf ("	It is time for a journey... \n");
						printf (" \n");
						for (unsigned int i=1; i<m-1; i+=1){
							for (unsigned int j=1; j<n-1; j+=1){
								if (Sf[i][j+1] != 7) {
									
									Sf[i][j+1] = Sf_journey[i][j];
									Sf_journey[i][j] = 0;
									
								} else if (Sf[i][j] == 7) {
									Sf_journey[i][j] = 0;
								}
							}
						}
						show_field (Sf, m, n, gamemode, information_code, geben, Colored);
					}
				}
			}
			
			if (gamemode == 7) {
				
				if (opague >= 1) {
					Sf_opague = opague_builder (Sf, m, n, (geben % 2)+1, opague, aop);	//possible to modify
				}
				
				if ((g-1)%freq == (freq-1)){
					count_freq += 1;
					if (count_freq == n-4){
						printf("	Both lost! \n");
						show_field (Sf, m, n, gamemode, information_code, geben, Colored);
						break;
					}
					printf("\n");
					printf("\n");
					printf("	It moved forward! \n");
					printf("\n");
					printf("\n");
					ahead (Sf, m, count_freq);
					
					if (opague >= 1) {
						show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
					} else {
						show_field (Sf, m, n, gamemode, information_code, geben, Colored);
					}
				}
				
				for (unsigned int i=1; i<(m-1); i+=1){
					if (Sf[i][n-3] == 1){
						A[0] += 1;
						break;
					} else if (Sf[i][n-3] == 2){
						B[0] += 1;
						break;
					}
				}
			}
			
			if (gamemode == 4) {
				if (((g-1)%turns_per_drop) == 1){
					for (unsigned int j=1; j<n-1; j+=1){
						if (Sf[m-2][j] == 7){
							if ((var_[1] == 1010)||(var_[2] == 1010)){
								if (fall_back == (n-1)/2){
									P[0] -= 1;
								} else if (fall_back < (n-1)/2){
									P[2] -= (((n-1)/2) - j);
								} else if (fall_back > (n-1)/2){
									P[1] -= (j - (n-1)/2);
								}
							}
							Sf[1][(n-1)/2] = 7;
							Sf[m-2][j] = 0;
							fall_controll = 1;
							
							printf ("\n");
							printf ("\n");
							printf ("\n");
							printf ("	It reached the ground!\n");
							printf ("\n");
							
							show_field (Sf, m, n, gamemode, information_code, geben, Colored);
							
							if (j == (n-1)/2){
								P[0] += 1;
								printf ("	It is an undecided #-square! \n");
							} else if (j < (n-1)/2){
								P[2] += ((n-1)/2) - j;
								printf ("	Points player 2:	+ %u \n", ((n-1)/2) - j);
							} else if (j > (n-1)/2){
								P[1] += (j - (n-1)/2);
								printf ("	Points player 1:	+ %u \n", (j - (n-1)/2));
							}
							fall_back = j;
							
							if (journey == 1){			//Übertragung		journey-Frequenz = fall-Frequenz
								for (unsigned int i=1; i<m-1; i+=1){
									for (unsigned int j=1; j<n-1; j+=1){
										if (Sf[i][j] != 7){
											Sf[i][j] = Sf_journey [i][j];
											Sf_journey[i][j] = 0;
										} else if (Sf[i][j] == 7) {
											Sf_journey[i][j] = 0;
										}
									}
								}
								printf ("\n");
								printf ("\n");
								printf ("\n");
								printf ("	It is time for a journey!\n");
								printf ("\n");
								show_field (Sf, m, n, gamemode, information_code, geben, Colored);
							}
							
							break;
						}
					}
				}
				
				if ((((g-1)%turns_per_drop) == 1)&&(fall_controll != 1)){
					for (unsigned int i=1; i<m-2; i+=1){
						for (unsigned int j=1; j<n-1; j+=1){
							if (Sf[i][j] == 7){
								Sf[i][j] = 0;
								if ((i+speed_of_fall) <= (m-2)) {
									for (unsigned int k=i; k<(i+speed_of_fall); k+=1) {
										Sf[k][j] = 0;
									}
									Sf[i+speed_of_fall][j] = 7;
								} else {
									Sf[m-2][j] = 7;
								}
								
								einmal = 1;
								printf ("\n");
								printf ("\n");
								printf ("\n");
								printf ("	It fell down!\n");
								printf ("\n");
								show_field (Sf, m, n, gamemode, information_code, geben, Colored);
								break;
							}
						}
						if (einmal == 1){
							break;
						}
					}
					einmal = 0;
				}
				fall_controll = 0;
				
				if ((var_[1] != 1010) && (var_[2] != 1010)){
					if (P[1] > P[2]){
						A[0] += 1;
					}
					if (P[1] < P[2]){
						B[0] += 1;
					}
				}
				
				if (P[1] >= points_for_win){		//Spiel-Ende
					printf ("	Sieg: player 1 \n");
					break;
				}
				if (P[2] >= points_for_win){
					printf ("	Sieg: player 2 \n");
					break;
				}
			}
			
			
			
			if ((gamemode == 1)||(gamemode == 2)||(gamemode == 4)||(gamemode == 5)||(gamemode == 7)) {
				for (unsigned int i=1; i<m-1; i+=1){
					for (unsigned int j=1; j<n-1; j+=1){
						if (Sf[i][j] == 2){
							ges[2] += 1;
						}
					}
				}
				if (ges[2] == 0){
					printf("	Sieg:	Spieler 1 \n");
						break;
				} else if ((ges[2]<5)&&(gamemode == 5)){
					B[0] += 1;
				}
				/*if (ges[2] > limit_at_all){	//test
					printf("too much\n");
				}*/
				ges[2] = 0;
				
				
				for (unsigned int i=1; i<m-1; i+=1){
					for (unsigned int j=1; j<n-1; j+=1){
						if (Sf[i][j] == 1){
							ges[1] += 1;
						}
					}
				}
				if (ges[1] == 0){
					printf("	Sieg:	Spieler 2 \n");
					break;
				} else if ((ges[1]<5)&&(gamemode == 5)){
					A[0] += 1;
				}
				/*if (ges[1] > limit_at_all){	//test
					printf("too much\n");
				}*/
				ges[1] = 0;
			}
			
			if (gamemode == 3) {
				for (unsigned int i=1; i<m-1; i+=1){
					for (unsigned int j=1; j<n-1; j+=1){
						if (Sf[i][j] == 2){
							ges[2] += 1;
						}
					}
				}
				if (ges[2] <= 5){
					B[0] += 1;
				}
				
				if (ges[2] == 0){
					printf("\n");
					printf("	Sieg:	Spieler 1 \n");
					show_field (Sf, m, n, gamemode, information_code, geben, Colored);
					break;
				}
				ges[2] = 0;
				
				
				for (unsigned int i=1; i<m-1; i+=1){
					for (unsigned int j=1; j<n-1; j+=1){
						if (Sf[i][j] == 1){
							ges[1] += 1;
						}
					}
				}
				if (ges[1] <= 5){
					A[0] += 1;
				}
				
				if (ges[1] == 0){
					printf("\n");
					printf("	Sieg:	Spieler 2 \n");
					show_field (Sf, m, n, gamemode, information_code, geben, Colored);
					break;
				}
				ges[1] = 0;
			}
			
			
			if (gamemode == 6) {
				unsigned int a;
				a = 0;
				for (unsigned int i=1; i<m-1; i+=1){
					for (unsigned int j=1; j<n-1; j+=1){
						if (Sf[i][j] == 11){
							
							printf("\n");
							
							if (Sf[i][j-1] > 1) {
								printf (" Sieg: Spieler %u \n", Sf[i][j-1]);
								a += 1;
							}
							if (Sf[i][j+1] > 1) {
								if (a == 0) {
									printf (" Sieg: Spieler %u \n", Sf[i][j+1]);
								}
								a += 1;
							}
							if (Sf[i-1][j] > 1) {
								if (a == 0) {
									printf (" Sieg: Spieler %u \n", Sf[i-1][j]);
								}
								a += 1;
							}
							if (Sf[i+1][j] > 1) {
								if (a == 0) {
									printf (" Sieg: Spieler %u \n", Sf[i+1][j]);
								}
								a += 1;
							}
							
							printf("\n");
							
							if (a == 2) {
								printf(" Double-catch! \n");
							}
							if (a == 3) {
								printf(" TRIPLE-catch!! \n");
							}
							if (a == 4) {
								printf(" QUADRO-CATCH!!! \n");
							}
							if (Sf[i+1][j+1] > 1) {
								if (Sf[i+1][j+1] == 2) {
									B[0] += 1;
								} else if (Sf[i+1][j+1] == 3) {
									AA[0] += 1;
								} else if (Sf[i+1][j+1] == 4) {
									BB[0] += 1;
								} else if (Sf[i+1][j+1] == 5) {
									AAA[0] += 1;
								} else if (Sf[i+1][j+1] == 6) {
									BBB[0] += 1;
								} else if (Sf[i+1][j+1] == 7) {
									AAAA[0] += 1;
								} else if (Sf[i+1][j+1] == 8) {
									BBBB[0] += 1;
								} else if (Sf[i+1][j+1] == 9) {
									AAAAA[0] += 1;
								}
							}
							if (Sf[i-1][j+1] > 1) {
								if (Sf[i-1][j+1] == 2) {
									B[0] += 1;
								} else if (Sf[i-1][j+1] == 3) {
									AA[0] += 1;
								} else if (Sf[i-1][j+1] == 4) {
									BB[0] += 1;
								} else if (Sf[i-1][j+1] == 5) {
									AAA[0] += 1;
								} else if (Sf[i-1][j+1] == 6) {
									BBB[0] += 1;
								} else if (Sf[i-1][j+1] == 7) {
									AAAA[0] += 1;
								} else if (Sf[i-1][j+1] == 8) {
									BBBB[0] += 1;
								} else if (Sf[i-1][j+1] == 9) {
									AAAAA[0] += 1;
								}
							}
							if (Sf[i+1][j-1] > 1) {
								if (Sf[i+1][j-1] == 2) {
									B[0] += 1;
								} else if (Sf[i+1][j-1] == 3) {
									AA[0] += 1;
								} else if (Sf[i+1][j-1] == 4) {
									BB[0] += 1;
								} else if (Sf[i+1][j-1] == 5) {
									AAA[0] += 1;
								} else if (Sf[i+1][j-1] == 6) {
									BBB[0] += 1;
								} else if (Sf[i+1][j-1] == 7) {
									AAAA[0] += 1;
								} else if (Sf[i+1][j-1] == 8) {
									BBBB[0] += 1;
								} else if (Sf[i+1][j-1] == 9) {
									AAAAA[0] += 1;
								}
							}
							if (Sf[i-1][j-1] > 1) {
								if (Sf[i-1][j-1] == 2) {
									B[0] += 1;
								} else if (Sf[i-1][j-1] == 3) {
									AA[0] += 1;
								} else if (Sf[i-1][j-1] == 4) {
									BB[0] += 1;
								} else if (Sf[i-1][j-1] == 5) {
									AAA[0] += 1;
								} else if (Sf[i-1][j-1] == 6) {
									BBB[0] += 1;
								} else if (Sf[i-1][j-1] == 7) {
									AAAA[0] += 1;
								} else if (Sf[i-1][j-1] == 8) {
									BBBB[0] += 1;
								} else if (Sf[i-1][j-1] == 9) {
									AAAAA[0] += 1;
								}
							}
							break;
						}
					}
					if (a > 0) {
						break;
					}
				}
				if (a > 0) {
					show_field (Sf, m, n, gamemode, information_code, geben, Colored);
					break;
				}
				
				a = 0;
				if ((round_counter == rtc)&&(geben == number_of_players)) {
					printf("	Sieg: Spieler 1");
					break;
				}
				
				for (unsigned int i=1; i<m-1; i+=1){
					for (unsigned int j=1; j<n-1; j+=1){
						for (unsigned int p=1; p<=number_of_players; p+=1) {
							if (Sf[i][j] == p) {
								ges[p] += 1;
								break;
							}
						} 
					}
				}
				if (ges[1] == 0) {
					printf("		Niederlage: Spieler 1 \n");
					break;
				}
				if ((ges[2] == 0)&&(number_of_players >= 2)) {
					printf("		Spieler 2, you are out. \n");
					player_counter += 1;
					ges[2] = 2020;
				}
				if ((ges[3] == 0)&&(number_of_players >= 3)) {
					printf("		Spieler 3, you are out. \n");
					player_counter += 1;
					ges[3] = 3030;
				}
				if ((ges[4] == 0)&&(number_of_players >= 4)) {
					printf("		Spieler 4, you are out. \n");
					player_counter += 1;
					ges[4] = 4040;
				}
				if ((ges[5] == 0)&&(number_of_players >= 5)) {
					printf("		Spieler 5, you are out. \n");
					player_counter += 1;
					ges[5] = 5050;
				}
				if ((ges[6] == 0)&&(number_of_players >= 6)) {
					printf("		Spieler 6, you are out. \n");
					player_counter += 1;
					ges[6] = 6060;
				}
				if ((ges[7] == 0)&&(number_of_players >= 7)) {
					printf("		Spieler 7, you are out. \n");
					player_counter += 1;
					ges[7] = 7070;
				}
				if ((ges[8] == 0)&&(number_of_players >= 8)) {
					printf("		Spieler 8, you are out. \n");
					player_counter += 1;
					ges[8] = 8080;
				}
				if ((ges[9] == 0)&&(number_of_players == 9)) {
					printf("		Spieler 9, you are out. \n");
					player_counter += 1;
					ges[9] = 9090;
				}
				
				ges[1] = 0;
				for (unsigned int p=2; p<=number_of_players; p+=1) {
					if (ges[p] < 1000) {
						ges[p] = 0;
					}
				} 
				
				if (player_counter == (number_of_players - 1)) {
					printf("		Game over. \n		Sieg: Spieler 1. \n");
					show_field (Sf, m, n, gamemode, information_code, geben, Colored);
					break;
				}
			}
			
			
			if (gamemode == 9) {
				for (unsigned int i=1; i<m-1; i+=1){
					for (unsigned int j=1; j<n-1; j+=1){
						for (unsigned int p=1; p<=number_of_players; p+=1) {
							if (Sf[i][j] == p) {
								ges[p] += 1;
								break;
							}
						}
					}
				}
				if ((ges[1] == 0)&&(number_of_players >= 1)) {
					printf("		Spieler 1, you are out. \n");
					player_counter += 1;
					ges[1] = 1010;
				}
				if ((ges[2] == 0)&&(number_of_players >= 2)) {
					printf("		Spieler 2, you are out. \n");
					player_counter += 1;
					ges[2] = 2020;
				}
				if ((ges[3] == 0)&&(number_of_players >= 3)) {
					printf("		Spieler 3, you are out. \n");
					player_counter += 1;
					ges[3] = 3030;
				}
				if ((ges[4] == 0)&&(number_of_players >= 4)) {
					printf("		Spieler 4, you are out. \n");
					player_counter += 1;
					ges[4] = 4040;
				}
				if ((ges[5] == 0)&&(number_of_players >= 5)) {
					printf("		Spieler 5, you are out. \n");
					player_counter += 1;
					ges[5] = 5050;
				}
				if ((ges[6] == 0)&&(number_of_players >= 6)) {
					printf("		Spieler 6, you are out. \n");
					player_counter += 1;
					ges[6] = 6060;
				}
				if ((ges[7] == 0)&&(number_of_players >= 7)) {
					printf("		Spieler 7, you are out. \n");
					player_counter += 1;
					ges[7] = 7070;
				}
				if ((ges[8] == 0)&&(number_of_players >= 8)) {
					printf("		Spieler 8, you are out. \n");
					player_counter += 1;
					ges[8] = 8080;
				}
				if ((ges[9] == 0)&&(number_of_players == 9)) {
					printf("		Spieler 9, you are out. \n");
					player_counter += 1;
					ges[9] = 9090;
				}
				
				if (player_counter == (number_of_players - 1)) {
					printf("		Game over, you can see the master of the arena. \n");
					show_field (Sf, m, n, gamemode, information_code, geben, Colored);
					break;
				}
				if (player_counter == number_of_players) {
					printf("		Game over, everybody died. \n");
					show_field (Sf, m, n, gamemode, information_code, geben, Colored);
					break;
				}
				
				if ((round_counter == rtp)&&(geben == number_of_players)) {
					printf(" \n ");
					printf("	Game over. \n ");
					printf(" \n ");
					for (unsigned int p=limit_at_all; p>0; p-=1) {
						for (unsigned int q=1; q<=number_of_players; q+=1) {
							if (ges[q] == p) {
								printf("	Spieler %u: %u \n", q, p);
							}
						}
						printf("\n");
						printf("\n");
					}
					break;
				}
				
				for (unsigned int p=1; p<=number_of_players; p+=1) {
					if (ges[p] < 1000) {
						ges[p] = 0;
					}
				}
				
			}		//lesezeichen
			
			if (gamemode == 10) {
				
				for (unsigned int i=1; i<m-1; i+=1){
					for (unsigned int j=1; j<n-1; j+=1){
						if ((Sf[i][j] == 1)&&(ges[1] < 1000)) {
							ges[1] += 1;
							if (ulcer_start[1] == 0) {
								ulcer_start[1] = 1;
							}
						} else if ((Sf[i][j] == 2)&&(ges[2] < 1000)) {
							ges[2] += 1;
							if (ulcer_start[2] == 0) {
								ulcer_start[2] = 1;
							}
						} else if ((Sf[i][j] == 3)&&(ges[3] < 1000)) {
							ges[3] += 1;
							if (ulcer_start[3] == 0) {
								ulcer_start[3] = 1;
							}
						} else if ((Sf[i][j] == 4)&&(ges[4] < 1000)) {
							ges[4] += 1;
							if (ulcer_start[4] == 0) {
								ulcer_start[4] = 1;
							}
						} else if ((Sf[i][j] == 5)&&(ges[5] < 1000)) {
							ges[5] += 1;
							if (ulcer_start[5] == 0) {
								ulcer_start[5] = 1;
							}
						} else if ((Sf[i][j] == 6)&&(ges[6] < 1000)) {
							ges[6] += 1;
							if (ulcer_start[6] == 0) {
								ulcer_start[6] = 1;
							}
						} else if ((Sf[i][j] == 7)&&(ges[7] < 1000)) {
							ges[7] += 1;
							if (ulcer_start[7] == 0) {
								ulcer_start[7] = 1;
							}
						} else if ((Sf[i][j] == 8)&&(ges[8] < 1000)) {
							ges[8] += 1;
							if (ulcer_start[8] == 0) {
								ulcer_start[8] = 1;
							}
						} else if ((Sf[i][j] == 9)&&(ges[9] < 1000)) {
							ges[9] += 1;
							if (ulcer_start[9] == 0) {
								ulcer_start[9] = 1;
							}
						}
					}
				}
				
				for (unsigned int p=1; p<=number_of_players; p+=1) {
					ges[0] += ges[p];
				}
				
				if ((ges[1] == 0)&&(ulcer_start[1] == 1)&&(geben == 1)) {
					ulcer_start[1] = 0;
					if (ulcer_lifes[1] > 0) {
						printf("		Spieler 1, you lost a life. \n");
						ulcer_lifes[1] -= 1;
					} else if (ulcer_start[0] == 0) {
						printf("		Niederlage: Spieler 1 \n");
						ulcer_start[0] = 100;
						break;
					} else if (ulcer_start[0] == 1) {
						printf("		Spieler 1, you are out. \n");
						player_counter += 1;
						ges[1] = 1010;
						
						for (unsigned int p=1; p<=number_of_players; p+=1) {
							if (out_counter[p] == 0) {
								out_counter[p] = 1;
								break;
							}
						}
					}
					
				}
				
				if ((ges[2] == 0)&&(number_of_players >= 2)&&(ulcer_start[2] == 1)&&(geben == 2)) {
					ulcer_start[2] = 0;
					if (ulcer_lifes[2] > 0) {
						printf("		Spieler 2, you lost a life. \n");
						ulcer_lifes[2] -= 1;
					} else {
						printf("		Spieler 2, you are out. \n");
						player_counter += 1;
						ges[2] = 2020;
						
						for (unsigned int p=1; p<=number_of_players; p+=1) {
							if (out_counter[p] == 0) {
								out_counter[p] = 2;
								break;
							}
						}
					}
				}
				if ((ges[3] == 0)&&(number_of_players >= 3)&&(ulcer_start[3] == 1)&&(geben == 3)) {
					ulcer_start[3] = 0;
					if (ulcer_lifes[3] > 0) {
						printf("		Spieler 3, you lost a life. \n");
						ulcer_lifes[3] -= 1;
					} else {
						printf("		Spieler 3, you are out. \n");
						player_counter += 1;
						ges[3] = 3030;
						
						for (unsigned int p=1; p<=number_of_players; p+=1) {
							if (out_counter[p] == 0) {
								out_counter[p] = 3;
								break;
							}
						}
					}
					
				}
				if ((ges[4] == 0)&&(number_of_players >= 4)&&(ulcer_start[4] == 1)&&(geben == 4)) {
					ulcer_start[4] = 0;
					if (ulcer_lifes[4] > 0) {
						printf("		Spieler 4, you lost a life. \n");
						ulcer_lifes[4] -= 1;
					} else {
						printf("		Spieler 4, you are out. \n");
						player_counter += 1;
						ges[4] = 4040;
						
						for (unsigned int p=1; p<=number_of_players; p+=1) {
							if (out_counter[p] == 0) {
								out_counter[p] = 4;
								break;
							}
						}
					}
					
				}
				if ((ges[5] == 0)&&(number_of_players >= 5)&&(ulcer_start[5] == 1)&&(geben == 5)) {
					ulcer_start[5] = 0;
					if (ulcer_lifes[5] > 0) {
						printf("		Spieler 5, you lost a life. \n");
						ulcer_lifes[5] -= 1;
					} else {
						printf("		Spieler 5, you are out. \n");
						player_counter += 1;
						ges[5] = 5050;
						
						for (unsigned int p=1; p<=number_of_players; p+=1) {
							if (out_counter[p] == 0) {
								out_counter[p] = 5;
								break;
							}
						}
					}
					
				}
				if ((ges[6] == 0)&&(number_of_players >= 6)&&(ulcer_start[6] == 1)&&(geben == 6)) {
					ulcer_start[6] = 0;
					if (ulcer_lifes[6] > 0) {
						printf("		Spieler 6, you lost a life. \n");
						ulcer_lifes[6] -= 1;
					} else {
						printf("		Spieler 6, you are out. \n");
						player_counter += 1;
						ges[6] = 6060;
						
						for (unsigned int p=1; p<=number_of_players; p+=1) {
							if (out_counter[p] == 0) {
								out_counter[p] = 6;
								break;
							}
						}
					}
				}
				if ((ges[7] == 0)&&(number_of_players >= 7)&&(ulcer_start[7] == 1)&&(geben == 7)) {
					ulcer_start[7] = 0;
					if (ulcer_lifes[7] > 0) {
						printf("		Spieler 7, you lost a life. \n");
						ulcer_lifes[7] -= 1;
					} else {
						printf("		Spieler 7, you are out. \n");
						player_counter += 1;
						ges[7] = 7070;
						
						for (unsigned int p=1; p<=number_of_players; p+=1) {
							if (out_counter[p] == 0) {
								out_counter[p] = 7;
								break;
							}
						}
					}
				}
				if ((ges[8] == 0)&&(number_of_players >= 8)&&(ulcer_start[8] == 1)&&(geben == 8)) {
					ulcer_start[8] = 0;
					if (ulcer_lifes[8] > 0) {
						printf("		Spieler 8, you lost a life. \n");
						ulcer_lifes[8] -= 1;
					} else {
						printf("		Spieler 8, you are out. \n");
						player_counter += 1;
						ges[8] = 8080;
						
						for (unsigned int p=1; p<=number_of_players; p+=1) {
							if (out_counter[p] == 0) {
								out_counter[p] = 8;
								break;
							}
						}
					}
				}
				if ((ges[9] == 0)&&(number_of_players == 9)&&(ulcer_start[9] == 1)&&(geben == 9)) {
					ulcer_start[9] = 0;
					if (ulcer_lifes[9] > 0) {
						printf("		Spieler 9, you lost a life. \n");
						ulcer_lifes[9] -= 1;
					} else {
						printf("		Spieler 9, you are out. \n");
						player_counter += 1;
						ges[9] = 9090;
						
						for (unsigned int p=1; p<=number_of_players; p+=1) {
							if (out_counter[p] == 0) {
								out_counter[p] = 9;
								break;
							}
						}
					}
				}
				
				if (player_counter == (number_of_players - 1)) {
					printf("		Game over, you can see the master of ulcer. \n");
					show_field (Sf, m, n, gamemode, information_code, geben, Colored);
					break;
				}
				if (player_counter == number_of_players) {
					printf("		Game over, everybody died. \n");
					show_field (Sf, m, n, gamemode, information_code, geben, Colored);
					break;
				}
				if ((geben == number_of_players)&&(rtp == round_counter)) {
					printf("\n");
					printf("	Congratulations Player 1, you are still alive!\n");
					printf("\n");
					break;
				}
				if (ges[0] == 0) {
					printf("		This game stucked. Try again! \n");
				}
				
				for (unsigned int p=0; p<=number_of_players; p+=1) {
					if (ges[p] < 1000) {
						ges[p] = 0;
					}
				}
				
				// ges-x in ges[x], done
			}
			
			if ((gamemode == 6)||(gamemode == 9)||(gamemode == 10)||(gamemode == 12)) {
				if (journey == 1){
					if (((10*number_of_players - 1) - ((g-1)%(10*number_of_players - 1))) == 1){
						printf (" \n");
						printf (" \n");
						printf ("	It is time for a journey... \n");
						printf (" \n");
						for (unsigned int i=1; i<m-1; i+=1){
							for (unsigned int j=1; j<n-1; j+=1){
								Sf[i][j] = Sf_journey[i][j];
								Sf_journey[i][j] = 0;
							}
						}
						show_field (Sf, m, n, gamemode, information_code, geben, Colored);
					}
				}
			}
			
			if (gamemode == 11) {
				
				if (journey == 1){
					if (((10*number_of_players - 1) - ((g-1)%(10*number_of_players - 1))) == 1){
						printf (" \n");
						printf (" \n");
						printf ("	It is time for a journey... \n");
						printf (" \n");
						for (unsigned int i=1; i<m-1; i+=1){
							for (unsigned int j=1; j<n-1; j+=1){
								if (Sf[i][j] != 77) {
									Sf[i][j] = Sf_journey[i][j];
									Sf_journey[i][j] = 0;
								} else {
									Sf[i][j] = 77;
								}
								
							}
						}
						show_field (Sf, m, n, gamemode, information_code, geben, Colored);
					}
				}
				
				for (unsigned int i=1; i<m-1; i+=1){
					for (unsigned int j=1; j<n-1; j+=1){
						for (unsigned int p=1; p<=number_of_players; p+=1) {
							if (Sf[i][j] == p) {
								ges[p] += 1;
								break;
							}
						}
					}
				}
				if ((ges[1] == 0)&&(number_of_players >= 1)) {
					printf("		Spieler 1, you are out. \n");
					player_counter += 1;
					ges[1] = 1010;
				}
				if ((ges[2] == 0)&&(number_of_players >= 2)) {
					printf("		Spieler 2, you are out. \n");
					player_counter += 1;
					ges[2] = 2020;
				}
				if ((ges[3] == 0)&&(number_of_players >= 3)) {
					printf("		Spieler 3, you are out. \n");
					player_counter += 1;
					ges[3] = 3030;
				}
				if ((ges[4] == 0)&&(number_of_players >= 4)) {
					printf("		Spieler 4, you are out. \n");
					player_counter += 1;
					ges[4] = 4040;
				}
				if ((ges[5] == 0)&&(number_of_players >= 5)) {
					printf("		Spieler 5, you are out. \n");
					player_counter += 1;
					ges[5] = 5050;
				}
				if ((ges[6] == 0)&&(number_of_players >= 6)) {
					printf("		Spieler 6, you are out. \n");
					player_counter += 1;
					ges[6] = 6060;
				}
				if ((ges[7] == 0)&&(number_of_players >= 7)) {
					printf("		Spieler 7, you are out. \n");
					player_counter += 1;
					ges[7] = 7070;
				}
				if ((ges[8] == 0)&&(number_of_players >= 8)) {
					printf("		Spieler 8, you are out. \n");
					player_counter += 1;
					ges[8] = 8080;
				}
				if ((ges[9] == 0)&&(number_of_players == 9)) {
					printf("		Spieler 9, you are out. \n");
					player_counter += 1;
					ges[9] = 9090;
				}
				
				if (number_of_players == 2) {
					if (player_counter == 1) {
						for (unsigned int t=1; t<=number_of_players; t+=1) {
							printf("\n");
							if (ges[t] != t*1010) {
								printf("	Sieg: Spieler %u \n", t);
							}
						}
						break;
					}
				} else if (number_of_players == 3) {
					if (player_counter == 2) {
						for (unsigned int t=1; t<=number_of_players; t+=1) {
							printf("\n");
							if (ges[t] != t*1010) {
								printf("	Sieg: Spieler %u \n", t);
							}
						}
						break;
					}
				} else if (number_of_players == 4) {
					if (player_counter == 3) {
						for (unsigned int t=1; t<=number_of_players; t+=1) {
							printf("\n");
							if (ges[t] != t*1010) {
								printf("	Sieg: Spieler %u \n", t);
							}
						}
						break;
					}
				} else if (number_of_players == 5) {
					if (player_counter == 4) {
						for (unsigned int t=1; t<=number_of_players; t+=1) {
							printf("\n");
							if (ges[t] != t*1010) {
								printf("	Sieg: Spieler %u \n", t);
							}
						}
						break;
					} else if ((player_counter == 3)&&(ges[4] != 4040)&&(ges[5] != 5050)) {
						for (unsigned int t=1; t<=number_of_players; t+=1) {
							printf("\n");
							if (ges[t] != t*1010) {
								printf("	Sieg: Spieler %u \n", t);
							}
						}
						break;
					}
				} else if (number_of_players == 6) {
					if (player_counter == 5) {
						for (unsigned int t=1; t<=number_of_players; t+=1) {
							printf("\n");
							if (ges[t] != t*1010) {
								printf("	Sieg: Spieler %u \n", t);
							}
						}
						break;
					} else if ((player_counter == 4)&&(((ges[2] != 2020)&&(ges[5] != 5050))||((ges[4] != 4040)&&(ges[1] != 1010))||((ges[3] != 3030)&&(ges[6] != 6060)))) {
						for (unsigned int t=1; t<=number_of_players; t+=1) {
							printf("\n");
							if (ges[t] != t*1010) {
								printf("	Sieg: Spieler %u \n", t);
							}
						}
						break;
					}
				} else if (number_of_players == 7) {
					if (player_counter == 6) {
						for (unsigned int t=1; t<=number_of_players; t+=1) {
							printf("\n");
							if (ges[t] != t*1010) {
								printf("	Sieg: Spieler %u \n", t);
							}
						}
						break;
					} else if ((player_counter == 5)&&(((ges[1] != 1010)&&(ges[5] != 5050))||((ges[4] != 4040)&&(ges[7] != 7070))||((ges[3] != 3030)&&(ges[6] != 6060)))) {
						for (unsigned int t=1; t<=number_of_players; t+=1) {
							printf("\n");
							if (ges[t] != t*1010) {
								printf("	Sieg: Spieler %u \n", t);
							}
						}
						break;
					}
				} else if (number_of_players == 8) {
					if (player_counter == 7) {
						for (unsigned int t=1; t<=number_of_players; t+=1) {
							printf("\n");
							if (ges[t] != t*1010) {
								printf("	Sieg: Spieler %u \n", t);
							}
						}
						break;
					} else if ((player_counter == 6)&&(((ges[1] != 1010)&&(ges[5] != 5050))||((ges[3] != 3030)&&(ges[7] != 7070))||((ges[2] != 2020)&&(ges[6] != 6060))||((ges[4] != 4040)&&(ges[8] != 8080)))) {
						for (unsigned int t=1; t<=number_of_players; t+=1) {
							printf("\n");
							if (ges[t] != t*1010) {
								printf("	Sieg: Spieler %u \n", t);
							}
						}
						break;
					}
				} else if (number_of_players == 9) {
					if (player_counter == 8) {
						for (unsigned int t=1; t<=number_of_players; t+=1) {
							printf("\n");
							if (ges[t] != t*1010) {
								printf("	Sieg: Spieler %u \n", t);
							}
						}
						break;
					} else if ((player_counter == 6)&&(((ges[1] != 1010)&&(ges[4] != 4040)&&(ges[7] != 7070))||((ges[3] != 3030)&&(ges[9] != 9090)&&(ges[6] != 6060))||((ges[2] != 2020)&&(ges[5] != 5050)&&(ges[8] != 8080)))) {
						for (unsigned int t=1; t<=number_of_players; t+=1) {
							printf("\n");
							if (ges[t] != t*1010) {
								printf("	Sieg: Spieler %u \n", t);
							}
						}
						break;
					} else if ((player_counter == 7)&&(((ges[1] != 1010)&&(ges[4] != 4040))||((ges[1] != 1010)&&(ges[7] != 7070))||((ges[4] != 4040)&&(ges[7] != 7070))||((ges[2] != 2020)&&(ges[5] != 5050))||((ges[2] != 2020)&&(ges[8] != 8080))||((ges[8] != 8080)&&(ges[5] != 5050))||((ges[3] != 3030)&&(ges[6] != 6060))||((ges[3] != 3030)&&(ges[9] != 9090))||((ges[6] != 6060)&&(ges[9] != 9090)))) {
						for (unsigned int t=1; t<=number_of_players; t+=1) {
							printf("\n");
							if (ges[t] != t*1010) {
								printf("	Sieg: Spieler %u \n", t);
							}
						}
						break;
					}
				}
				
				for (unsigned int p=1; p<=number_of_players; p+=1) {
					if (ges[p] < 1000) {
						ges[p] = 0;
					}
				}
				
			}
			
			if (gamemode == 12) {
				
				for (unsigned int i=1; i<m-1; i+=1){
					for (unsigned int j=1; j<n-1; j+=1){
						for (unsigned int p=1; p<=number_of_players; p+=1) {
							if (Sf[i][j] == p) {
								ges[p] += 1;
								break;
							}
						}
					}
				}
				if ((ges[1] == 0)&&(number_of_players >= 1)) {
					printf("		Spieler 1, you are out. \n");
					player_counter += 1;
					ges[1] = 1010;
				}
				if ((ges[2] == 0)&&(number_of_players >= 2)) {
					printf("		Spieler 2, you are out. \n");
					player_counter += 1;
					ges[2] = 2020;
				}
				if ((ges[3] == 0)&&(number_of_players >= 3)) {
					printf("		Spieler 3, you are out. \n");
					player_counter += 1;
					ges[3] = 3030;
				}
				if ((ges[4] == 0)&&(number_of_players >= 4)) {
					printf("		Spieler 4, you are out. \n");
					player_counter += 1;
					ges[4] = 4040;
				}
				if ((ges[5] == 0)&&(number_of_players >= 5)) {
					printf("		Spieler 5, you are out. \n");
					player_counter += 1;
					ges[5] = 5050;
				}
				if ((ges[6] == 0)&&(number_of_players >= 6)) {
					printf("		Spieler 6, you are out. \n");
					player_counter += 1;
					ges[6] = 6060;
				}
				if ((ges[7] == 0)&&(number_of_players >= 7)) {
					printf("		Spieler 7, you are out. \n");
					player_counter += 1;
					ges[7] = 7070;
				}
				if ((ges[8] == 0)&&(number_of_players >= 8)) {
					printf("		Spieler 8, you are out. \n");
					player_counter += 1;
					ges[8] = 8080;
				}
				if ((ges[9] == 0)&&(number_of_players == 9)) {
					printf("		Spieler 9, you are out. \n");
					player_counter += 1;
					ges[9] = 9090;
				}
				
				
				for (unsigned int p=1; p<=number_of_players; p+=1) {
					if (ges[p] < 1000) {
						ges[p] = 0;
					}
				}
				
			}
			
			if (player_counter == number_of_players) {	//Notbremse
				break;
			}
			
			g += 1;
		}
		//
		
		if (gamemode == 10) {
			if (ulcer_start[0] == 100) {
				for (unsigned int p=1; p<=number_of_players; p+=1) {
					if (out_counter[p] == 0) {
						out_counter[p] = 1;
						break;
					}
				}
			}
			ulcer_start[0] = 0;
			printf("	Who`s still alive? \n");
			
			for (unsigned int p=1; p<=number_of_players; p+=1) {
				for (unsigned int r=1; r<=number_of_players; r+=1) {
					if (out_counter[r] == p) {
						ulcer_lifes[p] = 1000;
						break;
					}
				}
				
				if (ulcer_lifes[p] != 1000) {
					printf("	Spieler %u \n", p);
				} else {
					ulcer_lifes[p] = 0;
				}
			}
			printf("\n");
			printf("\n");
			
			printf("	Top ulcer: \n");
			for (unsigned int p=1; p<=number_of_players; p+=1) {
				if (out_counter[1] == 0) {
					printf("		All were bad. \n");
					break;
				}
				
				if (out_counter[p] != 0) {
					if (out_counter[p] < number_of_players) {
						printf("		No.%u: %u \n", p-ulcer_start[0], out_counter[p]+1);
					} else {
						ulcer_start[0] = 1;
					}
				}
				
			}
			printf("\n");
			printf("\n");
			
			printf("	Lifes: \n");
			for (unsigned int p=1; p<=number_of_players; p+=1) {
				printf("		Spieler %u: %u life(s) left.\n", p, ulcer_lifes[p]);
			}
			printf("\n");
			printf("\n");
			
		}
		
		printf(" \n");
		printf("	Show Statistics:	yes: 1		no: 0 \n");
		scanf("%u", &lim);	
		
		if (lim == 1){
			printf("\n");
			printf("	Numbers of player 1: \n");
			printf("		#1 = %u \n", A[1]);
			printf("		#2 = %u \n", A[2]);
			printf("		#3 = %u \n", A[3]);
			printf("		#4 = %u \n", A[4]);
			printf("		#5 = %u \n", A[5]);
			printf("		#6 = %u \n", A[6]);
			printf("\n");
			if (number_of_players >= 2){
				printf("	Numbers of player 2: \n");
				printf("		#1 = %u \n", B[1]);
				printf("		#2 = %u \n", B[2]);
				printf("		#3 = %u \n", B[3]);
				printf("		#4 = %u \n", B[4]);
				printf("		#5 = %u \n", B[5]);
				printf("		#6 = %u \n", B[6]);
				printf("\n");
			}
			if (number_of_players >= 3){
				printf("	Numbers of player 3: \n");
				printf("		#1 = %u \n", AA[1]);
				printf("		#2 = %u \n", AA[2]);
				printf("		#3 = %u \n", AA[3]);
				printf("		#4 = %u \n", AA[4]);
				printf("		#5 = %u \n", AA[5]);
				printf("		#6 = %u \n", AA[6]);
				printf("\n");
			}
			if (number_of_players >= 4){
				printf("	Numbers of player 4: \n");
				printf("		#1 = %u \n", BB[1]);
				printf("		#2 = %u \n", BB[2]);
				printf("		#3 = %u \n", BB[3]);
				printf("		#4 = %u \n", BB[4]);
				printf("		#5 = %u \n", BB[5]);
				printf("		#6 = %u \n", BB[6]);
				printf("\n");
			}
			if (number_of_players >= 5){
				printf("	Numbers of player 5: \n");
				printf("		#1 = %u \n", AAA[1]);
				printf("		#2 = %u \n", AAA[2]);
				printf("		#3 = %u \n", AAA[3]);
				printf("		#4 = %u \n", AAA[4]);
				printf("		#5 = %u \n", AAA[5]);
				printf("		#6 = %u \n", AAA[6]);
				printf("\n");
			}
			if (number_of_players >= 6){
				printf("	Numbers of player 6: \n");
				printf("		#1 = %u \n", BBB[1]);
				printf("		#2 = %u \n", BBB[2]);
				printf("		#3 = %u \n", BBB[3]);
				printf("		#4 = %u \n", BBB[4]);
				printf("		#5 = %u \n", BBB[5]);
				printf("		#6 = %u \n", BBB[6]);
				printf("\n");
			}
			if (number_of_players >= 7){
				printf("	Numbers of player 7: \n");
				printf("		#1 = %u \n", AAAA[1]);
				printf("		#2 = %u \n", AAAA[2]);
				printf("		#3 = %u \n", AAAA[3]);
				printf("		#4 = %u \n", AAAA[4]);
				printf("		#5 = %u \n", AAAA[5]);
				printf("		#6 = %u \n", AAAA[6]);
				printf("\n");
			}
			if (number_of_players >= 8){
				printf("	Numbers of player 8: \n");
				printf("		#1 = %u \n", BBBB[1]);
				printf("		#2 = %u \n", BBBB[2]);
				printf("		#3 = %u \n", BBBB[3]);
				printf("		#4 = %u \n", BBBB[4]);
				printf("		#5 = %u \n", BBBB[5]);
				printf("		#6 = %u \n", BBBB[6]);
				printf("\n");
			}
			if (number_of_players >= 9){
				printf("	Numbers of player 9: \n");
				printf("		#1 = %u \n", AAAAA[1]);
				printf("		#2 = %u \n", AAAAA[2]);
				printf("		#3 = %u \n", AAAAA[3]);
				printf("		#4 = %u \n", AAAAA[4]);
				printf("		#5 = %u \n", AAAAA[5]);
				printf("		#6 = %u \n", AAAAA[6]);
				printf("\n");
			}
			
			if ((gamemode == 1)||(gamemode == 6)||(gamemode == 7)||(gamemode == 8)) {
				printf("	Matchballs player 1: 	%u \n", A[0]);
				printf("	Matchballs player 2: 	%u \n", B[0]);
				if (gamemode == 6) {
					if (number_of_players >= 3){printf("	Matchballs player 3: 	%u \n", AA[0]);}
					if (number_of_players >= 4){printf("	Matchballs player 4: 	%u \n", BB[0]);}
					if (number_of_players >= 5){printf("	Matchballs player 5: 	%u \n", AAA[0]);}
					if (number_of_players >= 6){printf("	Matchballs player 6: 	%u \n", BBB[0]);}
					if (number_of_players >= 7){printf("	Matchballs player 7: 	%u \n", AAAA[0]);}
					if (number_of_players >= 8){printf("	Matchballs player 8: 	%u \n", BBBB[0]);}
					if (number_of_players == 9){printf("	Matchballs player 9: 	%u \n", AAAAA[0]);}
				}
			} else if (gamemode == 2) {
				printf("	Squares collected by player 1: 	%u \n", A[0]);
				printf("	Squares collected by player 2: 	%u \n", B[0]);
			} else if (gamemode == 3) {
				printf("	Times with squares <= 5, player 1: 	%u \n", A[0]);
				printf("	Times with squares <= 5, player 2: 	%u \n", B[0]);
			} else if (gamemode == 4) {
				printf("	Points player 1: 		%u \n", P[1]);
				printf("	Points Player 2: 		%u \n", P[2]);
				printf("	Turns with more points player 1: 	%u \n", A[0]);
				printf("	Turns with more points player 2: 	%u \n", B[0]);
				printf("	Number of not decided #-squares: 	%u \n", P[0]);
			} else if (gamemode == 5) {
				printf("	Times with squares < 5, player 1: 	%u \n", A[0]);
				printf("	Times with squares < 5, player 2: 	%u \n", B[0]);
			} else if (gamemode == 9) {
				printf("	Number of excluded abilites: 	%u \n", exclude_counter);
				printf("	Offensive abilities taken: 	%u \n", number_of_players-ability[0]);
				printf("	Defensive abilities taken: 	%u \n", ability[0]);
			} else if (gamemode == 10) {
				for (unsigned int p=1; p<=number_of_players; p+=1) {
					printf("		Spieler %u: %u life(s) left.\n", p, ulcer_lifes[p]);
				}
			} else if (gamemode == 11) {	//mehr-gamemode
				for (unsigned int p=1; p<=number_of_players; p+=1) {
					if ((ges[p] > 1000)||(ges[p] == 0)) {
						printf("	Spieler %u: is out.\n", p);
					} else if (ges[p] < 1000) {
						printf("	Spieler %u: You own %u squares.\n", p, ges[p]);
					}
				}
			} else if (gamemode == 12) {
				for (unsigned int p=1; p<=number_of_players; p+=1) {
					if ((ges[p] > 1000)||(ges[p] == 0)) {
						printf("	Spieler %u: is out.\n", p);
					} else if (ges[p] < 1000) {
						printf("	Spieler %u: You own %u squares.\n", p, ges[p]);
					}
				}
			}
			
			if (ttt != 0) {
				printf("	Number of penalties given until	now: %u \n", pere[0]);
			}
		}
		
		if (gamemode == 6) {
			for (unsigned int p=0; p <= 3; p+=1) {
				information_code[p] = 1;
			}
		}
		
		printf("\n");
		printf("	Round: %u \n", round_counter);
		printf("\n");
		
		show_field (Sf, m, n, gamemode, information_code, geben, Colored);
		
		printf("	\n ");
		printf("	\n ");
		printf("	Do you want to play another match?	\n		Yes: 1		No:  0 ");
		scanf ("%u", &playtime);
		if (playtime == 0) {
			printf("				     ___ \n ");
		}
		
		if (playtime > 1) {
			printf("	it was a -1-, wasn't it?");
		}
		if (playtime >= 1) {
			playtime = 10;
			
			printf(" \n ");
			printf(" \n ");
			
			printf("	Do you want to play a revenge? \n ");
			printf("	yes: 1		No: 0 \n ");
			scanf("%u", &same[0]);
			
			if (same[0] > 1) {
				printf("	it was a -1-, wasn't it?");
				same[0] = 1;
				
			}
			if (same[0] == 1) {
				same[23] = use_number;
			}
			printf("	\n ");
			printf("	\n ");
			printf("	\n ");
			printf("	\n ");
			
		}
		
	}
	
	return 0;
}

Spielfeld Spielfeld_Create (unsigned int m, unsigned int n) {		//calloc in malloc geändert und zurückgenommen (16.06.2018),
	Spielfeld Sf;
	Sf = calloc(m, sizeof(unsigned int*));
	for (unsigned int i=0; i<m; i+=1) {
		Sf[i] = calloc(n, sizeof(unsigned int));
	}
	return Sf;
}

unsigned int* unsigned_int_Vektor_Create (unsigned int length) {
	unsigned int* Vektor;
	Vektor = calloc(length, sizeof(unsigned int));
	
	return Vektor;
}

int* int_Vektor_Create (unsigned int length) {
	int* Vektor;
	Vektor = calloc(length, sizeof(int));
	
	return Vektor;
}

void Spielfeld_Destroy (Spielfeld Spiel, unsigned int m){
	for (unsigned int i=1; i<m-1; i+=1){
		free((Spiel[i]));
		(Spiel[i]) = NULL;
	}
	free(Spiel);
	Spiel = NULL;		//nach testen auf andere Versionen übertragen!
}

Spielfeld start_normal (Spielfeld Sf, unsigned int m, unsigned int n, unsigned int gamemode, unsigned int number_of_players){
	
	
	if (gamemode == 1){
		unsigned int n_2;
		n_2 = n/2;
		
		Sf[1][n_2-1] 	= 1;		//Spieler 1
		Sf[1][n_2+1] 	= 1;
		Sf[2][n_2-1]	= 1;
		Sf[2][n_2]		= 1;
		Sf[3][n_2]		= 1;
		
		
		//Sf[8][3] = 2;	Sf[9][3] = 2;	//Test
		//Sf[8][4] = 2;	Sf[9][6] = 2;
		//Sf[8][5] = 2;	Sf[10][3] = 2;
		//Sf[8][6] = 2;	Sf[10][4] = 2;
		
		
		Sf[m-2][n_2-2] 	= 2;		//Spieler 2
		Sf[m-2][n_2] 	= 2;
		Sf[m-3][n_2]	= 2;
		Sf[m-3][n_2-1] 	= 2;
		Sf[m-4][n_2-1]	= 2;
		
	} else if (gamemode == 2){
		unsigned int n_2;
		n_2 = (n-1)/2;
		
		Sf[1][n_2-1] 	= 1;		//Spieler 1
		Sf[1][n_2+1] 	= 1;
		Sf[2][n_2-1]	= 1;
		Sf[2][n_2]		= 1;
		Sf[3][n_2]		= 1;
		
		
		//Sf[9][1] = 1;	Sf[8][5] = 1;	//Test
		//Sf[8][5] = 1;	Sf[8][6] = 1;
		//Sf[2][1] = 2;	Sf[5][2] = 1;
		//Sf[5][5] = 1;	Sf[5][6] = 1;
		
		
		Sf[m-2][n_2-1] 	= 2;		//Spieler 2
		Sf[m-2][n_2+1] 	= 2;
		Sf[m-3][n_2]	= 2;
		Sf[m-3][n_2+1] 	= 2;
		Sf[m-4][n_2]	= 2;
		
		
		Sf[(m-1)/2][2] 		= 7;		//to collect
		Sf[(m-1)/2][n-3] 	= 7;
		Sf[(m-1)/2][n_2]	= 7;
		
	} else if (gamemode == 3){
		unsigned int n_2;
		n_2 = n/2;
		
		Sf[1][n_2-1] 	= 1;		//Spieler 1
		Sf[1][n_2+1] 	= 1;
		Sf[2][n_2-1]	= 1;
		Sf[2][n_2]		= 1;
		Sf[3][n_2]		= 1;
		
		Sf[1][2] = 1;
		Sf[2][2] = 1;
		Sf[2][1] = 1;
		Sf[1][n-3] = 1;
		Sf[2][n-2] = 1;
		Sf[2][n-3] = 1;
		
		//Sf[9][1] = 1;	Sf[8][5] = 1;	//Test
		//Sf[8][5] = 1;	Sf[8][6] = 1;
		//Sf[2][1] = 2;	Sf[5][2] = 1;
		//Sf[5][5] = 1;	Sf[5][6] = 1;
		
		
		Sf[m-2][n_2-2] 	= 2;		//Spieler 2
		Sf[m-2][n_2] 	= 2;
		Sf[m-3][n_2]	= 2;
		Sf[m-3][n_2-1] 	= 2;
		Sf[m-4][n_2-1]	= 2;
		
		Sf[m-2][2] = 2;
		Sf[m-3][2] = 2;
		Sf[m-3][1] = 2;
		Sf[m-3][n-3] = 2;
		Sf[m-3][n-2] = 2;
		Sf[m-2][n-3] = 2;
		
	} else if (gamemode == 4){
		Sf[m-2][1] 	= 1;		//Spieler 1
		Sf[m-2][3] 	= 1;
		Sf[m-3][2]	= 1;
		Sf[m-3][3]	= 1;
		Sf[m-4][2]	= 1;
		
		
		//Sf[9][1] = 1;	Sf[8][5] = 1;	//Test
		//Sf[8][5] = 1;	Sf[8][6] = 1;
		//Sf[2][1] = 2;	Sf[5][2] = 1;
		//Sf[5][5] = 1;	Sf[5][6] = 1;
		
		
		Sf[m-2][n-2] 	= 2;		//Spieler 2
		Sf[m-2][n-4] 	= 2;
		Sf[m-3][n-3]	= 2;
		Sf[m-3][n-4] 	= 2;
		Sf[m-4][n-3]	= 2;
		
		Sf[1][(n-1)/2] = 7;
		
	} else if (gamemode == 5){
		unsigned int n_2;
		n_2 = n/2;
		
		Sf[1][n_2-1] 	= 1;		//Spieler 1
		Sf[1][n_2+1] 	= 1;
		Sf[2][n_2-1]	= 1;
		Sf[2][n_2]		= 1;
		Sf[3][n_2]		= 1;
		
		
		//Sf[9][1] = 1;	Sf[8][5] = 1;	//Test
		//Sf[8][5] = 1;	Sf[8][6] = 1;
		//Sf[2][1] = 2;	Sf[5][2] = 1;
		//Sf[5][5] = 1;	Sf[5][6] = 1;
		
		
		Sf[m-2][n_2-2] 	= 2;		//Spieler 2
		Sf[m-2][n_2] 	= 2;
		Sf[m-3][n_2]	= 2;
		Sf[m-3][n_2-1] 	= 2;
		Sf[m-4][n_2-1]	= 2;
		
	} else if (gamemode == 6){
		if (number_of_players == 2) {
			unsigned int m_2;
			m_2 = (m-1)/2;
			
			Sf[m_2-1][3] = 1;		//Spieler 1
			Sf[m_2][2] 	 = 1;
			Sf[m_2][3]	 = 11;
			Sf[m_2][4]	 = 1;
			Sf[m_2+1][3] = 1;
			
			Sf[m_2-1][n-2]	= 2;		//Spieler 2
			Sf[m_2][n-3]	= 2;
			Sf[m_2][n-4]	= 2;
			Sf[m_2+1][n-3]	= 2;
			Sf[m_2+1][n-2]	= 2;
			
		} else if (number_of_players == 3) {
			unsigned int m_2, n_2;
			m_2 = (m-1)/2;
			n_2 = (n-1)/2;
			
			Sf[m_2-1][n_2]	= 1;		//Spieler 1
			Sf[m_2][n_2-1] 	= 1;
			Sf[m_2][n_2]	= 11;
			Sf[m_2][n_2+1]	= 1;
			Sf[m_2+1][n_2]	= 1;
			
			Sf[m_2-1][n-2]	= 2;		//Spieler 2
			Sf[m_2][n-3]	= 2;
			Sf[m_2][n-4]	= 2;
			Sf[m_2+1][n-3]	= 2;
			Sf[m_2+1][n-2]	= 2;
			
			Sf[m_2-1][1] = 3;		//Spieler 3
			Sf[m_2-1][2] = 3;
			Sf[m_2][2]	 = 3;
			Sf[m_2][3]	 = 3;
			Sf[m_2+1][1] = 3;
			
		} else if (number_of_players == 4) {
			unsigned int m_2, n_2;
			m_2 = (m-1)/2;
			n_2 = (n-1)/2;
			
			Sf[m_2-2][n_2]	 = 1;		//Spieler 1
			Sf[m_2-1][n_2-1] = 1;
			Sf[m_2-1][n_2]	 = 11;
			Sf[m_2-1][n_2+1] = 1;
			Sf[m_2][n_2]	 = 1;
			
			Sf[m-2][n_2-1]	= 2;		//Spieler 2
			Sf[m-2][n_2+1]	= 2;
			Sf[m-3][n_2]	= 2;
			Sf[m-3][n_2+1]	= 2;
			Sf[m-4][n_2]	= 2;
			
			Sf[1][n-2]	= 3;		//Spieler 3
			Sf[2][n-3]	= 3;
			Sf[2][n-4]	= 3;
			Sf[3][n-2]	= 3;
			Sf[3][n-3]	= 3;
			
			Sf[1][1] = 4;		//Spieler 4
			Sf[2][2] = 4;
			Sf[2][3] = 4;
			Sf[3][1] = 4;
			Sf[3][2] = 4;
			
		} else if (number_of_players == 5) {
			unsigned int m_2, n_2;
			m_2 = (m-1)/2;
			n_2 = (n-1)/2;
			
			Sf[m_2-1][n_2]	= 1;		//Spieler 1
			Sf[m_2][n_2-1]	= 1;
			Sf[m_2][n_2]	= 11;
			Sf[m_2][n_2+1]	= 1;
			Sf[m_2+1][n_2]	= 1;
			
			Sf[m-2][n-2] = 2;		//Spieler 2
			Sf[m-4][n-2] = 2;
			Sf[m-3][n-3] = 2;
			Sf[m-3][n-4] = 2;
			Sf[m-4][n-3] = 2;
			
			Sf[1][n-2]	= 3;		//Spieler 3
			Sf[2][n-3]	= 3;
			Sf[2][n-4]	= 3;
			Sf[1][n-4]	= 3;
			Sf[3][n-3]	= 3;
			
			Sf[1][1] = 4;		//Spieler 4
			Sf[2][2] = 4;
			Sf[2][3] = 4;
			Sf[3][1] = 4;
			Sf[3][2] = 4;
			
			Sf[m-2][1] = 5;		//Spieler 5
			Sf[m-3][2] = 5;
			Sf[m-3][3] = 5;
			Sf[m-4][2] = 5;
			Sf[m-2][3] = 5;
			
		} else if (number_of_players == 6) {
			unsigned int m_2, nn;
			m_2 = (m-1)/2;
			nn = (n-4)/2;
			
			Sf[m_2-1][nn]	= 1;		//Spieler 1
			Sf[m_2][nn-1]	= 1;
			Sf[m_2][nn]		= 11;
			Sf[m_2][nn+1]	= 1;
			Sf[m_2+1][nn]	= 1;
			
			Sf[m_2-1][n-2]	= 2;		//Spieler 2
			Sf[m_2-1][n-3]	= 2;
			Sf[m_2][n-3]	= 2;
			Sf[m_2][n-4]	= 2;
			Sf[m_2+1][n-2]	= 2;
			
			Sf[1][n-8]	= 3;		//Spieler 3
			Sf[2][n-8]	= 3;
			Sf[2][n-7]	= 3;
			Sf[1][n-6]	= 3;
			Sf[3][n-7]	= 3;
			
			Sf[1][1] = 4;		//Spieler 4
			Sf[2][2] = 4;
			Sf[2][3] = 4;
			Sf[1][3] = 4;
			Sf[3][2] = 4;
			
			Sf[m-2][1] = 5;		//Spieler 5
			Sf[m-3][2] = 5;
			Sf[m-3][3] = 5;
			Sf[m-4][2] = 5;
			Sf[m-2][3] = 5;
			
			Sf[m-2][n-8] = 6;		//Spieler 6
			Sf[m-3][n-8] = 6;
			Sf[m-3][n-7] = 6;
			Sf[m-4][n-7] = 6;
			Sf[m-2][n-6] = 6;
			
		} else if (number_of_players == 7) {
			unsigned int m_2, n_2;
			m_2 = (m-1)/2;
			n_2 = (n-1)/2;
			
			Sf[m_2-1][n_2]	= 1;		//Spieler 1
			Sf[m_2][n_2-1]	= 1;
			Sf[m_2][n_2]	= 11;
			Sf[m_2][n_2+1]	= 1;
			Sf[m_2+1][n_2]	= 1;
			
			Sf[m_2-1][n-2]	= 2;		//Spieler 2
			Sf[m_2-1][n-3]	= 2;
			Sf[m_2][n-3]	= 2;
			Sf[m_2][n-4]	= 2;
			Sf[m_2+1][n-2]	= 2;
			
			Sf[1][n-7]	= 3;		//Spieler 3
			Sf[2][n-7]	= 3;
			Sf[2][n-6]	= 3;
			Sf[1][n-5]	= 3;
			Sf[3][n-6]	= 3;
			
			Sf[1][4] = 4;		//Spieler 4
			Sf[2][5] = 4;
			Sf[2][6] = 4;
			Sf[1][6] = 4;
			Sf[3][5] = 4;
			
			Sf[m_2-1][1] = 5;		//Spieler 5
			Sf[m_2][2]	 = 5;
			Sf[m_2][3]	 = 5;
			Sf[m_2+1][2] = 5;
			Sf[m_2+1][1] = 5;
			
			Sf[m-2][4] = 6;		//Spieler 6
			Sf[m-3][5] = 6;
			Sf[m-3][6] = 6;
			Sf[m-4][5] = 6;
			Sf[m-2][6] = 6;
			
			Sf[m-2][n-7] = 7;		//Spieler 7
			Sf[m-3][n-7] = 7;
			Sf[m-3][n-6] = 7;
			Sf[m-4][n-6] = 7;
			Sf[m-2][n-5] = 7;
			
		} else if (number_of_players == 8) {
			unsigned int m_2, n_2;
			m_2 = (m-2)/2;
			n_2 = (n-1)/2;
			
			Sf[m_2-1][n_2]	= 1;		//Spieler 1
			Sf[m_2][n_2-1]	= 1;
			Sf[m_2][n_2]	= 11;
			Sf[m_2][n_2+1]	= 1;
			Sf[m_2+1][n_2]	= 1;
			
			Sf[m_2-1][n-2]	= 2;		//Spieler 2
			Sf[m_2-1][n-3]	= 2;
			Sf[m_2][n-3]	= 2;
			Sf[m_2][n-4]	= 2;
			Sf[m_2+1][n-2]	= 2;
			
			Sf[1][n-8]	= 3;		//Spieler 3
			Sf[2][n-8]	= 3;
			Sf[2][n-7]	= 3;
			Sf[1][n-6]	= 3;
			Sf[3][n-7]	= 3;
			
			Sf[1][5] = 4;		//Spieler 4
			Sf[2][6] = 4;
			Sf[2][7] = 4;
			Sf[1][7] = 4;
			Sf[3][6] = 4;
			
			Sf[m_2-1][1] = 5;		//Spieler 5
			Sf[m_2][2]	 = 5;
			Sf[m_2][3]	 = 5;
			Sf[m_2-1][2] = 5;
			Sf[m_2+1][1] = 5;
			
			Sf[m-4][3] = 6;		//Spieler 6
			Sf[m-5][4] = 6;
			Sf[m-5][5] = 6;
			Sf[m-6][4] = 6;
			Sf[m-4][5] = 6;
			
			Sf[m-2][n_2]	= 7;		//Spieler 7
			Sf[m-3][n_2-1]	= 7;
			Sf[m-3][n_2]	= 7;
			Sf[m-3][n_2+1]	= 7;
			
			Sf[m-4][n-6] = 8;		//Spieler 8
			Sf[m-5][n-6] = 8;
			Sf[m-5][n-5] = 8;
			Sf[m-6][n-5] = 8;
			Sf[m-4][n-4] = 8;
			
		} else if (number_of_players == 9) {
			unsigned int m_2, n_2;
			m_2 = (m-1)/2;
			n_2 = (n-1)/2;
			
			Sf[m_2-1][n_2]	= 1;		//Spieler 1
			Sf[m_2][n_2-1]	= 1;
			Sf[m_2][n_2]	= 11;
			Sf[m_2][n_2+1]	= 1;
			Sf[m_2+1][n_2]	= 1;
			
			Sf[m_2-1][n-3]	= 2;		//Spieler 2
			Sf[m_2][n-2]	= 2;
			Sf[m_2][n-3]	= 2;
			Sf[m_2+1][n-3]	= 2;
			
			Sf[2][n-3]	= 3;		//Spieler 3
			Sf[2][n-5]	= 3;
			Sf[3][n-5]	= 3;
			Sf[4][n-5]	= 3;
			Sf[4][n-4]	= 3;
			Sf[4][n-3]	= 3;
			
			Sf[1][n_2]	 = 4;		//Spieler 4
			Sf[2][n_2-1] = 4;
			Sf[2][n_2]	 = 4;
			Sf[2][n_2+1] = 4;
			
			Sf[2][2] = 5;		//Spieler 5
			Sf[2][4] = 5;
			Sf[3][4] = 5;
			Sf[4][4] = 5;
			Sf[4][3] = 5;
			Sf[4][2] = 5;
			
			Sf[m_2-1][2] = 6;		//Spieler 6
			Sf[m_2][1]	 = 6;
			Sf[m_2][2]	 = 6;
			Sf[m_2+1][2] = 6;
			
			Sf[m-3][2] = 7;		//Spieler 7
			Sf[m-3][4] = 7;
			Sf[m-4][4] = 7;
			Sf[m-5][4] = 7;
			Sf[m-5][3] = 7;
			Sf[m-5][2] = 7;
			
			Sf[m-2][n_2]	= 8;		//Spieler 8
			Sf[m-3][n_2-1]	= 8;
			Sf[m-3][n_2]	= 8;
			Sf[m-3][n_2+1]	= 8;
			
			Sf[m-3][n-3] = 9;		//Spieler 9
			Sf[m-5][n-3] = 9;
			Sf[m-5][n-4] = 9;
			Sf[m-5][n-5] = 9;
			Sf[m-4][n-5] = 9;
			Sf[m-3][n-5] = 9;
			
		}
		
	} else if (gamemode == 7){
		Sf[1][2] 	= 1;		//Spieler 1
		Sf[2][3] 	= 1;
		Sf[2][4]	= 1;
		Sf[3][2]	= 1;
		Sf[3][3]	= 1;
		
		
		//Sf[9][1] = 1;	Sf[8][5] = 1;	//Test
		//Sf[8][5] = 1;	Sf[8][6] = 1;
		//Sf[2][1] = 2;	Sf[5][2] = 1;
		//Sf[5][5] = 1;	Sf[5][6] = 1;
		
		
		Sf[m-2][2] 	= 2;		//Spieler 2
		Sf[m-3][3] 	= 2;
		Sf[m-3][4]	= 2;
		Sf[m-4][2] 	= 2;
		Sf[m-4][3]	= 2;
		
		for (unsigned int i=1; i<m-1; i+=1){
			Sf[i][1] = 7;
		}
		Sf[(m-1)/2][n-2] = 7;
		
	} else if (gamemode == 8){
		Sf[m-2][1] 	= 1;		//Spieler 1
		Sf[m-2][3] 	= 1;
		Sf[m-3][2]	= 1;
		Sf[m-3][3]	= 1;
		Sf[m-4][2]	= 1;
		
		
		//Sf[4][10] = 2;	Sf[5][10] = 2;	//Test
		//Sf[4][11] = 2;	Sf[5][13] = 2;
		//Sf[4][12] = 2;	Sf[6][10] = 2;
		//Sf[4][13] = 2;	Sf[6][11] = 2;
		
		
		Sf[m-2][n-2] 	= 2;		//Spieler 2
		Sf[m-2][n-4] 	= 2;
		Sf[m-3][n-3]	= 2;
		Sf[m-3][n-4] 	= 2;
		Sf[m-4][n-3]	= 2;
		
		//Sf[1][(n-1)/2] = 7;
		
	} else if (gamemode == 9){
		if (number_of_players == 2) {
			unsigned int m_2;
			m_2 = (m-1)/2;
			
			Sf[m_2-1][1] = 1;		//Spieler 1
			Sf[m_2][2]	 = 1;
			Sf[m_2][3]	 = 1;
			Sf[m_2+1][1] = 1;
			Sf[m_2+1][2] = 1;
			
			Sf[m_2+1][n-2]	= 2;		//Spieler 2
			Sf[m_2][n-3] 	= 2;
			Sf[m_2][n-4] 	= 2;
			Sf[m_2-1][n-2] 	= 2;
			Sf[m_2-1][n-3] 	= 2;
			
		} else if (number_of_players == 3) {
			
			Sf[2][3] = 1;		//Spieler 1
			Sf[3][2] = 1;
			Sf[3][3] = 1;
			Sf[3][4] = 1;
			Sf[4][3] = 1;
			
			Sf[3][n-2] = 2;		//Spieler 2
			Sf[4][n-3] = 2;
			Sf[4][n-4] = 2;
			Sf[5][n-3] = 2;
			Sf[5][n-2] = 2;
			
			Sf[m-4][4] = 3;		//Spieler 3
			Sf[m-3][4] = 3;
			Sf[m-3][5] = 3;
			Sf[m-2][3] = 3;
			Sf[m-2][5] = 3;
			
		} else if (number_of_players == 4) {
			unsigned int m_2, n_2;
			m_2 = (m-1)/2;
			n_2 = (n-1)/2;
			
			Sf[m-2][n_2+1]	 = 1;		//Spieler 1
			Sf[m-2][n_2-1]	 = 1;
			Sf[m-3][n_2]	 = 1;
			Sf[m-3][n_2+1]	 = 1;
			Sf[m-4][n_2]	 = 1;
			
			Sf[1][n_2-1]	= 2;		//Spieler 2
			Sf[1][n_2+1]	= 2;
			Sf[2][n_2]		= 2;
			Sf[2][n_2-1]	= 2;
			Sf[3][n_2]		= 2;
			
			Sf[m_2-1][1]	= 3;		//Spieler 3
			Sf[m_2+1][1]	= 3;
			Sf[m_2+1][2]	= 3;
			Sf[m_2][2]		= 3;
			Sf[m_2][3]		= 3;
			
			Sf[m_2-1][n-2]	= 4;		//Spieler 4
			Sf[m_2+1][n-2]	= 4;
			Sf[m_2-1][n-3]	= 4;
			Sf[m_2][n-3]	= 4;
			Sf[m_2][n-4]	= 4;
			
		} else if (number_of_players == 5) {
			unsigned int mm, nn;
			mm = m/2;
			nn = n/2;
			
			Sf[m-2][nn+1]	 = 1;		//Spieler 1
			Sf[m-2][nn-1]	 = 1;
			Sf[m-3][nn] 	 = 1;
			Sf[m-3][nn+1]	 = 1;
			Sf[m-4][nn] 	 = 1;
			
			Sf[1][nn]	= 2;		//Spieler 2
			Sf[1][nn-2]	= 2;
			Sf[2][nn-2]	= 2;
			Sf[2][nn-1]	= 2;
			Sf[3][nn-1]	= 2;
			
			Sf[mm+1][1]	= 3;		//Spieler 3
			Sf[mm-1][1]	= 3;
			Sf[mm][2]	= 3;
			Sf[mm+1][2]	= 3;
			Sf[mm][3]	= 3;
			
			Sf[mm][n-2]		= 4;		//Spieler 4
			Sf[mm-2][n-2]	= 4;
			Sf[mm-1][n-3]	= 4;
			Sf[mm-2][n-3]	= 4;
			Sf[mm-1][n-4]	= 4;
			
			Sf[mm-2][nn-2] 	= 5;		//Spieler 5
			Sf[mm-2][nn+1] 	= 5;
			Sf[mm-1][nn-1] 	= 5;
			Sf[mm-1][nn]	= 5;
			Sf[mm][nn-1] 	= 5;
			Sf[mm][nn] 		= 5;
			Sf[mm+1][nn-2] 	= 5;
			Sf[mm+1][nn+1] 	= 5;
			
		} else if (number_of_players == 6) {
			unsigned int m_2;
			m_2 = (m-1)/2;
			
			Sf[m_2-1][1]	= 1;		//Spieler 1
			Sf[m_2-1][2]	= 1;
			Sf[m_2][2]		= 1;
			Sf[m_2][3]		= 1;
			Sf[m_2+1][1]	= 1;
			
			Sf[m_2-1][n-2]	= 2;		//Spieler 2
			Sf[m_2+1][n-3]	= 2;
			Sf[m_2][n-3]	= 2;
			Sf[m_2][n-4]	= 2;
			Sf[m_2+1][n-2]	= 2;
			
			Sf[1][n-5]	= 3;		//Spieler 3
			Sf[2][n-5]	= 3;
			Sf[2][n-6]	= 3;
			Sf[1][n-7]	= 3;
			Sf[3][n-6]	= 3;
			
			Sf[1][4] = 4;		//Spieler 4
			Sf[2][5] = 4;
			Sf[2][6] = 4;
			Sf[1][6] = 4;
			Sf[3][5] = 4;
			
			Sf[m-2][4] = 5;		//Spieler 5
			Sf[m-3][4] = 5;
			Sf[m-3][5] = 5;
			Sf[m-4][5] = 5;
			Sf[m-2][6] = 5;
			
			Sf[m-2][n-5] = 6;		//Spieler 6
			Sf[m-3][n-6] = 6;
			Sf[m-3][n-7] = 6;
			Sf[m-4][n-6] = 6;
			Sf[m-2][n-7] = 6;
			
		} else if (number_of_players == 7) {
			unsigned int mm, nn;
			mm = m/2;
			nn = n/2;
			
			Sf[mm-1][1]	= 1;		//Spieler 1
			Sf[mm-1][2]	= 1;
			Sf[mm][2]	= 1;
			Sf[mm][3]	= 1;
			Sf[mm+1][1]	= 1;
			
			Sf[mm-2][n-2]	= 2;		//Spieler 2
			Sf[mm][n-3]		= 2;
			Sf[mm-1][n-3]	= 2;
			Sf[mm-1][n-4]	= 2;
			Sf[mm][n-2]		= 2;
			
			Sf[1][n-5]	= 3;		//Spieler 3
			Sf[2][n-5]	= 3;
			Sf[2][n-6]	= 3;
			Sf[1][n-7]	= 3;
			Sf[3][n-6]	= 3;
			
			Sf[1][4] = 4;		//Spieler 4
			Sf[2][5] = 4;
			Sf[2][6] = 4;
			Sf[1][6] = 4;
			Sf[3][5] = 4;
			
			Sf[m-2][4] = 5;		//Spieler 5
			Sf[m-3][4] = 5;
			Sf[m-3][5] = 5;
			Sf[m-4][5] = 5;
			Sf[m-2][6] = 5;
			
			Sf[m-2][n-5] = 6;		//Spieler 6
			Sf[m-3][n-6] = 6;
			Sf[m-3][n-7] = 6;
			Sf[m-4][n-6] = 6;
			Sf[m-2][n-7] = 6;
			
			Sf[mm-2][nn-2] 	= 7;		//Spieler 7
			Sf[mm-2][nn+1] 	= 7;
			Sf[mm-1][nn-1] 	= 7;
			Sf[mm-1][nn]	= 7;
			Sf[mm][nn-1] 	= 7;
			Sf[mm][nn] 		= 7;
			Sf[mm+1][nn-2] 	= 7;
			Sf[mm+1][nn+1] 	= 7;
			
		} else if (number_of_players == 8) {
			
			Sf[4][1]	= 1;		//Spieler 1
			Sf[5][2]	= 1;
			Sf[5][3]	= 1;
			Sf[6][2]	= 1;
			Sf[6][1]	= 1;
			
			Sf[4][n-2]	= 2;		//Spieler 2
			Sf[4][n-3]	= 2;
			Sf[5][n-3]	= 2;
			Sf[5][n-4]	= 2;
			Sf[6][n-2]	= 2;
			
			Sf[1][n-5]	= 3;		//Spieler 3
			Sf[2][n-7]	= 3;
			Sf[2][n-6]	= 3;
			Sf[1][n-7]	= 3;
			Sf[3][n-6]	= 3;
			
			Sf[1][4] = 4;		//Spieler 4
			Sf[2][5] = 4;
			Sf[2][4] = 4;
			Sf[1][6] = 4;
			Sf[3][5] = 4;
			
			Sf[m-2][4] = 5;		//Spieler 5
			Sf[m-3][6] = 5;
			Sf[m-3][5] = 5;
			Sf[m-4][5] = 5;
			Sf[m-2][6] = 5;
			
			Sf[m-2][n-5] = 6;		//Spieler 6
			Sf[m-3][n-6] = 6;
			Sf[m-3][n-5] = 6;
			Sf[m-4][n-6] = 6;
			Sf[m-2][n-7] = 6;
			
			Sf[m-5][1]	= 7;		//Spieler 7
			Sf[m-5][2]	= 7;
			Sf[m-6][2]	= 7;
			Sf[m-6][3]	= 7;
			Sf[m-7][1]	= 7;
			
			Sf[m-5][n-2] = 8;		//Spieler 8
			Sf[m-6][n-3] = 8;
			Sf[m-6][n-4] = 8;
			Sf[m-7][n-3] = 8;
			Sf[m-7][n-2] = 8;
			
		} else if (number_of_players == 9) {
			unsigned int mm, nn;
			mm = m/2;
			nn = n/2;
			
			Sf[4][1]	= 1;		//Spieler 1
			Sf[5][2]	= 1;
			Sf[5][3]	= 1;
			Sf[6][2]	= 1;
			Sf[6][1]	= 1;
			
			Sf[4][n-2]	= 2;		//Spieler 2
			Sf[4][n-3]	= 2;
			Sf[5][n-3]	= 2;
			Sf[5][n-4]	= 2;
			Sf[6][n-2]	= 2;
			
			Sf[1][n-5]	= 3;		//Spieler 3
			Sf[2][n-7]	= 3;
			Sf[2][n-6]	= 3;
			Sf[1][n-7]	= 3;
			Sf[3][n-6]	= 3;
			
			Sf[1][4] = 4;		//Spieler 4
			Sf[2][5] = 4;
			Sf[2][4] = 4;
			Sf[1][6] = 4;
			Sf[3][5] = 4;
			
			Sf[m-2][4] = 5;		//Spieler 5
			Sf[m-3][6] = 5;
			Sf[m-3][5] = 5;
			Sf[m-4][5] = 5;
			Sf[m-2][6] = 5;
			
			Sf[m-2][n-5] = 6;		//Spieler 6
			Sf[m-3][n-6] = 6;
			Sf[m-3][n-5] = 6;
			Sf[m-4][n-6] = 6;
			Sf[m-2][n-7] = 6;
			
			Sf[m-5][1]	= 7;		//Spieler 7
			Sf[m-5][2]	= 7;
			Sf[m-6][2]	= 7;
			Sf[m-6][3]	= 7;
			Sf[m-7][1]	= 7;
			
			Sf[m-5][n-2] = 8;		//Spieler 8
			Sf[m-6][n-3] = 8;
			Sf[m-6][n-4] = 8;
			Sf[m-7][n-3] = 8;
			Sf[m-7][n-2] = 8;
			
			Sf[mm-2][nn-2] 	= 9;		//Spieler 9
			Sf[mm-2][nn+1] 	= 9;
			Sf[mm-1][nn-1] 	= 9;
			Sf[mm-1][nn]	= 9;
			Sf[mm][nn-1] 	= 9;
			Sf[mm][nn] 		= 9;
			Sf[mm+1][nn-2] 	= 9;
			Sf[mm+1][nn+1] 	= 9;
		}
		
	} else if (gamemode == 10) {
		for (unsigned int i=1; i<=(m-2); i+=1) {
			if (i%3 != 0) {
				Sf[i][3] = 1;
			}
		}
		for (unsigned int j=1; j<=(n-2); j+=1) {
			if (j%3 != 0) {
				Sf[3][j] = 1;
			}
		}
		Sf[5][5] = 1;
	
	} else if (gamemode == 11) {
		unsigned int m_2, n_2;
		m_2 = (m-1)/2;
		n_2 = (n-1)/2;
		
		if (number_of_players == 2) {
			
			Sf[m_2-1][1] = 1;		//Spieler 1
			Sf[m_2][2]	 = 1;
			Sf[m_2][3]	 = 1;
			Sf[m_2+1][1] = 1;
			Sf[m_2+1][2] = 1;
			
			Sf[m_2+1][n-2]	= 2;		//Spieler 2
			Sf[m_2+1][n-3] 	= 2;
			Sf[m_2][n-3] 	= 2;
			Sf[m_2][n-4] 	= 2;
			Sf[m_2-1][n-2] 	= 2;
			
		} else if (number_of_players == 3) {
			
			Sf[m_2-1][1] = 1;		//Spieler 1
			Sf[m_2][2]	 = 1;
			Sf[m_2][3]	 = 1;
			Sf[m_2+1][1] = 1;
			Sf[m_2+1][2] = 1;
			
			Sf[1][n_2] 		= 2;		//Spieler 2
			Sf[2][n_2-1]	= 2;
			Sf[2][n_2]		= 2;
			Sf[2][n_2+1]	= 2;
			
			Sf[m_2+1][n-2]	= 3;		//Spieler 3
			Sf[m_2+1][n-3] 	= 3;
			Sf[m_2][n-3] 	= 3;
			Sf[m_2][n-4] 	= 3;
			Sf[m_2-1][n-2] 	= 3;
			
		} else if (number_of_players == 4) {
			
			Sf[m_2-1][1] = 1;		//Spieler 1
			Sf[m_2][2]	 = 1;
			Sf[m_2][3]	 = 1;
			Sf[m_2+1][1] = 1;
			Sf[m_2+1][2] = 1;
			
			Sf[1][n_2] 		= 2;		//Spieler 2
			Sf[2][n_2-1]	= 2;
			Sf[2][n_2]		= 2;
			Sf[2][n_2+1]	= 2;
			
			Sf[m_2+1][n-2]	= 3;		//Spieler 3
			Sf[m_2+1][n-3] 	= 3;
			Sf[m_2][n-3] 	= 3;
			Sf[m_2][n-4] 	= 3;
			Sf[m_2-1][n-2] 	= 3;
			
			Sf[m-2][n_2] 	= 4;		//Spieler 4
			Sf[m-3][n_2-1]	= 4;
			Sf[m-3][n_2]	= 4;
			Sf[m-3][n_2+1]	= 4;
			
		} else if (number_of_players == 5) {
			
			Sf[m_2-1][1] = 1;		//Spieler 1
			Sf[m_2][2]	 = 1;
			Sf[m_2][3]	 = 1;
			Sf[m_2+1][1] = 1;
			Sf[m_2+1][2] = 1;
			
			Sf[1][n_2] 		= 2;		//Spieler 2
			Sf[2][n_2-1]	= 2;
			Sf[2][n_2]		= 2;
			Sf[2][n_2+1]	= 2;
			
			Sf[m_2+1][n-2]	= 3;		//Spieler 3
			Sf[m_2+1][n-3] 	= 3;
			Sf[m_2][n-3] 	= 3;
			Sf[m_2][n-4] 	= 3;
			Sf[m_2-1][n-2] 	= 3;
			
			Sf[m-2][n_2] 	= 4;		//Spieler 4
			Sf[m-2][n_2+2]	= 4;
			Sf[m-3][n_2+1]	= 4;
			Sf[m-3][n_2+2]	= 4;
			Sf[m-4][n_2+1]	= 4;
			
			Sf[m-2][n_2-1] 	= 5;		//Spieler 5
			Sf[m-3][n_2-2]	= 5;
			Sf[m-3][n_2-1]	= 5;
			Sf[m-4][n_2]	= 5;
			Sf[m-4][n_2-1]	= 5;
			
		} else if (number_of_players == 6) {
			
			Sf[m_2][1]		= 1;		//Spieler 1
			Sf[m_2+2][1]	= 1;
			Sf[m_2+1][2]	= 1;
			Sf[m_2+2][2]	= 1;
			Sf[m_2+1][3]	= 1;
			
			Sf[1][n_2] 		= 2;		//Spieler 2
			Sf[1][n_2-2]	= 2;
			Sf[2][n_2-1]	= 2;
			Sf[2][n_2-2]	= 2;
			Sf[3][n_2-1]	= 2;
			
			Sf[m_2+2][n-2]	= 3;		//Spieler 3
			Sf[m_2+2][n-3] 	= 3;
			Sf[m_2+1][n-3] 	= 3;
			Sf[m_2+1][n-4] 	= 3;
			Sf[m_2][n-2] 	= 3;
			
			Sf[m_2][3]		= 4;		//Spieler 4
			Sf[m_2-1][1]	= 4;
			Sf[m_2-1][2]	= 4;
			Sf[m_2-1][3]	= 4;
			Sf[m_2-2][2]	= 4;
			
			Sf[1][n_2+1] 	= 5;		//Spieler 5
			Sf[2][n_2+1]	= 5;
			Sf[2][n_2+2]	= 5;
			Sf[3][n_2]		= 5;
			Sf[3][n_2+1]	= 5;
			
			Sf[m_2-2][n-3]	= 6;		//Spieler 6
			Sf[m_2-1][n-2] 	= 6;
			Sf[m_2-1][n-3] 	= 6;
			Sf[m_2-1][n-4] 	= 6;
			Sf[m_2][n-4] 	= 6;
			
		} else if (number_of_players == 7) {
			
			Sf[m_2][1]		= 1;		//Spieler 1
			Sf[m_2+2][1]	= 1;
			Sf[m_2+1][2]	= 1;
			Sf[m_2+2][2]	= 1;
			Sf[m_2+1][3]	= 1;
			
			Sf[1][n_2] 		= 2;		//Spieler 2
			Sf[2][n_2-1]	= 2;
			Sf[2][n_2]		= 2;
			Sf[2][n_2+1]	= 2;
			
			Sf[m_2+2][n-2]	= 3;		//Spieler 3
			Sf[m_2+2][n-3] 	= 3;
			Sf[m_2+1][n-3] 	= 3;
			Sf[m_2+1][n-4] 	= 3;
			Sf[m_2][n-2] 	= 3;
			
			Sf[m-2][n_2] 	= 4;		//Spieler 4
			Sf[m-2][n_2+2]	= 4;
			Sf[m-3][n_2+1]	= 4;
			Sf[m-3][n_2+2]	= 4;
			Sf[m-4][n_2+1]	= 4;
			
			Sf[m_2][3]		= 5;		//Spieler 5
			Sf[m_2-1][1]	= 5;
			Sf[m_2-1][2]	= 5;
			Sf[m_2-1][3]	= 5;
			Sf[m_2-2][2]	= 5;
			
			Sf[m_2-2][n-3]	= 6;		//Spieler 6
			Sf[m_2-1][n-2] 	= 6;
			Sf[m_2-1][n-3] 	= 6;
			Sf[m_2-1][n-4] 	= 6;
			Sf[m_2][n-4] 	= 6;
			
			Sf[m-2][n_2-1] 	= 7;		//Spieler 7
			Sf[m-3][n_2-2]	= 7;
			Sf[m-3][n_2-1]	= 7;
			Sf[m-4][n_2]	= 7;
			Sf[m-4][n_2-1]	= 7;
			
		} else if (number_of_players == 8) {
			
			Sf[m_2][1]		= 1;		//Spieler 1
			Sf[m_2+2][1]	= 1;
			Sf[m_2+1][2]	= 1;
			Sf[m_2+2][2]	= 1;
			Sf[m_2+1][3]	= 1;
			
			Sf[1][n_2] 		= 2;		//Spieler 2
			Sf[1][n_2-2]	= 2;
			Sf[2][n_2-1]	= 2;
			Sf[2][n_2-2]	= 2;
			Sf[3][n_2-1]	= 2;
			
			Sf[m_2+2][n-2]	= 3;		//Spieler 3
			Sf[m_2+2][n-3] 	= 3;
			Sf[m_2+1][n-3] 	= 3;
			Sf[m_2+1][n-4] 	= 3;
			Sf[m_2][n-2] 	= 3;
			
			Sf[m-2][n_2] 	= 4;		//Spieler 4
			Sf[m-2][n_2+2]	= 4;
			Sf[m-3][n_2+1]	= 4;
			Sf[m-3][n_2+2]	= 4;
			Sf[m-4][n_2+1]	= 4;
			
			Sf[m_2][3]		= 5;		//Spieler 5
			Sf[m_2-1][1]	= 5;
			Sf[m_2-1][2]	= 5;
			Sf[m_2-1][3]	= 5;
			Sf[m_2-2][2]	= 5;
			
			Sf[1][n_2+1] 	= 6;		//Spieler 6
			Sf[2][n_2+1]	= 6;
			Sf[2][n_2+2]	= 6;
			Sf[3][n_2]		= 6;
			Sf[3][n_2+1]	= 6;
			
			Sf[m_2-2][n-3]	= 7;		//Spieler 7
			Sf[m_2-1][n-2] 	= 7;
			Sf[m_2-1][n-3] 	= 7;
			Sf[m_2-1][n-4] 	= 7;
			Sf[m_2][n-4] 	= 7;
			
			Sf[m-2][n_2-1] 	= 8;		//Spieler 8
			Sf[m-3][n_2-2]	= 8;
			Sf[m-3][n_2-1]	= 8;
			Sf[m-4][n_2]	= 8;
			Sf[m-4][n_2-1]	= 8;
			
		} else if (number_of_players == 9) {
			
			Sf[m_2+1][1]	= 1;		//Spieler 1
			Sf[m_2+3][1]	= 1;
			Sf[m_2+2][2]	= 1;
			Sf[m_2+3][2]	= 1;
			Sf[m_2+2][3]	= 1;
			
			Sf[1][n_2-1] 	= 2;		//Spieler 2
			Sf[1][n_2-3]	= 2;
			Sf[2][n_2-2]	= 2;
			Sf[2][n_2-3]	= 2;
			Sf[3][n_2-2]	= 2;
			
			Sf[m_2+3][n-2]	= 3;		//Spieler 3
			Sf[m_2+3][n-3] 	= 3;
			Sf[m_2+2][n-3] 	= 3;
			Sf[m_2+2][n-4] 	= 3;
			Sf[m_2+1][n-2] 	= 3;
			
			Sf[m_2-1][1]	= 4;		//Spieler 4
			Sf[m_2-2][2]	= 4;
			Sf[m_2-2][3]	= 4;
			Sf[m_2-3][1]	= 4;
			Sf[m_2-3][2]	= 4;
			
			Sf[1][n_2+1] 	= 5;		//Spieler 5
			Sf[1][n_2+3]	= 5;
			Sf[2][n_2+2]	= 5;
			Sf[2][n_2+3]	= 5;
			Sf[3][n_2+2]	= 5;
			
			Sf[m_2-3][n-2]	= 6;		//Spieler 6
			Sf[m_2-3][n-3] 	= 6;
			Sf[m_2-2][n-3] 	= 6;
			Sf[m_2-2][n-4] 	= 6;
			Sf[m_2-1][n-2] 	= 6;
			
			Sf[m_2][1]		= 7;		//Spieler 7
			Sf[m_2+1][2]	= 7;
			Sf[m_2][2]		= 7;
			Sf[m_2-1][2]	= 7;
			
			Sf[1][n_2] 		= 8;		//Spieler 8
			Sf[2][n_2-1]	= 8;
			Sf[2][n_2]		= 8;
			Sf[2][n_2+1]	= 8;
			
			Sf[m_2][n-2]	= 9;		//Spieler 9
			Sf[m_2-1][n-3] 	= 9;
			Sf[m_2][n-3] 	= 9;
			Sf[m_2+1][n-3] 	= 9;
			
		}
		
		Sf[m_2][n_2] = 77;
		
	} else if (gamemode == 12) {
		if (number_of_players >= 1) {
			
			Sf[1][1] = 1;		//Spieler 1
			Sf[2][2] = 1;
			Sf[2][3] = 1;
			Sf[3][1] = 1;
			Sf[3][2] = 1;
			
		}
		if (number_of_players >= 2) {
			
			Sf[1][n-2] = 2;		//Spieler 2
			Sf[1][n-4] = 2;
			Sf[2][n-4] = 2;
			Sf[2][n-3] = 2;
			Sf[3][n-3] = 2;
			
		}
		if (number_of_players >= 3) {
			
			Sf[m-2][n-2] = 3;		//Spieler 3
			Sf[m-3][n-4] = 3;
			Sf[m-3][n-3] = 3;
			Sf[m-4][n-3] = 3;
			Sf[m-4][n-2] = 3;
			
		}
		if (number_of_players >= 4) {
			
			Sf[m-2][1] = 4;		//Spieler 4
			Sf[m-2][3] = 4;
			Sf[m-3][2] = 4;
			Sf[m-3][3] = 4;
			Sf[m-4][2] = 4;
			
		}
		if (number_of_players == 5) {
			unsigned int n_2;
			unsigned int m_2;
			n_2 = (n-1)/2;
			m_2 = (m-1)/2;
			
			Sf[m_2][n_2]	= 5;		//Spieler 5
			Sf[m_2][n_2-1]	= 5;
			Sf[m_2][n_2+1]	= 5;
			Sf[m_2-1][n_2]	= 5;
			Sf[m_2+1][n_2]	= 5;
			
		} else if (number_of_players > 5) {
			unsigned int m_2;
			m_2 = (m-1)/2;
			
			Sf[m_2][n-2]	= 5;		//Spieler 5
			Sf[m_2][n-3]	= 5;
			Sf[m_2-1][n-3]	= 5;
			Sf[m_2+1][n-3]	= 5;
			
		}
		if (number_of_players >= 6) {
			unsigned int m_2;
			m_2 = (m-1)/2;
			
			Sf[m_2][1]		= 6;		//Spieler 6
			Sf[m_2][2]		= 6;
			Sf[m_2-1][2]	= 6;
			Sf[m_2+1][2]	= 6;
			
		}
		if (number_of_players == 7) {
			unsigned int n_2;
			unsigned int m_2;
			n_2 = (n-1)/2;
			m_2 = (m-1)/2;
			
			Sf[m_2][n_2]	= 7;		//Spieler 7
			Sf[m_2][n_2-1]	= 7;
			Sf[m_2][n_2+1]	= 7;
			Sf[m_2-1][n_2]	= 7;
			Sf[m_2+1][n_2]	= 7;
			
		} else if (number_of_players > 7) {
			unsigned int n_2;
			n_2 = (n-1)/2;
			
			Sf[1][n_2]		= 7;		//Spieler 7
			Sf[2][n_2-1]	= 7;
			Sf[2][n_2]		= 7;
			Sf[2][n_2+1]	= 7;
			
		}
		if (number_of_players >= 8) {
			unsigned int n_2;
			n_2 = (n-1)/2;
			
			Sf[m-2][n_2]	= 8;		//Spieler 8
			Sf[m-3][n_2-1]	= 8;
			Sf[m-3][n_2]	= 8;
			Sf[m-3][n_2+1]	= 8;
			
		}
		if (number_of_players >= 9) {
			unsigned int n_2;
			unsigned int m_2;
			n_2 = (n-1)/2;
			m_2 = (m-1)/2;
			
			Sf[m_2][n_2]	= 9;		//Spieler 9
			Sf[m_2][n_2-1]	= 9;
			Sf[m_2][n_2+1]	= 9;
			Sf[m_2-1][n_2]	= 9;
			Sf[m_2+1][n_2]	= 9;
			
		}
	}
	
	return Sf;
}

Spielfeld new_life_1 (Spielfeld Sf, unsigned int m, unsigned int n, unsigned int w, unsigned int gamemode, unsigned int* information_code){
	Spielfeld Sf_nl_1;
	unsigned int a, inhi;
	
	//printf("	w: %u\n", w);	//test
	
	Sf_nl_1 = Spielfeld_Create (m, n);		//inhibitor in informationcode[1], ability ist in information_code[0]
	a = 0;
	inhi = 0;
	
	if (gamemode != 7) {
		for (unsigned int i=1; i<m-1; i+=1){			//Spieler 1
			for (unsigned int j=1; j<n-1; j+=1){
				if ((Sf[i][j] == 0)||(Sf[i][j] == 71)) {	//71 = Trap, only used in survive
					for (unsigned int h=i-1; h<=i+1; h+=1){
						for (unsigned int k=j-1; k<=j+1; k+=1){
							if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
								if ((gamemode != 6)&&(gamemode != 9)) {
									if (Sf[h][k] == 1){
										a+=1;
									}
								} else if (gamemode == 6) {
									if ((Sf[h][k] == 1)||(Sf[h][k] == 11)){
										a+=1;
									}
								} else if (gamemode == 9) {
									if (Sf[h][k] == 1){
										a+=1;
									}
									if ((information_code[1] != 0)&&(information_code[1] != 100)&&(Sf[h][k] == information_code[1])&&(information_code[0] != 6)&&(information_code[0] != 5)) {
										inhi += 1;
									}
								}
							}
						}
					}				//w=3, w=2, w=4
					if (gamemode != 9) {
						if (w == 4){
							if ((a == w) || (a == w+1)){
								Sf_nl_1[i][j] = 1;
							}
						} else {
							if (a == w){
								Sf_nl_1[i][j] = 1;
							}
						}
						a = 0;
					} else if (gamemode == 9) {
						if (inhi != 3) {
							if (information_code[0] == 1) {
								if (w == 2){
									if ((a == w) || (a == w+1)){
										Sf_nl_1[i][j] = 1;
									}
								} else {
									if (a == w){
										if (w == 1) {
											Sf_nl_1[i][j] = 1;
										} else if (w == 0) {
											for (unsigned int h=i-1; h<=i+1; h+=1){
												for (unsigned int k=j-1; k<=j+1; k+=1){
													if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
														if (Sf[h][k] != 0) {
															inhi = 10;
															break;
														}
													}
												}
												if (inhi == 10) {
													break;
												}
											}
											if (inhi != 10) {
												Sf_nl_1[i][j] = 1;
											}
										}
									}
								}
							} else if (information_code[0] == 2) {
								if (w == 3){
									if ((a == w) || (a == w+1)){
										Sf_nl_1[i][j] = 1;
									}
								} else {
									if (a == w){
										Sf_nl_1[i][j] = 1;
									}
								}
							} else if (information_code[0] == 3) {
								if (w == 5){
									if ((a == w) || (a == w+1)){
										Sf_nl_1[i][j] = 1;
									}
								} else {
									if (a == w){
										Sf_nl_1[i][j] = 1;
									}
								}
							} else if (information_code[0] == 4) {
								if (w == 4){
									if ((a == w) || (a == w+1)){
										Sf_nl_1[i][j] = 1;
									}
								} else {
									if (a == w){
										Sf_nl_1[i][j] = 1;
									}  else if ((a == (w-1))&&((j == (n-2))||(j == 1)||(i == (m-2))||(i == 1))) {
										Sf_nl_1[i][j] = 1;
									}
								}
							} else {
								if (w == 4){
									if ((a == w) || (a == w+1)){
										Sf_nl_1[i][j] = 1;
									}
								} else {
									if (a == w){
										Sf_nl_1[i][j] = 1;
									}
								}
							}
						}
						a = 0;
						inhi = 0;
					}
					
				}
				if ((gamemode == 10)&&(Sf[i][j] == 2)) {
					for (unsigned int h=i-1; h<=i+1; h+=1){
						for (unsigned int k=j-1; k<=j+1; k+=1){
							if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
								if (Sf[h][k] == 1){
									a+=1;
								}
							}
						}
					}
					if (w == 4){
						if ((a == w) || (a == w+1)){
							Sf_nl_1[i][j] = 1;
						}
					} else {
						if (a == w){
							Sf_nl_1[i][j] = 1;
						}
					}
					a = 0;
				}
			}
		}
		if ((gamemode == 12)&&(information_code[1] >= 1)) {
			for (unsigned int i=1; i<m-1; i+=1){
				for (unsigned int j=1; j<n-1; j+=1){
					
					if ((Sf[i][j] == 71)&&(Sf_nl_1[i][j] == 1)) {
						Sf[i][j] = 0;
						Sf_nl_1[i][j] = 0;
						Sf[i-1][j] = 0;
						Sf_nl_1[i-1][j] = 0;
						Sf[i+1][j] = 0;
						Sf_nl_1[i+1][j] = 0;
						Sf[i][j-1] = 0;
						Sf_nl_1[i][j-1] = 0;
						Sf[i][j+1] = 0;
						Sf_nl_1[i][j+1] = 0;
						
					}
				}
			}
		}
		
	} else if (gamemode == 7) {
		for (unsigned int i=1; i<=(m-1)/2; i+=1){			//Spieler 1
			for (unsigned int j=1; j<n-1; j+=1){
				if (Sf[i][j] == 0) {
					for (unsigned int h=i-1; h<=i+1; h+=1){
						for (unsigned int k=j-1; k<=j+1; k+=1){
							if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
								if (Sf[h][k] == 1){
									a+=1;
								}
							}
						}
					}				//w=3, w=2, w=4
					if(w == 4){
						if ((a == w) || (a == w+1) ){
							Sf_nl_1[i][j] = 1;
						}
					} else {
						if (a == w){
							Sf_nl_1[i][j] = 1;
						}
					}
					a = 0;
					
				}
			}
		}
	}
		
	return Sf_nl_1;
}

Spielfeld old_dying_1 (Spielfeld Sf, unsigned int m, unsigned int n, unsigned int d, unsigned int e, unsigned int gamemode, unsigned int* information_code){
	Spielfeld Sf_od_1;
	unsigned int a, e_down, d_up;
	
	Sf_od_1 = Spielfeld_Create (m, n);
	a = 0;
	e_down = 0;
	d_up = 0;
	
	for (unsigned int i=1; i<m-1; i+=1){			//Spieler 1
		for (unsigned int j=1; j<n-1; j+=1){
			if (Sf[i][j] == 1) {
				if (gamemode == 9) {
					if ((information_code[2] != 0)&&(information_code[2] != 100)&&(information_code[0] != 7)&&(information_code[0] != 6)) {
						if ((Sf[i+1][j] == information_code[2])||(Sf[i][j-1] == information_code[2])||(Sf[i][j+1] == information_code[2])||(Sf[i-1][j] == information_code[2])) {
							d_up = 1;
							d += 1;
						}
					}
					if ((information_code[3] != 0)&&(information_code[3] != 100)&&(information_code[0] != 8)&&(information_code[0] != 6)) {
						if ((Sf[i+1][j] == information_code[3])||(Sf[i][j-1] == information_code[3])||(Sf[i][j+1] == information_code[3])||(Sf[i-1][j] == information_code[3])) {
							e_down = 1;
							e -= 1;
						}
					}
				}
				for (unsigned int h=i-1; h<=i+1; h+=1){
					for (unsigned int k=j-1; k<=j+1; k+=1){
						if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
							if ((gamemode != 6)&&(gamemode != 9)) {
								if (Sf[h][k] == 1){
									a+=1;
								}
							} else if (gamemode == 6) {
								if ((Sf[h][k] == 1)||(Sf[h][k] == 11)){
									a+=1;
								}
							} else if (gamemode == 9) {
								if (Sf[h][k] == 1){
									a+=1;
								}
							}
						}
					}
				}
				if (gamemode != 9) {
					if ((a < d+1) || (a > e+1)){		//d=2, d=1, e=3, e=4
						Sf_od_1[i][j] = 101;		//Code für das Eleminieren
					}
					
					a = 0;
				} else if (gamemode == 9) {
					if ((d == 11)||(d == 10)) {
						d = 0;
						d_up += 10;
					}
					
					if ((a < d+1) || (a > e+1)){
						Sf_od_1[i][j] = 101;
					}
					
					if ((d_up == 1)||(d_up == 11)) {
						d -= 1;
					}
					if ((d_up == 10)||(d_up == 11)) {
						d = 10;
					}
					if (e_down == 1) {
						e += 1;
					}
					d_up = 0;
					e_down = 0;
					a = 0;
				}
			}
		}
	}
	
	return Sf_od_1;
}

Spielfeld new_life_2 (Spielfeld Sf, unsigned int m, unsigned int n, unsigned int w, unsigned int gamemode, unsigned int* information_code){
	Spielfeld Sf_nl_2;
	unsigned int b, inhi;
	
	Sf_nl_2 = Spielfeld_Create (m, n);
	b = 0;
	inhi = 0;
	
	if (gamemode != 7) {
		for (unsigned int i=1; i<m-1; i+=1){			//Spieler 2
			for (unsigned int j=1; j<n-1; j+=1){
				if ((Sf[i][j] == 0)||(Sf[i][j] == 71)) {	//71 = Trap, only used in survive
					for (unsigned int h=i-1; h<=i+1; h+=1){
						for (unsigned int k=j-1; k<=j+1; k+=1){
							if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
								if (gamemode != 9) {
									if (Sf[h][k] == 2){
										b+=1;
									}
								} else if (gamemode == 9) {
									if (Sf[h][k] == 2){
										b+=1;
									}
									if ((information_code[1] != 0)&&(information_code[1] != 100)&&(Sf[h][k] == information_code[1])&&(information_code[0] != 6)&&(information_code[0] != 5)) {
										inhi += 1;
									}
								}
								
							}
						}
					}			//w=3, w=2, w=4
					if ((gamemode != 9)&&(gamemode != 10)) {
						if(w == 4){
							if ((b == w) || (b == w+1) ){
								Sf_nl_2[i][j] = 2;
							}
						} else {
							if (b == w){
								Sf_nl_2[i][j] = 2;
							}
						}
						b = 0;
					} else if (gamemode == 9) {
						if (inhi != 3) {
							if (information_code[0] == 1) {
								if (w == 2){
									if ((b == w) || (b == w+1)){
										Sf_nl_2[i][j] = 2;
									}
								} else {
									if (b == w){
										if (w == 1) {
											Sf_nl_2[i][j] = 2;
										} else if (w == 0) {
											for (unsigned int h=i-1; h<=i+1; h+=1){
												for (unsigned int k=j-1; k<=j+1; k+=1){
													if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
														if (Sf[h][k] != 0) {
															inhi = 10;
															break;
														}
													}
												}
												if (inhi == 10) {
													break;
												}
											}
											if (inhi != 10) {
												Sf_nl_2[i][j] = 2;
											}
										}
									}
								}
							} else if (information_code[0] == 2) {
								if (w == 3){
									if ((b == w) || (b == w+1)){
										Sf_nl_2[i][j] = 2;
									}
								} else {
									if (b == w){
										Sf_nl_2[i][j] = 2;
									}
								}
							} else if (information_code[0] == 3) {
								if (w == 5){
									if ((b == w) || (b == w+1)){
										Sf_nl_2[i][j] = 2;
									}
								} else {
									if (b == w){
										Sf_nl_2[i][j] = 2;
									}
								}
							} else if (information_code[0] == 4) {
								if (w == 4){
									if ((b == w) || (b == w+1)){
										Sf_nl_2[i][j] = 2;
									}
								} else {
									if (b == w){
										Sf_nl_2[i][j] = 2;
									}  else if ((b == (w-1))&&((j == (n-2))||(j == 1)||(i == (m-2))||(i == 1))) {
										Sf_nl_2[i][j] = 2;
									}
								}
							} else {
								if (w == 4){
									if ((b == w) || (b == w+1)){
										Sf_nl_2[i][j] = 2;
									}
								} else {
									if (b == w){
										Sf_nl_2[i][j] = 2;
									}
								}
							}
						}
						b = 0;
						inhi = 0;
					} else if (gamemode == 10) {
						if (w == 3){
							if ((b == w) || (b == w+1)){
								Sf_nl_2[i][j] = 2;
							}
						} else {
							if (b == w){
								Sf_nl_2[i][j] = 2;
							}
						}
						b = 0;
					}
					
				}
			}
		}
		if ((gamemode == 12)&&(information_code[1] >= 1)) {
			for (unsigned int i=1; i<m-1; i+=1){
				for (unsigned int j=1; j<n-1; j+=1){
					
					if ((Sf[i][j] == 71)&&(Sf_nl_2[i][j] == 2)) {
						Sf[i][j] = 0;
						Sf_nl_2[i][j] = 0;
						Sf[i-1][j] = 0;
						Sf_nl_2[i-1][j] = 0;
						Sf[i+1][j] = 0;
						Sf_nl_2[i+1][j] = 0;
						Sf[i][j-1] = 0;
						Sf_nl_2[i][j-1] = 0;
						Sf[i][j+1] = 0;
						Sf_nl_2[i][j+1] = 0;
						
					}
				}
			}
		}
		
	} else if (gamemode == 7) {
		for (unsigned int i=(m-1)/2; i<m-1; i+=1){			//Spieler 2
			for (unsigned int j=1; j<n-1; j+=1){
				if (Sf[i][j] == 0) {
					for (unsigned int h=i-1; h<=i+1; h+=1){
						for (unsigned int k=j-1; k<=j+1; k+=1){
							if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
								if (Sf[h][k] == 2){
									b+=1;
								}
							}
						}
					}			//w=3, w=2, w=4
					if(w == 4){
						if ((b == w) || (b == w+1) ){
							Sf_nl_2[i][j] = 2;
						}
					} else {
						if (b == w){
							Sf_nl_2[i][j] = 2;
						}
					}
					b = 0;
				}
			}
		}
	}
	
	
	return Sf_nl_2;
}

Spielfeld old_dying_2 (Spielfeld Sf, unsigned int m, unsigned int n, unsigned int d, unsigned int e, unsigned int gamemode, unsigned int* information_code){
	Spielfeld Sf_od_2;
	unsigned int b, e_down, d_up;
	
	Sf_od_2 = Spielfeld_Create (m, n);
	b = 0;
	e_down = 0;
	d_up = 0;
	
	for (unsigned int i=1; i<m-1; i+=1){			//Spieler 2
		for (unsigned int j=1; j<n-1; j+=1){
			if (Sf[i][j] == 2) {
				if (gamemode == 9) {
					if ((information_code[2] != 0)&&(information_code[2] != 100)&&(information_code[0] != 7)&&(information_code[0] != 6)) {
						if ((Sf[i+1][j] == information_code[2])||(Sf[i][j-1] == information_code[2])||(Sf[i][j+1] == information_code[2])||(Sf[i-1][j] == information_code[2])) {
							d_up = 1;
							d += 1;
						}
					}
					if ((information_code[3] != 0)&&(information_code[3] != 100)&&(information_code[0] != 8)&&(information_code[0] != 6)) {
						if ((Sf[i+1][j] == information_code[3])||(Sf[i][j-1] == information_code[3])||(Sf[i][j+1] == information_code[3])||(Sf[i-1][j] == information_code[3])) {
							e_down = 1;
							e -= 1;
						}
					}
				}
				for (unsigned int h=i-1; h<=i+1; h+=1){
					for (unsigned int k=j-1; k<=j+1; k+=1){
						if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
							if (Sf[h][k] == 2){
								b+=1;
							}
						}
					}
				}
				if (gamemode != 9) {
					if ((b < d+1) || (b > e+1)){		//d=2, d=1, e=3, e=4
						Sf_od_2[i][j] = 202;		//Code für das Eleminieren
					}
					b = 0;
					
					if ((gamemode == 10)&&(Sf_od_2[i][j] != 202)) {
						for (unsigned int h=i-1; h<=i+1; h+=1){		//Wirt in der Nähe?
							for (unsigned int k=j-1; k<=j+1; k+=1){
								if (Sf[h][k] == 1) {
									b = 1;
									break;
								}
							}
							if (b == 1) {
								break;
							}
						}
						if (b == 0) {
							Sf_od_2[i][j] = 202;		//Code für das Eleminieren
						}
						b = 0;
					}
				} else if (gamemode == 9) {
					if ((d == 11)||(d == 10)) {
						d = 0;
						d_up += 10;
					}
					
					if ((b < d+1) || (b > e+1)){
						Sf_od_2[i][j] = 202;
					}
					
					if ((d_up == 1)||(d_up == 11)) {
						d -= 1;
					}
					if ((d_up == 10)||(d_up == 11)) {
						d = 10;
					}
					if (e_down == 1) {
						e += 1;
					}
					d_up = 0;
					e_down = 0;
					b = 0;
				}
			}
		}
	}
	
	return Sf_od_2;
}

Spielfeld new_life_3 (Spielfeld Sf, unsigned int m, unsigned int n, unsigned int w, unsigned int gamemode, unsigned int* information_code){
	Spielfeld Sf_nl_3;
	unsigned int b, inhi;
	
	Sf_nl_3 = Spielfeld_Create (m, n);
	b = 0;
	inhi = 0;
	
	if (gamemode != 7) {
		for (unsigned int i=1; i<m-1; i+=1){			//Spieler 3
			for (unsigned int j=1; j<n-1; j+=1){
				if ((Sf[i][j] == 0)||(Sf[i][j] == 71)) {	//71 = Trap, only used in survive
					for (unsigned int h=i-1; h<=i+1; h+=1){
						for (unsigned int k=j-1; k<=j+1; k+=1){
							if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
								if (gamemode != 9) {
									if (Sf[h][k] == 3){
										b+=1;
									}
								} else if (gamemode == 9) {
									if (Sf[h][k] == 3){
										b+=1;
									}
									if ((information_code[1] != 0)&&(information_code[1] != 100)&&(Sf[h][k] == information_code[1])&&(information_code[0] != 6)&&(information_code[0] != 5)) {
										inhi += 1;
									}
								}
								
							}
						}
					}			//w=3, w=2, w=4
					if ((gamemode != 9)&&(gamemode != 10)) {
						if (w == 4){
							if ((b == w) || (b == w+1) ){
								Sf_nl_3[i][j] = 3;
							}
						} else {
							if (b == w){
								Sf_nl_3[i][j] = 3;
							}
						}
						b = 0;
					} else if (gamemode == 9) {
						if (inhi != 3) {
							if (information_code[0] == 1) {
								if (w == 2){
									if ((b == w) || (b == w+1)){
										Sf_nl_3[i][j] = 3;
									}
								} else {
									if (b == w){
										if (w == 1) {
											Sf_nl_3[i][j] = 3;
										} else if (w == 0) {
											for (unsigned int h=i-1; h<=i+1; h+=1){
												for (unsigned int k=j-1; k<=j+1; k+=1){
													if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
														if (Sf[h][k] != 0) {
															inhi = 10;
															break;
														}
													}
												}
												if (inhi == 10) {
													break;
												}
											}
											if (inhi != 10) {
												Sf_nl_3[i][j] = 3;
											}
										}
									}
								}
							} else if (information_code[0] == 2) {
								if (w == 3){
									if ((b == w) || (b == w+1)){
										Sf_nl_3[i][j] = 3;
									}
								} else {
									if (b == w){
										Sf_nl_3[i][j] = 3;
									}
								}
							} else if (information_code[0] == 3) {
								if (w == 5){
									if ((b == w) || (b == w+1)){
										Sf_nl_3[i][j] = 3;
									}
								} else {
									if (b == w){
										Sf_nl_3[i][j] = 3;
									}
								}
							} else if (information_code[0] == 4) {
								if (w == 4){
									if ((b == w) || (b == w+1)){
										Sf_nl_3[i][j] = 3;
									}
								} else {
									if (b == w){
										Sf_nl_3[i][j] = 3;
									}  else if ((b == (w-1))&&((j == (n-2))||(j == 1)||(i == (m-2))||(i == 1))) {
										Sf_nl_3[i][j] = 3;
									}
								}
							} else {
								if (w == 4){
									if ((b == w) || (b == w+1)){
										Sf_nl_3[i][j] = 3;
									}
								} else {
									if (b == w){
										Sf_nl_3[i][j] = 3;
									}
								}
							}
						}
						b = 0;
						inhi = 0;
					} else if (gamemode == 10) {
						if (w == 3){
							if ((b == w) || (b == w+1)){
								Sf_nl_3[i][j] = 3;
							}
						} else {
							if (b == w){
								Sf_nl_3[i][j] = 3;
							}
						}
						b = 0;
					}
					
				}
			}
		}
		if ((gamemode == 12)&&(information_code[1] >= 1)) {
			for (unsigned int i=1; i<m-1; i+=1){
				for (unsigned int j=1; j<n-1; j+=1){
					
					if ((Sf[i][j] == 71)&&(Sf_nl_3[i][j] == 3)) {
						Sf[i][j] = 0;
						Sf_nl_3[i][j] = 0;
						Sf[i-1][j] = 0;
						Sf_nl_3[i-1][j] = 0;
						Sf[i+1][j] = 0;
						Sf_nl_3[i+1][j] = 0;
						Sf[i][j-1] = 0;
						Sf_nl_3[i][j-1] = 0;
						Sf[i][j+1] = 0;
						Sf_nl_3[i][j+1] = 0;
						
					}
				}
			}
		}
		
	} else if (gamemode == 7) {		//possible to modify
		for (unsigned int i=(m-1)/2; i<m-1; i+=1){			//Spieler 3
			for (unsigned int j=1; j<n-1; j+=1){
				if (Sf[i][j] == 0) {
					for (unsigned int h=i-1; h<=i+1; h+=1){
						for (unsigned int k=j-1; k<=j+1; k+=1){
							if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
								if (Sf[h][k] == 3){
									b+=1;
								}
							}
						}
					}			//w=3, w=2, w=4
					if(w == 4){
						if ((b == w) || (b == w+1) ){
							Sf_nl_3[i][j] = 3;
						}
					} else {
						if (b == w){
							Sf_nl_3[i][j] = 3;
						}
					}
					b = 0;
				}
			}
		}
	}
	
	
	return Sf_nl_3;
}	//copy

Spielfeld old_dying_3 (Spielfeld Sf, unsigned int m, unsigned int n, unsigned int d, unsigned int e, unsigned int gamemode, unsigned int* information_code){
	Spielfeld Sf_od_3;
	unsigned int b, e_down, d_up;
	
	Sf_od_3 = Spielfeld_Create (m, n);
	b = 0;
	e_down = 0;
	d_up = 0;
	
	for (unsigned int i=1; i<m-1; i+=1){			//Spieler 3
		for (unsigned int j=1; j<n-1; j+=1){
			if (Sf[i][j] == 3) {
				if (gamemode == 9) {
					if ((information_code[2] != 0)&&(information_code[2] != 100)&&(information_code[0] != 7)&&(information_code[0] != 6)) {
						if ((Sf[i+1][j] == information_code[2])||(Sf[i][j-1] == information_code[2])||(Sf[i][j+1] == information_code[2])||(Sf[i-1][j] == information_code[2])) {
							d_up = 1;
							d += 1;
						}
					}
					if ((information_code[3] != 0)&&(information_code[3] != 100)&&(information_code[0] != 8)&&(information_code[0] != 6)) {
						if ((Sf[i+1][j] == information_code[3])||(Sf[i][j-1] == information_code[3])||(Sf[i][j+1] == information_code[3])||(Sf[i-1][j] == information_code[3])) {
							e_down = 1;
							e -= 1;
						}
					}
				}
				for (unsigned int h=i-1; h<=i+1; h+=1){
					for (unsigned int k=j-1; k<=j+1; k+=1){
						if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
							if (Sf[h][k] == 3){
								b+=1;
							}
						}
					}
				}
				if (gamemode != 9) {
					if ((b < d+1) || (b > e+1)){		//d=2, d=1, e=3, e=4
						Sf_od_3[i][j] = 303;		//Code für das Eleminieren
					}
					b = 0;
					
					if ((gamemode == 10)&&(Sf_od_3[i][j] != 303)) {
						for (unsigned int h=i-1; h<=i+1; h+=1){		//Wirt in der Nähe?
							for (unsigned int k=j-1; k<=j+1; k+=1){
								if (Sf[h][k] == 2) {
									b = 1;
									break;
								}
							}
							if (b == 1) {
								break;
							}
						}
						if (b == 0) {
							Sf_od_3[i][j] = 303;		//Code für das Eleminieren
						}
						b = 0;
					}
				} else if (gamemode == 9) {
					if ((d == 11)||(d == 10)) {
						d = 0;
						d_up += 10;
					}
					
					if ((b < d+1) || (b > e+1)){
						Sf_od_3[i][j] = 303;
					}
					
					if ((d_up == 1)||(d_up == 11)) {
						d -= 1;
					}
					if ((d_up == 10)||(d_up == 11)) {
						d = 10;
					}
					if (e_down == 1) {
						e += 1;
					}
					d_up = 0;
					e_down = 0;
					b = 0;
				}
			}
		}
	}
	
	return Sf_od_3;
}	//copy

Spielfeld new_life_4 (Spielfeld Sf, unsigned int m, unsigned int n, unsigned int w, unsigned int gamemode, unsigned int* information_code){
	Spielfeld Sf_nl_4;
	unsigned int b, inhi;
	
	//printf("Checkpoint: new_life_4 Aufruf \n");	//test
	
	//printf("w = %u \n", w);	//test, war nicht "w", sondern "b=0;" vergessen
	
	Sf_nl_4 = Spielfeld_Create (m, n);
	b = 0;
	inhi = 0;
	
	if (gamemode != 7) {
		for (unsigned int i=1; i<m-1; i+=1){			//Spieler 4
			for (unsigned int j=1; j<n-1; j+=1){
				if ((Sf[i][j] == 0)||(Sf[i][j] == 71)) {	//71 = Trap, only used in survive
					for (unsigned int h=i-1; h<=i+1; h+=1){
						for (unsigned int k=j-1; k<=j+1; k+=1){
							if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
								if (gamemode != 9) {
									if (Sf[h][k] == 4){
										b+=1;
									}
								} else if (gamemode == 9) {
									if (Sf[h][k] == 4){
										b+=1;
									}
									if ((information_code[1] != 0)&&(information_code[1] != 100)&&(Sf[h][k] == information_code[1])&&(information_code[0] != 6)&&(information_code[0] != 5)) {
										inhi += 1;
									}
								}
							}
						}
					}			//w=3, w=2, w=4
					if ((gamemode != 9)&&(gamemode != 10)) {
						if (w == 4){
							if ((b == w) || (b == w+1) ){
								Sf_nl_4[i][j] = 4;
							}
						} else {
							if (b == w){
								Sf_nl_4[i][j] = 4;
							}
						}
						b = 0;
					} else if (gamemode == 9) {
						if (inhi != 3) {
							if (information_code[0] == 1) {
								if (w == 2){
									if ((b == w) || (b == w+1)){
										Sf_nl_4[i][j] = 4;
									}
								} else {
									if (b == w){
										if (w == 1) {
											Sf_nl_4[i][j] = 4;
										} else if (w == 0) {
											for (unsigned int h=i-1; h<=i+1; h+=1){
												for (unsigned int k=j-1; k<=j+1; k+=1){
													if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
														if (Sf[h][k] != 0) {
															inhi = 10;
															break;
														}
													}
												}
												if (inhi == 10) {
													break;
												}
											}
											if (inhi != 10) {
												Sf_nl_4[i][j] = 4;
											}
										}
									}
								}
							} else if (information_code[0] == 2) {
								if (w == 3){
									if ((b == w) || (b == w+1)){
										Sf_nl_4[i][j] = 4;
									}
								} else {
									if (b == w){
										Sf_nl_4[i][j] = 4;
									}
								}
							} else if (information_code[0] == 3) {
								if (w == 5){
									if ((b == w) || (b == w+1)){
										Sf_nl_4[i][j] = 4;
									}
								} else {
									if (b == w){
										Sf_nl_4[i][j] = 4;
									}
								}
							} else if (information_code[0] == 4) {
								if (w == 4){
									if ((b == w) || (b == w+1)){
										Sf_nl_4[i][j] = 4;
									}
								} else {
									if (b == w){
										Sf_nl_4[i][j] = 4;
									}  else if ((b == (w-1))&&((j == (n-2))||(j == 1)||(i == (m-2))||(i == 1))) {
										Sf_nl_4[i][j] = 4;
									}
								}
							} else {
								if (w == 4){
									if ((b == w) || (b == w+1)){
										Sf_nl_4[i][j] = 4;
									}
								} else {
									if (b == w){
										Sf_nl_4[i][j] = 4;
									}
								}
							}
						}
						b = 0;
						inhi = 0;
					} else if (gamemode == 10) {
						if (w == 3){
							if ((b == w) || (b == w+1)){
								Sf_nl_4[i][j] = 4;
							}
						} else {
							if (b == w){
								Sf_nl_4[i][j] = 4;
							}
						}
						b = 0;
					}
					
				}
			}
		}if ((gamemode == 12)&&(information_code[1] >= 1)) {
			for (unsigned int i=1; i<m-1; i+=1){
				for (unsigned int j=1; j<n-1; j+=1){
					
					if ((Sf[i][j] == 71)&&(Sf_nl_4[i][j] == 4)) {
						Sf[i][j] = 0;
						Sf_nl_4[i][j] = 0;
						Sf[i-1][j] = 0;
						Sf_nl_4[i-1][j] = 0;
						Sf[i+1][j] = 0;
						Sf_nl_4[i+1][j] = 0;
						Sf[i][j-1] = 0;
						Sf_nl_4[i][j-1] = 0;
						Sf[i][j+1] = 0;
						Sf_nl_4[i][j+1] = 0;
						
					}
				}
			}
		}
		
	} else if (gamemode == 7) {		//possible to modify
		for (unsigned int i=(m-1)/2; i<m-1; i+=1){			//Spieler 4
			for (unsigned int j=1; j<n-1; j+=1){
				if (Sf[i][j] == 0) {
					for (unsigned int h=i-1; h<=i+1; h+=1){
						for (unsigned int k=j-1; k<=j+1; k+=1){
							if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
								if (Sf[h][k] == 4){
									b+=1;
								}
							}
						}
					}			//w=3, w=2, w=4
					if(w == 4){
						if ((b == w) || (b == w+1) ){
							Sf_nl_4[i][j] = 4;
						}
					} else {
						if (b == w){
							Sf_nl_4[i][j] = 4;
						}
					}
					b = 0;
				}
			}
		}
	}
	
	//printf("Checkpoint: new_life_4 Ende \n");	//test
	
	return Sf_nl_4;
}	//copy

Spielfeld old_dying_4 (Spielfeld Sf, unsigned int m, unsigned int n, unsigned int d, unsigned int e, unsigned int gamemode, unsigned int* information_code){
	Spielfeld Sf_od_4;
	unsigned int b, e_down, d_up;
	
	Sf_od_4 = Spielfeld_Create (m, n);
	b = 0;
	e_down = 0;
	d_up = 0;
	
	for (unsigned int i=1; i<m-1; i+=1){			//Spieler 4
		for (unsigned int j=1; j<n-1; j+=1){
			if (Sf[i][j] == 4) {
				if (gamemode == 9) {
					if ((information_code[2] != 0)&&(information_code[2] != 100)&&(information_code[0] != 7)&&(information_code[0] != 6)) {
						if ((Sf[i+1][j] == information_code[2])||(Sf[i][j-1] == information_code[2])||(Sf[i][j+1] == information_code[2])||(Sf[i-1][j] == information_code[2])) {
							d_up = 1;
							d += 1;
						}
					}
					if ((information_code[3] != 0)&&(information_code[3] != 100)&&(information_code[0] != 8)&&(information_code[0] != 6)) {
						if ((Sf[i+1][j] == information_code[3])||(Sf[i][j-1] == information_code[3])||(Sf[i][j+1] == information_code[3])||(Sf[i-1][j] == information_code[3])) {
							e_down = 1;
							e -= 1;
						}
					}
				}
				for (unsigned int h=i-1; h<=i+1; h+=1){
					for (unsigned int k=j-1; k<=j+1; k+=1){
						if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
							if (Sf[h][k] == 4){
								b+=1;
							}
						}
					}
				}
				if (gamemode != 9) {
					if ((b < d+1) || (b > e+1)){		//d=2, d=1, e=3, e=4
						Sf_od_4[i][j] = 404;		//Code für das Eleminieren
					}
					b = 0;
					
					if ((gamemode == 10)&&(Sf_od_4[i][j] != 404)) {
						for (unsigned int h=i-1; h<=i+1; h+=1){		//Wirt in der Nähe?
							for (unsigned int k=j-1; k<=j+1; k+=1){
								if (Sf[h][k] == 3) {
									b = 1;
									break;
								}
							}
							if (b == 1) {
								break;
							}
						}
						if (b == 0) {
							Sf_od_4[i][j] = 404;		//Code für das Eleminieren
						}
						b = 0;
					}
				} else if (gamemode == 9) {
					if ((d == 11)||(d == 10)) {
						d = 0;
						d_up += 10;
					}
					
					if ((b < d+1) || (b > e+1)){
						Sf_od_4[i][j] = 404;
					}
					
					if ((d_up == 1)||(d_up == 11)) {
						d -= 1;
					}
					if ((d_up == 10)||(d_up == 11)) {
						d = 10;
					}
					if (e_down == 1) {
						e += 1;
					}
					d_up = 0;
					e_down = 0;
					b = 0;
				}
			}
		}
	}
	
	return Sf_od_4;
}	//copy

Spielfeld new_life_5 (Spielfeld Sf, unsigned int m, unsigned int n, unsigned int w, unsigned int gamemode, unsigned int* information_code){
	Spielfeld Sf_nl_5;
	unsigned int b, inhi;
	
	Sf_nl_5 = Spielfeld_Create (m, n);
	b = 0;
	inhi = 0;
	
	if (gamemode != 7) {
		for (unsigned int i=1; i<m-1; i+=1){			//Spieler 5
			for (unsigned int j=1; j<n-1; j+=1){
				if ((Sf[i][j] == 0)||(Sf[i][j] == 71)) {	//71 = Trap, only used in survive
					for (unsigned int h=i-1; h<=i+1; h+=1){
						for (unsigned int k=j-1; k<=j+1; k+=1){
							if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
								if (gamemode != 9) {
									if (Sf[h][k] == 5){
										b+=1;
									}
								} else if (gamemode == 9) {
									if (Sf[h][k] == 5){
										b+=1;
									}
									if ((information_code[1] != 0)&&(information_code[1] != 100)&&(Sf[h][k] == information_code[1])&&(information_code[0] != 6)&&(information_code[0] != 5)) {
										inhi += 1;
									}
								}
							}
						}
					}			//w=3, w=2, w=4
					if ((gamemode != 9)&&(gamemode != 10)) {
						if(w == 4){
							if ((b == w) || (b == w+1) ){
								Sf_nl_5[i][j] = 5;
							}
						} else {
							if (b == w){
								Sf_nl_5[i][j] = 5;
							}
						}
						b = 0;
					} else if (gamemode == 9) {
						if (inhi != 3) {
							if (information_code[0] == 1) {
								if (w == 2){
									if ((b == w) || (b == w+1)){
										Sf_nl_5[i][j] = 5;
									}
								} else {
									if (b == w){
										if (w == 1) {
											Sf_nl_5[i][j] = 5;
										} else if (w == 0) {
											for (unsigned int h=i-1; h<=i+1; h+=1){
												for (unsigned int k=j-1; k<=j+1; k+=1){
													if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
														if (Sf[h][k] != 0) {
															inhi = 10;
															break;
														}
													}
												}
												if (inhi == 10) {
													break;
												}
											}
											if (inhi != 10) {
												Sf_nl_5[i][j] = 5;
											}
										}
									}
								}
							} else if (information_code[0] == 2) {
								if (w == 3){
									if ((b == w) || (b == w+1)){
										Sf_nl_5[i][j] = 5;
									}
								} else {
									if (b == w){
										Sf_nl_5[i][j] = 5;
									}
								}
							} else if (information_code[0] == 3) {
								if (w == 5){
									if ((b == w) || (b == w+1)){
										Sf_nl_5[i][j] = 5;
									}
								} else {
									if (b == w){
										Sf_nl_5[i][j] = 5;
									}
								}
							} else if (information_code[0] == 4) {
								if (w == 4){
									if ((b == w) || (b == w+1)){
										Sf_nl_5[i][j] = 5;
									}
								} else {
									if (b == w){
										Sf_nl_5[i][j] = 5;
									}  else if ((b == (w-1))&&((j == (n-2))||(j == 1)||(i == (m-2))||(i == 1))) {
										Sf_nl_5[i][j] = 5;
									}
								}
							} else {
								if (w == 4){
									if ((b == w) || (b == w+1)){
										Sf_nl_5[i][j] = 5;
									}
								} else {
									if (b == w){
										Sf_nl_5[i][j] = 5;
									}
								}
							}
						}
						b = 0;
						inhi = 0;
					} else if (gamemode == 10) {
						if (w == 3){
							if ((b == w) || (b == w+1)){
								Sf_nl_5[i][j] = 5;
							}
						} else {
							if (b == w){
								Sf_nl_5[i][j] = 5;
							}
						}
						b = 0;
					}
					
				}
			}
		}
		if ((gamemode == 12)&&(information_code[1] >= 1)) {
			for (unsigned int i=1; i<m-1; i+=1){
				for (unsigned int j=1; j<n-1; j+=1){
					
					if ((Sf[i][j] == 71)&&(Sf_nl_5[i][j] == 5)) {
						Sf[i][j] = 0;
						Sf_nl_5[i][j] = 0;
						Sf[i-1][j] = 0;
						Sf_nl_5[i-1][j] = 0;
						Sf[i+1][j] = 0;
						Sf_nl_5[i+1][j] = 0;
						Sf[i][j-1] = 0;
						Sf_nl_5[i][j-1] = 0;
						Sf[i][j+1] = 0;
						Sf_nl_5[i][j+1] = 0;
						
					}
				}
			}
		}
		
	} else if (gamemode == 7) {		//possible to modify
		for (unsigned int i=(m-1)/2; i<m-1; i+=1){			//Spieler 5
			for (unsigned int j=1; j<n-1; j+=1){
				if (Sf[i][j] == 0) {
					for (unsigned int h=i-1; h<=i+1; h+=1){
						for (unsigned int k=j-1; k<=j+1; k+=1){
							if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
								if (Sf[h][k] == 5){
									b+=1;
								}
							}
						}
					}			//w=3, w=2, w=4
					if(w == 4){
						if ((b == w) || (b == w+1) ){
							Sf_nl_5[i][j] = 5;
						}
					} else {
						if (b == w){
							Sf_nl_5[i][j] = 5;
						}
					}
					b = 0;
				}
			}
		}
	}
	
	
	return Sf_nl_5;
}	//copy

Spielfeld old_dying_5 (Spielfeld Sf, unsigned int m, unsigned int n, unsigned int d, unsigned int e, unsigned int gamemode, unsigned int* information_code){
	Spielfeld Sf_od_5;
	unsigned int b, e_down, d_up;
	
	Sf_od_5 = Spielfeld_Create (m, n);
	b = 0;
	e_down = 0;
	d_up = 0;
	
	for (unsigned int i=1; i<m-1; i+=1){			//Spieler 5
		for (unsigned int j=1; j<n-1; j+=1){
			if (Sf[i][j] == 5) {
				if (gamemode == 9) {
					if ((information_code[2] != 0)&&(information_code[2] != 100)&&(information_code[0] != 7)&&(information_code[0] != 6)) {
						if ((Sf[i+1][j] == information_code[2])||(Sf[i][j-1] == information_code[2])||(Sf[i][j+1] == information_code[2])||(Sf[i-1][j] == information_code[2])) {
							d_up = 1;
							d += 1;
						}
					}
					if ((information_code[3] != 0)&&(information_code[3] != 100)&&(information_code[0] != 8)&&(information_code[0] != 6)) {
						if ((Sf[i+1][j] == information_code[3])||(Sf[i][j-1] == information_code[3])||(Sf[i][j+1] == information_code[3])||(Sf[i-1][j] == information_code[3])) {
							e_down = 1;
							e -= 1;
						}
					}
				}
				for (unsigned int h=i-1; h<=i+1; h+=1){
					for (unsigned int k=j-1; k<=j+1; k+=1){
						if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
							if (Sf[h][k] == 5){
								b+=1;
							}
						}
					}
				}
				if (gamemode != 9) {
					if ((b < d+1) || (b > e+1)){		//d=2, d=1, e=3, e=4
						Sf_od_5[i][j] = 505;		//Code für das Eleminieren
					}
					b = 0;
					
					if ((gamemode == 10)&&(Sf_od_5[i][j] != 505)) {
						for (unsigned int h=i-1; h<=i+1; h+=1){		//Wirt in der Nähe?
							for (unsigned int k=j-1; k<=j+1; k+=1){
								if (Sf[h][k] == 4) {
									b = 1;
									break;
								}
							}
							if (b == 1) {
								break;
							}
						}
						if (b == 0) {
							Sf_od_5[i][j] = 505;		//Code für das Eleminieren
						}
						b = 0;
					}
				} else if (gamemode == 9) {
					if ((d == 11)||(d == 10)) {
						d = 0;
						d_up += 10;
					}
					
					if ((b < d+1) || (b > e+1)){
						Sf_od_5[i][j] = 505;
					}
					
					if ((d_up == 1)||(d_up == 11)) {
						d -= 1;
					}
					if ((d_up == 10)||(d_up == 11)) {
						d = 10;
					}
					if (e_down == 1) {
						e += 1;
					}
					d_up = 0;
					e_down = 0;
					b = 0;
				}
			}
		}
	}
	
	return Sf_od_5;
}	//copy

Spielfeld new_life_6 (Spielfeld Sf, unsigned int m, unsigned int n, unsigned int w, unsigned int gamemode, unsigned int* information_code){
	Spielfeld Sf_nl_6;
	unsigned int b, inhi;
	
	Sf_nl_6 = Spielfeld_Create (m, n);
	b = 0;
	inhi = 0;
	
	if (gamemode != 7) {
		for (unsigned int i=1; i<m-1; i+=1){			//Spieler 6
			for (unsigned int j=1; j<n-1; j+=1){
				if ((Sf[i][j] == 0)||(Sf[i][j] == 71)) {	//71 = Trap, only used in survive
					for (unsigned int h=i-1; h<=i+1; h+=1){
						for (unsigned int k=j-1; k<=j+1; k+=1){
							if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
								if (gamemode != 9) {
									if (Sf[h][k] == 6){
										b+=1;
									}
								} else if (gamemode == 9) {
									if (Sf[h][k] == 6){
										b+=1;
									}
									if ((information_code[1] != 0)&&(information_code[1] != 100)&&(Sf[h][k] == information_code[1])&&(information_code[0] != 6)&&(information_code[0] != 5)) {
										inhi += 1;
									}
								}
							}
						}
					}			//w=3, w=2, w=4
					if ((gamemode != 9)&&(gamemode != 10)) {
						if(w == 4){
							if ((b == w) || (b == w+1) ){
								Sf_nl_6[i][j] = 6;
							}
						} else {
							if (b == w){
								Sf_nl_6[i][j] = 6;
							}
						}
						b = 0;
					} else if (gamemode == 9) {
						if (inhi != 3) {
							if (information_code[0] == 1) {
								if (w == 2){
									if ((b == w) || (b == w+1)){
										Sf_nl_6[i][j] = 6;
									}
								} else {
									if (b == w){
										if (w == 1) {
											Sf_nl_6[i][j] = 6;
										} else if (w == 0) {
											for (unsigned int h=i-1; h<=i+1; h+=1){
												for (unsigned int k=j-1; k<=j+1; k+=1){
													if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
														if (Sf[h][k] != 0) {
															inhi = 10;
															break;
														}
													}
												}
												if (inhi == 10) {
													break;
												}
											}
											if (inhi != 10) {
												Sf_nl_6[i][j] = 6;
											}
										}
									}
								}
							} else if (information_code[0] == 2) {
								if (w == 3){
									if ((b == w) || (b == w+1)){
										Sf_nl_6[i][j] = 6;
									}
								} else {
									if (b == w){
										Sf_nl_6[i][j] = 6;
									}
								}
							} else if (information_code[0] == 3) {
								if (w == 5){
									if ((b == w) || (b == w+1)){
										Sf_nl_6[i][j] = 6;
									}
								} else {
									if (b == w){
										Sf_nl_6[i][j] = 6;
									}
								}
							} else if (information_code[0] == 4) {
								if (w == 4){
									if ((b == w) || (b == w+1)){
										Sf_nl_6[i][j] = 6;
									}
								} else {
									if (b == w){
										Sf_nl_6[i][j] = 6;
									}  else if ((b == (w-1))&&((j == (n-2))||(j == 1)||(i == (m-2))||(i == 1))) {
										Sf_nl_6[i][j] = 6;
									}
								}
							} else {
								if (w == 4){
									if ((b == w) || (b == w+1)){
										Sf_nl_6[i][j] = 6;
									}
								} else {
									if (b == w){
										Sf_nl_6[i][j] = 6;
									}
								}
							}
						}
						b = 0;
						inhi = 0;
					} else if (gamemode == 10) {
						if (w == 3){
							if ((b == w) || (b == w+1)){
								Sf_nl_6[i][j] = 6;
							}
						} else {
							if (b == w){
								Sf_nl_6[i][j] = 6;
							}
						}
						b = 0;
					}
					
				}
			}
		}
		if ((gamemode == 12)&&(information_code[1] >= 1)) {
			for (unsigned int i=1; i<m-1; i+=1){
				for (unsigned int j=1; j<n-1; j+=1){
					
					if ((Sf[i][j] == 71)&&(Sf_nl_6[i][j] == 6)) {
						Sf[i][j] = 0;
						Sf_nl_6[i][j] = 0;
						Sf[i-1][j] = 0;
						Sf_nl_6[i-1][j] = 0;
						Sf[i+1][j] = 0;
						Sf_nl_6[i+1][j] = 0;
						Sf[i][j-1] = 0;
						Sf_nl_6[i][j-1] = 0;
						Sf[i][j+1] = 0;
						Sf_nl_6[i][j+1] = 0;
						
					}
				}
			}
		}
		
	} else if (gamemode == 7) {		//possible to modify
		for (unsigned int i=(m-1)/2; i<m-1; i+=1){			//Spieler 6
			for (unsigned int j=1; j<n-1; j+=1){
				if (Sf[i][j] == 0) {
					for (unsigned int h=i-1; h<=i+1; h+=1){
						for (unsigned int k=j-1; k<=j+1; k+=1){
							if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
								if (Sf[h][k] == 6){
									b+=1;
								}
							}
						}
					}			//w=3, w=2, w=4
					if(w == 4){
						if ((b == w) || (b == w+1) ){
							Sf_nl_6[i][j] = 6;
						}
					} else {
						if (b == w){
							Sf_nl_6[i][j] = 6;
						}
					}
					b = 0;
				}
			}
		}
	}
	
	
	return Sf_nl_6;
}	//copy

Spielfeld old_dying_6 (Spielfeld Sf, unsigned int m, unsigned int n, unsigned int d, unsigned int e, unsigned int gamemode, unsigned int* information_code){
	Spielfeld Sf_od_6;
	unsigned int b, e_down, d_up;
	
	Sf_od_6 = Spielfeld_Create (m, n);
	b = 0;
	e_down = 0;
	d_up = 0;
	
	for (unsigned int i=1; i<m-1; i+=1){			//Spieler 6
		for (unsigned int j=1; j<n-1; j+=1){
			if (Sf[i][j] == 6) {
				if (gamemode == 9) {
					if ((information_code[2] != 0)&&(information_code[2] != 100)&&(information_code[0] != 7)&&(information_code[0] != 6)) {
						if ((Sf[i+1][j] == information_code[2])||(Sf[i][j-1] == information_code[2])||(Sf[i][j+1] == information_code[2])||(Sf[i-1][j] == information_code[2])) {
							d_up = 1;
							d += 1;
						}
					}
					if ((information_code[3] != 0)&&(information_code[3] != 100)&&(information_code[0] != 8)&&(information_code[0] != 6)) {
						if ((Sf[i+1][j] == information_code[3])||(Sf[i][j-1] == information_code[3])||(Sf[i][j+1] == information_code[3])||(Sf[i-1][j] == information_code[3])) {
							e_down = 1;
							e -= 1;
						}
					}
				}
				for (unsigned int h=i-1; h<=i+1; h+=1){
					for (unsigned int k=j-1; k<=j+1; k+=1){
						if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
							if (Sf[h][k] == 6){
								b+=1;
							}
						}
					}
				}
				if (gamemode != 9) {
					if ((b < d+1) || (b > e+1)){		//d=2, d=1, e=3, e=4
						Sf_od_6[i][j] = 606;		//Code für das Eleminieren
					}
					b = 0;
					
					if ((gamemode == 10)&&(Sf_od_6[i][j] != 606)) {
						for (unsigned int h=i-1; h<=i+1; h+=1){		//Wirt in der Nähe?
							for (unsigned int k=j-1; k<=j+1; k+=1){
								if (Sf[h][k] == 5) {
									b = 1;
									break;
								}
							}
							if (b == 1) {
								break;
							}
						}
						if (b == 0) {
							Sf_od_6[i][j] = 606;		//Code für das Eleminieren
						}
						b = 0;
					}
				} else if (gamemode == 9) {
					if ((d == 11)||(d == 10)) {
						d = 0;
						d_up += 10;
					}
					
					if ((b < d+1) || (b > e+1)){
						Sf_od_6[i][j] = 606;
					}
					
					if ((d_up == 1)||(d_up == 11)) {
						d -= 1;
					}
					if ((d_up == 10)||(d_up == 11)) {
						d = 10;
					}
					if (e_down == 1) {
						e += 1;
					}
					d_up = 0;
					e_down = 0;
					b = 0;
				}
			}
		}
	}
	
	return Sf_od_6;
}	//copy

Spielfeld new_life_7 (Spielfeld Sf, unsigned int m, unsigned int n, unsigned int w, unsigned int gamemode, unsigned int* information_code){
	Spielfeld Sf_nl_7;
	unsigned int b, inhi;
	
	Sf_nl_7 = Spielfeld_Create (m, n);
	b = 0;
	inhi = 0;
	
	if (gamemode != 7) {
		for (unsigned int i=1; i<m-1; i+=1){			//Spieler 7
			for (unsigned int j=1; j<n-1; j+=1){
				if ((Sf[i][j] == 0)||(Sf[i][j] == 71)) {	//71 = Trap, only used in survive
					for (unsigned int h=i-1; h<=i+1; h+=1){
						for (unsigned int k=j-1; k<=j+1; k+=1){
							if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
								if (gamemode != 9) {
									if (Sf[h][k] == 7){
										b+=1;
									}
								} else if (gamemode == 9) {
									if (Sf[h][k] == 7){
										b+=1;
									}
									if ((information_code[1] != 0)&&(information_code[1] != 100)&&(Sf[h][k] == information_code[1])&&(information_code[0] != 6)&&(information_code[0] != 5)) {
										inhi += 1;
									}
								}
							}
						}
					}			//w=3, w=2, w=4
					if ((gamemode != 9)&&(gamemode != 10)) {
						if(w == 4){
							if ((b == w) || (b == w+1) ){
								Sf_nl_7[i][j] = 7;
							}
						} else {
							if (b == w){
								Sf_nl_7[i][j] = 7;
							}
						}
						b = 0;
					} else if (gamemode == 9) {
						if (inhi != 3) {
							if (information_code[0] == 1) {
								if (w == 2){
									if ((b == w) || (b == w+1)){
										Sf_nl_7[i][j] = 7;
									}
								} else {
									if (b == w){
										if (w == 1) {
											Sf_nl_7[i][j] = 7;
										} else if (w == 0) {
											for (unsigned int h=i-1; h<=i+1; h+=1){
												for (unsigned int k=j-1; k<=j+1; k+=1){
													if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
														if (Sf[h][k] != 0) {
															inhi = 10;
															break;
														}
													}
												}
												if (inhi == 10) {
													break;
												}
											}
											if (inhi != 10) {
												Sf_nl_7[i][j] = 7;
											}
										}
									}
								}
							} else if (information_code[0] == 2) {
								if (w == 3){
									if ((b == w) || (b == w+1)){
										Sf_nl_7[i][j] = 7;
									}
								} else {
									if (b == w){
										Sf_nl_7[i][j] = 7;
									}
								}
							} else if (information_code[0] == 3) {
								if (w == 5){
									if ((b == w) || (b == w+1)){
										Sf_nl_7[i][j] = 7;
									}
								} else {
									if (b == w){
										Sf_nl_7[i][j] = 7;
									}
								}
							} else if (information_code[0] == 4) {
								if (w == 4){
									if ((b == w) || (b == w+1)){
										Sf_nl_7[i][j] = 7;
									}
								} else {
									if (b == w){
										Sf_nl_7[i][j] = 7;
									}  else if ((b == (w-1))&&((j == (n-2))||(j == 1)||(i == (m-2))||(i == 1))) {
										Sf_nl_7[i][j] = 7;
									}
								}
							} else {
								if (w == 4){
									if ((b == w) || (b == w+1)){
										Sf_nl_7[i][j] = 7;
									}
								} else {
									if (b == w){
										Sf_nl_7[i][j] = 7;
									}
								}
							}
						}
						b = 0;
						inhi = 0;
					} else if (gamemode == 10) {
						if (w == 3){
							if ((b == w) || (b == w+1)){
								Sf_nl_7[i][j] = 7;
							}
						} else {
							if (b == w){
								Sf_nl_7[i][j] = 7;
							}
						}
						b = 0;
					}
					
				}
			}
		}
		if ((gamemode == 12)&&(information_code[1] >= 1)) {
			for (unsigned int i=1; i<m-1; i+=1){
				for (unsigned int j=1; j<n-1; j+=1){
					
					if ((Sf[i][j] == 71)&&(Sf_nl_7[i][j] == 7)) {
						Sf[i][j] = 0;
						Sf_nl_7[i][j] = 0;
						Sf[i-1][j] = 0;
						Sf_nl_7[i-1][j] = 0;
						Sf[i+1][j] = 0;
						Sf_nl_7[i+1][j] = 0;
						Sf[i][j-1] = 0;
						Sf_nl_7[i][j-1] = 0;
						Sf[i][j+1] = 0;
						Sf_nl_7[i][j+1] = 0;
						
					}
				}
			}
		}
		
	} else if (gamemode == 7) {		//possible to modify
		for (unsigned int i=(m-1)/2; i<m-1; i+=1){			//Spieler 7
			for (unsigned int j=1; j<n-1; j+=1){
				if (Sf[i][j] == 0) {
					for (unsigned int h=i-1; h<=i+1; h+=1){
						for (unsigned int k=j-1; k<=j+1; k+=1){
							if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
								if (Sf[h][k] == 7){
									b+=1;
								}
							}
						}
					}			//w=3, w=2, w=4
					if(w == 4){
						if ((b == w) || (b == w+1) ){
							Sf_nl_7[i][j] = 7;
						}
					} else {
						if (b == w){
							Sf_nl_7[i][j] = 7;
						}
					}
					b = 0;
				}
			}
		}
	}
	
	
	return Sf_nl_7;
}	//copy

Spielfeld old_dying_7 (Spielfeld Sf, unsigned int m, unsigned int n, unsigned int d, unsigned int e, unsigned int gamemode, unsigned int* information_code){
	Spielfeld Sf_od_7;
	unsigned int b, e_down, d_up;
	
	Sf_od_7 = Spielfeld_Create (m, n);
	b = 0;
	e_down = 0;
	d_up = 0;
	
	for (unsigned int i=1; i<m-1; i+=1){			//Spieler 7
		for (unsigned int j=1; j<n-1; j+=1){
			if (Sf[i][j] == 7) {
				if (gamemode == 9) {
					if ((information_code[2] != 0)&&(information_code[2] != 100)&&(information_code[0] != 7)&&(information_code[0] != 6)) {
						if ((Sf[i+1][j] == information_code[2])||(Sf[i][j-1] == information_code[2])||(Sf[i][j+1] == information_code[2])||(Sf[i-1][j] == information_code[2])) {
							d_up = 1;
							d += 1;
						}
					}
					if ((information_code[3] != 0)&&(information_code[3] != 100)&&(information_code[0] != 8)&&(information_code[0] != 6)) {
						if ((Sf[i+1][j] == information_code[3])||(Sf[i][j-1] == information_code[3])||(Sf[i][j+1] == information_code[3])||(Sf[i-1][j] == information_code[3])) {
							e_down = 1;
							e -= 1;
						}
					}
				}
				for (unsigned int h=i-1; h<=i+1; h+=1){
					for (unsigned int k=j-1; k<=j+1; k+=1){
						if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
							if (Sf[h][k] == 7){
								b+=1;
							}
						}
					}
				}
				if (gamemode != 9) {
					if ((b < d+1) || (b > e+1)){		//d=2, d=1, e=3, e=4
						Sf_od_7[i][j] = 707;		//Code für das Eleminieren
					}
					b = 0;
					
					if ((gamemode == 10)&&(Sf_od_7[i][j] != 707)) {
						for (unsigned int h=i-1; h<=i+1; h+=1){		//Wirt in der Nähe?
							for (unsigned int k=j-1; k<=j+1; k+=1){
								if (Sf[h][k] == 6) {
									b = 1;
									break;
								}
							}
							if (b == 1) {
								break;
							}
						}
						if (b == 0) {
							Sf_od_7[i][j] = 707;		//Code für das Eleminieren
						}
						b = 0;
					}
				} else if (gamemode == 9) {
					if ((d == 11)||(d == 10)) {
						d = 0;
						d_up += 10;
					}
					
					if ((b < d+1) || (b > e+1)){
						Sf_od_7[i][j] = 707;
					}
					
					if ((d_up == 1)||(d_up == 11)) {
						d -= 1;
					}
					if ((d_up == 10)||(d_up == 11)) {
						d = 10;
					}
					if (e_down == 1) {
						e += 1;
					}
					d_up = 0;
					e_down = 0;
					b = 0;
				}
			}
		}
	}
	
	return Sf_od_7;
}	//copy

Spielfeld new_life_8 (Spielfeld Sf, unsigned int m, unsigned int n, unsigned int w, unsigned int gamemode, unsigned int* information_code){
	Spielfeld Sf_nl_8;
	unsigned int b, inhi;
	
	Sf_nl_8 = Spielfeld_Create (m, n);
	b = 0;
	inhi = 0;
	
	if (gamemode != 7) {
		for (unsigned int i=1; i<m-1; i+=1){			//Spieler 8
			for (unsigned int j=1; j<n-1; j+=1){
				if ((Sf[i][j] == 0)||(Sf[i][j] == 71)) {	//71 = Trap, only used in survive
					for (unsigned int h=i-1; h<=i+1; h+=1){
						for (unsigned int k=j-1; k<=j+1; k+=1){
							if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
								if (gamemode != 9) {
									if (Sf[h][k] == 8){
										b+=1;
									}
								} else if (gamemode == 9) {
									if (Sf[h][k] == 8){
										b+=1;
									}
									if ((information_code[1] != 0)&&(information_code[1] != 100)&&(Sf[h][k] == information_code[1])&&(information_code[0] != 6)&&(information_code[0] != 5)) {
										inhi += 1;
									}
								}
							}
						}
					}			//w=3, w=2, w=4
					if ((gamemode != 9)&&(gamemode != 10)) {
						if(w == 4){
							if ((b == w) || (b == w+1) ){
								Sf_nl_8[i][j] = 8;
							}
						} else {
							if (b == w){
								Sf_nl_8[i][j] = 8;
							}
						}
						b = 0;
					} else if (gamemode == 9) {
						if (inhi != 3) {
							if (information_code[0] == 1) {
								if (w == 2){
									if ((b == w) || (b == w+1)){
										Sf_nl_8[i][j] = 8;
									}
								} else {
									if (b == w){
										if (w == 1) {
											Sf_nl_8[i][j] = 8;
										} else if (w == 0) {
											for (unsigned int h=i-1; h<=i+1; h+=1){
												for (unsigned int k=j-1; k<=j+1; k+=1){
													if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
														if (Sf[h][k] != 0) {
															inhi = 10;
															break;
														}
													}
												}
												if (inhi == 10) {
													break;
												}
											}
											if (inhi != 10) {
												Sf_nl_8[i][j] = 8;
											}
										}
									}
								}
							} else if (information_code[0] == 2) {
								if (w == 3){
									if ((b == w) || (b == w+1)){
										Sf_nl_8[i][j] = 8;
									}
								} else {
									if (b == w){
										Sf_nl_8[i][j] = 8;
									}
								}
							} else if (information_code[0] == 3) {
								if (w == 5){
									if ((b == w) || (b == w+1)){
										Sf_nl_8[i][j] = 8;
									}
								} else {
									if (b == w){
										Sf_nl_8[i][j] = 8;
									}
								}
							} else if (information_code[0] == 4) {
								if (w == 4){
									if ((b == w) || (b == w+1)){
										Sf_nl_8[i][j] = 8;
									}
								} else {
									if (b == w){
										Sf_nl_8[i][j] = 8;
									}  else if ((b == (w-1))&&((j == (n-2))||(j == 1)||(i == (m-2))||(i == 1))) {
										Sf_nl_8[i][j] = 8;
									}
								}
							} else {
								if (w == 4){
									if ((b == w) || (b == w+1)){
										Sf_nl_8[i][j] = 8;
									}
								} else {
									if (b == w){
										Sf_nl_8[i][j] = 8;
									}
								}
							}
						}
						b = 0;
						inhi = 0;
					} else if (gamemode == 10) {
						if (w == 3){
							if ((b == w) || (b == w+1)){
								Sf_nl_8[i][j] = 8;
							}
						} else {
							if (b == w){
								Sf_nl_8[i][j] = 8;
							}
						}
						b = 0;
					}
					
				}
			}
		}
		if ((gamemode == 12)&&(information_code[1] >= 1)) {
			for (unsigned int i=1; i<m-1; i+=1){
				for (unsigned int j=1; j<n-1; j+=1){
					
					if ((Sf[i][j] == 71)&&(Sf_nl_8[i][j] == 8)) {
						Sf[i][j] = 0;
						Sf_nl_8[i][j] = 0;
						Sf[i-1][j] = 0;
						Sf_nl_8[i-1][j] = 0;
						Sf[i+1][j] = 0;
						Sf_nl_8[i+1][j] = 0;
						Sf[i][j-1] = 0;
						Sf_nl_8[i][j-1] = 0;
						Sf[i][j+1] = 0;
						Sf_nl_8[i][j+1] = 0;
						
					}
				}
			}
		}
		
	} else if (gamemode == 7) {		//possible to modify
		for (unsigned int i=(m-1)/2; i<m-1; i+=1){			//Spieler 8
			for (unsigned int j=1; j<n-1; j+=1){
				if (Sf[i][j] == 0) {
					for (unsigned int h=i-1; h<=i+1; h+=1){
						for (unsigned int k=j-1; k<=j+1; k+=1){
							if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
								if (Sf[h][k] == 8){
									b+=1;
								}
							}
						}
					}			//w=3, w=2, w=4
					if(w == 4){
						if ((b == w) || (b == w+1) ){
							Sf_nl_8[i][j] = 8;
						}
					} else {
						if (b == w){
							Sf_nl_8[i][j] = 8;
						}
					}
					b = 0;
				}
			}
		}
	}
	
	
	return Sf_nl_8;
}	//copy

Spielfeld old_dying_8 (Spielfeld Sf, unsigned int m, unsigned int n, unsigned int d, unsigned int e, unsigned int gamemode, unsigned int* information_code){
	Spielfeld Sf_od_8;
	unsigned int b, e_down, d_up;
	
	Sf_od_8 = Spielfeld_Create (m, n);
	b = 0;
	e_down = 0;
	d_up = 0;
	
	for (unsigned int i=1; i<m-1; i+=1){			//Spieler 8
		for (unsigned int j=1; j<n-1; j+=1){
			if (Sf[i][j] == 8) {
				if (gamemode == 9) {
					if ((information_code[2] != 0)&&(information_code[2] != 100)&&(information_code[0] != 7)&&(information_code[0] != 6)) {
						if ((Sf[i+1][j] == information_code[2])||(Sf[i][j-1] == information_code[2])||(Sf[i][j+1] == information_code[2])||(Sf[i-1][j] == information_code[2])) {
							d_up = 1;
							d += 1;
						}
					}
					if ((information_code[3] != 0)&&(information_code[3] != 100)&&(information_code[0] != 8)&&(information_code[0] != 6)) {
						if ((Sf[i+1][j] == information_code[3])||(Sf[i][j-1] == information_code[3])||(Sf[i][j+1] == information_code[3])||(Sf[i-1][j] == information_code[3])) {
							e_down = 1;
							e -= 1;
						}
					}
				}
				for (unsigned int h=i-1; h<=i+1; h+=1){
					for (unsigned int k=j-1; k<=j+1; k+=1){
						if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
							if (Sf[h][k] == 8){
								b+=1;
							}
						}
					}
				}
				if (gamemode != 9) {
					if ((b < d+1) || (b > e+1)){		//d=2, d=1, e=3, e=4
						Sf_od_8[i][j] = 808;		//Code für das Eleminieren
					}
					b = 0;
					
					if ((gamemode == 10)&&(Sf_od_8[i][j] != 808)) {
						for (unsigned int h=i-1; h<=i+1; h+=1){		//Wirt in der Nähe?
							for (unsigned int k=j-1; k<=j+1; k+=1){
								if (Sf[h][k] == 7) {
									b = 1;
									break;
								}
							}
							if (b == 1) {
								break;
							}
						}
						if (b == 0) {
							Sf_od_8[i][j] = 808;		//Code für das Eleminieren
						}
						b = 0;
					}
				} else if (gamemode == 9) {
					if ((d == 11)||(d == 10)) {
						d = 0;
						d_up += 10;
					}
					
					if ((b < d+1) || (b > e+1)){
						Sf_od_8[i][j] = 808;
					}
					
					if ((d_up == 1)||(d_up == 11)) {
						d -= 1;
					}
					if ((d_up == 10)||(d_up == 11)) {
						d = 10;
					}
					if (e_down == 1) {
						e += 1;
					}
					d_up = 0;
					e_down = 0;
					b = 0;
				}
			}
		}
	}
	
	return Sf_od_8;
}	//copy

Spielfeld new_life_9 (Spielfeld Sf, unsigned int m, unsigned int n, unsigned int w, unsigned int gamemode, unsigned int* information_code){
	Spielfeld Sf_nl_9;
	unsigned int b, inhi;
	
	Sf_nl_9 = Spielfeld_Create (m, n);
	b = 0;
	inhi = 0;
	
	if (gamemode != 7) {
		for (unsigned int i=1; i<m-1; i+=1){			//Spieler 9
			for (unsigned int j=1; j<n-1; j+=1){
				if ((Sf[i][j] == 0)||(Sf[i][j] == 71)) {	//71 = Trap, only used in survive
					for (unsigned int h=i-1; h<=i+1; h+=1){
						for (unsigned int k=j-1; k<=j+1; k+=1){
							if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
								if (gamemode != 9) {
									if (Sf[h][k] == 9){
										b+=1;
									}
								} else if (gamemode == 9) {
									if (Sf[h][k] == 9){
										b+=1;
									}
									if ((information_code[1] != 0)&&(information_code[1] != 100)&&(Sf[h][k] == information_code[1])&&(information_code[0] != 6)&&(information_code[0] != 5)) {
										inhi += 1;
									}
								}
							}
						}
					}			//w=3, w=2, w=4
					if ((gamemode != 9)&&(gamemode != 10)) {
						if (w == 4){
							if ((b == w) || (b == w+1) ){
								Sf_nl_9[i][j] = 9;
							}
						} else {
							if (b == w){
								Sf_nl_9[i][j] = 9;
							}
						}
						b = 0;
					} else if (gamemode == 9) {
						if (inhi != 3) {
							if (information_code[0] == 1) {
								if (w == 2){
									if ((b == w) || (b == w+1)){
										Sf_nl_9[i][j] = 9;
									}
								} else {
									if (b == w){
										if (w == 1) {
											Sf_nl_9[i][j] = 9;
										} else if (w == 0) {
											for (unsigned int h=i-1; h<=i+1; h+=1){
												for (unsigned int k=j-1; k<=j+1; k+=1){
													if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
														if (Sf[h][k] != 0) {
															inhi = 10;
															break;
														}
													}
												}
												if (inhi == 10) {
													break;
												}
											}
											if (inhi != 10) {
												Sf_nl_9[i][j] = 9;
											}
										}
									}
								}
							} else if (information_code[0] == 2) {
								if (w == 3){
									if ((b == w) || (b == w+1)){
										Sf_nl_9[i][j] = 9;
									}
								} else {
									if (b == w){
										Sf_nl_9[i][j] = 9;
									}
								}
							} else if (information_code[0] == 3) {
								if (w == 5){
									if ((b == w) || (b == w+1)){
										Sf_nl_9[i][j] = 9;
									}
								} else {
									if (b == w){
										Sf_nl_9[i][j] = 9;
									}
								}
							} else if (information_code[0] == 4) {
								if (w == 4){
									if ((b == w) || (b == w+1)){
										Sf_nl_9[i][j] = 9;
									}
								} else {
									if (b == w){
										Sf_nl_9[i][j] = 9;
									}  else if ((b == (w-1))&&((j == (n-2))||(j == 1)||(i == (m-2))||(i == 1))) {
										Sf_nl_9[i][j] = 9;
									}
								}
							} else {
								if (w == 4){
									if ((b == w) || (b == w+1)){
										Sf_nl_9[i][j] = 9;
									}
								} else {
									if (b == w){
										Sf_nl_9[i][j] = 9;
									}
								}
							}
						}
						b = 0;
						inhi = 0;
					} else if (gamemode == 10) {
						if (w == 3){
							if ((b == w) || (b == w+1)){
								Sf_nl_9[i][j] = 9;
							}
						} else {
							if (b == w){
								Sf_nl_9[i][j] = 9;
							}
						}
						b = 0;
					}
					
				}
				
			}
		}
		if ((gamemode == 12)&&(information_code[1] >= 1)) {
			for (unsigned int i=1; i<m-1; i+=1){
				for (unsigned int j=1; j<n-1; j+=1){
					
					if ((Sf[i][j] == 71)&&(Sf_nl_9[i][j] == 9)) {
						Sf[i][j] = 0;
						Sf_nl_9[i][j] = 0;
						Sf[i-1][j] = 0;
						Sf_nl_9[i-1][j] = 0;
						Sf[i+1][j] = 0;
						Sf_nl_9[i+1][j] = 0;
						Sf[i][j-1] = 0;
						Sf_nl_9[i][j-1] = 0;
						Sf[i][j+1] = 0;
						Sf_nl_9[i][j+1] = 0;
						
					}
				}
			}
		}
		
	} else if (gamemode == 7) {		//possible to modify
		for (unsigned int i=(m-1)/2; i<m-1; i+=1){			//Spieler 2
			for (unsigned int j=1; j<n-1; j+=1){
				if (Sf[i][j] == 0) {
					for (unsigned int h=i-1; h<=i+1; h+=1){
						for (unsigned int k=j-1; k<=j+1; k+=1){
							if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
								if (Sf[h][k] == 9){
									b+=1;
								}
							}
						}
					}			//w=3, w=2, w=4
					if(w == 4){
						if ((b == w) || (b == w+1) ){
							Sf_nl_9[i][j] = 9;
						}
					} else {
						if (b == w){
							Sf_nl_9[i][j] = 9;
						}
					}
					b = 0;
				}
			}
		}
	}
	
	
	return Sf_nl_9;
}	//copy

Spielfeld old_dying_9 (Spielfeld Sf, unsigned int m, unsigned int n, unsigned int d, unsigned int e, unsigned int gamemode, unsigned int* information_code){
	Spielfeld Sf_od_9;
	unsigned int b, e_down, d_up;
	
	Sf_od_9 = Spielfeld_Create (m, n);
	b = 0;
	e_down = 0;
	d_up = 0;
	
	for (unsigned int i=1; i<m-1; i+=1){			//Spieler 9
		for (unsigned int j=1; j<n-1; j+=1){
			if (Sf[i][j] == 9) {
				if (gamemode == 9) {
					if ((information_code[2] != 0)&&(information_code[2] != 100)&&(information_code[0] != 7)&&(information_code[0] != 6)) {
						if ((Sf[i+1][j] == information_code[2])||(Sf[i][j-1] == information_code[2])||(Sf[i][j+1] == information_code[2])||(Sf[i-1][j] == information_code[2])) {
							d_up = 1;
							d += 1;
						}
					}
					if ((information_code[3] != 0)&&(information_code[3] != 100)&&(information_code[0] != 8)&&(information_code[0] != 6)) {
						if ((Sf[i+1][j] == information_code[3])||(Sf[i][j-1] == information_code[3])||(Sf[i][j+1] == information_code[3])||(Sf[i-1][j] == information_code[3])) {
							e_down = 1;
							e -= 1;
						}
					}
				}
				for (unsigned int h=i-1; h<=i+1; h+=1){
					for (unsigned int k=j-1; k<=j+1; k+=1){
						if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
							if (Sf[h][k] == 9){
								b+=1;
							}
						}
					}
				}
				if (gamemode != 9) {
					if ((b < d+1) || (b > e+1)){		//d=2, d=1, e=3, e=4
						Sf_od_9[i][j] = 909;		//Code für das Eleminieren
					}
					b = 0;
					
					if ((gamemode == 10)&&(Sf_od_9[i][j] != 909)) {
						for (unsigned int h=i-1; h<=i+1; h+=1){		//Wirt in der Nähe?
							for (unsigned int k=j-1; k<=j+1; k+=1){
								if (Sf[h][k] == 8) {
									b = 1;
									break;
								}
							}
							if (b == 1) {
								break;
							}
						}
						if (b == 0) {
							Sf_od_9[i][j] = 909;		//Code für das Eleminieren
						}
						b = 0;
					}
				} else if (gamemode == 9) {
					if ((d == 11)||(d == 10)) {
						d = 0;
						d_up += 10;
					}
					
					if ((b < d+1) || (b > e+1)){
						Sf_od_9[i][j] = 909;
					}
					
					if ((d_up == 1)||(d_up == 11)) {
						d -= 1;
					}
					if ((d_up == 10)||(d_up == 11)) {
						d = 10;
					}
					if (e_down == 1) {
						e += 1;
					}
					d_up = 0;
					e_down = 0;
					b = 0;
				}
			}
		}
	}
	
	return Sf_od_9;
}	//copy

Spielfeld change_1 (Spielfeld Sf, Spielfeld Sf_nl_1, Spielfeld Sf_od_1, unsigned int m, unsigned int n, unsigned int gamemode, unsigned int number_of_players, unsigned int* ges){	
	
	for (unsigned int i=1; i<m-1; i+=1){			//Spieler 1
		for (unsigned int j=1; j<n-1; j+=1){			
			if (Sf[i][j] == 1){
				if (Sf_od_1[i][j] == 101){
					Sf[i][j] = 0;
					if ((gamemode == 10)&&(number_of_players >= 2)&&(ges[2] != 2020)) {
						Sf[i][j] = 2;
					} else if ((gamemode == 10)&&(number_of_players < 2)&&(ges[1] != 1010)){	//tritt nie ein!
						Sf[i][j] = 1;
					}
				}
			} else if (Sf[i][j] == 0){
				if (Sf_nl_1[i][j] == 1){
					Sf[i][j] = 1;
				}
			} else if ((gamemode == 10)&&(Sf[i][j] == 2)){
				if (Sf_nl_1[i][j] == 1){
					Sf[i][j] = 1;
				}
			}
		}
	}
	
	
	Spielfeld_Destroy (Sf_nl_1, m);
	Spielfeld_Destroy (Sf_od_1, m);
	
	return Sf;
	
}

Spielfeld change_2 (Spielfeld Sf, Spielfeld Sf_nl_2, Spielfeld Sf_od_2, unsigned int m, unsigned int n, unsigned int gamemode, unsigned int number_of_players, unsigned int* ges){
	
	for (unsigned int i=1; i<m-1; i+=1){			//Spieler 2
		for (unsigned int j=1; j<n-1; j+=1){
			if (Sf[i][j] == 2){
				if (Sf_od_2[i][j] == 202){
					Sf[i][j] = 0;
					if ((gamemode == 10)&&(number_of_players >= 3)&&(ges[3] != 3030)) {
						Sf[i][j] = 3;
					} else if ((gamemode == 10)&&(ges[1] != 1010)){
						Sf[i][j] = 1;
					}
				}
			} else if (Sf[i][j] == 0){
				if (Sf_nl_2[i][j] == 2){
					Sf[i][j] = 2;
				}
			}
		}
	}
	Spielfeld_Destroy (Sf_nl_2, m);
	Spielfeld_Destroy (Sf_od_2, m);
	
	return Sf;
}

Spielfeld change_3 (Spielfeld Sf, Spielfeld Sf_nl_3, Spielfeld Sf_od_3, unsigned int m, unsigned int n, unsigned int gamemode, unsigned int number_of_players, unsigned int* ges){
	
	for (unsigned int i=1; i<m-1; i+=1){			//Spieler 3
		for (unsigned int j=1; j<n-1; j+=1){
			if (Sf[i][j] == 3){
				if (Sf_od_3[i][j] == 303){
					Sf[i][j] = 0;
					if ((gamemode == 10)&&(number_of_players >= 4)&&(ges[4] != 4040)) {
						Sf[i][j] = 4;
					} else if ((gamemode == 10)&&(ges[1] != 1010)){
						Sf[i][j] = 1;
					}
				}
			} else if (Sf[i][j] == 0){
				if (Sf_nl_3[i][j] == 3){
					Sf[i][j] = 3;
				}
			}
		}
	}
	Spielfeld_Destroy (Sf_nl_3, m);
	Spielfeld_Destroy (Sf_od_3, m);
	
	return Sf;
}	//copy

Spielfeld change_4 (Spielfeld Sf, Spielfeld Sf_nl_4, Spielfeld Sf_od_4, unsigned int m, unsigned int n, unsigned int gamemode, unsigned int number_of_players, unsigned int* ges){
	
	for (unsigned int i=1; i<m-1; i+=1){			//Spieler 4
		for (unsigned int j=1; j<n-1; j+=1){
			if (Sf[i][j] == 4){
				if (Sf_od_4[i][j] == 404){
					Sf[i][j] = 0;
					if ((gamemode == 10)&&(number_of_players >= 5)&&(ges[5] != 5050)) {
						Sf[i][j] = 5;
					} else if ((gamemode == 10)&&(ges[1] != 1010)){
						Sf[i][j] = 1;
					}
				}
			} else if (Sf[i][j] == 0){
				if (Sf_nl_4[i][j] == 4){
					Sf[i][j] = 4;
				}
			}
		}
	}
	Spielfeld_Destroy (Sf_nl_4, m);
	Spielfeld_Destroy (Sf_od_4, m);
	
	return Sf;
}	//copy

Spielfeld change_5 (Spielfeld Sf, Spielfeld Sf_nl_5, Spielfeld Sf_od_5, unsigned int m, unsigned int n, unsigned int gamemode, unsigned int number_of_players, unsigned int* ges){
	
	for (unsigned int i=1; i<m-1; i+=1){			//Spieler 5
		for (unsigned int j=1; j<n-1; j+=1){
			if (Sf[i][j] == 5){
				if (Sf_od_5[i][j] == 505){
					Sf[i][j] = 0;
					if ((gamemode == 10)&&(number_of_players >= 6)&&(ges[6] != 6060)) {
						Sf[i][j] = 6;
					} else if ((gamemode == 10)&&(ges[1] != 1010)){
						Sf[i][j] = 1;
					}
				}
			} else if (Sf[i][j] == 0){
				if (Sf_nl_5[i][j] == 5){
					Sf[i][j] = 5;
				}
			}
		}
	}
	Spielfeld_Destroy (Sf_nl_5, m);
	Spielfeld_Destroy (Sf_od_5, m);
	
	return Sf;
}	//copy

Spielfeld change_6 (Spielfeld Sf, Spielfeld Sf_nl_6, Spielfeld Sf_od_6, unsigned int m, unsigned int n, unsigned int gamemode, unsigned int number_of_players, unsigned int* ges){
	
	for (unsigned int i=1; i<m-1; i+=1){			//Spieler 6
		for (unsigned int j=1; j<n-1; j+=1){
			if (Sf[i][j] == 6){
				if (Sf_od_6[i][j] == 606){
					Sf[i][j] = 0;
					if ((gamemode == 10)&&(number_of_players >= 7)&&(ges[7] != 7070)) {
						Sf[i][j] = 7;
					} else if ((gamemode == 10)&&(ges[1] != 1010)){
						Sf[i][j] = 1;
					}
				}
			} else if (Sf[i][j] == 0){
				if (Sf_nl_6[i][j] == 6){
					Sf[i][j] = 6;
				}
			}
		}
	}
	Spielfeld_Destroy (Sf_nl_6, m);
	Spielfeld_Destroy (Sf_od_6, m);
	
	return Sf;
}	//copy

Spielfeld change_7 (Spielfeld Sf, Spielfeld Sf_nl_7, Spielfeld Sf_od_7, unsigned int m, unsigned int n, unsigned int gamemode, unsigned int number_of_players, unsigned int* ges){
	
	for (unsigned int i=1; i<m-1; i+=1){			//Spieler 7
		for (unsigned int j=1; j<n-1; j+=1){
			if (Sf[i][j] == 7){
				if (Sf_od_7[i][j] == 707){
					Sf[i][j] = 0;
					if ((gamemode == 10)&&(number_of_players >= 8)&&(ges[8] != 8080)) {
						Sf[i][j] = 8;
					} else if ((gamemode == 10)&&(ges[1] != 1010)){
						Sf[i][j] = 1;
					}
				}
			} else if (Sf[i][j] == 0){
				if (Sf_nl_7[i][j] == 7){
					Sf[i][j] = 7;
				}
			}
		}
	}
	Spielfeld_Destroy (Sf_nl_7, m);
	Spielfeld_Destroy (Sf_od_7, m);
	
	return Sf;
}	//copy

Spielfeld change_8 (Spielfeld Sf, Spielfeld Sf_nl_8, Spielfeld Sf_od_8, unsigned int m, unsigned int n, unsigned int gamemode, unsigned int number_of_players, unsigned int* ges){
	
	for (unsigned int i=1; i<m-1; i+=1){			//Spieler 8
		for (unsigned int j=1; j<n-1; j+=1){
			if (Sf[i][j] == 8){
				if (Sf_od_8[i][j] == 808){
					Sf[i][j] = 0;
					if ((gamemode == 10)&&(number_of_players >= 9)&&(ges[9] != 9090)) {
						Sf[i][j] = 9;
					} else if ((gamemode == 10)&&(ges[1] != 1010)){
						Sf[i][j] = 1;
					}
				}
			} else if (Sf[i][j] == 0){
				if (Sf_nl_8[i][j] == 8){
					Sf[i][j] = 8;
				}
			}
		}
	}
	Spielfeld_Destroy (Sf_nl_8, m);
	Spielfeld_Destroy (Sf_od_8, m);
	
	return Sf;
}	//copy

Spielfeld change_9 (Spielfeld Sf, Spielfeld Sf_nl_9, Spielfeld Sf_od_9, unsigned int m, unsigned int n, unsigned int gamemode, unsigned int number_of_players, unsigned int* ges){
	
	for (unsigned int i=1; i<m-1; i+=1){			//Spieler 9
		for (unsigned int j=1; j<n-1; j+=1){
			if (Sf[i][j] == 9){
				if (Sf_od_9[i][j] == 909){
					Sf[i][j] = 0;
					if ((gamemode == 10)&&(number_of_players >= 10)&&(ges[1] != 1010)) {	//tritt nie ein!
						Sf[i][j] = 0;
					} else if ((gamemode == 10)&&(ges[1] != 1010)){
						Sf[i][j] = 1;
					}
				}
			} else if (Sf[i][j] == 0){
				if (Sf_nl_9[i][j] == 9){
					Sf[i][j] = 9;
				}
			}
		}
	}
	Spielfeld_Destroy (Sf_nl_9, m);
	Spielfeld_Destroy (Sf_od_9, m);
	
	return Sf;
}	//copy

void show_field (Spielfeld Sf, unsigned int m, unsigned int n, unsigned int gamemode, unsigned int* information_code, unsigned int geben, unsigned int* Colored){
	
	printf("\n");
	
	printf("	    ");
	for (unsigned int p=1; p<=n-2; p+=1){		//Nummerierung
		if (p<10){
			printf("%u  ", p);
		} else {
			printf("%u ", p);
		}
	}
	printf("\n");
	
	for (unsigned int i=1; i<m-1; i+=1){		
	
		printf("	   +");
		for (unsigned int t=1; t<=n-2; t+=1){		//Zwischenzeilen
			printf("--+");
		}
		printf("\n");
		
		for (unsigned int v=1; v<=2; v+=1){		//Doppel-Ausführung, ab 10 wird korrigiert, bis 99 gültig
		
			if (i<10){
				printf("	 %u |", i);
			} else {
				printf("	%u |", i);
			}
			for (unsigned int j=1; j<n-1; j+=1){	//Haupzeilen
				if (Sf[i][j] == 0){
					printf("  ");
				} else if (Sf[i][j] == 15){
					if (Colored[0] == 1) {
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+Colored[geben]);
					}
					printf("NN");
				} else if (Sf[i][j] == 16){
					if (Colored[0] == 1) {
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+Colored[geben]);
					}
					printf("D ");
				}
				
				if ((gamemode != 6)&&(gamemode != 9)&&(gamemode != 10)&&(gamemode != 11)&&(gamemode != 12)) {	//mehr-gamemode
					if (Sf[i][j] == 1){
						if (Colored[0] == 1) {
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+Colored[Sf[i][j]]);
						}
						printf("**");
					} else if (Sf[i][j] == 2){
						if (Colored[0] == 1) {
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+Colored[Sf[i][j]]);
						}
						printf("OO");
					} else if (Sf[i][j] == 7){
						printf("##");
					}
				} else if (gamemode == 6) {
					if (Sf[i][j] == 1) {
						if ((geben == 1)||((information_code[3] == 1)&&((Sf[i+1][j] == geben)||(Sf[i-1][j] == geben)||(Sf[i][j+1] == geben)||(Sf[i][j-1] == geben)))||((information_code[1] == 1)&&(information_code[2] == 1))){
							if (Colored[0] == 1) {
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+Colored[Sf[i][j]]);
							}
							printf("##");
						} else {
							printf("  ");
						}
					} else if (Sf[i][j] == 2){
						if (Colored[0] == 1) {
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+Colored[Sf[i][j]]);
						}
						printf("AA");
					} else if (Sf[i][j] == 3){
						if (Colored[0] == 1) {
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+Colored[Sf[i][j]]);
						}
						printf("BB");
					} else if (Sf[i][j] == 4){
						if (Colored[0] == 1) {
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+Colored[Sf[i][j]]);
						}
						printf("CC");
					} else if (Sf[i][j] == 5){
						if (Colored[0] == 1) {
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+Colored[Sf[i][j]]);
						}
						printf("DD");
					} else if (Sf[i][j] == 6){
						if (Colored[0] == 1) {
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+Colored[Sf[i][j]]);
						}
						printf("EE");
					} else if (Sf[i][j] == 7){
						if (Colored[0] == 1) {
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+Colored[Sf[i][j]]);
						}
						printf("GG");
					} else if (Sf[i][j] == 8){
						if (Colored[0] == 1) {
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+Colored[Sf[i][j]]);
						}
						printf("HH");
					} else if (Sf[i][j] == 9){
						if (Colored[0] == 1) {
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+Colored[Sf[i][j]]);
						}
						printf("II");
					} else if (Sf[i][j] == 11){
						if ((geben == 1)||(((information_code[2] == 2)||(information_code[2] == 1))&&(information_code[1] == 1))){
							if (Colored[0] == 1) {
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+Colored[1]);
							}
							printf("~~");
						} else {
							printf("  ");
						}
					} else if (Sf[i][j] == 17){
						printf("::");
					}
				} else if (gamemode == 9) {
					if (Sf[i][j] == geben) {
						if (Colored[0] == 1) {
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+Colored[Sf[i][j]]);
						}
						if (information_code[0] == 1) {
							printf("UU");
						} else if (information_code[0] == 2) {
							printf("LL");
						} else if (information_code[0] == 3) {
							printf("AA");
						} else if (information_code[0] == 4) {
							printf("CC");
						} else if (information_code[0] == 5) {
							printf("II");
						} else if (information_code[0] == 6) {
							printf("SS");
						} else if (information_code[0] == 7) {
							printf("PP");
						} else if (information_code[0] == 8) {
							printf("HH");
						} else if (information_code[0] == 9) {
							printf("EE");
						}
					} else if ((information_code[1] != 0)&&(information_code[1] != 100)&&(Sf[i][j] == information_code[1])) {
						if (Colored[0] == 1) {
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+Colored[Sf[i][j]]);
						}
						printf("II");
					} else if ((information_code[2] != 0)&&(information_code[2] != 100)&&(Sf[i][j] == information_code[2])) {
						if (Colored[0] == 1) {
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+Colored[Sf[i][j]]);
						}
						printf("PP");
					} else if ((information_code[3] != 0)&&(information_code[3] != 100)&&(Sf[i][j] == information_code[3])) {
						if (Colored[0] == 1) {
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+Colored[Sf[i][j]]);
						}
						printf("HH");
					} else if ((Sf[1][0] != 0)&&(Sf[1][0] != 1000)&&(Sf[i][j] == Sf[1][0]/10)) {
						if (Colored[0] == 1) {
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+Colored[Sf[i][j]]);
						}
						printf("UU");
					} else if ((Sf[0][0] != 0)&&(Sf[0][0] != 1000)&&(Sf[i][j] == Sf[0][0]/10)) {
						if (Colored[0] == 1) {
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+Colored[Sf[i][j]]);
						}
						printf("LL");
					} else if ((Sf[0][1] != 0)&&(Sf[0][1] != 1000)&&(Sf[i][j] == Sf[0][1]/10)) {
						if (Colored[0] == 1) {
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+Colored[Sf[i][j]]);
						}
						printf("AA");
					} else if ((Sf[0][n-1] != 0)&&(Sf[0][n-1] != 1000)&&(Sf[i][j] == Sf[0][n-1]/10)) {
						if (Colored[0] == 1) {
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+Colored[Sf[i][j]]);
						}
						printf("CC");
					} else if ((Sf[m-1][n-1] != 0)&&(Sf[m-1][n-1] != 1000)&&(Sf[i][j] == Sf[m-1][n-1]/10)) {
						if (Colored[0] == 1) {
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+Colored[Sf[i][j]]);
						}
						printf("SS");
					} else if ((Sf[m-1][0] != 0)&&(Sf[m-1][0] != 1000)&&(Sf[i][j] == Sf[m-1][0]/10)) {
						if (Colored[0] == 1) {
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+Colored[Sf[i][j]]);
						}
						printf("EE");
					} else if (Sf[i][j] == 17){	//hint
						printf("::");
					}
				} else if (gamemode == 10) {
					for (unsigned int p=1; p<=information_code[0]; p+=1) {	//information_code[0] == number_of_players
						if (Sf[i][j] == p) {
							if (Colored[0] == 1) {
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+Colored[Sf[i][j]]);
							}
							printf("%u%u", p, p);
							break;
						}
					}
					if (Sf[i][j] == 17){	//hint
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+7);
						printf("::");
					}
				} else if (gamemode == 11) {
					if (Sf[i][j] == 77) {
						if (Colored[0] == 1) {
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+6);	//6 --> brown, but it is white
						}
						printf("##");
					} else if (Sf[i][j] == 17){	//hint
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+7);
						printf("::");
					}
					
					for (unsigned int p=1; p<=information_code[0]; p+=1) {	//information_code[0] == number_of_players
						if (Sf[i][j] == p) {
							if (Colored[0] == 1) {
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+Colored[Sf[i][j]]);
							}
							printf("%u%u", p, p);
							break;
						}
					}
					
				} else if (gamemode == 12) {
					if (Sf[i][j] == 71) {	//Trap
						if (Colored[0] == 1) {
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+6);	//6 --> brown, but it is white
						}
						printf("TT");
					} else if (Sf[i][j] == 84) {	//Bomb
						if (Colored[0] == 1) {
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+6);	//6 --> brown, but it is white
						}
						printf("B4");
					} else if (Sf[i][j] == 83) {	//Bomb
						if (Colored[0] == 1) {
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+6);	//6 --> brown, but it is white
						}
						printf("B3");
					} else if (Sf[i][j] == 82) {	//Bomb
						if (Colored[0] == 1) {
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+6);	//6 --> brown, but it is white
						}
						printf("B2");
					} else if (Sf[i][j] == 81) {	//Bomb
						if (Colored[0] == 1) {
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+6);	//6 --> brown, but it is white
						}
						printf("B1");
					} else if (Sf[i][j] == 75) {	//Wave
						if (Colored[0] == 1) {
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+6);	//6 --> brown, but it is white
						}
						printf("WW");
					}
					
					for (unsigned int p=1; p<=information_code[0]; p+=1) {	//information_code[0] == number_of_players
						if (Sf[i][j] == p) {
							if (Colored[0] == 1) {
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+Colored[Sf[i][j]]);
							}
							printf("%u%u", p, p);
							break;
						}
					}
					
				}
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+7);
				printf("|");
			}
		printf(" %u \n", i);
		}
	}
	
	printf("	   +");
	for (unsigned int t=1; t<=n-2; t+=1){		//Endzeile
		printf("--+");
	}
	
	printf("\n");
	printf("	    ");
	for (unsigned int q=1; q<=n-2; q+=1){		//Nummerierung
		if (q<10){
			printf("%u  ", q);
		} else {
			printf("%u ", q);
		}
	}
	printf("\n");
	
	printf("\n");
	
		/*test
		printf("\n");
		printf("	information_code: [0]=%u,	[1]=%u,	[2]=%u,	[3]=%u,	\n", information_code[0], information_code[1], information_code[2], information_code[3]);
		printf("\n");
		*/
}

void Plus (unsigned int m, unsigned int n, unsigned int geben, Spielfeld Sf, unsigned int limit_at_all, unsigned int gamemode, unsigned int* information_code, unsigned int number_of_players, unsigned int* Colored, unsigned int opague, Spielfeld Sf_opague){
	unsigned int a, b;
	unsigned int Zeile, Spalte;
	
	a = 0;
	b = 0;
	
	if ((gamemode == 6)&&(geben == 1)) {
		limit_at_all = (limit_at_all+ 2 *(number_of_players - 3));
	}
	
	for (unsigned int i=1; i<m-1; i+=1){
		for (unsigned int j=1; j<n-1; j+=1){
			if ((geben == 1) && (gamemode == 6)) {
				if ((Sf[i][j] == 1)||(Sf[i][j] == 11)){
					b += 1;
				}
			} else if (Sf[i][j] == geben){
				b += 1;
			}
			
		}
	}
	if ((b >= limit_at_all)&&(gamemode != 3)&&(gamemode != 10)&&(gamemode != 12)){
		printf ("	ERROR\n");		//max. #Steine auf dem Feld
		b = 0;
	} else {
	
		printf(" Zeile: \n Spalte: \n");
		scanf("%u %u", &Zeile, &Spalte);
		
		if ((Zeile == 0)&&(Spalte == 0)){
			printf("	Sweet escape...\n");
		} else {
			
			if (((Zeile<1)||(Zeile>(m-2))) || ((Spalte<1)||(Spalte>n-2))){
				printf("	you made a mistake, try again: \n");
				
				if (opague >= 1) {
					show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
				} else {
					show_field (Sf, m, n, gamemode, information_code, geben, Colored);
				}
				Plus (m, n, geben, Sf, limit_at_all, gamemode, information_code, number_of_players, Colored, opague, Sf_opague);
			}
		
			for (unsigned int h=Zeile-1; h<=Zeile+1; h+=1){			//Lebender in der Nähe?
				for (unsigned int k=Spalte-1; k<=Spalte+1; k+=1){
					if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
						if ((gamemode == 6)&&(geben == 1)) {
							if ((Sf[h][k] == 1)||(Sf[h][k] == 11)){
								a+=1;
							}
						} else if (Sf[h][k] == geben){
							a+=1;
						}
					}
				}
			}
			if (gamemode == 6) {
				if ((a == 0) || (Sf[Zeile][Spalte] != 0)){
					printf ("	Not possible\n");
				} else {
					if (geben == 1) {
						Sf[Zeile][Spalte] = 1;
					} else {
						Sf[Zeile][Spalte] = geben;
					}
				}
			} else if ((gamemode != 10)&&(gamemode != 12)) {
				if ((a == 0) || (Sf[Zeile][Spalte] != 0)){
					printf ("	Not possible\n");
				} else {
					Sf[Zeile][Spalte] = geben;
				}
			} else {
				if (a == 0){
					printf ("	Not possible\n");
				} else {
					Sf[Zeile][Spalte] = geben;
				}
			}
		}
	}
}

void Minus (unsigned int m, unsigned int n, unsigned int geben, Spielfeld Sf, unsigned int gamemode, unsigned int* information_code, unsigned int* Colored, unsigned int opague, Spielfeld Sf_opague){
	unsigned int Zeile, Spalte;
	
	printf(" Zeile: \n Spalte: \n");
	scanf("%u %u", &Zeile, &Spalte);
	
	if ((Zeile == 0)&&(Spalte == 0)){
		printf("	Sweet escape...\n");
	} else {
		
		if (((Zeile<1)||(Zeile>(m-2))) || ((Spalte<1)||(Spalte>n-2))){
			printf("	you made a mistake, try again: \n");
			if (opague >= 1) {
				show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
			} else {
				show_field (Sf, m, n, gamemode, information_code, geben, Colored);
			}
			Minus (m, n, geben, Sf, gamemode, information_code, Colored, opague, Sf_opague);
		}
		
		if (Sf[Zeile][Spalte] != geben){
			printf("	you made a mistake, try again: \n");
			Minus (m, n, geben, Sf, gamemode, information_code, Colored, opague, Sf_opague);
		} else {
			Sf[Zeile][Spalte] = 0;
		}
	}
}

void Move (unsigned int m, unsigned int n, unsigned int geben, Spielfeld Sf, unsigned int gamemode, unsigned int* information_code, unsigned int* Colored, unsigned int opague, Spielfeld Sf_opague){
	unsigned int Zeile_alt, Spalte_alt, Zeile_neu, Spalte_neu;
	unsigned int a, b;
	Spielfeld temp_move;
	
	b = 0;
	for (unsigned int h=1; h<=(m-2); h+=1){
		for (unsigned int k=1; k<=(n-2); k+=1){
			if ((gamemode == 6)&&(geben == 1)) {
				if ((Sf[h][k] == 1)||(Sf[h][k] == 11)){
					if ((Sf[h-1][k]==0)&&((h-1)>=1)){
						b+=1;
					}
					if ((Sf[h][k-1]==0)&&((k-1)>=1)){
						b+=1;
					}
					if ((Sf[h][k+1]==0)&&((k+1)<=(n-2))){
						b+=1;
					}
					if ((Sf[h+1][k]==0)&&((h+1)<=(m-2))){
						b+=1;
					}
				}
			} else if (Sf[h][k] == geben){
				if ((Sf[h-1][k]==0)&&((h-1)>=1)){
					b+=1;
				}
				if ((Sf[h][k-1]==0)&&((k-1)>=1)){
					b+=1;
				}
				if ((Sf[h][k+1]==0)&&((k+1)<=(n-2))){
					b+=1;
				}
				if ((Sf[h+1][k]==0)&&((h+1)<=(m-2))){
					b+=1;
				}
			}
			
			if (b >= 2) {
				break;
			}
			
		}
		
		if (b >= 2) {
			break;
		}
	}
	if (b == 1){
		b = 0;
		for (unsigned int h=1; h<=(m-2); h+=1){
			for (unsigned int k=1; k<=(n-2); k+=1){
				
				if (((Sf[h][k]==11)||(Sf[h][k]==1))&&(gamemode == 6)&&(geben == 1)) {
					if ((Sf[h-1][k]==0)&&((h-1)>=1)){
						b = 1;
						Sf[h-1][k] = 1;
						Sf[h][k] = 0;
						break;
					} else if ((Sf[h][k-1]==0)&&((k-1)>=1)){
						b = 1;
						Sf[h][k-1] = 1;
						Sf[h][k] = 0;
						break;
					} else if ((Sf[h][k+1]==0)&&((k+1)<=(n-2))){
						b = 1;
						Sf[h][k+1] = 1;
						Sf[h][k] = 0;
						break;
					} else if ((Sf[h+1][k]==0)&&((h+1)<=(m-2))){
						b = 1;
						Sf[h+1][k] = 1;
						Sf[h][k] = 0;
						break;
					}
				} else if (Sf[h][k] == geben){
					if ((Sf[h-1][k]==0)&&((h-1)>=1)){
						b = 1;
						Sf[h-1][k] = geben;
						Sf[h][k] = 0;
						break;
					} else if ((Sf[h][k-1]==0)&&((k-1)>=1)){
						b = 1;
						Sf[h][k-1] = geben;
						Sf[h][k] = 0;
						break;
					} else if ((Sf[h][k+1]==0)&&((k+1)<=(n-2))){
						b = 1;
						Sf[h][k+1] = geben;
						Sf[h][k] = 0;
						break;
					} else if ((Sf[h+1][k]==0)&&((h+1)<=(m-2))){
						b = 1;
						Sf[h+1][k] = geben;
						Sf[h][k] = 0;
						break;
					}
				}
				
			}
			if (b == 1){
				break;
			}
		}
		
	} else if (b == 0){
		printf("	No match found, use 100 to correct your mistake \n");
	} else {
	
		temp_move = Spielfeld_Create (m, n);
		
		printf(" alte Zeile: \n alte Spalte: \n");
		scanf("%u %u", &Zeile_alt, &Spalte_alt);
		
		if ((Zeile_alt == 0)&&(Spalte_alt == 0)){
			printf("	Sweet escape...\n");
		} else {
			
			if (((Zeile_alt<1)||(Zeile_alt>(m-2))) || ((Spalte_alt<1)||(Spalte_alt>n-2))){
				printf("	you made a mistake, try again: \n");
				if (opague >= 1) {
					show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
				} else {
					show_field (Sf, m, n, gamemode, information_code, geben, Colored);
				}
				Move (m, n, geben, Sf, gamemode, information_code, Colored, opague, Sf_opague);
				
			}
			
			if ((gamemode == 6)&&(geben == 1)) {
				if ((Sf[Zeile_alt][Spalte_alt] != 1)&&(Sf[Zeile_alt][Spalte_alt] != 11)){
					printf("	you made a mistake, try again: \n");
					Move (m, n, geben, Sf, gamemode, information_code, Colored, opague, Sf_opague);
				} else {
					
					printf(" neue Zeile: \n neue Spalte: \n");
					scanf("%u %u", &Zeile_neu, &Spalte_neu);
					
					if ((Zeile_neu == 0)&&(Spalte_neu == 0)){
						printf("	Sweet escape...\n");
					} else {
					
						if (((Zeile_neu<1)||(Zeile_neu>(m-2))) || ((Spalte_neu<1)||(Spalte_neu>n-2))){
							printf("	you made a mistake, try again: \n");
							if (opague >= 1) {
								show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
							} else {
								show_field (Sf, m, n, gamemode, information_code, geben, Colored);
							}
							Move (m, n, geben, Sf, gamemode, information_code, Colored, opague, Sf_opague);
							
						} else if (Sf[Zeile_alt][Spalte_alt] == 1) {
							temp_move[Zeile_alt][Spalte_alt] = 1;
							a = 0;								//Ursprung in der Nähe?
							if ((temp_move[Zeile_neu-1][Spalte_neu]==1)||(temp_move[Zeile_neu][Spalte_neu-1]==1)||(temp_move[Zeile_neu][Spalte_neu+1]==1)||(temp_move[Zeile_neu+1][Spalte_neu]==1)){
								a = 1;
							}
							if (a == 0){
								printf("	you made a mistake, try again: \n");
								Move (m, n, geben, Sf, gamemode, information_code, Colored, opague, Sf_opague);
							} else if (Sf[Zeile_neu][Spalte_neu] != 0){
								printf("	you made a mistake, try again: \n");
								Move (m, n, geben, Sf, gamemode, information_code, Colored, opague, Sf_opague);
							} else {
								Sf[Zeile_neu][Spalte_neu] = 1;
								Sf[Zeile_alt][Spalte_alt] = 0;
							}
						} else if (Sf[Zeile_alt][Spalte_alt] == 11) {
							temp_move[Zeile_alt][Spalte_alt] = 11;
							a = 0;								//Ursprung in der Nähe?
							if ((temp_move[Zeile_neu-1][Spalte_neu]==11)||(temp_move[Zeile_neu][Spalte_neu-1]==11)||(temp_move[Zeile_neu][Spalte_neu+1]==11)||(temp_move[Zeile_neu+1][Spalte_neu]==11)){
								a = 1;
							}
							if (a == 0){
								printf("	you made a mistake, try again: \n");
								Move (m, n, geben, Sf, gamemode, information_code, Colored, opague, Sf_opague);
							} else if (Sf[Zeile_neu][Spalte_neu] != 0){
								printf("	you made a mistake, try again: \n");
								Move (m, n, geben, Sf, gamemode, information_code, Colored, opague, Sf_opague);
							} else {
								Sf[Zeile_neu][Spalte_neu] = 11;
								Sf[Zeile_alt][Spalte_alt] = 0;
							}
						}
					}
				}
			} else if ((gamemode != 6)||(geben != 1)){
				if (Sf[Zeile_alt][Spalte_alt] != geben){
					printf("	you made a mistake, try again: \n");
					Move (m, n, geben, Sf, gamemode, information_code, Colored, opague, Sf_opague);
				} else {
					
					printf(" neue Zeile: \n neue Spalte: \n");
					scanf("%u %u", &Zeile_neu, &Spalte_neu);
					
					if ((Zeile_neu == 0)&&(Spalte_neu == 0)){
						printf("	Sweet escape...\n");
					} else {
						
						if (((Zeile_neu<1)||(Zeile_neu>(m-2))) || ((Spalte_neu<1)||(Spalte_neu>n-2))){
							printf("	you made a mistake, try again: \n");
							if (opague >= 1) {
								show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
							} else {
								show_field (Sf, m, n, gamemode, information_code, geben, Colored);
							}
							Move (m, n, geben, Sf, gamemode, information_code, Colored, opague, Sf_opague);
							
						} else {
							temp_move[Zeile_alt][Spalte_alt] = geben;
							
							a = 0;								//Ursprung in der Nähe?
							if ((temp_move[Zeile_neu-1][Spalte_neu]==geben)||(temp_move[Zeile_neu][Spalte_neu-1]==geben)||(temp_move[Zeile_neu][Spalte_neu+1]==geben)||(temp_move[Zeile_neu+1][Spalte_neu]==geben)){
								a = 1;
							}
							
							if (a == 0){
								printf("	you made a mistake, try again: \n");
								Move (m, n, geben, Sf, gamemode, information_code, Colored, opague, Sf_opague);
							} else if (Sf[Zeile_neu][Spalte_neu] != 0){
								printf("	you made a mistake, try again: \n");
								Move (m, n, geben, Sf, gamemode, information_code, Colored, opague, Sf_opague);
							} else {
								Sf[Zeile_neu][Spalte_neu] = geben;
								Sf[Zeile_alt][Spalte_alt] = 0;
							}
						}
						
					}
				}
			}
		}
		
		Spielfeld_Destroy (temp_move, m);
	}
}

void Change (unsigned int m, unsigned int n, unsigned int geben, Spielfeld Sf, unsigned int gamemode, unsigned int* information_code, unsigned int* Colored, unsigned int opague, Spielfeld Sf_opague, unsigned int* position){
	unsigned int geben_change, a, b;
	unsigned int eigene_Zeile, fremde_Zeile, eigene_Spalte, fremde_Spalte, heart_Zeile, heart_Spalte, normal_Zeile, normal_Spalte;
	
	b = 0;
	eigene_Zeile = 0;
	fremde_Zeile = 0;
	eigene_Spalte = 0;
	fremde_Spalte = 0;
	heart_Zeile = 0;
	heart_Spalte = 0;
	normal_Zeile = 0;
	normal_Spalte = 0;
	
	if ((gamemode != 6)&&(gamemode != 9)&&(gamemode != 10)&&(gamemode != 11)&&(gamemode != 12)) {	//mehr-gamemode
		geben_change = (geben%2)+1;
	} else if ((gamemode == 6)&&(geben != 1)) {
		geben_change = 1;
	} else if ((gamemode == 6)||(gamemode == 9)||(gamemode == 10)||(gamemode == 11)||(gamemode == 12)) {	//mehr-gamemode
		geben_change = 0;
	}
	
	if ((gamemode == 6)&&(geben == 1)) {
		for (unsigned int h=1; h<=(m-2); h+=1){
			for (unsigned int k=1; k<=(n-2); k+=1){
				if (Sf[h][k] == 11){
					if (Sf[h-1][k]==1){
						b+=1;
					}
					if (Sf[h][k-1]==1){
						b+=1;
					}
					if (Sf[h][k+1]==1){
						b+=1;
					}
					if (Sf[h+1][k]==1){
						b+=1;
					}
					
					if (b >= 2) {
						break;
					}
				}
			}
			if (b >= 2) {
				break;
			}
		}
		
		if (b == 1) {
			b = 0;
			
			for (unsigned int h=1; h<=(m-2); h+=1){
				for (unsigned int k=1; k<=(n-2); k+=1){
					if (Sf[h][k] == 11){
						if (Sf[h-1][k]==1){
							b = 1;
							Sf[h-1][k] = 11;
							Sf[h][k] = 1;
							break;
						} else if (Sf[h][k-1]==1){
							b = 1;
							Sf[h][k-1] = 11;
							Sf[h][k] = 1;
							break;
						} else if (Sf[h][k+1]==1){
							b = 1;
							Sf[h][k+1] = 11;
							Sf[h][k] = 1;
							break;
						} else if (Sf[h+1][k]==1){
							b = 1;
							Sf[h+1][k] = 11;
							Sf[h][k] = 1;
							break;
						}
					}
				}
				if (b == 1){
					break;
				}
			}
			
		} else if (b == 0){
			printf("	No match found, use 100 to correct your mistake \n");
		} else {
			for (unsigned int h=1; h<=(m-2); h+=1){
				for (unsigned int k=1; k<=(n-2); k+=1){
					if (Sf[h][k] == 11) {
						heart_Spalte = k;
						heart_Zeile = h;
						
						if (heart_Spalte != 0) {
							break;
						}
					}
				}
				if (heart_Spalte != 0) {
					break;
				}
			}
			
			a = 0;								//eigener in der Nähe?
			if ((Sf[heart_Zeile-1][heart_Spalte]==1)||(Sf[heart_Zeile][heart_Spalte-1]==1)||(Sf[heart_Zeile][heart_Spalte+1]==1)||(Sf[heart_Zeile+1][heart_Spalte]==1)){
				a = 1;
			}
				
			if (a == 0){
				printf("	it isn't possible, try a move: \n");
				Move (m, n, geben, Sf, gamemode, information_code, Colored, opague, Sf_opague);
			} else {
				
				printf(" normale Zeile: \n normale Spalte: \n");
				scanf("%u %u", &normal_Zeile, &normal_Spalte);
				
				if ((normal_Zeile == 0)&&(normal_Spalte == 0)){
					printf("	Sweet escape...\n");
				} else {
					
					if (((normal_Zeile<1)||(normal_Zeile>(m-2))) || ((normal_Spalte<1)||(normal_Spalte>n-2))){
						printf("	you made a mistake, try again: \n");
						if (opague >= 1) {
							show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
						} else {
							show_field (Sf, m, n, gamemode, information_code, geben, Colored);
						}
						Change (m, n, geben, Sf, gamemode, information_code, Colored, opague, Sf_opague, position);
						
					} else if ((Sf[normal_Zeile][normal_Spalte] != 1)||((abs(normal_Spalte - heart_Spalte) + abs(normal_Zeile - heart_Zeile)) != 1)){
						printf("	you made a mistake, try again: \n");
						Change (m, n, geben, Sf, gamemode, information_code, Colored, opague, Sf_opague, position);
					} else if (((Sf[normal_Zeile+1][normal_Spalte]%10) > 1)||((Sf[normal_Zeile-1][normal_Spalte]%10) > 1)||((Sf[normal_Zeile][normal_Spalte+1]%10) > 1)||((Sf[normal_Zeile][normal_Spalte-1]%10) > 1)) {
						printf("	it isn't possible, try again: \n");
						Change (m, n, geben, Sf, gamemode, information_code, Colored, opague, Sf_opague, position);
					} else {
						Sf[normal_Zeile][normal_Spalte] = 11;
						Sf[heart_Zeile][heart_Spalte] = 1;
					}
				}
			}
		
		}
	}
	
	if ((gamemode == 1)||(gamemode == 2)||(gamemode == 4)||(gamemode == 5)||(gamemode == 7)||((gamemode == 6)&&(geben != 1))) {
		
		for (unsigned int h=1; h<=(m-2); h+=1){
			for (unsigned int k=1; k<=(n-2); k+=1){
				if (Sf[h][k] == geben){
					if (Sf[h-1][k]==geben_change){
						b+=1;
					}
					if (Sf[h][k-1]==geben_change){
						b+=1;
					}
					if (Sf[h][k+1]==geben_change){
						b+=1;
					}
					if (Sf[h+1][k]==geben_change){
						b+=1;
					}
					
					if (b >= 2) {
						break;
					}
				}
			}
			if (b >= 2) {
				break;
			}
		}
	} else if (gamemode == 3) {
	
		for (unsigned int h=1; h<=(m-2); h+=1){
			for (unsigned int k=1; k<=(n-2); k+=1){
				if (Sf[h][k] == geben){
					for (unsigned int u=(h-1); u<=(h+1); u+=1){
						for (unsigned int o=(k-1); o<=(k+1); o+=1){
							if (Sf[u][o] == geben_change){
								b+=1;
							}
							
							if (b >= 2) {
								break;
							}
						}
						if (b >= 2) {
							break;
						}
					}
				}
				if (b >= 2) {
					break;
				}
			}
			if (b >= 2) {
				break;
			}
		}
	} else if (gamemode == 8) {
	
		for (unsigned int h=1; h<=(m-2); h+=1){
			for (unsigned int k=1; k<=(n-2); k+=1){
				if (Sf[h][k] == geben){
					if (Sf[h-1][k]==7){
						b+=1;
					}
					if (Sf[h][k-1]==7){
						b+=1;
					}
					if (Sf[h][k+1]==7){
						b+=1;
					}
					if (Sf[h+1][k]==7){
						b+=1;
					}
					
					if (b >= 2) {
						break;
					}
				}
			}
			if (b >= 2) {
				break;
			}
		}
	} else if ((gamemode == 9)||(gamemode == 10)||(gamemode == 11)||(gamemode == 12)) {	//nur Berechnung, kein Change direkt, mehr-gamemode
		for (unsigned int h=1; h<=(m-2); h+=1){
			for (unsigned int k=1; k<=(n-2); k+=1){
				if (Sf[h][k] == geben){
					if ((Sf[h-1][k] != 0)&&(Sf[h-1][k] != geben)){
						b+=1;
					}
					if ((Sf[h][k-1] != 0)&&(Sf[h][k-1] != geben)){
						b+=1;
					}
					if ((Sf[h+1][k] != 0)&&(Sf[h+1][k] != geben)){
						b+=1;
					}
					if ((Sf[h][k+1] != 0)&&(Sf[h][k+1] != geben)){
						b+=1;
					}
					
					if (b >= 2) {
						break;
					}
				}
			}
			if (b >= 2) {
				break;
			}
		}
	}
	
	if (b == 1){
		b = 0;
		
		if ((gamemode == 1)||(gamemode == 2)||(gamemode == 4)||(gamemode == 5)||(gamemode == 7)||((gamemode == 6)&&(geben != 1))) {
			for (unsigned int h=1; h<=(m-2); h+=1){
				for (unsigned int k=1; k<=(n-2); k+=1){
					if (Sf[h][k] == geben){
						if (Sf[h-1][k]==geben_change){
							b = 1;
							Sf[h-1][k] = geben;
							Sf[h][k] = geben_change;
							break;
						} else if (Sf[h][k-1]==geben_change){
							b = 1;
							Sf[h][k-1] = geben;
							Sf[h][k] = geben_change;
							break;
						} else if (Sf[h][k+1]==geben_change){
							b = 1;
							Sf[h][k+1] = geben;
							Sf[h][k] = geben_change;
							break;
						} else if (Sf[h+1][k]==geben_change){
							b = 1;
							Sf[h+1][k] = geben;
							Sf[h][k] = geben_change;
							break;
						}
					}
				}
				if (b == 1){
					break;
				}
			}
		} else if (gamemode == 3) {
			for (unsigned int h=1; h<=(m-2); h+=1){
				for (unsigned int k=1; k<=(n-2); k+=1){
					if (Sf[h][k] == geben){
						for (unsigned int u=(h-1); u<=(h+1); u+=1){
							for (unsigned int o=(k-1); o<=(k+1); o+=1){
								if (Sf[u][o] == geben_change){
									b = 1;
									Sf[u][o] = geben;
									Sf[h][k] = geben_change;
									break;
								}
							}
							if (b == 1){
								break;
							}
						}
						if (b == 1){
							break;
						}
					}
				}
				if (b == 1){
					break;
				}
			}
		} else if (gamemode == 8) {
			for (unsigned int h=1; h<=(m-2); h+=1){
				for (unsigned int k=1; k<=(n-2); k+=1){
					if (Sf[h][k] == geben){
						if (Sf[h-1][k]==7){
							b = 1;
							Sf[h-1][k] = geben;
							Sf[h][k] = 7;
							break;
						} else if (Sf[h][k-1]==7){
							b = 1;
							Sf[h][k-1] = geben;
							Sf[h][k] = 7;
							break;
						} else if (Sf[h][k+1]==7){
							b = 1;
							Sf[h][k+1] = geben;
							Sf[h][k] = 7;
							break;
						} else if (Sf[h+1][k]==7){
							b = 1;
							Sf[h+1][k] = geben;
							Sf[h][k] = 7;
							break;
						}
					}
				}
				if (b == 1){
					break;
				}
			}
		} else if ((gamemode == 9)||(gamemode == 10)||(gamemode == 12)) {	//mehr-gamemode
			for (unsigned int h=1; h<=(m-2); h+=1){
				for (unsigned int k=1; k<=(n-2); k+=1){
					if (Sf[h][k] == geben){
						if ((Sf[h-1][k] != 0)&&(Sf[h-1][k] != geben)){
							Sf[h][k] = Sf[h-1][k];
							Sf[h-1][k] = geben;
							b = 1;
						}
						if ((Sf[h][k-1] != 0)&&(Sf[h][k-1] != geben)){
							Sf[h][k] = Sf[h][k-1];
							Sf[h][k-1] = geben;
							b = 1;
						}
						if ((Sf[h+1][k] != 0)&&(Sf[h+1][k] != geben)){
							Sf[h][k] = Sf[h+1][k];
							Sf[h+1][k] = geben;
							b = 1;
						}
						if ((Sf[h][k+1] != 0)&&(Sf[h][k+1] != geben)){
							Sf[h][k] = Sf[h][k+1];
							Sf[h][k+1] = geben;
							b = 1;
						}
						
						if (b == 1){
							break;
						}
					}
				}
				if (b == 1){
					break;
				}
			}
		} else if (gamemode == 11) {
			for (unsigned int h=1; h<=(m-2); h+=1){
				for (unsigned int k=1; k<=(n-2); k+=1){
					if (Sf[h][k] == geben){
						if ((Sf[h-1][k] != 0)&&(Sf[h-1][k] != geben)){
							Sf[h][k] = Sf[h-1][k];
							Sf[h-1][k] = geben;
							b = 1;
						}
						if ((Sf[h][k-1] != 0)&&(Sf[h][k-1] != geben)){
							Sf[h][k] = Sf[h][k-1];
							Sf[h][k-1] = geben;
							b = 1;
						}
						if ((Sf[h+1][k] != 0)&&(Sf[h+1][k] != geben)){
							Sf[h][k] = Sf[h+1][k];
							Sf[h+1][k] = geben;
							b = 1;
						}
						if ((Sf[h][k+1] != 0)&&(Sf[h][k+1] != geben)){
							Sf[h][k] = Sf[h][k+1];
							Sf[h][k+1] = geben;
							b = 1;
						}
						
						if (Sf[h][k] == 77) {	//object instead of geben, nach dem change
							position[1] = h;
							position[0] = k;
						}
						
						if (b == 1){
							break;
						}
					}
				}
				if (b == 1){
					break;
				}
			}
		}
		
	} else if (b == 0){
		printf("	No match found, use 100 to correct your mistake \n");
	} else {
	
		printf(" eigene Zeile: \n eigene Spalte: \n");
		scanf("%u %u", &eigene_Zeile, &eigene_Spalte);
		
		if ((eigene_Zeile == 0)&&(eigene_Spalte == 0)){
			printf("	Sweet escape...\n");
		} else {
		
			if (((eigene_Zeile<1)||(eigene_Zeile>(m-2))) || ((eigene_Spalte<1)||(eigene_Spalte>n-2))){
				printf("	you made a mistake, try again: \n");
				if (opague >= 1) {
					show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
				} else {
					show_field (Sf, m, n, gamemode, information_code, geben, Colored);
				}
				Change (m, n, geben, Sf, gamemode, information_code, Colored, opague, Sf_opague, position);
				
			}
			
			if (Sf[eigene_Zeile][eigene_Spalte] != geben){
				printf("	you made a mistake, try again: \n");
				Change (m, n, geben, Sf, gamemode, information_code, Colored, opague, Sf_opague, position);
			} else {
				
				a = 0;								//Feind in der Nähe?
				if ((gamemode == 1)||(gamemode == 2)||(gamemode == 4)||(gamemode == 5)||(gamemode == 6)||(gamemode == 7)) {
					if ((Sf[eigene_Zeile-1][eigene_Spalte]==geben_change)||(Sf[eigene_Zeile][eigene_Spalte-1]==geben_change)||(Sf[eigene_Zeile][eigene_Spalte+1]==geben_change)||(Sf[eigene_Zeile+1][eigene_Spalte]==geben_change)){
						a = 1;
					}
				} else if (gamemode == 3) {
					for (unsigned int h=eigene_Zeile-1; h<=eigene_Zeile+1; h+=1){
						for (unsigned int k=eigene_Spalte-1; k<=eigene_Spalte+1; k+=1){
							if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
								if (Sf[h][k] == geben_change){
									a = 1;
								}
							}
						}
					}
				} else if (gamemode == 8){
					if ((Sf[eigene_Zeile-1][eigene_Spalte]==7)||(Sf[eigene_Zeile][eigene_Spalte-1]==7)||(Sf[eigene_Zeile][eigene_Spalte+1]==7)||(Sf[eigene_Zeile+1][eigene_Spalte]==7)){
						a = 1;
					}
				} else if ((gamemode == 9)||(gamemode == 10)||(gamemode == 11)||(gamemode == 12)) {	//mehr-gamemode
					if (((Sf[eigene_Zeile-1][eigene_Spalte]!=geben)&&(Sf[eigene_Zeile-1][eigene_Spalte]!=0))||((Sf[eigene_Zeile][eigene_Spalte-1]!=geben)&&(Sf[eigene_Zeile][eigene_Spalte-1]!=0))||((Sf[eigene_Zeile][eigene_Spalte+1]!=geben)&&(Sf[eigene_Zeile][eigene_Spalte+1]!=0))||((Sf[eigene_Zeile+1][eigene_Spalte]!=geben)&&(Sf[eigene_Zeile+1][eigene_Spalte]!=0))){
						a = 1;
					}
				}
				
				
				if (a == 0){
					printf("	you made a mistake, try again: \n");
					Change (m, n, geben, Sf, gamemode, information_code, Colored, opague, Sf_opague, position);
				} else {
					
					printf(" fremde Zeile: \n fremde Spalte: \n");
					scanf("%u %u", &fremde_Zeile, &fremde_Spalte);
					
					if ((fremde_Zeile == 0)&&(fremde_Spalte == 0)){
						printf("	Sweet escape...\n");
					} else {
					
						if (((fremde_Zeile<1)||(fremde_Zeile>(m-2))) || ((fremde_Spalte<1)||(fremde_Spalte>n-2))){
							printf("	you made a mistake, try again: \n");
							if (opague >= 1) {
								show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
							} else {
								show_field (Sf, m, n, gamemode, information_code, geben, Colored);
							}
							Change (m, n, geben, Sf, gamemode, information_code, Colored, opague, Sf_opague, position);
							
						}
						
						if ((gamemode != 3)&&(gamemode != 8)&&(gamemode != 9)&&(gamemode != 10)&&(gamemode != 11)&&(gamemode != 12)) {	//mehr-gamemode
							if ((Sf[fremde_Zeile][fremde_Spalte] != geben_change)||(abs(fremde_Spalte-eigene_Spalte)+abs(fremde_Zeile-eigene_Zeile)!= 1)){
								printf("	you made a mistake, try again: \n");
								Change (m, n, geben, Sf, gamemode, information_code, Colored, opague, Sf_opague, position);
							} else {
								Sf[fremde_Zeile][fremde_Spalte] = geben;
								Sf[eigene_Zeile][eigene_Spalte] = geben_change;
							}
						} else if (gamemode == 3) {
							if ((Sf[fremde_Zeile][fremde_Spalte] != geben_change)||(abs(fremde_Spalte-eigene_Spalte)>1)||(abs(fremde_Zeile-eigene_Zeile)>1)){
								printf("	you made a mistake, try again: \n");
								Change (m, n, geben, Sf, gamemode, information_code, Colored, opague, Sf_opague, position);
							} else {
								Sf[fremde_Zeile][fremde_Spalte] = geben;
								Sf[eigene_Zeile][eigene_Spalte] = geben_change;
							}
						} else if (gamemode == 8) {
							if ((Sf[fremde_Zeile][fremde_Spalte] != 7)||(abs(fremde_Spalte-eigene_Spalte)+abs(fremde_Zeile-eigene_Zeile)!= 1)){
								printf("	you made a mistake, try again: \n");
								Change (m, n, geben, Sf, gamemode, information_code, Colored, opague, Sf_opague, position);
							} else {
								Sf[fremde_Zeile][fremde_Spalte] = geben;
								Sf[eigene_Zeile][eigene_Spalte] = 7;
							}
						} else if ((gamemode == 9)||(gamemode == 10)||(gamemode == 12)) {
							if ((Sf[fremde_Zeile][fremde_Spalte] == 0)||(Sf[fremde_Zeile][fremde_Spalte] == geben)||(abs(fremde_Spalte-eigene_Spalte)+abs(fremde_Zeile-eigene_Zeile)!= 1)){
								printf("	you made a mistake, try again: \n");
								Change (m, n, geben, Sf, gamemode, information_code, Colored, opague, Sf_opague, position);
							} else {
								Sf[eigene_Zeile][eigene_Spalte] = Sf[fremde_Zeile][fremde_Spalte];
								Sf[fremde_Zeile][fremde_Spalte] = geben;
							}
						} else if (gamemode == 11) {
							if ((Sf[fremde_Zeile][fremde_Spalte] == 0)||(Sf[fremde_Zeile][fremde_Spalte] == geben)||(abs(fremde_Spalte-eigene_Spalte)+abs(fremde_Zeile-eigene_Zeile)!= 1)){
								printf("	you made a mistake, try again: \n");
								Change (m, n, geben, Sf, gamemode, information_code, Colored, opague, Sf_opague, position);
							} else {
								Sf[eigene_Zeile][eigene_Spalte] = Sf[fremde_Zeile][fremde_Spalte];
								Sf[fremde_Zeile][fremde_Spalte] = geben;
								
								if (Sf[eigene_Zeile][eigene_Spalte] == 77) {	//object instead of geben
									position[1] = eigene_Zeile;
									position[0] = eigene_Spalte;
								}
							}
						}
					}
					
				}
			}
		}
	}
}

void Destroy (unsigned int m, unsigned int n, unsigned int geben, Spielfeld Sf, unsigned int gamemode, unsigned int* information_code, unsigned int* Colored, unsigned int opague, Spielfeld Sf_opague){
	unsigned int geben_destroy, a, b;
	unsigned int fremde_Zeile, fremde_Spalte;
	
	if ((gamemode != 6)&&(gamemode != 9)&&(gamemode != 10)&&(gamemode != 11)&&(gamemode != 12)) {	//mehr-gamemode
		geben_destroy = (geben%2)+1;
	} else if ((gamemode == 6)&&(geben != 1)) {
		geben_destroy = 1;
	} else if ((gamemode == 9)||(gamemode == 10)||(gamemode == 11)||(gamemode == 12)) {
		geben_destroy = 0;
	}
	
	if ((gamemode == 6)&&(geben == 1)) {
		printf(" fremde Zeile: \n fremde Spalte: \n");
		scanf("%u %u", &fremde_Zeile, &fremde_Spalte);
		
		if ((fremde_Zeile == 0)&&(fremde_Spalte == 0)){
			printf("	Sweet escape...\n");
		} else {
			
			if ((Sf[fremde_Zeile][fremde_Spalte] == 0)||(Sf[fremde_Zeile][fremde_Spalte] == 1)||(Sf[fremde_Zeile][fremde_Spalte] == 11)) {
				printf("	you made a mistake, try again: \n");
				Destroy (m, n, geben, Sf, gamemode, information_code, Colored, opague, Sf_opague);
			} else {
				Sf[fremde_Zeile][fremde_Spalte] = 0;
			}
		}
	} else if ((gamemode != 6)||(geben != 1)) {
		
		b = 0;
		if ((gamemode == 1)||(gamemode == 2)||(gamemode == 4)||(gamemode == 5)||(gamemode == 7)||(gamemode == 6)) {
			for (unsigned int h=1; h<=(m-2); h+=1){
				for (unsigned int k=1; k<=(n-2); k+=1){
					if (Sf[h][k] == geben){
						if (Sf[h-1][k]==geben_destroy){
							b+=1;
						}
						if (Sf[h][k-1]==geben_destroy){
							b+=1;
						}
						if (Sf[h][k+1]==geben_destroy){
							b+=1;
						}
						if (Sf[h+1][k]==geben_destroy){
							b+=1;
						}
					}
				}
			}
		} else if (gamemode == 3) {
			for (unsigned int h=1; h<=(m-2); h+=1){
				for (unsigned int k=1; k<=(n-2); k+=1){
					if (Sf[h][k] == geben){
						for (unsigned int u=(h-1); u<=(h+1); u+=1){
							for (unsigned int o=(k-1); o<=(k+1); o+=1){
								if (Sf[u][o] == geben_destroy){
									b+=1;
								}
							}
						}
					}
				}
			}
		} else if (gamemode == 8) {
			for (unsigned int h=1; h<=(m-4); h+=1){
				for (unsigned int k=1; k<=(n-2); k+=1){
					if (Sf[h][k] == geben_destroy){
						b += 1;
					}
				}
			}
		} else if ((gamemode == 9)||(gamemode == 12)) {
			for (unsigned int h=1; h<=(m-2); h+=1){
				for (unsigned int k=1; k<=(n-2); k+=1){
					if (Sf[h][k] == geben){
						if ((Sf[h-1][k] != geben)&&(Sf[h-1][k] != 0)){
							b+=1;
						}
						if ((Sf[h][k-1] != geben)&&(Sf[h][k-1] != 0)){
							b+=1;
						}
						if ((Sf[h][k+1] != geben)&&(Sf[h][k+1] != 0)){
							b+=1;
						}
						if ((Sf[h+1][k] != geben)&&(Sf[h+1][k] != 0)){
							b+=1;
						}
					}
				}
			}
		} else if (gamemode == 10) {
			for (unsigned int h=1; h<=(m-2); h+=1){
				for (unsigned int k=1; k<=(n-2); k+=1){
					if (Sf[h][k] == geben){
						if ((Sf[h-1][k] != geben)&&(Sf[h-1][k] != 0)&&(Sf[h-1][k] != 1)){
							b+=1;
						}
						if ((Sf[h][k-1] != geben)&&(Sf[h][k-1] != 0)&&(Sf[h][k-1] != 1)){
							b+=1;
						}
						if ((Sf[h][k+1] != geben)&&(Sf[h][k+1] != 0)&&(Sf[h][k+1] != 1)){
							b+=1;
						}
						if ((Sf[h+1][k] != geben)&&(Sf[h+1][k] != 0)&&(Sf[h+1][k] != 1)){
							b+=1;
						}
					}
				}
			}
		} else if (gamemode == 11) {
			for (unsigned int h=1; h<=(m-2); h+=1){
				for (unsigned int k=1; k<=(n-2); k+=1){
					if (Sf[h][k] == geben){
						if ((Sf[h-1][k] != geben)&&(Sf[h-1][k] != 0)&&(Sf[h-1][k] != 77)){
							b+=1;
						}
						if ((Sf[h][k-1] != geben)&&(Sf[h][k-1] != 0)&&(Sf[h][k-1] != 77)){
							b+=1;
						}
						if ((Sf[h][k+1] != geben)&&(Sf[h][k+1] != 0)&&(Sf[h][k+1] != 77)){
							b+=1;
						}
						if ((Sf[h+1][k] != geben)&&(Sf[h+1][k] != 0)&&(Sf[h+1][k] != 77)){
							b+=1;
						}
					}
				}
			}
		}
		
		if (b == 1){
			b = 0;
			
			if ((gamemode == 1)||(gamemode == 2)||(gamemode == 4)||(gamemode == 5)||(gamemode == 7)||(gamemode == 6)) {
				for (unsigned int h=1; h<=(m-2); h+=1){
					for (unsigned int k=1; k<=(n-2); k+=1){
						if (Sf[h][k] == geben){
							if (Sf[h-1][k]==geben_destroy){
								b = 1;
								Sf[h-1][k] = 0;
								break;
							} else if (Sf[h][k-1]==geben_destroy){
								b = 1;
								Sf[h][k-1] = 0;
								break;
							} else if (Sf[h][k+1]==geben_destroy){
								b = 1;
								Sf[h][k+1] = 0;
								break;
							} else if (Sf[h+1][k]==geben_destroy){
								b = 1;
								Sf[h+1][k] = 0;
								break;
							}
						}
					}
					if (b == 1){
						break;
					}
				}
			} else if (gamemode == 3) {
				for (unsigned int h=1; h<=(m-2); h+=1){
					for (unsigned int k=1; k<=(n-2); k+=1){
						if (Sf[h][k] == geben){
							for (unsigned int u=(h-1); u<=(h+1); u+=1){
								for (unsigned int o=(k-1); o<=(k+1); o+=1){
									if (Sf[u][o] == geben_destroy){
										b = 1;
										Sf[u][o] = 0;
										break;
									}
								}
								if (b == 1){
									break;
								}
							}
							if (b == 1){
								break;
							}
						}
					}
					if (b == 1){
						break;
					}
				}
			} else if (gamemode == 8) {
				for (unsigned int h=1; h<=(m-4); h+=1){
					for (unsigned int k=1; k<=(n-2); k+=1){
						if (Sf[h][k] == geben_destroy){
							b = 1;
							Sf[h][k] = 0;
							break;
						}
					}
					if (b == 1){
						break;
					}
				}
			} else if ((gamemode == 9)||(gamemode == 12)) {
				for (unsigned int h=1; h<=(m-2); h+=1){
					for (unsigned int k=1; k<=(n-2); k+=1){
						if (Sf[h][k] == geben){
							if ((Sf[h-1][k] != geben)&&(Sf[h-1][k] != 0)){
								b = 1;
								Sf[h-1][k] = 0;
								break;
							}
							if ((Sf[h][k-1] != geben)&&(Sf[h][k-1] != 0)){
								b = 1;
								Sf[h][k-1] = 0;
								break;
							}
							if ((Sf[h][k+1] != geben)&&(Sf[h][k+1] != 0)){
								b = 1;
								Sf[h][k+1] = 0;
								break;
							}
							if ((Sf[h+1][k] != geben)&&(Sf[h+1][k] != 0)){
								b = 1;
								Sf[h+1][k] = 0;
								break;
							}
						}
					}
					if (b == 1){
						break;
					}
				}
			} else if (gamemode == 10) {
				for (unsigned int h=1; h<=(m-2); h+=1){
					for (unsigned int k=1; k<=(n-2); k+=1){
						if (Sf[h][k] == geben){
							if ((Sf[h-1][k] != geben)&&(Sf[h-1][k] != 0)&&(Sf[h-1][k] != 1)){
								b = 1;
								Sf[h-1][k] = 0;
								break;
							}
							if ((Sf[h][k-1] != geben)&&(Sf[h][k-1] != 0)&&(Sf[h][k-1] != 1)){
								b = 1;
								Sf[h][k-1] = 0;
								break;
							}
							if ((Sf[h][k+1] != geben)&&(Sf[h][k+1] != 0)&&(Sf[h][k+1] != 1)){
								b = 1;
								Sf[h][k+1] = 0;
								break;
							}
							if ((Sf[h+1][k] != geben)&&(Sf[h+1][k] != 0)&&(Sf[h+1][k] != 1)){
								b = 1;
								Sf[h+1][k] = 0;
								break;
							}
						}
					}
					if (b == 1){
						break;
					}
				}
			} else if (gamemode == 11) {
				for (unsigned int h=1; h<=(m-2); h+=1){
					for (unsigned int k=1; k<=(n-2); k+=1){
						if (Sf[h][k] == geben){
							if ((Sf[h-1][k] != geben)&&(Sf[h-1][k] != 0)&&(Sf[h-1][k] != 77)){
								b = 1;
								Sf[h-1][k] = 0;
								break;
							}
							if ((Sf[h][k-1] != geben)&&(Sf[h][k-1] != 0)&&(Sf[h][k-1] != 77)){
								b = 1;
								Sf[h][k-1] = 0;
								break;
							}
							if ((Sf[h][k+1] != geben)&&(Sf[h][k+1] != 0)&&(Sf[h][k+1] != 77)){
								b = 1;
								Sf[h][k+1] = 0;
								break;
							}
							if ((Sf[h+1][k] != geben)&&(Sf[h+1][k] != 0)&&(Sf[h+1][k] != 77)){
								b = 1;
								Sf[h+1][k] = 0;
								break;
							}
						}
					}
					if (b == 1){
						break;
					}
				}
			}
			
			
		} else if (b == 0){
			printf("	No match found, use 100 to correct your mistake \n");
		} else {
		
			printf(" fremde Zeile: \n fremde Spalte: \n");
			scanf("%u %u", &fremde_Zeile, &fremde_Spalte);
			
			if ((fremde_Zeile == 0)&&(fremde_Spalte == 0)){
				printf("	Sweet escape...\n");
			} else {
			
				if (((fremde_Zeile<1)||(fremde_Zeile>(m-2))) || ((fremde_Spalte<1)||(fremde_Spalte>n-2))){
					printf("	you made a mistake, try again: \n");
					if (opague >= 1) {
						show_field (Sf_opague, m, n, gamemode, information_code, geben, Colored);
					} else {
						show_field (Sf, m, n, gamemode, information_code, geben, Colored);
					}
					Destroy (m, n, geben, Sf, gamemode, information_code, Colored, opague, Sf_opague);
					
				}
				
				a = 0;								//Eigener in der Nähe?
				if ((gamemode == 1)||(gamemode == 2)||(gamemode == 4)||(gamemode == 5)||(gamemode == 6)||(gamemode == 7)||(gamemode == 9)||(gamemode == 10)||(gamemode == 11)||(gamemode == 12)) {	//mehr-gamemode
					if ((Sf[fremde_Zeile-1][fremde_Spalte]==geben)||(Sf[fremde_Zeile][fremde_Spalte-1]==geben)||(Sf[fremde_Zeile][fremde_Spalte+1]==geben)||(Sf[fremde_Zeile+1][fremde_Spalte]==geben)){
						a = 1;
					}
				} else if (gamemode == 3) {
					for (unsigned int h=fremde_Zeile-1; h<=fremde_Zeile+1; h+=1){
						for (unsigned int k=fremde_Spalte-1; k<=fremde_Spalte+1; k+=1){
							if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
								if (Sf[h][k] == geben){
									a = 1;
								}
							}
						}
					}
				} else if (gamemode == 8) {
					if (fremde_Zeile <= (m-4)){
						a = 1;
					}
				}
					
				if (a == 0){
					printf("	you made a mistake, try again: \n");
					Destroy (m, n, geben, Sf, gamemode, information_code, Colored, opague, Sf_opague);
				} else if ((gamemode != 12)&&(gamemode != 11)&&(gamemode != 10)&&(gamemode != 9)&&(Sf[fremde_Zeile][fremde_Spalte] != geben_destroy)){	//mehr-gamemode
					printf("	you made a mistake, try again: \n");
					Destroy (m, n, geben, Sf, gamemode, information_code, Colored, opague, Sf_opague);
				} else if (((gamemode == 12)||(gamemode == 9))&&((Sf[fremde_Zeile][fremde_Spalte] == 0)||(Sf[fremde_Zeile][fremde_Spalte] == geben))){
					printf("	you made a mistake, try again: \n");
					Destroy (m, n, geben, Sf, gamemode, information_code, Colored, opague, Sf_opague);
				} else if ((gamemode == 10)&&((Sf[fremde_Zeile][fremde_Spalte] == 0)||(Sf[fremde_Zeile][fremde_Spalte] == geben)||(Sf[fremde_Zeile][fremde_Spalte] == 1))){
					printf("	you made a mistake, try again: \n");
					Destroy (m, n, geben, Sf, gamemode, information_code, Colored, opague, Sf_opague);
				} else if ((gamemode == 11)&&((Sf[fremde_Zeile][fremde_Spalte] == 0)||(Sf[fremde_Zeile][fremde_Spalte] == geben)||(Sf[fremde_Zeile][fremde_Spalte] == 77))){
					printf("	you made a mistake, try again: \n");
					Destroy (m, n, geben, Sf, gamemode, information_code, Colored, opague, Sf_opague);
				} else {
					Sf[fremde_Zeile][fremde_Spalte] = 0;
				}
			}
		}
	}
	
}

void Revive_1 (unsigned int m, unsigned int n, Spielfeld Sf_od_1, Spielfeld Sf){
	unsigned int a;
	Spielfeld temp_1;
	
	temp_1 = Spielfeld_Create (m, n);
	a = 0;
	
	for (unsigned int i=1; i<m-1; i+=1){
		for (unsigned int j=1; j<n-1; j+=1){
			if (Sf_od_1[i][j] == 101){
				temp_1[i][j] = 101;
				for (unsigned int h=i-1; h<=i+1; h+=1){
					for (unsigned int k=j-1; k<=j+1; k+=1){
						if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
							if ((Sf[h][k] == 1) && (Sf_od_1[h][k] != 101)){
								a+=1;
							}
						}
					}
				}
				if (a == 0){
					temp_1[i][j] = 0;
				}
				a = 0;
			}
		}
	}
		
	for (unsigned int i=1; i<m-1; i+=1){
		for (unsigned int j=1; j<n-1; j+=1){
			if ((Sf_od_1[i][j] == 101) && (temp_1[i][j] == 0)){
				Sf_od_1[i][j] = 0;
			}
		}
	}
		
	Spielfeld_Destroy (temp_1, m);
}

void Revive_2 (unsigned int m, unsigned int n, Spielfeld Sf_od_2, Spielfeld Sf){
	unsigned int a;
	Spielfeld temp_2;
	
	temp_2 = Spielfeld_Create (m, n);
	a = 0;
	
	for (unsigned int i=1; i<m-1; i+=1){
		for (unsigned int j=1; j<n-1; j+=1){
			if (Sf_od_2[i][j] == 202){
				temp_2[i][j] = 202;
				for (unsigned int h=i-1; h<=i+1; h+=1){
					for (unsigned int k=j-1; k<=j+1; k+=1){
						if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
							if ((Sf[h][k] == 2) && (Sf_od_2[h][k] != 202)){
								a+=1;
							}
						}
					}
				}
				if (a == 0){
					temp_2[i][j] = 0;
				}
				a = 0;
			}
		}
	}
	
	for (unsigned int i=1; i<m-1; i+=1){
		for (unsigned int j=1; j<n-1; j+=1){
			if ((Sf_od_2[i][j] == 202) && (temp_2[i][j] == 0)){
				Sf_od_2[i][j] = 0;
			}
		}
	}
	
	Spielfeld_Destroy (temp_2, m);
}

void Revive_3 (unsigned int m, unsigned int n, Spielfeld Sf_od_3, Spielfeld Sf){
	unsigned int a;
	Spielfeld temp_3;
	
	temp_3 = Spielfeld_Create (m, n);
	a = 0;
	
	for (unsigned int i=1; i<m-1; i+=1){
		for (unsigned int j=1; j<n-1; j+=1){
			if (Sf_od_3[i][j] == 303){
				temp_3[i][j] = 303;
				for (unsigned int h=i-1; h<=i+1; h+=1){
					for (unsigned int k=j-1; k<=j+1; k+=1){
						if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
							if ((Sf[h][k] == 3) && (Sf_od_3[h][k] != 303)){
								a+=1;
							}
						}
					}
				}
				if (a == 0){
					temp_3[i][j] = 0;
				}
				a = 0;
			}
		}
	}
	
	for (unsigned int i=1; i<m-1; i+=1){
		for (unsigned int j=1; j<n-1; j+=1){
			if ((Sf_od_3[i][j] == 303) && (temp_3[i][j] == 0)){
				Sf_od_3[i][j] = 0;
			}
		}
	}
	
	Spielfeld_Destroy (temp_3, m);
}	//copy

void Revive_4 (unsigned int m, unsigned int n, Spielfeld Sf_od_4, Spielfeld Sf){
	unsigned int a;
	Spielfeld temp_4;
	
	temp_4 = Spielfeld_Create (m, n);
	a = 0;
	
	for (unsigned int i=1; i<m-1; i+=1){
		for (unsigned int j=1; j<n-1; j+=1){
			if (Sf_od_4[i][j] == 404){
				temp_4[i][j] = 404;
				for (unsigned int h=i-1; h<=i+1; h+=1){
					for (unsigned int k=j-1; k<=j+1; k+=1){
						if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
							if ((Sf[h][k] == 4) && (Sf_od_4[h][k] != 404)){
								a+=1;
							}
						}
					}
				}
				if (a == 0){
					temp_4[i][j] = 0;
				}
				a = 0;
			}
		}
	}
	
	for (unsigned int i=1; i<m-1; i+=1){
		for (unsigned int j=1; j<n-1; j+=1){
			if ((Sf_od_4[i][j] == 404) && (temp_4[i][j] == 0)){
				Sf_od_4[i][j] = 0;
			}
		}
	}
	
	Spielfeld_Destroy (temp_4, m);
}	//copy

void Revive_5 (unsigned int m, unsigned int n, Spielfeld Sf_od_5, Spielfeld Sf){
	unsigned int a;
	Spielfeld temp_5;
	
	temp_5 = Spielfeld_Create (m, n);
	a = 0;
	
	for (unsigned int i=1; i<m-1; i+=1){
		for (unsigned int j=1; j<n-1; j+=1){
			if (Sf_od_5[i][j] == 505){
				temp_5[i][j] = 505;
				for (unsigned int h=i-1; h<=i+1; h+=1){
					for (unsigned int k=j-1; k<=j+1; k+=1){
						if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
							if ((Sf[h][k] == 5) && (Sf_od_5[h][k] != 505)){
								a+=1;
							}
						}
					}
				}
				if (a == 0){
					temp_5[i][j] = 0;
				}
				a = 0;
			}
		}
	}
	
	for (unsigned int i=1; i<m-1; i+=1){
		for (unsigned int j=1; j<n-1; j+=1){
			if ((Sf_od_5[i][j] == 505) && (temp_5[i][j] == 0)){
				Sf_od_5[i][j] = 0;
			}
		}
	}
	
	Spielfeld_Destroy (temp_5, m);
}	//copy

void Revive_6 (unsigned int m, unsigned int n, Spielfeld Sf_od_6, Spielfeld Sf){
	unsigned int a;
	Spielfeld temp_6;
	
	temp_6 = Spielfeld_Create (m, n);
	a = 0;
	
	for (unsigned int i=1; i<m-1; i+=1){
		for (unsigned int j=1; j<n-1; j+=1){
			if (Sf_od_6[i][j] == 606){
				temp_6[i][j] = 606;
				for (unsigned int h=i-1; h<=i+1; h+=1){
					for (unsigned int k=j-1; k<=j+1; k+=1){
						if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
							if ((Sf[h][k] == 6) && (Sf_od_6[h][k] != 606)){
								a+=1;
							}
						}
					}
				}
				if (a == 0){
					temp_6[i][j] = 0;
				}
				a = 0;
			}
		}
	}
	
	for (unsigned int i=1; i<m-1; i+=1){
		for (unsigned int j=1; j<n-1; j+=1){
			if ((Sf_od_6[i][j] == 606) && (temp_6[i][j] == 0)){
				Sf_od_6[i][j] = 0;
			}
		}
	}
	
	Spielfeld_Destroy (temp_6, m);
}	//copy

void Revive_7 (unsigned int m, unsigned int n, Spielfeld Sf_od_7, Spielfeld Sf){
	unsigned int a;
	Spielfeld temp_7;
	
	temp_7 = Spielfeld_Create (m, n);
	a = 0;
	
	for (unsigned int i=1; i<m-1; i+=1){
		for (unsigned int j=1; j<n-1; j+=1){
			if (Sf_od_7[i][j] == 707){
				temp_7[i][j] = 707;
				for (unsigned int h=i-1; h<=i+1; h+=1){
					for (unsigned int k=j-1; k<=j+1; k+=1){
						if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
							if ((Sf[h][k] == 7) && (Sf_od_7[h][k] != 707)){
								a+=1;
							}
						}
					}
				}
				if (a == 0){
					temp_7[i][j] = 0;
				}
				a = 0;
			}
		}
	}
	
	for (unsigned int i=1; i<m-1; i+=1){
		for (unsigned int j=1; j<n-1; j+=1){
			if ((Sf_od_7[i][j] == 707) && (temp_7[i][j] == 0)){
				Sf_od_7[i][j] = 0;
			}
		}
	}
	
	Spielfeld_Destroy (temp_7, m);
}	//copy

void Revive_8 (unsigned int m, unsigned int n, Spielfeld Sf_od_8, Spielfeld Sf){
	unsigned int a;
	Spielfeld temp_8;
	
	temp_8 = Spielfeld_Create (m, n);
	a = 0;
	
	for (unsigned int i=1; i<m-1; i+=1){
		for (unsigned int j=1; j<n-1; j+=1){
			if (Sf_od_8[i][j] == 808){
				temp_8[i][j] = 808;
				for (unsigned int h=i-1; h<=i+1; h+=1){
					for (unsigned int k=j-1; k<=j+1; k+=1){
						if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
							if ((Sf[h][k] == 8) && (Sf_od_8[h][k] != 808)){
								a+=1;
							}
						}
					}
				}
				if (a == 0){
					temp_8[i][j] = 0;
				}
				a = 0;
			}
		}
	}
	
	for (unsigned int i=1; i<m-1; i+=1){
		for (unsigned int j=1; j<n-1; j+=1){
			if ((Sf_od_8[i][j] == 808) && (temp_8[i][j] == 0)){
				Sf_od_8[i][j] = 0;
			}
		}
	}
	
	Spielfeld_Destroy (temp_8, m);
}	//copy

void Revive_9 (unsigned int m, unsigned int n, Spielfeld Sf_od_9, Spielfeld Sf){
	unsigned int a;
	Spielfeld temp_9;
	
	temp_9 = Spielfeld_Create (m, n);
	a = 0;
	
	for (unsigned int i=1; i<m-1; i+=1){
		for (unsigned int j=1; j<n-1; j+=1){
			if (Sf_od_9[i][j] == 909){
				temp_9[i][j] = 909;
				for (unsigned int h=i-1; h<=i+1; h+=1){
					for (unsigned int k=j-1; k<=j+1; k+=1){
						if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
							if ((Sf[h][k] == 9) && (Sf_od_9[h][k] != 909)){
								a+=1;
							}
						}
					}
				}
				if (a == 0){
					temp_9[i][j] = 0;
				}
				a = 0;
			}
		}
	}
	
	for (unsigned int i=1; i<m-1; i+=1){
		for (unsigned int j=1; j<n-1; j+=1){
			if ((Sf_od_9[i][j] == 909) && (temp_9[i][j] == 0)){
				Sf_od_9[i][j] = 0;
			}
		}
	}
	
	Spielfeld_Destroy (temp_9, m);
}	//copy

void Boost (unsigned int geben, Spielfeld Sf, unsigned int m, unsigned int n, Spielfeld temp, unsigned int gamemode){
	unsigned int geben_Boost;
				//printf("?");
	if ((gamemode != 6)&&(gamemode != 9)&&(gamemode != 10)&&(gamemode != 11)&&(gamemode != 12)) {	//mehr-gamemode
		geben_Boost = (geben%2)+1;
	} else if (gamemode == 6) {
		geben_Boost = 1;
	} else if ((gamemode == 9)||(gamemode == 10)||(gamemode == 11)||(gamemode == 12)) {
		geben_Boost = 0;
	}
	
	
	if ((gamemode == 1)||(gamemode == 2)||(gamemode == 4)||(gamemode == 5)||((gamemode == 6)&&(geben != 1))||(gamemode == 7)) {
		for (unsigned int i=1; i<m-1; i+=1){
			for (unsigned int j=1; j<n-1; j+=1){
				if (Sf[i][j] == geben_Boost) {
					if ((Sf[i-1][j]==geben)||(Sf[i][j-1]==geben)||(Sf[i][j+1]==geben)||(Sf[i+1][j]==geben)){
						temp[i][j] = geben;
					}
				}
			}
		}
	} else if (gamemode == 3) {
		for (unsigned int i=1; i<m-1; i+=1){
			for (unsigned int j=1; j<n-1; j+=1){
				if (Sf[i][j] == geben_Boost) {
					for (unsigned int h=i-1; h<=i+1; h+=1){
						for (unsigned int k=j-1; k<=j+1; k+=1){
							if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
								if (Sf[h][k] == geben){
									temp[i][j] = geben;
								}
							}
						}
					}
				}
			}
		}
	} else if (gamemode == 8) {
		for (unsigned int i=1; i<m-1; i+=1){
			for (unsigned int j=1; j<n-1; j+=1){
				if (Sf[i][j] == 7) {
					if ((Sf[i-1][j]==geben)||(Sf[i][j-1]==geben)||(Sf[i][j+1]==geben)||(Sf[i+1][j]==geben)){
						temp[i][j] = geben;
					}
				}
			}
		}
	} else if ((gamemode == 9)||(gamemode == 10)||(gamemode == 11)||(gamemode == 12)) {	//mehr-gamemode
		for (unsigned int i=1; i<m-1; i+=1){
			for (unsigned int j=1; j<n-1; j+=1){
				if ((Sf[i][j] != geben)&&(Sf[i][j] != 0)) {
					if ((Sf[i-1][j]==geben)||(Sf[i][j-1]==geben)||(Sf[i][j+1]==geben)||(Sf[i+1][j]==geben)){
						temp[i][j] = Sf[i][j];
					}
				}
			}
		}
	}
	
	for (unsigned int i=1; i<m-1; i+=1){
		for (unsigned int j=1; j<n-1; j+=1){
			if ((gamemode != 9)&&(gamemode != 10)&&(gamemode != 11)&&(gamemode != 12)) {	//mehr-gamemode
				if (temp[i][j] == geben){
					Sf[i][j] = geben;
				}
			} else if ((gamemode == 9)||(gamemode == 10)||(gamemode == 11)||(gamemode == 12)) {
				if (temp[i][j] != 0){
					Sf[i][j] = geben;
				}
			}
		}
	}
	
}

Spielfeld Index_1 (unsigned int ent, unsigned int count_new, unsigned int m, unsigned int n, Spielfeld Sf, Spielfeld Sf_nl_1, Spielfeld Sf_od_1, unsigned int limit_new, unsigned int limit_at_all, unsigned int zeitgewinner){
	unsigned int Index_Wert_1, a, b, c, f, ind_1, ind_3, ind, ober;
	Spielfeld Index_1_Feld;
	
	ind = 0;
	f = 0;
	b = 0;
	c = 0;
	a = 0;
	Index_Wert_1 = 0;
	Index_1_Feld = Spielfeld_Create (m, n);
	
	if (zeitgewinner >= limit_at_all) {
		for (unsigned int i=1; i<m-1; i+=1){
			for (unsigned int j=1; j<n-1; j+=1){
				if (Sf_nl_1[i][j] == 1){
					Sf_nl_1[i][j] = 0;
				}
			}
		}
	} else {
		while ((ind != 1)&&(ind != 2)){
			printf (" How do you want to play: \n");
			if (ent == limit_new){
				printf(" #produce	defensive: 1		offensive: 2 \n");
				scanf("%u", &ind_1);
				ind = ind_1;
			}
			
			if (ent >= (limit_at_all - 4)){
				printf(" #reduce	defensive: 1		offensive: 2 \n");
				scanf("%u", &ind_3);
				ind = ind_3;
			}
		}
							//printf("ent: %u \n", ent); printf("\n");
							//printf("ind: %u \n", ind); printf("\n");
							//printf("count_new: %u \n", count_new); printf("\n");
		ober = 80;
		while (count_new > ent){
			for (unsigned int i=1; i<m-1; i+=1){
				for (unsigned int j=1; j<n-1; j+=1){
					if (Sf_nl_1[i][j] == 1){
						
						for (unsigned int h=i-1; h<=i+1; h+=1){		//Stirbt Zelle?
							for (unsigned int k=j-1; k<=j+1; k+=1){
								if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
									if ((Sf_nl_1[h][k] == 1) || ((Sf[h][k] == 1) && (Sf_od_1[h][k] == 0))){
										a+=1;
									}
								}
							}	
						}
						if (a > 4){
							Index_Wert_1 += 3;
																		//printf("1.  %u \n", Index_Wert_1);
						}
						a = 0;
						
						Index_Wert_1 += (8*ind);
						for (unsigned int h=i-1; h<=i+1; h+=1){		//Regeneriert neue Zellen?
							for (unsigned int k=j-1; k<=j+1; k+=1){
								if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
									if (((Sf[h][k] == 0) || ((Sf[h][k] == 1)&&(Sf_od_1[h][k] == 101))) && (Sf_nl_1[h][k] == 0)){
										for (unsigned int u=h-1; u<=h+1; u+=1){
											for (unsigned int o=k-1; o<=k+1; o+=1){
												if ((u>0)&&(u<(m-1))&&(o>0)&&(o<(n-1))){
													if ((Sf_nl_1[u][o] == 1) || ((Sf[u][o] == 1) && (Sf_od_1[u][o] == 0))){
														a += 1;
													}
												}
											}
										}
										if (a == 3){
											Index_Wert_1 -= ind;
																				//printf("2.  %u \n", Index_Wert_1);
										}
										a = 0;
									}
								}
							}
						}
						
						for (unsigned int h=i-1; h<=i+1; h+=1){		//Stört feindliches Wachstum?
							for (unsigned int k=j-1; k<=j+1; k+=1){
								if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
									if (Sf[h][k] == 2){
										a+=1;
									}
								}
							}	
						}
						if (a != 3){
							Index_Wert_1 += 10;
																	//printf("3.  %u \n", Index_Wert_1);
						}
						a = 0;
						
						for (unsigned int h=i-1; h<=i+1; h+=1){		//Regeneriert ihr Tod neue Zellen?
							for (unsigned int k=j-1; k<=j+1; k+=1){
								if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
									if (((Sf[h][k] == 0) || ((Sf[h][k] == 1)&&(Sf_od_1[h][k] == 101))) && (Sf_nl_1[h][k] == 0)){
										for (unsigned int u=h-1; u<=h+1; u+=1){
											for (unsigned int o=k-1; o<=k+1; o+=1){
												if ((u>0)&&(u<(m-1))&&(o>0)&&(o<(n-1))){
													if ((Sf_nl_1[u][o] == 1) || ((Sf[u][o] == 1) && (Sf_od_1[u][o] == 0))){
														a += 1;
													}
												}
											}
										}
										if (a == 4){
											Index_Wert_1 += ind;
																				//printf("4.  %u \n", Index_Wert_1);
										} 
										a = 0;
										
									}
								}
							}
						}
						
						for (unsigned int h=i-1; h<=i+1; h+=1){		//sterben eigene Zellen?
							for (unsigned int k=j-1; k<=j+1; k+=1){
								if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
									if (((Sf[h][k] == 1) && (Sf_od_1[h][k] == 0)) ||(Sf_nl_1[h][k] == 1)){
										for (unsigned int u=h-1; u<=h+1; u+=1){
											for (unsigned int o=k-1; o<=k+1; o+=1){
												if ((u>0)&&(u<(m-1))&&(o>0)&&(o<(n-1))){
													if ((Sf_nl_1[u][o] == 1) || ((Sf[u][o] == 1) && (Sf_od_1[u][o] == 0))){
														a += 1;
													}
												}
											}
										}
										if (a > 4){
											Index_Wert_1 += 3;
																				//printf("5.  %u \n", Index_Wert_1);
										}
										a = 0;
									}
								}
							}
						}
						
						for (unsigned int h=i-1; h<=i+1; h+=1){		//tötet ihr Tod eigene Zellen?
							for (unsigned int k=j-1; k<=j+1; k+=1){
								if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
									if (((Sf[h][k] == 1) && (Sf_od_1[h][k] == 0)) ||(Sf_nl_1[h][k] == 1)){
										for (unsigned int u=h-1; u<=h+1; u+=1){
											for (unsigned int o=k-1; o<=k+1; o+=1){
												if ((u>0)&&(u<(m-1))&&(o>0)&&(o<(n-1))){
													if ((Sf_nl_1[u][o] == 1) || ((Sf[u][o] == 1) && (Sf_od_1[u][o] == 0))){
														a += 1;
													}
												}
											}
										}
										if (a < 4){
											b = 1;
										}
										a = 0;
									}
								}
							}
						}
						if (b != 1){
							Index_Wert_1 += 10;
																	//printf("6.  %u \n", Index_Wert_1);
						} 
						b = 0;
						
						if (i == m-2){
							Index_Wert_1 = 1;
						}
																			//printf("7.  %u \n", Index_Wert_1);  printf("\n");
						Index_1_Feld[i][j] = Index_Wert_1;
						Index_Wert_1 = 0;
					}
				}
			}
			//printf("\n");
			
			if (ind == 2){
				for (unsigned int i=1; i<m-1; i+=1){
					if (c == 1){
						break;
					}
					for (unsigned int j=1; j<n-1; j+=1){
						if (Index_1_Feld[i][j] == ober){
							Index_1_Feld[i][j] = 0;
							Sf_nl_1[i][j] = 0;
							count_new -= 1;
							ober = 80;
							c = 1;
							break;
						}
					}
				}
				if (c == 0){
					ober -= 1;
				}
			}
			
			if (ind == 1) {
				for (unsigned int i=m-2; i>0; i-=1){
					if (c == 1){
						break;
					}
					for (unsigned int j=n-2; j>0; j-=1){
						if (Index_1_Feld[i][j] == ober){
							Index_1_Feld[i][j] = 0;
							Sf_nl_1[i][j] = 0;
							count_new -= 1;
							ober = 80;
							c = 1;
							break;
						}
					}
				}
				if (c == 0){
					ober -= 1;
				}
			}
			
			c = 0;
															//printf("ent: %u \n", ent); printf("\n");
															//printf("ind: %u \n", ind); printf("\n");
															//printf("count_new: %u \n", count_new); printf("\n");
			
			for (unsigned int t=1; t<m-1; t+=1){
				if (f == 1){
					break;
				}
				for (unsigned int z=1; z<n-1; z+=1){
					if (Sf_nl_1[t][z] == 1){
						f = 1;
						break;
					}
				}
			}
			if (f == 0){
				break;
			}
			f = 0;
		}		//zu viele generiert, da Index_field[i][j] nicht zurückgesetzt, daher count_new mehrfach reduziert.
	
	}
	
	Spielfeld_Destroy (Index_1_Feld, m);
	
	return Sf_nl_1;
}

Spielfeld Index_2 (unsigned int ent, unsigned int count_new, unsigned int m, unsigned int n, Spielfeld Sf, Spielfeld Sf_nl_2, Spielfeld Sf_od_2, unsigned int limit_new, unsigned int limit_at_all, unsigned int zeitgewinner){
	unsigned int Index_Wert_2, a, b, c, f, ind_2, ind_4, ind, ober;
	Spielfeld Index_2_Feld;		//mehr als Limit-Steine auf dem Feld, Problem analysieren und beheben!
	
	ind = 0;
	c = 0;
	f = 0;
	b = 0;
	a = 0;
	Index_Wert_2 = 0;
	Index_2_Feld = Spielfeld_Create (m, n);
	
	if (zeitgewinner >= limit_at_all) {
		for (unsigned int i=1; i<m-1; i+=1){
			for (unsigned int j=1; j<n-1; j+=1){
				if (Sf_nl_2[i][j] == 2){
					Sf_nl_2[i][j] = 0;
				}
			}
		}
	} else {
		while ((ind != 1)&&(ind != 2)){
			printf (" How do you want to play: \n");
			if (ent == limit_new){
				printf(" #produce	defensive: 1		offensive: 2 \n");
				scanf("%u", &ind_2);
				ind = ind_2;
			}
			
			if (ent >= (limit_at_all - 4)){
				printf(" #reduce	defensive: 1		offensive: 2 \n");
				scanf("%u", &ind_4);
				ind = ind_4;
			}
		}
		
		ober = 80;
		while (count_new > ent){
			for (unsigned int i=1; i<m-1; i+=1){
				for (unsigned int j=1; j<n-1; j+=1){
					if (Sf_nl_2[i][j] == 2){
						
						for (unsigned int h=i-1; h<=i+1; h+=1){		//Stirbt Zelle?
							for (unsigned int k=j-1; k<=j+1; k+=1){
								if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
									if ((Sf_nl_2[h][k] == 2) || ((Sf[h][k] == 2) && (Sf_od_2[h][k] == 0))){
										a+=1;
									}
								}
							}	
						}
						if (a > 4){
							Index_Wert_2 += 3;
						}
						a = 0;
						
						Index_Wert_2 += (8*ind);
						for (unsigned int h=i-1; h<=i+1; h+=1){		//Regeneriert neue Zellen?
							for (unsigned int k=j-1; k<=j+1; k+=1){
								if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
									if (((Sf[h][k] == 0) || ((Sf[h][k] == 2)&&(Sf_od_2[h][k] == 202))) && (Sf_nl_2[h][k] == 0)){
										for (unsigned int u=h-1; u<=h+1; u+=1){
											for (unsigned int o=k-1; o<=k+1; o+=1){
												if ((u>0)&&(u<(m-1))&&(o>0)&&(o<(n-1))){
													if ((Sf_nl_2[u][o] == 2) || ((Sf[u][o] == 2) && (Sf_od_2[u][o] == 0))){
														a += 1;
													}
												}
											}
										}
										if (a == 3){
											Index_Wert_2 -= ind;
										}
										a = 0;
									}
								}
							}
						}
						
						for (unsigned int h=i-1; h<=i+1; h+=1){		//Stört feindliches Wachstum?
							for (unsigned int k=j-1; k<=j+1; k+=1){
								if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
									if (Sf[h][k] == 1){
										a+=1;
									}
								}
							}	
						}
						if (a != 3){
							Index_Wert_2 += 10;
						}
						a = 0;
						
						for (unsigned int h=i-1; h<=i+1; h+=1){		//Regeneriert ihr Tod neue Zellen?
							for (unsigned int k=j-1; k<=j+1; k+=1){
								if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
									if (((Sf[h][k] == 0) || ((Sf[h][k] == 2)&&(Sf_od_2[h][k] == 202))) && (Sf_nl_2[h][k] == 0)){
										for (unsigned int u=h-1; u<=h+1; u+=1){
											for (unsigned int o=k-1; o<=k+1; o+=1){
												if ((u>0)&&(u<(m-1))&&(o>0)&&(o<(n-1))){
													if ((Sf_nl_2[u][o] == 2) || ((Sf[u][o] == 2) && (Sf_od_2[u][o] == 0))){
														a += 1;
													}
												}
											}
										}
										if (a == 4){
											Index_Wert_2 += ind;
										} 
										a = 0;
										
									}
								}
							}
						}
						
						for (unsigned int h=i-1; h<=i+1; h+=1){		//sterben eigene Zellen?
							for (unsigned int k=j-1; k<=j+1; k+=1){
								if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
									if (((Sf[h][k] == 2) && (Sf_od_2[h][k] == 0)) ||(Sf_nl_2[h][k] == 2)){
										for (unsigned int u=h-1; u<=h+1; u+=1){
											for (unsigned int o=k-1; o<=k+1; o+=1){
												if ((u>0)&&(u<(m-1))&&(o>0)&&(o<(n-1))){
													if ((Sf_nl_2[u][o] == 2) || ((Sf[u][o] == 2) && (Sf_od_2[u][o] == 0))){
														a += 1;
													}
												}
											}
										}
										if (a > 4){
											Index_Wert_2 += 3;
										}
										a = 0;
									}
								}
							}
						}
						
						for (unsigned int h=i-1; h<=i+1; h+=1){		//tötet ihr Tod eigene Zellen?
							for (unsigned int k=j-1; k<=j+1; k+=1){
								if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
									if (((Sf[h][k] == 2) && (Sf_od_2[h][k] == 0)) ||(Sf_nl_2[h][k] == 2)){
										for (unsigned int u=h-1; u<=h+1; u+=1){
											for (unsigned int o=k-1; o<=k+1; o+=1){
												if ((u>0)&&(u<(m-1))&&(o>0)&&(o<(n-1))){
													if ((Sf_nl_2[u][o] == 2) || ((Sf[u][o] == 2) && (Sf_od_2[u][o] == 0))){
														a += 1;
													}
												}
											}
										}
										if (a < 4){
											b = 1;
										}
										a = 0;							
									}
								}
							}
						}
						if (b != 1){
							Index_Wert_2 += 10;
						} 
						b = 0;
						
						if (i == 1){
							Index_Wert_2 = 1;
						}
						
						Index_2_Feld[i][j] = Index_Wert_2;
						Index_Wert_2 = 0;
					}
				}
			}
			
			
			if (ind == 1){
				for (unsigned int i=1; i<m-1; i+=1){
					if (c == 1){
						break;
					}
					for (unsigned int j=1; j<n-1; j+=1){
						if (Index_2_Feld[i][j] == ober){
							Index_2_Feld[i][j] = 0;
							Sf_nl_2[i][j] = 0;
							count_new -= 1;
							ober = 80;
							c = 1;
							break;
						}
					}
				}
				if (c == 0){
					ober -= 1;
				}
			} 
				
			if (ind == 2) {
				for (unsigned int i=m-2; i>0; i-=1){
					if (c == 1){
						break;
					}
					for (unsigned int j=n-2; j>0; j-=1){
						if (Index_2_Feld[i][j] == ober){
							Index_2_Feld[i][j] = 0;
							Sf_nl_2[i][j] = 0;
							count_new -= 1;
							ober = 80;
							c = 1;
							break;
						}
					}
				}
				if (c == 0){
					ober -= 1;
				}
			}
			c = 0;
			for (unsigned int t=1; t<m-1; t+=1){
				if (f == 1){
					break;
				}
				for (unsigned int z=1; z<n-1; z+=1){
					if (Sf_nl_2[t][z] == 2){
						f = 1;
						break;
					}
				}
			}
			if (f == 0){
				break;
			}
			f = 0;
		}
	}
		
	Spielfeld_Destroy (Index_2_Feld, m);
	
	return Sf_nl_2;
}

Spielfeld Index_1_col (unsigned int ent, unsigned int count_new, unsigned int m, unsigned int n, Spielfeld Sf, Spielfeld Sf_nl_1, Spielfeld Sf_od_1, unsigned int limit_new, unsigned int limit_at_all, unsigned int zeitgewinner){
	unsigned int Index_Wert_1, a, b, c, f, ind_1, ind_3, ind, ober;
	Spielfeld Index_1_Feld;
	
	ind = 0;
	f = 0;
	b = 0;
	c = 0;
	a = 0;
	Index_Wert_1 = 0;
	Index_1_Feld = Spielfeld_Create (m, n);
	
	if (zeitgewinner >= limit_at_all) {
		for (unsigned int i=1; i<m-1; i+=1){
			for (unsigned int j=1; j<n-1; j+=1){
				if (Sf_nl_1[i][j] == 1){
					Sf_nl_1[i][j] = 0;
				}
			}
		}
	} else {
		while ((ind != 1)&&(ind != 2)){
			printf (" Where do you want to keep them: \n");
			if (ent == limit_new){
				printf(" #produce	top: 1		bottom: 2 \n");
				scanf("%u", &ind_1);
				ind = ind_1;
			}
			
			if (ent >= (limit_at_all - 4)){
				printf(" #reduce	top: 1		bottom: 2 \n");
				scanf("%u", &ind_3);
				ind = ind_3;
			}
		}
															//printf("%u \n", ent); printf("\n");
															//printf("%u \n", ind); printf("\n");
															//printf("%u \n", count_new); printf("\n");
		ober = 85;
		while (count_new > ent){
			for (unsigned int i=1; i<m-1; i+=1){
				for (unsigned int j=1; j<n-1; j+=1){
					if (Sf_nl_1[i][j] == 1){
						
						for (unsigned int h=i-1; h<=i+1; h+=1){		//Stirbt Zelle?
							for (unsigned int k=j-1; k<=j+1; k+=1){
								if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
									if ((Sf_nl_1[h][k] == 1) || ((Sf[h][k] == 1) && (Sf_od_1[h][k] == 0))){
										a+=1;
									}
								}
							}	
						}
						if (a > 4){
							Index_Wert_1 += 3;
																		//printf("1.  %u \n", Index_Wert_1);
						}
						a = 0;
						
						Index_Wert_1 += 8;
						for (unsigned int h=i-1; h<=i+1; h+=1){		//Regeneriert neue Zellen?
							for (unsigned int k=j-1; k<=j+1; k+=1){
								if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
									if (((Sf[h][k] == 0) || ((Sf[h][k] == 1)&&(Sf_od_1[h][k] == 101))) && (Sf_nl_1[h][k] == 0)){
										for (unsigned int u=h-1; u<=h+1; u+=1){
											for (unsigned int o=k-1; o<=k+1; o+=1){
												if ((u>0)&&(u<(m-1))&&(o>0)&&(o<(n-1))){
													if ((Sf_nl_1[u][o] == 1) || ((Sf[u][o] == 1) && (Sf_od_1[u][o] == 0))){
														a += 1;
													}
												}
											}
										}
										if (a == 3){
											Index_Wert_1 -= 1;
																				//printf("2.  %u \n", Index_Wert_1);
										}
										a = 0;
									}
								}
							}
						}
						
						for (unsigned int h=i-1; h<=i+1; h+=1){		//Stört feindliches Wachstum?
							for (unsigned int k=j-1; k<=j+1; k+=1){
								if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
									if (Sf[h][k] == 2){
										a+=1;
									}
								}
							}	
						}
						if (a != 3){
							Index_Wert_1 += 10;
																	//printf("3.  %u \n", Index_Wert_1);
						}
						a = 0;
						
						for (unsigned int h=i-1; h<=i+1; h+=1){		//Regeneriert ihr Tod neue Zellen?
							for (unsigned int k=j-1; k<=j+1; k+=1){
								if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
									if (((Sf[h][k] == 0) || ((Sf[h][k] == 1)&&(Sf_od_1[h][k] == 101))) && (Sf_nl_1[h][k] == 0)){
										for (unsigned int u=h-1; u<=h+1; u+=1){
											for (unsigned int o=k-1; o<=k+1; o+=1){
												if ((u>0)&&(u<(m-1))&&(o>0)&&(o<(n-1))){
													if ((Sf_nl_1[u][o] == 1) || ((Sf[u][o] == 1) && (Sf_od_1[u][o] == 0))){
														a += 1;
													}
												}
											}
										}
										if (a == 4){
											Index_Wert_1 += 1;
																				//printf("4.  %u \n", Index_Wert_1);
										} 
										a = 0;
										
									}
								}
							}
						}
						
						for (unsigned int h=i-1; h<=i+1; h+=1){		//sterben eigene Zellen?
							for (unsigned int k=j-1; k<=j+1; k+=1){
								if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
									if (((Sf[h][k] == 1) && (Sf_od_1[h][k] == 0)) ||(Sf_nl_1[h][k] == 1)){
										for (unsigned int u=h-1; u<=h+1; u+=1){
											for (unsigned int o=k-1; o<=k+1; o+=1){
												if ((u>0)&&(u<(m-1))&&(o>0)&&(o<(n-1))){
													if ((Sf_nl_1[u][o] == 1) || ((Sf[u][o] == 1) && (Sf_od_1[u][o] == 0))){
														a += 1;
													}
												}
											}
										}
										if (a > 4){
											Index_Wert_1 += 3;
																				//printf("5.  %u \n", Index_Wert_1);
										}
										a = 0;
									}
								}
							}
						}
						
						for (unsigned int h=i-1; h<=i+1; h+=1){		//tötet ihr Tod eigene Zellen?
							for (unsigned int k=j-1; k<=j+1; k+=1){
								if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
									if (((Sf[h][k] == 1) && (Sf_od_1[h][k] == 0)) ||(Sf_nl_1[h][k] == 1)){
										for (unsigned int u=h-1; u<=h+1; u+=1){
											for (unsigned int o=k-1; o<=k+1; o+=1){
												if ((u>0)&&(u<(m-1))&&(o>0)&&(o<(n-1))){
													if ((Sf_nl_1[u][o] == 1) || ((Sf[u][o] == 1) && (Sf_od_1[u][o] == 0))){
														a += 1;
													}
												}
											}
										}
										if (a < 4){
											b = 1;
										}
										a = 0;
									}
								}
							}
						}
						if (b != 1){
							Index_Wert_1 += 10;
																	//printf("6.  %u \n", Index_Wert_1);
						} 
						b = 0;
						
						if (ind == 1) {
							Index_Wert_1 += i;
						}
						if (ind == 2) {
							Index_Wert_1 += (6-i);
						}
						
						if ((i >= (m-3)/2)&&(i <= (m+1)/2)){
							Index_Wert_1 = 2;
						}
						
						if ((Sf[i-1][j]==7)||(Sf[i+1][j]==7)||(Sf[i][j-1]==7)||(Sf[i][j+1]==7)){
							Index_Wert_1 = 1;
						}
																			//printf("7.  %u \n", Index_Wert_1);  printf("\n");
						Index_1_Feld[i][j] = Index_Wert_1;
						Index_Wert_1 = 0;
					}
				}
			}
			//printf("\n");
			
			if (ind == 2){
				for (unsigned int i=1; i<m-1; i+=1){
					if (c == 1){
						break;
					}
					for (unsigned int j=1; j<n-1; j+=1){
						if (Index_1_Feld[i][j] == ober){
							Index_1_Feld[i][j] = 0;
							Sf_nl_1[i][j] = 0;
							count_new -= 1;
							ober = 85;
							c = 1;
							break;
						}
					}
				}
				if (c == 0){
					ober -= 1;
				}
			}
			
			if (ind == 1) {
				for (unsigned int i=m-2; i>0; i-=1){
					if (c == 1){
						break;
					}
					for (unsigned int j=n-2; j>0; j-=1){
						if (Index_1_Feld[i][j] == ober){
							Index_1_Feld[i][j] = 0;
							Sf_nl_1[i][j] = 0;
							count_new -= 1;
							ober = 85;
							c = 1;
							break;
						}
					}
				}
				if (c == 0){
					ober -= 1;
				}
			}
			c = 0;
			for (unsigned int t=1; t<m-1; t+=1){
				if (f == 1){
					break;
				}
				for (unsigned int z=1; z<n-1; z+=1){
					if (Sf_nl_1[t][z] == 1){
						f = 1;
						break;
					}
				}
			}
			if (f == 0){
				break;
			}
			f = 0;
		}
	}
	
	Spielfeld_Destroy (Index_1_Feld, m);
	
	return Sf_nl_1;
}

Spielfeld Index_2_col (unsigned int ent, unsigned int count_new, unsigned int m, unsigned int n, Spielfeld Sf, Spielfeld Sf_nl_2, Spielfeld Sf_od_2, unsigned int limit_new, unsigned int limit_at_all, unsigned int zeitgewinner){
	unsigned int Index_Wert_2, a, b, c, f, ind_2, ind_4, ind, ober;
	Spielfeld Index_2_Feld;
	
	ind = 0;
	f = 0;
	b = 0;
	c = 0;
	a = 0;
	Index_Wert_2 = 0;
	Index_2_Feld = Spielfeld_Create (m, n);
	
	if (zeitgewinner >= limit_at_all) {
		for (unsigned int i=1; i<m-1; i+=1){
			for (unsigned int j=1; j<n-1; j+=1){
				if (Sf_nl_2[i][j] == 2){
					Sf_nl_2[i][j] = 0;
				}
			}
		}
	} else {
		while ((ind != 1)&&(ind != 2)){
			printf (" Where do you want to keep them: \n");
			if (ent == limit_new){
				printf(" #produce	bottom: 1		top: 2 \n");
				scanf("%u", &ind_2);
				ind = ind_2;
			}
			
			if (ent >= (limit_at_all - 4)){
				printf(" #reduce	bottom: 1		top: 2 \n");
				scanf("%u", &ind_4);
				ind = ind_4;
			}
		}
		
		ober = 85;
		while (count_new > ent){
			for (unsigned int i=1; i<m-1; i+=1){
				for (unsigned int j=1; j<n-1; j+=1){
					if (Sf_nl_2[i][j] == 2){
						
						for (unsigned int h=i-1; h<=i+1; h+=1){		//Stirbt Zelle?
							for (unsigned int k=j-1; k<=j+1; k+=1){
								if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
									if ((Sf_nl_2[h][k] == 2) || ((Sf[h][k] == 2) && (Sf_od_2[h][k] == 0))){
										a+=1;
									}
								}
							}	
						}
						if (a > 4){
							Index_Wert_2 += 3;
															//if (ober == 80){printf("%u \n", Index_Wert_2);}
						}
						a = 0;
						
						Index_Wert_2 += 8;
						for (unsigned int h=i-1; h<=i+1; h+=1){		//Regeneriert neue Zellen?
							for (unsigned int k=j-1; k<=j+1; k+=1){
								if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
									if (((Sf[h][k] == 0) || ((Sf[h][k] == 2)&&(Sf_od_2[h][k] == 202))) && (Sf_nl_2[h][k] == 0)){
										for (unsigned int u=h-1; u<=h+1; u+=1){
											for (unsigned int o=k-1; o<=k+1; o+=1){
												if ((u>0)&&(u<(m-1))&&(o>0)&&(o<(n-1))){
													if ((Sf_nl_2[u][o] == 2) || ((Sf[u][o] == 2) && (Sf_od_2[u][o] == 0))){
														a += 1;
													}
												}
											}
										}
										if (a == 3){
											Index_Wert_2 -= 1;
															//if (ober == 80){printf("%u	 \n", Index_Wert_2);}
										}
										a = 0;
									}
								}
							}
						}
						
						for (unsigned int h=i-1; h<=i+1; h+=1){		//Stört feindliches Wachstum?
							for (unsigned int k=j-1; k<=j+1; k+=1){
								if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
									if (Sf[h][k] == 1){
										a+=1;
									}
								}
							}	
						}
						if (a != 3){
							Index_Wert_2 += 10;
															//if (ober == 80){printf("%u \n", Index_Wert_2);}
						}
						a = 0;
						
						for (unsigned int h=i-1; h<=i+1; h+=1){		//Regeneriert ihr Tod neue Zellen?
							for (unsigned int k=j-1; k<=j+1; k+=1){
								if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
									if (((Sf[h][k] == 0) || ((Sf[h][k] == 2)&&(Sf_od_2[h][k] == 202))) && (Sf_nl_2[h][k] == 0)){
										for (unsigned int u=h-1; u<=h+1; u+=1){
											for (unsigned int o=k-1; o<=k+1; o+=1){
												if ((u>0)&&(u<(m-1))&&(o>0)&&(o<(n-1))){
													if ((Sf_nl_2[u][o] == 2) || ((Sf[u][o] == 2) && (Sf_od_2[u][o] == 0))){
														a += 1;
													}
												}
											}
										}
										if (a == 4){
											Index_Wert_2 += 1;
															//if (ober == 80){printf("%u \n", Index_Wert_2);}
										} 
										a = 0;
										
									}
								}
							}
						}
						
						for (unsigned int h=i-1; h<=i+1; h+=1){		//sterben eigene Zellen?
							for (unsigned int k=j-1; k<=j+1; k+=1){
								if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
									if (((Sf[h][k] == 2) && (Sf_od_2[h][k] == 0)) ||(Sf_nl_2[h][k] == 2)){
										for (unsigned int u=h-1; u<=h+1; u+=1){
											for (unsigned int o=k-1; o<=k+1; o+=1){
												if ((u>0)&&(u<(m-1))&&(o>0)&&(o<(n-1))){
													if ((Sf_nl_2[u][o] == 2) || ((Sf[u][o] == 2) && (Sf_od_2[u][o] == 0))){
														a += 1;
													}
												}
											}
										}
										if (a > 4){
											Index_Wert_2 += 3;
															//if (ober == 80){printf("%u	 \n", Index_Wert_2);}
										}
										a = 0;
									}
								}
							}
						}
						
						for (unsigned int h=i-1; h<=i+1; h+=1){		//tötet ihr Tod eigene Zellen?
							for (unsigned int k=j-1; k<=j+1; k+=1){
								if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
									if (((Sf[h][k] == 2) && (Sf_od_2[h][k] == 0)) ||(Sf_nl_2[h][k] == 2)){
										for (unsigned int u=h-1; u<=h+1; u+=1){
											for (unsigned int o=k-1; o<=k+1; o+=1){
												if ((u>0)&&(u<(m-1))&&(o>0)&&(o<(n-1))){
													if ((Sf_nl_2[u][o] == 2) || ((Sf[u][o] == 2) && (Sf_od_2[u][o] == 0))){
														a += 1;
													}
												}
											}
										}
										if (a < 4){
											b = 1;
										}
										a = 0;							
									}
								}
							}
						}
						if (b != 1){
							Index_Wert_2 += 10;
															//if (ober == 80){printf("%u \n", Index_Wert_2);}
						}
						b = 0;
						
						if (ind == 2) {
							Index_Wert_2 += i;
						}
						if (ind == 1) {
							Index_Wert_2 += (6-i);
						}
						
						if ((i >= (m-3)/2)&&(i <= (m+1)/2)){
							Index_Wert_2 = 2;
						}
						
						if ((Sf[i-1][j]==7)||(Sf[i+1][j]==7)||(Sf[i][j-1]==7)||(Sf[i][j+1]==7)){
							Index_Wert_2 = 1;
						}
															//if (ober == 80){printf("%u	%u	%u \n", Index_Wert_2, i, j);}

						Index_2_Feld[i][j] = Index_Wert_2;
						Index_Wert_2 = 0;
					}
				}
			}
			
			
			if (ind == 1){
				for (unsigned int i=1; i<m-1; i+=1){
					if (c == 1){
						break;
					}
					for (unsigned int j=1; j<n-1; j+=1){
						if (Index_2_Feld[i][j] == ober){
							Index_2_Feld[i][j] = 0;
							Sf_nl_2[i][j] = 0;
							count_new -= 1;
							ober = 85;
							c = 1;
							break;
						}
					}
				}
				if (c == 0){
					ober -= 1;
				}
							//löscht nur einmal einen bestimmten Indexwert, nicht zweimal!!!!!!
									//printf("ober: %u \n", ober);

			}
			
			if (ind == 2) {
				for (unsigned int i=m-2; i>0; i-=1){
					if (c == 1){
						break;
					}
					for (unsigned int j=n-2; j>0; j-=1){
						if (Index_2_Feld[i][j] == ober){
							Index_2_Feld[i][j] = 0;
							Sf_nl_2[i][j] = 0;
							count_new -= 1;
							ober = 85;
							c = 1;
							break;
						}
					}
				}
				if (c == 0){
					ober -= 1;
				}
			}
			c = 0;
			for (unsigned int t=1; t<m-1; t+=1){
				if (f == 1){
					break;
				}
				for (unsigned int z=1; z<n-1; z+=1){
					if (Sf_nl_2[t][z] == 2){
						f = 1;
						break;
					}
				}
			}
			if (f == 0){
				break;
			}
			f = 0;
		}
	}
	
	Spielfeld_Destroy (Index_2_Feld, m);
	
	return Sf_nl_2;
}

Spielfeld Index_1_con (unsigned int ent, unsigned int count_new, unsigned int m, unsigned int n, Spielfeld Sf, Spielfeld Sf_nl_1, unsigned int limit_new){
	unsigned int Index_Wert_1, ind, ober, c, f;
	Spielfeld Index_1_Feld;
	
	ind = 0;
	c = 0;
	f = 0;
	Index_Wert_1 = 0;
	Index_1_Feld = Spielfeld_Create (m, n);

	while ((ind != 1)&&(ind != 2)&&(ind != 3)&&(ind != 4)){
		printf (" Where do you want to keep them: \n");
		if (ent == limit_new){
			printf(" #produce	top: 1		bottom: 2 	left: 3 	right: 4 \n");
			scanf("%u", &ind);
		}
	}
	
	ober = m+n;
	
	while (count_new > ent){
		for (unsigned int i=1; i<m-1; i+=1){
			for (unsigned int j=1; j<n-1; j+=1){
				if (Sf_nl_1[i][j] == 1){
					if (ind == 1){
						Index_Wert_1 = i;
					}
					if (ind == 2){
						Index_Wert_1 = (m-1)-i;
					}
					if (ind == 4){
						Index_Wert_1 = (n-1)-j;
					}
					if (ind == 3){
						Index_Wert_1 = j;
					}
					
					for (unsigned int h=i-1; h<=i+1; h+=1){
						for (unsigned int k=j-1; k<=j+1; k+=1){
							if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
								if (Sf[h][k] == 2){
									Index_Wert_1 = 1;
								}
							}
						}
					}
					
					Index_1_Feld[i][j] = Index_Wert_1;
					Index_Wert_1 = 0;
				}
			}
		}
		
		
		for (unsigned int i=1; i<m-1; i+=1){
			if (c == 1){
				break;
			}
			for (unsigned int j=(n-2); j>0; j-=1){
				if (Index_1_Feld[i][j] == ober){
					Index_1_Feld[i][j] = 0;
					Sf_nl_1[i][j] = 0;
					count_new -= 1;
					ober = m+n;
					c = 1;
					break;
				}
			}
		}
		if (c == 0){
			ober -= 1;
		}
		c = 0;
		
		for (unsigned int t=1; t<m-1; t+=1){
			if (f == 1){
				break;
			}
			for (unsigned int z=1; z<n-1; z+=1){
				if (Sf_nl_1[t][z] == 1){
					f = 1;
					break;
				}
			}
		}
		if (f == 0){
			break;
		}
		f = 0;
	}
	
	
	Spielfeld_Destroy (Index_1_Feld, m);
	
	return Sf_nl_1;
}

Spielfeld Index_2_con (unsigned int ent, unsigned int count_new, unsigned int m, unsigned int n, Spielfeld Sf, Spielfeld Sf_nl_2, unsigned int limit_new){
	unsigned int Index_Wert_2, ind, ober, c, f;
	Spielfeld Index_2_Feld;
	
	ind = 0;
	f = 0;
	c = 0;
	Index_Wert_2 = 0;
	Index_2_Feld = Spielfeld_Create (m, n);
	
	while ((ind != 1)&&(ind != 2)&&(ind != 3)&&(ind != 4)){
		printf (" Where do you want to keep them: \n");
		if (ent == limit_new){
			printf(" #produce	top: 1		bottom: 2 	left: 3 	right: 4 \n");
			scanf("%u", &ind);
		}
	}
	ober = m+n;
	
	while (count_new > ent){
		for (unsigned int i=1; i<m-1; i+=1){
			for (unsigned int j=1; j<n-1; j+=1){
				if (Sf_nl_2[i][j] == 2){
					if (ind == 1){
						Index_Wert_2 = i;
					}
					if (ind == 2){
						Index_Wert_2 = (m-1)-i;
					}
					if (ind == 4){
						Index_Wert_2 = (n-1)-j;
					}
					if (ind == 3){
						Index_Wert_2 = j;
					}
					
					for (unsigned int h=i-1; h<=i+1; h+=1){
						for (unsigned int k=j-1; k<=j+1; k+=1){
							if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
								if (Sf[h][k] == 1){
									Index_Wert_2 = 1;
								}
							}
						}
					}
					
					Index_2_Feld[i][j] = Index_Wert_2;
					Index_Wert_2 = 0;
				}
			}
		}
	
		for (unsigned int i=1; i<m-1; i+=1){
			if (c == 1){
				break;
			}
			for (unsigned int j=1; j<n-1; j+=1){
				if (Index_2_Feld[i][j] == ober){
					Index_2_Feld[i][j] = 0;
					Sf_nl_2[i][j] = 0;
					count_new -= 1;
					ober = m+n;
					c = 1;
					break;
				}
			}
		}
		if (c == 0){
			ober -= 1;
		}
		c = 0;
		
		for (unsigned int t=1; t<m-1; t+=1){
			if (f == 1){
				break;
			}
			for (unsigned int z=1; z<n-1; z+=1){
				if (Sf_nl_2[t][z] == 2){
					f = 1;
					break;
				}
			}
		}
		if (f == 0){
			break;
		}
		f = 0;
	}
	
	
	Spielfeld_Destroy (Index_2_Feld, m);
	
	return Sf_nl_2;
}

Spielfeld Index_1_fal (unsigned int ent, unsigned int count_new, unsigned int m, unsigned int n, Spielfeld Sf, Spielfeld Sf_nl_1, Spielfeld Sf_od_1, unsigned int limit_new, unsigned int limit_at_all, unsigned int zeitgewinner){
	unsigned int Index_Wert_1, a, b, c, f, ind_1, ind_3, ind, ober;
	Spielfeld Index_1_Feld;
	
	ind = 0;
	f = 0;
	b = 0;
	c = 0;
	a = 0;
	Index_Wert_1 = 0;
	Index_1_Feld = Spielfeld_Create (m, n);
	
	if (zeitgewinner >= limit_at_all) {
		for (unsigned int i=1; i<m-1; i+=1){
			for (unsigned int j=1; j<n-1; j+=1){
				if (Sf_nl_1[i][j] == 1){
					Sf_nl_1[i][j] = 0;
				}
			}
		}
	} else {
		while ((ind != 1)&&(ind != 2)){
			printf (" Where do you want to keep them: \n");
			if (ent == limit_new){
				printf(" #produce	top: 1		bottom: 2 \n");
				scanf("%u", &ind_1);
				ind = ind_1;
			}
			
			if (ent >= (limit_at_all - 4)){
				printf(" #reduce	top: 1		bottom: 2 \n");
				scanf("%u", &ind_3);
				ind = ind_3;
			}
		}
															//printf("%u \n", ent); printf("\n");
															//printf("%u \n", ind); printf("\n");
															//printf("%u \n", count_new); printf("\n");
		ober = 80;
		while (count_new > ent){
			for (unsigned int i=1; i<m-1; i+=1){
				for (unsigned int j=1; j<n-1; j+=1){
					if (Sf_nl_1[i][j] == 1){
						
						for (unsigned int h=i-1; h<=i+1; h+=1){		//Stirbt Zelle?
							for (unsigned int k=j-1; k<=j+1; k+=1){
								if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
									if ((Sf_nl_1[h][k] == 1) || ((Sf[h][k] == 1) && (Sf_od_1[h][k] == 0))){
										a+=1;
									}
								}
							}	
						}
						if (a > 4){
							Index_Wert_1 += 3;
															//if (ober == 70){printf("%u \n", Index_Wert_1);}	//test
						}
						a = 0;
						
						for (unsigned int h=i-1; h<=i+1; h+=1){		//Regeneriert neue Zellen?
							for (unsigned int k=j-1; k<=j+1; k+=1){
								if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
									if (((Sf[h][k] == 0) || ((Sf[h][k] == 1)&&(Sf_od_1[h][k] == 101))) && (Sf_nl_1[h][k] == 0)){
										for (unsigned int u=h-1; u<=h+1; u+=1){
											for (unsigned int o=k-1; o<=k+1; o+=1){
												if ((u>0)&&(u<(m-1))&&(o>0)&&(o<(n-1))){
													if ((Sf_nl_1[u][o] == 1) || ((Sf[u][o] == 1) && (Sf_od_1[u][o] == 0))){
														a += 1;
													}
												}
											}
										}
										if (a != 3){
											Index_Wert_1 += 1;
															//if (ober == 70){printf("%u \n", Index_Wert_1);}	//test
										}
										a = 0;
									}
								}
							}
						}
						
						
						for (unsigned int h=i-1; h<=i+1; h+=1){		//Regeneriert ihr Tod neue Zellen?
							for (unsigned int k=j-1; k<=j+1; k+=1){
								if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
									if (((Sf[h][k] == 0) || ((Sf[h][k] == 1)&&(Sf_od_1[h][k] == 101))) && (Sf_nl_1[h][k] == 0)){
										for (unsigned int u=h-1; u<=h+1; u+=1){
											for (unsigned int o=k-1; o<=k+1; o+=1){
												if ((u>0)&&(u<(m-1))&&(o>0)&&(o<(n-1))){
													if ((Sf_nl_1[u][o] == 1) || ((Sf[u][o] == 1) && (Sf_od_1[u][o] == 0))){
														a += 1;
													}
												}
											}
										}
										if (a == 4){
											Index_Wert_1 += 1;
															//if (ober == 70){printf("%u \n", Index_Wert_1);}	//test
										} 
										a = 0;
										
									}
								}
							}
						}
						
						for (unsigned int h=i-1; h<=i+1; h+=1){		//sterben eigene Zellen?
							for (unsigned int k=j-1; k<=j+1; k+=1){
								if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
									if (((Sf[h][k] == 1) && (Sf_od_1[h][k] == 0)) ||(Sf_nl_1[h][k] == 1)){
										for (unsigned int u=h-1; u<=h+1; u+=1){
											for (unsigned int o=k-1; o<=k+1; o+=1){
												if ((u>0)&&(u<(m-1))&&(o>0)&&(o<(n-1))){
													if ((Sf_nl_1[u][o] == 1) || ((Sf[u][o] == 1) && (Sf_od_1[u][o] == 0))){
														a += 1;
													}
												}
											}
										}
										if (a > 4){
											Index_Wert_1 += 3;
															//if (ober == 70){printf("%u \n", Index_Wert_1);}	//test
										}
										a = 0;
									}
								}
							}
						}
						
						for (unsigned int h=i-1; h<=i+1; h+=1){		//tötet ihr Tod eigene Zellen?
							for (unsigned int k=j-1; k<=j+1; k+=1){
								if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
									if (((Sf[h][k] == 1) && (Sf_od_1[h][k] == 0)) ||(Sf_nl_1[h][k] == 1)){
										for (unsigned int u=h-1; u<=h+1; u+=1){
											for (unsigned int o=k-1; o<=k+1; o+=1){
												if ((u>0)&&(u<(m-1))&&(o>0)&&(o<(n-1))){
													if ((Sf_nl_1[u][o] == 1) || ((Sf[u][o] == 1) && (Sf_od_1[u][o] == 0))){
														a += 1;
													}
												}
											}
										}
										if (a < 4){
											b = 1;
										}
										a = 0;
									}
								}
							}
						}
						if (b != 1){
							Index_Wert_1 += 10;
															//if (ober == 70){printf("%u \n", Index_Wert_1);}	//test
						} 
						b = 0;
						
						if (ind == 1) {
							Index_Wert_1 += i;
						}
						if (ind == 2) {
							Index_Wert_1 += (6-i);
						}
						
						if ((Sf[i-1][j]==7)||(Sf[i][j-1]==7)||(Sf[i+1][j]==7)){
							Index_Wert_1 = 1;
						}
						
								//if (ober == 70){printf("%u	%u	%u \n", Index_Wert_1, i, j);}
						
						Index_1_Feld[i][j] = Index_Wert_1;
						Index_Wert_1 = 0;
					}
				}
			}
			//printf("\n");
			
			if (ind == 2){
				for (unsigned int i=1; i<m-1; i+=1){
					if (c == 1){
						break;
					}
					for (unsigned int j=1; j<n-1; j+=1){
						if (Index_1_Feld[i][j] == ober){
							Index_1_Feld[i][j] = 0;
							Sf_nl_1[i][j] = 0;
							count_new -= 1;
							ober = 80;
							c = 1;
							break;
						}
					}
				}
				if (c == 0){
					ober -= 1;
				}
			}
			
			if (ind == 1) {
				for (unsigned int i=m-2; i>0; i-=1){
					if (c == 1){
						break;
					}
					for (unsigned int j=n-2; j>0; j-=1){
						if (Index_1_Feld[i][j] == ober){
							Index_1_Feld[i][j] = 0;
							Sf_nl_1[i][j] = 0;
							count_new -= 1;
							ober = 80;
							c = 1;
							break;
						}
					}
				}
				if (c == 0){
					ober -= 1;
				}
			}
			c = 0;
			for (unsigned int t=1; t<m-1; t+=1){
				if (f == 1){
					break;
				}
				for (unsigned int z=1; z<n-1; z+=1){
					if (Sf_nl_1[t][z] == 1){
						f = 1;
						break;
					}
				}
			}
			if (f == 0){
				break;
			}
			f = 0;
		}
	}
	
	Spielfeld_Destroy (Index_1_Feld, m);
	
	return Sf_nl_1;
}

Spielfeld Index_2_fal (unsigned int ent, unsigned int count_new, unsigned int m, unsigned int n, Spielfeld Sf, Spielfeld Sf_nl_2, Spielfeld Sf_od_2, unsigned int limit_new, unsigned int limit_at_all, unsigned int zeitgewinner){
	unsigned int Index_Wert_2, a, b, c, f, ind_2, ind_4, ind, ober;
	Spielfeld Index_2_Feld;
	
	ind = 0;
	f = 0;
	a = 0;
	b = 0;
	c = 0;
	Index_Wert_2 = 0;
	Index_2_Feld = Spielfeld_Create (m, n);
	
	if (zeitgewinner >= limit_at_all) {
		for (unsigned int i=1; i<m-1; i+=1){
			for (unsigned int j=1; j<n-1; j+=1){
				if (Sf_nl_2[i][j] == 2){
					Sf_nl_2[i][j] = 0;
				}
			}
		}
	} else {
		while ((ind != 1)&&(ind != 2)){
			printf (" Where do you want to keep them: \n");
			if (ent == limit_new){
				printf(" #produce	bottom: 1		top: 2 \n");
				scanf("%u", &ind_2);
				ind = ind_2;
			}
			
			if (ent >= (limit_at_all - 4)){
				printf(" #reduce	bottom: 1		top: 2 \n");
				scanf("%u", &ind_4);
				ind = ind_4;
			}
		}
		
		ober = 80;
		while (count_new > ent){
			for (unsigned int i=1; i<m-1; i+=1){
				for (unsigned int j=1; j<n-1; j+=1){
					if (Sf_nl_2[i][j] == 2){
						
						for (unsigned int h=i-1; h<=i+1; h+=1){		//Stirbt Zelle?
							for (unsigned int k=j-1; k<=j+1; k+=1){
								if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
									if ((Sf_nl_2[h][k] == 2) || ((Sf[h][k] == 2) && (Sf_od_2[h][k] == 0))){
										a+=1;
									}
								}
							}	
						}
						if (a > 4){
							Index_Wert_2 += 3;
													//if (ober == 70){printf("%u \n", Index_Wert_2);}
						}
						a = 0;
						
						for (unsigned int h=i-1; h<=i+1; h+=1){		//Regeneriert neue Zellen?
							for (unsigned int k=j-1; k<=j+1; k+=1){
								if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
									if (((Sf[h][k] == 0) || ((Sf[h][k] == 2)&&(Sf_od_2[h][k] == 202))) && (Sf_nl_2[h][k] == 0)){
										for (unsigned int u=h-1; u<=h+1; u+=1){
											for (unsigned int o=k-1; o<=k+1; o+=1){
												if ((u>0)&&(u<(m-1))&&(o>0)&&(o<(n-1))){
													if ((Sf_nl_2[u][o] == 2) || ((Sf[u][o] == 2) && (Sf_od_2[u][o] == 0))){
														a += 1;
													}
												}
											}
										}
										if (a != 3){
											Index_Wert_2 += 1;
													//if (ober == 70){printf("%u \n", Index_Wert_2);}
										}
										a = 0;
									}
								}
							}
						}
						
						
						for (unsigned int h=i-1; h<=i+1; h+=1){		//Regeneriert ihr Tod neue Zellen?
							for (unsigned int k=j-1; k<=j+1; k+=1){
								if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
									if (((Sf[h][k] == 0) || ((Sf[h][k] == 2)&&(Sf_od_2[h][k] == 202))) && (Sf_nl_2[h][k] == 0)){
										for (unsigned int u=h-1; u<=h+1; u+=1){
											for (unsigned int o=k-1; o<=k+1; o+=1){
												if ((u>0)&&(u<(m-1))&&(o>0)&&(o<(n-1))){
													if ((Sf_nl_2[u][o] == 2) || ((Sf[u][o] == 2) && (Sf_od_2[u][o] == 0))){
														a += 1;
													}
												}
											}
										}
										if (a == 4){
											Index_Wert_2 += 1;
													//if (ober == 70){printf("%u \n", Index_Wert_2);}
										} 
										a = 0;
										
									}
								}
							}
						}
						
						for (unsigned int h=i-1; h<=i+1; h+=1){		//sterben eigene Zellen?
							for (unsigned int k=j-1; k<=j+1; k+=1){
								if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
									if (((Sf[h][k] == 2) && (Sf_od_2[h][k] == 0)) ||(Sf_nl_2[h][k] == 2)){
										for (unsigned int u=h-1; u<=h+1; u+=1){
											for (unsigned int o=k-1; o<=k+1; o+=1){
												if ((u>0)&&(u<(m-1))&&(o>0)&&(o<(n-1))){
													if ((Sf_nl_2[u][o] == 2) || ((Sf[u][o] == 2) && (Sf_od_2[u][o] == 0))){
														a += 1;
													}
												}
											}
										}
										if (a > 4){
											Index_Wert_2 += 3;
													//if (ober == 70){printf("%u \n", Index_Wert_2);}
										}
										a = 0;
									}
								}
							}
						}
						
						for (unsigned int h=i-1; h<=i+1; h+=1){		//tötet ihr Tod eigene Zellen?
							for (unsigned int k=j-1; k<=j+1; k+=1){
								if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
									if (((Sf[h][k] == 2) && (Sf_od_2[h][k] == 0)) ||(Sf_nl_2[h][k] == 2)){
										for (unsigned int u=h-1; u<=h+1; u+=1){
											for (unsigned int o=k-1; o<=k+1; o+=1){
												if ((u>0)&&(u<(m-1))&&(o>0)&&(o<(n-1))){
													if ((Sf_nl_2[u][o] == 2) || ((Sf[u][o] == 2) && (Sf_od_2[u][o] == 0))){
														a += 1;
													}
												}
											}
										}
										if (a < 4){
											b = 1;
										}
										a = 0;							
									}
								}
							}
						}
						if (b != 1){
							Index_Wert_2 += 10;
											//if (ober == 70){printf("%u \n", Index_Wert_2);}

						} 
						b = 0;
						
						if (ind == 2) {
							Index_Wert_2 += i;
						}
						if (ind == 1) {
							Index_Wert_2 += (6-i);
						}
						
						if ((Sf[i-1][j]==7)||(Sf[i][j+1]==7)||(Sf[i+1][j]==7)){
							Index_Wert_2 = 1;		//fehlerhaft!
						} 
						
										//if (ober == 70){printf("%u	%u	%u \n", Index_Wert_2, i, j);}
							
						Index_2_Feld[i][j] = Index_Wert_2;
						Index_Wert_2 = 0;
					}
				}
			}
			
			
			if (ind == 1){
				for (unsigned int i=1; i<m-1; i+=1){
					if (c == 1){
						break;
					}
					for (unsigned int j=1; j<n-1; j+=1){
						if (Index_2_Feld[i][j] == ober){
							Index_2_Feld[i][j] = 0;
							Sf_nl_2[i][j] = 0;
							count_new -= 1;
							ober = 80;
							c = 1;
							break;
						}
					}
				}
				if (c == 0){
					ober -= 1;
				}
			}
			
			if (ind == 2) {
				for (unsigned int i=m-2; i>0; i-=1){
					if (c == 1){
						break;
					}
					for (unsigned int j=n-2; j>0; j-=1){
						if (Index_2_Feld[i][j] == ober){
							Index_2_Feld[i][j] = 0;
							Sf_nl_2[i][j] = 0;
							count_new -= 1;
							ober = 80;
							c = 1;
							break;
						}
					}
				}
				if (c == 0){
					ober -= 1;
				}
			}
			c = 0;
			for (unsigned int t=1; t<m-1; t+=1){
				if (f == 1){
					break;
				}
				for (unsigned int z=1; z<n-1; z+=1){
					if (Sf_nl_2[t][z] == 2){
						f = 1;
						break;
					}
				}
			}
			if (f == 0){
				break;
			}
			f = 0;
		}
	}
	
	Spielfeld_Destroy (Index_2_Feld, m);
	
	return Sf_nl_2;
}

Spielfeld Index_1_fig (unsigned int ent, unsigned int count_new, unsigned int m, unsigned int n, Spielfeld Sf, Spielfeld Sf_nl_1, Spielfeld Sf_od_1, unsigned int limit_new, unsigned int limit_at_all, unsigned int zeitgewinner){
	unsigned int Index_Wert_1, a, b, c, f, ind_1, ind_3, ind, ober;
	Spielfeld Index_1_Feld;
	
	ind = 0;
	f = 0;
	b = 0;
	c = 0;
	a = 0;
	Index_Wert_1 = 0;
	Index_1_Feld = Spielfeld_Create (m, n);
	
	//printf("	zeitgewinner:	%u \n ", zeitgewinner);
	//printf("	ent:	%u \n ", ent);
	
	if (zeitgewinner >= limit_at_all) {
		for (unsigned int i=1; i<m-1; i+=1){
			for (unsigned int j=1; j<n-1; j+=1){
				if (Sf_nl_1[i][j] == 1){
					Sf_nl_1[i][j] = 0;
				}
			}
		}
	} else {
		while ((ind != 1)&&(ind != 2)){
			printf (" Where do you want to keep them: \n");
			if (ent == limit_new){
				printf(" #produce	top: 1		bottom: 2 \n");
				scanf("%u", &ind_1);
				ind = ind_1;
			}
			
			if (ent >= (limit_at_all - 4)){
				printf(" #reduce	top: 1		bottom: 2 \n");
				scanf("%u", &ind_3);
				ind = ind_3;
			}
		}
															//printf("%u \n", ent); printf("\n");
															//printf("%u \n", ind); printf("\n");
															//printf("%u \n", count_new); printf("\n");
		ober = 105;
		
		while (count_new > ent){
			for (unsigned int i=1; i<m-1; i+=1){
				for (unsigned int j=1; j<n-1; j+=1){
					if (Sf_nl_1[i][j] == 1){
						
						for (unsigned int h=i-1; h<=i+1; h+=1){		//Stirbt Zelle?
							for (unsigned int k=j-1; k<=j+1; k+=1){
								if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
									if ((Sf_nl_1[h][k] == 1) || ((Sf[h][k] == 1) && (Sf_od_1[h][k] == 0))){
										a+=1;
									}
								}
							}	
						}
						if (a > 4){
							Index_Wert_1 += 3;
															//printf("1.  %u \n", Index_Wert_1);
						}
						a = 0;
						
						Index_Wert_1 += 8;
						for (unsigned int h=i-1; h<=i+1; h+=1){		//Regeneriert neue Zellen?
							for (unsigned int k=j-1; k<=j+1; k+=1){
								if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
									if (((Sf[h][k] == 0) || ((Sf[h][k] == 1)&&(Sf_od_1[h][k] == 101))) && (Sf_nl_1[h][k] == 0)){
										for (unsigned int u=h-1; u<=h+1; u+=1){
											for (unsigned int o=k-1; o<=k+1; o+=1){
												if ((u>0)&&(u<(m-1))&&(o>0)&&(o<(n-1))){
													if ((Sf_nl_1[u][o] == 1) || ((Sf[u][o] == 1) && (Sf_od_1[u][o] == 0))){
														a += 1;
													}
												}
											}
										}
										if (a == 3){
											Index_Wert_1 -= 1;
																				//printf("2.  %u \n", Index_Wert_1);
										}
										a = 0;
									}
								}
							}
						}
						
						for (unsigned int h=i-1; h<=i+1; h+=1){		//Stört feindliches Wachstum?
							for (unsigned int k=j-1; k<=j+1; k+=1){
								if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
									if (Sf[h][k] == 2){
										a+=1;
									}
								}
							}	
						}
						if (a != 3){
							Index_Wert_1 += 20;
																	//printf("3.  %u \n", Index_Wert_1);
						}
						a = 0;
						
						for (unsigned int h=i-1; h<=i+1; h+=1){		//Regeneriert ihr Tod neue Zellen?
							for (unsigned int k=j-1; k<=j+1; k+=1){
								if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
									if (((Sf[h][k] == 0) || ((Sf[h][k] == 1)&&(Sf_od_1[h][k] == 101))) && (Sf_nl_1[h][k] == 0)){
										for (unsigned int u=h-1; u<=h+1; u+=1){
											for (unsigned int o=k-1; o<=k+1; o+=1){
												if ((u>0)&&(u<(m-1))&&(o>0)&&(o<(n-1))){
													if ((Sf_nl_1[u][o] == 1) || ((Sf[u][o] == 1) && (Sf_od_1[u][o] == 0))){
														a += 1;
													}
												}
											}
										}
										if (a == 4){
											Index_Wert_1 += 1;
																				//printf("4.  %u \n", Index_Wert_1);
										} 
										a = 0;
										
									}
								}
							}
						}
						
						for (unsigned int h=i-1; h<=i+1; h+=1){		//sterben eigene Zellen?
							for (unsigned int k=j-1; k<=j+1; k+=1){
								if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
									if (((Sf[h][k] == 1) && (Sf_od_1[h][k] == 0)) ||(Sf_nl_1[h][k] == 1)){
										for (unsigned int u=h-1; u<=h+1; u+=1){
											for (unsigned int o=k-1; o<=k+1; o+=1){
												if ((u>0)&&(u<(m-1))&&(o>0)&&(o<(n-1))){
													if ((Sf_nl_1[u][o] == 1) || ((Sf[u][o] == 1) && (Sf_od_1[u][o] == 0))){
														a += 1;
													}
												}
											}
										}
										if (a > 4){
											Index_Wert_1 += 3;
																				//printf("5.  %u \n", Index_Wert_1);
										}
										a = 0;
									}
								}
							}
						}
						
						for (unsigned int h=i-1; h<=i+1; h+=1){		//tötet ihr Tod eigene Zellen?
							for (unsigned int k=j-1; k<=j+1; k+=1){
								if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
									if (((Sf[h][k] == 1) && (Sf_od_1[h][k] == 0)) ||(Sf_nl_1[h][k] == 1)){
										for (unsigned int u=h-1; u<=h+1; u+=1){
											for (unsigned int o=k-1; o<=k+1; o+=1){
												if ((u>0)&&(u<(m-1))&&(o>0)&&(o<(n-1))){
													if ((Sf_nl_1[u][o] == 1) || ((Sf[u][o] == 1) && (Sf_od_1[u][o] == 0))){
														a += 1;
													}
												}
											}
										}
										if (a < 4){
											b = 1;
										}
										a = 0;
									}
								}
							}
						}
						if (b != 1){
							Index_Wert_1 += 10;
																	//printf("6.  %u \n", Index_Wert_1);
						} 
						b = 0;
						if ((Sf[i+1][j] != 2)&&(Sf[i][j+1] != 2)&&(Sf[i][j-1] != 2)&&(Sf[i-1][j] != 2)) {
							Index_Wert_1 += 10;
						}
						if (ind == 1) {
							Index_Wert_1 += i;
						}
						if (ind == 2) {
							Index_Wert_1 += (6-i);
						}
																	//printf("7.  %u \n", Index_Wert_1);  printf("\n");
						Index_1_Feld[i][j] = Index_Wert_1;
						Index_Wert_1 = 0;
					}
				}
			}
			//printf("\n");
			
			if (ind == 2){
				for (unsigned int i=1; i<m-1; i+=1){
					if (c == 1){
						break;
					}
					for (unsigned int j=1; j<n-1; j+=1){
						if (Index_1_Feld[i][j] == ober){
							Index_1_Feld[i][j] = 0;
							Sf_nl_1[i][j] = 0;
							count_new -= 1;
							ober = 105;
							c = 1;
							break;
						}
					}
				}
				if (c == 0){
					ober -= 1;
				}
			}
			
			if (ind == 1) {
				for (unsigned int i=m-2; i>0; i-=1){
					if (c == 1){
						break;
					}
					for (unsigned int j=n-2; j>0; j-=1){
						if (Index_1_Feld[i][j] == ober){
							Index_1_Feld[i][j] = 0;
							Sf_nl_1[i][j] = 0;
							count_new -= 1;
							ober = 105;
							c = 1;
							break;
						}
					}
				}
				if (c == 0){
					ober -= 1;
				}
			}
			c = 0;
			for (unsigned int t=1; t<m-1; t+=1){
				if (f == 1){
					break;
				}
				for (unsigned int z=1; z<n-1; z+=1){
					if (Sf_nl_1[t][z] == 1){
						f = 1;
						break;
					}
				}
			}
			if (f == 0){
				break;
			}
			f = 0;
		}
	}	
	
	Spielfeld_Destroy (Index_1_Feld, m);
	
	return Sf_nl_1;
}

Spielfeld Index_2_fig (unsigned int ent, unsigned int count_new, unsigned int m, unsigned int n, Spielfeld Sf, Spielfeld Sf_nl_2, Spielfeld Sf_od_2, unsigned int limit_new, unsigned int limit_at_all, unsigned int zeitgewinner){
	unsigned int Index_Wert_2, a, b, c, f, ind_2, ind_4, ind, ober;
	Spielfeld Index_2_Feld;
	
	ind = 0;
	f = 0;
	b = 0;
	c = 0;
	a = 0;
	Index_Wert_2 = 0;
	Index_2_Feld = Spielfeld_Create (m, n);
	
	if (zeitgewinner >= limit_at_all) {
		for (unsigned int i=1; i<m-1; i+=1){
			for (unsigned int j=1; j<n-1; j+=1){
				if (Sf_nl_2[i][j] == 2){
					Sf_nl_2[i][j] = 0;
				}
			}
		}
	} else {
		while ((ind != 1)&&(ind != 2)){
			printf (" Where do you want to keep them: \n");
			if (ent == limit_new){
				printf(" #produce	bottom: 1		top: 2 \n");
				scanf("%u", &ind_2);
				ind = ind_2;
			}
			
			if (ent >= (limit_at_all - 4)){
				printf(" #reduce	bottom: 1		top: 2 \n");
				scanf("%u", &ind_4);
				ind = ind_4;
			}
		}
		
		ober = 105;
			//printf("	ok 5214 \n");
		while (count_new > ent){		//printf("	ok 5215 \n");
			for (unsigned int i=1; i<m-1; i+=1){		//printf("	ok 5216 \n");
				for (unsigned int j=1; j<n-1; j+=1){		//printf("	ok 5217 \n");
					if (Sf_nl_2[i][j] == 2){		//printf("	ok 5218 \n");
						
						for (unsigned int h=i-1; h<=i+1; h+=1){				//printf("	ok 5220 \n"); //Stirbt Zelle?
							for (unsigned int k=j-1; k<=j+1; k+=1){			//printf("	ok 5221 \n");
								if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){			//printf("	ok 5222 \n");
									if ((Sf_nl_2[h][k] == 2) || ((Sf[h][k] == 2) && (Sf_od_2[h][k] == 0))){
										a+=1;				//printf("	ok 5224 \n");
									}
								}
							}	
						}
						if (a > 4){		//printf("		//ok 5229 \n");
							Index_Wert_2 += 3;
															//if (ober == 90){printf("%u \n", Index_Wert_2);}	//test
						}
						a = 0;
								//printf("	ok 5234 \n");
						Index_Wert_2 += 8;
						for (unsigned int h=i-1; h<=i+1; h+=1){		//Regeneriert neue Zellen?
							for (unsigned int k=j-1; k<=j+1; k+=1){
								if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
									if (((Sf[h][k] == 0) || ((Sf[h][k] == 2)&&(Sf_od_2[h][k] == 202))) && (Sf_nl_2[h][k] == 0)){
										for (unsigned int u=h-1; u<=h+1; u+=1){
											for (unsigned int o=k-1; o<=k+1; o+=1){
												if ((u>0)&&(u<(m-1))&&(o>0)&&(o<(n-1))){
													if ((Sf_nl_2[u][o] == 2) || ((Sf[u][o] == 2) && (Sf_od_2[u][o] == 0))){
														a += 1;
													}
												}
											}
										}
										if (a == 3){
											Index_Wert_2 -= 1;
																//if (ober == 90){printf("%u \n", Index_Wert_2);}	//test
										}
										a = 0;
									}
								}
							}
						}
								//printf("	ok 5258 \n");
						for (unsigned int h=i-1; h<=i+1; h+=1){		//Stört feindliches Wachstum?
							for (unsigned int k=j-1; k<=j+1; k+=1){
								if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
									if (Sf[h][k] == 1){
										a+=1;
									}
								}
							}	
						}
						if (a != 3){
							Index_Wert_2 += 20;
													//if (ober == 90){printf("%u \n", Index_Wert_2);}	//test
						}
						a = 0;
								//printf("	ok 5273 \n");
						for (unsigned int h=i-1; h<=i+1; h+=1){		//Regeneriert ihr Tod neue Zellen?
							for (unsigned int k=j-1; k<=j+1; k+=1){
								if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
									if (((Sf[h][k] == 0) || ((Sf[h][k] == 2)&&(Sf_od_2[h][k] == 202))) && (Sf_nl_2[h][k] == 0)){
										for (unsigned int u=h-1; u<=h+1; u+=1){
											for (unsigned int o=k-1; o<=k+1; o+=1){
												if ((u>0)&&(u<(m-1))&&(o>0)&&(o<(n-1))){
													if ((Sf_nl_2[u][o] == 2) || ((Sf[u][o] == 2) && (Sf_od_2[u][o] == 0))){
														a += 1;
													}
												}
											}
										}
										if (a == 4){
											Index_Wert_2 += 1;
																	//if (ober == 90){printf("%u \n", Index_Wert_2);}	//test
										} 
										a = 0;
										
									}
								}
							}
						}
								//printf("	ok 5297 \n");
						for (unsigned int h=i-1; h<=i+1; h+=1){		//sterben eigene Zellen?
							for (unsigned int k=j-1; k<=j+1; k+=1){
								if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
									if (((Sf[h][k] == 2) && (Sf_od_2[h][k] == 0)) ||(Sf_nl_2[h][k] == 2)){
										for (unsigned int u=h-1; u<=h+1; u+=1){
											for (unsigned int o=k-1; o<=k+1; o+=1){
												if ((u>0)&&(u<(m-1))&&(o>0)&&(o<(n-1))){
													if ((Sf_nl_2[u][o] == 2) || ((Sf[u][o] == 2) && (Sf_od_2[u][o] == 0))){
														a += 1;
													}
												}
											}
										}
										if (a > 4){
											Index_Wert_2 += 3;
																	//if (ober == 90){printf("%u \n", Index_Wert_2);}	//test
										}
										a = 0;
									}
								}
							}
						}
								//printf("	ok 5320 \n");
						for (unsigned int h=i-1; h<=i+1; h+=1){		//tötet ihr Tod eigene Zellen?
							for (unsigned int k=j-1; k<=j+1; k+=1){
								if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
									if (((Sf[h][k] == 2) && (Sf_od_2[h][k] == 0)) ||(Sf_nl_2[h][k] == 2)){
										for (unsigned int u=h-1; u<=h+1; u+=1){
											for (unsigned int o=k-1; o<=k+1; o+=1){
												if ((u>0)&&(u<(m-1))&&(o>0)&&(o<(n-1))){
													if ((Sf_nl_2[u][o] == 2) || ((Sf[u][o] == 2) && (Sf_od_2[u][o] == 0))){
														a += 1;
													}
												}
											}
										}
										if (a < 4){
											b = 1;
										}
										a = 0;
									}
								}
							}
						}
						if (b != 1){
							Index_Wert_2 += 10;
													//if (ober == 90){printf("%u \n", Index_Wert_2);}	//test
						} 
						b = 0;
						if ((Sf[i+1][j] != 1)&&(Sf[i][j+1] != 1)&&(Sf[i][j-1] != 1)&&(Sf[i-1][j] != 1)) {
							Index_Wert_2 += 10;
						}
						
						if (ind == 2) {
							Index_Wert_2 += i;
						}
						if (ind == 1) {
							Index_Wert_2 += (6-i);
						}
							//printf("	ok 5347 \n");
										//if (ober == 90){printf("%u %u %u \n", Index_Wert_2, i, j);}	//test
						
						Index_2_Feld[i][j] = Index_Wert_2;
						Index_Wert_2 = 0;
					}
				}
			}
					//printf("	ok 5355 \n");
			
			if (ind == 1){
				for (unsigned int i=1; i<m-1; i+=1){
					if (c == 1){
						break;
					}
					for (unsigned int j=1; j<n-1; j+=1){
						if (Index_2_Feld[i][j] == ober){
							Index_2_Feld[i][j] = 0;
							Sf_nl_2[i][j] = 0;
							count_new -= 1;
							ober = 105;
							c = 1;
							break;
						}
					}
				}
				if (c == 0){
					ober -= 1;
				}
			}
			
			if (ind == 2) {
				for (unsigned int i=m-2; i>0; i-=1){
					if (c == 1){
						break;
					}
					for (unsigned int j=n-2; j>0; j-=1){
						if (Index_2_Feld[i][j] == ober){
							Index_2_Feld[i][j] = 0;
							Sf_nl_2[i][j] = 0;
							count_new -= 1;
							ober = 105;
							c = 1;
							break;
						}
					}
				}
				if (c == 0){
					ober -= 1;
				}
			}
			c = 0;
			for (unsigned int t=1; t<m-1; t+=1){
				if (f == 1){
					break;
				}
				for (unsigned int z=1; z<n-1; z+=1){
					if (Sf_nl_2[t][z] == 2){
						f = 1;
						break;
					}
				}
			}
			if (f == 0){
				break;
			}
			f = 0;
		}
	}
	
			//printf("	ok 5415 \n");
	Spielfeld_Destroy (Index_2_Feld, m);
			//printf("	ok 5417 \n");
	return Sf_nl_2;
}

Spielfeld Index_1_race (unsigned int ent, unsigned int count_new, unsigned int m, unsigned int n, Spielfeld Sf, Spielfeld Sf_nl_1, Spielfeld Sf_od_1, unsigned int limit_new, unsigned int limit_at_all, unsigned int zeitgewinner){
	unsigned int Index_Wert_1, a, b, c, f, ind_1, ind_3, ind, ober;
	Spielfeld Index_1_Feld;
	
	ind = 0;
	f = 0;
	b = 0;
	c = 0;
	a = 0;
	Index_Wert_1 = 0;
	Index_1_Feld = Spielfeld_Create (m, n);

	if (zeitgewinner >= limit_at_all) {
		for (unsigned int i=1; i<m-1; i+=1){
			for (unsigned int j=1; j<n-1; j+=1){
				if (Sf_nl_1[i][j] == 1){
					Sf_nl_1[i][j] = 0;
				}
			}
		}
	} else {
		while ((ind != 1)&&(ind != 2)){
			printf (" Where do you want to keep them: \n");
			if (ent == limit_new){
				printf(" #produce	top: 1		bottom: 2 \n");
				scanf("%u", &ind_1);
				ind = ind_1;
			}
			
			if (ent >= (limit_at_all - 4)){
				printf(" #reduce	top: 1		bottom: 2 \n");
				scanf("%u", &ind_3);
				ind = ind_3;
			}
		}
															//printf("%u \n", ent); printf("\n");
															//printf("%u \n", ind); printf("\n");
															//printf("%u \n", count_new); printf("\n");
		ober = 85+(n-4);
		while (count_new > ent){
			for (unsigned int i=1; i<m-1; i+=1){
				for (unsigned int j=1; j<n-1; j+=1){
					if (Sf_nl_1[i][j] == 1){
						for (unsigned int h=i-1; h<=i+1; h+=1){		//Stirbt Zelle?
							for (unsigned int k=j-1; k<=j+1; k+=1){
								if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
									if ((Sf_nl_1[h][k] == 1) || ((Sf[h][k] == 1) && (Sf_od_1[h][k] == 0))){
										a+=1;
									}
								}
							}	
						}
						if (a > 4){
							Index_Wert_1 += 3;
																//printf("1.  %u \n", Index_Wert_1);
						}
						a = 0;
						
						Index_Wert_1 += 8;
						for (unsigned int h=i-1; h<=i+1; h+=1){		//Regeneriert neue Zellen?
							for (unsigned int k=j-1; k<=j+1; k+=1){
								if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
									if (((Sf[h][k] == 0) || ((Sf[h][k] == 1)&&(Sf_od_1[h][k] == 101))) && (Sf_nl_1[h][k] == 0)){
										for (unsigned int u=h-1; u<=h+1; u+=1){
											for (unsigned int o=k-1; o<=k+1; o+=1){
												if ((u>0)&&(u<(m-1))&&(o>0)&&(o<(n-1))){
													if ((Sf_nl_1[u][o] == 1) || ((Sf[u][o] == 1) && (Sf_od_1[u][o] == 0))){
														a += 1;
													}
												}
											}
										}
										if (a == 3){
											Index_Wert_1 -= 1;
																				//printf("2.  %u \n", Index_Wert_1);
										}
										a = 0;
									}
								}
							}
						}
						
						for (unsigned int h=i-1; h<=i+1; h+=1){		//Stört feindliches Wachstum?
							for (unsigned int k=j-1; k<=j+1; k+=1){
								if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
									if (Sf[h][k] == 2){
										a+=1;
									}
								}
							}	
						}
						if (a != 3){
							Index_Wert_1 += 10;
																	//printf("3.  %u \n", Index_Wert_1);
						}
						a = 0;
						
						for (unsigned int h=i-1; h<=i+1; h+=1){		//Regeneriert ihr Tod neue Zellen?
							for (unsigned int k=j-1; k<=j+1; k+=1){
								if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
									if (((Sf[h][k] == 0) || ((Sf[h][k] == 1)&&(Sf_od_1[h][k] == 101))) && (Sf_nl_1[h][k] == 0)){
										for (unsigned int u=h-1; u<=h+1; u+=1){
											for (unsigned int o=k-1; o<=k+1; o+=1){
												if ((u>0)&&(u<(m-1))&&(o>0)&&(o<(n-1))){
													if ((Sf_nl_1[u][o] == 1) || ((Sf[u][o] == 1) && (Sf_od_1[u][o] == 0))){
														a += 1;
													}
												}
											}
										}
										if (a == 4){
											Index_Wert_1 += 1;
																				//printf("4.  %u \n", Index_Wert_1);
										} 
										a = 0;
										
									}
								}
							}
						}
						
						for (unsigned int h=i-1; h<=i+1; h+=1){		//sterben eigene Zellen?
							for (unsigned int k=j-1; k<=j+1; k+=1){
								if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
									if (((Sf[h][k] == 1) && (Sf_od_1[h][k] == 0)) ||(Sf_nl_1[h][k] == 1)){
										for (unsigned int u=h-1; u<=h+1; u+=1){
											for (unsigned int o=k-1; o<=k+1; o+=1){
												if ((u>0)&&(u<(m-1))&&(o>0)&&(o<(n-1))){
													if ((Sf_nl_1[u][o] == 1) || ((Sf[u][o] == 1) && (Sf_od_1[u][o] == 0))){
														a += 1;
													}
												}
											}
										}
										if (a > 4){
											Index_Wert_1 += 3;
																				//printf("5.  %u \n", Index_Wert_1);
										}
										a = 0;
									}
								}
							}
						}
						
						for (unsigned int h=i-1; h<=i+1; h+=1){		//tötet ihr Tod eigene Zellen?
							for (unsigned int k=j-1; k<=j+1; k+=1){
								if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
									if (((Sf[h][k] == 1) && (Sf_od_1[h][k] == 0)) ||(Sf_nl_1[h][k] == 1)){
										for (unsigned int u=h-1; u<=h+1; u+=1){
											for (unsigned int o=k-1; o<=k+1; o+=1){
												if ((u>0)&&(u<(m-1))&&(o>0)&&(o<(n-1))){
													if ((Sf_nl_1[u][o] == 1) || ((Sf[u][o] == 1) && (Sf_od_1[u][o] == 0))){
														a += 1;
													}
												}
											}
										}
										if (a < 4){
											b = 1;
										}
										a = 0;
									}
								}
							}
						}
						if (b != 1){
							Index_Wert_1 += 10;
																	//printf("6.  %u \n", Index_Wert_1);
						} 
						b = 0;
						
						Index_Wert_1 += (n-2-j);
						
						if (ind == 1) {
							Index_Wert_1 += i;
						}
						if (ind == 2) {
							Index_Wert_1 += (6-i);
						}
						
						if (j>=n-3){
							Index_Wert_1 = 1;
						}
																	//printf("7.  %u \n", Index_Wert_1);  printf("\n");
						Index_1_Feld[i][j] = Index_Wert_1;
						Index_Wert_1 = 0;
					}
				}
			}
			//printf("\n");
			
			if (ind == 2){
				for (unsigned int i=1; i<m-1; i+=1){
					if (c == 1){
						break;
					}
					for (unsigned int j=1; j<n-1; j+=1){
						if (Index_1_Feld[i][j] == ober){
							Index_1_Feld[i][j] = 0;
							Sf_nl_1[i][j] = 0;
							count_new -= 1;
							ober = 85+(n-4);
							c = 1;
							break;
						}
					}
				}
				if (c == 0){
					ober -= 1;
				}
			}
			
			if (ind == 1) {
				for (unsigned int i=m-2; i>0; i-=1){
					if (c == 1){
						break;
					}
					for (unsigned int j=n-2; j>0; j-=1){
						if (Index_1_Feld[i][j] == ober){
							Index_1_Feld[i][j] = 0;
							Sf_nl_1[i][j] = 0;
							count_new -= 1;
							ober = 85+(n-4);
							c = 1;
							break;
						}
					}
				}
				if (c == 0){
					ober -= 1;
				}
			}
			c = 0;
			for (unsigned int t=1; t<m-1; t+=1){
				if (f == 1){
					break;
				}
				for (unsigned int z=1; z<n-1; z+=1){
					if (Sf_nl_1[t][z] == 1){
						f = 1;
						break;
					}
				}
			}
			if (f == 0){
				break;
			}
			f = 0;
		}
	}
	
	Spielfeld_Destroy (Index_1_Feld, m);
	
	return Sf_nl_1;
}

Spielfeld Index_2_race (unsigned int ent, unsigned int count_new, unsigned int m, unsigned int n, Spielfeld Sf, Spielfeld Sf_nl_2, Spielfeld Sf_od_2, unsigned int limit_new, unsigned int limit_at_all, unsigned int zeitgewinner){
	unsigned int Index_Wert_2, a, b, c, f, ind_2, ind_4, ind, ober;
	Spielfeld Index_2_Feld;
	
	ind = 0;
	f = 0;
	b = 0;
	c = 0;
	a = 0;
	Index_Wert_2 = 0;
	Index_2_Feld = Spielfeld_Create (m, n);
	
	if (zeitgewinner >= limit_at_all) {
		for (unsigned int i=1; i<m-1; i+=1){
			for (unsigned int j=1; j<n-1; j+=1){
				if (Sf_nl_2[i][j] == 2){
					Sf_nl_2[i][j] = 0;
				}
			}
		}
	} else {
		while ((ind != 1)&&(ind != 2)){
			printf (" Where do you want to keep them: \n");
			if (ent == limit_new){
				printf(" #produce	bottom: 1		top: 2 \n");
				scanf("%u", &ind_2);
				ind = ind_2;
			}
			
			if (ent >= (limit_at_all - 4)){
				printf(" #reduce	bottom: 1		top: 2 \n");
				scanf("%u", &ind_4);
				ind = ind_4;
			}
		}
		
		ober = 85+(n-4);
		while (count_new > ent){
			for (unsigned int i=1; i<m-1; i+=1){
				for (unsigned int j=1; j<n-1; j+=1){
					if (Sf_nl_2[i][j] == 2){
						
						for (unsigned int h=i-1; h<=i+1; h+=1){		//Stirbt Zelle?
							for (unsigned int k=j-1; k<=j+1; k+=1){
								if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
									if ((Sf_nl_2[h][k] == 2) || ((Sf[h][k] == 2) && (Sf_od_2[h][k] == 0))){
										a+=1;
									}
								}
							}	
						}
						if (a > 4){
							Index_Wert_2 += 3;
						}
						a = 0;
						
						Index_Wert_2 += 8;
						for (unsigned int h=i-1; h<=i+1; h+=1){		//Regeneriert neue Zellen?
							for (unsigned int k=j-1; k<=j+1; k+=1){
								if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
									if (((Sf[h][k] == 0) || ((Sf[h][k] == 2)&&(Sf_od_2[h][k] == 202))) && (Sf_nl_2[h][k] == 0)){
										for (unsigned int u=h-1; u<=h+1; u+=1){
											for (unsigned int o=k-1; o<=k+1; o+=1){
												if ((u>0)&&(u<(m-1))&&(o>0)&&(o<(n-1))){
													if ((Sf_nl_2[u][o] == 2) || ((Sf[u][o] == 2) && (Sf_od_2[u][o] == 0))){
														a += 1;
													}
												}
											}
										}
										if (a == 3){
											Index_Wert_2 -= 1;
										}
										a = 0;
									}
								}
							}
						}
						
						for (unsigned int h=i-1; h<=i+1; h+=1){		//Stört feindliches Wachstum?
							for (unsigned int k=j-1; k<=j+1; k+=1){
								if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
									if (Sf[h][k] == 1){
										a+=1;
									}
								}
							}	
						}
						if (a != 3){
							Index_Wert_2 += 10;
						}
						a = 0;
						
						for (unsigned int h=i-1; h<=i+1; h+=1){		//Regeneriert ihr Tod neue Zellen?
							for (unsigned int k=j-1; k<=j+1; k+=1){
								if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
									if (((Sf[h][k] == 0) || ((Sf[h][k] == 2)&&(Sf_od_2[h][k] == 202))) && (Sf_nl_2[h][k] == 0)){
										for (unsigned int u=h-1; u<=h+1; u+=1){
											for (unsigned int o=k-1; o<=k+1; o+=1){
												if ((u>0)&&(u<(m-1))&&(o>0)&&(o<(n-1))){
													if ((Sf_nl_2[u][o] == 2) || ((Sf[u][o] == 2) && (Sf_od_2[u][o] == 0))){
														a += 1;
													}
												}
											}
										}
										if (a == 4){
											Index_Wert_2 += 1;
										} 
										a = 0;
										
									}
								}
							}
						}
						
						for (unsigned int h=i-1; h<=i+1; h+=1){		//sterben eigene Zellen?
							for (unsigned int k=j-1; k<=j+1; k+=1){
								if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
									if (((Sf[h][k] == 2) && (Sf_od_2[h][k] == 0)) ||(Sf_nl_2[h][k] == 2)){
										for (unsigned int u=h-1; u<=h+1; u+=1){
											for (unsigned int o=k-1; o<=k+1; o+=1){
												if ((u>0)&&(u<(m-1))&&(o>0)&&(o<(n-1))){
													if ((Sf_nl_2[u][o] == 2) || ((Sf[u][o] == 2) && (Sf_od_2[u][o] == 0))){
														a += 1;
													}
												}
											}
										}
										if (a > 4){
											Index_Wert_2 += 3;
										}
										a = 0;
									}
								}
							}
						}
						
						for (unsigned int h=i-1; h<=i+1; h+=1){		//tötet ihr Tod eigene Zellen?
							for (unsigned int k=j-1; k<=j+1; k+=1){
								if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
									if (((Sf[h][k] == 2) && (Sf_od_2[h][k] == 0)) ||(Sf_nl_2[h][k] == 2)){
										for (unsigned int u=h-1; u<=h+1; u+=1){
											for (unsigned int o=k-1; o<=k+1; o+=1){
												if ((u>0)&&(u<(m-1))&&(o>0)&&(o<(n-1))){
													if ((Sf_nl_2[u][o] == 2) || ((Sf[u][o] == 2) && (Sf_od_2[u][o] == 0))){
														a += 1;
													}
												}
											}
										}
										if (a < 4){
											b = 1;
										}
										a = 0;
									}
								}
							}
						}
						if (b != 1){
							Index_Wert_2 += 10;
						} 
						b = 0;
						
						Index_Wert_2 += (n-2-j);
						
						if (ind == 2) {
							Index_Wert_2 += i;
						}
						if (ind == 1) {
							Index_Wert_2 += (6-i);
						}
						
						if (j>=n-3){
							Index_Wert_2 = 1;
						}
						
						Index_2_Feld[i][j] = Index_Wert_2;
						Index_Wert_2 = 0;
					}
				}
			}
			
			if (ind == 1){
				for (unsigned int i=1; i<m-1; i+=1){
					if (c == 1){
						break;
					}
					for (unsigned int j=1; j<n-1; j+=1){
						if (Index_2_Feld[i][j] == ober){
							Index_2_Feld[i][j] = 0;
							Sf_nl_2[i][j] = 0;
							count_new -= 1;
							ober = 85+(n-4);
							c = 1;
							break;
						}
					}
				}
				if (c == 0){
					ober -= 1;
				}
			}
			
			if (ind == 2) {
				for (unsigned int i=m-2; i>0; i-=1){
					if (c == 1){
						break;
					}
					for (unsigned int j=n-2; j>0; j-=1){
						if (Index_2_Feld[i][j] == ober){
							Index_2_Feld[i][j] = 0;
							Sf_nl_2[i][j] = 0;
							count_new -= 1;
							ober = 85+(n-4);
							c = 1;
							break;
						}
					}
				}
				if (c == 0){
					ober -= 1;
				}
			}
			c = 0;
			for (unsigned int t=1; t<m-1; t+=1){
				if (f == 1){
					break;
				}
				for (unsigned int z=1; z<n-1; z+=1){
					if (Sf_nl_2[t][z] == 2){
						f = 1;
						break;
					}
				}
			}
			if (f == 0){
				break;
			}
			f = 0;
		}
	}
	
	Spielfeld_Destroy (Index_2_Feld, m);
	
	return Sf_nl_2;
}

Spielfeld Index_1_rain (unsigned int ent, unsigned int count_new, unsigned int m, unsigned int n, Spielfeld Sf, Spielfeld Sf_nl_1, Spielfeld Sf_od_1, unsigned int limit_new, unsigned int limit_at_all, unsigned int rain, unsigned int zeitgewinner){
	unsigned int Index_Wert_1, a, b, c, f, ind_1, ind_3, ind, ober;
	Spielfeld Index_1_Feld;
	
	ind = 0;
	f = 0;
	b = 0;
	c = 0;
	a = 0;
	Index_Wert_1 = 0;
	Index_1_Feld = Spielfeld_Create (m, n);

	if (zeitgewinner >= limit_at_all) {
		for (unsigned int i=1; i<m-1; i+=1){
			for (unsigned int j=1; j<n-1; j+=1){
				if (Sf_nl_1[i][j] == 1){
					Sf_nl_1[i][j] = 0;
				}
			}
		}
	} else {
		while ((ind != 1)&&(ind != 2)){
			printf (" Where do you want to keep them: \n");
			if (ent == limit_new){
				printf(" #produce	top: 1		bottom: 2 \n");
				scanf("%u", &ind_1);
				ind = ind_1;
			}
			
			if (ent >= (limit_at_all - 4)){
				printf(" #reduce	top: 1		bottom: 2 \n");
				scanf("%u", &ind_3);
				ind = ind_3;
			}
		}
															//printf("%u \n", ent); printf("\n");
															//printf("%u \n", ind); printf("\n");
															//printf("%u \n", count_new); printf("\n");
		ober = 87;
		while (count_new > ent){
			for (unsigned int i=1; i<m-1; i+=1){
				for (unsigned int j=1; j<n-1; j+=1){
					if (Sf_nl_1[i][j] == 1){
						for (unsigned int h=i-1; h<=i+1; h+=1){		//Stirbt Zelle?
							for (unsigned int k=j-1; k<=j+1; k+=1){
								if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
									if ((Sf_nl_1[h][k] == 1) || ((Sf[h][k] == 1) && (Sf_od_1[h][k] == 0))){
										a+=1;
									}
								}
							}	
						}
						if (a > 4){
							Index_Wert_1 += 3;
																		//printf("1.  %u \n", Index_Wert_1);
						}
						a = 0;
						
						
						Index_Wert_1 += 8;
						for (unsigned int h=i-1; h<=i+1; h+=1){		//Regeneriert neue Zellen?
							for (unsigned int k=j-1; k<=j+1; k+=1){
								if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
									if (((Sf[h][k] == 0) || ((Sf[h][k] == 1)&&(Sf_od_1[h][k] == 101))) && (Sf_nl_1[h][k] == 0)){
										for (unsigned int u=h-1; u<=h+1; u+=1){
											for (unsigned int o=k-1; o<=k+1; o+=1){
												if ((u>0)&&(u<(m-1))&&(o>0)&&(o<(n-1))){
													if ((Sf_nl_1[u][o] == 1) || ((Sf[u][o] == 1) && (Sf_od_1[u][o] == 0))){
														a += 1;
													}
												}
											}
										}
										if (a == 3){
											Index_Wert_1 -= 1;
																				//printf("2.  %u \n", Index_Wert_1);
										}
										a = 0;
									}
								}
							}
						}
						
						for (unsigned int h=i-1; h<=i+1; h+=1){		//Regeneriert ihr Tod neue Zellen?
							for (unsigned int k=j-1; k<=j+1; k+=1){
								if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
									if (((Sf[h][k] == 0) || ((Sf[h][k] == 1)&&(Sf_od_1[h][k] == 101))) && (Sf_nl_1[h][k] == 0)){
										for (unsigned int u=h-1; u<=h+1; u+=1){
											for (unsigned int o=k-1; o<=k+1; o+=1){
												if ((u>0)&&(u<(m-1))&&(o>0)&&(o<(n-1))){
													if ((Sf_nl_1[u][o] == 1) || ((Sf[u][o] == 1) && (Sf_od_1[u][o] == 0))){
														a += 1;
													}
												}
											}
										}
										if (a == 4){
											Index_Wert_1 += 1;
																				//printf("4.  %u \n", Index_Wert_1);
										} 
										a = 0;
										
									}
								}
							}
						}
						
						for (unsigned int h=i-1; h<=i+1; h+=1){		//sterben eigene Zellen?
							for (unsigned int k=j-1; k<=j+1; k+=1){
								if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
									if (((Sf[h][k] == 1) && (Sf_od_1[h][k] == 0)) ||(Sf_nl_1[h][k] == 1)){
										for (unsigned int u=h-1; u<=h+1; u+=1){
											for (unsigned int o=k-1; o<=k+1; o+=1){
												if ((u>0)&&(u<(m-1))&&(o>0)&&(o<(n-1))){
													if ((Sf_nl_1[u][o] == 1) || ((Sf[u][o] == 1) && (Sf_od_1[u][o] == 0))){
														a += 1;
													}
												}
											}
										}
										if (a > 4){
											Index_Wert_1 += 3;
																				//printf("5.  %u \n", Index_Wert_1);
										}
										a = 0;
									}
								}
							}
						}
						
						for (unsigned int h=i-1; h<=i+1; h+=1){		//tötet ihr Tod eigene Zellen?
							for (unsigned int k=j-1; k<=j+1; k+=1){
								if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
									if (((Sf[h][k] == 1) && (Sf_od_1[h][k] == 0)) ||(Sf_nl_1[h][k] == 1)){
										for (unsigned int u=h-1; u<=h+1; u+=1){
											for (unsigned int o=k-1; o<=k+1; o+=1){
												if ((u>0)&&(u<(m-1))&&(o>0)&&(o<(n-1))){
													if ((Sf_nl_1[u][o] == 1) || ((Sf[u][o] == 1) && (Sf_od_1[u][o] == 0))){
														a += 1;
													}
												}
											}
										}
										if (a < 4){
											b = 1;
										}
										a = 0;
									}
								}
							}
						}
						if (b != 1){
							Index_Wert_1 += 10;
																	//printf("6.  %u \n", Index_Wert_1);
						} 
						b = 0;
						
						if (j < ((n-1)/2)){
							Index_Wert_1 += (((n-1)/2)-j);
						} else if (j > ((n-1)/2)){
							Index_Wert_1 += (j-(n-1)/2);
						}
						
						Index_Wert_1 += i;
						
						if (ind == 1) {
							Index_Wert_1 += i;
						}
						if (ind == 2) {
							Index_Wert_1 += (6-i);
						}
						
						if ((i <= 2)&&((j >= ((n-3)/2))&&(j <= ((n+1)/2)))){
							Index_Wert_1 = 1;
						}
						
						if ((rain == 31)||(rain == 32)||(rain == 2)){
							if (Sf[i-1][j] == 7){
								Index_Wert_1 = 80;
							}
						}
						
						Index_1_Feld[i][j] = Index_Wert_1;
						Index_Wert_1 = 0;
					}
				}
			}
			//printf("\n");
			
			if (ind == 2){
				for (unsigned int i=1; i<(m-1); i+=1){
					if (c == 1){
						break;
					}
					for (unsigned int j=1; j<(n-1); j+=1){
						if (Index_1_Feld[i][j] == ober){
							Index_1_Feld[i][j] = 0;
							Sf_nl_1[i][j] = 0;
							count_new -= 1;
							ober = 87;
							c = 1;
							break;
						}
					}
				}
				if (c == 0){
					ober -= 1;
				}
			}
			
			if (ind == 1) {
				for (unsigned int i=m-2; i>0; i-=1){
					if (c == 1){
						break;
					}
					for (unsigned int j=n-2; j>0; j-=1){
						if (Index_1_Feld[i][j] == ober){
							Index_1_Feld[i][j] = 0;
							Sf_nl_1[i][j] = 0;
							count_new -= 1;
							ober = 87;
							c = 1;
							break;
						}
					}
				}
				if (c == 0){
					ober -= 1;
				}
			}
			c = 0;
			
			for (unsigned int t=1; t<m-1; t+=1){
				if (f == 1){
					break;
				}
				for (unsigned int z=1; z<n-1; z+=1){
					if (Sf_nl_1[t][z] == 1){
						f = 1;
						break;
					}
				}
			}
			if (f == 0){
				break;
			}
			f = 0;
		}
	}
	
	Spielfeld_Destroy (Index_1_Feld, m);
	
	return Sf_nl_1;
}

Spielfeld Index_2_rain (unsigned int ent, unsigned int count_new, unsigned int m, unsigned int n, Spielfeld Sf, Spielfeld Sf_nl_2, Spielfeld Sf_od_2, unsigned int limit_new, unsigned int limit_at_all, unsigned int rain, unsigned int zeitgewinner){
	unsigned int Index_Wert_2, a, b, c, f, ind_2, ind_4, ind, ober;
	Spielfeld Index_2_Feld;
	
	ind = 0;
	f = 0;
	b = 0;
	c = 0;
	a = 0;
	Index_Wert_2 = 0;
	Index_2_Feld = Spielfeld_Create (m, n);
	
	if (zeitgewinner >= limit_at_all) {
		for (unsigned int i=1; i<m-1; i+=1){
			for (unsigned int j=1; j<n-1; j+=1){
				if (Sf_nl_2[i][j] == 2){
					Sf_nl_2[i][j] = 0;
				}
			}
		}
	} else {
		while ((ind != 1)&&(ind != 2)){
			printf (" Where do you want to keep them: \n");
			if (ent == limit_new){
				printf(" #produce	bottom: 1		top: 2 \n");
				scanf("%u", &ind_2);
				ind = ind_2;
			}
			
			if (ent >= (limit_at_all - 4)){
				printf(" #reduce	bottom: 1		top: 2 \n");
				scanf("%u", &ind_4);
				ind = ind_4;
			}
		}
		ober = 87;
		while (count_new > ent){
			for (unsigned int i=1; i<m-1; i+=1){
				for (unsigned int j=1; j<n-1; j+=1){
					if (Sf_nl_2[i][j] == 2){
						
						for (unsigned int h=i-1; h<=i+1; h+=1){		//Stirbt Zelle?
							for (unsigned int k=j-1; k<=j+1; k+=1){
								if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
									if ((Sf_nl_2[h][k] == 2) || ((Sf[h][k] == 2) && (Sf_od_2[h][k] == 0))){
										a+=1;
									}
								}
							}	
						}
						if (a > 4){
							Index_Wert_2 += 3;
						}
						a = 0;
						
						Index_Wert_2 += 8;
						
						for (unsigned int h=i-1; h<=i+1; h+=1){		//Regeneriert neue Zellen?
							for (unsigned int k=j-1; k<=j+1; k+=1){
								if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
									if (((Sf[h][k] == 0) || ((Sf[h][k] == 2)&&(Sf_od_2[h][k] == 202))) && (Sf_nl_2[h][k] == 0)){
										for (unsigned int u=h-1; u<=h+1; u+=1){
											for (unsigned int o=k-1; o<=k+1; o+=1){
												if ((u>0)&&(u<(m-1))&&(o>0)&&(o<(n-1))){
													if ((Sf_nl_2[u][o] == 2) || ((Sf[u][o] == 2) && (Sf_od_2[u][o] == 0))){
														a += 1;
													}
												}
											}
										}
										if (a == 3){
											Index_Wert_2 -= 1;
										}
										a = 0;
									}
								}
							}
						}
						
														//printf("%u \n", Index_Wert_2);
						for (unsigned int h=i-1; h<=i+1; h+=1){		//Regeneriert ihr Tod neue Zellen?
							for (unsigned int k=j-1; k<=j+1; k+=1){
								if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
									if (((Sf[h][k] == 0) || ((Sf[h][k] == 2)&&(Sf_od_2[h][k] == 202))) && (Sf_nl_2[h][k] == 0)){
										for (unsigned int u=h-1; u<=h+1; u+=1){
											for (unsigned int o=k-1; o<=k+1; o+=1){
												if ((u>0)&&(u<(m-1))&&(o>0)&&(o<(n-1))){
													if ((Sf_nl_2[u][o] == 2) || ((Sf[u][o] == 2) && (Sf_od_2[u][o] == 0))){
														a += 1;
													}
												}
											}
										}
										if (a == 4){
											Index_Wert_2 += 1;
										} 
										a = 0;
										
									}
								}
							}
						}
						
						for (unsigned int h=i-1; h<=i+1; h+=1){		//sterben eigene Zellen?
							for (unsigned int k=j-1; k<=j+1; k+=1){
								if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
									if (((Sf[h][k] == 2) && (Sf_od_2[h][k] == 0)) ||(Sf_nl_2[h][k] == 2)){
										for (unsigned int u=h-1; u<=h+1; u+=1){
											for (unsigned int o=k-1; o<=k+1; o+=1){
												if ((u>0)&&(u<(m-1))&&(o>0)&&(o<(n-1))){
													if ((Sf_nl_2[u][o] == 2) || ((Sf[u][o] == 2) && (Sf_od_2[u][o] == 0))){
														a += 1;
													}
												}
											}
										}
										if (a > 4){
											Index_Wert_2 += 3;
										}
										a = 0;
									}
								}
							}
						}
						
						for (unsigned int h=i-1; h<=i+1; h+=1){		//tötet ihr Tod eigene Zellen?
							for (unsigned int k=j-1; k<=j+1; k+=1){
								if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
									if (((Sf[h][k] == 2) && (Sf_od_2[h][k] == 0)) ||(Sf_nl_2[h][k] == 2)){
										for (unsigned int u=h-1; u<=h+1; u+=1){
											for (unsigned int o=k-1; o<=k+1; o+=1){
												if ((u>0)&&(u<(m-1))&&(o>0)&&(o<(n-1))){
													if ((Sf_nl_2[u][o] == 2) || ((Sf[u][o] == 2) && (Sf_od_2[u][o] == 0))){
														a += 1;
													}
												}
											}
										}
										if (a < 4){
											b = 1;
										}
										a = 0;							
									}
								}
							}
						}
						if (b != 1){
							Index_Wert_2 += 10;
						} 
						b = 0;
						
						if (j > ((n-1)/2)){
							Index_Wert_2 += (j-(n-1)/2);
						} else if (j < ((n-1)/2)){
							Index_Wert_2 += (((n-1)/2)-j);
						}
						Index_Wert_2 += i;
						
						if (ind == 2) {
							Index_Wert_2 += i;
						}
						if (ind == 1) {
							Index_Wert_2 += (6-i);
						}
						
						if ((i <= 2)&&((j >= ((n-3)/2))&&(j <= ((n+1)/2)))){
							Index_Wert_2 = 1;
						}
						
						if ((rain == 31)||(rain == 32)||(rain == 2)){
							if (Sf[i-1][j] == 7){
								Index_Wert_2 = 80;
							}
						}
						
									//printf("%u \n", Index_Wert_2);
						Index_2_Feld[i][j] = Index_Wert_2;
						Index_Wert_2 = 0;
					}
				}
			}
			
			
			
			if (ind == 1){
				for (unsigned int i=1; i<m-1; i+=1){
					if (c == 1){
						break;
					}
					for (unsigned int j=1; j<n-1; j+=1){
						if (Index_2_Feld[i][j] == ober){
							Index_2_Feld[i][j] = 0;
							Sf_nl_2[i][j] = 0;
							count_new -= 1;
							ober = 87;
							c = 1;
							break;
						}
					}
				}
				if (c == 0){
					ober -= 1;
				}
			}
				
			if (ind == 2) {
				for (unsigned int i=(m-2); i>0; i-=1){
					if (c == 1){
						break;
					}
					for (unsigned int j=(n-2); j>0; j-=1){
						if (Index_2_Feld[i][j] == ober){
							Index_2_Feld[i][j] = 0;
							Sf_nl_2[i][j] = 0;
							count_new -= 1;
							ober = 87;
							c = 1;
							break;
						}
					}
				}
				if (c == 0){
					ober -= 1;
				}
			}
			c = 0;
			
			for (unsigned int t=1; t<m-1; t+=1){
				if (f == 1){
					break;
				}
				for (unsigned int z=1; z<n-1; z+=1){
					if (Sf_nl_2[t][z] == 2){
						f = 1;
						break;
					}
				}
			}
			if (f == 0){
				break;
			}
			f = 0;
		}
	}
	
	
	Spielfeld_Destroy (Index_2_Feld, m);
	
	return Sf_nl_2;
}

Spielfeld Index_1_hunt (unsigned int ent, unsigned int count_new, unsigned int m, unsigned int n, Spielfeld Sf_nl_1, Spielfeld Sf_od_1, unsigned int limit_new, unsigned int limit_at_all, unsigned int zeitgewinner, Spielfeld Sf, unsigned int number_of_players){
	unsigned int Index_Wert_1, a, b, c, f, ind_1, ind_3, ind, ober, heart_i, heart_j;
	Spielfeld Index_1_Feld;
	
	ind = 0;
	f = 0;
	b = 0;
	c = 0;
	a = 0;
	Index_Wert_1 = 0;
	Index_1_Feld = Spielfeld_Create (m, n);
	
	if (ent == limit_new) {
		ent = (ent + (number_of_players-3));
	} else if (ent == limit_at_all) {
		ent = (ent + 2* (number_of_players-3));
	}
	
	limit_new = (limit_new + (number_of_players-3));
	limit_at_all = (limit_at_all + (2*(number_of_players-3)));
	
	for (unsigned int i=1; i<m-1; i+=1){
		for (unsigned int j=1; j<n-1; j+=1){
			if (Sf[i][j] == 11) {
				heart_i = i;
				heart_j = j;
				a = 1;
				break;
			}
		}
		if (a == 1) {
			break;
		}
	}
	a = 0;
	
	if (zeitgewinner >= limit_at_all) {
		for (unsigned int i=1; i<m-1; i+=1){
			for (unsigned int j=1; j<n-1; j+=1){
				if (Sf_nl_1[i][j] == 1){
					Sf_nl_1[i][j] = 0;
				}
			}
		}
	} else {
		
		while ((ind != 1)&&(ind != 2)){
			printf (" \n");
			printf (" \n");
			printf (" How do you want to play: \n");
			printf (" \n");
			if (ent == limit_new){
				printf(" #produce	defensive: 1		offensive: 2 \n");
				scanf("%u", &ind_1);
				ind = ind_1;
			}
			
			if (ent == limit_at_all){
				printf(" #reduce	defensive: 1		offensive: 2 \n");
				scanf("%u", &ind_3);
				ind = ind_3;
			}
			printf (" \n");
		}
											//printf("ent: %u \n", ent); printf("\n");
											//printf("ind: %u \n", ind); printf("\n");
											//printf("count_new: %u \n", count_new); printf("\n");
		if (ind == 1) {
			ober = m+n;
			while (count_new > ent){
				for (unsigned int i=1; i<m-1; i+=1){
					for (unsigned int j=1; j<n-1; j+=1){
						if (Sf_nl_1[i][j] == 1){
							if (j >= heart_j) {
								if (i >= heart_i) {
									Index_Wert_1 = (i-heart_i-heart_j+j);
								} else if (i < heart_i) {
									Index_Wert_1 = (heart_i-i-heart_j+j);
								}
							} else if (j < heart_j) {
								if (i >= heart_i) {
									Index_Wert_1 = (i+heart_j-heart_i-j);
								} else if (i < heart_i) {
									Index_Wert_1 = (heart_i+heart_j-i-j);
								}
							}
							
							Index_1_Feld[i][j] = Index_Wert_1;
							Index_Wert_1 = 0;
						}
					}
				}
				
				
				
				for (unsigned int i=1; i<m-1; i+=1){
					if (c == 1){
						break;
					}
					for (unsigned int j=1; j<n-1; j+=1){
						if (Index_1_Feld[i][j] == ober){
							Index_1_Feld[i][j] = 0;
							Sf_nl_1[i][j] = 0;
							count_new -= 1;
							ober = m+n;
							c = 1;
							break;
						}
					}
				}
				if (c == 0){
					ober -= 1;
				}
				
				c = 0;
				for (unsigned int t=1; t<m-1; t+=1){
					if (f == 1){
						break;
					}
					for (unsigned int z=1; z<n-1; z+=1){
						if (Sf_nl_1[t][z] >= 1){
							f = 1;
							break;
						}
					}
				}
				if (f == 0){
					break;
				}
				f = 0;
			}
		} else if (ind == 2) {
			ober = 90;
			while (count_new > ent){
				for (unsigned int i=1; i<m-1; i+=1){
					for (unsigned int j=1; j<n-1; j+=1){
						if (Sf_nl_1[i][j] == 1){
							
							for (unsigned int h=i-1; h<=i+1; h+=1){		//Stirbt Zelle?
								for (unsigned int k=j-1; k<=j+1; k+=1){
									if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
										if ((Sf_nl_1[h][k] == 1) || (((Sf[h][k] == 11)||(Sf[h][k] == 1)) && (Sf_od_1[h][k] == 0))){
											a+=1;
										}
									}
								}	
							}
							if (a > 4){
								Index_Wert_1 += 3;
																	//printf("1.  %u \n", Index_Wert_1);
							}
							a = 0;
							
							Index_Wert_1 += (8*ind);
							for (unsigned int h=i-1; h<=i+1; h+=1){		//Regeneriert neue Zellen?
								for (unsigned int k=j-1; k<=j+1; k+=1){
									if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
										if (((Sf[h][k] == 0) || ((Sf[h][k] == 1)&&(Sf_od_1[h][k] == 101))) && (Sf_nl_1[h][k] == 0)){
											for (unsigned int u=h-1; u<=h+1; u+=1){
												for (unsigned int o=k-1; o<=k+1; o+=1){
													if ((u>0)&&(u<(m-1))&&(o>0)&&(o<(n-1))){
														if ((Sf_nl_1[u][o] == 1) || (((Sf[u][o] == 1)||(Sf[u][o] == 11)) && (Sf_od_1[u][o] == 0))){
															a += 1;
														}
													}
												}
											}
											if (a == 3){
												Index_Wert_1 -= ind;
																			//printf("2.  %u \n", Index_Wert_1);
											}
											a = 0;
										}
									}
								}
							}
							
							for (unsigned int h=i-1; h<=i+1; h+=1){		//Stört feindliches Wachstum?
								for (unsigned int k=j-1; k<=j+1; k+=1){
									if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
										if ((Sf[h][k] != 1)&&(Sf[h][k] != 11)){
											a+=1;
										}
									}
								}	
							}
							if (a != 3){
								Index_Wert_1 += 10;
																//printf("3.  %u \n", Index_Wert_1);
							}
							a = 0;
							
							if ((Sf[i-1][j]!=11)&&(Sf[i][j-1]!=11)&&(Sf[i+1][j]!=11)&&(Sf[i][j+1]!=11)){
								Index_Wert_1 += 10;
							}
							
							for (unsigned int h=i-1; h<=i+1; h+=1){		//Regeneriert ihr Tod neue Zellen?
								for (unsigned int k=j-1; k<=j+1; k+=1){
									if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
										if ((((Sf[h][k] == 0) || ((Sf[h][k] == 1)&&(Sf_od_1[h][k] == 101))) && (Sf_nl_1[h][k] == 0))&&(Sf[h][k] != 11)){
											for (unsigned int u=h-1; u<=h+1; u+=1){
												for (unsigned int o=k-1; o<=k+1; o+=1){
													if ((u>0)&&(u<(m-1))&&(o>0)&&(o<(n-1))){
														if ((Sf_nl_1[u][o] == 1) || (((Sf[u][o] == 1)||(Sf[u][o] == 11)) && (Sf_od_1[u][o] == 0))){
															a += 1;
														}
													}
												}
											}
											if (a == 4){
												Index_Wert_1 += ind;
																			//printf("4.  %u \n", Index_Wert_1);
											} 
											a = 0;
											
										}
									}
								}
							}
							
							for (unsigned int h=i-1; h<=i+1; h+=1){		//sterben eigene Zellen?
								for (unsigned int k=j-1; k<=j+1; k+=1){
									if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
										if (((Sf[h][k] == 1) && (Sf_od_1[h][k] == 0)) ||(Sf_nl_1[h][k] == 1)){
											for (unsigned int u=h-1; u<=h+1; u+=1){
												for (unsigned int o=k-1; o<=k+1; o+=1){
													if ((u>0)&&(u<(m-1))&&(o>0)&&(o<(n-1))){
														if (((Sf_nl_1[u][o] == 1) || ((Sf[u][o] == 1) && (Sf_od_1[u][o] == 0)))||(Sf[u][o] == 11)){
															a += 1;
														}
													}
												}
											}
											if (a > 4){
												Index_Wert_1 += 3;
																			//printf("5.  %u \n", Index_Wert_1);
											}
											a = 0;
										}
									}
								}
							}
							
							for (unsigned int h=i-1; h<=i+1; h+=1){		//tötet ihr Tod eigene Zellen?
								for (unsigned int k=j-1; k<=j+1; k+=1){
									if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
										if (((Sf[h][k] == 1) && (Sf_od_1[h][k] == 0)) ||(Sf_nl_1[h][k] == 1)){
											for (unsigned int u=h-1; u<=h+1; u+=1){
												for (unsigned int o=k-1; o<=k+1; o+=1){
													if ((u>0)&&(u<(m-1))&&(o>0)&&(o<(n-1))){
														if (((Sf_nl_1[u][o] == 1) || ((Sf[u][o] == 1) && (Sf_od_1[u][o] == 0)))||(Sf[u][o] == 11)){
															a += 1;
														}
													}
												}
											}
											if (a < 4){
												b = 1;
											}
											a = 0;
										}
									}
								}
							}
							if (b != 1){
								Index_Wert_1 += 10;
																		//printf("6.  %u \n", Index_Wert_1);
							} 
							b = 0;
							
																				//printf("	%u	%u	%u \n", i, j, Index_Wert_1);
							Index_1_Feld[i][j] = Index_Wert_1;
							Index_Wert_1 = 0;
						}
					}
				}
				//printf("\n");
				
				if (ind == 2){
					for (unsigned int i=1; i<m-1; i+=1){
						if (c == 1){
							break;
						}
						for (unsigned int j=1; j<n-1; j+=1){
							if (Index_1_Feld[i][j] == ober){
								Index_1_Feld[i][j] = 0;
								Sf_nl_1[i][j] = 0;
								count_new -= 1;
								ober = 90;
								c = 1;
								break;
							}
						}
					}
					if (c == 0){
						ober -= 1;
					}
				}
				
				if (ind == 1) {
					for (unsigned int i=m-2; i>0; i-=1){
						if (c == 1){
							break;
						}
						for (unsigned int j=n-2; j>0; j-=1){
							if (Index_1_Feld[i][j] == ober){
								Index_1_Feld[i][j] = 0;
								Sf_nl_1[i][j] = 0;
								count_new -= 1;
								ober = 90;
								c = 1;
								break;
							}
						}
					}
					if (c == 0){
						ober -= 1;
					}
				}
				
				c = 0;
																//printf("ent: %u \n", ent); printf("\n");
																//printf("ind: %u \n", ind); printf("\n");
																//printf("count_new: %u \n", count_new); printf("\n");
				
				for (unsigned int t=1; t<m-1; t+=1){
					if (f == 1){
						break;
					}
					for (unsigned int z=1; z<n-1; z+=1){
						if (Sf_nl_1[t][z] == 1){
							f = 1;
							break;
						}
					}
				}
				if (f == 0){
					break;
				}
				f = 0;
			}
		}
				//zu viele generiert, da Index_field[i][j] nicht zurückgesetzt, daher count_new mehrfach reduziert.
		
	}
	
	
	
	Spielfeld_Destroy (Index_1_Feld, m);
	
	return Sf_nl_1;
}

Spielfeld Index_other_hunt (unsigned int ent, unsigned int count_new, unsigned int m, unsigned int n, Spielfeld Sf_nl_other_hunt, unsigned int geben, unsigned int zeitgewinner, Spielfeld Sf, unsigned int limit_at_all){
	unsigned int Index_Wert_other_hunt, a, c, f, ober, heart_i, heart_j;
	Spielfeld Index_other_hunt_Feld;		//mehr als Limit-Steine auf dem Feld, Problem analysieren und beheben!
	
	c = 0;
	f = 0;
	a = 0;
	heart_i = 0;
	heart_j = 0;
	Index_Wert_other_hunt = 0;
	Index_other_hunt_Feld = Spielfeld_Create (m, n);
	
	for (unsigned int i=1; i<m-1; i+=1){
		for (unsigned int j=1; j<n-1; j+=1){
			if (Sf[i][j] == 11) {
				heart_i = i;
				heart_j = j;
				a = 1;
				break;
			}
		}
		if (a == 1) {
			break;
		}
	}
	a = 0;
	
	if (zeitgewinner >= limit_at_all) {
		for (unsigned int i=1; i<m-1; i+=1){
			for (unsigned int j=1; j<n-1; j+=1){
				if (Sf_nl_other_hunt[i][j] == geben) {
					Sf_nl_other_hunt[i][j] = 0;
				}
			}
		}
	} else {
	
		ober = m+n;
		while (count_new > ent){
			for (unsigned int i=1; i<m-1; i+=1){
				for (unsigned int j=1; j<n-1; j+=1){
					if (Sf_nl_other_hunt[i][j] == geben){
						if (j >= heart_j) {
							if (i >= heart_i) {
								Index_Wert_other_hunt = (i-heart_i-heart_j+j);
							} else if (i < heart_i) {
								Index_Wert_other_hunt = (heart_i-i-heart_j+j);
							}
						} else if (j < heart_j) {
							if (i >= heart_i) {
								Index_Wert_other_hunt = (i+heart_j-heart_i-j);
							} else if (i < heart_i) {
								Index_Wert_other_hunt = (heart_i+heart_j-i-j);
							}
						}
							
						Index_other_hunt_Feld[i][j] = Index_Wert_other_hunt;
						Index_Wert_other_hunt = 0;
					}
				}
			}
			
			
			
			for (unsigned int i=1; i<m-1; i+=1){
				if (c == 1){
					break;
				}
				for (unsigned int j=1; j<n-1; j+=1){
					if (Index_other_hunt_Feld[i][j] == ober){
						Index_other_hunt_Feld[i][j] = 0;
						Sf_nl_other_hunt[i][j] = 0;
						count_new -= 1;
						ober = m+n;
						c = 1;
						break;
					}
				}
			}
			if (c == 0){
				ober -= 1;
			}
			
			c = 0;
			for (unsigned int t=1; t<m-1; t+=1){
				if (f == 1){
					break;
				}
				for (unsigned int z=1; z<n-1; z+=1){
					if (Sf_nl_other_hunt[t][z] >= 1){
						f = 1;
						break;
					}
				}
			}
			if (f == 0){
				break;
			}
			f = 0;
		}
	
	}
	
	Spielfeld_Destroy (Index_other_hunt_Feld, m);
	
	return Sf_nl_other_hunt;
}

Spielfeld Index_are (unsigned int ent, unsigned int count_new, unsigned int m, unsigned int n, Spielfeld Sf_nl, Spielfeld Sf_od, unsigned int limit_new, unsigned int limit_at_all, unsigned int zeitgewinner, Spielfeld Sf, unsigned int w, unsigned int d, unsigned int e, unsigned int geben){
	unsigned int Index_Wert, a, b, c, f, ind, ober;
	Spielfeld Index_Feld;
	
	ind = 0;
	f = 0;
	b = 0;
	c = 0;
	a = 0;
	Index_Wert = 0;
	Index_Feld = Spielfeld_Create (m, n);
	
	if (d == 10) {
		d = 0;
	}
	
	if (zeitgewinner >= limit_at_all) {
		for (unsigned int i=1; i<m-1; i+=1){
			for (unsigned int j=1; j<n-1; j+=1){
				if (Sf_nl[i][j] == geben){
					Sf_nl[i][j] = 0;
				}
			}
		}
	} else {
		
		while ((ind != 1)&&(ind != 2)){
			printf (" \n");
			printf (" \n");
			printf (" How do you want to play: \n");
			printf (" \n");
			if (ent == limit_new){
				printf(" #produce	defensive: 1		offensive: 2 \n");
				scanf("%u", &ind);
			}
			
			if (ent == limit_at_all){
				printf(" #reduce	defensive: 1		offensive: 2 \n");
				scanf("%u", &ind);
			}
			printf (" \n");
		}
		if (ind == 1) {
			ober = 90;
		} else if (ind == 2) {
			ober = 10;
		}
		
		
		while (count_new > ent){
			if (ind == 1) {
				for (unsigned int i=1; i<m-1; i+=1){
					for (unsigned int j=1; j<n-1; j+=1){
						if (Sf_nl[i][j] == geben){
							
							for (unsigned int h=i-1; h<=i+1; h+=1){		//Stirbt Zelle?
								for (unsigned int k=j-1; k<=j+1; k+=1){
									if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
										if ((Sf_nl[h][k] == geben) || ((Sf[h][k] == geben) && (Sf_od[h][k] == 0))){
											a+=1;
										}
									}
								}	
							}
							if (a > e+1){
								Index_Wert += 3;
							}
							a = 0;
							
							Index_Wert += (8*ind);
							for (unsigned int h=i-1; h<=i+1; h+=1){		//Regeneriert neue Zellen?
								for (unsigned int k=j-1; k<=j+1; k+=1){
									if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
										if (((Sf[h][k] == 0) || ((Sf[h][k] == geben)&&(Sf_od[h][k] == (100*geben+geben)))) && (Sf_nl[h][k] == 0)){
											for (unsigned int u=h-1; u<=h+1; u+=1){
												for (unsigned int o=k-1; o<=k+1; o+=1){
													if ((u>0)&&(u<(m-1))&&(o>0)&&(o<(n-1))){
														if ((Sf_nl[u][o] == geben) || ((Sf[u][o] == geben) && (Sf_od[u][o] == 0))){
															a += 1;
														}
													}
												}
											}
											if (a == w){
												Index_Wert -= ind;
											}
											a = 0;
										}
									}
								}
							}
							
							for (unsigned int h=i-1; h<=i+1; h+=1){		//Stört feindliches Wachstum?
								for (unsigned int k=j-1; k<=j+1; k+=1){
									if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
										if (Sf[h][k] != geben){
											a+=1;
										}
									}
								}	
							}
							if (a != 3){
								Index_Wert += 10;
							}
							a = 0;
							
							for (unsigned int h=i-1; h<=i+1; h+=1){		//Regeneriert ihr Tod neue Zellen?
								for (unsigned int k=j-1; k<=j+1; k+=1){
									if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
										if (((Sf[h][k] == 0) || ((Sf[h][k] == geben)&&(Sf_od[h][k] == (100*geben + geben)))) && (Sf_nl[h][k] == 0)){
											for (unsigned int u=h-1; u<=h+1; u+=1){
												for (unsigned int o=k-1; o<=k+1; o+=1){
													if ((u>0)&&(u<(m-1))&&(o>0)&&(o<(n-1))){
														if ((Sf_nl[u][o] == geben) || ((Sf[u][o] == geben) && (Sf_od[u][o] == 0))){
															a += 1;
														}
													}
												}
											}
											if (a == w+1){
												Index_Wert += ind;
											} 
											a = 0;
											
										}
									}
								}
							}
							
							for (unsigned int h=i-1; h<=i+1; h+=1){		//sterben eigene Zellen?
								for (unsigned int k=j-1; k<=j+1; k+=1){
									if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
										if (((Sf[h][k] == geben) && (Sf_od[h][k] == 0)) ||(Sf_nl[h][k] == geben)){
											for (unsigned int u=h-1; u<=h+1; u+=1){
												for (unsigned int o=k-1; o<=k+1; o+=1){
													if ((u>0)&&(u<(m-1))&&(o>0)&&(o<(n-1))){
														if ((Sf_nl[u][o] == geben) || ((Sf[u][o] == geben) && (Sf_od[u][o] == 0))){
															a += 1;
														}
													}
												}
											}
											if (a > e+1){
												Index_Wert += 3;
											}
											a = 0;
										}
									}
								}
							}
							
							for (unsigned int h=i-1; h<=i+1; h+=1){		//tötet ihr Tod eigene Zellen?
								for (unsigned int k=j-1; k<=j+1; k+=1){
									if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
										if (((Sf[h][k] == geben) && (Sf_od[h][k] == 0)) ||(Sf_nl[h][k] == geben)){
											for (unsigned int u=h-1; u<=h+1; u+=1){
												for (unsigned int o=k-1; o<=k+1; o+=1){
													if ((u>0)&&(u<(m-1))&&(o>0)&&(o<(n-1))){
														if ((Sf_nl[u][o] == geben) || ((Sf[u][o] == geben) && (Sf_od[u][o] == 0))){
															a += 1;
														}
													}
												}
											}
											if (a < d+1){
												b = 1;
											}
											a = 0;
										}
									}
								}
							}
							if (b != 1){
								Index_Wert += 10;
							} 
							b = 0;
							
							Index_Feld[i][j] = Index_Wert;
							Index_Wert = 0;
						}
					}
				}
			} else if (ind == 2) {
				a = 0;
				for (unsigned int i=1; i<m-1; i+=1){
					for (unsigned int j=1; j<n-1; j+=1){
						if (Sf_nl[i][j] == geben){
							for (unsigned int h=i-1; h<=i+1; h+=1){
								for (unsigned int k=j-1; k<=j+1; k+=1){
									if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
										if ((Sf[h][k] != geben)&&(Sf[h][k] != 0)) {
											Index_Wert += 1;
										} else if (Sf[h][k] == geben) {
											a += 1;
										}
									}
								}
							}
							
							if ((a > d)&&(a <= e+1)) {
								Index_Wert += 1;
							}
							a = 0;
							Index_Feld[i][j] = (10 - Index_Wert);
							Index_Wert = 0;
						}
					}
				}
			}
				
			if (ind == 2){
				for (unsigned int i=1; i<m-1; i+=1){
					if (c == 1){
						break;
					}
					for (unsigned int j=1; j<n-1; j+=1){
						if (Index_Feld[i][j] == ober){
							Index_Feld[i][j] = 0;
							Sf_nl[i][j] = 0;
							count_new -= 1;
							ober = 10;
							c = 1;
							break;
						}
					}
				}
				if (c == 0){
					ober -= 1;
				}
			}
			
			if (ind == 1) {
				for (unsigned int i=m-2; i>0; i-=1){
					if (c == 1){
						break;
					}
					for (unsigned int j=n-2; j>0; j-=1){
						if (Index_Feld[i][j] == ober){
							Index_Feld[i][j] = 0;
							Sf_nl[i][j] = 0;
							count_new -= 1;
							ober = 90;
							c = 1;
							break;
						}
					}
				}
				if (c == 0){
					ober -= 1;
				}
			}
			
			c = 0;
															//printf("ent: %u \n", ent); printf("\n");
															//printf("ind: %u \n", ind); printf("\n");
															//printf("count_new: %u \n", count_new); printf("\n");
				
			for (unsigned int t=1; t<m-1; t+=1){
				if (f == 1){
					break;
				}
				for (unsigned int z=1; z<n-1; z+=1){
					if (Sf_nl[t][z] == geben){
						f = 1;
						break;
					}
				}
			}
			if (f == 0){
				break;
			}
			f = 0;			
		}
	}
	
	return Sf_nl;
}

Spielfeld Index_dyn (unsigned int ent, unsigned int count_new, unsigned int m, unsigned int n, Spielfeld Sf_nl, Spielfeld Sf_od, unsigned int limit_new, unsigned int limit_at_all, unsigned int zeitgewinner, Spielfeld Sf, unsigned int w, unsigned int d, unsigned int e, unsigned int geben, unsigned int* position){
	unsigned int Index_Wert, a, b, c, f, ind, ober;
	Spielfeld Index_Feld;
	
	ind = 0;
	f = 0;
	b = 0;
	c = 0;
	a = 0;
	Index_Wert = 0;
	Index_Feld = Spielfeld_Create (m, n);
	
	if (zeitgewinner >= limit_at_all) {
		for (unsigned int i=1; i<m-1; i+=1){
			for (unsigned int j=1; j<n-1; j+=1){
				if (Sf_nl[i][j] == geben){
					Sf_nl[i][j] = 0;
				}
			}
		}
	} else {
		
		while ((ind != 1)&&(ind != 2)){
			printf (" \n");
			printf (" \n");
			printf (" How do you want to play: \n");
			printf (" \n");
			if (ent == limit_new){
				printf(" #produce	defensive: 1		offensive: 2 \n");
				scanf("%u", &ind);
			}
			
			if (ent == limit_at_all){
				printf(" #reduce	defensive: 1		offensive: 2 \n");
				scanf("%u", &ind);
			}
			printf (" \n");
		}
		if (ind == 1) {
			ober = 80;
		} else if (ind == 2) {
			ober = m+n;
		}
		
		
		while (count_new > ent){
			if (ind == 1) {
				for (unsigned int i=1; i<m-1; i+=1){
					for (unsigned int j=1; j<n-1; j+=1){
						if (Sf_nl[i][j] == geben){
							
							for (unsigned int h=i-1; h<=i+1; h+=1){		//Stirbt Zelle?
								for (unsigned int k=j-1; k<=j+1; k+=1){
									if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
										if ((Sf_nl[h][k] == geben) || ((Sf[h][k] == geben) && (Sf_od[h][k] == 0))){
											a+=1;
										}
									}
								}	
							}
							if (a > e+1){
								Index_Wert += 3;
							}
							a = 0;
							
							Index_Wert += (8*ind);
							for (unsigned int h=i-1; h<=i+1; h+=1){		//Regeneriert neue Zellen?
								for (unsigned int k=j-1; k<=j+1; k+=1){
									if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
										if (((Sf[h][k] == 0) || ((Sf[h][k] == geben)&&(Sf_od[h][k] == (100*geben+geben)))) && (Sf_nl[h][k] == 0)){
											for (unsigned int u=h-1; u<=h+1; u+=1){
												for (unsigned int o=k-1; o<=k+1; o+=1){
													if ((u>0)&&(u<(m-1))&&(o>0)&&(o<(n-1))){
														if ((Sf_nl[u][o] == geben) || ((Sf[u][o] == geben) && (Sf_od[u][o] == 0))){
															a += 1;
														}
													}
												}
											}
											if (a == w){
												Index_Wert -= ind;
											}
											a = 0;
										}
									}
								}
							}
							
							for (unsigned int h=i-1; h<=i+1; h+=1){		//Regeneriert ihr Tod neue Zellen?
								for (unsigned int k=j-1; k<=j+1; k+=1){
									if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
										if (((Sf[h][k] == 0) || ((Sf[h][k] == geben)&&(Sf_od[h][k] == (100*geben + geben)))) && (Sf_nl[h][k] == 0)){
											for (unsigned int u=h-1; u<=h+1; u+=1){
												for (unsigned int o=k-1; o<=k+1; o+=1){
													if ((u>0)&&(u<(m-1))&&(o>0)&&(o<(n-1))){
														if ((Sf_nl[u][o] == geben) || ((Sf[u][o] == geben) && (Sf_od[u][o] == 0))){
															a += 1;
														}
													}
												}
											}
											if (a == w+1){
												Index_Wert += ind;
											} 
											a = 0;
											
										}
									}
								}
							}
							
							for (unsigned int h=i-1; h<=i+1; h+=1){		//sterben eigene Zellen?
								for (unsigned int k=j-1; k<=j+1; k+=1){
									if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
										if (((Sf[h][k] == geben) && (Sf_od[h][k] == 0)) ||(Sf_nl[h][k] == geben)){
											for (unsigned int u=h-1; u<=h+1; u+=1){
												for (unsigned int o=k-1; o<=k+1; o+=1){
													if ((u>0)&&(u<(m-1))&&(o>0)&&(o<(n-1))){
														if ((Sf_nl[u][o] == geben) || ((Sf[u][o] == geben) && (Sf_od[u][o] == 0))){
															a += 1;
														}
													}
												}
											}
											if (a > e+1){
												Index_Wert += 3;
											}
											a = 0;
										}
									}
								}
							}
							
							for (unsigned int h=i-1; h<=i+1; h+=1){		//tötet ihr Tod eigene Zellen?
								for (unsigned int k=j-1; k<=j+1; k+=1){
									if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
										if (((Sf[h][k] == geben) && (Sf_od[h][k] == 0)) ||(Sf_nl[h][k] == geben)){
											for (unsigned int u=h-1; u<=h+1; u+=1){
												for (unsigned int o=k-1; o<=k+1; o+=1){
													if ((u>0)&&(u<(m-1))&&(o>0)&&(o<(n-1))){
														if ((Sf_nl[u][o] == geben) || ((Sf[u][o] == geben) && (Sf_od[u][o] == 0))){
															a += 1;
														}
													}
												}
											}
											if (a < d+1){
												b = 1;
											}
											a = 0;
										}
									}
								}
							}
							if (b != 1){
								Index_Wert += 10;
							} 
							b = 0;
							
							if ((i == position[1])||(j == position[0])) {
								Index_Wert = 1;
							}
							
							Index_Feld[i][j] = Index_Wert;
							Index_Wert = 0;
						}
					}
				}
			} else if (ind == 2) {
				
				for (unsigned int i=1; i<m-1; i+=1){
					for (unsigned int j=1; j<n-1; j+=1){
						if (Sf_nl[i][j] == geben){
							
							Index_Feld[i][j] = abs(i-position[1])+abs(j-position[0]);
							
						}
					}
				}
			}
			
			if (ind == 2){
				for (unsigned int i=1; i<m-1; i+=1){
					if (c == 1){
						break;
					}
					for (unsigned int j=1; j<n-1; j+=1){
						if (Index_Feld[i][j] == ober){
							Index_Feld[i][j] = 0;
							Sf_nl[i][j] = 0;
							count_new -= 1;
							ober = m+n;
							c = 1;
							break;
						}
					}
				}
				if (c == 0){
					ober -= 1;
				}
			}
			
			if (ind == 1) {
				for (unsigned int i=m-2; i>0; i-=1){
					if (c == 1){
						break;
					}
					for (unsigned int j=n-2; j>0; j-=1){
						if (Index_Feld[i][j] == ober){
							Index_Feld[i][j] = 0;
							Sf_nl[i][j] = 0;
							count_new -= 1;
							ober = 80;
							c = 1;
							break;
						}
					}
				}
				if (c == 0){
					ober -= 1;
				}
			}
			
			c = 0;
															//printf("ent: %u \n", ent); printf("\n");
															//printf("ind: %u \n", ind); printf("\n");
															//printf("count_new: %u \n", count_new); printf("\n");
				
			for (unsigned int t=1; t<m-1; t+=1){
				if (f == 1){
					break;
				}
				for (unsigned int z=1; z<n-1; z+=1){
					if (Sf_nl[t][z] == geben){
						f = 1;
						break;
					}
				}
			}
			if (f == 0){
				break;
			}
			f = 0;			
		}
	}
	
	return Sf_nl;
}

void battle (unsigned int m, unsigned int n, Spielfeld Sf, unsigned int geben){
	Spielfeld chain, chain_temp;
	unsigned int geben_op, chain_total_1, chain_total_2;
	
	geben_op = (geben%2)+1;
	chain_total_1 = 0;
	chain_total_2 = 0;
	chain = Spielfeld_Create (m, n);
	
	for (unsigned int i=1; i<m-1; i+=1){
		for (unsigned int j=1; j<n-1; j+=1){
			if (Sf[i][j] == geben){
				chain_temp = Spielfeld_Create (m, n);
				if ((Sf[i][j+1] == geben_op)&&(chain_temp[i][j+1] != geben_op)){
					chain_temp[i][j] = geben;
					chain_total_1 = 1;
					chain_total_1 = chain_count (i, j, Sf, chain_temp, geben, chain_total_1);
					
					chain_temp[i][j+1] = geben_op;
					chain_total_2 = 1;
					chain_total_2 = chain_count (i, (j+1), Sf, chain_temp, geben_op, chain_total_2);
					
					if (chain_total_1 > chain_total_2){
						for (unsigned int h=1; h<m-1; h+=1){
							for (unsigned int k=1; k<n-1; k+=1){
								if (chain_temp[h][k] == geben_op){
									chain[h][k] = geben;
								}
							}
						}
					} else if (chain_total_2 > chain_total_1){
						for (unsigned int h=1; h<m-1; h+=1){
							for (unsigned int k=1; k<n-1; k+=1){
								if (chain_temp[h][k] == geben){
									chain[h][k] = geben_op;
								}
							}
						}
					} else if ((chain_total_1 == chain_total_2)&&(chain_total_1 == 1)){
						chain[i][j+1] = geben;
					}
					
				}
				
				if ((Sf[i][j-1] == geben_op)&&(chain_temp[i][j-1] != geben_op)){
					Spielfeld_Destroy (chain_temp, m);
					chain_temp = Spielfeld_Create (m, n);
					
					chain_temp[i][j] = geben;
					chain_total_1 = 1;
					chain_total_1 = chain_count (i, j, Sf, chain_temp, geben, chain_total_1);
					
					chain_temp[i][j-1] = geben_op;
					chain_total_2 = 1;
					chain_total_2 = chain_count (i, (j-1), Sf, chain_temp, geben_op, chain_total_2);
					
					if (chain_total_1 > chain_total_2){
						for (unsigned int h=1; h<m-1; h+=1){
							for (unsigned int k=1; k<n-1; k+=1){
								if (chain_temp[h][k] == geben_op){
									chain[h][k] = geben;
								}
							}
						}
					} else if (chain_total_2 > chain_total_1){
						for (unsigned int h=1; h<m-1; h+=1){
							for (unsigned int k=1; k<n-1; k+=1){
								if (chain_temp[h][k] == geben){
									chain[h][k] = geben_op;
								}
							}
						}
					} else if ((chain_total_1 == chain_total_2)&&(chain_total_1 == 1)){
						chain[i][j-1] = geben;
					}
					
				}
				
				if ((Sf[i+1][j] == geben_op)&&(chain_temp[i+1][j] != geben_op)){
					Spielfeld_Destroy (chain_temp, m);
					chain_temp = Spielfeld_Create (m, n);
					
					chain_temp[i][j] = geben;
					chain_total_1 = 1;
					chain_total_1 = chain_count (i, j, Sf, chain_temp, geben, chain_total_1);
					
					chain_temp[i+1][j] = geben_op;
					chain_total_2 = 1;
					chain_total_2 = chain_count ((i+1), j, Sf, chain_temp, geben_op, chain_total_2);
					
					if (chain_total_1 > chain_total_2){
						for (unsigned int h=1; h<m-1; h+=1){
							for (unsigned int k=1; k<n-1; k+=1){
								if (chain_temp[h][k] == geben_op){
									chain[h][k] = geben;
								}
							}
						}
					} else if (chain_total_2 > chain_total_1){
						for (unsigned int h=1; h<m-1; h+=1){
							for (unsigned int k=1; k<n-1; k+=1){
								if (chain_temp[h][k] == geben){
									chain[h][k] = geben_op;
								}
							}
						}
					} else if ((chain_total_1 == chain_total_2)&&(chain_total_1 == 1)){
						chain[i+1][j] = geben;
					}
					
				}
				
				if ((Sf[i-1][j] == geben_op)&&(chain_temp[i-1][j] != geben_op)){
					Spielfeld_Destroy (chain_temp, m);
					chain_temp = Spielfeld_Create (m, n);
					
					chain_temp[i][j] = geben;
					chain_total_1 = 1;
					chain_total_1 = chain_count (i, j, Sf, chain_temp, geben, chain_total_1);
					
					chain_temp[i-1][j] = geben_op;
					chain_total_2 = 1;
					chain_total_2 = chain_count ((i-1), j, Sf, chain_temp, geben_op, chain_total_2);
					
					if (chain_total_1 > chain_total_2){
						for (unsigned int h=1; h<m-1; h+=1){
							for (unsigned int k=1; k<n-1; k+=1){
								if (chain_temp[h][k] == geben_op){
									chain[h][k] = geben;
								}
							}
						}
					} else if (chain_total_2 > chain_total_1){
						for (unsigned int h=1; h<m-1; h+=1){
							for (unsigned int k=1; k<n-1; k+=1){
								if (chain_temp[h][k] == geben){
									chain[h][k] = geben_op;
								}
							}
						}
					} else if ((chain_total_1 == chain_total_2)&&(chain_total_1 == 1)){
						chain[i-1][j] = geben;
					}
					
				}
				
				Spielfeld_Destroy (chain_temp, m);
				
			}
		}
	}
	
	for (unsigned int i=1; i<m-1; i+=1){
		for (unsigned int j=1; j<n-1; j+=1){
			if (chain[i][j] == 1){
				Sf[i][j] = 1;
			} else if (chain[i][j] == 2){
				Sf[i][j] = 2;
			}
		}
	}
	
	Spielfeld_Destroy (chain, m);
	
}

unsigned int chain_count (unsigned int i, unsigned int j, Spielfeld Sf, Spielfeld chain_temp, unsigned int player, unsigned int chain_total){	//player=geben
	if ((Sf[i][j+1] == player)&&(chain_temp[i][j+1] != player)){
		chain_temp[i][j+1] = player;
		chain_total += 1;
		chain_total = chain_count (i, (j+1), Sf, chain_temp, player, chain_total);
	}
	if ((Sf[i][j-1] == player)&&(chain_temp[i][j-1] != player)){
		chain_temp[i][j-1] = player;
		chain_total += 1;
		chain_total = chain_count (i, (j-1), Sf, chain_temp, player, chain_total);
	}
	if ((Sf[i+1][j] == player)&&(chain_temp[i+1][j] != player)){
		chain_temp[i+1][j] = player;
		chain_total += 1;
		chain_total = chain_count ((i+1), j, Sf, chain_temp, player, chain_total);
	}
	if ((Sf[i-1][j] == player)&&(chain_temp[i-1][j] != player)){
		chain_temp[i-1][j] = player;
		chain_total += 1;
		chain_total = chain_count ((i-1), j, Sf, chain_temp, player, chain_total);
	}
	
	return chain_total;
}

unsigned int random_number (unsigned int num_1, unsigned int num_2, unsigned int num_3, unsigned int use_number, unsigned int g, unsigned int* var_, unsigned int number_3, unsigned int number_4){
	unsigned int temp_number, new_number, c, mult, inkre, modu, zusatz;
	
	mult = 7;
	inkre = 5;
	modu = 6;
	zusatz = ((g + var_[1] + var_[2] + number_3 + number_4 )%60)%6;
	
	temp_number = (num_1 % 2)+(num_2 % 3)+2*(num_3 % 3);
	
	if (temp_number <= 1){
		c = 1;
	} else if (temp_number >= 6){
		c = 6;
	} else {
		c = temp_number;
	}
	
	new_number = (mult*use_number + inkre + c + zusatz)%modu;
	
	if (new_number == 0){
		new_number = 6;
	}
	
	return new_number;
}

void touch (Spielfeld Sf, unsigned int m, unsigned int n, unsigned int geben, Spielfeld Sf_nl_1, Spielfeld Sf_nl_2){
	unsigned int einmal;
	einmal = 0;
	for (unsigned int i=1; i<m-1; i+=1){
		for (unsigned int j=1; j<n-1; j+=1){
			if (Sf[i][j] == 7){
				
				//test printf("	#-Block alt:	i=%u ,	j=%u \n ", i, j);
				
				if (geben == 1){
					if (((Sf_nl_1[i][j-1] == 1) || (Sf[i][j-1] == 1))&&(j != (n-2))){
						Sf[i][j+1] = 7;
						Sf[i][j] = 0;
					} else if (((Sf_nl_1[i+1][j] == 1)  || (Sf[i+1][j] == 1))&&(i != 1)){
						Sf[i-1][j] = 7;
						Sf[i][j] = 0;
					} else if (((Sf_nl_1[i-1][j] == 1) || (Sf[i-1][j] == 1))&&(i != (m-2))){
						Sf[i+1][j] = 7;
						Sf[i][j] = 0;
					} else if (((Sf_nl_1[i][j+1] == 1) || (Sf[i][j+1] == 1))&&(j != 1)){
						Sf[i][j-1] = 7;
						Sf[i][j] = 0;
					}
				} else if (geben == 2){
					if (((Sf_nl_2[i][j+1] == 2) || (Sf[i][j+1] == 2))&&(j != 1)){
						Sf[i][j-1] = 7;
						Sf[i][j] = 0;
					} else if (((Sf_nl_2[i+1][j] == 2) || (Sf[i+1][j] == 2))&&(i != 1)){
						Sf[i-1][j] = 7;
						Sf[i][j] = 0;
					} else if (((Sf_nl_2[i-1][j] == 2) || (Sf[i-1][j] == 2))&&(i != (m-2))){
						Sf[i+1][j] = 7;
						Sf[i][j] = 0;
					} else if (((Sf_nl_2[i][j-1] == 2) || (Sf[i][j-1] == 2))&&(j != (n-2))){
						Sf[i][j+1] = 7;
						Sf[i][j] = 0;
					}
				}
				einmal = 1;
				
				//test printf("	#-Block neu:	i=%u ,	j=%u \n ", i, j);
				
				break;
				
			}
			
		}
			if (einmal == 1){
				break;
			}
	}
	einmal = 0;
	
}

void ahead (Spielfeld Sf, unsigned int m, unsigned int count_freq){
	
	for (unsigned int i=1; i<m-1; i+=1){
		for (unsigned int j=1; j<count_freq; j+=1){
			if (Sf[i][j] == 7){
				Sf[i][j] = 0;
				Sf[i][j+1] = 7;
			}
		}
	}
}


void choose_heart (Spielfeld Sf, unsigned int m, unsigned int n){
	unsigned int heart_i_wanted, heart_j_wanted, a, heart_i, heart_j;
	Spielfeld ground_temp;
	
	ground_temp = Spielfeld_Create (m, n);
	heart_i_wanted = 0;
	heart_j_wanted = 0;
	a = 0;
	
	for (unsigned int i=1; i<m-1; i+=1){
		for (unsigned int j=1; j<n-1; j+=1){
			if (Sf[i][j] == 11){
				heart_i = i;
				heart_j = j;
				a = 1;
				break;
			}
		}
		if (a == 1) {
			break;
		}
	}
	a = 0;
	
	heart_ground (heart_i, heart_j, Sf, ground_temp);
	while ((heart_i_wanted == 0)||(heart_i_wanted >= m-1)||(heart_j_wanted >= n-1)||(heart_i_wanted == 0)) {
		printf(" Choose the next position of your heart-block: \n");
		printf("	\n");
		printf(" Zeile: \n Spalte: \n");
		scanf("%u %u", &heart_i_wanted, &heart_j_wanted);
	}
	
	
	if (Sf[heart_i_wanted][heart_j_wanted] == 11) {
		Sf[heart_i_wanted][heart_j_wanted] = 11;
	} else if (ground_temp[heart_i_wanted][heart_j_wanted] != 111) {
		printf("	You made a mistake, try again: \n");
		printf("\n");
		choose_heart (Sf, m, n);
	} else if (ground_temp[heart_i_wanted][heart_j_wanted] == 111) {
		Sf[heart_i][heart_j] = 1;
		Sf[heart_i_wanted][heart_j_wanted] = 11;
	}
	
	Spielfeld_Destroy (ground_temp, m);
}

void heart_ground (unsigned int i, unsigned int j, Spielfeld Sf, Spielfeld ground_temp){
	if ((Sf[i][j+1] == 1)&&(ground_temp[i][j+1] != 111)){
		ground_temp[i][j+1] = 111;
		heart_ground (i, (j+1), Sf, ground_temp);
	}
	if ((Sf[i][j-1] == 1)&&(ground_temp[i][j-1] != 111)){
		ground_temp[i][j-1] = 111;
		heart_ground (i, (j-1), Sf, ground_temp);
	}
	if ((Sf[i+1][j] == 1)&&(ground_temp[i+1][j] != 111)){
		ground_temp[i+1][j] = 111;
		heart_ground ((i+1), j, Sf, ground_temp);
	}
	if ((Sf[i-1][j] == 1)&&(ground_temp[i-1][j] != 111)){
		ground_temp[i-1][j] = 111;
		heart_ground ((i-1), j, Sf, ground_temp);
	}
}

Spielfeld opague_builder (Spielfeld Sf, unsigned int m, unsigned int n, unsigned int geben, unsigned int opague, unsigned int aop) {
	unsigned int extra;
	unsigned int* opague_counter; 
	Spielfeld temp;
	
	//printf("opague: %u \n", opague);		//test
	
	extra = 1;	//alle zusätzlichen Werte neben den aop-Spielerwerten
	opague_counter = unsigned_int_Vektor_Create(1+aop+extra);
	temp = Spielfeld_Create (m, n);
	
	for (unsigned int p=0; p<=aop+extra; p+=1) {
		opague_counter[p] = 0;
	}
	
	for (unsigned int i=1; i<m-1; i+=1){
		for (unsigned int j=1; j<n-1; j+=1){
			
			if (opague >= 20) {		//4-Mode-Opague, near-by
			
				if (Sf[i][j] != 11) {
					if (Sf[i][j] == geben) {
						temp[i][j] = geben;
					} else if ((Sf[i][j] != 0)) {
						if (Sf[i][j] == 77) {
							opague_counter[10] += 1;
						} else {
							opague_counter[Sf[i][j]] += 1;
						}
					}
				}
				
				if ((i<(m-2))&&(Sf[i][j] != 11)) {
					if (Sf[i][j] == geben) {
						temp[i+1][j] = Sf[i+1][j];
					} else if ((Sf[i+1][j] != 11)&&(Sf[i+1][j] != 0)) {
						if (Sf[i+1][j] == 77) {
							opague_counter[10] += 1;
						} else {
							opague_counter[Sf[i+1][j]] += 1;
						}
					}
				}
				
				if ((i>1)&&(Sf[i][j] != 11)) {
					if (Sf[i][j] == geben) {
						temp[i-1][j] = Sf[i-1][j];
					} else if ((Sf[i-1][j] != 11)&&(Sf[i-1][j] != 0)) {
						if (Sf[i-1][j] == 77) {
							opague_counter[10] += 1;
						} else {
							opague_counter[Sf[i-1][j]] += 1;
						}
					}
				}
				
				if ((j>1)&&(Sf[i][j] != 11)) {
					if (Sf[i][j] == geben) {
						temp[i][j-1] = Sf[i][j-1];
					} else if ((Sf[i][j-1] != 11)&&(Sf[i][j-1] != 0)) {
						if (Sf[i][j-1] == 77) {
							opague_counter[10] += 1;
						} else {
							opague_counter[Sf[i][j-1]] += 1;
						}
					}
				}
				
				if ((j<(n-2))&&(Sf[i][j] != 11)) {
					if (Sf[i][j] == geben) {
						temp[i][j+1] = Sf[i][j+1];
					} else if ((Sf[i][j+1] != 11)&&(Sf[i][j+1] != 0)) {
						if (Sf[i][j+1] == 77) {
							opague_counter[10] += 1;
						} else {
							opague_counter[Sf[i][j+1]] += 1;
						}
					}
				}
				
				if ((Sf[i][j+1] == geben)||(Sf[i][j-1] == geben)||(Sf[i-1][j] == geben)||(Sf[i+1][j] == geben)) {
					
					for (unsigned int p=0; p<=aop+extra; p+=1) {
						opague_counter[p] = 0;
					}
					
				}
				
				if (opague % 10 == 1) {		//4-Mode-Opague, uneven
					for (unsigned int p=1; p<=aop+extra; p+=1) {
						if (opague_counter[p] % 2 == 0) {
							opague_counter[p] = 0;
						}
					}	//p=10: 77
					
				} else if (opague % 10 == 2) {		//4-Mode-Opague, even
					for (unsigned int p=1; p<=aop+extra; p+=1) {
						if (opague_counter[p] % 2 == 1) {
							opague_counter[p] = 0;
						}
					}	//p=10: 77
					
				}
				
				opague_counter[0] = 0;
				
				for (unsigned int a=1; a<=aop+extra; a+=1) {
					if (a != geben) {
						if (opague_counter[a] != 0) {
							
							for (unsigned int b=1; b<=aop+extra; b+=1) {
								if (a != b) {
									if (opague_counter[a] > opague_counter[b]) {	//für b > number_of_players gilt opague_counter[b] = 0;
										opague_counter[0] += 1;
									}
								}
							}
							
							if ((opague_counter[0] == aop+extra-1)&&(temp[i][j] == 0)) {	//bei Gleichstand zweier Objekte bleibt temp[i][j] unbesetzt, da die aop+extra-1 von keinem erreicht wird
								if (a == aop+1) {
									temp[i][j] = 77;	//für aop=9 programmiert
								} else {
									temp[i][j] = a;
								}
							}
							
							opague_counter[0] = 0;
						}
					}
				}
				
				for (unsigned int p=0; p<=aop+extra; p+=1) {
					opague_counter[p] = 0;
				}
				
				
			} else if (opague >= 10) {		//4-Mode-Opague, Surrounding
			
				for (unsigned int h=i-1; h<=i+1; h+=1){
					for (unsigned int k=j-1; k<=j+1; k+=1){
						if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
							if (Sf[h][k] != 11) {
								
								if (Sf[i][j] == geben) {
									temp[h][k] = Sf[h][k];
								} else if ((Sf[h][k] != 0) && (Sf[h][k] != 77)) {
									opague_counter[Sf[h][k]] += 1;
								} else if ((Sf[h][k] != 0) && (Sf[h][k] == 77)) {
									opague_counter[aop+1] += 1;
								}
								
							}
						}
					}
				}
				
				if (opague % 10 == 1) {		//4-Mode-Opague, uneven
					for (unsigned int p=1; p<=aop+extra; p+=1) {
						if (opague_counter[p] % 2 == 0) {
							opague_counter[p] = 0;
						}
					}	//p=10: 77
				} else if (opague % 10 == 2) {		//4-Mode-Opague, even
					for (unsigned int p=1; p<=aop+extra; p+=1) {
						if (opague_counter[p] % 2 == 1) {
							opague_counter[p] = 0;
						}
					}	//p=10: 77
				}
				
				opague_counter[0] = 0;
				
				for (unsigned int a=1; a<=aop+extra; a+=1) {	//Übertragung auf temp
					if (a != geben) {
						if (opague_counter[a] != 0) {
							
							for (unsigned int b=1; b<=aop+extra; b+=1) {
								if (a != b) {
									if (opague_counter[a] > opague_counter[b]) {
										opague_counter[0] += 1;
									}
								}
							}
							
							if ((opague_counter[0] == aop+extra-1)&&(temp[i][j] == 0)) {
								if (a == aop+1) {
									temp[i][j] = 77;	//für aop=9 programmiert
								} else if (a == aop+2) {
									temp[i][j] = 77;	//für aop=9 programmiert go on
								} else {
									temp[i][j] = a;
								}
							}
							
							opague_counter[0] = 0;
						}
					}
				}
				
				for (unsigned int p=0; p<=aop+extra; p+=1) {
					opague_counter[p] = 0;
				}
			//aop und opague_counter ersetzen/anpassen... , done
			}
			
			if (Sf[i][j] == 11) {
				temp[i][j] = 11;
			}
		}
	}
	
	return temp;
}

int sgn (int a){	//sgn(0)=0;
	int sgna;
	sgna = 0;
	
	if (abs(a) != 0){
		sgna = a/abs(a);
	} else {
		sgna = 0;
	}
	
	return sgna;
}

void Reflection (int* dynamic_pointer, unsigned int a, int erd){
	
	dynamic_pointer[0+a] *= (-1);
	dynamic_pointer[2+a] *= (-1);
	
	if (sgn(dynamic_pointer[4+a])>0) {
		dynamic_pointer[4+a] -= 1;
	} else if (sgn(dynamic_pointer[4+a])<0) {
		dynamic_pointer[4+a] += 1;
	}
	
	for (int r=1; r<=2*abs(erd); r+=1) {
		if (sgn(dynamic_pointer[0+a]) > 0) {
			dynamic_pointer[0+a] -= 1;
			if (dynamic_pointer[0+a] == 0) {
				break;
			}
		} else if (sgn(dynamic_pointer[0+a]) < 0) {
			dynamic_pointer[0+a] += 1;
			if (dynamic_pointer[0+a] == 0) {
				break;
			}
		}
		
	}
	
}

void impact_y_semi_square (unsigned int m, unsigned int n, unsigned int* position, unsigned int d_wert, unsigned int range, int* dynamic_pointer, Spielfeld Sf){
	
	for (unsigned int i=0; i<m-1; i+=1) {	//Berechnung impact y
		for (unsigned int j=0; j<n-1; j+=1) {
			if ((Sf[i][j] != 0)&&(Sf[i][j] != 77)) {
				if ((abs(position[1]-i)+abs(position[0]-j))<=(abs(range)+1)) {	//Manhatten-Norm
					if ((position[1]-i) != 0) {
						dynamic_pointer[7] += (sgn(position[1]-i))*(d_wert*(range+1-abs(position[1]-i))*(range+1-abs(position[1]-i)) +1);
					}
					if ((position[0]-j) != 0) {
						dynamic_pointer[6] += (sgn(position[0]-j))*(d_wert*(range+1-abs(position[0]-j))*(range+1-abs(position[0]-j)) +1);
					}
				}
			}
		}
	}
	
}


//dynamic (gamemode)	, done		(just notes following)
//Geschwindigkeit (vertikal, horizontal)
//Beschleunigung (vertikal, horizontal)
//range (distance:0-5 in Manhatten-Norm)	--> distance+1 = difference, normal:2
//impact y=f(x), x distance, in beschleunigung(linear[f(x)=a*(range-x+1); a=1,2,3; x<=range], semi-square[f(x)=a*(range-x)^2 +1; a=1,2,3; x<=range], square[f(x)=a*(range-x+1)^2; a=1,2,3; x<=range])	normal:semi-square, a=1
//Erdanziehung g linear auf Beschleunigung (-g = 0-5)		normal:1
//crash mit Hindernis: Geschwindigkeit, Beschleunigung, Weg entgegengesetzt +1, mit der Bewegung Hindernis um 1 verschieben, Richtung des wegen zwischen vertikal-horizontal ändern
//crash mit solider Formation: (-1)* sofort auf 1.Beschleunigung(oder 2.Geschwindigkeit) statt Berechnung, -(restliche Wegstrecke+2) falls sgn ändert
//Übertragung Beschleunigung-Geschwindigkeit?
//Grundbetrag: vertikal: s=sgn(a)*a^2+v, v+=a, a+=g+y.		horizontal: s=sgn(a)*a^2+v, v+=a, a+=y.
//Feintuning: Betrag von s reduzieren über: 1 Schritt gehen und von |s| abziehen, wenn sgn(v)!=sgn(y-g)!=sgn(a), dann |v|-1 bzw. |a|-1 am Ende, und |y|>|a|: |s|-|y-a| , wenn |s| null erreicht immer aufhören
//Schrittweite = 1, s_ges = Abstand zur Grundlinie; Wenn a oder v =0 --> |a| = |v|, wenn beide null vorzeichenlos
//s=10: 10	10	9	4	6	9	10	10														s=10:	10	10	9	4	8	4	3	3	3	2	3	7	3		
//v= 0:	0	0	-1	-3	-6	-3	-1	0	<--leer	,freier Fall,	1 Hindernis auf Grund-->	v= 0:	0	0	-1	-3	-3	-4	-4	-3	-3	-2	-3	-4	-4		für 1.
//a= 0:	0	-1	-2	-3	3	2	1	0														a= 0:	0	-1	-2	-3	-1	-2	0	-1	0	-1	-3	0	-1
//Nimm 2.Geschwindigkeit
