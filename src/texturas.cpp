#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include <GL/glut.h>
#include <texturas.h>
#include <tela.h>
#include <gerais.h>

/* Armazena as todas texturas */
GLuint *textures;

/* Guarda o estado atual do frame da animação  */
int currentBackgroundMenuFrame = 0;   // Background da Tela Inicial

void loadTexture(GLuint texture, const char *filename)
{
    int imgWidth, imgHeight, imgChannels;
    unsigned char *imgData;
    // Carrega a imagem usando stb_image
    imgData = stbi_load(filename, &imgWidth, &imgHeight, &imgChannels, STBI_default);
    if (imgData == nullptr)
    {
        fprintf(stderr, "Erro ao carregar a imagem %s\n", filename);
        exit(1);
    }

    glBindTexture(GL_TEXTURE_2D, texture);

    // Define os parâmetros da textura
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // Carrega a textura para a memória da GPU
    if (imgChannels == 3)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, imgWidth, imgHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, imgData);
    }
    else if (imgChannels == 4)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, imgWidth, imgHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, imgData);
    }

    // Libera a imagem carregada da memória RAM
    stbi_image_free(imgData);
}

void initTextures()
{
    // Armazenar o espaço para todas as texturas
    textures = (GLuint *)malloc(sizeof(GLuint) * NUM_TEXTURES);
    glGenTextures(NUM_TEXTURES, textures);

    // Carrega todas as texturas usadas no Jogo
    loadTexture(textures[LOGO], "../assets/logoDengue.png");
    loadTexture(textures[FUNDO_PRINCIPAL], "../assets/fundoTelaInicial3.png");
    loadTexture(textures[BOTAO_INICIAR], "../assets/btnIniciar.png");
    loadTexture(textures[BOTAO_COMO_JOGAR], "../assets/btnComoJogar.png");
    loadTexture(textures[BOTAO_SAIR_PRINCIPAL], "../assets/btnSair.png");
    loadTexture(textures[FUNDO_COMO_JOGAR], "../assets/fundoComoJogar.png");
    loadTexture(textures[BOTAO_VOLTAR], "../assets/btnVoltar.png");
    loadTexture(textures[FUNDO_TELA_FASE_DIA], "../assets/fundoFaseDia.png");
    loadTexture(textures[FUNDO_TELA_FASE_ANOITECER], "../assets/fundoFaseAnoitecer.png");
    loadTexture(textures[FUNDO_SOBRE_JOGO], "../assets/fundoTelaSobreJogo.png");
    loadTexture(textures[BOTAO_SOBRE_JOGO], "../assets/btnSobreJogo.png");
    loadTexture(textures[FUNDO_PAUSE], "../assets/fundoTelaPause.png");
    loadTexture(textures[BOTAO_CONTINUAR], "../assets/btnContinuar.png");
    loadTexture(textures[BOTAO_MENU], "../assets/btnMenu.png");
    loadTexture(textures[FUNDO_TELA_GAMEOVER], "../assets/fundoTelaGameOver.png");
    loadTexture(textures[CANHAO], "../assets/canhao.png");
    loadTexture(textures[TEXTURA_TIRO_1], "../assets/tiro1.png");
    loadTexture(textures[TEXTURA_TIRO_2], "../assets/tiro2.png");
    loadTexture(textures[MOSQUITO], "../assets/mosquito.png");
    loadTexture(textures[VIDAS_1], "../assets/1vidas.png");
    loadTexture(textures[VIDAS_2], "../assets/2vidas.png");
    loadTexture(textures[VIDAS_3], "../assets/3vidas.png");
    loadTexture(textures[VIDAS_4], "../assets/4vidas.png");
    loadTexture(textures[VIDAS_5], "../assets/5vidas.png");
 
}

/* Função que espera carregar todas as texturas para só depois ir para tela inicial */
void loadTextures(int)
{
    initTextures(); // Carrega as texturas

    // Depois muda a tela de carregando para a tela de início
    glutDisplayFunc(telaInicial);
   
}

/* Libera as texturas da memória */
void freeTextures()
{
    glDeleteTextures(NUM_TEXTURES, textures);
    free(textures);
}


// Função que Desenha uma imagem que tem o controle do recorte sobre a textura
void drawImageTexture(int imageId, GLfloat xTexture, GLfloat yTexture, GLfloat wTexture, GLfloat hTexture, GLfloat x, GLfloat y, GLfloat width, GLfloat height)
{
    glBindTexture(GL_TEXTURE_2D, textures[imageId]); // Aplica a textura
    glBegin(GL_QUADS);
    glTexCoord2f(xTexture, yTexture + hTexture);
    glVertex2f(x, y);
    glTexCoord2f(xTexture + wTexture, yTexture + hTexture);
    glVertex2f(x + width, y);
    glTexCoord2f(xTexture + wTexture, yTexture);
    glVertex2f(x + width, y + height);
    glTexCoord2f(xTexture, yTexture);
    glVertex2f(x, y + height);
    glEnd();
}

// Função que Desenha uma imagem usando a textura completa
void drawImage(int imageId, GLfloat x, GLfloat y, GLfloat width, GLfloat height)
{
    drawImageTexture(imageId, 0.0f, 0.0f, 1.0f, 1.0f, x, y, width, height);
}
