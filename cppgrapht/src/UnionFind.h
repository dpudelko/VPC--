#ifndef UNIONFIND_H_
#define UNIONFIND_H_

#include <map>
#include <set>
#include <stdexcept>
#include <typeinfo>
#include <AbstractGraph.h>
#include <EdgeFactory.h>
#include <EdgeSetFactory.h>
#include <Graphs.h>
#include <IntrusiveEdge.h>
#include <UndirectedGraph.h>
#include <WeightedGraph.h>


/**
 * An implementation of <a
 * href="http://en.wikipedia.org/wiki/Disjoint-set_data_structure">Union
 * Find</a> data structure. Union Find is a disjoint-set data structure. It
 * supports two operations: finding the set a specific element is in, and
 * merging two sets. The implementation uses union by rank and path compression
 * to achieve an amortized cost of O(a(n)) per operation where a is the inverse
 * Ackermann function. UnionFind uses the hashCode and equals method of the
 * elements it operates on.
 *
 * @author Daniel Weber
 * @since 2012-06-21
 */
template <class T>
class UnionFind
{
    //~ Instance fields --------------------------------------------------------

private:
	set<T*, T*>* parentMap;
    set<T*, int*>* rankMap;

    //~ Constructors -----------------------------------------------------------

    /**
     * Creates a UnionFind instance with all of the elements of elements in
     * seperate sets.
     */
public:
    UnionFind(set<T*>* elements)
    {
        for (T* element : elements) {
            parentMap->put(element, element);
            rankMap->put(element, 0);
        }
    }

    //~ Methods ----------------------------------------------------------------

    /**
     * Adds a new element to the data structure in its own set.
     *
     * @param element The element to add.
     */
    void addElement(T* element)
    {
        parentMap->put(element, element);
        rankMap->put(element, 0);
    }

    /**
     * @return map from element to parent element
     */
    map<T*, T*>* getParentMap()
    {
        return parentMap;
    }

    /**
     * @return map from element to rank
     */
    map<T*, int*>* getRankMap()
    {
        return rankMap;
    }

    /**
     * Returns the representative element of the set that element is in.
     *
     * @param element The element to find.
     *
     * @return The element representing the set the element is in.
     */
     T* find(T* element)
    {
        if (!parentMap->containsKey(element)) {
            throw new IllegalArgumentException(
                "elements must be contained in given set");
        }

        T* parent = parentMap->get(element);
        if (parent->equals(element)) {
            return element;
        }

        T* newParent = find(parent);
        parentMap->put(element, newParent);
        return newParent;
    }

    /**
     * Merges the sets which contain element1 and element2.
     *
     * @param element1 The first element to unionC.
     * @param element2 The second element to unionC.
     */
    void unionC(T* element1, T* element2)
    {
        if (!parentMap->containsKey(element1)
            || !parentMap->containsKey(element2))
        {
            throw new IllegalArgumentException(
                "elements must be contained in given set");
        }

        T* parent1 = find(element1);
        T* parent2 = find(element2);

        //check if the elements are already in the same set
        if (parent1->equals(parent2)) {
            return;
        }

        int rank1 = rankMap->get(parent1);
        int rank2 = rankMap->get(parent2);
        if (rank1 > rank2) {
            parentMap->put(parent2, parent1);
        } else if (rank1 < rank2) {
            parentMap->put(parent1, parent2);
        } else {
            parentMap->put(parent2, parent1);
            rankMap->put(parent1, rank1 + 1);
        }
    }
};




#endif /* UNIONFIND_H_ */
