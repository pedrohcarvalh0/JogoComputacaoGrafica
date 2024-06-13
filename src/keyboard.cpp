#include <GL/glut.h>
#include <tela.h>
#include <playSounds.h>
#include <canhao.h>

extern int currentScreen; // Variável global declarada em tela.cpp
extern bool isPaused;     // Variável global declarada em tela.cpp

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'p':
    case 'P':
        if (currentScreen == TELA_GAMEPLAY)
        {
            isPaused = !isPaused;
            if (isPaused)
            {
                //stopSounds(TELA_GAMEPLAY); // Certifique-se de ter uma função para parar a música
                desenharNovaTela(TELA_PAUSE);
            }
            else
            {
                desenharNovaTela(TELA_GAMEPLAY);
            }
        }
        break;
    case 27: // Tecla Esc para voltar a tela de gameplay
        if (currentScreen == TELA_PAUSE)
        {
            isPaused = false;
            desenharNovaTela(TELA_GAMEPLAY);
        }
        break;
    case '\t': // Tecla Tab para voltar à tela inicial
        if (currentScreen == TELA_GAME_OVER)
        {
            desenharNovaTela(TELA_INICIAL);
        }
        break;
    case 'a':
    case 'A':
        cannonX -= 15;
        if (cannonX < 20) cannonX = 20;
        break;
    case 'd':
    case 'D':
        cannonX += 15;
        if (cannonX > windowWidth - 20) cannonX = windowWidth - 20;
        break;
    case ' ':
        currentBulletShape = !currentBulletShape;
        break;
    default:
        break;
    }
    glutPostRedisplay();
}
