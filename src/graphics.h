#pragma once
#include "GL/glut.h"
#include <iostream>
using namespace std;

static GLfloat WIDTH, HEIGHT; // Cartsian coordinates  -x | x | -y | y;

GLfloat** affineTransformations(GLfloat** mainMatrix, GLfloat** shiftMatrix, int size, int counter);

// Class using Affine of transformations; 
class graphics
{
private:
public:
	graphics(); // Constructor without parameterse;
	graphics(GLfloat width, GLfloat height); // Constructor with two parameters;
	void initialization(); // Basic setting Opengl | Базовые настройки OpenGl;
	void menuInitialization(); // Create main menu;
	static void menuCheck(int value); // Menu comamnd;
	static void ResizeWindows(GLsizei width_of_window, GLsizei height_of_window); // Method for resize main window;
	static void DrawScene(); // Draw scene;
	static void MouseKlick(int button, int state, int x_mouse, int y_mouse); // Select points;
};

