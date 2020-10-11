#pragma once

void render();
void changeViewPort(int w, int h);
void timerHandller(int t);
void keyboardHanddle(unsigned char c, int x, int y);
void mouseHanddle(int button, int state, int x, int y);
void joystickHanddle(unsigned int buttonmask, int x, int y, int z);