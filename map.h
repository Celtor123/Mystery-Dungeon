#ifndef MAP_H
#define MAP_H
#include <SDL2/SDL.h>
//Declaración de funciones para que todos los archivos las vean
#define ANCHO_MAPA 1200
#define ALTO_MAPA 870
#define MAX_SALAS 4

//Estructura para la forma del mapa
typedef struct{
	SDL_Rect mazmorra;
	int count;
} Rectangulo;
//Estructura para la forma del mapa

typedef struct{
	int x,y,w,h;
} Celda;
typedef struct{
	Celda lista[(MAX_SALAS)];
	int count;
} Mapa;
void pintarSala();
void crearSala();
#endif
