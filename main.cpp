// <1924564>
// Snakes and Ladders
// Jess Dworcan

#include <iostream>
#include <fstream>
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

    game new_game(players, board_size);

    out_file << " " << board_size << " " << players << " " << student_number << " " << binary_equivalent << endl;

    for (int i = 0; i < board_size; ++i) {
        cout << new_board.check_position(i) << " ";
    }
    cout << endl;

    while(!new_game.is_game_won())
    {
        int round;
        for (int player = 0; player < players; ++player)
        {
            new_game.take_turn(player);
            int new_pos = new_game.get_player_pos(player);
            out_file << "R-" << new_game.get_round() << " P-" << player + 1 << " D-" << new_game.get_last_roll() << " M-" << new_pos << endl;

            int is_snake_or_ladder = new_board.check_position(new_game.get_player_pos(player));
            if(is_snake_or_ladder > 0 )
            {
                cout << "A ladder was reached" << endl;
                new_game.change_player_pos(player, is_snake_or_ladder, board_size);
                out_file << "R-" << new_game.get_round() << " P-" << player + 1 << " L-" << new_pos << " M-" << new_game.get_player_pos(player) << endl;
            }
            else if (is_snake_or_ladder < 0)
            {
                cout << "A snake was reached" << endl;
                new_game.change_player_pos(player, is_snake_or_ladder, board_size);
                out_file << "R-" << new_game.get_round() << " P-" << player + 1 << " S-" << new_pos << " M-" << new_game.get_player_pos(player) << endl;
            }
        }
        round = new_game.get_round();

        new_game.inc_round();
    }
    int winner = new_game.get_winner()+1;
    out_file << "wP-" << winner << endl;



    return 0;
}


