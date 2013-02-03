#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>

void init(void);
void display(void);

int main(int argc, char** argv){
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(800, 800);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("Hello");
  init();
  glutDisplayFunc(display);
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
void display(void)
{
 glClear(GL_COLOR_BUFFER_BIT);
 // gluLookAt(0.0, 0.0, 0.0, 0.25, 0.25, 0.0, 1.0, 1.0, 1.0);
 glColor3f(1.0, 0, 0);
 glTranslatef(0.5,0.5,0);
 glutSolidSphere(0.05,100,100);

 glColor3f(0, 1.0, 0);
 glTranslatef(0.1,0.1,0);
 glutSolidSphere(0.05,100,100);

 glColor3f(0, 0, 1);
 glTranslatef(0.1,0.2,0);
 glutSolidSphere(0.05,100,100);

 glColor3f(1.0, 0, 0); 
 glTranslatef(0.2,0.1,5);
 glutSolidSphere(0.05,100,100);

 glColor3f(1.0, 0, 1.0);
 glTranslatef(-0.1,0.3,0);
 glutSolidSphere(0.05,100,100);

 glColor3f(0, 1.0, 0);
 glTranslatef(0.1,0.1,-1);
 glutSolidSphere(0.05,100,100);

 glFlush();
}
