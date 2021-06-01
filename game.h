//
// Created by dworcanj on 01/06/2021.
//

#include <vector>

#ifndef SNAKES_AND_LADDERS_GAME_H
#define SNAKES_AND_LADDERS_GAME_H

using namespace std;

class game {
public:
    game();
    game(int num_players, int board_size);
    void take_turn(int player);
    void change_player_pos(int player, int moves, int size);
    int get_player_pos(int player);

    bool is_game_won();
    int get_round();

    void set_game_won();

    void inc_round();

    int get_winner();

    int get_last_roll();

private:
    vector <int> players; //vector containing player position
    int round;
    int game_won;
    int current_roll;
    int board_size;
};


#endif //SNAKES_AND_LADDERS_GAME_H
