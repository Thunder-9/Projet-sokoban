/*
 * niveau.c
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


#include <stdio.h>
#include "constantes.h"
#include "sokoban.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>



void charger_niveau (char* str,int num_niveau){
	int x,y;
	SOKOBAN S; 
	char* tmp;
	FILE* fic = fopen(str , "r");
	if(fic==NULL){
		printf("échec ouverture fichier %s", str);
		exit(EXIT_FAILURE);
	}
	//+cas le fichier ne se termine pas par .xsb
	
	tmp=fgets(fic)
	while (tmp != num_niveau){  //on se place au numéro du niveau voulu
		tmp=fgets(fic) 
		if (tmp == EOF){
			printf("le niveau numéro %d n'a pas été trouvé dans le fichier %s",numero_niveau,str);
			exit(EXIT_FAILURE);
	}}
/* set long position du niveau = long ftell(FILE* pointeurSurFichier);
utiliser la même fonction que wc.c(dans IN301) pour avoir le nb de ligne 
* reset la position à position du niv avec fseek
*écrire une fonction pour avoir la longueur de ligne maximal
* rest la position
* charger le niv case par case
* utiliser des pointeur pour modifier les valeurs nb de ligne et largeur max
* 
* 
* 
* 
* 
* */ 
	
	
	
	fclose(fic); 

}
	

