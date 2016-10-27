/* ---------------------------------------------------------------------------
** compactList.hpp
** Header class for a compact list.
**
** Author: Santiago Gil Begué, NIA: 683482
** -------------------------------------------------------------------------*/

#ifndef COMPACTLISTSEARCHER_COMPACTLIST_HPP
#define COMPACTLISTSEARCHER_COMPACTLIST_HPP

#include <ostream>
#include <vector>

class CompactList {

public:

    /**
     * Creates a random ordered compact list of size [size] with values 1 to [size].
     *
     * @param size of the ordered compact list.
     * @return a random ordered compact list of size [size] with values 1 to [size].
     */
    CompactList(unsigned int size);

    /**
     * Searchs the number [number] in the compact list and return its position.
     * It also puts into [steps] the number of iterations made.
     *
     * @param number to search.
     * @param steps number of iterations made by this search.
     * @return the position of [number] in the compact list.
     */
    int Search(int number, int &steps);

    /**
     * Overloads << to return an ostream with the representation of the compact list.
     *
     * @param out ostream.
     * @param cL compact list to representate.
     * @return an ostream with the representation of the compact list.
     */
    friend std::ostream& operator<<(std::ostream &out, const CompactList &cL);

private:

    /* Values of the list. */
    std::vector<int> mVal;

    /* Marks the order of the values. */
    std::vector<int> mPtr;

    /* The index of the first value in val. */
    unsigned int mHead;
};

#endif // COMPACTLISTSEARCHER_COMPACTLIST_HPP