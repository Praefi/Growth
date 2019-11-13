
#ifndef GROWTH_ALL_OPTIONS_SPECIALS_H
#define GROWTH_ALL_OPTIONS_SPECIALS_H

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

// #define VERBOSE
// #define Contact_mistake_search
// #define Quidditch_mistake_search

#ifdef _WIN32
#include <windows.h>
#endif

void realize_modifications (Quidditch_setup*, Moveable_objects_condition*, Moveable_objects_condition*, Moveable_objects_condition*, Spielfeld, Spielfeld, Special_Fields, Special_Fields_Collector*, Spielfeld, unsigned int*, unsigned int*, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int*, unsigned int*, Growth_Player*, Special_Fields, unsigned int, Single_option_representives, Realize_modifications_variables*, Limits, unsigned int);


void figure_check (Spielfeld, unsigned int, unsigned int, unsigned int, Growth_Player*, Special_Fields_Collector*, Spielfeld, unsigned int, unsigned int);


void inverted_organism (Spielfeld, unsigned int*, Spielfeld, Spielfeld, unsigned int, Spielfeld, unsigned int, Special_Fields_Collector*, unsigned int, unsigned int, unsigned int, unsigned int*, Growth_Player*, Single_option_representives);
void find_edges_of_organism_2dim (unsigned int*, Spielfeld, unsigned int, unsigned int, unsigned int);


void addition_maker (Spielfeld, unsigned int, unsigned int, unsigned int, unsigned int, Spielfeld, unsigned int, Special_Fields_Collector*, unsigned int*);
void projection_maker (Spielfeld, unsigned int, unsigned int, Spielfeld, unsigned int, Special_Fields_Collector*, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
void assassin_maker (unsigned int, Spielfeld, unsigned int*, Spielfeld, Spielfeld, unsigned int, Special_Fields, unsigned int, Special_Fields_Collector*, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int*, Growth_Player*, Single_option_representives);
void avalanche_maker (Spielfeld, Spielfeld, Spielfeld, Special_Fields_Collector*, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
void spreading_maker (Spielfeld, Spielfeld, Spielfeld, Special_Fields_Collector*, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
void permutations_permutate_maker (Spielfeld, Spielfeld, unsigned int, unsigned int, unsigned int**, unsigned int, unsigned int, Spielfeld, unsigned int, Special_Fields_Collector*);
void Partition_compare_maker (Spielfeld, unsigned int, unsigned int, Spielfeld, unsigned int, Spielfeld, Special_Fields_Collector*, unsigned int, unsigned int);

void translate_permutations_amounts_to_permutations_areas (Spielfeld, unsigned int, unsigned int, Collector);


unsigned int random_number (Num_num, unsigned int, unsigned int, unsigned int*, unsigned int*);


void ges0_reset_and_counter (unsigned int*, unsigned int);


void get_two_amounts_for_permutations (unsigned int*, unsigned int*, unsigned int, unsigned int, unsigned int, unsigned int);


void get_sigmas_for_permutation_number (unsigned int**, unsigned int);


#endif