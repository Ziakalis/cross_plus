#pragma once
#include <stdio.h>
#include <GL/glut.h>
#include "scene.h"

// Window Init Funciton
void wnd_init();

// Main Display Function
void on_display();

// Mouse Function
void on_mouse_btn(int button, int state, int x, int y);
void on_mouse_move(int x, int y);

// Size Change Function
void on_size_change(int w, int h);

// Assistent Functions
void draw_text(GLint x, GLint y, char *s, GLfloat r, GLfloat g, GLfloat b);

