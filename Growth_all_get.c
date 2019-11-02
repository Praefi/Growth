
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#ifdef _WIN32
#include <windows.h>
#endif


#include "Growth_all_Def.h"
#include "Growth_all_Vektor.h"
#include "Growth_all_set.h"
#include "Growth_all_options_specials.h"
#include "Growth_all_show.h"
#include "Growth_all_Initialisierung.h"
#include "Growth_all_get.h"


void get_hints (unsigned int* level, Spielfeld Sf_permutations, unsigned int gamemode_played, Spielfeld Field, unsigned int geben, unsigned int w, unsigned int d, unsigned int e, unsigned int m, unsigned int n, unsigned int* information_code, Special_Fields Opague_o, Growth_Player* Growth_players, unsigned int AOP, Special_Fields Allocation_o, unsigned int number_of_players) {

	Spielfeld hint;
	unsigned int b, a, menuoperator;
	hint = Spielfeld_Create (m, n, 0);

	b = 0;
	a = 0;
	menuoperator = 0;

	for (unsigned int i=1; i<(m-1); i+=1){
		for (unsigned int j=1; j<(n-1); j+=1){
			if (Field[0][i][j] == geben){
				set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, hint, 0, i, j, geben);
			} else if (Field[0][i][j] != 0){
				set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, hint, 0, i, j, bir_sey);
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
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, hint, 0, i, j, oeluem);
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
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, hint, 0, i, j, dogum);
					}
				}
			}
		}
	}

	if (Opague_o.characterization >= 1) {
		opague_builder (hint, Opague_o, m, n, geben, AOP, Allocation_o, number_of_players, gamemode_played);
		show_field (number_of_players, level, Sf_permutations, Opague_o.field, Opague_o.field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
	} else {
		show_field (number_of_players, level, Sf_permutations, Opague_o.field, hint, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
	}

	Spielfeld_Destroy (hint, m, 0);

}
unsigned int get_m (unsigned int gamemode_played, unsigned int number_of_players) {
	unsigned int m;
	m = 0;

	if (gamemode_played == Classic){	//that's right
		printf(" Zeilen: >=6				(normal: 10) \n");
		m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

		if (m<6){
			printf("	You missed the assertion(s) !!! \n");
			printf("\n");
			m = 12;
		} else {
			m += 2;
		}
	} else if (gamemode_played == Collect) {
		printf(" Zeilen: >=7, mod2==1				(normal: 9) \n");
		m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

		if ((m<7)||(m%2==0)){
			printf("	You missed the assertion(s) !!! \n");
			printf("\n");
			m = 9 +2;
		} else {
			m += 2;
		}
	} else if (gamemode_played == Contact) {
		printf(" Zeilen: >=6				(normal: %u) \n", 10+(number_of_players-2));
		m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

		if (m<6){
			printf("	You missed the assertion(s) !!! \n");
			printf("\n");
			m = 10+(number_of_players-2) +2;
		} else {
			m += 2;
		}
	} else if (gamemode_played == Fall) {
		printf(" Zeilen: >=3				(normal: %u) \n", 6+2*(((number_of_players+1)/2)-1));
		m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

		if (m<3){
			printf("	You missed the assertion(s) !!! \n");
			printf("\n");
			m = 6+2*(((number_of_players+1)/2)-1) +2;
		} else {
			m += 2;
		}
	} else if (gamemode_played == Fight) {
		printf(" Zeilen: >=6				(normal: 6) \n");
		m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

		if (m<6){
			printf("	You missed the assertion(s) !!! \n");
			printf("\n");
			m = 6 +2;
		} else {
			m += 2;
		}
	} else if (gamemode_played == Hunt) {
		if (number_of_players == 2) {
			printf(" Zeilen: >=3, mod2==1				(normal: 7) \n");
			m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((m<3)||(m%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				m = 9;
			} else {
				m += 2;
			}
		} else if (number_of_players == 3) {
			printf(" Zeilen: >=3, mod2==1				(normal: 7) \n");
			m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((m<3)||(m%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				m = 9;
			} else {
				m += 2;
			}
		} else if (number_of_players == 4) {
			printf(" Zeilen: >=7, mod2==1				(normal: 11) \n");
			m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((m<7)||(m%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				m = 13;
			} else {
				m += 2;
			}
		} else if (number_of_players == 5) {
			printf(" Zeilen: >=9, mod2==1				(normal: 13) \n");
			m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((m<9)||(m%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				m = 15;
			} else {
				m += 2;
			}
		} else if (number_of_players == 6) {
			printf(" Zeilen: >=9, mod2==1				(normal: 13) \n");
			m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((m<9)||(m%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				m = 15;
			} else {
				m += 2;
			}
		} else if (number_of_players == 7) {
			printf(" Zeilen: >=9, mod2==1				(normal: 15) \n");
			m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((m<9)||(m%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				m = 17;
			} else {
				m += 2;
			}
		} else if (number_of_players == 8) {
			printf(" Zeilen: >=10, mod2==0				(normal: 16) \n");
			m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((m<9)||(m%2==1)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				m = 18;
			} else {
				m += 2;
			}
		} else if (number_of_players == 9) {
			printf(" Zeilen: >=13, mod2==1				(normal: 21) \n");
			m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((m<9)||(m%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				m = 23;
			} else {
				m += 2;
			}
		}
	} else if (gamemode_played == Race) {
		printf(" Zeilen: >=%u, mod(Number of players)==-1			(normal: %u) \n", 4*number_of_players-1, 4*number_of_players-1);
		m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

		if ((m<4*number_of_players-1)||(m%number_of_players != number_of_players-1)){
			printf("	You missed the assertion(s) !!! \n");
			printf("\n");
			m = 4*number_of_players-1 +2;
		} else {
			m += 2;
		}
	} else if (gamemode_played == Rain) {
		printf(" Zeilen: >=3				(normal: 6) \n");
		m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

		if (m<3){
			printf("	You missed the assertion(s) !!! \n");
			printf("\n");
			m = 6 +2;
		} else {
			m += 2;
		}
	} else if (gamemode_played == Arena) {
		if (number_of_players == 2) {
			printf(" Zeilen: >=3, mod2==1				(normal: 7) \n");
			m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((m<3)||(m%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				m = 9;
			} else {
				m += 2;
			}
		} else if (number_of_players == 3) {
			printf(" Zeilen: >=7, mod2==1				(normal: 7) \n");
			m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((m<7)||(m%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				m = 9;
			} else {
				m += 2;
			}
		} else if (number_of_players == 4) {
			printf(" Zeilen: >=9, mod2==1				(normal: 9) \n");
			m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((m<9)||(m%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				m = 11;
			} else {
				m += 2;
			}
		} else if (number_of_players == 5) {
			printf(" Zeilen: >=8, mod2==0				(normal: 10) \n");
			m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((m<8)||(m%2==1)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				m = 12;
			} else {
				m += 2;
			}
		} else if (number_of_players == 6) {
			printf(" Zeilen: >=7, mod2==1				(normal: 11) \n");
			m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((m<7)||(m%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				m = 13;
			} else {
				m += 2;
			}
		} else if (number_of_players == 7) {
			printf(" Zeilen: >=8, mod2==0				(normal: 12) \n");
			m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((m<4)||(m%2==1)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				m = 14;
			} else {
				m += 2;
			}
		} else if (number_of_players == 8) {
			printf(" Zeilen: >=12, mod2==0				(normal: 14) \n");
			m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((m<12)||(m%2==1)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				m = 16;
			} else {
				m += 2;
			}
		} else if (number_of_players == 9) {
			printf(" Zeilen: >=12, mod2==0				(normal: 14) \n");
			m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((m<12)||(m%2==1)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				m = 16;
			} else {
				m += 2;
			}
		}
	} else if (gamemode_played == Ulcer) {
		if (number_of_players == 2) {
			printf(" Zeilen: >=6				(normal: 6) \n");
			m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if (m<6){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				m = 8;
			} else {
				m += 2;
			}
		} else if (number_of_players == 3) {
			printf(" Zeilen: >=7				(normal: 7) \n");
			m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if (m<7){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				m = 9;
			} else {
				m += 2;
			}
		} else if (number_of_players == 4) {
			printf(" Zeilen: >=9				(normal: 9) \n");
			m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if (m<9){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				m = 11;
			} else {
				m += 2;
			}
		} else if (number_of_players == 5) {
			printf(" Zeilen: >=10				(normal: 10) \n");
			m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if (m<10){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				m = 12;
			} else {
				m += 2;
			}
		} else if (number_of_players == 6) {
			printf(" Zeilen: >=11				(normal: 11) \n");
			m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if (m<11){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				m = 13;
			} else {
				m += 2;
			}
		} else if (number_of_players == 7) {
			printf(" Zeilen: >=12				(normal: 12) \n");
			m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if (m<12){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				m = 14;
			} else {
				m += 2;
			}
		} else if (number_of_players == 8) {
			printf(" Zeilen: >=13				(normal: 13) \n");
			m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if (m<13){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				m = 15;
			} else {
				m += 2;
			}
		} else if (number_of_players == 9) {
			printf(" Zeilen: >=14				(normal: 14) \n");
			m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if (m<14){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				m = 16;
			} else {
				m += 2;
			}
		}

	} else if (gamemode_played == Dynamic) {
		if (number_of_players == 2) {
			printf(" Zeilen: >=3, mod2==1				(normal: 7) \n");
			m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((m<3)||(m%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				m = 9;
			} else {
				m += 2;
			}
		} else if (number_of_players == 3) {
			printf(" Zeilen: >=5, mod2==1				(normal: 9) \n");
			m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((m<5)||(m%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				m = 11;
			} else {
				m += 2;
			}
		} else if (number_of_players == 4) {
			printf(" Zeilen: >=7, mod2==1				(normal: 11) \n");
			m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((m<7)||(m%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				m = 13;
			} else {
				m += 2;
			}
		} else if (number_of_players == 5) {
			printf(" Zeilen: >=7, mod2==1				(normal: 11) \n");
			m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((m<7)||(m%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				m = 13;
			} else {
				m += 2;
			}
		} else if (number_of_players == 6) {
			printf(" Zeilen: >=9, mod2==1				(normal: 15) \n");
			m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((m<9)||(m%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				m = 17;
			} else {
				m += 2;
			}
		} else if (number_of_players == 7) {
			printf(" Zeilen: >=9, mod2==1				(normal: 15) \n");
			m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((m<9)||(m%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				m = 17;
			} else {
				m += 2;
			}
		} else if (number_of_players == 8) {
			printf(" Zeilen: >=9, mod2==1				(normal: 17) \n");
			m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((m<9)||(m%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				m = 19;
			} else {
				m += 2;
			}
		} else if (number_of_players == 9) {
			printf(" Zeilen: >=11, mod2==1				(normal: 17) \n");
			m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((m<11)||(m%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				m = 19;
			} else {
				m += 2;
			}
		}
	} else if (gamemode_played == Survive) {
		if (number_of_players == 1) {
			printf(" Zeilen: >=3				(normal: 10) \n");
			m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if (m<3){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				m = 12;
			} else {
				m += 2;
			}
		} else if (number_of_players == 2) {
			printf(" Zeilen: >=3				(normal: 11) \n");
			m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if (m<6){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				m = 13;
			} else {
				m += 2;
			}
		} else if (number_of_players == 3) {
			printf(" Zeilen: >=6				(normal: 12) \n");
			m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if (m<6){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				m = 14;
			} else {
				m += 2;
			}
		} else if (number_of_players == 4) {
			printf(" Zeilen: >=6				(normal: 13) \n");
			m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if (m<6){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				m = 15;
			} else {
				m += 2;
			}
		} else if (number_of_players == 5) {
			printf(" Zeilen: >=7, mod2==1				(normal: 15) \n");
			m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((m<7)||(m%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				m = 17;
			} else {
				m += 2;
			}
		} else if (number_of_players == 6) {
			printf(" Zeilen: >=9, mod2==1				(normal: 15) \n");
			m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((m<9)||(m%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				m = 17;
			} else {
				m += 2;
			}
		} else if (number_of_players == 7) {
			printf(" Zeilen: >=9, mod2==1				(normal: 17) \n");
			m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((m<9)||(m%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				m = 19;
			} else {
				m += 2;
			}
		} else if (number_of_players == 8) {
			printf(" Zeilen: >=9, mod2==1				(normal: 17) \n");
			m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((m<9)||(m%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				m = 19;
			} else {
				m += 2;
			}
		} else if (number_of_players == 9) {
			printf(" Zeilen: >=9, mod2==1				(normal: 17) \n");
			m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((m<9)||(m%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				m = 19;
			} else {
				m += 2;
			}
		}
	} else if (gamemode_played == Sand) {
		printf(" Zeilen: >=4				(normal: %u) \n", 5+number_of_players);
		m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

		if (m<4){
			printf("	You missed the assertion(s) !!! \n");
			printf("\n");
			m = 5+number_of_players +2;
		} else {
			m += 2;
		}
	}

	return m;
}

unsigned int get_n (unsigned int gamemode_played, unsigned int number_of_players) {
	unsigned int n;
	n = 0;
		//n-2 >= 3*((number_of_players+1)/2)
	if (gamemode_played == Classic){
		printf(" Spalten: >=%u				(normal: %u) \n", 3*((number_of_players+1)/2), 3*((number_of_players+3)/2));
		n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

		if (n<(3*((number_of_players+1)/2))){
			printf("	You missed the assertion(s) !!! \n");
			printf("\n");
			n = 3*((number_of_players+3)/2) +2;
		} else {
			n += 2;
		}
	} else if (gamemode_played == Collect) {
		printf(" Spalten: >=%u, mod(Number of players)==3				(normal: %u) \n", 2*(number_of_players+1)+1, 4+(4*number_of_players)-1);
		n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

		if ((n<2*(number_of_players+1)+1)||((n-3)%number_of_players!=0)){
			printf("	You missed the assertion(s) !!! \n");
			printf("\n");
			n = 4+(4*number_of_players)-1 +2;
		} else {
			n += 2;
		}
	} else if (gamemode_played == Contact) {
		if (number_of_players == 2) {
			printf(" Spalten: >=%u, mod2==0				(normal: %u) \n", 8*((number_of_players+1)/2), 8*((number_of_players+2)/2));
			n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((n<8*((number_of_players+1)/2))||(n%2!=0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				n = 8*((number_of_players+2)/2) +2;
			} else {
				n += 2;
			}
		} else {
			printf(" Spalten: >=%u, mod((Number of players+1)/2)==0				(normal: %u) \n", 8*((number_of_players+1)/2), 8*((number_of_players+1)/2));
			n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((n<8*((number_of_players+1)/2))||(n%((number_of_players+1)/2)!=0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				n = 8*((number_of_players+1)/2) +2;
			} else {
				n += 2;
			}
		}
	} else if (gamemode_played == Fall) {
		printf(" Spalten: >=%u, mod2==1				(normal: %u) \n", 3*2*((number_of_players+1)/2)+1, 5*2*((number_of_players+1)/2)+1);
		n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

		if ((n<3*2*((number_of_players+1)/2)+1)||(n%2==0)){
			printf("	You missed the assertion(s) !!! \n");
			printf("\n");
			n = 5*2*((number_of_players+1)/2)+1 +2;
		} else {
			n += 2;
		}
	} else if (gamemode_played == Fight) {
		printf(" Spalten: >=%u,			(normal: %u) \n", 4+4*((number_of_players+1-2)/2), 6+4*((number_of_players+1-2)/2));
		n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

		if (n<4+4*((number_of_players+1-2)/2)){
			printf("	You missed the assertion(s) !!! \n");
			printf("\n");
			n = 6+4*((number_of_players+1-2)/2) +2;
		} else {
			n += 2;
		}
	} else if (gamemode_played == Hunt) {
		if (number_of_players == 2) {
			printf(" Spalten: >=7, mod2==1				(normal: 9) \n");
			n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((n<7)||(n%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				n = 11;
			} else {
				n += 2;
			}
		} else if (number_of_players == 3) {
			printf(" Spalten: >=9, mod2==1				(normal: 13) \n");
			n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((n<9)||(n%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				n = 15;
			} else {
				n += 2;
			}
		} else if (number_of_players == 4) {
			printf(" Spalten: >=9, mod2==1				(normal: 13) \n");
			n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((n<9)||(n%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				n = 15;
			} else {
				n += 2;
			}
		} else if (number_of_players == 5) {
			printf(" Spalten: >=9, mod2==1				(normal: 13) \n");
			n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((n<9)||(n%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				n = 15;
			} else {
				n += 2;
			}
		} else if (number_of_players == 6) {
			printf(" Spalten: >=10, mod2==0				(normal: 16) \n");
			n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((n<10)||(n%2==1)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				n = 18;
			} else {
				n += 2;
			}
		} else if (number_of_players == 7) {
			printf(" Spalten: >=13, mod2==1				(normal: 19) \n");
			n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((n<13)||(n%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				n = 21;
			} else {
				n += 2;
			}
		} else if (number_of_players == 8) {
			printf(" Spalten: >=13, mod2==1				(normal: 21) \n");
			n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((n<13)||(n%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				n = 23;
			} else {
				n += 2;
			}
		} else if (number_of_players == 9) {
			printf(" Spalten: >=13, mod2==1				(normal: 21) \n");
			n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((n<13)||(n%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				n = 23;
			} else {
				n += 2;
			}
		}
	} else if (gamemode_played == Race) {
		printf(" Spalten: >=5				(normal: 19) \n");
		n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

		if (n<5) {
			printf("	You missed the assertion(s) !!! \n");
			printf("\n");
			n = 19 +2;
		} else {
			n += 2;
		}
	} else if (gamemode_played == Arena) {
		if (number_of_players == 2) {
			printf(" Spalten: >=7, mod2==1				(normal: 7) \n");
			n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((n<7)||(n%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				n = 9;
			} else {
				n += 2;
			}
		} else if (number_of_players == 3) {
			printf(" Spalten: >=7, mod2==1				(normal: 7) \n");
			n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((n<7)||(n%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				n = 9;
			} else {
				n += 2;
			}
		} else if (number_of_players == 4) {
			printf(" Spalten: >=9, mod2==1				(normal: 9) \n");
			n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((n<9)||(n%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				n = 11;
			} else {
				n += 2;
			}
		} else if (number_of_players == 5) {
			printf(" Spalten: >=8, mod2==0				(normal: 10) \n");
			n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((n<8)||(n%2==1)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				n = 12;
			} else {
				n += 2;
			}
		} else if (number_of_players == 6) {
			printf(" Spalten: >=13, mod2==1				(normal: 11) \n");
			n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((n<13)||(n%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				n = 13;
			} else {
				n += 2;
			}
		} else if (number_of_players == 7) {
			printf(" Spalten: >=12, mod2==0				(normal: 12) \n");
			n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((n<12)||(n%2==1)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				n = 14;
			} else {
				n += 2;
			}
		} else if (number_of_players == 8) {
			printf(" Spalten: >=12, mod2==0				(normal: 14) \n");
			n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((n<12)||(n%2==1)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				n = 16;
			} else {
				n += 2;
			}
		} else if (number_of_players == 9) {
			printf(" Spalten: >=12, mod2==0				(normal: 14) \n");
			n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((n<12)||(n%2==1)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				n = 16;
			} else {
				n += 2;
			}
		}
	} else if (gamemode_played == Ulcer) {
		if (number_of_players == 2) {
			printf(" Spalten: >=6				(normal: 6) \n");
			n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if (n<6){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				n = 8;
			} else {
				n += 2;
			}
		} else if (number_of_players == 3) {
			printf(" Spalten: >=7				(normal: 7) \n");
			n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if (n<7){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				n = 9;
			} else {
				n += 2;
			}
		} else if (number_of_players == 4) {
			printf(" Spalten: >=9				(normal: 9) \n");
			n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if (n<9){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				n = 11;
			} else {
				n += 2;
			}
		} else if (number_of_players == 5) {
			printf(" Spalten: >=10				(normal: 10) \n");
			n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if (n<10){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				n = 12;
			} else {
				n += 2;
			}
		} else if (number_of_players == 6) {
			printf(" Spalten: >=11				(normal: 11) \n");
			n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if (n<11){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				n = 13;
			} else {
				n += 2;
			}
		} else if (number_of_players == 7) {
			printf(" Spalten: >=12				(normal: 12) \n");
			n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if (n<12){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				n = 14;
			} else {
				n += 2;
			}
		} else if (number_of_players == 8) {
			printf(" Spalten: >=13				(normal: 13) \n");
			n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if (n<13){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				n = 15;
			} else {
				n += 2;
			}
		} else if (number_of_players == 9) {
			printf(" Spalten: >=14				(normal: 14) \n");
			n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if (n<14){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				n = 16;
			} else {
				n += 2;
			}
		}

	} else if (gamemode_played == Dynamic) {
		if (number_of_players == 2) {
			printf(" Spalten: >=7, mod2==1				(normal: 11) \n");
			n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((n<7)||(n%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				n = 11;
			} else {
				n += 2;
			}
		} else if (number_of_players == 3) {
			printf(" Spalten: >=7, mod2==1				(normal: 11) \n");
			n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((n<7)||(n%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				n = 13;
			} else {
				n += 2;
			}
		} else if (number_of_players == 4) {
			printf(" Spalten: >=7, mod2==1				(normal: 11) \n");
			n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((n<7)||(n%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				n = 13;
			} else {
				n += 2;
			}
		} else if (number_of_players == 5) {
			printf(" Spalten: >=7, mod2==1				(normal: 15) \n");
			n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((n<7)||(n%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				n = 17;
			} else {
				n += 2;
			}
		} else if (number_of_players == 6) {
			printf(" Spalten: >=9, mod2==1				(normal: 15) \n");
			n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((n<9)||(n%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				n = 17;
			} else {
				n += 2;
			}
		} else if (number_of_players == 7) {
			printf(" Spalten: >=9, mod2==1				(normal: 15) \n");
			n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((n<9)||(n%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				n = 17;
			} else {
				n += 2;
			}
		} else if (number_of_players == 8) {
			printf(" Spalten: >=9, mod2==1				(normal: 17) \n");
			n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((n<9)||(n%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				n = 19;
			} else {
				n += 2;
			}
		} else if (number_of_players == 9) {
			printf(" Spalten: >=11, mod2==1				(normal: 17) \n");
			n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((n<11)||(n%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				n = 19;
			} else {
				n += 2;
			}
		}
	} else if (gamemode_played == Survive) {
		if (number_of_players == 1) {
			printf(" Spalten: >=3				(normal: 10) \n");
			n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if (n<3){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				n = 12;
			} else {
				n += 2;
			}
		} else if (number_of_players == 2) {
			printf(" Spalten: >=6				(normal: 11) \n");
			n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if (n<6){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				n = 13;
			} else {
				n += 2;
			}
		} else if (number_of_players == 3) {
			printf(" Spalten: >=6				(normal: 12) \n");
			n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if (n<6){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				n = 14;
			} else {
				n += 2;
			}
		} else if (number_of_players == 4) {
			printf(" Spalten: >=6				(normal: 13) \n");
			n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if (n<6){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				n = 15;
			} else {
				n += 2;
			}
		} else if (number_of_players == 5) {
			printf(" Spalten: >=7, mod2==1				(normal: 15) \n");
			n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((n<7)||(n%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				n = 17;
			} else {
				n += 2;
			}
		} else if (number_of_players == 6) {
			printf(" Spalten: >=6				(normal: 15) \n");
			n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if (n<6){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				n = 17;
			} else {
				n += 2;
			}
		} else if (number_of_players == 7) {
			printf(" Spalten: >=9, mod2==1				(normal: 17) \n");
			n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((n<9)||(n%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				n = 19;
			} else {
				n += 2;
			}
		} else if (number_of_players == 8) {
			printf(" Spalten: >=9, mod2==1				(normal: 17) \n");
			n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((n<9)||(n%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				n = 19;
			} else {
				n += 2;
			}
		} else if (number_of_players == 9) {
			printf(" Spalten: >=9, mod2==1				(normal: 17) \n");
			n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((n<9)||(n%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				n = 19;
			} else {
				n += 2;
			}
		}
	} else if (gamemode_played == Sand) {
		if (number_of_players == 1) {
			printf(" Spalten: >=3				(normal: 4) \n");
			n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if (n<3){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				n = 6;
			} else {
				n += 2;
			}
		} else {
			printf(" Spalten: >=%u				(normal: %u) \n", 3+4*(number_of_players-1), 3+4*(number_of_players-1));
			n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if (n<3+4*(number_of_players-1)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				n = 5+4*(number_of_players-1);
			} else {
				n += 2;
			}
		}
	}

	return n;
}

unsigned int get_unsigned_numeric_input_with_not_more_than_3_letters () {
	char input[3];
	unsigned int parameter;
	int atoi_saver;

	atoi_saver = 0;
	parameter = 0;

	scanf("%3s", input);

	if (isdigit(*input) == 0) {
		printf("	You should give me natural numbers, this will be count as a 0. \n");
	} else {

		atoi_saver = abs(atoi(input));

		if (atoi_saver != 0) {
			for (int q=1; q<=atoi_saver; q+=1) {
				parameter += 1;
			}
		}
	}
	printf("\n");

	return parameter;	//returning 0 if there is made a mistake
}

unsigned int get_unsigned_numeric_input_with_not_more_than_letters_4_for_splitting () {
	char input[4];
	unsigned int parameter;
	int atoi_saver;

	atoi_saver = 0;
	parameter = 0;

	scanf("%4s", input);

	if (isdigit(*input) == 0) {
		printf("	You should give me natural numbers, this will be count as a 0. \n");
	} else {

		atoi_saver = abs(atoi(input));

		if (atoi_saver != 0) {
			for (int q=1; q<=atoi_saver; q+=1) {
				parameter += 1;
			}
		}
	}
	printf("\n");

	return parameter;	//returning 0 if there is made a mistake
}

unsigned int get_unsigned_numeric_input_with_not_more_than_2_letters () {
	char input[2];
	unsigned int parameter;
	int atoi_saver;

	atoi_saver = 0;
	parameter = 0;

	scanf("%2s", input);

	if (isdigit(*input) == 0) {
		printf("	You should give me natural numbers, this will be count as a 0. \n");
	} else {

		// printf("atoi(input): %d \n", atoi(input));	//test
		// printf("abs(atoi(input)): %d \n", abs(atoi(input)));	//test

		atoi_saver = abs(atoi(input));

		// printf("atoi_saver: %d \n", atoi_saver);	//test

		if (atoi_saver != 0) {
			for (int q=1; q<=atoi_saver; q+=1) {

				parameter += 1;

				// printf("parameter: %u  q: %d \n \n", parameter, q);	//test

			}
		}

		// printf("parameter: %u \n", parameter);	//test

	}
	printf("\n");

	return parameter;	//returning 0 if there is made a mistake
}

unsigned int split_unsigned_numeric_input_with_letters_4 (unsigned int letters_4, unsigned int which_part) {	//which_part=0 => first, which_part=1 => second.
	unsigned int parameter;
	parameter = 0;

	if (which_part == 0) {
		parameter = letters_4/100;
	} else if (which_part == 1) {
		parameter = letters_4%100;
	}

	return parameter;
}

unsigned int split_unsigned_numeric_input_with_letters_2 (unsigned int letters_2, unsigned int which_part) {	//which_part=0 => first, which_part=1 => second.
	unsigned int parameter;
	parameter = 0;

	if (which_part == 0) {
		parameter = letters_2/10;
	} else if (which_part == 1) {
		parameter = letters_2%10;
	}

	return parameter;
}

unsigned int get_unsigned_numeric_input_with_not_more_than_letters_2_for_splitting () {
	char input[2];
	unsigned int parameter;
	int atoi_saver;

	atoi_saver = 0;
	parameter = 0;

	scanf("%2s", input);

	if (isdigit(*input) == 0) {
		printf("	You should give me natural numbers, this will be count as a 0. \n");
	} else {

		atoi_saver = abs(atoi(input));

		if (atoi_saver != 0) {
			for (int q=1; q<=atoi_saver; q+=1) {
				parameter += 1;
			}
		}
	}
	printf("\n");

	return parameter;	//returning 0 if there is made a mistake
}

unsigned int get_unsigned_numeric_input_with_not_more_than_1_letter () {
	char input[1];
	unsigned int parameter;
	int atoi_saver;

	atoi_saver = 0;
	parameter = 0;

	scanf("%1s", input);

	if (isdigit(*input) == 0) {
		printf("	You should give me natural numbers, this will be count as a 0. \n");
	} else {

		atoi_saver = abs(atoi(input));

		if (atoi_saver != 0) {
			for (int q=1; q<=atoi_saver; q+=1) {
				parameter += 1;
			}
		}
	}
	printf("\n");

	return parameter;	//returning 0 if there is made a mistake
}

int get_signed_numeric_input_with_not_more_than_1_letter () {
	char input[1];
	int parameter;

	parameter = 0;

	scanf("%1s", input);

	if (isdigit(*input) == 0) {
		printf("	You should give me natural numbers with a sign, this will be count as a 0. \n");
	} else {
		parameter = atoi (input);
	}
	printf("\n");

	return parameter;
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


void get_two_amounts_for_permutations (unsigned int* aopn_b, unsigned int* aopn_c, unsigned int m, unsigned int n, unsigned int Collector_of_permutation_permutation_number_b, unsigned int Collector_of_permutation_permutation_number_c) {	//permutation_number_b, permutation_number_c are arguments, 0<permutation_number_b<permutation_number_c<10
	unsigned int x, y, a;
	x = m-2;
	y = n-2;
	a = 0;

	// printf("get_two_amounts_for_permutations ok.1 \n");	//test
	if ((x*y)%Collector_of_permutation_permutation_number_c == 0) {
		*aopn_b = 0;
		*aopn_c = (x*y)/Collector_of_permutation_permutation_number_c;
	} else if ((x*y)%Collector_of_permutation_permutation_number_b == 0) {
		*aopn_b = (x*y)/Collector_of_permutation_permutation_number_b;
		*aopn_c = 0;
	} else {
		*aopn_b = (x*y)/(Collector_of_permutation_permutation_number_b+Collector_of_permutation_permutation_number_c);
		*aopn_c = (x*y)/(Collector_of_permutation_permutation_number_b+Collector_of_permutation_permutation_number_c);
		a = (x*y)%(Collector_of_permutation_permutation_number_b+Collector_of_permutation_permutation_number_c);
	}

	// printf("get_two_amounts_for_permutations ok.2 \n");	//test

	if (a/Collector_of_permutation_permutation_number_c != 0) {
		*aopn_c += a/Collector_of_permutation_permutation_number_c;
		a = a % Collector_of_permutation_permutation_number_c;
	}
	if (a/Collector_of_permutation_permutation_number_b != 0) {
		*aopn_b += a/Collector_of_permutation_permutation_number_b;
		a = a % Collector_of_permutation_permutation_number_b;
	}

	// printf("get_two_amounts_for_permutations ok.3 \n");	//test

	if (a > 0) {
		int* Rest;
		int* permutation_number_c_factor;
		int* permutation_number_b_factor;	//die Null wird wegen Vorganger nicht gebraucht.
		unsigned int durchlauf;

		Rest = int_Vektor_Create (4);
		permutation_number_c_factor = int_Vektor_Create (4);
		permutation_number_b_factor = int_Vektor_Create (4);

		Rest[2] = Collector_of_permutation_permutation_number_b;
		Rest[1] = Collector_of_permutation_permutation_number_c;
		permutation_number_b_factor[2] = 1;
		permutation_number_b_factor[1] = 0;
		permutation_number_c_factor[2] = 0;
		permutation_number_c_factor[1] = 1;
		durchlauf = 2;

		// printf("get_two_amounts_for_permutations ok.4 \n");	//test

		while ((Rest[1] != 1)&&(Rest[2] != 1)&&(Rest[3] != 1)) {	//erweiteter euklidischer Algorithmus

			// printf("get_two_amounts_for_permutations while-Schleife ok.4.1 \n");	//test

			Rest[durchlauf%3+1] = Rest[Vorganger(Vorganger(durchlauf%3+1, 3), 3)]-Rest[Vorganger(durchlauf%3+1, 3)]*(Rest[Vorganger(Vorganger(durchlauf%3+1, 3), 3)]/Rest[Vorganger(durchlauf%3+1, 3)]);

			// printf("Rest[%u] = %d \n", durchlauf%3+1, Rest[durchlauf%3+1]);	//test

			permutation_number_c_factor[durchlauf%3+1] = permutation_number_c_factor[Vorganger(Vorganger(durchlauf%3+1, 3), 3)]-permutation_number_c_factor[Vorganger(durchlauf%3+1, 3)]*(Rest[Vorganger(Vorganger(durchlauf%3+1, 3), 3)]/Rest[Vorganger(durchlauf%3+1, 3)]);

			// printf("permutation_number_c_factor[%u] = %d \n", durchlauf%3+1, permutation_number_c_factor[durchlauf%3+1]);	//test

			permutation_number_b_factor[durchlauf%3+1] = permutation_number_b_factor[Vorganger(Vorganger(durchlauf%3+1, 3), 3)]-permutation_number_b_factor[Vorganger(durchlauf%3+1, 3)]*(Rest[Vorganger(Vorganger(durchlauf%3+1, 3), 3)]/Rest[Vorganger(durchlauf%3+1, 3)]);

			// printf("permutation_number_b_factor[%u] = %d \n", durchlauf%3+1, permutation_number_b_factor[durchlauf%3+1]);	//test

			durchlauf++;

			// printf("get_two_amounts_for_permutations while-Schleife ok.4.5 \n");	//test

			if ((Rest[1] == 0)||(Rest[2] == 0)||(Rest[3] == 0)) {
				printf("	ggT(%u, %u) != 1 caused a problem \n", Collector_of_permutation_permutation_number_b, Collector_of_permutation_permutation_number_c);
				durchlauf = 0;	//to know to cancel
				break;
			}
		}

		// printf("get_two_amounts_for_permutations ok.5 \n");	//test

		if (durchlauf != 0) {
			for (unsigned int p=1; p<=3; p++) {
				if (Rest[p] == 1) {
					permutation_number_c_factor[p] *= a;
					permutation_number_b_factor[p] *= a;

					while ((permutation_number_c_factor[p] < 0)&&(abs(permutation_number_c_factor[p]) > abs(*aopn_c))) {
						permutation_number_c_factor[p] += Collector_of_permutation_permutation_number_b;
						permutation_number_b_factor[p] -= Collector_of_permutation_permutation_number_c;
					}
					if ((permutation_number_b_factor[p] < 0)&&(abs(permutation_number_b_factor[p]) > abs(*aopn_b))) {
						printf("	Try again with other arguments or with another size. \n");
					} else {
						if (permutation_number_b_factor[p] < 0) {
							for (int q=1; q<=abs(permutation_number_b_factor[p]); q+=1) {
								*aopn_b -= 1;
							}
						} else if (permutation_number_b_factor[p] > 0) {
							for (int q=1; q<=abs(permutation_number_b_factor[p]); q+=1) {
								*aopn_b += 1;
							}
						}
						if (permutation_number_c_factor[p] < 0) {
							for (int q=1; q<=abs(permutation_number_c_factor[p]); q+=1) {
								*aopn_c -= 1;
							}
						} else if (permutation_number_c_factor[p] > 0) {
							for (int q=1; q<=abs(permutation_number_c_factor[p]); q+=1) {
								*aopn_c += 1;
							}
						}

					}
				}
			}
		}

		int_Vektor_Destroy (Rest);

		int_Vektor_Destroy (permutation_number_b_factor);

		int_Vektor_Destroy (permutation_number_c_factor);
	}

	while (*aopn_c > *aopn_b + ((Collector_of_permutation_permutation_number_b+Collector_of_permutation_permutation_number_c)/2)) {
		*aopn_c -= Collector_of_permutation_permutation_number_b;
		*aopn_b += Collector_of_permutation_permutation_number_c;
	}
	while (*aopn_b > *aopn_c + ((Collector_of_permutation_permutation_number_b+Collector_of_permutation_permutation_number_c)/2)) {
		*aopn_b -= Collector_of_permutation_permutation_number_c;
		*aopn_c += Collector_of_permutation_permutation_number_b;
	}

	// printf("	aopn_b: %u \n", *aopn_b);	//test
	// printf("	aopn_c: %u \n", *aopn_c);	//test
	// printf("	Collector_of_permutation_permutation_number_b: %u \n", Collector_of_permutation_permutation_number_b);	//test
	// printf("	Collector_of_permutation_permutation_number_c: %u \n", Collector_of_permutation_permutation_number_c);	//test
	// printf("	x*y: %u \n", x*y);	//test
	// printf("	a: %u \n", a);	//test

	if (Collector_of_permutation_permutation_number_b*(*aopn_b) + Collector_of_permutation_permutation_number_c*(*aopn_c) != x*y) {
		printf("	Bir hata var. Miktarlar yanlis. \n");
		*aopn_c = 0;
		*aopn_b = 0;
	}

	if (Collector_of_permutation_permutation_number_b*(*aopn_b) + Collector_of_permutation_permutation_number_c*(*aopn_c) == x*y) {	//test
		printf("	Her sey dogrudur. \n");
	}
}


void get_sigmas_for_permutation_number (unsigned int** sigmas_for_permutation_number, unsigned int permutation_number) {
	unsigned int Eintrag, hangi_sigma;

	Eintrag = 1;
	hangi_sigma = 0;
	muemkuen_mue = belki;

	// printf("get_sigmas_for_permutation_number ok.1\n");	//test

	for (unsigned int p=1; p<permutation_number; p++) {

		// printf("get_sigmas_for_permutation_number for(p) ok.2\n");	//test

		while ((sigmas_for_permutation_number[Fakultaet(permutation_number-1)-1][p] == 0)||(muemkuen_mue != evet)) {

			// printf("get_sigmas_for_permutation_number while ok.3\n");	//test

			muemkuen_mue = hayir;
			sigmas_for_permutation_number[hangi_sigma][p] = Eintrag;

			for (unsigned int q=0; q<=p; q++) {
				if (hangi_sigma < Fakultaet(permutation_number-1-p)) {
					muemkuen_mue = evet;
					break;
				} else if (sigmas_for_permutation_number[hangi_sigma][q] != sigmas_for_permutation_number[hangi_sigma-Fakultaet(permutation_number-1-p)][q]) {
					muemkuen_mue = evet;
					break;
				}
			}
			for (unsigned int q=0; q<p; q++) {
				if (Eintrag == sigmas_for_permutation_number[hangi_sigma][q]) {
					muemkuen_mue = hayir;
				}
			}
			if (muemkuen_mue == hayir) {
				Eintrag = (Eintrag+1)%permutation_number;
			} else if (muemkuen_mue == evet) {
				hangi_sigma += 1;
			} else if (muemkuen_mue == belki) {
				printf("	hangi_sigma: %u		neden belki?", hangi_sigma);
			}

			// printf("	muemkuen_mue: %u\n", muemkuen_mue);	//test
		}
		hangi_sigma = 0;
	}

	// for (unsigned int p=0; p<Fakultaet(permutation_number-1); p++) {	//test
		// for (unsigned int q=0; q<permutation_number; q++) {
			// printf("	%u", sigmas_for_permutation_number[p][q]);
		// }
		// printf("\n");
	// }	//test

}
