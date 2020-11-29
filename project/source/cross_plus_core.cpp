#include "cross_plus_core.h"

cross_plus_core::cross_plus_core(/* args */)
{
    player1_num1 = 1;
    player1_num2 = 1;
    player2_num1 = 1;
    player2_num2 = 1;
    cur_player = 1;
    winner = 0;
}

cross_plus_core::~cross_plus_core()
{
}

void cross_plus_core::update(strategy stg)
{
    if (cur_player == 1)
    {
        //cur_player = 2;
        switch (stg)
        {
        case l_plus_l:
            player1_num1 += player2_num1;
            break;

        case l_plus_r:
            player1_num1 += player2_num2;
            break;
        
        case r_plus_l:
            player1_num2 += player2_num1;
            break;
        
        case r_plus_r:
            player1_num2 += player2_num2;
            break;
        default:
            break;
        }
    }
    else if (cur_player == 2)
    {
        //cur_player = 1;
        switch (stg)
        {
        case l_plus_l:
            player2_num1 += player1_num1;
            break;
        
        case l_plus_r:
            player2_num1 += player1_num2;
            break;
        
        case r_plus_l:
            player2_num2 += player1_num1;
            break;
        
        case r_plus_r:
            player2_num2 += player1_num2;
            break;
        default:
            break;
        }
    }
    player1_num1 %= 10;
    player1_num2 %= 10;
    player2_num1 %= 10;
    player2_num2 %= 10;
    if (player1_num1 == 9 && player1_num2 == 9)
        winner = 1;
    if (player2_num1 == 9 && player2_num2 == 9)
        winner = 2;
}