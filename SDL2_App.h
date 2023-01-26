#ifndef _SDL2_APP_H_
#define _SDL2_APP_H_

//Includes das frameworks
#include <iostream>
#include <SDL2\SDL.h>

//Meus Includes
#include "Define.h"
 
using namespace std;

//Inicializa SDL e cria uma janela
bool init();

//Carrega os arquivos
bool loadMedia();

//Libera o arquivos e para o SDL
void close();

//A janela vai ser renderizada aqui
extern SDL_Window* gWindow;

//A superficie contida na janela
extern SDL_Surface* gScreenSurface;

//A imagem que iremos carregar e mostrar na tela
extern SDL_Surface* gHelloWorld;

#endif