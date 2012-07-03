#ifndef TRAVERSALLISTENER_H_
#define TRAVERSALLISTENER_H_


//package org.jgrapht.event;
#import"ConnectedComponentTraversalEvent.h";

/**
 * A listener on graph iterator or on a graph traverser.
 *
 * @author Barak Naveh
 * @since Jul 19, 2003
 */
template <class V, class E>
class TraversalListener
{
    //~ Methods ----------------------------------------------------------------

    /**
     * Called to inform listeners that the traversal of the current connected
     * component has finished.
     *
     * @param e the traversal event.
     */
public:
	virtual void connectedComponentFinished(ConnectedComponentTraversalEvent e) = 0;

    /**
     * Called to inform listeners that a traversal of a new connected component
     * has started.
     *
     * @param e the traversal event.
     */
    virtual void connectedComponentStarted(ConnectedComponentTraversalEvent e) = 0;

    /**
     * Called to inform the listener that the specified edge have been visited
     * during the graph traversal. Depending on the traversal algorithm, edge
     * might be visited more than once.
     *
     * @param e the edge traversal event.
     */
    virtual void edgeTraversed(EdgeTraversalEvent<V, E> e) = 0;

    /**
     * Called to inform the listener that the specified vertex have been visited
     * during the graph traversal. Depending on the traversal algorithm, vertex
     * might be visited more than once.
     *
     * @param e the vertex traversal event.
     */

    virtual void vertexTraversed(VertexTraversalEvent<V> e) = 0;

    /**
     * Called to inform the listener that the specified vertex have been
     * finished during the graph traversal. Exact meaning of "finish" is
     * algorithm-dependent; e.g. for DFS, it means that all vertices reachable
     * via the vertex have been visited as well.
     *
     * @param e the vertex traversal event.
     */
   virtual void vertexFinished(VertexTraversalEvent<V> e) = 0;
};

// End TraversalListener.java



#endif /* TRAVERSALLISTENER_H_ */
