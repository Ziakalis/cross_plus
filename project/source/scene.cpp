#include "scene.h"

scene::scene(int w, int h)
{
    cpc_ptr = new cross_plus_core();
    wnd_w = w;
    wnd_h = h;

    is_mouse_btn_down = false;
    
    p1n1.actived = false;
    p1n2.actived = false;
    p2n1.actived = false;
    p2n2.actived = false;

    calc_size();
}

scene::~scene()
{
    delete cpc_ptr;
}

void scene::calc_size()
{
    size_num_w = wnd_w / 8;
    size_num_h = wnd_h / 5;

    pos_player1_num1_x = wnd_w / 3 - size_num_w / 2;
    pos_player1_num1_y = wnd_h / 3 - size_num_h / 2;
    pos_player1_num2_x = 2 * wnd_w / 3 - size_num_w / 2;
    pos_player1_num2_y = wnd_h / 3 - size_num_h / 2;

    pos_player2_num1_x = wnd_w / 3 - size_num_w / 2;
    pos_player2_num1_y = 2 * wnd_h / 3 - size_num_h / 2;
    pos_player2_num2_x = 2 * wnd_w / 3 - size_num_w / 2;
    pos_player2_num2_y = 2 * wnd_h / 3 - size_num_h / 2;

    pos_line_beg_x = 0;
    pos_line_beg_y = 0;
    pos_line_end_x = 0;
    pos_line_end_y = 0;

    p1n1.x1 = pos_player1_num1_x;
    p1n1.y1 = pos_player1_num1_y;
    p1n1.x2 = pos_player1_num1_x + size_num_w;
    p1n1.y2 = pos_player1_num1_y + size_num_h;

    p1n2.x1 = pos_player1_num2_x;
    p1n2.y1 = pos_player1_num2_y;
    p1n2.x2 = pos_player1_num2_x + size_num_w;
    p1n2.y2 = pos_player1_num2_y + size_num_h;

    p2n1.x1 = pos_player2_num1_x;
    p2n1.y1 = pos_player2_num1_y;
    p2n1.x2 = pos_player2_num1_x + size_num_w;
    p2n1.y2 = pos_player2_num1_y + size_num_h;

    p2n2.x1 = pos_player2_num2_x;
    p2n2.y1 = pos_player2_num2_y;
    p2n2.x2 = pos_player2_num2_x + size_num_w;
    p2n2.y2 = pos_player2_num2_y + size_num_h;
}