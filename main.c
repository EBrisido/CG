//
//  main.c
//  Projeto PS
//
//  Created by Eliel Brisido on 01/09/17.
//  Copyright © 2017 Eliel Brisido. All rights reserved.
//

#include <GLUT/GLUT.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define pi 3.142857

// c e d acompanha a quantidade de tempo 'b' e 'n' pressionados respectivamente
// left e right indica o indice mais a esquerda e a direita do retangulo movel
int c = 0, d = 0, left = 0, right = 0;
int m = 0, j = 1, flag1 = 0, l = 1, flag2 = 0, n = 0, score = 0, count = 1 , vidas = 3;
char texto [30];
GLfloat RF = 0, GF = 0, BF = 0, R = 0 , G = 1 , B = 0 ; // Variaveis para troca da cor de fundo e troca da cor dos objetos

void DesenhaTexto(void *font, char *string)
{
    // Exibe caractere a caractere
    while(*string)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*string++);
}

void DesenhaTextoStroke(void *font, char *string)
{
    // Exibe caractere a caractere
    while(*string)
        glutStrokeCharacter(GLUT_STROKE_ROMAN,*string++);
}

// Inicializacao
void myInit (void)
{
    // Cor de fundo
    glClearColor(RF, GF, BF, 0.0);

    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    // tamanho da janela
    gluOrtho2D(-620.0, 620.0, -340.0, 340.0);
}

void DesenhaGO(void)
{
    // Limpa a janela de visualização com a cor de fundo definida
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Posição no universo onde o texto bitmap será colocado
    glColor3f(0,0,1); // azul
    //glScalef(0.1, 0.1, 0.1); // diminui o tamanho do fonte
    //glRotatef(15, 0,0,1); // rotaciona o texto
    glRasterPos2f(-80,-10);
    DesenhaTexto(GLUT_BITMAP_TIMES_ROMAN_24,"GAME OVER !!!");
    glRasterPos2f(-160,-40);
    DesenhaTexto(GLUT_BITMAP_TIMES_ROMAN_24,"Pressione 'r' para Reiniciar! :-)");
    // Exibe o desenha na janela
    glutSwapBuffers();
    
}

void DesenhaInstrucoes(void)
{
    
    // Limpa a janela de visualização com a cor de fundo definida
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1,1,1);
    glRasterPos2f(-280,-10);
    DesenhaTexto(GLUT_BITMAP_TIMES_ROMAN_24,"Mover barra para direita 'n' e para esquerda 'b'");
    glRasterPos2f(-280,-200);
    DesenhaTexto(GLUT_BITMAP_TIMES_ROMAN_24,"Para Mover a Bolinha segura a barra de espaco");
    glRasterPos2f(-200,200);
    DesenhaTexto(GLUT_BITMAP_TIMES_ROMAN_24,"Para Reiniciar o Jogo pressione `r`");
    // Exibe o desenha na janela
    glutSwapBuffers();
    
}

void myDisplay(void)
{
    // x e y matem o ponto na circunferencia do circulo
    int x, y, k;
    // for faz o movimento da bola
    for (k = 0; k <= 1000; k += 15) // k < 1000 significa a quantidade de interacoes da bolinha ate o proximo movimento do teclado, quanto mair o crescimento do k
    {                               // melhor a movimentacao, porem a bolinha para mais rapido
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_LINE_LOOP); // primitiva q vai desenhando linhas ponto a ponto
        // i acompanha o angulo
        float i = 0;
        // a mudanca do m indica movimento na direcao vertical e
        // a mudanca do n indica movimento na direcao horizontal
        m = m + 6;
        n = n + 4;
        // desenha a bola no centro do circulo em (0,12) iterado ate 2*pi, ou seja, 360 graus
        while (i <= 2 * pi)
        {
            y = 12 + 20 * cos(i); // posicao inicial em y
            x = 20 * sin(i); // posicao inicial em x
            i = i + 0.1;
            // flag1 e 0 para mostrar o movimento na direcao pra cima e 1 pra baixo
            if (m == 288 && flag1 == 0) // m == 288 limitacao da tela parte positiva na vertical
            {
                j = -1; //indica na equacao movimentacao negativa
                m = -288; // 288 limitacao da tela parte negativa
                flag1 = 1; // seta movimentacao para baixo
                score++;
                
            }
            if (m == 288 && flag1 == 1) // m == 288 limitacao da tela parte positiva na vertical
            {
                j = 1; // indica na equacao movimento positivo
                m = -288; // 288 limitacao da tela parte negativa
                flag1 = 0; // seta movimentacao para cima
            }
            // flag2 e 0 para mostrar o movimento pra direita e 1 para esquerda
            if (n == 580 && flag2 == 0)
            {
                l = -1; // indica na equacao movimentacao negativa
                n = -580; // limitacao negativa da tela
                flag2 = 1; // apos chegar ao limite seta movimentacao para esquerda
            }
            if (n == 580 && flag2 == 1)
            {
                l = 1; // indica na equacao movimentacao positiva
                n = -580; // limitacao negativa da tela
                flag2 = 0; // apos chegar ao limite seta movimentacao para direita
            }
            // equacao do movimento da bola
            glVertex2i((x - l * n), (y - j * m)); // redesenha os pontos da bola de acordo com a movimentacao
                                                  //
        }
        glEnd();
        
        // determina o retangulo externo
        glBegin(GL_LINE_LOOP);
        glVertex2i(-600, -320);
        glVertex2i(-600, 320);
        glVertex2i(600, 320);
        glVertex2i(600, -320);
        glEnd();
        
        // retangulo que pega a bola
        glBegin(GL_QUADS);
        left = -200 + 200 * (d - c); // seta posicao inicial e varia de acordo com pressionado ( d - c ) compensa a direcao um do outro
        right = 200 + 200 * (d - c); // seta posicao inicial e varia de acordo com pressionado ( d - c ) compensa a direcao um do outro
        glVertex2i(left, -315);
        glVertex2i(left, -295);
        glVertex2i(right, -295);
        glVertex2i(right, -315);
        glEnd();
        
        
        glColor3f(R,G,B);
        
        //converte o valor do Score para string
        char scoreStr[3];
        sprintf(scoreStr, "%i", score);
        
        //Exibe valor Score
        glPushMatrix();
        //Posicao do Score na Tela
        glTranslatef(-500,290,0);
        glScalef(0.2, 0.2, 0.2); // diminui o tamanho do fonte
        //glRotatef(15, 0,0,1); // rotaciona o texto
        glLineWidth(2); // define a espessura da linha
        DesenhaTextoStroke(GLUT_STROKE_ROMAN,scoreStr);
        glPopMatrix();
        
        //Exibe texto Score
        glPushMatrix();
        //Posicao do Score na Tela
        glTranslatef(-590,292,0);
        glScalef(0.2, 0.2, 0.2); // diminui o tamanho do fonte
        //glRotatef(15, 0,0,1); // rotaciona o texto
        glLineWidth(2); // define a espessura da linha
        DesenhaTextoStroke(GLUT_STROKE_ROMAN,"Score:");
        glPopMatrix();
        
        //converte o valor de vidas para string
        char vidasStr[3];
        sprintf(vidasStr, "%i", vidas);
        
        //Exibe valor das vidas
        glPushMatrix();
        //Posicao das vidas na tela
        glTranslatef(570,290,0); // posicao na tela
        glScalef(0.2, 0.2, 0.2); // diminui o tamanho do fonte
        glLineWidth(2); // define a espessura da linha
        DesenhaTextoStroke(GLUT_STROKE_ROMAN,vidasStr);
        glPopMatrix();
        
        //Exibe string de vidas
        glPushMatrix();
        //Posicao da string vidas na tela
        glTranslatef(490,290,0); // posicao na tela
        glScalef(0.2, 0.2, 0.2); // diminui o tamanho do fonte
        glLineWidth(2); // define a espessura da linha
        DesenhaTextoStroke(GLUT_STROKE_ROMAN,"Vidas:");
        glPopMatrix();
        
        
        // verificacao se a bola caiu no retangulo ou nao
        if ((j * m) == 288) // significa q j negativo indicando q a bolinha esta descendo e m negativo, indicando movimentacao negativa
        {                   // ao chegar no limite da parte inferior 288 ( q e o limite abaixo da barra verifica-se se caiu a direita ou a esquerda da mesma
            if ((left > ((-1 * l * n) + 22)) || (right < (-1 * l * n) - 22)) // verifica se a bola passou o limite a esquerda ou a direita
            {
                vidas--;
                
                if ( vidas <= 0){
                    vidas = 0;
                    glutDisplayFunc(DesenhaGO);
                }
            }
            
        }
        glutSwapBuffers();
    }
}

// keyboard : ativa quando tem um botao pressionado
void keyboard(unsigned char key, int x, int y)
{
    left = -200 + 200 * (d - c); // altera a movimentacao do desenho na funcao MyDisplay
    right = 200 + 200 * (d - c); // altera a movimentacao do desenho na funcao MyDisplay
    
    // se o indice da janela mais a esquerda for atingido
    // entao retangulo nao se movera mais a esquerda enquanto b estiver pressionado
    // so se move para a direita quando pressionar n
    if (left == -600)
    {
        // '110' -> valor do 'n' na tabela ASCII
        // d e incrementado quando n e pressionado
        if (key == 110)
            d++;
    }
    // se o indice da janela mais a direita for atingido
    // entao o retangulo nao se movera mais a direita enquanto n estiver pressionado
    // so se move para a direita quando pressionar b
    else if (right == 600)
    {
        // '98' -> valor de 'b' na tabela ASCII
        // c e incrementado quando b e pressionado
        if (key == 98)
            c++;
    }
    // quando o retangulo esta no meio ele se move para qualuqer lado
    // dependendo do botao a ser pressionado
    else
    {
        if (key == 98)
            c++;
        if (key == 110)
            d++;
    }
    
    
    switch (key) {
        case 'R':
        case 'r':
            glutDisplayFunc(myDisplay);
            vidas = 3;
            score = 0;
            break;
        case 'I':
        case 'i':
            glutDisplayFunc(DesenhaInstrucoes);
            break;
            
            
    }
    glutPostRedisplay();
}
void MoveMouseBotaoPressionado( int x, int y)
{
    sprintf(texto, "Botao pressionado (%d),(%d)", x, y);
    glutPostRedisplay();
    
}

// verifica movimentacao do mouse
void MoveMouse( int x, int y)
{
    sprintf(texto , "(%d),(%d)", x, y);
    glutPostRedisplay();
}

void MenuFundo(int op)
{
    switch (op) {
        case 0:
            RF = 1, GF = 0, BF =0;
            glClearColor(RF, GF, BF, 0);
            break;
        case 1:
            RF = 0, GF = 1, BF = 0;
            glClearColor(RF, GF, BF, 0);
            break;
        case 2:
            RF = 0, GF = 0, BF = 1;
            glClearColor(RF, GF, BF, 0);
            break;
        case 3:
            RF = 1, GF = 1, BF = 1;
            glClearColor(RF, GF, BF, 0);
            break;
        case 4:
            RF = 0, GF = 0, BF = 0;
            glClearColor(RF, GF, BF, 0);
            break;
    }
    
    glutPostRedisplay();
}
void MenuObjetos(int op)
{
    switch (op) {
        case 0:
            R = 1, G = 0, B = 0;
            glColor3f(R, B, G);
            break;
        case 1:
            R = 0, G = 1, B = 0;
            glColor3f(R, B, G);
            break;
        case 2:
            R = 0, G = 0, B = 1;
            glColor3f(R, B, G);
            break;
        case 3:
            R = 1, G = 1, B = 1;
            glColor3f(R, B, G);
            break;
        case 4:
            R = 0, G = 0, B = 0;
            glColor3f(R, B, G);
            break;
    }
    
    glutPostRedisplay();
}

void MenuPrincipal( int op)
{
    
}

void myCreateMenu()
{
    int menu, submenu1, submenu2;
    
    submenu1 = glutCreateMenu(MenuFundo);
    glutAddMenuEntry("Vermelho", 0);
    glutAddMenuEntry("Verde", 1);
    glutAddMenuEntry("Azul", 2);
    glutAddMenuEntry("Branco", 3);
    glutAddMenuEntry("Preto", 4);
    
    submenu2 = glutCreateMenu(MenuObjetos);
    glutAddMenuEntry("Vermelho", 0);
    glutAddMenuEntry("Verde", 1);
    glutAddMenuEntry("Azul", 2);
    glutAddMenuEntry("Branco", 3);
    glutAddMenuEntry("Preto", 4);
    
    menu = glutCreateMenu(MenuPrincipal);
    glutAddSubMenu("Fundo", submenu1);
    glutAddSubMenu("Objetos", submenu2);
    
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    
    
}

void myMouse ( int button, int state, int x, int y)
{
    if( button == GLUT_RIGHT_BUTTON)
        if( state == GLUT_DOWN)
            myCreateMenu();
    
    glutPostRedisplay();

}
// Principal
int main (int argc, char** argv)
{
    glutInit(&argc, argv);
    
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    // tamanho da janela
    glutInitWindowSize(1200, 600);
    
    // Posicao da janela
    glutInitWindowPosition(0, 0);
    
    // Nome da Janela
    glutCreateWindow("Tenis");
    
    // Funcoes do Teclado
    glutKeyboardFunc(keyboard);
    
    glutDisplayFunc(myDisplay);
    
    glutMotionFunc(MoveMouseBotaoPressionado);
    glutPassiveMotionFunc(MoveMouse);
    glutMouseFunc(myMouse);
    // chama inicializacao
    myInit();
    glutMainLoop();
}
