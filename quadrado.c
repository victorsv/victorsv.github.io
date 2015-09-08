#include <GL/glut.h>
#include <stdlib.h>

void init(void);
void display(void);
void keyboard(unsigned char key, int x, int y);
float r1 = 1;
float g1 = 0;
float b1 = 0;

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (256, 256); 
	glutInitWindowPosition (100, 100); 
	glutCreateWindow ("Desenhando uma linha");
	init();
	glutDisplayFunc(display); 
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}

void init(void){
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glOrtho (0, 256, 0, 256, -1 ,1);
}

void display(void){
	int i;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f (r1, g1, b1);
	glBegin(GL_LINES);
	glVertex2i(30,30); glVertex2i(30,226);

	glColor3f (r1, g1, b1);
	glBegin(GL_LINES);
	glVertex2i(30,226); glVertex2i(226,226);

	glColor3f (r1, g1, b1);
	glBegin(GL_LINES);
	glVertex2i(226,226); glVertex2i(226,30);

	glColor3f (r1, g1, b1);
	glBegin(GL_LINES);
	glVertex2i(226,30); glVertex2i(30,30);
	glEnd();
	glFlush();
}

void keyboard(unsigned char key, int x, int y){
	switch (key) {
	case 97:
		r1 = 0;
		b1 = 1;
	break;
	case 118:
		r1 = 1;
		b1 = 0;
	break;
	case 27:
	exit(0);
	break;
	}
}
