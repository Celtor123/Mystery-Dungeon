#include "map.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_main.h>
#include <time.h>



int main(int arc, char **argv){
srand(time(NULL)); 
Mapa mapa;
mapa.count=0;
int z;
//for(z=0;z<MAX_SALAS+2;z++){
	pintarSala(&mapa);
//}
SDL_Init(SDL_INIT_VIDEO);
SDL_Window* window = SDL_CreateWindow("Ventana de ejemplo",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,ANCHO_MAPA,ALTO_MAPA,SDL_WINDOW_SHOWN);
SDL_Renderer* renderer = SDL_CreateRenderer(window,-1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
if (renderer == NULL) {
    printf("Error al crear renderer: %s\n", SDL_GetError());
    return 1; 
}

SDL_Event e;
int quit = 0;

/*
printf("Count: %d \n",mapa.count);
int i;
for(i=0;i<MAX_SALAS;i++){
	printf("Sala: %d con x: %d \t y: %d\t w: %d\t h:%d\n", i, mapa.lista[i].x, mapa.lista[i].y, mapa.lista[i].w, mapa.lista[i].h);
}*/
while(!quit){
	while(SDL_PollEvent(&e)){
		if(e.type==SDL_QUIT) quit=1;
	}
	
	SDL_SetRenderDrawColor(renderer,0,0,0,255);
	SDL_RenderClear(renderer);
	//---funciones de dibujo--
	SDL_SetRenderDrawColor(renderer, 255,255,255,SDL_ALPHA_OPAQUE);
        /*for(int i=0; i<100; i++) {
        	SDL_RenderDrawPoint(renderer, (int)((1200 - 0 + 1.0) * rand() / (RAND_MAX + 1.0)),(int)((870 - 0 + 1.0) * rand() / (RAND_MAX + 1.0)));
    	}*/
    	
	SDL_Rect rect = {mapa.lista[0].x,mapa.lista[0].y,mapa.lista[0].w,mapa.lista[0].h};
	SDL_Rect rect2 = {mapa.lista[1].x,mapa.lista[1].y,mapa.lista[1].w,mapa.lista[1].h};
	SDL_Rect rect3 = {mapa.lista[2].x,mapa.lista[2].y,mapa.lista[2].w,mapa.lista[2].h};
	SDL_Rect rect4 = {mapa.lista[3].x,mapa.lista[3].y,mapa.lista[3].w,mapa.lista[3].h};
	SDL_Rect grupo []= {rect,rect2,rect3,rect4};
	
	SDL_RenderDrawRects(renderer,grupo,4);
	//SDL_RenderFillRect(renderer,&rect4);
	//SDL_RenderDrawRect(renderer,&rect3);
	//SDL_RenderFillRect(renderer,&rect2);
	//SDL_RenderDrawRects(renderer, grupo,3);
	SDL_RenderPresent(renderer);
	//SDL_Delay(17);
}
SDL_DestroyRenderer(renderer);
SDL_DestroyWindow(window);
SDL_Quit();

return 0;
}
