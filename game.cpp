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
    game::game_won = 0;
}

game::game(int num_players)
{
    srand (time(0));
    for (int i = 0; i < num_players; ++i) {
        game::players.push_back(0);
    }
    game::round = 0;
    game::game_won = 0;
}

int game::roll_die()
{
    int roll;
    return  roll = rand() % 6 + 1;
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
    game::game_won = 1;
}

int game::get_player_pos(int player)
{
    return game::players[player];
}

int game::is_game_won()
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