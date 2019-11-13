
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

Spielfeld Spielfeld_Create (unsigned int m, unsigned int n, unsigned int number_of_players) {
	Spielfeld Spiel;

	// printf("Checkpoint: Start of Spielfeld_Create	\n ");	//test

	Spiel = calloc(number_of_players+1, sizeof(unsigned int**));

	if (Spiel == NULL) {
		printf("	Kein freier Speicher wurde gefunden! \n ");
	}

	// printf("Checkpoint: 1st step of Spielfeld_Create	\n ");	//test

	for (unsigned int geben=0; geben<=number_of_players; geben+=1) {	//geben und i, um zugehörigkeit zu verdeutlichen

		// printf("Checkpoint: 1.5nd step of Spielfeld_Create	\n ");	//test

		Spiel[geben] = calloc(m, sizeof(unsigned int*));

		// printf("Checkpoint: 2nd step of Spielfeld_Create	\n ");	//test

		for (unsigned int i=0; i<m; i+=1) {
			Spiel[geben][i] = calloc(n, sizeof(unsigned int));

			// printf("Checkpoint: 3rd step of Spielfeld_Create	\n ");	//test

		}

	}
		// Spiel = calloc(1, sizeof(unsigned int**));
		// printf("	1. \n");
		// Spiel[0] = calloc(1, sizeof(unsigned int*));
		// printf("	2. \n");
		// Spiel[0][0] = calloc(1, sizeof(unsigned int*));
		// printf("	3. \n");


	Spielfeld_counter += 1;

	return Spiel;
}

Moveable_objects_condition* Moveable_objects_condition_Vektor_Create (unsigned int length) {
	Moveable_objects_condition* Vektor;
	Vektor = calloc(length, sizeof(Moveable_objects_condition));

	Vektor_counter += 1;

	return Vektor;
}

Special_Fields_Collector* Special_Fields_Collector_Vektor_Create (unsigned int length) {
	Special_Fields_Collector* Vektor;
	Vektor = calloc(length, sizeof(Special_Fields_Collector));

	Vektor_counter += 1;
	
	return Vektor;
}

Realize_modifications_variables* Realize_modifications_variables_Vektor_Create (unsigned int length) {
	Realize_modifications_variables* Vektor;
	Vektor = calloc(length, sizeof(Realize_modifications_variables));

	Vektor_counter += 1;
	
	return Vektor;
}

Quidditch_team_abilities* Quidditch_team_abilities_Vektor_Create (unsigned int length) {
	Quidditch_team_abilities* Vektor;
	Vektor = calloc(length, sizeof(Quidditch_team_abilities));

	Vektor_counter += 1;
	
	return Vektor;
}

Quidditch_object_abilities* Quidditch_object_abilities_Vektor_Create (unsigned int length) {
	Quidditch_object_abilities* Vektor;
	Vektor = calloc(length, sizeof(Quidditch_object_abilities));

	Vektor_counter += 1;
	
	return Vektor;
}

Quidditch_setup* Quidditch_setup_Vektor_Create (unsigned int length) {
	Quidditch_setup* Vektor;
	Vektor = calloc(length, sizeof(Quidditch_setup));

	Vektor_counter += 1;
	
	return Vektor;
}

unsigned int* unsigned_int_Vektor_Create (unsigned int length) {
	unsigned int* Vektor;
	Vektor = calloc(length, sizeof(unsigned int));

	Vektor_counter += 1;

	return Vektor;
}

int* int_Vektor_Create (unsigned int length) {
	int* Vektor;
	Vektor = calloc(length, sizeof(int));

	Vektor_counter += 1;

	return Vektor;
}

int** int_2dim_Vektor_Create (unsigned int m, unsigned int n) {
	int** Vektor;
	Vektor = calloc(m, sizeof(int*));

	for (unsigned int p=0; p<m; p+=1) {
		Vektor[p] = calloc(n, sizeof(int));
	}

	Vektor_counter += 1;

	return Vektor;
}

unsigned int** unsigned_int_2dim_Vektor_Create (unsigned int m, unsigned int n) {
	unsigned int** Vektor;
	Vektor = calloc(m, sizeof(unsigned int*));

	for (unsigned int p=0; p<m; p+=1) {
		Vektor[p] = calloc(n, sizeof(unsigned int));
	}

	Vektor_counter += 1;

	return Vektor;
}

void Moveable_objects_condition_Vektor_Destroy (Moveable_objects_condition* Vektor) {
	
	free(Vektor);
	Vektor = NULL;

	Vektor_counter -= 1;
}

void Quidditch_team_abilities_Vektor_Destroy (Quidditch_team_abilities* Vektor) {
	
	free(Vektor);
	Vektor = NULL;

	Vektor_counter -= 1;
}

void Quidditch_object_abilities_Vektor_Destroy (Quidditch_object_abilities* Vektor) {
	
	free(Vektor);
	Vektor = NULL;

	Vektor_counter -= 1;
}

void Quidditch_setup_Vektor_Destroy (Quidditch_setup* Vektor) {
	
	free(Vektor);
	Vektor = NULL;

	Vektor_counter -= 1;
}

void int_2dim_Vektor_Destroy (int** Vektor, unsigned int m) {

	for (unsigned int p=0; p<m; p+=1) {
		free(Vektor[p]);
		// Vektor[p] = NULL;
	}

	free(Vektor);
	Vektor = NULL;

	Vektor_counter -= 1;
}

void unsigned_int_2dim_Vektor_Destroy (unsigned int** Vektor, unsigned int m) {

	for (unsigned int p=0; p<m; p+=1) {
		free(Vektor[p]);
		// Vektor[p] = NULL;
	}

	free(Vektor);
	Vektor = NULL;

	Vektor_counter -= 1;
}

void int_Vektor_Destroy (int* Vektor) {
	free(Vektor);
	Vektor = NULL;

	Vektor_counter -= 1;
}

void unsigned_int_Vektor_Destroy (unsigned int* Vektor) {
	free(Vektor);
	Vektor = NULL;

	Vektor_counter -= 1;
}

void Realize_modifications_variables_Vektor_Destroy (Realize_modifications_variables* Vektor) {
	free(Vektor);
	Vektor = NULL;

	Vektor_counter -= 1;
}

void Special_Fields_Collector_Vektor_Destroy (Special_Fields_Collector* Vektor) {
	free(Vektor);
	Vektor = NULL;

	Vektor_counter -= 1;
}

void Spielfeld_Destroy (Spielfeld Spiel, unsigned int m, unsigned int number_of_players){
	for (unsigned int geben=number_of_players+1; geben>0; geben-=1) {	//number_of_players, geben, i, j dienen nur zur Anschauung

		// printf("	Spielfeld_Destroy #1 \n");	//test

		for (unsigned int i=m; i>0; i-=1){
			free(Spiel[geben-1][i-1]);
			// Spiel[geben-1][i-1] = NULL;
		}

		// printf("	Spielfeld_Destroy #2 \n");	//test

	}
	for (unsigned int geben=number_of_players+1; geben>0; geben-=1) {	//Having_too_much-Verschiebung
		free(Spiel[geben-1]);
		//Spiel[geben-1] = NULL;
	}

	// printf("	Spielfeld_Destroy #3 \n");	//test

	free(Spiel);
	Spiel = NULL;		//nach testen auf andere Versionen übertragen!

	// printf("	Spielfeld_Destroy #4 \n");	//test

	Spielfeld_counter -= 1;
}
