
#ifndef GROWTH_ALL_DEF_H
#define GROWTH_ALL_DEF_H

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

extern unsigned int letters_4;
extern unsigned int letters_2;

extern unsigned int AOP;

extern unsigned int Liz_max;
extern unsigned int anything; //Die Variable für alles Mögliche

time_t time_of_the_start;

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
	// used field numbers: 1,2,3,4,5,6,7,8,9,10,11,15,16,17,20,30,40,50,60,70,71,74,75,77,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,101,102,103,104,105,106,110,111,112,113,114,115,116,202,303,404,505,606,707,808,909

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
	
	Roses_0 = 110,
	Roses_1 = 111,
	Roses_2 = 112,
	Roses_3 = 113,
	Roses_4 = 114,
	Roses_5 = 115,
	Roses_6 = 116,
	
	//undead = n*10000,
	
};

enum show_field_lines {
	number_edge_line = 1,
	frame_lines = 2,
	square_containing_beginning = 3,
	square_containing_ending = 4,
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
enum gamemode {		//checklist
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
	Quidditch = 14,
	Duell = 15,	//go on
	
	
	Invalid = 16, //CHANGE
};

enum moveable_objects_directions {	//Quidditch: Klatscher, Quaffel

	standing = 0,		//no movement
	top = 1,			//top
	top_right = 2,		//top&right
	right = 3,			//right
	right_bottom = 4,	//right&bottom
	bottom = 5,			//bottom
	bottom_left = 6,	//bottom&left
	left = 7,			//left
	left_top = 8,		//left&top
	
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
	oSpreading = 20,
	oInvisible = 21,
	oRoses = 22,
	oPartition = 23,

	oBack = 26,		//synchronisiere mit oBack, tivialerweise! Last value +3

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
	unsigned int Jaeger_fly_distance;		//normal: 5
	unsigned int Jaeger_throw_distance;		//normal: 5
	unsigned int Hueter_fly_distance;		//normal: 4
	unsigned int Hueter_throw_distance;		//normal: 5
	unsigned int Treiber_fly_distance;		//normal: 5
	unsigned int Treiber_hit_distance;		//normal: 5
	unsigned int Sucher_fly_distance;		//normal: 5
} Quidditch_team_abilities;

typedef struct Quidditch_object_abilities_t {	//Qoa
	unsigned int Klatscher_fly_distance;		//normal: 4
	unsigned int Schnatz_fly_distance;			//normal: 6
	unsigned int Schnatz_appearence_factor;		//normal: 25	(to read as 2/5, necessary to get 2 letters)
	unsigned int Schnatz_disappearence_factor;	//normal: 12	(to read as 1/2, necessary to get 2 letters)	(except a Sucher is in its surrounding, frozen);
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

typedef struct Special_Fields_Collector_t {	//allocation, partition
	Special_Fields Allocation_o;
	Special_Fields Partition_o;
} Special_Fields_Collector;

typedef struct Limits_t {	//square-limits
	unsigned int yeni;
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

typedef struct Single_option_representives_t {
	unsigned int undead_duration;
	unsigned int inverted;
	unsigned int addition;
	unsigned int intensity_loss_per_line_multiplication;
	unsigned int spreading;
	unsigned int invisible;
} Single_option_representives;

typedef struct Time_matters_t {
	unsigned int ttt;
	unsigned int warning_system;
} Time_matters;

typedef struct Realize_modifications_variables_t {	//all variables used for normal options
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


unsigned int Fakultaet (unsigned int);

unsigned int Vorganger (unsigned int, unsigned int);
unsigned int Nachfolger (unsigned int, unsigned int);


void ges_counter (Spielfeld, unsigned int, unsigned int, unsigned int*, unsigned int);
void who_is_out (unsigned int*, unsigned int, Realize_modifications_variables*);
void reset_of_ges (unsigned int*, unsigned int);


unsigned int Zufall (unsigned int, unsigned int);


void neue_Zeilen (unsigned int);
void neue_Leerzeichen (unsigned int);
void neue_Tabs (unsigned int);


#endif