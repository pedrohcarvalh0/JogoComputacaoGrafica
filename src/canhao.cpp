#include <GL/glut.h>
#include "texturas.h"
#include "canhao.h"
#include <tela.h>

// Posição do canhão
float cannonX = 900.0f;
float cannonY = 80.0f;

// Posição do mouse
float mouseX = 0.0f;
float mouseY = 0.0f;


// Pode precisar de ajuste
float velocidadeTiroCanhao = 0.02f;

// Estrutura para representar uma bala
Bullet bullets[MAX_BULLETS];

// Variável para alternar entre quadrado e triângulo
int currentBulletShape = 0;

void initBullets() {
    for (int i = 0; i < MAX_BULLETS; ++i) {
        bullets[i].active = 0;
    }
}

void createBullet(float startX, float startY, float targetX, float targetY) {
    for (int i = 0; i < MAX_BULLETS; ++i) {
        if (!bullets[i].active) {
            bullets[i].x = startX;
            bullets[i].y = startY;
            bullets[i].vx = (targetX - startX) * velocidadeTiroCanhao;
            bullets[i].vy = (targetY - startY) * velocidadeTiroCanhao;
            bullets[i].active = 1;
            bullets[i].shape = currentBulletShape;
            break;
        }
    }
}

void updateBullets() {
    for (int i = 0; i < MAX_BULLETS; ++i) {
        if (bullets[i].active) {
            bullets[i].x += bullets[i].vx;
            bullets[i].y += bullets[i].vy;

            // Desativar a bala se ela sair da tela
            if (bullets[i].x < 0 || bullets[i].x > windowWidth || bullets[i].y < 0 || bullets[i].y > windowHeight) {
                bullets[i].active = 0;
            }

        }
    }
}

void drawSquare(float x, float y, float size) {
    glBegin(GL_QUADS);
    glVertex2f(x - size / 2, y - size / 2);
    glVertex2f(x + size / 2, y - size / 2);
    glVertex2f(x + size / 2, y + size / 2);
    glVertex2f(x - size / 2, y + size / 2);
    glEnd();
}

void drawTriangle(float x, float y, float size) {
    glBegin(GL_TRIANGLES);
    glVertex2f(x, y + size / 2);
    glVertex2f(x + size / 2, y - size / 2);
    glVertex2f(x - size / 2, y - size / 2);
    glEnd();
}

void drawBullets() {
    glEnable(GL_TEXTURE_2D); 
    for (int i = 0; i < MAX_BULLETS; ++i) {
        if (bullets[i].active) {
            if (bullets[i].shape == 0) {
                //drawSquare(bullets[i].x, bullets[i].y, 10.0f);
                drawImage(TEXTURA_TIRO_1, bullets[i].x, bullets[i].y, 20, 20);
            } else {
                //drawTriangle(bullets[i].x, bullets[i].y, 10.0f);
                drawImage(TEXTURA_TIRO_2, bullets[i].x, bullets[i].y, 20, 20);
            }
        }
    }
    glEnable(GL_TEXTURE_2D);  // Reabilita o uso de texturas
}

void drawCannon() {
    // Desenha a textura do canhão na posição do canhão
    drawImage(CANHAO, cannonX - 25.0f, cannonY - 25.0f, 90.0f, 90.0f); 
}

void mouseMotion(int x, int y) {
    mouseX = (float)x;
    mouseY = (float)(600 - y); // Inverte o valor de y para corresponder às coordenadas da janela
    cannonX = mouseX;
    cannonY = mouseY;
    glutPostRedisplay();
}

void update(int value) {
    updateBullets();
    glutPostRedisplay();
    glutTimerFunc(16, update, 0); // Chama novamente a função de atualização em 16 ms
}
