// <1924564>
// Snakes and Ladders
// Jess Dworcan

#include <iostream>
#include <fstream>
#include "board.h"

using namespace std;

int main() {

    ifstream in_file("input.txt");
    ofstream out_file("out.txt");


    int board_size, players;
    string student_number;
    string binary_equivalent;


    in_file >> board_size >> players >> student_number >> binary_equivalent;

    board new_board(board_size, binary_equivalent);

    for (int i = 0; i < new_board.get_num_snakes()+new_board.get_num_ladders(); ++i) {
        char s_or_l;
        int start_pos, length;
        char hyphen = '-';
        in_file >> s_or_l >> start_pos >> hyphen >> length;

        if (s_or_l == 'S')
        {
            new_board.add_snake(start_pos, length);
        }
    }

    return 0;
}
