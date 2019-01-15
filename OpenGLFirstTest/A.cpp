//
//  A.cpp
//  绘制矩形
//  OpenGLFirstTest
//
//  Created by app on 2019/1/14.
//  Copyright © 2019年 happts. All rights reserved.
//

#include <GLUT/GLUT.h>
#include <math.h>
#include <stdio.h>
void setPixel(GLfloat x,GLfloat y){
    //用OpenGL自己的函数实现书上的setPixel
    glPointSize(2.0f);
    glBegin(GL_POINTS);
//    glVertex2i(x,y);
//    glVertex2f(x, y);
    glVertex3f(x, y, 0);
    glEnd();
    glFlush();
}
void DDALine(float x0,float y0,float x1,float y1){
    GLfloat dx,dy,x,y;
    int deltax,deltay;
    int steps;
    deltax = x1 - x0 ;
    deltay = y1 - y0 ;
    if (fabs(deltax) > fabs(deltay)) {
        steps = fabs(deltax);
    }else {
        steps = fabs(deltay);
    }
    
    dx = (GLfloat)deltax / (GLfloat)steps;
    dy = (GLfloat)deltay / (GLfloat)steps;
    
    x = x0;
    y = y0;
    setPixel(x, y);
    
    for (int i = 1; i <= steps; i++) {
        x += dx;
        y += dy;
        setPixel(x/100, y/100);
    }
    
}
void display(){
    glClear(GL_COLOR_BUFFER_BIT);
//    glBegin(GL_POLYGON);
//    glVertex2f(-1, -0.5);
//    glVertex2f(-0.5, 0.5);
//    glVertex2f(0.5, 0.5);
//    glVertex2f(0.5, -0.5);
//    glEnd();
    
    
    DDALine(0, 0, 20, 20);
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("绘制矩形");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}


