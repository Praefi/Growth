
#ifndef GROWTH_ALL_SET_H
#define GROWTH_ALL_SET_H

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


void set_Spielfeld_Eintrag (Spielfeld, unsigned int, Spielfeld, unsigned int, Special_Fields_Collector*, unsigned int, Spielfeld, unsigned int, unsigned int, unsigned int, unsigned int);


void set_gleiter_oben_links (unsigned int, Spielfeld, unsigned int, unsigned int, unsigned int);
void set_gleiter_links_oben (unsigned int, Spielfeld, unsigned int, unsigned int, unsigned int);
void set_gleiter_oben_rechts (unsigned int, Spielfeld, unsigned int, unsigned int, unsigned int);
void set_gleiter_rechts_oben (unsigned int, Spielfeld, unsigned int, unsigned int, unsigned int);
void set_gleiter_unten_links (unsigned int, Spielfeld, unsigned int, unsigned int, unsigned int);
void set_gleiter_links_unten (unsigned int, Spielfeld, unsigned int, unsigned int, unsigned int);
void set_gleiter_unten_rechts (unsigned int, Spielfeld, unsigned int, unsigned int, unsigned int);
void set_gleiter_rechts_unten (unsigned int, Spielfeld, unsigned int, unsigned int, unsigned int);
void set_triangle_oben_links (unsigned int, Spielfeld, unsigned int, unsigned int, unsigned int);
void set_triangle_oben_rechts (unsigned int, Spielfeld, unsigned int, unsigned int, unsigned int);
void set_triangle_unten_rechts (unsigned int, Spielfeld, unsigned int, unsigned int, unsigned int);
void set_triangle_unten_links (unsigned int, Spielfeld, unsigned int, unsigned int, unsigned int);
void set_mountain_oben (unsigned int, Spielfeld, unsigned int, unsigned int, unsigned int);
void set_mountain_unten (unsigned int, Spielfeld, unsigned int, unsigned int, unsigned int);
void set_mountain_rechts (unsigned int, Spielfeld, unsigned int, unsigned int, unsigned int);
void set_mountain_links (unsigned int, Spielfeld, unsigned int, unsigned int, unsigned int);
void set_star (unsigned int, Spielfeld, unsigned int, unsigned int, unsigned int);
void set_net_basic_two_four (unsigned int, Spielfeld, unsigned int, unsigned int, unsigned int);
void set_f_links_oben (unsigned int, Spielfeld, unsigned int, unsigned int, unsigned int);
void set_f_oben_rechts (unsigned int, Spielfeld, unsigned int, unsigned int, unsigned int);
void set_f_rechts_unten (unsigned int, Spielfeld, unsigned int, unsigned int, unsigned int);
void set_f_oben_links (unsigned int, Spielfeld, unsigned int, unsigned int, unsigned int);
void set_edge_oben_links (unsigned int, Spielfeld, unsigned int, unsigned int, unsigned int);
void set_edge_oben_rechts (unsigned int, Spielfeld, unsigned int, unsigned int, unsigned int);
void set_edge_unten_rechts (unsigned int, Spielfeld, unsigned int, unsigned int, unsigned int);
void set_edge_unten_links (unsigned int, Spielfeld, unsigned int, unsigned int, unsigned int);


#endif