/*
 * sokoban.h
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
#include<stdio.h>
#include<stdlib.h>
#include "constantes.h"
#ifndef SOKOBAN_H
#define SOKOBAN_H

//on fait le choix qu'au début d'un niveau
//(c'est à dire qu'il n'y a pas encore eu d'action)
//l'historique est vide  

// création de la structure case
struct une_case {
		char element; // mur,rangement,personnage ...
		struct une_case *suivant;
		struct une_case *precedant;
		// éléments se trouvant autour de la case 
		// struct une_case *haut;
		// struct une_case *gauche;
		// struct une_case *droit;
		// struct une_case *bas;
} une_case; 
// structure pour stocker la position du personnage 
struct personnage {
	int pos_x;
	int pos_y;
};

// création d'une liste doublement chaînée pour l'historique des déplacment(undo/redo) 
typedef struct historique {
	size_t taille;
	struct une_case *debut;
	struct une_case *fin;
}historique; 

//création d'un historique vide 
historique *new_historique(void)
{
    historique *p_new_historique = malloc(sizeof *p_new_historique);
    if (p_new_historique != NULL)
    {
        p_new_historique->taille = 0;  
        p_new_historique->debut = NULL;
        p_new_historique->fin = NULL;
    }
    return p_new_historique;
}

//ajout d'un élément à l'historique(à la fin)
historique *insert_historique (historique *p_historique, char element)
{
    if (p_historique != NULL) /* On vérifie si notre liste a été allouée */
    {
        struct une_case *p_new_case = malloc(sizeof *p_new_case); /* Création d'un nouveau node */
        if (p_new_case != NULL) /* On vérifie si le malloc n'a pas échoué */
        {
            p_new_case->element = element; /* On 'enregistre' notre donnée */
            p_new_case->suivant = NULL; /* On fait pointer suivant vers NULL */
            if (p_historique->fin == NULL) /* Cas où notre liste est vide (pointeur vers fin de liste à  NULL) */
            {
                p_new_case->precedant = NULL; /* On fait pointer p_prev vers NULL */
                p_historique ->debut = p_new_case; /* On fait pointer la tête de liste vers le nouvel élément */
                p_historique->fin = p_new_case; /* On fait pointer la fin de liste vers le nouvel élément */
            }
            else /* Cas où des éléments sont déjà présents dans notre liste */
            {
                p_historique->fin->suivant = p_new_case; /* On relie le dernier élément de la liste vers notre nouvel élément (début du chaînage) */
                p_new_case->precedant = p_historique->fin; /* On fait pointer p_prev vers le dernier élément de la liste */
                p_historique->fin = p_new_case; /* On fait pointer la fin de liste vers notre nouvel élément (fin du chaînage: 3 étapes) */
            }
            p_historique->taille++; /* Incrémentation de la taille de la liste */
        }
    }
    return p_historique; /* on retourne notre nouvelle liste */
}

//suppression d'un élément à la fin de l'historique
historique *supp_fin_historique(historique *p_historique,char element){
if (p_historique !=NULL){
	if (p_historique->fin==p_historique->debut) //l'historique n'a qu'un seul élément	
	{	p_historique=NULL;
	}			}
	else 
	{	
		p_historique->fin=p_historique->fin->precedant;
		p_historique->fin->suivant=NULL;
		p_historique->taille--;
	}	
	


}

//libération d'un historique 
void suppression_historique(historique **p_historique)
{
    if (*p_historique != NULL)
    {
        struct une_case *p_temp = (*p_historique)->debut;
        while (p_temp != NULL)
        {
            struct une_case *p_del = p_temp;
            p_temp = p_temp->suivant;
            free(p_del);
        }
        free(*p_historique), *p_historique = NULL;
    }
}


struct sokoban {
//	int mode;
	struct une_case la_case [N][N];
};
typedef struct sokoban SOKOBAN;




#endif

