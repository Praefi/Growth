
#ifndef GROWTH_ALL_KI_H
#define GROWTH_ALL_KI_H

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

void synchronisation_Field_copy (Spielfeld, Spielfeld, unsigned int, unsigned int, unsigned int, unsigned int, Spielfeld, unsigned int, Special_Fields_Collector*);
void reset_Field_copy (Spielfeld, Spielfeld, Spielfeld, unsigned int, unsigned int, unsigned int, unsigned int, Spielfeld, unsigned int, Special_Fields_Collector*);


void synchronisation_ges_copy (unsigned int*, unsigned int, unsigned int*);
void reset_ges_copy (unsigned int*, unsigned int*, unsigned int);
void ges_others_counter (unsigned int*, unsigned int*, unsigned int, unsigned int);


void turn_of_KI_random (Quidditch_setup*, Moveable_objects_condition*, Moveable_objects_condition*, Moveable_objects_condition*, unsigned int*, Spielfeld, unsigned int, unsigned int, unsigned int, Special_Fields, Special_Fields_Collector*, Spielfeld, unsigned int*, Growth_Player*, unsigned int, unsigned int, unsigned int* , unsigned int*, Limits, Single_option_representives, unsigned int, Realize_modifications_variables*, Special_Fields);
void fill_KI_table_of_choice (Quidditch_setup*, Moveable_objects_condition*, Moveable_objects_condition*, Moveable_objects_condition*, unsigned int*, Spielfeld, Spielfeld, unsigned int, unsigned int, unsigned int, Special_Fields, Special_Fields_Collector*, Spielfeld, unsigned int*, Growth_Player*, unsigned int, unsigned int, unsigned int*, unsigned int*, unsigned int*, unsigned int*, Limits, Single_option_representives, unsigned int, Realize_modifications_variables*, Special_Fields);
void set_KI_table_of_choice (Quidditch_setup*, Moveable_objects_condition*, Moveable_objects_condition*, Moveable_objects_condition*, unsigned int*, Spielfeld, Spielfeld, unsigned int, unsigned int, unsigned int, Special_Fields, Special_Fields_Collector*, Spielfeld, unsigned int*, Growth_Player*, unsigned int, unsigned int, unsigned int*, unsigned int*, unsigned int*, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int*, Limits, Single_option_representives, unsigned int, Realize_modifications_variables*, Special_Fields);
void update_KI_table_of_choice (unsigned int*, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int*, unsigned int, unsigned int, unsigned int*, unsigned int, unsigned int, unsigned int*, unsigned int);


void decision_max_maker (unsigned int, unsigned int, unsigned int*);	//checklist

unsigned int get_how_many_ways_of_keeping (unsigned int);	//checklist

unsigned int accepted_or_not (unsigned int, unsigned int*, unsigned int, unsigned int);

void dimension_of (unsigned int*, unsigned int*, unsigned int);

void is_it_necessary (unsigned int*, unsigned int*, unsigned int*, unsigned int, unsigned int);


#endif