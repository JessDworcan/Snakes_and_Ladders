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
}
board::board(int size, int snakes, int ladders)
{
    board::board_size = size;
    board::num_snakes = snakes;
    board::num_ladders = ladders;
}

void board::create_board(int size, string binary_equivalent)
{
    set_board_size(size);
    for (int i = 0; i < binary_equivalent.size(); i++)
    {
        if (binary_equivalent[i]=='0')
        {
            int x = get_num_snakes();
            x++;
            set_num_snakes(x);
        }
        else
        {
            int x = get_num_ladders();
            x++;
            set_num_ladders(x);
        }
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

const vector<int> &board::getLadderPos() const {
    return ladder_pos;
}

void board::setLadderPos(const vector<int> &ladderPos) {
    ladder_pos = ladderPos;
}

const vector<int> &board::getLadderLength() const {
    return ladder_length;
}

void board::setLadderLength(const vector<int> &ladderLength) {
    ladder_length = ladderLength;
}

const vector<int> &board::getSnakePos() const {
    return snake_pos;
}

void board::setSnakePos(const vector<int> &snakePos) {
    snake_pos = snakePos;
}

const vector<int> &board::getSnakeLength() const {
    return snake_length;
}

void board::setSnakeLength(const vector<int> &snakeLength) {
    snake_length = snakeLength;
}