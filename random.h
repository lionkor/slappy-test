#ifndef RANDOM_H
#define RANDOM_H

#include <random>

int randomGen(int minDistrib, int maxDistrib) {

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(minDistrib, maxDistrib); // Here is where you can change the MIN and MAX values of the random dib.

    int randResult = distrib(gen);
    return randResult;
}

#endif // RANDOM_H