#include <stdlib.h>
#include <GL/glut.h>
#include <iostream>
#include "callbacks.h"

using namespace std;

static int state = 1;

static float x_position = -10.0;

//joystick key map
static const int A_KEY = 97;

static int   button1 = 0; //A or X 
static int   button2 = 0;
static int   button3 = 0;
static int   button4 = 0;
static int   button5 = 0;
static int   button6 = 0;
static int   button7 = 0;
static int   button8 = 0;
static int   x_axis = 0;
static int   y_axis = 0;
static int   z_axis = 0;

void timerHandller(int t) {
	glutPostRedisplay(); //call render() when possible
	glutTimerFunc(1000 / 60, timerHandller, 0);
	switch (state)
	{
	case 1:
		if (x_position < 8)
		{
			if (x_axis > 0)
			{
				x_position += 0.15f;
			}
			else if (x_axis <= -1) {
				state = -1;
			}
		}
		else
		{
			state = -1;
		}
		break;
	case -1:
		if (x_position > -10) {
			if (x_axis <= -1)
			{
				x_position -= 0.15f;
			}
			else if (x_axis > 0) {
				state = 1;
			}
		}
		else {
			state = 1;
		}
		break;
	}
}

void changeViewPort(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-10, 10, -10, 10);
	glMatrixMode(GL_MODELVIEW);
}

void render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	//glPointSize(90.0);
	//glShadeModel(GL_FLAT); //GL_SMOOTH default

	glBegin(GL_POLYGON);
		glColor3f(1.0, 0.0, 0.0);
		glVertex2f(x_position, 1.0);
		glColor3f(1.0, 1.0, 0.0);
		glVertex2f(x_position, -1.0);
		glColor3f(0.0, 1.0, 0.0);
		glVertex2f(x_position + 2.0, -1.0);
		glColor3f(0.0, 0.0, 1.0);
		glVertex2f(x_position + 2.0, 1.0);
	glEnd();

	glBegin(GL_TRIANGLES);
		glColor3f(1, 1, 0);
		glVertex2f(-0.5, -0.5);
		glColor3f(0, 1, 0);
		glVertex2f(0.5, -0.5);
		glColor3f(0, 0, 1);
		glVertex2f(0.0, 0.5);
	glEnd();

	glutSwapBuffers(); //swap buffers positions
	//glFlush(); //flush buffer
}

void keyboardHanddle(unsigned char c, int x, int y)
{
	if (c == A_KEY) {
		exit(0);
	}
}

void joystickHanddle(unsigned int buttonmask, int x, int y, int z)
{
	x_axis = x;
	y_axis = y;
	z_axis = z;

	if (buttonmask & 0x01)  button1 = 1;
	else  button1 = 0;

	if (buttonmask & 0x02) button2 = 1;
	else button2 = 0;

	if (buttonmask & 0x04) button3 = 1;
	else button3 = 0;

	if (buttonmask & 0x08) button4 = 1;
	else button4 = 0;

	if (buttonmask & 0x10) button5 = 1;
	else button5 = 0;

	if (buttonmask & 0x20) button6 = 1;
	else button6 = 0;

	if (buttonmask & 0x40) button7 = 1;
	else button7 = 0;

	if (buttonmask & 0x80) button8 = 1;
	else button8 = 0;

	if (x_axis > 0) {
		printf("\n x_axis positive");
	}
	else if (x_axis < -1) {
		printf("\n x_axis negative");
	}

	if (button1) {
		printf(" \n Button A pressed");
	}

}

void mouseHanddle(int button, int state, int x, int y)
{
	if (button == GLUT_RIGHT_BUTTON) {
		exit(0);
	}
}