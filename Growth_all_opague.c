
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
#include "Growth_all_set.h"
#include "Growth_all_visual.h"
#include "Growth_all_show.h"
#include "Growth_all_opague.h"

void Opague_show_controll (unsigned int* level, Spielfeld Field, Special_Fields Opague_o, unsigned int m, unsigned int n, unsigned int geben, unsigned int AOP, Special_Fields_Collector* sfc, unsigned int number_of_players, unsigned int gamemode_played, unsigned int single_option_representives_invisible, Spielfeld Sf_permutations, unsigned int* information_code, Growth_Player* Growth_players) {
	
	if (Opague_o.characterization >= 1) {
		opague_builder (Field, Opague_o, m, n, geben, AOP, sfc, number_of_players, gamemode_played);
		show_field (number_of_players, single_option_representives_invisible, level, Sf_permutations, Opague_o.field, Opague_o.field, m, n, gamemode_played, information_code, geben, Growth_players, 0, sfc);
	} else {
		show_field (number_of_players, single_option_representives_invisible, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, sfc);
	}
}

void opague_builder (Spielfeld Field, Special_Fields Opague_o, unsigned int m, unsigned int n, unsigned int geben, unsigned int AOP, Special_Fields_Collector* sfc, unsigned int number_of_players, unsigned int gamemode_played) {
	unsigned int extra;
	unsigned int list_position, value;
	unsigned int* opague_counter;
	Spielfeld temp_opague;

	//printf("Opague_o.characterization: %u \n", Opague_o.characterization);		//test

	extra = 0;
	list_position = AOP+2;	// extra has to be counted
	value = geben;	//geben can't be picked
	
	while (value != 0) {
		value = list_of_possible_Field_values_from_one_to_ninethousand (AOP, list_position);
		extra += 1;
		list_position += 1;
	}
	
	opague_counter = unsigned_int_Vektor_Create(1+AOP+extra);
	temp_opague = Spielfeld_Create (m, n, 0);
	
	for (unsigned int p=0; p<=AOP+extra; p++) {
		opague_counter[p] = 0;
	}
	
	for (unsigned int i=1; i<m-1; i+=1){
		for (unsigned int j=1; j<n-1; j+=1){

			if (Opague_o.characterization >= 20) {		//4-Mode-Opague, near-by

				if (Field[0][i][j] != 11) {
					if (Field[0][i][j] == geben) {
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, sfc, number_of_players, temp_opague, 0, i, j, geben);
					} else if ((Field[0][i][j] != 0)) {
						
						list_position = 1;	// =0 would quit the while-loop instantly
						value = geben;	//geben can't be picked
						
						while ((Field[0][i][j] != value)&&(value != 0)) {
							value = list_of_possible_Field_values_from_one_to_ninethousand (AOP, list_position);
							if (Field[0][i][j] == value) {	//Field[0][i][j] != 0, therefore there is no problem according to the list_position which isn't in the range of opague_counter anymore.
								opague_counter[list_position] += 1;
							}
							list_position += 1;
						}
					}
				}

				if ((i<(m-2))&&(Field[0][i][j] != 11)) {
					if (Field[0][i][j] == geben) {
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, sfc, number_of_players, temp_opague, 0, i+1, j, Field[0][i+1][j]);
					} else if ((Field[0][i+1][j] != 11)&&(Field[0][i+1][j] != 0)&&(Field[0][i+1][j] != geben)) {
						list_position = 1;	// =0 would quit the while-loop instantly
						value = geben;	//geben can't be picked
						
						while ((Field[0][i+1][j] != value)&&(value != 0)) {
							value = list_of_possible_Field_values_from_one_to_ninethousand (AOP, list_position);
							if (Field[0][i+1][j] == value) {	//Field[0][i][j] != 0, therefore there is no problem according to the list_position which isn't in the range of opague_counter anymore.
								opague_counter[list_position] += 1;
							}
							list_position += 1;
						}
					}
				}

				if ((i>1)&&(Field[0][i][j] != 11)) {
					if (Field[0][i][j] == geben) {
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, sfc, number_of_players, temp_opague, 0, i-1, j, Field[0][i-1][j]);
					} else if ((Field[0][i-1][j] != 11)&&(Field[0][i-1][j] != 0)&&(Field[0][i-1][j] != geben)) {
						list_position = 1;	// =0 would quit the while-loop instantly
						value = geben;	//geben can't be picked
						
						while ((Field[0][i-1][j] != value)&&(value != 0)) {
							value = list_of_possible_Field_values_from_one_to_ninethousand (AOP, list_position);
							if (Field[0][i-1][j] == value) {	//Field[0][i][j] != 0, therefore there is no problem according to the list_position which isn't in the range of opague_counter anymore.
								opague_counter[list_position] += 1;
							}
							list_position += 1;
						}
					}
				}

				if ((j>1)&&(Field[0][i][j] != 11)) {
					if (Field[0][i][j] == geben) {
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, sfc, number_of_players, temp_opague, 0, i, j-1, Field[0][i][j-1]);
					} else if ((Field[0][i][j-1] != 11)&&(Field[0][i][j-1] != 0)&&(Field[0][i][j-1] != geben)) {
						list_position = 1;	// =0 would quit the while-loop instantly
						value = geben;	//geben can't be picked
						
						while ((Field[0][i][j-1] != value)&&(value != 0)) {
							value = list_of_possible_Field_values_from_one_to_ninethousand (AOP, list_position);
							if (Field[0][i][j-1] == value) {	//Field[0][i][j] != 0, therefore there is no problem according to the list_position which isn't in the range of opague_counter anymore.
								opague_counter[list_position] += 1;
							}
							list_position += 1;
						}
					}
				}

				if ((j<(n-2))&&(Field[0][i][j] != 11)) {
					if (Field[0][i][j] == geben) {
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, sfc, number_of_players, temp_opague, 0, i, j+1, Field[0][i][j+1]);
					} else if ((Field[0][i][j+1] != 11)&&(Field[0][i][j+1] != 0)&&(Field[0][i][j+1] != geben)) {
						list_position = 1;	// =0 would quit the while-loop instantly
						value = geben;	//geben can't be picked
						
						while ((Field[0][i][j+1] != value)&&(value != 0)) {
							value = list_of_possible_Field_values_from_one_to_ninethousand (AOP, list_position);
							if (Field[0][i][j+1] == value) {	//Field[0][i][j] != 0, therefore there is no problem according to the list_position which isn't in the range of opague_counter anymore.
								opague_counter[list_position] += 1;
							}
							list_position += 1;
						}
					}
				}

				if ((Field[0][i][j+1] == geben)||(Field[0][i][j-1] == geben)||(Field[0][i-1][j] == geben)||(Field[0][i+1][j] == geben)) {
					for (unsigned int p=0; p<=AOP+extra; p+=1) {
						opague_counter[p] = 0;
					}
				}

				if (Opague_o.characterization % 10 == 1) {		//4-Mode-Opague, uneven
					for (unsigned int p=1; p<=AOP+extra; p+=1) {
						if (opague_counter[p] % 2 == 0) {
							opague_counter[p] = 0;
						}
					}

				} else if (Opague_o.characterization % 10 == 2) {		//4-Mode-Opague, even
					for (unsigned int p=1; p<=AOP+extra; p+=1) {
						if (opague_counter[p] % 2 == 1) {
							opague_counter[p] = 0;
						}
					}

				}

				opague_counter[0] = 0;

				for (unsigned int a=1; a<=AOP+extra; a+=1) {
					if (a != geben) {
						if (opague_counter[a] != 0) {

							for (unsigned int b=1; b<=AOP+extra; b+=1) {
								if (a != b) {
									if (opague_counter[a] > opague_counter[b]) {	//für AOP >= b > number_of_players gilt opague_counter[b] = 0;
										opague_counter[0] += 1;
									}
								}
							}

							if ((opague_counter[0] == AOP+extra-1)&&(temp_opague[0][i][j] == 0)) {	//bei Gleichstand zweier Objekte bleibt temp_opague[0][i][j] unbesetzt, da die AOP+extra-1 von keinem erreicht wird
								value = list_of_possible_Field_values_from_one_to_ninethousand (AOP, a);
								set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, sfc, number_of_players, temp_opague, 0, i, j, value);
							}
							opague_counter[0] = 0;
						}
					}
				}

				for (unsigned int p=0; p<=AOP+extra; p+=1) {
					opague_counter[p] = 0;
				}


			} else if (Opague_o.characterization >= 10) {		//4-Mode-Opague, Surrounding

				for (unsigned int h=i-1; h<=i+1; h+=1){
					for (unsigned int k=j-1; k<=j+1; k+=1){
						if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
							if (Field[0][h][k] != 11) {
								if (Field[0][i][j] == geben) {
									set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, sfc, number_of_players, temp_opague, 0, h, k, Field[0][h][k]);
								} else if ((Field[0][h][k] != 11)&&(Field[0][h][k] != 0)&&(Field[0][h][k] != geben)) {
									list_position = 1;	// =0 would quit the while-loop instantly
									value = geben;	//geben can't be picked
									
									while ((Field[0][h][k] != value)&&(value != 0)) {
										value = list_of_possible_Field_values_from_one_to_ninethousand (AOP, list_position);
										if (Field[0][i][j+1] == value) {	//Field[0][i][j] != 0, therefore there is no problem according to the list_position which isn't in the range of opague_counter anymore.
											opague_counter[list_position] += 1;
										}
										list_position += 1;
									}
								}
							}
						}
					}
				}

				if (Opague_o.characterization % 10 == 1) {		//4-Mode-Opague, uneven
					for (unsigned int p=1; p<=AOP+extra; p+=1) {
						if (opague_counter[p] % 2 == 0) {
							opague_counter[p] = 0;
						}
					}
				} else if (Opague_o.characterization % 10 == 2) {		//4-Mode-Opague, even
					for (unsigned int p=1; p<=AOP+extra; p+=1) {
						if (opague_counter[p] % 2 == 1) {
							opague_counter[p] = 0;
						}
					}
				}

				opague_counter[0] = 0;

				for (unsigned int a=1; a<=AOP+extra; a+=1) {	//Übertragung auf temp_opague
					if (a != geben) {
						if (opague_counter[a] != 0) {

							for (unsigned int b=1; b<=AOP+extra; b+=1) {
								if (a != b) {
									if (opague_counter[a] > opague_counter[b]) {
										opague_counter[0] += 1;
									}
								}
							}

							if ((opague_counter[0] == AOP+extra-1)&&(temp_opague[0][i][j] == 0)) {	//bei Gleichstand zweier Objekte bleibt temp_opague[0][i][j] unbesetzt, da die AOP+extra-1 von keinem erreicht wird
								value = list_of_possible_Field_values_from_one_to_ninethousand (AOP, a);
								set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, sfc, number_of_players, temp_opague, 0, i, j, value);
							}

							opague_counter[0] = 0;
						}
					}
				}

				for (unsigned int p=0; p<=AOP+extra; p+=1) {
					opague_counter[p] = 0;
				}
			//AOP und opague_counter ersetzen/anpassen... , done
			}

			if (Field[0][i][j] == 11) {
				set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, sfc, number_of_players, temp_opague, 0, i, j, 11);
			}
		}
	}

	for (unsigned int i=1; i<m-1; i+=1){
		for (unsigned int j=1; j<n-1; j+=1){
			set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, sfc, number_of_players, Opague_o.field, 0, i, j, temp_opague[0][i][j]);
		}
	}

	Spielfeld_Destroy (temp_opague, m, 0);
	unsigned_int_Vektor_Destroy (opague_counter);
}

unsigned int list_of_possible_Field_values_from_one_to_ninethousand (unsigned int AOP, unsigned int list_position) {	//checklist
	
	unsigned int value;
	value = 0;
	
	if (list_position <= AOP) {
		value = list_position;
	} else if (list_position == AOP+1) {
		value = To_collect;
	} else if (list_position == AOP+2) {
		value = Fall_ball;
	} else if (list_position == AOP+3) {
		value = Wall;
	} else if (list_position == AOP+4) {
		value = Wall_at_the_end;
	} else if (list_position == AOP+5) {
		value = Raindrop;
	} else if (list_position == AOP+6) {
		value = Dynamic_ball;
	} else if (list_position == AOP+7) {
		value = Waves;
	} else if (list_position == AOP+8) {
		value = Waves_new;
	} else if (list_position == AOP+9) {
		value = Traps;
	} else if (list_position == AOP+10) {
		value = Bomb_4;
	} else if (list_position == AOP+11) {
		value = Bomb_3;
	} else if (list_position == AOP+12) {
		value = Bomb_2;
	} else if (list_position == AOP+13) {
		value = Bomb_1;
	} else if (list_position == AOP+14) {
		value = Quaffel;
	} else if (list_position == AOP+15) {
		value = Klatscher;
	} else if (list_position == AOP+16) {
		value = Schnatz;
	} else if (list_position == AOP+17) {
		value = Jaeger_1;
	} else if (list_position == AOP+18) {
		value = Hueter_1;
	} else if (list_position == AOP+19) {
		value = Treiber_1;
	} else if (list_position == AOP+20) {
		value = Sucher_1;
	} else if (list_position == AOP+21) {
		value = Torring_1;
	} else if (list_position == AOP+22) {
		value = Torring_2;
	} else if (list_position == AOP+23) {
		value = Jaeger_2;
	} else if (list_position == AOP+24) {
		value = Hueter_2;
	} else if (list_position == AOP+25) {
		value = Treiber_2;
	} else if (list_position == AOP+26) {
		value = Sucher_2;
	} else if (list_position == AOP+27) {
		value = Roses_0;
	} else if (list_position == AOP+28) {
		value = Roses_1;
	} else if (list_position == AOP+29) {
		value = Roses_2;
	} else if (list_position == AOP+30) {
		value = Roses_3;
	} else if (list_position == AOP+31) {
		value = Roses_4;
	} else if (list_position == AOP+32) {
		value = Roses_5;
	} else if (list_position == AOP+33) {
		value = Roses_6;
	} else {
		value = 0;
	}
	
	
	return value;
}
