/* ---------------------------------------------------------------------------
** compactList.cpp
** Source class for a compact list.
**
** Author: Santiago Gil Begué, NIA: 683482
** -------------------------------------------------------------------------*/

#include "compactList.hpp"
#include <list>
#include <stdlib.h>

using namespace std;

CompactList::CompactList(unsigned int size)
{
    mVal.resize(size);
    mPtr.resize(size);
    // Still free positions in the compact list.
    list<int> freePositions;
    for (int i = 0; i < size; i++) {
        freePositions.push_back(i);
    }
    /* Save [1-size] values randomly. */
    // Save the last value.
    unsigned int randomPosition = *next(freePositions.begin(), rand() % size);
    freePositions.remove(randomPosition);
    mVal[randomPosition] = size;
    mPtr[randomPosition] = -1;
    // Save the rest values.
    for (unsigned int i = size-1; i >= 1; i--) {
        unsigned int oldPosition = randomPosition;
        randomPosition = *next(freePositions.begin(), rand() % freePositions.size());
        freePositions.remove(randomPosition);
        mVal[randomPosition] = i;
        mPtr[randomPosition] = oldPosition;
    }
    // The smallest value is the last randomPosition calculated.
    mHead = randomPosition;
}

int CompactList::Search(int number, int &steps)
{
    steps = 0;
    int i = mHead;
    while (mVal[i] < number) {
        steps++;
        int j = rand() % mVal.size();
        if (mVal[i] < mVal[j] & mVal[j] <= number) {
            i = j;
        } else {
            i = mPtr[i];
        }
    }
    return i;
}

std::ostream& operator<<(std::ostream &out, const CompactList &cL)
{
    out << "HEAD = " << cL.mHead << endl;
    out << "VAL(";
    for (int i = 0; i < cL.mVal.size()-1; i++) {
        out << cL.mVal[i] << ", ";
    }
    out << cL.mVal[cL.mVal.size()-1] << ")" << endl;
    out << "PTR(";
    for (int i = 0; i < cL.mPtr.size()-1; i++) {
        out << cL.mPtr[i] << ", ";
    }
    out << cL.mPtr[cL.mPtr.size()-1] << ")" << endl;
    return out;
}