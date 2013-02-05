#include <stdio.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include <unistd.h>

void init(void);
void display(void);
void reshape(int w, int h);
void speckeyhandler(int key, int x, int y);

GLfloat blue[] = { 0.0, 0.0, 1.0, 1.0 };     /* blue */
GLfloat sx = 1.0;
GLfloat sy = 1.0;
GLfloat sz = 1.0;

int main(int argc, char** argv){
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(800, 800);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("Hello");
  init();
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutSpecialFunc(speckeyhandler);
  glutMainLoop();
  
    return 0;
}
void init(void)
{
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
    
  //glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
 
}
void reshape(int w, int h)
{
  GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
  GLfloat light_ambient[] = { .15, .15, .15, 1.0 };
  GLfloat light_pos[] = { 0.0, 100.0, 0.0 }; 

  glViewport(0,0,(GLsizei) w, (GLsizei) h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(60.0, (GLfloat) w/ (GLfloat) h, 1,10); 
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
  glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
    printf("%lf %lf %lf", sx,sy,sz);

  gluLookAt(sx,sy,sz,
  	    0.7,0.7,0.7,
  	    0.0,1.0,0.0);
}

void display(void)
{
    
  
    glClear(GL_COLOR_BUFFER_BIT);
 
    glLoadIdentity();
    gluLookAt(sx,sy,sz,
              0.7,0.7,0.7,
              0.0,1.0,0.0);
    

  //Balloon 1 
  glColor4fv(blue);
  glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, blue); 
   
    glPushMatrix();
        glTranslatef(0.3,0.3,0);
        glutSolidSphere(0.05,10,10);
    glPopMatrix();
    
    
  glColor4fv(blue); 
  
    glPushMatrix();
        glTranslatef(0.1,0.1,0);
        glutSolidSphere(0.05,10,10);
    glPopMatrix();

    
  glColor4fv(blue);
    
    glPushMatrix();
        glTranslatef(0.1,0.0,0);
        glutWireSphere(0.05,10,10);
    glPopMatrix();
  
  
  glColor4fv(blue);
    glPushMatrix();
        glTranslatef(0.1,0.1,0);
        glutWireSphere(0.05,10,10);
    glPopMatrix();
    
    
  glColor4fv(blue);
    glPushMatrix();
        glTranslatef(0.1,0.1,0);
        glutWireSphere(0.05,10,10);
    glPopMatrix();

  
  glColor4fv(blue);
    
    glPushMatrix();
        glTranslatef(0.1,0.1,0);
        glutWireSphere(0.05,10,10);
    glPopMatrix();
    

  glFlush();
}
void speckeyhandler(int key, int x, int y)
{
    
    switch (key) {
        case GLUT_KEY_UP:
            sy += 0.1;
            break;
        case GLUT_KEY_DOWN:
            sy -= 0.1;
            break;
        case GLUT_KEY_LEFT:
            sx += 0.1;
            break;
        case GLUT_KEY_RIGHT:
            sx -= 0.1;
            break;
            
            
        default:
            break;
    }
    
    glutPostRedisplay();
    
}
