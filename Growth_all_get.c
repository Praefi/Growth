
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
#include "Growth_all_show.h"
#include "Growth_all_Initialisierung.h"
#include "Growth_all_get.h"


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

