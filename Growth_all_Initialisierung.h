
#ifndef GROWTH_ALL_INITIALISIERUNG_H
#define GROWTH_ALL_INITIALISIERUNG_H

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

void Initialisierung (unsigned int, unsigned int*);


unsigned int Initialisierung_limits_at_all (unsigned int);	//checklist
unsigned int Initialisierung_limits_yeni (unsigned int);	//checklist


unsigned int Initialisierung_m (unsigned int);	//checklist
unsigned int Initialisierung_n (unsigned int);	//checklist


void unsigned_int_array_null_initialisierung (unsigned int*, unsigned int);
void int_array_null_initialisierung (int*, unsigned int);


void Initialisierung_Arrays_1 (unsigned int, unsigned int*, unsigned int*, unsigned int*);
void Initialisierung_Arrays_2 (unsigned int, unsigned int*, unsigned int*, unsigned int*, unsigned int*, unsigned int*, unsigned int*, unsigned int*, unsigned int*);

void Duell_specials_Initialisation (Duell_Specials*, unsigned int);
void Initialisierung_Duell_abilities (unsigned int**);

void start_normal (Spielfeld, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, Spielfeld, Special_Fields_Collector*, unsigned int);	//checklist


#endif