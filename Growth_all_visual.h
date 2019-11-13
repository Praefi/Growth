#ifndef GROWTH_VISUAL_H
#define GROWTH_VISUAL_H

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

void Square_color_interpretation (Growth_Player*, unsigned int, unsigned int, unsigned int);
void get_colors (Growth_Player*, unsigned int, unsigned int, unsigned int);

void set_terminal_color (Color);
void set_player_color (Growth_Player*, unsigned int, Color);

#endif