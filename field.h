#ifndef FIELD_H
#define FIELD_H

#include <ctime>
#include <iostream>
#include "typeofterrain.h"

class Field
{
private:
    unsigned int size_;
    type** field_;
public:
    Field(unsigned int size);
    void genTrees(int percent);
    void draw();
    void genRabbits(unsigned int num);
    void changeState();
    void moveRabbit(int x, int y);
};

#endif // FIELD_H
