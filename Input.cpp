#include "Library.h"

void input(int position, string* ptr){
    if (position >=1 && position <= 9){
        string* Newptr = ptr + position - 1;
        *Newptr = "o";
    }

    else {
        cout <<"1-9";
    }
}

void inputAI(int position, string* ptr){
        string* Newptr = ptr + position - 1;
        *Newptr = "x";
}
