
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
#include "Growth_all_options_specials.h"
#include "Growth_all_Development.h"
#include "Growth_all_KI.h"

// #define VERBOSE
// #define Contact_mistake_search
// #define Quidditch_mistake_search


void synchronisation_Field_copy (Spielfeld Field, Spielfeld Field_copy, unsigned int m, unsigned int n, unsigned int number_of_players, unsigned int geben, Spielfeld Opague_o_field, unsigned int gamemode_played, Special_Fields Allocation_o) {

	// printf("synchronisation_Field_copy ok.1\n");	//test

	for (unsigned int i=1; i<=m-2; i++) {
		for (unsigned int j=1; j<=n-2; j++) {
			set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field_copy, 0, i, j, Field_copy[1][i][j]);
		}
	}
}

void reset_Field_copy (Spielfeld Field, Spielfeld Field_copy_save, Spielfeld Field_copy, unsigned int m, unsigned int n, unsigned int number_of_players, unsigned int geben, Spielfeld Opague_o_field, unsigned int gamemode_played, Special_Fields Allocation_o) {

	// printf("reset_Field_copy ok.1\n");	//test

	for (unsigned int i=1; i<=m-2; i++) {
		for (unsigned int j=1; j<=n-2; j++) {
			set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field_copy, 0, i, j, Field_copy_save[0][i][j]);
		}
	}
}

void synchronisation_ges_copy (unsigned int* ges_copy, unsigned int number_of_players, unsigned int* ges) {
	// printf("reset_ges_copy ok.1\n");	//test
	for (unsigned int p=0; p<=number_of_players; p++) {
		ges_copy[p] = ges[p];
	}
}

void reset_ges_copy (unsigned int* ges_copy_save, unsigned int* ges_copy, unsigned int number_of_players) {
	// printf("reset_ges_copy ok.1\n");	//test
	for (unsigned int p=0; p<=number_of_players; p++) {
		ges_copy[p] = ges_copy_save[p];
	}
}

void ges_others_counter (unsigned int* ges_copy, unsigned int* ges_others, unsigned int number_of_players, unsigned int geben) {
	unsigned int count_players;

	count_players = 0;
	// printf("ges_others: %u \n", *ges_others);	//test

	for (unsigned int p=1; p<=number_of_players; p++) {
		if ((p != geben)&&(ges_copy[p] != 1010*p)) {
			count_players += 1;
			*ges_others += ges_copy[p];
		}
	}
	if (count_players != 0) {
		*ges_others = (*ges_others)/count_players;
	} else {
		*ges_others = 0;
	}

	// printf("ges_others_counter ok.1\n");	//test
}


void turn_of_KI_random (Quidditch_setup* Qs, Moveable_objects_condition* Moc_Quaffel, Moveable_objects_condition* Moc_Schnatz, Moveable_objects_condition* Moc_Klatscher, unsigned int* KI_decision, Spielfeld Field, unsigned int m, unsigned int n, unsigned int geben, Special_Fields Opague_o, Special_Fields Allocation_o, Spielfeld Sf_permutations, unsigned int* ges, Growth_Player* Growth_players, unsigned int number_of_players, unsigned int gamemode_played, unsigned int* information_code, unsigned int* level, Limits limits, Single_option_representives single_option_representives, unsigned int rain, Realize_modifications_variables* rmv, Special_Fields Roses_o) {
	Spielfeld Field_copy;
	unsigned int* KI_table_of_choice;		// number/own_square or 0/enemy_square or 0/more (1) or less (2) squares in possession/difference of squares
	unsigned int* ges_copy;
	unsigned int dimension;

	#ifdef VERBOSE
	printf (" turn_of_KI_random ok.1 \n");	//test
	#endif

	dimension = 0;
	Field_copy = Spielfeld_Create (m, n, 1);	//0 to work with, 1 to synchronisate with
	dimension_of (level, &dimension, geben);
	KI_table_of_choice = unsigned_int_Vektor_Create (dimension);
	ges_copy = unsigned_int_Vektor_Create (rmv->AOP+1);
	for (unsigned int p=0; p<=rmv->AOP; p++) {
		ges_copy[p] = ges[p];
	}
	for (unsigned int i=1; i<=m-2; i++) {
		for (unsigned int j=1; j<=n-2; j++) {
			set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field_copy, 1, i, j, Field[0][i][j]);
		}
	}

	synchronisation_Field_copy (Field, Field_copy, m, n, number_of_players, geben, Opague_o.field, gamemode_played, Allocation_o);

	while (KI_table_of_choice[0] == 0) {
		fill_KI_table_of_choice (Qs, Moc_Quaffel, Moc_Schnatz, Moc_Klatscher, KI_decision, Field, Field_copy, m, n, geben, Opague_o, Allocation_o, Sf_permutations, ges_copy, Growth_players, number_of_players, gamemode_played, information_code, level, KI_table_of_choice, ges, limits, single_option_representives, rain, rmv, Roses_o);
	}

	synchronisation_Field_copy (Field, Field_copy, m, n, number_of_players, geben, Opague_o.field, gamemode_played, Allocation_o);

	rmv->var_[geben] = KI_table_of_choice[0];
	*KI_decision = KI_table_of_choice[5];
	if ((KI_table_of_choice[0] == Move_2)||(KI_table_of_choice[0] == Change_)||(KI_table_of_choice[0] == Move_4)) {
		set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, KI_table_of_choice[1]/100, KI_table_of_choice[1]%100, Field_copy[1][KI_table_of_choice[2]/100][KI_table_of_choice[2]%100]);
		set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, KI_table_of_choice[2]/100, KI_table_of_choice[2]%100, Field_copy[1][KI_table_of_choice[1]/100][KI_table_of_choice[1]%100]);
	} else if (KI_table_of_choice[0] == Minus_) {
		set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, KI_table_of_choice[1]/100, KI_table_of_choice[1]%100, 0);
	} else if (KI_table_of_choice[0] == Plus_) {
		set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, KI_table_of_choice[2]/100, KI_table_of_choice[2]%100, geben);
	} else if (KI_table_of_choice[0] == Destroy_) {
		set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, KI_table_of_choice[2]/100, KI_table_of_choice[2]%100, 0);
	}

	if (level[geben] == Liz) {
		Liz_max = 0;
	}

	unsigned_int_Vektor_Destroy (ges_copy);
	unsigned_int_Vektor_Destroy (KI_table_of_choice);
	Spielfeld_Destroy (Field_copy, m, 1);

	#ifdef VERBOSE
	printf (" turn_of_KI_random ok.2 \n");	//test
	#endif
}


void fill_KI_table_of_choice (Quidditch_setup* Qs, Moveable_objects_condition* Moc_Quaffel, Moveable_objects_condition* Moc_Schnatz, Moveable_objects_condition* Moc_Klatscher, unsigned int* KI_decision, Spielfeld Field, Spielfeld Field_copy, unsigned int m, unsigned int n, unsigned int geben, Special_Fields Opague_o, Special_Fields Allocation_o, Spielfeld Sf_permutations, unsigned int* ges_copy, Growth_Player* Growth_players, unsigned int number_of_players, unsigned int gamemode_played, unsigned int* information_code, unsigned int* level, unsigned int* KI_table_of_choice, unsigned int* ges, Limits limits, Single_option_representives single_option_representives, unsigned int rain, Realize_modifications_variables* rmv, Special_Fields Roses_o) {

	unsigned int w, d, e, how_many_ways_of_keeping;
	Spielfeld Plus_rememory;

	w = 3;
	d = 2;
	e = 3;
	how_many_ways_of_keeping = 1;
	Plus_rememory = Spielfeld_Create (m, n, 0);

	// printf("fill_KI_table_of_choice ok.1\n");	//test
	
	#ifdef VERBOSE
	printf("rmv->use_number: %u \n", rmv->use_number);	//test
	#endif
	
	how_many_ways_of_keeping = get_how_many_ways_of_keeping (gamemode_played);

	if (rmv->use_number == 1) {
		for (unsigned int i=1; i<=m-2; i++) {
			for (unsigned int j=1; j<=n-2; j++) {
				if (Field_copy[0][i][j] == geben) {
					for (unsigned int h=i-1; h<=i+1; h++) {
						for (unsigned int k=j-1; k<=j+1; k++) {
							if ((Plus_rememory[0][h][k] == 0)&&(Field_copy[0][h][k] == 0)&&(h<=m-2)&&(h>0)&&(k<=n-2)&&(k>0)) {	//Plus
								for (unsigned int p=1; p<=how_many_ways_of_keeping; p++) {
									set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field_copy, 0, h, k, geben);
									set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Plus_rememory, 0, h, k, geben);
									*KI_decision = p;
									set_KI_table_of_choice (Qs, Moc_Quaffel, Moc_Schnatz, Moc_Klatscher, KI_decision, Field, Field_copy, m, n, geben, Opague_o, Allocation_o, Sf_permutations, ges_copy, Growth_players, number_of_players, gamemode_played, information_code, level, KI_table_of_choice, w, d, e, Plus_, h, k, i, j, ges, limits, single_option_representives, rain, rmv, Roses_o);
								}
							}
						}
					}

					if (Field_copy[0][i][j] == geben) {	//Minus
						for (unsigned int p=1; p<=how_many_ways_of_keeping; p++) {
							set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field_copy, 0, i, j, 0);
							*KI_decision = p;
							set_KI_table_of_choice (Qs, Moc_Quaffel, Moc_Schnatz, Moc_Klatscher, KI_decision, Field, Field_copy, m, n, geben, Opague_o, Allocation_o, Sf_permutations, ges_copy, Growth_players, number_of_players, gamemode_played, information_code, level, KI_table_of_choice, w, d, e, Minus_, 0, 0, i, j, ges, limits, single_option_representives, rain, rmv, Roses_o);
						}
					}
				}
			}
		}
	} else if (rmv->use_number == 2) {
		for (unsigned int i=1; i<=m-2; i++) {
			for (unsigned int j=1; j<=n-2; j++) {
				if ((gamemode_played == Hunt)&&(geben == 1)) {
					if (Field_copy[0][i][j] == 11) {
						for (unsigned int h=i-1; h<=i+1; h++) {
							for (unsigned int k=j-1; k<=j+1; k++) {
								if ((Field_copy[0][h][k] == geben)&&(h<=m-2)&&(h>0)&&(k<=n-2)&&(k>0)&&((h+k)%2 == (i+j+1)%2)) {
									for (unsigned int p=1; p<=how_many_ways_of_keeping; p++) {
										set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field_copy, 0, i, j, geben);
										set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field_copy, 0, h, k, 11);
										*KI_decision = p;
										set_KI_table_of_choice (Qs, Moc_Quaffel, Moc_Schnatz, Moc_Klatscher, KI_decision, Field, Field_copy, m, n, geben, Opague_o, Allocation_o, Sf_permutations, ges_copy, Growth_players, number_of_players, gamemode_played, information_code, level, KI_table_of_choice, w, d, e, Change_, h, k, i, j, ges, limits, single_option_representives, rain, rmv, Roses_o);
									}
								} else if ((Field_copy[0][h][k] == 0)&&(h<=m-2)&&(h>0)&&(k<=n-2)&&(k>0)&&((h+k)%2 == (i+j+1)%2)) {
									for (unsigned int p=1; p<=how_many_ways_of_keeping; p++) {
										set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field_copy, 0, i, j, 0);
										set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field_copy, 0, h, k, 11);
										*KI_decision = p;
										set_KI_table_of_choice (Qs, Moc_Quaffel, Moc_Schnatz, Moc_Klatscher, KI_decision, Field, Field_copy, m, n, geben, Opague_o, Allocation_o, Sf_permutations, ges_copy, Growth_players, number_of_players, gamemode_played, information_code, level, KI_table_of_choice, w, d, e, Move_2, h, k, i, j, ges, limits, single_option_representives, rain, rmv, Roses_o);
									}
								}
							}
						}
					} else if (Field_copy[0][i][j] == geben) {
						for (unsigned int h=i-1; h<=i+1; h++) {
							for (unsigned int k=j-1; k<=j+1; k++) {
								if ((Field_copy[0][h][k] == 11)&&(h<=m-2)&&(h>0)&&(k<=n-2)&&(k>0)&&((h+k)%2 == (i+j+1)%2)) {	//Change_
									for (unsigned int p=1; p<=how_many_ways_of_keeping; p++) {
										set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field_copy, 0, i, j, 11);
										set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field_copy, 0, h, k, geben);
										*KI_decision = p;
										set_KI_table_of_choice (Qs, Moc_Quaffel, Moc_Schnatz, Moc_Klatscher, KI_decision, Field, Field_copy, m, n, geben, Opague_o, Allocation_o, Sf_permutations, ges_copy, Growth_players, number_of_players, gamemode_played, information_code, level, KI_table_of_choice, w, d, e, Change_, h, k, i, j, ges, limits, single_option_representives, rain, rmv, Roses_o);
									}
								} else if ((Field_copy[0][h][k] == 0)&&(h<=m-2)&&(h>0)&&(k<=n-2)&&(k>0)&&((h+k)%2 == (i+j+1)%2)) {	//Move
									for (unsigned int p=1; p<=how_many_ways_of_keeping; p++) {
										set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field_copy, 0, i, j, 0);
										set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field_copy, 0, h, k, geben);
										*KI_decision = p;
										set_KI_table_of_choice (Qs, Moc_Quaffel, Moc_Schnatz, Moc_Klatscher, KI_decision, Field, Field_copy, m, n, geben, Opague_o, Allocation_o, Sf_permutations, ges_copy, Growth_players, number_of_players, gamemode_played, information_code, level, KI_table_of_choice, w, d, e, Move_2, h, k, i, j, ges, limits, single_option_representives, rain, rmv, Roses_o);
									}
								}
							}
						}
					}
				} else {	//not gamemode_played == Hunt together with geben == 1
					if (Field_copy[0][i][j] == geben) {
						for (unsigned int h=i-1; h<=i+1; h++) {
							for (unsigned int k=j-1; k<=j+1; k++) {
								if (((Field_copy[0][h][k] != 0)&&(Field_copy[0][h][k] != geben)&&((gamemode_played != Hunt)||(Field_copy[0][h][k] == 1))&&((gamemode_played != Rain)||(Field_copy[0][h][k] == Raindrop))&&(Field_copy[0][h][k] != Wall)&&(Field_copy[0][h][k] != Wall_at_the_end)&&(Field_copy[0][h][k] != To_collect)&&(Field_copy[0][h][k] != Torring_1)&&(Field_copy[0][h][k] != Torring_2))&&(h<=m-2)&&(h>0)&&(k<=n-2)&&(k>0)&&(((h+k)%2 == (i+j+1)%2)||(gamemode_played == Contact))) {	//Change_
									for (unsigned int p=1; p<=how_many_ways_of_keeping; p++) {
										set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field_copy, 0, i, j, Field_copy[0][h][k]);
										set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field_copy, 0, h, k, geben);
										*KI_decision = p;
										set_KI_table_of_choice (Qs, Moc_Quaffel, Moc_Schnatz, Moc_Klatscher, KI_decision, Field, Field_copy, m, n, geben, Opague_o, Allocation_o, Sf_permutations, ges_copy, Growth_players, number_of_players, gamemode_played, information_code, level, KI_table_of_choice, w, d, e, Change_, h, k, i, j, ges, limits, single_option_representives, rain, rmv, Roses_o);
									}
								} else if ((Field_copy[0][h][k] == 0)&&(h<=m-2)&&(h>0)&&(k<=n-2)&&(k>0)&&((h+k)%2 == (i+j+1)%2)) {	//Move
									for (unsigned int p=1; p<=how_many_ways_of_keeping; p++) {
										set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field_copy, 0, i, j, 0);
										set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field_copy, 0, h, k, geben);
										*KI_decision = p;
										set_KI_table_of_choice (Qs, Moc_Quaffel, Moc_Schnatz, Moc_Klatscher, KI_decision, Field, Field_copy, m, n, geben, Opague_o, Allocation_o, Sf_permutations, ges_copy, Growth_players, number_of_players, gamemode_played, information_code, level, KI_table_of_choice, w, d, e, Move_2, h, k, i, j, ges, limits, single_option_representives, rain, rmv, Roses_o);
									}
								}
							}
						}
					}
				}
			}
		}
	} else if (rmv->use_number == 3) {
		for (unsigned int p=1; p<=how_many_ways_of_keeping; p++) {
			*KI_decision = p;
			set_KI_table_of_choice (Qs, Moc_Quaffel, Moc_Schnatz, Moc_Klatscher, KI_decision, Field, Field_copy, m, n, geben, Opague_o, Allocation_o, Sf_permutations, ges_copy, Growth_players, number_of_players, gamemode_played, information_code, level, KI_table_of_choice, w, d, e, Revive_, 0, 0, 0, 0, ges, limits, single_option_representives, rain, rmv, Roses_o);	//Revive_
		}
		if (gamemode_played == Rain) {	//Destroy_
			for (unsigned int h=1; h<=(m-4); h+=1){
				for (unsigned int k=1; k<=(n-2); k+=1){
					if ((Field[0][h][k] != geben)&&(Field[0][h][k] != 0)){
						for (unsigned int p=1; p<=how_many_ways_of_keeping; p++) {
							set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field_copy, 0, h, k, 0);
							*KI_decision = p;
							set_KI_table_of_choice (Qs, Moc_Quaffel, Moc_Schnatz, Moc_Klatscher, KI_decision, Field, Field_copy, m, n, geben, Opague_o, Allocation_o, Sf_permutations, ges_copy, Growth_players, number_of_players, gamemode_played, information_code, level, KI_table_of_choice, w, d, e, Destroy_, h, k, 0, 0, ges, limits, single_option_representives, rain, rmv, Roses_o);
						}
					}
				}
			}
		} else {	// gamemode_played != Rain
			for (unsigned int i=1; i<=m-2; i++) {
				for (unsigned int j=1; j<=n-2; j++) {
					if (Field_copy[0][i][j] == geben) {
							for (unsigned int h=i-1; h<=i+1; h++) {
								for (unsigned int k=j-1; k<=j+1; k++) {
									if ((Field_copy[0][h][k] != geben)&&(Field_copy[0][h][k] != 0)&&(((gamemode_played != Hunt)||(geben == 1))||(Field_copy[0][h][k] == 1))&&((gamemode_played != Ulcer)||(Field_copy[0][h][k] != 1))&&(Field_copy[0][h][k] != Wall)&&(Field_copy[0][h][k] != Wall_at_the_end)&&(Field_copy[0][h][k] != To_collect)&&((gamemode_played != Quidditch)||(Field_copy[0][h][k] <= number_of_players))&&(Field_copy[0][h][k] != Fall_ball)&&(Field_copy[0][h][k] != Dynamic_ball)&&(h<=m-2)&&(h>0)&&(k<=n-2)&&(k>0)&&(((h+k)%2 == (i+j+1)%2)||(gamemode_played == Contact))) {
										for (unsigned int p=1; p<=how_many_ways_of_keeping; p++) {
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field_copy, 0, h, k, 0);
											*KI_decision = p;
											set_KI_table_of_choice (Qs, Moc_Quaffel, Moc_Schnatz, Moc_Klatscher, KI_decision, Field, Field_copy, m, n, geben, Opague_o, Allocation_o, Sf_permutations, ges_copy, Growth_players, number_of_players, gamemode_played, information_code, level, KI_table_of_choice, w, d, e, Destroy_, h, k, i, j, ges, limits, single_option_representives, rain, rmv, Roses_o);
										}
									}
								}
							}
						
					}
				}
			}
		}
	} else if (rmv->use_number == 4) {
		for (unsigned int p=1; p<=how_many_ways_of_keeping; p++) {
			*KI_decision = p;
			set_KI_table_of_choice (Qs, Moc_Quaffel, Moc_Schnatz, Moc_Klatscher, KI_decision, Field, Field_copy, m, n, geben, Opague_o, Allocation_o, Sf_permutations, ges_copy, Growth_players, number_of_players, gamemode_played, information_code, level, KI_table_of_choice, w, d, e, Boost_, 0, 0, 0, 0, ges, limits, single_option_representives, rain, rmv, Roses_o);	//Boost_
		}
		for (unsigned int i=1; i<=m-2; i++) {	//Move
			for (unsigned int j=1; j<=n-2; j++) {
				if (Field_copy[0][i][j] == geben) {
					for (unsigned int h=i-1; h<=i+1; h++) {
						for (unsigned int k=j-1; k<=j+1; k++) {
							if ((Field_copy[0][h][k] == 0)&&(h<=m-2)&&(h>0)&&(k<=n-2)&&(k>0)&&((h+k)%2 == (i+j+1)%2)) {
								for (unsigned int p=1; p<=how_many_ways_of_keeping; p++) {
									set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field_copy, 0, i, j, 0);
									set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field_copy, 0, h, k, geben);
									*KI_decision = p;
									set_KI_table_of_choice (Qs, Moc_Quaffel, Moc_Schnatz, Moc_Klatscher, KI_decision, Field, Field_copy, m, n, geben, Opague_o, Allocation_o, Sf_permutations, ges_copy, Growth_players, number_of_players, gamemode_played, information_code, level, KI_table_of_choice, w, d, e, Move_4, h, k, i, j, ges, limits, single_option_representives, rain, rmv, Roses_o);
								}
							}
						}
					}
				}
			}
		}
	} else if (rmv->use_number == 5) {
		w = 2;
		d = 2;
		e = 3;
		for (unsigned int p=1; p<=how_many_ways_of_keeping; p++) {
			*KI_decision = p;
			set_KI_table_of_choice (Qs, Moc_Quaffel, Moc_Schnatz, Moc_Klatscher, KI_decision, Field, Field_copy, m, n, geben, Opague_o, Allocation_o, Sf_permutations, ges_copy, Growth_players, number_of_players, gamemode_played, information_code, level, KI_table_of_choice, w, d, e, new_2, 0, 0, 0, 0, ges, limits, single_option_representives, rain, rmv, Roses_o);	//2-new
		}

		w = 4;
		d = 2;
		e = 3;
		for (unsigned int p=1; p<=how_many_ways_of_keeping; p++) {
			*KI_decision = p;
			set_KI_table_of_choice (Qs, Moc_Quaffel, Moc_Schnatz, Moc_Klatscher, KI_decision, Field, Field_copy, m, n, geben, Opague_o, Allocation_o, Sf_permutations, ges_copy, Growth_players, number_of_players, gamemode_played, information_code, level, KI_table_of_choice, w, d, e, new_4_5, 0, 0, 0, 0, ges, limits, single_option_representives, rain, rmv, Roses_o);	//4/5-new
		}
	} else if (rmv->use_number == 6) {
		w = 3;
		d = 1;
		e = 3;
		for (unsigned int p=1; p<=how_many_ways_of_keeping; p++) {
			*KI_decision = p;
			set_KI_table_of_choice (Qs, Moc_Quaffel, Moc_Schnatz, Moc_Klatscher, KI_decision, Field, Field_copy, m, n, geben, Opague_o, Allocation_o, Sf_permutations, ges_copy, Growth_players, number_of_players, gamemode_played, information_code, level, KI_table_of_choice, w, d, e, min_1, 0, 0, 0, 0, ges, limits, single_option_representives, rain, rmv, Roses_o);	//1-min
		}

		w = 3;
		d = 2;
		e = 4;
		for (unsigned int p=1; p<=how_many_ways_of_keeping; p++) {
			*KI_decision = p;
			set_KI_table_of_choice (Qs, Moc_Quaffel, Moc_Schnatz, Moc_Klatscher, KI_decision, Field, Field_copy, m, n, geben, Opague_o, Allocation_o, Sf_permutations, ges_copy, Growth_players, number_of_players, gamemode_played, information_code, level, KI_table_of_choice, w, d, e, max_4, 0, 0, 0, 0, ges, limits, single_option_representives, rain, rmv, Roses_o);	//4-max
		}
	}

	Spielfeld_Destroy (Plus_rememory, m, 0);
	
	#ifdef VERBOSE
	printf("fill_KI_table_of_choice ok.2\n");	//test
	#endif

}

void set_KI_table_of_choice (Quidditch_setup* Qs, Moveable_objects_condition* Moc_Quaffel, Moveable_objects_condition* Moc_Schnatz, Moveable_objects_condition* Moc_Klatscher, unsigned int* KI_decision, Spielfeld Field, Spielfeld Field_copy, unsigned int m, unsigned int n, unsigned int geben, Special_Fields Opague_o, Special_Fields Allocation_o, Spielfeld Sf_permutations, unsigned int* ges_copy, Growth_Player* Growth_players, unsigned int number_of_players, unsigned int gamemode_played, unsigned int* information_code, unsigned int* level, unsigned int* KI_table_of_choice, unsigned int w, unsigned int d, unsigned int e, unsigned int exactly_number, unsigned int h, unsigned int k, unsigned int i, unsigned int j, unsigned int* ges, Limits limits, Single_option_representives single_option_representives, unsigned int rain, Realize_modifications_variables* rmv, Special_Fields Roses_o) {
	unsigned int ges_others, ges_difference, Feinstrukturkonstante_1, Feinstrukturkonstante_2, compact, g, how_many_ways_of_keeping, worth_of_turn;
	unsigned int* ges_average;
	unsigned int* position;
	
	Special_Fields Journey_o;	//empty field, no characterization
	Num_num num;
	Evolution evolution_copy;
	evolution_copy.nl = Spielfeld_Create (m, n, number_of_players);
	evolution_copy.od = Spielfeld_Create (m, n, number_of_players);

	Journey_o.characterization = 0;	//just for the function, it has no effect because of hayir
	Journey_o.field = Spielfeld_Create (m, n, number_of_players);
	num.bir = 0;
	num.iki = 0;
	num.uec = 0;
	g = 0;	//just for the function, it has no effect because of hayir

	how_many_ways_of_keeping = 1;

	worth_of_turn = 0;
	compact = 0;
	ges_others = 0;
	ges_difference = 0;
	ges_average = unsigned_int_Vektor_Create (number_of_players+1);
	position = unsigned_int_Vektor_Create (number_of_players+1);

	#ifdef VERBOSE
	printf("set_KI_table_of_choice ok.1\n");	//test
	#endif
	
	basic_development (Field, Field_copy, m, n, geben, Opague_o.field, Allocation_o, Sf_permutations, ges_copy, Growth_players, number_of_players, gamemode_played, information_code, level, w, d, e, exactly_number, evolution_copy, &num, &g, Journey_o, limits, single_option_representives, Roses_o, position, KI_decision, rain, hayir);

	if (level[geben] != Hera) {	//gamemode-specials
		realize_modifications (Qs, Moc_Schnatz, Moc_Quaffel, Moc_Klatscher, Field, Field_copy, Opague_o, Allocation_o, Sf_permutations, ges_copy, &g, m, n, geben, number_of_players, gamemode_played, level, information_code, Growth_players, Journey_o, rain, single_option_representives, rmv, limits, hayir);
		// battle (m, n, Field_copy, geben, Opague_o.field, Allocation_o, number_of_players, gamemode_played);	// Copy from realize_modifications

	}
	#ifdef VERBOSE
	printf("set_KI_table_of_choice ok.2\n");	//test
	#endif

	if (level[geben] == Yasmin) {	//future-vision
		unsigned int person;
		unsigned int* ges_copy_save;
		Spielfeld Field_copy_save;

		ges_copy_save = unsigned_int_Vektor_Create (number_of_players+1);
		Field_copy_save = Spielfeld_Create (m, n, 0);
		person = 0;

		reset_of_ges (ges_copy, number_of_players);
		ges_counter (Field_copy, m, n, ges_copy, number_of_players);	//count ges_copy after the turn of geben.

		for (unsigned int p=0; p<=number_of_players; p++) {
			ges_copy_save[p] = ges_copy[p];
		}

		// printf("ges_copy[%u]: %u \n", geben, ges_copy[geben]);	//test

		person = Nachfolger(geben, number_of_players);
		for (unsigned int i=1; i<=m-2; i++) {
			for (unsigned int j=1; j<=n-2; j++) {
				set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field_copy_save, 0, i, j, Field_copy[0][i][j]);
			}
		}

		if ((gamemode_played == Dynamic)||(gamemode_played == Arena)||(gamemode_played == Sand)||(gamemode_played == Hunt)) {
			how_many_ways_of_keeping = 2;
		} else if ((gamemode_played == Rain)||(gamemode_played == Race)||(gamemode_played == Fight)||(gamemode_played == Fall)||(gamemode_played == Collect)||(gamemode_played == Classic)) {
			how_many_ways_of_keeping = 3;
		} else if ((gamemode_played == Contact)||(gamemode_played == Quidditch)) {
			how_many_ways_of_keeping = 5;
		}

		// printf("set_KI_table_of_choice ok.3\n");	//test

		for (unsigned int p=1; p<=number_of_players-1; p++) {
			if ((ges[person] != 1010*person)&&(ges_copy[person] != 1010*person)) {
				for (unsigned int t=1; t<=how_many_ways_of_keeping; t++) {
					for (unsigned int q=Revive_; q<=Boost_; q+=10) {
						w = 3;
						d = 2;
						e = 3;

						basic_development (Field, Field_copy, m, n, person, Opague_o.field, Allocation_o, Sf_permutations, ges_copy, Growth_players, number_of_players, gamemode_played, information_code, level, w, d, e, q, evolution_copy, &num, &g, Journey_o, limits, single_option_representives, Roses_o, position, &t, rain, hayir);
		
						realize_modifications (Qs, Moc_Schnatz, Moc_Quaffel, Moc_Klatscher, Field, Field_copy, Opague_o, Allocation_o, Sf_permutations, ges_copy, &g, m, n, geben, number_of_players, gamemode_played, level, information_code, Growth_players, Journey_o, rain, single_option_representives, rmv, limits, hayir);

						// battle (m, n, Field_copy, geben, Opague_o.field, Allocation_o, number_of_players, gamemode_played);	// Copy from realize_modifications

						reset_of_ges (ges_copy, number_of_players);
						ges_counter (Field_copy, m, n, ges_copy, number_of_players);
						for (unsigned int z=1; z<=number_of_players; z++) {
							if (ges_copy[z] != 1010*z) {
								ges_average[z] += ges_copy[z];
							}
						}

						reset_ges_copy (ges_copy_save, ges_copy, number_of_players);
						reset_Field_copy (Field, Field_copy_save, Field_copy, m, n, number_of_players, geben, Opague_o.field, gamemode_played, Allocation_o);	//keep the 'real' Field_copy
					}
					for (unsigned int q=50; q<=60; q+=10) {
						unsigned int* ges_compared;
						ges_compared = unsigned_int_Vektor_Create (number_of_players+1);	//look at the function
						for (unsigned int l=1; l<=2; l++) {

							reset_ges_copy (ges_copy_save, ges_copy, number_of_players);
							w = 3;
							d = 2;
							e = 3;

							if (q+l == new_4_5) {
								w = 4;
							} else if (q+l == new_2) {
								w = 2;
							} else if (q+l == max_4) {
								e = 4;
							} else if (q+l == min_1) {
								d = 1;
							}

							basic_development (Field, Field_copy, m, n, person, Opague_o.field, Allocation_o, Sf_permutations, ges_copy, Growth_players, number_of_players, gamemode_played, information_code, level, w, d, e, q+l, evolution_copy, &num, &g, Journey_o, limits, single_option_representives, Roses_o, position, &t, rain, hayir);

							realize_modifications (Qs, Moc_Schnatz, Moc_Quaffel, Moc_Klatscher, Field, Field_copy, Opague_o, Allocation_o, Sf_permutations, ges_copy, &g, m, n, geben, number_of_players, gamemode_played, level, information_code, Growth_players, Journey_o, rain, single_option_representives, rmv, limits, hayir);

							// battle (m, n, Field_copy, geben, Opague_o.field, Allocation_o, number_of_players, gamemode_played);	// Copy from realize_modifications

							// printf("After the basic_development of person %u.\n", person);	//test
							// show_field (number_of_players, single_option_representives.invisible, level, Sf_permutations, Opague_o.field, Field_copy, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);	//test

							reset_of_ges (ges_copy, number_of_players);
							ges_counter (Field_copy, m, n, ges_copy, number_of_players);

							if (l == 1) {
								for (unsigned int z=1; z<=number_of_players; z++) {
									if (ges_copy[z] != 1010*z) {
										ges_compared[z] = ges_copy[z];
									}
								}
							} else if (l == 2) {
								for (unsigned int z=1; z<=number_of_players; z++) {
									if (ges_copy[z] != 1010*z) {
										if (z == geben) {
										ges_copy[z] = minimum (ges_compared[z], ges_copy[z]);
										} else {
										ges_copy[z] = maximum (ges_compared[z], ges_copy[z]);
										}
									}
								}
							}

							reset_Field_copy (Field, Field_copy_save, Field_copy, m, n, number_of_players, geben, Opague_o.field, gamemode_played, Allocation_o);	//keep the 'real' Field_copy
						}
						for (unsigned int z=1; z<=number_of_players; z++) {
							if (ges_copy[z] != 1010*z) {
								ges_average[z] += ges_copy[z];
							}
						}

						reset_ges_copy (ges_copy_save, ges_copy, number_of_players);
						unsigned_int_Vektor_Destroy (ges_compared);
					}
				}
			}

			person = Nachfolger(person, number_of_players);

			// printf("set_KI_table_of_choice ok.3.4 p=%u \n", p);	//test
		}

		unsigned_int_Vektor_Destroy (ges_copy_save);
		Spielfeld_Destroy (Field_copy_save, m, 0);
	}
	
	#ifdef VERBOSE
	printf("set_KI_table_of_choice ok.3.5\n");	//test
	#endif

	if (level[geben] == Yasmin) {	//averages
		reset_of_ges (ges_copy, number_of_players);
		for (unsigned int p=1; p<=number_of_players; p++) {
			ges_copy[p] = ges_average[p]/(4*((number_of_players-rmv->player_counter)-1)*how_many_ways_of_keeping);		//because i hope i used 4 additions;
		}
	} else {
		reset_of_ges (ges_copy, number_of_players);
		ges_counter (Field_copy, m, n, ges_copy, number_of_players);
	}

	ges_others = 0;
	ges_others_counter (ges_copy, &ges_others, number_of_players, geben);

	#ifdef VERBOSE
	printf("set_KI_table_of_choice ok.3.7 \n");	//test
	#endif


	if ((level[geben] == Coco)&&(ges_copy[geben] >= 5)) {	//Hyperfeinstruktur
		unsigned int edges_of_organism[4], hoch, breit;	//0=oben, 1=rechts, 2=unten, 3=links
		hoch = 0;
		breit = 0;

		find_edges_of_organism_2dim (edges_of_organism, Field_copy, geben, m, n);
		hoch = edges_of_organism[2]-edges_of_organism[0]+1;
		breit = edges_of_organism[1]-edges_of_organism[3]+1;

		// printf("hoch: %u \n", hoch);	//test
		// printf("breit: %u \n", breit);	//test

		if (((hoch*breit) > 0)&&(2*15*ges_copy[geben] > 2*maximum (hoch, breit))&&(((2*15*ges_copy[geben]-2*maximum (hoch, breit))/(hoch*breit)) >= minimum (hoch, breit))) {
			compact = ((2*15*ges_copy[geben]-2*maximum (hoch, breit))/(hoch*breit)) + 1 - minimum (hoch, breit);
		} else {
			compact = 0;
		}
		// printf("KI_table_of_choice[%u]: %u \n", 5, KI_table_of_choice[5]);	//test

		// ges_copy[geben] += KI_table_of_choice[5]; //new dimension request
	} else if ((level[geben] == Liz)&&(ges_copy[geben] >= 5)) {
		if (Liz_max > 20*how_many_ways_of_keeping) {
			ges_copy[geben] = 1;
		}
	}

	if ((level[geben] == Natalie)&&(ges_copy[geben] >= 5)) {	//Feinstruktur
		Feinstrukturkonstante_1 = 3;	//mehr
		Feinstrukturkonstante_2 = 2;	//weniger
	} else {
		Feinstrukturkonstante_1 = 0;
		Feinstrukturkonstante_2 = 0;
	}

	if (ges_copy[geben] == 0) {	//Lebenserhaltende Maßnahmen
		ges_others += 100000;
	}
	if (ges_others <= 1) {	//Killer-Instinkt im 1vs1
		ges_copy[geben] += 100000;
	}

	ges_difference = 0;
	if (ges_copy[geben] >= ges_others) {
		ges_difference = ges_copy[geben] - ges_others;
	} else {
		ges_difference = ges_others - ges_copy[geben];
	}

	#ifdef VERBOSE
	for (unsigned int p=0; p<=4; p++) {
		printf("KI_table_of_choice[%u]: %u \n", p, KI_table_of_choice[p]);	//test
	}
	printf("ges_others: %u   ges_copy[geben]: %u   ges_difference: %u	\n", ges_others, ges_copy[geben], ges_difference);	//test

	printf("set_KI_table_of_choice ok.3.8 \n");	//test
	#endif
	
	if (gamemode_played == Classic) {
		unsigned int team_indicator;
		team_indicator = geben%2;
		
		for (unsigned int i=1; i<=m-2; i++) {
			for (unsigned int j=1; j<=n-2; j++) {
				if (team_indicator == 1) {
					if (Field_copy[0][i][j] == geben) {
						worth_of_turn += 2*i;
						if (i == (m-2)) {
							worth_of_turn += 4*i*i;
						}
					}
					if ((Field_copy[0][i][j])%2 != (team_indicator+1)%2) {
						worth_of_turn += (m-2+1)-i;
					}
				} else if (team_indicator == 0) {
					if (Field_copy[0][i][j] == geben) {
						worth_of_turn += 2*(m-2-i);
						if (i == 1) {
							worth_of_turn += 4*(m-2)*(m-2);
						}
					}
					if ((Field_copy[0][i][j])%2 != (team_indicator+1)%2) {
						worth_of_turn += i;
					}
				}
			}
		}
	} else if (gamemode_played == Collect) {
		for (unsigned int q=1; q<=number_of_players-1; q++) {
			if ((Field[0][(m-1)/2][2+q+q*(n-2-4-(number_of_players-1))/number_of_players] == To_collect)&&(Field_copy[0][(m-1)/2][2+q+q*(n-2-4-(number_of_players-1))/number_of_players] == geben)) {
				worth_of_turn += 10000;
			}
		}
		if ((Field[0][(m-1)/2][2] == To_collect)&&(Field_copy[0][(m-1)/2][2] == geben)) {
			worth_of_turn += 10000;
		}
		if ((Field[0][(m-1)/2][n-3] == To_collect)&&(Field_copy[0][(m-1)/2][n-3] == geben)) {
			worth_of_turn += 10000;
		}
		for (unsigned int i=1; i<=m-2; i++) {
			for (unsigned int j=1; j<=n-2; j++) {
				worth_of_turn += i*((m-2) -i);
			}
		}
		
	} else if (gamemode_played == Fall) {
		for (unsigned int i=1; i<=m-2; i++) {
			for (unsigned int j=1; j<=n-2; j++) {
				if (Field_copy[0][i][j] == Fall_ball) {
					if (geben%2 == 0) {
						worth_of_turn += 10000*((n-2)-j);
						if (j > (n-1)/2) {
							worth_of_turn += 100*((m-2)-i);
						}
					} else if (geben%2 == 1) {
						worth_of_turn += 10000*j;
						if (j < (n-1)/2) {
							worth_of_turn += 100*((m-2)-i);
						}
					}
				} else if (Field_copy[0][i][j] == geben) {
					worth_of_turn += j*((n-2) -j);
				}
			}
		}
	} else if (gamemode_played == Hunt) {
		for (unsigned int i=1; i<=m-2; i++) {
			for (unsigned int j=1; j<=n-2; j++) {
				if (Field_copy[0][i][j] == 11) {
					worth_of_turn = 1;
					for (unsigned int p=1; p<=number_of_players; p++) {
						for (unsigned int q=0; q<=2*p-1; q++) {
							if (Field_copy[0][i-p][j-p+q] == geben) {
								worth_of_turn += number_of_players+1-p;
							}
							if (Field_copy[0][i-p+q][j+p] == geben) {
								worth_of_turn += number_of_players+1-p;
							}
							if (Field_copy[0][i+p][j+p-q] == geben) {
								worth_of_turn += number_of_players+1-p;
							}
							if (Field_copy[0][i+p-q][j-p] == geben) {
								worth_of_turn += number_of_players+1-p;
							}
							// in circles aroung the heart_block
						}
					}
					break;
				}
			}
			if (worth_of_turn != 0) {
				break;
			}
		}
	} else if (gamemode_played == Race) {
		for (unsigned int j=n-2; j>0; j--) {
			for (unsigned int i=1; i<=m-2; i++) {
				if (Field_copy[0][i][j] == geben) {
					worth_of_turn = j;
					break;
				}
			}
			if (worth_of_turn != 0) {
				break;
			}
		}
	} else if (gamemode_played == Rain) {
		for (unsigned int j=1; j<=number_of_players-1; j+=7) {
			worth_of_turn = 1;
			if (Field_copy[0][1][j] == geben) {
				worth_of_turn += 100000;
			}
			for (unsigned int p=1; p<=6; p++) {
				for (unsigned int q=0; q<=2*p-1; q++) {
					if (Field_copy[0][1+q/2][j+p] == geben) {
						worth_of_turn += number_of_players+1-p;
					}
					if (Field_copy[0][1+p][j+p-q] == geben) {
						worth_of_turn += number_of_players+1-p;
					}
					if (Field_copy[0][p-q/2][j-p] == geben) {
						worth_of_turn += number_of_players+1-p;
					}
					// in circles aroung the heart_block
				}
			}
		}
	} else if (gamemode_played == Dynamic) {
		for (unsigned int i=1; i<=m-2; i++) {
			for (unsigned int j=1; j<=n-2; j++) {
				if (Field_copy[0][i][j] == Dynamic_ball) {
					worth_of_turn = 1;
					if (geben == 1) {	//from left to right
						for (unsigned int q=1; q<=3; q++) {
							for (unsigned int p=0; p<=2*3; p++) {
								if (((j+q)<=n-2)&&((j-q)>0)&&((i-3+p)>0)&&((i-3+p)<=m-2)) {
									if (Field_copy[0][i-3+p][j-q] == geben) {
										worth_of_turn += 4-q;
									}
									if (Field_copy[0][i-3+p][j+q] == 0) {
										worth_of_turn += 4-q;
									}
								}
							}
						}
					} else if (geben == 2) {
						if ((number_of_players == 3)||(number_of_players == 4)||(number_of_players == 5)||(number_of_players == 6)||(number_of_players == 7)||(number_of_players == 8)||(number_of_players == 9)) {	//from top to bottom
							for (unsigned int q=1; q<=3; q++) {
								for (unsigned int p=0; p<=2*3; p++) {
									if (((i+q)<=m-2)&&((i-q)>0)&&((j-3+p)>0)&&((j-3+p)<=n-2)) {
										if (Field_copy[0][i-q][j-3+p] == geben) {
											worth_of_turn += 4-q;
										}
										if (Field_copy[0][i+q][j-3+p] == 0) {
											worth_of_turn += 4-q;
										}
									}
								}
							}
						} else if (number_of_players == 2) {	//from right to left
							for (unsigned int q=1; q<=3; q++) {
								for (unsigned int p=0; p<=2*3; p++) {
									if (((j+q)<=n-2)&&((j-q)>0)&&((i-3+p)>0)&&((i-3+p)<=m-2)) {
										if (Field_copy[0][i-3+p][j+q] == geben) {
											worth_of_turn += 4-q;
										}
										if (Field_copy[0][i-3+p][j-q] == 0) {
											worth_of_turn += 4-q;
										}
									}
								}
							}
						}
					} else if (geben == 4) {
						if ((number_of_players == 6)||(number_of_players == 9)) {	//from left to right
							for (unsigned int q=1; q<=3; q++) {
								for (unsigned int p=0; p<=2*3; p++) {
									if (((j+q)<=n-2)&&((j-q)>0)&&((i-3+p)>0)&&((i-3+p)<=m-2)) {
										if (Field_copy[0][i-3+p][j-q] == geben) {
											worth_of_turn += 4-q;
										}
										if (Field_copy[0][i-3+p][j+q] == 0) {
											worth_of_turn += 4-q;
										}
									}
								}
							}
						} else if ((number_of_players == 4)||(number_of_players == 5)||(number_of_players == 7)||(number_of_players == 8)) {	//from bottom to top
							for (unsigned int q=1; q<=3; q++) {
								for (unsigned int p=0; p<=2*3; p++) {
									if (((i+q)<=m-2)&&((i-q)>0)&&((j-3+p)>0)&&((j-3+p)<=n-2)) {
										if (Field_copy[0][i+q][j-3+p] == geben) {
											worth_of_turn += 4-q;
										}
										if (Field_copy[0][i-q][j-3+p] == 0) {
											worth_of_turn += 4-q;
										}
									}
								}
							}
						}
					} else if (geben == 5) {
						if ((number_of_players == 7)||(number_of_players == 8)) {	//from left to right
							for (unsigned int q=1; q<=3; q++) {
								for (unsigned int p=0; p<=2*3; p++) {
									if (((j+q)<=n-2)&&((j-q)>0)&&((i-3+p)>0)&&((i-3+p)<=m-2)) {
										if (Field_copy[0][i-3+p][j-q] == geben) {
											worth_of_turn += 4-q;
										}
										if (Field_copy[0][i-3+p][j+q] == 0) {
											worth_of_turn += 4-q;
										}
									}
								}
							}
						} else if ((number_of_players == 6)||(number_of_players == 9)) {	//from top to bottom
							for (unsigned int q=1; q<=3; q++) {
								for (unsigned int p=0; p<=2*3; p++) {
									if (((i+q)<=m-2)&&((i-q)>0)&&((j-3+p)>0)&&((j-3+p)<=n-2)) {
										if (Field_copy[0][i-q][j-3+p] == geben) {
											worth_of_turn += 4-q;
										}
										if (Field_copy[0][i+q][j-3+p] == 0) {
											worth_of_turn += 4-q;
										}
									}
								}
							}
						} else if (number_of_players == 5) {	//from bottom to top
							for (unsigned int q=1; q<=3; q++) {
								for (unsigned int p=0; p<=2*3; p++) {
									if (((i+q)<=m-2)&&((i-q)>0)&&((j-3+p)>0)&&((j-3+p)<=n-2)) {
										if (Field_copy[0][i+q][j-3+p] == geben) {
											worth_of_turn += 4-q;
										}
										if (Field_copy[0][i-q][j-3+p] == 0) {
											worth_of_turn += 4-q;
										}
									}
								}
							}
						}
					} else if (geben == 6) {
						if ((number_of_players == 6)||(number_of_players == 8)) {	//from top to bottom
							for (unsigned int q=1; q<=3; q++) {
								for (unsigned int p=0; p<=2*3; p++) {
									if (((i+q)<=m-2)&&((i-q)>0)&&((j-3+p)>0)&&((j-3+p)<=n-2)) {
										if (Field_copy[0][i-q][j-3+p] == geben) {
											worth_of_turn += 4-q;
										}
										if (Field_copy[0][i+q][j-3+p] == 0) {
											worth_of_turn += 4-q;
										}
									}
								}
							}
						} else if ((number_of_players == 7)||(number_of_players == 9)) {	//from right to left
							for (unsigned int q=1; q<=3; q++) {
								for (unsigned int p=0; p<=2*3; p++) {
									if (((j+q)<=n-2)&&((j-q)>0)&&((i-3+p)>0)&&((i-3+p)<=m-2)) {
										if (Field_copy[0][i-3+p][j+q] == geben) {
											worth_of_turn += 4-q;
										}
										if (Field_copy[0][i-3+p][j-q] == 0) {
											worth_of_turn += 4-q;
										}
									}
								}
							}
						}
					} else if (geben == 7) {
						if (number_of_players == 9) {	//from left to right
							for (unsigned int q=1; q<=3; q++) {
								for (unsigned int p=0; p<=2*3; p++) {
									if (((j+q)<=n-2)&&((j-q)>0)&&((i-3+p)>0)&&((i-3+p)<=m-2)) {
										if (Field_copy[0][i-3+p][j-q] == geben) {
											worth_of_turn += 4-q;
										}
										if (Field_copy[0][i-3+p][j+q] == 0) {
											worth_of_turn += 4-q;
										}
									}
								}
							}
						} else if (number_of_players == 8) {	//from right to left
							for (unsigned int q=1; q<=3; q++) {
								for (unsigned int p=0; p<=2*3; p++) {
									if (((j+q)<=n-2)&&((j-q)>0)&&((i-3+p)>0)&&((i-3+p)<=m-2)) {
										if (Field_copy[0][i-3+p][j+q] == geben) {
											worth_of_turn += 4-q;
										}
										if (Field_copy[0][i-3+p][j-q] == 0) {
											worth_of_turn += 4-q;
										}
									}
								}
							}
						} else if (number_of_players == 7) {	//from bottom to top
							for (unsigned int q=1; q<=3; q++) {
								for (unsigned int p=0; p<=2*3; p++) {
									if (((i+q)<=m-2)&&((i-q)>0)&&((j-3+p)>0)&&((j-3+p)<=n-2)) {
										if (Field_copy[0][i+q][j-3+p] == geben) {
											worth_of_turn += 4-q;
										}
										if (Field_copy[0][i-q][j-3+p] == 0) {
											worth_of_turn += 4-q;
										}
									}
								}
							}
						}
					} else if (geben == 8) {
						if (number_of_players == 9) {	//from top to bottom
							for (unsigned int q=1; q<=3; q++) {
								for (unsigned int p=0; p<=2*3; p++) {
									if (((i+q)<=m-2)&&((i-q)>0)&&((j-3+p)>0)&&((j-3+p)<=n-2)) {
										if (Field_copy[0][i-q][j-3+p] == geben) {
											worth_of_turn += 4-q;
										}
										if (Field_copy[0][i+q][j-3+p] == 0) {
											worth_of_turn += 4-q;
										}
									}
								}
							}
						} else if (number_of_players == 8) {	//from bottom to top
							for (unsigned int q=1; q<=3; q++) {
								for (unsigned int p=0; p<=2*3; p++) {
									if (((i+q)<=m-2)&&((i-q)>0)&&((j-3+p)>0)&&((j-3+p)<=n-2)) {
										if (Field_copy[0][i+q][j-3+p] == geben) {
											worth_of_turn += 4-q;
										}
										if (Field_copy[0][i-q][j-3+p] == 0) {
											worth_of_turn += 4-q;
										}
									}
								}
							}
						}
					} else if (geben == 9) {	//from right to left
						for (unsigned int q=1; q<=3; q++) {
							for (unsigned int p=0; p<=2*3; p++) {
								if (((j+q)<=n-2)&&((j-q)>0)&&((i-3+p)>0)&&((i-3+p)<=m-2)) {
									if (Field_copy[0][i-3+p][j+q] == geben) {
										worth_of_turn += 4-q;
									}
									if (Field_copy[0][i-3+p][j-q] == 0) {
										worth_of_turn += 4-q;
									}
								}
							}
						}
					}
					break;
				}
			}
			if (worth_of_turn != 0) {
				break;
			}
		}
	} else if (gamemode_played == Sand) {
		for (unsigned int i=1; i<=m-2; i++) {
			for (unsigned int j=1; j<=n-2; j++) {
				if (Field_copy[0][i][j] == geben) {
					worth_of_turn = m-2-i;
					break;
				}
			}
			if (worth_of_turn != 0) {
				break;
			}
		}
	} else if (gamemode_played == Ulcer) {
		for (unsigned int p=1; p<=number_of_players; p++) {
			worth_of_turn += ges_copy[p];
		}

		if (geben == 1) {
			worth_of_turn = (m-2)*(n-2) - worth_of_turn;
		}
	} else if (gamemode_played == Survive) {
		worth_of_turn = ges_copy[geben];
	}
	
	if (ges_copy[geben] == 0) {
		worth_of_turn = 0;
	}
	if (worth_of_turn >= KI_table_of_choice[6]) {
		if (((KI_table_of_choice[0] == 0)||(((ges_copy[geben] >= ges_others)&&((KI_table_of_choice[3] == daha_fazla_degil)||(ges_difference > KI_table_of_choice[4]+Feinstrukturkonstante_1)))||((ges_copy[geben] < ges_others)&&(ges_difference+Feinstrukturkonstante_2 < KI_table_of_choice[4])&&(KI_table_of_choice[3] == daha_fazla_degil)))||((level[geben] == Jill)&&(ges_others < KI_table_of_choice[7]))||((level[geben] == Coco)&&(compact > KI_table_of_choice[7]+2)))&&((level[geben] != Uma)||((level[geben] == Uma)&&(accepted_or_not(exactly_number, ges, geben, how_many_ways_of_keeping) == evet)))) {
			update_KI_table_of_choice (KI_table_of_choice, exactly_number, h, k, i, j, ges_copy, ges_others, ges_difference, KI_decision, worth_of_turn, geben, level, compact);
		}
	}
	
	
	#ifdef VERBOSE
	printf("set_KI_table_of_choice ok.4 \n");	//test
	#endif
	
	// for (unsigned int p=0; p<=4; p++) {
		// printf("KI_table_of_choice[%u]: %u \n", p, KI_table_of_choice[p]);	//test
	// }
	// printf("\n");	//test
	if (level[geben] == Liz) {
		Liz_max += 1;
	}

	synchronisation_Field_copy (Field, Field_copy, m, n, number_of_players, geben, Opague_o.field, gamemode_played, Allocation_o);
	synchronisation_ges_copy (ges_copy, number_of_players, ges);

	Spielfeld_Destroy (evolution_copy.nl, m, number_of_players);
	Spielfeld_Destroy (evolution_copy.od, m, number_of_players);
	Spielfeld_Destroy (Journey_o.field, m, number_of_players);
	unsigned_int_Vektor_Destroy (ges_average);
	unsigned_int_Vektor_Destroy (position);
	
	#ifdef VERBOSE
	printf("set_KI_table_of_choice ok.5 \n");	//test
	#endif

}

void update_KI_table_of_choice (unsigned int* KI_table_of_choice, unsigned int exactly_number, unsigned int h, unsigned int k, unsigned int i, unsigned int j, unsigned int* ges_copy, unsigned int ges_others, unsigned int ges_difference, unsigned int* KI_decision, unsigned int worth_of_turn, unsigned int geben, unsigned int* level, unsigned int compact) {
	
	// printf("update_KI_table_of_choice ok.1 \n");	//test

	KI_table_of_choice[0] = exactly_number;

	if ((exactly_number == Plus_)||(exactly_number == Destroy_)) {
		KI_table_of_choice[1] = 0;			//own squares
		KI_table_of_choice[2] = 100*h+k;	//other squares
	
	} else if (exactly_number == Minus_) {
		KI_table_of_choice[1] = 100*i+j;
		KI_table_of_choice[2] = 0;
	
	} else if ((exactly_number == Move_2)||(exactly_number == Change_)||(exactly_number == Move_4)) {
		KI_table_of_choice[1] = 100*i+j;
		KI_table_of_choice[2] = 100*h+k;
	
	} else if ((exactly_number == Revive_)||(exactly_number == Boost_)||(exactly_number == new_2)||(exactly_number == new_4_5)||(exactly_number == min_1)||(exactly_number == max_4)) {
		KI_table_of_choice[1] = 0;
		KI_table_of_choice[2] = 0;
	
	}

	if (ges_copy[geben] >= ges_others) {
		KI_table_of_choice[3] = daha_fazla;
	} else {
		KI_table_of_choice[3] = daha_fazla_degil;
	}

	KI_table_of_choice[4] = ges_difference;
	KI_table_of_choice[5] = *KI_decision;

	KI_table_of_choice[6] = worth_of_turn;

	if (level[geben] == Jill) {
		KI_table_of_choice[7] = ges_others;
	} else if (level[geben] == Coco) {
		KI_table_of_choice[7] = compact;
	}

	// printf("update_KI_table_of_choice ok.2 \n");	//test
	
}

void decision_max_maker (unsigned int gamemode_played, unsigned int geben, unsigned int* decision_max) {	//checklist
	if ((gamemode_played == Dynamic)||(gamemode_played == Arena)||(gamemode_played == Sand)) {
		*decision_max = 2;
	} else if ((gamemode_played == Hunt)&&(geben != 1)) {
		*decision_max = 2;
	} else if ((gamemode_played == Rain)||(gamemode_played == Race)||(gamemode_played == Fight)||(gamemode_played == Fall)||(gamemode_played == Collect)) {
		*decision_max = 3;
	} else if ((gamemode_played == Contact)||(gamemode_played == Quidditch)) {
		*decision_max = 5;
	} else if (gamemode_played == Classic) {
		*decision_max = 3;
	}
}

unsigned int get_how_many_ways_of_keeping (unsigned int gamemode_played) {	//checklist
	
	unsigned int how_many_ways_of_keeping;
	
	if ((gamemode_played == Dynamic)||(gamemode_played == Arena)||(gamemode_played == Sand)||(gamemode_played == Hunt)) {
		how_many_ways_of_keeping = 2;
	} else if ((gamemode_played == Rain)||(gamemode_played == Race)||(gamemode_played == Fight)||(gamemode_played == Fall)||(gamemode_played == Collect)||(gamemode_played == Classic)||(gamemode_played == Duell)) {
		how_many_ways_of_keeping = 3;
	} else if ((gamemode_played == Contact)||(gamemode_played == Quidditch)) {
		how_many_ways_of_keeping = 5;
	}
	
	return how_many_ways_of_keeping;
}

unsigned int accepted_or_not (unsigned int number, unsigned int* ges, unsigned int geben, unsigned int how_many_ways_of_keeping) {
	unsigned int approx_n, answer;

	approx_n = 0;
	answer = 0;
	
	#ifdef VERBOSE
	printf("accepted_or_not ok.1 \n");	//test
	#endif
	
	if ((number/10 == 3)||(number/10 == 5)||(number/10 == 6)) {
		approx_n = 2*how_many_ways_of_keeping*how_many_ways_of_keeping;
	} else if (number/10 == 1) {
		approx_n = (7*ges[geben]+1)*how_many_ways_of_keeping*how_many_ways_of_keeping;
	} else if ((number/10 == 2)||(number/10 == 4)) {
		approx_n = (3*ges[geben]+1)*how_many_ways_of_keeping*how_many_ways_of_keeping;
	}

	answer = Zufall(1, approx_n);

	if (1.0*answer <= sqrt(approx_n)) {
		answer = evet;
	} else {
		answer = hayir;
	}

	// printf("Accepted number %u:	%u \n", number, answer);	//test
	// printf("approx_n %u:	\n", approx_n);

	#ifdef VERBOSE
	printf("accepted_or_not ok.2 \n");	//test
	#endif
	return answer;
}

void dimension_of (unsigned int* level, unsigned int* dimension, unsigned int geben) {

	// printf("dimension_of ok.1\n");	//test

	if ((level[geben] == Coco)||(level[geben] == Jill)) {
		*dimension = 8;
	} else {
		*dimension = 7;
	}
}

void is_it_necessary (unsigned int* level, unsigned int* ges, unsigned int* necessary, unsigned int geben, unsigned int number_of_players) {
	if (ges[Nachfolger(geben, number_of_players)] == 1010*Nachfolger(geben, number_of_players)) {
		is_it_necessary (level, ges, necessary, Nachfolger(geben, number_of_players), number_of_players);
	} else if (level[Nachfolger(geben, number_of_players)] != human) {
		*necessary = 1;
	}
}
