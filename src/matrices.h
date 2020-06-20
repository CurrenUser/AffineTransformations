#pragma once
#include "GL/glut.h"
#include <iostream>
using namespace std;

class MyMatrix
{
private:
	int counter;
	int all;
public:
	GLfloat** matrix;
	MyMatrix();
	MyMatrix(int);
	void add(GLfloat x,GLfloat  y, GLfloat z = 1.0f);
	void showMatrix();
	void deleteMatrix();
	int getCounter();
	int getSize();
	void setCounter(int counter);
	void ResetMatrix();
};

