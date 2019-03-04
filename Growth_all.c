#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <windows.h>
#include <ctype.h>

// anscheinend kehren die gestorbenen zurück in das Standartspiel bei gamemode_played 6 (aktuell ?)

typedef unsigned int*** Spielfeld;	//Spielfeld ist kubisch

Spielfeld Spielfeld_Create (unsigned int, unsigned int, unsigned int);		//mxn, m >= 6 (+2), n gerade, n >= 4 (+2)		Original: m = 10 (+2), n = 6 (+2)

void start_normal (Spielfeld, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, Spielfeld, Spielfeld, unsigned int, unsigned int);

unsigned int* unsigned_int_Vektor_Create (unsigned int);
int* int_Vektor_Create (unsigned int);
int** int_2dim_Vektor_Create (unsigned int, unsigned int);

void new_life (Spielfeld, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int*, unsigned int, Spielfeld, Spielfeld, Spielfeld, Spielfeld, unsigned int, unsigned int);
void old_dying (Spielfeld, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int*, unsigned int, Spielfeld, unsigned int, Spielfeld, unsigned int, Spielfeld, unsigned int);
void change (Spielfeld, Spielfeld, Spielfeld, Spielfeld, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int*, unsigned int, unsigned int, Spielfeld, unsigned int, Spielfeld, unsigned int*, unsigned int*, unsigned int);

void show_field (Spielfeld, Spielfeld, Spielfeld, unsigned int, unsigned int, unsigned int, unsigned int*, unsigned int, unsigned int*, unsigned int, Spielfeld, unsigned int);
void show_whose_turn (unsigned int, unsigned int, unsigned int*, unsigned int*);
void show_statistics (unsigned int, unsigned int, Spielfeld, unsigned int*, unsigned int, unsigned int*, unsigned int*, unsigned int*, unsigned int*, unsigned int);
void show_options_of_actions (unsigned int, unsigned int*, unsigned int);
void show_the_numbers (unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
void show_figures ();
void show_abilities (unsigned int*);

unsigned int Vorganger (unsigned int, unsigned int);
unsigned int Nachfolger (unsigned int, unsigned int);

void figure_check (Spielfeld, unsigned int, unsigned int, unsigned int, unsigned int*, Spielfeld, unsigned int, Spielfeld, unsigned int);

void Spielfeld_Destroy (Spielfeld, unsigned int, unsigned int);
void unsigned_int_Vektor_Destroy (unsigned int*);
void int_Vektor_Destroy (int*);
void int_2dim_Vektor_Destroy (int**, unsigned int);

void Plus (Spielfeld, unsigned int, unsigned int, unsigned int, Spielfeld, unsigned int, unsigned int, unsigned int*, unsigned int, unsigned int*, unsigned int, Spielfeld, Spielfeld, unsigned int);
void Minus (Spielfeld, unsigned int, unsigned int, unsigned int, Spielfeld, unsigned int, unsigned int*, unsigned int*, unsigned int, Spielfeld, Spielfeld, unsigned int, unsigned int);
void Move (Spielfeld, unsigned int, unsigned int, unsigned int, Spielfeld, unsigned int, unsigned int*, unsigned int*, unsigned int, Spielfeld, Spielfeld, unsigned int, unsigned int);
void Change (Spielfeld, unsigned int, unsigned int, unsigned int, Spielfeld, unsigned int, unsigned int*, unsigned int*, unsigned int, Spielfeld, unsigned int*, Spielfeld, unsigned int, unsigned int);
void Destroy (Spielfeld, unsigned int, unsigned int, unsigned int, Spielfeld, unsigned int, unsigned int*, unsigned int*, unsigned int, Spielfeld, Spielfeld, unsigned int, unsigned int);
void Revive (unsigned int, unsigned int, Spielfeld, Spielfeld, unsigned int, Spielfeld, unsigned int, Spielfeld, unsigned int);

void Boost (unsigned int, Spielfeld, unsigned int, unsigned int, Spielfeld, unsigned int, Spielfeld, Spielfeld, unsigned int, unsigned int);

void Initialisierung (unsigned int, unsigned int*);
unsigned int Initialisierung_limit_at_all (unsigned int);
unsigned int Initialisierung_limit_new (unsigned int);
unsigned int Initialisierung_m (unsigned int);
unsigned int Initialisierung_n (unsigned int);
void unsigned_int_array_null_initialisierung (unsigned int*, unsigned int);
void int_array_null_initialisierung (int*, unsigned int);

void About_the_game (unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
void get_hints (Spielfeld, unsigned int, Spielfeld, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int*, Spielfeld, unsigned int, unsigned int*, unsigned int, Spielfeld, unsigned int, unsigned int);
unsigned int get_m (unsigned int, unsigned int, unsigned int);
unsigned int get_n (unsigned int, unsigned int, unsigned int);
unsigned int get_unsigned_numeric_input_with_not_more_than_3_letters ();
unsigned int get_unsigned_numeric_input_with_not_more_than_2_letters ();
unsigned int split_unsigned_numeric_input_with_letters_4 (unsigned int, unsigned int);
unsigned int get_unsigned_numeric_input_with_not_more_than_1_letter ();
unsigned int get_unsigned_numeric_input_with_not_more_than_letters_4_for_splitting ();
unsigned int split_unsigned_numeric_input_with_letters_2 (unsigned int, unsigned int);
unsigned int get_unsigned_numeric_input_with_not_more_than_letters_2_for_splitting ();
int get_signed_numeric_input_with_not_more_than_1_letter ();
void get_colors (unsigned int*, unsigned int, unsigned int, unsigned int);
void get_two_amounts_for_permutations (unsigned int*, unsigned int*, unsigned int, unsigned int, unsigned int, unsigned int);

void choose_your_ability (unsigned int, unsigned int*, unsigned int*);
unsigned int dynamic_take_out (unsigned int*, unsigned int, Spielfeld, unsigned int*, unsigned int, unsigned int, unsigned int, Spielfeld, Spielfeld, unsigned int, unsigned int);
unsigned int who_is_out (unsigned int*, unsigned int, unsigned int);

void set_Spielfeld_Eintrag (Spielfeld, unsigned int, Spielfeld, unsigned int, Spielfeld, unsigned int, unsigned int, Spielfeld, unsigned int, unsigned int, unsigned int, unsigned int);
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

void Index (unsigned int, unsigned int, unsigned int, unsigned int, Spielfeld, Spielfeld, unsigned int, unsigned int, unsigned int, Spielfeld, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int*, unsigned int, unsigned int, unsigned int, Spielfeld, Spielfeld, unsigned int);

void inverted_organism (Spielfeld, Spielfeld, unsigned int, Spielfeld, unsigned int, Spielfeld, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int*, unsigned int*);

void opague_builder (Spielfeld, Spielfeld, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, Spielfeld, unsigned int, unsigned int);

unsigned int random_number (unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int*, unsigned int*);

void battle (unsigned int, unsigned int, Spielfeld, unsigned int, Spielfeld, Spielfeld, unsigned int, unsigned int);
unsigned int chain_count (unsigned int, unsigned int, Spielfeld, Spielfeld, unsigned int, unsigned int, unsigned int, Spielfeld, Spielfeld, unsigned int, unsigned int);

void touch (Spielfeld, unsigned int, unsigned int, unsigned int, Spielfeld, Spielfeld, unsigned int, Spielfeld, unsigned int);

void addition_maker (Spielfeld, unsigned int, unsigned int, unsigned int, unsigned int, Spielfeld, unsigned int, Spielfeld, unsigned int, unsigned int*);
void projection_maker (Spielfeld, unsigned int, unsigned int, Spielfeld, unsigned int, Spielfeld, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
void assassin_maker (Spielfeld, Spielfeld, unsigned int, Spielfeld, unsigned int, Spielfeld, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int*, unsigned int*);

void ahead (Spielfeld, unsigned int, unsigned int, Spielfeld, unsigned int, Spielfeld, unsigned int, unsigned int);

void choose_heart (Spielfeld, unsigned int, unsigned int, unsigned int, Spielfeld, Spielfeld, unsigned int, unsigned int);
void heart_ground (unsigned int, unsigned int, Spielfeld, Spielfeld, unsigned int, Spielfeld, Spielfeld, unsigned int, unsigned int);

int sgn (int);
void Reflection (int*, unsigned int, int);
void impact_y_semi_square (unsigned int, unsigned int, unsigned int*, unsigned int, unsigned int, int*, Spielfeld);	// unsigned int** wird zu Spielfeld

void translate_permutations_amounts_to_permutations_areas (Spielfeld, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, Spielfeld, Spielfeld);

unsigned int letters_4;
unsigned int letters_2;

int Vektor_counter;
int Spielfeld_counter;

enum directions {	//projection
	
	Horizontal	= 0,
	Vertikal 	= 1,
	Changing = 2,
	
	undefined = 3,	//undefined immer als letzter Wert
	
} direction;

enum where_to_go {	//Permutations
	
	to_the_right = 0,
	to_the_bottom = 1,
	to_the_left = 2,
	to_the_top = 3,
	
	more_undefined = 4,	//more_undefined immer als letzter Wert
	
} nereye_gitmeliyiz;

enum survive_objects {	//survive
	
	Waves		= 75,
	Waves_new	= 74,
	
	Traps 		= 71,
	
	Bomb_4		= 84,
	Bomb_3		= 83,
	Bomb_2		= 82,
	Bomb_1		= 81,
	
};

enum ulcer_start_values {	//ulcer
	
	missing = 0,
	existing = 1,
};

enum gamemode {
	nothing	= 0,
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
} gamemode_played;

enum options {
	
	Start 	= 1,
	Size	= 2,
	Journey	= 3,
	Tactics	= 4,
	Random	= 5,
	Limits	= 6,
	Time	= 7,
	Color	= 8,
	Opague	= 9,
	undead	= 10,
	Figures	= 11,
	Allocation = 12,
	Cards = 13,
	Inverted = 14,
	Addition = 15,
	Projection = 16,
	Assassin = 17,
	Permutations = 18,
	
	back = 19,		//synchronisiere mit back, tivialerweise!
} beginningmenu;	//"historical" definition

int main (void) {
	
	unsigned int pause; //Fehlersuche
	
	pause = 0;
	
	//printf ("	ok 1 \n");	//test
	
	//Spielfeld test_;	//test
	
	//printf ("	ok 1.1 \n");	//test
	
	Spielfeld numbers_of_, stack_of_;	//ruck muss raus, done, numbers_of_==statistics, numbers_of_[geben][0]==Matchballs etc., stack_of_==stack of tac
	Spielfeld Field, Field_journey;	//cons_field in Field, cons_journey in Field_journey, Field[0]==Das Spielfeld, Field_journey[0]==Das Journeyfeld
	Spielfeld Sf_nl_, Sf_od_;
	Spielfeld Sf_opague, Sf_allocation;	//Sf_opague[0]==Opague-Spielfeld,
	Spielfeld Sf_permutations, Collector_of_permutation_number_c_areas, Collector_of_permutation_number_b_areas;	//Permutations
	
	enum options beginningmenu;
	enum gamemode gamemode_played;
	unsigned int m, n;	//Höhe, Breite
	unsigned int number_of_players, geben;	//spielende Spieler, aktiver Spieler
	unsigned int count_new, ent, zeitgewinner, limit_new, limit_at_all, limit_at_all_saver;	//Index and limits
	unsigned int lim; //Die Variable für alles mögliche
	unsigned int fall_controll, fall_back, turns_per_drop, speed_of_fall, points_for_win, einmal;	//Gamemode = Fall, "einmal" als Bezeichnung auch in einer Funktion
	unsigned int count_freq, freq;	//Gamemode = Race
	unsigned int rain, rain_drops, rain_save, rain_obj, rain_speed, rain_speed_save, number_rain;	//Gamemode = Rain
	unsigned int w, d, e;	//Entwicklungsparameter
	unsigned int menuoperator, playtime;	//Navigationsparameter
	unsigned int opt, use_number, num_1, num_2, num_3, num_temp, tac, cards, controll_1, controll_2;	//How to get the numbers, and to controll them
	unsigned int suprise, sup_num;	//specialeffects
	unsigned int figures, allocation, iteration, journey, undead_duration, opague, inverted, addition, assassin;	//options, selected with beginningmenu
	unsigned int rtc, spf, scwhp, hboa, boost_hunt_activator, precounter;	//Spezieller Boost für the hunted one in gamemode Hunt
	unsigned int nosv, AOP;		//number of saved variables; amount of players
	unsigned int range, d_wert, indikator1, indikator2, indikator3, space_i, space_j, controll;		//Gamemode = Dynamic
	//unsigned int cons[1]_fort, cons[2]_fort, cons[3]_fort, cons[4]_fort, cons[5]_fort, cons[6]_fort, cons[7]_fort, cons[8]_fort, cons[9]_fort;
	
	//sort the variables, done
	
	//scanf("%u", &pause); //test
	//printf ("	ok 2 \n");	//test
	
	unsigned int round_counter, round_counter_before;	//Rundenanzahl und ihre Sicherung
	unsigned int ttt, warning_system, all_turns_correction;		//time-to-think, Verstöße bestrafen, die Züge an die aktuelle Spieleranzahl anpassen
	unsigned int exclude_counter, player_counter, rtp, information_code[4];	//rounds-to-play, 0 == rtc, 1 == spf, 2 == hboa, 3 == scwhp (gamemode_played == Hunt)
	unsigned int* same;	//immer aktualisieren
	unsigned int* position;		// "*" bezieht sich auf "position", nicht auf "unsigned int" !!!!
	int erd;	//erdbeschleunigung
	int* dynamic_pointer;	//Dynamic direction
	int** dynamic_pointer_save;	//saved Dynamic direction
	unsigned int intensity_minimum, intensity_loss_per_line_multiplication;	//option: projection
	unsigned int amount_of_permutation_number_b, amount_of_permutation_number_c, permutation_number_b, permutation_number_c;	//option: permutations
	
	AOP = 9;	//Amount Of Players, needed so early - look at the following lines
	
	unsigned int ges[AOP+1], var_[AOP+1], cons[AOP+1], number_[AOP+1];	//ges==How much squares do you have, var_==your choice, cons==saved numbers,
	//unsigned int same_counter;
	
	//same: 0, m, n, journey, tac, gamemode_played, fall_controll, turns_per_drop, speed_of_fall, count_freq, rain, rain_drops, rain_obj, rain_speed,	//14
	//		opt, limit_new, limit_at_all, points_for_win, freq, use_number,	//6
	//		number_of_players, rtc, spf, scwhp, hboa, ttt, warning_system, exclude_counter, rtp, information_code[4], ability[10], Colored[10], ulcer_lifes[10] ohne [0]	//42
	
	double time_saver, time_warning;
	
	time_t time1, time2, time3, time4;
	
	unsigned int* Points;		//undecided, 1, 2
	
	unsigned int pere[AOP+1], ability[AOP+1], Colored[AOP+1], ulcer_start[AOP+1], ulcer_lifes[AOP+1], out_counter[AOP+1];		//pere==penalty-reminder, ulcer_start==Are you on the field, out_counter== Are you out of play
	
	//gamemode_played == Hunt, geben == 1: information_code: [0]=0, [1]=1, [2]=1, [3]=0
	
	//Benutzbar, aber benutzt:	unsigned int: lim, suprise, 
	//Benutzbar, und unbenutzt:	unsigned int: 	(cons[0]?)		int (in int-Vektor): dynamic_pointer_save[p][0] (p=0,1,2,3)
	// used field numbers: 1,2,3,4,5,6,7,8,9,10,11,15,16,17,20,30,40,50,60,70,71,74,75,77,80,81,82,83,84,90,101,202,303,404,505,606,707,808,909
	// used unusually ges numbers 1010,2020,3030,4040,5050,6060,7070,8080,9090
	// 10, 20, 30, 40, 50, 60, 70, 80, 90 ausschließlich im Spielfeldrand
	//used Field[0]: (1,0), (0,0), (0,1), (0,n-1), (m-1,n-1), (m-1,0)
	// >=10000 nur bei undead, sonst muss undead_duration der show_field mitgegeben werden.
	
	Vektor_counter = 0;
	Spielfeld_counter = 0;
	
	playtime = 1;	//playing game after game after...
	
	nosv = 82;	//Number_of_saved_variables, drücke abhängig von AOP aus, go on
	//same_counter = 0; 		//for variable length of same
	
	same = unsigned_int_Vektor_Create (nosv);
	
	/*
	cons_fort[1] = 0;
	cons_fort[2] = 0;
	cons_fort[3] = 0;
	cons_fort[4] = 0;
	cons_fort[5] = 0;
	cons_fort[6] = 0;
	cons_fort[7] = 0;
	cons_fort[8] = 0;
	cons_fort[9] = 0;
	*/
	
	//scanf("%u", &pause); //test
	//printf("%u \n", same[0]);	//test
	//printf ("	ok 3 \n");	//test
	
	while (playtime != 0){		// Außenschleife für mehrere Spiele hintereinander
		
		//scanf("%u", &pause); //test
		//printf ("	ok 3.1 \n");	//test
		
		Points = unsigned_int_Vektor_Create (3);	//possible to modify
		
		dynamic_pointer = int_Vektor_Create (8);
		
		position = unsigned_int_Vektor_Create (2);
		
		//scanf("%u", &pause); //test
		//printf ("	ok 4 \n");	//test
		
		//playtime should start here, done
		
		number_of_players = 2;	//normally
		
		//scanf("%u", &pause); //test
		//printf ("	ok 5 \n");	//test
		
		m = 0;	//
		n = 0;	//
		
		letters_4 = 0;
		letters_2 = 0;
		
		rain_speed = 1;		//Rain
		rain_speed_save = 0;
		rain_obj = 0;
		rain = 1;		//Push
		rain_drops = 1;
		rain_save = 0;
		
		freq = 6;	//Race
		
		figures = 0;	//options
		undead_duration = 0;
		allocation = 0;
		inverted = 0;
		addition = 0;
		assassin = 0;
		
		fall_back = 0;		//Fall
		fall_controll = 0;
		points_for_win = 3;
		turns_per_drop = 3;
		speed_of_fall = 1;
		
		iteration = 0;		//eine Iteration-Option, go on
		controll = 0;
		
		space_i = 0;
		space_j = 0;
		indikator1 = 0;		//für horizontal
		indikator2 = 0;		//für vertikal
		indikator3 = 0;
		
		d_wert = 1;
		
		range = 1;	//Dynamic parameter
		erd = 1;
		
		intensity_minimum = 0;	//projection
		intensity_loss_per_line_multiplication = 0;
		direction = undefined;
		
		amount_of_permutation_number_b = 0;	//permutations
		amount_of_permutation_number_c = 0;
		permutation_number_b = 0;
		permutation_number_c = 0;
		
		//scanf("%u", &pause); //test
		//printf ("	ok 5.1 \n");	//test
		
		lim = 0;
		opt = 0;
		cards = 0;
		tac = 0;
		journey = 0;
		
		all_turns_correction = 0;	//for mechanisms based on turns of the players, if a player is out
		
		ent = 0;
		num_temp = 0;
		limit_new = 0;		//if
		limit_at_all = 0;		//if
		
		w = 3;	//most important parameters
		d = 2;
		e = 3;
		
		sup_num = 0;
		use_number = 1;
		
		beginningmenu = back;	//auch hier
		gamemode_played = 0;
		menuoperator = 0;
		suprise = 0;
		
		scwhp = 1;
		spf = 5;
		rtc = 30;
		round_counter = 0;
		round_counter_before = 0;
		
		hboa = 1;
		precounter = 0;
		
		ttt = 0;	//time
		time_warning = 0.0;
		time_saver = 0.0;
		warning_system = 0;
		
		exclude_counter = 0;
		
		player_counter = 0;
		rtp = 30;
		limit_at_all_saver = 0;
		
		opague = 0;
		
		//scanf("%u", &pause); //test
		//printf ("	ok 5.2 \n");	//test
		
		//scanf("%u", &pause); //test
		//printf ("	ok 5.3 \n");	//test
		
		unsigned_int_array_null_initialisierung (information_code, 3);
		
		//scanf("%u", &pause); //test
		//printf ("	ok 5.4 \n");	//test
		
		position[Horizontal] = 0;
		position[Vertikal] = 0;
		
		//int_array_null_initialisierung (dynamic_pointer, 7);	//already null
		
		//[0] = s_horizontal
		//[1] = s_vertikal
		
		//[2] = v_horizontal
		//[3] = v_vertikal
		
		//[4] = a_horizontal
		//[5] = a_vertikal
		
		//[6] = y_horizontal
		//[7] = y_vertikal
		
		for (unsigned int p=0; p<=AOP; p+=1) {
			pere[p] = 0;
			ability[p] = 0;
			Colored[p] = 0;
			ulcer_start[p] = missing;
			// printf("ulcer_start[%u] = %u \n", p, ulcer_start[p]);	//test
			ulcer_lifes[p] = 0;
			out_counter[p] = 0;
			ges[p] = 0;
			var_[p] = 0;
			cons[p] = 0;
			number_[p] = 0;
			if (p!=0) {
				ulcer_lifes[p] = p-1;
			}
		}
		
		ulcer_start[1] = existing;
		// printf("ulcer_start[1] = %u \n", ulcer_start[1]);	//test
		
		//scanf("%u", &pause); //test
		//printf ("	ok 5.5 \n");	//test
		
		if (same[0] == 0) {
			
			//Startmenü, Anfang
			
			if (playtime != 10) {
				printf("\n");
				printf("	Welcome to >Growth<. Have a nice game. \n");
				printf("\n");
			}
			
			//scanf("%u", &pause); //test
			//printf ("	ok 6 \n");	//test
			
			while (beginningmenu == back) {
				
				// scanf("%u", &pause); //test
				// printf ("	ok 7 \n");	//test
				while ((gamemode_played < 1) || (gamemode_played > 13)) {
					
					printf("	Choose your gamemode\n  \n");

					// enum: gamemode_played[done], (traps, bombs, waves, done), in menu (about the game, limits, hints, numbers), beginningmenu done 	//go on
					
					printf("	Classic: 1\n	Collect: 2\n	Contact: 3\n	Fall   : 4\n	Fight  : 5\n	Hunt   : 6\n	Race   : 7\n	Rain   : 8\n	Arena  : 9\n  	Ulcer  : 10\n   	Dynamic: 11\n   	Survive: 12\n   	Sand   : 13\n  \n");	//mehr-gamemode_played
					gamemode_played = get_unsigned_numeric_input_with_not_more_than_2_letters ();
					printf("\n");
					//Players?
				}
				
				Initialisierung (gamemode_played, information_code);
				limit_at_all = Initialisierung_limit_at_all (gamemode_played);
				limit_new = Initialisierung_limit_new (gamemode_played);
				m = Initialisierung_m (gamemode_played);
				n = Initialisierung_n (gamemode_played);
				
				while (beginningmenu != Start){
			
					printf("	Start game  : 1\n \n	Game size   : 2\n	Journey     : 3\n	Tactics     : 4\n	Random      : 5\n	Limits      : 6\n 	Time	    : 7\n 	Color	    : 8\n 	Opague	    : 9\n	undead	    : 10\n	Figures	    : 11\n 	Allocation  : 12\n 	Cards	    : 13\n 	Inverted    : 14\n 	Addition    : 15\n  	Projection  : 16\n   	Assassin    : 17\n   	Permutations: 18\n  \n	Back        : %u\n \n", back);	//synchronisiere stets back mit beginningmenu
					if (gamemode_played == Fall) {
						printf("	Points for win  : %u \n", back+1);
						printf("	Turns per drop  : %u \n", back+2);
						printf("	Speed of the #-square: %u \n", back+3);
					} else if (gamemode_played == Hunt) {
						printf("	Hunt-conditions: %u \n", back+1);
						printf("	Number of players: %u \n", back+2);	// synchronisiere diese ebenfalls
					} else if (gamemode_played == Race) {
						printf("	Frequence : %u \n", back+1);
					} else if (gamemode_played == Rain) {
						printf("	Rain-Modus: %u \n", back+1);
					} else if (gamemode_played == Arena) {
						printf("	Abilities : %u \n", back+1);
						printf("	Number of players: %u \n", back+2);
						printf("	Rounds to play	 : %u \n", back+3);
					} else if (gamemode_played == Ulcer) {
						printf("	Lifes	  : %u \n", back+1);
						printf("	Number of players: %u \n", back+2);
						printf("	Rounds to play	 : %u \n", back+3);
						printf("	K.O.-Mode : %u \n", back+4);
					} else if (gamemode_played == Dynamic) {
						printf("	Gravity	  : %u \n", back+1);
						printf("	Number of players: %u \n", back+2);
						printf("	Range	  : %u \n", back+3);
						printf("	Coefficient : %u \n", back+4);
					} else if (gamemode_played == Survive) {
						printf("	obstacles : %u \n", back+1);
						printf("	Number of players: %u \n", back+2);
					} else if (gamemode_played == Sand) {
						printf("	Gravity	  : %u \n", back+1);
						printf("	Number of players: %u \n", back+2);
						printf("	Speed	  : %u \n", back+3);
						printf("	Period	  : %u \n", back+4);
					}
					
					printf("\n");
					beginningmenu = get_unsigned_numeric_input_with_not_more_than_2_letters ();
					printf("\n");
				
					if (beginningmenu == Start){
						printf("	Let's start! \n");
					}
				
					if (beginningmenu == Size){
						if ((gamemode_played == Hunt)||(gamemode_played == Arena)||(gamemode_played == Ulcer)||(gamemode_played == Dynamic)||(gamemode_played == Survive)) {
							printf("	This only works if the number of players is correct! \n");
						}
						
						m = get_m (gamemode_played, number_of_players, AOP);
						n = get_n (gamemode_played, number_of_players, AOP);
						
					}
				
					if (beginningmenu == Journey){
						if (journey == 1){
							journey = 0;
							printf("	journey deactivated \n");
						} else if (journey == 0){
							journey = 1;
							printf("	journey activated \n");
						}
						printf("\n");
					}
					
					if (beginningmenu == Tactics){
						opt = 0;
						cards = 0;
						
						if (tac != 0) {
							printf("	Tactics-mode reseted! \n");
							printf(" \n");
							tac = 0;
						} else {
							printf("	Do not activate Random or Cards, it will replace the Tactics-Mode! \n");
							printf("	Stack of every number until refresh: \n");
							tac = get_unsigned_numeric_input_with_not_more_than_2_letters ();
							printf("\n");
						}
					}
					
					if ((beginningmenu == Random)&&(gamemode_played != Hunt)&&(gamemode_played != Arena)&&(gamemode_played != Ulcer)&(gamemode_played != Dynamic)&(gamemode_played != Survive)){
						tac = 0;
						cards = 0;
						
						if (opt != 0) {
							printf("	Random-mode reseted! \n");
							printf(" \n");
							opt = 0;
						} else {
						
							printf("	Do not activate Tactics or Cards, it will replace the Random-Mode! \n");
							printf("	Random activated \n");
							printf("	A Player :	Give me three random numbers from 1 to 60 \n");
							number_[1] = get_unsigned_numeric_input_with_not_more_than_2_letters ();
							number_[2] = get_unsigned_numeric_input_with_not_more_than_2_letters ();
							number_[3] = get_unsigned_numeric_input_with_not_more_than_2_letters ();
							printf("\n");
							if ((number_[1]==0)||(number_[2]==0)||(number_[3]==0)||(number_[1]>60)||(number_[2]>60)||(number_[3]>60)){
								printf("	You missed the assertion(s) !!! \n");
								printf("\n");
								beginningmenu = 0;
							} else {
								printf("\n");
								printf("	The other Player :	Give me a random number from 1 to 60 \n");
								number_[4] = get_unsigned_numeric_input_with_not_more_than_2_letters ();
								printf("\n");
								if ((number_[4]<1)||(number_[4]>60)){
									printf("	You missed the assertion(s) !!! \n");
									printf("\n");
									beginningmenu = 0;
								} else {
									number_[4] = ((number_[4]%6)+1)%3 + 1;
									if (number_[4] == 1){
										num_temp = (number_[1] % 2)+(number_[2] % 3)+2*(number_[3] % 3);
										if (num_temp <= 1){
											use_number = 1;
										} else if (num_temp >= 6){
											use_number = 6;
										} else {
											use_number = num_temp;
										}
									}
									if (number_[4] == 2){
										num_temp = (number_[2] % 2)+(number_[1] % 3)+2*(number_[3] % 3);
										if (num_temp <= 1){
											use_number = 1;
										} else if (num_temp >= 6){
											use_number = 6;
										} else {
											use_number = num_temp;
										}
									}
									if (number_[4] == 3){
										num_temp = (number_[3] % 2)+(number_[1] % 3)+2*(number_[2] % 3);
										if (num_temp <= 1){
											use_number = 1;
										} else if (num_temp >= 6){
											use_number = 6;
										} else {
											use_number = num_temp;
										}
									}
								
									opt = 5;
								}
							}
						}
						
					} else if ((beginningmenu == Random)&&((gamemode_played == Hunt)||(gamemode_played == Arena)||(gamemode_played == Ulcer)||(gamemode_played == Dynamic)||(gamemode_played == Survive))) {
						tac = 0;
						cards = 0;
						
						if (opt != 0) {
							printf("	Random-mode reseted! \n");
							printf(" \n");
							opt = 0;
						} else {
							printf("	Do not activate Tactics or Cards, it will replace the Random-Mode! \n");
							printf("	This only works if the number of players is correct! \n");
							
							printf("	Random activated \n");
							printf("	Please get all a number from 0 to %u, not the same, it will have no effect further on. \n", number_of_players-1);
							printf("	Give me three random numbers from 1 to 60 \n");
							number_[1] = get_unsigned_numeric_input_with_not_more_than_2_letters ();
							number_[2] = get_unsigned_numeric_input_with_not_more_than_2_letters ();
							number_[3] = get_unsigned_numeric_input_with_not_more_than_2_letters ();
							if ((number_[1]==0)||(number_[2]==0)||(number_[3]==0)||(number_[1]>60)||(number_[2]>60)||(number_[3]>60)){
								printf("	You missed the assertion(s) !!! \n");
							} else {
								printf("	Give me another random number from 1 to 60 \n");
								number_[4] = get_unsigned_numeric_input_with_not_more_than_2_letters ();
								if ((number_[4]<1)||(number_[4]>60)){
									printf("	You missed the assertion(s) !!! \n");
								} else {
									number_[4] = ((number_[4]%6)+1)%3 + 1;
									if (number_[4] == 1){
										num_temp = (number_[1] % 2)+(number_[2] % 3)+2*(number_[3] % 3);
										if (num_temp <= 1){
											use_number = 1;
										} else if (num_temp >= 6){
											use_number = 6;
										} else {
											use_number = num_temp;
										}
									}
									if (number_[4] == 2){
										num_temp = (number_[2] % 2)+(number_[1] % 3)+2*(number_[3] % 3);
										if (num_temp <= 1){
											use_number = 1;
										} else if (num_temp >= 6){
											use_number = 6;
										} else {
											use_number = num_temp;
										}
									}
									if (number_[4] == 3){
										num_temp = (number_[3] % 2)+(number_[1] % 3)+2*(number_[2] % 3);
										if (num_temp <= 1){
											use_number = 1;
										} else if (num_temp >= 6){
											use_number = 6;
										} else {
											use_number = num_temp;
										}
									}
									unsigned int Row[number_of_players];
									unsigned_int_array_null_initialisierung (Row, number_of_players-1);
									
									unsigned int Verteilung;
									Verteilung = (number_[1] + number_[2] + number_[3] + number_[4])%(number_of_players);
									for (unsigned int y = 0; y < number_of_players; y+=1){
										Row[y] = Verteilung;
										if (number_of_players == 9){
											Verteilung = (4*Verteilung + 8)%9;
										} else if (number_of_players == 2){
											Verteilung = (3*Verteilung + 1)%2;
										} else if (number_of_players == 3){
											Verteilung = (4*Verteilung + 2)%3;
										} else if (number_of_players == 4){
											Verteilung = (5*Verteilung + 1)%4;
										} else if (number_of_players == 5){
											Verteilung = (6*Verteilung + 3)%5;
										} else if (number_of_players == 6){
											Verteilung = (7*Verteilung + 1)%6;
										} else if (number_of_players == 7){
											Verteilung = (8*Verteilung + 4)%7;
										} else if (number_of_players == 8){
											Verteilung = (5*Verteilung + 7)%8;
										}
										
									}
									for (unsigned int y=0; y < number_of_players; y+=1){
										if (Row[y] == 0){
											if (gamemode_played == Hunt) {
												printf("	%u = Player 1, you will be hunted. (##) \n", y);
											} else if (gamemode_played == Arena) {
												printf("	%u = Player 1. \n", y);
											} else if ((gamemode_played == Ulcer)||(gamemode_played == Dynamic)||(gamemode_played == Survive)) {
												printf("	%u = Player 1, (11) \n", y);
											}
										} else if (Row[y] == 1){
											if (gamemode_played == Hunt) {
												printf("	%u = Player 2, (AA) \n", y);
											} else if (gamemode_played == Arena) {
												printf("	%u = Player 2. \n", y);
											} else if ((gamemode_played == Ulcer)||(gamemode_played == Dynamic)||(gamemode_played == Survive)) {
												printf("	%u = Player 2, (22) \n", y);
											}
										} else if (Row[y] == 2){
											if (gamemode_played == Hunt) {
												printf("	%u = Player 3, (BB) \n", y);
											} else if (gamemode_played == Arena) {
												printf("	%u = Player 3. \n", y);
											} else if ((gamemode_played == Ulcer)||(gamemode_played == Dynamic)||(gamemode_played == Survive)) {
												printf("	%u = Player 3, (33) \n", y);
											}
										} else if (Row[y] == 3){
											if (gamemode_played == Hunt) {
												printf("	%u = Player 4, (CC) \n", y);
											} else if (gamemode_played == Arena) {
												printf("	%u = Player 4. \n", y);
											} else if ((gamemode_played == Ulcer)||(gamemode_played == Dynamic)||(gamemode_played == Survive)) {
												printf("	%u = Player 4, (44) \n", y);
											}
										} else if (Row[y] == 4){
											if (gamemode_played == Hunt) {
												printf("	%u = Player 5, (DD) \n", y);
											} else if (gamemode_played == Arena) {
												printf("	%u = Player 5. \n", y);
											} else if ((gamemode_played == Ulcer)||(gamemode_played == Dynamic)||(gamemode_played == Survive)) {
												printf("	%u = Player 5, (55) \n", y);
											}
										} else if (Row[y] == 5){
											if (gamemode_played == Hunt) {
												printf("	%u = Player 6, (EE) \n", y);
											} else if (gamemode_played == Arena) {
												printf("	%u = Player 6. \n", y);
											} else if ((gamemode_played == Ulcer)||(gamemode_played == Dynamic)||(gamemode_played == Survive)) {
												printf("	%u = Player 6, (66) \n", y);
											}
										} else if (Row[y] == 6){
											if (gamemode_played == Hunt) {
												printf("	%u = Player 7, (GG) \n", y);
											} else if (gamemode_played == Arena) {
												printf("	%u = Player 7. \n", y);
											} else if ((gamemode_played == Ulcer)||(gamemode_played == Dynamic)||(gamemode_played == Survive)) {
												printf("	%u = Player 7, (77) \n", y);
											}
										} else if (Row[y] == 7){
											if (gamemode_played == Hunt) {
												printf("	%u = Player 8, (HH) \n", y);
											} else if (gamemode_played == Arena) {
												printf("	%u = Player 8. \n", y);
											} else if ((gamemode_played == Ulcer)||(gamemode_played == Dynamic)||(gamemode_played == Survive)) {
												printf("	%u = Player 8, (88) \n", y);
											}
										} else if (Row[y] == 8){
											if (gamemode_played == Hunt) {
												printf("	%u = Player 9, (II) \n", y);
											} else if (gamemode_played == Arena) {
												printf("	%u = Player 9. \n", y);
											} else if ((gamemode_played == Ulcer)||(gamemode_played == Dynamic)||(gamemode_played == Survive)) {
												printf("	%u = Player 9, (99) \n", y);
											}
										}
									}
								}
							}
							opt = 5;
						}
					}
					
					if (beginningmenu == Limits){
						if ((gamemode_played == Classic)||(gamemode_played == Collect)) {
							printf("	limit_new < limit_at_all - 4 	!	\n");
							printf("	Change limit_new: 1 \n	Change limit_at_all: 2 \n	Change both: 3 \n");
							lim = get_unsigned_numeric_input_with_not_more_than_1_letter ();
							printf("\n");
						
							if (lim == 1){
								printf("	limit_new:		(normal: 10) \n");
								limit_new = get_unsigned_numeric_input_with_not_more_than_2_letters ();
								printf("\n");
							}
							if (lim == 2){
								printf("	limit_at_all:		(normal: 20) \n");
								limit_at_all = get_unsigned_numeric_input_with_not_more_than_2_letters ();
								printf("\n");
							}
							if (lim == 3){
								printf("	limit_new:				(normal: 10) \n	limit_at_all:				(normal: 20) \n");
								letters_4 = get_unsigned_numeric_input_with_not_more_than_letters_4_for_splitting();
								limit_new = split_unsigned_numeric_input_with_letters_4 (letters_4, 0);
								limit_at_all = split_unsigned_numeric_input_with_letters_4 (letters_4, 1);
								printf("\n");
							}
							if (limit_new >= limit_at_all - 4) {
								limit_at_all = limit_new + 5;
							}
							
						} else if (gamemode_played == Contact) {
							printf("	limit_new: 1		limit_at_all: 2		both: 3\n");
							lim = get_unsigned_numeric_input_with_not_more_than_1_letter ();
							
							if (lim == 1){
								printf("	limit_new: 			(normal: 15) \n");
								limit_new = get_unsigned_numeric_input_with_not_more_than_2_letters ();
							}
							if (lim == 2){
								printf("	limit_at_all: 			(normal: 30) \n");
								limit_at_all = get_unsigned_numeric_input_with_not_more_than_2_letters ();
							}
							if (lim == 3){
								printf("	limit_new:				(normal: 15) \n	limit_at_all:				(normal: 30) \n");
								letters_4 = get_unsigned_numeric_input_with_not_more_than_letters_4_for_splitting();
								limit_new = split_unsigned_numeric_input_with_letters_4 (letters_4, 0);
								limit_at_all = split_unsigned_numeric_input_with_letters_4 (letters_4, 1);
							}
						} else if ((gamemode_played == Fall)||(gamemode_played == Race)||(gamemode_played == Rain)) {
							printf("	limit_new < limit_at_all - 4 	!	\n");
							printf("	limit_new: 1		limit_at_all: 2		both: 3\n");
							lim = get_unsigned_numeric_input_with_not_more_than_1_letter ();
							
							if (lim == 1){
								printf("	limit_new: 			(normal: 7) \n");
								limit_new = get_unsigned_numeric_input_with_not_more_than_2_letters ();
							}
							if (lim == 2){
								printf("	limit_at_all: 			(normal: 14) \n");
								limit_at_all = get_unsigned_numeric_input_with_not_more_than_2_letters ();
							}
							if (lim == 3){
								printf("	limit_new:				(normal: 7) \n	limit_at_all:				(normal: 14) \n");
								letters_4 = get_unsigned_numeric_input_with_not_more_than_letters_4_for_splitting();
								limit_new = split_unsigned_numeric_input_with_letters_4 (letters_4, 0);
								limit_at_all = split_unsigned_numeric_input_with_letters_4 (letters_4, 1);
							}
							if (limit_new >= limit_at_all - 4) {
								limit_at_all = limit_new + 5;
							}
						} else if (gamemode_played == Fight) {
							printf("	limit_new < limit_at_all - 4 	!	\n");
							printf("	limit_new: 1		limit_at_all: 2		both: 3\n");
							lim = get_unsigned_numeric_input_with_not_more_than_1_letter ();
							
							if (lim == 1){
								printf("	limit_new: 			(normal: 5) \n");
								limit_new = get_unsigned_numeric_input_with_not_more_than_2_letters ();
							}
							if (lim == 2){
								printf("	limit_at_all: 			(normal: 10) \n");
								limit_at_all = get_unsigned_numeric_input_with_not_more_than_2_letters ();
							}
							if (lim == 3){
								printf("	limit_new:				(normal: 5) \n	limit_at_all:				(normal: 10) \n");
								letters_4 = get_unsigned_numeric_input_with_not_more_than_letters_4_for_splitting();
								limit_new = split_unsigned_numeric_input_with_letters_4 (letters_4, 0);
								limit_at_all = split_unsigned_numeric_input_with_letters_4 (letters_4, 1);
							}
							if (limit_new >= limit_at_all - 4) {
								limit_at_all = limit_new + 5;
							}
						} else if (gamemode_played == Hunt) {
							printf("	The limits of the hunted one will be calculated seperatly.\n");
							printf("	limit_new < limit_at_all - 4 	!	\n");
							printf("	limit_new: 1		limit_at_all: 2		both: 3\n");
							lim = get_unsigned_numeric_input_with_not_more_than_1_letter ();
							
							if (lim == 1){
								printf("	limit_new: 			(normal: 6) \n");
								limit_new = get_unsigned_numeric_input_with_not_more_than_2_letters ();
							}
							if (lim == 2){
								printf("	limit_at_all: 			(normal: 12) \n");
								limit_at_all = get_unsigned_numeric_input_with_not_more_than_2_letters ();
							}
							if (lim == 3){
								printf("	limit_new:				(normal: 6) \n	limit_at_all:				(normal: 12) \n");
								letters_4 = get_unsigned_numeric_input_with_not_more_than_letters_4_for_splitting();
								limit_new = split_unsigned_numeric_input_with_letters_4 (letters_4, 0);
								limit_at_all = split_unsigned_numeric_input_with_letters_4 (letters_4, 1);
							}
							if (limit_new >= limit_at_all - 4) {
								limit_at_all = limit_new + 5;
							}
						} else if (gamemode_played == Arena) {
							printf("	limit_new can change with your ability.\n");
							printf("	limit_new < limit_at_all - 4 	!	\n");
							printf("	limit_new: 1		limit_at_all: 2		both: 3\n");
							lim = get_unsigned_numeric_input_with_not_more_than_1_letter ();
							
							if (lim == 1){
								printf("	limit_new: 			(normal: 8) \n");
								limit_new = get_unsigned_numeric_input_with_not_more_than_2_letters ();
							}
							if (lim == 2){
								printf("	limit_at_all: 			(normal: 16) \n");
								limit_at_all = get_unsigned_numeric_input_with_not_more_than_2_letters ();
							}
							if (lim == 3){
								printf("	limit_new:				(normal: 8) \n	limit_at_all:				(normal: 16) \n");
								letters_4 = get_unsigned_numeric_input_with_not_more_than_letters_4_for_splitting();
								limit_new = split_unsigned_numeric_input_with_letters_4 (letters_4, 0);
								limit_at_all = split_unsigned_numeric_input_with_letters_4 (letters_4, 1);
							}
							if (limit_new >= limit_at_all - 4) {
								limit_at_all = limit_new + 5;
							}
							
						} else if (gamemode_played == Ulcer) {
							printf("	Ulcer is unlimited.\n");
							
						} else if (gamemode_played == Dynamic) {
							printf("	This only works if the number of players is correct! \n");
							
							printf("	limit_new < limit_at_all - 4 	!	\n");
							printf("	limit_new: 1		limit_at_all: 2		both: 3\n");
							lim = get_unsigned_numeric_input_with_not_more_than_1_letter ();
							
							if (lim == 1){
								
								printf("	limit_new: 			(normal: 10) \n");
								limit_new = get_unsigned_numeric_input_with_not_more_than_2_letters ();
								
							}
							if (lim == 2){
								
								printf("	limit_at_all: 			(normal: 20) \n");
								limit_at_all = get_unsigned_numeric_input_with_not_more_than_2_letters ();
								
							}
							if (lim == 3){
								
								printf("	limit_new:				(normal: 10) \n	limit_at_all:				(normal: 20) \n");
								letters_4 = get_unsigned_numeric_input_with_not_more_than_letters_4_for_splitting();
								limit_new = split_unsigned_numeric_input_with_letters_4 (letters_4, 0);
								limit_at_all = split_unsigned_numeric_input_with_letters_4 (letters_4, 1);
							}
							if (limit_new >= limit_at_all - 4) {
								limit_at_all = limit_new + 5;
							}
						} else if (gamemode_played == Survive) {
							printf("	Survive is unlimited.\n");
							
						} else if (gamemode_played == Sand) {
							printf("	This only works if the number of players is correct! \n");
							
							printf("	limit_new < limit_at_all - 4 	!	\n");
							printf("	limit_new: 1		limit_at_all: 2		both: 3\n");
							lim = get_unsigned_numeric_input_with_not_more_than_1_letter ();
							
							if (lim == 1){
								
								printf("	limit_new: 			(normal: 7) \n");
								limit_new = get_unsigned_numeric_input_with_not_more_than_2_letters ();
								
							}
							if (lim == 2){
								
								printf("	limit_at_all: 			(normal: 14) \n");
								limit_at_all = get_unsigned_numeric_input_with_not_more_than_2_letters ();
								
							}
							if (lim == 3){
								
								printf("	limit_new:				(normal: 7) \n	limit_at_all:				(normal: 14) \n");
								letters_4 = get_unsigned_numeric_input_with_not_more_than_letters_4_for_splitting();
								limit_new = split_unsigned_numeric_input_with_letters_4 (letters_4, 0);
								limit_at_all = split_unsigned_numeric_input_with_letters_4 (letters_4, 1);
							}
							if (limit_new >= limit_at_all - 4) {
								limit_at_all = limit_new + 5;
							}
						}
						
					}
					
					if (beginningmenu == Time) {
						if (ttt != 0) {
							ttt = 0;
							warning_system = 0;
							
							printf("	The time for your turn is unlimited. \n");
						} else {
							printf("	Limit the time of each turn to make the game faster. \n");
							printf("	You should add a bonus of 10sec if you want to play in the tactics-mode. \n");
							printf("\n");
							if ((gamemode_played == Classic)||(gamemode_played == Collect)) {
								printf("	Choose the limit of time: 				(normal: 20sec) \n");
								ttt = get_unsigned_numeric_input_with_not_more_than_2_letters ();
								if (ttt == 0) {
									printf("	That's impossible! You'll take 20sec. \n");
									ttt = 20;
								}
								printf("\n");
								printf("\n");
								
								printf("	Choose the penalty: 		relaxed: 1, 	normal: 2, 	serious: 3, 	strict: 4, 	hard: 5, 	elite: 6, 	no mercy: 7 \n");
								warning_system = get_unsigned_numeric_input_with_not_more_than_1_letter ();
								if ((warning_system == 0)||(warning_system > 7)) {
									printf("	Let's say normal. \n");
									warning_system = 2;
								}
								printf("\n");
								printf("\n");
								
							} else if ((gamemode_played == Contact)||(gamemode_played == Arena)||(gamemode_played == Dynamic)) {
								printf("	Choose the limit of time: 				(normal: 30sec) \n");
								ttt = get_unsigned_numeric_input_with_not_more_than_2_letters ();
								if (ttt == 0) {
									printf("	That's impossible! You'll take 30sec. \n");
									ttt = 30;
								}
								printf("\n");
								printf("\n");
								
								printf("	Choose the penalty: 		relaxed: 1, 	normal: 2, 	serious: 3, 	strict: 4, 	hard: 5, 	elite: 6, 	no mercy: 7 \n");
								warning_system = get_unsigned_numeric_input_with_not_more_than_1_letter ();
								if ((warning_system == 0)||(warning_system > 7)) {
									printf("	Let's say normal. \n");
									warning_system = 2;
								}
								printf("\n");
								printf("\n");
								
							} else if ((gamemode_played == Fall)||(gamemode_played == Race)||(gamemode_played == Rain)||(gamemode_played == Ulcer)||(gamemode_played == Survive)) {
								printf("	Choose the limit of time: 				(normal: 25sec) \n");
								ttt = get_unsigned_numeric_input_with_not_more_than_2_letters ();
								if (ttt == 0) {
									printf("	That's impossible! You'll take 25sec. \n");
									ttt = 25;
								}
								printf("\n");
								printf("\n");
								
								printf("	Choose the penalty: 		relaxed: 1, 	normal: 2, 	serious: 3, 	strict: 4, 	hard: 5, 	elite: 6, 	no mercy: 7 \n");
								warning_system = get_unsigned_numeric_input_with_not_more_than_1_letter ();
								if ((warning_system == 0)||(warning_system > 7)) {
									printf("	Let's say normal. \n");
									warning_system = 2;
								}
								printf("\n");
								printf("\n");
							} else if (gamemode_played == Fight) {
								printf("	Choose the limit of time: 				(normal: 15sec) \n");
								ttt = get_unsigned_numeric_input_with_not_more_than_2_letters ();
								if (ttt == 0) {
									printf("	That's impossible! You'll take 15sec. \n");
									ttt = 15;
								}
								printf("\n");
								printf("\n");
								
								printf("	Choose the penalty: 		relaxed: 1, 	normal: 2, 	serious: 3, 	strict: 4, 	hard: 5, 	elite: 6, 	no mercy: 7 \n");
								warning_system = get_unsigned_numeric_input_with_not_more_than_1_letter ();
								if ((warning_system == 0)||(warning_system > 7)) {
									printf("	Let's say normal. \n");
									warning_system = 2;
								}
								printf("\n");
								printf("\n");
								
							} else if (gamemode_played == Hunt) {
								printf("	The hunted one will get a 10sec bonus. \n");
								printf("	The time for choosing his heart is unlimited. \n");
								printf("	\n");
								printf("	Choose the limit of time: 				(normal: 35sec) \n");
								ttt = get_unsigned_numeric_input_with_not_more_than_2_letters ();
								if (ttt == 0) {
									printf("	That's impossible! You'll take 35sec. \n");
									ttt = 35;
								}
								printf("\n");
								printf("\n");
								
								printf("	Choose the penalty: 		relaxed: 1, 	normal: 2, 	serious: 3, 	strict: 4, 	hard: 5, 	elite: 6, 	no mercy: 7 \n");
								warning_system = get_unsigned_numeric_input_with_not_more_than_1_letter ();
								if ((warning_system == 0)||(warning_system > 7)) {
									printf("	Let's say normal. \n");
									warning_system = 2;
								}
								printf("\n");
								printf("\n");
							}
						}
						
					}
					
					if (beginningmenu == Color) {
						
						get_colors(Colored, gamemode_played, number_of_players, AOP);
						
					}
					
					if (beginningmenu == Opague) {
						lim = 0;
						if (opague == 0) {
							
							printf("	Going here again will lead to a return to normal visibility! \n");
							printf(" \n");
							while ((opague != 11)&&(opague != 12)&&(opague != 21)&&(opague != 22)) {		//4-Mode-Opague
								
								opague = 0;
								lim = 0;
								
								printf(" 	Use the #Surrounding or the #near-by additional to the place itself? \n\n");
								printf(" 	#Surrounding: 1			#near-by: 2 \n");
								
								lim = get_unsigned_numeric_input_with_not_more_than_1_letter ();
								
								printf(" 	Show even or uneven counts? \n\n");
								printf(" 	Uneven: 1		Even: 2	\n");
								
								opague = get_unsigned_numeric_input_with_not_more_than_1_letter ();
								
								opague += 10*lim;
							}
							
						} else if (opague >= 1) {
							printf("	Returned to normal visibility! \n");
							printf(" \n");
							opague = 0;
						}
						lim = 0;
					}
					
					if (beginningmenu == undead) {
						
						if (undead_duration != 0) {
							printf("	undead-mode reseted! \n");
							printf(" \n");
							undead_duration = 0;
						} else {
							printf("	Going here again will reset the undead-mode! \n");
							printf("	How many turns the undead-square should survive? \n");
							undead_duration = get_unsigned_numeric_input_with_not_more_than_2_letters ();
						}
					}
					
					if (beginningmenu == Figures) {
						
						if (figures != 0) {
							printf("	Figures-mode reseted! \n");
							printf(" \n");
							figures = 0;
						} else {
							printf("	Going here again will reset the Figures-mode! \n");
							figures = 1;	//make a selection possible, go on
							
							show_figures ();
						}
					}
					
					if (beginningmenu == Allocation) {
						
						printf("	Every movement of a square owned by a player caused by gamemode-special actions will reduce its allocation to 1 \n");
						
						if (allocation != 0) {
							printf("	Allocation-mode reseted! \n");
							printf(" \n");
							allocation = 0;
						} else {
							printf("	Going here again will reset the Allocation-mode! \n");
							printf("	Maximum of possession? (<100)\n");
							
							allocation = get_unsigned_numeric_input_with_not_more_than_2_letters ();
							
							if (allocation == 0) {
								printf("	That's not possible !!! \n");
							}
						}
					}
					
					if (beginningmenu == Cards) {
						tac = 0;
						opt = 0;
						
						if (cards != 0) {
							printf("	Cards-mode reseted! \n");
							printf(" \n");
							cards = 0;
						} else {
							printf("	Do not activate Tactics or Random, it will replace the Cards-Mode! \n");
							printf("	This only works if the number of players is correct! \n");
							printf("	Going here again will reset the Cards-mode! \n");
							
							time3 = time(NULL);
							cards = 1;
						}
						
					}
					
					if (beginningmenu == Inverted) {
						
						if (inverted != 0) {
							printf("	Inverted-mode reseted! \n");
							printf(" \n");
							inverted = 0;
						} else {
							printf("	Going here again will reset the Inverted-mode! \n");
							printf("	Inverted overrides the limits of development! \n");
							inverted = 1;
						}
					}
					
					if (beginningmenu == Addition) {
						
						if (addition != 0) {
							printf("	Addition-mode reseted! \n");
							printf(" \n");
							addition = 0;
						} else {
							printf("	Going here again will reset the Addition-mode! \n");
							printf("	Addition overrides the limits of development! \n");
							addition = 1;
						}
					}
					
					if (beginningmenu == Projection) {
						
						if (intensity_loss_per_line_multiplication != 0) {
							printf("	Projection-mode reseted! \n");
							printf(" \n");
							intensity_loss_per_line_multiplication = 0;
							intensity_minimum = 0;
							direction = undefined;
						} else {
							printf("	Going here again will reset the Projection-mode! \n");
							printf("	Projection overrides the limits of development! \n \n");
							printf("	Loss of intensity per line passed in per cent: 0<Loss<100		(normal: 40) \n");
							lim = 0;
							lim = get_unsigned_numeric_input_with_not_more_than_2_letters ();
							
							if (lim == 0) {
								printf("	Than you should not use this option, you will get 40. \n \n");
								lim = 40;
							}
							
							printf("lim = %u \n", lim);	//test
							
							intensity_loss_per_line_multiplication = 100 - lim;
							lim = 0;
							
							printf("	Minimum of intensity in per cent:  0=<Minimum<1000		(normal: %u) \n \n", intensity_loss_per_line_multiplication);
							intensity_minimum = get_unsigned_numeric_input_with_not_more_than_3_letters ();
							
							direction = undefined;
							while ((direction != Horizontal)&&(direction != Vertikal)&&(direction != Changing)) {
								printf("	Direction of projection:\n		Horizontal = 0 \n		Vertikal = 1\n		Changing = 2 \n");
								direction = get_unsigned_numeric_input_with_not_more_than_1_letter ();
							}
							
						}
					}
					
					if (beginningmenu == Assassin) {
						
						if (assassin != 0) {
							printf("	Assassin-mode reseted! \n");
							printf(" \n");
							assassin = 0;
						} else {
							printf("	Going here again will reset the Assassin-mode! \n");
							assassin = 1;
						}
					}
					
					if (beginningmenu == Permutations) {
						
						if ((amount_of_permutation_number_b != 0)||(amount_of_permutation_number_c != 0)) {
							printf("	Permutations-mode reseted! \n");
							printf(" \n");
							amount_of_permutation_number_b = 0;
							amount_of_permutation_number_c = 0;
							permutation_number_b = 0;
							permutation_number_c = 0;
						} else {
							printf("	Going here again will reset the Permutations-mode! \n\n");
							
							while ((permutation_number_c <= permutation_number_b)||(permutation_number_b == 0)||(permutation_number_c >= 10)) {
								
								printf("	Choose two numbers b,c with 0<b<c<10 and probably ggT(b,c) = 1. \n");
								printf("	b: \n	c: \n");
								
								letters_2 = get_unsigned_numeric_input_with_not_more_than_letters_2_for_splitting ();
								permutation_number_b = split_unsigned_numeric_input_with_letters_2 (letters_2, 0);
								permutation_number_c = split_unsigned_numeric_input_with_letters_2 (letters_2, 1);
								
								// printf("	permutation_number_b = %u \n", permutation_number_b);	//test
								// printf("	permutation_number_c = %u \n", permutation_number_c);	//test
							}
							
							get_two_amounts_for_permutations (&amount_of_permutation_number_b, &amount_of_permutation_number_c, m, n, permutation_number_b, permutation_number_c);
							
							// printf("	amount_of_permutation_number_b = %u \n", amount_of_permutation_number_b);	//test
							// printf("	amount_of_permutation_number_c = %u \n", amount_of_permutation_number_c);	//test
							
							if ((amount_of_permutation_number_b == 0)&&(amount_of_permutation_number_c == 0)) {
								permutation_number_b = 0;
								permutation_number_c = 0;
								printf("	Try again, it doesn't fit. \n");
							}
						}
					}
					
					if ((beginningmenu == back+1)&&(gamemode_played == Fall)){
						printf("	Points for win: (0<...<10)			(normal: 3) \n");
						points_for_win = get_unsigned_numeric_input_with_not_more_than_1_letter ();
						
						if ((points_for_win == 0) || (points_for_win >= 10)) {
							printf("	You missed the assertion(s) !!! \n");
							points_for_win = 3;
						}
						
					}
					if ((beginningmenu == back+2)&&(gamemode_played == Fall)){
						printf("	Turns per drop: (>=2)			(normal: 3) \n");
						turns_per_drop = get_unsigned_numeric_input_with_not_more_than_1_letter ();
						
						if (turns_per_drop < 2) {
							printf("	You missed the assertion(s) !!! \n");
							turns_per_drop = 3;
						}
						
					}
					if ((beginningmenu == back+3)&&(gamemode_played == Fall)){
						printf("	Speed of the #-square: 	(>0)		(normal: 1) \n");
						speed_of_fall = get_unsigned_numeric_input_with_not_more_than_1_letter ();
						
						if (speed_of_fall == 0) {
							printf("	You missed the assertion(s) !!! \n");
							speed_of_fall = 1;
						}
					}
					if ((beginningmenu == back+1)&&(gamemode_played == Hunt)){
						printf("	Rounds to catch? >=5			(normal: 30) \n");
						rtc = get_unsigned_numeric_input_with_not_more_than_1_letter ();
						if (rtc < 5) {
							printf("	You missed the assertion(s) !!! \n");
							rtc = 30;
						}
						
						printf("	Show-Position-Frequence in Rounds:			(normal: 5) \n");
						spf = get_unsigned_numeric_input_with_not_more_than_1_letter ();
						if (spf < 1) {
							printf("	You missed the assertion(s) !!! \n");
							spf = 5;
						}
						
						printf("	Show the heart_block or all?: 		(normal: all) \n		heart_block: 0 \n		all: 1 \n		\n");
						hboa = get_unsigned_numeric_input_with_not_more_than_1_letter ();
						if (hboa >= 2) {
							printf("	You missed the assertion(s) !!! \n");
							hboa = 1;
						}
						
						printf("	Show Contact with hunted person: 		(normal: 1) \n		No: 0 \n		Only if necessary : 1 \n		Always: 2 \n		\n");
						scwhp = get_unsigned_numeric_input_with_not_more_than_1_letter ();
						if (scwhp > 2) {
							printf("	You missed the assertion(s) !!! \n");
							scwhp = 1;
						}
					}
					if ((beginningmenu == back+1)&&(gamemode_played == Arena)) {
						
						if (number_of_players != AOP) {
							printf("	This only works if the number of players is correct! \n");
							printf("\n");
							printf("	Going here again will lead to a reset of the exclusion! \n");
						} else {
							printf("	Sorry, you can't exclude any ability, because you need all of them. \n");
						}
						
						printf(" \n");
						for (unsigned int p=0; p<=AOP; p+=1) {
							ability[p] = 0;
						}
						
						lim = 0;
						while (((lim == 0)||(lim > 10))&&(exclude_counter < (AOP-number_of_players))) {
							printf("	Which ability do you want to exclude? \n");
							printf(" \n");
							
							show_abilities (ability);
							
							printf(" \n");
							printf(" \n");
							if ((ability[1] == 100)||(ability[2] == 100)||(ability[3] == 100)||(ability[4] == 100)||(ability[5] == 100)||(ability[6] == 100)||(ability[7] == 100)||(ability[8] == 100)||(ability[9] == 100)) {
								printf("	Which ability do you want to include? \n");
							}
							printf(" \n");
							
							show_abilities (ability);
							
							printf(" \n");
							printf(" \n");
							printf("	Back: 10 \n");
							printf(" \n");
							lim = get_unsigned_numeric_input_with_not_more_than_1_letter ();
							
							for (unsigned int u=0; u<=AOP; u++) {
								if ((lim == u)&&(ability[u] == 0)) {
									ability[u] = 100;
									exclude_counter += 1;
									lim = 0;
								} else if ((lim == u)&&(ability[u] == 100)) {
									ability[u] = 0;
									exclude_counter -= 1;
									lim = 0;
								}
							}
						}
						
					}
					if ((beginningmenu == back+2)&&((gamemode_played == Hunt)||(gamemode_played == Arena)||(gamemode_played == Ulcer)||(gamemode_played == Dynamic)||(gamemode_played == Survive)||(gamemode_played == Sand))){
						
						number_of_players = 0;
						
						while ((number_of_players < 1) || (number_of_players > AOP)){
							printf("	Number of players?		(1 - 9) \n");
							number_of_players = get_unsigned_numeric_input_with_not_more_than_1_letter ();	//watch out, if AOP gets >= 10
						}
						
						if (gamemode_played == Hunt) {
							if (number_of_players == 2) {
								m = Initialisierung_m (gamemode_played);
								n = Initialisierung_n (gamemode_played);
							} else {
								for (unsigned int p=1; p<=AOP; p++) {
									if (p == number_of_players) {
										m = 2*p + 1 + 2;
										if ((number_of_players == 4)||(number_of_players == 5)||(number_of_players == 9)) {
											m+=2;
										} else if (number_of_players == 8) {
											m--;
										}
										
										n = 3*p + 2;
										if ((number_of_players == 4)||(number_of_players == 5)||(number_of_players == 6)||(number_of_players == 7)) {
											n-=((p+1)/3);
										} else if (number_of_players == 9) {
											n+=(4-3*(p%3)-10*(p/7));
										}
										break;
									}
								}
							}
						} else if (gamemode_played == Arena) {
							if (number_of_players == 2) {
								m = Initialisierung_m (gamemode_played);
								n = Initialisierung_n (gamemode_played);
							} else {
								for (unsigned int p=1; p<=AOP; p++) {
									if (p == number_of_players) {
										m = 6 + p + (p-1)/3 - p/7 + p/8 - p/9 + 2;
										n = 6 + p + (p-1)/3 - p/7 + p/8 - p/9 + 2;
										break;
									}
								}
							}
						} else if (gamemode_played == Ulcer) {
							if (number_of_players == 2) {
								m = Initialisierung_m (gamemode_played);
								n = Initialisierung_n (gamemode_played);
							} else {
								for (unsigned int p=1; p<=AOP; p++) {
									if (p == number_of_players) {
										m = 5 + p + 2;
										n = 5 + p + 2;
										if (number_of_players == 3) {
											m--;
											n--;
										}
										break;
									}
								}
							}
						} else if (gamemode_played == Dynamic) {
							if (number_of_players == 2) {
								m = Initialisierung_m (gamemode_played);
								n = Initialisierung_n (gamemode_played);
							} else {
								for (unsigned int p=1; p<=AOP; p++) {
									if (p == number_of_players) {
										m = 9 + 2*(p/4) + 4*(p/6) + 2;
										n = 11 + 4*(p/5) + 2*(p/8) + 2;
										break;
									}
								}
							}
						} else if (gamemode_played == Survive) {
							
							for (unsigned int p=1; p<=AOP; p++) {
								if (p == number_of_players) {
									m = 9 + p + 2;
									n = 9 + p + 2;
									
									if ((number_of_players == 5)||(number_of_players == 7)) {
										m++;
										n++;
									} else if (number_of_players == 9) {
										m--;
										n--;
									}
									break;
								}
							}
						} else if (gamemode_played == Sand) {
							if (number_of_players == 2) {
								m = Initialisierung_m (gamemode_played);
								n = Initialisierung_n (gamemode_played);
							} else {
								for (unsigned int p=1; p<=AOP; p++) {
									if (p == number_of_players) {
										m = 5+p + 2;
										n = 3+4*(p-1)+ 1/(p*p) + 2;
										break;
									}
								}
							}
						}
						
					} else if ((beginningmenu == back+3)&&((gamemode_played == Arena)||(gamemode_played == Ulcer))) {
						printf("	Rounds to play: 			(normal: 30) \n");
						rtp = get_unsigned_numeric_input_with_not_more_than_2_letters ();
						if (rtp == 0) {
							rtp = 30;
						}
						if (gamemode_played == Ulcer) {
							printf("	K.O.-Mode deactivated \n");
							ulcer_start[0] = 0;
						}
					} else if ((beginningmenu == back+1)&&(gamemode_played == Race)){
						printf("	Frequence: 			(normal: 6) \n");
						freq = get_unsigned_numeric_input_with_not_more_than_1_letter ();
					} else if ((beginningmenu == back+1)&&(gamemode_played == Rain)){
						printf("	Only Object: 	yes [1]		no [0] \n");
						rain_obj = get_unsigned_numeric_input_with_not_more_than_1_letter ();
						if ((rain_obj != 1)&&(rain_obj != 0)) {
							printf("	You missed the assertion(s) !!! \n");
							rain_obj = 0;
						}
						
						printf("	Raindrops per turn:		1, 	2, 	4, 	5, 	6 	? \n");
						rain_drops = get_unsigned_numeric_input_with_not_more_than_1_letter ();
						if ((rain_drops == 0) || (rain_drops > 6) || (rain_drops == 3)){
							printf("	You missed the assertion(s) !!! \n");
							rain_drops = 1;
						}
						printf("\n");
						
						printf("	Characteristics of the Raindrops: \n");
						printf("		Push: 1 \n		Destroy: 2 \n		Explode: 3 \n		Transform: 4 \n		Teleport: 5 \n		Mixed: 6 \n");
						rain = get_unsigned_numeric_input_with_not_more_than_1_letter ();
						if (rain == 3){
							printf("		Explode: 31		or		Explode & survival: 32 \n");
							rain = get_unsigned_numeric_input_with_not_more_than_2_letters ();
						}
						printf("\n");
						if ((rain == 0)||(rain > 6)) {
							printf("	You missed the assertion(s) !!! \n");
							rain = 1;
						}
						
						printf("	Distance in squares the rain should Fall per turn:  		(<=6), 0 = 0,5 \n");
						rain_speed = get_unsigned_numeric_input_with_not_more_than_1_letter ();
						if (rain_speed > 6){
							printf("	You missed the assertion(s) !!! \n");
							rain_speed = 1;
						}
						printf("\n");
					} else if ((beginningmenu == back+1)&&(gamemode_played == Ulcer)) {
						
						printf("	This only works if the number of players is correct! \n");
						printf("\n");
						printf("	Choose the amount of lifes. \n");
						for (unsigned int p=1; p<=number_of_players; p+=1) {
							printf("\n");
							printf("	Lifes PLayer: %u		(normal %u) \n", p, p-1);
							ulcer_lifes[p] = get_unsigned_numeric_input_with_not_more_than_1_letter ();
							printf("\n");
						}
					} else if ((beginningmenu == back+4)&&(gamemode_played == Ulcer)) {
						if (ulcer_start[0] == 0) {
							printf("	K.O.-Mode activated. \n");
							printf("	Rounds are unlimited. \n");
							
							rtp = 0;
							ulcer_start[0] = 1;
						} else if (ulcer_start[0] == 1) {
							printf("	K.O.-Mode deactivated. \n");
							ulcer_start[0] = 0;
						}
						
					} else if ((beginningmenu == back+1)&&(gamemode_played == Dynamic)) {
						printf("	The Gravity is pulling down the object. \n");
						printf("	Gravity:	-5 to 5		(normal: 1) \n");
						erd = get_signed_numeric_input_with_not_more_than_1_letter ();
						if ((erd < -5)||(erd > 5)) {
							printf("	That makes no sense, i will give you the 1. \n");
							erd = 1;
						}
					} else if ((beginningmenu == back+3)&&(gamemode_played == Dynamic)) {
						printf("	The Range of the impact moving the object. \n");
						printf("	Range:	0-5		(normal: 1) \n");
						range = get_unsigned_numeric_input_with_not_more_than_1_letter ();
						if (range > 5) {
							printf("	That makes no sense, i will give you the 1. \n");
							range = 1;
						}
					} else if ((beginningmenu == back+4)&&(gamemode_played == Dynamic)) {
						printf("	The Coefficient influences the way and strength of the impact moving the object. \n");
						printf("	Coefficient:	0-5		(normal: 1) \n");
						d_wert = get_unsigned_numeric_input_with_not_more_than_1_letter ();
						if (d_wert > 5) {
							printf("	That makes no sense, i will give you the 1. \n");
							d_wert = 1;
						}
					} else if ((beginningmenu == back+1)&&(gamemode_played == Survive)) {
						for (unsigned int p=1; p<=3; p+=1) {
							information_code[p] = 2;
						}
						printf("	Do you want to play with: \n");
						
						while (information_code[1]>1) {
							printf("	-Traps:		Yes: 1		No: 0 \n");
							information_code[1] = get_unsigned_numeric_input_with_not_more_than_1_letter ();
						}
						while (information_code[2]>1) {
							printf("	-Bombs:		Yes: 1		No: 0 \n");
							information_code[2] = get_unsigned_numeric_input_with_not_more_than_1_letter ();
						}
						while (information_code[3]>1) {
							printf("	-Waves:		Yes: 1		No: 0 \n");
							information_code[3] = get_unsigned_numeric_input_with_not_more_than_1_letter ();
						}
					} else if ((beginningmenu == back+1)&&(gamemode_played == Sand)) {
						printf("	Where to start falling? \n");
						printf("	Top: 1		Bottom: 2 \n");
						information_code[1] = get_unsigned_numeric_input_with_not_more_than_1_letter ();
						
						if ((information_code[1] == 0)||(information_code[1] > 2)) {
							printf("	You missed the assertion(s) !!! \n");
							information_code[1] = 1;
						}
					} else if ((beginningmenu == back+3)&&(gamemode_played == Sand)) {
						printf("	How many squares falling? \n");
						information_code[2] = get_unsigned_numeric_input_with_not_more_than_2_letters ();
						
					} else if ((beginningmenu == back+4)&&(gamemode_played == Sand)) {
						printf("	After how many rounds falling? (>0)\n");
						information_code[3] = get_unsigned_numeric_input_with_not_more_than_2_letters ();
						
						if (information_code[3] == 0) {
							printf("	You missed the assertion(s) !!! \n");
							information_code[3] = 2;
						}
					} else if (beginningmenu == back){	//auch hier!
						gamemode_played = 0;
						break;
					}
					printf("\n");
				
					printf("	Your chosen set-up: \n");
					printf("\n");
					printf("	Gamemode:");
					if (gamemode_played == Classic) {
						printf(" Classic \n ");
					} else if (gamemode_played == Collect) {
						printf(" Collect \n ");
					} else if (gamemode_played == Contact) {
						printf(" Contact \n ");
					} else if (gamemode_played == Fall) {
						printf(" Fall \n ");
						printf("	Points for win: %u \n", points_for_win);
						printf("	Turns per drop: %u \n", turns_per_drop);
						printf("	Speed of the #-square: %u \n", speed_of_fall);
					} else if (gamemode_played == Fight) {
						printf(" Fight \n ");
					} else if (gamemode_played == Hunt) {
						printf(" Hunt \n ");
						printf("	Rounds to catch: %u \n", rtc);
						printf("	Show-Position-Frequence in Rounds: %u \n", spf);
						printf("	What to show: ");
						if (hboa == 0) {
							printf(" heart-block \n");
						} else if (hboa == 1) {
							printf(" all \n");
						}
						printf("	Show Contact with hunted person: ");
						if (scwhp == 0) {
							printf(" No \n");
						} else if (scwhp == 1) {
							printf(" Only if necessary \n");
						} else if (scwhp == 2) {
							printf(" Permanent \n");
						}
						printf("	Number of players: %u \n", number_of_players);
					} else if (gamemode_played == Race) {
						printf(" Race \n ");
						printf("	Frequence: %u \n", freq);
					} else if (gamemode_played == Rain) {
						printf(" Rain \n ");
						printf("	Only Object: ");
						if (rain_obj == 1) {
							printf("	yes \n");
						} else if (rain_obj == 0) {
							printf("	no \n");
						}
						printf("	Raindrops per turn: %u \n", rain_drops);
						printf("	Characteristics of the Raindrops: ");
						if (rain == 1) {
							printf("	Push: 1 \n");
						} else if (rain == 2) {
							printf("	Destroy: 2 \n");
						} else if (rain == 31) {
							printf("	Explode: 3 \n");
						} else if (rain == 32) {
							printf("	Explode & survival: 3 \n");
						} else if (rain == 4) {
							printf("	Transform: 4 \n");
						} else if (rain == 5) {
							printf("	Teleport: 5 \n");
						} else if (rain == 6) {
							printf("	Mixed: 6 \n");
						}
						if (rain_speed == 0) {
							printf("	Distance in squares: 0,5 \n");
						} else {
							printf("	Distance in squares: %u \n", rain_speed);
						}
						
					} else if (gamemode_played == Arena) {
						printf(" Arena \n ");
						printf(" \n ");
						printf("	Excluded abilities: \n");
						printf(" \n");
						
						if (ability[1] == 100) {
							printf("	Ultra light. \n");
						}
						if (ability[2] == 100) {
							printf("	Light. \n");
						}
						if (ability[3] == 100) {
							printf("	Anti. \n");
						}
						if (ability[4] == 100) {
							printf("	Cornered. \n");
						}
						if (ability[5] == 100) {
							printf("	Inhibitor. \n");
						}
						if (ability[6] == 100) {
							printf("	Shield. \n");
						}
						if (ability[7] == 100) {
							printf("	Poisoning. \n");
						}
						if (ability[8] == 100) {
							printf("	Pressure. \n");
						}
						if (ability[9] == 100) {
							printf("	Electric. \n");
						}
						if (exclude_counter == 0) {
							printf("	No ability excluded. \n");
						}
						printf("	Number of players: %u \n", number_of_players);
					} else if (gamemode_played == Ulcer) {
						printf(" Ulcer \n ");
						for (unsigned int p=1; p<=number_of_players; p+=1) {
							printf(" \n ");
							printf("	Lifes player %u: %u \n ", p, ulcer_lifes[p]);
						}
						printf("	Number of players: %u \n", number_of_players);
					} else if (gamemode_played == Dynamic) {
						printf(" Dynamic \n ");
						printf("	Gravity: %d \n", erd);
						printf("	range: %u \n", range);
						printf("	Coefficient: %u \n", d_wert);
						printf("	Number of players: %u \n", number_of_players);
					} else if (gamemode_played == Survive) {
						printf(" Survive \n ");
						printf("	Traps: ");
						if (information_code[1] == 1) {
							printf("	yes \n");
						} else if (information_code[1]== 0) {
							printf("	no \n");
						}
						printf("	Bombs: ");
						if (information_code[2] == 1) {
							printf("	yes \n");
						} else if (information_code[2]== 0) {
							printf("	no \n");
						}
						printf("	Waves: ");
						if (information_code[3] == 1) {
							printf("	yes \n");
						} else if (information_code[3]== 0) {
							printf("	no \n");
						}
						printf("	Number of players: %u \n", number_of_players);
					} else if (gamemode_played == Sand) {
						printf(" Sand \n ");
						printf("	Gravity begins at the: ");
						if (information_code[1] == 1) {
							printf("	Top \n");
						} else if (information_code[1]== 2) {
							printf("	Bottom \n");
						}
						printf("	Speed : %u \n", information_code[2]);
						printf("	Period: %u \n", information_code[3]);
						printf("	Number of players: %u \n", number_of_players);
					}
					printf(" \n ");
					printf(" \n");
					printf(" 	Zeilen:  %u \n	Spalten: %u \n", m-2, n-2);
					printf(" \n");
					if (journey == 1){
						printf("	Journey   activated \n");
					} else if (journey == 0){
						printf("	Journey deactivated \n");
					}
					printf(" \n");
					if (gamemode_played == Ulcer) {
						if (ulcer_start[0] == 1){
							printf("	K.O.-Mode   activated. \n");	
						} else if (ulcer_start[0] == 0){
							printf("	K.O.-Mode deactivated \n");	
						}
						
						printf(" \n");
					}
					
					if (ttt == 0) {
						printf("	Time	deactivated \n");
					} else if (ttt != 0) {
						printf("	Time	  activated \n");
					}
					printf("\n");
					
					if (opague != 0){
						printf("	Opague   activated \n");
						printf(" \n");
						
						if (opague >= 20) {		//4-Mode-Opague
							printf("	Use the #near-by. \n");
						} else if (opague >= 10) {
							printf("	Use the #Surrounding. \n");
						}
						if (opague % 10 == 1) {
							printf("	Show uneven counts. \n");
						}
						if (opague % 10 == 2) {
							printf("	Show   even counts. \n");
						}
					} else {
						printf("	Opague  deactivated \n");	
					}
					printf(" \n");
					
					if (undead_duration == 0) {
						printf("	undead	deactivated \n");
					} else if (undead_duration != 0) {
						printf("	undead	  activated \n");
					}
					printf("\n");
					
					if (figures == 0) {
						printf("	Figures	deactivated \n");
					} else if (figures != 0) {
						printf("	Figures	  activated \n");
					}
					printf("\n");
					
					if (allocation == 0) {
						printf("	Allocation deactivated \n");
					} else if (allocation != 0) {
						printf("	Allocation   activated \n");
					}
					printf("\n");
					
					if (inverted == 0) {
						printf("	Inverted deactivated \n");
					} else if (inverted != 0) {
						printf("	Inverted   activated \n");
					}
					printf("\n");
					
					if (addition == 0) {
						printf("	Addition deactivated \n");
					} else if (addition != 0) {
						printf("	Addition   activated \n");
					}
					printf("\n");
					
					if (assassin == 0) {
						printf("	Assassin deactivated \n");
					} else if (assassin != 0) {
						printf("	Assassin   activated \n");
					}
					printf("\n");
					
					if (intensity_loss_per_line_multiplication == 0) {
						printf("	Projection deactivated \n");
					} else if (intensity_loss_per_line_multiplication != 0) {
						printf("	Projection   activated \n");
					}
					printf("\n");
					
					if ((amount_of_permutation_number_b == 0)&&(amount_of_permutation_number_c == 0)) {
						printf("	Permutations deactivated \n");
					} else if ((amount_of_permutation_number_b != 0)||(amount_of_permutation_number_c != 0)) {
						printf("	Permutations   activated \n");
					}
					printf("\n");
					
					if (opt == 5) {
						printf("	Random    activated \n");
						if ((gamemode_played != Hunt)&&(gamemode_played != Arena)&&(gamemode_played != Ulcer)&&(gamemode_played != Dynamic)&&(gamemode_played != Survive)&&(gamemode_played != Sand)) {
							if ((number_[1] + number_[3]) % 4 <= 1){
								printf("\n");
								printf("	A Player: Spieler 1	\n	The other Player: Spieler 2 \n");
								printf("\n");
							} else {
								printf("\n");
								printf("	The other Player: Spieler 1	\n	A Player: Spieler 2 \n");
								printf("\n");
							}
						}
						
					} else if (opt == 0) {
						printf("	Random  deactivated \n");
					}
					printf(" \n");
					if (tac != 0){
						printf("	Tactics   activated, 	stack = %u \n", tac);	
					} else {
						printf("	Tactics deactivated \n");	
					}
					printf(" \n");
					if (cards != 0){
						printf("	Cards     activated \n");
					} else {
						printf("	Cards   deactivated \n");	
					}
					printf(" \n");
					printf("	limit_new:    %u \n	limit_at_all: %u \n", limit_new, limit_at_all);
					printf("	(sometimes only for the journey!) \n");
					printf("\n");
					
					printf("	Colored squares:	");
					if (Colored[0] == 1) {
						printf("yes \n");
					} else if (Colored[0] == 0) {
						printf("no \n");
					}
					if (beginningmenu != 1) {
						printf("\n");
						printf("	... until now.\n");
						printf("\n");
					} else {
						printf(" \n");
						printf(" \n");
						printf(" \n");
						printf(" \n");
						printf(" Have a good game. \n");
						printf(" \n");
						
						if (gamemode_played == Arena) {
							choose_your_ability (number_of_players, ability, Colored);
						}
					}
					printf("\n");
					printf("\n");
				}
			}
			
			// scanf("%u", &pause);	//test
			// printf("	#line 2k, before same \n");	//test
			
			//Startmenü, Ende
			
			same[0] = 0;
			same[1] = m;
			same[2] = n;
			same[3] = journey;
			same[4] = tac;
			same[5] = gamemode_played;
			same[6] = fall_controll;
			same[7] = turns_per_drop;
			same[8] = speed_of_fall;
			same[9] = count_freq;
			same[10] = ulcer_lifes[1];
			same[11] = rain;
			same[12] = rain_drops;
			same[13] = rain_obj;
			same[14] = rain_speed;
			same[15] = opt;
			same[16] = range;
			same[17] = d_wert;
			same[18] = limit_new;
			same[19] = limit_at_all;
			same[20] = ulcer_lifes[2];
			same[21] = points_for_win;
			same[22] = freq;
				//same[23] ist schon belegt
			same[24] = number_of_players;
			same[25] = rtc;
			same[26] = spf;
			same[27] = scwhp;
			same[28] = hboa;
			same[29] = ttt;
			same[30] = ulcer_lifes[3];
			same[31] = warning_system;
			same[32] = exclude_counter;
			same[33] = rtp;
			same[34] = information_code[0];
			same[35] = information_code[1];
			same[36] = information_code[2];
			same[37] = information_code[3];
			same[38] = ability[0];
			same[39] = ability[1];
			same[40] = ulcer_lifes[4];
			same[41] = ability[2];
			same[42] = ability[3];
			same[43] = ability[4];
			same[44] = ability[5];
			same[45] = ability[6];
			same[46] = ability[7];
			same[47] = ability[8];
			same[48] = ability[9];
			same[49] = Colored[0];
			same[50] = ulcer_lifes[5];
			same[51] = Colored[1];
			same[52] = Colored[2];
			same[53] = Colored[3];
			same[54] = Colored[4];
			same[55] = Colored[5];
			same[56] = Colored[6];
			same[57] = Colored[7];
			same[58] = Colored[8];
			same[59] = Colored[9];
			same[60] = ulcer_lifes[6];
			same[61] = ulcer_lifes[7];
			same[62] = ulcer_lifes[8];
			same[63] = ulcer_lifes[9];
			same[64] = opague;
			same[65] = number_[3];
			same[66] = number_[4];
			if (erd < 0) {	//int - unsigned int_Komplikationen
				for (unsigned int r=5; r>0; r-=1) {
					if (erd == -abs(r)) {
						same[67] = 10*r;
						break;
					}
				}
				
			} else {
				same[67] = erd;
			}
			same[68] = undead_duration;
			same[69] = figures;
			same[70] = allocation;
			same[71] = cards;
			same[72] = inverted;
			same[73] = addition;
			same[74] = intensity_minimum;
			same[75] = intensity_loss_per_line_multiplication;
			same[76] = direction;
			same[77] = assassin;
			same[78] = permutation_number_c;
			same[79] = permutation_number_b;
			same[80] = amount_of_permutation_number_c;
			same[81] = amount_of_permutation_number_b;
			
		} else if (same[0] == 1) {
			same[0] = 0;
			m = same[1];
			n = same[2];
			journey = same[3];
			tac = same[4];
			gamemode_played = same[5];
			fall_controll = same[6];
			turns_per_drop = same[7];
			speed_of_fall = same[8];
			count_freq = same[9];
			ulcer_lifes[1] = same[10];
			rain = same[11];
			rain_drops = same[12];
			rain_obj = same[13];
			rain_speed = same[14];
			opt = same[15];
			range = same[16];
			d_wert = same[17];
			limit_new = same[18];
			limit_at_all = same[19];
			ulcer_lifes[2] = same[20];
			points_for_win = same[21];
			freq = same[22];
			use_number = same[23];
			number_of_players = same[24];
			rtc = same[25];
			spf = same[26];
			scwhp = same[27];
			hboa = same[28];
			ttt = same[29];
			ulcer_lifes[3] = same[30];
			warning_system = same[31];
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
			Colored[0] = same[49];
			ulcer_lifes[5] = same[50];
			Colored[1] = same[51];
			Colored[2] = same[52];
			Colored[3] = same[53];
			Colored[4] = same[54];
			Colored[5] = same[55];
			Colored[6] = same[56];
			Colored[7] = same[57];
			Colored[8] = same[58];
			Colored[9] = same[59];
			ulcer_lifes[6] = same[60];
			ulcer_lifes[7] = same[61];
			ulcer_lifes[8] = same[62];
			ulcer_lifes[9] = same[63];
			opague = same[64];
			number_[3] = same[65];
			number_[4] = same[66];
			if (same[67] >= 10) {	//-1 --> 10, -2 --> 20, ...
				erd = -1 * (same[67]/10);
			} else {
				erd = same[67];
			}
			undead_duration = same[68];
			figures = same[69];
			allocation = same[70];
			cards = same[71];
			inverted = same[72];
			addition = same[73];
			intensity_minimum = same[74];
			intensity_loss_per_line_multiplication = same[75];
			direction = same[76];
			assassin = same[77];
			permutation_number_c = same[78];
			permutation_number_b = same[79];
			amount_of_permutation_number_c = same[80];
			amount_of_permutation_number_b = same[81];
			
			time3 = time(NULL);	//because of cards
			
		}
		
		// scanf("%u", &pause);	//test
		// printf("	#line 2k, after same \n");	//test
		
		Sf_nl_ = Spielfeld_Create(m, n, number_of_players);	//the order is (1, 2, 3) ==> [3][1][2]
		
		// scanf("%u", &pause);	//test
		// printf("	#line 2k, after Sf_nl \n");	//test
		
		Sf_od_ = Spielfeld_Create(m, n, number_of_players);
		
		// scanf("%u", &pause);	//test
		// printf("	#line 2k, after Sf_od \n");	//test
		// printf("	number_of_players: %u \n", number_of_players);	//test
		// printf("	m: %u \n", m);	//test
		// printf("	n: %u \n", n);	//test
		
		dynamic_pointer_save = int_2dim_Vektor_Create (number_of_players+1, 4);
		
		// scanf("%u", &pause);	//test
		// printf("	#line 2k, after dynamic_pointer_save \n");	//test
		
		Field_journey = Spielfeld_Create (m, n, number_of_players);	//gamemode_played 11 journey, done
		
		// scanf("%u", &pause);	//test
		// printf("	#line 2k, after Field_journey \n");	//test
		
		Sf_opague = Spielfeld_Create (m, n, 0);
		
		// scanf("%u", &pause);	//test
		// printf("	#line 2k, after Sf_opague \n");	//test
		
		Sf_allocation = Spielfeld_Create (m, n, number_of_players+2);
		
		// scanf("%u", &pause);	//test
		// printf("	#line 2k, after Sf_allocation \n");	//test
		
		Sf_permutations = Spielfeld_Create (m, n, 0);
		
		// scanf("%u", &pause);	//test
		// printf("	#line 2k, after Sf_permutations \n");	//test
		
		if (permutation_number_c == 0) {
			amount_of_permutation_number_c = 1;
		}
		Collector_of_permutation_number_c_areas = Spielfeld_Create (permutation_number_c, 2, amount_of_permutation_number_c-1);
		if (permutation_number_c == 0) {
			amount_of_permutation_number_c = 0;
		}
		
		// scanf("%u", &pause);	//test
		// printf("	#line 2k, between the Collectors \n");	//test
		
		if (permutation_number_b == 0) {
			amount_of_permutation_number_b = 1;
		}
		Collector_of_permutation_number_b_areas = Spielfeld_Create (permutation_number_b, 2, amount_of_permutation_number_b-1);
		if (permutation_number_b == 0) {
			amount_of_permutation_number_b = 0;
		}
		
		// scanf("%u", &pause);	//test
		// printf("	#line 2k, before Field \n");	//test
		
		Field = Spielfeld_Create (m, n, number_of_players);
		
		// scanf("%u", &pause);	//test
		// printf("	#line 2k, before start_normal \n");	//test
		
		start_normal (Field, m, n, gamemode_played, number_of_players, geben, Sf_opague, Sf_allocation, allocation, inverted);
		
		// show_field (Sf_permutations, Sf_opague, Field, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);	//test
		
		if (allocation != 0) {
			for (unsigned int i=1; i<=m-2; i++) {
				for (unsigned int j=1; j<=n-2; j++) {
					if ((Field[0][i][j] != 0)&&(Field[0][i][j] <= number_of_players)) {
						set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Sf_allocation, 0, i, j, 1);
					}
				}
			}
		}
		
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
			
			printf("	Zeitdifferenz12: %f \n", time_saver);	//test
			scanf("%lf", &time_saver);
			
			lim = 0;
			unsigned int c = 0;
			unsigned int x = 0;
			while (lim == 0) {
				c += 1;
				if ((time_saver) <= 1.0*c) {
					lim = (c%6)+1;
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
					stack_of_[p][((((lim+(((9+p*q)/10)%6)+1)%6)+1)*(((x+q/2)%6)+1))%7][0] += 1;
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
			lim = 0;
			time1 = 0;
			time2 = 0;
			time3 = 0;
			time_saver = 0.0;
		}
		
		if ((amount_of_permutation_number_b != 0)||(amount_of_permutation_number_c != 0)) {
			translate_permutations_amounts_to_permutations_areas (Sf_permutations, m, n, permutation_number_c, permutation_number_b, amount_of_permutation_number_c, amount_of_permutation_number_b, Collector_of_permutation_number_c_areas, Collector_of_permutation_number_b_areas);
			
			// scanf("%u", &pause);	//test
			// printf("	#line 2k, after translate_permutations_amounts_to_permutations_areas \n");	//test
		
			// show_field (Sf_permutations, Sf_opague, Sf_permutations, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);	//test
		}
		
		//start of playing/the first print of a field
		
		if (gamemode_played == Rain) {
			show_field (Sf_permutations, Sf_opague, Field, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
		}
		
		// scanf("%u", &pause);	//test
		// printf("	#line 2k, before count_freq \n");	//test
		
		count_freq = 1;
		
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
		
		// scanf("%u", &pause);	//test
		// printf("	#line 3007, before limit_at_all_saver \n");	//test
		
		limit_at_all_saver = limit_at_all;
		
		if ((gamemode_played == Ulcer)||(gamemode_played == Dynamic)||(gamemode_played == Survive)||(gamemode_played == Sand)) {
			information_code[0] = number_of_players;
		}
		
		unsigned int g, survive_different;	//its time to play
		g = 1;
		survive_different = 0;
		
		if (gamemode_played == Survive) {
			while ((survive_different == 0)||(survive_different > 60)){
				printf("	Please give me a number between 1 and 60. \n");
				survive_different = get_unsigned_numeric_input_with_not_more_than_2_letters ();
			}
		}
		
		// scanf("%u", &pause);	//test
		// printf("	#line 3021, before while \n");	//test
		
		while (g != 0){
			Spielfeld temp;
			
			zeitgewinner = 0;
			boost_hunt_activator = 0;
			einmal = 0;
			
			if (player_counter == number_of_players) {	//Notbremse
				break;
			}
			
			if (gamemode_played == Dynamic) {
				controll = 0;
				for (unsigned int i=1; i<m-1; i+=1) {
					for (unsigned int j=1; j<n-1; j+=1) {
						if (Field[0][i][j] == 77) {
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
				
			}
			
			if (ttt != 0) {
				time_warning = 0.0;
				time_saver = 0.0;
			}
			
			geben = ((g-1)%number_of_players)+1;
			
			// scanf("%u", &pause);	//test
			// printf("	#line 1989, after geben-def \n");	//test
			
			/* printf("	test \n");
			show_field (Sf_permutations, Sf_opague, Field, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);	//test
			printf("	test \n"); */
			round_counter_before = round_counter;
			round_counter = 0;
			for (unsigned int p=1; p<=g; p+=number_of_players) {
				round_counter += 1;
			}
			if ((gamemode_played == Survive)&&(round_counter == round_counter_before+1)) {
				
				//printf("in the obstacles-generator \n");	//test
				
				if ((round_counter % 5 == 0)&&(information_code[3] >= 1)) {	//delete Waves
					for (unsigned int i=1; i<m-1; i+=1){
						for (unsigned int j=1; j<n-1; j+=1){
							if (Field[0][i][j] == Waves) {
								set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j, 0);
							}
						}
					}
				}
				
				if (opague >= 1) {
					opague_builder (Field, Sf_opague, m, n, geben%number_of_players, opague, AOP, Sf_allocation, allocation, number_of_players);
					show_field (Sf_permutations, Sf_opague, Sf_opague, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
				} else {
					show_field (Sf_permutations, Sf_opague, Field, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
				}
				
				for (unsigned int i=1; i<m-1; i+=1){
					for (unsigned int j=1; j<n-1; j+=1){
						
						if (information_code[2] >= 1) {	//Bombs
							if (Field[0][i][j] == Bomb_4) {
								set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j, Bomb_3);
							} else if (Field[0][i][j] == Bomb_3) {
								set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j, Bomb_2);
							} else if (Field[0][i][j] == Bomb_2) {
								set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j, Bomb_1);
							} else if (Field[0][i][j] == Bomb_1) {
								for (unsigned int h=i-1; h<=i+1; h+=1){
									for (unsigned int k=j-1; k<=j+1; k+=1){
										if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
											set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, h, k, 0);
										}
									}
								}
							}
						}
						if (information_code[3] >= 1) {	//Waves
							if (((Field[0][i-1][j] == Waves)&&(Field[0][i+1][j] != Waves)&&(Field[0][i][j+1] != Waves)&&(Field[0][i][j-1] != Waves))||((Field[0][i-1][j] != Waves)&&(Field[0][i+1][j] == Waves)&&(Field[0][i][j+1] != Waves)&&(Field[0][i][j-1] != Waves))||((Field[0][i-1][j] != Waves)&&(Field[0][i+1][j] != Waves)&&(Field[0][i][j+1] == Waves)&&(Field[0][i][j-1] != Waves))||((Field[0][i-1][j] != Waves)&&(Field[0][i+1][j] != Waves)&&(Field[0][i][j+1] != Waves)&&(Field[0][i][j-1] == Waves))) {
								set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j, Waves_new);
							}
						}
					}
				}
				
				for (unsigned int i=1; i<m-1; i+=1){
					for (unsigned int j=1; j<n-1; j+=1){
						if (Field[0][i][j] == Waves) {
							set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j, 0);
						}
					}
				}
				for (unsigned int i=1; i<m-1; i+=1){
					for (unsigned int j=1; j<n-1; j+=1){
						if (Field[0][i][j] == Waves_new) {
							set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j, Waves);
						}
					}
				}
				
				if ((round_counter % 5 == 0)&&(information_code[1] >= 1)) {	//Traps amount per round
					information_code[1] += 1;
				}
				if ((round_counter % 10 == 0)&&(information_code[2] >= 1)) {	//Bombs amount per round
					information_code[2] += 1;
				}
				if ((round_counter % 15 == 0)&&(information_code[3] >= 1)) {	//Waves amount per 5 rounds
					information_code[3] += 1;
				}
				
				if ((round_counter % 5 == 1)&&(information_code[3] >= 1)) {	//new Waves
					for (unsigned int p=1; p<=information_code[3]; p+=1) {
						unsigned int i;
						unsigned int j;
						i = ((survive_different%10)+ges[1]+ges[3]+ges[5]+ges[7]+ges[9]+var_[2]+var_[4]+var_[6]+var_[8]+Colored[1]+Colored[3]+Colored[5]+Colored[7]+Colored[9]+7*p+g+2*use_number+tac)%(m-2) + 1;
						j = ((survive_different%6)+ges[2]+ges[4]+ges[6]+ges[8]+var_[1]+var_[3]+var_[5]+var_[7]+var_[9]+Colored[0]+Colored[2]+Colored[4]+Colored[6]+Colored[8]+11*p+g+3*use_number+ttt)%(n-2) + 1;
						set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j, Waves);
					}
				}
				if (information_code[1] >= 1) {	//new Traps
					for (unsigned int p=1; p<=information_code[1]; p+=1) {
						unsigned int i;
						unsigned int j;
						i = ((survive_different%5)+ges[1]+ges[3]+ges[5]+ges[7]+ges[9]+var_[2]+var_[4]+var_[6]+var_[8]+Colored[1]+Colored[3]+Colored[5]+Colored[7]+Colored[9]+3*p+g+use_number+tac)%(m-2) + 1;
						j = ((survive_different%12)+ges[2]+ges[4]+ges[6]+ges[8]+var_[1]+var_[3]+var_[5]+var_[7]+var_[9]+Colored[0]+Colored[2]+Colored[4]+Colored[6]+Colored[8]+6*p+g+2*use_number+ttt)%(n-2) + 1;
						set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j, Traps);
					}
				}
				if (information_code[2] >= 1) {	//new Bombs
					for (unsigned int p=1; p<=information_code[2]; p+=1) {
						unsigned int i;
						unsigned int j;
						i = ((survive_different%15)+ges[1]+ges[3]+ges[5]+ges[7]+ges[9]+var_[2]+var_[4]+var_[6]+var_[8]+Colored[1]+Colored[3]+Colored[5]+Colored[7]+Colored[9]+8*p+g+3*use_number+tac)%(m-2) + 1;
						j = ((survive_different%4)+ges[2]+ges[4]+ges[6]+ges[8]+var_[1]+var_[3]+var_[5]+var_[7]+var_[9]+Colored[0]+Colored[2]+Colored[4]+Colored[6]+Colored[8]+5*p+g+use_number+ttt)%(n-2) + 1;
						set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j, Bomb_4);
					}
				}
				
			}
			
			if ((gamemode_played == Dynamic)&&((g-1)%number_of_players == 0)&&(var_[1] != 1010)) {	//Object-77 movement
				
				if (opague >= 1) {
					opague_builder (Field, Sf_opague, m, n, geben, opague, AOP, Sf_allocation, allocation, number_of_players);
					show_field (Sf_permutations, Sf_opague, Sf_opague, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
				} else {
					show_field (Sf_permutations, Sf_opague, Field, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
				}
				
				dynamic_pointer[6] = 0;		//impact y_horizontal
				dynamic_pointer[7] = 0;		//impact y_vertikal
				
				dynamic_pointer[Horizontal] = dynamic_pointer[4] + dynamic_pointer[2];	//aus "sgn(a)*a^2" mach "a", done
				dynamic_pointer[Vertikal] = dynamic_pointer[5] + dynamic_pointer[3];
				
				dynamic_pointer[2] += dynamic_pointer[4];
				dynamic_pointer[3] += dynamic_pointer[5];
				
				impact_y_semi_square (m, n, position, d_wert, range, dynamic_pointer, Field);
				
				dynamic_pointer[4] += dynamic_pointer[6];
				dynamic_pointer[5] += dynamic_pointer[7] + erd;
				
				while (abs(dynamic_pointer[Vertikal])+abs(dynamic_pointer[Horizontal]) != 0){
					
					// printf("	Test-print \n");
					// show_field (Sf_permutations, Sf_opague, Field, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);		//test
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
					
					player_counter = dynamic_take_out (position, number_of_players, Field, ges, player_counter, m, n, Sf_opague, Sf_allocation, allocation, geben);
					
					indikator1 = 0;		
					indikator2 = 0;		//Staffelung: grösser im Betrag 1, anderer nur geblockt 3, anderer reflektiert 5, anderer Null-Betrag 5		3 und 5 und 5 schließen sich aus
					
					controll = 0;
					
					if (abs(dynamic_pointer[Horizontal])>abs(dynamic_pointer[Vertikal])) {	//indikator1, position[Horizontal], dynamic_pointer[Horizontal] horizontal
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
									
									Field[0][position[Vertikal] +1][position[Horizontal] +1] = 77;
									Field[0][position[Vertikal]][position[Horizontal]] = 0;
									position[Vertikal] += 1;
									position[Horizontal] += 1;
									dynamic_pointer[Horizontal] -= 1;
									dynamic_pointer[Vertikal] -= 1;
									
								} else if ((position[Horizontal] +1 >= n-1) && (position[Vertikal] +1 >= m-1)) { //beide nein
									
									Reflection (dynamic_pointer, 0, erd);
									Reflection (dynamic_pointer, 1, erd);
									
									continue;
									
								} else if (position[Horizontal]+1 >= n-1) {	//horizontal nein
									
									Reflection (dynamic_pointer, 0, erd);
									
									continue;
									
								} else if (position[Vertikal]+1 >= m-1) {	//vertikal nein
									
									Reflection (dynamic_pointer, 1, erd);
									
									continue;
									
								} else {
									indikator3 = 1;
									continue;
								}
								
							} else if (sgn(dynamic_pointer[Horizontal])<0) {	//Vorzeichen negativ
								
								if ((position[Horizontal]-1 > 0) && (position[Vertikal]-1 > 0) && (Field[0][position[Vertikal]-1][position[Horizontal]-1] == 0)) {	//Noch im Spielfeld? Ja und diagonal ist frei
									
									Field[0][position[Vertikal]-1][position[Horizontal]-1] = 77;
									Field[0][position[Vertikal]][position[Horizontal]] = 0;
									position[Vertikal] -= 1;
									position[Horizontal] -= 1;
									dynamic_pointer[Horizontal] += 1;
									dynamic_pointer[Vertikal] += 1;
									
								} else if ((position[Horizontal]-1 == 0) && (position[Vertikal]-1 == 0)) { //beide nein
									
									Reflection (dynamic_pointer, 0, erd);
									Reflection (dynamic_pointer, 1, erd);
									
									continue;
									
								} else if (position[Horizontal]-1 == 0) {	//horizontal nein
									
									Reflection (dynamic_pointer, 0, erd);
									
									continue;
									
								} else if (position[Vertikal]-1 == 0) {	//vertikal nein
									
									Reflection (dynamic_pointer, 1, erd);
									
									continue;
									
								} else {
									indikator3 = 1;
									continue;
								}
								
							}
							
						} else {	//unterschiedliches Vorzeichen
							
							if (sgn(dynamic_pointer[Horizontal])>0) {	//Vorzeichen horizontal positiv
							
								if ((position[Horizontal]+1 < n-1) && (position[Vertikal]-1 > 0) && (Field[0][position[Vertikal]-1][position[Horizontal]+1] == 0)) {	//Noch im Spielfeld? Ja und diagonal ist frei
									
									Field[0][position[Vertikal]-1][position[Horizontal]+1] = 77;
									Field[0][position[Vertikal]][position[Horizontal]] = 0;
									position[Vertikal] -= 1;
									position[Horizontal] += 1;
									dynamic_pointer[Horizontal] -= 1;
									dynamic_pointer[Vertikal] += 1;
									
								} else if ((position[Horizontal]+1 >= n-1) && (position[Vertikal]-1 == 0)) { //beide nein
									
									Reflection (dynamic_pointer, 0, erd);
									Reflection (dynamic_pointer, 1, erd);
									
									continue;
									
								} else if (position[Horizontal]+1 >= n-1) {	//horizontal nein
									
									Reflection (dynamic_pointer, 0, erd);
									
									continue;
									
								} else if (position[Vertikal]-1 == 0) {	//vertikal nein
									
									Reflection (dynamic_pointer, 1, erd);
									
									continue;
									
								} else {
									indikator3 = 1;
									continue;
								}
								
							}  else if (sgn(dynamic_pointer[Horizontal])<0) {	//Vorzeichen horizontal negativ
								
								if ((position[Horizontal]-1 > 0) && (position[Vertikal]+1 < m-1) && (Field[0][position[Vertikal]+1][position[Horizontal]-1] == 0)) {	//Noch im Spielfeld? Ja und diagonal ist frei
									
									Field[0][position[Vertikal]+1][position[Horizontal]-1] = 77;
									Field[0][position[Vertikal]][position[Horizontal]] = 0;
									position[Vertikal] += 1;
									position[Horizontal] -= 1;
									dynamic_pointer[Horizontal] += 1;
									dynamic_pointer[Vertikal] -= 1;
									
								} else if ((position[Horizontal]-1 == 0) && (position[Vertikal]+1 >= m-1)) { //beide nein
									
									Reflection (dynamic_pointer, 0, erd);
									Reflection (dynamic_pointer, 1, erd);
									
									continue;
									
								} else if (position[Horizontal] -1 == 0) {	//horizontal nein
									
									Reflection (dynamic_pointer, 0, erd);
									
									continue;
									
								} else if (position[Vertikal] +1 >= m-1) {	//vertikal nein
									
									Reflection (dynamic_pointer, 1, erd);
									
									continue;
									
								} else {
									indikator3 = 1;
									continue;
								}
								
							} 
							
						}
						
					} else if (indikator1 >= indikator2) {	//partielle Durchführung, außer bei doppelter Reflektion, nimm s_horizontal = dynamic_pointer[Horizontal]
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
									Field[0][position[Vertikal]][r] = Field[0][position[Vertikal]][r-1];
								}
								Field[0][position[Vertikal]][position[Horizontal]] = 0;
								position[Horizontal] += 1;
								dynamic_pointer[Horizontal] -= 1;
								dynamic_pointer[2] -= 1;
								dynamic_pointer[4] -= 1;
								
								if (dynamic_pointer[Horizontal] != 0) {
									dynamic_pointer[Horizontal] -= 1;
								}
								
							} else if (sgn(dynamic_pointer[Horizontal])<0) {
								for (unsigned int r=space_j; r<position[Horizontal]; r+=1) {
									Field[0][position[Vertikal]][r] = Field[0][position[Vertikal]][r+1];
								}
								Field[0][position[Vertikal]][position[Horizontal]] = 0;
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
								
								Field[0][position[Vertikal]][position[Horizontal]+1] = 77;
								Field[0][position[Vertikal]][position[Horizontal]] = 0;
								dynamic_pointer[Horizontal] -= 1;
								position[Horizontal] += 1;
								
							} else if (sgn(dynamic_pointer[Horizontal])<0) {
								
								Field[0][position[Vertikal]][position[Horizontal]-1] = 77;
								Field[0][position[Vertikal]][position[Horizontal]] = 0;
								dynamic_pointer[Horizontal] += 1;
								position[Horizontal] -= 1;
							
							}		//Diagonal-Schritt mit partieller Reflection entzieht sich dem freien Schritt
						}
						
					} else if (indikator2 >= indikator1) {	//partielle Durchführung, außer bei doppelter Reflektion, nimm s_vertikal = dynamic_pointer[Vertikal]
						if (indikator1 >= 5) {
							
							if (abs(dynamic_pointer[Horizontal]) > 0) {
								Reflection (dynamic_pointer, 0, erd);
							}
							if (abs(dynamic_pointer[Vertikal]) > 0) {
								Reflection (dynamic_pointer, 1, erd);
							}
							/*
							printf("	\n");	//test
							printf("	indikator1: %u \n", indikator1);
							printf("	indikator2: %u \n", indikator2);
							printf("	sgn(dynamic_pointer[Horizontal]): %d \n", sgn(dynamic_pointer[Horizontal]));
							printf("	sgn(dynamic_pointer[Vertikal]): %d \n", sgn(dynamic_pointer[Vertikal]));
							printf("	position[Horizontal]: %u \n", position[Horizontal]);
							printf("	position[Vertikal]: %u \n", position[Vertikal]);
							
							printf("	\n");
							printf("	Object position: (%u, %u) \n", position[Vertikal], position[Horizontal]);
							printf("	Weg s: (%d, %d) \n", dynamic_pointer[Vertikal], dynamic_pointer[Horizontal]);
							printf("	Geschw. v: (%d, %d) \n", dynamic_pointer[3], dynamic_pointer[2]);
							printf("	Beschl. a: (%d, %d) \n", dynamic_pointer[5], dynamic_pointer[4]);
							printf("	Impact  y(+erd): (%d, %d) \n", dynamic_pointer[7]+erd, dynamic_pointer[6]);
							printf("	######\n");
							printf("	\n");
							//*/
							continue;
							
						} else if (indikator1 >= 3) {	//moveable crash, um Reflection zu verhindern
							
							if (sgn(dynamic_pointer[Vertikal])>0) {
								for (unsigned int r=space_i; r>position[Vertikal]; r-=1) {
									Field[0][r][position[Horizontal]] = Field[0][r-1][position[Horizontal]];
								}
								Field[0][position[Vertikal]][position[Horizontal]] = 0;
								position[Vertikal] += 1;
								dynamic_pointer[Vertikal] -= 1;
								dynamic_pointer[3] -= 1;
								dynamic_pointer[5] -= 1;
								
								if (dynamic_pointer[Vertikal] != 0) {
									dynamic_pointer[Vertikal] -= 1;
								}
								
							} else if (sgn(dynamic_pointer[Vertikal])<0) {
								for (unsigned int r=space_i; r<position[Vertikal]; r+=1) {
									Field[0][r][position[Horizontal]] = Field[0][r+1][position[Horizontal]];
								}
								Field[0][position[Vertikal]][position[Horizontal]] = 0;
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
								
								Field[0][position[Vertikal]+1][position[Horizontal]] = 77;
								Field[0][position[Vertikal]][position[Horizontal]] = 0;
								dynamic_pointer[Vertikal] -= 1;
								position[Vertikal] += 1;
								
							} else if (sgn(dynamic_pointer[Vertikal])<0) {
								
								Field[0][position[Vertikal]-1][position[Horizontal]] = 77;
								Field[0][position[Vertikal]][position[Horizontal]] = 0;
								dynamic_pointer[Vertikal] += 1;
								position[Vertikal] -= 1;
								
							}
						}
						
					}
					
					player_counter = dynamic_take_out (position, number_of_players, Field, ges, player_counter, m, n, Sf_opague, Sf_allocation, allocation, geben);
					
					if ((abs(dynamic_pointer[Vertikal])+abs(dynamic_pointer[Horizontal])) == 0) {
						
						/*
						printf("	\n");	//test
						printf("	Object position: (%u, %u) \n", position[Vertikal], position[Horizontal]);
						printf("	Weg s: (%d, %d) \n", dynamic_pointer[Vertikal], dynamic_pointer[Horizontal]);
						printf("	Geschw. v: (%d, %d) \n", dynamic_pointer[3], dynamic_pointer[2]);
						printf("	Beschl. a: (%d, %d) \n", dynamic_pointer[5], dynamic_pointer[4]);
						printf("	Impact  y(+erd): (%d, %d) \n", dynamic_pointer[7]+erd, dynamic_pointer[6]);
						printf("	bbbbbbb\n");
						//*/
						break;
					}
					
					indikator3 = 0;
					
					//Feintuning
					
					dynamic_pointer[6] = 0;		//impact y_horizontal
					dynamic_pointer[7] = 0;		//impact y_vertikal
					
					impact_y_semi_square (m, n, position, d_wert, range, dynamic_pointer, Field);
					
					if (sgn(dynamic_pointer[2]) < 0) {		//horizontal (ohne erd)
						if (sgn(dynamic_pointer[6]) > 0) {
							for (int r=1; r<=abs(erd); r+=1) {
								dynamic_pointer[2] += 1;
								if (dynamic_pointer[2] == 0) {
									break;
								}
							}
						}
					} else if (sgn(dynamic_pointer[2]) > 0) {		//dynamic_pointer[2] = v_horizontal
						if (sgn(dynamic_pointer[6]) < 0) {
							for (int r=1; r<=abs(erd); r+=1) {
								dynamic_pointer[2] -= 1;
								if (dynamic_pointer[2] == 0) {
									break;
								}
							}
						}
					}
					
					if (sgn(dynamic_pointer[4]) < 0) {		//horizontal (ohne erd)
						if (sgn(dynamic_pointer[6]) > 0) {
							for (int r=1; r<=abs(erd); r+=1) {
								dynamic_pointer[4] += 1;
								if (dynamic_pointer[4] == 0) {
									break;
								}
							}
							
							if ((abs(dynamic_pointer[4]) < abs(dynamic_pointer[6])) && (sgn(dynamic_pointer[4]) == sgn(dynamic_pointer[Horizontal]))&&(sgn(dynamic_pointer[Horizontal]) != 0)) {	//s_horizontal-Verringerung
								
								for (int r=1; r<=(abs(dynamic_pointer[6])-abs(dynamic_pointer[4])); r+=1) {
									dynamic_pointer[Horizontal] += 1;
									if (dynamic_pointer[Horizontal] == 0) {
										break;
									}
								}
							}
						}
						
					} else if (sgn(dynamic_pointer[4]) > 0) {		//dynamic_pointer[4] = a_horizontal
						if (sgn(dynamic_pointer[6]) < 0) {
							for (int r=1; r<=abs(erd); r+=1) {
								dynamic_pointer[4] -= 1;
								if (dynamic_pointer[4] == 0) {
									break;
								}
							}
							
							if ((abs(dynamic_pointer[4]) < abs(dynamic_pointer[6])) && (sgn(dynamic_pointer[4]) == sgn(dynamic_pointer[Horizontal]))&&(sgn(dynamic_pointer[Horizontal]) != 0)) {
								
								for (int r=1; r<=(abs(dynamic_pointer[6])-abs(dynamic_pointer[4])); r+=1) {	//s_horizontal-Verringerung
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
								
								for (int r=1; r<=(abs(dynamic_pointer[6])-abs(dynamic_pointer[4])); r+=1) {	//s_horizontal-Verringerung
									dynamic_pointer[Horizontal] -= 1;
									if (dynamic_pointer[Horizontal] == 0) {
										break;
									}
								}
							}
							
						} else if (sgn(dynamic_pointer[6]) > sgn(dynamic_pointer[2])) {
							
							if ((0 < abs(dynamic_pointer[6])) && (sgn(dynamic_pointer[2]) == sgn(dynamic_pointer[Horizontal]))) {	//s_horizontal-Verringerung
								
								for (int r=1; r<=(abs(dynamic_pointer[6])-abs(dynamic_pointer[4])); r+=1) {
									dynamic_pointer[Horizontal] += 1;
									if (dynamic_pointer[Horizontal] == 0) {
										break;
									}
								}
							}
						}
						
					}
					
					
					
					
					if (sgn(dynamic_pointer[3] < 0)) {		//vertikal (mit erd)
						if (sgn(dynamic_pointer[7]+erd) > 0) {
							for (int r=1; r<=abs(erd); r+=1) {
								dynamic_pointer[3] += 1;
								if (dynamic_pointer[3] == 0) {
									break;
								}
							}
						}
					} else if (sgn(dynamic_pointer[3] > 0)) {		//dynamic_pointer[3] = v_vertikal
						if (sgn(dynamic_pointer[7]+erd) < 0) {	//<= wegen-erd-Kompensierung, zurückgenommen wegen eventuell negativer erd
							for (int r=1; r<=abs(erd); r+=1) {
								dynamic_pointer[3] -= 1;
								if (dynamic_pointer[3] == 0) {
									break;
								}
							}
						}
					}
					
					if (sgn(dynamic_pointer[5] < 0)) {		//vertikal (mit erd)
						if (sgn(dynamic_pointer[7]+erd) > 0) {
							for (int r=1; r<=abs(erd); r+=1) {
								dynamic_pointer[5] += 1;
								if (dynamic_pointer[5] == 0) {
									break;
								}
							}
							
							if ((abs(dynamic_pointer[5]) < abs(dynamic_pointer[7]+erd))&&(sgn(dynamic_pointer[5]) == sgn(dynamic_pointer[Vertikal]))&&(sgn(dynamic_pointer[Vertikal]) != 0)) {	//s_vertikal-Verringerung
								
								for (int r=1; r<=(abs(dynamic_pointer[7]+erd)-abs(dynamic_pointer[5])); r+=1) {
									dynamic_pointer[Vertikal] += 1;
									if (dynamic_pointer[Vertikal] == 0) {
										break;
									}
								}
							}
						}
						
					} else if (sgn(dynamic_pointer[5]) > 0) {		//dynamic_pointer[5] = a_vertikal
						if (sgn(dynamic_pointer[7]+erd) < 0) {	//<= wegen-erd-Kompensierung, zurückgenommen wegen eventuell negativer erd
							for (int r=1; r<=abs(erd); r+=1) {
								dynamic_pointer[5] -= 1;
								if (dynamic_pointer[5] == 0) {
									break;
								}
							}
							
							if ((abs(dynamic_pointer[5]) < abs(dynamic_pointer[7]+erd)) && (sgn(dynamic_pointer[5]) == sgn(dynamic_pointer[Vertikal]))&&(sgn(dynamic_pointer[Vertikal]) != 0)) {
								
								for (int r=1; r<=(abs(dynamic_pointer[7]+erd)-abs(dynamic_pointer[5])); r+=1) {	//s_vertikal-Verringerung
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
								
								for (int r=1; r<=(abs(dynamic_pointer[7]+erd)-abs(dynamic_pointer[5])); r+=1) {	//s_vertikal-Verringerung
									dynamic_pointer[Vertikal] -= 1;
									if (dynamic_pointer[Vertikal] == 0) {
										break;
									}
								}
							}
							
						} else if (sgn(dynamic_pointer[7]+erd) > sgn(dynamic_pointer[3])) {
							
							if ((0 < abs(dynamic_pointer[7]+erd)) && (sgn(dynamic_pointer[3]) == sgn(dynamic_pointer[Vertikal]))) {	//s_vertikal-Verringerung
								
								for (int r=1; r<=(abs(dynamic_pointer[7]+erd)-abs(dynamic_pointer[5])); r+=1) {
									dynamic_pointer[Vertikal] += 1;
									if (dynamic_pointer[Vertikal] == 0) {
										break;
									}
								}
							}
						}
						
					}
					
					if ((sgn(dynamic_pointer[Horizontal]) > 0)&&(sgn(dynamic_pointer[2]) >= 0)&&(sgn(dynamic_pointer[4]) < 0)) {		//a_horizontal-verringerung
						dynamic_pointer[4] += 1;
					} else if ((sgn(dynamic_pointer[Horizontal]) < 0)&&(sgn(dynamic_pointer[2]) <= 0)&&(sgn(dynamic_pointer[4]) > 0)) {
						dynamic_pointer[4] -= 1;
					}
					
					if ((sgn(dynamic_pointer[Vertikal]) > 0)&&(sgn(dynamic_pointer[3]) >= 0)&&(sgn(dynamic_pointer[5]) < 0)) {		//a_vertikal-verringerung
						dynamic_pointer[5] += 1;
					} else if ((sgn(dynamic_pointer[Vertikal]) < 0)&&(sgn(dynamic_pointer[3]) <= 0)&&(sgn(dynamic_pointer[5]) > 0)) {
						dynamic_pointer[5] -= 1;
					}
					
					/*
					printf("	\n");	//test
					printf("	indikator1: %u \n", indikator1);
					printf("	indikator2: %u \n", indikator2);
					printf("	sgn(dynamic_pointer[Horizontal]): %d \n", sgn(dynamic_pointer[Horizontal]));
					printf("	sgn(dynamic_pointer[Vertikal]): %d \n", sgn(dynamic_pointer[Vertikal]));
					printf("	position[Horizontal]: %u \n", position[Horizontal]);
					printf("	position[Vertikal]: %u \n", position[Vertikal]);
					
					printf("	\n");
					printf("	Object position: (%u, %u) \n", position[Vertikal], position[Horizontal]);
					printf("	Weg s: (%d, %d) \n", dynamic_pointer[Vertikal], dynamic_pointer[Horizontal]);
					printf("	Geschw. v: (%d, %d) \n", dynamic_pointer[3], dynamic_pointer[2]);
					printf("	Beschl. a: (%d, %d) \n", dynamic_pointer[5], dynamic_pointer[4]);
					printf("	Impact  y(+erd): (%d, %d) \n", dynamic_pointer[7]+erd, dynamic_pointer[6]);
					printf("	\n");
					printf("	\n");
					*/
					
						//beschleunigung abbremsen, falls sgn(s)==sgn(v)!=sgn(a), done
					
				}	//komplette durchrechnung
				
			}
			
			// scanf("%u", &pause);	//test
			// printf("	#line 4494, komplette durchrechnung \n");	//test
			
			if (gamemode_played == Dynamic) {	//Ausscheiden der Teams?
				
				player_counter = dynamic_take_out (position, number_of_players, Field, ges, player_counter, m, n, Sf_opague, Sf_allocation, allocation, geben);
				
			}
			
			if (gamemode_played == Hunt) {	//Hunt-Formalitäten
				/* test
				printf("\n");
				printf("	hboa=%u	\n", hboa);
				printf("\n");
				*/
				if (hboa == 0) {
					information_code[2] = 2;
				} else if (hboa == 1) {
					information_code[2] = 1;
				}
				
				if (round_counter == (rtc - 1)) {
					numbers_of_[geben][0][0] = 1;
				} else if ((round_counter == rtc)&&(geben == number_of_players)) {
					printf(" \n ");
					printf(" \n ");
					printf(" Ready for the last round? \n ");
					printf(" \n ");
					printf(" \n ");
				}
				
				if (round_counter%spf == 0) {
					information_code[1] = 1;
				} else {
					information_code[1] = 0;
				}
			}
			
			if ((gamemode_played == Arena)||(gamemode_played == Ulcer)) {	//last round
				if ((round_counter == rtp)&&(geben == number_of_players)) {
					printf(" \n ");
					printf(" \n ");
					printf(" Ready for the last round? \n ");
					printf(" \n ");
					printf(" \n ");
				}
			}
			
			/* test
			printf("\n");
			printf("	information_code: [0]=%u,	[1]=%u,	[2]=%u,	[3]=%u	\n", information_code[0], information_code[1], information_code[2], information_code[3]);
			printf("\n");
			*/
			
			printf("\n");
			printf("	Round: %u \n", round_counter);
			printf("\n");
			
			//previous if(geben == 1){}
			
			if (opague >= 1) {
				opague_builder (Field, Sf_opague, m, n, geben, opague, AOP, Sf_allocation, allocation, number_of_players);
			}
			
			if ((ttt != 0)&&(pere[geben] == 100)) {
				g+=1;
				continue;
			}
			
			if ((ges[geben] == 1010*geben)&&((gamemode_played == Hunt)||(gamemode_played == Arena)||(gamemode_played == Ulcer)||(gamemode_played == Dynamic)||(gamemode_played == Survive)||(gamemode_played == Sand))) {	//mehr-gamemode_played	//Überspringen, wenn ausgeschieden
				
				all_turns_correction += 1;
				var_[geben] = 1010*geben;		//eigentlich var_[geben] = 1010*geben, done
				for (unsigned int i=1; i<m-1; i+=1){
					for (unsigned int j=1; j<n-1; j+=1){
						if (journey == 1){
							for (unsigned int p=1; p<=number_of_players; p+=1) {
								if (Field_journey[p][i][j] == geben) {
									set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field_journey, p, i, j, 0);
								}
							}
							set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field_journey, geben, i, j, Field_journey[Vorganger(geben, number_of_players)][i][j]);
						}
						
						set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, geben, i, j, Field[Vorganger(geben, number_of_players)][i][j]);
						cons[geben] = cons[Vorganger(geben, number_of_players)];
						
						if (gamemode_played == Dynamic){
							for (unsigned int p=2; p<=5; p+=1) {
								dynamic_pointer_save[Vorganger(geben, number_of_players)][p-2] = dynamic_pointer_save[geben][p-2]; // if geben == 1 => number_of_players, sonst geben-1	(maybe a function), done
							}
						}
						
					}
				}
				if (var_[0] == 1) {	//if "go back" is used
					g-=1;
					all_turns_correction -= 1;
				} else {
					g+=1;
				}
				continue;
			}
			
			if ((gamemode_played == Ulcer)&&(ulcer_start[geben] == missing)) {
				
				all_turns_correction += 1;
				
				if (var_[0] == 1) {	//if "go back" is used
					g-=1;
					all_turns_correction -= 1;
					var_[geben] = 1010*geben;
				} else {
					g+=1;
				}
				continue;
			}
			
			if ((journey == 1)&&((gamemode_played == Classic)||(gamemode_played == Collect)||(gamemode_played == Contact))){	//journey-frequence
				printf("	All turns until the journey starts: %u \n", (19 - ((g-1)%19)));
				printf("\n");
			} else if ((journey == 1)&&((gamemode_played == Fight)||(gamemode_played == Rain))) {
				printf("	All turns until the journey starts: %u \n", (15 - ((g-1)%15)));
				printf("\n");
			} else if ((journey == 1)&&(gamemode_played == Race)) {
				printf("	All turns until the journey starts: %u \n", ((2*freq) - ((g-1)%(2*freq))));
				printf("\n");
			} else if ((journey == 1)&&((gamemode_played == Hunt)||(gamemode_played == Arena)||(gamemode_played == Ulcer)||(gamemode_played == Dynamic)||(gamemode_played == Survive)||(gamemode_played == Sand))) {	//mehr-gamemode_played
				printf("	All turns until the journey starts: %u \n", ((10*(number_of_players - player_counter) - 1) - ((g-all_turns_correction-1)%(10*(number_of_players - player_counter) - 1))));
				printf("\n");
			}
			
			if ((intensity_loss_per_line_multiplication != 0)&&((gamemode_played == Classic)||(gamemode_played == Collect)||(gamemode_played == Contact))){	//projection-frequence
				printf("	All turns until the projection starts: %u \n", (17 - ((g-1)%17)));
				printf("\n");
			} else if ((intensity_loss_per_line_multiplication != 0)&&((gamemode_played == Fight)||(gamemode_played == Rain))) {
				printf("	All turns until the projection starts: %u \n", (13 - ((g-1)%13)));
				printf("\n");
			} else if ((intensity_loss_per_line_multiplication != 0)&&(gamemode_played == Race)) {
				printf("	All turns until the projection starts: %u \n", ((2*freq-2) - ((g-1)%(2*freq-2))));
				printf("\n");
			} else if ((intensity_loss_per_line_multiplication != 0)&&((gamemode_played == Hunt)||(gamemode_played == Arena)||(gamemode_played == Ulcer)||(gamemode_played == Dynamic)||(gamemode_played == Survive)||(gamemode_played == Sand))) {	//mehr-gamemode_played
				printf("	All turns until the projection starts: %u \n", ((9*(number_of_players - player_counter) - 1) - ((g-all_turns_correction-1)%(9*(number_of_players - player_counter) - 1))));
				printf("\n");
			}
			
			if (gamemode_played == Race) {
				printf("	All turns until the wall moves forward: %u \n", (freq - ((g-1)%freq)));
				printf("\n");
			} else if (gamemode_played == Sand) {
				printf("	All turns until the squares will fall down: %u \n", (number_of_players - player_counter)*information_code[3] - ((g-all_turns_correction-1)%((number_of_players - player_counter)*information_code[3])));
				printf("\n");
			}
			
			w = 3;
			d = 2;
			e = 3;
			
			if (gamemode_played == Arena) {	//Arena-abilities werden eingesetzt
			
				for (unsigned int i=4; i<=AOP-1; i+=1) {
					if (ability[i] == geben) {
						information_code[0] = i;
					}
				}
				if (ability[1] == geben) {
					w = 1;
					d = 0;
					e = 1;
					information_code[0] = 1;
				} else if (ability[2] == geben) {
					w = 2;
					d = 1;
					e = 2;
					information_code[0] = 2;
				} else if (ability[3] == geben) {
					w = 4;
					d = 1;
					e = 4;	//abweichende e-definition
					information_code[0] = 3;
				} else if (ability[9] == geben) {
					information_code[0] = 9;
				
					if (opague >= 1) {
						opague_builder (Field, Sf_opague, m, n, geben, opague, AOP, Sf_allocation, allocation, number_of_players);
						show_field (Sf_permutations, Sf_opague, Sf_opague, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
					} else {
						show_field (Sf_permutations, Sf_opague, Field, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
					}
					
					for (unsigned int i=1; i<m-1; i+=1){	//push of electric
						for (unsigned int j=1; j<n-1; j+=1){
							if (Field[0][i][j] == geben) {
								if ((Field[0][i+1][j] != 0)&&(Field[0][i+1][j] != geben)&&((i+2) <= (m-2))) {
									if (Field[0][i+2][j] == 0) {
										set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i+2, j, Field[0][i+1][j]);
										set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i+1, j, 0);
									}
								}
								if ((Field[0][i-1][j] != 0)&&(Field[0][i-1][j] != geben)&&((i-2) >= 1)) {
									if (Field[0][i-2][j] == 0) {
										set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i-2, j, Field[0][i-1][j]);
										set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i-1, j, 0);
									}
								}
								if ((Field[0][i][j-1] != 0)&&(Field[0][i][j-1] != geben)&&((j-2) >= 1)) {
									if (Field[0][i][j-2] == 0) {
										set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j-2, Field[0][i][j-1]);
										set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j-1, 0);
									}
								}
								if ((Field[0][i][j+1] != 0)&&(Field[0][i][j+1] != geben)&&((j+2) <= (n-2))) {
									if (Field[0][i][j+2] == 0) {
										set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j+2, Field[0][i][j+1]);
										set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j+1, 0);
									}
								}
							}
						}
					}
				}
			}	// Done : index, show_field, var == 62,	start_normal, dies, != 6, hint, new_life, old_dying, ability_used_counter, 	  übertragen: /	 to do:	/	yes!
			
			if ((gamemode_played == Ulcer)&&(geben != 1)) {
				w = 2;
				d = 1;
				e = 2;
			}
			
			if (gamemode_played == Arena) {	//light und ultra_light erhalten gekürzte limit_at_all, beim Rest wird der richtige Wert eingesetzt
				if (information_code[0] == 1) {
					limit_at_all = limit_at_all_saver-2;
				} else if (information_code[0] == 2) {
					limit_at_all = limit_at_all_saver-1;
				} else {
					limit_at_all = limit_at_all_saver;
				}
			}
			
			if (ttt != 0) {		//Strafen wegen der Zeit
				if ((pere[geben] != 0)&&(warning_system <= 5)&&((pere[geben]+warning_system) == 7)) {
					g += 1;
					printf(" \n ");
					printf("	You got a penalty. \n ");
					printf(" \n ");
					pere[geben] = 0;
					continue;
				} else if ((pere[geben] != 0)&&(warning_system != 0)&&(((warning_system <= 5)&&((pere[geben]+warning_system) == 8))||((warning_system == 6)&&(pere[geben] == 1)))) {
					old_dying (Field, m, n, d, e, gamemode_played, information_code, geben, Sf_od_, w, Sf_allocation, allocation, Sf_opague, number_of_players);
					change (Sf_permutations, Field, Sf_nl_, Sf_od_, m, n, gamemode_played, number_of_players, ges, geben, undead_duration, Sf_allocation, allocation, Sf_opague, information_code, Colored, inverted); 	//Change befreit
					g += 1;
					printf(" \n ");
					printf("	You got a penalty. \n ");
					printf(" \n ");
					pere[geben] = 0;
					continue;
				} else if (((warning_system <= 5)&&((warning_system + pere[geben]) >= 9))||((warning_system >= 6)&&((warning_system + pere[geben]) >= 8))) {
					printf("	Niederlage: Spieler %u \n ", geben);
					for (unsigned int i=1; i<m-1; i+=1){
						for (unsigned int j=1; j<n-1; j+=1){
							if (Field[0][i][j] == geben) {
								set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j, 0);
							}
						}
					}
					ges[geben] = 1010*geben;
					player_counter += 1;
					pere[geben] = 100;
					g += 1;
					continue;
				}
			}
			
			if (var_[geben] == 1010*geben) {
				use_number = cons[geben];
				if (opt == 5) {
					printf("	Player %u ,do you want to keep your number (%u) or do you want to get the next one? \n", geben, cons[geben]);
					printf("	Keep the number: 	1 \n");
					printf("	Get the next one:	2 \n");
					lim = get_unsigned_numeric_input_with_not_more_than_1_letter ();
					
					if (lim == 2) {
						use_number = random_number (num_1, num_2, num_3, use_number, g, var_, number_);
					} else if (lim != 1) {
						printf("	Well, you keep your number, but next time please take an option i offered. \n\n");
					}
					lim = 0;
				} else if (cards != 0) {
					printf("	Player %u ,do you want to keep your Card (%u) or do you want to get the next one? \n", geben, cons[geben]);
					printf("	Keep the number: 	1 \n");
					printf("	Get the next one:	2 \n");
					lim = get_unsigned_numeric_input_with_not_more_than_1_letter ();
					
					if (lim == 2) {
						use_number = random_number (num_1, num_2, num_3, use_number, g, var_, number_);
					} else if (lim != 1) {
						printf("	Well, you keep your number, but next time please take an option i offered. \n\n");
					}
					lim = 0;
				}
			}
			
			if (var_[Nachfolger(geben, number_of_players)] == 1010*(Nachfolger(geben, number_of_players))){		//geben%number_of_players+1 ist der Nachfolger von geben.
				if (tac != 0) {
					stack_of_[geben][number_[geben]][0] += 1;
					numbers_of_[geben][number_[geben]][0] -= 1;
				} else if (opt == 5) {
					use_number = cons[geben];
					numbers_of_[geben][use_number][0] -= 1;
				} else if (cards != 0) {
					stack_of_[geben][number_[geben]][0] += 1;
					numbers_of_[geben][number_[geben]][0] -= 1;
				} else {
					numbers_of_[geben][number_[geben]][0] -= 1;
				}
				
			} else if (cards != 0) {
				stack_of_[geben][use_number][0] += 1;	//Drawing a card
			}
			
			
			if ((tac != 0)&&((stack_of_[geben][1][0]+stack_of_[geben][2][0]+stack_of_[geben][3][0]+stack_of_[geben][4][0]+stack_of_[geben][5][0]+stack_of_[geben][6][0]) == 0)){
				for (unsigned int p=1; p<=6; p+=1){
					stack_of_[geben][p][0] = tac;
				}
			}
			
			menuoperator = 1;		//Ende der Vorbereitung
			
			//#-start
			while (menuoperator != 0) {		//Beginn des Zuges
				
				if (gamemode_played != Rain) {
					if (opague >= 1) {
						opague_builder (Field, Sf_opague, m, n, geben, opague, AOP, Sf_allocation, allocation, number_of_players);
						show_field (Sf_permutations, Sf_opague, Sf_opague, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
					} else {
						show_field (Sf_permutations, Sf_opague, Field, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
					}
				}
				
				if (gamemode_played == Fall) {
					printf("\n");
					printf("	Points player %u: 	%u Point(s) \n", geben, Points[geben]);
				}
				
				if (gamemode_played == Ulcer) {
					printf("\n");
					printf("	Lifes player %u: 	%u Life(s) \n", geben, ulcer_lifes[geben]);
				}
				
				if (gamemode_played == Dynamic) {
					printf("	\n");
					printf("	Geschwindigkeit: 	Zeile: %d, 	Spalte: %d \n", dynamic_pointer[2], dynamic_pointer[3]);
					printf("	Beschleunigung: 	Zeile: %d, 	Spalte: %d \n", dynamic_pointer[4], dynamic_pointer[5]);
					printf("	\n");
				}
				
				printf("\n");
				
				show_whose_turn (gamemode_played, geben, ability, Colored);
				
				if ((cards != 0)&&(var_[Nachfolger(geben, number_of_players)] != 1010*(Nachfolger(geben, number_of_players)))) {
					printf("	You draw a %u. \n\n", use_number);
				} else if ((cards != 0)&&(var_[Nachfolger(geben, number_of_players)] == 1010*(Nachfolger(geben, number_of_players)))) {
					printf("	You still draw a %u. \n\n", cons[geben]);
				}
				
				if ((tac != 0)||(cards != 0)){
					printf("	Your stack of numbers:	\n	1) [%u], 	2) [%u], 	3) [%u],  \n\n	4) [%u], 	5) [%u], 	6) [%u], \n", stack_of_[geben][1][0], stack_of_[geben][2][0], stack_of_[geben][3][0], stack_of_[geben][4][0], stack_of_[geben][5][0], stack_of_[geben][6][0]);
					printf("\n");
					printf("\n");
				}
				
				if (opt == 5){		//random number
					printf("	Your number: %u ", use_number);
					printf("\n");
					printf("\n");
									//##
				}
				
				//#-end
				
				show_options_of_actions (gamemode_played, information_code, geben);
				
				if ((ttt != 0)&&(time_saver == 0.0)) {
					time1 = time(NULL);
				}
				var_[geben] = get_unsigned_numeric_input_with_not_more_than_3_letters ();
				//printf("	Checkpoint: var_[geben] \n");	//test
				
				if (var_[geben] == 10){
					if (ttt != 0) {
						time3 = time(NULL);
					}
					
					while (menuoperator != 7) {
						printf("\n");
						printf("\n");
						printf("	About the game: 1 \n	Statistics: 2 \n	The numbers: 3 \n	The limits: 4 \n	Get Hints: 5 \n	Suprise: 6 \n	Quit Menu: 7 \n");
						menuoperator = get_unsigned_numeric_input_with_not_more_than_1_letter();
						
						if (menuoperator == 1){
							About_the_game (gamemode_played, geben, limit_at_all, limit_new, number_of_players, freq, w, d, e);
							
						} else if (menuoperator == 2){
							printf("\n");
							printf("	turns at all: %u \n", g);
							
							show_statistics (number_of_players, gamemode_played, numbers_of_, Points, exclude_counter, ulcer_lifes, ges, pere, ability, ttt);
							
						} else if (menuoperator == 3){
							
							show_the_numbers (gamemode_played, w, d, e, geben);
							
						} else if (menuoperator == 4){
							if ((gamemode_played != Ulcer)&&(gamemode_played != Survive)) {
								printf("	Limit of development:	%u \n", limit_new);
								if (gamemode_played != Contact) {
									printf("	Limit in total:		%u \n", limit_at_all);
									printf("	Limit in total with >2-new< taken: %u -0/-1/-2/-3/-4.\n", limit_at_all);
								}
							}
						} else if (menuoperator == 5){
							
							get_hints (Sf_permutations, gamemode_played, Field, geben, w, d, e, m, n, information_code, Sf_opague, opague, Colored, AOP, Sf_allocation, allocation, number_of_players);
							
							//show_field (Sf_permutations, Sf_opague, hint, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);		//teste die destroy-funktion für Spielfelder, done
						} else if (menuoperator == 6){
							
							if (suprise == 0) {
								for (unsigned int i=1; i<m-1; i+=1){
									for (unsigned int j=1; j<n-1; j+=1){
										
										set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, geben, i, j, Field[0][i][j]);
										
										if (journey == 1){
											set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field_journey, geben, i, j, Field_journey[0][i][j]);
										}
									}
								}
								sup_num = use_number;
							}
							
							while (menuoperator != 1) {
					
								printf("	Creator menu. 	Change number: 1	Suprise: 2	Suprise undo: 3	Back: 4 \n");
								lim = get_unsigned_numeric_input_with_not_more_than_1_letter ();
								if (lim == 1){
									printf("	number = ? \n");
									use_number = get_unsigned_numeric_input_with_not_more_than_1_letter();
								} else if (lim == 2){
							
									printf("\n");
									suprise = get_unsigned_numeric_input_with_not_more_than_1_letter();
							
									if (suprise == 31){
										for (unsigned int i=2; i<m-2; i+=1){
											for (unsigned int j=1; j<n-1; j+=1){
												if (Field[0][i][j] != 0){
													if (Field[0][i][j] == geben){
														set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j, Nachfolger(geben, number_of_players));
													} else if (Field[0][i][j] == Nachfolger(geben, number_of_players)){
														set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j, geben);
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
													set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j, 0);
												}
												if (i == (m-2)){
													set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, geben, m-2, j, Nachfolger(geben, number_of_players));
												}
											}
										}
									}
							
								} else if (lim == 3){
									for (unsigned int i=1; i<m-1; i+=1){
										for (unsigned int j=1; j<n-1; j+=1){
											set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, geben, i, j, Field[geben][i][j]);
											if (journey == 1){
												set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field_journey, geben, i, j, Field_journey[geben][i][j]);
											}
										}
									}
									use_number = sup_num;
								} else if (lim == 4){
									menuoperator = 1;
								} else {
									printf("	Invalid comment");
								}
							}
						}
						
					}		// menuoperator = 7
					
					if (gamemode_played == Rain) {		//##
						if (opague >= 1) {
							opague_builder (Field, Sf_opague, m, n, geben, opague, AOP, Sf_allocation, allocation, number_of_players);
							show_field (Sf_permutations, Sf_opague, Sf_opague, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
						} else {
							show_field (Sf_permutations, Sf_opague, Field, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
						}	//show_field über menuoperator = 7 und stack und so löschen, (verschiebe menuoperator!=0 - Schleife) ,done
						
						printf("\n");
					
					}
					
					if (ttt != 0) {
						time4 = time(NULL);
						time_saver += difftime(time4, time3);
					}
				}		//Menu-end.
				
				menuoperator = 0;
				
				if (var_[geben] == 10) {
					menuoperator = 1;
					var_[geben] = 5;		//## to avoid the mistake-note by closing the menu
				}
				
				
				
				if (((tac != 0)||(cards != 0))&&(var_[geben] <= 62)&&(var_[geben] > 10)){
					unsigned int tac_controll;	//also used for cards
					tac_controll = 0;
					if (((var_[geben]%10) > 2)||((var_[geben]%10) == 0)){
						var_[geben] = 7;
						menuoperator = 1;
					} else {
						for (unsigned int z=var_[geben]; z>2; z-=10){
							tac_controll += 1;
						}
						if (stack_of_[geben][tac_controll][0] == 0){
							var_[geben] = 7;
							menuoperator = 1;
						} else {
							stack_of_[geben][tac_controll][0] -= 1;		//Die tac/cards-Abrechnung
						}
					}
				} else if (((tac != 0)||(cards != 0))&&(var_[geben] != 100)&&(var_[geben] != 1010*geben)&&(var_[geben] != 0)&&(var_[geben] != 5)) {
					var_[geben] = 7;
				}		
				//tac/cards-mode
				
				if (opt == 5){
					controll_1 = 10+use_number;
					controll_2 = 11+use_number;
				
					for (unsigned int i=0; i<use_number-1; i+=1){
						controll_1 += 9;
						controll_2 += 9;
					}
				
					if (var_[geben] == 0){
						controll_1 = 0;
						controll_2 = 0;
					}
					if (var_[geben] == 100){
						controll_1 = 100;
						controll_2 = 100;
					}
					if (var_[geben] == 1010*geben){
						controll_1 = 1010*geben;
						controll_2 = 1010*geben;
					}
				}
				
				if (((var_[geben] > 0)&&(var_[geben] < 10))||(((opt == 5)&&(var_[geben] != controll_1))&&((opt == 5)&&(var_[geben] != controll_2)))){
					
					if (var_[geben] != 5) {		//#-start
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
				
			} 		// menuoperator = 0 

			suprise = 0;
			
			if (var_[geben] == 0){
				printf("	Do you really want to end the game ? \n");
				printf("	Yes: 0		No: 1 \n");
				lim = get_unsigned_numeric_input_with_not_more_than_1_letter ();
				if (lim == 0){
					break;
				} else if (lim == 1){
					lim = 0;
					continue;
				} else {
					printf("	0 or 1, it is so difficult to understand? \n");
					printf("	Well, it seems I have to end it by myself... \n");
					break;
				}
			} else {
				
				// printf("	Checkpoint: var_[geben] accepted \n");	//test
				
				if (var_[geben] == 100){		//1, 2, 3,... durch "geben" ersetzen, done
					
					var_[0] = 1;
					
					if (gamemode_played == Dynamic) {
						for (unsigned int p=2; p<=5; p+=1) {
							
							dynamic_pointer[p] = dynamic_pointer_save[Vorganger(geben, number_of_players)][p-2];	//if
							
						}
					}
					if (cards != 0) {
						stack_of_[geben][use_number][0] -= 1;
					}
					
					cons[geben] = use_number;
					
					for (unsigned int i=1; i<m-1; i+=1){
						for (unsigned int j=1; j<n-1; j+=1){
							
							set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j, Field[Vorganger(geben, number_of_players)][i][j]);
							
							if (allocation != 0) {
								set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Sf_allocation, 0, i, j, Sf_allocation[Vorganger(geben, number_of_players)+2][i][j]);	//+2 wegen Indexverschiebung
							}
						
							if (journey == 1){
								set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field_journey, 0, i, j, Field_journey[Vorganger(geben, number_of_players)][i][j]);

							}
							
						}
					}
					
					if (opague >= 1) {
						opague_builder (Field, Sf_opague, m, n, Vorganger(geben, number_of_players), opague, AOP, Sf_allocation, allocation, number_of_players);
						show_field (Sf_permutations, Sf_opague, Sf_opague, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
					} else {
						show_field (Sf_permutations, Sf_opague, Field, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
					}
					
					g-=1;
					var_[geben] = 1010*geben;
					if (gamemode_played == Ulcer) {
						ulcer_lifes[geben] += 1;
						ulcer_start[geben] = missing;
					}
					continue;
				} else {
					
					if (var_[Nachfolger(geben, number_of_players)] != 1010*(Nachfolger(geben, number_of_players))){
						
						for (unsigned int i=1; i<m-1; i+=1){
							for (unsigned int j=1; j<n-1; j+=1){
								set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, geben, i, j, Field[0][i][j]);
								
								if (allocation != 0) {
									set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Sf_allocation, geben+2, i, j, Sf_allocation[0][i][j]);	//geben+2 wegen indexverschiebung
								}
						
								if (journey == 1){
									set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field_journey, geben, i, j, Field_journey[0][i][j]);
								}
							}
						}
						
						if (gamemode_played == Dynamic) {
							for (unsigned int p=2; p<=5; p+=1) {
								
								dynamic_pointer_save[geben][p-2] = dynamic_pointer[p];
								
							}
						}
						
						
					}
					
					var_[0] = 0;
					
					temp = Spielfeld_Create (m, n, 0);
					
					if (var_[geben] < 50){
						
						// printf("	Checkpoint: var_[geben]<50 accepted \n");	//test
						
						if (var_[geben] == 11){numbers_of_[geben][1][0] += 1; Plus (Sf_permutations, m, n, geben, Field, limit_at_all, gamemode_played, information_code, number_of_players, Colored, opague, Sf_opague, Sf_allocation, allocation);}
						if (var_[geben] == 12){numbers_of_[geben][1][0] += 1; Minus (Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Colored, opague, Sf_opague, Sf_allocation, allocation, number_of_players);}
						if (var_[geben] == 21){numbers_of_[geben][2][0] += 1; Move (Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Colored, opague, Sf_opague, Sf_allocation, allocation, number_of_players);}
						if (var_[geben] == 41){numbers_of_[geben][4][0] += 1; Move (Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Colored, opague, Sf_opague, Sf_allocation, allocation, number_of_players);}
						if (var_[geben] == 22){numbers_of_[geben][2][0] += 1; Change (Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Colored, opague, Sf_opague, position, Sf_allocation, allocation, number_of_players);}
						if (var_[geben] == 31){numbers_of_[geben][3][0] += 1; Destroy (Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Colored, opague, Sf_opague, Sf_allocation, allocation, number_of_players);}
						if (var_[geben] == 42){
							numbers_of_[geben][4][0] += 1;
							if ((gamemode_played != Hunt)||(geben != 1)) {
								Boost (geben, Field, m, n, temp, gamemode_played, Sf_opague, Sf_allocation, allocation, number_of_players);
							} else if ((gamemode_played == Hunt)&&(geben == 1)) {
								boost_hunt_activator = 1;
							}
						}
					} else {
						
						// printf("	Checkpoint: var_[geben]>50 accepted \n");	//test
						
						if (var_[geben] == 51){numbers_of_[geben][5][0] += 1; w += 1;}		//w
						if (var_[geben] == 52){numbers_of_[geben][5][0] += 1; w -= 1;}		//w
						if (var_[geben] == 61){numbers_of_[geben][6][0] += 1; e += 1;}		//e
						if (var_[geben] == 62){numbers_of_[geben][6][0] += 1; if (d != 0) {d -= 1;} else {d = 10;}}		//d
					}
					
					// printf("	Checkpoint: Funktions accepted \n");	//test
					
					if (ttt != 0) {
						time2 = time(NULL);		//wirklich die eingabe abwarten, done
						time_warning = ((difftime(time2, time1)) - time_saver);
						
						///printf("	time_warning: %f \n", time_warning);		//test
						
						if ((pere[geben] != 0)&&((pere[geben] + warning_system) <= 6)) {
							if (pere[geben] == 1) {
								if (warning_system <= 2) {
									time_warning += 1.0;
								} else if (warning_system == 3) {
									time_warning += 2.0;
								} else if (warning_system == 4) {
									time_warning += 3.0;
								} else if (warning_system == 5) {
									time_warning += 5.0;
								}
							} else if (pere[geben] == 2) {
								if (warning_system == 1) {
									time_warning += 2.0;
								} else if (warning_system == 2) {
									time_warning += 3.0;
								} else if (warning_system == 3) {
									time_warning += 5.0;
								} else if (warning_system == 4) {
									time_warning += 6.0;
								}
							} else if (pere[geben] == 3) {
								if (warning_system == 1) {
									time_warning += 3.0;
								} else if (warning_system == 2) {
									time_warning += 5.0;
								} else if (warning_system == 3) {
									time_warning += 8.0;
								}
							} else if (pere[geben] == 4) {
								if (warning_system == 1) {
									time_warning += 4.0;
								} else if (warning_system == 2) {
									time_warning += 7.0;
								}
							} else if (pere[geben] == 5) {
								if (warning_system == 1) {
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
						if (time_warning > (1.0*ttt)) {
							pere[0] += 1;
							printf("	You took too much time! %f sec more than you should. \n", (time_warning-1.0*ttt) );
							printf(" \n");
							for (unsigned int p=16; p>=1; p-=3) {	//index_verschiebung
								if ((time_warning-1.0*ttt) > 1.0*(p-1)) {
									pere[geben] = (((p-1)/3) + 1);
									break;
								}
							}
						} else {
							pere[geben] = 0;
						}
						//printf("	pere[%u]: %u \n", geben, pere[geben] );	//test
					}
					
					new_life (Field, m, n, w, gamemode_played, information_code, geben, Sf_nl_, Sf_od_, Sf_opague, Sf_allocation, allocation, number_of_players);
					
					// printf("	Checkpoint: new_life accepted \n");	//test
					
					// show_field (Sf_permutations, Sf_opague, Sf_nl_, m, n, gamemode_played, information_code, geben, Colored, geben, Sf_allocation, allocation);	// test
					
					if (gamemode_played == Hunt) {
						
						precounter = 0;
						for (unsigned int i=1; i<m-1; i+=1){
							for (unsigned int j=1; j<n-1; j+=1){
								if (Field[0][i][j] == 11){
									if (Sf_nl_[geben][i][j-1] > 1) {
										printf (" Sieg: Spieler %u \n", Sf_nl_[geben][i][j-1]);
										precounter += 1;
									}
									if (Sf_nl_[geben][i][j+1] > 1) {
										if (precounter == 0) {
											printf (" Sieg: Spieler %u \n", Sf_nl_[geben][i][j+1]);
										}
										precounter += 1;
									}
									if (Sf_nl_[geben][i-1][j] > 1) {
										if (precounter == 0) {
											printf (" Sieg: Spieler %u \n", Sf_nl_[geben][i-1][j]);
										}
										precounter += 1;
									}
									if (Sf_nl_[geben][i+1][j] > 1) {
										if (precounter == 0) {
											printf (" Sieg: Spieler %u \n", Sf_nl_[geben][i+1][j]);
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
									if (Sf_nl_[geben][i][j] == geben) {
										set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j, geben);
									}
								}
							}
							show_field (Sf_permutations, Sf_opague, Field, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
							break;
						}
					}
			
					controll = 0;
					if (gamemode_played == Race) {
						for (unsigned int i=1; i<=(m-1)/2; i+=1){		//Spiel-Ende?
							if ((Sf_nl_[geben][i][n-2] == geben)||(Field[0][i][n-2] == geben)){
								for (unsigned int k=1; k<m-1; k+=1){
									if (Sf_nl_[geben][k][n-2] == geben){
										set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, k, n-2, geben);
									}
								}
								show_field (Sf_permutations, Sf_opague, Field, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
								printf("	Sieg:	Spieler %u \n", geben);
								controll = 1;
							}
						}
						if (controll == 1){
							break;
						}
					}
					controll = 0;
					
					num_1 = 0;
					for (unsigned int i=1; i<m-1; i+=1){
						for (unsigned int j=1; j<n-1; j+=1){
							if (Sf_nl_[geben][i][j] == geben){
								num_1 += 1;
							}
						}
					}
					
					if ((gamemode_played != Hunt)||(geben != 1)) {	//wegen hunted one, if (geben != 1)
						if (var_[geben] == 42){
							for (unsigned int i=1; i<m-1; i+=1){
								for (unsigned int j=1; j<n-1; j+=1){
									if (gamemode_played == Rain) {
										if (temp[0][i][j] == geben){
											set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j, 0);
										}
									} else if ((gamemode_played == Arena)||(gamemode_played == Ulcer)||(gamemode_played == Dynamic)||(gamemode_played == Survive)||(gamemode_played == Sand)) {	//mehr-gamemode_played
										if (temp[0][i][j] != 0){
											set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j, temp[0][i][j]);
										}
									} else if ((gamemode_played != Rain)&&(gamemode_played != Arena)&&(gamemode_played != Ulcer)&&(gamemode_played != Dynamic)&&(gamemode_played != Survive)&&(gamemode_played != Sand)) {	//10
										if (temp[0][i][j] == 1){
											set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j, 2);
										} else if (temp[0][i][j] == 2) {
											set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j, 1);
										}
									}
								}
							}
						}
					}
					
					controll = 0;
					if (gamemode_played == Classic) {
						for (unsigned int j=1; j<n-1; j+=1){
							if (geben == 1) {
								if (Field[0][m-2][j] == geben){
									printf("	Sieg:	Spieler %u \n", geben);
									controll = 1;
									break;
								}
							} else if (geben == 2) {
								if (Field[0][1][j] == geben){
									printf("	Sieg:	Spieler %u \n", geben);
									controll = 1;
									break;
								}
							}
							
						}
						if (controll == 1){
							break;
						}
					}
					controll = 0;
					
					Spielfeld_Destroy (temp, m, 0);
				
					old_dying (Field, m, n, d, e, gamemode_played, information_code, geben, Sf_od_, w, Sf_allocation, allocation, Sf_opague, number_of_players);
					
					// show_field (Sf_permutations, Sf_opague, Sf_od_, m, n, gamemode_played, information_code, geben, Colored, geben, Sf_allocation, allocation);	//test
					
					if ((boost_hunt_activator == 1)&&(gamemode_played == Hunt)&&(geben == 1)) {
						for (unsigned int i=1; i<m-1; i+=1){
							for (unsigned int j=1; j<n-1; j+=1){
								if (Field[0][i][j] == 11){
									set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Sf_od_, geben, i-1, j, 0);
									set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Sf_od_, geben, i, j-1, 0);
									set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Sf_od_, geben, i+1, j, 0);
									set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Sf_od_, geben, i, j+1, 0);
									
									boost_hunt_activator = 0;
									break;
								}
							}
							if (boost_hunt_activator == 0) {
								break;
							}
						}
					}
					
					if (journey == 1){
						unsigned int journey_max, temp_limit_at_all;
						journey_max = 0;
						temp_limit_at_all = 0;
						
						if (limit_at_all == 0) {
							limit_at_all = 25;
							temp_limit_at_all = 1;
						}
						
						for (unsigned int i=1; i<m-1; i+=1){
							for (unsigned int j=1; j<n-1; j+=1){
								if (Field_journey[0][i][j] == geben){
									journey_max += 1;
								}
							}
						}
						for (unsigned int i=1; i<m-1; i+=1){
							for (unsigned int j=1; j<n-1; j+=1){
								if ((Sf_od_[geben][i][j] == 101*geben) && (Field_journey[0][i][j] == 0) && (journey_max >= limit_at_all)){
									for (unsigned int u=0; u<(m-1); u+=1){
										for (unsigned int o=1; o<(n-1); o+=1){
											if ((Field_journey[0][u][o] == geben)&&((u+o)%2 == 0)){
												set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field_journey, 0, u, o, 0);
												journey_max -= 1;
												if (journey_max < limit_at_all){
													break;
												}
											}
										}
										if (journey_max < limit_at_all){
											break;
										}
									}
									
								}
								if ((Sf_od_[geben][i][j] == 101*geben) && (Field_journey[0][i][j] == 0) && (journey_max < limit_at_all)){
									set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field_journey, 0, i, j, geben);
									journey_max += 1;
								}
							}
						}
						journey_max = 0;
						
						if (temp_limit_at_all == 1) {
							limit_at_all = 0;
						}
					}
					
					if (var_[geben] == 32){numbers_of_[geben][3][0] += 1; Revive(m, n, Sf_od_, Field, geben, Sf_allocation, allocation, Sf_opague, number_of_players);}
					
					num_2 = 0;
					for (unsigned int i=1; i<m-1; i+=1){
						for (unsigned int j=1; j<n-1; j+=1){
							if (Sf_od_[geben][i][j] == 101*geben){
								num_2 += 1;
							}
						}
					}
				
					count_new = 0;
					
					for (unsigned int i=1; i<m-1; i+=1){
						for (unsigned int j=1; j<n-1; j+=1){
							if (Sf_nl_[geben][i][j] == geben){
								count_new += 1;
							}
						}
					}
					
					ent = limit_new;
					
					for (unsigned int i=1; i<m-1; i+=1){
						for (unsigned int j=1; j<n-1; j+=1){
							if ((Field[0][i][j] == geben) && (Sf_od_[geben][i][j] == 0)){
								zeitgewinner += 1;
							}
						}
					}
					
					//printf("	ent: %u \n ", ent);
					if ((gamemode_played == Hunt)&&(geben == 1)) {
						ent = (ent + (number_of_players-3));
					}
					
					if ((count_new > limit_new)&&(inverted == 0)&&(addition == 0)&&(intensity_loss_per_line_multiplication == 0)){		//Abfrage auf max. 10 neue Steine, normalerweise
						if ((gamemode_played != Ulcer)&&(gamemode_played != Survive)) {
							Index (ent, count_new, m, n, Sf_nl_, Sf_od_, limit_new, limit_at_all, zeitgewinner, Field, w, d, e, geben, position, gamemode_played, number_of_players, rain, Sf_opague, Sf_allocation, allocation);
						} else {
							count_new = 0;
						}
					
					}
					ent = 0;
					count_new = 0;
				
					num_3 = 0;
					for (unsigned int i=1; i<m-1; i+=1){
						for (unsigned int j=1; j<n-1; j+=1){
							if (((Field[0][i][j] == geben) && (((Sf_od_[geben][i][j] == 0)&&(allocation == 0))||(Sf_allocation[0][i][j] > Sf_allocation[1][i][j]))) || (Sf_nl_[geben][i][j] == geben)){
								count_new += 1;
								num_3 += 1;
							}
						}
					}
					
					if ((gamemode_played == Hunt)&&(geben == 1)) {	//count the heart, if geben == 1
						count_new += 1;
						num_3 += 1;
					}
					
					ent = limit_at_all;
					
					if ((gamemode_played == Classic)||(gamemode_played == Collect)||(gamemode_played == Fall)||(gamemode_played == Fight)||(gamemode_played == Race)||(gamemode_played == Rain)) {
						
						if (var_[geben] == 52){
							lim = 0;
							for (unsigned int i=1; i<m-1; i+=1){
								for (unsigned int j=1; j<n-1; j+=1){
									if ((Field[0][i][j] == geben) && (Sf_od_[geben][i][j] == 0)){
										lim += 1;
									}
								}
							}
							ent = lim;
							lim = 0;
							for (unsigned int i=1; i<m-1; i+=1){
								for (unsigned int j=1; j<n-1; j+=1){
									if (Field[0][i][j] == Nachfolger(geben, number_of_players)){
										lim += 1;
									}
								}
							}
							if ((lim <= limit_new) && (ent < (limit_at_all - 1))){
								if (ent >= (limit_at_all - 3)){
									ent = limit_at_all - 1;
								} else if (ent >= (limit_at_all - 5)){
									ent = limit_at_all - 2;
								} else if (ent >= (limit_at_all - 7)){
									ent = limit_at_all - 3;
								} else if (ent >= (limit_at_all - 10)){
									ent = limit_at_all - 4;
								} else {
									ent = limit_at_all;
								}
							} else {
								ent = limit_at_all;
							}
							lim = 0;
						}
					}
					
					if ((gamemode_played == Hunt)&&(geben == 1)) {
						ent = (ent + 2* (number_of_players-3));
					}
					
					if ((count_new > ent)&&(inverted == 0)&&(addition == 0)&&(intensity_loss_per_line_multiplication == 0)){		//Abfrage auf insgesamt max. 20 Steine, normalerweise
						if ((gamemode_played != Contact)&&(gamemode_played != Ulcer)&&(gamemode_played != Survive)) {
							Index (ent, count_new, m, n, Sf_nl_, Sf_od_, limit_new, limit_at_all, zeitgewinner, Field, w, d, e, geben, position, gamemode_played, number_of_players, rain, Sf_opague, Sf_allocation, allocation);
						} else {
							count_new = 0;
						}
					
					}
					
					zeitgewinner = 0;
					ent = 0;
					
					if (gamemode_played == Fall) {
						touch (Field, m, n, geben, Sf_nl_, Sf_allocation, allocation, Sf_opague, number_of_players);
					}
					
					change (Sf_permutations, Field, Sf_nl_, Sf_od_, m, n, gamemode_played, number_of_players, ges, geben, undead_duration, Sf_allocation, allocation, Sf_opague, information_code, Colored, inverted); 	//Change setzt auf null
					
					if (addition != 0) {
						
						if (opague >= 1) {
							opague_builder (Field, Sf_opague, m, n, geben, opague, AOP, Sf_allocation, allocation, number_of_players);
							show_field (Sf_permutations, Sf_opague, Sf_opague, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
						} else {
							show_field (Sf_permutations, Sf_opague, Field, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
						}
						
						addition_maker (Field, m, n, number_of_players, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, ges);
						
					}
					
					/*
					get_sequence (Spielfeld Field, Spielfeld Sf_nl_, Spielfeld Sf_od_, unsigned int m, unsigned int n, unsigned int w, unsigned int d, unsigned int e, unsigned int gamemode_played, unsigned int* information_code, unsigned int number_of_players, unsigned int ges, unsigned int opague, Spielfeld Sf_opague, Spielfeld sequence, unsigned int seq_max, unsigned int nosv);
					
					if (sequence[0][0] > 0) {
						
						sequence[0][0] = 100;
						
						if (opague >= 1) {
							opague_builder (Field, Sf_opague, m, n, geben, opague, AOP, Sf_allocation, allocation, number_of_players);
							show_field (Sf_permutations, Sf_opague, Sf_opague, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
						} else {
							show_field (Sf_permutations, Sf_opague, Field, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
						}
						
						while (sequence[0][0] == 100) {
							printf("\n");
							printf("	How long should be your sequence from now on? \n");
							for (unsigned int p=0; p<seq_max; p+=1) {
								printf("	Length of [%u]: 	%u left \n", p, sequence[geben][p]);
							}
							printf("\n");
							sequence[0][0] = get_unsigned_numeric_input_with_not_more_than_1_letter ();
							if ((sequence[0][0] >= seq_max)||(sequence[geben][sequence[0][0]] == 0)) {
								sequence[0][0] = 100;
								printf("	You made a mistake. \n");
							} else {
								sequence[geben][sequence[0][0]] -= 1;
								
								for (unsigned int p=1; p<=sequence[0][0]; p+=1) {		//Index?
									
									new_life (Field, m, n, w, gamemode_played, information_code, geben, Sf_nl_, Sf_od_, Sf_opague, Sf_allocation, allocation, number_of_players);		//let Index go over it, even without reason? What will Index do? Nothing, i guess...
									old_dying (Field, m, n, d, e, gamemode_played, information_code, Sf_od_, w, Sf_allocation, allocation, Sf_opague, number_of_players);
									Field[0] = change (Sf_permutations, Field, Sf_nl_, Sf_od_, m, n, gamemode_played, number_of_players, ges, geben, undead_duration, Sf_allocation, allocation, Sf_opague, information_code, Colored, inverted)
									if (p == sequence[0][0]) {
										if (opague >= 1) {
											opague_builder (Field, Sf_opague, m, n, geben, opague, AOP, Sf_allocation, allocation, number_of_players);
											show_field (Sf_permutations, Sf_opague, Sf_opague, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
										} else {
											show_field (Sf_permutations, Sf_opague, Field, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
										}
									}
								}
							}
						}
						
						sequence[0][1] = 0;
						for (unsigned int p=0; p<seq_max; p+=1) {
							sequence[0][1] += sequence[geben][p];
						}
						if (sequence[0][1] == 0) {
							for (unsigned int p=seq_max; p>0; p-=1) {
								sequence[geben][seq_max-p] = same[nosv-p+1];	//put nosv-Wert +10
							}
						}
						sequence[0][1] = 0;
						
						
						//seq_max, sequence[10][10], go on
					
					}*/
					
					if ((gamemode_played == Hunt)&&(geben == 1)) {	//if geben == 1
						
						if (opague >= 1) {
							opague_builder (Field, Sf_opague, m, n, geben, opague, AOP, Sf_allocation, allocation, number_of_players);
							show_field (Sf_permutations, Sf_opague, Sf_opague, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
						} else {
							show_field (Sf_permutations, Sf_opague, Field, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
						}
						
						printf("\n");
						printf("\n");
						choose_heart (Field, m, n, geben, Sf_opague, Sf_allocation, allocation, number_of_players);
						printf("\n");
					}
					
					if (gamemode_played == Classic) {	//if, because different
						for (unsigned int j=1; j<n-1; j+=1){
							if (geben == 1) {
								if (Field[0][m-3][j] == geben){
									numbers_of_[geben][0][0] += 1;
									break;
								}
							} else if (geben == 2) {
								if (Field[0][2][j] == geben){
									numbers_of_[geben][0][0] += 1;
									break;
								}
							}
							
						}
						
						controll = 0;
						
						for (unsigned int j=1; j<n-1; j+=1){
							if (geben == 1) {
								if (Field[0][m-2][j] == geben){
									printf("	Sieg:	Spieler %u \n", geben);
									controll = 1;
									break;
								}
							} else if (geben == 2) {
								if (Field[0][1][j] == geben){
									printf("	Sieg:	Spieler %u \n", geben);
									controll = 1;
									break;
								}
							}
							
						}
						if (controll == 1){
							break;
						}
						
						controll = 0;
						
					} else if (gamemode_played == Collect) {
						for (unsigned int j=2; j<n-1; j+=((n-1)/2)-2){		//Collect-Bed. prüfen
							unsigned int a;
							a = 0;
							if (Field[0][((m-1)/2)][j] == 7){
								if (Field[0][((m-1)/2)-1][j]==geben){a += 1;}
								if (Field[0][((m-1)/2)+1][j]==geben){a += 1;}
								if (Field[0][(m-1)/2][j-1]==geben){a += 1;}
								if (Field[0][(m-1)/2][j+1]==geben){a += 1;}
								if (a >= 3){
									numbers_of_[geben][0][0] += 1;
									set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, ((m-1)/2), j, geben);
								}
							}
						}
						if (numbers_of_[geben][0][0] == 2){
							printf("\n");
							printf("	Sieg: Spieler %u \n", geben);
							printf("\n");
							show_field (Sf_permutations, Sf_opague, Field, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
							break;
						}
					} else if (gamemode_played == Sand) {
						for (unsigned int j=1; j<n-1; j+=1){
						
							if ((Field[0][2][j] != 0)&&(Field[0][2][j] <= AOP)){
								numbers_of_[Field[0][2][j]][0][0] += 1;
							}
							
						}
					}
					
					if ((gamemode_played == Hunt)&&(geben == number_of_players)) {
						lim = 1;
						printf("	\n");
						
						if (opague >= 1) {
							opague_builder (Field, Sf_opague, m, n, geben, opague, AOP, Sf_allocation, allocation, number_of_players);
							show_field (Sf_permutations, Sf_opague, Sf_opague, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
						} else {
							show_field (Sf_permutations, Sf_opague, Field, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
						}
						
						printf("	\n");
						while (lim == 1) {
							printf("	\n");
							printf("	\n");
							printf("	Are you ready to make your turn, player 1 ? \n");
							printf("	Yes: 1 \n");
							printf("	\n");
							printf("	\n");
							lim = get_unsigned_numeric_input_with_not_more_than_1_letter ();
							
							if (lim != 1) {
								lim = 1;
							} else {
								lim = 0;
							}
						}
					}
					if (gamemode_played == Hunt) {
						information_code[3] = 0;
					}
					
					if ((gamemode_played == Hunt)&&(geben == 1)) {	//if geben==1
						for (unsigned int p=0; p<=3; p+=1) {
							information_code[p] = 0;
						}
						/* test
						printf("\n");
						printf("	hboa=%u	\n", hboa);
						printf("\n");
						*/
						
						if (opague >= 1) {
							opague_builder (Field, Sf_opague, m, n, geben, opague, AOP, Sf_allocation, allocation, number_of_players);
							show_field (Sf_permutations, Sf_opague, Sf_opague, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
						} else {
							show_field (Sf_permutations, Sf_opague, Field, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
						}
						
						for (unsigned int s = 1; s <= 20; s+=1) {	//Abstandhalter
							printf(" \n");
						}
					}
					
					if (assassin != 0) {
						assassin_maker (Sf_permutations, Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, m, n, opague, AOP, information_code, Colored);
					}
					
					if (gamemode_played == Contact) {
						
						if (opague >= 1) {
							opague_builder (Field, Sf_opague, m, n, geben, opague, AOP, Sf_allocation, allocation, number_of_players);
							show_field (Sf_permutations, Sf_opague, Sf_opague, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
						} else {
							show_field (Sf_permutations, Sf_opague, Field, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
						}
						
						battle (m, n, Field, geben, Sf_opague, Sf_allocation, allocation, number_of_players);
					}
					
					if ((var_[Nachfolger(geben, number_of_players)] != 1010*(Nachfolger(geben, number_of_players)))||(ges[Nachfolger(geben, number_of_players)] == 1010*(Nachfolger(geben, number_of_players)))) {
						cons[geben] = use_number;
					}
					
					use_number = random_number (num_1, num_2, num_3, use_number, g, var_, number_);
					
					if ((opt != 5)&&(var_[geben] <= 62)){
						controll_1 = 0;
						for (unsigned int z=var_[geben]; z>2; z-=10){
							controll_1 += 1;
						}
						number_[geben] = controll_1;
						controll_1 = 0;
					}
				}
			}
			
			//normal_end
			
			printf("\n");
			
			if ((gamemode_played == Classic)||(gamemode_played == Collect)||(gamemode_played == Contact)) {
				if (journey == 1){
					if (((g-1)%19) == 18){
						printf (" \n");
						printf (" \n");
						printf ("	It is time for a journey... \n");
						printf (" \n");
						for (unsigned int i=1; i<m-1; i+=1){
							for (unsigned int j=1; j<n-1; j+=1){
								if (Field[0][i][j] != 7) {
									set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j, Field_journey[0][i][j]);
									set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field_journey, 0, i, j, 0);
									
								} else if (Field[0][i][j] == 7) {
									set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field_journey, 0, i, j, 0);
								}
							}
						}
						
						if (opague >= 1) {
							opague_builder (Field, Sf_opague, m, n, (geben%number_of_players)+1, opague, AOP, Sf_allocation, allocation, number_of_players);
							show_field (Sf_permutations, Sf_opague, Sf_opague, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
						} else {
							show_field (Sf_permutations, Sf_opague, Field, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
						}
						
					}
				}
				
				if (intensity_loss_per_line_multiplication != 0){
					if (((g-1)%17) == 16){
						if (opague >= 1) {
							opague_builder (Field, Sf_opague, m, n, (geben%number_of_players)+1, opague, AOP, Sf_allocation, allocation, number_of_players);
							show_field (Sf_permutations, Sf_opague, Sf_opague, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
						} else {
							show_field (Sf_permutations, Sf_opague, Field, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
						}
						
						printf (" \n");
						printf (" \n");
						printf ("	It is time for a projection... \n");
						printf (" \n");
						projection_maker (Field, number_of_players, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, direction, intensity_minimum, intensity_loss_per_line_multiplication, m, n);
						
					}
				}
			}
			
			if ((gamemode_played == Fight)||(gamemode_played == Rain)) {
				if (journey == 1){
					if (((g-1)%15) == 14){
						printf (" \n");
						printf (" \n");
						printf ("	It is time for a journey... \n");
						printf (" \n");
						for (unsigned int i=1; i<m-1; i+=1){
							for (unsigned int j=1; j<n-1; j+=1){
								set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j, Field_journey[0][i][j]);
								set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field_journey, 0, i, j, 0);
							}
						}
						
						if (opague >= 1) {
							opague_builder (Field, Sf_opague, m, n, (geben%number_of_players)+1, opague, AOP, Sf_allocation, allocation, number_of_players);
							show_field (Sf_permutations, Sf_opague, Sf_opague, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
						} else {
							show_field (Sf_permutations, Sf_opague, Field, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
						}
						
					}
				}
				
				if (intensity_loss_per_line_multiplication != 0){
					if (((g-1)%13) == 12){
						if (opague >= 1) {
							opague_builder (Field, Sf_opague, m, n, (geben%number_of_players)+1, opague, AOP, Sf_allocation, allocation, number_of_players);
							show_field (Sf_permutations, Sf_opague, Sf_opague, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
						} else {
							show_field (Sf_permutations, Sf_opague, Field, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
						}
						
						printf (" \n");
						printf (" \n");
						printf ("	It is time for a projection... \n");
						printf (" \n");
						projection_maker (Field, number_of_players, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, direction, intensity_minimum, intensity_loss_per_line_multiplication, m, n);
						
					}
				}
			}
			
			if (gamemode_played == Race) {
				if (journey == 1){
					if (((g-1)%(2*freq)) == (2*freq-1)){
						printf (" \n");
						printf (" \n");
						printf ("	It is time for a journey... \n");
						printf (" \n");
						for (unsigned int i=1; i<m-1; i+=1){
							for (unsigned int j=1; j<n-1; j+=1){
								if (Field[0][i][j+1] != 7) {	//Schub um 1
									set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j+1, Field_journey[0][i][j]);
									set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field_journey, 0, i, j, 0);
								} else if (Field[0][i][j] == 7) {
									set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field_journey, 0, i, j, 0);
								}
							}
						}
						
						if (opague >= 1) {
							opague_builder (Field, Sf_opague, m, n, (geben%number_of_players)+1, opague, AOP, Sf_allocation, allocation, number_of_players);
							show_field (Sf_permutations, Sf_opague, Sf_opague, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
						} else {
							show_field (Sf_permutations, Sf_opague, Field, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
						}
						
					}
				}
				
				if (intensity_loss_per_line_multiplication != 0){
					if (((g-1)%(2*freq-2)) == (2*freq-3)){
						if (opague >= 1) {
							opague_builder (Field, Sf_opague, m, n, (geben%number_of_players)+1, opague, AOP, Sf_allocation, allocation, number_of_players);
							show_field (Sf_permutations, Sf_opague, Sf_opague, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
						} else {
							show_field (Sf_permutations, Sf_opague, Field, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
						}
						
						printf (" \n");
						printf (" \n");
						printf ("	It is time for a projection... \n");
						printf (" \n");
						projection_maker (Field, number_of_players, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, direction, intensity_minimum, intensity_loss_per_line_multiplication, m, n);
						
					}
				}
			}
			
			if ((gamemode_played == Hunt)||(gamemode_played == Arena)||(gamemode_played == Ulcer)||(gamemode_played == Survive)||(gamemode_played == Sand)) {
				if (journey == 1){
					if (((10*(number_of_players - player_counter) - 1) - ((g-all_turns_correction-1)%(10*(number_of_players - player_counter) - 1))) == 1){
						if (opague >= 1) {
							opague_builder (Field, Sf_opague, m, n, (geben%number_of_players)+1, opague, AOP, Sf_allocation, allocation, number_of_players);
							show_field (Sf_permutations, Sf_opague, Sf_opague, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
						} else {
							show_field (Sf_permutations, Sf_opague, Field, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
						}
						
						printf (" \n");
						printf (" \n");
						printf ("	It is time for a journey... \n");
						printf (" \n");
						for (unsigned int i=1; i<m-1; i+=1){
							for (unsigned int j=1; j<n-1; j+=1){
								if ((Field[0][i][j] != 77)||(gamemode_played != Dynamic)) {	//The ball has to exist.
									set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j, Field_journey[0][i][j]);
									set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field_journey, 0, i, j, 0);
								} else {
									set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j, 77);
									set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field_journey, 0, i, j, 0);
								}
							}
						}
						
					}
				}
				
				if (intensity_loss_per_line_multiplication != 0){
					if (((9*(number_of_players - player_counter) - 1) - ((g-all_turns_correction-1)%(9*(number_of_players - player_counter) - 1))) == 1){
						if (opague >= 1) {
							opague_builder (Field, Sf_opague, m, n, (geben%number_of_players)+1, opague, AOP, Sf_allocation, allocation, number_of_players);
							show_field (Sf_permutations, Sf_opague, Sf_opague, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
						} else {
							show_field (Sf_permutations, Sf_opague, Field, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
						}
						
						printf (" \n");
						printf (" \n");
						printf ("	It is time for a projection... \n");
						printf (" \n");
						projection_maker (Field, number_of_players, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, direction, intensity_minimum, intensity_loss_per_line_multiplication, m, n);
						
					}
				}
			}
			
			// printf("	gamemode_played = %u \n", gamemode_played);	//test
			// printf("	Rain = %u \n", Rain);	//test
			
			if (gamemode_played == Rain) {
				
				if (opague >= 1) {
					opague_builder (Field, Sf_opague, m, n, (geben%number_of_players)+1, opague, AOP, Sf_allocation, allocation, number_of_players);
					show_field (Sf_permutations, Sf_opague, Sf_opague, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
				} else {
					show_field (Sf_permutations, Sf_opague, Field, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
				}
				
				printf("\n");
				printf("\n");
				printf("\n");
				printf("\n");
				printf("\n");
				printf("\n");
				printf("\n");
				
				if (rain == 1){
					printf("		rain-Characteristics: Push \n");
				} else if (rain == 2){
					printf("		rain-Characteristics: Destroy \n");
				} else if (rain == 31){
					printf("		rain-Characteristics: Explode \n");
				} else if (rain == 32){
					printf("		rain-Characteristics: Explode & survival \n");
				} else if (rain == 4){
					printf("		rain-Characteristics: Transform \n");
				} else if (rain == 5){
					printf("		rain-Characteristics: Teleport \n");
				} else if (rain == 6){
					printf("		rain-Characteristics: Mixed \n");
				}
				
				number_rain = use_number;
				
				if ((rain_speed == 0) && (((g-1)%4) >= 2)){
					printf("	\n");
					printf("	Falling slowly...\n");
					printf("	\n");
					if (opague >= 1) {
						show_field (Sf_permutations, Sf_opague, Sf_opague, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);	//already build
					} else {
						show_field (Sf_permutations, Sf_opague, Field, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
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
						if (geben == 1){
							for (unsigned int i=m-2; i>0; i-=1){
								for (unsigned int j=0; j<((n-1)/2); j+=1){
									if (Field[0][i][j] == 7){
										if (Field[0][i+1][j] != 0){
											
											if (rain == 1){
												unsigned int mem;
												mem = i;
												while ((Field[0][i+1][j] != 0)&&((i+1)<=(m-2))){
													if ((i+1)<=(m-2)){
														set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, mem, j, Field[0][i+1][j]);
													}
													
													if (i == mem) {
														
														if ((Field[0][mem+2][j] == 0)&&((mem+2)<=(m-2))) {
															set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, mem+2, j, Field[0][mem][j]);
															break;
														} else if ((Field[0][mem+2][j] != 0)&&((mem+2)<=(m-2))) {
															set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, mem+1, j, Field[0][mem+2][j]);
															set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, mem+2, j, Field[0][mem][j]);
															if ((Field[0][mem+3][j] == 0)&&((mem+3)<=(m-2))) {
																set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, mem+3, j, Field[0][mem+1][j]);
															}
														}
														
														i += 2;
													} else {
														
														i += 1;
														
														set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j, Field[0][mem+1][j]);
														
														if ((Field[0][i+1][j] == 0)&&((i+1)<=(m-2))){
															set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i+1, j, Field[0][mem][j]);
															break;
														}
														set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, mem+1, j, Field[0][mem][j]);
													}
												}
												i = mem;
												set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j, 0);
												if (i < (m-2)) {
													set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i+1, j, 7);
												}
												
											} else if (rain == 2){
												set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i+1, j, 7);
												set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j, 0);

											} else if (rain == 31){
												for (unsigned int h=i; h<=i+2; h+=1){
													for (unsigned int k=j-1; k<=j+1; k+=1){
														if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
															set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, h, k, 0);
														}
													}
												}
											} else if (rain == 32){
												for (unsigned int h=i; h<=i+2; h+=1){
													for (unsigned int k=j-1; k<=j+1; k+=1){
														if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
															if (Field[0][h][k] == 7){
																set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, h, k, geben);
															} else {
																set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, h, k, 0);
															}
														}
													}
												}
												set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j, 0);
												set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i+1, j, 0);
											} else if (rain == 4){
												if((Field[0][i-1][j] == geben)||(Field[0][i+1][j] == geben)||(Field[0][i][j-1] == geben)||(Field[0][i][j+1] == geben)){
													set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j, geben);
												} else {
													if (i != (m-2)){
														set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i+1, j, 7);
													}
													set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j, 0);
												}
											} else if (rain == 5){
												
												if (Field[0][i+1][j] == geben){
													set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i-1, j, geben);
													set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i+1, j, 0);
												} else if (Field[0][i][j-1] == geben){
													set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j+1, geben);
													set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j-1, 0);
												} else if ((Field[0][i][j+1] == geben) && (((Field[0][i][j+2] != 7) || (Field[0][i+1][j+2] != geben)) && (Field[0][i-1][j+1] != 7))){
													set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j-1, geben);
													set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j+1, 0);
												} else if ((Field[0][i-1][j] == geben) && (Field[0][i-2][j] != 7) && (Field[0][i-1][j-1] != 7)){   
													set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i+1, j, geben);
													set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i-1, j, 0);
												}
												set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i+1, j, 7);
												set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j, 0);
											}
										} else {
											
											if (rain == 5){
												if (Field[0][i+1][j] == geben){
													set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i-1, j, geben);
													set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i+1, j, 0);
												} else if (Field[0][i][j-1] == geben){
													set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j+1, geben);
													set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j-1, 0);
												} else if ((Field[0][i][j+1] == geben) && (((Field[0][i][j+2] != 7) || (Field[0][i+1][j+2] != geben)) && (Field[0][i-1][j+1] != 7))){
													set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j-1, geben);
													set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j+1, 0);
												} else if ((Field[0][i-1][j] == geben) && (Field[0][i-2][j] != 7) && (Field[0][i-1][j-1] != 7)){   
													set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i+1, j, geben);
													set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i-1, j, 0);
												}
											}
											if (rain == 4){
												if((Field[0][i-1][j] == geben)||(Field[0][i+1][j] == geben)||(Field[0][i][j-1] == geben)||(Field[0][i][j+1] == geben)){
													set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j, geben);
												} else {
													if (i != (m-2)){
														set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i+1, j, 7);
													}
													set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j, 0);									
												}
											} else {
												if (i != (m-2)){
													set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i+1, j, 7);
												}
												set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j, 0);
											}
										}
									}
								}
							}
							if (rain_drops == 1){
								set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, 1, number_rain, 7);
							} else if (rain_drops == 2){
								set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, 1, number_rain, 7);
								set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, 1, ((n-1)/2)-number_rain, 7);
							} else if (rain_drops == 4){
								for (unsigned int s=0; s<(n-1)/2; s+=1){
									if ((s != number_rain)&&(s != ((n-1)/2)-number_rain)){
										set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, 1, s, 7);
									}
								}
							} else if (rain_drops == 5){
								for (unsigned int s=0; s<(n-1)/2; s+=1){
									if (s != number_rain){
										set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, 1, s, 7);
									}
								}
							} else if (rain_drops == 6){
								for (unsigned int s=0; s<(n-1)/2; s+=1){
									set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, 1, s, 7);
								}
							}
							
						} else if (geben == 2) {
							for (unsigned int i=m-2; i>0; i-=1){
								for (unsigned int j=(n-2); j>((n-1)/2); j-=1){
									if (Field[0][i][j] == 7){
										if (Field[0][i+1][j] != 0){
											
											if (rain == 1){
												unsigned int mem;
												mem = i;
												while ((Field[0][i+1][j] != 0)&&((i+1)<=(m-2))){
													if ((i+1)<=(m-2)){
														set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, mem, j, Field[0][i+1][j]);
													}
													
													if (i == mem) {
														
														if ((Field[0][mem+2][j] == 0)&&((mem+2)<=(m-2))) {
															set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, mem+2, j, Field[0][mem][j]);
															break;
														} else if ((Field[0][mem+2][j] != 0)&&((mem+2)<=(m-2))) {
															set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, mem+1, j, Field[0][mem+2][j]);
															set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, mem+2, j, Field[0][mem][j]);
															if ((Field[0][mem+3][j] == 0)&&((mem+3)<=(m-2))) {
																set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, mem+3, j, Field[0][mem+1][j]);
															}
														}
														
														i += 2;
													} else {
														
														i += 1;
														
														set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j, Field[0][mem+1][j]);
														
														if ((Field[0][i+1][j] == 0)&&((i+1)<=(m-2))){
															set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i+1, j, Field[0][mem][j]);
															break;
														}
														set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, mem+1, j, Field[0][mem][j]);
														
													}
												}
												i = mem;
												set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j, 0);
												if (i < (m-2)) {
													set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i+1, j, 7);
												}
											} else if (rain == 2){
												set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i+1, j, 7);
												set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j, 0);
											} else if (rain == 31){
												for (unsigned int h=i; h<=i+2; h+=1){
													for (unsigned int k=j-1; k<=j+1; k+=1){
														if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
															set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, h, k, 0);
														}
													}
												}
											} else if (rain == 32){
												for (unsigned int h=i; h<=i+2; h+=1){
													for (unsigned int k=j-1; k<=j+1; k+=1){
														if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
															if (Field[0][h][k] == 7){
																set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, h, k, geben);
															} else {
																set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, h, k, 0);
															}
														}
													}
												}
												set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j, 0);
												set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i+1, j, geben);
											} else if (rain == 4){
												if((Field[0][i-1][j] == geben)||(Field[0][i+1][j] == geben)||(Field[0][i][j-1] == geben)||(Field[0][i][j+1] == geben)){
													set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j, geben);
												} else {
													if (i != (m-2)){
														set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i+1, j, 7);
													}
													set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j, 0);
												}
											} else if (rain == 5){
												if (Field[0][i+1][j] == geben){
													set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i-1, j, geben);
													set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i+1, j, 0);
												} else if (Field[0][i][j+1] == geben){
													set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j-1, geben);
													set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j+1, 0);
												} else if ((Field[0][i][j-1] == geben) && ((Field[0][i][j-2] != 7)||(Field[0][i+1][j-2] != geben)) &&(Field[0][i-1][j-1] != 7)){
													set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j+1, geben);
													set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j-1, 0);
												} else if ((Field[0][i-1][j] == geben) && (Field[0][i-2][j] != 7) && (Field[0][i-1][j+1] != 7)){
													set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i+1, j, geben);
													set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i-1, j, 0);
												}
												set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i+1, j, 7);
												set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j, 0);
											}
										} else {
											
											if (rain == 5){
												if (Field[0][i+1][j] == geben){
													set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i-1, j, geben);
													set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i+1, j, 0);
												} else if (Field[0][i][j+1] == geben){
													set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j-1, geben);
													set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j+1, 0);
												} else if ((Field[0][i][j-1] == geben) && ((Field[0][i][j-2] != 7)||(Field[0][i+1][j-2] != geben)) &&(Field[0][i-1][j-1] != 7)){
													set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j+1, geben);
													set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j-1, 0);
												} else if ((Field[0][i-1][j] == geben) && (Field[0][i-2][j] != 7) && (Field[0][i-1][j+1] != 7)){
													set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i+1, j, geben);
													set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i-1, j, 0);
												}
											}
											
											if (rain == 4){
												if((Field[0][i-1][j] == geben)||(Field[0][i][j-1] == geben)||(Field[0][i][j+1] == geben)){
													set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j, geben);
												} else {
													if (i != (m-2)){
														set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i+1, j, 7);
													}
													set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j, 0);									
												}
											} else {
												if (i != (m-2)){
													set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i+1, j, 7);
												}
												set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j, 0);
											}
										}
									}
								}
							}
							if (rain_drops == 1){
								set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, 1, n-(1+number_rain), 7);
							} else if (rain_drops == 2){
								set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, 1, n-(1+number_rain), 7);
								set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, 1, ((n-1)/2)+number_rain, 7);
								
							} else if (rain_drops == 4){
								for (unsigned int s=(n+1)/2; s<(n-1); s+=1){
									if ((s != (n-(1+number_rain)))&&(s != (((n-1)/2)+number_rain))){
										set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, 1, s, 7);
									}
								}
							} else if (rain_drops == 5){
								for (unsigned int s=(n+1)/2; s<(n-1); s+=1){
									if (s != (n-(1+number_rain))){
										set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, 1, s, 7);
									}
								}
							} else if (rain_drops == 6){
								for (unsigned int s=(n+1)/2; s<(n-1); s+=1){
									set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, 1, s, 7);
								}
							}
							
						}
						number_rain = (number_rain%6) + 1;
						if (opague >= 1) {
							show_field (Sf_permutations, Sf_opague, Sf_opague, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
						} else {
							show_field (Sf_permutations, Sf_opague, Field, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
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
					set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, 0, j, 0);
					set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, m-1, j, 0);
				}
				for (unsigned int i=0; i<m; i+=1){
					set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, 0, 0);
					set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, n-1, 0);
				}
				
				printf("\n");
				printf("		Get: [1][7] \n");
				printf("\n");
				
				if (Field[0][1][((n-1)/2)] != 0){
					show_field (Sf_permutations, Sf_opague, Field, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
					for (unsigned int p=1; p<=number_of_players; p+=1) {
						if (Field[0][1][((n-1)/2)] == p){
							printf ("	Sieg: 	Spieler %u \n", p);
						}
					}
					break;
				}
				for (unsigned int p=1; p<=number_of_players; p+=1) {
					if ((Field[0][1][((n-3)/2)] == p)||(Field[0][1][((n+1)/2)] == p)||(Field[0][2][((n-1)/2)] == p)){
						numbers_of_[p][0][0] += 1;
					}
				}
				
				for (unsigned int i=1; i<m-1; i+=1){
					for (unsigned int j=1; j<n-1; j+=1){
						if (Field[0][i][j] == 2){
							ges[2] += 1;
						}
					}
				}
				if (ges[2] == 0){
					if (rain_obj == 1){
						set_triangle_unten_rechts (inverted, Field, 1, m-2, n-2);
					} else {
						printf("	Sieg:	Spieler 1 \n");
						break;
					}
					
				}
				ges[2] = 0;
				
				
				for (unsigned int i=1; i<m-1; i+=1){
					for (unsigned int j=1; j<n-1; j+=1){
						if (Field[0][i][j] == 1){
							ges[1] += 1;
						}
					}
				}
				if (ges[1] == 0){
					if (rain_obj == 1){
						set_triangle_unten_links (inverted, Field, 1, m-2, 1);
					} else {
						printf("	Sieg:	Spieler 2 \n");
						break;
					}
					
				}
				ges[1] = 0;
			}
			
			if (gamemode_played == Race) {
				
				if ((g-1)%freq == (freq-1)){
					count_freq += 1;
					if (count_freq == n-4){
						printf("	Both lost! \n");
						show_field (Sf_permutations, Sf_opague, Field, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
						break;
					}
					printf("\n");
					printf("\n");
					printf("	It moved forward! \n");
					printf("\n");
					printf("\n");
					ahead (Field, m, count_freq, Sf_allocation, allocation, Sf_opague, number_of_players, geben);
					
					if (opague >= 1) {
						opague_builder (Field, Sf_opague, m, n, (geben%number_of_players)+1, opague, AOP, Sf_allocation, allocation, number_of_players);
						show_field (Sf_permutations, Sf_opague, Sf_opague, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
					} else {
						show_field (Sf_permutations, Sf_opague, Field, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
					}
				}
				
				for (unsigned int p=1; p<=number_of_players; p+=1) {
					for (unsigned int i=1; i<(m-1); i+=1){
						if (Field[0][i][n-3] == p){
							numbers_of_[p][0][0] += 1;
							break;
						}
					}
				}
				
			}
			
			if (gamemode_played == Fall) {
				
				if (((g-1)%turns_per_drop) == 1){
					for (unsigned int j=1; j<n-1; j+=1){
						if (Field[0][m-2][j] == 7){
							if ((var_[1] == 1010)||(var_[2] == 1010*2)){
								if (fall_back == (n-1)/2){
									Points[0] -= 1;
								} else if (fall_back < (n-1)/2){
									Points[2] -= (((n-1)/2) - j);
								} else if (fall_back > (n-1)/2){
									Points[1] -= (j - (n-1)/2);
								}
							}
							set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, 1, (n-1)/2, 7);
							set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, m-2, j, 0);
							fall_controll = 1;
							
							printf ("\n");
							printf ("\n");
							printf ("\n");
							printf ("	It reached the ground!\n");
							printf ("\n");
							
							if (opague >= 1) {
								opague_builder (Field, Sf_opague, m, n, (geben%number_of_players)+1, opague, AOP, Sf_allocation, allocation, number_of_players);
								show_field (Sf_permutations, Sf_opague, Sf_opague, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
							} else {
								show_field (Sf_permutations, Sf_opague, Field, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
							}
							
							if (j == (n-1)/2){
								Points[0] += 1;
								printf ("	It is an undecided #-square! \n");
							} else if (j < (n-1)/2){
								Points[2] += ((n-1)/2) - j;
								printf ("	Points player 2:	+ %u \n", ((n-1)/2) - j);
							} else if (j > (n-1)/2){
								Points[1] += (j - (n-1)/2);
								printf ("	Points player 1:	+ %u \n", (j - (n-1)/2));
							}
							fall_back = j;
							
							if (journey == 1){			//Übertragung		journey-Frequenz = Fall-Frequenz
								
								printf ("\n");
								printf ("\n");
								printf ("	It is time for a journey... \n");
								printf ("\n");
								
								for (unsigned int i=1; i<m-1; i+=1){
									for (unsigned int j=1; j<n-1; j+=1){
										if (Field[0][i][j] != 7){
											set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j, Field_journey[0][i][j]);
											set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field_journey, 0, i, j, 0);
										} else if (Field[0][i][j] == 7) {
											set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field_journey, 0, i, j, 0);
										}
									}
								}
							}
							
							break;
						}
					}
				}
				
				if ((((g-1)%turns_per_drop) == 1)&&(fall_controll != 1)){
					for (unsigned int i=1; i<m-2; i+=1){
						for (unsigned int j=1; j<n-1; j+=1){
							if (Field[0][i][j] == 7){
								set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j, 0);
								if ((i+speed_of_fall) <= (m-2)) {
									for (unsigned int k=i; k<(i+speed_of_fall); k+=1) {
										set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, k, j, 0);
									}
									set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i+speed_of_fall, j, 7);
								} else {
									set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, m-2, j, 7);
								}
								
								einmal = 1;
								printf ("\n");
								printf ("\n");
								printf ("\n");
								printf ("	It fell down!\n");
								printf ("\n");
								
								if (opague >= 1) {
									opague_builder (Field, Sf_opague, m, n, (geben%number_of_players)+1, opague, AOP, Sf_allocation, allocation, number_of_players);
									show_field (Sf_permutations, Sf_opague, Sf_opague, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
								} else {
									show_field (Sf_permutations, Sf_opague, Field, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
								}
								
								break;
							}
						}
						if (einmal == 1){
							break;
						}
					}
					einmal = 0;
				}
				fall_controll = 0;
				
				if ((var_[1] != 1010) && (var_[2] != 1010*2)){
					if (Points[1] > Points[2]){
						numbers_of_[1][0][0] += 1;
					}
					if (Points[1] < Points[2]){
						numbers_of_[2][0][0] += 1;
					}
				}
				
				if (Points[1] >= points_for_win){		//Spiel-Ende
					printf ("	Sieg: player 1 \n");
					break;
				}
				if (Points[2] >= points_for_win){
					printf ("	Sieg: player 2 \n");
					break;
				}
			}
			
			
			
			if ((gamemode_played == Classic)||(gamemode_played == Collect)||(gamemode_played == Fall)||(gamemode_played == Fight)||(gamemode_played == Race)) {
				for (unsigned int i=1; i<m-1; i+=1){
					for (unsigned int j=1; j<n-1; j+=1){
						if (Field[0][i][j] == 2){
							ges[2] += 1;
						}
					}
				}
				if (ges[2] == 0){
					printf("	Sieg:	Spieler 1 \n");
					break;
				} else if ((ges[2]<5)&&(gamemode_played == Fight)){
					numbers_of_[2][0][0] += 1;
				}
				/*if (ges[2] > limit_at_all){	//test
					printf("too much\n");
				}*/
				ges[2] = 0;
				
				
				for (unsigned int i=1; i<m-1; i+=1){
					for (unsigned int j=1; j<n-1; j+=1){
						if (Field[0][i][j] == 1){
							ges[1] += 1;
						}
					}
				}
				if (ges[1] == 0){
					printf("	Sieg:	Spieler 2 \n");
					break;
				} else if ((ges[1]<5)&&(gamemode_played == Fight)){
					numbers_of_[1][0][0] += 1;
				}
				/*if (ges[1] > limit_at_all){	//test
					printf("too much\n");
				}*/
				ges[1] = 0;
			}
			
			if (gamemode_played == Contact) {
				for (unsigned int i=1; i<m-1; i+=1){
					for (unsigned int j=1; j<n-1; j+=1){
						if (Field[0][i][j] == 2){
							ges[2] += 1;
						}
					}
				}
				if (ges[2] <= 5){
				numbers_of_[2][0][0] += 1;
				}
				
				if (ges[2] == 0){
					printf("\n");
					printf("	Sieg:	Spieler 1 \n");
					show_field (Sf_permutations, Sf_opague, Field, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
					break;
				}
				ges[2] = 0;
				
				
				for (unsigned int i=1; i<m-1; i+=1){
					for (unsigned int j=1; j<n-1; j+=1){
						if (Field[0][i][j] == 1){
							ges[1] += 1;
						}
					}
				}
				if (ges[1] <= 5){
					numbers_of_[1][0][0] += 1;
				}
				
				if (ges[1] == 0){
					printf("\n");
					printf("	Sieg:	Spieler 2 \n");
					show_field (Sf_permutations, Sf_opague, Field, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
					break;
				}
				ges[1] = 0;
			}
			
			
			if (gamemode_played == Hunt) {
				unsigned int a;
				a = 0;
				for (unsigned int i=1; i<m-1; i+=1){
					for (unsigned int j=1; j<n-1; j+=1){
						if (Field[0][i][j] == 11){
							
							printf("\n");
							
							if (Field[0][i][j-1] > 1) {
								printf (" Sieg: Spieler %u \n", Field[0][i][j-1]);
								a += 1;
							}
							if (Field[0][i][j+1] > 1) {
								if (a == 0) {
									printf (" Sieg: Spieler %u \n", Field[0][i][j+1]);
								}
								a += 1;
							}
							if (Field[0][i-1][j] > 1) {
								if (a == 0) {
									printf (" Sieg: Spieler %u \n", Field[0][i-1][j]);
								}
								a += 1;
							}
							if (Field[0][i+1][j] > 1) {
								if (a == 0) {
									printf (" Sieg: Spieler %u \n", Field[0][i+1][j]);
								}
								a += 1;
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
							if (Field[0][i+1][j+1] > 1) {
								for (unsigned int p=2; p<=number_of_players; p+=1) {
									if (Field[0][i+1][j+1] == p) {
										numbers_of_[p][0][0] += 1;
									}
								}
							}
							if (Field[0][i-1][j+1] > 1) {
								for (unsigned int p=2; p<=number_of_players; p+=1) {
									if (Field[0][i+1][j+1] == p) {
										numbers_of_[p][0][0] += 1;
									}
								}
							}
							if (Field[0][i+1][j-1] > 1) {
								for (unsigned int p=2; p<=number_of_players; p+=1) {
									if (Field[0][i+1][j+1] == p) {
										numbers_of_[p][0][0] += 1;
									}
								}
							}
							if (Field[0][i-1][j-1] > 1) {
								for (unsigned int p=2; p<=number_of_players; p+=1) {
									if (Field[0][i+1][j+1] == p) {
										numbers_of_[p][0][0] += 1;
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
					show_field (Sf_permutations, Sf_opague, Field, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
					break;
				}
				
				a = 0;
				if ((round_counter == rtc)&&(geben == number_of_players)) {
					printf("	Sieg: Spieler 1");
					break;
				}
				
				for (unsigned int i=1; i<m-1; i+=1){
					for (unsigned int j=1; j<n-1; j+=1){
						for (unsigned int p=1; p<=number_of_players; p+=1) {
							if (Field[0][i][j] == p) {
								ges[p] += 1;
								break;
							}
						} 
					}
				}
				if (ges[1] == 0) {
					printf("		Niederlage: Spieler 1 \n");
					break;
				} else {
					player_counter = who_is_out (ges, number_of_players, player_counter);
				}
				
				ges[1] = 0;
				for (unsigned int p=2; p<=number_of_players; p+=1) {
					if (ges[p] < 1000) {
						ges[p] = 0;
					}
				} 
				
				if (player_counter == (number_of_players - 1)) {
					printf("		Game over. \n		Sieg: Spieler 1. \n");
					show_field (Sf_permutations, Sf_opague, Field, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
					break;
				}
			}
			
			
			if (gamemode_played == Arena) {
				for (unsigned int i=1; i<m-1; i+=1){
					for (unsigned int j=1; j<n-1; j+=1){
						for (unsigned int p=1; p<=number_of_players; p+=1) {
							if (Field[0][i][j] == p) {
								ges[p] += 1;
								break;
							}
						}
					}
				}
				
				player_counter = who_is_out (ges, number_of_players, player_counter);
				
				if (player_counter == (number_of_players - 1)) {
					printf("		Game over, you can see the master of the Arena. \n");
					show_field (Sf_permutations, Sf_opague, Field, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
					break;
				}
				if (player_counter == number_of_players) {
					printf("		Game over, everybody died. \n");
					show_field (Sf_permutations, Sf_opague, Field, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
					break;
				}
				
				if ((round_counter == rtp)&&(geben == number_of_players)) {
					printf(" \n ");
					printf("	Game over. \n ");
					printf(" \n ");
					for (unsigned int p=limit_at_all; p>0; p-=1) {
						for (unsigned int q=1; q<=number_of_players; q+=1) {
							if (ges[q] == p) {
								printf("	Spieler %u: %u \n", q, p);
							}
						}
						printf("\n");
						printf("\n");
					}
					break;
				}
				
				for (unsigned int p=1; p<=number_of_players; p+=1) {
					if (ges[p] < 1000) {
						ges[p] = 0;
					}
				}
				
			}
			
			if (gamemode_played == Ulcer) {
				
				for (unsigned int i=1; i<m-1; i+=1){
					for (unsigned int j=1; j<n-1; j+=1){
						for (unsigned int p=1; p<=number_of_players; p++) {
							if ((Field[0][i][j] == p)&&(ges[p] < 1000)) {
								ges[p] += 1;
								if (ulcer_start[p] == missing) {
									ulcer_start[p] = existing;
								}
								break;
							}
						}
					}
				}
				
				for (unsigned int p=1; p<=number_of_players; p+=1) {
					ges[0] += ges[p];
				}
				
				if ((ges[1] == 0)&&(ulcer_start[1] == existing)&&(geben == 1)) {
					ulcer_start[1] = missing;
					if (ulcer_lifes[1] > 0) {
						printf("		Spieler 1, you lost a life. \n");
						ulcer_lifes[1] -= 1;
					} else if (ulcer_start[0] == 0) {
						printf("		Niederlage: Spieler 1 \n");
						ulcer_start[0] = 100;
						break;
					} else if (ulcer_start[0] == 1) {
						printf("		Spieler 1, you are out. \n");
						player_counter += 1;
						ges[1] = 1010;
						
						for (unsigned int p=1; p<=number_of_players; p+=1) {
							if (out_counter[p] == 0) {
								out_counter[p] = 1;
								break;
							}
						}
					}
					
				}
				
				for (unsigned int p=1; p<=number_of_players; p+=1) {
					
					if ((ges[p] == 0)&&(number_of_players >= p)&&(ulcer_start[p] == existing)&&(geben == p)) {
						ulcer_start[p] = missing;
						if (ulcer_lifes[p] > 0) {
							printf("		Spieler %u, you lost a life. \n", p);
							ulcer_lifes[p] -= 1;
						} else {
							printf("		Spieler %u, you are out. \n", p);
							player_counter += 1;
							ges[p] = 1010*p;
							
							for (unsigned int q=1; q<=number_of_players; q+=1) {
								if (out_counter[q] == 0) {
									out_counter[q] = p;
									break;
								}
							}
						}
					}
				}
				
				if (player_counter == (number_of_players - 1)) {
					printf("		Game over, you can see the master of Ulcer. \n");
					show_field (Sf_permutations, Sf_opague, Field, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
					break;
				}
				if (player_counter == number_of_players) {
					printf("		Game over, everybody died. \n");
					show_field (Sf_permutations, Sf_opague, Field, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
					break;
				}
				if ((geben == number_of_players)&&(rtp == round_counter)) {
					printf("\n");
					printf("	Congratulations Player 1, you are still alive!\n");
					printf("\n");
					break;
				}
				if (ges[0] == 0) {
					printf("		This game stucked. Try again! \n");
				}
				
				for (unsigned int p=0; p<=number_of_players; p+=1) {
					if (ges[p] < 1000) {
						ges[p] = 0;
					}
				}
				
				// ges-x in ges[x], done
			}
			
			if (gamemode_played == Dynamic) {	
				for (unsigned int i=1; i<m-1; i+=1){
					for (unsigned int j=1; j<n-1; j+=1){
						for (unsigned int p=1; p<=number_of_players; p+=1) {
							if (Field[0][i][j] == p) {
								ges[p] += 1;
								break;
							}
						}
					}
				}
				
				player_counter = who_is_out (ges, number_of_players, player_counter);
				
				for (unsigned int p=2; p<=AOP; p++) {
					if (number_of_players == p) {
						if (player_counter == p-1) {
							for (unsigned int t=1; t<=number_of_players; t+=1) {
								printf("\n");
								if (ges[t] != t*1010) {
									printf("	Sieg: Spieler %u \n", t);
								}
							}
							break;
						}
					}
				}
				
				if (number_of_players == 5) {
					if ((player_counter == 3)&&(ges[4] != 4040)&&(ges[5] != 5050)) {
						for (unsigned int t=1; t<=number_of_players; t+=1) {
							printf("\n");
							if (ges[t] != t*1010) {
								printf("	Sieg: Spieler %u \n", t);
							}
						}
						break;
					}
				} else if (number_of_players == 6) {
					if ((player_counter == 4)&&(((ges[2] != 2020)&&(ges[5] != 5050))||((ges[4] != 4040)&&(ges[1] != 1010))||((ges[3] != 3030)&&(ges[6] != 6060)))) {
						for (unsigned int t=1; t<=number_of_players; t+=1) {
							printf("\n");
							if (ges[t] != t*1010) {
								printf("	Sieg: Spieler %u \n", t);
							}
						}
						break;
					}
				} else if (number_of_players == 7) {
					if ((player_counter == 5)&&(((ges[1] != 1010)&&(ges[5] != 5050))||((ges[4] != 4040)&&(ges[7] != 7070))||((ges[3] != 3030)&&(ges[6] != 6060)))) {
						for (unsigned int t=1; t<=number_of_players; t+=1) {
							printf("\n");
							if (ges[t] != t*1010) {
								printf("	Sieg: Spieler %u \n", t);
							}
						}
						break;
					}
				} else if (number_of_players == 8) {
					if ((player_counter == 6)&&(((ges[1] != 1010)&&(ges[5] != 5050))||((ges[3] != 3030)&&(ges[7] != 7070))||((ges[2] != 2020)&&(ges[6] != 6060))||((ges[4] != 4040)&&(ges[8] != 8080)))) {
						for (unsigned int t=1; t<=number_of_players; t+=1) {
							printf("\n");
							if (ges[t] != t*1010) {
								printf("	Sieg: Spieler %u \n", t);
							}
						}
						break;
					}
				} else if (number_of_players == 9) {
					if ((player_counter == 6)&&(((ges[1] != 1010)&&(ges[4] != 4040)&&(ges[7] != 7070))||((ges[3] != 3030)&&(ges[9] != 9090)&&(ges[6] != 6060))||((ges[2] != 2020)&&(ges[5] != 5050)&&(ges[8] != 8080)))) {
						for (unsigned int t=1; t<=number_of_players; t+=1) {
							printf("\n");
							if (ges[t] != t*1010) {
								printf("	Sieg: Spieler %u \n", t);
							}
						}
						break;
					} else if ((player_counter == 7)&&(((ges[1] != 1010)&&(ges[4] != 4040))||((ges[1] != 1010)&&(ges[7] != 7070))||((ges[4] != 4040)&&(ges[7] != 7070))||((ges[2] != 2020)&&(ges[5] != 5050))||((ges[2] != 2020)&&(ges[8] != 8080))||((ges[8] != 8080)&&(ges[5] != 5050))||((ges[3] != 3030)&&(ges[6] != 6060))||((ges[3] != 3030)&&(ges[9] != 9090))||((ges[6] != 6060)&&(ges[9] != 9090)))) {
						for (unsigned int t=1; t<=number_of_players; t+=1) {
							printf("\n");
							if (ges[t] != t*1010) {
								printf("	Sieg: Spieler %u \n", t);
							}
						}
						break;
					}
				}
				
				for (unsigned int p=1; p<=number_of_players; p+=1) {
					if (ges[p] < 1000) {
						ges[p] = 0;
					}
				}
				
			}
			
			if (gamemode_played == Survive) {
				
				for (unsigned int i=1; i<m-1; i+=1){
					for (unsigned int j=1; j<n-1; j+=1){
						for (unsigned int p=1; p<=number_of_players; p+=1) {
							if (Field[0][i][j] == p) {
								ges[p] += 1;
								break;
							}
						}
					}
				}
				
				player_counter = who_is_out (ges, number_of_players, player_counter);
				
				for (unsigned int p=1; p<=number_of_players; p+=1) {
					if (ges[p] < 1000) {
						ges[p] = 0;
					}
				}
				
			}
			
			if (gamemode_played == Sand) {
				lim = 0;
				for (unsigned j=1; j<=n-2; j++) {
					if (Field[0][1][j] != 0) {
						printf("	Sieg Spieler: %u \n", Field[0][1][j]);
						lim = 1;
						break;
					}
				}
				if (lim == 1) {
					break;
				}
				
				if ((g - all_turns_correction)%((number_of_players - player_counter)*information_code[3]) == 0) {
					
					if (opague >= 1) {
						opague_builder (Field, Sf_opague, m, n, (geben%number_of_players)+1, opague, AOP, Sf_allocation, allocation, number_of_players);
						show_field (Sf_permutations, Sf_opague, Sf_opague, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
					} else {
						show_field (Sf_permutations, Sf_opague, Field, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
					}
					
					if (information_code[1] == 1) {
						for (unsigned int i=1; i<=m-2; i++) {
							for (unsigned int j=1; j<=n-2; j++) {
								lim = 0;
								while (lim != information_code[2]) {
									if ((Field[0][i+lim][j] != 0)&&(i+lim+1 != m-1)&&(Field[0][i+lim+1][j] == 0)) {
										set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i+lim+1, j, Field[0][i+lim][j]);
										set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i+lim, j, 0);
									}
									lim += 1;
								}
								lim = 0;
							}
						}
					} else if (information_code[1] == 2) {
						for (unsigned int i=m-2; i>=1; i--) {
							for (unsigned int j=n-2; j>=1; j--) {
								lim = 0;
								while (lim != information_code[2]) {
									if ((Field[0][i+lim][j] != 0)&&(i+lim+1 != m-1)&&(Field[0][i+lim+1][j] == 0)) {
										set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i+lim+1, j, Field[0][i+lim][j]);
										set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i+lim, j, 0);
									}
									lim += 1;
								}
								lim = 0;
							}
						}
					}
				}
				
				for (unsigned int i=1; i<m-1; i+=1){
					for (unsigned int j=1; j<n-1; j+=1){
						for (unsigned int p=1; p<=number_of_players; p+=1) {
							if (Field[0][i][j] == p) {
								ges[p] += 1;
								break;
							}
						}
					}
				}
				player_counter = who_is_out (ges, number_of_players, player_counter);
				
				for (unsigned int p=1; p<=number_of_players; p+=1) {
					if (ges[p] < 1000) {
						ges[p] = 0;
					}
				}
				
				if (player_counter == number_of_players-1) {
					for (unsigned int p=1; p<=number_of_players; p++) {
						if (ges[p] != p*1010) {
							printf("	Sieg Spieler: %u \n", p);
							break;
						}
					}
					break;
				}
			}
			
			if (figures != 0) {
				if (opague >= 1) {
					opague_builder (Field, Sf_opague, m, n, (geben%number_of_players)+1, opague, AOP, Sf_allocation, allocation, number_of_players);
					show_field (Sf_permutations, Sf_opague, Sf_opague, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
				} else {
					show_field (Sf_permutations, Sf_opague, Field, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
				}
				
				figure_check (Field, m, n, number_of_players, Colored, Sf_allocation, allocation, Sf_opague, geben);
			}
			
			if (player_counter == number_of_players) {	//Notbremse
				printf("	No player left \n ");
				break;
			}
			
			g += 1;
		}
		//
		
		if (gamemode_played == Ulcer) {
			if (ulcer_start[0] == 100) {
				for (unsigned int p=1; p<=number_of_players; p+=1) {
					if (out_counter[p] == 0) {
						out_counter[p] = 1;
						break;
					}
				}
			}
			ulcer_start[0] = 0;
			printf("	Who`s still alive? \n");
			
			for (unsigned int p=1; p<=number_of_players; p+=1) {
				for (unsigned int r=1; r<=number_of_players; r+=1) {
					if (out_counter[r] == p) {
						ulcer_lifes[p] = 1000;
						break;
					}
				}
				
				if (ulcer_lifes[p] != 1000) {
					printf("	Spieler %u \n", p);
				} else {
					ulcer_lifes[p] = 0;
				}
			}
			printf("\n");
			printf("\n");
			
			printf("	Top Ulcer: \n");
			for (unsigned int p=1; p<=number_of_players; p+=1) {
				if (out_counter[1] == 0) {
					printf("		All were bad. \n");
					break;
				}
				
				if (out_counter[p] != 0) {
					if (out_counter[p] < number_of_players) {	//It is < and not <=, because the first one has not the aim to kill the last player
						printf("		No.%u: %u \n", p-ulcer_start[0], out_counter[p]+1);
					} else {
						ulcer_start[0] = 1;
					}
				}
				
			}
			printf("\n");
			printf("\n");
			
			printf("	Lifes: \n");
			for (unsigned int p=1; p<=number_of_players; p+=1) {
				printf("		Spieler %u: %u life(s) left.\n", p, ulcer_lifes[p]);
			}
			printf("\n");
			printf("\n");
			
		}
		
		printf(" \n");
		printf("	Show statistics:	yes: 1		no: 0 \n");
		lim = get_unsigned_numeric_input_with_not_more_than_1_letter ();
		if (lim == 1){
			printf("	\n");
			show_statistics (number_of_players, gamemode_played, numbers_of_, Points, exclude_counter, ulcer_lifes, ges, pere, ability, ttt);
			
		}
		
		if (gamemode_played == Hunt) {
			for (unsigned int p=0; p <= 3; p+=1) {
				information_code[p] = 1;
			}
		}
		
		printf("\n");
		printf("	Round: %u \n", round_counter);
		printf("\n");
		
		show_field (Sf_permutations, Sf_opague, Field, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
		
		printf("	\n ");
		printf("	\n ");
		printf("	Do you want to play another match?	\n		Yes: 1		No:  0 ");
		playtime = get_unsigned_numeric_input_with_not_more_than_1_letter ();
		if (playtime == 0) {
			printf("				     ___ \n ");
		} else if (playtime > 1) {
			printf("	it was a -1-, wasn't it?");
		}
		if (playtime >= 1) {
			playtime = 10;
			
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
				same[23] = use_number;
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
		// printf("	#line 6k, 1\n");	//test
		// scanf("%u", &pause);	//test
		
		unsigned_int_Vektor_Destroy (Points);
		
		// printf("	Existing Fields: %d \n ", Spielfeld_counter);	//test
		// printf("	Existing Vektors: %d \n ", Vektor_counter);	//test
		// printf("	\n ");
		// printf("	#line 6k, 2\n");	//test
		// scanf("%u", &pause);	//test
		
		int_2dim_Vektor_Destroy (dynamic_pointer_save, number_of_players+1);
		
		// printf("	Existing Fields: %d \n ", Spielfeld_counter);	//test
		// printf("	Existing Vektors: %d \n ", Vektor_counter);	//test
		// printf("	\n ");
		// printf("	#line 6k, 3\n");	//test
		// scanf("%u", &pause);	//test
		
		unsigned_int_Vektor_Destroy (position);
		
		// printf("	Existing Fields: %d \n ", Spielfeld_counter);	//test
		// printf("	Existing Vektors: %d \n ", Vektor_counter);	//test
		// printf("	\n ");
		// printf("	#line 6k, 4\n");	//test
		// scanf("%u", &pause);	//test
		
		Spielfeld_Destroy (Field, m, number_of_players);
		
		// printf("	Existing Fields: %d \n ", Spielfeld_counter);	//test
		// printf("	Existing Vektors: %d \n ", Vektor_counter);	//test
		// printf("	\n ");
		// printf("	#line 6k, 5\n");	//test
		// scanf("%u", &pause);	//test
		
		Spielfeld_Destroy (Sf_od_, m, number_of_players);
		
		// printf("	Existing Fields: %d \n ", Spielfeld_counter);	//test
		// printf("	Existing Vektors: %d \n ", Vektor_counter);	//test
		// printf("	\n ");
		// printf("	#line 6k, 6\n");	//test
		// scanf("%u", &pause);	//test
		
		Spielfeld_Destroy (Sf_nl_, m, number_of_players);
		
		// printf("	Existing Fields: %d \n ", Spielfeld_counter);	//test
		// printf("	Existing Vektors: %d \n ", Vektor_counter);	//test
		// printf("	\n ");
		// printf("	#line 6k, 7\n");	//test
		// scanf("%u", &pause);	//test
		
		Spielfeld_Destroy (Sf_opague, m, 0);
		
		// printf("	Existing Fields: %d \n ", Spielfeld_counter);	//test
		// printf("	Existing Vektors: %d \n ", Vektor_counter);	//test
		// printf("	\n ");
		// printf("	#line 6k, 8\n");	//test
		// scanf("%u", &pause);	//test
		
		Spielfeld_Destroy (numbers_of_, 7, number_of_players);
		
		// printf("	Existing Fields: %d \n ", Spielfeld_counter);	//test
		// printf("	Existing Vektors: %d \n ", Vektor_counter);	//test
		// printf("	\n ");
		// printf("	#line 6k, 9\n");	//test
		// scanf("%u", &pause);	//test
		
		Spielfeld_Destroy (stack_of_, 7, number_of_players);
		
		// printf("	Existing Fields: %d \n ", Spielfeld_counter);	//test
		// printf("	Existing Vektors: %d \n ", Vektor_counter);	//test
		// printf("	\n ");
		// printf("	#line 6k, 10\n");	//test
		// scanf("%u", &pause);	//test
		
		Spielfeld_Destroy (Field_journey, m, number_of_players);
		
		// printf("	Existing Fields: %d \n ", Spielfeld_counter);	//test
		// printf("	Existing Vektors: %d \n ", Vektor_counter);	//test
		// printf("	\n ");
		// printf("	#line 6k, 11\n");	//test
		// scanf("%u", &pause);	//test
		
		Spielfeld_Destroy (Sf_allocation, m, number_of_players+2);
		
		// printf("	Existing Fields: %d \n ", Spielfeld_counter);	//test
		// printf("	Existing Vektors: %d \n ", Vektor_counter);	//test
		// printf("	\n ");
		// printf("	#line 6k, 12\n");	//test
		// scanf("%u", &pause);	//test
		
		Spielfeld_Destroy (Sf_permutations, m, 0);
		
		// printf("	Existing Fields: %d \n ", Spielfeld_counter);	//test
		// printf("	Existing Vektors: %d \n ", Vektor_counter);	//test
		// printf("	\n ");
		// printf("	#line 6k, 13\n");	//test
		// scanf("%u", &pause);	//test
		
		Spielfeld_Destroy (Collector_of_permutation_number_c_areas, permutation_number_c, amount_of_permutation_number_c-1);
		
		// printf("	Existing Fields: %d \n ", Spielfeld_counter);	//test
		// printf("	Existing Vektors: %d \n ", Vektor_counter);	//test
		// printf("	\n ");
		// printf("	#line 6k, 14\n");	//test
		// scanf("%u", &pause);	//test
		
		Spielfeld_Destroy (Collector_of_permutation_number_b_areas, permutation_number_b, amount_of_permutation_number_b-1);
		
		// printf("	Existing Fields: %d \n ", Spielfeld_counter);	//test
		// printf("	Existing Vektors: %d \n ", Vektor_counter);	//test
		// printf("	\n ");
		// printf("	#line 6k, 15\n");	//test
		// scanf("%u", &pause);	//test
		
	}
	
	unsigned_int_Vektor_Destroy (same);
	
	// printf("	Existing Fields: %d \n ", Spielfeld_counter);	//test
	// printf("	Existing Vektors: %d \n ", Vektor_counter);	//test
	// printf("	\n ");
	// printf("	#line 6k, 16\n");	//test
	// scanf("%u", &pause);	//test
	
	return 0;
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

void int_2dim_Vektor_Destroy (int** Vektor, unsigned int m) {
	
	for (unsigned int p=0; p<m; p+=1) {
		Vektor[p] = NULL;
		free(Vektor[p]);
	}
	
	Vektor = NULL;
	free(Vektor);
	
	Vektor_counter -= 1;
}

void int_Vektor_Destroy (int* Vektor) {
	Vektor = NULL;
	free(Vektor);
	
	Vektor_counter -= 1;
}

void unsigned_int_Vektor_Destroy (unsigned int* Vektor) {
	free(Vektor);
	Vektor = NULL;
	
	Vektor_counter -= 1;
}

void Spielfeld_Destroy (Spielfeld Spiel, unsigned int m, unsigned int number_of_players){
	for (unsigned int geben=number_of_players+1; geben>0; geben-=1) {	//geben, i, j dienen nur zur Anschauung
		
		// printf("	Spielfeld_Destroy #1 \n");	//test
		
		for (unsigned int i=m; i>0; i-=1){
			Spiel[geben-1][i-1] = NULL;
			free(Spiel[geben-1][i-1]);
		}
		
		// printf("	Spielfeld_Destroy #2 \n");	//test
		
	}
	for (unsigned int geben=number_of_players+1; geben>0; geben-=1) {	//Index-Verschiebung
		Spiel[geben-1] = NULL;
		free(Spiel[geben-1]);
	}
	
	// printf("	Spielfeld_Destroy #3 \n");	//test
	
	Spiel = NULL;		//nach testen auf andere Versionen übertragen!
	free(Spiel);
	
	// printf("	Spielfeld_Destroy #4 \n");	//test
	
	Spielfeld_counter -= 1;
}

void start_normal (Spielfeld Field, unsigned int m, unsigned int n, unsigned int gamemode_played, unsigned int number_of_players, unsigned int geben, Spielfeld Sf_opague, Spielfeld Sf_allocation, unsigned int allocation, unsigned int inverted){
	
	if (gamemode_played == Classic){
		
		set_gleiter_links_unten (inverted, Field, 1, 2, n/2);		//Spieler 1
		
		//Field[0][8][3] = 2;	Field[0][9][3] = 2;	//Test
		//Field[0][8][4] = 2;	Field[0][9][6] = 2;
		//Field[0][8][5] = 2;	Field[0][10][3] = 2;
		//Field[0][8][6] = 2;	Field[0][10][4] = 2;
		
		set_gleiter_rechts_oben (inverted, Field, 2, m-3, (n/2)-1);		//Spieler 2
		
	} else if (gamemode_played == Collect){
		
		set_gleiter_links_unten (inverted, Field, 1, 2, (n-1)/2);		//Spieler 1
		
		//Field[0][9][1] = 1;	Field[0][8][5] = 1;	//Test
		//Field[0][8][5] = 1;	Field[0][8][6] = 1;
		//Field[0][2][1] = 2;	Field[0][5][2] = 1;
		//Field[0][5][5] = 1;	Field[0][5][6] = 1;
		
		set_gleiter_rechts_oben (inverted, Field, 2, m-3, (n/2)-1);		//Spieler 2
		
		Field[0][(m-1)/2][2] 	= 7;		//to Collect
		Field[0][(m-1)/2][n-3] 	= 7;
		Field[0][(m-1)/2][(n-1)/2]	= 7;
		
	} else if (gamemode_played == Contact){
		
		set_gleiter_links_unten (inverted, Field, 1, 2, n/2);		//Spieler 1
		set_triangle_oben_links (inverted, Field, 1, 1, 1);
		set_triangle_oben_rechts (inverted, Field, 1, 1, n-2);
		
		//Field[0][9][1] = 1;	Field[0][8][5] = 1;	//Test
		//Field[0][8][5] = 1;	Field[0][8][6] = 1;
		//Field[0][2][1] = 2;	Field[0][5][2] = 1;
		//Field[0][5][5] = 1;	Field[0][5][6] = 1;
		
		set_gleiter_rechts_oben (inverted, Field, 2, m-3, (n/2)-1);		//Spieler 2
		set_triangle_unten_links (inverted, Field, 2, m-2, 1);
		set_triangle_unten_rechts (inverted, Field, 2, m-2, n-2);
		
	} else if (gamemode_played == Fall){
		
		set_gleiter_rechts_oben (inverted, Field, 1, m-3, 2);		//Spieler 1
		
		//Field[0][9][1] = 1;	Field[0][8][5] = 1;	//Test
		//Field[0][8][5] = 1;	Field[0][8][6] = 1;
		//Field[0][2][1] = 2;	Field[0][5][2] = 1;
		//Field[0][5][5] = 1;	Field[0][5][6] = 1;
		
		set_gleiter_links_oben (inverted, Field, 2, m-3, n-3);		//Spieler 2
		
		Field[0][1][(n-1)/2] = 7;
		
	} else if (gamemode_played == Fight){
		
		set_gleiter_links_unten (inverted, Field, 1, 2, n/2);		//Spieler 1
		
		//Field[0][9][1] = 1;	Field[0][8][5] = 1;	//Test
		//Field[0][8][5] = 1;	Field[0][8][6] = 1;
		//Field[0][2][1] = 2;	Field[0][5][2] = 1;
		//Field[0][5][5] = 1;	Field[0][5][6] = 1;
		
		set_gleiter_rechts_oben (inverted, Field, 2, m-3, (n/2)-1);		//Spieler 2
		
	} else if (gamemode_played == Hunt){
		if (number_of_players == 2) {
			unsigned int m_2;
			m_2 = (m-1)/2;
			
			Field[0][m_2-1][3]	= 1;		//Spieler 1
			Field[0][m_2][2]	= 1;
			Field[0][m_2][3]	= 11;
			Field[0][m_2][4]	= 1;
			Field[0][m_2+1][3]	= 1;
			
			set_gleiter_unten_links (inverted, Field, 2, m_2, n-3);		//Spieler 2
			
		} else if (number_of_players == 3) {
			unsigned int m_2, n_2;
			m_2 = (m-1)/2;
			n_2 = (n-1)/2;
			
			Field[0][m_2-1][n_2] = 1;		//Spieler 1
			Field[0][m_2][n_2-1] = 1;
			Field[0][m_2][n_2]	 = 11;
			Field[0][m_2][n_2+1] = 1;
			Field[0][m_2+1][n_2] = 1;
			
			set_gleiter_unten_links (inverted, Field, 2, m_2, n-3);		//Spieler 2
			set_gleiter_oben_rechts (inverted, Field, 3, m_2, 2);		//Spieler 3
			
		} else if (number_of_players == 4) {
			unsigned int m_2, n_2;
			m_2 = (m-1)/2;
			n_2 = (n-1)/2;
			
			Field[0][m_2-2][n_2]	= 1;		//Spieler 1
			Field[0][m_2-1][n_2-1]	= 1;
			Field[0][m_2-1][n_2]	= 11;
			Field[0][m_2-1][n_2+1]	= 1;
			Field[0][m_2][n_2]		= 1;
			
			set_gleiter_rechts_oben (inverted, Field, 2, m-3, n_2);		//Spieler 2
			set_gleiter_unten_links (inverted, Field, 3, 2, n-3);		//Spieler 3
			set_gleiter_unten_rechts (inverted, Field, 4, 2, 2);		//Spieler 4
			
		} else if (number_of_players == 5) {
			unsigned int m_2, n_2;
			m_2 = (m-1)/2;
			n_2 = (n-1)/2;
			
			Field[0][m_2-1][n_2]	= 1;		//Spieler 1
			Field[0][m_2][n_2-1]	= 1;
			Field[0][m_2][n_2]		= 11;
			Field[0][m_2][n_2+1]	= 1;
			Field[0][m_2+1][n_2]	= 1;
			
			set_gleiter_oben_links (inverted, Field, 2, m-3, n-3);		//Spieler 2
			set_gleiter_links_unten (inverted, Field, 3, 2, n-3);		//Spieler 3
			set_gleiter_unten_rechts (inverted, Field, 4, 2, 2);		//Spieler 4
			set_gleiter_rechts_oben (inverted, Field, 5, m-3, 2);		//Spieler 5
			
		} else if (number_of_players == 6) {
			unsigned int m_2, nn;
			m_2 = (m-1)/2;
			nn = (n-4)/2;
			
			Field[0][m_2-1][nn]	= 1;		//Spieler 1
			Field[0][m_2][nn-1]	= 1;
			Field[0][m_2][nn]	= 11;
			Field[0][m_2][nn+1]	= 1;
			Field[0][m_2+1][nn]	= 1;
			
			set_gleiter_oben_links (inverted, Field, 2, m_2, n-3);		//Spieler 2
			set_gleiter_links_unten (inverted, Field, 3, 2, n-7);		//Spieler 3
			set_gleiter_rechts_unten (inverted, Field, 4, 2, 2);		//Spieler 4
			set_gleiter_rechts_oben (inverted, Field, 5, m-3, 2);		//Spieler 5
			set_gleiter_links_oben (inverted, Field, 6, m-3, n-7);		//Spieler 6
			
		} else if (number_of_players == 7) {
			unsigned int m_2, n_2;
			m_2 = (m-1)/2;
			n_2 = (n-1)/2;
			
			Field[0][m_2-1][n_2]	= 1;		//Spieler 1
			Field[0][m_2][n_2-1]	= 1;
			Field[0][m_2][n_2]		= 11;
			Field[0][m_2][n_2+1]	= 1;
			Field[0][m_2+1][n_2]	= 1;
			
			set_gleiter_oben_links (inverted, Field, 2, m_2, n-3);		//Spieler 2
			set_gleiter_links_unten (inverted, Field, 3, 2, n-6);		//Spieler 3
			set_gleiter_rechts_unten (inverted, Field, 4, 2, 5);		//Spieler 4
			set_gleiter_unten_rechts (inverted, Field, 5, m_2, 2);		//Spieler 5
			set_gleiter_rechts_oben (inverted, Field, 6, m-3, 5);		//Spieler 6
			set_gleiter_links_oben (inverted, Field, 7, m-3, n-6);		//Spieler 7
			
		} else if (number_of_players == 8) {
			unsigned int m_2, n_2;
			m_2 = (m-2)/2;
			n_2 = (n-1)/2;
			
			Field[0][m_2-1][n_2]	= 1;		//Spieler 1
			Field[0][m_2][n_2-1]	= 1;
			Field[0][m_2][n_2]		= 11;
			Field[0][m_2][n_2+1]	= 1;
			Field[0][m_2+1][n_2]	= 1;
			
			set_gleiter_oben_links (inverted, Field, 2, m_2, n-3);		//Spieler 2
			set_gleiter_links_unten (inverted, Field, 3, 2, n-7);		//Spieler 3
			set_gleiter_rechts_unten (inverted, Field, 4, 2, 6);		//Spieler 4
			set_gleiter_oben_rechts (inverted, Field, 5, m_2, 2);		//Spieler 5
			set_gleiter_rechts_oben (inverted, Field, 6, m-5, 4);		//Spieler 6
			set_mountain_unten (inverted, Field, 7, m-3, n_2);		//Spieler 7
			set_gleiter_rechts_oben (inverted, Field, 8, m-5, n-5);		//Spieler 8
			
		} else if (number_of_players == 9) {
			unsigned int m_2, n_2;
			m_2 = (m-1)/2;
			n_2 = (n-1)/2;
			
			Field[0][m_2-1][n_2]	= 1;		//Spieler 1
			Field[0][m_2][n_2-1]	= 1;
			Field[0][m_2][n_2]		= 11;
			Field[0][m_2][n_2+1]	= 1;
			Field[0][m_2+1][n_2]	= 1;
			
			set_mountain_rechts (inverted, Field, 2, m_2, n-3);		//Spieler 2
			set_edge_oben_rechts (inverted, Field, 3, 2, n-3);		//Spieler 3
			set_mountain_oben (inverted, Field, 4, 2, n_2);		//Spieler 4
			set_edge_oben_links (inverted, Field, 5, 2, 2);		//Spieler 5
			set_mountain_links (inverted, Field, 6, m_2, 2);		//Spieler 6
			set_edge_unten_links (inverted, Field, 7, m-3, 2);		//Spieler 7
			set_mountain_unten (inverted, Field, 8, m-3, n_2);		//Spieler 8
			set_edge_unten_rechts (inverted, Field, 9, m-3, n-3);		//Spieler 9
		}
		
	} else if (gamemode_played == Race){
		
		set_gleiter_unten_rechts (inverted, Field, 1, 2, 3);		//Spieler 1
		
		//Field[0][9][1] = 1;	Field[0][8][5] = 1;	//Test
		//Field[0][8][5] = 1;	Field[0][8][6] = 1;
		//Field[0][2][1] = 2;	Field[0][5][2] = 1;
		//Field[0][5][5] = 1;	Field[0][5][6] = 1;
		
		set_gleiter_oben_rechts (inverted, Field, 2, m-3, 3);		//Spieler 2
		
		for (unsigned int i=1; i<m-1; i+=1){
			Field[0][i][1] = 7;
		}
		Field[0][(m-1)/2][n-2] = 7;
		
	} else if (gamemode_played == Rain){
		
		set_gleiter_rechts_oben (inverted, Field, 1, m-3, 2);		//Spieler 1
		
		//Field[0][4][10] = 2;	Field[0][5][10] = 2;	//Test
		//Field[0][4][11] = 2;	Field[0][5][13] = 2;
		//Field[0][4][12] = 2;	Field[0][6][10] = 2;
		//Field[0][4][13] = 2;	Field[0][6][11] = 2;
		
		set_gleiter_links_oben (inverted, Field, 2, m-3, n-3);		//Spieler 2
		
		//Field[0][1][(n-1)/2] = 7;
		
	} else if (gamemode_played == Arena){
		if (number_of_players == 2) {
			unsigned int m_2;
			m_2 = (m-1)/2;
			
			set_gleiter_unten_rechts (inverted, Field, 1, m_2, 2);		//Spieler 1
			set_gleiter_oben_links (inverted, Field, 2, m_2, n-3);		//Spieler 2
			
		} else if (number_of_players == 3) {
			
			set_star (inverted, Field, 1, 3, 3);		//Spieler 1
			set_gleiter_unten_links (inverted, Field, 2, 4, n-3);		//Spieler 2
			set_gleiter_rechts_oben (inverted, Field, 3, m-3, 4);		//Spieler 3
			
		} else if (number_of_players == 4) {
			unsigned int m_2, n_2;
			m_2 = (m-1)/2;
			n_2 = (n-1)/2;
			
			set_gleiter_rechts_oben (inverted, Field, 1, m-3, n_2);		//Spieler 1
			set_gleiter_links_unten (inverted, Field, 2, 2, n_2);		//Spieler 2
			set_gleiter_unten_rechts (inverted, Field, 3, m_2, 2);		//Spieler 3
			set_gleiter_oben_links (inverted, Field, 4, m_2, n-3);		//Spieler 4
			
		} else if (number_of_players == 5) {
			unsigned int mm, nn;
			mm = m/2;
			nn = n/2;
			
			set_gleiter_rechts_oben (inverted, Field, 1, m-3, nn);		//Spieler 1
			set_gleiter_links_unten (inverted, Field, 2, 2, nn-1);		//Spieler 2
			set_gleiter_unten_rechts (inverted, Field, 3, mm, 2);		//Spieler 3
			set_gleiter_oben_links (inverted, Field, 4, mm-1, n-3);		//Spieler 4
			set_net_basic_two_four (inverted, Field, 5, mm-1, nn-1);	//Spieler 5
			
		} else if (number_of_players == 6) {
			unsigned int m_2;
			m_2 = (m-1)/2;
			
			set_gleiter_oben_rechts (inverted, Field, 1, m_2, 2);		//Spieler 1
			set_gleiter_unten_links (inverted, Field, 2, m_2, n-3);		//Spieler 2
			set_gleiter_rechts_unten (inverted, Field, 3, 2, n-6);		//Spieler 3
			set_gleiter_rechts_unten (inverted, Field, 4, 2, 5);		//Spieler 4
			set_gleiter_links_oben (inverted, Field, 5, m-3, 5);		//Spieler 5
			set_gleiter_links_oben (inverted, Field, 6, m-3, n-6);		//Spieler 6
			
		} else if (number_of_players == 7) {
			unsigned int mm, nn;
			mm = m/2;
			nn = n/2;
			
			set_gleiter_oben_rechts (inverted, Field, 1, mm, 2);		//Spieler 1
			set_gleiter_unten_links (inverted, Field, 2, mm-1, n-3);		//Spieler 2
			set_gleiter_rechts_unten (inverted, Field, 3, 2, n-6);		//Spieler 3
			set_gleiter_rechts_unten (inverted, Field, 4, 2, 5);		//Spieler 4
			set_gleiter_links_oben (inverted, Field, 5, m-3, 5);		//Spieler 5
			set_gleiter_links_oben (inverted, Field, 6, m-3, n-6);		//Spieler 6
			set_net_basic_two_four (inverted, Field, 7, mm-1, nn-1);	//Spieler 7
			
		} else if (number_of_players == 8) {
			
			set_gleiter_unten_rechts (inverted, Field, 1, 5, 2);		//Spieler 1
			set_gleiter_oben_links (inverted, Field, 2, 5, n-3);		//Spieler 2
			set_gleiter_links_unten (inverted, Field, 3, 2, n-6);		//Spieler 3
			set_gleiter_links_unten (inverted, Field, 4, 2, 5);		//Spieler 4
			set_gleiter_rechts_oben (inverted, Field, 5, m-3, 5);		//Spieler 5
			set_gleiter_rechts_oben (inverted, Field, 6, m-3, n-6);		//Spieler 6
			set_gleiter_unten_rechts (inverted, Field, 7, m-6, 2);		//Spieler 7
			set_gleiter_oben_links (inverted, Field, 8, m-6, n-3);		//Spieler 8
			
		} else if (number_of_players == 9) {
			unsigned int mm, nn;
			mm = m/2;
			nn = n/2;
			
			set_gleiter_unten_rechts (inverted, Field, 1, 5, 2);		//Spieler 1
			set_gleiter_oben_links (inverted, Field, 2, 5, n-3);		//Spieler 2
			set_gleiter_links_unten (inverted, Field, 3, 2, n-6);		//Spieler 3
			set_gleiter_links_unten (inverted, Field, 4, 2, 5);		//Spieler 4
			set_gleiter_rechts_oben (inverted, Field, 5, m-3, 5);		//Spieler 5
			set_gleiter_rechts_oben (inverted, Field, 6, m-3, n-6);		//Spieler 6
			set_gleiter_unten_rechts (inverted, Field, 7, m-6, 2);		//Spieler 7
			set_gleiter_oben_links (inverted, Field, 8, m-6, n-3);		//Spieler 8
			set_net_basic_two_four (inverted, Field, 9, mm-1, nn-1);	//Spieler 9
		}
		
	} else if (gamemode_played == Ulcer) {
		for (unsigned int i=1; i<=(m-2); i+=1) {
			if (i%3 != 0) {
				set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, 3, 1);
			}
		}
		for (unsigned int j=1; j<=(n-2); j+=1) {
			if (j%3 != 0) {
				set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, 3, j, 1);
			}
		}
		set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, 5, 5, 1);
	
	} else if (gamemode_played == Dynamic) {
		unsigned int m_2, n_2;
		m_2 = (m-1)/2;
		n_2 = (n-1)/2;
		
		if (number_of_players == 2) {
			
			set_gleiter_unten_rechts (inverted, Field, 1, m_2, 2);		//Spieler 1
			set_gleiter_unten_links (inverted, Field, 2, m_2, n-3);		//Spieler 2
			
		} else if (number_of_players == 3) {
			
			set_gleiter_unten_rechts (inverted, Field, 1, m_2, 2);		//Spieler 1
			set_mountain_oben (inverted, Field, 2, 2, n_2);		//Spieler 2
			set_gleiter_unten_links (inverted, Field, 3, m_2, n-3);		//Spieler 3
			
		} else if (number_of_players == 4) {
			
			set_gleiter_unten_rechts (inverted, Field, 1, m_2, 2);		//Spieler 1
			set_mountain_oben (inverted, Field, 2, 2, n_2);		//Spieler 2
			set_gleiter_unten_links (inverted, Field, 3, m_2, n-3);		//Spieler 3
			set_mountain_unten (inverted, Field, 4, m-3, n_2);		//Spieler 4
			
		} else if (number_of_players == 5) {
			
			set_gleiter_unten_rechts (inverted, Field, 1, m_2, 2);		//Spieler 1
			set_mountain_oben (inverted, Field, 2, 2, n_2);		//Spieler 2
			set_gleiter_unten_links (inverted, Field, 3, m_2, n-3);		//Spieler 3
			set_gleiter_rechts_oben (inverted, Field, 4, m-3, n_2+1);		//Spieler 4
			set_f_links_oben (inverted, Field, 5, m-3, n_2-1);		//Spieler 5
			
		} else if (number_of_players == 6) {
			
			set_gleiter_unten_rechts (inverted, Field, 1, m_2+1, 2);		//Spieler 1
			set_gleiter_links_unten (inverted, Field, 2, 2, n_2-1);		//Spieler 2
			set_gleiter_unten_links (inverted, Field, 3, m_2+1, n-3);		//Spieler 3
			set_f_oben_rechts (inverted, Field, 4, m_2-1, 2);		//Spieler 4
			set_f_rechts_unten (inverted, Field, 5, 2, n_2+1);		//Spieler 5
			set_f_oben_links (inverted, Field, 6, m_2-1, n-3);		//Spieler 6
			
		} else if (number_of_players == 7) {
			
			set_gleiter_unten_rechts (inverted, Field, 1, m_2+1, 2);		//Spieler 1
			set_mountain_oben (inverted, Field, 2, 2, n_2);		//Spieler 2
			set_gleiter_unten_links (inverted, Field, 3, m_2+1, n-3);		//Spieler 3
			set_gleiter_rechts_oben (inverted, Field, 4, m-3, n_2+1);		//Spieler 4
			set_f_oben_rechts (inverted, Field, 5, m_2-1, 2);		//Spieler 5
			set_f_oben_links (inverted, Field, 6, m_2-1, n-3);		//Spieler 6
			set_f_links_oben (inverted, Field, 7, m-3, n_2-1);		//Spieler 7
			
		} else if (number_of_players == 8) {
			
			set_gleiter_unten_rechts (inverted, Field, 1, m_2+1, 2);		//Spieler 1
			set_gleiter_links_unten (inverted, Field, 2, 2, n_2-1);		//Spieler 2
			set_gleiter_unten_links (inverted, Field, 3, m_2+1, n-3);		//Spieler 3
			set_gleiter_rechts_oben (inverted, Field, 4, m-3, n_2+1);		//Spieler 4
			set_f_oben_rechts (inverted, Field, 5, m_2-1, 2);		//Spieler 5
			set_f_rechts_unten (inverted, Field, 6, 2, n_2+1);		//Spieler 6
			set_f_oben_links (inverted, Field, 7, m_2-1, n-3);		//Spieler 7
			set_f_links_oben (inverted, Field, 8, m-3, n_2-1);		//Spieler 8
			
		} else if (number_of_players == 9) {
			
			set_gleiter_unten_rechts (inverted, Field, 1, m_2+2, 2);		//Spieler 1
			set_gleiter_links_unten (inverted, Field, 2, 2, n_2-2);		//Spieler 2
			set_gleiter_unten_links (inverted, Field, 3, m_2+2, n-3);		//Spieler 3
			set_gleiter_oben_rechts (inverted, Field, 4, m_2-2, 2);		//Spieler 4
			set_gleiter_rechts_unten (inverted, Field, 5, 2, n_2+2);		//Spieler 5
			set_gleiter_oben_links (inverted, Field, 6, m_2-2, n-3);		//Spieler 6
			set_mountain_links (inverted, Field, 7, m_2, 2);		//Spieler 7
			set_mountain_oben (inverted, Field, 8, 2, n_2);		//Spieler 8
			set_mountain_rechts (inverted, Field, 7, m_2, n-3);		//Spieler 9
			
		}
		
		Field[0][m_2][n_2] = 77;
		
	} else if (gamemode_played == Survive) {
		if (number_of_players >= 1) {
			set_gleiter_unten_rechts (inverted, Field, 1, 2, 2);		//Spieler 1
		}
		if (number_of_players >= 2) {
			set_gleiter_links_unten (inverted, Field, 2, 2, n-3);		//Spieler 2
		}
		if (number_of_players >= 3) {
			set_gleiter_oben_links (inverted, Field, 3, m-3, n-3);		//Spieler 3
		}
		if (number_of_players >= 4) {
			set_gleiter_rechts_oben (inverted, Field, 4, m-3, 2);		//Spieler 4
		}
		if (number_of_players == 5) {
			unsigned int n_2;
			unsigned int m_2;
			n_2 = (n-1)/2;
			m_2 = (m-1)/2;
			
			set_star (inverted, Field, 5, m_2, n_2);		//Spieler 5
			
		} else if (number_of_players > 5) {
			unsigned int m_2;
			m_2 = (m-1)/2;
			
			set_mountain_rechts (inverted, Field, 5, m_2, n-3);		//Spieler 5
			
		}
		if (number_of_players >= 6) {
			unsigned int m_2;
			m_2 = (m-1)/2;
			
			set_mountain_links (inverted, Field, 6, m_2, 2);		//Spieler 6
			
		}
		if (number_of_players == 7) {
			unsigned int n_2;
			unsigned int m_2;
			n_2 = (n-1)/2;
			m_2 = (m-1)/2;
			
			set_star (inverted, Field, 7, m_2, n_2);		//Spieler 7
			
		} else if (number_of_players > 7) {
			unsigned int n_2;
			n_2 = (n-1)/2;
			
			set_mountain_oben (inverted, Field, 7, 2, n_2);		//Spieler 7
			
		}
		if (number_of_players >= 8) {
			unsigned int n_2;
			n_2 = (n-1)/2;
			
			set_mountain_unten (inverted, Field, 8, m-3, n_2);		//Spieler 8
			
		}
		if (number_of_players >= 9) {
			unsigned int n_2;
			unsigned int m_2;
			n_2 = (n-1)/2;
			m_2 = (m-1)/2;
			
			set_star (inverted, Field, 9, m_2, n_2);		//Spieler 9
			
		}
	} else if (gamemode_played == Sand) {
		if (number_of_players >= 1) {
			set_gleiter_rechts_oben (inverted, Field, 1, m-3, 2);		//Spieler 1
		}
		if (number_of_players >= 2) {
			set_gleiter_links_oben (inverted, Field, 2, m-3, 6);		//Spieler 2
		}
		if (number_of_players >= 3) {
			set_gleiter_rechts_oben (inverted, Field, 3, m-3, 10);		//Spieler 3
		}
		if (number_of_players >= 4) {
			set_gleiter_links_oben (inverted, Field, 4, m-3, 14);		//Spieler 4
		}
		if (number_of_players >= 5) {
			set_gleiter_rechts_oben (inverted, Field, 5, m-3, 18);		//Spieler 5
		}
		if (number_of_players >= 6) {
			set_gleiter_links_oben (inverted, Field, 6, m-3, 22);		//Spieler 6
		}
		if (number_of_players >= 7) {
			set_gleiter_rechts_oben (inverted, Field, 7, m-3, 26);		//Spieler 7
		}
		if (number_of_players >= 8) {
			set_gleiter_links_oben (inverted, Field, 8, m-3, 30);		//Spieler 8
		}
		if (number_of_players >= 9) {
			set_gleiter_rechts_oben (inverted, Field, 9, m-3, 34);		//Spieler 9
		}
	}
	
}

void new_life (Spielfeld Field, unsigned int m, unsigned int n, unsigned int w, unsigned int gamemode_played, unsigned int* information_code, unsigned int geben, Spielfeld Sf_nl_, Spielfeld Sf_od_, Spielfeld Sf_opague, Spielfeld Sf_allocation, unsigned int allocation, unsigned int number_of_players){
	Spielfeld Sf_temp;
	unsigned int a, inhi;
	
	// printf("	w: %u\n", w);	//test
	
	Sf_temp = Spielfeld_Create (m, n, 0);		//inhibitor in information_code[1], ability ist in information_code[0]
	a = 0;
	inhi = 0;
	
	// printf("	w: %u\n", w);	//test
	
	if (gamemode_played != Race) {
		for (unsigned int i=1; i<m-1; i+=1){
			for (unsigned int j=1; j<n-1; j+=1){
				if ((Field[0][i][j] == 0)||(Field[0][i][j] == Traps)) {	//Traps only used in Survive
					for (unsigned int h=i-1; h<=i+1; h+=1){
						for (unsigned int k=j-1; k<=j+1; k+=1){
							if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
								if (((gamemode_played != Hunt)||(geben != 1))&&(gamemode_played != Arena)) {
									if (Field[0][h][k] == geben){
										a+=1;
									}
								} else if ((gamemode_played == Hunt)&&(geben == 1)) {
									if ((Field[0][h][k] == 1)||(Field[0][h][k] == 11)){
										a+=1;
									}
								} else if (gamemode_played == Arena) {
									if (Field[0][h][k] == geben){
										a+=1;
									}
									if ((information_code[1] != 0)&&(information_code[1] != 100)&&(Field[0][h][k] == information_code[1])&&(information_code[0] != 6)&&(information_code[0] != 5)) {
										inhi += 1;
									}
								}
							}
						}
					}				//w=3, w=2, w=4
					if (gamemode_played != Arena) {
						if (w == 4){
							if ((a == w) || (a == w+1)){
								set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Sf_temp, 0, i, j, geben);
							}
						} else {
							if (a == w){
								set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Sf_temp, 0, i, j, geben);
							}
						}
						a = 0;
					} else if (gamemode_played == Arena) {
						if (inhi != 3) {
							if (information_code[0] == 1) {
								if (w == 2){
									if ((a == w) || (a == w+1)){
										set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Sf_temp, 0, i, j, geben);
									}
								} else {
									if (a == w){
										if (w == 1) {
											set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Sf_temp, 0, i, j, geben);
										} else if (w == 0) {
											for (unsigned int h=i-1; h<=i+1; h+=1){
												for (unsigned int k=j-1; k<=j+1; k+=1){
													if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
														if (Field[0][h][k] != 0) {
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
												set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Sf_temp, 0, i, j, geben);
											}
										}
									}
								}
							} else if (information_code[0] == 2) {
								if (w == 3){
									if ((a == w) || (a == w+1)){
										set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Sf_temp, 0, i, j, geben);
									}
								} else {
									if (a == w){
										set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Sf_temp, 0, i, j, geben);
									}
								}
							} else if (information_code[0] == 3) {
								if (w == 5){
									if ((a == w) || (a == w+1)){
										set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Sf_temp, 0, i, j, geben);
									}
								} else {
									if (a == w){
										set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Sf_temp, 0, i, j, geben);
									}
								}
							} else if (information_code[0] == 4) {
								if (w == 4){
									if ((a == w) || (a == w+1)){
										set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Sf_temp, 0, i, j, geben);
									}
								} else {
									if (a == w){
										set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Sf_temp, 0, i, j, geben);
									}  else if ((a == (w-1))&&((j == (n-2))||(j == 1)||(i == (m-2))||(i == 1))) {
										set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Sf_temp, 0, i, j, geben);
									}
								}
							} else {
								if (w == 4){
									if ((a == w) || (a == w+1)){
										set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Sf_temp, 0, i, j, geben);
									}
								} else {
									if (a == w){
										set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Sf_temp, 0, i, j, geben);
									}
								}
							}
						}
						a = 0;
						inhi = 0;
					}
					
				}
				if ((gamemode_played == Ulcer)&&((Field[0][i][j] == 2)&&(geben == 1))) {
					for (unsigned int h=i-1; h<=i+1; h+=1){
						for (unsigned int k=j-1; k<=j+1; k+=1){
							if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
								if (Field[0][h][k] == geben){
									a+=1;
								}
							}
						}
					}
					if (w == 4){
						if ((a == w) || (a == w+1)){
							set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Sf_temp, 0, i, j, geben);
						}
					} else {
						if (a == w){
							set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Sf_temp, 0, i, j, geben);
						}
					}
					a = 0;
				}
			}
		}
		if ((gamemode_played == Survive)&&(information_code[1] >= 1)) {
			for (unsigned int i=1; i<m-1; i+=1){
				for (unsigned int j=1; j<n-1; j+=1){
					
					if ((Field[0][i][j] == Traps)&&(Sf_temp[0][i][j] == geben)) {
						
						if (Field[0][i][j] == geben) {	//sinnlos?
							set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Sf_od_, geben, i, j, 101*geben);
						} else {
							set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j, 0);
						}
						set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Sf_temp, 0, i, j, 0);
						
						if (Field[0][i-1][j] == geben) {
							set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Sf_od_, geben, i-1, j, 101*geben);
						} else {
							set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i-1, j, 0);
						}
						set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Sf_temp, 0, i-1, j, 0);
						
						if (Field[0][i+1][j] == geben) {
							set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Sf_od_, geben, i+1, j, 101*geben);
						} else {
							set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i+1, j, 0);
						}
						set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Sf_temp, 0, i+1, j, 0);
						
						if (Field[0][i][j-1] == geben) {
							set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Sf_od_, geben, i, j-1, 101*geben);
						} else {
							set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j-1, 0);
						}
						set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Sf_temp, 0, i, j-1, 0);
						
						if (Field[0][i][j+1] == geben) {
							set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Sf_od_, geben, i, j+1, 101*geben);
						} else {
							set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j+1, 0);
						}
						set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Sf_temp, 0, i, j+1, 0);
						
					}
				}
			}
		}
		
	} else if ((gamemode_played == Race)&&(geben == 1)) {		//if, done
		for (unsigned int i=1; i<=(m-1)/2; i+=1){			//Spieler 1
			for (unsigned int j=1; j<n-1; j+=1){
				if (Field[0][i][j] == 0) {
					for (unsigned int h=i-1; h<=i+1; h+=1){
						for (unsigned int k=j-1; k<=j+1; k+=1){
							if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
								if (Field[0][h][k] == 1){
									a+=1;
								}
							}
						}
					}				//w=3, w=2, w=4
					if(w == 4){
						if ((a == w) || (a == w+1) ){
							set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Sf_temp, 0, i, j, geben);
						}
					} else {
						if (a == w){
							set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Sf_temp, 0, i, j, geben);
						}
					}
					a = 0;
					
				}
			}
		}
	} else if ((gamemode_played == Race)&&(geben == 2)) {
		for (unsigned int i=(m-1)/2; i<m-1; i+=1){			//Spieler 2
			for (unsigned int j=1; j<n-1; j+=1){
				if (Field[0][i][j] == 0) {
					for (unsigned int h=i-1; h<=i+1; h+=1){
						for (unsigned int k=j-1; k<=j+1; k+=1){
							if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
								if (Field[0][h][k] == 2){
									a+=1;
								}
							}
						}
					}			//w=3, w=2, w=4
					if(w == 4){
						if ((a == w) || (a == w+1) ){
							set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Sf_temp, 0, i, j, geben);
						}
					} else {
						if (a == w){
							set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Sf_temp, 0, i, j, geben);
						}
					}
					a = 0;
				}
			}
		}
	}
	
	for (unsigned int i=1; i<m-1; i+=1){
		for (unsigned int j=1; j<n-1; j+=1){
			if (Sf_temp[0][i][j] == geben) {
				set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Sf_nl_, geben, i, j, geben);
			}
		}
	}
	
	Spielfeld_Destroy (Sf_temp, m, 0);
	
	// printf("end of new_life");	//test
	
}

void old_dying (Spielfeld Field, unsigned int m, unsigned int n, unsigned int d, unsigned int e, unsigned int gamemode_played, unsigned int* information_code, unsigned int geben, Spielfeld Sf_od_, unsigned int w, Spielfeld Sf_allocation, unsigned int allocation, Spielfeld Sf_opague, unsigned int number_of_players){
	Spielfeld Sf_temp;
	unsigned int a, e_down, d_up;
	
	Sf_temp = Spielfeld_Create (m, n, 0);
	a = 0;
	e_down = 0;
	d_up = 0;
	
	for (unsigned int i=1; i<m-1; i+=1){
		for (unsigned int j=1; j<n-1; j+=1){
			if (Field[0][i][j] == geben) {
				if (gamemode_played == Arena) {
					if ((information_code[2] != 0)&&(information_code[2] != 100)&&(information_code[0] != 7)&&(information_code[0] != 6)) {
						if ((Field[0][i+1][j] == information_code[2])||(Field[0][i][j-1] == information_code[2])||(Field[0][i][j+1] == information_code[2])||(Field[0][i-1][j] == information_code[2])) {
							d_up = 1;
							d += 1;
						}
					}
					if ((information_code[3] != 0)&&(information_code[3] != 100)&&(information_code[0] != 8)&&(information_code[0] != 6)) {	//wenn du kein Shield hast oder die Angriffseigenschaft selbst besitzt.
						if ((Field[0][i+1][j] == information_code[3])||(Field[0][i][j-1] == information_code[3])||(Field[0][i][j+1] == information_code[3])||(Field[0][i-1][j] == information_code[3])) {
							e_down = 1;
							e -= 1;
						}
					}
				}
				for (unsigned int h=i-1; h<=i+1; h+=1){
					for (unsigned int k=j-1; k<=j+1; k+=1){
						if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
							if (((gamemode_played != Hunt)||(geben != 1))&&(gamemode_played != Arena)) {
								if (Field[0][h][k] == geben){
									a+=1;
								}
							} else if ((gamemode_played == Hunt)&&(geben == 1)) {
								if ((Field[0][h][k] == 1)||(Field[0][h][k] == 11)){
									a+=1;
								}
							} else if (gamemode_played == Arena) {
								if (Field[0][h][k] == geben){
									a+=1;
								}
							}
						}
					}
				}
				if (gamemode_played != Arena) {
					if ((a < d+1) || (a > e+1)){		//d=2, d=1, e=3, e=4, +1 wegen des Steines selbst, da er mitgezählt wird
						set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Sf_temp, 0, i, j, 101*geben);		//Code für das Eleminieren
					}
					
					if (allocation != 0) {
						if (w == 4) {
							if ((a == w+1)||(a == w+2)) {
								if (Sf_allocation[0][i][j] < allocation) {
									Sf_allocation[0][i][j] += 1;
								}
							}
						} else {
							if (a == w+1) {
								if (Sf_allocation[0][i][j] < allocation) {
									Sf_allocation[0][i][j] += 1;
								}
							}
						}
						
						if (a < d+1){
							set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Sf_allocation, 1, i, j, (d+1-a));
						} else if (a > e+1) {
							set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Sf_allocation, 1, i, j, (a-e-1));
						}
					}
					
					a = 0;
				} else if (gamemode_played == Arena) {
					if ((d == 11)||(d == 10)) {
						d = 0;
						d_up += 10;
					}
					
					if ((a < d+1) || (a > e+1)){
						set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Sf_temp, 0, i, j, 101*geben);
					}
					
					if ((d_up == 1)||(d_up == 11)) {
						d -= 1;
					}
					if ((d_up == 10)||(d_up == 11)) {
						d = 10;
					}
					if (e_down == 1) {
						e += 1;
					}
					d_up = 0;
					e_down = 0;
					
					if (allocation != 0) {
						if (w == 4) {
							if ((a == w+1)||(a == w+2)) {
								if (Sf_allocation[0][i][j] < allocation) {
									Sf_allocation[0][i][j] += 1;
								}
							}
						} else {
							if (a == w+1) {
								if (Sf_allocation[0][i][j] < allocation) {
									Sf_allocation[0][i][j] += 1;
								}
							}
						}
						
						if (a < d+1){
							set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Sf_allocation, 1, i, j, (d+1-a));
						} else if (a > e+1) {
							set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Sf_allocation, 1, i, j, (a-e-1));
						}
					}
					
					a = 0;
				}
			}
		}
	}
	
	for (unsigned int i=1; i<m-1; i+=1){
		for (unsigned int j=1; j<n-1; j+=1){
			if (Sf_temp[0][i][j] == 101*geben) {
				set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Sf_od_, geben, i, j, 101*geben);
			}
		}
	}
	
	Spielfeld_Destroy (Sf_temp, m, 0);
	
	// printf("	101*geben=%u, geben=%u \n", 101*geben, geben);	//test
	
}

void change (Spielfeld Sf_permutations, Spielfeld Field, Spielfeld Sf_nl_, Spielfeld Sf_od_, unsigned int m, unsigned int n, unsigned int gamemode_played, unsigned int number_of_players, unsigned int* ges, unsigned int geben, unsigned int undead_duration, Spielfeld Sf_allocation, unsigned int allocation, Spielfeld Sf_opague, unsigned int* information_code, unsigned int* Colored, unsigned int inverted){	
	
	for (unsigned int i=1; i<m-1; i+=1){
		for (unsigned int j=1; j<n-1; j+=1){
			if (Field[0][i][j] == geben){
				if (Sf_od_[geben][i][j] == 101*geben){
					
					if (allocation != 0) {	//So Allocation is activated
						for (unsigned int p=1; p<=Sf_allocation[1][i][j]; p++) {
							Sf_allocation[0][i][j] -= 1;
							if (Sf_allocation[0][i][j] == 0) {
								break;
							}
						}
						if (Sf_allocation[0][i][j] == 0) {
							set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j, 0);
							
							if ((gamemode_played == Ulcer)&&(ges[Nachfolger(geben, number_of_players)] != 1010*geben)) {
								set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j, Nachfolger(geben, number_of_players));
							}
							if (undead_duration != 0) {
								set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j, undead_duration*10000);
							}
						}
						
					} else {
						set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j, 0);
						if ((gamemode_played == Ulcer)&&(ges[Nachfolger(geben, number_of_players)] != 1010*geben)) {
							set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j, Nachfolger(geben, number_of_players));
						}
						if (undead_duration != 0) {
							set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j, undead_duration*10000);
						}
					}
					
				}
			} else if (Field[0][i][j] == 0){
				if (Sf_nl_[geben][i][j] == geben){
					set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j, geben);
				}
			} else if ((gamemode_played == Ulcer)&&(geben == 1)&&(Field[0][i][j] == 2)){	//player one takes back squares from player 2
				if (Sf_nl_[geben][i][j] == 1){
					set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j, 1);
				}
			} else if ((undead_duration != 0)&&(Field[0][i][j] >= 10000)) {	//because nothing is higher than 10000
				Field[0][i][j]-=10000;
				if ((Field[0][i][j] == 0)&&(gamemode_played == Ulcer)) {
					set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j, Nachfolger(geben, number_of_players));
				}
			}
		}
	}
	
	if (inverted != 0) {
		inverted_organism (Sf_permutations, Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, m, n, information_code, Colored);
	}
	
	// printf("change:	101*geben=%u, geben=%u \n", 101*geben, geben); //test
	
	for (unsigned int i=1; i<m-1; i+=1){
		for (unsigned int j=1; j<n-1; j+=1){
			set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Sf_od_, geben, i, j, 0);
			set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Sf_nl_, geben, i, j, 0);
			set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Sf_allocation, 1, i, j, 0);
		}
	}
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

void show_field (Spielfeld Sf_permutations, Spielfeld Sf_opague, Spielfeld Spiel, unsigned int m, unsigned int n, unsigned int gamemode_played, unsigned int* information_code, unsigned int geben, unsigned int* Colored, unsigned int auswerter, Spielfeld Sf_allocation, unsigned int allocation){
	unsigned int allocation_choice;
	allocation_choice = 0;
	
	if (Spiel == Sf_opague) {
		allocation_choice = 2;
	}
	
	printf("\n");
	
	printf("	    ");
	for (unsigned int p=1; p<=n-2; p+=1){		//Nummerierung
		if (p<10){
			printf("%u  ", p);
		} else {
			printf("%u ", p);
		}
	}
	printf("   ");	//üc bosluk
	
	if (allocation != 0) {
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
	
		printf("	   +");
		for (unsigned int t=1; t<=n-2; t+=1){		//Zwischenzeilen
			printf("--+");
		}
		printf("   ");	//üc bosluk
		
		if (allocation != 0) {
			printf("	");	//two tabs
			printf("	   +");
			for (unsigned int t=1; t<=n-2; t+=1){
				printf("--+");
			}
			printf("   ");	//üc bosluk
		}
		
		if (Sf_permutations[0][1][1] != 0) {
			printf("	");	//two tabs
			printf("	   +");
			for (unsigned int t=1; t<=n-2; t+=1){
				printf("--+");
			}
		}
		
		printf("\n");
		
		for (unsigned int v=1; v<=2; v+=1){		//Doppel-Ausführung, ab 10 wird korrigiert, bis 99 gültig
		
			if (i<10){
				printf("	 %u |", i);
			} else {
				printf("	%u |", i);
			}
			for (unsigned int j=1; j<n-1; j+=1){	//Haupzeilen
				if (Spiel[auswerter][i][j] == 0){
					printf("  ");
				} else if (Spiel[auswerter][i][j] == 15){
					if (Colored[0] == 1) {
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+Colored[geben]);
					}
					printf("NN");
				} else if (Spiel[auswerter][i][j] == 16){
					if (Colored[0] == 1) {
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+Colored[geben]);
					}
					printf("D ");
				} else if (Spiel[auswerter][i][j] >= 10000){
					if (Colored[0] == 1) {
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+6);
					}
					printf("??");
				} 
				
				if ((gamemode_played != Hunt)&&(gamemode_played != Arena)&&(gamemode_played != Ulcer)&&(gamemode_played != Dynamic)&&(gamemode_played != Survive)&&(gamemode_played != Sand)) {	//mehr-gamemode_played
					if (Spiel[auswerter][i][j] == 1){
						if (Colored[0] == 1) {
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+Colored[Spiel[auswerter][i][j]]);
						}
						printf("**");
					} else if (Spiel[auswerter][i][j] == 2){
						if (Colored[0] == 1) {
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+Colored[Spiel[auswerter][i][j]]);
						}
						printf("OO");
					} else if (Spiel[auswerter][i][j] == 7){
						printf("##");
					}
				} else if (gamemode_played == Hunt) {
					if (Spiel[auswerter][i][j] == 1) {
						if ((geben == 1)||((information_code[3] == 1)&&((Spiel[auswerter][i+1][j] == geben)||(Spiel[auswerter][i-1][j] == geben)||(Spiel[auswerter][i][j+1] == geben)||(Spiel[auswerter][i][j-1] == geben)))||((information_code[1] == 1)&&(information_code[2] == 1))){
							if (Colored[0] == 1) {
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+Colored[Spiel[auswerter][i][j]]);
							}
							printf("##");
						} else {
							printf("  ");
						}
					} else if (Spiel[auswerter][i][j] == 2){
						if (Colored[0] == 1) {
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+Colored[Spiel[auswerter][i][j]]);
						}
						printf("AA");
					} else if (Spiel[auswerter][i][j] == 3){
						if (Colored[0] == 1) {
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+Colored[Spiel[auswerter][i][j]]);
						}
						printf("BB");
					} else if (Spiel[auswerter][i][j] == 4){
						if (Colored[0] == 1) {
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+Colored[Spiel[auswerter][i][j]]);
						}
						printf("CC");
					} else if (Spiel[auswerter][i][j] == 5){
						if (Colored[0] == 1) {
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+Colored[Spiel[auswerter][i][j]]);
						}
						printf("DD");
					} else if (Spiel[auswerter][i][j] == 6){
						if (Colored[0] == 1) {
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+Colored[Spiel[auswerter][i][j]]);
						}
						printf("EE");
					} else if (Spiel[auswerter][i][j] == 7){
						if (Colored[0] == 1) {
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+Colored[Spiel[auswerter][i][j]]);
						}
						printf("GG");
					} else if (Spiel[auswerter][i][j] == 8){
						if (Colored[0] == 1) {
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+Colored[Spiel[auswerter][i][j]]);
						}
						printf("HH");
					} else if (Spiel[auswerter][i][j] == 9){
						if (Colored[0] == 1) {
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+Colored[Spiel[auswerter][i][j]]);
						}
						printf("II");
					} else if (Spiel[auswerter][i][j] == 11){
						if ((geben == 1)||(((information_code[2] == 2)||(information_code[2] == 1))&&(information_code[1] == 1))){
							if (Colored[0] == 1) {
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+Colored[1]);
							}
							printf("~~");
						} else {
							printf("  ");
						}
					} else if (Spiel[auswerter][i][j] == 17){
						printf("::");
					}
				} else if (gamemode_played == Arena) {
					if (Spiel[auswerter][i][j] == geben) {
						if (Colored[0] == 1) {
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+Colored[Spiel[auswerter][i][j]]);
						}
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
						if (Colored[0] == 1) {
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+Colored[Spiel[auswerter][i][j]]);
						}
						printf("II");
					} else if ((information_code[2] != 0)&&(information_code[2] != 100)&&(Spiel[auswerter][i][j] == information_code[2])) {
						if (Colored[0] == 1) {
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+Colored[Spiel[auswerter][i][j]]);
						}
						printf("PP");
					} else if ((information_code[3] != 0)&&(information_code[3] != 100)&&(Spiel[auswerter][i][j] == information_code[3])) {
						if (Colored[0] == 1) {
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+Colored[Spiel[auswerter][i][j]]);
						}
						printf("HH");
					} else if ((Spiel[auswerter][1][0] != 0)&&(Spiel[auswerter][1][0] != 1000)&&(Spiel[auswerter][i][j] == Spiel[auswerter][1][0]/10)) {
						if (Colored[0] == 1) {
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+Colored[Spiel[auswerter][i][j]]);
						}
						printf("UU");
					} else if ((Spiel[auswerter][0][0] != 0)&&(Spiel[auswerter][0][0] != 1000)&&(Spiel[auswerter][i][j] == Spiel[auswerter][0][0]/10)) {
						if (Colored[0] == 1) {
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+Colored[Spiel[auswerter][i][j]]);
						}
						printf("LL");
					} else if ((Spiel[auswerter][0][1] != 0)&&(Spiel[auswerter][0][1] != 1000)&&(Spiel[auswerter][i][j] == Spiel[auswerter][0][1]/10)) {
						if (Colored[0] == 1) {
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+Colored[Spiel[auswerter][i][j]]);
						}
						printf("AA");
					} else if ((Spiel[auswerter][0][n-1] != 0)&&(Spiel[auswerter][0][n-1] != 1000)&&(Spiel[auswerter][i][j] == Spiel[auswerter][0][n-1]/10)) {
						if (Colored[0] == 1) {
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+Colored[Spiel[auswerter][i][j]]);
						}
						printf("CC");
					} else if ((Spiel[auswerter][m-1][n-1] != 0)&&(Spiel[auswerter][m-1][n-1] != 1000)&&(Spiel[auswerter][i][j] == Spiel[auswerter][m-1][n-1]/10)) {
						if (Colored[0] == 1) {
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+Colored[Spiel[auswerter][i][j]]);
						}
						printf("SS");
					} else if ((Spiel[auswerter][m-1][0] != 0)&&(Spiel[auswerter][m-1][0] != 1000)&&(Spiel[auswerter][i][j] == Spiel[auswerter][m-1][0]/10)) {
						if (Colored[0] == 1) {
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+Colored[Spiel[auswerter][i][j]]);
						}
						printf("EE");
					} else if (Spiel[auswerter][i][j] == 17){	//hint
						printf("::");
					}
				} else if ((gamemode_played == Ulcer)||(gamemode_played == Sand)) {
					for (unsigned int p=1; p<=information_code[0]; p+=1) {	//information_code[0] == number_of_players
						if (Spiel[auswerter][i][j] == p) {
							if (Colored[0] == 1) {
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+Colored[Spiel[auswerter][i][j]]);
							}
							printf("%u%u", p, p);
							break;
						}
					}
					if (Spiel[auswerter][i][j] == 17){	//hint
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+7);
						printf("::");
					}
				} else if (gamemode_played == Dynamic) {
					if (Spiel[auswerter][i][j] == 77) {
						if (Colored[0] == 1) {
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+6);	//6 --> brown, but it is white
						}
						printf("##");
					} else if (Spiel[auswerter][i][j] == 17){	//hint
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+7);
						printf("::");
					}
					
					for (unsigned int p=1; p<=information_code[0]; p+=1) {	//information_code[0] == number_of_players
						if (Spiel[auswerter][i][j] == p) {
							if (Colored[0] == 1) {
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+Colored[Spiel[auswerter][i][j]]);
							}
							printf("%u%u", p, p);
							break;
						}
					}
					
				} else if (gamemode_played == Survive) {
					if (Spiel[auswerter][i][j] == Traps) {	//Trap
						if (Colored[0] == 1) {
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+6);	//6 --> brown, but it is white
						}
						printf("TT");
					} else if (Spiel[auswerter][i][j] == Bomb_4) {	//Bomb
						if (Colored[0] == 1) {
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+6);	//6 --> brown, but it is white
						}
						printf("B4");
					} else if (Spiel[auswerter][i][j] == Bomb_3) {	//Bomb
						if (Colored[0] == 1) {
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+6);	//6 --> brown, but it is white
						}
						printf("B3");
					} else if (Spiel[auswerter][i][j] == Bomb_2) {	//Bomb
						if (Colored[0] == 1) {
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+6);	//6 --> brown, but it is white
						}
						printf("B2");
					} else if (Spiel[auswerter][i][j] == Bomb_1) {	//Bomb
						if (Colored[0] == 1) {
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+6);	//6 --> brown, but it is white
						}
						printf("B1");
					} else if (Spiel[auswerter][i][j] == Waves) {	//Wave
						if (Colored[0] == 1) {
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+6);	//6 --> brown, but it is white
						}
						printf("WW");
					}
					
					for (unsigned int p=1; p<=information_code[0]; p+=1) {	//information_code[0] == number_of_players
						if (Spiel[auswerter][i][j] == p) {
							if (Colored[0] == 1) {
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+Colored[Spiel[auswerter][i][j]]);
							}
							printf("%u%u", p, p);
							break;
						}
					}
					
				}
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+7);
				printf("|");
			}
		
			if (i<10){
				printf(" %u ", i);
			} else {
				printf(" %u", i);
			}
			
			if ((allocation == 0)&&(Sf_permutations[0][1][1] == 0)) {	//only if no field is following
				printf("\n");
			}
			if (allocation != 0) {	//a second field
				printf("	");	//one tab(s)
				
				if (i<10){
					printf("	 %u |", i);
				} else {
					printf("	%u |", i);
				}
				
				for (unsigned int j=1; j<n-1; j+=1){
					if ((Sf_allocation[allocation_choice][i][j] < 10)&&(Sf_allocation[allocation_choice][i][j] != 0)) {
						if (Colored[0] == 1) {
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+Colored[Spiel[auswerter][i][j]]);
						}
						printf("0%u", Sf_allocation[allocation_choice][i][j]);
					} else if ((Sf_allocation[allocation_choice][i][j] >= 10)&&(Sf_allocation[allocation_choice][i][j] != 0)) {	//last one can be left
						if (Colored[0] == 1) {
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+Colored[Spiel[auswerter][i][j]]);
						}
						printf("%u", Sf_allocation[allocation_choice][i][j]);
					} else {	//no allocation possible for objects
						printf("  ");
					}
					
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+7);
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
					printf("	 %u |", i);
				} else {
					printf("	%u |", i);
				}
				
				for (unsigned int j=1; j<n-1; j+=1){
					if ((Sf_permutations[0][i][j] < 10)&&(Sf_permutations[0][i][j] != 0)) {
						
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+Sf_permutations[0][i][j]%15 +1);
						printf("0%u", Sf_permutations[0][i][j]);
						
					} else if ((Sf_permutations[0][i][j] >= 10)&&(Sf_permutations[0][i][j] != 0)) {	//last one can be left
						
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+Sf_permutations[0][i][j]%15 +1);
						printf("%u", Sf_permutations[0][i][j]);
						
					} else {
						printf("  ");
					}
					
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+7);
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
	
	printf("	   +");
	for (unsigned int t=1; t<=n-2; t+=1){		//Endzeile
		printf("--+");
	}
	printf("   ");	//üc bosluk
	
	if (allocation != 0) {
		printf("	");	//one tab(s)
		printf("	   +");
		for (unsigned int t=1; t<=n-2; t+=1){
			printf("--+");
		}
		printf("   ");	//üc bosluk
	}
	
	if (Sf_permutations[0][1][1] != 0) {
		printf("	");	//one tab(s)
		printf("	   +");
		for (unsigned int t=1; t<=n-2; t+=1){
			printf("--+");
		}
	}
	
	printf("\n");
	printf("	    ");
	for (unsigned int q=1; q<=n-2; q+=1){		//Nummerierung
		if (q<10){
			printf("%u  ", q);
		} else {
			printf("%u ", q);
		}
	}
	printf("   ");	//üc bosluk
	
	if (allocation != 0) {
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
	
		/*test
		printf("\n");
		printf("	information_code: [0]=%u,	[1]=%u,	[2]=%u,	[3]=%u,	\n", information_code[0], information_code[1], information_code[2], information_code[3]);
		printf("\n");
		*/
}

void Plus (Spielfeld Sf_permutations, unsigned int m, unsigned int n, unsigned int geben, Spielfeld Field, unsigned int limit_at_all, unsigned int gamemode_played, unsigned int* information_code, unsigned int number_of_players, unsigned int* Colored, unsigned int opague, Spielfeld Sf_opague, Spielfeld Sf_allocation, unsigned int allocation){
	unsigned int a, b;
	unsigned int Zeile, Spalte;
	
	a = 0;
	b = 0;
	Zeile = 0;
	Spalte = 0;
	
	if ((gamemode_played == Hunt)&&(geben == 1)) {
		limit_at_all = (limit_at_all+ 2 *(number_of_players - 3));
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
	if ((b >= limit_at_all)&&(gamemode_played != Contact)&&(gamemode_played != Ulcer)&&(gamemode_played != Survive)){
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
				
				if (opague >= 1) {
					show_field (Sf_permutations, Sf_opague, Sf_opague, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
				} else {
					show_field (Sf_permutations, Sf_opague, Field, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
				}
				Plus (Sf_permutations, m, n, geben, Field, limit_at_all, gamemode_played, information_code, number_of_players, Colored, opague, Sf_opague, Sf_allocation, allocation);
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
					} else {
						if (geben == 1) {
							set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, Zeile, Spalte, 1);
						} else {
							set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, Zeile, Spalte, geben);
						}
					}
				} else if ((gamemode_played != Ulcer)&&(gamemode_played != Survive)) {
					if ((a == 0) || (Field[0][Zeile][Spalte] != 0)){
						printf ("	Not possible\n");
					} else {
						set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, Zeile, Spalte, geben);
					}
				} else {
					if (a == 0){
						printf ("	Not possible\n");
					} else {
						set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, Zeile, Spalte, geben);
					}
				}
			}
		}
	}
}

void Minus (Spielfeld Sf_permutations, unsigned int m, unsigned int n, unsigned int geben, Spielfeld Field, unsigned int gamemode_played, unsigned int* information_code, unsigned int* Colored, unsigned int opague, Spielfeld Sf_opague, Spielfeld Sf_allocation, unsigned int allocation, unsigned int number_of_players){
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
			if (opague >= 1) {
				show_field (Sf_permutations, Sf_opague, Sf_opague, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
			} else {
				show_field (Sf_permutations, Sf_opague, Field, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
			}
			Minus (Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Colored, opague, Sf_opague, Sf_allocation, allocation, number_of_players);
		} else if (Field[0][Zeile][Spalte] != geben){
			printf("	you made a mistake, try again: \n");
			Minus (Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Colored, opague, Sf_opague, Sf_allocation, allocation, number_of_players);
		} else {
			set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, Zeile, Spalte, 0);
		}
	}
}

void Move (Spielfeld Sf_permutations, unsigned int m, unsigned int n, unsigned int geben, Spielfeld Field, unsigned int gamemode_played, unsigned int* information_code, unsigned int* Colored, unsigned int opague, Spielfeld Sf_opague, Spielfeld Sf_allocation, unsigned int allocation, unsigned int number_of_players){
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
						set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, h-1, k, 1);
						set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, h, k, 0);
						
						break;
					} else if ((Field[0][h][k-1]==0)&&((k-1)>=1)){
						b = 1;
						set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, h, k-1, 1);
						set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, h, k, 0);
						
						break;
					} else if ((Field[0][h][k+1]==0)&&((k+1)<=(n-2))){
						b = 1;
						set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, h, k+1, 1);
						set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, h, k, 0);
						
						break;
					} else if ((Field[0][h+1][k]==0)&&((h+1)<=(m-2))){
						b = 1;
						set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, h+1, k, 1);
						set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, h, k, 0);
						
						break;
					}
				} else if (Field[0][h][k] == geben){
					if ((Field[0][h-1][k]==0)&&((h-1)>=1)){
						b = 1;
						set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, h-1, k, geben);
						set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, h, k, 0);
						
						break;
					} else if ((Field[0][h][k-1]==0)&&((k-1)>=1)){
						b = 1;
						set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, h, k-1, geben);
						set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, h, k, 0);
						
						break;
					} else if ((Field[0][h][k+1]==0)&&((k+1)<=(n-2))){
						b = 1;
						set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, h, k+1, geben);
						set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, h, k, 0);
						
						break;
					} else if ((Field[0][h+1][k]==0)&&((h+1)<=(m-2))){
						b = 1;
						set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, h+1, k, geben);
						set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, h, k, 0);
						
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
				if (opague >= 1) {
					show_field (Sf_permutations, Sf_opague, Sf_opague, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
				} else {
					show_field (Sf_permutations, Sf_opague, Field, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
				}
				Move (Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Colored, opague, Sf_opague, Sf_allocation, allocation, number_of_players);
				
			} else if ((gamemode_played == Hunt)&&(geben == 1)) {
				if ((Field[0][Zeile_alt][Spalte_alt] != 1)&&(Field[0][Zeile_alt][Spalte_alt] != 11)){
					printf("	you made a mistake, try again: \n");
					Move (Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Colored, opague, Sf_opague, Sf_allocation, allocation, number_of_players);
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
							if (opague >= 1) {
								show_field (Sf_permutations, Sf_opague, Sf_opague, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
							} else {
								show_field (Sf_permutations, Sf_opague, Field, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);		//transform Spielfeld in Spielfeld[0], übergebe nur noch personal, done
							}
							Move (Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Colored, opague, Sf_opague, Sf_allocation, allocation, number_of_players);
							
						} else if (Field[0][Zeile_alt][Spalte_alt] == 1) {
							set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, temp_move, 0, Zeile_alt, Spalte_alt, 1);
							a = 0;								//Ursprung in der Nähe?
							if ((temp_move[0][Zeile_neu-1][Spalte_neu]==1)||(temp_move[0][Zeile_neu][Spalte_neu-1]==1)||(temp_move[0][Zeile_neu][Spalte_neu+1]==1)||(temp_move[0][Zeile_neu+1][Spalte_neu]==1)){
								a = 1;
							}
							if (a == 0){
								printf("	you made a mistake, try again: \n");
								Move (Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Colored, opague, Sf_opague, Sf_allocation, allocation, number_of_players);
							} else if (Field[0][Zeile_neu][Spalte_neu] != 0){
								printf("	you made a mistake, try again: \n");
								Move (Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Colored, opague, Sf_opague, Sf_allocation, allocation, number_of_players);
							} else {
								set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, Zeile_neu, Spalte_neu, 1);
								if (allocation != 0) {
									Sf_allocation[0][Zeile_neu][Spalte_neu] = Sf_allocation[0][Zeile_alt][Spalte_alt];
									Sf_allocation[0][Zeile_alt][Spalte_alt] = 0;
								}
								set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, Zeile_alt, Spalte_alt, 0);
							}
						} else if (Field[0][Zeile_alt][Spalte_alt] == 11) {
							set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, temp_move, 0, Zeile_alt, Spalte_alt, 11);
							a = 0;								//Ursprung in der Nähe?
							if ((temp_move[0][Zeile_neu-1][Spalte_neu]==11)||(temp_move[0][Zeile_neu][Spalte_neu-1]==11)||(temp_move[0][Zeile_neu][Spalte_neu+1]==11)||(temp_move[0][Zeile_neu+1][Spalte_neu]==11)){
								a = 1;
							}
							if (a == 0){
								printf("	you made a mistake, try again: \n");
								Move (Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Colored, opague, Sf_opague, Sf_allocation, allocation, number_of_players);
							} else if (Field[0][Zeile_neu][Spalte_neu] != 0){
								printf("	you made a mistake, try again: \n");
								Move (Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Colored, opague, Sf_opague, Sf_allocation, allocation, number_of_players);
							} else {
								set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, Zeile_neu, Spalte_neu, 11);
								if (allocation != 0) {
									Sf_allocation[0][Zeile_neu][Spalte_neu] = Sf_allocation[0][Zeile_alt][Spalte_alt];
									Sf_allocation[0][Zeile_alt][Spalte_alt] = 0;
								}
								set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, Zeile_alt, Spalte_alt, 0);
							}
						}
					}
				}
			} else if ((gamemode_played != Hunt)||(geben != 1)){
				if (Field[0][Zeile_alt][Spalte_alt] != geben){
					printf("	you made a mistake, try again: \n");
					Move (Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Colored, opague, Sf_opague, Sf_allocation, allocation, number_of_players);
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
							if (opague >= 1) {
								show_field (Sf_permutations, Sf_opague, Sf_opague, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
							} else {
								show_field (Sf_permutations, Sf_opague, Field, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
							}
							Move (Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Colored, opague, Sf_opague, Sf_allocation, allocation, number_of_players);
							
						} else {
							set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, temp_move, 0, Zeile_alt, Spalte_alt, geben);
							
							a = 0;								//Ursprung in der Nähe?
							if ((temp_move[0][Zeile_neu-1][Spalte_neu]==geben)||(temp_move[0][Zeile_neu][Spalte_neu-1]==geben)||(temp_move[0][Zeile_neu][Spalte_neu+1]==geben)||(temp_move[0][Zeile_neu+1][Spalte_neu]==geben)){
								a = 1;
							}
							
							if (a == 0){
								printf("	you made a mistake, try again: \n");
								Move (Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Colored, opague, Sf_opague, Sf_allocation, allocation, number_of_players);
							} else if (Field[0][Zeile_neu][Spalte_neu] != 0){
								printf("	you made a mistake, try again: \n");
								Move (Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Colored, opague, Sf_opague, Sf_allocation, allocation, number_of_players);
							} else {
								set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, Zeile_neu, Spalte_neu, geben);
								if (allocation != 0) {
									Sf_allocation[0][Zeile_neu][Spalte_neu] = Sf_allocation[0][Zeile_alt][Spalte_alt];
									Sf_allocation[0][Zeile_alt][Spalte_alt] = 0;
								}
								set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, Zeile_alt, Spalte_alt, 0);
							}
						}
						
					}
				}
			}
		}
		
		Spielfeld_Destroy (temp_move, m, 0);
	}
}

void Change (Spielfeld Sf_permutations, unsigned int m, unsigned int n, unsigned int geben, Spielfeld Field, unsigned int gamemode_played, unsigned int* information_code, unsigned int* Colored, unsigned int opague, Spielfeld Sf_opague, unsigned int* position, Spielfeld Sf_allocation, unsigned int allocation, unsigned int number_of_players){
	unsigned int geben_change, a, b;
	unsigned int eigene_Zeile, fremde_Zeile, eigene_Spalte, fremde_Spalte, heart_Zeile, heart_Spalte, normal_Zeile, normal_Spalte;
	
	b = 0;
	eigene_Zeile = 0;
	fremde_Zeile = 0;
	eigene_Spalte = 0;
	fremde_Spalte = 0;
	heart_Zeile = 0;
	heart_Spalte = 0;
	normal_Zeile = 0;
	normal_Spalte = 0;
	
	if ((gamemode_played != Hunt)&&(gamemode_played != Arena)&&(gamemode_played != Ulcer)&&(gamemode_played != Dynamic)&&(gamemode_played != Survive)&&(gamemode_played != Sand)) {	//mehr-gamemode_played
		geben_change = (geben%2)+1;
	} else if ((gamemode_played == Hunt)&&(geben != 1)) {
		geben_change = 1;
	} else if ((gamemode_played == Hunt)||(gamemode_played == Arena)||(gamemode_played == Ulcer)||(gamemode_played == Dynamic)||(gamemode_played == Survive)||(gamemode_played == Sand)) {	//mehr-gamemode_played
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
							set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, h-1, k, 11);
							set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, h, k, 1);
							break;
						} else if (Field[0][h][k-1]==1){
							b = 1;
							set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, h, k-1, 11);
							set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, h, k, 1);
							break;
						} else if (Field[0][h][k+1]==1){
							b = 1;
							set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, h, k+1, 11);
							set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, h, k, 1);
							break;
						} else if (Field[0][h+1][k]==1){
							b = 1;
							set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, h+1, k, 11);
							set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, h, k, 1);
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
				Move (Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Colored, opague, Sf_opague, Sf_allocation, allocation, number_of_players);
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
						if (opague >= 1) {
							show_field (Sf_permutations, Sf_opague, Sf_opague, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
						} else {
							show_field (Sf_permutations, Sf_opague, Field, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
						}
						Change (Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Colored, opague, Sf_opague, position, Sf_allocation, allocation, number_of_players);
						
					} else if ((Field[0][normal_Zeile][normal_Spalte] != 1)||((abs(normal_Spalte - heart_Spalte) + abs(normal_Zeile - heart_Zeile)) != 1)){
						printf("	you made a mistake, try again: \n");
						Change (Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Colored, opague, Sf_opague, position, Sf_allocation, allocation, number_of_players);
					} else if (((Field[0][normal_Zeile+1][normal_Spalte]%10) > 1)||((Field[0][normal_Zeile-1][normal_Spalte]%10) > 1)||((Field[0][normal_Zeile][normal_Spalte+1]%10) > 1)||((Field[0][normal_Zeile][normal_Spalte-1]%10) > 1)) {
						printf("	it isn't possible, try again: \n");
						Change (Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Colored, opague, Sf_opague, position, Sf_allocation, allocation, number_of_players);
					} else {
						set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, normal_Zeile, normal_Spalte, 11);
						set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, heart_Zeile, heart_Spalte, 1);
					}
				}
			}
		
		}
	}
	
	if ((gamemode_played == Classic)||(gamemode_played == Collect)||(gamemode_played == Fall)||(gamemode_played == Fight)||(gamemode_played == Race)||((gamemode_played == Hunt)&&(geben != 1))) {
		
		for (unsigned int h=1; h<=(m-2); h+=1){
			for (unsigned int k=1; k<=(n-2); k+=1){
				if (Field[0][h][k] == geben){
					if (Field[0][h-1][k]==geben_change){
						b+=1;
					}
					if (Field[0][h][k-1]==geben_change){
						b+=1;
					}
					if (Field[0][h][k+1]==geben_change){
						b+=1;
					}
					if (Field[0][h+1][k]==geben_change){
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
	} else if (gamemode_played == Contact) {
	
		for (unsigned int h=1; h<=(m-2); h+=1){
			for (unsigned int k=1; k<=(n-2); k+=1){
				if (Field[0][h][k] == geben){
					for (unsigned int u=(h-1); u<=(h+1); u+=1){
						for (unsigned int o=(k-1); o<=(k+1); o+=1){
							if (Field[0][u][o] == geben_change){
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
					if (Field[0][h-1][k]==7){
						b+=1;
					}
					if (Field[0][h][k-1]==7){
						b+=1;
					}
					if (Field[0][h][k+1]==7){
						b+=1;
					}
					if (Field[0][h+1][k]==7){
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
	} else if ((gamemode_played == Arena)||(gamemode_played == Ulcer)||(gamemode_played == Dynamic)||(gamemode_played == Survive)||(gamemode_played == Sand)) {	//nur Berechnung, kein Change direkt, mehr-gamemode_played
		for (unsigned int h=1; h<=(m-2); h+=1){
			for (unsigned int k=1; k<=(n-2); k+=1){
				if (Field[0][h][k] == geben){
					if ((Field[0][h-1][k] != 0)&&(Field[0][h-1][k] != geben)){
						b+=1;
					}
					if ((Field[0][h][k-1] != 0)&&(Field[0][h][k-1] != geben)){
						b+=1;
					}
					if ((Field[0][h+1][k] != 0)&&(Field[0][h+1][k] != geben)){
						b+=1;
					}
					if ((Field[0][h][k+1] != 0)&&(Field[0][h][k+1] != geben)){
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
	}
	
	if (b == 1){
		b = 0;
		
		if ((gamemode_played == Classic)||(gamemode_played == Collect)||(gamemode_played == Fall)||(gamemode_played == Fight)||(gamemode_played == Race)||((gamemode_played == Hunt)&&(geben != 1))) {
			for (unsigned int h=1; h<=(m-2); h+=1){
				for (unsigned int k=1; k<=(n-2); k+=1){
					if (Field[0][h][k] == geben){
						if (Field[0][h-1][k]==geben_change){
							b = 1;
							set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, h-1, k, geben);
							set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, h, k, geben_change);
							break;
						} else if (Field[0][h][k-1]==geben_change){
							b = 1;
							set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, h, k-1, geben);
							set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, h, k, geben_change);
							break;
						} else if (Field[0][h][k+1]==geben_change){
							b = 1;
							set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, h, k+1, geben);
							set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, h, k, geben_change);
							break;
						} else if (Field[0][h+1][k]==geben_change){
							b = 1;
							set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, h+1, k, geben);
							set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, h, k, geben_change);
							break;
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
								if (Field[0][u][o] == geben_change){
									b = 1;
									set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, u, o, geben);
									set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, h, k, geben_change);
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
						if (Field[0][h-1][k]==7){
							b = 1;
							set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, h-1, k, geben);
							set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, h, k, 7);
							break;
						} else if (Field[0][h][k-1]==7){
							b = 1;
							set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, h, k-1, geben);
							set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, h, k, 7);
							break;
						} else if (Field[0][h][k+1]==7){
							b = 1;
							set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, h, k+1, geben);
							set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, h, k, 7);
							break;
						} else if (Field[0][h+1][k]==7){
							b = 1;
							set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, h+1, k, geben);
							set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, h, k, 7);
							break;
						}
					}
				}
				if (b == 1){
					break;
				}
			}
		} else if ((gamemode_played == Arena)||(gamemode_played == Ulcer)||(gamemode_played == Survive)||(gamemode_played == Sand)) {	//mehr-gamemode_played
			for (unsigned int h=1; h<=(m-2); h+=1){
				for (unsigned int k=1; k<=(n-2); k+=1){
					if (Field[0][h][k] == geben){
						if ((Field[0][h-1][k] != 0)&&(Field[0][h-1][k] != geben)){
							set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, h-1, k, Field[0][h-1][k]);
							set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, h-1, k, geben);
							b = 1;
						}
						if ((Field[0][h][k-1] != 0)&&(Field[0][h][k-1] != geben)){
							set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, h, k, Field[0][h][k-1]);
							set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, h, k-1, geben);
							b = 1;
						}
						if ((Field[0][h+1][k] != 0)&&(Field[0][h+1][k] != geben)){
							set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, h, k, Field[0][h+1][k]);
							set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, h+1, k, geben);
							b = 1;
						}
						if ((Field[0][h][k+1] != 0)&&(Field[0][h][k+1] != geben)){
							set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, h, k, Field[0][h][k+1]);
							set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, h, k+1, geben);
							b = 1;
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
		} else if (gamemode_played == Dynamic) {
			for (unsigned int h=1; h<=(m-2); h+=1){
				for (unsigned int k=1; k<=(n-2); k+=1){
					if (Field[0][h][k] == geben){
						if ((Field[0][h-1][k] != 0)&&(Field[0][h-1][k] != geben)){
							set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, h, k, Field[0][h-1][k]);
							set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, h-1, k, geben);
							b = 1;
						}
						if ((Field[0][h][k-1] != 0)&&(Field[0][h][k-1] != geben)){
							set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, h, k, Field[0][h][k-1]);
							set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, h, k-1, geben);
							b = 1;
						}
						if ((Field[0][h+1][k] != 0)&&(Field[0][h+1][k] != geben)){
							set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, h, k, Field[0][h+1][k]);
							set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, h+1, k, geben);
							b = 1;
						}
						if ((Field[0][h][k+1] != 0)&&(Field[0][h][k+1] != geben)){
							set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, h, k, Field[0][h][k+1]);
							set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, h, k+1, geben);
							b = 1;
						}
						
						if (Field[0][h][k] == 77) {	//object instead of geben, nach dem change
							position[Vertikal] = h;
							position[Horizontal] = k;
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
				if (opague >= 1) {
					show_field (Sf_permutations, Sf_opague, Sf_opague, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
				} else {
					show_field (Sf_permutations, Sf_opague, Field, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
				}
				Change (Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Colored, opague, Sf_opague, position, Sf_allocation, allocation, number_of_players);
				
			} else if (Field[0][eigene_Zeile][eigene_Spalte] != geben){
				printf("	you made a mistake, try again: \n");
				Change (Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Colored, opague, Sf_opague, position, Sf_allocation, allocation, number_of_players);
			} else {
				
				a = 0;								//Feind in der Nähe?
				if ((gamemode_played == Classic)||(gamemode_played == Collect)||(gamemode_played == Fall)||(gamemode_played == Fight)||(gamemode_played == Hunt)||(gamemode_played == Race)) {
					if ((Field[0][eigene_Zeile-1][eigene_Spalte]==geben_change)||(Field[0][eigene_Zeile][eigene_Spalte-1]==geben_change)||(Field[0][eigene_Zeile][eigene_Spalte+1]==geben_change)||(Field[0][eigene_Zeile+1][eigene_Spalte]==geben_change)){
						a = 1;
					}
				} else if (gamemode_played == Contact) {
					for (unsigned int h=eigene_Zeile-1; h<=eigene_Zeile+1; h+=1){
						for (unsigned int k=eigene_Spalte-1; k<=eigene_Spalte+1; k+=1){
							if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
								if (Field[0][h][k] == geben_change){
									a = 1;
								}
							}
						}
					}
				} else if (gamemode_played == Rain){
					if ((Field[0][eigene_Zeile-1][eigene_Spalte]==7)||(Field[0][eigene_Zeile][eigene_Spalte-1]==7)||(Field[0][eigene_Zeile][eigene_Spalte+1]==7)||(Field[0][eigene_Zeile+1][eigene_Spalte]==7)){
						a = 1;
					}
				} else if ((gamemode_played == Arena)||(gamemode_played == Ulcer)||(gamemode_played == Dynamic)||(gamemode_played == Survive)||(gamemode_played == Sand)) {	//mehr-gamemode_played
					if (((Field[0][eigene_Zeile-1][eigene_Spalte]!=geben)&&(Field[0][eigene_Zeile-1][eigene_Spalte]!=0))||((Field[0][eigene_Zeile][eigene_Spalte-1]!=geben)&&(Field[0][eigene_Zeile][eigene_Spalte-1]!=0))||((Field[0][eigene_Zeile][eigene_Spalte+1]!=geben)&&(Field[0][eigene_Zeile][eigene_Spalte+1]!=0))||((Field[0][eigene_Zeile+1][eigene_Spalte]!=geben)&&(Field[0][eigene_Zeile+1][eigene_Spalte]!=0))){
						a = 1;
					}
				}
				
				
				if (a == 0){
					printf("	you made a mistake, try again: \n");
					Change (Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Colored, opague, Sf_opague, position, Sf_allocation, allocation, number_of_players);
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
							if (opague >= 1) {
								show_field (Sf_permutations, Sf_opague, Sf_opague, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
							} else {
								show_field (Sf_permutations, Sf_opague, Field, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
							}
							Change (Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Colored, opague, Sf_opague, position, Sf_allocation, allocation, number_of_players);
							
						} else if ((gamemode_played != Contact)&&(gamemode_played != Rain)&&(gamemode_played != Arena)&&(gamemode_played != Ulcer)&&(gamemode_played != Dynamic)&&(gamemode_played != Survive)&&(gamemode_played != Sand)) {	//mehr-gamemode_played
							if ((Field[0][fremde_Zeile][fremde_Spalte] != geben_change)||(abs(fremde_Spalte-eigene_Spalte)+abs(fremde_Zeile-eigene_Zeile)!= 1)){
								printf("	you made a mistake, try again: \n");
								Change (Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Colored, opague, Sf_opague, position, Sf_allocation, allocation, number_of_players);
							} else {
								set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, fremde_Zeile, fremde_Spalte, geben); 
								set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, eigene_Zeile, eigene_Spalte, geben_change);
							}
						} else if (gamemode_played == Contact) {
							if ((Field[0][fremde_Zeile][fremde_Spalte] != geben_change)||(abs(fremde_Spalte-eigene_Spalte)>1)||(abs(fremde_Zeile-eigene_Zeile)>1)){
								printf("	you made a mistake, try again: \n");
								Change (Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Colored, opague, Sf_opague, position, Sf_allocation, allocation, number_of_players);
							} else {
								set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, fremde_Zeile, fremde_Spalte, geben);
								set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, eigene_Zeile, eigene_Spalte, geben_change);
							}
						} else if (gamemode_played == Rain) {
							if ((Field[0][fremde_Zeile][fremde_Spalte] != 7)||(abs(fremde_Spalte-eigene_Spalte)+abs(fremde_Zeile-eigene_Zeile)!= 1)){
								printf("	you made a mistake, try again: \n");
								Change (Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Colored, opague, Sf_opague, position, Sf_allocation, allocation, number_of_players);
							} else {
								set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, fremde_Zeile, fremde_Spalte, geben);
								set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, eigene_Zeile, eigene_Spalte, 7);
							}
						} else if ((gamemode_played == Arena)||(gamemode_played == Ulcer)||(gamemode_played == Survive)||(gamemode_played == Sand)) {
							if ((Field[0][fremde_Zeile][fremde_Spalte] == 0)||(Field[0][fremde_Zeile][fremde_Spalte] == geben)||(abs(fremde_Spalte-eigene_Spalte)+abs(fremde_Zeile-eigene_Zeile)!= 1)){
								printf("	you made a mistake, try again: \n");
								Change (Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Colored, opague, Sf_opague, position, Sf_allocation, allocation, number_of_players);
							} else {
								set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, eigene_Zeile, eigene_Spalte, Field[0][fremde_Zeile][fremde_Spalte]);
								set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, fremde_Zeile, fremde_Spalte, geben);
							}
						} else if (gamemode_played == Dynamic) {
							if ((Field[0][fremde_Zeile][fremde_Spalte] == 0)||(Field[0][fremde_Zeile][fremde_Spalte] == geben)||(abs(fremde_Spalte-eigene_Spalte)+abs(fremde_Zeile-eigene_Zeile)!= 1)){
								printf("	you made a mistake, try again: \n");
								Change (Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Colored, opague, Sf_opague, position, Sf_allocation, allocation, number_of_players);
							} else {
								set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, eigene_Zeile, eigene_Spalte, Field[0][fremde_Zeile][fremde_Spalte]);
								set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, fremde_Zeile, fremde_Spalte, geben);
								
								if (Field[0][eigene_Zeile][eigene_Spalte] == 77) {	//object instead of geben
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
}

void Destroy (Spielfeld Sf_permutations, unsigned int m, unsigned int n, unsigned int geben, Spielfeld Field, unsigned int gamemode_played, unsigned int* information_code, unsigned int* Colored, unsigned int opague, Spielfeld Sf_opague, Spielfeld Sf_allocation, unsigned int allocation, unsigned int number_of_players){
	unsigned int geben_destroy, a, b;
	unsigned int fremde_Zeile, fremde_Spalte;
	
	fremde_Zeile = 0;
	fremde_Spalte = 0;
	
	if ((gamemode_played != Hunt)&&(gamemode_played != Arena)&&(gamemode_played != Ulcer)&&(gamemode_played != Dynamic)&&(gamemode_played != Survive)&&(gamemode_played != Sand)) {	//mehr-gamemode_played
		geben_destroy = (geben%2)+1;
	} else if ((gamemode_played == Hunt)&&(geben != 1)) {
		geben_destroy = 1;
	} else if ((gamemode_played == Arena)||(gamemode_played == Ulcer)||(gamemode_played == Dynamic)||(gamemode_played == Survive)||(gamemode_played == Sand)) {
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
				Destroy (Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Colored, opague, Sf_opague, Sf_allocation, allocation, number_of_players);
			} else {
				set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, fremde_Zeile, fremde_Spalte, 0);
			}
		}
	} else if ((gamemode_played != Hunt)||(geben != 1)) {
		
		b = 0;
		if ((gamemode_played == Classic)||(gamemode_played == Collect)||(gamemode_played == Fall)||(gamemode_played == Fight)||(gamemode_played == Race)||(gamemode_played == Hunt)) {
			for (unsigned int h=1; h<=(m-2); h+=1){
				for (unsigned int k=1; k<=(n-2); k+=1){
					if (Field[0][h][k] == geben){
						if (Field[0][h-1][k]==geben_destroy){
							b+=1;
						}
						if (Field[0][h][k-1]==geben_destroy){
							b+=1;
						}
						if (Field[0][h][k+1]==geben_destroy){
							b+=1;
						}
						if (Field[0][h+1][k]==geben_destroy){
							b+=1;
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
								if (Field[0][u][o] == geben_destroy){
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
					if (Field[0][h][k] == geben_destroy){
						b += 1;
					}
				}
			}
		} else if ((gamemode_played == Arena)||(gamemode_played == Survive)||(gamemode_played == Sand)) {
			for (unsigned int h=1; h<=(m-2); h+=1){
				for (unsigned int k=1; k<=(n-2); k+=1){
					if (Field[0][h][k] == geben){
						if ((Field[0][h-1][k] != geben)&&(Field[0][h-1][k] != 0)){
							b+=1;
						}
						if ((Field[0][h][k-1] != geben)&&(Field[0][h][k-1] != 0)){
							b+=1;
						}
						if ((Field[0][h][k+1] != geben)&&(Field[0][h][k+1] != 0)){
							b+=1;
						}
						if ((Field[0][h+1][k] != geben)&&(Field[0][h+1][k] != 0)){
							b+=1;
						}
					}
				}
			}
		} else if (gamemode_played == Ulcer) {
			for (unsigned int h=1; h<=(m-2); h+=1){
				for (unsigned int k=1; k<=(n-2); k+=1){
					if (Field[0][h][k] == geben){
						if ((Field[0][h-1][k] != geben)&&(Field[0][h-1][k] != 0)&&(Field[0][h-1][k] != 1)){
							b+=1;
						}
						if ((Field[0][h][k-1] != geben)&&(Field[0][h][k-1] != 0)&&(Field[0][h][k-1] != 1)){
							b+=1;
						}
						if ((Field[0][h][k+1] != geben)&&(Field[0][h][k+1] != 0)&&(Field[0][h][k+1] != 1)){
							b+=1;
						}
						if ((Field[0][h+1][k] != geben)&&(Field[0][h+1][k] != 0)&&(Field[0][h+1][k] != 1)){
							b+=1;
						}
					}
				}
			}
		} else if (gamemode_played == Dynamic) {
			for (unsigned int h=1; h<=(m-2); h+=1){
				for (unsigned int k=1; k<=(n-2); k+=1){
					if (Field[0][h][k] == geben){
						if ((Field[0][h-1][k] != geben)&&(Field[0][h-1][k] != 0)&&(Field[0][h-1][k] != 77)){
							b+=1;
						}
						if ((Field[0][h][k-1] != geben)&&(Field[0][h][k-1] != 0)&&(Field[0][h][k-1] != 77)){
							b+=1;
						}
						if ((Field[0][h][k+1] != geben)&&(Field[0][h][k+1] != 0)&&(Field[0][h][k+1] != 77)){
							b+=1;
						}
						if ((Field[0][h+1][k] != geben)&&(Field[0][h+1][k] != 0)&&(Field[0][h+1][k] != 77)){
							b+=1;
						}
					}
				}
			}
		}
		
		if (b == 1){
			b = 0;
			
			if ((gamemode_played == Classic)||(gamemode_played == Collect)||(gamemode_played == Fall)||(gamemode_played == Fight)||(gamemode_played == Race)||(gamemode_played == Hunt)) {
				for (unsigned int h=1; h<=(m-2); h+=1){
					for (unsigned int k=1; k<=(n-2); k+=1){
						if (Field[0][h][k] == geben){
							if (Field[0][h-1][k]==geben_destroy){
								b = 1;
								set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, h-1, k, 0);
								break;
							} else if (Field[0][h][k-1]==geben_destroy){
								b = 1;
								set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, h, k-1, 0);
								break;
							} else if (Field[0][h][k+1]==geben_destroy){
								b = 1;
								set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, h, k+1, 0);
								break;
							} else if (Field[0][h+1][k]==geben_destroy){
								b = 1;
								set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, h+1, k, 0);
								break;
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
									if (Field[0][u][o] == geben_destroy){
										b = 1;
										set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, u, o, 0);
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
				for (unsigned int h=1; h<=(m-4); h+=1){
					for (unsigned int k=1; k<=(n-2); k+=1){
						if (Field[0][h][k] == geben_destroy){
							b = 1;
							set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, h, k, 0);
							break;
						}
					}
					if (b == 1){
						break;
					}
				}
			} else if ((gamemode_played == Arena)||(gamemode_played == Survive)||(gamemode_played == Sand)) {
				for (unsigned int h=1; h<=(m-2); h+=1){
					for (unsigned int k=1; k<=(n-2); k+=1){
						if (Field[0][h][k] == geben){
							if ((Field[0][h-1][k] != geben)&&(Field[0][h-1][k] != 0)){
								b = 1;
								set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, h-1, k, 0);
								break;
							}
							if ((Field[0][h][k-1] != geben)&&(Field[0][h][k-1] != 0)){
								b = 1;
								set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, h, k-1, 0);
								break;
							}
							if ((Field[0][h][k+1] != geben)&&(Field[0][h][k+1] != 0)){
								b = 1;
								set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, h, k+1, 0);
								break;
							}
							if ((Field[0][h+1][k] != geben)&&(Field[0][h+1][k] != 0)){
								b = 1;
								set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, h+1, k, 0);
								break;
							}
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
							if ((Field[0][h-1][k] != geben)&&(Field[0][h-1][k] != 0)&&(Field[0][h-1][k] != 1)){
								b = 1;
								set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, h-1, k, 0);
								break;
							}
							if ((Field[0][h][k-1] != geben)&&(Field[0][h][k-1] != 0)&&(Field[0][h][k-1] != 1)){
								b = 1;
								set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, h, k-1, 0);
								break;
							}
							if ((Field[0][h][k+1] != geben)&&(Field[0][h][k+1] != 0)&&(Field[0][h][k+1] != 1)){
								b = 1;
								set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, h, k+1, 0);
								break;
							}
							if ((Field[0][h+1][k] != geben)&&(Field[0][h+1][k] != 0)&&(Field[0][h+1][k] != 1)){
								b = 1;
								set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, h+1, k, 0);
								break;
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
							if ((Field[0][h-1][k] != geben)&&(Field[0][h-1][k] != 0)&&(Field[0][h-1][k] != 77)){
								b = 1;
								set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, h-1, k, 0);
								break;
							}
							if ((Field[0][h][k-1] != geben)&&(Field[0][h][k-1] != 0)&&(Field[0][h][k-1] != 77)){
								b = 1;
								set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, h, k-1, 0);
								break;
							}
							if ((Field[0][h][k+1] != geben)&&(Field[0][h][k+1] != 0)&&(Field[0][h][k+1] != 77)){
								b = 1;
								set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, h, k+1, 0);
								break;
							}
							if ((Field[0][h+1][k] != geben)&&(Field[0][h+1][k] != 0)&&(Field[0][h+1][k] != 77)){
								b = 1;
								set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, h+1, k, 0);
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
					if (opague >= 1) {
						show_field (Sf_permutations, Sf_opague, Sf_opague, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
					} else {
						show_field (Sf_permutations, Sf_opague, Field, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
					}
					Destroy (Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Colored, opague, Sf_opague, Sf_allocation, allocation, number_of_players);
					
				} else if ((gamemode_played == Classic)||(gamemode_played == Collect)||(gamemode_played == Fall)||(gamemode_played == Fight)||(gamemode_played == Hunt)||(gamemode_played == Race)||(gamemode_played == Arena)||(gamemode_played == Ulcer)||(gamemode_played == Dynamic)||(gamemode_played == Survive)||(gamemode_played == Sand)) {	//mehr-gamemode_played
					if ((Field[0][fremde_Zeile-1][fremde_Spalte]==geben)||(Field[0][fremde_Zeile][fremde_Spalte-1]==geben)||(Field[0][fremde_Zeile][fremde_Spalte+1]==geben)||(Field[0][fremde_Zeile+1][fremde_Spalte]==geben)){
						a = 1;
					}
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
				}
				
				if (a == 0){
					printf("	you made a mistake, try again: \n");
					Destroy (Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Colored, opague, Sf_opague, Sf_allocation, allocation, number_of_players);
				} else if ((gamemode_played != Sand)&&(gamemode_played != Survive)&&(gamemode_played != Dynamic)&&(gamemode_played != Ulcer)&&(gamemode_played != Arena)&&(Field[0][fremde_Zeile][fremde_Spalte] != geben_destroy)){	//mehr-gamemode_played
					printf("	you made a mistake, try again: \n");
					Destroy (Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Colored, opague, Sf_opague, Sf_allocation, allocation, number_of_players);
				} else if (((gamemode_played == Sand)||(gamemode_played == Survive)||(gamemode_played == Arena))&&((Field[0][fremde_Zeile][fremde_Spalte] == 0)||(Field[0][fremde_Zeile][fremde_Spalte] == geben))){
					printf("	you made a mistake, try again: \n");
					Destroy (Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Colored, opague, Sf_opague, Sf_allocation, allocation, number_of_players);
				} else if ((gamemode_played == Ulcer)&&((Field[0][fremde_Zeile][fremde_Spalte] == 0)||(Field[0][fremde_Zeile][fremde_Spalte] == geben)||(Field[0][fremde_Zeile][fremde_Spalte] == 1))){
					printf("	you made a mistake, try again: \n");
					Destroy (Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Colored, opague, Sf_opague, Sf_allocation, allocation, number_of_players);
				} else if ((gamemode_played == Dynamic)&&((Field[0][fremde_Zeile][fremde_Spalte] == 0)||(Field[0][fremde_Zeile][fremde_Spalte] == geben)||(Field[0][fremde_Zeile][fremde_Spalte] == 77))){
					printf("	you made a mistake, try again: \n");
					Destroy (Sf_permutations, m, n, geben, Field, gamemode_played, information_code, Colored, opague, Sf_opague, Sf_allocation, allocation, number_of_players);
				} else {
					Field[0][fremde_Zeile][fremde_Spalte] = 0;
					Sf_allocation[0][fremde_Zeile][fremde_Spalte] = 0;
				}
			}
		}
	}
	
}

void Revive (unsigned int m, unsigned int n, Spielfeld Sf_od_, Spielfeld Field, unsigned int geben, Spielfeld Sf_allocation, unsigned int allocation, Spielfeld Sf_opague, unsigned int number_of_players){
	unsigned int a;
	Spielfeld temp;
	
	temp = Spielfeld_Create (m, n, 0);
	a = 0;
	
	for (unsigned int i=1; i<m-1; i+=1){
		for (unsigned int j=1; j<n-1; j+=1){
			if (Sf_od_[geben][i][j] == 101*geben){
				set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, temp, 0, i, j, 101*geben);
				for (unsigned int h=i-1; h<=i+1; h+=1){
					for (unsigned int k=j-1; k<=j+1; k+=1){
						if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
							if ((Field[0][h][k] == geben) && (Sf_od_[geben][h][k] != 101*geben)){
								a+=1;
							}
						}
					}
				}
				if (a == 0){
					set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, temp, 0, i, j, 0);
				}
				a = 0;
			}
		}
	}
	
	for (unsigned int i=1; i<m-1; i+=1){
		for (unsigned int j=1; j<n-1; j+=1){
			if ((Sf_od_[geben][i][j] == 101*geben) && (temp[0][i][j] == 0)){
				set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Sf_od_, geben, i, j, 0);
			}
		}
	}
	
	Spielfeld_Destroy (temp, m, 0);
}

void Boost (unsigned int geben, Spielfeld Field, unsigned int m, unsigned int n, Spielfeld temp, unsigned int gamemode_played, Spielfeld Sf_opague, Spielfeld Sf_allocation, unsigned int allocation, unsigned int number_of_players){
	unsigned int geben_Boost;
				//printf("?");
	if ((gamemode_played != Hunt)&&(gamemode_played != Arena)&&(gamemode_played != Ulcer)&&(gamemode_played != Dynamic)&&(gamemode_played != Survive)&&(gamemode_played != Sand)) {	//mehr-gamemode_played
		geben_Boost = (geben%2)+1;
	} else if (gamemode_played == Hunt) {
		geben_Boost = 1;
	} else if ((gamemode_played == Arena)||(gamemode_played == Ulcer)||(gamemode_played == Dynamic)||(gamemode_played == Survive)||(gamemode_played == Sand)) {
		geben_Boost = 0;
	}
	
	
	if ((gamemode_played == Classic)||(gamemode_played == Collect)||(gamemode_played == Fall)||(gamemode_played == Fight)||((gamemode_played == Hunt)&&(geben != 1))||(gamemode_played == Race)) {
		for (unsigned int i=1; i<m-1; i+=1){
			for (unsigned int j=1; j<n-1; j+=1){
				if (Field[0][i][j] == geben_Boost) {
					if ((Field[0][i-1][j]==geben)||(Field[0][i][j-1]==geben)||(Field[0][i][j+1]==geben)||(Field[0][i+1][j]==geben)){
						set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, temp, 0, i, j, geben);
					}
				}
			}
		}
	} else if (gamemode_played == Contact) {
		for (unsigned int i=1; i<m-1; i+=1){
			for (unsigned int j=1; j<n-1; j+=1){
				if (Field[0][i][j] == geben_Boost) {
					for (unsigned int h=i-1; h<=i+1; h+=1){
						for (unsigned int k=j-1; k<=j+1; k+=1){
							if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
								if (Field[0][h][k] == geben){
									set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, temp, 0, i, j, geben);
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
				if (Field[0][i][j] == 7) {
					if ((Field[0][i-1][j]==geben)||(Field[0][i][j-1]==geben)||(Field[0][i][j+1]==geben)||(Field[0][i+1][j]==geben)){
						set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, temp, 0, i, j, geben);
					}
				}
			}
		}
	} else if ((gamemode_played == Arena)||(gamemode_played == Ulcer)||(gamemode_played == Dynamic)||(gamemode_played == Survive)||(gamemode_played == Sand)) {	//mehr-gamemode_played
		for (unsigned int i=1; i<m-1; i+=1){
			for (unsigned int j=1; j<n-1; j+=1){
				if ((Field[0][i][j] != geben)&&(Field[0][i][j] != 0)) {
					if ((Field[0][i-1][j]==geben)||(Field[0][i][j-1]==geben)||(Field[0][i][j+1]==geben)||(Field[0][i+1][j]==geben)){
						set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, temp, 0, i, j, Field[0][i][j]);
					}
				}
			}
		}
	}
	
	for (unsigned int i=1; i<m-1; i+=1){
		for (unsigned int j=1; j<n-1; j+=1){
			if ((gamemode_played != Arena)&&(gamemode_played != Ulcer)&&(gamemode_played != Dynamic)&&(gamemode_played != Survive)&&(gamemode_played != Sand)) {	//mehr-gamemode_played
				if (temp[0][i][j] == geben){
					set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j, geben);
				}
			} else if ((gamemode_played == Arena)||(gamemode_played == Ulcer)||(gamemode_played == Dynamic)||(gamemode_played == Survive)||(gamemode_played == Sand)) {
				if (temp[0][i][j] != 0){
					set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j, geben);
				}
			}
		}
	}
	
}

void Index (unsigned int ent, unsigned int count_new, unsigned int m, unsigned int n, Spielfeld Sf_nl_, Spielfeld Sf_od_, unsigned int limit_new, unsigned int limit_at_all, unsigned int zeitgewinner, Spielfeld Field, unsigned int w, unsigned int d, unsigned int e, unsigned int geben, unsigned int* position, unsigned int gamemode_played, unsigned int number_of_players, unsigned int rain, Spielfeld Sf_opague, Spielfeld Sf_allocation, unsigned int allocation){
	unsigned int Index_Wert, a, b, c, f, ind, ober, heart_i, heart_j, keep;
	Spielfeld Index_Feld;
	
	ind = 0;
	keep = 0;
	f = 0;
	b = 0;
	c = 0;
	a = 0;
	Index_Wert = 0;
	Index_Feld = Spielfeld_Create (m, n, 0);
	
	if (d == 10) {	//Arena
		d = 0;
	}
	
	if ((gamemode_played == Hunt)&&(geben == 1)) {
		
		limit_new = (limit_new + (number_of_players-3));
		limit_at_all = (limit_at_all + (2*(number_of_players-3)));
	
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
		
		Field[0][heart_i][heart_j] = 1;	//heart versteckt
	}
	
	if ((zeitgewinner >= limit_at_all)&&(gamemode_played != Contact)) {
		for (unsigned int i=1; i<m-1; i+=1){
			for (unsigned int j=1; j<n-1; j+=1){
				if (Sf_nl_[geben][i][j] == geben){
					set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Sf_nl_, geben, i, j, 0);
				}
			}
		}
	} else if ((gamemode_played != Hunt)||(geben == 1)) {
		
		while ((ind != 1)&&(ind != 2)){
			printf (" \n");
			printf (" \n");
			printf (" How do you want to play: \n");
			printf (" \n");
			if (ent == limit_new){
				if ((gamemode_played == Dynamic)||(gamemode_played == Arena)||(gamemode_played == Sand)) {
					printf(" #produce	defensive: 1		offensive: 2 \n");
					ind = get_unsigned_numeric_input_with_not_more_than_1_letter ();
				} else if (gamemode_played == Hunt) {
					printf(" #produce	defensive: 2		offensive: 1 \n");
					ind = get_unsigned_numeric_input_with_not_more_than_1_letter ();
				} else if ((gamemode_played == Rain)||(gamemode_played == Race)||(gamemode_played == Fight)||(gamemode_played == Fall)||(gamemode_played == Collect)) {
					printf(" #produce	keep bottom: 1		keep top: 2		equal: >=3 \n");
					keep = get_unsigned_numeric_input_with_not_more_than_1_letter ();
					ind = 1;
				} else if (gamemode_played == Contact) {
					printf(" #produce	keep top: 1		keep bottom: 2		keep left: 3		keep right: 4		don't matter: >=5 \n");
					keep = get_unsigned_numeric_input_with_not_more_than_1_letter ();
					ind = 2;
				} else if (gamemode_played == Classic) {
					printf(" #produce	defensive: 1		offensive: 2 	equal: >=3 \n");
					keep = get_unsigned_numeric_input_with_not_more_than_1_letter ();	//correct misuse of keep, done
					ind = 1;
				}
			}
			
			if ((ent >= (limit_at_all - 4))&&(gamemode_played != Contact)){		//min 5/10, watch out with Hunt on 2 players
				if ((gamemode_played == Dynamic)||(gamemode_played == Arena)||(gamemode_played == Sand)) {
					printf(" #reduce	defensive: 1		offensive: 2 \n");
					ind = get_unsigned_numeric_input_with_not_more_than_1_letter ();
				} else if (gamemode_played == Hunt) {
					printf(" #reduce	defensive: 2		offensive: 1 \n");
					ind = get_unsigned_numeric_input_with_not_more_than_1_letter ();
				} else if ((gamemode_played == Rain)||(gamemode_played == Race)||(gamemode_played == Fight)||(gamemode_played == Fall)||(gamemode_played == Collect)) {
					printf(" #reduce	keep bottom: 1		keep top: 2 	equal: >=3 \n");
					keep = get_unsigned_numeric_input_with_not_more_than_1_letter ();
					ind = 1;
				} else if (gamemode_played == Classic) {
					printf(" #reduce	defensive: 1		offensive: 2 	equal: >=3 \n");
					keep = get_unsigned_numeric_input_with_not_more_than_1_letter ();	//correct misuse of keep, done
					ind = 1;
				}
				
			}
			printf (" \n");
		}
		if (ind == 1) {
			if ((gamemode_played == Dynamic)||(gamemode_played == Fight)||(gamemode_played == Classic)) {
				ober = 80;
			} else if ((gamemode_played == Arena)||(gamemode_played == Hunt)) {
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
						if (Sf_nl_[geben][i][j] == geben){
							
							for (unsigned int h=i-1; h<=i+1; h+=1){		//Stirbt Zelle?
								for (unsigned int k=j-1; k<=j+1; k+=1){
									if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
										if ((Sf_nl_[geben][h][k] == geben) || ((Field[0][h][k] == geben) && (Sf_od_[geben][h][k] == 0))){
											a+=1;
										}
									}
								}	
							}
							if (a > e+1){
								Index_Wert += 3;
							}
							a = 0;
							
							Index_Wert += 8;
							for (unsigned int h=i-1; h<=i+1; h+=1){		//Regeneriert neue Zellen?
								for (unsigned int k=j-1; k<=j+1; k+=1){
									if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
										if (((Field[0][h][k] == 0) || ((Field[0][h][k] == geben)&&(Sf_od_[geben][h][k] == 101*geben))) && (Sf_nl_[geben][h][k] == 0)){
											for (unsigned int u=h-1; u<=h+1; u+=1){
												for (unsigned int o=k-1; o<=k+1; o+=1){
													if ((u>0)&&(u<(m-1))&&(o>0)&&(o<(n-1))){
														if ((Sf_nl_[geben][u][o] == geben) || ((Field[0][u][o] == geben) && (Sf_od_[geben][u][o] == 0))){
															a += 1;
														}
													}
												}
											}
											if (a == w){
												Index_Wert -= 1;
											}
											a = 0;
										}
									}
								}
							}
							if ((gamemode_played == Arena)||(gamemode_played == Hunt)||(gamemode_played == Rain)||(gamemode_played == Race)||(gamemode_played == Fight)||(gamemode_played == Collect)||(gamemode_played == Sand)) {
								for (unsigned int h=i-1; h<=i+1; h+=1){		//Stört feindliches Wachstum?
									for (unsigned int k=j-1; k<=j+1; k+=1){
										if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
											
											if (Field[0][h][k] != geben){
												a+=1;
											}
											
										}
									}	
								}
								if (a != 3){
									Index_Wert += 10;
									if (gamemode_played == Fight) {
										Index_Wert += 10;	//erneut +10
									}
								}
								a = 0;
								
							}
							
							for (unsigned int h=i-1; h<=i+1; h+=1){		//Regeneriert ihr Tod neue Zellen?
								for (unsigned int k=j-1; k<=j+1; k+=1){
									if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
										if (((Field[0][h][k] == 0) || ((Field[0][h][k] == geben)&&(Sf_od_[geben][h][k] == 101*geben))) && (Sf_nl_[geben][h][k] == 0)){
											for (unsigned int u=h-1; u<=h+1; u+=1){
												for (unsigned int o=k-1; o<=k+1; o+=1){
													if ((u>0)&&(u<(m-1))&&(o>0)&&(o<(n-1))){
														if ((Sf_nl_[geben][u][o] == geben) || ((Field[0][u][o] == geben) && (Sf_od_[geben][u][o] == 0))){
															a += 1;
														}
													}
												}
											}
											if (a == w+1){
												Index_Wert += 1;
											} 
											a = 0;
											
										}
									}
								}
							}
							
							for (unsigned int h=i-1; h<=i+1; h+=1){		//sterben eigene Zellen?
								for (unsigned int k=j-1; k<=j+1; k+=1){
									if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
										if (((Field[0][h][k] == geben) && (Sf_od_[geben][h][k] == 0)) ||(Sf_nl_[geben][h][k] == geben)){
											for (unsigned int u=h-1; u<=h+1; u+=1){
												for (unsigned int o=k-1; o<=k+1; o+=1){
													if ((u>0)&&(u<(m-1))&&(o>0)&&(o<(n-1))){
														if ((Sf_nl_[geben][u][o] == geben) || ((Field[0][u][o] == geben) && (Sf_od_[geben][u][o] == 0))){
															a += 1;
														}
													}
												}
											}
											if (a > e+1){
												Index_Wert += 3;
											}
											a = 0;
										}
									}
								}
							}
							
							for (unsigned int h=i-1; h<=i+1; h+=1){		//tötet ihr Tod eigene Zellen?
								for (unsigned int k=j-1; k<=j+1; k+=1){
									if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
										if (((Field[0][h][k] == geben) && (Sf_od_[geben][h][k] == 0)) ||(Sf_nl_[geben][h][k] == geben)){
											for (unsigned int u=h-1; u<=h+1; u+=1){
												for (unsigned int o=k-1; o<=k+1; o+=1){
													if ((u>0)&&(u<(m-1))&&(o>0)&&(o<(n-1))){
														if ((Sf_nl_[geben][u][o] == geben) || ((Field[0][u][o] == geben) && (Sf_od_[geben][u][o] == 0))){
															a += 1;
														}
													}
												}
											}
											if (a < d+1){
												b = 1;
											}
											a = 0;
										}
									}
								}
							}
							if (b != 1){
								Index_Wert += 10;
							} 
							b = 0;
							
							
							if (keep == 1) {
								Index_Wert += (6-i);
							} else if (keep == 2) {
								Index_Wert += i;
							}
							
							if (gamemode_played == Dynamic) {		//gamemode_played depending specials
								if ((i == position[Vertikal])||(j == position[Horizontal])) {
									Index_Wert = 1;
								}
							} else if (gamemode_played == Hunt) {
								if ((i+1 != heart_i)&&(i-1 != heart_i)&&(j-1 != heart_j)&&(j+1 != heart_j)){
									Index_Wert += 10;
								}
							} else if (gamemode_played == Rain) {
								
								if (j > ((n-1)/2)){
									Index_Wert += (j-(n-1)/2);
								} else if (j < ((n-1)/2)){
									Index_Wert += (((n-1)/2)-j);
								}
								
								Index_Wert += i;
								
								if ((i <= 2)&&((j >= ((n-3)/2))&&(j <= ((n+1)/2)))){
									Index_Wert = 1;
								}
								
								if ((rain == 31)||(rain == 32)||(rain == 2)){
									if (Field[0][i-1][j] == 7){
										Index_Wert = 80;
									}
								}
								
							} else if (gamemode_played == Race) {
								Index_Wert += (n-2-j);
								
								if (j>=n-3){
									Index_Wert = 1;
								}
								
							} else if (gamemode_played == Fight) {
								if (geben == 2) {
									if ((Field[0][i+1][j] != 1)&&(Field[0][i][j+1] != 1)&&(Field[0][i][j-1] != 1)&&(Field[0][i-1][j] != 1)) {
										Index_Wert += 10;
									}
								} else if (geben == 1) {
									if ((Field[0][i+1][j] != 2)&&(Field[0][i][j+1] != 2)&&(Field[0][i][j-1] != 2)&&(Field[0][i-1][j] != 2)) {
										Index_Wert += 10;
									}
								}
							} else if (gamemode_played == Fall) {
								if (geben == 2) {
									if ((Field[0][i-1][j]==7)||(Field[0][i][j+1]==7)||(Field[0][i+1][j]==7)){
										Index_Wert = 1;		//fehlerhaft!
									}
								} else if (geben == 1) {
									if ((Field[0][i-1][j]==7)||(Field[0][i][j-1]==7)||(Field[0][i+1][j]==7)){
										Index_Wert = 1;
									}
								}
								
							} else if (gamemode_played == Collect) {
								if ((i >= (m-3)/2)&&(i <= (m+1)/2)){
									Index_Wert = 2;
								}
								
								if ((Field[0][i-1][j]==7)||(Field[0][i+1][j]==7)||(Field[0][i][j-1]==7)||(Field[0][i][j+1]==7)){
									Index_Wert = 1;
								}
								
							} else if (gamemode_played == Classic) {
								if (geben == 2) {
									if (i == 1){
										Index_Wert = 1;
									}
								} else if (geben == 1) {
									if (i == (m-2)){
										Index_Wert = 1;
									}
								}
							} else if (gamemode_played == Sand) {
								Index_Wert += i;
							}
							
							set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Index_Feld, 0, i, j, Index_Wert);
							Index_Wert = 0;
						}
					}
				}
			} else if (ind == 2) {
				a = 0;
				
				for (unsigned int i=1; i<m-1; i+=1){
					for (unsigned int j=1; j<n-1; j+=1){
						if (Sf_nl_[geben][i][j] == geben){
							
							if (gamemode_played == Dynamic) {
								set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Index_Feld, 0, i, j, abs(i-position[Vertikal])+abs(j-position[Horizontal]));
							} else if (gamemode_played == Arena) {
								for (unsigned int h=i-1; h<=i+1; h+=1){
									for (unsigned int k=j-1; k<=j+1; k+=1){
										if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
											if ((Field[0][h][k] != geben)&&(Field[0][h][k] != 0)) {
												Index_Wert += 1;
											} else if (Field[0][h][k] == geben) {
												a += 1;
											}
										}
									}
								}
								
								if ((a > d)&&(a <= e+1)) {
									Index_Wert += 1;
								}
								a = 0;
								set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Index_Feld, 0, i, j, 10 - Index_Wert);
								Index_Wert = 0;
								
							} else if (gamemode_played == Hunt) {
								if (j >= heart_j) {
									if (i >= heart_i) {
										Index_Wert = (i-heart_i-heart_j+j);
									} else if (i < heart_i) {
										Index_Wert = (heart_i-i-heart_j+j);
									}
								} else if (j < heart_j) {
									if (i >= heart_i) {
										Index_Wert = (i+heart_j-heart_i-j);
									} else if (i < heart_i) {
										Index_Wert = (heart_i+heart_j-i-j);
									}
								}
								
								set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Index_Feld, 0, i, j, Index_Wert);
								Index_Wert = 0;
								
							} else if (gamemode_played == Contact) {
								
								if (keep == 1) {
									Index_Wert += i;
								} else if (keep == 2) {
									Index_Wert += (m-1)-i;
								} else if (keep == 3) {
									Index_Wert += j;
								} else if (keep == 4) {
									Index_Wert += (n-1)-j;
								}
								
								for (unsigned int h=i-1; h<=i+1; h+=1){
									for (unsigned int k=j-1; k<=j+1; k+=1){
										if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
											if ((Field[0][h][k] != 0)&&(Field[0][h][k] != geben)){
												Index_Wert = 1;
											}
										}
									}
								}
								
								set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Index_Feld, 0, i, j, Index_Wert);
								Index_Wert = 0;
								
							} else if (gamemode_played == Sand) {
								set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Index_Feld, 0, i, j, i);
							}
						}
					}
				}
			}
			
			if (gamemode_played == Hunt) {
				set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, heart_i, heart_j, 11);	//verstecken von heart undone
			}
			
			c = 0;
			for (unsigned int i=1; i<m-1; i+=1){
				if (c == 1){
					break;
				}
				for (unsigned int j=1; j<n-1; j+=1){
					if (Index_Feld[0][i][j] == ober){
						set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Index_Feld, 0, i, j, 0);
						set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Sf_nl_, geben, i, j, 0);
						count_new -= 1;
						if (ind  == 2) {
							if ((gamemode_played == Dynamic)||(gamemode_played == Contact)||((gamemode_played == Hunt)&&(geben == 1))) {
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
			
			c = 0;
															//printf("ent: %u \n", ent); printf("\n");
															//printf("ind: %u \n", ind); printf("\n");
															//printf("count_new: %u \n", count_new); printf("\n");
				
			for (unsigned int t=1; t<m-1; t+=1){
				if (f == 1){
					break;
				}
				for (unsigned int z=1; z<n-1; z+=1){
					if (Sf_nl_[geben][t][z] == geben){
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
					if (Sf_nl_[geben][i][j] == geben){
						if (j >= heart_j) {
							if (i >= heart_i) {
								Index_Wert = (i-heart_i-heart_j+j);
							} else if (i < heart_i) {
								Index_Wert = (heart_i-i-heart_j+j);
							}
						} else if (j < heart_j) {
							if (i >= heart_i) {
								Index_Wert = (i+heart_j-heart_i-j);
							} else if (i < heart_i) {
								Index_Wert = (heart_i+heart_j-i-j);
							}
						}
						
						set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Index_Feld, 0, i, j, Index_Wert);
						Index_Wert = 0;
					}
				}
			}
			
			for (unsigned int i=1; i<m-1; i+=1){
				if (c == 1){
					break;
				}
				for (unsigned int j=1; j<n-1; j+=1){
					if (Index_Feld[0][i][j] == ober){
						set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Index_Feld, 0, i, j, 0);
						set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Sf_nl_, geben, i, j, 0);
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
			
			c = 0;
			for (unsigned int t=1; t<m-1; t+=1){
				if (f == 1){
					break;
				}
				for (unsigned int z=1; z<n-1; z+=1){
					if (Sf_nl_[geben][t][z] >= 1){
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
	
	Spielfeld_Destroy (Index_Feld, m, 0);
	
}

void battle (unsigned int m, unsigned int n, Spielfeld Field, unsigned int geben, Spielfeld Sf_opague, Spielfeld Sf_allocation, unsigned int allocation, unsigned int number_of_players){
	Spielfeld chain, chain_temp;
	unsigned int geben_op, chain_total_1, chain_total_2;
	
	geben_op = (geben%2)+1;
	chain_total_1 = 0;
	chain_total_2 = 0;
	chain = Spielfeld_Create (m, n, 0);
	
	for (unsigned int i=1; i<m-1; i+=1){
		for (unsigned int j=1; j<n-1; j+=1){
			if (Field[0][i][j] == geben){
				chain_temp = Spielfeld_Create (m, n, 0);
				if ((Field[0][i][j+1] == geben_op)&&(chain_temp[0][i][j+1] != geben_op)){
					set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, chain_temp, 0, i, j, geben);
					chain_total_1 = 1;
					chain_total_1 = chain_count (i, j, Field, chain_temp, geben, chain_total_1, geben, Sf_opague, Sf_allocation, allocation, number_of_players);
					
					set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, chain_temp, 0, i, j+1, geben_op);
					chain_total_2 = 1;
					chain_total_2 = chain_count (i, (j+1), Field, chain_temp, geben_op, chain_total_2, geben, Sf_opague, Sf_allocation, allocation, number_of_players);
					
					if (chain_total_1 > chain_total_2){
						for (unsigned int h=1; h<m-1; h+=1){
							for (unsigned int k=1; k<n-1; k+=1){
								if (chain_temp[0][h][k] == geben_op){
									set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, chain, 0, h, k, geben);
								}
							}
						}
					} else if (chain_total_2 > chain_total_1){
						for (unsigned int h=1; h<m-1; h+=1){
							for (unsigned int k=1; k<n-1; k+=1){
								if (chain_temp[0][h][k] == geben){
									set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, chain, 0, h, k, geben_op);
								}
							}
						}
					} else if ((chain_total_1 == chain_total_2)&&(chain_total_1 == 1)){
						chain[0][i][j+1] = geben;
					}
					
				}
				
				if ((Field[0][i][j-1] == geben_op)&&(chain_temp[0][i][j-1] != geben_op)){
					Spielfeld_Destroy (chain_temp, m, 0);
					chain_temp = Spielfeld_Create (m, n, 0);
					
					set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, chain_temp, 0, i, j, geben);
					chain_total_1 = 1;
					chain_total_1 = chain_count (i, j, Field, chain_temp, geben, chain_total_1, geben, Sf_opague, Sf_allocation, allocation, number_of_players);
					
					set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, chain_temp, 0, i, j-1, geben_op);
					chain_total_2 = 1;
					chain_total_2 = chain_count (i, (j-1), Field, chain_temp, geben_op, chain_total_2, geben, Sf_opague, Sf_allocation, allocation, number_of_players);
					
					if (chain_total_1 > chain_total_2){
						for (unsigned int h=1; h<m-1; h+=1){
							for (unsigned int k=1; k<n-1; k+=1){
								if (chain_temp[0][h][k] == geben_op){
									set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, chain, 0, h, k, geben);
								}
							}
						}
					} else if (chain_total_2 > chain_total_1){
						for (unsigned int h=1; h<m-1; h+=1){
							for (unsigned int k=1; k<n-1; k+=1){
								if (chain_temp[0][h][k] == geben){
									set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, chain, 0, h, k, geben_op);
								}
							}
						}
					} else if ((chain_total_1 == chain_total_2)&&(chain_total_1 == 1)){
						chain[0][i][j-1] = geben;
					}
					
				}
				
				if ((Field[0][i+1][j] == geben_op)&&(chain_temp[0][i+1][j] != geben_op)){
					Spielfeld_Destroy (chain_temp, m, 0);
					chain_temp = Spielfeld_Create (m, n, 0);
					
					set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, chain_temp, 0, i, j, geben);
					chain_total_1 = 1;
					chain_total_1 = chain_count (i, j, Field, chain_temp, geben, chain_total_1, geben, Sf_opague, Sf_allocation, allocation, number_of_players);
					
					set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, chain_temp, 0, i+1, j, geben_op);
					chain_total_2 = 1;
					chain_total_2 = chain_count ((i+1), j, Field, chain_temp, geben_op, chain_total_2, geben, Sf_opague, Sf_allocation, allocation, number_of_players);
					
					if (chain_total_1 > chain_total_2){
						for (unsigned int h=1; h<m-1; h+=1){
							for (unsigned int k=1; k<n-1; k+=1){
								if (chain_temp[0][h][k] == geben_op){
									set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, chain, 0, h, k, geben);
								}
							}
						}
					} else if (chain_total_2 > chain_total_1){
						for (unsigned int h=1; h<m-1; h+=1){
							for (unsigned int k=1; k<n-1; k+=1){
								if (chain_temp[0][h][k] == geben){
									set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, chain, 0, h, k, geben_op);
								}
							}
						}
					} else if ((chain_total_1 == chain_total_2)&&(chain_total_1 == 1)){
						set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, chain, 0, i+1, j, geben);
					}
					
				}
				
				if ((Field[0][i-1][j] == geben_op)&&(chain_temp[0][i-1][j] != geben_op)){
					Spielfeld_Destroy (chain_temp, m, 0);
					chain_temp = Spielfeld_Create (m, n, 0);
					
					set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, chain_temp, 0, i, j, geben);
					chain_total_1 = 1;
					chain_total_1 = chain_count (i, j, Field, chain_temp, geben, chain_total_1, geben, Sf_opague, Sf_allocation, allocation, number_of_players);
					
					set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, chain_temp, 0, i-1, j, geben_op);
					chain_total_2 = 1;
					chain_total_2 = chain_count ((i-1), j, Field, chain_temp, geben_op, chain_total_2, geben, Sf_opague, Sf_allocation, allocation, number_of_players);
					
					if (chain_total_1 > chain_total_2){
						for (unsigned int h=1; h<m-1; h+=1){
							for (unsigned int k=1; k<n-1; k+=1){
								if (chain_temp[0][h][k] == geben_op){
									set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, chain, 0, h, k, geben);
								}
							}
						}
					} else if (chain_total_2 > chain_total_1){
						for (unsigned int h=1; h<m-1; h+=1){
							for (unsigned int k=1; k<n-1; k+=1){
								if (chain_temp[0][h][k] == geben){
									set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, chain, 0, h, k, geben_op);
								}
							}
						}
					} else if ((chain_total_1 == chain_total_2)&&(chain_total_1 == 1)){
						set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, chain, 0, i-1, j, geben);
					}
					
				}
				
				Spielfeld_Destroy (chain_temp, m, 0);
				
			}
		}
	}
	
	for (unsigned int i=1; i<m-1; i+=1){
		for (unsigned int j=1; j<n-1; j+=1){	//possible to modify for >2 player
			if (chain[0][i][j] == 1){
				set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j, 1);
			} else if (chain[0][i][j] == 2){
				set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j, 2);
			}
		}
	}
	
	Spielfeld_Destroy (chain, m, 0);
	
}

unsigned int chain_count (unsigned int i, unsigned int j, Spielfeld Field, Spielfeld chain_temp, unsigned int player, unsigned int chain_total, unsigned int geben, Spielfeld Sf_opague, Spielfeld Sf_allocation, unsigned int allocation, unsigned int number_of_players){	//player=geben
	if ((Field[0][i][j+1] == player)&&(chain_temp[0][i][j+1] != player)){
		set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, chain_temp, 0, i, j+1, player);
		chain_total += 1;
		chain_total = chain_count (i, (j+1), Field, chain_temp, player, chain_total, geben, Sf_opague, Sf_allocation, allocation, number_of_players);
	}
	if ((Field[0][i][j-1] == player)&&(chain_temp[0][i][j-1] != player)){
		set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, chain_temp, 0, i, j-1, player);
		chain_total += 1;
		chain_total = chain_count (i, (j-1), Field, chain_temp, player, chain_total, geben, Sf_opague, Sf_allocation, allocation, number_of_players);
	}
	if ((Field[0][i+1][j] == player)&&(chain_temp[0][i+1][j] != player)){
		set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, chain_temp, 0, i+1, j, player);
		chain_total += 1;
		chain_total = chain_count ((i+1), j, Field, chain_temp, player, chain_total, geben, Sf_opague, Sf_allocation, allocation, number_of_players);
	}
	if ((Field[0][i-1][j] == player)&&(chain_temp[0][i-1][j] != player)){
		set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, chain_temp, 0, i-1, j, player);
		chain_total += 1;
		chain_total = chain_count ((i-1), j, Field, chain_temp, player, chain_total, geben, Sf_opague, Sf_allocation, allocation, number_of_players);
	}
	
	return chain_total;
}

unsigned int random_number (unsigned int num_1, unsigned int num_2, unsigned int num_3, unsigned int use_number, unsigned int g, unsigned int* var_, unsigned int* number_){
	unsigned int temp_number, new_number, c, mult, inkre, modu, zusatz;
	
	mult = 7;
	inkre = 5;
	modu = 6;
	zusatz = ((g + var_[1] + var_[2] + number_[3] + number_[4] )%60)%6;
	
	temp_number = (num_1 % 2)+(num_2 % 3)+2*(num_3 % 3);
	
	if (temp_number <= 1){
		c = 1;
	} else if (temp_number >= 6){
		c = 6;
	} else {
		c = temp_number;
	}
	
	new_number = (mult*use_number + inkre + c + zusatz)%modu;
	
	if (new_number == 0){
		new_number = 6;
	}
	
	return new_number;
}

void touch (Spielfeld Field, unsigned int m, unsigned int n, unsigned int geben, Spielfeld Sf_nl_, Spielfeld Sf_allocation, unsigned int allocation, Spielfeld Sf_opague, unsigned int number_of_players){
	unsigned int einmal;
	einmal = 0;
	for (unsigned int i=1; i<m-1; i+=1){
		for (unsigned int j=1; j<n-1; j+=1){
			if (Field[0][i][j] == 7){
				
				//test printf("	#-Block alt:	i=%u ,	j=%u \n ", i, j);
				
				if (geben == 1){
					if (((Sf_nl_[geben][i][j-1] == 1) || (Field[0][i][j-1] == 1))&&(j != (n-2))){
						set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j+1, 7);
						set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j, 0);
					} else if (((Sf_nl_[geben][i+1][j] == 1)  || (Field[0][i+1][j] == 1))&&(i != 1)){
						set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i-1, j, 7);
						set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j, 0);
					} else if (((Sf_nl_[geben][i-1][j] == 1) || (Field[0][i-1][j] == 1))&&(i != (m-2))){
						set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i+1, j, 7);
						set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j, 0);
					} else if (((Sf_nl_[geben][i][j+1] == 1) || (Field[0][i][j+1] == 1))&&(j != 1)){
						set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j-1, 7);
						set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j, 0);
					}
				} else if (geben == 2){
					if (((Sf_nl_[geben][i][j+1] == 2) || (Field[0][i][j+1] == 2))&&(j != 1)){
						set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j-1, 7);
						set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j, 0);
					} else if (((Sf_nl_[geben][i+1][j] == 2) || (Field[0][i+1][j] == 2))&&(i != 1)){
						set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i-1, j, 7);
						set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j, 0);
					} else if (((Sf_nl_[geben][i-1][j] == 2) || (Field[0][i-1][j] == 2))&&(i != (m-2))){
						set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i+1, j, 7);
						set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j, 0);
					} else if (((Sf_nl_[geben][i][j-1] == 2) || (Field[0][i][j-1] == 2))&&(j != (n-2))){
						set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j+1, 7);
						set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j, 0);
					}
				}
				einmal = 1;
				
				//test printf("	#-Block neu:	i=%u ,	j=%u \n ", i, j);
				
				break;
				
			}
			
		}
			if (einmal == 1){
				break;
			}
	}
	einmal = 0;
	
}

void ahead (Spielfeld Field, unsigned int m, unsigned int count_freq, Spielfeld Sf_allocation, unsigned int allocation, Spielfeld Sf_opague, unsigned int number_of_players, unsigned int geben){
	
	for (unsigned int i=1; i<m-1; i+=1){
		for (unsigned int j=1; j<count_freq; j+=1){
			if (Field[0][i][j] == 7){
				set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j, 0);
				set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j+1, 7);
			}
		}
	}
}


void choose_heart (Spielfeld Field, unsigned int m, unsigned int n, unsigned int geben, Spielfeld Sf_opague, Spielfeld Sf_allocation, unsigned int allocation, unsigned int number_of_players){
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
	
	heart_ground (heart_i, heart_j, Field, ground_temp, geben, Sf_opague, Sf_allocation, allocation, number_of_players);
	while ((heart_i_wanted == 0)||(heart_i_wanted >= m-1)||(heart_j_wanted >= n-1)||(heart_i_wanted == 0)) {
		printf(" Choose the next position of your heart-block: \n");
		printf("	\n");
		printf(" Zeile: \n Spalte: \n");
		
		letters_4 = get_unsigned_numeric_input_with_not_more_than_letters_4_for_splitting();
		heart_i_wanted = split_unsigned_numeric_input_with_letters_4 (letters_4, 0);
		heart_j_wanted = split_unsigned_numeric_input_with_letters_4 (letters_4, 1);
		
	}
	
	
	if (Field[0][heart_i_wanted][heart_j_wanted] == 11) {
		Field[0][heart_i_wanted][heart_j_wanted] = 11;
	} else if (ground_temp[0][heart_i_wanted][heart_j_wanted] != 111) {
		printf("	You made a mistake, try again: \n");
		printf("\n");
		choose_heart (Field, m, n, geben, Sf_opague, Sf_allocation, allocation, number_of_players);
	} else if (ground_temp[0][heart_i_wanted][heart_j_wanted] == 111) {
		Field[0][heart_i][heart_j] = 1;
		Field[0][heart_i_wanted][heart_j_wanted] = 11;
	}
	
	Spielfeld_Destroy (ground_temp, m, 0);
}

void heart_ground (unsigned int i, unsigned int j, Spielfeld Field, Spielfeld ground_temp, unsigned int geben, Spielfeld Sf_opague, Spielfeld Sf_allocation, unsigned int allocation, unsigned int number_of_players){
	if ((Field[0][i][j+1] == 1)&&(ground_temp[0][i][j+1] != 111)){
		set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, ground_temp, 0, i, j+1, 111);
		heart_ground (i, (j+1), Field, ground_temp, geben, Sf_opague, Sf_allocation, allocation, number_of_players);
	}
	if ((Field[0][i][j-1] == 1)&&(ground_temp[0][i][j-1] != 111)){
		set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, ground_temp, 0, i, j-1, 111);
		heart_ground (i, (j-1), Field, ground_temp, geben, Sf_opague, Sf_allocation, allocation, number_of_players);
	}
	if ((Field[0][i+1][j] == 1)&&(ground_temp[0][i+1][j] != 111)){
		set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, ground_temp, 0, i+1, j, 111);
		heart_ground ((i+1), j, Field, ground_temp, geben, Sf_opague, Sf_allocation, allocation, number_of_players);
	}
	if ((Field[0][i-1][j] == 1)&&(ground_temp[0][i-1][j] != 111)){
		set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, ground_temp, 0, i-1, j, 111);
		heart_ground ((i-1), j, Field, ground_temp, geben, Sf_opague, Sf_allocation, allocation, number_of_players);
	}
}

void opague_builder (Spielfeld Field, Spielfeld Sf_opague, unsigned int m, unsigned int n, unsigned int geben, unsigned int opague, unsigned int AOP, Spielfeld Sf_allocation, unsigned int allocation, unsigned int number_of_players) {
	unsigned int extra;
	unsigned int* opague_counter; 
	Spielfeld temp;
	
	//printf("opague: %u \n", opague);		//test
	
	extra = 1;	//alle zusätzlichen Werte neben den AOP-Spielerwerten
	opague_counter = unsigned_int_Vektor_Create(1+AOP+extra);
	temp = Spielfeld_Create (m, n, 0);
	
	for (unsigned int p=0; p<=AOP+extra; p+=1) {
		opague_counter[p] = 0;
	}
	
	for (unsigned int i=1; i<m-1; i+=1){
		for (unsigned int j=1; j<n-1; j+=1){
			
			if (opague >= 20) {		//4-Mode-Opague, near-by
			
				if (Field[0][i][j] != 11) {
					if (Field[0][i][j] == geben) {
						set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, temp, 0, i, j, geben);
					} else if ((Field[0][i][j] != 0)) {
						if (Field[0][i][j] == 77) {	//Nur für Objekte=77 bisher , go on
							opague_counter[AOP+1] += 1;
						} else {
							opague_counter[Field[0][i][j]] += 1;
						}
					}
				}
				
				if ((i<(m-2))&&(Field[0][i][j] != 11)) {
					if (Field[0][i][j] == geben) {
						set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, temp, 0, i+1, j, Field[0][i+1][j]);
					} else if ((Field[0][i+1][j] != 11)&&(Field[0][i+1][j] != 0)) {
						if (Field[0][i+1][j] == 77) {
							opague_counter[AOP+1] += 1;
						} else {
							opague_counter[Field[0][i+1][j]] += 1;
						}
					}
				}
				
				if ((i>1)&&(Field[0][i][j] != 11)) {
					if (Field[0][i][j] == geben) {
						set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, temp, 0, i-1, j, Field[0][i-1][j]);
					} else if ((Field[0][i-1][j] != 11)&&(Field[0][i-1][j] != 0)) {
						if (Field[0][i-1][j] == 77) {
							opague_counter[AOP+1] += 1;
						} else {
							opague_counter[Field[0][i-1][j]] += 1;
						}
					}
				}
				
				if ((j>1)&&(Field[0][i][j] != 11)) {
					if (Field[0][i][j] == geben) {
						temp[0][i][j-1] = Field[0][i][j-1];
					} else if ((Field[0][i][j-1] != 11)&&(Field[0][i][j-1] != 0)) {
						if (Field[0][i][j-1] == 77) {
							opague_counter[AOP+1] += 1;
						} else {
							opague_counter[Field[0][i][j-1]] += 1;
						}
					}
				}
				
				if ((j<(n-2))&&(Field[0][i][j] != 11)) {
					if (Field[0][i][j] == geben) {
						temp[0][i][j+1] = Field[0][i][j+1];
					} else if ((Field[0][i][j+1] != 11)&&(Field[0][i][j+1] != 0)) {
						if (Field[0][i][j+1] == 77) {
							opague_counter[AOP+1] += 1;
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
				
				if (opague % 10 == 1) {		//4-Mode-Opague, uneven
					for (unsigned int p=1; p<=AOP+extra; p+=1) {
						if (opague_counter[p] % 2 == 0) {
							opague_counter[p] = 0;
						}
					}	//p=10: 77
					
				} else if (opague % 10 == 2) {		//4-Mode-Opague, even
					for (unsigned int p=1; p<=AOP+extra; p+=1) {
						if (opague_counter[p] % 2 == 1) {
							opague_counter[p] = 0;
						}
					}	//p=10: 77
					
				}
				
				opague_counter[0] = 0;
				
				for (unsigned int a=1; a<=AOP+extra; a+=1) {
					if (a != geben) {
						if (opague_counter[a] != 0) {
							
							for (unsigned int b=1; b<=AOP+extra; b+=1) {
								if (a != b) {
									if (opague_counter[a] > opague_counter[b]) {	//für b > number_of_players gilt opague_counter[b] = 0;
										opague_counter[0] += 1;
									}
								}
							}
							
							if ((opague_counter[0] == AOP+extra-1)&&(temp[0][i][j] == 0)) {	//bei Gleichstand zweier Objekte bleibt temp[0][i][j] unbesetzt, da die AOP+extra-1 von keinem erreicht wird
								if (a == AOP+1) {
									set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, temp, 0, i, j, 77);
								} else {
									set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, temp, 0, i, j, a);
								}
							}
							
							opague_counter[0] = 0;
						}
					}
				}
				
				for (unsigned int p=0; p<=AOP+extra; p+=1) {
					opague_counter[p] = 0;
				}
				
				
			} else if (opague >= 10) {		//4-Mode-Opague, Surrounding
			
				for (unsigned int h=i-1; h<=i+1; h+=1){
					for (unsigned int k=j-1; k<=j+1; k+=1){
						if ((h>0)&&(h<(m-1))&&(k>0)&&(k<(n-1))){
							if (Field[0][h][k] != 11) {
								
								if (Field[0][i][j] == geben) {
									set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, temp, 0, h, k, Field[0][h][k]);
								} else if ((Field[0][h][k] != 0) && (Field[0][h][k] != 77)) {
									opague_counter[Field[0][h][k]] += 1;
								} else if ((Field[0][h][k] != 0) && (Field[0][h][k] == 77)) {
									opague_counter[AOP+1] += 1;
								}
								
							}
						}
					}
				}
				
				if (opague % 10 == 1) {		//4-Mode-Opague, uneven
					for (unsigned int p=1; p<=AOP+extra; p+=1) {
						if (opague_counter[p] % 2 == 0) {
							opague_counter[p] = 0;
						}
					}	//p=10: 77
				} else if (opague % 10 == 2) {		//4-Mode-Opague, even
					for (unsigned int p=1; p<=AOP+extra; p+=1) {
						if (opague_counter[p] % 2 == 1) {
							opague_counter[p] = 0;
						}
					}	//p=10: 77
				}
				
				opague_counter[0] = 0;
				
				for (unsigned int a=1; a<=AOP+extra; a+=1) {	//Übertragung auf temp
					if (a != geben) {
						if (opague_counter[a] != 0) {
							
							for (unsigned int b=1; b<=AOP+extra; b+=1) {
								if (a != b) {
									if (opague_counter[a] > opague_counter[b]) {
										opague_counter[0] += 1;
									}
								}
							}
							
							if ((opague_counter[0] == AOP+extra-1)&&(temp[0][i][j] == 0)) {
								if (a == AOP+1) {
									set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, temp, 0, i, j, 77);
								} else if (a == AOP+2) {	//not active yet
									set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, temp, 0, i, j, 77);
								} else {
									set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, temp, 0, i, j, a);
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
				set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, temp, 0, i, j, 11);
			}
		}
	}
	
	for (unsigned int i=1; i<m-1; i+=1){
		for (unsigned int j=1; j<n-1; j+=1){
			set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Sf_opague, 0, i, j, temp[0][i][j]);
		}
	}
	
	Spielfeld_Destroy (temp, m, 0);
	
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

void impact_y_semi_square (unsigned int m, unsigned int n, unsigned int* position, unsigned int d_wert, unsigned int range, int* dynamic_pointer, Spielfeld Field){
	
	for (unsigned int i=0; i<m-1; i+=1) {	//Berechnung impact y
		for (unsigned int j=0; j<n-1; j+=1) {
			if ((Field[0][i][j] != 0)&&(Field[0][i][j] != 77)) {
				if ((abs(position[Vertikal]-i)+abs(position[Horizontal]-j))<=(abs(range)+1)) {	//Manhatten-Norm
					if ((position[Vertikal]-i) != 0) {
						dynamic_pointer[7] += (sgn(position[Vertikal]-i))*(d_wert*(range+1-abs(position[Vertikal]-i))*(range+1-abs(position[Vertikal]-i)) +1);
					}
					if ((position[Horizontal]-j) != 0) {
						dynamic_pointer[6] += (sgn(position[Horizontal]-j))*(d_wert*(range+1-abs(position[Horizontal]-j))*(range+1-abs(position[Horizontal]-j)) +1);
					}
				}
			}
		}
	}
	
}

void show_whose_turn (unsigned int gamemode_played, unsigned int geben, unsigned int* ability, unsigned int* Colored) {
	
	if (Colored[0] == 1) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+Colored[geben]);
	}
	
	if ((gamemode_played != Hunt)&&(gamemode_played != Arena)&&(gamemode_played != Ulcer)&&(gamemode_played != Dynamic)&&(gamemode_played != Survive)&&(gamemode_played != Sand)){	//10
		if (geben == 1) {
			printf("	Am Zug: Spieler %u (**)	\n", geben);
		} else if (geben == 2) {
			printf("	Am Zug: Spieler %u (OO)	\n", geben);
		}
	} else if (gamemode_played == Hunt) {
		if (geben == 1) {
			printf("	Am Zug: Spieler %u (##)	\n", geben);
		} else if (geben == 2) {
			printf("	Am Zug: Spieler %u (AA)	\n", geben);
		} else if (geben == 3) {
			printf("	Am Zug: Spieler %u (BB)	\n", geben);
		} else if (geben == 4) {
			printf("	Am Zug: Spieler %u (CC)	\n", geben);
		} else if (geben == 5) {
			printf("	Am Zug: Spieler %u (DD)	\n", geben);
		} else if (geben == 6) {
			printf("	Am Zug: Spieler %u (EE)	\n", geben);
		} else if (geben == 7) {
			printf("	Am Zug: Spieler %u (FF)	\n", geben);
		} else if (geben == 8) {
			printf("	Am Zug: Spieler %u (GG)	\n", geben);
		} else if (geben == 9) {
			printf("	Am Zug: Spieler %u (HH)	\n", geben);
		}
	} else if (gamemode_played == Arena) {
		if (ability[1] == geben) {
			printf("	Am Zug: Spieler %u (UU)	\n", geben);
		} else if (ability[2] == geben) {
			printf("	Am Zug: Spieler %u (LL)	\n", geben);
		} else if (ability[3] == geben) {
			printf("	Am Zug: Spieler %u (AA)	\n", geben);
		} else if (ability[4] == geben) {
			printf("	Am Zug: Spieler %u (CC)	\n", geben);
		} else if (ability[5] == geben) {
			printf("	Am Zug: Spieler %u (II)	\n", geben);
		} else if (ability[6] == geben) {
			printf("	Am Zug: Spieler %u (SS)	\n", geben);
		} else if (ability[7] == geben) {
			printf("	Am Zug: Spieler %u (PP)	\n", geben);
		} else if (ability[8] == geben) {
			printf("	Am Zug: Spieler %u (HH)	\n", geben);
		} else if (ability[9] == geben) {
			printf("	Am Zug: Spieler %u (EE)	\n", geben);
		}
	} else if ((gamemode_played == Ulcer)||(gamemode_played == Dynamic)||(gamemode_played == Survive)||(gamemode_played == Sand)) {	//10
		printf("	Am Zug: Spieler %u (%u%u)	\n", geben, geben, geben);
	}
	
	if (Colored[0] == 1) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+7);
	}
	
	printf("\n");
	
}

void show_statistics (unsigned int number_of_players, unsigned int gamemode_played, Spielfeld numbers_of_, unsigned int* Points, unsigned int exclude_counter, unsigned int* ulcer_lifes, unsigned int* ges, unsigned int* pere, unsigned int* ability, unsigned int ttt) {

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
			printf("	Matchballs player %u: 	%u \n", p, numbers_of_[p][0][0]);
		}
	} else if (gamemode_played == Collect) {
		for (unsigned int p=1; p<=number_of_players; p+=1) {
			printf("	Squares collected by player %u: 	%u \n", p, numbers_of_[p][0][0]);
		}
	} else if (gamemode_played == Contact) {
		for (unsigned int p=1; p<=number_of_players; p+=1) {
			printf("	Times with squares <= 5, player %u: 	%u \n", p, numbers_of_[p][0][0]);
		}
	} else if (gamemode_played == Fall) {
		for (unsigned int p=1; p<=number_of_players; p+=1) {
			printf("	Points player %u: 		%u \n", p, Points[p]);
			printf("	Turns with more points player %u: 	%u \n", p, numbers_of_[p][0][0]);
		}
		printf("	Number of not decided #-squares: 	%u \n", Points[0]);
	} else if (gamemode_played == Fight) {
		for (unsigned int p=1; p<=number_of_players; p+=1) {
			printf("	Times with squares < 5, player %u: 	%u \n", p, numbers_of_[p][0][0]);
		}
	} else if (gamemode_played == Arena) {
		printf("	Number of excluded abilites: 	%u \n", exclude_counter);
		printf("	Offensive abilities taken: 	%u \n", number_of_players-ability[0]);
		printf("	Defensive abilities taken: 	%u \n", ability[0]);
	} else if (gamemode_played == Ulcer) {	//10
		for (unsigned int p=1; p<=number_of_players; p+=1) {
			if ((ges[p] < 1000)&&(ges[p] != 0)) {
				printf("		Spieler %u: %u life(s) left.\n", p, ulcer_lifes[p]);
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
	}
	printf("\n");
	if (ttt != 0) {
		printf("	Number of penalties given until now: %u \n", pere[0]);
	}
	printf("\n");
	
}

void show_options_of_actions (unsigned int gamemode_played, unsigned int* information_code, unsigned int geben) {
	
	printf("	1) Plus:	11	Minus:	12 \n");
	printf("	2) Move:	21	Change:	22 \n");
	printf("	3) Destroy:	31	Revive:	32 \n");
	printf("	4) Move:	41	Boost:	42 \n");
	if (((gamemode_played != Arena)&&(gamemode_played != Ulcer))||((gamemode_played == Ulcer)&&(geben == 1))) {	//10
		printf("	5) 4/5-new:	51	2-new:	52 \n");
		printf("	6) 4-max:	61	1-min:	62 \n");
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
			printf("	5) 4/5-new:	51	2-new:	52 \n");
			printf("	6) 4-max:	61	1-min:	62 \n");
		}
	} else if ((gamemode_played == Ulcer)&&(geben != 1)) {	//10
		printf("	5) 3/4-new:	51	1-new:	52 \n");
		printf("	6) 3-max:	61	0-min:	62 \n");
	}
	printf("							\n");
	printf("		Go back: 100 \n");
	printf("		Menu: 10 \n");
	printf("		End game: 0 \n");
	
}

void About_the_game (unsigned int gamemode_played, unsigned int geben, unsigned int limit_at_all, unsigned int limit_new, unsigned int number_of_players, unsigned int freq, unsigned int w, unsigned int d, unsigned int e) {
	
	if (gamemode_played == Classic) {
		printf("	How to win? 	Own a square on your last line or force your opponent to lose all his/her ones.\n");
	} else if (gamemode_played == Collect) {
		printf("	How to win? 	Be at 2 of the 3 targets with three of your squares near-by.\n");
	} else if (gamemode_played == Contact) {
		printf("	How to win? 	Take over all your opponent's squares by winning Contact-battles.\n");
		printf("	Contact-battles? 	All near-by squares in a row with the Contact-square build a chain, beat your opponent in the length.\n");
	} else if (gamemode_played == Fall) {
		printf("	How to win? 	Get more points than your opponent.\n");
		printf("	Note:	Touch the #-square in the near-by to move it to the opposite side. \n");
	} else if (gamemode_played == Fight) {
		printf("	How to win? 	Force your opponent to lose all his/her squares.\n");
	} else if (gamemode_played == Hunt) {
		if (geben == 1) {
			printf("	How to win? 	Protect your heart-block so no enemy can touch it.\n");
		} else {
			printf("	How to win? 	Catch the heart-block of the hunted one before it disappears.\n");
		}
	} else if (gamemode_played == Race) {
		printf("	How to win? 	Reach the end of the field or force your opponent to lose all his/her ones.\n");
		printf("	Note:	Every %u turns in total the #-line will go ahead and destroys everything in it's way.\n Also you are not allowed to cross the mid-line. \n", freq);
	} else if (gamemode_played == Rain) {
		printf("	How to win? 	Reach [1][7] of the field or force your opponent to lose all his/her squares.\n");
		printf("	Note:	Falling down the #-squares will push, destroy, explode, or teleport, transform into yours by Contact. \n");
	} else if ((gamemode_played == Arena)||(gamemode_played == Ulcer)) {	//10
		printf("	How to win? 	Force your opponent to lose all his/her squares while keeping yours alive.\n");
	} else if (gamemode_played == Dynamic) {
		printf("	How to win? 	Push the ball against your opponent's side.\n");
	} else if (gamemode_played == Survive) {
		printf("	How to win? 	Stay alive.\n");
	} else if (gamemode_played == Sand) {
		printf("	How to win? 	Reach the top.\n");
	}
	printf("	Surrounding:	The 8 squares around another, at the edge 5, in the corners 3, are called #surrounding. \n");
	printf("	near-by:	The 4 squares around another, at the edge 3, in the corners 2, are called #near-by. \n");
	printf("	Standard actions:	(After your choice of number and not influencing each other) \n	-Development:	If it is your turn and a free square has exactly %u of yours surrounding it, you will own it.\n", w);
	printf("	-Losses: 	If it is your turn and a square of yours is surrounded by less than %u or more than %u of yours,\n			it will be set free.\n", d, e);	//10
	if ((gamemode_played == Hunt)&&(geben == 1)) {	//If geben == 1
		printf("	Limits: 	Your development is limited by %u per round, your units in total by %u per round. \n", (limit_new+(number_of_players-3)), (limit_at_all+(2*(number_of_players-3))));
	} else if ((gamemode_played == Ulcer)||(gamemode_played == Survive)) {
		printf("	Limits: 	This gamemode_played is unlimited. \n");
	} else if (gamemode_played == Contact) {
		printf("	Limits: 	Your development is limited by %u per round. \n", limit_new);
	} else if ((gamemode_played != Hunt)||(geben != 1)) {
		printf("	Limits: 	Your development is limited by %u per round, your units in total by %u per round. \n", limit_new, limit_at_all);
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

void get_hints (Spielfeld Sf_permutations, unsigned int gamemode_played, Spielfeld Field, unsigned int geben, unsigned int w, unsigned int d, unsigned int e, unsigned int m, unsigned int n, unsigned int* information_code, Spielfeld Sf_opague, unsigned int opague, unsigned int* Colored, unsigned int AOP, Spielfeld Sf_allocation, unsigned int allocation, unsigned int number_of_players) {
	
	Spielfeld hint;
	unsigned int b, a, menuoperator;
	hint = Spielfeld_Create (m, n, 0);
	
	b = 0;
	a = 0;
	menuoperator = 0;
	
	for (unsigned int i=1; i<(m-1); i+=1){
		for (unsigned int j=1; j<(n-1); j+=1){
			if ((gamemode_played != Hunt)&&(gamemode_played != Arena)&&(gamemode_played != Ulcer)&&(gamemode_played != Dynamic)&&(gamemode_played != Survive)&&(gamemode_played != Sand)) {	//mehr-gamemode_played
				if (Field[0][i][j] == geben){
					set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, hint, 0, i, j, geben);
				} else if (Field[0][i][j] == (geben%2)+1){
					set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, hint, 0, i, j, (geben%2)+1);
				} else if (Field[0][i][j] == 7){
					set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, hint, 0, i, j, 7);
				}
			} else if ((gamemode_played == Hunt)||(gamemode_played == Arena)||(gamemode_played == Ulcer)||(gamemode_played == Sand)) {	//10
				if (Field[0][i][j] == geben){
					set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, hint, 0, i, j, geben);
				} else if (Field[0][i][j] != 0){
					set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, hint, 0, i, j, 17);
				}
			} else if (gamemode_played == Dynamic) {
				if (Field[0][i][j] == geben){
					set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, hint, 0, i, j, geben);
				} else if (Field[0][i][j] == 77){
					set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, hint, 0, i, j, 77);
				} else if (Field[0][i][j] != 0){
					set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, hint, 0, i, j, 17);
				}
			} else if (gamemode_played == Survive) {
				if (Field[0][i][j] == geben){
					set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, hint, 0, i, j, geben);
				} else if (Field[0][i][j] == Bomb_1){
					set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, hint, 0, i, j, Bomb_1);
				} else if (Field[0][i][j] == Bomb_2){
					set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, hint, 0, i, j, Bomb_2);
				} else if (Field[0][i][j] == Bomb_3){
					set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, hint, 0, i, j, Bomb_3);
				} else if (Field[0][i][j] == Bomb_4){
					set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, hint, 0, i, j, Bomb_4);
				} else if (Field[0][i][j] == Waves){
					set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, hint, 0, i, j, Waves);
				} else if (Field[0][i][j] == Traps){
					set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, hint, 0, i, j, Traps);
				} else if (Field[0][i][j] != 0){
					set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, hint, 0, i, j, 17);
				}
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
						set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, hint, 0, i, j, 16);
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
						set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, hint, 0, i, j, 15);
					}
				}
			}
		}
	}
	
	if (opague >= 1) {
		opague_builder (hint, Sf_opague, m, n, geben, opague, AOP, Sf_allocation, allocation, number_of_players);
		show_field (Sf_permutations, Sf_opague, Sf_opague, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
	} else {
		show_field (Sf_permutations, Sf_opague, hint, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
	}
	
	Spielfeld_Destroy (hint, m, 0);
	
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

unsigned int Initialisierung_limit_new (unsigned int gamemode_played) {
	
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
	} else if (gamemode_played == Ulcer) {
		Ausgabe = 8;
	} else {
		Ausgabe = 0;
	}
	
	return Ausgabe;
}

unsigned int Initialisierung_limit_at_all (unsigned int gamemode_played) {
	
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
	} else if (gamemode_played == Ulcer) {
		Ausgabe = 16;
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
	}
	
	return Ausgabe;
}

unsigned int get_m (unsigned int gamemode_played, unsigned int number_of_players, unsigned int AOP) {
	unsigned int m;
	m = 0;
	
	if (gamemode_played == Classic){
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
			m = 11;
		} else {
			m += 2;
		}
	} else if (gamemode_played == Contact) {
		printf(" Zeilen: >=6				(normal: 10) \n");
		m = get_unsigned_numeric_input_with_not_more_than_2_letters ();
		
		if (m<6){
			printf("	You missed the assertion(s) !!! \n");
			printf("\n");
			m = 12;
		} else {
			m += 2;
		}
	} else if (gamemode_played == Fall) {
		printf(" Zeilen: >=3				(normal: 6) \n");
		m = get_unsigned_numeric_input_with_not_more_than_2_letters ();
		
		if (m<3){
			printf("	You missed the assertion(s) !!! \n");
			printf("\n");
			m = 8;
		} else {
			m += 2;
		}
	} else if (gamemode_played == Fight) {
		printf(" Zeilen: >=6				(normal: 6) \n");
		m = get_unsigned_numeric_input_with_not_more_than_2_letters ();
		
		if (m<6){
			printf("	You missed the assertion(s) !!! \n");
			printf("\n");
			m = 8;
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
		printf(" Zeilen: >=7				(normal: 7) \n");
		m = get_unsigned_numeric_input_with_not_more_than_2_letters ();
		
		if (m<7){
			printf("	You missed the assertion(s) !!! \n");
			printf("\n");
			m = 9;
		} else {
			m += 2;
		}
	} else if (gamemode_played == Rain) {
		printf(" Zeilen: >=3				(normal: 6) \n");
		m = get_unsigned_numeric_input_with_not_more_than_2_letters ();
		
		if (m<3){
			printf("	You missed the assertion(s) !!! \n");
			printf("\n");
			m = 8;
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
		for (unsigned int p=1; p<=AOP; p++) {
			if (p == number_of_players) {
				printf(" Zeilen: >=4				(normal: %u) \n", 5+p);
				m = get_unsigned_numeric_input_with_not_more_than_2_letters ();
				
				if (m<4){
					printf("	You missed the assertion(s) !!! \n");
					printf("\n");
					m = 7+p;
				} else {
					m += 2;
				}
				break;
			}
		}
	}
	
	return m;
}

unsigned int get_n (unsigned int gamemode_played, unsigned int number_of_players, unsigned int AOP) {
	unsigned int n;
	n = 0;
	
	if (gamemode_played == Classic){
		printf(" Spalten: >=4, mod2==0				(normal: 6) \n");
		n = get_unsigned_numeric_input_with_not_more_than_2_letters ();
		
		if ((n<4)||(n%2==1)){
			printf("	You missed the assertion(s) !!! \n");
			printf("\n");
			n = 8;
		} else {
			n += 2;
		}
	} else if (gamemode_played == Collect) {
		printf(" Spalten: >=7, mod2==1				(normal: 11) \n");
		n = get_unsigned_numeric_input_with_not_more_than_2_letters ();
		
		if ((n<7)||(n%2==0)){
			printf("	You missed the assertion(s) !!! \n");
			printf("\n");
			n = 13;
		} else {
			n += 2;
		}
	} else if (gamemode_played == Contact) {
		printf(" Spalten: >=4, mod2==0				(normal: 16) \n");
		n = get_unsigned_numeric_input_with_not_more_than_2_letters ();
		
		if ((n<4)||(n%2==1)){
			printf("	You missed the assertion(s) !!! \n");
			printf("\n");
			n = 18;
		} else {
			n += 2;
		}
	} else if (gamemode_played == Fall) {
		printf(" Spalten: >=7, mod2==1				(normal: 11) \n");
		n = get_unsigned_numeric_input_with_not_more_than_2_letters ();
		
		if ((n<7)||(n%2==0)){
			printf("	You missed the assertion(s) !!! \n");
			printf("\n");
			n = 13;
		} else {
			n += 2;
		}
	} else if (gamemode_played == Fight) {
		printf(" Spalten: >=4, mod2==0				(normal: 6) \n");
		n = get_unsigned_numeric_input_with_not_more_than_2_letters ();
		
		if ((n<4)||(n%2==1)){
			printf("	You missed the assertion(s) !!! \n");
			printf("\n");
			n = 8;
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
		printf(" Spalten: >=5, mod2==1				(normal: 19) \n");
		n = get_unsigned_numeric_input_with_not_more_than_2_letters ();
		
		if ((n<5)||(n%2==0)){
			printf("	You missed the assertion(s) !!! \n");
			printf("\n");
			n = 21;
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
			for (unsigned int p=2; p<=AOP; p++) {
				if (p == number_of_players) {
					printf(" Spalten: >=%u				(normal: %u) \n", 3+4*(p-1), 3+4*(p-1));
					n = get_unsigned_numeric_input_with_not_more_than_2_letters ();
					
					if (n<3+4*(p-1)){
						printf("	You missed the assertion(s) !!! \n");
						printf("\n");
						n = 5+4*(p-1);
					} else {
						n += 2;
					}
					break;
				}
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
				
				// printf("parameter: %u 	q: %d \n \n", parameter, q);	//test
				
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

void choose_your_ability (unsigned int number_of_players, unsigned int* ability, unsigned int* Colored) {
	
	unsigned int input;
	input = 0;
	
	for (unsigned int p=1; p<=number_of_players; p+=1) {
		printf(" \n");
		printf(" \n");
		while ((input == 0)||(input > 9)||((ability[input] != 0)&&(ability[input] != p))) {
			if (Colored[0] == 1) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+Colored[p]);
			}
			printf("	Spieler %u, please choose your ability:	\n", p);
			if (Colored[0] == 1) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+7);
			}
			printf(" \n");
			if (ability[1] == 0) {
				printf("	Ultra light: 1 \n");
			}
			if (ability[2] == 0) {
				printf("	Light	   : 2 \n");
			}
			if (ability[3] == 0) {
				printf("	Anti	   : 3 \n");
			}
			if (ability[4] == 0) {
				printf("	Cornered   : 4 \n");
			}
			if (ability[5] == 0) {
				printf("	Inhibitor  : 5 \n");
			}
			if (ability[6] == 0) {
				printf("	Shield	   : 6 \n");
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

void get_colors (unsigned int* Colored, unsigned int gamemode_played, unsigned int number_of_players, unsigned int AOP) {
	
	unsigned int Color_choice[13], input;
	input = 0;
	unsigned_int_array_null_initialisierung (Color_choice, 12);
	
	if ((gamemode_played == Hunt)||(gamemode_played == Arena)||(gamemode_played == Ulcer)||(gamemode_played == Dynamic)||(gamemode_played == Survive)) {
		printf("	This only works if the number of players is correct! \n");
	}
	
	printf("	Going here again will lead to a reset of the chosen colors! \n");
	printf(" \n");
	
	unsigned_int_array_null_initialisierung (Colored, AOP);
	
	for (unsigned int p=1; p<=number_of_players; p+=1) {
		if (input != 14) {
			printf("	Choose your color, Spieler %u . \n", p);
		}
		
		while ((input == 0)||(input > 14)||((Color_choice[input-1] != 0)&&(Color_choice[input-1] != p))) {		//pere[] wird zweckentfremdet, da hier noch nicht in Gebrauch, und jetzt ausgetauscht durch Color_choice
			printf(" \n");
			if (Color_choice[0] == 0) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+15);
				printf("	1) white. \n");
			}
			if (Color_choice[1] == 0) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+7);
				printf("	2) lightgrey. \n");
			}
			if (Color_choice[2] == 0) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+8);
				printf("	3) darkgrey. \n");
			}
			if (Color_choice[3] == 0) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+13);
				printf("	4) lightmagenta. \n");
			}
			if (Color_choice[4] == 0) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+12);
				printf("	5) lightred. \n");
			}
			if (Color_choice[5] == 0) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+4);
				printf("	6) red. \n");
			}
			if (Color_choice[6] == 0) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+11);
				printf("	7) lightcyan. \n");
			}
			if (Color_choice[7] == 0) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+3);
				printf("	8) cyan. \n");
			}
			if (Color_choice[8] == 0) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+9);
				printf("	9) lightblue. \n");
			}
			if (Color_choice[9] == 0) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+1);
				printf("	10) blue. \n");
			}
			if (Color_choice[10] == 0) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+14);
				printf("	11) yellow. \n");
			}
			if (Color_choice[11] == 0) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+10);
				printf("	12) lightgreen. \n");
			}
			if (Color_choice[12] == 0) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+2);
				printf("	13) green. \n");
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+7);
			
			printf(" \n");
			printf(" \n");
			printf("	Back: 14 \n");
			printf(" \n");
			input = get_unsigned_numeric_input_with_not_more_than_2_letters ();
			if ((input != 0)&&(input <= 13)&&(Color_choice[input-1] == 0)) {
				if (input == 1) {
					Colored[p] = 15;	//change 6, brown, back to 7, grey, done	//maybe 6 is white	//now white, 15
					
				} else if (input == 2) {
					Colored[p] = 7;
					
				} else if (input == 3) {
					Colored[p] = 8;
					
				} else if (input == 4) {
					Colored[p] = 13;
					
				} else if (input == 5) {
					Colored[p] = 12;
					
				} else if (input == 6) {
					Colored[p] = 4;
					
				} else if (input == 7) {
					Colored[p] = 11;
					
				} else if (input == 8) {
					Colored[p] = 3;
					
				} else if (input == 9) {
					Colored[p] = 9;
					
				} else if (input == 10) {
					Colored[p] = 1;
					
				} else if (input == 11) {
					Colored[p] = 14;
					
				} else if (input == 12) {
					Colored[p] = 10;
					
				} else if (input == 13) {
					Colored[p] = 2;
					
				}
				
				Color_choice[input-1] = p;
			}
		}
	}
	Colored[0] = 1;
	
	unsigned_int_array_null_initialisierung (Color_choice, 12);
}

unsigned int dynamic_take_out (unsigned int* position, unsigned int number_of_players, Spielfeld Field, unsigned int* ges, unsigned int player_counter, unsigned int m, unsigned int n, Spielfeld Sf_opague, Spielfeld Sf_allocation, unsigned int allocation, unsigned int geben) {
	
	if (position[Horizontal] == 1) {	//links
		if ((number_of_players == 2)||(number_of_players == 3)||(number_of_players == 4)||(number_of_players == 5)) {
			for (unsigned int i=1; i<m-1; i+=1) {
				for (unsigned int j=1; j<n-1; j+=1) {
					if (Field[0][i][j] == 1) {
						set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j, 0);
					}
				}
			}
			if (ges[1] != 1010) {
				printf("	Player 1, you are out \n");
				ges[1] = 1010;
				player_counter += 1;
			}
			
		} else if (number_of_players == 6) {
			for (unsigned int i=1; i<m-1; i+=1) {
				for (unsigned int j=1; j<n-1; j+=1) {
					if ((Field[0][i][j] == 1)||(Field[0][i][j] == 4)) {
						set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j, 0);
					}
				}
			}
			if (ges[1] != 1010) {
				printf("	Player 1, you are out \n");
				ges[1] = 1010;
				player_counter += 1;
			}
			if (ges[4] != 4040) {
				printf("	Player 4, you are out \n");
				ges[4] = 4040;
				player_counter += 1;
			}
			
		} else if ((number_of_players == 7)||(number_of_players == 8)) {
			for (unsigned int i=1; i<m-1; i+=1) {
				for (unsigned int j=1; j<n-1; j+=1) {
					if ((Field[0][i][j] == 1)||(Field[0][i][j] == 5)) {
						set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j, 0);
					}
				}
			}
			if (ges[1] != 1010) {
				printf("	Player 1, you are out \n");
				ges[1] = 1010;
				player_counter += 1;
			}
			if (ges[5] != 5050) {
				printf("	Player 5, you are out \n");
				ges[5] = 5050;
				player_counter += 1;
			}
			
		} else if (number_of_players == 9) {
			for (unsigned int i=1; i<m-1; i+=1) {
				for (unsigned int j=1; j<n-1; j+=1) {
					if ((Field[0][i][j] == 1)||(Field[0][i][j] == 4)||(Field[0][i][j] == 7)) {
						set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j, 0);
					}
				}
			}
			if (ges[1] != 1010) {
				printf("	Player 1, you are out \n");
				ges[1] = 1010;
				player_counter += 1;
			}
			if (ges[4] != 4040) {
				printf("	Player 4, you are out \n");
				ges[4] = 4040;
				player_counter += 1;
			}
			if (ges[7] != 7070) {
				printf("	Player 7, you are out \n");
				ges[7] = 7070;
				player_counter += 1;
			}
		}
		
	} else if (position[Vertikal] == 1) {	//oben
		if ((number_of_players == 3)||(number_of_players == 4)||(number_of_players == 5)||(number_of_players == 7)) {
			for (unsigned int i=1; i<m-1; i+=1) {
				for (unsigned int j=1; j<n-1; j+=1) {
					if (Field[0][i][j] == 2) {
						set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j, 0);
					}
				}
			}
			if (ges[2] != 2020) {
				printf("	Player 2, you are out \n");
				ges[2] = 2020;
				player_counter += 1;
			}
			
		} else if (number_of_players == 6) {
			for (unsigned int i=1; i<m-1; i+=1) {
				for (unsigned int j=1; j<n-1; j+=1) {
					if ((Field[0][i][j] == 2)||(Field[0][i][j] == 5)) {
						set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j, 0);
					}
				}
			}
			
			if (ges[2] != 2020) {
				printf("	Player 2, you are out \n");
				ges[2] = 2020;
				player_counter += 1;
			}
			if (ges[5] != 5050) {
				printf("	Player 5, you are out \n");
				ges[5] = 5050;
				player_counter += 1;
			}
			
		} else if (number_of_players == 8) {
			for (unsigned int i=1; i<m-1; i+=1) {
				for (unsigned int j=1; j<n-1; j+=1) {
					if ((Field[0][i][j] == 2)||(Field[0][i][j] == 6)) {
						set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j, 0);
					}
				}
			}
			
			if (ges[2] != 2020) {
				printf("	Player 2, you are out \n");
				ges[2] = 2020;
				player_counter += 1;
			}
			if (ges[6] != 6060) {
				printf("	Player 6, you are out \n");
				ges[6] = 6060;
				player_counter += 1;
			}
			
		} else if (number_of_players == 9) {
			for (unsigned int i=1; i<m-1; i+=1) {
				for (unsigned int j=1; j<n-1; j+=1) {
					if ((Field[0][i][j] == 2)||(Field[0][i][j] == 5)||(Field[0][i][j] == 8)) {
						set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j, 0);
					}
				}
			}
			if (ges[2] != 2020) {
				printf("	Player 2, you are out \n");
				ges[2] = 2020;
				player_counter += 1;
			}
			if (ges[5] != 5050) {
				printf("	Player 5, you are out \n");
				ges[5] = 5050;
				player_counter += 1;
			}
			if (ges[8] != 8080) {
				printf("	Player 8, you are out \n");
				ges[8] = 8080;
				player_counter += 1;
			}
		}
		
	} else if (position[Horizontal] == n-2) {	//rechts
		if ((number_of_players == 3)||(number_of_players == 4)||(number_of_players == 5)) {
			for (unsigned int i=1; i<m-1; i+=1) {
				for (unsigned int j=1; j<n-1; j+=1) {
					if (Field[0][i][j] == 3) {
						set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j, 0);
					}
				}
			}
			if (ges[3] != 3030) {
				printf("	Player 3, you are out \n");
				ges[3] = 3030;
				player_counter += 1;
			}
			
		} else if ((number_of_players == 6)||(number_of_players == 7)) {
			for (unsigned int i=1; i<m-1; i+=1) {
				for (unsigned int j=1; j<n-1; j+=1) {
					if ((Field[0][i][j] == 3)||(Field[0][i][j] == 6)) {
						set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j, 0);
					}
				}
			}
			
			if (ges[3] != 3030) {
				printf("	Player 3, you are out \n");
				ges[3] = 3030;
				player_counter += 1;
			}
			if (ges[6] != 6060) {
				printf("	Player 6, you are out \n");
				ges[6] = 6060;
				player_counter += 1;
			}
			
		} else if (number_of_players == 8) {
			for (unsigned int i=1; i<m-1; i+=1) {
				for (unsigned int j=1; j<n-1; j+=1) {
					if ((Field[0][i][j] == 3)||(Field[0][i][j] == 7)) {
						set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j, 0);
					}
				}
			}
			if (ges[3] != 3030) {
				printf("	Player 3, you are out \n");
				ges[3] = 3030;
				player_counter += 1;
			}
			if (ges[7] != 7070) {
				printf("	Player 7, you are out \n");
				ges[7] = 7070;
				player_counter += 1;
			}
			
		} else if (number_of_players == 2) {
			for (unsigned int i=1; i<m-1; i+=1) {
				for (unsigned int j=1; j<n-1; j+=1) {
					if (Field[0][i][j] == 2) {
						set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j, 0);
					}
				}
			}
			if (ges[2] != 2020) {
				printf("	Player 2, you are out \n");
				ges[2] = 2020;
				player_counter += 1;
			}
			
		} else if (number_of_players == 9) {
			for (unsigned int i=1; i<m-1; i+=1) {
				for (unsigned int j=1; j<n-1; j+=1) {
					if ((Field[0][i][j] == 3)||(Field[0][i][j] == 6)||(Field[0][i][j] == 9)) {
						set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j, 0);
					}
				}
			}
			if (ges[3] != 3030) {
				printf("	Player 3, you are out \n");
				ges[3] = 3030;
				player_counter += 1;
			}
			if (ges[6] != 6060) {
				printf("	Player 6, you are out \n");
				ges[6] = 6060;
				player_counter += 1;
			}
			if (ges[9] != 9090) {
				printf("	Player 9, you are out \n");
				ges[9] = 9090;
				player_counter += 1;
			}
			
		}
		
	} else if (position[Vertikal] == m-2) {		//unten
		if (number_of_players == 4) {
			for (unsigned int i=1; i<m-1; i+=1) {
				for (unsigned int j=1; j<n-1; j+=1) {
					if (Field[0][i][j] == 4) {
						set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j, 0);
					}
				}
			}
			if (ges[4] != 4040) {
				printf("	Player 4, you are out \n");
				ges[4] = 4040;
				player_counter += 1;
			}
			
		} else if (number_of_players == 5) {
			for (unsigned int i=1; i<m-1; i+=1) {
				for (unsigned int j=1; j<n-1; j+=1) {
					if ((Field[0][i][j] == 4)||(Field[0][i][j] == 5)) {
						set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j, 0);
					}
				}
			}
			if (ges[4] != 4040) {
				printf("	Player 4, you are out \n");
				ges[4] = 4040;
				player_counter += 1;
			}
			if (ges[5] != 5050) {
				printf("	Player 5, you are out \n");
				ges[5] = 5050;
				player_counter += 1;
			}
			
		} else if (number_of_players == 7) {
			for (unsigned int i=1; i<m-1; i+=1) {
				for (unsigned int j=1; j<n-1; j+=1) {
					if ((Field[0][i][j] == 4)||(Field[0][i][j] == 7)) {
						set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j, 0);
					}
				}
			}
			if (ges[4] != 4040) {
				printf("	Player 4, you are out \n");
				ges[4] = 4040;
				player_counter += 1;
			}
			if (ges[7] != 7070) {
				printf("	Player 7, you are out \n");
				ges[7] = 7070;
				player_counter += 1;
			}
			
		} else if (number_of_players == 8) {
			for (unsigned int i=1; i<m-1; i+=1) {
				for (unsigned int j=1; j<n-1; j+=1) {
					if ((Field[0][i][j] == 4)||(Field[0][i][j] == 8)) {
						set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j, 0);
					}
				}
			}
			if (ges[4] != 4040) {
				printf("	Player 4, you are out \n");
				ges[4] = 4040;
				player_counter += 1;
			}
			if (ges[8] != 8080) {
				printf("	Player 8, you are out \n");
				ges[8] = 8080;
				player_counter += 1;
			}
			
		}
	}
	
	return player_counter;
}

unsigned int who_is_out (unsigned int* ges, unsigned int number_of_players, unsigned int player_counter) {
	
	for (unsigned int p=1; p<=number_of_players; p++) {
		if ((ges[p] == 0)&&(number_of_players >= p)) {
			printf("		Spieler %u, you are out. \n", p);
			player_counter += 1;
			ges[p] = 1010*p;
		}
	}
	printf("\n");
	return player_counter;
}

void show_figures () {	//in order of calculation
	
	// if (menuoperator == 1) {
		printf("		Seed:	\n");
		printf("	OOO		OXO	\n");
		printf("	OXO	--->	XOX	\n");
		printf("	OOO		OXO	\n");
		printf("	\n\n");
		
	// } else if (menuoperator == 2) {
		printf("		Grass:	\n");
		printf("	OOO		OXO	\n");
		printf("	OXO		OXO	\n");
		printf("	OXO	--->	OXO	\n");
		printf("	OOO		OOO	\n");
		printf("	\n\n");
		
	// } else if (menuoperator == 3) {
		printf("		Windmill:	\n");
		printf("	OOOO		OOOO		OOOO	\n");
		printf("	OOXO		OXOO		OOXO	\n");
		printf("	OXOO	--->	OOXO	--->	OXOO	\n");
		printf("	OOOO		OOOO		OOOO	\n");
		printf("	\n\n");
		
	// } else if (menuoperator == 4) {
		printf("		Popcorn:	\n");
		printf("	OOOO		OXXO	\n");
		printf("	OXXO		XOOX	\n");
		printf("	OXXO	--->	XOOX	\n");
		printf("	OOOO		OXXO	\n");
		printf("	\n\n");
		
	// } else if (menuoperator == 5) {
		printf("		Shield:	\n");
		printf("	OOOOO		OOOOO	\n");
		printf("	OOXOO		OOXOO	\n");
		printf("	OXOXO	--->	XXOXX	\n");
		printf("	OOOOO		OOOOO	\n");
		printf("	\n\n");
		
	// } else if (menuoperator == 6) {
		printf("		Flower:	\n");
		printf("	OOOOO		OOXOO	\n");
		printf("	OOXOO		OOXOO	\n");
		printf("	OXOXO	--->	XXOXX	\n");
		printf("	OOXOO		OOXOO	\n");
		printf("	OOOOO		OOXOO	\n");
		printf("	\n\n");
		
	// } else if (menuoperator == 7) {
		printf("		Black hole:	\n");
		printf("	OOOOO		OOOOO	\n");
		printf("	OXXXO		OOOOO	\n");
		printf("	OXXXO	--->	OOXOO	\n");
		printf("	OXXXO		OOOOO	\n");
		printf("	OOOOO		OOOOO	\n");
		printf("	\n\n");
		
	// }
}

void figure_check (Spielfeld Field, unsigned int m, unsigned int n, unsigned int number_of_players, unsigned int* Colored, Spielfeld Sf_allocation, unsigned int allocation, Spielfeld Sf_opague, unsigned int geben) {
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
					
					if (Colored[0] == 1) {
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+Colored[Field[0][i+1][j+1]]);
					}
					printf("	Time for a Seed \n\n");
					
					for (unsigned int t=0; t<=2; t++) {
						for (unsigned int z=0; z<=2; z++) {
							if ((t+z)%2 == 1) {
								set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i+t, j+z, Field[0][i+1][j+1]);
							}
						}
					}
					set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i+1, j+1, 0);
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
						if (Colored[0] == 1) {
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+Colored[Field[0][i+1][j+1]]);
						}
						printf("	Time for Grass \n\n");
						
						set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j+1, Field[0][i+1][j+1]);
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
								
								if (Colored[0] == 1) {
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+Colored[Field[0][i+1][j+1]]);
								}
								printf("	Time for a Windmill \n\n");
								
								for (unsigned int t=2; t>=1; t--) {
									for (unsigned int z=2; z>=1; z--) {
										if ((z+t)%2 == 1) {
											set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i+t, j+z, Field[0][i+1][j+1]);
										} else if ((z+t)%2 == 0) {
											set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i+t, j+z, 0);
										}
									}
								}
							} else if (figure_check_counter == 20) {	//Popcorn
								figure_check_counter = 0;
								
								if (Colored[0] == 1) {
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+Colored[Field[0][i+1][j+1]]);
								}
								printf("	Time for Popcorn \n\n");
								
								for (unsigned int t=1; t<=2; t++) {
									set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i+t, j, Field[0][i+1][j+1]);
									set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i+t, j+3, Field[0][i+1][j+1]);
								}
								for (unsigned int z=1; z<=2; z++) {
									set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j+z, Field[0][i+1][j+1]);
									set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i+3, j+z, Field[0][i+1][j+1]);
								}
								for (unsigned int t=2; t>=1; t--) {
									for (unsigned int z=2; z>=1; z--) {
										set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i+t, j+z, 0);
									}
								}
							}
							
						} else if (Field[0][i+1][j+1] == 0) {	//Windmill#1
							
							if ((Field[0][i+1][j+2] != 0)&&(Field[0][i+1][j+2] <= number_of_players)&&(Field[0][i+2][j+1] == Field[0][i+1][j+2])&&(Field[0][i+2][j+2] == 0)) {
								
								if (Colored[0] == 1) {
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+Colored[Field[0][i+1][j+2]]);
								}
								printf("	Time for a Windmill \n\n");
								
								for (unsigned int t=2; t>=1; t--) {
									for (unsigned int z=1; z<=2; z++) {
										if ((z+t)%2 == 0) {
											set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i+t, j+z, Field[0][i+1][j+2]);
										} else if ((z+t)%2 == 1) {
											set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i+t, j+z, 0);
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
									
									if (Colored[0] == 1) {
										SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+Colored[Field[0][i+1][j+2]]);
									}
									printf("	Time for a Shield \n\n");
									
									set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i+2, j, Field[0][i+1][j+2]);
									set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i+2, j+4, Field[0][i+1][j+2]);
									
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
										
										if (Colored[0] == 1) {
											SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+Colored[Field[0][i+1][j+2]]);
										}
										printf("	Time for a Flower \n\n");
										
										set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i+2, j, Field[0][i+1][j+2]);
										set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i+2, j+4, Field[0][i+1][j+2]);
										set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j+2, Field[0][i+1][j+2]);
										set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i+4, j+2, Field[0][i+1][j+2]);
										
									} else if (figure_check_counter == 49) {	//Black hole
										
										if (Colored[0] == 1) {
											SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+Colored[Field[0][i+1][j+1]]);
										}
										printf("	Time for a Black hole \n\n");
										
										for (unsigned int t=1; t<=3; t++) {
											for (unsigned int z=1; z<=3; z++) {
												if ((t != 2)&&(z != 2)) {
													set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i+t, j+z, 0);
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
	if (Colored[0] == 1) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+7);
	}
	
}

void set_Spielfeld_Eintrag (Spielfeld Field, unsigned int geben, Spielfeld Sf_opague, unsigned int gamemode_played, Spielfeld Sf_allocation, unsigned int allocation, unsigned int number_of_players, Spielfeld Spiel, unsigned int first, unsigned int i, unsigned int j, unsigned int Eintrag) {
	
	Spiel[first][i][j] = Eintrag;
	
	if (allocation != 0) {
		if (((Eintrag != 0)&&(Eintrag <= number_of_players))||((gamemode_played == Hunt)&&(Eintrag == 11))) {
			if (Spiel == Sf_opague) {
				if (Eintrag == geben) {
					Sf_allocation[2][i][j] = Sf_allocation[0][i][j];
				} else {
					Sf_allocation[2][i][j] = 1;
				}
			} else if ((Spiel == Field)&&(first == 0)) {
				Sf_allocation[0][i][j] = 1;
			}
		} else {
			if (Spiel == Sf_opague) {
				Sf_allocation[2][i][j] = 0;
			} else if ((Spiel == Field)&&(first == 0)) {
				Sf_allocation[0][i][j] = 0;
			}
		}
	}
}

void set_gleiter_oben_links (unsigned int inverted, Spielfeld Field, unsigned int geben, unsigned int i, unsigned int j) {	//oben das Bein, oben links das Wachstum, zentral aufgetragen
	if (inverted == 0) {
		Field[0][i-1][j]	= geben;
		Field[0][i-1][j+1]	= geben;
		Field[0][i][j]		= geben;
		Field[0][i][j-1]	= geben;
		Field[0][i+1][j+1]	= geben;
	} else if (inverted == 1) {
		Field[0][i-1][j+1]	= geben;
		Field[0][i-1][j-1]	= geben;
		Field[0][i][j]		= geben;
		Field[0][i][j-1]	= geben;
		Field[0][i+1][j-1]	= geben;
		Field[0][i+1][j]	= geben;
	}
}

void set_gleiter_links_oben (unsigned int inverted, Spielfeld Field, unsigned int geben, unsigned int i, unsigned int j) {
	if (inverted == 0) {
		Field[0][i-1][j]	= geben;
		Field[0][i+1][j-1]	= geben;
		Field[0][i][j]		= geben;
		Field[0][i][j-1]	= geben;
		Field[0][i+1][j+1]	= geben;
	} else if (inverted == 1) {
		Field[0][i-1][j]	= geben;
		Field[0][i-1][j+1]	= geben;
		Field[0][i-1][j-1]	= geben;
		Field[0][i][j]		= geben;
		Field[0][i][j+1]	= geben;
		Field[0][i+1][j-1]	= geben;
	}
}

void set_gleiter_oben_rechts (unsigned int inverted, Spielfeld Field, unsigned int geben, unsigned int i, unsigned int j) {
	if (inverted == 0) {
		Field[0][i-1][j]	= geben;
		Field[0][i-1][j-1]	= geben;
		Field[0][i][j]		= geben;
		Field[0][i][j+1]	= geben;
		Field[0][i+1][j-1]	= geben;
	} else if (inverted == 1) {
		Field[0][i-1][j+1]	= geben;
		Field[0][i-1][j-1]	= geben;
		Field[0][i][j]		= geben;
		Field[0][i][j+1]	= geben;
		Field[0][i+1][j+1]	= geben;
		Field[0][i+1][j]	= geben;
	}
}

void set_gleiter_rechts_oben (unsigned int inverted, Spielfeld Field, unsigned int geben, unsigned int i, unsigned int j) {
	if (inverted == 0) {
		Field[0][i-1][j]	= geben;
		Field[0][i+1][j+1]	= geben;
		Field[0][i][j]		= geben;
		Field[0][i][j+1]	= geben;
		Field[0][i+1][j-1]	= geben;
	} else if (inverted == 1) {
		Field[0][i-1][j]	= geben;
		Field[0][i-1][j+1]	= geben;
		Field[0][i-1][j-1]	= geben;
		Field[0][i][j]		= geben;
		Field[0][i][j-1]	= geben;
		Field[0][i+1][j+1]	= geben;
	}
}

void set_gleiter_unten_links (unsigned int inverted, Spielfeld Field, unsigned int geben, unsigned int i, unsigned int j) {
	if (inverted == 0) {
		Field[0][i-1][j+1]	= geben;
		Field[0][i][j-1]	= geben;
		Field[0][i][j]		= geben;
		Field[0][i+1][j]	= geben;
		Field[0][i+1][j+1]	= geben;
	} else if (inverted == 1) {
		Field[0][i-1][j]	= geben;
		Field[0][i-1][j-1]	= geben;
		Field[0][i][j]		= geben;
		Field[0][i][j-1]	= geben;
		Field[0][i+1][j-1]	= geben;
		Field[0][i+1][j+1]	= geben;
	}
}

void set_gleiter_links_unten (unsigned int inverted, Spielfeld Field, unsigned int geben, unsigned int i, unsigned int j) {
	if (inverted == 0) {
		Field[0][i-1][j-1]	= geben;
		Field[0][i-1][j+1]	= geben;
		Field[0][i][j]		= geben;
		Field[0][i][j-1]	= geben;
		Field[0][i+1][j]	= geben;
	} else if (inverted == 1) {
		Field[0][i+1][j]	= geben;
		Field[0][i+1][j+1]	= geben;
		Field[0][i+1][j-1]	= geben;
		Field[0][i][j]		= geben;
		Field[0][i][j+1]	= geben;
		Field[0][i-1][j-1]	= geben;
	}
}

void set_gleiter_unten_rechts (unsigned int inverted, Spielfeld Field, unsigned int geben, unsigned int i, unsigned int j) {
	if (inverted == 0) {
		Field[0][i-1][j-1]	= geben;
		Field[0][i][j+1]	= geben;
		Field[0][i][j]		= geben;
		Field[0][i+1][j-1]	= geben;
		Field[0][i+1][j]	= geben;
	} else if (inverted == 1) {
		Field[0][i-1][j]	= geben;
		Field[0][i-1][j+1]	= geben;
		Field[0][i][j]		= geben;
		Field[0][i][j+1]	= geben;
		Field[0][i+1][j-1]	= geben;
		Field[0][i+1][j+1]	= geben;
	}
}

void set_gleiter_rechts_unten (unsigned int inverted, Spielfeld Field, unsigned int geben, unsigned int i, unsigned int j) {
	if (inverted == 0) {
		Field[0][i-1][j-1]	= geben;
		Field[0][i][j+1]	= geben;
		Field[0][i][j]		= geben;
		Field[0][i-1][j+1]	= geben;
		Field[0][i+1][j]	= geben;
	} else if (inverted == 1) {
		Field[0][i+1][j]	= geben;
		Field[0][i+1][j+1]	= geben;
		Field[0][i+1][j-1]	= geben;
		Field[0][i][j]		= geben;
		Field[0][i][j-1]	= geben;
		Field[0][i-1][j+1]	= geben;
	}
}

void set_triangle_oben_links (unsigned int inverted, Spielfeld Field, unsigned int geben, unsigned int i, unsigned int j) {	//platziert beim Wachstum, in der angegebenen Ecke
	if ((inverted == 0)||(inverted == 1)) {
		Field[0][i][j+1] = geben;
		Field[0][i+1][j] = geben;
		Field[0][i+1][j+1] = geben;
	}
}

void set_triangle_oben_rechts (unsigned int inverted, Spielfeld Field, unsigned int geben, unsigned int i, unsigned int j) {	//platziert beim Wachstum, in der angegebenen Ecke
	if ((inverted == 0)||(inverted == 1)) {
		Field[0][i][j-1] = geben;
		Field[0][i+1][j] = geben;
		Field[0][i+1][j-1] = geben;
	}
}

void set_triangle_unten_rechts (unsigned int inverted, Spielfeld Field, unsigned int geben, unsigned int i, unsigned int j) {	//platziert beim Wachstum, in der angegebenen Ecke
	if ((inverted == 0)||(inverted == 1)) {
		Field[0][i-1][j-1] = geben;
		Field[0][i-1][j] = geben;
		Field[0][i][j-1] = geben;
	}
}

void set_triangle_unten_links (unsigned int inverted, Spielfeld Field, unsigned int geben, unsigned int i, unsigned int j) {	//platziert beim Wachstum, in der angegebenen Ecke
	if ((inverted == 0)||(inverted == 1)) {
		Field[0][i-1][j] = geben;
		Field[0][i-1][j+1] = geben;
		Field[0][i][j+1] = geben;
	}
}

void set_mountain_oben (unsigned int inverted, Spielfeld Field, unsigned int geben, unsigned int i, unsigned int j) {	//platziert beim Schwerpunkt
	if (inverted == 0) {
		Field[0][i][j]	 = geben;
		Field[0][i-1][j] = geben;
		Field[0][i][j-1] = geben;
		Field[0][i][j+1] = geben;
	} else if (inverted == 1) {
		Field[0][i][j]		= geben;
		Field[0][i][j-1]	= geben;
		Field[0][i][j+1]	= geben;
		Field[0][i+2][j-1]	= geben;
		Field[0][i+2][j+1]	= geben;
	}
}

void set_mountain_unten (unsigned int inverted, Spielfeld Field, unsigned int geben, unsigned int i, unsigned int j) {	//platziert beim Schwerpunkt
	if (inverted == 0) {
		Field[0][i][j] = geben;
		Field[0][i+1][j] = geben;
		Field[0][i][j-1] = geben;
		Field[0][i][j+1] = geben;
	} else if (inverted == 1) {
		Field[0][i][j]		= geben;
		Field[0][i][j-1]	= geben;
		Field[0][i][j+1]	= geben;
		Field[0][i-2][j-1]	= geben;
		Field[0][i-2][j+1]	= geben;
	}
}

void set_mountain_rechts (unsigned int inverted, Spielfeld Field, unsigned int geben, unsigned int i, unsigned int j) {	//platziert beim Schwerpunkt
	if (inverted == 0) {
		Field[0][i][j] = geben;
		Field[0][i][j+1] = geben;
		Field[0][i-1][j] = geben;
		Field[0][i+1][j] = geben;
	} else if (inverted == 1) {
		Field[0][i][j] = geben;
		Field[0][i-1][j] = geben;
		Field[0][i+1][j] = geben;
		Field[0][i-1][j-2] = geben;
		Field[0][i+1][j-2] = geben;
	}
}

void set_mountain_links (unsigned int inverted, Spielfeld Field, unsigned int geben, unsigned int i, unsigned int j) {	//platziert beim Schwerpunkt
	if (inverted == 0) {
		Field[0][i][j] = geben;
		Field[0][i][j-1] = geben;
		Field[0][i-1][j] = geben;
		Field[0][i+1][j] = geben;
	} else if (inverted == 1) {
		Field[0][i][j] = geben;
		Field[0][i-1][j] = geben;
		Field[0][i+1][j] = geben;
		Field[0][i-1][j+2] = geben;
		Field[0][i+1][j+2] = geben;
	}
}

void set_edge_oben_links (unsigned int inverted, Spielfeld Field, unsigned int geben, unsigned int i, unsigned int j) {	//platziert beim Schweif
	if ((inverted == 0)||(inverted == 1)) {
		Field[0][i][j] = geben;
		Field[0][i+2][j] = geben;
		Field[0][i+2][j+1] = geben;
		Field[0][i+2][j+2] = geben;
		Field[0][i][j+2] = geben;
		Field[0][i+1][j+2] = geben;
	}
}

void set_edge_oben_rechts (unsigned int inverted, Spielfeld Field, unsigned int geben, unsigned int i, unsigned int j) {	//platziert beim Schweif
	if ((inverted == 0)||(inverted == 1)) {
		Field[0][i][j] = geben;
		Field[0][i+2][j] = geben;
		Field[0][i+2][j-1] = geben;
		Field[0][i+2][j-2] = geben;
		Field[0][i][j-2] = geben;
		Field[0][i+1][j-2] = geben;
	}
}

void set_edge_unten_rechts (unsigned int inverted, Spielfeld Field, unsigned int geben, unsigned int i, unsigned int j) {	//platziert beim Schweif
	if ((inverted == 0)||(inverted == 1)) {
		Field[0][i][j] = geben;
		Field[0][i-2][j] = geben;
		Field[0][i-2][j-1] = geben;
		Field[0][i-2][j-2] = geben;
		Field[0][i][j-2] = geben;
		Field[0][i-1][j-2] = geben;
	}
}

void set_edge_unten_links (unsigned int inverted, Spielfeld Field, unsigned int geben, unsigned int i, unsigned int j) {	//platziert beim Schweif
	if ((inverted == 0)||(inverted == 1)) {
		Field[0][i][j] = geben;
		Field[0][i-2][j] = geben;
		Field[0][i-2][j+1] = geben;
		Field[0][i-2][j+2] = geben;
		Field[0][i][j+2] = geben;
		Field[0][i-1][j+2] = geben;
	}
}

void set_star (unsigned int inverted, Spielfeld Field, unsigned int geben, unsigned int i, unsigned int j) {	//platziert im Zentrum
	if (inverted == 0) {
		Field[0][i][j] = geben;
		Field[0][i-1][j] = geben;
		Field[0][i][j+1] = geben;
		Field[0][i][j-1] = geben;
		Field[0][i+1][j] = geben;
	} else if (inverted == 1) {
		Field[0][i][j] = geben;
		Field[0][i-1][j-1] = geben;
		Field[0][i-1][j+1] = geben;
		Field[0][i+1][j-1] = geben;
		Field[0][i+1][j+1] = geben;
	}
}

void set_net_basic_two_four (unsigned int inverted, Spielfeld Field, unsigned int geben, unsigned int i, unsigned int j) {	//platziert im Zentrum oben links
	if ((inverted == 0)||(inverted == 1)) {
		Field[0][i][j] = geben;
		Field[0][i-1][j-1] = geben;
		Field[0][i][j+1] = geben;
		Field[0][i+1][j] = geben;
		Field[0][i+1][j+1] = geben;
		Field[0][i-1][j+2] = geben;
		Field[0][i+2][j-1] = geben;
		Field[0][i+2][j+2] = geben;
	}
}

void set_f_links_oben (unsigned int inverted, Spielfeld Field, unsigned int geben, unsigned int i, unsigned int j) {	//platziert im Zentrum, links Wachstum, oben Anhängsel
	if (inverted == 0) {
		Field[0][i][j] = geben;
		Field[0][i][j-1] = geben;
		Field[0][i-1][j+1] = geben;
		Field[0][i-1][j] = geben;
		Field[0][i+1][j] = geben;
	} else if (inverted == 1) {
		Field[0][i][j] = geben;
		Field[0][i][j-1] = geben;
		Field[0][i-1][j+1] = geben;
		Field[0][i-1][j] = geben;
		Field[0][i+1][j] = geben;
		Field[0][i-1][j-1] = geben;
	}
}

void set_f_oben_rechts (unsigned int inverted, Spielfeld Field, unsigned int geben, unsigned int i, unsigned int j) {
	if (inverted == 0) {
		Field[0][i][j] = geben;
		Field[0][i][j-1] = geben;
		Field[0][i][j+1] = geben;
		Field[0][i-1][j] = geben;
		Field[0][i+1][j+1] = geben;
	} else if (inverted == 1) {
		Field[0][i][j] = geben;
		Field[0][i][j-1] = geben;
		Field[0][i][j+1] = geben;
		Field[0][i-1][j] = geben;
		Field[0][i+1][j+1] = geben;
		Field[0][i-1][j+1] = geben;
	}
}

void set_f_rechts_unten (unsigned int inverted, Spielfeld Field, unsigned int geben, unsigned int i, unsigned int j) {
	if (inverted == 0) {
		Field[0][i][j] = geben;
		Field[0][i][j+1] = geben;
		Field[0][i-1][j] = geben;
		Field[0][i+1][j] = geben;
		Field[0][i+1][j-1] = geben;
	} else if (inverted == 1) {
		Field[0][i][j] = geben;
		Field[0][i][j+1] = geben;
		Field[0][i-1][j] = geben;
		Field[0][i+1][j] = geben;
		Field[0][i+1][j-1] = geben;
		Field[0][i+1][j+1] = geben;
	}
}

void set_f_oben_links (unsigned int inverted, Spielfeld Field, unsigned int geben, unsigned int i, unsigned int j) {
	if (inverted == 0) {
		Field[0][i][j] = geben;
		Field[0][i][j-1] = geben;
		Field[0][i][j+1] = geben;
		Field[0][i-1][j] = geben;
		Field[0][i+1][j-1] = geben;
	} else if (inverted == 1) {
		Field[0][i][j] = geben;
		Field[0][i][j-1] = geben;
		Field[0][i][j+1] = geben;
		Field[0][i-1][j] = geben;
		Field[0][i+1][j-1] = geben;
		Field[0][i-1][j-1] = geben;
	}
}

void inverted_organism (Spielfeld Sf_permutations, Spielfeld Field, unsigned int geben, Spielfeld Sf_opague, unsigned int gamemode_played, Spielfeld Sf_allocation, unsigned int allocation, unsigned int number_of_players, unsigned int m, unsigned int n, unsigned int* information_code, unsigned int* Colored) {
	unsigned int edges_of_organism[4];	//0=oben, 1=rechts, 2=unten, 3=links
	
	show_field (Sf_permutations, Sf_opague, Field, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
	
	for (unsigned int p=0; p<=3; p++) {
		edges_of_organism[p] = 0;
	}
	
	for (unsigned int i=1; i<=m-2; i++) {
		for (unsigned int j=1; j<=n-2; j++) {
			if (Field[0][i][j] == geben) {
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
			if (Field[0][i][j] == geben) {
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
	
	for (unsigned int i=edges_of_organism[0]; i<=edges_of_organism[2]; i++) {
		for (unsigned int j=edges_of_organism[3]; j<=edges_of_organism[1]; j++) {
			if (Field[0][i][j] == geben) {
				set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j, 0);
			} else if (Field[0][i][j] == 0) {
				set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j, geben);
			}
		}
	}
	
}

void show_abilities (unsigned int* ability) {
	if ((ability[1] == 0)||(ability[1] == 100)) {
		printf("	Ultra light: 1 \n");
	}
	if ((ability[2] == 0)||(ability[2] == 100)) {
		printf("	Light	   : 2 \n");
	}
	if ((ability[3] == 0)||(ability[3] == 100)) {
		printf("	Anti	   : 3 \n");
	}
	if ((ability[4] == 0)||(ability[4] == 100)) {
		printf("	Cornered   : 4 \n");
	}
	if ((ability[5] == 0)||(ability[5] == 100)) {
		printf("	Inhibitor  : 5 \n");
	}
	if ((ability[6] == 0)||(ability[6] == 100)) {
		printf("	Shield	   : 6 \n");
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

void addition_maker (Spielfeld Field, unsigned int m, unsigned int n, unsigned int number_of_players, unsigned int geben, Spielfeld Sf_opague, unsigned int gamemode_played, Spielfeld Sf_allocation, unsigned int allocation, unsigned int* ges) {
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
				set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j, additional_counter);
			}
		}
	}
	
	Spielfeld_Destroy (Field_addition, m, 0);
}

void projection_maker (Spielfeld Field, unsigned int number_of_players, unsigned int geben, Spielfeld Sf_opague, unsigned int gamemode_played, Spielfeld Sf_allocation, unsigned int allocation, unsigned int direction, unsigned int intensity_minimum, unsigned int intensity_loss_per_line_multiplication, unsigned int m, unsigned int n) {
	
	double intensity_counter, intensity_minimum_real, intensity_loss_per_line_multiplication_real;
	double Spielfeld_intensity[number_of_players][m][n];	//enthält die Intensitäten der Spieler, index_verschiebung geben-->Spielfeld_intensity[geben-1]
	unsigned int a;
	
	// printf("projection_maker ok1\n");	//test
	
	a = 0;
	intensity_counter = 1;
	intensity_minimum_real = 1.0*intensity_minimum/100;
	intensity_loss_per_line_multiplication_real = 1.0*intensity_loss_per_line_multiplication/100;
	
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
					set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, i, j, p);
				}
				a = 0;
			}
		}
	}
}

void assassin_maker (Spielfeld Sf_permutations, Spielfeld Field, unsigned int geben, Spielfeld Sf_opague, unsigned int gamemode_played, Spielfeld Sf_allocation, unsigned int allocation, unsigned int number_of_players, unsigned int m, unsigned int n, unsigned int opague, unsigned int AOP, unsigned int* information_code, unsigned int* Colored) {
	unsigned int assassin_counter;
	assassin_counter = 0;
	
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
					
					if (opague >= 1) {
						opague_builder (Field, Sf_opague, m, n, geben, opague, AOP, Sf_allocation, allocation, number_of_players);
						show_field (Sf_permutations, Sf_opague, Sf_opague, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
					} else {
						show_field (Sf_permutations, Sf_opague, Field, m, n, gamemode_played, information_code, geben, Colored, 0, Sf_allocation, allocation);
					}
					
					if (Colored[0] == 1) {
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+Colored[Field[0][i][j]]);
					}
					printf("\n");
					printf("	An Assassin \n");
					printf("\n");
					if (Colored[0] == 1) {
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 0*16+7);
					}
					
					for (unsigned int h=i-1; h<=i+1; h++) {
						for (unsigned int k=j-1; k<=j+1; k++) {
							if ((Field[0][h][k] != Field[0][i][j])&&(Field[0][h][k] <= number_of_players)) {
								set_Spielfeld_Eintrag (Field, geben, Sf_opague, gamemode_played, Sf_allocation, allocation, number_of_players, Field, 0, h, k, 0);
							}
						}
					}
				}
				assassin_counter = 0;
			}
		}
	}
	
}

void get_two_amounts_for_permutations (unsigned int* aopn_b, unsigned int* aopn_c, unsigned int m, unsigned int n, unsigned int permutation_number_b, unsigned int permutation_number_c) {	//permutation_number_b, permutation_number_c are arguments, 0<permutation_number_b<permutation_number_c<10
	unsigned int x, y, a;
	x = m-2;
	y = n-2;
	a = 0;
	
	// printf("get_two_amounts_for_permutations ok.1 \n");	//test
	if ((x*y)%permutation_number_c == 0) {
		*aopn_b = 0;
		*aopn_c = (x*y)/permutation_number_c;
	} else if ((x*y)%permutation_number_b == 0) {
		*aopn_b = (x*y)/permutation_number_b;
		*aopn_c = 0;
	} else {
		*aopn_b = (x*y)/(permutation_number_b+permutation_number_c);
		*aopn_c = (x*y)/(permutation_number_b+permutation_number_c);
		a = (x*y)%(permutation_number_b+permutation_number_c);
	}
	
	// printf("get_two_amounts_for_permutations ok.2 \n");	//test
	
	if (a/permutation_number_c != 0) {
		*aopn_c += a/permutation_number_c;
		a = a % permutation_number_c;
	}
	if (a/permutation_number_b != 0) {
		*aopn_b += a/permutation_number_b;
		a = a % permutation_number_b;
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
		
		Rest[2] = permutation_number_b;
		Rest[1] = permutation_number_c;
		permutation_number_b_factor[2] = 1;
		permutation_number_b_factor[1] = 0;
		permutation_number_c_factor[2] = 0;
		permutation_number_c_factor[1] = 1;
		durchlauf = 2;
		
		// printf("get_two_amounts_for_permutations ok.4 \n");	//test
		
		while ((Rest[1] != 1)&&(Rest[2] != 1)&&(Rest[3] != 1)) {
			
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
				printf("	ggT(%u, %u) != 1 caused a problem \n", permutation_number_b, permutation_number_c);
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
						permutation_number_c_factor[p] += permutation_number_b;
						permutation_number_b_factor[p] -= permutation_number_c;
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
	
	while (*aopn_c > *aopn_b + ((permutation_number_b+permutation_number_c)/2)) {
		*aopn_c -= permutation_number_b;
		*aopn_b += permutation_number_c;
	}
	while (*aopn_b > *aopn_c + ((permutation_number_b+permutation_number_c)/2)) {
		*aopn_b -= permutation_number_c;
		*aopn_c += permutation_number_b;
	}
	
	printf("	aopn_b: %u \n", *aopn_b);	//test
	printf("	aopn_c: %u \n", *aopn_c);	//test
	printf("	permutation_number_b: %u \n", permutation_number_b);	//test
	printf("	permutation_number_c: %u \n", permutation_number_c);	//test
	printf("	x*y: %u \n", x*y);	//test
	printf("	a: %u \n", a);	//test
	
	if (permutation_number_b*(*aopn_b) + permutation_number_c*(*aopn_c) != x*y) {
		printf("	Bir hata var. Miktarlar yanlis. \n");
		*aopn_c = 0;
		*aopn_b = 0;
	}
	
	if (permutation_number_b*(*aopn_b) + permutation_number_c*(*aopn_c) == x*y) {	//test
		printf("	Her sey dogrudur. \n");
	}
}

void translate_permutations_amounts_to_permutations_areas (Spielfeld Sf_permutations, unsigned int m, unsigned int n, unsigned int permutation_number_c, unsigned int permutation_number_b, unsigned int amount_of_permutation_number_c, unsigned int amount_of_permutation_number_b, Spielfeld Collector_of_permutation_number_c_areas, Spielfeld Collector_of_permutation_number_b_areas) {
	
	unsigned int unutma_i, unutma_j, amount_of_permutation_number_c_in_real, amount_of_permutation_number_b_in_real;
	
	unutma_i = 1;
	unutma_j = 0;
	nereye_gitmeliyiz = to_the_right;
	
	amount_of_permutation_number_c_in_real = amount_of_permutation_number_c;
	amount_of_permutation_number_b_in_real = amount_of_permutation_number_b;
	
	// printf("translate_permutations_amounts_to_permutations_areas ok.1\n");
	
	while ((amount_of_permutation_number_c > 0)||(amount_of_permutation_number_b > 0)) {		//the reduction of the amounts only happens intern of this function, because they are copies
		
		// printf("translate_permutations_amounts_to_permutations_areas while ok.2\n");
		
		if (amount_of_permutation_number_c >= amount_of_permutation_number_b) {
			
			// printf("translate_permutations_amounts_to_permutations_areas while ok.2c\n");
			
			for (unsigned int p=1; p<=permutation_number_c; p++) {
				
				// printf("translate_permutations_amounts_to_permutations_areas while ok.3c\n");
				
				if (nereye_gitmeliyiz == to_the_right) {	//if it gets needed, work with continue
					if ((Sf_permutations[0][unutma_i][unutma_j+1] == 0)&&(unutma_j+1 <= n-2)) {
						unutma_j += 1;	//unutma_ already changed, dont forget!
						
						Collector_of_permutation_number_c_areas[(amount_of_permutation_number_c_in_real - amount_of_permutation_number_c)][p-1][Horizontal] = unutma_i;
						Collector_of_permutation_number_c_areas[(amount_of_permutation_number_c_in_real - amount_of_permutation_number_c)][p-1][Vertikal] = unutma_j;
						
						Sf_permutations[0][unutma_i][unutma_j] = ((amount_of_permutation_number_c_in_real - amount_of_permutation_number_c)+(permutation_number_b+permutation_number_c))%100 +1;
					} else {
						nereye_gitmeliyiz = to_the_bottom;
						p -= 1;
					}
				} else if (nereye_gitmeliyiz == to_the_bottom) {
					if ((Sf_permutations[0][unutma_i+1][unutma_j] == 0)&&(unutma_i+1 <= m-2)) {
						unutma_i += 1;	//unutma_ already changed, dont forget!
						
						Collector_of_permutation_number_c_areas[(amount_of_permutation_number_c_in_real - amount_of_permutation_number_c)][p-1][Horizontal] = unutma_i;
						Collector_of_permutation_number_c_areas[(amount_of_permutation_number_c_in_real - amount_of_permutation_number_c)][p-1][Vertikal] = unutma_j;
						
						Sf_permutations[0][unutma_i][unutma_j] = ((amount_of_permutation_number_c_in_real - amount_of_permutation_number_c)+(permutation_number_b+permutation_number_c))%100 +1;
					} else {
						nereye_gitmeliyiz = to_the_left;
						p -= 1;
					}
				} else if (nereye_gitmeliyiz == to_the_left) {
					if ((Sf_permutations[0][unutma_i][unutma_j-1] == 0)&&(unutma_j-1 >= 1)) {
						unutma_j -= 1;	//unutma_ already changed, dont forget!
						
						Collector_of_permutation_number_c_areas[(amount_of_permutation_number_c_in_real - amount_of_permutation_number_c)][p-1][Horizontal] = unutma_i;
						Collector_of_permutation_number_c_areas[(amount_of_permutation_number_c_in_real - amount_of_permutation_number_c)][p-1][Vertikal] = unutma_j;
						
						Sf_permutations[0][unutma_i][unutma_j] = ((amount_of_permutation_number_c_in_real - amount_of_permutation_number_c)+(permutation_number_b+permutation_number_c))%100 +1;
					} else {
						nereye_gitmeliyiz = to_the_top;
						p -= 1;
					}
				} else if (nereye_gitmeliyiz == to_the_top) {
					if ((Sf_permutations[0][unutma_i-1][unutma_j] == 0)&&(unutma_i-1 >= 1)) {
						unutma_i -= 1;	//unutma_ already changed, dont forget!
						
						Collector_of_permutation_number_c_areas[(amount_of_permutation_number_c_in_real - amount_of_permutation_number_c)][p-1][Horizontal] = unutma_i;
						Collector_of_permutation_number_c_areas[(amount_of_permutation_number_c_in_real - amount_of_permutation_number_c)][p-1][Vertikal] = unutma_j;
						
						Sf_permutations[0][unutma_i][unutma_j] = ((amount_of_permutation_number_c_in_real - amount_of_permutation_number_c)+(permutation_number_b+permutation_number_c))%100 +1;
					} else {
						nereye_gitmeliyiz = to_the_right;
						p -= 1;
					}
				}
			}
			amount_of_permutation_number_c -= 1;
			
		} else if (amount_of_permutation_number_b >= amount_of_permutation_number_c) {
			
			// printf("translate_permutations_amounts_to_permutations_areas while ok.2b\n");
			
			for (unsigned int p=1; p<=permutation_number_b; p++) {
				
				// printf("translate_permutations_amounts_to_permutations_areas while ok.3b\n");
				
				if (nereye_gitmeliyiz == to_the_right) {	//if it gets needed, work with continue
					
					// printf("translate_permutations_amounts_to_permutations_areas while ok.4b\n");
					
					if ((Sf_permutations[0][unutma_i][unutma_j+1] == 0)&&(unutma_j+1 <= n-2)) {
						unutma_j += 1;	//unutma_ already changed, dont forget!
						
						// printf("translate_permutations_amounts_to_permutations_areas while ok.5b\n");
						
						Collector_of_permutation_number_b_areas[(amount_of_permutation_number_b_in_real - amount_of_permutation_number_b)][p-1][Horizontal] = unutma_i;
						
						// printf("translate_permutations_amounts_to_permutations_areas while ok.5.1b\n");
						
						Collector_of_permutation_number_b_areas[(amount_of_permutation_number_b_in_real - amount_of_permutation_number_b)][p-1][Vertikal] = unutma_j;
						
						// printf("translate_permutations_amounts_to_permutations_areas while ok.6b\n");
						
						Sf_permutations[0][unutma_i][unutma_j] = (amount_of_permutation_number_b_in_real - amount_of_permutation_number_b)%100 +1;
					} else {
						nereye_gitmeliyiz = to_the_bottom;
						p -= 1;
					}
				} else if (nereye_gitmeliyiz == to_the_bottom) {
					if ((Sf_permutations[0][unutma_i+1][unutma_j] == 0)&&(unutma_i+1 <= m-2)) {
						unutma_i += 1;	//unutma_ already changed, dont forget!
						
						Collector_of_permutation_number_b_areas[(amount_of_permutation_number_b_in_real - amount_of_permutation_number_b)][p-1][Horizontal] = unutma_i;
						Collector_of_permutation_number_b_areas[(amount_of_permutation_number_b_in_real - amount_of_permutation_number_b)][p-1][Vertikal] = unutma_j;
						
						Sf_permutations[0][unutma_i][unutma_j] = (amount_of_permutation_number_b_in_real - amount_of_permutation_number_b)%100 +1;
					} else {
						nereye_gitmeliyiz = to_the_left;
						p -= 1;
					}
				} else if (nereye_gitmeliyiz == to_the_left) {
					if ((Sf_permutations[0][unutma_i][unutma_j-1] == 0)&&(unutma_j-1 >= 1)) {
						unutma_j -= 1;	//unutma_ already changed, dont forget!
						
						Collector_of_permutation_number_b_areas[(amount_of_permutation_number_b_in_real - amount_of_permutation_number_b)][p-1][Horizontal] = unutma_i;
						Collector_of_permutation_number_b_areas[(amount_of_permutation_number_b_in_real - amount_of_permutation_number_b)][p-1][Vertikal] = unutma_j;
						
						Sf_permutations[0][unutma_i][unutma_j] = (amount_of_permutation_number_b_in_real - amount_of_permutation_number_b)%100 +1;
					} else {
						nereye_gitmeliyiz = to_the_top;
						p -= 1;
					}
				} else if (nereye_gitmeliyiz == to_the_top) {
					if ((Sf_permutations[0][unutma_i-1][unutma_j] == 0)&&(unutma_i-1 >= 1)) {
						unutma_i -= 1;	//unutma_ already changed, dont forget!
						
						Collector_of_permutation_number_b_areas[(amount_of_permutation_number_b_in_real - amount_of_permutation_number_b)][p-1][Horizontal] = unutma_i;
						Collector_of_permutation_number_b_areas[(amount_of_permutation_number_b_in_real - amount_of_permutation_number_b)][p-1][Vertikal] = unutma_j;
						
						Sf_permutations[0][unutma_i][unutma_j] = (amount_of_permutation_number_b_in_real - amount_of_permutation_number_b)%100 +1;
					} else {
						nereye_gitmeliyiz = to_the_right;
						p -= 1;
					}
				}
			}
			amount_of_permutation_number_b -= 1;
		}
	}
	
	// printf("translate_permutations_amounts_to_permutations_areas while ok.3\n");
}

// get_sigmas_for_permutation_number_c () {
	
// }

// get_sigmas_for_permutation_number_b () {
	
// }

// void Permutations_permutate_maker () {
	
// }

//Dynamic (gamemode_played)	, done		(just notes following)
//Geschwindigkeit (vertikal, horizontal)
//Beschleunigung (vertikal, horizontal)
//range (distance:0-5 in Manhatten-Norm)	--> distance+1 = difference, normal:2
//impact y=f(x), x distance, in beschleunigung(linear[f(x)=a*(range-x+1); a=1,2,3; x<=range], semi-square[f(x)=a*(range-x)^2 +1; a=1,2,3; x<=range], square[f(x)=a*(range-x+1)^2; a=1,2,3; x<=range]) normal:semi-square, a=1
//Erdanziehung g linear auf Beschleunigung (-g = 0-5)		normal:1
//crash mit Hindernis: Geschwindigkeit, Beschleunigung, Weg entgegengesetzt +1, mit der Bewegung Hindernis um 1 verschieben, Richtung des wegen zwischen vertikal-horizontal ändern
//crash mit solider Formation: (-1)* sofort auf 1.Beschleunigung(oder 2.Geschwindigkeit) statt Berechnung, -(restliche Wegstrecke+2) falls sgn ändert
//Übertragung Beschleunigung-Geschwindigkeit?
//Grundbetrag: vertikal: s=sgn(a)*a^2+v, v+=a, a+=g+y.		horizontal: s=sgn(a)*a^2+v, v+=a, a+=y.
//Feintuning: Betrag von s reduzieren über: 1 Schritt gehen und von |s| abziehen, wenn sgn(v)!=sgn(y-g)!=sgn(a), dann |v|-1 bzw. |a|-1 am Ende, und |y|>|a|: |s|-|y-a| , wenn |s| null erreicht immer aufhören
//Schrittweite = 1, s_ges = Abstand zur Grundlinie; Wenn a oder v =0 --> |a| = |v|, wenn beide null vorzeichenlos
//s=10: 10	10	9	4	6	9	10	10														s=10:	10	10	9	4	8	4	3	3	3	2	3	7	3		
//v= 0:	0	0	-1	-3	-6	-3	-1	0	<--leer	,freier Fall,	1 Hindernis auf Grund-->	v= 0:	0	0	-1	-3	-3	-4	-4	-3	-3	-2	-3	-4	-4		für 1.
//a= 0:	0	-1	-2	-3	3	2	1	0														a= 0:	0	-1	-2	-3	-1	-2	0	-1	0	-1	-3	0	-1
//Nimm 2.Geschwindigkeit
//Write a timeline: Which options and actions happen when and what tey do, according to their time? go on

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
// after number_of_players+1 turns, look at lines (vertikal/horizontal) and project parallel lines to it.
// Loss of intesity per line in percent, requested minimum? 0<L<1 given in per cent.

// labyrinth (gamemode), go on
// try to reach the mid, but there are walls in the center (3 lines from endings are free)
// the walls can move after a period of turns.

// assassin (option), done
// a lonely square will kill all players in his whole surrounding, mentioned by Arne
