#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include<stdio.h>

/*
OpenGL is a software interface to graphics hardware. This interface consists of about 150 distinct commands that you use to
specify the objects and operations needed to produce interactive three-dimensional applications.
OpenGL is designed as a streamlined, hardware-independent interface to be implemented on many different hardware platforms.
To achieve these qualities, no commands for performing windowing tasks or obtaining user input are included in OpenGL;
instead, you must work through whatever windowing system controls the particular hardware you're using. Similarly, OpenGL
doesn't provide high-level commands for describing models of three-dimensional objects. Such commands might allow you to
specify relatively complicated shapes such as automobiles, parts of the body, airplanes, or molecules.
*/


static int t=0, a=0, z=1, x=0, count1=0, count2=0, c=0, i=0, y=0;	//initialize the values required
static int score=0;
static int flag=0;
static const int FPS = 50;//Ftames per Second
int level,m;

void init(void)
{
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glShadeModel (GL_FLAT);

//initializes color and shade model

}




void display(void)
{
	glClear (GL_COLOR_BUFFER_BIT);

	glColor3f (0.0, 1.0, 0.2);
	/* Nest */
	glPushMatrix();
	glTranslatef(-17.0,0.0,0.0);
	glScalef(5.00,1.0,1.0);
	glutSolidCube(1.0);
	glPopMatrix();
	/* Nest */

	glColor3f (1.0, 1.0, 0.2);
	/* Bird */
	glPushMatrix();
	glTranslatef(-15.0+(GLfloat)a,(GLfloat)y,0.0);
	glScalef(0.1,0.08,0.08);
	glutSolidCube(1.0);
	glPopMatrix();
	/* Bird */

	glColor3f (1.0, 0.0, 0.2);
	/* Home Target */
	glPushMatrix();
	glScalef(1.00,0.3,0.3);
	glTranslatef(15.0,0.0,0.0);
	glutSolidCube(1.0);
	glPopMatrix();
	/* Home Target */


	/* Obstacles */

	glPushMatrix();
	glTranslatef(-12.00,-5.00,0.00);
	glScalef(1.00,9.00,1.00);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-12.00,5.00,0.00);
	glScalef(1.00,9.00,1.00);
	glutSolidCube(1.0);
	glPopMatrix();



	glPushMatrix();
	glTranslatef(-7.00,-3.0,0.00);
	glScalef(1.00,9.00,1.00);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-7.00,7.00,0.00);
	glScalef(1.00,9.00,1.00);
	glutSolidCube(1.0);
	glPopMatrix();



	glPushMatrix();
	glTranslatef(-2.00,-8.00,0.00);
	glScalef(1.00,9.00,1.00);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2.00,2.00,0.00);
	glScalef(1.00,9.00,1.00);
	glutSolidCube(1.0);
	glPopMatrix();



	glPushMatrix();
	glTranslatef(3.00,-4.00,0.00);
	glScalef(1.00,9.00,1.00);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(3.00,6.00,0.00);
	glScalef(1.00,9.00,1.00);
	glutSolidCube(1.0);
	glPopMatrix();



	glPushMatrix();
	glTranslatef(8.00,0.00,0.00);
	glScalef(1.00,9.00,1.00);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(8.00,10.00,0.00);
	glScalef(1.00,9.00,1.00);
	glutSolidCube(1.0);
	glPopMatrix();

	/* Obstacles */

	
	glFlush();
	glutSwapBuffers();
}
void reshape (int w, int h)	//RESHAPES THE SCREEN
{
	glViewport (0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 0.2, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt (0.0, 0.0, 15.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void timer(int value)
{

	//Incrementation
	//X translation...Continous.
	if(z==1)
	{
		a=a+1;
		glutPostRedisplay();
		glutTimerFunc(m/FPS,timer,value);
	}
	//Back to Pavalion..
	else if(z==2)
	{
		a=0;y=0;
		glutPostRedisplay();
	}

	//w..move up
	else if(z==3)
	{
		y=(y+1)%9;
		glutPostRedisplay();
		z=1;
		glutTimerFunc(m/FPS,timer,value);
	}
	//s..move down
	else if(z==4)
	{
		y=(y-1)%9;
		glutPostRedisplay();
		z=1;
		glutTimerFunc(m/FPS,timer,value);
	}

		//printf("\t%d\t%d\n",a,y);


	// Collision Conditions
	if(a==3)
	{
		flag=1;
		if(y==0)
			score++;
		else
		{
			printf("\n\nSCORE : %d\n",score);
			exit(0);
		}
	}
	else if(a==8&&flag==1)
	{
		flag=2;
		if(y==2||y<=-8)
			score++;
		else
		{
			printf("\n\nSCORE : %d\n",score);
			exit(0);
		}
	}
	else if(a==13&&flag==2)
	{
		flag=3;
		if(y==-3||y>=7)
			score++;
		else
		{
			printf("\n\nSCORE : %d\n",score);
			exit(0);
		}
	}
	else if(a==18&&flag==3)
	{
		flag=4;
		if(y==1)
			score++;
		else
		{
			printf("\n\nSCORE : %d\n",score);
			exit(0);
		}
	}
	else if(a==23&&flag==4)
	{
		flag=5;
		if(y==5||y<=-5)
			score++;
		else
		{
			printf("\n\nSCORE : %d\n",score);
			exit(0);
		}
	}
	else if(a==30&&flag==5)
	{
		if(y==0)
		{
			printf("\n\n*************************************\n\t-----------\n\t| YOU WON |\n\t-----------\n*************************************\n\n");
			exit(0);
		}
		else
		{
			printf("\n\nSCORE : %d\n",score);
			exit(0);
		}
	}

	
}



void keyboard (unsigned char key, int x, int y)	//CONTROLS OF THE KEYBOARD
{


	switch (key)
	{


		case 'w':
			z=3;
		break;

		case 's':
			z=4;
		break;

		case 'a':
			z=2;
		break;

		case 'd':

			z=1;
			glutTimerFunc(100,timer,0);
		break;

	}
}

int main(int argc, char** argv)
{
	printf("-----------------\n|   FLAPPY BIRD |\n-----------------\n******************************\n* Enter the level :\t\t*\n*-------------------\t\t*\n*Level 1: NOOB (SLOW)\t\t*\n*Level 2: AMETEUR (MEDIUM)\t*\n*Level 3: EXPERT (FAST)\t\t*\n******************************\n\nENTER YOUR CHOICE :");
	scanf("%d",&level);
	
	//Level Defination.
	if(level==1)
		m=10000;
	else if(level==2)
		m=8000;
	else if(level==3)
		m=6000;

	glutInit(&argc, argv);
/*
	glutInit(int *argc, char **argv) initializes GLUT and processes any command line arguments (for X, this would be options
	like -display and -geometry). glutInit() should be called before any other GLUT routine.
*/
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
/*
glutInitDisplayMode(unsigned int mode) specifies whether to use an RGBA or color-index color model. You can also
specify whether you want a single- or double-buffered window. (If you're working in color-index mode, you'll want to load
certain colors into the color map; use glutSetColor() to do this.) Finally, you can use this routine to indicate that you want
the window to have an associated depth, stencil, and/or accumulation buffer. For example, if you want a window with
double buffering, the RGBA color model, and a depth buffer, you might call glutInitDisplayMode(GLUT_DOUBLE |
GLUT_RGB | GLUT_DEPTH)

*/
	glutInitWindowSize (500, 500);
/*
glutInitWindowSize(int width, int size) specifies the size, in pixels, of your window.
*/
	glutInitWindowPosition (100, 100);
/*
glutInitWindowPosition(int x, int y) specifies the screen location for the upper-left corner of your window.
*/
	glutCreateWindow (argv[0]);
	init ();

	
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);

	glutKeyboardFunc(keyboard);

	glutMainLoop();
	return 0;
}
