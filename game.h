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
    game(int num_players);
    int roll_die();
    void change_player_pos(int player, int moves, int size);
    int get_player_pos(int player);

    int is_game_won();
    int get_round();

    void set_game_won();

    void inc_round();

private:
    vector <int> players; //vector containing player position
    int round;
    int game_won;

};


#endif //SNAKES_AND_LADDERS_GAME_H
