#ifndef GROWTH_OPAGUE_H
#define GROWTH_OPAGUE_H

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

void Opague_show_controll (unsigned int*, Spielfeld, Special_Fields, unsigned int, unsigned int, unsigned int, unsigned int, Special_Fields_Collector*, unsigned int, unsigned int, unsigned int, Spielfeld, unsigned int*, Growth_Player*);
void opague_builder (Spielfeld, Special_Fields, unsigned int, unsigned int, unsigned int, unsigned int, Special_Fields_Collector*, unsigned int, unsigned int);
unsigned int list_of_possible_Field_values_from_one_to_ninethousand(unsigned int, unsigned int);	//checklist

#endif