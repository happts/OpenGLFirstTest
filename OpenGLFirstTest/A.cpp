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

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
    glVertex2f(-1, -0.5);
    glVertex2f(-0.5, 0.5);
    glVertex2f(0.5, 0.5);
    glVertex2f(0.5, -0.5);
    glEnd();
    
    glFlush();
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
