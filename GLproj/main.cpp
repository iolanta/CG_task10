#include <GL/glut.h>
#include<SOIL2.h>
#include <cstdlib>
#include <time.h> 

//Глобальные статические переменные - хранят текущий размер экрана
static int w = 0, h = 0, x = 0, y = 0, type = 0;
GLfloat clr[9];
GLdouble rotate = 0;

GLfloat rand_color() {
	return (double)std::rand() / RAND_MAX;
}
//Функция вызываемая каждый кадр - для его отрисовки, вычислений и т. д.
void Update(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();

	GLfloat wx = (GLfloat)x / w;
	GLfloat wy = (GLfloat)y / h;
	GLfloat center_x, center_y;
	
	switch (type)
	{
	case 0:
		glColor3f(clr[0], clr[1], clr[2]);
		center_x = (wx * 3 + 0.9) / 3;
		center_y = (wy * 3 + 0.4) / 3;

		glTranslatef(center_x, center_y, 0);
		glRotatef(rotate, 0, 0, -1);
		glTranslatef(-center_x, -center_y, 0);
		
		glBegin(GL_TRIANGLES);
		glVertex2f(wx, wy);
		glVertex2f(wx + 0.3, wy + 0.4);
		glVertex2f(wx + 0.6, wy);
		glEnd();

		
		break;
	case 1:
		glColor3f(clr[0], clr[1], clr[2]);
		center_x = (wx * 4 + 1.2) / 4;
		center_y = (wy * 4 + 0.8) / 4;
		
		glTranslatef(center_x, center_y, 0);
		glRotatef(rotate, 0, 0, -1);
		glTranslatef(-center_x, -center_y, 0);

		glBegin(GL_QUADS);
		glVertex2f(wx, wy);
		glVertex2f(wx, wy + 0.4);
		glVertex2f(wx + 0.6, wy + 0.4);
		glVertex2f(wx + 0.6, wy);
		glEnd();
		break;
	case 2:
		center_x = (wx * 3 + 0.9) / 3;
		center_y = (wy * 3 + 0.4) / 3;
		
		glTranslatef(center_x, center_y, 0);
		glRotatef(rotate, 0, 0, -1);
		glTranslatef(-center_x, -center_y, 0);

		glBegin(GL_TRIANGLES);
		glVertex2f(wx, wy); glColor3f(clr[0], clr[1], clr[2]);
		glVertex2f(wx + 0.3, wy + 0.4); glColor3f(clr[3], clr[4], clr[5]);
		glVertex2f(wx + 0.6, wy); glColor3f(clr[6], clr[7], clr[8]);
		glEnd();
		break;
	default:
		break;
	}
	
	glPopMatrix();
	glFlush();
	glutSwapBuffers();
}

void Reshape(int width, int height)
{
	w = width;
	h = height; 
	glViewport(0, 0, w, h);
}

//Функция вызываемая перед вхождением в главный цикл
void Init(void)
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	gluOrtho2D(0.0, 1.0, 0.0, 1.0);
}

void MouseClick(int button, int state, int _x, int _y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		x = _x;
		y = h -_y;
		rotate = 0;
		type = (type + 1) % 3;
		for (int i = 0; i < 9; ++i)
			clr[i] = rand_color();
	}
}

void specialKeys(int key, int x, int y) {
	switch (key)
	{
	case GLUT_KEY_RIGHT:
		rotate += 5;
		break;
	case GLUT_KEY_LEFT:
		rotate -= 5;
	default:
		break;
	}
}

int main(int argc, char **argv)
{
	srand(time(NULL));
	//Инициализировать сам glut
	glutInit(&argc, argv);
	//Установить начальное положение окна
	glutInitWindowPosition(100, 100);
	//Установить начальные размеры окна
	glutInitWindowSize(600, 600);
	//Установить параметры окна - двойная буфферизация и поддержка цвета RGBA
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutCreateWindow("2D Figures");	
	//Укажем glut функцию, которая будет вызываться каждый кадр
	glutIdleFunc(Update);

	//Укажем glut функцию, которая будет рисовать каждый кадр
	glutDisplayFunc(Update);
	//Укажем glut функцию, которая будет вызываться при изменении размера окна приложения
	glutReshapeFunc(Reshape);
	glutMouseFunc(MouseClick); 
	glutSpecialFunc(specialKeys);

	for (int i = 0; i < 9; ++i)
		clr[i] = rand_color();
	Init();
	//Войти в главный цикл приложения
	glutMainLoop();
	return 0;           
}