// <1924564>
// Snakes and Ladders
// Jess Dworcan

#include <iostream>
#include <fstream>
#include <sstream>
#include "board.h"
#include "game.h"

using namespace std;

int main() {

    ifstream in_file("input.txt");
    ofstream out_file("results.txt");

    int board_size, players;
    string student_number;
    string binary_equivalent;

    in_file >> board_size >> players >> student_number >> binary_equivalent;

    board new_board(board_size, binary_equivalent);
    char s_or_l;
    int start_pos, length;
    char hyphen;

    for (int i = 0; i < new_board.get_num_snakes()+new_board.get_num_ladders(); ++i)
    {
        in_file >> s_or_l >> start_pos >> hyphen >> length;
        cout << s_or_l << " " << start_pos << hyphen << length << endl;

        if (s_or_l == 'S')
        {
            new_board.add_snake(start_pos-1, length);
        }
        else
        {
            new_board.add_ladder(start_pos-1, length);
        }
    }


    game new_game(players);

    out_file << board_size << players << student_number << binary_equivalent;

    for (int i = 0; i < board_size; ++i) {
        cout << new_board.check_position(i) << " ";
    }

    while(new_game.is_game_won()==0)
    {
        int round;
        for (int i = 0; i < players; ++i)
        {

        }
        round = new_game.get_round();

        new_game.inc_round();
        new_game.set_game_won();
    }



    return 0;
}
