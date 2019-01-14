//
//  main.cpp
//  OpenGLFirstTest
//
//  Created by happts on 2019/1/7.
//  Copyright © 2019年 happts. All rights reserved.
//

#include <GLUT/GLUT.h>
#include <math.h>
#include <stdio.h>
//#include <OpenGL/OpenGL.h>
//#include <GLKit/GLKit.h>




void setPixel(int x,int y){
    //用OpenGL自己的函数实现书上的setPixel
    glPointSize(1.0f);
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
    glFlush();
}
void lineDDA(int x0,int y0,int xEnd,int yEnd){
    glPointSize(3.0f);//设置像素点大小
    int dx=xEnd-x0,dy=yEnd-y0,steps,k;
    float xIncrement,yIncrement,x=x0,y=y0;
    if(fabs(dx)>fabs(dy))//确定步长，谁大就取谁
        steps=fabs(dx);
    else
        steps=fabs(dy);
    xIncrement=float(dx)/float(steps);//增量当中有一个会为1，另一个会为斜率k
    yIncrement=float(dy)/float(steps);
    setPixel(round(x),round(y));//由于每次都加了小于1的增量，所以需要取整
    for(k=0;k<steps;k++){
        /*
         glBegin(GL_POINTS);
         glVertex2i((int)x,(int)y);
         glEnd();
         glFlush();
         */
        x+=xIncrement;
        y+=yIncrement;
        setPixel(round(x),round(y));
    }
}
    
void myDisplay(void){
//    glClear(GL_COLOR_BUFFER_BIT);//好像没这句话也可以啊。。初学好迷=。=
    lineDDA(50,50,200,200);
}

void init(){
    // red, green, blue, alpha
    glClearColor(1.0, 1.0, 1.0, 0.0);
    
    // project to the screen and set the location
    glMatrixMode(GL_PROJECTION);
    
    gluOrtho2D(0.0, 200.0, 0.0, 150.0);
}

void lineSegment(){
    //clear display window
    glClear(GL_COLOR_BUFFER_BIT);
    
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POINTS);
    glVertex2i(180, 15);
    glVertex2i(10, 145);
    glEnd();
    
    // Process all OpenGl routines as quickly as possible
    // 强制清空缓存来处理OpenGL函数
    glFlush();
}

int main(int argc, char** argv){
    
    glutInit(&argc, argv);                      // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);// Set display mode
    glutInitWindowPosition(500, 100);
    glutInitWindowSize(400, 300);
    glutCreateWindow("An Example OpenGL Program");
    
    init();
    glutDisplayFunc(myDisplay);// Note:function have no ()
    glutMainLoop();              // Display everything and wait
    
    return 0;
}

