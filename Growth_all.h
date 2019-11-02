
#ifndef GROWTH_ALL_H
#define GROWTH_ALL_H

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

void playing_a_game (unsigned int*, unsigned int*, unsigned int, time_t, unsigned int*, unsigned int, Quidditch_setup*);

#endif
