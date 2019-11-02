
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

void About_the_game (unsigned int gamemode_played, unsigned int geben, Limits limits, unsigned int number_of_players, unsigned int freq, unsigned int w, unsigned int d, unsigned int e) {	//checklist

	if (gamemode_played == Classic) {
		printf("	How to win?   Own a square on your last line or force your opponents to lose all his/her ones.\n");
	} else if (gamemode_played == Collect) {
		printf("	How to win?   Be at 2 of the 3 targets with three of your squares near-by.\n");
	} else if (gamemode_played == Contact) {
		printf("	How to win?   Take over all your opponents' squares by winning Contact-battles.\n");
		printf("	Contact-battles?  All near-by squares in a row with the Contact-square build a chain, beat your opponents in the length.\n");
	} else if (gamemode_played == Fall) {
		printf("	How to win?   Get more points than your opponents.\n");
		printf("	Note:	Touch the #-square in the near-by to move it to the opposite side of touch. \n");
	} else if ((gamemode_played == Fight)||(gamemode_played == Duell)) {
		printf("	How to win?   Force your opponents to lose all his/her squares.\n");
	} else if (gamemode_played == Hunt) {
		if (geben == 1) {
			printf("	How to win?   Protect your heart-block in a way that no enemy can touch it.\n");
		} else {
			printf("	How to win?   Touch the heart-block of the hunted one before it disappears.\n");
		}
	} else if (gamemode_played == Race) {
		printf("	How to win?   Reach the end of the field or force your opponents to lose all his/her ones.\n");
		printf("	Note:	Every %u turn(s) in total the #-line will go ahead and destroys everything in it's way.\n Also you are not allowed to cross the mid-line. \n", freq);
	} else if (gamemode_played == Rain) {
		printf("	How to win?   Reach [1][7]");
		for (unsigned int p=2; p<=number_of_players; p++) {
			printf(" or [1][%u]", (p-1)*7);
		}
		printf(" of the field or force your opponents to lose all his/her squares.\n");
		printf("	Note:	Falling down the #-squares will push, destroy, explode, or teleport, transform into yours by contact. \n");
	} else if ((gamemode_played == Arena)||(gamemode_played == Ulcer)) {	//10
		printf("	How to win?   Force your opponents to lose all his/her squares while keeping yours alive by using your special abilities.\n");
	} else if (gamemode_played == Dynamic) {
		printf("	How to win?   Push the ball towards your opponent's side.\n");
	} else if (gamemode_played == Survive) {
		printf("	How to win?   Stay alive by avoiding traps, waves and bombs.\n");
	} else if (gamemode_played == Sand) {
		printf("	How to win?   Reach the topline, your squares keep falling.\n");
	} else if (gamemode_played == Quidditch) {
		printf("	How to win?   Get more points as your opponent. Every goal with a Quaffel worths 10 points, catching the Schnatz gives you 150 points and ends the game.\n");
		printf("	Note:	Teammembers can move through changing position with one of your squares in its reach.\n	In the Near-by of objects, no living square is going to die.\n	In the Near-by of a Jaeger/Hueter the Quaffel is possessed and follows the movements of it's owner or can be thrown.\n	Passing this area the Quaffel stops during it's throw.\n \n If a Sucher flys through the Schnatz, it is caught.\n \n	If a Klatscher hits a target, the position of the target will change.\n ");
	}
	printf("	Surrounding:	The 8 squares around another, at the edge 5, in the corners 3, are called #surrounding. \n");
	printf("	near-by:	The 4 squares around another, at the edge 3, in the corners 2, are called #near-by. \n");
	printf("	Standard actions:	(After your choice of number and not influencing each other) \n	-Development:	If it is your turn and a free square has exactly %u of yours surrounding it, you will own it.\n", w);
	printf("	-Losses:  If it is your turn and a square of yours is surrounded by less than %u or more than %u of yours,\n			it will be set free.\n", d, e);	//10
	if ((gamemode_played == Hunt)&&(geben == 1)) {	//If geben == 1
		printf("	Limits:   Your development is limited by %u per round, your units in total by %u per round. \n", (limits.new+(number_of_players-3)), (limits.at_all+(2*(number_of_players-3))));
	} else if ((gamemode_played == Ulcer)||(gamemode_played == Survive)) {
		printf("	Limits:   This gamemode is unlimited. \n");
	} else if (gamemode_played == Contact) {
		printf("	Limits:   Your development is limited by %u per round. \n", limits.new);
	} else {
		printf("	Limits:   Your development is limited by %u per round, your units in total by %u per round. \n", limits.new, limits.at_all);
	}

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
