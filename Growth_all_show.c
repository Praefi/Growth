
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#ifdef _WIN32
#include <windows.h>
#endif


#include "Growth_all_Def.h"
#include "Growth_all_visual.h"
#include "Growth_all_show.h"

// #define VERBOSE
// #define Contact_mistake_search
// #define Quidditch_mistake_search

void show_field (unsigned int number_of_players, unsigned int invisible, unsigned int* level, Spielfeld Sf_permutations, Spielfeld Opague_o_field, Spielfeld Spiel, unsigned int m, unsigned int n, unsigned int gamemode_played, unsigned int* information_code, unsigned int geben, Growth_Player* Growth_players, unsigned int auswerter, Special_Fields Allocation_o){	//checklist
	unsigned int allocation_choice;
	allocation_choice = 0;

	#ifdef VERBOSE
	printf("show_field ok.1 \n"); //test
	#endif
	
	if (level[0] <= 2) {	//so it is necessary
		//number_of_players increased go on (done?)
		if (Spiel == Opague_o_field) {
			allocation_choice = 2;
		}

		printf("\n");

		printf("      ");
		for (unsigned int p=1; p<=n-2; p+=1){		//Nummerierung
			if (p%7 == 0) {
				set_terminal_color (cBROWN);
			}
			if (p<10){
				printf("%u  ", p);
			} else {
				printf("%u ", p);
			}
			set_terminal_color (cNORMAL);
		}
		printf("   ");	//üc bosluk

		if (Allocation_o.characterization != 0) {
			printf("		");	//two tabs
			printf("    ");	//dört bosluk
			for (unsigned int p=1; p<=n-2; p+=1){
				if (p<10){
					printf("%u  ", p);
				} else {
					printf("%u ", p);
				}
			}
			printf("   ");	//üc bosluk
		}

		if (Sf_permutations[0][1][1] != 0) {
			printf("		");	//two tabs
			printf("    ");	//dört bosluk
			for (unsigned int p=1; p<=n-2; p+=1){
				if (p<10){
					printf("%u  ", p);
				} else {
					printf("%u ", p);
				}
			}
		}

		printf("\n");

		for (unsigned int i=1; i<m-1; i+=1){

			printf("     +");
			for (unsigned int t=1; t<=n-2; t+=1){		//Zwischenzeilen
				printf("--+");
			}
			printf("   ");	//üc bosluk

			if (Allocation_o.characterization != 0) {
				printf("	");	//two tabs
				printf("     +");
				for (unsigned int t=1; t<=n-2; t+=1){
					printf("--+");
				}
				printf("   ");	//üc bosluk
			}

			if (Sf_permutations[0][1][1] != 0) {
				printf("	");	//two tabs
				printf("     +");
				for (unsigned int t=1; t<=n-2; t+=1){
					printf("--+");
				}
			}

			printf("\n");

			for (unsigned int v=1; v<=2; v+=1){		//Doppel-Ausführung, ab 10 wird korrigiert, bis 99 gültig

				if (i<10){
					printf("   %u |", i);
				} else {
					printf("  %u |", i);
				}
				for (unsigned int j=1; j<n-1; j+=1){	//Haupzeilen
					
					Square_color_interpretation (Growth_players, geben, number_of_players, Spiel[auswerter][i][j]);
					
					if ((Spiel[auswerter][i][j] == 0)||((invisible == 1)&&(Spiel[auswerter][i][j] != geben))){
						printf("  ");
					} else if (Spiel[auswerter][i][j] == dogum){
						printf("NN");
					} else if (Spiel[auswerter][i][j] == oeluem){
						printf("D ");
					} else if (Spiel[auswerter][i][j] == bir_sey){	//hint
						printf("::");
					} else if (Spiel[auswerter][i][j] >= 10000){
						printf("??");
					}
					
					if ((invisible == 0)||(Spiel[auswerter][i][j] == geben)) {
						if (gamemode_played == Hunt) {
							if (Spiel[auswerter][i][j] == 1) {
								if ((geben == 1)||((information_code[3] == 1)&&((Spiel[auswerter][i+1][j] == geben)||(Spiel[auswerter][i-1][j] == geben)||(Spiel[auswerter][i][j+1] == geben)||(Spiel[auswerter][i][j-1] == geben)))||((information_code[1] == 1)&&(information_code[2] == 1))){
									printf("##");
								} else {
									printf("  ");
								}
							} else if (Spiel[auswerter][i][j] == 2){
								printf("AA");
							} else if (Spiel[auswerter][i][j] == 3){
								printf("BB");
							} else if (Spiel[auswerter][i][j] == 4){
								printf("CC");
							} else if (Spiel[auswerter][i][j] == 5){
								printf("DD");
							} else if (Spiel[auswerter][i][j] == 6){
								printf("EE");
							} else if (Spiel[auswerter][i][j] == 7){
								printf("GG");
							} else if (Spiel[auswerter][i][j] == 8){
								printf("HH");
							} else if (Spiel[auswerter][i][j] == 9){
								printf("II");
							} else if (Spiel[auswerter][i][j] == 11){
								if ((geben == 1)||(((information_code[2] == 2)||(information_code[2] == 1))&&(information_code[1] == 1))){
									printf("~~");
								} else {
									printf("  ");
								}
							}
						} else if (gamemode_played == Arena) {
							if (Spiel[auswerter][i][j] == geben) {
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
							} else if ((information_code[1] != 0)&&(information_code[1] != 100)&&(Spiel[auswerter][i][j] == information_code[1])) {
								printf("II");
							} else if ((information_code[2] != 0)&&(information_code[2] != 100)&&(Spiel[auswerter][i][j] == information_code[2])) {
								printf("PP");
							} else if ((information_code[3] != 0)&&(information_code[3] != 100)&&(Spiel[auswerter][i][j] == information_code[3])) {
								printf("HH");
							} else if ((Spiel[auswerter][1][0] != 0)&&(Spiel[auswerter][1][0] != 1000)&&(Spiel[auswerter][i][j] == Spiel[auswerter][1][0]/10)) {
								printf("UU");
							} else if ((Spiel[auswerter][0][0] != 0)&&(Spiel[auswerter][0][0] != 1000)&&(Spiel[auswerter][i][j] == Spiel[auswerter][0][0]/10)) {
								printf("LL");
							} else if ((Spiel[auswerter][0][1] != 0)&&(Spiel[auswerter][0][1] != 1000)&&(Spiel[auswerter][i][j] == Spiel[auswerter][0][1]/10)) {
								printf("AA");
							} else if ((Spiel[auswerter][0][n-1] != 0)&&(Spiel[auswerter][0][n-1] != 1000)&&(Spiel[auswerter][i][j] == Spiel[auswerter][0][n-1]/10)) {
								printf("CC");
							} else if ((Spiel[auswerter][m-1][n-1] != 0)&&(Spiel[auswerter][m-1][n-1] != 1000)&&(Spiel[auswerter][i][j] == Spiel[auswerter][m-1][n-1]/10)) {
								printf("SS");
							} else if ((Spiel[auswerter][m-1][0] != 0)&&(Spiel[auswerter][m-1][0] != 1000)&&(Spiel[auswerter][i][j] == Spiel[auswerter][m-1][0]/10)) {
								printf("EE");
							}
						} else {
							for (unsigned int p=1; p<=number_of_players; p++) {	//information_code[0] == number_of_players, changed
								if (Spiel[auswerter][i][j] == p) {
									printf("%u%u", p, p);
									break;
								}
							}
							if (gamemode_played == Collect) {
								if (Spiel[auswerter][i][j] == To_collect) {
									printf("##");
								}
							} else if (gamemode_played == Fall) {
								if (Spiel[auswerter][i][j] == Fall_ball) {
									printf("##");
								}
							} else if (gamemode_played == Race) {
								if (Spiel[auswerter][i][j] == Wall) {
									printf("##");
								} else if (Spiel[auswerter][i][j] == Wall_at_the_end) {
									printf("((");
								}
							} else if (gamemode_played == Rain) {
								if (Spiel[auswerter][i][j] == Raindrop) {
									printf("##");
								}
							} else if (gamemode_played == Dynamic) {
								if (Spiel[auswerter][i][j] == Dynamic_ball) {
									printf("##");
								}
							} else if (gamemode_played == Survive) {
								if (Spiel[auswerter][i][j] == Traps) {	//Trap
									printf("TT");
								} else if (Spiel[auswerter][i][j] == Bomb_4) {	//Bomb
									printf("B4");
								} else if (Spiel[auswerter][i][j] == Bomb_3) {	//Bomb
									printf("B3");
								} else if (Spiel[auswerter][i][j] == Bomb_2) {	//Bomb
									printf("B2");
								} else if (Spiel[auswerter][i][j] == Bomb_1) {	//Bomb
									printf("B1");
								} else if (Spiel[auswerter][i][j] == Waves) {	//Wave
									printf("WW");
								}
							} else if (gamemode_played == Quidditch) {
								if (Spiel[auswerter][i][j] == Quaffel) {	//Quaffel
									printf("Qu");
								} else if (Spiel[auswerter][i][j] == Klatscher) {	//Klatscher
									printf("Kl");
								} else if (Spiel[auswerter][i][j] == Schnatz) {		//Schnatz
									printf("Sz");
								} else if (Spiel[auswerter][i][j] == Jaeger_1) {	//Jaeger_1
									printf("Ja");
								} else if (Spiel[auswerter][i][j] == Jaeger_2) {	//Jaeger_2
									printf("Ja");
								} else if (Spiel[auswerter][i][j] == Hueter_1) {	//Hueter_1
									printf("Hu");
								} else if (Spiel[auswerter][i][j] == Hueter_2) {	//Hueter_2
									printf("Hu");
								} else if (Spiel[auswerter][i][j] == Treiber_1) {	//Treiber_1
									printf("Tr");
								} else if (Spiel[auswerter][i][j] == Treiber_2) {	//Treiber_2
									printf("Tr");
								} else if (Spiel[auswerter][i][j] == Sucher_1) {	//Sucher_1
									printf("Su");
								} else if (Spiel[auswerter][i][j] == Sucher_2) {	//Sucher_2
									printf("Su");
								} else if ((Spiel[auswerter][i][j] == Torring_1)||(Spiel[auswerter][i][j] == Torring_2)) {	//Torringe
									printf("()");
								}
							}
						}
					}
					
					set_terminal_color (cNORMAL);
					printf("|");
				}

				if (i<10){
					printf(" %u ", i);
				} else {
					printf(" %u", i);
				}

				if ((Allocation_o.characterization == 0)&&(Sf_permutations[0][1][1] == 0)) {	//only if no field is following
					printf("\n");
				}
				if (Allocation_o.characterization != 0) {	//a second field
					printf("	");	//one tab(s)
					
					if (i<10){
						printf("    %u |", i);
					} else {
						printf("   %u |", i);
					}
					
					for (unsigned int j=1; j<n-1; j+=1){
						
						Square_color_interpretation (Growth_players, geben, number_of_players, Spiel[auswerter][i][j]);
						
						if ((Allocation_o.field[allocation_choice][i][j] < 10)&&(Allocation_o.field[allocation_choice][i][j] != 0)) {
							printf("0%u", Allocation_o.field[allocation_choice][i][j]);
						} else if ((Allocation_o.field[allocation_choice][i][j] >= 10)&&(Allocation_o.field[allocation_choice][i][j] != 0)) {	//last one can be left
							printf("%u", Allocation_o.field[allocation_choice][i][j]);
						} else {	//no allocation possible for objects
							printf("  ");
						}

						set_terminal_color (cNORMAL);
						printf("|");
					}

					if (i<10){
						printf(" %u ", i);
					} else {
						printf(" %u", i);
					}

					if (Sf_permutations[0][1][1] == 0) {	//only if no field is following
						printf("\n");
					}

				}
				if (Sf_permutations[0][1][1] != 0) {	//a third field
					printf("	");	//one tab(s)

					if (i<10){
						printf("    %u |", i);
					} else {
						printf("   %u |", i);
					}
					
					for (unsigned int j=1; j<n-1; j+=1){
						
						set_terminal_color (Sf_permutations[0][i][j]%15 +1);
					
						if ((Sf_permutations[0][i][j] < 10)&&(Sf_permutations[0][i][j] != 0)) {
							printf("0%u", Sf_permutations[0][i][j]);
						} else if ((Sf_permutations[0][i][j] >= 10)&&(Sf_permutations[0][i][j] != 0)) {	//last one can be left
							printf("%u", Sf_permutations[0][i][j]);
						} else {
							printf("  ");
						}

						set_terminal_color (cNORMAL);
						
						printf("|");

					}

					if (i<10){
						printf(" %u ", i);
					} else {
						printf(" %u", i);
					}

				//if () {	//only if no field is following
					printf("\n");
				//}

				}
			}
		}

		printf("     +");
		for (unsigned int t=1; t<=n-2; t+=1){		//Endzeile
			printf("--+");
		}
		printf("   ");	//üc bosluk

		if (Allocation_o.characterization != 0) {
			printf("	");	//one tab(s)
			printf("     +");
			for (unsigned int t=1; t<=n-2; t+=1){
				printf("--+");
			}
			printf("   ");	//üc bosluk
		}

		if (Sf_permutations[0][1][1] != 0) {
			printf("	");	//one tab(s)
			printf("     +");
			for (unsigned int t=1; t<=n-2; t+=1){
				printf("--+");
			}
		}

		printf("\n");
		printf("      ");
		for (unsigned int q=1; q<=n-2; q+=1){		//Nummerierung
			if (q<10){
				printf("%u  ", q);
			} else {
				printf("%u ", q);
			}
		}
		printf("   ");	//üc bosluk

		if (Allocation_o.characterization != 0) {
			printf("		");	//two tab(s)
			printf("    ");	//dört bosluk
			for (unsigned int q=1; q<=n-2; q+=1){		//Nummerierung
				if (q<10){
				printf("%u  ", q);
				} else {
				printf("%u ", q);
				}
			}
			printf("   ");	//üc bosluk
		}

		if (Sf_permutations[0][1][1] != 0) {
			printf("		");	//two tab(s)
			printf("    ");	//dört bosluk
			for (unsigned int q=1; q<=n-2; q+=1){		//Nummerierung
				if (q<10){
					printf("%u  ", q);
				} else {
					printf("%u ", q);
				}
			}
		}

		printf("\n");
		printf("\n");

		#ifdef VERBOSE
		printf("\n");	//test
		printf("	information_code: [0]=%u,	[1]=%u,	[2]=%u,	[3]=%u,	\n", information_code[0], information_code[1], information_code[2], information_code[3]);
		printf("\n");
		#endif
	}
}


void show_whose_turn (unsigned int gamemode_played, unsigned int geben, unsigned int* ability, Growth_Player* Growth_players, unsigned int* level, unsigned int number_of_players) {
	
	Square_color_interpretation (Growth_players, geben, number_of_players, geben);
	
	if (gamemode_played == Hunt) {
		if (geben == 1) {
			printf("	Am Zug: Spieler %u (##)	", geben);
		} else if (geben == 2) {
			printf("	Am Zug: Spieler %u (AA)	", geben);
		} else if (geben == 3) {
			printf("	Am Zug: Spieler %u (BB)	", geben);
		} else if (geben == 4) {
			printf("	Am Zug: Spieler %u (CC)	", geben);
		} else if (geben == 5) {
			printf("	Am Zug: Spieler %u (DD)	", geben);
		} else if (geben == 6) {
			printf("	Am Zug: Spieler %u (EE)	", geben);
		} else if (geben == 7) {
			printf("	Am Zug: Spieler %u (FF)	", geben);
		} else if (geben == 8) {
			printf("	Am Zug: Spieler %u (GG)	", geben);
		} else if (geben == 9) {
			printf("	Am Zug: Spieler %u (HH)	", geben);
		}
	} else if (gamemode_played == Arena) {
		if (ability[1] == geben) {
			printf("	Am Zug: Spieler %u (UU)	", geben);
		} else if (ability[2] == geben) {
			printf("	Am Zug: Spieler %u (LL)	", geben);
		} else if (ability[3] == geben) {
			printf("	Am Zug: Spieler %u (AA)	", geben);
		} else if (ability[4] == geben) {
			printf("	Am Zug: Spieler %u (CC)	", geben);
		} else if (ability[5] == geben) {
			printf("	Am Zug: Spieler %u (II)	", geben);
		} else if (ability[6] == geben) {
			printf("	Am Zug: Spieler %u (SS)	", geben);
		} else if (ability[7] == geben) {
			printf("	Am Zug: Spieler %u (PP)	", geben);
		} else if (ability[8] == geben) {
			printf("	Am Zug: Spieler %u (HH)	", geben);
		} else if (ability[9] == geben) {
			printf("	Am Zug: Spieler %u (EE)	", geben);
		}
	} else {
		printf("	Am Zug: Spieler %u (%u%u)	", geben, geben, geben);
	}

	if (level[geben] == human) {
		printf("\n");
	} else {
		if (level[geben] == Delilag) {
			printf("Delilag");
		} else if (level[geben] == Hera) {
			printf("Hera");
		} else if (level[geben] == Yasmin) {
			printf("Yasmin");
		} else if (level[geben] == Coco) {
			printf("Coco");
		} else if (level[geben] == Natalie) {
			printf("Natalie");
		} else if (level[geben] == Liz) {
			printf("Liz");
		} else if (level[geben] == Jill) {
			printf("Jill");
		} else if (level[geben] == Uma) {
			printf("Uma");
		}
		printf("\n");
	}
	
	set_terminal_color (cNORMAL);
	printf("\n");

}

void show_statistics (unsigned int number_of_players, unsigned int gamemode_played, Spielfeld numbers_of_, unsigned int* rmv_Points, unsigned int exclude_counter, unsigned int* rmv_ulcer_lifes, unsigned int* ges, unsigned int* pere, unsigned int* ability, unsigned int time_matters_ttt, Quidditch_setup* Qs) {	//checklist

	printf("\n");
	for (unsigned int p=1; p<=number_of_players; p+=1) {
		printf("	Numbers of player %u: \n", p);
		for (unsigned int q=1; q<=6; q+=1) {
			printf("		#%u = %u \n", q, numbers_of_[p][q][0]);
		}
		printf("\n");
	}

	if ((gamemode_played == Classic)||(gamemode_played == Hunt)||(gamemode_played == Race)||(gamemode_played == Rain)||(gamemode_played == Sand)) {
		for (unsigned int p=1; p<=number_of_players; p+=1) {
			printf("	Matchballs player %u:   %u \n", p, numbers_of_[p][0][0]);
		}
	} else if (gamemode_played == Collect) {
		for (unsigned int p=1; p<=number_of_players; p+=1) {
			printf("	Squares collected by player %u:   %u \n", p, numbers_of_[p][0][0]);
		}
	} else if (gamemode_played == Contact) {
		for (unsigned int p=1; p<=number_of_players; p+=1) {
			printf("	Times with squares <= 5, player %u:   %u \n", p, numbers_of_[p][0][0]);
		}
	} else if (gamemode_played == Fall) {
		for (unsigned int p=1; p<=number_of_players; p+=1) {
			printf("	Points player %u:     %u \n", p, rmv_Points[p]);
			printf("	Turns with more points player %u:   %u \n", p, numbers_of_[p][0][0]);
		}
		printf("	Number of not decided #-squares:  %u \n", rmv_Points[0]);
	} else if ((gamemode_played == Fight)||(gamemode_played == Duell)) {
		for (unsigned int p=1; p<=number_of_players; p+=1) {
			printf("	Times with squares < 5, player %u:  %u \n", p, numbers_of_[p][0][0]);
		}
	} else if (gamemode_played == Arena) {
		printf("	Number of excluded abilities:  %u \n", exclude_counter);
		printf("	Offensive abilities taken:  %u \n", number_of_players-ability[0]);
		printf("	Defensive abilities taken:  %u \n", ability[0]);
	} else if (gamemode_played == Ulcer) {
		for (unsigned int p=1; p<=number_of_players; p+=1) {
			if ((ges[p] < 1000)&&(ges[p] != 0)) {
				printf("		Spieler %u: %u life(s) left.\n", p, rmv_ulcer_lifes[p]);
			}
		}
	} else if ((gamemode_played == Dynamic)||(gamemode_played == Survive)||(gamemode_played == Sand)) {	//mehr-gamemode_played
		for (unsigned int p=1; p<=number_of_players; p+=1) {
			if ((ges[p] > 1000)||(ges[p] == 0)) {
				printf("	Spieler %u: is out.\n", p);
			} else if (ges[p] < 1000) {
				printf("	Spieler %u: You own %u squares.\n", p, ges[p]);
			}
		}
	} else if (gamemode_played == Quidditch) {
		printf("	Klatscher-hits:     %u \n", Qs->Points[0]);
		for (unsigned int p=1; p<=number_of_players; p+=1) {
			printf("	Points player %u:     %u \n", p, Qs->Points[p]);
		}
	}
	printf("\n");
	if (time_matters_ttt != 0) {
		printf("	Number of penalties given until now: %u \n", pere[0]);
	}

}

void show_options_of_actions (unsigned int gamemode_played, unsigned int* information_code, unsigned int geben) {

	printf("	1) Plus:	%u	Minus :	%u \n", Plus_, Minus_);
	printf("	2) Move:	%u	Change:	%u \n", Move_2, Change_);
	printf("	3) Destroy:	%u	Revive:	%u \n", Destroy_, Revive_);
	printf("	4) Move:	%u	Boost:	%u \n", Move_4, Boost_);
	if (((gamemode_played != Arena)&&(gamemode_played != Ulcer))||((gamemode_played == Ulcer)&&(geben == 1))) {
		printf("	5) 4/5-new:	%u	2-new:	%u \n", new_4_5, new_2);
		printf("	6) 4-max:	%u	1-min:	%u \n", max_4, min_1);
	} else if (gamemode_played == Arena) {
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
			printf("	5) 4/5-new:	%u	2-new:	%u \n", new_4_5, new_2);
			printf("	6) 4-max:	%u	1-min:	%u \n", max_4, min_1);
		}
	} else if ((gamemode_played == Ulcer)&&(geben != 1)) {
		printf("	5) 3/4-new:	51	1-new:	52 \n");
		printf("	6) 3-max:	61	0-min:	62 \n");
	}
	printf("							\n");
	printf("		Go back: 100 \n");
	printf("		Menu: 10 \n");
	printf("		End game: 0 \n");

}

void show_the_numbers (unsigned int gamemode_played, unsigned int w, unsigned int d, unsigned int e, unsigned int geben) {

	if ((gamemode_played != Ulcer)&&(gamemode_played != Survive)) {
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

	if ((gamemode_played == Classic)||(gamemode_played == Collect)||(gamemode_played == Fall)||(gamemode_played == Fight)||(gamemode_played == Race)||(gamemode_played == Arena)||(gamemode_played == Ulcer)||(gamemode_played == Sand)) {	//mehr-gamemode_played
		printf("	Change: A square of yours and a near-by square of your enemy will change positions.\n");
		printf("	Destroy: Delete a near-by square of your enemy.\n");
		printf("	Boost: Use all near-by squares of your enemy as your own for the development according to dead squares.\n");

	} else if (gamemode_played == Contact) {
		printf("	Change: A square of yours and a square of your enemy in the surrounding will change positions.\n");
		printf("	Destroy: Delete a surrounding square of your enemy.\n");
		printf("	Boost: Use all surrounding squares of your enemy as your own for the development according to dead squares.\n");

	} else if (gamemode_played == Rain) {
		printf("	Change: A square of yours and a near-by #-square will change positions.\n");
		printf("	Destroy: Delete a square of your enemy, but not in the last two lines.\n");
		printf("	Boost: Use all near-by #-squares as your own for the development according to dead squares.\n");

	} else if (gamemode_played == Hunt) {
		if (geben == 1) {
			printf("	Change: The heart-block and a square of yours will change positions.\n");
			printf("	Destroy: Delete a square of your enemy.\n");
			printf("	Boost: Touching the heart_block no square of yours can die.\n");
		} else {
			printf("	Change: A square of yours and a near-by square of the hunted one will change positions.\n");
			printf("	Destroy: Delete a near-by square of your enemy.\n");
			printf("	Boost: Use all near-by squares of the hunted one as your own for the development according to dead squares.\n");
		}

	} else if (gamemode_played == Dynamic) {
		printf("	Change: A square of yours and a near-by square of your enemy or the near-by ball will change positions.\n");
		printf("	Destroy: Delete a near-by square of your enemy.\n");
		printf("	Boost: Use all near-by squares of your enemy and the near-by ball as your own for the development according to dead squares.\n");
	} else if (gamemode_played == Survive) {
		printf("	Change: A square of yours and a near-by square of your enemy or a near-by object will change positions.\n");
		printf("	Destroy: Delete a near-by square of your enemy or a near-by object.\n");
		printf("	Boost: Use all near-by squares of your enemy and near-by objects as your own for the development according to dead squares.\n");
	} else if (gamemode_played == Quidditch) {
		printf("	Change: A square of yours and a near-by square except the Torrings will change position.\n");
		printf("	Destroy: Delete a near-by square of your enemy.\n");
		printf("	Boost: Use all near-by squares of your enemy and near-by objects as your own for the development according to dead squares.\n");
	}

	printf("\n");
}


void show_figures () {	//in order of calculation

	// if (menuoperator == 1) {
		printf("		Seed:	\n");
		printf("	OOO		O*O	\n");
		printf("	O*O	--->	*O*	\n");
		printf("	OOO		O*O	\n");
		printf("	\n\n");

	// } else if (menuoperator == 2) {
		printf("		Grass:	\n");
		printf("	OOO		O*O	\n");
		printf("	O*O		O*O	\n");
		printf("	O*O	--->	O*O	\n");
		printf("	OOO		OOO	\n");
		printf("	\n\n");

	// } else if (menuoperator == 3) {
		printf("		Windmill:	\n");
		printf("	OOOO		OOOO		OOOO	\n");
		printf("	OO*O		O*OO		OO*O	\n");
		printf("	O*OO	--->	OO*O	--->	O*OO	\n");
		printf("	OOOO		OOOO		OOOO	\n");
		printf("	\n\n");

	// } else if (menuoperator == 4) {
		printf("		Popcorn:	\n");
		printf("	OOOO		O**O	\n");
		printf("	O**O		*OO*	\n");
		printf("	O**O	--->	*OO*	\n");
		printf("	OOOO		O**O	\n");
		printf("	\n\n");

	// } else if (menuoperator == 5) {
		printf("		Shield:	\n");
		printf("	OOOOO		OOOOO	\n");
		printf("	OO*OO		OO*OO	\n");
		printf("	O*O*O	--->	**O**	\n");
		printf("	OOOOO		OOOOO	\n");
		printf("	\n\n");

	// } else if (menuoperator == 6) {
		printf("		Flower:	\n");
		printf("	OOOOO		OO*OO	\n");
		printf("	OO*OO		OO*OO	\n");
		printf("	O*O*O	--->	**O**	\n");
		printf("	OO*OO		OO*OO	\n");
		printf("	OOOOO		OO*OO	\n");
		printf("	\n\n");

	// } else if (menuoperator == 7) {
		printf("		Black hole:	\n");
		printf("	OOOOO		OOOOO	\n");
		printf("	O***O		OOOOO	\n");
		printf("	O***O	--->	OO*OO	\n");
		printf("	O***O		OOOOO	\n");
		printf("	OOOOO		OOOOO	\n");
		printf("	\n\n");

	// }
}


void show_abilities (unsigned int* ability) {
	if ((ability[1] == 0)||(ability[1] == 100)) {
		printf("	Ultra light: 1 \n");
	}
	if ((ability[2] == 0)||(ability[2] == 100)) {
		printf("	Light    : 2 \n");
	}
	if ((ability[3] == 0)||(ability[3] == 100)) {
		printf("	Anti     : 3 \n");
	}
	if ((ability[4] == 0)||(ability[4] == 100)) {
		printf("	Cornered   : 4 \n");
	}
	if ((ability[5] == 0)||(ability[5] == 100)) {
		printf("	Inhibitor  : 5 \n");
	}
	if ((ability[6] == 0)||(ability[6] == 100)) {
		printf("	Shield     : 6 \n");
	}
	if ((ability[7] == 0)||(ability[7] == 100)) {
		printf("	Poisoning  : 7 \n");
	}
	if ((ability[8] == 0)||(ability[8] == 100)) {
		printf("	Pressure   : 8 \n");
	}
	if ((ability[9] == 0)||(ability[9] == 100)) {
		printf("	Electric   : 9 \n");
	}

}

