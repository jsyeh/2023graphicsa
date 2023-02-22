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