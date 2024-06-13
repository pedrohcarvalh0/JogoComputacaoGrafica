#include <GL/glut.h>
#include <tela.h>
#include <localizacao.h>
#include <gerais.h>
#include <canhao.h>

int objectDetector(GLfloat xMouse, GLfloat yMouse, GLfloat xObj, GLfloat yObj, GLfloat wObj, GLfloat hObj) {
    return (xMouse > xObj && xMouse < xObj + wObj && yMouse > yObj && yMouse < yObj + hObj);
}

void mouseClick(int button, int estado, int x, int y)
{
    int alturaMax = glutGet(GLUT_WINDOW_HEIGHT); // Armazena a altura máxima da tela
    int yInvertido = alturaMax - y;

    if (button == GLUT_LEFT_BUTTON && estado == GLUT_DOWN)
    {
        if (currentScreen == TELA_INICIAL) {
            if (objectDetector(x, yInvertido, botaoIniciarX, botaoIniciarY, botaoIniciarWidth, botaoIniciarHeight)) {
                glutSetCursor(GLUT_CURSOR_INHERIT);
                desenharNovaTela(TELA_GAMEPLAY); // Troca para tela de gameplay
            } else if (objectDetector(x, yInvertido, botaoComoJogarX, botaoComoJogarY, botaoComoJogarWidth, botaoComoJogarHeigth)) {
                glutSetCursor(GLUT_CURSOR_INHERIT);
                desenharNovaTela(TELA_COMO_JOGAR); // Troca para tela de como jogar
            } else if (objectDetector(x, yInvertido, botaoSobreJogoX, botaoSobreJogoY, botaoSobreJogoWidth, botaoSobreJogoHeigth)) {
                glutSetCursor(GLUT_CURSOR_INHERIT);
                desenharNovaTela(TELA_SOBRE_JOGO); // Troca para tela de sobre o jogo
            } else if (objectDetector(x, yInvertido, botaoSairX, botaoSairY, botaoSairWidth, botaoSairHeigth)) {
                exit(0); // Encerra o programa
            }
        } else if (currentScreen == TELA_COMO_JOGAR || currentScreen == TELA_SOBRE_JOGO) {
            if (objectDetector(x, yInvertido, botaoVoltarX, botaoVoltarY, botaoVoltarWidth, botaoVoltarHeigth)) {
                glutSetCursor(GLUT_CURSOR_INHERIT);
                desenharNovaTela(TELA_INICIAL); // Troca para tela inicial
            }
            // Teste pause
        } else if (currentScreen == TELA_PAUSE) {
            if (objectDetector(x, yInvertido, botaoMenuX, botaoMenuY, botaoMenuWidth, botaoMenuHeigth)) {
                glutSetCursor(GLUT_CURSOR_INHERIT);
                isPaused = false; // Volta para o menu
                desenharNovaTela(TELA_INICIAL);
            }
        } 
        // PARTES DA GAMEPLAY
        else if (currentScreen == TELA_GAMEPLAY) {
            createBullet(cannonX, cannonY + 40, x, windowHeight - y);
        }
    }
}

void onChangeMouseCursor(int x, int y)
{
    y = glutGet(GLUT_WINDOW_HEIGHT) - y;

    if (currentScreen == TELA_INICIAL) {
        if (objectDetector(x, y, botaoIniciarX, botaoIniciarY, botaoIniciarWidth, botaoIniciarHeight) ||
            objectDetector(x, y, botaoComoJogarX, botaoComoJogarY, botaoComoJogarWidth, botaoComoJogarHeigth) ||
            objectDetector(x, y, botaoSobreJogoX, botaoSobreJogoY, botaoSobreJogoWidth, botaoSobreJogoHeigth) ||
            objectDetector(x, y, botaoSairX, botaoSairY, botaoSairWidth, botaoSairHeigth)) {
            glutSetCursor(GLUT_CURSOR_INFO);
        } else {
            glutSetCursor(GLUT_CURSOR_INHERIT);
        }
    } else if (currentScreen == TELA_COMO_JOGAR || currentScreen == TELA_SOBRE_JOGO) {
        if (objectDetector(x, y, botaoVoltarX, botaoVoltarY, botaoVoltarWidth, botaoVoltarHeigth)) {
            glutSetCursor(GLUT_CURSOR_INFO);
        } else {
            glutSetCursor(GLUT_CURSOR_INHERIT);
        }
    } else if (currentScreen == TELA_PAUSE) {
        if (objectDetector(x, y, botaoMenuX, botaoMenuY, botaoMenuWidth, botaoMenuHeigth)) {
            glutSetCursor(GLUT_CURSOR_INFO);
        } else {
            glutSetCursor(GLUT_CURSOR_INHERIT);
        }
    }
}