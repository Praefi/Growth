
#ifndef GROWTH_ALL_ACTIONS_H
#define GROWTH_ALL_ACTIONS_H

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

void Plus (unsigned int*, Spielfeld, unsigned int, unsigned int, unsigned int, Spielfeld, unsigned int, unsigned int, unsigned int*, unsigned int, Growth_Player*, Special_Fields, Special_Fields_Collector*, Single_option_representives);	//checklist
void Minus (unsigned int*, Spielfeld, unsigned int, unsigned int, unsigned int, Spielfeld, unsigned int, unsigned int*, Growth_Player*, Special_Fields, Special_Fields_Collector*, unsigned int, Single_option_representives);	//checklist


void Move (unsigned int*, Spielfeld, unsigned int, unsigned int, unsigned int, Spielfeld, unsigned int, unsigned int*, Growth_Player*, Special_Fields, Special_Fields_Collector*, unsigned int, Single_option_representives);	//checklist


void Change (unsigned int*, Spielfeld, unsigned int, unsigned int, unsigned int, Spielfeld, unsigned int, unsigned int*, Growth_Player*, Special_Fields, unsigned int*, Special_Fields_Collector*, unsigned int, Single_option_representives);	//checklist


void Destroy (unsigned int*, Spielfeld, unsigned int, unsigned int, unsigned int, Spielfeld, unsigned int, unsigned int*, Growth_Player*, Special_Fields, Special_Fields_Collector*, unsigned int, Single_option_representives);	//checklist


void Revive (Spielfeld, unsigned int, unsigned int, Spielfeld, Spielfeld, unsigned int, Special_Fields_Collector*, Spielfeld, unsigned int, unsigned int);	//checklist


void Boost (Spielfeld, unsigned int, Spielfeld, unsigned int, unsigned int, Spielfeld, unsigned int, Spielfeld, Special_Fields_Collector*, unsigned int);	//checklist


#endif