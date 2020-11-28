#include "utility.h"

int rand4()
{
    return rand() % 4;
}

bool is_point_in_rect(int point_x, int point_y, int rect_x1, int rect_y1, int rect_x2, int rect_y2)
{
    if (point_x >= rect_x1 && point_x <= rect_x2 &&
    point_y >= rect_y1 && point_y <= rect_y2)
        return true;
    return false;
}