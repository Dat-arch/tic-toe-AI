#include "Library.h"
#include "PrintBoard.cpp"
#include "Input.cpp"
#include "AICore.cpp"

bool hasWon(string* board, const string& mark){
    const int lines[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8},
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8},
        {0, 4, 8}, {2, 4, 6}
    };

    for (const auto& line : lines){
        if (board[line[0]] == mark && board[line[1]] == mark && board[line[2]] == mark){
            return true;
        }
    }
    return false;
}

bool boardIsFull(string* board){
    for (int position = 0; position < 9; ++position){
        if (board[position] == "."){
            return false;
        }
    }
    return true;
}

int main(){
    string pointer[] = {".",".",".",".",".",".",".",".","."};

    string* ptr = pointer;
    
    cout << "1-9" << endl;
    printResult(pointer[0],pointer[1],pointer[2],pointer[3],pointer[4],pointer[5],pointer[6],pointer[7],pointer[8]);

    while (true){
        int position;
        cin >> position;

        if (!cin || position < 1 || position > 9 || pointer[position - 1] != "."){
            cout << "Choose a hole 1-9" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        pointer[position - 1] = "o";
        printResult(pointer[0],pointer[1],pointer[2],pointer[3],pointer[4],pointer[5],pointer[6],pointer[7],pointer[8]);

        if (hasWon(ptr, "o")){
            cout << "Just lucky!" << endl;
            break;
        }
        if (boardIsFull(ptr)){
            cout << "Draw!" << endl;
            break;
        }

        int aiMove = AI(ptr);
        pointer[aiMove] = "x";
        cout << "-------"<<endl;

        printResult(pointer[0],pointer[1],pointer[2],pointer[3],pointer[4],pointer[5],pointer[6],pointer[7],pointer[8]);

        if (hasWon(ptr, "x")){
            cout << "Chicken!" << endl;
            break;
        }
        if (boardIsFull(ptr)){
            cout << "Draw!" << endl;
            break;
        }
    }
    system("pause");
    return 0;
}