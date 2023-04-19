///week10_glm_gundam �M�� ��week10_glm ���{��, ���ӥ�!
#include <GL/glut.h>
#include "glm.h" ///�U�� source.zip �� glm.h �� week10_glm_gundam �ؿ���
///glm.c ���ɦW�� glm.cpp ��b week10_glm_gundam �ؿ���
///�� glm.cpp �[��M�׸�
///�A�� Gundam.obj Gundam.mtl Diffuse.jpg ���u�@����ؿ�
GLMmodel * pmodel = NULL;///���@�Ӽҫ�������,���O�Ū�!
///Step03-1 �A��W��week07�W�ұЪ� �K�� ���ӥ�
///1. OpenCV 2.1 �˦n (�ୱ/�����t�Ѯv) �O�o�[PATH,�A���}CodeBlocks
///2. �]�w�G�y Settings-Compiler
///3. �� myTexture ���{�����ӥ�!
///4. �b glutCreateWindow()����, �[�@�� myTexture("Diffuse.jpg");
///   glmDraw(pmodel, GLM_MATERIAL | GLM_TEXTURE);
#include <opencv/highgui.h> ///�ϥ� OpenCV 2.1 ���²��, �u�n�� High GUI �Y�i
#include <opencv/cv.h>
#include <GL/glut.h>
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCVŪ��
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV���m (�ݭncv.h)
    glEnable(GL_TEXTURE_2D); ///1. �}�ҶK�ϥ\��
    GLuint id; ///�ǳƤ@�� unsigned int ���, �s �K��ID
    glGenTextures(1, &id); /// ����Generate �K��ID
    glBindTexture(GL_TEXTURE_2D, id); ///�j�wbind �K��ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// �K�ϰѼ�, �W�L�]�˪��d��T, �N���жK��
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// �K�ϰѼ�, �W�L�]�˪��d��S, �N���жK��
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// �K�ϰѼ�, ��j�ɪ�����, �γ̪��I
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// �K�ϰѼ�, �Y�p�ɪ�����, �γ̪��I
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}
float angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    if(pmodel==NULL){
        pmodel = glmReadOBJ("Gundam.obj");///Step03-1
        glmUnitize(pmodel);
        glmFacetNormals(pmodel);
        glmVertexNormals(pmodel, 90);
    }
    glPushMatrix();
        glRotatef(angle, 0, 1, 0);
        glmDraw(pmodel, GLM_MATERIAL | GLM_TEXTURE);
    glPopMatrix();
    angle++;
    ///glutSolidTeapot( 0.3 );
    glutSwapBuffers();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week10");

    myTexture("Diffuse.jpg");
    glEnable(GL_DEPTH_TEST);

    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutMainLoop();
}
