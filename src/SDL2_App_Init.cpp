#include "..\SDL2_App.h"

SDL_Window* gWindow = NULL;

//A superficie contida na janela
SDL_Surface* gScreenSurface = NULL;

//A imagem que iremos carregar e mostrar na tela
SDL_Surface* gHelloWorld = NULL;

bool    init(){
        //flag de inicialização
        bool    success = true;

        //Inicializa SDL
        if ( SDL_Init( SDL_INIT_VIDEO) < 0){
		cout << "SDL não conseguiu inicializar! SDL_Error:" << SDL_GetError() << endl;
		success = false;
	}
	else {
		//Cria a janela
		gWindow =  SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if (gWindow == NULL){
			cout << "A Janela não pode ser criada! SDL_Error" << SDL_GetError() << endl;
			success = false;
		}
		else {
		//Pega a janela da superficie
		gScreenSurface = SDL_GetWindowSurface( gWindow );
		}
	}
	return success;
}