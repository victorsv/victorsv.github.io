/* programa teste-make.c */

#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

void display(void);
void timer(int);
void keyboard(unsigned char key, int x, int y);

/* cores do quadrado */
GLfloat r=1.0, g=0.5, b=0.0;

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (256, 256); 
	glutInitWindowPosition (100, 100); 
	glutCreateWindow (argv[0]);
	// inicia um temporizador. após 33ms ativa a funcao timer
	glutTimerFunc(33, timer, 1);
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glShadeModel (GL_FLAT);
	glOrtho (0, 1, 0, 1, -1 ,1);
	glutDisplayFunc(display);
	glutMainLoop(); 
	return 0;
}

void timer(int value){
	//r=r+0.01;
	//g=g+0.01;
	//b=b+0.01;
	//if(r>1) r=0;
	//if(g>1) g=0;
	//if(b>1) b=0;
	glutPostRedisplay();
	glutTimerFunc(33, timer, 1);
}

void display(void){
	int i;
	float r1, g1, b1;
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f (0.1, 0.2, 0.5);
	glBegin(GL_POLYGON);
	glVertex2f(0.20,0.20);
	glVertex2f(0.33,0.20);
	glVertex2f(0.33,0.33);
	glVertex2f(0.20,0.33);
	glEnd();

	glColor3f (0.5, 0.3, 0.7);
	glBegin(GL_POLYGON);
	glVertex2f(0.40,0.40);
	glVertex2f(0.53,0.40);
	glVertex2f(0.53,0.53);
	glVertex2f(0.40,0.53);
	glEnd();

	glColor3f (0.7, 0.5, 0.2);
	glBegin(GL_POLYGON);
	glVertex2f(0.60,0.60);
	glVertex2f(0.73,0.60);
	glVertex2f(0.73,0.73);
	glVertex2f(0.60,0.73);
	glEnd();

	glColor3f (0.1, 0.8, 0.5);
	glBegin(GL_POLYGON);
	glVertex2f(0.80,0.80);
	glVertex2f(0.93,0.80);
	glVertex2f(0.93,0.93);
	glVertex2f(0.80,0.93);
	glEnd();


	glFlush();
}
