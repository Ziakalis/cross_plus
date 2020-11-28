#pragma once
enum strategy
{
    l_plus_l,
    l_plus_r,
    r_plus_l,
    r_plus_r
};

class cross_plus_core
{
public:
    int player1_num1;
    int player1_num2;
    int player2_num1;
    int player2_num2;
    int cur_player;
    int winner;

public:
    cross_plus_core();
    ~cross_plus_core();
    void update(strategy stg);
};
