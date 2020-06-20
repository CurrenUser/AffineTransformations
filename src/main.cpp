#include "graphics.h"

int main(int argc, char** argv)
{
	graphics graphics;
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize((GLint)WIDTH, (GLint)HEIGHT);
	glutCreateWindow("-=[Affine transformations]=-");
	graphics.initialization();
	graphics.menuInitialization();
	glutDisplayFunc(graphics.DrawScene);
	glutMouseFunc(graphics.MouseKlick);
	glutReshapeFunc(graphics.ResizeWindows);
	glutMainLoop();
}