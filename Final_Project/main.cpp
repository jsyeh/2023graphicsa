///week12-5_TRT_keyboard_mouse �n�� keyboard mouse �Ӿޱ�
#include <stdio.h>
#include <GL/glut.h>
#include "glm.h" ///week13 step02-1
GLMmodel * head = NULL; ///week13 step02-1
GLMmodel * body = NULL; ///week13 step02-1
GLMmodel * uparmR = NULL; ///week13 step02-1
GLMmodel * lowarmR = NULL; ///week13 step02-1
int show[4] = {1, 1, 1, 1};/// week14_step03-1 �� show[i] �ӨM�w�n���n���
int ID = 3;///0:�Y 1���� 2�W���u 3�U���u  ///week14_step03-1
void keyboard(unsigned char key, int x, int y) {/// week13 step03-1
    if(key=='0') ID = 0; ///week14_step02-2
    if(key=='1') ID = 1; ///week14_step02-2
    if(key=='2') ID = 2; ///week14_step02-2
    if(key=='3') ID = 3; ///week14_step02-2
    ///if(key=='0') show[0] = !show[0];/// week13 step03-1
    ///if(key=='1') show[1] = !show[1];/// week13 step03-1
    ///if(key=='2') show[2] = !show[2];/// week13 step03-1
    ///if(key=='3') show[3] = !show[3];/// week13 step03-1
    glutPostRedisplay();
} ///��Ӫ�keyboard�����ѡB���n��
FILE * fout = NULL; ///step02-2 �@�}�l,�ɮרS���}, NULL
FILE * fin = NULL; ///step02-2 �nŪ�ɥΪ�����, �@�}�l�]�O NULL
float teapotX=0, teapotY=0; ///���ڭ̬ݲ��ʭ�
float angle=0, angle2=0, angle3=0;///step03-2 �\�ʧ@
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glScalef(0.2, 0.2, 0.2); ///week13_step02-2
        if(body==NULL){///week13 step02-1
            head = glmReadOBJ("model/head.obj");
            body = glmReadOBJ("model/body.obj");///week13 step02-1
            uparmR = glmReadOBJ("model/uparmR.obj");///Week13 step03-1
            lowarmR = glmReadOBJ("model/lowarmR.obj");///Week13 step03-1
            ///glmUnitize(body); ///week13 step02-1 �o�椧��|��
        }
        if(ID==0) glColor3f(1,0,0); ///��w��,�]����
        else glColor3f(1,1,1); ///�S��w,�]�զ�
        if(show[0]) glmDraw(head, GLM_MATERIAL);///Week13 step03-1

        if(ID==1) glColor3f(1,0,0); ///��w��,�]����
        else glColor3f(1,1,1); ///�S��w,�]�զ�
        if(show[1]) glmDraw(body, GLM_MATERIAL);///week13 step02-1�o�椧��|��

        glPushMatrix();
            glTranslatef(-1.200000, +0.453333, 0); ///wee14_step03-1 �ϹL��
            glRotatef(angle, 0, 0, 1); ///week14_step03-1_TRT�إX��
            //glTranslatef(teapotX, teapotY, 0); ///week14_step03-1_TRT�إX��
            glTranslatef(1.200000, -0.453333, 0); ///week14_step03-1_�����G

            if(ID==2) glColor3f(1,0,0); ///��w��,�]����
            else glColor3f(1,1,1); ///�S��w,�]�զ�
            if(show[2]) glmDraw(uparmR, GLM_MATERIAL);///Week13 step03-1
            glPushMatrix();
                glTranslatef(-1.959999, +0.113333, 0);
                glRotatef(angle, 0, 0, 1);
                glTranslatef(1.959999, -0.113333, 0);

                if(ID==3) glColor3f(1,0,0); ///��w��,�]����
                else glColor3f(1,1,1); ///�S��w,�]�զ�
                if(show[3]) glmDraw(lowarmR, GLM_MATERIAL);///Week13 step03-1
            glPopMatrix();
        glPopMatrix();

    glPopMatrix();
    glColor3f(0, 1, 0);///week14_step03-1 ��Ӥp����,�b������,���Ѧ��I
    glutSolidTeapot( 0.02 );///week14_step03-1 ��Ӥp����,�b������,���Ѧ��I
    glutSwapBuffers();
}
int oldX = 0, oldY = 0; ///Week13 step03-2
void motion(int x, int y){ ///Week13 step03-2
    teapotX += (x - oldX)/150.0; ///Week13 step03-2
    teapotY -= (y - oldY)/150.0; ///Week13 step03-2
    oldX = x;
    oldY = y;
    angle = x; ///week14_step03-1
    printf("glTranslatef(%f, %f, 0);\n", teapotX, teapotY);
    glutPostRedisplay(); ///Week13 step03-2
} ///Week13 step03-2
void mouse(int button, int state, int x, int y)
{
    if(state==GLUT_DOWN){
        oldX = x; ///teapotX = (x-150)/150.0;
        oldY = y; ///teapotY = (150-y)/150.0;
        angle = x;
        ///printf("glTranslatef(%f, %f, 0);\n", teapotX, teapotY);
        ///if(fout==NULL) fout = fopen("file4.txt", "w"); ///step02-2 �S�}��,�N�}
        ///fprintf(fout, "%f %f\n", teapotX, teapotY); ///step02-2 �n�A�s�y��
    }
    display();
}
//void keyboard(unsigned char key, int x, int y) ///step02-2 keyboard�禡
//{
//    if(fin==NULL){ ///step02-2 �p�G�ɮ��٨S fopen(), �N�}��
//        fclose(fout); ///�e��mouse�|�}fout����, �ҥH�n����
//        fin = fopen("file4.txt", "r"); ///step02-2 �S�}��,�N�}
//    }
//    ///fscanf(fin, "%f %f", &teapotX, &teapotY); ///step02-2 �u��Ū��
//    display(); ///step02-2 ���e�e��
//}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week12");

    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMotionFunc(motion); ///Week13 step03-3
    glutKeyboardFunc(keyboard); ///step02-2 keyboard�n�����o(�}�ɡBŪ��)

    glutMainLoop();
}
