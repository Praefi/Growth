
#ifndef GROWTH_ALL_SHOW_H
#define GROWTH_ALL_SHOW_H

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

void show_field (unsigned int, unsigned int, unsigned int*, Spielfeld, Spielfeld, Spielfeld, unsigned int, unsigned int, unsigned int, unsigned int*, unsigned int, Growth_Player*, unsigned int, Special_Fields_Collector*);	//checklist

void Nummerierung_show_field (unsigned int, unsigned int, unsigned int, unsigned int);


void show_whose_turn (unsigned int, unsigned int, unsigned int*, Growth_Player*, unsigned int*, unsigned int);
void show_statistics (unsigned int, unsigned int, Spielfeld, unsigned int*, unsigned int, unsigned int*, unsigned int*, unsigned int*, unsigned int*, unsigned int, Quidditch_setup*);	//checklist
void show_options_of_actions (unsigned int, unsigned int*, unsigned int);
void show_the_numbers (unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);


void show_figures ();


void show_abilities (unsigned int*);








#endif