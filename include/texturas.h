#ifndef TEXTURE_H
#define TEXTURE_H
#include <GL/glut.h>

#define NUM_TEXTURES 27

#define LOGO 0
#define FUNDO_TELA_ZERO 1
#define FUNDO_PRINCIPAL 2    
#define BOTAO_INICIAR 3      
#define BOTAO_COMO_JOGAR 4  
#define BOTAO_SOBRE_JOGO 5
#define BOTAO_SAIR_PRINCIPAL 6
#define BOTAO_APRENDER 7
#define FUNDO_COMO_JOGAR 8
#define FUNDO_SOBRE_JOGO 9
#define BOTAO_VOLTAR 10
#define FUNDO_TELA_FASE_DIA 11
#define FUNDO_TELA_FASE_ANOITECER 12
#define FUNDO_PAUSE 13
#define BOTAO_CONTINUAR 14
#define BOTAO_MENU 15
#define TEXTURA_TIRO_1 16
#define TEXTURA_TIRO_2 17
#define FUNDO_TELA_GAMEOVER 18
#define CANHAO 19
#define MOSQUITO 20

#define VIDAS_5 21
#define VIDAS_4 22
#define VIDAS_3 23
#define VIDAS_2 24
#define VIDAS_1 25
#define VIDAS_0 26

void loadTextures(int);
void freeTextures();
void drawImageTexture(int imageId, GLfloat xTexture, GLfloat yTexture, GLfloat wTexture, GLfloat hTexture, GLfloat x, GLfloat y, GLfloat width, GLfloat height);
void drawImage(int imageId, GLfloat x, GLfloat y, GLfloat width, GLfloat height);

#endif
