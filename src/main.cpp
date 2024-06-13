#include <GL/glut.h>
#include <mouse.h>
#include <tela.h>
#include <texturas.h>
#include <gerais.h>
#include <localizacao.h>
#include <keyboard.h>

// Inicializa o que precisa ser usado no jogo
void init()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    // Habilita o blending para lidar com a transparência alfa
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
}

// Função de limpeza
void Cleanup()
{
    freeTextures();
}

void reshapeWindow(GLsizei w, GLsizei h)
{
    // Atualiza as variáveis globais com as novas dimensões
    windowWidth = w;
    windowHeight = h;

    // Evita a divisão por zero
    if (h == 0)
        h = 1;

    // Especifica as dimensões da Viewport
    glViewport(0, 0, windowWidth, windowHeight);

    // Inicializa o sistema de coordenadas
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, windowWidth, 0.0, windowHeight);
    updatePosition();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutCreateWindow("Dengue Defenders");
    glutFullScreen();
    glutDisplayFunc(telaZero);
    glutReshapeFunc(reshapeWindow);
    
    glutMouseFunc(mouseClick);
    glutKeyboardFunc(keyboard);

    glutPassiveMotionFunc(onChangeMouseCursor);
    glutTimerFunc(100, loadTextures, 0);
    init();
    atexit(Cleanup);
    glutMainLoop();

    return 0;
}
