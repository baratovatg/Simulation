#include "field.h"

enum direction {UP, RIGHT, DOWN, LEFT};

Field::Field(unsigned int size)
{
//    srand(time(0));
    size_ = size;
    field_ = new type* [size_];
    for(unsigned int i = 0; i < size_; ++i) {
        field_[i] = new type [size_];
    }
    //Наполняем поле травой
    for(unsigned int i = 0; i < size_; ++i) {
        for(unsigned int j = 0; j < size_; ++j) {
            field_[i][j] = static_cast<type>(rand()%3);
        }
    }

//    for(unsigned int i = 0; i < numOfRabbits; ++i) {
//        bool smthHere = false;
//        int x;
//        int y;
//        do {
//            x = rand()%size_;
//            y = rand()%size_;
//            if((field_[x][y] != tree)) {
//                for(const auto &rabbit : rabbits_) {
//                    if((rabbit.getX() == x) && (rabbit.getY() == y)) {
//                        smthHere = true;
//                    }
//                }
//            }
//        } while(smthHere);
//        rabbits_.push_back(Rabbit(x, y));
//    }
}

void Field::genTrees(int percent) {
    for(unsigned int i = 0; i < ((size_*size_) * percent / 100); ++i) {
        field_[rand()%size_][rand()%size_] = tree;
    }
}

void Field::genRabbits(unsigned int num) {
    for(unsigned int i = 0; i < num; ++i) {
        int a = rand()%size_;
        int b = rand()%size_;
        if(field_[a][b] != tree) {
            field_[a][b] = rabbit;
        }
        else {
            i--;
        }
    }
}

void Field::draw() {
    for(unsigned int i = 0; i < size_; ++i) {
        for(unsigned int j = 0; j < size_; ++j) {
                    switch(field_[i][j]) {
                    case empty:
                        std::cout << "░░";
                        break;
                    case little_grass:
                        std::cout << "▒▒";
                        break;
                    case adult_grass:
                        std::cout << "▓▓";
                        break;
                    case tree:
                        std::cout << "  ";
                        break;
                    case rabbit:
                        std::cout << "Rb";
                        break;
                    default:
                        break;
                    }
            }
        std::cout << std::endl;
    }
}

void Field::changeState() {
    for(unsigned int i = 0; i < size_; ++i) {
        for(unsigned int j = 0; j < size_; ++j) {
            if(field_[i][j] == rabbit) {
                moveRabbit(i, j);
            }
            else if((field_[i][j] == adult_grass) || (field_[i][j] == rabbit)) {
                field_[i][j] = empty;
            }
            else if(field_[i][j] != tree) {
                field_[i][j] = static_cast<type>(field_[i][j] + 1);
            }
        }
    }
}

void Field::moveRabbit(int x, int y) {
    field_[x][y] = empty;
    bool smthHere = true;
    do {
        direction where = static_cast<direction>(rand()%4);
        switch(where) {
            case UP:
                y--;
                break;
            case RIGHT:
                x++;
                break;
            case LEFT:
                x--;
                break;
            case DOWN:
                y++;
                break;
        }
        if((x >= 0) && (x <= (size_ - 1)) && (y >= 0) && (y <= (size_ - 1))) {
            if((field_[x][y] != tree) && (field_[x][y] != rabbit)) {
                field_[x][y] = rabbit;
                smthHere = false;
            }
        }
    } while (smthHere);
}


