
#ifndef GROWTH_ALL_GAMEMODE_SPECIALS_H
#define GROWTH_ALL_GAMEMODE_SPECIALS_H

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#ifdef _WIN32
#include <windows.h>
#endif

void Time_for_a_Tutorial (unsigned int, unsigned int*, unsigned int*, unsigned int*, Growth_Player*);
void synchronisation_Test_field (Spielfeld, unsigned int, unsigned int, unsigned int, unsigned int);


void dynamic_take_out (unsigned int*, unsigned int, Spielfeld, unsigned int*, Realize_modifications_variables*, unsigned int, unsigned int, Spielfeld, Special_Fields, unsigned int, unsigned int);
void out_in_dynamic_take_out (unsigned int*, Realize_modifications_variables*, unsigned int);	//repair! go on
int sgn (int);
void Reflection (int*, unsigned int, int);
void impact_y_semi_square (unsigned int, unsigned int, unsigned int*, Earth_impact impact_tuple, int*, Spielfeld);	// unsigned int*** wird zu Spielfeld
void Dynamic_ball_movement (Spielfeld, Special_Fields, unsigned int, unsigned int, unsigned int, Special_Fields, unsigned int, unsigned int*, Spielfeld, unsigned int*, Growth_Player*, unsigned int, int*, unsigned int, unsigned int*, unsigned int, unsigned int*, Earth_impact, Realize_modifications_variables*);


void battle (unsigned int, unsigned int, Spielfeld, unsigned int, Spielfeld, Special_Fields, unsigned int, unsigned int);
void chain_count (unsigned int, unsigned int, Spielfeld, Spielfeld, unsigned int, unsigned int*, unsigned int, Spielfeld, Special_Fields, unsigned int, unsigned int);


void touch (Spielfeld, unsigned int, unsigned int, unsigned int, Spielfeld, Special_Fields, Spielfeld, unsigned int, unsigned int);


void ahead (Spielfeld, unsigned int, unsigned int, Special_Fields, Spielfeld, unsigned int, unsigned int, unsigned int);


void choose_heart (Spielfeld, unsigned int, unsigned int, unsigned int, Spielfeld, Special_Fields, unsigned int, unsigned int);
void heart_ground (unsigned int, unsigned int, Spielfeld, Spielfeld, unsigned int, Spielfeld, Special_Fields, unsigned int, unsigned int);


void choose_your_ability (unsigned int, unsigned int*, Growth_Player*, unsigned int);


void survive_obstacles_generator (unsigned int, unsigned int, unsigned int, unsigned int*, Spielfeld, unsigned int, Special_Fields, unsigned int, Special_Fields, Spielfeld, unsigned int, unsigned int*, Growth_Player*, unsigned int, unsigned int, unsigned int, unsigned int*, unsigned int*, unsigned int, unsigned int, unsigned int, unsigned int);




void Quidditch_Klatscher_players_actions (Spielfeld, unsigned int, Spielfeld, unsigned int, Special_Fields, unsigned int, unsigned int, unsigned int, unsigned int*, Moveable_objects_condition*, Moveable_objects_condition*, Quidditch_setup*, Special_Fields, unsigned int*, Spielfeld, unsigned int*, Growth_Player*);
void Quidditch_Quaffel_players_actions (Spielfeld, unsigned int, Spielfeld, unsigned int, Special_Fields, unsigned int, unsigned int, unsigned int, unsigned int*, Moveable_objects_condition*, Moveable_objects_condition*, Quidditch_setup*, Special_Fields, unsigned int*, Spielfeld, unsigned int*, Growth_Player*, unsigned int*, unsigned int);
void Quidditch_Schnatz_player_actions (Spielfeld, unsigned int, Spielfeld, unsigned int, Special_Fields, unsigned int, unsigned int, unsigned int, unsigned int*, Moveable_objects_condition*, Moveable_objects_condition*, Quidditch_setup*, Special_Fields, unsigned int*, Spielfeld, unsigned int*, Growth_Player*);

void Quidditch_Klatscher_movements (Spielfeld, unsigned int, Spielfeld, unsigned int, Special_Fields, unsigned int, unsigned int, unsigned int, Moveable_objects_condition*, Quidditch_setup*);
void Quidditch_Klatscher_target_search (Spielfeld, unsigned int, unsigned int, Moveable_objects_condition*, unsigned int);
void Quidditch_move_of_Klatscher (Spielfeld, unsigned int, Spielfeld, unsigned int, Special_Fields, unsigned int, unsigned int, unsigned int, Moveable_objects_condition*, unsigned int, Quidditch_setup*);
void Quidditch_Klatscher_steps (Spielfeld, unsigned int, Spielfeld, unsigned int, Special_Fields, unsigned int, unsigned int, unsigned int, Moveable_objects_condition*, unsigned int, int, int, Quidditch_setup*);
void Klatscher_hits_target (unsigned int, Spielfeld, unsigned int, Spielfeld, unsigned int, Special_Fields, unsigned int, unsigned int, unsigned int, Moveable_objects_condition*, unsigned int, Quidditch_setup*);
void Klatscher_hit_allowed_directions (unsigned int, Spielfeld, unsigned int, unsigned int, Moveable_objects_condition*, unsigned int, unsigned int**);
void Treiber_hits_Klatscher (unsigned int, Spielfeld, unsigned int, Spielfeld, unsigned int, Special_Fields, unsigned int, unsigned int, unsigned int, Moveable_objects_condition*, unsigned int, Quidditch_setup*);

void Quidditch_Schnatz_movements (Spielfeld, unsigned int, Spielfeld, unsigned int, Special_Fields, unsigned int, unsigned int, unsigned int, Moveable_objects_condition*, Quidditch_setup*, unsigned int);
void Quidditch_move_of_Schnatz (Spielfeld, unsigned int, Spielfeld, unsigned int, Special_Fields, unsigned int, unsigned int, unsigned int, Moveable_objects_condition*);

void dokuz_direction_interpretation_single_step (Moveable_objects_condition*, unsigned int);

void Move_of_a_Quidditch_player (Spielfeld, unsigned int, Spielfeld, unsigned int, Special_Fields, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int*, Moveable_objects_condition*, Moveable_objects_condition*, Quidditch_setup*, unsigned int*);

void Localization_of_Moc (Spielfeld, unsigned int, unsigned int, Moveable_objects_condition*, Moveable_objects_condition*, Moveable_objects_condition*);

void Quidditch_Quaffel_Throw (Spielfeld, unsigned int, Spielfeld, unsigned int, Special_Fields, unsigned int, unsigned int, unsigned int, Moveable_objects_condition*, Quidditch_setup*, unsigned int*, unsigned int, unsigned int*);
void Realize_Moc_Quaffel_Throw_step (Spielfeld, unsigned int, Moveable_objects_condition*, unsigned int);
void Quidditch_a_goal_has_been_scored (Spielfeld, unsigned int, Spielfeld, unsigned int, Special_Fields, unsigned int, unsigned int, unsigned int, Moveable_objects_condition*, unsigned int*, unsigned int);

#endif