///Week04-3_rotate_translate �{��copy�Ӧ� week04-1_rotate
///Step03-2
#include <GL/glut.h>
float angle = 0; ///step02-1 �ŧiglobal�����ܼ� angle
void display()
{
    glEnable(GL_DEPTH_TEST);
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); ///�M�I��
    glPushMatrix(); ///step02-1 �ƥ��x�}
        glTranslatef(0.6, 0, 0);///step03-2
        glRotatef(angle, 0, 1, 0); ///step02-1 ���� angle ����
        glColor3f(1,1,0);
        glutSolidTeapot( 0.3 );
    glPopMatrix();  ///step02-1 �٭�x�}
    glPushMatrix(); ///step02-1 �ƥ��x�}
        glRotatef(angle, 0, 1, 0); ///step02-1 ���� angle ����
        glTranslatef(0.6, 0, 0);///step03-2
        glColor3f(1,0,0);
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
