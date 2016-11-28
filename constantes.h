/*
 * constante.h
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


#ifndef ___CONSTANTES_H
#define ___CONSTANTES_H
// La taille du sudoku
#define N 30

// La valeur pour une case
#define VIDE 0

// Les actions et le mode
#define UNDO 0
#define REDO   1
#define INIT	    2
#define PRECEDANT 3
#define SUIVANT   4
#define QUITTER 5


// Constantes liées à l'affichage
#define TAILLE_CASE 40
#define LARG_BOUTON ((N*TAILLE_CASE)/4)
#define HAUT_BOUTON (TAILLE_CASE)
#define LARG_FENETRE (N*TAILLE_CASE)
#define HAUT_FENETRE (N*TAILLE_CASE + HAUT_BOUTON)
#define TAILLE_POLICE 20

// Les différentes couleurs
#define COUL_BORD tan
#define COUL_FOND antiquewhite
#define COUL_CHIFFRE sienna
#define COUL_CHIFFRE_NON_MODIFIABLE rouge

#endif


