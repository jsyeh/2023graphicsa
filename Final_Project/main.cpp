///week12-5_TRT_keyboard_mouse �n�� keyboard mouse �Ӿޱ�
#include <stdio.h>
#include <GL/glut.h>
FILE * fout = NULL; ///step02-2 �@�}�l,�ɮרS���}, NULL
FILE * fin = NULL; ///step02-2 �nŪ�ɥΪ�����, �@�}�l�]�O NULL
float teapotX=0, teapotY=0; ///���ڭ̬ݲ��ʭ�
float angle=0, angle2=0, angle3=0;///step03-2 �\�ʧ@
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        ///glTranslatef(teapotX, teapotY, 0);
        ///glTranslatef(????); ///step03-2 �\�ʧ@
        glRotatef(angle, 0, 0, 1);///step03-2 �\�ʧ@
        glTranslatef(0.400000, -0.060000, 0);///step03-2
        ///glTranslatef(teapotX, teapotY, 0);///step03-2 �\�ʧ@
        glutSolidTeapot( 0.3 );
    glPopMatrix();
    glutSwapBuffers();
}
void mouse(int button, int state, int x, int y)
{
    if(state==GLUT_DOWN){
        teapotX = (x-150)/150.0;
        teapotY = (150-y)/150.0;
        angle = x;
        printf("glTranslatef(%f, %f, 0);\n", teapotX, teapotY);
        if(fout==NULL) fout = fopen("file4.txt", "w"); ///step02-2 �S�}��,�N�}
        ///fprintf(fout, "%f %f\n", teapotX, teapotY); ///step02-2 �n�A�s�y��
    }
    display();
}
void keyboard(unsigned char key, int x, int y) ///step02-2 keyboard�禡
{
    if(fin==NULL){ ///step02-2 �p�G�ɮ��٨S fopen(), �N�}��
        fclose(fout); ///�e��mouse�|�}fout����, �ҥH�n����
        fin = fopen("file4.txt", "r"); ///step02-2 �S�}��,�N�}
    }
    ///fscanf(fin, "%f %f", &teapotX, &teapotY); ///step02-2 �u��Ū��
    display(); ///step02-2 ���e�e��
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week12");

    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard); ///step02-2 keyboard�n�����o(�}�ɡBŪ��)

    glutMainLoop();
}
