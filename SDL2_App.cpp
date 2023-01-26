#include "SDL2_App.h"

int main( int argc,char* args[]){
	//Inicializa o SDL e cria uma janela
	if ( !init() ){
		cout << "Falhou ao inicializar" << endl;
	}
	else{
	//Carrega os arquivos
		if ( !loadMedia() ){
			cout << "Falhou ao carregar os arquivos" << endl;
		}
		else{
			//Aplica a imagem
			SDL_BlitSurface( gHelloWorld,NULL,gScreenSurface,NULL);
			//Atualiza a superficie
			SDL_UpdateWindowSurface( gWindow);
			//Hack para manter a janela aberta
            		SDL_Event e; bool quit = false; while( quit == false ){ while( SDL_PollEvent( &e ) ){ if( e.type == SDL_QUIT ) quit = true; } }
		}
	}
	//Libera os recursos e fecha o SDL
	close();

	return 0;
}