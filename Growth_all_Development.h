
#ifndef GROWTH_ALL_DEVELOPMENT_H
#define GROWTH_ALL_DEVELOPMENT_H

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

void basic_development (Spielfeld, Spielfeld, unsigned int, unsigned int, unsigned int, Spielfeld, Special_Fields_Collector*, Spielfeld, unsigned int*, Growth_Player*, unsigned int, unsigned int, unsigned int*, unsigned int*, unsigned int, unsigned int, unsigned int, unsigned int, Evolution, Num_num*, unsigned int*, Special_Fields, Limits, Single_option_representives, Special_Fields, unsigned int*, unsigned int*, unsigned int, unsigned int);

void new_life (Spielfeld, Spielfeld, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int*, unsigned int, Evolution, Spielfeld, Special_Fields_Collector*, unsigned int);	//checklist
void old_dying (Spielfeld, Spielfeld, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int*, unsigned int, Spielfeld, unsigned int, Special_Fields_Collector*, Spielfeld, unsigned int, Special_Fields);	//checklist


void change (Spielfeld, unsigned int*, Spielfeld, Spielfeld, Evolution, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int*, unsigned int, Special_Fields_Collector*, Spielfeld, unsigned int*, Growth_Player*, Single_option_representives, Special_Fields);


void Having_too_much (unsigned int*, unsigned int, unsigned int, unsigned int, unsigned int, Evolution, Limits, unsigned int, Spielfeld, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int*, unsigned int, unsigned int, unsigned int, Spielfeld, Special_Fields_Collector*, unsigned*, unsigned int);	//checklist

#endif