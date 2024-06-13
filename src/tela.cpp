#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <tela.h>
#include <gerais.h>
#include <texturas.h>
#include <localizacao.h>
#include <windows.h>
#include <playsoundapi.h>
#include <playSounds.h>
#include <keyboard.h> 
#include <canhao.h>
#include <mosquitos.h>

int windowWidth, windowHeight;
int currentScreen = TELA_INICIAL;

void telaZero()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 1.0f, 1.0f);
    const char *message1 = "Um projeto da UNIVASF na luta contra a Dengue";
    const char *message2 = "Clique AQUI para se aventurar...";
    void *font = GLUT_BITMAP_TIMES_ROMAN_24;
    bitMapText(((windowWidth - glutBitmapLength(font, (const unsigned char *)message1)) / 2), 84, font, message1);
    bitMapText(((windowWidth - glutBitmapLength(font, (const unsigned char *)message2)) / 2), 30, font, message2);
    glutSwapBuffers();
}

void telaInicial()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glEnable(GL_TEXTURE_2D);
    drawImage(FUNDO_PRINCIPAL, fundoPrincipalX, fundoPrincipalY, windowWidth, windowHeight);
    drawImage(LOGO, logoX, logoY, logoWidth, logoHeight);
    drawImage(BOTAO_INICIAR, botaoIniciarX, botaoIniciarY, botaoIniciarWidth, botaoIniciarHeight);
    drawImage(BOTAO_COMO_JOGAR, botaoComoJogarX, botaoComoJogarY, botaoComoJogarWidth, botaoComoJogarHeigth);
    drawImage(BOTAO_SOBRE_JOGO, botaoSobreJogoX, botaoSobreJogoY, botaoSobreJogoWidth, botaoSobreJogoHeigth);
    drawImage(BOTAO_SAIR_PRINCIPAL, botaoSairX, botaoSairY, botaoSairWidth, botaoSairHeigth);
    playSounds(TELA_INICIAL);
    glDisable(GL_TEXTURE_2D);
    glutSwapBuffers();
}

void telaComoJogar()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glEnable(GL_TEXTURE_2D);
    drawImage(FUNDO_COMO_JOGAR, fundoComoJogarX, fundoComoJogarY, windowWidth, windowHeight);
    drawImage(BOTAO_VOLTAR, botaoVoltarX, botaoVoltarY, botaoVoltarWidth, botaoVoltarHeigth);
    glDisable(GL_TEXTURE_2D);
    glutSwapBuffers();
}

void telaSobreJogo()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glEnable(GL_TEXTURE_2D);
    drawImage(FUNDO_SOBRE_JOGO, fundoComoJogarX, fundoComoJogarY, windowWidth, windowHeight);
    drawImage(BOTAO_VOLTAR, botaoVoltarX, botaoVoltarY, botaoVoltarWidth, botaoVoltarHeigth);
    glDisable(GL_TEXTURE_2D);
    glutSwapBuffers();
}

void telaGameplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glEnable(GL_TEXTURE_2D);
    drawImage(FUNDO_TELA_FASE_ANOITECER, fundoGameplayX, fundoGameplayY, windowWidth, windowHeight);

    // Desenha o canhão
    drawCannon();
    // Desenha e atualiza as balas
    drawBullets();
    updateBullets();
    //Desenha vida
    drawLives();
    //Desenha mosquitos
    drawFallingSquares();

    // Desenha pontuação
    glDisable(GL_TEXTURE_2D);  // Desabilita texturas para desenhar o texto
    glColor3f(0.0f, 0.0f, 0.0f);  // Define a cor do texto para preto
    char pontuacao[50];
    snprintf(pontuacao, sizeof(pontuacao), "Pontos: %d", score);
    float textWidth = glutBitmapLength(GLUT_BITMAP_TIMES_ROMAN_24, (const unsigned char *)pontuacao);
    bitMapText((windowWidth - textWidth) / 2, windowHeight - 20.0f, GLUT_BITMAP_TIMES_ROMAN_24, pontuacao);

    updatemosq();

    glutPostRedisplay();
    
    
    if (!isPaused) {
        playSounds(TELA_GAMEPLAY);
    }
    glDisable(GL_TEXTURE_2D);
    if (isPaused) {
        telaPause();
    }

    glutSwapBuffers();
}

void telaPause()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glEnable(GL_TEXTURE_2D);
    drawImage(FUNDO_PAUSE, fundoPauseX, fundoPauseY, windowWidth, windowHeight);
    drawImage(BOTAO_MENU, botaoMenuX, botaoMenuY, botaoMenuWidth, botaoMenuHeigth);
    glDisable(GL_TEXTURE_2D);
    glutSwapBuffers();
}

void telaGameOver()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glEnable(GL_TEXTURE_2D);
    drawImage(FUNDO_TELA_GAMEOVER, fundoGameOverX, fundoGameOverY, windowWidth, windowHeight);
    playSounds(TELA_GAME_OVER);
    glDisable(GL_TEXTURE_2D);
    glutSwapBuffers();
}

void desenharNovaTela(int novaTela)
{
    currentScreen = novaTela; // Atualiza a tela atual

    switch (novaTela)
    {
    case TELA_INICIAL:
        glutDisplayFunc(telaInicial);
        break;
    case TELA_COMO_JOGAR:
        glutDisplayFunc(telaComoJogar);
        break;
    case TELA_GAMEPLAY:
        glutDisplayFunc(telaGameplay);
        break;
    case TELA_SOBRE_JOGO:
        glutDisplayFunc(telaSobreJogo);
        break;
    case TELA_PAUSE:
        glutDisplayFunc(telaPause);
        break;
    case TELA_GAME_OVER:
        glutDisplayFunc(telaGameOver);
        break;
    default:
        printf("Tela desconhecida: %d\n", currentScreen);
        break;
    }

    glutPostRedisplay(); // Força a atualização da tela
}
