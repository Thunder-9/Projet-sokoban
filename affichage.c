/*
 * affichage.c
 * 
 * Copyright 2016 Tristan <tristan@Thunder>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <uvsqgraphics.h>
#include "affichage.h"
#include "constantes.h"
#include "sokoban.h"

// Initialise la fenêtre graphique et le mode d'affichage
void initialiser_affichage() {
	init_graphics(LARG_FENETRE,HAUT_FENETRE);
	affiche_auto_off();
}


// Affiche le contenu d'une case de la grille
void afficher_une_case(SUDOKU S, int x, int y) {
	POINT bg, hd, centre;
	bg.x = x*TAILLE_CASE;      bg.y = y*TAILLE_CASE;
	hd.x = bg.x + TAILLE_CASE; hd.y = bg.y + TAILLE_CASE;
	centre.x = (bg.x+hd.x)/2;     centre.y = (bg.y+hd.y)/2;
	draw_fill_rectangle(bg,hd,COUL_FOND);
	draw_rectangle(bg,hd,COUL_BORD);



// Affiche un bouton
// numero donne le rang du bouton en les comptant à partir de la gauche et à partir de 0
// texte est le texte dans le bouton
// la_selection vaut 1 si c'est le mode actif et 0 sinon
void afficher_un_bouton(int numero, char *texte, int la_selection) {
	// rouge si c'est le bouton actif et noir sinon
	COULEUR coul_texte = la_selection*rouge + (1 - la_selection)*noir;

	POINT bg, hd, centre;
	bg.x = numero*LARG_BOUTON; bg.y = HAUT_FENETRE-HAUT_BOUTON;
	hd.x = bg.x + LARG_BOUTON; hd.y = bg.y + HAUT_BOUTON;
	centre.x = (bg.x+hd.x)/2;  centre.y = (bg.y+hd.y)/2;

	draw_fill_rectangle(bg,hd,COUL_FOND);
	draw_rectangle(bg,hd,COUL_BORD);
	aff_pol_centre(texte,TAILLE_POLICE,centre,coul_texte);
}


// Affiche les 6 boutons
void afficher_les_boutons(SOKOBAN S) {
	// Le 3ème argument vaut 0 ou 1 selon que c'est le mode actif ou non
	afficher_un_bouton(0,"UNDO", S.mode==JOUER);
	afficher_un_bouton(1,"REDO",  S.mode==JOUER);
	afficher_un_bouton(2,"INIT",  S.mode==JOUER);
	afficher_un_bouton(3,"PRECEDANT",S.mode==JOUER);
	afficher_un_bouton(4,"SUIVANT",S.mode==JOUER);
	afficher_un_bouton(5,"QUITTER",S.mode==QUITTER);
}


// Affiche le sokoban
void afficher_sokoban(SOKOBAN S) {
	fill_screen(noir);
	afficher_grille(S);
	afficher_les_boutons(S);
	affiche_all();
}

