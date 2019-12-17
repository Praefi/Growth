
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
#include "Growth_all_Vektor.h"
#include "Growth_all_actions.h"
#include "Growth_all_set.h"
#include "Growth_all_show.h"
#include "Growth_all_visual.h"
#include "Growth_all_opague.h"
#include "Growth_all_get.h"
#include "Growth_all_gamemode_specials.h"
#include "Growth_all_options_specials.h"
#include "Growth_all_Development.h"


void basic_development (Spielfeld Field, Spielfeld Spiel, unsigned int m, unsigned int n, unsigned int geben, Spielfeld Opague_o_field, Special_Fields_Collector* sfc, Spielfeld Sf_permutations, unsigned int* ges_copy, Growth_Player* Growth_players, unsigned int number_of_players, unsigned int gamemode_played, unsigned int* information_code, unsigned int* level, unsigned int w, unsigned int d, unsigned int e, unsigned int exactly_number, Evolution evolution, Num_num* num, unsigned int* g, Special_Fields Journey_o, Limits limits, Single_option_representives single_option_representives, Special_Fields Roses_o, unsigned int* position, unsigned int* KI_decision, unsigned int rain, unsigned int real) {
	Spielfeld temp;
	unsigned int boost_hunt_activator, precounter;	//Hunt
	unsigned int ent, count_new;	// imitates limits, counts the squares
	unsigned int zeitgewinner;	//if you can't hold anything, you are winning time

	ent = 0;
	count_new = 0;
	zeitgewinner = 0;

	boost_hunt_activator = 0;
	precounter = 0;
	temp = Spielfeld_Create (m, n, 0);

	if (exactly_number == Boost_) {
		if ((gamemode_played == Hunt)&&(geben == 1)) {
			boost_hunt_activator = 1;
		} else {
			Boost (Spiel, geben, Field, m, n, temp, gamemode_played, Opague_o_field, sfc, number_of_players);
		}
	}

	#ifdef VERBOSE
	printf("basic_development ok.1\n");	//test
	#endif

	new_life (Spiel, Field, m, n, w, gamemode_played, information_code, geben, evolution, Opague_o_field, sfc, number_of_players);

	num->bir = 0;
	for (unsigned int i=1; i<m-1; i+=1){
		for (unsigned int j=1; j<n-1; j+=1){
			if (evolution.nl[geben][i][j] == geben){
				num->bir += 1;
			}
		}
	}

	// printf("basic_development ok.1.1\n");	//test

	if ((gamemode_played != Hunt)||(geben != 1)) {	//wegen hunted one, if (geben != 1)
		if (exactly_number == Boost_){
			for (unsigned int i=1; i<m-1; i+=1){
				for (unsigned int j=1; j<n-1; j+=1){
					if (gamemode_played == Rain) {
						if (temp[0][i][j] == Raindrop){
							set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Spiel, 0, i, j, 0);
						}
					} else {
						if (temp[0][i][j] != 0){
							set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Spiel, 0, i, j, temp[0][i][j]);
						}
					}
				}
			}
		}
	}

	if (real == evet) {
		if (gamemode_played == Hunt) {
			precounter = 0;
			for (unsigned int i=1; i<m-1; i+=1){
				for (unsigned int j=1; j<n-1; j+=1){
					if (Field[0][i][j] == 11){
						if (evolution.nl[geben][i][j-1] > 1) {
							printf (" Sieg: Spieler %u \n", evolution.nl[geben][i][j-1]);
							precounter += 1;
						}
						if (evolution.nl[geben][i][j+1] > 1) {
							if (precounter == 0) {
								printf (" Sieg: Spieler %u \n", evolution.nl[geben][i][j+1]);
							}
							precounter += 1;
						}
						if (evolution.nl[geben][i-1][j] > 1) {
							if (precounter == 0) {
								printf (" Sieg: Spieler %u \n", evolution.nl[geben][i-1][j]);
							}
							precounter += 1;
						}
						if (evolution.nl[geben][i+1][j] > 1) {
							if (precounter == 0) {
								printf (" Sieg: Spieler %u \n", evolution.nl[geben][i+1][j]);
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
						if (evolution.nl[geben][i][j] == geben) {
							set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, i, j, geben);
						}
					}
				}
				show_field (number_of_players, single_option_representives.invisible, level, Sf_permutations, Opague_o_field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, sfc);
				*g = 0;
			}
		}
	}

	// printf("basic_development ok.1.2\n");	//test

	Spielfeld_Destroy (temp, m, 0); // ab jetzt nicht mehr verwendbar

	// printf("basic_development ok.2\n");	//test

	old_dying (Spiel, Field, m, n, d, e, gamemode_played, information_code, geben, evolution.od, w, sfc, Opague_o_field, number_of_players, Roses_o);

	if ((boost_hunt_activator == 1)&&(gamemode_played == Hunt)&&(geben == 1)) {
		for (unsigned int i=1; i<m-1; i+=1){
			for (unsigned int j=1; j<n-1; j+=1){
				if (Spiel[0][i][j] == 11){
					set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, evolution.od, geben, i-1, j, 0);
					set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, evolution.od, geben, i, j-1, 0);
					set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, evolution.od, geben, i+1, j, 0);
					set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, evolution.od, geben, i, j+1, 0);

					boost_hunt_activator = 0;
					break;	//because i found the unique value
				}
			}
			if (boost_hunt_activator == 0) {
				break;	//because i found the unique value
			}
		}
	}

	if (real == evet) {
		if (Journey_o.characterization != 0){
			unsigned int journey_max, temp_limits_at_all;
			journey_max = 0;
			temp_limits_at_all = 0;

			if (limits.at_all == 0) {
				limits.at_all = 25;
				temp_limits_at_all = 1;
			}

			for (unsigned int i=1; i<m-1; i+=1){
				for (unsigned int j=1; j<n-1; j+=1){
					if (Journey_o.field[0][i][j] == geben){
						journey_max += 1;
					}
				}
			}

			// printf("Spieler %u: %u Steine in Journey_o.field \n", geben, journey_max);	//test

			for (unsigned int i=1; i<m-1; i+=1){
				for (unsigned int j=1; j<n-1; j+=1){
					if ((evolution.od[geben][i][j] == 101*geben) && (Journey_o.field[0][i][j] == 0) && (journey_max >= limits.at_all)){

						// show_field (number_of_players, single_option_representives.invisible, level, Sf_permutations, Opague_o_field, Journey_o.field, m, n, gamemode_played, information_code, geben, Growth_players, 0, sfc);	//test

						for (unsigned int p=0; p<=1; p++) {
							for (unsigned int q=0; q<=(((minimum(m, n)-2)-1)/2)*2; q++) {
								if (q%2 == 0) {
									for (unsigned int o=1+(q/2); o<(n-1)-(q/2); o+=1){
										if ((Journey_o.field[0][1+(q/2)][o] == geben)&&((1+(q/2)+o)%2 == p)){
											set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Journey_o.field, 0, 1+(q/2), o, 0);
											journey_max -= 1;
											if (journey_max < limits.at_all){
												break;
											}
										}
										if ((Journey_o.field[0][(m-2)-(q/2)][o] == geben)&&(((m-2)-(q/2)+o)%2 == p)){
											set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Journey_o.field, 0, (m-2)-(q/2), o, 0);
											journey_max -= 1;
											if (journey_max < limits.at_all){
												break;
											}
										}
									}
								} else if (q%2 == 1) {
									for (unsigned int u=1+((q+1)/2); u<(m-1)-((q+1)/2); u+=1){
										if ((Journey_o.field[0][u][1+(q/2)] == geben)&&((1+(q/2)+u)%2 == p)){
											set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Journey_o.field, 0, u, 1+(q/2), 0);
											journey_max -= 1;
											if (journey_max < limits.at_all){
												break;
											}
										}
										if ((Journey_o.field[0][u][(n-2)-(q/2)] == geben)&&(((n-2)-(q/2)+u)%2 == p)){
											set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Journey_o.field, 0, u, (n-2)-(q/2), 0);
											journey_max -= 1;
											if (journey_max < limits.at_all){
												break;
											}
										}
									}
								}
								if (journey_max < limits.at_all){
									break;
								}
							}
							if (journey_max < limits.at_all){
								break;
							}
						}
					}
					if ((evolution.od[geben][i][j] == 101*geben) && (Journey_o.field[0][i][j] == 0) && (journey_max < limits.at_all)){
						set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Journey_o.field, 0, i, j, geben);
						journey_max += 1;
					}
				}
			}

			// printf("Spieler %u: %u Steine in Journey_o.field \n", geben, journey_max);	//test

			journey_max = 0;

			if (temp_limits_at_all == 1) {
				limits.at_all = 0;
			}
		}
	}

	if (exactly_number == Revive_) {
		Revive (Spiel, m, n, evolution.od, Field, geben, sfc, Opague_o_field, number_of_players, gamemode_played);
	}

	num->iki = 0;
	for (unsigned int i=1; i<m-1; i+=1){
		for (unsigned int j=1; j<n-1; j+=1){
			if (evolution.od[geben][i][j] == 101*geben){
				num->iki += 1;
			}
		}
	}

	count_new = 0;

	for (unsigned int i=1; i<m-1; i+=1){
		for (unsigned int j=1; j<n-1; j+=1){
			if (evolution.nl[geben][i][j] == geben){
				count_new += 1;
			}
		}
	}

	ent = limits.yeni;

	for (unsigned int i=1; i<m-1; i+=1){
		for (unsigned int j=1; j<n-1; j+=1){
			if ((Spiel[0][i][j] == geben) && (evolution.od[geben][i][j] == 0)){
				zeitgewinner += 1;
			}
		}
	}

	//printf("	ent: %u \n ", ent);
	if ((gamemode_played == Hunt)&&(geben == 1)) {
		ent = (ent + (number_of_players-3));
	}

	if ((count_new > limits.yeni)&&(single_option_representives.inverted == 0)&&(single_option_representives.addition == 0)&&(single_option_representives.intensity_loss_per_line_multiplication == 0)&&(single_option_representives.spreading == 0)){		//Abfrage auf max. limits.yeni neue Steine,
		if ((gamemode_played != Ulcer)&&(gamemode_played != Survive)) {
			Having_too_much (KI_decision, ent, count_new, m, n, evolution, limits, zeitgewinner, Spiel, w, d, e, geben, position, gamemode_played, number_of_players, rain, Opague_o_field, sfc, level, real);
		} else {
			count_new = 0;
		}

	}
	ent = 0;
	count_new = 0;

	num->uec = 0;
	for (unsigned int i=1; i<m-1; i+=1){
		for (unsigned int j=1; j<n-1; j+=1){
			if (((Spiel[0][i][j] == geben) && (((evolution.od[geben][i][j] == 0)&&(sfc->Allocation_o.characterization == 0))||(sfc->Allocation_o.field[0][i][j] > sfc->Allocation_o.field[1][i][j]))) || (evolution.nl[geben][i][j] == geben)){
				count_new += 1;
				num->uec += 1;
			}
		}
	}

	if ((gamemode_played == Hunt)&&(geben == 1)) {	//count the heart, if geben == 1
		count_new += 1;
		num->uec += 1;
	}

	ent = limits.at_all;

	if ((gamemode_played == Hunt)&&(geben == 1)) {
		ent = (ent + 2* (number_of_players-3));
	}

	if ((count_new > ent)&&(single_option_representives.inverted == 0)&&(single_option_representives.addition == 0)&&(single_option_representives.intensity_loss_per_line_multiplication == 0)&&(single_option_representives.spreading == 0)){		//Abfrage auf insgesamt max. limits.at_all Steine
		if ((gamemode_played != Contact)&&(gamemode_played != Ulcer)&&(gamemode_played != Survive)) {
			Having_too_much (KI_decision, ent, count_new, m, n, evolution, limits, zeitgewinner, Spiel, w, d, e, geben, position, gamemode_played, number_of_players, rain, Opague_o_field, sfc, level, real);
		} else {
			count_new = 0;
		}

	}

	zeitgewinner = 0;
	ent = 0;

	if (gamemode_played == Fall) {
		touch (Spiel, Field, m, n, geben, evolution.nl, sfc, Opague_o_field, number_of_players, gamemode_played);
	}

	// printf("basic_development ok.3\n");	//test

	change (Spiel, level, Sf_permutations, Field, evolution, m, n, gamemode_played, number_of_players, ges_copy, geben, sfc, Opague_o_field, information_code, Growth_players, single_option_representives, Roses_o);

	#ifdef VERBOSE
	printf("basic_development ok.4\n");	//test
	#endif

}


void new_life (Spielfeld Spiel, Spielfeld Field, unsigned int m, unsigned int n, unsigned int w, unsigned int gamemode_played, unsigned int* information_code, unsigned int geben, Evolution evolution, Spielfeld Opague_o_field, Special_Fields_Collector* sfc, unsigned int number_of_players){	//checklist
	Spielfeld temp_new_life;
	unsigned int a, inhi;

	#ifdef VERBOSE
	printf("	new_life_ok.0 \n");	//test
	#endif

	temp_new_life = Spielfeld_Create (m, n, 0);		//inhibitor in information_code[1], ability in information_code[0]
	a = 0;
	inhi = 0;

	// printf("	w: %u\n", w);	//test

	if (gamemode_played != Race) {
		for (unsigned int i=1; i<m-1; i+=1){
			for (unsigned int j=1; j<n-1; j+=1){
				if ((Spiel[0][i][j] == 0)||((Spiel[0][i][j] == Traps)&&(gamemode_played == Survive))||((gamemode_played == Duell)&&(Spiel[0][i][j] != geben))) {	//Traps only used in Survive
					for (unsigned int h=i-1; h<=i+1; h+=1){
						for (unsigned int k=j-1; k<=j+1; k+=1){
							if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
								if (((gamemode_played != Hunt)||(geben != 1))&&(gamemode_played != Arena)) {
									if (Spiel[0][h][k] == geben){
										a+=1;
									}
								} else if ((gamemode_played == Hunt)&&(geben == 1)) {
									if ((Spiel[0][h][k] == 1)||(Spiel[0][h][k] == 11)){
										a+=1;
									}
								} else if (gamemode_played == Arena) {
									if (Spiel[0][h][k] == geben){
										a+=1;
									}
									if ((information_code[1] != 0)&&(information_code[1] != 100)&&(Spiel[0][h][k] == information_code[1])&&(information_code[0] != 6)&&(information_code[0] != 5)) {
										inhi += 1;
									}
								}
							}
						}
					}				//w=3, w=2, w=4
					if (gamemode_played != Arena) {
						if (w == 4){
							if ((a == w) || (a == w+1)){
								set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, temp_new_life, 0, i, j, geben);
							}
						} else {
							if (a == w){
								set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, temp_new_life, 0, i, j, geben);
							}
						}
						a = 0;
					} else if (gamemode_played == Arena) {
						if (inhi != 3) {
							if (information_code[0] == 1) {
								if (w == 2){
									if ((a == w) || (a == w+1)){
										set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, temp_new_life, 0, i, j, geben);
									}
								} else {
									if (a == w){
										if (w == 1) {
											set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, temp_new_life, 0, i, j, geben);
										} else if (w == 0) {
											for (unsigned int h=i-1; h<=i+1; h+=1){
												for (unsigned int k=j-1; k<=j+1; k+=1){
													if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
														if (Spiel[0][h][k] != 0) {
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
												set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, temp_new_life, 0, i, j, geben);
											}
										}
									}
								}
							} else if (information_code[0] == 2) {
								if (w == 3){
									if ((a == w) || (a == w+1)){
										set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, temp_new_life, 0, i, j, geben);
									}
								} else {
									if (a == w){
										set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, temp_new_life, 0, i, j, geben);
									}
								}
							} else if (information_code[0] == 3) {
								if (w == 5){
									if ((a == w) || (a == w+1)){
										set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, temp_new_life, 0, i, j, geben);
									}
								} else {
									if (a == w){
										set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, temp_new_life, 0, i, j, geben);
									}
								}
							} else if (information_code[0] == 4) {	//Cornered
								if (w == 4){
									if ((a == w) || (a == w+1)){
										set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, temp_new_life, 0, i, j, geben);
									}
								} else {
									if (a == w){
										set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, temp_new_life, 0, i, j, geben);
									}  else if ((a == (w-1))&&((j == (n-2))||(j == 1)||(i == (m-2))||(i == 1))) {
										set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, temp_new_life, 0, i, j, geben);
									}
								}
							} else {
								if (w == 4){
									if ((a == w) || (a == w+1)){
										set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, temp_new_life, 0, i, j, geben);
									}
								} else {
									if (a == w){
										set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, temp_new_life, 0, i, j, geben);
									}
								}
							}
						}
						a = 0;
						inhi = 0;
					}

				}
				if ((gamemode_played == Ulcer)&&((Spiel[0][i][j] == 2)&&(geben == 1))) {
					for (unsigned int h=i-1; h<=i+1; h+=1){
						for (unsigned int k=j-1; k<=j+1; k+=1){
							if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
								if (Spiel[0][h][k] == geben){
									a+=1;
								}
							}
						}
					}
					if (w == 4){
						if ((a == w) || (a == w+1)){
							set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, temp_new_life, 0, i, j, geben);
						}
					} else {
						if (a == w){
							set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, temp_new_life, 0, i, j, geben);
						}
					}
					a = 0;
				}
			}
		}
		if ((gamemode_played == Survive)&&(information_code[1] >= 1)) {	//with Traps?
			for (unsigned int i=1; i<m-1; i+=1){
				for (unsigned int j=1; j<n-1; j+=1){

					if ((Spiel[0][i][j] == Traps)&&(temp_new_life[0][i][j] == geben)) {

						// printf("(sfc->Allocation_o.characterization+1)/2: %u \n", (sfc->Allocation_o.characterization+1)/2);	//test

						for (unsigned int h=i-1; h<=i+1; h+=1){
							for (unsigned int k=j-1; k<=j+1; k+=1){
								if (((h+k)%2 == (i+j+1)%2)||((k == j)&&(h == i))) {
									if (Spiel[0][h][k] == geben) {
										set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, evolution.od, geben, h, k, 101*geben);
										if (sfc->Allocation_o.characterization != 0) {
											set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, sfc->Allocation_o.field, 1, h, k, (sfc->Allocation_o.characterization+1/2));	//Half of allocation-max
										}
									} else {
										set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Spiel, 0, h, k, 0);
									}
									set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, temp_new_life, 0, h, k, 0);
								}
							}
						}
					}
				}
			}
		}

	} else if (gamemode_played == Race) {
		for (unsigned int i=(geben-1)*((m-2+1)/number_of_players)+1; i<=geben*((m-2+1)/number_of_players); i+=1){
			for (unsigned int j=1; j<n-1; j+=1){
				if (Spiel[0][i][j] == 0) {
					for (unsigned int h=i-1; h<=i+1; h+=1){
						for (unsigned int k=j-1; k<=j+1; k+=1){
							if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))&&(i<(m-1))&&(i>0)){
								if (Spiel[0][h][k] == geben){
									a+=1;
								}
							}
						}
					}				//w=3, w=2, w=4
					if(w == 4){
						if ((a == w) || (a == w+1) ){
							set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, temp_new_life, 0, i, j, geben);
						}
					} else {
						if (a == w){
							set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, temp_new_life, 0, i, j, geben);
						}
					}
					a = 0;

				}
			}
		}
	}

	// printf("almost end of new_life \n");	//test
	
	for (unsigned int i=1; i<m-1; i+=1){
		for (unsigned int j=1; j<n-1; j+=1){
			if (temp_new_life[0][i][j] == geben) {
				set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, evolution.nl, geben, i, j, geben);
			}
		}
	}

	Spielfeld_Destroy (temp_new_life, m, 0);

	#ifdef VERBOSE
	printf("end of new_life \n");	//test
	#endif

}

void old_dying (Spielfeld Spiel, Spielfeld Field, unsigned int m, unsigned int n, unsigned int d, unsigned int e, unsigned int gamemode_played, unsigned int* information_code, unsigned int geben, Spielfeld evolution_od, unsigned int w, Special_Fields_Collector* sfc, Spielfeld Opague_o_field, unsigned int number_of_players, Special_Fields Roses_o){	//checklist
	Spielfeld temp_old_dying;
	unsigned int a, e_down, d_up;

	temp_old_dying = Spielfeld_Create (m, n, 0);
	a = 0;
	e_down = 0;
	d_up = 0;

	#ifdef VERBOSE
	printf("old_dying ok.1 \n");	//test
	#endif

	for (unsigned int i=1; i<m-1; i+=1){
		for (unsigned int j=1; j<n-1; j+=1){
			if (Spiel[0][i][j] == geben) {
				if (gamemode_played == Arena) {
					if ((information_code[2] != 0)&&(information_code[2] != 100)&&(information_code[0] != 7)&&(information_code[0] != 6)) {
						if ((Spiel[0][i+1][j] == information_code[2])||(Spiel[0][i][j-1] == information_code[2])||(Spiel[0][i][j+1] == information_code[2])||(Spiel[0][i-1][j] == information_code[2])) {
							d_up = 1;
							d += 1;
						}
					}
					if ((information_code[3] != 0)&&(information_code[3] != 100)&&(information_code[0] != 8)&&(information_code[0] != 6)) {	//wenn du kein Shield hast oder die Angriffseigenschaft selbst besitzt.
						if ((Spiel[0][i+1][j] == information_code[3])||(Spiel[0][i][j-1] == information_code[3])||(Spiel[0][i][j+1] == information_code[3])||(Spiel[0][i-1][j] == information_code[3])) {
							e_down = 1;
							e -= 1;
						}
					}
				}

				// printf("old_dying ok.2 \n");	//test

				for (unsigned int h=i-1; h<=i+1; h+=1){
					for (unsigned int k=j-1; k<=j+1; k+=1){
						if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
							if (((gamemode_played != Hunt)||(geben != 1))&&(gamemode_played != Arena)) {
								if (Spiel[0][h][k] == geben){
									a+=1;
								}
							} else if ((gamemode_played == Hunt)&&(geben == 1)) {
								if ((Spiel[0][h][k] == 1)||(Spiel[0][h][k] == 11)){
									a+=1;
								}
							} else if (gamemode_played == Arena) {
								if (Spiel[0][h][k] == geben){
									a+=1;
								}
							}
						}
					}
				}
				
				// printf("	a=%u	w=%u	d=%u	e=%u	\n", a, w, d, e);	//test
				
				if ((gamemode_played != Arena)&&(gamemode_played != Ulcer)) {
					if ((a < d+1) || (a > e+1)){		//d=2, d=1, e=3, e=4, +1 wegen des Steines selbst, da er mitgezählt wird
						set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, temp_old_dying, 0, i, j, 101*geben);		//Code für das Eleminieren
						if (Roses_o.characterization != 0) {
							set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Roses_o.field, 0, i, j, Roses_0+(a-1));	//saves the Roses_(a-1)
						}
					}

					if (sfc->Allocation_o.characterization != 0) {
						if (w == 4) {
							if ((a == w+1)||(a == w+2)) {
								if (sfc->Allocation_o.field[0][i][j] < sfc->Allocation_o.characterization) {
									sfc->Allocation_o.field[0][i][j] += 1;
								}
							}
						} else {
							if (a == w+1) {
								if (sfc->Allocation_o.field[0][i][j] < sfc->Allocation_o.characterization) {
									sfc->Allocation_o.field[0][i][j] += 1;
								}
							}
						}

						if (a < d+1){
							set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, sfc->Allocation_o.field, 1, i, j, (d+1-a));
						} else if (a > e+1) {
							set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, sfc->Allocation_o.field, 1, i, j, (a-e-1));
						}
					}

					a = 0;
				} else if (gamemode_played == Ulcer) {
					if ((a < d+1) || (a > e+1)){		//d=2, d=1, e=3, e=4, +1 wegen des Steines selbst, da er mitgezählt wird
						set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, temp_old_dying, 0, i, j, 101*geben);		//Code für das Eleminieren
						if (Roses_o.characterization != 0) {
							set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Roses_o.field, 0, i, j, Roses_0+(a-1));	//saves the Roses_(a-1)
						}
					}

					if (sfc->Allocation_o.characterization != 0) {
						if (e-d == 1) {	//e und d nicht verändert
							if (w == e+1) {
								if ((a == w+1)||(a == w+2)) {
									if (sfc->Allocation_o.field[0][i][j] < sfc->Allocation_o.characterization) {
										sfc->Allocation_o.field[0][i][j] += 1;
									}
								}
							} else {
								if (a == w+1) {
									if (sfc->Allocation_o.field[0][i][j] < sfc->Allocation_o.characterization) {
										sfc->Allocation_o.field[0][i][j] += 1;
									}
								}
							}
						} else if (e-d == 2) {	//e oder d verändert, also w nicht
							if (a == w+1) {
								if (sfc->Allocation_o.field[0][i][j] < sfc->Allocation_o.characterization) {
									sfc->Allocation_o.field[0][i][j] += 1;
								}
							}
						}

						if (a < d+1){
							set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, sfc->Allocation_o.field, 1, i, j, (d+1-a));
						} else if (a > e+1) {
							set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, sfc->Allocation_o.field, 1, i, j, (a-e-1));
						}
					}

					a = 0;
				} else if (gamemode_played == Arena) {
					if ((d == 11)||(d == 10)) {
						d = 0;
						d_up += 10;
					}

					if ((a < d+1) || (a > e+1)){
						set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, temp_old_dying, 0, i, j, 101*geben);
						if (Roses_o.characterization != 0) {
							set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Roses_o.field, 0, i, j, Roses_0+(a-1));	//saves the Roses_(a-1)
						}
					}
					if (sfc->Allocation_o.characterization != 0) {

						if (a < d+1){
							set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, sfc->Allocation_o.field, 1, i, j, (d+1-a));
						} else if (a > e+1) {
							set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, sfc->Allocation_o.field, 1, i, j, (a-e-1));
						}
					}

					if ((d_up == 1)||(d_up == 11)) {
						d -= 1;
					}
					if ((d_up == 10)||(d_up == 11)) {
						d = 10;	//für den nächsten Eintrag
					}
					if (e_down == 1) {
						e += 1;
					}
					d_up = 0;
					e_down = 0;	//d und e bereinigt

					if (sfc->Allocation_o.characterization != 0) {

						if (information_code[0] == 3) {	//Anti
							if (w == 5) {
								if ((a == w+1)||(a == w+2)) {
									if (sfc->Allocation_o.field[0][i][j] < sfc->Allocation_o.characterization) {
										sfc->Allocation_o.field[0][i][j] += 1;
									}
								}
							} else {
								if (a == w+1) {
									if (sfc->Allocation_o.field[0][i][j] < sfc->Allocation_o.characterization) {
										sfc->Allocation_o.field[0][i][j] += 1;
									}
								}
							}
						} else if (e-d == 1) {	//e und d nicht verändert (or ultra_light with changed d)
							if (w == e+1) {
								if ((a == w+1)||(a == w+2)) {
									if (sfc->Allocation_o.field[0][i][j] < sfc->Allocation_o.characterization) {
										sfc->Allocation_o.field[0][i][j] += 1;
									}
								} else if ((information_code[0] == 4)&&((a == w)||(a == w+1))&&((j == (n-2))||(j == 1)||(i == (m-2))||(i == 1))) {
									if (sfc->Allocation_o.field[0][i][j] < sfc->Allocation_o.characterization) {
										sfc->Allocation_o.field[0][i][j] += 1;
									}
								}
							} else {
								if (a == w+1) {
									if (sfc->Allocation_o.field[0][i][j] < sfc->Allocation_o.characterization) {
										sfc->Allocation_o.field[0][i][j] += 1;
									}
								} else if ((information_code[0] == 4)&&(a == w)&&((j == (n-2))||(j == 1)||(i == (m-2))||(i == 1))) {
									if (sfc->Allocation_o.field[0][i][j] < sfc->Allocation_o.characterization) {
										sfc->Allocation_o.field[0][i][j] += 1;
									}
								}
							}
						} else if (e-d == 2) {	//e oder d verändert, also w nicht
							if (a == w+1) {
								if (sfc->Allocation_o.field[0][i][j] < sfc->Allocation_o.characterization) {
									sfc->Allocation_o.field[0][i][j] += 1;
								}
							} else if ((information_code[0] == 4)&&(a == w)&&((j == (n-2))||(j == 1)||(i == (m-2))||(i == 1))) {
								if (sfc->Allocation_o.field[0][i][j] < sfc->Allocation_o.characterization) {
									sfc->Allocation_o.field[0][i][j] += 1;
								}
							}
						}
					}

					a = 0;
				}
			}
		}
	}

	// printf("old_dying ok.3 \n");	//test

	for (unsigned int i=1; i<m-1; i+=1){
		for (unsigned int j=1; j<n-1; j+=1){
			if (temp_old_dying[0][i][j] == 101*geben) {
				set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, evolution_od, geben, i, j, 101*geben);
				if (gamemode_played == Quidditch) {
					for (unsigned int h=0; h<=2; h++) {
						for (unsigned int k=0; k<=2; k++) {
							if (((h+k)%2 == 1) && (Spiel[0][i+h-1][j+k-1] > number_of_players)) {	//every object is saving squares in near-by
								set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, evolution_od, geben, i, j, 0);
								break;
							}
							
							// if (((h+k)%2 == 1) && ((Spiel[0][i+h-1][j+k-1] == Klatscher) || (Spiel[0][i+h-1][j+k-1] == Quaffel) || (Spiel[0][i+h-1][j+k-1] == Schnatz))) {	//Moc-near-by saves squares
								// set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, evolution_od, geben, i, j, 0);
								// break;
							// }
						}
						if (evolution_od[geben][i][j] == 0) {
							break;
						}
					}
				}
			}
		}
	}

	Spielfeld_Destroy (temp_old_dying, m, 0);

	#ifdef VERBOSE
	printf("old_dying ok.4 \n");	//test
	#endif

	// printf("	101*geben=%u, geben=%u \n", 101*geben, geben);	//test

}

void change (Spielfeld Spiel, unsigned int* level, Spielfeld Sf_permutations, Spielfeld Field, Evolution evolution, unsigned int m, unsigned int n, unsigned int gamemode_played, unsigned int number_of_players, unsigned int* ges, unsigned int geben, Special_Fields_Collector* sfc, Spielfeld Opague_o_field, unsigned int* information_code, Growth_Player* Growth_players, Single_option_representives single_option_representives, Special_Fields Roses_o){

	unsigned int a, b;
	a = 0;
	b = 0;

	#ifdef VERBOSE
	printf("change ok.1 \n"); //test
	#endif
	if (Roses_o.characterization != 0) {
		for (unsigned int i=1; i<=m-2; i++) {
			for (unsigned int j=1; j<=n-2; j++) {
				if ((Spiel[0][i][j] >= Roses_0)&&(Spiel[0][i][j] <= Roses_6)) {
					for (unsigned int h=0; h<=2; h++) {
						for (unsigned int k=0; k<=2; k++) {
							if (Spiel[0][i-1+h][j-1+k] == geben) {
								b += 1;
							}
						}
					}
					if (b == Spiel[0][i][j]-Roses_0) {	//Look at the Definition of Roses_0 until Roses_6
						set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Spiel, 0, i, j, 0);
					}
					b = 0;
				}
			}
		}
		b = 0;
	}
	
	for (unsigned int i=1; i<m-1; i+=1){
		for (unsigned int j=1; j<n-1; j+=1){
			if (Spiel[0][i][j] == geben){

				// printf("change ok.2 \n"); //test

				if (evolution.od[geben][i][j] == 101*geben){

					// printf("change ok.3 \n"); //test

					if (sfc->Allocation_o.characterization != 0) {	//So Allocation is activated
						for (unsigned int p=1; p<=sfc->Allocation_o.field[1][i][j]; p++) {
							sfc->Allocation_o.field[0][i][j] -= 1;
							if (sfc->Allocation_o.field[0][i][j] == 0) {
								break;
							}
						}
						if (sfc->Allocation_o.field[0][i][j] == 0) {
							set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Spiel, 0, i, j, 0);
							
							if (Roses_o.characterization != 0) {
								set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Spiel, 0, i, j, Roses_o.field[0][i][j]);	//saves the Roses_(a-1)
							}
							if ((gamemode_played == Ulcer)&&(ges[Nachfolger(geben, number_of_players)] != 1010*geben)) {
								set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Spiel, 0, i, j, Nachfolger(geben, number_of_players));
							}
							if (single_option_representives.undead_duration != 0) {
								set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Spiel, 0, i, j, single_option_representives.undead_duration*10000);
							}
						}

					} else {
						set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Spiel, 0, i, j, 0);
						
						if (Roses_o.characterization != 0) {
							set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Spiel, 0, i, j, Roses_o.field[0][i][j]);	//saves the Roses_(a-1)
						}
						if ((gamemode_played == Ulcer)&&(ges[Nachfolger(geben, number_of_players)] != 1010*geben)) {
							set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Spiel, 0, i, j, Nachfolger(geben, number_of_players));
						}
						if (single_option_representives.undead_duration != 0) {
							set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Spiel, 0, i, j, single_option_representives.undead_duration*10000);
						}
					}

				}

				// printf("change ok.3 \n"); //test

				if ((gamemode_played == Ulcer)&&(geben != 1)) {
					for (unsigned int h=i-1; h<=i+1; h+=1){
						for (unsigned int k=j-1; k<=j+1; k+=1){
							if (Spiel[0][h][k] == Vorganger (geben, number_of_players)) {
								a = 1;
								break;
							}
						}
						if (a == 1) {
							break;
						}
					}
					if (a != 1) {
						set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Spiel, 0, i, j, Nachfolger(geben, number_of_players));
					}

					a = 0;
				}
			} else if ((Spiel[0][i][j] == 0)||((gamemode_played == Duell)&&(evolution.nl[geben][i][j] == geben))){
				if (evolution.nl[geben][i][j] == geben){
					set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Spiel, 0, i, j, geben);
				}
			} else if ((gamemode_played == Ulcer)&&(geben == 1)&&(Spiel[0][i][j] == 2)){	//player one takes back squares from player 2
				if (evolution.nl[geben][i][j] == 1){
					set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Spiel, 0, i, j, 1);
				}
			} else if ((single_option_representives.undead_duration != 0)&&(Spiel[0][i][j] >= 10000)) {	//because nothing is higher than 10000
				Spiel[0][i][j]-=10000;
				if ((Spiel[0][i][j] == 0)&&(gamemode_played == Ulcer)) {
					set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Spiel, 0, i, j, Nachfolger(geben, number_of_players));
				}
			}
		}
	}

	if (single_option_representives.inverted != 0) {
		inverted_organism (Spiel, level, Sf_permutations, Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, m, n, information_code, Growth_players, single_option_representives);
	}

	// printf("change:	101*geben=%u, geben=%u \n", 101*geben, geben); //test

	for (unsigned int i=1; i<m-1; i+=1){
		for (unsigned int j=1; j<n-1; j+=1){
			set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, evolution.od, geben, i, j, 0);
			set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, evolution.nl, geben, i, j, 0);
			set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, sfc->Allocation_o.field, 1, i, j, 0);
		}
	}

	#ifdef VERBOSE
	printf("change ok.4 \n"); //test
	#endif

}

void Having_too_much (unsigned int* KI_decision, unsigned int ent, unsigned int count_new, unsigned int m, unsigned int n, Evolution evolution, Limits limits, unsigned int zeitgewinner, Spielfeld Field, unsigned int w, unsigned int d, unsigned int e, unsigned int geben, unsigned int* position, unsigned int gamemode_played, unsigned int number_of_players, unsigned int rain, Spielfeld Opague_o_field, Special_Fields_Collector* sfc, unsigned int* level, unsigned int real){	//checklist
	unsigned int Having_too_much_Wert, a, b, c, f, ind, ober, heart_i, heart_j, keep, daha_kisa;
	Spielfeld Having_too_much_Feld;

	// if (gamemode_played == Hunt) {	//test
		// printf (" In Having_too_much with Hunt\n");
	// }

	ind = 0;
	keep = 0;
	f = 0;
	b = 0;
	c = 0;
	a = 0;
	daha_kisa = 0;
	Having_too_much_Wert = 0;
	Having_too_much_Feld = Spielfeld_Create (m, n, 0);
	if (d == 10) {	//Arena
		d = 0;
	}

	if ((gamemode_played == Hunt)&&(geben == 1)) {	//Anpassung bezüglich Hunt
		limits.yeni = (limits.yeni + (number_of_players-3));	//only intern, because of the dot
		limits.at_all = (limits.at_all + (2*(number_of_players-3)));
	}

	if (gamemode_played == Hunt) {
		for (unsigned int i=1; i<m-1; i+=1){
			for (unsigned int j=1; j<n-1; j+=1){
				if (Field[0][i][j] == 11) {
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

		Field[0][heart_i][heart_j] = 1;	//heart versteckt, why? Because the squares around have to die
	}

	if ((zeitgewinner >= limits.at_all)&&(gamemode_played != Contact)) {
		for (unsigned int i=1; i<m-1; i+=1){
			for (unsigned int j=1; j<n-1; j+=1){
				if (evolution.nl[geben][i][j] == geben){
					set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, evolution.nl, geben, i, j, 0);
				}
			}
		}
	} else if ((gamemode_played != Hunt)||(geben != 1)) {

		while ((ind != 1)&&(ind != 2)){
			if ((level[geben] == human)&&(real == evet)) {
				printf (" \n");
				printf (" \n");
				printf (" How do you want to play: \n");
				printf (" \n");
			}
			if (ent == limits.yeni){
				if ((gamemode_played == Dynamic)||(gamemode_played == Arena)||(gamemode_played == Sand)) {
					if ((level[geben] == human)&&(real == evet)) {
						printf(" #produce	defensive: 1		offensive: 2 \n");
						ind = get_unsigned_numeric_input_with_not_more_than_1_letter ();
					} else {
						ind = *KI_decision;
					}
				} else if (gamemode_played == Hunt) {
					if ((level[geben] == human)&&(real == evet)) {
						printf(" #produce	defensive: 2		offensive: 1 \n");
						ind = get_unsigned_numeric_input_with_not_more_than_1_letter ();
					} else {
						ind = *KI_decision;
					}
				} else if ((gamemode_played == Rain)||(gamemode_played == Race)||(gamemode_played == Fight)||(gamemode_played == Fall)||(gamemode_played == Collect)||(gamemode_played == Duell)) {
					if ((level[geben] == human)&&(real == evet)) {
						printf(" #produce	keep bottom: 1		keep top: 2		equal: 3 \n");
						keep = get_unsigned_numeric_input_with_not_more_than_1_letter ();
					} else {
						keep = *KI_decision;
					}
					ind = 1;
				} else if ((gamemode_played == Contact)||(gamemode_played == Quidditch)) {
					if ((level[geben] == human)&&(real == evet)) {
						printf(" #produce	keep top: 1		keep bottom: 2		keep left: 3		keep right: 4		don't matter: 5 \n");
						keep = get_unsigned_numeric_input_with_not_more_than_1_letter ();
					} else {
						keep = *KI_decision;
					}
					if ((keep >= 5)||(keep == 0)) {
						ind = 1;
					} else {
						ind = 2;
					}
				} else if (gamemode_played == Classic) {
					if ((level[geben] == human)&&(real == evet)) {
						printf(" #produce	defensive: 1	offensive: 2	equal: 3 \n");
						keep = get_unsigned_numeric_input_with_not_more_than_1_letter ();	//correct misuse of keep, done
					} else {
						keep = *KI_decision;
					}
					ind = 1;
				}
			} else if ((ent == limits.at_all)&&(gamemode_played != Contact)){		//min 5/10, watch out with Hunt on 2 players (theres no need for it anymore, the 52-break is deleted)
				if ((gamemode_played == Dynamic)||(gamemode_played == Arena)||(gamemode_played == Sand)) {
					if ((level[geben] == human)&&(real == evet)) {
						printf(" #reduce	defensive: 1		offensive: 2 \n");
						ind = get_unsigned_numeric_input_with_not_more_than_1_letter ();
					} else {
						ind = *KI_decision;
					}
				} else if (gamemode_played == Hunt) {
					if ((level[geben] == human)&&(real == evet)) {
						printf(" #reduce	defensive: 2		offensive: 1 \n");
						ind = get_unsigned_numeric_input_with_not_more_than_1_letter ();
					} else {
						ind = *KI_decision;
					}
				} else if ((gamemode_played == Rain)||(gamemode_played == Race)||(gamemode_played == Fight)||(gamemode_played == Fall)||(gamemode_played == Collect)||(gamemode_played == Duell)) {
					if ((level[geben] == human)&&(real == evet)) {
						printf(" #reduce	keep bottom: 1	keep top: 2	equal: 3 \n");
						keep = get_unsigned_numeric_input_with_not_more_than_1_letter ();
					} else {
						keep = *KI_decision;
					}
					ind = 1;
				} else if (gamemode_played == Classic) {
					if ((level[geben] == human)&&(real == evet)) {
						printf(" #reduce	defensive: 1	offensive: 2	equal: 3 \n");
						keep = get_unsigned_numeric_input_with_not_more_than_1_letter ();	//correct misuse of keep, done
					} else {
						keep = *KI_decision;
					}
					ind = 1;
				} else if (gamemode_played == Quidditch) {
					if ((level[geben] == human)&&(real == evet)) {
						printf(" #produce	keep top: 1		keep bottom: 2		keep left: 3		keep right: 4		don't matter: 5 \n");
						keep = get_unsigned_numeric_input_with_not_more_than_1_letter ();
					} else {
						keep = *KI_decision;
					}
					if ((keep >= 5)||(keep == 0)) {
						ind = 1;
					} else {
						ind = 2;
					}
				}

			}
			if ((level[geben] == human)&&(real == evet)) {
				printf (" \n");
			}
		}
		if (ind == 1) {
			if ((gamemode_played == Dynamic)||(gamemode_played == Fall)||(gamemode_played == Classic)) {
				ober = 80;
			} else if ((gamemode_played == Arena)||(gamemode_played == Hunt)||(gamemode_played == Contact)) {
				ober = 90;
			} else if (gamemode_played == Rain) {
				ober = 87;
			} else if (gamemode_played == Race) {
				ober = 85+(n-4);
			} else if ((gamemode_played == Fight)||(gamemode_played == Duell)) {
				ober = 105;
			} else if (gamemode_played == Collect) {
				ober = 85;
			} else if (gamemode_played == Sand) {
				ober = 85+m;
			}

		} else if (ind == 2) {
			if ((gamemode_played == Dynamic)||(gamemode_played == Hunt)||(gamemode_played == Contact)) {
				ober = m+n+20;
			} else if ((gamemode_played == Arena)) {
				ober = 10;
			} else if ((gamemode_played == Sand)) {
				ober = m;
			}
		}


		while (count_new > ent){
			if (ind == 1) {

				for (unsigned int i=1; i<m-1; i+=1){
					for (unsigned int j=1; j<n-1; j+=1){
						if (evolution.nl[geben][i][j] == geben){

							for (unsigned int h=i-1; h<=i+1; h+=1){		//Stirbt Zelle?
								for (unsigned int k=j-1; k<=j+1; k+=1){
									if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
										if ((evolution.nl[geben][h][k] == geben) || ((Field[0][h][k] == geben) && (evolution.od[geben][h][k] == 0))){
											a+=1;
										}
									}
								}
							}
							if (a > e+1){
								Having_too_much_Wert += 3;
							}
							a = 0;

							Having_too_much_Wert += 8;
							for (unsigned int h=i-1; h<=i+1; h+=1){		//Regeneriert neue Zellen?
								for (unsigned int k=j-1; k<=j+1; k+=1){
									if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
										if (((Field[0][h][k] == 0) || ((Field[0][h][k] == geben)&&(evolution.od[geben][h][k] == 101*geben))) && (evolution.nl[geben][h][k] == 0)){
											for (unsigned int u=h-1; u<=h+1; u+=1){
												for (unsigned int o=k-1; o<=k+1; o+=1){
													if ((u>0)&&(u<(m-1))&&(o>0)&&(o<(n-1))){
														if ((evolution.nl[geben][u][o] == geben) || ((Field[0][u][o] == geben) && (evolution.od[geben][u][o] == 0))){
															a += 1;
														}
													}
												}
											}
											if (a == w){
												Having_too_much_Wert -= 1;
											}
											a = 0;
										}
									}
								}
							}
							if ((gamemode_played == Arena)||(gamemode_played == Hunt)||(gamemode_played == Rain)||(gamemode_played == Race)||(gamemode_played == Fight)||(gamemode_played == Collect)||(gamemode_played == Sand)||(gamemode_played == Contact)||(gamemode_played == Classic)||(gamemode_played == Quidditch)||(gamemode_played == Duell)) {
								for (unsigned int h=i-1; h<=i+1; h+=1){		//Stört feindliche Wachstumsmöglichkeiten?
									for (unsigned int k=j-1; k<=j+1; k+=1){
										if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
											if ((Field[0][h][k] != geben)&&(Field[0][h][k] != 0)&&(Field[0][h][k] <= number_of_players)){
												a+=1;
											}
										}
									}
								}
								if (a != 3){
									Having_too_much_Wert += 10;
									if ((gamemode_played == Fight)||(gamemode_played == Duell)) {
										Having_too_much_Wert += 10;	//erneut +10
									}
								}
								a = 0;

							}

							for (unsigned int h=i-1; h<=i+1; h+=1){		//Regeneriert ihr Tod neue Zellen?
								for (unsigned int k=j-1; k<=j+1; k+=1){
									if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
										if (((Field[0][h][k] == 0) || ((Field[0][h][k] == geben)&&(evolution.od[geben][h][k] == 101*geben))) && (evolution.nl[geben][h][k] == 0)){
											for (unsigned int u=h-1; u<=h+1; u+=1){
												for (unsigned int o=k-1; o<=k+1; o+=1){
													if ((u>0)&&(u<(m-1))&&(o>0)&&(o<(n-1))){
														if ((evolution.nl[geben][u][o] == geben) || ((Field[0][u][o] == geben) && (evolution.od[geben][u][o] == 0))){
															a += 1;
														}
													}
												}
											}
											if (a == w+1){
												Having_too_much_Wert += 1;
											}
											a = 0;

										}
									}
								}
							}

							for (unsigned int h=i-1; h<=i+1; h+=1){		//sterben eigene Zellen?
								for (unsigned int k=j-1; k<=j+1; k+=1){
									if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
										if (((Field[0][h][k] == geben) && (evolution.od[geben][h][k] == 0)) ||(evolution.nl[geben][h][k] == geben)){
											for (unsigned int u=h-1; u<=h+1; u+=1){
												for (unsigned int o=k-1; o<=k+1; o+=1){
													if ((u>0)&&(u<(m-1))&&(o>0)&&(o<(n-1))){
														if ((evolution.nl[geben][u][o] == geben) || ((Field[0][u][o] == geben) && (evolution.od[geben][u][o] == 0))){
															a += 1;
														}
													}
												}
											}
											if (a > e+1){
												Having_too_much_Wert += 3;
											}
											a = 0;
										}
									}
								}
							}

							for (unsigned int h=i-1; h<=i+1; h+=1){		//tötet ihr Tod eigene Zellen?
								for (unsigned int k=j-1; k<=j+1; k+=1){
									if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
										if (((Field[0][h][k] == geben) && (evolution.od[geben][h][k] == 0))||(evolution.nl[geben][h][k] == geben)){
											for (unsigned int u=h-1; u<=h+1; u+=1){
												for (unsigned int o=k-1; o<=k+1; o+=1){
													if ((u>0)&&(u<(m-1))&&(o>0)&&(o<(n-1))){
														if ((evolution.nl[geben][u][o] == geben) || ((Field[0][u][o] == geben) && (evolution.od[geben][u][o] == 0))){
															a += 1;
														}
													}
												}
											}
											if (sfc->Allocation_o.characterization != 0) {
												if (a < d+1){
													b = 1;
												}
											} else {
												if (a == d){
													b = 1;
												}
											}
											a = 0;
										}
									}
								}
							}
							if (b != 1){
								Having_too_much_Wert += 10;
							}
							b = 0;

							if ((gamemode_played == Rain)||(gamemode_played == Race)||(gamemode_played == Fight)||(gamemode_played == Fall)||(gamemode_played == Collect||(gamemode_played == Duell))) {
								if (keep == 1) {
									Having_too_much_Wert += (6-i);	//stack_overflow? not causing troubles
								} else if (keep == 2) {
									Having_too_much_Wert += i;
								}
							}

							if (gamemode_played == Dynamic) {		//gamemode depending specials
								if ((i == position[Vertikal])||(j == position[Horizontal])) {
									Having_too_much_Wert = 1;
								}
							} else if (gamemode_played == Hunt) {
								if ((i+1 != heart_i)&&(i-1 != heart_i)&&(j-1 != heart_j)&&(j+1 != heart_j)){
									Having_too_much_Wert += 20;
								}
							} else if (gamemode_played == Rain) {

								if (j > ((n-1)/2)){
									Having_too_much_Wert += (j-(n-1)/2);
								} else if (j < ((n-1)/2)){
									Having_too_much_Wert += (((n-1)/2)-j);
								}

								Having_too_much_Wert += i;

								if ((i <= 2)&&((j >= ((n-3)/2))&&(j <= ((n+1)/2)))){
									Having_too_much_Wert = 1;
								}

								if ((rain == 31)||(rain == 32)||(rain == 2)){
									if (Field[0][i-1][j] == Raindrop){
										Having_too_much_Wert = 80;
									}
								}

							} else if (gamemode_played == Race) {
								Having_too_much_Wert += (n-2-j);

								if (j>=n-3){
									Having_too_much_Wert = 1;
								}

							} else if (gamemode_played == Fight) {
								if (((Field[0][i+1][j] > number_of_players)||(Field[0][i+1][j] == geben)||(Field[0][i+1][j] == 0))&&((Field[0][i][j+1] > number_of_players)||(Field[0][i][j+1] == geben)||(Field[0][i+1][j] == 0))&&((Field[0][i][j-1] > number_of_players)||(Field[0][i][j-1] == geben)||(Field[0][i+1][j] == 0))&&((Field[0][i-1][j] > number_of_players)||(Field[0][i-1][j] == geben)||(Field[0][i+1][j] == 0))) {
									Having_too_much_Wert += 10;
								}
							} else if (gamemode_played == Fall) {
								if (geben%2 == 0) {
									if ((Field[0][i-1][j]==Fall_ball)||(Field[0][i][j+1]==Fall_ball)||(Field[0][i+1][j]==Fall_ball)){
										Having_too_much_Wert = 1;		//fehlerhaft! (Vielleicht die Seiten vertauscht)
									}
								} else if (geben%2 == 1) {
									if ((Field[0][i-1][j]==Fall_ball)||(Field[0][i][j-1]==Fall_ball)||(Field[0][i+1][j]==Fall_ball)){
										Having_too_much_Wert = 1;
									}
								}

							} else if (gamemode_played == Collect) {
								if ((i >= (m-3)/2)&&(i <= (m+1)/2)){
									Having_too_much_Wert = 2;
								}

								if ((Field[0][i-1][j]==To_collect)||(Field[0][i+1][j]==To_collect)||(Field[0][i][j-1]==To_collect)||(Field[0][i][j+1]==To_collect)){
									Having_too_much_Wert = 1;
								}

							} else if (gamemode_played == Classic) {
								if (geben%2 == 0) {
									if (i == 1){
										Having_too_much_Wert = 1;
									} else if (i == 2) {
										Having_too_much_Wert = 2;
									}
								} else if (geben%2 == 1) {
									if (i == (m-2)){
										Having_too_much_Wert = 1;
									} else if (i == (m-3)) {
										Having_too_much_Wert = 2;
									}
								}
							} else if (gamemode_played == Sand) {
								Having_too_much_Wert += i;
							}

							set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Having_too_much_Feld, 0, i, j, Having_too_much_Wert);
							Having_too_much_Wert = 0;
						}
					}
				}
			} else if (ind == 2) {
				a = 0;

				for (unsigned int i=1; i<m-1; i+=1){
					for (unsigned int j=1; j<n-1; j+=1){
						if (evolution.nl[geben][i][j] == geben){

							if (gamemode_played == Dynamic) {
								set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Having_too_much_Feld, 0, i, j, abs(i-position[Vertikal])+abs(j-position[Horizontal]));
							} else if (gamemode_played == Arena) {
								for (unsigned int h=i-1; h<=i+1; h+=1){
									for (unsigned int k=j-1; k<=j+1; k+=1){
										if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
											if ((Field[0][h][k] != geben)&&(Field[0][h][k] != 0)) {
												Having_too_much_Wert += 1;
											} else if (Field[0][h][k] == geben) {
												a += 1;
											}
										}
									}
								}

								if ((a > d)&&(a <= e+1)) {
									Having_too_much_Wert += 1;
								}
								a = 0;
								set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Having_too_much_Feld, 0, i, j, 10 - Having_too_much_Wert);
								Having_too_much_Wert = 0;

							} else if (gamemode_played == Hunt) {
								if (j >= heart_j) {
									if (i >= heart_i) {
										Having_too_much_Wert = (i-heart_i-heart_j+j);
									} else if (i < heart_i) {
										Having_too_much_Wert = (heart_i-i-heart_j+j);
									}
								} else if (j < heart_j) {
									if (i >= heart_i) {
										Having_too_much_Wert = (i+heart_j-heart_i-j);
									} else if (i < heart_i) {
										Having_too_much_Wert = (heart_i+heart_j-i-j);
									}
								}

								set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Having_too_much_Feld, 0, i, j, Having_too_much_Wert);
								Having_too_much_Wert = 0;

							} else if ((gamemode_played == Contact)||(gamemode_played == Quidditch)) {

								if (keep == 1) {
									Having_too_much_Wert = i;
								} else if (keep == 2) {
									Having_too_much_Wert = (m-1)-i;
								} else if (keep == 3) {
									Having_too_much_Wert = j;
								} else if (keep == 4) {
									Having_too_much_Wert = (n-1)-j;
								}

								for (unsigned int h=i-1; h<=i+1; h+=1){
									for (unsigned int k=j-1; k<=j+1; k+=1){
										if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
											if ((Field[0][h][k] != 0)&&(Field[0][h][k] != geben)){
												Having_too_much_Wert = 1;
											}
										}
									}
								}

								set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Having_too_much_Feld, 0, i, j, Having_too_much_Wert);
								Having_too_much_Wert = 0;

							} else if (gamemode_played == Sand) {
								set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Having_too_much_Feld, 0, i, j, i);
							}
						}
					}
				}
			}

			// if (gamemode_played == Hunt) {
				// set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, heart_i, heart_j, 11);	//verstecken von heart undone, why?
			// }

			c = 0;
			daha_kisa = count_new;

			while (daha_kisa == count_new) {
				for (unsigned int i=1; i<m-1; i+=1){
					if (c == 1){
						break;
					}
					for (unsigned int j=1; j<n-1; j+=1){
						if (Having_too_much_Feld[0][i][j] == ober){
							set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Having_too_much_Feld, 0, i, j, 0);
							set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, evolution.nl, geben, i, j, 0);
							count_new -= 1;
							if (ind  == 2) {
								if ((gamemode_played == Dynamic)||(gamemode_played == Contact)||(gamemode_played == Quidditch)||((gamemode_played == Hunt)&&(geben == 1))) {
									ober = m+n;
								} else if (gamemode_played == Arena) {
									ober = 10;
								} else if (gamemode_played == Sand) {
									ober = m;
								}
							} else if (ind == 1) {

								if ((gamemode_played == Dynamic)||(gamemode_played == Fall)||(gamemode_played == Classic)) {
									ober = 80;
								} else if ((gamemode_played == Arena)||((gamemode_played == Hunt)&&(geben == 1))) {
									ober = 90;
								} else if (gamemode_played == Rain) {
									ober = 87;
								} else if (gamemode_played == Race) {
									ober = 85+(n-4);
								} else if ((gamemode_played == Fight)||(gamemode_played == Duell)) {
									ober = 105;
								} else if (gamemode_played == Collect) {
									ober = 85;
								} else if (gamemode_played == Sand) {
									ober = 85+m;
								}
							}

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
					if (evolution.nl[geben][t][z] == geben){
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
	} else if ((gamemode_played == Hunt)&&(geben != 1)) {

		ober = m+n;
		while (count_new > ent){
			for (unsigned int i=1; i<m-1; i+=1){
				for (unsigned int j=1; j<n-1; j+=1){
					if (evolution.nl[geben][i][j] == geben){
						if (j >= heart_j) {
							if (i >= heart_i) {
								Having_too_much_Wert = (i-heart_i-heart_j+j);
							} else if (i < heart_i) {
								Having_too_much_Wert = (heart_i-i-heart_j+j);
							}
						} else if (j < heart_j) {
							if (i >= heart_i) {
								Having_too_much_Wert = (i+heart_j-heart_i-j);
							} else if (i < heart_i) {
								Having_too_much_Wert = (heart_i+heart_j-i-j);
							}
						}

						set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Having_too_much_Feld, 0, i, j, Having_too_much_Wert);
						Having_too_much_Wert = 0;
					}
				}
			}

			c = 0;
			daha_kisa = count_new;

			while (daha_kisa == count_new) {
				for (unsigned int i=1; i<m-1; i+=1){
					if (c == 1){
						break;
					}
					for (unsigned int j=1; j<n-1; j+=1){
						if (Having_too_much_Feld[0][i][j] == ober){
							set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Having_too_much_Feld, 0, i, j, 0);
							set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, evolution.nl, geben, i, j, 0);
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

			c = 0;
			for (unsigned int t=1; t<m-1; t+=1){
				if (f == 1){
					break;
				}
				for (unsigned int z=1; z<n-1; z+=1){
					if (evolution.nl[geben][t][z] >= 1){
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

	Spielfeld_Destroy (Having_too_much_Feld, m, 0);
}
