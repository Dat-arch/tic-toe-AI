#include "Library.h"

int random(){
    random_device rd;

    mt19937 gen(rd());

    uniform_int_distribution<> dis(0,8);

    return dis(gen);
}

int randomConner(){
    random_device rd;

    mt19937 gen(rd());

    uniform_int_distribution<> dis(0,3);

    return dis(gen);
}