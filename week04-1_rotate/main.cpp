///�ݤF�{������, ��{�����ƥ��b Notepad++ ���@�U�i�H�Ѧ�
///�A��W�g���{�� copy �L��
///�{���X���R,���ڭ̤W�g�Ъ�10��
#include <GL/glut.h>
float angle = 0; ///step02-1 �ŧiglobal�����ܼ� angle
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); ///�M�I��
    glPushMatrix(); ///step02-1 �ƥ��x�}
        glRotatef(angle, 0, 1, 0); ///step02-1 ���� angle ����
        glutSolidTeapot( 0.3 );
    glPopMatrix();  ///step02-1 �٭�x�}
    glutSwapBuffers();
    angle++; ///step02-1 �⨤��++
}
int main(int argc, char* argv[] )
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week04");

    glutDisplayFunc(display);
    glutIdleFunc(display); ///step02-1 ����idle��,�N���e�e��
    glutMainLoop();
}
