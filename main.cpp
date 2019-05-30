#include <iostream>
#include <unistd.h>
#include "typeofterrain.h"
#include "field.h"

int main()
{
    unsigned int size;
    unsigned int numOfRabbits;
    std::cout << "Введите размеры поля: ";
    std::cin >> size;
    std::cout << "Введите количество кроликов: ";
    std::cin >> numOfRabbits;
    Field simField(size);
    simField.genTrees(10);
    simField.genRabbits(numOfRabbits);
    while(true) {
        printf("\e[1;1H\e[2J"); //Вместо очистки экрана
        simField.draw();
        simField.changeState();
        sleep(2);
    }
}

