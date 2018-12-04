#include <GL/glut.h>

GLdouble w, h;
GLfloat xrotate, yrotate, zrotate;
int proj_type = 0;
int rotate_type = 0; // 0  around scene, 1 around center cube , 2 around invd center 

void init(void)
{
	glClearColor(0, 0, 0, 0);

}



void cube(GLdouble rx, GLdouble ry, GLdouble offset) {
	glPushMatrix();
	glTranslatef(offset, 0, 0);
	glRotatef(rx, 1.0, 0.0, 0.0);
	glRotatef(ry, 0.0, 0.0, 1.0);
	glutSolidCube(2.0f);
	glPopMatrix();
}


void DrawCubes(void)
{

	glMatrixMode(GL_MODELVIEW);
	

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		
	
	glPushMatrix();

	GLdouble xr = 0.0, yr = 0.0;


	
	if (rotate_type == 0) {
		glRotatef(xrotate, 1.0, 0.0, 0.0);
		glRotatef(yrotate, 0.0, 0.0, 1.0);
	}
	
	glTranslatef(-1.5, 0, 0);

	if(rotate_type == 1){
		
		glRotatef(xrotate, 1.0, 0.0, 0.0);
		glRotatef(yrotate, 0.0, 0.0, 1.0);
		
	}


	if (rotate_type == 2) {
		xr = xrotate;
		yr = yrotate;
	}

	glColor3f(0.75f, 0.75f, 0.75f);    // Color Silver
	cube(xr, yr, 2);
	glPushMatrix();
	glTranslated(0, 0, 2);
	glColor3f(1.0f, 0.84f, 0.0f);    // Color Gold
	cube(xr, yr, 0.0);
	glPopMatrix();
	glColor3f(0.8f, 0.5f, 0.2f);    // Color Bronse
	cube(xr, yr, -2);


	glPopMatrix();
	glFlush();
	glutSwapBuffers();
}


void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'a':	// A
		yrotate -= 5;
		break;
	case 'd':	// D
		yrotate += 5;
		break;
	case 'w':	// W
		xrotate += 5;
		break;
	case 's':	// S
		xrotate -= 5;
		break;
	default:
		break;

	}

	glutPostRedisplay();

}




void reset_projection(int type) {
	if (type == 0) { // perspective
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(70.0, w / h, 0.5, 20.0);
		glViewport(0, 0, w, h);
	
	}
	else if (type == 1) {
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(-10 * (float)w / h, 10*(float)w/h, -10, 10, 0, 20);
		glViewport(0, 0, w, h);
	}

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, 10, 0, 0, 0, 0, 0, 0, 1);

}



void specialkeys(int key, int x, int y) {
	switch (key)
	{
	case GLUT_KEY_PAGE_UP:
		proj_type = (proj_type + 1) % 2;
		break;
	case GLUT_KEY_PAGE_DOWN:
		rotate_type = (rotate_type+1)%3;
		break;
	default:
		break;
	}
	xrotate = 0;
	yrotate = 0;
	reset_projection(proj_type);
	glutPostRedisplay();

}


void reshape(int x, int y)
{
	if (y == 0 || x == 0) return;  

	w = x;
	h = y;

	reset_projection(proj_type);
	
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
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(specialkeys);

	glutMainLoop();
	return 0;
}
