#include "mazmorra.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_main.h>

int main(int arc, char **argv){
SDL_Init(SDL_INIT_VIDEO);
SDL_Window* window = SDL_CreateWindow("Ventana de ejemplo",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1200,870,SDL_WINDOW_SHOWN);
SDL_Renderer* renderer = SDL_CreateRenderer(window,-1, SDL_RENDERER_ACCELERATED);

SDL_Event e;
int quit = 0;
while(!quit){
	while(SDL_PollEvent(&e)){
		if(e.type==SDL_QUIT) quit=1;
	}
	SDL_SetRenderDrawColor(renderer,0,0,0,255);
	SDL_RenderClear(renderer);
	//---funciones de dibujo--
	SDL_SetRenderDrawColor(renderer, 255,255,255,SDL_ALPHA_OPAQUE);
        for(int i=0; i<100; i++) {
        	SDL_RenderDrawPoint(renderer, (int)((1200 - 0 + 1.0) * rand() / (RAND_MAX + 1.0)),(int)((870 - 0 + 1.0) * rand() / (RAND_MAX + 1.0)));
    	}
    	
	SDL_Rect rect={10,200,70,10};
	SDL_Rect rect2={0,30,100,50};
	SDL_Rect rect3={300,300,400,200};
	SDL_Rect grupo []= {rect,rect2,rect3};
	//SDL_RenderFillRect(renderer,&rect);
	//SDL_RenderFillRect(renderer,&rect4);
	//SDL_RenderDrawRect(renderer,&rect3);
	//SDL_RenderFillRect(renderer,&rect2);
	SDL_RenderDrawRects(renderer, grupo,3);
	SDL_RenderPresent(renderer);
	SDL_Delay(17);
}
SDL_DestroyRenderer(renderer);
SDL_DestroyWindow(window);
SDL_Quit();

return 0;
}
