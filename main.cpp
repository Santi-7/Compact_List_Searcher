/* ---------------------------------------------------------------------------
** main.cpp
**
**
** Author: Santiago Gil Begué, NIA: 683482
** -------------------------------------------------------------------------*/

#include <compactList.hpp>
#include <iostream>
#include <stdlib.h>

using namespace std;

static constexpr unsigned int SIZE = 10000;
static constexpr unsigned int LOOPS = 1000;

int main()
{
    // Initialize random seed.
    srand(time(NULL));

    CompactList list(SIZE);
    int totalRandimizedSteps = 0, totalLinealSteps = 0;
    clock_t randomized = 0, lineal = 0;
    for (int i = 0; i < LOOPS; i++) {
        int steps;
        // Element to search;
        int element = rand() % SIZE + 1;
        // Randomized Search.
        clock_t begin = clock();
        int index = list.RandomizedSearch(element, steps);
        clock_t end = clock();
        if (list[index] != element) {
            cout << "Randomized Search has failed.";
            return 1;
        }
        totalRandimizedSteps += steps;
        randomized += end - begin;
        // Lineal Search;
        begin = clock();
        index = list.LinealSearch(element);
        end = clock();
        if (list[index] != element) {
            cout << "Lineal Search has failed.";
            return 1;
        }
        totalLinealSteps += element;
        lineal += end - begin;
    }
    cout << "Randomized algorithm has cost an average time of " <<
         randomized * 1000.0 / LOOPS / CLOCKS_PER_SEC << "ms " <<
         "and an average number of steps of " <<
         static_cast<float>(totalRandimizedSteps) / LOOPS << endl;
    cout << "Lineal algorithm has cost an average time of " <<
         lineal * 1000.0 / LOOPS / CLOCKS_PER_SEC << "ms " <<
         "and an average number of steps of " <<
         static_cast<float>(totalLinealSteps) / LOOPS << endl;
}