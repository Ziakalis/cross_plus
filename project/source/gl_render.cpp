#include "gl_render.h"

extern scene *scene_ptr;

// Window Init Funciton
void wnd_init()
{
    if (!scene_ptr)
        return;
    glClearColor(0.2, 0.2, 0.2, 0.0);
    glColor3f(0.0f,0.0f,0.0f);
    glPointSize(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,scene_ptr->wnd_w,0.0,scene_ptr->wnd_h);
}

// Main Display Function
void on_display()
{
    if (!scene_ptr)
        return;
    glClear(GL_COLOR_BUFFER_BIT);

    // Display Numbers
    (scene_ptr->is_mouse_btn_down && (scene_ptr->p1n1.actived_beg || scene_ptr->p1n1.actived_end)) ? glColor3f(0.8, 0.8, 0.6) : glColor3f(0.6, 0.6, 0.4);
    glRecti(scene_ptr->p1n1.x1, scene_ptr->p1n1.y1, scene_ptr->p1n1.x2, scene_ptr->p1n1.y2);
    (scene_ptr->is_mouse_btn_down && (scene_ptr->p1n2.actived_beg || scene_ptr->p1n2.actived_end)) ? glColor3f(0.8, 0.8, 0.6) : glColor3f(0.6, 0.6, 0.4);
    glRecti(scene_ptr->p1n2.x1, scene_ptr->p1n2.y1, scene_ptr->p1n2.x2, scene_ptr->p1n2.y2);
    (scene_ptr->is_mouse_btn_down && (scene_ptr->p2n1.actived_beg || scene_ptr->p2n1.actived_end)) ? glColor3f(0.8, 0.8, 0.6) : glColor3f(0.6, 0.6, 0.4);
    glRecti(scene_ptr->p2n1.x1, scene_ptr->p2n1.y1, scene_ptr->p2n1.x2, scene_ptr->p2n1.y2);
    (scene_ptr->is_mouse_btn_down && (scene_ptr->p2n2.actived_beg || scene_ptr->p2n2.actived_end)) ? glColor3f(0.8, 0.8, 0.6) : glColor3f(0.6, 0.6, 0.4);
    glRecti(scene_ptr->p2n2.x1, scene_ptr->p2n2.y1, scene_ptr->p2n2.x2, scene_ptr->p2n2.y2);
    
    // Draw Line
    if (scene_ptr->is_mouse_btn_down)
    {
        //printf("Line!  %d    %d    %d   %d\n", scene_ptr->pos_line_beg_x, scene_ptr->pos_line_beg_y, scene_ptr->pos_line_end_x, scene_ptr->pos_line_end_y);
        glColor3f(0.9, 0.2, 0.3);
        glBegin(GL_LINES);
        glVertex2i(scene_ptr->pos_line_beg_x, scene_ptr->pos_line_beg_y);
        glVertex2i(scene_ptr->pos_line_end_x, scene_ptr->pos_line_end_y);
        glEnd();
    }

    // Display Text Elements
    begin_text();
    if (scene_ptr->cpc_ptr->cur_player == 1)
    {
        draw_text(20, 20, (char*)"Player1's turn.", 0.7, 0.7, 0.7, GLUT_BITMAP_HELVETICA_18);
    }
    else
    {
        draw_text(20, scene_ptr->wnd_h - 20, (char*)"Player2's turn.", 0.7, 0.7, 0.7, GLUT_BITMAP_HELVETICA_18);
    }
    char s;
    s = (char)(scene_ptr->cpc_ptr->player1_num1 + 0x30);
    draw_text(scene_ptr->p1n1.xc - 6, scene_ptr->p1n1.yc - 6, &s, 0.2, 0.2, 0.2, GLUT_BITMAP_TIMES_ROMAN_24);
    s = (char)(scene_ptr->cpc_ptr->player1_num2 + 0x30);
    draw_text(scene_ptr->p1n2.xc - 6, scene_ptr->p1n2.yc - 6, &s, 0.2, 0.2, 0.2, GLUT_BITMAP_TIMES_ROMAN_24);
    s = (char)(scene_ptr->cpc_ptr->player2_num1 + 0x30);
    draw_text(scene_ptr->p2n1.xc - 6, scene_ptr->p2n1.yc - 6, &s, 0.2, 0.2, 0.2, GLUT_BITMAP_TIMES_ROMAN_24);
    s = (char)(scene_ptr->cpc_ptr->player2_num2 + 0x30);
    draw_text(scene_ptr->p2n2.xc - 6, scene_ptr->p2n2.yc - 6, &s, 0.2, 0.2, 0.2, GLUT_BITMAP_TIMES_ROMAN_24);
    end_text();

    glFlush();
}

// Mouse Function
void on_mouse_btn(int button, int state, int x, int y)
{
    if (!scene_ptr)
        return;

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        scene_ptr->is_mouse_btn_down = true;
        scene_ptr->pos_line_beg_x = x;
        scene_ptr->pos_line_beg_y = scene_ptr->wnd_h - y;
        scene_ptr->pos_line_end_x = x;
        scene_ptr->pos_line_end_y = scene_ptr->wnd_h - y;
        scene_ptr->stg = strategy::idel;
        //printf("Btn Down! Cur Player: %d\n", scene_ptr->cpc_ptr->cur_player);
        scene_ptr->p1n1.actived_beg = is_point_in_rect(scene_ptr->pos_line_beg_x, scene_ptr->pos_line_beg_y,
                                                       scene_ptr->p1n1.x1, scene_ptr->p1n1.y1, scene_ptr->p1n1.x2, scene_ptr->p1n1.y2) &&
                                      scene_ptr->cpc_ptr->cur_player == 1;

        scene_ptr->p1n2.actived_beg = is_point_in_rect(scene_ptr->pos_line_beg_x, scene_ptr->pos_line_beg_y,
                                                       scene_ptr->p1n2.x1, scene_ptr->p1n2.y1, scene_ptr->p1n2.x2, scene_ptr->p1n2.y2) &&
                                      scene_ptr->cpc_ptr->cur_player == 1;

        scene_ptr->p2n1.actived_beg = is_point_in_rect(scene_ptr->pos_line_beg_x, scene_ptr->pos_line_beg_y,
                                                       scene_ptr->p2n1.x1, scene_ptr->p2n1.y1, scene_ptr->p2n1.x2, scene_ptr->p2n1.y2) &&
                                      scene_ptr->cpc_ptr->cur_player == 2;

        scene_ptr->p2n2.actived_beg = is_point_in_rect(scene_ptr->pos_line_beg_x, scene_ptr->pos_line_beg_y,
                                                       scene_ptr->p2n2.x1, scene_ptr->p2n2.y1, scene_ptr->p2n2.x2, scene_ptr->p2n2.y2) &&
                                      scene_ptr->cpc_ptr->cur_player == 2;
        scene_ptr->p1n1.actived_end = false;
        scene_ptr->p1n2.actived_end = false;
        scene_ptr->p2n1.actived_end = false;
        scene_ptr->p2n2.actived_end = false;
    }

    if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
    {
        scene_ptr->is_mouse_btn_down = false;

        // Stragty Recognise
        if (scene_ptr->cpc_ptr->cur_player == 1)
        {
            if (scene_ptr->p1n1.actived_beg)
            {
                if (scene_ptr->p2n1.actived_end)
                {
                    scene_ptr->stg = strategy::l_plus_l;
                }
                if (scene_ptr->p2n2.actived_end)
                {
                    scene_ptr->stg = strategy::l_plus_r;
                }
            }
            if (scene_ptr->p1n2.actived_beg)
            {
                if (scene_ptr->p2n1.actived_end)
                {
                    scene_ptr->stg = strategy::r_plus_l;
                }
                if (scene_ptr->p2n2.actived_end)
                {
                    scene_ptr->stg = strategy::r_plus_r;
                }
            }
        }
        if (scene_ptr->cpc_ptr->cur_player == 2)
        {
            if (scene_ptr->p2n1.actived_beg)
            {
                if (scene_ptr->p1n1.actived_end)
                {
                    scene_ptr->stg = strategy::l_plus_l;
                }
                if (scene_ptr->p1n2.actived_end)
                {
                    scene_ptr->stg = strategy::l_plus_r;
                }
            }
            if (scene_ptr->p2n2.actived_beg)
            {
                if (scene_ptr->p1n1.actived_end)
                {
                    scene_ptr->stg = strategy::r_plus_l;
                }
                if (scene_ptr->p1n2.actived_end)
                {
                    scene_ptr->stg = strategy::r_plus_r;
                }
            }
        }
        
        // update numbers
        scene_ptr->cpc_ptr->update(scene_ptr->stg);
        printf("Btn Up! Stg: %d\n", (int)scene_ptr->stg);
        // change player
        if (scene_ptr->cpc_ptr->cur_player == 1 && scene_ptr->stg != strategy::idel)
        {
            scene_ptr->cpc_ptr->cur_player = 2;
        }
        else if (scene_ptr->cpc_ptr->cur_player == 2 && scene_ptr->stg != strategy::idel)
        {
            scene_ptr->cpc_ptr->cur_player = 1;
        }

        scene_ptr->stg = strategy::idel;

        
    }
    
}

void on_mouse_move(int x, int y)
{
    if (!scene_ptr)
        return;
    scene_ptr->pos_line_end_x = x;
    scene_ptr->pos_line_end_y = scene_ptr->wnd_h - y;
    //printf("Moving!\n");
    scene_ptr->p1n1.actived_end = is_point_in_rect(scene_ptr->pos_line_end_x, scene_ptr->pos_line_end_y,
                                                   scene_ptr->p1n1.x1, scene_ptr->p1n1.y1, scene_ptr->p1n1.x2, scene_ptr->p1n1.y2) &&
                                  !is_point_in_rect(scene_ptr->pos_line_beg_x, scene_ptr->pos_line_beg_y,
                                                    scene_ptr->p1n1.x1, scene_ptr->p1n1.y1, scene_ptr->p1n1.x2, scene_ptr->p1n1.y2) &&
                                  !scene_ptr->p1n2.actived_beg && scene_ptr->cpc_ptr->cur_player == 2 &&
                                  (scene_ptr->p2n1.actived_beg || scene_ptr->p2n2.actived_beg);

    scene_ptr->p1n2.actived_end = is_point_in_rect(scene_ptr->pos_line_end_x, scene_ptr->pos_line_end_y,
                                                   scene_ptr->p1n2.x1, scene_ptr->p1n2.y1, scene_ptr->p1n2.x2, scene_ptr->p1n2.y2) &&
                                  !is_point_in_rect(scene_ptr->pos_line_beg_x, scene_ptr->pos_line_beg_y,
                                                    scene_ptr->p1n2.x1, scene_ptr->p1n2.y1, scene_ptr->p1n2.x2, scene_ptr->p1n2.y2) &&
                                  !scene_ptr->p1n1.actived_beg && scene_ptr->cpc_ptr->cur_player == 2 &&
                                  (scene_ptr->p2n1.actived_beg || scene_ptr->p2n2.actived_beg);

    scene_ptr->p2n1.actived_end = is_point_in_rect(scene_ptr->pos_line_end_x, scene_ptr->pos_line_end_y,
                                                   scene_ptr->p2n1.x1, scene_ptr->p2n1.y1, scene_ptr->p2n1.x2, scene_ptr->p2n1.y2) &&
                                  !is_point_in_rect(scene_ptr->pos_line_beg_x, scene_ptr->pos_line_beg_y,
                                                    scene_ptr->p2n1.x1, scene_ptr->p2n1.y1, scene_ptr->p2n1.x2, scene_ptr->p2n1.y2) &&
                                  !scene_ptr->p2n2.actived_beg && scene_ptr->cpc_ptr->cur_player == 1 &&
                                  (scene_ptr->p1n1.actived_beg || scene_ptr->p1n2.actived_beg);

    scene_ptr->p2n2.actived_end = is_point_in_rect(scene_ptr->pos_line_end_x, scene_ptr->pos_line_end_y,
                                                   scene_ptr->p2n2.x1, scene_ptr->p2n2.y1, scene_ptr->p2n2.x2, scene_ptr->p2n2.y2) &&
                                  !is_point_in_rect(scene_ptr->pos_line_beg_x, scene_ptr->pos_line_beg_y,
                                                    scene_ptr->p2n2.x1, scene_ptr->p2n2.y1, scene_ptr->p2n2.x2, scene_ptr->p2n2.y2) &&
                                  !scene_ptr->p2n1.actived_beg && scene_ptr->cpc_ptr->cur_player == 1 &&
                                  (scene_ptr->p1n1.actived_beg || scene_ptr->p1n2.actived_beg);
}

// Size Change Function
void on_size_change(int w, int h)
{
    if (!scene_ptr)
        return;
    scene_ptr->wnd_w = w;
    scene_ptr->wnd_h = h;
    scene_ptr->calc_size();
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,scene_ptr->wnd_w,0.0,scene_ptr->wnd_h);
    glViewport(0, 0, w, h);
}

// Assistent Functions
void begin_text()
{
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(0.0, glutGet(GLUT_WINDOW_WIDTH),
    0.0, glutGet(GLUT_WINDOW_HEIGHT), -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
}

void end_text()
{
    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
}

void draw_text(GLint x, GLint y, char *s, GLfloat r, GLfloat g, GLfloat b, void *font)
{
    int lines;
    char* p;
    
    glColor3f(r,g,b);
    glRasterPos2i(x, y);
    for(p = s, lines = 0; *p; p++) 
    {
        if (*p == '\n') 
        {
            lines++;
            glRasterPos2i(x, y-(lines*24));
        }
        glutBitmapCharacter(font, *p);
    }
}