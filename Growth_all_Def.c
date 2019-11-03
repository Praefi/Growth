
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#ifdef _WIN32
#include <windows.h>
#endif


#include "Growth_all_Def.h"

// #define VERBOSE
// #define Contact_mistake_search
// #define Quidditch_mistake_search


unsigned int minimum (unsigned int a, unsigned int b) {
	unsigned int ruckgabe;
	ruckgabe = 0;

	if (a>=b) {
		ruckgabe = b;
	} else {
		ruckgabe = a;
	}

	return ruckgabe;
}

unsigned int maximum (unsigned int a, unsigned int b) {
	unsigned int ruckgabe;
	ruckgabe = 0;

	if (a>=b) {
		ruckgabe = a;
	} else {
		ruckgabe = b;
	}

	return ruckgabe;
}

unsigned int Fakultaet (unsigned int wert) {
	unsigned int ruckgabe;
	ruckgabe = 1;

	for (unsigned int p=1; p<=wert; p++) {
		ruckgabe *= p;
	}

	// printf("Fakultaet(%u) = %u \n", wert, ruckgabe);	//test

	return ruckgabe;
}

unsigned int Vorganger (unsigned int geben, unsigned int number_of_players) {
	unsigned int vorher;
	vorher = 0;

	if (geben == 1) {
		vorher = number_of_players;
	} else {
		vorher = geben - 1;
	}

	return vorher;
}

unsigned int Nachfolger (unsigned int geben, unsigned int number_of_players) {
	unsigned int nachher;
	nachher = 0;

	nachher = (geben%number_of_players) + 1;

	return nachher;
}


void ges_counter (Spielfeld Field, unsigned int m, unsigned int n, unsigned int* ges, unsigned int number_of_players) {
	for (unsigned int i=1; i<m-1; i+=1){
		for (unsigned int j=1; j<n-1; j+=1){
			for (unsigned int p=1; p<=number_of_players; p+=1) {
				if ((Field[0][i][j] == p)&&(ges[p] < 1010*p)) {
					ges[p] += 1;
					break;
				}
			}
		}
	}
}

void who_is_out (unsigned int* ges, unsigned int number_of_players, Realize_modifications_variables* rmv) {

	for (unsigned int p=1; p<=number_of_players; p++) {
		if ((ges[p] == 0)&&(number_of_players >= p)) {	//second cause obviously?
			printf("		Spieler %u, you are out. \n", p);
			rmv->player_counter += 1;
			ges[p] = 1010*p;
		}
	}
	printf("\n");
}

void reset_of_ges (unsigned int* ges, unsigned int number_of_players) {
	for (unsigned int p=1; p<=number_of_players; p++) {
		if (ges[p] < p*1010) {
			ges[p] = 0;
		}
	}
}


unsigned int Zufall (unsigned int start, unsigned int amount) {
	unsigned int number, counter, scout;
	time_t time_of_calling_Zufall;
	double time_difference;
	
	number = 0;
	counter = 0;
	scout = 1;
	time_of_calling_Zufall = time(NULL);
	time_difference = difftime(time_of_calling_Zufall, time_of_the_start);
	
	// printf("	Zufall: time_differnce: %f \n", time_difference); // test
	// printf("	Zufall: time_of_calling_Zufall: %lu \n", time_of_calling_Zufall); // test
	// printf("	Zufall: time_of_the_start: %lu \n", time_of_the_start); // test
	
	if (time_difference < 0.0) {
		printf("	Error: The timedifference is negative! \n");
	}
	
	while (time_difference >= 1.0) {
		if (time_difference >= 1.0*scout) {
			time_difference -= 1.0*scout;
			counter += scout;
			scout *= 2;
		} else {
			scout = scout/2;
		}
	}
	
	// printf("	Zufall: counter: %u \n", counter); // test
	
	number = ((counter + rand())%amount)+start;
	
	return number;
}
