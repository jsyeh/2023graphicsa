# 2023graphicsa
2023電腦圖學 資傳二甲 程式倉庫

# Week01
電腦圖學 Week01 2023-02-15
1. What 這門課會學到什麼 (用期末作品來思考, 三個圈圈, blog)
2. How 如何學 (錄影、截圖、實作、Blog、GitHub)
3. 成績: 期中考10%  & 平時90%(Blog20%, Moodle(作業/考試)40%, 期末作品40%)
4. 點名/座位表, moodle, blogger, facebook
5. 第1個 OpenGL程式
6. W08清明、期中考、期末作品展示
7. 回家完成 HW1

## step01-1 介紹課程、設定Blog

https://2023graphicsa.blogspot.com

標題: 你的品牌 - 第幾週 - 什麼主題 

標籤tags: 學號_姓名, Week01

(要加上逗號)

 每一週,只發1篇文章: 往右(發布), 往左(回來繼續編輯)

## step02-1_第一個程式, 利用 CodeBlocks開發OpenGL程式

今天的第一個程式, 是用 CodeBlocks 17.12 新增 OpenGL專案

File-New-Project, 選 OpenGL Project

下一步, 點點點,選目錄在桌面, 再加上專案名字 week01-1_OpenGL

執行, 便能看到轉動的彩色三角形

## step02-2_第二個程式, 利用 CodeBlocks 開發 GLUT 專案
step02-2_第二個程式, 利用 CodeBlocks 開發 GLUT 專案

File-New-Project-GLUT Project

要把 freeglut解壓縮、把 lib 目錄中的 libfreeglut.a 複製成 libglut32.a。

專案設成 week01-1_GLUT 並把剛剛桌面的 freelut 目錄設到 glut 設定中, 便能看到6個轉動中的紅色3D模型。

## step03-1_第三個部分,在Chrome中試著跑 WebGL的範例

https://madebyevan.com/webgl-water/

## step03-2_ 把今天的程式, 上傳到 GitHub

- 0. 在 GitHub 新增倉庫+ New repository
- 0.1. 名字: 2023graphicsa
- 0.2. 介紹專案: 2023電腦圖學 資傳二甲 XXX 的程式倉庫
- 0.3. (重要)勾 README.md 
- 0.4. (重要)選 .gitignore 對應 C++
- 0.5. 完成 (做一次就好)

- 1. 裝好 Git 軟體
- 1.1. 在桌面的「葉正聖老師上課軟體」裡
- 1.2. 20個下一步
- 1.3. 開啟 Git Bash

- 2. 在 Git Bash 小黑裡, 下指令 (要小心空格)
- 2.1. cd desktop (改一下目錄)
- 2.2. git clone https://github.com/帳號/2023graphicsa (只能做一次)
- 2.3. cd 2023graphicsa (把雲端GitHub下載下來後,進入目錄) 
- 2.4. start .  (一個小數點,可開啟檔案總管)

- 3. 把今天的 2個程式的目錄, 放進去!
- 3.1. 記得 CodeBlocks 要先存檔!
- 3.2. 把程式 copy 到你桌面的 2023graphics 目錄裡

- 4. 在 Git Bash 小黑裡, add 加進去
- 4.1. git status (會顯示紅色)
- 4.2. git add . (把你的這個 2023graphics 現在的目錄,加進去)
- 4.3. git status (會顯示綠色)

- 5. 在 Git Bash 裡, commit (確認、同意、認可) 附上你的 message
- 5.0. git config --global user.email jsyeh@mail.mcu.edu.tw
- 5.0. git config --global user.name jsyeh
- 5.1. 要設定好後, 才知道你是誰Who you are, 才能執行下一行
- 5.1. git commit -m "第一週的OpenGL和GLUT專案"

- 6. 推送上雲端
- 6.1. git push
- 6.2. 要記得先在 Chrome 裡, 登入你的 GitHub


# Week02

電腦圖學 2023-02-22 Week02
1. 主題: 點、線、面、色彩
2. 親手打造 GLUT 程式
3. 實作: glColor3f(r,g,b); glVertex2f(x,y); 實心茶壼、形狀
4. 回家作業: 20+ 頂點

## step01-1_File-New-Project,GLUT專案,點點點選桌面,week02_GLUT_first 第一個專案的名字。在檔案總管裡,把桌面-葉正聖老師的 freeglut壓緒檔點開,裡面的freeglut資料夾複製到桌面,再把 lib的libfreeglut.a複製成libglut32.a 便可在CodeBlocks繼續,完成。老師帶大家看177行程式碼..

請複製程式 10行
```cpp
#include <GL/glut.h>
void display()
{
	glutSolidTeapot( 0.3 );
	glutSwapBuffers();
}

int main(int argc, char *argv[])
{ ///上面是特別的 main()函式, 有很多參數
    glutInit(&argc, argv); ///把 GLUT 開起來
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    ///上面這行,把顯示的模式設定好!	
	glutCreateWindow("GLUT Shapes"); ///要開視窗
	glutDisplayFunc(display); ///要顯示的對應函式
	glutMainLoop(); ///最後用 main迴圈,壓在最後面
}
```

## step01-2_有了基礎的10行程式碼,我們嘗試加上色彩 glColor3f(r,g,b) 比如說 glColor3f(1,1,0) 是黃色。再配合不同大小的茶壼,便能看到比較多變化的程式

```cpp
#include <GL/glut.h>
void display()
{
    glColor3f(0,1,0); ///step01-2 綠色
    glutSolidTeapot( 0.5 ); ///step01-2 畫出一個實心的大茶壼, 它的大小 0.5

    glColor3f(1,1,0); ///step01-2 黃色
    glutSolidTeapot( 0.3 ); ///step01-1 畫出一個實心的小茶壼, 它的大小 0.3
    glutSwapBuffers(); ///step01-1 請GLUT把畫面swap送到顯示的地方
}
int main(int argc, char *argv[])
{ ///step01-1 上面是特別的 main()函式, 有很多參數
    glutInit(&argc, argv); ///step01-1 把 GLUT 開起來
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); ///上面這行,把顯示的模式設定好!
	glutCreateWindow("GLUT Shapes"); ///step01-1 要開視窗
	glutDisplayFunc(display); ///step01-1 要顯示的對應函式
	glutMainLoop(); ///step01-1 最後用「主要的迴圈」,卡在最後面
}
```

## step02-1_有了色彩,今天的第二個重點是頂點Vertex, 對應的程式是 glVertex2f(x,y); 有3個頂點,包在 glBegin(GL_POLYGON) 及 glEnd() 中間, 便能繪製出3角形。座標要注意要開、不能共線,才畫得出來。

```cpp
#include <GL/glut.h>
void display()
{
    glColor3f(0,1,0); ///step01-2 綠色
    ///glutSolidTeapot( 0.5 ); ///step01-2 畫出一個實心的大茶壼, 它的大小 0.5
    glBegin(GL_POLYGON); ///開始畫多邊形
        glVertex2f( 0, 1); ///頂點 Vertex
        glVertex2f(-1,-1); ///頂點 Vertex
        glVertex2f(+1,-1); ///頂點 Vertex
    glEnd(); ///結束畫

    glColor3f(1,1,0); ///step01-2 黃色
    glutSolidTeapot( 0.3 ); ///step01-1 畫出一個實心的小茶壼, 它的大小 0.3
    glutSwapBuffers(); ///step01-1 請GLUT把畫面swap送到顯示的地方
}
int main(int argc, char *argv[])
{ ///step01-1 上面是特別的 main()函式, 有很多參數
    glutInit(&argc, argv); ///step01-1 把 GLUT 開起來
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); ///上面這行,把顯示的模式設定好!
	glutCreateWindow("GLUT Shapes"); ///step01-1 要開視窗
	glutDisplayFunc(display); ///step01-1 要顯示的對應函式
	glutMainLoop(); ///step01-1 最後用「主要的迴圈」,卡在最後面
}
```

## step02-2_其實每一個頂點,都可以有自己的色彩, 也就是一行裡,同時寫2行的程式 glColor3f(r,g,b); glVertex2f(x,y) 配合往右一個TAB縮排,方便理解

```cpp
#include <GL/glut.h>
void display()
{
    ///glColor3f(0,1,0); ///step01-2 綠色
    ///glutSolidTeapot( 0.5 ); ///step01-2 畫出一個實心的大茶壼, 它的大小 0.5
    glBegin(GL_POLYGON); ///step02-1 開始畫多邊形
        glColor3f(1,0,0);  glVertex2f( 0, 1); ///紅色的頂點 Vertex step02-2
        glColor3f(0,1,0);  glVertex2f(-1,-1); ///綠色的頂點 Vertex step02-2
        glColor3f(0,0,1);  glVertex2f(+1,-1); ///藍色的頂點 Vertex step02-2
    glEnd(); ///step02-1 結束畫

    glColor3f(1,1,0); ///step01-2 黃色
    glutSolidTeapot( 0.3 ); ///step01-1 畫出一個實心的小茶壼, 它的大小 0.3
    glutSwapBuffers(); ///step01-1 請GLUT把畫面swap送到顯示的地方
}
int main(int argc, char *argv[])
{ ///step01-1 上面是特別的 main()函式, 有很多參數
    glutInit(&argc, argv); ///step01-1 把 GLUT 開起來
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); ///上面這行,把顯示的模式設定好!
	glutCreateWindow("GLUT Shapes"); ///step01-1 要開視窗
	glutDisplayFunc(display); ///step01-1 要顯示的對應函式
	glutMainLoop(); ///step01-1 最後用「主要的迴圈」,卡在最後面
}
```

## step02-3_回家作業,要用很多個頂點來畫圖。老師挑了一張皮卡丘的圖來示範, 可利用大的正方形先畫出背景, 再畫你的圖形。可用小畫家的滴管+色彩編輯器來挑顏色,再除255.0便能換算到0到1間的浮點數。座標可用「減一半、除一半、y變負的」來找到頂點

```cpp
#include <GL/glut.h>
void display()
{
    glColor3f(247/255.0, 247/255.0, 247/255.0);
    glBegin(GL_POLYGON);
        glVertex2f( 1, 1);
        glVertex2f(-1, 1);
        glVertex2f(-1,-1);
        glVertex2f( 1,-1);
    glEnd();

    glColor3f(244/255.0, 209/255.0, 33/255.0);
    glBegin(GL_POLYGON);
        glVertex2f( (45-100)/100.0, -(134-100)/100.0 );
        glVertex2f( (36-100)/100.0, -(171-100)/100.0 );
        glVertex2f( (108-100)/100.0, -(179-100)/100.0 );
        glVertex2f( (104-100)/100.0, -(117-100)/100.0 );
        ///口訣:減一半、除一半、y變負號
    glEnd();

    glutSwapBuffers(); ///step01-1 請GLUT把畫面swap送到顯示的地方
}
int main(int argc, char *argv[])
{ ///step01-1 上面是特別的 main()函式, 有很多參數
    glutInit(&argc, argv); ///step01-1 把 GLUT 開起來
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); ///上面這行,把顯示的模式設定好!
	glutCreateWindow("GLUT Shapes"); ///step01-1 要開視窗
	glutDisplayFunc(display); ///step01-1 要顯示的對應函式
	glutMainLoop(); ///step01-1 最後用「主要的迴圈」,卡在最後面
}
```

## step03-1_有個挑戰,要如何利用glVertex2f()畫出一個圓。暗示1可用迴圈2行來做,便不用畫很多頂點,想像100邊形, 暗示2與cos()及sin()有關,暗示3與直角三角形有關。畫出單位圓後,發現x與cos()有關, y與sin()有關。配合PI 3.1415926 的兩倍來寫迴圈,最後改成自訂函式myCircle()及參數r,x,y等

```cpp
///Week02-3_circle_cos_sin
#include <GL/glut.h>
#include <math.h> ///cos() 和 sin() 要用
void myCircle(float r, float x, float y)
{
    glBegin(GL_POLYGON); ///step02-1 開始畫多邊形
    for(float a = 0; a< 2*3.1415926; a+=0.01){
        glVertex2f( r*cos(a)+x, r*sin(a)+y );
    }
    glEnd(); ///step02-1 結束畫
}
void display()
{
    glColor3f(1,0,1); myCircle( 0.6, 0, 0 ); ///正中間

    glColor3f(1,0,0); myCircle( 0.3, 0.5, 0.5 ); ///右上角
    glColor3f(0,1,0); myCircle( 0.3,-0.5, 0.5 ); ///左上角
    glColor3f(1,1,0); myCircle( 0.3,-0.5,-0.5 ); ///左下角
    glColor3f(0,0,1); myCircle( 0.3, 0.5,-0.5 ); ///右下角

    glutSwapBuffers(); ///step01-1 請GLUT把畫面swap送到顯示的地方
}
int main(int argc, char *argv[])
{ ///step01-1 上面是特別的 main()函式, 有很多參數
    glutInit(&argc, argv); ///step01-1 把 GLUT 開起來
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); ///上面這行,把顯示的模式設定好!
	glutCreateWindow("GLUT Shapes"); ///step01-1 要開視窗
	glutDisplayFunc(display); ///step01-1 要顯示的對應函式
	glutMainLoop(); ///step01-1 最後用「主要的迴圈」,卡在最後面
}
```

## step03-2_把程式備份到GitHub

0. 安裝 Git
1. 開 GitBash, 進入desktop桌面, clone複製, 進入 2023graphicsa
2. start . 可開檔案總管,把今天的程式放進來
3. 把今天的修改 git add . 加進帳冊 (用 git status 會有紅色 or 綠色)
4. 用 commit 配上 commit message 確認、認可你的修改
	- 4.0. git config --global user.email jsyeh@mail.mcu.edu.tw
	- 4.0. git config --global user.name jsyeh
	- 4.0. 第一次上傳前, 要設定上面的 user.email 及 user.name (who you are...)
	- 4.1. git commit -m "add week02"
5. 用 push 推送上雲端


# Week03

## step01-0_介紹上週作業&blog的問題, 介紹今天的上課主題

## step01-1_下載上課的資料,執行 Transformation.exe 範例,了解上課的主題 Transform

https://jsyeh.org/3dcg10/
下載
- data data.zip
- win32 windows.zip
- glut32.dll

解壓縮
- windows.zip => 下載\windows\Transformation.exe
- data.zip    => 下載\windows\data\很多模型檔

執行今天的課本範例 Transformation.exe
(若有閃退,就是 data 解錯目錄了)

執行時, 可移動 x y z 的座標


## step01-2_了解Translate的意思後,我們從上週的10行GLUT程式出發, 先加glTranslate(x,y,z) 讓它下面的茶壼移動, 再把 glPushMatrix()放前面、glPopMatrix() 放後面, 把它們包起來

- 先把 freeglut 裝好
- File-New-Project, GLUT專案, 命名 week03-1_transalte 專案
- 把 177行的範例刪掉, 改成上週的10行程式
- 加上 glTranslatef(x, y, z) 把茶壼往右移
- 前面加上 glPushMatrix(); 
- 後面加上 glPopMatrix();

```cpp
///程式碼全刪,換我們上週教的10行
#include <GL/glut.h>
void display()
{
    glPushMatrix(); ///備份矩陣
        glTranslatef( 0.5, 0, 0 ); ///只有這行?還不夠
        glutSolidTeapot( 0.3 );
    glPopMatrix(); ///還原矩陣

    glutSwapBuffers();
}
int main(int argc, char* argv[] )
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week03");

    glutDisplayFunc(display);

    glutMainLoop();
}
```

## step02-1_想用mouse讓它可以一直動,所以需要研究如何有mouse的函式。先在 main()裡面加上 glutMouseFunc(mouse); 註冊它, 再回到前面寫下 void mouse(int button, int state, int x, int y){ } 裡面則是利用 printf() 來印出值, 認識這些參數。前面要記得 include stdio.h 哦

```cpp
///程式碼全刪,換我們上週教的10行
#include <GL/glut.h>
void display()
{
    glPushMatrix(); ///step01-2 備份矩陣
        glTranslatef( 0.5, 0, 0 ); ///step01-2 只有這行?還不夠
        glutSolidTeapot( 0.3 );
    glPopMatrix(); ///step01-2 還原矩陣

    glutSwapBuffers();
}
#include <stdio.h>
void mouse(int button, int state, int x, int y)
{ ///step02-1 請 mouse函式幫忙
    printf("%d %d %d %d\n", button, state, x, y);
}
int main(int argc, char* argv[] )
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week03");

    glutDisplayFunc(display);
    glutMouseFunc(mouse); ///step02-1 請 mouse函式幫忙

    glutMainLoop();
}

```

## step02-2_有了step02-1的mouse的幫忙,我們在最前面先宣告global 變數 float X=0, Y=0; 利用它來傳值。在 void display()裡面, 利用 glTranslatef(X, Y, 0) 來移動到想要的位置。而 void mouse()裡面, 則是換算出 X 及 Y 的座標, 使用減一半、除一半、y負號的技巧。

```cpp
///程式碼全刪,換我們上週教的10行
#include <GL/glut.h>
float X=0, Y=0;///step02-2 利用 global 變數,在函式之間傳值 (大寫的)
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); ///step02-2 清背景
    glPushMatrix(); ///step01-2 備份矩陣
        glTranslatef( X, Y, 0 ); ///step01-2 只有這行?還不夠
        glutSolidTeapot( 0.3 );
    glPopMatrix(); ///step01-2 還原矩陣

    glutSwapBuffers();
}
///#include <stdio.h> ///step02-1 為了 printf()
void mouse(int button, int state, int x, int y) ///小寫的
{ ///step02-1 請 mouse函式幫忙
    X = (x-150)/150.0; ///printf("%d %d %d %d\n", button, state, x, y);
    Y = -(y-150)/150.0; ///step02-2 口訣: 減一半、除一半, y負號
}///step02-1 印出來 printf()
int main(int argc, char* argv[] )
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week03");

    glutDisplayFunc(display);
    glutMouseFunc(mouse); ///step02-1 請 mouse函式幫忙

    glutMainLoop();
}
```

## step02-3_老師示範 GitHub 的 Gist功能, 只要在 gist.github.com 裡面 + 新增一個不公開的小程式, 便能經由 embedded 的 HTML JavaScript的方法, 把程式用很漂亮的格式,放在你的 blog 裡。只是你要熟 HTML CSS 才能運作順利。

```html
<script src="https://gist.github.com/jsyeh/21455b1bcf237a4870e6a6cb980cb0b4.js"></script>
```

## step03-1_關於上週出的作業, 其實也可以利用 mouse 來幫忙描點哦。只要在 void mouse() 裡面 if(state==GLUT_DOWN) 再印出你換算出來的座標, 便能幫你寫出程式碼

```cpp
#include <GL/glut.h>
#include <stdio.h>
void display()
{
    ///glutSolidTeapot( 0.3 );
    glBegin(GL_POLYGON);
    glVertex2f(-0.268, 0.160);
    glVertex2f(-0.304, 0.204);
    glVertex2f(-0.332, 0.264);
    glVertex2f(-0.352, 0.384);
    glVertex2f(-0.344, 0.484);
    glVertex2f(-0.308, 0.532);
    glVertex2f(-0.236, 0.552);
    glVertex2f(-0.204, 0.496);
    glVertex2f(-0.204, 0.404);
    glVertex2f(-0.204, 0.348);
    glVertex2f(-0.180, 0.280);
    glVertex2f(-0.156, 0.228);
    glVertex2f(-0.156, 0.212);
    glVertex2f(-0.152, 0.188);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(0.040, 0.200);
    glVertex2f(0.032, 0.248);
    glVertex2f(0.028, 0.328);
    glVertex2f(0.028, 0.404);
    glVertex2f(0.040, 0.480);
    glVertex2f(0.064, 0.540);
    glVertex2f(0.096, 0.572);
    glVertex2f(0.152, 0.616);
    glVertex2f(0.208, 0.604);
    glVertex2f(0.260, 0.524);
    glVertex2f(0.240, 0.468);
    glVertex2f(0.192, 0.428);
    glVertex2f(0.164, 0.384);
    glVertex2f(0.152, 0.328);
    glVertex2f(0.148, 0.276);
    glVertex2f(0.148, 0.244);
    glVertex2f(0.140, 0.212);
    glVertex2f(0.140, 0.188);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-0.196, 0.044);
    glVertex2f(-0.188, 0.068);
    glVertex2f(-0.112, 0.096);
    glVertex2f(-0.060, 0.096);
    glVertex2f(-0.048, 0.068);
    glVertex2f(-0.088, 0.048);
    glVertex2f(-0.140, 0.032);
    glVertex2f(-0.188, 0.032);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.212, 0.152);
    glVertex2f(-0.256, 0.116);
    glVertex2f(-0.272, 0.064);
    glVertex2f(-0.300, -0.084);
    glVertex2f(-0.292, -0.140);
    glVertex2f(-0.220, -0.224);
    glVertex2f(-0.124, -0.252);
    glVertex2f(0.080, -0.260);
    glVertex2f(0.156, -0.256);
    glVertex2f(0.224, -0.224);
    glVertex2f(0.264, -0.160);
    glVertex2f(0.288, -0.152);
    glVertex2f(0.284, 0.004);
    glVertex2f(0.256, 0.092);
    glVertex2f(0.232, 0.164);
    glVertex2f(0.068, 0.180);
    glVertex2f(0.000, 0.192);
    glVertex2f(-0.144, 0.176);
    glEnd();
    glutSwapBuffers();
}
void mouse(int button, int state, int x, int y) ///小寫的
{
    float X = (x-250)/250.0;
    float Y = -(y-250)/250.0; ///口訣: 減一半、除一半, y負號
    if(state==GLUT_DOWN){  ///只有按下mouse,才印出程式,等下要剪貼!
        printf("    glVertex2f(%.3f, %.3f);\n", X, Y);
    }
}
int main(int argc, char* argv[] )
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
    glutInitWindowSize(500,500);
    glutCreateWindow("week03");

    glutDisplayFunc(display);
    glutMouseFunc(mouse); ///step02-1 請 mouse函式幫忙

    glutMainLoop();
}
```


## step03-2_畫出中華民國的國旗
```cpp
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
void rect(float x1, float y1, float x2, float y2)
{
    glBegin(GL_POLYGON);
        glVertex2f(x1,y1); glVertex2f(x1,y2); glVertex2f(x2,y2); glVertex2f(x2, y1);
    glEnd();
}
void circle(float x, float y, float r)
{
    glBegin(GL_POLYGON);
    for(float a=0; a<3.1415926*2; a+=0.01){
        glVertex2f(x+r*cos(a), y+r*sin(a));
    }
    glEnd();
}
float pinX[12], pinY[12], baseX[12], baseY[12];
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,0,0); rect(-0.9, -0.6, +0.9, +0.6);
    glColor3f(0,0,1); rect(-0.9, +0.6, 0, 0);
    glColor3f(1,1,1);
    for(int i=0; i<12; i++){
        float angle = 2*3.1415926*i/12;
        pinX[i] = -0.45+cos(angle)*0.9/4;
        pinY[i] = 0.30+sin(angle)*0.9/4;
        baseX[i] = -0.45+cos(angle-0.2618)*0.9/8*(1+2.0/15);
        baseY[i] = 0.30 + sin(angle-0.2618)*0.9/8*(1+2.0/15);
    }
    for(int i=0; i<12; i++){
        glBegin(GL_POLYGON);
        glVertex2f(baseX[i], baseY[i]);
        glVertex2f(pinX[i], pinY[i]);
        glVertex2f(baseX[(i+1)%12], baseY[(i+1)%12]);
        glEnd();
    }
    glColor3f(0,0,1); circle(-0.45, +0.3, 0.9/8*(1+2.0/15));
    glColor3f(1,1,1); circle(-0.45, +0.3, 0.9/8);

    glutSwapBuffers();
}
int main(int argc, char* argv[] )
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
    glutInitWindowSize(800, 800);
    glutCreateWindow("week03");
    glutDisplayFunc(display);
    glutMainLoop();
}

```

## step03-3_利用Git將今天的程式碼上傳

- 0. 安裝 Git, 開啟 Git Bash
- 1. 進入桌面,用 git clone 下載 2023graphicsa, 再進入 2023graphicsa
- 2. start . 可以開檔案總管, 整理今天的2個程式
- 3. 用 git add . 將修改加入帳冊 (git status 會秀紅色or綠色)
- 4. 用 git commit -m "你的訊息" 來確認、認可你的修改 (要先git config 設定名字及email)
- 5. 用 git push 推送上雲端

# Week04

電腦圖學 2023-03-08 Week04
1. 主題: 旋轉 Rotate
2. 實作: glRotatef(角度, x, y, z);
3. 主題: 矩陣 Matrix
4. 利用 mouse motion 來控制

## step01-1_下載課本的範例 跑Transformation.exe 試著了解今天的主題「旋轉Rotate」對應的glRotatef(角度, x, y, z) 的意思

- https://jsyeh.org/3dcg10/
- 下載 windows.zip => 下載\windows\Transformation.exe
- 下載 data.zip    => 下載\windows\data\模型

## step01-2_前面了解x軸轉、y軸轉, 現在要用 glRotatef(角度, 0, 0, 1); 了解對z軸轉的意思。首先要了解z軸怎麼出來的, 是用右手座標系統, 把手掌從x掃到y時, 由姆指的方向決定z軸的方向。再來是真的旋轉時, 右手姆指當旋轉軸, 再看你的其餘4指是往哪個方向轉

## step01-3_接下來是應用的時間。如果是X軸旋轉、如果是Y軸旋轉、如果是Z軸旋轉,都試過一次。最後的難題, 是如果旋轉軸是 (1,1,0) 這個斜斜的旋轉軸, 請問人會怎麼轉, 技巧是想像買鹹酥雞時, 那個竹籤是旋轉軸的話, 你插下去的鹹酥雞會怎麼轉動, 一樣使用右手「按個讚」來想像它怎麼轉動


## step02-0_實作, File-New-Project, GLUT專案(要先把桌面的freeglut目錄變出來,把lib目錄裡的libfreeglut.a 複製成 libglut32.a), 存 week04-1_rotate 專案


## step02-1_接下來,把今天教的 glRotatef(angle, 0, 1, 0) 拿來用, 記得前後要有 glPushMatrix() 及 glPopMatrix() 包起來。最前面宣告全域變數 float angle=0; 在 display() 最後面 angle++ 改變它。在 glutDisplayFunc(display)的旁邊加上 glutIdleFunc(display) 讓它有空idle時,就呼叫 display() 重畫畫面。

```cpp
///看了程式之後, 把程式先備份在 Notepad++ 等一下可以參考
///再把上週的程式 copy 過來
///程式碼全刪,換我們上週教的10行
#include <GL/glut.h>
float angle = 0; ///step02-1 宣告global全域變數 angle
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); ///清背景
    glPushMatrix(); ///step02-1 備份矩陣
        glRotatef(angle, 0, 1, 0); ///step02-1 旋轉 angle 角度
        glutSolidTeapot( 0.3 );
    glPopMatrix();  ///step02-1 還原矩陣
    glutSwapBuffers();
    angle++; ///step02-1 把角度++
}
int main(int argc, char* argv[] )
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week04");

    glutDisplayFunc(display);
    glutIdleFunc(display); ///step02-1 有空idle時,就重畫畫面
    glutMainLoop();
}
```

## step02-2_想要加上打光的效果, 有20行程式要加進去, 不過可以copy。week04-2_rotate_light 在程式中, Ctrl-F 找到 light 相關的程式。目前看起來會比較暗,而且轉的方向好像反過來,請別擔心, 之後會改好。

```cpp
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };
```

```cpp
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
```

```cpp

///把 week04-1_rotate 的程式, copy 來 week04-2_rotate_light
///再把177行範例的 2段程式加進來
#include <GL/glut.h>
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

void myLight()
{
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
}

float angle = 0; ///step02-1 宣告global全域變數 angle
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); ///清背景
    glPushMatrix(); ///step02-1 備份矩陣
        glRotatef(angle, 0, 1, 0); ///step02-1 旋轉 angle 角度
        glutSolidTeapot( 0.3 );
    glPopMatrix();  ///step02-1 還原矩陣
    glutSwapBuffers();
    angle++; ///step02-1 把角度++
}
int main(int argc, char* argv[] )
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week04");

    glutDisplayFunc(display);
    glutIdleFunc(display); ///step02-1 有空idle時,就重畫畫面

    myLight(); ///step02-2 我們自己寫一個 myLight()函式, 裡面有很多行!
    glutMainLoop();
}
```

## step02-3_加點色彩 glColor3f(r,g,b) 另外有 glClearColor(r,g,b,a) 用來清背景的色彩

```cpp
float angle = 0; ///step02-1 宣告global全域變數 angle
void display()
{
    glClearColor(1,1,1,1); ///Step02-3 用來清背景的色彩 R,G,B,A
    ///(目前GLUT_RGB不會用到 A)
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); ///清背景
    glPushMatrix(); ///step02-1 備份矩陣
        glRotatef(angle, 0, 1, 0); ///step02-1 旋轉 angle 角度
        glColor3f(1,1,0); ///step02-3 加點色彩
        glutSolidTeapot( 0.3 );
    glPopMatrix();  ///step02-1 還原矩陣
    glutSwapBuffers();
    angle++; ///step02-1 把角度++
}
```

## step03-1_這兩週教的移動、旋轉,程式碼如果對調, 結果會不一樣, 可在今天第一節課的範例裡, 在下方按右鍵, 選 swap translate rotate 交換移動、旋轉的這兩行。要想一套方法,來理解 在邊邊孤獨的轉(自轉)、繞著正中心轉(公轉)

## step03-2_試著在 week04-3_rotate_translate的範例裡, 把兩行程式交換看看

口訣「左耳靠左肩」讓程式從下往上讀。

```
茶壼
```

```
黃色的茶壼
```

```
旋轉黃色的茶壼
```

```
移動那個「旋轉中的黃色茶壼」
```

再看另一個程式

```
茶壼
```

```
紅色的茶壼
```

```
放在右邊的紅色茶壼
```

想像在吃喜宴時的紅色大圓桌,有個盤子會轉
```
旋轉整個桌子「放在右邊的紅色茶壼」
```


## step03-3_Git備份程式到GitHub
- 0. 安裝 Git 開 Git Bash
- 1. 進入桌面 cd desktop  複製下來 git clone 你的網址, 進入 2023graphisa
- 2. 開啟檔案總管 start .  整理你今天的程式
- 3. 把修改加到帳冊 git add .
- 4. 確認你的修改 git commit -m "add week04" 
- 5. 推送上雲端 git push


# Week05
1. 主題: T-R-T 對特定軸轉動
2. 複習: 移動-旋轉 vs 旋轉-移動, 縮放
3. 主題: 矩陣 Matrix 1 2 3 4 5
4. 實作: 機器手臂的轉動

## step01-0_老師介紹 Blogger, GitHub, Leetcode, 累積你的作品

## step01-1_看課本的範例, 下載 jsyeh.org 的 3dcg10 裡的範例, 重新理解 T-R vs. R-T 的差別。 理解程式碼的方法 左耳碰左肩 從下往上讀。我們試出了「移動到右邊的」「轉動」「長胖的」「藍色的車子」

```cpp
glTranslatef(0.7, 0, 0); //移動到右邊的
glRotatef(轉轉轉, 0, 1, 0); //轉動
glScalef(1.5, 1, 1); //長胖的
glBegin(...); //藍色的車子
```


## step01-2_如果把範例的 Translate與Rotate交換的話, 則是另一個故事。轉動那行, 其實一直都是把整個世界繞著中心轉動。移動的效果, 是把整個世界往右移動。程式碼的順序不同時, 結合出來的效果不同。你可以用吃喜宴辦桌時, 桌上的大圓盤來思考, 車子被稿到右邊後, 轉動的結果, 好像有一盤菜, 在大家的面前繞世界一圈

```cpp
glRotatef(轉轉轉, 0, 1, 0); //轉動
glTranslatef(0.7, 0, 0); //移動到右邊的
glScalef(1.5, 1, 1); //長胖的
glBegin(...); //藍色的車子
```

## step02-1_要開啟CodeBlocks新增GLUT專案,存成 week05-1_TRT_rotate_translate 讓它轉動出效果(對Z軸)。在程式碼裡, 對Z軸轉動, 還有往右移動。但順序不同, 分別用不同的紅色、綠色畫出的茶壼,來看最後一步造成的效果

```cpp
///Week05-1_TRT_rotate_translate 對z軸轉
///先把你上週的 week04-1 拿來用 (GitHub上面有哦)
#include <GL/glut.h>
float angle = 0;
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); ///清背景

    glColor3f(0, 1, 0); ///綠色的
    glPushMatrix();
        glTranslatef(0.8, 0, 0); ///最後是綠色的移動
        glRotatef(angle, 0, 0, 1); ///改對z軸轉
        glutSolidTeapot( 0.3 );
    glPopMatrix();

    glColor3f(1, 0, 0); ///紅色的
    glPushMatrix();
        glRotatef(angle, 0, 0, 1);  ///改對z軸轉 ///最後是紅色的轉動
        glTranslatef(0.8, 0, 0);
        glutSolidTeapot( 0.3 );
    glPopMatrix();

    glutSwapBuffers();
    angle++; ///step02-1 把角度++
}
int main(int argc, char* argv[] )
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week04");

    glutDisplayFunc(display);
    glutIdleFunc(display); ///step02-1 有空idle時,就重畫畫面
    glutMainLoop();
}

```

## step02-2_想要了解TRT,老師寫了一個展示練習的程式, 可以在裡面畫圖ToDraw, 也可以把程式碼 像板子一樣,在右邊移動程式的順序。按空白鍵時, angle 會自動增加。點選右邊的 glTranslatef()後,再點左邊可改變glTranslatef()裡面的值, 用這種方法, 試著移動你畫出來的手臂。最後的成品, 是 T-R-T 

```cpp
myDrawObject(0); ///畫出我們的身體與頭
glPushMatrix();
	glTranslatef(+0.18, +0.28, 0); //(3) 最後,把會轉動的手臂,掛在肩膀上
	glRotatef(angle, 0, 0, 1);     //(2) 再世界對z軸轉,手臂擺好後,剛好像關節在轉
	glTranslatef(-0.18, -0.28, 0); //(1) 把旋轉中心,放在正中心
	myDrawObject(1); //我們要轉動的手臂
glPopMatrix();
myDrawObject(2); //不小心畫錯了, 當沒看到
```

## step03-1_介紹 T-R-T 考試(佔一個小作業)

以10702-16202電腦圖學 的考題(奇異博士用手拿著寶石)為例, 講解程式怎麼轉

```cpp
glPushMatrix();
glTranslatef(-0.5,-0.9,0); //(3) 最後,把轉動的手肘,掛到正確的位置
glRotate(-45,0,0,1);  //(2) 轉動,要小心正負號 還有轉動軸
glTranslatef(-0.8,0.9,0); // 把手肘中心,放到世界中心
drawHand();
glPopMatrix();
```

## step03-2_新開GLUT專案 week05-2_TRT_robot 要畫出手臂轉動的樣子。使用的技巧 T-R-T 的步驟, 先把旋轉中心放在正中心, 再轉動, 最後把整個手臂掛在對應的位置。

```cpp
///Week05-2_TRT_robot 程式來自 week05-1_TRT_rotate_translate
///畫出大的身體、畫出手臂
#include <GL/glut.h>
float angle = 0;
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); ///清背景

    glColor3f(0, 1, 0); ///綠色的身體
    glPushMatrix();
        glutSolidCube(0.5);

        glPushMatrix();
            glTranslatef(0.25, 0.25, 0);///(3)把整個東西,掛在右上角
            glRotatef(angle, 0, 0, 1);  ///(2)轉動
            glTranslatef(0.25, 0.25, 0);///(1)把旋轉中心,放到中心
            glColor3f(1,0,0); ///紅色的手臂
            glutSolidCube(0.5);
        glPopMatrix();
    glPopMatrix();

    glutSwapBuffers();
    angle++; ///step02-1 把角度++
}
int main(int argc, char* argv[] )
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week04");

    glutDisplayFunc(display);
    glutIdleFunc(display); ///step02-1 有空idle時,就重畫畫面
    glutMainLoop();
}
```

## step03-3_把程式用Git指令上傳到GitHub
- 0. 安裝 Git 開啟 Git Bash
- 1. 進入桌面 cd desktop 雲端複製下載 git clone https://網址 進入目錄 cd 2022graphcsa
- 2. 開啟檔案總管 start . 整理你的程式(複製)
- 3. 加入修改 git add .
- 4. 確認 git commit -m "week05"   (小心, 要先講「你是誰」 git config --global user.email ... 和 user.name
- 5. 推送上雲端 git push

# Week06

## step01-1_為了複習考試題目,我們先寫week06-1_TRT_robot2,了解T-R-T的觀念是怎麼建出來的。先貼上週的 week05-2_TRT_robot 再慢慢建出程式碼。比較不同的,在正中心多了一個glutSolidSphere(0.02, 30, 30) 的圓球, 方便你校正

```cpp
///貼上上週的week05-2_TRT_robot
#include <GL/glut.h>
float angle = 0;
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    glutSolidSphere(0.02, 30, 30); ///正中心的圓球

    glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        glTranslatef( 0.46, -0.05, 0 ); ///(1) 把轉動的中心,放中心
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
```


## step01-2_剛剛正確轉動的茶壼,可以掛在任意你想要放的位置。有了這些觀念, 便可以進行T-R-T特定軸轉動的小考了。



```cpp
///Week06-1_TRT_robot2 貼上上週的week05-2_TRT_robot
#include <GL/glut.h>
float angle = 0;
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    glutSolidSphere(0.02, 30, 30); ///正中心的圓球

    glPushMatrix();
        glTranslatef(-0.5, 0.5, 0);     ///(3) 掛上去
        glRotatef(angle, 0, 0, 1);      ///(2) 就可以轉動了
        glTranslatef( 0.46, -0.05, 0 ); ///(1) 把轉動的中心,放中心
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
```

## step02-1_想要了解階層轉動(Hierarchy) 其實就是很多組的T-R-T配合 push pop 所以 week06-2_TRT_robot3_hierarchy, 把剛剛設定正確轉動的茶壼,掛在另一個茶壼的嘴上

```cpp
///Week06-2_TRT_robot_hierarchy 改自 Week06-1
///很多不同的連結狀況, 而且手臂會帶手肘轉動
#include <GL/glut.h>
float angle = 0;
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    glutSolidSphere(0.02, 30, 30); ///正中心的圓球

    glutSolidTeapot(0.3); ///step02-1 身體

    glPushMatrix();
        ///step02-1 先註解掉 ///glTranslatef(-0.5, 0.5, 0);     ///(3) 掛上去
        glTranslatef(0.49, 0.13, 0); ///step02-2 新的
        glRotatef(angle, 0, 0, 1);      ///(2) 就可以轉動了
        glTranslatef( 0.46, -0.05, 0 ); ///(1) 把轉動的中心,放中心
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
```

## step02-2_要更多層的轉動。可以想像 glPushMatrix() 和 glPopMatrix()很像是程式的大括號, 裡面要往右退一格。外面的動作,會影響到裡面跟著轉動。

```cpp
///Week06-2_TRT_robot_hierarchy 改自 Week06-1
///很多不同的連結狀況, 而且手臂會帶手肘轉動
#include <GL/glut.h>
float angle = 0;
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    ///glutSolidSphere(0.02, 30, 30); ///正中心的圓球
    glutSolidTeapot(0.3); ///step02-1 身體

    glPushMatrix(); ///右手臂
        ///step02-1 先註解掉 ///glTranslatef(-0.5, 0.5, 0);     ///(3) 掛上去
        glTranslatef(0.49, 0.13, 0); ///step02-2 新的
        glRotatef(angle, 0, 0, 1);      ///(2) 就可以轉動了
        glTranslatef( 0.46, -0.05, 0 ); ///(1) 把轉動的中心,放中心
        glutSolidTeapot(0.3);

        glPushMatrix(); ///右手肘
            glTranslatef(0.49, 0.13, 0); ///step02-2 新的
            glRotatef(angle, 0, 0, 1);      ///(2) 就可以轉動了
            glTranslatef( 0.46, -0.05, 0 ); ///(1) 把轉動的中心,放中心
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
```

## step02-3_要再開一個新的程式week06-3_TRT_robot_arm_hand_left_right,改用上週的 glutSolidCube() 變形成長方形, 慢慢建出它的 T-R-T 多層的關係, 有左手邊的手臂、手肘等。先把簡單的部分做好, 同時發明drawHand()函式幫忙, 讓 display()裡面不要太複雜。

```cpp
///Week06-3_TRT_robot_arm_hand_right_left 從上週的 week05-2 拿來用
///畫出大的身體、畫出手臂
#include <GL/glut.h>
float angle = 0;
void drawHand()
{
    glPushMatrix();
        glScalef(1, 0.3, 0.3);
        glutSolidCube(0.5);
    glPopMatrix();
}
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); ///清背景

    glPushMatrix();
        ///(3) 要掛上去
        glRotatef(angle, 0,0,1);  ///(2) 轉動
        glTranslatef(0.25, 0, 0); ///(1) 把中心,放在正中心
        drawHand();
    glPopMatrix();

    glutSwapBuffers();
    angle++; ///step02-1 把角度++
}
int main(int argc, char* argv[] )
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week04");

    glutDisplayFunc(display);
    glutIdleFunc(display); ///step02-1 有空idle時,就重畫畫面
    glutMainLoop();
}
```

## step03-1_想要一層層掛上去, 要怎麼做呢 先把上手臂的 T-R-T都先註解掉,上手臂擺好不要動,才能正確把下手肘「掛正確」。接下來再修改, 讓上手臂也掛在正確的位置動起來

```cpp
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); ///清背景

    glPushMatrix();
        ///(3) 要掛上去
        ///glRotatef(angle, 0,0,1);  ///(2) 轉動
        ///glTranslatef(0.25, 0, 0); ///(1) 把中心,放在正中心
        ///step03-1 把前面的T-R-T都先註解掉,會較好理解
        drawHand(); ///上手臂
        glPushMatrix();
            ///(3) 要掛上去
            glRotatef(angle, 0,0,1);  ///(2) 轉動
            glTranslatef(0.25, 0, 0); ///(1) 把中心,放在正中心
            drawHand();
        glPopMatrix();
    glPopMatrix();

    glutSwapBuffers();
    angle++; ///step02-1 把角度++
}
```

接下來再修改, 讓上手臂也掛在正確的位置動起來

```cpp
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); ///清背景

    glPushMatrix();
        glTranslatef(0.25, 0, 0); ///(3) 要掛上去
        glRotatef(angle, 0,0,1);  ///(2) 轉動
        glTranslatef(0.25, 0, 0); ///(1) 把中心,放在正中心
        ///step03-1 把前面的T-R-T都先註解掉,會較好理解
        ///設好後, 再把上面的程式解開來
        drawHand(); ///上手臂
        glPushMatrix();
            glTranslatef(0.25, 0, 0); ///(3) 要掛上去
            glRotatef(angle, 0,0,1);  ///(2) 轉動
            glTranslatef(0.25, 0, 0); ///(1) 把中心,放在正中心
            drawHand();
        glPopMatrix();
    glPopMatrix();

    glutSwapBuffers();
    angle++; ///step02-1 把角度++
}
```

## step03-2_今天最後集大成的程式, 是把右半邊的手臂、手肘, 再copy成為左半邊的手臂、手肘。在設定glTranslatef()的參數時, 要想一下到底要動多少。

```cpp
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); ///清背景
    glPushMatrix(); ///右上手臂
        glTranslatef(0.25, 0, 0); ///(3) 要掛上去
        glRotatef(angle, 0,0,1);  ///(2) 轉動
        glTranslatef(0.25, 0, 0); ///(1) 把中心,放在正中心
        ///step03-1 把前面的T-R-T都先註解掉,會較好理解
        ///設好後, 再把上面的程式解開來
        drawHand(); ///右上手臂

        glPushMatrix();///右下手肘
            glTranslatef(0.25, 0, 0); ///(3) 要掛上去
            glRotatef(angle, 0,0,1);  ///(2) 轉動
            glTranslatef(0.25, 0, 0); ///(1) 把中心,放在正中心
            drawHand();///右下手肘
        glPopMatrix();
    glPopMatrix();

    glPushMatrix(); ///左上手臂
        glTranslatef(-0.25, 0, 0); ///(3) 要掛上去
        glRotatef(angle, 0,0,1);  ///(2) 轉動
        glTranslatef(-0.25, 0, 0); ///(1) 把中心,放在正中心
        ///step03-1 把前面的T-R-T都先註解掉,會較好理解
        ///設好後, 再把上面的程式解開來
        drawHand(); ///上手臂

        glPushMatrix();///左下手肘
            glTranslatef(-0.25, 0, 0); ///(3) 要掛上去
            glRotatef(angle, 0,0,1);  ///(2) 轉動
            glTranslatef(-0.25, 0, 0); ///(1) 把中心,放在正中心
            drawHand();///下手肘
        glPopMatrix();
    glPopMatrix();

    glutSwapBuffers();
    angle++; ///step02-1 把角度++
}
```

## step03-3_期中考試複習

https://jsyeh.org/gl 裡面有練習的軟體

```cpp
glPushMatrix(); 備份矩陣
	glTranslatef(x,y,z);//移動
	glRotatef(angle, x, y, z);//轉動
	glScalef(x, y, z);//縮放
	glBegin(GL_POLYGON);//開始畫,可以用其他的參數
		glNormal3f(nx, ny, nz);//打光的法向量
		glTexCoord2f(tx,ty);//貼圖座標
		glColor3f(r,g,c); //顏色
		glVertex2f(x,y);//頂點,也可以寫 glVertex3f(x,y,z);
	glEnd();//結束畫
glPopMatrix(); 還原矩陣
```


## step03-4_利用Git指令,將今天的程式上傳到GitHub

- 0. 安裝 Git 開啟 Git Bash
- 1. 進入桌面 cd desktop 複製專案 git clone https://網址 進入目錄 cd 2023graphicsa
- 2. 開檔案總管 start . 整理你的目錄
- 3. 加入帳冊 git add .
- 4. 確認修改
- 4.0. 先設好 git config --global user.email jsyeh@mail.mcu.edu.tw
- 4.0. 先設好 git config --global user.name jsyeh
- 4.1. 確認修改 git commit -m week06
- 5. 推送上雲端 git push

# Week07

說明: 大家早安,我是葉正聖老師。昨天早上上課上到11點時, 突然沒有聲音, 沒辦法上課。

症狀與就診: 先喉嚨不舒服,週一去看醫生。但週二上課用盡生命點數, 11點就沒聲音了。週二再看醫生, 有換藥, 希望讓聲帶儘量恢復。)

解釋細節: 停止講話20小時後,有恢復一點聲音。但是只要再講2個小時,就會突然沒聲音。所以今天講話會很輕、很小聲、很溫柔。

今天的上課的主題, 與貼圖相關

0. 公布 T-R-T 小考成績

1. 主題: 貼圖 Texture

2. 主題: OpenCV

3. 貼圖 15行程式碼

4. 實作 glTexCoord2f(tx, ty) 貼圖座標



一開始上課前, 先介紹畢業3年的學姐傳訊息說, 在銘傳學電腦圖學對她現在的幫助。




## step01-1_利用上課的教材 jsyeh.org/3dcg10 下載今天的程式 Texture.exe 裡面會去讀圖檔, 並讓大家示範貼圖的一些細節。第一個細節是 glColor3f(r,g,b)的結果, 會與貼圖的結果混在一起。我們已經熟悉glVertex3f(x,y,z)是畫3D點的座標, 在畫之前, 可設定對應的貼圖座標 glTexCoord2f(tx, ty) 而這些程式碼,會放在 glBegin()程 glEnd()中間








## step01-2_想要繼續了解貼圖的運作方式, 所以試著改一個頂點的貼圖座標。如果超過0...1範圍的話, 也會有圖, 目前是用重覆的方式呈現。同時請觀察,四邊形其實會被拆解成2個3角形畫出來。在3D的世界, 圖學都是用3角形來畫, 又快又好, 像 Unity, 3dsMax, 底層的OpenGL等。但人類理解的世界, 4邊形比較好用, 人類好理解, 所以Maya用4邊形。只是匯入遊戲後, 還是3角形在畫







## step01-3_在範例裡, 也可切換貼圖的矩陣Matrix, 這時候 glTranslatef() glRotatef() glScalef()就都會套用到貼圖的座標計算裡。接下來老師複習期中考的10行 OpenGL程式碼, 方便大家下次第10週上課時考期中考



```cpp
1.  glPushMatrix(); //備份矩陣 現在有90分
2.    glTranslatef( x, y, z);//移動
3.    glRotatef(角度, x, y, z);//轉動
4.    glScalef(x, y, z);//縮放
5.    glBegin(GL_POLYGON); //開始畫(多邊形)
6.      glColor3f(r,g,b); //色彩
7.      glNormal3f(nx, ny, nz);//打光的法向量
8.      glTexCoord2f(tx, ty);//貼圖座標
9.      glVertex3f(x,y,z);//頂點
10.   glEnd();//結束畫
11. glPopMatrix(); //還原矩陣
```



## step02-1_為了要做貼圖, 我們需要將圖片讀入。有很多讀圖的方法, 最好的讀圖的方法 OpenCV 用舊版 OpenCV 2.1 在桌面,請點葉正聖老師上課軟體, 安裝 OpenCV-2.1.0-win32-vs2008.exe 這個程式, 第2步 Add PATH 一定要設, 用原來的目錄 C的OpenCV2.1目錄。請把 CodeBlocks重開!!!要寫人生中第一個 OpenCV程式, 最常遇到「設定出錯」的問題。設定法: Setting-Compiler, 有３個咒語要下， Search directory搜尋的目錄(Compiler include, linker lib), 及 Linker setting cv210 cxcore210 highgui210

1. Compiler: C:\OpenCV2.1\include
2. Linker: C:\OpenCV2.1\lib
3. 在 Linker setting裡, 要加 3個名字: cv210 cxcore210 highgui210 要很小心,不要拼錯了



## step02-2_最簡單的三行程式碼,使用 CodeBlocks File-New-Empty空白檔案, 存檔成 week07-1_opencv_cvLoadImage_cvShowImage.cpp 注意副檔名要 .cpp 不能是 .c 。寫下下面3行程式。記得把你的圖檔放在程式執行的同一個目錄裡, 圖的副檔名 要和程式裡一樣。這樣就會秀圖了。

```cpp
#include <opencv/highgui.h>
int main()
{
    IplImage * img = cvLoadImage("檔名.png");
    cvShowImage("week07", img);
    cvWaitKey(0);
}
```
OpenCV非常好用, 之前老師有寫一個 ResizeCam 的程式, 可以開視訊、利用 mouse wheel 來縮放視窗, 就是用 OpenCV 寫的 https://github.com/jsyeh/ResizeCam



## step03-1_接下來要在我們的 GLUT專案裡, 使用圖片來貼圖, 安裝好 freeglut 後, 新增GLUT專案 week07-2_myTexture, 程式從 gist.github.com/jsyeh 裡找下 myTexture 的範例, 拿 sample 來用。圖檔比較麻煩, 因為歷史原因, GLUT專案的工作執行目錄藏在 桌面的 freeglut 的 bin裡面, 所以把 earth.jpg 世界地圖的圖檔放在那裡。



```cpp
///Week07-2_myTexture 來自 gist.github.com/jsyeh 裡面 myTexture
///有 sample 可以剪貼,但要小心 earth.jpg 要自己去下載
#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
#include <GL/glut.h>
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCV讀圖
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能
    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID
    glGenTextures(1, &id); /// 產生Generate 貼圖ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// 貼圖參數, 放大時的內插, 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// 貼圖參數, 縮小時的內插, 用最近點
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glutSolidTeapot( 0.3 );
    glutSwapBuffers();
}

int main(int argc, char**argv)
{
    glutInit( &argc, argv );
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week07 texture");

    glutDisplayFunc(display);
    myTexture("earth.jpg");///這個圖檔, 現在不存在
    ///圖檔要放在特別的工作執行目錄

    glutMainLoop();
}
```

## step03-2_今天第1節課有教 glTexCoord2f(tx,ty) 的貼圖座標設定, 我們就把那個茶壼的貼圖, 把它改成有貼圖的部分。



```cpp
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    ///glutSolidTeapot( 0.3 );
    glBegin(GL_POLYGON);
        glTexCoord2f(0, 0); glVertex2f(-1, +1);
        glTexCoord2f(1, 0); glVertex2f(+1, +1);
        glTexCoord2f(1, 1); glVertex2f(+1, -1);
        glTexCoord2f(0, 1); glVertex2f(-1, -1);
    glEnd();
    glutSwapBuffers();
}
```

## step03-3_要做出會旋轉的世界地球,在 gist.github.com的jsyeh找到myEarth的範例,把它拿來用, 要記得把圖檔放在工作執行目錄(以原本的GLUT專案為例,會在 freeglut的bin目錄裡。檔名改成 earth.jpg 就可以看到地球在旋轉了。

```cpp
///Week07-3_myEarth, 來自 gist.github.com/jsyeh 的 myEarth
///把程式最下面的 myEarth.jpg 改成你的 earth.jpg
#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
#include <GL/glut.h>
GLUquadric * sphere = NULL;///一個指到二次曲面的指標
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCV讀圖
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能
    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID
    glGenTextures(1, &id); /// 產生Generate 貼圖ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// 貼圖參數, 放大時的內插, 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// 貼圖參數, 縮小時的內插, 用最近點
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}
float angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glRotatef(angle, 0,-1,0);
        glRotatef(90, 1,0,0);
        gluQuadricTexture(sphere, 1);
        gluSphere(sphere, 1, 30, 30);///glutSolidTeapot(0.3);
    glPopMatrix();
    glutSwapBuffers();
    angle++;
}
int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week10 texture background");

    glutIdleFunc(display);
    glutDisplayFunc(display);
    myTexture("earth.jpg");
    sphere = gluNewQuadric();
    glEnable(GL_DEPTH_TEST);

    glutMainLoop();
}
```


## step03-4_使用Git指令上傳GitHub

- 0. 安裝 Git 再開啟 Git Bash
- 1. cd desktop 進入桌面 git clone https://網址 , 再 cd 2023graphicsa
- 2. start .   (注意那個點)開啟檔案總管, 整理你的程式(有兩個目錄、1個獨立的.cpp檔)
- 3. git add .    (注意那個點)加到帳冊
- 4.0. git config --global user.email jsyeh@mail.mcu.edu.tw
- 4.0. git config --global user.name jsyeh
- 4.1 git commit -m week07
- 5. git push

# Week08
清明連假

# Week09
期中考週
 
# Week10

電腦圖學 2023-04-19 Week10
1. 期中考-OpenGL必背10函式
2. 主題: 3D模型
3. 主題: OBJ檔
4. 主題: glm.h glm.cpp
5. 實作: Gundam 剛彈模型

## step01-1_認識3D模型。先從jsyeh.org的3dcg10下載老師的範例, 跑 Transformation.exe 會把 data 目錄中的 3D模型畫出來。3D模型對應的OBJ檔,會再引用 .mtl 檔對應 material 材質。OBJ檔裡的v對應vertex頂點, vt對應 vertex texture 貼圖座標, vn 對應 vertex normal 打光要用的法向量。 f是點線面的面, 會需要 3個頂點 or 4個以上的頂點。

- https://jsyeh.org/3dcg10/

## step01-2_接下來老師帶大家看 OBJ格式的Wikipedia維基百科的介紹,裡面有說明#註解, v頂點, vt貼圖座標, vn法向量, f面。另外看到它的歷史, 是從 wavefront 到 alias (開發maya的公司),最後被Autodesk併購。接著, 老師介紹課本範例裡 transformation.c 使用了 glm.c 及 glm.h 來簡化讀OBJ模型檔的程式。
 
- https://zh.wikipedia.org/zh-tw/Wavefront_.obj%E6%96%87%E4%BB%B6
- https://en.wikipedia.org/wiki/Wavefront_.obj_file
- https://en.wikipedia.org/wiki/Wavefront_Technologies
- https://en.wikipedia.org/wiki/Alias_Systems_Corporation
- https://en.wikipedia.org/wiki/Autodesk

## step02-1_接下來要寫自己的專案, 準備好GLUT後, 開 GLUT專案 week10_glm, 裡面先放10行程式。再把 source.zip 裡 glm.h 與 glm.c 放到 week10_glm 目錄裡, glm.c 改成 glm.cpp。再把 3D 模型放到工作執行目錄裡。接下來便可模仿 transformation.c 的程式, 找裡面 glm 出現的地方, 把 include 弄好, 把指標 pmodel 宣告, 再把 display() 裡讀模型、畫模型的程式弄好。

```cpp
///請把之前的 10行 GLUT程式拿來用
#include <GL/glut.h>
#include "glm.h" ///下載 source.zip 有 glm.h 放 week10_glm 目錄裡
///glm.c 改檔名成 glm.cpp 放在 week10_glm 目錄裡
///把 glm.cpp 加到專案裡
///把模型檔 (ex. Al.obj Al.mtl ... ) 複製到 工作執行目錄
/// Build log 最後一行會說它在哪裡 (in C:\Users\.....\freeglut\bin)
///最後, 把模型檔畫出來....
GLMmodel * pmodel = NULL;///有一個模型的指標,先是空的!
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    if(pmodel==NULL){
        pmodel = glmReadOBJ("Al.obj");
        glmUnitize(pmodel);
        glmFacetNormals(pmodel);
        glmVertexNormals(pmodel, 90);
    }
    glmDraw(pmodel, GLM_MATERIAL);
    ///glutSolidTeapot( 0.3 );
    glutSwapBuffers();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week10");

    glutDisplayFunc(display);
    glutMainLoop();
}
```

## step03-1_想要做出有貼圖的Gundam模型, 新增week10_glm_gundam 專案 把week10_glm 的程式拿來用。把Gundam.obj Gundam.mtl Diffuse.jpg 放到工作執行目錄, 把 OpenCV2.1 裝好, 設定好 3個咒語, 把 myTexture 程式拿來用, 在 glutCreateWindow()後, 加入 myTexture("Diffuse.jpg") 並把 GLM_TEXTURE加入glmDraw()裡。就可以做出 Gundam模型了。

```cpp
///week10_glm_gundam 專案 把week10_glm 的程式, 拿來用!
#include <GL/glut.h>
#include "glm.h" ///下載 source.zip 有 glm.h 放 week10_glm_gundam 目錄裡
///glm.c 改檔名成 glm.cpp 放在 week10_glm_gundam 目錄裡
///把 glm.cpp 加到專案裡
///再把 Gundam.obj Gundam.mtl Diffuse.jpg 放到工作執行目錄
GLMmodel * pmodel = NULL;///有一個模型的指標,先是空的!
///Step03-1 再把上次week07上課教的 貼圖 拿來用
///1. OpenCV 2.1 裝好 (桌面/葉正聖老師) 記得加PATH,再重開CodeBlocks
///2. 設定咒語 Settings-Compiler
///3. 把 myTexture 的程式拿來用!
///4. 在 glutCreateWindow()之後, 加一行 myTexture("Diffuse.jpg");
///   glmDraw(pmodel, GLM_MATERIAL | GLM_TEXTURE);
#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
#include <GL/glut.h>
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCV讀圖
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能
    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID
    glGenTextures(1, &id); /// 產生Generate 貼圖ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// 貼圖參數, 放大時的內插, 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// 貼圖參數, 縮小時的內插, 用最近點
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
```



## step03-2_Git指令備份程式
- Git Bash 
- 複製下來 git clone https://網址
- git add .
- 設定 git config --global user.email jsyeh@mail.mcu.edu.tw
- 設定 git config --global user.name jsyeh
- git commit -m week10
- git push



# Week11

## step01-1_為了試鍵盤keyboard,新開GLUT專案,week11-1_keyboard, 裡面會有 glutKeyboardFunc(keyboard) 會去叫用 void keyboard(), 呼叫 exit(0) 程式就結束,並return 0

File-New-Project, GLUT專案

```cpp
///Week11-1_keyboard 學習自GLUT專案的範例
#include <GL/glut.h>
void display()
{
    glutSolidTeapot( 0.3 );
    glutSwapBuffers();
}
void keyboard(unsigned char key, int x, int y)
{///step01-1 今天新教的
    if(key==27) exit(594088); ///學習自GLUT專案的範例
} ///ESC就會結束
int main(int argc, char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week11");


    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);///step01-1 今天新教的

    glutMainLoop();
}

```


## step01-2_兩種音樂格式 wav(檔案大,直播播放,簡單) mp3(檔案小,有壓縮,難一點點) 用Notepad++可看檔案前面的3-4個英文單字,代表格式。最簡單播放的是 wav。新GLUT專案 week11-2_keyboard_wav_PlaySound。最前面要 include windows.h 而呼叫 PlaySound("檔名", NULL, SND_ASYNC); 便能播放。其中NULL代表這個播放音樂沒有掛在任何物件下。SND_ASYNC不等待同步,所以播放會馬上繼續。

PlaySoundA()

## step02-1_為了讓大家更了解 PlaySound()的用法, 我們改用大一上教的 File-New-Empty File 空白檔案來示範。寫了 include windows.h 及 PlaySound() 卻出現 link 時 PlaySoundA找不到的問題。原因是 Linker Settings要加1個咒語 winmm 就可以了。這裡改用 SND_SYNC 要等待同步, 以免程式瞬間結束。另外老師講解「絕對路徑」與「相對路徑」的差別。都可以。

```cpp
///Week11-3_PlaySound.cpp 可是它卻不能執行 因為找不到 PlaySoundA
///C:\Users\Administrator\Desktop\week11-3_PlaySound.o:week11-3_PlaySound.cpp:(.text+0x2e):
///  undefined reference to `PlaySoundA@12'
///PlaySoundA() 其實在 winmm 裡面 所以, step02-1 要手動把 winmm 加到 lib 咒語裡
/// 比較: OpenCV 要 3咒語, GLUT 要 5咒語。 PlaySound 要 1咒語
/// Setting-Compiler... 的 Linker Settings 要加上 winmm
#include <windows.h>
int main()
{                         ///要等待同步 SND_SYNC, 不然會瞬間結束
    PlaySound("do_re_mi\\do.wav", NULL, SND_SYNC);
    PlaySound("do_re_mi\\do.wav", NULL, SND_SYNC);
    PlaySound("do_re_mi\\do.wav", NULL, SND_SYNC);
    PlaySound("do_re_mi\\re.wav", NULL, SND_SYNC);
    ///PlaySound("C:\\Users\\Administrator\\Desktop\\do_re_mi\\mi.wav", NULL, SND_SYNC);
}
///Build log 會寫: Checking for existence: C:\Users\Administrator\Desktop\week11-3_PlaySound.exe
///Executing: '"C:\Program Files (x86)\CodeBlocks/cb_console_runner.exe" "C:\Users\Administrator\Desktop\week11-3_PlaySound.exe"' (in 'C:\Users\Administrator\Desktop')
/// 它的執行目錄, 是在 C:\Users\Administrator\Desktop 我們的 do.wav re.wav mi.wav 在 相對目錄裡
```

## step02-0_介紹做筆記的習慣,可以讓學習的效果更好。老師用自己做筆記的幾個例子來說明, 像是學習寫程式、聽演講、學習AI等。這樣之後才會記起來, 而且別人有遇到問題時, 可以有文件幫助別人。

## step02-2_想要試試 MP3檔, 新開GLUT專案 week11-4_glut_mp3 要再用到工具 CMP3_MCI.h 先把檔案放到同一目錄裡, include "CMP3_MCI.h" 雙引號代表同一目錄的檔案。CMP3_MCI myMP3;宣告物件變數, myMP3.Load("檔名.mp3"); 及 myMP3.Play(); 便能播放。目錄的字串裡, 兩個反斜線, 或一個斜線, 都可以。

## step03-1_講解相對目錄、絕對目錄的意思

## step03-2_最後要講一下Git上傳時的 .gitignore 哪些檔案不備份

在 .gitignore 裡面, 要備份 .dll 檔案, 所以要加上 # 不要擋它
```
# *.dll 
# 因為我們希望也備份 libfreeglut.dll 及 opencv的 .dll 才能讓程式執行
```

Git Bash
1. 先 clone 下來, 再編輯 .gitignore
2. 整理今天的程式 week11 的 4個程式
3. git add .
4. git commit -m week11   (之前要 git config --global 設定2個東西)
5. git push


# Week12

電腦圖學 2023-05-03 Week12
1. 主題: 檔案讀寫
2. 主題: 鍵盤、滑鼠控制角度
3. 回家作業: 可控制關節角度的模型

## step01-1_今天教檔案讀寫,先試著開檔、寫檔。之前學過的printf()只要稍做改裝 fprintf(), 便能寫檔案。前面的 f 對應 檔案指標 fout = fopen("檔名", "模式"); 

```cpp
///Week12-1_printf_fprintf.cpp
/// 要能夠寫檔案
#include <stdio.h>

int main()
{///檔案指標 fout = 開檔案("檔名", "用什麼模式")
    FILE * fout = fopen("file.txt", "w");///w:write

    printf("Hello World\n");
    fprintf(fout, "Hello World在檔案裡\n");

}
```

## step01-2_有了 printf() 接下來當然是對應 scanf() 與 fscanf()了。因為剛剛已經有檔案 "file.txt" 所以, 我們可開啟它, 使用 fopen("file.txt", "r") 讀它, 檔案指標換個名字 fin 方便你了解它是 file input 的變數。使用字串去讀它。

```cpp
#include <stdio.h>
int main()
{
    FILE * fin = fopen("file.txt", "r"); ///前一個範例有寫檔了

    char line[100];
    fscanf(fin, "%s", line);
    printf("從file.txt讀到了: %s\n", line);

    fscanf(fin, "%s", line);
    printf("從file.txt讀到了: %s\n", line);
}
```

## step01-3_如果想要在程式中, 又有讀、又有寫,那就要記得 fopen() 配上 fclose()要適時把檔案關起來,讓後面的程式繼續做事。我們期末作品會需要把機器人關節的角度做檔案讀寫, 所以會用 %d 記得在印的時候, 空格、跳行都很重要, 不然數字會黏在一起, 就無法順利讀取了。

```cpp
///Week12-3
#include <stdio.h>
int main()
{
    int a[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int b[10] = {};

    FILE * fout = fopen("file3.txt", "w");
    for(int i=0; i<10; i++){
        printf("%d ", a[i] );
        fprintf(fout, "%d ", a[i] );
    }
    printf("\n");
    fprintf(fout, "\n");
    fclose(fout);

    FILE * fin = fopen("file3.txt", "r");
    for(int i=0; i<10; i++){
        fscanf(fin, "%d", &b[i] );
        printf("b%d:%d ", i, b[i] );
    }
    fclose(fin);
}
```

## step02-1_新的GLUT專案 week12-4_keyboard_mouse 想要用 keyboard mouse 來操控簡單的茶壼。

```cpp
///week12-4_keyboard_mouse 要用 keyboard mouse 來操控茶壼, 而且可存檔、會自己動
#include <stdio.h>
#include <GL/glut.h>
float teapotX=0, teapotY=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glTranslatef(teapotX, teapotY, 0);
        glutSolidTeapot( 0.3 );
    glPopMatrix();
    glutSwapBuffers();
}
void mouse(int button, int state, int x, int y)
{
    if(state==GLUT_DOWN){
        teapotX = (x-150)/150.0;
        teapotY = (150-y)/150.0;
    }
    display();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week12");

    glutDisplayFunc(display);
    glutMouseFunc(mouse);

    glutMainLoop();
}
```

## step02-2_繼續把剛剛的 week12-4_keyboard_mouse 進行改寫, 在按下 mouse 時, 會去寫檔案, 在按下 keyboard 時, 會去讀檔案。如果檔案指標是一開始預設值 NULL 的話, 程式會自己進行 fopen() 把指標放好值。記得檔案要fclose之後, 才能交給下一個指標做另一件事。file4.txt 檔案會在working_dir工作執行目錄裡。

```cpp
///week12-4_keyboard_mouse 要用 keyboard mouse 來操控茶壼, 而且可存檔、會自己動
///在按mosue時,除了改 teapotX, teapotY 座標, 並重畫, 還要再存座標
///存檔時,會在工作執行目錄 working_dir
///在CodeBlocks Project-Properties 裡面的第二個Build targets 下面可以設定
///把它從 C:\Users\Administrator\Desktop\freeglut\bin 改成 . (小數點,現在目錄的意思)
/// 記得, Debug 和 Release 兩個都要改
/// 而且要 File-Save Everything (Ctrl-Shift-S全部存檔)才會將 .cbp 專案檔存檔
#include <stdio.h>
#include <GL/glut.h>
FILE * fout = NULL; ///step02-2 一開始,檔案沒有開, NULL
FILE * fin = NULL; ///step02-2 要讀檔用的指標, 一開始也是 NULL
float teapotX=0, teapotY=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glTranslatef(teapotX, teapotY, 0);
        glutSolidTeapot( 0.3 );
    glPopMatrix();
    glutSwapBuffers();
}
void mouse(int button, int state, int x, int y)
{
    if(state==GLUT_DOWN){
        teapotX = (x-150)/150.0;
        teapotY = (150-y)/150.0;
        if(fout==NULL) fout = fopen("file4.txt", "w"); ///step02-2 沒開檔,就開
        fprintf(fout, "%f %f\n", teapotX, teapotY); ///step02-2 要再存座標
    }
    display();
}
void keyboard(unsigned char key, int x, int y) ///step02-2 keyboard函式
{
    if(fin==NULL){ ///step02-2 如果檔案還沒 fopen(), 就開它
        fclose(fout); ///前面mouse會開fout指標, 所以要關掉
        fin = fopen("file4.txt", "r"); ///step02-2 沒開檔,就開
    }
    fscanf(fin, "%f %f", &teapotX, &teapotY); ///step02-2 真的讀檔
    display(); ///step02-2 重畫畫面
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week12");

    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard); ///step02-2 keyboard要做事囉(開檔、讀檔)

    glutMainLoop();
}
```

## step03-1_工作執行目錄 working_dir 在 freeglut 的 bin 很奇怪, 上週利用 Notepad++ 改到現在專案的目錄 . 好像比較帥。CodeBlocks裡 Project-Properties 裡面第二個 Build targets 裡面可以改。不過改成 . (小數點, 代表現在所在目錄) 後, 執行時竟然出現 freeglut.dll 找不到的歷史餘毒的問題。把 dll 檔手動複製過去, 就可以成功了。

## step03-2_老師本來新開 week12-5_TRT_keyboard_mouse 要再講回家作業, 不過發現一下太難、同學可能聽不懂, 所以臨時把目錄改成 Final_Project 裡面的 Project-Properpties 的 title 也改成 Final_Projet, 專案檔也改成 Final_Project.cbp 以便下週上課時, 可以利用 GitHub 的備份繼續做。

## step03-3_利用Git指令,將今天的程式上傳GitHub

先在 Git Bash 裡, 改變目錄、雲端複製下載
- cd desktop
- git clone https://github.com/你的帳號/2023graphics
- cd 2023graphics

接下來, 要 start . 開檔案總管, 整理目錄
- git status (紅色,可省略)
- git add . 
- git status (綠色,可省略)

接下來要設定你的名字
- git config --global user.email jsyeh@mail.mcu.edu.tw
- git config --global user.name jsyeh

接下來,是 commit 和 push
- git commit -m week12
- git push


# Week13

## step01-1_今天的主題是「綜合練習」,講解今天的任務後,先開啟 Autodesk Maya 來練習,讀入上課用過的 Al.obj 模型 (在data.zip裡), 試著切出幾個部位,方便上課使用 (head.obj body.obj uparmR.obj lowarmR.obj) 

綜合練習
- Maya 裁切模型
	- Alt-左鍵: 旋轉
	- Alt-中鍵: 平移
	- 滾輸: 縮放
	- 左鍵: 選取
	- File-Import 匯入模型
	- File-Export Selection 匯出模型(OBJ)

## step01-2_使用Git把上週的專案下載下來, 並且用 CodeBlocks開啟專案檔, 把 freeglut 也複製到 Final_Project 裡, 並把專案的 include 目錄、lib 目錄, 都重新設定「相對路徑」。(記得 .gitignore也要把 .lib 和 .a 也解開備份機制)

綜合練習 (用舊的專案)
- GitHub上面的 Final Project (2023graphicsa裡)
	- 可用 cd 目錄, 來改變你的目錄
	- git clone https://github.com/jsyeh/2023graphicsa
	- start . 開你現在的目錄
- CodeBlocks 開舊專案 File-Open, 點 Final Project 的 Final_Project.cbp 
	- 要解決 freeglut 每次要安裝的問題, 直接在 Final_Project 也放一份!!! 
	- 把freeglut目錄解在 Final_Project 裡, 把lib的libfreeglut.lib做出 libglut32.a
	- Project-Properties的

## step02-1_模型匯入、組合

- 組合模型
	- 第10週用的 glm.cpp glm.h 都複製到你的 Final_Project 專案裡
	- 在專案裡, Add File, 把 glm.cpp 加進去
	- File-Save everything 才會存檔, 不然會備份到(還沒存檔的)舊檔
	- 把剛剛截切好的 head.obj body.obj uparmR.obj lowarmR.obj 複製到專案的model目錄
- 對應的 glm 程式
	- #include "glm.h"
	- GLMmodel * body = NULL;
	- 在 display()裡面
		- if(body==NULL){
		-   body = glmReadOBJ("model/body.obj");
		-   glmUnitize(body);//這行之後會改
		- }
		- glmDraw(body, GLM_MATERIAL); //這行之後會改

```cpp
#include "glm.h" ///week13 step02-1
GLMmodel * body = NULL; ///week13 step02-1
```

```cpp
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        if(body==NULL){///week13 step02-1
            body = glmReadOBJ("model/body.obj");///week13 step02-1
            glmUnitize(body); ///week13 step02-1 這行之後會改
        }
        glmDraw(body, GLM_MATERIAL);///week13 step02-1這行之後會改
    glPopMatrix();
    glutSwapBuffers();
}
```

## step02-2_想要有更多的模型,要小心模型的大小,因為glmUnitize()之後不要用,所以找到適當大小後, 使用 glScalef(0.2, 0.2, 0.2) 調成五分之一。把模型依序讀入。

- 程式進行修改

```cpp
#include "glm.h" ///week13 step02-1
GLMmodel * head = NULL; ///week13 step02-1
GLMmodel * body = NULL; ///week13 step02-1
```

```cpp
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        if(body==NULL){///week13 step02-1
            body = glmReadOBJ("model/body.obj");///week13 step02-1
            glmUnitize(body); ///week13 step02-1 這行之後會改
        }
		glmDraw(head, GLM_MATERIAL);///Week13 step03-1
		glmDraw(body, GLM_MATERIAL);///week13 step02-1這行之後會改
    glPopMatrix();
    glutSwapBuffers();
}
```

## step03-1_想要用 show[i] 陣列來決定有哪些模型要秀出來

```cpp
#include "glm.h" ///week13 step02-1
GLMmodel * head = NULL; ///week13 step02-1
GLMmodel * body = NULL; ///week13 step02-1
GLMmodel * uparmR = NULL; ///week13 step02-1
GLMmodel * lowarmR = NULL; ///week13 step02-1
int show[4] = {0, 1, 0, 0};/// week13 step03-1 用 show[i] 來決定要不要顯示
```

```cpp
void keyboard(unsigned char key, int x, int y) {/// week13 step03-1
    if(key=='0') show[0] = !show[0];/// week13 step03-1
    if(key=='1') show[1] = !show[1];/// week13 step03-1
    if(key=='2') show[2] = !show[2];/// week13 step03-1
    if(key=='3') show[3] = !show[3];/// week13 step03-1
    glutPostRedisplay();
} ///原來的keyboard先註解、不要用
```

```cpp
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
        if(show[0]) glmDraw(head, GLM_MATERIAL);///Week13 step03-1
        if(show[1]) glmDraw(body, GLM_MATERIAL);///week13 step02-1這行之後會改
        if(show[2]) glmDraw(uparmR, GLM_MATERIAL);///Week13 step03-1
        if(show[3]) glmDraw(lowarmR, GLM_MATERIAL);///Week13 step03-1
    glPopMatrix();
    glutSwapBuffers();
}
```

## step03-2_利用 mouse motion 來看看要移動多少, 才能正確把模型放到對的位置

在 display()裡面
```cpp
        glPushMatrix();
            glTranslatef(teapotX, teapotY, 0);

            if(show[2]) glmDraw(uparmR, GLM_MATERIAL);///Week13 step03-1
        glPopMatrix();
```

```cpp
int oldX = 0, oldY = 0; ///Week13 step03-2
void motion(int x, int y){ ///Week13 step03-2
    teapotX += (x - oldX)/150.0; ///Week13 step03-2
    teapotY -= (y - oldY)/150.0; ///Week13 step03-2
    oldX = x;
    oldY = y;
    printf("glTranslatef(%f, %f, 0);\n", teapotX, teapotY);
    glutPostRedisplay(); ///Week13 step03-2
} ///Week13 step03-2
```

在 int main()裡面
```cpp
    glutMotionFunc(motion); ///Week13 step03-3
```

## step03-3_修改 .gitignore 清單, 把一些檔案也上傳。 
- .gitignore 要記得存檔
	- # 你在前面加 #號 就可以註解掉
	- # 因為我們希望也備份 3D model 檔
	- # *.obj
	- # 因為我們希望也備份 libfreeglut.dll 及 opencv的 .dll 才能讓程式執行
	- # *.dll 
	- # 因為我們希望也備份 freeglut 的 lib 目錄裡的 libfreeglut32.a 等檔案
	- # *.a
	- # *.lib
- git status (紅色)
- git add . (加入備分的清單)
- git status (綠色)
- 要把你的名字、email都設好
- git config --global user.email jsyeh@mail.mcu.edu.tw
- git config --global user.name jsyeh
- git commit -m week13
- git push


# Week14
電腦圖學 2023-05-17 Week14
1. 主題: 切換關節
2. 主題: 切換移動、旋轉
3. 整合打光、貼圖
4. 主題: timer計時器、內插動作


1. 請先裝 Git, 把我們的專案clone下載
	- git clone 你的網址(比較慢)
	- 
2. 今天的程式: timer
	- 先把 freeglut 再裝一次, 先照開學前幾週的作法
	- glutTimerFunc(等多久, timer, 參數);
	- 另外要準備好 void timer(int t) { ... }
	- CodeBlocks: File-New-Project, GLUT專案 week14-1_timer 專案

## step01-1_今天第一個主題, 是學會 timer()計時器的技巧。要用到 glutTimerFunc(等多久, timer, 參數)來設定。等的時間單位是 ms 千分之一秒。在範例裡,執行時會先等2秒鐘,然後開始第一個timer叫醒。timer()會改變angle值, 並更新畫面。巧妙的地方, 在 timer()裡, 又會再設定下一個timer()啟動的時間

```cpp
///Week14-1_timer
#include <GL/glut.h>
float angle=0;
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
    glutTimerFunc(500, timer, t+1); ///step01-1 設定下一個鬧鐘
    angle += 90; ///增加90度
    glutPostRedisplay(); ///重畫畫面
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week14");

    glutDisplayFunc(display);
    glutTimerFunc(2000, timer, 0); ///step01-1 設定timer函式

    glutMainLoop();
}
```

## step01-2_新的專案 week14-2_timer_play 想要改用 keyboard()來觸發 timer() 而不要在 main()裡直接觸發。

```cpp
///Week14-2_timer_play 用鍵盤來播放
#include <GL/glut.h>
float angle=0;
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
    glutTimerFunc(500, timer, t+1); ///step01-1 設定下一個鬧鐘
    angle += 90; ///增加90度
    glutPostRedisplay(); ///重畫畫面
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
    glutKeyboardFunc(keyboard); ///step01-2 用 keyboard()
    ///glutTimerFunc(2000, timer, 0); ///step01-1 設定timer函式

    glutMainLoop();
}
```

## step01-3_利用Excel來示範,什麼是alpha內插, 能用 alpha乘 新+(1-alpha)乘舊

## step02-1_新的專案 week14-3_timer_alpha_interpolation, 裡面增加 mouse() 負責處理按下去、放開來,對應的動作。增加 motion() 負責即時更新角度,讓你看到角度。最後 timer()裡, 想要用 100格的內插, 所以t小於100時,持續設定下一次 timer, 等待的時間不要太久。alpha算出來, 用 alpha 來算出角度的值。

```cpp
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
```

## step02-2_回到Final_Project這個專案, 先利用Git指令, 把前面的 week14-1 到 week14-3 都備份到雲端。接下來, 開啟 Final_Project, 我們想要選定關節, 利用 keyboard()配合 ID變數,來做到。按'0'就把ID=0; 按'1'就把ID=1; 所以在 display()裡, if(ID==0) 就在畫頭的地方設定紅色, else設白色。這樣我們便能挑選不同的關節

```cpp
///week12-5_TRT_keyboard_mouse 要用 keyboard mouse 來操控
#include <stdio.h>
#include <GL/glut.h>
#include "glm.h" ///week13 step02-1
GLMmodel * head = NULL; ///week13 step02-1
GLMmodel * body = NULL; ///week13 step02-1
GLMmodel * uparmR = NULL; ///week13 step02-1
GLMmodel * lowarmR = NULL; ///week13 step02-1
int show[4] = {1, 1, 1, 1};/// week14_step02-2 用 show[i] 來決定要不要顯示
int ID = 0;///0:頭 1身體 2上手臂 3下手臂  ///week14_step02-2
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
} ///原來的keyboard先註解、不要用
FILE * fout = NULL; ///step02-2 一開始,檔案沒有開, NULL
FILE * fin = NULL; ///step02-2 要讀檔用的指標, 一開始也是 NULL
float teapotX=0, teapotY=0; ///幫我們看移動值
float angle=0, angle2=0, angle3=0;///step03-2 擺動作
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
        
            glTranslatef(teapotX, teapotY, 0);

            if(ID==2) glColor3f(1,0,0); ///選定的,設紅色
            else glColor3f(1,1,1); ///沒選定,設白色
            if(show[2]) glmDraw(uparmR, GLM_MATERIAL);///Week13 step03-1
        glPopMatrix();

        if(ID==3) glColor3f(1,0,0); ///選定的,設紅色
        else glColor3f(1,1,1); ///沒選定,設白色
        if(show[3]) glmDraw(lowarmR, GLM_MATERIAL);///Week13 step03-1
    glPopMatrix();
    glutSwapBuffers();
}
int oldX = 0, oldY = 0; ///Week13 step03-2
void motion(int x, int y){ ///Week13 step03-2
    teapotX += (x - oldX)/150.0; ///Week13 step03-2
    teapotY -= (y - oldY)/150.0; ///Week13 step03-2
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
        angle = x;
        ///printf("glTranslatef(%f, %f, 0);\n", teapotX, teapotY);
        ///if(fout==NULL) fout = fopen("file4.txt", "w"); ///step02-2 沒開檔,就開
        ///fprintf(fout, "%f %f\n", teapotX, teapotY); ///step02-2 要再存座標
    }
    display();
}
//void keyboard(unsigned char key, int x, int y) ///step02-2 keyboard函式
//{
//    if(fin==NULL){ ///step02-2 如果檔案還沒 fopen(), 就開它
//        fclose(fout); ///前面mouse會開fout指標, 所以要關掉
//        fin = fopen("file4.txt", "r"); ///step02-2 沒開檔,就開
//    }
//    ///fscanf(fin, "%f %f", &teapotX, &teapotY); ///step02-2 真的讀檔
//    display(); ///step02-2 重畫畫面
//}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week12");

    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMotionFunc(motion); ///Week13 step03-3
    glutKeyboardFunc(keyboard); ///step02-2 keyboard要做事囉(開檔、讀檔)

    glutMainLoop();
}
```

## step03-1_利用 teapotX, teapotY 來協助找到 T-R-T 的關鍵 glTranslatef()的值, 讓旋轉中心能正確定位。這樣能做一正確旋轉的上手臂。再利用 glPushMatrix() glPopMatrix() 加深一層後, 把下手臂也做出來。

```cpp
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
} ///原來的keyboard先註解、不要用
FILE * fout = NULL; ///step02-2 一開始,檔案沒有開, NULL
FILE * fin = NULL; ///step02-2 要讀檔用的指標, 一開始也是 NULL
float teapotX=0, teapotY=0; ///幫我們看移動值
float angle=0, angle2=0, angle3=0;///step03-2 擺動作
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
            glRotatef(angle, 0, 0, 1); ///week14_step03-1_TRT建出來
            //glTranslatef(teapotX, teapotY, 0); ///week14_step03-1_TRT建出來
            glTranslatef(1.200000, -0.453333, 0); ///week14_step03-1_的結果

            if(ID==2) glColor3f(1,0,0); ///選定的,設紅色
            else glColor3f(1,1,1); ///沒選定,設白色
            if(show[2]) glmDraw(uparmR, GLM_MATERIAL);///Week13 step03-1
            glPushMatrix();
                glTranslatef(-1.959999, +0.113333, 0);
                glRotatef(angle, 0, 0, 1);
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
        ///if(fout==NULL) fout = fopen("file4.txt", "w"); ///step02-2 沒開檔,就開
        ///fprintf(fout, "%f %f\n", teapotX, teapotY); ///step02-2 要再存座標
    }
    display();
}
//void keyboard(unsigned char key, int x, int y) ///step02-2 keyboard函式
//{
//    if(fin==NULL){ ///step02-2 如果檔案還沒 fopen(), 就開它
//        fclose(fout); ///前面mouse會開fout指標, 所以要關掉
//        fin = fopen("file4.txt", "r"); ///step02-2 沒開檔,就開
//    }
//    ///fscanf(fin, "%f %f", &teapotX, &teapotY); ///step02-2 真的讀檔
//    display(); ///step02-2 重畫畫面
//}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week12");

    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMotionFunc(motion); ///Week13 step03-3
    glutKeyboardFunc(keyboard); ///step02-2 keyboard要做事囉(開檔、讀檔)

    glutMainLoop();
}
```

# Week15
電腦圖學 2023-05-24 Week15
1. 主題: 攝影機 Camera
2. 主題: 投影、運鏡  gluPerspective(), gluLookAt()
3. 期末作品

## step01-1_今天上課的重點是攝影機, 所以我們從課本的範例 jsyeh.org 的 3dcg10 下載 windows.zip 及 data.zip, 解壓縮好, 執行 Projection.exe 來看看攝影機的一些設定。首先是測試 gluLookAt()的9個參數, 前3個是eye眼睛的座標(從哪裡看), 中間3個是center座標(看哪裡)



## step01-2_在 gluLookAt()的最後3個參數, 是 up 向量。前面的 eye, center 會決定攝影機的一個軸線, 從 eye 射向 center。不過要完整決定你的矩陣時, 還有一個變化的, 就是攝影機照著軸線, 再 360度轉動。這個就由 up 向量來決定。舉例來說, 拍照時, 直拍、橫拍,  up 向量就不一樣。有時候斜拍, up向量就向著斜斜的方向。有了 9個參數, 便能決定攝影機是怎麼拍攝的。


## step01-3_接下來介紹課本範例裡的 gluPerspective()裡面的參數。這些字其實不是英文, 而是專有名詞的縮寫。 fov 是 field of view 視野, 也就是你看到的角度範圍。 fovy 是在 y方向的 fov。如果 fov的角度越大, 則東西自然就會變小。如果fov的角度越小, 則目光如豆, 看到的東西佔的比例就變大。 aspect 是 aspect ratio 長寬比的意思, 通常要對應你的視窗的長度、寬度, 來決定你的 aspect 的值要設多少。 zNear zFar 是在 z方向的近的切一刀、遠的切一刀, 決定哪個範圍裡的內容會被投影到方塊裡, 再壓扁畫出來。

fovy: field of view (y方向) 視野的角度
aspect: aspect ratio 長寬比


## step02-1_開啟 GLUT 專案 week15-1_gluPerspective 要試試看 gluPerspective()的參數。在 GLUT 專案的範例裡, 有個 resize()函式, 裡面會有 glFrustum()函式, 設好左右上下前後的邊界, 變成一個透視投影的矩陣。(在開 GLUT專案時, 我們已經進化, 先使用 Git 把 GitHub 的倉庫 clone 複製下來, 所以在硬碟裡的 2023graphicsa 已經有 freeglut 可以用, 所以方便很多。)

## step02-2_在 week15-1_gluPerspective的範例裡, 我們試著把GLUT專案範例裡的 resize()裡的 glFrustum() 改成 glOrtho() 看看「透視投影」與「垂直投影」的差別。

```cpp
static void resize(int width, int height)
{
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);  ///week15_step02_02 切換成投影矩陣
    glLoadIdentity(); ///week15_step02_02 還原成單位矩陣
    ///glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);
    ///glOrtho(-ar*3, ar*3, -1*3, 1*3, -100, +100);
    gluPerspective(60, ar, 0.01, 1000);
///week15_step02_02 角度, 比例, 近的, 遠的


    glMatrixMode(GL_MODELVIEW);   ///week15_step02_02 切換成 Model View 矩陣
    glLoadIdentity(); ///week15_step02_02 還原成單位矩陣
}
```

## step02-3_新增GLUT專案 week15-2_gluLookAt, 要把今天教的觀念都實作看看。首先是先寫出10行精簡的GLUT程式, 增加 glutReshapeFunc(reshape) 讓它可在調整視窗長寬時, 修改 glViewport()看到的2D範圍, 再利用 glMatrixMode()來切換投影矩陣、model view矩陣。投影矩陣裡, 先用identity矩陣, 再設定gluPerspective(60, ar, 0.01, 1000)設好透視投影。但變成一片白茫茫, 因為你困在白色茶壼裡, 所以需要在 model view 裡, 設定 gluLookAt() 把你的 camera 設好。

## step02-4_再增加motion()函式, 看看 gluLookAt()隨著mouse motion時,改變攝影機的位置, 也就是計算出 eyeX 與 eyeY 的值, 再去改變 gluLookAt()的參數

```cpp
///Week15-2_glutLookAt
///函式 reshape(), display(), 再加上 motion() 幫我們把 camera動來動去
#include <GL/glut.h>
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glutSolidTeapot( 0.3 );
    glutSwapBuffers();
}
void reshape(int w, int h) {

    glViewport(0, 0, w, h); ///視窗裡,會看到的2D範圍

    float ar = w / (float) h; ///aspect ratio 長寬比

    glMatrixMode(GL_PROJECTION); ///先切換到 Project 矩陣
    glLoadIdentity(); ///矩陣清空,成為單位矩陣(最一開始的矩陣)
    gluPerspective(60, ar, 0.01, 1000); ///現在一片空白,因為我們在茶壼裡

    glMatrixMode(GL_MODELVIEW); ///做好後, 馬上切回 model view 矩陣
    glLoadIdentity(); ///矩陣清空,成為單位矩陣(最一開始的矩陣)
    gluLookAt(0,0,1,  0,0,0,  0,1,0);
    ///在0,0,1 看著茶壼0,0,0, up是0,1,0
    glutPostRedisplay();
}
float eyeX = 0, eyeY = 0;
void motion(int x, int y) {
    eyeX = (x-150.0)/150.0;
    eyeY = (150.0-y)/150.0;
    glMatrixMode(GL_MODELVIEW); ///做好後, 馬上切回 model view 矩陣
    glLoadIdentity(); ///矩陣清空,成為單位矩陣(最一開始的矩陣)
    gluLookAt(eyeX, eyeY, 1,  0,0,0,  0,1,0);
    glutPostRedisplay();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week15");

    glutMotionFunc(motion);///
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);///老師把名字變reshape

    glutMainLoop();
}
```

## step03-1_把期末作品的範例拿來再練習一下, 把原本的 float angle=0; 改成陣列 float angle[20]={}; 再把 display()裡,每個關節的部分, 對應不同的 angle[i] 的值, 而 motion() 裡則是 angle[ID] += x-oldX;

```cpp
///Week15_step03_1 程式用陣列: (模型組合好了)切換不同的關節,要改變不同的角度
/// int angle[20]; angle[0] angle[1] ...  用它們來旋轉
/// motion()時, 用 angle[ID]來改
```

```cpp
float angle[20] = {};///week15_step03_1 變陣列
```

```cpp
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
```

```cpp
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
```


## step03-2_把期末作品裡, keyboard()裡 if(key=='s') 裡面利用迴圈來寫檔,把20個陣列的值,都在到檔案裡。 if(key=='r')則是讀檔, 把陣列的值讀入後, 重畫畫面。

```cpp
///Week15_step03_2 把angle[i]存檔's', 再播放動畫'r'
///week12-5_TRT_keyboard_mouse 要用 keyboard mouse 來操控
```

```cpp
FILE * fout = NULL; ///step02-2 一開始,檔案沒有開, NULL
FILE * fin = NULL; ///step02-2 要讀檔用的指標, 一開始也是 NULL
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
```

## step03-3_Git 備份到雲端

```
cd desktop
git clone https://github.com/.../2023graphicsa
cd 2023graphicsa
開檔案總管 start .
(要 Save Everything)

git status
git add .
git status

git config --global user.email jsyeh@gmail.com
git config --global user.name jsyeh
git commit -m week15

git push
```

# Week16

## step01

```cpp
#include <GL/glut.h>
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(0,1,0);
    glBegin(GL_POLYGON);
        glVertex2f(0.5, 0.5);
        glVertex2f(-0.5, 0.5);
        glVertex2f(-0.5, -0.5);
        glVertex2f(0.5, -0.5);
    glEnd();
    glColor3f(1,1,0);
    glutSolidTeapot( 0.3 );
    glutSwapBuffers();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week16");

    glutDisplayFunc(display);

    glutMainLoop();
}
```

## step02

```cpp
#include <GL/glut.h>
float teapotX=0, teapotY=0;
void motion(int x, int y) {
    teapotX = (x-150) / 150.0;
    teapotY = (150-y) / 150.0;
    glutPostRedisplay();
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glTranslatef(teapotX, teapotY, 0);
        glutSolidTeapot( 0.3 );
    glPopMatrix();
    glutSwapBuffers();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week16");

    glutDisplayFunc(display);
    glutMotionFunc(motion);

    glutMainLoop();
}
```

## step03

```cpp
#include <GL/glut.h>
float teapotX=0, teapotY=0, angle=0, oldX=0, oldY=0;
void mouse(int button, int state, int x, int y) {
    oldX = x;
    oldY = y;
}
void motion(int x, int y) {
    angle += x - oldX; ///teapotX = (x-150) / 150.0;
    oldX = x;          ///teapotY = (150-y) / 150.0;
    glutPostRedisplay();
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glRotatef(angle, 0, 0, 1); ///glTranslatef(teapotX, teapotY, 0);
        glutSolidTeapot( 0.3 );
    glPopMatrix();
    glutSwapBuffers();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week16");

    glutDisplayFunc(display);
    glutMotionFunc(motion);
    glutMouseFunc(mouse);

    glutMainLoop();
}
```

## step04

```cpp
#include <GL/glut.h>
#include <stdio.h>
float teapotX=0, teapotY=0, angle=0, oldX=0, oldY=0;
void mouse(int button, int state, int x, int y) {
    oldX = x;
    oldY = y;
}

void motion(int x, int y) {
    teapotX = (x-150) / 150.0;///angle += x - oldX; ///
    teapotY = (150-y) / 150.0;///oldX = x;          ///
    printf("glTranslatef(%.3f , %.3f , 0 );\n", teapotX, teapotY);
    glutPostRedisplay();
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glColor3f(1,1,1);
        ///glTranslatef(....);
        ///glRotatef(angle, 0, 0, 1);
        ///glTranslatef(....);
        glTranslatef(teapotX, teapotY, 0);
        glutSolidTeapot( 0.3 );
    glPopMatrix();

    glColor3f(0,1,0);
    glutSolidTeapot( 0.01 );

    glutSwapBuffers();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week16");

    glutDisplayFunc(display);
    glutMotionFunc(motion);
    glutMouseFunc(mouse);

    glutMainLoop();
}
```

## step05

```cpp
#include <GL/glut.h>
#include <stdio.h>
float teapotX=0, teapotY=0, angle=0, oldX=0, oldY=0;
void mouse(int button, int state, int x, int y) {
    oldX = x;
    oldY = y;
}

void motion(int x, int y) {
    teapotX = (x-150) / 150.0;
    teapotY = (150-y) / 150.0;
    angle += x - oldX;
    oldX = x;
    printf("glTranslatef(%.3f , %.3f , 0 );\n", teapotX, teapotY);
    glutPostRedisplay();
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glColor3f(1,1,1);
        glTranslatef(-0.420 , +0.047 , 0 );///glTranslatef(....);
        glRotatef(angle, 0, 0, 1);
        glTranslatef(0.420 , -0.047 , 0 );///glTranslatef(....);
        ///glTranslatef(teapotX, teapotY, 0);
        glutSolidTeapot( 0.3 );
    glPopMatrix();

    glColor3f(0,1,0);
    glutSolidTeapot( 0.01 );

    glutSwapBuffers();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week16");

    glutDisplayFunc(display);
    glutMotionFunc(motion);
    glutMouseFunc(mouse);

    glutMainLoop();
}
```

## step06

```cpp
#include <GL/glut.h>
#include <stdio.h>
#include "glm.h"
GLMmodel * gundam = NULL;

float teapotX=0, teapotY=0, angle=0, oldX=0, oldY=0;
void mouse(int button, int state, int x, int y) {
    oldX = x;
    oldY = y;
}

void motion(int x, int y) {
    teapotX = (x-150) / 150.0;
    teapotY = (150-y) / 150.0;
    angle += x - oldX;
    oldX = x;
    printf("glTranslatef(%.3f , %.3f , 0 );\n", teapotX, teapotY);
    glutPostRedisplay();
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glColor3f(1,0,0);
        glScalef(0.03, 0.03, 0.03);
        glmDraw(gundam, GLM_MATERIAL);
    glPopMatrix();

    glColor3f(0,1,0);
    glutSolidTeapot( 0.01 );

    glutSwapBuffers();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week16");

    glutDisplayFunc(display);
    glutMotionFunc(motion);
    glutMouseFunc(mouse);

    gundam = glmReadOBJ("model/gundam.obj");

    glutMainLoop();
}
```

## step07

```cpp
#include <stdio.h>
#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
#include <GL/glut.h>
#include "glm.h"
GLMmodel * gundam = NULL;
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCV讀圖
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能
    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID
    glGenTextures(1, &id); /// 產生Generate 貼圖ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// 貼圖參數, 放大時的內插, 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// 貼圖參數, 縮小時的內插, 用最近點
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}

float teapotX=0, teapotY=0, angle=0, oldX=0, oldY=0;
void mouse(int button, int state, int x, int y) {
    oldX = x;
    oldY = y;
}

void motion(int x, int y) {
    teapotX = (x-150) / 150.0;
    teapotY = (150-y) / 150.0;
    angle += x - oldX;
    oldX = x;
    printf("glTranslatef(%.3f , %.3f , 0 );\n", teapotX, teapotY);
    glutPostRedisplay();
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glColor3f(1,1,1);///glColor3f(1,0,0);
        glScalef(0.03, 0.03, 0.03);
        glRotatef(angle, 0, 1, 0);
        glmDraw(gundam, GLM_MATERIAL | GLM_TEXTURE);
    glPopMatrix();

    glColor3f(0,1,0);
    glutSolidTeapot( 0.01 );

    glutSwapBuffers();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week16");

    glutDisplayFunc(display);
    glutMotionFunc(motion);
    glutMouseFunc(mouse);

    gundam = glmReadOBJ("model/gundam.obj");
    myTexture("model/Diffuse.jpg");
    glEnable(GL_DEPTH_TEST);

    glutMainLoop();
}
```


## step08

```cpp
#include <stdio.h>
#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
#include <GL/glut.h>
#include "glm.h"
GLMmodel * head = NULL;
GLMmodel * body = NULL; ///GLMmodel * gundam = NULL;
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCV讀圖
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能
    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID
    glGenTextures(1, &id); /// 產生Generate 貼圖ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// 貼圖參數, 放大時的內插, 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// 貼圖參數, 縮小時的內插, 用最近點
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}

float teapotX=0, teapotY=0, angle=0, angle2=0, oldX=0, oldY=0;  ///有不同
void mouse(int button, int state, int x, int y) {
    oldX = x;
    oldY = y;
}

void motion(int x, int y) {
    teapotX += (x - oldX)/10.0; ///有不同
    teapotY += (oldY - y)/10.0; ///有不同
    angle += x - oldX;
    angle2 += y - oldY; ///有不同
    oldX = x;
    oldY = y; ///有不同
    printf("glTranslatef(%.3f , %.3f , 0 );\n", teapotX, teapotY);
    glutPostRedisplay();
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glColor3f(1,1,1);///glColor3f(1,0,0);
        glScalef(0.03, 0.03, 0.03);
        ///glRotatef(angle, 0, 1, 0);
        glmDraw(body, GLM_MATERIAL | GLM_TEXTURE); ///glmDraw(gundam, GLM_MATERIAL | GLM_TEXTURE);
        glPushMatrix();
            ///glTranslatef(+0.000 , +33.200 , 0 );
            ///glRotatef(angle, 0, 1, 0);
            ///glRotatef(angle2, 1, 0, 0);
            ///glTranslatef(-0.000 , -33.200 , 0 );
            glTranslatef(teapotX, teapotY, 0);
            glmDraw(head, GLM_MATERIAL | GLM_TEXTURE);
        glPopMatrix();
    glPopMatrix();

    glColor3f(0,1,0);
    glutSolidTeapot( 0.01 );

    glutSwapBuffers();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week16");

    glutDisplayFunc(display);
    glutMotionFunc(motion);
    glutMouseFunc(mouse);

    head = glmReadOBJ("model/head.obj");
    body = glmReadOBJ("model/body.obj"); ///gundam = glmReadOBJ("model/gundam.obj");
    myTexture("model/Diffuse.jpg");
    glEnable(GL_DEPTH_TEST);

    glutMainLoop();
}
```


## step09

```cpp
#include <stdio.h>
#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
#include <GL/glut.h>
#include "glm.h"
GLMmodel * head = NULL;
GLMmodel * body = NULL; ///GLMmodel * gundam = NULL;
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCV讀圖
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能
    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID
    glGenTextures(1, &id); /// 產生Generate 貼圖ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// 貼圖參數, 放大時的內插, 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// 貼圖參數, 縮小時的內插, 用最近點
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}

float teapotX=0, teapotY=0, angle=0, angle2=0, oldX=0, oldY=0;  ///有不同
void mouse(int button, int state, int x, int y) {
    oldX = x;
    oldY = y;
}

void motion(int x, int y) {
    teapotX += (x - oldX)/10.0; ///有不同
    teapotY += (oldY - y)/10.0; ///有不同
    angle += x - oldX;
    angle2 += y - oldY; ///有不同
    oldX = x;
    oldY = y; ///有不同
    printf("glTranslatef(%.3f , %.3f , 0 );\n", teapotX, teapotY);
    glutPostRedisplay();
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glColor3f(1,1,1);///glColor3f(1,0,0);
        glScalef(0.03, 0.03, 0.03);
        ///glRotatef(angle, 0, 1, 0);
        glmDraw(body, GLM_MATERIAL | GLM_TEXTURE); ///glmDraw(gundam, GLM_MATERIAL | GLM_TEXTURE);
        glPushMatrix();
            glTranslatef(0.000 , +22.300 , 0 );
            glRotatef(angle, 0, 1, 0);
            glRotatef(angle2, 1, 0, 0);
            glTranslatef(0.000 , -22.300 , 0 );
            ///glTranslatef(teapotX, teapotY, 0);
            glmDraw(head, GLM_MATERIAL | GLM_TEXTURE);
        glPopMatrix();
    glPopMatrix();

    glColor3f(0,1,0);
    glutSolidTeapot( 0.01 );

    glutSwapBuffers();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week16");

    glutDisplayFunc(display);
    glutMotionFunc(motion);
    glutMouseFunc(mouse);

    head = glmReadOBJ("model/head.obj");
    body = glmReadOBJ("model/body.obj"); ///gundam = glmReadOBJ("model/gundam.obj");
    myTexture("model/Diffuse.jpg");
    glEnable(GL_DEPTH_TEST);

    glutMainLoop();
}
```


## step10

```cpp
#include <stdio.h>
#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
#include <GL/glut.h>
#include "glm.h"
GLMmodel * head = NULL;
GLMmodel * body = NULL; ///GLMmodel * gundam = NULL;
GLMmodel * arm1 = NULL, * arm2 = NULL;
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCV讀圖
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能
    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID
    glGenTextures(1, &id); /// 產生Generate 貼圖ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// 貼圖參數, 放大時的內插, 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// 貼圖參數, 縮小時的內插, 用最近點
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}

float teapotX=0, teapotY=0, angle=0, angle2=0, oldX=0, oldY=0;  ///有不同
void mouse(int button, int state, int x, int y) {
    oldX = x;
    oldY = y;
}

void motion(int x, int y) {
    teapotX += (x - oldX)/10.0; ///有不同
    teapotY += (oldY - y)/10.0; ///有不同
    angle += x - oldX;
    angle2 += y - oldY; ///有不同
    oldX = x;
    oldY = y; ///有不同
    printf("glTranslatef(%.3f , %.3f , 0 );\n", teapotX, teapotY);
    glutPostRedisplay();
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glScalef(2,2,2);
        glTranslatef(0, -0.4, 0);
        glPushMatrix();
            glColor3f(1,1,1);///glColor3f(1,0,0);
            glScalef(0.03, 0.03, 0.03);
            ///glRotatef(angle, 0, 1, 0);
            glmDraw(body, GLM_MATERIAL | GLM_TEXTURE); ///glmDraw(gundam, GLM_MATERIAL | GLM_TEXTURE);

            glPushMatrix();
                glTranslatef(0.000 , +22.300 , 0 );
                //glRotatef(angle, 0, 1, 0);
                //glRotatef(angle2, 1, 0, 0);
                glTranslatef(0.000 , -22.300 , 0 );
                ///glTranslatef(teapotX, teapotY, 0);
                glmDraw(head, GLM_MATERIAL | GLM_TEXTURE);
            glPopMatrix();

            glPushMatrix();
                glTranslatef(teapotX, teapotY, 0);
                glmDraw(arm1, GLM_MATERIAL | GLM_TEXTURE);
            glPopMatrix();

        glPopMatrix();
        glColor3f(0,1,0);///中心點的位置
        glutSolidTeapot( 0.01 );///中心點的位置
    glPopMatrix();

    glutSwapBuffers();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week16");

    glutDisplayFunc(display);
    glutMotionFunc(motion);
    glutMouseFunc(mouse);

    head = glmReadOBJ("model/head.obj");
    body = glmReadOBJ("model/body.obj"); ///gundam = glmReadOBJ("model/gundam.obj");
    arm1 = glmReadOBJ("model/arm1.obj");
    arm2 = glmReadOBJ("model/arm1.obj");
    myTexture("model/Diffuse.jpg");
    glEnable(GL_DEPTH_TEST);

    glutMainLoop();
}
```


## step11

```cpp
#include <stdio.h>
#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
#include <GL/glut.h>
#include "glm.h"
GLMmodel * head = NULL;
GLMmodel * body = NULL; ///GLMmodel * gundam = NULL;
GLMmodel * arm1 = NULL, * arm2 = NULL;
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCV讀圖
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能
    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID
    glGenTextures(1, &id); /// 產生Generate 貼圖ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// 貼圖參數, 放大時的內插, 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// 貼圖參數, 縮小時的內插, 用最近點
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}

float teapotX=0, teapotY=0, angle=0, angle2=0, oldX=0, oldY=0;  ///有不同
void mouse(int button, int state, int x, int y) {
    oldX = x;
    oldY = y;
}

void motion(int x, int y) {
    teapotX += (x - oldX)/10.0; ///有不同
    teapotY += (oldY - y)/10.0; ///有不同
    angle += x - oldX;
    angle2 += y - oldY; ///有不同
    oldX = x;
    oldY = y; ///有不同
    printf("glTranslatef(%.3f , %.3f , 0 );\n", teapotX, teapotY);
    glutPostRedisplay();
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glScalef(2,2,2);
        glTranslatef(0, -0.4, 0);
        glPushMatrix();
            glColor3f(1,1,1);///glColor3f(1,0,0);
            glScalef(0.03, 0.03, 0.03);
            ///glRotatef(angle, 0, 1, 0);
            glmDraw(body, GLM_MATERIAL | GLM_TEXTURE); ///glmDraw(gundam, GLM_MATERIAL | GLM_TEXTURE);

            glPushMatrix();
                glTranslatef(0.000 , +22.300 , 0 );
                //glRotatef(angle, 0, 1, 0);
                //glRotatef(angle2, 1, 0, 0);
                glTranslatef(0.000 , -22.300 , 0 );
                ///glTranslatef(teapotX, teapotY, 0);
                glmDraw(head, GLM_MATERIAL | GLM_TEXTURE);
            glPopMatrix();

            glPushMatrix();
                glTranslatef(-3.800 , +21.200 , 0 );
                glRotatef(angle, 0, 1, 0);
                glRotatef(angle2, 1, 0, 0);
                glTranslatef(3.800 , -21.200 , 0 );
                ///glTranslatef(teapotX, teapotY, 0);
                glmDraw(arm1, GLM_MATERIAL | GLM_TEXTURE);
            glPopMatrix();

        glPopMatrix();
        glColor3f(0,1,0);///中心點的位置
        glutSolidTeapot( 0.01 );///中心點的位置
    glPopMatrix();

    glutSwapBuffers();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week16");

    glutDisplayFunc(display);
    glutMotionFunc(motion);
    glutMouseFunc(mouse);

    head = glmReadOBJ("model/head.obj");
    body = glmReadOBJ("model/body.obj"); ///gundam = glmReadOBJ("model/gundam.obj");
    arm1 = glmReadOBJ("model/arm1.obj");
    arm2 = glmReadOBJ("model/arm1.obj");
    myTexture("model/Diffuse.jpg");
    glEnable(GL_DEPTH_TEST);

    glutMainLoop();
}
```


## step12

```cpp
#include <stdio.h>
#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
#include <GL/glut.h>
#include "glm.h"
GLMmodel * head = NULL;
GLMmodel * body = NULL; ///GLMmodel * gundam = NULL;
GLMmodel * arm1 = NULL, * arm2 = NULL;
GLMmodel * hand1 = NULL, * hand2 = NULL;
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCV讀圖
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能
    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID
    glGenTextures(1, &id); /// 產生Generate 貼圖ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// 貼圖參數, 放大時的內插, 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// 貼圖參數, 縮小時的內插, 用最近點
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}

float teapotX=0, teapotY=0, angle=0, angle2=0, oldX=0, oldY=0;  ///有不同
void mouse(int button, int state, int x, int y) {
    oldX = x;
    oldY = y;
}

void motion(int x, int y) {
    teapotX += (x - oldX)/10.0; ///有不同
    teapotY += (oldY - y)/10.0; ///有不同
    angle += x - oldX;
    angle2 += y - oldY; ///有不同
    oldX = x;
    oldY = y; ///有不同
    printf("glTranslatef(%.3f , %.3f , 0 );\n", teapotX, teapotY);
    glutPostRedisplay();
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glScalef(2,2,2);
        glTranslatef(0, -0.4, 0);
        glPushMatrix();
            glColor3f(1,1,1);///glColor3f(1,0,0);
            glScalef(0.03, 0.03, 0.03);
            ///glRotatef(angle, 0, 1, 0);
            glmDraw(body, GLM_MATERIAL | GLM_TEXTURE); ///glmDraw(gundam, GLM_MATERIAL | GLM_TEXTURE);

            glPushMatrix();
                glTranslatef(0.000 , +22.300 , 0 );
                //glRotatef(angle, 0, 1, 0);
                //glRotatef(angle2, 1, 0, 0);
                glTranslatef(0.000 , -22.300 , 0 );
                ///glTranslatef(teapotX, teapotY, 0);
                glmDraw(head, GLM_MATERIAL | GLM_TEXTURE);
            glPopMatrix();

            glPushMatrix();
                glTranslatef(-3.800 , +21.200 , 0 );
                //glRotatef(angle, 0, 1, 0);
                //glRotatef(angle2, 1, 0, 0);
                glTranslatef(3.800 , -21.200 , 0 );
                ///glTranslatef(teapotX, teapotY, 0);
                glmDraw(arm1, GLM_MATERIAL | GLM_TEXTURE);
                glPushMatrix();
                    glTranslatef(-4.300 , +18.600 , 0 );
                    glRotatef(angle, 0, 1, 0);
                    glRotatef(angle2, 1, 0, 0);
                    glTranslatef(4.300 , -18.600 , 0 );
                    glmDraw(hand1, GLM_MATERIAL | GLM_TEXTURE);
                glPopMatrix();
            glPopMatrix();

            glPushMatrix();
                glTranslatef(+3.800 , +21.200 , 0 );
                //glRotatef(angle, 0, 1, 0);
                //glRotatef(angle2, 1, 0, 0);
                glTranslatef(-3.800 , -21.200 , 0 );
                ///glTranslatef(teapotX, teapotY, 0);
                glmDraw(arm2, GLM_MATERIAL | GLM_TEXTURE);
                glPushMatrix();
                    glTranslatef(+4.300 , +18.600 , 0 );
                    glRotatef(angle, 0, 1, 0);
                    glRotatef(angle2, 1, 0, 0);
                    glTranslatef(-4.300 , -18.600 , 0 );
                    glmDraw(hand2, GLM_MATERIAL | GLM_TEXTURE);
                glPopMatrix();
            glPopMatrix();
        glPopMatrix();
        glColor3f(0,1,0);///中心點的位置
        glutSolidTeapot( 0.01 );///中心點的位置
    glPopMatrix();

    glutSwapBuffers();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week16");

    glutDisplayFunc(display);
    glutMotionFunc(motion);
    glutMouseFunc(mouse);

    head = glmReadOBJ("model/head.obj");
    body = glmReadOBJ("model/body.obj"); ///gundam = glmReadOBJ("model/gundam.obj");
    arm1 = glmReadOBJ("model/arm1.obj");
    arm2 = glmReadOBJ("model/arm2.obj");
    hand1 = glmReadOBJ("model/hand1.obj");
    hand2 = glmReadOBJ("model/hand2.obj");
    myTexture("model/Diffuse.jpg");
    glEnable(GL_DEPTH_TEST);

    glutMainLoop();
}
```


## step13

```cpp
#include <stdio.h>
#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
#include <GL/glut.h>
#include "glm.h"
GLMmodel * head = NULL;
GLMmodel * body = NULL; ///GLMmodel * gundam = NULL;
GLMmodel * arm1 = NULL, * arm2 = NULL;
GLMmodel * hand1 = NULL, * hand2 = NULL;
GLMmodel * bot = NULL;
GLMmodel * leg1 = NULL, * leg2 = NULL;
GLMmodel * knee1 = NULL, * knee2 = NULL;
GLMmodel * foot1 = NULL, * foot2 = NULL;
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCV讀圖
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能
    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID
    glGenTextures(1, &id); /// 產生Generate 貼圖ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// 貼圖參數, 放大時的內插, 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// 貼圖參數, 縮小時的內插, 用最近點
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}

float teapotX=0, teapotY=0, angle=0, angle2=0, oldX=0, oldY=0;  ///有不同
void mouse(int button, int state, int x, int y) {
    oldX = x;
    oldY = y;
}

void motion(int x, int y) {
    teapotX += (x - oldX)/10.0; ///有不同
    teapotY += (oldY - y)/10.0; ///有不同
    angle += x - oldX;
    angle2 += y - oldY; ///有不同
    oldX = x;
    oldY = y; ///有不同
    printf("glTranslatef(%.3f , %.3f , 0 );\n", teapotX, teapotY);
    glutPostRedisplay();
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glScalef(2,2,2);
        glTranslatef(0, -0.4, 0);
        glPushMatrix();
            glColor3f(1,1,1);///glColor3f(1,0,0);
            glScalef(0.03, 0.03, 0.03);
            ///glRotatef(angle, 0, 1, 0);
            glmDraw(body, GLM_MATERIAL | GLM_TEXTURE); ///glmDraw(gundam, GLM_MATERIAL | GLM_TEXTURE);

            glPushMatrix();
                glTranslatef(0.000 , +22.300 , 0 );
                //glRotatef(angle, 0, 1, 0);
                //glRotatef(angle2, 1, 0, 0);
                glTranslatef(0.000 , -22.300 , 0 );
                ///glTranslatef(teapotX, teapotY, 0);
                glmDraw(head, GLM_MATERIAL | GLM_TEXTURE);
            glPopMatrix();

            glPushMatrix();
                glTranslatef(-3.800 , +21.200 , 0 );
                //glRotatef(angle, 0, 1, 0);
                //glRotatef(angle2, 1, 0, 0);
                glTranslatef(3.800 , -21.200 , 0 );
                ///glTranslatef(teapotX, teapotY, 0);
                glmDraw(arm1, GLM_MATERIAL | GLM_TEXTURE);
                glPushMatrix();
                    glTranslatef(-4.300 , +18.600 , 0 );
                    //glRotatef(angle, 0, 1, 0);
                    //glRotatef(angle2, 1, 0, 0);
                    glTranslatef(4.300 , -18.600 , 0 );
                    glmDraw(hand1, GLM_MATERIAL | GLM_TEXTURE);
                glPopMatrix();
            glPopMatrix();

            glPushMatrix();
                glTranslatef(+3.800 , +21.200 , 0 );
                //glRotatef(angle, 0, 1, 0);
                //glRotatef(angle2, 1, 0, 0);
                glTranslatef(-3.800 , -21.200 , 0 );
                ///glTranslatef(teapotX, teapotY, 0);
                glmDraw(arm2, GLM_MATERIAL | GLM_TEXTURE);
                glPushMatrix();
                    glTranslatef(+4.300 , +18.600 , 0 );
                    //glRotatef(angle, 0, 1, 0);
                    //glRotatef(angle2, 1, 0, 0);
                    glTranslatef(-4.300 , -18.600 , 0 );
                    glmDraw(hand2, GLM_MATERIAL | GLM_TEXTURE);
                glPopMatrix();
            glPopMatrix();

            glmDraw(bot, GLM_MATERIAL | GLM_TEXTURE);
            
            glPushMatrix();///左大腿
                glTranslatef(-2.000 , +14.100 , 0 );
                //glRotatef(angle, 0, 1, 0);
                //glRotatef(angle2, 1, 0, 0);
                glTranslatef(2.000 , -14.100 , 0 );
                glmDraw(leg1, GLM_MATERIAL | GLM_TEXTURE);

                glPushMatrix();
                    glTranslatef(-2.000 , +10.500 , 0 );
                    //glRotatef(angle, 0, 1, 0);
                    //glRotatef(angle2, 1, 0, 0);
                    glTranslatef(2.000 , -10.500 , 0 );
                    glmDraw(knee1, GLM_MATERIAL | GLM_TEXTURE);

                    glPushMatrix();
                        glTranslatef(-2.000 , +3.000 , 0 );
                        glRotatef(angle, 0, 1, 0);
                        glRotatef(angle2, 1, 0, 0);
                        glTranslatef(2.000 , -3.000 , 0 );
                        glmDraw(foot1, GLM_MATERIAL | GLM_TEXTURE);
                    glPopMatrix();
                glPopMatrix();
            glPopMatrix();



        glPopMatrix();
        glColor3f(0,1,0);///中心點的位置
        glutSolidTeapot( 0.01 );///中心點的位置
    glPopMatrix();

    glutSwapBuffers();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week16");

    glutDisplayFunc(display);
    glutMotionFunc(motion);
    glutMouseFunc(mouse);

    head = glmReadOBJ("model/head.obj");
    body = glmReadOBJ("model/body.obj"); ///gundam = glmReadOBJ("model/gundam.obj");
    arm1 = glmReadOBJ("model/arm1.obj");
    arm2 = glmReadOBJ("model/arm2.obj");
    hand1 = glmReadOBJ("model/hand1.obj");
    hand2 = glmReadOBJ("model/hand2.obj");
    bot = glmReadOBJ("model/bot.obj");
    leg1 = glmReadOBJ("model/leg1.obj");
    leg2 = glmReadOBJ("model/leg2.obj");
    knee1 = glmReadOBJ("model/knee1.obj");
    knee2 = glmReadOBJ("model/knee2.obj");
    foot1 = glmReadOBJ("model/foot1.obj");
    foot2 = glmReadOBJ("model/foot2.obj");
    myTexture("model/Diffuse.jpg");
    glEnable(GL_DEPTH_TEST);

    glutMainLoop();
}
```


## step14

```cpp
#include <stdio.h>
#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
#include <GL/glut.h>
#include "glm.h"
GLMmodel * head = NULL;
GLMmodel * body = NULL; ///GLMmodel * gundam = NULL;
GLMmodel * arm1 = NULL, * arm2 = NULL;
GLMmodel * hand1 = NULL, * hand2 = NULL;
GLMmodel * bot = NULL;
GLMmodel * leg1 = NULL, * leg2 = NULL;
GLMmodel * knee1 = NULL, * knee2 = NULL;
GLMmodel * foot1 = NULL, * foot2 = NULL;
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCV讀圖
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能
    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID
    glGenTextures(1, &id); /// 產生Generate 貼圖ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// 貼圖參數, 放大時的內插, 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// 貼圖參數, 縮小時的內插, 用最近點
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}

float teapotX=0, teapotY=0, angle=0, angle2=0, oldX=0, oldY=0;  ///有不同
void mouse(int button, int state, int x, int y) {
    oldX = x;
    oldY = y;
}

void motion(int x, int y) {
    teapotX += (x - oldX)/10.0; ///有不同
    teapotY += (oldY - y)/10.0; ///有不同
    angle += x - oldX;
    angle2 += y - oldY; ///有不同
    oldX = x;
    oldY = y; ///有不同
    printf("glTranslatef(%.3f , %.3f , 0 );\n", teapotX, teapotY);
    glutPostRedisplay();
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glScalef(2,2,2);
        glTranslatef(0, -0.4, 0);
        glPushMatrix();
            glColor3f(1,1,1);///glColor3f(1,0,0);
            glScalef(0.03, 0.03, 0.03);
            ///glRotatef(angle, 0, 1, 0);
            glmDraw(body, GLM_MATERIAL | GLM_TEXTURE); ///glmDraw(gundam, GLM_MATERIAL | GLM_TEXTURE);

            glPushMatrix();
                glTranslatef(0.000 , +22.300 , 0 );
                //glRotatef(angle, 0, 1, 0);
                //glRotatef(angle2, 1, 0, 0);
                glTranslatef(0.000 , -22.300 , 0 );
                ///glTranslatef(teapotX, teapotY, 0);
                glmDraw(head, GLM_MATERIAL | GLM_TEXTURE);
            glPopMatrix();

            glPushMatrix();
                glTranslatef(-3.800 , +21.200 , 0 );
                //glRotatef(angle, 0, 1, 0);
                //glRotatef(angle2, 1, 0, 0);
                glTranslatef(3.800 , -21.200 , 0 );
                ///glTranslatef(teapotX, teapotY, 0);
                glmDraw(arm1, GLM_MATERIAL | GLM_TEXTURE);
                glPushMatrix();
                    glTranslatef(-4.300 , +18.600 , 0 );
                    //glRotatef(angle, 0, 1, 0);
                    //glRotatef(angle2, 1, 0, 0);
                    glTranslatef(4.300 , -18.600 , 0 );
                    glmDraw(hand1, GLM_MATERIAL | GLM_TEXTURE);
                glPopMatrix();
            glPopMatrix();

            glPushMatrix();
                glTranslatef(+3.800 , +21.200 , 0 );
                //glRotatef(angle, 0, 1, 0);
                //glRotatef(angle2, 1, 0, 0);
                glTranslatef(-3.800 , -21.200 , 0 );
                ///glTranslatef(teapotX, teapotY, 0);
                glmDraw(arm2, GLM_MATERIAL | GLM_TEXTURE);
                glPushMatrix();
                    glTranslatef(+4.300 , +18.600 , 0 );
                    //glRotatef(angle, 0, 1, 0);
                    //glRotatef(angle2, 1, 0, 0);
                    glTranslatef(-4.300 , -18.600 , 0 );
                    glmDraw(hand2, GLM_MATERIAL | GLM_TEXTURE);
                glPopMatrix();
            glPopMatrix();

            glmDraw(bot, GLM_MATERIAL | GLM_TEXTURE);

            glPushMatrix();///左大腿
                glTranslatef(-2.000 , +14.100 , 0 );
                //glRotatef(angle, 0, 1, 0);
                //glRotatef(angle2, 1, 0, 0);
                glTranslatef(2.000 , -14.100 , 0 );
                glmDraw(leg1, GLM_MATERIAL | GLM_TEXTURE);

                glPushMatrix();
                    glTranslatef(-2.000 , +10.500 , 0 );
                    //glRotatef(angle, 0, 1, 0);
                    //glRotatef(angle2, 1, 0, 0);
                    glTranslatef(2.000 , -10.500 , 0 );
                    glmDraw(knee1, GLM_MATERIAL | GLM_TEXTURE);

                    glPushMatrix();
                        glTranslatef(-2.000 , +3.000 , 0 );
                        glRotatef(angle, 0, 1, 0);
                        glRotatef(angle2, 1, 0, 0);
                        glTranslatef(2.000 , -3.000 , 0 );
                        glmDraw(foot1, GLM_MATERIAL | GLM_TEXTURE);
                    glPopMatrix();
                glPopMatrix();
            glPopMatrix();

            glPushMatrix();///右大腿
                glTranslatef(+2.000 , +14.100 , 0 );
                //glRotatef(angle, 0, 1, 0);
                //glRotatef(angle2, 1, 0, 0);
                glTranslatef(-2.000 , -14.100 , 0 );
                glmDraw(leg2, GLM_MATERIAL | GLM_TEXTURE);

                glPushMatrix();
                    glTranslatef(+2.000 , +10.500 , 0 );
                    glRotatef(angle, 0, 1, 0);
                    glRotatef(angle2, 1, 0, 0);
                    glTranslatef(-2.000 , -10.500 , 0 );
                    glmDraw(knee2, GLM_MATERIAL | GLM_TEXTURE);

                    glPushMatrix();
                        glTranslatef(+2.000 , +3.000 , 0 );
                        glRotatef(angle, 0, 1, 0);
                        glRotatef(angle2, 1, 0, 0);
                        glTranslatef(-2.000 , -3.000 , 0 );
                        glmDraw(foot2, GLM_MATERIAL | GLM_TEXTURE);
                    glPopMatrix();
                glPopMatrix();
            glPopMatrix();

        glPopMatrix();
        glColor3f(0,1,0);///中心點的位置
        glutSolidTeapot( 0.01 );///中心點的位置
    glPopMatrix();

    glutSwapBuffers();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week16");

    glutDisplayFunc(display);
    glutMotionFunc(motion);
    glutMouseFunc(mouse);

    head = glmReadOBJ("model/head.obj");
    body = glmReadOBJ("model/body.obj"); ///gundam = glmReadOBJ("model/gundam.obj");
    arm1 = glmReadOBJ("model/arm1.obj");
    arm2 = glmReadOBJ("model/arm2.obj");
    hand1 = glmReadOBJ("model/hand1.obj");
    hand2 = glmReadOBJ("model/hand2.obj");
    bot = glmReadOBJ("model/bot.obj");
    leg1 = glmReadOBJ("model/leg1.obj");
    leg2 = glmReadOBJ("model/leg2.obj");
    knee1 = glmReadOBJ("model/knee1.obj");
    knee2 = glmReadOBJ("model/knee2.obj");
    foot1 = glmReadOBJ("model/foot1.obj");
    foot2 = glmReadOBJ("model/foot2.obj");
    myTexture("model/Diffuse.jpg");
    glEnable(GL_DEPTH_TEST);

    glutMainLoop();
}
```


## step15

```cpp
#include <stdio.h>
#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
#include <GL/glut.h>
#include "glm.h"
GLMmodel * head = NULL;
GLMmodel * body = NULL; ///GLMmodel * gundam = NULL;
GLMmodel * arm1 = NULL, * arm2 = NULL;
GLMmodel * hand1 = NULL, * hand2 = NULL;
GLMmodel * bot = NULL;
GLMmodel * leg1 = NULL, * leg2 = NULL;
GLMmodel * knee1 = NULL, * knee2 = NULL;
GLMmodel * foot1 = NULL, * foot2 = NULL;
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCV讀圖
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能
    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID
    glGenTextures(1, &id); /// 產生Generate 貼圖ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// 貼圖參數, 放大時的內插, 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// 貼圖參數, 縮小時的內插, 用最近點
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}

float teapotX=0, teapotY=0, oldX=0, oldY=0;  ///有不同
float angle[20]={}, angle2[20]={};
int ID=0; ///0:head, 1,2:left, 3,4:right hand, 5,6,7:left leg, 8,9,10:right leg
void keyboard(unsigned char key, int x, int y) {
    if(key=='0') ID=0;
    if(key=='1') ID=1;
    if(key=='2') ID=2;
    if(key=='3') ID=3;
    if(key=='4') ID=4;
    if(key=='5') ID=5;
    if(key=='6') ID=6;
    if(key=='7') ID=7;
    if(key=='8') ID=8;
    if(key=='9') ID=9;
}
void mouse(int button, int state, int x, int y) {
    oldX = x;
    oldY = y;
}

void motion(int x, int y) {
    teapotX += (x - oldX)/10.0; ///有不同
    teapotY += (oldY - y)/10.0; ///有不同
    angle[ID] += x - oldX;
    angle2[ID] += y - oldY; ///有不同
    oldX = x;
    oldY = y; ///有不同
    printf("glTranslatef(%.3f , %.3f , 0 );\n", teapotX, teapotY);
    glutPostRedisplay();
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glScalef(2,2,2);
        glTranslatef(0, -0.4, 0);
        glPushMatrix();
            glColor3f(1,1,1);///glColor3f(1,0,0);
            glScalef(0.03, 0.03, 0.03);
            glRotatef(90, 0, 1, 0);
            glmDraw(body, GLM_MATERIAL | GLM_TEXTURE); ///glmDraw(gundam, GLM_MATERIAL | GLM_TEXTURE);

            glPushMatrix();
                glTranslatef(0.000 , +22.300 , 0 );
                glRotatef(angle[0], 0, 1, 0);
                glRotatef(angle2[0], 1, 0, 0);
                glTranslatef(0.000 , -22.300 , 0 );
                glmDraw(head, GLM_MATERIAL | GLM_TEXTURE);
            glPopMatrix();

            glPushMatrix();
                glTranslatef(-3.800 , +21.200 , 0 );
                glRotatef(angle[1], 0, 1, 0);
                glRotatef(angle2[1], 1, 0, 0);
                glTranslatef(3.800 , -21.200 , 0 );
                glmDraw(arm1, GLM_MATERIAL | GLM_TEXTURE);
                glPushMatrix();
                    glTranslatef(-4.300 , +18.600 , 0 );
                    glRotatef(angle[2], 0, 1, 0);
                    glRotatef(angle2[2], 1, 0, 0);
                    glTranslatef(4.300 , -18.600 , 0 );
                    glmDraw(hand1, GLM_MATERIAL | GLM_TEXTURE);
                glPopMatrix();
            glPopMatrix();

            glPushMatrix();
                glTranslatef(+3.800 , +21.200 , 0 );
                glRotatef(angle[3], 0, 1, 0);
                glRotatef(angle2[3], 1, 0, 0);
                glTranslatef(-3.800 , -21.200 , 0 );
                glmDraw(arm2, GLM_MATERIAL | GLM_TEXTURE);
                glPushMatrix();
                    glTranslatef(+4.300 , +18.600 , 0 );
                    glRotatef(angle[4], 0, 1, 0);
                    glRotatef(angle2[4], 1, 0, 0);
                    glTranslatef(-4.300 , -18.600 , 0 );
                    glmDraw(hand2, GLM_MATERIAL | GLM_TEXTURE);
                glPopMatrix();
            glPopMatrix();

            glmDraw(bot, GLM_MATERIAL | GLM_TEXTURE);

            glPushMatrix();///左大腿
                glTranslatef(-2.000 , +14.100 , 0 );
                glRotatef(angle[5], 0, 1, 0);
                glRotatef(angle2[5], 1, 0, 0);
                glTranslatef(2.000 , -14.100 , 0 );
                glmDraw(leg1, GLM_MATERIAL | GLM_TEXTURE);

                glPushMatrix();
                    glTranslatef(-2.000 , +10.500 , 0 );
                    glRotatef(angle[6], 0, 1, 0);
                    glRotatef(angle2[6], 1, 0, 0);
                    glTranslatef(2.000 , -10.500 , 0 );
                    glmDraw(knee1, GLM_MATERIAL | GLM_TEXTURE);

                    glPushMatrix();
                        glTranslatef(-2.000 , +3.000 , 0 );
                        glRotatef(angle[7], 0, 1, 0);
                        glRotatef(angle2[7], 1, 0, 0);
                        glTranslatef(2.000 , -3.000 , 0 );
                        glmDraw(foot1, GLM_MATERIAL | GLM_TEXTURE);
                    glPopMatrix();
                glPopMatrix();
            glPopMatrix();

            glPushMatrix();///右大腿
                glTranslatef(+2.000 , +14.100 , 0 );
                glRotatef(angle[8], 0, 1, 0);
                glRotatef(angle2[8], 1, 0, 0);
                glTranslatef(-2.000 , -14.100 , 0 );
                glmDraw(leg2, GLM_MATERIAL | GLM_TEXTURE);

                glPushMatrix();
                    glTranslatef(+2.000 , +10.500 , 0 );
                    glRotatef(angle[9], 0, 1, 0);
                    glRotatef(angle2[9], 1, 0, 0);
                    glTranslatef(-2.000 , -10.500 , 0 );
                    glmDraw(knee2, GLM_MATERIAL | GLM_TEXTURE);

                    glPushMatrix();
                        glTranslatef(+2.000 , +3.000 , 0 );
                        glRotatef(angle[10], 0, 1, 0);
                        glRotatef(angle2[10], 1, 0, 0);
                        glTranslatef(-2.000 , -3.000 , 0 );
                        glmDraw(foot2, GLM_MATERIAL | GLM_TEXTURE);
                    glPopMatrix();
                glPopMatrix();
            glPopMatrix();

        glPopMatrix();
        glColor3f(0,1,0);///中心點的位置
        glutSolidTeapot( 0.01 );///中心點的位置
    glPopMatrix();

    glutSwapBuffers();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week16");

    glutDisplayFunc(display);
    glutMotionFunc(motion);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);

    head = glmReadOBJ("model/head.obj");
    body = glmReadOBJ("model/body.obj"); ///gundam = glmReadOBJ("model/gundam.obj");
    arm1 = glmReadOBJ("model/arm1.obj");
    arm2 = glmReadOBJ("model/arm2.obj");
    hand1 = glmReadOBJ("model/hand1.obj");
    hand2 = glmReadOBJ("model/hand2.obj");
    bot = glmReadOBJ("model/bot.obj");
    leg1 = glmReadOBJ("model/leg1.obj");
    leg2 = glmReadOBJ("model/leg2.obj");
    knee1 = glmReadOBJ("model/knee1.obj");
    knee2 = glmReadOBJ("model/knee2.obj");
    foot1 = glmReadOBJ("model/foot1.obj");
    foot2 = glmReadOBJ("model/foot2.obj");
    myTexture("model/Diffuse.jpg");
    glEnable(GL_DEPTH_TEST);

    glutMainLoop();
}
```


## step16

```cpp
#include <stdio.h>
#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
#include <GL/glut.h>
#include "glm.h"
GLMmodel * head = NULL;
GLMmodel * body = NULL; ///GLMmodel * gundam = NULL;
GLMmodel * arm1 = NULL, * arm2 = NULL;
GLMmodel * hand1 = NULL, * hand2 = NULL;
GLMmodel * bot = NULL;
GLMmodel * leg1 = NULL, * leg2 = NULL;
GLMmodel * knee1 = NULL, * knee2 = NULL;
GLMmodel * foot1 = NULL, * foot2 = NULL;
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCV讀圖
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能
    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID
    glGenTextures(1, &id); /// 產生Generate 貼圖ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// 貼圖參數, 放大時的內插, 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// 貼圖參數, 縮小時的內插, 用最近點
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}
FILE * fin = NULL;
FILE * fout = NULL;
float teapotX=0, teapotY=0, oldX=0, oldY=0;  ///有不同
float angle[20]={}, angle2[20]={};
int ID=0; ///0:head, 1,2:left, 3,4:right hand, 5,6,7:left leg, 8,9,10:right leg
void keyboard(unsigned char key, int x, int y) {
    if(key=='0') ID=0;
    if(key=='1') ID=1;
    if(key=='2') ID=2;
    if(key=='3') ID=3;
    if(key=='4') ID=4;
    if(key=='5') ID=5;
    if(key=='6') ID=6;
    if(key=='7') ID=7;
    if(key=='8') ID=8;
    if(key=='9') ID=9;
    if(key=='s'){ ///save
        if(fout==NULL) fout = fopen("motion.txt", "w");
        for(int i=0; i<20; i++){
            fprintf(fout, "%.2f ", angle[i] );
            fprintf(fout, "%.2f ", angle2[i] );
        }
        fprintf(fout, "\n");
        printf("你寫了1行\n");
    }
}
void mouse(int button, int state, int x, int y) {
    oldX = x;
    oldY = y;
}

void motion(int x, int y) {
    teapotX += (x - oldX)/10.0; ///有不同
    teapotY += (oldY - y)/10.0; ///有不同
    angle[ID] += x - oldX;
    angle2[ID] += y - oldY; ///有不同
    oldX = x;
    oldY = y; ///有不同
    ///printf("glTranslatef(%.3f , %.3f , 0 );\n", teapotX, teapotY);
    glutPostRedisplay();
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glScalef(2,2,2);
        glTranslatef(0, -0.4, 0);
        glPushMatrix();
            glColor3f(1,1,1);///glColor3f(1,0,0);
            glScalef(0.03, 0.03, 0.03);
            glRotatef(180, 0, 1, 0);
            glmDraw(body, GLM_MATERIAL | GLM_TEXTURE); ///glmDraw(gundam, GLM_MATERIAL | GLM_TEXTURE);

            glPushMatrix();
                glTranslatef(0.000 , +22.300 , 0 );
                glRotatef(angle[0], 0, 1, 0);
                glRotatef(angle2[0], 1, 0, 0);
                glTranslatef(0.000 , -22.300 , 0 );
                glmDraw(head, GLM_MATERIAL | GLM_TEXTURE);
            glPopMatrix();

            glPushMatrix();
                glTranslatef(-3.800 , +21.200 , 0 );
                glRotatef(angle[1], 0, 1, 0);
                glRotatef(angle2[1], 1, 0, 0);
                glTranslatef(3.800 , -21.200 , 0 );
                glmDraw(arm1, GLM_MATERIAL | GLM_TEXTURE);
                glPushMatrix();
                    glTranslatef(-4.300 , +18.600 , 0 );
                    glRotatef(angle[2], 0, 1, 0);
                    glRotatef(angle2[2], 1, 0, 0);
                    glTranslatef(4.300 , -18.600 , 0 );
                    glmDraw(hand1, GLM_MATERIAL | GLM_TEXTURE);
                glPopMatrix();
            glPopMatrix();

            glPushMatrix();
                glTranslatef(+3.800 , +21.200 , 0 );
                glRotatef(angle[3], 0, 1, 0);
                glRotatef(angle2[3], 1, 0, 0);
                glTranslatef(-3.800 , -21.200 , 0 );
                glmDraw(arm2, GLM_MATERIAL | GLM_TEXTURE);
                glPushMatrix();
                    glTranslatef(+4.300 , +18.600 , 0 );
                    glRotatef(angle[4], 0, 1, 0);
                    glRotatef(angle2[4], 1, 0, 0);
                    glTranslatef(-4.300 , -18.600 , 0 );
                    glmDraw(hand2, GLM_MATERIAL | GLM_TEXTURE);
                glPopMatrix();
            glPopMatrix();

            glmDraw(bot, GLM_MATERIAL | GLM_TEXTURE);

            glPushMatrix();///左大腿
                glTranslatef(-2.000 , +14.100 , 0 );
                glRotatef(angle[5], 0, 1, 0);
                glRotatef(angle2[5], 1, 0, 0);
                glTranslatef(2.000 , -14.100 , 0 );
                glmDraw(leg1, GLM_MATERIAL | GLM_TEXTURE);

                glPushMatrix();
                    glTranslatef(-2.000 , +10.500 , 0 );
                    glRotatef(angle[6], 0, 1, 0);
                    glRotatef(angle2[6], 1, 0, 0);
                    glTranslatef(2.000 , -10.500 , 0 );
                    glmDraw(knee1, GLM_MATERIAL | GLM_TEXTURE);

                    glPushMatrix();
                        glTranslatef(-2.000 , +3.000 , 0 );
                        glRotatef(angle[7], 0, 1, 0);
                        glRotatef(angle2[7], 1, 0, 0);
                        glTranslatef(2.000 , -3.000 , 0 );
                        glmDraw(foot1, GLM_MATERIAL | GLM_TEXTURE);
                    glPopMatrix();
                glPopMatrix();
            glPopMatrix();

            glPushMatrix();///右大腿
                glTranslatef(+2.000 , +14.100 , 0 );
                glRotatef(angle[8], 0, 1, 0);
                glRotatef(angle2[8], 1, 0, 0);
                glTranslatef(-2.000 , -14.100 , 0 );
                glmDraw(leg2, GLM_MATERIAL | GLM_TEXTURE);

                glPushMatrix();
                    glTranslatef(+2.000 , +10.500 , 0 );
                    glRotatef(angle[9], 0, 1, 0);
                    glRotatef(angle2[9], 1, 0, 0);
                    glTranslatef(-2.000 , -10.500 , 0 );
                    glmDraw(knee2, GLM_MATERIAL | GLM_TEXTURE);

                    glPushMatrix();
                        glTranslatef(+2.000 , +3.000 , 0 );
                        glRotatef(angle[10], 0, 1, 0);
                        glRotatef(angle2[10], 1, 0, 0);
                        glTranslatef(-2.000 , -3.000 , 0 );
                        glmDraw(foot2, GLM_MATERIAL | GLM_TEXTURE);
                    glPopMatrix();
                glPopMatrix();
            glPopMatrix();

        glPopMatrix();
        glColor3f(0,1,0);///中心點的位置
        glutSolidTeapot( 0.01 );///中心點的位置
    glPopMatrix();

    glutSwapBuffers();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week16");

    glutDisplayFunc(display);
    glutMotionFunc(motion);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);

    head = glmReadOBJ("model/head.obj");
    body = glmReadOBJ("model/body.obj"); ///gundam = glmReadOBJ("model/gundam.obj");
    arm1 = glmReadOBJ("model/arm1.obj");
    arm2 = glmReadOBJ("model/arm2.obj");
    hand1 = glmReadOBJ("model/hand1.obj");
    hand2 = glmReadOBJ("model/hand2.obj");
    bot = glmReadOBJ("model/bot.obj");
    leg1 = glmReadOBJ("model/leg1.obj");
    leg2 = glmReadOBJ("model/leg2.obj");
    knee1 = glmReadOBJ("model/knee1.obj");
    knee2 = glmReadOBJ("model/knee2.obj");
    foot1 = glmReadOBJ("model/foot1.obj");
    foot2 = glmReadOBJ("model/foot2.obj");
    myTexture("model/Diffuse.jpg");
    glEnable(GL_DEPTH_TEST);

    glutMainLoop();
}
```


## step17

```cpp
#include <stdio.h>
#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
#include <GL/glut.h>
#include "glm.h"
GLMmodel * head = NULL;
GLMmodel * body = NULL; ///GLMmodel * gundam = NULL;
GLMmodel * arm1 = NULL, * arm2 = NULL;
GLMmodel * hand1 = NULL, * hand2 = NULL;
GLMmodel * bot = NULL;
GLMmodel * leg1 = NULL, * leg2 = NULL;
GLMmodel * knee1 = NULL, * knee2 = NULL;
GLMmodel * foot1 = NULL, * foot2 = NULL;
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCV讀圖
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能
    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID
    glGenTextures(1, &id); /// 產生Generate 貼圖ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// 貼圖參數, 放大時的內插, 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// 貼圖參數, 縮小時的內插, 用最近點
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}
FILE * fin = NULL;
FILE * fout = NULL;
float teapotX=0, teapotY=0, oldX=0, oldY=0;  ///有不同
float angle[20]={}, angle2[20]={};
int ID=0; ///0:head, 1,2:left, 3,4:right hand, 5,6,7:left leg, 8,9,10:right leg
void keyboard(unsigned char key, int x, int y) {
    if(key=='0') ID=0;
    if(key=='1') ID=1;
    if(key=='2') ID=2;
    if(key=='3') ID=3;
    if(key=='4') ID=4;
    if(key=='5') ID=5;
    if(key=='6') ID=6;
    if(key=='7') ID=7;
    if(key=='8') ID=8;
    if(key=='9') ID=9;
    if(key=='s'){ ///save
        if(fout==NULL) fout = fopen("motion.txt", "w");
        for(int i=0; i<20; i++){
            fprintf(fout, "%.2f ", angle[i] );
            fprintf(fout, "%.2f ", angle2[i] );
        }
        fprintf(fout, "\n");
        printf("你寫了1行\n");
    }
    if(key=='r'){ ///read
        if(fin==NULL) fin = fopen("motion.txt", "r");
        for(int i=0; i<20; i++){
            fscanf(fin, "%f", &angle[i] );
            fscanf(fin, "%f", &angle2[i] );
        }
        glutPostRedisplay();
    }
}
void mouse(int button, int state, int x, int y) {
    oldX = x;
    oldY = y;
}

void motion(int x, int y) {
    teapotX += (x - oldX)/10.0; ///有不同
    teapotY += (oldY - y)/10.0; ///有不同
    angle[ID] += x - oldX;
    angle2[ID] += y - oldY; ///有不同
    oldX = x;
    oldY = y; ///有不同
    ///printf("glTranslatef(%.3f , %.3f , 0 );\n", teapotX, teapotY);
    glutPostRedisplay();
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glScalef(2,2,2);
        glTranslatef(0, -0.4, 0);
        glPushMatrix();
            glColor3f(1,1,1);///glColor3f(1,0,0);
            glScalef(0.03, 0.03, 0.03);
            glRotatef(180, 0, 1, 0);
            glmDraw(body, GLM_MATERIAL | GLM_TEXTURE); ///glmDraw(gundam, GLM_MATERIAL | GLM_TEXTURE);

            glPushMatrix();
                glTranslatef(0.000 , +22.300 , 0 );
                glRotatef(angle[0], 0, 1, 0);
                glRotatef(angle2[0], 1, 0, 0);
                glTranslatef(0.000 , -22.300 , 0 );
                glmDraw(head, GLM_MATERIAL | GLM_TEXTURE);
            glPopMatrix();

            glPushMatrix();
                glTranslatef(-3.800 , +21.200 , 0 );
                glRotatef(angle[1], 0, 1, 0);
                glRotatef(angle2[1], 1, 0, 0);
                glTranslatef(3.800 , -21.200 , 0 );
                glmDraw(arm1, GLM_MATERIAL | GLM_TEXTURE);
                glPushMatrix();
                    glTranslatef(-4.300 , +18.600 , 0 );
                    glRotatef(angle[2], 0, 1, 0);
                    glRotatef(angle2[2], 1, 0, 0);
                    glTranslatef(4.300 , -18.600 , 0 );
                    glmDraw(hand1, GLM_MATERIAL | GLM_TEXTURE);
                glPopMatrix();
            glPopMatrix();

            glPushMatrix();
                glTranslatef(+3.800 , +21.200 , 0 );
                glRotatef(angle[3], 0, 1, 0);
                glRotatef(angle2[3], 1, 0, 0);
                glTranslatef(-3.800 , -21.200 , 0 );
                glmDraw(arm2, GLM_MATERIAL | GLM_TEXTURE);
                glPushMatrix();
                    glTranslatef(+4.300 , +18.600 , 0 );
                    glRotatef(angle[4], 0, 1, 0);
                    glRotatef(angle2[4], 1, 0, 0);
                    glTranslatef(-4.300 , -18.600 , 0 );
                    glmDraw(hand2, GLM_MATERIAL | GLM_TEXTURE);
                glPopMatrix();
            glPopMatrix();

            glmDraw(bot, GLM_MATERIAL | GLM_TEXTURE);

            glPushMatrix();///左大腿
                glTranslatef(-2.000 , +14.100 , 0 );
                glRotatef(angle[5], 0, 1, 0);
                glRotatef(angle2[5], 1, 0, 0);
                glTranslatef(2.000 , -14.100 , 0 );
                glmDraw(leg1, GLM_MATERIAL | GLM_TEXTURE);

                glPushMatrix();
                    glTranslatef(-2.000 , +10.500 , 0 );
                    glRotatef(angle[6], 0, 1, 0);
                    glRotatef(angle2[6], 1, 0, 0);
                    glTranslatef(2.000 , -10.500 , 0 );
                    glmDraw(knee1, GLM_MATERIAL | GLM_TEXTURE);

                    glPushMatrix();
                        glTranslatef(-2.000 , +3.000 , 0 );
                        glRotatef(angle[7], 0, 1, 0);
                        glRotatef(angle2[7], 1, 0, 0);
                        glTranslatef(2.000 , -3.000 , 0 );
                        glmDraw(foot1, GLM_MATERIAL | GLM_TEXTURE);
                    glPopMatrix();
                glPopMatrix();
            glPopMatrix();

            glPushMatrix();///右大腿
                glTranslatef(+2.000 , +14.100 , 0 );
                glRotatef(angle[8], 0, 1, 0);
                glRotatef(angle2[8], 1, 0, 0);
                glTranslatef(-2.000 , -14.100 , 0 );
                glmDraw(leg2, GLM_MATERIAL | GLM_TEXTURE);

                glPushMatrix();
                    glTranslatef(+2.000 , +10.500 , 0 );
                    glRotatef(angle[9], 0, 1, 0);
                    glRotatef(angle2[9], 1, 0, 0);
                    glTranslatef(-2.000 , -10.500 , 0 );
                    glmDraw(knee2, GLM_MATERIAL | GLM_TEXTURE);

                    glPushMatrix();
                        glTranslatef(+2.000 , +3.000 , 0 );
                        glRotatef(angle[10], 0, 1, 0);
                        glRotatef(angle2[10], 1, 0, 0);
                        glTranslatef(-2.000 , -3.000 , 0 );
                        glmDraw(foot2, GLM_MATERIAL | GLM_TEXTURE);
                    glPopMatrix();
                glPopMatrix();
            glPopMatrix();

        glPopMatrix();
        glColor3f(0,1,0);///中心點的位置
        glutSolidTeapot( 0.01 );///中心點的位置
    glPopMatrix();

    glutSwapBuffers();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week16");

    glutDisplayFunc(display);
    glutMotionFunc(motion);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);

    head = glmReadOBJ("model/head.obj");
    body = glmReadOBJ("model/body.obj"); ///gundam = glmReadOBJ("model/gundam.obj");
    arm1 = glmReadOBJ("model/arm1.obj");
    arm2 = glmReadOBJ("model/arm2.obj");
    hand1 = glmReadOBJ("model/hand1.obj");
    hand2 = glmReadOBJ("model/hand2.obj");
    bot = glmReadOBJ("model/bot.obj");
    leg1 = glmReadOBJ("model/leg1.obj");
    leg2 = glmReadOBJ("model/leg2.obj");
    knee1 = glmReadOBJ("model/knee1.obj");
    knee2 = glmReadOBJ("model/knee2.obj");
    foot1 = glmReadOBJ("model/foot1.obj");
    foot2 = glmReadOBJ("model/foot2.obj");
    myTexture("model/Diffuse.jpg");
    glEnable(GL_DEPTH_TEST);

    glutMainLoop();
}
```


## step18

```cpp
#include <stdio.h>
#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
#include <GL/glut.h>
#include "glm.h"
GLMmodel * head = NULL;
GLMmodel * body = NULL; ///GLMmodel * gundam = NULL;
GLMmodel * arm1 = NULL, * arm2 = NULL;
GLMmodel * hand1 = NULL, * hand2 = NULL;
GLMmodel * bot = NULL;
GLMmodel * leg1 = NULL, * leg2 = NULL;
GLMmodel * knee1 = NULL, * knee2 = NULL;
GLMmodel * foot1 = NULL, * foot2 = NULL;
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCV讀圖
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能
    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID
    glGenTextures(1, &id); /// 產生Generate 貼圖ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// 貼圖參數, 放大時的內插, 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// 貼圖參數, 縮小時的內插, 用最近點
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}
FILE * fin = NULL;
FILE * fout = NULL;
float teapotX=0, teapotY=0, oldX=0, oldY=0;  ///有不同
float angle[20]={}, angle2[20]={};
float OldAngle[20]={}, NewAngle[20]={};
float OldAngle2[20]={}, NewAngle2[20]={};
int ID=0; ///0:head, 1,2:left, 3,4:right hand, 5,6,7:left leg, 8,9,10:right leg
void timer(int t) {
    glutTimerFunc(20, timer, t+1);
    if(t%50==0){ ///新的開始,要讀新的動作
        if(fin==NULL) fin = fopen("motion.txt", "r");
        for(int i=0; i<20; i++){
            OldAngle[i] = NewAngle[i];
            OldAngle2[i] = NewAngle2[i];
            fscanf(fin, "%f", &NewAngle[i] );
            fscanf(fin, "%f", &NewAngle2[i] );
        }
    }
    float alpha = (t%50) / 50.0;
    for(int i=0; i<20; i++){
        angle[i] = alpha * NewAngle[i] + (1-alpha) * OldAngle[i];
        angle2[i] = alpha * NewAngle2[i] + (1-alpha) * OldAngle2[i];
    }
    glutPostRedisplay();
}
void keyboard(unsigned char key, int x, int y) {
    if(key=='0') ID=0;
    if(key=='1') ID=1;
    if(key=='2') ID=2;
    if(key=='3') ID=3;
    if(key=='4') ID=4;
    if(key=='5') ID=5;
    if(key=='6') ID=6;
    if(key=='7') ID=7;
    if(key=='8') ID=8;
    if(key=='9') ID=9;
    if(key=='s'){ ///save 三選一: save, read, play (重開)
        if(fout==NULL) fout = fopen("motion.txt", "w");
        for(int i=0; i<20; i++){
            fprintf(fout, "%.2f ", angle[i] );
            fprintf(fout, "%.2f ", angle2[i] );
        }
        fprintf(fout, "\n");
        printf("你寫了1行\n");
    }
    if(key=='r'){ ///read 三選一: save, read, play (重開)
        if(fin==NULL) fin = fopen("motion.txt", "r");
        for(int i=0; i<20; i++){
            fscanf(fin, "%f", &angle[i] );
            fscanf(fin, "%f", &angle2[i] );
        }
        glutPostRedisplay();
    }
    if(key=='p'){ ///play 三選一: save, read, play (重開)
        glutTimerFunc(0, timer, 0);
    }
}
void mouse(int button, int state, int x, int y) {
    oldX = x;
    oldY = y;
}

void motion(int x, int y) {
    teapotX += (x - oldX)/10.0; ///有不同
    teapotY += (oldY - y)/10.0; ///有不同
    angle[ID] += x - oldX;
    angle2[ID] += y - oldY; ///有不同
    oldX = x;
    oldY = y; ///有不同
    ///printf("glTranslatef(%.3f , %.3f , 0 );\n", teapotX, teapotY);
    glutPostRedisplay();
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glScalef(2,2,2);
        glTranslatef(0, -0.4, 0);
        glPushMatrix();
            glColor3f(1,1,1);///glColor3f(1,0,0);
            glScalef(0.03, 0.03, 0.03);
            glRotatef(180, 0, 1, 0);
            glmDraw(body, GLM_MATERIAL | GLM_TEXTURE); ///glmDraw(gundam, GLM_MATERIAL | GLM_TEXTURE);

            glPushMatrix();
                glTranslatef(0.000 , +22.300 , 0 );
                glRotatef(angle[0], 0, 1, 0);
                glRotatef(angle2[0], 1, 0, 0);
                glTranslatef(0.000 , -22.300 , 0 );
                glmDraw(head, GLM_MATERIAL | GLM_TEXTURE);
            glPopMatrix();

            glPushMatrix();
                glTranslatef(-3.800 , +21.200 , 0 );
                glRotatef(angle[1], 0, 1, 0);
                glRotatef(angle2[1], 1, 0, 0);
                glTranslatef(3.800 , -21.200 , 0 );
                glmDraw(arm1, GLM_MATERIAL | GLM_TEXTURE);
                glPushMatrix();
                    glTranslatef(-4.300 , +18.600 , 0 );
                    glRotatef(angle[2], 0, 1, 0);
                    glRotatef(angle2[2], 1, 0, 0);
                    glTranslatef(4.300 , -18.600 , 0 );
                    glmDraw(hand1, GLM_MATERIAL | GLM_TEXTURE);
                glPopMatrix();
            glPopMatrix();

            glPushMatrix();
                glTranslatef(+3.800 , +21.200 , 0 );
                glRotatef(angle[3], 0, 1, 0);
                glRotatef(angle2[3], 1, 0, 0);
                glTranslatef(-3.800 , -21.200 , 0 );
                glmDraw(arm2, GLM_MATERIAL | GLM_TEXTURE);
                glPushMatrix();
                    glTranslatef(+4.300 , +18.600 , 0 );
                    glRotatef(angle[4], 0, 1, 0);
                    glRotatef(angle2[4], 1, 0, 0);
                    glTranslatef(-4.300 , -18.600 , 0 );
                    glmDraw(hand2, GLM_MATERIAL | GLM_TEXTURE);
                glPopMatrix();
            glPopMatrix();

            glmDraw(bot, GLM_MATERIAL | GLM_TEXTURE);

            glPushMatrix();///左大腿
                glTranslatef(-2.000 , +14.100 , 0 );
                glRotatef(angle[5], 0, 1, 0);
                glRotatef(angle2[5], 1, 0, 0);
                glTranslatef(2.000 , -14.100 , 0 );
                glmDraw(leg1, GLM_MATERIAL | GLM_TEXTURE);

                glPushMatrix();
                    glTranslatef(-2.000 , +10.500 , 0 );
                    glRotatef(angle[6], 0, 1, 0);
                    glRotatef(angle2[6], 1, 0, 0);
                    glTranslatef(2.000 , -10.500 , 0 );
                    glmDraw(knee1, GLM_MATERIAL | GLM_TEXTURE);

                    glPushMatrix();
                        glTranslatef(-2.000 , +3.000 , 0 );
                        glRotatef(angle[7], 0, 1, 0);
                        glRotatef(angle2[7], 1, 0, 0);
                        glTranslatef(2.000 , -3.000 , 0 );
                        glmDraw(foot1, GLM_MATERIAL | GLM_TEXTURE);
                    glPopMatrix();
                glPopMatrix();
            glPopMatrix();

            glPushMatrix();///右大腿
                glTranslatef(+2.000 , +14.100 , 0 );
                glRotatef(angle[8], 0, 1, 0);
                glRotatef(angle2[8], 1, 0, 0);
                glTranslatef(-2.000 , -14.100 , 0 );
                glmDraw(leg2, GLM_MATERIAL | GLM_TEXTURE);

                glPushMatrix();
                    glTranslatef(+2.000 , +10.500 , 0 );
                    glRotatef(angle[9], 0, 1, 0);
                    glRotatef(angle2[9], 1, 0, 0);
                    glTranslatef(-2.000 , -10.500 , 0 );
                    glmDraw(knee2, GLM_MATERIAL | GLM_TEXTURE);

                    glPushMatrix();
                        glTranslatef(+2.000 , +3.000 , 0 );
                        glRotatef(angle[10], 0, 1, 0);
                        glRotatef(angle2[10], 1, 0, 0);
                        glTranslatef(-2.000 , -3.000 , 0 );
                        glmDraw(foot2, GLM_MATERIAL | GLM_TEXTURE);
                    glPopMatrix();
                glPopMatrix();
            glPopMatrix();

        glPopMatrix();
        glColor3f(0,1,0);///中心點的位置
        glutSolidTeapot( 0.01 );///中心點的位置
    glPopMatrix();

    glutSwapBuffers();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week16");

    glutDisplayFunc(display);
    glutMotionFunc(motion);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);

    head = glmReadOBJ("model/head.obj");
    body = glmReadOBJ("model/body.obj"); ///gundam = glmReadOBJ("model/gundam.obj");
    arm1 = glmReadOBJ("model/arm1.obj");
    arm2 = glmReadOBJ("model/arm2.obj");
    hand1 = glmReadOBJ("model/hand1.obj");
    hand2 = glmReadOBJ("model/hand2.obj");
    bot = glmReadOBJ("model/bot.obj");
    leg1 = glmReadOBJ("model/leg1.obj");
    leg2 = glmReadOBJ("model/leg2.obj");
    knee1 = glmReadOBJ("model/knee1.obj");
    knee2 = glmReadOBJ("model/knee2.obj");
    foot1 = glmReadOBJ("model/foot1.obj");
    foot2 = glmReadOBJ("model/foot2.obj");
    myTexture("model/Diffuse.jpg");
    glEnable(GL_DEPTH_TEST);

    glutMainLoop();
}
```