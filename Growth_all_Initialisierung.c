
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#ifdef _WIN32
#include <windows.h>
#endif

// #define VERBOSE
// #define Contact_mistake_search
// #define Quidditch_mistake_search


#include "Growth_all_Def.h"
#include "Growth_all_set.h"
#include "Growth_all_show.h"
#include "Growth_all_Initialisierung.h"

void unsigned_int_array_null_initialisierung (unsigned int* array, unsigned int bueyuekluek) {
	for (unsigned int p=0; p<=bueyuekluek; p++) {
		array[p] = 0;
	}
}

void int_array_null_initialisierung (int* array, unsigned int bueyuekluek) {
	for (unsigned int p=0; p<=bueyuekluek; p++) {
		array[p] = 0;
	}
}

void Initialisierung (unsigned int gamemode_played, unsigned int* information_code) {
	if (gamemode_played == Survive) {

		for (unsigned int p=1; p<=3; p+=1) {
			information_code[p] = 1;
		}
	} else if (gamemode_played == Sand) {

		for (unsigned int p=1; p<=3; p+=1) {
			information_code[p] = 1 + p/3;
		}
	}

}

unsigned int Initialisierung_limits_yeni (unsigned int gamemode_played) {	//checklist
	unsigned int Ausgabe;
	Ausgabe = 0;

	if ((gamemode_played == Classic)||(gamemode_played == Collect)||(gamemode_played == Dynamic)||(gamemode_played == Sand)) {
		Ausgabe = 10;
	} else if (gamemode_played == Contact) {
		Ausgabe = 15;
	} else if ((gamemode_played == Fall)||(gamemode_played == Race)||(gamemode_played == Rain)) {
		Ausgabe = 7;
	} else if ((gamemode_played == Fight)||(gamemode_played == Duell)) {
		Ausgabe = 5;
	} else if (gamemode_played == Hunt) {
		Ausgabe = 6;
	} else if (gamemode_played == Arena) {
		Ausgabe = 8;
	} else if (gamemode_played == Quidditch) {
		Ausgabe = 45;
	} else {
		Ausgabe = 0;
	}

	return Ausgabe;
}

unsigned int Initialisierung_limits_at_all (unsigned int gamemode_played) {	//checklist
	unsigned int Ausgabe;
	Ausgabe = 0;

	if ((gamemode_played == Classic)||(gamemode_played == Collect)||(gamemode_played == Dynamic)||(gamemode_played == Sand)) {
		Ausgabe = 20;
	} else if ((gamemode_played == Fall)||(gamemode_played == Race)||(gamemode_played == Rain)) {
		Ausgabe = 14;
	} else if ((gamemode_played == Fight)||(gamemode_played == Duell)) {
		Ausgabe = 10;
	} else if (gamemode_played == Hunt) {
		Ausgabe = 12;
	} else if (gamemode_played == Arena) {
		Ausgabe = 16;
	} else if (gamemode_played == Quidditch) {
		Ausgabe = 90;
	} else {
		Ausgabe = 0;
	}

	return Ausgabe;
}

unsigned int Initialisierung_n (unsigned int gamemode_played) {	//real+2
	unsigned int Ausgabe;	//checklist
	Ausgabe = 0;

	if ((gamemode_played == Classic)||(gamemode_played == Fight)||(gamemode_played == Ulcer)||(gamemode_played == Duell)) {
		Ausgabe = 8;
	} else if ((gamemode_played == Collect)||(gamemode_played == Fall)||(gamemode_played == Dynamic)||(gamemode_played == Survive)) {
		Ausgabe = 13;
	} else if (gamemode_played == Contact) {
		Ausgabe = 18;
	} else if (gamemode_played == Hunt) {
		Ausgabe = 11;
	} else if (gamemode_played == Race) {
		Ausgabe = 21;
	} else if (gamemode_played == Rain) {
		Ausgabe = 15;
	} else if ((gamemode_played == Arena)||(gamemode_played == Sand)) {
		Ausgabe = 9;
	} else if (gamemode_played == Quidditch) {
		Ausgabe = 21;
	} else {
		Ausgabe = 0;
	}

	return Ausgabe;
}

unsigned int Initialisierung_m (unsigned int gamemode_played) {	//real+2
	unsigned int Ausgabe;	//checklist

	Ausgabe = 0;

	if ((gamemode_played == Classic)||(gamemode_played == Contact)) {
		Ausgabe = 12;
	} else if (gamemode_played == Collect) {
		Ausgabe = 11;
	} else if ((gamemode_played == Fall)||(gamemode_played == Fight)||(gamemode_played == Rain)||(gamemode_played == Ulcer)||(gamemode_played == Duell)) {
		Ausgabe = 8;
	} else if ((gamemode_played == Hunt)||(gamemode_played == Race)||(gamemode_played == Arena)||(gamemode_played == Dynamic)||(gamemode_played == Sand)) {
		Ausgabe = 9;
	} else if (gamemode_played == Survive) {
		Ausgabe = 13;
	} else if (gamemode_played == Quidditch) {
		Ausgabe = 20;
	} else {
		Ausgabe = 0;
	}

	return Ausgabe;
}

void Initialisierung_Arrays_1 (unsigned int AOP, unsigned int* ability, unsigned int* ulcer_lifes, unsigned int* number_){

	unsigned_int_array_null_initialisierung (ability, AOP);	//0 - AOP
	unsigned_int_array_null_initialisierung (ulcer_lifes, AOP);
	unsigned_int_array_null_initialisierung (number_, AOP);

	for (unsigned int p=1; p<=AOP; p+=1) {
		ulcer_lifes[p] = p-1;
	}
}

void Initialisierung_Arrays_2 (unsigned int AOP, unsigned int* pere, unsigned int* ges, unsigned int* var_, unsigned int* ulcer_start, unsigned int* win_condition, unsigned int* out_counter, unsigned int* number_, unsigned int* cons){

	unsigned_int_array_null_initialisierung (pere, AOP);	//0 - AOP
	unsigned_int_array_null_initialisierung (ges, AOP);
	unsigned_int_array_null_initialisierung (var_, AOP);
	unsigned_int_array_null_initialisierung (ulcer_start, AOP);
	unsigned_int_array_null_initialisierung (win_condition, AOP);
	unsigned_int_array_null_initialisierung (out_counter, AOP);
	unsigned_int_array_null_initialisierung (number_, AOP);
	unsigned_int_array_null_initialisierung (cons, AOP);

	for (unsigned int p=0; p<=AOP; p+=1) {
		ulcer_start[p] = missing;
		// printf("ulcer_start[%u] = %u \n", p, ulcer_start[p]);	//test
	}
	ulcer_start[1] = existing;
	// printf("ulcer_start[1] = %u \n", ulcer_start[1]);	//test
}

void start_normal (Spielfeld Field, unsigned int m, unsigned int n, unsigned int gamemode_played, unsigned int number_of_players, unsigned int geben, Spielfeld Opague_o_field, Special_Fields_Collector* sfc, unsigned int single_option_representives_inverted){	//checklist

	if (gamemode_played == Tutorial){
		Field[0][4][1] = 2;		//Spieler 2
		Field[0][5][1] = 2;
		Field[0][4][2] = 2;
		Field[0][5][2] = 2;

		Field[0][4][6] = 1;		//Spieler 1
		Field[0][5][4] = 1;
		Field[0][5][5] = 1;
		Field[0][6][5] = 1;
		Field[0][6][6] = 1;
	} else if (gamemode_played == Classic){
		if (number_of_players == 2) {

				set_gleiter_links_unten (single_option_representives_inverted, Field, 1, 2, 4);		//Spieler 1

				set_gleiter_rechts_oben (single_option_representives_inverted, Field, 2, m-3, 3);		//Spieler 2

		} else {
			for (unsigned int p=1; p<=number_of_players; p++) {
				if (p%2 == 1) {
					set_gleiter_links_unten (single_option_representives_inverted, Field, p, 2, (((n-2)/((number_of_players+1)/2))/2)+((p-1)/2)*((n-2)/((number_of_players+1)/2)));		//Spieler p
				} else if (p%2 == 0) {
					set_gleiter_rechts_oben (single_option_representives_inverted, Field, p, m-3, (((n-2)/(number_of_players/2))/2)+((p-2)/2)*((n-2)/(number_of_players/2)));		//Spieler p
				}
			}	//n-2 >= 3*((number_of_players+1)/2)
		}

	} else if (gamemode_played == Collect){
		for (unsigned int p=1; p<=number_of_players; p++) {
			if (p%2 == 1) {
				set_gleiter_links_unten (single_option_representives_inverted, Field, p, 2, ((p+1)/2)+p*((n-2-((number_of_players+1)/2))/(2*((number_of_players+1)/2))));		//Spieler p
			} else if (p%2 == 0) {
				set_gleiter_rechts_oben (single_option_representives_inverted, Field, p, m-3, (p/2)+(p-1)*((n-2-(number_of_players/2))/(2*(number_of_players/2))));		//Spieler p
			}
		}	//n-2 >= 3*((number_of_players+1)/2)		n-2 >= 3*(number_of_players+1)

		//Field[0][9][1] = 1;	Field[0][8][5] = 1;	//Test
		//Field[0][8][5] = 1;	Field[0][8][6] = 1;
		//Field[0][2][1] = 2;	Field[0][5][2] = 1;
		//Field[0][5][5] = 1;	Field[0][5][6] = 1;
		for (unsigned int q=1; q<=number_of_players-1; q++) {
			Field[0][(m-1)/2][2+q+q*(n-2-4-(number_of_players-1))/number_of_players] = To_collect;	//uniform setting between the following two To_collect-squares
		}
		Field[0][(m-1)/2][2] = To_collect;
		Field[0][(m-1)/2][n-3] = To_collect;

	} else if (gamemode_played == Contact){
		if (number_of_players == 2) {
			set_gleiter_links_unten (single_option_representives_inverted, Field, 1, 2, n/2);		//Spieler 1
			set_triangle_oben_links (single_option_representives_inverted, Field, 1, 1, 1);
			set_triangle_oben_rechts (single_option_representives_inverted, Field, 1, 1, n-2);

			//Field[0][9][1] = 1;	Field[0][8][5] = 1;	//Test
			//Field[0][8][5] = 1;	Field[0][8][6] = 1;
			//Field[0][2][1] = 2;	Field[0][5][2] = 1;
			//Field[0][5][5] = 1;	Field[0][5][6] = 1;

			set_gleiter_rechts_oben (single_option_representives_inverted, Field, 2, m-3, (n/2)-1);		//Spieler 2
			set_triangle_unten_links (single_option_representives_inverted, Field, 2, m-2, 1);
			set_triangle_unten_rechts (single_option_representives_inverted, Field, 2, m-2, n-2);
		} else {
			for (unsigned int p=1; p<=number_of_players; p++) {
				if (p%2 == 1) {
					set_gleiter_links_unten (single_option_representives_inverted, Field, p, 2, 1+2+((p-1)/2)*((n-2)/((number_of_players+1)/2)));		//Spieler p
					set_triangle_oben_rechts (single_option_representives_inverted, Field, p, 1, 1+7+((p-1)/2)*((n-2)/((number_of_players+1)/2)));
				} else if (p%2 == 0) {
					set_gleiter_rechts_oben (single_option_representives_inverted, Field, p, m-3, n-2-2-((p-1)/2)*((n-2)/(number_of_players/2)));		//Spieler p
					set_triangle_unten_links (single_option_representives_inverted, Field, p, m-2, n-2-7-((p-1)/2)*((n-2)/(number_of_players/2)));
				}
			}
		}

	} else if (gamemode_played == Fall){
		for (unsigned int p=1; p<=number_of_players; p++) {
			if (p%2 == 1) {	//links
				set_gleiter_rechts_oben (single_option_representives_inverted, Field, p, m-3, 1+1+((p-1)/2)*((n-2-1)/number_of_players));		//Spieler p
			} else if (p%2 == 0) {	//rechts
				set_gleiter_links_oben (single_option_representives_inverted, Field, p, m-3, n-2-1-((p-1)/2)*((n-2-1)/number_of_players));		//Spieler p
			}
		}

		Field[0][1][(n-1)/2] = Fall_ball;

	} else if ((gamemode_played == Fight)||(gamemode_played == Duell)){
		for (unsigned int p=1; p<=number_of_players; p++) {
			if (p%2 == 1) {
				set_gleiter_links_unten (single_option_representives_inverted, Field, p, 2, 1+((p+1)/2)*((n-2)/(((number_of_players+1)/2)+1)));		//Spieler p
			} else if (p%2 == 0) {
				set_gleiter_rechts_oben (single_option_representives_inverted, Field, p, m-3, 1+((p+1)/2)*((n-2)/((number_of_players/2)+1)));		//Spieler p
			}
		}

	} else if (gamemode_played == Hunt){
		if (number_of_players == 2) {
			unsigned int m_2;
			m_2 = (m-1)/2;

			if (single_option_representives_inverted == 0) {
				Field[0][m_2-1][3]	= 1;		//Spieler 1
				Field[0][m_2][2]	= 1;
				Field[0][m_2][3]	= 11;
				Field[0][m_2][4]	= 1;
				Field[0][m_2+1][3]	= 1;
			} else if (single_option_representives_inverted == 1) {
				Field[0][m_2-1][2]	= 1;		//Spieler 1
				Field[0][m_2+1][2]	= 1;
				Field[0][m_2][3]	= 11;
				Field[0][m_2-1][4]	= 1;
				Field[0][m_2+1][4]	= 1;
			}

			set_gleiter_unten_links (single_option_representives_inverted, Field, 2, m_2, n-3);		//Spieler 2

		} else if (number_of_players == 3) {
			unsigned int m_2, n_2;
			m_2 = (m-1)/2;
			n_2 = (n-1)/2;

			if (single_option_representives_inverted == 0) {
				Field[0][m_2-1][n_2] = 1;		//Spieler 1
				Field[0][m_2][n_2-1] = 1;
				Field[0][m_2][n_2]   = 11;
				Field[0][m_2][n_2+1] = 1;
				Field[0][m_2+1][n_2] = 1;
			} else if (single_option_representives_inverted == 1) {
				Field[0][m_2-1][n_2-1] = 1;		//Spieler 1
				Field[0][m_2+1][n_2-1] = 1;
				Field[0][m_2][n_2]   = 11;
				Field[0][m_2-1][n_2+1] = 1;
				Field[0][m_2+1][n_2+1] = 1;
			}

			set_gleiter_unten_links (single_option_representives_inverted, Field, 2, m_2, n-3);		//Spieler 2
			set_gleiter_oben_rechts (single_option_representives_inverted, Field, 3, m_2, 2);		//Spieler 3

		} else if (number_of_players == 4) {
			unsigned int m_2, n_2;
			m_2 = (m-1)/2;
			n_2 = (n-1)/2;

			if (single_option_representives_inverted == 0) {
				Field[0][m_2-1][n_2] = 1;		//Spieler 1
				Field[0][m_2][n_2-1] = 1;
				Field[0][m_2][n_2]   = 11;
				Field[0][m_2][n_2+1] = 1;
				Field[0][m_2+1][n_2] = 1;
			} else if (single_option_representives_inverted == 1) {
				Field[0][m_2-1][n_2-1] = 1;		//Spieler 1
				Field[0][m_2+1][n_2-1] = 1;
				Field[0][m_2][n_2]   = 11;
				Field[0][m_2-1][n_2+1] = 1;
				Field[0][m_2+1][n_2+1] = 1;
			}

			set_gleiter_rechts_oben (single_option_representives_inverted, Field, 2, m-3, n_2);		//Spieler 2
			set_gleiter_unten_links (single_option_representives_inverted, Field, 3, 2, n-3);		//Spieler 3
			set_gleiter_unten_rechts (single_option_representives_inverted, Field, 4, 2, 2);		//Spieler 4

		} else if (number_of_players == 5) {
			unsigned int m_2, n_2;
			m_2 = (m-1)/2;
			n_2 = (n-1)/2;

			if (single_option_representives_inverted == 0) {
				Field[0][m_2-1][n_2] = 1;		//Spieler 1
				Field[0][m_2][n_2-1] = 1;
				Field[0][m_2][n_2]   = 11;
				Field[0][m_2][n_2+1] = 1;
				Field[0][m_2+1][n_2] = 1;
			} else if (single_option_representives_inverted == 1) {
				Field[0][m_2-1][n_2-1] = 1;		//Spieler 1
				Field[0][m_2+1][n_2-1] = 1;
				Field[0][m_2][n_2]   = 11;
				Field[0][m_2-1][n_2+1] = 1;
				Field[0][m_2+1][n_2+1] = 1;
			}

			set_gleiter_oben_links (single_option_representives_inverted, Field, 2, m-3, n-3);		//Spieler 2
			set_gleiter_links_unten (single_option_representives_inverted, Field, 3, 2, n-3);		//Spieler 3
			set_gleiter_unten_rechts (single_option_representives_inverted, Field, 4, 2, 2);		//Spieler 4
			set_gleiter_rechts_oben (single_option_representives_inverted, Field, 5, m-3, 2);		//Spieler 5

		} else if (number_of_players == 6) {
			unsigned int m_2, nn;
			m_2 = (m-1)/2;
			nn = (n-4)/2;

			if (single_option_representives_inverted == 0) {
				Field[0][m_2-1][nn]	= 1;		//Spieler 1
				Field[0][m_2][nn-1]	= 1;
				Field[0][m_2][nn]	= 11;
				Field[0][m_2][nn+1]	= 1;
				Field[0][m_2+1][nn]	= 1;
			} else if (single_option_representives_inverted == 1) {
				Field[0][m_2-1][nn-1]	= 1;		//Spieler 1
				Field[0][m_2+1][nn-1]	= 1;
				Field[0][m_2][nn]	= 11;
				Field[0][m_2-1][nn+1]	= 1;
				Field[0][m_2+1][nn+1]	= 1;
			}

			set_gleiter_oben_links (single_option_representives_inverted, Field, 2, m_2, n-3);		//Spieler 2
			set_gleiter_links_unten (single_option_representives_inverted, Field, 3, 2, n-7);		//Spieler 3
			set_gleiter_rechts_unten (single_option_representives_inverted, Field, 4, 2, 2);		//Spieler 4
			set_gleiter_rechts_oben (single_option_representives_inverted, Field, 5, m-3, 2);		//Spieler 5
			set_gleiter_links_oben (single_option_representives_inverted, Field, 6, m-3, n-7);		//Spieler 6

		} else if (number_of_players == 7) {
			unsigned int m_2, n_2;
			m_2 = (m-1)/2;
			n_2 = (n-1)/2;

			if (single_option_representives_inverted == 0) {
				Field[0][m_2-1][n_2] = 1;		//Spieler 1
				Field[0][m_2][n_2-1] = 1;
				Field[0][m_2][n_2]   = 11;
				Field[0][m_2][n_2+1] = 1;
				Field[0][m_2+1][n_2] = 1;
			} else if (single_option_representives_inverted == 1) {
				Field[0][m_2-1][n_2-1] = 1;		//Spieler 1
				Field[0][m_2+1][n_2-1] = 1;
				Field[0][m_2][n_2]   = 11;
				Field[0][m_2-1][n_2+1] = 1;
				Field[0][m_2+1][n_2+1] = 1;
			}

			set_gleiter_oben_links (single_option_representives_inverted, Field, 2, m_2, n-3);		//Spieler 2
			set_gleiter_links_unten (single_option_representives_inverted, Field, 3, 2, n-6);		//Spieler 3
			set_gleiter_rechts_unten (single_option_representives_inverted, Field, 4, 2, 5);		//Spieler 4
			set_gleiter_unten_rechts (single_option_representives_inverted, Field, 5, m_2, 2);		//Spieler 5
			set_gleiter_rechts_oben (single_option_representives_inverted, Field, 6, m-3, 5);		//Spieler 6
			set_gleiter_links_oben (single_option_representives_inverted, Field, 7, m-3, n-6);		//Spieler 7

		} else if (number_of_players == 8) {
			unsigned int m_2, n_2;
			m_2 = (m-2)/2;
			n_2 = (n-1)/2;

			if (single_option_representives_inverted == 0) {
				Field[0][m_2-1][n_2] = 1;		//Spieler 1
				Field[0][m_2][n_2-1] = 1;
				Field[0][m_2][n_2]   = 11;
				Field[0][m_2][n_2+1] = 1;
				Field[0][m_2+1][n_2] = 1;
			} else if (single_option_representives_inverted == 1) {
				Field[0][m_2-1][n_2-1] = 1;		//Spieler 1
				Field[0][m_2+1][n_2-1] = 1;
				Field[0][m_2][n_2]   = 11;
				Field[0][m_2-1][n_2+1] = 1;
				Field[0][m_2+1][n_2+1] = 1;
			}

			set_gleiter_oben_links (single_option_representives_inverted, Field, 2, m_2, n-3);		//Spieler 2
			set_gleiter_links_unten (single_option_representives_inverted, Field, 3, 2, n-7);		//Spieler 3
			set_gleiter_rechts_unten (single_option_representives_inverted, Field, 4, 2, 6);		//Spieler 4
			set_gleiter_oben_rechts (single_option_representives_inverted, Field, 5, m_2, 2);		//Spieler 5
			set_gleiter_rechts_oben (single_option_representives_inverted, Field, 6, m-5, 4);		//Spieler 6
			set_mountain_unten (single_option_representives_inverted, Field, 7, m-3, n_2);		//Spieler 7
			set_gleiter_rechts_oben (single_option_representives_inverted, Field, 8, m-5, n-5);		//Spieler 8

		} else if (number_of_players == 9) {
			unsigned int m_2, n_2;
			m_2 = (m-1)/2;
			n_2 = (n-1)/2;

			if (single_option_representives_inverted == 0) {
				Field[0][m_2-1][n_2] = 1;		//Spieler 1
				Field[0][m_2][n_2-1] = 1;
				Field[0][m_2][n_2]   = 11;
				Field[0][m_2][n_2+1] = 1;
				Field[0][m_2+1][n_2] = 1;
			} else if (single_option_representives_inverted == 1) {
				Field[0][m_2-1][n_2-1] = 1;		//Spieler 1
				Field[0][m_2+1][n_2-1] = 1;
				Field[0][m_2][n_2]   = 11;
				Field[0][m_2-1][n_2+1] = 1;
				Field[0][m_2+1][n_2+1] = 1;
			}

			set_mountain_rechts (single_option_representives_inverted, Field, 2, m_2, n-3);		//Spieler 2
			set_edge_oben_rechts (single_option_representives_inverted, Field, 3, 3, n-4);		//Spieler 3
			set_mountain_oben (single_option_representives_inverted, Field, 4, 2, n_2);		//Spieler 4
			set_edge_oben_links (single_option_representives_inverted, Field, 5, 3, 3);		//Spieler 5
			set_mountain_links (single_option_representives_inverted, Field, 6, m_2, 2);		//Spieler 6
			set_edge_unten_links (single_option_representives_inverted, Field, 7, m-4, 3);		//Spieler 7
			set_mountain_unten (single_option_representives_inverted, Field, 8, m-3, n_2);		//Spieler 8
			set_edge_unten_rechts (single_option_representives_inverted, Field, 9, m-4, n-4);		//Spieler 9
		}

	} else if (gamemode_played == Race){
		for (unsigned int p=1; p<=number_of_players; p++) {
			if (p <= number_of_players/2) {
				set_gleiter_unten_rechts (single_option_representives_inverted, Field, p, (((m-2+1)/number_of_players)+1)/2 +(p-1)*((m-2+1)/number_of_players), 3);		//Spieler p
			} else {
				set_gleiter_oben_rechts (single_option_representives_inverted, Field, p, (((m-2+1)/number_of_players)+1)/2 +(p-1)*((m-2+1)/number_of_players), 3);		//Spieler p
			}
			if (p!=number_of_players) {
				Field[0][p*((m-2+1)/number_of_players)][n-2] = Wall_at_the_end;
			}

		}

		for (unsigned int i=1; i<m-1; i+=1){
			Field[0][i][1] = Wall;
		}

	} else if (gamemode_played == Rain){
		for (unsigned int p=1; p<=number_of_players; p++) {
			if (p == 1) {
				set_gleiter_rechts_oben (single_option_representives_inverted, Field, p, m-3, 2);		//Spieler 1
			} else if (p == number_of_players) {
				set_gleiter_links_oben (single_option_representives_inverted, Field, p, m-3, n-3);	//Spieler number_of_players
			} else {
				set_star (single_option_representives_inverted, Field, p, m-3, 3+(p-1)*7);		//Spieler p
			}
		}
	} else if (gamemode_played == Arena){
		if (number_of_players == 2) {
			unsigned int m_2;
			m_2 = (m-1)/2;

			set_gleiter_unten_rechts (single_option_representives_inverted, Field, 1, m_2, 2);		//Spieler 1
			set_gleiter_oben_links (single_option_representives_inverted, Field, 2, m_2, n-3);		//Spieler 2

		} else if (number_of_players == 3) {

			set_star (single_option_representives_inverted, Field, 1, 3, 3);		//Spieler 1
			set_gleiter_unten_links (single_option_representives_inverted, Field, 2, 4, n-3);		//Spieler 2
			set_gleiter_rechts_oben (single_option_representives_inverted, Field, 3, m-3, 4);		//Spieler 3

		} else if (number_of_players == 4) {
			unsigned int m_2, n_2;
			m_2 = (m-1)/2;
			n_2 = (n-1)/2;

			set_gleiter_rechts_oben (single_option_representives_inverted, Field, 1, m-3, n_2);		//Spieler 1
			set_gleiter_links_unten (single_option_representives_inverted, Field, 2, 2, n_2);		//Spieler 2
			set_gleiter_unten_rechts (single_option_representives_inverted, Field, 3, m_2, 2);		//Spieler 3
			set_gleiter_oben_links (single_option_representives_inverted, Field, 4, m_2, n-3);		//Spieler 4

		} else if (number_of_players == 5) {
			unsigned int mm, nn;
			mm = m/2;
			nn = n/2;

			set_gleiter_rechts_oben (single_option_representives_inverted, Field, 1, m-3, nn);		//Spieler 1
			set_gleiter_links_unten (single_option_representives_inverted, Field, 2, 2, nn-1);		//Spieler 2
			set_gleiter_unten_rechts (single_option_representives_inverted, Field, 3, mm, 2);		//Spieler 3
			set_gleiter_oben_links (single_option_representives_inverted, Field, 4, mm-1, n-3);		//Spieler 4
			set_net_basic_two_four (single_option_representives_inverted, Field, 5, mm-1, nn-1);	//Spieler 5

		} else if (number_of_players == 6) {
			unsigned int m_2;
			m_2 = (m-1)/2;

			set_gleiter_oben_rechts (single_option_representives_inverted, Field, 1, m_2, 2);		//Spieler 1
			set_gleiter_unten_links (single_option_representives_inverted, Field, 2, m_2, n-3);		//Spieler 2
			set_gleiter_rechts_unten (single_option_representives_inverted, Field, 3, 2, n-6);		//Spieler 3
			set_gleiter_rechts_unten (single_option_representives_inverted, Field, 4, 2, 5);		//Spieler 4
			set_gleiter_links_oben (single_option_representives_inverted, Field, 5, m-3, 5);		//Spieler 5
			set_gleiter_links_oben (single_option_representives_inverted, Field, 6, m-3, n-6);		//Spieler 6

		} else if (number_of_players == 7) {
			unsigned int mm, nn;
			mm = m/2;
			nn = n/2;

			set_gleiter_oben_rechts (single_option_representives_inverted, Field, 1, mm, 2);		//Spieler 1
			set_gleiter_unten_links (single_option_representives_inverted, Field, 2, mm-1, n-3);		//Spieler 2
			set_gleiter_rechts_unten (single_option_representives_inverted, Field, 3, 2, n-6);		//Spieler 3
			set_gleiter_rechts_unten (single_option_representives_inverted, Field, 4, 2, 5);		//Spieler 4
			set_gleiter_links_oben (single_option_representives_inverted, Field, 5, m-3, 5);		//Spieler 5
			set_gleiter_links_oben (single_option_representives_inverted, Field, 6, m-3, n-6);		//Spieler 6
			set_net_basic_two_four (single_option_representives_inverted, Field, 7, mm-1, nn-1);	//Spieler 7

		} else if (number_of_players == 8) {

			set_gleiter_unten_rechts (single_option_representives_inverted, Field, 1, 5, 2);		//Spieler 1
			set_gleiter_oben_links (single_option_representives_inverted, Field, 2, 5, n-3);		//Spieler 2
			set_gleiter_links_unten (single_option_representives_inverted, Field, 3, 2, n-6);		//Spieler 3
			set_gleiter_links_unten (single_option_representives_inverted, Field, 4, 2, 5);		//Spieler 4
			set_gleiter_rechts_oben (single_option_representives_inverted, Field, 5, m-3, 5);		//Spieler 5
			set_gleiter_rechts_oben (single_option_representives_inverted, Field, 6, m-3, n-6);		//Spieler 6
			set_gleiter_unten_rechts (single_option_representives_inverted, Field, 7, m-6, 2);		//Spieler 7
			set_gleiter_oben_links (single_option_representives_inverted, Field, 8, m-6, n-3);		//Spieler 8

		} else if (number_of_players == 9) {
			unsigned int mm, nn;
			mm = m/2;
			nn = n/2;

			set_gleiter_unten_rechts (single_option_representives_inverted, Field, 1, 5, 2);		//Spieler 1
			set_gleiter_oben_links (single_option_representives_inverted, Field, 2, 5, n-3);		//Spieler 2
			set_gleiter_links_unten (single_option_representives_inverted, Field, 3, 2, n-6);		//Spieler 3
			set_gleiter_links_unten (single_option_representives_inverted, Field, 4, 2, 5);		//Spieler 4
			set_gleiter_rechts_oben (single_option_representives_inverted, Field, 5, m-3, 5);		//Spieler 5
			set_gleiter_rechts_oben (single_option_representives_inverted, Field, 6, m-3, n-6);		//Spieler 6
			set_gleiter_unten_rechts (single_option_representives_inverted, Field, 7, m-6, 2);		//Spieler 7
			set_gleiter_oben_links (single_option_representives_inverted, Field, 8, m-6, n-3);		//Spieler 8
			set_net_basic_two_four (single_option_representives_inverted, Field, 9, mm-1, nn-1);	//Spieler 9
		}

	} else if (gamemode_played == Ulcer) {
		for (unsigned int i=1; i<=(m-2); i+=1) {
			if (i%3 != 0) {
				set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, i, 3, 1);
			}
		}
		for (unsigned int j=1; j<=(n-2); j+=1) {
			if (j%3 != 0) {
				set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, 3, j, 1);
			}
		}
		set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, 5, 5, 1);

	} else if (gamemode_played == Dynamic) {
		unsigned int m_2, n_2;
		m_2 = (m-1)/2;
		n_2 = (n-1)/2;

		if (number_of_players == 2) {

			set_gleiter_unten_rechts (single_option_representives_inverted, Field, 1, m_2, 2);		//Spieler 1
			set_gleiter_unten_links (single_option_representives_inverted, Field, 2, m_2, n-3);		//Spieler 2

		} else if (number_of_players == 3) {

			set_gleiter_unten_rechts (single_option_representives_inverted, Field, 1, m_2, 2);		//Spieler 1
			set_mountain_oben (single_option_representives_inverted, Field, 2, 2, n_2);		//Spieler 2
			set_gleiter_unten_links (single_option_representives_inverted, Field, 3, m_2, n-3);		//Spieler 3

		} else if (number_of_players == 4) {

			set_gleiter_unten_rechts (single_option_representives_inverted, Field, 1, m_2, 2);		//Spieler 1
			set_mountain_oben (single_option_representives_inverted, Field, 2, 2, n_2);		//Spieler 2
			set_gleiter_unten_links (single_option_representives_inverted, Field, 3, m_2, n-3);		//Spieler 3
			set_mountain_unten (single_option_representives_inverted, Field, 4, m-3, n_2);		//Spieler 4

		} else if (number_of_players == 5) {

			set_gleiter_unten_rechts (single_option_representives_inverted, Field, 1, m_2, 2);		//Spieler 1
			set_mountain_oben (single_option_representives_inverted, Field, 2, 2, n_2);		//Spieler 2
			set_gleiter_unten_links (single_option_representives_inverted, Field, 3, m_2, n-3);		//Spieler 3
			set_gleiter_rechts_oben (single_option_representives_inverted, Field, 4, m-3, n_2+1);		//Spieler 4
			set_f_links_oben (single_option_representives_inverted, Field, 5, m-3, n_2-1);		//Spieler 5

		} else if (number_of_players == 6) {

			set_gleiter_unten_rechts (single_option_representives_inverted, Field, 1, m_2+1, 2);		//Spieler 1
			set_gleiter_links_unten (single_option_representives_inverted, Field, 2, 2, n_2-1);		//Spieler 2
			set_gleiter_unten_links (single_option_representives_inverted, Field, 3, m_2+1, n-3);		//Spieler 3
			set_f_oben_rechts (single_option_representives_inverted, Field, 4, m_2-1, 2);		//Spieler 4
			set_f_rechts_unten (single_option_representives_inverted, Field, 5, 2, n_2+1);		//Spieler 5
			set_f_oben_links (single_option_representives_inverted, Field, 6, m_2-1, n-3);		//Spieler 6

		} else if (number_of_players == 7) {

			set_gleiter_unten_rechts (single_option_representives_inverted, Field, 1, m_2+1, 2);		//Spieler 1
			set_mountain_oben (single_option_representives_inverted, Field, 2, 2, n_2);		//Spieler 2
			set_gleiter_unten_links (single_option_representives_inverted, Field, 3, m_2+1, n-3);		//Spieler 3
			set_gleiter_rechts_oben (single_option_representives_inverted, Field, 4, m-3, n_2+1);		//Spieler 4
			set_f_oben_rechts (single_option_representives_inverted, Field, 5, m_2-1, 2);		//Spieler 5
			set_f_oben_links (single_option_representives_inverted, Field, 6, m_2-1, n-3);		//Spieler 6
			set_f_links_oben (single_option_representives_inverted, Field, 7, m-3, n_2-1);		//Spieler 7

		} else if (number_of_players == 8) {

			set_gleiter_unten_rechts (single_option_representives_inverted, Field, 1, m_2+1, 2);		//Spieler 1
			set_gleiter_links_unten (single_option_representives_inverted, Field, 2, 2, n_2-1);		//Spieler 2
			set_gleiter_unten_links (single_option_representives_inverted, Field, 3, m_2+1, n-3);		//Spieler 3
			set_gleiter_rechts_oben (single_option_representives_inverted, Field, 4, m-3, n_2+1);		//Spieler 4
			set_f_oben_rechts (single_option_representives_inverted, Field, 5, m_2-1, 2);		//Spieler 5
			set_f_rechts_unten (single_option_representives_inverted, Field, 6, 2, n_2+1);		//Spieler 6
			set_f_oben_links (single_option_representives_inverted, Field, 7, m_2-1, n-3);		//Spieler 7
			set_f_links_oben (single_option_representives_inverted, Field, 8, m-3, n_2-1);		//Spieler 8

		} else if (number_of_players == 9) {

			set_gleiter_unten_rechts (single_option_representives_inverted, Field, 1, m_2+2, 2);		//Spieler 1
			set_gleiter_links_unten (single_option_representives_inverted, Field, 2, 2, n_2-2);		//Spieler 2
			set_gleiter_unten_links (single_option_representives_inverted, Field, 3, m_2+2, n-3);		//Spieler 3
			set_gleiter_oben_rechts (single_option_representives_inverted, Field, 4, m_2-2, 2);		//Spieler 4
			set_gleiter_rechts_unten (single_option_representives_inverted, Field, 5, 2, n_2+2);		//Spieler 5
			set_gleiter_oben_links (single_option_representives_inverted, Field, 6, m_2-2, n-3);		//Spieler 6
			set_mountain_links (single_option_representives_inverted, Field, 7, m_2, 2);		//Spieler 7
			set_mountain_oben (single_option_representives_inverted, Field, 8, 2, n_2);		//Spieler 8
			set_mountain_rechts (single_option_representives_inverted, Field, 7, m_2, n-3);		//Spieler 9

		}

		Field[0][m_2][n_2] = Dynamic_ball;

	} else if (gamemode_played == Survive) {
		if (number_of_players >= 1) {
			set_gleiter_unten_rechts (single_option_representives_inverted, Field, 1, 2, 2);		//Spieler 1
		}
		if (number_of_players >= 2) {
			set_gleiter_links_unten (single_option_representives_inverted, Field, 2, 2, n-3);		//Spieler 2
		}
		if (number_of_players >= 3) {
			set_gleiter_oben_links (single_option_representives_inverted, Field, 3, m-3, n-3);		//Spieler 3
		}
		if (number_of_players >= 4) {
			set_gleiter_rechts_oben (single_option_representives_inverted, Field, 4, m-3, 2);		//Spieler 4
		}
		if (number_of_players == 5) {
			unsigned int n_2;
			unsigned int m_2;
			n_2 = (n-1)/2;
			m_2 = (m-1)/2;

			set_star (single_option_representives_inverted, Field, 5, m_2, n_2);		//Spieler 5

		} else if (number_of_players > 5) {
			unsigned int m_2;
			m_2 = (m-1)/2;

			set_mountain_rechts (single_option_representives_inverted, Field, 5, m_2, n-3);		//Spieler 5

		}
		if (number_of_players >= 6) {
			unsigned int m_2;
			m_2 = (m-1)/2;

			set_mountain_links (single_option_representives_inverted, Field, 6, m_2, 2);		//Spieler 6

		}
		if (number_of_players == 7) {
			unsigned int n_2;
			unsigned int m_2;
			n_2 = (n-1)/2;
			m_2 = (m-1)/2;

			set_star (single_option_representives_inverted, Field, 7, m_2, n_2);		//Spieler 7

		} else if (number_of_players > 7) {
			unsigned int n_2;
			n_2 = (n-1)/2;

			set_mountain_oben (single_option_representives_inverted, Field, 7, 2, n_2);		//Spieler 7

		}
		if (number_of_players >= 8) {
			unsigned int n_2;
			n_2 = (n-1)/2;

			set_mountain_unten (single_option_representives_inverted, Field, 8, m-3, n_2);		//Spieler 8

		}
		if (number_of_players >= 9) {
			unsigned int n_2;
			unsigned int m_2;
			n_2 = (n-1)/2;
			m_2 = (m-1)/2;

			set_star (single_option_representives_inverted, Field, 9, m_2, n_2);		//Spieler 9

		}
	} else if (gamemode_played == Sand) {
		for (unsigned int p=1; p<=number_of_players; p++) {
			if (p%2 == 1) {
				set_gleiter_rechts_oben (single_option_representives_inverted, Field, p, m-3, 2+(p-1)*4 );		//Spieler p
			} else if (p%2 == 0) {
				set_gleiter_links_oben (single_option_representives_inverted, Field, p, m-3, 2+(p-1)*4);		//Spieler p
			}
		}
	} else if (gamemode_played == Quidditch) {
		
		set_triangle_unten_rechts (single_option_representives_inverted, Field, 1, 1+2, (n-1)/2 +2);	//Squares player 1
		set_triangle_unten_links (single_option_representives_inverted, Field, 1, 1+2, (n-1)/2 -2);
		set_gleiter_rechts_unten (single_option_representives_inverted, Field, 1, 2, 2);
		set_gleiter_links_unten (single_option_representives_inverted, Field, 1, 2, n-3);
		set_triangle_oben_rechts (single_option_representives_inverted, Field, 1, (m-2)/2 -1, (n-1)/2 +2);
		set_triangle_unten_links (single_option_representives_inverted, Field, 1, (m-2)/2 +2, (n-1)/2 -2);
		set_mountain_unten (single_option_representives_inverted, Field, 1, (m-2)/2 -4, (n-1)/2);
		set_net_basic_two_four (single_option_representives_inverted, Field, 1, (m-2)/2 -2, n-5);
		set_edge_oben_links (single_option_representives_inverted, Field, 1, (m-2)/2 -3, 4);
		set_triangle_oben_rechts (single_option_representives_inverted, Field, 1, (m-2)/2 -1, 2);	//Squares player 1
		
		set_triangle_oben_rechts (single_option_representives_inverted, Field, 2, (m-2) -2, (n-1)/2 +2);	//Squares player 2
		set_triangle_oben_links (single_option_representives_inverted, Field, 2, (m-2) -2, (n-1)/2 -2);
		set_gleiter_rechts_oben (single_option_representives_inverted, Field, 2, m-3, 2);
		set_gleiter_links_oben (single_option_representives_inverted, Field, 2, m-3, n-3);
		set_triangle_unten_rechts (single_option_representives_inverted, Field, 2, (m-2)/2 +2, (n-1)/2 +2);
		set_triangle_oben_links (single_option_representives_inverted, Field, 2, (m-2)/2 -1, (n-1)/2 -2);
		set_mountain_oben (single_option_representives_inverted, Field, 2, (m-2)/2 +5, (n-1)/2);
		set_edge_unten_rechts (single_option_representives_inverted, Field, 2, (m-2)/2 +4, n-5);
		set_triangle_unten_links (single_option_representives_inverted, Field, 2, (m-2)/2 +2, n-3);
		
		set_net_basic_two_four (single_option_representives_inverted, Field, 2, (m-2)/2 +2, 3);	//Squares player 2
		
		
		set_gleiter_links_unten (single_option_representives_inverted, Field, 1, (m-2) -3, (n-1)/2 +5);	//Squares player 1
		set_gleiter_rechts_unten (single_option_representives_inverted, Field, 1, (m-2) -3, (n-1)/2 -5);	//Squares player 1
		
		set_gleiter_links_oben (single_option_representives_inverted, Field, 2, 1 +3, (n-1)/2 +5);	//Squares player 2
		set_gleiter_rechts_oben (single_option_representives_inverted, Field, 2, 1 +3, (n-1)/2 -5);	//Squares player 2
		
		
		
		
		// set_triangle_unten_rechts (single_option_representives_inverted, Field, 1, 1+2, (n-1)/2 -1);	//Squares player 1
		// set_triangle_unten_links (single_option_representives_inverted, Field, 1, 1+2, (n-1)/2 +1);
		// set_triangle_oben_links (single_option_representives_inverted, Field, 1, (m-2)/2 -1, 1);
		// set_triangle_oben_rechts (single_option_representives_inverted, Field, 1, (m-2)/2 -1, n-2);
		// set_gleiter_links_unten (single_option_representives_inverted, Field, 1, (m-2)/2 -4, (n-1)/2);
		// set_triangle_oben_links (single_option_representives_inverted, Field, 1, 1+3, n-3);
		// set_triangle_oben_rechts (single_option_representives_inverted, Field, 1, 1+3, 2);
		
		// set_triangle_oben_rechts (single_option_representives_inverted, Field, 2, (m-2) -2, (n-1)/2 -1);	//Squares player 2
		// set_triangle_oben_links (single_option_representives_inverted, Field, 2, (m-2) -2, (n-1)/2 +1);
		// set_triangle_unten_links (single_option_representives_inverted, Field, 2, (m-2)/2 +2, 1);
		// set_triangle_unten_rechts (single_option_representives_inverted, Field, 2, (m-2)/2 +2, n-2);
		// set_gleiter_rechts_oben (single_option_representives_inverted, Field, 2, (m-2)/2 +5, (n-1)/2);
		// set_triangle_unten_links (single_option_representives_inverted, Field, 2, m-5, n-3);
		// set_triangle_unten_rechts (single_option_representives_inverted, Field, 2, m-5, 2);
		
		for (unsigned int j=(n-1)/2 -2; j<=(n-1)/2 +2; j+=2) {	//Torringe
			set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, 1, j, Torring_1);
			set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, m-2, j, Torring_2);
		}
		set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, (m-2)/2 -1, (n-1)/2, Klatscher);	//Quidditch Bälle
		set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, (m-2)/2, (n-1)/2, Quaffel);
		set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, (m-2)/2 +1, (n-1)/2, Schnatz);
		set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, (m-2)/2 +2, (n-1)/2, Klatscher);
		
		set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, 1+2, (n-1)/2, Hueter_1);	//Team_1
		set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, (m-2)/2 -1, 2, Jaeger_1);
		set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, (m-2)/2 -1, n-3, Jaeger_1);
		set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, (m-2)/2 -2, 5, Treiber_1);
		set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, (m-2)/2 -2, n-6, Treiber_1);
		set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, (m-2)/2 -3, (n-1)/2 +1, Jaeger_1);
		set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, (m-2)/2 -4, (n-1)/2 -2, Sucher_1);
		
		set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, (m-2)-2, (n-1)/2, Hueter_2);	//Team_2
		set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, (m-2)/2 +2, 2, Jaeger_2);
		set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, (m-2)/2 +2, n-3, Jaeger_2);
		set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, (m-2)/2 +3, 5, Treiber_2);
		set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, (m-2)/2 +3, n-6, Treiber_2);
		set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, (m-2)/2 +4, (n-1)/2 -1, Jaeger_2);
		set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, (m-2)/2 +5, (n-1)/2 +2, Sucher_2);
	}
}

