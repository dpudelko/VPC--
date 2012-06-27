#ifndef KRUSKALMINIMUMSPANNINGTREE_H_
#define KRUSKALMINIMUMSPANNINGTREE_H_

#include <map>
#include <set>
#include <iostream>
#include <typeinfo>
#include <stdexcept>
#include <algorithm>
#include "AbstractGraph.h"
#include "EdgeFactory.h"
#include "EdgeSetFactory.h"
#include "Graphs.h"						// memo fuer mittwochBei uns heißt die headder Graph.h ohne s!!-->???? mit s gibts auch! welche?
#include "IntrusiveEdge.h"
#include "UndirectedGraph.h"
#include "WeightedGraph.h"
#include "UnionFind.h"



/**
 * An implementation of <a
 * href="http://en.wikipedia.org/wiki/Kruskal's_algorithm">Kruskal's minimum
 * spanning tree algorithm</a>. If the given graph is connected it computes the
 * minimum spanning tree, otherwise it computes the minimum spanning forest. The
 * algorithm runs in time O(E log E). This implementation uses the hashCode and
 * equals method of the vertices.
 *
 * @author Daniel Weber
 * @since 2012-06-21
 */

template <class V, class E>

class KruskalMinimumSpanningTree
{
    //~ Instance fields --------------------------------------------------------

private:
	double spanningTreeCost;
    set<E*>* edgeList;

    //~ Constructors -----------------------------------------------------------

    /**
     * Creates and executes a new KruskalMinimumSpanningTree algorithm instance.
     * An instance is only good for a single spanning tree; after construction,
     * it can be accessed to retrieve information about the spanning tree found.
     *
     * @param graph the graph to be searched
     */
public:
    KruskalMinimumSpanningTree(Graph graph)
    {
        UnionFind<V> forest = new UnionFind<V>(graph->vertexSet());
        set<E*>* allEdges = graph->edgeSet();
        sort(allEdges->begin(),allEdges->end());[](E edge1, E edge2)->bool{

        	return graph->getEdgeWeight(edge1)<graph->getEdgeWeight(edge2);
        };


        spanningTreeCost = 0;
        set<E*>* edgeList;

        for (E edge : allEdges) {
            V source = graph->getEdgeSource(edge);
            V target = graph->getEdgeTarget(edge);
            if (forest->find(source)->equals(forest->find(target))) {
                continue;
            }

            forest->unionC(source, target);
            edgeList->add(edge);
            spanningTreeCost += graph.getEdgeWeight(edge);
        }
    }

    //~ Methods ----------------------------------------------------------------

    /**
     * Returns the edges making up the tree found.
     *
     * @return Set of Edges
     */
    set<E> getEdgeSet()
    {
        return edgeList;
    }

    /**
     * Returns the cost of the minimum spanning tree or forest.
     *
     * @return Cost of the spanning tree
     */
    double getSpanningTreeCost()
    {
        return spanningTreeCost;
    }
};


#endif /* KRUSKALMINIMUMSPANNINGTREE_H_ */
