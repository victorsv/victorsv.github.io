#include <GL/glut.h>
#include <stdlib.h>

typedef struct block {
float r, g, b;
float r1, g1, b1;

} Bloco;
Bloco sqr1, sqr2, sqr3, sqr4;
int cswitch = 0;

GLfloat r,g,b;

void init(void);
void display(void);
void keyboard(unsigned char key, int x, int y);
void mouse(int button, int state, int x, int y);

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize (256, 256); 
	glutInitWindowPosition (100, 100); 
	glutCreateWindow ("Preenchendo regiões");
	init();
	glutDisplayFunc(display); 
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glutMainLoop();
	return 0;
}

void init(void){
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glOrtho (0, 256, 0, 256, -1 ,1);
	sqr1.r = 1;
	sqr1.g = 1;
	sqr1.b = 0;
	sqr1.r1 = 0;
	sqr1.g1 = 0;
	sqr1.b1 = 0;

	sqr2.r = 1;
	sqr2.g = 1;
	sqr2.b = 0;
	sqr2.r1 = 0;
	sqr2.g1 = 0;
	sqr2.b1 = 0;

	sqr3.r = 1;
	sqr3.g = 1;
	sqr3.b = 0;
	sqr3.r1 = 0;
	sqr3.g1 = 0;
	sqr3.b1 = 0;

	sqr4.r = 1;
	sqr4.g = 1;
	sqr4.b = 0;
	sqr4.r1 = 0;
	sqr4.g1 = 0;
	sqr4.b1 = 0;


}

void display(void){
	int i;
	glClear(GL_COLOR_BUFFER_BIT);
	glDisable(GL_POLYGON_STIPPLE);

	glPolygonMode(GL_BACK, GL_FILL);
	glColor3f(sqr1.r, sqr1.g, sqr1.b);
	glBegin(GL_POLYGON);
	glVertex2i(30,226);  glVertex2i(113,226);
	glVertex2i(113,143); glVertex2i(30,143); 
	glEnd();

	glPolygonMode(GL_BACK, GL_LINE);
	glColor3f(sqr1.r1, sqr1.g1, sqr1.b1);
	glBegin(GL_POLYGON);
	glVertex2i(30,226);  glVertex2i(113,226);
	glVertex2i(113,143); glVertex2i(30,143); 
	glEnd();

	glPolygonMode(GL_BACK, GL_FILL);
	glColor3f(sqr2.r, sqr2.g, sqr2.b);
	glBegin(GL_POLYGON);
	glVertex2i(143,226); glVertex2i(226,226);
	glVertex2i(226,143); glVertex2i(143,143); 
	glEnd();

	glPolygonMode(GL_BACK, GL_LINE);
	glColor3f(sqr2.r1, sqr2.g1, sqr2.b1);
	glBegin(GL_POLYGON);
	glVertex2i(143,226); glVertex2i(226,226);
	glVertex2i(226,143); glVertex2i(143,143); 
	glEnd();

	glPolygonMode(GL_BACK, GL_FILL);
	glColor3f(sqr3.r, sqr3.g, sqr3.b);
	glBegin(GL_POLYGON);
	glVertex2i(30,113);	glVertex2i(113,113);
	glVertex2i(113,30);	glVertex2i(30,30); 
	glEnd();

	glPolygonMode(GL_BACK, GL_LINE);
	glColor3f(sqr3.r1, sqr3.g1, sqr3.b1);
	glBegin(GL_POLYGON);
	glVertex2i(30,113);	glVertex2i(113,113);
	glVertex2i(113,30);	glVertex2i(30,30); 
	glEnd();

	glPolygonMode(GL_BACK, GL_FILL);
	glColor3f(sqr4.r, sqr4.g, sqr4.b);
	glBegin(GL_POLYGON);
	glVertex2i(143,113); glVertex2i(226,113);
	glVertex2i(226,30); glVertex2i(143,30); 
	glEnd();

	glPolygonMode(GL_BACK, GL_LINE);
	glColor3f(sqr4.r1, sqr4.g1, sqr4.b1);
	glBegin(GL_POLYGON);
	glVertex2i(143,113); glVertex2i(226,113);
	glVertex2i(226,30); glVertex2i(143,30); 
	glEnd();
	glFlush();
	glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y){
	switch (key) {
	case 98:
	cswitch = 1;
	break;
	case 102:
	cswitch = 0;
	break;
	case 27:
	exit(0);
	break;
	}
}

void mouse(int button, int state, int x, int y){
	switch (button) {
	case GLUT_LEFT_BUTTON:
		if (cswitch == 0){
			if ((x > 30 && x < 113 ) && (y > 143 && y < 226)) {
				if (state == GLUT_DOWN) {
					sqr3.r=(GLfloat)rand()/(RAND_MAX+1.0);
					sqr3.g=(GLfloat)rand()/(RAND_MAX+1.0);
					sqr3.b=(GLfloat)rand()/(RAND_MAX+1.0);
					glutPostRedisplay();
				}
			}
			else if ((x > 143 && x < 226 ) && (y > 143 && y < 226)) {
				if (state == GLUT_DOWN) {
					sqr4.r=(GLfloat)rand()/(RAND_MAX+1.0);
					sqr4.g=(GLfloat)rand()/(RAND_MAX+1.0);
					sqr4.b=(GLfloat)rand()/(RAND_MAX+1.0);
					glutPostRedisplay();
				}
			}
			else if ((x > 30 && x < 113 ) && (y > 30 && y < 113)) {
				if (state == GLUT_DOWN) {
					sqr1.r=(GLfloat)rand()/(RAND_MAX+1.0);
					sqr1.g=(GLfloat)rand()/(RAND_MAX+1.0);
					sqr1.b=(GLfloat)rand()/(RAND_MAX+1.0);
					glutPostRedisplay();
				}
			}
			else if ((x > 143 && x < 226 ) && (y > 30 && y < 113)) {
				if (state == GLUT_DOWN) {
					sqr2.r=(GLfloat)rand()/(RAND_MAX+1.0);
					sqr2.g=(GLfloat)rand()/(RAND_MAX+1.0);
					sqr2.b=(GLfloat)rand()/(RAND_MAX+1.0);
					glutPostRedisplay();
				}
			}
		}
		else{
			if ((x > 30 && x < 113 ) && (y > 143 && y < 226)) {
				if (state == GLUT_DOWN) {
					sqr3.r1=(GLfloat)rand()/(RAND_MAX+1.0);
					sqr3.g1=(GLfloat)rand()/(RAND_MAX+1.0);
					sqr3.b1=(GLfloat)rand()/(RAND_MAX+1.0);
					glutPostRedisplay();
				}
			}
			else if ((x > 143 && x < 226 ) && (y > 143 && y < 226)) {
				if (state == GLUT_DOWN) {
					sqr4.r1=(GLfloat)rand()/(RAND_MAX+1.0);
					sqr4.g1=(GLfloat)rand()/(RAND_MAX+1.0);
					sqr4.b1=(GLfloat)rand()/(RAND_MAX+1.0);
					glutPostRedisplay();
				}
			}
			else if ((x > 30 && x < 113 ) && (y > 30 && y < 113)) {
				if (state == GLUT_DOWN) {
					sqr1.r1=(GLfloat)rand()/(RAND_MAX+1.0);
					sqr1.g1=(GLfloat)rand()/(RAND_MAX+1.0);
					sqr1.b1=(GLfloat)rand()/(RAND_MAX+1.0);
					glutPostRedisplay();
				}
			}
			else if ((x > 143 && x < 226 ) && (y > 30 && y < 113)) {
				if (state == GLUT_DOWN) {
					sqr2.r1=(GLfloat)rand()/(RAND_MAX+1.0);
					sqr2.g1=(GLfloat)rand()/(RAND_MAX+1.0);
					sqr2.b1=(GLfloat)rand()/(RAND_MAX+1.0);
					glutPostRedisplay();
				}
			}
		}
		break;
	}
}
