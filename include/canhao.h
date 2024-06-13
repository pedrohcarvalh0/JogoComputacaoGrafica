#ifndef CANHAO_H
#define CANHAO_H

#include <GL/glut.h>

// Posição do canhão
extern float cannonX;
extern float cannonY;

// Posição do mouse
extern float mouseX, mouseY;

// Estrutura para representar uma bala
typedef struct {
    float x, y;         // Posição da bala
    float vx, vy;       // Velocidade da bala
    int active;         // Status ativo da bala
    int shape;          // Forma da bala: 0 para quadrado, 1 para triângulo
} Bullet;

#define MAX_BULLETS 1000
extern Bullet bullets[MAX_BULLETS];
// Variável para alternar entre quadrado e triângulo
extern int currentBulletShape;
void initBullets(); // Inicializa as balas
void createBullet(float startX, float startY, float targetX, float targetY); // Cria uma nova bala
void updateBullets(); // Atualiza a posição das balas
void drawSquare(float x, float y, float size); // Função para desenhar um quadrado
void drawTriangle(float x, float y, float size); // Função para desenhar um triângulo
void drawBullets(); // Desenha as balas
void drawCannon(); // Função para desenhar o canhão
void mouseMotion(int x, int y); // Função de movimento do mouse
void update(int value); // Função de atualização
#endif