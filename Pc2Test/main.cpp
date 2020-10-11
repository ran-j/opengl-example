#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>
#include "callbacks.h"

static int win;

int main(int argc, char* argv[]) {

	// Initialize GLUT
	glutInit(&argc, argv);
	// Set up some memory buffers for our display
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	// Set the window size
	glutInitWindowSize(800, 600);
	//Set the window position
	glutInitWindowPosition(100, 100);
	// Create the window with the title "Hello,GL"
	win = glutCreateWindow("PC2 Test");
	// set the clearcolor and the callback
	glClearColor(0.0, 0.0, 0.0, 1.0);
	// Bind the two functions (above) to respond when necessary
	glutReshapeFunc(&changeViewPort);
	glutDisplayFunc(&render);

	// Very important!  This initializes the entry points in the OpenGL driver so we can 
	// call all the functions in the API.
	GLenum err = glewInit();
	if (GLEW_OK != err) {
		fprintf(stderr, "GLEW error");
		return 1;
	}

	glutKeyboardFunc(&keyboardHanddle);
	glutJoystickFunc(&joystickHanddle, 10);
	glutMouseFunc(&mouseHanddle);
	glutTimerFunc(0, &timerHandller, 0);

	glutMainLoop();
	return 0;
}
