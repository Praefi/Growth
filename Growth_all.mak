CFLAGES = -std=c99 -pedantic -Wall -Wextra

Growth_all.exe: Growth_all.o Growth_all_KI.o Growth_all_Initialisierung.o Growth_all_show.o Growth_all_get.o Growth_all_Development.o Growth_all_actions.o Growth_all_gamemode_specials.o Growth_all_options_specials.o Growth_all_set.o Growth_all_Vektor.o Growth_all_Def.o
	gcc $(CFLAGES) -o Growth_all.exe Growth_all.o Growth_all_KI.o Growth_all_Initialisierung.o Growth_all_show.o Growth_all_get.o Growth_all_Development.o Growth_all_actions.o Growth_all_gamemode_specials.o Growth_all_options_specials.o Growth_all_set.o Growth_all_Vektor.o Growth_all_Def.o -lm

Growth_all.o: Growth_all.c Growth_all.h
	gcc $(CFLAGES) -c Growth_all.c

Growth_all_KI.o: Growth_all_KI.c Growth_all_KI.h
	gcc $(CFLAGES) -c Growth_all_KI.c

Growth_all_Initialisierung.o: Growth_all_Initialisierung.c Growth_all_Initialisierung.h
	gcc $(CFLAGES) -c Growth_all_Initialisierung.c

Growth_all_show.o: Growth_all_show.c Growth_all_show.h
	gcc $(CFLAGES) -c Growth_all_show.c

Growth_all_get.o: Growth_all_get.c Growth_all_get.h
	gcc $(CFLAGES) -c Growth_all_get.c

Growth_all_Development.o: Growth_all_Development.c Growth_all_Development.h
	gcc $(CFLAGES) -c Growth_all_Development.c

Growth_all_actions.o: Growth_all_actions.c Growth_all_actions.h
	gcc $(CFLAGES) -c Growth_all_actions.c

Growth_all_gamemode_specials.o: Growth_all_gamemode_specials.c Growth_all_gamemode_specials.h
	gcc $(CFLAGES) -c Growth_all_gamemode_specials.c

Growth_all_options_specials.o: Growth_all_options_specials.c Growth_all_options_specials.h
	gcc $(CFLAGES) -c Growth_all_options_specials.c

Growth_all_set.o: Growth_all_set.c Growth_all_set.h
	gcc $(CFLAGES) -c Growth_all_set.c

Growth_all_Vektor.o: Growth_all_Vektor.c Growth_all_Vektor.h
	gcc $(CFLAGES) -c Growth_all_Vektor.c

Growth_all_Def.o: Growth_all_Def.c Growth_all_Def.h
	gcc $(CFLAGES) -c Growth_all_Def.c
