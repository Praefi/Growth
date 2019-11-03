
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
#include "Growth_all_show.h"
#include "Growth_all_set.h"
#include "Growth_all_get.h"
#include "Growth_all_gamemode_specials.h"
#include "Growth_all_options_specials.h"


// /*
void realize_modifications (Quidditch_setup* Qs, Moveable_objects_condition* Moc_Schnatz, Moveable_objects_condition* Moc_Quaffel, Moveable_objects_condition* Moc_Klatscher, Spielfeld Field, Spielfeld Spiel, Special_Fields Opague_o, Special_Fields Allocation_o, Spielfeld Sf_permutations, unsigned int* ges, unsigned int* g, unsigned int m, unsigned int n, unsigned int geben, unsigned int number_of_players, unsigned int gamemode_played, unsigned int* level, unsigned int* information_code, Growth_Player* Growth_players, Special_Fields Journey_o, unsigned int rain, Single_option_representives single_option_representives, Realize_modifications_variables* rmv, Limits limits, unsigned int real) {

	unsigned int einmal;	// just to controll something
	unsigned int rain_save, rain_speed_save, number_rain;	// Gamemode: Rain
	unsigned int fall_back;	// Gamemode: Fall
	unsigned int count_freq;	// Gamemode: Race

	// copies of same
	unsigned int fall_controll, turns_per_drop, speed_of_fall, points_for_win;	//Gamemode: Fall
	unsigned int rain_drops, rain_obj, rain_speed;	//Gamemode: Rain
	unsigned int figures, assassin, avalanche, spreading;	// Modifications
	unsigned int intensity_minimum, direction;	// Projection matters

	#ifdef VERBOSE
	printf("	realize_modifications ok.0\n ");	//test
	#endif
	
	einmal = 0;

	count_freq = 1;
	
	rain_speed_save = 0;	//Rain
	rain_save = 0;
	number_rain = 0;

	fall_back = 0;	//Fall

	direction = rmv->same[76];
	// printf("	realize_modifications ok.0.1\n ");	//test
	intensity_minimum = rmv->same[74];
	// printf("	realize_modifications ok.0.2\n ");	//test
	avalanche = rmv->same[9];
	// printf("	realize_modifications ok.0.3\n ");	//test
	assassin = rmv->same[77];
	// printf("	realize_modifications ok.0.4\n ");	//test
	figures = rmv->same[69];
	// printf("	realize_modifications ok.0.5\n ");	//test
	rain_speed = rmv->same[14];
	// printf("	realize_modifications ok.0.6\n ");	//test
	rain_obj = rmv->same[13];
	// printf("	realize_modifications ok.0.7\n ");	//test
	rain_drops = rmv->same[12];
	// printf("	realize_modifications ok.0.8\n ");	//test
	points_for_win = rmv->same[21];
	// printf("	realize_modifications ok.0.9\n ");	//test
	speed_of_fall = rmv->same[8];
	// printf("	realize_modifications ok.0.10\n ");	//test
	turns_per_drop = rmv->same[7];
	// printf("	realize_modifications ok.0.11\n ");	//test
	fall_controll = rmv->same[6];
	spreading = rmv->same[91];
	
	#ifdef Contact_mistake_search
	printf("	realize_modifications ok.1Con\n ");	//test
	#endif
	
	// printf("	realize_modifications ok.1\n ");	//test

	if (single_option_representives.addition != 0) {

		if (real == evet) {
			if (Opague_o.characterization >= 1) {
				opague_builder (Spiel, Opague_o, m, n, geben, rmv->AOP, Allocation_o, number_of_players, gamemode_played);
				show_field (number_of_players, level, Sf_permutations, Opague_o.field, Opague_o.field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
			} else {
				show_field (number_of_players, level, Sf_permutations, Opague_o.field, Spiel, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
			}
		}

		addition_maker (Spiel, m, n, number_of_players, geben, Opague_o.field, gamemode_played, Allocation_o, ges);

	}

	// printf("	realize_modifications ok.2\n ");	//test

	if (real == evet) {
		if ((gamemode_played == Hunt)&&(geben == 1)) {	//if geben == 1

			if (Opague_o.characterization >= 1) {
				opague_builder (Spiel, Opague_o, m, n, geben, rmv->AOP, Allocation_o, number_of_players, gamemode_played);
				show_field (number_of_players, level, Sf_permutations, Opague_o.field, Opague_o.field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
			} else {
				show_field (number_of_players, level, Sf_permutations, Opague_o.field, Spiel, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
			}

			printf("\n");
			printf("\n");
			choose_heart (Spiel, m, n, geben, Opague_o.field, Allocation_o, number_of_players, gamemode_played);
			printf("\n");
		}
	}

	// printf("	realize_modifications ok.3\n ");	//test

	if (gamemode_played == Classic) {	//Matchballs and win
		if (real == evet) {
			for (unsigned int j=1; j<n-1; j+=1) {
				if (Field[0][(m-3)*(geben%2)+2*((geben+1)%2)][j] == geben){
					rmv->numbers_of_[geben][0][0] += 1;	//Matchballs
					break;	//because the line should be count once not twice or...
				}
			}
			for (unsigned int j=1; j<n-1; j+=1){
				for (unsigned int p=1; p<=number_of_players; p++) {
					if (Field[0][(m-2)*(p%2)+1*((p+1)%2)][j] == p){
						rmv->win_condition[p] = kazanacak;
						rmv->win_condition[0] = biri_kazanacak;
					}
				}
			}
			for (unsigned int p=1; p<=number_of_players; p++) {
				if (rmv->win_condition[p] == kazanacak){
					printf("	Sieg:	Spieler %u \n", p);
				}
			}
			if (rmv->win_condition[0] == biri_kazanacak){
				*g = 0;
		// printf("g=0 line: 12914");	//test
			}
		}
	} else if (gamemode_played == Collect) {
		unsigned int a;
		a = 0;
		
		for (unsigned int q=1; q<=number_of_players-1; q++) {		//Collect-Bed. prüfen
			
			if (Spiel[0][(m-1)/2][2+q+q*(n-2-4-(number_of_players-1))/number_of_players] == To_collect) {
				if (Spiel[0][((m-1)/2)-1][2+q+q*(n-2-4-(number_of_players-1))/number_of_players]==geben){a += 1;}
				if (Spiel[0][((m-1)/2)+1][2+q+q*(n-2-4-(number_of_players-1))/number_of_players]==geben){a += 1;}
				if (Spiel[0][(m-1)/2][(2+q+q*(n-2-4-(number_of_players-1))/number_of_players)-1]==geben){a += 1;}
				if (Spiel[0][(m-1)/2][(2+q+q*(n-2-4-(number_of_players-1))/number_of_players)+1]==geben){a += 1;}
				if (a >= 3){
					if (real == evet) {
						rmv->numbers_of_[geben][0][0] += 1;
					}
					set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, ((m-1)/2), 2+q+q*(n-2-4-(number_of_players-1))/number_of_players, geben);
				}
			}
			a = 0;
		}
		if (Field[0][(m-1)/2][2] == To_collect) {
			if (Spiel[0][((m-1)/2)-1][2] == geben){a += 1;}
			if (Spiel[0][((m-1)/2)+1][2] == geben){a += 1;}
			if (Spiel[0][(m-1)/2][1] == geben){a += 1;}
			if (Spiel[0][(m-1)/2][3] == geben){a += 1;}
			if (a >= 3){
				if (real == evet) {
					rmv->numbers_of_[geben][0][0] += 1;
				}
				set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, ((m-1)/2), 2, geben);
			}
			a = 0;
		}
		if (Field[0][(m-1)/2][n-3] == To_collect) {
			if (Spiel[0][((m-1)/2)-1][n-3] == geben){a += 1;}
			if (Spiel[0][((m-1)/2)+1][n-3] == geben){a += 1;}
			if (Spiel[0][(m-1)/2][n-4] == geben){a += 1;}
			if (Spiel[0][(m-1)/2][n-2] == geben){a += 1;}
			if (a >= 3){
				if (real == evet) {
					rmv->numbers_of_[geben][0][0] += 1;
				}
				set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, ((m-1)/2), n-3, geben);
			}
			a = 0;
		}
		
		if (real == evet) {
			if (rmv->numbers_of_[geben][0][0] == 2){
				printf("\n");
				printf("	Sieg: Spieler %u \n", geben);
				printf("\n");
				show_field (number_of_players, level, Sf_permutations, Opague_o.field, Spiel, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
				*g = 0;
		// printf("g=0 line: 12941");	//test
			}
		}
	} else if (gamemode_played == Sand) {
		if (real == evet) {
			for (unsigned int j=1; j<n-1; j+=1){
				if (Field[0][2][j] == geben){
					rmv->numbers_of_[geben][0][0] += 1;
				}
			}
		}
	}

	// printf("	realize_modifications ok.4\n ");	//test

	if (real == evet) {
		if ((gamemode_played == Hunt)&&(geben == number_of_players)) {
			printf("	\n");

			if (Opague_o.characterization >= 1) {
				opague_builder (Field, Opague_o, m, n, geben, rmv->AOP, Allocation_o, number_of_players, gamemode_played);
				show_field (number_of_players, level, Sf_permutations, Opague_o.field, Opague_o.field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
			} else {
				show_field (number_of_players, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
			}

			printf("	\n");
			if (information_code[1] == 0) {
				anything = 1;
				while (anything == 1) {
					printf("	\n");
					printf("	\n");
					printf("	Are you ready to make your turn, player 1 ? \n");
					printf("	Yes: 1 \n");
					printf("	\n");
					printf("	\n");
					anything = get_unsigned_numeric_input_with_not_more_than_1_letter ();

					if (anything != 1) {
						anything = 1;
					} else {
						anything = 0;
					}
				}
				anything = 0;
			}
		}

		if (gamemode_played == Hunt) {
			information_code[3] = 0;
		}

		// printf("	realize_modifications ok.5\n ");	//test

		if ((gamemode_played == Hunt)&&(geben == 1)) {	//if geben==1
			for (unsigned int p=0; p<=3; p+=1) {
				information_code[p] = 0;
			}

			// printf("\n");	//test
			// printf("	hboa=%u	\n", information_code[2]);
			// printf("\n");
			
			if (Opague_o.characterization >= 1) {
				opague_builder (Field, Opague_o, m, n, geben, rmv->AOP, Allocation_o, number_of_players, gamemode_played);
				show_field (number_of_players, level, Sf_permutations, Opague_o.field, Opague_o.field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
			} else {
				show_field (number_of_players, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
			}

			for (unsigned int s = 1; s <= 20; s+=1) {	//Abstandhalter
				printf(" \n");
			}
		}
	}	//real = hayir possible

	// printf("	realize_modifications ok.6\n ");	//test

	if (assassin != 0) {
		assassin_maker (real, Spiel, level, Sf_permutations, Field, geben, Opague_o, gamemode_played, Allocation_o, number_of_players, m, n, rmv->AOP, information_code, Growth_players);
	}

	#ifdef Contact_mistake_search
	printf("gamemode_played = %u \n", gamemode_played);	//test
	printf("Contact = %u \n", Contact);	//test
	#endif
	
	// printf("	realize_modifications ok.6.0\n ");	//test
	
	if (gamemode_played == Contact) {

		#ifdef Contact_mistake_search
		printf("	realize_modifications ok.3Con\n ");	//test
		#endif
	
		if (real == evet) {
			if (Opague_o.characterization >= 1) {
				opague_builder (Field, Opague_o, m, n, geben, rmv->AOP, Allocation_o, number_of_players, gamemode_played);
				show_field (number_of_players, level, Sf_permutations, Opague_o.field, Opague_o.field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
			} else {
				show_field (number_of_players, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
			}
		}
		
		#ifdef Contact_mistake_search
		printf("	realize_modifications ok.4Con\n ");	//test
		#endif
	
		battle (Spiel, m, n, Field, geben, Opague_o.field, Allocation_o, number_of_players, gamemode_played);
		
		#ifdef Contact_mistake_search
		printf("	realize_modifications ok.5Con\n ");	//test
		#endif
	
	}

	// printf("	realize_modifications ok.7\n ");	//test

	if (real == evet) {
		if (Journey_o.characterization != 0) {
			if (gamemode_played == Race) {
				anything = 2*rmv->freq;
			} else {
				anything = (10*(number_of_players - rmv->player_counter) - 1);
			}

			if ((anything - ((*g-rmv->all_turns_correction-1)%anything)) == 1) {
				if (Opague_o.characterization >= 1) {
					opague_builder (Field, Opague_o, m, n, (geben%number_of_players)+1, rmv->AOP, Allocation_o, number_of_players, gamemode_played);
					show_field (number_of_players, level, Sf_permutations, Opague_o.field, Opague_o.field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
				} else {
					show_field (number_of_players, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
				}

				printf (" \n");
				printf (" \n");
				printf ("	It is time for a journey... \n");
				printf (" \n");
				for (unsigned int i=1; i<m-1; i+=1){
					for (unsigned int j=1; j<n-1; j+=1){
						if (Field[0][i][j] <= number_of_players) {
							set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, i, j, Journey_o.field[0][i][j]);
							set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Journey_o.field, 0, i, j, 0);
						} else {
							set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Journey_o.field, 0, i, j, 0);
						}
					}
				}
			}
		}
		if (single_option_representives.intensity_loss_per_line_multiplication != 0) {
			if (gamemode_played == Race) {
				anything = 2*rmv->freq-2;
			} else {
				anything = (9*(number_of_players - rmv->player_counter) - 1);
			}

			if ((anything - ((*g-rmv->all_turns_correction-1)%anything)) == 1) {
				if (Opague_o.characterization >= 1) {
					opague_builder (Field, Opague_o, m, n, (geben%number_of_players)+1, rmv->AOP, Allocation_o, number_of_players, gamemode_played);
					show_field (number_of_players, level, Sf_permutations, Opague_o.field, Opague_o.field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
				} else {
					show_field (number_of_players, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
				}

				printf (" \n");
				printf (" \n");
				printf ("	It is time for a projection... \n");
				printf (" \n");
				projection_maker (Field, number_of_players, geben, Opague_o.field, gamemode_played, Allocation_o, direction, intensity_minimum, single_option_representives.intensity_loss_per_line_multiplication, m, n);
			}
		}
		if ((rmv->Collector_of_permutation.amount_of_permutation_number_b != 0)||(rmv->Collector_of_permutation.amount_of_permutation_number_c != 0)) {
			if (gamemode_played == Race) {
				anything = 2*rmv->freq-3;
			} else {
				anything = (8*(number_of_players - rmv->player_counter) - 1);
			}
		
			// printf (" number_b: %u, number_c: %u \n", rmv->Collector_of_permutation.amount_of_permutation_number_b, rmv->Collector_of_permutation.amount_of_permutation_number_c);	//test
		
			if ((anything - ((*g-rmv->all_turns_correction-1)%anything)) == 1) {
				if (Opague_o.characterization >= 1) {
					opague_builder (Field, Opague_o, m, n, (geben%number_of_players)+1, rmv->AOP, Allocation_o, number_of_players, gamemode_played);
					show_field (number_of_players, level, Sf_permutations, Opague_o.field, Opague_o.field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
				} else {
					show_field (number_of_players, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
				}

				printf (" \n");
				printf (" \n");
				printf ("	It is time for a permutation... \n");
				printf (" \n");

				// show_field (number_of_players, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);	//test

				Permutations_permutate_maker (rmv->Collector_of_permutation.areas_c, Field, number_of_players, rmv->Collector_of_permutation.permutation_number_c, rmv->Collector_of_permutation.sigmas_c, rmv->Collector_of_permutation.amount_of_permutation_number_c, geben, Opague_o.field, gamemode_played, Allocation_o);

				// printf (" #5k after Permutations_permutate_maker(c) ok\n");

				Permutations_permutate_maker (rmv->Collector_of_permutation.areas_b, Field, number_of_players, rmv->Collector_of_permutation.permutation_number_b, rmv->Collector_of_permutation.sigmas_b, rmv->Collector_of_permutation.amount_of_permutation_number_b, geben, Opague_o.field, gamemode_played, Allocation_o);

			}
		}
	}

	// printf("	realize_modifications ok.8\n ");	//test

	// printf("	gamemode_played = %u \n", gamemode_played);	//test
	// printf("	Rain = %u \n", Rain);	//test

	if (gamemode_played == Rain) {
		if (real == evet) {
			if (Opague_o.characterization >= 1) {
				opague_builder (Field, Opague_o, m, n, (geben%number_of_players)+1, rmv->AOP, Allocation_o, number_of_players, gamemode_played);
				show_field (number_of_players, level, Sf_permutations, Opague_o.field, Opague_o.field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
			} else {
				show_field (number_of_players, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
			}

			printf("\n");
			printf("\n");
			printf("\n");
			printf("\n");
			printf("\n");
			printf("\n");
			printf("\n");

			if (rain == Push){
				printf("		rain-Characteristics: Push \n");
			} else if (rain == Destroy_rain){
				printf("		rain-Characteristics: Destroy \n");
			} else if (rain == Explode){
				printf("		rain-Characteristics: Explode \n");
			} else if (rain == Explode_and_survival){
				printf("		rain-Characteristics: Explode & survival \n");
			} else if (rain == Transform){
				printf("		rain-Characteristics: Transform \n");
			} else if (rain == Teleport){
				printf("		rain-Characteristics: Teleport \n");
			} else if (rain == Mixed){
				printf("		rain-Characteristics: Mixed \n");
			}
		}

		number_rain = rmv->use_number;

		if ((rain_speed == 0) && (((*g-1)%4) >= 2)){
			if (real == evet) {
				printf("	\n");
				printf("	Falling slowly...\n");
				printf("	\n");
				if (Opague_o.characterization >= 1) {
					show_field (number_of_players, level, Sf_permutations, Opague_o.field, Opague_o.field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);	//already build
				} else {
					show_field (number_of_players, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
				}
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
				if (geben <= number_of_players/2){
					for (unsigned int i=m-2; i>0; i-=1){
						for (unsigned int j=1+(geben-1)*7; j<=6+(geben-1)*7; j+=1){
							if (Spiel[0][i][j] == Raindrop){
								if (Spiel[0][i+1][j] != 0){

									if (rain == 1){
										unsigned int mem;
										mem = i;
										while (((i+1)<=(m-2))&&(Spiel[0][i+1][j] != 0)){
											if ((i+1)<=(m-2)){
												set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, mem, j, Spiel[0][i+1][j]);
											}

											if (i == mem) {

												if (((mem+2)<=(m-2))&&(Spiel[0][mem+2][j] == 0)) {
													set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, mem+2, j, Spiel[0][mem][j]);
													break;
												} else if (((mem+2)<=(m-2))&&(Spiel[0][mem+2][j] != 0)) {
													set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, mem+1, j, Spiel[0][mem+2][j]);
													set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, mem+2, j, Spiel[0][mem][j]);
													if (((mem+3)<=(m-2))&&(Spiel[0][mem+3][j] == 0)) {
														set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, mem+3, j, Spiel[0][mem+1][j]);
													}
												}

												i += 2;
											} else {

												i += 1;

												set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j, Spiel[0][mem+1][j]);

												if (((i+1)<=(m-2))&&(Spiel[0][i+1][j] == 0)){
													set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i+1, j, Spiel[0][mem][j]);
													break;
												}
												set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, mem+1, j, Spiel[0][mem][j]);
											}
										}
										i = mem;
										set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j, 0);
										if (i < (m-2)) {
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i+1, j, Raindrop);
										}

									} else if (rain == 2){
										set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i+1, j, Raindrop);
										set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j, 0);

									} else if (rain == 31){
										for (unsigned int h=i; h<=i+2; h+=1){
											for (unsigned int k=j-1; k<=j+1; k+=1){
												if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
													set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, h, k, 0);
												}
											}
										}
									} else if (rain == 32){
										for (unsigned int h=i; h<=i+2; h+=1){
											for (unsigned int k=j-1; k<=j+1; k+=1){
												if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
													if (Spiel[0][h][k] == Raindrop){
														set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, h, k, geben);
													} else {
														set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, h, k, 0);
													}
												}
											}
										}
										set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j, 0);
										set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i+1, j, 0);
									} else if (rain == 4){
										if((Spiel[0][i-1][j] == geben)||(Spiel[0][i+1][j] == geben)||(Spiel[0][i][j-1] == geben)||(Spiel[0][i][j+1] == geben)){
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j, geben);
										} else {
											if (i != (m-2)){
												set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i+1, j, Raindrop);
											}
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j, 0);
										}
									} else if (rain == 5){

										if (Spiel[0][i+1][j] == geben){
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i-1, j, geben);
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i+1, j, 0);
										} else if (Spiel[0][i][j-1] == geben){
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j+1, geben);
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j-1, 0);
										} else if (((j+2)<=n-1) && (Spiel[0][i][j+1] == geben) && (((Spiel[0][i][j+2] != Raindrop) || (Spiel[0][i+1][j+2] != geben)) && (Spiel[0][i-1][j+1] != Raindrop))){
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j-1, geben);
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j+1, 0);
										} else if (((i-1)>=1) && (Spiel[0][i-1][j] == geben) && (Spiel[0][i-2][j] != Raindrop) && (Spiel[0][i-1][j-1] != Raindrop)){
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i+1, j, geben);
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i-1, j, 0);
										}
										set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i+1, j, Raindrop);
										set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j, 0);
									}
								} else {

									if (rain == 5){
										if (Spiel[0][i+1][j] == geben){
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i-1, j, geben);
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i+1, j, 0);
										} else if (Spiel[0][i][j-1] == geben){
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j+1, geben);
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j-1, 0);
										} else if (((j+2)<=n-1) && (Spiel[0][i][j+1] == geben) && (((Spiel[0][i][j+2] != Raindrop) || (Spiel[0][i+1][j+2] != geben)) && (Spiel[0][i-1][j+1] != Raindrop))){
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j-1, geben);
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j+1, 0);
										} else if (((i-1)>=1) && (Spiel[0][i-1][j] == geben) && (Spiel[0][i-2][j] != Raindrop) && (Spiel[0][i-1][j-1] != Raindrop)){
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i+1, j, geben);
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i-1, j, 0);
										}
									}
									if (rain == 4){
										if((Spiel[0][i-1][j] == geben)||(Spiel[0][i+1][j] == geben)||(Spiel[0][i][j-1] == geben)||(Spiel[0][i][j+1] == geben)){
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j, geben);
										} else {
											if (i != (m-2)){
												set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i+1, j, Raindrop);
											}
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j, 0);
										}
									} else {
										if (i != (m-2)){
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i+1, j, Raindrop);
										}
										set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j, 0);
									}
								}
							}
						}
					}
					if (rain_drops == 1){
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, 1, geben*7-number_rain, Raindrop);
					} else if (rain_drops == 2){
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, 1, (geben-1)*7+number_rain, Raindrop);
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, 1, geben*7-number_rain, Raindrop);
					} else if (rain_drops == 4){
						for (unsigned int s=1+(geben-1)*7; s<=6+(geben-1)*7; s+=1){
							if ((s != (geben-1)*7+number_rain)&&(s != geben*7-number_rain)){
								set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, 1, s, Raindrop);
							}
						}
					} else if (rain_drops == 5){
						for (unsigned int s=1+(geben-1)*7; s<=6+(geben-1)*7; s+=1){
							if (s != (geben-1)*7+number_rain){
								set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, 1, s, Raindrop);
							}
						}
					} else if (rain_drops == 6){
						for (unsigned int s=1+(geben-1)*7; s<=6+(geben-1)*7; s+=1){
							set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, 1, s, Raindrop);
						}
					}

				} else if (geben > number_of_players/2) {
					for (unsigned int i=m-2; i>0; i-=1){
						for (unsigned int j=6+(geben-1)*7; j>=1+(geben-1)*7; j-=1){
							if (Spiel[0][i][j] == Raindrop){
								if (Spiel[0][i+1][j] != 0){

									if (rain == 1){
										unsigned int mem;
										mem = i;
										while (((i+1)<=(m-2))&&(Spiel[0][i+1][j] != 0)){
											if ((i+1)<=(m-2)){
												set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, mem, j, Spiel[0][i+1][j]);
											}

											if (i == mem) {

												if (((mem+2)<=(m-2))&&(Spiel[0][mem+2][j] == 0)) {
													set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, mem+2, j, Spiel[0][mem][j]);
													break;
												} else if (((mem+2)<=(m-2))&&(Spiel[0][mem+2][j] != 0)) {
													set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, mem+1, j, Spiel[0][mem+2][j]);
													set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, mem+2, j, Spiel[0][mem][j]);
													if (((mem+3)<=(m-2))&&(Spiel[0][mem+3][j] == 0)) {
														set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, mem+3, j, Spiel[0][mem+1][j]);
													}
												}

												i += 2;
											} else {

												i += 1;

												set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j, Spiel[0][mem+1][j]);

												if (((i+1)<=(m-2))&&(Spiel[0][i+1][j] == 0)){
													set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i+1, j, Spiel[0][mem][j]);
													break;
												}
												set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, mem+1, j, Spiel[0][mem][j]);

											}
										}
										i = mem;
										set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j, 0);
										if (i < (m-2)) {
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i+1, j, Raindrop);
										}
									} else if (rain == 2){
										set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i+1, j, Raindrop);
										set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j, 0);
									} else if (rain == 31){
										for (unsigned int h=i; h<=i+2; h+=1){
											for (unsigned int k=j-1; k<=j+1; k+=1){
												if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
													set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, h, k, 0);
												}
											}
										}
									} else if (rain == 32){
										for (unsigned int h=i; h<=i+2; h+=1){
											for (unsigned int k=j-1; k<=j+1; k+=1){
												if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
													if (Spiel[0][h][k] == Raindrop){
														set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, h, k, geben);
													} else {
														set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, h, k, 0);
													}
												}
											}
										}
										set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j, 0);
										set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i+1, j, geben);
									} else if (rain == 4){
										if((Spiel[0][i-1][j] == geben)||(Spiel[0][i+1][j] == geben)||(Spiel[0][i][j-1] == geben)||(Spiel[0][i][j+1] == geben)){
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j, geben);
										} else {
											if (i != (m-2)){
												set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i+1, j, Raindrop);
											}
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j, 0);
										}

									} else if (rain == 5){
										if (Spiel[0][i+1][j] == geben){
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i-1, j, geben);
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i+1, j, 0);
										} else if (Spiel[0][i][j+1] == geben){
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j-1, geben);
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j+1, 0);
										} else if (((j-1)>=1)&&(Spiel[0][i][j-1] == geben) && ((Spiel[0][i][j-2] != Raindrop)||(Spiel[0][i+1][j-2] != geben)) &&(Spiel[0][i-1][j-1] != Raindrop)){
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j+1, geben);
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j-1, 0);
										} else if (((i-1)>=1)&&(Spiel[0][i-1][j] == geben) && (Spiel[0][i-2][j] != Raindrop) && (Spiel[0][i-1][j+1] != Raindrop)){
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i+1, j, geben);
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i-1, j, 0);
										}
										set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i+1, j, Raindrop);
										set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j, 0);
									}
								} else {

									if (rain == 5){
										if (Spiel[0][i+1][j] == geben){
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i-1, j, geben);
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i+1, j, 0);
										} else if (Spiel[0][i][j+1] == geben){
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j-1, geben);
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j+1, 0);
										} else if (((j-1)>=1)&&(Spiel[0][i][j-1] == geben) && ((Spiel[0][i][j-2] != Raindrop)||(Spiel[0][i+1][j-2] != geben)) &&(Spiel[0][i-1][j-1] != Raindrop)){
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j+1, geben);
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j-1, 0);
										} else if (((i-1)>=1)&&(Spiel[0][i-1][j] == geben) && (Spiel[0][i-2][j] != Raindrop) && (Spiel[0][i-1][j+1] != Raindrop)){
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i+1, j, geben);
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i-1, j, 0);
										}
									}

									if (rain == 4){
										if((Spiel[0][i-1][j] == geben)||(Spiel[0][i][j-1] == geben)||(Spiel[0][i][j+1] == geben)){
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j, geben);
										} else {
											if (i != (m-2)){
												set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i+1, j, Raindrop);
											}
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j, 0);
										}
									} else {
										if (i != (m-2)){
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i+1, j, Raindrop);
										}
										set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j, 0);
									}
								}
							}
						}
					}
					if (rain_drops == 1){
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, 1, number_rain+(geben-1)*7, Raindrop);
					} else if (rain_drops == 2){
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, 1, geben*7-number_rain, Raindrop);
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, 1, (geben-1)*7+number_rain, Raindrop);

					} else if (rain_drops == 4){
						for (unsigned int s=1+(geben-1)*7; s<=6+(geben-1)*7; s+=1){
							if ((s != geben*7-number_rain)&&(s != (geben-1)*7+number_rain)){
								set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, 1, s, Raindrop);
							}
						}
					} else if (rain_drops == 5){
						for (unsigned int s=1+(geben-1)*7; s<=6+(geben-1)*7; s+=1){
							if (s != geben*7-number_rain){
								set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, 1, s, Raindrop);
							}
						}
					} else if (rain_drops == 6){
						for (unsigned int s=1+(geben-1)*7; s<=6+(geben-1)*7; s+=1){
							set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, 1, s, Raindrop);
						}
					}

				}
				number_rain = (number_rain%6) + 1;
				
				if (real == evet) {
					if (level[0] == 5) {
						level[0] = 2;
					}
					if (Opague_o.characterization >= 1) {
						show_field (number_of_players, level, Sf_permutations, Opague_o.field, Opague_o.field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
					} else {
						show_field (number_of_players, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
					}
					if (level[0] == 2) {
						level[0] = 5;
					}
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
			set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, 0, j, 0);
			set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, m-1, j, 0);
		}
		for (unsigned int i=0; i<m; i+=1){
			set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, 0, 0);
			set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, n-1, 0);
		}

		if (real == evet) {
			if (level[0] <= 2) {
				printf("\n");
				printf("		Get:");
				for (unsigned int q=2; q<=number_of_players; q++) {
					if (q != 2 ) {
						printf("or");
					}
					printf(" [1][%u] ", (q-1)*7);
				}
				printf("\n");
				printf("\n");
			}

			for (unsigned int q=2; q<=number_of_players; q++) {
				if (Spiel[0][1][(q-1)*7] != 0){
					for (unsigned int p=1; p<=number_of_players; p+=1) {
						if (Spiel[0][1][(q-1)*7] == p){
							rmv->win_condition[p] = kazanacak;
							rmv->win_condition[0] = biri_kazanacak;
						}
					}
				}
			}
			for (unsigned int p=1; p<=number_of_players; p++) {
				if (rmv->win_condition[p] == kazanacak){
					printf("	Sieg:	Spieler %u \n", p);
				}
			}
			if (rmv->win_condition[0] == biri_kazanacak){
				*g = 0;
				// printf("g=0 line: 113587");	//test
			}

			for (unsigned int q=2; q<=number_of_players; q+=1) {
				if ((Field[0][1][(q-1)*7-1] == geben)||(Field[0][1][(q-1)*7+1] == geben)||(Field[0][2][(q-1)*7] == geben)){
					rmv->numbers_of_[geben][0][0] += 1;
				}
			}
		}
	}

	// printf("	realize_modifications ok.9\n ");	//test

	if (gamemode_played == Race) {

		if ((*g-1)%rmv->freq == (rmv->freq-1)){
			count_freq = (*g/rmv->freq) +1;
			
			if (real == evet) {
				if (count_freq == n-4){
					printf("	All lost! \n");
					show_field (number_of_players, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
					*g = 0;
					// printf("g=0 line: 13608");	//test
				}
				printf("\n");
				printf("\n");
				printf("	It moved forward! \n");
				printf("\n");
				printf("\n");
			}
			
			ahead (Spiel, Field, m, count_freq, Allocation_o, Opague_o.field, number_of_players, geben, gamemode_played);
			
			if (real == evet) {
				if (Opague_o.characterization >= 1) {
					opague_builder (Field, Opague_o, m, n, (geben%number_of_players)+1, rmv->AOP, Allocation_o, number_of_players, gamemode_played);
					show_field (number_of_players, level, Sf_permutations, Opague_o.field, Opague_o.field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
				} else {
					show_field (number_of_players, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
				}
			}
			
		}
		
		if (real == evet) {
			for (unsigned int p=1; p<=number_of_players; p++) {
				for (unsigned int i=1+(p-1)*(1+((m-2-(number_of_players-1))/number_of_players)); i<1+p*(1+((m-2-(number_of_players-1))/number_of_players)); i+=1){		//Spiel-Ende?
					if (Field[0][i][n-2] == p){
						rmv->win_condition[p] = kazanacak;
						rmv->win_condition[0] = biri_kazanacak;
					}
				}
			}
			for (unsigned int p=1; p<=number_of_players; p++) {
				if (rmv->win_condition[p] == kazanacak) {
					printf (" Sieg: Spieler %u \n", p);
				}
			}
			if (rmv->win_condition[0] == biri_kazanacak){
				*g = 0;
			// printf("g=0 line: 13640");	//test
			}

			for (unsigned int i=1; i<(m-1); i+=1){
				if (Field[0][i][n-3] == geben){
					rmv->numbers_of_[geben][0][0] += 1;	//Matchballs
					break;	// to count only once
				}
			}
		}
	}

	// printf("	realize_modifications ok.10\n ");	//test

	if (real == evet) {
		if (gamemode_played == Fall) {
			if (((*g-1)%turns_per_drop) == 1){
				for (unsigned int j=1; j<n-1; j+=1){
					if (Field[0][m-2][j] == Fall_ball){
						if ((rmv->var_[1] == 1010)||(rmv->var_[2] == 1010*2)){
							if (fall_back == (n-1)/2){
								rmv->Points[0] -= 1;
							} else if (fall_back < (n-1)/2){
								for (unsigned int p=1; p<=number_of_players; p++) {
									if (p%2 == 0) {
										rmv->Points[p] -= (((n-1)/2) - j);
									}
								}
							} else if (fall_back > (n-1)/2){
								for (unsigned int p=1; p<=number_of_players; p++) {
									if (p%2 == 1) {
										rmv->Points[p] -= (j - (n-1)/2);
									}
								}
							}
						}
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, 1, (n-1)/2, Fall_ball);
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, m-2, j, 0);
						fall_controll = 1;

						printf ("\n");
						printf ("\n");
						printf ("\n");
						printf ("	It reached the ground!\n");
						printf ("\n");

						if (Opague_o.characterization >= 1) {
							opague_builder (Field, Opague_o, m, n, (geben%number_of_players)+1, rmv->AOP, Allocation_o, number_of_players, gamemode_played);
							show_field (number_of_players, level, Sf_permutations, Opague_o.field, Opague_o.field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
						} else {
							show_field (number_of_players, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
						}

						if (j == (n-1)/2){
							rmv->Points[0] += 1;
							printf ("	It is an undecided #-square! \n");
						} else if (j < (n-1)/2){
							for (unsigned int p=1; p<=number_of_players; p++) {
								if (p%2 == 0) {
									rmv->Points[p] += (((n-1)/2) - j);
									printf ("	Points player %u:	+ %u \n", p, ((n-1)/2) - j);
								}
							}
						} else if (j > (n-1)/2){
							for (unsigned int p=1; p<=number_of_players; p++) {
								if (p%2 == 1) {
									rmv->Points[p] += (j - (n-1)/2);
									printf ("	Points player %u:	+ %u \n", p, (j - (n-1)/2));
								}
							}
						}
						fall_back = j;

						if (Journey_o.characterization != 0){			//Übertragung		journey-Frequenz = Fall-Frequenz

							printf ("\n");
							printf ("\n");
							printf ("	It is time for a journey... \n");
							printf ("\n");

							for (unsigned int i=1; i<m-1; i+=1){
								for (unsigned int j=1; j<n-1; j+=1){
									if (Field[0][i][j] <= number_of_players){
										set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, i, j, Journey_o.field[0][i][j]);
										set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Journey_o.field, 0, i, j, 0);
									} else {
										set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Journey_o.field, 0, i, j, 0);
									}
								}
							}
						}
						break;	//because i found the only one existing Fall_ball
					}
				}
			}

			if ((((*g-1)%turns_per_drop) == 1)&&(fall_controll != 1)){
				for (unsigned int i=1; i<m-2; i+=1){
					for (unsigned int j=1; j<n-1; j+=1){
						if (Field[0][i][j] == Fall_ball){
							set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, i, j, 0);
							if ((i+speed_of_fall) <= (m-2)) {
								for (unsigned int k=i; k<(i+speed_of_fall); k+=1) {
									set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, k, j, 0);
								}
								set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, i+speed_of_fall, j, Fall_ball);
							} else {
								set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, m-2, j, Fall_ball);
							}

							einmal = 1;
							printf ("\n");
							printf ("\n");
							printf ("\n");
							printf ("	It fell down!\n");
							printf ("\n");

							if (Opague_o.characterization >= 1) {
								opague_builder (Field, Opague_o, m, n, (geben%number_of_players)+1, rmv->AOP, Allocation_o, number_of_players, gamemode_played);
								show_field (number_of_players, level, Sf_permutations, Opague_o.field, Opague_o.field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
							} else {
								show_field (number_of_players, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
							}

							break;	//the only ball i can find
						}
					}
					if (einmal == 1){
						break;
					}
				}
				einmal = 0;
			}
			fall_controll = 0;
			
			if ((rmv->var_[1] != 1010) && (rmv->var_[2] != 1010*2)){
				if (rmv->Points[1] > rmv->Points[2]){	//Vertreter der Parteien
				for (unsigned int p=1; p<=number_of_players; p++) {
					if (p%2 == 1) {
					rmv->numbers_of_[p][0][0] += 1;
					}
				}
				} else if (rmv->Points[1] < rmv->Points[2]){	//Vertreter der Parteien
				for (unsigned int p=1; p<=number_of_players; p++) {
					if (p%2 == 0) {
					rmv->numbers_of_[p][0][0] += 1;
					}
				}
				}
			}
			if (rmv->Points[1] >= points_for_win){		//Vertreter der Parteien	//Spiel-Ende
				for (unsigned int p=1; p<=number_of_players; p++) {
				if (p%2 == 1) {
					printf ("	Sieg: Spieler %u \n", p);
				}
				}
				*g = 0;
				// printf("g=0 line: 13798");	//test
			}
			if (rmv->Points[2] >= points_for_win){	//Vertreter der Parteien	//Spiel-Ende
				for (unsigned int p=1; p<=number_of_players; p++) {
				if (p%2 == 0) {
					printf ("	Sieg: Spieler %u \n", p);
				}
				}
				*g = 0;
				// printf("g=0 line: 13807");	//test
			}
			
			// printf("	realize_modifications ok.11\n ");	//test
		} else if (gamemode_played == Hunt) {
			unsigned int a;
			a = 0;
			for (unsigned int i=1; i<m-1; i+=1){
				for (unsigned int j=1; j<n-1; j+=1){
					if (Field[0][i][j] == 11){

						printf("\n");
						for (unsigned int h=i-1; h<=i+1; h++) {
							for (unsigned int k=j-1; k<=j+1; k++) {
								if (((h+k)%2 != (i+j)%2)&&(Field[0][h][k] > 1)) {
									printf (" Sieg: Spieler %u \n", Field[0][h][k]);
									a += 1;
								}
							}
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

						for (unsigned int h=i-1; h<=i+1; h++) {
							for (unsigned int k=j-1; k<=j+1; k++) {
								if (((h+k)%2 == (i+j)%2)&&(Field[0][h][k] > 1)) {
									for (unsigned int p=2; p<=number_of_players; p+=1) {
										if (Field[0][h][k] == p) {
										rmv->numbers_of_[p][0][0] += 1;
										break;	//player found
										}
									}
								}
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
				show_field (number_of_players, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
				*g = 0;
				// printf("g=0 line: 13864");	//test
			}

			a = 0;
			if ((rmv->round_counter == rmv->rtc)&&(geben == number_of_players)) {
				printf("	Sieg: Spieler 1");
				*g = 0;
				// printf("g=0 line: 13871");	//test
			}
			// printf("	realize_modifications ok.12\n ");	//test

		} else if (gamemode_played == Sand) {
			for (unsigned j=1; j<=n-2; j++) {
				if (Field[0][1][j] != 0) {
					printf("	Sieg Spieler: %u \n", Field[0][1][j]);
					rmv->win_condition[0] = biri_kazanacak;
				}
			}
			if (rmv->win_condition[0] == biri_kazanacak) {
				*g = 0;
				// printf("g=0 line: 13887");	//test
			}

			if ((*g - rmv->all_turns_correction)%((number_of_players - rmv->player_counter)*information_code[3]) == 0) {

				if (Opague_o.characterization >= 1) {
					opague_builder (Field, Opague_o, m, n, (geben%number_of_players)+1, rmv->AOP, Allocation_o, number_of_players, gamemode_played);
					show_field (number_of_players, level, Sf_permutations, Opague_o.field, Opague_o.field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
				} else {
					show_field (number_of_players, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
				}

				if (information_code[1] == 1) {
					for (unsigned int i=1; i<=m-2; i++) {
						for (unsigned int j=1; j<=n-2; j++) {
							anything = 0;
							while (anything != information_code[2]) {
								if ((Field[0][i+anything][j] != 0)&&(i+anything+1 != m-1)&&(Field[0][i+anything+1][j] == 0)) {
								set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, i+anything+1, j, Field[0][i+anything][j]);
								set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, i+anything, j, 0);
								}
								anything += 1;
							}
							anything = 0;
						}
					}
				} else if (information_code[1] == 2) {
					for (unsigned int i=m-2; i>=1; i--) {
						for (unsigned int j=n-2; j>=1; j--) {
							anything = 0;
							while (anything != information_code[2]) {
								if ((Field[0][i+anything][j] != 0)&&(i+anything+1 != m-1)&&(Field[0][i+anything+1][j] == 0)) {
								set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, i+anything+1, j, Field[0][i+anything][j]);
								set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, i+anything, j, 0);
								}
								anything += 1;
							}
							anything = 0;
						}
					}
				}
			}

			// printf("	realize_modifications ok.13\n ");	//test
		}
	}

	if (figures != 0) {
		if (real == evet) {
			if (Opague_o.characterization >= 1) {
				opague_builder (Field, Opague_o, m, n, (geben%number_of_players)+1, rmv->AOP, Allocation_o, number_of_players, gamemode_played);
				show_field (number_of_players, level, Sf_permutations, Opague_o.field, Opague_o.field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
			} else {
				show_field (number_of_players, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
			}
		}

		figure_check (Spiel, m, n, number_of_players, Growth_players, Allocation_o, Opague_o.field, geben, gamemode_played);
	}

	// printf("	realize_modifications ok.14\n ");	//test

	if (avalanche != 0) {
		if (real == evet) {
			if (Opague_o.characterization >= 1) {
				opague_builder (Field, Opague_o, m, n, (geben%number_of_players)+1, rmv->AOP, Allocation_o, number_of_players, gamemode_played);
				show_field (number_of_players, level, Sf_permutations, Opague_o.field, Opague_o.field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
			} else {
				show_field (number_of_players, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
			}
		}
		Avalanche_maker (Spiel, Field, Opague_o.field, Allocation_o, geben, gamemode_played, number_of_players, m, n);
	}
	
	if (spreading != 0) {
		if (real == evet) {
			if (Opague_o.characterization >= 1) {
				opague_builder (Field, Opague_o, m, n, (geben%number_of_players)+1, rmv->AOP, Allocation_o, number_of_players, gamemode_played);
				show_field (number_of_players, level, Sf_permutations, Opague_o.field, Opague_o.field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
			} else {
				show_field (number_of_players, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
			}
		}
		Spreading_maker (Spiel, Field, Opague_o.field, Allocation_o, geben, gamemode_played, number_of_players, m, n);
	}

	// printf("	realize_modifications ok.15\n ");	//test
	if (real == evet) {
		reset_of_ges (ges, number_of_players);	//checklist
		if (gamemode_played == Rain) {
			ges_counter (Field, m, n, ges, number_of_players);

			for (unsigned int p=1; p<=number_of_players; p++) {
				if (ges[p] == 0){
					if (rain_obj == 1){
						if (p <= number_of_players/2) {
						set_triangle_unten_links (single_option_representives.inverted, Field, p, m-2, 1+7*((p-1)/2));
						} else if (p > number_of_players/2) {
						set_triangle_unten_rechts (single_option_representives.inverted, Field, p, m-2, n-2-7*((p-2)/2));
						}

					} else {
						printf("		Spieler %u, you are out. \n", p);
						ges[p] = p*1010;
						rmv->player_counter += 1;
					}
				}
			}

		} else if (gamemode_played == Sand) {
			ges_counter (Field, m, n, ges, number_of_players);
			who_is_out (ges, number_of_players, rmv);

			if (rmv->player_counter == number_of_players-1) {
				for (unsigned int p=1; p<=number_of_players; p++) {
				if (ges[p] != p*1010) {
					printf("	Sieg Spieler: %u \n", p);
					break;
				}
				}
				*g = 0;
				// printf("g=0 line: 13992");	//test
			}

		} else if (gamemode_played == Survive) {
			ges_counter (Field, m, n, ges, number_of_players);
			who_is_out (ges, number_of_players, rmv);

		} else if (gamemode_played == Dynamic) {
			ges_counter (Field, m, n, ges, number_of_players);
			who_is_out (ges, number_of_players, rmv);

			if (rmv->player_counter == number_of_players-1) {
				for (unsigned int t=1; t<=number_of_players; t+=1) {
					printf("\n");
					if (ges[t] != t*1010) {
						printf("	Sieg: Spieler %u \n", t);
						break;
					}
				}
				*g = 0;
				// printf("g=0 line: 14012");	//test
			}

			if (number_of_players == 5) {
				if ((rmv->player_counter == 3)&&(((ges[4] != 4040)&&(ges[1] != 1010))||((ges[5] != 5050)&&(ges[3] != 3030)))) {
				for (unsigned int t=1; t<=number_of_players; t+=1) {
					printf("\n");
					if (ges[t] != t*1010) {
					printf("	Sieg: Spieler %u \n", t);
					}
				}
				*g = 0;
				// printf("g=0 line: 14024");	//test
				}
			} else if (number_of_players == 6) {
				if ((rmv->player_counter == 4)&&(((ges[2] != 2020)&&(ges[5] != 5050))||((ges[4] != 4040)&&(ges[1] != 1010))||((ges[3] != 3030)&&(ges[6] != 6060)))) {
					for (unsigned int t=1; t<=number_of_players; t+=1) {
						printf("\n");
						if (ges[t] != t*1010) {
						printf("	Sieg: Spieler %u \n", t);
						}
					}
					*g = 0;
				}
			} else if (number_of_players == 7) {
				if ((rmv->player_counter == 5)&&(((ges[1] != 1010)&&(ges[5] != 5050))||((ges[4] != 4040)&&(ges[7] != 7070))||((ges[3] != 3030)&&(ges[6] != 6060)))) {
					for (unsigned int t=1; t<=number_of_players; t+=1) {
						printf("\n");
						if (ges[t] != t*1010) {
						printf("	Sieg: Spieler %u \n", t);
						}
					}
					*g = 0;
				}
			} else if (number_of_players == 8) {
				if ((rmv->player_counter == 6)&&(((ges[1] != 1010)&&(ges[5] != 5050))||((ges[3] != 3030)&&(ges[7] != 7070))||((ges[2] != 2020)&&(ges[6] != 6060))||((ges[4] != 4040)&&(ges[8] != 8080)))) {
					for (unsigned int t=1; t<=number_of_players; t+=1) {
						printf("\n");
						if (ges[t] != t*1010) {
						printf("	Sieg: Spieler %u \n", t);
						}
					}
					*g = 0;
				}
			} else if (number_of_players == 9) {
				if ((rmv->player_counter == 6)&&(((ges[1] != 1010)&&(ges[4] != 4040)&&(ges[7] != 7070))||((ges[3] != 3030)&&(ges[9] != 9090)&&(ges[6] != 6060))||((ges[2] != 2020)&&(ges[5] != 5050)&&(ges[8] != 8080)))) {
					for (unsigned int t=1; t<=number_of_players; t+=1) {
						printf("\n");
						if (ges[t] != t*1010) {
						printf("	Sieg: Spieler %u \n", t);
						}
					}
					*g = 0;
				} else if ((rmv->player_counter == 7)&&(((ges[1] != 1010)&&(ges[4] != 4040))||((ges[1] != 1010)&&(ges[7] != 7070))||((ges[4] != 4040)&&(ges[7] != 7070))||((ges[2] != 2020)&&(ges[5] != 5050))||((ges[2] != 2020)&&(ges[8] != 8080))||((ges[8] != 8080)&&(ges[5] != 5050))||((ges[3] != 3030)&&(ges[6] != 6060))||((ges[3] != 3030)&&(ges[9] != 9090))||((ges[6] != 6060)&&(ges[9] != 9090)))) {
					for (unsigned int t=1; t<=number_of_players; t+=1) {
						printf("\n");
						if (ges[t] != t*1010) {
						printf("	Sieg: Spieler %u \n", t);
						}
					}
					*g = 0;
				}
			}

		} else if (gamemode_played == Ulcer) {
			for (unsigned int i=1; i<m-1; i+=1){
				for (unsigned int j=1; j<n-1; j+=1){
					for (unsigned int p=1; p<=number_of_players; p++) {
						if ((Field[0][i][j] == p)&&(ges[p] < 1000)) {
						ges[p] += 1;
						if (rmv->ulcer_start[p] == missing) {
							rmv->ulcer_start[p] = existing;
						}
						break;	//to be faster
						}
					}
				}
			}

			ges0_reset_and_counter (ges, number_of_players);

			if ((ges[1] == 0)&&(rmv->ulcer_start[1] == existing)&&(geben == 1)) {
				rmv->ulcer_start[1] = missing;
				if (rmv->ulcer_lifes[1] > 0) {
					printf("		Spieler 1, you lost a life. \n");
					rmv->ulcer_lifes[1] -= 1;
				} else if (rmv->ulcer_start[0] == 0) {	//rmv->ulcer_start[0] ist eine Einstellung des Spielmodus
					printf("		Niederlage: Spieler 1 \n");
					rmv->ulcer_start[0] = 100;
					*g = 0;
				} else if (rmv->ulcer_start[0] == 1) {
					printf("		Spieler 1, you are out. \n");
					rmv->player_counter += 1;
					ges[1] = 1010;

					for (unsigned int p=1; p<=number_of_players; p+=1) {
						if (rmv->out_counter[p] == 0) {
						rmv->out_counter[p] = 1;
						break;	// to be faster
						}
					}
				}
			}

			for (unsigned int p=2; p<=number_of_players; p+=1) {
				if ((ges[p] == 0)&&(number_of_players >= p)&&(rmv->ulcer_start[p] == existing)&&(geben == p)) {
				rmv->ulcer_start[p] = missing;
				if (rmv->ulcer_lifes[p] > 0) {
					printf("		Spieler %u, you lost a life. \n", p);
					rmv->ulcer_lifes[p] -= 1;
				} else {
					printf("		Spieler %u, you are out. \n", p);
					rmv->player_counter += 1;
					ges[p] = 1010*p;

					for (unsigned int q=1; q<=number_of_players; q+=1) {
					if (rmv->out_counter[q] == 0) {
						rmv->out_counter[q] = p;
						break;
					}
					}
				}
				}
			}

			if (rmv->player_counter == (number_of_players - 1)) {
				printf("		Game over, you can see the master of Ulcer. \n");
				show_field (number_of_players, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
				*g = 0;
			}
			if (rmv->player_counter == number_of_players) {
				printf("		Game over, everybody died. \n");
				show_field (number_of_players, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
				*g = 0;
			}
			if ((geben == number_of_players)&&(rmv->rtp == rmv->round_counter)) {
				printf("\n");
				printf("	Congratulations Player 1, you are still alive!\n");
				printf("\n");
				*g = 0;
			}
			if (ges[0] == 0) {
				printf("		This game stucked. Try again! \n");
			}
			// ges-x in ges[x], done

		} else if (gamemode_played == Arena) {
			ges_counter (Field, m, n, ges, number_of_players);
			who_is_out (ges, number_of_players, rmv);

			if (rmv->player_counter == (number_of_players - 1)) {
				printf("		Game over, you can see the master of the Arena. \n");
				show_field (number_of_players, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
				*g = 0;
			}
			if (rmv->player_counter == number_of_players) {
				printf("		Game over, everybody died. \n");
				show_field (number_of_players, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
				*g = 0;
			}

			if ((rmv->round_counter == rmv->rtp)&&(geben == number_of_players)) {
				printf(" \n ");
				printf("	Game over. \n ");
				printf(" \n ");

				ges0_reset_and_counter (ges, number_of_players);

				for (unsigned int p=ges[0]; p>0; p-=1) {
					for (unsigned int q=1; q<=number_of_players; q+=1) {
						if (ges[q] == p) {
							printf("	Spieler %u: %u squares \n", q, p);
						}
					}
					printf("\n");
					printf("\n");
				}
				*g = 0;
			}

		} else if (gamemode_played == Contact) {
			ges_counter (Field, m, n, ges, number_of_players);
			who_is_out (ges, number_of_players, rmv);

			for (unsigned int p=1; p<=number_of_players; p++) {
				if (ges[p] <= 5){
					rmv->numbers_of_[p][0][0] += 1;
				}
			}

			if (rmv->player_counter == (number_of_players - 1)) {
				for (unsigned int p=1; p<=number_of_players; p++) {
					if (ges[p] != p*1010) {
						printf("	Sieg: Spieler %u \n", p);
					}
					break;
				}
				show_field (number_of_players, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
				*g = 0;
				// printf("g=0 line: 14212");	//test
			}

		} else if (gamemode_played == Hunt) {
			ges_counter (Field, m, n, ges, number_of_players);

			if (ges[1] == 0) {
				printf("		Niederlage: Spieler 1 \n");
				*g = 0;
			} else {
				who_is_out (ges, number_of_players, rmv);
			}

			if (rmv->player_counter == (number_of_players - 1)) {
				printf("		Game over. \n		Sieg: Spieler 1. \n");
				show_field (number_of_players, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
				*g = 0;
			}

		} else if ((gamemode_played == Classic)||(gamemode_played == Collect)||(gamemode_played == Fall)||(gamemode_played == Fight)||(gamemode_played == Race)||(gamemode_played == Quidditch)||(gamemode_played == Duell)) {
			ges_counter (Field, m, n, ges, number_of_players);
			who_is_out (ges, number_of_players, rmv);

			if (rmv->player_counter == (number_of_players - 1)) {
				for (unsigned int p=1; p<=number_of_players; p++) {
					if (ges[p] != 1010*p) {
						printf(" Sieg: Spieler %u. \n", p);
						break;
					}
				}
				show_field (number_of_players, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
				*g = 0;
			}
			if ((gamemode_played == Fight)||(gamemode_played == Duell)) {
				for (unsigned int p=1; p<=number_of_players; p++) {
					if (ges[p]<5){
						rmv->numbers_of_[p][0][0] += 1;
					}
					// if (ges[p] > limits.at_all){	//test
					// printf("too much\n");
					// }
				}
			}
		}
	}
	
	// /*
	if (gamemode_played == Quidditch) {	//Selected actions/movements by teammembers
		if (real == evet) {
			Localization_of_Moc (Field, m, n, Moc_Quaffel, Moc_Schnatz, Moc_Klatscher);	//better save than sorry. (Field before Moc)
			
			Quidditch_Klatscher_players_actions (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, m, n, g, Moc_Schnatz, Moc_Quaffel, Qs, Opague_o, level, Sf_permutations, information_code, Growth_players);	//1-time
			
			Quidditch_Quaffel_players_actions (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, m, n, g, Moc_Schnatz, Moc_Quaffel, Qs, Opague_o, level, Sf_permutations, information_code, Growth_players, ges, limits.at_all);	//2-times
			
			Quidditch_Schnatz_player_actions (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, m, n, g, Moc_Schnatz, Moc_Quaffel, Qs, Opague_o, level, Sf_permutations, information_code, Growth_players);	//1-time
			
			#ifdef Quidditch_mistake_search
			printf("	Quidditch_team_actions.ok \n");	//test
			#endif
			
			if ((geben == number_of_players)&&(*g != 0)) {
				
				Quidditch_Schnatz_movements (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, m, n, Moc_Schnatz, Qs, rmv->use_number);
				
				Localization_of_Moc (Field, m, n, Moc_Quaffel, Moc_Schnatz, Moc_Klatscher);	//better save than sorry.
				
				show_field (number_of_players, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
				
				Quidditch_Klatscher_movements (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, m, n, Moc_Klatscher, Qs);
				
				Localization_of_Moc (Field, m, n, Moc_Quaffel, Moc_Schnatz, Moc_Klatscher);	//better save than sorry.
				
				show_field (number_of_players, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
				
				#ifdef Quidditch_mistake_search
				printf("	Quidditch_S/K_actions.ok \n");	//test
				#endif
			}
		}
		
		Localization_of_Moc (Field, m, n, Moc_Quaffel, Moc_Schnatz, Moc_Klatscher);	//better save than sorry.
	}
	// */
	
	#ifdef VERBOSE
	printf("	realize_modifications ok.16\n ");	//test
	printf(" player_counter: %u \n ", rmv->player_counter);	//test
	if ((rmv->player_counter != 0)&&(real == evet)) {
		printf(" player_counter != 0 \n ");	//test
		scanf("%u", &pause);	//test
	}
	#endif
	
	if (real == evet) {
		if (rmv->player_counter == number_of_players) {	//Notbremse
			printf("	No player left \n ");
			*g = 0;
		}
	}
}
// */


void figure_check (Spielfeld Field, unsigned int m, unsigned int n, unsigned int number_of_players, Growth_Player* Growth_players, Special_Fields Allocation_o, Spielfeld Opague_o_field, unsigned int geben, unsigned int gamemode_played) {
	unsigned int figure_check_counter;
	figure_check_counter = 0;

	for (unsigned int i=1; i<=m-2; i++) {
		for (unsigned int j=1; j<=n-2; j++) {
			figure_check_counter = 0;

			for (unsigned int z=0; z<=2; z++) {
				if ((j+2<=n-2)&&(i+2<=m-2)&&(Field[0][i][j+z] == 0)&&(Field[0][i+2][j+z] == 0)) {
					figure_check_counter += 2;
				}
			}
			for (unsigned int t=1; t<=1; t++) {
				if ((j+2<=n-2)&&(i+2<=m-2)&&(Field[0][i+t][j] == 0)&&(Field[0][i+t][j+2] == 0)) {
					figure_check_counter += 2;
				}
			}
			if (figure_check_counter == 8) {	//Seed
				figure_check_counter = 0;

				if ((Field[0][i+1][j+1] != 0)&&(Field[0][i+1][j+1] <= number_of_players)) {

					Square_color_interpretation (Growth_players, geben, number_of_players, Field[0][i+1][j+1]);
					printf("	Time for a Seed \n\n");

					for (unsigned int t=0; t<=2; t++) {
						for (unsigned int z=0; z<=2; z++) {
							if ((t+z)%2 == 1) {
								set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, i+t, j+z, Field[0][i+1][j+1]);
							}
						}
					}
					set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, i+1, j+1, 0);
				}
			} else {
				figure_check_counter = 0;

				for (unsigned int z=0; z<=2; z++) {
					if ((j+2<=n-2)&&(i+3<=m-2)&&(Field[0][i][j+z] == 0)&&(Field[0][i+3][j+z] == 0)) {
						figure_check_counter += 2;
					}
				}
				for (unsigned int t=1; t<=2; t++) {
					if ((j+2<=n-2)&&(i+3<=m-2)&&(Field[0][i+t][j] == 0)&&(Field[0][i+t][j+2] == 0)) {
						figure_check_counter += 2;
					}
				}
				if (figure_check_counter == 10) {	//Grass
					figure_check_counter = 0;

					if ((Field[0][i+1][j+1] != 0)&&(Field[0][i+1][j+1] <= number_of_players)&&(Field[0][i+2][j+1] == Field[0][i+1][j+1])) {
						Square_color_interpretation (Growth_players, geben, number_of_players, Field[0][i+1][j+1]);
						printf("	Time for Grass \n\n");

						set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, i, j+1, Field[0][i+1][j+1]);
					}
				} else {
					figure_check_counter = 0;

					for (unsigned int z=0; z<=3; z++) {
						if ((j+3<=n-2)&&(i+3<=m-2)&&(Field[0][i][j+z] == 0)&&(Field[0][i+3][j+z] == 0)) {
							figure_check_counter += 2;
						}
					}
					for (unsigned int t=1; t<=2; t++) {
						if ((j+3<=n-2)&&(i+3<=m-2)&&(Field[0][i+t][j] == 0)&&(Field[0][i+t][j+3] == 0)) {
							figure_check_counter += 2;
						}
					}
					if (figure_check_counter == 12) {
						figure_check_counter = 0;

						if ((Field[0][i+1][j+1] != 0)&&(Field[0][i+1][j+1] <= number_of_players)) {
							for (unsigned int t=1; t<=2; t++) {
								for (unsigned int z=1; z<=2; z++) {
									if (((t+z)%2 == 0)&&(Field[0][i+t][j+z] == Field[0][i+1][j+1])) {
										figure_check_counter += 1;
									} else if (((t+z)%2 == 1)&&(Field[0][i+t][j+z] == 0)) {
										figure_check_counter += 3;
									} else if (((t+z)%2 == 1)&&(Field[0][i+t][j+z] == Field[0][i+1][j+1])) {
										figure_check_counter += 9;
									}
								}
							}
							if (figure_check_counter == 8) {	//Windmill#2
								figure_check_counter = 0;
								
								Square_color_interpretation (Growth_players, geben, number_of_players, Field[0][i+1][j+1]);
								printf("	Time for a Windmill \n\n");

								for (unsigned int t=2; t>=1; t--) {
									for (unsigned int z=2; z>=1; z--) {
										if ((z+t)%2 == 1) {
											set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, i+t, j+z, Field[0][i+1][j+1]);
										} else if ((z+t)%2 == 0) {
											set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, i+t, j+z, 0);
										}
									}
								}
							} else if (figure_check_counter == 20) {	//Popcorn
								figure_check_counter = 0;
								
								Square_color_interpretation (Growth_players, geben, number_of_players, Field[0][i+1][j+1]);
								printf("	Time for Popcorn \n\n");

								for (unsigned int t=1; t<=2; t++) {
									set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, i+t, j, Field[0][i+1][j+1]);
									set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, i+t, j+3, Field[0][i+1][j+1]);
								}
								for (unsigned int z=1; z<=2; z++) {
									set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, i, j+z, Field[0][i+1][j+1]);
									set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, i+3, j+z, Field[0][i+1][j+1]);
								}
								for (unsigned int t=2; t>=1; t--) {
									for (unsigned int z=2; z>=1; z--) {
										set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, i+t, j+z, 0);
									}
								}
							}

						} else if (Field[0][i+1][j+1] == 0) {	//Windmill#1

							if ((Field[0][i+1][j+2] != 0)&&(Field[0][i+1][j+2] <= number_of_players)&&(Field[0][i+2][j+1] == Field[0][i+1][j+2])&&(Field[0][i+2][j+2] == 0)) {
								
								Square_color_interpretation (Growth_players, geben, number_of_players, Field[0][i+1][j+2]);
								printf("	Time for a Windmill \n\n");

								for (unsigned int t=2; t>=1; t--) {
									for (unsigned int z=1; z<=2; z++) {
										if ((z+t)%2 == 0) {
											set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, i+t, j+z, Field[0][i+1][j+2]);
										} else if ((z+t)%2 == 1) {
											set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, i+t, j+z, 0);
										}
									}
								}
							}
						}

					} else {
						figure_check_counter = 0;

						for (unsigned int z=0; z<=4; z++) {
							if ((j+4<=n-2)&&(i+3<=m-2)&&(Field[0][i][j+z] == 0)&&(Field[0][i+3][j+z] == 0)) {
								figure_check_counter += 2;
							}
						}
						for (unsigned int t=1; t<=2; t++) {
							if ((j+4<=n-2)&&(i+3<=m-2)&&(Field[0][i+t][j] == 0)&&(Field[0][i+t][j+4] == 0)) {
								figure_check_counter += 2;
							}
						}
						if (figure_check_counter == 14) {
							figure_check_counter = 0;

							if ((Field[0][i+1][j+2] != 0)&&(Field[0][i+1][j+2] <= number_of_players)) {
								for (unsigned int t=1; t<=2; t++) {
									for (unsigned int z=1; z<=3; z++) {
										if (((t+z)%2 == 1)&&(Field[0][i+t][j+z] == Field[0][i+1][j+2])) {
											figure_check_counter += 1;
										} else if (((t+z)%2 == 0)&&(Field[0][i+t][j+z] == 0)) {
											figure_check_counter += 1;
										}
									}
								}
								if (figure_check_counter == 6) {	//Shield
									
									Square_color_interpretation (Growth_players, geben, number_of_players, Field[0][i+1][j+2]);
									printf("	Time for a Shield \n\n");

									set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, i+2, j, Field[0][i+1][j+2]);
									set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, i+2, j+4, Field[0][i+1][j+2]);

								}
							}
						} else {
							figure_check_counter = 0;

							for (unsigned int z=0; z<=4; z++) {
								if ((j+4<=n-2)&&(i+4<=m-2)&&(Field[0][i][j+z] == 0)&&(Field[0][i+4][j+z] == 0)) {
									figure_check_counter += 2;
								}
							}
							for (unsigned int t=1; t<=3; t++) {
								if ((j+4<=n-2)&&(i+4<=m-2)&&(Field[0][i+t][j] == 0)&&(Field[0][i+t][j+4] == 0)) {
									figure_check_counter += 2;
								}
							}
							if (figure_check_counter == 16) {
								figure_check_counter = 0;

								if ((Field[0][i+1][j+2] != 0)&&(Field[0][i+1][j+2] <= number_of_players)) {
									for (unsigned int t=1; t<=3; t++) {
										for (unsigned int z=1; z<=3; z++) {
											if (((t+z)%2 == 1)&&(Field[0][i+t][j+z] == Field[0][i+1][j+2])) {
												figure_check_counter += 1;
											} else if (((t+z)%2 == 0)&&(Field[0][i+t][j+z] == 0)) {
												figure_check_counter += 1;
											} else if (((t+z)%2 == 0)&&(Field[0][i+t][j+z] == Field[0][i+1][j+2])) {
												figure_check_counter += 9;
											}
										}
									}
									if (figure_check_counter == 9) {	//Flower
										figure_check_counter = 0;

										Square_color_interpretation (Growth_players, geben, number_of_players, Field[0][i+1][j+2]);
										printf("	Time for a Flower \n\n");

										set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, i+2, j, Field[0][i+1][j+2]);
										set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, i+2, j+4, Field[0][i+1][j+2]);
										set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, i, j+2, Field[0][i+1][j+2]);
										set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, i+4, j+2, Field[0][i+1][j+2]);

									} else if (figure_check_counter == 49) {	//Black hole

										Square_color_interpretation (Growth_players, geben, number_of_players, Field[0][i+1][j+1]);
										printf("	Time for a Black hole \n\n");

										for (unsigned int t=1; t<=3; t++) {
											for (unsigned int z=1; z<=3; z++) {
												if ((t != 2)&&(z != 2)) {
													set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, i+t, j+z, 0);
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}

		}
	}
	set_terminal_color (cNORMAL);
}


void inverted_organism (Spielfeld Spiel, unsigned int* level, Spielfeld Sf_permutations, Spielfeld Field, unsigned int geben, Spielfeld Opague_o_field, unsigned int gamemode_played, Special_Fields Allocation_o, unsigned int number_of_players, unsigned int m, unsigned int n, unsigned int* information_code, Growth_Player* Growth_players) {
	unsigned int edges_of_organism[4];	//0=oben, 1=rechts, 2=unten, 3=links

	show_field (number_of_players, level, Sf_permutations, Opague_o_field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);

	find_edges_of_organism_2dim (edges_of_organism, Spiel, geben, m, n);

	for (unsigned int i=edges_of_organism[0]; i<=edges_of_organism[2]; i++) {
		for (unsigned int j=edges_of_organism[3]; j<=edges_of_organism[1]; j++) {
			if (Spiel[0][i][j] == geben) {
				set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j, 0);
			} else if (Spiel[0][i][j] == 0) {
				set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j, geben);
			}
		}
	}

}

void find_edges_of_organism_2dim (unsigned int* edges_of_organism, Spielfeld Spiel, unsigned int geben, unsigned int m, unsigned int n) {
	for (unsigned int p=0; p<=3; p++) {
		edges_of_organism[p] = 0;
	}

	for (unsigned int i=1; i<=m-2; i++) {
		for (unsigned int j=1; j<=n-2; j++) {
			if (Spiel[0][i][j] == geben) {
				edges_of_organism[0] = i;
				edges_of_organism[1] = j;
				edges_of_organism[2] = i;
				edges_of_organism[3] = j;
				break;
			}
		}
		if (edges_of_organism[0] != 0) {
			break;
		}
	}

	for (unsigned int i=1; i<=m-2; i++) {
		for (unsigned int j=1; j<=n-2; j++) {
			if (Spiel[0][i][j] == geben) {
				if (i<edges_of_organism[0]) {
					edges_of_organism[0] = i;
				} else if (i>edges_of_organism[2]) {
					edges_of_organism[2] = i;
				}
				if (j>edges_of_organism[1]) {
					edges_of_organism[1] = j;
				} else if (j<edges_of_organism[3]) {
					edges_of_organism[3] = j;
				}
			}
		}
	}
}

void addition_maker (Spielfeld Field, unsigned int m, unsigned int n, unsigned int number_of_players, unsigned int geben, Spielfeld Opague_o_field, unsigned int gamemode_played, Special_Fields Allocation_o, unsigned int* ges) {
	Spielfeld Field_addition;
	unsigned int additional_counter;

	additional_counter = 0;
	Field_addition = Spielfeld_Create (m, n, 0);

	for (unsigned int i=1; i<=m-2; i++) {
		for (unsigned int j=1; j<=n-2; j++) {
			if (Field[0][i][j] == geben) {
				for (unsigned int t=0; t<=2; t++) {
					for (unsigned int z=0; z<=2; z++) {
						if (((t+z)%2 == 1)&&(Field[0][i-1+t][j-1+z] != 0)&&(Field[0][i-1+t][j-1+z] <= number_of_players)&&(Field[0][i-1+t][j-1+z] != geben)) {
							if (Field_addition[0][i-1+t][j-1+z] == 0) {
								additional_counter += Field[0][i-1+t][j-1+z];
								Field_addition[0][i-1+t][j-1+z] = 1;
							}
							if (Field_addition[0][i][j] == 0) {
								additional_counter += Field[0][i][j];
								Field_addition[0][i][j] = 1;
							}
						}
					}
				}
			}
		}
	}

	additional_counter = additional_counter%(number_of_players+1);
	if ((additional_counter != 0)&&(ges[additional_counter] == additional_counter*1010)) {
		additional_counter = 0;
	}

	for (unsigned int i=1; i<=m-2; i++) {
		for (unsigned int j=1; j<=n-2; j++) {
			if (Field_addition[0][i][j] != 0) {
				set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, i, j, additional_counter);
			}
		}
	}

	Spielfeld_Destroy (Field_addition, m, 0);
}

void projection_maker (Spielfeld Field, unsigned int number_of_players, unsigned int geben, Spielfeld Opague_o_field, unsigned int gamemode_played, Special_Fields Allocation_o, unsigned int direction, unsigned int intensity_minimum, unsigned int single_option_representives_intensity_loss_per_line_multiplication, unsigned int m, unsigned int n) {

	double intensity_counter, intensity_minimum_real, intensity_loss_per_line_multiplication_real;
	double Spielfeld_intensity[number_of_players][m][n];	//enthält die Intensitäten der Spieler, index_verschiebung geben-->Spielfeld_intensity[geben-1]
	unsigned int a;

	// printf("projection_maker ok1\n");	//test

	a = 0;
	intensity_counter = 1;
	intensity_minimum_real = 1.0*intensity_minimum/100;
	intensity_loss_per_line_multiplication_real = 1.0*single_option_representives_intensity_loss_per_line_multiplication/100;

	for (unsigned int p=0; p<number_of_players; p++) {
		for (unsigned int i=0; i<=m-1; i++) {
			for (unsigned int j=0; j<=n-1; j++) {
				Spielfeld_intensity[p][i][j] = 0.0;
			}
		}
	}

	// printf("projection_maker ok2\n");	//test

	for (unsigned int i=1; i<=m-2; i++) {

		// printf("projection_maker ok i=%u\n", i);	//test

		for (unsigned int j=1; j<=n-2; j++) {

			// printf("projection_maker ok i=%u, j=%u\n", i, j);	//test

			if (Field[0][i][j] <= number_of_players) {
				for (unsigned int p=1; p<=number_of_players; p++) {	//p entspricht den Spielern

					// printf("projection_maker ok i=%u, j=%u, p=%u \n", i, j, p);	//test

					if (direction == Changing) {
						direction = geben%Changing;
					}
					if (direction == Vertikal) {
						for (unsigned int k=1; k<=n-2; k++) {
							if (Field[0][i][k] == p) {
								if (j != k) {
									for (int q=1; q<=abs(j-k); q+=1) {
										intensity_counter *= intensity_loss_per_line_multiplication_real;
									}
								}
								Spielfeld_intensity[p-1][i][j] += intensity_counter;
								intensity_counter = 1;
							}
						}
					} else if (direction == Horizontal) {
						for (unsigned int h=1; h<=m-2; h++) {
							if (Field[0][h][j] == p) {
								if (i != h) {
									for (int q=1; q<=abs(i-h); q+=1) {
										intensity_counter *= intensity_loss_per_line_multiplication_real;
									}
								}
								Spielfeld_intensity[p-1][i][j] += intensity_counter;
								intensity_counter = 1;
							}
						}
					}
				}
			}
		}
	}

	for (unsigned int i=1; i<=m-2; i++) {
		for (unsigned int j=1; j<=n-2; j++) {
			for (unsigned int p=1; p<=number_of_players; p++) {
				for (unsigned int q=1; q<=number_of_players; q++) {
					if (p != q) {
						if (Spielfeld_intensity[p-1][i][j] > Spielfeld_intensity[q-1][i][j]) {
							a += 1;
						}
					}
				}
				if ((a == number_of_players-1)&&(Spielfeld_intensity[p-1][i][j] >= intensity_minimum_real)) {
					set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, i, j, p);
				}
				a = 0;
			}
		}
	}
}

void assassin_maker (unsigned int real, Spielfeld Spiel, unsigned int* level, Spielfeld Sf_permutations, Spielfeld Field, unsigned int geben, Special_Fields Opague_o, unsigned int gamemode_played, Special_Fields Allocation_o, unsigned int number_of_players, unsigned int m, unsigned int n, unsigned int AOP, unsigned int* information_code, Growth_Player* Growth_players) {
	unsigned int assassin_counter, a, b;
	assassin_counter = 0;
	a = 0;
	b = 0;

	for (unsigned int i=1; i<=m-2; i++) {
		for (unsigned int j=1; j<=n-2; j++) {
			if (Spiel[0][i][j] == geben) {
				for (unsigned int h=i-1; h<=i+1; h++) {
					for (unsigned int k=j-1; k<=j+1; k++) {
						if ((Spiel[0][h][k] != Spiel[0][i][j])&&(h>=1)&&(h<=m-2)&&(k>=1)&&(k<=n-2)) {
							assassin_counter += 1;
						}
					}
				}
				if (assassin_counter == 8) {

					a = 0;
					for (unsigned int h=i-1; h<=i+1; h++) {
						for (unsigned int k=j-1; k<=j+1; k++) {
							if ((Spiel[0][h][k] != Spiel[0][i][j])&&(Spiel[0][h][k] <= number_of_players)&&(Spiel[0][h][k] != 0)) {
								if (b == 0) {
									b = 1;
									if (real == evet) {
										if (Opague_o.characterization >= 1) {
											opague_builder (Field, Opague_o, m, n, geben, AOP, Allocation_o, number_of_players, gamemode_played);
											show_field (number_of_players, level, Sf_permutations, Opague_o.field, Opague_o.field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
										} else {
											show_field (number_of_players, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
										}
									}
								}
								set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, h, k, 0);
								a += 1;
							}
						}
					}

					if ((a != 0)&&(real == evet)) {
						
						Square_color_interpretation (Growth_players, geben, number_of_players, Field[0][i][j]);
						printf("\n");
						printf("	An Assassin \n");
						printf("\n");
						set_terminal_color (cNORMAL);
					}
					a = 0;
					b = 0;
				}
				assassin_counter = 0;
			}
		}
	}
}

void Avalanche_maker (Spielfeld Spiel, Spielfeld Field, Spielfeld Opague_o_field, Special_Fields Allocation_o, unsigned int geben, unsigned int gamemode_played, unsigned int number_of_players, unsigned int m, unsigned int n) {
	for (unsigned int i=1; i<=m-2; i++) {
		for (unsigned int j=1; j<=n-2; j++) {
			if (Spiel[0][i][j] == geben) {
				if ((Spiel[0][i][j-1] != geben)&&(Spiel[0][i][j-1] != 0)&&(Spiel[0][i][j-1] <= number_of_players)&&(((n-2)/2)+1<=j-1)) {
					set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j, Spiel[0][i][j-1]);
					set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j-1, geben);
					Avalanche_maker (Spiel, Field, Opague_o_field, Allocation_o, geben, gamemode_played, number_of_players, m, n);

					// printf("Avalanche_maker ok.1 \n");	//test

				} else if ((Spiel[0][i][j+1] != geben)&&(Spiel[0][i][j+1] != 0)&&(Spiel[0][i][j+1] <= number_of_players)&&(((n-2)/2)+1>=j+1)) {
					set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j, Spiel[0][i][j+1]);
					set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j+1, geben);
					Avalanche_maker (Spiel, Field, Opague_o_field, Allocation_o, geben, gamemode_played, number_of_players, m, n);

					// printf("Avalanche_maker ok.2 \n");	//test

				} else if ((Spiel[0][i-1][j] != geben)&&(Spiel[0][i-1][j] != 0)&&(Spiel[0][i-1][j] <= number_of_players)&&(((m-2)/2)+1<=i-1)) {
					set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j, Spiel[0][i-1][j]);
					set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i-1, j, geben);
					Avalanche_maker (Spiel, Field, Opague_o_field, Allocation_o, geben, gamemode_played, number_of_players, m, n);

					// printf("Avalanche_maker ok.3 \n");	//test

				} else if ((Spiel[0][i+1][j] != geben)&&(Spiel[0][i+1][j] != 0)&&(Spiel[0][i+1][j] <= number_of_players)&&(((m-2)/2)+1>=i+1)) {
					set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j, Spiel[0][i+1][j]);
					set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i+1, j, geben);
					Avalanche_maker (Spiel, Field, Opague_o_field, Allocation_o, geben, gamemode_played, number_of_players, m, n);

					// printf("Avalanche_maker ok.4 \n");	//test
				}
			}
		}
	}
}

void Spreading_maker (Spielfeld Spiel, Spielfeld Field, Spielfeld Opague_o_field, Special_Fields Allocation_o, unsigned int geben, unsigned int gamemode_played, unsigned int number_of_players, unsigned int m, unsigned int n) {
	// printf("Spreading_maker ok.start \n");	//test
	
	for (unsigned int i=1; i<=m-2; i++) {
		if ((Spiel[0][i][1] != 0)&&(Spiel[0][i][1] <= number_of_players)) {
			if (((i-1) >= 1)&&(Spiel[0][i-1][1] == 0)) {
				set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i-1, 1, Spiel[0][i][1]);
				Spreading_maker (Spiel, Field, Opague_o_field, Allocation_o, geben, gamemode_played, number_of_players, m, n);
			}
			if (((i+1) <= (m-2))&&(Spiel[0][i+1][1] == 0)) {
				set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i+1, 1, Spiel[0][i][1]);
				Spreading_maker (Spiel, Field, Opague_o_field, Allocation_o, geben, gamemode_played, number_of_players, m, n);
			}
		}
		if ((Spiel[0][i][(n-2)] != 0)&&(Spiel[0][i][(n-2)] <= number_of_players)) {
			if (((i-1) >= 1)&&(Spiel[0][i-1][(n-2)] == 0)) {
				set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i-1, (n-2), Spiel[0][i][(n-2)]);
				Spreading_maker (Spiel, Field, Opague_o_field, Allocation_o, geben, gamemode_played, number_of_players, m, n);
			}
			if (((i+1) <= (m-2))&&(Spiel[0][i+1][(n-2)] == 0)) {
				set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i+1, (n-2), Spiel[0][i][(n-2)]);
				Spreading_maker (Spiel, Field, Opague_o_field, Allocation_o, geben, gamemode_played, number_of_players, m, n);
			}
		}
	}
	for (unsigned int j=1; j<=n-2; j++) {
		if ((Spiel[0][1][j] != 0)&&(Spiel[0][1][j] <= number_of_players)) {
			if (((j-1) >= 1)&&(Spiel[0][1][j-1] == 0)) {
				set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, 1, j-1, Spiel[0][1][j]);
				Spreading_maker (Spiel, Field, Opague_o_field, Allocation_o, geben, gamemode_played, number_of_players, m, n);
			}
			if (((j+1) <= (n-2))&&(Spiel[0][1][j+1] == 0)) {
				set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, 1, j+1, Spiel[0][1][j]);
				Spreading_maker (Spiel, Field, Opague_o_field, Allocation_o, geben, gamemode_played, number_of_players, m, n);
			}
		}
		if ((Spiel[0][(m-2)][j] != 0)&&(Spiel[0][(m-2)][j] <= number_of_players)) {
			if (((j-1) >= 1)&&(Spiel[0][(m-2)][j-1] == 0)) {
				set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, (m-2), j-1, Spiel[0][(m-2)][j]);
				Spreading_maker (Spiel, Field, Opague_o_field, Allocation_o, geben, gamemode_played, number_of_players, m, n);
			}
			if (((j+1) <= (n-2))&&(Spiel[0][(m-2)][j+1] == 0)) {
				set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, (m-2), j+1, Spiel[0][(m-2)][j]);
				Spreading_maker (Spiel, Field, Opague_o_field, Allocation_o, geben, gamemode_played, number_of_players, m, n);
			}
		}
	}
	// printf("Spreading_maker ok.end \n");	//test
}

void Permutations_permutate_maker (Spielfeld Collector_of_permutation_number_areas, Spielfeld Field, unsigned int number_of_players, unsigned int permutation_number, unsigned int** sigmas_for_permutation_number, unsigned int amount_of_permutation_number, unsigned int geben, Spielfeld Opague_o_field, unsigned int gamemode_played, Special_Fields Allocation_o) {
	unsigned int temp_permutations, hangi_sigma, unutma_i, unutma_j, unutma_r, unutma_s;
	temp_permutations = 0;
	hangi_sigma = 0;
	unutma_i = 0;	//changes
	unutma_j = 0;	//changes
	unutma_r = 0;
	unutma_s = 0;	//changes

	// printf("Permutations_permutate_maker ok.1\n");	//test

	if (permutation_number > 1) {

		for (unsigned int p=0; p<amount_of_permutation_number; p++) {	//going through Collector_of_permutation_number_areas

			// printf("Permutations_permutate_maker for(p) ok.2\n");	//test

			for (unsigned int q=1; q<=permutation_number-2; q++) {	//getting sigma(p)

				// printf("Permutations_permutate_maker for(p) ok.2.1\n");	//test

				hangi_sigma += Fakultaet(q)*Zufall(0, q);
			}

			// printf("Permutations_permutate_maker for(p) ok.3\n");	//test

			for (unsigned int r=0; r<permutation_number; r++) {
				if (Field[0][Collector_of_permutation_number_areas[p][r][Horizontal]][Collector_of_permutation_number_areas[p][r][Vertikal]] <= number_of_players) {
					unutma_r = r;	//find the first square which isn't an object
					break;
				}
			}

			// printf("Permutations_permutate_maker for(p) ok.4\n");	//test

			unutma_i = Collector_of_permutation_number_areas[p][unutma_r][Horizontal];

			// printf("Permutations_permutate_maker for(p) ok.4.1\n");	//test

			unutma_j = Collector_of_permutation_number_areas[p][unutma_r][Vertikal];

			// printf("Permutations_permutate_maker for(p) ok.4.2\n");	//test

			temp_permutations = Field[0][unutma_i][unutma_j];

			// printf("Permutations_permutate_maker for(p) ok.5\n");	//test

			for (unsigned int s=0; s<permutation_number; s++) {
				if (sigmas_for_permutation_number[hangi_sigma][s] == unutma_r) {
					unutma_s = s;
					break;
				}
			}

			// printf("Permutations_permutate_maker for(p) ok.6\n");	//test

			unutma_r = 1;	//übernimmt neue Aufgabe

			for (unsigned int q=0; q<permutation_number; q++) {

				if (Field[0][Collector_of_permutation_number_areas[p][sigmas_for_permutation_number[hangi_sigma][(unutma_s+permutation_number-unutma_r)%permutation_number]][Horizontal]][Collector_of_permutation_number_areas[p][sigmas_for_permutation_number[hangi_sigma][(unutma_s+permutation_number-unutma_r)%permutation_number]][Vertikal]] <= number_of_players) {	//Vorheriger in sigma <= number_of_players
					if (q == permutation_number-1) {
						set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, Collector_of_permutation_number_areas[p][sigmas_for_permutation_number[hangi_sigma][unutma_s]][Horizontal], Collector_of_permutation_number_areas[p][sigmas_for_permutation_number[hangi_sigma][unutma_s]][Vertikal], temp_permutations);
					} else {
						set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, Collector_of_permutation_number_areas[p][sigmas_for_permutation_number[hangi_sigma][unutma_s]][Horizontal], Collector_of_permutation_number_areas[p][sigmas_for_permutation_number[hangi_sigma][unutma_s]][Vertikal], Field[0][Collector_of_permutation_number_areas[p][sigmas_for_permutation_number[hangi_sigma][(unutma_s+permutation_number-unutma_r)%permutation_number]][Horizontal]][Collector_of_permutation_number_areas[p][sigmas_for_permutation_number[hangi_sigma][(unutma_s+permutation_number-unutma_r)%permutation_number]][Vertikal]]);
						unutma_s = (unutma_s+permutation_number-unutma_r)%permutation_number;
						unutma_r = 1;
					}
				} else {
					unutma_r += 1;
				}
			}

			unutma_r = 0;	//übernimmt neue (ursprüngliche/alte) Aufgabe mit Standartinitialisierung

			// printf("Permutations_permutate_maker for(p) ok.7\n");	//test

			hangi_sigma = 0;
		}
	}

	// printf("Permutations_permutate_maker ok.8\n");	//test
}

void translate_permutations_amounts_to_permutations_areas (Spielfeld Sf_permutations, unsigned int m, unsigned int n, Collector Collector_of_permutation) {

	unsigned int unutma_i, unutma_j, amount_of_permutation_number_c_in_real, amount_of_permutation_number_b_in_real;

	unutma_i = 1;
	unutma_j = 0;
	nereye_gitmeliyiz = to_the_right;

	amount_of_permutation_number_c_in_real = Collector_of_permutation.amount_of_permutation_number_c;
	amount_of_permutation_number_b_in_real = Collector_of_permutation.amount_of_permutation_number_b;

	// printf("translate_permutations_amounts_to_permutations_areas ok.1\n");	//test

	while ((Collector_of_permutation.amount_of_permutation_number_c > 0)||(Collector_of_permutation.amount_of_permutation_number_b > 0)) {		//the reduction of the amounts only happens intern of this function, because they are copies

		// printf("translate_permutations_amounts_to_permutations_areas while ok.2\n");	//test

		if (Collector_of_permutation.amount_of_permutation_number_c >= Collector_of_permutation.amount_of_permutation_number_b) {

			// printf("translate_permutations_amounts_to_permutations_areas while ok.2c\n");	//test

			for (unsigned int p=1; p<=Collector_of_permutation.permutation_number_c; p++) {

				// printf("translate_permutations_amounts_to_permutations_areas while ok.3c\n");	//test

				if (nereye_gitmeliyiz == to_the_right) {	//if it gets needed, work with continue
					if ((Sf_permutations[0][unutma_i][unutma_j+1] == 0)&&(unutma_j+1 <= n-2)) {
						unutma_j += 1;	//unutma_ already changed, dont forget!
						Collector_of_permutation.areas_c[(amount_of_permutation_number_c_in_real - Collector_of_permutation.amount_of_permutation_number_c)][p-1][Horizontal] = unutma_i;
						Collector_of_permutation.areas_c[(amount_of_permutation_number_c_in_real - Collector_of_permutation.amount_of_permutation_number_c)][p-1][Vertikal] = unutma_j;

						Sf_permutations[0][unutma_i][unutma_j] = ((amount_of_permutation_number_c_in_real - Collector_of_permutation.amount_of_permutation_number_c)+(Collector_of_permutation.permutation_number_b+Collector_of_permutation.permutation_number_c))%100 +1;
					} else {
						nereye_gitmeliyiz = to_the_bottom;
						p -= 1;
					}
				} else if (nereye_gitmeliyiz == to_the_bottom) {
					if ((Sf_permutations[0][unutma_i+1][unutma_j] == 0)&&(unutma_i+1 <= m-2)) {
						unutma_i += 1;	//unutma_ already changed, dont forget!

						Collector_of_permutation.areas_c[(amount_of_permutation_number_c_in_real - Collector_of_permutation.amount_of_permutation_number_c)][p-1][Horizontal] = unutma_i;
						Collector_of_permutation.areas_c[(amount_of_permutation_number_c_in_real - Collector_of_permutation.amount_of_permutation_number_c)][p-1][Vertikal] = unutma_j;

						Sf_permutations[0][unutma_i][unutma_j] = ((amount_of_permutation_number_c_in_real - Collector_of_permutation.amount_of_permutation_number_c)+(Collector_of_permutation.permutation_number_b+Collector_of_permutation.permutation_number_c))%100 +1;
					} else {
						nereye_gitmeliyiz = to_the_left;
						p -= 1;
					}
				} else if (nereye_gitmeliyiz == to_the_left) {
					if ((Sf_permutations[0][unutma_i][unutma_j-1] == 0)&&(unutma_j-1 >= 1)) {
						unutma_j -= 1;	//unutma_ already changed, dont forget!

						Collector_of_permutation.areas_c[(amount_of_permutation_number_c_in_real - Collector_of_permutation.amount_of_permutation_number_c)][p-1][Horizontal] = unutma_i;
						Collector_of_permutation.areas_c[(amount_of_permutation_number_c_in_real - Collector_of_permutation.amount_of_permutation_number_c)][p-1][Vertikal] = unutma_j;

						Sf_permutations[0][unutma_i][unutma_j] = ((amount_of_permutation_number_c_in_real - Collector_of_permutation.amount_of_permutation_number_c)+(Collector_of_permutation.permutation_number_b+Collector_of_permutation.permutation_number_c))%100 +1;
					} else {
						nereye_gitmeliyiz = to_the_top;
						p -= 1;
					}
				} else if (nereye_gitmeliyiz == to_the_top) {
					if ((Sf_permutations[0][unutma_i-1][unutma_j] == 0)&&(unutma_i-1 >= 1)) {
						unutma_i -= 1;	//unutma_ already changed, dont forget!

						Collector_of_permutation.areas_c[(amount_of_permutation_number_c_in_real - Collector_of_permutation.amount_of_permutation_number_c)][p-1][Horizontal] = unutma_i;
						Collector_of_permutation.areas_c[(amount_of_permutation_number_c_in_real - Collector_of_permutation.amount_of_permutation_number_c)][p-1][Vertikal] = unutma_j;

						Sf_permutations[0][unutma_i][unutma_j] = ((amount_of_permutation_number_c_in_real - Collector_of_permutation.amount_of_permutation_number_c)+(Collector_of_permutation.permutation_number_b+Collector_of_permutation.permutation_number_c))%100 +1;
					} else {
						nereye_gitmeliyiz = to_the_right;
						p -= 1;
					}
				}
			}
			Collector_of_permutation.amount_of_permutation_number_c -= 1;

		} else if (Collector_of_permutation.amount_of_permutation_number_b >= Collector_of_permutation.amount_of_permutation_number_c) {

			// printf("translate_permutations_amounts_to_permutations_areas while ok.2b\n");	//test

			for (unsigned int p=1; p<=Collector_of_permutation.permutation_number_b; p++) {

				// printf("translate_permutations_amounts_to_permutations_areas while ok.3b\n");	//test

				if (nereye_gitmeliyiz == to_the_right) {	//if it gets needed, work with continue

					// printf("translate_permutations_amounts_to_permutations_areas while ok.4b\n");

					if ((Sf_permutations[0][unutma_i][unutma_j+1] == 0)&&(unutma_j+1 <= n-2)) {
						unutma_j += 1;	//unutma_ already changed, dont forget!

						// printf("translate_permutations_amounts_to_permutations_areas while ok.5b\n");	//test

						Collector_of_permutation.areas_b[(amount_of_permutation_number_b_in_real - Collector_of_permutation.amount_of_permutation_number_b)][p-1][Horizontal] = unutma_i;

						// printf("translate_permutations_amounts_to_permutations_areas while ok.5.1b\n");	//test

						Collector_of_permutation.areas_b[(amount_of_permutation_number_b_in_real - Collector_of_permutation.amount_of_permutation_number_b)][p-1][Vertikal] = unutma_j;

						// printf("translate_permutations_amounts_to_permutations_areas while ok.6b\n");	//test

						Sf_permutations[0][unutma_i][unutma_j] = (amount_of_permutation_number_b_in_real - Collector_of_permutation.amount_of_permutation_number_b)%100 +1;
					} else {
						nereye_gitmeliyiz = to_the_bottom;
						p -= 1;
					}
				} else if (nereye_gitmeliyiz == to_the_bottom) {
					if ((Sf_permutations[0][unutma_i+1][unutma_j] == 0)&&(unutma_i+1 <= m-2)) {
						unutma_i += 1;	//unutma_ already changed, dont forget!

						Collector_of_permutation.areas_b[(amount_of_permutation_number_b_in_real - Collector_of_permutation.amount_of_permutation_number_b)][p-1][Horizontal] = unutma_i;
						Collector_of_permutation.areas_b[(amount_of_permutation_number_b_in_real - Collector_of_permutation.amount_of_permutation_number_b)][p-1][Vertikal] = unutma_j;

						Sf_permutations[0][unutma_i][unutma_j] = (amount_of_permutation_number_b_in_real - Collector_of_permutation.amount_of_permutation_number_b)%100 +1;
					} else {
						nereye_gitmeliyiz = to_the_left;
						p -= 1;
					}
				} else if (nereye_gitmeliyiz == to_the_left) {
					if ((Sf_permutations[0][unutma_i][unutma_j-1] == 0)&&(unutma_j-1 >= 1)) {
						unutma_j -= 1;	//unutma_ already changed, dont forget!

						Collector_of_permutation.areas_b[(amount_of_permutation_number_b_in_real - Collector_of_permutation.amount_of_permutation_number_b)][p-1][Horizontal] = unutma_i;
						Collector_of_permutation.areas_b[(amount_of_permutation_number_b_in_real - Collector_of_permutation.amount_of_permutation_number_b)][p-1][Vertikal] = unutma_j;

						Sf_permutations[0][unutma_i][unutma_j] = (amount_of_permutation_number_b_in_real - Collector_of_permutation.amount_of_permutation_number_b)%100 +1;
					} else {
						nereye_gitmeliyiz = to_the_top;
						p -= 1;
					}
				} else if (nereye_gitmeliyiz == to_the_top) {
					if ((Sf_permutations[0][unutma_i-1][unutma_j] == 0)&&(unutma_i-1 >= 1)) {
						unutma_i -= 1;	//unutma_ already changed, dont forget!

						Collector_of_permutation.areas_b[(amount_of_permutation_number_b_in_real - Collector_of_permutation.amount_of_permutation_number_b)][p-1][Horizontal] = unutma_i;
						Collector_of_permutation.areas_b[(amount_of_permutation_number_b_in_real - Collector_of_permutation.amount_of_permutation_number_b)][p-1][Vertikal] = unutma_j;

						Sf_permutations[0][unutma_i][unutma_j] = (amount_of_permutation_number_b_in_real - Collector_of_permutation.amount_of_permutation_number_b)%100 +1;
					} else {
						nereye_gitmeliyiz = to_the_right;
						p -= 1;
					}
				}
			}
			Collector_of_permutation.amount_of_permutation_number_b -= 1;
		}
	}

	// printf("translate_permutations_amounts_to_permutations_areas while ok.3\n");	//test
}

unsigned int random_number (Num_num num, unsigned int rmv_use_number, unsigned int g, unsigned int* rmv_var_, unsigned int* number_){
	unsigned int temp_number, new_number, c, mult, inkre, modu, zusatz;

	mult = 7;
	inkre = 5;
	modu = 6;
	zusatz = ((g + rmv_var_[1] + rmv_var_[2] + number_[3] + number_[4] )%60)%6;

	temp_number = (num.bir % 2)+(num.iki % 3)+2*(num.uec % 3);

	if (temp_number <= 1){
		c = 1;
	} else if (temp_number >= 6){
		c = 6;
	} else {
		c = temp_number;
	}

	new_number = (mult*rmv_use_number + inkre + c + zusatz + Zufall(1, 6))%modu;

	if (new_number == 0){
		new_number = 6;
	}

	return new_number;
}

void Square_color_interpretation (Growth_Player* Growth_players, unsigned int geben, unsigned int number_of_players, unsigned int square_number) {
	
	if (Growth_players[0].color == 1) {
		if (square_number != 0) {
			if (square_number <= number_of_players) {
				for (unsigned int p=1; p<=number_of_players; p++) {
					if (Growth_players[p].id == square_number) {
						set_terminal_color (Growth_players[p].color);
					}
				}
			} else {
				if (square_number == 11) {
					set_terminal_color (Growth_players[1].color);
				} else if (square_number == oeluem) {
					set_terminal_color (Growth_players[geben].color);
				} else if (square_number == dogum) {
					set_terminal_color (Growth_players[geben].color);
				} else if (square_number == bir_sey) {
					set_terminal_color (cNORMAL);
				} else if (square_number == Quaffel) {
					set_terminal_color (cRED);
				} else if (square_number == Klatscher) {
					set_terminal_color (cGRAY);
				} else if (square_number == Schnatz) {
					set_terminal_color (cWHITE);
				} else if ((square_number == Treiber_1)||(square_number == Jaeger_1)||(square_number == Sucher_1)||(square_number == Hueter_1)||(square_number == Torring_1)) {
					if (Growth_players[1].color == cLIGHT_MAGENTA) {
						set_terminal_color (cLIGHT_RED);
					} else if (Growth_players[1].color == cLIGHT_CYAN) {
						set_terminal_color (cLIGHT_BLUE);
					} else if (Growth_players[1].color == cYELLOW) {
						set_terminal_color (cBROWN);
					} else if (Growth_players[1].color == cLIGHT_GREEN) {
						set_terminal_color (cGREEN);
					}
				} else if ((square_number == Treiber_2)||(square_number == Jaeger_2)||(square_number == Sucher_2)||(square_number == Hueter_2)||(square_number == Torring_2)) {
					if (Growth_players[2].color == cLIGHT_MAGENTA) {
						set_terminal_color (cLIGHT_RED);
					} else if (Growth_players[2].color == cLIGHT_CYAN) {
						set_terminal_color (cLIGHT_BLUE);
					} else if (Growth_players[2].color == cYELLOW) {
						set_terminal_color (cBROWN);
					} else if (Growth_players[2].color == cLIGHT_GREEN) {
						set_terminal_color (cGREEN);
					}
				} else {
					set_terminal_color (cBROWN);
				}
			}
		}
	}
}

void opague_builder (Spielfeld Field, Special_Fields Opague_o, unsigned int m, unsigned int n, unsigned int geben, unsigned int AOP, Special_Fields Allocation_o, unsigned int number_of_players, unsigned int gamemode_played) {
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
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, temp_opague, 0, i, j, geben);
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
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, temp_opague, 0, i+1, j, Field[0][i+1][j]);
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
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, temp_opague, 0, i-1, j, Field[0][i-1][j]);
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
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, temp_opague, 0, i, j-1, Field[0][i][j-1]);
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
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, temp_opague, 0, i, j+1, Field[0][i][j+1]);
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
								set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, temp_opague, 0, i, j, value);
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
									set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, temp_opague, 0, h, k, Field[0][h][k]);
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
								set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, temp_opague, 0, i, j, value);
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
				set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, temp_opague, 0, i, j, 11);
			}
		}
	}

	for (unsigned int i=1; i<m-1; i+=1){
		for (unsigned int j=1; j<n-1; j+=1){
			set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Opague_o.field, 0, i, j, temp_opague[0][i][j]);
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
	} else {
		value = 0;
	}
	
	
	return value;
}

void ges0_reset_and_counter (unsigned int* ges, unsigned int number_of_players) {
	ges[0] = 0;
	for (unsigned int p=1; p<=number_of_players; p+=1) {
		ges[0] += ges[p];
	}
}
