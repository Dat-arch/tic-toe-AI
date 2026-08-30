#include "Library.h"
#include "random.cpp"

bool isWinningMove(string* board, int move, const string& mark){
    string previous = board[move];
    board[move] = mark;

    const int lines[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8},
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8},
        {0, 4, 8}, {2, 4, 6}
    };

    bool wins = false;
    for (const auto& line : lines){
        if (board[line[0]] == mark && board[line[1]] == mark && board[line[2]] == mark){
            wins = true;
            break;
        }
    }

    board[move] = previous;
    return wins;
}

int AI(string* board){
    for (int move = 0; move < 9; ++move){
        if (board[move] == "." && isWinningMove(board, move, "x")){
            return move;
        }
    }

    for (int move = 0; move < 9; ++move){
        if (board[move] == "." && isWinningMove(board, move, "o")){
            return move;
        }
    }

    if (board[4] == "."){
        return 4;
    }

    int move = random();
    while (board[move] != "."){
        move = random();
    }
    return move;
}