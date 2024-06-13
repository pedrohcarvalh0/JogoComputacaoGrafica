#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "canhao.h"
#include <tela.h>
#include "mosquitos.h"
#include <texturas.h>

// Definição das variáveis globais
int score = 0;
int livesLeft = MAX_LIVES;
float velocidadeQuedaMosquitos = 2.0f;
int initialNumSquares = 1;
FallingSquare squares[MAX_SQUARES];
Life lives[MAX_LIVES];

void initFallingSquares() {
    for (int i = 0; i < MAX_SQUARES; i++) {
        squares[i].active = 0;
    }
}

void initLives() {
    for (int i = 0; i < MAX_LIVES; i++) {
        lives[i].active = 1;
        lives[i].x = windowWidth - 50 * (i + 1);
        lives[i].y = windowHeight - 50;
    }
}

void createFallingSquare() {
    for (int i = 0; i < MAX_SQUARES; i++) {
        if (!squares[i].active) {
            squares[i].x = rand() % windowWidth;
            squares[i].y = windowHeight;
            squares[i].active = 1;
            break;
        }
    }
}

void updateFallingSquares() {
    for (int i = 0; i < MAX_SQUARES; i++) {
        if (squares[i].active) {
            squares[i].y -= velocidadeQuedaMosquitos;  // Velocidade do quadrado que cai

            // Desativa o quadrado se sair da tela
            if (squares[i].y < 0) {
                squares[i].active = 0;
                desenharNovaTela(TELA_GAME_OVER);
                // Se o quadrado alcançou o fundo da tela sem ser destruído, game over
                
            }
        }
    }
}

void drawFallingSquares() {
    glEnable(GL_TEXTURE_2D); 
    for (int i = 0; i < MAX_SQUARES; i++) {
        if (squares[i].active) {
            //glColor3f(0.0f, 0.0f, 1.0f);  // Azul para quadrados que caem
            //drawSquare(squares[i].x, squares[i].y, 20);
            drawImage(MOSQUITO, squares[i].x, squares[i].y, 50, 50);
        }
    }
    glEnable(GL_TEXTURE_2D);  // Reabilita texturas após desenhar os quadrados
}

void drawLives() {
    for (int i = 0; i < MAX_LIVES; i++) {
        if (lives[i].active) {
            glColor3f(1.0f, 0.0f, 0.0f);  // Vermelho para vidas ativas
            drawSquare(lives[i].x, lives[i].y, 20);
        }
    }
}

void detectCollisions() {
    for (int i = 0; i < MAX_BULLETS; i++) {
        if (bullets[i].active) {
            for (int j = 0; j < MAX_SQUARES; j++) {
                if (squares[j].active) {
                    float dx = bullets[i].x - squares[j].x;
                    float dy = bullets[i].y - squares[j].y;
                    float distance = sqrt(dx * dx + dy * dy);
                    if (distance < 35) {  // Assumindo que 10 + 20/2 é a distância mínima para colisão
                        bullets[i].active = 0;
                        squares[j].active = 0;
                        score += 10;
                        printf("Pontos: %d\n", score);

                        // A cada 200 pontos, ganha uma vida
                        if (score % 200 == 0 && livesLeft < MAX_LIVES) {
                            lives[livesLeft++].active = 1;
                        }

                        // Cria um novo quadrado quando o atual é destruído
                        createFallingSquare();

                        break;
                    }
                }
            }
        }
    }
}

void drawText(const char* text, float x, float y) {
    glRasterPos2f(x, y);
    while (*text) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *text);
        text++;
    }
}

void updatemosq() {
    updateFallingSquares(); 
    detectCollisions();

    static int squaresCreated = 0;
    static int scoreThreshold = 100;
    static int numSquaresToCreate = initialNumSquares;

    // Cria os quadrados adicionais se a pontuação for atingida
    if (score >= scoreThreshold) {    
        squaresCreated = 0;
        scoreThreshold += 100;
    }

    // Cria os quadrados que caem
    for (int i = 0; i < numSquaresToCreate; i++) {
        if (squaresCreated < numSquaresToCreate) {
            createFallingSquare();
            squaresCreated++;
        }
    }

    glutPostRedisplay();
}

void initmosq() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    initFallingSquares();
    initLives();
}
