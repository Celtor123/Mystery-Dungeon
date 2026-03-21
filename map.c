#include "map.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_main.h>
//Funciones epecíficas del mapa
void pintarSala(Mapa *mapa){
if (mapa == NULL) { printf("Mapa es NULL\n"); return; }
	crearSala(mapa);
}

void pintarPasillo(Mapa *mapa){
if (mapa == NULL) { printf("Mapa es NULL\n"); return; }
	/*for(int w=0;w<MAX_SALAS;++w){
		
		celda=mapa.lista[w]
	}*/
}
