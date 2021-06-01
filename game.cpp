//
// Created by dworcanj on 01/06/2021.
//

#include <cstdlib>
#include <ctime>
#include "game.h"

game::game()
{
    srand (time(0));
    game::players = {};
    game::round = 0;
    game::game_won = false;
    game::current_roll = 0;
}

game::game(int num_players, int board_size)
{
    srand (time(0));
    for (int i = 0; i < num_players; ++i) {
        game::players.push_back(0);
    }
    game::round = 0;
    game::game_won = false;
    game::current_roll = 0;
    game::board_size = board_size;
}

void game::take_turn(int player)
{
    game::current_roll = rand() % 6 + 1;
    change_player_pos(player, game::current_roll, game::board_size);
}

void game::change_player_pos(int player, int moves, int size)
{
    int current = game::players[player];
    //only move a player if the moves falls on or below the final board position i.e the board size
    if( ( current += moves) <= size)
    {
        game::players[player] += moves;
        if (game::players[player] == size)
        {
            game::game_won = 1;
        }
    }
}

void game::set_game_won()
{
    game::game_won = true;
}

int game::get_player_pos(int player)
{
    return game::players[player];
}

bool game::is_game_won()
{
    return game::game_won;
}

int game::get_round()
{
    return game::round;
}

void game::inc_round()
{
    game::round++;
}

int game::get_winner() {
    for (int i = 0; i < game::players.size(); ++i) {
        if (game::players[i]==100)
        {
            return i;
        }
    }
    return -1;
}

int game::get_last_roll() {
    return game::current_roll;
}
