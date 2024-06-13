#ifndef POSITION_H
#define POSITION_H
#include <GL/glut.h>

extern GLfloat fundoZeroX, fundoZeroY;
extern GLfloat logoX, logoY, logoWidth, logoHeight;
extern GLfloat fundoPrincipalX, fundoPrincipalY;
extern GLfloat botaoIniciarX, botaoIniciarY, botaoIniciarWidth, botaoIniciarHeight;
extern GLfloat botaoComoJogarX, botaoComoJogarY, botaoComoJogarWidth, botaoComoJogarHeigth;
extern GLfloat botaoSobreJogoX, botaoSobreJogoY, botaoSobreJogoWidth, botaoSobreJogoHeigth;
extern GLfloat botaoSairX, botaoSairY, botaoSairWidth, botaoSairHeigth;
extern GLfloat fundoComoJogarX, fundoComoJogarY;
extern GLfloat botaoVoltarX, botaoVoltarY, botaoVoltarWidth, botaoVoltarHeigth;
extern GLfloat fundoGameplayX, fundoGameplayY;
extern GLfloat fundoPauseX, fundoPauseY;
extern GLfloat botaoMenuX, botaoMenuY, botaoMenuWidth, botaoMenuHeigth;
extern GLfloat fundoGameOverX, fundoGameOverY;

void updatePosition();

#endif