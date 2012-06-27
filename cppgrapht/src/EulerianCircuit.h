/*
 * EulerianCircuit.h
 *
 *  Created on: 23.06.2012
 *      Author: dAda
 */

#ifndef EULERIANCIRCUIT_H_
#define EULERIANCIRCUIT_H_

#include "Graphs.h"

/* ==========================================
 * JGraphT : a free Java graph-theory library
 * ==========================================
 *
 * Project Info:  http://jgrapht.sourceforge.net/
 * Project Creator:  Barak Naveh (http://sourceforge.net/users/barak_naveh)
 *
 * (C) Copyright 2003-2008, by Barak Naveh and Contributors.
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
/* -------------------
 * EulerianCircuit.java
 * -------------------
 * (C) Copyright 2008-2008, by Andrew Newell and Contributors.
 *
 * Original Author:  Andrew Newell
 * Contributor(s):   -
 *
 * $Id: EulerianCircuit.java 651 2008-12-24 21:13:41Z perfecthash $
 *
 * Changes
 * -------
 * 24-Dec-2008 : Initial revision (AN);
 *
 */

/**
 * This algorithm will check whether a graph is Eulerian (hence it contains an
 * <a href="http://mathworld.wolfram.com/EulerianCircuit.html">Eulerian
 * circuit</a>). Also, if a graph is Eulerian, the caller can obtain a list of
 * vertices making up the Eulerian circuit. An Eulerian circuit is a circuit
 * which traverses each edge exactly once.
 *
 * @author Andrew Newell
 * @since Dec 21, 2008
 */
template <class V, class E>

class EulerianCircuit
{
    //~ Methods ----------------------------------------------------------------

    /**
     * This method will check whether the graph passed in is Eulerian or not.
     *
     * @param g The graph to be checked
     *
     * @return true for Eulerian and false for non-Eulerian
     */
public:
	static bool isEulerian(Graph<V, E> g)
    {
        // If the graph is not connected, then no Eulerian circuit exists
        /*if (!(new ConnectivityInspector<V, E>(g)).isGraphConnected()) {
            return false;
        }*/

        // A graph is Eulerian if and only if all vertices have even degree
        // So, this code will check for that
		set<V> vertices = g.vertexSet();
		typename set<V>::iterator it;
        it = vertices.begin();
        while (it != vertices.end()) {
            V v = *it;
            if ((g.degreeOf(v) % 2) == 1) {
                return false;
            }
            it++;
        }
        return true;
    }

    /**
     * This method will return a list of vertices which represents the Eulerian
     * circuit of the graph.
     *
     * @param g The graph to find an Eulerian circuit
     *
     * @return null if no Eulerian circuit exists, or a list of vertices
     * representing the Eulerian circuit if one does exist
     */
    static list<V> getEulerianCircuitVertices(
        UndirectedGraph<V, E> g)
    {
        // If the graph is not Eulerian then just return a null since no
        // Eulerian circuit exists
        if (!isEulerian(g)) {
            return 0;
        }

        // The circuit will be represented by a linked list
        list<V> path = new list<V>();
        UndirectedGraph<V, E> sg = new UndirectedSubgraph<V, E>(g, null, null);
        path.add(sg.vertexSet().iterator().next());

        // Algorithm for finding an Eulerian circuit Basically this will find an
        // arbitrary circuit, then it will find another arbitrary circuit until
        // every edge has been traversed
        while (sg.edgeSet().size() > 0) {
            V v = 0;

            // Find a vertex which has an edge that hasn't been traversed yet,
            // and keep its index position in the circuit list
            int index = 0;

            set<V>::iterator it;
            for (it = path.begin(); it != path.end(); it++) {
                v = *it;
                if (sg.degreeOf(v) > 0) {
                    break;
                }
            }

            // Finds an arbitrary circuit of the current vertex and
            // appends this into the circuit list
            set<V>::iterator iter;
            while (sg.degreeOf(v) > 0) {
                for (iter = sg.vertexSet().begin(); iter != sg.vertexSet().end(); it++)
                {
                    V temp = *it;
                    if (sg.containsEdge(v, temp)) {
                        path.add(index, temp);
                        sg.removeEdge(v, temp);
                        v = temp;
                        break;
                    }
                }
            }
        }
        return path;
    }
};

// End EulerianCircuit.h


#endif /* EULERIANCIRCUIT_H_ */
