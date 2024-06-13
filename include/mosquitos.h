#ifndef MOSQUITOS_H
#define MOSQUITOS_H
#include <GL/glut.h>

#define MAX_SQUARES 10
#define MAX_LIVES 5

// Estrutura para representar um quadrado que cai
typedef struct {
    float x, y;
    int active;
} FallingSquare;

extern FallingSquare squares[MAX_SQUARES];

// Estrutura para representar as vidas
typedef struct {
    float x, y;
    int active;
} Life;

extern Life lives[MAX_LIVES];

// Variável para contabilizar pontos
extern int score;
// Variável para contabilizar vidas
extern int livesLeft;
// Variável para a velocidade de queda dos quadrados
extern float velocidadeQuedaMosquitos;
// Número inicial de quadrados que caem
extern int initialNumSquares;

void initFallingSquares();                           // Inicializa os quadrados que caem
void initLives();                                    // Inicializa as vidas
void createFallingSquare();                          // Cria um novo quadrado que cai
void updateFallingSquares();                         // Atualiza a posição dos quadrados que caem
void drawFallingSquares();                           // Desenha os quadrados que caem
void drawLives();                                    // Desenha as vidas
void detectCollisions();                             // Detecta colisões entre tiros e quadrados que caem
void drawText(const char* text, float x, float y);   // Função para desenhar o texto
void updatemosq();                          // Função para atualização mosquitos
void initmosq();                                     // Função de inicialização


#endif