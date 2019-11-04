
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

void Initialisierung (unsigned int, unsigned int*);


unsigned int Initialisierung_limits_at_all (unsigned int);	//checklist
unsigned int Initialisierung_limits_new (unsigned int);	//checklist


unsigned int Initialisierung_m (unsigned int);	//checklist
unsigned int Initialisierung_n (unsigned int);	//checklist


void unsigned_int_array_null_initialisierung (unsigned int*, unsigned int);
void int_array_null_initialisierung (int*, unsigned int);


void Initialisierung_Arrays_1 (unsigned int, unsigned int*, unsigned int*, unsigned int*);
void Initialisierung_Arrays_2 (unsigned int, unsigned int*, unsigned int*, unsigned int*, unsigned int*, unsigned int*, unsigned int*, unsigned int*, unsigned int*);



void start_normal (Spielfeld, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, Spielfeld, Special_Fields, unsigned int);	//checklist


#endif