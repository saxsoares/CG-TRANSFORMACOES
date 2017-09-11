#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include "Transformacoes.h"

void MovimentaMouse(int, int);
void Keyboard (unsigned char , int , int );
void SpecialKeys (int , int , int );
void Timer(int );
void Transformacoes();

GLint escala = 1;
GLint veloc = 1;
GLfloat passoX = 0.1;
GLfloat passoY = 0.1;

GLfloat preto[]={0,0,0}, branco[]={1,1,1}, verde[]={0,1,0}, vermelho[]={1,0,0}, azul[]={0,0,1}, amarelo[]={1,1,0},
        furchsia[]={1,0,1}, rosa[]={1,0.75,0.8}, rosaBri[]={1,0,0.5}, abobora[]={0.99,0.06,0.75}, ciano[]={0,1,1},
        verdeEsc[]={0, 0.39, 0}, azulEsc[]={0,0,0.55}, marinho[]={0.07,0.04,0.56}, fuligem[]={0.24,0.17,0.12},
        roxo[]={0.5,0,0.5},azulCeu[]={0.53,0.81,0.98},verdeGrama[]={0.49,0.99,0},cinzaFosco[]={0.41,0.41,0.41},
        jambo[]={1,0.27,0},laranja[]={1,0.65,0},marrom[]={0.65,0.16,0.16},cinza[]={0.5,0.5,0.5}, cinzaEsc[]={0.66,0.66,0.66};


void MovimentaMouse(int x, int y){
}

void Keyboard (unsigned char key, int x, int y){
}

void SpecialKeys (int key, int x, int y){
}
void Timer(int extra){
    passoY += 0.001;
    passoX += 0.001;
    if(1){
        glutPostRedisplay();
        glutTimerFunc(veloc,Timer,0);
    }
}

void figura(){
    glShadeModel(GL_SMOOTH);
    glBegin(GL_POLYGON);
        glColor3fv(cinzaEsc); glVertex2f( passoX + 0.0, passoY + 0.21);    //begin CABINE
        glColor3fv(cinzaFosco);
        glVertex2f( passoX + 0.005, passoY + 0.18);
        glVertex2f( passoX + 0.011, passoY + 0.17);
        glVertex2f( passoX + 0.012, passoY + 0.16);
        glVertex2f( passoX + 0.014, passoY + 0.06);
        glColor3fv(cinzaEsc); glVertex2f( passoX + 0.0, passoY + -0.01);
        glColor3fv(cinzaFosco);
        glVertex2f( passoX + -0.014, passoY + 0.06);
        glVertex2f( passoX + -0.012, passoY + 0.16);
        glVertex2f( passoX + -0.011, passoY + 0.17);
        glVertex2f( passoX + -0.005, passoY + 0.18);                        //end Cabine
    glEnd();
    glBegin(GL_POLYGON);                                                    //begin fuselagem
        glColor3fv(cinzaFosco);glVertex2f( passoX + 0.0, passoY + -0.01);
        glColor3fv(cinza);
        glVertex2f( passoX + -0.014, passoY + 0.1);
        glVertex2f( passoX + -0.020, passoY + 0.075);
        glVertex2f( passoX + -0.020, passoY + -0.0);
        glVertex2f( passoX + -0.012, passoY + -0.075);
        glColor3fv(cinzaFosco);glVertex2f( passoX + -0.007, passoY + -0.137);
        glVertex2f( passoX + 0.007, passoY + -0.137);
        glColor3fv(cinza);
        glVertex2f( passoX + 0.012, passoY + -0.075);
        glVertex2f( passoX + 0.020, passoY + -0.0);
        glVertex2f( passoX + 0.020, passoY + 0.075);
        glVertex2f( passoX + 0.014, passoY + 0.1);                          //end fuselagem
    glEnd();
    glBegin(GL_POLYGON);                                    //ASA ESQUERDA
        glVertex2f( passoX + -0.014, passoY + 0.065);
        glColor3fv(cinzaEsc);
        glVertex2f( passoX + -0.09, passoY + 0.015);
        glVertex2f( passoX + -0.09, passoY + -0.01);
        glColor3fv(cinza);glVertex2f( passoX + -0.020, passoY + 0.0);
    glEnd();
    glBegin(GL_POLYGON);                                    //ASA DIREITA
        glVertex2f( passoX + 0.014, passoY + 0.065);
        glColor3fv(cinzaEsc); glVertex2f( passoX + 0.09, passoY + 0.015);
        glVertex2f( passoX + 0.09, passoY + -0.01);
        glColor3fv(cinza);glVertex2f( passoX + 0.020, passoY + 0.0);
    glEnd();
    glBegin(GL_POLYGON);                                    //deriva ESQUERDA
        glVertex2f( passoX + -0.012, passoY + -0.075);
        glColor3fv(cinzaEsc);glVertex2f( passoX + -0.053, passoY + -0.13);
        glVertex2f( passoX + -0.053, passoY + -0.145);
        glColor3fv(cinza);glVertex2f( passoX + -0.008, passoY + -0.12);
    glEnd();
    glBegin(GL_POLYGON);                                    //deriva DIREITA
        glVertex2f( passoX + 0.012, passoY + -0.075);
        glColor3fv(cinzaEsc);glVertex2f( passoX + 0.053, passoY + -0.13);
        glVertex2f( passoX + 0.053, passoY + -0.145);
        glColor3fv(cinza);glVertex2f( passoX + 0.008, passoY + -0.12);
    glEnd();
    glLineWidth(escala*0.7);
    glBegin(GL_LINES);
        glColor3fv(preto);                                 //begin CABINE
        glVertex2f( passoX + 0.014, passoY + 0.1);
        glVertex2f( passoX + 0.0, passoY + -0.01);         //
        glVertex2f( passoX + -0.014, passoY + 0.1);
        glVertex2f( passoX + 0.0, passoY + -0.01);         //                 //end Cabine
        glVertex2f( passoX + -0.020, passoY + 0.075);                         //begin fuselagem
        glVertex2f( passoX + -0.020, passoY + -0.01);      //
        glVertex2f( passoX + 0.020, passoY + -0.01);
        glVertex2f( passoX + 0.020, passoY + 0.075);       //
        glVertex2f( passoX + -0.012, passoY + -0.075);
        glVertex2f( passoX + -0.008, passoY + -0.125);     //
        glVertex2f( passoX + 0.012, passoY + -0.075);
        glVertex2f( passoX + 0.008, passoY + -0.125);      //
        glVertex2f( passoX + 0.053, passoY + -0.135);
        glVertex2f( passoX + 0.0081, passoY + -0.11);      //
        glVertex2f( passoX + -0.053, passoY + -0.135);
        glVertex2f( passoX + -0.0081, passoY + -0.11);     //
        glVertex2f( passoX + 0.09, passoY + -0.002);
        glVertex2f( passoX + 0.020, passoY + 0.008);       //
        glVertex2f( passoX + -0.09, passoY + -0.002);
        glVertex2f( passoX + -0.020, passoY + 0.008);      //
    glEnd();
    glutPostRedisplay();
}

void Transformacoes(){
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
        figura();
    glutSwapBuffers();
    glFlush();
}

int main(int argc, char *argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    sw = glutGet(GLUT_SCREEN_WIDTH);
    sh = glutGet(GLUT_SCREEN_HEIGHT);
    winPosX = 0; winPosY = 0;
    glutInitWindowPosition(winPosX, winPosY);
    glutInitWindowSize(sw, sh);
    glutCreateWindow("CG Fernando Ex2-Transformacoes");
        glutDisplayFunc(Transformacoes);
        glutTimerFunc(0,Timer,0);
//        glutKeyboardFunc(Keyboard);
//        glutSpecialFunc(SpecialKeys);
//        glutPassiveMotionFunc(MovimentaMouse);
    glutMainLoop();
}
