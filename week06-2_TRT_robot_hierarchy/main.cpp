///Week06-2_TRT_robot_hierarchy ��� Week06-1
///�ܦh���P���s�����p, �ӥB���u�|�a��y���
#include <GL/glut.h>
float angle = 0;
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    ///glutSolidSphere(0.02, 30, 30); ///�����ߪ���y
    glutSolidTeapot(0.3); ///step02-1 ����

    glPushMatrix(); ///�k���u
        ///step02-1 �����ѱ� ///glTranslatef(-0.5, 0.5, 0);     ///(3) ���W�h
        glTranslatef(0.49, 0.13, 0); ///step02-2 �s��
        glRotatef(angle, 0, 0, 1);      ///(2) �N�i�H��ʤF
        glTranslatef( 0.46, -0.05, 0 ); ///(1) ����ʪ�����,�񤤤�
        glutSolidTeapot(0.3);

        glPushMatrix(); ///�k��y
            glTranslatef(0.49, 0.13, 0); ///step02-2 �s��
            glRotatef(angle, 0, 0, 1);      ///(2) �N�i�H��ʤF
            glTranslatef( 0.46, -0.05, 0 ); ///(1) ����ʪ�����,�񤤤�
            glutSolidTeapot(0.3);
        glPopMatrix();
    glPopMatrix();

    glutSwapBuffers();
    angle++;
}
int main(int argc, char* argv[] )
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week04");

    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutMainLoop();
}