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