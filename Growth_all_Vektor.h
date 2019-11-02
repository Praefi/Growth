
#ifndef GROWTH_ALL_VEKTOR_H
#define GROWTH_ALL_VEKTOR_H

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#ifdef _WIN32
#include <windows.h>
#endif

Spielfeld Spielfeld_Create (unsigned int, unsigned int, unsigned int);		//mxn, m >= 6 (+2), n gerade, n >= 4 (+2)		Original: m = 10 (+2), n = 6 (+2)


unsigned int* unsigned_int_Vektor_Create (unsigned int);
int* int_Vektor_Create (unsigned int);
int** int_2dim_Vektor_Create (unsigned int, unsigned int);
unsigned int** unsigned_int_2dim_Vektor_Create (unsigned int, unsigned int);
Moveable_objects_condition* Moveable_objects_condition_Vektor_Create (unsigned int);
Realize_modifications_variables* Realize_modifications_variables_Vektor_Create (unsigned int);
Quidditch_team_abilities* Quidditch_team_abilities_Vektor_Create (unsigned int);
Quidditch_object_abilities* Quidditch_object_abilities_Vektor_Create (unsigned int);
Quidditch_setup* Quidditch_setup_Vektor_Create (unsigned int);


void Spielfeld_Destroy (Spielfeld, unsigned int, unsigned int);


void unsigned_int_Vektor_Destroy (unsigned int*);
void int_Vektor_Destroy (int*);
void int_2dim_Vektor_Destroy (int**, unsigned int);
void unsigned_int_2dim_Vektor_Destroy (unsigned int**, unsigned int);
void Moveable_objects_condition_Vektor_Destroy (Moveable_objects_condition*);
void Realize_modifications_variables_Vektor_Destroy (Realize_modifications_variables*);
void Quidditch_team_abilities_Vektor_Destroy (Quidditch_team_abilities*);
void Quidditch_object_abilities_Vektor_Destroy (Quidditch_object_abilities*);
void Quidditch_setup_Vektor_Destroy (Quidditch_setup*);


#endif