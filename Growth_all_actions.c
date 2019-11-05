
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
#include "Growth_all_visual.h"
#include "Growth_all_get.h"
#include "Growth_all_actions.h"

void Plus (unsigned int* level, Spielfeld Sf_permutations, unsigned int m, unsigned int n, unsigned int geben, Spielfeld Field, unsigned int limits_at_all, unsigned int gamemode_played, unsigned int* information_code, unsigned int number_of_players, Growth_Player* Growth_players, Special_Fields Opague_o, Special_Fields Allocation_o, Single_option_representives single_option_representives){	//checklist
	unsigned int a, b;
	unsigned int Zeile, Spalte;
	
	a = 0;
	b = 0;
	Zeile = 0;
	Spalte = 0;

	if ((gamemode_played == Hunt)&&(geben == 1)) {
		limits_at_all = (limits_at_all+ 2 *(number_of_players - 3));
	}

	for (unsigned int i=1; i<m-1; i+=1){
		for (unsigned int j=1; j<n-1; j+=1){
			if ((geben == 1) && (gamemode_played == Hunt)) {
				if ((Field[0][i][j] == 1)||(Field[0][i][j] == 11)){
					b += 1;
				}
			} else if (Field[0][i][j] == geben){
				b += 1;
			}

		}
	}
	if ((b >= limits_at_all)&&(gamemode_played != Contact)&&(gamemode_played != Ulcer)&&(gamemode_played != Survive)){
		printf ("	ERROR\n");		//max. #Steine auf dem Feld
		b = 0;
	} else {

		printf(" Zeile: \n Spalte: \n");
		letters_4 = get_unsigned_numeric_input_with_not_more_than_letters_4_for_splitting();
		Zeile = split_unsigned_numeric_input_with_letters_4 (letters_4, 0);
		Spalte = split_unsigned_numeric_input_with_letters_4 (letters_4, 1);

		if ((Zeile == 0)&&(Spalte == 0)){
			printf("	Sweet escape...\n");
		} else {

			if (((Zeile<1)||(Zeile>(m-2))) || ((Spalte<1)||(Spalte>n-2))){
				printf("	you made a mistake, try again: \n");

				if (Opague_o.characterization >= 1) {
					show_field (number_of_players, single_option_representives.invisible, level, Sf_permutations, Opague_o.field, Opague_o.field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
				} else {
					show_field (number_of_players, single_option_representives.invisible, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
				}
				Plus (level, Sf_permutations, m, n, geben, Field, limits_at_all, gamemode_played, information_code, number_of_players, Growth_players, Opague_o, Allocation_o, single_option_representives);
			} else {

				for (unsigned int h=Zeile-1; h<=Zeile+1; h+=1){			//Lebender in der Nähe?
					for (unsigned int k=Spalte-1; k<=Spalte+1; k+=1){
						if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
							if ((gamemode_played == Hunt)&&(geben == 1)) {
								if ((Field[0][h][k] == 1)||(Field[0][h][k] == 11)){
									a+=1;
								}
							} else if (Field[0][h][k] == geben){
								a+=1;
							}
						}
					}
				}
				if (gamemode_played == Hunt) {
					if ((a == 0) || (Field[0][Zeile][Spalte] != 0)){
						printf ("	Not possible\n");
						Plus (level, Sf_permutations, m, n, geben, Field, limits_at_all, gamemode_played, information_code, number_of_players, Growth_players, Opague_o, Allocation_o, single_option_representives);

					} else {
						if (geben == 1) {
							set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, Zeile, Spalte, 1);
						} else {
							set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, Zeile, Spalte, geben);
						}
					}
				} else if ((gamemode_played != Ulcer)&&(gamemode_played != Survive)) {
					if ((a == 0) || (Field[0][Zeile][Spalte] != 0)){
						printf ("	Not possible\n");
						Plus (level, Sf_permutations, m, n, geben, Field, limits_at_all, gamemode_played, information_code, number_of_players, Growth_players, Opague_o, Allocation_o, single_option_representives);
					} else {
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, Zeile, Spalte, geben);
					}
				} else {
					if (a == 0){
						printf ("	Not possible\n");
						Plus (level, Sf_permutations, m, n, geben, Field, limits_at_all, gamemode_played, information_code, number_of_players, Growth_players, Opague_o, Allocation_o, single_option_representives);
					} else {
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, Zeile, Spalte, geben);
					}
				}
			}
		}
	}
}

void Minus (unsigned int* level, Spielfeld Sf_permutations, unsigned int m, unsigned int n, unsigned int geben, Spielfeld Field, unsigned int gamemode_played, unsigned int* information_code, Growth_Player* Growth_players, Special_Fields Opague_o, Special_Fields Allocation_o, unsigned int number_of_players, Single_option_representives single_option_representives){	//checklist
	unsigned int Zeile, Spalte;

	Zeile = 0;
	Spalte = 0;

	printf(" Zeile: \n Spalte: \n");
	letters_4 = get_unsigned_numeric_input_with_not_more_than_letters_4_for_splitting();
	Zeile = split_unsigned_numeric_input_with_letters_4 (letters_4, 0);
	Spalte = split_unsigned_numeric_input_with_letters_4 (letters_4, 1);

	if ((Zeile == 0)&&(Spalte == 0)){
		printf("	Sweet escape...\n");
	} else {

		if (((Zeile<1)||(Zeile>(m-2))) || ((Spalte<1)||(Spalte>n-2))){
			printf("	you made a mistake, try again: \n");
			if (Opague_o.characterization >= 1) {
				show_field (number_of_players, single_option_representives.invisible, level, Sf_permutations, Opague_o.field, Opague_o.field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
			} else {
				show_field (number_of_players, single_option_representives.invisible, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
			}
			Minus (level, Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Growth_players, Opague_o, Allocation_o, number_of_players, single_option_representives);
		} else if (Field[0][Zeile][Spalte] != geben){
			printf("	you made a mistake, try again: \n");
			Minus (level, Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Growth_players, Opague_o, Allocation_o, number_of_players, single_option_representives);
		} else {
			set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, Zeile, Spalte, 0);
		}
	}
}

void Move (unsigned int* level, Spielfeld Sf_permutations, unsigned int m, unsigned int n, unsigned int geben, Spielfeld Field, unsigned int gamemode_played, unsigned int* information_code, Growth_Player* Growth_players, Special_Fields Opague_o, Special_Fields Allocation_o, unsigned int number_of_players, Single_option_representives single_option_representives){	//checklist
	unsigned int Zeile_alt, Spalte_alt, Zeile_neu, Spalte_neu;
	unsigned int a, b;
	Spielfeld temp_move;

	b = 0;

	Zeile_alt = 0;
	Spalte_alt = 0;

	Zeile_neu = 0;
	Spalte_neu = 0;

	for (unsigned int h=1; h<=(m-2); h+=1){
		for (unsigned int k=1; k<=(n-2); k+=1){
			if ((gamemode_played == Hunt)&&(geben == 1)) {
				if ((Field[0][h][k] == 1)||(Field[0][h][k] == 11)){
					if ((Field[0][h-1][k]==0)&&((h-1)>=1)){
						b+=1;
					}
					if ((Field[0][h][k-1]==0)&&((k-1)>=1)){
						b+=1;
					}
					if ((Field[0][h][k+1]==0)&&((k+1)<=(n-2))){
						b+=1;
					}
					if ((Field[0][h+1][k]==0)&&((h+1)<=(m-2))){
						b+=1;
					}
				}
			} else if (Field[0][h][k] == geben){
				if ((Field[0][h-1][k]==0)&&((h-1)>=1)){
					b+=1;
				}
				if ((Field[0][h][k-1]==0)&&((k-1)>=1)){
					b+=1;
				}
				if ((Field[0][h][k+1]==0)&&((k+1)<=(n-2))){
					b+=1;
				}
				if ((Field[0][h+1][k]==0)&&((h+1)<=(m-2))){
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

				if (Field[0][h][k]==11) {
					if ((Field[0][h-1][k]==0)&&((h-1)>=1)){
						b = 1;
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, h-1, k, 1);
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, h, k, 0);

						break;
					} else if ((Field[0][h][k-1]==0)&&((k-1)>=1)){
						b = 1;
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, h, k-1, 1);
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, h, k, 0);

						break;
					} else if ((Field[0][h][k+1]==0)&&((k+1)<=(n-2))){
						b = 1;
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, h, k+1, 1);
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, h, k, 0);

						break;
					} else if ((Field[0][h+1][k]==0)&&((h+1)<=(m-2))){
						b = 1;
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, h+1, k, 1);
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, h, k, 0);

						break;
					}
				} else if (Field[0][h][k] == geben){
					if ((Field[0][h-1][k]==0)&&((h-1)>=1)){
						b = 1;
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, h-1, k, geben);
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, h, k, 0);

						break;
					} else if ((Field[0][h][k-1]==0)&&((k-1)>=1)){
						b = 1;
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, h, k-1, geben);
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, h, k, 0);

						break;
					} else if ((Field[0][h][k+1]==0)&&((k+1)<=(n-2))){
						b = 1;
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, h, k+1, geben);
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, h, k, 0);

						break;
					} else if ((Field[0][h+1][k]==0)&&((h+1)<=(m-2))){
						b = 1;
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, h+1, k, geben);
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, h, k, 0);

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

		temp_move = Spielfeld_Create (m, n, 0);

		printf(" alte Zeile: \n alte Spalte: \n");
		letters_4 = get_unsigned_numeric_input_with_not_more_than_letters_4_for_splitting();
		Zeile_alt = split_unsigned_numeric_input_with_letters_4 (letters_4, 0);
		Spalte_alt = split_unsigned_numeric_input_with_letters_4 (letters_4, 1);

		if ((Zeile_alt == 0)&&(Spalte_alt == 0)){
			printf("	Sweet escape...\n");
		} else {

			if (((Zeile_alt<1)||(Zeile_alt>(m-2))) || ((Spalte_alt<1)||(Spalte_alt>n-2))){
				printf("	you made a mistake, try again: \n");
				if (Opague_o.characterization >= 1) {
					show_field (number_of_players, single_option_representives.invisible, level, Sf_permutations, Opague_o.field, Opague_o.field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
				} else {
					show_field (number_of_players, single_option_representives.invisible, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
				}
				Move (level, Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Growth_players, Opague_o, Allocation_o, number_of_players, single_option_representives);

			} else if ((gamemode_played == Hunt)&&(geben == 1)) {
				if ((Field[0][Zeile_alt][Spalte_alt] != 1)&&(Field[0][Zeile_alt][Spalte_alt] != 11)){
					printf("	you made a mistake, try again: \n");
					Move (level, Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Growth_players, Opague_o, Allocation_o, number_of_players, single_option_representives);
				} else {

					printf(" neue Zeile: \n neue Spalte: \n");
					letters_4 = get_unsigned_numeric_input_with_not_more_than_letters_4_for_splitting();
					Zeile_neu = split_unsigned_numeric_input_with_letters_4 (letters_4, 0);
					Spalte_neu = split_unsigned_numeric_input_with_letters_4 (letters_4, 1);

					if ((Zeile_neu == 0)&&(Spalte_neu == 0)){
						printf("	Sweet escape...\n");
					} else {

						if (((Zeile_neu<1)||(Zeile_neu>(m-2))) || ((Spalte_neu<1)||(Spalte_neu>n-2))){
							printf("	you made a mistake, try again: \n");
							if (Opague_o.characterization >= 1) {
								show_field (number_of_players, single_option_representives.invisible, level, Sf_permutations, Opague_o.field, Opague_o.field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
							} else {
								show_field (number_of_players, single_option_representives.invisible, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);		//transform Spielfeld in Spielfeld[0], übergebe nur noch personal, done
							}
							Move (level, Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Growth_players, Opague_o, Allocation_o, number_of_players, single_option_representives);

						} else if (Field[0][Zeile_alt][Spalte_alt] == 1) {
							set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, temp_move, 0, Zeile_alt, Spalte_alt, 1);
							a = 0;								//Ursprung in der Nähe?
							if ((temp_move[0][Zeile_neu-1][Spalte_neu]==1)||(temp_move[0][Zeile_neu][Spalte_neu-1]==1)||(temp_move[0][Zeile_neu][Spalte_neu+1]==1)||(temp_move[0][Zeile_neu+1][Spalte_neu]==1)){
								a = 1;
							}
							if (a == 0){
								printf("	you made a mistake, try again: \n");
								Move (level, Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Growth_players, Opague_o, Allocation_o, number_of_players, single_option_representives);
							} else if (Field[0][Zeile_neu][Spalte_neu] != 0){
								printf("	you made a mistake, try again: \n");
								Move (level, Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Growth_players, Opague_o, Allocation_o, number_of_players, single_option_representives);
							} else {
								set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, Zeile_neu, Spalte_neu, 1);
								set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, Zeile_alt, Spalte_alt, 0);
							}
						} else if (Field[0][Zeile_alt][Spalte_alt] == 11) {
							set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, temp_move, 0, Zeile_alt, Spalte_alt, 11);
							a = 0;								//Ursprung in der Nähe?
							if ((temp_move[0][Zeile_neu-1][Spalte_neu]==11)||(temp_move[0][Zeile_neu][Spalte_neu-1]==11)||(temp_move[0][Zeile_neu][Spalte_neu+1]==11)||(temp_move[0][Zeile_neu+1][Spalte_neu]==11)){
								a = 1;
							}
							if (a == 0){
								printf("	you made a mistake, try again: \n");
								Move (level, Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Growth_players, Opague_o, Allocation_o, number_of_players, single_option_representives);
							} else if (Field[0][Zeile_neu][Spalte_neu] != 0){
								printf("	you made a mistake, try again: \n");
								Move (level, Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Growth_players, Opague_o, Allocation_o, number_of_players, single_option_representives);
							} else {
								set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, Zeile_neu, Spalte_neu, 11);
								set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, Zeile_alt, Spalte_alt, 0);
							}
						}
					}
				}
			} else if ((gamemode_played != Hunt)||(geben != 1)){
				if (Field[0][Zeile_alt][Spalte_alt] != geben){
					printf("	you made a mistake, try again: \n");
					Move (level, Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Growth_players, Opague_o, Allocation_o, number_of_players, single_option_representives);
				} else {

					printf(" neue Zeile: \n neue Spalte: \n");
					letters_4 = get_unsigned_numeric_input_with_not_more_than_letters_4_for_splitting();
					Zeile_neu = split_unsigned_numeric_input_with_letters_4 (letters_4, 0);
					Spalte_neu = split_unsigned_numeric_input_with_letters_4 (letters_4, 1);

					if ((Zeile_neu == 0)&&(Spalte_neu == 0)){
						printf("	Sweet escape...\n");
					} else {

						if (((Zeile_neu<1)||(Zeile_neu>(m-2))) || ((Spalte_neu<1)||(Spalte_neu>n-2))){
							printf("	you made a mistake, try again: \n");
							if (Opague_o.characterization >= 1) {
								show_field (number_of_players, single_option_representives.invisible, level, Sf_permutations, Opague_o.field, Opague_o.field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
							} else {
								show_field (number_of_players, single_option_representives.invisible, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
							}
							Move (level, Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Growth_players, Opague_o, Allocation_o, number_of_players, single_option_representives);

						} else {
							set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, temp_move, 0, Zeile_alt, Spalte_alt, geben);

							a = 0;								//Ursprung in der Nähe?
							if ((temp_move[0][Zeile_neu-1][Spalte_neu]==geben)||(temp_move[0][Zeile_neu][Spalte_neu-1]==geben)||(temp_move[0][Zeile_neu][Spalte_neu+1]==geben)||(temp_move[0][Zeile_neu+1][Spalte_neu]==geben)){
								a = 1;
							}

							if (a == 0){
								printf("	you made a mistake, try again: \n");
								Move (level, Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Growth_players, Opague_o, Allocation_o, number_of_players, single_option_representives);
							} else if (Field[0][Zeile_neu][Spalte_neu] != 0){
								printf("	you made a mistake, try again: \n");
								Move (level, Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Growth_players, Opague_o, Allocation_o, number_of_players, single_option_representives);
							} else {
								set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, Zeile_neu, Spalte_neu, geben);
								set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, Zeile_alt, Spalte_alt, 0);
							}
						}

					}
				}
			}
		}

		Spielfeld_Destroy (temp_move, m, 0);
	}
}

void Change (unsigned int* level, Spielfeld Sf_permutations, unsigned int m, unsigned int n, unsigned int geben, Spielfeld Field, unsigned int gamemode_played, unsigned int* information_code, Growth_Player* Growth_players, Special_Fields Opague_o, unsigned int* position, Special_Fields Allocation_o, unsigned int number_of_players, Single_option_representives single_option_representives){	//checklist
	unsigned int geben_change, a, b;
	unsigned int eigene_Zeile, fremde_Zeile, eigene_Spalte, fremde_Spalte, heart_Zeile, heart_Spalte, normal_Zeile, normal_Spalte;

	// printf("gamemode_played = %u \n", gamemode_played);	//test
	
	b = 0;
	eigene_Zeile = 0;
	fremde_Zeile = 0;
	eigene_Spalte = 0;
	fremde_Spalte = 0;
	heart_Zeile = 0;
	heart_Spalte = 0;
	normal_Zeile = 0;
	normal_Spalte = 0;

	if ((gamemode_played == Hunt)&&(geben != 1)) {
		geben_change = 1;
	} else {
		geben_change = 0;
	}

	if ((gamemode_played == Hunt)&&(geben == 1)) {
		for (unsigned int h=1; h<=(m-2); h+=1){
			for (unsigned int k=1; k<=(n-2); k+=1){
				if (Field[0][h][k] == 11){
					if (Field[0][h-1][k]==1){
						b+=1;
					}
					if (Field[0][h][k-1]==1){
						b+=1;
					}
					if (Field[0][h][k+1]==1){
						b+=1;
					}
					if (Field[0][h+1][k]==1){
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
					if (Field[0][h][k] == 11){
						if (Field[0][h-1][k]==1){
							b = 1;
							set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, h-1, k, 11);
							set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, h, k, 1);
							break;
						} else if (Field[0][h][k-1]==1){
							b = 1;
							set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, h, k-1, 11);
							set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, h, k, 1);
							break;
						} else if (Field[0][h][k+1]==1){
							b = 1;
							set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, h, k+1, 11);
							set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, h, k, 1);
							break;
						} else if (Field[0][h+1][k]==1){
							b = 1;
							set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, h+1, k, 11);
							set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, h, k, 1);
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
					if (Field[0][h][k] == 11) {
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
			if ((Field[0][heart_Zeile-1][heart_Spalte]==1)||(Field[0][heart_Zeile][heart_Spalte-1]==1)||(Field[0][heart_Zeile][heart_Spalte+1]==1)||(Field[0][heart_Zeile+1][heart_Spalte]==1)){
				a = 1;
			}

			if (a == 0){
				printf("	it isn't possible, try a move: \n");
				Move (level, Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Growth_players, Opague_o, Allocation_o, number_of_players, single_option_representives);
			} else {

				printf(" normale Zeile: \n normale Spalte: \n");
				letters_4 = get_unsigned_numeric_input_with_not_more_than_letters_4_for_splitting();
				normal_Zeile = split_unsigned_numeric_input_with_letters_4 (letters_4, 0);
				normal_Spalte = split_unsigned_numeric_input_with_letters_4 (letters_4, 1);

				if ((normal_Zeile == 0)&&(normal_Spalte == 0)){
					printf("	Sweet escape...\n");
				} else {

					if (((normal_Zeile<1)||(normal_Zeile>(m-2))) || ((normal_Spalte<1)||(normal_Spalte>n-2))){
						printf("	you made a mistake, try again: \n");
						if (Opague_o.characterization >= 1) {
							show_field (number_of_players, single_option_representives.invisible, level, Sf_permutations, Opague_o.field, Opague_o.field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
						} else {
							show_field (number_of_players, single_option_representives.invisible, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
						}
						Change (level, Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Growth_players, Opague_o, position, Allocation_o, number_of_players, single_option_representives);

					} else if ((Field[0][normal_Zeile][normal_Spalte] != 1)||((abs(normal_Spalte - heart_Spalte) + abs(normal_Zeile - heart_Zeile)) != 1)){
						printf("	you made a mistake, try again: \n");
						Change (level, Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Growth_players, Opague_o, position, Allocation_o, number_of_players, single_option_representives);
					} else if (((Field[0][normal_Zeile+1][normal_Spalte]%10) > 1)||((Field[0][normal_Zeile-1][normal_Spalte]%10) > 1)||((Field[0][normal_Zeile][normal_Spalte+1]%10) > 1)||((Field[0][normal_Zeile][normal_Spalte-1]%10) > 1)) {
						printf("	it isn't possible, try again: \n");
						Change (level, Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Growth_players, Opague_o, position, Allocation_o, number_of_players, single_option_representives);
					} else {
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, normal_Zeile, normal_Spalte, 11);
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, heart_Zeile, heart_Spalte, 1);
					}
				}
			}

		}
	} else if ((gamemode_played == Hunt)&&(geben != 1)) {

		for (unsigned int h=1; h<=(m-2); h+=1){
			for (unsigned int k=1; k<=(n-2); k+=1){
				if (Field[0][h][k] == geben){
					for (unsigned int u=h-1; u<=h+1; u++){
						for (unsigned int o=k-1; o<=k+1; o++){
							if ((u+o)%2 == (h+k+1)%2) {
								if (Field[0][u][o] == geben_change){
									b+=1;
								}
							}
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
	} else if (gamemode_played == Contact) {

		for (unsigned int h=1; h<=(m-2); h+=1){
			for (unsigned int k=1; k<=(n-2); k+=1){
				if (Field[0][h][k] == geben){
					for (unsigned int u=(h-1); u<=(h+1); u+=1){
						for (unsigned int o=(k-1); o<=(k+1); o+=1){
							if ((Field[0][u][o] != 0)&&(Field[0][u][o] != geben)){
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

	} else if (gamemode_played == Rain) {
		for (unsigned int h=1; h<=(m-2); h+=1){
			for (unsigned int k=1; k<=(n-2); k+=1){
				if (Field[0][h][k] == geben){
					for (unsigned int u=h-1; u<=h+1; u++){
						for (unsigned int o=k-1; o<=k+1; o++){
							if ((u+o)%2 == (h+k+1)%2) {
								if (Field[0][u][o] == Raindrop){
									b+=1;
								}
							}
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

	} else if (gamemode_played == Collect) {
		for (unsigned int h=1; h<=(m-2); h+=1){
			for (unsigned int k=1; k<=(n-2); k+=1){
				if (Field[0][h][k] == geben){
					for (unsigned int u=h-1; u<=h+1; u++){
						for (unsigned int o=k-1; o<=k+1; o++){
							if ((u+o)%2 == (h+k+1)%2) {
								if ((Field[0][u][o] != 0)&&(Field[0][u][o] != geben)&&(Field[0][u][o] != To_collect)){
									b+=1;
								}
							}
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
	} else if (gamemode_played == Race) {
		for (unsigned int h=1; h<=(m-2); h+=1){
			for (unsigned int k=1; k<=(n-2); k+=1){
				if (Field[0][h][k] == geben){
					for (unsigned int u=h-1; u<=h+1; u++){
						for (unsigned int o=k-1; o<=k+1; o++){
							if ((u+o)%2 == (h+k+1)%2) {
								if ((Field[0][u][o] != 0)&&(Field[0][u][o] != geben)&&(Field[0][u][o] != Wall)&&(Field[0][u][o] != Wall_at_the_end)){
									b+=1;
								}
							}
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
	} else if (gamemode_played == Quidditch) {
		for (unsigned int h=1; h<=(m-2); h+=1){
			for (unsigned int k=1; k<=(n-2); k+=1){
				if (Field[0][h][k] == geben){
					for (unsigned int u=h-1; u<=h+1; u++){
						for (unsigned int o=k-1; o<=k+1; o++){
							if ((u+o)%2 == (h+k+1)%2) {
								if ((Field[0][u][o] != 0)&&(Field[0][u][o] != geben)&&(Field[0][u][o] != Torring_1)&&(Field[0][u][o] != Torring_2)){
									b+=1;
								}
							}
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
	} else {	//nur Berechnung, kein Change direkt, mehr-gamemode_played
		for (unsigned int h=1; h<=(m-2); h+=1){
			for (unsigned int k=1; k<=(n-2); k+=1){
				if (Field[0][h][k] == geben){
					for (unsigned int u=h-1; u<=h+1; u++){
						for (unsigned int o=k-1; o<=k+1; o++){
							if ((u+o)%2 == (h+k+1)%2) {
								if ((Field[0][u][o] != 0)&&(Field[0][u][o] != geben)){
									b+=1;
								}
							}
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
	}

	if (b == 1){
		b = 0;

		if ((gamemode_played == Hunt)&&(geben != 1)) {
			for (unsigned int h=1; h<=(m-2); h+=1){
				for (unsigned int k=1; k<=(n-2); k+=1){
					if (Field[0][h][k] == geben){
						for (unsigned int u=h-1; u<=h+1; u++){
							for (unsigned int o=k-1; o<=k+1; o++){
								if ((u+o)%2 == (h+k+1)%2) {
									if (Field[0][u][o] == geben_change){
										b = 1;
										set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, h, k, geben_change);
										set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, u, o, geben);
										break;
									}
								}
							}
						}
					}
				}
				if (b == 1){
					break;
				}
			}
		} else if (gamemode_played == Contact) {
			for (unsigned int h=1; h<=(m-2); h+=1){
				for (unsigned int k=1; k<=(n-2); k+=1){
					if (Field[0][h][k] == geben){
						for (unsigned int u=(h-1); u<=(h+1); u+=1){
							for (unsigned int o=(k-1); o<=(k+1); o+=1){
								if ((Field[0][u][o] != geben)&&(Field[0][u][o] != 0)&&(Field[0][u][o] <= number_of_players)){
									b = 1;
									set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, h, k, Field[0][u][o]);
									set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, u, o, geben);
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
		} else if (gamemode_played == Rain) {
			for (unsigned int h=1; h<=(m-2); h+=1){
				for (unsigned int k=1; k<=(n-2); k+=1){
					if (Field[0][h][k] == geben){
						for (unsigned int u=h-1; u<=h+1; u++){
							for (unsigned int o=k-1; o<=k+1; o++){
								if ((u+o)%2 == (h+k+1)%2) {
									if (Field[0][u][o] == Raindrop){
										b = 1;
										set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, h, k, Raindrop);
										set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, u, o, geben);
										break;
									}
								}
							}
						}
					}
				}
				if (b == 1){
					break;
				}
			}
		} else if (gamemode_played == Quidditch) {
			for (unsigned int h=1; h<=(m-2); h+=1){
				for (unsigned int k=1; k<=(n-2); k+=1){
					if (Field[0][h][k] == geben){
						for (unsigned int u=h-1; u<=h+1; u++){
							for (unsigned int o=k-1; o<=k+1; o++){
								if ((u+o)%2 == (h+k+1)%2) {
									if ((Field[0][u][o] != 0)&&(Field[0][u][o] != geben)&&(Field[0][u][o] != Torring_1)&&(Field[0][u][o] != Torring_2)){
										b = 1;
										set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, h, k, Field[0][u][o]);
										set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, u, o, geben);
										break;
									}
								}
							}
						}
					}
				}
				if (b == 1){
					break;
				}
			}
		} else {	//mehr-gamemode_played
			for (unsigned int h=1; h<=(m-2); h+=1){
				for (unsigned int k=1; k<=(n-2); k+=1){
					if (Field[0][h][k] == geben){
						for (unsigned int u=h-1; u<=h+1; u++){
							for (unsigned int o=k-1; o<=k+1; o++){
								if ((u+o)%2 == (h+k+1)%2) {
									if ((Field[0][u][o] != 0)&&(Field[0][u][o] != geben)){
										set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, h, k, Field[0][u][o]);
										set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, u, o, geben);
										b = 1;
									}

									if (Field[0][h][k] == Dynamic_ball) {	//object instead of geben, nach dem change
										position[Vertikal] = h;
										position[Horizontal] = k;
									}
								}
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
		}

	} else if (b == 0){
		printf("	No match found, use 100 to correct your mistake \n");
	} else {

		printf(" eigene Zeile: \n eigene Spalte: \n");
		letters_4 = get_unsigned_numeric_input_with_not_more_than_letters_4_for_splitting();
		eigene_Zeile = split_unsigned_numeric_input_with_letters_4 (letters_4, 0);
		eigene_Spalte = split_unsigned_numeric_input_with_letters_4 (letters_4, 1);

		if ((eigene_Zeile == 0)&&(eigene_Spalte == 0)){
			printf("	Sweet escape...\n");
		} else {

			if (((eigene_Zeile<1)||(eigene_Zeile>(m-2))) || ((eigene_Spalte<1)||(eigene_Spalte>n-2))){
				printf("	you made a mistake, try again: \n");
				if (Opague_o.characterization >= 1) {
					show_field (number_of_players, single_option_representives.invisible, level, Sf_permutations, Opague_o.field, Opague_o.field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
				} else {
					show_field (number_of_players, single_option_representives.invisible, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
				}
				Change (level, Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Growth_players, Opague_o, position, Allocation_o, number_of_players, single_option_representives);

			} else if (Field[0][eigene_Zeile][eigene_Spalte] != geben){
				printf("	you made a mistake, try again: \n");
				Change (level, Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Growth_players, Opague_o, position, Allocation_o, number_of_players, single_option_representives);
			} else {

				a = 0;								//Feind in der Nähe?
				if (gamemode_played == Hunt) {
					if ((Field[0][eigene_Zeile-1][eigene_Spalte]==geben_change)||(Field[0][eigene_Zeile][eigene_Spalte-1]==geben_change)||(Field[0][eigene_Zeile][eigene_Spalte+1]==geben_change)||(Field[0][eigene_Zeile+1][eigene_Spalte]==geben_change)){
						a = 1;
					}
				} else if (gamemode_played == Contact) {
					for (unsigned int h=eigene_Zeile-1; h<=eigene_Zeile+1; h+=1){
						for (unsigned int k=eigene_Spalte-1; k<=eigene_Spalte+1; k+=1){
							if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
								if ((Field[0][h][k] != geben)&&(Field[0][h][k] != 0)&&(Field[0][h][k] <= number_of_players)){
									a = 1;
								}
							}
						}
					}
				} else if (gamemode_played == Rain){
					if ((Field[0][eigene_Zeile-1][eigene_Spalte]==Raindrop)||(Field[0][eigene_Zeile][eigene_Spalte-1]==Raindrop)||(Field[0][eigene_Zeile][eigene_Spalte+1]==Raindrop)||(Field[0][eigene_Zeile+1][eigene_Spalte]==Raindrop)){
						a = 1;
					}
				} else if (gamemode_played == Race){
					if (((Field[0][eigene_Zeile-1][eigene_Spalte]!=geben)&&(Field[0][eigene_Zeile-1][eigene_Spalte]!=0)&&(Field[0][eigene_Zeile-1][eigene_Spalte]!=Wall)&&(Field[0][eigene_Zeile-1][eigene_Spalte]!=Wall_at_the_end))||((Field[0][eigene_Zeile][eigene_Spalte-1]!=geben)&&(Field[0][eigene_Zeile][eigene_Spalte-1]!=0)&&(Field[0][eigene_Zeile][eigene_Spalte-1]!=Wall)&&(Field[0][eigene_Zeile][eigene_Spalte-1]!=Wall_at_the_end))||((Field[0][eigene_Zeile][eigene_Spalte+1]!=geben)&&(Field[0][eigene_Zeile][eigene_Spalte+1]!=0)&&(Field[0][eigene_Zeile][eigene_Spalte+1]!=Wall)&&(Field[0][eigene_Zeile][eigene_Spalte+1]!=Wall_at_the_end))||((Field[0][eigene_Zeile+1][eigene_Spalte]!=geben)&&(Field[0][eigene_Zeile+1][eigene_Spalte]!=0)&&(Field[0][eigene_Zeile+1][eigene_Spalte]!=Wall)&&(Field[0][eigene_Zeile+1][eigene_Spalte]!=Wall_at_the_end))){
						a = 1;
					}
				} else if (gamemode_played == Quidditch){
					if (((Field[0][eigene_Zeile-1][eigene_Spalte]!=geben)&&(Field[0][eigene_Zeile-1][eigene_Spalte]!=0)&&(Field[0][eigene_Zeile-1][eigene_Spalte]!=Torring_1)&&(Field[0][eigene_Zeile-1][eigene_Spalte]!=Torring_2))||((Field[0][eigene_Zeile][eigene_Spalte-1]!=geben)&&(Field[0][eigene_Zeile][eigene_Spalte-1]!=0)&&(Field[0][eigene_Zeile][eigene_Spalte-1]!=Torring_1)&&(Field[0][eigene_Zeile][eigene_Spalte-1]!=Torring_2))||((Field[0][eigene_Zeile][eigene_Spalte+1]!=geben)&&(Field[0][eigene_Zeile][eigene_Spalte+1]!=0)&&(Field[0][eigene_Zeile][eigene_Spalte+1]!=Torring_1)&&(Field[0][eigene_Zeile][eigene_Spalte+1]!=Torring_2))||((Field[0][eigene_Zeile+1][eigene_Spalte]!=geben)&&(Field[0][eigene_Zeile+1][eigene_Spalte]!=0)&&(Field[0][eigene_Zeile+1][eigene_Spalte]!=Torring_1)&&(Field[0][eigene_Zeile+1][eigene_Spalte]!=Torring_2))){
						a = 1;
					}
				} else {	//mehr-gamemode_played
					if (((Field[0][eigene_Zeile-1][eigene_Spalte]!=geben)&&(Field[0][eigene_Zeile-1][eigene_Spalte]!=0))||((Field[0][eigene_Zeile][eigene_Spalte-1]!=geben)&&(Field[0][eigene_Zeile][eigene_Spalte-1]!=0))||((Field[0][eigene_Zeile][eigene_Spalte+1]!=geben)&&(Field[0][eigene_Zeile][eigene_Spalte+1]!=0))||((Field[0][eigene_Zeile+1][eigene_Spalte]!=geben)&&(Field[0][eigene_Zeile+1][eigene_Spalte]!=0))){
						a = 1;
					}
				}

				if (a == 0){
					printf("	you made a mistake, try again: \n");
					Change (level, Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Growth_players, Opague_o, position, Allocation_o, number_of_players, single_option_representives);
				} else {

					printf(" fremde Zeile: \n fremde Spalte: \n");
					letters_4 = get_unsigned_numeric_input_with_not_more_than_letters_4_for_splitting();
					fremde_Zeile = split_unsigned_numeric_input_with_letters_4 (letters_4, 0);
					fremde_Spalte = split_unsigned_numeric_input_with_letters_4 (letters_4, 1);

					if ((fremde_Zeile == 0)&&(fremde_Spalte == 0)){
						printf("	Sweet escape...\n");
					} else {

						if (((fremde_Zeile<1)||(fremde_Zeile>(m-2))) || ((fremde_Spalte<1)||(fremde_Spalte>n-2))){
							printf("	you made a mistake, try again: \n");
							if (Opague_o.characterization >= 1) {
								show_field (number_of_players, single_option_representives.invisible, level, Sf_permutations, Opague_o.field, Opague_o.field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
							} else {
								show_field (number_of_players, single_option_representives.invisible, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
							}
							Change (level, Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Growth_players, Opague_o, position, Allocation_o, number_of_players, single_option_representives);

						} else if (gamemode_played == Hunt) {
							if ((Field[0][fremde_Zeile][fremde_Spalte] != geben_change)||(abs(fremde_Spalte-eigene_Spalte)+abs(fremde_Zeile-eigene_Zeile)!= 1)){
								printf("	you made a mistake, try again: \n");
								Change (level, Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Growth_players, Opague_o, position, Allocation_o, number_of_players, single_option_representives);
							} else {
								set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, fremde_Zeile, fremde_Spalte, geben);
								set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, eigene_Zeile, eigene_Spalte, geben_change);
							}
						} else if (gamemode_played == Contact) {
							if ((Field[0][fremde_Zeile][fremde_Spalte] > number_of_players)||(Field[0][fremde_Zeile][fremde_Spalte] == 0)||(Field[0][fremde_Zeile][fremde_Spalte] == geben)||(abs(fremde_Spalte-eigene_Spalte)>1)||(abs(fremde_Zeile-eigene_Zeile)>1)){
								printf("	you made a mistake, try again: \n");
								Change (level, Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Growth_players, Opague_o, position, Allocation_o, number_of_players, single_option_representives);
							} else {
								set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, eigene_Zeile, eigene_Spalte, Field[0][fremde_Zeile][fremde_Spalte]);
								set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, fremde_Zeile, fremde_Spalte, geben);
							}
						} else if (gamemode_played == Rain) {
							if ((Field[0][fremde_Zeile][fremde_Spalte] != Raindrop)||(abs(fremde_Spalte-eigene_Spalte)+abs(fremde_Zeile-eigene_Zeile)!= 1)){
								printf("	you made a mistake, try again: \n");
								Change (level, Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Growth_players, Opague_o, position, Allocation_o, number_of_players, single_option_representives);
							} else {
								set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, fremde_Zeile, fremde_Spalte, geben);
								set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, eigene_Zeile, eigene_Spalte, Raindrop);
							}
						} else if (gamemode_played == Race) {
							if ((Field[0][fremde_Zeile][fremde_Spalte] > number_of_players)||(Field[0][fremde_Zeile][fremde_Spalte] == 0)||(Field[0][fremde_Zeile][fremde_Spalte] == geben)||(Field[0][fremde_Zeile][fremde_Spalte] == Wall)||(Field[0][fremde_Zeile][fremde_Spalte] == Wall_at_the_end)||(abs(fremde_Spalte-eigene_Spalte)+abs(fremde_Zeile-eigene_Zeile)!= 1)){
								printf("	you made a mistake, try again: \n");
								Change (level, Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Growth_players, Opague_o, position, Allocation_o, number_of_players, single_option_representives);
							} else {
								set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, eigene_Zeile, eigene_Spalte, Field[0][fremde_Zeile][fremde_Spalte]);
								set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, fremde_Zeile, fremde_Spalte, geben);
							}
						} else if (gamemode_played == Quidditch) {
							if ((Field[0][fremde_Zeile][fremde_Spalte] == 0)||(Field[0][fremde_Zeile][fremde_Spalte] == geben)||(Field[0][fremde_Zeile][fremde_Spalte] == Torring_1)||(Field[0][fremde_Zeile][fremde_Spalte] == Torring_2)||(abs(fremde_Spalte-eigene_Spalte)+abs(fremde_Zeile-eigene_Zeile)!= 1)){
								printf("	you made a mistake, try again: \n");
								Change (level, Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Growth_players, Opague_o, position, Allocation_o, number_of_players, single_option_representives);
							} else {
								set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, eigene_Zeile, eigene_Spalte, Field[0][fremde_Zeile][fremde_Spalte]);
								set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, fremde_Zeile, fremde_Spalte, geben);
							}
						} else {
							if ((Field[0][fremde_Zeile][fremde_Spalte] > number_of_players)||(Field[0][fremde_Zeile][fremde_Spalte] == 0)||(Field[0][fremde_Zeile][fremde_Spalte] == geben)||(abs(fremde_Spalte-eigene_Spalte)+abs(fremde_Zeile-eigene_Zeile)!= 1)){
								printf("	you made a mistake, try again: \n");
								Change (level, Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Growth_players, Opague_o, position, Allocation_o, number_of_players, single_option_representives);
							} else {
								set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, eigene_Zeile, eigene_Spalte, Field[0][fremde_Zeile][fremde_Spalte]);
								set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, fremde_Zeile, fremde_Spalte, geben);
							}

							if (Field[0][eigene_Zeile][eigene_Spalte] == Dynamic_ball) {	//object instead of geben
								position[Vertikal] = eigene_Zeile;
								position[Horizontal] = eigene_Spalte;
							}
						}
					}

				}
			}
		}
	}
}

void Destroy (unsigned int* level, Spielfeld Sf_permutations, unsigned int m, unsigned int n, unsigned int geben, Spielfeld Field, unsigned int gamemode_played, unsigned int* information_code, Growth_Player* Growth_players, Special_Fields Opague_o, Special_Fields Allocation_o, unsigned int number_of_players, Single_option_representives single_option_representives){	//checklist
	
	unsigned int geben_destroy, a, b;
	unsigned int fremde_Zeile, fremde_Spalte;

	fremde_Zeile = 0;
	fremde_Spalte = 0;

	if ((gamemode_played == Hunt)&&(geben != 1)) {
		geben_destroy = 1;
	} else {
		geben_destroy = 0;
	}

	if ((gamemode_played == Hunt)&&(geben == 1)) {
		printf(" fremde Zeile: \n fremde Spalte: \n");
		letters_4 = get_unsigned_numeric_input_with_not_more_than_letters_4_for_splitting();
		fremde_Zeile = split_unsigned_numeric_input_with_letters_4 (letters_4, 0);
		fremde_Spalte = split_unsigned_numeric_input_with_letters_4 (letters_4, 1);

		if ((fremde_Zeile == 0)&&(fremde_Spalte == 0)){
			printf("	Sweet escape...\n");
		} else {

			if ((Field[0][fremde_Zeile][fremde_Spalte] == 0)||(Field[0][fremde_Zeile][fremde_Spalte] == 1)||(Field[0][fremde_Zeile][fremde_Spalte] == 11)) {
				printf("	you made a mistake, try again: \n");
				Destroy (level, Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Growth_players, Opague_o, Allocation_o, number_of_players, single_option_representives);
			} else {
				set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, fremde_Zeile, fremde_Spalte, 0);
			}
		}
	} else if ((gamemode_played != Hunt)||(geben != 1)) {

		b = 0;
		if (gamemode_played == Hunt) {
			for (unsigned int h=1; h<=(m-2); h+=1){
				for (unsigned int k=1; k<=(n-2); k+=1){
					if (Field[0][h][k] == geben){
						for (unsigned int u=(h-1); u<=(h+1); u+=1){
							for (unsigned int o=(k-1); o<=(k+1); o+=1){
								if (((u+o)%2 == (h+k+1)%2)&&(Field[0][u][o]==geben_destroy)) {
									b+=1;
								}
							}
						}
					}
				}
			}
		} else if (gamemode_played == Contact) {
			for (unsigned int h=1; h<=(m-2); h+=1){
				for (unsigned int k=1; k<=(n-2); k+=1){
					if (Field[0][h][k] == geben){
						for (unsigned int u=(h-1); u<=(h+1); u+=1){
							for (unsigned int o=(k-1); o<=(k+1); o+=1){
								if ((Field[0][u][o] != geben)&&(Field[0][u][o] != 0)){
									b+=1;
								}
							}
						}
					}
				}
			}
		} else if (gamemode_played == Collect) {
			for (unsigned int h=1; h<=(m-2); h+=1){
				for (unsigned int k=1; k<=(n-2); k+=1){
					if (Field[0][h][k] == geben){
						for (unsigned int u=(h-1); u<=(h+1); u+=1){
							for (unsigned int o=(k-1); o<=(k+1); o+=1){
								if ((Field[0][u][o] != geben)&&(Field[0][u][o] != 0)&&(Field[0][u][o] != To_collect)){
									b+=1;
								}
							}
						}
					}
				}
			}
		} else if (gamemode_played == Fall) {
			for (unsigned int h=1; h<=(m-2); h+=1){
				for (unsigned int k=1; k<=(n-2); k+=1){
					if (Field[0][h][k] == geben){
						for (unsigned int u=(h-1); u<=(h+1); u+=1){
							for (unsigned int o=(k-1); o<=(k+1); o+=1){
								if ((Field[0][u][o] != geben)&&(Field[0][u][o] != 0)&&(Field[0][u][o] != Fall_ball)){
									b+=1;
								}
							}
						}
					}
				}
			}
		} else if (gamemode_played == Race) {
			for (unsigned int h=1; h<=(m-2); h+=1){
				for (unsigned int k=1; k<=(n-2); k+=1){
					if (Field[0][h][k] == geben){
						for (unsigned int u=(h-1); u<=(h+1); u+=1){
							for (unsigned int o=(k-1); o<=(k+1); o+=1){
								if ((Field[0][u][o] != geben)&&(Field[0][u][o] != 0)&&(Field[0][u][o] != Wall)&&(Field[0][u][o] != Wall_at_the_end)){
									b+=1;
								}
							}
						}
					}
				}
			}
		} else if (gamemode_played == Rain) {
			for (unsigned int h=1; h<=(m-4); h+=1){
				for (unsigned int k=1; k<=(n-2); k+=1){
					if ((Field[0][h][k] != geben)&&(Field[0][h][k] != 0)){
						b+=1;
					}
				}
			}
		} else if (gamemode_played == Ulcer) {
			for (unsigned int h=1; h<=(m-2); h+=1){
				for (unsigned int k=1; k<=(n-2); k+=1){
					if (Field[0][h][k] == geben){
						for (unsigned int u=(h-1); u<=(h+1); u+=1){
							for (unsigned int o=(k-1); o<=(k+1); o+=1){
								if ((u+o)%2 == (h+k+1)%2) {
									if ((Field[0][u][o] != geben)&&(Field[0][u][o] != 0)&&(Field[0][u][o] != 1)){
										b+=1;
									}
								}
							}
						}
					}
				}
			}
		} else if (gamemode_played == Dynamic) {
			for (unsigned int h=1; h<=(m-2); h+=1){
				for (unsigned int k=1; k<=(n-2); k+=1){
					if (Field[0][h][k] == geben){
						for (unsigned int u=(h-1); u<=(h+1); u+=1){
							for (unsigned int o=(k-1); o<=(k+1); o+=1){
								if ((u+o)%2 == (h+k+1)%2) {
									if ((Field[0][u][o] != geben)&&(Field[0][u][o] != 0)&&(Field[0][u][o] != Dynamic_ball)){
										b+=1;
									}
								}
							}
						}
					}
				}
			}
		} else if (gamemode_played == Quidditch) {
			for (unsigned int h=1; h<=(m-2); h+=1){
				for (unsigned int k=1; k<=(n-2); k+=1){
					if (Field[0][h][k] == geben){
						for (unsigned int u=(h-1); u<=(h+1); u+=1){
							for (unsigned int o=(k-1); o<=(k+1); o+=1){
								if ((u+o)%2 == (h+k+1)%2) {
									if (Field[0][u][o] == geben%2 +1){
										b+=1;
									}
								}
							}
						}
					}
				}
			}
		} else {
			for (unsigned int h=1; h<=(m-2); h+=1){
				for (unsigned int k=1; k<=(n-2); k+=1){
					if (Field[0][h][k] == geben){
						for (unsigned int u=(h-1); u<=(h+1); u+=1){
							for (unsigned int o=(k-1); o<=(k+1); o+=1){
								if ((u+o)%2 == (h+k+1)%2) {
									if ((Field[0][u][o] != geben)&&(Field[0][u][o] != 0)){
										b+=1;
									}
								}
							}
						}
					}
				}
			}
		}

		if (b == 1){
			b = 0;

			if (gamemode_played == Hunt) {
				for (unsigned int h=1; h<=(m-2); h+=1){
					for (unsigned int k=1; k<=(n-2); k+=1){
						if (Field[0][h][k] == geben){
							for (unsigned int u=(h-1); u<=(h+1); u+=1){
								for (unsigned int o=(k-1); o<=(k+1); o+=1){
									if ((u+o)%2 == (h+k+1)%2) {
										if (Field[0][u][o]==geben_destroy){
											b = 1;
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, u, o, 0);
											break;
										}
									}
								}
							}
						}
					}
					if (b == 1){
						break;
					}
				}
			} else if (gamemode_played == Contact) {
				for (unsigned int h=1; h<=(m-2); h+=1){
					for (unsigned int k=1; k<=(n-2); k+=1){
						if (Field[0][h][k] == geben){
							for (unsigned int u=(h-1); u<=(h+1); u+=1){
								for (unsigned int o=(k-1); o<=(k+1); o+=1){
									if ((Field[0][u][o] != geben)&&(Field[0][u][o] != 0)){
										b = 1;
										set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, u, o, 0);
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
			} else if (gamemode_played == Collect) {
				for (unsigned int h=1; h<=(m-2); h+=1){
					for (unsigned int k=1; k<=(n-2); k+=1){
						if (Field[0][h][k] == geben){
							for (unsigned int u=(h-1); u<=(h+1); u+=1){
								for (unsigned int o=(k-1); o<=(k+1); o+=1){
									if ((u+o)%2 == (h+k+1)%2) {
										if ((Field[0][u][o] != geben)&&(Field[0][u][o] != 0)&&(Field[0][u][o] != To_collect)){
											b = 1;
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, u, o, 0);
											break;
										}
									}
								}
							}
						}
					}
					if (b == 1){
						break;
					}
				}
			} else if (gamemode_played == Fall) {
				for (unsigned int h=1; h<=(m-2); h+=1){
					for (unsigned int k=1; k<=(n-2); k+=1){
						if (Field[0][h][k] == geben){
							for (unsigned int u=(h-1); u<=(h+1); u+=1){
								for (unsigned int o=(k-1); o<=(k+1); o+=1){
									if ((u+o)%2 == (h+k+1)%2) {
										if ((Field[0][u][o] != geben)&&(Field[0][u][o] != 0)&&(Field[0][u][o] != Fall_ball)){
											b = 1;
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, u, o, 0);
											break;
										}
									}
								}
							}
						}
					}
					if (b == 1){
						break;
					}
				}
			} else if (gamemode_played == Race) {
				for (unsigned int h=1; h<=(m-2); h+=1){
					for (unsigned int k=1; k<=(n-2); k+=1){
						if (Field[0][h][k] == geben){
							for (unsigned int u=(h-1); u<=(h+1); u+=1){
								for (unsigned int o=(k-1); o<=(k+1); o+=1){
									if ((u+o)%2 == (h+k+1)%2) {
										if ((Field[0][u][o] != geben)&&(Field[0][u][o] != 0)&&(Field[0][u][o] != Wall)&&(Field[0][u][o] != Wall_at_the_end)){
											b = 1;
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, u, o, 0);
											break;
										}
									}
								}
							}
						}
					}
					if (b == 1){
						break;
					}
				}
			} else if (gamemode_played == Rain) {
				for (unsigned int h=1; h<=(m-4); h+=1){
					for (unsigned int k=1; k<=(n-2); k+=1){
						if ((Field[0][h][k] != geben)&&(Field[0][h][k] != 0)){
							b = 1;
							set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, h, k, 0);
							break;
						}
					}
					if (b == 1){
						break;
					}
				}
			} else if (gamemode_played == Ulcer) {
				for (unsigned int h=1; h<=(m-2); h+=1){
					for (unsigned int k=1; k<=(n-2); k+=1){
						if (Field[0][h][k] == geben){
							for (unsigned int u=(h-1); u<=(h+1); u+=1){
								for (unsigned int o=(k-1); o<=(k+1); o+=1){
									if ((u+o)%2 == (h+k+1)%2) {
										if ((Field[0][u][o] != geben)&&(Field[0][u][o] != 0)&&(Field[0][u][o] != 1)){
											b = 1;
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, u, o, 0);
											break;
										}
									}
								}
							}
						}
					}
					if (b == 1){
						break;
					}
				}
			} else if (gamemode_played == Dynamic) {
				for (unsigned int h=1; h<=(m-2); h+=1){
					for (unsigned int k=1; k<=(n-2); k+=1){
						if (Field[0][h][k] == geben){
							for (unsigned int u=(h-1); u<=(h+1); u+=1){
								for (unsigned int o=(k-1); o<=(k+1); o+=1){
									if ((u+o)%2 == (h+k+1)%2) {
										if ((Field[0][u][o] != geben)&&(Field[0][u][o] != 0)&&(Field[0][u][o] != Dynamic_ball)){
											b = 1;
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, u, o, 0);
											break;
										}
									}
								}
							}
						}
					}
					if (b == 1){
						break;
					}
				}
			} else if (gamemode_played == Quidditch) {
				for (unsigned int h=1; h<=(m-2); h+=1){
					for (unsigned int k=1; k<=(n-2); k+=1){
						if (Field[0][h][k] == geben){
							for (unsigned int u=(h-1); u<=(h+1); u+=1){
								for (unsigned int o=(k-1); o<=(k+1); o+=1){
									if ((u+o)%2 == (h+k+1)%2) {
										if (Field[0][u][o] == geben%2 +1){
											b = 1;
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, u, o, 0);
											break;
										}
									}
								}
							}
						}
					}
					if (b == 1){
						break;
					}
				}
			} else {
				for (unsigned int h=1; h<=(m-2); h+=1){
					for (unsigned int k=1; k<=(n-2); k+=1){
						if (Field[0][h][k] == geben){
							for (unsigned int u=(h-1); u<=(h+1); u+=1){
								for (unsigned int o=(k-1); o<=(k+1); o+=1){
									if ((u+o)%2 == (h+k+1)%2) {
										if ((Field[0][u][o] != geben)&&(Field[0][u][o] != 0)){
											b = 1;
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, u, o, 0);
											break;
										}
									}
								}
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
			letters_4 = get_unsigned_numeric_input_with_not_more_than_letters_4_for_splitting();
			fremde_Zeile = split_unsigned_numeric_input_with_letters_4 (letters_4, 0);
			fremde_Spalte = split_unsigned_numeric_input_with_letters_4 (letters_4, 1);

			if ((fremde_Zeile == 0)&&(fremde_Spalte == 0)){
				printf("	Sweet escape...\n");
			} else {

				a = 0;								//Eigener in der Nähe?

				if (((fremde_Zeile<1)||(fremde_Zeile>(m-2))) || ((fremde_Spalte<1)||(fremde_Spalte>n-2))){
					printf("	you made a mistake, try again: \n");
					if (Opague_o.characterization >= 1) {
						show_field (number_of_players, single_option_representives.invisible, level, Sf_permutations, Opague_o.field, Opague_o.field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
					} else {
						show_field (number_of_players, single_option_representives.invisible, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
					}
					Destroy (level, Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Growth_players, Opague_o, Allocation_o, number_of_players, single_option_representives);

				} else if (gamemode_played == Contact) {
					for (unsigned int h=fremde_Zeile-1; h<=fremde_Zeile+1; h+=1){
						for (unsigned int k=fremde_Spalte-1; k<=fremde_Spalte+1; k+=1){
							if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
								if (Field[0][h][k] == geben){
									a = 1;
								}
							}
						}
					}
				} else if (gamemode_played == Rain) {
					if (fremde_Zeile <= (m-4)){
						a = 1;
					}
				} else {
					if ((Field[0][fremde_Zeile-1][fremde_Spalte]==geben)||(Field[0][fremde_Zeile][fremde_Spalte-1]==geben)||(Field[0][fremde_Zeile][fremde_Spalte+1]==geben)||(Field[0][fremde_Zeile+1][fremde_Spalte]==geben)){
						a = 1;
					}
				}

				if (a == 0){	//mehr-gamemode_played
					printf("	you made a mistake, try again: \n");
					Destroy (level, Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Growth_players, Opague_o, Allocation_o, number_of_players, single_option_representives);
				} else if ((gamemode_played == Hunt)&&(Field[0][fremde_Zeile][fremde_Spalte] != geben_destroy)){
					printf("	you made a mistake, try again: \n");
					Destroy (level, Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Growth_players, Opague_o, Allocation_o, number_of_players, single_option_representives);
				} else if (((gamemode_played == Classic)||(gamemode_played == Contact)||(gamemode_played == Fight)||(gamemode_played == Sand)||(gamemode_played == Survive)||(gamemode_played == Arena))&&((Field[0][fremde_Zeile][fremde_Spalte] == 0)||(Field[0][fremde_Zeile][fremde_Spalte] == geben))){
					printf("	you made a mistake, try again: \n");
					Destroy (level, Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Growth_players, Opague_o, Allocation_o, number_of_players, single_option_representives);
				} else if ((gamemode_played == Collect)&&((Field[0][fremde_Zeile][fremde_Spalte] == 0)||(Field[0][fremde_Zeile][fremde_Spalte] == geben)||(Field[0][fremde_Zeile][fremde_Spalte] == To_collect))){
					printf("	you made a mistake, try again: \n");
					Destroy (level, Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Growth_players, Opague_o, Allocation_o, number_of_players, single_option_representives);
				} else if ((gamemode_played == Fall)&&((Field[0][fremde_Zeile][fremde_Spalte] == 0)||(Field[0][fremde_Zeile][fremde_Spalte] == geben)||(Field[0][fremde_Zeile][fremde_Spalte] == Fall_ball))){
					printf("	you made a mistake, try again: \n");
					Destroy (level, Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Growth_players, Opague_o, Allocation_o, number_of_players, single_option_representives);
				} else if ((gamemode_played == Race)&&((Field[0][fremde_Zeile][fremde_Spalte] == 0)||(Field[0][fremde_Zeile][fremde_Spalte] == geben)||(Field[0][fremde_Zeile][fremde_Spalte] == Wall)||(Field[0][fremde_Zeile][fremde_Spalte] == Wall_at_the_end))){
					printf("	you made a mistake, try again: \n");
					Destroy (level, Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Growth_players, Opague_o, Allocation_o, number_of_players, single_option_representives);
				} else if ((gamemode_played == Rain)&&((Field[0][fremde_Zeile][fremde_Spalte] == 0)||(Field[0][fremde_Zeile][fremde_Spalte] == geben)||(fremde_Zeile > m-4))){
					printf("	you made a mistake, try again: \n");
					Destroy (level, Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Growth_players, Opague_o, Allocation_o, number_of_players, single_option_representives);
				} else if ((gamemode_played == Ulcer)&&((Field[0][fremde_Zeile][fremde_Spalte] == 0)||(Field[0][fremde_Zeile][fremde_Spalte] == geben)||(Field[0][fremde_Zeile][fremde_Spalte] == 1))){
					printf("	you made a mistake, try again: \n");
					Destroy (level, Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Growth_players, Opague_o, Allocation_o, number_of_players, single_option_representives);
				} else if ((gamemode_played == Dynamic)&&((Field[0][fremde_Zeile][fremde_Spalte] == 0)||(Field[0][fremde_Zeile][fremde_Spalte] == geben)||(Field[0][fremde_Zeile][fremde_Spalte] == Dynamic_ball))){
					printf("	you made a mistake, try again: \n");
					Destroy (level, Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Growth_players, Opague_o, Allocation_o, number_of_players, single_option_representives);
				} else if ((gamemode_played == Quidditch)&&(Field[0][fremde_Zeile][fremde_Spalte] != geben%2 +1)){
					printf("	you made a mistake, try again: \n");
					Destroy (level, Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Growth_players, Opague_o, Allocation_o, number_of_players, single_option_representives);
				} else {
					Field[0][fremde_Zeile][fremde_Spalte] = 0;
					Allocation_o.field[0][fremde_Zeile][fremde_Spalte] = 0;
				}
			}
		}
	}
}

void Revive (Spielfeld Spiel, unsigned int m, unsigned int n, Spielfeld evolution_od, Spielfeld Field, unsigned int geben, Special_Fields Allocation_o, Spielfeld Opague_o_field, unsigned int number_of_players, unsigned int gamemode_played){	//checklist
	unsigned int a;
	Spielfeld temp_revive;

	temp_revive = Spielfeld_Create (m, n, 0);
	a = 0;

	for (unsigned int i=1; i<m-1; i+=1){
		for (unsigned int j=1; j<n-1; j+=1){
			if (evolution_od[geben][i][j] == 101*geben){
				set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, temp_revive, 0, i, j, 101*geben);
				for (unsigned int h=i-1; h<=i+1; h+=1){
					for (unsigned int k=j-1; k<=j+1; k+=1){
						if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
							if ((Spiel[0][h][k] == geben) && (evolution_od[geben][h][k] != 101*geben)){
								a+=1;
							}
						}
					}
				}
				if (a == 0){
					set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, temp_revive, 0, i, j, 0);
				}
				a = 0;
			}
		}
	}

	for (unsigned int i=1; i<m-1; i+=1){
		for (unsigned int j=1; j<n-1; j+=1){
			if ((evolution_od[geben][i][j] == 101*geben) && (temp_revive[0][i][j] == 0)){
				set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, evolution_od, geben, i, j, 0);
			}
		}
	}

	Spielfeld_Destroy (temp_revive, m, 0);
}

void Boost (Spielfeld Spiel, unsigned int geben, Spielfeld Field, unsigned int m, unsigned int n, Spielfeld temp, unsigned int gamemode_played, Spielfeld Opague_o_field, Special_Fields Allocation_o, unsigned int number_of_players){	//checklist
	unsigned int geben_Boost;
	//printf("?");
	if (gamemode_played == Hunt) {
		geben_Boost = 1;
	} else {
		geben_Boost = 0;	// geben_Boost = 0; done
	}


	if ((gamemode_played == Hunt)&&(geben != 1)) {
		for (unsigned int i=1; i<m-1; i+=1){
			for (unsigned int j=1; j<n-1; j+=1){
				if (Spiel[0][i][j] == geben_Boost) {
					if ((Spiel[0][i-1][j]==geben)||(Spiel[0][i][j-1]==geben)||(Spiel[0][i][j+1]==geben)||(Spiel[0][i+1][j]==geben)){
						set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, temp, 0, i, j, geben_Boost);
					}
				}
			}
		}
	} else if (gamemode_played == Contact) {
		for (unsigned int i=1; i<m-1; i+=1){
			for (unsigned int j=1; j<n-1; j+=1){
				if ((Spiel[0][i][j] != geben)&&(Spiel[0][i][j] != 0)) {
					for (unsigned int h=i-1; h<=i+1; h+=1){
						for (unsigned int k=j-1; k<=j+1; k+=1){
							if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
								if (Spiel[0][h][k] == geben){
									set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, temp, 0, i, j, Spiel[0][i][j]);
								}
							}
						}
					}
				}
			}
		}
	} else if (gamemode_played == Rain) {
		for (unsigned int i=1; i<m-1; i+=1){
			for (unsigned int j=1; j<n-1; j+=1){
				if (Spiel[0][i][j] == Raindrop) {
					if ((Spiel[0][i-1][j]==geben)||(Spiel[0][i][j-1]==geben)||(Spiel[0][i][j+1]==geben)||(Spiel[0][i+1][j]==geben)){
						set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, temp, 0, i, j, Raindrop);
					}
				}
			}
		}
	} else {
		for (unsigned int i=1; i<m-1; i+=1){
			for (unsigned int j=1; j<n-1; j+=1){
				if ((Spiel[0][i][j] != geben)&&(Spiel[0][i][j] != 0)) {
					if ((Spiel[0][i-1][j]==geben)||(Spiel[0][i][j-1]==geben)||(Spiel[0][i][j+1]==geben)||(Spiel[0][i+1][j]==geben)){
						set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, temp, 0, i, j, Spiel[0][i][j]);
					}
				}
			}
		}
	}

	for (unsigned int i=1; i<m-1; i+=1){
		for (unsigned int j=1; j<n-1; j+=1){
			if (temp[0][i][j] != 0){
				set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j, geben);
			}
		}
	}

}
