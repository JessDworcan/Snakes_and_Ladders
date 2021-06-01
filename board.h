//
// Created by dworcanj on 31/05/2021.
//

#include <vector>
#ifndef SNAKES_AND_LADDERS_BOARD_H
#define SNAKES_AND_LADDERS_BOARD_H

using namespace std;

class board
{
public:
    board();
    board(int size, string binary_equivalent);
    int get_board_size();
    void set_board_size(int size);
    int get_num_snakes();
    void set_num_snakes(int snakes);
    int get_num_ladders();
    void set_num_ladders(int ladders);

    int check_position(int position);


    void add_snake(int position, int length);

    void add_ladder(int position, int length);

private:
    int board_size;
    int num_snakes;
    int num_ladders;
    vector <int> positions;


};


#endif //SNAKES_AND_LADDERS_BOARD_H
