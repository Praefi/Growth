
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
#include "Growth_all_get.h"
#include "Growth_all_set.h"
#include "Growth_all_show.h"
#include "Growth_all_visual.h"
#include "Growth_all_opague.h"
#include "Growth_all_actions.h"
#include "Growth_all_Initialisierung.h"
#include "Growth_all_gamemode_specials.h"

void dynamic_take_out (unsigned int* position, unsigned int number_of_players, Spielfeld Field, unsigned int* ges, Realize_modifications_variables* rmv, unsigned int m, unsigned int n, Spielfeld Opague_o_field, Special_Fields_Collector* sfc, unsigned int geben, unsigned int gamemode_played) {

	if (position[Horizontal] == 1) {	//links
		if ((number_of_players == 2)||(number_of_players == 3)||(number_of_players == 4)||(number_of_players == 5)) {
			for (unsigned int i=1; i<m-1; i+=1) {
				for (unsigned int j=1; j<n-1; j+=1) {
					if (Field[0][i][j] == 1) {
						set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, i, j, 0);
					}
				}
			}
			out_in_dynamic_take_out (ges, rmv, 1);
		} else if (number_of_players == 6) {
			for (unsigned int i=1; i<m-1; i+=1) {
				for (unsigned int j=1; j<n-1; j+=1) {
					if ((Field[0][i][j] == 1)||(Field[0][i][j] == 4)) {
						set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, i, j, 0);
					}
				}
			}
			out_in_dynamic_take_out (ges, rmv, 1);
			out_in_dynamic_take_out (ges, rmv, 4);
		} else if ((number_of_players == 7)||(number_of_players == 8)) {
			for (unsigned int i=1; i<m-1; i+=1) {
				for (unsigned int j=1; j<n-1; j+=1) {
					if ((Field[0][i][j] == 1)||(Field[0][i][j] == 5)) {
						set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, i, j, 0);
					}
				}
			}
			out_in_dynamic_take_out (ges, rmv, 1);
			out_in_dynamic_take_out (ges, rmv, 5);
		} else if (number_of_players == 9) {
			for (unsigned int i=1; i<m-1; i+=1) {
				for (unsigned int j=1; j<n-1; j+=1) {
					if ((Field[0][i][j] == 1)||(Field[0][i][j] == 4)||(Field[0][i][j] == 7)) {
						set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, i, j, 0);
					}
				}
			}
			out_in_dynamic_take_out (ges, rmv, 1);
			out_in_dynamic_take_out (ges, rmv, 4);
			out_in_dynamic_take_out (ges, rmv, 7);
		}

	} else if (position[Vertikal] == 1) {	//oben
		if ((number_of_players == 3)||(number_of_players == 4)||(number_of_players == 5)||(number_of_players == 7)) {
			for (unsigned int i=1; i<m-1; i+=1) {
				for (unsigned int j=1; j<n-1; j+=1) {
					if (Field[0][i][j] == 2) {
						set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, i, j, 0);
					}
				}
			}

			out_in_dynamic_take_out (ges, rmv, 2);
		} else if (number_of_players == 6) {
			for (unsigned int i=1; i<m-1; i+=1) {
				for (unsigned int j=1; j<n-1; j+=1) {
					if ((Field[0][i][j] == 2)||(Field[0][i][j] == 5)) {
						set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, i, j, 0);
					}
				}
			}
			out_in_dynamic_take_out (ges, rmv, 2);
			out_in_dynamic_take_out (ges, rmv, 5);
		} else if (number_of_players == 8) {
			for (unsigned int i=1; i<m-1; i+=1) {
				for (unsigned int j=1; j<n-1; j+=1) {
					if ((Field[0][i][j] == 2)||(Field[0][i][j] == 6)) {
						set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, i, j, 0);
					}
				}
			}
			out_in_dynamic_take_out (ges, rmv, 2);
			out_in_dynamic_take_out (ges, rmv, 6);
		} else if (number_of_players == 9) {
			for (unsigned int i=1; i<m-1; i+=1) {
				for (unsigned int j=1; j<n-1; j+=1) {
					if ((Field[0][i][j] == 2)||(Field[0][i][j] == 5)||(Field[0][i][j] == 8)) {
						set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, i, j, 0);
					}
				}
			}
			out_in_dynamic_take_out (ges, rmv, 2);
			out_in_dynamic_take_out (ges, rmv, 5);
			out_in_dynamic_take_out (ges, rmv, 8);
		}

	} else if (position[Horizontal] == n-2) {	//rechts
		if ((number_of_players == 3)||(number_of_players == 4)||(number_of_players == 5)) {
			for (unsigned int i=1; i<m-1; i+=1) {
				for (unsigned int j=1; j<n-1; j+=1) {
					if (Field[0][i][j] == 3) {
						set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, i, j, 0);
					}
				}
			}
			out_in_dynamic_take_out (ges, rmv, 3);
		} else if ((number_of_players == 6)||(number_of_players == 7)) {
			for (unsigned int i=1; i<m-1; i+=1) {
				for (unsigned int j=1; j<n-1; j+=1) {
					if ((Field[0][i][j] == 3)||(Field[0][i][j] == 6)) {
						set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, i, j, 0);
					}
				}
			}
			out_in_dynamic_take_out (ges, rmv, 3);
			out_in_dynamic_take_out (ges, rmv, 6);
		} else if (number_of_players == 8) {
			for (unsigned int i=1; i<m-1; i+=1) {
				for (unsigned int j=1; j<n-1; j+=1) {
					if ((Field[0][i][j] == 3)||(Field[0][i][j] == 7)) {
						set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, i, j, 0);
					}
				}
			}
			out_in_dynamic_take_out (ges, rmv, 3);
			out_in_dynamic_take_out (ges, rmv, 7);
		} else if (number_of_players == 2) {
			for (unsigned int i=1; i<m-1; i+=1) {
				for (unsigned int j=1; j<n-1; j+=1) {
					if (Field[0][i][j] == 2) {
						set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, i, j, 0);
					}
				}
			}
			out_in_dynamic_take_out (ges, rmv, 2);
		} else if (number_of_players == 9) {
			for (unsigned int i=1; i<m-1; i+=1) {
				for (unsigned int j=1; j<n-1; j+=1) {
					if ((Field[0][i][j] == 3)||(Field[0][i][j] == 6)||(Field[0][i][j] == 9)) {
						set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, i, j, 0);
					}
				}
			}
			out_in_dynamic_take_out (ges, rmv, 3);
			out_in_dynamic_take_out (ges, rmv, 6);
			out_in_dynamic_take_out (ges, rmv, 9);
		}

	} else if (position[Vertikal] == m-2) {		//unten
		if (number_of_players == 4) {
			for (unsigned int i=1; i<m-1; i+=1) {
				for (unsigned int j=1; j<n-1; j+=1) {
					if (Field[0][i][j] == 4) {
						set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, i, j, 0);
					}
				}
			}
			out_in_dynamic_take_out (ges, rmv, 4);
		} else if (number_of_players == 5) {
			for (unsigned int i=1; i<m-1; i+=1) {
				for (unsigned int j=1; j<n-1; j+=1) {
					if ((Field[0][i][j] == 4)||(Field[0][i][j] == 5)) {
						set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, i, j, 0);
					}
				}
			}
			out_in_dynamic_take_out (ges, rmv, 4);
			out_in_dynamic_take_out (ges, rmv, 5);
		} else if (number_of_players == 7) {
			for (unsigned int i=1; i<m-1; i+=1) {
				for (unsigned int j=1; j<n-1; j+=1) {
					if ((Field[0][i][j] == 4)||(Field[0][i][j] == 7)) {
						set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, i, j, 0);
					}
				}
			}
			out_in_dynamic_take_out (ges, rmv, 4);
			out_in_dynamic_take_out (ges, rmv, 7);
		} else if (number_of_players == 8) {
			for (unsigned int i=1; i<m-1; i+=1) {
				for (unsigned int j=1; j<n-1; j+=1) {
					if ((Field[0][i][j] == 4)||(Field[0][i][j] == 8)) {
						set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, i, j, 0);
					}
				}
			}
			out_in_dynamic_take_out (ges, rmv, 4);
			out_in_dynamic_take_out (ges, rmv, 8);
		}
	}
}

void out_in_dynamic_take_out (unsigned int* ges, Realize_modifications_variables* rmv, unsigned int player) {
	if (ges[player] != 1010*player) {
		printf("	Player %u, you are out \n", player);
		ges[player] = 1010*player;
		rmv->player_counter += 1;
	}
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

void impact_y_semi_square (unsigned int m, unsigned int n, unsigned int* position, Earth_impact impact_tuple, int* dynamic_pointer, Spielfeld Field){

	for (unsigned int i=0; i<m-1; i+=1) {	//Berechnung impact y
		for (unsigned int j=0; j<n-1; j+=1) {
			if ((Field[0][i][j] != 0)&&(Field[0][i][j] != Dynamic_ball)) {
				if ((abs(position[Vertikal]-i)+abs(position[Horizontal]-j))<=(abs(impact_tuple.range)+1)) {	//Manhatten-Norm
					if ((position[Vertikal]-i) != 0) {
						dynamic_pointer[7] += (sgn(position[Vertikal]-i))*(impact_tuple.strength*(impact_tuple.range+1-abs(position[Vertikal]-i))*(impact_tuple.range+1-abs(position[Vertikal]-i)) +1);
					}
					if ((position[Horizontal]-j) != 0) {
						dynamic_pointer[6] += (sgn(position[Horizontal]-j))*(impact_tuple.strength*(impact_tuple.range+1-abs(position[Horizontal]-j))*(impact_tuple.range+1-abs(position[Horizontal]-j)) +1);
					}
				}
			}
		}
	}

}

void Dynamic_ball_movement (Spielfeld Field, Special_Fields Opague_o, unsigned int m, unsigned int n, unsigned int geben, Special_Fields_Collector* sfc, unsigned int number_of_players, unsigned int* level, Spielfeld Sf_permutations, unsigned int* information_code, Growth_Player* Growth_players, unsigned int gamemode_played, int* dynamic_pointer, unsigned int erd, unsigned int* position, unsigned int g, unsigned int* ges, Earth_impact impact_tuple, Realize_modifications_variables* rmv, Single_option_representives single_option_representives) {

	unsigned int controll, indikator1, indikator2, indikator3, space_i, space_j;

	space_i = 0;
	space_j = 0;
	controll = 0;
	indikator1 = 0;		//für Horizontal
	indikator2 = 0;		//für Vertikal
	indikator3 = 0;

	for (unsigned int i=1; i<m-1; i+=1) {
		for (unsigned int j=1; j<n-1; j+=1) {
			if (Field[0][i][j] == Dynamic_ball) {
				position[Horizontal] = j;
				position[Vertikal] = i;
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

	if ((gamemode_played == Dynamic)&&((g-1)%number_of_players == 0)&&(rmv->var_[1] != 1010)) {	//Dynamic_ball movement

		Opague_show_controll (level, Field, Opague_o, m, n, geben, rmv->AOP, sfc, number_of_players, gamemode_played, single_option_representives.invisible, Sf_permutations, information_code, Growth_players);
		
		dynamic_pointer[6] = 0;		//impact y_Horizontal
		dynamic_pointer[7] = 0;		//impact y_Vertikal

		dynamic_pointer[Horizontal] = dynamic_pointer[4] + dynamic_pointer[2];	//aus "sgn(a)*a^2" mach "a", done
		dynamic_pointer[Vertikal] = dynamic_pointer[5] + dynamic_pointer[3];

		dynamic_pointer[2] += dynamic_pointer[4];
		dynamic_pointer[3] += dynamic_pointer[5];

		impact_y_semi_square (m, n, position, impact_tuple, dynamic_pointer, Field);

		dynamic_pointer[4] += dynamic_pointer[6];
		dynamic_pointer[5] += dynamic_pointer[7] + erd;

		while (abs(dynamic_pointer[Vertikal])+abs(dynamic_pointer[Horizontal]) != 0){

			// printf("	Test-print \n");
			// show_field (number_of_players, single_option_representives.invisible, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, sfc);		//test
			// printf("	Test-print \n");
			// printf("	\n");
			// printf("	indikator1: %u \n", indikator1);
			// printf("	indikator2: %u \n", indikator2);
			// printf("	sgn(dynamic_pointer[Horizontal]): %d \n", sgn(dynamic_pointer[Horizontal]));
			// printf("	sgn(dynamic_pointer[Vertikal]): %d \n", sgn(dynamic_pointer[Vertikal]));
			// printf("	position[Horizontal]: %u \n", position[Horizontal]);
			// printf("	position[Vertikal]: %u \n", position[Vertikal]);

			// printf("	\n");
			// printf("	Object position: (%u, %u) \n", position[Vertikal], position[Horizontal]);
			// printf("	Weg s: (%d, %d) \n", dynamic_pointer[Vertikal], dynamic_pointer[Horizontal]);
			// printf("	Geschw. v: (%d, %d) \n", dynamic_pointer[3], dynamic_pointer[2]);
			// printf("	Beschl. a: (%d, %d) \n", dynamic_pointer[5], dynamic_pointer[4]);
			// printf("	Impact  y(+erd): (%d, %d) \n", dynamic_pointer[7]+erd, dynamic_pointer[6]);
			// printf("	ffffffff\n");
			// printf("	\n");	//test

			// iteration += 1;

			dynamic_take_out (position, number_of_players, Field, ges, rmv, m, n, Opague_o.field, sfc, geben, gamemode_played);

			indikator1 = 0;
			indikator2 = 0;		//Staffelung: grösser im Betrag 1, anderer nur geblockt 3, anderer reflektiert 5, anderer Null-Betrag 5		3 und 5 und 5 schließen sich aus

			controll = 0;

			if (abs(dynamic_pointer[Horizontal])>abs(dynamic_pointer[Vertikal])) {	//indikator1, position[Horizontal], dynamic_pointer[Horizontal] Horizontal
				indikator1 += 1;
			} else if (abs(dynamic_pointer[Horizontal])<abs(dynamic_pointer[Vertikal])) {
				indikator2 += 1;
			}

			if (sgn(dynamic_pointer[Horizontal])>0) {	//Betrag = 0 wird verhindert
				for (unsigned int j=position[Horizontal]+1; j<n-1; j+=1) {
					if ((Field[0][position[Vertikal]][j] == 0)&&(position[Horizontal]+1 < n-1)) {
						space_j = j;
						if (j != position[Horizontal]+1) {
							indikator2 += 3;
						}
						controll = 1;
						break;
					}
				}
				if ((indikator2 < 3)&&(controll != 1)) {
					indikator2 += 5;
				}
			} else if (sgn(dynamic_pointer[Horizontal])<0) {
				for (unsigned int j=position[Horizontal]-1; j>0; j-=1) {
					if ((Field[0][position[Vertikal]][j] == 0)&&(position[Horizontal]-1 > 0)) {
						space_j = j;
						if (j != position[Horizontal]-1) {
							indikator2 += 3;
						}
						controll = 1;
						break;
					}
				}
				if ((indikator2 < 3)&&(controll != 1)) {
					indikator2 += 5;
				}
			} else if (sgn(dynamic_pointer[Horizontal]) == 0) {
				indikator2 += 5;
			}
			controll = 0;

			if (sgn(dynamic_pointer[Vertikal])>0) {	//Betrag = 0 wird verhindert
				for (unsigned int i=position[Vertikal]+1; i<m-1; i+=1) {
					if ((Field[0][i][position[Horizontal]] == 0)&&(position[Vertikal]+1 < m-1)) {
						space_i = i;
						if (i != position[Vertikal]+1) {
							indikator1 += 3;
						}
						controll = 1;
						break;
					}
				}
				if ((indikator1 < 3)&&(controll != 1)) {
					indikator1 += 5;
				}
			} else if (sgn(dynamic_pointer[Vertikal])<0) {
				for (unsigned int i=position[Vertikal]-1; i>0; i-=1) {
					if ((Field[0][i][position[Horizontal]] == 0)&&(position[Vertikal]-1 > 0)) {
						space_i = i;
						if (i != position[Vertikal]-1) {
							indikator1 += 3;
						}
						controll = 1;
						break;
					}
				}
				if ((indikator1 < 3)&&(controll != 1)) {
					indikator1 += 5;
				}
			} else if (sgn(dynamic_pointer[Vertikal]) == 0) {	//Betrag = 0 hier angenommen
				indikator1 += 5;
			}
			controll = 0;


			if ((abs(dynamic_pointer[Horizontal]) == abs(dynamic_pointer[Vertikal])) && (indikator3 == 0)) {	//Betrag gleich, indikator3 = 1 zeigt kein Fortschritt auf diesem Weg.

				if (sgn(dynamic_pointer[Horizontal]) == sgn(dynamic_pointer[Vertikal])) {	//Vorzeichen gleich

					if (sgn(dynamic_pointer[Horizontal])>0) {	//Vorzeichen positiv

						if ((position[Horizontal] +1 < n-1) && (position[Vertikal] +1 < m-1) && (Field[0][position[Vertikal] +1][position[Horizontal] +1] == 0)) {	//Noch im Spielfeld? Ja und diagonal ist frei

							Field[0][position[Vertikal] +1][position[Horizontal] +1] = Dynamic_ball;
							Field[0][position[Vertikal]][position[Horizontal]] = 0;
							position[Vertikal] += 1;
							position[Horizontal] += 1;
							dynamic_pointer[Horizontal] -= 1;
							dynamic_pointer[Vertikal] -= 1;

						} else if ((position[Horizontal] +1 >= n-1) && (position[Vertikal] +1 >= m-1)) { //beide nein

							Reflection (dynamic_pointer, 0, erd);
							Reflection (dynamic_pointer, 1, erd);

							continue;

						} else if (position[Horizontal]+1 >= n-1) {	//Horizontal nein

							Reflection (dynamic_pointer, 0, erd);

							continue;

						} else if (position[Vertikal]+1 >= m-1) {	//Vertikal nein

							Reflection (dynamic_pointer, 1, erd);

							continue;

						} else {
							indikator3 = 1;
							continue;
						}

					} else if (sgn(dynamic_pointer[Horizontal])<0) {	//Vorzeichen negativ

						if ((position[Horizontal]-1 > 0) && (position[Vertikal]-1 > 0) && (Field[0][position[Vertikal]-1][position[Horizontal]-1] == 0)) {	//Noch im Spielfeld? Ja und diagonal ist frei

							Field[0][position[Vertikal]-1][position[Horizontal]-1] = Dynamic_ball;
							Field[0][position[Vertikal]][position[Horizontal]] = 0;
							position[Vertikal] -= 1;
							position[Horizontal] -= 1;
							dynamic_pointer[Horizontal] += 1;
							dynamic_pointer[Vertikal] += 1;

						} else if ((position[Horizontal]-1 == 0) && (position[Vertikal]-1 == 0)) { //beide nein

							Reflection (dynamic_pointer, 0, erd);
							Reflection (dynamic_pointer, 1, erd);

							continue;

						} else if (position[Horizontal]-1 == 0) {	//Horizontal nein

							Reflection (dynamic_pointer, 0, erd);

							continue;

						} else if (position[Vertikal]-1 == 0) {	//Vertikal nein

							Reflection (dynamic_pointer, 1, erd);

							continue;

						} else {
							indikator3 = 1;
							continue;
						}

					}

				} else {	//unterschiedliches Vorzeichen

					if (sgn(dynamic_pointer[Horizontal])>0) {	//Vorzeichen Horizontal positiv

						if ((position[Horizontal]+1 < n-1) && (position[Vertikal]-1 > 0) && (Field[0][position[Vertikal]-1][position[Horizontal]+1] == 0)) {	//Noch im Spielfeld? Ja und diagonal ist frei

							Field[0][position[Vertikal]-1][position[Horizontal]+1] = Dynamic_ball;
							Field[0][position[Vertikal]][position[Horizontal]] = 0;
							position[Vertikal] -= 1;
							position[Horizontal] += 1;
							dynamic_pointer[Horizontal] -= 1;
							dynamic_pointer[Vertikal] += 1;

						} else if ((position[Horizontal]+1 >= n-1) && (position[Vertikal]-1 == 0)) { //beide nein

							Reflection (dynamic_pointer, 0, erd);
							Reflection (dynamic_pointer, 1, erd);

							continue;

						} else if (position[Horizontal]+1 >= n-1) {	//Horizontal nein

							Reflection (dynamic_pointer, 0, erd);

							continue;

						} else if (position[Vertikal]-1 == 0) {	//Vertikal nein

							Reflection (dynamic_pointer, 1, erd);

							continue;

						} else {
							indikator3 = 1;
							continue;
						}

					}  else if (sgn(dynamic_pointer[Horizontal])<0) {	//Vorzeichen Horizontal negativ

						if ((position[Horizontal]-1 > 0) && (position[Vertikal]+1 < m-1) && (Field[0][position[Vertikal]+1][position[Horizontal]-1] == 0)) {	//Noch im Spielfeld? Ja und diagonal ist frei

							Field[0][position[Vertikal]+1][position[Horizontal]-1] = Dynamic_ball;
							Field[0][position[Vertikal]][position[Horizontal]] = 0;
							position[Vertikal] += 1;
							position[Horizontal] -= 1;
							dynamic_pointer[Horizontal] += 1;
							dynamic_pointer[Vertikal] -= 1;

						} else if ((position[Horizontal]-1 == 0) && (position[Vertikal]+1 >= m-1)) { //beide nein

							Reflection (dynamic_pointer, 0, erd);
							Reflection (dynamic_pointer, 1, erd);

							continue;

						} else if (position[Horizontal] -1 == 0) {	//Horizontal nein

							Reflection (dynamic_pointer, 0, erd);

							continue;

						} else if (position[Vertikal] +1 >= m-1) {	//Vertikal nein

							Reflection (dynamic_pointer, 1, erd);

							continue;

						} else {
							indikator3 = 1;
							continue;
						}

					}

				}

			} else if (indikator1 >= indikator2) {	//partielle Durchführung, außer bei doppelter Reflektion, nimm s_Horizontal = dynamic_pointer[Horizontal]
				if (indikator2 >= 5) {

					if (abs(dynamic_pointer[Horizontal]) > 0) {
						Reflection (dynamic_pointer, 0, erd);
					}
					if (abs(dynamic_pointer[Vertikal]) > 0) {
						Reflection (dynamic_pointer, 1, erd);
					}

					continue;

				} else if (indikator2 >= 3) {	//moveable crash, um Reflection zu verhindern

					if (sgn(dynamic_pointer[Horizontal])>0) {
						for (unsigned int r=space_j; r>position[Horizontal]; r-=1) {
							set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, sfc, number_of_players, Field, 0, position[Vertikal], r, Field[0][position[Vertikal]][r-1]);
						}
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, sfc, number_of_players, Field, 0, position[Vertikal], position[Horizontal], 0);
						position[Horizontal] += 1;
						dynamic_pointer[Horizontal] -= 1;
						dynamic_pointer[2] -= 1;
						dynamic_pointer[4] -= 1;

						if (dynamic_pointer[Horizontal] != 0) {
							dynamic_pointer[Horizontal] -= 1;
						}

					} else if (sgn(dynamic_pointer[Horizontal])<0) {
						for (unsigned int r=space_j; r<position[Horizontal]; r+=1) {
							set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, sfc, number_of_players, Field, 0, position[Vertikal], r, Field[0][position[Vertikal]][r+1]);
						}
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, sfc, number_of_players, Field, 0, position[Vertikal], position[Horizontal], 0);
						position[Horizontal] -= 1;
						dynamic_pointer[Horizontal] += 1;
						dynamic_pointer[2] += 1;
						dynamic_pointer[4] += 1;

						if (dynamic_pointer[Horizontal] != 0) {
							dynamic_pointer[Horizontal] += 1;
						}
					}

				} else {		//freier Schritt
					if (sgn(dynamic_pointer[Horizontal])>0) {

						Field[0][position[Vertikal]][position[Horizontal]+1] = Dynamic_ball;
						Field[0][position[Vertikal]][position[Horizontal]] = 0;
						dynamic_pointer[Horizontal] -= 1;
						position[Horizontal] += 1;

					} else if (sgn(dynamic_pointer[Horizontal])<0) {

						Field[0][position[Vertikal]][position[Horizontal]-1] = Dynamic_ball;
						Field[0][position[Vertikal]][position[Horizontal]] = 0;
						dynamic_pointer[Horizontal] += 1;
						position[Horizontal] -= 1;

					}		//Diagonal-Schritt mit partieller Reflection entzieht sich dem freien Schritt
				}

			} else if (indikator2 >= indikator1) {	//partielle Durchführung, außer bei doppelter Reflektion, nimm s_Vertikal = dynamic_pointer[Vertikal]
				if (indikator1 >= 5) {

					if (abs(dynamic_pointer[Horizontal]) > 0) {
						Reflection (dynamic_pointer, 0, erd);
					}
					if (abs(dynamic_pointer[Vertikal]) > 0) {
						Reflection (dynamic_pointer, 1, erd);
					}
					// printf("	\n");	//test
					// printf("	indikator1: %u \n", indikator1);
					// printf("	indikator2: %u \n", indikator2);
					// printf("	sgn(dynamic_pointer[Horizontal]): %d \n", sgn(dynamic_pointer[Horizontal]));
					// printf("	sgn(dynamic_pointer[Vertikal]): %d \n", sgn(dynamic_pointer[Vertikal]));
					// printf("	position[Horizontal]: %u \n", position[Horizontal]);
					// printf("	position[Vertikal]: %u \n", position[Vertikal]);

					// printf("	\n");
					// printf("	Object position: (%u, %u) \n", position[Vertikal], position[Horizontal]);
					// printf("	Weg s: (%d, %d) \n", dynamic_pointer[Vertikal], dynamic_pointer[Horizontal]);
					// printf("	Geschw. v: (%d, %d) \n", dynamic_pointer[3], dynamic_pointer[2]);
					// printf("	Beschl. a: (%d, %d) \n", dynamic_pointer[5], dynamic_pointer[4]);
					// printf("	Impact  y(+erd): (%d, %d) \n", dynamic_pointer[7]+erd, dynamic_pointer[6]);
					// printf("	######\n");
					// printf("	\n");

					continue;

				} else if (indikator1 >= 3) {	//moveable crash, um Reflection zu verhindern

					if (sgn(dynamic_pointer[Vertikal])>0) {
						for (unsigned int r=space_i; r>position[Vertikal]; r-=1) {
							set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, sfc, number_of_players, Field, 0, r, position[Horizontal], Field[0][r-1][position[Horizontal]]);
						}
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, sfc, number_of_players, Field, 0, position[Vertikal], position[Horizontal], 0);
						position[Vertikal] += 1;
						dynamic_pointer[Vertikal] -= 1;
						dynamic_pointer[3] -= 1;
						dynamic_pointer[5] -= 1;

						if (dynamic_pointer[Vertikal] != 0) {
							dynamic_pointer[Vertikal] -= 1;
						}

					} else if (sgn(dynamic_pointer[Vertikal])<0) {
						for (unsigned int r=space_i; r<position[Vertikal]; r+=1) {
							set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, sfc, number_of_players, Field, 0, r, position[Horizontal], Field[0][r+1][position[Horizontal]]);
						}
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, sfc, number_of_players, Field, 0, position[Vertikal], position[Horizontal], 0);
						position[Vertikal] -= 1;
						dynamic_pointer[Vertikal] += 1;
						dynamic_pointer[3] += 1;
						dynamic_pointer[5] += 1;

						if (dynamic_pointer[Vertikal] != 0) {
							dynamic_pointer[Vertikal] += 1;
						}
					}

				} else {		//freier Schritt
					if (sgn(dynamic_pointer[Vertikal])>0) {

						Field[0][position[Vertikal]+1][position[Horizontal]] = Dynamic_ball;
						Field[0][position[Vertikal]][position[Horizontal]] = 0;
						dynamic_pointer[Vertikal] -= 1;
						position[Vertikal] += 1;

					} else if (sgn(dynamic_pointer[Vertikal])<0) {

						Field[0][position[Vertikal]-1][position[Horizontal]] = Dynamic_ball;
						Field[0][position[Vertikal]][position[Horizontal]] = 0;
						dynamic_pointer[Vertikal] += 1;
						position[Vertikal] -= 1;

					}
				}

			}

			dynamic_take_out (position, number_of_players, Field, ges, rmv, m, n, Opague_o.field, sfc, geben, gamemode_played);

			if ((abs(dynamic_pointer[Vertikal])+abs(dynamic_pointer[Horizontal])) == 0) {

				// printf("	\n");	//test
				// printf("	Object position: (%u, %u) \n", position[Vertikal], position[Horizontal]);
				// printf("	Weg s: (%d, %d) \n", dynamic_pointer[Vertikal], dynamic_pointer[Horizontal]);
				// printf("	Geschw. v: (%d, %d) \n", dynamic_pointer[3], dynamic_pointer[2]);
				// printf("	Beschl. a: (%d, %d) \n", dynamic_pointer[5], dynamic_pointer[4]);
				// printf("	Impact  y(+erd): (%d, %d) \n", dynamic_pointer[7]+erd, dynamic_pointer[6]);
				// printf("	bbbbbbb\n");

				break;
			}

			indikator3 = 0;

			//Feintuning

			dynamic_pointer[6] = 0;		//impact y_Horizontal
			dynamic_pointer[7] = 0;		//impact y_Vertikal

			impact_y_semi_square (m, n, position, impact_tuple, dynamic_pointer, Field);

			if (sgn(dynamic_pointer[2]) < 0) {		//Horizontal (ohne erd)
				if (sgn(dynamic_pointer[6]) > 0) {
					for (int r=1; r<=abs(erd); r+=1) {
						dynamic_pointer[2] += 1;
						if (dynamic_pointer[2] == 0) {
							break;
						}
					}
				}
			} else if (sgn(dynamic_pointer[2]) > 0) {		//dynamic_pointer[2] = v_Horizontal
				if (sgn(dynamic_pointer[6]) < 0) {
					for (int r=1; r<=abs(erd); r+=1) {
						dynamic_pointer[2] -= 1;
						if (dynamic_pointer[2] == 0) {
							break;
						}
					}
				}
			}

			if (sgn(dynamic_pointer[4]) < 0) {		//Horizontal (ohne erd)
				if (sgn(dynamic_pointer[6]) > 0) {
					for (int r=1; r<=abs(erd); r+=1) {
						dynamic_pointer[4] += 1;
						if (dynamic_pointer[4] == 0) {
							break;
						}
					}

					if ((abs(dynamic_pointer[4]) < abs(dynamic_pointer[6])) && (sgn(dynamic_pointer[4]) == sgn(dynamic_pointer[Horizontal]))&&(sgn(dynamic_pointer[Horizontal]) != 0)) {	//s_Horizontal-Verringerung

						for (int r=1; r<=(abs(dynamic_pointer[6])-abs(dynamic_pointer[4])); r+=1) {
							dynamic_pointer[Horizontal] += 1;
							if (dynamic_pointer[Horizontal] == 0) {
								break;
							}
						}
					}
				}

			} else if (sgn(dynamic_pointer[4]) > 0) {		//dynamic_pointer[4] = a_Horizontal
				if (sgn(dynamic_pointer[6]) < 0) {
					for (int r=1; r<=abs(erd); r+=1) {
						dynamic_pointer[4] -= 1;
						if (dynamic_pointer[4] == 0) {
							break;
						}
					}

					if ((abs(dynamic_pointer[4]) < abs(dynamic_pointer[6])) && (sgn(dynamic_pointer[4]) == sgn(dynamic_pointer[Horizontal]))&&(sgn(dynamic_pointer[Horizontal]) != 0)) {

						for (int r=1; r<=(abs(dynamic_pointer[6])-abs(dynamic_pointer[4])); r+=1) {	//s_Horizontal-Verringerung
							dynamic_pointer[Horizontal] -= 1;
							if (dynamic_pointer[Horizontal] == 0) {
								break;
							}
						}
					}
				}

			} else if ((sgn(dynamic_pointer[4]) == 0) && (sgn(dynamic_pointer[2]) != 0) && (sgn(dynamic_pointer[6]) != 0)) {

				if (sgn(dynamic_pointer[6]) < sgn(dynamic_pointer[2])) {

					if ((0 < abs(dynamic_pointer[6])) && (sgn(dynamic_pointer[2]) == sgn(dynamic_pointer[Horizontal]))) {

						for (int r=1; r<=(abs(dynamic_pointer[6])-abs(dynamic_pointer[4])); r+=1) {	//s_Horizontal-Verringerung
							dynamic_pointer[Horizontal] -= 1;
							if (dynamic_pointer[Horizontal] == 0) {
								break;
							}
						}
					}

				} else if (sgn(dynamic_pointer[6]) > sgn(dynamic_pointer[2])) {

					if ((0 < abs(dynamic_pointer[6])) && (sgn(dynamic_pointer[2]) == sgn(dynamic_pointer[Horizontal]))) {	//s_Horizontal-Verringerung

						for (int r=1; r<=(abs(dynamic_pointer[6])-abs(dynamic_pointer[4])); r+=1) {
							dynamic_pointer[Horizontal] += 1;
							if (dynamic_pointer[Horizontal] == 0) {
								break;
							}
						}
					}
				}

			}




			if (sgn(dynamic_pointer[3] < 0)) {		//Vertikal (mit erd)
				if (sgn(dynamic_pointer[7]+erd) > 0) {
					for (int r=1; r<=abs(erd); r+=1) {
						dynamic_pointer[3] += 1;
						if (dynamic_pointer[3] == 0) {
							break;
						}
					}
				}
			} else if (sgn(dynamic_pointer[3] > 0)) {		//dynamic_pointer[3] = v_Vertikal
				if (sgn(dynamic_pointer[7]+erd) < 0) {	//<= wegen-erd-Kompensierung, zurückgenommen wegen eventuell negativer erd
					for (int r=1; r<=abs(erd); r+=1) {
						dynamic_pointer[3] -= 1;
						if (dynamic_pointer[3] == 0) {
							break;
						}
					}
				}
			}

			if (sgn(dynamic_pointer[5] < 0)) {		//Vertikal (mit erd)
				if (sgn(dynamic_pointer[7]+erd) > 0) {
					for (int r=1; r<=abs(erd); r+=1) {
						dynamic_pointer[5] += 1;
						if (dynamic_pointer[5] == 0) {
							break;
						}
					}

					if ((abs(dynamic_pointer[5]) < abs(dynamic_pointer[7]+erd))&&(sgn(dynamic_pointer[5]) == sgn(dynamic_pointer[Vertikal]))&&(sgn(dynamic_pointer[Vertikal]) != 0)) {	//s_Vertikal-Verringerung

						for (int r=1; r<=(abs(dynamic_pointer[7]+erd)-abs(dynamic_pointer[5])); r+=1) {
							dynamic_pointer[Vertikal] += 1;
							if (dynamic_pointer[Vertikal] == 0) {
								break;
							}
						}
					}
				}

			} else if (sgn(dynamic_pointer[5]) > 0) {		//dynamic_pointer[5] = a_Vertikal
				if (sgn(dynamic_pointer[7]+erd) < 0) {	//<= wegen-erd-Kompensierung, zurückgenommen wegen eventuell negativer erd
					for (int r=1; r<=abs(erd); r+=1) {
						dynamic_pointer[5] -= 1;
						if (dynamic_pointer[5] == 0) {
							break;
						}
					}

					if ((abs(dynamic_pointer[5]) < abs(dynamic_pointer[7]+erd)) && (sgn(dynamic_pointer[5]) == sgn(dynamic_pointer[Vertikal]))&&(sgn(dynamic_pointer[Vertikal]) != 0)) {

						for (int r=1; r<=(abs(dynamic_pointer[7]+erd)-abs(dynamic_pointer[5])); r+=1) {	//s_Vertikal-Verringerung
							dynamic_pointer[Vertikal] -= 1;
							if (dynamic_pointer[Vertikal] == 0) {
								break;
							}
						}
					}
				}

			} else if ((sgn(dynamic_pointer[5]) == 0) && (sgn(dynamic_pointer[3]) != 0) && (sgn(dynamic_pointer[7]+erd) != 0)) {

				if (sgn(dynamic_pointer[7]+erd) < sgn(dynamic_pointer[3])) {

					if ((0 < abs(dynamic_pointer[7]+erd)) && (sgn(dynamic_pointer[3]) == sgn(dynamic_pointer[Vertikal]))) {

						for (int r=1; r<=(abs(dynamic_pointer[7]+erd)-abs(dynamic_pointer[5])); r+=1) {	//s_Vertikal-Verringerung
							dynamic_pointer[Vertikal] -= 1;
							if (dynamic_pointer[Vertikal] == 0) {
								break;
							}
						}
					}

				} else if (sgn(dynamic_pointer[7]+erd) > sgn(dynamic_pointer[3])) {

					if ((0 < abs(dynamic_pointer[7]+erd)) && (sgn(dynamic_pointer[3]) == sgn(dynamic_pointer[Vertikal]))) {	//s_Vertikal-Verringerung

						for (int r=1; r<=(abs(dynamic_pointer[7]+erd)-abs(dynamic_pointer[5])); r+=1) {
							dynamic_pointer[Vertikal] += 1;
							if (dynamic_pointer[Vertikal] == 0) {
								break;
							}
						}
					}
				}

			}

			if ((sgn(dynamic_pointer[Horizontal]) > 0)&&(sgn(dynamic_pointer[2]) >= 0)&&(sgn(dynamic_pointer[4]) < 0)) {		//a_Horizontal-verringerung
				dynamic_pointer[4] += 1;
			} else if ((sgn(dynamic_pointer[Horizontal]) < 0)&&(sgn(dynamic_pointer[2]) <= 0)&&(sgn(dynamic_pointer[4]) > 0)) {
				dynamic_pointer[4] -= 1;
			}

			if ((sgn(dynamic_pointer[Vertikal]) > 0)&&(sgn(dynamic_pointer[3]) >= 0)&&(sgn(dynamic_pointer[5]) < 0)) {		//a_Vertikal-verringerung
				dynamic_pointer[5] += 1;
			} else if ((sgn(dynamic_pointer[Vertikal]) < 0)&&(sgn(dynamic_pointer[3]) <= 0)&&(sgn(dynamic_pointer[5]) > 0)) {
				dynamic_pointer[5] -= 1;
			}

			// printf("	\n");	//test
			// printf("	indikator1: %u \n", indikator1);
			// printf("	indikator2: %u \n", indikator2);
			// printf("	sgn(dynamic_pointer[Horizontal]): %d \n", sgn(dynamic_pointer[Horizontal]));
			// printf("	sgn(dynamic_pointer[Vertikal]): %d \n", sgn(dynamic_pointer[Vertikal]));
			// printf("	position[Horizontal]: %u \n", position[Horizontal]);
			// printf("	position[Vertikal]: %u \n", position[Vertikal]);

			// printf("	\n");
			// printf("	Object position: (%u, %u) \n", position[Vertikal], position[Horizontal]);
			// printf("	Weg s: (%d, %d) \n", dynamic_pointer[Vertikal], dynamic_pointer[Horizontal]);
			// printf("	Geschw. v: (%d, %d) \n", dynamic_pointer[3], dynamic_pointer[2]);
			// printf("	Beschl. a: (%d, %d) \n", dynamic_pointer[5], dynamic_pointer[4]);
			// printf("	Impact  y(+erd): (%d, %d) \n", dynamic_pointer[7]+erd, dynamic_pointer[6]);
			// printf("	\n");
			// printf("	\n");

			//beschleunigung abbremsen, falls sgn(s)==sgn(v)!=sgn(a), done

		}	//komplette durchrechnung

	}

	// scanf("%u", &pause);	//test
	// printf("	#line 4494, komplette durchrechnung \n");	//test

	if (gamemode_played == Dynamic) {	//Ausscheiden der Teams?
		dynamic_take_out (position, number_of_players, Field, ges, rmv, m, n, Opague_o.field, sfc, geben, gamemode_played);
	}

}

void battle (Spielfeld Spiel, unsigned int m, unsigned int n, Spielfeld Field, unsigned int geben, Spielfeld Opague_o_field, Special_Fields_Collector* sfc, unsigned int number_of_players, unsigned int gamemode_played){
	Spielfeld chain, chain_temp;
	unsigned int chain_total[number_of_players+1], a;

	#ifdef Contact_mistake_search
	printf("battle ok.1Con \n"); //test
	#endif

	// printf("battle ok.1 \n"); //test
	
	a = 0;
	unsigned_int_array_null_initialisierung(chain_total, number_of_players);
	chain = Spielfeld_Create (m, n, number_of_players);

	for (unsigned int i=1; i<m-1; i+=1){
		for (unsigned int j=1; j<n-1; j+=1){
			if (Spiel[0][i][j] == geben){

				// printf("battle ok.2 \n"); //test

				for (unsigned int u=i-1; u<=i+1; u++){
					for (unsigned int o=j-1; o<=j+1; o++){
						if ((u+o)%2 == (i+j+1)%2) {
							if ((Spiel[0][u][o] != geben)&&(Spiel[0][u][o] <= number_of_players)&&(Spiel[0][u][o] != 0)) {

								// printf("battle ok.2.1 \n"); //test

								chain_temp = Spielfeld_Create (m, n, 0);

								// printf("battle ok.2.0.5 \n"); //test

								set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, chain_temp, 0, i, j, geben);

								// printf("battle ok.2.1.1 \n"); //test

								chain_total[geben] = 1;

								// printf("battle ok.2.1.2 \n"); //test

								chain_count (Spiel, i, j, Field, chain_temp, geben, chain_total, geben, Opague_o_field, sfc, number_of_players, gamemode_played);

								// printf("battle ok.2.1.3 \n"); //test

								set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, chain_temp, 0, u, o, Spiel[0][u][o]);

								// printf("battle ok.2.1.4 \n"); //test

								chain_total[Spiel[0][u][o]] = 1;

								// printf("battle ok.2.1.5 \n"); //test

								chain_count (Spiel, u, o, Field, chain_temp, Spiel[0][u][o], chain_total, geben, Opague_o_field, sfc, number_of_players, gamemode_played);

								// printf("battle ok.2.2 \n"); //test

								if (chain_total[geben] > chain_total[Spiel[0][u][o]]){
									for (unsigned int h=1; h<m-1; h+=1){
										for (unsigned int k=1; k<n-1; k+=1){
											if ((chain_temp[0][h][k] == Spiel[0][u][o])&&(chain[geben][h][k] < chain_total[geben])){
												set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, chain, geben, h, k, chain_total[geben]);
											}
										}
									}
								} else if (chain_total[Spiel[0][u][o]] > chain_total[geben]){
									for (unsigned int h=1; h<m-1; h+=1){
										for (unsigned int k=1; k<n-1; k+=1){
											if ((chain_temp[0][h][k] == geben)&&(chain[Spiel[0][u][o]][h][k] < chain_total[Spiel[0][u][o]])){
												set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, chain, Spiel[0][u][o], h, k, chain_total[Spiel[0][u][o]]);
											}
										}
									}
								} else if ((chain_total[geben] == chain_total[Spiel[0][u][o]])&&(chain_total[geben] == 1)&&(chain[geben][u][o] < chain_total[geben])){
									set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, chain, geben, u, o, chain_total[geben]);
								}

								Spielfeld_Destroy (chain_temp, m, 0);

								// printf("battle ok.2.3 \n"); //test

							}
						}
					}
				}
			}
		}
	}

	// printf("battle ok.3 \n"); //test

	for (unsigned int i=1; i<m-1; i+=1){
		for (unsigned int j=1; j<n-1; j+=1){
			if (Spiel[0][i][j] != 0) {
				for (unsigned int p=1; p<=number_of_players; p++) {
					a = 0;
					for (unsigned int q=1; q<=number_of_players; q++) {
						if ((p!=q)&&(chain[p][i][j] > chain[q][i][j])){
							a += 1;

							// printf("battle ok.3.1 \n"); //test
						}
					}

					if (a > 1) {	//this square will change
						set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Spiel, 0, i, j, 0);

						// printf("battle ok.3.2 \n"); //test
					}

					if (a == number_of_players-1) {	//highest values
						set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Spiel, 0, i, j, p);

						// printf("battle ok.3.3 \n"); //test
					}
					a = 0;
				}
			}
		}
	}

	#ifdef Contact_mistake_search
	printf("battle ok.2Con \n"); //test
	#endif

	Spielfeld_Destroy (chain, m, number_of_players);
	
	// printf("battle ok.4 \n"); //test
	
}	//possible to modify for >2 player, done

void chain_count (Spielfeld Spiel, unsigned int i, unsigned int j, Spielfeld Field, Spielfeld chain_temp, unsigned int player, unsigned int* chain_total, unsigned int geben, Spielfeld Opague_o_field, Special_Fields_Collector* sfc, unsigned int number_of_players, unsigned int gamemode_played){	//player=geben

	for (unsigned int u=i-1; u<=i+1; u++){
		for (unsigned int o=j-1; o<=j+1; o++){
			if ((u+o)%2 == (i+j+1)%2) {
				if ((Spiel[0][u][o] == player)&&(chain_temp[0][u][o] != player)){
					set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, chain_temp, 0, u, o, player);
					chain_total[player] += 1;
					chain_count (Spiel, u, o, Field, chain_temp, player, chain_total, geben, Opague_o_field, sfc, number_of_players, gamemode_played);
				}
			}
		}
	}
}

void touch (Spielfeld Spiel, Spielfeld Field, unsigned int m, unsigned int n, unsigned int geben, Spielfeld evolution_nl, Special_Fields_Collector* sfc, Spielfeld Opague_o_field, unsigned int number_of_players, unsigned int gamemode_played){
	unsigned int value_found;
	value_found = hayir;

	for (unsigned int i=1; i<m-1; i+=1){
		for (unsigned int j=1; j<n-1; j+=1){
			if (Spiel[0][i][j] == Fall_ball){
				//test printf("	#-Block alt:	i=%u ,	j=%u \n ", i, j);
				for (unsigned int p=1; p<=number_of_players; p++) {
					if (geben%2 == 1){
						if (((evolution_nl[geben][i][j-1] == geben) || (Spiel[0][i][j-1] == geben))&&(j != (n-2))){
							set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Spiel, 0, i, j+1, Fall_ball);
							set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Spiel, 0, i, j, 0);
						} else if (((evolution_nl[geben][i+1][j] == geben) || (Spiel[0][i+1][j] == geben))&&(i != 1)){
							set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Spiel, 0, i-1, j, Fall_ball);
							set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Spiel, 0, i, j, 0);
						} else if (((evolution_nl[geben][i-1][j] == geben) || (Spiel[0][i-1][j] == geben))&&(i != (m-2))){
							set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Spiel, 0, i+1, j, Fall_ball);
							set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Spiel, 0, i, j, 0);
						} else if (((evolution_nl[geben][i][j+1] == geben) || (Spiel[0][i][j+1] == geben))&&(j != 1)){
							set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Spiel, 0, i, j-1, Fall_ball);
							set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Spiel, 0, i, j, 0);
						}
					} else if (geben%2 == 0){
						if (((evolution_nl[geben][i][j+1] == geben) || (Spiel[0][i][j+1] == geben))&&(j != 1)){
							set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Spiel, 0, i, j-1, Fall_ball);
							set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Spiel, 0, i, j, 0);
						} else if (((evolution_nl[geben][i+1][j] == geben) || (Spiel[0][i+1][j] == geben))&&(i != 1)){
							set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Spiel, 0, i-1, j, Fall_ball);
							set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Spiel, 0, i, j, 0);
						} else if (((evolution_nl[geben][i-1][j] == geben) || (Spiel[0][i-1][j] == geben))&&(i != (m-2))){
							set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Spiel, 0, i+1, j, Fall_ball);
							set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Spiel, 0, i, j, 0);
						} else if (((evolution_nl[geben][i][j-1] == geben) || (Spiel[0][i][j-1] == geben))&&(j != (n-2))){
							set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Spiel, 0, i, j+1, Fall_ball);
							set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Spiel, 0, i, j, 0);
						}
					}
					value_found = evet;
					// printf("	#-Block neu:	i=%u ,	j=%u \n ", i, j);	//test 
					break;
				}
			}
		}
		if (value_found == evet){
			break;
		}
	}
}

void ahead (Spielfeld Spiel, Spielfeld Field, unsigned int m, unsigned int count_freq, Special_Fields_Collector* sfc, Spielfeld Opague_o_field, unsigned int number_of_players, unsigned int geben, unsigned int gamemode_played){
	
	// printf("	ahead ok.1"); //test 
	
	for (unsigned int i=1; i<m-1; i+=1){
		for (unsigned int j=1; j<count_freq; j+=1){
			if (Spiel[0][i][j] == Wall){
				set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Spiel, 0, i, j, 0);
				set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Spiel, 0, i, j+1, Wall);
			}
		}
	}
}


void choose_heart (Spielfeld Field, unsigned int m, unsigned int n, unsigned int geben, Spielfeld Opague_o_field, Special_Fields_Collector* sfc, unsigned int number_of_players, unsigned int gamemode_played){
	unsigned int heart_i_wanted, heart_j_wanted, a, heart_i, heart_j;
	Spielfeld ground_temp;

	ground_temp = Spielfeld_Create (m, n, 0);
	heart_i_wanted = 0;
	heart_j_wanted = 0;
	a = 0;

	for (unsigned int i=1; i<m-1; i+=1){
		for (unsigned int j=1; j<n-1; j+=1){
			if (Field[0][i][j] == 11){
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

	heart_ground (heart_i, heart_j, Field, ground_temp, geben, Opague_o_field, sfc, number_of_players, gamemode_played);
	while ((heart_i_wanted == 0)||(heart_i_wanted >= m-1)||(heart_j_wanted >= n-1)||(heart_i_wanted == 0)) {
		printf(" Choose the next position of your heart-block: \n");
		printf("	\n");
		printf(" Zeile: \n Spalte: \n");

		letters_4 = get_unsigned_numeric_input_with_not_more_than_letters_4_for_splitting();
		heart_i_wanted = split_unsigned_numeric_input_with_letters_4 (letters_4, 0);
		heart_j_wanted = split_unsigned_numeric_input_with_letters_4 (letters_4, 1);

	}


	if (Field[0][heart_i_wanted][heart_j_wanted] == 11) {
		set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, heart_i_wanted, heart_j_wanted, 11);
	} else if (ground_temp[0][heart_i_wanted][heart_j_wanted] != 111) {
		printf("	You made a mistake, try again: \n");
		printf("\n");
		choose_heart (Field, m, n, geben, Opague_o_field, sfc, number_of_players, gamemode_played);
	} else if (ground_temp[0][heart_i_wanted][heart_j_wanted] == 111) {
		set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, heart_i, heart_j, 1);
		set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, heart_i_wanted, heart_j_wanted, 11);
	}

	Spielfeld_Destroy (ground_temp, m, 0);
}

void heart_ground (unsigned int i, unsigned int j, Spielfeld Field, Spielfeld ground_temp, unsigned int geben, Spielfeld Opague_o_field, Special_Fields_Collector* sfc, unsigned int number_of_players, unsigned int gamemode_played){
	if ((Field[0][i][j+1] == 1)&&(ground_temp[0][i][j+1] != 111)){
		set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, ground_temp, 0, i, j+1, 111);
		heart_ground (i, (j+1), Field, ground_temp, geben, Opague_o_field, sfc, number_of_players, gamemode_played);
	}
	if ((Field[0][i][j-1] == 1)&&(ground_temp[0][i][j-1] != 111)){
		set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, ground_temp, 0, i, j-1, 111);
		heart_ground (i, (j-1), Field, ground_temp, geben, Opague_o_field, sfc, number_of_players, gamemode_played);
	}
	if ((Field[0][i+1][j] == 1)&&(ground_temp[0][i+1][j] != 111)){
		set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, ground_temp, 0, i+1, j, 111);
		heart_ground ((i+1), j, Field, ground_temp, geben, Opague_o_field, sfc, number_of_players, gamemode_played);
	}
	if ((Field[0][i-1][j] == 1)&&(ground_temp[0][i-1][j] != 111)){
		set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, ground_temp, 0, i-1, j, 111);
		heart_ground ((i-1), j, Field, ground_temp, geben, Opague_o_field, sfc, number_of_players, gamemode_played);
	}
}

void choose_your_ability (unsigned int number_of_players, unsigned int* ability, Growth_Player* Growth_players, unsigned int geben) {

	unsigned int input;
	input = 0;

	for (unsigned int p=1; p<=number_of_players; p+=1) {
		printf(" \n");
		printf(" \n");
		while ((input == 0)||(input > 9)||((ability[input] != 0)&&(ability[input] != p))) {
			Square_color_interpretation (Growth_players, geben, number_of_players, p);
			printf("	Spieler %u, please choose your ability:	\n", p);
			set_terminal_color (cNORMAL);
			
			printf(" \n");
			if (ability[1] == 0) {
				printf("	Ultra light: 1 \n");
			}
			if (ability[2] == 0) {
				printf("	Light    : 2 \n");
			}
			if (ability[3] == 0) {
				printf("	Anti     : 3 \n");
			}
			if (ability[4] == 0) {
				printf("	Cornered   : 4 \n");
			}
			if (ability[5] == 0) {
				printf("	Inhibitor  : 5 \n");
			}
			if (ability[6] == 0) {
				printf("	Shield     : 6 \n");
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

			input = get_unsigned_numeric_input_with_not_more_than_1_letter ();

			if ((ability[input] == 0)&&(input != 0)&&(input <= 9)) {
				ability[input] = p;
				if ((input <= 4)||(input == 6)) {
					ability[0] += 1;
				}
			}
			printf(" \n");
			printf(" \n");
		}
	}
}

void survive_obstacles_generator (unsigned int gamemode_played, unsigned int rmv_round_counter, unsigned int round_counter_before, unsigned int* information_code, Spielfeld Field, unsigned int geben, Special_Fields_Collector* sfc, unsigned int number_of_players, Special_Fields Opague_o, Spielfeld Sf_permutations, unsigned int AOP, unsigned int* level, Growth_Player* Growth_players, unsigned int m, unsigned int n, unsigned int survive_different, unsigned int* ges, unsigned int* rmv_var_, unsigned int g, unsigned int rmv_use_number, unsigned int tac, unsigned int time_matters_ttt, Single_option_representives single_option_representives) {

	if ((gamemode_played == Survive)&&(rmv_round_counter == round_counter_before+1)) {

		//printf("in the obstacles-generator \n");	//test

		if ((rmv_round_counter % 5 == 0)&&(information_code[3] >= 1)) {	//delete Waves
			for (unsigned int i=1; i<m-1; i+=1){
				for (unsigned int j=1; j<n-1; j+=1){
					if (Field[0][i][j] == Waves) {
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, sfc, number_of_players, Field, 0, i, j, 0);
					}
				}
			}
		}

		Opague_show_controll (level, Field, Opague_o, m, n, geben, AOP, sfc, number_of_players, gamemode_played, single_option_representives.invisible, Sf_permutations, information_code, Growth_players);
		
		for (unsigned int i=1; i<m-1; i+=1){
			for (unsigned int j=1; j<n-1; j+=1){

				if (information_code[2] >= 1) {	//Bombs
					if (Field[0][i][j] == Bomb_4) {
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, sfc, number_of_players, Field, 0, i, j, Bomb_3);
					} else if (Field[0][i][j] == Bomb_3) {
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, sfc, number_of_players, Field, 0, i, j, Bomb_2);
					} else if (Field[0][i][j] == Bomb_2) {
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, sfc, number_of_players, Field, 0, i, j, Bomb_1);
					} else if (Field[0][i][j] == Bomb_1) {
						for (unsigned int h=i-1; h<=i+1; h+=1){
							for (unsigned int k=j-1; k<=j+1; k+=1){
								if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))&&(Field[0][h][k] != 0)){
									set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, sfc, number_of_players, Field, 0, h, k, 0);
								}
							}
						}
					}
				}
				if (information_code[3] >= 1) {	//Waves
					if (((Field[0][i-1][j] == Waves)&&(Field[0][i+1][j] != Waves)&&(Field[0][i][j+1] != Waves)&&(Field[0][i][j-1] != Waves))||((Field[0][i-1][j] != Waves)&&(Field[0][i+1][j] == Waves)&&(Field[0][i][j+1] != Waves)&&(Field[0][i][j-1] != Waves))||((Field[0][i-1][j] != Waves)&&(Field[0][i+1][j] != Waves)&&(Field[0][i][j+1] == Waves)&&(Field[0][i][j-1] != Waves))||((Field[0][i-1][j] != Waves)&&(Field[0][i+1][j] != Waves)&&(Field[0][i][j+1] != Waves)&&(Field[0][i][j-1] == Waves))) {
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, sfc, number_of_players, Field, 0, i, j, Waves_new);
					}
				}
			}
		}

		for (unsigned int i=1; i<m-1; i+=1){
			for (unsigned int j=1; j<n-1; j+=1){
				if (Field[0][i][j] == Waves) {
					set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, sfc, number_of_players, Field, 0, i, j, 0);
				}
			}
		}
		for (unsigned int i=1; i<m-1; i+=1){
			for (unsigned int j=1; j<n-1; j+=1){
				if (Field[0][i][j] == Waves_new) {
					set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, sfc, number_of_players, Field, 0, i, j, Waves);
				}
			}
		}

		if ((rmv_round_counter % 5 == 0)&&(information_code[1] >= 1)) {	//Traps amount per round
			information_code[1] += 1;
		}
		if ((rmv_round_counter % 10 == 0)&&(information_code[2] >= 1)) {	//Bombs amount per round
			information_code[2] += 1;
		}
		if ((rmv_round_counter % 15 == 0)&&(information_code[3] >= 1)) {	//Waves amount per 5 rounds
			information_code[3] += 1;
		}

		if ((rmv_round_counter % 5 == 1)&&(information_code[3] >= 1)) {	//new Waves
			for (unsigned int p=1; p<=information_code[3]; p+=1) {
				unsigned int i;
				unsigned int j;
				i = ((survive_different%10)+ges[1]+ges[3]+ges[5]+ges[7]+ges[9]+rmv_var_[2]+rmv_var_[4]+rmv_var_[6]+rmv_var_[8]+Growth_players[1].color+Growth_players[3].color+Growth_players[5].color+Growth_players[7].color+Growth_players[9].color+7*p+g+2*rmv_use_number+tac)%(m-2) + 1;
				j = ((survive_different%6)+ges[2]+ges[4]+ges[6]+ges[8]+rmv_var_[1]+rmv_var_[3]+rmv_var_[5]+rmv_var_[7]+rmv_var_[9]+Growth_players[0].color+Growth_players[2].color+Growth_players[4].color+Growth_players[6].color+Growth_players[8].color+11*p+g+3*rmv_use_number+time_matters_ttt)%(n-2) + 1;
				set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, sfc, number_of_players, Field, 0, i, j, Waves);
			}
		}
		if (information_code[1] >= 1) {	//new Traps
			for (unsigned int p=1; p<=information_code[1]; p+=1) {
				unsigned int i;
				unsigned int j;
				i = ((survive_different%5)+ges[1]+ges[3]+ges[5]+ges[7]+ges[9]+rmv_var_[2]+rmv_var_[4]+rmv_var_[6]+rmv_var_[8]+Growth_players[1].color+Growth_players[3].color+Growth_players[5].color+Growth_players[7].color+Growth_players[9].color+3*p+g+rmv_use_number+tac)%(m-2) + 1;
				j = ((survive_different%12)+ges[2]+ges[4]+ges[6]+ges[8]+rmv_var_[1]+rmv_var_[3]+rmv_var_[5]+rmv_var_[7]+rmv_var_[9]+Growth_players[0].color+Growth_players[2].color+Growth_players[4].color+Growth_players[6].color+Growth_players[8].color+6*p+g+2*rmv_use_number+time_matters_ttt)%(n-2) + 1;
				set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, sfc, number_of_players, Field, 0, i, j, Traps);
			}
		}
		if (information_code[2] >= 1) {	//new Bombs
			for (unsigned int p=1; p<=information_code[2]; p+=1) {
				unsigned int i;
				unsigned int j;
				i = ((survive_different%15)+ges[1]+ges[3]+ges[5]+ges[7]+ges[9]+rmv_var_[2]+rmv_var_[4]+rmv_var_[6]+rmv_var_[8]+Growth_players[1].color+Growth_players[3].color+Growth_players[5].color+Growth_players[7].color+Growth_players[9].color+8*p+g+3*rmv_use_number+tac)%(m-2) + 1;
				j = ((survive_different%4)+ges[2]+ges[4]+ges[6]+ges[8]+rmv_var_[1]+rmv_var_[3]+rmv_var_[5]+rmv_var_[7]+rmv_var_[9]+Growth_players[0].color+Growth_players[2].color+Growth_players[4].color+Growth_players[6].color+Growth_players[8].color+5*p+g+rmv_use_number+time_matters_ttt)%(n-2) + 1;
				set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, sfc, number_of_players, Field, 0, i, j, Bomb_4);
			}
		}
	}
}



void Quidditch_Klatscher_players_actions (Spielfeld Field, unsigned int geben, Spielfeld Opague_o_field, unsigned int gamemode_played, Special_Fields_Collector* sfc, unsigned int number_of_players, unsigned int m, unsigned int n, unsigned int* g, Moveable_objects_condition* Moc_Schnatz, Moveable_objects_condition* Moc_Quaffel, Quidditch_setup* Qs, Special_Fields Opague_o, unsigned int* level, Spielfeld Sf_permutations, unsigned int* information_code, Growth_Player* Growth_players, Single_option_representives single_option_representives, unsigned int AOP) {
	
	#ifdef Quidditch_mistake_search
	printf("	Quidditch_Klatscher_players_actions-beginning.ok \n");	//test
	#endif
	
	unsigned int Treiber, turns, already_moved_indicator[2];
	
	Treiber = 0;
	turns = 0;
	for (unsigned int p=0; p<=1; p++) {
		 already_moved_indicator[p] = 0;
	}
	
	Opague_show_controll (level, Field, Opague_o, m, n, geben, AOP, sfc, number_of_players, gamemode_played, single_option_representives.invisible, Sf_permutations, information_code, Growth_players);
	
	if (geben == 1) {
		Treiber = Treiber_1;
	} else if (geben == 2) {
		Treiber = Treiber_2;
	}
	
	turns = 2;
	while (turns >= 2) {	//Only 0 or 1 possible
		Square_color_interpretation (Growth_players, geben, number_of_players, geben);
		printf("	Do you want to move one of your Treiber ? \n");
		set_terminal_color (cNORMAL);
		printf("	0 : no\n	1 : yes\n");
		turns = get_unsigned_numeric_input_with_not_more_than_1_letter ();
	}
	
	for (unsigned int p=1; p<=turns; p++) {
		Move_of_a_Quidditch_player (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Treiber, Qs->Qta[geben].Treiber_fly_distance, m, n, g, Moc_Schnatz, Moc_Quaffel, Qs, already_moved_indicator);
	}
	
	#ifdef Quidditch_mistake_search
	printf("	Quidditch_Klatscher_players_actions-ending.ok \n");	//test
	#endif
	
}

void Quidditch_Quaffel_players_actions (Spielfeld Field, unsigned int geben, Spielfeld Opague_o_field, unsigned int gamemode_played, Special_Fields_Collector* sfc, unsigned int number_of_players, unsigned int m, unsigned int n, unsigned int* g, Moveable_objects_condition* Moc_Schnatz, Moveable_objects_condition* Moc_Quaffel, Quidditch_setup* Qs, Special_Fields Opague_o, unsigned int* level, Spielfeld Sf_permutations, unsigned int* information_code, Growth_Player* Growth_players, unsigned int* ges, unsigned int limits_at_all, Single_option_representives single_option_representives, unsigned int AOP) {
	
	#ifdef Quidditch_mistake_search
	printf("	Quidditch_Quaffel_players_actions-beginning.ok \n");	//test
	#endif
	
	unsigned int turns, already_moved_indicator[2];
	
	turns = 0;
	for (unsigned int p=0; p<=1; p++) {
		already_moved_indicator[p] = 0;	//the position of an already moved player (Jäger/Hüter);
	}
	
	Opague_show_controll (level, Field, Opague_o, m, n, geben, AOP, sfc, number_of_players, gamemode_played, single_option_representives.invisible, Sf_permutations, information_code, Growth_players);
	
	turns = 3;
	while (turns >= 3) {	//Only 0 or 1 or 2 possible
		Square_color_interpretation (Growth_players, geben, number_of_players, geben);
		printf("	How many actions do you want to make according to the Quaffel ?		(max.: 2)\n");
		set_terminal_color (cNORMAL);
		turns = get_unsigned_numeric_input_with_not_more_than_1_letter ();
	}
	
	unsigned int action_choice, action_choice_limit, Team_member;
	action_choice = 0;
	action_choice_limit = 0;
	Team_member = 0;
	
	action_choice_limit = 3;
	for (unsigned int p=1; p<=turns; p++) {
		
		action_choice = action_choice_limit;
		while (action_choice >= action_choice_limit) {	//Only 0 or 1 or 2 possible at the first time
			Square_color_interpretation (Growth_players, geben, number_of_players, geben);
			printf("	What do you want to do ? \n");
			set_terminal_color (cNORMAL);
			printf("	0: Throw Quaffel \n");
			printf("	1: Move Jaeger \n");	//Why there was a limit of moving Jaeger/Hueter ?
			if (action_choice_limit != 2) {
				printf("	2: Move Hueter \n");
			}
			
			action_choice = get_unsigned_numeric_input_with_not_more_than_1_letter ();
		}
		
		if (action_choice == 0) {
			Quidditch_Quaffel_Throw (Field, geben, Opague_o.field, gamemode_played, sfc, number_of_players, m, n, Moc_Quaffel, Qs, ges, limits_at_all, &p);
		} else if (action_choice == 1) {
			
			if (geben == 1) {
				Team_member = Jaeger_1;
			} else if (geben == 2) {
				Team_member = Jaeger_2;
			}
			
			Move_of_a_Quidditch_player (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Team_member, Qs->Qta[geben].Jaeger_fly_distance, m, n, g, Moc_Schnatz, Moc_Quaffel, Qs, already_moved_indicator);
			
		} else if (action_choice == 2) {
			
			if (geben == 1) {
				Team_member = Hueter_1;
			} else if (geben == 2) {
				Team_member = Hueter_2;
			}
			
			action_choice_limit = 2;
			
			Move_of_a_Quidditch_player (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Team_member, Qs->Qta[geben].Hueter_fly_distance, m, n, g, Moc_Schnatz, Moc_Quaffel, Qs, already_moved_indicator);
		}
	}
	
	for (unsigned int p=0; p<=1; p++) {
		already_moved_indicator[p] = 0;	//the position of an already moved player (Jäger/Hüter);
	}
	
	#ifdef Quidditch_mistake_search
	printf("	Quidditch_Quaffel_players_actions-ending.ok \n");	//test
	#endif
	
}

void Quidditch_Schnatz_player_actions (Spielfeld Field, unsigned int geben, Spielfeld Opague_o_field, unsigned int gamemode_played, Special_Fields_Collector* sfc, unsigned int number_of_players, unsigned int m, unsigned int n, unsigned int* g, Moveable_objects_condition* Moc_Schnatz, Moveable_objects_condition* Moc_Quaffel, Quidditch_setup* Qs, Special_Fields Opague_o, unsigned int* level, Spielfeld Sf_permutations, unsigned int* information_code, Growth_Player* Growth_players, Single_option_representives single_option_representives, unsigned int AOP) {
	
	#ifdef Quidditch_mistake_search
	printf("	Quidditch_Schnatz_player_actions-beginning.ok \n");	//test
	#endif
	
	unsigned int Sucher, turns, already_moved_indicator[2];
	
	Sucher = undefined;
	turns = undefined;
	for (unsigned int p=0; p<=1; p++) {
		 already_moved_indicator[p] = 0;
	}
	
	Opague_show_controll (level, Field, Opague_o, m, n, geben, AOP, sfc, number_of_players, gamemode_played, single_option_representives.invisible, Sf_permutations, information_code, Growth_players);
	
	if (geben == 1) {
		Sucher = Sucher_1;
	} else if (geben == 2) {
		Sucher = Sucher_2;
	}
	
	turns = 2;
	while (turns > 1) {	//Only 0 or 1 possible
		Square_color_interpretation (Growth_players, geben, number_of_players, geben);
		printf("	Do you want to move your Sucher ? \n");
		set_terminal_color (cNORMAL);
		printf("	0 : no\n	1 : yes\n");
		turns = get_unsigned_numeric_input_with_not_more_than_1_letter ();
	}
	
	for (unsigned int p=1; p<=turns; p++) {
		Move_of_a_Quidditch_player (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Sucher, Qs->Qta[geben].Sucher_fly_distance, m, n, g, Moc_Schnatz, Moc_Quaffel, Qs, already_moved_indicator);
	}
	
	#ifdef Quidditch_mistake_search
	printf("	Quidditch_Schnatz_player_actions-ending.ok \n");	//test
	#endif
	
}

void Quidditch_Klatscher_movements (Spielfeld Field, unsigned int geben, Spielfeld Opague_o_field, unsigned int gamemode_played, Special_Fields_Collector* sfc, unsigned int number_of_players, unsigned int m, unsigned int n, Moveable_objects_condition* Moc_Klatscher, Quidditch_setup* Qs) {
	
	#ifdef Quidditch_mistake_search
	printf("	Quidditch_Klatscher_movements-beginning.ok \n");	//test
	#endif
	
	for (unsigned int p=0; p<=1; p++) {
		
		#ifdef Quidditch_mistake_search
		printf("	Klatscher[%u]: [%u][%u] \n", p, Moc_Klatscher[p].i, Moc_Klatscher[p].j);	//test
		#endif
	
		Quidditch_Klatscher_target_search (Field, m, n, Moc_Klatscher, p);	//fill in wanted
		
		Moc_Klatscher[p].remaining_squares_to_move = Qs->Qoa->Klatscher_fly_distance;
		
		Quidditch_move_of_Klatscher (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, m, n, Moc_Klatscher, p, Qs);
		
		Moc_Klatscher[p].wanted_i = 0;
		Moc_Klatscher[p].wanted_j = 0;
	}
	
	#ifdef Quidditch_mistake_search
	printf("	Quidditch_Klatscher_movements-ending.ok \n");	//test
	#endif
	
}

void Quidditch_Klatscher_target_search (Spielfeld Field, unsigned int m, unsigned int n, Moveable_objects_condition* Moc_Klatscher, unsigned int p) {	//fix it(?), go on

	#ifdef Quidditch_mistake_search
	printf("	Quidditch_Klatscher_target_search-beginning.ok \n");	//test
	#endif
	
	unsigned int break_up, q, unutma_direction;
	
	break_up = hayir;
	q = 1;
	unutma_direction = hayir;
	
	if (Moc_Klatscher[p].directed == 0) {
		Moc_Klatscher[p].directed = Zufall (1, 8);
		unutma_direction = evet;
	}
	
	#ifdef Quidditch_mistake_search
	printf("	Klatscher[%u]: [%u][%u] \n", p, Moc_Klatscher[p].i, Moc_Klatscher[p].j);	//test
	printf("	Klatscher[%u].directed: %u \n", p, Moc_Klatscher[p].directed);	//test
	#endif
	
	while ((Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] != Jaeger_1)&&(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] != Jaeger_2)&&(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] != Hueter_1)&&(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] != Hueter_2)&&(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] != Treiber_1)&&(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] != Treiber_2)&&(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] != Sucher_1)&&(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] != Sucher_2)) {
		
		if (Moc_Klatscher[p].directed == 1) {
			for (unsigned int h=0; h<=2*q; h++) {
				for (unsigned int k=2*q+1; k>0; k--) {
					if ((Moc_Klatscher[p].i +h -q != 0)&&(Moc_Klatscher[p].i +h -q <= m-2)&&(Moc_Klatscher[p].j +k -q-1 != 0)&&(Moc_Klatscher[p].j +k -q-1 <= n-2)) {
							Moc_Klatscher[p].wanted_i = Moc_Klatscher[p].i +h -q;
							Moc_Klatscher[p].wanted_j = Moc_Klatscher[p].j +k -q-1;
							if ((Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Jaeger_1)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Jaeger_2)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Hueter_1)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Hueter_2)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Treiber_1)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Treiber_2)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Sucher_1)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Sucher_2)) {
								break_up = evet;
								break;
							}
					}
				}
				if (break_up == evet) {
					break;
				}
			}
		} else if (Moc_Klatscher[p].directed == 2) {
			for (unsigned int k=2*q+1; k>0; k--) {
				for (unsigned int h=0; h<=2*q; h++) {
					if ((Moc_Klatscher[p].i +h -q != 0)&&(Moc_Klatscher[p].i +h -q <= m-2)&&(Moc_Klatscher[p].j +k -q-1 != 0)&&(Moc_Klatscher[p].j +k -q-1 <= n-2)) {
							Moc_Klatscher[p].wanted_i = Moc_Klatscher[p].i +h -q;
							Moc_Klatscher[p].wanted_j = Moc_Klatscher[p].j +k -q-1;
							if ((Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Jaeger_1)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Jaeger_2)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Hueter_1)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Hueter_2)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Treiber_1)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Treiber_2)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Sucher_1)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Sucher_2)) {
								break_up = evet;
								break;
							}
					}
				}
				if (break_up == evet) {
					break;
				}
			}
		} else if (Moc_Klatscher[p].directed == 3) {
			for (unsigned int k=2*q+1; k>0; k--) {
				for (unsigned int h=2*q+1; h>0; h--) {
					if ((Moc_Klatscher[p].i +h -q-1 != 0)&&(Moc_Klatscher[p].i +h -q-1 <= m-2)&&(Moc_Klatscher[p].j +k -q-1 != 0)&&(Moc_Klatscher[p].j +k -q-1 <= n-2)) {
							Moc_Klatscher[p].wanted_i = Moc_Klatscher[p].i +h -q-1;
							Moc_Klatscher[p].wanted_j = Moc_Klatscher[p].j +k -q-1;
							if ((Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Jaeger_1)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Jaeger_2)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Hueter_1)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Hueter_2)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Treiber_1)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Treiber_2)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Sucher_1)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Sucher_2)) {
								break_up = evet;
								break;
							}
					}
				}
				if (break_up == evet) {
					break;
				}
			}
		} else if (Moc_Klatscher[p].directed == 4) {
			for (unsigned int h=2*q+1; h>0; h--) {
				for (unsigned int k=2*q+1; k>0; k--) {
					if ((Moc_Klatscher[p].i +h -q-1 != 0)&&(Moc_Klatscher[p].i +h -q-1 <= m-2)&&(Moc_Klatscher[p].j +k -q-1 != 0)&&(Moc_Klatscher[p].j +k -q-1 <= n-2)) {
							Moc_Klatscher[p].wanted_i = Moc_Klatscher[p].i +h -q-1;
							Moc_Klatscher[p].wanted_j = Moc_Klatscher[p].j +k -q-1;
							if ((Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Jaeger_1)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Jaeger_2)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Hueter_1)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Hueter_2)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Treiber_1)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Treiber_2)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Sucher_1)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Sucher_2)) {
								break_up = evet;
								break;
							}
					}
				}
				if (break_up == evet) {
					break;
				}
			}
		} else if (Moc_Klatscher[p].directed == 5) {
			for (unsigned int h=2*q+1; h>0; h--) {
				for (unsigned int k=0; k<=2*q; k++) {
					if ((Moc_Klatscher[p].i +h -q-1 != 0)&&(Moc_Klatscher[p].i +h -q-1 <= m-2)&&(Moc_Klatscher[p].j +k -q != 0)&&(Moc_Klatscher[p].j +k -q <= n-2)) {
							Moc_Klatscher[p].wanted_i = Moc_Klatscher[p].i +h -q-1;
							Moc_Klatscher[p].wanted_j = Moc_Klatscher[p].j +k -q;
							if ((Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Jaeger_1)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Jaeger_2)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Hueter_1)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Hueter_2)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Treiber_1)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Treiber_2)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Sucher_1)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Sucher_2)) {
								break_up = evet;
								break;
							}
					}
				}
				if (break_up == evet) {
					break;
				}
			}
		} else if (Moc_Klatscher[p].directed == 6) {
			for (unsigned int k=0; k<=2*q; k++) {
				for (unsigned int h=2*q+1; h>0; h--) {
					if ((Moc_Klatscher[p].i +h -q-1 != 0)&&(Moc_Klatscher[p].i +h -q-1 <= m-2)&&(Moc_Klatscher[p].j +k -q != 0)&&(Moc_Klatscher[p].j +k -q <= n-2)) {
							Moc_Klatscher[p].wanted_i = Moc_Klatscher[p].i +h -q-1;
							Moc_Klatscher[p].wanted_j = Moc_Klatscher[p].j +k -q;
							if ((Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Jaeger_1)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Jaeger_2)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Hueter_1)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Hueter_2)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Treiber_1)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Treiber_2)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Sucher_1)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Sucher_2)) {
								break_up = evet;
								break;
							}
					}
				}
				if (break_up == evet) {
					break;
				}
			}
		} else if (Moc_Klatscher[p].directed == 7) {
			for (unsigned int k=0; k<=2*q; k++) {
				for (unsigned int h=0; h<=2*q; h++) {
					if ((Moc_Klatscher[p].i +h -q != 0)&&(Moc_Klatscher[p].i +h -q <= m-2)&&(Moc_Klatscher[p].j +k -q != 0)&&(Moc_Klatscher[p].j +k -q <= n-2)) {
							Moc_Klatscher[p].wanted_i = Moc_Klatscher[p].i +h -q;
							Moc_Klatscher[p].wanted_j = Moc_Klatscher[p].j +k -q;
							if ((Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Jaeger_1)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Jaeger_2)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Hueter_1)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Hueter_2)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Treiber_1)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Treiber_2)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Sucher_1)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Sucher_2)) {
								break_up = evet;
								break;
							}
					}
				}
				if (break_up == evet) {
					break;
				}
			}
		} else if (Moc_Klatscher[p].directed == 8) {
			for (unsigned int h=0; h<=2*q; h++) {
				for (unsigned int k=0; k<=2*q; k++) {
					if ((Moc_Klatscher[p].i +h -q != 0)&&(Moc_Klatscher[p].i +h -q <= m-2)&&(Moc_Klatscher[p].j +k -q != 0)&&(Moc_Klatscher[p].j +k -q <= n-2)) {
							Moc_Klatscher[p].wanted_i = Moc_Klatscher[p].i +h -q;
							Moc_Klatscher[p].wanted_j = Moc_Klatscher[p].j +k -q;
							if ((Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Jaeger_1)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Jaeger_2)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Hueter_1)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Hueter_2)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Treiber_1)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Treiber_2)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Sucher_1)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Sucher_2)) {
								break_up = evet;
								break;
							}
					}
				}
				if (break_up == evet) {
					break;
				}
			}
		}
		
		q += 1;
	}
	
	if (unutma_direction == evet) {
		Moc_Klatscher[p].directed = 0;
	}
	
	#ifdef Quidditch_mistake_search
	printf("	Klatscher-Target: [%u][%u] \n", Moc_Klatscher[p].wanted_i, Moc_Klatscher[p].wanted_j);	//test
	#endif
	
	#ifdef Quidditch_mistake_search
	printf("	Quidditch_Klatscher_target_search-ending.ok \n");	//test
	#endif
	
}

void Quidditch_move_of_Klatscher (Spielfeld Field, unsigned int geben, Spielfeld Opague_o_field, unsigned int gamemode_played, Special_Fields_Collector* sfc, unsigned int number_of_players, unsigned int m, unsigned int n, Moveable_objects_condition* Moc_Klatscher, unsigned int p, Quidditch_setup* Qs) {
	
	#ifdef Quidditch_mistake_search
	printf("	Quidditch_move_of_Klatscher-beginning.ok \n");	//test
	#endif
	
	int i_difference, j_difference;
	
	i_difference = 0;
	j_difference = 0;
	
	i_difference = Moc_Klatscher[p].wanted_i - Moc_Klatscher[p].i;
	j_difference = Moc_Klatscher[p].wanted_j - Moc_Klatscher[p].j;
	
	#ifdef Quidditch_mistake_search
	printf("	Klatscher[%u]: [%u][%u] \n", p, Moc_Klatscher[p].i, Moc_Klatscher[p].j);	//test
	#endif
	
	Quidditch_Klatscher_steps (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, m, n, Moc_Klatscher, p, i_difference, j_difference, Qs);
	
	#ifdef Quidditch_mistake_search
	printf("	Quidditch_move_of_Klatscher-ending.ok \n");	//test
	#endif
	
}

void Quidditch_Klatscher_steps (Spielfeld Field, unsigned int geben, Spielfeld Opague_o_field, unsigned int gamemode_played, Special_Fields_Collector* sfc, unsigned int number_of_players, unsigned int m, unsigned int n, Moveable_objects_condition* Moc_Klatscher, unsigned int p, int i_difference, int j_difference, Quidditch_setup* Qs) {
	
	#ifdef Quidditch_mistake_search
	printf("	Quidditch_Klatscher_steps-beginning.ok \n");	//test
	#endif
	
	unsigned int unutma_i, unutma_j;
	
	unutma_i = Moc_Klatscher[p].i;
	unutma_j = Moc_Klatscher[p].j;
	
	if (Field[0][unutma_i][unutma_j] == Klatscher) {
		set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, unutma_i, unutma_j, 0);
	}
	//812
	//703
	//654
	//this is the directed-table
	
	while ((Moc_Klatscher[p].remaining_squares_to_move != 0)&&((Moc_Klatscher[p].i != Moc_Klatscher[p].wanted_i)||(Moc_Klatscher[p].j != Moc_Klatscher[p].wanted_j))) {	//the way of the Klatscher
		
		#ifdef Quidditch_mistake_search
		printf("	Moc_Klatscher[%u].remaining_squares_to_move = %u \n", p, Moc_Klatscher[p].remaining_squares_to_move);	//test
		#endif
		
		if (Moc_Klatscher[p].directed == 0) {
			if (i_difference > 0) {
				if (j_difference > 0) {
					Moc_Klatscher[p].directed = 4;
				} else if (j_difference < 0) {
					Moc_Klatscher[p].directed = 6;
				} else if (j_difference == 0) {
					Moc_Klatscher[p].directed = 5;
				}
				Moc_Klatscher[p].remaining_squares_to_move -= 1;
				
			} else if (i_difference < 0) {
				if (j_difference > 0) {
					Moc_Klatscher[p].directed = 2;
				} else if (j_difference < 0) {
					Moc_Klatscher[p].directed = 8;
				} else if (j_difference == 0) {
					Moc_Klatscher[p].directed = 1;
				}
				Moc_Klatscher[p].remaining_squares_to_move -= 1;
				
			} else if (i_difference == 0) {
				if (j_difference > 0) {
					Moc_Klatscher[p].directed = 3;
				} else if (j_difference < 0) {
					Moc_Klatscher[p].directed = 7;
				}
				Moc_Klatscher[p].remaining_squares_to_move -= 1;
				
			}
		}
		
		if (i_difference > 0) {
			if (j_difference > 0) {
				if (Moc_Klatscher[p].directed == 4) {
					Moc_Klatscher[p].i += 1;
					i_difference -= 1;
					Moc_Klatscher[p].j += 1;
					j_difference -= 1;
					Moc_Klatscher[p].remaining_squares_to_move -= 1;
					
				} else if ((Moc_Klatscher[p].directed == 3)&&(j_difference > i_difference)) {
					Moc_Klatscher[p].j += 1;
					j_difference -= 1;
					Moc_Klatscher[p].remaining_squares_to_move -= 1;
					
				} else if ((Moc_Klatscher[p].directed == 5)&&(i_difference > j_difference)) {
					Moc_Klatscher[p].i += 1;
					i_difference -= 1;
					Moc_Klatscher[p].remaining_squares_to_move -= 1;
					
				} else {
					Moc_Klatscher[p].remaining_squares_to_move -= 1;
					if ((Moc_Klatscher[p].remaining_squares_to_move != 0)&&(Moc_Klatscher[p].directed == 8)) {
						Moc_Klatscher[p].remaining_squares_to_move -= 1;
					}
					Moc_Klatscher[p].directed = 4;
				}
			} else if (j_difference < 0) {
				if (Moc_Klatscher[p].directed == 6) {
					Moc_Klatscher[p].i += 1;
					i_difference -= 1;
					Moc_Klatscher[p].j -= 1;
					j_difference += 1;
					Moc_Klatscher[p].remaining_squares_to_move -= 1;
					
				} else if ((Moc_Klatscher[p].directed == 7)&&(abs(j_difference) > i_difference)) {
					Moc_Klatscher[p].j -= 1;
					j_difference += 1;
					Moc_Klatscher[p].remaining_squares_to_move -= 1;
					
				} else if ((Moc_Klatscher[p].directed == 5)&&(i_difference > abs(j_difference))) {
					Moc_Klatscher[p].i += 1;
					i_difference -= 1;
					Moc_Klatscher[p].remaining_squares_to_move -= 1;
					
				} else {
					Moc_Klatscher[p].remaining_squares_to_move -= 1;
					if ((Moc_Klatscher[p].remaining_squares_to_move != 0)&&(Moc_Klatscher[p].directed == 2)) {
						Moc_Klatscher[p].remaining_squares_to_move -= 1;
					}
					Moc_Klatscher[p].directed = 6;
				}
			} else if (j_difference == 0) {
				if (Moc_Klatscher[p].directed == 5) {
					Moc_Klatscher[p].i += 1;
					i_difference -= 1;
					Moc_Klatscher[p].remaining_squares_to_move -= 1;
					
				} else {
					Moc_Klatscher[p].remaining_squares_to_move -= 1;
					if ((Moc_Klatscher[p].remaining_squares_to_move != 0)&&(Moc_Klatscher[p].directed == 1)) {
						Moc_Klatscher[p].remaining_squares_to_move -= 1;
					}
					Moc_Klatscher[p].directed = 5;
				}
			}
		} else if (i_difference < 0) {
			if (j_difference > 0) {
				if (Moc_Klatscher[p].directed == 2) {
					Moc_Klatscher[p].i -= 1;
					i_difference += 1;
					Moc_Klatscher[p].j += 1;
					j_difference -= 1;
					Moc_Klatscher[p].remaining_squares_to_move -= 1;
					
				} else if ((Moc_Klatscher[p].directed == 3)&&(abs(j_difference) > abs(i_difference))) {
					Moc_Klatscher[p].j += 1;
					j_difference -= 1;
					Moc_Klatscher[p].remaining_squares_to_move -= 1;
					
				} else if ((Moc_Klatscher[p].directed == 1)&&(abs(i_difference) > abs(j_difference))) {
					Moc_Klatscher[p].i -= 1;
					i_difference += 1;
					Moc_Klatscher[p].remaining_squares_to_move -= 1;
					
				} else {
					Moc_Klatscher[p].remaining_squares_to_move -= 1;
					if ((Moc_Klatscher[p].remaining_squares_to_move != 0)&&(Moc_Klatscher[p].directed == 6)) {
						Moc_Klatscher[p].remaining_squares_to_move -= 1;
					}
					Moc_Klatscher[p].directed = 2;
				}
			} else if (j_difference < 0) {
				if (Moc_Klatscher[p].directed == 8) {
					Moc_Klatscher[p].i -= 1;
					i_difference += 1;
					Moc_Klatscher[p].j -= 1;
					j_difference += 1;
					Moc_Klatscher[p].remaining_squares_to_move -= 1;
					
				} else if ((Moc_Klatscher[p].directed == 7)&&(abs(j_difference) > abs(i_difference))) {
					Moc_Klatscher[p].j -= 1;
					j_difference += 1;
					Moc_Klatscher[p].remaining_squares_to_move -= 1;
					
				} else if ((Moc_Klatscher[p].directed == 1)&&(abs(i_difference) > abs(j_difference))) {
					Moc_Klatscher[p].i -= 1;
					i_difference += 1;
					Moc_Klatscher[p].remaining_squares_to_move -= 1;
					
				} else {
					Moc_Klatscher[p].remaining_squares_to_move -= 1;
					if ((Moc_Klatscher[p].remaining_squares_to_move != 0)&&(Moc_Klatscher[p].directed == 4)) {
						Moc_Klatscher[p].remaining_squares_to_move -= 1;
					}
					Moc_Klatscher[p].directed = 8;
				}
			} else if (j_difference == 0) {
				if (Moc_Klatscher[p].directed == 1) {
					Moc_Klatscher[p].i -= 1;
					i_difference += 1;
					Moc_Klatscher[p].remaining_squares_to_move -= 1;
					
				} else {
					Moc_Klatscher[p].remaining_squares_to_move -= 1;
					if ((Moc_Klatscher[p].remaining_squares_to_move != 0)&&(Moc_Klatscher[p].directed == 5)) {
						Moc_Klatscher[p].remaining_squares_to_move -= 1;
					}
					Moc_Klatscher[p].directed = 1;
				}
			}
		} else if (i_difference == 0) {
			if (j_difference > 0) {
				if (Moc_Klatscher[p].directed == 3) {
					Moc_Klatscher[p].j += 1;
					j_difference -= 1;
					Moc_Klatscher[p].remaining_squares_to_move -= 1;
					
				} else {
					Moc_Klatscher[p].remaining_squares_to_move -= 1;
					if ((Moc_Klatscher[p].remaining_squares_to_move != 0)&&(Moc_Klatscher[p].directed == 7)) {
						Moc_Klatscher[p].remaining_squares_to_move -= 1;
					}
					Moc_Klatscher[p].directed = 3;
				}
			} else if (j_difference < 0) {
				if (Moc_Klatscher[p].directed == 7) {
					Moc_Klatscher[p].j -= 1;
					j_difference += 1;
					Moc_Klatscher[p].remaining_squares_to_move -= 1;
					
				} else {
					Moc_Klatscher[p].remaining_squares_to_move -= 1;
					if ((Moc_Klatscher[p].remaining_squares_to_move != 0)&&(Moc_Klatscher[p].directed == 3)) {
						Moc_Klatscher[p].remaining_squares_to_move -= 1;
					}
					Moc_Klatscher[p].directed = 7;
				}
			}
		}
	}	//no effects on not-target objects on the way (-> Klatscher-hit)
	
	Moc_Klatscher[p].remaining_squares_to_move = 0;	//its work is done.
	
	if ((Field[0][Moc_Klatscher[p].i][Moc_Klatscher[p].j] != Torring_1)&&(Field[0][Moc_Klatscher[p].i][Moc_Klatscher[p].j] != Torring_2)) {
		if ((Field[0][Moc_Klatscher[p].i][Moc_Klatscher[p].j] == Jaeger_1)||(Field[0][Moc_Klatscher[p].i][Moc_Klatscher[p].j] == Hueter_1)||(Field[0][Moc_Klatscher[p].i][Moc_Klatscher[p].j] == Sucher_1)) {
			Klatscher_hits_target (2, Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, m, n,  Moc_Klatscher, p, Qs);
		} else if ((Field[0][Moc_Klatscher[p].i][Moc_Klatscher[p].j] == Jaeger_2)||(Field[0][Moc_Klatscher[p].i][Moc_Klatscher[p].j] == Hueter_2)||(Field[0][Moc_Klatscher[p].i][Moc_Klatscher[p].j] == Sucher_2)) {
			Klatscher_hits_target (1, Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, m, n,  Moc_Klatscher, p, Qs);
		} else if (Field[0][Moc_Klatscher[p].i][Moc_Klatscher[p].j] == Treiber_1) {
			Treiber_hits_Klatscher (1, Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, m, n, Moc_Klatscher, p, Qs);
		} else if (Field[0][Moc_Klatscher[p].i][Moc_Klatscher[p].j] == Treiber_2) {
			Treiber_hits_Klatscher (2, Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, m, n, Moc_Klatscher, p, Qs);
		} else {
			if ((unutma_i != Moc_Klatscher[p].i)||(unutma_j != Moc_Klatscher[p].j)) {
				while ((Field[0][unutma_i][unutma_j] > number_of_players)||((unutma_i == Moc_Klatscher[p].i)&&(unutma_j == Moc_Klatscher[p].j))) {
					unutma_i = Zufall (1, m-2);
					unutma_j = Zufall (1, n-2);
				}
				set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, unutma_i, unutma_j, Field[0][Moc_Klatscher[p].i][Moc_Klatscher[p].j]);
			}
			set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, Moc_Klatscher[p].i, Moc_Klatscher[p].j, Klatscher);
		}
		
	} else { //you can't push Torringe away.
		if ((Field[0][unutma_i][unutma_j] == Treiber_1)||(Field[0][unutma_i][unutma_j] == Treiber_2)) {
			while (Field[0][unutma_i][unutma_j] > number_of_players) {
				unutma_i = Zufall (1, m-2);
				unutma_j = Zufall (1, n-2);
			}
		}
		Moc_Klatscher[p].i = unutma_i;
		Moc_Klatscher[p].j = unutma_j;
		set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, Moc_Klatscher[p].i, Moc_Klatscher[p].j, Klatscher);
	}
	
	#ifdef Quidditch_mistake_search
	printf("	Quidditch_Klatscher_steps-ending.ok \n");	//test
	#endif
	
}

void Klatscher_hits_target (unsigned int whose_turn, Spielfeld Field, unsigned int geben, Spielfeld Opague_o_field, unsigned int gamemode_played, Special_Fields_Collector* sfc, unsigned int number_of_players, unsigned int m, unsigned int n, Moveable_objects_condition* Moc_Klatscher, unsigned int p, Quidditch_setup* Qs) {
	
	#ifdef Quidditch_mistake_search
	printf("	Klatscher_hits_target-beginning.ok \n");	//test
	#endif
	
	unsigned int direction_choice;
	
	unsigned int ** allowed_directions;
	allowed_directions = unsigned_int_2dim_Vektor_Create (9, 3);
	
	direction_choice = 100;	//higher than 8
	for (unsigned int q=0; q<=8; q++) {
		allowed_directions[q][0] = hayir;
	}
	printf("	Player %u", whose_turn);
	printf(", a Klatscher hits the enemy at [%u][%u]. \n", Moc_Klatscher[p].i, Moc_Klatscher[p].j);
	printf("	In which direction do you want to push the enemy? \n");
	Klatscher_hit_allowed_directions (whose_turn, Field, m, n, Moc_Klatscher, p, allowed_directions);
	
	if (allowed_directions[1][0] == evet) {
		printf("	1: Top \n");
	}
	if (allowed_directions[2][0] == evet) {
		printf("	2: Top & Right \n");
	}
	if (allowed_directions[3][0] == evet) {
		printf("	3: Right \n");
	}
	if (allowed_directions[4][0] == evet) {
		printf("	4: Bottom & Right \n");
	}
	if (allowed_directions[5][0] == evet) {
		printf("	5: Bottom \n");
	}
	if (allowed_directions[6][0] == evet) {
		printf("	6: Bottom & Left \n");
	}
	if (allowed_directions[7][0] == evet) {
		printf("	7: Left \n");
	}
	if (allowed_directions[8][0] == evet) {
		printf("	8: Top & Left \n");
	}
	
	if (allowed_directions[0][0] == evet) {
		set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, allowed_directions[direction_choice][1], allowed_directions[direction_choice][2], Field[0][Moc_Klatscher[p].i][Moc_Klatscher[p].j]);
	} else {
		while ((direction_choice > 8) || (allowed_directions[direction_choice][0] != evet)) {
			direction_choice = get_unsigned_numeric_input_with_not_more_than_1_letter ();
		}
		set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, allowed_directions[direction_choice][1], allowed_directions[direction_choice][2], Field[0][Moc_Klatscher[p].i][Moc_Klatscher[p].j]);
	}
	set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, Moc_Klatscher[p].i, Moc_Klatscher[p].j, Klatscher);
	
	Moc_Klatscher[p].directed = 0;
	
	Moc_Klatscher[p].wanted_i = 0;
	Moc_Klatscher[p].wanted_j = 0;
	
	Qs->Points[0] += 1;
	
	unsigned_int_2dim_Vektor_Destroy (allowed_directions, 9);
	
	#ifdef Quidditch_mistake_search
	printf("	Klatscher_hits_target-ending.ok \n");	//test
	#endif
	
}

void Klatscher_hit_allowed_directions (unsigned int whose_turn, Spielfeld Field, unsigned int m, unsigned int n, Moveable_objects_condition* Moc_Klatscher, unsigned int p, unsigned int** allowed_directions) {
	
	#ifdef Quidditch_mistake_search
	printf("	Klatscher_hit_allowed_directions-beginning.ok \n");	//test
	#endif
	
	unsigned int h, k;
	
	h = 0;
	k = 0;
	allowed_directions[0][0] = evet;
	allowed_directions[0][1] = Zufall (1, m-2);
	allowed_directions[0][2] = Zufall (1, n-2);
	while (Field[0][allowed_directions[0][1]][allowed_directions[0][2]] > 2) {
		allowed_directions[0][1] = Zufall (1, m-2);
		allowed_directions[0][2] = Zufall (1, n-2);
	}
	
	for (unsigned int q=1; q<=8; q++) {
		h = Moc_Klatscher[p].i;
		k = Moc_Klatscher[p].j;
		while ((h != 0)&&(k != 0)&&(h <= m-2)&&(k <= n-2)) {
			if (Field[0][h][k] == (whose_turn%2)+1) {	//search for owner-square
				allowed_directions[0][0] = hayir;	//[0][0] is only possible if nothing else is possible
				allowed_directions[q][0] = evet;
				allowed_directions[q][1] = h;
				allowed_directions[q][2] = k;
				break;
			}
			
			if (q % 8 <= 2) {
				h -= 1;
			} else if ((q >= 4)&&(q <= 6)) {
				h += 1;
			}
			if (q % 9 >= 6) {
				k -= 1;
			} else if ((q >= 2)&&(q <= 4)) {
				k += 1;
			}
		}
	}
	
	#ifdef Quidditch_mistake_search
	printf("	Klatscher_hit_allowed_directions-ending.ok \n");	//test
	#endif
	
}

void Treiber_hits_Klatscher (unsigned int whose_turn, Spielfeld Field, unsigned int geben, Spielfeld Opague_o_field, unsigned int gamemode_played, Special_Fields_Collector* sfc, unsigned int number_of_players, unsigned int m, unsigned int n, Moveable_objects_condition* Moc_Klatscher, unsigned int p, Quidditch_setup* Qs) {
	
	#ifdef Quidditch_mistake_search
	printf("	Treiber_hits_Klatscher-beginning.ok \n");	//test
	#endif
	
	unsigned int allowed_directions[9], direction_choice, hit_length;
	int i_difference, j_difference;
	
	i_difference = 0;
	j_difference = 0;
	
	hit_length = 0;
	direction_choice = 0;
	for (unsigned int q=0; q<=8; q++) {
		allowed_directions[q] = evet;
	}
	printf("	Player %u", whose_turn);
	printf(", a Klatscher hits your Treiber at [%u][%u]. \n", Moc_Klatscher[p].i, Moc_Klatscher[p].j);
	printf("	In which direction do you want to hit the Klatscher? \n");
	
	if (Moc_Klatscher[p].i == 1) {
		allowed_directions[8] = hayir;
		allowed_directions[1] = hayir;
		allowed_directions[2] = hayir;
	} else if (Moc_Klatscher[p].i == m-2) {
		allowed_directions[4] = hayir;
		allowed_directions[5] = hayir;
		allowed_directions[6] = hayir;
	}
	if (Moc_Klatscher[p].j == 1) {
		allowed_directions[6] = hayir;
		allowed_directions[7] = hayir;
		allowed_directions[8] = hayir;
	} else if (Moc_Klatscher[p].j == n-2) {
		allowed_directions[2] = hayir;
		allowed_directions[3] = hayir;
		allowed_directions[4] = hayir;
	}
	
	
	while ((direction_choice == 0) || (direction_choice > 8) || (allowed_directions[direction_choice] != evet)) {
		
		if (allowed_directions[1] == evet) {
			printf("	%u: Top \n", top);
		}
		if (allowed_directions[2] == evet) {
			printf("	2: Top & Right \n");
		}
		if (allowed_directions[3] == evet) {
			printf("	3: Right \n");
		}
		if (allowed_directions[4] == evet) {
			printf("	4: Bottom & Right \n");
		}
		if (allowed_directions[5] == evet) {
			printf("	5: Bottom \n");
		}
		if (allowed_directions[6] == evet) {
			printf("	6: Bottom & Left \n");
		}
		if (allowed_directions[7] == evet) {
			printf("	7: Left \n");
		}
		if (allowed_directions[8] == evet) {
			printf("	8: Top & Left \n");
		}
		direction_choice = get_unsigned_numeric_input_with_not_more_than_1_letter ();
	}
	while ((hit_length == 0)||(hit_length > Qs->Qta[whose_turn].Treiber_hit_distance)) {
		printf("	How many squares should been taken? 	(1 - %u)\n", Qs->Qta[whose_turn].Treiber_hit_distance);
		hit_length = get_unsigned_numeric_input_with_not_more_than_1_letter ();
	}
	
	Moc_Klatscher[p].directed = direction_choice;
	Moc_Klatscher[p].remaining_squares_to_move = hit_length;
	for (unsigned int q=1; q<=hit_length; q++) {
		if (direction_choice % 8 <= 2) {
			i_difference -= 1;
		} else if ((direction_choice >= 4)&&(direction_choice <= 6)) {
			i_difference += 1;
		}
		if (direction_choice % 9 >= 6) {
			j_difference -= 1;
		} else if ((direction_choice >= 2)&&(direction_choice <= 4)) {
			j_difference += 1;
		}
	}
	
	Moc_Klatscher[p].wanted_i = 0;	// otherwise it causes trouble with Klatscher_steps
	Moc_Klatscher[p].wanted_j = 0;
	
	Quidditch_Klatscher_steps (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, m, n, Moc_Klatscher, p, i_difference, j_difference, Qs);
	
	#ifdef Quidditch_mistake_search
	printf("	Treiber_hits_Klatscher-ending.ok \n");	//test
	#endif
	
}

void Quidditch_Schnatz_movements (Spielfeld Field, unsigned int geben, Spielfeld Opague_o_field, unsigned int gamemode_played, Special_Fields_Collector* sfc, unsigned int number_of_players, unsigned int m, unsigned int n, Moveable_objects_condition* Moc_Schnatz, Quidditch_setup* Qs, unsigned int use_number) {
	
	#ifdef Quidditch_mistake_search
	printf("	Quidditch_Schnatz_movements-beginning.ok \n");	//test
	#endif
	
	unsigned int a_random_number, short_cut;
	
	a_random_number = undefined;
	short_cut = hayir;
	
	#ifdef Quidditch_mistake_search
	printf("	Moc_Schnatz->directed:  %u \n", Moc_Schnatz->directed);	//test
	printf("	use_number:  %u \n", use_number);	//test
	#endif
	
	if (Moc_Schnatz->directed == hayir) {	//not on the field.
		a_random_number = Zufall (1, (Qs->Qoa->Schnatz_appearence_factor)%10);
		// a_random_number = 1;	//test, reverse
		if (a_random_number <= (Qs->Qoa->Schnatz_appearence_factor)/10) {	//Appearence
			if (use_number%2 == 0) {
				for (unsigned int h=1; h<=m-2; h++) {
					for (unsigned int k=1; k<=n-2; k++) {
						if (Field[0][h][k] == Klatscher) {
							Moc_Schnatz->i = h;
							Moc_Schnatz->j = k;	//The Klatscher's position is imitating a Schnatz-position.
							Moc_Schnatz->remaining_squares_to_move = 3*(Qs->Qoa->Schnatz_fly_distance);
							Quidditch_move_of_Schnatz (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, m, n, Moc_Schnatz);
							short_cut = evet;
							break;
						}
					}
					if (short_cut == evet) {
						break;
					}
				}
			} else if (use_number%2 == 1) {
				for (unsigned int h=m-2; h>0; h--) {
					for (unsigned int k=n-2; k>0; k--) {
						if (Field[0][h][k] == Klatscher) {
							Moc_Schnatz->i = h;
							Moc_Schnatz->j = k;	//The Klatscher's position is imitating a Schnatz-position.
							Moc_Schnatz->remaining_squares_to_move = 3*(Qs->Qoa->Schnatz_fly_distance);
							Quidditch_move_of_Schnatz (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, m, n, Moc_Schnatz);
							short_cut = evet;
							break;
						}
					}
					if (short_cut == evet) {
						break;
					}
				}
			}
			Moc_Schnatz->directed = evet;
		}
	} else if (Moc_Schnatz->directed == evet) {	//on the field.
		a_random_number = Zufall (1, (Qs->Qoa->Schnatz_disappearence_factor)%10);
		if (a_random_number <= (Qs->Qoa->Schnatz_disappearence_factor)/10) {	//Dis-Appearence
			set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, Moc_Schnatz->i, Moc_Schnatz->j, 0);
			Moc_Schnatz->directed = hayir;
			Moc_Schnatz->i = 0;
			Moc_Schnatz->j = 0;
		} else {
			Moc_Schnatz->remaining_squares_to_move = Qs->Qoa->Schnatz_fly_distance;
			Quidditch_move_of_Schnatz (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, m, n, Moc_Schnatz);
		}
	}

	#ifdef Quidditch_mistake_search
	printf("	Quidditch_Schnatz_movements-ending.ok \n");	//test
	#endif
	
}

void Quidditch_move_of_Schnatz (Spielfeld Field, unsigned int geben, Spielfeld Opague_o_field, unsigned int gamemode_played, Special_Fields_Collector* sfc, unsigned int number_of_players, unsigned int m, unsigned int n, Moveable_objects_condition* Moc_Schnatz) {
	
	#ifdef Quidditch_mistake_search
	printf("	Quidditch_move_of_Schnatz-beginning.ok \n");	//test
	#endif
	
	unsigned int direction_choice, remember_steps_amount, unutma_i, unutma_j;
	
	unutma_i = Moc_Schnatz->i;
	unutma_j = Moc_Schnatz->j;
	direction_choice = undefined;
	remember_steps_amount = Moc_Schnatz->remaining_squares_to_move;
	
	while (Moc_Schnatz->remaining_squares_to_move != 0) {
		
		#ifdef Quidditch_mistake_search
		printf("	Moc_Schnatz->remaining_squares_to_move: %u \n", Moc_Schnatz->remaining_squares_to_move);	//test
		printf("	Moc_Schnatz->i: %u \n", Moc_Schnatz->i);	//test
		printf("	Moc_Schnatz->j: %u \n", Moc_Schnatz->j);	//test
		#endif
		
		direction_choice = Zufall (0, 9);
		dokuz_direction_interpretation_single_step (Moc_Schnatz, direction_choice);
		Moc_Schnatz->remaining_squares_to_move -= 1;
		if ((Moc_Schnatz->remaining_squares_to_move == 0)&&((Moc_Schnatz->i > m-2)||(Moc_Schnatz->i == 0)||(Moc_Schnatz->j > n-2)||(Moc_Schnatz->j == 0)||(Field[0][Moc_Schnatz->i][Moc_Schnatz->j] > number_of_players))) {
			Moc_Schnatz->remaining_squares_to_move = remember_steps_amount;
			Moc_Schnatz->i = unutma_i;
			Moc_Schnatz->j = unutma_j;
		}
	}
	if (Field[0][unutma_i][unutma_j] == Schnatz) {
		set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, unutma_i, unutma_j, 0);	//The order of "set_.." is important for the cause that the Schnatz' position stays the same
	}
	set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, Moc_Schnatz->i, Moc_Schnatz->j, Schnatz);
	
	#ifdef Quidditch_mistake_search
	printf("	Quidditch_move_of_Schnatz-ending.ok \n");	//test
	#endif
	
}

void dokuz_direction_interpretation_single_step (Moveable_objects_condition* Moc, unsigned int direction_choice) {
	
	#ifdef Quidditch_mistake_search
	printf("	dokuz_direction_interpretation_single_step-beginning.ok \n");	//test
	#endif
	
	if (direction_choice != 0) {
		if (direction_choice % 8 <= 2) {
			Moc->i -= 1;
		} else if ((direction_choice >= 4)&&(direction_choice <= 6)) {
			Moc->i += 1;
		}
		if (direction_choice % 9 >= 6) {
			Moc->j -= 1;
		} else if ((direction_choice >= 2)&&(direction_choice <= 4)) {
			Moc->j += 1;
		}
	}
	
	#ifdef Quidditch_mistake_search
	printf("	dokuz_direction_interpretation_single_step-ending.ok \n");	//test
	#endif
	
}

void Move_of_a_Quidditch_player (Spielfeld Field, unsigned int geben, Spielfeld Opague_o_field, unsigned int gamemode_played, Special_Fields_Collector* sfc, unsigned int number_of_players, unsigned int Team_member, unsigned int fly_distance, unsigned int m, unsigned int n, unsigned int* g, Moveable_objects_condition* Moc_Schnatz, Moveable_objects_condition* Moc_Quaffel, Quidditch_setup* Qs, unsigned int* already_moved_indicator) {
	
	#ifdef Quidditch_mistake_search
	printf("	Move_of_a_Quidditch_player-beginning.ok \n");	//test
	#endif
	
	unsigned int Zeile_alt, Spalte_alt, Zeile_neu, Spalte_neu;
	unsigned int direction_indicator, unutma_i, unutma_j, short_cut, range, Sucher, Hueter;
	
	//Team_member = Hueter, Sucher, Treiber, Jaeger
	
	direction_indicator = hayir;
	short_cut = hayir;
	range = 0;
	Sucher = undefined;
	
	if (geben == 1) {
		Sucher = Sucher_1;
		Hueter = Hueter_1;
	} else if (geben == 2) {
		Sucher = Sucher_2;
		Hueter = Hueter_2;
	}
	
	Zeile_alt = m;	//to get out of range, because zero would lead to "Sweet..."
	Spalte_alt = n;

	Zeile_neu = 0;
	Spalte_neu = 0;
	
	if (Team_member == Sucher) {
		range = Qs->Qta[geben].Sucher_fly_distance;
	} else if ((Team_member == Jaeger_1)||(Team_member == Jaeger_2)) {
		range = Qs->Qta[geben].Jaeger_fly_distance;
	} else if ((Team_member == Hueter_1)||(Team_member == Hueter_2)) {
		range = Qs->Qta[geben].Hueter_fly_distance;
	} else if ((Team_member == Treiber_1)||(Team_member == Treiber_2)) {
		range = Qs->Qta[geben].Treiber_fly_distance;
	}
	
	if ((Team_member != Sucher)&&(Team_member != Hueter)) {
		while ((((Zeile_alt > m-2)||(Spalte_alt > n-2)||(Field[0][Zeile_alt][Spalte_alt] != Team_member))&&((Spalte_alt != 0)||(Zeile_alt != 0)))||((Zeile_alt == already_moved_indicator[0])&&(Spalte_alt == already_moved_indicator[1]))) {
			printf("	The position of the Quidditch-player ?\n");
			printf("	alte Zeile: \n	alte Spalte: \n");
			
			letters_4 = get_unsigned_numeric_input_with_not_more_than_letters_4_for_splitting();
			Zeile_alt = split_unsigned_numeric_input_with_letters_4 (letters_4, 0);
			Spalte_alt = split_unsigned_numeric_input_with_letters_4 (letters_4, 1);
			
			if ((Zeile_alt == already_moved_indicator[0])&&(Spalte_alt == already_moved_indicator[1])&&(Zeile_alt != 0)&&(Spalte_alt != 0)) {
				printf("	You already moved this player! \n\n");
				Zeile_alt = 0;
				Spalte_alt = 0;
			}
		}
	} else {
		for (unsigned int i=1; i<=m-2; i++) {
			for (unsigned int j=1; j<=n-2; j++) {
				if (Team_member == Sucher) {
					if (Field[0][i][j] == Sucher) {
						Zeile_alt = i;
						Spalte_alt = j;
						short_cut = evet;
						break;
					}
				} else if (Team_member == Hueter) {
					if (Field[0][i][j] == Hueter) {
						Zeile_alt = i;
						Spalte_alt = j;
						short_cut = evet;
						break;
					}
				}
				
			}
			if (short_cut == evet) {
				short_cut = hayir;
				break;
			}
		}
	}
	
	
	if ((Spalte_alt == 0)&&(Zeile_alt == 0)) {
		printf("	Sweet escape...\n");
	} else {
		printf("	The position of choice of the Quidditch-player	(range: %u) ?\n", range);
		printf("	neue Zeile: \n	neue Spalte: \n");
		
		letters_4 = get_unsigned_numeric_input_with_not_more_than_letters_4_for_splitting();
		Zeile_neu = split_unsigned_numeric_input_with_letters_4 (letters_4, 0);
		Spalte_neu = split_unsigned_numeric_input_with_letters_4 (letters_4, 1);
		
		if ((Zeile_neu == 0)&&(Spalte_neu == 0)) {	//trivial change
			short_cut = evet;
			Zeile_neu = Zeile_alt;
			Spalte_neu = Spalte_alt;
		} else {
			for (unsigned int p=fly_distance; p>=1; p--) {
				for (unsigned int i=0; i<=2; i++) {
					for (unsigned int j=0; j<=2; j++) {
						if ((Zeile_alt + p*i-p <= m-2)&&(Spalte_alt + p*j-p <= n-2)) {	//Stackoverflow solves the bottom-border
							if ((Field[0][Zeile_alt + p*i-p*1][Spalte_alt + p*j-p] == geben)&&(Zeile_alt + p*i-p == Zeile_neu)&&(Spalte_alt + p*j-p == Spalte_neu)) {
								short_cut = evet;
								unutma_i = i;
								unutma_j = j;
								break;	//The new position is valid and found.
							}
						}
					}
					if (short_cut == evet) {
						break;
					}
				}
				if (short_cut == evet) {
					break;
				}
			}
		}
		
		if (short_cut == hayir) {	//The wanted new position wasn't valid.
			
			Move_of_a_Quidditch_player (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Team_member, fly_distance, m, n, g, Moc_Schnatz, Moc_Quaffel, Qs, already_moved_indicator);	//try again at the very beginning.
		} else if (short_cut == evet) {
			short_cut = hayir;
			
			set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, Zeile_alt, Spalte_alt, geben);	//Changing of the positions
			set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, Zeile_neu, Spalte_neu, Team_member);	//the order is important for Sweet Escape!
			
			direction_indicator = 0;
			while ((Zeile_alt + direction_indicator*unutma_i-direction_indicator != Zeile_neu)||(Spalte_alt + direction_indicator*unutma_j-direction_indicator != Spalte_neu)) {	//"||(direction_indicator <= fly_distance)" deleted, Schnatz/Quaffel-Regelungen beim Durchqueren/Mitnehmen.
				if ((Team_member == Sucher_1)||(Team_member == Sucher_2)) {
					if ((Zeile_alt + direction_indicator*unutma_i-direction_indicator == Moc_Schnatz->i)&&(Spalte_alt + direction_indicator*unutma_j-direction_indicator == Moc_Schnatz->j)) {
						set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, Moc_Schnatz->i, Moc_Schnatz->j, 0);
						Moc_Schnatz->i = 0;
						Moc_Schnatz->j = 0;
						if (Team_member == Sucher_1) {	// Catch of the Schnatz.
							Qs->Points[1] += 150;
						} else if (Team_member == Sucher_2) {
							Qs->Points[2] += 150;
						}
						
						set_terminal_color (cWHITE);
						printf("\n\n	What a BEEEAUUUUTIFULLLLL catch !!! \n\n");
						set_terminal_color (cNORMAL);
						
						*g = 0;
					}
				} else if ((Team_member == Jaeger_1)||(Team_member == Hueter_1)||(Team_member == Jaeger_2)||(Team_member == Hueter_2)) {	//All Quaffel-carrying people.
					already_moved_indicator[0] = Zeile_neu;
					already_moved_indicator[1] = Spalte_neu;
					
					for (unsigned int i=0; i<=2; i++) {
						for (unsigned int j=0; j<=2; j++) {
							if ((Zeile_alt-1+i + direction_indicator*unutma_i-direction_indicator == Moc_Quaffel->i)&&(Spalte_alt-1+j + direction_indicator*unutma_j-direction_indicator == Moc_Quaffel->j)&&((j%2 == 1)||(i%2 == 1))) {
								//Near-by controlling is following:
								if (geben == 2) {
									if (Field[0][Zeile_neu-1][Spalte_neu] == 0) {
										set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, Moc_Quaffel->i, Moc_Quaffel->j, 0);
										set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, Zeile_neu-1, Spalte_neu, Quaffel);
										Moc_Quaffel->i = Zeile_neu-1;
										Moc_Quaffel->j = Spalte_neu;
									} else if (Field[0][Zeile_neu][Spalte_neu-1] == 0) {
										set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, Moc_Quaffel->i, Moc_Quaffel->j, 0);
										set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, Zeile_neu, Spalte_neu-1, Quaffel);
										Moc_Quaffel->i = Zeile_neu;
										Moc_Quaffel->j = Spalte_neu-1;
									} else if (Field[0][Zeile_neu][Spalte_neu+1] == 0) {
										set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, Moc_Quaffel->i, Moc_Quaffel->j, 0);
										set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, Zeile_neu, Spalte_neu+1, Quaffel);
										Moc_Quaffel->i = Zeile_neu;
										Moc_Quaffel->j = Spalte_neu+1;
									} else if (Field[0][Zeile_neu+1][Spalte_neu] == 0) {
										set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, Moc_Quaffel->i, Moc_Quaffel->j, 0);
										set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, Zeile_neu+1, Spalte_neu, Quaffel);
										Moc_Quaffel->i = Zeile_neu+1;
										Moc_Quaffel->j = Spalte_neu;
									} else if (Field[0][Zeile_neu-1][Spalte_neu] == geben) {
										set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, Moc_Quaffel->i, Moc_Quaffel->j, geben);
										set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, Zeile_neu-1, Spalte_neu, Quaffel);
										Moc_Quaffel->i = Zeile_neu-1;
										Moc_Quaffel->j = Spalte_neu;
									} else if (Field[0][Zeile_neu][Spalte_neu-1] == geben) {
										set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, Moc_Quaffel->i, Moc_Quaffel->j, geben);
										set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, Zeile_neu, Spalte_neu-1, Quaffel);
										Moc_Quaffel->i = Zeile_neu;
										Moc_Quaffel->j = Spalte_neu-1;
									} else if (Field[0][Zeile_neu][Spalte_neu+1] == geben) {
										set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, Moc_Quaffel->i, Moc_Quaffel->j, geben);
										set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, Zeile_neu, Spalte_neu+1, Quaffel);
										Moc_Quaffel->i = Zeile_neu;
										Moc_Quaffel->j = Spalte_neu+1;
									} else if (Field[0][Zeile_neu+1][Spalte_neu] == geben) {
										set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, Moc_Quaffel->i, Moc_Quaffel->j, geben);
										set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, Zeile_neu+1, Spalte_neu, Quaffel);
										Moc_Quaffel->i = Zeile_neu+1;
										Moc_Quaffel->j = Spalte_neu;
									}	//If no near-by-field is free (zero or in your possession with a normal square), you can't pick up the Quaffel.
									
								} else if (geben == 1) {
									if (Field[0][Zeile_neu+1][Spalte_neu] == 0) {
										set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, Moc_Quaffel->i, Moc_Quaffel->j, 0);
										set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, Zeile_neu+1, Spalte_neu, Quaffel);
										Moc_Quaffel->i = Zeile_neu+1;
										Moc_Quaffel->j = Spalte_neu;
									} else if (Field[0][Zeile_neu][Spalte_neu-1] == 0) {
										set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, Moc_Quaffel->i, Moc_Quaffel->j, 0);
										set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, Zeile_neu, Spalte_neu-1, Quaffel);
										Moc_Quaffel->i = Zeile_neu;
										Moc_Quaffel->j = Spalte_neu-1;
									} else if (Field[0][Zeile_neu][Spalte_neu+1] == 0) {
										set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, Moc_Quaffel->i, Moc_Quaffel->j, 0);
										set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, Zeile_neu, Spalte_neu+1, Quaffel);
										Moc_Quaffel->i = Zeile_neu;
										Moc_Quaffel->j = Spalte_neu+1;
									} else if (Field[0][Zeile_neu-1][Spalte_neu] == 0) {
										set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, Moc_Quaffel->i, Moc_Quaffel->j, 0);
										set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, Zeile_neu-1, Spalte_neu, Quaffel);
										Moc_Quaffel->i = Zeile_neu-1;
										Moc_Quaffel->j = Spalte_neu;
									} else if (Field[0][Zeile_neu+1][Spalte_neu] == geben) {
										set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, Moc_Quaffel->i, Moc_Quaffel->j, geben);
										set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, Zeile_neu+1, Spalte_neu, Quaffel);
										Moc_Quaffel->i = Zeile_neu+1;
										Moc_Quaffel->j = Spalte_neu;
									} else if (Field[0][Zeile_neu][Spalte_neu-1] == geben) {
										set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, Moc_Quaffel->i, Moc_Quaffel->j, geben);
										set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, Zeile_neu, Spalte_neu-1, Quaffel);
										Moc_Quaffel->i = Zeile_neu;
										Moc_Quaffel->j = Spalte_neu-1;
									} else if (Field[0][Zeile_neu][Spalte_neu+1] == geben) {
										set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, Moc_Quaffel->i, Moc_Quaffel->j, geben);
										set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, Zeile_neu, Spalte_neu+1, Quaffel);
										Moc_Quaffel->i = Zeile_neu;
										Moc_Quaffel->j = Spalte_neu+1;
									} else if (Field[0][Zeile_neu-1][Spalte_neu] == geben) {
										set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, Moc_Quaffel->i, Moc_Quaffel->j, geben);
										set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, Zeile_neu-1, Spalte_neu, Quaffel);
										Moc_Quaffel->i = Zeile_neu-1;
										Moc_Quaffel->j = Spalte_neu;
									}	//If no near-by-field is free (zero or in your possession with a normal square), you can't pick up the Quaffel.
								}
								
								direction_indicator += (fly_distance +1);
								break;
							}
						}
						if (direction_indicator >= fly_distance +1) {
							break;
						}
					}
				}
				if (direction_indicator >= fly_distance +1) {
					break;
				}
				direction_indicator+=1;
			}
		}
	}
	
	#ifdef Quidditch_mistake_search
	printf("	Move_of_a_Quidditch_player-ending.ok \n");	//test
	#endif
	
}

void Localization_of_Moc (Spielfeld Field, unsigned int m, unsigned int n, Moveable_objects_condition* Moc_Quaffel, Moveable_objects_condition* Moc_Schnatz, Moveable_objects_condition* Moc_Klatscher) {
	
	#ifdef Quidditch_mistake_search
	printf("	Localization_of_Moc-beginning.ok \n");	//test
	#endif
	
	unsigned int klatscher_choice;
	
	klatscher_choice = 0;
	
	#ifdef Quidditch_mistake_search
	printf("	Quaffel: [%u][%u]		at this position: %u \n", Moc_Quaffel->i, Moc_Quaffel->j, Field[0][Moc_Quaffel->i][Moc_Quaffel->j]);	//test
	printf("	Schnatz: [%u][%u]		at this position: %u \n", Moc_Schnatz->i, Moc_Schnatz->j, Field[0][Moc_Schnatz->i][Moc_Schnatz->j]);	//test
	printf("	Klatscher[0]: [%u][%u]		at this position: %u \n", Moc_Klatscher[0].i, Moc_Klatscher[0].j, Field[0][Moc_Klatscher[0].i][Moc_Klatscher[0].j]);	//test
	printf("	Klatscher[1]: [%u][%u]		at this position: %u \n", Moc_Klatscher[1].i, Moc_Klatscher[1].j, Field[0][Moc_Klatscher[1].i][Moc_Klatscher[1].j]);	//test
	#endif
	
	for (unsigned int h=1; h<=m-2; h++) {
		for (unsigned int k=1; k<=n-2; k++) {
			if (Field[0][h][k] == Quaffel) {
				Moc_Quaffel->i = h;
				Moc_Quaffel->j = k;
			} else if (Field[0][h][k] == Schnatz) {
				Moc_Schnatz->i = h;
				Moc_Schnatz->j = k;
			} else if (Field[0][h][k] == Klatscher) {
				Moc_Klatscher[klatscher_choice].i = h;
				Moc_Klatscher[klatscher_choice].j = k;
				klatscher_choice += 1;
			}
		}
	}
	klatscher_choice = 0;
	
	#ifdef Quidditch_mistake_search
	printf("	Localization_of_Moc-ending.ok \n");	//test
	#endif
	
}

void Quidditch_Quaffel_Throw (Spielfeld Field, unsigned int geben, Spielfeld Opague_o_field, unsigned int gamemode_played, Special_Fields_Collector* sfc, unsigned int number_of_players, unsigned int m, unsigned int n, Moveable_objects_condition* Moc_Quaffel, Quidditch_setup* Qs, unsigned int* ges, unsigned int limits_at_all, unsigned int* turns_counter) {
	
	#ifdef Quidditch_mistake_search
	printf("	Quidditch_Quaffel_Throw-beginning.ok \n");	//test
	#endif
	
	unsigned int allowed_to, Hueter, Jaeger, Torring, throw_distance, Zeile_alt, Spalte_alt, Zeile_neu, Spalte_neu;
	
	allowed_to = hayir;	//is it possible to reach the Quaffel?
	Hueter = undefined;
	Jaeger = undefined;
	Torring = undefined;
	throw_distance = 0;	//needs to be 0.
	Zeile_neu = m;
	Spalte_neu = n;
	Zeile_alt = Moc_Quaffel->i;
	Spalte_alt = Moc_Quaffel->j;
	
	if (geben == 1) {
		Hueter = Hueter_1;
		Jaeger = Jaeger_1;
		Torring = Torring_2;
	} else if (geben == 2) {
		Hueter = Hueter_2;
		Jaeger = Jaeger_2;
		Torring = Torring_1;
	}
	
	for (unsigned int h=0; h<=2; h++) {
		for (unsigned int k=0; k<=2; k++) {
			if ((h+k)%2 == 1) {
				if (Field[0][Moc_Quaffel->i +h-1][Moc_Quaffel->j +k-1] == Jaeger) {
					if (Qs->Qta[geben].Jaeger_throw_distance > throw_distance) {
						throw_distance = Qs->Qta[geben].Jaeger_throw_distance;
					}
					allowed_to = evet;
					
				} else if (Field[0][Moc_Quaffel->i +h-1][Moc_Quaffel->j +k-1] == Hueter) {
					if (Qs->Qta[geben].Hueter_throw_distance > throw_distance) {
						throw_distance = Qs->Qta[geben].Hueter_throw_distance;
					}
					allowed_to = evet;
				}
			}
		}
	}
	
	if (allowed_to == hayir) {
		printf("	Sorry, but the Quaffel isn't in your possession. \n");
		*turns_counter -= 1;
	} else if (allowed_to == evet) {
		
		while ((Zeile_neu > m-2)||(Spalte_neu > n-2)||((Zeile_neu == 0)&&(Spalte_neu != 0))||((Spalte_neu == 0)&&(Zeile_neu != 0))||(abs(Moc_Quaffel->i - Zeile_neu) > abs(throw_distance - 0))||(abs(Moc_Quaffel->j - Spalte_neu) > abs(throw_distance - 0))||((Field[0][Zeile_neu][Spalte_neu] != 0)&&(Field[0][Zeile_neu][Spalte_neu] != geben)&&(Field[0][Zeile_neu][Spalte_neu] != Torring))) {
			
			printf("	The position of choice of the Quaffel (now: [%u][%u]) ?		(Range: %u)\n", Moc_Quaffel->i, Moc_Quaffel->j, throw_distance);
			printf("	neue Zeile: \n	neue Spalte: \n");
			
			letters_4 = get_unsigned_numeric_input_with_not_more_than_letters_4_for_splitting();
			Zeile_neu = split_unsigned_numeric_input_with_letters_4 (letters_4, 0);
			Spalte_neu = split_unsigned_numeric_input_with_letters_4 (letters_4, 1);
		}
		
		if ((Spalte_neu == 0)&&(Zeile_neu == 0)) {
			printf("	Sweet escape...\n");
		} else {
			Moc_Quaffel->wanted_i = Zeile_neu;
			Moc_Quaffel->wanted_j = Spalte_neu;
			
			while ((Moc_Quaffel->i != Moc_Quaffel->wanted_i)||(Moc_Quaffel->j != Moc_Quaffel->wanted_j)||((Field[0][Moc_Quaffel->i][Moc_Quaffel->j] > 2)&&(Field[0][Moc_Quaffel->i][Moc_Quaffel->j] != Torring))) {
				Realize_Moc_Quaffel_Throw_step (Field, geben,  Moc_Quaffel, Torring);
			}
			
			if (Field[0][Moc_Quaffel->i][Moc_Quaffel->j] == Torring) {
				set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, Zeile_alt, Spalte_alt, 0);
				Quidditch_a_goal_has_been_scored (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, m, n, Moc_Quaffel, ges, limits_at_all);
				Qs->Points[geben] += 10;
			} else {
				set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, Zeile_neu, Spalte_neu, Quaffel);
				set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, Zeile_alt, Spalte_alt, 0);
			}
		}
	}
	
	#ifdef Quidditch_mistake_search
	printf("	Quidditch_Quaffel_Throw-ending.ok \n");	//test
	#endif
	
}

void Realize_Moc_Quaffel_Throw_step (Spielfeld Field, unsigned int geben, Moveable_objects_condition* Moc_Quaffel, unsigned int Torring) {
	
	#ifdef Quidditch_mistake_search
	printf("	Realize_Moc_Quaffel_Throw_step-beginning.ok \n");	//test
	#endif
	
	unsigned int direction_choice, Jaeger, Hueter;
	int i_difference, j_difference;
	
	direction_choice = undefined;
	Jaeger = undefined;
	Hueter = undefined;
	i_difference = 0;
	j_difference = 0;
	
	
	if (geben == 2) {
		Hueter = Hueter_1;
		Jaeger = Jaeger_1;
	} else if (geben == 1) {
		Hueter = Hueter_2;
		Jaeger = Jaeger_2;
	}
	i_difference = Moc_Quaffel->wanted_i - Moc_Quaffel->i;
	j_difference = Moc_Quaffel->wanted_j - Moc_Quaffel->j;
	
	#ifdef Quidditch_mistake_search
	printf("	Quaffel: [%u][%u]		at this position: %u \n", Moc_Quaffel->i, Moc_Quaffel->j, Field[0][Moc_Quaffel->i][Moc_Quaffel->j]);	//test
	printf("	Quaffel_wanted: [%u][%u]		at this position: %u \n", Moc_Quaffel->wanted_i, Moc_Quaffel->wanted_j, Field[0][Moc_Quaffel->wanted_i][Moc_Quaffel->wanted_j]);	//test
	printf("	i_difference: %d \n", i_difference);
	printf("	j_difference: %d \n", j_difference);
	#endif
	
	if (j_difference == 0) {
		direction_choice = Vertikal;
	} else if (i_difference == 0) {
		direction_choice = Horizontal;
	} else if (abs(i_difference) == abs(j_difference)) {
		direction_choice = Changing;
	} else {
		while ((((direction_choice != Horizontal)||(abs(j_difference) <= abs(i_difference)))&&((direction_choice != Vertikal)||(abs(i_difference) <= abs(j_difference)))&&((direction_choice != Changing)||((i_difference == 0)||(j_difference == 0))))&&(direction_choice != 9)) {
				printf("	How do you want to throw?");
				printf(" 	(target: [%u][%u]) \n", Moc_Quaffel->wanted_i, Moc_Quaffel->wanted_j);
				if (abs(i_difference) < abs(j_difference)) {
					printf("	%u: Horizontal \n", Horizontal);
				}
				if (abs(i_difference) > abs(j_difference)) {
					printf("	%u: Vertikal \n", Vertikal);
				}
				if ((i_difference != 0)&&(j_difference != 0)) {
					printf("	%u: diagonal \n", Changing);
				}
				direction_choice = get_unsigned_numeric_input_with_not_more_than_1_letter ();
		}
	}
	
	//it is important that Horizontal comes before Vertikal for the scoring of goals
	
	if ((direction_choice == Horizontal)||(direction_choice == Changing)) {
		if (j_difference < 0) {	//have a look on the definition of the difference.
			Moc_Quaffel->j -= 1;
		} else if (j_difference > 0) {
			Moc_Quaffel->j += 1;
		}
		
		if ((Moc_Quaffel->i == Moc_Quaffel->wanted_i)&&(Moc_Quaffel->j == Moc_Quaffel->wanted_j)&&(Field[0][Moc_Quaffel->wanted_i][Moc_Quaffel->wanted_j] == Torring)) {	//only possible if there's no Vertikal anymore
			
			if (j_difference < 0) {	//have a look on the definition of the difference.
				Moc_Quaffel->j += 1;
			} else if (j_difference > 0) {
				Moc_Quaffel->j -= 1;
			}
			Moc_Quaffel->wanted_j = Moc_Quaffel->j;	//break before reaching the Torring, because you hit it from the side.
		}
	}
	if ((direction_choice == Vertikal)||(direction_choice == Changing)) {
		if (i_difference < 0) {	//have a look on the definition of the difference.
			Moc_Quaffel->i -= 1;
		} else if (i_difference > 0) {
			Moc_Quaffel->i += 1;
		}
	}
	
	for (unsigned int h=0; h<=2; h++) {
		for (unsigned int k=0; k<=2; k++) {
			if ((h+k)%2 == 1) {
				if ((Field[0][Moc_Quaffel->i +h-1][Moc_Quaffel->j +k-1] == Jaeger)||(Field[0][Moc_Quaffel->i +h-1][Moc_Quaffel->j +k-1] == Hueter)) {
					Moc_Quaffel->wanted_i = Moc_Quaffel->i;	//caught by the enemy
					Moc_Quaffel->wanted_j = Moc_Quaffel->j;
				}
			}
		}
	}
	
	if (direction_choice == 9) {	//escaping
			Moc_Quaffel->wanted_i = Moc_Quaffel->i;
			Moc_Quaffel->wanted_j = Moc_Quaffel->j;
	}
	
	#ifdef Quidditch_mistake_search
	printf("	Quaffel: [%u][%u]		at this position: %u \n", Moc_Quaffel->i, Moc_Quaffel->j, Field[0][Moc_Quaffel->i][Moc_Quaffel->j]);	//test
	printf("	Quaffel_wanted: [%u][%u]		at this position: %u \n", Moc_Quaffel->wanted_i, Moc_Quaffel->wanted_j, Field[0][Moc_Quaffel->wanted_i][Moc_Quaffel->wanted_j]);	//test
	printf("	i_difference: %d \n", i_difference);
	printf("	j_difference: %d \n", j_difference);
	#endif
	
	#ifdef Quidditch_mistake_search
	printf("	Realize_Moc_Quaffel_Throw_step-ending.ok \n");	//test
	#endif
	
}

void Quidditch_a_goal_has_been_scored (Spielfeld Field, unsigned int geben, Spielfeld Opague_o_field, unsigned int gamemode_played, Special_Fields_Collector* sfc, unsigned int number_of_players, unsigned int m, unsigned int n, Moveable_objects_condition* Moc_Quaffel, unsigned int* ges, unsigned int limits_at_all) {
	
	#ifdef Quidditch_mistake_search
	printf("	Quidditch_a_goal_has_been_scored-beginning.ok \n");	//test
	#endif
	
	unsigned int only_need_one_square;
	
	only_need_one_square = hayir;
	
	for (unsigned int i=m/2; i<=m-2; i++) {
		for (unsigned int j=1; j<=n-2; j++) {
			if (Field[0][i][j] == Jaeger_1) {
				for (unsigned int h=1; h<=(m-2)/2; h++) {
					for (unsigned int k=1; k<=n-2; k++) {
						if (Field[0][h][k] == 1) {
							set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, i, j, 1);
							set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, h, k, Jaeger_1);
							only_need_one_square = evet;
							break;
						}
					}
					if (only_need_one_square == evet) {
						only_need_one_square = hayir;	//there are maybe more than 1 Jaeger who can get back
						break;
					}
				}
			}
		}
	}
	for (unsigned int i=1; i<=(m-2)/2; i++) {
		for (unsigned int j=1; j<=n-2; j++) {
			if (Field[0][i][j] == Jaeger_2) {
				for (unsigned int h=m-2; h>=m/2; h--) {
					for (unsigned int k=1; k<=n-2; k++) {
						if (Field[0][h][k] == 2) {
							set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, i, j, 2);
							set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, h, k, Jaeger_2);
							only_need_one_square = evet;
							break;
						}
					}
					if (only_need_one_square == evet) {
						only_need_one_square = hayir;	//there are maybe more than 1 Jaeger who can get pulled back
						break;
					}
				}
			}
		}
	}
	
	only_need_one_square = hayir;
	if (geben == 1) {	//where to put the Quaffel (look at the h-loop).
		for (unsigned int h=m-3; h<=m-2; h++) {
			for (unsigned int k=2; k<=n-3; k++) {	//don't want it at the wall.
				if (Field[0][h][k] <= 2) {
					set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, h, k, Quaffel);
					Moc_Quaffel->i = h;
					Moc_Quaffel->j = k;
					only_need_one_square = evet;
					break;
				}
			}
			if (only_need_one_square == evet) {
				break;
			}
		}
	} else if (geben == 2) {
		for (unsigned int h=2; h>=1; h--) {
			for (unsigned int k=2; k<=n-3; k++) {
				if (Field[0][h][k] <= 2) {
					set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, h, k, Quaffel);
					Moc_Quaffel->i = h;
					Moc_Quaffel->j = k;
					only_need_one_square = evet;
					break;
				}
			}
			if (only_need_one_square == evet) {
				break;
			}
		}
	}
	
	for (unsigned int p=1; p<=number_of_players; p++) {
		unsigned int i;
		i = (p%2) * (m-2) + ((p+1)%2);	//regain strenght in the offensive
		for (unsigned int j=1; j<=n-2; j++) {
			if ((Field[0][i][j] == 0) && (ges[p] < limits_at_all)) {
				set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, i, j, p);
				ges[p] += 1;
			}
		}
		
		i = (p%2) * 2 + ((p+1)%2) * (m-3);	//regain strenght in the defensive
		for (unsigned int j=1; j<=n-2; j++) {
			if ((Field[0][i][j] == 0) && (ges[p] < limits_at_all)) {
				set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, sfc, number_of_players, Field, 0, i, j, p);
				ges[p] += 1;
			}
		}
	}
	
	set_terminal_color(cWHITE);
	printf("\n	A goal has been scored! \n");
	set_terminal_color(cNORMAL);
	
	#ifdef Quidditch_mistake_search
	printf("	Quidditch_a_goal_has_been_scored-ending.ok \n");	//test
	#endif
	
}

void Initialisierung_Qs (Quidditch_setup* Qs, Quidditch_team_abilities* Qta, Quidditch_object_abilities* Qoa, Growth_Player* Growth_players) {
	unsigned int color_translation[3], numberofplayers;
	numberofplayers = 2;
	
	color_translation[0] = 0;
	
	for (unsigned int p=1; p<=numberofplayers; p++) {
		unsigned int choice, types;
		types = 3;
		choice = types + 1;
		
		while (choice > types) {
			Square_color_interpretation (Growth_players, 0, 2, p);
			printf("	Which Quidditch-team-abilities do you want to take, player %u ? \n", p);
			set_terminal_color (cNORMAL);
			printf("	0 : basic\n	1 : default_1 \n	2 : default_2 \n	%u : classic \n", types);
			choice = get_unsigned_numeric_input_with_not_more_than_1_letter ();
		}
		
		if (choice <= 2) {
			color_translation[p] = choice;	//thats 0,1,2
		} else if (choice == types) {
			if (Growth_players[p].color == cLIGHT_MAGENTA) {
				color_translation[p] = HGryffindor;
			} else if (Growth_players[p].color == cLIGHT_CYAN) {
				color_translation[p] = HRavenclaw;
			} else if (Growth_players[p].color == cYELLOW) {
				color_translation[p] = HHufflepuff;
			} else if (Growth_players[p].color == cLIGHT_GREEN) {
				color_translation[p] = HSlytherin;
			}
		}
	}
	
	for (unsigned int q=0; q<=2; q++) {	//the right modification of the abilities, reducing from 1+2+4 to 1+2 ("1+" because of the standard-setting, "2+" because of the defaults).
		Qs->Qta[q] = Qta[color_translation[q]];	//that means: no copy.
		Qs->Points[q] = 0;
	}
	Qs->Qoa = Qoa;
	
}
void Initialisierung_Qoa (Quidditch_object_abilities* Qoa) {	//always synchronisate with (normal: ... in .c)
	Qoa[0].Klatscher_fly_distance = 4;
	Qoa[0].Schnatz_fly_distance = 6;
	Qoa[0].Schnatz_appearence_factor = 25;	//to read as 2/5
	Qoa[0].Schnatz_disappearence_factor = 12;	//to read as 1/2
}
void Initialisierung_Qta (Quidditch_team_abilities* Qta) {	//always synchronisate with (normal: ... in .c)
	unsigned int normal_value;
	normal_value = 5;
	
	for (unsigned int p=0; p<=HSlytherin; p++) {
		Qta[p].Jaeger_fly_distance = normal_value;
		Qta[p].Jaeger_throw_distance = normal_value;
		Qta[p].Hueter_fly_distance = normal_value-1;
		Qta[p].Hueter_throw_distance = normal_value;
		Qta[p].Treiber_fly_distance = normal_value;
		Qta[p].Treiber_hit_distance = normal_value;
		Qta[p].Sucher_fly_distance = normal_value;
		
		if (p == HGryffindor) {
			Qta[p].Sucher_fly_distance = normal_value+1;
		} else if (p == HHufflepuff) {
			Qta[p].Hueter_fly_distance = normal_value+2;
			Qta[p].Hueter_throw_distance = normal_value+1;
		} else if (p == HRavenclaw) {
			Qta[p].Jaeger_fly_distance = normal_value+1;
			Qta[p].Jaeger_throw_distance = normal_value+1;
		} else if (p == HSlytherin) {
			Qta[p].Treiber_fly_distance = normal_value+1;
			Qta[p].Treiber_hit_distance = normal_value+1;
		}
	}
}

void Initialisierung_Moc (Moveable_objects_condition* Moc_Quaffel, Moveable_objects_condition* Moc_Schnatz, Moveable_objects_condition* Moc_Klatscher, unsigned int m, unsigned int n) {
	
	Moc_Quaffel->i = (m-2)/2;
	Moc_Quaffel->j = (n-1)/2;
	
	Moc_Schnatz->i = (m-2)/2 +1;
	Moc_Schnatz->j = (n-1)/2;
	Moc_Schnatz->directed = evet;
	
	Moc_Klatscher[0].i = (m-2)/2 -1;
	Moc_Klatscher[0].j = (n-1)/2;
	Moc_Klatscher[1].i = (m-2)/2 +2;
	Moc_Klatscher[1].j = (n-1)/2;
	
}

