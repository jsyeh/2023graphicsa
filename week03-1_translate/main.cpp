///�{���X���R,���ڭ̤W�g�Ъ�10��
#include <GL/glut.h>
float X=0, Y=0;///step02-2 �Q�� global �ܼ�,�b�禡�����ǭ� (�j�g��)
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); ///step02-2 �M�I��
    glPushMatrix(); ///step01-2 �ƥ��x�}
        glTranslatef( X, Y, 0 ); ///step01-2 �u���o��?�٤���
        glutSolidTeapot( 0.3 );
    glPopMatrix(); ///step01-2 �٭�x�}

    glutSwapBuffers();
}
///#include <stdio.h> ///step02-1 ���F printf()
void mouse(int button, int state, int x, int y) ///�p�g��
{ ///step02-1 �� mouse�禡����
    X = (x-150)/150.0; ///printf("%d %d %d %d\n", button, state, x, y);
    Y = -(y-150)/150.0; ///step02-2 �f�Z: ��@�b�B���@�b, y�t��
}///step02-1 �L�X�� printf()
int main(int argc, char* argv[] )
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week03");

    glutDisplayFunc(display);
    glutMouseFunc(mouse); ///step02-1 �� mouse�禡����

    glutMainLoop();
}
