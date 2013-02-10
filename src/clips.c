#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void init(void);
void display(void);
void reshape(int w, int h);
void drawAxis(void);
void drawBalloon(float size);
void drawBalloonBottom(void);
void drawBalloonString(float x, float y, float z);
void drawBox(void);
void drawTableFromOrigin(void);
void generateLists(void);
void drawImage(void);
void processSpecialKeys(int key, int xx, int yy);
void processNormalKeys(unsigned char key, int x, int y);



GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat light_ambient[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat light_pos[] = { 0.0, 100.0, 0.0 };
GLuint axis, table, box, string, balloon, totalImage;

// angle of rotation for the camera direction
float angle=0.0;
// actual vector representing the camera's direction
float lx=0.0,lz=-1.0;
// XZ position of the camera
float x=0.0,z=5.0;

int main(int argc, char** argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Ballon Image");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
    glutKeyboardFunc(processNormalKeys);
    glutSpecialFunc(processSpecialKeys);
    glEnable(GL_DEPTH_TEST);

    
	glutMainLoop();
	return 0;
}

void init(void){
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
}

void reshape(int w, int h){
	glViewport(0,0,(GLsizei) w, (GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (GLfloat) w/ (GLfloat) h, 1,10);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//gluLookAt(5,5,5,0,0,0,0,1.0,0);
       
}

void display(void){
    
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
    glLoadIdentity();
    
    gluLookAt(	x, 1.0, z,
              x+lx, 1.0,  z+lz,
              0.0, 1.0,  0.0);
    

	generateLists();
	glCallList(axis);
    
	totalImage = glGenLists (1);
	glNewList(totalImage, GL_COMPILE);
	drawImage();
	glEndList();
    
	glCallList(totalImage);
    
	glTranslatef(2,0,0);
    
	glCallList(totalImage);
    
	glTranslatef(-2,0,2);
    
	glCallList(totalImage);
    
	glTranslatef(2,0,0);
    
	glCallList(totalImage);
    
	glFlush();
}

void drawAxis(void){
	//Axis
	glBegin(GL_LINES);
	glColor3f(0, 1.0, 0);
	glVertex3f(0,0,0);
	glVertex3f(5,0,0);
    
	glColor3f(1.0, 0, 1.0);
	glVertex3f(0,0,0);
	glVertex3f(0,5,0);
    
	glColor3f(0, 0, 1.0);
	glVertex3f(0,0,0);
	glVertex3f(0,0,5);
	glEnd();
}

void drawBalloon(float size){
	//First Balloon
	glutWireSphere(size,10,10);
}

void drawBalloonString(float x, float y, float z){
	//First Balloon String
	glBegin(GL_LINES);
	glVertex3f(0,0,0);
	glVertex3f(-x,-1-y,-z);
	glEnd();
}

void drawBalloonBottom(void){
	//Draw the bottom of the balloon
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(0,0,0);
	glVertex3f(-0.015,-0.03,0);
	glVertex3f(0.015,-0.03,0);
	glVertex3f(0.015,-0.03,-0.03);
	glVertex3f(-0.015,-0.03,-0.03);
	glVertex3f(-0.015,-0.03,0);
	glEnd();
}
void drawImage(){
	glCallList(table);
    
	glTranslatef(0,0.1,0);
	glColor3f(1.0,0,0);
	glCallList(box);

	glTranslatef(0,1.0,0);
	glColor3f(1.0,0,0);
	drawBalloonString(0,0,0);
	glCallList(balloon);
    
	glTranslatef(0.2,0,-0.1);
	glColor3f(0,1.0,0);
	drawBalloonString(0.2,0,-0.1);
	glCallList(balloon);
    
	glTranslatef(-0.5,0,0.1);
	glColor3f(1.0,1.0,0);
	drawBalloonString(-0.3,0,0);
	glCallList(balloon);
    
	glTranslatef(0.2,-0.2,0.2);
	glColor3f(0,0,1.0);
	drawBalloonString(-0.1,-0.2,0.2);
	glCallList(balloon);
    
	glTranslatef(0,0,0.2);
	glColor3f(1.0,0,0);
	drawBalloonString(-0.1,-0.1,0.5);
	glCallList(balloon);
    
	glTranslatef(0.1,0.2,-0.6);
	glColor3f(0,1.0,1.0);
	drawBalloonString(0,0,-.2);
	glCallList(balloon);
}

void drawBox(void){
	glBegin(GL_QUAD_STRIP);
	//Side 1
	glVertex3f(-0.05,0,0.05);
	glVertex3f(-0.05,-0.1,0.05);
	glVertex3f(0.05,0,0.05);
	glVertex3f(0.05,-0.1,0.05);
    
	//Side 2
	glVertex3f(0.05,0,-0.05);
	glVertex3f(0.05,-0.1,-0.05);
    
	//Side 3
	glVertex3f(-0.05,0,-0.05);
	glVertex3f(-0.05,-0.1,-0.05);
    
	//Side 4
	glVertex3f(-0.05,0,0.05);
	glVertex3f(-0.05,-0.1,0.05);
	glEnd();
    
	glBegin(GL_QUADS);
	glVertex3f(-0.05,0,-0.05);
	glVertex3f(-0.05,0,0.05);
	glVertex3f(0.05,0,0.05);
	glVertex3f(0.05,0,-0.05);
	glEnd();
    
	glColor3f(1.0,1.0,0);
	glBegin(GL_LINE_LOOP);
	glVertex3f(-0.05,0,-0.05);
	glVertex3f(-0.05,0,0.05);
	glVertex3f(0.05,0,0.05);
	glVertex3f(0.05,0,-0.05);
	glEnd();
    
	glBegin(GL_LINE_LOOP);
	glVertex3f(-0.05,0,0.05);
	glVertex3f(-0.05,-0.1,0.05);
	glVertex3f(0.05,-0.1,0.05);
	glVertex3f(0.05,0,0.05);
	glEnd();
    
	glBegin(GL_LINE_LOOP);
	glVertex3f(0.05,-0.1,0.05);
	glVertex3f(0.05,-0.1,-0.05);
	glVertex3f(0.05,0,-0.05);
	glVertex3f(0.05,0,0.05);
	glEnd();
    
}

void drawTableFromOrigin(void){
	glColor3f(1.0,0.5,0);
	glTranslatef(0,-1.1,0);
    
	//Draw Legs of Table
	glBegin(GL_QUAD_STRIP);
	glVertex3f(-0.5,0,-0.5);
	glVertex3f(-0.5,-0.5,-0.5);
	glVertex3f(-0.5,0,-0.4);
	glVertex3f(-0.5,-0.5,-0.4);
	glVertex3f(-0.4,0,-0.4);
	glVertex3f(-0.4,-0.5,-0.4);
	glVertex3f(-0.4,0,-0.5);
	glVertex3f(-0.4,-0.5,-0.5);
	glVertex3f(-0.5,0,-0.5);
	glVertex3f(-0.5,-0.5,-0.5);
	glEnd();
    
	glBegin(GL_QUAD_STRIP);
	glVertex3f(0.5,0,0.5);
	glVertex3f(0.5,-0.5,0.5);
	glVertex3f(0.5,0,0.4);
	glVertex3f(0.5,-0.5,0.4);
	glVertex3f(0.4,0,0.4);
	glVertex3f(0.4,-0.5,0.4);
	glVertex3f(0.4,0,0.5);
	glVertex3f(0.4,-0.5,0.5);
	glVertex3f(0.5,0,0.5);
	glVertex3f(0.5,-0.5,0.5);
	glEnd();
    
	glBegin(GL_QUAD_STRIP);
	glVertex3f(0.5,0,-0.5);
	glVertex3f(0.5,-0.5,-0.5);
	glVertex3f(0.5,0,-0.4);
	glVertex3f(0.5,-0.5,-0.4);
	glVertex3f(0.4,0,-0.4);
	glVertex3f(0.4,-0.5,-0.4);
	glVertex3f(0.4,0,-0.5);
	glVertex3f(0.4,-0.5,-0.5);
	glVertex3f(0.5,0,-0.5);
	glVertex3f(0.5,-0.5,-0.5);
	glEnd();
    
	glBegin(GL_QUAD_STRIP);
	glVertex3f(-0.5,0,0.5);
	glVertex3f(-0.5,-0.5,0.5);
	glVertex3f(-0.5,0,0.4);
	glVertex3f(-0.5,-0.5,0.4);
	glVertex3f(-0.4,0,0.4);
	glVertex3f(-0.4,-0.5,0.4);
	glVertex3f(-0.4,0,0.5);
	glVertex3f(-0.4,-0.5,0.5);
	glVertex3f(-0.5,0,0.5);
	glVertex3f(-0.5,-0.5,0.5);
	glEnd();
    
	//Draw Top of Table
	glBegin(GL_QUADS);
	glVertex3f(-0.5,0,-0.5);
	glVertex3f(-0.5,0,0.5);
	glVertex3f(0.5,0,0.5);
	glVertex3f(0.5,0,-0.5);
	glEnd();
    
	//Draw Sideof Table
	glColor3f(1.0,1.0,0);
	glBegin(GL_QUAD_STRIP);
	glVertex3f(-0.5,0,0.5);
	glVertex3f(-0.5,-0.1,0.5);
	glVertex3f(0.5,0,0.5);
	glVertex3f(0.5,-0.1,0.5);
	glVertex3f(0.5,0,-0.5);
	glVertex3f(0.5,-0.1,-0.5);
	glVertex3f(-0.5,0,-0.5);
	glVertex3f(-0.5,-0.1,-0.5);
	glVertex3f(-0.5,0,0.5);
	glVertex3f(-0.5,-0.1,0.5);
	glEnd();
}

void generateLists(void){
    
	axis = glGenLists (1);
	glNewList(axis, GL_COMPILE);
	drawAxis();
	glEndList();
    
	table = glGenLists (1);
	glNewList(table, GL_COMPILE);
	drawTableFromOrigin();
	glEndList();
    
	box = glGenLists (1);
	glNewList(box, GL_COMPILE);
	drawBox(); 
	glEndList();
    
	balloon = glGenLists (1);
	glNewList(balloon, GL_COMPILE); 
	drawBalloon(0.1); 
	glEndList();
	glEndList();
    
}
void processSpecialKeys(int key, int xx, int yy) {
    
	float fraction = 0.1;
    
	switch (key) {
		case GLUT_KEY_LEFT :
			angle -= 0.01;
			lx = sin(angle);
			lz = -cos(angle);
			break;
		case GLUT_KEY_RIGHT :
			angle += 0.01;
			lx = sin(angle);
			lz = -cos(angle);
			break;
		case GLUT_KEY_UP :
			x += lx * fraction;
			z += lz * fraction;
			break;
		case GLUT_KEY_DOWN :
			x -= lx * fraction;
			z -= lz * fraction;
			break;
	}
    
    glutPostRedisplay();
    
}
void processNormalKeys(unsigned char key, int x, int y) {
    
	if (key == 27)
		exit(0);
}






