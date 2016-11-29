CFLAGS=-c -g -Wall 

affichage.o: affichage.c affichage.h sokoban.h constantes.h
	gcc $(CFLAGS) `sdl-config --cflags` affichage.c
