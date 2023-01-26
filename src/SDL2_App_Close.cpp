#include "..\SDL2_App.h"

void close(){

	//Libera a memoria
	SDL_FreeSurface( gHelloWorld );
	gHelloWorld = NULL;

	//Destroi a janela
	SDL_DestroyWindow( gWindow);
	gWindow = NULL;

	//Finaliza o programa
	SDL_Quit();

}