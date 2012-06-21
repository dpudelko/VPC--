/*
 * KruskalMinimumSpanningTree.h
 *
 *  Created on: 21.06.2012
 *      Author: Daniel Weber
 */

#ifndef KRUSKALMINIMUMSPANNINGTREE_H_
#define KRUSKALMINIMUMSPANNINGTREE_H_

#include <map>
#include <set>
#include <iostream>
#include <typeinfo>
#include <stdexcept>
#include <algorithm>
#include <AbstractGraph.h>
#include <EdgeFactory.h>
#include <EdgeSetFactory.h>
#include <Graphs.h>
#include <IntrusiveEdge.h>
#include <UndirectedGraph.h>
#include <WeightedGraph.h>
#include <UnionFind.h>

/* ==========================================
 * JGraphT : a free Java graph-theory library
 * ==========================================
 *
 * Project Info:  http://jgrapht.sourceforge.net/
 * Project Creator:  Barak Naveh (http://sourceforge.net/users/barak_naveh)
 *
 * (C) Copyright 2003-2010, by Barak Naveh and Contributors.
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public
 * License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library; if not, write to the Free Software Foundation,
 * Inc.,
 * 59 Temple Place, Suite 330, Boston, MA 02111-1307, USA.
 */
/* -------------------------
 * KruskalMinimumSpanningTree.java
 * -------------------------
 * (C) Copyright 2010-2010, by Tom Conerly and Contributors.
 *
 * Original Author:  Tom Conerly
 * Contributor(s):
 *
 * Changes
 * -------
 * 02-Feb-2010 : Initial revision (TC);
 *
 */



/**
 * An implementation of <a
 * href="http://en.wikipedia.org/wiki/Kruskal's_algorithm">Kruskal's minimum
 * spanning tree algorithm</a>. If the given graph is connected it computes the
 * minimum spanning tree, otherwise it computes the minimum spanning forest. The
 * algorithm runs in time O(E log E). This implementation uses the hashCode and
 * equals method of the vertices.
 *
 * @author Tom Conerly
 * @since Feb 10, 2010
 */

template <class V, class E>

class KruskalMinimumSpanningTree
{
    //~ Instance fields --------------------------------------------------------

private:
	double spanningTreeCost;
    set<E>* edgeList;

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
        }


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
}

// End KruskalMinimumSpanningTree.java



#endif /* KRUSKALMINIMUMSPANNINGTREE_H_ */
