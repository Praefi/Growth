
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
#include "Growth_all_set.h"


void set_Spielfeld_Eintrag (Spielfeld Field, unsigned int geben, Spielfeld Opague_o_field, unsigned int gamemode_played, Special_Fields_Collector* sfc, unsigned int number_of_players, Spielfeld Spiel, unsigned int first, unsigned int i, unsigned int j, unsigned int Eintrag) {

	// if ((Field[first][i][j] == 11)&&(Eintrag != 11)) {	//test
		// printf("	Fehler: Heart wird in Field nicht trivial überschrieben	i=%u	j=%u \n", i, j);
	// } else {
		// printf("	Eintrag:%u	i=%u	j=%u \n\n", Eintrag, i, j);
	// }

	// printf("set_Spielfeld_Eintrag ok.1 \n");	//test
	// if (Spiel != Field) {
		// printf("Eintrag:%u, i=%u, j=%u	", Eintrag, i, j);
		// printf("ok.1 ");	//test
	// }

	if ((Spiel == sfc->Allocation_o.field)&&(first == 1)&&(Eintrag != 0)) {	//Addieren statt ersetzen in Allocation[1], da die Summe an Abzügen gezählt werden muss, außer beim Reset (Eintrag == 0).
		Spiel[first][i][j] += Eintrag;

		// printf("set_Spielfeld_Eintrag ok.2 \n");	//test
		// printf("ok.2 \n");	//test

	} else {
		Spiel[first][i][j] = Eintrag;

		// printf("set_Spielfeld_Eintrag ok.3 \n");	//test
		// if (Spiel != Field) {
			// printf("ok.3 ");	//test
		// }
	}

	if (sfc->Allocation_o.characterization != 0) {
		// printf("set_Spielfeld_Eintrag ok.4 \n");
		if (((Eintrag != 0)&&(Eintrag <= number_of_players))||((gamemode_played == Hunt)&&(Eintrag == 11))) {
			if (Spiel == Opague_o_field) {
				if (Eintrag == geben) {
					sfc->Allocation_o.field[2][i][j] = sfc->Allocation_o.field[0][i][j];
				} else {
					sfc->Allocation_o.field[2][i][j] = 1;
				}
			} else if ((Spiel == Field)&&(first == 0)) {
				sfc->Allocation_o.field[0][i][j] = 1;
			}

			// printf("set_Spielfeld_Eintrag ok.5 \n");

		} else {	//Eintrag is not a player
			if (Spiel == Opague_o_field) {
				sfc->Allocation_o.field[2][i][j] = 0;
			} else if ((Spiel == Field)&&(first == 0)) {
				sfc->Allocation_o.field[0][i][j] = 0;
			}

			// printf("set_Spielfeld_Eintrag ok.6 \n");

		}
	}

	if (sfc->Partition_o.characterization != 0) {
		// printf("set_Spielfeld_Eintrag ok.7 \n");
		if (((Eintrag != 0)&&(Eintrag <= number_of_players))||((gamemode_played == Hunt)&&(Eintrag == 11))) {
			if (Spiel == Opague_o_field) {
				if (Eintrag == geben) {
					sfc->Partition_o.field[2][i][j] = sfc->Partition_o.field[0][i][j];
				} else {
					sfc->Partition_o.field[2][i][j] = 1;
				}
			} else if ((Spiel == Field)&&(first == 0)) {
				unsigned int partition_counter;
				partition_counter = 0;
				
				for (unsigned int h=i-1; h<=i+1; h++) {
					for (unsigned int k=j-1; k<=j+1; k++) {
						if ((sfc->Partition_o.field[1][h][k] != 0)&&((Field[0][h][k] == Eintrag)||(Field[0][h][k] == 0))) {
							partition_counter += (sfc->Partition_o.field[1][h][k]);
						}
					}
				}
				if (partition_counter == 0) {
					partition_counter = 1;
				}
				if (sfc->Partition_o.characterization == 1) {
					sfc->Partition_o.field[0][i][j] = partition_counter;
				} else {
					sfc->Partition_o.field[0][i][j] = ((partition_counter-1)%(sfc->Partition_o.characterization)) +1;	//partition_counter >= 1.
				}
			}

			// printf("set_Spielfeld_Eintrag ok.8 \n");

		} else {	//Eintrag is not a player
			if (Spiel == Opague_o_field) {
				sfc->Partition_o.field[2][i][j] = 0;
			} else if ((Spiel == Field)&&(first == 0)) {
				sfc->Partition_o.field[0][i][j] = 0;
			}

			// printf("set_Spielfeld_Eintrag ok.9 \n");

		}
	}
	// if (Spiel != Field) {
		// printf("ok.10 ");	//test
	// }
}

void set_gleiter_oben_links (unsigned int single_option_representives_inverted, Spielfeld Field, unsigned int geben, unsigned int i, unsigned int j) {	//oben das Bein, oben links das Wachstum, zentral aufgetragen
	if (single_option_representives_inverted == 0) {
		Field[0][i-1][j]	= geben;
		Field[0][i-1][j+1]	= geben;
		Field[0][i][j]		= geben;
		Field[0][i][j-1]	= geben;
		Field[0][i+1][j+1]	= geben;
	} else if (single_option_representives_inverted == 1) {
		Field[0][i-1][j+1]	= geben;
		Field[0][i-1][j-1]	= geben;
		Field[0][i][j]		= geben;
		Field[0][i][j-1]	= geben;
		Field[0][i+1][j-1]	= geben;
		Field[0][i+1][j]	= geben;
	}
}

void set_gleiter_links_oben (unsigned int single_option_representives_inverted, Spielfeld Field, unsigned int geben, unsigned int i, unsigned int j) {
	if (single_option_representives_inverted == 0) {
		Field[0][i-1][j]	= geben;
		Field[0][i+1][j-1]	= geben;
		Field[0][i][j]		= geben;
		Field[0][i][j-1]	= geben;
		Field[0][i+1][j+1]	= geben;
	} else if (single_option_representives_inverted == 1) {
		Field[0][i-1][j]	= geben;
		Field[0][i-1][j+1]	= geben;
		Field[0][i-1][j-1]	= geben;
		Field[0][i][j]		= geben;
		Field[0][i][j+1]	= geben;
		Field[0][i+1][j-1]	= geben;
	}
}

void set_gleiter_oben_rechts (unsigned int single_option_representives_inverted, Spielfeld Field, unsigned int geben, unsigned int i, unsigned int j) {
	if (single_option_representives_inverted == 0) {
		Field[0][i-1][j]	= geben;
		Field[0][i-1][j-1]	= geben;
		Field[0][i][j]		= geben;
		Field[0][i][j+1]	= geben;
		Field[0][i+1][j-1]	= geben;
	} else if (single_option_representives_inverted == 1) {
		Field[0][i-1][j+1]	= geben;
		Field[0][i-1][j-1]	= geben;
		Field[0][i][j]		= geben;
		Field[0][i][j+1]	= geben;
		Field[0][i+1][j+1]	= geben;
		Field[0][i+1][j]	= geben;
	}
}

void set_gleiter_rechts_oben (unsigned int single_option_representives_inverted, Spielfeld Field, unsigned int geben, unsigned int i, unsigned int j) {
	if (single_option_representives_inverted == 0) {
		Field[0][i-1][j]	= geben;
		Field[0][i+1][j+1]	= geben;
		Field[0][i][j]		= geben;
		Field[0][i][j+1]	= geben;
		Field[0][i+1][j-1]	= geben;
	} else if (single_option_representives_inverted == 1) {
		Field[0][i-1][j]	= geben;
		Field[0][i-1][j+1]	= geben;
		Field[0][i-1][j-1]	= geben;
		Field[0][i][j]		= geben;
		Field[0][i][j-1]	= geben;
		Field[0][i+1][j+1]	= geben;
	}
}

void set_gleiter_unten_links (unsigned int single_option_representives_inverted, Spielfeld Field, unsigned int geben, unsigned int i, unsigned int j) {
	if (single_option_representives_inverted == 0) {
		Field[0][i-1][j+1]	= geben;
		Field[0][i][j-1]	= geben;
		Field[0][i][j]		= geben;
		Field[0][i+1][j]	= geben;
		Field[0][i+1][j+1]	= geben;
	} else if (single_option_representives_inverted == 1) {
		Field[0][i-1][j]	= geben;
		Field[0][i-1][j-1]	= geben;
		Field[0][i][j]		= geben;
		Field[0][i][j-1]	= geben;
		Field[0][i+1][j-1]	= geben;
		Field[0][i+1][j+1]	= geben;
	}
}

void set_gleiter_links_unten (unsigned int single_option_representives_inverted, Spielfeld Field, unsigned int geben, unsigned int i, unsigned int j) {
	if (single_option_representives_inverted == 0) {
		Field[0][i-1][j-1]	= geben;
		Field[0][i-1][j+1]	= geben;
		Field[0][i][j]		= geben;
		Field[0][i][j-1]	= geben;
		Field[0][i+1][j]	= geben;
	} else if (single_option_representives_inverted == 1) {
		Field[0][i+1][j]	= geben;
		Field[0][i+1][j+1]	= geben;
		Field[0][i+1][j-1]	= geben;
		Field[0][i][j]		= geben;
		Field[0][i][j+1]	= geben;
		Field[0][i-1][j-1]	= geben;
	}
}

void set_gleiter_unten_rechts (unsigned int single_option_representives_inverted, Spielfeld Field, unsigned int geben, unsigned int i, unsigned int j) {
	if (single_option_representives_inverted == 0) {
		Field[0][i-1][j-1]	= geben;
		Field[0][i][j+1]	= geben;
		Field[0][i][j]		= geben;
		Field[0][i+1][j-1]	= geben;
		Field[0][i+1][j]	= geben;
	} else if (single_option_representives_inverted == 1) {
		Field[0][i-1][j]	= geben;
		Field[0][i-1][j+1]	= geben;
		Field[0][i][j]		= geben;
		Field[0][i][j+1]	= geben;
		Field[0][i+1][j-1]	= geben;
		Field[0][i+1][j+1]	= geben;
	}
}

void set_gleiter_rechts_unten (unsigned int single_option_representives_inverted, Spielfeld Field, unsigned int geben, unsigned int i, unsigned int j) {
	if (single_option_representives_inverted == 0) {
		Field[0][i-1][j-1]	= geben;
		Field[0][i][j+1]	= geben;
		Field[0][i][j]		= geben;
		Field[0][i-1][j+1]	= geben;
		Field[0][i+1][j]	= geben;
	} else if (single_option_representives_inverted == 1) {
		Field[0][i+1][j]	= geben;
		Field[0][i+1][j+1]	= geben;
		Field[0][i+1][j-1]	= geben;
		Field[0][i][j]		= geben;
		Field[0][i][j-1]	= geben;
		Field[0][i-1][j+1]	= geben;
	}
}

void set_triangle_oben_links (unsigned int single_option_representives_inverted, Spielfeld Field, unsigned int geben, unsigned int i, unsigned int j) {	//platziert beim Wachstum, in der angegebenen Ecke
	if ((single_option_representives_inverted == 0)||(single_option_representives_inverted == 1)) {
		Field[0][i][j+1] = geben;
		Field[0][i+1][j] = geben;
		Field[0][i+1][j+1] = geben;
	}
}

void set_triangle_oben_rechts (unsigned int single_option_representives_inverted, Spielfeld Field, unsigned int geben, unsigned int i, unsigned int j) {	//platziert beim Wachstum, in der angegebenen Ecke
	if ((single_option_representives_inverted == 0)||(single_option_representives_inverted == 1)) {
		Field[0][i][j-1] = geben;
		Field[0][i+1][j] = geben;
		Field[0][i+1][j-1] = geben;
	}
}

void set_triangle_unten_rechts (unsigned int single_option_representives_inverted, Spielfeld Field, unsigned int geben, unsigned int i, unsigned int j) {	//platziert beim Wachstum, in der angegebenen Ecke
	if ((single_option_representives_inverted == 0)||(single_option_representives_inverted == 1)) {
		Field[0][i-1][j-1] = geben;
		Field[0][i-1][j] = geben;
		Field[0][i][j-1] = geben;
	}
}

void set_triangle_unten_links (unsigned int single_option_representives_inverted, Spielfeld Field, unsigned int geben, unsigned int i, unsigned int j) {	//platziert beim Wachstum, in der angegebenen Ecke
	if ((single_option_representives_inverted == 0)||(single_option_representives_inverted == 1)) {
		Field[0][i-1][j] = geben;
		Field[0][i-1][j+1] = geben;
		Field[0][i][j+1] = geben;
	}
}

void set_mountain_oben (unsigned int single_option_representives_inverted, Spielfeld Field, unsigned int geben, unsigned int i, unsigned int j) {	//platziert beim Schwerpunkt
	if (single_option_representives_inverted == 0) {
		Field[0][i][j]   = geben;
		Field[0][i-1][j] = geben;
		Field[0][i][j-1] = geben;
		Field[0][i][j+1] = geben;
	} else if (single_option_representives_inverted == 1) {
		Field[0][i][j]		= geben;
		Field[0][i][j-1]	= geben;
		Field[0][i][j+1]	= geben;
		Field[0][i+2][j-1]	= geben;
		Field[0][i+2][j+1]	= geben;
	}
}

void set_mountain_unten (unsigned int single_option_representives_inverted, Spielfeld Field, unsigned int geben, unsigned int i, unsigned int j) {	//platziert beim Schwerpunkt
	if (single_option_representives_inverted == 0) {
		Field[0][i][j] = geben;
		Field[0][i+1][j] = geben;
		Field[0][i][j-1] = geben;
		Field[0][i][j+1] = geben;
	} else if (single_option_representives_inverted == 1) {
		Field[0][i][j]		= geben;
		Field[0][i][j-1]	= geben;
		Field[0][i][j+1]	= geben;
		Field[0][i-2][j-1]	= geben;
		Field[0][i-2][j+1]	= geben;
	}
}

void set_mountain_rechts (unsigned int single_option_representives_inverted, Spielfeld Field, unsigned int geben, unsigned int i, unsigned int j) {	//platziert beim Schwerpunkt
	if (single_option_representives_inverted == 0) {
		Field[0][i][j] = geben;
		Field[0][i][j+1] = geben;
		Field[0][i-1][j] = geben;
		Field[0][i+1][j] = geben;
	} else if (single_option_representives_inverted == 1) {
		Field[0][i][j] = geben;
		Field[0][i-1][j] = geben;
		Field[0][i+1][j] = geben;
		Field[0][i-1][j-2] = geben;
		Field[0][i+1][j-2] = geben;
	}
}

void set_mountain_links (unsigned int single_option_representives_inverted, Spielfeld Field, unsigned int geben, unsigned int i, unsigned int j) {	//platziert beim Schwerpunkt
	if (single_option_representives_inverted == 0) {
		Field[0][i][j] = geben;
		Field[0][i][j-1] = geben;
		Field[0][i-1][j] = geben;
		Field[0][i+1][j] = geben;
	} else if (single_option_representives_inverted == 1) {
		Field[0][i][j] = geben;
		Field[0][i-1][j] = geben;
		Field[0][i+1][j] = geben;
		Field[0][i-1][j+2] = geben;
		Field[0][i+1][j+2] = geben;
	}
}

void set_edge_oben_links (unsigned int single_option_representives_inverted, Spielfeld Field, unsigned int geben, unsigned int i, unsigned int j) {	//platziert beim Schweif
	if ((single_option_representives_inverted == 0)||(single_option_representives_inverted == 1)) {
		Field[0][i][j] = geben;
		Field[0][i+2][j] = geben;
		Field[0][i+2][j+1] = geben;
		Field[0][i+2][j+2] = geben;
		Field[0][i][j+2] = geben;
		Field[0][i+1][j+2] = geben;
	}
}

void set_edge_oben_rechts (unsigned int single_option_representives_inverted, Spielfeld Field, unsigned int geben, unsigned int i, unsigned int j) {	//platziert beim Schweif
	if ((single_option_representives_inverted == 0)||(single_option_representives_inverted == 1)) {
		Field[0][i][j] = geben;
		Field[0][i+2][j] = geben;
		Field[0][i+2][j-1] = geben;
		Field[0][i+2][j-2] = geben;
		Field[0][i][j-2] = geben;
		Field[0][i+1][j-2] = geben;
	}
}

void set_edge_unten_rechts (unsigned int single_option_representives_inverted, Spielfeld Field, unsigned int geben, unsigned int i, unsigned int j) {	//platziert beim Schweif
	if ((single_option_representives_inverted == 0)||(single_option_representives_inverted == 1)) {
		Field[0][i][j] = geben;
		Field[0][i-2][j] = geben;
		Field[0][i-2][j-1] = geben;
		Field[0][i-2][j-2] = geben;
		Field[0][i][j-2] = geben;
		Field[0][i-1][j-2] = geben;
	}
}

void set_edge_unten_links (unsigned int single_option_representives_inverted, Spielfeld Field, unsigned int geben, unsigned int i, unsigned int j) {	//platziert beim Schweif
	if ((single_option_representives_inverted == 0)||(single_option_representives_inverted == 1)) {
		Field[0][i][j] = geben;
		Field[0][i-2][j] = geben;
		Field[0][i-2][j+1] = geben;
		Field[0][i-2][j+2] = geben;
		Field[0][i][j+2] = geben;
		Field[0][i-1][j+2] = geben;
	}
}

void set_star (unsigned int single_option_representives_inverted, Spielfeld Field, unsigned int geben, unsigned int i, unsigned int j) {	//platziert im Zentrum
	if (single_option_representives_inverted == 0) {
		Field[0][i][j] = geben;
		Field[0][i-1][j] = geben;
		Field[0][i][j+1] = geben;
		Field[0][i][j-1] = geben;
		Field[0][i+1][j] = geben;
	} else if (single_option_representives_inverted == 1) {
		Field[0][i][j] = geben;
		Field[0][i-1][j-1] = geben;
		Field[0][i-1][j+1] = geben;
		Field[0][i+1][j-1] = geben;
		Field[0][i+1][j+1] = geben;
	}
}

void set_net_basic_two_four (unsigned int single_option_representives_inverted, Spielfeld Field, unsigned int geben, unsigned int i, unsigned int j) {	//platziert im Zentrum oben links
	if ((single_option_representives_inverted == 0)||(single_option_representives_inverted == 1)) {
		// Field[0][i][j] = geben;	//Dead with number 5
		Field[0][i-1][j-1] = geben;
		Field[0][i][j+1] = geben;
		Field[0][i+1][j] = geben;
		Field[0][i+1][j+1] = geben;
		Field[0][i-1][j+2] = geben;
		Field[0][i+2][j-1] = geben;
		Field[0][i+2][j+2] = geben;
	}
}

void set_f_links_oben (unsigned int single_option_representives_inverted, Spielfeld Field, unsigned int geben, unsigned int i, unsigned int j) {	//platziert im Zentrum, links Wachstum, oben Anhängsel
	if (single_option_representives_inverted == 0) {
		Field[0][i][j] = geben;
		Field[0][i][j-1] = geben;
		Field[0][i-1][j+1] = geben;
		Field[0][i-1][j] = geben;
		Field[0][i+1][j] = geben;
	} else if (single_option_representives_inverted == 1) {
		Field[0][i][j] = geben;
		Field[0][i][j-1] = geben;
		Field[0][i-1][j+1] = geben;
		Field[0][i-1][j] = geben;
		Field[0][i+1][j] = geben;
		Field[0][i-1][j-1] = geben;
	}
}

void set_f_oben_rechts (unsigned int single_option_representives_inverted, Spielfeld Field, unsigned int geben, unsigned int i, unsigned int j) {
	if (single_option_representives_inverted == 0) {
		Field[0][i][j] = geben;
		Field[0][i][j-1] = geben;
		Field[0][i][j+1] = geben;
		Field[0][i-1][j] = geben;
		Field[0][i+1][j+1] = geben;
	} else if (single_option_representives_inverted == 1) {
		Field[0][i][j] = geben;
		Field[0][i][j-1] = geben;
		Field[0][i][j+1] = geben;
		Field[0][i-1][j] = geben;
		Field[0][i+1][j+1] = geben;
		Field[0][i-1][j+1] = geben;
	}
}

void set_f_rechts_unten (unsigned int single_option_representives_inverted, Spielfeld Field, unsigned int geben, unsigned int i, unsigned int j) {
	if (single_option_representives_inverted == 0) {
		Field[0][i][j] = geben;
		Field[0][i][j+1] = geben;
		Field[0][i-1][j] = geben;
		Field[0][i+1][j] = geben;
		Field[0][i+1][j-1] = geben;
	} else if (single_option_representives_inverted == 1) {
		Field[0][i][j] = geben;
		Field[0][i][j+1] = geben;
		Field[0][i-1][j] = geben;
		Field[0][i+1][j] = geben;
		Field[0][i+1][j-1] = geben;
		Field[0][i+1][j+1] = geben;
	}
}

void set_f_oben_links (unsigned int single_option_representives_inverted, Spielfeld Field, unsigned int geben, unsigned int i, unsigned int j) {
	if (single_option_representives_inverted == 0) {
		Field[0][i][j] = geben;
		Field[0][i][j-1] = geben;
		Field[0][i][j+1] = geben;
		Field[0][i-1][j] = geben;
		Field[0][i+1][j-1] = geben;
	} else if (single_option_representives_inverted == 1) {
		Field[0][i][j] = geben;
		Field[0][i][j-1] = geben;
		Field[0][i][j+1] = geben;
		Field[0][i-1][j] = geben;
		Field[0][i+1][j-1] = geben;
		Field[0][i-1][j-1] = geben;
	}
}

