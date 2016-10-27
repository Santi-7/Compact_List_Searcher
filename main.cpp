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

int main()
{
    // Initialize random seed.
    srand(time(NULL));

    CompactList list(5);
    int steps;
    int index = list.Search(4, steps);

    cout << list << endl;
    cout << index << endl;
    cout << steps << endl;
}