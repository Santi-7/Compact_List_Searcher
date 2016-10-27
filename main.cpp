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

    cout << CompactList(6);
}