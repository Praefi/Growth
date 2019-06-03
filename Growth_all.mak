CFLAGES = -std=c99 -pedantic -Wall -Wextra

Growth_all.exe: Growth_all.o 
	gcc $(CFLAGES) -o Growth_all.exe Growth_all.o -lm

Growth_all.o: Growth_all.c Growth_all.h
	gcc $(CFLAGES) -c Growth_all.c