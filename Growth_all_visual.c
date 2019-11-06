
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
//#include <windows.h>	// look at Growth.h
#include <ctype.h>

#ifdef _WIN32
#include <windows.h>
#endif

#include "Growth_all_Def.h"
#include "Growth_all_Vektor.h"
#include "Growth_all_Initialisierung.h"
#include "Growth_all_set.h"
#include "Growth_all_get.h"
#include "Growth_all_visual.h"

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
				} else if ((square_number >= Roses_0)&&(square_number <= Roses_6)) {
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

void set_terminal_color (Color color) {

		switch(color) {
		case cWHITE:
		{
			#ifdef _WIN32
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+15);
			#else
				printf("\x1B[37m");
			#endif
			break;
		}
		
		case cLIGHT_GRAY:
		{
			#ifdef _WIN32
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+7);
			#else
				printf("\x0B[37m");
			#endif
			break;
		}
		
		case cGRAY:
		{
			#ifdef _WIN32
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+8);
			#else
				printf("\x1B[0m");
			#endif
			break;
		}
		
		case cLIGHT_MAGENTA:
		{
			#ifdef _WIN32
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+13);
			#else
				printf("\x1B[35m");
			#endif
			break;
		}
		case cLIGHT_RED:
		{
			#ifdef _WIN32
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+12);
			#else
				printf("\x1B[31m");
			#endif
			break;
		}
		case cRED:
		{
			#ifdef _WIN32
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+4);
			#else
				printf("\x0B[31m");
			#endif
			break;
		}
		case cLIGHT_CYAN:
		{
			#ifdef _WIN32
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+11);
			#else
				printf("\x1B[36m");
			#endif
			break;
		}
		case cCYAN:
		{
			#ifdef _WIN32
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+3);
			#else
				printf("\x0B[36m");
			#endif
			break;
		}
		case cLIGHT_BLUE:
		{
			#ifdef _WIN32
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+9);
			#else
				printf("\x1B[34m");
			#endif
			break;
		}
		case cBLUE:
		{
			#ifdef _WIN32
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+1);
			#else
				printf("\x0B[34m");
			#endif
			break;
		}
		
		case cYELLOW:
		{
			#ifdef _WIN32
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+14);
			#else
				printf("\x1B[33m");
			#endif
			break;
		}
		
		case cLIGHT_GREEN:
		{
			#ifdef _WIN32
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+10);
			#else
				printf("\x1B[32m");
			#endif
			break;
		}
		
		case cGREEN:
		{
			#ifdef _WIN32
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+2);
			#else
				printf("\x0B[32m");
			#endif
			break;
		}
		
		case cBROWN:
		{
			#ifdef _WIN32
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+6);
			#else
				printf("\x1B[0m");
			#endif
			break;
		}
		
		default:
		{
			#ifdef _WIN32
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+7);
			#else
				printf("\x1B[0m");
			#endif
			break;
		}
		}
}

void set_player_color (Growth_Player* Growth_players, unsigned int id, Color color) {
		Growth_players[id].color = color;
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
