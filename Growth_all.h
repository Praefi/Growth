
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
#define Quidditch_mistake_search

extern unsigned int letters_4;
extern unsigned int letters_2;

extern unsigned int Liz_max;
extern unsigned int anything; //Die Variable für alles Mögliche

extern int Vektor_counter;
extern int Spielfeld_counter;

unsigned int pause; //Fehlersuche

enum directions {	//projection

	Horizontal	= 0,
	Vertikal  = 1,
	Changing = 2,

	undefined = 3,	//undefined immer als letzter Wert

} direction;

enum muemkuen {	//projection

	belki	= 0,
	evet	= 1,
	hayir	= 2,

} muemkuen_mue;

enum durum {	//hint

	oeluem = 15,
	dogum = 16,
	bir_sey = 17,

};

enum zorluk {	//levels, KI

	// Names: Delilag^, Yasmin (min), Lianne (-ant-), Coco (compact), Hera (her...zaman), Liz ([h]iz...li), Lisi (easy), Jill (kill), Natalie (natural <-> diskret), Uma (human)
	//In order of appearence

	human = 0,		//a living player
	Delilag	= 7,	//(Delilag^)
	Hera = 2,
	Yasmin = 8,
	Coco = 4,
	Natalie = 6,
	Liz = 3,
	Jill = 5,
	Uma = 1,

	level_majorante = 9,  //immer das Höchste
};

enum miktar {	//levels, KI

	daha_fazla	= 1,
	daha_fazla_degil = 2,

};

enum yagmurun_durumu {	//abilities of the rain

	Push	= 1,
	Destroy_rain = 2,
	Explode	= 31,
	Explode_and_survival = 32,
	Transform = 4,
	Teleport = 5,
	Mixed	= 6,

};

enum numbers {

	Plus_ = 11,
	Minus_ = 12,
	Move_2 = 21,
	Change_ = 22,
	Destroy_ = 31,
	Revive_ = 32,
	Move_4 = 41,
	Boost_ = 42,
	new_4_5 = 51,
	new_2 = 52,
	max_4 = 61,
	min_1 = 62,

};

enum where_to_go {	//Permutations

	to_the_right = 0,
	to_the_bottom = 1,
	to_the_left = 2,
	to_the_top = 3,

	more_undefined = 4,	//more_undefined immer als letzter Wert

} nereye_gitmeliyiz;

enum objects {
	//	?? == n*10.000 (n = 1, 2, ..., 99, ?? are the last objects >= 10.000)
	// used field numbers: 1,2,3,4,5,6,7,8,9,10,11,15,16,17,20,30,40,50,60,70,71,74,75,77,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,101,102,103,104,105,106,202,303,404,505,606,707,808,909

	Waves		= 75,	//Survive
	Waves_new	= 74,
	Traps     = 71,
	Bomb_4	= 84,
	Bomb_3	= 83,
	Bomb_2	= 82,
	Bomb_1	= 81,

	Dynamic_ball = 77,	//Dynamic

	Fall_ball = 87,	//Fall

	Raindrop = 88,	//Rain

	To_collect = 89,	//Collect

	Wall = 91,	//Race
	Wall_at_the_end = 92,
	
	Quaffel = 85,	//Quidditch
	Klatscher = 86,
	Schnatz = 93,
	Jaeger_1 = 94,
	Hueter_1 = 95,
	Treiber_1 = 96,
	Sucher_1 = 97,
	Torring_1 = 98,
	Torring_2 = 102,
	Jaeger_2 = 103,
	Hueter_2 = 104,
	Treiber_2 = 105,
	Sucher_2 = 106,
	
};

enum winning_options {

	kazanacak = 1,
	biri_kazanacak = 2,

};

enum ulcer_start_values {	//ulcer
	missing = 0,
	existing = 1,
};

enum Houses_of_Hogwarts {	//Quidditch, 1&2 are default
	HGryffindor = 3,
	HHufflepuff = 4,
	HRavenclaw = 5,
	HSlytherin = 6,
};

// NOT-TODO Zahlen hinter enums sind uennoetig, nein, sind sie nicht, weil sonst ungewollte Überschneidungen auftreten
enum gamemode {
	Tutorial = 0,
	Classic	= 1,
	Collect	= 2,
	Contact	= 3,
	Fall	= 4,
	Fight	= 5,
	Hunt	= 6,
	Race	= 7,
	Rain	= 8,
	Arena	= 9,
	Ulcer	= 10,
	Dynamic	= 11,
	Survive	= 12,
	Sand	= 13,
	Quidditch = 14,	//go on
	
	Invalid = 15, //CHANGE
};

enum moveable_objects_directions {	//Quidditch: Klatscher, Quaffel

	standing = 0,	//no movement
	nh = 1,			//north
	nh_et = 2,		//north-east
	et = 3,			//east
	et_sh = 4,		//east-south
	sh = 5,			//south
	sh_wt = 6,		//south-west
	wt = 7,			//west
	wt_nh = 8,		//west-north
	
};

enum options {

	oStart  = 1,
	oSize	= 2,
	oJourney= 3,
	oTactics= 4,
	oRandom	= 5,
	oLimits	= 6,
	oTime	= 7,
	oColor	= 8,
	oOpague	= 9,
	oUndead	= 10,
	oFigures	= 11,
	oAllocation = 12,
	oCards = 13,
	oInverted = 14,
	oAddition = 15,
	oProjection = 16,
	oAssassin = 17,
	oPermutations = 18,
	oAvalanche = 19,

	oBack = 22,		//synchronisiere mit oBack, tivialerweise!

	Numberofplayers = oBack-1,	//Numberofplayers immer (fast) zuletzt
	KI = oBack-2,	//Numberofplayers immer (fast) zuvorletzt

};	//"historical" definition

typedef unsigned int*** Spielfeld;	//Spielfeld ist kubisch

typedef enum color_t {
	cBLUE = 10,
	cGREEN = 13,
	cCYAN = 8,
	cRED = 6,
	cLIGHT_GRAY = 2,
	cGRAY = 3,
	cLIGHT_BLUE = 9,
	cLIGHT_GREEN = 12,
	cLIGHT_CYAN = 7,
	cLIGHT_RED = 5,
	cLIGHT_MAGENTA = 4,
	cYELLOW = 11,
	cWHITE = 1,
	
	cBROWN = 14,
	
	cNORMAL = 0,
} Color;

typedef struct player_t {	//player
	unsigned int id;
	Color color;
} Growth_Player;

typedef struct Quidditch_team_abilities_t {	//Qta
	unsigned int Jaeger_fly_distance;		//normal: 3
	unsigned int Jaeger_throw_distance;		//normal: 3
	unsigned int Hueter_fly_distance;		//normal: 2
	unsigned int Hueter_throw_distance;		//normal: 3
	unsigned int Treiber_fly_distance;		//normal: 3
	unsigned int Treiber_hit_distance;		//normal: 3
	unsigned int Sucher_fly_distance;		//normal: 3
} Quidditch_team_abilities;

typedef struct Quidditch_object_abilities_t {	//Qoa
	unsigned int Klatscher_fly_distance;		//normal: 3
	unsigned int Schnatz_fly_distance;			//normal: 3
	unsigned int Schnatz_appearence_factor;		//normal: 13	(to read as 1/3, necessary to get 2 letters)
	unsigned int Schnatz_disappearence_factor;	//normal: 23	(to read as 2/3, necessary to get 2 letters)	(except a Sucher is in its surrounding, frozen);
} Quidditch_object_abilities;

typedef struct Quidditch_setup_t {	//Quidditch-modifications
	Quidditch_team_abilities Qta[3];
	Quidditch_object_abilities* Qoa;
	unsigned int Points[3];	//Points[0] == Klatscher-hits
	
} Quidditch_setup;	//all distances are maxima

typedef struct Moveable_objects_condition_t {	//Quidditch: Klatscher, Quaffel, Schnatz
	unsigned int i;		//Horizontal, position (Klatscher, Quaffel, Schnatz)
	unsigned int j;		//Vertikal, position (Klatscher, Quaffel, Schnatz)
	unsigned int remaining_squares_to_move;		//how many squares can the object move, Klatscher/Quaffel(<=3)
	unsigned int directed;		//its direction, only important for Klatscher until now, now for Schnatz to indicate if it's on the field or not.
	unsigned int wanted_i;		//Horizontal, target (Klatscher, Quaffel, Schnatz)
	unsigned int wanted_j;		//Vertikal, target (Klatscher, Quaffel, Schnatz)
} Moveable_objects_condition;

typedef struct Special_Fields_t {	//allocation, opague, journey
	Spielfeld field;
	unsigned int characterization;
} Special_Fields;

typedef struct Limits_t {	//square-limits
	unsigned int new;
	unsigned int at_all;
	unsigned int at_all_saver;
} Limits;

typedef struct Num_num_t {	//three numbers
	unsigned int bir;
	unsigned int iki;
	unsigned int uec;
} Num_num;

typedef struct Evolution_t {	//born and dying cells
	Spielfeld nl;
	Spielfeld od;
} Evolution;

typedef struct Earth_impact_t {	//Gamemode: Dynamic
	unsigned int range;
	unsigned int strength;
} Earth_impact;

typedef struct Collector_t {	//Option: Permutations
	Spielfeld areas_b;
	Spielfeld areas_c;
	unsigned int** sigmas_b;
	unsigned int** sigmas_c;
	unsigned int permutation_number_b;
	unsigned int permutation_number_c;
	unsigned int amount_of_permutation_number_b;
	unsigned int amount_of_permutation_number_c;
} Collector;

typedef struct Single_option_representives_t {	//square-limits
	unsigned int undead_duration;
	unsigned int inverted;
	unsigned int addition;
	unsigned int intensity_loss_per_line_multiplication;
} Single_option_representives;

typedef struct Time_matters_t {	//square-limits
	unsigned int ttt;
	unsigned int warning_system;
} Time_matters;

typedef struct Realize_modifications_variables_t {	//square-limits
	unsigned int* win_condition;
	Spielfeld numbers_of_;
	unsigned int* same;
	unsigned int AOP;
	unsigned int freq;
	unsigned int player_counter;
	unsigned int all_turns_correction;
	unsigned int use_number;
	unsigned int* var_;
	unsigned int* Points;
	unsigned int round_counter;
	unsigned int rtc;
	unsigned int* ulcer_start;
	unsigned int* ulcer_lifes;
	unsigned int* out_counter;
	unsigned int rtp;
	Collector Collector_of_permutation;
} Realize_modifications_variables;


unsigned int minimum (unsigned int, unsigned int);
unsigned int maximum (unsigned int, unsigned int);

Spielfeld Spielfeld_Create (unsigned int, unsigned int, unsigned int);		//mxn, m >= 6 (+2), n gerade, n >= 4 (+2)		Original: m = 10 (+2), n = 6 (+2)

void playing_a_game (unsigned int*, unsigned int*, unsigned int, time_t, unsigned int*, unsigned int, Quidditch_setup*);

void start_normal (Spielfeld, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, Spielfeld, Special_Fields, unsigned int);

unsigned int* unsigned_int_Vektor_Create (unsigned int);
int* int_Vektor_Create (unsigned int);
int** int_2dim_Vektor_Create (unsigned int, unsigned int);
unsigned int** unsigned_int_2dim_Vektor_Create (unsigned int, unsigned int);
Moveable_objects_condition* Moveable_objects_condition_Vektor_Create (unsigned int);

void new_life (Spielfeld, Spielfeld, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int*, unsigned int, Evolution, Spielfeld, Special_Fields, unsigned int);
void old_dying (Spielfeld, Spielfeld, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int*, unsigned int, Spielfeld, unsigned int, Special_Fields, Spielfeld, unsigned int);
void change (Spielfeld, unsigned int*, Spielfeld, Spielfeld, Evolution, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int*, unsigned int, Special_Fields, Spielfeld, unsigned int*, Growth_Player*, Single_option_representives);

void show_field (unsigned int, unsigned int*, Spielfeld, Spielfeld, Spielfeld, unsigned int, unsigned int, unsigned int, unsigned int*, unsigned int, Growth_Player*, unsigned int, Special_Fields);
void show_whose_turn (unsigned int, unsigned int, unsigned int*, Growth_Player*, unsigned int*, unsigned int);
void show_statistics (unsigned int, unsigned int, Spielfeld, unsigned int*, unsigned int, unsigned int*, unsigned int*, unsigned int*, unsigned int*, unsigned int, Quidditch_setup*);
void show_options_of_actions (unsigned int, unsigned int*, unsigned int);
void show_the_numbers (unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
void show_figures ();
void show_abilities (unsigned int*);

unsigned int Vorganger (unsigned int, unsigned int);
unsigned int Nachfolger (unsigned int, unsigned int);

void figure_check (Spielfeld, unsigned int, unsigned int, unsigned int, Growth_Player*, Special_Fields, Spielfeld, unsigned int, unsigned int);

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

void Plus (unsigned int*, Spielfeld, unsigned int, unsigned int, unsigned int, Spielfeld, unsigned int, unsigned int, unsigned int*, unsigned int, Growth_Player*, Special_Fields, Special_Fields);
void Minus (unsigned int*, Spielfeld, unsigned int, unsigned int, unsigned int, Spielfeld, unsigned int, unsigned int*, Growth_Player*, Special_Fields, Special_Fields, unsigned int);
void Move (unsigned int*, Spielfeld, unsigned int, unsigned int, unsigned int, Spielfeld, unsigned int, unsigned int*, Growth_Player*, Special_Fields, Special_Fields, unsigned int);
void Change (unsigned int*, Spielfeld, unsigned int, unsigned int, unsigned int, Spielfeld, unsigned int, unsigned int*, Growth_Player*, Special_Fields, unsigned int*, Special_Fields, unsigned int);
void Destroy (unsigned int*, Spielfeld, unsigned int, unsigned int, unsigned int, Spielfeld, unsigned int, unsigned int*, Growth_Player*, Special_Fields, Special_Fields, unsigned int);
void Revive (Spielfeld, unsigned int, unsigned int, Spielfeld, Spielfeld, unsigned int, Special_Fields, Spielfeld, unsigned int, unsigned int);

void Boost (Spielfeld, unsigned int, Spielfeld, unsigned int, unsigned int, Spielfeld, unsigned int, Spielfeld, Special_Fields, unsigned int);

void Initialisierung (unsigned int, unsigned int*);
unsigned int Initialisierung_limits_at_all (unsigned int);
unsigned int Initialisierung_limits_new (unsigned int);
unsigned int Initialisierung_m (unsigned int);
unsigned int Initialisierung_n (unsigned int);
void unsigned_int_array_null_initialisierung (unsigned int*, unsigned int);
void int_array_null_initialisierung (int*, unsigned int);
void Initialisierung_Arrays_1 (unsigned int, unsigned int*, unsigned int*, unsigned int*);
void Initialisierung_Arrays_2 (unsigned int, unsigned int*, unsigned int*, unsigned int*, unsigned int*, unsigned int*, unsigned int*, unsigned int*, unsigned int*);
void Initialisierung_Qs (Quidditch_setup*, Quidditch_team_abilities*, Quidditch_object_abilities*, Growth_Player*);
void Initialisierung_Qoa (Quidditch_object_abilities*);
void Initialisierung_Qta (Quidditch_team_abilities*);
void Initialisierung_Moc (Moveable_objects_condition*, Moveable_objects_condition*, Moveable_objects_condition*, unsigned int, unsigned int);

void About_the_game (unsigned int, unsigned int, Limits, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
void get_hints (unsigned int*, Spielfeld, unsigned int, Spielfeld, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int*, Special_Fields, Growth_Player*, unsigned int, Special_Fields, unsigned int);
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
void get_colors (Growth_Player*, unsigned int, unsigned int, unsigned int);
void get_two_amounts_for_permutations (unsigned int*, unsigned int*, unsigned int, unsigned int, unsigned int, unsigned int);
void get_sigmas_for_permutation_number (unsigned int**, unsigned int);

void choose_your_ability (unsigned int, unsigned int*, Growth_Player*, unsigned int);
void dynamic_take_out (unsigned int*, unsigned int, Spielfeld, unsigned int*, Realize_modifications_variables*, unsigned int, unsigned int, Spielfeld, Special_Fields, unsigned int, unsigned int);
void out_in_dynamic_take_out (unsigned int*, Realize_modifications_variables*, unsigned int);	//repair! go on
void who_is_out (unsigned int*, unsigned int, Realize_modifications_variables*);
void reset_of_ges (unsigned int*, unsigned int);

void set_Spielfeld_Eintrag (Spielfeld, unsigned int, Spielfeld, unsigned int, Special_Fields, unsigned int, Spielfeld, unsigned int, unsigned int, unsigned int, unsigned int);
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

void Having_too_much (unsigned int*, unsigned int, unsigned int, unsigned int, unsigned int, Evolution, Limits, unsigned int, Spielfeld, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int*, unsigned int, unsigned int, unsigned int, Spielfeld, Special_Fields, unsigned*, unsigned int);

void inverted_organism (Spielfeld, unsigned int*, Spielfeld, Spielfeld, unsigned int, Spielfeld, unsigned int, Special_Fields, unsigned int, unsigned int, unsigned int, unsigned int*, Growth_Player*);

void opague_builder (Spielfeld, Special_Fields, unsigned int, unsigned int, unsigned int, unsigned int, Special_Fields, unsigned int, unsigned int);

unsigned int random_number (Num_num, unsigned int, unsigned int, unsigned int*, unsigned int*);
unsigned int Zufall (unsigned int, unsigned int);

void battle (unsigned int, unsigned int, Spielfeld, unsigned int, Spielfeld, Special_Fields, unsigned int, unsigned int);
void chain_count (unsigned int, unsigned int, Spielfeld, Spielfeld, unsigned int, unsigned int*, unsigned int, Spielfeld, Special_Fields, unsigned int, unsigned int);

void touch (Spielfeld, unsigned int, unsigned int, unsigned int, Spielfeld, Special_Fields, Spielfeld, unsigned int, unsigned int);

void addition_maker (Spielfeld, unsigned int, unsigned int, unsigned int, unsigned int, Spielfeld, unsigned int, Special_Fields, unsigned int*);
void projection_maker (Spielfeld, unsigned int, unsigned int, Spielfeld, unsigned int, Special_Fields, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
void assassin_maker (unsigned int*, Spielfeld, Spielfeld, unsigned int, Special_Fields, unsigned int, Special_Fields, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int*, Growth_Player*);
void Avalanche_maker (Spielfeld, Spielfeld, Special_Fields, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
void Permutations_permutate_maker (Spielfeld, Spielfeld, unsigned int, unsigned int, unsigned int**, unsigned int, unsigned int, Spielfeld, unsigned int, Special_Fields);
void decision_max_maker (unsigned int, unsigned int, unsigned int*);

void ges_counter (Spielfeld, unsigned int, unsigned int, unsigned int*, unsigned int);
void ges0_reset_and_counter (unsigned int*, unsigned int);

void ahead (Spielfeld, unsigned int, unsigned int, Special_Fields, Spielfeld, unsigned int, unsigned int, unsigned int);

void choose_heart (Spielfeld, unsigned int, unsigned int, unsigned int, Spielfeld, Special_Fields, unsigned int, unsigned int);
void heart_ground (unsigned int, unsigned int, Spielfeld, Spielfeld, unsigned int, Spielfeld, Special_Fields, unsigned int, unsigned int);

int sgn (int);
void Reflection (int*, unsigned int, int);
void impact_y_semi_square (unsigned int, unsigned int, unsigned int*, Earth_impact impact_tuple, int*, Spielfeld);	// unsigned int*** wird zu Spielfeld
void Dynamic_ball_movement (Spielfeld, Special_Fields, unsigned int, unsigned int, unsigned int, Special_Fields, unsigned int, unsigned int*, Spielfeld, unsigned int*, Growth_Player*, unsigned int, int*, unsigned int, unsigned int*, unsigned int, unsigned int*, Earth_impact, Realize_modifications_variables*);

void translate_permutations_amounts_to_permutations_areas (Spielfeld, unsigned int, unsigned int, Collector);

void survive_obstacles_generator (unsigned int, unsigned int, unsigned int, unsigned int*, Spielfeld, unsigned int, Special_Fields, unsigned int, Special_Fields, Spielfeld, unsigned int, unsigned int*, Growth_Player*, unsigned int, unsigned int, unsigned int, unsigned int*, unsigned int*, unsigned int, unsigned int, unsigned int, unsigned int);

void turn_of_KI_random (Quidditch_setup*, Moveable_objects_condition*, Moveable_objects_condition*, Moveable_objects_condition*, unsigned int*, Spielfeld, unsigned int, unsigned int, unsigned int, Special_Fields, Special_Fields, Spielfeld, unsigned int*, Growth_Player*, unsigned int, unsigned int, unsigned int* , unsigned int*, Limits, Single_option_representives, unsigned int, Realize_modifications_variables*);
void fill_KI_table_of_choice (Quidditch_setup*, Moveable_objects_condition*, Moveable_objects_condition*, Moveable_objects_condition*, unsigned int*, Spielfeld, Spielfeld, unsigned int, unsigned int, unsigned int, Special_Fields, Special_Fields, Spielfeld, unsigned int*, Growth_Player*, unsigned int, unsigned int, unsigned int*, unsigned int*, unsigned int*, unsigned int*, Limits, Single_option_representives, unsigned int, Realize_modifications_variables*);
void set_KI_table_of_choice (Quidditch_setup*, Moveable_objects_condition*, Moveable_objects_condition*, Moveable_objects_condition*, unsigned int*, Spielfeld, Spielfeld, unsigned int, unsigned int, unsigned int, Special_Fields, Special_Fields, Spielfeld, unsigned int*, Growth_Player*, unsigned int, unsigned int, unsigned int*, unsigned int*, unsigned int*, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int*, Limits, Single_option_representives, unsigned int, Realize_modifications_variables*);
void update_KI_table_of_choice (unsigned int*, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int*, unsigned int, unsigned int, unsigned int*, unsigned int, unsigned int, unsigned int*, unsigned int);

void basic_development (Spielfeld, Spielfeld, unsigned int, unsigned int, unsigned int, Spielfeld, Special_Fields, Spielfeld, unsigned int*, Growth_Player*, unsigned int, unsigned int, unsigned int*, unsigned int*, unsigned int, unsigned int, unsigned int, unsigned int, Evolution, Num_num*, unsigned int*, Special_Fields, Limits, Single_option_representives, unsigned int*, unsigned int*, unsigned int, unsigned int);
void realize_modifications (Quidditch_setup*, Moveable_objects_condition*, Moveable_objects_condition*, Moveable_objects_condition*, Spielfeld, Spielfeld, Special_Fields, Special_Fields, Spielfeld, unsigned int*, unsigned int*, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int*, unsigned int*, Growth_Player*, Special_Fields, unsigned int, Single_option_representives, Realize_modifications_variables*, unsigned int);

void dimension_of (unsigned int*, unsigned int*, unsigned int);
void synchronisation_Field_copy (Spielfeld, Spielfeld, unsigned int, unsigned int, unsigned int, unsigned int, Spielfeld, unsigned int, Special_Fields);
void synchronisation_Test_field (Spielfeld, unsigned int, unsigned int, unsigned int, unsigned int);
void synchronisation_ges_copy (unsigned int*, unsigned int, unsigned int*);
void reset_ges_copy (unsigned int*, unsigned int*, unsigned int);
void reset_Field_copy (Spielfeld, Spielfeld, Spielfeld, unsigned int, unsigned int, unsigned int, unsigned int, Spielfeld, unsigned int, Special_Fields);
void ges_others_counter (unsigned int*, unsigned int*, unsigned int, unsigned int);
void is_it_necessary (unsigned int*, unsigned int*, unsigned int*, unsigned int, unsigned int);
unsigned int accepted_or_not (unsigned int, unsigned int*, unsigned int, unsigned int);

void find_edges_of_organism_2dim (unsigned int*, Spielfeld, unsigned int, unsigned int, unsigned int);

void Time_for_a_Tutorial (unsigned int, unsigned int*, unsigned int*, unsigned int*, Growth_Player*);

void Square_color_interpretation (Growth_Player*, unsigned int, unsigned int, unsigned int);
void set_terminal_color (Color);
void set_player_color (Growth_Player*, unsigned int, Color);

void Quidditch_Klatscher_players_actions (Spielfeld, unsigned int, Spielfeld, unsigned int, Special_Fields, unsigned int, unsigned int, unsigned int, unsigned int*, Moveable_objects_condition*, Moveable_objects_condition*, Quidditch_setup*, Special_Fields, unsigned int*, Spielfeld, unsigned int*, Growth_Player*);
void Quidditch_Quaffel_players_actions (Spielfeld, unsigned int, Spielfeld, unsigned int, Special_Fields, unsigned int, unsigned int, unsigned int, unsigned int*, Moveable_objects_condition*, Moveable_objects_condition*, Quidditch_setup*, Special_Fields, unsigned int*, Spielfeld, unsigned int*, Growth_Player*);
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

void Move_of_a_Quidditch_player (Spielfeld, unsigned int, Spielfeld, unsigned int, Special_Fields, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int*, Moveable_objects_condition*, Moveable_objects_condition*, unsigned int*);

void Localization_of_Moc (Spielfeld, unsigned int, unsigned int, Moveable_objects_condition*, Moveable_objects_condition*, Moveable_objects_condition*);

void Quidditch_Quaffel_Throw (Spielfeld, unsigned int, Spielfeld, unsigned int, Special_Fields, unsigned int, unsigned int, unsigned int, Moveable_objects_condition*, Quidditch_setup*);
void Realize_Moc_Quaffel_Throw_step (Spielfeld, unsigned int, Moveable_objects_condition*, unsigned int);
void Quidditch_a_goal_has_been_scored (Spielfeld, unsigned int, Spielfeld, unsigned int, Special_Fields, unsigned int, unsigned int, unsigned int, Moveable_objects_condition*);

void Square_color_interpretation (Growth_Player* Growth_players, unsigned int geben, unsigned int number_of_players, unsigned int square_number) {
	if (square_number != 0) {
		if (square_number <= number_of_players) {
			for (unsigned int p=1; p<=number_of_players; p++) {
				if (Growth_players[p].id == square_number) {
					set_terminal_color (Growth_players[p].color);
				}
			}
		} else {
			if (square_number == 11) {
				set_terminal_color (Growth_players[1].color);
			} else if (square_number == oeluem) {
				set_terminal_color (Growth_players[geben].color);
			} else if (square_number == dogum) {
				set_terminal_color (Growth_players[geben].color);
			} else if (square_number == bir_sey) {
				set_terminal_color (cNORMAL);
			} else if (square_number == Quaffel) {
				set_terminal_color (cRED);
			} else if (square_number == Klatscher) {
				set_terminal_color (cGRAY);
			} else if (square_number == Schnatz) {
				set_terminal_color (cWHITE);
			} else if ((square_number == Treiber_1)||(square_number == Jaeger_1)||(square_number == Sucher_1)||(square_number == Hueter_1)) {
				if (Growth_players[1].color == cLIGHT_MAGENTA) {
					set_terminal_color (cLIGHT_RED);
				} else if (Growth_players[1].color == cLIGHT_CYAN) {
					set_terminal_color (cLIGHT_BLUE);
				} else if (Growth_players[1].color == cYELLOW) {
					set_terminal_color (cBROWN);
				} else if (Growth_players[1].color == cLIGHT_GREEN) {
					set_terminal_color (cGREEN);
				}
			} else if ((square_number == Treiber_2)||(square_number == Jaeger_2)||(square_number == Sucher_2)||(square_number == Hueter_2)) {
				if (Growth_players[2].color == cLIGHT_MAGENTA) {
					set_terminal_color (cLIGHT_RED);
				} else if (Growth_players[2].color == cLIGHT_CYAN) {
					set_terminal_color (cLIGHT_BLUE);
				} else if (Growth_players[2].color == cYELLOW) {
					set_terminal_color (cBROWN);
				} else if (Growth_players[2].color == cLIGHT_GREEN) {
					set_terminal_color (cGREEN);
				}
			} else if ((square_number == Torring_1)||(square_number == Torring_2)) {
				set_terminal_color (cLIGHT_GRAY);
			} else {
				set_terminal_color (cBROWN);
			}
		}
	}
}

void set_terminal_color (Color color) {

		switch(color) {
		case cWHITE:
		{
			#ifdef _WIN32
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+15);
			#else
				printf("\x1B[37m");
			#endif
			break;
		}
		
		case cLIGHT_GRAY:
		{
			#ifdef _WIN32
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+7);
			#else
				printf("\x0B[37m");
			#endif
			break;
		}
		
		case cGRAY:
		{
			#ifdef _WIN32
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+8);
			#else
				printf("\x1B[0m");
			#endif
			break;
		}
		
		case cLIGHT_MAGENTA:
		{
			#ifdef _WIN32
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+13);
			#else
				printf("\x1B[35m");
			#endif
			break;
		}
		case cLIGHT_RED:
		{
			#ifdef _WIN32
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+12);
			#else
				printf("\x1B[31m");
			#endif
			break;
		}
		case cRED:
		{
			#ifdef _WIN32
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+4);
			#else
				printf("\x0B[31m");
			#endif
			break;
		}
		case cLIGHT_CYAN:
		{
			#ifdef _WIN32
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+11);
			#else
				printf("\x1B[36m");
			#endif
			break;
		}
		case cCYAN:
		{
			#ifdef _WIN32
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+3);
			#else
				printf("\x0B[36m");
			#endif
			break;
		}
		case cLIGHT_BLUE:
		{
			#ifdef _WIN32
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+9);
			#else
				printf("\x1B[34m");
			#endif
			break;
		}
		case cBLUE:
		{
			#ifdef _WIN32
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+1);
			#else
				printf("\x0B[34m");
			#endif
			break;
		}
		
		case cYELLOW:
		{
			#ifdef _WIN32
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+14);
			#else
				printf("\x1B[33m");
			#endif
			break;
		}
		
		case cLIGHT_GREEN:
		{
			#ifdef _WIN32
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+10);
			#else
				printf("\x1B[32m");
			#endif
			break;
		}
		
		case cGREEN:
		{
			#ifdef _WIN32
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+2);
			#else
				printf("\x0B[32m");
			#endif
			break;
		}
		
		case cBROWN:
		{
			#ifdef _WIN32
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+6);
			#else
				printf("\x1B[0m");
			#endif
			break;
		}
		
		default:
		{
			#ifdef _WIN32
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+7);
			#else
				printf("\x1B[0m");
			#endif
			break;
		}
		}
}

void set_player_color (Growth_Player* Growth_players, unsigned int id, Color color) {
		Growth_players[id].color = color;
}

Spielfeld Spielfeld_Create (unsigned int m, unsigned int n, unsigned int number_of_players) {
	Spielfeld Spiel;

	// printf("Checkpoint: Start of Spielfeld_Create	\n ");	//test

	Spiel = calloc(number_of_players+1, sizeof(unsigned int**));

	if (Spiel == NULL) {
		printf("	Kein freier Speicher wurde gefunden! \n ");
	}

	// printf("Checkpoint: 1st step of Spielfeld_Create	\n ");	//test

	for (unsigned int geben=0; geben<=number_of_players; geben+=1) {	//geben und i, um zugehörigkeit zu verdeutlichen

		// printf("Checkpoint: 1.5nd step of Spielfeld_Create	\n ");	//test

		Spiel[geben] = calloc(m, sizeof(unsigned int*));

		// printf("Checkpoint: 2nd step of Spielfeld_Create	\n ");	//test

		for (unsigned int i=0; i<m; i+=1) {
			Spiel[geben][i] = calloc(n, sizeof(unsigned int));

			// printf("Checkpoint: 3rd step of Spielfeld_Create	\n ");	//test

		}

	}
		// Spiel = calloc(1, sizeof(unsigned int**));
		// printf("	1. \n");
		// Spiel[0] = calloc(1, sizeof(unsigned int*));
		// printf("	2. \n");
		// Spiel[0][0] = calloc(1, sizeof(unsigned int*));
		// printf("	3. \n");


	Spielfeld_counter += 1;

	return Spiel;
}

Moveable_objects_condition* Moveable_objects_condition_Vektor_Create (unsigned int length) {
	Moveable_objects_condition* Vektor;
	Vektor = calloc(length, sizeof(Moveable_objects_condition));

	Vektor_counter += 1;

	return Vektor;
}

Realize_modifications_variables* Realize_modifications_variables_Vektor_Create (unsigned int length) {
	Realize_modifications_variables* Vektor;
	Vektor = calloc(length, sizeof(Realize_modifications_variables));

	Vektor_counter += 1;
	
	return Vektor;
}

Quidditch_team_abilities* Quidditch_team_abilities_Vektor_Create (unsigned int length) {
	Quidditch_team_abilities* Vektor;
	Vektor = calloc(length, sizeof(Quidditch_team_abilities));

	Vektor_counter += 1;
	
	return Vektor;
}

Quidditch_object_abilities* Quidditch_object_abilities_Vektor_Create (unsigned int length) {
	Quidditch_object_abilities* Vektor;
	Vektor = calloc(length, sizeof(Quidditch_object_abilities));

	Vektor_counter += 1;
	
	return Vektor;
}

Quidditch_setup* Quidditch_setup_Vektor_Create (unsigned int length) {
	Quidditch_setup* Vektor;
	Vektor = calloc(length, sizeof(Quidditch_setup));

	Vektor_counter += 1;
	
	return Vektor;
}

unsigned int* unsigned_int_Vektor_Create (unsigned int length) {
	unsigned int* Vektor;
	Vektor = calloc(length, sizeof(unsigned int));

	Vektor_counter += 1;

	return Vektor;
}

int* int_Vektor_Create (unsigned int length) {
	int* Vektor;
	Vektor = calloc(length, sizeof(int));

	Vektor_counter += 1;

	return Vektor;
}

int** int_2dim_Vektor_Create (unsigned int m, unsigned int n) {
	int** Vektor;
	Vektor = calloc(m, sizeof(int*));

	for (unsigned int p=0; p<m; p+=1) {
		Vektor[p] = calloc(n, sizeof(int));
	}

	Vektor_counter += 1;

	return Vektor;
}

unsigned int** unsigned_int_2dim_Vektor_Create (unsigned int m, unsigned int n) {
	unsigned int** Vektor;
	Vektor = calloc(m, sizeof(unsigned int*));

	for (unsigned int p=0; p<m; p+=1) {
		Vektor[p] = calloc(n, sizeof(unsigned int));
	}

	Vektor_counter += 1;

	return Vektor;
}

void Moveable_objects_condition_Vektor_Destroy (Moveable_objects_condition* Vektor) {
	
	free(Vektor);
	Vektor = NULL;

	Vektor_counter -= 1;
}

void Quidditch_team_abilities_Vektor_Destroy (Quidditch_team_abilities* Vektor) {
	
	free(Vektor);
	Vektor = NULL;

	Vektor_counter -= 1;
}

void Quidditch_object_abilities_Vektor_Destroy (Quidditch_object_abilities* Vektor) {
	
	free(Vektor);
	Vektor = NULL;

	Vektor_counter -= 1;
}

void Quidditch_setup_Vektor_Destroy (Quidditch_setup* Vektor) {
	
	free(Vektor);
	Vektor = NULL;

	Vektor_counter -= 1;
}

void int_2dim_Vektor_Destroy (int** Vektor, unsigned int m) {

	for (unsigned int p=0; p<m; p+=1) {
		free(Vektor[p]);
		// Vektor[p] = NULL;
	}

	free(Vektor);
	Vektor = NULL;

	Vektor_counter -= 1;
}

void unsigned_int_2dim_Vektor_Destroy (unsigned int** Vektor, unsigned int m) {

	for (unsigned int p=0; p<m; p+=1) {
		free(Vektor[p]);
		// Vektor[p] = NULL;
	}

	free(Vektor);
	Vektor = NULL;

	Vektor_counter -= 1;
}

void int_Vektor_Destroy (int* Vektor) {
	free(Vektor);
	Vektor = NULL;

	Vektor_counter -= 1;
}

void unsigned_int_Vektor_Destroy (unsigned int* Vektor) {
	free(Vektor);
	Vektor = NULL;

	Vektor_counter -= 1;
}

void Realize_modifications_variables_Vektor_Destroy (Realize_modifications_variables* Vektor) {
	free(Vektor);
	Vektor = NULL;

	Vektor_counter -= 1;
}

void Spielfeld_Destroy (Spielfeld Spiel, unsigned int m, unsigned int number_of_players){
	for (unsigned int geben=number_of_players+1; geben>0; geben-=1) {	//number_of_players, geben, i, j dienen nur zur Anschauung

		// printf("	Spielfeld_Destroy #1 \n");	//test

		for (unsigned int i=m; i>0; i-=1){
			free(Spiel[geben-1][i-1]);
			// Spiel[geben-1][i-1] = NULL;
		}

		// printf("	Spielfeld_Destroy #2 \n");	//test

	}
	for (unsigned int geben=number_of_players+1; geben>0; geben-=1) {	//Having_too_much-Verschiebung
		free(Spiel[geben-1]);
		//Spiel[geben-1] = NULL;
	}

	// printf("	Spielfeld_Destroy #3 \n");	//test

	free(Spiel);
	Spiel = NULL;		//nach testen auf andere Versionen übertragen!

	// printf("	Spielfeld_Destroy #4 \n");	//test

	Spielfeld_counter -= 1;
}

unsigned int Fakultaet (unsigned int wert) {
	unsigned int ruckgabe;
	ruckgabe = 1;

	for (unsigned int p=1; p<=wert; p++) {
		ruckgabe *= p;
	}

	// printf("Fakultaet(%u) = %u \n", wert, ruckgabe);	//test

	return ruckgabe;
}

unsigned int minimum (unsigned int a, unsigned int b) {
	unsigned int ruckgabe;
	ruckgabe = 0;

	if (a>=b) {
		ruckgabe = b;
	} else {
		ruckgabe = a;
	}

	return ruckgabe;
}

unsigned int maximum (unsigned int a, unsigned int b) {
	unsigned int ruckgabe;
	ruckgabe = 0;

	if (a>=b) {
		ruckgabe = a;
	} else {
		ruckgabe = b;
	}

	return ruckgabe;
}

void start_normal (Spielfeld Field, unsigned int m, unsigned int n, unsigned int gamemode_played, unsigned int number_of_players, unsigned int geben, Spielfeld Opague_o_field, Special_Fields Allocation_o, unsigned int single_option_representives_inverted){

	if (gamemode_played == Tutorial){
		Field[0][4][1] = 2;		//Spieler 2
		Field[0][5][1] = 2;
		Field[0][4][2] = 2;
		Field[0][5][2] = 2;

		Field[0][4][6] = 1;		//Spieler 1
		Field[0][5][4] = 1;
		Field[0][5][5] = 1;
		Field[0][6][5] = 1;
		Field[0][6][6] = 1;
	} else if (gamemode_played == Classic){
		if (number_of_players == 2) {

				set_gleiter_links_unten (single_option_representives_inverted, Field, 1, 2, 4);		//Spieler 1

				set_gleiter_rechts_oben (single_option_representives_inverted, Field, 2, m-3, 3);		//Spieler 2

		} else {
			for (unsigned int p=1; p<=number_of_players; p++) {
				if (p%2 == 1) {
					set_gleiter_links_unten (single_option_representives_inverted, Field, p, 2, (((n-2)/((number_of_players+1)/2))/2)+((p-1)/2)*((n-2)/((number_of_players+1)/2)));		//Spieler p
				} else if (p%2 == 0) {
					set_gleiter_rechts_oben (single_option_representives_inverted, Field, p, m-3, (((n-2)/(number_of_players/2))/2)+((p-2)/2)*((n-2)/(number_of_players/2)));		//Spieler p
				}
			}	//n-2 >= 3*((number_of_players+1)/2)
		}

	} else if (gamemode_played == Collect){
		for (unsigned int p=1; p<=number_of_players; p++) {
			if (p%2 == 1) {
				set_gleiter_links_unten (single_option_representives_inverted, Field, p, 2, ((p+1)/2)+p*((n-2-((number_of_players+1)/2))/(2*((number_of_players+1)/2))));		//Spieler p
			} else if (p%2 == 0) {
				set_gleiter_rechts_oben (single_option_representives_inverted, Field, p, m-3, (p/2)+(p-1)*((n-2-(number_of_players/2))/(2*(number_of_players/2))));		//Spieler p
			}
		}	//n-2 >= 3*((number_of_players+1)/2)		n-2 >= 3*(number_of_players+1)

		//Field[0][9][1] = 1;	Field[0][8][5] = 1;	//Test
		//Field[0][8][5] = 1;	Field[0][8][6] = 1;
		//Field[0][2][1] = 2;	Field[0][5][2] = 1;
		//Field[0][5][5] = 1;	Field[0][5][6] = 1;
		for (unsigned int q=1; q<=number_of_players-1; q++) {
			Field[0][(m-1)/2][2+q+q*(n-2-4-(number_of_players-1))/number_of_players] = To_collect;	//uniform setting between the following two To_collect-squares
		}
		Field[0][(m-1)/2][2] = To_collect;
		Field[0][(m-1)/2][n-3] = To_collect;

	} else if (gamemode_played == Contact){
		if (number_of_players == 2) {
			set_gleiter_links_unten (single_option_representives_inverted, Field, 1, 2, n/2);		//Spieler 1
			set_triangle_oben_links (single_option_representives_inverted, Field, 1, 1, 1);
			set_triangle_oben_rechts (single_option_representives_inverted, Field, 1, 1, n-2);

			//Field[0][9][1] = 1;	Field[0][8][5] = 1;	//Test
			//Field[0][8][5] = 1;	Field[0][8][6] = 1;
			//Field[0][2][1] = 2;	Field[0][5][2] = 1;
			//Field[0][5][5] = 1;	Field[0][5][6] = 1;

			set_gleiter_rechts_oben (single_option_representives_inverted, Field, 2, m-3, (n/2)-1);		//Spieler 2
			set_triangle_unten_links (single_option_representives_inverted, Field, 2, m-2, 1);
			set_triangle_unten_rechts (single_option_representives_inverted, Field, 2, m-2, n-2);
		} else {
			for (unsigned int p=1; p<=number_of_players; p++) {
				if (p%2 == 1) {
					set_gleiter_links_unten (single_option_representives_inverted, Field, p, 2, 1+2+((p-1)/2)*((n-2)/((number_of_players+1)/2)));		//Spieler p
					set_triangle_oben_rechts (single_option_representives_inverted, Field, p, 1, 1+7+((p-1)/2)*((n-2)/((number_of_players+1)/2)));
				} else if (p%2 == 0) {
					set_gleiter_rechts_oben (single_option_representives_inverted, Field, p, m-3, n-2-2-((p-1)/2)*((n-2)/(number_of_players/2)));		//Spieler p
					set_triangle_unten_links (single_option_representives_inverted, Field, p, m-2, n-2-7-((p-1)/2)*((n-2)/(number_of_players/2)));
				}
			}
		}

	} else if (gamemode_played == Fall){
		for (unsigned int p=1; p<=number_of_players; p++) {
			if (p%2 == 1) {	//links
				set_gleiter_rechts_oben (single_option_representives_inverted, Field, p, m-3, 1+1+((p-1)/2)*((n-2-1)/number_of_players));		//Spieler p
			} else if (p%2 == 0) {	//rechts
				set_gleiter_links_oben (single_option_representives_inverted, Field, p, m-3, n-2-1-((p-1)/2)*((n-2-1)/number_of_players));		//Spieler p
			}
		}

		Field[0][1][(n-1)/2] = Fall_ball;

	} else if (gamemode_played == Fight){
		for (unsigned int p=1; p<=number_of_players; p++) {
			if (p%2 == 1) {
				set_gleiter_links_unten (single_option_representives_inverted, Field, p, 2, 1+((p+1)/2)*((n-2)/(((number_of_players+1)/2)+1)));		//Spieler p
			} else if (p%2 == 0) {
				set_gleiter_rechts_oben (single_option_representives_inverted, Field, p, m-3, 1+((p+1)/2)*((n-2)/((number_of_players/2)+1)));		//Spieler p
			}
		}

	} else if (gamemode_played == Hunt){
		if (number_of_players == 2) {
			unsigned int m_2;
			m_2 = (m-1)/2;

			if (single_option_representives_inverted == 0) {
				Field[0][m_2-1][3]	= 1;		//Spieler 1
				Field[0][m_2][2]	= 1;
				Field[0][m_2][3]	= 11;
				Field[0][m_2][4]	= 1;
				Field[0][m_2+1][3]	= 1;
			} else if (single_option_representives_inverted == 1) {
				Field[0][m_2-1][2]	= 1;		//Spieler 1
				Field[0][m_2+1][2]	= 1;
				Field[0][m_2][3]	= 11;
				Field[0][m_2-1][4]	= 1;
				Field[0][m_2+1][4]	= 1;
			}

			set_gleiter_unten_links (single_option_representives_inverted, Field, 2, m_2, n-3);		//Spieler 2

		} else if (number_of_players == 3) {
			unsigned int m_2, n_2;
			m_2 = (m-1)/2;
			n_2 = (n-1)/2;

			if (single_option_representives_inverted == 0) {
				Field[0][m_2-1][n_2] = 1;		//Spieler 1
				Field[0][m_2][n_2-1] = 1;
				Field[0][m_2][n_2]   = 11;
				Field[0][m_2][n_2+1] = 1;
				Field[0][m_2+1][n_2] = 1;
			} else if (single_option_representives_inverted == 1) {
				Field[0][m_2-1][n_2-1] = 1;		//Spieler 1
				Field[0][m_2+1][n_2-1] = 1;
				Field[0][m_2][n_2]   = 11;
				Field[0][m_2-1][n_2+1] = 1;
				Field[0][m_2+1][n_2+1] = 1;
			}

			set_gleiter_unten_links (single_option_representives_inverted, Field, 2, m_2, n-3);		//Spieler 2
			set_gleiter_oben_rechts (single_option_representives_inverted, Field, 3, m_2, 2);		//Spieler 3

		} else if (number_of_players == 4) {
			unsigned int m_2, n_2;
			m_2 = (m-1)/2;
			n_2 = (n-1)/2;

			if (single_option_representives_inverted == 0) {
				Field[0][m_2-1][n_2] = 1;		//Spieler 1
				Field[0][m_2][n_2-1] = 1;
				Field[0][m_2][n_2]   = 11;
				Field[0][m_2][n_2+1] = 1;
				Field[0][m_2+1][n_2] = 1;
			} else if (single_option_representives_inverted == 1) {
				Field[0][m_2-1][n_2-1] = 1;		//Spieler 1
				Field[0][m_2+1][n_2-1] = 1;
				Field[0][m_2][n_2]   = 11;
				Field[0][m_2-1][n_2+1] = 1;
				Field[0][m_2+1][n_2+1] = 1;
			}

			set_gleiter_rechts_oben (single_option_representives_inverted, Field, 2, m-3, n_2);		//Spieler 2
			set_gleiter_unten_links (single_option_representives_inverted, Field, 3, 2, n-3);		//Spieler 3
			set_gleiter_unten_rechts (single_option_representives_inverted, Field, 4, 2, 2);		//Spieler 4

		} else if (number_of_players == 5) {
			unsigned int m_2, n_2;
			m_2 = (m-1)/2;
			n_2 = (n-1)/2;

			if (single_option_representives_inverted == 0) {
				Field[0][m_2-1][n_2] = 1;		//Spieler 1
				Field[0][m_2][n_2-1] = 1;
				Field[0][m_2][n_2]   = 11;
				Field[0][m_2][n_2+1] = 1;
				Field[0][m_2+1][n_2] = 1;
			} else if (single_option_representives_inverted == 1) {
				Field[0][m_2-1][n_2-1] = 1;		//Spieler 1
				Field[0][m_2+1][n_2-1] = 1;
				Field[0][m_2][n_2]   = 11;
				Field[0][m_2-1][n_2+1] = 1;
				Field[0][m_2+1][n_2+1] = 1;
			}

			set_gleiter_oben_links (single_option_representives_inverted, Field, 2, m-3, n-3);		//Spieler 2
			set_gleiter_links_unten (single_option_representives_inverted, Field, 3, 2, n-3);		//Spieler 3
			set_gleiter_unten_rechts (single_option_representives_inverted, Field, 4, 2, 2);		//Spieler 4
			set_gleiter_rechts_oben (single_option_representives_inverted, Field, 5, m-3, 2);		//Spieler 5

		} else if (number_of_players == 6) {
			unsigned int m_2, nn;
			m_2 = (m-1)/2;
			nn = (n-4)/2;

			if (single_option_representives_inverted == 0) {
				Field[0][m_2-1][nn]	= 1;		//Spieler 1
				Field[0][m_2][nn-1]	= 1;
				Field[0][m_2][nn]	= 11;
				Field[0][m_2][nn+1]	= 1;
				Field[0][m_2+1][nn]	= 1;
			} else if (single_option_representives_inverted == 1) {
				Field[0][m_2-1][nn-1]	= 1;		//Spieler 1
				Field[0][m_2+1][nn-1]	= 1;
				Field[0][m_2][nn]	= 11;
				Field[0][m_2-1][nn+1]	= 1;
				Field[0][m_2+1][nn+1]	= 1;
			}

			set_gleiter_oben_links (single_option_representives_inverted, Field, 2, m_2, n-3);		//Spieler 2
			set_gleiter_links_unten (single_option_representives_inverted, Field, 3, 2, n-7);		//Spieler 3
			set_gleiter_rechts_unten (single_option_representives_inverted, Field, 4, 2, 2);		//Spieler 4
			set_gleiter_rechts_oben (single_option_representives_inverted, Field, 5, m-3, 2);		//Spieler 5
			set_gleiter_links_oben (single_option_representives_inverted, Field, 6, m-3, n-7);		//Spieler 6

		} else if (number_of_players == 7) {
			unsigned int m_2, n_2;
			m_2 = (m-1)/2;
			n_2 = (n-1)/2;

			if (single_option_representives_inverted == 0) {
				Field[0][m_2-1][n_2] = 1;		//Spieler 1
				Field[0][m_2][n_2-1] = 1;
				Field[0][m_2][n_2]   = 11;
				Field[0][m_2][n_2+1] = 1;
				Field[0][m_2+1][n_2] = 1;
			} else if (single_option_representives_inverted == 1) {
				Field[0][m_2-1][n_2-1] = 1;		//Spieler 1
				Field[0][m_2+1][n_2-1] = 1;
				Field[0][m_2][n_2]   = 11;
				Field[0][m_2-1][n_2+1] = 1;
				Field[0][m_2+1][n_2+1] = 1;
			}

			set_gleiter_oben_links (single_option_representives_inverted, Field, 2, m_2, n-3);		//Spieler 2
			set_gleiter_links_unten (single_option_representives_inverted, Field, 3, 2, n-6);		//Spieler 3
			set_gleiter_rechts_unten (single_option_representives_inverted, Field, 4, 2, 5);		//Spieler 4
			set_gleiter_unten_rechts (single_option_representives_inverted, Field, 5, m_2, 2);		//Spieler 5
			set_gleiter_rechts_oben (single_option_representives_inverted, Field, 6, m-3, 5);		//Spieler 6
			set_gleiter_links_oben (single_option_representives_inverted, Field, 7, m-3, n-6);		//Spieler 7

		} else if (number_of_players == 8) {
			unsigned int m_2, n_2;
			m_2 = (m-2)/2;
			n_2 = (n-1)/2;

			if (single_option_representives_inverted == 0) {
				Field[0][m_2-1][n_2] = 1;		//Spieler 1
				Field[0][m_2][n_2-1] = 1;
				Field[0][m_2][n_2]   = 11;
				Field[0][m_2][n_2+1] = 1;
				Field[0][m_2+1][n_2] = 1;
			} else if (single_option_representives_inverted == 1) {
				Field[0][m_2-1][n_2-1] = 1;		//Spieler 1
				Field[0][m_2+1][n_2-1] = 1;
				Field[0][m_2][n_2]   = 11;
				Field[0][m_2-1][n_2+1] = 1;
				Field[0][m_2+1][n_2+1] = 1;
			}

			set_gleiter_oben_links (single_option_representives_inverted, Field, 2, m_2, n-3);		//Spieler 2
			set_gleiter_links_unten (single_option_representives_inverted, Field, 3, 2, n-7);		//Spieler 3
			set_gleiter_rechts_unten (single_option_representives_inverted, Field, 4, 2, 6);		//Spieler 4
			set_gleiter_oben_rechts (single_option_representives_inverted, Field, 5, m_2, 2);		//Spieler 5
			set_gleiter_rechts_oben (single_option_representives_inverted, Field, 6, m-5, 4);		//Spieler 6
			set_mountain_unten (single_option_representives_inverted, Field, 7, m-3, n_2);		//Spieler 7
			set_gleiter_rechts_oben (single_option_representives_inverted, Field, 8, m-5, n-5);		//Spieler 8

		} else if (number_of_players == 9) {
			unsigned int m_2, n_2;
			m_2 = (m-1)/2;
			n_2 = (n-1)/2;

			if (single_option_representives_inverted == 0) {
				Field[0][m_2-1][n_2] = 1;		//Spieler 1
				Field[0][m_2][n_2-1] = 1;
				Field[0][m_2][n_2]   = 11;
				Field[0][m_2][n_2+1] = 1;
				Field[0][m_2+1][n_2] = 1;
			} else if (single_option_representives_inverted == 1) {
				Field[0][m_2-1][n_2-1] = 1;		//Spieler 1
				Field[0][m_2+1][n_2-1] = 1;
				Field[0][m_2][n_2]   = 11;
				Field[0][m_2-1][n_2+1] = 1;
				Field[0][m_2+1][n_2+1] = 1;
			}

			set_mountain_rechts (single_option_representives_inverted, Field, 2, m_2, n-3);		//Spieler 2
			set_edge_oben_rechts (single_option_representives_inverted, Field, 3, 3, n-4);		//Spieler 3
			set_mountain_oben (single_option_representives_inverted, Field, 4, 2, n_2);		//Spieler 4
			set_edge_oben_links (single_option_representives_inverted, Field, 5, 3, 3);		//Spieler 5
			set_mountain_links (single_option_representives_inverted, Field, 6, m_2, 2);		//Spieler 6
			set_edge_unten_links (single_option_representives_inverted, Field, 7, m-4, 3);		//Spieler 7
			set_mountain_unten (single_option_representives_inverted, Field, 8, m-3, n_2);		//Spieler 8
			set_edge_unten_rechts (single_option_representives_inverted, Field, 9, m-4, n-4);		//Spieler 9
		}

	} else if (gamemode_played == Race){
		for (unsigned int p=1; p<=number_of_players; p++) {
			if (p <= number_of_players/2) {
				set_gleiter_unten_rechts (single_option_representives_inverted, Field, p, (((m-2+1)/number_of_players)+1)/2 +(p-1)*((m-2+1)/number_of_players), 3);		//Spieler p
			} else {
				set_gleiter_oben_rechts (single_option_representives_inverted, Field, p, (((m-2+1)/number_of_players)+1)/2 +(p-1)*((m-2+1)/number_of_players), 3);		//Spieler p
			}
			if (p!=number_of_players) {
				Field[0][p*((m-2+1)/number_of_players)][n-2] = Wall_at_the_end;
			}

		}

		for (unsigned int i=1; i<m-1; i+=1){
			Field[0][i][1] = Wall;
		}

	} else if (gamemode_played == Rain){
		for (unsigned int p=1; p<=number_of_players; p++) {
			if (p == 1) {
				set_gleiter_rechts_oben (single_option_representives_inverted, Field, p, m-3, 2);		//Spieler 1
			} else if (p == number_of_players) {
				set_gleiter_links_oben (single_option_representives_inverted, Field, p, m-3, n-3);	//Spieler number_of_players
			} else {
				set_star (single_option_representives_inverted, Field, p, m-3, 3+(p-1)*7);		//Spieler p
			}
		}
	} else if (gamemode_played == Arena){
		if (number_of_players == 2) {
			unsigned int m_2;
			m_2 = (m-1)/2;

			set_gleiter_unten_rechts (single_option_representives_inverted, Field, 1, m_2, 2);		//Spieler 1
			set_gleiter_oben_links (single_option_representives_inverted, Field, 2, m_2, n-3);		//Spieler 2

		} else if (number_of_players == 3) {

			set_star (single_option_representives_inverted, Field, 1, 3, 3);		//Spieler 1
			set_gleiter_unten_links (single_option_representives_inverted, Field, 2, 4, n-3);		//Spieler 2
			set_gleiter_rechts_oben (single_option_representives_inverted, Field, 3, m-3, 4);		//Spieler 3

		} else if (number_of_players == 4) {
			unsigned int m_2, n_2;
			m_2 = (m-1)/2;
			n_2 = (n-1)/2;

			set_gleiter_rechts_oben (single_option_representives_inverted, Field, 1, m-3, n_2);		//Spieler 1
			set_gleiter_links_unten (single_option_representives_inverted, Field, 2, 2, n_2);		//Spieler 2
			set_gleiter_unten_rechts (single_option_representives_inverted, Field, 3, m_2, 2);		//Spieler 3
			set_gleiter_oben_links (single_option_representives_inverted, Field, 4, m_2, n-3);		//Spieler 4

		} else if (number_of_players == 5) {
			unsigned int mm, nn;
			mm = m/2;
			nn = n/2;

			set_gleiter_rechts_oben (single_option_representives_inverted, Field, 1, m-3, nn);		//Spieler 1
			set_gleiter_links_unten (single_option_representives_inverted, Field, 2, 2, nn-1);		//Spieler 2
			set_gleiter_unten_rechts (single_option_representives_inverted, Field, 3, mm, 2);		//Spieler 3
			set_gleiter_oben_links (single_option_representives_inverted, Field, 4, mm-1, n-3);		//Spieler 4
			set_net_basic_two_four (single_option_representives_inverted, Field, 5, mm-1, nn-1);	//Spieler 5

		} else if (number_of_players == 6) {
			unsigned int m_2;
			m_2 = (m-1)/2;

			set_gleiter_oben_rechts (single_option_representives_inverted, Field, 1, m_2, 2);		//Spieler 1
			set_gleiter_unten_links (single_option_representives_inverted, Field, 2, m_2, n-3);		//Spieler 2
			set_gleiter_rechts_unten (single_option_representives_inverted, Field, 3, 2, n-6);		//Spieler 3
			set_gleiter_rechts_unten (single_option_representives_inverted, Field, 4, 2, 5);		//Spieler 4
			set_gleiter_links_oben (single_option_representives_inverted, Field, 5, m-3, 5);		//Spieler 5
			set_gleiter_links_oben (single_option_representives_inverted, Field, 6, m-3, n-6);		//Spieler 6

		} else if (number_of_players == 7) {
			unsigned int mm, nn;
			mm = m/2;
			nn = n/2;

			set_gleiter_oben_rechts (single_option_representives_inverted, Field, 1, mm, 2);		//Spieler 1
			set_gleiter_unten_links (single_option_representives_inverted, Field, 2, mm-1, n-3);		//Spieler 2
			set_gleiter_rechts_unten (single_option_representives_inverted, Field, 3, 2, n-6);		//Spieler 3
			set_gleiter_rechts_unten (single_option_representives_inverted, Field, 4, 2, 5);		//Spieler 4
			set_gleiter_links_oben (single_option_representives_inverted, Field, 5, m-3, 5);		//Spieler 5
			set_gleiter_links_oben (single_option_representives_inverted, Field, 6, m-3, n-6);		//Spieler 6
			set_net_basic_two_four (single_option_representives_inverted, Field, 7, mm-1, nn-1);	//Spieler 7

		} else if (number_of_players == 8) {

			set_gleiter_unten_rechts (single_option_representives_inverted, Field, 1, 5, 2);		//Spieler 1
			set_gleiter_oben_links (single_option_representives_inverted, Field, 2, 5, n-3);		//Spieler 2
			set_gleiter_links_unten (single_option_representives_inverted, Field, 3, 2, n-6);		//Spieler 3
			set_gleiter_links_unten (single_option_representives_inverted, Field, 4, 2, 5);		//Spieler 4
			set_gleiter_rechts_oben (single_option_representives_inverted, Field, 5, m-3, 5);		//Spieler 5
			set_gleiter_rechts_oben (single_option_representives_inverted, Field, 6, m-3, n-6);		//Spieler 6
			set_gleiter_unten_rechts (single_option_representives_inverted, Field, 7, m-6, 2);		//Spieler 7
			set_gleiter_oben_links (single_option_representives_inverted, Field, 8, m-6, n-3);		//Spieler 8

		} else if (number_of_players == 9) {
			unsigned int mm, nn;
			mm = m/2;
			nn = n/2;

			set_gleiter_unten_rechts (single_option_representives_inverted, Field, 1, 5, 2);		//Spieler 1
			set_gleiter_oben_links (single_option_representives_inverted, Field, 2, 5, n-3);		//Spieler 2
			set_gleiter_links_unten (single_option_representives_inverted, Field, 3, 2, n-6);		//Spieler 3
			set_gleiter_links_unten (single_option_representives_inverted, Field, 4, 2, 5);		//Spieler 4
			set_gleiter_rechts_oben (single_option_representives_inverted, Field, 5, m-3, 5);		//Spieler 5
			set_gleiter_rechts_oben (single_option_representives_inverted, Field, 6, m-3, n-6);		//Spieler 6
			set_gleiter_unten_rechts (single_option_representives_inverted, Field, 7, m-6, 2);		//Spieler 7
			set_gleiter_oben_links (single_option_representives_inverted, Field, 8, m-6, n-3);		//Spieler 8
			set_net_basic_two_four (single_option_representives_inverted, Field, 9, mm-1, nn-1);	//Spieler 9
		}

	} else if (gamemode_played == Ulcer) {
		for (unsigned int i=1; i<=(m-2); i+=1) {
			if (i%3 != 0) {
				set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, i, 3, 1);
			}
		}
		for (unsigned int j=1; j<=(n-2); j+=1) {
			if (j%3 != 0) {
				set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, 3, j, 1);
			}
		}
		set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, 5, 5, 1);

	} else if (gamemode_played == Dynamic) {
		unsigned int m_2, n_2;
		m_2 = (m-1)/2;
		n_2 = (n-1)/2;

		if (number_of_players == 2) {

			set_gleiter_unten_rechts (single_option_representives_inverted, Field, 1, m_2, 2);		//Spieler 1
			set_gleiter_unten_links (single_option_representives_inverted, Field, 2, m_2, n-3);		//Spieler 2

		} else if (number_of_players == 3) {

			set_gleiter_unten_rechts (single_option_representives_inverted, Field, 1, m_2, 2);		//Spieler 1
			set_mountain_oben (single_option_representives_inverted, Field, 2, 2, n_2);		//Spieler 2
			set_gleiter_unten_links (single_option_representives_inverted, Field, 3, m_2, n-3);		//Spieler 3

		} else if (number_of_players == 4) {

			set_gleiter_unten_rechts (single_option_representives_inverted, Field, 1, m_2, 2);		//Spieler 1
			set_mountain_oben (single_option_representives_inverted, Field, 2, 2, n_2);		//Spieler 2
			set_gleiter_unten_links (single_option_representives_inverted, Field, 3, m_2, n-3);		//Spieler 3
			set_mountain_unten (single_option_representives_inverted, Field, 4, m-3, n_2);		//Spieler 4

		} else if (number_of_players == 5) {

			set_gleiter_unten_rechts (single_option_representives_inverted, Field, 1, m_2, 2);		//Spieler 1
			set_mountain_oben (single_option_representives_inverted, Field, 2, 2, n_2);		//Spieler 2
			set_gleiter_unten_links (single_option_representives_inverted, Field, 3, m_2, n-3);		//Spieler 3
			set_gleiter_rechts_oben (single_option_representives_inverted, Field, 4, m-3, n_2+1);		//Spieler 4
			set_f_links_oben (single_option_representives_inverted, Field, 5, m-3, n_2-1);		//Spieler 5

		} else if (number_of_players == 6) {

			set_gleiter_unten_rechts (single_option_representives_inverted, Field, 1, m_2+1, 2);		//Spieler 1
			set_gleiter_links_unten (single_option_representives_inverted, Field, 2, 2, n_2-1);		//Spieler 2
			set_gleiter_unten_links (single_option_representives_inverted, Field, 3, m_2+1, n-3);		//Spieler 3
			set_f_oben_rechts (single_option_representives_inverted, Field, 4, m_2-1, 2);		//Spieler 4
			set_f_rechts_unten (single_option_representives_inverted, Field, 5, 2, n_2+1);		//Spieler 5
			set_f_oben_links (single_option_representives_inverted, Field, 6, m_2-1, n-3);		//Spieler 6

		} else if (number_of_players == 7) {

			set_gleiter_unten_rechts (single_option_representives_inverted, Field, 1, m_2+1, 2);		//Spieler 1
			set_mountain_oben (single_option_representives_inverted, Field, 2, 2, n_2);		//Spieler 2
			set_gleiter_unten_links (single_option_representives_inverted, Field, 3, m_2+1, n-3);		//Spieler 3
			set_gleiter_rechts_oben (single_option_representives_inverted, Field, 4, m-3, n_2+1);		//Spieler 4
			set_f_oben_rechts (single_option_representives_inverted, Field, 5, m_2-1, 2);		//Spieler 5
			set_f_oben_links (single_option_representives_inverted, Field, 6, m_2-1, n-3);		//Spieler 6
			set_f_links_oben (single_option_representives_inverted, Field, 7, m-3, n_2-1);		//Spieler 7

		} else if (number_of_players == 8) {

			set_gleiter_unten_rechts (single_option_representives_inverted, Field, 1, m_2+1, 2);		//Spieler 1
			set_gleiter_links_unten (single_option_representives_inverted, Field, 2, 2, n_2-1);		//Spieler 2
			set_gleiter_unten_links (single_option_representives_inverted, Field, 3, m_2+1, n-3);		//Spieler 3
			set_gleiter_rechts_oben (single_option_representives_inverted, Field, 4, m-3, n_2+1);		//Spieler 4
			set_f_oben_rechts (single_option_representives_inverted, Field, 5, m_2-1, 2);		//Spieler 5
			set_f_rechts_unten (single_option_representives_inverted, Field, 6, 2, n_2+1);		//Spieler 6
			set_f_oben_links (single_option_representives_inverted, Field, 7, m_2-1, n-3);		//Spieler 7
			set_f_links_oben (single_option_representives_inverted, Field, 8, m-3, n_2-1);		//Spieler 8

		} else if (number_of_players == 9) {

			set_gleiter_unten_rechts (single_option_representives_inverted, Field, 1, m_2+2, 2);		//Spieler 1
			set_gleiter_links_unten (single_option_representives_inverted, Field, 2, 2, n_2-2);		//Spieler 2
			set_gleiter_unten_links (single_option_representives_inverted, Field, 3, m_2+2, n-3);		//Spieler 3
			set_gleiter_oben_rechts (single_option_representives_inverted, Field, 4, m_2-2, 2);		//Spieler 4
			set_gleiter_rechts_unten (single_option_representives_inverted, Field, 5, 2, n_2+2);		//Spieler 5
			set_gleiter_oben_links (single_option_representives_inverted, Field, 6, m_2-2, n-3);		//Spieler 6
			set_mountain_links (single_option_representives_inverted, Field, 7, m_2, 2);		//Spieler 7
			set_mountain_oben (single_option_representives_inverted, Field, 8, 2, n_2);		//Spieler 8
			set_mountain_rechts (single_option_representives_inverted, Field, 7, m_2, n-3);		//Spieler 9

		}

		Field[0][m_2][n_2] = Dynamic_ball;

	} else if (gamemode_played == Survive) {
		if (number_of_players >= 1) {
			set_gleiter_unten_rechts (single_option_representives_inverted, Field, 1, 2, 2);		//Spieler 1
		}
		if (number_of_players >= 2) {
			set_gleiter_links_unten (single_option_representives_inverted, Field, 2, 2, n-3);		//Spieler 2
		}
		if (number_of_players >= 3) {
			set_gleiter_oben_links (single_option_representives_inverted, Field, 3, m-3, n-3);		//Spieler 3
		}
		if (number_of_players >= 4) {
			set_gleiter_rechts_oben (single_option_representives_inverted, Field, 4, m-3, 2);		//Spieler 4
		}
		if (number_of_players == 5) {
			unsigned int n_2;
			unsigned int m_2;
			n_2 = (n-1)/2;
			m_2 = (m-1)/2;

			set_star (single_option_representives_inverted, Field, 5, m_2, n_2);		//Spieler 5

		} else if (number_of_players > 5) {
			unsigned int m_2;
			m_2 = (m-1)/2;

			set_mountain_rechts (single_option_representives_inverted, Field, 5, m_2, n-3);		//Spieler 5

		}
		if (number_of_players >= 6) {
			unsigned int m_2;
			m_2 = (m-1)/2;

			set_mountain_links (single_option_representives_inverted, Field, 6, m_2, 2);		//Spieler 6

		}
		if (number_of_players == 7) {
			unsigned int n_2;
			unsigned int m_2;
			n_2 = (n-1)/2;
			m_2 = (m-1)/2;

			set_star (single_option_representives_inverted, Field, 7, m_2, n_2);		//Spieler 7

		} else if (number_of_players > 7) {
			unsigned int n_2;
			n_2 = (n-1)/2;

			set_mountain_oben (single_option_representives_inverted, Field, 7, 2, n_2);		//Spieler 7

		}
		if (number_of_players >= 8) {
			unsigned int n_2;
			n_2 = (n-1)/2;

			set_mountain_unten (single_option_representives_inverted, Field, 8, m-3, n_2);		//Spieler 8

		}
		if (number_of_players >= 9) {
			unsigned int n_2;
			unsigned int m_2;
			n_2 = (n-1)/2;
			m_2 = (m-1)/2;

			set_star (single_option_representives_inverted, Field, 9, m_2, n_2);		//Spieler 9

		}
	} else if (gamemode_played == Sand) {
		for (unsigned int p=1; p<=number_of_players; p++) {
			if (p%2 == 1) {
				set_gleiter_rechts_oben (single_option_representives_inverted, Field, p, m-3, 2+(p-1)*4 );		//Spieler p
			} else if (p%2 == 0) {
				set_gleiter_links_oben (single_option_representives_inverted, Field, p, m-3, 2+(p-1)*4);		//Spieler p
			}
		}
	} else if (gamemode_played == Quidditch) {
		for (unsigned int j=(n-1)/2 -2; j<=(n-1)/2 +2; j+=2) {	//Torringe
			set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, 1, j, Torring_1);
			set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, m-2, j, Torring_2);
		}
		set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, (m-2)/2 -1, (n-1)/2, Klatscher);	//Quidditch Bälle
		set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, (m-2)/2, (n-1)/2, Quaffel);
		set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, (m-2)/2 +1, (n-1)/2, Schnatz);
		set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, (m-2)/2 +2, (n-1)/2, Klatscher);
		
		set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, 1+2, (n-1)/2, Hueter_1);	//Team_1
		set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, (m-2)/2 -2, 2, Jaeger_1);
		set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, (m-2)/2 -2, n-3, Jaeger_1);
		set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, (m-2)/2 -3, 4, Treiber_1);
		set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, (m-2)/2 -3, n-5, Treiber_1);
		set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, (m-2)/2 -4, (n-1)/2 +1, Jaeger_1);
		set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, (m-2)/2 -5, (n-1)/2 -2, Sucher_1);
		
		set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, (m-2)-2, (n-1)/2, Hueter_2);	//Team_2
		set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, (m-2)/2 +3, 2, Jaeger_2);
		set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, (m-2)/2 +3, n-3, Jaeger_2);
		set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, (m-2)/2 +4, 4, Treiber_2);
		set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, (m-2)/2 +4, n-5, Treiber_2);
		set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, (m-2)/2 +5, (n-1)/2 -1, Jaeger_2);
		set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, (m-2)/2 +6, (n-1)/2 +2, Sucher_2);
		
		set_triangle_unten_rechts (single_option_representives_inverted, Field, 1, 1+2, (n-1)/2 -1);	//Squares player 1
		set_triangle_unten_links (single_option_representives_inverted, Field, 1, 1+2, (n-1)/2 +1);
		set_triangle_oben_links (single_option_representives_inverted, Field, 1, (m-2)/2 -1, 1);
		set_triangle_oben_rechts (single_option_representives_inverted, Field, 1, (m-2)/2 -1, n-2);
		set_gleiter_links_unten (single_option_representives_inverted, Field, 1, (m-2)/2 -4, (n-1)/2);
		set_triangle_oben_links (single_option_representives_inverted, Field, 1, 1+3, n-3);
		set_triangle_oben_rechts (single_option_representives_inverted, Field, 1, 1+3, 2);
		
		set_triangle_oben_rechts (single_option_representives_inverted, Field, 2, (m-2) -2, (n-1)/2 -1);	//Squares player 2
		set_triangle_oben_links (single_option_representives_inverted, Field, 2, (m-2) -2, (n-1)/2 +1);
		set_triangle_unten_links (single_option_representives_inverted, Field, 2, (m-2)/2 +2, 1);
		set_triangle_unten_rechts (single_option_representives_inverted, Field, 2, (m-2)/2 +2, n-2);
		set_gleiter_rechts_oben (single_option_representives_inverted, Field, 2, (m-2)/2 +5, (n-1)/2);
		set_triangle_unten_links (single_option_representives_inverted, Field, 2, m-5, n-3);
		set_triangle_unten_rechts (single_option_representives_inverted, Field, 2, m-5, 2);
	}
}

void new_life (Spielfeld Spiel, Spielfeld Field, unsigned int m, unsigned int n, unsigned int w, unsigned int gamemode_played, unsigned int* information_code, unsigned int geben, Evolution evolution, Spielfeld Opague_o_field, Special_Fields Allocation_o, unsigned int number_of_players){
	Spielfeld temp_new_life;
	unsigned int a, inhi;

	#ifdef VERBOSE
	printf("	new_life_ok.0 \n");	//test
	#endif

	temp_new_life = Spielfeld_Create (m, n, 0);		//inhibitor in information_code[1], ability in information_code[0]
	a = 0;
	inhi = 0;

	// printf("	w: %u\n", w);	//test

	if (gamemode_played != Race) {
		for (unsigned int i=1; i<m-1; i+=1){
			for (unsigned int j=1; j<n-1; j+=1){
				if ((Spiel[0][i][j] == 0)||(Spiel[0][i][j] == Traps)) {	//Traps only used in Survive
					for (unsigned int h=i-1; h<=i+1; h+=1){
						for (unsigned int k=j-1; k<=j+1; k+=1){
							if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
								if (((gamemode_played != Hunt)||(geben != 1))&&(gamemode_played != Arena)) {
									if (Spiel[0][h][k] == geben){
										a+=1;
									}
								} else if ((gamemode_played == Hunt)&&(geben == 1)) {
									if ((Spiel[0][h][k] == 1)||(Spiel[0][h][k] == 11)){
										a+=1;
									}
								} else if (gamemode_played == Arena) {
									if (Spiel[0][h][k] == geben){
										a+=1;
									}
									if ((information_code[1] != 0)&&(information_code[1] != 100)&&(Spiel[0][h][k] == information_code[1])&&(information_code[0] != 6)&&(information_code[0] != 5)) {
										inhi += 1;
									}
								}
							}
						}
					}				//w=3, w=2, w=4
					if (gamemode_played != Arena) {
						if (w == 4){
							if ((a == w) || (a == w+1)){
								set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, temp_new_life, 0, i, j, geben);
							}
						} else {
							if (a == w){
								set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, temp_new_life, 0, i, j, geben);
							}
						}
						a = 0;
					} else if (gamemode_played == Arena) {
						if (inhi != 3) {
							if (information_code[0] == 1) {
								if (w == 2){
									if ((a == w) || (a == w+1)){
										set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, temp_new_life, 0, i, j, geben);
									}
								} else {
									if (a == w){
										if (w == 1) {
											set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, temp_new_life, 0, i, j, geben);
										} else if (w == 0) {
											for (unsigned int h=i-1; h<=i+1; h+=1){
												for (unsigned int k=j-1; k<=j+1; k+=1){
													if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
														if (Spiel[0][h][k] != 0) {
															inhi = 10;
															break;
														}
													}
												}
												if (inhi == 10) {
													break;
												}
											}
											if (inhi != 10) {
												set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, temp_new_life, 0, i, j, geben);
											}
										}
									}
								}
							} else if (information_code[0] == 2) {
								if (w == 3){
									if ((a == w) || (a == w+1)){
										set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, temp_new_life, 0, i, j, geben);
									}
								} else {
									if (a == w){
										set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, temp_new_life, 0, i, j, geben);
									}
								}
							} else if (information_code[0] == 3) {
								if (w == 5){
									if ((a == w) || (a == w+1)){
										set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, temp_new_life, 0, i, j, geben);
									}
								} else {
									if (a == w){
										set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, temp_new_life, 0, i, j, geben);
									}
								}
							} else if (information_code[0] == 4) {	//Cornered
								if (w == 4){
									if ((a == w) || (a == w+1)){
										set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, temp_new_life, 0, i, j, geben);
									}
								} else {
									if (a == w){
										set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, temp_new_life, 0, i, j, geben);
									}  else if ((a == (w-1))&&((j == (n-2))||(j == 1)||(i == (m-2))||(i == 1))) {
										set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, temp_new_life, 0, i, j, geben);
									}
								}
							} else {
								if (w == 4){
									if ((a == w) || (a == w+1)){
										set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, temp_new_life, 0, i, j, geben);
									}
								} else {
									if (a == w){
										set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, temp_new_life, 0, i, j, geben);
									}
								}
							}
						}
						a = 0;
						inhi = 0;
					}

				}
				if ((gamemode_played == Ulcer)&&((Spiel[0][i][j] == 2)&&(geben == 1))) {
					for (unsigned int h=i-1; h<=i+1; h+=1){
						for (unsigned int k=j-1; k<=j+1; k+=1){
							if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
								if (Spiel[0][h][k] == geben){
									a+=1;
								}
							}
						}
					}
					if (w == 4){
						if ((a == w) || (a == w+1)){
							set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, temp_new_life, 0, i, j, geben);
						}
					} else {
						if (a == w){
							set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, temp_new_life, 0, i, j, geben);
						}
					}
					a = 0;
				}
			}
		}
		if ((gamemode_played == Survive)&&(information_code[1] >= 1)) {	//with Traps?
			for (unsigned int i=1; i<m-1; i+=1){
				for (unsigned int j=1; j<n-1; j+=1){

					if ((Spiel[0][i][j] == Traps)&&(temp_new_life[0][i][j] == geben)) {

						printf("(Allocation_o.characterization+1)/2: %u \n", (Allocation_o.characterization+1)/2);	//test

						for (unsigned int h=i-1; h<=i+1; h+=1){
							for (unsigned int k=j-1; k<=j+1; k+=1){
								if (((h+k)%2 == (i+j+1)%2)||((k == j)&&(h == i))) {
									if (Spiel[0][h][k] == geben) {
										set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, evolution.od, geben, h, k, 101*geben);
										if (Allocation_o.characterization != 0) {
											set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Allocation_o.field, 1, h, k, (Allocation_o.characterization+1/2));	//Half of allocation-max
										}
									} else {
										set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, h, k, 0);
									}
									set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, temp_new_life, 0, h, k, 0);
								}
							}
						}
					}
				}
			}
		}

	} else if (gamemode_played == Race) {
		for (unsigned int i=(geben-1)*((m-2+1)/number_of_players)+1; i<=geben*((m-2+1)/number_of_players); i+=1){
			for (unsigned int j=1; j<n-1; j+=1){
				if (Spiel[0][i][j] == 0) {
					for (unsigned int h=i-1; h<=i+1; h+=1){
						for (unsigned int k=j-1; k<=j+1; k+=1){
							if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))&&(i<(m-1))&&(i>0)){
								if (Spiel[0][h][k] == geben){
									a+=1;
								}
							}
						}
					}				//w=3, w=2, w=4
					if(w == 4){
						if ((a == w) || (a == w+1) ){
							set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, temp_new_life, 0, i, j, geben);
						}
					} else {
						if (a == w){
							set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, temp_new_life, 0, i, j, geben);
						}
					}
					a = 0;

				}
			}
		}
	}

	// printf("almost end of new_life \n");	//test
	
	for (unsigned int i=1; i<m-1; i+=1){
		for (unsigned int j=1; j<n-1; j+=1){
			if (temp_new_life[0][i][j] == geben) {
				set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, evolution.nl, geben, i, j, geben);
			}
		}
	}

	Spielfeld_Destroy (temp_new_life, m, 0);

	#ifdef VERBOSE
	printf("end of new_life \n");	//test
	#endif

}

void old_dying (Spielfeld Spiel, Spielfeld Field, unsigned int m, unsigned int n, unsigned int d, unsigned int e, unsigned int gamemode_played, unsigned int* information_code, unsigned int geben, Spielfeld evolution_od, unsigned int w, Special_Fields Allocation_o, Spielfeld Opague_o_field, unsigned int number_of_players){
	Spielfeld temp_old_dying;
	unsigned int a, e_down, d_up;

	temp_old_dying = Spielfeld_Create (m, n, 0);
	a = 0;
	e_down = 0;
	d_up = 0;

	#ifdef VERBOSE
	printf("old_dying ok.1 \n");	//test
	#endif

	for (unsigned int i=1; i<m-1; i+=1){
		for (unsigned int j=1; j<n-1; j+=1){
			if (Spiel[0][i][j] == geben) {
				if (gamemode_played == Arena) {
					if ((information_code[2] != 0)&&(information_code[2] != 100)&&(information_code[0] != 7)&&(information_code[0] != 6)) {
						if ((Spiel[0][i+1][j] == information_code[2])||(Spiel[0][i][j-1] == information_code[2])||(Spiel[0][i][j+1] == information_code[2])||(Spiel[0][i-1][j] == information_code[2])) {
							d_up = 1;
							d += 1;
						}
					}
					if ((information_code[3] != 0)&&(information_code[3] != 100)&&(information_code[0] != 8)&&(information_code[0] != 6)) {	//wenn du kein Shield hast oder die Angriffseigenschaft selbst besitzt.
						if ((Spiel[0][i+1][j] == information_code[3])||(Spiel[0][i][j-1] == information_code[3])||(Spiel[0][i][j+1] == information_code[3])||(Spiel[0][i-1][j] == information_code[3])) {
							e_down = 1;
							e -= 1;
						}
					}
				}

				// printf("old_dying ok.2 \n");	//test

				for (unsigned int h=i-1; h<=i+1; h+=1){
					for (unsigned int k=j-1; k<=j+1; k+=1){
						if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
							if (((gamemode_played != Hunt)||(geben != 1))&&(gamemode_played != Arena)) {
								if (Spiel[0][h][k] == geben){
									a+=1;
								}
							} else if ((gamemode_played == Hunt)&&(geben == 1)) {
								if ((Spiel[0][h][k] == 1)||(Spiel[0][h][k] == 11)){
									a+=1;
								}
							} else if (gamemode_played == Arena) {
								if (Spiel[0][h][k] == geben){
									a+=1;
								}
							}
						}
					}
				}

				if ((gamemode_played != Arena)&&(gamemode_played != Ulcer)) {
					if ((a < d+1) || (a > e+1)){		//d=2, d=1, e=3, e=4, +1 wegen des Steines selbst, da er mitgezählt wird
						set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, temp_old_dying, 0, i, j, 101*geben);		//Code für das Eleminieren
					}

					if (Allocation_o.characterization != 0) {
						if (w == 4) {
							if ((a == w+1)||(a == w+2)) {
								if (Allocation_o.field[0][i][j] < Allocation_o.characterization) {
									Allocation_o.field[0][i][j] += 1;
								}
							}
						} else {
							if (a == w+1) {
								if (Allocation_o.field[0][i][j] < Allocation_o.characterization) {
									Allocation_o.field[0][i][j] += 1;
								}
							}
						}

						if (a < d+1){
							set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Allocation_o.field, 1, i, j, (d+1-a));
						} else if (a > e+1) {
							set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Allocation_o.field, 1, i, j, (a-e-1));
						}
					}

					a = 0;
				} else if (gamemode_played == Ulcer) {
					if ((a < d+1) || (a > e+1)){		//d=2, d=1, e=3, e=4, +1 wegen des Steines selbst, da er mitgezählt wird
						set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, temp_old_dying, 0, i, j, 101*geben);		//Code für das Eleminieren
					}

					if (Allocation_o.characterization != 0) {
						if (e-d == 1) {	//e und d nicht verändert
							if (w == e+1) {
								if ((a == w+1)||(a == w+2)) {
									if (Allocation_o.field[0][i][j] < Allocation_o.characterization) {
										Allocation_o.field[0][i][j] += 1;
									}
								}
							} else {
								if (a == w+1) {
									if (Allocation_o.field[0][i][j] < Allocation_o.characterization) {
										Allocation_o.field[0][i][j] += 1;
									}
								}
							}
						} else if (e-d == 2) {	//e oder d verändert, also w nicht
							if (a == w+1) {
								if (Allocation_o.field[0][i][j] < Allocation_o.characterization) {
									Allocation_o.field[0][i][j] += 1;
								}
							}
						}

						if (a < d+1){
							set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Allocation_o.field, 1, i, j, (d+1-a));
						} else if (a > e+1) {
							set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Allocation_o.field, 1, i, j, (a-e-1));
						}
					}

					a = 0;
				} else if (gamemode_played == Arena) {
					if ((d == 11)||(d == 10)) {
						d = 0;
						d_up += 10;
					}

					if ((a < d+1) || (a > e+1)){
						set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, temp_old_dying, 0, i, j, 101*geben);
					}
					if (Allocation_o.characterization != 0) {

						if (a < d+1){
							set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Allocation_o.field, 1, i, j, (d+1-a));
						} else if (a > e+1) {
							set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Allocation_o.field, 1, i, j, (a-e-1));
						}
					}

					if ((d_up == 1)||(d_up == 11)) {
						d -= 1;
					}
					if ((d_up == 10)||(d_up == 11)) {
						d = 10;	//für den nächsten Eintrag
					}
					if (e_down == 1) {
						e += 1;
					}
					d_up = 0;
					e_down = 0;	//d und e bereinigt

					if (Allocation_o.characterization != 0) {

						if (information_code[0] == 3) {	//Anti
							if (w == 5) {
								if ((a == w+1)||(a == w+2)) {
									if (Allocation_o.field[0][i][j] < Allocation_o.characterization) {
										Allocation_o.field[0][i][j] += 1;
									}
								}
							} else {
								if (a == w+1) {
									if (Allocation_o.field[0][i][j] < Allocation_o.characterization) {
										Allocation_o.field[0][i][j] += 1;
									}
								}
							}
						} else if (e-d == 1) {	//e und d nicht verändert (or ultra_light with changed d)
							if (w == e+1) {
								if ((a == w+1)||(a == w+2)) {
									if (Allocation_o.field[0][i][j] < Allocation_o.characterization) {
										Allocation_o.field[0][i][j] += 1;
									}
								} else if ((information_code[0] == 4)&&((a == w)||(a == w+1))&&((j == (n-2))||(j == 1)||(i == (m-2))||(i == 1))) {
									if (Allocation_o.field[0][i][j] < Allocation_o.characterization) {
										Allocation_o.field[0][i][j] += 1;
									}
								}
							} else {
								if (a == w+1) {
									if (Allocation_o.field[0][i][j] < Allocation_o.characterization) {
										Allocation_o.field[0][i][j] += 1;
									}
								} else if ((information_code[0] == 4)&&(a == w)&&((j == (n-2))||(j == 1)||(i == (m-2))||(i == 1))) {
									if (Allocation_o.field[0][i][j] < Allocation_o.characterization) {
										Allocation_o.field[0][i][j] += 1;
									}
								}
							}
						} else if (e-d == 2) {	//e oder d verändert, also w nicht
							if (a == w+1) {
								if (Allocation_o.field[0][i][j] < Allocation_o.characterization) {
									Allocation_o.field[0][i][j] += 1;
								}
							} else if ((information_code[0] == 4)&&(a == w)&&((j == (n-2))||(j == 1)||(i == (m-2))||(i == 1))) {
								if (Allocation_o.field[0][i][j] < Allocation_o.characterization) {
									Allocation_o.field[0][i][j] += 1;
								}
							}
						}
					}

					a = 0;
				}
			}
		}
	}

	// printf("old_dying ok.3 \n");	//test

	for (unsigned int i=1; i<m-1; i+=1){
		for (unsigned int j=1; j<n-1; j+=1){
			if (temp_old_dying[0][i][j] == 101*geben) {
				set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, evolution_od, geben, i, j, 101*geben);
			}
		}
	}

	Spielfeld_Destroy (temp_old_dying, m, 0);

	#ifdef VERBOSE
	printf("old_dying ok.4 \n");	//test
	#endif

	// printf("	101*geben=%u, geben=%u \n", 101*geben, geben);	//test

}

void change (Spielfeld Spiel, unsigned int* level, Spielfeld Sf_permutations, Spielfeld Field, Evolution evolution, unsigned int m, unsigned int n, unsigned int gamemode_played, unsigned int number_of_players, unsigned int* ges, unsigned int geben, Special_Fields Allocation_o, Spielfeld Opague_o_field, unsigned int* information_code, Growth_Player* Growth_players, Single_option_representives single_option_representives){

	unsigned int a;
	a = 0;

	#ifdef VERBOSE
	printf("change ok.1 \n"); //test
	#endif

	for (unsigned int i=1; i<m-1; i+=1){
		for (unsigned int j=1; j<n-1; j+=1){
			if (Spiel[0][i][j] == geben){

				// printf("change ok.2 \n"); //test

				if (evolution.od[geben][i][j] == 101*geben){

					// printf("change ok.3 \n"); //test

					if (Allocation_o.characterization != 0) {	//So Allocation is activated
						for (unsigned int p=1; p<=Allocation_o.field[1][i][j]; p++) {
							Allocation_o.field[0][i][j] -= 1;
							if (Allocation_o.field[0][i][j] == 0) {
								break;
							}
						}
						if (Allocation_o.field[0][i][j] == 0) {
							set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j, 0);

							if ((gamemode_played == Ulcer)&&(ges[Nachfolger(geben, number_of_players)] != 1010*geben)) {
								set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j, Nachfolger(geben, number_of_players));
							}
							if (single_option_representives.undead_duration != 0) {
								set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j, single_option_representives.undead_duration*10000);
							}
						}

					} else {
						set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j, 0);
						if ((gamemode_played == Ulcer)&&(ges[Nachfolger(geben, number_of_players)] != 1010*geben)) {
							set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j, Nachfolger(geben, number_of_players));
						}
						if (single_option_representives.undead_duration != 0) {
							set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j, single_option_representives.undead_duration*10000);
						}
					}

				}

				// printf("change ok.3 \n"); //test

				if ((gamemode_played == Ulcer)&&(geben != 1)) {
					for (unsigned int h=i-1; h<=i+1; h+=1){
						for (unsigned int k=j-1; k<=j+1; k+=1){
							if (Spiel[0][h][k] == Vorganger (geben, number_of_players)) {
								a = 1;
								break;
							}
						}
						if (a == 1) {
							break;
						}
					}
					if (a != 1) {
						set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j, Nachfolger(geben, number_of_players));
					}

					a = 0;
				}
			} else if (Spiel[0][i][j] == 0){
				if (evolution.nl[geben][i][j] == geben){
					set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j, geben);
				}
			} else if ((gamemode_played == Ulcer)&&(geben == 1)&&(Spiel[0][i][j] == 2)){	//player one takes back squares from player 2
				if (evolution.nl[geben][i][j] == 1){
					set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j, 1);
				}
			} else if ((single_option_representives.undead_duration != 0)&&(Spiel[0][i][j] >= 10000)) {	//because nothing is higher than 10000
				Spiel[0][i][j]-=10000;
				if ((Spiel[0][i][j] == 0)&&(gamemode_played == Ulcer)) {
					set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j, Nachfolger(geben, number_of_players));
				}
			}
		}
	}

	if (single_option_representives.inverted != 0) {
		inverted_organism (Spiel, level, Sf_permutations, Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, m, n, information_code, Growth_players);
	}

	// printf("change:	101*geben=%u, geben=%u \n", 101*geben, geben); //test

	for (unsigned int i=1; i<m-1; i+=1){
		for (unsigned int j=1; j<n-1; j+=1){
			set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, evolution.od, geben, i, j, 0);
			set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, evolution.nl, geben, i, j, 0);
			set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Allocation_o.field, 1, i, j, 0);	//KI testing... warning	//Ausnahme für += Realisierung im 0-Fall
		}
	}

	#ifdef VERBOSE
	printf("change ok.4 \n"); //test
	#endif

}

unsigned int Vorganger (unsigned int geben, unsigned int number_of_players) {
	unsigned int vorher;
	vorher = 0;

	if (geben == 1) {
		vorher = number_of_players;
	} else {
		vorher = geben - 1;
	}

	return vorher;
}

unsigned int Nachfolger (unsigned int geben, unsigned int number_of_players) {
	unsigned int nachher;
	nachher = 0;

	nachher = (geben%number_of_players) + 1;

	return nachher;
}

void show_field (unsigned int number_of_players, unsigned int* level, Spielfeld Sf_permutations, Spielfeld Opague_o_field, Spielfeld Spiel, unsigned int m, unsigned int n, unsigned int gamemode_played, unsigned int* information_code, unsigned int geben, Growth_Player* Growth_players, unsigned int auswerter, Special_Fields Allocation_o){
	unsigned int allocation_choice;
	allocation_choice = 0;

	#ifdef VERBOSE
	printf("show_field ok.1 \n"); //test
	#endif
	
	if (level[0] <= 2) {	//so it is necessary
		//number_of_players increased go on (done?)
		if (Spiel == Opague_o_field) {
			allocation_choice = 2;
		}

		printf("\n");

		printf("      ");
		for (unsigned int p=1; p<=n-2; p+=1){		//Nummerierung
			if (p%7 == 0) {
				set_terminal_color (cBROWN);
			}
			if (p<10){
				printf("%u  ", p);
			} else {
				printf("%u ", p);
			}
			set_terminal_color (cNORMAL);
		}
		printf("   ");	//üc bosluk

		if (Allocation_o.characterization != 0) {
			printf("		");	//two tabs
			printf("    ");	//dört bosluk
			for (unsigned int p=1; p<=n-2; p+=1){
				if (p<10){
					printf("%u  ", p);
				} else {
					printf("%u ", p);
				}
			}
			printf("   ");	//üc bosluk
		}

		if (Sf_permutations[0][1][1] != 0) {
			printf("		");	//two tabs
			printf("    ");	//dört bosluk
			for (unsigned int p=1; p<=n-2; p+=1){
				if (p<10){
					printf("%u  ", p);
				} else {
					printf("%u ", p);
				}
			}
		}

		printf("\n");

		for (unsigned int i=1; i<m-1; i+=1){

			printf("     +");
			for (unsigned int t=1; t<=n-2; t+=1){		//Zwischenzeilen
				printf("--+");
			}
			printf("   ");	//üc bosluk

			if (Allocation_o.characterization != 0) {
				printf("	");	//two tabs
				printf("     +");
				for (unsigned int t=1; t<=n-2; t+=1){
					printf("--+");
				}
				printf("   ");	//üc bosluk
			}

			if (Sf_permutations[0][1][1] != 0) {
				printf("	");	//two tabs
				printf("     +");
				for (unsigned int t=1; t<=n-2; t+=1){
					printf("--+");
				}
			}

			printf("\n");

			for (unsigned int v=1; v<=2; v+=1){		//Doppel-Ausführung, ab 10 wird korrigiert, bis 99 gültig

				if (i<10){
					printf("   %u |", i);
				} else {
					printf("  %u |", i);
				}
				for (unsigned int j=1; j<n-1; j+=1){	//Haupzeilen
					
					if (Growth_players[0].color == 1) {
						Square_color_interpretation (Growth_players, geben, number_of_players, Spiel[auswerter][i][j]);
					}
					
					if (Spiel[auswerter][i][j] == 0){
						printf("  ");
					} else if (Spiel[auswerter][i][j] == dogum){
						printf("NN");
					} else if (Spiel[auswerter][i][j] == oeluem){
						printf("D ");
					} else if (Spiel[auswerter][i][j] == bir_sey){	//hint
						printf("::");
					} else if (Spiel[auswerter][i][j] >= 10000){
						printf("??");
					}

					if (gamemode_played == Hunt) {
						if (Spiel[auswerter][i][j] == 1) {
							if ((geben == 1)||((information_code[3] == 1)&&((Spiel[auswerter][i+1][j] == geben)||(Spiel[auswerter][i-1][j] == geben)||(Spiel[auswerter][i][j+1] == geben)||(Spiel[auswerter][i][j-1] == geben)))||((information_code[1] == 1)&&(information_code[2] == 1))){
								printf("##");
							} else {
								printf("  ");
							}
						} else if (Spiel[auswerter][i][j] == 2){
							printf("AA");
						} else if (Spiel[auswerter][i][j] == 3){
							printf("BB");
						} else if (Spiel[auswerter][i][j] == 4){
							printf("CC");
						} else if (Spiel[auswerter][i][j] == 5){
							printf("DD");
						} else if (Spiel[auswerter][i][j] == 6){
							printf("EE");
						} else if (Spiel[auswerter][i][j] == 7){
							printf("GG");
						} else if (Spiel[auswerter][i][j] == 8){
							printf("HH");
						} else if (Spiel[auswerter][i][j] == 9){
							printf("II");
						} else if (Spiel[auswerter][i][j] == 11){
							if ((geben == 1)||(((information_code[2] == 2)||(information_code[2] == 1))&&(information_code[1] == 1))){
								printf("~~");
							} else {
								printf("  ");
							}
						}
					} else if (gamemode_played == Arena) {
						if (Spiel[auswerter][i][j] == geben) {
							if (information_code[0] == 1) {
								printf("UU");
							} else if (information_code[0] == 2) {
								printf("LL");
							} else if (information_code[0] == 3) {
								printf("AA");
							} else if (information_code[0] == 4) {
								printf("CC");
							} else if (information_code[0] == 5) {
								printf("II");
							} else if (information_code[0] == 6) {
								printf("SS");
							} else if (information_code[0] == 7) {
								printf("PP");
							} else if (information_code[0] == 8) {
								printf("HH");
							} else if (information_code[0] == 9) {
								printf("EE");
							}
						} else if ((information_code[1] != 0)&&(information_code[1] != 100)&&(Spiel[auswerter][i][j] == information_code[1])) {
							printf("II");
						} else if ((information_code[2] != 0)&&(information_code[2] != 100)&&(Spiel[auswerter][i][j] == information_code[2])) {
							printf("PP");
						} else if ((information_code[3] != 0)&&(information_code[3] != 100)&&(Spiel[auswerter][i][j] == information_code[3])) {
							printf("HH");
						} else if ((Spiel[auswerter][1][0] != 0)&&(Spiel[auswerter][1][0] != 1000)&&(Spiel[auswerter][i][j] == Spiel[auswerter][1][0]/10)) {
							printf("UU");
						} else if ((Spiel[auswerter][0][0] != 0)&&(Spiel[auswerter][0][0] != 1000)&&(Spiel[auswerter][i][j] == Spiel[auswerter][0][0]/10)) {
							printf("LL");
						} else if ((Spiel[auswerter][0][1] != 0)&&(Spiel[auswerter][0][1] != 1000)&&(Spiel[auswerter][i][j] == Spiel[auswerter][0][1]/10)) {
							printf("AA");
						} else if ((Spiel[auswerter][0][n-1] != 0)&&(Spiel[auswerter][0][n-1] != 1000)&&(Spiel[auswerter][i][j] == Spiel[auswerter][0][n-1]/10)) {
							printf("CC");
						} else if ((Spiel[auswerter][m-1][n-1] != 0)&&(Spiel[auswerter][m-1][n-1] != 1000)&&(Spiel[auswerter][i][j] == Spiel[auswerter][m-1][n-1]/10)) {
							printf("SS");
						} else if ((Spiel[auswerter][m-1][0] != 0)&&(Spiel[auswerter][m-1][0] != 1000)&&(Spiel[auswerter][i][j] == Spiel[auswerter][m-1][0]/10)) {
							printf("EE");
						}
					} else {
						for (unsigned int p=1; p<=number_of_players; p++) {	//information_code[0] == number_of_players, changed
							if (Spiel[auswerter][i][j] == p) {
								printf("%u%u", p, p);
								break;
							}
						}
						if (gamemode_played == Collect) {
							if (Spiel[auswerter][i][j] == To_collect) {
								printf("##");
							}
						} else if (gamemode_played == Fall) {
							if (Spiel[auswerter][i][j] == Fall_ball) {
								printf("##");
							}
						} else if (gamemode_played == Race) {
							if (Spiel[auswerter][i][j] == Wall) {
								printf("##");
							} else if (Spiel[auswerter][i][j] == Wall_at_the_end) {
								printf("((");
							}
						} else if (gamemode_played == Rain) {
							if (Spiel[auswerter][i][j] == Raindrop) {
								printf("##");
							}
						} else if (gamemode_played == Dynamic) {
							if (Spiel[auswerter][i][j] == Dynamic_ball) {
								printf("##");
							}
						} else if (gamemode_played == Survive) {
							if (Spiel[auswerter][i][j] == Traps) {	//Trap
								printf("TT");
							} else if (Spiel[auswerter][i][j] == Bomb_4) {	//Bomb
								printf("B4");
							} else if (Spiel[auswerter][i][j] == Bomb_3) {	//Bomb
								printf("B3");
							} else if (Spiel[auswerter][i][j] == Bomb_2) {	//Bomb
								printf("B2");
							} else if (Spiel[auswerter][i][j] == Bomb_1) {	//Bomb
								printf("B1");
							} else if (Spiel[auswerter][i][j] == Waves) {	//Wave
								printf("WW");
							}
						} else if (gamemode_played == Quidditch) {
							if (Spiel[auswerter][i][j] == Quaffel) {	//Quaffel
								printf("Qu");
							} else if (Spiel[auswerter][i][j] == Klatscher) {	//Klatscher
								printf("Kl");
							} else if (Spiel[auswerter][i][j] == Schnatz) {		//Schnatz
								printf("Sz");
							} else if (Spiel[auswerter][i][j] == Jaeger_1) {	//Jaeger_1
								printf("Ja");
							} else if (Spiel[auswerter][i][j] == Jaeger_2) {	//Jaeger_2
								printf("Ja");
							} else if (Spiel[auswerter][i][j] == Hueter_1) {	//Hueter_1
								printf("Hu");
							} else if (Spiel[auswerter][i][j] == Hueter_2) {	//Hueter_2
								printf("Hu");
							} else if (Spiel[auswerter][i][j] == Treiber_1) {	//Treiber_1
								printf("Tr");
							} else if (Spiel[auswerter][i][j] == Treiber_2) {	//Treiber_2
								printf("Tr");
							} else if (Spiel[auswerter][i][j] == Sucher_1) {	//Sucher_1
								printf("Su");
							} else if (Spiel[auswerter][i][j] == Sucher_2) {	//Sucher_2
								printf("Su");
							} else if ((Spiel[auswerter][i][j] == Torring_1)||(Spiel[auswerter][i][j] == Torring_2)) {	//Torringe
								printf("()");
							}
						}
					}
					set_terminal_color (cNORMAL);
					printf("|");
				}

				if (i<10){
					printf(" %u ", i);
				} else {
					printf(" %u", i);
				}

				if ((Allocation_o.characterization == 0)&&(Sf_permutations[0][1][1] == 0)) {	//only if no field is following
					printf("\n");
				}
				if (Allocation_o.characterization != 0) {	//a second field
					printf("	");	//one tab(s)
					
					if (i<10){
						printf("    %u |", i);
					} else {
						printf("   %u |", i);
					}
					
					for (unsigned int j=1; j<n-1; j+=1){
						
						if (Growth_players[0].color == 1) {
							Square_color_interpretation (Growth_players, geben, number_of_players, Spiel[auswerter][i][j]);
						}
						
						if ((Allocation_o.field[allocation_choice][i][j] < 10)&&(Allocation_o.field[allocation_choice][i][j] != 0)) {
							printf("0%u", Allocation_o.field[allocation_choice][i][j]);
						} else if ((Allocation_o.field[allocation_choice][i][j] >= 10)&&(Allocation_o.field[allocation_choice][i][j] != 0)) {	//last one can be left
							printf("%u", Allocation_o.field[allocation_choice][i][j]);
						} else {	//no allocation possible for objects
							printf("  ");
						}

						set_terminal_color (cNORMAL);
						printf("|");
					}

					if (i<10){
						printf(" %u ", i);
					} else {
						printf(" %u", i);
					}

					if (Sf_permutations[0][1][1] == 0) {	//only if no field is following
						printf("\n");
					}

				}
				if (Sf_permutations[0][1][1] != 0) {	//a third field
					printf("	");	//one tab(s)

					if (i<10){
						printf("    %u |", i);
					} else {
						printf("   %u |", i);
					}
					
					for (unsigned int j=1; j<n-1; j+=1){
						
						set_terminal_color (Sf_permutations[0][i][j]%15 +1);
					
						if ((Sf_permutations[0][i][j] < 10)&&(Sf_permutations[0][i][j] != 0)) {
							printf("0%u", Sf_permutations[0][i][j]);
						} else if ((Sf_permutations[0][i][j] >= 10)&&(Sf_permutations[0][i][j] != 0)) {	//last one can be left
							printf("%u", Sf_permutations[0][i][j]);
						} else {
							printf("  ");
						}

						set_terminal_color (cNORMAL);
						
						printf("|");

					}

					if (i<10){
						printf(" %u ", i);
					} else {
						printf(" %u", i);
					}

				//if () {	//only if no field is following
					printf("\n");
				//}

				}
			}
		}

		printf("     +");
		for (unsigned int t=1; t<=n-2; t+=1){		//Endzeile
			printf("--+");
		}
		printf("   ");	//üc bosluk

		if (Allocation_o.characterization != 0) {
			printf("	");	//one tab(s)
			printf("     +");
			for (unsigned int t=1; t<=n-2; t+=1){
				printf("--+");
			}
			printf("   ");	//üc bosluk
		}

		if (Sf_permutations[0][1][1] != 0) {
			printf("	");	//one tab(s)
			printf("     +");
			for (unsigned int t=1; t<=n-2; t+=1){
				printf("--+");
			}
		}

		printf("\n");
		printf("      ");
		for (unsigned int q=1; q<=n-2; q+=1){		//Nummerierung
			if (q<10){
				printf("%u  ", q);
			} else {
				printf("%u ", q);
			}
		}
		printf("   ");	//üc bosluk

		if (Allocation_o.characterization != 0) {
			printf("		");	//two tab(s)
			printf("    ");	//dört bosluk
			for (unsigned int q=1; q<=n-2; q+=1){		//Nummerierung
				if (q<10){
				printf("%u  ", q);
				} else {
				printf("%u ", q);
				}
			}
			printf("   ");	//üc bosluk
		}

		if (Sf_permutations[0][1][1] != 0) {
			printf("		");	//two tab(s)
			printf("    ");	//dört bosluk
			for (unsigned int q=1; q<=n-2; q+=1){		//Nummerierung
				if (q<10){
					printf("%u  ", q);
				} else {
					printf("%u ", q);
				}
			}
		}

		printf("\n");
		printf("\n");

		#ifdef VERBOSE
		printf("\n");	//test
		printf("	information_code: [0]=%u,	[1]=%u,	[2]=%u,	[3]=%u,	\n", information_code[0], information_code[1], information_code[2], information_code[3]);
		printf("\n");
		#endif
	}

}

void Plus (unsigned int* level, Spielfeld Sf_permutations, unsigned int m, unsigned int n, unsigned int geben, Spielfeld Field, unsigned int limits_at_all, unsigned int gamemode_played, unsigned int* information_code, unsigned int number_of_players, Growth_Player* Growth_players, Special_Fields Opague_o, Special_Fields Allocation_o){
	unsigned int a, b;
	unsigned int Zeile, Spalte;

	a = 0;
	b = 0;
	Zeile = 0;
	Spalte = 0;

	if ((gamemode_played == Hunt)&&(geben == 1)) {
		limits_at_all = (limits_at_all+ 2 *(number_of_players - 3));
	}

	for (unsigned int i=1; i<m-1; i+=1){
		for (unsigned int j=1; j<n-1; j+=1){
			if ((geben == 1) && (gamemode_played == Hunt)) {
				if ((Field[0][i][j] == 1)||(Field[0][i][j] == 11)){
					b += 1;
				}
			} else if (Field[0][i][j] == geben){
				b += 1;
			}

		}
	}
	if ((b >= limits_at_all)&&(gamemode_played != Contact)&&(gamemode_played != Ulcer)&&(gamemode_played != Survive)){
		printf ("	ERROR\n");		//max. #Steine auf dem Feld
		b = 0;
	} else {

		printf(" Zeile: \n Spalte: \n");
		letters_4 = get_unsigned_numeric_input_with_not_more_than_letters_4_for_splitting();
		Zeile = split_unsigned_numeric_input_with_letters_4 (letters_4, 0);
		Spalte = split_unsigned_numeric_input_with_letters_4 (letters_4, 1);

		if ((Zeile == 0)&&(Spalte == 0)){
			printf("	Sweet escape...\n");
		} else {

			if (((Zeile<1)||(Zeile>(m-2))) || ((Spalte<1)||(Spalte>n-2))){
				printf("	you made a mistake, try again: \n");

				if (Opague_o.characterization >= 1) {
					show_field (number_of_players, level, Sf_permutations, Opague_o.field, Opague_o.field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
				} else {
					show_field (number_of_players, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
				}
				Plus (level, Sf_permutations, m, n, geben, Field, limits_at_all, gamemode_played, information_code, number_of_players, Growth_players, Opague_o, Allocation_o);
			} else {

				for (unsigned int h=Zeile-1; h<=Zeile+1; h+=1){			//Lebender in der Nähe?
					for (unsigned int k=Spalte-1; k<=Spalte+1; k+=1){
						if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
							if ((gamemode_played == Hunt)&&(geben == 1)) {
								if ((Field[0][h][k] == 1)||(Field[0][h][k] == 11)){
									a+=1;
								}
							} else if (Field[0][h][k] == geben){
								a+=1;
							}
						}
					}
				}
				if (gamemode_played == Hunt) {
					if ((a == 0) || (Field[0][Zeile][Spalte] != 0)){
						printf ("	Not possible\n");
						Plus (level, Sf_permutations, m, n, geben, Field, limits_at_all, gamemode_played, information_code, number_of_players, Growth_players, Opague_o, Allocation_o);

					} else {
						if (geben == 1) {
							set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, Zeile, Spalte, 1);
						} else {
							set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, Zeile, Spalte, geben);
						}
					}
				} else if ((gamemode_played != Ulcer)&&(gamemode_played != Survive)) {
					if ((a == 0) || (Field[0][Zeile][Spalte] != 0)){
						printf ("	Not possible\n");
						Plus (level, Sf_permutations, m, n, geben, Field, limits_at_all, gamemode_played, information_code, number_of_players, Growth_players, Opague_o, Allocation_o);
					} else {
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, Zeile, Spalte, geben);
					}
				} else {
					if (a == 0){
						printf ("	Not possible\n");
						Plus (level, Sf_permutations, m, n, geben, Field, limits_at_all, gamemode_played, information_code, number_of_players, Growth_players, Opague_o, Allocation_o);
					} else {
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, Zeile, Spalte, geben);
					}
				}
			}
		}
	}
}

void Minus (unsigned int* level, Spielfeld Sf_permutations, unsigned int m, unsigned int n, unsigned int geben, Spielfeld Field, unsigned int gamemode_played, unsigned int* information_code, Growth_Player* Growth_players, Special_Fields Opague_o, Special_Fields Allocation_o, unsigned int number_of_players){
	unsigned int Zeile, Spalte;

	Zeile = 0;
	Spalte = 0;

	printf(" Zeile: \n Spalte: \n");
	letters_4 = get_unsigned_numeric_input_with_not_more_than_letters_4_for_splitting();
	Zeile = split_unsigned_numeric_input_with_letters_4 (letters_4, 0);
	Spalte = split_unsigned_numeric_input_with_letters_4 (letters_4, 1);

	if ((Zeile == 0)&&(Spalte == 0)){
		printf("	Sweet escape...\n");
	} else {

		if (((Zeile<1)||(Zeile>(m-2))) || ((Spalte<1)||(Spalte>n-2))){
			printf("	you made a mistake, try again: \n");
			if (Opague_o.characterization >= 1) {
				show_field (number_of_players, level, Sf_permutations, Opague_o.field, Opague_o.field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
			} else {
				show_field (number_of_players, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
			}
			Minus (level, Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Growth_players, Opague_o, Allocation_o, number_of_players);
		} else if (Field[0][Zeile][Spalte] != geben){
			printf("	you made a mistake, try again: \n");
			Minus (level, Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Growth_players, Opague_o, Allocation_o, number_of_players);
		} else {
			set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, Zeile, Spalte, 0);
		}
	}
}

void Move (unsigned int* level, Spielfeld Sf_permutations, unsigned int m, unsigned int n, unsigned int geben, Spielfeld Field, unsigned int gamemode_played, unsigned int* information_code, Growth_Player* Growth_players, Special_Fields Opague_o, Special_Fields Allocation_o, unsigned int number_of_players){
	unsigned int Zeile_alt, Spalte_alt, Zeile_neu, Spalte_neu;
	unsigned int a, b;
	Spielfeld temp_move;

	b = 0;

	Zeile_alt = 0;
	Spalte_alt = 0;

	Zeile_neu = 0;
	Spalte_neu = 0;

	for (unsigned int h=1; h<=(m-2); h+=1){
		for (unsigned int k=1; k<=(n-2); k+=1){
			if ((gamemode_played == Hunt)&&(geben == 1)) {
				if ((Field[0][h][k] == 1)||(Field[0][h][k] == 11)){
					if ((Field[0][h-1][k]==0)&&((h-1)>=1)){
						b+=1;
					}
					if ((Field[0][h][k-1]==0)&&((k-1)>=1)){
						b+=1;
					}
					if ((Field[0][h][k+1]==0)&&((k+1)<=(n-2))){
						b+=1;
					}
					if ((Field[0][h+1][k]==0)&&((h+1)<=(m-2))){
						b+=1;
					}
				}
			} else if (Field[0][h][k] == geben){
				if ((Field[0][h-1][k]==0)&&((h-1)>=1)){
					b+=1;
				}
				if ((Field[0][h][k-1]==0)&&((k-1)>=1)){
					b+=1;
				}
				if ((Field[0][h][k+1]==0)&&((k+1)<=(n-2))){
					b+=1;
				}
				if ((Field[0][h+1][k]==0)&&((h+1)<=(m-2))){
					b+=1;
				}
			}

			if (b >= 2) {
				break;
			}

		}

		if (b >= 2) {
			break;
		}
	}
	if (b == 1){
		b = 0;
		for (unsigned int h=1; h<=(m-2); h+=1){
			for (unsigned int k=1; k<=(n-2); k+=1){

				if (Field[0][h][k]==11) {
					if ((Field[0][h-1][k]==0)&&((h-1)>=1)){
						b = 1;
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, h-1, k, 1);
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, h, k, 0);

						break;
					} else if ((Field[0][h][k-1]==0)&&((k-1)>=1)){
						b = 1;
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, h, k-1, 1);
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, h, k, 0);

						break;
					} else if ((Field[0][h][k+1]==0)&&((k+1)<=(n-2))){
						b = 1;
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, h, k+1, 1);
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, h, k, 0);

						break;
					} else if ((Field[0][h+1][k]==0)&&((h+1)<=(m-2))){
						b = 1;
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, h+1, k, 1);
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, h, k, 0);

						break;
					}
				} else if (Field[0][h][k] == geben){
					if ((Field[0][h-1][k]==0)&&((h-1)>=1)){
						b = 1;
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, h-1, k, geben);
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, h, k, 0);

						break;
					} else if ((Field[0][h][k-1]==0)&&((k-1)>=1)){
						b = 1;
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, h, k-1, geben);
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, h, k, 0);

						break;
					} else if ((Field[0][h][k+1]==0)&&((k+1)<=(n-2))){
						b = 1;
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, h, k+1, geben);
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, h, k, 0);

						break;
					} else if ((Field[0][h+1][k]==0)&&((h+1)<=(m-2))){
						b = 1;
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, h+1, k, geben);
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, h, k, 0);

						break;
					}
				}

			}
			if (b == 1){
				break;
			}
		}

	} else if (b == 0){
		printf("	No match found, use 100 to correct your mistake \n");
	} else {

		temp_move = Spielfeld_Create (m, n, 0);

		printf(" alte Zeile: \n alte Spalte: \n");
		letters_4 = get_unsigned_numeric_input_with_not_more_than_letters_4_for_splitting();
		Zeile_alt = split_unsigned_numeric_input_with_letters_4 (letters_4, 0);
		Spalte_alt = split_unsigned_numeric_input_with_letters_4 (letters_4, 1);

		if ((Zeile_alt == 0)&&(Spalte_alt == 0)){
			printf("	Sweet escape...\n");
		} else {

			if (((Zeile_alt<1)||(Zeile_alt>(m-2))) || ((Spalte_alt<1)||(Spalte_alt>n-2))){
				printf("	you made a mistake, try again: \n");
				if (Opague_o.characterization >= 1) {
					show_field (number_of_players, level, Sf_permutations, Opague_o.field, Opague_o.field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
				} else {
					show_field (number_of_players, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
				}
				Move (level, Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Growth_players, Opague_o, Allocation_o, number_of_players);

			} else if ((gamemode_played == Hunt)&&(geben == 1)) {
				if ((Field[0][Zeile_alt][Spalte_alt] != 1)&&(Field[0][Zeile_alt][Spalte_alt] != 11)){
					printf("	you made a mistake, try again: \n");
					Move (level, Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Growth_players, Opague_o, Allocation_o, number_of_players);
				} else {

					printf(" neue Zeile: \n neue Spalte: \n");
					letters_4 = get_unsigned_numeric_input_with_not_more_than_letters_4_for_splitting();
					Zeile_neu = split_unsigned_numeric_input_with_letters_4 (letters_4, 0);
					Spalte_neu = split_unsigned_numeric_input_with_letters_4 (letters_4, 1);

					if ((Zeile_neu == 0)&&(Spalte_neu == 0)){
						printf("	Sweet escape...\n");
					} else {

						if (((Zeile_neu<1)||(Zeile_neu>(m-2))) || ((Spalte_neu<1)||(Spalte_neu>n-2))){
							printf("	you made a mistake, try again: \n");
							if (Opague_o.characterization >= 1) {
								show_field (number_of_players, level, Sf_permutations, Opague_o.field, Opague_o.field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
							} else {
								show_field (number_of_players, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);		//transform Spielfeld in Spielfeld[0], übergebe nur noch personal, done
							}
							Move (level, Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Growth_players, Opague_o, Allocation_o, number_of_players);

						} else if (Field[0][Zeile_alt][Spalte_alt] == 1) {
							set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, temp_move, 0, Zeile_alt, Spalte_alt, 1);
							a = 0;								//Ursprung in der Nähe?
							if ((temp_move[0][Zeile_neu-1][Spalte_neu]==1)||(temp_move[0][Zeile_neu][Spalte_neu-1]==1)||(temp_move[0][Zeile_neu][Spalte_neu+1]==1)||(temp_move[0][Zeile_neu+1][Spalte_neu]==1)){
								a = 1;
							}
							if (a == 0){
								printf("	you made a mistake, try again: \n");
								Move (level, Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Growth_players, Opague_o, Allocation_o, number_of_players);
							} else if (Field[0][Zeile_neu][Spalte_neu] != 0){
								printf("	you made a mistake, try again: \n");
								Move (level, Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Growth_players, Opague_o, Allocation_o, number_of_players);
							} else {
								set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, Zeile_neu, Spalte_neu, 1);
								set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, Zeile_alt, Spalte_alt, 0);
							}
						} else if (Field[0][Zeile_alt][Spalte_alt] == 11) {
							set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, temp_move, 0, Zeile_alt, Spalte_alt, 11);
							a = 0;								//Ursprung in der Nähe?
							if ((temp_move[0][Zeile_neu-1][Spalte_neu]==11)||(temp_move[0][Zeile_neu][Spalte_neu-1]==11)||(temp_move[0][Zeile_neu][Spalte_neu+1]==11)||(temp_move[0][Zeile_neu+1][Spalte_neu]==11)){
								a = 1;
							}
							if (a == 0){
								printf("	you made a mistake, try again: \n");
								Move (level, Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Growth_players, Opague_o, Allocation_o, number_of_players);
							} else if (Field[0][Zeile_neu][Spalte_neu] != 0){
								printf("	you made a mistake, try again: \n");
								Move (level, Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Growth_players, Opague_o, Allocation_o, number_of_players);
							} else {
								set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, Zeile_neu, Spalte_neu, 11);
								set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, Zeile_alt, Spalte_alt, 0);
							}
						}
					}
				}
			} else if ((gamemode_played != Hunt)||(geben != 1)){
				if (Field[0][Zeile_alt][Spalte_alt] != geben){
					printf("	you made a mistake, try again: \n");
					Move (level, Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Growth_players, Opague_o, Allocation_o, number_of_players);
				} else {

					printf(" neue Zeile: \n neue Spalte: \n");
					letters_4 = get_unsigned_numeric_input_with_not_more_than_letters_4_for_splitting();
					Zeile_neu = split_unsigned_numeric_input_with_letters_4 (letters_4, 0);
					Spalte_neu = split_unsigned_numeric_input_with_letters_4 (letters_4, 1);

					if ((Zeile_neu == 0)&&(Spalte_neu == 0)){
						printf("	Sweet escape...\n");
					} else {

						if (((Zeile_neu<1)||(Zeile_neu>(m-2))) || ((Spalte_neu<1)||(Spalte_neu>n-2))){
							printf("	you made a mistake, try again: \n");
							if (Opague_o.characterization >= 1) {
								show_field (number_of_players, level, Sf_permutations, Opague_o.field, Opague_o.field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
							} else {
								show_field (number_of_players, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
							}
							Move (level, Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Growth_players, Opague_o, Allocation_o, number_of_players);

						} else {
							set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, temp_move, 0, Zeile_alt, Spalte_alt, geben);

							a = 0;								//Ursprung in der Nähe?
							if ((temp_move[0][Zeile_neu-1][Spalte_neu]==geben)||(temp_move[0][Zeile_neu][Spalte_neu-1]==geben)||(temp_move[0][Zeile_neu][Spalte_neu+1]==geben)||(temp_move[0][Zeile_neu+1][Spalte_neu]==geben)){
								a = 1;
							}

							if (a == 0){
								printf("	you made a mistake, try again: \n");
								Move (level, Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Growth_players, Opague_o, Allocation_o, number_of_players);
							} else if (Field[0][Zeile_neu][Spalte_neu] != 0){
								printf("	you made a mistake, try again: \n");
								Move (level, Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Growth_players, Opague_o, Allocation_o, number_of_players);
							} else {
								set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, Zeile_neu, Spalte_neu, geben);
								set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, Zeile_alt, Spalte_alt, 0);
							}
						}

					}
				}
			}
		}

		Spielfeld_Destroy (temp_move, m, 0);
	}
}

void Change (unsigned int* level, Spielfeld Sf_permutations, unsigned int m, unsigned int n, unsigned int geben, Spielfeld Field, unsigned int gamemode_played, unsigned int* information_code, Growth_Player* Growth_players, Special_Fields Opague_o, unsigned int* position, Special_Fields Allocation_o, unsigned int number_of_players){
	unsigned int geben_change, a, b;
	unsigned int eigene_Zeile, fremde_Zeile, eigene_Spalte, fremde_Spalte, heart_Zeile, heart_Spalte, normal_Zeile, normal_Spalte;

	// printf("gamemode_played = %u \n", gamemode_played);	//test
	
	b = 0;
	eigene_Zeile = 0;
	fremde_Zeile = 0;
	eigene_Spalte = 0;
	fremde_Spalte = 0;
	heart_Zeile = 0;
	heart_Spalte = 0;
	normal_Zeile = 0;
	normal_Spalte = 0;

	if ((gamemode_played == Hunt)&&(geben != 1)) {
		geben_change = 1;
	} else {
		geben_change = 0;
	}

	if ((gamemode_played == Hunt)&&(geben == 1)) {
		for (unsigned int h=1; h<=(m-2); h+=1){
			for (unsigned int k=1; k<=(n-2); k+=1){
				if (Field[0][h][k] == 11){
					if (Field[0][h-1][k]==1){
						b+=1;
					}
					if (Field[0][h][k-1]==1){
						b+=1;
					}
					if (Field[0][h][k+1]==1){
						b+=1;
					}
					if (Field[0][h+1][k]==1){
						b+=1;
					}

					if (b >= 2) {
						break;
					}
				}
			}
			if (b >= 2) {
				break;
			}
		}

		if (b == 1) {
			b = 0;

			for (unsigned int h=1; h<=(m-2); h+=1){
				for (unsigned int k=1; k<=(n-2); k+=1){
					if (Field[0][h][k] == 11){
						if (Field[0][h-1][k]==1){
							b = 1;
							set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, h-1, k, 11);
							set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, h, k, 1);
							break;
						} else if (Field[0][h][k-1]==1){
							b = 1;
							set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, h, k-1, 11);
							set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, h, k, 1);
							break;
						} else if (Field[0][h][k+1]==1){
							b = 1;
							set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, h, k+1, 11);
							set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, h, k, 1);
							break;
						} else if (Field[0][h+1][k]==1){
							b = 1;
							set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, h+1, k, 11);
							set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, h, k, 1);
							break;
						}
					}
				}
				if (b == 1){
					break;
				}
			}

		} else if (b == 0){
			printf("	No match found, use 100 to correct your mistake \n");
		} else {
			for (unsigned int h=1; h<=(m-2); h+=1){
				for (unsigned int k=1; k<=(n-2); k+=1){
					if (Field[0][h][k] == 11) {
						heart_Spalte = k;
						heart_Zeile = h;

						if (heart_Spalte != 0) {
							break;
						}
					}
				}
				if (heart_Spalte != 0) {
					break;
				}
			}

			a = 0;								//eigener in der Nähe?
			if ((Field[0][heart_Zeile-1][heart_Spalte]==1)||(Field[0][heart_Zeile][heart_Spalte-1]==1)||(Field[0][heart_Zeile][heart_Spalte+1]==1)||(Field[0][heart_Zeile+1][heart_Spalte]==1)){
				a = 1;
			}

			if (a == 0){
				printf("	it isn't possible, try a move: \n");
				Move (level, Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Growth_players, Opague_o, Allocation_o, number_of_players);
			} else {

				printf(" normale Zeile: \n normale Spalte: \n");
				letters_4 = get_unsigned_numeric_input_with_not_more_than_letters_4_for_splitting();
				normal_Zeile = split_unsigned_numeric_input_with_letters_4 (letters_4, 0);
				normal_Spalte = split_unsigned_numeric_input_with_letters_4 (letters_4, 1);

				if ((normal_Zeile == 0)&&(normal_Spalte == 0)){
					printf("	Sweet escape...\n");
				} else {

					if (((normal_Zeile<1)||(normal_Zeile>(m-2))) || ((normal_Spalte<1)||(normal_Spalte>n-2))){
						printf("	you made a mistake, try again: \n");
						if (Opague_o.characterization >= 1) {
							show_field (number_of_players, level, Sf_permutations, Opague_o.field, Opague_o.field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
						} else {
							show_field (number_of_players, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
						}
						Change (level, Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Growth_players, Opague_o, position, Allocation_o, number_of_players);

					} else if ((Field[0][normal_Zeile][normal_Spalte] != 1)||((abs(normal_Spalte - heart_Spalte) + abs(normal_Zeile - heart_Zeile)) != 1)){
						printf("	you made a mistake, try again: \n");
						Change (level, Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Growth_players, Opague_o, position, Allocation_o, number_of_players);
					} else if (((Field[0][normal_Zeile+1][normal_Spalte]%10) > 1)||((Field[0][normal_Zeile-1][normal_Spalte]%10) > 1)||((Field[0][normal_Zeile][normal_Spalte+1]%10) > 1)||((Field[0][normal_Zeile][normal_Spalte-1]%10) > 1)) {
						printf("	it isn't possible, try again: \n");
						Change (level, Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Growth_players, Opague_o, position, Allocation_o, number_of_players);
					} else {
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, normal_Zeile, normal_Spalte, 11);
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, heart_Zeile, heart_Spalte, 1);
					}
				}
			}

		}
	} else if ((gamemode_played == Hunt)&&(geben != 1)) {

		for (unsigned int h=1; h<=(m-2); h+=1){
			for (unsigned int k=1; k<=(n-2); k+=1){
				if (Field[0][h][k] == geben){
					for (unsigned int u=h-1; u<=h+1; u++){
						for (unsigned int o=k-1; o<=k+1; o++){
							if ((u+o)%2 == (h+k+1)%2) {
								if (Field[0][u][o] == geben_change){
									b+=1;
								}
							}
						}
					}
					if (b >= 2) {
						break;
					}
				}
			}
			if (b >= 2) {
				break;
			}
		}
	} else if (gamemode_played == Contact) {

		for (unsigned int h=1; h<=(m-2); h+=1){
			for (unsigned int k=1; k<=(n-2); k+=1){
				if (Field[0][h][k] == geben){
					for (unsigned int u=(h-1); u<=(h+1); u+=1){
						for (unsigned int o=(k-1); o<=(k+1); o+=1){
							if ((Field[0][u][o] != 0)&&(Field[0][u][o] != geben)){
								b+=1;
							}

							if (b >= 2) {
								break;
							}
						}
						if (b >= 2) {
							break;
						}
					}
				}
				if (b >= 2) {
					break;
				}
			}
			if (b >= 2) {
				break;
			}
		}

	} else if (gamemode_played == Rain) {
		for (unsigned int h=1; h<=(m-2); h+=1){
			for (unsigned int k=1; k<=(n-2); k+=1){
				if (Field[0][h][k] == geben){
					for (unsigned int u=h-1; u<=h+1; u++){
						for (unsigned int o=k-1; o<=k+1; o++){
							if ((u+o)%2 == (h+k+1)%2) {
								if (Field[0][u][o] == Raindrop){
									b+=1;
								}
							}
						}
					}

					if (b >= 2) {
						break;
					}
				}
			}
			if (b >= 2) {
				break;
			}
		}

	} else if (gamemode_played == Collect) {
		for (unsigned int h=1; h<=(m-2); h+=1){
			for (unsigned int k=1; k<=(n-2); k+=1){
				if (Field[0][h][k] == geben){
					for (unsigned int u=h-1; u<=h+1; u++){
						for (unsigned int o=k-1; o<=k+1; o++){
							if ((u+o)%2 == (h+k+1)%2) {
								if ((Field[0][u][o] != 0)&&(Field[0][u][o] != geben)&&(Field[0][u][o] != To_collect)){
									b+=1;
								}
							}
						}
					}

					if (b >= 2) {
						break;
					}
				}
			}
			if (b >= 2) {
				break;
			}
		}
	} else if (gamemode_played == Race) {
		for (unsigned int h=1; h<=(m-2); h+=1){
			for (unsigned int k=1; k<=(n-2); k+=1){
				if (Field[0][h][k] == geben){
					for (unsigned int u=h-1; u<=h+1; u++){
						for (unsigned int o=k-1; o<=k+1; o++){
							if ((u+o)%2 == (h+k+1)%2) {
								if ((Field[0][u][o] != 0)&&(Field[0][u][o] != geben)&&(Field[0][u][o] != Wall)&&(Field[0][u][o] != Wall_at_the_end)){
									b+=1;
								}
							}
						}
					}

					if (b >= 2) {
						break;
					}
				}
			}
			if (b >= 2) {
				break;
			}
		}
	} else {	//nur Berechnung, kein Change direkt, mehr-gamemode_played
		for (unsigned int h=1; h<=(m-2); h+=1){
			for (unsigned int k=1; k<=(n-2); k+=1){
				if (Field[0][h][k] == geben){
					for (unsigned int u=h-1; u<=h+1; u++){
						for (unsigned int o=k-1; o<=k+1; o++){
							if ((u+o)%2 == (h+k+1)%2) {
								if ((Field[0][u][o] != 0)&&(Field[0][u][o] != geben)){
									b+=1;
								}
							}
						}
					}
					if (b >= 2) {
						break;
					}
				}
			}
			if (b >= 2) {
				break;
			}
		}
	}

	if (b == 1){
		b = 0;

		if ((gamemode_played == Hunt)&&(geben != 1)) {
			for (unsigned int h=1; h<=(m-2); h+=1){
				for (unsigned int k=1; k<=(n-2); k+=1){
					if (Field[0][h][k] == geben){
						for (unsigned int u=h-1; u<=h+1; u++){
							for (unsigned int o=k-1; o<=k+1; o++){
								if ((u+o)%2 == (h+k+1)%2) {
									if (Field[0][u][o] == geben_change){
										b = 1;
										set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, h, k, geben_change);
										set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, u, o, geben);
										break;
									}
								}
							}
						}
					}
				}
				if (b == 1){
					break;
				}
			}
		} else if (gamemode_played == Contact) {
			for (unsigned int h=1; h<=(m-2); h+=1){
				for (unsigned int k=1; k<=(n-2); k+=1){
					if (Field[0][h][k] == geben){
						for (unsigned int u=(h-1); u<=(h+1); u+=1){
							for (unsigned int o=(k-1); o<=(k+1); o+=1){
								if ((Field[0][u][o] != geben)&&(Field[0][u][o] != 0)&&(Field[0][u][o] <= number_of_players)){
									b = 1;
									set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, h, k, Field[0][u][o]);
									set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, u, o, geben);
									break;
								}
							}
							if (b == 1){
								break;
							}
						}
						if (b == 1){
							break;
						}
					}
				}
				if (b == 1){
					break;
				}
			}
		} else if (gamemode_played == Rain) {
			for (unsigned int h=1; h<=(m-2); h+=1){
				for (unsigned int k=1; k<=(n-2); k+=1){
					if (Field[0][h][k] == geben){
						for (unsigned int u=h-1; u<=h+1; u++){
							for (unsigned int o=k-1; o<=k+1; o++){
								if ((u+o)%2 == (h+k+1)%2) {
									if (Field[0][u][o] == Raindrop){
										b = 1;
										set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, h, k, Raindrop);
										set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, u, o, geben);
										break;
									}
								}
							}
						}
					}
				}
				if (b == 1){
					break;
				}
			}
		} else {	//mehr-gamemode_played
			for (unsigned int h=1; h<=(m-2); h+=1){
				for (unsigned int k=1; k<=(n-2); k+=1){
					if (Field[0][h][k] == geben){
						for (unsigned int u=h-1; u<=h+1; u++){
							for (unsigned int o=k-1; o<=k+1; o++){
								if ((u+o)%2 == (h+k+1)%2) {
									if ((Field[0][u][o] != 0)&&(Field[0][u][o] != geben)){
										set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, h, k, Field[0][u][o]);
										set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, u, o, geben);
										b = 1;
									}

									if (Field[0][h][k] == Dynamic_ball) {	//object instead of geben, nach dem change
										position[Vertikal] = h;
										position[Horizontal] = k;
									}
								}
							}
						}
						if (b == 1){
							break;
						}
					}
				}
				if (b == 1){
					break;
				}
			}
		}

	} else if (b == 0){
		printf("	No match found, use 100 to correct your mistake \n");
	} else {

		printf(" eigene Zeile: \n eigene Spalte: \n");
		letters_4 = get_unsigned_numeric_input_with_not_more_than_letters_4_for_splitting();
		eigene_Zeile = split_unsigned_numeric_input_with_letters_4 (letters_4, 0);
		eigene_Spalte = split_unsigned_numeric_input_with_letters_4 (letters_4, 1);

		if ((eigene_Zeile == 0)&&(eigene_Spalte == 0)){
			printf("	Sweet escape...\n");
		} else {

			if (((eigene_Zeile<1)||(eigene_Zeile>(m-2))) || ((eigene_Spalte<1)||(eigene_Spalte>n-2))){
				printf("	you made a mistake, try again: \n");
				if (Opague_o.characterization >= 1) {
					show_field (number_of_players, level, Sf_permutations, Opague_o.field, Opague_o.field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
				} else {
					show_field (number_of_players, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
				}
				Change (level, Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Growth_players, Opague_o, position, Allocation_o, number_of_players);

			} else if (Field[0][eigene_Zeile][eigene_Spalte] != geben){
				printf("	you made a mistake, try again: \n");
				Change (level, Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Growth_players, Opague_o, position, Allocation_o, number_of_players);
			} else {

				a = 0;								//Feind in der Nähe?
				if (gamemode_played == Hunt) {
					if ((Field[0][eigene_Zeile-1][eigene_Spalte]==geben_change)||(Field[0][eigene_Zeile][eigene_Spalte-1]==geben_change)||(Field[0][eigene_Zeile][eigene_Spalte+1]==geben_change)||(Field[0][eigene_Zeile+1][eigene_Spalte]==geben_change)){
						a = 1;
					}
				} else if (gamemode_played == Contact) {
					for (unsigned int h=eigene_Zeile-1; h<=eigene_Zeile+1; h+=1){
						for (unsigned int k=eigene_Spalte-1; k<=eigene_Spalte+1; k+=1){
							if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
								if ((Field[0][h][k] != geben)&&(Field[0][h][k] != 0)&&(Field[0][h][k] <= number_of_players)){
									a = 1;
								}
							}
						}
					}
				} else if (gamemode_played == Rain){
					if ((Field[0][eigene_Zeile-1][eigene_Spalte]==Raindrop)||(Field[0][eigene_Zeile][eigene_Spalte-1]==Raindrop)||(Field[0][eigene_Zeile][eigene_Spalte+1]==Raindrop)||(Field[0][eigene_Zeile+1][eigene_Spalte]==Raindrop)){
						a = 1;
					}
				} else if (gamemode_played == Race){
					if (((Field[0][eigene_Zeile-1][eigene_Spalte]!=geben)&&(Field[0][eigene_Zeile-1][eigene_Spalte]!=0&&(Field[0][eigene_Zeile-1][eigene_Spalte]!=Wall)&&(Field[0][eigene_Zeile-1][eigene_Spalte]!=Wall_at_the_end)))||((Field[0][eigene_Zeile][eigene_Spalte-1]!=geben)&&(Field[0][eigene_Zeile][eigene_Spalte-1]!=0)&&(Field[0][eigene_Zeile][eigene_Spalte-1]!=Wall)&&(Field[0][eigene_Zeile][eigene_Spalte-1]!=Wall_at_the_end))||((Field[0][eigene_Zeile][eigene_Spalte+1]!=geben)&&(Field[0][eigene_Zeile][eigene_Spalte+1]!=0)&&(Field[0][eigene_Zeile][eigene_Spalte+1]!=Wall)&&(Field[0][eigene_Zeile][eigene_Spalte+1]!=Wall_at_the_end))||((Field[0][eigene_Zeile+1][eigene_Spalte]!=geben)&&(Field[0][eigene_Zeile+1][eigene_Spalte]!=0)&&(Field[0][eigene_Zeile+1][eigene_Spalte]!=Wall)&&(Field[0][eigene_Zeile+1][eigene_Spalte]!=Wall_at_the_end))){
						a = 1;
					}
				} else {	//mehr-gamemode_played
					if (((Field[0][eigene_Zeile-1][eigene_Spalte]!=geben)&&(Field[0][eigene_Zeile-1][eigene_Spalte]!=0))||((Field[0][eigene_Zeile][eigene_Spalte-1]!=geben)&&(Field[0][eigene_Zeile][eigene_Spalte-1]!=0))||((Field[0][eigene_Zeile][eigene_Spalte+1]!=geben)&&(Field[0][eigene_Zeile][eigene_Spalte+1]!=0))||((Field[0][eigene_Zeile+1][eigene_Spalte]!=geben)&&(Field[0][eigene_Zeile+1][eigene_Spalte]!=0))){
						a = 1;
					}
				}

				if (a == 0){
					printf("	you made a mistake, try again: \n");
					Change (level, Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Growth_players, Opague_o, position, Allocation_o, number_of_players);
				} else {

					printf(" fremde Zeile: \n fremde Spalte: \n");
					letters_4 = get_unsigned_numeric_input_with_not_more_than_letters_4_for_splitting();
					fremde_Zeile = split_unsigned_numeric_input_with_letters_4 (letters_4, 0);
					fremde_Spalte = split_unsigned_numeric_input_with_letters_4 (letters_4, 1);

					if ((fremde_Zeile == 0)&&(fremde_Spalte == 0)){
						printf("	Sweet escape...\n");
					} else {

						if (((fremde_Zeile<1)||(fremde_Zeile>(m-2))) || ((fremde_Spalte<1)||(fremde_Spalte>n-2))){
							printf("	you made a mistake, try again: \n");
							if (Opague_o.characterization >= 1) {
								show_field (number_of_players, level, Sf_permutations, Opague_o.field, Opague_o.field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
							} else {
								show_field (number_of_players, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
							}
							Change (level, Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Growth_players, Opague_o, position, Allocation_o, number_of_players);

						} else if (gamemode_played == Hunt) {
							if ((Field[0][fremde_Zeile][fremde_Spalte] != geben_change)||(abs(fremde_Spalte-eigene_Spalte)+abs(fremde_Zeile-eigene_Zeile)!= 1)){
								printf("	you made a mistake, try again: \n");
								Change (level, Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Growth_players, Opague_o, position, Allocation_o, number_of_players);
							} else {
								set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, fremde_Zeile, fremde_Spalte, geben);
								set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, eigene_Zeile, eigene_Spalte, geben_change);
							}
						} else if (gamemode_played == Contact) {
							if ((Field[0][fremde_Zeile][fremde_Spalte] > number_of_players)||(Field[0][fremde_Zeile][fremde_Spalte] == 0)||(Field[0][fremde_Zeile][fremde_Spalte] == geben)||(abs(fremde_Spalte-eigene_Spalte)>1)||(abs(fremde_Zeile-eigene_Zeile)>1)){
								printf("	you made a mistake, try again: \n");
								Change (level, Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Growth_players, Opague_o, position, Allocation_o, number_of_players);
							} else {
								set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, eigene_Zeile, eigene_Spalte, Field[0][fremde_Zeile][fremde_Spalte]);
								set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, fremde_Zeile, fremde_Spalte, geben);
							}
						} else if (gamemode_played == Rain) {
							if ((Field[0][fremde_Zeile][fremde_Spalte] != Raindrop)||(abs(fremde_Spalte-eigene_Spalte)+abs(fremde_Zeile-eigene_Zeile)!= 1)){
								printf("	you made a mistake, try again: \n");
								Change (level, Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Growth_players, Opague_o, position, Allocation_o, number_of_players);
							} else {
								set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, fremde_Zeile, fremde_Spalte, geben);
								set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, eigene_Zeile, eigene_Spalte, Raindrop);
							}
						} else if (gamemode_played == Race) {
							if ((Field[0][fremde_Zeile][fremde_Spalte] > number_of_players)||(Field[0][fremde_Zeile][fremde_Spalte] == 0)||(Field[0][fremde_Zeile][fremde_Spalte] == geben)||(Field[0][fremde_Zeile][fremde_Spalte] == Wall)||(Field[0][fremde_Zeile][fremde_Spalte] == Wall_at_the_end)||(abs(fremde_Spalte-eigene_Spalte)+abs(fremde_Zeile-eigene_Zeile)!= 1)){
								printf("	you made a mistake, try again: \n");
								Change (level, Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Growth_players, Opague_o, position, Allocation_o, number_of_players);
							} else {
								set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, eigene_Zeile, eigene_Spalte, Field[0][fremde_Zeile][fremde_Spalte]);
								set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, fremde_Zeile, fremde_Spalte, geben);
							}
						} else {
							if ((Field[0][fremde_Zeile][fremde_Spalte] > number_of_players)||(Field[0][fremde_Zeile][fremde_Spalte] == 0)||(Field[0][fremde_Zeile][fremde_Spalte] == geben)||(abs(fremde_Spalte-eigene_Spalte)+abs(fremde_Zeile-eigene_Zeile)!= 1)){
								printf("	you made a mistake, try again: \n");
								Change (level, Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Growth_players, Opague_o, position, Allocation_o, number_of_players);
							} else {
								set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, eigene_Zeile, eigene_Spalte, Field[0][fremde_Zeile][fremde_Spalte]);
								set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, fremde_Zeile, fremde_Spalte, geben);
							}

							if (Field[0][eigene_Zeile][eigene_Spalte] == Dynamic_ball) {	//object instead of geben
								position[Vertikal] = eigene_Zeile;
								position[Horizontal] = eigene_Spalte;
							}
						}
					}

				}
			}
		}
	}
}

void Destroy (unsigned int* level, Spielfeld Sf_permutations, unsigned int m, unsigned int n, unsigned int geben, Spielfeld Field, unsigned int gamemode_played, unsigned int* information_code, Growth_Player* Growth_players, Special_Fields Opague_o, Special_Fields Allocation_o, unsigned int number_of_players){
	unsigned int geben_destroy, a, b;
	unsigned int fremde_Zeile, fremde_Spalte;

	fremde_Zeile = 0;
	fremde_Spalte = 0;

	if ((gamemode_played == Hunt)&&(geben != 1)) {
		geben_destroy = 1;
	} else {
		geben_destroy = 0;
	}

	if ((gamemode_played == Hunt)&&(geben == 1)) {
		printf(" fremde Zeile: \n fremde Spalte: \n");
		letters_4 = get_unsigned_numeric_input_with_not_more_than_letters_4_for_splitting();
		fremde_Zeile = split_unsigned_numeric_input_with_letters_4 (letters_4, 0);
		fremde_Spalte = split_unsigned_numeric_input_with_letters_4 (letters_4, 1);

		if ((fremde_Zeile == 0)&&(fremde_Spalte == 0)){
			printf("	Sweet escape...\n");
		} else {

			if ((Field[0][fremde_Zeile][fremde_Spalte] == 0)||(Field[0][fremde_Zeile][fremde_Spalte] == 1)||(Field[0][fremde_Zeile][fremde_Spalte] == 11)) {
				printf("	you made a mistake, try again: \n");
				Destroy (level, Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Growth_players, Opague_o, Allocation_o, number_of_players);
			} else {
				set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, fremde_Zeile, fremde_Spalte, 0);
			}
		}
	} else if ((gamemode_played != Hunt)||(geben != 1)) {

		b = 0;
		if (gamemode_played == Hunt) {
			for (unsigned int h=1; h<=(m-2); h+=1){
				for (unsigned int k=1; k<=(n-2); k+=1){
					if (Field[0][h][k] == geben){
						for (unsigned int u=(h-1); u<=(h+1); u+=1){
							for (unsigned int o=(k-1); o<=(k+1); o+=1){
								if (((u+o)%2 == (h+k+1)%2)&&(Field[0][u][o]==geben_destroy)) {
									b+=1;
								}
							}
						}
					}
				}
			}
		} else if (gamemode_played == Contact) {
			for (unsigned int h=1; h<=(m-2); h+=1){
				for (unsigned int k=1; k<=(n-2); k+=1){
					if (Field[0][h][k] == geben){
						for (unsigned int u=(h-1); u<=(h+1); u+=1){
							for (unsigned int o=(k-1); o<=(k+1); o+=1){
								if ((Field[0][u][o] != geben)&&(Field[0][u][o] != 0)){
									b+=1;
								}
							}
						}
					}
				}
			}
		} else if (gamemode_played == Collect) {
			for (unsigned int h=1; h<=(m-2); h+=1){
				for (unsigned int k=1; k<=(n-2); k+=1){
					if (Field[0][h][k] == geben){
						for (unsigned int u=(h-1); u<=(h+1); u+=1){
							for (unsigned int o=(k-1); o<=(k+1); o+=1){
								if ((Field[0][u][o] != geben)&&(Field[0][u][o] != 0)&&(Field[0][u][o] != To_collect)){
									b+=1;
								}
							}
						}
					}
				}
			}
		} else if (gamemode_played == Fall) {
			for (unsigned int h=1; h<=(m-2); h+=1){
				for (unsigned int k=1; k<=(n-2); k+=1){
					if (Field[0][h][k] == geben){
						for (unsigned int u=(h-1); u<=(h+1); u+=1){
							for (unsigned int o=(k-1); o<=(k+1); o+=1){
								if ((Field[0][u][o] != geben)&&(Field[0][u][o] != 0)&&(Field[0][u][o] != Fall_ball)){
									b+=1;
								}
							}
						}
					}
				}
			}
		} else if (gamemode_played == Race) {
			for (unsigned int h=1; h<=(m-2); h+=1){
				for (unsigned int k=1; k<=(n-2); k+=1){
					if (Field[0][h][k] == geben){
						for (unsigned int u=(h-1); u<=(h+1); u+=1){
							for (unsigned int o=(k-1); o<=(k+1); o+=1){
								if ((Field[0][u][o] != geben)&&(Field[0][u][o] != 0)&&(Field[0][u][o] != Wall)&&(Field[0][u][o] != Wall_at_the_end)){
									b+=1;
								}
							}
						}
					}
				}
			}
		} else if (gamemode_played == Rain) {
			for (unsigned int h=1; h<=(m-4); h+=1){
				for (unsigned int k=1; k<=(n-2); k+=1){
					if ((Field[0][h][k] != geben)&&(Field[0][h][k] != 0)){
						b+=1;
					}
				}
			}
		} else if (gamemode_played == Ulcer) {
			for (unsigned int h=1; h<=(m-2); h+=1){
				for (unsigned int k=1; k<=(n-2); k+=1){
					if (Field[0][h][k] == geben){
						for (unsigned int u=(h-1); u<=(h+1); u+=1){
							for (unsigned int o=(k-1); o<=(k+1); o+=1){
								if ((u+o)%2 == (h+k+1)%2) {
									if ((Field[0][u][o] != geben)&&(Field[0][u][o] != 0)&&(Field[0][u][o] != 1)){
										b+=1;
									}
								}
							}
						}
					}
				}
			}
		} else if (gamemode_played == Dynamic) {
			for (unsigned int h=1; h<=(m-2); h+=1){
				for (unsigned int k=1; k<=(n-2); k+=1){
					if (Field[0][h][k] == geben){
						for (unsigned int u=(h-1); u<=(h+1); u+=1){
							for (unsigned int o=(k-1); o<=(k+1); o+=1){
								if ((u+o)%2 == (h+k+1)%2) {
									if ((Field[0][u][o] != geben)&&(Field[0][u][o] != 0)&&(Field[0][u][o] != Dynamic_ball)){
										b+=1;
									}
								}
							}
						}
					}
				}
			}
		} else {
			for (unsigned int h=1; h<=(m-2); h+=1){
				for (unsigned int k=1; k<=(n-2); k+=1){
					if (Field[0][h][k] == geben){
						for (unsigned int u=(h-1); u<=(h+1); u+=1){
							for (unsigned int o=(k-1); o<=(k+1); o+=1){
								if ((u+o)%2 == (h+k+1)%2) {
									if ((Field[0][u][o] != geben)&&(Field[0][u][o] != 0)){
										b+=1;
									}
								}
							}
						}
					}
				}
			}
		}

		if (b == 1){
			b = 0;

			if (gamemode_played == Hunt) {
				for (unsigned int h=1; h<=(m-2); h+=1){
					for (unsigned int k=1; k<=(n-2); k+=1){
						if (Field[0][h][k] == geben){
							for (unsigned int u=(h-1); u<=(h+1); u+=1){
								for (unsigned int o=(k-1); o<=(k+1); o+=1){
									if ((u+o)%2 == (h+k+1)%2) {
										if (Field[0][u][o]==geben_destroy){
											b = 1;
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, u, o, 0);
											break;
										}
									}
								}
							}
						}
					}
					if (b == 1){
						break;
					}
				}
			} else if (gamemode_played == Contact) {
				for (unsigned int h=1; h<=(m-2); h+=1){
					for (unsigned int k=1; k<=(n-2); k+=1){
						if (Field[0][h][k] == geben){
							for (unsigned int u=(h-1); u<=(h+1); u+=1){
								for (unsigned int o=(k-1); o<=(k+1); o+=1){
									if ((Field[0][u][o] != geben)&&(Field[0][u][o] != 0)){
										b = 1;
										set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, u, o, 0);
										break;
									}
								}
								if (b == 1){
									break;
								}
							}
							if (b == 1){
								break;
							}
						}
					}
					if (b == 1){
						break;
					}
				}
			} else if (gamemode_played == Collect) {
				for (unsigned int h=1; h<=(m-2); h+=1){
					for (unsigned int k=1; k<=(n-2); k+=1){
						if (Field[0][h][k] == geben){
							for (unsigned int u=(h-1); u<=(h+1); u+=1){
								for (unsigned int o=(k-1); o<=(k+1); o+=1){
									if ((u+o)%2 == (h+k+1)%2) {
										if ((Field[0][u][o] != geben)&&(Field[0][u][o] != 0)&&(Field[0][u][o] != To_collect)){
											b = 1;
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, u, o, 0);
											break;
										}
									}
								}
							}
						}
					}
					if (b == 1){
						break;
					}
				}
			} else if (gamemode_played == Fall) {
				for (unsigned int h=1; h<=(m-2); h+=1){
					for (unsigned int k=1; k<=(n-2); k+=1){
						if (Field[0][h][k] == geben){
							for (unsigned int u=(h-1); u<=(h+1); u+=1){
								for (unsigned int o=(k-1); o<=(k+1); o+=1){
									if ((u+o)%2 == (h+k+1)%2) {
										if ((Field[0][u][o] != geben)&&(Field[0][u][o] != 0)&&(Field[0][u][o] != Fall_ball)){
											b = 1;
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, u, o, 0);
											break;
										}
									}
								}
							}
						}
					}
					if (b == 1){
						break;
					}
				}
			} else if (gamemode_played == Race) {
				for (unsigned int h=1; h<=(m-2); h+=1){
					for (unsigned int k=1; k<=(n-2); k+=1){
						if (Field[0][h][k] == geben){
							for (unsigned int u=(h-1); u<=(h+1); u+=1){
								for (unsigned int o=(k-1); o<=(k+1); o+=1){
									if ((u+o)%2 == (h+k+1)%2) {
										if ((Field[0][u][o] != geben)&&(Field[0][u][o] != 0)&&(Field[0][u][o] != Wall)&&(Field[0][u][o] != Wall_at_the_end)){
											b = 1;
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, u, o, 0);
											break;
										}
									}
								}
							}
						}
					}
					if (b == 1){
						break;
					}
				}
			} else if (gamemode_played == Rain) {
				for (unsigned int h=1; h<=(m-4); h+=1){
					for (unsigned int k=1; k<=(n-2); k+=1){
						if ((Field[0][h][k] != geben)&&(Field[0][h][k] != 0)){
							b = 1;
							set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, h, k, 0);
							break;
						}
					}
					if (b == 1){
						break;
					}
				}
			} else if (gamemode_played == Ulcer) {
				for (unsigned int h=1; h<=(m-2); h+=1){
					for (unsigned int k=1; k<=(n-2); k+=1){
						if (Field[0][h][k] == geben){
							for (unsigned int u=(h-1); u<=(h+1); u+=1){
								for (unsigned int o=(k-1); o<=(k+1); o+=1){
									if ((u+o)%2 == (h+k+1)%2) {
										if ((Field[0][u][o] != geben)&&(Field[0][u][o] != 0)&&(Field[0][u][o] != 1)){
											b = 1;
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, u, o, 0);
											break;
										}
									}
								}
							}
						}
					}
					if (b == 1){
						break;
					}
				}
			} else if (gamemode_played == Dynamic) {
				for (unsigned int h=1; h<=(m-2); h+=1){
					for (unsigned int k=1; k<=(n-2); k+=1){
						if (Field[0][h][k] == geben){
							for (unsigned int u=(h-1); u<=(h+1); u+=1){
								for (unsigned int o=(k-1); o<=(k+1); o+=1){
									if ((u+o)%2 == (h+k+1)%2) {
										if ((Field[0][u][o] != geben)&&(Field[0][u][o] != 0)&&(Field[0][u][o] != Dynamic_ball)){
											b = 1;
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, u, o, 0);
											break;
										}
									}
								}
							}
						}
					}
					if (b == 1){
						break;
					}
				}
			} else {
				for (unsigned int h=1; h<=(m-2); h+=1){
					for (unsigned int k=1; k<=(n-2); k+=1){
						if (Field[0][h][k] == geben){
							for (unsigned int u=(h-1); u<=(h+1); u+=1){
								for (unsigned int o=(k-1); o<=(k+1); o+=1){
									if ((u+o)%2 == (h+k+1)%2) {
										if ((Field[0][u][o] != geben)&&(Field[0][u][o] != 0)){
											b = 1;
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, u, o, 0);
											break;
										}
									}
								}
							}
						}
					}
					if (b == 1){
						break;
					}
				}
			}

		} else if (b == 0){
			printf("	No match found, use 100 to correct your mistake \n");
		} else {

			printf(" fremde Zeile: \n fremde Spalte: \n");
			letters_4 = get_unsigned_numeric_input_with_not_more_than_letters_4_for_splitting();
			fremde_Zeile = split_unsigned_numeric_input_with_letters_4 (letters_4, 0);
			fremde_Spalte = split_unsigned_numeric_input_with_letters_4 (letters_4, 1);

			if ((fremde_Zeile == 0)&&(fremde_Spalte == 0)){
				printf("	Sweet escape...\n");
			} else {

				a = 0;								//Eigener in der Nähe?

				if (((fremde_Zeile<1)||(fremde_Zeile>(m-2))) || ((fremde_Spalte<1)||(fremde_Spalte>n-2))){
					printf("	you made a mistake, try again: \n");
					if (Opague_o.characterization >= 1) {
						show_field (number_of_players, level, Sf_permutations, Opague_o.field, Opague_o.field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
					} else {
						show_field (number_of_players, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
					}
					Destroy (level, Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Growth_players, Opague_o, Allocation_o, number_of_players);

				} else if (gamemode_played == Contact) {
					for (unsigned int h=fremde_Zeile-1; h<=fremde_Zeile+1; h+=1){
						for (unsigned int k=fremde_Spalte-1; k<=fremde_Spalte+1; k+=1){
							if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
								if (Field[0][h][k] == geben){
									a = 1;
								}
							}
						}
					}
				} else if (gamemode_played == Rain) {
					if (fremde_Zeile <= (m-4)){
						a = 1;
					}
				} else {
					if ((Field[0][fremde_Zeile-1][fremde_Spalte]==geben)||(Field[0][fremde_Zeile][fremde_Spalte-1]==geben)||(Field[0][fremde_Zeile][fremde_Spalte+1]==geben)||(Field[0][fremde_Zeile+1][fremde_Spalte]==geben)){
						a = 1;
					}
				}

				if (a == 0){	//mehr-gamemode_played
					printf("	you made a mistake, try again: \n");
					Destroy (level, Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Growth_players, Opague_o, Allocation_o, number_of_players);
				} else if ((gamemode_played == Hunt)&&(Field[0][fremde_Zeile][fremde_Spalte] != geben_destroy)){
					printf("	you made a mistake, try again: \n");
					Destroy (level, Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Growth_players, Opague_o, Allocation_o, number_of_players);
				} else if (((gamemode_played == Classic)||(gamemode_played == Contact)||(gamemode_played == Fight)||(gamemode_played == Sand)||(gamemode_played == Survive)||(gamemode_played == Arena))&&((Field[0][fremde_Zeile][fremde_Spalte] == 0)||(Field[0][fremde_Zeile][fremde_Spalte] == geben))){
					printf("	you made a mistake, try again: \n");
					Destroy (level, Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Growth_players, Opague_o, Allocation_o, number_of_players);
				} else if ((gamemode_played == Collect)&&((Field[0][fremde_Zeile][fremde_Spalte] == 0)||(Field[0][fremde_Zeile][fremde_Spalte] == geben)||(Field[0][fremde_Zeile][fremde_Spalte] == To_collect))){
					printf("	you made a mistake, try again: \n");
					Destroy (level, Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Growth_players, Opague_o, Allocation_o, number_of_players);
				} else if ((gamemode_played == Fall)&&((Field[0][fremde_Zeile][fremde_Spalte] == 0)||(Field[0][fremde_Zeile][fremde_Spalte] == geben)||(Field[0][fremde_Zeile][fremde_Spalte] == Fall_ball))){
					printf("	you made a mistake, try again: \n");
					Destroy (level, Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Growth_players, Opague_o, Allocation_o, number_of_players);
				} else if ((gamemode_played == Race)&&((Field[0][fremde_Zeile][fremde_Spalte] == 0)||(Field[0][fremde_Zeile][fremde_Spalte] == geben)||(Field[0][fremde_Zeile][fremde_Spalte] == Wall)||(Field[0][fremde_Zeile][fremde_Spalte] == Wall_at_the_end))){
					printf("	you made a mistake, try again: \n");
					Destroy (level, Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Growth_players, Opague_o, Allocation_o, number_of_players);
				} else if ((gamemode_played == Rain)&&((Field[0][fremde_Zeile][fremde_Spalte] == 0)||(Field[0][fremde_Zeile][fremde_Spalte] == geben)||(fremde_Zeile > m-4))){
					printf("	you made a mistake, try again: \n");
					Destroy (level, Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Growth_players, Opague_o, Allocation_o, number_of_players);
				} else if ((gamemode_played == Ulcer)&&((Field[0][fremde_Zeile][fremde_Spalte] == 0)||(Field[0][fremde_Zeile][fremde_Spalte] == geben)||(Field[0][fremde_Zeile][fremde_Spalte] == 1))){
					printf("	you made a mistake, try again: \n");
					Destroy (level, Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Growth_players, Opague_o, Allocation_o, number_of_players);
				} else if ((gamemode_played == Dynamic)&&((Field[0][fremde_Zeile][fremde_Spalte] == 0)||(Field[0][fremde_Zeile][fremde_Spalte] == geben)||(Field[0][fremde_Zeile][fremde_Spalte] == Dynamic_ball))){
					printf("	you made a mistake, try again: \n");
					Destroy (level, Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Growth_players, Opague_o, Allocation_o, number_of_players);
				} else {
					Field[0][fremde_Zeile][fremde_Spalte] = 0;
					Allocation_o.field[0][fremde_Zeile][fremde_Spalte] = 0;
				}
			}
		}
	}
}

void Revive (Spielfeld Spiel, unsigned int m, unsigned int n, Spielfeld evolution_od, Spielfeld Field, unsigned int geben, Special_Fields Allocation_o, Spielfeld Opague_o_field, unsigned int number_of_players, unsigned int gamemode_played){
	unsigned int a;
	Spielfeld temp_revive;

	temp_revive = Spielfeld_Create (m, n, 0);
	a = 0;

	for (unsigned int i=1; i<m-1; i+=1){
		for (unsigned int j=1; j<n-1; j+=1){
			if (evolution_od[geben][i][j] == 101*geben){
				set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, temp_revive, 0, i, j, 101*geben);
				for (unsigned int h=i-1; h<=i+1; h+=1){
					for (unsigned int k=j-1; k<=j+1; k+=1){
						if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
							if ((Spiel[0][h][k] == geben) && (evolution_od[geben][h][k] != 101*geben)){
								a+=1;
							}
						}
					}
				}
				if (a == 0){
					set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, temp_revive, 0, i, j, 0);
				}
				a = 0;
			}
		}
	}

	for (unsigned int i=1; i<m-1; i+=1){
		for (unsigned int j=1; j<n-1; j+=1){
			if ((evolution_od[geben][i][j] == 101*geben) && (temp_revive[0][i][j] == 0)){
				set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, evolution_od, geben, i, j, 0);
			}
		}
	}

	Spielfeld_Destroy (temp_revive, m, 0);
}

void Boost (Spielfeld Spiel, unsigned int geben, Spielfeld Field, unsigned int m, unsigned int n, Spielfeld temp, unsigned int gamemode_played, Spielfeld Opague_o_field, Special_Fields Allocation_o, unsigned int number_of_players){
	unsigned int geben_Boost;
	//printf("?");
	if (gamemode_played == Hunt) {
		geben_Boost = 1;
	} else {
		geben_Boost = 0;	// geben_Boost = 0; done
	}


	if ((gamemode_played == Hunt)&&(geben != 1)) {
		for (unsigned int i=1; i<m-1; i+=1){
			for (unsigned int j=1; j<n-1; j+=1){
				if (Spiel[0][i][j] == geben_Boost) {
					if ((Spiel[0][i-1][j]==geben)||(Spiel[0][i][j-1]==geben)||(Spiel[0][i][j+1]==geben)||(Spiel[0][i+1][j]==geben)){
						set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, temp, 0, i, j, geben_Boost);
					}
				}
			}
		}
	} else if (gamemode_played == Contact) {
		for (unsigned int i=1; i<m-1; i+=1){
			for (unsigned int j=1; j<n-1; j+=1){
				if ((Spiel[0][i][j] != geben)&&(Spiel[0][i][j] != 0)) {
					for (unsigned int h=i-1; h<=i+1; h+=1){
						for (unsigned int k=j-1; k<=j+1; k+=1){
							if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
								if (Spiel[0][h][k] == geben){
									set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, temp, 0, i, j, Spiel[0][i][j]);
								}
							}
						}
					}
				}
			}
		}
	} else if (gamemode_played == Rain) {
		for (unsigned int i=1; i<m-1; i+=1){
			for (unsigned int j=1; j<n-1; j+=1){
				if (Spiel[0][i][j] == Raindrop) {
					if ((Spiel[0][i-1][j]==geben)||(Spiel[0][i][j-1]==geben)||(Spiel[0][i][j+1]==geben)||(Spiel[0][i+1][j]==geben)){
						set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, temp, 0, i, j, Raindrop);
					}
				}
			}
		}
	} else {
		for (unsigned int i=1; i<m-1; i+=1){
			for (unsigned int j=1; j<n-1; j+=1){
				if ((Spiel[0][i][j] != geben)&&(Spiel[0][i][j] != 0)) {
					if ((Spiel[0][i-1][j]==geben)||(Spiel[0][i][j-1]==geben)||(Spiel[0][i][j+1]==geben)||(Spiel[0][i+1][j]==geben)){
						set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, temp, 0, i, j, Spiel[0][i][j]);
					}
				}
			}
		}
	}

	for (unsigned int i=1; i<m-1; i+=1){
		for (unsigned int j=1; j<n-1; j+=1){
			if (temp[0][i][j] != 0){
				set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j, geben);
			}
		}
	}

}

void Having_too_much (unsigned int* KI_decision, unsigned int ent, unsigned int count_new, unsigned int m, unsigned int n, Evolution evolution, Limits limits, unsigned int zeitgewinner, Spielfeld Field, unsigned int w, unsigned int d, unsigned int e, unsigned int geben, unsigned int* position, unsigned int gamemode_played, unsigned int number_of_players, unsigned int rain, Spielfeld Opague_o_field, Special_Fields Allocation_o, unsigned int* level, unsigned int real){
	unsigned int Having_too_much_Wert, a, b, c, f, ind, ober, heart_i, heart_j, keep, daha_kisa;
	Spielfeld Having_too_much_Feld;

	// if (gamemode_played == Hunt) {	//test
		// printf (" In Having_too_much with Hunt\n");
	// }

	ind = 0;
	keep = 0;
	f = 0;
	b = 0;
	c = 0;
	a = 0;
	daha_kisa = 0;
	Having_too_much_Wert = 0;
	Having_too_much_Feld = Spielfeld_Create (m, n, 0);
	if (d == 10) {	//Arena
		d = 0;
	}

	if ((gamemode_played == Hunt)&&(geben == 1)) {	//Anpassung bezüglich Hunt
		limits.new = (limits.new + (number_of_players-3));
		limits.at_all = (limits.at_all + (2*(number_of_players-3)));
	}

	if (gamemode_played == Hunt) {
		for (unsigned int i=1; i<m-1; i+=1){
			for (unsigned int j=1; j<n-1; j+=1){
				if (Field[0][i][j] == 11) {
					heart_i = i;
					heart_j = j;
					a = 1;
					break;
				}
			}
			if (a == 1) {
				break;
			}
		}
		a = 0;

		Field[0][heart_i][heart_j] = 1;	//heart versteckt, why? Because the squares around have to die
	}

	if ((zeitgewinner >= limits.at_all)&&(gamemode_played != Contact)) {
		for (unsigned int i=1; i<m-1; i+=1){
			for (unsigned int j=1; j<n-1; j+=1){
				if (evolution.nl[geben][i][j] == geben){
					set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, evolution.nl, geben, i, j, 0);
				}
			}
		}
	} else if ((gamemode_played != Hunt)||(geben != 1)) {

		while ((ind != 1)&&(ind != 2)){
			if ((level[geben] == human)&&(real == evet)) {
				printf (" \n");
				printf (" \n");
				printf (" How do you want to play: \n");
				printf (" \n");
			}
			if (ent == limits.new){
				if ((gamemode_played == Dynamic)||(gamemode_played == Arena)||(gamemode_played == Sand)) {
					if ((level[geben] == human)&&(real == evet)) {
						printf(" #produce	defensive: 1		offensive: 2 \n");
						ind = get_unsigned_numeric_input_with_not_more_than_1_letter ();
					} else {
						ind = *KI_decision;
					}
				} else if (gamemode_played == Hunt) {
					if ((level[geben] == human)&&(real == evet)) {
						printf(" #produce	defensive: 2		offensive: 1 \n");
						ind = get_unsigned_numeric_input_with_not_more_than_1_letter ();
					} else {
						ind = *KI_decision;
					}
				} else if ((gamemode_played == Rain)||(gamemode_played == Race)||(gamemode_played == Fight)||(gamemode_played == Fall)||(gamemode_played == Collect)) {
					if ((level[geben] == human)&&(real == evet)) {
						printf(" #produce	keep bottom: 1		keep top: 2		equal: 3 \n");
						keep = get_unsigned_numeric_input_with_not_more_than_1_letter ();
					} else {
						keep = *KI_decision;
					}
					ind = 1;
				} else if ((gamemode_played == Contact)||(gamemode_played == Quidditch)) {
					if ((level[geben] == human)&&(real == evet)) {
						printf(" #produce	keep top: 1		keep bottom: 2		keep left: 3		keep right: 4		don't matter: 5 \n");
						keep = get_unsigned_numeric_input_with_not_more_than_1_letter ();
					} else {
						keep = *KI_decision;
					}
					if ((keep >= 5)||(keep == 0)) {
						ind = 1;
					} else {
						ind = 2;
					}
				} else if (gamemode_played == Classic) {
					if ((level[geben] == human)&&(real == evet)) {
						printf(" #produce	defensive: 1	offensive: 2	equal: 3 \n");
						keep = get_unsigned_numeric_input_with_not_more_than_1_letter ();	//correct misuse of keep, done
					} else {
						keep = *KI_decision;
					}
					ind = 1;
				}
			} else if ((ent == limits.at_all)&&(gamemode_played != Contact)){		//min 5/10, watch out with Hunt on 2 players (theres no need for it anymore, the 52-break is deleted)
				if ((gamemode_played == Dynamic)||(gamemode_played == Arena)||(gamemode_played == Sand)) {
					if ((level[geben] == human)&&(real == evet)) {
						printf(" #reduce	defensive: 1		offensive: 2 \n");
						ind = get_unsigned_numeric_input_with_not_more_than_1_letter ();
					} else {
						ind = *KI_decision;
					}
				} else if (gamemode_played == Hunt) {
					if ((level[geben] == human)&&(real == evet)) {
						printf(" #reduce	defensive: 2		offensive: 1 \n");
						ind = get_unsigned_numeric_input_with_not_more_than_1_letter ();
					} else {
						ind = *KI_decision;
					}
				} else if ((gamemode_played == Rain)||(gamemode_played == Race)||(gamemode_played == Fight)||(gamemode_played == Fall)||(gamemode_played == Collect)) {
					if ((level[geben] == human)&&(real == evet)) {
						printf(" #reduce	keep bottom: 1	keep top: 2	equal: 3 \n");
						keep = get_unsigned_numeric_input_with_not_more_than_1_letter ();
					} else {
						keep = *KI_decision;
					}
					ind = 1;
				} else if (gamemode_played == Classic) {
					if ((level[geben] == human)&&(real == evet)) {
						printf(" #reduce	defensive: 1	offensive: 2	equal: 3 \n");
						keep = get_unsigned_numeric_input_with_not_more_than_1_letter ();	//correct misuse of keep, done
					} else {
						keep = *KI_decision;
					}
					ind = 1;
				} else if (gamemode_played == Quidditch) {
					if ((level[geben] == human)&&(real == evet)) {
						printf(" #produce	keep top: 1		keep bottom: 2		keep left: 3		keep right: 4		don't matter: 5 \n");
						keep = get_unsigned_numeric_input_with_not_more_than_1_letter ();
					} else {
						keep = *KI_decision;
					}
					if ((keep >= 5)||(keep == 0)) {
						ind = 1;
					} else {
						ind = 2;
					}
				}

			}
			if ((level[geben] == human)&&(real == evet)) {
				printf (" \n");
			}
		}
		if (ind == 1) {
			if ((gamemode_played == Dynamic)||(gamemode_played == Fight)||(gamemode_played == Classic)) {
				ober = 80;
			} else if ((gamemode_played == Arena)||(gamemode_played == Hunt)||(gamemode_played == Contact)) {
				ober = 90;
			} else if (gamemode_played == Rain) {
				ober = 87;
			} else if (gamemode_played == Race) {
				ober = 85+(n-4);
			} else if (gamemode_played == Fight) {
				ober = 105;
			} else if (gamemode_played == Collect) {
				ober = 85;
			} else if (gamemode_played == Sand) {
				ober = 85+m;
			}

		} else if (ind == 2) {
			if ((gamemode_played == Dynamic)||(gamemode_played == Hunt)||(gamemode_played == Contact)) {
				ober = m+n;
			} else if ((gamemode_played == Arena)) {
				ober = 10;
			} else if ((gamemode_played == Sand)) {
				ober = m;
			}
		}


		while (count_new > ent){
			if (ind == 1) {

				for (unsigned int i=1; i<m-1; i+=1){
					for (unsigned int j=1; j<n-1; j+=1){
						if (evolution.nl[geben][i][j] == geben){

							for (unsigned int h=i-1; h<=i+1; h+=1){		//Stirbt Zelle?
								for (unsigned int k=j-1; k<=j+1; k+=1){
									if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
										if ((evolution.nl[geben][h][k] == geben) || ((Field[0][h][k] == geben) && (evolution.od[geben][h][k] == 0))){
											a+=1;
										}
									}
								}
							}
							if (a > e+1){
								Having_too_much_Wert += 3;
							}
							a = 0;

							Having_too_much_Wert += 8;
							for (unsigned int h=i-1; h<=i+1; h+=1){		//Regeneriert neue Zellen?
								for (unsigned int k=j-1; k<=j+1; k+=1){
									if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
										if (((Field[0][h][k] == 0) || ((Field[0][h][k] == geben)&&(evolution.od[geben][h][k] == 101*geben))) && (evolution.nl[geben][h][k] == 0)){
											for (unsigned int u=h-1; u<=h+1; u+=1){
												for (unsigned int o=k-1; o<=k+1; o+=1){
													if ((u>0)&&(u<(m-1))&&(o>0)&&(o<(n-1))){
														if ((evolution.nl[geben][u][o] == geben) || ((Field[0][u][o] == geben) && (evolution.od[geben][u][o] == 0))){
															a += 1;
														}
													}
												}
											}
											if (a == w){
												Having_too_much_Wert -= 1;
											}
											a = 0;
										}
									}
								}
							}
							if ((gamemode_played == Arena)||(gamemode_played == Hunt)||(gamemode_played == Rain)||(gamemode_played == Race)||(gamemode_played == Fight)||(gamemode_played == Collect)||(gamemode_played == Sand)||(gamemode_played == Contact)||(gamemode_played == Classic)||(gamemode_played == Quidditch)) {
								for (unsigned int h=i-1; h<=i+1; h+=1){		//Stört feindliche Wachstumsmöglichkeiten?
									for (unsigned int k=j-1; k<=j+1; k+=1){
										if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
											if ((Field[0][h][k] != geben)&&(Field[0][h][k] != 0)&&(Field[0][h][k] <= number_of_players)){
												a+=1;
											}
										}
									}
								}
								if (a != 3){
									Having_too_much_Wert += 10;
									if (gamemode_played == Fight) {
										Having_too_much_Wert += 10;	//erneut +10
									}
								}
								a = 0;

							}

							for (unsigned int h=i-1; h<=i+1; h+=1){		//Regeneriert ihr Tod neue Zellen?
								for (unsigned int k=j-1; k<=j+1; k+=1){
									if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
										if (((Field[0][h][k] == 0) || ((Field[0][h][k] == geben)&&(evolution.od[geben][h][k] == 101*geben))) && (evolution.nl[geben][h][k] == 0)){
											for (unsigned int u=h-1; u<=h+1; u+=1){
												for (unsigned int o=k-1; o<=k+1; o+=1){
													if ((u>0)&&(u<(m-1))&&(o>0)&&(o<(n-1))){
														if ((evolution.nl[geben][u][o] == geben) || ((Field[0][u][o] == geben) && (evolution.od[geben][u][o] == 0))){
															a += 1;
														}
													}
												}
											}
											if (a == w+1){
												Having_too_much_Wert += 1;
											}
											a = 0;

										}
									}
								}
							}

							for (unsigned int h=i-1; h<=i+1; h+=1){		//sterben eigene Zellen?
								for (unsigned int k=j-1; k<=j+1; k+=1){
									if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
										if (((Field[0][h][k] == geben) && (evolution.od[geben][h][k] == 0)) ||(evolution.nl[geben][h][k] == geben)){
											for (unsigned int u=h-1; u<=h+1; u+=1){
												for (unsigned int o=k-1; o<=k+1; o+=1){
													if ((u>0)&&(u<(m-1))&&(o>0)&&(o<(n-1))){
														if ((evolution.nl[geben][u][o] == geben) || ((Field[0][u][o] == geben) && (evolution.od[geben][u][o] == 0))){
															a += 1;
														}
													}
												}
											}
											if (a > e+1){
												Having_too_much_Wert += 3;
											}
											a = 0;
										}
									}
								}
							}

							for (unsigned int h=i-1; h<=i+1; h+=1){		//tötet ihr Tod eigene Zellen?
								for (unsigned int k=j-1; k<=j+1; k+=1){
									if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
										if (((Field[0][h][k] == geben) && (evolution.od[geben][h][k] == 0))||(evolution.nl[geben][h][k] == geben)){
											for (unsigned int u=h-1; u<=h+1; u+=1){
												for (unsigned int o=k-1; o<=k+1; o+=1){
													if ((u>0)&&(u<(m-1))&&(o>0)&&(o<(n-1))){
														if ((evolution.nl[geben][u][o] == geben) || ((Field[0][u][o] == geben) && (evolution.od[geben][u][o] == 0))){
															a += 1;
														}
													}
												}
											}
											if (Allocation_o.characterization != 0) {
												if (a < d+1){
													b = 1;
												}
											} else {
												if (a == d){
													b = 1;
												}
											}
											a = 0;
										}
									}
								}
							}
							if (b != 1){
								Having_too_much_Wert += 10;
							}
							b = 0;

							if ((gamemode_played == Rain)||(gamemode_played == Race)||(gamemode_played == Fight)||(gamemode_played == Fall)||(gamemode_played == Collect)) {
								if (keep == 1) {
									Having_too_much_Wert += (6-i);	//stack_overflow? not causing troubles
								} else if (keep == 2) {
									Having_too_much_Wert += i;
								}
							}

							if (gamemode_played == Dynamic) {		//gamemode depending specials
								if ((i == position[Vertikal])||(j == position[Horizontal])) {
									Having_too_much_Wert = 1;
								}
							} else if (gamemode_played == Hunt) {
								if ((i+1 != heart_i)&&(i-1 != heart_i)&&(j-1 != heart_j)&&(j+1 != heart_j)){
									Having_too_much_Wert += 10;
								}
							} else if (gamemode_played == Rain) {

								if (j > ((n-1)/2)){
									Having_too_much_Wert += (j-(n-1)/2);
								} else if (j < ((n-1)/2)){
									Having_too_much_Wert += (((n-1)/2)-j);
								}

								Having_too_much_Wert += i;

								if ((i <= 2)&&((j >= ((n-3)/2))&&(j <= ((n+1)/2)))){
									Having_too_much_Wert = 1;
								}

								if ((rain == 31)||(rain == 32)||(rain == 2)){
									if (Field[0][i-1][j] == Raindrop){
										Having_too_much_Wert = 80;
									}
								}

							} else if (gamemode_played == Race) {
								Having_too_much_Wert += (n-2-j);

								if (j>=n-3){
									Having_too_much_Wert = 1;
								}

							} else if (gamemode_played == Fight) {
								if ((Field[0][i+1][j] <= number_of_players)&&(Field[0][i][j+1] <= number_of_players)&&(Field[0][i][j-1] <= number_of_players)&&(Field[0][i-1][j] <= number_of_players)&&(Field[0][i+1][j] != geben)&&(Field[0][i][j+1] != geben)&&(Field[0][i][j-1] != geben)&&(Field[0][i-1][j] != geben)) {
									Having_too_much_Wert += 10;
								}
							} else if (gamemode_played == Fall) {
								if (geben%2 == 0) {
									if ((Field[0][i-1][j]==Fall_ball)||(Field[0][i][j+1]==Fall_ball)||(Field[0][i+1][j]==Fall_ball)){
										Having_too_much_Wert = 1;		//fehlerhaft! (Vielleicht die Seiten vertauscht)
									}
								} else if (geben%2 == 1) {
									if ((Field[0][i-1][j]==Fall_ball)||(Field[0][i][j-1]==Fall_ball)||(Field[0][i+1][j]==Fall_ball)){
										Having_too_much_Wert = 1;
									}
								}

							} else if (gamemode_played == Collect) {
								if ((i >= (m-3)/2)&&(i <= (m+1)/2)){
									Having_too_much_Wert = 2;
								}

								if ((Field[0][i-1][j]==To_collect)||(Field[0][i+1][j]==To_collect)||(Field[0][i][j-1]==To_collect)||(Field[0][i][j+1]==To_collect)){
									Having_too_much_Wert = 1;
								}

							} else if (gamemode_played == Classic) {
								if (geben%2 == 0) {
									if (i == 1){
										Having_too_much_Wert = 1;
									} else if (i == 2) {
										Having_too_much_Wert = 2;
									}
								} else if (geben%2 == 1) {
									if (i == (m-2)){
										Having_too_much_Wert = 1;
									} else if (i == (m-3)) {
										Having_too_much_Wert = 2;
									}
								}
							} else if (gamemode_played == Sand) {
								Having_too_much_Wert += i;
							}

							set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Having_too_much_Feld, 0, i, j, Having_too_much_Wert);
							Having_too_much_Wert = 0;
						}
					}
				}
			} else if (ind == 2) {
				a = 0;

				for (unsigned int i=1; i<m-1; i+=1){
					for (unsigned int j=1; j<n-1; j+=1){
						if (evolution.nl[geben][i][j] == geben){

							if (gamemode_played == Dynamic) {
								set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Having_too_much_Feld, 0, i, j, abs(i-position[Vertikal])+abs(j-position[Horizontal]));
							} else if (gamemode_played == Arena) {
								for (unsigned int h=i-1; h<=i+1; h+=1){
									for (unsigned int k=j-1; k<=j+1; k+=1){
										if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
											if ((Field[0][h][k] != geben)&&(Field[0][h][k] != 0)) {
												Having_too_much_Wert += 1;
											} else if (Field[0][h][k] == geben) {
												a += 1;
											}
										}
									}
								}

								if ((a > d)&&(a <= e+1)) {
									Having_too_much_Wert += 1;
								}
								a = 0;
								set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Having_too_much_Feld, 0, i, j, 10 - Having_too_much_Wert);
								Having_too_much_Wert = 0;

							} else if (gamemode_played == Hunt) {
								if (j >= heart_j) {
									if (i >= heart_i) {
										Having_too_much_Wert = (i-heart_i-heart_j+j);
									} else if (i < heart_i) {
										Having_too_much_Wert = (heart_i-i-heart_j+j);
									}
								} else if (j < heart_j) {
									if (i >= heart_i) {
										Having_too_much_Wert = (i+heart_j-heart_i-j);
									} else if (i < heart_i) {
										Having_too_much_Wert = (heart_i+heart_j-i-j);
									}
								}

								set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Having_too_much_Feld, 0, i, j, Having_too_much_Wert);
								Having_too_much_Wert = 0;

							} else if ((gamemode_played == Contact)||(gamemode_played == Quidditch)) {

								if (keep == 1) {
									Having_too_much_Wert = i;
								} else if (keep == 2) {
									Having_too_much_Wert = (m-1)-i;
								} else if (keep == 3) {
									Having_too_much_Wert = j;
								} else if (keep == 4) {
									Having_too_much_Wert = (n-1)-j;
								}

								for (unsigned int h=i-1; h<=i+1; h+=1){
									for (unsigned int k=j-1; k<=j+1; k+=1){
										if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
											if ((Field[0][h][k] != 0)&&(Field[0][h][k] != geben)){
												Having_too_much_Wert = 1;
											}
										}
									}
								}

								set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Having_too_much_Feld, 0, i, j, Having_too_much_Wert);
								Having_too_much_Wert = 0;

							} else if (gamemode_played == Sand) {
								set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Having_too_much_Feld, 0, i, j, i);
							}
						}
					}
				}
			}

			// if (gamemode_played == Hunt) {
				// set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, heart_i, heart_j, 11);	//verstecken von heart undone, why?
			// }

			c = 0;
			daha_kisa = count_new;

			while (daha_kisa == count_new) {
				for (unsigned int i=1; i<m-1; i+=1){
					if (c == 1){
						break;
					}
					for (unsigned int j=1; j<n-1; j+=1){
						if (Having_too_much_Feld[0][i][j] == ober){
							set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Having_too_much_Feld, 0, i, j, 0);
							set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, evolution.nl, geben, i, j, 0);
							count_new -= 1;
							if (ind  == 2) {
								if ((gamemode_played == Dynamic)||(gamemode_played == Contact)||(gamemode_played == Quidditch)||((gamemode_played == Hunt)&&(geben == 1))) {
									ober = m+n;
								} else if (gamemode_played == Arena) {
									ober = 10;
								} else if (gamemode_played == Sand) {
									ober = m;
								}
							} else if (ind == 1) {

								if ((gamemode_played == Dynamic)||(gamemode_played == Fall)||(gamemode_played == Classic)) {
									ober = 80;
								} else if ((gamemode_played == Arena)||((gamemode_played == Hunt)&&(geben == 1))) {
									ober = 90;
								} else if (gamemode_played == Rain) {
									ober = 87;
								} else if (gamemode_played == Race) {
									ober = 85+(n-4);
								} else if (gamemode_played == Fight) {
									ober = 105;
								} else if (gamemode_played == Collect) {
									ober = 85;
								} else if (gamemode_played == Sand) {
									ober = 85+m;
								}
							}

							c = 1;
							break;
						}
					}
				}

				if (c == 0){
					ober -= 1;
				}
			}

			c = 0;

			//printf("ent: %u \n", ent); printf("\n");
			//printf("ind: %u \n", ind); printf("\n");
			//printf("count_new: %u \n", count_new); printf("\n");

			for (unsigned int t=1; t<m-1; t+=1){
				if (f == 1){
					break;
				}
				for (unsigned int z=1; z<n-1; z+=1){
					if (evolution.nl[geben][t][z] == geben){
						f = 1;
						break;
					}
				}
			}
			if (f == 0){
				break;
			}
			f = 0;
		}
	} else if ((gamemode_played == Hunt)&&(geben != 1)) {

		ober = m+n;
		while (count_new > ent){
			for (unsigned int i=1; i<m-1; i+=1){
				for (unsigned int j=1; j<n-1; j+=1){
					if (evolution.nl[geben][i][j] == geben){
						if (j >= heart_j) {
							if (i >= heart_i) {
								Having_too_much_Wert = (i-heart_i-heart_j+j);
							} else if (i < heart_i) {
								Having_too_much_Wert = (heart_i-i-heart_j+j);
							}
						} else if (j < heart_j) {
							if (i >= heart_i) {
								Having_too_much_Wert = (i+heart_j-heart_i-j);
							} else if (i < heart_i) {
								Having_too_much_Wert = (heart_i+heart_j-i-j);
							}
						}

						set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Having_too_much_Feld, 0, i, j, Having_too_much_Wert);
						Having_too_much_Wert = 0;
					}
				}
			}

			c = 0;
			daha_kisa = count_new;

			while (daha_kisa == count_new) {
				for (unsigned int i=1; i<m-1; i+=1){
					if (c == 1){
						break;
					}
					for (unsigned int j=1; j<n-1; j+=1){
						if (Having_too_much_Feld[0][i][j] == ober){
							set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Having_too_much_Feld, 0, i, j, 0);
							set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, evolution.nl, geben, i, j, 0);
							count_new -= 1;
							ober = m+n;
							c = 1;
							break;
						}
					}
				}
				if (c == 0){
					ober -= 1;
				}
			}

			c = 0;
			for (unsigned int t=1; t<m-1; t+=1){
				if (f == 1){
					break;
				}
				for (unsigned int z=1; z<n-1; z+=1){
					if (evolution.nl[geben][t][z] >= 1){
						f = 1;
						break;
					}
				}
			}
			if (f == 0){
				break;
			}
			f = 0;
		}

	}

	Spielfeld_Destroy (Having_too_much_Feld, m, 0);
}

void battle (unsigned int m, unsigned int n, Spielfeld Field, unsigned int geben, Spielfeld Opague_o_field, Special_Fields Allocation_o, unsigned int number_of_players, unsigned int gamemode_played){
	Spielfeld chain, chain_temp;
	unsigned int chain_total[number_of_players+1], a;

	#ifdef Contact_mistake_search
	printf("battle ok.1Con \n"); //test
	#endif

	// printf("battle ok.1 \n"); //test
	
	a = 0;
	unsigned_int_array_null_initialisierung(chain_total, number_of_players);
	chain = Spielfeld_Create (m, n, number_of_players);

	for (unsigned int i=1; i<m-1; i+=1){
		for (unsigned int j=1; j<n-1; j+=1){
			if (Field[0][i][j] == geben){

				// printf("battle ok.2 \n"); //test

				for (unsigned int u=i-1; u<=i+1; u++){
					for (unsigned int o=j-1; o<=j+1; o++){
						if ((u+o)%2 == (i+j+1)%2) {
							if ((Field[0][u][o] != geben)&&(Field[0][u][o] <= number_of_players)&&(Field[0][u][o] != 0)) {

								// printf("battle ok.2.1 \n"); //test

								chain_temp = Spielfeld_Create (m, n, 0);

								// printf("battle ok.2.0.5 \n"); //test

								set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, chain_temp, 0, i, j, geben);

								// printf("battle ok.2.1.1 \n"); //test

								chain_total[geben] = 1;

								// printf("battle ok.2.1.2 \n"); //test

								chain_count (i, j, Field, chain_temp, geben, chain_total, geben, Opague_o_field, Allocation_o, number_of_players, gamemode_played);

								// printf("battle ok.2.1.3 \n"); //test

								set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, chain_temp, 0, u, o, Field[0][u][o]);

								// printf("battle ok.2.1.4 \n"); //test

								chain_total[Field[0][u][o]] = 1;

								// printf("battle ok.2.1.5 \n"); //test

								chain_count (u, o, Field, chain_temp, Field[0][u][o], chain_total, geben, Opague_o_field, Allocation_o, number_of_players, gamemode_played);

								// printf("battle ok.2.2 \n"); //test

								if (chain_total[geben] > chain_total[Field[0][u][o]]){
									for (unsigned int h=1; h<m-1; h+=1){
										for (unsigned int k=1; k<n-1; k+=1){
											if ((chain_temp[0][h][k] == Field[0][u][o])&&(chain[geben][h][k] < chain_total[geben])){
												set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, chain, geben, h, k, chain_total[geben]);
											}
										}
									}
								} else if (chain_total[Field[0][u][o]] > chain_total[geben]){
									for (unsigned int h=1; h<m-1; h+=1){
										for (unsigned int k=1; k<n-1; k+=1){
											if ((chain_temp[0][h][k] == geben)&&(chain[Field[0][u][o]][h][k] < chain_total[Field[0][u][o]])){
												set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, chain, Field[0][u][o], h, k, chain_total[Field[0][u][o]]);
											}
										}
									}
								} else if ((chain_total[geben] == chain_total[Field[0][u][o]])&&(chain_total[geben] == 1)&&(chain[geben][u][o] < chain_total[geben])){
									set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, chain, geben, u, o, chain_total[geben]);
								}

								Spielfeld_Destroy (chain_temp, m, 0);

								// printf("battle ok.2.3 \n"); //test

							}
						}
					}
				}
			}
		}
	}

	// printf("battle ok.3 \n"); //test

	for (unsigned int i=1; i<m-1; i+=1){
		for (unsigned int j=1; j<n-1; j+=1){
			if (Field[0][i][j] != 0) {
				for (unsigned int p=1; p<=number_of_players; p++) {
					a = 0;
					for (unsigned int q=1; q<=number_of_players; q++) {
						if ((p!=q)&&(chain[p][i][j] > chain[q][i][j])){
							a += 1;

							// printf("battle ok.3.1 \n"); //test
						}
					}

					if (a > 1) {	//this square will change
						set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, i, j, 0);

						// printf("battle ok.3.2 \n"); //test
					}

					if (a == number_of_players-1) {	//highest values
						set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, i, j, p);

						// printf("battle ok.3.3 \n"); //test
					}
					a = 0;
				}
			}
		}
	}

	#ifdef Contact_mistake_search
	printf("battle ok.2Con \n"); //test
	#endif

	Spielfeld_Destroy (chain, m, number_of_players);
	
	// printf("battle ok.4 \n"); //test
	
}	//possible to modify for >2 player, done

void chain_count (unsigned int i, unsigned int j, Spielfeld Field, Spielfeld chain_temp, unsigned int player, unsigned int* chain_total, unsigned int geben, Spielfeld Opague_o_field, Special_Fields Allocation_o, unsigned int number_of_players, unsigned int gamemode_played){	//player=geben

	for (unsigned int u=i-1; u<=i+1; u++){
		for (unsigned int o=j-1; o<=j+1; o++){
			if ((u+o)%2 == (i+j+1)%2) {
				if ((Field[0][u][o] == player)&&(chain_temp[0][u][o] != player)){
					set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, chain_temp, 0, u, o, player);
					chain_total[player] += 1;
					chain_count (u, o, Field, chain_temp, player, chain_total, geben, Opague_o_field, Allocation_o, number_of_players, gamemode_played);
				}
			}
		}
	}
}

unsigned int random_number (Num_num num, unsigned int rmv_use_number, unsigned int g, unsigned int* rmv_var_, unsigned int* number_){
	unsigned int temp_number, new_number, c, mult, inkre, modu, zusatz;

	mult = 7;
	inkre = 5;
	modu = 6;
	zusatz = ((g + rmv_var_[1] + rmv_var_[2] + number_[3] + number_[4] )%60)%6;

	temp_number = (num.bir % 2)+(num.iki % 3)+2*(num.uec % 3);

	if (temp_number <= 1){
		c = 1;
	} else if (temp_number >= 6){
		c = 6;
	} else {
		c = temp_number;
	}

	new_number = (mult*rmv_use_number + inkre + c + zusatz + Zufall(1, 6))%modu;

	if (new_number == 0){
		new_number = 6;
	}

	return new_number;
}

unsigned int Zufall (unsigned int start, unsigned int amount) {
	unsigned int number;
	number = 0;
	
	number = (rand()%amount)+start;
	
	return number;
}

void touch (Spielfeld Field, unsigned int m, unsigned int n, unsigned int geben, Spielfeld evolution_nl, Special_Fields Allocation_o, Spielfeld Opague_o_field, unsigned int number_of_players, unsigned int gamemode_played){
	unsigned int value_found;
	value_found = hayir;

	for (unsigned int i=1; i<m-1; i+=1){
		for (unsigned int j=1; j<n-1; j+=1){
			if (Field[0][i][j] == Fall_ball){
				//test printf("	#-Block alt:	i=%u ,	j=%u \n ", i, j);
				for (unsigned int p=1; p<=number_of_players; p++) {
					if (geben%2 == 1){
						if (((evolution_nl[geben][i][j-1] == geben) || (Field[0][i][j-1] == geben))&&(j != (n-2))){
							set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, i, j+1, Fall_ball);
							set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, i, j, 0);
						} else if (((evolution_nl[geben][i+1][j] == geben) || (Field[0][i+1][j] == geben))&&(i != 1)){
							set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, i-1, j, Fall_ball);
							set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, i, j, 0);
						} else if (((evolution_nl[geben][i-1][j] == geben) || (Field[0][i-1][j] == geben))&&(i != (m-2))){
							set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, i+1, j, Fall_ball);
							set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, i, j, 0);
						} else if (((evolution_nl[geben][i][j+1] == geben) || (Field[0][i][j+1] == geben))&&(j != 1)){
							set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, i, j-1, Fall_ball);
							set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, i, j, 0);
						}
					} else if (geben%2 == 0){
						if (((evolution_nl[geben][i][j+1] == geben) || (Field[0][i][j+1] == geben))&&(j != 1)){
							set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, i, j-1, Fall_ball);
							set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, i, j, 0);
						} else if (((evolution_nl[geben][i+1][j] == geben) || (Field[0][i+1][j] == geben))&&(i != 1)){
							set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, i-1, j, Fall_ball);
							set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, i, j, 0);
						} else if (((evolution_nl[geben][i-1][j] == geben) || (Field[0][i-1][j] == geben))&&(i != (m-2))){
							set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, i+1, j, Fall_ball);
							set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, i, j, 0);
						} else if (((evolution_nl[geben][i][j-1] == geben) || (Field[0][i][j-1] == geben))&&(j != (n-2))){
							set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, i, j+1, Fall_ball);
							set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, i, j, 0);
						}
					}
					value_found = evet;
					// printf("	#-Block neu:	i=%u ,	j=%u \n ", i, j);	//test 
					break;
				}
			}
		}
		if (value_found == evet){
			break;
		}
	}
}

void ahead (Spielfeld Field, unsigned int m, unsigned int count_freq, Special_Fields Allocation_o, Spielfeld Opague_o_field, unsigned int number_of_players, unsigned int geben, unsigned int gamemode_played){
	
	// printf("	ahead ok.1"); //test 
	
	for (unsigned int i=1; i<m-1; i+=1){
		for (unsigned int j=1; j<count_freq; j+=1){
			if (Field[0][i][j] == Wall){
				set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, i, j, 0);
				set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, i, j+1, Wall);
			}
		}
	}
}


void choose_heart (Spielfeld Field, unsigned int m, unsigned int n, unsigned int geben, Spielfeld Opague_o_field, Special_Fields Allocation_o, unsigned int number_of_players, unsigned int gamemode_played){
	unsigned int heart_i_wanted, heart_j_wanted, a, heart_i, heart_j;
	Spielfeld ground_temp;

	ground_temp = Spielfeld_Create (m, n, 0);
	heart_i_wanted = 0;
	heart_j_wanted = 0;
	a = 0;

	for (unsigned int i=1; i<m-1; i+=1){
		for (unsigned int j=1; j<n-1; j+=1){
			if (Field[0][i][j] == 11){
				heart_i = i;
				heart_j = j;
				a = 1;
				break;
			}
		}
		if (a == 1) {
			break;
		}
	}
	a = 0;

	heart_ground (heart_i, heart_j, Field, ground_temp, geben, Opague_o_field, Allocation_o, number_of_players, gamemode_played);
	while ((heart_i_wanted == 0)||(heart_i_wanted >= m-1)||(heart_j_wanted >= n-1)||(heart_i_wanted == 0)) {
		printf(" Choose the next position of your heart-block: \n");
		printf("	\n");
		printf(" Zeile: \n Spalte: \n");

		letters_4 = get_unsigned_numeric_input_with_not_more_than_letters_4_for_splitting();
		heart_i_wanted = split_unsigned_numeric_input_with_letters_4 (letters_4, 0);
		heart_j_wanted = split_unsigned_numeric_input_with_letters_4 (letters_4, 1);

	}


	if (Field[0][heart_i_wanted][heart_j_wanted] == 11) {
		set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, heart_i_wanted, heart_j_wanted, 11);
	} else if (ground_temp[0][heart_i_wanted][heart_j_wanted] != 111) {
		printf("	You made a mistake, try again: \n");
		printf("\n");
		choose_heart (Field, m, n, geben, Opague_o_field, Allocation_o, number_of_players, gamemode_played);
	} else if (ground_temp[0][heart_i_wanted][heart_j_wanted] == 111) {
		set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, heart_i, heart_j, 1);
		set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, heart_i_wanted, heart_j_wanted, 11);
	}

	Spielfeld_Destroy (ground_temp, m, 0);
}

void heart_ground (unsigned int i, unsigned int j, Spielfeld Field, Spielfeld ground_temp, unsigned int geben, Spielfeld Opague_o_field, Special_Fields Allocation_o, unsigned int number_of_players, unsigned int gamemode_played){
	if ((Field[0][i][j+1] == 1)&&(ground_temp[0][i][j+1] != 111)){
		set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, ground_temp, 0, i, j+1, 111);
		heart_ground (i, (j+1), Field, ground_temp, geben, Opague_o_field, Allocation_o, number_of_players, gamemode_played);
	}
	if ((Field[0][i][j-1] == 1)&&(ground_temp[0][i][j-1] != 111)){
		set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, ground_temp, 0, i, j-1, 111);
		heart_ground (i, (j-1), Field, ground_temp, geben, Opague_o_field, Allocation_o, number_of_players, gamemode_played);
	}
	if ((Field[0][i+1][j] == 1)&&(ground_temp[0][i+1][j] != 111)){
		set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, ground_temp, 0, i+1, j, 111);
		heart_ground ((i+1), j, Field, ground_temp, geben, Opague_o_field, Allocation_o, number_of_players, gamemode_played);
	}
	if ((Field[0][i-1][j] == 1)&&(ground_temp[0][i-1][j] != 111)){
		set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, ground_temp, 0, i-1, j, 111);
		heart_ground ((i-1), j, Field, ground_temp, geben, Opague_o_field, Allocation_o, number_of_players, gamemode_played);
	}
}

void opague_builder (Spielfeld Field, Special_Fields Opague_o, unsigned int m, unsigned int n, unsigned int geben, unsigned int AOP, Special_Fields Allocation_o, unsigned int number_of_players, unsigned int gamemode_played) {
	unsigned int extra;
	unsigned int* opague_counter;
	Spielfeld temp_opague;

	//printf("Opague_o.characterization: %u \n", Opague_o.characterization);		//test

	extra = 13;	//alle zusätzlichen Werte neben den AOP-Spielerwerten
	opague_counter = unsigned_int_Vektor_Create(1+AOP+extra);
	temp_opague = Spielfeld_Create (m, n, 0);

	for (unsigned int p=0; p<=AOP+extra; p+=1) {
		opague_counter[p] = 0;
	}

	for (unsigned int i=1; i<m-1; i+=1){
		for (unsigned int j=1; j<n-1; j+=1){

			if (Opague_o.characterization >= 20) {		//4-Mode-Opague, near-by

				if (Field[0][i][j] != 11) {
					if (Field[0][i][j] == geben) {
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, temp_opague, 0, i, j, geben);
					} else if ((Field[0][i][j] != 0)) {
						if (Field[0][i][j] == To_collect) {
							opague_counter[AOP+1] += 1;
						} else if (Field[0][i][j] == Fall_ball) {
							opague_counter[AOP+2] += 1;
						} else if (Field[0][i][j] == Wall) {
							opague_counter[AOP+3] += 1;
						} else if (Field[0][i][j] == Wall_at_the_end) {
							opague_counter[AOP+4] += 1;
						} else if (Field[0][i][j] == Raindrop) {
							opague_counter[AOP+5] += 1;
						} else if (Field[0][i][j] == Dynamic_ball) {
							opague_counter[AOP+6] += 1;
						} else if (Field[0][i][j] == Waves) {
							opague_counter[AOP+7] += 1;
						} else if (Field[0][i][j] == Waves_new) {
							opague_counter[AOP+8] += 1;
						} else if (Field[0][i][j] == Traps) {
							opague_counter[AOP+9] += 1;
						} else if (Field[0][i][j] == Bomb_4) {
							opague_counter[AOP+10] += 1;
						} else if (Field[0][i][j] == Bomb_3) {
							opague_counter[AOP+11] += 1;
						} else if (Field[0][i][j] == Bomb_2) {
							opague_counter[AOP+12] += 1;
						} else if (Field[0][i][j] == Bomb_1) {
							opague_counter[AOP+13] += 1;
						} else {
							opague_counter[Field[0][i][j]] += 1;
						}
					}
				}

				if ((i<(m-2))&&(Field[0][i][j] != 11)) {
					if (Field[0][i][j] == geben) {
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, temp_opague, 0, i+1, j, Field[0][i+1][j]);
					} else if ((Field[0][i+1][j] != 11)&&(Field[0][i+1][j] != 0)) {
						if (Field[0][i+1][j] == To_collect) {
							opague_counter[AOP+1] += 1;
						} else if (Field[0][i+1][j] == Fall_ball) {
							opague_counter[AOP+2] += 1;
						} else if (Field[0][i+1][j] == Wall) {
							opague_counter[AOP+3] += 1;
						} else if (Field[0][i+1][j] == Wall_at_the_end) {
							opague_counter[AOP+4] += 1;
						} else if (Field[0][i+1][j] == Raindrop) {
							opague_counter[AOP+5] += 1;
						} else if (Field[0][i+1][j] == Dynamic_ball) {
							opague_counter[AOP+6] += 1;
						} else if (Field[0][i+1][j] == Waves) {
							opague_counter[AOP+7] += 1;
						} else if (Field[0][i+1][j] == Waves_new) {
							opague_counter[AOP+8] += 1;
						} else if (Field[0][i+1][j] == Traps) {
							opague_counter[AOP+9] += 1;
						} else if (Field[0][i+1][j] == Bomb_4) {
							opague_counter[AOP+10] += 1;
						} else if (Field[0][i+1][j] == Bomb_3) {
							opague_counter[AOP+11] += 1;
						} else if (Field[0][i+1][j] == Bomb_2) {
							opague_counter[AOP+12] += 1;
						} else if (Field[0][i+1][j] == Bomb_1) {
							opague_counter[AOP+13] += 1;
						} else {
							opague_counter[Field[0][i+1][j]] += 1;
						}
					}
				}

				if ((i>1)&&(Field[0][i][j] != 11)) {
					if (Field[0][i][j] == geben) {
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, temp_opague, 0, i-1, j, Field[0][i-1][j]);
					} else if ((Field[0][i-1][j] != 11)&&(Field[0][i-1][j] != 0)) {
						if (Field[0][i-1][j] == To_collect) {
							opague_counter[AOP+1] += 1;
						} else if (Field[0][i-1][j] == Fall_ball) {
							opague_counter[AOP+2] += 1;
						} else if (Field[0][i-1][j] == Wall) {
							opague_counter[AOP+3] += 1;
						} else if (Field[0][i-1][j] == Wall_at_the_end) {
							opague_counter[AOP+4] += 1;
						} else if (Field[0][i-1][j] == Raindrop) {
							opague_counter[AOP+5] += 1;
						} else if (Field[0][i-1][j] == Dynamic_ball) {
							opague_counter[AOP+6] += 1;
						} else if (Field[0][i-1][j] == Waves) {
							opague_counter[AOP+7] += 1;
						} else if (Field[0][i-1][j] == Waves_new) {
							opague_counter[AOP+8] += 1;
						} else if (Field[0][i-1][j] == Traps) {
							opague_counter[AOP+9] += 1;
						} else if (Field[0][i-1][j] == Bomb_4) {
							opague_counter[AOP+10] += 1;
						} else if (Field[0][i-1][j] == Bomb_3) {
							opague_counter[AOP+11] += 1;
						} else if (Field[0][i-1][j] == Bomb_2) {
							opague_counter[AOP+12] += 1;
						} else if (Field[0][i-1][j] == Bomb_1) {
							opague_counter[AOP+13] += 1;
						} else {
							opague_counter[Field[0][i-1][j]] += 1;
						}
					}
				}

				if ((j>1)&&(Field[0][i][j] != 11)) {
					if (Field[0][i][j] == geben) {
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, temp_opague, 0, i, j-1, Field[0][i][j-1]);
					} else if ((Field[0][i][j-1] != 11)&&(Field[0][i][j-1] != 0)) {
						if (Field[0][i][j-1] == To_collect) {
							opague_counter[AOP+1] += 1;
						} else if (Field[0][i][j-1] == Fall_ball) {
							opague_counter[AOP+2] += 1;
						} else if (Field[0][i][j-1] == Wall) {
							opague_counter[AOP+3] += 1;
						} else if (Field[0][i][j-1] == Wall_at_the_end) {
							opague_counter[AOP+4] += 1;
						} else if (Field[0][i][j-1] == Raindrop) {
							opague_counter[AOP+5] += 1;
						} else if (Field[0][i][j-1] == Dynamic_ball) {
							opague_counter[AOP+6] += 1;
						} else if (Field[0][i][j-1] == Waves) {
							opague_counter[AOP+7] += 1;
						} else if (Field[0][i][j-1] == Waves_new) {
							opague_counter[AOP+8] += 1;
						} else if (Field[0][i][j-1] == Traps) {
							opague_counter[AOP+9] += 1;
						} else if (Field[0][i][j-1] == Bomb_4) {
							opague_counter[AOP+10] += 1;
						} else if (Field[0][i][j-1] == Bomb_3) {
							opague_counter[AOP+11] += 1;
						} else if (Field[0][i][j-1] == Bomb_2) {
							opague_counter[AOP+12] += 1;
						} else if (Field[0][i][j-1] == Bomb_1) {
							opague_counter[AOP+13] += 1;
						} else {
							opague_counter[Field[0][i][j-1]] += 1;
						}
					}
				}

				if ((j<(n-2))&&(Field[0][i][j] != 11)) {
					if (Field[0][i][j] == geben) {
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, temp_opague, 0, i, j+1, Field[0][i][j+1]);
					} else if ((Field[0][i][j+1] != 11)&&(Field[0][i][j+1] != 0)) {
						if (Field[0][i][j+1] == To_collect) {
							opague_counter[AOP+1] += 1;
						} else if (Field[0][i][j+1] == Fall_ball) {
							opague_counter[AOP+2] += 1;
						} else if (Field[0][i][j+1] == Wall) {
							opague_counter[AOP+3] += 1;
						} else if (Field[0][i][j+1] == Wall_at_the_end) {
							opague_counter[AOP+4] += 1;
						} else if (Field[0][i][j+1] == Raindrop) {
							opague_counter[AOP+5] += 1;
						} else if (Field[0][i][j+1] == Dynamic_ball) {
							opague_counter[AOP+6] += 1;
						} else if (Field[0][i][j+1] == Waves) {
							opague_counter[AOP+7] += 1;
						} else if (Field[0][i][j+1] == Waves_new) {
							opague_counter[AOP+8] += 1;
						} else if (Field[0][i][j+1] == Traps) {
							opague_counter[AOP+9] += 1;
						} else if (Field[0][i][j+1] == Bomb_4) {
							opague_counter[AOP+10] += 1;
						} else if (Field[0][i][j+1] == Bomb_3) {
							opague_counter[AOP+11] += 1;
						} else if (Field[0][i][j+1] == Bomb_2) {
							opague_counter[AOP+12] += 1;
						} else if (Field[0][i][j+1] == Bomb_1) {
							opague_counter[AOP+13] += 1;
						} else {
							opague_counter[Field[0][i][j+1]] += 1;
						}
					}
				}

				if ((Field[0][i][j+1] == geben)||(Field[0][i][j-1] == geben)||(Field[0][i-1][j] == geben)||(Field[0][i+1][j] == geben)) {
					for (unsigned int p=0; p<=AOP+extra; p+=1) {
						opague_counter[p] = 0;
					}
				}

				if (Opague_o.characterization % 10 == 1) {		//4-Mode-Opague, uneven
					for (unsigned int p=1; p<=AOP+extra; p+=1) {
						if (opague_counter[p] % 2 == 0) {
							opague_counter[p] = 0;
						}
					}	//p=10: Dynamic_ball

				} else if (Opague_o.characterization % 10 == 2) {		//4-Mode-Opague, even
					for (unsigned int p=1; p<=AOP+extra; p+=1) {
						if (opague_counter[p] % 2 == 1) {
							opague_counter[p] = 0;
						}
					}	//p=10: Dynamic_ball

				}

				opague_counter[0] = 0;

				for (unsigned int a=1; a<=AOP+extra; a+=1) {
					if (a != geben) {
						if (opague_counter[a] != 0) {

							for (unsigned int b=1; b<=AOP+extra; b+=1) {
								if (a != b) {
									if (opague_counter[a] > opague_counter[b]) {	//für AOP >= b > number_of_players gilt opague_counter[b] = 0;
										opague_counter[0] += 1;
									}
								}
							}

							if ((opague_counter[0] == AOP+extra-1)&&(temp_opague[0][i][j] == 0)) {	//bei Gleichstand zweier Objekte bleibt temp_opague[0][i][j] unbesetzt, da die AOP+extra-1 von keinem erreicht wird
								if (a == AOP+1) {
									set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, temp_opague, 0, i, j, To_collect);
								} else if (a == AOP+2) {
									set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, temp_opague, 0, i, j, Fall_ball);
								} else if (a == AOP+3) {
									set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, temp_opague, 0, i, j, Wall);
								} else if (a == AOP+4) {
									set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, temp_opague, 0, i, j, Wall_at_the_end);
								} else if (a == AOP+5) {
									set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, temp_opague, 0, i, j, Raindrop);
								} else if (a == AOP+6) {
									set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, temp_opague, 0, i, j, Dynamic_ball);
								} else if (a == AOP+7) {
									set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, temp_opague, 0, i, j, Waves);
								} else if (a == AOP+8) {
									set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, temp_opague, 0, i, j, Waves_new);
								} else if (a == AOP+9) {
									set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, temp_opague, 0, i, j, Traps);
								} else if (a == AOP+10) {
									set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, temp_opague, 0, i, j, Bomb_4);
								} else if (a == AOP+11) {
									set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, temp_opague, 0, i, j, Bomb_3);
								} else if (a == AOP+12) {
									set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, temp_opague, 0, i, j, Bomb_2);
								} else if (a == AOP+13) {
									set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, temp_opague, 0, i, j, Bomb_1);
								} else {
									set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, temp_opague, 0, i, j, a);
								}
							}
							opague_counter[0] = 0;
						}
					}
				}

				for (unsigned int p=0; p<=AOP+extra; p+=1) {
					opague_counter[p] = 0;
				}


			} else if (Opague_o.characterization >= 10) {		//4-Mode-Opague, Surrounding

				for (unsigned int h=i-1; h<=i+1; h+=1){
					for (unsigned int k=j-1; k<=j+1; k+=1){
						if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
							if (Field[0][h][k] != 11) {
								if (Field[0][i][j] == geben) {
									set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, temp_opague, 0, h, k, Field[0][h][k]);
								} else if ((Field[0][h][k] != 11)&&(Field[0][h][k] != 0)) {
									if (Field[0][h][k] == To_collect) {
										opague_counter[AOP+1] += 1;
									} else if (Field[0][h][k] == Fall_ball) {
										opague_counter[AOP+2] += 1;
									} else if (Field[0][h][k] == Wall) {
										opague_counter[AOP+3] += 1;
									} else if (Field[0][h][k] == Wall_at_the_end) {
										opague_counter[AOP+4] += 1;
									} else if (Field[0][h][k] == Raindrop) {
										opague_counter[AOP+5] += 1;
									} else if (Field[0][h][k] == Dynamic_ball) {
										opague_counter[AOP+6] += 1;
									} else if (Field[0][h][k] == Waves) {
										opague_counter[AOP+7] += 1;
									} else if (Field[0][h][k] == Waves_new) {
										opague_counter[AOP+8] += 1;
									} else if (Field[0][h][k] == Traps) {
										opague_counter[AOP+9] += 1;
									} else if (Field[0][h][k] == Bomb_4) {
										opague_counter[AOP+10] += 1;
									} else if (Field[0][h][k] == Bomb_3) {
										opague_counter[AOP+11] += 1;
									} else if (Field[0][h][k] == Bomb_2) {
										opague_counter[AOP+12] += 1;
									} else if (Field[0][h][k] == Bomb_1) {
										opague_counter[AOP+13] += 1;
									} else {
										opague_counter[Field[0][h][k]] += 1;
									}
								}
							}
						}
					}
				}

				if (Opague_o.characterization % 10 == 1) {		//4-Mode-Opague, uneven
					for (unsigned int p=1; p<=AOP+extra; p+=1) {
						if (opague_counter[p] % 2 == 0) {
							opague_counter[p] = 0;
						}
					}	//p=10: Dynamic_ball
				} else if (Opague_o.characterization % 10 == 2) {		//4-Mode-Opague, even
					for (unsigned int p=1; p<=AOP+extra; p+=1) {
						if (opague_counter[p] % 2 == 1) {
							opague_counter[p] = 0;
						}
					}	//p=10: Dynamic_ball
				}

				opague_counter[0] = 0;

				for (unsigned int a=1; a<=AOP+extra; a+=1) {	//Übertragung auf temp_opague
					if (a != geben) {
						if (opague_counter[a] != 0) {

							for (unsigned int b=1; b<=AOP+extra; b+=1) {
								if (a != b) {
									if (opague_counter[a] > opague_counter[b]) {
										opague_counter[0] += 1;
									}
								}
							}

							if ((opague_counter[0] == AOP+extra-1)&&(temp_opague[0][i][j] == 0)) {	//bei Gleichstand zweier Objekte bleibt temp_opague[0][i][j] unbesetzt, da die AOP+extra-1 von keinem erreicht wird
								if (a == AOP+1) {
									set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, temp_opague, 0, i, j, To_collect);
								} else if (a == AOP+2) {
									set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, temp_opague, 0, i, j, Fall_ball);
								} else if (a == AOP+3) {
									set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, temp_opague, 0, i, j, Wall);
								} else if (a == AOP+4) {
									set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, temp_opague, 0, i, j, Wall_at_the_end);
								} else if (a == AOP+5) {
									set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, temp_opague, 0, i, j, Raindrop);
								} else if (a == AOP+6) {
									set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, temp_opague, 0, i, j, Dynamic_ball);
								} else if (a == AOP+7) {
									set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, temp_opague, 0, i, j, Waves);
								} else if (a == AOP+8) {
									set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, temp_opague, 0, i, j, Waves_new);
								} else if (a == AOP+9) {
									set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, temp_opague, 0, i, j, Traps);
								} else if (a == AOP+10) {
									set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, temp_opague, 0, i, j, Bomb_4);
								} else if (a == AOP+11) {
									set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, temp_opague, 0, i, j, Bomb_3);
								} else if (a == AOP+12) {
									set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, temp_opague, 0, i, j, Bomb_2);
								} else if (a == AOP+13) {
									set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, temp_opague, 0, i, j, Bomb_1);
								} else {
									set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, temp_opague, 0, i, j, a);
								}
							}

							opague_counter[0] = 0;
						}
					}
				}

				for (unsigned int p=0; p<=AOP+extra; p+=1) {
					opague_counter[p] = 0;
				}
			//AOP und opague_counter ersetzen/anpassen... , done
			}

			if (Field[0][i][j] == 11) {
				set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, temp_opague, 0, i, j, 11);
			}
		}
	}

	for (unsigned int i=1; i<m-1; i+=1){
		for (unsigned int j=1; j<n-1; j+=1){
			set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Opague_o.field, 0, i, j, temp_opague[0][i][j]);
		}
	}

	Spielfeld_Destroy (temp_opague, m, 0);
	unsigned_int_Vektor_Destroy (opague_counter);
}

int sgn (int a){	//sgn(0)=0;
	int sgna;
	sgna = 0;

	if (abs(a) != 0){
		sgna = a/abs(a);
	} else {
		sgna = 0;
	}

	return sgna;
}

void Reflection (int* dynamic_pointer, unsigned int a, int erd){

	dynamic_pointer[0+a] *= (-1);
	dynamic_pointer[2+a] *= (-1);

	if (sgn(dynamic_pointer[4+a])>0) {
		dynamic_pointer[4+a] -= 1;
	} else if (sgn(dynamic_pointer[4+a])<0) {
		dynamic_pointer[4+a] += 1;
	}

	for (int r=1; r<=2*abs(erd); r+=1) {
		if (sgn(dynamic_pointer[0+a]) > 0) {
			dynamic_pointer[0+a] -= 1;
			if (dynamic_pointer[0+a] == 0) {
				break;
			}
		} else if (sgn(dynamic_pointer[0+a]) < 0) {
			dynamic_pointer[0+a] += 1;
			if (dynamic_pointer[0+a] == 0) {
				break;
			}
		}

	}

}

void impact_y_semi_square (unsigned int m, unsigned int n, unsigned int* position, Earth_impact impact_tuple, int* dynamic_pointer, Spielfeld Field){

	for (unsigned int i=0; i<m-1; i+=1) {	//Berechnung impact y
		for (unsigned int j=0; j<n-1; j+=1) {
			if ((Field[0][i][j] != 0)&&(Field[0][i][j] != Dynamic_ball)) {
				if ((abs(position[Vertikal]-i)+abs(position[Horizontal]-j))<=(abs(impact_tuple.range)+1)) {	//Manhatten-Norm
					if ((position[Vertikal]-i) != 0) {
						dynamic_pointer[7] += (sgn(position[Vertikal]-i))*(impact_tuple.strength*(impact_tuple.range+1-abs(position[Vertikal]-i))*(impact_tuple.range+1-abs(position[Vertikal]-i)) +1);
					}
					if ((position[Horizontal]-j) != 0) {
						dynamic_pointer[6] += (sgn(position[Horizontal]-j))*(impact_tuple.strength*(impact_tuple.range+1-abs(position[Horizontal]-j))*(impact_tuple.range+1-abs(position[Horizontal]-j)) +1);
					}
				}
			}
		}
	}

}

void show_whose_turn (unsigned int gamemode_played, unsigned int geben, unsigned int* ability, Growth_Player* Growth_players, unsigned int* level, unsigned int number_of_players) {
	if (Growth_players[0].color == 1) {
		Square_color_interpretation (Growth_players, geben, number_of_players, geben);
	}

	if (gamemode_played == Hunt) {
		if (geben == 1) {
			printf("	Am Zug: Spieler %u (##)	", geben);
		} else if (geben == 2) {
			printf("	Am Zug: Spieler %u (AA)	", geben);
		} else if (geben == 3) {
			printf("	Am Zug: Spieler %u (BB)	", geben);
		} else if (geben == 4) {
			printf("	Am Zug: Spieler %u (CC)	", geben);
		} else if (geben == 5) {
			printf("	Am Zug: Spieler %u (DD)	", geben);
		} else if (geben == 6) {
			printf("	Am Zug: Spieler %u (EE)	", geben);
		} else if (geben == 7) {
			printf("	Am Zug: Spieler %u (FF)	", geben);
		} else if (geben == 8) {
			printf("	Am Zug: Spieler %u (GG)	", geben);
		} else if (geben == 9) {
			printf("	Am Zug: Spieler %u (HH)	", geben);
		}
	} else if (gamemode_played == Arena) {
		if (ability[1] == geben) {
			printf("	Am Zug: Spieler %u (UU)	", geben);
		} else if (ability[2] == geben) {
			printf("	Am Zug: Spieler %u (LL)	", geben);
		} else if (ability[3] == geben) {
			printf("	Am Zug: Spieler %u (AA)	", geben);
		} else if (ability[4] == geben) {
			printf("	Am Zug: Spieler %u (CC)	", geben);
		} else if (ability[5] == geben) {
			printf("	Am Zug: Spieler %u (II)	", geben);
		} else if (ability[6] == geben) {
			printf("	Am Zug: Spieler %u (SS)	", geben);
		} else if (ability[7] == geben) {
			printf("	Am Zug: Spieler %u (PP)	", geben);
		} else if (ability[8] == geben) {
			printf("	Am Zug: Spieler %u (HH)	", geben);
		} else if (ability[9] == geben) {
			printf("	Am Zug: Spieler %u (EE)	", geben);
		}
	} else {
		printf("	Am Zug: Spieler %u (%u%u)	", geben, geben, geben);
	}

	if (level[geben] == human) {
		printf("\n");
	} else {
		if (level[geben] == Delilag) {
			printf("Delilag");
		} else if (level[geben] == Hera) {
			printf("Hera");
		} else if (level[geben] == Yasmin) {
			printf("Yasmin");
		} else if (level[geben] == Coco) {
			printf("Coco");
		} else if (level[geben] == Natalie) {
			printf("Natalie");
		} else if (level[geben] == Liz) {
			printf("Liz");
		} else if (level[geben] == Jill) {
			printf("Jill");
		} else if (level[geben] == Uma) {
			printf("Uma");
		}
		printf("\n");
	}
	
	if (Growth_players[0].color == 1) {
		set_terminal_color (cNORMAL);
	}
	printf("\n");

}

void show_statistics (unsigned int number_of_players, unsigned int gamemode_played, Spielfeld numbers_of_, unsigned int* rmv_Points, unsigned int exclude_counter, unsigned int* rmv_ulcer_lifes, unsigned int* ges, unsigned int* pere, unsigned int* ability, unsigned int time_matters_ttt, Quidditch_setup* Qs) {

	printf("\n");
	for (unsigned int p=1; p<=number_of_players; p+=1) {
		printf("	Numbers of player %u: \n", p);
		for (unsigned int q=1; q<=6; q+=1) {
			printf("		#%u = %u \n", q, numbers_of_[p][q][0]);
		}
		printf("\n");
	}

	if ((gamemode_played == Classic)||(gamemode_played == Hunt)||(gamemode_played == Race)||(gamemode_played == Rain)||(gamemode_played == Sand)) {
		for (unsigned int p=1; p<=number_of_players; p+=1) {
			printf("	Matchballs player %u:   %u \n", p, numbers_of_[p][0][0]);
		}
	} else if (gamemode_played == Collect) {
		for (unsigned int p=1; p<=number_of_players; p+=1) {
			printf("	Squares collected by player %u:   %u \n", p, numbers_of_[p][0][0]);
		}
	} else if (gamemode_played == Contact) {
		for (unsigned int p=1; p<=number_of_players; p+=1) {
			printf("	Times with squares <= 5, player %u:   %u \n", p, numbers_of_[p][0][0]);
		}
	} else if (gamemode_played == Fall) {
		for (unsigned int p=1; p<=number_of_players; p+=1) {
			printf("	Points player %u:     %u \n", p, rmv_Points[p]);
			printf("	Turns with more points player %u:   %u \n", p, numbers_of_[p][0][0]);
		}
		printf("	Number of not decided #-squares:  %u \n", rmv_Points[0]);
	} else if (gamemode_played == Fight) {
		for (unsigned int p=1; p<=number_of_players; p+=1) {
			printf("	Times with squares < 5, player %u:  %u \n", p, numbers_of_[p][0][0]);
		}
	} else if (gamemode_played == Arena) {
		printf("	Number of excluded abilities:  %u \n", exclude_counter);
		printf("	Offensive abilities taken:  %u \n", number_of_players-ability[0]);
		printf("	Defensive abilities taken:  %u \n", ability[0]);
	} else if (gamemode_played == Ulcer) {
		for (unsigned int p=1; p<=number_of_players; p+=1) {
			if ((ges[p] < 1000)&&(ges[p] != 0)) {
				printf("		Spieler %u: %u life(s) left.\n", p, rmv_ulcer_lifes[p]);
			}
		}
	} else if ((gamemode_played == Dynamic)||(gamemode_played == Survive)||(gamemode_played == Sand)) {	//mehr-gamemode_played
		for (unsigned int p=1; p<=number_of_players; p+=1) {
			if ((ges[p] > 1000)||(ges[p] == 0)) {
				printf("	Spieler %u: is out.\n", p);
			} else if (ges[p] < 1000) {
				printf("	Spieler %u: You own %u squares.\n", p, ges[p]);
			}
		}
	} else if (gamemode_played == Quidditch) {
		printf("	Klatscher-hits:     %u \n", Qs->Points[0]);
		for (unsigned int p=1; p<=number_of_players; p+=1) {
			printf("	Points player %u:     %u \n", p, Qs->Points[p]);
		}
	}
	printf("\n");
	if (time_matters_ttt != 0) {
		printf("	Number of penalties given until now: %u \n", pere[0]);
	}

}

void show_options_of_actions (unsigned int gamemode_played, unsigned int* information_code, unsigned int geben) {

	printf("	1) Plus:	%u	Minus :	%u \n", Plus_, Minus_);
	printf("	2) Move:	%u	Change:	%u \n", Move_2, Change_);
	printf("	3) Destroy:	%u	Revive:	%u \n", Destroy_, Revive_);
	printf("	4) Move:	%u	Boost:	%u \n", Move_4, Boost_);
	if (((gamemode_played != Arena)&&(gamemode_played != Ulcer))||((gamemode_played == Ulcer)&&(geben == 1))) {
		printf("	5) 4/5-new:	%u	2-new:	%u \n", new_4_5, new_2);
		printf("	6) 4-max:	%u	1-min:	%u \n", max_4, min_1);
	} else if (gamemode_played == Arena) {
		if (information_code[0] == 1) {
			printf("	5) 2/3-new:	51	0-new:	52 \n");
			printf("	6) 2-max:	61	-1-min:	62 \n");
		} else if (information_code[0] == 2) {
			printf("	5) 3/4-new:	51	1-new:	52 \n");
			printf("	6) 3-max:	61	0-min:	62 \n");
		} else if (information_code[0] == 3) {
			printf("	5) 5/6-new:	51	3-new:	52 \n");
			printf("	6) 5-max:	61	0-min:	62 \n");
		} else {
			printf("	5) 4/5-new:	%u	2-new:	%u \n", new_4_5, new_2);
			printf("	6) 4-max:	%u	1-min:	%u \n", max_4, min_1);
		}
	} else if ((gamemode_played == Ulcer)&&(geben != 1)) {
		printf("	5) 3/4-new:	51	1-new:	52 \n");
		printf("	6) 3-max:	61	0-min:	62 \n");
	}
	printf("							\n");
	printf("		Go back: 100 \n");
	printf("		Menu: 10 \n");
	printf("		End game: 0 \n");

}

void About_the_game (unsigned int gamemode_played, unsigned int geben, Limits limits, unsigned int number_of_players, unsigned int freq, unsigned int w, unsigned int d, unsigned int e) {

	if (gamemode_played == Classic) {
		printf("	How to win?   Own a square on your last line or force your opponents to lose all his/her ones.\n");
	} else if (gamemode_played == Collect) {
		printf("	How to win?   Be at 2 of the 3 targets with three of your squares near-by.\n");
	} else if (gamemode_played == Contact) {
		printf("	How to win?   Take over all your opponents' squares by winning Contact-battles.\n");
		printf("	Contact-battles?  All near-by squares in a row with the Contact-square build a chain, beat your opponents in the length.\n");
	} else if (gamemode_played == Fall) {
		printf("	How to win?   Get more points than your opponents.\n");
		printf("	Note:	Touch the #-square in the near-by to move it to the opposite side. \n");
	} else if (gamemode_played == Fight) {
		printf("	How to win?   Force your opponents to lose all his/her squares.\n");
	} else if (gamemode_played == Hunt) {
		if (geben == 1) {
			printf("	How to win?   Protect your heart-block so no enemy can touch it.\n");
		} else {
			printf("	How to win?   Catch the heart-block of the hunted one before it disappears.\n");
		}
	} else if (gamemode_played == Race) {
		printf("	How to win?   Reach the end of the field or force your opponents to lose all his/her ones.\n");
		printf("	Note:	Every %u turns in total the #-line will go ahead and destroys everything in it's way.\n Also you are not allowed to cross the mid-line. \n", freq);
	} else if (gamemode_played == Rain) {
		printf("	How to win?   Reach [1][7]");
		for (unsigned int p=2; p<=number_of_players; p++) {
			printf(" or [1][%u]", (p-1)*7);
		}
		printf(" of the field or force your opponents to lose all his/her squares.\n");
		printf("	Note:	Falling down the #-squares will push, destroy, explode, or teleport, transform into yours by Contact. \n");
	} else if ((gamemode_played == Arena)||(gamemode_played == Ulcer)) {	//10
		printf("	How to win?   Force your opponents to lose all his/her squares while keeping yours alive.\n");
	} else if (gamemode_played == Dynamic) {
		printf("	How to win?   Push the ball against your opponent's side.\n");
	} else if (gamemode_played == Survive) {
		printf("	How to win?   Stay alive.\n");
	} else if (gamemode_played == Sand) {
		printf("	How to win?   Reach the top.\n");
	}
	printf("	Surrounding:	The 8 squares around another, at the edge 5, in the corners 3, are called #surrounding. \n");
	printf("	near-by:	The 4 squares around another, at the edge 3, in the corners 2, are called #near-by. \n");
	printf("	Standard actions:	(After your choice of number and not influencing each other) \n	-Development:	If it is your turn and a free square has exactly %u of yours surrounding it, you will own it.\n", w);
	printf("	-Losses:  If it is your turn and a square of yours is surrounded by less than %u or more than %u of yours,\n			it will be set free.\n", d, e);	//10
	if ((gamemode_played == Hunt)&&(geben == 1)) {	//If geben == 1
		printf("	Limits:   Your development is limited by %u per round, your units in total by %u per round. \n", (limits.new+(number_of_players-3)), (limits.at_all+(2*(number_of_players-3))));
	} else if ((gamemode_played == Ulcer)||(gamemode_played == Survive)) {
		printf("	Limits:   This gamemode is unlimited. \n");
	} else if (gamemode_played == Contact) {
		printf("	Limits:   Your development is limited by %u per round. \n", limits.new);
	} else {
		printf("	Limits:   Your development is limited by %u per round, your units in total by %u per round. \n", limits.new, limits.at_all);
	}

}

void show_the_numbers (unsigned int gamemode_played, unsigned int w, unsigned int d, unsigned int e, unsigned int geben) {

	if ((gamemode_played != Ulcer)&&(gamemode_played != Survive)) {
		printf("	Plus: Change a free square in the surrounding of yours in one of yours.\n");
	} else {
		printf("	Plus: Change a square in the surrounding of yours in one of yours.\n");
	}
	printf("	Minus: Delete one of your squares.\n");
	printf("	Move: The position of one of yours will change with a free, near-by square.\n");
	printf("	Revive: Your lost squares having no living squares of yours surrounding them at the beginning of your turn,\n		will be revived.\n");
	printf("	%u/%u-new: A free square has to be surrounded by %u or %u of yours during the development.\n", w+1, w+2, w+1, w+2);
	printf("	%u-new: A free square has to be surrounded by %u of yours during the development.\n", w-1, w-1);
	printf("	%u-max: A square of yours will survive even by %u of your squares surrounding it.\n", e+1, e+1);
	if (d == 0) {
		printf("	-1-min: A square of yours will survive even by only -1 of your squares surrounding it.\n");
	} else {
		printf("	%u-min: A square of yours will survive even by only %u of your squares surrounding it.\n", d-1, d-1);
	}

	if ((gamemode_played == Classic)||(gamemode_played == Collect)||(gamemode_played == Fall)||(gamemode_played == Fight)||(gamemode_played == Race)||(gamemode_played == Arena)||(gamemode_played == Ulcer)||(gamemode_played == Sand)) {	//mehr-gamemode_played
		printf("	Change: A square of yours and a near-by square of your enemy will change positions.\n");
		printf("	Destroy: Delete a near-by square of your enemy.\n");
		printf("	Boost: Use all near-by squares of your enemy as your own for the development according to dead squares.\n");

	} else if (gamemode_played == Contact) {
		printf("	Change: A square of yours and a square of your enemy in the surrounding will change positions.\n");
		printf("	Destroy: Delete a surrounding square of your enemy.\n");
		printf("	Boost: Use all surrounding squares of your enemy as your own for the development according to dead squares.\n");

	} else if (gamemode_played == Rain) {
		printf("	Change: A square of yours and a near-by #-square will change positions.\n");
		printf("	Destroy: Delete a square of your enemy, but not in the last two lines.\n");
		printf("	Boost: Use all near-by #-squares as your own for the development according to dead squares.\n");

	} else if (gamemode_played == Hunt) {
		if (geben == 1) {
			printf("	Change: The heart-block and a square of yours will change positions.\n");
			printf("	Destroy: Delete a square of your enemy.\n");
			printf("	Boost: Touching the heart_block no square of yours can die.\n");
		} else {
			printf("	Change: A square of yours and a near-by square of the hunted one will change positions.\n");
			printf("	Destroy: Delete a near-by square of your enemy.\n");
			printf("	Boost: Use all near-by squares of the hunted one as your own for the development according to dead squares.\n");
		}

	} else if (gamemode_played == Dynamic) {
		printf("	Change: A square of yours and a near-by square of your enemy or the near-by ball will change positions.\n");
		printf("	Destroy: Delete a near-by square of your enemy.\n");
		printf("	Boost: Use all near-by squares of your enemy and the near-by ball as your own for the development according to dead squares.\n");
	} else if (gamemode_played == Survive) {
		printf("	Change: A square of yours and a near-by square of your enemy or a near-by object will change positions.\n");
		printf("	Destroy: Delete a near-by square of your enemy or a near-by object.\n");
		printf("	Boost: Use all near-by squares of your enemy and near-by objects as your own for the development according to dead squares.\n");
	}

	printf("\n");
}

void get_hints (unsigned int* level, Spielfeld Sf_permutations, unsigned int gamemode_played, Spielfeld Field, unsigned int geben, unsigned int w, unsigned int d, unsigned int e, unsigned int m, unsigned int n, unsigned int* information_code, Special_Fields Opague_o, Growth_Player* Growth_players, unsigned int AOP, Special_Fields Allocation_o, unsigned int number_of_players) {

	Spielfeld hint;
	unsigned int b, a, menuoperator;
	hint = Spielfeld_Create (m, n, 0);

	b = 0;
	a = 0;
	menuoperator = 0;

	for (unsigned int i=1; i<(m-1); i+=1){
		for (unsigned int j=1; j<(n-1); j+=1){
			if (Field[0][i][j] == geben){
				set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, hint, 0, i, j, geben);
			} else if (Field[0][i][j] != 0){
				set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, hint, 0, i, j, bir_sey);
			}
		}
	}

	printf("	New: 1 \n	Dying: 2 \n	Both: 3 \n");
	menuoperator = get_unsigned_numeric_input_with_not_more_than_1_letter ();

	if ((menuoperator == 2)||(menuoperator == 3)){
		for (unsigned int i=1; i<(m-1); i+=1){
			for (unsigned int j=1; j<(n-1); j+=1){
				if (Field[0][i][j] == geben){
					a = 0;
					for (unsigned int h=(i-1); h<=(i+1); h+=1){
						for (unsigned int k=(j-1); k<=(j+1); k+=1){
							if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
								if (Field[0][h][k] == geben){
									a += 1;
								}
							}
						}
					}
					if ((a > e+1) || (a <= d)){
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, hint, 0, i, j, oeluem);
					}
				}
			}
		}
	}

	if ((menuoperator == 1)||(menuoperator == 3)){
		for (unsigned int i=1; i<(m-1); i+=1){
			for (unsigned int j=1; j<(n-1); j+=1){
				if (Field[0][i][j] == 0){
					b = 0;
					for (unsigned int h=(i-1); h<=(i+1); h+=1){
						for (unsigned int k=(j-1); k<=(j+1); k+=1){
							if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
								if (Field[0][h][k] == geben){
									b += 1;
								}
							}
						}
					}
					if (b == w){
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, hint, 0, i, j, dogum);
					}
				}
			}
		}
	}

	if (Opague_o.characterization >= 1) {
		opague_builder (hint, Opague_o, m, n, geben, AOP, Allocation_o, number_of_players, gamemode_played);
		show_field (number_of_players, level, Sf_permutations, Opague_o.field, Opague_o.field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
	} else {
		show_field (number_of_players, level, Sf_permutations, Opague_o.field, hint, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
	}

	Spielfeld_Destroy (hint, m, 0);

}

void Initialisierung_Qs (Quidditch_setup* Qs, Quidditch_team_abilities* Qta, Quidditch_object_abilities* Qoa, Growth_Player* Growth_players) {
	unsigned int color_translation[3], numberofplayers;
	numberofplayers = 2;
	
	color_translation[0] = 0;
	
	for (unsigned int p=1; p<=numberofplayers; p++) {
		unsigned int choice, types;
		types = 3;
		choice = types + 1;
		
		while (choice > types) {
			printf("	Which Quidditch-team-abilities do you want to take, player %u ? \n	0 : basic\n	1 : default_1 \n	2 : default_2 \n	%u : classic \n", p, types);
			choice = get_unsigned_numeric_input_with_not_more_than_1_letter ();
		}
		
		if (choice <= 2) {
			color_translation[p] = choice;	//thats 0,1,2
		} else if (choice == types) {
			if (Growth_players[p].color == cLIGHT_MAGENTA) {
				color_translation[p] = HGryffindor;
			} else if (Growth_players[p].color == cLIGHT_CYAN) {
				color_translation[p] = HRavenclaw;
			} else if (Growth_players[p].color == cYELLOW) {
				color_translation[p] = HHufflepuff;
			} else if (Growth_players[p].color == cLIGHT_GREEN) {
				color_translation[p] = HSlytherin;
			}
		}
	}
	
	for (unsigned int q=0; q<=2; q++) {	//the right modification of the abilities, reducing from 1+2+4 to 1+2 ("1+" because of the standard-setting, "2+" because of the defaults).
		Qs->Qta[q] = Qta[color_translation[p]];	//that means: no copy.
		Qs->Points[q] = 0;
	}
	Qs->Qoa = Qoa;
	
}
void Initialisierung_Qoa (Quidditch_object_abilities* Qoa) {
	Qoa[0].Klatscher_fly_distance = 3;
	Qoa[0].Schnatz_fly_distance = 3;
	Qoa[0].Schnatz_appearence_factor = 13;	//to read as 1/3
	Qoa[0].Schnatz_disappearence_factor = 23;	//to read as 2/3
}
void Initialisierung_Qta (Quidditch_team_abilities* Qta) {
	for (unsigned int p=0; p<=HSlytherin; p++) {
		Qta[p].Jaeger_fly_distance = 3;
		Qta[p].Jaeger_throw_distance = 3;
		Qta[p].Hueter_fly_distance = 2;
		Qta[p].Hueter_throw_distance = 3;
		Qta[p].Treiber_fly_distance = 3;
		Qta[p].Treiber_hit_distance = 3;
		Qta[p].Sucher_fly_distance = 3;
		
		if (p == HGryffindor) {
			Qta[p].Sucher_fly_distance = 4;
		} else if (p == HHufflepuff) {
			Qta[p].Hueter_fly_distance = 4;
			Qta[p].Hueter_throw_distance = 4;
		} else if (p == HRavenclaw) {
			Qta[p].Jaeger_fly_distance = 4;
			Qta[p].Jaeger_throw_distance = 4;
		} else if (p == HSlytherin) {
			Qta[p].Treiber_fly_distance = 4;
			Qta[p].Treiber_hit_distance = 4;
		}
	}
}

void Initialisierung_Moc (Moveable_objects_condition* Moc_Quaffel, Moveable_objects_condition* Moc_Schnatz, Moveable_objects_condition* Moc_Klatscher, unsigned int m, unsigned int n) {
	
	Moc_Quaffel->i = (m-2)/2;
	Moc_Quaffel->j = (n-1)/2;
	
	Moc_Schnatz->i = (m-2)/2 +1;
	Moc_Schnatz->j = (n-1)/2;
	Moc_Schnatz->directed = evet;
	
	Moc_Klatscher[0].i = (m-2)/2 -1;
	Moc_Klatscher[0].j = (n-1)/2;
	Moc_Klatscher[1].i = (m-2)/2 +2;
	Moc_Klatscher[1].j = (n-1)/2;
	
}

void Initialisierung (unsigned int gamemode_played, unsigned int* information_code) {
	if (gamemode_played == Survive) {

		for (unsigned int p=1; p<=3; p+=1) {
			information_code[p] = 1;
		}
	} else if (gamemode_played == Sand) {

		for (unsigned int p=1; p<=3; p+=1) {
			information_code[p] = 1 + p/3;
		}
	}

}

unsigned int Initialisierung_limits_new (unsigned int gamemode_played) {
	unsigned int Ausgabe;
	Ausgabe = 0;

	if ((gamemode_played == Classic)||(gamemode_played == Collect)||(gamemode_played == Dynamic)||(gamemode_played == Sand)) {
		Ausgabe = 10;
	} else if (gamemode_played == Contact) {
		Ausgabe = 15;
	} else if ((gamemode_played == Fall)||(gamemode_played == Race)||(gamemode_played == Rain)) {
		Ausgabe = 7;
	} else if (gamemode_played == Fight) {
		Ausgabe = 5;
	} else if (gamemode_played == Hunt) {
		Ausgabe = 6;
	} else if (gamemode_played == Arena) {
		Ausgabe = 8;
	} else if (gamemode_played == Quidditch) {
		Ausgabe = 20;
	} else {
		Ausgabe = 0;
	}

	return Ausgabe;
}

unsigned int Initialisierung_limits_at_all (unsigned int gamemode_played) {
	unsigned int Ausgabe;
	Ausgabe = 0;

	if ((gamemode_played == Classic)||(gamemode_played == Collect)||(gamemode_played == Dynamic)||(gamemode_played == Sand)) {
		Ausgabe = 20;
	} else if ((gamemode_played == Fall)||(gamemode_played == Race)||(gamemode_played == Rain)) {
		Ausgabe = 14;
	} else if (gamemode_played == Fight) {
		Ausgabe = 10;
	} else if (gamemode_played == Hunt) {
		Ausgabe = 12;
	} else if (gamemode_played == Arena) {
		Ausgabe = 16;
	} else if (gamemode_played == Quidditch) {
		Ausgabe = 40;
	} else {
		Ausgabe = 0;
	}

	return Ausgabe;
}

unsigned int Initialisierung_n (unsigned int gamemode_played) {	//real+2
	unsigned int Ausgabe;
	Ausgabe = 0;

	if ((gamemode_played == Classic)||(gamemode_played == Fight)||(gamemode_played == Ulcer)) {
		Ausgabe = 8;
	} else if ((gamemode_played == Collect)||(gamemode_played == Fall)||(gamemode_played == Dynamic)||(gamemode_played == Survive)) {
		Ausgabe = 13;
	} else if (gamemode_played == Contact) {
		Ausgabe = 18;
	} else if (gamemode_played == Hunt) {
		Ausgabe = 11;
	} else if (gamemode_played == Race) {
		Ausgabe = 21;
	} else if (gamemode_played == Rain) {
		Ausgabe = 15;
	} else if ((gamemode_played == Arena)||(gamemode_played == Sand)) {
		Ausgabe = 9;
	} else if (gamemode_played == Quidditch) {
		Ausgabe = 15;
	} else {
		Ausgabe = 0;
	}

	return Ausgabe;
}

unsigned int Initialisierung_m (unsigned int gamemode_played) {	//real+2
	unsigned int Ausgabe;

	Ausgabe = 0;

	if ((gamemode_played == Classic)||(gamemode_played == Contact)) {
		Ausgabe = 12;
	} else if (gamemode_played == Collect) {
		Ausgabe = 11;
	} else if ((gamemode_played == Fall)||(gamemode_played == Fight)||(gamemode_played == Rain)||(gamemode_played == Ulcer)) {
		Ausgabe = 8;
	} else if ((gamemode_played == Hunt)||(gamemode_played == Race)||(gamemode_played == Arena)||(gamemode_played == Dynamic)||(gamemode_played == Sand)) {
		Ausgabe = 9;
	} else if (gamemode_played == Survive) {
		Ausgabe = 13;
	} else if (gamemode_played == Quidditch) {
		Ausgabe = 22;
	} else {
		Ausgabe = 0;
	}

	return Ausgabe;
}

void Initialisierung_Arrays_1 (unsigned int AOP, unsigned int* ability, unsigned int* ulcer_lifes, unsigned int* number_){

	unsigned_int_array_null_initialisierung (ability, AOP);	//0 - AOP
	unsigned_int_array_null_initialisierung (ulcer_lifes, AOP);
	unsigned_int_array_null_initialisierung (number_, AOP);

	for (unsigned int p=1; p<=AOP; p+=1) {
		ulcer_lifes[p] = p-1;
	}
}

void Initialisierung_Arrays_2 (unsigned int AOP, unsigned int* pere, unsigned int* ges, unsigned int* var_, unsigned int* ulcer_start, unsigned int* win_condition, unsigned int* out_counter, unsigned int* number_, unsigned int* cons){

	unsigned_int_array_null_initialisierung (pere, AOP);	//0 - AOP
	unsigned_int_array_null_initialisierung (ges, AOP);
	unsigned_int_array_null_initialisierung (var_, AOP);
	unsigned_int_array_null_initialisierung (ulcer_start, AOP);
	unsigned_int_array_null_initialisierung (win_condition, AOP);
	unsigned_int_array_null_initialisierung (out_counter, AOP);
	unsigned_int_array_null_initialisierung (number_, AOP);
	unsigned_int_array_null_initialisierung (cons, AOP);

	for (unsigned int p=0; p<=AOP; p+=1) {
		ulcer_start[p] = missing;
		// printf("ulcer_start[%u] = %u \n", p, ulcer_start[p]);	//test
	}
	ulcer_start[1] = existing;
	// printf("ulcer_start[1] = %u \n", ulcer_start[1]);	//test
}

unsigned int get_m (unsigned int gamemode_played, unsigned int number_of_players) {
	unsigned int m;
	m = 0;

	if (gamemode_played == Classic){	//that's right
		printf(" Zeilen: >=6				(normal: 10) \n");
		m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

		if (m<6){
			printf("	You missed the assertion(s) !!! \n");
			printf("\n");
			m = 12;
		} else {
			m += 2;
		}
	} else if (gamemode_played == Collect) {
		printf(" Zeilen: >=7, mod2==1				(normal: 9) \n");
		m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

		if ((m<7)||(m%2==0)){
			printf("	You missed the assertion(s) !!! \n");
			printf("\n");
			m = 9 +2;
		} else {
			m += 2;
		}
	} else if (gamemode_played == Contact) {
		printf(" Zeilen: >=6				(normal: %u) \n", 10+(number_of_players-2));
		m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

		if (m<6){
			printf("	You missed the assertion(s) !!! \n");
			printf("\n");
			m = 10+(number_of_players-2) +2;
		} else {
			m += 2;
		}
	} else if (gamemode_played == Fall) {
		printf(" Zeilen: >=3				(normal: %u) \n", 6+2*(((number_of_players+1)/2)-1));
		m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

		if (m<3){
			printf("	You missed the assertion(s) !!! \n");
			printf("\n");
			m = 6+2*(((number_of_players+1)/2)-1) +2;
		} else {
			m += 2;
		}
	} else if (gamemode_played == Fight) {
		printf(" Zeilen: >=6				(normal: 6) \n");
		m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

		if (m<6){
			printf("	You missed the assertion(s) !!! \n");
			printf("\n");
			m = 6 +2;
		} else {
			m += 2;
		}
	} else if (gamemode_played == Hunt) {
		if (number_of_players == 2) {
			printf(" Zeilen: >=3, mod2==1				(normal: 7) \n");
			m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((m<3)||(m%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				m = 9;
			} else {
				m += 2;
			}
		} else if (number_of_players == 3) {
			printf(" Zeilen: >=3, mod2==1				(normal: 7) \n");
			m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((m<3)||(m%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				m = 9;
			} else {
				m += 2;
			}
		} else if (number_of_players == 4) {
			printf(" Zeilen: >=7, mod2==1				(normal: 11) \n");
			m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((m<7)||(m%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				m = 13;
			} else {
				m += 2;
			}
		} else if (number_of_players == 5) {
			printf(" Zeilen: >=9, mod2==1				(normal: 13) \n");
			m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((m<9)||(m%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				m = 15;
			} else {
				m += 2;
			}
		} else if (number_of_players == 6) {
			printf(" Zeilen: >=9, mod2==1				(normal: 13) \n");
			m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((m<9)||(m%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				m = 15;
			} else {
				m += 2;
			}
		} else if (number_of_players == 7) {
			printf(" Zeilen: >=9, mod2==1				(normal: 15) \n");
			m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((m<9)||(m%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				m = 17;
			} else {
				m += 2;
			}
		} else if (number_of_players == 8) {
			printf(" Zeilen: >=10, mod2==0				(normal: 16) \n");
			m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((m<9)||(m%2==1)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				m = 18;
			} else {
				m += 2;
			}
		} else if (number_of_players == 9) {
			printf(" Zeilen: >=13, mod2==1				(normal: 21) \n");
			m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((m<9)||(m%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				m = 23;
			} else {
				m += 2;
			}
		}
	} else if (gamemode_played == Race) {
		printf(" Zeilen: >=%u, mod(Number of players)==-1			(normal: %u) \n", 4*number_of_players-1, 4*number_of_players-1);
		m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

		if ((m<4*number_of_players-1)||(m%number_of_players != number_of_players-1)){
			printf("	You missed the assertion(s) !!! \n");
			printf("\n");
			m = 4*number_of_players-1 +2;
		} else {
			m += 2;
		}
	} else if (gamemode_played == Rain) {
		printf(" Zeilen: >=3				(normal: 6) \n");
		m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

		if (m<3){
			printf("	You missed the assertion(s) !!! \n");
			printf("\n");
			m = 6 +2;
		} else {
			m += 2;
		}
	} else if (gamemode_played == Arena) {
		if (number_of_players == 2) {
			printf(" Zeilen: >=3, mod2==1				(normal: 7) \n");
			m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((m<3)||(m%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				m = 9;
			} else {
				m += 2;
			}
		} else if (number_of_players == 3) {
			printf(" Zeilen: >=7, mod2==1				(normal: 7) \n");
			m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((m<7)||(m%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				m = 9;
			} else {
				m += 2;
			}
		} else if (number_of_players == 4) {
			printf(" Zeilen: >=9, mod2==1				(normal: 9) \n");
			m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((m<9)||(m%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				m = 11;
			} else {
				m += 2;
			}
		} else if (number_of_players == 5) {
			printf(" Zeilen: >=8, mod2==0				(normal: 10) \n");
			m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((m<8)||(m%2==1)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				m = 12;
			} else {
				m += 2;
			}
		} else if (number_of_players == 6) {
			printf(" Zeilen: >=7, mod2==1				(normal: 11) \n");
			m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((m<7)||(m%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				m = 13;
			} else {
				m += 2;
			}
		} else if (number_of_players == 7) {
			printf(" Zeilen: >=8, mod2==0				(normal: 12) \n");
			m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((m<4)||(m%2==1)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				m = 14;
			} else {
				m += 2;
			}
		} else if (number_of_players == 8) {
			printf(" Zeilen: >=12, mod2==0				(normal: 14) \n");
			m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((m<12)||(m%2==1)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				m = 16;
			} else {
				m += 2;
			}
		} else if (number_of_players == 9) {
			printf(" Zeilen: >=12, mod2==0				(normal: 14) \n");
			m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((m<12)||(m%2==1)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				m = 16;
			} else {
				m += 2;
			}
		}
	} else if (gamemode_played == Ulcer) {
		if (number_of_players == 2) {
			printf(" Zeilen: >=6				(normal: 6) \n");
			m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if (m<6){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				m = 8;
			} else {
				m += 2;
			}
		} else if (number_of_players == 3) {
			printf(" Zeilen: >=7				(normal: 7) \n");
			m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if (m<7){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				m = 9;
			} else {
				m += 2;
			}
		} else if (number_of_players == 4) {
			printf(" Zeilen: >=9				(normal: 9) \n");
			m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if (m<9){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				m = 11;
			} else {
				m += 2;
			}
		} else if (number_of_players == 5) {
			printf(" Zeilen: >=10				(normal: 10) \n");
			m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if (m<10){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				m = 12;
			} else {
				m += 2;
			}
		} else if (number_of_players == 6) {
			printf(" Zeilen: >=11				(normal: 11) \n");
			m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if (m<11){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				m = 13;
			} else {
				m += 2;
			}
		} else if (number_of_players == 7) {
			printf(" Zeilen: >=12				(normal: 12) \n");
			m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if (m<12){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				m = 14;
			} else {
				m += 2;
			}
		} else if (number_of_players == 8) {
			printf(" Zeilen: >=13				(normal: 13) \n");
			m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if (m<13){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				m = 15;
			} else {
				m += 2;
			}
		} else if (number_of_players == 9) {
			printf(" Zeilen: >=14				(normal: 14) \n");
			m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if (m<14){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				m = 16;
			} else {
				m += 2;
			}
		}

	} else if (gamemode_played == Dynamic) {
		if (number_of_players == 2) {
			printf(" Zeilen: >=3, mod2==1				(normal: 7) \n");
			m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((m<3)||(m%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				m = 9;
			} else {
				m += 2;
			}
		} else if (number_of_players == 3) {
			printf(" Zeilen: >=5, mod2==1				(normal: 9) \n");
			m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((m<5)||(m%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				m = 11;
			} else {
				m += 2;
			}
		} else if (number_of_players == 4) {
			printf(" Zeilen: >=7, mod2==1				(normal: 11) \n");
			m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((m<7)||(m%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				m = 13;
			} else {
				m += 2;
			}
		} else if (number_of_players == 5) {
			printf(" Zeilen: >=7, mod2==1				(normal: 11) \n");
			m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((m<7)||(m%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				m = 13;
			} else {
				m += 2;
			}
		} else if (number_of_players == 6) {
			printf(" Zeilen: >=9, mod2==1				(normal: 15) \n");
			m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((m<9)||(m%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				m = 17;
			} else {
				m += 2;
			}
		} else if (number_of_players == 7) {
			printf(" Zeilen: >=9, mod2==1				(normal: 15) \n");
			m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((m<9)||(m%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				m = 17;
			} else {
				m += 2;
			}
		} else if (number_of_players == 8) {
			printf(" Zeilen: >=9, mod2==1				(normal: 17) \n");
			m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((m<9)||(m%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				m = 19;
			} else {
				m += 2;
			}
		} else if (number_of_players == 9) {
			printf(" Zeilen: >=11, mod2==1				(normal: 17) \n");
			m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((m<11)||(m%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				m = 19;
			} else {
				m += 2;
			}
		}
	} else if (gamemode_played == Survive) {
		if (number_of_players == 1) {
			printf(" Zeilen: >=3				(normal: 10) \n");
			m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if (m<3){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				m = 12;
			} else {
				m += 2;
			}
		} else if (number_of_players == 2) {
			printf(" Zeilen: >=3				(normal: 11) \n");
			m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if (m<6){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				m = 13;
			} else {
				m += 2;
			}
		} else if (number_of_players == 3) {
			printf(" Zeilen: >=6				(normal: 12) \n");
			m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if (m<6){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				m = 14;
			} else {
				m += 2;
			}
		} else if (number_of_players == 4) {
			printf(" Zeilen: >=6				(normal: 13) \n");
			m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if (m<6){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				m = 15;
			} else {
				m += 2;
			}
		} else if (number_of_players == 5) {
			printf(" Zeilen: >=7, mod2==1				(normal: 15) \n");
			m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((m<7)||(m%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				m = 17;
			} else {
				m += 2;
			}
		} else if (number_of_players == 6) {
			printf(" Zeilen: >=9, mod2==1				(normal: 15) \n");
			m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((m<9)||(m%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				m = 17;
			} else {
				m += 2;
			}
		} else if (number_of_players == 7) {
			printf(" Zeilen: >=9, mod2==1				(normal: 17) \n");
			m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((m<9)||(m%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				m = 19;
			} else {
				m += 2;
			}
		} else if (number_of_players == 8) {
			printf(" Zeilen: >=9, mod2==1				(normal: 17) \n");
			m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((m<9)||(m%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				m = 19;
			} else {
				m += 2;
			}
		} else if (number_of_players == 9) {
			printf(" Zeilen: >=9, mod2==1				(normal: 17) \n");
			m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((m<9)||(m%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				m = 19;
			} else {
				m += 2;
			}
		}
	} else if (gamemode_played == Sand) {
		printf(" Zeilen: >=4				(normal: %u) \n", 5+number_of_players);
		m = get_unsigned_numeric_input_with_not_more_than_2_letters ();

		if (m<4){
			printf("	You missed the assertion(s) !!! \n");
			printf("\n");
			m = 5+number_of_players +2;
		} else {
			m += 2;
		}
	}

	return m;
}

unsigned int get_n (unsigned int gamemode_played, unsigned int number_of_players) {
	unsigned int n;
	n = 0;
		//n-2 >= 3*((number_of_players+1)/2)
	if (gamemode_played == Classic){
		printf(" Spalten: >=%u				(normal: %u) \n", 3*((number_of_players+1)/2), 3*((number_of_players+3)/2));
		n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

		if (n<(3*((number_of_players+1)/2))){
			printf("	You missed the assertion(s) !!! \n");
			printf("\n");
			n = 3*((number_of_players+3)/2) +2;
		} else {
			n += 2;
		}
	} else if (gamemode_played == Collect) {
		printf(" Spalten: >=%u, mod(Number of players)==3				(normal: %u) \n", 2*(number_of_players+1)+1, 4+(4*number_of_players)-1);
		n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

		if ((n<2*(number_of_players+1)+1)||((n-3)%number_of_players!=0)){
			printf("	You missed the assertion(s) !!! \n");
			printf("\n");
			n = 4+(4*number_of_players)-1 +2;
		} else {
			n += 2;
		}
	} else if (gamemode_played == Contact) {
		if (number_of_players == 2) {
			printf(" Spalten: >=%u, mod2==0				(normal: %u) \n", 8*((number_of_players+1)/2), 8*((number_of_players+2)/2));
			n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((n<8*((number_of_players+1)/2))||(n%2!=0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				n = 8*((number_of_players+2)/2) +2;
			} else {
				n += 2;
			}
		} else {
			printf(" Spalten: >=%u, mod((Number of players+1)/2)==0				(normal: %u) \n", 8*((number_of_players+1)/2), 8*((number_of_players+1)/2));
			n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((n<8*((number_of_players+1)/2))||(n%((number_of_players+1)/2)!=0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				n = 8*((number_of_players+1)/2) +2;
			} else {
				n += 2;
			}
		}
	} else if (gamemode_played == Fall) {
		printf(" Spalten: >=%u, mod2==1				(normal: %u) \n", 3*2*((number_of_players+1)/2)+1, 5*2*((number_of_players+1)/2)+1);
		n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

		if ((n<3*2*((number_of_players+1)/2)+1)||(n%2==0)){
			printf("	You missed the assertion(s) !!! \n");
			printf("\n");
			n = 5*2*((number_of_players+1)/2)+1 +2;
		} else {
			n += 2;
		}
	} else if (gamemode_played == Fight) {
		printf(" Spalten: >=%u,			(normal: %u) \n", 4+4*((number_of_players+1-2)/2), 6+4*((number_of_players+1-2)/2));
		n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

		if (n<4+4*((number_of_players+1-2)/2)){
			printf("	You missed the assertion(s) !!! \n");
			printf("\n");
			n = 6+4*((number_of_players+1-2)/2) +2;
		} else {
			n += 2;
		}
	} else if (gamemode_played == Hunt) {
		if (number_of_players == 2) {
			printf(" Spalten: >=7, mod2==1				(normal: 9) \n");
			n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((n<7)||(n%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				n = 11;
			} else {
				n += 2;
			}
		} else if (number_of_players == 3) {
			printf(" Spalten: >=9, mod2==1				(normal: 13) \n");
			n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((n<9)||(n%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				n = 15;
			} else {
				n += 2;
			}
		} else if (number_of_players == 4) {
			printf(" Spalten: >=9, mod2==1				(normal: 13) \n");
			n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((n<9)||(n%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				n = 15;
			} else {
				n += 2;
			}
		} else if (number_of_players == 5) {
			printf(" Spalten: >=9, mod2==1				(normal: 13) \n");
			n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((n<9)||(n%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				n = 15;
			} else {
				n += 2;
			}
		} else if (number_of_players == 6) {
			printf(" Spalten: >=10, mod2==0				(normal: 16) \n");
			n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((n<10)||(n%2==1)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				n = 18;
			} else {
				n += 2;
			}
		} else if (number_of_players == 7) {
			printf(" Spalten: >=13, mod2==1				(normal: 19) \n");
			n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((n<13)||(n%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				n = 21;
			} else {
				n += 2;
			}
		} else if (number_of_players == 8) {
			printf(" Spalten: >=13, mod2==1				(normal: 21) \n");
			n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((n<13)||(n%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				n = 23;
			} else {
				n += 2;
			}
		} else if (number_of_players == 9) {
			printf(" Spalten: >=13, mod2==1				(normal: 21) \n");
			n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((n<13)||(n%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				n = 23;
			} else {
				n += 2;
			}
		}
	} else if (gamemode_played == Race) {
		printf(" Spalten: >=5				(normal: 19) \n");
		n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

		if (n<5) {
			printf("	You missed the assertion(s) !!! \n");
			printf("\n");
			n = 19 +2;
		} else {
			n += 2;
		}
	} else if (gamemode_played == Arena) {
		if (number_of_players == 2) {
			printf(" Spalten: >=7, mod2==1				(normal: 7) \n");
			n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((n<7)||(n%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				n = 9;
			} else {
				n += 2;
			}
		} else if (number_of_players == 3) {
			printf(" Spalten: >=7, mod2==1				(normal: 7) \n");
			n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((n<7)||(n%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				n = 9;
			} else {
				n += 2;
			}
		} else if (number_of_players == 4) {
			printf(" Spalten: >=9, mod2==1				(normal: 9) \n");
			n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((n<9)||(n%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				n = 11;
			} else {
				n += 2;
			}
		} else if (number_of_players == 5) {
			printf(" Spalten: >=8, mod2==0				(normal: 10) \n");
			n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((n<8)||(n%2==1)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				n = 12;
			} else {
				n += 2;
			}
		} else if (number_of_players == 6) {
			printf(" Spalten: >=13, mod2==1				(normal: 11) \n");
			n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((n<13)||(n%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				n = 13;
			} else {
				n += 2;
			}
		} else if (number_of_players == 7) {
			printf(" Spalten: >=12, mod2==0				(normal: 12) \n");
			n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((n<12)||(n%2==1)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				n = 14;
			} else {
				n += 2;
			}
		} else if (number_of_players == 8) {
			printf(" Spalten: >=12, mod2==0				(normal: 14) \n");
			n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((n<12)||(n%2==1)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				n = 16;
			} else {
				n += 2;
			}
		} else if (number_of_players == 9) {
			printf(" Spalten: >=12, mod2==0				(normal: 14) \n");
			n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((n<12)||(n%2==1)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				n = 16;
			} else {
				n += 2;
			}
		}
	} else if (gamemode_played == Ulcer) {
		if (number_of_players == 2) {
			printf(" Spalten: >=6				(normal: 6) \n");
			n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if (n<6){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				n = 8;
			} else {
				n += 2;
			}
		} else if (number_of_players == 3) {
			printf(" Spalten: >=7				(normal: 7) \n");
			n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if (n<7){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				n = 9;
			} else {
				n += 2;
			}
		} else if (number_of_players == 4) {
			printf(" Spalten: >=9				(normal: 9) \n");
			n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if (n<9){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				n = 11;
			} else {
				n += 2;
			}
		} else if (number_of_players == 5) {
			printf(" Spalten: >=10				(normal: 10) \n");
			n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if (n<10){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				n = 12;
			} else {
				n += 2;
			}
		} else if (number_of_players == 6) {
			printf(" Spalten: >=11				(normal: 11) \n");
			n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if (n<11){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				n = 13;
			} else {
				n += 2;
			}
		} else if (number_of_players == 7) {
			printf(" Spalten: >=12				(normal: 12) \n");
			n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if (n<12){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				n = 14;
			} else {
				n += 2;
			}
		} else if (number_of_players == 8) {
			printf(" Spalten: >=13				(normal: 13) \n");
			n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if (n<13){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				n = 15;
			} else {
				n += 2;
			}
		} else if (number_of_players == 9) {
			printf(" Spalten: >=14				(normal: 14) \n");
			n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if (n<14){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				n = 16;
			} else {
				n += 2;
			}
		}

	} else if (gamemode_played == Dynamic) {
		if (number_of_players == 2) {
			printf(" Spalten: >=7, mod2==1				(normal: 11) \n");
			n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((n<7)||(n%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				n = 11;
			} else {
				n += 2;
			}
		} else if (number_of_players == 3) {
			printf(" Spalten: >=7, mod2==1				(normal: 11) \n");
			n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((n<7)||(n%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				n = 13;
			} else {
				n += 2;
			}
		} else if (number_of_players == 4) {
			printf(" Spalten: >=7, mod2==1				(normal: 11) \n");
			n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((n<7)||(n%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				n = 13;
			} else {
				n += 2;
			}
		} else if (number_of_players == 5) {
			printf(" Spalten: >=7, mod2==1				(normal: 15) \n");
			n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((n<7)||(n%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				n = 17;
			} else {
				n += 2;
			}
		} else if (number_of_players == 6) {
			printf(" Spalten: >=9, mod2==1				(normal: 15) \n");
			n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((n<9)||(n%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				n = 17;
			} else {
				n += 2;
			}
		} else if (number_of_players == 7) {
			printf(" Spalten: >=9, mod2==1				(normal: 15) \n");
			n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((n<9)||(n%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				n = 17;
			} else {
				n += 2;
			}
		} else if (number_of_players == 8) {
			printf(" Spalten: >=9, mod2==1				(normal: 17) \n");
			n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((n<9)||(n%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				n = 19;
			} else {
				n += 2;
			}
		} else if (number_of_players == 9) {
			printf(" Spalten: >=11, mod2==1				(normal: 17) \n");
			n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((n<11)||(n%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				n = 19;
			} else {
				n += 2;
			}
		}
	} else if (gamemode_played == Survive) {
		if (number_of_players == 1) {
			printf(" Spalten: >=3				(normal: 10) \n");
			n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if (n<3){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				n = 12;
			} else {
				n += 2;
			}
		} else if (number_of_players == 2) {
			printf(" Spalten: >=6				(normal: 11) \n");
			n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if (n<6){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				n = 13;
			} else {
				n += 2;
			}
		} else if (number_of_players == 3) {
			printf(" Spalten: >=6				(normal: 12) \n");
			n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if (n<6){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				n = 14;
			} else {
				n += 2;
			}
		} else if (number_of_players == 4) {
			printf(" Spalten: >=6				(normal: 13) \n");
			n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if (n<6){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				n = 15;
			} else {
				n += 2;
			}
		} else if (number_of_players == 5) {
			printf(" Spalten: >=7, mod2==1				(normal: 15) \n");
			n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((n<7)||(n%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				n = 17;
			} else {
				n += 2;
			}
		} else if (number_of_players == 6) {
			printf(" Spalten: >=6				(normal: 15) \n");
			n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if (n<6){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				n = 17;
			} else {
				n += 2;
			}
		} else if (number_of_players == 7) {
			printf(" Spalten: >=9, mod2==1				(normal: 17) \n");
			n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((n<9)||(n%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				n = 19;
			} else {
				n += 2;
			}
		} else if (number_of_players == 8) {
			printf(" Spalten: >=9, mod2==1				(normal: 17) \n");
			n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((n<9)||(n%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				n = 19;
			} else {
				n += 2;
			}
		} else if (number_of_players == 9) {
			printf(" Spalten: >=9, mod2==1				(normal: 17) \n");
			n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if ((n<9)||(n%2==0)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				n = 19;
			} else {
				n += 2;
			}
		}
	} else if (gamemode_played == Sand) {
		if (number_of_players == 1) {
			printf(" Spalten: >=3				(normal: 4) \n");
			n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if (n<3){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				n = 6;
			} else {
				n += 2;
			}
		} else {
			printf(" Spalten: >=%u				(normal: %u) \n", 3+4*(number_of_players-1), 3+4*(number_of_players-1));
			n = get_unsigned_numeric_input_with_not_more_than_2_letters ();

			if (n<3+4*(number_of_players-1)){
				printf("	You missed the assertion(s) !!! \n");
				printf("\n");
				n = 5+4*(number_of_players-1);
			} else {
				n += 2;
			}
		}
	}

	return n;
}

unsigned int get_unsigned_numeric_input_with_not_more_than_3_letters () {
	char input[3];
	unsigned int parameter;
	int atoi_saver;

	atoi_saver = 0;
	parameter = 0;

	scanf("%3s", input);

	if (isdigit(*input) == 0) {
		printf("	You should give me natural numbers, this will be count as a 0. \n");
	} else {

		atoi_saver = abs(atoi(input));

		if (atoi_saver != 0) {
			for (int q=1; q<=atoi_saver; q+=1) {
				parameter += 1;
			}
		}
	}
	printf("\n");

	return parameter;	//returning 0 if there is made a mistake
}

unsigned int get_unsigned_numeric_input_with_not_more_than_letters_4_for_splitting () {
	char input[4];
	unsigned int parameter;
	int atoi_saver;

	atoi_saver = 0;
	parameter = 0;

	scanf("%4s", input);

	if (isdigit(*input) == 0) {
		printf("	You should give me natural numbers, this will be count as a 0. \n");
	} else {

		atoi_saver = abs(atoi(input));

		if (atoi_saver != 0) {
			for (int q=1; q<=atoi_saver; q+=1) {
				parameter += 1;
			}
		}
	}
	printf("\n");

	return parameter;	//returning 0 if there is made a mistake
}

unsigned int get_unsigned_numeric_input_with_not_more_than_2_letters () {
	char input[2];
	unsigned int parameter;
	int atoi_saver;

	atoi_saver = 0;
	parameter = 0;

	scanf("%2s", input);

	if (isdigit(*input) == 0) {
		printf("	You should give me natural numbers, this will be count as a 0. \n");
	} else {

		// printf("atoi(input): %d \n", atoi(input));	//test
		// printf("abs(atoi(input)): %d \n", abs(atoi(input)));	//test

		atoi_saver = abs(atoi(input));

		// printf("atoi_saver: %d \n", atoi_saver);	//test

		if (atoi_saver != 0) {
			for (int q=1; q<=atoi_saver; q+=1) {

				parameter += 1;

				// printf("parameter: %u  q: %d \n \n", parameter, q);	//test

			}
		}

		// printf("parameter: %u \n", parameter);	//test

	}
	printf("\n");

	return parameter;	//returning 0 if there is made a mistake
}

unsigned int split_unsigned_numeric_input_with_letters_4 (unsigned int letters_4, unsigned int which_part) {	//which_part=0 => first, which_part=1 => second.
	unsigned int parameter;
	parameter = 0;

	if (which_part == 0) {
		parameter = letters_4/100;
	} else if (which_part == 1) {
		parameter = letters_4%100;
	}

	return parameter;
}

unsigned int split_unsigned_numeric_input_with_letters_2 (unsigned int letters_2, unsigned int which_part) {	//which_part=0 => first, which_part=1 => second.
	unsigned int parameter;
	parameter = 0;

	if (which_part == 0) {
		parameter = letters_2/10;
	} else if (which_part == 1) {
		parameter = letters_2%10;
	}

	return parameter;
}

unsigned int get_unsigned_numeric_input_with_not_more_than_letters_2_for_splitting () {
	char input[2];
	unsigned int parameter;
	int atoi_saver;

	atoi_saver = 0;
	parameter = 0;

	scanf("%2s", input);

	if (isdigit(*input) == 0) {
		printf("	You should give me natural numbers, this will be count as a 0. \n");
	} else {

		atoi_saver = abs(atoi(input));

		if (atoi_saver != 0) {
			for (int q=1; q<=atoi_saver; q+=1) {
				parameter += 1;
			}
		}
	}
	printf("\n");

	return parameter;	//returning 0 if there is made a mistake
}

unsigned int get_unsigned_numeric_input_with_not_more_than_1_letter () {
	char input[1];
	unsigned int parameter;
	int atoi_saver;

	atoi_saver = 0;
	parameter = 0;

	scanf("%1s", input);

	if (isdigit(*input) == 0) {
		printf("	You should give me natural numbers, this will be count as a 0. \n");
	} else {

		atoi_saver = abs(atoi(input));

		if (atoi_saver != 0) {
			for (int q=1; q<=atoi_saver; q+=1) {
				parameter += 1;
			}
		}
	}
	printf("\n");

	return parameter;	//returning 0 if there is made a mistake
}

int get_signed_numeric_input_with_not_more_than_1_letter () {
	char input[1];
	int parameter;

	parameter = 0;

	scanf("%1s", input);

	if (isdigit(*input) == 0) {
		printf("	You should give me natural numbers with a sign, this will be count as a 0. \n");
	} else {
		parameter = atoi (input);
	}
	printf("\n");

	return parameter;
}

void choose_your_ability (unsigned int number_of_players, unsigned int* ability, Growth_Player* Growth_players, unsigned int geben) {

	unsigned int input;
	input = 0;

	for (unsigned int p=1; p<=number_of_players; p+=1) {
		printf(" \n");
		printf(" \n");
		while ((input == 0)||(input > 9)||((ability[input] != 0)&&(ability[input] != p))) {
			if (Growth_players[0].color == 1) {
				Square_color_interpretation (Growth_players, geben, number_of_players, p);
			}
			printf("	Spieler %u, please choose your ability:	\n", p);
			if (Growth_players[0].color == 1) {
				set_terminal_color (cNORMAL);
			}
			printf(" \n");
			if (ability[1] == 0) {
				printf("	Ultra light: 1 \n");
			}
			if (ability[2] == 0) {
				printf("	Light    : 2 \n");
			}
			if (ability[3] == 0) {
				printf("	Anti     : 3 \n");
			}
			if (ability[4] == 0) {
				printf("	Cornered   : 4 \n");
			}
			if (ability[5] == 0) {
				printf("	Inhibitor  : 5 \n");
			}
			if (ability[6] == 0) {
				printf("	Shield     : 6 \n");
			}
			if (ability[7] == 0) {
				printf("	Poisoning  : 7 \n");
			}
			if (ability[8] == 0) {
				printf("	Pressure   : 8 \n");
			}
			if (ability[9] == 0) {
				printf("	Electric   : 9 \n");
			}

			input = get_unsigned_numeric_input_with_not_more_than_1_letter ();

			if ((ability[input] == 0)&&(input != 0)&&(input <= 9)) {
				ability[input] = p;
				if ((input <= 4)||(input == 6)) {
					ability[0] += 1;
				}
			}
			printf(" \n");
			printf(" \n");
		}
	}
}

void unsigned_int_array_null_initialisierung (unsigned int* array, unsigned int bueyuekluek) {
	for (unsigned int p=0; p<=bueyuekluek; p++) {
		array[p] = 0;
	}
}

void int_array_null_initialisierung (int* array, unsigned int bueyuekluek) {
	for (unsigned int p=0; p<=bueyuekluek; p++) {
		array[p] = 0;
	}
}

void get_colors (Growth_Player* Growth_players, unsigned int number_of_players, unsigned int gamemode_played, unsigned int AOP) {

	unsigned int Color_choice[13], input;
	input = 0;
	unsigned_int_array_null_initialisierung (Color_choice, 12);


	if (Growth_players[0].color == 1) {
		
		for (unsigned int p=1; p<=AOP; p++) {
			set_player_color (Growth_players, p, cNORMAL);
		}
		Growth_players[0].color = 0;
		printf("	That caused a reset of the chosen colors. \n");
	
	} else {

		printf("	This only works if the number of players is correct! \n");
		printf("	Going here again will lead to a reset of the chosen colors! \n");
		if (gamemode_played == Quidditch) {
			printf("	Your choice will be the color of your house.\n");
		}
		printf(" \n");

		for (unsigned int p=1; p<=number_of_players; ++p) {
			Growth_Player* current_player = &Growth_players[p];
			unsigned int curr_id = current_player->id;

			if (curr_id != p) {
				puts("BOESER FEHLER");
			}

			if (input != 14) {
				printf("	Choose your color, Spieler %u . \n", curr_id);
			}

			while ((input == 0)||(input > 14)||((Color_choice[input-1] != 0)&&(Color_choice[input-1] != curr_id))) {		//pere[] wird zweckentfremdet, da hier noch nicht in Gebrauch, und jetzt ausgetauscht durch Color_choice
				printf(" \n");
				if (gamemode_played != Quidditch) {
					if (Color_choice[0] == 0) {
						set_terminal_color(cWHITE);
						printf("	1) white. \n");
					}
					if (Color_choice[1] == 0) {
						set_terminal_color(cLIGHT_GRAY);
						printf("	2) lightgrey. \n");
					}
					if (Color_choice[2] == 0) {
						set_terminal_color(cGRAY);
						printf("	3) darkgrey. \n");
					}
				}
				
				if (Color_choice[3] == 0) {
					set_terminal_color(cLIGHT_MAGENTA);
					printf("	4) lightmagenta. \n");
				}
				
				if (gamemode_played != Quidditch) {
					if (Color_choice[4] == 0) {
						set_terminal_color(cLIGHT_RED);
						printf("	5) lightred. \n");
					}
					if (Color_choice[5] == 0) {
						set_terminal_color(cRED);
						printf("	6) red. \n");
					}
				}
				
				if (Color_choice[6] == 0) {
					set_terminal_color(cLIGHT_CYAN);
					printf("	7) lightcyan. \n");
				}
				
				if (gamemode_played != Quidditch) {
					if (Color_choice[7] == 0) {
						set_terminal_color(cCYAN);
						printf("	8) cyan. \n");
					}
					if (Color_choice[8] == 0) {
						set_terminal_color(cLIGHT_BLUE);
						printf("	9) lightblue. \n");
					}
					if (Color_choice[9] == 0) {
						set_terminal_color(cBLUE);
						printf("	10) blue. \n");
					}
				}
				
				if (Color_choice[10] == 0) {
					set_terminal_color(cYELLOW);
					printf("	11) yellow. \n");
				}
				if (Color_choice[11] == 0) {
					set_terminal_color(cLIGHT_GREEN);
					printf("	12) lightgreen. \n");
				}
				
				if (gamemode_played != Quidditch) {
					if (Color_choice[12] == 0) {
						set_terminal_color(cGREEN);
						printf("	13) green. \n");
					}
				}
				set_terminal_color(cNORMAL);	//normal, maybe calling a normal color (done).

				printf(" \n");
				printf(" \n");
				printf("	Back: 14 \n");
				printf(" \n");
				input = get_unsigned_numeric_input_with_not_more_than_2_letters ();
				
				if (gamemode_played == Quidditch) {	//because the forbidden colors aren't house-colors
					if ((input != 4)&&(input != 7)&&(input != 11)&&(input != 12)) {
						input = 0;
					}
				}
				if ((input != 0)&&(input <= 13)&&(Color_choice[input-1] == 0)) {
					current_player->color = input;
					if (input == cWHITE) {
						set_player_color (Growth_players, curr_id, cWHITE);
					} else if (input == cLIGHT_GRAY) {
						set_player_color (Growth_players, curr_id, cLIGHT_GRAY);
					} else if (input == cGRAY) {
						set_player_color (Growth_players, curr_id, cGRAY);
					} else if (input == cLIGHT_MAGENTA) {
						set_player_color (Growth_players, curr_id, cLIGHT_MAGENTA);
					} else if (input == cLIGHT_RED) {
						set_player_color (Growth_players, curr_id, cLIGHT_RED);
					} else if (input == cRED) {
						set_player_color (Growth_players, curr_id, cRED);
					} else if (input == cLIGHT_CYAN) {
						set_player_color (Growth_players, curr_id, cLIGHT_CYAN);
					} else if (input == cCYAN) {
						set_player_color (Growth_players, curr_id, cCYAN);
					} else if (input == cLIGHT_BLUE) {
						set_player_color (Growth_players, curr_id, cLIGHT_BLUE);
					} else if (input == cBLUE) {
						set_player_color (Growth_players, curr_id, cBLUE);
					} else if (input == cYELLOW) {
						set_player_color (Growth_players, curr_id, cYELLOW);
					} else if (input == cLIGHT_GREEN) {
						set_player_color (Growth_players, curr_id, cLIGHT_GREEN);
					} else if (input == cGREEN) {
						set_player_color (Growth_players, curr_id, cGREEN);
					}
					Color_choice[input-1] = p;
				}
			}
		}
		Growth_players[0].color = 1;
	}
	unsigned_int_array_null_initialisierung (Color_choice, 12);
}

void dynamic_take_out (unsigned int* position, unsigned int number_of_players, Spielfeld Field, unsigned int* ges, Realize_modifications_variables* rmv, unsigned int m, unsigned int n, Spielfeld Opague_o_field, Special_Fields Allocation_o, unsigned int geben, unsigned int gamemode_played) {

	if (position[Horizontal] == 1) {	//links
		if ((number_of_players == 2)||(number_of_players == 3)||(number_of_players == 4)||(number_of_players == 5)) {
			for (unsigned int i=1; i<m-1; i+=1) {
				for (unsigned int j=1; j<n-1; j+=1) {
					if (Field[0][i][j] == 1) {
						set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, i, j, 0);
					}
				}
			}
			out_in_dynamic_take_out (ges, rmv, 1);
		} else if (number_of_players == 6) {
			for (unsigned int i=1; i<m-1; i+=1) {
				for (unsigned int j=1; j<n-1; j+=1) {
					if ((Field[0][i][j] == 1)||(Field[0][i][j] == 4)) {
						set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, i, j, 0);
					}
				}
			}
			out_in_dynamic_take_out (ges, rmv, 1);
			out_in_dynamic_take_out (ges, rmv, 4);
		} else if ((number_of_players == 7)||(number_of_players == 8)) {
			for (unsigned int i=1; i<m-1; i+=1) {
				for (unsigned int j=1; j<n-1; j+=1) {
					if ((Field[0][i][j] == 1)||(Field[0][i][j] == 5)) {
						set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, i, j, 0);
					}
				}
			}
			out_in_dynamic_take_out (ges, rmv, 1);
			out_in_dynamic_take_out (ges, rmv, 5);
		} else if (number_of_players == 9) {
			for (unsigned int i=1; i<m-1; i+=1) {
				for (unsigned int j=1; j<n-1; j+=1) {
					if ((Field[0][i][j] == 1)||(Field[0][i][j] == 4)||(Field[0][i][j] == 7)) {
						set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, i, j, 0);
					}
				}
			}
			out_in_dynamic_take_out (ges, rmv, 1);
			out_in_dynamic_take_out (ges, rmv, 4);
			out_in_dynamic_take_out (ges, rmv, 7);
		}

	} else if (position[Vertikal] == 1) {	//oben
		if ((number_of_players == 3)||(number_of_players == 4)||(number_of_players == 5)||(number_of_players == 7)) {
			for (unsigned int i=1; i<m-1; i+=1) {
				for (unsigned int j=1; j<n-1; j+=1) {
					if (Field[0][i][j] == 2) {
						set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, i, j, 0);
					}
				}
			}

			out_in_dynamic_take_out (ges, rmv, 2);
		} else if (number_of_players == 6) {
			for (unsigned int i=1; i<m-1; i+=1) {
				for (unsigned int j=1; j<n-1; j+=1) {
					if ((Field[0][i][j] == 2)||(Field[0][i][j] == 5)) {
						set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, i, j, 0);
					}
				}
			}
			out_in_dynamic_take_out (ges, rmv, 2);
			out_in_dynamic_take_out (ges, rmv, 5);
		} else if (number_of_players == 8) {
			for (unsigned int i=1; i<m-1; i+=1) {
				for (unsigned int j=1; j<n-1; j+=1) {
					if ((Field[0][i][j] == 2)||(Field[0][i][j] == 6)) {
						set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, i, j, 0);
					}
				}
			}
			out_in_dynamic_take_out (ges, rmv, 2);
			out_in_dynamic_take_out (ges, rmv, 6);
		} else if (number_of_players == 9) {
			for (unsigned int i=1; i<m-1; i+=1) {
				for (unsigned int j=1; j<n-1; j+=1) {
					if ((Field[0][i][j] == 2)||(Field[0][i][j] == 5)||(Field[0][i][j] == 8)) {
						set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, i, j, 0);
					}
				}
			}
			out_in_dynamic_take_out (ges, rmv, 2);
			out_in_dynamic_take_out (ges, rmv, 5);
			out_in_dynamic_take_out (ges, rmv, 8);
		}

	} else if (position[Horizontal] == n-2) {	//rechts
		if ((number_of_players == 3)||(number_of_players == 4)||(number_of_players == 5)) {
			for (unsigned int i=1; i<m-1; i+=1) {
				for (unsigned int j=1; j<n-1; j+=1) {
					if (Field[0][i][j] == 3) {
						set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, i, j, 0);
					}
				}
			}
			out_in_dynamic_take_out (ges, rmv, 3);
		} else if ((number_of_players == 6)||(number_of_players == 7)) {
			for (unsigned int i=1; i<m-1; i+=1) {
				for (unsigned int j=1; j<n-1; j+=1) {
					if ((Field[0][i][j] == 3)||(Field[0][i][j] == 6)) {
						set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, i, j, 0);
					}
				}
			}
			out_in_dynamic_take_out (ges, rmv, 3);
			out_in_dynamic_take_out (ges, rmv, 6);
		} else if (number_of_players == 8) {
			for (unsigned int i=1; i<m-1; i+=1) {
				for (unsigned int j=1; j<n-1; j+=1) {
					if ((Field[0][i][j] == 3)||(Field[0][i][j] == 7)) {
						set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, i, j, 0);
					}
				}
			}
			out_in_dynamic_take_out (ges, rmv, 3);
			out_in_dynamic_take_out (ges, rmv, 7);
		} else if (number_of_players == 2) {
			for (unsigned int i=1; i<m-1; i+=1) {
				for (unsigned int j=1; j<n-1; j+=1) {
					if (Field[0][i][j] == 2) {
						set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, i, j, 0);
					}
				}
			}
			out_in_dynamic_take_out (ges, rmv, 2);
		} else if (number_of_players == 9) {
			for (unsigned int i=1; i<m-1; i+=1) {
				for (unsigned int j=1; j<n-1; j+=1) {
					if ((Field[0][i][j] == 3)||(Field[0][i][j] == 6)||(Field[0][i][j] == 9)) {
						set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, i, j, 0);
					}
				}
			}
			out_in_dynamic_take_out (ges, rmv, 3);
			out_in_dynamic_take_out (ges, rmv, 6);
			out_in_dynamic_take_out (ges, rmv, 9);
		}

	} else if (position[Vertikal] == m-2) {		//unten
		if (number_of_players == 4) {
			for (unsigned int i=1; i<m-1; i+=1) {
				for (unsigned int j=1; j<n-1; j+=1) {
					if (Field[0][i][j] == 4) {
						set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, i, j, 0);
					}
				}
			}
			out_in_dynamic_take_out (ges, rmv, 4);
		} else if (number_of_players == 5) {
			for (unsigned int i=1; i<m-1; i+=1) {
				for (unsigned int j=1; j<n-1; j+=1) {
					if ((Field[0][i][j] == 4)||(Field[0][i][j] == 5)) {
						set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, i, j, 0);
					}
				}
			}
			out_in_dynamic_take_out (ges, rmv, 4);
			out_in_dynamic_take_out (ges, rmv, 5);
		} else if (number_of_players == 7) {
			for (unsigned int i=1; i<m-1; i+=1) {
				for (unsigned int j=1; j<n-1; j+=1) {
					if ((Field[0][i][j] == 4)||(Field[0][i][j] == 7)) {
						set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, i, j, 0);
					}
				}
			}
			out_in_dynamic_take_out (ges, rmv, 4);
			out_in_dynamic_take_out (ges, rmv, 7);
		} else if (number_of_players == 8) {
			for (unsigned int i=1; i<m-1; i+=1) {
				for (unsigned int j=1; j<n-1; j+=1) {
					if ((Field[0][i][j] == 4)||(Field[0][i][j] == 8)) {
						set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, i, j, 0);
					}
				}
			}
			out_in_dynamic_take_out (ges, rmv, 4);
			out_in_dynamic_take_out (ges, rmv, 8);
		}
	}
}

void out_in_dynamic_take_out (unsigned int* ges, Realize_modifications_variables* rmv, unsigned int player) {
	if (ges[player] != 1010*player) {
		printf("	Player %u, you are out \n", player);
		ges[player] = 1010*player;
		rmv->player_counter += 1;
	}
}

void who_is_out (unsigned int* ges, unsigned int number_of_players, Realize_modifications_variables* rmv) {

	for (unsigned int p=1; p<=number_of_players; p++) {
		if ((ges[p] == 0)&&(number_of_players >= p)) {	//second cause obviously?
			printf("		Spieler %u, you are out. \n", p);
			rmv->player_counter += 1;
			ges[p] = 1010*p;
		}
	}
	printf("\n");
}

void reset_of_ges (unsigned int* ges, unsigned int number_of_players) {
	for (unsigned int p=1; p<=number_of_players; p++) {
		if (ges[p] < p*1010) {
			ges[p] = 0;
		}
	}
}

void show_figures () {	//in order of calculation

	// if (menuoperator == 1) {
		printf("		Seed:	\n");
		printf("	OOO		O*O	\n");
		printf("	O*O	--->	*O*	\n");
		printf("	OOO		O*O	\n");
		printf("	\n\n");

	// } else if (menuoperator == 2) {
		printf("		Grass:	\n");
		printf("	OOO		O*O	\n");
		printf("	O*O		O*O	\n");
		printf("	O*O	--->	O*O	\n");
		printf("	OOO		OOO	\n");
		printf("	\n\n");

	// } else if (menuoperator == 3) {
		printf("		Windmill:	\n");
		printf("	OOOO		OOOO		OOOO	\n");
		printf("	OO*O		O*OO		OO*O	\n");
		printf("	O*OO	--->	OO*O	--->	O*OO	\n");
		printf("	OOOO		OOOO		OOOO	\n");
		printf("	\n\n");

	// } else if (menuoperator == 4) {
		printf("		Popcorn:	\n");
		printf("	OOOO		O**O	\n");
		printf("	O**O		*OO*	\n");
		printf("	O**O	--->	*OO*	\n");
		printf("	OOOO		O**O	\n");
		printf("	\n\n");

	// } else if (menuoperator == 5) {
		printf("		Shield:	\n");
		printf("	OOOOO		OOOOO	\n");
		printf("	OO*OO		OO*OO	\n");
		printf("	O*O*O	--->	**O**	\n");
		printf("	OOOOO		OOOOO	\n");
		printf("	\n\n");

	// } else if (menuoperator == 6) {
		printf("		Flower:	\n");
		printf("	OOOOO		OO*OO	\n");
		printf("	OO*OO		OO*OO	\n");
		printf("	O*O*O	--->	**O**	\n");
		printf("	OO*OO		OO*OO	\n");
		printf("	OOOOO		OO*OO	\n");
		printf("	\n\n");

	// } else if (menuoperator == 7) {
		printf("		Black hole:	\n");
		printf("	OOOOO		OOOOO	\n");
		printf("	O***O		OOOOO	\n");
		printf("	O***O	--->	OO*OO	\n");
		printf("	O***O		OOOOO	\n");
		printf("	OOOOO		OOOOO	\n");
		printf("	\n\n");

	// }
}

void figure_check (Spielfeld Field, unsigned int m, unsigned int n, unsigned int number_of_players, Growth_Player* Growth_players, Special_Fields Allocation_o, Spielfeld Opague_o_field, unsigned int geben, unsigned int gamemode_played) {
	unsigned int figure_check_counter;
	figure_check_counter = 0;

	for (unsigned int i=1; i<=m-2; i++) {
		for (unsigned int j=1; j<=n-2; j++) {
			figure_check_counter = 0;

			for (unsigned int z=0; z<=2; z++) {
				if ((j+2<=n-2)&&(i+2<=m-2)&&(Field[0][i][j+z] == 0)&&(Field[0][i+2][j+z] == 0)) {
					figure_check_counter += 2;
				}
			}
			for (unsigned int t=1; t<=1; t++) {
				if ((j+2<=n-2)&&(i+2<=m-2)&&(Field[0][i+t][j] == 0)&&(Field[0][i+t][j+2] == 0)) {
					figure_check_counter += 2;
				}
			}
			if (figure_check_counter == 8) {	//Seed
				figure_check_counter = 0;

				if ((Field[0][i+1][j+1] != 0)&&(Field[0][i+1][j+1] <= number_of_players)) {

					if (Growth_players[0].color == 1) {
				Square_color_interpretation (Growth_players, geben, number_of_players, Field[0][i+1][j+1]);
					}
					printf("	Time for a Seed \n\n");

					for (unsigned int t=0; t<=2; t++) {
						for (unsigned int z=0; z<=2; z++) {
							if ((t+z)%2 == 1) {
								set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, i+t, j+z, Field[0][i+1][j+1]);
							}
						}
					}
					set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, i+1, j+1, 0);
				}
			} else {
				figure_check_counter = 0;

				for (unsigned int z=0; z<=2; z++) {
					if ((j+2<=n-2)&&(i+3<=m-2)&&(Field[0][i][j+z] == 0)&&(Field[0][i+3][j+z] == 0)) {
						figure_check_counter += 2;
					}
				}
				for (unsigned int t=1; t<=2; t++) {
					if ((j+2<=n-2)&&(i+3<=m-2)&&(Field[0][i+t][j] == 0)&&(Field[0][i+t][j+2] == 0)) {
						figure_check_counter += 2;
					}
				}
				if (figure_check_counter == 10) {	//Grass
					figure_check_counter = 0;

					if ((Field[0][i+1][j+1] != 0)&&(Field[0][i+1][j+1] <= number_of_players)&&(Field[0][i+2][j+1] == Field[0][i+1][j+1])) {
						if (Growth_players[0].color == 1) {
				Square_color_interpretation (Growth_players, geben, number_of_players, Field[0][i+1][j+1]);
						}
						printf("	Time for Grass \n\n");

						set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, i, j+1, Field[0][i+1][j+1]);
					}
				} else {
					figure_check_counter = 0;

					for (unsigned int z=0; z<=3; z++) {
						if ((j+3<=n-2)&&(i+3<=m-2)&&(Field[0][i][j+z] == 0)&&(Field[0][i+3][j+z] == 0)) {
							figure_check_counter += 2;
						}
					}
					for (unsigned int t=1; t<=2; t++) {
						if ((j+3<=n-2)&&(i+3<=m-2)&&(Field[0][i+t][j] == 0)&&(Field[0][i+t][j+3] == 0)) {
							figure_check_counter += 2;
						}
					}
					if (figure_check_counter == 12) {
						figure_check_counter = 0;

						if ((Field[0][i+1][j+1] != 0)&&(Field[0][i+1][j+1] <= number_of_players)) {
							for (unsigned int t=1; t<=2; t++) {
								for (unsigned int z=1; z<=2; z++) {
									if (((t+z)%2 == 0)&&(Field[0][i+t][j+z] == Field[0][i+1][j+1])) {
										figure_check_counter += 1;
									} else if (((t+z)%2 == 1)&&(Field[0][i+t][j+z] == 0)) {
										figure_check_counter += 3;
									} else if (((t+z)%2 == 1)&&(Field[0][i+t][j+z] == Field[0][i+1][j+1])) {
										figure_check_counter += 9;
									}
								}
							}
							if (figure_check_counter == 8) {	//Windmill#2
								figure_check_counter = 0;

								if (Growth_players[0].color == 1) {
					Square_color_interpretation (Growth_players, geben, number_of_players, Field[0][i+1][j+1]);
								}
								printf("	Time for a Windmill \n\n");

								for (unsigned int t=2; t>=1; t--) {
									for (unsigned int z=2; z>=1; z--) {
										if ((z+t)%2 == 1) {
											set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, i+t, j+z, Field[0][i+1][j+1]);
										} else if ((z+t)%2 == 0) {
											set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, i+t, j+z, 0);
										}
									}
								}
							} else if (figure_check_counter == 20) {	//Popcorn
								figure_check_counter = 0;

								if (Growth_players[0].color == 1) {
					Square_color_interpretation (Growth_players, geben, number_of_players, Field[0][i+1][j+1]);
								}
								printf("	Time for Popcorn \n\n");

								for (unsigned int t=1; t<=2; t++) {
									set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, i+t, j, Field[0][i+1][j+1]);
									set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, i+t, j+3, Field[0][i+1][j+1]);
								}
								for (unsigned int z=1; z<=2; z++) {
									set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, i, j+z, Field[0][i+1][j+1]);
									set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, i+3, j+z, Field[0][i+1][j+1]);
								}
								for (unsigned int t=2; t>=1; t--) {
									for (unsigned int z=2; z>=1; z--) {
										set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, i+t, j+z, 0);
									}
								}
							}

						} else if (Field[0][i+1][j+1] == 0) {	//Windmill#1

							if ((Field[0][i+1][j+2] != 0)&&(Field[0][i+1][j+2] <= number_of_players)&&(Field[0][i+2][j+1] == Field[0][i+1][j+2])&&(Field[0][i+2][j+2] == 0)) {

								if (Growth_players[0].color == 1) {
					Square_color_interpretation (Growth_players, geben, number_of_players, Field[0][i+1][j+2]);
								}
								printf("	Time for a Windmill \n\n");

								for (unsigned int t=2; t>=1; t--) {
									for (unsigned int z=1; z<=2; z++) {
										if ((z+t)%2 == 0) {
											set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, i+t, j+z, Field[0][i+1][j+2]);
										} else if ((z+t)%2 == 1) {
											set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, i+t, j+z, 0);
										}
									}
								}
							}
						}

					} else {
						figure_check_counter = 0;

						for (unsigned int z=0; z<=4; z++) {
							if ((j+4<=n-2)&&(i+3<=m-2)&&(Field[0][i][j+z] == 0)&&(Field[0][i+3][j+z] == 0)) {
								figure_check_counter += 2;
							}
						}
						for (unsigned int t=1; t<=2; t++) {
							if ((j+4<=n-2)&&(i+3<=m-2)&&(Field[0][i+t][j] == 0)&&(Field[0][i+t][j+4] == 0)) {
								figure_check_counter += 2;
							}
						}
						if (figure_check_counter == 14) {
							figure_check_counter = 0;

							if ((Field[0][i+1][j+2] != 0)&&(Field[0][i+1][j+2] <= number_of_players)) {
								for (unsigned int t=1; t<=2; t++) {
									for (unsigned int z=1; z<=3; z++) {
										if (((t+z)%2 == 1)&&(Field[0][i+t][j+z] == Field[0][i+1][j+2])) {
											figure_check_counter += 1;
										} else if (((t+z)%2 == 0)&&(Field[0][i+t][j+z] == 0)) {
											figure_check_counter += 1;
										}
									}
								}
								if (figure_check_counter == 6) {	//Shield

					if (Growth_players[0].color == 1) {
						Square_color_interpretation (Growth_players, geben, number_of_players, Field[0][i+1][j+2]);
					}
									printf("	Time for a Shield \n\n");

									set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, i+2, j, Field[0][i+1][j+2]);
									set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, i+2, j+4, Field[0][i+1][j+2]);

								}
							}
						} else {
							figure_check_counter = 0;

							for (unsigned int z=0; z<=4; z++) {
								if ((j+4<=n-2)&&(i+4<=m-2)&&(Field[0][i][j+z] == 0)&&(Field[0][i+4][j+z] == 0)) {
									figure_check_counter += 2;
								}
							}
							for (unsigned int t=1; t<=3; t++) {
								if ((j+4<=n-2)&&(i+4<=m-2)&&(Field[0][i+t][j] == 0)&&(Field[0][i+t][j+4] == 0)) {
									figure_check_counter += 2;
								}
							}
							if (figure_check_counter == 16) {
								figure_check_counter = 0;

								if ((Field[0][i+1][j+2] != 0)&&(Field[0][i+1][j+2] <= number_of_players)) {
									for (unsigned int t=1; t<=3; t++) {
										for (unsigned int z=1; z<=3; z++) {
											if (((t+z)%2 == 1)&&(Field[0][i+t][j+z] == Field[0][i+1][j+2])) {
												figure_check_counter += 1;
											} else if (((t+z)%2 == 0)&&(Field[0][i+t][j+z] == 0)) {
												figure_check_counter += 1;
											} else if (((t+z)%2 == 0)&&(Field[0][i+t][j+z] == Field[0][i+1][j+2])) {
												figure_check_counter += 9;
											}
										}
									}
									if (figure_check_counter == 9) {	//Flower
										figure_check_counter = 0;

						if (Growth_players[0].color == 1) {
							Square_color_interpretation (Growth_players, geben, number_of_players, Field[0][i+1][j+2]);
						}
										printf("	Time for a Flower \n\n");

										set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, i+2, j, Field[0][i+1][j+2]);
										set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, i+2, j+4, Field[0][i+1][j+2]);
										set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, i, j+2, Field[0][i+1][j+2]);
										set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, i+4, j+2, Field[0][i+1][j+2]);

									} else if (figure_check_counter == 49) {	//Black hole

						if (Growth_players[0].color == 1) {
							Square_color_interpretation (Growth_players, geben, number_of_players, Field[0][i+1][j+1]);
						}
										printf("	Time for a Black hole \n\n");

										for (unsigned int t=1; t<=3; t++) {
											for (unsigned int z=1; z<=3; z++) {
												if ((t != 2)&&(z != 2)) {
													set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, i+t, j+z, 0);
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}

		}
	}
	
	if (Growth_players[0].color == 1) {
		set_terminal_color (cNORMAL);
	}

}

void set_Spielfeld_Eintrag (Spielfeld Field, unsigned int geben, Spielfeld Opague_o_field, unsigned int gamemode_played, Special_Fields Allocation_o, unsigned int number_of_players, Spielfeld Spiel, unsigned int first, unsigned int i, unsigned int j, unsigned int Eintrag) {

	// if ((Field[first][i][j] == 11)&&(Eintrag != 11)) {	//test
		// printf("	Fehler: Heart wird in Field nicht trivial überschrieben	i=%u	j=%u \n", i, j);
	// } else {
		// printf("	Eintrag:%u	i=%u	j=%u \n\n", Eintrag, i, j);
	// }

	// printf("set_Spielfeld_Eintrag ok.1 \n");	//test
	// if (Spiel != Field) {
		// printf("Eintrag:%u, i=%u, j=%u	", Eintrag, i, j);
		// printf("ok.1 ");	//test
	// }

	if ((Spiel == Allocation_o.field)&&(first == 1)&&(Eintrag != 0)) {	//Addieren statt ersetzen in Allocation[1], da die Summe an Abzügen gezählt werden muss, außer beim Reset (Eintrag == 0).
		Spiel[first][i][j] += Eintrag;

		// printf("set_Spielfeld_Eintrag ok.2 \n");	//test
		// printf("ok.2 \n");	//test

	} else {
		Spiel[first][i][j] = Eintrag;

		// printf("set_Spielfeld_Eintrag ok.3 \n");	//test
		// if (Spiel != Field) {
			// printf("ok.3 ");	//test
		// }
	}

	if (Allocation_o.characterization != 0) {

		// printf("set_Spielfeld_Eintrag ok.4 \n");

		if (((Eintrag != 0)&&(Eintrag <= number_of_players))||((gamemode_played == Hunt)&&(Eintrag == 11))) {
			if (Spiel == Opague_o_field) {
				if (Eintrag == geben) {
					Allocation_o.field[2][i][j] = Allocation_o.field[0][i][j];
				} else {
					Allocation_o.field[2][i][j] = 1;
				}
			} else if ((Spiel == Field)&&(first == 0)) {
				Allocation_o.field[0][i][j] = 1;
			}

			// printf("set_Spielfeld_Eintrag ok.5 \n");

		} else {	//Eintrag is not a player
			if (Spiel == Opague_o_field) {
				Allocation_o.field[2][i][j] = 0;
			} else if ((Spiel == Field)&&(first == 0)) {
				Allocation_o.field[0][i][j] = 0;
			}

			// printf("set_Spielfeld_Eintrag ok.6 \n");

		}
	}

	// if (Spiel != Field) {
		// printf("ok.7 ");	//test
	// }
}

void set_gleiter_oben_links (unsigned int single_option_representives_inverted, Spielfeld Field, unsigned int geben, unsigned int i, unsigned int j) {	//oben das Bein, oben links das Wachstum, zentral aufgetragen
	if (single_option_representives_inverted == 0) {
		Field[0][i-1][j]	= geben;
		Field[0][i-1][j+1]	= geben;
		Field[0][i][j]		= geben;
		Field[0][i][j-1]	= geben;
		Field[0][i+1][j+1]	= geben;
	} else if (single_option_representives_inverted == 1) {
		Field[0][i-1][j+1]	= geben;
		Field[0][i-1][j-1]	= geben;
		Field[0][i][j]		= geben;
		Field[0][i][j-1]	= geben;
		Field[0][i+1][j-1]	= geben;
		Field[0][i+1][j]	= geben;
	}
}

void set_gleiter_links_oben (unsigned int single_option_representives_inverted, Spielfeld Field, unsigned int geben, unsigned int i, unsigned int j) {
	if (single_option_representives_inverted == 0) {
		Field[0][i-1][j]	= geben;
		Field[0][i+1][j-1]	= geben;
		Field[0][i][j]		= geben;
		Field[0][i][j-1]	= geben;
		Field[0][i+1][j+1]	= geben;
	} else if (single_option_representives_inverted == 1) {
		Field[0][i-1][j]	= geben;
		Field[0][i-1][j+1]	= geben;
		Field[0][i-1][j-1]	= geben;
		Field[0][i][j]		= geben;
		Field[0][i][j+1]	= geben;
		Field[0][i+1][j-1]	= geben;
	}
}

void set_gleiter_oben_rechts (unsigned int single_option_representives_inverted, Spielfeld Field, unsigned int geben, unsigned int i, unsigned int j) {
	if (single_option_representives_inverted == 0) {
		Field[0][i-1][j]	= geben;
		Field[0][i-1][j-1]	= geben;
		Field[0][i][j]		= geben;
		Field[0][i][j+1]	= geben;
		Field[0][i+1][j-1]	= geben;
	} else if (single_option_representives_inverted == 1) {
		Field[0][i-1][j+1]	= geben;
		Field[0][i-1][j-1]	= geben;
		Field[0][i][j]		= geben;
		Field[0][i][j+1]	= geben;
		Field[0][i+1][j+1]	= geben;
		Field[0][i+1][j]	= geben;
	}
}

void set_gleiter_rechts_oben (unsigned int single_option_representives_inverted, Spielfeld Field, unsigned int geben, unsigned int i, unsigned int j) {
	if (single_option_representives_inverted == 0) {
		Field[0][i-1][j]	= geben;
		Field[0][i+1][j+1]	= geben;
		Field[0][i][j]		= geben;
		Field[0][i][j+1]	= geben;
		Field[0][i+1][j-1]	= geben;
	} else if (single_option_representives_inverted == 1) {
		Field[0][i-1][j]	= geben;
		Field[0][i-1][j+1]	= geben;
		Field[0][i-1][j-1]	= geben;
		Field[0][i][j]		= geben;
		Field[0][i][j-1]	= geben;
		Field[0][i+1][j+1]	= geben;
	}
}

void set_gleiter_unten_links (unsigned int single_option_representives_inverted, Spielfeld Field, unsigned int geben, unsigned int i, unsigned int j) {
	if (single_option_representives_inverted == 0) {
		Field[0][i-1][j+1]	= geben;
		Field[0][i][j-1]	= geben;
		Field[0][i][j]		= geben;
		Field[0][i+1][j]	= geben;
		Field[0][i+1][j+1]	= geben;
	} else if (single_option_representives_inverted == 1) {
		Field[0][i-1][j]	= geben;
		Field[0][i-1][j-1]	= geben;
		Field[0][i][j]		= geben;
		Field[0][i][j-1]	= geben;
		Field[0][i+1][j-1]	= geben;
		Field[0][i+1][j+1]	= geben;
	}
}

void set_gleiter_links_unten (unsigned int single_option_representives_inverted, Spielfeld Field, unsigned int geben, unsigned int i, unsigned int j) {
	if (single_option_representives_inverted == 0) {
		Field[0][i-1][j-1]	= geben;
		Field[0][i-1][j+1]	= geben;
		Field[0][i][j]		= geben;
		Field[0][i][j-1]	= geben;
		Field[0][i+1][j]	= geben;
	} else if (single_option_representives_inverted == 1) {
		Field[0][i+1][j]	= geben;
		Field[0][i+1][j+1]	= geben;
		Field[0][i+1][j-1]	= geben;
		Field[0][i][j]		= geben;
		Field[0][i][j+1]	= geben;
		Field[0][i-1][j-1]	= geben;
	}
}

void set_gleiter_unten_rechts (unsigned int single_option_representives_inverted, Spielfeld Field, unsigned int geben, unsigned int i, unsigned int j) {
	if (single_option_representives_inverted == 0) {
		Field[0][i-1][j-1]	= geben;
		Field[0][i][j+1]	= geben;
		Field[0][i][j]		= geben;
		Field[0][i+1][j-1]	= geben;
		Field[0][i+1][j]	= geben;
	} else if (single_option_representives_inverted == 1) {
		Field[0][i-1][j]	= geben;
		Field[0][i-1][j+1]	= geben;
		Field[0][i][j]		= geben;
		Field[0][i][j+1]	= geben;
		Field[0][i+1][j-1]	= geben;
		Field[0][i+1][j+1]	= geben;
	}
}

void set_gleiter_rechts_unten (unsigned int single_option_representives_inverted, Spielfeld Field, unsigned int geben, unsigned int i, unsigned int j) {
	if (single_option_representives_inverted == 0) {
		Field[0][i-1][j-1]	= geben;
		Field[0][i][j+1]	= geben;
		Field[0][i][j]		= geben;
		Field[0][i-1][j+1]	= geben;
		Field[0][i+1][j]	= geben;
	} else if (single_option_representives_inverted == 1) {
		Field[0][i+1][j]	= geben;
		Field[0][i+1][j+1]	= geben;
		Field[0][i+1][j-1]	= geben;
		Field[0][i][j]		= geben;
		Field[0][i][j-1]	= geben;
		Field[0][i-1][j+1]	= geben;
	}
}

void set_triangle_oben_links (unsigned int single_option_representives_inverted, Spielfeld Field, unsigned int geben, unsigned int i, unsigned int j) {	//platziert beim Wachstum, in der angegebenen Ecke
	if ((single_option_representives_inverted == 0)||(single_option_representives_inverted == 1)) {
		Field[0][i][j+1] = geben;
		Field[0][i+1][j] = geben;
		Field[0][i+1][j+1] = geben;
	}
}

void set_triangle_oben_rechts (unsigned int single_option_representives_inverted, Spielfeld Field, unsigned int geben, unsigned int i, unsigned int j) {	//platziert beim Wachstum, in der angegebenen Ecke
	if ((single_option_representives_inverted == 0)||(single_option_representives_inverted == 1)) {
		Field[0][i][j-1] = geben;
		Field[0][i+1][j] = geben;
		Field[0][i+1][j-1] = geben;
	}
}

void set_triangle_unten_rechts (unsigned int single_option_representives_inverted, Spielfeld Field, unsigned int geben, unsigned int i, unsigned int j) {	//platziert beim Wachstum, in der angegebenen Ecke
	if ((single_option_representives_inverted == 0)||(single_option_representives_inverted == 1)) {
		Field[0][i-1][j-1] = geben;
		Field[0][i-1][j] = geben;
		Field[0][i][j-1] = geben;
	}
}

void set_triangle_unten_links (unsigned int single_option_representives_inverted, Spielfeld Field, unsigned int geben, unsigned int i, unsigned int j) {	//platziert beim Wachstum, in der angegebenen Ecke
	if ((single_option_representives_inverted == 0)||(single_option_representives_inverted == 1)) {
		Field[0][i-1][j] = geben;
		Field[0][i-1][j+1] = geben;
		Field[0][i][j+1] = geben;
	}
}

void set_mountain_oben (unsigned int single_option_representives_inverted, Spielfeld Field, unsigned int geben, unsigned int i, unsigned int j) {	//platziert beim Schwerpunkt
	if (single_option_representives_inverted == 0) {
		Field[0][i][j]   = geben;
		Field[0][i-1][j] = geben;
		Field[0][i][j-1] = geben;
		Field[0][i][j+1] = geben;
	} else if (single_option_representives_inverted == 1) {
		Field[0][i][j]		= geben;
		Field[0][i][j-1]	= geben;
		Field[0][i][j+1]	= geben;
		Field[0][i+2][j-1]	= geben;
		Field[0][i+2][j+1]	= geben;
	}
}

void set_mountain_unten (unsigned int single_option_representives_inverted, Spielfeld Field, unsigned int geben, unsigned int i, unsigned int j) {	//platziert beim Schwerpunkt
	if (single_option_representives_inverted == 0) {
		Field[0][i][j] = geben;
		Field[0][i+1][j] = geben;
		Field[0][i][j-1] = geben;
		Field[0][i][j+1] = geben;
	} else if (single_option_representives_inverted == 1) {
		Field[0][i][j]		= geben;
		Field[0][i][j-1]	= geben;
		Field[0][i][j+1]	= geben;
		Field[0][i-2][j-1]	= geben;
		Field[0][i-2][j+1]	= geben;
	}
}

void set_mountain_rechts (unsigned int single_option_representives_inverted, Spielfeld Field, unsigned int geben, unsigned int i, unsigned int j) {	//platziert beim Schwerpunkt
	if (single_option_representives_inverted == 0) {
		Field[0][i][j] = geben;
		Field[0][i][j+1] = geben;
		Field[0][i-1][j] = geben;
		Field[0][i+1][j] = geben;
	} else if (single_option_representives_inverted == 1) {
		Field[0][i][j] = geben;
		Field[0][i-1][j] = geben;
		Field[0][i+1][j] = geben;
		Field[0][i-1][j-2] = geben;
		Field[0][i+1][j-2] = geben;
	}
}

void set_mountain_links (unsigned int single_option_representives_inverted, Spielfeld Field, unsigned int geben, unsigned int i, unsigned int j) {	//platziert beim Schwerpunkt
	if (single_option_representives_inverted == 0) {
		Field[0][i][j] = geben;
		Field[0][i][j-1] = geben;
		Field[0][i-1][j] = geben;
		Field[0][i+1][j] = geben;
	} else if (single_option_representives_inverted == 1) {
		Field[0][i][j] = geben;
		Field[0][i-1][j] = geben;
		Field[0][i+1][j] = geben;
		Field[0][i-1][j+2] = geben;
		Field[0][i+1][j+2] = geben;
	}
}

void set_edge_oben_links (unsigned int single_option_representives_inverted, Spielfeld Field, unsigned int geben, unsigned int i, unsigned int j) {	//platziert beim Schweif
	if ((single_option_representives_inverted == 0)||(single_option_representives_inverted == 1)) {
		Field[0][i][j] = geben;
		Field[0][i+2][j] = geben;
		Field[0][i+2][j+1] = geben;
		Field[0][i+2][j+2] = geben;
		Field[0][i][j+2] = geben;
		Field[0][i+1][j+2] = geben;
	}
}

void set_edge_oben_rechts (unsigned int single_option_representives_inverted, Spielfeld Field, unsigned int geben, unsigned int i, unsigned int j) {	//platziert beim Schweif
	if ((single_option_representives_inverted == 0)||(single_option_representives_inverted == 1)) {
		Field[0][i][j] = geben;
		Field[0][i+2][j] = geben;
		Field[0][i+2][j-1] = geben;
		Field[0][i+2][j-2] = geben;
		Field[0][i][j-2] = geben;
		Field[0][i+1][j-2] = geben;
	}
}

void set_edge_unten_rechts (unsigned int single_option_representives_inverted, Spielfeld Field, unsigned int geben, unsigned int i, unsigned int j) {	//platziert beim Schweif
	if ((single_option_representives_inverted == 0)||(single_option_representives_inverted == 1)) {
		Field[0][i][j] = geben;
		Field[0][i-2][j] = geben;
		Field[0][i-2][j-1] = geben;
		Field[0][i-2][j-2] = geben;
		Field[0][i][j-2] = geben;
		Field[0][i-1][j-2] = geben;
	}
}

void set_edge_unten_links (unsigned int single_option_representives_inverted, Spielfeld Field, unsigned int geben, unsigned int i, unsigned int j) {	//platziert beim Schweif
	if ((single_option_representives_inverted == 0)||(single_option_representives_inverted == 1)) {
		Field[0][i][j] = geben;
		Field[0][i-2][j] = geben;
		Field[0][i-2][j+1] = geben;
		Field[0][i-2][j+2] = geben;
		Field[0][i][j+2] = geben;
		Field[0][i-1][j+2] = geben;
	}
}

void set_star (unsigned int single_option_representives_inverted, Spielfeld Field, unsigned int geben, unsigned int i, unsigned int j) {	//platziert im Zentrum
	if (single_option_representives_inverted == 0) {
		Field[0][i][j] = geben;
		Field[0][i-1][j] = geben;
		Field[0][i][j+1] = geben;
		Field[0][i][j-1] = geben;
		Field[0][i+1][j] = geben;
	} else if (single_option_representives_inverted == 1) {
		Field[0][i][j] = geben;
		Field[0][i-1][j-1] = geben;
		Field[0][i-1][j+1] = geben;
		Field[0][i+1][j-1] = geben;
		Field[0][i+1][j+1] = geben;
	}
}

void set_net_basic_two_four (unsigned int single_option_representives_inverted, Spielfeld Field, unsigned int geben, unsigned int i, unsigned int j) {	//platziert im Zentrum oben links
	if ((single_option_representives_inverted == 0)||(single_option_representives_inverted == 1)) {
		// Field[0][i][j] = geben;	//Dead with number 5
		Field[0][i-1][j-1] = geben;
		Field[0][i][j+1] = geben;
		Field[0][i+1][j] = geben;
		Field[0][i+1][j+1] = geben;
		Field[0][i-1][j+2] = geben;
		Field[0][i+2][j-1] = geben;
		Field[0][i+2][j+2] = geben;
	}
}

void set_f_links_oben (unsigned int single_option_representives_inverted, Spielfeld Field, unsigned int geben, unsigned int i, unsigned int j) {	//platziert im Zentrum, links Wachstum, oben Anhängsel
	if (single_option_representives_inverted == 0) {
		Field[0][i][j] = geben;
		Field[0][i][j-1] = geben;
		Field[0][i-1][j+1] = geben;
		Field[0][i-1][j] = geben;
		Field[0][i+1][j] = geben;
	} else if (single_option_representives_inverted == 1) {
		Field[0][i][j] = geben;
		Field[0][i][j-1] = geben;
		Field[0][i-1][j+1] = geben;
		Field[0][i-1][j] = geben;
		Field[0][i+1][j] = geben;
		Field[0][i-1][j-1] = geben;
	}
}

void set_f_oben_rechts (unsigned int single_option_representives_inverted, Spielfeld Field, unsigned int geben, unsigned int i, unsigned int j) {
	if (single_option_representives_inverted == 0) {
		Field[0][i][j] = geben;
		Field[0][i][j-1] = geben;
		Field[0][i][j+1] = geben;
		Field[0][i-1][j] = geben;
		Field[0][i+1][j+1] = geben;
	} else if (single_option_representives_inverted == 1) {
		Field[0][i][j] = geben;
		Field[0][i][j-1] = geben;
		Field[0][i][j+1] = geben;
		Field[0][i-1][j] = geben;
		Field[0][i+1][j+1] = geben;
		Field[0][i-1][j+1] = geben;
	}
}

void set_f_rechts_unten (unsigned int single_option_representives_inverted, Spielfeld Field, unsigned int geben, unsigned int i, unsigned int j) {
	if (single_option_representives_inverted == 0) {
		Field[0][i][j] = geben;
		Field[0][i][j+1] = geben;
		Field[0][i-1][j] = geben;
		Field[0][i+1][j] = geben;
		Field[0][i+1][j-1] = geben;
	} else if (single_option_representives_inverted == 1) {
		Field[0][i][j] = geben;
		Field[0][i][j+1] = geben;
		Field[0][i-1][j] = geben;
		Field[0][i+1][j] = geben;
		Field[0][i+1][j-1] = geben;
		Field[0][i+1][j+1] = geben;
	}
}

void set_f_oben_links (unsigned int single_option_representives_inverted, Spielfeld Field, unsigned int geben, unsigned int i, unsigned int j) {
	if (single_option_representives_inverted == 0) {
		Field[0][i][j] = geben;
		Field[0][i][j-1] = geben;
		Field[0][i][j+1] = geben;
		Field[0][i-1][j] = geben;
		Field[0][i+1][j-1] = geben;
	} else if (single_option_representives_inverted == 1) {
		Field[0][i][j] = geben;
		Field[0][i][j-1] = geben;
		Field[0][i][j+1] = geben;
		Field[0][i-1][j] = geben;
		Field[0][i+1][j-1] = geben;
		Field[0][i-1][j-1] = geben;
	}
}

void inverted_organism (Spielfeld Spiel, unsigned int* level, Spielfeld Sf_permutations, Spielfeld Field, unsigned int geben, Spielfeld Opague_o_field, unsigned int gamemode_played, Special_Fields Allocation_o, unsigned int number_of_players, unsigned int m, unsigned int n, unsigned int* information_code, Growth_Player* Growth_players) {
	unsigned int edges_of_organism[4];	//0=oben, 1=rechts, 2=unten, 3=links

	show_field (number_of_players, level, Sf_permutations, Opague_o_field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);

	find_edges_of_organism_2dim (edges_of_organism, Spiel, geben, m, n);

	for (unsigned int i=edges_of_organism[0]; i<=edges_of_organism[2]; i++) {
		for (unsigned int j=edges_of_organism[3]; j<=edges_of_organism[1]; j++) {
			if (Spiel[0][i][j] == geben) {
				set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j, 0);
			} else if (Spiel[0][i][j] == 0) {
				set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j, geben);
			}
		}
	}

}

void show_abilities (unsigned int* ability) {
	if ((ability[1] == 0)||(ability[1] == 100)) {
		printf("	Ultra light: 1 \n");
	}
	if ((ability[2] == 0)||(ability[2] == 100)) {
		printf("	Light    : 2 \n");
	}
	if ((ability[3] == 0)||(ability[3] == 100)) {
		printf("	Anti     : 3 \n");
	}
	if ((ability[4] == 0)||(ability[4] == 100)) {
		printf("	Cornered   : 4 \n");
	}
	if ((ability[5] == 0)||(ability[5] == 100)) {
		printf("	Inhibitor  : 5 \n");
	}
	if ((ability[6] == 0)||(ability[6] == 100)) {
		printf("	Shield     : 6 \n");
	}
	if ((ability[7] == 0)||(ability[7] == 100)) {
		printf("	Poisoning  : 7 \n");
	}
	if ((ability[8] == 0)||(ability[8] == 100)) {
		printf("	Pressure   : 8 \n");
	}
	if ((ability[9] == 0)||(ability[9] == 100)) {
		printf("	Electric   : 9 \n");
	}

}

void addition_maker (Spielfeld Field, unsigned int m, unsigned int n, unsigned int number_of_players, unsigned int geben, Spielfeld Opague_o_field, unsigned int gamemode_played, Special_Fields Allocation_o, unsigned int* ges) {
	Spielfeld Field_addition;
	unsigned int additional_counter;

	additional_counter = 0;
	Field_addition = Spielfeld_Create (m, n, 0);

	for (unsigned int i=1; i<=m-2; i++) {
		for (unsigned int j=1; j<=n-2; j++) {
			if (Field[0][i][j] == geben) {
				for (unsigned int t=0; t<=2; t++) {
					for (unsigned int z=0; z<=2; z++) {
						if (((t+z)%2 == 1)&&(Field[0][i-1+t][j-1+z] != 0)&&(Field[0][i-1+t][j-1+z] <= number_of_players)&&(Field[0][i-1+t][j-1+z] != geben)) {
							if (Field_addition[0][i-1+t][j-1+z] == 0) {
								additional_counter += Field[0][i-1+t][j-1+z];
								Field_addition[0][i-1+t][j-1+z] = 1;
							}
							if (Field_addition[0][i][j] == 0) {
								additional_counter += Field[0][i][j];
								Field_addition[0][i][j] = 1;
							}
						}
					}
				}
			}
		}
	}

	additional_counter = additional_counter%(number_of_players+1);
	if ((additional_counter != 0)&&(ges[additional_counter] == additional_counter*1010)) {
		additional_counter = 0;
	}

	for (unsigned int i=1; i<=m-2; i++) {
		for (unsigned int j=1; j<=n-2; j++) {
			if (Field_addition[0][i][j] != 0) {
				set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, i, j, additional_counter);
			}
		}
	}

	Spielfeld_Destroy (Field_addition, m, 0);
}

void projection_maker (Spielfeld Field, unsigned int number_of_players, unsigned int geben, Spielfeld Opague_o_field, unsigned int gamemode_played, Special_Fields Allocation_o, unsigned int direction, unsigned int intensity_minimum, unsigned int single_option_representives_intensity_loss_per_line_multiplication, unsigned int m, unsigned int n) {

	double intensity_counter, intensity_minimum_real, intensity_loss_per_line_multiplication_real;
	double Spielfeld_intensity[number_of_players][m][n];	//enthält die Intensitäten der Spieler, index_verschiebung geben-->Spielfeld_intensity[geben-1]
	unsigned int a;

	// printf("projection_maker ok1\n");	//test

	a = 0;
	intensity_counter = 1;
	intensity_minimum_real = 1.0*intensity_minimum/100;
	intensity_loss_per_line_multiplication_real = 1.0*single_option_representives_intensity_loss_per_line_multiplication/100;

	for (unsigned int p=0; p<number_of_players; p++) {
		for (unsigned int i=0; i<=m-1; i++) {
			for (unsigned int j=0; j<=n-1; j++) {
				Spielfeld_intensity[p][i][j] = 0.0;
			}
		}
	}

	// printf("projection_maker ok2\n");	//test

	for (unsigned int i=1; i<=m-2; i++) {

		// printf("projection_maker ok i=%u\n", i);	//test

		for (unsigned int j=1; j<=n-2; j++) {

			// printf("projection_maker ok i=%u, j=%u\n", i, j);	//test

			if (Field[0][i][j] <= number_of_players) {
				for (unsigned int p=1; p<=number_of_players; p++) {	//p entspricht den Spielern

					// printf("projection_maker ok i=%u, j=%u, p=%u \n", i, j, p);	//test

					if (direction == Changing) {
						direction = geben%Changing;
					}
					if (direction == Vertikal) {
						for (unsigned int k=1; k<=n-2; k++) {
							if (Field[0][i][k] == p) {
								if (j != k) {
									for (int q=1; q<=abs(j-k); q+=1) {
										intensity_counter *= intensity_loss_per_line_multiplication_real;
									}
								}
								Spielfeld_intensity[p-1][i][j] += intensity_counter;
								intensity_counter = 1;
							}
						}
					} else if (direction == Horizontal) {
						for (unsigned int h=1; h<=m-2; h++) {
							if (Field[0][h][j] == p) {
								if (i != h) {
									for (int q=1; q<=abs(i-h); q+=1) {
										intensity_counter *= intensity_loss_per_line_multiplication_real;
									}
								}
								Spielfeld_intensity[p-1][i][j] += intensity_counter;
								intensity_counter = 1;
							}
						}
					}
				}
			}
		}
	}

	for (unsigned int i=1; i<=m-2; i++) {
		for (unsigned int j=1; j<=n-2; j++) {
			for (unsigned int p=1; p<=number_of_players; p++) {
				for (unsigned int q=1; q<=number_of_players; q++) {
					if (p != q) {
						if (Spielfeld_intensity[p-1][i][j] > Spielfeld_intensity[q-1][i][j]) {
							a += 1;
						}
					}
				}
				if ((a == number_of_players-1)&&(Spielfeld_intensity[p-1][i][j] >= intensity_minimum_real)) {
					set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, i, j, p);
				}
				a = 0;
			}
		}
	}
}

void assassin_maker (unsigned int* level, Spielfeld Sf_permutations, Spielfeld Field, unsigned int geben, Special_Fields Opague_o, unsigned int gamemode_played, Special_Fields Allocation_o, unsigned int number_of_players, unsigned int m, unsigned int n, unsigned int AOP, unsigned int* information_code, Growth_Player* Growth_players) {
	unsigned int assassin_counter, a, b;
	assassin_counter = 0;
	a = 0;
	b = 0;

	for (unsigned int i=1; i<=m-2; i++) {
		for (unsigned int j=1; j<=n-2; j++) {
			if (Field[0][i][j] == geben) {
				for (unsigned int h=i-1; h<=i+1; h++) {
					for (unsigned int k=j-1; k<=j+1; k++) {
						if ((Field[0][h][k] != Field[0][i][j])&&(h>=1)&&(h<=m-2)&&(k>=1)&&(k<=n-2)) {
							assassin_counter += 1;
						}
					}
				}
				if (assassin_counter == 8) {

					a = 0;
					for (unsigned int h=i-1; h<=i+1; h++) {
						for (unsigned int k=j-1; k<=j+1; k++) {
							if ((Field[0][h][k] != Field[0][i][j])&&(Field[0][h][k] <= number_of_players)&&(Field[0][h][k] != 0)) {
								if (b == 0) {
									b = 1;
									if (Opague_o.characterization >= 1) {
										opague_builder (Field, Opague_o, m, n, geben, AOP, Allocation_o, number_of_players, gamemode_played);
										show_field (number_of_players, level, Sf_permutations, Opague_o.field, Opague_o.field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
									} else {
										show_field (number_of_players, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
									}
								}
								set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, h, k, 0);
								a += 1;
							}
						}
					}

					if (a != 0) {
								if (Growth_players[0].color == 1) {
					Square_color_interpretation (Growth_players, geben, number_of_players, Field[0][i][j]);
								}
						printf("\n");
						printf("	An Assassin \n");
						printf("\n");
								if (Growth_players[0].color == 1) {
					set_terminal_color (cNORMAL);
				}
					}
					a = 0;
					b = 0;
				}
				assassin_counter = 0;
			}
		}
	}
}

void Avalanche_maker (Spielfeld Field, Spielfeld Opague_o_field, Special_Fields Allocation_o, unsigned int geben, unsigned int gamemode_played, unsigned int number_of_players, unsigned int m, unsigned int n) {
	for (unsigned int i=1; i<=m-2; i++) {
		for (unsigned int j=1; j<=n-2; j++) {
			if (Field[0][i][j] == geben) {
				if ((Field[0][i][j-1] != geben)&&(Field[0][i][j-1] != 0)&&(Field[0][i][j-1] <= number_of_players)&&(((n-2)/2)+1<=j-1)) {
					set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, i, j, Field[0][i][j-1]);
					set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, i, j-1, geben);
					Avalanche_maker (Field, Opague_o_field, Allocation_o, geben, gamemode_played, number_of_players, m, n);

					// printf("Avalanche_maker ok.1 \n");	//test

				} else if ((Field[0][i][j+1] != geben)&&(Field[0][i][j+1] != 0)&&(Field[0][i][j+1] <= number_of_players)&&(((n-2)/2)+1>=j+1)) {
					set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, i, j, Field[0][i][j+1]);
					set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, i, j+1, geben);
					Avalanche_maker (Field, Opague_o_field, Allocation_o, geben, gamemode_played, number_of_players, m, n);

					// printf("Avalanche_maker ok.2 \n");	//test

				} else if ((Field[0][i-1][j] != geben)&&(Field[0][i-1][j] != 0)&&(Field[0][i-1][j] <= number_of_players)&&(((m-2)/2)+1<=i-1)) {
					set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, i, j, Field[0][i-1][j]);
					set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, i-1, j, geben);
					Avalanche_maker (Field, Opague_o_field, Allocation_o, geben, gamemode_played, number_of_players, m, n);

					// printf("Avalanche_maker ok.3 \n");	//test

				} else if ((Field[0][i+1][j] != geben)&&(Field[0][i+1][j] != 0)&&(Field[0][i+1][j] <= number_of_players)&&(((m-2)/2)+1>=i+1)) {
					set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, i, j, Field[0][i+1][j]);
					set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, i+1, j, geben);
					Avalanche_maker (Field, Opague_o_field, Allocation_o, geben, gamemode_played, number_of_players, m, n);

					// printf("Avalanche_maker ok.4 \n");	//test
				}
			}
		}
	}
}

void ges_counter (Spielfeld Field, unsigned int m, unsigned int n, unsigned int* ges, unsigned int number_of_players) {
	for (unsigned int i=1; i<m-1; i+=1){
		for (unsigned int j=1; j<n-1; j+=1){
			for (unsigned int p=1; p<=number_of_players; p+=1) {
				if ((Field[0][i][j] == p)&&(ges[p] < 1010*p)) {
					ges[p] += 1;
					break;
				}
			}
		}
	}
}

void ges0_reset_and_counter (unsigned int* ges, unsigned int number_of_players) {
	ges[0] = 0;
	for (unsigned int p=1; p<=number_of_players; p+=1) {
		ges[0] += ges[p];
	}
}

void get_two_amounts_for_permutations (unsigned int* aopn_b, unsigned int* aopn_c, unsigned int m, unsigned int n, unsigned int Collector_of_permutation_permutation_number_b, unsigned int Collector_of_permutation_permutation_number_c) {	//permutation_number_b, permutation_number_c are arguments, 0<permutation_number_b<permutation_number_c<10
	unsigned int x, y, a;
	x = m-2;
	y = n-2;
	a = 0;

	// printf("get_two_amounts_for_permutations ok.1 \n");	//test
	if ((x*y)%Collector_of_permutation_permutation_number_c == 0) {
		*aopn_b = 0;
		*aopn_c = (x*y)/Collector_of_permutation_permutation_number_c;
	} else if ((x*y)%Collector_of_permutation_permutation_number_b == 0) {
		*aopn_b = (x*y)/Collector_of_permutation_permutation_number_b;
		*aopn_c = 0;
	} else {
		*aopn_b = (x*y)/(Collector_of_permutation_permutation_number_b+Collector_of_permutation_permutation_number_c);
		*aopn_c = (x*y)/(Collector_of_permutation_permutation_number_b+Collector_of_permutation_permutation_number_c);
		a = (x*y)%(Collector_of_permutation_permutation_number_b+Collector_of_permutation_permutation_number_c);
	}

	// printf("get_two_amounts_for_permutations ok.2 \n");	//test

	if (a/Collector_of_permutation_permutation_number_c != 0) {
		*aopn_c += a/Collector_of_permutation_permutation_number_c;
		a = a % Collector_of_permutation_permutation_number_c;
	}
	if (a/Collector_of_permutation_permutation_number_b != 0) {
		*aopn_b += a/Collector_of_permutation_permutation_number_b;
		a = a % Collector_of_permutation_permutation_number_b;
	}

	// printf("get_two_amounts_for_permutations ok.3 \n");	//test

	if (a > 0) {
		int* Rest;
		int* permutation_number_c_factor;
		int* permutation_number_b_factor;	//die Null wird wegen Vorganger nicht gebraucht.
		unsigned int durchlauf;

		Rest = int_Vektor_Create (4);
		permutation_number_c_factor = int_Vektor_Create (4);
		permutation_number_b_factor = int_Vektor_Create (4);

		Rest[2] = Collector_of_permutation_permutation_number_b;
		Rest[1] = Collector_of_permutation_permutation_number_c;
		permutation_number_b_factor[2] = 1;
		permutation_number_b_factor[1] = 0;
		permutation_number_c_factor[2] = 0;
		permutation_number_c_factor[1] = 1;
		durchlauf = 2;

		// printf("get_two_amounts_for_permutations ok.4 \n");	//test

		while ((Rest[1] != 1)&&(Rest[2] != 1)&&(Rest[3] != 1)) {	//erweiteter euklidischer Algorithmus

			// printf("get_two_amounts_for_permutations while-Schleife ok.4.1 \n");	//test

			Rest[durchlauf%3+1] = Rest[Vorganger(Vorganger(durchlauf%3+1, 3), 3)]-Rest[Vorganger(durchlauf%3+1, 3)]*(Rest[Vorganger(Vorganger(durchlauf%3+1, 3), 3)]/Rest[Vorganger(durchlauf%3+1, 3)]);

			// printf("Rest[%u] = %d \n", durchlauf%3+1, Rest[durchlauf%3+1]);	//test

			permutation_number_c_factor[durchlauf%3+1] = permutation_number_c_factor[Vorganger(Vorganger(durchlauf%3+1, 3), 3)]-permutation_number_c_factor[Vorganger(durchlauf%3+1, 3)]*(Rest[Vorganger(Vorganger(durchlauf%3+1, 3), 3)]/Rest[Vorganger(durchlauf%3+1, 3)]);

			// printf("permutation_number_c_factor[%u] = %d \n", durchlauf%3+1, permutation_number_c_factor[durchlauf%3+1]);	//test

			permutation_number_b_factor[durchlauf%3+1] = permutation_number_b_factor[Vorganger(Vorganger(durchlauf%3+1, 3), 3)]-permutation_number_b_factor[Vorganger(durchlauf%3+1, 3)]*(Rest[Vorganger(Vorganger(durchlauf%3+1, 3), 3)]/Rest[Vorganger(durchlauf%3+1, 3)]);

			// printf("permutation_number_b_factor[%u] = %d \n", durchlauf%3+1, permutation_number_b_factor[durchlauf%3+1]);	//test

			durchlauf++;

			// printf("get_two_amounts_for_permutations while-Schleife ok.4.5 \n");	//test

			if ((Rest[1] == 0)||(Rest[2] == 0)||(Rest[3] == 0)) {
				printf("	ggT(%u, %u) != 1 caused a problem \n", Collector_of_permutation_permutation_number_b, Collector_of_permutation_permutation_number_c);
				durchlauf = 0;	//to know to cancel
				break;
			}
		}

		// printf("get_two_amounts_for_permutations ok.5 \n");	//test

		if (durchlauf != 0) {
			for (unsigned int p=1; p<=3; p++) {
				if (Rest[p] == 1) {
					permutation_number_c_factor[p] *= a;
					permutation_number_b_factor[p] *= a;

					while ((permutation_number_c_factor[p] < 0)&&(abs(permutation_number_c_factor[p]) > abs(*aopn_c))) {
						permutation_number_c_factor[p] += Collector_of_permutation_permutation_number_b;
						permutation_number_b_factor[p] -= Collector_of_permutation_permutation_number_c;
					}
					if ((permutation_number_b_factor[p] < 0)&&(abs(permutation_number_b_factor[p]) > abs(*aopn_b))) {
						printf("	Try again with other arguments or with another size. \n");
					} else {
						if (permutation_number_b_factor[p] < 0) {
							for (int q=1; q<=abs(permutation_number_b_factor[p]); q+=1) {
								*aopn_b -= 1;
							}
						} else if (permutation_number_b_factor[p] > 0) {
							for (int q=1; q<=abs(permutation_number_b_factor[p]); q+=1) {
								*aopn_b += 1;
							}
						}
						if (permutation_number_c_factor[p] < 0) {
							for (int q=1; q<=abs(permutation_number_c_factor[p]); q+=1) {
								*aopn_c -= 1;
							}
						} else if (permutation_number_c_factor[p] > 0) {
							for (int q=1; q<=abs(permutation_number_c_factor[p]); q+=1) {
								*aopn_c += 1;
							}
						}

					}
				}
			}
		}

		int_Vektor_Destroy (Rest);

		int_Vektor_Destroy (permutation_number_b_factor);

		int_Vektor_Destroy (permutation_number_c_factor);
	}

	while (*aopn_c > *aopn_b + ((Collector_of_permutation_permutation_number_b+Collector_of_permutation_permutation_number_c)/2)) {
		*aopn_c -= Collector_of_permutation_permutation_number_b;
		*aopn_b += Collector_of_permutation_permutation_number_c;
	}
	while (*aopn_b > *aopn_c + ((Collector_of_permutation_permutation_number_b+Collector_of_permutation_permutation_number_c)/2)) {
		*aopn_b -= Collector_of_permutation_permutation_number_c;
		*aopn_c += Collector_of_permutation_permutation_number_b;
	}

	// printf("	aopn_b: %u \n", *aopn_b);	//test
	// printf("	aopn_c: %u \n", *aopn_c);	//test
	// printf("	Collector_of_permutation_permutation_number_b: %u \n", Collector_of_permutation_permutation_number_b);	//test
	// printf("	Collector_of_permutation_permutation_number_c: %u \n", Collector_of_permutation_permutation_number_c);	//test
	// printf("	x*y: %u \n", x*y);	//test
	// printf("	a: %u \n", a);	//test

	if (Collector_of_permutation_permutation_number_b*(*aopn_b) + Collector_of_permutation_permutation_number_c*(*aopn_c) != x*y) {
		printf("	Bir hata var. Miktarlar yanlis. \n");
		*aopn_c = 0;
		*aopn_b = 0;
	}

	if (Collector_of_permutation_permutation_number_b*(*aopn_b) + Collector_of_permutation_permutation_number_c*(*aopn_c) == x*y) {	//test
		printf("	Her sey dogrudur. \n");
	}
}

void translate_permutations_amounts_to_permutations_areas (Spielfeld Sf_permutations, unsigned int m, unsigned int n, Collector Collector_of_permutation) {

	unsigned int unutma_i, unutma_j, amount_of_permutation_number_c_in_real, amount_of_permutation_number_b_in_real;

	unutma_i = 1;
	unutma_j = 0;
	nereye_gitmeliyiz = to_the_right;

	amount_of_permutation_number_c_in_real = Collector_of_permutation.amount_of_permutation_number_c;
	amount_of_permutation_number_b_in_real = Collector_of_permutation.amount_of_permutation_number_b;

	// printf("translate_permutations_amounts_to_permutations_areas ok.1\n");	//test

	while ((Collector_of_permutation.amount_of_permutation_number_c > 0)||(Collector_of_permutation.amount_of_permutation_number_b > 0)) {		//the reduction of the amounts only happens intern of this function, because they are copies

		// printf("translate_permutations_amounts_to_permutations_areas while ok.2\n");	//test

		if (Collector_of_permutation.amount_of_permutation_number_c >= Collector_of_permutation.amount_of_permutation_number_b) {

			// printf("translate_permutations_amounts_to_permutations_areas while ok.2c\n");	//test

			for (unsigned int p=1; p<=Collector_of_permutation.permutation_number_c; p++) {

				// printf("translate_permutations_amounts_to_permutations_areas while ok.3c\n");	//test

				if (nereye_gitmeliyiz == to_the_right) {	//if it gets needed, work with continue
					if ((Sf_permutations[0][unutma_i][unutma_j+1] == 0)&&(unutma_j+1 <= n-2)) {
						unutma_j += 1;	//unutma_ already changed, dont forget!
						Collector_of_permutation.areas_c[(amount_of_permutation_number_c_in_real - Collector_of_permutation.amount_of_permutation_number_c)][p-1][Horizontal] = unutma_i;
						Collector_of_permutation.areas_c[(amount_of_permutation_number_c_in_real - Collector_of_permutation.amount_of_permutation_number_c)][p-1][Vertikal] = unutma_j;

						Sf_permutations[0][unutma_i][unutma_j] = ((amount_of_permutation_number_c_in_real - Collector_of_permutation.amount_of_permutation_number_c)+(Collector_of_permutation.permutation_number_b+Collector_of_permutation.permutation_number_c))%100 +1;
					} else {
						nereye_gitmeliyiz = to_the_bottom;
						p -= 1;
					}
				} else if (nereye_gitmeliyiz == to_the_bottom) {
					if ((Sf_permutations[0][unutma_i+1][unutma_j] == 0)&&(unutma_i+1 <= m-2)) {
						unutma_i += 1;	//unutma_ already changed, dont forget!

						Collector_of_permutation.areas_c[(amount_of_permutation_number_c_in_real - Collector_of_permutation.amount_of_permutation_number_c)][p-1][Horizontal] = unutma_i;
						Collector_of_permutation.areas_c[(amount_of_permutation_number_c_in_real - Collector_of_permutation.amount_of_permutation_number_c)][p-1][Vertikal] = unutma_j;

						Sf_permutations[0][unutma_i][unutma_j] = ((amount_of_permutation_number_c_in_real - Collector_of_permutation.amount_of_permutation_number_c)+(Collector_of_permutation.permutation_number_b+Collector_of_permutation.permutation_number_c))%100 +1;
					} else {
						nereye_gitmeliyiz = to_the_left;
						p -= 1;
					}
				} else if (nereye_gitmeliyiz == to_the_left) {
					if ((Sf_permutations[0][unutma_i][unutma_j-1] == 0)&&(unutma_j-1 >= 1)) {
						unutma_j -= 1;	//unutma_ already changed, dont forget!

						Collector_of_permutation.areas_c[(amount_of_permutation_number_c_in_real - Collector_of_permutation.amount_of_permutation_number_c)][p-1][Horizontal] = unutma_i;
						Collector_of_permutation.areas_c[(amount_of_permutation_number_c_in_real - Collector_of_permutation.amount_of_permutation_number_c)][p-1][Vertikal] = unutma_j;

						Sf_permutations[0][unutma_i][unutma_j] = ((amount_of_permutation_number_c_in_real - Collector_of_permutation.amount_of_permutation_number_c)+(Collector_of_permutation.permutation_number_b+Collector_of_permutation.permutation_number_c))%100 +1;
					} else {
						nereye_gitmeliyiz = to_the_top;
						p -= 1;
					}
				} else if (nereye_gitmeliyiz == to_the_top) {
					if ((Sf_permutations[0][unutma_i-1][unutma_j] == 0)&&(unutma_i-1 >= 1)) {
						unutma_i -= 1;	//unutma_ already changed, dont forget!

						Collector_of_permutation.areas_c[(amount_of_permutation_number_c_in_real - Collector_of_permutation.amount_of_permutation_number_c)][p-1][Horizontal] = unutma_i;
						Collector_of_permutation.areas_c[(amount_of_permutation_number_c_in_real - Collector_of_permutation.amount_of_permutation_number_c)][p-1][Vertikal] = unutma_j;

						Sf_permutations[0][unutma_i][unutma_j] = ((amount_of_permutation_number_c_in_real - Collector_of_permutation.amount_of_permutation_number_c)+(Collector_of_permutation.permutation_number_b+Collector_of_permutation.permutation_number_c))%100 +1;
					} else {
						nereye_gitmeliyiz = to_the_right;
						p -= 1;
					}
				}
			}
			Collector_of_permutation.amount_of_permutation_number_c -= 1;

		} else if (Collector_of_permutation.amount_of_permutation_number_b >= Collector_of_permutation.amount_of_permutation_number_c) {

			// printf("translate_permutations_amounts_to_permutations_areas while ok.2b\n");	//test

			for (unsigned int p=1; p<=Collector_of_permutation.permutation_number_b; p++) {

				// printf("translate_permutations_amounts_to_permutations_areas while ok.3b\n");	//test

				if (nereye_gitmeliyiz == to_the_right) {	//if it gets needed, work with continue

					// printf("translate_permutations_amounts_to_permutations_areas while ok.4b\n");

					if ((Sf_permutations[0][unutma_i][unutma_j+1] == 0)&&(unutma_j+1 <= n-2)) {
						unutma_j += 1;	//unutma_ already changed, dont forget!

						// printf("translate_permutations_amounts_to_permutations_areas while ok.5b\n");	//test

						Collector_of_permutation.areas_b[(amount_of_permutation_number_b_in_real - Collector_of_permutation.amount_of_permutation_number_b)][p-1][Horizontal] = unutma_i;

						// printf("translate_permutations_amounts_to_permutations_areas while ok.5.1b\n");	//test

						Collector_of_permutation.areas_b[(amount_of_permutation_number_b_in_real - Collector_of_permutation.amount_of_permutation_number_b)][p-1][Vertikal] = unutma_j;

						// printf("translate_permutations_amounts_to_permutations_areas while ok.6b\n");	//test

						Sf_permutations[0][unutma_i][unutma_j] = (amount_of_permutation_number_b_in_real - Collector_of_permutation.amount_of_permutation_number_b)%100 +1;
					} else {
						nereye_gitmeliyiz = to_the_bottom;
						p -= 1;
					}
				} else if (nereye_gitmeliyiz == to_the_bottom) {
					if ((Sf_permutations[0][unutma_i+1][unutma_j] == 0)&&(unutma_i+1 <= m-2)) {
						unutma_i += 1;	//unutma_ already changed, dont forget!

						Collector_of_permutation.areas_b[(amount_of_permutation_number_b_in_real - Collector_of_permutation.amount_of_permutation_number_b)][p-1][Horizontal] = unutma_i;
						Collector_of_permutation.areas_b[(amount_of_permutation_number_b_in_real - Collector_of_permutation.amount_of_permutation_number_b)][p-1][Vertikal] = unutma_j;

						Sf_permutations[0][unutma_i][unutma_j] = (amount_of_permutation_number_b_in_real - Collector_of_permutation.amount_of_permutation_number_b)%100 +1;
					} else {
						nereye_gitmeliyiz = to_the_left;
						p -= 1;
					}
				} else if (nereye_gitmeliyiz == to_the_left) {
					if ((Sf_permutations[0][unutma_i][unutma_j-1] == 0)&&(unutma_j-1 >= 1)) {
						unutma_j -= 1;	//unutma_ already changed, dont forget!

						Collector_of_permutation.areas_b[(amount_of_permutation_number_b_in_real - Collector_of_permutation.amount_of_permutation_number_b)][p-1][Horizontal] = unutma_i;
						Collector_of_permutation.areas_b[(amount_of_permutation_number_b_in_real - Collector_of_permutation.amount_of_permutation_number_b)][p-1][Vertikal] = unutma_j;

						Sf_permutations[0][unutma_i][unutma_j] = (amount_of_permutation_number_b_in_real - Collector_of_permutation.amount_of_permutation_number_b)%100 +1;
					} else {
						nereye_gitmeliyiz = to_the_top;
						p -= 1;
					}
				} else if (nereye_gitmeliyiz == to_the_top) {
					if ((Sf_permutations[0][unutma_i-1][unutma_j] == 0)&&(unutma_i-1 >= 1)) {
						unutma_i -= 1;	//unutma_ already changed, dont forget!

						Collector_of_permutation.areas_b[(amount_of_permutation_number_b_in_real - Collector_of_permutation.amount_of_permutation_number_b)][p-1][Horizontal] = unutma_i;
						Collector_of_permutation.areas_b[(amount_of_permutation_number_b_in_real - Collector_of_permutation.amount_of_permutation_number_b)][p-1][Vertikal] = unutma_j;

						Sf_permutations[0][unutma_i][unutma_j] = (amount_of_permutation_number_b_in_real - Collector_of_permutation.amount_of_permutation_number_b)%100 +1;
					} else {
						nereye_gitmeliyiz = to_the_right;
						p -= 1;
					}
				}
			}
			Collector_of_permutation.amount_of_permutation_number_b -= 1;
		}
	}

	// printf("translate_permutations_amounts_to_permutations_areas while ok.3\n");	//test
}

void get_sigmas_for_permutation_number (unsigned int** sigmas_for_permutation_number, unsigned int permutation_number) {
	unsigned int Eintrag, hangi_sigma;

	Eintrag = 1;
	hangi_sigma = 0;
	muemkuen_mue = belki;

	// printf("get_sigmas_for_permutation_number ok.1\n");	//test

	for (unsigned int p=1; p<permutation_number; p++) {

		// printf("get_sigmas_for_permutation_number for(p) ok.2\n");	//test

		while ((sigmas_for_permutation_number[Fakultaet(permutation_number-1)-1][p] == 0)||(muemkuen_mue != evet)) {

			// printf("get_sigmas_for_permutation_number while ok.3\n");	//test

			muemkuen_mue = hayir;
			sigmas_for_permutation_number[hangi_sigma][p] = Eintrag;

			for (unsigned int q=0; q<=p; q++) {
				if (hangi_sigma < Fakultaet(permutation_number-1-p)) {
					muemkuen_mue = evet;
					break;
				} else if (sigmas_for_permutation_number[hangi_sigma][q] != sigmas_for_permutation_number[hangi_sigma-Fakultaet(permutation_number-1-p)][q]) {
					muemkuen_mue = evet;
					break;
				}
			}
			for (unsigned int q=0; q<p; q++) {
				if (Eintrag == sigmas_for_permutation_number[hangi_sigma][q]) {
					muemkuen_mue = hayir;
				}
			}
			if (muemkuen_mue == hayir) {
				Eintrag = (Eintrag+1)%permutation_number;
			} else if (muemkuen_mue == evet) {
				hangi_sigma += 1;
			} else if (muemkuen_mue == belki) {
				printf("	hangi_sigma: %u		neden belki?", hangi_sigma);
			}

			// printf("	muemkuen_mue: %u\n", muemkuen_mue);	//test
		}
		hangi_sigma = 0;
	}

	// for (unsigned int p=0; p<Fakultaet(permutation_number-1); p++) {	//test
		// for (unsigned int q=0; q<permutation_number; q++) {
			// printf("	%u", sigmas_for_permutation_number[p][q]);
		// }
		// printf("\n");
	// }	//test

}

void Permutations_permutate_maker (Spielfeld Collector_of_permutation_number_areas, Spielfeld Field, unsigned int number_of_players, unsigned int permutation_number, unsigned int** sigmas_for_permutation_number, unsigned int amount_of_permutation_number, unsigned int geben, Spielfeld Opague_o_field, unsigned int gamemode_played, Special_Fields Allocation_o) {
	unsigned int temp_permutations, hangi_sigma, unutma_i, unutma_j, unutma_r, unutma_s;
	temp_permutations = 0;
	hangi_sigma = 0;
	unutma_i = 0;	//changes
	unutma_j = 0;	//changes
	unutma_r = 0;
	unutma_s = 0;	//changes

	// printf("Permutations_permutate_maker ok.1\n");	//test

	if (permutation_number > 1) {

		for (unsigned int p=0; p<amount_of_permutation_number; p++) {	//going through Collector_of_permutation_number_areas

			// printf("Permutations_permutate_maker for(p) ok.2\n");	//test

			for (unsigned int q=1; q<=permutation_number-2; q++) {	//getting sigma(p)

				// printf("Permutations_permutate_maker for(p) ok.2.1\n");	//test

				hangi_sigma += Fakultaet(q)*Zufall(0, q);
			}

			// printf("Permutations_permutate_maker for(p) ok.3\n");	//test

			for (unsigned int r=0; r<permutation_number; r++) {
				if (Field[0][Collector_of_permutation_number_areas[p][r][Horizontal]][Collector_of_permutation_number_areas[p][r][Vertikal]] <= number_of_players) {
					unutma_r = r;	//find the first field which isn't an object
					break;
				}
			}

			// printf("Permutations_permutate_maker for(p) ok.4\n");	//test

			unutma_i = Collector_of_permutation_number_areas[p][unutma_r][Horizontal];

			// printf("Permutations_permutate_maker for(p) ok.4.1\n");	//test

			unutma_j = Collector_of_permutation_number_areas[p][unutma_r][Vertikal];

			// printf("Permutations_permutate_maker for(p) ok.4.2\n");	//test

			temp_permutations = Field[0][unutma_i][unutma_j];

			// printf("Permutations_permutate_maker for(p) ok.5\n");	//test

			for (unsigned int s=0; s<permutation_number; s++) {
				if (sigmas_for_permutation_number[hangi_sigma][s] == unutma_r) {
					unutma_s = s;
					break;
				}
			}

			// printf("Permutations_permutate_maker for(p) ok.6\n");	//test

			unutma_r = 1;	//übernimmt neue Aufgabe

			for (unsigned int q=0; q<permutation_number; q++) {

				if (Field[0][Collector_of_permutation_number_areas[p][sigmas_for_permutation_number[hangi_sigma][(unutma_s+permutation_number-unutma_r)%permutation_number]][Horizontal]][Collector_of_permutation_number_areas[p][sigmas_for_permutation_number[hangi_sigma][(unutma_s+permutation_number-unutma_r)%permutation_number]][Vertikal]] <= number_of_players) {	//Vorheriger in sigma <= number_of_players
					if (q == permutation_number-1) {
						set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, Collector_of_permutation_number_areas[p][sigmas_for_permutation_number[hangi_sigma][unutma_s]][Horizontal], Collector_of_permutation_number_areas[p][sigmas_for_permutation_number[hangi_sigma][unutma_s]][Vertikal], temp_permutations);
					} else {
						set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, Collector_of_permutation_number_areas[p][sigmas_for_permutation_number[hangi_sigma][unutma_s]][Horizontal], Collector_of_permutation_number_areas[p][sigmas_for_permutation_number[hangi_sigma][unutma_s]][Vertikal], Field[0][Collector_of_permutation_number_areas[p][sigmas_for_permutation_number[hangi_sigma][(unutma_s+permutation_number-unutma_r)%permutation_number]][Horizontal]][Collector_of_permutation_number_areas[p][sigmas_for_permutation_number[hangi_sigma][(unutma_s+permutation_number-unutma_r)%permutation_number]][Vertikal]]);
						unutma_s = (unutma_s+permutation_number-unutma_r)%permutation_number;
						unutma_r = 1;
					}
				} else {
					unutma_r += 1;
				}
			}

			unutma_r = 0;	//übernimmt neue (ursprüngliche/alte) Aufgabe mit Standartinitialisierung

			// printf("Permutations_permutate_maker for(p) ok.7\n");	//test

			hangi_sigma = 0;
		}
	}

	// printf("Permutations_permutate_maker ok.8\n");	//test
}

void turn_of_KI_random (Quidditch_setup* Qs, Moveable_objects_condition* Moc_Quaffel, Moveable_objects_condition* Moc_Schnatz, Moveable_objects_condition* Moc_Klatscher, unsigned int* KI_decision, Spielfeld Field, unsigned int m, unsigned int n, unsigned int geben, Special_Fields Opague_o, Special_Fields Allocation_o, Spielfeld Sf_permutations, unsigned int* ges, Growth_Player* Growth_players, unsigned int number_of_players, unsigned int gamemode_played, unsigned int* information_code, unsigned int* level, Limits limits, Single_option_representives single_option_representives, unsigned int rain, Realize_modifications_variables* rmv) {
	Spielfeld Field_copy;
	unsigned int* KI_table_of_choice;		// number/own_square or 0/enemy_square or 0/more (1) or less (2) squares in possession/difference of squares
	unsigned int* ges_copy;
	unsigned int dimension;

	#ifdef VERBOSE
	printf (" turn_of_KI_random ok.1 \n");	//test
	#endif

	dimension = 0;
	Field_copy = Spielfeld_Create (m, n, 1);	//0 to work with, 1 to synchronisate with
	dimension_of (level, &dimension, geben);
	KI_table_of_choice = unsigned_int_Vektor_Create (dimension);
	ges_copy = unsigned_int_Vektor_Create (rmv->AOP+1);
	for (unsigned int p=0; p<=rmv->AOP; p++) {
		ges_copy[p] = ges[p];
	}
	for (unsigned int i=1; i<=m-2; i++) {
		for (unsigned int j=1; j<=n-2; j++) {
			set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field_copy, 1, i, j, Field[0][i][j]);
		}
	}

	synchronisation_Field_copy (Field, Field_copy, m, n, number_of_players, geben, Opague_o.field, gamemode_played, Allocation_o);

	while (KI_table_of_choice[0] == 0) {
		fill_KI_table_of_choice (Qs, Moc_Quaffel, Moc_Schnatz, Moc_Klatscher, KI_decision, Field, Field_copy, m, n, geben, Opague_o, Allocation_o, Sf_permutations, ges_copy, Growth_players, number_of_players, gamemode_played, information_code, level, KI_table_of_choice, ges, limits, single_option_representives, rain, rmv);
	}

	synchronisation_Field_copy (Field, Field_copy, m, n, number_of_players, geben, Opague_o.field, gamemode_played, Allocation_o);

	rmv->var_[geben] = KI_table_of_choice[0];
	*KI_decision = KI_table_of_choice[5];
	if ((KI_table_of_choice[0] == Move_2)||(KI_table_of_choice[0] == Change_)||(KI_table_of_choice[0] == Move_4)) {
		set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, KI_table_of_choice[1]/100, KI_table_of_choice[1]%100, Field_copy[1][KI_table_of_choice[2]/100][KI_table_of_choice[2]%100]);
		set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, KI_table_of_choice[2]/100, KI_table_of_choice[2]%100, Field_copy[1][KI_table_of_choice[1]/100][KI_table_of_choice[1]%100]);
	} else if (KI_table_of_choice[0] == Minus_) {
		set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, KI_table_of_choice[1]/100, KI_table_of_choice[1]%100, 0);
	} else if (KI_table_of_choice[0] == Plus_) {
		set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, KI_table_of_choice[2]/100, KI_table_of_choice[2]%100, geben);
	} else if (KI_table_of_choice[0] == Destroy_) {
		set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, KI_table_of_choice[2]/100, KI_table_of_choice[2]%100, 0);
	}

	if (level[geben] == Liz) {
		Liz_max = 0;
	}

	unsigned_int_Vektor_Destroy (ges_copy);
	unsigned_int_Vektor_Destroy (KI_table_of_choice);
	Spielfeld_Destroy (Field_copy, m, 1);

	#ifdef VERBOSE
	printf (" turn_of_KI_random ok.2 \n");	//test
	#endif
}

void fill_KI_table_of_choice (Quidditch_setup* Qs, Moveable_objects_condition* Moc_Quaffel, Moveable_objects_condition* Moc_Schnatz, Moveable_objects_condition* Moc_Klatscher, unsigned int* KI_decision, Spielfeld Field, Spielfeld Field_copy, unsigned int m, unsigned int n, unsigned int geben, Special_Fields Opague_o, Special_Fields Allocation_o, Spielfeld Sf_permutations, unsigned int* ges_copy, Growth_Player* Growth_players, unsigned int number_of_players, unsigned int gamemode_played, unsigned int* information_code, unsigned int* level, unsigned int* KI_table_of_choice, unsigned int* ges, Limits limits, Single_option_representives single_option_representives, unsigned int rain, Realize_modifications_variables* rmv) {

	unsigned int w, d, e, how_many_ways_of_keeping;
	Spielfeld Plus_rememory;

	w = 3;
	d = 2;
	e = 3;
	how_many_ways_of_keeping = 1;
	Plus_rememory = Spielfeld_Create (m, n, 0);

	// printf("fill_KI_table_of_choice ok.1\n");	//test
	
	#ifdef VERBOSE
	printf("rmv->use_number: %u \n", rmv->use_number);	//test
	#endif

	if ((gamemode_played == Dynamic)||(gamemode_played == Arena)||(gamemode_played == Sand)||(gamemode_played == Hunt)) {
		how_many_ways_of_keeping = 2;
	} else if ((gamemode_played == Rain)||(gamemode_played == Race)||(gamemode_played == Fight)||(gamemode_played == Fall)||(gamemode_played == Collect)||(gamemode_played == Classic)) {
		how_many_ways_of_keeping = 3;
	} else if (gamemode_played == Contact) {
		how_many_ways_of_keeping = 5;
	}

	if (rmv->use_number == 1) {
		for (unsigned int i=1; i<=m-2; i++) {
			for (unsigned int j=1; j<=n-2; j++) {
				if (Field_copy[0][i][j] == geben) {
					for (unsigned int h=i-1; h<=i+1; h++) {
						for (unsigned int k=j-1; k<=j+1; k++) {
							if ((Plus_rememory[0][h][k] == 0)&&(Field_copy[0][h][k] == 0)&&(h<=m-2)&&(h>0)&&(k<=n-2)&&(k>0)) {	//Plus
								for (unsigned int p=1; p<=how_many_ways_of_keeping; p++) {
									set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field_copy, 0, h, k, geben);
									set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Plus_rememory, 0, h, k, geben);
									*KI_decision = p;
									set_KI_table_of_choice (Qs, Moc_Quaffel, Moc_Schnatz, Moc_Klatscher, KI_decision, Field, Field_copy, m, n, geben, Opague_o, Allocation_o, Sf_permutations, ges_copy, Growth_players, number_of_players, gamemode_played, information_code, level, KI_table_of_choice, w, d, e, Plus_, h, k, i, j, ges, limits, single_option_representives, rain, rmv);
								}
							}
						}
					}

					if (Field_copy[0][i][j] == geben) {	//Minus
						for (unsigned int p=1; p<=how_many_ways_of_keeping; p++) {
							set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field_copy, 0, i, j, 0);
							*KI_decision = p;
							set_KI_table_of_choice (Qs, Moc_Quaffel, Moc_Schnatz, Moc_Klatscher, KI_decision, Field, Field_copy, m, n, geben, Opague_o, Allocation_o, Sf_permutations, ges_copy, Growth_players, number_of_players, gamemode_played, information_code, level, KI_table_of_choice, w, d, e, Minus_, 0, 0, i, j, ges, limits, single_option_representives, rain, rmv);
						}
					}
				}
			}
		}
	} else if (rmv->use_number == 2) {
		for (unsigned int i=1; i<=m-2; i++) {
			for (unsigned int j=1; j<=n-2; j++) {
				if ((gamemode_played == Hunt)&&(geben == 1)) {
					if (Field_copy[0][i][j] == 11) {
						for (unsigned int h=i-1; h<=i+1; h++) {
							for (unsigned int k=j-1; k<=j+1; k++) {
								if ((Field_copy[0][h][k] == geben)&&(h<=m-2)&&(h>0)&&(k<=n-2)&&(k>0)&&((h+k)%2 == (i+j+1)%2)) {
									for (unsigned int p=1; p<=how_many_ways_of_keeping; p++) {
										set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field_copy, 0, i, j, geben);
										set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field_copy, 0, h, k, 11);
										*KI_decision = p;
										set_KI_table_of_choice (Qs, Moc_Quaffel, Moc_Schnatz, Moc_Klatscher, KI_decision, Field, Field_copy, m, n, geben, Opague_o, Allocation_o, Sf_permutations, ges_copy, Growth_players, number_of_players, gamemode_played, information_code, level, KI_table_of_choice, w, d, e, Change_, h, k, i, j, ges, limits, single_option_representives, rain, rmv);
									}
								} else if ((Field_copy[0][h][k] == 0)&&(h<=m-2)&&(h>0)&&(k<=n-2)&&(k>0)&&((h+k)%2 == (i+j+1)%2)) {
									for (unsigned int p=1; p<=how_many_ways_of_keeping; p++) {
										set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field_copy, 0, i, j, 0);
										set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field_copy, 0, h, k, 11);
										*KI_decision = p;
										set_KI_table_of_choice (Qs, Moc_Quaffel, Moc_Schnatz, Moc_Klatscher, KI_decision, Field, Field_copy, m, n, geben, Opague_o, Allocation_o, Sf_permutations, ges_copy, Growth_players, number_of_players, gamemode_played, information_code, level, KI_table_of_choice, w, d, e, Move_2, h, k, i, j, ges, limits, single_option_representives, rain, rmv);
									}
								}
							}
						}
					} else if (Field_copy[0][i][j] == geben) {
						for (unsigned int h=i-1; h<=i+1; h++) {
							for (unsigned int k=j-1; k<=j+1; k++) {
								if ((Field_copy[0][h][k] == 11)&&(h<=m-2)&&(h>0)&&(k<=n-2)&&(k>0)&&((h+k)%2 == (i+j+1)%2)) {	//Change_
									for (unsigned int p=1; p<=how_many_ways_of_keeping; p++) {
										set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field_copy, 0, i, j, 11);
										set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field_copy, 0, h, k, geben);
										*KI_decision = p;
										set_KI_table_of_choice (Qs, Moc_Quaffel, Moc_Schnatz, Moc_Klatscher, KI_decision, Field, Field_copy, m, n, geben, Opague_o, Allocation_o, Sf_permutations, ges_copy, Growth_players, number_of_players, gamemode_played, information_code, level, KI_table_of_choice, w, d, e, Change_, h, k, i, j, ges, limits, single_option_representives, rain, rmv);
									}
								} else if ((Field_copy[0][h][k] == 0)&&(h<=m-2)&&(h>0)&&(k<=n-2)&&(k>0)&&((h+k)%2 == (i+j+1)%2)) {	//Move
									for (unsigned int p=1; p<=how_many_ways_of_keeping; p++) {
										set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field_copy, 0, i, j, 0);
										set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field_copy, 0, h, k, geben);
										*KI_decision = p;
										set_KI_table_of_choice (Qs, Moc_Quaffel, Moc_Schnatz, Moc_Klatscher, KI_decision, Field, Field_copy, m, n, geben, Opague_o, Allocation_o, Sf_permutations, ges_copy, Growth_players, number_of_players, gamemode_played, information_code, level, KI_table_of_choice, w, d, e, Move_2, h, k, i, j, ges, limits, single_option_representives, rain, rmv);
									}
								}
							}
						}
					}
				} else {	//not gamemode_played == Hunt together with geben == 1
					if (Field_copy[0][i][j] == geben) {
						for (unsigned int h=i-1; h<=i+1; h++) {
							for (unsigned int k=j-1; k<=j+1; k++) {
								if (((Field_copy[0][h][k] != 0)&&(Field_copy[0][h][k] != geben)&&((gamemode_played != Hunt)||(Field_copy[0][h][k] == 1))&&((gamemode_played != Rain)||(Field_copy[0][h][k] == Raindrop))&&(Field_copy[0][h][k] != Wall)&&(Field_copy[0][h][k] != Wall_at_the_end)&&(Field_copy[0][h][k] != To_collect))&&(h<=m-2)&&(h>0)&&(k<=n-2)&&(k>0)&&(((h+k)%2 == (i+j+1)%2)||(gamemode_played == Contact))) {	//Change_
									for (unsigned int p=1; p<=how_many_ways_of_keeping; p++) {
										set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field_copy, 0, i, j, Field_copy[0][h][k]);
										set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field_copy, 0, h, k, geben);
										*KI_decision = p;
										set_KI_table_of_choice (Qs, Moc_Quaffel, Moc_Schnatz, Moc_Klatscher, KI_decision, Field, Field_copy, m, n, geben, Opague_o, Allocation_o, Sf_permutations, ges_copy, Growth_players, number_of_players, gamemode_played, information_code, level, KI_table_of_choice, w, d, e, Change_, h, k, i, j, ges, limits, single_option_representives, rain, rmv);
									}
								} else if ((Field_copy[0][h][k] == 0)&&(h<=m-2)&&(h>0)&&(k<=n-2)&&(k>0)&&((h+k)%2 == (i+j+1)%2)) {	//Move
									for (unsigned int p=1; p<=how_many_ways_of_keeping; p++) {
										set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field_copy, 0, i, j, 0);
										set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field_copy, 0, h, k, geben);
										*KI_decision = p;
										set_KI_table_of_choice (Qs, Moc_Quaffel, Moc_Schnatz, Moc_Klatscher, KI_decision, Field, Field_copy, m, n, geben, Opague_o, Allocation_o, Sf_permutations, ges_copy, Growth_players, number_of_players, gamemode_played, information_code, level, KI_table_of_choice, w, d, e, Move_2, h, k, i, j, ges, limits, single_option_representives, rain, rmv);
									}
								}
							}
						}
					}
				}
			}
		}
	} else if (rmv->use_number == 3) {
		for (unsigned int p=1; p<=how_many_ways_of_keeping; p++) {
			*KI_decision = p;
			set_KI_table_of_choice (Qs, Moc_Quaffel, Moc_Schnatz, Moc_Klatscher, KI_decision, Field, Field_copy, m, n, geben, Opague_o, Allocation_o, Sf_permutations, ges_copy, Growth_players, number_of_players, gamemode_played, information_code, level, KI_table_of_choice, w, d, e, Revive_, 0, 0, 0, 0, ges, limits, single_option_representives, rain, rmv);	//Revive_
		}
		if (gamemode_played == Rain) {	//Destroy_
			for (unsigned int h=1; h<=(m-4); h+=1){
				for (unsigned int k=1; k<=(n-2); k+=1){
					if ((Field[0][h][k] != geben)&&(Field[0][h][k] != 0)){
						for (unsigned int p=1; p<=how_many_ways_of_keeping; p++) {
							set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field_copy, 0, h, k, 0);
							*KI_decision = p;
							set_KI_table_of_choice (Qs, Moc_Quaffel, Moc_Schnatz, Moc_Klatscher, KI_decision, Field, Field_copy, m, n, geben, Opague_o, Allocation_o, Sf_permutations, ges_copy, Growth_players, number_of_players, gamemode_played, information_code, level, KI_table_of_choice, w, d, e, Destroy_, h, k, 0, 0, ges, limits, single_option_representives, rain, rmv);
						}
					}
				}
			}
		} else {	// gamemode_played != Rain
			for (unsigned int i=1; i<=m-2; i++) {
				for (unsigned int j=1; j<=n-2; j++) {
					if (Field_copy[0][i][j] == geben) {
							for (unsigned int h=i-1; h<=i+1; h++) {
								for (unsigned int k=j-1; k<=j+1; k++) {
									if ((Field_copy[0][h][k] != geben)&&(Field_copy[0][h][k] != 0)&&(((gamemode_played != Hunt)||(geben == 1))||(Field_copy[0][h][k] == 1))&&((gamemode_played != Ulcer)||(Field_copy[0][h][k] != 1))&&(Field_copy[0][h][k] != Wall)&&(Field_copy[0][h][k] != Wall_at_the_end)&&(Field_copy[0][h][k] != To_collect)&&(Field_copy[0][h][k] != Fall_ball)&&(Field_copy[0][h][k] != Dynamic_ball)&&(h<=m-2)&&(h>0)&&(k<=n-2)&&(k>0)&&(((h+k)%2 == (i+j+1)%2)||(gamemode_played == Contact))) {
										for (unsigned int p=1; p<=how_many_ways_of_keeping; p++) {
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field_copy, 0, h, k, 0);
											*KI_decision = p;
											set_KI_table_of_choice (Qs, Moc_Quaffel, Moc_Schnatz, Moc_Klatscher, KI_decision, Field, Field_copy, m, n, geben, Opague_o, Allocation_o, Sf_permutations, ges_copy, Growth_players, number_of_players, gamemode_played, information_code, level, KI_table_of_choice, w, d, e, Destroy_, h, k, i, j, ges, limits, single_option_representives, rain, rmv);
										}
									}
								}
							}
						
					}
				}
			}
		}
	} else if (rmv->use_number == 4) {
		for (unsigned int p=1; p<=how_many_ways_of_keeping; p++) {
			*KI_decision = p;
			set_KI_table_of_choice (Qs, Moc_Quaffel, Moc_Schnatz, Moc_Klatscher, KI_decision, Field, Field_copy, m, n, geben, Opague_o, Allocation_o, Sf_permutations, ges_copy, Growth_players, number_of_players, gamemode_played, information_code, level, KI_table_of_choice, w, d, e, Boost_, 0, 0, 0, 0, ges, limits, single_option_representives, rain, rmv);	//Boost_
		}
		for (unsigned int i=1; i<=m-2; i++) {	//Move
			for (unsigned int j=1; j<=n-2; j++) {
				if (Field_copy[0][i][j] == geben) {
					for (unsigned int h=i-1; h<=i+1; h++) {
						for (unsigned int k=j-1; k<=j+1; k++) {
							if ((Field_copy[0][h][k] == 0)&&(h<=m-2)&&(h>0)&&(k<=n-2)&&(k>0)&&((h+k)%2 == (i+j+1)%2)) {
								for (unsigned int p=1; p<=how_many_ways_of_keeping; p++) {
									set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field_copy, 0, i, j, 0);
									set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field_copy, 0, h, k, geben);
									*KI_decision = p;
									set_KI_table_of_choice (Qs, Moc_Quaffel, Moc_Schnatz, Moc_Klatscher, KI_decision, Field, Field_copy, m, n, geben, Opague_o, Allocation_o, Sf_permutations, ges_copy, Growth_players, number_of_players, gamemode_played, information_code, level, KI_table_of_choice, w, d, e, Move_4, h, k, i, j, ges, limits, single_option_representives, rain, rmv);
								}
							}
						}
					}
				}
			}
		}
	} else if (rmv->use_number == 5) {
		w = 2;
		d = 2;
		e = 3;
		for (unsigned int p=1; p<=how_many_ways_of_keeping; p++) {
			*KI_decision = p;
			set_KI_table_of_choice (Qs, Moc_Quaffel, Moc_Schnatz, Moc_Klatscher, KI_decision, Field, Field_copy, m, n, geben, Opague_o, Allocation_o, Sf_permutations, ges_copy, Growth_players, number_of_players, gamemode_played, information_code, level, KI_table_of_choice, w, d, e, new_2, 0, 0, 0, 0, ges, limits, single_option_representives, rain, rmv);	//2-new
		}

		w = 4;
		d = 2;
		e = 3;
		for (unsigned int p=1; p<=how_many_ways_of_keeping; p++) {
			*KI_decision = p;
			set_KI_table_of_choice (Qs, Moc_Quaffel, Moc_Schnatz, Moc_Klatscher, KI_decision, Field, Field_copy, m, n, geben, Opague_o, Allocation_o, Sf_permutations, ges_copy, Growth_players, number_of_players, gamemode_played, information_code, level, KI_table_of_choice, w, d, e, new_4_5, 0, 0, 0, 0, ges, limits, single_option_representives, rain, rmv);	//4/5-new
		}
	} else if (rmv->use_number == 6) {
		w = 3;
		d = 1;
		e = 3;
		for (unsigned int p=1; p<=how_many_ways_of_keeping; p++) {
			*KI_decision = p;
			set_KI_table_of_choice (Qs, Moc_Quaffel, Moc_Schnatz, Moc_Klatscher, KI_decision, Field, Field_copy, m, n, geben, Opague_o, Allocation_o, Sf_permutations, ges_copy, Growth_players, number_of_players, gamemode_played, information_code, level, KI_table_of_choice, w, d, e, min_1, 0, 0, 0, 0, ges, limits, single_option_representives, rain, rmv);	//1-min
		}

		w = 3;
		d = 2;
		e = 4;
		for (unsigned int p=1; p<=how_many_ways_of_keeping; p++) {
			*KI_decision = p;
			set_KI_table_of_choice (Qs, Moc_Quaffel, Moc_Schnatz, Moc_Klatscher, KI_decision, Field, Field_copy, m, n, geben, Opague_o, Allocation_o, Sf_permutations, ges_copy, Growth_players, number_of_players, gamemode_played, information_code, level, KI_table_of_choice, w, d, e, max_4, 0, 0, 0, 0, ges, limits, single_option_representives, rain, rmv);	//4-max
		}
	}

	Spielfeld_Destroy (Plus_rememory, m, 0);
	
	#ifdef VERBOSE
	printf("fill_KI_table_of_choice ok.2\n");	//test
	#endif

}

void set_KI_table_of_choice (Quidditch_setup* Qs, Moveable_objects_condition* Moc_Quaffel, Moveable_objects_condition* Moc_Schnatz, Moveable_objects_condition* Moc_Klatscher, unsigned int* KI_decision, Spielfeld Field, Spielfeld Field_copy, unsigned int m, unsigned int n, unsigned int geben, Special_Fields Opague_o, Special_Fields Allocation_o, Spielfeld Sf_permutations, unsigned int* ges_copy, Growth_Player* Growth_players, unsigned int number_of_players, unsigned int gamemode_played, unsigned int* information_code, unsigned int* level, unsigned int* KI_table_of_choice, unsigned int w, unsigned int d, unsigned int e, unsigned int exactly_number, unsigned int h, unsigned int k, unsigned int i, unsigned int j, unsigned int* ges, Limits limits, Single_option_representives single_option_representives, unsigned int rain, Realize_modifications_variables* rmv) {
	unsigned int ges_others, ges_difference, Feinstrukturkonstante_1, Feinstrukturkonstante_2, compact, g, how_many_ways_of_keeping, worth_of_turn;
	unsigned int* ges_average;
	unsigned int* position;
	
	Special_Fields Journey_o;	//empty field, no characterization
	Num_num num;
	Evolution evolution_copy;
	evolution_copy.nl = Spielfeld_Create (m, n, number_of_players);
	evolution_copy.od = Spielfeld_Create (m, n, number_of_players);

	Journey_o.characterization = 0;	//just for the function, it has no effect because of hayir
	Journey_o.field = Spielfeld_Create (m, n, number_of_players);
	num.bir = 0;
	num.iki = 0;
	num.uec = 0;
	g = 0;	//just for the function, it has no effect because of hayir

	how_many_ways_of_keeping = 1;

	worth_of_turn = 0;
	compact = 0;
	ges_others = 0;
	ges_difference = 0;
	ges_average = unsigned_int_Vektor_Create (number_of_players+1);
	position = unsigned_int_Vektor_Create (number_of_players+1);

	#ifdef VERBOSE
	printf("set_KI_table_of_choice ok.1\n");	//test
	#endif
	
	basic_development (Field, Field_copy, m, n, geben, Opague_o.field, Allocation_o, Sf_permutations, ges_copy, Growth_players, number_of_players, gamemode_played, information_code, level, w, d, e, exactly_number, evolution_copy, &num, &g, Journey_o, limits, single_option_representives, position, KI_decision, rain, hayir);

	if (level[geben] != Hera) {	//gamemode-specials
		realize_modifications (Qs, Moc_Schnatz, Moc_Quaffel, Moc_Klatscher, Field, Field_copy, Opague_o, Allocation_o, Sf_permutations, ges_copy, &g, m, n, geben, number_of_players, gamemode_played, level, information_code, Growth_players, Journey_o, rain, single_option_representives, rmv, hayir);
		// battle (m, n, Field_copy, geben, Opague_o.field, Allocation_o, number_of_players, gamemode_played);	// Copy from realize_modifications

	}
	#ifdef VERBOSE
	printf("set_KI_table_of_choice ok.2\n");	//test
	#endif

	if (level[geben] == Yasmin) {	//future-vision
		unsigned int person;
		unsigned int* ges_copy_save;
		Spielfeld Field_copy_save;

		ges_copy_save = unsigned_int_Vektor_Create (number_of_players+1);
		Field_copy_save = Spielfeld_Create (m, n, 0);
		person = 0;

		reset_of_ges (ges_copy, number_of_players);
		ges_counter (Field_copy, m, n, ges_copy, number_of_players);	//count ges_copy after the turn of geben.

		for (unsigned int p=0; p<=number_of_players; p++) {
			ges_copy_save[p] = ges_copy[p];
		}

		// printf("ges_copy[%u]: %u \n", geben, ges_copy[geben]);	//test

		person = Nachfolger(geben, number_of_players);
		for (unsigned int i=1; i<=m-2; i++) {
			for (unsigned int j=1; j<=n-2; j++) {
				set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field_copy_save, 0, i, j, Field_copy[0][i][j]);
			}
		}

		if ((gamemode_played == Dynamic)||(gamemode_played == Arena)||(gamemode_played == Sand)||(gamemode_played == Hunt)) {
			how_many_ways_of_keeping = 2;
		} else if ((gamemode_played == Rain)||(gamemode_played == Race)||(gamemode_played == Fight)||(gamemode_played == Fall)||(gamemode_played == Collect)||(gamemode_played == Classic)) {
			how_many_ways_of_keeping = 3;
		} else if (gamemode_played == Contact) {
			how_many_ways_of_keeping = 5;
		}

		// printf("set_KI_table_of_choice ok.3\n");	//test

		for (unsigned int p=1; p<=number_of_players-1; p++) {
			if ((ges[person] != 1010*person)&&(ges_copy[person] != 1010*person)) {
				for (unsigned int t=1; t<=how_many_ways_of_keeping; t++) {
					for (unsigned int q=Revive_; q<=Boost_; q+=10) {
						w = 3;
						d = 2;
						e = 3;

						basic_development (Field, Field_copy, m, n, person, Opague_o.field, Allocation_o, Sf_permutations, ges_copy, Growth_players, number_of_players, gamemode_played, information_code, level, w, d, e, q, evolution_copy, &num, &g, Journey_o, limits, single_option_representives, position, &t, rain, hayir);
		
						realize_modifications (Qs, Moc_Schnatz, Moc_Quaffel, Moc_Klatscher, Field, Field_copy, Opague_o, Allocation_o, Sf_permutations, ges_copy, &g, m, n, geben, number_of_players, gamemode_played, level, information_code, Growth_players, Journey_o, rain, single_option_representives, rmv, hayir);

						// battle (m, n, Field_copy, geben, Opague_o.field, Allocation_o, number_of_players, gamemode_played);	// Copy from realize_modifications

						reset_of_ges (ges_copy, number_of_players);
						ges_counter (Field_copy, m, n, ges_copy, number_of_players);
						for (unsigned int z=1; z<=number_of_players; z++) {
							if (ges_copy[z] != 1010*z) {
								ges_average[z] += ges_copy[z];
							}
						}

						reset_ges_copy (ges_copy_save, ges_copy, number_of_players);
						reset_Field_copy (Field, Field_copy_save, Field_copy, m, n, number_of_players, geben, Opague_o.field, gamemode_played, Allocation_o);	//keep the 'real' Field_copy
					}
					for (unsigned int q=50; q<=60; q+=10) {
						unsigned int* ges_compared;
						ges_compared = unsigned_int_Vektor_Create (number_of_players+1);	//look at the function
						for (unsigned int l=1; l<=2; l++) {

							reset_ges_copy (ges_copy_save, ges_copy, number_of_players);
							w = 3;
							d = 2;
							e = 3;

							if (q+l == new_4_5) {
								w = 4;
							} else if (q+l == new_2) {
								w = 2;
							} else if (q+l == max_4) {
								e = 4;
							} else if (q+l == min_1) {
								d = 1;
							}

							basic_development (Field, Field_copy, m, n, person, Opague_o.field, Allocation_o, Sf_permutations, ges_copy, Growth_players, number_of_players, gamemode_played, information_code, level, w, d, e, q+l, evolution_copy, &num, &g, Journey_o, limits, single_option_representives, position, &t, rain, hayir);

							realize_modifications (Qs, Moc_Schnatz, Moc_Quaffel, Moc_Klatscher, Field, Field_copy, Opague_o, Allocation_o, Sf_permutations, ges_copy, &g, m, n, geben, number_of_players, gamemode_played, level, information_code, Growth_players, Journey_o, rain, single_option_representives, rmv, hayir);

							// battle (m, n, Field_copy, geben, Opague_o.field, Allocation_o, number_of_players, gamemode_played);	// Copy from realize_modifications

							// printf("After the basic_development of person %u.\n", person);	//test
							// show_field (number_of_players, level, Sf_permutations, Opague_o.field, Field_copy, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);	//test

							reset_of_ges (ges_copy, number_of_players);
							ges_counter (Field_copy, m, n, ges_copy, number_of_players);

							if (l == 1) {
								for (unsigned int z=1; z<=number_of_players; z++) {
									if (ges_copy[z] != 1010*z) {
										ges_compared[z] = ges_copy[z];
									}
								}
							} else if (l == 2) {
								for (unsigned int z=1; z<=number_of_players; z++) {
									if (ges_copy[z] != 1010*z) {
										if (z == geben) {
										ges_copy[z] = minimum (ges_compared[z], ges_copy[z]);
										} else {
										ges_copy[z] = maximum (ges_compared[z], ges_copy[z]);
										}
									}
								}
							}

							reset_Field_copy (Field, Field_copy_save, Field_copy, m, n, number_of_players, geben, Opague_o.field, gamemode_played, Allocation_o);	//keep the 'real' Field_copy
						}
						for (unsigned int z=1; z<=number_of_players; z++) {
							if (ges_copy[z] != 1010*z) {
								ges_average[z] += ges_copy[z];
							}
						}

						reset_ges_copy (ges_copy_save, ges_copy, number_of_players);
						unsigned_int_Vektor_Destroy (ges_compared);
					}
				}
			}

			person = Nachfolger(person, number_of_players);

			// printf("set_KI_table_of_choice ok.3.4 p=%u \n", p);	//test
		}

		unsigned_int_Vektor_Destroy (ges_copy_save);
		Spielfeld_Destroy (Field_copy_save, m, 0);
	}
	
	#ifdef VERBOSE
	printf("set_KI_table_of_choice ok.3.5\n");	//test
	#endif

	if (level[geben] == Yasmin) {	//averages
		reset_of_ges (ges_copy, number_of_players);
		for (unsigned int p=1; p<=number_of_players; p++) {
			ges_copy[p] = ges_average[p]/(4*((number_of_players-rmv->player_counter)-1)*how_many_ways_of_keeping);		//because i hope i used 4 additions;
		}
	} else {
		reset_of_ges (ges_copy, number_of_players);
		ges_counter (Field_copy, m, n, ges_copy, number_of_players);
	}

	ges_others = 0;
	ges_others_counter (ges_copy, &ges_others, number_of_players, geben);

	#ifdef VERBOSE
	printf("set_KI_table_of_choice ok.3.7 \n");	//test
	#endif


	if ((level[geben] == Coco)&&(ges_copy[geben] >= 5)) {	//Hyperfeinstruktur
		unsigned int edges_of_organism[4], hoch, breit;	//0=oben, 1=rechts, 2=unten, 3=links
		hoch = 0;
		breit = 0;

		find_edges_of_organism_2dim (edges_of_organism, Field_copy, geben, m, n);
		hoch = edges_of_organism[2]-edges_of_organism[0]+1;
		breit = edges_of_organism[1]-edges_of_organism[3]+1;

		// printf("hoch: %u \n", hoch);	//test
		// printf("breit: %u \n", breit);	//test

		if (((hoch*breit) > 0)&&(2*15*ges_copy[geben] > 2*maximum (hoch, breit))&&(((2*15*ges_copy[geben]-2*maximum (hoch, breit))/(hoch*breit)) >= minimum (hoch, breit))) {
			compact = ((2*15*ges_copy[geben]-2*maximum (hoch, breit))/(hoch*breit)) + 1 - minimum (hoch, breit);
		} else {
			compact = 0;
		}
		// printf("KI_table_of_choice[%u]: %u \n", 5, KI_table_of_choice[5]);	//test

		// ges_copy[geben] += KI_table_of_choice[5]; //new dimension request
	} else if ((level[geben] == Liz)&&(ges_copy[geben] >= 5)) {
		if (Liz_max > 20*how_many_ways_of_keeping) {
			ges_copy[geben] = 1;
		}
	}

	if ((level[geben] == Natalie)&&(ges_copy[geben] >= 5)) {	//Feinstruktur
		Feinstrukturkonstante_1 = 3;	//mehr
		Feinstrukturkonstante_2 = 2;	//weniger
	} else {
		Feinstrukturkonstante_1 = 0;
		Feinstrukturkonstante_2 = 0;
	}

	if (ges_copy[geben] == 0) {	//Lebenserhaltende Maßnahmen
		ges_others += 50;
	}
	if (ges_others <= 1) {	//Killer-Instinkt im 1vs1
		ges_copy[geben] += 50;
	}

	ges_difference = 0;
	if (ges_copy[geben] >= ges_others) {
		ges_difference = ges_copy[geben] - ges_others;
	} else {
		ges_difference = ges_others - ges_copy[geben];
	}

	#ifdef VERBOSE
	for (unsigned int p=0; p<=4; p++) {
		printf("KI_table_of_choice[%u]: %u \n", p, KI_table_of_choice[p]);	//test
	}
	printf("ges_others: %u   ges_copy[geben]: %u   ges_difference: %u	\n", ges_others, ges_copy[geben], ges_difference);	//test

	printf("set_KI_table_of_choice ok.3.8 \n");	//test
	#endif
	
	if (gamemode_played == Collect) {
		for (unsigned int q=1; q<=number_of_players-1; q++) {
			if ((Field[0][(m-1)/2][2+q+q*(n-2-4-(number_of_players-1))/number_of_players] == To_collect)&&(Field_copy[0][(m-1)/2][2+q+q*(n-2-4-(number_of_players-1))/number_of_players] == geben)) {
				worth_of_turn += 1;
			}
		}
		if ((Field[0][(m-1)/2][2] == To_collect)&&(Field_copy[0][(m-1)/2][2] == geben)) {
			worth_of_turn += 1;
		}
		if ((Field[0][(m-1)/2][n-3] == To_collect)&&(Field_copy[0][(m-1)/2][n-3] == geben)) {
			worth_of_turn += 1;
		}
	} else if (gamemode_played == Fall) {
		for (unsigned int i=1; i<=m-2; i++) {
			for (unsigned int j=1; j<=n-2; j++) {
				if (Field_copy[0][i][j] == Fall_ball) {
					if (geben%2 == 0) {
						worth_of_turn = (n-2)-j;
					} else if (geben%2 == 1) {
						worth_of_turn = j;
					}
					break;
				}
			}
			if (worth_of_turn != 0) {
				break;
			}
		}
	} else if (gamemode_played == Hunt) {
		for (unsigned int i=1; i<=m-2; i++) {
			for (unsigned int j=1; j<=n-2; j++) {
				if (Field_copy[0][i][j] == 11) {
					worth_of_turn = 1;
					for (unsigned int p=1; p<=number_of_players; p++) {
						for (unsigned int q=0; q<=2*p-1; q++) {
							if (Field_copy[0][i-p][j-p+q] == geben) {
								worth_of_turn += number_of_players+1-p;
							}
							if (Field_copy[0][i-p+q][j+p] == geben) {
								worth_of_turn += number_of_players+1-p;
							}
							if (Field_copy[0][i+p][j+p-q] == geben) {
								worth_of_turn += number_of_players+1-p;
							}
							if (Field_copy[0][i+p-q][j-p] == geben) {
								worth_of_turn += number_of_players+1-p;
							}
							// in circles aroung the heart_block
						}
					}
					break;
				}
			}
			if (worth_of_turn != 0) {
				break;
			}
		}
	} else if (gamemode_played == Race) {
		for (unsigned int j=n-2; j>0; j--) {
			for (unsigned int i=1; i<=m-2; i++) {
				if (Field_copy[0][i][j] == geben) {
					worth_of_turn = j;
					break;
				}
			}
			if (worth_of_turn != 0) {
				break;
			}
		}
	} else if (gamemode_played == Rain) {
		for (unsigned int j=1; j<=number_of_players-1; j+=7) {
			worth_of_turn = 1;
			if (Field_copy[0][1][j] == geben) {
				worth_of_turn += 100000;
			}
			for (unsigned int p=1; p<=6; p++) {
				for (unsigned int q=0; q<=2*p-1; q++) {
					if (Field_copy[0][1+q/2][j+p] == geben) {
						worth_of_turn += number_of_players+1-p;
					}
					if (Field_copy[0][1+p][j+p-q] == geben) {
						worth_of_turn += number_of_players+1-p;
					}
					if (Field_copy[0][p-q/2][j-p] == geben) {
						worth_of_turn += number_of_players+1-p;
					}
					// in circles aroung the heart_block
				}
			}
		}
	} else if (gamemode_played == Dynamic) {
		for (unsigned int i=1; i<=m-2; i++) {
			for (unsigned int j=1; j<=n-2; j++) {
				if (Field_copy[0][i][j] == Dynamic_ball) {
					worth_of_turn = 1;
					if (geben == 1) {	//from left to right
						for (unsigned int q=1; q<=3; q++) {
							for (unsigned int p=0; p<=2*3; p++) {
								if (((j+q)<=n-2)&&((j-q)>0)&&((i-3+p)>0)&&((i-3+p)<=m-2)) {
									if (Field_copy[0][i-3+p][j-q] == geben) {
										worth_of_turn += 4-q;
									}
									if (Field_copy[0][i-3+p][j+q] == 0) {
										worth_of_turn += 4-q;
									}
								}
							}
						}
					} else if (geben == 2) {
						if ((number_of_players == 3)||(number_of_players == 4)||(number_of_players == 5)||(number_of_players == 6)||(number_of_players == 7)||(number_of_players == 8)||(number_of_players == 9)) {	//from top to bottom
							for (unsigned int q=1; q<=3; q++) {
								for (unsigned int p=0; p<=2*3; p++) {
									if (((i+q)<=m-2)&&((i-q)>0)&&((j-3+p)>0)&&((j-3+p)<=n-2)) {
										if (Field_copy[0][i-q][j-3+p] == geben) {
											worth_of_turn += 4-q;
										}
										if (Field_copy[0][i+q][j-3+p] == 0) {
											worth_of_turn += 4-q;
										}
									}
								}
							}
						} else if (number_of_players == 2) {	//from right to left
							for (unsigned int q=1; q<=3; q++) {
								for (unsigned int p=0; p<=2*3; p++) {
									if (((j+q)<=n-2)&&((j-q)>0)&&((i-3+p)>0)&&((i-3+p)<=m-2)) {
										if (Field_copy[0][i-3+p][j+q] == geben) {
											worth_of_turn += 4-q;
										}
										if (Field_copy[0][i-3+p][j-q] == 0) {
											worth_of_turn += 4-q;
										}
									}
								}
							}
						}
					} else if (geben == 4) {
						if ((number_of_players == 6)||(number_of_players == 9)) {	//from left to right
							for (unsigned int q=1; q<=3; q++) {
								for (unsigned int p=0; p<=2*3; p++) {
									if (((j+q)<=n-2)&&((j-q)>0)&&((i-3+p)>0)&&((i-3+p)<=m-2)) {
										if (Field_copy[0][i-3+p][j-q] == geben) {
											worth_of_turn += 4-q;
										}
										if (Field_copy[0][i-3+p][j+q] == 0) {
											worth_of_turn += 4-q;
										}
									}
								}
							}
						} else if ((number_of_players == 4)||(number_of_players == 5)||(number_of_players == 7)||(number_of_players == 8)) {	//from bottom to top
							for (unsigned int q=1; q<=3; q++) {
								for (unsigned int p=0; p<=2*3; p++) {
									if (((i+q)<=m-2)&&((i-q)>0)&&((j-3+p)>0)&&((j-3+p)<=n-2)) {
										if (Field_copy[0][i+q][j-3+p] == geben) {
											worth_of_turn += 4-q;
										}
										if (Field_copy[0][i-q][j-3+p] == 0) {
											worth_of_turn += 4-q;
										}
									}
								}
							}
						}
					} else if (geben == 5) {
						if ((number_of_players == 7)||(number_of_players == 8)) {	//from left to right
							for (unsigned int q=1; q<=3; q++) {
								for (unsigned int p=0; p<=2*3; p++) {
									if (((j+q)<=n-2)&&((j-q)>0)&&((i-3+p)>0)&&((i-3+p)<=m-2)) {
										if (Field_copy[0][i-3+p][j-q] == geben) {
											worth_of_turn += 4-q;
										}
										if (Field_copy[0][i-3+p][j+q] == 0) {
											worth_of_turn += 4-q;
										}
									}
								}
							}
						} else if ((number_of_players == 6)||(number_of_players == 9)) {	//from top to bottom
							for (unsigned int q=1; q<=3; q++) {
								for (unsigned int p=0; p<=2*3; p++) {
									if (((i+q)<=m-2)&&((i-q)>0)&&((j-3+p)>0)&&((j-3+p)<=n-2)) {
										if (Field_copy[0][i-q][j-3+p] == geben) {
											worth_of_turn += 4-q;
										}
										if (Field_copy[0][i+q][j-3+p] == 0) {
											worth_of_turn += 4-q;
										}
									}
								}
							}
						} else if (number_of_players == 5) {	//from bottom to top
							for (unsigned int q=1; q<=3; q++) {
								for (unsigned int p=0; p<=2*3; p++) {
									if (((i+q)<=m-2)&&((i-q)>0)&&((j-3+p)>0)&&((j-3+p)<=n-2)) {
										if (Field_copy[0][i+q][j-3+p] == geben) {
											worth_of_turn += 4-q;
										}
										if (Field_copy[0][i-q][j-3+p] == 0) {
											worth_of_turn += 4-q;
										}
									}
								}
							}
						}
					} else if (geben == 6) {
						if ((number_of_players == 6)||(number_of_players == 8)) {	//from top to bottom
							for (unsigned int q=1; q<=3; q++) {
								for (unsigned int p=0; p<=2*3; p++) {
									if (((i+q)<=m-2)&&((i-q)>0)&&((j-3+p)>0)&&((j-3+p)<=n-2)) {
										if (Field_copy[0][i-q][j-3+p] == geben) {
											worth_of_turn += 4-q;
										}
										if (Field_copy[0][i+q][j-3+p] == 0) {
											worth_of_turn += 4-q;
										}
									}
								}
							}
						} else if ((number_of_players == 7)||(number_of_players == 9)) {	//from right to left
							for (unsigned int q=1; q<=3; q++) {
								for (unsigned int p=0; p<=2*3; p++) {
									if (((j+q)<=n-2)&&((j-q)>0)&&((i-3+p)>0)&&((i-3+p)<=m-2)) {
										if (Field_copy[0][i-3+p][j+q] == geben) {
											worth_of_turn += 4-q;
										}
										if (Field_copy[0][i-3+p][j-q] == 0) {
											worth_of_turn += 4-q;
										}
									}
								}
							}
						}
					} else if (geben == 7) {
						if (number_of_players == 9) {	//from left to right
							for (unsigned int q=1; q<=3; q++) {
								for (unsigned int p=0; p<=2*3; p++) {
									if (((j+q)<=n-2)&&((j-q)>0)&&((i-3+p)>0)&&((i-3+p)<=m-2)) {
										if (Field_copy[0][i-3+p][j-q] == geben) {
											worth_of_turn += 4-q;
										}
										if (Field_copy[0][i-3+p][j+q] == 0) {
											worth_of_turn += 4-q;
										}
									}
								}
							}
						} else if (number_of_players == 8) {	//from right to left
							for (unsigned int q=1; q<=3; q++) {
								for (unsigned int p=0; p<=2*3; p++) {
									if (((j+q)<=n-2)&&((j-q)>0)&&((i-3+p)>0)&&((i-3+p)<=m-2)) {
										if (Field_copy[0][i-3+p][j+q] == geben) {
											worth_of_turn += 4-q;
										}
										if (Field_copy[0][i-3+p][j-q] == 0) {
											worth_of_turn += 4-q;
										}
									}
								}
							}
						} else if (number_of_players == 7) {	//from bottom to top
							for (unsigned int q=1; q<=3; q++) {
								for (unsigned int p=0; p<=2*3; p++) {
									if (((i+q)<=m-2)&&((i-q)>0)&&((j-3+p)>0)&&((j-3+p)<=n-2)) {
										if (Field_copy[0][i+q][j-3+p] == geben) {
											worth_of_turn += 4-q;
										}
										if (Field_copy[0][i-q][j-3+p] == 0) {
											worth_of_turn += 4-q;
										}
									}
								}
							}
						}
					} else if (geben == 8) {
						if (number_of_players == 9) {	//from top to bottom
							for (unsigned int q=1; q<=3; q++) {
								for (unsigned int p=0; p<=2*3; p++) {
									if (((i+q)<=m-2)&&((i-q)>0)&&((j-3+p)>0)&&((j-3+p)<=n-2)) {
										if (Field_copy[0][i-q][j-3+p] == geben) {
											worth_of_turn += 4-q;
										}
										if (Field_copy[0][i+q][j-3+p] == 0) {
											worth_of_turn += 4-q;
										}
									}
								}
							}
						} else if (number_of_players == 8) {	//from bottom to top
							for (unsigned int q=1; q<=3; q++) {
								for (unsigned int p=0; p<=2*3; p++) {
									if (((i+q)<=m-2)&&((i-q)>0)&&((j-3+p)>0)&&((j-3+p)<=n-2)) {
										if (Field_copy[0][i+q][j-3+p] == geben) {
											worth_of_turn += 4-q;
										}
										if (Field_copy[0][i-q][j-3+p] == 0) {
											worth_of_turn += 4-q;
										}
									}
								}
							}
						}
					} else if (geben == 9) {	//from right to left
						for (unsigned int q=1; q<=3; q++) {
							for (unsigned int p=0; p<=2*3; p++) {
								if (((j+q)<=n-2)&&((j-q)>0)&&((i-3+p)>0)&&((i-3+p)<=m-2)) {
									if (Field_copy[0][i-3+p][j+q] == geben) {
										worth_of_turn += 4-q;
									}
									if (Field_copy[0][i-3+p][j-q] == 0) {
										worth_of_turn += 4-q;
									}
								}
							}
						}
					}
					break;
				}
			}
			if (worth_of_turn != 0) {
				break;
			}
		}
	} else if (gamemode_played == Sand) {
		for (unsigned int i=1; i<=m-2; i++) {
			for (unsigned int j=1; j<=n-2; j++) {
				if (Field_copy[0][i][j] == geben) {
					worth_of_turn = m-2-i;
					break;
				}
			}
			if (worth_of_turn != 0) {
				break;
			}
		}
	}
	
	if (((KI_table_of_choice[0] == 0)||((ges_copy[geben] >= ges_others)&&((KI_table_of_choice[3] == daha_fazla_degil)||(ges_difference > KI_table_of_choice[4]+Feinstrukturkonstante_1)))||((ges_copy[geben] < ges_others)&&(ges_difference+Feinstrukturkonstante_2 < KI_table_of_choice[4])&&(KI_table_of_choice[3] == daha_fazla_degil))||((level[geben] == Jill)&&(ges_others < KI_table_of_choice[7]))||((level[geben] == Coco)&&(compact > KI_table_of_choice[7]+2)))&&(worth_of_turn >= KI_table_of_choice[6])&&((level[geben] != Uma)||((level[geben] == Uma)&&(accepted_or_not(exactly_number, ges, geben, how_many_ways_of_keeping) == evet)))) {
		update_KI_table_of_choice (KI_table_of_choice, exactly_number, h, k, i, j, ges_copy, ges_others, ges_difference, KI_decision, worth_of_turn, geben, level, compact);
	}
	
	#ifdef VERBOSE
	printf("set_KI_table_of_choice ok.4 \n");	//test
	#endif
	
	// for (unsigned int p=0; p<=4; p++) {
		// printf("KI_table_of_choice[%u]: %u \n", p, KI_table_of_choice[p]);	//test
	// }
	// printf("\n");	//test
	if (level[geben] == Liz) {
		Liz_max += 1;
	}

	synchronisation_Field_copy (Field, Field_copy, m, n, number_of_players, geben, Opague_o.field, gamemode_played, Allocation_o);
	synchronisation_ges_copy (ges_copy, number_of_players, ges);

	Spielfeld_Destroy (evolution_copy.nl, m, number_of_players);
	Spielfeld_Destroy (evolution_copy.od, m, number_of_players);
	Spielfeld_Destroy (Journey_o.field, m, number_of_players);
	unsigned_int_Vektor_Destroy (ges_average);
	unsigned_int_Vektor_Destroy (position);
	
	#ifdef VERBOSE
	printf("set_KI_table_of_choice ok.5 \n");	//test
	#endif

}

void update_KI_table_of_choice (unsigned int* KI_table_of_choice, unsigned int exactly_number, unsigned int h, unsigned int k, unsigned int i, unsigned int j, unsigned int* ges_copy, unsigned int ges_others, unsigned int ges_difference, unsigned int* KI_decision, unsigned int worth_of_turn, unsigned int geben, unsigned int* level, unsigned int compact) {
	
	// printf("update_KI_table_of_choice ok.1 \n");	//test

	KI_table_of_choice[0] = exactly_number;

	if ((exactly_number == Plus_)||(exactly_number == Destroy_)) {
		KI_table_of_choice[1] = 0;			//own squares
		KI_table_of_choice[2] = 100*h+k;	//other squares
	
	} else if (exactly_number == Minus_) {
		KI_table_of_choice[1] = 100*i+j;
		KI_table_of_choice[2] = 0;
	
	} else if ((exactly_number == Move_2)||(exactly_number == Change_)||(exactly_number == Move_4)) {
		KI_table_of_choice[1] = 100*i+j;
		KI_table_of_choice[2] = 100*h+k;
	
	} else if ((exactly_number == Revive_)||(exactly_number == Boost_)||(exactly_number == new_2)||(exactly_number == new_4_5)||(exactly_number == min_1)||(exactly_number == max_4)) {
		KI_table_of_choice[1] = 0;
		KI_table_of_choice[2] = 0;
	
	}

	if (ges_copy[geben] >= ges_others) {
		KI_table_of_choice[3] = daha_fazla;
	} else {
		KI_table_of_choice[3] = daha_fazla_degil;
	}

	KI_table_of_choice[4] = ges_difference;
	KI_table_of_choice[5] = *KI_decision;

	KI_table_of_choice[6] = worth_of_turn;

	if (level[geben] == Jill) {
		KI_table_of_choice[7] = ges_others;
	} else if (level[geben] == Coco) {
		KI_table_of_choice[7] = compact;
	}

	// printf("update_KI_table_of_choice ok.2 \n");	//test
	
}
	
void basic_development (Spielfeld Field, Spielfeld Spiel, unsigned int m, unsigned int n, unsigned int geben, Spielfeld Opague_o_field, Special_Fields Allocation_o, Spielfeld Sf_permutations, unsigned int* ges_copy, Growth_Player* Growth_players, unsigned int number_of_players, unsigned int gamemode_played, unsigned int* information_code, unsigned int* level, unsigned int w, unsigned int d, unsigned int e, unsigned int exactly_number, Evolution evolution, Num_num* num, unsigned int* g, Special_Fields Journey_o, Limits limits, Single_option_representives single_option_representives, unsigned int* position, unsigned int* KI_decision, unsigned int rain, unsigned int real) {
	Spielfeld temp;
	unsigned int boost_hunt_activator, precounter;	//Hunt
	unsigned int ent, count_new;	// imitates limits, counts the squares
	unsigned int zeitgewinner;	//if you can't hold anything, you are winning time

	ent = 0;
	count_new = 0;
	zeitgewinner = 0;

	boost_hunt_activator = 0;
	precounter = 0;
	temp = Spielfeld_Create (m, n, 0);

	if (exactly_number == Boost_) {
		if ((gamemode_played == Hunt)&&(geben == 1)) {
			boost_hunt_activator = 1;
		} else {
			Boost (Spiel, geben, Field, m, n, temp, gamemode_played, Opague_o_field, Allocation_o, number_of_players);
		}
	}

	#ifdef VERBOSE
	printf("basic_development ok.1\n");	//test
	#endif

	new_life (Spiel, Field, m, n, w, gamemode_played, information_code, geben, evolution, Opague_o_field, Allocation_o, number_of_players);

	num->bir = 0;
	for (unsigned int i=1; i<m-1; i+=1){
		for (unsigned int j=1; j<n-1; j+=1){
			if (evolution.nl[geben][i][j] == geben){
				num->bir += 1;
			}
		}
	}

	// printf("basic_development ok.1.1\n");	//test

	if ((gamemode_played != Hunt)||(geben != 1)) {	//wegen hunted one, if (geben != 1)
		if (exactly_number == Boost_){
			for (unsigned int i=1; i<m-1; i+=1){
				for (unsigned int j=1; j<n-1; j+=1){
					if (gamemode_played == Rain) {
						if (temp[0][i][j] == Raindrop){
							set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j, 0);
						}
					} else {
						if (temp[0][i][j] != 0){
							set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j, temp[0][i][j]);
						}
					}
				}
			}
		}
	}

	if (real == evet) {
		if (gamemode_played == Hunt) {
			precounter = 0;
			for (unsigned int i=1; i<m-1; i+=1){
				for (unsigned int j=1; j<n-1; j+=1){
					if (Field[0][i][j] == 11){
						if (evolution.nl[geben][i][j-1] > 1) {
							printf (" Sieg: Spieler %u \n", evolution.nl[geben][i][j-1]);
							precounter += 1;
						}
						if (evolution.nl[geben][i][j+1] > 1) {
							if (precounter == 0) {
								printf (" Sieg: Spieler %u \n", evolution.nl[geben][i][j+1]);
							}
							precounter += 1;
						}
						if (evolution.nl[geben][i-1][j] > 1) {
							if (precounter == 0) {
								printf (" Sieg: Spieler %u \n", evolution.nl[geben][i-1][j]);
							}
							precounter += 1;
						}
						if (evolution.nl[geben][i+1][j] > 1) {
							if (precounter == 0) {
								printf (" Sieg: Spieler %u \n", evolution.nl[geben][i+1][j]);
							}
							precounter += 1;
						}
						if (precounter == 2) {
							printf(" Double-catch! \n");
						}
						if (precounter == 3) {
							printf(" TRIPLE-catch!! \n");
						}
						if (precounter == 4) {
							printf(" QUADRO-CATCH!!! \n");
						}
						break;
					}
				}
				if (precounter > 0) {
					break;
				}
			}
			if (precounter > 0) {
				for (unsigned int i=1; i<m-1; i+=1){
					for (unsigned int j=1; j<n-1; j+=1){
						if (evolution.nl[geben][i][j] == geben) {
							set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, i, j, geben);
						}
					}
				}
				show_field (number_of_players, level, Sf_permutations, Opague_o_field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
				*g = 0;
			}
		}
	}

	// printf("basic_development ok.1.2\n");	//test

	Spielfeld_Destroy (temp, m, 0); // ab jetzt nicht mehr verwendbar

	// printf("basic_development ok.2\n");	//test

	old_dying (Spiel, Field, m, n, d, e, gamemode_played, information_code, geben, evolution.od, w, Allocation_o, Opague_o_field, number_of_players);

	if ((boost_hunt_activator == 1)&&(gamemode_played == Hunt)&&(geben == 1)) {
		for (unsigned int i=1; i<m-1; i+=1){
			for (unsigned int j=1; j<n-1; j+=1){
				if (Spiel[0][i][j] == 11){
					set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, evolution.od, geben, i-1, j, 0);
					set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, evolution.od, geben, i, j-1, 0);
					set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, evolution.od, geben, i+1, j, 0);
					set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, evolution.od, geben, i, j+1, 0);

					boost_hunt_activator = 0;
					break;	//because i found the unique value
				}
			}
			if (boost_hunt_activator == 0) {
				break;	//because i found the unique value
			}
		}
	}

	if (real == evet) {
		if (Journey_o.characterization != 0){
			unsigned int journey_max, temp_limits_at_all;
			journey_max = 0;
			temp_limits_at_all = 0;

			if (limits.at_all == 0) {
				limits.at_all = 25;
				temp_limits_at_all = 1;
			}

			for (unsigned int i=1; i<m-1; i+=1){
				for (unsigned int j=1; j<n-1; j+=1){
					if (Journey_o.field[0][i][j] == geben){
						journey_max += 1;
					}
				}
			}

			// printf("Spieler %u: %u Steine in Journey_o.field \n", geben, journey_max);	//test

			for (unsigned int i=1; i<m-1; i+=1){
				for (unsigned int j=1; j<n-1; j+=1){
					if ((evolution.od[geben][i][j] == 101*geben) && (Journey_o.field[0][i][j] == 0) && (journey_max >= limits.at_all)){

						// show_field (number_of_players, level, Sf_permutations, Opague_o_field, Journey_o.field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);	//test

						for (unsigned int p=0; p<=1; p++) {
							for (unsigned int q=0; q<=(((minimum(m, n)-2)-1)/2)*2; q++) {
								if (q%2 == 0) {
									for (unsigned int o=1+(q/2); o<(n-1)-(q/2); o+=1){
										if ((Journey_o.field[0][1+(q/2)][o] == geben)&&((1+(q/2)+o)%2 == p)){
											set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Journey_o.field, 0, 1+(q/2), o, 0);
											journey_max -= 1;
											if (journey_max < limits.at_all){
												break;
											}
										}
										if ((Journey_o.field[0][(m-2)-(q/2)][o] == geben)&&(((m-2)-(q/2)+o)%2 == p)){
											set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Journey_o.field, 0, (m-2)-(q/2), o, 0);
											journey_max -= 1;
											if (journey_max < limits.at_all){
												break;
											}
										}
									}
								} else if (q%2 == 1) {
									for (unsigned int u=1+((q+1)/2); u<(m-1)-((q+1)/2); u+=1){
										if ((Journey_o.field[0][u][1+(q/2)] == geben)&&((1+(q/2)+u)%2 == p)){
											set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Journey_o.field, 0, u, 1+(q/2), 0);
											journey_max -= 1;
											if (journey_max < limits.at_all){
												break;
											}
										}
										if ((Journey_o.field[0][u][(n-2)-(q/2)] == geben)&&(((n-2)-(q/2)+u)%2 == p)){
											set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Journey_o.field, 0, u, (n-2)-(q/2), 0);
											journey_max -= 1;
											if (journey_max < limits.at_all){
												break;
											}
										}
									}
								}
								if (journey_max < limits.at_all){
									break;
								}
							}
							if (journey_max < limits.at_all){
								break;
							}
						}
					}
					if ((evolution.od[geben][i][j] == 101*geben) && (Journey_o.field[0][i][j] == 0) && (journey_max < limits.at_all)){
						set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Journey_o.field, 0, i, j, geben);
						journey_max += 1;
					}
				}
			}

			// printf("Spieler %u: %u Steine in Journey_o.field \n", geben, journey_max);	//test

			journey_max = 0;

			if (temp_limits_at_all == 1) {
				limits.at_all = 0;
			}
		}
	}

	if (exactly_number == Revive_) {
		Revive (Spiel, m, n, evolution.od, Field, geben, Allocation_o, Opague_o_field, number_of_players, gamemode_played);
	}

	num->iki = 0;
	for (unsigned int i=1; i<m-1; i+=1){
		for (unsigned int j=1; j<n-1; j+=1){
			if (evolution.od[geben][i][j] == 101*geben){
				num->iki += 1;
			}
		}
	}

	count_new = 0;

	for (unsigned int i=1; i<m-1; i+=1){
		for (unsigned int j=1; j<n-1; j+=1){
			if (evolution.nl[geben][i][j] == geben){
				count_new += 1;
			}
		}
	}

	ent = limits.new;

	for (unsigned int i=1; i<m-1; i+=1){
		for (unsigned int j=1; j<n-1; j+=1){
			if ((Spiel[0][i][j] == geben) && (evolution.od[geben][i][j] == 0)){
				zeitgewinner += 1;
			}
		}
	}

	//printf("	ent: %u \n ", ent);
	if ((gamemode_played == Hunt)&&(geben == 1)) {
		ent = (ent + (number_of_players-3));
	}

	if ((count_new > limits.new)&&(single_option_representives.inverted == 0)&&(single_option_representives.addition == 0)&&(single_option_representives.intensity_loss_per_line_multiplication == 0)){		//Abfrage auf max. limits.new neue Steine,
		if ((gamemode_played != Ulcer)&&(gamemode_played != Survive)) {
			Having_too_much (KI_decision, ent, count_new, m, n, evolution, limits, zeitgewinner, Spiel, w, d, e, geben, position, gamemode_played, number_of_players, rain, Opague_o_field, Allocation_o, level, real);
		} else {
			count_new = 0;
		}

	}
	ent = 0;
	count_new = 0;

	num->uec = 0;
	for (unsigned int i=1; i<m-1; i+=1){
		for (unsigned int j=1; j<n-1; j+=1){
			if (((Spiel[0][i][j] == geben) && (((evolution.od[geben][i][j] == 0)&&(Allocation_o.characterization == 0))||(Allocation_o.field[0][i][j] > Allocation_o.field[1][i][j]))) || (evolution.nl[geben][i][j] == geben)){
				count_new += 1;
				num->uec += 1;
			}
		}
	}

	if ((gamemode_played == Hunt)&&(geben == 1)) {	//count the heart, if geben == 1
		count_new += 1;
		num->uec += 1;
	}

	ent = limits.at_all;

	if ((gamemode_played == Hunt)&&(geben == 1)) {
		ent = (ent + 2* (number_of_players-3));
	}

	if ((count_new > ent)&&(single_option_representives.inverted == 0)&&(single_option_representives.addition == 0)&&(single_option_representives.intensity_loss_per_line_multiplication == 0)){		//Abfrage auf insgesamt max. limits.at_all Steine
		if ((gamemode_played != Contact)&&(gamemode_played != Ulcer)&&(gamemode_played != Survive)) {
			Having_too_much (KI_decision, ent, count_new, m, n, evolution, limits, zeitgewinner, Spiel, w, d, e, geben, position, gamemode_played, number_of_players, rain, Opague_o_field, Allocation_o, level, real);
		} else {
			count_new = 0;
		}

	}

	zeitgewinner = 0;
	ent = 0;

	if (gamemode_played == Fall) {
		touch (Spiel, m, n, geben, evolution.nl, Allocation_o, Opague_o_field, number_of_players, gamemode_played);
	}

	// printf("basic_development ok.3\n");	//test

	change (Spiel, level, Sf_permutations, Field, evolution, m, n, gamemode_played, number_of_players, ges_copy, geben, Allocation_o, Opague_o_field, information_code, Growth_players, single_option_representives);

	#ifdef VERBOSE
	printf("basic_development ok.4\n");	//test
	#endif

}

void ges_others_counter (unsigned int* ges_copy, unsigned int* ges_others, unsigned int number_of_players, unsigned int geben) {
	unsigned int count_players;

	count_players = 0;
	// printf("ges_others: %u \n", *ges_others);	//test

	for (unsigned int p=1; p<=number_of_players; p++) {
		if ((p != geben)&&(ges_copy[p] != 1010*p)) {
			count_players += 1;
			*ges_others += ges_copy[p];
		}
	}
	if (count_players != 0) {
		*ges_others = (*ges_others)/count_players;
	} else {
		*ges_others = 0;
	}

	// printf("ges_others_counter ok.1\n");	//test
}

void synchronisation_Field_copy (Spielfeld Field, Spielfeld Field_copy, unsigned int m, unsigned int n, unsigned int number_of_players, unsigned int geben, Spielfeld Opague_o_field, unsigned int gamemode_played, Special_Fields Allocation_o) {

	// printf("synchronisation_Field_copy ok.1\n");	//test

	for (unsigned int i=1; i<=m-2; i++) {
		for (unsigned int j=1; j<=n-2; j++) {
			set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field_copy, 0, i, j, Field_copy[1][i][j]);
		}
	}
}

void synchronisation_Test_field (Spielfeld Test_field, unsigned int m, unsigned int n, unsigned int to, unsigned int from) {

	// printf("synchronisation_Test_field ok.1\n");	//test

	for (unsigned int i=1; i<=m-2; i++) {
		for (unsigned int j=1; j<=n-2; j++) {
			Test_field[to][i][j] = Test_field[from][i][j];
		}
	}
}

void reset_Field_copy (Spielfeld Field, Spielfeld Field_copy_save, Spielfeld Field_copy, unsigned int m, unsigned int n, unsigned int number_of_players, unsigned int geben, Spielfeld Opague_o_field, unsigned int gamemode_played, Special_Fields Allocation_o) {

	// printf("reset_Field_copy ok.1\n");	//test

	for (unsigned int i=1; i<=m-2; i++) {
		for (unsigned int j=1; j<=n-2; j++) {
			set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field_copy, 0, i, j, Field_copy_save[0][i][j]);
		}
	}
}

void synchronisation_ges_copy (unsigned int* ges_copy, unsigned int number_of_players, unsigned int* ges) {
	// printf("reset_ges_copy ok.1\n");	//test
	for (unsigned int p=0; p<=number_of_players; p++) {
		ges_copy[p] = ges[p];
	}
}

void reset_ges_copy (unsigned int* ges_copy_save, unsigned int* ges_copy, unsigned int number_of_players) {
	// printf("reset_ges_copy ok.1\n");	//test
	for (unsigned int p=0; p<=number_of_players; p++) {
		ges_copy[p] = ges_copy_save[p];
	}
}

void dimension_of (unsigned int* level, unsigned int* dimension, unsigned int geben) {

	// printf("dimension_of ok.1\n");	//test

	if ((level[geben] == Coco)||(level[geben] == Jill)) {
		*dimension = 8;
	} else {
		*dimension = 7;
	}
}

void is_it_necessary (unsigned int* level, unsigned int* ges, unsigned int* necessary, unsigned int geben, unsigned int number_of_players) {
	if (ges[Nachfolger(geben, number_of_players)] == 1010*Nachfolger(geben, number_of_players)) {
		is_it_necessary (level, ges, necessary, Nachfolger(geben, number_of_players), number_of_players);
	} else if (level[Nachfolger(geben, number_of_players)] != human) {
		*necessary = 1;
	}
}

void find_edges_of_organism_2dim (unsigned int* edges_of_organism, Spielfeld Spiel, unsigned int geben, unsigned int m, unsigned int n) {
	for (unsigned int p=0; p<=3; p++) {
		edges_of_organism[p] = 0;
	}

	for (unsigned int i=1; i<=m-2; i++) {
		for (unsigned int j=1; j<=n-2; j++) {
			if (Spiel[0][i][j] == geben) {
				edges_of_organism[0] = i;
				edges_of_organism[1] = j;
				edges_of_organism[2] = i;
				edges_of_organism[3] = j;
				break;
			}
		}
		if (edges_of_organism[0] != 0) {
			break;
		}
	}

	for (unsigned int i=1; i<=m-2; i++) {
		for (unsigned int j=1; j<=n-2; j++) {
			if (Spiel[0][i][j] == geben) {
				if (i<edges_of_organism[0]) {
					edges_of_organism[0] = i;
				} else if (i>edges_of_organism[2]) {
					edges_of_organism[2] = i;
				}
				if (j>edges_of_organism[1]) {
					edges_of_organism[1] = j;
				} else if (j<edges_of_organism[3]) {
					edges_of_organism[3] = j;
				}
			}
		}
	}
}

void decision_max_maker (unsigned int gamemode_played, unsigned int geben, unsigned int* decision_max) {	//mehr-gamemode_played
	if ((gamemode_played == Dynamic)||(gamemode_played == Arena)||(gamemode_played == Sand)) {
		*decision_max = 2;
	} else if ((gamemode_played == Hunt)&&(geben != 1)) {
		*decision_max = 2;
	} else if ((gamemode_played == Rain)||(gamemode_played == Race)||(gamemode_played == Fight)||(gamemode_played == Fall)||(gamemode_played == Collect)) {
		*decision_max = 3;
	} else if (gamemode_played == Contact) {
		*decision_max = 5;
	} else if (gamemode_played == Classic) {
		*decision_max = 3;
	}
}

unsigned int accepted_or_not (unsigned int number, unsigned int* ges, unsigned int geben, unsigned int how_many_ways_of_keeping) {
	unsigned int approx_n, answer;

	approx_n = 0;
	answer = 0;
	
	#ifdef VERBOSE
	printf("accepted_or_not ok.1 \n");	//test
	#endif
	
	if ((number/10 == 3)||(number/10 == 5)||(number/10 == 6)) {
		approx_n = 2*how_many_ways_of_keeping*how_many_ways_of_keeping;
	} else if (number/10 == 1) {
		approx_n = (7*ges[geben]+1)*how_many_ways_of_keeping*how_many_ways_of_keeping;
	} else if ((number/10 == 2)||(number/10 == 4)) {
		approx_n = (3*ges[geben]+1)*how_many_ways_of_keeping*how_many_ways_of_keeping;
	}

	answer = Zufall(1, approx_n);

	if (1.0*answer <= sqrt(approx_n)) {
		answer = evet;
	} else {
		answer = hayir;
	}

	// printf("Accepted number %u:	%u \n", number, answer);	//test
	// printf("approx_n %u:	\n", approx_n);

	#ifdef VERBOSE
	printf("accepted_or_not ok.2 \n");	//test
	#endif
	return answer;
}

void Time_for_a_Tutorial (unsigned int AOP, unsigned int* level, unsigned int* information_code, unsigned int* position, Growth_Player* Growth_players) {

	unsigned int m, n, w, d, e, geben, number_of_players, input, 	gamemode_played, rain, g;
	Limits limits;	//just a copy
	unsigned int ges[AOP+1];
	unsigned int* KI_decision;
	Spielfeld Test_field;
	Special_Fields Test_special_fields;
	Single_option_representives test_single_options;
	Evolution evolution;
	Num_num num;

	w = 3;
	d = 2;
	e = 3;
	m = 10;
	n = 10;
	geben = 1;
	number_of_players = 2;
	input = 0;
	gamemode_played = Tutorial;
	limits.at_all = 100;
	limits.new = 100;
	rain = 0;
	num.bir = 0;
	num.iki = 0;
	num.uec = 0;
	g = 0;
	Test_special_fields.characterization = 0;
	test_single_options.undead_duration = 0;
	test_single_options.inverted = 0;
	test_single_options.addition = 0;
	test_single_options.intensity_loss_per_line_multiplication = 0;
	
	KI_decision = unsigned_int_Vektor_Create (1);
	Test_field = Spielfeld_Create (m, n, 1);
	evolution.nl = Spielfeld_Create (m, n, number_of_players);
	evolution.od = Spielfeld_Create (m, n, number_of_players);
	Test_special_fields.field = Spielfeld_Create (m, n, number_of_players+2);;
	
	for (unsigned int p=0; p<=AOP; p++) {
		ges[p] = 1;
	}

	start_normal (Test_field, m, n, gamemode_played, number_of_players, geben, Test_field, Test_special_fields, 0);
	synchronisation_Test_field (Test_field, m, n, 1, 0);

	input = 1;
	while (input != 0) {
		printf("	At first you need to type a zero (0) and click 'Enter' to get to the next step of the Tutorial. The signal for doing this is '?0?' at the end of the text.	?0?\n");
		input = get_unsigned_numeric_input_with_not_more_than_1_letter ();
		printf(" \n");
	}

	input = 1;
	while (input != 0) {
		printf("	The game is played in rounds on a field of squares. A square can be owned by a player or be dead. At the beginning of each game you get a couple of squares you own.	?0?\n");
		input = get_unsigned_numeric_input_with_not_more_than_1_letter ();
		printf(" \n");
	}

	input = 1;
	while (input != 0) {
		printf("	If it is your turn, you can improve the situation of your squares by using actions. \n	Normally you can choose between two options, but in this Tutorial we only learn what these options can do.	?0?\n");
		input = get_unsigned_numeric_input_with_not_more_than_1_letter ();
		printf(" \n");
	}

	input = 1;
	while (input != 0) {
		printf("	After making a decision, your organism of squares will evolve in the following way: Every dead squares with exactly 3 of your squares in its surrounding of 8 squares will be owned by you. \n	Every square of yours having less than 2 or more than 3 own squares in its surrounding will turn into a dead square. \n	There are no effects between the single steps of evolving. \n	Let's have a look on the field we are working with...	?0?\n");
		input = get_unsigned_numeric_input_with_not_more_than_1_letter ();
		printf(" \n");
	}

	show_field (number_of_players, level, Test_field, Test_field, Test_field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Test_special_fields);

	input = 1;
	while (input != 0) {
		printf("	If you get asked for the position of a square you are interacting with, you write at first the line (yy) and than the other component of its position (xx). \n	If a part of the position is just a single letter, than you write a zero before the letter. \n	After that you click 'Enter'. \n	For example the squares of player 2 would be called 0401, 0402, 0501, 0502.	?0?\n");
		input = get_unsigned_numeric_input_with_not_more_than_1_letter ();
		printf(" \n");
	}

	input = 1;
	while (input != 0) {
		printf("	Well, now you are prepared for a match. The word before every new comment is the name of the action you will use.	?0?\n");
		input = get_unsigned_numeric_input_with_not_more_than_1_letter ();
		printf(" \n");
	}

	input = 1;
	while (input != 0) {
		show_field (number_of_players, level, Test_field, Test_field, Test_field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Test_special_fields);
		printf("	Plus: Set a square on 0405.\n");

		Plus (level, Test_field, m, n, geben, Test_field, limits.at_all, gamemode_played, information_code, number_of_players, Growth_players, Test_special_fields, Test_special_fields);

		if (Test_field[0][4][5] != geben) {
			input = 1;
			synchronisation_Test_field (Test_field, m, n, 0, 1);
		} else {
			input = 0;
		}
	}
	basic_development (Test_field, Test_field, m, n, geben, Test_field, Test_special_fields, Test_field, ges, Growth_players, number_of_players, gamemode_played, information_code, level, w, d, e, Plus_, evolution, &num, &g, Test_special_fields, limits, test_single_options, position, KI_decision, rain, hayir);
	synchronisation_Test_field (Test_field, m, n, 1, 0);

	input = 1;
	while (input != 0) {
		show_field (number_of_players, level, Test_field, Test_field, Test_field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Test_special_fields);
		printf("	Minus: Delete your square on 0605.\n");

		Minus (level, Test_field, m, n, geben, Test_field, gamemode_played, information_code, Growth_players, Test_special_fields, Test_special_fields, number_of_players);

		if (Test_field[0][6][5] != 0) {
			input = 1;
			synchronisation_Test_field (Test_field, m, n, 0, 1);
		} else {
			input = 0;
		}
	}
	basic_development (Test_field, Test_field, m, n, geben, Test_field, Test_special_fields, Test_field, ges, Growth_players, number_of_players, gamemode_played, information_code, level, w, d, e, Minus_, evolution, &num, &g, Test_special_fields, limits, test_single_options, position, KI_decision, rain, hayir);
	synchronisation_Test_field (Test_field, m, n, 1, 0);

	input = 1;
	while (input != 0) {
		show_field (number_of_players, level, Test_field, Test_field, Test_field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Test_special_fields);
		printf("	Move: Move your square on 0605 to 0604.\n");

		Move (level, Test_field, m, n, geben, Test_field, gamemode_played, information_code, Growth_players, Test_special_fields, Test_special_fields, number_of_players);

		if ((Test_field[0][6][5] != 0)||(Test_field[0][6][4] != geben)) {
			input = 1;
			synchronisation_Test_field (Test_field, m, n, 0, 1);
		} else {
			input = 0;
		}
	}
	basic_development (Test_field, Test_field, m, n, geben, Test_field, Test_special_fields, Test_field, ges, Growth_players, number_of_players, gamemode_played, information_code, level, w, d, e, Move_2, evolution, &num, &g, Test_special_fields, limits, test_single_options, position, KI_decision, rain, hayir);
	synchronisation_Test_field (Test_field, m, n, 1, 0);

	input = 1;
	while (input != 0) {
		show_field (number_of_players, level, Test_field, Test_field, Test_field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Test_special_fields);
		printf("	Change: Change your square on 0503 with the square of the enemy on 0502.\n");

		Change (level, Test_field, m, n, geben, Test_field, gamemode_played, information_code, Growth_players,Test_special_fields, position, Test_special_fields, number_of_players);

		if ((Test_field[0][5][2] != geben)||(Test_field[0][5][3] != 2)) {
			input = 1;
			synchronisation_Test_field (Test_field, m, n, 0, 1);
		} else {
			input = 0;
		}
	}
	basic_development (Test_field, Test_field, m, n, geben, Test_field, Test_special_fields, Test_field, ges, Growth_players, number_of_players, gamemode_played, information_code, level, w, d, e, Change_, evolution, &num, &g, Test_special_fields, limits, test_single_options, position, KI_decision, rain, hayir);
	synchronisation_Test_field (Test_field, m, n, 1, 0);

	input = 1;
	while (input != 0) {
		show_field (number_of_players, level, Test_field, Test_field, Test_field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Test_special_fields);
		printf("	Destroy: Destroy the square of the enemy on 0503.\n");

		Destroy (level, Test_field, m, n, geben, Test_field, gamemode_played, information_code, Growth_players, Test_special_fields, Test_special_fields, number_of_players);

		if (Test_field[0][5][3] != 0) {
			input = 1;
			synchronisation_Test_field (Test_field, m, n, 0, 1);
		} else {
			input = 0;
		}
	}
	basic_development (Test_field, Test_field, m, n, geben, Test_field, Test_special_fields, Test_field, ges, Growth_players, number_of_players, gamemode_played, information_code, level, w, d, e, Destroy_, evolution, &num, &g, Test_special_fields, limits, test_single_options, position, KI_decision, rain, hayir);
	synchronisation_Test_field (Test_field, m, n, 1, 0);

	input = 1;
	while (input != 0) {
		show_field (number_of_players, level, Test_field, Test_field, Test_field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Test_special_fields);
		printf("	Boost: The next action of you will be a Boost, \n	that means the squares of the enemy which are touching you with at least one full side will count as your own squares according to the development, not for the decision which squares of yours have to die.	?0?\n");
		input = get_unsigned_numeric_input_with_not_more_than_1_letter ();
		printf(" \n");
	}
	basic_development (Test_field, Test_field, m, n, geben, Test_field, Test_special_fields, Test_field, ges, Growth_players, number_of_players, gamemode_played, information_code, level, w, d, e, Boost_, evolution, &num, &g, Test_special_fields, limits, test_single_options, position, KI_decision, rain, hayir);
	synchronisation_Test_field (Test_field, m, n, 1, 0);

	input = 1;
	while (input != 0) {
		show_field (number_of_players, level, Test_field, Test_field, Test_field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Test_special_fields);
		printf("	Move: Move your square on 0703 to 0603.\n");

		Move (level, Test_field, m, n, geben, Test_field, gamemode_played, information_code, Growth_players, Test_special_fields, Test_special_fields, number_of_players);

		if ((Test_field[0][7][3] != 0)||(Test_field[0][6][3] != geben)) {
			input = 1;
			synchronisation_Test_field (Test_field, m, n, 0, 1);
		} else {
			input = 0;
		}
	}
	basic_development (Test_field, Test_field, m, n, geben, Test_field, Test_special_fields, Test_field, ges, Growth_players, number_of_players, gamemode_played, information_code, level, w, d, e, Move_4, evolution, &num, &g, Test_special_fields, limits, test_single_options, position, KI_decision, rain, hayir);
	synchronisation_Test_field (Test_field, m, n, 1, 0);

	input = 1;
	while (input != 0) {
		show_field (number_of_players, level, Test_field, Test_field, Test_field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Test_special_fields);
		printf("	2-new: The next action of you will be a 2-new, means you are getting dead squares which have 2 instead of 3 squares of yours in its surrounding.	?0?\n");
		input = get_unsigned_numeric_input_with_not_more_than_1_letter ();
		printf(" \n");
	}
	w = 2;
	basic_development (Test_field, Test_field, m, n, geben, Test_field, Test_special_fields, Test_field, ges, Growth_players, number_of_players, gamemode_played, information_code, level, w, d, e, new_2, evolution, &num, &g, Test_special_fields, limits, test_single_options, position, KI_decision, rain, hayir);
	synchronisation_Test_field (Test_field, m, n, 1, 0);
	w = 3;

	input = 1;
	while (input != 0) {
		show_field (number_of_players, level, Test_field, Test_field, Test_field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Test_special_fields);
		printf("	Revive: The next action of you will be a Revive, means the squares of yours that died and have no squares in its surrounding, which were owned by you before and are still living, will be yours again.	?0?\n");
		input = get_unsigned_numeric_input_with_not_more_than_1_letter ();
		printf(" \n");
	}
	basic_development (Test_field, Test_field, m, n, geben, Test_field, Test_special_fields, Test_field, ges, Growth_players, number_of_players, gamemode_played, information_code, level, w, d, e, Revive_, evolution, &num, &g, Test_special_fields, limits, test_single_options, position, KI_decision, rain, hayir);
	synchronisation_Test_field (Test_field, m, n, 1, 0);

	input = 1;
	while (input != 0) {
		show_field (number_of_players, level, Test_field, Test_field, Test_field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Test_special_fields);
		printf("	4/5-new: The next action of you will be a 4/5-new, means you are getting dead squares which have 4 or 5 instead of 3 squares of yours in its surrounding.	?0?\n");
		input = get_unsigned_numeric_input_with_not_more_than_1_letter ();
		printf(" \n");
	}
	w = 4;
	basic_development (Test_field, Test_field, m, n, geben, Test_field, Test_special_fields, Test_field, ges, Growth_players, number_of_players, gamemode_played, information_code, level, w, d, e, new_4_5, evolution, &num, &g, Test_special_fields, limits, test_single_options, position, KI_decision, rain, hayir);
	synchronisation_Test_field (Test_field, m, n, 1, 0);
	w = 3;

	input = 1;
	while (input != 0) {
		show_field (number_of_players, level, Test_field, Test_field, Test_field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Test_special_fields);
		printf("	4-max: The next action of you will be a 4-max, means squares of yours can have up to 4 instead of 3 squares of yours in its surrounding and will still survive.	?0?\n");
		input = get_unsigned_numeric_input_with_not_more_than_1_letter ();
		printf(" \n");
	}
	e = 4;
	basic_development (Test_field, Test_field, m, n, geben, Test_field, Test_special_fields, Test_field, ges, Growth_players, number_of_players, gamemode_played, information_code, level, w, d, e, max_4, evolution, &num, &g, Test_special_fields, limits, test_single_options, position, KI_decision, rain, hayir);
	synchronisation_Test_field (Test_field, m, n, 1, 0);
	e = 3;

	input = 1;
	while (input != 0) {
		show_field (number_of_players, level, Test_field, Test_field, Test_field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Test_special_fields);
		printf("	1-min: The next action of you will be a 1-min, means squares of yours can have down to 1 instead of 2 squares of yours in its surrounding and will still survive.	?0?\n");
		input = get_unsigned_numeric_input_with_not_more_than_1_letter ();
		printf(" \n");
	}
	d = 1;
	basic_development (Test_field, Test_field, m, n, geben, Test_field, Test_special_fields, Test_field, ges, Growth_players, number_of_players, gamemode_played, information_code, level, w, d, e, min_1, evolution, &num, &g, Test_special_fields, limits, test_single_options, position, KI_decision, rain, hayir);
	synchronisation_Test_field (Test_field, m, n, 1, 0);
	d = 2;

	show_field (number_of_players, level, Test_field, Test_field, Test_field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Test_special_fields);
	printf(" \n");

	Spielfeld_Destroy (evolution.nl, m, number_of_players);
	Spielfeld_Destroy (evolution.od, m, number_of_players);
	Spielfeld_Destroy (Test_field, m, 1);
}

void Dynamic_ball_movement (Spielfeld Field, Special_Fields Opague_o, unsigned int m, unsigned int n, unsigned int geben, Special_Fields Allocation_o, unsigned int number_of_players, unsigned int* level, Spielfeld Sf_permutations, unsigned int* information_code, Growth_Player* Growth_players, unsigned int gamemode_played, int* dynamic_pointer, unsigned int erd, unsigned int* position, unsigned int g, unsigned int* ges, Earth_impact impact_tuple, Realize_modifications_variables* rmv) {

	unsigned int controll, indikator1, indikator2, indikator3, space_i, space_j;

	space_i = 0;
	space_j = 0;
	controll = 0;
	indikator1 = 0;		//für Horizontal
	indikator2 = 0;		//für Vertikal
	indikator3 = 0;

	for (unsigned int i=1; i<m-1; i+=1) {
		for (unsigned int j=1; j<n-1; j+=1) {
			if (Field[0][i][j] == Dynamic_ball) {
				position[Horizontal] = j;
				position[Vertikal] = i;
				controll = 1;
			}
			if (controll == 1) {
				break;
			}
		}
		if (controll == 1) {
			break;
		}
	}
	controll = 0;

	if ((gamemode_played == Dynamic)&&((g-1)%number_of_players == 0)&&(rmv->var_[1] != 1010)) {	//Dynamic_ball movement

		if (Opague_o.characterization >= 1) {
			opague_builder (Field, Opague_o, m, n, geben, rmv->AOP, Allocation_o, number_of_players, gamemode_played);
			show_field (number_of_players, level, Sf_permutations, Opague_o.field, Opague_o.field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
		} else {
			show_field (number_of_players, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
		}

		dynamic_pointer[6] = 0;		//impact y_Horizontal
		dynamic_pointer[7] = 0;		//impact y_Vertikal

		dynamic_pointer[Horizontal] = dynamic_pointer[4] + dynamic_pointer[2];	//aus "sgn(a)*a^2" mach "a", done
		dynamic_pointer[Vertikal] = dynamic_pointer[5] + dynamic_pointer[3];

		dynamic_pointer[2] += dynamic_pointer[4];
		dynamic_pointer[3] += dynamic_pointer[5];

		impact_y_semi_square (m, n, position, impact_tuple, dynamic_pointer, Field);

		dynamic_pointer[4] += dynamic_pointer[6];
		dynamic_pointer[5] += dynamic_pointer[7] + erd;

		while (abs(dynamic_pointer[Vertikal])+abs(dynamic_pointer[Horizontal]) != 0){

			// printf("	Test-print \n");
			// show_field (number_of_players, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);		//test
			// printf("	Test-print \n");
			// printf("	\n");
			// printf("	indikator1: %u \n", indikator1);
			// printf("	indikator2: %u \n", indikator2);
			// printf("	sgn(dynamic_pointer[Horizontal]): %d \n", sgn(dynamic_pointer[Horizontal]));
			// printf("	sgn(dynamic_pointer[Vertikal]): %d \n", sgn(dynamic_pointer[Vertikal]));
			// printf("	position[Horizontal]: %u \n", position[Horizontal]);
			// printf("	position[Vertikal]: %u \n", position[Vertikal]);

			// printf("	\n");
			// printf("	Object position: (%u, %u) \n", position[Vertikal], position[Horizontal]);
			// printf("	Weg s: (%d, %d) \n", dynamic_pointer[Vertikal], dynamic_pointer[Horizontal]);
			// printf("	Geschw. v: (%d, %d) \n", dynamic_pointer[3], dynamic_pointer[2]);
			// printf("	Beschl. a: (%d, %d) \n", dynamic_pointer[5], dynamic_pointer[4]);
			// printf("	Impact  y(+erd): (%d, %d) \n", dynamic_pointer[7]+erd, dynamic_pointer[6]);
			// printf("	ffffffff\n");
			// printf("	\n");	//test

			// iteration += 1;

			dynamic_take_out (position, number_of_players, Field, ges, rmv, m, n, Opague_o.field, Allocation_o, geben, gamemode_played);

			indikator1 = 0;
			indikator2 = 0;		//Staffelung: grösser im Betrag 1, anderer nur geblockt 3, anderer reflektiert 5, anderer Null-Betrag 5		3 und 5 und 5 schließen sich aus

			controll = 0;

			if (abs(dynamic_pointer[Horizontal])>abs(dynamic_pointer[Vertikal])) {	//indikator1, position[Horizontal], dynamic_pointer[Horizontal] Horizontal
				indikator1 += 1;
			} else if (abs(dynamic_pointer[Horizontal])<abs(dynamic_pointer[Vertikal])) {
				indikator2 += 1;
			}

			if (sgn(dynamic_pointer[Horizontal])>0) {	//Betrag = 0 wird verhindert
				for (unsigned int j=position[Horizontal]+1; j<n-1; j+=1) {
					if ((Field[0][position[Vertikal]][j] == 0)&&(position[Horizontal]+1 < n-1)) {
						space_j = j;
						if (j != position[Horizontal]+1) {
							indikator2 += 3;
						}
						controll = 1;
						break;
					}
				}
				if ((indikator2 < 3)&&(controll != 1)) {
					indikator2 += 5;
				}
			} else if (sgn(dynamic_pointer[Horizontal])<0) {
				for (unsigned int j=position[Horizontal]-1; j>0; j-=1) {
					if ((Field[0][position[Vertikal]][j] == 0)&&(position[Horizontal]-1 > 0)) {
						space_j = j;
						if (j != position[Horizontal]-1) {
							indikator2 += 3;
						}
						controll = 1;
						break;
					}
				}
				if ((indikator2 < 3)&&(controll != 1)) {
					indikator2 += 5;
				}
			} else if (sgn(dynamic_pointer[Horizontal]) == 0) {
				indikator2 += 5;
			}
			controll = 0;

			if (sgn(dynamic_pointer[Vertikal])>0) {	//Betrag = 0 wird verhindert
				for (unsigned int i=position[Vertikal]+1; i<m-1; i+=1) {
					if ((Field[0][i][position[Horizontal]] == 0)&&(position[Vertikal]+1 < m-1)) {
						space_i = i;
						if (i != position[Vertikal]+1) {
							indikator1 += 3;
						}
						controll = 1;
						break;
					}
				}
				if ((indikator1 < 3)&&(controll != 1)) {
					indikator1 += 5;
				}
			} else if (sgn(dynamic_pointer[Vertikal])<0) {
				for (unsigned int i=position[Vertikal]-1; i>0; i-=1) {
					if ((Field[0][i][position[Horizontal]] == 0)&&(position[Vertikal]-1 > 0)) {
						space_i = i;
						if (i != position[Vertikal]-1) {
							indikator1 += 3;
						}
						controll = 1;
						break;
					}
				}
				if ((indikator1 < 3)&&(controll != 1)) {
					indikator1 += 5;
				}
			} else if (sgn(dynamic_pointer[Vertikal]) == 0) {	//Betrag = 0 hier angenommen
				indikator1 += 5;
			}
			controll = 0;


			if ((abs(dynamic_pointer[Horizontal]) == abs(dynamic_pointer[Vertikal])) && (indikator3 == 0)) {	//Betrag gleich, indikator3 = 1 zeigt kein Fortschritt auf diesem Weg.

				if (sgn(dynamic_pointer[Horizontal]) == sgn(dynamic_pointer[Vertikal])) {	//Vorzeichen gleich

					if (sgn(dynamic_pointer[Horizontal])>0) {	//Vorzeichen positiv

						if ((position[Horizontal] +1 < n-1) && (position[Vertikal] +1 < m-1) && (Field[0][position[Vertikal] +1][position[Horizontal] +1] == 0)) {	//Noch im Spielfeld? Ja und diagonal ist frei

							Field[0][position[Vertikal] +1][position[Horizontal] +1] = Dynamic_ball;
							Field[0][position[Vertikal]][position[Horizontal]] = 0;
							position[Vertikal] += 1;
							position[Horizontal] += 1;
							dynamic_pointer[Horizontal] -= 1;
							dynamic_pointer[Vertikal] -= 1;

						} else if ((position[Horizontal] +1 >= n-1) && (position[Vertikal] +1 >= m-1)) { //beide nein

							Reflection (dynamic_pointer, 0, erd);
							Reflection (dynamic_pointer, 1, erd);

							continue;

						} else if (position[Horizontal]+1 >= n-1) {	//Horizontal nein

							Reflection (dynamic_pointer, 0, erd);

							continue;

						} else if (position[Vertikal]+1 >= m-1) {	//Vertikal nein

							Reflection (dynamic_pointer, 1, erd);

							continue;

						} else {
							indikator3 = 1;
							continue;
						}

					} else if (sgn(dynamic_pointer[Horizontal])<0) {	//Vorzeichen negativ

						if ((position[Horizontal]-1 > 0) && (position[Vertikal]-1 > 0) && (Field[0][position[Vertikal]-1][position[Horizontal]-1] == 0)) {	//Noch im Spielfeld? Ja und diagonal ist frei

							Field[0][position[Vertikal]-1][position[Horizontal]-1] = Dynamic_ball;
							Field[0][position[Vertikal]][position[Horizontal]] = 0;
							position[Vertikal] -= 1;
							position[Horizontal] -= 1;
							dynamic_pointer[Horizontal] += 1;
							dynamic_pointer[Vertikal] += 1;

						} else if ((position[Horizontal]-1 == 0) && (position[Vertikal]-1 == 0)) { //beide nein

							Reflection (dynamic_pointer, 0, erd);
							Reflection (dynamic_pointer, 1, erd);

							continue;

						} else if (position[Horizontal]-1 == 0) {	//Horizontal nein

							Reflection (dynamic_pointer, 0, erd);

							continue;

						} else if (position[Vertikal]-1 == 0) {	//Vertikal nein

							Reflection (dynamic_pointer, 1, erd);

							continue;

						} else {
							indikator3 = 1;
							continue;
						}

					}

				} else {	//unterschiedliches Vorzeichen

					if (sgn(dynamic_pointer[Horizontal])>0) {	//Vorzeichen Horizontal positiv

						if ((position[Horizontal]+1 < n-1) && (position[Vertikal]-1 > 0) && (Field[0][position[Vertikal]-1][position[Horizontal]+1] == 0)) {	//Noch im Spielfeld? Ja und diagonal ist frei

							Field[0][position[Vertikal]-1][position[Horizontal]+1] = Dynamic_ball;
							Field[0][position[Vertikal]][position[Horizontal]] = 0;
							position[Vertikal] -= 1;
							position[Horizontal] += 1;
							dynamic_pointer[Horizontal] -= 1;
							dynamic_pointer[Vertikal] += 1;

						} else if ((position[Horizontal]+1 >= n-1) && (position[Vertikal]-1 == 0)) { //beide nein

							Reflection (dynamic_pointer, 0, erd);
							Reflection (dynamic_pointer, 1, erd);

							continue;

						} else if (position[Horizontal]+1 >= n-1) {	//Horizontal nein

							Reflection (dynamic_pointer, 0, erd);

							continue;

						} else if (position[Vertikal]-1 == 0) {	//Vertikal nein

							Reflection (dynamic_pointer, 1, erd);

							continue;

						} else {
							indikator3 = 1;
							continue;
						}

					}  else if (sgn(dynamic_pointer[Horizontal])<0) {	//Vorzeichen Horizontal negativ

						if ((position[Horizontal]-1 > 0) && (position[Vertikal]+1 < m-1) && (Field[0][position[Vertikal]+1][position[Horizontal]-1] == 0)) {	//Noch im Spielfeld? Ja und diagonal ist frei

							Field[0][position[Vertikal]+1][position[Horizontal]-1] = Dynamic_ball;
							Field[0][position[Vertikal]][position[Horizontal]] = 0;
							position[Vertikal] += 1;
							position[Horizontal] -= 1;
							dynamic_pointer[Horizontal] += 1;
							dynamic_pointer[Vertikal] -= 1;

						} else if ((position[Horizontal]-1 == 0) && (position[Vertikal]+1 >= m-1)) { //beide nein

							Reflection (dynamic_pointer, 0, erd);
							Reflection (dynamic_pointer, 1, erd);

							continue;

						} else if (position[Horizontal] -1 == 0) {	//Horizontal nein

							Reflection (dynamic_pointer, 0, erd);

							continue;

						} else if (position[Vertikal] +1 >= m-1) {	//Vertikal nein

							Reflection (dynamic_pointer, 1, erd);

							continue;

						} else {
							indikator3 = 1;
							continue;
						}

					}

				}

			} else if (indikator1 >= indikator2) {	//partielle Durchführung, außer bei doppelter Reflektion, nimm s_Horizontal = dynamic_pointer[Horizontal]
				if (indikator2 >= 5) {

					if (abs(dynamic_pointer[Horizontal]) > 0) {
						Reflection (dynamic_pointer, 0, erd);
					}
					if (abs(dynamic_pointer[Vertikal]) > 0) {
						Reflection (dynamic_pointer, 1, erd);
					}

					continue;

				} else if (indikator2 >= 3) {	//moveable crash, um Reflection zu verhindern

					if (sgn(dynamic_pointer[Horizontal])>0) {
						for (unsigned int r=space_j; r>position[Horizontal]; r-=1) {
							set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, position[Vertikal], r, Field[0][position[Vertikal]][r-1]);
						}
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, position[Vertikal], position[Horizontal], 0);
						position[Horizontal] += 1;
						dynamic_pointer[Horizontal] -= 1;
						dynamic_pointer[2] -= 1;
						dynamic_pointer[4] -= 1;

						if (dynamic_pointer[Horizontal] != 0) {
							dynamic_pointer[Horizontal] -= 1;
						}

					} else if (sgn(dynamic_pointer[Horizontal])<0) {
						for (unsigned int r=space_j; r<position[Horizontal]; r+=1) {
							set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, position[Vertikal], r, Field[0][position[Vertikal]][r+1]);
						}
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, position[Vertikal], position[Horizontal], 0);
						position[Horizontal] -= 1;
						dynamic_pointer[Horizontal] += 1;
						dynamic_pointer[2] += 1;
						dynamic_pointer[4] += 1;

						if (dynamic_pointer[Horizontal] != 0) {
							dynamic_pointer[Horizontal] += 1;
						}
					}

				} else {		//freier Schritt
					if (sgn(dynamic_pointer[Horizontal])>0) {

						Field[0][position[Vertikal]][position[Horizontal]+1] = Dynamic_ball;
						Field[0][position[Vertikal]][position[Horizontal]] = 0;
						dynamic_pointer[Horizontal] -= 1;
						position[Horizontal] += 1;

					} else if (sgn(dynamic_pointer[Horizontal])<0) {

						Field[0][position[Vertikal]][position[Horizontal]-1] = Dynamic_ball;
						Field[0][position[Vertikal]][position[Horizontal]] = 0;
						dynamic_pointer[Horizontal] += 1;
						position[Horizontal] -= 1;

					}		//Diagonal-Schritt mit partieller Reflection entzieht sich dem freien Schritt
				}

			} else if (indikator2 >= indikator1) {	//partielle Durchführung, außer bei doppelter Reflektion, nimm s_Vertikal = dynamic_pointer[Vertikal]
				if (indikator1 >= 5) {

					if (abs(dynamic_pointer[Horizontal]) > 0) {
						Reflection (dynamic_pointer, 0, erd);
					}
					if (abs(dynamic_pointer[Vertikal]) > 0) {
						Reflection (dynamic_pointer, 1, erd);
					}
					// printf("	\n");	//test
					// printf("	indikator1: %u \n", indikator1);
					// printf("	indikator2: %u \n", indikator2);
					// printf("	sgn(dynamic_pointer[Horizontal]): %d \n", sgn(dynamic_pointer[Horizontal]));
					// printf("	sgn(dynamic_pointer[Vertikal]): %d \n", sgn(dynamic_pointer[Vertikal]));
					// printf("	position[Horizontal]: %u \n", position[Horizontal]);
					// printf("	position[Vertikal]: %u \n", position[Vertikal]);

					// printf("	\n");
					// printf("	Object position: (%u, %u) \n", position[Vertikal], position[Horizontal]);
					// printf("	Weg s: (%d, %d) \n", dynamic_pointer[Vertikal], dynamic_pointer[Horizontal]);
					// printf("	Geschw. v: (%d, %d) \n", dynamic_pointer[3], dynamic_pointer[2]);
					// printf("	Beschl. a: (%d, %d) \n", dynamic_pointer[5], dynamic_pointer[4]);
					// printf("	Impact  y(+erd): (%d, %d) \n", dynamic_pointer[7]+erd, dynamic_pointer[6]);
					// printf("	######\n");
					// printf("	\n");

					continue;

				} else if (indikator1 >= 3) {	//moveable crash, um Reflection zu verhindern

					if (sgn(dynamic_pointer[Vertikal])>0) {
						for (unsigned int r=space_i; r>position[Vertikal]; r-=1) {
							set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, r, position[Horizontal], Field[0][r-1][position[Horizontal]]);
						}
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, position[Vertikal], position[Horizontal], 0);
						position[Vertikal] += 1;
						dynamic_pointer[Vertikal] -= 1;
						dynamic_pointer[3] -= 1;
						dynamic_pointer[5] -= 1;

						if (dynamic_pointer[Vertikal] != 0) {
							dynamic_pointer[Vertikal] -= 1;
						}

					} else if (sgn(dynamic_pointer[Vertikal])<0) {
						for (unsigned int r=space_i; r<position[Vertikal]; r+=1) {
							set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, r, position[Horizontal], Field[0][r+1][position[Horizontal]]);
						}
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, position[Vertikal], position[Horizontal], 0);
						position[Vertikal] -= 1;
						dynamic_pointer[Vertikal] += 1;
						dynamic_pointer[3] += 1;
						dynamic_pointer[5] += 1;

						if (dynamic_pointer[Vertikal] != 0) {
							dynamic_pointer[Vertikal] += 1;
						}
					}

				} else {		//freier Schritt
					if (sgn(dynamic_pointer[Vertikal])>0) {

						Field[0][position[Vertikal]+1][position[Horizontal]] = Dynamic_ball;
						Field[0][position[Vertikal]][position[Horizontal]] = 0;
						dynamic_pointer[Vertikal] -= 1;
						position[Vertikal] += 1;

					} else if (sgn(dynamic_pointer[Vertikal])<0) {

						Field[0][position[Vertikal]-1][position[Horizontal]] = Dynamic_ball;
						Field[0][position[Vertikal]][position[Horizontal]] = 0;
						dynamic_pointer[Vertikal] += 1;
						position[Vertikal] -= 1;

					}
				}

			}

			dynamic_take_out (position, number_of_players, Field, ges, rmv, m, n, Opague_o.field, Allocation_o, geben, gamemode_played);

			if ((abs(dynamic_pointer[Vertikal])+abs(dynamic_pointer[Horizontal])) == 0) {

				// printf("	\n");	//test
				// printf("	Object position: (%u, %u) \n", position[Vertikal], position[Horizontal]);
				// printf("	Weg s: (%d, %d) \n", dynamic_pointer[Vertikal], dynamic_pointer[Horizontal]);
				// printf("	Geschw. v: (%d, %d) \n", dynamic_pointer[3], dynamic_pointer[2]);
				// printf("	Beschl. a: (%d, %d) \n", dynamic_pointer[5], dynamic_pointer[4]);
				// printf("	Impact  y(+erd): (%d, %d) \n", dynamic_pointer[7]+erd, dynamic_pointer[6]);
				// printf("	bbbbbbb\n");

				break;
			}

			indikator3 = 0;

			//Feintuning

			dynamic_pointer[6] = 0;		//impact y_Horizontal
			dynamic_pointer[7] = 0;		//impact y_Vertikal

			impact_y_semi_square (m, n, position, impact_tuple, dynamic_pointer, Field);

			if (sgn(dynamic_pointer[2]) < 0) {		//Horizontal (ohne erd)
				if (sgn(dynamic_pointer[6]) > 0) {
					for (int r=1; r<=abs(erd); r+=1) {
						dynamic_pointer[2] += 1;
						if (dynamic_pointer[2] == 0) {
							break;
						}
					}
				}
			} else if (sgn(dynamic_pointer[2]) > 0) {		//dynamic_pointer[2] = v_Horizontal
				if (sgn(dynamic_pointer[6]) < 0) {
					for (int r=1; r<=abs(erd); r+=1) {
						dynamic_pointer[2] -= 1;
						if (dynamic_pointer[2] == 0) {
							break;
						}
					}
				}
			}

			if (sgn(dynamic_pointer[4]) < 0) {		//Horizontal (ohne erd)
				if (sgn(dynamic_pointer[6]) > 0) {
					for (int r=1; r<=abs(erd); r+=1) {
						dynamic_pointer[4] += 1;
						if (dynamic_pointer[4] == 0) {
							break;
						}
					}

					if ((abs(dynamic_pointer[4]) < abs(dynamic_pointer[6])) && (sgn(dynamic_pointer[4]) == sgn(dynamic_pointer[Horizontal]))&&(sgn(dynamic_pointer[Horizontal]) != 0)) {	//s_Horizontal-Verringerung

						for (int r=1; r<=(abs(dynamic_pointer[6])-abs(dynamic_pointer[4])); r+=1) {
							dynamic_pointer[Horizontal] += 1;
							if (dynamic_pointer[Horizontal] == 0) {
								break;
							}
						}
					}
				}

			} else if (sgn(dynamic_pointer[4]) > 0) {		//dynamic_pointer[4] = a_Horizontal
				if (sgn(dynamic_pointer[6]) < 0) {
					for (int r=1; r<=abs(erd); r+=1) {
						dynamic_pointer[4] -= 1;
						if (dynamic_pointer[4] == 0) {
							break;
						}
					}

					if ((abs(dynamic_pointer[4]) < abs(dynamic_pointer[6])) && (sgn(dynamic_pointer[4]) == sgn(dynamic_pointer[Horizontal]))&&(sgn(dynamic_pointer[Horizontal]) != 0)) {

						for (int r=1; r<=(abs(dynamic_pointer[6])-abs(dynamic_pointer[4])); r+=1) {	//s_Horizontal-Verringerung
							dynamic_pointer[Horizontal] -= 1;
							if (dynamic_pointer[Horizontal] == 0) {
								break;
							}
						}
					}
				}

			} else if ((sgn(dynamic_pointer[4]) == 0) && (sgn(dynamic_pointer[2]) != 0) && (sgn(dynamic_pointer[6]) != 0)) {

				if (sgn(dynamic_pointer[6]) < sgn(dynamic_pointer[2])) {

					if ((0 < abs(dynamic_pointer[6])) && (sgn(dynamic_pointer[2]) == sgn(dynamic_pointer[Horizontal]))) {

						for (int r=1; r<=(abs(dynamic_pointer[6])-abs(dynamic_pointer[4])); r+=1) {	//s_Horizontal-Verringerung
							dynamic_pointer[Horizontal] -= 1;
							if (dynamic_pointer[Horizontal] == 0) {
								break;
							}
						}
					}

				} else if (sgn(dynamic_pointer[6]) > sgn(dynamic_pointer[2])) {

					if ((0 < abs(dynamic_pointer[6])) && (sgn(dynamic_pointer[2]) == sgn(dynamic_pointer[Horizontal]))) {	//s_Horizontal-Verringerung

						for (int r=1; r<=(abs(dynamic_pointer[6])-abs(dynamic_pointer[4])); r+=1) {
							dynamic_pointer[Horizontal] += 1;
							if (dynamic_pointer[Horizontal] == 0) {
								break;
							}
						}
					}
				}

			}




			if (sgn(dynamic_pointer[3] < 0)) {		//Vertikal (mit erd)
				if (sgn(dynamic_pointer[7]+erd) > 0) {
					for (int r=1; r<=abs(erd); r+=1) {
						dynamic_pointer[3] += 1;
						if (dynamic_pointer[3] == 0) {
							break;
						}
					}
				}
			} else if (sgn(dynamic_pointer[3] > 0)) {		//dynamic_pointer[3] = v_Vertikal
				if (sgn(dynamic_pointer[7]+erd) < 0) {	//<= wegen-erd-Kompensierung, zurückgenommen wegen eventuell negativer erd
					for (int r=1; r<=abs(erd); r+=1) {
						dynamic_pointer[3] -= 1;
						if (dynamic_pointer[3] == 0) {
							break;
						}
					}
				}
			}

			if (sgn(dynamic_pointer[5] < 0)) {		//Vertikal (mit erd)
				if (sgn(dynamic_pointer[7]+erd) > 0) {
					for (int r=1; r<=abs(erd); r+=1) {
						dynamic_pointer[5] += 1;
						if (dynamic_pointer[5] == 0) {
							break;
						}
					}

					if ((abs(dynamic_pointer[5]) < abs(dynamic_pointer[7]+erd))&&(sgn(dynamic_pointer[5]) == sgn(dynamic_pointer[Vertikal]))&&(sgn(dynamic_pointer[Vertikal]) != 0)) {	//s_Vertikal-Verringerung

						for (int r=1; r<=(abs(dynamic_pointer[7]+erd)-abs(dynamic_pointer[5])); r+=1) {
							dynamic_pointer[Vertikal] += 1;
							if (dynamic_pointer[Vertikal] == 0) {
								break;
							}
						}
					}
				}

			} else if (sgn(dynamic_pointer[5]) > 0) {		//dynamic_pointer[5] = a_Vertikal
				if (sgn(dynamic_pointer[7]+erd) < 0) {	//<= wegen-erd-Kompensierung, zurückgenommen wegen eventuell negativer erd
					for (int r=1; r<=abs(erd); r+=1) {
						dynamic_pointer[5] -= 1;
						if (dynamic_pointer[5] == 0) {
							break;
						}
					}

					if ((abs(dynamic_pointer[5]) < abs(dynamic_pointer[7]+erd)) && (sgn(dynamic_pointer[5]) == sgn(dynamic_pointer[Vertikal]))&&(sgn(dynamic_pointer[Vertikal]) != 0)) {

						for (int r=1; r<=(abs(dynamic_pointer[7]+erd)-abs(dynamic_pointer[5])); r+=1) {	//s_Vertikal-Verringerung
							dynamic_pointer[Vertikal] -= 1;
							if (dynamic_pointer[Vertikal] == 0) {
								break;
							}
						}
					}
				}

			} else if ((sgn(dynamic_pointer[5]) == 0) && (sgn(dynamic_pointer[3]) != 0) && (sgn(dynamic_pointer[7]+erd) != 0)) {

				if (sgn(dynamic_pointer[7]+erd) < sgn(dynamic_pointer[3])) {

					if ((0 < abs(dynamic_pointer[7]+erd)) && (sgn(dynamic_pointer[3]) == sgn(dynamic_pointer[Vertikal]))) {

						for (int r=1; r<=(abs(dynamic_pointer[7]+erd)-abs(dynamic_pointer[5])); r+=1) {	//s_Vertikal-Verringerung
							dynamic_pointer[Vertikal] -= 1;
							if (dynamic_pointer[Vertikal] == 0) {
								break;
							}
						}
					}

				} else if (sgn(dynamic_pointer[7]+erd) > sgn(dynamic_pointer[3])) {

					if ((0 < abs(dynamic_pointer[7]+erd)) && (sgn(dynamic_pointer[3]) == sgn(dynamic_pointer[Vertikal]))) {	//s_Vertikal-Verringerung

						for (int r=1; r<=(abs(dynamic_pointer[7]+erd)-abs(dynamic_pointer[5])); r+=1) {
							dynamic_pointer[Vertikal] += 1;
							if (dynamic_pointer[Vertikal] == 0) {
								break;
							}
						}
					}
				}

			}

			if ((sgn(dynamic_pointer[Horizontal]) > 0)&&(sgn(dynamic_pointer[2]) >= 0)&&(sgn(dynamic_pointer[4]) < 0)) {		//a_Horizontal-verringerung
				dynamic_pointer[4] += 1;
			} else if ((sgn(dynamic_pointer[Horizontal]) < 0)&&(sgn(dynamic_pointer[2]) <= 0)&&(sgn(dynamic_pointer[4]) > 0)) {
				dynamic_pointer[4] -= 1;
			}

			if ((sgn(dynamic_pointer[Vertikal]) > 0)&&(sgn(dynamic_pointer[3]) >= 0)&&(sgn(dynamic_pointer[5]) < 0)) {		//a_Vertikal-verringerung
				dynamic_pointer[5] += 1;
			} else if ((sgn(dynamic_pointer[Vertikal]) < 0)&&(sgn(dynamic_pointer[3]) <= 0)&&(sgn(dynamic_pointer[5]) > 0)) {
				dynamic_pointer[5] -= 1;
			}

			// printf("	\n");	//test
			// printf("	indikator1: %u \n", indikator1);
			// printf("	indikator2: %u \n", indikator2);
			// printf("	sgn(dynamic_pointer[Horizontal]): %d \n", sgn(dynamic_pointer[Horizontal]));
			// printf("	sgn(dynamic_pointer[Vertikal]): %d \n", sgn(dynamic_pointer[Vertikal]));
			// printf("	position[Horizontal]: %u \n", position[Horizontal]);
			// printf("	position[Vertikal]: %u \n", position[Vertikal]);

			// printf("	\n");
			// printf("	Object position: (%u, %u) \n", position[Vertikal], position[Horizontal]);
			// printf("	Weg s: (%d, %d) \n", dynamic_pointer[Vertikal], dynamic_pointer[Horizontal]);
			// printf("	Geschw. v: (%d, %d) \n", dynamic_pointer[3], dynamic_pointer[2]);
			// printf("	Beschl. a: (%d, %d) \n", dynamic_pointer[5], dynamic_pointer[4]);
			// printf("	Impact  y(+erd): (%d, %d) \n", dynamic_pointer[7]+erd, dynamic_pointer[6]);
			// printf("	\n");
			// printf("	\n");

			//beschleunigung abbremsen, falls sgn(s)==sgn(v)!=sgn(a), done

		}	//komplette durchrechnung

	}

	// scanf("%u", &pause);	//test
	// printf("	#line 4494, komplette durchrechnung \n");	//test

	if (gamemode_played == Dynamic) {	//Ausscheiden der Teams?
		dynamic_take_out (position, number_of_players, Field, ges, rmv, m, n, Opague_o.field, Allocation_o, geben, gamemode_played);
	}

}

void survive_obstacles_generator (unsigned int gamemode_played, unsigned int rmv_round_counter, unsigned int round_counter_before, unsigned int* information_code, Spielfeld Field, unsigned int geben, Special_Fields Allocation_o, unsigned int number_of_players, Special_Fields Opague_o, Spielfeld Sf_permutations, unsigned int AOP, unsigned int* level, Growth_Player* Growth_players, unsigned int m, unsigned int n, unsigned int survive_different, unsigned int* ges, unsigned int* rmv_var_, unsigned int g, unsigned int rmv_use_number, unsigned int tac, unsigned int time_matters_ttt) {

	if ((gamemode_played == Survive)&&(rmv_round_counter == round_counter_before+1)) {

		//printf("in the obstacles-generator \n");	//test

		if ((rmv_round_counter % 5 == 0)&&(information_code[3] >= 1)) {	//delete Waves
			for (unsigned int i=1; i<m-1; i+=1){
				for (unsigned int j=1; j<n-1; j+=1){
					if (Field[0][i][j] == Waves) {
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, i, j, 0);
					}
				}
			}
		}

		if (Opague_o.characterization >= 1) {
			opague_builder (Field, Opague_o, m, n, geben%number_of_players, AOP, Allocation_o, number_of_players, gamemode_played);
			show_field (number_of_players, level, Sf_permutations, Opague_o.field, Opague_o.field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
		} else {
			show_field (number_of_players, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
		}

		for (unsigned int i=1; i<m-1; i+=1){
			for (unsigned int j=1; j<n-1; j+=1){

				if (information_code[2] >= 1) {	//Bombs
					if (Field[0][i][j] == Bomb_4) {
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, i, j, Bomb_3);
					} else if (Field[0][i][j] == Bomb_3) {
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, i, j, Bomb_2);
					} else if (Field[0][i][j] == Bomb_2) {
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, i, j, Bomb_1);
					} else if (Field[0][i][j] == Bomb_1) {
						for (unsigned int h=i-1; h<=i+1; h+=1){
							for (unsigned int k=j-1; k<=j+1; k+=1){
								if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))&&(Field[0][h][k] != 0)){
									set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, h, k, 0);
								}
							}
						}
					}
				}
				if (information_code[3] >= 1) {	//Waves
					if (((Field[0][i-1][j] == Waves)&&(Field[0][i+1][j] != Waves)&&(Field[0][i][j+1] != Waves)&&(Field[0][i][j-1] != Waves))||((Field[0][i-1][j] != Waves)&&(Field[0][i+1][j] == Waves)&&(Field[0][i][j+1] != Waves)&&(Field[0][i][j-1] != Waves))||((Field[0][i-1][j] != Waves)&&(Field[0][i+1][j] != Waves)&&(Field[0][i][j+1] == Waves)&&(Field[0][i][j-1] != Waves))||((Field[0][i-1][j] != Waves)&&(Field[0][i+1][j] != Waves)&&(Field[0][i][j+1] != Waves)&&(Field[0][i][j-1] == Waves))) {
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, i, j, Waves_new);
					}
				}
			}
		}

		for (unsigned int i=1; i<m-1; i+=1){
			for (unsigned int j=1; j<n-1; j+=1){
				if (Field[0][i][j] == Waves) {
					set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, i, j, 0);
				}
			}
		}
		for (unsigned int i=1; i<m-1; i+=1){
			for (unsigned int j=1; j<n-1; j+=1){
				if (Field[0][i][j] == Waves_new) {
					set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, i, j, Waves);
				}
			}
		}

		if ((rmv_round_counter % 5 == 0)&&(information_code[1] >= 1)) {	//Traps amount per round
			information_code[1] += 1;
		}
		if ((rmv_round_counter % 10 == 0)&&(information_code[2] >= 1)) {	//Bombs amount per round
			information_code[2] += 1;
		}
		if ((rmv_round_counter % 15 == 0)&&(information_code[3] >= 1)) {	//Waves amount per 5 rounds
			information_code[3] += 1;
		}

		if ((rmv_round_counter % 5 == 1)&&(information_code[3] >= 1)) {	//new Waves
			for (unsigned int p=1; p<=information_code[3]; p+=1) {
				unsigned int i;
				unsigned int j;
				i = ((survive_different%10)+ges[1]+ges[3]+ges[5]+ges[7]+ges[9]+rmv_var_[2]+rmv_var_[4]+rmv_var_[6]+rmv_var_[8]+Growth_players[1].color+Growth_players[3].color+Growth_players[5].color+Growth_players[7].color+Growth_players[9].color+7*p+g+2*rmv_use_number+tac)%(m-2) + 1;
				j = ((survive_different%6)+ges[2]+ges[4]+ges[6]+ges[8]+rmv_var_[1]+rmv_var_[3]+rmv_var_[5]+rmv_var_[7]+rmv_var_[9]+Growth_players[0].color+Growth_players[2].color+Growth_players[4].color+Growth_players[6].color+Growth_players[8].color+11*p+g+3*rmv_use_number+time_matters_ttt)%(n-2) + 1;
				set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, i, j, Waves);
			}
		}
		if (information_code[1] >= 1) {	//new Traps
			for (unsigned int p=1; p<=information_code[1]; p+=1) {
				unsigned int i;
				unsigned int j;
				i = ((survive_different%5)+ges[1]+ges[3]+ges[5]+ges[7]+ges[9]+rmv_var_[2]+rmv_var_[4]+rmv_var_[6]+rmv_var_[8]+Growth_players[1].color+Growth_players[3].color+Growth_players[5].color+Growth_players[7].color+Growth_players[9].color+3*p+g+rmv_use_number+tac)%(m-2) + 1;
				j = ((survive_different%12)+ges[2]+ges[4]+ges[6]+ges[8]+rmv_var_[1]+rmv_var_[3]+rmv_var_[5]+rmv_var_[7]+rmv_var_[9]+Growth_players[0].color+Growth_players[2].color+Growth_players[4].color+Growth_players[6].color+Growth_players[8].color+6*p+g+2*rmv_use_number+time_matters_ttt)%(n-2) + 1;
				set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, i, j, Traps);
			}
		}
		if (information_code[2] >= 1) {	//new Bombs
			for (unsigned int p=1; p<=information_code[2]; p+=1) {
				unsigned int i;
				unsigned int j;
				i = ((survive_different%15)+ges[1]+ges[3]+ges[5]+ges[7]+ges[9]+rmv_var_[2]+rmv_var_[4]+rmv_var_[6]+rmv_var_[8]+Growth_players[1].color+Growth_players[3].color+Growth_players[5].color+Growth_players[7].color+Growth_players[9].color+8*p+g+3*rmv_use_number+tac)%(m-2) + 1;
				j = ((survive_different%4)+ges[2]+ges[4]+ges[6]+ges[8]+rmv_var_[1]+rmv_var_[3]+rmv_var_[5]+rmv_var_[7]+rmv_var_[9]+Growth_players[0].color+Growth_players[2].color+Growth_players[4].color+Growth_players[6].color+Growth_players[8].color+5*p+g+rmv_use_number+time_matters_ttt)%(n-2) + 1;
				set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, i, j, Bomb_4);
			}
		}
	}
}

void playing_a_game (unsigned int* same, unsigned int* position, unsigned int AOP, time_t time3, unsigned int* playtime, unsigned int NOSV, Quidditch_setup* Qs) {

	Realize_modifications_variables* rmv;	//realize_modifications_variables (rmv), contains both copied and new variables

	Spielfeld Field;	//cons_field in Field, cons_journey in Journey_o.field, Field[0]==Das Spielfeld, Journey_o.field[0]==Das Journeyfeld
	Spielfeld Sf_permutations;	//Permutations-Spielfeld, Opague-Spielfeld, Allocations-Spielfeld
	Spielfeld numbers_of_, stack_of_;	//ruck muss raus, done, numbers_of_==statistics, numbers_of_[geben][0]==Matchballs etc., stack_of_==stack of tac

	unsigned int g, survive_different;	//it is time to play, and to play different
	unsigned int w, d, e;	// Evolutionsparameter
	unsigned int player_counter, round_counter;	//Ausgeschiedene Spieler und Rundenanzahl
	unsigned int round_counter_before;	//A signal of going further or back
	unsigned int controll_1, controll_2;	// just to controll something
	unsigned int menuoperator;	// Navigationsparameter
	unsigned int all_turns_correction;	// die Züge an die aktuelle Spieleranzahl anpassen
	unsigned int sup_num, suprise;	// specialeffectssuprise;
	unsigned int KI_decision;	//choice of where to keep/produce made by a KI

	unsigned int cons[AOP+1], pere[AOP+1], win_condition[AOP+1], var_[AOP+1], ges[AOP+1], out_counter[AOP+1], geben;	//saved numbers, penalty-reminder, Spielereingabevariable, Anzahl der Spielsteine, Are you out of play, aktiver Spieler

	unsigned int* Points;		//undecided, 1, 2

	time_t time1, time2, time4;
	double time_warning;
	double time_saver;

	int* dynamic_pointer;	//Dynamic direction
	int** dynamic_pointer_save;	//saved Dynamic direction
	// unsigned int** sigmas_for_permutation_number_c;	//permutations in Permutations, in struct
	// unsigned int** sigmas_for_permutation_number_b;	//permutations in Permutations, in struct


	// copies of the same-variables following

	unsigned int m, n;	//Field: height and length
	unsigned int opt, tac, cards, use_number;	//how to get the actions: random, tactical, mixed in cards, rmv->use_number shows possible actions
	unsigned int rain;	//Gamemode: Rain
	unsigned int gamemode_played, number_of_players;	//the played gamemode, how many players are playing
	unsigned int freq;	// Race
	// unsigned int permutation_number_c, permutation_number_b, amount_of_permutation_number_c, amount_of_permutation_number_b;	// Permutation matters, now in a struct called Collector_of_permutation
	unsigned int rtp;	//rounds to play - used in Ulcer/Arena
	unsigned int rtc, spf;	// Gamemode: Hunt
	unsigned int exclude_counter;	//Gamemode: Arena

	unsigned int ulcer_lifes[AOP+1], ulcer_start[AOP+1], information_code[4], ability[AOP+1];	//how many lifes in Ulcer, some necessary information about gamemodes, abilities in Arena
	unsigned int level[AOP+1];		// Colors for players, the level of the KI's
	unsigned int number_[AOP+1];	//numbers to confuse the random and for the statistics
	int erd; // Gamemode: Dynamic
	
	Special_Fields Allocation_o, Opague_o, Journey_o;
	Growth_Player Growth_players[AOP+1];	//id and color
	Limits limits;	//the limits
	Num_num num;	//remix the random
		Evolution evolution;	//Fields for born/dying squares
	Collector Collector_of_permutation;	//Permutations
	Earth_impact impact_tuple;
	Single_option_representives single_option_representives;	// Modifications, Projection matters
	Time_matters time_matters;	// Time-limits and the penalties
	
	Moveable_objects_condition* Moc_Klatscher;
	Moveable_objects_condition* Moc_Quaffel;
	Moveable_objects_condition* Moc_Schnatz;
	
	rmv = Realize_modifications_variables_Vektor_Create(1);
	
	w = 3;
	d = 2;
	e = 3;

	Points = unsigned_int_Vektor_Create (3);	//possible to modify

	num.bir = 0;
	num.iki = 0;
	num.uec = 0;

	menuoperator = 0;

	controll_1 = 0;
	controll_2 = 0;

	round_counter_before = 0;
	round_counter = 0;

	time_warning = 0.0;
	time_saver = 0.0;

	player_counter = 0;

	Initialisierung_Arrays_2 (AOP, pere, ges, var_, ulcer_start, win_condition, out_counter, number_, cons);

	survive_different = 0;

	all_turns_correction = 0;	//for mechanisms based on turns of the players, if a player is out

	suprise = 0;
	sup_num = 0;

	KI_decision = 0;
	level[0] = 0;

	same[0] = 0;
	m = same[1];
	n = same[2];
	Journey_o.characterization = same[3];
	tac = same[4];
	gamemode_played = same[5];
	ulcer_lifes[1] = same[10];
	rain = same[11];
	opt = same[15];
	impact_tuple.range = same[16];
	impact_tuple.strength = same[17];
	limits.new = same[18];
	limits.at_all = same[19];
	ulcer_lifes[2] = same[20];
	freq = same[22];
	use_number = same[23];
	number_of_players = same[24];
	rtc = same[25];
	spf = same[26];
	ulcer_lifes[0] = same[27];
	// hboa = same[28];
	time_matters.ttt = same[29];
	ulcer_lifes[3] = same[30];
	time_matters.warning_system = same[31];
	exclude_counter = same[32];
	rtp = same[33];
	information_code[0] = same[34];
	information_code[1] = same[35];
	information_code[2] = same[36];
	information_code[3] = same[37];
	ability[0] = same[38];
	ability[1] = same[39];
	ulcer_lifes[4] = same[40];
	ability[2] = same[41];
	ability[3] = same[42];
	ability[4] = same[43];
	ability[5] = same[44];
	ability[6] = same[45];
	ability[7] = same[46];
	ability[8] = same[47];
	ability[9] = same[48];
	Growth_players[0].color = same[49];
	ulcer_lifes[5] = same[50];
	Growth_players[1].color = same[51];
	Growth_players[2].color = same[52];
	Growth_players[3].color = same[53];
	Growth_players[4].color = same[54];
	Growth_players[5].color = same[55];
	Growth_players[6].color = same[56];
	Growth_players[7].color = same[57];
	Growth_players[8].color = same[58];
	Growth_players[9].color = same[59];
	ulcer_lifes[6] = same[60];
	ulcer_lifes[7] = same[61];
	ulcer_lifes[8] = same[62];
	ulcer_lifes[9] = same[63];
	Opague_o.characterization  = same[64];
	number_[3] = same[65];
	number_[4] = same[66];
	if (same[67] >= 10) {	//-1 --> 10, -2 --> 20, ...
		erd = -1 * (same[67]/10);
	} else {
		erd = same[67];
	}
	single_option_representives.undead_duration = same[68];
	Allocation_o.characterization = same[70];
	cards = same[71];
	single_option_representives.inverted = same[72];
	single_option_representives.addition = same[73];
	single_option_representives.intensity_loss_per_line_multiplication = same[75];
	direction = same[76];
	Collector_of_permutation.permutation_number_c = same[78];
	Collector_of_permutation.permutation_number_b = same[79];
	Collector_of_permutation.amount_of_permutation_number_c = same[80];
	Collector_of_permutation.amount_of_permutation_number_b = same[81];
	level[1] = same[82];
	level[2] = same[83];
	level[3] = same[84];
	level[4] = same[85];
	level[5] = same[86];
	level[6] = same[87];
	level[7] = same[88];
	level[8] = same[89];
	level[9] = same[90];

	for (unsigned int p=1; p<=number_of_players; p++) {
		Growth_players[p].id = p;
	}
	
	time3 = time(NULL);	//because of cards
	
	evolution.nl = Spielfeld_Create (m, n, number_of_players);	//the order is (1, 2, 3) ==> [3][1][2]
	evolution.od = Spielfeld_Create (m, n, number_of_players);

	dynamic_pointer = int_Vektor_Create (8);
	dynamic_pointer_save = int_2dim_Vektor_Create (number_of_players+1, 4);

	if (Collector_of_permutation.permutation_number_b == 0) {
		Collector_of_permutation.permutation_number_c = 1;
	}
	Collector_of_permutation.sigmas_c = unsigned_int_2dim_Vektor_Create (Fakultaet(Collector_of_permutation.permutation_number_c - 1), Collector_of_permutation.permutation_number_c);
	if (Collector_of_permutation.permutation_number_b == 0) {
		Collector_of_permutation.permutation_number_c = 0;
	}

	if (Collector_of_permutation.permutation_number_c == 0) {
		Collector_of_permutation.permutation_number_b = 1;
	}
	Collector_of_permutation.sigmas_b = unsigned_int_2dim_Vektor_Create (Fakultaet(Collector_of_permutation.permutation_number_b - 1), Collector_of_permutation.permutation_number_b);
	if (Collector_of_permutation.permutation_number_c == 0) {
		Collector_of_permutation.permutation_number_b = 0;
	}

	Journey_o.field = Spielfeld_Create (m, n, number_of_players);	//gamemode_played 11 journey, done

	Opague_o.field = Spielfeld_Create (m, n, 0);

	Allocation_o.field = Spielfeld_Create (m, n, number_of_players+2);

	// scanf("%u", &pause);	//test
	// printf("	#line 2k, after Allocation_o.field \n");	//test

	Sf_permutations = Spielfeld_Create (m, n, 0);

	// scanf("%u", &pause);	//test
	// printf("	#line 2k, after Sf_permutations \n");	//test

	if (Collector_of_permutation.permutation_number_b == 0) {
		Collector_of_permutation.amount_of_permutation_number_c = 1;
	Collector_of_permutation.permutation_number_c = 1;
	}
	Collector_of_permutation.areas_c = Spielfeld_Create (Collector_of_permutation.permutation_number_c, 2, Collector_of_permutation.amount_of_permutation_number_c-1);
	if (Collector_of_permutation.permutation_number_b == 0) {
		Collector_of_permutation.amount_of_permutation_number_c = 0;
	Collector_of_permutation.permutation_number_c = 0;
	}

	// scanf("%u", &pause);	//test
	// printf("	#line 2k, between the Collectors \n");	//test

	if (Collector_of_permutation.permutation_number_c == 0) {
		Collector_of_permutation.amount_of_permutation_number_b = 1;
	Collector_of_permutation.permutation_number_b = 1;
	}
	Collector_of_permutation.areas_b = Spielfeld_Create (Collector_of_permutation.permutation_number_b, 2, Collector_of_permutation.amount_of_permutation_number_b-1);
	if (Collector_of_permutation.permutation_number_c == 0) {
		Collector_of_permutation.amount_of_permutation_number_b = 0;
	Collector_of_permutation.permutation_number_b = 0;
	}

	// scanf("%u", &pause);	//test
	// printf("	#line 2k, before Field \n");	//test

	Field = Spielfeld_Create (m, n, number_of_players);

	// scanf("%u", &pause);	//test
	// printf("	#line 2k, before start_normal \n");	//test

	start_normal (Field, m, n, gamemode_played, number_of_players, 0, Opague_o.field, Allocation_o, single_option_representives.inverted);

	// show_field (number_of_players, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, 0, Growth_players, 0, Allocation_o);	//test, geben durch 0 ersetzt

	// scanf("%u", &pause);	//test
	// printf("	#line 2022, before numbers_of_ \n");	//test
	// printf("	AOP= %u \n", AOP);	//test
	// printf("	number_of_players= %u \n", number_of_players);	//test

	// scanf("%u", &pause);	//test
	// Spielfeld FieldTest;
	// FieldTest = (unsigned int **) calloc(1, sizeof(unsigned int*));
	// printf("Checkpoint: 1	\n ");	//test
	// FieldTest[0] = (unsigned int **) calloc(1, sizeof(unsigned int*));
	// printf("Checkpoint: 2	\n ");	//test
	// FieldTest[0][0] = (unsigned int *) calloc(1, sizeof(unsigned int));
	// printf("Checkpoint: 3	\n ");	//test


	numbers_of_ = Spielfeld_Create (7, 1, number_of_players);
	stack_of_ = Spielfeld_Create (7, 1, number_of_players);

	// scanf("%u", &pause);	//test
	// printf("	#line 2k, before tac \n");	//test

	//before this line no not-trivial-definitions
	
	limits.at_all_saver = limits.at_all;

	reset_of_ges (ges, number_of_players);
	ges_counter (Field, m, n, ges, number_of_players);
	
	// printf("Checkpoint: a	\n ");	//test
	
	// Initialisation of rmv
	rmv->win_condition = unsigned_int_Vektor_Create(AOP+1);
	rmv->numbers_of_ = Spielfeld_Create (7, 1, number_of_players);
	rmv->same = unsigned_int_Vektor_Create(NOSV);
	rmv->var_ = unsigned_int_Vektor_Create(AOP+1);
	rmv->Points =  unsigned_int_Vektor_Create(AOP+1);
	rmv->ulcer_start = unsigned_int_Vektor_Create(AOP+1);
	rmv->ulcer_lifes = unsigned_int_Vektor_Create(AOP+1);
	rmv->out_counter = unsigned_int_Vektor_Create(AOP+1);

	if (Collector_of_permutation.permutation_number_b == 0) {	// areas_c
		Collector_of_permutation.amount_of_permutation_number_c = 1;
		Collector_of_permutation.permutation_number_c = 1;
	}
	rmv->Collector_of_permutation.areas_c = Spielfeld_Create (Collector_of_permutation.permutation_number_c, 2, Collector_of_permutation.amount_of_permutation_number_c-1);
	if (Collector_of_permutation.permutation_number_b == 0) {	// areas_c
		Collector_of_permutation.amount_of_permutation_number_c = 0;
		Collector_of_permutation.permutation_number_c = 0;
	}

	if (Collector_of_permutation.permutation_number_c == 0) {	// areas_b
		Collector_of_permutation.amount_of_permutation_number_b = 1;
	Collector_of_permutation.permutation_number_b = 1;
	}
	rmv->Collector_of_permutation.areas_b = Spielfeld_Create (Collector_of_permutation.permutation_number_b, 2, Collector_of_permutation.amount_of_permutation_number_b-1);
	if (Collector_of_permutation.permutation_number_c == 0) {	// areas_b
		Collector_of_permutation.amount_of_permutation_number_b = 0;
	Collector_of_permutation.permutation_number_b = 0;
	}
	
	if (Collector_of_permutation.permutation_number_b == 0) {	// sigmas_c
		Collector_of_permutation.permutation_number_c = 1;
	}
	rmv->Collector_of_permutation.sigmas_c = unsigned_int_2dim_Vektor_Create (Fakultaet(Collector_of_permutation.permutation_number_c - 1), Collector_of_permutation.permutation_number_c);
	if (Collector_of_permutation.permutation_number_b == 0) {	// sigmas_c
		Collector_of_permutation.permutation_number_c = 0;
	}

	if (Collector_of_permutation.permutation_number_c == 0) {	// sigmas_b
		Collector_of_permutation.permutation_number_b = 1;
	}
	rmv->Collector_of_permutation.sigmas_b = unsigned_int_2dim_Vektor_Create (Fakultaet(Collector_of_permutation.permutation_number_b - 1), Collector_of_permutation.permutation_number_b);
	if (Collector_of_permutation.permutation_number_c == 0) {	// sigmas_b
		Collector_of_permutation.permutation_number_b = 0;
	}
	
	// setting rmv
	for (unsigned int p=0; p<=NOSV-1; p++) {
		rmv->same[p] = same[p];	//static during the game
	}
	for (unsigned int p=0; p<=number_of_players; p++) {
		for (unsigned int i=0; i<=6; i++) {
			rmv->numbers_of_[p][i][0] = numbers_of_[p][i][0];
		}
	}
	
	for (unsigned int p=0; p<=AOP; p++) {
		rmv->win_condition[p] = win_condition[p];
		rmv->var_[p] = var_[p];
		rmv->Points[p] = Points[p];
		rmv->ulcer_start[p] = ulcer_start[p];
		rmv->ulcer_lifes[p] = ulcer_lifes[p];
		rmv->out_counter[p] = out_counter[p];

	}
	// printf("Checkpoint: h	\n ");	//test
	
	rmv->AOP = AOP;	//static during the game
	rmv->freq = freq;	//static during the game
	rmv->player_counter = player_counter;
	rmv->all_turns_correction = all_turns_correction;
	rmv->use_number = use_number;
	rmv->round_counter = round_counter;
	rmv->rtc = rtc;	//static during the game
	rmv->rtp = rtp;	//static during the game
	// rmv->Collector_of_permutation = Collector_of_permutation;	//static during the game, already made for each component
	
	// printf("Checkpoint: i	\n ");	//test
	
	Moc_Quaffel = Moveable_objects_condition_Vektor_Create (1);
	Moc_Schnatz = Moveable_objects_condition_Vektor_Create (1);
	Moc_Klatscher = Moveable_objects_condition_Vektor_Create (2);
	Initialisierung_Moc (Moc_Quaffel, Moc_Schnatz, Moc_Klatscher, m, n);
	
	if (Allocation_o.characterization != 0) {
		for (unsigned int i=1; i<=m-2; i++) {
			for (unsigned int j=1; j<=n-2; j++) {
				if ((Field[0][i][j] != 0)&&(Field[0][i][j] <= number_of_players)) {
					set_Spielfeld_Eintrag (Field, 0, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Allocation_o.field, 0, i, j, 1);	//geben durch 0 ersetzt
				}
			}
		}
	}

	if (tac != 0){
		for (unsigned int p=1; p<=number_of_players; p+=1){
			for (unsigned int q=1; q<=6; q+=1){
				stack_of_[p][q][0] = tac;
			}
		}

	} else if (cards != 0) {
		time1 = time(NULL);
		printf("	How many cards to own (1<...<100)?\n");

		cards = get_unsigned_numeric_input_with_not_more_than_2_letters ();

		if (cards == 0) {
			printf("	That's not possible, you will take 6 !!! \n");
			cards = 6;
		}
		time2 = time(NULL);
		time_saver = difftime(time2, time1);

		// printf("	Zeitdifferenz12: %f \n", time_saver);	//test
		// scanf("%lf", &time_saver);

		anything = 0;
		unsigned int c = 0;
		unsigned int x = 0;
		while (anything == 0) {
			c += 1;
			if ((time_saver) <= 1.0*c) {
				anything = (c%6)+1;
			}
		}
		c = 0;

		time_saver = difftime(time1, time3);

		// printf("	Zeitdifferenz31: %f \n", time_saver);	//test
		// scanf("%lf", &time_saver);

		while (x == 0) {
			c += 1;
			if ((time_saver) <= 1.0*c) {
				x = (c%6)+1;
			}
		}

		for (unsigned int q=1; q<=cards; q++) {
			for (unsigned int p=1; p<=number_of_players; p++) {
				stack_of_[p][((((anything+(((p*q)/3)%6)+1)%6)+1)*(((x+q/5)%6)+1))%7][0] += 1;	// %7 weil das Ergebnis nicht durch 7 teilbar
			}
		}

		// for (unsigned f=1; f<=number_of_players; f++) {	//test
			// printf("Spieler %u:", f);
			// for (unsigned int g=1; g<=6; g++) {
				// printf("	[%u]=%u", g, stack_of_[f][g][0]);
			// }
			// printf("\n");
		// }

		c = 0;
		x = 0;
		anything = 0;
		time1 = 0;
		time2 = 0;
		time3 = 0;
		time_saver = 0.0;
	}

	level[0] = 0;
	for (unsigned int p=1; p<=number_of_players; p++) {
		if (level[p] == human) {
			level[0] = 1;
			break;
		}
	}
	if (level[0] == 1) {
		for (unsigned int p=1; p<=number_of_players; p++) {	//make it better, go on
			if (level[p] != human) {
				level[0] = 2;
				while ((level[0] != 0)&&(level[0] != 1)) {
					printf("	Skip between KI's: \n");
					printf("		Yes: 1		No: 0 \n");
					level[0] = get_unsigned_numeric_input_with_not_more_than_1_letter();
				}
				break;
			}
		}
	} else {
		level[0] = 2;
		while ((level[0] != 0)&&(level[0] != 1)) {
			printf("	Skip between KI's: \n");
			printf("		Yes: 1		No: 0 \n");
			level[0] = get_unsigned_numeric_input_with_not_more_than_1_letter();
		}
		if (level[0] == 0) {
			level[0] = 5;
		}
	}

	if ((Collector_of_permutation.amount_of_permutation_number_b != 0)||(Collector_of_permutation.amount_of_permutation_number_c != 0)) {
		translate_permutations_amounts_to_permutations_areas (Sf_permutations, m, n, Collector_of_permutation);

		// scanf("%u", &pause);	//test
		// printf("	#line 2k, after translate_permutations_amounts_to_permutations_areas \n");	//test

		// show_field (number_of_players, level, Sf_permutations, Opague_o.field, Sf_permutations, m, n, gamemode_played, information_code, 0, Growth_players, 0, Allocation_o);	//test

		get_sigmas_for_permutation_number (Collector_of_permutation.sigmas_c, Collector_of_permutation.permutation_number_c);

		// scanf("%u", &pause);	//test
		// printf("	#line 2k, after get_sigmas_for_permutation_number (c) \n");	//test

		get_sigmas_for_permutation_number (Collector_of_permutation.sigmas_b, Collector_of_permutation.permutation_number_b);
	}

	if (gamemode_played == Arena) {	//abilities in information_code
		information_code[1] = ability[5];
		information_code[2] = ability[7];
		information_code[3] = ability[8];

		if ((ability[1] != 0)&&(ability[1] != 100)) {
			Field[0][1][0] = 10*ability[1];
		}
		if ((ability[2] != 0)&&(ability[2] != 100)) {
			Field[0][0][0] = 10*ability[2];
		}
		if ((ability[3] != 0)&&(ability[3] != 100)) {
			Field[0][0][1] = 10*ability[3];
		}
		if ((ability[4] != 0)&&(ability[4] != 100)) {
			Field[0][0][n-1] = 10*ability[4];
		}
		if ((ability[6] != 0)&&(ability[6] != 100)) {
			Field[0][m-1][n-1] = 10*ability[6];
		}
		if ((ability[9] != 0)&&(ability[9] != 100)) {
			Field[0][m-1][0] = 10*ability[9];
		}

	}

	g = 1;

	if (gamemode_played == Survive) {
		while ((survive_different == 0)||(survive_different > 60)){
			printf("	Please give me a number between 1 and 60. \n");
			survive_different = get_unsigned_numeric_input_with_not_more_than_2_letters ();
		}
	}

	if (gamemode_played == Rain) {
		show_field (number_of_players, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, 0, Growth_players, 0, Allocation_o);	// geben mit 0 ersetzt
	}

	// printf("gamemode_played = %u \n", gamemode_played);	//test
	
	while (g != 0) {	//start of the turns

		// printf("gamemode_played = %u \n", gamemode_played);	//test
		// printf("g = %u \n", g);	//test
	
		if (rmv->player_counter == number_of_players) {	//Notbremse, kein Spieler spielt mehr
			break;
		}

		geben = ((g-1)%number_of_players)+1;	//aktiver Spieler, an Anzahl der Züge gekoppelt

		if (time_matters.ttt != 0) {	//reset of the time
			time_warning = 0.0;
			time_saver = 0.0;
		}

		// scanf("%u", &pause);	//test
		// printf("	#line 2k, after geben-def \n");	//test

		// printf("	test \n");
		// show_field (number_of_players, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);	//test
		// printf("	test \n");

		round_counter_before = rmv->round_counter;
		rmv->round_counter = 0;
		for (unsigned int p=1; p<=g; p+=number_of_players) {
			rmv->round_counter += 1;
		}

		survive_obstacles_generator (gamemode_played, rmv->round_counter, round_counter_before, information_code, Field, geben, Allocation_o, number_of_players, Opague_o, Sf_permutations, AOP, level, Growth_players, m, n, survive_different, ges, rmv->var_, g, rmv->use_number, tac, time_matters.ttt);

		Dynamic_ball_movement (Field, Opague_o, m, n, geben, Allocation_o, number_of_players, level, Sf_permutations, information_code, Growth_players, gamemode_played, dynamic_pointer, erd, position, g, ges, impact_tuple, rmv);
		// these two modifications do not belong to realize_modifications

		if (gamemode_played == Hunt) {	//Hunt-Formalitäten

			if (rmv->round_counter == (rtc - 1)) {
				rmv->numbers_of_[1][0][0] = 1;
			} else if ((rmv->round_counter == rtc)&&(geben == number_of_players)) {
				printf(" \n ");
				printf(" \n ");
				printf(" Ready for the last round? \n ");
				printf(" \n ");
				printf(" \n ");
			}

			if (rmv->round_counter%spf == 0) {
				information_code[1] = 1;
			} else {
				information_code[1] = 0;
			}
		}

		if ((gamemode_played == Arena)||(gamemode_played == Ulcer)) {	//last round
			if ((rmv->round_counter == rtp)&&(geben == number_of_players)) {
				printf(" \n ");
				printf(" \n ");
				printf(" Ready for the last round? \n ");
				printf(" \n ");
				printf(" \n ");
			}
		}

		// printf("\n");	//test
		// printf("	information_code: [0]=%u,	[1]=%u,	[2]=%u,	[3]=%u	\n", information_code[0], information_code[1], information_code[2], information_code[3]);
		// printf("\n");

		//previous if(geben == 1){}

		if (Opague_o.characterization >= 1) {
			opague_builder (Field, Opague_o, m, n, geben, AOP, Allocation_o, number_of_players, gamemode_played);
		}

		if ((time_matters.ttt != 0)&&(pere[geben] == 100)) {
			g+=1;
			continue;
		}

		if (ges[geben] == 1010*geben) {	//Überspringen, wenn ausgeschieden	(//mehr-gamemode_played)

			rmv->all_turns_correction += 1;
			rmv->var_[geben] = 0;		//eigentlich rmv->var_[geben] = 1010*geben, done, undone because only if rmv->var_[0] == 1 somebody goes back

			for (unsigned int i=1; i<m-1; i+=1){
				for (unsigned int j=1; j<n-1; j+=1){

					for (unsigned int p=0; p<=number_of_players; p+=1) {	//missed to include the 0, that caused not-wanted-revives.
						if (Field[p][i][j] == geben) {
							set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, p, i, j, 0);
						}
						if (Journey_o.characterization != 0){
							if (Journey_o.field[p][i][j] == geben) {
								set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Journey_o.field, p, i, j, 0);
							}
						}
					}
					if (Journey_o.characterization != 0) {
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Journey_o.field, geben, i, j, Journey_o.field[Vorganger(geben, number_of_players)][i][j]);
					}
					set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, geben, i, j, Field[Vorganger(geben, number_of_players)][i][j]);
				}
			}
			cons[geben] = cons[Vorganger(geben, number_of_players)];

			if (gamemode_played == Dynamic){
				for (unsigned int p=2; p<=5; p+=1) {
					dynamic_pointer_save[Vorganger(geben, number_of_players)][p-2] = dynamic_pointer_save[geben][p-2]; // if geben == 1 => number_of_players, sonst geben-1	(maybe a function), done
				}
			}	//KI testing... warning

			if (rmv->var_[0] == 1) {	//if "go back" is used
				g-=1;
				rmv->var_[geben] = 1010*geben;
				rmv->all_turns_correction -= 1;
			} else {
				g+=1;
			}
			continue;
		}

		if ((gamemode_played == Ulcer)&&(rmv->ulcer_start[geben] == missing)) {	//not on the field yet

			rmv->all_turns_correction += 1;

			if (rmv->var_[0] == 1) {	//if "go back" is used
				g-=1;
				rmv->var_[geben] = 1010*geben;
				rmv->all_turns_correction -= 1;
			} else {
				g+=1;
			}
			continue;
		}

		if ((level[0] != 5)&&(level[0] != 0)&&(level[geben] != human)) {
			unsigned int necessary;
			necessary = 0;
			is_it_necessary (level, ges, &necessary, geben, number_of_players);
			if (necessary == 1) {
				level[0] = 3;
			} else {
				level[0] = 1;
			}
		}

		if (level[0] <= 2) {
			for (unsigned int yer=0; yer<=5; yer++) {
				printf("\n");
			}
		}
		printf("	Round: %u \n", rmv->round_counter);
		printf("\n");

		// if (rmv->round_counter >= 66) {	//test
			// level[0] = 0;	//test
			// printf("Have a look\n");	//test
			// show_field (number_of_players, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);	//test
			// scanf("%u", &pause);	//test
			// level[0] = 3;	//test
		// }	//test

		if (Journey_o.characterization != 0) {
			if (gamemode_played == Race) {	//journey-frequence
				anything = 2*freq;
			} else {
				anything = (10*(number_of_players - rmv->player_counter) - 1);
			}

			printf("	All turns until the journey starts: %u \n", (anything - ((g-rmv->all_turns_correction-1)%anything)));
			printf("\n");

			anything = 0;
		}
		if (single_option_representives.intensity_loss_per_line_multiplication != 0) {
			if (gamemode_played == Race) {	//journey-frequence
				anything = 2*freq-2;
			} else {
				anything = (9*(number_of_players - rmv->player_counter) - 1);
			}

			printf("	All turns until the projection starts: %u \n", (anything - ((g-rmv->all_turns_correction-1)%anything)));
			printf("\n");

			anything = 0;
		}
		if ((Collector_of_permutation.amount_of_permutation_number_b != 0)||(Collector_of_permutation.amount_of_permutation_number_c != 0)) {
			if (gamemode_played == Race) {	//journey-frequence
				anything = 2*freq-3;
			} else {
				anything = (8*(number_of_players - rmv->player_counter) - 1);
			}

			printf("	All turns until the permutation starts: %u \n", (anything - ((g-rmv->all_turns_correction-1)%anything)));
			printf("\n");

			anything = 0;
		}

		if (gamemode_played == Race) {
			printf("	All turns until the wall moves forward: %u \n", (freq - ((g-1)%freq)));
			printf("\n");
		} else if (gamemode_played == Sand) {
			printf("	All turns until the squares will fall down: %u \n", (number_of_players - rmv->player_counter)*information_code[3] - ((g-rmv->all_turns_correction-1)%((number_of_players - rmv->player_counter)*information_code[3])));
			printf("\n");
		}

		w = 3;
		d = 2;
		e = 3;

		if (gamemode_played == Arena) {	//Arena-abilities werden eingesetzt

			for (unsigned int i=1; i<=AOP; i+=1) {
				if (ability[i] == geben) {
					information_code[0] = i;
				}
			}
			if (ability[1] == geben) {
				w = 1;
				d = 0;
				e = 1;
			} else if (ability[2] == geben) {
				w = 2;
				d = 1;
				e = 2;
			} else if (ability[3] == geben) {
				w = 4;
				d = 1;
				e = 4;	//abweichende e-definition
			} else if (ability[AOP] == geben) {
				if (Opague_o.characterization >= 1) {
					opague_builder (Field, Opague_o, m, n, geben, AOP, Allocation_o, number_of_players, gamemode_played);
					show_field (number_of_players, level, Sf_permutations, Opague_o.field, Opague_o.field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
				} else {
					show_field (number_of_players, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
				}

				for (unsigned int i=1; i<m-1; i+=1){	//push of electric
					for (unsigned int j=1; j<n-1; j+=1){
						if (Field[0][i][j] == geben) {
							if ((Field[0][i+1][j] != 0)&&(Field[0][i+1][j] != geben)&&((i+2) <= (m-2))) {
								if (Field[0][i+2][j] == 0) {
									set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, i+2, j, Field[0][i+1][j]);
									set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, i+1, j, 0);
								}
							}
							if ((Field[0][i-1][j] != 0)&&(Field[0][i-1][j] != geben)&&((i-2) >= 1)) {
								if (Field[0][i-2][j] == 0) {
									set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, i-2, j, Field[0][i-1][j]);
									set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, i-1, j, 0);
								}
							}
							if ((Field[0][i][j-1] != 0)&&(Field[0][i][j-1] != geben)&&((j-2) >= 1)) {
								if (Field[0][i][j-2] == 0) {
									set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, i, j-2, Field[0][i][j-1]);
									set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, i, j-1, 0);
								}
							}
							if ((Field[0][i][j+1] != 0)&&(Field[0][i][j+1] != geben)&&((j+2) <= (n-2))) {
								if (Field[0][i][j+2] == 0) {
									set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, i, j+2, Field[0][i][j+1]);
									set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, i, j+1, 0);
								}
							}
						}
					}
				}
			}
		}	// Done : index, show_field, rmv->var_ == min_1,	start_normal, dies, != 6, hint, new_life, old_dying, ability_used_counter,    übertragen: /  to do:	/	yes!

		if ((gamemode_played == Ulcer)&&(geben != 1)) {
			w = 2;
			d = 1;
			e = 2;
		}

		if (gamemode_played == Arena) {	//light und ultra_light erhalten gekürzte limits.at_all, beim Rest wird der richtige Wert eingesetzt
			if (information_code[0] == 1) {
				limits.at_all = limits.at_all_saver-2;
			} else if (information_code[0] == 2) {
				limits.at_all = limits.at_all_saver-1;
			} else {
				limits.at_all = limits.at_all_saver;
			}
		}

		if (time_matters.ttt != 0) {		//Strafen wegen der Zeit
			if ((pere[geben] != 0)&&(time_matters.warning_system <= 5)&&((pere[geben]+time_matters.warning_system) == 7)) {
				g += 1;
				printf(" \n ");
				printf("	You got a penalty. \n ");
				printf(" \n ");
				pere[geben] = 0;
				continue;
			} else if ((pere[geben] != 0)&&(time_matters.warning_system != 0)&&(((time_matters.warning_system <= 5)&&((pere[geben]+time_matters.warning_system) == 8))||((time_matters.warning_system == 6)&&(pere[geben] == 1)))) {
				old_dying (Field, Field, m, n, d, e, gamemode_played, information_code, geben, evolution.od, w, Allocation_o, Opague_o.field, number_of_players);
				change (Field, level, Sf_permutations, Field, evolution, m, n, gamemode_played, number_of_players, ges, geben, Allocation_o, Opague_o.field, information_code, Growth_players, single_option_representives);  //Change befreit
				g += 1;
				printf(" \n ");
				printf("	You got a penalty. \n ");
				printf(" \n ");
				pere[geben] = 0;
				continue;
			} else if (((time_matters.warning_system <= 5)&&((time_matters.warning_system + pere[geben]) >= 9))||((time_matters.warning_system >= 6)&&((time_matters.warning_system + pere[geben]) >= 8))) {
				printf("	Niederlage: Spieler %u \n ", geben);
				for (unsigned int i=1; i<m-1; i+=1){
					for (unsigned int j=1; j<n-1; j+=1){
						if (Field[0][i][j] == geben) {
							set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, i, j, 0);
						}
					}
				}
				ges[geben] = 1010*geben;
				rmv->player_counter += 1;
				pere[geben] = 100;
				g += 1;
				continue;
			}
		}

		if (rmv->var_[geben] == 1010*geben) {
			rmv->use_number = cons[geben];
			if (opt == 5) {
				printf("	Player %u ,do you want to keep your number (%u) or do you want to get the next one? \n", geben, cons[geben]);
				printf("	Keep the number:  1 \n");
				printf("	Get the next one:	2 \n");
				anything = get_unsigned_numeric_input_with_not_more_than_1_letter ();

				if (anything == 2) {
					rmv->use_number = random_number (num, rmv->use_number, g, rmv->var_, number_);
				} else if (anything != 1) {
					printf("	Well, you keep your number, but next time please take an option i offered. \n\n");
				}
				anything = 0;
			} else if (cards != 0) {
				printf("	Player %u ,do you want to keep your Card (%u) or do you want to get the next one? \n", geben, cons[geben]);
				printf("	Keep the number:  1 \n");
				printf("	Get the next one:	2 \n");
				anything = get_unsigned_numeric_input_with_not_more_than_1_letter ();

				if (anything == 2) {
					rmv->use_number = random_number (num, rmv->use_number, g, rmv->var_, number_);
				} else if (anything != 1) {
					printf("	Well, you keep your number, but next time please take an option i offered. \n\n");
				}
				anything = 0;
			}
		}

		if (rmv->var_[Nachfolger(geben, number_of_players)] == 1010*(Nachfolger(geben, number_of_players))){		//geben%number_of_players+1 ist der Nachfolger von geben.
			if (tac != 0) {
				stack_of_[geben][number_[geben]][0] += 1;
				rmv->numbers_of_[geben][number_[geben]][0] -= 1;
			} else if (opt == 5) {
				rmv->use_number = cons[geben];
				rmv->numbers_of_[geben][rmv->use_number][0] -= 1;
			} else if (cards != 0) {
				stack_of_[geben][number_[geben]][0] += 1;
				rmv->numbers_of_[geben][number_[geben]][0] -= 1;
			} else {
				rmv->numbers_of_[geben][number_[geben]][0] -= 1;
			}

		} else if ((cards != 0)&&(rmv->var_[geben] != 1010)) {	//if you thought about ending the game
			stack_of_[geben][rmv->use_number][0] += 1;	//Drawing a card
		}


		if ((tac != 0)&&((stack_of_[geben][1][0]+stack_of_[geben][2][0]+stack_of_[geben][3][0]+stack_of_[geben][4][0]+stack_of_[geben][5][0]+stack_of_[geben][6][0]) == 0)){
			for (unsigned int p=1; p<=6; p+=1){
				stack_of_[geben][p][0] = tac;
			}
		}

		menuoperator = 1;		//Ende der Vorbereitung

		// printf("2. g = %u \n", g);	//test
	
		//#-start
		while (menuoperator != 0) {		//Beginn des Zuges

			if (level[0] == 5) {	//show only one field for each player, if every player is a KI but you want to see what is happening
				level[0] = 2;
			}
			if (gamemode_played != Rain) {
				if (Opague_o.characterization >= 1) {
					opague_builder (Field, Opague_o, m, n, geben, AOP, Allocation_o, number_of_players, gamemode_played);
					show_field (number_of_players, level, Sf_permutations, Opague_o.field, Opague_o.field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
				} else {
					show_field (number_of_players, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
				}
			}
			if (level[0] == 2) {
				level[0] = 5;
			}

			if (gamemode_played == Fall) {
				printf("\n");
				printf("	Points player %u:   %u Point(s) \n", geben, rmv->Points[geben]);
			} else if (gamemode_played == Ulcer) {
				printf("\n");
				printf("	Lifes player %u:  %u Life(s) \n", geben, rmv->ulcer_lifes[geben]);
			} else if (gamemode_played == Dynamic) {
				printf("	\n");
				printf("	Geschwindigkeit:  Zeile: %d,  Spalte: %d \n", dynamic_pointer[2], dynamic_pointer[3]);
				printf("	Beschleunigung:   Zeile: %d,  Spalte: %d \n", dynamic_pointer[4], dynamic_pointer[5]);
				printf("	\n");
			} else if (gamemode_played == Quidditch) {
				printf("\n");
				printf("	Points player %u:   %u Points \n", geben, Qs->Points[geben]);
			}

			printf("\n");

			show_whose_turn (gamemode_played, geben, ability, Growth_players, level, number_of_players);

			if ((cards != 0)&&(rmv->var_[Nachfolger(geben, number_of_players)] != 1010*(Nachfolger(geben, number_of_players)))) {
				printf("	You draw a %u. \n\n", rmv->use_number);
			} else if ((cards != 0)&&(rmv->var_[Nachfolger(geben, number_of_players)] == 1010*(Nachfolger(geben, number_of_players)))) {
				printf("	You still draw a %u. \n\n", cons[geben]);
			}

			if ((tac != 0)||(cards != 0)){
				printf("	Your stack of numbers:	\n	1) [%u],  2) [%u],  3) [%u],  \n\n	4) [%u],  5) [%u],  6) [%u], \n", stack_of_[geben][1][0], stack_of_[geben][2][0], stack_of_[geben][3][0], stack_of_[geben][4][0], stack_of_[geben][5][0], stack_of_[geben][6][0]);
				printf("\n");
				printf("\n");
			}

			if (opt == 5){		//random number
				printf("	Your number: %u ", rmv->use_number);
				printf("\n");
				printf("\n");
				//##
			}

			//#-end

			if ((time_matters.ttt != 0)&&(time_saver == 0.0)) {
				time1 = time(NULL);
			}

			if (level[geben] == human) {
				show_options_of_actions (gamemode_played, information_code, geben);

				rmv->var_[geben] = get_unsigned_numeric_input_with_not_more_than_3_letters ();
		
				// printf("Checkpoint: rmv->var_[geben] =  %u\n", rmv->var_[geben]);	//test
		
			} else {
				// rmv->use_number = 5;	//KI testing... warning

				turn_of_KI_random (Qs, Moc_Quaffel, Moc_Schnatz, Moc_Klatscher, &KI_decision, Field, m, n, geben, Opague_o, Allocation_o, Sf_permutations, ges, Growth_players, number_of_players, gamemode_played, information_code, level, limits, single_option_representives, rain, rmv);

				// rmv->var_[geben] = 51;	//KI testing... warning

			}

			if (rmv->var_[geben] == 10){
				if (time_matters.ttt != 0) {
					time3 = time(NULL);
				}

				while (menuoperator != 7) {
					printf("\n");
					printf("\n");
					printf("	About the game: 1 \n	Statistics: 2 \n	The numbers: 3 \n	The limits: 4 \n	Get Hints: 5 \n	Suprise: 6 \n	Quit Menu: 7 \n");
					menuoperator = get_unsigned_numeric_input_with_not_more_than_1_letter();

					if (menuoperator == 1){
						About_the_game (gamemode_played, geben, limits, number_of_players, freq, w, d, e);

					} else if (menuoperator == 2){
						printf("\n");
						printf("	turns at all: %u \n", g);

						show_statistics (number_of_players, gamemode_played, rmv->numbers_of_, rmv->Points, exclude_counter, rmv->ulcer_lifes, ges, pere, ability, time_matters.ttt, Qs);

					} else if (menuoperator == 3){

						show_the_numbers (gamemode_played, w, d, e, geben);

					} else if (menuoperator == 4){
						if ((gamemode_played != Ulcer)&&(gamemode_played != Survive)) {
							printf("	Limit of development:	%u \n", limits.new);
							if (gamemode_played != Contact) {
								printf("	Limit in total:		%u \n", limits.at_all);
							}
						}
					} else if (menuoperator == 5){

						get_hints (level, Sf_permutations, gamemode_played, Field, geben, w, d, e, m, n, information_code, Opague_o, Growth_players, AOP, Allocation_o, number_of_players);

						//show_field (number_of_players, level, Sf_permutations, Opague_o.field, hint, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);		//teste die destroy-funktion für Spielfelder, done
					} else if (menuoperator == 6){

						if (suprise == 0) {
							for (unsigned int i=1; i<m-1; i+=1){
								for (unsigned int j=1; j<n-1; j+=1){

									set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, geben, i, j, Field[0][i][j]);

									if (Journey_o.characterization != 0){
										set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Journey_o.field, geben, i, j, Journey_o.field[0][i][j]);
									}
								}
							}
							sup_num = rmv->use_number;
						}

						while (menuoperator != 1) {

							printf("	Creator menu.   Change number: 1	Suprise: 2	Suprise undo: 3	Back: 4 \n");
							anything = get_unsigned_numeric_input_with_not_more_than_1_letter ();
							if (anything == 1){
								printf("	number = ? \n");
								rmv->use_number = get_unsigned_numeric_input_with_not_more_than_1_letter();
							} else if (anything == 2){

								printf("\n");
								suprise = get_unsigned_numeric_input_with_not_more_than_2_letters();

								if (suprise == 31){
									for (unsigned int i=2; i<m-2; i+=1){
										for (unsigned int j=1; j<n-1; j+=1){
											if (Field[0][i][j] != 0){
												if (Field[0][i][j] == geben){
													set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, i, j, Nachfolger(geben, number_of_players));
												} else if (Field[0][i][j] == Nachfolger(geben, number_of_players)){
													set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, i, j, geben);
												}
											}
										}
									}
								}

								if (suprise == 257642){
									printf("\n");
									printf("	This game and it's C-Code is created and written by Kjell Lewandowski, born 06.03.1998, Germany.\n");
									printf("	Date: 10.10.2017 \n");
									printf("\n");
								}

								if (suprise == 13){
									for (unsigned int i=1; i<m-1; i+=1){
										for (unsigned int j=1; j<n-1; j+=1){
											if (Field[0][i][j] == Nachfolger(geben, number_of_players)){
												set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, i, j, 0);
											}
											if (i == (m-2)){
												set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, geben, m-2, j, Nachfolger(geben, number_of_players));
											}
										}
									}
								}

							} else if (anything == 3){
								rmv->use_number = sup_num;
							} else if (anything == 4){
								menuoperator = 1;
							} else {
								printf("	Invalid comment \n");
							}
						}
					}

				}		// menuoperator = 7

				if (level[0] == 5) {
					level[0] = 2;
				}
				if (gamemode_played == Rain) {		//##
					if (Opague_o.characterization >= 1) {
						opague_builder (Field, Opague_o, m, n, geben, AOP, Allocation_o, number_of_players, gamemode_played);
						show_field (number_of_players, level, Sf_permutations, Opague_o.field, Opague_o.field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
					} else {
						show_field (number_of_players, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
					}	//show_field über menuoperator = 7 und stack und so löschen, (verschiebe menuoperator!=0 - Schleife) ,done

					printf("\n");

				}
				if (level[0] == 2) {
					level[0] = 5;
				}

				if (time_matters.ttt != 0) {
					time4 = time(NULL);
					time_saver += difftime(time4, time3);
				}
			}		//Menu-end.

			menuoperator = 0;

			if (rmv->var_[geben] == 10) {
				menuoperator = 1;
				rmv->var_[geben] = 5;		//## to avoid the mistake-note by closing the menu
			}

			if (((tac != 0)||(cards != 0))&&(rmv->var_[geben] <= min_1)&&(rmv->var_[geben] > 10)){
				unsigned int tac_controll;	//also used for cards
				tac_controll = 0;
				if (((rmv->var_[geben]%10) > 2)||((rmv->var_[geben]%10) == 0)){
					rmv->var_[geben] = 7;
					menuoperator = 1;
				} else {
					for (unsigned int z=rmv->var_[geben]; z>2; z-=10){
						tac_controll += 1;
					}
					if (stack_of_[geben][tac_controll][0] == 0){
						rmv->var_[geben] = 7;
						menuoperator = 1;
					} else {
						stack_of_[geben][tac_controll][0] -= 1;		//Die tac/cards-Abrechnung
					}
				}
			} else if (((tac != 0)||(cards != 0))&&(rmv->var_[geben] != 100)&&(rmv->var_[geben] != 1010*geben)&&(rmv->var_[geben] != 0)&&(rmv->var_[geben] != 5)) {
				rmv->var_[geben] = 7;
			}
			//tac/cards-mode

			if (opt == 5){
				controll_1 = 10+rmv->use_number;
				controll_2 = 11+rmv->use_number;

				for (unsigned int i=0; i<rmv->use_number-1; i+=1){
					controll_1 += 9;
					controll_2 += 9;
				}

				if (rmv->var_[geben] == 0){
					controll_1 = 0;
					controll_2 = 0;
				}
				if (rmv->var_[geben] == 100){
					controll_1 = 100;
					controll_2 = 100;
				}
				if (rmv->var_[geben] == 1010*geben){
					controll_1 = 1010*geben;
					controll_2 = 1010*geben;
				}
			}

			if (((rmv->var_[geben] > 0)&&(rmv->var_[geben] < 10))||(((opt == 5)&&(rmv->var_[geben] != controll_1))&&((opt == 5)&&(rmv->var_[geben] != controll_2)))){

				if (rmv->var_[geben] != 5) {		//#-start
					printf("	You made a mistake, try again: \n");
					printf("\n");
					printf("\n");
				} else {
					printf("	You closed the menu. \n");
					printf("\n");
					printf("\n");
				}		//#-end

				//enough

				menuoperator = 1;	//menuoperator = 1 : Back to while(menuoperator!=0)
			}

		}     // menuoperator = 0

		suprise = 0;

		if (rmv->var_[geben] == 0){
			printf("	Do you really want to end the game ? \n");
			printf("	Yes: 0		No: 1 \n");
			anything = get_unsigned_numeric_input_with_not_more_than_1_letter ();
			if (anything == 0){
				break;
			} else if (anything == 1){
				anything = 0;
				// rmv->var_[geben] = 1010;
				continue;	//g+=1 is at the end, so there is no need to reduce g
			} else {
				printf("	0 or 1, it is so difficult to understand? \n");
				printf("	Well, it seems I have to end it by myself... \n");
				break;
			}
		} else {

			// printf("Checkpoint: rmv->var_[geben] accepted \n");	//test

			if (rmv->var_[geben] == 100){		//1, 2, 3,... durch "geben" ersetzen, done

				rmv->var_[0] = 1;

				if (gamemode_played == Dynamic) {
					for (unsigned int p=2; p<=5; p+=1) {

						dynamic_pointer[p] = dynamic_pointer_save[Vorganger(geben, number_of_players)][p-2];	//if

					}
				}
				if (cards != 0) {
					stack_of_[geben][rmv->use_number][0] -= 1;
				}

				cons[geben] = rmv->use_number;

				for (unsigned int i=1; i<m-1; i+=1){
					for (unsigned int j=1; j<n-1; j+=1){

						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, i, j, Field[Vorganger(geben, number_of_players)][i][j]);

						if (Allocation_o.characterization != 0) {
							set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Allocation_o.field, 0, i, j, Allocation_o.field[Vorganger(geben, number_of_players)+2][i][j]);	//+2 wegen Having_too_muchverschiebung
						}

						if (Journey_o.characterization != 0){
							set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Journey_o.field, 0, i, j, Journey_o.field[Vorganger(geben, number_of_players)][i][j]);
						}

					}
				}

				if (Opague_o.characterization >= 1) {
					opague_builder (Field, Opague_o, m, n, Vorganger(geben, number_of_players), AOP, Allocation_o, number_of_players, gamemode_played);
					show_field (number_of_players, level, Sf_permutations, Opague_o.field, Opague_o.field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
				} else {
					show_field (number_of_players, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
				}

				g-=1;
				rmv->var_[geben] = 1010*geben;
				if (gamemode_played == Ulcer) {
					rmv->ulcer_lifes[geben] += 1;
					rmv->ulcer_start[geben] = missing;
				}
				continue;
			} else {

				if (rmv->var_[Nachfolger(geben, number_of_players)] != 1010*(Nachfolger(geben, number_of_players))){

					for (unsigned int i=1; i<m-1; i+=1){
						for (unsigned int j=1; j<n-1; j+=1){
							set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, geben, i, j, Field[0][i][j]);

							if (Allocation_o.characterization != 0) {
								set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Allocation_o.field, geben+2, i, j, Allocation_o.field[0][i][j]);	//geben+2 wegen indexverschiebung
							}

							if (Journey_o.characterization != 0){
								set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Journey_o.field, geben, i, j, Journey_o.field[0][i][j]);
							}
						}
					} //KI testing... warning

					if (gamemode_played == Dynamic) {
						for (unsigned int p=2; p<=5; p+=1) {
							dynamic_pointer_save[geben][p-2] = dynamic_pointer[p];
						}
					}
				}

				rmv->var_[0] = 0;

		// printf("3. g = %u \n", g);	//test
	
				if (rmv->var_[geben] < 50){	//KI has [no need] to do this, it has!

					// printf("Checkpoint: rmv->var_[geben]<50 accepted \n");	//test

					if (rmv->var_[geben] == Plus_){
						rmv->numbers_of_[geben][1][0] += 1;
						if (level[geben] == human) {
							Plus (level, Sf_permutations, m, n, geben, Field, limits.at_all, gamemode_played, information_code, number_of_players, Growth_players, Opague_o, Allocation_o);
						}
					} else if (rmv->var_[geben] == Minus_) {
						rmv->numbers_of_[geben][1][0] += 1;
						if (level[geben] == human) {
							Minus (level, Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Growth_players, Opague_o, Allocation_o, number_of_players);
						}
					} else if (rmv->var_[geben] == Move_2) {
						rmv->numbers_of_[geben][2][0] += 1;
						if (level[geben] == human) {
							Move (level, Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Growth_players, Opague_o, Allocation_o, number_of_players);
						}
					} else if (rmv->var_[geben] == Move_4) {
						rmv->numbers_of_[geben][4][0] += 1;
						if (level[geben] == human) {
							Move (level, Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Growth_players, Opague_o, Allocation_o, number_of_players);
						}
					} else if (rmv->var_[geben] == Change_) {
						rmv->numbers_of_[geben][2][0] += 1;
						if (level[geben] == human) {
							Change (level, Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Growth_players, Opague_o, position, Allocation_o, number_of_players);
						}
					} else if (rmv->var_[geben] == Destroy_) {
						rmv->numbers_of_[geben][3][0] += 1;
						if (level[geben] == human) {
							Destroy (level, Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Growth_players, Opague_o, Allocation_o, number_of_players);
						}
					} else if (rmv->var_[geben] == Boost_) {
						rmv->numbers_of_[geben][4][0] += 1;
					} else if (rmv->var_[geben] == Revive_) {
						rmv->numbers_of_[geben][3][0] += 1;
					}
				} else {

					// printf("Checkpoint: rmv->var_[geben]>50 accepted \n");	//test
					// printf("Checkpoint: rmv->var_[geben]>50 (1) \n");	//test

					if (rmv->var_[geben] == new_4_5){rmv->numbers_of_[geben][5][0] += 1; w += 1;}		//w
					// printf("Checkpoint: rmv->var_[geben]>50 (2) \n");	//test
			
					if (rmv->var_[geben] == new_2){rmv->numbers_of_[geben][5][0] += 1; w -= 1;}		//w
					// printf("Checkpoint: rmv->var_[geben]>50 (3) \n");	//test
			
					if (rmv->var_[geben] == max_4){rmv->numbers_of_[geben][6][0] += 1; e += 1;}		//e
					// printf("Checkpoint: rmv->var_[geben]>50 (4) \n");	//test
			
			if (rmv->var_[geben] == min_1){
				// printf("Checkpoint: rmv->var_[geben]>50 (5) \n");	//test
				rmv->numbers_of_[geben][6][0] += 1;
				// printf("Checkpoint: rmv->var_[geben]>50 (6) \n");	//test
				if (d != 0) {
					d -= 1;
					// printf("Checkpoint: rmv->var_[geben]>50 (7) \n");	//test
				} else {
					d = 10;
					// printf("Checkpoint: rmv->var_[geben]>50 (8) \n");	//test
				}
			}		//d
			
			// printf("Checkpoint: rmv->var_[geben]>50 (9) \n");	//test
			
				}
		
				// printf("Checkpoint: functions accepted \n");	//test
		
				if (time_matters.ttt != 0) {
					time2 = time(NULL);		//wirklich die eingabe abwarten, done
					time_warning = ((difftime(time2, time1)) - time_saver);

					///printf("	time_warning: %f \n", time_warning);		//test

					if ((pere[geben] != 0)&&((pere[geben] + time_matters.warning_system) <= 6)) {
						if (pere[geben] == 1) {
							if (time_matters.warning_system <= 2) {
								time_warning += 1.0;
							} else if (time_matters.warning_system == 3) {
								time_warning += 2.0;
							} else if (time_matters.warning_system == 4) {
								time_warning += 3.0;
							} else if (time_matters.warning_system == 5) {
								time_warning += 5.0;
							}
						} else if (pere[geben] == 2) {
							if (time_matters.warning_system == 1) {
								time_warning += 2.0;
							} else if (time_matters.warning_system == 2) {
								time_warning += 3.0;
							} else if (time_matters.warning_system == 3) {
								time_warning += 5.0;
							} else if (time_matters.warning_system == 4) {
								time_warning += 6.0;
							}
						} else if (pere[geben] == 3) {
							if (time_matters.warning_system == 1) {
								time_warning += 3.0;
							} else if (time_matters.warning_system == 2) {
								time_warning += 5.0;
							} else if (time_matters.warning_system == 3) {
								time_warning += 8.0;
							}
						} else if (pere[geben] == 4) {
							if (time_matters.warning_system == 1) {
								time_warning += 4.0;
							} else if (time_matters.warning_system == 2) {
								time_warning += 7.0;
							}
						} else if (pere[geben] == 5) {
							if (time_matters.warning_system == 1) {
								time_warning += 5.0;
							}
						}
					}

					if ((gamemode_played == Hunt)&&(geben == 1)) {	//keep it
						if (time_warning > 10.0) {	//hunted one bonus
							time_warning -= 10.0;
						} else {
							time_warning = 0.0;
						}
					}
					if (time_warning > (1.0*time_matters.ttt)) {
						pere[0] += 1;
						printf("	You took too much time! %f sec more than you should. \n", (time_warning-1.0*time_matters.ttt) );
						printf(" \n");
						for (unsigned int p=16; p>=1; p-=3) {	//index_verschiebung
							if ((time_warning-1.0*time_matters.ttt) > 1.0*(p-1)) {
								pere[geben] = (((p-1)/3) + 1);
								break;
							}
						}
					} else {
						pere[geben] = 0;
					}
					//printf("	pere[%u]: %u \n", geben, pere[geben] );	//test
				}
		
				//development_start
		
				// printf("4. g = %u \n", g);	//test
	
				// printf("Checkpoint: development_start \n");	//test
		
				basic_development (Field, Field, m, n, geben, Opague_o.field, Allocation_o, Sf_permutations, ges, Growth_players, number_of_players, gamemode_played, information_code, level, w, d, e, rmv->var_[geben], evolution, &num, &g, Journey_o, limits, single_option_representives, position, &KI_decision, rain, evet);

				// printf("Checkpoint: development_end \n");	//test
		
				// printf("5. g = %u \n", g);	//test
	
				// development_end
		
				// printf("Checkpoint: realize_modifications_start \n");	//test
		
				realize_modifications (Qs, Moc_Schnatz, Moc_Quaffel, Moc_Klatscher, Field, Field, Opague_o, Allocation_o, Sf_permutations, ges, &g, m, n, geben, number_of_players, gamemode_played, level, information_code, Growth_players, Journey_o, rain, single_option_representives, rmv, evet);
				
				// printf("Checkpoint: realize_modifications_end \n");	//test
		
				// printf("6. g = %u \n", g);	//test
	
				// if (gamemode_played == Contact) {	// Copy from realize_modifications

					// if (real == evet) {
						// if (Opague_o.characterization >= 1) {
							// opague_builder (Field, Opague_o, m, n, geben, AOP, Allocation_o, number_of_players, gamemode_played);
							// show_field (number_of_players, level, Sf_permutations, Opague_o.field, Opague_o.field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
						// } else {
							// show_field (number_of_players, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
						// }
					// }
					// battle (m, n, Field, geben, Opague_o.field, Allocation_o, number_of_players, gamemode_played);	// Copy from realize_modifications
				// }
		
				// reset_of_ges (ges, number_of_players);	// Copy from realize_modifications
				// if (gamemode_played == Contact) {	// Copy from realize_modifications
					// ges_counter (Field, m, n, ges, number_of_players);
					// who_is_out (ges, number_of_players, rmv);

					// for (unsigned int p=1; p<=number_of_players; p++) {
						// if (ges[p] <= 5){
							// rmv->numbers_of_[p][0][0] += 1;
						// }
					// }

					// if (rmv->player_counter == (number_of_players - 1)) {
						// for (unsigned int p=1; p<=number_of_players; p++) {
							// if (ges[p] != p*1010) {
								// printf("	Sieg: Spieler %u \n", p);
							// }
							// break;
						// }
						// show_field (number_of_players, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
						// break;
					// }
				// }

				if (rmv->var_[Nachfolger(geben, number_of_players)] != 1010*(Nachfolger(geben, number_of_players))) {
					cons[geben] = rmv->use_number;
				}

				rmv->use_number = random_number (num, rmv->use_number, g, rmv->var_, number_);

				if ((opt != 5)&&(rmv->var_[geben] <= min_1)){
					controll_1 = 0;
					for (unsigned int z=rmv->var_[geben]; z>2; z-=10){
						controll_1 += 1;
					}
					number_[geben] = controll_1;
					controll_1 = 0;
				}
			}
		}

		//normal_end
		// printf("Checkpoint: normal_end \n");	//test
		// printf("7.g = %u \n", g);	//test
		
		//end of sections of geben, but geben is still active	//try to put the following section befor this, transfer the undone of special action under "Go back" to the main if. go on
		if (level[0] <= 2) {
			printf("\n");
		}

		// printf("	Existing Fields: %d \n ", Spielfeld_counter);	//test
		// printf("	Existing Vektors: %d \n ", Vektor_counter);	//test
		// printf("	\n ");
		// printf("	#line 4k, geben=%u \n", geben);	//test

		if (gamemode_played == Ulcer) {
			if (rmv->ulcer_start[0] == 100) {
				for (unsigned int p=1; p<=number_of_players; p+=1) {
					if (rmv->out_counter[p] == 0) {
						rmv->out_counter[p] = 1;
						break;
					}
				}
			}
			rmv->ulcer_start[0] = 0;
			printf("	Who`s still alive? \n");

			for (unsigned int p=1; p<=number_of_players; p+=1) {
				for (unsigned int r=1; r<=number_of_players; r+=1) {
					if (rmv->out_counter[r] == p) {
						rmv->ulcer_lifes[p] = 1000;
					break;
					}
				}

				if (rmv->ulcer_lifes[p] != 1000) {
					printf("	Spieler %u \n", p);
				} else {
					rmv->ulcer_lifes[p] = 0;
				}
			}

			printf("\n");
			printf("\n");

			printf("	Top Ulcer: \n");
			for (unsigned int p=1; p<=number_of_players; p+=1) {
				if (rmv->out_counter[1] == 0) {
					printf("		All were bad. \n");
					break;
				}

				if (rmv->out_counter[p] != 0) {
					if (rmv->out_counter[p] < number_of_players) {	//It is < and not <=, because the first one has not the aim to kill the last player
					printf("		No.%u: %u \n", p-rmv->ulcer_start[0], rmv->out_counter[p]+1);
					} else {
						rmv->ulcer_start[0] = 1;
					}
				}
			}
			printf("\n");
			printf("\n");

			printf("	Lifes: \n");
			for (unsigned int p=1; p<=number_of_players; p+=1) {
				printf("		Spieler %u: %u life(s) left.\n", p, rmv->ulcer_lifes[p]);
			}
			printf("\n");
			printf("\n");
		}
		
		if (g == 0) {
			break;
		} else {
			g += 1;
		}
	}

	level[0] = 0;

	printf(" \n");
	printf("	Show statistics:	yes: 1		no: 0 \n");
	anything = get_unsigned_numeric_input_with_not_more_than_1_letter ();
	if (anything == 1){
		printf("	\n");
		show_statistics (number_of_players, gamemode_played, rmv->numbers_of_, rmv->Points, exclude_counter, rmv->ulcer_lifes, ges, pere, ability, time_matters.ttt, Qs);

	}

	if (gamemode_played == Hunt) {
		for (unsigned int p=0; p<=3; p+=1) {
			information_code[p] = 1;
		}
	}

	printf("\n");
	printf("	Round: %u \n", rmv->round_counter);
	printf("\n");

	show_field (number_of_players, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);

	printf("	\n ");
	printf("	\n ");
	printf("	Do you want to play another match?	\n		Yes: 1		No:  0 ");
	*playtime = get_unsigned_numeric_input_with_not_more_than_1_letter ();
	if (*playtime == 0) {
		printf("				     ___ \n ");
	} else if (*playtime > 1) {
		printf("	it was a -1-, wasn't it?");
	}
	if (*playtime >= 1) {
		*playtime = 10;

		printf(" \n ");
		printf(" \n ");

		printf("	Do you want to play a revanche? \n ");
		printf("	yes: 1		No: 0 \n ");
		same[0] = get_unsigned_numeric_input_with_not_more_than_1_letter ();

		// printf("	same[0] = %u \n", same[0]);	//test

		if (same[0] > 1) {
			printf("	it was a -1-, wasn't it?");
			same[0] = 1;

		}
		if (same[0] == 1) {
			same[23] = rmv->use_number;
		}
		printf("	\n ");
		printf("	\n ");
		printf("	\n ");
		printf("	\n ");

	}

	// Aufräumphase !!!


	// printf("	Existing Fields: %d \n ", Spielfeld_counter);	//test
	// printf("	Existing Vektors: %d \n ", Vektor_counter);	//test

	int_Vektor_Destroy (dynamic_pointer);

	// printf("	Existing Fields: %d \n ", Spielfeld_counter);	//test
	// printf("	Existing Vektors: %d \n ", Vektor_counter);	//test
	// printf("	\n ");
	// printf("	#line 12k, 1\n");	//test
	// scanf("%u", &pause);	//test

	unsigned_int_Vektor_Destroy (Points);
	unsigned_int_Vektor_Destroy (rmv->Points);
	
	// printf("	Existing Fields: %d \n ", Spielfeld_counter);	//test
	// printf("	Existing Vektors: %d \n ", Vektor_counter);	//test
	// printf("	\n ");
	// printf("	#line 12k, 2\n");	//test
	// scanf("%u", &pause);	//test

	int_2dim_Vektor_Destroy (dynamic_pointer_save, number_of_players+1);

	// printf("	Existing Fields: %d \n ", Spielfeld_counter);	//test
	// printf("	Existing Vektors: %d \n ", Vektor_counter);	//test
	// printf("	\n ");
	// printf("	#line 12k, 3\n");	//test
	// scanf("%u", &pause);	//test

	unsigned_int_Vektor_Destroy (position);

	// printf("	Existing Fields: %d \n ", Spielfeld_counter);	//test
	// printf("	Existing Vektors: %d \n ", Vektor_counter);	//test
	// printf("	\n ");
	// printf("	#line 12k, 4\n");	//test
	// scanf("%u", &pause);	//test

	Spielfeld_Destroy (Field, m, number_of_players);

	// printf("	Existing Fields: %d \n ", Spielfeld_counter);	//test
	// printf("	Existing Vektors: %d \n ", Vektor_counter);	//test
	// printf("	\n ");
	// printf("	#line 12k, 5\n");	//test
	// scanf("%u", &pause);	//test

	Spielfeld_Destroy (evolution.od, m, number_of_players);

	// printf("	Existing Fields: %d \n ", Spielfeld_counter);	//test
	// printf("	Existing Vektors: %d \n ", Vektor_counter);	//test
	// printf("	\n ");
	// printf("	#line 12k, 6\n");	//test
	// scanf("%u", &pause);	//test

	Spielfeld_Destroy (evolution.nl, m, number_of_players);

	// printf("	Existing Fields: %d \n ", Spielfeld_counter);	//test
	// printf("	Existing Vektors: %d \n ", Vektor_counter);	//test
	// printf("	\n ");
	// printf("	#line 12k, 7\n");	//test
	// scanf("%u", &pause);	//test

	Spielfeld_Destroy (Opague_o.field, m, 0);

	// printf("	Existing Fields: %d \n ", Spielfeld_counter);	//test
	// printf("	Existing Vektors: %d \n ", Vektor_counter);	//test
	// printf("	\n ");
	// printf("	#line 12k, 8\n");	//test
	// scanf("%u", &pause);	//test

	Spielfeld_Destroy (numbers_of_, 7, number_of_players);
	Spielfeld_Destroy (rmv->numbers_of_, 7, number_of_players);
	
	// printf("	Existing Fields: %d \n ", Spielfeld_counter);	//test
	// printf("	Existing Vektors: %d \n ", Vektor_counter);	//test
	// printf("	\n ");
	// printf("	#line 12k, 9\n");	//test
	// scanf("%u", &pause);	//test

	Spielfeld_Destroy (stack_of_, 7, number_of_players);

	// printf("	Existing Fields: %d \n ", Spielfeld_counter);	//test
	// printf("	Existing Vektors: %d \n ", Vektor_counter);	//test
	// printf("	\n ");
	// printf("	#line 12k, 10\n");	//test
	// scanf("%u", &pause);	//test

	Spielfeld_Destroy (Journey_o.field, m, number_of_players);

	// printf("	Existing Fields: %d \n ", Spielfeld_counter);	//test
	// printf("	Existing Vektors: %d \n ", Vektor_counter);	//test
	// printf("	\n ");
	// printf("	#line 12k, 11\n");	//test
	// scanf("%u", &pause);	//test

	Spielfeld_Destroy (Allocation_o.field, m, number_of_players+2);

	// printf("	Existing Fields: %d \n ", Spielfeld_counter);	//test
	// printf("	Existing Vektors: %d \n ", Vektor_counter);	//test
	// printf("	\n ");
	// printf("	#line 12k, 12\n");	//test
	// scanf("%u", &pause);	//test

	Spielfeld_Destroy (Sf_permutations, m, 0);

	// printf("	Existing Fields: %d \n ", Spielfeld_counter);	//test
	// printf("	Existing Vektors: %d \n ", Vektor_counter);	//test
	// printf("	\n ");
	// printf("	#line 12k, 13\n");	//test
	// scanf("%u", &pause);	//test
	if (Collector_of_permutation.permutation_number_b == 0) {
		Collector_of_permutation.amount_of_permutation_number_c = 1;
		Collector_of_permutation.permutation_number_c = 1;
	}
	Spielfeld_Destroy (Collector_of_permutation.areas_c, Collector_of_permutation.permutation_number_c, Collector_of_permutation.amount_of_permutation_number_c-1);
	Spielfeld_Destroy (rmv->Collector_of_permutation.areas_c, Collector_of_permutation.permutation_number_c, Collector_of_permutation.amount_of_permutation_number_c-1);
	if (Collector_of_permutation.permutation_number_b == 0) {
		Collector_of_permutation.amount_of_permutation_number_c = 0;
		Collector_of_permutation.permutation_number_c = 0;
	}

	// printf("	Existing Fields: %d \n ", Spielfeld_counter);	//test
	// printf("	Existing Vektors: %d \n ", Vektor_counter);	//test
	// printf("	\n ");
	// printf("	#line 12k, 14\n");	//test
	// scanf("%u", &pause);	//test

	if (Collector_of_permutation.permutation_number_c == 0) {
		Collector_of_permutation.amount_of_permutation_number_b = 1;
		Collector_of_permutation.permutation_number_b = 1;
	}
	Spielfeld_Destroy (Collector_of_permutation.areas_b, Collector_of_permutation.permutation_number_b, Collector_of_permutation.amount_of_permutation_number_b-1);
	Spielfeld_Destroy (rmv->Collector_of_permutation.areas_b, Collector_of_permutation.permutation_number_b, Collector_of_permutation.amount_of_permutation_number_b-1);
	if (Collector_of_permutation.permutation_number_c == 0) {
		Collector_of_permutation.amount_of_permutation_number_b = 0;
		Collector_of_permutation.permutation_number_b = 0;
	}
	
	// printf("	Existing Fields: %d \n ", Spielfeld_counter);	//test
	// printf("	Existing Vektors: %d \n ", Vektor_counter);	//test
	// printf("	\n ");
	// printf("	#line 12k, 15\n");	//test
	// scanf("%u", &pause);	//test

	if (Collector_of_permutation.permutation_number_b == 0) {
		Collector_of_permutation.permutation_number_c = 1;
	}
	unsigned_int_2dim_Vektor_Destroy (Collector_of_permutation.sigmas_c, Fakultaet(Collector_of_permutation.permutation_number_c - 1));
	unsigned_int_2dim_Vektor_Destroy (rmv->Collector_of_permutation.sigmas_c, Fakultaet(Collector_of_permutation.permutation_number_c - 1));
	if (Collector_of_permutation.permutation_number_b == 0) {
		Collector_of_permutation.permutation_number_c = 0;
	}

	// printf("	Existing Fields: %d \n ", Spielfeld_counter);	//test
	// printf("	Existing Vektors: %d \n ", Vektor_counter);	//test
	// printf("	\n ");
	// printf("	#line 12k, 15.1\n");	//test
	// scanf("%u", &pause);	//test

	if (Collector_of_permutation.permutation_number_c == 0) {
		Collector_of_permutation.permutation_number_b = 1;
	}
	unsigned_int_2dim_Vektor_Destroy (Collector_of_permutation.sigmas_b, Fakultaet(Collector_of_permutation.permutation_number_b - 1));
	unsigned_int_2dim_Vektor_Destroy (rmv->Collector_of_permutation.sigmas_b, Fakultaet(Collector_of_permutation.permutation_number_b - 1));
	if (Collector_of_permutation.permutation_number_c == 0) {
		Collector_of_permutation.permutation_number_b = 0;
	}

	// printf("	Existing Fields: %d \n ", Spielfeld_counter);	//test
	// printf("	Existing Vektors: %d \n ", Vektor_counter);	//test
	// printf("	\n ");
	// printf("	#line 12k, 15.2\n");	//test
	// scanf("%u", &pause);	//test

	unsigned_int_Vektor_Destroy (level);

	// printf("	Existing Fields: %d \n ", Spielfeld_counter);	//test
	// printf("	Existing Vektors: %d \n ", Vektor_counter);	//test
	// printf("	\n ");
	// printf("	#line 12k, 16\n");	//test
	// scanf("%u", &pause);	//test

	unsigned_int_Vektor_Destroy (rmv->win_condition);

	// printf("	Existing Fields: %d \n ", Spielfeld_counter);	//test
	// printf("	Existing Vektors: %d \n ", Vektor_counter);	//test
	// printf("	\n ");
	// printf("	#line 12k, 17\n");	//test
	// scanf("%u", &pause);	//test

	unsigned_int_Vektor_Destroy (rmv->var_);

	// printf("	Existing Fields: %d \n ", Spielfeld_counter);	//test
	// printf("	Existing Vektors: %d \n ", Vektor_counter);	//test
	// printf("	\n ");
	// printf("	#line 12k, 18\n");	//test
	// scanf("%u", &pause);	//test

	unsigned_int_Vektor_Destroy (rmv->ulcer_start);

	// printf("	Existing Fields: %d \n ", Spielfeld_counter);	//test
	// printf("	Existing Vektors: %d \n ", Vektor_counter);	//test
	// printf("	\n ");
	// printf("	#line 12k, 19\n");	//test
	// scanf("%u", &pause);	//test

	unsigned_int_Vektor_Destroy (rmv->ulcer_lifes);

	// printf("	Existing Fields: %d \n ", Spielfeld_counter);	//test
	// printf("	Existing Vektors: %d \n ", Vektor_counter);	//test
	// printf("	\n ");
	// printf("	#line 12k, 20\n");	//test
	// scanf("%u", &pause);	//test

	unsigned_int_Vektor_Destroy (rmv->out_counter);

	// printf("	Existing Fields: %d \n ", Spielfeld_counter);	//test
	// printf("	Existing Vektors: %d \n ", Vektor_counter);	//test
	// printf("	\n ");
	// printf("	#line 12k, 21\n");	//test
	// scanf("%u", &pause);	//test

	unsigned_int_Vektor_Destroy (rmv->same);

	// printf("	Existing Fields: %d \n ", Spielfeld_counter);	//test
	// printf("	Existing Vektors: %d \n ", Vektor_counter);	//test
	// printf("	\n ");
	// printf("	#line 12k, 22\n");	//test
	// scanf("%u", &pause);	//test

	Realize_modifications_variables_Vektor_Destroy (rmv);

	// printf("	Existing Fields: %d \n ", Spielfeld_counter);	//test
	// printf("	Existing Vektors: %d \n ", Vektor_counter);	//test
	// printf("	\n ");
	// printf("	#line 12k, 22.1\n");	//test
	// scanf("%u", &pause);	//test

	Moveable_objects_condition_Vektor_Destroy (Moc_Klatscher);
	Moveable_objects_condition_Vektor_Destroy (Moc_Quaffel);
	Moveable_objects_condition_Vektor_Destroy (Moc_Schnatz);
	
	// printf("	Existing Fields: %d \n ", Spielfeld_counter);	//test
	// printf("	Existing Vektors: %d \n ", Vektor_counter);	//test
	// printf("	\n ");
	// printf("	#line 13k, 23\n");	//test
	// scanf("%u", &pause);	//test

}

// /*
void realize_modifications (Quidditch_setup* Qs, Moveable_objects_condition* Moc_Schnatz, Moveable_objects_condition* Moc_Quaffel, Moveable_objects_condition* Moc_Klatscher, Spielfeld Field, Spielfeld Spiel, Special_Fields Opague_o, Special_Fields Allocation_o, Spielfeld Sf_permutations, unsigned int* ges, unsigned int* g, unsigned int m, unsigned int n, unsigned int geben, unsigned int number_of_players, unsigned int gamemode_played, unsigned int* level, unsigned int* information_code, Growth_Player* Growth_players, Special_Fields Journey_o, unsigned int rain, Single_option_representives single_option_representives, Realize_modifications_variables* rmv, unsigned int real) {

	unsigned int einmal;	// just to controll something
	unsigned int rain_save, rain_speed_save, number_rain;	// Gamemode: Rain
	unsigned int fall_back;	// Gamemode: Fall
	unsigned int count_freq;	// Gamemode: Race

	// copies of same
	unsigned int fall_controll, turns_per_drop, speed_of_fall, points_for_win;	//Gamemode: Fall
	unsigned int rain_drops, rain_obj, rain_speed;	//Gamemode: Rain
	unsigned int figures, assassin, avalanche;	// Modifications
	unsigned int intensity_minimum, direction;	// Projection matters

	#ifdef VERBOSE
	printf("	realize_modifications ok.0\n ");	//test
	#endif
	
	einmal = 0;

	count_freq = 1;
	
	rain_speed_save = 0;	//Rain
	rain_save = 0;
	number_rain = 0;

	fall_back = 0;	//Fall

	direction = rmv->same[76];
	// printf("	realize_modifications ok.0.1\n ");	//test
	intensity_minimum = rmv->same[74];
	// printf("	realize_modifications ok.0.2\n ");	//test
	avalanche = rmv->same[9];
	// printf("	realize_modifications ok.0.3\n ");	//test
	assassin = rmv->same[77];
	// printf("	realize_modifications ok.0.4\n ");	//test
	figures = rmv->same[69];
	// printf("	realize_modifications ok.0.5\n ");	//test
	rain_speed = rmv->same[14];
	// printf("	realize_modifications ok.0.6\n ");	//test
	rain_obj = rmv->same[13];
	// printf("	realize_modifications ok.0.7\n ");	//test
	rain_drops = rmv->same[12];
	// printf("	realize_modifications ok.0.8\n ");	//test
	points_for_win = rmv->same[21];
	// printf("	realize_modifications ok.0.9\n ");	//test
	speed_of_fall = rmv->same[8];
	// printf("	realize_modifications ok.0.10\n ");	//test
	turns_per_drop = rmv->same[7];
	// printf("	realize_modifications ok.0.11\n ");	//test
	fall_controll = rmv->same[6];

	#ifdef Contact_mistake_search
	printf("	realize_modifications ok.1Con\n ");	//test
	#endif
	
	// printf("	realize_modifications ok.1\n ");	//test

	if (single_option_representives.addition != 0) {

		if (real == evet) {
			if (Opague_o.characterization >= 1) {
				opague_builder (Spiel, Opague_o, m, n, geben, rmv->AOP, Allocation_o, number_of_players, gamemode_played);
				show_field (number_of_players, level, Sf_permutations, Opague_o.field, Opague_o.field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
			} else {
				show_field (number_of_players, level, Sf_permutations, Opague_o.field, Spiel, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
			}
		}

		addition_maker (Spiel, m, n, number_of_players, geben, Opague_o.field, gamemode_played, Allocation_o, ges);

	}

	// printf("	realize_modifications ok.2\n ");	//test

	if (real == evet) {
		if ((gamemode_played == Hunt)&&(geben == 1)) {	//if geben == 1

			if (Opague_o.characterization >= 1) {
				opague_builder (Spiel, Opague_o, m, n, geben, rmv->AOP, Allocation_o, number_of_players, gamemode_played);
				show_field (number_of_players, level, Sf_permutations, Opague_o.field, Opague_o.field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
			} else {
				show_field (number_of_players, level, Sf_permutations, Opague_o.field, Spiel, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
			}

			printf("\n");
			printf("\n");
			choose_heart (Spiel, m, n, geben, Opague_o.field, Allocation_o, number_of_players, gamemode_played);
			printf("\n");
		}
	}

	// printf("	realize_modifications ok.3\n ");	//test

	if (gamemode_played == Classic) {	//Matchballs and win
		if (real == evet) {
			for (unsigned int j=1; j<n-1; j+=1) {
				if (Field[0][(m-3)*(geben%2)+2*((geben+1)%2)][j] == geben){
					rmv->numbers_of_[geben][0][0] += 1;	//Matchballs
					break;	//because the line should be count once not twice or...
				}
			}
			for (unsigned int j=1; j<n-1; j+=1){
				for (unsigned int p=1; p<=number_of_players; p++) {
					if (Field[0][(m-2)*(p%2)+1*((p+1)%2)][j] == p){
						rmv->win_condition[p] = kazanacak;
						rmv->win_condition[0] = biri_kazanacak;
					}
				}
			}
			for (unsigned int p=1; p<=number_of_players; p++) {
				if (rmv->win_condition[p] == kazanacak){
					printf("	Sieg:	Spieler %u \n", p);
				}
			}
			if (rmv->win_condition[0] == biri_kazanacak){
				*g = 0;
		// printf("g=0 line: 12914");	//test
			}
		}
	} else if (gamemode_played == Collect) {
		for (unsigned int j=2; j<n-1; j+=((n-1)/2)-2){		//Collect-Bed. prüfen
			unsigned int a;
			a = 0;
			if (Spiel[0][((m-1)/2)][j] == To_collect){
				if (Spiel[0][((m-1)/2)-1][j]==geben){a += 1;}
				if (Spiel[0][((m-1)/2)+1][j]==geben){a += 1;}
				if (Spiel[0][(m-1)/2][j-1]==geben){a += 1;}
				if (Spiel[0][(m-1)/2][j+1]==geben){a += 1;}
				if (a >= 3){
					if (real == evet) {
						rmv->numbers_of_[geben][0][0] += 1;
					}
					set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, ((m-1)/2), j, geben);
				}
			}
		}
		if (real == evet) {
			if (rmv->numbers_of_[geben][0][0] == 2){
				printf("\n");
				printf("	Sieg: Spieler %u \n", geben);
				printf("\n");
				show_field (number_of_players, level, Sf_permutations, Opague_o.field, Spiel, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
				*g = 0;
		// printf("g=0 line: 12941");	//test
			}
		}
	} else if (gamemode_played == Sand) {
		if (real == evet) {
			for (unsigned int j=1; j<n-1; j+=1){
				if (Field[0][2][j] == geben){
					rmv->numbers_of_[geben][0][0] += 1;
				}
			}
		}
	}

	// printf("	realize_modifications ok.4\n ");	//test

	if (real == evet) {
		if ((gamemode_played == Hunt)&&(geben == number_of_players)) {
			printf("	\n");

			if (Opague_o.characterization >= 1) {
				opague_builder (Field, Opague_o, m, n, geben, rmv->AOP, Allocation_o, number_of_players, gamemode_played);
				show_field (number_of_players, level, Sf_permutations, Opague_o.field, Opague_o.field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
			} else {
				show_field (number_of_players, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
			}

			printf("	\n");
			if (information_code[1] == 0) {
				anything = 1;
				while (anything == 1) {
					printf("	\n");
					printf("	\n");
					printf("	Are you ready to make your turn, player 1 ? \n");
					printf("	Yes: 1 \n");
					printf("	\n");
					printf("	\n");
					anything = get_unsigned_numeric_input_with_not_more_than_1_letter ();

					if (anything != 1) {
						anything = 1;
					} else {
						anything = 0;
					}
				}
				anything = 0;
			}
		}

		if (gamemode_played == Hunt) {
			information_code[3] = 0;
		}

		// printf("	realize_modifications ok.5\n ");	//test

		if ((gamemode_played == Hunt)&&(geben == 1)) {	//if geben==1
			for (unsigned int p=0; p<=3; p+=1) {
				information_code[p] = 0;
			}

			// printf("\n");	//test
			// printf("	hboa=%u	\n", information_code[2]);
			// printf("\n");
			
			if (Opague_o.characterization >= 1) {
				opague_builder (Field, Opague_o, m, n, geben, rmv->AOP, Allocation_o, number_of_players, gamemode_played);
				show_field (number_of_players, level, Sf_permutations, Opague_o.field, Opague_o.field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
			} else {
				show_field (number_of_players, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
			}

			for (unsigned int s = 1; s <= 20; s+=1) {	//Abstandhalter
				printf(" \n");
			}
		}
	}	//real = hayir

	// printf("	realize_modifications ok.6\n ");	//test

	if (assassin != 0) {
		assassin_maker (level, Sf_permutations, Spiel, geben, Opague_o, gamemode_played, Allocation_o, number_of_players, m, n, rmv->AOP, information_code, Growth_players);
	}

	#ifdef Contact_mistake_search
	printf("gamemode_played = %u \n", gamemode_played);	//test
	printf("Contact = %u \n", Contact);	//test
	#endif
	
	// printf("	realize_modifications ok.6.0\n ");	//test
	
	if (gamemode_played == Contact) {

		#ifdef Contact_mistake_search
		printf("	realize_modifications ok.3Con\n ");	//test
		#endif
	
		if (real == evet) {
			if (Opague_o.characterization >= 1) {
				opague_builder (Field, Opague_o, m, n, geben, rmv->AOP, Allocation_o, number_of_players, gamemode_played);
				show_field (number_of_players, level, Sf_permutations, Opague_o.field, Opague_o.field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
			} else {
				show_field (number_of_players, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
			}
		}
		
		#ifdef Contact_mistake_search
		printf("	realize_modifications ok.4Con\n ");	//test
		#endif
	
		battle (m, n, Spiel, geben, Opague_o.field, Allocation_o, number_of_players, gamemode_played);
		
		#ifdef Contact_mistake_search
		printf("	realize_modifications ok.5Con\n ");	//test
		#endif
	
	}

	// printf("	realize_modifications ok.7\n ");	//test

	if (real == evet) {
		if (Journey_o.characterization != 0) {
			if (gamemode_played == Race) {
				anything = 2*rmv->freq;
			} else {
				anything = (10*(number_of_players - rmv->player_counter) - 1);
			}

			if ((anything - ((*g-rmv->all_turns_correction-1)%anything)) == 1) {
				if (Opague_o.characterization >= 1) {
					opague_builder (Field, Opague_o, m, n, (geben%number_of_players)+1, rmv->AOP, Allocation_o, number_of_players, gamemode_played);
					show_field (number_of_players, level, Sf_permutations, Opague_o.field, Opague_o.field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
				} else {
					show_field (number_of_players, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
				}

				printf (" \n");
				printf (" \n");
				printf ("	It is time for a journey... \n");
				printf (" \n");
				for (unsigned int i=1; i<m-1; i+=1){
					for (unsigned int j=1; j<n-1; j+=1){
						if (Field[0][i][j] <= number_of_players) {
							set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, i, j, Journey_o.field[0][i][j]);
							set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Journey_o.field, 0, i, j, 0);
						} else {
							set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Journey_o.field, 0, i, j, 0);
						}
					}
				}
			}
		}
		if (single_option_representives.intensity_loss_per_line_multiplication != 0) {
			if (gamemode_played == Race) {
				anything = 2*rmv->freq-2;
			} else {
				anything = (9*(number_of_players - rmv->player_counter) - 1);
			}

			if ((anything - ((*g-rmv->all_turns_correction-1)%anything)) == 1) {
				if (Opague_o.characterization >= 1) {
					opague_builder (Field, Opague_o, m, n, (geben%number_of_players)+1, rmv->AOP, Allocation_o, number_of_players, gamemode_played);
					show_field (number_of_players, level, Sf_permutations, Opague_o.field, Opague_o.field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
				} else {
					show_field (number_of_players, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
				}

				printf (" \n");
				printf (" \n");
				printf ("	It is time for a projection... \n");
				printf (" \n");
				projection_maker (Field, number_of_players, geben, Opague_o.field, gamemode_played, Allocation_o, direction, intensity_minimum, single_option_representives.intensity_loss_per_line_multiplication, m, n);
			}
		}
		if ((rmv->Collector_of_permutation.amount_of_permutation_number_b != 0)||(rmv->Collector_of_permutation.amount_of_permutation_number_c != 0)) {
			if (gamemode_played == Race) {
				anything = 2*rmv->freq-3;
			} else {
				anything = (8*(number_of_players - rmv->player_counter) - 1);
			}
		
			// printf (" number_b: %u, number_c: %u \n", rmv->Collector_of_permutation.amount_of_permutation_number_b, rmv->Collector_of_permutation.amount_of_permutation_number_c);	//test
		
			if ((anything - ((*g-rmv->all_turns_correction-1)%anything)) == 1) {
				if (Opague_o.characterization >= 1) {
					opague_builder (Field, Opague_o, m, n, (geben%number_of_players)+1, rmv->AOP, Allocation_o, number_of_players, gamemode_played);
					show_field (number_of_players, level, Sf_permutations, Opague_o.field, Opague_o.field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
				} else {
					show_field (number_of_players, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
				}

				printf (" \n");
				printf (" \n");
				printf ("	It is time for a permutation... \n");
				printf (" \n");

				// show_field (number_of_players, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);	//test

				Permutations_permutate_maker (rmv->Collector_of_permutation.areas_c, Field, number_of_players, rmv->Collector_of_permutation.permutation_number_c, rmv->Collector_of_permutation.sigmas_c, rmv->Collector_of_permutation.amount_of_permutation_number_c, geben, Opague_o.field, gamemode_played, Allocation_o);

				// printf (" #5k after Permutations_permutate_maker(c) ok\n");

				Permutations_permutate_maker (rmv->Collector_of_permutation.areas_b, Field, number_of_players, rmv->Collector_of_permutation.permutation_number_b, rmv->Collector_of_permutation.sigmas_b, rmv->Collector_of_permutation.amount_of_permutation_number_b, geben, Opague_o.field, gamemode_played, Allocation_o);

			}
		}
	}

	// printf("	realize_modifications ok.8\n ");	//test

	// printf("	gamemode_played = %u \n", gamemode_played);	//test
	// printf("	Rain = %u \n", Rain);	//test

	if (gamemode_played == Rain) {
		if (real == evet) {
			if (Opague_o.characterization >= 1) {
				opague_builder (Field, Opague_o, m, n, (geben%number_of_players)+1, rmv->AOP, Allocation_o, number_of_players, gamemode_played);
				show_field (number_of_players, level, Sf_permutations, Opague_o.field, Opague_o.field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
			} else {
				show_field (number_of_players, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
			}

			printf("\n");
			printf("\n");
			printf("\n");
			printf("\n");
			printf("\n");
			printf("\n");
			printf("\n");

			if (rain == Push){
				printf("		rain-Characteristics: Push \n");
			} else if (rain == Destroy_rain){
				printf("		rain-Characteristics: Destroy \n");
			} else if (rain == Explode){
				printf("		rain-Characteristics: Explode \n");
			} else if (rain == Explode_and_survival){
				printf("		rain-Characteristics: Explode & survival \n");
			} else if (rain == Transform){
				printf("		rain-Characteristics: Transform \n");
			} else if (rain == Teleport){
				printf("		rain-Characteristics: Teleport \n");
			} else if (rain == Mixed){
				printf("		rain-Characteristics: Mixed \n");
			}
		}

		number_rain = rmv->use_number;

		if ((rain_speed == 0) && (((*g-1)%4) >= 2)){
			if (real == evet) {
				printf("	\n");
				printf("	Falling slowly...\n");
				printf("	\n");
				if (Opague_o.characterization >= 1) {
					show_field (number_of_players, level, Sf_permutations, Opague_o.field, Opague_o.field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);	//already build
				} else {
					show_field (number_of_players, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
				}
			}
		} else {
			if (rain_speed == 0){
				rain_speed_save = 1;
				rain_speed = 1;
			}

			for (unsigned int r=1; r<=rain_speed; r+=1){
				if (rain == 6){
					rain_save = 6;
					if (number_rain == 1){
						rain = 1;
					} else if (number_rain == 2){
						rain = 2;
					} else if (number_rain == 3){
						rain = 31;
					} else if (number_rain == 4){
						rain = 4;
					} else if (number_rain == 5){
						rain = 5;
					} else if (number_rain == 6){
						rain = 32;
					}
				}
				if (geben <= number_of_players/2){
					for (unsigned int i=m-2; i>0; i-=1){
						for (unsigned int j=1+(geben-1)*7; j<=6+(geben-1)*7; j+=1){
							if (Spiel[0][i][j] == Raindrop){
								if (Spiel[0][i+1][j] != 0){

									if (rain == 1){
										unsigned int mem;
										mem = i;
										while (((i+1)<=(m-2))&&(Spiel[0][i+1][j] != 0)){
											if ((i+1)<=(m-2)){
												set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, mem, j, Spiel[0][i+1][j]);
											}

											if (i == mem) {

												if (((mem+2)<=(m-2))&&(Spiel[0][mem+2][j] == 0)) {
													set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, mem+2, j, Spiel[0][mem][j]);
													break;
												} else if (((mem+2)<=(m-2))&&(Spiel[0][mem+2][j] != 0)) {
													set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, mem+1, j, Spiel[0][mem+2][j]);
													set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, mem+2, j, Spiel[0][mem][j]);
													if (((mem+3)<=(m-2))&&(Spiel[0][mem+3][j] == 0)) {
														set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, mem+3, j, Spiel[0][mem+1][j]);
													}
												}

												i += 2;
											} else {

												i += 1;

												set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j, Spiel[0][mem+1][j]);

												if (((i+1)<=(m-2))&&(Spiel[0][i+1][j] == 0)){
													set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i+1, j, Spiel[0][mem][j]);
													break;
												}
												set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, mem+1, j, Spiel[0][mem][j]);
											}
										}
										i = mem;
										set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j, 0);
										if (i < (m-2)) {
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i+1, j, Raindrop);
										}

									} else if (rain == 2){
										set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i+1, j, Raindrop);
										set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j, 0);

									} else if (rain == 31){
										for (unsigned int h=i; h<=i+2; h+=1){
											for (unsigned int k=j-1; k<=j+1; k+=1){
												if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
													set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, h, k, 0);
												}
											}
										}
									} else if (rain == 32){
										for (unsigned int h=i; h<=i+2; h+=1){
											for (unsigned int k=j-1; k<=j+1; k+=1){
												if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
													if (Spiel[0][h][k] == Raindrop){
														set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, h, k, geben);
													} else {
														set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, h, k, 0);
													}
												}
											}
										}
										set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j, 0);
										set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i+1, j, 0);
									} else if (rain == 4){
										if((Spiel[0][i-1][j] == geben)||(Spiel[0][i+1][j] == geben)||(Spiel[0][i][j-1] == geben)||(Spiel[0][i][j+1] == geben)){
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j, geben);
										} else {
											if (i != (m-2)){
												set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i+1, j, Raindrop);
											}
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j, 0);
										}
									} else if (rain == 5){

										if (Spiel[0][i+1][j] == geben){
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i-1, j, geben);
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i+1, j, 0);
										} else if (Spiel[0][i][j-1] == geben){
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j+1, geben);
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j-1, 0);
										} else if (((j+2)<=n-1) && (Spiel[0][i][j+1] == geben) && (((Spiel[0][i][j+2] != Raindrop) || (Spiel[0][i+1][j+2] != geben)) && (Spiel[0][i-1][j+1] != Raindrop))){
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j-1, geben);
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j+1, 0);
										} else if (((i-1)>=1) && (Spiel[0][i-1][j] == geben) && (Spiel[0][i-2][j] != Raindrop) && (Spiel[0][i-1][j-1] != Raindrop)){
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i+1, j, geben);
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i-1, j, 0);
										}
										set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i+1, j, Raindrop);
										set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j, 0);
									}
								} else {

									if (rain == 5){
										if (Spiel[0][i+1][j] == geben){
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i-1, j, geben);
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i+1, j, 0);
										} else if (Spiel[0][i][j-1] == geben){
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j+1, geben);
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j-1, 0);
										} else if (((j+2)<=n-1) && (Spiel[0][i][j+1] == geben) && (((Spiel[0][i][j+2] != Raindrop) || (Spiel[0][i+1][j+2] != geben)) && (Spiel[0][i-1][j+1] != Raindrop))){
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j-1, geben);
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j+1, 0);
										} else if (((i-1)>=1) && (Spiel[0][i-1][j] == geben) && (Spiel[0][i-2][j] != Raindrop) && (Spiel[0][i-1][j-1] != Raindrop)){
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i+1, j, geben);
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i-1, j, 0);
										}
									}
									if (rain == 4){
										if((Spiel[0][i-1][j] == geben)||(Spiel[0][i+1][j] == geben)||(Spiel[0][i][j-1] == geben)||(Spiel[0][i][j+1] == geben)){
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j, geben);
										} else {
											if (i != (m-2)){
												set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i+1, j, Raindrop);
											}
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j, 0);
										}
									} else {
										if (i != (m-2)){
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i+1, j, Raindrop);
										}
										set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j, 0);
									}
								}
							}
						}
					}
					if (rain_drops == 1){
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, 1, geben*7-number_rain, Raindrop);
					} else if (rain_drops == 2){
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, 1, (geben-1)*7+number_rain, Raindrop);
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, 1, geben*7-number_rain, Raindrop);
					} else if (rain_drops == 4){
						for (unsigned int s=1+(geben-1)*7; s<=6+(geben-1)*7; s+=1){
							if ((s != (geben-1)*7+number_rain)&&(s != geben*7-number_rain)){
								set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, 1, s, Raindrop);
							}
						}
					} else if (rain_drops == 5){
						for (unsigned int s=1+(geben-1)*7; s<=6+(geben-1)*7; s+=1){
							if (s != (geben-1)*7+number_rain){
								set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, 1, s, Raindrop);
							}
						}
					} else if (rain_drops == 6){
						for (unsigned int s=1+(geben-1)*7; s<=6+(geben-1)*7; s+=1){
							set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, 1, s, Raindrop);
						}
					}

				} else if (geben > number_of_players/2) {
					for (unsigned int i=m-2; i>0; i-=1){
						for (unsigned int j=6+(geben-1)*7; j>=1+(geben-1)*7; j-=1){
							if (Spiel[0][i][j] == Raindrop){
								if (Spiel[0][i+1][j] != 0){

									if (rain == 1){
										unsigned int mem;
										mem = i;
										while (((i+1)<=(m-2))&&(Spiel[0][i+1][j] != 0)){
											if ((i+1)<=(m-2)){
												set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, mem, j, Spiel[0][i+1][j]);
											}

											if (i == mem) {

												if (((mem+2)<=(m-2))&&(Spiel[0][mem+2][j] == 0)) {
													set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, mem+2, j, Spiel[0][mem][j]);
													break;
												} else if (((mem+2)<=(m-2))&&(Spiel[0][mem+2][j] != 0)) {
													set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, mem+1, j, Spiel[0][mem+2][j]);
													set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, mem+2, j, Spiel[0][mem][j]);
													if (((mem+3)<=(m-2))&&(Spiel[0][mem+3][j] == 0)) {
														set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, mem+3, j, Spiel[0][mem+1][j]);
													}
												}

												i += 2;
											} else {

												i += 1;

												set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j, Spiel[0][mem+1][j]);

												if (((i+1)<=(m-2))&&(Spiel[0][i+1][j] == 0)){
													set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i+1, j, Spiel[0][mem][j]);
													break;
												}
												set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, mem+1, j, Spiel[0][mem][j]);

											}
										}
										i = mem;
										set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j, 0);
										if (i < (m-2)) {
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i+1, j, Raindrop);
										}
									} else if (rain == 2){
										set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i+1, j, Raindrop);
										set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j, 0);
									} else if (rain == 31){
										for (unsigned int h=i; h<=i+2; h+=1){
											for (unsigned int k=j-1; k<=j+1; k+=1){
												if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
													set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, h, k, 0);
												}
											}
										}
									} else if (rain == 32){
										for (unsigned int h=i; h<=i+2; h+=1){
											for (unsigned int k=j-1; k<=j+1; k+=1){
												if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
													if (Spiel[0][h][k] == Raindrop){
														set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, h, k, geben);
													} else {
														set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, h, k, 0);
													}
												}
											}
										}
										set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j, 0);
										set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i+1, j, geben);
									} else if (rain == 4){
										if((Spiel[0][i-1][j] == geben)||(Spiel[0][i+1][j] == geben)||(Spiel[0][i][j-1] == geben)||(Spiel[0][i][j+1] == geben)){
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j, geben);
										} else {
											if (i != (m-2)){
												set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i+1, j, Raindrop);
											}
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j, 0);
										}

									} else if (rain == 5){
										if (Spiel[0][i+1][j] == geben){
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i-1, j, geben);
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i+1, j, 0);
										} else if (Spiel[0][i][j+1] == geben){
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j-1, geben);
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j+1, 0);
										} else if (((j-1)>=1)&&(Spiel[0][i][j-1] == geben) && ((Spiel[0][i][j-2] != Raindrop)||(Spiel[0][i+1][j-2] != geben)) &&(Spiel[0][i-1][j-1] != Raindrop)){
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j+1, geben);
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j-1, 0);
										} else if (((i-1)>=1)&&(Spiel[0][i-1][j] == geben) && (Spiel[0][i-2][j] != Raindrop) && (Spiel[0][i-1][j+1] != Raindrop)){
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i+1, j, geben);
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i-1, j, 0);
										}
										set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i+1, j, Raindrop);
										set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j, 0);
									}
								} else {

									if (rain == 5){
										if (Spiel[0][i+1][j] == geben){
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i-1, j, geben);
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i+1, j, 0);
										} else if (Spiel[0][i][j+1] == geben){
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j-1, geben);
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j+1, 0);
										} else if (((j-1)>=1)&&(Spiel[0][i][j-1] == geben) && ((Spiel[0][i][j-2] != Raindrop)||(Spiel[0][i+1][j-2] != geben)) &&(Spiel[0][i-1][j-1] != Raindrop)){
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j+1, geben);
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j-1, 0);
										} else if (((i-1)>=1)&&(Spiel[0][i-1][j] == geben) && (Spiel[0][i-2][j] != Raindrop) && (Spiel[0][i-1][j+1] != Raindrop)){
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i+1, j, geben);
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i-1, j, 0);
										}
									}

									if (rain == 4){
										if((Spiel[0][i-1][j] == geben)||(Spiel[0][i][j-1] == geben)||(Spiel[0][i][j+1] == geben)){
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j, geben);
										} else {
											if (i != (m-2)){
												set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i+1, j, Raindrop);
											}
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j, 0);
										}
									} else {
										if (i != (m-2)){
											set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i+1, j, Raindrop);
										}
										set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, j, 0);
									}
								}
							}
						}
					}
					if (rain_drops == 1){
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, 1, number_rain+(geben-1)*7, Raindrop);
					} else if (rain_drops == 2){
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, 1, geben*7-number_rain, Raindrop);
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, 1, (geben-1)*7+number_rain, Raindrop);

					} else if (rain_drops == 4){
						for (unsigned int s=1+(geben-1)*7; s<=6+(geben-1)*7; s+=1){
							if ((s != geben*7-number_rain)&&(s != (geben-1)*7+number_rain)){
								set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, 1, s, Raindrop);
							}
						}
					} else if (rain_drops == 5){
						for (unsigned int s=1+(geben-1)*7; s<=6+(geben-1)*7; s+=1){
							if (s != geben*7-number_rain){
								set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, 1, s, Raindrop);
							}
						}
					} else if (rain_drops == 6){
						for (unsigned int s=1+(geben-1)*7; s<=6+(geben-1)*7; s+=1){
							set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, 1, s, Raindrop);
						}
					}

				}
				number_rain = (number_rain%6) + 1;
				
				if (real == evet) {
					if (level[0] == 5) {
						level[0] = 2;
					}
					if (Opague_o.characterization >= 1) {
						show_field (number_of_players, level, Sf_permutations, Opague_o.field, Opague_o.field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
					} else {
						show_field (number_of_players, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
					}
					if (level[0] == 2) {
						level[0] = 5;
					}
				}
				
				if (rain_save == 6){
					rain = 6;
				}
			}

		}	//speed = 0,5 (=0)

		if (rain_speed_save == 1){
			rain_speed_save = 0;
			rain_speed = 0;
		}

		for (unsigned int j=0; j<n; j+=1){
			set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, 0, j, 0);
			set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, m-1, j, 0);
		}
		for (unsigned int i=0; i<m; i+=1){
			set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, 0, 0);
			set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Spiel, 0, i, n-1, 0);
		}

		if (real == evet) {
			if (level[0] <= 2) {
				printf("\n");
				printf("		Get:");
				for (unsigned int q=2; q<=number_of_players; q++) {
					if (q != 2 ) {
						printf("or");
					}
					printf(" [1][%u] ", (q-1)*7);
				}
				printf("\n");
				printf("\n");
			}

			for (unsigned int q=2; q<=number_of_players; q++) {
				if (Spiel[0][1][(q-1)*7] != 0){
					for (unsigned int p=1; p<=number_of_players; p+=1) {
						if (Spiel[0][1][(q-1)*7] == p){
							rmv->win_condition[p] = kazanacak;
							rmv->win_condition[0] = biri_kazanacak;
						}
					}
				}
			}
			for (unsigned int p=1; p<=number_of_players; p++) {
				if (rmv->win_condition[p] == kazanacak){
					printf("	Sieg:	Spieler %u \n", p);
				}
			}
			if (rmv->win_condition[0] == biri_kazanacak){
				*g = 0;
				// printf("g=0 line: 113587");	//test
			}

			for (unsigned int q=2; q<=number_of_players; q+=1) {
				if ((Field[0][1][(q-1)*7-1] == geben)||(Field[0][1][(q-1)*7+1] == geben)||(Field[0][2][(q-1)*7] == geben)){
					rmv->numbers_of_[geben][0][0] += 1;
				}
			}
		}
	}

	// printf("	realize_modifications ok.9\n ");	//test

	if (gamemode_played == Race) {

		if ((*g-1)%rmv->freq == (rmv->freq-1)){
			count_freq = (*g/rmv->freq) +1;
			if (count_freq == n-4){
				printf("	All lost! \n");
				show_field (number_of_players, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
				*g = 0;
		// printf("g=0 line: 13608");	//test
			}
			printf("\n");
			printf("\n");
			printf("	It moved forward! \n");
			printf("\n");
			printf("\n");
			ahead (Field, m, count_freq, Allocation_o, Opague_o.field, number_of_players, geben, gamemode_played);

			if (Opague_o.characterization >= 1) {
				opague_builder (Field, Opague_o, m, n, (geben%number_of_players)+1, rmv->AOP, Allocation_o, number_of_players, gamemode_played);
				show_field (number_of_players, level, Sf_permutations, Opague_o.field, Opague_o.field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
			} else {
				show_field (number_of_players, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
			}
		}

		for (unsigned int p=1; p<=number_of_players; p++) {
			for (unsigned int i=1+(p-1)*(1+((m-2-(number_of_players-1))/number_of_players)); i<1+p*(1+((m-2-(number_of_players-1))/number_of_players)); i+=1){		//Spiel-Ende?
				if (Field[0][i][n-2] == p){
					rmv->win_condition[p] = kazanacak;
					rmv->win_condition[0] = biri_kazanacak;
				}
			}
		}
		for (unsigned int p=1; p<=number_of_players; p++) {
			if (rmv->win_condition[p] == kazanacak) {
				printf (" Sieg: Spieler %u \n", p);
			}
		}
		if (rmv->win_condition[0] == biri_kazanacak){
			*g = 0;
		// printf("g=0 line: 13640");	//test
		}

		for (unsigned int i=1; i<(m-1); i+=1){
			if (Field[0][i][n-3] == geben){
				rmv->numbers_of_[geben][0][0] += 1;	//Matchballs
				break;	// to count only once
			}
		}
	}

	// printf("	realize_modifications ok.10\n ");	//test

	if (real == evet) {
		if (gamemode_played == Fall) {
			if (((*g-1)%turns_per_drop) == 1){
				for (unsigned int j=1; j<n-1; j+=1){
					if (Field[0][m-2][j] == Fall_ball){
						if ((rmv->var_[1] == 1010)||(rmv->var_[2] == 1010*2)){
							if (fall_back == (n-1)/2){
								rmv->Points[0] -= 1;
							} else if (fall_back < (n-1)/2){
								for (unsigned int p=1; p<=number_of_players; p++) {
									if (p%2 == 0) {
										rmv->Points[p] -= (((n-1)/2) - j);
									}
								}
							} else if (fall_back > (n-1)/2){
								for (unsigned int p=1; p<=number_of_players; p++) {
									if (p%2 == 1) {
										rmv->Points[p] -= (j - (n-1)/2);
									}
								}
							}
						}
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, 1, (n-1)/2, Fall_ball);
						set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, m-2, j, 0);
						fall_controll = 1;

						printf ("\n");
						printf ("\n");
						printf ("\n");
						printf ("	It reached the ground!\n");
						printf ("\n");

						if (Opague_o.characterization >= 1) {
							opague_builder (Field, Opague_o, m, n, (geben%number_of_players)+1, rmv->AOP, Allocation_o, number_of_players, gamemode_played);
							show_field (number_of_players, level, Sf_permutations, Opague_o.field, Opague_o.field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
						} else {
							show_field (number_of_players, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
						}

						if (j == (n-1)/2){
							rmv->Points[0] += 1;
							printf ("	It is an undecided #-square! \n");
						} else if (j < (n-1)/2){
							for (unsigned int p=1; p<=number_of_players; p++) {
								if (p%2 == 0) {
									rmv->Points[p] += (((n-1)/2) - j);
									printf ("	Points player %u:	+ %u \n", p, ((n-1)/2) - j);
								}
							}
						} else if (j > (n-1)/2){
							for (unsigned int p=1; p<=number_of_players; p++) {
								if (p%2 == 1) {
									rmv->Points[p] += (j - (n-1)/2);
									printf ("	Points player %u:	+ %u \n", p, (j - (n-1)/2));
								}
							}
						}
						fall_back = j;

						if (Journey_o.characterization != 0){			//Übertragung		journey-Frequenz = Fall-Frequenz

							printf ("\n");
							printf ("\n");
							printf ("	It is time for a journey... \n");
							printf ("\n");

							for (unsigned int i=1; i<m-1; i+=1){
								for (unsigned int j=1; j<n-1; j+=1){
									if (Field[0][i][j] <= number_of_players){
										set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, i, j, Journey_o.field[0][i][j]);
										set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Journey_o.field, 0, i, j, 0);
									} else {
										set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Journey_o.field, 0, i, j, 0);
									}
								}
							}
						}
						break;	//because i found the only one existing Fall_ball
					}
				}
			}

			if ((((*g-1)%turns_per_drop) == 1)&&(fall_controll != 1)){
				for (unsigned int i=1; i<m-2; i+=1){
					for (unsigned int j=1; j<n-1; j+=1){
						if (Field[0][i][j] == Fall_ball){
							set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, i, j, 0);
							if ((i+speed_of_fall) <= (m-2)) {
								for (unsigned int k=i; k<(i+speed_of_fall); k+=1) {
									set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, k, j, 0);
								}
								set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, i+speed_of_fall, j, Fall_ball);
							} else {
								set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, m-2, j, Fall_ball);
							}

							einmal = 1;
							printf ("\n");
							printf ("\n");
							printf ("\n");
							printf ("	It fell down!\n");
							printf ("\n");

							if (Opague_o.characterization >= 1) {
								opague_builder (Field, Opague_o, m, n, (geben%number_of_players)+1, rmv->AOP, Allocation_o, number_of_players, gamemode_played);
								show_field (number_of_players, level, Sf_permutations, Opague_o.field, Opague_o.field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
							} else {
								show_field (number_of_players, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
							}

							break;	//the only ball i can find
						}
					}
					if (einmal == 1){
						break;
					}
				}
				einmal = 0;
			}
			fall_controll = 0;
			
			if ((rmv->var_[1] != 1010) && (rmv->var_[2] != 1010*2)){
				if (rmv->Points[1] > rmv->Points[2]){	//Vertreter der Parteien
				for (unsigned int p=1; p<=number_of_players; p++) {
					if (p%2 == 1) {
					rmv->numbers_of_[p][0][0] += 1;
					}
				}
				} else if (rmv->Points[1] < rmv->Points[2]){	//Vertreter der Parteien
				for (unsigned int p=1; p<=number_of_players; p++) {
					if (p%2 == 0) {
					rmv->numbers_of_[p][0][0] += 1;
					}
				}
				}
			}
			if (rmv->Points[1] >= points_for_win){		//Vertreter der Parteien	//Spiel-Ende
				for (unsigned int p=1; p<=number_of_players; p++) {
				if (p%2 == 1) {
					printf ("	Sieg: Spieler %u \n", p);
				}
				}
				*g = 0;
				// printf("g=0 line: 13798");	//test
			}
			if (rmv->Points[2] >= points_for_win){	//Vertreter der Parteien	//Spiel-Ende
				for (unsigned int p=1; p<=number_of_players; p++) {
				if (p%2 == 0) {
					printf ("	Sieg: Spieler %u \n", p);
				}
				}
				*g = 0;
				// printf("g=0 line: 13807");	//test
			}
			
			// printf("	realize_modifications ok.11\n ");	//test
		} else if (gamemode_played == Hunt) {
			unsigned int a;
			a = 0;
			for (unsigned int i=1; i<m-1; i+=1){
				for (unsigned int j=1; j<n-1; j+=1){
					if (Field[0][i][j] == 11){

						printf("\n");
						for (unsigned int h=i-1; h<=i+1; h++) {
							for (unsigned int k=j-1; k<=j+1; k++) {
								if (((h+k)%2 != (i+j)%2)&&(Field[0][h][k] > 1)) {
									printf (" Sieg: Spieler %u \n", Field[0][h][k]);
									a += 1;
								}
							}
						}
						printf("\n");

						if (a == 2) {
							printf(" Double-catch! \n");
						}
						if (a == 3) {
							printf(" TRIPLE-catch!! \n");
						}
						if (a == 4) {
							printf(" QUADRO-CATCH!!! \n");
						}

						for (unsigned int h=i-1; h<=i+1; h++) {
							for (unsigned int k=j-1; k<=j+1; k++) {
								if (((h+k)%2 == (i+j)%2)&&(Field[0][h][k] > 1)) {
									for (unsigned int p=2; p<=number_of_players; p+=1) {
										if (Field[0][h][k] == p) {
										rmv->numbers_of_[p][0][0] += 1;
										break;	//player found
										}
									}
								}
							}
						}

						break;
					}
				}
				if (a > 0) {
					break;
				}
			}
			if (a > 0) {
				show_field (number_of_players, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
				*g = 0;
				// printf("g=0 line: 13864");	//test
			}

			a = 0;
			if ((rmv->round_counter == rmv->rtc)&&(geben == number_of_players)) {
				printf("	Sieg: Spieler 1");
				*g = 0;
				// printf("g=0 line: 13871");	//test
			}
			// printf("	realize_modifications ok.12\n ");	//test

		} else if (gamemode_played == Sand) {
			for (unsigned j=1; j<=n-2; j++) {
				if (Field[0][1][j] != 0) {
					printf("	Sieg Spieler: %u \n", Field[0][1][j]);
					rmv->win_condition[0] = biri_kazanacak;
				}
			}
			if (rmv->win_condition[0] == biri_kazanacak) {
				*g = 0;
				printf("g=0 line: 13887");	//test
			}

			if ((*g - rmv->all_turns_correction)%((number_of_players - rmv->player_counter)*information_code[3]) == 0) {

				if (Opague_o.characterization >= 1) {
					opague_builder (Field, Opague_o, m, n, (geben%number_of_players)+1, rmv->AOP, Allocation_o, number_of_players, gamemode_played);
					show_field (number_of_players, level, Sf_permutations, Opague_o.field, Opague_o.field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
				} else {
					show_field (number_of_players, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
				}

				if (information_code[1] == 1) {
					for (unsigned int i=1; i<=m-2; i++) {
						for (unsigned int j=1; j<=n-2; j++) {
							anything = 0;
							while (anything != information_code[2]) {
								if ((Field[0][i+anything][j] != 0)&&(i+anything+1 != m-1)&&(Field[0][i+anything+1][j] == 0)) {
								set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, i+anything+1, j, Field[0][i+anything][j]);
								set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, i+anything, j, 0);
								}
								anything += 1;
							}
							anything = 0;
						}
					}
				} else if (information_code[1] == 2) {
					for (unsigned int i=m-2; i>=1; i--) {
						for (unsigned int j=n-2; j>=1; j--) {
							anything = 0;
							while (anything != information_code[2]) {
								if ((Field[0][i+anything][j] != 0)&&(i+anything+1 != m-1)&&(Field[0][i+anything+1][j] == 0)) {
								set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, i+anything+1, j, Field[0][i+anything][j]);
								set_Spielfeld_Eintrag (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, Field, 0, i+anything, j, 0);
								}
								anything += 1;
							}
							anything = 0;
						}
					}
				}
			}

			// printf("	realize_modifications ok.13\n ");	//test
		}
	}

	if (figures != 0) {
		if (Opague_o.characterization >= 1) {
			opague_builder (Field, Opague_o, m, n, (geben%number_of_players)+1, rmv->AOP, Allocation_o, number_of_players, gamemode_played);
			show_field (number_of_players, level, Sf_permutations, Opague_o.field, Opague_o.field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
		} else {
			show_field (number_of_players, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
		}

		figure_check (Field, m, n, number_of_players, Growth_players, Allocation_o, Opague_o.field, geben, gamemode_played);
	}

	// printf("	realize_modifications ok.14\n ");	//test

	if (avalanche != 0) {
		if (Opague_o.characterization >= 1) {
			opague_builder (Field, Opague_o, m, n, (geben%number_of_players)+1, rmv->AOP, Allocation_o, number_of_players, gamemode_played);
			show_field (number_of_players, level, Sf_permutations, Opague_o.field, Opague_o.field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
		} else {
			show_field (number_of_players, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
		}

		Avalanche_maker (Field, Opague_o.field, Allocation_o, geben, gamemode_played, number_of_players, m, n);
	}

	// printf("	realize_modifications ok.15\n ");	//test
	if (real == evet) {
		reset_of_ges (ges, number_of_players);
		if (gamemode_played == Rain) {	//checklist
			ges_counter (Field, m, n, ges, number_of_players);

			for (unsigned int p=1; p<=number_of_players; p++) {
				if (ges[p] == 0){
					if (rain_obj == 1){
						if (p <= number_of_players/2) {
						set_triangle_unten_links (single_option_representives.inverted, Field, p, m-2, 1+7*((p-1)/2));
						} else if (p > number_of_players/2) {
						set_triangle_unten_rechts (single_option_representives.inverted, Field, p, m-2, n-2-7*((p-2)/2));
						}

					} else {
						printf("		Spieler %u, you are out. \n", p);
						ges[p] = p*1010;
						rmv->player_counter += 1;
					}
				}
			}

		} else if (gamemode_played == Sand) {
			ges_counter (Field, m, n, ges, number_of_players);
			who_is_out (ges, number_of_players, rmv);

			if (rmv->player_counter == number_of_players-1) {
				for (unsigned int p=1; p<=number_of_players; p++) {
				if (ges[p] != p*1010) {
					printf("	Sieg Spieler: %u \n", p);
					break;
				}
				}
				*g = 0;
				// printf("g=0 line: 13992");	//test
			}

		} else if (gamemode_played == Survive) {
			ges_counter (Field, m, n, ges, number_of_players);
			who_is_out (ges, number_of_players, rmv);

		} else if (gamemode_played == Dynamic) {
			ges_counter (Field, m, n, ges, number_of_players);
			who_is_out (ges, number_of_players, rmv);

			if (rmv->player_counter == number_of_players-1) {
				for (unsigned int t=1; t<=number_of_players; t+=1) {
					printf("\n");
					if (ges[t] != t*1010) {
						printf("	Sieg: Spieler %u \n", t);
						break;
					}
				}
				*g = 0;
				// printf("g=0 line: 14012");	//test
			}

			if (number_of_players == 5) {
				if ((rmv->player_counter == 3)&&(((ges[4] != 4040)&&(ges[1] != 1010))||((ges[5] != 5050)&&(ges[3] != 3030)))) {
				for (unsigned int t=1; t<=number_of_players; t+=1) {
					printf("\n");
					if (ges[t] != t*1010) {
					printf("	Sieg: Spieler %u \n", t);
					}
				}
				*g = 0;
				// printf("g=0 line: 14024");	//test
				}
			} else if (number_of_players == 6) {
				if ((rmv->player_counter == 4)&&(((ges[2] != 2020)&&(ges[5] != 5050))||((ges[4] != 4040)&&(ges[1] != 1010))||((ges[3] != 3030)&&(ges[6] != 6060)))) {
					for (unsigned int t=1; t<=number_of_players; t+=1) {
						printf("\n");
						if (ges[t] != t*1010) {
						printf("	Sieg: Spieler %u \n", t);
						}
					}
					*g = 0;
				}
			} else if (number_of_players == 7) {
				if ((rmv->player_counter == 5)&&(((ges[1] != 1010)&&(ges[5] != 5050))||((ges[4] != 4040)&&(ges[7] != 7070))||((ges[3] != 3030)&&(ges[6] != 6060)))) {
					for (unsigned int t=1; t<=number_of_players; t+=1) {
						printf("\n");
						if (ges[t] != t*1010) {
						printf("	Sieg: Spieler %u \n", t);
						}
					}
					*g = 0;
				}
			} else if (number_of_players == 8) {
				if ((rmv->player_counter == 6)&&(((ges[1] != 1010)&&(ges[5] != 5050))||((ges[3] != 3030)&&(ges[7] != 7070))||((ges[2] != 2020)&&(ges[6] != 6060))||((ges[4] != 4040)&&(ges[8] != 8080)))) {
					for (unsigned int t=1; t<=number_of_players; t+=1) {
						printf("\n");
						if (ges[t] != t*1010) {
						printf("	Sieg: Spieler %u \n", t);
						}
					}
					*g = 0;
				}
			} else if (number_of_players == 9) {
				if ((rmv->player_counter == 6)&&(((ges[1] != 1010)&&(ges[4] != 4040)&&(ges[7] != 7070))||((ges[3] != 3030)&&(ges[9] != 9090)&&(ges[6] != 6060))||((ges[2] != 2020)&&(ges[5] != 5050)&&(ges[8] != 8080)))) {
					for (unsigned int t=1; t<=number_of_players; t+=1) {
						printf("\n");
						if (ges[t] != t*1010) {
						printf("	Sieg: Spieler %u \n", t);
						}
					}
					*g = 0;
				} else if ((rmv->player_counter == 7)&&(((ges[1] != 1010)&&(ges[4] != 4040))||((ges[1] != 1010)&&(ges[7] != 7070))||((ges[4] != 4040)&&(ges[7] != 7070))||((ges[2] != 2020)&&(ges[5] != 5050))||((ges[2] != 2020)&&(ges[8] != 8080))||((ges[8] != 8080)&&(ges[5] != 5050))||((ges[3] != 3030)&&(ges[6] != 6060))||((ges[3] != 3030)&&(ges[9] != 9090))||((ges[6] != 6060)&&(ges[9] != 9090)))) {
					for (unsigned int t=1; t<=number_of_players; t+=1) {
						printf("\n");
						if (ges[t] != t*1010) {
						printf("	Sieg: Spieler %u \n", t);
						}
					}
					*g = 0;
				}
			}

		} else if (gamemode_played == Ulcer) {
			for (unsigned int i=1; i<m-1; i+=1){
				for (unsigned int j=1; j<n-1; j+=1){
					for (unsigned int p=1; p<=number_of_players; p++) {
						if ((Field[0][i][j] == p)&&(ges[p] < 1000)) {
						ges[p] += 1;
						if (rmv->ulcer_start[p] == missing) {
							rmv->ulcer_start[p] = existing;
						}
						break;	//to be faster
						}
					}
				}
			}

			ges0_reset_and_counter (ges, number_of_players);

			if ((ges[1] == 0)&&(rmv->ulcer_start[1] == existing)&&(geben == 1)) {
				rmv->ulcer_start[1] = missing;
				if (rmv->ulcer_lifes[1] > 0) {
					printf("		Spieler 1, you lost a life. \n");
					rmv->ulcer_lifes[1] -= 1;
				} else if (rmv->ulcer_start[0] == 0) {	//rmv->ulcer_start[0] ist eine Einstellung des Spielmodus
					printf("		Niederlage: Spieler 1 \n");
					rmv->ulcer_start[0] = 100;
					*g = 0;
				} else if (rmv->ulcer_start[0] == 1) {
					printf("		Spieler 1, you are out. \n");
					rmv->player_counter += 1;
					ges[1] = 1010;

					for (unsigned int p=1; p<=number_of_players; p+=1) {
						if (rmv->out_counter[p] == 0) {
						rmv->out_counter[p] = 1;
						break;	// to be faster
						}
					}
				}
			}

			for (unsigned int p=2; p<=number_of_players; p+=1) {
				if ((ges[p] == 0)&&(number_of_players >= p)&&(rmv->ulcer_start[p] == existing)&&(geben == p)) {
				rmv->ulcer_start[p] = missing;
				if (rmv->ulcer_lifes[p] > 0) {
					printf("		Spieler %u, you lost a life. \n", p);
					rmv->ulcer_lifes[p] -= 1;
				} else {
					printf("		Spieler %u, you are out. \n", p);
					rmv->player_counter += 1;
					ges[p] = 1010*p;

					for (unsigned int q=1; q<=number_of_players; q+=1) {
					if (rmv->out_counter[q] == 0) {
						rmv->out_counter[q] = p;
						break;
					}
					}
				}
				}
			}

			if (rmv->player_counter == (number_of_players - 1)) {
				printf("		Game over, you can see the master of Ulcer. \n");
				show_field (number_of_players, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
				*g = 0;
			}
			if (rmv->player_counter == number_of_players) {
				printf("		Game over, everybody died. \n");
				show_field (number_of_players, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
				*g = 0;
			}
			if ((geben == number_of_players)&&(rmv->rtp == rmv->round_counter)) {
				printf("\n");
				printf("	Congratulations Player 1, you are still alive!\n");
				printf("\n");
				*g = 0;
			}
			if (ges[0] == 0) {
				printf("		This game stucked. Try again! \n");
			}
			// ges-x in ges[x], done

		} else if (gamemode_played == Arena) {
			ges_counter (Field, m, n, ges, number_of_players);
			who_is_out (ges, number_of_players, rmv);

			if (rmv->player_counter == (number_of_players - 1)) {
				printf("		Game over, you can see the master of the Arena. \n");
				show_field (number_of_players, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
				*g = 0;
			}
			if (rmv->player_counter == number_of_players) {
				printf("		Game over, everybody died. \n");
				show_field (number_of_players, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
				*g = 0;
			}

			if ((rmv->round_counter == rmv->rtp)&&(geben == number_of_players)) {
				printf(" \n ");
				printf("	Game over. \n ");
				printf(" \n ");

				ges0_reset_and_counter (ges, number_of_players);

				for (unsigned int p=ges[0]; p>0; p-=1) {
					for (unsigned int q=1; q<=number_of_players; q+=1) {
						if (ges[q] == p) {
							printf("	Spieler %u: %u squares \n", q, p);
						}
					}
					printf("\n");
					printf("\n");
				}
				*g = 0;
			}

		} else if (gamemode_played == Contact) {
			ges_counter (Field, m, n, ges, number_of_players);
			who_is_out (ges, number_of_players, rmv);

			for (unsigned int p=1; p<=number_of_players; p++) {
				if (ges[p] <= 5){
					rmv->numbers_of_[p][0][0] += 1;
				}
			}

			if (rmv->player_counter == (number_of_players - 1)) {
				for (unsigned int p=1; p<=number_of_players; p++) {
					if (ges[p] != p*1010) {
						printf("	Sieg: Spieler %u \n", p);
					}
					break;
				}
				show_field (number_of_players, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
				*g = 0;
				// printf("g=0 line: 14212");	//test
			}

		} else if (gamemode_played == Hunt) {
			ges_counter (Field, m, n, ges, number_of_players);

			if (ges[1] == 0) {
				printf("		Niederlage: Spieler 1 \n");
				*g = 0;
			} else {
				who_is_out (ges, number_of_players, rmv);
			}

			if (rmv->player_counter == (number_of_players - 1)) {
				printf("		Game over. \n		Sieg: Spieler 1. \n");
				show_field (number_of_players, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
				*g = 0;
			}

		} else if ((gamemode_played == Classic)||(gamemode_played == Collect)||(gamemode_played == Fall)||(gamemode_played == Fight)||(gamemode_played == Race)||(gamemode_played == Quidditch)) {
			ges_counter (Field, m, n, ges, number_of_players);
			who_is_out (ges, number_of_players, rmv);

			if (rmv->player_counter == (number_of_players - 1)) {
				for (unsigned int p=1; p<=number_of_players; p++) {
					if (ges[p] != 1010*p) {
						printf(" Sieg: Spieler %u. \n", p);
						break;
					}
				}
				show_field (number_of_players, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
				*g = 0;
			}
			if (gamemode_played == Fight) {
				for (unsigned int p=1; p<=number_of_players; p++) {
					if (ges[p]<5){
						rmv->numbers_of_[p][0][0] += 1;
					}
					// if (ges[p] > limits.at_all){	//test
					// printf("too much\n");
					// }
				}
			}
		}
	}
	
	// /*
	if (gamemode_played == Quidditch) {	//Selected actions/movements by teammembers
		Localization_of_Moc (Field, m, n, Moc_Quaffel, Moc_Schnatz, Moc_Klatscher);	//better save than sorry.
		
		Quidditch_Klatscher_players_actions (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, m, n, g, Moc_Schnatz, Moc_Quaffel, Qs, Opague_o, level, Sf_permutations, information_code, Growth_players);	//1-time
		
		Quidditch_Quaffel_players_actions (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, m, n, g, Moc_Schnatz, Moc_Quaffel, Qs, Opague_o, level, Sf_permutations, information_code, Growth_players);	//2-times
		
		Quidditch_Schnatz_player_actions (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, m, n, g, Moc_Schnatz, Moc_Quaffel, Qs, Opague_o, level, Sf_permutations, information_code, Growth_players);	//1-time
		
		#ifdef Quidditch_mistake_search
		printf("	Quidditch_team_actions.ok \n");	//test
		#endif
		
		// Move_of_a_Quidditch_player (Spielfeld Field, unsigned int geben, Spielfeld Opague_o_field, unsigned int gamemode_played, Special_Fields Allocation_o, unsigned int number_of_players, unsigned int Team_member, unsigned int fly_distance, unsigned int m, unsigned int n, unsigned int g, Moveable_objects_condition* Moc_Schnatz, Moveable_objects_condition* Moc_Quaffel, unsigned int* Points)
		if (geben == number_of_players) {
			
			Quidditch_Schnatz_movements (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, m, n, Moc_Schnatz, Qs, rmv->use_number);
			
			Localization_of_Moc (Field, m, n, Moc_Quaffel, Moc_Schnatz, Moc_Klatscher);	//better save than sorry.
			
			show_field (number_of_players, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
			
			Quidditch_Klatscher_movements (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, m, n, Moc_Klatscher, Qs);
			
			show_field (number_of_players, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
			
			#ifdef Quidditch_mistake_search
			printf("	Quidditch_S/K_actions.ok \n");	//test
			#endif
		}
		
		Localization_of_Moc (Field, m, n, Moc_Quaffel, Moc_Schnatz, Moc_Klatscher);	//better save than sorry.
	}
	// */
	
	#ifdef VERBOSE
	printf("	realize_modifications ok.16\n ");	//test
	printf(" player_counter: %u \n ", rmv->player_counter);	//test
	if ((rmv->player_counter != 0)&&(real == evet)) {
		printf(" player_counter != 0 \n ");	//test
		scanf("%u", &pause);	//test
	}
	#endif
	
	if (real == evet) {
		if (rmv->player_counter == number_of_players) {	//Notbremse
			printf("	No player left \n ");
			*g = 0;
		}
	}
}
// */

void Quidditch_Klatscher_players_actions (Spielfeld Field, unsigned int geben, Spielfeld Opague_o_field, unsigned int gamemode_played, Special_Fields Allocation_o, unsigned int number_of_players, unsigned int m, unsigned int n, unsigned int* g, Moveable_objects_condition* Moc_Schnatz, Moveable_objects_condition* Moc_Quaffel, Quidditch_setup* Qs, Special_Fields Opague_o, unsigned int* level, Spielfeld Sf_permutations, unsigned int* information_code, Growth_Player* Growth_players) {
	
	#ifdef Quidditch_mistake_search
	printf("	Quidditch_Klatscher_players_actions-beginning.ok \n");	//test
	#endif
	
	unsigned int Treiber, turns;
	
	Treiber = 0;
	turns = 0;
	
	if (Opague_o.characterization >= 1) {
		show_field (number_of_players, level, Sf_permutations, Opague_o.field, Opague_o.field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
	} else {
		show_field (number_of_players, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
	}
	
	if (geben == 1) {
		Treiber = Treiber_1;
	} else if (geben == 2) {
		Treiber = Treiber_2;
	}
	
	turns = 2;
	while (turns >= 2) {	//Only 0 or 1 possible
		printf("	Do you want to move one of your Treiber ? \n	0 : no\n	1 : yes\n");
		turns = get_unsigned_numeric_input_with_not_more_than_1_letter ();
	}
	
	for (unsigned int p=1; p<=turns; p++) {
		Move_of_a_Quidditch_player (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Treiber, Qs->Qta[geben].Treiber_fly_distance, m, n, g, Moc_Schnatz, Moc_Quaffel, Qs->Points);
	}
	
	#ifdef Quidditch_mistake_search
	printf("	Quidditch_Klatscher_players_actions-ending.ok \n");	//test
	#endif
	
}

void Quidditch_Quaffel_players_actions (Spielfeld Field, unsigned int geben, Spielfeld Opague_o_field, unsigned int gamemode_played, Special_Fields Allocation_o, unsigned int number_of_players, unsigned int m, unsigned int n, unsigned int* g, Moveable_objects_condition* Moc_Schnatz, Moveable_objects_condition* Moc_Quaffel, Quidditch_setup* Qs, Special_Fields Opague_o, unsigned int* level, Spielfeld Sf_permutations, unsigned int* information_code, Growth_Player* Growth_players) {
	
	#ifdef Quidditch_mistake_search
	printf("	Quidditch_Quaffel_players_actions-beginning.ok \n");	//test
	#endif
	
	unsigned int turns;
	
	turns = 0;
	
	if (Opague_o.characterization >= 1) {
		show_field (number_of_players, level, Sf_permutations, Opague_o.field, Opague_o.field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
	} else {
		show_field (number_of_players, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
	}
	
	turns = 3;
	while (turns >= 3) {	//Only 0 or 1 or 2 possible
	
		printf("	How many actions do you want to make according to the Quaffel ?		(max.: 2)\n");
		turns = get_unsigned_numeric_input_with_not_more_than_1_letter ();
	}
	
	unsigned int action_choice, Team_member;
	action_choice = 0;
	Team_member = 0;
	
	for (unsigned int p=1; p<=turns; p++) {
		
		action_choice = 3;
		while (action_choice >= 3) {	//Only 0 or 1 or 2 possible
	
			printf("	What do you want to do ? \n	0: Throw Quaffel \n");
			printf("	1: Move Jaeger \n");	//Why there was a limit of moving Jaeger/Hueter ?
			printf("	2: Move Hueter \n");
			
			
			action_choice = get_unsigned_numeric_input_with_not_more_than_1_letter ();
		}
		
		if (action_choice == 0) {
			Quidditch_Quaffel_Throw (Field, geben, Opague_o.field, gamemode_played, Allocation_o, number_of_players, m, n, Moc_Quaffel, Qs);
		} else if (action_choice == 1) {
			
			if (geben == 1) {
				Team_member = Jaeger_1;
			} else if (geben == 2) {
				Team_member = Jaeger_2;
			}
			
			Move_of_a_Quidditch_player (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Team_member, Qs->Qta[geben].Jaeger_fly_distance, m, n, g, Moc_Schnatz, Moc_Quaffel, Qs->Points);
			
		} else if (action_choice == 2) {
			
			if (geben == 1) {
				Team_member = Hueter_1;
			} else if (geben == 2) {
				Team_member = Hueter_2;
			}
			
			Move_of_a_Quidditch_player (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Team_member, Qs->Qta[geben].Hueter_fly_distance, m, n, g, Moc_Schnatz, Moc_Quaffel, Qs->Points);
		}
	}
	
	#ifdef Quidditch_mistake_search
	printf("	Quidditch_Quaffel_players_actions-ending.ok \n");	//test
	#endif
	
}

void Quidditch_Schnatz_player_actions (Spielfeld Field, unsigned int geben, Spielfeld Opague_o_field, unsigned int gamemode_played, Special_Fields Allocation_o, unsigned int number_of_players, unsigned int m, unsigned int n, unsigned int* g, Moveable_objects_condition* Moc_Schnatz, Moveable_objects_condition* Moc_Quaffel, Quidditch_setup* Qs, Special_Fields Opague_o, unsigned int* level, Spielfeld Sf_permutations, unsigned int* information_code, Growth_Player* Growth_players) {
	
	#ifdef Quidditch_mistake_search
	printf("	Quidditch_Schnatz_player_actions-beginning.ok \n");	//test
	#endif
	
	unsigned int Sucher, turns;
	
	Sucher = undefined;
	turns = undefined;
	
	if (Opague_o.characterization >= 1) {
		show_field (number_of_players, level, Sf_permutations, Opague_o.field, Opague_o.field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
	} else {
		show_field (number_of_players, level, Sf_permutations, Opague_o.field, Field, m, n, gamemode_played, information_code, geben, Growth_players, 0, Allocation_o);
	}
	
	if (geben == 1) {
		Sucher = Sucher_1;
	} else if (geben == 2) {
		Sucher = Sucher_2;
	}
	
	turns = 2;
	while (turns >= 2) {	//Only 0 or 1 possible
		printf("	Do you want to move your Sucher ? \n	0 : no\n	1 : yes\n");
		turns = get_unsigned_numeric_input_with_not_more_than_1_letter ();
	}
	
	for (unsigned int p=1; p<=turns; p++) {
		
		Move_of_a_Quidditch_player (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Sucher, Qs->Qta[geben].Sucher_fly_distance, m, n, g, Moc_Schnatz, Moc_Quaffel, Qs->Points);
	}
	
	#ifdef Quidditch_mistake_search
	printf("	Quidditch_Schnatz_player_actions-ending.ok \n");	//test
	#endif
	
}

void Localization_of_Moc (Spielfeld Field, unsigned int m, unsigned int n, Moveable_objects_condition* Moc_Quaffel, Moveable_objects_condition* Moc_Schnatz, Moveable_objects_condition* Moc_Klatscher) {
	
	#ifdef Quidditch_mistake_search
	printf("	Localization_of_Moc-beginning.ok \n");	//test
	#endif
	
	unsigned int klatscher_choice;
	
	klatscher_choice = 0;
	
	#ifdef Quidditch_mistake_search
	printf("	Quaffel: [%u][%u]		at this position: %u \n", Moc_Quaffel->i, Moc_Quaffel->j, Field[0][Moc_Quaffel->i][Moc_Quaffel->j]);	//test
	printf("	Schnatz: [%u][%u]		at this position: %u \n", Moc_Schnatz->i, Moc_Schnatz->j, Field[0][Moc_Schnatz->i][Moc_Schnatz->j]);	//test
	printf("	Klatscher[0]: [%u][%u]		at this position: %u \n", Moc_Klatscher[0].i, Moc_Klatscher[0].j, Field[0][Moc_Klatscher[0].i][Moc_Klatscher[0].j]);	//test
	printf("	Klatscher[1]: [%u][%u]		at this position: %u \n", Moc_Klatscher[1].i, Moc_Klatscher[1].j, Field[0][Moc_Klatscher[1].i][Moc_Klatscher[1].j]);	//test
	#endif
	
	for (unsigned int h=1; h<=m-2; h++) {
		for (unsigned int k=1; k<=n-2; k++) {
			if (Field[0][h][k] == Quaffel) {
				Moc_Quaffel->i = h;
				Moc_Quaffel->j = k;
			} else if (Field[0][h][k] == Schnatz) {
				Moc_Schnatz->i = h;
				Moc_Schnatz->j = k;
			} else if (Field[0][h][k] == Klatscher) {
				Moc_Klatscher[klatscher_choice].i = h;
				Moc_Klatscher[klatscher_choice].j = k;
				klatscher_choice += 1;
			}
		}
	}
	klatscher_choice = 0;
	
	#ifdef Quidditch_mistake_search
	printf("	Localization_of_Moc-ending.ok \n");	//test
	#endif
	
}

void Quidditch_Quaffel_Throw (Spielfeld Field, unsigned int geben, Spielfeld Opague_o_field, unsigned int gamemode_played, Special_Fields Allocation_o, unsigned int number_of_players, unsigned int m, unsigned int n, Moveable_objects_condition* Moc_Quaffel, Quidditch_setup* Qs) {
	
	#ifdef Quidditch_mistake_search
	printf("	Quidditch_Quaffel_Throw-beginning.ok \n");	//test
	#endif
	
	unsigned int allowed_to, Hueter, Jaeger, Torring, throw_distance, Zeile_alt, Spalte_alt, Zeile_neu, Spalte_neu;
	
	allowed_to = hayir;	//is it possible to reach the Quaffel?
	Hueter = undefined;
	Jaeger = undefined;
	Torring = undefined;
	throw_distance = 0;	//needs to be 0.
	Zeile_neu = m;
	Spalte_neu = n;
	Zeile_alt = Moc_Quaffel->i;
	Spalte_alt = Moc_Quaffel->j;
	
	if (geben == 1) {
		Hueter = Hueter_1;
		Jaeger = Jaeger_1;
		Torring = Torring_2;
	} else if (geben == 2) {
		Hueter = Hueter_2;
		Jaeger = Jaeger_2;
		Torring = Torring_1;
	}
	
	for (unsigned int h=0; h<=2; h++) {
		for (unsigned int k=0; k<=2; k++) {
			if ((h+k)%2 == 1) {
				if (Field[0][Moc_Quaffel->i +h-1][Moc_Quaffel->j +k-1] == Jaeger) {
					if (Qs->Qta[geben].Jaeger_throw_distance > throw_distance) {
						throw_distance = Qs->Qta[geben].Jaeger_throw_distance;
					}
					allowed_to = evet;
					
				} else if (Field[0][Moc_Quaffel->i +h-1][Moc_Quaffel->j +k-1] == Hueter) {
					if (Qs->Qta[geben].Hueter_throw_distance > throw_distance) {
						throw_distance = Qs->Qta[geben].Hueter_throw_distance;
					}
					allowed_to = evet;
				}
			}
		}
	}
	
	if (allowed_to == hayir) {
		printf("	Sorry, but the Quaffel isn't in your possession. \n");
	} else if (allowed_to == hayir) {
		
		while ((Zeile_neu > m-2)||(Spalte_neu > n-2)||((Zeile_neu == 0)&&(Spalte_neu != 0))||((Spalte_neu == 0)&&(Zeile_neu != 0))||(abs(Moc_Quaffel->i - Zeile_neu) > abs(throw_distance - 0))||(abs(Moc_Quaffel->j - Spalte_neu) > abs(throw_distance - 0))||((Field[0][Zeile_neu][Spalte_neu] != 0)&&(Field[0][Zeile_neu][Spalte_neu] != geben)&&(Field[0][Zeile_neu][Spalte_neu] != Torring))) {
			
			printf("	The position of choice of the Quaffel ?		(Range: %u)\n", throw_distance);
			printf("	neue Zeile: \n neue Spalte: \n");
			
			letters_4 = get_unsigned_numeric_input_with_not_more_than_letters_4_for_splitting();
			Zeile_neu = split_unsigned_numeric_input_with_letters_4 (letters_4, 0);
			Spalte_neu = split_unsigned_numeric_input_with_letters_4 (letters_4, 1);
		}
		
		if ((Spalte_neu == 0)&&(Zeile_neu == 0)) {
			printf("	Sweet escape...\n");
		} else {
			Moc_Quaffel->wanted_i = Zeile_neu;
			Moc_Quaffel->wanted_j = Spalte_neu;
			
			while ((Moc_Quaffel->i != Moc_Quaffel->wanted_i)||(Moc_Quaffel->j != Moc_Quaffel->wanted_j)) {
				Realize_Moc_Quaffel_Throw_step (Field, geben,  Moc_Quaffel, Torring);
			}
			
			if (Field[0][Moc_Quaffel->wanted_i][Moc_Quaffel->wanted_j] == Torring) {
				Qs->Points[geben] += 10;
				Quidditch_a_goal_has_been_scored (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, m, n, Moc_Quaffel);
			}
			
			set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, Zeile_neu, Spalte_neu, Quaffel);
			set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, Zeile_alt, Spalte_alt, 0);
		}
	}
	
	#ifdef Quidditch_mistake_search
	printf("	Quidditch_Quaffel_Throw-ending.ok \n");	//test
	#endif
	
}

void Quidditch_a_goal_has_been_scored (Spielfeld Field, unsigned int geben, Spielfeld Opague_o_field, unsigned int gamemode_played, Special_Fields Allocation_o, unsigned int number_of_players, unsigned int m, unsigned int n, Moveable_objects_condition* Moc_Quaffel) {
	
	#ifdef Quidditch_mistake_search
	printf("	Quidditch_a_goal_has_been_scored-beginning.ok \n");	//test
	#endif
	
	unsigned int only_need_one_square;
	
	only_need_one_square = hayir;
	
	for (unsigned int i=(m+1)/2; i<=m-2; i++) {
		for (unsigned int j=1; j<=n-2; j++) {
			if (Field[0][i][j] == Jaeger_1) {
				for (unsigned int h=1; h<=(m-3)/2; h++) {
					for (unsigned int k=1; k<=n-2; k++) {
						if (Field[0][h][k] == 1) {
							set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, i, j, 1);
							set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, h, k, Jaeger_1);
							only_need_one_square = evet;
							break;
						}
					}
					if (only_need_one_square == evet) {
						only_need_one_square = hayir;	//there are maybe more than 1 Jaeger who can get back
						break;
					}
				}
			}
		}
	}
	for (unsigned int i=1; i<=(m-3)/2; i++) {
		for (unsigned int j=1; j<=n-2; j++) {
			if (Field[0][i][j] == Jaeger_2) {
				for (unsigned int h=m-2; h>=(m+1)/2; h--) {
					for (unsigned int k=1; k<=n-2; k++) {
						if (Field[0][h][k] == 2) {
							set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, i, j, 2);
							set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, h, k, Jaeger_1);
							only_need_one_square = evet;
							break;
						}
					}
					if (only_need_one_square == evet) {
						only_need_one_square = hayir;	//there are maybe more than 1 Jaeger who can get pulled back
						break;
					}
				}
			}
		}
	}
	
	only_need_one_square = hayir;
	if (geben == 1) {	//where to put the Quaffel (look at the h-loop).
		for (unsigned int h=m-1; h<=m-2; h++) {
			for (unsigned int k=2; k<=n-1; k++) {	//don't want it at the wall.
				if (Field[0][h][k] <= 2) {
					set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, h, k, Quaffel);
					Moc_Quaffel->i = h;
					Moc_Quaffel->j = k;
					only_need_one_square = evet;
					break;
				}
			}
			if (only_need_one_square == evet) {
				break;
			}
		}
	} else if (geben == 2) {
		for (unsigned int h=2; h>=1; h--) {
			for (unsigned int k=2; k<=n-1; k++) {
				if (Field[0][h][k] <= 2) {
					set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, h, k, Quaffel);
					Moc_Quaffel->i = h;
					Moc_Quaffel->j = k;
					only_need_one_square = evet;
					break;
				}
			}
			if (only_need_one_square == evet) {
				break;
			}
		}
	}
	
	#ifdef Quidditch_mistake_search
	printf("	Quidditch_a_goal_has_been_scored-ending.ok \n");	//test
	#endif
	
}

void Realize_Moc_Quaffel_Throw_step (Spielfeld Field, unsigned int geben, Moveable_objects_condition* Moc_Quaffel, unsigned int Torring) {
	
	#ifdef Quidditch_mistake_search
	printf("	Realize_Moc_Quaffel_Throw_step-beginning.ok \n");	//test
	#endif
	
	unsigned int direction_choice, Jaeger, Hueter;
	int i_difference, j_difference;
	
	direction_choice = undefined;
	Jaeger = undefined;
	Hueter = undefined;
	i_difference = 0;
	j_difference = 0;
	
	
	if (geben == 2) {
		Hueter = Hueter_1;
		Jaeger = Jaeger_1;
	} else if (geben == 1) {
		Hueter = Hueter_2;
		Jaeger = Jaeger_2;
	}
	i_difference = Moc_Quaffel->wanted_i - Moc_Quaffel->i;
	j_difference = Moc_Quaffel->wanted_j - Moc_Quaffel->j;
	
	if (i_difference == 0) {
		direction_choice = Vertikal;
	} else if (j_difference == 0) {
		direction_choice = Horizontal;
	} else if (abs(i_difference) == abs(j_difference)) {
		direction_choice = Changing;
	} else {
		while (((direction_choice != Horizontal)||(abs(i_difference) <= abs(j_difference)))&&((direction_choice != Vertikal)||(abs(i_difference) >= abs(j_difference)))&&((direction_choice != Changing)||((i_difference != 0)&&(j_difference != 0)))) {
			
		}
		printf("	How do you want to throw? 	(target: [%u][%u]) \n", Moc_Quaffel->wanted_i, Moc_Quaffel->wanted_j);
		if (abs(i_difference) > abs(j_difference)) {
			printf("	%u: Horizontal \n", Horizontal);
		}
		if (abs(i_difference) < abs(j_difference)) {
			printf("	%u: Vertikal \n", Vertikal);
		}
		if ((i_difference != 0)&&(j_difference != 0)) {
			printf("	%u: diagonal \n", Changing);
		}
		
		direction_choice = get_unsigned_numeric_input_with_not_more_than_1_letter ();
	}
	
	//it is important that Horizontal comes before Vertikal for the scoring of goals
	
	if ((direction_choice == Horizontal)||(direction_choice == Changing)) {
		if (i_difference < 0) {	//have a look on the definition of the difference.
			Moc_Quaffel->i -= 1;
		} else if (i_difference > 0) {
			Moc_Quaffel->i += 1;
		}
		
		if ((Moc_Quaffel->i == Moc_Quaffel->wanted_i)&&(Moc_Quaffel->j == Moc_Quaffel->wanted_j)&&(Field[0][Moc_Quaffel->wanted_i][Moc_Quaffel->wanted_j] == Torring)) {	//only possible if there's no Vertikal anymore
			
			if (i_difference < 0) {	//have a look on the definition of the difference.
				Moc_Quaffel->i += 1;
			} else if (i_difference > 0) {
				Moc_Quaffel->i -= 1;
			}
			Moc_Quaffel->wanted_i = Moc_Quaffel->i;	//break before reaching the Torring, because you hit it from the side.
		}
	}
	if ((direction_choice == Vertikal)||(direction_choice == Changing)) {
		if (j_difference < 0) {	//have a look on the definition of the difference.
			Moc_Quaffel->i -= 1;
		} else if (j_difference > 0) {
			Moc_Quaffel->i += 1;
		}
	}
	
	for (unsigned int h=0; h<=2; h++) {
		for (unsigned int k=0; k<=2; k++) {
			if ((h+k)%2 == 1) {
				if ((Field[0][Moc_Quaffel->i +h-1][Moc_Quaffel->j +k-1] == Jaeger)||(Field[0][Moc_Quaffel->i +h-1][Moc_Quaffel->j +k-1] == Hueter)) {
					Moc_Quaffel->wanted_i = Moc_Quaffel->i;	//caught by the enemy
					Moc_Quaffel->wanted_j = Moc_Quaffel->j;
				}
			}
		}
	}
	
	#ifdef Quidditch_mistake_search
	printf("	Realize_Moc_Quaffel_Throw_step-ending.ok \n");	//test
	#endif
	
}

void Move_of_a_Quidditch_player (Spielfeld Field, unsigned int geben, Spielfeld Opague_o_field, unsigned int gamemode_played, Special_Fields Allocation_o, unsigned int number_of_players, unsigned int Team_member, unsigned int fly_distance, unsigned int m, unsigned int n, unsigned int* g, Moveable_objects_condition* Moc_Schnatz, Moveable_objects_condition* Moc_Quaffel, unsigned int* Points) {
	
	#ifdef Quidditch_mistake_search
	printf("	Move_of_a_Quidditch_player-beginning.ok \n");	//test
	#endif
	
	unsigned int Zeile_alt, Spalte_alt, Zeile_neu, Spalte_neu;
	unsigned int b, unutma_i, unutma_j;
	
	//Team_member = Hueter, Sucher, Treiber, Jaeger
	
	b = hayir;
	
	Zeile_alt = m;	//to get out of range, because zero would lead to "Sweet..."
	Spalte_alt = n;

	Zeile_neu = 0;
	Spalte_neu = 0;

	while (((Zeile_alt > m-2)||(Spalte_alt > n-2)||(Field[0][Zeile_alt][Spalte_alt] != Team_member))&&((Spalte_alt != 0)||(Zeile_alt != 0))) {
		printf("	The position of the Quidditch-player ?\n");
		printf("	alte Zeile: \n	alte Spalte: \n");
		
		letters_4 = get_unsigned_numeric_input_with_not_more_than_letters_4_for_splitting();
		Zeile_alt = split_unsigned_numeric_input_with_letters_4 (letters_4, 0);
		Spalte_alt = split_unsigned_numeric_input_with_letters_4 (letters_4, 1);
	}
	
	if ((Spalte_alt == 0)&&(Zeile_alt == 0)) {
		printf("	Sweet escape...\n");
	} else {
		printf("	The position of choice of the Quidditch-player ?\n");
		printf("	neue Zeile: \n	neue Spalte: \n");
		
		letters_4 = get_unsigned_numeric_input_with_not_more_than_letters_4_for_splitting();
		Zeile_neu = split_unsigned_numeric_input_with_letters_4 (letters_4, 0);
		Spalte_neu = split_unsigned_numeric_input_with_letters_4 (letters_4, 1);
		
		for (unsigned int p=fly_distance; p>=1; p--) {
			for (unsigned int i=0; i<=2; i++) {
				for (unsigned int j=0; j<=2; j++) {
					if ((Zeile_alt + p*i-p*1 <= m-2)&&(Spalte_alt + p*j-p*1 <= n-2)) {	//Stackoverflow solves the bottom-border
						if ((Field[0][Zeile_alt + p*i-p*1][Spalte_alt + p*j-p] == geben)&&(Zeile_alt + p*i-p == Zeile_neu)&&(Spalte_alt + p*j-p == Spalte_neu)) {
							b = evet;
							unutma_i = i;
							unutma_j = j;
							break;	//The new position is valid and found.
						}
					}
				}
				if (b == evet) {	//shortcut
					break;
				}
			}
			if (b == evet) {	//shortcut
				break;
			}
		}
		
		if (b == hayir) {	//The wanted new position wasn't valid.
			
			Move_of_a_Quidditch_player (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Team_member, fly_distance, m, n, g, Moc_Schnatz, Moc_Quaffel, Points);	//try again at the very beginning.
		} else {
			set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, Zeile_neu, Spalte_neu, Team_member);
			set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, Zeile_alt, Spalte_alt, geben);	//Changing of the positions
			
			b = 0;	//new usage of b
			while ((Zeile_alt + b*(unutma_i-1) != Zeile_neu)||(Spalte_alt + b*(unutma_j-1) != Spalte_neu)) {	//"||(b <= fly_distance)" deleted, Schnatz/Quaffel-Regelungen beim Durchqueren/Mitnehmen.
				if ((Team_member == Sucher_1)||(Team_member == Sucher_2)) {
					if ((Zeile_alt + b*(unutma_i-1) == Moc_Schnatz->i)&&(Spalte_alt + b*(unutma_j-1) == Moc_Schnatz->j)) {
						set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, Moc_Schnatz->i, Moc_Schnatz->j, 0);
						Moc_Schnatz->i = 0;
						Moc_Schnatz->j = 0;
						*g = 0;
						if (Team_member == Sucher_1) {	// Catch of the Schnatz.
							Points[1] += 150;
						} else if (Team_member == Sucher_2) {
							Points[2] += 150;
						}
					}
				} else if ((Team_member == Jaeger_1)||(Team_member == Hueter_1)||(Team_member == Jaeger_2)||(Team_member == Hueter_2)) {	//All Quaffel-carrying people.
					for (unsigned int i=0; i<=2; i++) {
						for (unsigned int j=0; j<=2; j++) {
							if ((Zeile_alt-1+i + b*(unutma_i-1) == Moc_Quaffel->i)&&(Spalte_alt-1+j + b*(unutma_j-1) == Moc_Quaffel->j)&&((j%2 == 1)||(i%2 == 1))) {
								//Near-by controlling is following:
								if ((Field[0][Zeile_neu-1][Spalte_neu] == 0)||(Field[0][Zeile_neu-1][Spalte_neu] == geben)) {
									set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, Moc_Quaffel->i, Moc_Quaffel->j, 0);
									set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, Zeile_neu-1, Spalte_neu, Quaffel);
									Moc_Quaffel->i = Zeile_neu-1;
									Moc_Quaffel->j = Spalte_neu;
								} else if ((Field[0][Zeile_neu+1][Spalte_neu] == 0)||(Field[0][Zeile_neu+1][Spalte_neu] == geben)) {
									set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, Moc_Quaffel->i, Moc_Quaffel->j, 0);
									set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, Zeile_neu+1, Spalte_neu, Quaffel);
									Moc_Quaffel->i = Zeile_neu+1;
									Moc_Quaffel->j = Spalte_neu;
								} else if ((Field[0][Zeile_neu][Spalte_neu-1] == 0)||(Field[0][Zeile_neu][Spalte_neu-1] == geben)) {
									set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, Moc_Quaffel->i, Moc_Quaffel->j, 0);
									set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, Zeile_neu, Spalte_neu-1, Quaffel);
									Moc_Quaffel->i = Zeile_neu;
									Moc_Quaffel->j = Spalte_neu-1;
								} else if ((Field[0][Zeile_neu][Spalte_neu+1] == 0)||(Field[0][Zeile_neu][Spalte_neu+1] == geben)) {
									set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, Moc_Quaffel->i, Moc_Quaffel->j, 0);
									set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, Zeile_neu, Spalte_neu+1, Quaffel);
									Moc_Quaffel->i = Zeile_neu;
									Moc_Quaffel->j = Spalte_neu+1;
								}	//If no near-by-field is free (zero or in your possession with a normal square), you can't pick up the Quaffel.
							}
						}
					}
				}
				b+=1;
			}
		}
	}
	
	#ifdef Quidditch_mistake_search
	printf("	Move_of_a_Quidditch_player-ending.ok \n");	//test
	#endif
	
}

void Quidditch_Klatscher_movements (Spielfeld Field, unsigned int geben, Spielfeld Opague_o_field, unsigned int gamemode_played, Special_Fields Allocation_o, unsigned int number_of_players, unsigned int m, unsigned int n, Moveable_objects_condition* Moc_Klatscher, Quidditch_setup* Qs) {
	
	#ifdef Quidditch_mistake_search
	printf("	Quidditch_Klatscher_movements-beginning.ok \n");	//test
	#endif
	
	for (unsigned int p=0; p<=1; p++) {
		
		#ifdef Quidditch_mistake_search
		printf("	Klatscher[%u]: [%u][%u] \n", p, Moc_Klatscher[p].i, Moc_Klatscher[p].j);	//test
		#endif
	
		Quidditch_Klatscher_target_search (Field, m, n, Moc_Klatscher, p);	//fill in wanted
		
		Moc_Klatscher[p].remaining_squares_to_move = Qs->Qoa->Klatscher_fly_distance;
		
		Quidditch_move_of_Klatscher (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, m, n, Moc_Klatscher, p, Qs);
		
		Moc_Klatscher[p].wanted_i = 0;
		Moc_Klatscher[p].wanted_j = 0;
	}
	
	#ifdef Quidditch_mistake_search
	printf("	Quidditch_Klatscher_movements-ending.ok \n");	//test
	#endif
	
}

void Quidditch_move_of_Klatscher (Spielfeld Field, unsigned int geben, Spielfeld Opague_o_field, unsigned int gamemode_played, Special_Fields Allocation_o, unsigned int number_of_players, unsigned int m, unsigned int n, Moveable_objects_condition* Moc_Klatscher, unsigned int p, Quidditch_setup* Qs) {
	
	#ifdef Quidditch_mistake_search
	printf("	Quidditch_move_of_Klatscher-beginning.ok \n");	//test
	#endif
	
	int i_difference, j_difference;
	
	i_difference = 0;
	j_difference = 0;
	
	i_difference = Moc_Klatscher[p].wanted_i - Moc_Klatscher[p].i;
	j_difference = Moc_Klatscher[p].wanted_j - Moc_Klatscher[p].j;
	
	#ifdef Quidditch_mistake_search
	printf("	Klatscher[%u]: [%u][%u] \n", p, Moc_Klatscher[p].i, Moc_Klatscher[p].j);	//test
	#endif
	
	Quidditch_Klatscher_steps (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, m, n, Moc_Klatscher, p, i_difference, j_difference, Qs);
	
	#ifdef Quidditch_mistake_search
	printf("	Quidditch_move_of_Klatscher-ending.ok \n");	//test
	#endif
	
}

void Quidditch_Klatscher_steps (Spielfeld Field, unsigned int geben, Spielfeld Opague_o_field, unsigned int gamemode_played, Special_Fields Allocation_o, unsigned int number_of_players, unsigned int m, unsigned int n, Moveable_objects_condition* Moc_Klatscher, unsigned int p, int i_difference, int j_difference, Quidditch_setup* Qs) {
	
	#ifdef Quidditch_mistake_search
	printf("	Quidditch_Klatscher_steps-beginning.ok \n");	//test
	#endif
	
	unsigned int unutma_i, unutma_j;
	
	unutma_i = Moc_Klatscher[p].i;
	unutma_j = Moc_Klatscher[p].j;
	
	//812
	//703
	//654
	//this is the directed-table
	
	while (Moc_Klatscher[p].remaining_squares_to_move != 0) {	//the way of the Klatscher
		
		#ifdef Quidditch_mistake_search
		printf("	Moc_Klatscher[%u].remaining_squares_to_move = %u \n", p, Moc_Klatscher[p].remaining_squares_to_move);	//test
		#endif
		
		if (Moc_Klatscher[p].directed == 0) {
			if (i_difference > 0) {
				if (j_difference > 0) {
					Moc_Klatscher[p].directed = 4;
				} else if (j_difference < 0) {
					Moc_Klatscher[p].directed = 6;
				} else if (j_difference == 0) {
					Moc_Klatscher[p].directed = 5;
				}
				Moc_Klatscher[p].remaining_squares_to_move -= 1;
				
			} else if (i_difference < 0) {
				if (j_difference > 0) {
					Moc_Klatscher[p].directed = 2;
				} else if (j_difference < 0) {
					Moc_Klatscher[p].directed = 8;
				} else if (j_difference == 0) {
					Moc_Klatscher[p].directed = 1;
				}
				Moc_Klatscher[p].remaining_squares_to_move -= 1;
				
			} else if (i_difference == 0) {
				if (j_difference > 0) {
					Moc_Klatscher[p].directed = 3;
				} else if (j_difference < 0) {
					Moc_Klatscher[p].directed = 7;
				}
				Moc_Klatscher[p].remaining_squares_to_move -= 1;
				
			}
		}
		
		if (i_difference > 0) {
			if (j_difference > 0) {
				if (Moc_Klatscher[p].directed == 4) {
					Moc_Klatscher[p].i += 1;
					Moc_Klatscher[p].j += 1;
					Moc_Klatscher[p].remaining_squares_to_move -= 1;
					
				} else if ((Moc_Klatscher[p].directed == 3)&&(j_difference > i_difference)) {
					Moc_Klatscher[p].j += 1;
					Moc_Klatscher[p].remaining_squares_to_move -= 1;
					
				} else if ((Moc_Klatscher[p].directed == 5)&&(i_difference > j_difference)) {
					Moc_Klatscher[p].i += 1;
					Moc_Klatscher[p].remaining_squares_to_move -= 1;
					
				} else {
					Moc_Klatscher[p].remaining_squares_to_move -= 1;
					if ((Moc_Klatscher[p].remaining_squares_to_move != 0)&&(Moc_Klatscher[p].directed == 8)) {
						Moc_Klatscher[p].remaining_squares_to_move -= 1;
					}
					Moc_Klatscher[p].directed = 4;
				}
			} else if (j_difference < 0) {
				if (Moc_Klatscher[p].directed == 6) {
					Moc_Klatscher[p].i += 1;
					Moc_Klatscher[p].j -= 1;
					Moc_Klatscher[p].remaining_squares_to_move -= 1;
					
				} else if ((Moc_Klatscher[p].directed == 7)&&(abs(j_difference) > i_difference)) {
					Moc_Klatscher[p].j -= 1;
					Moc_Klatscher[p].remaining_squares_to_move -= 1;
					
				} else if ((Moc_Klatscher[p].directed == 5)&&(i_difference > abs(j_difference))) {
					Moc_Klatscher[p].i += 1;
					Moc_Klatscher[p].remaining_squares_to_move -= 1;
					
				} else {
					Moc_Klatscher[p].remaining_squares_to_move -= 1;
					if ((Moc_Klatscher[p].remaining_squares_to_move != 0)&&(Moc_Klatscher[p].directed == 2)) {
						Moc_Klatscher[p].remaining_squares_to_move -= 1;
					}
					Moc_Klatscher[p].directed = 6;
				}
			} else if (j_difference == 0) {
				if (Moc_Klatscher[p].directed == 5) {
					Moc_Klatscher[p].i += 1;
					Moc_Klatscher[p].remaining_squares_to_move -= 1;
					
				} else {
					Moc_Klatscher[p].remaining_squares_to_move -= 1;
					if ((Moc_Klatscher[p].remaining_squares_to_move != 0)&&(Moc_Klatscher[p].directed == 1)) {
						Moc_Klatscher[p].remaining_squares_to_move -= 1;
					}
					Moc_Klatscher[p].directed = 5;
				}
			}
		} else if (i_difference < 0) {
			if (j_difference > 0) {
				if (Moc_Klatscher[p].directed == 2) {
					Moc_Klatscher[p].i -= 1;
					Moc_Klatscher[p].j += 1;
					Moc_Klatscher[p].remaining_squares_to_move -= 1;
					
				} else if ((Moc_Klatscher[p].directed == 3)&&(abs(j_difference) > abs(i_difference))) {
					Moc_Klatscher[p].j += 1;
					Moc_Klatscher[p].remaining_squares_to_move -= 1;
					
				} else if ((Moc_Klatscher[p].directed == 1)&&(abs(i_difference) > abs(j_difference))) {
					Moc_Klatscher[p].i -= 1;
					Moc_Klatscher[p].remaining_squares_to_move -= 1;
					
				} else {
					Moc_Klatscher[p].remaining_squares_to_move -= 1;
					if ((Moc_Klatscher[p].remaining_squares_to_move != 0)&&(Moc_Klatscher[p].directed == 6)) {
						Moc_Klatscher[p].remaining_squares_to_move -= 1;
					}
					Moc_Klatscher[p].directed = 2;
				}
			} else if (j_difference < 0) {
				if (Moc_Klatscher[p].directed == 8) {
					Moc_Klatscher[p].i -= 1;
					Moc_Klatscher[p].j -= 1;
					Moc_Klatscher[p].remaining_squares_to_move -= 1;
					
				} else if ((Moc_Klatscher[p].directed == 7)&&(abs(j_difference) > abs(i_difference))) {
					Moc_Klatscher[p].j -= 1;
					Moc_Klatscher[p].remaining_squares_to_move -= 1;
					
				} else if ((Moc_Klatscher[p].directed == 1)&&(abs(i_difference) > abs(j_difference))) {
					Moc_Klatscher[p].i -= 1;
					Moc_Klatscher[p].remaining_squares_to_move -= 1;
					
				} else {
					Moc_Klatscher[p].remaining_squares_to_move -= 1;
					if ((Moc_Klatscher[p].remaining_squares_to_move != 0)&&(Moc_Klatscher[p].directed == 4)) {
						Moc_Klatscher[p].remaining_squares_to_move -= 1;
					}
					Moc_Klatscher[p].directed = 8;
				}
			} else if (j_difference == 0) {
				if (Moc_Klatscher[p].directed == 1) {
					Moc_Klatscher[p].i -= 1;
					Moc_Klatscher[p].remaining_squares_to_move -= 1;
					
				} else {
					Moc_Klatscher[p].remaining_squares_to_move -= 1;
					if ((Moc_Klatscher[p].remaining_squares_to_move != 0)&&(Moc_Klatscher[p].directed == 5)) {
						Moc_Klatscher[p].remaining_squares_to_move -= 1;
					}
					Moc_Klatscher[p].directed = 1;
				}
			}
		} else if (i_difference == 0) {
			if (j_difference > 0) {
				if (Moc_Klatscher[p].directed == 3) {
					Moc_Klatscher[p].j += 1;
					Moc_Klatscher[p].remaining_squares_to_move -= 1;
					
				} else {
					Moc_Klatscher[p].remaining_squares_to_move -= 1;
					if ((Moc_Klatscher[p].remaining_squares_to_move != 0)&&(Moc_Klatscher[p].directed == 7)) {
						Moc_Klatscher[p].remaining_squares_to_move -= 1;
					}
					Moc_Klatscher[p].directed = 3;
				}
			} else if (j_difference < 0) {
				if (Moc_Klatscher[p].directed == 7) {
					Moc_Klatscher[p].j -= 1;
					Moc_Klatscher[p].remaining_squares_to_move -= 1;
					
				} else {
					Moc_Klatscher[p].remaining_squares_to_move -= 1;
					if ((Moc_Klatscher[p].remaining_squares_to_move != 0)&&(Moc_Klatscher[p].directed == 3)) {
						Moc_Klatscher[p].remaining_squares_to_move -= 1;
					}
					Moc_Klatscher[p].directed = 7;
				}
			}
		}
	}
	if ((Field[0][Moc_Klatscher[p].i][Moc_Klatscher[p].j] != Torring_1)&&(Field[0][Moc_Klatscher[p].i][Moc_Klatscher[p].j] != Torring_2)&&(Field[0][Moc_Klatscher[p].i][Moc_Klatscher[p].j] != Klatscher)) {
		if ((Field[0][Moc_Klatscher[p].i][Moc_Klatscher[p].j] == Jaeger_1)||(Field[0][Moc_Klatscher[p].i][Moc_Klatscher[p].j] == Hueter_1)||(Field[0][Moc_Klatscher[p].i][Moc_Klatscher[p].j] == Sucher_1)) {
			Klatscher_hits_target (2, Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, m, n,  Moc_Klatscher, p, Qs);
		} else if ((Field[0][Moc_Klatscher[p].i][Moc_Klatscher[p].j] == Jaeger_2)||(Field[0][Moc_Klatscher[p].i][Moc_Klatscher[p].j] == Hueter_2)||(Field[0][Moc_Klatscher[p].i][Moc_Klatscher[p].j] == Sucher_2)) {
			Klatscher_hits_target (1, Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, m, n,  Moc_Klatscher, p, Qs);
		} else if (Field[0][Moc_Klatscher[p].i][Moc_Klatscher[p].j] == Treiber_1) {
			Treiber_hits_Klatscher (1, Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, m, n, Moc_Klatscher, p, Qs);
		} else if (Field[0][Moc_Klatscher[p].i][Moc_Klatscher[p].j] == Treiber_2) {
			Treiber_hits_Klatscher (2, Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, m, n, Moc_Klatscher, p, Qs);
		}
		if ((Field[0][unutma_i][unutma_j] == Treiber_1)||(Field[0][unutma_i][unutma_j] == Treiber_2)) {
			while (Field[0][unutma_i][unutma_j] > number_of_players) {
				unutma_i = Zufall (1, m-2);
				unutma_j = Zufall (1, n-2);
			}
		}
		set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, unutma_i, unutma_j, Field[0][Moc_Klatscher[p].i][Moc_Klatscher[p].j]);
		set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, Moc_Klatscher[p].i, Moc_Klatscher[p].j, Klatscher);
		
	} else { //you can't push Torringe and Klatscher away.
		if ((Field[0][unutma_i][unutma_j] == Treiber_1)||(Field[0][unutma_i][unutma_j] == Treiber_2)) {
			while (Field[0][unutma_i][unutma_j] > number_of_players) {
				unutma_i = Zufall (1, m-2);
				unutma_j = Zufall (1, n-2);
			}
		}
		Moc_Klatscher[p].i = unutma_i;
		Moc_Klatscher[p].j = unutma_j;
	}
	
	#ifdef Quidditch_mistake_search
	printf("	Quidditch_Klatscher_steps-ending.ok \n");	//test
	#endif
	
}

void Klatscher_hits_target (unsigned int whose_turn, Spielfeld Field, unsigned int geben, Spielfeld Opague_o_field, unsigned int gamemode_played, Special_Fields Allocation_o, unsigned int number_of_players, unsigned int m, unsigned int n, Moveable_objects_condition* Moc_Klatscher, unsigned int p, Quidditch_setup* Qs) {
	
	#ifdef Quidditch_mistake_search
	printf("	Klatscher_hits_target-beginning.ok \n");	//test
	#endif
	
	unsigned int direction_choice;
	
	unsigned int ** allowed_directions;
	allowed_directions = unsigned_int_2dim_Vektor_Create (9, 3);
	
	direction_choice = 100;	//higher than 8
	for (unsigned int q=0; q<=8; q++) {
		allowed_directions[q][0] = hayir;
	}
	
	printf("	Player %u, a Klatscher hits the enemy at [%u][%u]. \n", whose_turn, Moc_Klatscher[p].i, Moc_Klatscher[p].j);
	printf("	In which direction do you want to push the enemy? \n");
	Klatscher_hit_allowed_directions (whose_turn, Field, m, n, Moc_Klatscher, p, allowed_directions);
	if (allowed_directions[0][0] == evet) {
		printf("	0: Change of positions \n");
	}
	if (allowed_directions[1][0] == evet) {
		printf("	1: Top \n");
	}
	if (allowed_directions[2][0] == evet) {
		printf("	2: Top & Right \n");
	}
	if (allowed_directions[3][0] == evet) {
		printf("	3: Right \n");
	}
	if (allowed_directions[4][0] == evet) {
		printf("	4: Bottom & Right \n");
	}
	if (allowed_directions[5][0] == evet) {
		printf("	5: Bottom \n");
	}
	if (allowed_directions[6][0] == evet) {
		printf("	6: Bottom & Left \n");
	}
	if (allowed_directions[7][0] == evet) {
		printf("	7: Left \n");
	}
	if (allowed_directions[8][0] == evet) {
		printf("	8: Top & Left \n");
	}
	
	while ((direction_choice > 8) || (allowed_directions[direction_choice][0] != evet)) {
		direction_choice = get_unsigned_numeric_input_with_not_more_than_1_letter ();
	}
	if ((allowed_directions[direction_choice][1] != 0)&&(allowed_directions[direction_choice][2] != 0)) {
		
		set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, allowed_directions[direction_choice][1], allowed_directions[direction_choice][2], Field[0][Moc_Klatscher[p].i][Moc_Klatscher[p].j]);
		set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, Moc_Klatscher[p].i, Moc_Klatscher[p].j, 0);
	}
	
	Qs->Points[0] += 1;
	
	unsigned_int_2dim_Vektor_Destroy (allowed_directions, 9);
	
	#ifdef Quidditch_mistake_search
	printf("	Klatscher_hits_target-ending.ok \n");	//test
	#endif
	
}

void Treiber_hits_Klatscher (unsigned int whose_turn, Spielfeld Field, unsigned int geben, Spielfeld Opague_o_field, unsigned int gamemode_played, Special_Fields Allocation_o, unsigned int number_of_players, unsigned int m, unsigned int n, Moveable_objects_condition* Moc_Klatscher, unsigned int p, Quidditch_setup* Qs) {
	
	#ifdef Quidditch_mistake_search
	printf("	Treiber_hits_Klatscher-beginning.ok \n");	//test
	#endif
	
	unsigned int allowed_directions[9], direction_choice, hit_length;
	int i_difference, j_difference;
	
	i_difference = 0;
	j_difference = 0;
	
	hit_length = 0;
	direction_choice = 0;
	for (unsigned int q=0; q<=8; q++) {
		allowed_directions[q] = evet;
	}
	
	printf("	Player %u, a Klatscher hits your Treiber at [%u][%u]. \n", whose_turn, Moc_Klatscher[p].i, Moc_Klatscher[p].j);
	printf("	In which direction do you want to hit the Klatscher? \n");
	
	if (Moc_Klatscher[p].i == 1) {
		allowed_directions[8] = hayir;
		allowed_directions[1] = hayir;
		allowed_directions[2] = hayir;
	} else if (Moc_Klatscher[p].i == m-2) {
		allowed_directions[4] = hayir;
		allowed_directions[5] = hayir;
		allowed_directions[6] = hayir;
	}
	if (Moc_Klatscher[p].j == 1) {
		allowed_directions[6] = hayir;
		allowed_directions[7] = hayir;
		allowed_directions[8] = hayir;
	} else if (Moc_Klatscher[p].j == n-2) {
		allowed_directions[2] = hayir;
		allowed_directions[3] = hayir;
		allowed_directions[4] = hayir;
	}
	
	
	while ((direction_choice == 0) || (direction_choice > 8) || (allowed_directions[direction_choice] != evet)) {
		
		if (allowed_directions[1] == evet) {
			printf("	1: Top \n");
		}
		if (allowed_directions[2] == evet) {
			printf("	2: Top & Right \n");
		}
		if (allowed_directions[3] == evet) {
			printf("	3: Right \n");
		}
		if (allowed_directions[4] == evet) {
			printf("	4: Bottom & Right \n");
		}
		if (allowed_directions[5] == evet) {
			printf("	5: Bottom \n");
		}
		if (allowed_directions[6] == evet) {
			printf("	6: Bottom & Left \n");
		}
		if (allowed_directions[7] == evet) {
			printf("	7: Left \n");
		}
		if (allowed_directions[8] == evet) {
			printf("	8: Top & Left \n");
		}
		direction_choice = get_unsigned_numeric_input_with_not_more_than_1_letter ();
	}
	while ((hit_length == 0)||(hit_length > Qs->Qta[whose_turn].Treiber_hit_distance)) {
		printf("	How many squares should been taken? 	(1 - %u)\n", Qs->Qta[whose_turn].Treiber_hit_distance);
		hit_length = get_unsigned_numeric_input_with_not_more_than_1_letter ();
	}
	
	Moc_Klatscher[p].directed = direction_choice;
	Moc_Klatscher[p].remaining_squares_to_move = hit_length;
	for (unsigned int q=1; q<=hit_length; q++) {
		if (direction_choice % 8 <= 2) {
			i_difference -= 1;
		} else if ((direction_choice >= 4)&&(direction_choice <= 6)) {
			i_difference += 1;
		}
		if (direction_choice % 9 >= 6) {
			j_difference -= 1;
		} else if ((direction_choice >= 2)&&(direction_choice <= 4)) {
			j_difference += 1;
		}
	}
	
	Quidditch_Klatscher_steps (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, m, n, Moc_Klatscher, p, i_difference, j_difference, Qs);
	
	#ifdef Quidditch_mistake_search
	printf("	Treiber_hits_Klatscher-ending.ok \n");	//test
	#endif
	
}

void Klatscher_hit_allowed_directions (unsigned int whose_turn, Spielfeld Field, unsigned int m, unsigned int n, Moveable_objects_condition* Moc_Klatscher, unsigned int p, unsigned int** allowed_directions) {
	
	#ifdef Quidditch_mistake_search
	printf("	Klatscher_hit_allowed_directions-beginning.ok \n");	//test
	#endif
	
	unsigned int h, k;
	
	h = 0;
	k = 0;
	allowed_directions[0][0] = evet;
	allowed_directions[0][1] = 0;
	allowed_directions[0][2] = 0;
	
	for (unsigned int q=1; q<=8; q++) {
		h = Moc_Klatscher[p].i;
		k = Moc_Klatscher[p].j;
		while ((h != 0)&&(k != 0)&&(h <= m-2)&&(k <= n-2)) {
			if (Field[0][h][k] == (whose_turn%2)+1) {	//search for owner-square
				allowed_directions[q][0] = evet;
				allowed_directions[q][1] = h;
				allowed_directions[q][2] = k;
				break;
			}
			
			if (q % 8 <= 2) {
				h -= 1;
			} else if ((q >= 4)&&(q <= 6)) {
				h += 1;
			}
			if (q % 9 >= 6) {
				k -= 1;
			} else if ((q >= 2)&&(q <= 4)) {
				k += 1;
			}
		}
	}
	
	#ifdef Quidditch_mistake_search
	printf("	Klatscher_hit_allowed_directions-ending.ok \n");	//test
	#endif
	
}

void Quidditch_Klatscher_target_search (Spielfeld Field, unsigned int m, unsigned int n, Moveable_objects_condition* Moc_Klatscher, unsigned int p) {	//fix it, go on

	#ifdef Quidditch_mistake_search
	printf("	Quidditch_Klatscher_target_search-beginning.ok \n");	//test
	#endif
	
	unsigned int break_up, q, unutma_direction;
	
	break_up = hayir;
	q = 1;
	unutma_direction = hayir;
	
	if (Moc_Klatscher[p].directed == 0) {
		Moc_Klatscher[p].directed = Zufall (1, 8);
		unutma_direction = evet;
	}
	
	#ifdef Quidditch_mistake_search
	printf("	Klatscher[%u]: [%u][%u] \n", p, Moc_Klatscher[p].i, Moc_Klatscher[p].j);	//test
	printf("	Klatscher[%u].directed: %u \n", p, Moc_Klatscher[p].directed);	//test
	#endif
	
	while ((Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] != Jaeger_1)&&(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] != Jaeger_2)&&(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] != Hueter_1)&&(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] != Hueter_2)&&(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] != Treiber_1)&&(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] != Treiber_2)&&(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] != Sucher_1)&&(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] != Sucher_2)) {
		
		if (Moc_Klatscher[p].directed == 1) {
			for (unsigned int h=0; h<=2*q; h++) {
				for (unsigned int k=2*q+1; k>0; k--) {
					if ((Moc_Klatscher[p].i +h -q != 0)&&(Moc_Klatscher[p].i +h -q <= m-2)&&(Moc_Klatscher[p].j +k -q-1 != 0)&&(Moc_Klatscher[p].j +k -q-1 <= n-2)) {
							Moc_Klatscher[p].wanted_i = Moc_Klatscher[p].i +h -q;
							Moc_Klatscher[p].wanted_j = Moc_Klatscher[p].i +k -q-1;
							if ((Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Jaeger_1)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Jaeger_2)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Hueter_1)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Hueter_2)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Treiber_1)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Treiber_2)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Sucher_1)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Sucher_2)) {
								break_up = evet;
								break;
							}
					}
				}
				if (break_up == evet) {
					break;
				}
			}
		} else if (Moc_Klatscher[p].directed == 2) {
			for (unsigned int k=2*q+1; k>0; k--) {
				for (unsigned int h=0; h<=2*q; h++) {
					if ((Moc_Klatscher[p].i +h -q != 0)&&(Moc_Klatscher[p].i +h -q <= m-2)&&(Moc_Klatscher[p].j +k -q-1 != 0)&&(Moc_Klatscher[p].j +k -q-1 <= n-2)) {
							Moc_Klatscher[p].wanted_i = Moc_Klatscher[p].i +h -q;
							Moc_Klatscher[p].wanted_j = Moc_Klatscher[p].i +k -q-1;
							if ((Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Jaeger_1)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Jaeger_2)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Hueter_1)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Hueter_2)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Treiber_1)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Treiber_2)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Sucher_1)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Sucher_2)) {
								break_up = evet;
								break;
							}
					}
				}
				if (break_up == evet) {
					break;
				}
			}
		} else if (Moc_Klatscher[p].directed == 3) {
			for (unsigned int k=2*q+1; k>0; k--) {
				for (unsigned int h=2*q+1; h>0; h--) {
					if ((Moc_Klatscher[p].i +h -q-1 != 0)&&(Moc_Klatscher[p].i +h -q-1 <= m-2)&&(Moc_Klatscher[p].j +k -q-1 != 0)&&(Moc_Klatscher[p].j +k -q-1 <= n-2)) {
							Moc_Klatscher[p].wanted_i = Moc_Klatscher[p].i +h -q-1;
							Moc_Klatscher[p].wanted_j = Moc_Klatscher[p].i +k -q-1;
							if ((Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Jaeger_1)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Jaeger_2)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Hueter_1)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Hueter_2)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Treiber_1)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Treiber_2)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Sucher_1)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Sucher_2)) {
								break_up = evet;
								break;
							}
					}
				}
				if (break_up == evet) {
					break;
				}
			}
		} else if (Moc_Klatscher[p].directed == 4) {
			for (unsigned int h=2*q+1; h>0; h--) {
				for (unsigned int k=2*q+1; k>0; k--) {
					if ((Moc_Klatscher[p].i +h -q-1 != 0)&&(Moc_Klatscher[p].i +h -q-1 <= m-2)&&(Moc_Klatscher[p].j +k -q-1 != 0)&&(Moc_Klatscher[p].j +k -q-1 <= n-2)) {
							Moc_Klatscher[p].wanted_i = Moc_Klatscher[p].i +h -q-1;
							Moc_Klatscher[p].wanted_j = Moc_Klatscher[p].i +k -q-1;
							if ((Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Jaeger_1)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Jaeger_2)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Hueter_1)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Hueter_2)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Treiber_1)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Treiber_2)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Sucher_1)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Sucher_2)) {
								break_up = evet;
								break;
							}
					}
				}
				if (break_up == evet) {
					break;
				}
			}
		} else if (Moc_Klatscher[p].directed == 5) {
			for (unsigned int h=2*q+1; h>0; h--) {
				for (unsigned int k=0; k<=2*q; k++) {
					if ((Moc_Klatscher[p].i +h -q-1 != 0)&&(Moc_Klatscher[p].i +h -q-1 <= m-2)&&(Moc_Klatscher[p].j +k -q != 0)&&(Moc_Klatscher[p].j +k -q <= n-2)) {
							Moc_Klatscher[p].wanted_i = Moc_Klatscher[p].i +h -q-1;
							Moc_Klatscher[p].wanted_j = Moc_Klatscher[p].i +k -q;
							if ((Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Jaeger_1)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Jaeger_2)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Hueter_1)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Hueter_2)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Treiber_1)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Treiber_2)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Sucher_1)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Sucher_2)) {
								break_up = evet;
								break;
							}
					}
				}
				if (break_up == evet) {
					break;
				}
			}
		} else if (Moc_Klatscher[p].directed == 6) {
			for (unsigned int k=0; k<=2*q; k++) {
				for (unsigned int h=2*q+1; h>0; h--) {
					if ((Moc_Klatscher[p].i +h -q-1 != 0)&&(Moc_Klatscher[p].i +h -q-1 <= m-2)&&(Moc_Klatscher[p].j +k -q != 0)&&(Moc_Klatscher[p].j +k -q <= n-2)) {
							Moc_Klatscher[p].wanted_i = Moc_Klatscher[p].i +h -q-1;
							Moc_Klatscher[p].wanted_j = Moc_Klatscher[p].i +k -q;
							if ((Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Jaeger_1)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Jaeger_2)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Hueter_1)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Hueter_2)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Treiber_1)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Treiber_2)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Sucher_1)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Sucher_2)) {
								break_up = evet;
								break;
							}
					}
				}
				if (break_up == evet) {
					break;
				}
			}
		} else if (Moc_Klatscher[p].directed == 7) {
			for (unsigned int k=0; k<=2*q; k++) {
				for (unsigned int h=0; h<=2*q; h++) {
					if ((Moc_Klatscher[p].i +h -q != 0)&&(Moc_Klatscher[p].i +h -q <= m-2)&&(Moc_Klatscher[p].j +k -q != 0)&&(Moc_Klatscher[p].j +k -q <= n-2)) {
							Moc_Klatscher[p].wanted_i = Moc_Klatscher[p].i +h -q;
							Moc_Klatscher[p].wanted_j = Moc_Klatscher[p].i +k -q;
							if ((Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Jaeger_1)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Jaeger_2)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Hueter_1)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Hueter_2)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Treiber_1)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Treiber_2)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Sucher_1)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Sucher_2)) {
								break_up = evet;
								break;
							}
					}
				}
				if (break_up == evet) {
					break;
				}
			}
		} else if (Moc_Klatscher[p].directed == 8) {
			for (unsigned int h=0; h<=2*q; h++) {
				for (unsigned int k=0; k<=2*q; k++) {
					if ((Moc_Klatscher[p].i +h -q != 0)&&(Moc_Klatscher[p].i +h -q <= m-2)&&(Moc_Klatscher[p].j +k -q != 0)&&(Moc_Klatscher[p].j +k -q <= n-2)) {
							Moc_Klatscher[p].wanted_i = Moc_Klatscher[p].i +h -q;
							Moc_Klatscher[p].wanted_j = Moc_Klatscher[p].i +k -q;
							if ((Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Jaeger_1)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Jaeger_2)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Hueter_1)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Hueter_2)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Treiber_1)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Treiber_2)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Sucher_1)||(Field[0][Moc_Klatscher[p].wanted_i][Moc_Klatscher[p].wanted_j] == Sucher_2)) {
								break_up = evet;
								break;
							}
					}
				}
				if (break_up == evet) {
					break;
				}
			}
		}
		
		q += 1;
	}
	
	if (unutma_direction == evet) {
		Moc_Klatscher[p].directed = 0;
	}
	
	#ifdef Quidditch_mistake_search
	printf("	Klatscher-Target: [%u][%u] \n", Moc_Klatscher[p].wanted_i, Moc_Klatscher[p].wanted_j);	//test
	#endif
	
	#ifdef Quidditch_mistake_search
	printf("	Quidditch_Klatscher_target_search-ending.ok \n");	//test
	#endif
	
}

void Quidditch_Schnatz_movements (Spielfeld Field, unsigned int geben, Spielfeld Opague_o_field, unsigned int gamemode_played, Special_Fields Allocation_o, unsigned int number_of_players, unsigned int m, unsigned int n, Moveable_objects_condition* Moc_Schnatz, Quidditch_setup* Qs, unsigned int use_number) {
	
	#ifdef Quidditch_mistake_search
	printf("	Quidditch_Schnatz_movements-beginning.ok \n");	//test
	#endif
	
	unsigned int a_random_number, short_cut;
	
	a_random_number = undefined;
	short_cut = hayir;
	
	if (Moc_Schnatz->directed == hayir) {	//not on the field.
		a_random_number = Zufall (1, (Qs->Qoa->Schnatz_appearence_factor)%10);
		if (a_random_number <= (Qs->Qoa->Schnatz_appearence_factor)/10) {	//Appearence
			if (use_number%2 == 0) {
				for (unsigned int h=1; h<=m-2; h++) {
					for (unsigned int k=1; k<=n-2; k++) {
						if (Field[0][h][k] == Klatscher) {
							Moc_Schnatz->i = h;
							Moc_Schnatz->j = k;	//The Klatscher's position is imitating a Schnatz-position.
							Moc_Schnatz->remaining_squares_to_move = 2* Qs->Qoa->Schnatz_fly_distance;
							Quidditch_move_of_Schnatz (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, m, n, Moc_Schnatz);
						}
						short_cut = evet;
						break;
					}
					if (short_cut == evet) {
						break;
					}
				}
			} else if (use_number%2 == 1) {
				for (unsigned int h=m-2; h>0; h--) {
					for (unsigned int k=n-2; k>0; k--) {
						if (Field[0][h][k] == Klatscher) {
							Moc_Schnatz->i = h;
							Moc_Schnatz->j = k;	//The Klatscher's position is imitating a Schnatz-position.
							Moc_Schnatz->remaining_squares_to_move = 2* Qs->Qoa->Schnatz_fly_distance;
							Quidditch_move_of_Schnatz (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, m, n, Moc_Schnatz);
						}
						short_cut = evet;
						break;
					}
					if (short_cut == evet) {
						break;
					}
				}
			}
			Moc_Schnatz->directed = evet;
		}
	} else if (Moc_Schnatz->directed == evet) {	//on the field.
		a_random_number = Zufall (1, (Qs->Qoa->Schnatz_disappearence_factor)%10);
		if (a_random_number <= (Qs->Qoa->Schnatz_disappearence_factor)/10) {	//Dis-Appearence
			set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, Moc_Schnatz->i, Moc_Schnatz->j, 0);
			Moc_Schnatz->directed = hayir;
			Moc_Schnatz->i = 0;
			Moc_Schnatz->j = 0;
		} else {
			Moc_Schnatz->remaining_squares_to_move = Qs->Qoa->Schnatz_fly_distance;
			Quidditch_move_of_Schnatz (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, m, n, Moc_Schnatz);
		}
	}

	#ifdef Quidditch_mistake_search
	printf("	Quidditch_Schnatz_movements-ending.ok \n");	//test
	#endif
	
}

void Quidditch_move_of_Schnatz (Spielfeld Field, unsigned int geben, Spielfeld Opague_o_field, unsigned int gamemode_played, Special_Fields Allocation_o, unsigned int number_of_players, unsigned int m, unsigned int n, Moveable_objects_condition* Moc_Schnatz) {
	
	#ifdef Quidditch_mistake_search
	printf("	Quidditch_move_of_Schnatz-beginning.ok \n");	//test
	#endif
	
	unsigned int direction_choice, exit_counter, remember_steps_amount, unutma_i, unutma_j;
	
	unutma_i = Moc_Schnatz->i;
	unutma_j = Moc_Schnatz->j;
	direction_choice = undefined;
	exit_counter = 0;
	remember_steps_amount = Moc_Schnatz->remaining_squares_to_move;
	
	while (Moc_Schnatz->remaining_squares_to_move != 0) {
		direction_choice = Zufall (0, 9);
		dokuz_direction_interpretation_single_step (Moc_Schnatz, direction_choice);
		Moc_Schnatz->remaining_squares_to_move -= 1;
		if ((Moc_Schnatz->remaining_squares_to_move == 0)&&((Moc_Schnatz->i > m-2)||(Moc_Schnatz->i == 0)||(Moc_Schnatz->j > n-2)||(Moc_Schnatz->j == 0)||(Field[0][Moc_Schnatz->i][Moc_Schnatz->j] > number_of_players))) {
			Moc_Schnatz->remaining_squares_to_move = remember_steps_amount;
			Moc_Schnatz->i = unutma_i;
			Moc_Schnatz->j = unutma_j;
		}
		exit_counter += 1;
		if (exit_counter >= 1000) {
			break;
		}
	}
	
	set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, unutma_i, unutma_j, 0);	//The order of "set_.." is important for the cause, that the Schnatz' position stays the same
	set_Spielfeld_Eintrag (Field, geben, Opague_o_field, gamemode_played, Allocation_o, number_of_players, Field, 0, Moc_Schnatz->i, Moc_Schnatz->j, Schnatz);
	
	#ifdef Quidditch_mistake_search
	printf("	Quidditch_move_of_Schnatz-ending.ok \n");	//test
	#endif
	
}

void dokuz_direction_interpretation_single_step (Moveable_objects_condition* Moc, unsigned int direction_choice) {
	
	#ifdef Quidditch_mistake_search
	printf("	dokuz_direction_interpretation_single_step-beginning.ok \n");	//test
	#endif
	
	if (direction_choice != 0) {
		if (direction_choice % 8 <= 2) {
			Moc->i -= 1;
		} else if ((direction_choice >= 4)&&(direction_choice <= 6)) {
			Moc->i += 1;
		}
		if (direction_choice % 9 >= 6) {
			Moc->j -= 1;
		} else if ((direction_choice >= 2)&&(direction_choice <= 4)) {
			Moc->j += 1;
		}
	}
	
	#ifdef Quidditch_mistake_search
	printf("	dokuz_direction_interpretation_single_step-ending.ok \n");	//test
	#endif
	
}

//Dynamic (gamemode_played)	, done		(just notes following)
//Geschwindigkeit (Vertikal, Horizontal)
//Beschleunigung (Vertikal, Horizontal)
//range (distance:0-5 in Manhatten-Norm)	--> distance+1 = difference, normal:2
//impact y=f(x), x distance, in beschleunigung(linear[f(x)=a*(range-x+1); a=1,2,3; x<=range], semi-square[f(x)=a*(range-x)^2 +1; a=1,2,3; x<=range], square[f(x)=a*(range-x+1)^2; a=1,2,3; x<=range]) normal:semi-square, a=1
//Erdanziehung g linear auf Beschleunigung (-g = 0-5)		normal:1
//crash mit Hindernis: Geschwindigkeit, Beschleunigung, Weg entgegengesetzt +1, mit der Bewegung Hindernis um 1 verschieben, Richtung des wegen zwischen Vertikal-Horizontal ändern
//crash mit solider Formation: (-1)* sofort auf 1.Beschleunigung(oder 2.Geschwindigkeit) statt Berechnung, -(restliche Wegstrecke+2) falls sgn ändert
//Übertragung Beschleunigung-Geschwindigkeit?
//Grundbetrag: Vertikal: s=sgn(a)*a^2+v, v+=a, a+=g+y.		Horizontal: s=sgn(a)*a^2+v, v+=a, a+=y.
//Feintuning: Betrag von s reduzieren über: 1 Schritt gehen und von |s| abziehen, wenn sgn(v)!=sgn(y-g)!=sgn(a), dann |v|-1 bzw. |a|-1 am Ende, und |y|>|a|: |s|-|y-a| , wenn |s| null erreicht immer aufhören
//Schrittweite = 1, s_ges = Abstand zur Grundlinie; Wenn a oder v =0 --> |a| = |v|, wenn beide null vorzeichenlos
//s=10: 10	10	9	4	6	9	10	10														s=10:	10	10	9	4	8	4	3	3	3	2	3	7	3
//v= 0:	0	0	-1	-3	-6	-3	-1	0	<--leer	,freier Fall,	1 Hindernis auf Grund-->	v= 0:	0	0	-1	-3	-3	-4	-4	-3	-3	-2	-3	-4	-4		für 1.
//a= 0:	0	-1	-2	-3	3	2	1	0														a= 0:	0	-1	-2	-3	-1	-2	0	-1	0	-1	-3	0	-1
//Nimm 2.Geschwindigkeit

//Write a timeline: Which options and actions happen when and what they do, according to their time? go on

// undead (option), done
// no return into dead, but into undead squares for a period of time,
// undead squares just reserve the place

// sand (gamemode), done
// reach the top, after development: Every square falls down one square,
// if there is a dead square under.

// allocation (option), done
// you can own a square more than once, lose it with the difference of parameters,
// limited to an amount

// figures (option), done
// activate movements by building special figures.

// cards (option), done
// get numbers as cards every round, choose one to play.

// inverse (option), done
// after turn: look at smallest rectangle containing the organism
// and invertate dead and owned squares

// numbers (gamemode), go on
// try to own the requested number of squares for getting a point.
// (numbers= squares and primes<20)
// Start with 13, end with 2 and 1 and 0.

// matrix [multiplication] (option), frozen
// take the field as a matrix, multiply it with itself (or with A € Z^mxm/Z^nxn)

// Addition (option), done
// if players touch each other, the player-numbers will be count together and %(number_of_players+1)
// local/global, only global

// projections (option), done
// after (number_of_players+1) turns, look at lines (Vertikal/Horizontal) and project parallel lines to it.
// Loss of intesity per line in percent, requested minimum? 0<L<1 given in per cent.

// labyrinth (gamemode), frozen
// try to reach the mid, but there are walls in the center (3 lines from endings are free)
// the walls can move after a period of turns.

// assassin (option), done
// a lonely square is going to kill all players in his whole surrounding, mentioned by Arne.

// shadow (gamemode), go on
// build new fields by reducing/increasing the lengths by 1.

// shadow (option), frozen
// build new fields by reducing/increasing the lengths by 1.

// avalanche (option), done
// the squares change positions like in a change until the active player cannot get nearer to the center.

// avalanche (gamemode), frozen
// the squares change positions like in a change until the active player cannot get nearer to the center.

// spreading (option), go on
// touching the wall causes a line of owned squares along the wall until there is an other living square or the end.

// Imitation (option), go on
// Every square of the enemies is shown as own square, except until the distance x from the edge.

// Laser-competition (gamemode), go on
// Two teams against each other: mod2==1 is like elementary waves, mod2==0 as solid, touch all edges/stop the laser.

// Goliath (and David) (gamemode), go on
// it is like throwing stones on pumping stations

// invisible (option), go on
// cannot see anything of the enemies

// roses (option), go on
// if there are too many in the surrounding and a square dies, a rose is born an will rise up every time a square is dying in its surrounding the same way (according to the difference to the maximum)

// Ptunoi (gamemode), go on
// Possible to understand nothing of it.
// every player gets 2 attack-figures and one defensive figure. Almost each attack can get countered (50:50). The figures are grouped, only one attack and one defend played per player per round, counters are defending.
// P = Possible but not own, Z = dead, X = owend square, x = own square who died, D = Defending enemy square, O = dead square, Y = dead-line until the wall is coming
// Candle:	PPP	ZZZ	DDD	Scissors:	PXO	ZXO	DDO	Vulcano:	PPP	PYP	DDD	Sacrifice:	PPP	ZZZ	PDP	Duplicity:	OXO	XOX	Sphäre: OOO	OXO	Cut:	OXX	YXX	Explosion:	XXX	XxX
//			PXP	ZXZ	PXP				XXO	XXO	DDx				XXX	XXX	XxX				PXP	ZZZ	DxD				OXO	XOX			XXX	XOX			XOX	XYX				XOX	xYx
//      	XXX	XXX	XXX				OOX	OOX	OxX				XOX	XOX	XOX				PPP	ZZZ	PDP								OOO	OXO			XXO	XXY				XXX	XxX
//
// Rocket:	OXX	OXX	OXX		The rest of it is written on paper
//			XOX	XYX	xOX
//			PXO	YXO	DxO

// KI for Contact, ... go on
// Make Yasmin faster, not possible

// Quidditch (gamemode), go on
// Well, just Quidditch.

// Donation (gamemode), go on
// spend squares for your team, counting 1/x if you have x squares in this situation. Spend before or after, but not both except at least one of it is teamless. Team 2 and team 3 neighbours. Fill space with teamless 1 and 0 donations.

// Genimo_ve_flagrate (gamemode), go on
// touching an object will let it evolve like one step of a wave, possible to destroy it accross. Reach the mid. Difficulty handle through number of objects in each quarter.

// partition (option), go on
// every square gets a number, if you get a new square, it has to have another number then all near-by squares at this time.

// Supernova (gamemode), go on
// avoid the blackholes flying accross the field caused by gravity and pulling your squares and so on. Mass of square: 1. Mass of blackholes: 5. Fusion with blackhole(): Mass-Addition. timestep t = 1. Destroy on blackholes: reduce the mass with 1. Count all impacts and use it for new accelaration, add this value to the speed (t=1). After every round a timestep. Sort (binary) the speed according to length (sqrt(x*x+y*y)), most speed at first. Collosion: half of speed-difference plus and minus, after that next square with highest speed.


#endif
