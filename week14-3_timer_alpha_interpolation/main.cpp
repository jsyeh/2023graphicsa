///Week14-3_timer_alpha_interpolation
#include <GL/glut.h>
float angle=0, oldAngle=0, newAngle=0; ///step02-1 宣告變數
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        glutSolidTeapot( 0.3 );
    glPopMatrix();
    glutSwapBuffers();
}
void timer(int t) ///step01-1 你的 timer()函式,做對應動作
{
    if(t<100) glutTimerFunc(50, timer, t+1); ///step02-1 在100之內,設定下一個鬧鐘
    float alpha = t/ 100.0;///step02-1 alpha 介於0.00~1.00之間
    angle = newAngle*alpha + (1-alpha) * oldAngle; ///step02-1 alpha內插公式
    glutPostRedisplay(); ///重畫畫面
}
void motion(int x, int y) ///step02-1
{
    angle = x; ///step02-1 即時更新角度
    glutPostRedisplay(); ///step02-1 重畫畫面
}
void mouse(int button, int state, int x, int y) ///step02-1
{
    if(state==GLUT_DOWN) oldAngle = x; ///step02-1 按下去
    if(state==GLUT_UP) newAngle = x; ///step02-1 放開來
    glutPostRedisplay(); ///step02-1 重畫畫面
}
void keyboard(unsigned char key, int x, int y)
{
    glutTimerFunc(0, timer, 0);
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week14");

    glutDisplayFunc(display);
    glutMouseFunc(mouse); ///step02-1 按下去,表示起點, 放開來,表示終點
    glutMotionFunc(motion); ///step02-1 當mouse在motion時,即時更新畫面
    glutKeyboardFunc(keyboard); ///step01-2 用 keyboard()

    glutMainLoop();
}
