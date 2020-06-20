#include "graphics.h"
#include "matrices.h"
#include <math.h>

MyMatrix points;
MyMatrix shift(3);
MyMatrix rotation(3);
MyMatrix scaling(3);
MyMatrix miror(3);
bool down = false, line = false;

// Constructor without parameters;
graphics::graphics()
{
	WIDTH = 600.0f;
	HEIGHT = 600.0f;
}

// Constructor with two parameters;
graphics::graphics(GLfloat width, GLfloat height)
{ 
	WIDTH = width;
	HEIGHT = height;
}

// Basic setting OpenGl;
void graphics::initialization()
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // Black collor;
	glColor3f(0.0f, 1.0f, 0.0f); // Green collor;
	glPointSize(3);

	shift.add(1.0f,0.0f,1.0f);
	shift.add(0.0f, 1.0f, 0.0f);
	shift.add(0.0f, 0.0f, 1.0f);

	rotation.add(0.0f, -1.0f,0.0f);
	rotation.add(1.0f, 0.0f, 0.0f);
	rotation.add(0.0f, 0.0f, 1.0f);

	scaling.add(0.0f, 0.0f, 0.0f);
	scaling.add(0.0f, 0.0f, 0.0f);
	scaling.add(0.0f, 0.0f, 1.0f);

	miror.add(-1.0f, 0.0f, 0.0f);
	miror.add(0.0f, 1.0f, 0.0f);
	miror.add(0.0f, 0.0f, 1.0f);

}

// Method for resize main window;
void graphics::ResizeWindows(GLsizei width_of_window, GLsizei height_of_window)
{	
	WIDTH = (GLfloat)width_of_window / 2.0f; // -x | x;
	HEIGHT = (GLfloat)height_of_window / 2.0f; // -y | y;
	glViewport(0, 0, width_of_window, height_of_window);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-WIDTH, WIDTH, -HEIGHT, HEIGHT, 0, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

// Method create menu windeows;
void graphics::menuInitialization()
{
	int menu = glutCreateMenu(menuCheck);
	glutSetMenu(menu);
	glutAddMenuEntry("CLear window", 1);
	glutAddMenuEntry("Draw lines", 2);
	glutAddMenuEntry("Draw Shift left", 3);
	glutAddMenuEntry("Draw Shift right", 4);
	glutAddMenuEntry("Draw Shift top", 5);
	glutAddMenuEntry("Draw Shift bottom", 6);
	glutAddMenuEntry("Rotation at 90", 7);
	glutAddMenuEntry("Scaling x2", 8);
	glutAddMenuEntry("Scaling x1", 9);
	glutAddMenuEntry("Miror x", 10);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void graphics::menuCheck(int value)
{
	switch (value)
	{
	case 1:
		down = false;
		line = false;
		points.setCounter(0);
		glutPostRedisplay();
	break;
	case 2:
		down = false;
		line = true;
		glutPostRedisplay();
	break;
	case 3:
		cout << "Matrix before shif left" << endl;
		shift.matrix[2][0] = -10.0f;
		shift.matrix[2][1] = 0.0f;
		points.showMatrix();
		points.matrix = affineTransformations(points.matrix, shift.matrix, points.getSize(),points.getCounter());
		cout << "Matrix after shif left" << endl;
		points.showMatrix();
		glutPostRedisplay();
		break;
	case 4:
		cout << "Matrix before shift rigt" << endl;
		shift.matrix[2][0] = 10.0f;
		shift.matrix[2][1] = 0.0f;
		points.showMatrix();
		points.matrix = affineTransformations(points.matrix, shift.matrix, points.getSize(), points.getCounter());
		cout << "Matrix after sshift rigt" << endl;
		points.showMatrix();
		glutPostRedisplay();
		break;
	case 5:
		cout << "Matrix before shift top" << endl;
		shift.matrix[2][0] = 0.0f;
		shift.matrix[2][1] = 10.0f;
		points.showMatrix();
		points.matrix = affineTransformations(points.matrix, shift.matrix, points.getSize(), points.getCounter());
		cout << "Matrix after shift top" << endl;
		points.showMatrix();
		glutPostRedisplay();
		break;
	case 6:
		cout << "Matrix before shift bottom" << endl;
		shift.matrix[2][0] = 0.0f;
		shift.matrix[2][1] = -10.0f;
		points.showMatrix();
		points.matrix = affineTransformations(points.matrix, shift.matrix, points.getSize(), points.getCounter());
		cout << "Matrix after shift bottom" << endl;
		points.showMatrix();
		glutPostRedisplay();
		break;
	case 7:
		cout << "Matrix before rotate 90 os z" << endl;
		points.showMatrix();
		points.matrix = affineTransformations(points.matrix, rotation.matrix, points.getSize(), points.getCounter());
		cout << "Matrix after rotate 90 os z" << endl;
		points.showMatrix();
		glutPostRedisplay();
		break;
	case 8:
		cout << "Matrix before scaling x2" << endl;
		scaling.matrix[0][0] = 1.1f;
		scaling.matrix[1][1] = 1.1f;
		points.showMatrix();
		points.matrix = affineTransformations(points.matrix, scaling.matrix, points.getSize(), points.getCounter());
		cout << "Matrix after scaling" << endl;
		points.showMatrix();
		glutPostRedisplay();
		break;
	case 9:
		cout << "Matrix before scaling x2" << endl;
		scaling.matrix[0][0] = 0.9f;
		scaling.matrix[1][1] = 0.9f;
		points.showMatrix();
		points.matrix = affineTransformations(points.matrix, scaling.matrix, points.getSize(), points.getCounter());
		cout << "Matrix after scaling" << endl;
		points.showMatrix();
		glutPostRedisplay();
		break;
	case 10:
		cout << "Matrix before miror" << endl;
		points.showMatrix();
		points.matrix = affineTransformations(points.matrix, miror.matrix, points.getSize(), points.getCounter());
		cout << "Matrix after miror" << endl;
		points.showMatrix();
		glutPostRedisplay();
		break;
	}
}

// Select pSoints
void graphics::MouseKlick(int button, int state, int x_mouse, int y_mouse)
{
	switch (button)
	{
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN)
		{
			x_mouse = x_mouse - (int)WIDTH;
			y_mouse = (int)HEIGHT - y_mouse;
			cout << "Mouse click - coordinates x,y:" << x_mouse << "|" << y_mouse << endl;
			points.add((GLfloat)x_mouse, (GLfloat)y_mouse);
			down = true;
		}
		break;
	}
}

// Draw shift;
GLfloat** affineTransformations(GLfloat **mainMatrix, GLfloat **shiftMatrix, int size, int counter)
{
	GLfloat **temp = new GLfloat * [size];
	for (int i = 0; i < size; i++)
	{
		temp[i] = new GLfloat[3];
		temp[i][0] = 0; temp[i][1] = 0; temp[i][2] = 1;
	}

	for (int i = 0; i < counter; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				temp[i][j] += mainMatrix[i][k] * shiftMatrix[k][j];
			}
		}
	}

	for (int j = 0; j < size; j++)
	{
		delete[] mainMatrix[j];
	}
	delete[] mainMatrix;
	mainMatrix = nullptr;

	return temp;
}

// Draw scene;
void graphics::DrawScene()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_LINES);
	glVertex2f(-WIDTH, 0.0f); glVertex2f(WIDTH, 0.0f);
	glVertex2f(0.0f, -HEIGHT); glVertex2f(0.0f, HEIGHT);
	glEnd();


	if (line)
	{
		glColor3f(0.0f, 1.0f, 1.0f);
		glBegin(GL_LINE_LOOP);
		for (int i = 0; i < points.getCounter(); i++)
		{
			glVertex2f(points.matrix[i][0], points.matrix[i][1]);
		}
		glEnd();
	}

	if (down)
	{
		glBegin(GL_POINTS);
		glColor3f(1.0f, 1.0f, 0.0f);
		for (int i = 0; i < points.getCounter(); i++)
		{
			glVertex2f(points.matrix[i][0], points.matrix[i][1]);
		}
		glEnd();
	}

	glutSwapBuffers();
}