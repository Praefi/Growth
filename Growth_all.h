
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
// #define Quidditch_mistake_search

void playing_a_game (unsigned int*, unsigned int*, unsigned int, time_t, unsigned int*, unsigned int, Quidditch_setup*);


void get_hints (unsigned int*, Spielfeld, unsigned int, Spielfeld, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int*, Special_Fields, Growth_Player*, unsigned int, Special_Fields_Collector*, unsigned int, Single_option_representives);	//menu

void About_the_game (unsigned int, unsigned int, Limits, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);	//menu


void Time_for_a_Tutorial (unsigned int, unsigned int*, unsigned int*, unsigned int*, Growth_Player*);
void synchronisation_Test_field (Spielfeld, unsigned int, unsigned int, unsigned int, unsigned int);

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
// (numbers = squares and primes<20)
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

// spreading (option), done
// touching the wall causes a line of owned squares along the wall until there is an other living square or the end.

// Imitation (option), frozen
// Every square of the enemies is shown as own square, except until the distance x from the edge.

// Laser-competition (gamemode), go on
// Two teams against each other: mod2==1 is like elementary waves, mod2==0 as solid, touch all edges/stop the laser.

// Goliath (and David) (gamemode), go on
// it is like throwing stones on pumping stations

// invisible (option), done
// cannot see anything of the enemies

// roses (option), done
// if there are too many in the surrounding and a square dies, a rose is born an can get cleared away trough having the same count of equal squares in its surrounding again.

// Ptunoi (gamemode), frozen
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

// KI for Contact, ... done
// done for: Classic, Collect, Fall, Hunt, Race, Rain, Dynamic, Sand, Contact&Fight&Arena&Survive (ges_copy), 
// Make Yasmin faster, not possible

// KI: Anne, the MOTHER of all KI's. go on
// She is able to be tactical, set traps and know how to play the objective.

// Quidditch (gamemode), done
// Well, just Quidditch.

// Donation (gamemode), go on
// spend squares for your team, counting 1/x if you have x squares in this situation. Spend before or after, but not both except at least one of it is teamless. Team 2 and team 3 neighbours. Fill space with teamless 1 and 0 donations. (Whats about 4+ ?)

// Genimo_ve_flagrate (gamemode), go on
// touching an object will let it evolve like one step of a wave, possible to destroy it accross. Reach the mid. Difficulty handle through number of objects in each quarter.

// partition (option), done
// every square gets a ((number-1)%x)+1, if you get a new square, it gets ((the sum of the evolving squares -1) mod x) +1. Touching a square of the enemy with a lower number than the number of your square, you will own the square of the enemy.

// Supernova (gamemode), frozen
// avoid the blackholes flying accross the field caused by gravity and pulling your squares and so on. Mass of square: 1. Mass of blackholes: 5. Fusion with blackhole(): Mass-Addition. timestep t = 1. Destroy on blackholes: reduce the mass with 1. Count all impacts and use it for new accelaration, add this value to the speed (t=1). After every round a timestep. Sort (binary) the speed according to length (sqrt(x*x+y*y)), most speed at first. Collosion: half of speed-difference plus and minus, after that next square with highest speed.

// Mining (gamemode), go on
// Search for gold, silver and copper on a Kubik, donating squares of yours to dig, played with Allocation.

// Creatures (gamemode), go on
// Be a vampire, werewolf, dwarf, goblin, human, troll, dragon, elf, fairy.

// Circle (gamemode), go on
// reach the mid as a team while the squares are moved in a circle, radial static points.

// labrinth (gamemode), go on
// the field is a labrinth and you can push your squares in a direction at the end of your turn, killing enemies on your way.

// Duell (gamemode), go on
// every player gets cards with abilities, development on enemies is not forbidden anymore.

// envelope (option), go on
// Set a distence of the surrounding, like 1 = normal 8, 2 = bigger 16, ... , i = 8*i for 0<i<max(m, n)

// Spielstände speichern, go on


#endif
