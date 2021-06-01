//
// Created by dworcanj on 31/05/2021.
//

#include <string>
#include "board.h"

using namespace std;

board::board()
{
    board::board_size = 0;
    board::num_snakes = 0;
    board::num_ladders = 0;
    board::positions = {};
}

board::board(int size, string binary_equivalent) {
    int snakes = 0, ladders = 0;
    for (int i = 0; i < binary_equivalent.size(); i++)
    {
        if (binary_equivalent[i]=='0')
        {
            snakes++;
        }
        else
        {
            ladders++;
        }
    }
    board::board_size = size;
    board::num_snakes = snakes;
    board::num_ladders = ladders;
    for (int i =0 ; i<size; i++)
    {
        board::positions.push_back(0);
    }
}

int board::get_board_size()
{
    return board::board_size;
}

int board::get_num_ladders()
{
    return board::num_ladders;
}

int board::get_num_snakes()
{
    return board::num_snakes;
}

void board::set_board_size(int size)
{
    board::board_size = size;
}

void board::set_num_ladders(int ladders)
{
    board::num_ladders = ladders;
}

void board::set_num_snakes(int snakes)
{
    board::num_snakes = snakes;
}

void board::add_snake(int position, int length)
{
    board::positions[position] = -length;
}

void board::add_ladder(int position, int length)
{
    board::positions[position] = length;
}

int board::check_position(int position)
{
    int new_pos;
    new_pos = board::positions[position];
    return new_pos ; // 0 is returned then the play has not reached a snake or ladder
}

