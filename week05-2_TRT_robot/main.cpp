///Week05-2_TRT_robot �{���Ӧ� week05-1_TRT_rotate_translate
///�e�X�j������B�e�X���u
#include <GL/glut.h>
float angle = 0;
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); ///�M�I��

    glColor3f(0, 1, 0); ///��⪺����
    glPushMatrix();
        glutSolidCube(0.5);

        glPushMatrix();
            glTranslatef(0.25, 0.25, 0);///(3)���ӪF��,���b�k�W��
            glRotatef(angle, 0, 0, 1);  ///(2)���
            glTranslatef(0.25, 0.25, 0);///(1)����त��,��줤��
///            glTranslatef(0.5, 0.5, 0);///step03-3_�����ѱ�
            glColor3f(1,0,0); ///���⪺���u
            glutSolidCube(0.5);
        glPopMatrix();
    glPopMatrix();

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
