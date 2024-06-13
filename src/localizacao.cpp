#include <GL/glut.h>
#include <tela.h>

GLfloat fundoZeroX;
GLfloat fundoZeroY;

GLfloat logoX;  
GLfloat logoY;  
GLfloat logoWidth; 
GLfloat logoHeight;

GLfloat fundoPrincipalX; 
GLfloat fundoPrincipalY; 

GLfloat fundoGameplayX; 
GLfloat fundoGameplayY; 

GLfloat botaoIniciarX; 
GLfloat botaoIniciarY; 
GLfloat botaoIniciarWidth; 
GLfloat botaoIniciarHeight;

GLfloat botaoComoJogarX; 
GLfloat botaoComoJogarY; 
GLfloat botaoComoJogarWidth; 
GLfloat botaoComoJogarHeigth;

GLfloat botaoSobreJogoX;
GLfloat botaoSobreJogoY;
GLfloat botaoSobreJogoWidth;
GLfloat botaoSobreJogoHeigth;

GLfloat botaoSairX; 
GLfloat botaoSairY; 
GLfloat botaoSairWidth; 
GLfloat botaoSairHeigth;

GLfloat fundoComoJogarX; 
GLfloat fundoComoJogarY; 

GLfloat botaoVoltarX; 
GLfloat botaoVoltarY; 
GLfloat botaoVoltarWidth; 
GLfloat botaoVoltarHeigth;

//tESTE PAUSE
GLfloat fundoPauseX;
GLfloat fundoPauseY;

GLfloat fundoGameOverX;
GLfloat fundoGameOverY;

GLfloat botaoMenuX;
GLfloat botaoMenuY;
GLfloat botaoMenuWidth;
GLfloat botaoMenuHeigth;

// Centralizar o objeto em X ou Y
GLfloat centerPosition(GLfloat objSize, GLfloat windowSize) {
    return (windowSize - objSize) / 2;
}

void updatePosition()
{
  
    logoWidth = windowWidth * 0.6; 
    logoHeight = windowHeight * 0.3; 
    logoX = centerPosition(logoWidth, windowWidth); 
    logoY = windowHeight * 0.60; 

   
    botaoIniciarWidth = windowWidth * 0.2; 
    botaoIniciarHeight = windowHeight * 0.1; 
    botaoIniciarX = centerPosition(botaoIniciarWidth, windowWidth); 
    botaoIniciarY = windowHeight * 0.45; // Mover botão de Iniciar mais para cima

    botaoComoJogarWidth = botaoIniciarWidth;  
    botaoComoJogarHeigth = botaoIniciarHeight;
    botaoComoJogarX = botaoIniciarX; 
    botaoComoJogarY = botaoIniciarY - botaoComoJogarHeigth - windowHeight * 0.05; 

    botaoSobreJogoWidth = botaoIniciarWidth;  
    botaoSobreJogoHeigth = botaoIniciarHeight;
    botaoSobreJogoX = botaoIniciarX; 
    botaoSobreJogoY = botaoComoJogarY - botaoSobreJogoHeigth - windowHeight * 0.05; // Espaço entre os botões

    
    botaoSairWidth = windowWidth * 0.1; 
    botaoSairHeigth = windowHeight * 0.06; 
    botaoSairX = windowWidth - botaoSairWidth - windowWidth * 0.02; 
    botaoSairY = windowHeight * 0.02; 

    botaoVoltarWidth = botaoSairWidth;
    botaoVoltarHeigth = botaoSairHeigth;
    botaoVoltarX = windowWidth - botaoVoltarWidth - windowWidth * 0.02;
    botaoVoltarY = botaoSairY; 

    botaoMenuWidth = windowWidth * 0.15; // Reduzindo um pouco a largura
    botaoMenuHeigth = windowHeight * 0.08; // Reduzindo um pouco a altura
    botaoMenuX = centerPosition(botaoMenuWidth, windowWidth); 
    botaoMenuY = windowHeight * 0.45; // Movendo um pouco para cima
}