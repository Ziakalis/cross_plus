#pragma once
#include "cross_plus_core.h"
#include "utility.h"

struct rect
{
    int x1, x2, y1, y2;
    int xc, yc;
    bool actived_beg;
    bool actived_end;
};

class scene
{
public:
    /* data */
    cross_plus_core *cpc_ptr;
    int wnd_w, wnd_h;

    int size_num_w, size_num_h;
    int pos_player1_num1_x, pos_player1_num1_y;
    int pos_player1_num2_x, pos_player1_num2_y;
    int pos_player2_num1_x, pos_player2_num1_y;
    int pos_player2_num2_x, pos_player2_num2_y;

    bool is_mouse_btn_down;
    int pos_line_beg_x, pos_line_beg_y;
    int pos_line_end_x, pos_line_end_y;

    rect p1n1, p1n2, p2n1, p2n2;
    strategy stg;

public:
    scene(int w, int h);
    ~scene();
    void calc_size();
    void render();
    void mouse_btn_down(int x, int y);
    void mouse_btn_up(int x, int y);
};
