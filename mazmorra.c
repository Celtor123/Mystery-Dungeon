#include "map.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_main.h>
void crearSala(Mapa *mapa){
	if (mapa == NULL) { printf("Mazmorra es NULL\n"); return; }
	int recursivo=0;
	int *r=&recursivo;
	int solapa;
	while(mapa->count<MAX_SALAS){
	//Valor boolean de si se superpone los rectángulos
	Celda celda;
	celda.w=200+(int)((490 - 200 + 1.0) * rand() / (RAND_MAX + 1.0));
	celda.h=200+(int)((490 - 200 + 1.0) * rand() / (RAND_MAX + 1.0));
	celda.x=(int)(((ANCHO_MAPA-(celda.w)) - 0 + 1.0) * rand() / (RAND_MAX + 1.0));
	celda.y=(int)(((ALTO_MAPA-(celda.h)) - 0 + 1.0) * rand() / (RAND_MAX + 1.0));
	
	solapa=0;
	
	
	//Interseccion entre rectangulo añadido y Guardados
	for( int y = 0; y < mapa->count; y++){
		if(
		celda.x < mapa->lista[y].x + mapa->lista[y].w &&
		celda.x + celda.w > mapa->lista[y].x &&
		celda.y < mapa->lista[y].y + mapa->lista[y].h &&
		celda.y + celda.h > mapa->lista[y].y
		)
		{ solapa=1;break;}//El break es para evitar seguir observando otras colisiones
	}
	
	if(solapa){
	(*r)++;
		}else{
		mapa->lista[mapa->count]=celda;
		mapa->count++;
		(*r)=0;
		}	
	if((*r)>30){
		printf("Mapa muy lleno, parando en la sala: %d",mapa->count);
		break;
	}
	
	printf("Rectangulo: %d \tR: %d\n",(mapa->count-1),*r);
	
	}
	
}

