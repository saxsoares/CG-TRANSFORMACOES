#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include "Transformacoes.h"

void MovimentaMouse(int, int);
void Keyboard (unsigned char , int , int );
void SpecialKeys (int , int , int );
void Timer(int );
void Transformacoes();
void CalculoAng();
void Figura();
GLfloat px, py;
GLint escala = 1;
GLfloat proporcao;
GLint veloc = 1;
GLfloat passoX = 0, passoY = 0;
GLfloat pontaX = 0.0, pontaY = 0.105, auxpontaX, auxpontaY ;
GLdouble origemX = 0, origemY = 0, auxorigemX, auxorigemY;
GLfloat teta = 0.0, tetaAlvo = 0.0 , beta, alfa;
GLdouble mouseVector[2] = {0, 1}, naveVector[2];
GLdouble aux1, aux2;

GLfloat preto[]={0,0,0}, branco[]={1,1,1}, verde[]={0,1,0}, vermelho[]={1,0,0}, azul[]={0,0,1}, amarelo[]={1,1,0},
        furchsia[]={1,0,1}, rosa[]={1,0.75,0.8}, rosaBri[]={1,0,0.5}, abobora[]={0.99,0.06,0.75}, ciano[]={0,1,1},
        verdeEsc[]={0, 0.39, 0}, azulEsc[]={0,0,0.55}, marinho[]={0.07,0.04,0.56}, fuligem[]={0.24,0.17,0.12},
        roxo[]={0.5,0,0.5},azulCeu[]={0.53,0.81,0.98},verdeGrama[]={0.49,0.99,0},cinzaFosco[]={0.41,0.41,0.41},
        jambo[]={1,0.27,0},laranja[]={1,0.65,0},marrom[]={0.65,0.16,0.16},cinza[]={0.5,0.5,0.5}, cinzaEsc[]={0.66,0.66,0.66};


void MovimentaMouse(int x, int y){
    y = w_height - y;
    aux2 = (double)(((double)y/(double)w_height)*2.0 - 1.0);
    aux1 = (double)(((double)x/(double)w_width)*2.0 -1.0);

    mouseVector[0] = aux1;// - auxorigemX;
    mouseVector[1] = aux2;// - auxorigemY;

    printf("M(%f, %f) -- A(%f, %f)\n", mouseVector[0], mouseVector[1], naveVector[0], naveVector[1]);
    printf("tetaAlvo = %f\n", tetaAlvo);
    printf("teta = %f\n", teta);
}

void CalculoAng(){
    tetaAlvo = atan(mouseVector[0]/mouseVector[1]);

    if((mouseVector[0] >= 0) && (mouseVector[1] >= 0)){            //2° Quadrante
        tetaAlvo = 2*PI -tetaAlvo ;
        passoY = tan(tetaAlvo * passoX);
    }
    else if((mouseVector[0] <= 0) && (mouseVector[1]  >= 0)){      //3° Quadrante
        tetaAlvo = -tetaAlvo ;
         passoY = tan(tetaAlvo * passoX);
    }
    else if((mouseVector[0] <= 0) && (mouseVector[1]  <= 0)){      //4° Quadrante
        tetaAlvo = -tetaAlvo + PI;
         passoY = tan(tetaAlvo * passoX);
    }
    else if((mouseVector[0] >= 0) && (mouseVector[1]  <= 0)){      //4° Quadrante
        tetaAlvo = -tetaAlvo + PI ;
         passoY = tan(tetaAlvo * passoX);
    }
    if(teta != tetaAlvo){
        glutTimerFunc(veloc,Timer,0);
    }
    else
        ;
}
void MouseInt(int botao, int estado, int x, int y){

    switch(botao){
        case GLUT_LEFT_BUTTON:
            if(estado == GLUT_DOWN){
                y = w_height - y;
                px =((x/w_width)*2 -1); py =((y/w_height)*2 - 1);
            }

            break;
    default:
       break;
    }
    glutPostRedisplay();
}
void Keyboard (unsigned char key, int x, int y){
}

void SpecialKeys (int key, int x, int y){

}

void Timer(int extra){

    if(teta < tetaAlvo && (sqrt(pow(tetaAlvo - teta, 2))) <= 3.14 ){
         teta += 0.005;
         if(teta > 6.28) teta = 0;
    }
    if(teta < tetaAlvo && (sqrt(pow(tetaAlvo - teta, 2))) >= 3.14 ){
         teta -= 0.005;
         if(teta < 0) teta = 6.28;
    }
    if(teta > tetaAlvo && (sqrt(pow(tetaAlvo - teta, 2)))  >= 3.14 ){
         teta += 0.005;
         if(teta > 6.28) teta = 0;
    }
    if(teta > tetaAlvo && (sqrt(pow(tetaAlvo - teta, 2)))  <= 3.14 ){
        teta -= 0.005;
        if(teta < 0) teta = 6.28;
    }
    glutPostRedisplay();
    //glutTimerFunc(veloc,Timer,0);
}

void Figura(){
    auxorigemX = (passoX + (origemX * cos(teta) - origemY * sin(teta)));
    auxorigemY = (passoY + (origemY * cos(teta) + origemX * sin(teta)));
    auxpontaX =   passoX + (pontaX * cos(teta) - pontaY * sin(teta));
    auxpontaY =  (passoY + (cos(teta) * pontaY + pontaX * sin(teta))) * proporcao;


    glCullFace(GL_BACK);
    glEnable(GL_CULL_FACE);
    glShadeModel(GL_SMOOTH);
    glBegin(GL_POLYGON);
        glColor3fv(cinzaEsc);
        glVertex2f(passoX+(pontaX*cos(teta) - pontaY*sin(teta)),
            (passoY +(cos(teta)*pontaY + pontaX*sin(teta)))*proporcao);    //begin CABINE
        glColor3fv(cinzaFosco);
        glVertex2f(passoX+(-0.005*cos(teta) - 0.09*sin(teta)),
            (passoY +(cos(teta)*0.09+(-0.005)*sin(teta)))*proporcao);
        glVertex2f(passoX+(-0.011*cos(teta) - 0.085*sin(teta)),
            (passoY +(cos(teta)*0.085+(-0.011)*sin(teta)))*proporcao);
        glVertex2f(passoX+(-0.012*cos(teta) - 0.08*sin(teta)),
            (passoY +(cos(teta)*0.08+(-0.012)*sin(teta)))*proporcao);
        glVertex2f(passoX+(-0.014*cos(teta) - 0.03*sin(teta)),
            (passoY +(cos(teta)*0.03+(-0.014)*sin(teta)))*proporcao);
        glColor3fv(cinzaEsc);
        glVertex2f(passoX+(0.0*cos(teta) - (-0.005)*sin(teta)),
            (passoY +(cos(teta)*-0.005+(0)*sin(teta)))*proporcao);
        glColor3fv(cinzaFosco);
        glVertex2f(passoX+(0.014*cos(teta) - 0.03*sin(teta)),
            (passoY +(cos(teta)*0.03+0.014*sin(teta)))*proporcao);
        glVertex2f(passoX+(0.012*cos(teta) - 0.08*sin(teta)),
            (passoY +(cos(teta)*0.08+0.012*sin(teta)))*proporcao);
        glVertex2f(passoX+(0.011*cos(teta) - 0.085*sin(teta)),
            (passoY +(cos(teta)*0.085+0.011*sin(teta)))*proporcao);
        glVertex2f(passoX+(0.005*cos(teta) - 0.09*sin(teta)),
            (passoY +(cos(teta)*0.09+0.005*sin(teta)))*proporcao);                        //end Cabine
    glEnd();
        //
    glBegin(GL_POLYGON);                                              //begin CABINE
        glColor3fv(branco); glVertex2f(passoX+(0.0*cos(teta) - 0.085*sin(teta)),
            (passoY +(cos(teta)*0.085+0*sin(teta)))*proporcao);
        glColor3fv(preto);  glVertex2f(passoX+(-0.008*cos(teta) - 0.075*sin(teta)),
            (passoY +(cos(teta)*0.075+(-0.008)*sin(teta)))*proporcao);
        glColor3fv(preto);  glVertex2f(passoX+(-0.008*cos(teta) - 0.06*sin(teta)),
            (passoY +(cos(teta)*0.06+(-0.008)*sin(teta)))*proporcao);
        glColor3fv(branco); glVertex2f(passoX+(0.0*cos(teta) - 0.04*sin(teta)),
            (passoY +(cos(teta)*0.04+(0)*sin(teta)))*proporcao);
        glColor3fv(preto);  glVertex2f(passoX+(0.008*cos(teta) - 0.06*sin(teta)),
            (passoY +(cos(teta)*0.06+0.008*sin(teta)))*proporcao);
        glColor3fv(preto);  glVertex2f(passoX+(0.008*cos(teta) - 0.075*sin(teta)),
            (passoY +(cos(teta)*0.075+0.008*sin(teta)))*proporcao);     //end Cabine
    glEnd();
    glBegin(GL_POLYGON);                                                    //begin fuselagem
        glColor3fv(cinzaFosco);
        glVertex2f(passoX+(0.0*cos(teta) - (-0.005)*sin(teta)),
            (passoY +(cos(teta)* (-0.005)+0*sin(teta)))*proporcao);
        glColor3fv(cinza);
        glVertex2f(passoX+(-0.014*cos(teta) - 0.05*sin(teta)),
            (passoY +(cos(teta)*0.05+(-0.014)*sin(teta)))*proporcao);
        glVertex2f(passoX+(-0.020*cos(teta) - 0.0375*sin(teta)),
            (passoY +(cos(teta)*0.0375+(-0.02)*sin(teta)))*proporcao);
        glVertex2f(passoX+(-0.020*cos(teta) - (0.0)*sin(teta)),
            (passoY +(cos(teta)*0.0+(-0.02)*sin(teta)))*proporcao);
        glVertex2f(passoX+(-0.012*cos(teta) - (-0.0375)*sin(teta)),
            (passoY +(cos(teta)*-0.0375+(-0.012)*sin(teta)))*proporcao);
        glColor3fv(cinzaFosco);
        glVertex2f(passoX+(-0.007*cos(teta) - (-0.0685)*sin(teta)),
            (passoY +(cos(teta)*-0.0685+(-0.007)*sin(teta)))*proporcao);
        glVertex2f(passoX+(0.007*cos(teta) - (-0.0685)*sin(teta)),
            (passoY +(cos(teta)*-0.0685+(0.007)*sin(teta)))*proporcao);
        glColor3fv(cinza);
        glVertex2f(passoX+(0.012*cos(teta) - (-0.0375)*sin(teta)),
            (passoY +(cos(teta)*-0.0375+(0.012)*sin(teta)))*proporcao);
        glVertex2f(passoX+(0.020*cos(teta) - 0*sin(teta)),
            (passoY +(cos(teta)*0.0+0.02*sin(teta)))*proporcao);
        glVertex2f(passoX+(0.020*cos(teta) - 0.0375*sin(teta)),
            (passoY +(cos(teta)*0.0375+0.02*sin(teta)))*proporcao);
        glVertex2f(passoX+(0.014*cos(teta) - 0.05*sin(teta)),
            (passoY +(cos(teta)*0.05+0.014*sin(teta)))*proporcao);                          //end fuselagem
    glEnd();
    glBegin(GL_POLYGON);                                    //ASA ESQUERDA
        glVertex2f(passoX+(-0.020*cos(teta) - 0.0325*sin(teta)),
            (passoY +(cos(teta)*0.0325+(-0.02)*sin(teta)))*proporcao);
        glColor3fv(cinzaEsc);
        glVertex2f(passoX+(-0.09*cos(teta) - 0.0075*sin(teta)),
            (passoY +(cos(teta)*0.0075+(-0.09)*sin(teta)))*proporcao);
        glVertex2f(passoX+(-0.09*cos(teta) - (-0.005)*sin(teta)),
            (passoY +(cos(teta)*-0.005+(-0.09)*sin(teta)))*proporcao);
        glColor3fv(cinza);
        glVertex2f(passoX+(-0.020*cos(teta) - 0*sin(teta)),
            (passoY +(cos(teta)*0.0+(-0.02)*sin(teta)))*proporcao);
    glEnd();
    glBegin(GL_POLYGON);                                    //ASA DIREITA
        glColor3fv(cinza);
        glVertex2f(passoX+(0.020*cos(teta) - 0*sin(teta)),
            (passoY +(cos(teta)*0.0+0.02*sin(teta)))*proporcao);
        glVertex2f(passoX+(0.09*cos(teta) - (-0.005)*sin(teta)),
            (passoY +(cos(teta)*-0.005+0.09*sin(teta)))*proporcao);
        glColor3fv(cinzaEsc);
        glVertex2f(passoX+(0.09*cos(teta) - 0.0075*sin(teta)),
            (passoY +(cos(teta)*0.0075+0.09*sin(teta)))*proporcao);
        glVertex2f(passoX+(0.020*cos(teta) - 0.0325*sin(teta)),
            (passoY +(cos(teta)*0.0325+0.02*sin(teta)))*proporcao);
    glEnd();
    glBegin(GL_POLYGON);                                    //deriva ESQUERDA
        glVertex2f(passoX+(-0.012*cos(teta) - (-0.0375)*sin(teta)),
            (passoY +(cos(teta)*-0.0375+(-0.012)*sin(teta)))*proporcao);
        glColor3fv(cinzaEsc);
        glVertex2f(passoX+(-0.053*cos(teta) - (-0.065)*sin(teta)),
            (passoY +(cos(teta)*-0.065+(-0.053)*sin(teta)))*proporcao);
        glVertex2f(passoX+(-0.053*cos(teta) - (-0.0725)*sin(teta)),
            (passoY +(cos(teta)*-0.0725+(-0.053)*sin(teta)))*proporcao);
        glColor3fv(cinza);
        glVertex2f(passoX+(-0.008*cos(teta) - (-0.06)*sin(teta)),
            (passoY +(cos(teta)*-0.06+(-0.008)*sin(teta)))*proporcao);
    glEnd();
    glBegin(GL_POLYGON);                                    //deriva DIREITA
        glColor3fv(cinza);
        glVertex2f(passoX+(0.008*cos(teta) - (-0.06)*sin(teta)),
            (passoY +(cos(teta)*-0.06+0.008*sin(teta)))*proporcao);
        glVertex2f(passoX+(0.053*cos(teta) - (-0.0725)*sin(teta)),
            (passoY +(cos(teta)*-0.0725+0.053*sin(teta)))*proporcao);
        glColor3fv(cinzaEsc);
        glVertex2f(passoX+(0.053*cos(teta) - (-0.065)*sin(teta)),
            (passoY +(cos(teta)*-0.065+(0.053)*sin(teta)))*proporcao);
        glVertex2f(passoX+(0.012*cos(teta) - (-0.0375)*sin(teta)),
            (passoY +(cos(teta)*-0.0375+(0.012)*sin(teta)))*proporcao);
    glEnd();
    glLineWidth(escala*0.7);
    glBegin(GL_LINES);
        glColor3fv(preto);                                 //begin CABINE
        glVertex2f(passoX+(0.014*cos(teta) - 0.05*sin(teta)),
            (passoY +(cos(teta)*0.05+(0.014)*sin(teta)))*proporcao);
        glVertex2f(passoX+(0.0*cos(teta) - (-0.005)*sin(teta)),
            (passoY +(cos(teta)*-0.005+(0)*sin(teta)))*proporcao);         //
        glVertex2f(passoX+(-0.014*cos(teta) - 0.05*sin(teta)),
            (passoY +(cos(teta)*0.05+(-0.014)*sin(teta)))*proporcao);
        glVertex2f(passoX+(0.0*cos(teta) - (-0.005)*sin(teta)),
            (passoY +(cos(teta)*-0.005+0*sin(teta)))*proporcao);         //                 //end Cabine
        glVertex2f(passoX+(-0.020*cos(teta) - (0.0375)*sin(teta)),
            (passoY +(cos(teta)*0.0375+(-0.02)*sin(teta)))*proporcao);                         //begin fuselagem
        glVertex2f(passoX+(-0.020*cos(teta) - (-0.005)*sin(teta)),
            (passoY +(cos(teta)*-0.005+(-0.02)*sin(teta)))*proporcao);      //
        glVertex2f(passoX+(0.020*cos(teta) - (-0.005)*sin(teta)),
            (passoY +(cos(teta)*-0.005+0.02*sin(teta)))*proporcao);
        glVertex2f(passoX+(0.020*cos(teta) - 0.0375*sin(teta)),
            (passoY +(cos(teta)*0.0375+0.02*sin(teta)))*proporcao);       //
        glVertex2f(passoX+(-0.012*cos(teta) - (-0.0375)*sin(teta)),
            (passoY +(cos(teta)*-0.0375+(-0.012)*sin(teta)))*proporcao);
        glVertex2f(passoX+(-0.008*cos(teta) - (-0.0625)*sin(teta)),
            (passoY +(cos(teta)*-0.0625+(-0.008)*sin(teta)))*proporcao);     //
        glVertex2f(passoX+(0.012*cos(teta) - (-0.0375)*sin(teta)),
            (passoY +(cos(teta)*-0.0375+0.012*sin(teta)))*proporcao);
        glVertex2f(passoX+(0.008*cos(teta) - (-0.0625)*sin(teta)),
            (passoY +(cos(teta)*-0.0625+0.008*sin(teta)))*proporcao);      //
        glVertex2f(passoX+(0.053*cos(teta) - (-0.0675)*sin(teta)),
            (passoY +(cos(teta)*-0.0675+0.053*sin(teta)))*proporcao);
        glVertex2f(passoX+(0.0081*cos(teta) - (-0.055)*sin(teta)),
            (passoY +(cos(teta)*-0.055+0.0081*sin(teta)))*proporcao);      //
        glVertex2f(passoX+(-0.053*cos(teta) - (-0.0675)*sin(teta)),
            (passoY +(cos(teta)*-0.0675+(-0.053)*sin(teta)))*proporcao);
        glVertex2f(passoX+(-0.0081*cos(teta) - (-0.055)*sin(teta)),
            (passoY +(cos(teta)*-0.055+(-0.0081)*sin(teta)))*proporcao);     //
        glVertex2f(passoX+(0.09*cos(teta) - (-0.002)*sin(teta)),
            (passoY +(cos(teta)*-0.002+0.09*sin(teta)))*proporcao);
        glVertex2f(passoX+(0.020*cos(teta) - 0.008*sin(teta)),
            (passoY +(cos(teta)*0.008+0.02*sin(teta)))*proporcao);       //
        glVertex2f(passoX+(-0.09*cos(teta) - (-0.002)*sin(teta)),
            (passoY +(cos(teta)*-0.002+(-0.09)*sin(teta)))*proporcao);
        glVertex2f(passoX+(-0.020*cos(teta) - 0.008*sin(teta)),
            (passoY +(cos(teta)*0.008+(-0.02)*sin(teta)))*proporcao);      //
    glEnd();

    naveVector[0] = auxpontaX - auxorigemX;
    naveVector[1] = auxpontaY - auxorigemY;
    glutPostRedisplay();

}



void Transformacoes(){
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    w_width = glutGet(GLUT_WINDOW_WIDTH);
    w_height = glutGet(GLUT_WINDOW_HEIGHT);
    proporcao = (float)w_width/(float)w_height;
        Figura();
        CalculoAng();
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
    glutCreateWindow("CG Fernando Ex2-Transformacos");
        glutDisplayFunc(Transformacoes);
        glutTimerFunc(0,Timer,0);
//        glutMouseFunc(MouseInt);
//        glutKeyboardFunc(Keyboard);
//        glutSpecialFunc(SpecialKeys);
        glutPassiveMotionFunc(MovimentaMouse);
    glutMainLoop();
}
