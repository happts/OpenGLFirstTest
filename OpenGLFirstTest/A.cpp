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
    glPointSize(5.0f);
    glBegin(GL_POINTS);
//    glVertex2i(x,y);
    glVertex2f(x, y);
    glEnd();
    glFlush();
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
//    glBegin(GL_POLYGON);
//    glVertex2f(-1, -0.5);
//    glVertex2f(-0.5, 0.5);
//    glVertex2f(0.5, 0.5);
//    glVertex2f(0.5, -0.5);
//    glEnd();
//
    setPixel(0, 0);
    setPixel(0.1, 0.1);
    setPixel(0.2, 0.2);
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("绘制矩形");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
