#include <GL/glut.h>


GLfloat xrotate, yrotate, zrotate;
void init(void)
{
	glClearColor(0, 0, 0, 0);

}

void center_cube(void)
{
	// Top
	glVertex3f(1.0f, 1.0f, -1.0f);    // Top Right 
	glVertex3f(-1.0f, 1.0f, -1.0f);    // Top Left  
	glVertex3f(-1.0f, 1.0f, 1.0f);    // Bottom Left 
	glVertex3f(1.0f, 1.0f, 1.0f);    // Bottom Right  

	// Bottom
	glVertex3f(1.0f, -1.0f, 1.0f);    // Top Right 
	glVertex3f(-1.0f, -1.0f, 1.0f);    // Top Left 
	glVertex3f(-1.0f, -1.0f, -1.0f);    // Bottom 
	glVertex3f(1.0f, -1.0f, -1.0f);    // Bottom 

	// Front
	glVertex3f(1.0f, 1.0f, 1.0f);    // Top Right 
	glVertex3f(-1.0f, 1.0f, 1.0f);    // Top Left 
	glVertex3f(-1.0f, -1.0f, 1.0f);    // Bottom 
	glVertex3f(1.0f, -1.0f, 1.0f);    // Bottom 

	// Back
	glVertex3f(1.0f, -1.0f, -1.0f);    // Top Right
	glVertex3f(-1.0f, -1.0f, -1.0f);    // Top Left
	glVertex3f(-1.0f, 1.0f, -1.0f);    // Bottom 
	glVertex3f(1.0f, 1.0f, -1.0f);    // Bottom 

	// Left
	glVertex3f(-1.0f, 1.0f, 1.0f);    // Top Right 
	glVertex3f(-1.0f, 1.0f, -1.0f);    // Top Left 
	glVertex3f(-1.0f, -1.0f, -1.0f);    // Bottom 
	glVertex3f(-1.0f, -1.0f, 1.0f);    // Bottom 

	// Right
	glVertex3f(1.0f, 1.0f, -1.0f);    // Top Right 
	glVertex3f(1.0f, 1.0f, 1.0f);    // Top Left 
	glVertex3f(1.0f, -1.0f, 1.0f);    // Bottom 
	glVertex3f(1.0f, -1.0f, -1.0f);    // Bottom 

}

void left_cube(void)
{
	// Top
	glVertex3f(-3.0f, 1.0f, -1.0f);    // Top Right 
	glVertex3f(-5.0f, 1.0f, -1.0f);    // Top Left 
	glVertex3f(-5.0f, 1.0f, 1.0f);    // Bottom Left 
	glVertex3f(-3.0f, 1.0f, 1.0f);    // Bottom Right 

	// Bottom
	glVertex3f(-3.0f, -1.0f, 1.0f);    // Top Right 
	glVertex3f(-5.0f, -1.0f, 1.0f);    // Top Left 
	glVertex3f(-5.0f, -1.0f, -1.0f);    // Bottom Left 
	glVertex3f(-3.0f, -1.0f, -1.0f);    // Bottom Right 

	// Front
	glVertex3f(-3.0f, 1.0f, 1.0f);    // Top Right 
	glVertex3f(-5.0f, 1.0f, 1.0f);    // Top Left 
	glVertex3f(-5.0f, -1.0f, 1.0f);    // Bottom Left 
	glVertex3f(-3.0f, -1.0f, 1.0f);    // Bottom Right 

	// Back
	glVertex3f(-3.0f, -1.0f, -1.0f);    // Top Right 
	glVertex3f(-5.0f, -1.0f, -1.0f);    // Top Left 
	glVertex3f(-5.0f, 1.0f, -1.0f);    // Bottom Left
	glVertex3f(-3.0f, 1.0f, -1.0f);    // Bottom Right 

	// Left
	glVertex3f(-5.0f, 1.0f, 1.0f);    // Top Right
	glVertex3f(-5.0f, 1.0f, -1.0f);    // Top Left 
	glVertex3f(-5.0f, -1.0f, -1.0f);    // Bottom Left
	glVertex3f(-5.0f, -1.0f, 1.0f);    // Bottom Right 

	// Right
	glVertex3f(-3.0f, 1.0f, -1.0f);    // Top Right
	glVertex3f(-3.0f, 1.0f, 1.0f);    // Top Left 
	glVertex3f(-3.0f, -1.0f, 1.0f);    // Bottom Left 
	glVertex3f(-3.0f, -1.0f, -1.0f);    // Bottom Right 
}

void right_cube(void)
{
	// Top
	glVertex3f(5.0f, 1.0f, -1.0f);    // Top Right 
	glVertex3f(3.0f, 1.0f, -1.0f);    // Top Left 
	glVertex3f(3.0f, 1.0f, 1.0f);    // Bottom Left 
	glVertex3f(5.0f, 1.0f, 1.0f);    // Bottom Right

	// Bottom
	glVertex3f(5.0f, -1.0f, 1.0f);    // Top Right 
	glVertex3f(3.0f, -1.0f, 1.0f);    // Top Left 
	glVertex3f(3.0f, -1.0f, -1.0f);    // Bottom Left
	glVertex3f(5.0f, -1.0f, -1.0f);    // Bottom Right 

	// Front 
	glVertex3f(5.0f, 1.0f, 1.0f);    // Top Right 
	glVertex3f(3.0f, 1.0f, 1.0f);    // Top Left 
	glVertex3f(3.0f, -1.0f, 1.0f);    // Bottom Left 
	glVertex3f(5.0f, -1.0f, 1.0f);    // Bottom Right 

	// Back
	glVertex3f(5.0f, -1.0f, -1.0f);    // Top Right 
	glVertex3f(3.0f, -1.0f, -1.0f);    // Top Left 
	glVertex3f(3.0f, 1.0f, -1.0f);    // Bottom Left 
	glVertex3f(5.0f, 1.0f, -1.0f);    // Bottom Right 

	// Left
	glVertex3f(3.0f, 1.0f, 1.0f);    // Top Right 
	glVertex3f(3.0f, 1.0f, -1.0f);    // Top Left
	glVertex3f(3.0f, -1.0f, -1.0f);    // Bottom Left
	glVertex3f(3.0f, -1.0f, 1.0f);    // Bottom Right 

	// Right
	glVertex3f(5.0f, 1.0f, -1.0f);    // Top Right 
	glVertex3f(5.0f, 1.0f, 1.0f);    // Top Left
	glVertex3f(5.0f, -1.0f, 1.0f);    // Bottom Left
	glVertex3f(5.0f, -1.0f, -1.0f);    // Bottom Right 
}

void DrawCubes(void)
{

	glMatrixMode(GL_MODELVIEW);
	

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		
	glLoadIdentity();

	glTranslatef(0.0, -3.0, -12.5);

	// Rotation 
	glRotatef(xrotate, 1.0, 0.0, 0.0);
	glRotatef(yrotate, 0.0, 1.0, 0.0);
	glRotatef(zrotate, 0.0, 0.0, 1.0);


	glBegin(GL_QUADS);        // Draw The Cube Using quads


	glColor3f(0.75f, 0.75f, 0.75f);    // Color Silver
	left_cube();
	glColor3f(1.0f, 0.84f, 0.0f);    // Color Gold
	center_cube();
	glColor3f(0.8f, 0.5f, 0.2f);    // Color Bronse
	right_cube();


	glEnd();            // End Drawing The Cube
	glFlush();
	glutSwapBuffers();
}


void keyboard(int key, int x, int y)
{
	switch (key)
	{
	case 65:	// A
		yrotate -= 5;
	case 68:	// D
		yrotate += 5;
	case 87:	// W
		xrotate += 5;
	case 83:	// S
		xrotate -= 5;
	}

	glutPostRedisplay();

}

void animation(void)
{

	yrotate += 0.05;
//	xrotate += 0.05;
	
	DrawCubes();
}


void reshape(int x, int y)
{
	if (y == 0 || x == 0) return;  

	glMatrixMode(GL_PROJECTION);	
	glLoadIdentity();

	gluPerspective(70.0, (GLdouble)x / (GLdouble)y, 0.5, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glViewport(0, 0, x, y); 
}

int main(int argc, char** argv) {

	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(800, 600);
	glutCreateWindow("3D Cubes");
	glEnable(GL_DEPTH_TEST);
	
	glutDisplayFunc(DrawCubes);
	glutReshapeFunc(reshape);

	//glutIdleFunc(DrawCubes);
	glutIdleFunc(animation);
	glutSpecialFunc(keyboard); 


	glutMainLoop();
	return 0;
}
