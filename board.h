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
    board(int size, int snakes, int ladders);
    void create_board(int size, string binary_equivalent);
    int get_board_size();
    void set_board_size(int size);
    int get_num_snakes();
    void set_num_snakes(int snakes);
    int get_num_ladders();
    void set_num_ladders(int ladders);

    const vector<int> &getLadderPos() const;

    void setLadderPos(const vector<int> &ladderPos);

    const vector<int> &getLadderLength() const;

    void setLadderLength(const vector<int> &ladderLength);

    const vector<int> &getSnakePos() const;

    void setSnakePos(const vector<int> &snakePos);

    const vector<int> &getSnakeLength() const;

    void setSnakeLength(const vector<int> &snakeLength);


private:
    int board_size;
    int num_snakes;
    int num_ladders;
    vector <int> ladder_pos;
    vector <int> ladder_length;
    vector <int> snake_pos;
    vector <int> snake_length;
};


#endif //SNAKES_AND_LADDERS_BOARD_H
