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

void Square_color_interpretation (Growth_Player*, unsigned int, unsigned int, unsigned int);
void get_colors (Growth_Player*, unsigned int, unsigned int, unsigned int);

void set_terminal_color (Color);
void set_player_color (Growth_Player*, unsigned int, Color);

void opague_builder (Spielfeld, Special_Fields, unsigned int, unsigned int, unsigned int, unsigned int, Special_Fields, unsigned int, unsigned int);
unsigned int list_of_possible_Field_values_from_one_to_ninethousand(unsigned int, unsigned int);	//checklist

#endif