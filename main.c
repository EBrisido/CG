//
//  main.c
//  Projeto PS
//
//  Created by Eliel Brisido on 04/12/17.
//  Copyright © 2017 Eliel Brisido. All rights reserved.
//

#include <GLUT/GLUT.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

GLUquadricObj *quadratic; // declaracao para usar quadric

GLfloat angleboca = 0,anglebocasup = 0, anglesombesq = 0, anglesombdir =0, tsombesq = 0, tsombdir = 0;
GLfloat tolhoesqX = 0, tolhodirX = 0, tolhoesqY = 0, tolhodirY = 0;
GLfloat angle, fAspect;
GLfloat obsX = 0, obsY =80, obsZ =200;
GLfloat Rcalca = 0.3f, Gcalca = 0.5f, Bcalca = 0.8f;
GLfloat Rcamisa = 1.0f, Gcamisa = 1.0f, Bcamisa = 1.0f;
int count = 0, counttxt = 0;


// Função callback chamada para fazer o desenho
void DesenhaHomer(void)
{
    // Limpa a janela e o depth buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // -----------CABECA-------------- //
    //suporte da cabeca ------
    glColor3f(1.0f, 1.0f, 0.2f);
    glPushMatrix();
    glTranslated(0, 0, 0);
    glRotated(90, 0, 0, 0);
    gluCylinder(quadratic = gluNewQuadric(), 10.0f, 10.0f, 25, 32, 32);
    glPopMatrix();
    //topo da cabeca----------
    glColor3f(1.0f, 1.0f, 0.2f);
    glPushMatrix();
    glTranslated(0, 0, 0);
    //glRotated(90, 0, 0, 0);
    glutSolidSphere(10, 30, 30);
    glPopMatrix();
    // ---- SOMBRANCELHAS ----
    //sombrancelha esquerda
    glColor3f(0, 0, 0);
    glPushMatrix();
    glTranslatef(-3.5, tsombesq, 0);
    glRotatef(anglesombesq, 0, 0, 1); // levanta sombrancelha
    glBegin(GL_QUADS);			// Face frontal
    glVertex3f(2.5, .7, 12.5);
    glVertex3f(2.5, -.7, 12.5);
    glVertex3f(-2.5, -.7, 12.5);
    glVertex3f(-2.5, .7, 12.5);
    glEnd();
    glPopMatrix();
    //sombrancelha direita
    glColor3f(0, 0, 0);
    glPushMatrix();
    glTranslatef(4, tsombdir, 0);
    glRotatef(-anglesombdir, 0, 0, 1); // levanta sombrancelha
    glBegin(GL_QUADS);			// Face frontal
    glVertex3f(2.5, .7, 12.5);
    glVertex3f(2.5, -.7, 12.5);
    glVertex3f(-2.5, -.7, 12.5);
    glVertex3f(-2.5, .7, 12.5);
    glEnd();
    glPopMatrix();
    // ------ OLHOS ----------
    //Olho esquerdo ----------
    //parte branca
    glColor3f(1.0f, 1.0f, 1.0f);
    glPushMatrix();
    glTranslated(-3, -5, 8.5);
    glutSolidSphere(4, 30, 30);
    glPopMatrix();
    //parte preta
    glColor3f(0, 0, 0);
    glPushMatrix();
    glTranslatef(-3,-5,12.55);
    glTranslatef(tolhoesqX, tolhoesqY, 0);
    gluDisk(quadratic = gluNewQuadric(), 0, 0.5, 30, 30);
    glPopMatrix();
    //Olho direito -----------
    //parte branca -----------
    glColor3f(1.0f, 1.0f, 1.0f);
    glPushMatrix();
    glTranslated(4, -5, 8.5);
    glutSolidSphere(4, 30, 30);
    glPopMatrix();
    //parte preta
    glColor3f(0, 0, 0);
    glPushMatrix();
    glTranslatef(4,-5,12.55);
    glTranslatef(tolhodirX, tolhoesqY, 0);
    gluDisk(quadratic = gluNewQuadric(), 0, 0.5, 30, 30);
    glPopMatrix();
    //nariz -------------------
    glColor3f(1.0f, 1.0f, 0.2f);
    glPushMatrix();
    glTranslatef(0.5, -9, 0);
    glRotated(0, 0, 0, 0);
    gluCylinder(quadratic = gluNewQuadric(), 2.0f, 2.0f, 14, 32, 32);
    glPopMatrix();
    //topo do nariz -----------
    glColor3f(1.0f, 1.0f, 0.2f);
    glPushMatrix();
    glTranslatef(0.5, -9, 13.7);
    //glRotated(90, 0, 0, 0);
    glutSolidSphere(2, 30, 30);
    glPopMatrix();
    //Orelhas -----------------
    //orelha esquerda
    glColor3f(1.0, 1.0, 0.2);
    glPushMatrix();
    glTranslatef(-10,-13,0);
    glRotatef(0, 0, 0, 0);
    gluDisk(quadratic = gluNewQuadric(), 0, 2, 30, 30);
    glPopMatrix();
    //orelha direita
    glColor3f(1.0, 1.0, 0.2);
    glPushMatrix();
    glTranslatef(10,-13,0);
    glRotatef(0, 0, 0, 0);
    gluDisk(quadratic = gluNewQuadric(), 0, 2, 30, 30);
    glPopMatrix();
    //Cabelo Topo ------------
    glColor3f(0.8, 0.5, 0.1);
    glPushMatrix();
    glTranslatef(0,6,5); //frontal
    glRotatef(0, 0, 0, 0);
    glutSolidTorus(0.25, 5, 30, 30);
    glPopMatrix();
    glColor3f(0.8, 0.5, 0.1);
    glPushMatrix();
    glTranslatef(0,7,0); //tras
    glRotatef(0, 0, 0, 0);
    glutSolidTorus(0.25, 5, 30, 30);
    glPopMatrix();
    // Boca ------------------
    // parte superior
    glColor3f(0.9, 0.8, 0.0);
    glPushMatrix();
    glTranslatef(0.35, -15, 7);
    glRotatef(-90, 0, 0, 0);
    glRotatef(anglebocasup, 1, 0, 0);
    glutSolidCone(7, 6, 30, 30);
    glPopMatrix();
    //parte inferior
    glColor3f(0.9, 0.8, 0.0);
    glPushMatrix();
    glTranslatef(0.35, -15, 7);
    glRotatef(90, 0, 0, 0);
    glRotatef(angleboca, 1, 0, 0);// mexe a boca
    glutSolidCone(7, 4, 30, 30);
    glPopMatrix();
    //--------------TRONCO------------------ //
    //parte superior
    glColor3f(Rcamisa, Gcamisa, Bcamisa);
    glPushMatrix();
    glTranslated(0, -38, 0);
    glutSolidSphere(17, 30, 30);
    glPopMatrix();
    //parte inferior
    glColor3f(Rcamisa, Gcamisa, Bcamisa);
    glPushMatrix();
    glTranslated(0, -51, 0);
    glutSolidSphere(22, 30, 30);
    glPopMatrix();
    //parte do inicio da calca
    glColor3f(Rcalca, Gcalca, Bcalca);
    glPushMatrix();
    glTranslated(0, -63.5, 0);
    glRotatef(90, 0, 0, 0);
    glutSolidTorus(6, 14, 30, 30);
    glPopMatrix();
    glColor3f(Rcalca, Gcalca, Bcalca);
    glPushMatrix();
    glTranslated(0, -59.2, 0);
    glutSolidSphere(16, 30, 30);
    glPopMatrix();
    //gola da camisa
    glColor3f(Rcamisa, Gcamisa, Bcamisa);
    glPushMatrix();
    glTranslated(0, -25, 0);
    glRotatef(90, 0, 0, 0);
    glutSolidTorus(1, 10, 30, 30);
    glPopMatrix();
    //--------------PERNAS-------------//
    //perna esquerda------------
    glColor3f(Rcalca, Gcalca, Bcalca);
    glPushMatrix();
    glTranslated(-8, -68, 0);
    glRotated(90, 0, 0, 0);
    gluCylinder(quadratic = gluNewQuadric(), 7.0f, 7.0f, 30, 32, 32);
    glPopMatrix();
    //perna direita
    glColor3f(Rcalca, Gcalca, Bcalca);
    glPushMatrix();
    glTranslated(8, -68, 0);
    glRotated(90, 0, 0, 0);
    gluCylinder(quadratic = gluNewQuadric(), 7.0f, 7.0f, 30, 32, 32);
    glPopMatrix();
    //pe esquerdo
    glColor3f(0.5f, 0.5f, 0.5f);
    glPushMatrix();
    glTranslated(-8, -101, 0);
    glRotated(-15, 0, 1, 0);
    glutSolidCube(9.8);
    glPopMatrix();
    glPushMatrix();
    glTranslated(-9.5, -102, 3);
    glRotated(-15, 0, 1, 0);
    gluCylinder(quadratic = gluNewQuadric(), 5.0f, 5.0f, 8, 32, 32);
    glPopMatrix();
    glPopMatrix();
    glPushMatrix();
    glTranslated(-11.5, -102, 10);
    glRotated(0, 0, 0, 0);
    glutSolidSphere(5, 30, 30);
    glPopMatrix();
    //pe direito
    glColor3f(0.5f, 0.5f, 0.5f);
    glPushMatrix();
    glTranslated(8, -101, 0);
    glRotated(15, 0, 1, 0);
    glutSolidCube(9.8);
    glPopMatrix();
    glPushMatrix();
    glTranslated(9.5, -102, 3);
    glRotated(15, 0, 1, 0);
    gluCylinder(quadratic = gluNewQuadric(), 5.0f, 5.0f, 8, 32, 32);
    glPopMatrix();
    glPushMatrix();
    glTranslated(11.5, -102, 10);
    glRotated(0, 0, 0, 0);
    glutSolidSphere(5, 30, 30);
    glPopMatrix();
    //----------------BRACOS--------------------//
    //braco esquerdo -------------
    //ombro esquerdo
    glColor3f(Rcamisa, Gcamisa, Bcamisa);
    glPushMatrix();
    glTranslated(-16, -30, 0);
    glRotated(0, 0, 0, 0);
    glutSolidSphere(6, 30, 30);
    glPopMatrix();
    //biceps
    glColor3f(1.0f, 1.0f, 0.2f);
    glPopMatrix();
    glPushMatrix();
    glTranslated(-17, -30, 0);
    glRotated(90, 0, 0, 0);
    glRotatef(-40, 0, 1, 0);
    gluCylinder(quadratic = gluNewQuadric(), 4.5f, 4.5f, 15, 32, 32);
    glPopMatrix();
    //juncao
    glColor3f(1.0f, 1.0f, 0.2f);
    glPushMatrix();
    glTranslated(-27, -42, 0);
    glRotated(0, 0, 0, 0);
    glutSolidSphere(4.5, 30, 30);
    glPopMatrix();
    //ante-braco
    glColor3f(1.0f, 1.0f, 0.2f);
    glPopMatrix();
    glPushMatrix();
    glTranslated(-27, -42, 0);
    glRotated(90, 0, 0, 0);
    glRotatef(-40, 0, 1, 0);
    gluCylinder(quadratic = gluNewQuadric(), 4.5f, 4.5f, 13, 32, 32);
    glPopMatrix();
    //mao
    glColor3f(1.0f, 1.0f, 0.2f);
    glPushMatrix();
    glTranslated(-35, -51.5, 0);
    glRotated(0, 0, 0, 0);
    glutSolidSphere(4.5, 30, 30);
    glPopMatrix();
    //dedos----
    //polegar
    glColor3f(1.0f, 1.0f, 0.2f);
    glPushMatrix();
    glTranslatef(-32, -50, 2);
    glRotated(90, 0, 0, 0);
    glRotated(20, 0, 1, 0);
    gluCylinder(quadratic = gluNewQuadric(), 1.5f, 1.5f, 5, 32, 32);
    glPopMatrix();
    //ponta do dedo
    glColor3f(1.0f, 1.0f, 0.2f);
    glPushMatrix();
    glTranslatef(-30.2, -55, 2);
    glutSolidSphere(1.5, 30, 30);
    glPopMatrix();
    //braco direito -------------
    //ombro direito
    glColor3f(Rcamisa, Gcamisa, Bcamisa);
    glPushMatrix();
    glTranslated(16, -30, 0);
    glRotated(0, 0, 0, 0);
    glutSolidSphere(6, 30, 30);
    glPopMatrix();
    //biceps
    glColor3f(1.0f, 1.0f, 0.2f);
    glPopMatrix();
    glPushMatrix();
    glTranslated(17, -30, 0);
    glRotated(90, 0, 0, 0);
    glRotatef(40, 0, 1, 0);
    gluCylinder(quadratic = gluNewQuadric(), 4.5f, 4.5f, 15, 32, 32);
    glPopMatrix();
    //juncao
    glColor3f(1.0f, 1.0f, 0.2f);
    glPushMatrix();
    glTranslated(27, -42, 0);
    glRotated(0, 0, 0, 0);
    glutSolidSphere(4.5, 30, 30);
    glPopMatrix();
    //ante-braco
    glColor3f(1.0f, 1.0f, 0.2f);
    glPopMatrix();
    glPushMatrix();
    glTranslated(27, -42, 0);
    glRotated(90, 0, 0, 0);
    glRotatef(40, 0, 1, 0);
    gluCylinder(quadratic = gluNewQuadric(), 4.5f, 4.5f, 13, 32, 32);
    glPopMatrix();
    //mao
    glColor3f(1.0f, 1.0f, 0.2f);
    glPushMatrix();
    glTranslated(35, -51.5, 0);
    glRotated(0, 0, 0, 0);
    glutSolidSphere(4.5, 30, 30);
    glPopMatrix();
    //dedos----
    //polegar
    glColor3f(1.0f, 1.0f, 0.2f);
    glPushMatrix();
    glTranslatef(32, -50, 2);
    glRotated(90, 0, 0, 0);
    glRotated(-20, 0, 1, 0);
    gluCylinder(quadratic = gluNewQuadric(), 1.5f, 1.5f, 5, 32, 32);
    glPopMatrix();
    //ponta do dedo
    glColor3f(1.0f, 1.0f, 0.2f);
    glPushMatrix();
    glTranslatef(30.2, -55, 2);
    glutSolidSphere(1.5, 30, 30);
    glPopMatrix();
    
    //-------- texto -------//
    if (counttxt == 1){
        glLineWidth(6);
        glColor3f(0, 1, 0);
        glBegin(GL_LINES);
        glVertex3i(-15, 30, 0);//F
        glVertex3i(-15, 20, 0);
        glVertex3i(-10, 30, 0);
        glVertex3i(-15, 30, 0);
        glVertex3i(-10, 25, 0);
        glVertex3i(-15, 25, 0);//F
        glVertex3i(-8, 30, 0); //E
        glVertex3i(-8, 20, 0);
        glVertex3i(-3, 30, 0);
        glVertex3i(-8, 30, 0);
        glVertex3i(-3, 25, 0);
        glVertex3i(-8, 25, 0);
        glVertex3i(-3, 20, 0);
        glVertex3i(-8, 20, 0); //E
        glVertex3i(-1, 30, 0); //L
        glVertex3i(-1, 20, 0);
        glVertex3i(4, 20, 0);
        glVertex3i(-1, 20, 0); //L
        glVertex3i(6, 30, 0); // I
        glVertex3i(6, 20, 0); // I
        glVertex3i(8, 30, 0); // Z
        glVertex3i(13, 30, 0);
        glVertex3i(8, 20, 0);
        glVertex3i(13, 30, 0);
        glVertex3i(8, 20, 0);
        glVertex3i(13, 20, 0); //Z
        glEnd();
        glFlush();
        glutPostRedisplay();
    }
    
    if (counttxt == 2){
        glLineWidth(6);
        glColor3f(0, 1, 0);
        glBegin(GL_LINES);
        glVertex3i(-37, 30, 0); //D
        glVertex3i(-37, 20, 0);
        glVertex3i(-37, 30, 0);
        glVertex3i(-34, 30, 0);
        glVertex3i(-37, 20, 0);
        glVertex3i(-34, 20, 0);
        glVertex3i(-32, 28, 0);
        glVertex3i(-32, 22, 0);
        glVertex3i(-34, 30, 0);
        glVertex3i(-32, 28, 0);
        glVertex3i(-34, 20, 0);
        glVertex3i(-32, 22, 0); //D
        glVertex3i(-30, 30, 0); //E
        glVertex3i(-30, 20, 0);
        glVertex3i(-25, 30, 0);
        glVertex3i(-30, 30, 0);
        glVertex3i(-25, 25, 0);
        glVertex3i(-30, 25, 0);
        glVertex3i(-25, 20, 0);
        glVertex3i(-30, 20, 0); //E
        glVertex3i(-18, 30, 0); //S
        glVertex3i(-23, 30, 0);
        glVertex3i(-23, 30, 0);
        glVertex3i(-23, 25, 0);
        glVertex3i(-18, 25, 0);
        glVertex3i(-23, 25, 0);
        glVertex3i(-18, 25, 0);
        glVertex3i(-18, 20, 0);
        glVertex3i(-18, 20, 0);
        glVertex3i(-23, 20, 0);//S
        glVertex3i(-16, 20, 0);//C
        glVertex3i(-16, 30, 0);
        glVertex3i(-16, 20, 0);
        glVertex3i(-11, 20, 0);
        glVertex3i(-11, 30, 0);
        glVertex3i(-16, 30, 0);//C
        glVertex3i(-4, 20, 0);//O
        glVertex3i(-4, 30, 0);
        glVertex3i(-9, 30, 0);
        glVertex3i(-9, 20, 0);
        glVertex3i(-4, 20, 0);
        glVertex3i(-9, 20, 0);
        glVertex3i(-4, 30, 0);
        glVertex3i(-9, 30, 0); //O
        glVertex3i(3, 30, 0); // N
        glVertex3i(3, 20, 0);
        glVertex3i(-2, 30, 0);
        glVertex3i(-2, 20, 0);
        glVertex3i(-2, 30, 0);
        glVertex3i(3, 20, 0); // N
        glVertex3i(6, 30, 0);//F
        glVertex3i(6, 20, 0);
        glVertex3i(6, 30, 0);
        glVertex3i(12, 30, 0);
        glVertex3i(6, 25, 0);
        glVertex3i(12, 25, 0);//F
        glVertex3i(14, 30, 0); // I
        glVertex3i(14, 20, 0); // I
        glVertex3i(16, 20, 0); // A
        glVertex3i(19, 30, 0);
        glVertex3i(22, 20, 0);
        glVertex3i(19, 30, 0);
        glVertex3i(18, 25, 0);
        glVertex3i(20, 25, 0);// A
        glVertex3i(24, 30, 0); //D
        glVertex3i(24, 20, 0);
        glVertex3i(24, 30, 0);
        glVertex3i(27, 30, 0);
        glVertex3i(24, 20, 0);
        glVertex3i(27, 20, 0);
        glVertex3i(29, 28, 0);
        glVertex3i(29, 22, 0);
        glVertex3i(27, 30, 0);
        glVertex3i(29, 28, 0);
        glVertex3i(27, 20, 0);
        glVertex3i(29, 22, 0); //D
        glVertex3i(31, 20, 0);//O
        glVertex3i(31, 30, 0);
        glVertex3i(36, 30, 0);
        glVertex3i(36, 20, 0);
        glVertex3i(31, 20, 0);
        glVertex3i(36, 20, 0);
        glVertex3i(31, 30, 0);
        glVertex3i(36, 30, 0); //O
        glEnd();
        glFlush();
        glutPostRedisplay();
    }
    
    if(counttxt == 3){
        glLineWidth(6);
        glColor3f(0, 1, 0);
        glBegin(GL_LINES);
        glVertex3i(-20, 30, 0); //S
        glVertex3i(-25, 30, 0);
        glVertex3i(-25, 30, 0);
        glVertex3i(-25, 25, 0);
        glVertex3i(-20, 25, 0);
        glVertex3i(-25, 25, 0);
        glVertex3i(-20, 25, 0);
        glVertex3i(-20, 20, 0);
        glVertex3i(-20, 20, 0);
        glVertex3i(-25, 20, 0);//S
        glVertex3i(-13, 20, 0);//U
        glVertex3i(-13, 30, 0);
        glVertex3i(-18, 30, 0);
        glVertex3i(-18, 20, 0);
        glVertex3i(-13, 20, 0);
        glVertex3i(-18, 20, 0); //U
        glVertex3i(-11, 30, 0);//R
        glVertex3i(-11, 20, 0);
        glVertex3i(-11, 30, 0);
        glVertex3i(-6, 30, 0);
        glVertex3i(-11, 25, 0);
        glVertex3i(-6, 25, 0);
        glVertex3i(-6, 30, 0);
        glVertex3i(-6, 25, 0);
        glVertex3f(-8.5, 25, 0);
        glVertex3f(-6, 20, 0);//R
        glVertex3i(-4, 30, 0); // P
        glVertex3i(-4, 20, 0);
        glVertex3i(-4, 30, 0);
        glVertex3i(1, 30, 0);
        glVertex3i(-4, 25, 0);
        glVertex3i(1, 25, 0);
        glVertex3i(1, 30, 0);
        glVertex3i(1, 25, 0); //P
        glVertex3i(3, 30, 0);//R
        glVertex3i(3, 20, 0);
        glVertex3i(3, 30, 0);
        glVertex3i(8, 30, 0);
        glVertex3i(3, 25, 0);
        glVertex3i(8, 25, 0);
        glVertex3i(8, 30, 0);
        glVertex3i(8, 25, 0);
        glVertex3f(5.5, 25, 0);
        glVertex3f(8, 20, 0);//R
        glVertex3i(10, 30, 0); //E
        glVertex3i(10, 20, 0);
        glVertex3i(15, 30, 0);
        glVertex3i(10, 30, 0);
        glVertex3i(15, 25, 0);
        glVertex3i(10, 25, 0);
        glVertex3i(15, 20, 0);
        glVertex3i(10, 20, 0); //E
        glVertex3i(22, 30, 0); //S
        glVertex3i(17, 30, 0);
        glVertex3i(17, 30, 0);
        glVertex3i(17, 25, 0);
        glVertex3i(22, 25, 0);
        glVertex3i(17, 25, 0);
        glVertex3i(22, 25, 0);
        glVertex3i(22, 20, 0);
        glVertex3i(22, 20, 0);
        glVertex3i(17, 20, 0);//S
        glVertex3i(29, 20, 0);//O
        glVertex3i(29, 30, 0);
        glVertex3i(24, 30, 0);
        glVertex3i(24, 20, 0);
        glVertex3i(29, 20, 0);
        glVertex3i(24, 20, 0);
        glVertex3i(29, 30, 0);
        glVertex3i(24, 30, 0);//O
        glEnd();
        glFlush();
        glutPostRedisplay();
    }
    
    if (counttxt == 4){
        glLineWidth(6);
        glColor3f(0, 1, 0);
        glBegin(GL_LINES);
        glVertex3i(-12, 30, 0); //T
        glVertex3i(-17, 30, 0);
        glVertex3f(-14.5, 30, 0);
        glVertex3f(-14.5, 20, 0); // T
        glVertex3i(-10, 30, 0);//R
        glVertex3i(-10, 20, 0);
        glVertex3i(-10, 30, 0);
        glVertex3i(-5, 30, 0);
        glVertex3i(-10, 25, 0);
        glVertex3i(-5, 25, 0);
        glVertex3i(-5, 30, 0);
        glVertex3i(-5, 25, 0);
        glVertex3f(-8.5, 25, 0);
        glVertex3f(-5, 20, 0);//R
        glVertex3i(-3, 30, 0); // I
        glVertex3i(-3, 20, 0); // I
        glVertex3i(4, 30, 0); //S
        glVertex3i(-1, 30, 0);
        glVertex3i(-1, 30, 0);
        glVertex3i(-1, 25, 0);
        glVertex3i(4, 25, 0);
        glVertex3i(-1, 25, 0);
        glVertex3i(4, 25, 0);
        glVertex3i(4, 20, 0);
        glVertex3i(4, 20, 0);
        glVertex3i(-1, 20, 0);//S
        glVertex3i(11, 30, 0); //T
        glVertex3i(6, 30, 0);
        glVertex3f(8.5, 30, 0);
        glVertex3f(8.5, 20, 0); // T
        glVertex3i(13, 30, 0); //E
        glVertex3i(13, 20, 0);
        glVertex3i(18, 30, 0);
        glVertex3i(13, 30, 0);
        glVertex3i(18, 25, 0);
        glVertex3i(13, 25, 0);
        glVertex3i(18, 20, 0);
        glVertex3i(13, 20, 0); //E
        glEnd();
        glFlush();
        glutPostRedisplay();
    }
    
    if( counttxt == 5){
        glLineWidth(6);
        glColor3f(0, 1, 0);
        glBegin(GL_LINES);
        glVertex3i(-13, 30, 0);//R
        glVertex3i(-13, 20, 0);
        glVertex3i(-13, 30, 0);
        glVertex3i(-9, 30, 0);
        glVertex3i(-13, 25, 0);
        glVertex3i(-9, 25, 0);
        glVertex3i(-9, 30, 0);
        glVertex3i(-9, 25, 0);
        glVertex3f(-11.5, 25, 0);
        glVertex3f(-9, 20, 0);//R
        glVertex3i(-7, 20, 0); // A
        glVertex3i(-5, 30, 0);
        glVertex3i(-2, 20, 0);
        glVertex3i(-5, 30, 0);
        glVertex3i(-6, 24, 0);
        glVertex3i(-3, 24, 0);// A
        glVertex3i(0, 30, 0); // I
        glVertex3i(0, 20, 0); // I
        glVertex3i(4, 20, 0); //V
        glVertex3i(2, 30, 0);
        glVertex3i(4, 20, 0);
        glVertex3i(7, 30, 0);//V
        glVertex3i(7, 20, 0); // A
        glVertex3i(9, 30, 0);
        glVertex3i(12, 20, 0);
        glVertex3i(9, 30, 0);
        glVertex3i(8, 24, 0);
        glVertex3i(11, 24, 0);// A
        glEnd();
        glFlush();
        glutPostRedisplay();
    }
    
    if (counttxt == 6){
        glLineWidth(6);
        glColor3f(0, 1, 0);
        glBegin(GL_LINES);
        glVertex3i(-30, 30, 0); //E
        glVertex3i(-30, 20, 0);
        glVertex3i(-25, 30, 0);
        glVertex3i(-30, 30, 0);
        glVertex3i(-25, 25, 0);
        glVertex3i(-30, 25, 0);
        glVertex3i(-25, 20, 0);
        glVertex3i(-30, 20, 0); //E
        glVertex3i(-18, 30, 0); // N
        glVertex3i(-18, 20, 0);
        glVertex3i(-23, 30, 0);
        glVertex3i(-23, 20, 0);
        glVertex3i(-23, 30, 0);
        glVertex3i(-18, 20, 0); // N
        glVertex3i(-11, 30, 0); //T
        glVertex3i(-16, 30, 0);
        glVertex3f(-13.5, 30, 0);
        glVertex3f(-13.5, 20, 0); // T
        glVertex3i(-9, 30, 0); //E
        glVertex3i(-9, 20, 0);
        glVertex3i(-4, 30, 0);
        glVertex3i(-9, 30, 0);
        glVertex3i(-4, 25, 0);
        glVertex3i(-9, 25, 0);
        glVertex3i(-4, 20, 0);
        glVertex3i(-9, 20, 0); //E
        glVertex3i(-2, 30, 0); //D
        glVertex3i(-2, 20, 0);
        glVertex3i(-2, 30, 0);
        glVertex3i(1, 30, 0);
        glVertex3i(-2, 20, 0);
        glVertex3i(1, 20, 0);
        glVertex3i(3, 28, 0);
        glVertex3i(3, 22, 0);
        glVertex3i(1, 30, 0);
        glVertex3i(3, 28, 0);
        glVertex3i(1, 20, 0);
        glVertex3i(3, 22, 0); //D
        glVertex3i(5, 30, 0); // I
        glVertex3i(5, 20, 0); // I
        glVertex3i(7, 20, 0); // A
        glVertex3i(9, 30, 0);
        glVertex3i(12, 20, 0);
        glVertex3i(9, 30, 0);
        glVertex3i(8, 24, 0);
        glVertex3i(11, 24, 0);// A
        glVertex3i(14, 30, 0); //D
        glVertex3i(14, 20, 0);
        glVertex3i(14, 30, 0);
        glVertex3i(17, 30, 0);
        glVertex3i(14, 20, 0);
        glVertex3i(17, 20, 0);
        glVertex3i(19, 28, 0);
        glVertex3i(19, 22, 0);
        glVertex3i(17, 30, 0);
        glVertex3i(19, 28, 0);
        glVertex3i(17, 20, 0);
        glVertex3i(19, 22, 0); //D
        glVertex3i(26, 20, 0);//O
        glVertex3i(26, 30, 0);
        glVertex3i(21, 30, 0);
        glVertex3i(21, 20, 0);
        glVertex3i(26, 20, 0);
        glVertex3i(21, 20, 0);
        glVertex3i(26, 30, 0);
        glVertex3i(21, 30, 0);//O
        glEnd();
        glFlush();
        glutPostRedisplay();
        
    }
    glFlush();
    glutSwapBuffers();
}

// Inicializa parâmetros de rendering
void Inicializa (void)
{
    GLfloat luzAmbiente[4]={0.2,0.2,0.2,1.0};
    GLfloat luzDifusa[4]={0.7,0.7,0.7,1.0};		 // "cor"
    GLfloat luzEspecular[4]={1.0, 1.0, 1.0, 1.0};// "brilho"
    GLfloat posicaoLuz[4]={0.0, 50.0, 50.0, 1.0};
    
    // Capacidade de brilho do material
    GLfloat especularidade[4]={1.0,1.0,1.0,1.0};
    GLint especMaterial = 60;
    
    // Especifica que a cor de fundo da janela será preta
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    
    // Habilita o modelo de colorização de Gouraud
    glShadeModel(GL_SMOOTH);
    
    // Define a refletância do material
    glMaterialfv(GL_FRONT,GL_SPECULAR, especularidade);
    // Define a concentração do brilho
    glMateriali(GL_FRONT,GL_SHININESS,especMaterial);
    
    // Ativa o uso da luz ambiente
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);
    
    // Define os parâmetros da luz de número 0
    glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa );
    glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular );
    glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz );
    
    // Habilita a definição da cor do material a partir da cor corrente
    glEnable(GL_COLOR_MATERIAL);
    //Habilita o uso de iluminação
    glEnable(GL_LIGHTING);
    // Habilita a luz de número 0
    glEnable(GL_LIGHT0);
    // Habilita o depth-buffering
    glEnable(GL_DEPTH_TEST);
    
    angle=50;
}

// Função usada para especificar o volume de visualização
void EspecificaParametrosVisualizacao(void)
{
    // Especifica sistema de coordenadas de projeção
    glMatrixMode(GL_PROJECTION);
    // Inicializa sistema de coordenadas de projeção
    glLoadIdentity();
    
    // Especifica a projeção perspectiva
    gluPerspective(angle,fAspect,0.9,1000);
    
    // Especifica sistema de coordenadas do modelo
    glMatrixMode(GL_MODELVIEW);
    // Inicializa sistema de coordenadas do modelo
    glLoadIdentity();
    
    // Especifica posição do observador e do alvo
    gluLookAt(obsX,obsY,obsZ, 0,0,0, 0,1,0);
    
}

// Função callback chamada quando o tamanho da janela é alterado
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
    // Para previnir uma divisão por zero
    if ( h == 0 ) h = 1;
    
    // Especifica o tamanho da viewport
    glViewport(0, 0, w, h);
    
    // Calcula a correção de aspecto
    fAspect = (GLfloat)w/(GLfloat)h;
    
    EspecificaParametrosVisualizacao();
}

void GerenciaTeclado(unsigned char key, int x, int y){
    // swith para trocar posicao do observador
    switch (key) {
        case 'x':
            obsX -= 20;
            break;
        case 'X':
            obsX += 20;
            glutPostRedisplay();
            break;
        case 'y':
            obsY -= 20;
            break;
        case 'Y':
            obsY += 20;
            glutPostRedisplay();
            break;
        case 'z':
            obsZ -= 20;
            break;
        case 'Z':
            obsZ += 20;
            glutPostRedisplay();
            break;
        case 'f': // --------------------------------- FELIZ -------------------------------
            if(angleboca == 0){
                while(angleboca<10){
                    angleboca+=0.000001;
                }
            }
            if ((tsombdir && tsombesq) == 0){
                while(tsombdir<2.3){
                    tsombdir += 0.000001;
                    tsombesq += 0.000001;
                }
            }
            
            counttxt = 1;
            break;
        case 'F': // desfaz a felicidade xD
            if(angleboca >= 10 ){
                while(angleboca>0){
                    angleboca-=0.000001;
                }
            }
            if ((tsombdir && tsombesq) > 0){
                while(tsombdir>0){
                    tsombdir += -0.000001;
                    tsombesq += -0.000001;
                }
                
            }
            angleboca = 0;
            tsombesq = 0;
            tsombdir = 0;
            counttxt = 0;
            break;
        case 'd': //  ------------------------------- DESCONFIADO ---------------------------
            if ( anglesombdir == 0){
                while (anglesombdir < 15) {
                    anglesombdir += 0.000001;
                }
                while (tsombdir <2.3){
                    tsombdir += 0.00001;
                }
            }
            counttxt = 2;
            break;
        case 'D':  // nao esta mais desconfiado
            tsombdir = 0;
            anglesombdir = 0;
            counttxt = 0;
            break;
        case 'b': // ----------------------------------MEXE A BOCA -------------------------
        case 'B':
            if(angleboca == 0){
                while(angleboca<10){
                    angleboca+=0.000001;
                }
            }else{
                angleboca = 0;
            }
            break;
        case 's': //------------------------------ SURPRESO ---------------------------------
            if(angleboca == 0){
                while(angleboca<10){
                    angleboca+=0.000001;
                }
            }
            if ((tsombdir && tsombesq) == 0){
                while(tsombdir<2.3){
                    tsombdir += 0.000001;
                    tsombesq += 0.000001;
                }
            }
            
            if(anglesombdir == 0){
                anglesombdir = 15;
                anglesombesq = 15;
            }
            
            if( anglebocasup == 0){
                anglebocasup = -15;
            }
            counttxt = 3;
            break;
        case 'S':
            angleboca = 0;
            anglebocasup = 0;
            anglesombesq = 0;
            anglesombdir = 0;
            tsombdir = 0;
            tsombesq = 0;
            counttxt = 0;
            break;
        case 't': // -----------------------------TRISTE -----------------------------------------
            tsombdir = -1.5;
            tsombesq = -1.5;
            tolhoesqY = -2;
            tolhodirY = -2;
            anglesombdir = 5;
            anglesombesq = 5;
            counttxt = 4;
            break;
        case 'T':
            tsombdir = 0;
            tsombesq = 0;
            tolhoesqY = 0;
            tolhodirY = 0;
            anglesombdir = 0;
            anglesombesq = 0;
            counttxt = 0;
            break;
        case 'r': // -------------------------- RAIVA ---------------------------------------------
            anglesombesq = -15;
            anglesombdir = -16;
            counttxt =5;
            break;
        case 'R':
            anglesombesq = 0;
            anglesombdir = 0;
            counttxt = 0;
            break;
        case 'e': // ------------------------- ENTEDIADO ------------------------------------------
            if(count == 0){
                tsombdir = -1.5;
                tsombesq = -1.5;
                tolhodirX = 2;
                tolhoesqX = 2;
                tolhodirY = -1;
                tolhoesqY = -1;
                count = 1;
            }else{
                count = 0;
                tolhodirX = -2;
                tolhoesqX = -2;
            }
            counttxt = 6;
            break;
        case 'E':
            count = 0;
            tsombdir = 0;
            tsombesq = 0;
            tolhodirX = 0;
            tolhoesqX = 0;
            tolhodirY = 0;
            tolhoesqY = 0;
            counttxt = 0;
            break;
    }

    EspecificaParametrosVisualizacao();
    glutPostRedisplay();
    
}
void Camisa(int op){
    switch (op) {
        case 0:
            Rcamisa = 1.0f;
            Gcamisa = 1.0f;
            Bcamisa = 1.0f;
            break;
        case 1:
            Rcamisa = 0.0f;
            Gcamisa = 0.0f;
            Bcamisa = 0.0f;
            break;
        case 2:
            Rcamisa = 0.0f;
            Gcamisa = 0.0f;
            Bcamisa = 1.0f;
            break;
        case 3:
            Rcamisa = 1.0f;
            Gcamisa = 0.0f;
            Bcamisa = 0.0f;
            break;
        case 4:
            Rcamisa = 0.0f;
            Gcamisa = 1.0f;
            Bcamisa = 0.0f;
            break;
            
    }
    glutPostRedisplay();
}

void Calcas(int op){
    
    switch (op) {
        case 0:
            Rcalca = 0.3f;
            Gcalca = 0.5f;
            Bcalca = 0.8f;
            break;
        case 1:
            Rcalca = 0.0f;
            Gcalca = 0.0f;
            Bcalca = 0.0f;
            break;
        case 2:
            Rcalca = 0.0f;
            Gcalca = 0.0f;
            Bcalca = 1.0f;
            break;
        case 3:
            Rcalca = 1.0f;
            Gcalca = 0.0f;
            Bcalca = 0.0f;
            break;
        case 4:
            Rcalca = 0.0f;
            Gcalca = 1.0f;
            Bcalca = 0.0f;
            break;
        
    }
    //glFlush();
    glutPostRedisplay();
    
}

void MenuPrincipal(int op){
    
    
}

void CriaMenu(){
    
    int menu, submenu1, submenu2;
    submenu1 = glutCreateMenu(Camisa);
    glutAddMenuEntry("Original", 0);
    glutAddMenuEntry("Preta", 1);
    glutAddMenuEntry("Azul", 2);
    glutAddMenuEntry("Vermelha", 3);
    glutAddMenuEntry("Verde", 4);
    
    submenu2 = glutCreateMenu(Calcas);
    glutAddMenuEntry("Original", 0);
    glutAddMenuEntry("Preta", 1);
    glutAddMenuEntry("Azul", 2);
    glutAddMenuEntry("Vermelha", 3);
    glutAddMenuEntry("Verde", 4);
   
    menu = glutCreateMenu(MenuPrincipal);
    glutAddSubMenu("Camisa", submenu1);
    glutAddSubMenu("Calca", submenu2);
    
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    
    
}

// Função callback chamada para gerenciar eventos do mouse
void GerenciaMouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON)// Zoom-in
            if (angle >= 10) angle -= 5;
        
    if (button == GLUT_MIDDLE_BUTTON)// Zoom-out
            if (angle <= 130) angle += 5;
    
    if (button == GLUT_RIGHT_BUTTON){
        
        if(state == GLUT_DOWN)
            CriaMenu();
    }
    
    EspecificaParametrosVisualizacao();
    glutPostRedisplay();
}

// Programa Principal
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1200,800);
    glutCreateWindow("Homer");
    glutDisplayFunc(DesenhaHomer);
    glutReshapeFunc(AlteraTamanhoJanela);
    glutKeyboardFunc(GerenciaTeclado);
    glutMouseFunc(GerenciaMouse);
    Inicializa();
    glutMainLoop();
}




