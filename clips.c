#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>

void init(void);
void display(void);
void reshape(int w, int h);

int main(int argc, char** argv){
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(800, 800);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("Hello");
  init();
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutMainLoop();
  return 0;
}
void init(void)
{
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}
void reshape(int w, int h)
{
  glViewport(0,0,(GLsizei) w, (GLsizei) h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(60.0, (GLfloat) w/ (GLfloat) h, 1,10);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(1.0,1.0,1.0,
	    0.7,0.7,0.0,
	    0.0,1.0,0.0);
}

void display(void)
{
 glClear(GL_COLOR_BUFFER_BIT);
 //glColor3f(1.0, 0, 0);
 glTranslatef(0.5,0.5,0);
 glutWireSphere(0.05,10,10);

 //glColor3f(0, 1.0, 0);
 glTranslatef(0.1,0.1,0);
 glutWireSphere(0.05,10,10);

 glColor3f(0, 0, 1);
 glTranslatef(0.1,0.2,0);
 glutWireSphere(0.05,100,100);

 glColor3f(1.0, 0, 0); 
 glTranslatef(0.2,0.4,5);
 glutWireSphere(0.05,100,100);

 glColor3f(1.0, 0, 1.0);
 glTranslatef(-0.3,0.3,0);
 glutWireSphere(0.05,100,100);

 glColor3f(0, 1.0, 0);
 glTranslatef(0.1,0.1,-1);
 glutWireSphere(0.05,100,100);

 glFlush();
}
