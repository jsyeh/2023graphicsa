///Week15_step03_1 程式用陣列: (模型組合好了)切換不同的關節,要改變不同的角度
/// int angle[20]; angle[0] angle[1] ...  用它們來旋轉
/// motion()時, 用 angle[ID]來改
///Week15_step03_2 把angle[i]存檔's', 再播放動畫'r'
///week12-5_TRT_keyboard_mouse 要用 keyboard mouse 來操控
#include <stdio.h>
#include <GL/glut.h>
#include "glm.h" ///week13 step02-1
GLMmodel * head = NULL; ///week13 step02-1
GLMmodel * body = NULL; ///week13 step02-1
GLMmodel * uparmR = NULL; ///week13 step02-1
GLMmodel * lowarmR = NULL; ///week13 step02-1
int show[4] = {1, 1, 1, 1};/// week14_step03-1 用 show[i] 來決定要不要顯示
int ID = 3;///0:頭 1身體 2上手臂 3下手臂  ///week14_step03-1
FILE * fout = NULL; ///step02-2 一開始,檔案沒有開, NULL
FILE * fin = NULL; ///step02-2 要讀檔用的指標, 一開始也是 NULL
float teapotX=0, teapotY=0; ///幫我們看移動值
///float angle=0, angle2=0, angle3=0;///step03-2 擺動作
float angle[20] = {};///week15_step03_1 變陣列
void keyboard(unsigned char key, int x, int y) {/// week13 step03-1
    if(key=='0') ID = 0; ///week14_step02-2
    if(key=='1') ID = 1; ///week14_step02-2
    if(key=='2') ID = 2; ///week14_step02-2
    if(key=='3') ID = 3; ///week14_step02-2
    if(key=='s'){
        if(fout==NULL) fout = fopen("motion.txt", "w");///week15_step03_2 寫檔案
        for(int i=0; i<20; i++){ ///week15_step03_2 寫檔案
            fprintf(fout, "%.2f ", angle[i] );///week15_step03_2 寫檔案, 小心,有空格
        }
        fprintf(fout, "\n");///week15_step03_2 寫檔案,後面有跳行
    }else if(key=='r'){
        if(fin==NULL) fin = fopen("motion.txt", "r");///week15_step03_2
        for(int i=0; i<20; i++){
            fscanf(fin, "%f", &angle[i] ); ///week15_step03_2
        }
        glutPostRedisplay();
    }
    ///if(key=='0') show[0] = !show[0];/// week13 step03-1
    ///if(key=='1') show[1] = !show[1];/// week13 step03-1
    ///if(key=='2') show[2] = !show[2];/// week13 step03-1
    ///if(key=='3') show[3] = !show[3];/// week13 step03-1
    glutPostRedisplay();
} ///原來的keyboard先註解、不要用
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
            ///glmUnitize(body); ///week13 step02-1 這行之後會改
        }
        if(ID==0) glColor3f(1,0,0); ///選定的,設紅色
        else glColor3f(1,1,1); ///沒選定,設白色
        if(show[0]) glmDraw(head, GLM_MATERIAL);///Week13 step03-1

        if(ID==1) glColor3f(1,0,0); ///選定的,設紅色
        else glColor3f(1,1,1); ///沒選定,設白色
        if(show[1]) glmDraw(body, GLM_MATERIAL);///week13 step02-1這行之後會改

        glPushMatrix();
            glTranslatef(-1.200000, +0.453333, 0); ///wee14_step03-1 反過來
            glRotatef(angle[2], 0, 0, 1); ///week15_step03_1 改用陣列
            glTranslatef(1.200000, -0.453333, 0); ///week14_step03-1_的結果

            if(ID==2) glColor3f(1,0,0); ///選定的,設紅色
            else glColor3f(1,1,1); ///沒選定,設白色
            if(show[2]) glmDraw(uparmR, GLM_MATERIAL);///Week13 step03-1
            glPushMatrix();
                glTranslatef(-1.959999, +0.113333, 0);
                glRotatef(angle[3], 0, 0, 1); ///week15_step03_1 改用陣列
                glTranslatef(1.959999, -0.113333, 0);

                if(ID==3) glColor3f(1,0,0); ///選定的,設紅色
                else glColor3f(1,1,1); ///沒選定,設白色
                if(show[3]) glmDraw(lowarmR, GLM_MATERIAL);///Week13 step03-1
            glPopMatrix();
        glPopMatrix();

    glPopMatrix();
    glColor3f(0, 1, 0);///week14_step03-1 放個小茶壼,在正中心,當成參考點
    glutSolidTeapot( 0.02 );///week14_step03-1 放個小茶壼,在正中心,當成參考點
    glutSwapBuffers();
}
int oldX = 0, oldY = 0; ///Week13 step03-2
void motion(int x, int y){ ///Week13 step03-2
    teapotX += (x - oldX)/150.0; ///Week13 step03-2
    teapotY -= (y - oldY)/150.0; ///Week13 step03-2
    angle[ID] += (x - oldX); ///week15_step03_1 改用陣列, 且程式放高一點
    ///angle = x; ///week14_step03-1
    oldX = x;
    oldY = y;
    printf("glTranslatef(%f, %f, 0);\n", teapotX, teapotY);
    glutPostRedisplay(); ///Week13 step03-2
} ///Week13 step03-2
void mouse(int button, int state, int x, int y)
{
    if(state==GLUT_DOWN){
        oldX = x; ///teapotX = (x-150)/150.0;
        oldY = y; ///teapotY = (150-y)/150.0;
        //angle = x;///week15_step03_1
        //printf("glTranslatef(%f, %f, 0);\n", teapotX, teapotY);
        ///if(fout==NULL) fout = fopen("file4.txt", "w"); ///step02-2 沒開檔,就開
        ///fprintf(fout, "%f %f\n", teapotX, teapotY); ///step02-2 要再存座標
    }
    display();
}
//void keyboard(unsigned char key, int x, int y) ///step02-2 keyboard函式
//{
///    if(fin==NULL){ ///step02-2 如果檔案還沒 fopen(), 就開它
///        fclose(fout); ///前面mouse會開fout指標, 所以要關掉
///        fin = fopen("file4.txt", "r"); ///step02-2 沒開檔,就開
//    }
///    ///fscanf(fin, "%f %f", &teapotX, &teapotY); ///step02-2 真的讀檔
//    display(); ///step02-2 重畫畫面
//}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week15");

    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMotionFunc(motion); ///Week13 step03-3
    glutKeyboardFunc(keyboard); ///step02-2 keyboard要做事囉(開檔、讀檔)

    glutMainLoop();
}
