#include <GL/glut.h>
#include <stdlib.h>
#include <tela.h>
#include <texturas.h>

void bitMapText(float x, float y, void *fonte, const char *string){
    const char *c;
    glRasterPos2f(x, y);
    for (c = string; *c != '\0'; c++)
        glutBitmapCharacter(fonte, *c);
}


