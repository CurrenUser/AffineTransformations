#include "matrices.h"

MyMatrix::MyMatrix()
{
	matrix = new GLfloat*[4];
	all = 4;
	counter = 0;

	for (int i = 0; i < all; i++)
	{
		matrix[i] = new GLfloat[3];
	}
}

MyMatrix::MyMatrix(int size)
{
	matrix = new GLfloat * [size];
	all = size;
	counter = 0;

	for (int i = 0; i < all; i++)
	{
		matrix[i] = new GLfloat[3];
	}
}


void MyMatrix::add(GLfloat x , GLfloat y, GLfloat z)
{
	if (counter < all)
	{
		matrix[counter][0] = x;
		matrix[counter][1] = y;
		matrix[counter][2] = z;
	}
	else
	{
		all += 4;
		GLfloat **tempMatrix = new GLfloat*[all];
		
		for (int i = 0; i < all; i++)
		{
			tempMatrix[i] = new GLfloat[3];
			if (i < counter)
			{
				tempMatrix[i][0] = matrix[i][0];
				tempMatrix[i][1] = matrix[i][1];
				tempMatrix[i][2] = matrix[i][2];
			}
		}
		tempMatrix[counter][0] = x;
		tempMatrix[counter][1] = y;
		tempMatrix[counter][2] = z;
		this->deleteMatrix();
		matrix = tempMatrix;
	}
	counter++;
}

void MyMatrix::showMatrix()
{
	for (int i = 0; i < counter; i++)
	{
		for (int k = 0; k < 3; k++)
		{
			cout << matrix[i][k] << " ";
		}
		cout << endl;
	}
}

// Destructor matrix;
void MyMatrix::deleteMatrix()
{
	for (int j = 0; j < all - 4; j++)
	{
			delete[] matrix[j];
	}
	delete [] matrix;
}

int MyMatrix::getCounter()
{
	return counter;
}

void MyMatrix::setCounter(int counter)
{
	this->counter = counter;
}

int MyMatrix::getSize()
{
	return all;
}

void MyMatrix::ResetMatrix()
{
	for (int j = 0; j < 3; j++)
	{
		for (int k = 0; k < 3; k++)
		{
			matrix[j][k] = 0;
		}
	}

	matrix[0][0] = 1;
	matrix[1][1] = 1;
	matrix[2][2] = 1;
}