///Week06-1_TRT_robot2 �K�W�W�g��week05-2_TRT_robot
#include <GL/glut.h>
float angle = 0;
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    glutSolidSphere(0.02, 30, 30); ///�����ߪ���y

    glPushMatrix();
        glTranslatef(-0.5, 0.5, 0);     ///(3) ���W�h
        glRotatef(angle, 0, 0, 1);      ///(2) �N�i�H��ʤF
        glTranslatef( 0.46, -0.05, 0 ); ///(1) ����ʪ�����,�񤤤�
        glutSolidTeapot(0.3);
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
