#include <stdio.h>
#include <stdlib.h>
#include "cross_plus_core.h"
#include "utility.h"
#include "scene.h"
#include "gl_render.h"

scene *scene_ptr;

int main(int argc, char* argv[])
{
    scene_ptr = new scene(640, 480);
    // Create Wnd
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100,150);
    glutCreateWindow("Cross Plus");

    // Set Callbacks
    glutDisplayFunc(on_display);
    glutIdleFunc(on_display);
    glutMouseFunc(on_mouse_btn);
    glutMotionFunc(on_mouse_move);
    glutReshapeFunc(on_size_change);

    // Init and Run
    wnd_init();
    glutMainLoop();

    delete scene_ptr;
    return 0;
}