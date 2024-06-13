#ifndef SCREEN_H
#define SCREEN_H

#include <GL/glut.h>

/* Estados das Telas do Jogo */
#define TELA_INICIAL 0
#define TELA_COMO_JOGAR 1
#define TELA_SOBRE_JOGO 2
#define TELA_GAMEPLAY 3
#define TELA_PAUSE 4
#define TELA_FIM_DE_JOGO 5
#define TELA_GAME_OVER 6


extern int windowWidth, windowHeight, currentScreen;
extern bool isPaused;
extern const GLuint *imageId;

void desenharNovaTela(int novaTela);
void telaZero();
void telaInicial();
void telaComoJogar();
void telaGameplay();
void telaPause();

// Função para reproduzir música
void playSounds(int telaID);

#endif
