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

    board new_board;

    in_file >> board_size >> players >> student_number >> binary_equivalent;

    new_board.create_board(board_size, binary_equivalent);

    

    return 0;
}
