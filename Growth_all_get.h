
#ifndef GROWTH_ALL_GET_H
#define GROWTH_ALL_GET_H

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


unsigned int get_m (unsigned int, unsigned int);
unsigned int get_n (unsigned int, unsigned int);


unsigned int get_unsigned_numeric_input_with_not_more_than_3_letters ();
unsigned int get_unsigned_numeric_input_with_not_more_than_2_letters ();
unsigned int split_unsigned_numeric_input_with_letters_4 (unsigned int, unsigned int);
unsigned int get_unsigned_numeric_input_with_not_more_than_1_letter ();
unsigned int get_unsigned_numeric_input_with_not_more_than_letters_4_for_splitting ();
unsigned int split_unsigned_numeric_input_with_letters_2 (unsigned int, unsigned int);
unsigned int get_unsigned_numeric_input_with_not_more_than_letters_2_for_splitting ();


int get_signed_numeric_input_with_not_more_than_1_letter ();


#endif