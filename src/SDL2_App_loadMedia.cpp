#include "..\SDL2_App.h"

bool loadMedia(){
	//Carrega o flag de sucesso
	bool success = true;

	//Carrega a imagem
	gHelloWorld = SDL_LoadBMP ("res/Leao001.bmp");
	if (gHelloWorld == NULL){
		cout << "Nao foi possivel carregar a imgem! SDL_Error" << SDL_GetError() << endl;
		success = false;
	}
	return success;
}
