#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "read.h"

typedef struct Chaine Chaine;
struct Chaine{
    char c;
    Chaine *suivant;
};

Chaine* new(Chaine *ch, char car);
void liberer(Chaine *ch);
char *chaineToStr(Chaine*ch);



char *read(){
	Chaine *ch= NULL;
	char * retour=NULL;
	char c;

	do{
	 c = getc(stdin);
	 if(c!='\n') ch = new(ch,c); // on enregistre pas le saut de ligne
	}while(c !='\n');

	retour = chaineToStr(ch);
	liberer(ch);
	return retour;
}

char *chaineToStr(Chaine*ch){
	Chaine *it = ch;
	int i =0;
	char *retour = NULL;
	//compter
	//allouer
	//remplir
	while(it!=NULL){
		i++;
		it = it->suivant;
	} 
	i++; //pour le \0
	retour = (char*) malloc(sizeof(char)*i);
	for(i=0;ch!=NULL;i++){
		retour[i] = ch->c;
		ch = ch->suivant;
	} 
	retour[i]='\0';
	return retour;
}

void liberer(Chaine *ch){
	Chaine *it = ch;//on place un marqueur
	it = it->suivant;

	while(it != NULL){
		free(ch);
		ch = it;
		it = it->suivant;
	}

	free(ch); // on supprime le dernier maillon
}

Chaine* new(Chaine *ch, char car){
	Chaine *save; // je positionne un pointeur au début de la liste
	Chaine *sch = NULL;

	if(ch!=NULL){ //on se place
	    save = ch;
		while(ch->suivant != NULL) ch = ch->suivant;
	}

	//on prepare le nouveau bloc
	sch = malloc(sizeof(Chaine));
	sch->suivant = NULL;
	sch->c = car;
	//on attache le tout ensemble de maniere harmonieuse
	
	if(ch!=NULL)
		ch->suivant = sch;
	else
		save = sch;

	return save;
}


