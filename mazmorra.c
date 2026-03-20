#include "map.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_main.h>
void crearSala(Mapa *mapa){
	if (mapa == NULL) { printf("Mazmorra es NULL\n"); return; }
	int recursivo=0;
	int *r=&recursivo;
	if(mapa->count>=MAX_SALAS) return;
	//Celda *new= &mapa->lista[mapa->count];
	int solapa=0;//Valor boolean de si se superpone los rectángulos
	do{
	Celda celda;
	celda.rect.w=200+(int)((490 - 200 + 1.0) * rand() / (RAND_MAX + 1.0));
	celda.rect.h=200+(int)((490 - 200 + 1.0) * rand() / (RAND_MAX + 1.0));
	celda.rect.x=(int)(((ANCHO_MAPA-(celda.rect.w)) - 0 + 1.0) * rand() / (RAND_MAX + 1.0));
	celda.rect.y=(int)(((ALTO_MAPA-(celda.rect.h)) - 0 + 1.0) * rand() / (RAND_MAX + 1.0));
	int y;
	solapa=0;
	//Interseccion entre rectangulo añadido y Guardados
	for( y = 0; y < mapa->count; y++){
		if(SDL_HasIntersection(&celda.rect,&mapa->lista[y].rect)){ solapa=1;break;}
	}
	if((*r)>30){break;}//Evitar bucle infinito
	if(!solapa){
		mapa->lista[mapa->count]=celda;
		printf("count: %d",mapa->count);
		mapa->count++;
		break;
	}	
	++(*r);
	}while(solapa);
	
}

