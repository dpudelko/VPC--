#ifndef ABSTACTGRAPHITERATOR_H_
#define ABSTACTGRAPHITERATOR_H_

//import java.util.*;
//import org.jgrapht.event.*;
#include "GraphIterator.h";

/**
 * An empty implementation of a graph iterator to minimize the effort required
 * to implement graph iterators.
 */
//using namespace std;

template <class V, class E>
class AbstractGraphIterator : GraphIterator<V, E>
//JAVACODE: public abstract class AbstractGraphIterator<V, E> implements GraphIterator<V, E>

{
    //~ Instance fields --------------------------------------------------------

private:
	List<TraversalListener<V, E>> traversalListeners =
			new ArrayList<TraversalListener<V, E>>();
    boolean crossComponentTraversal = true;
    boolean reuseEvents = false;

    // We keep this cached redundantly with traversalListeners.size()
    // so that subclasses can use it as a fast check to see if
    // event firing calls can be skipped.
protected:
    int nListeners = 0;

    //~ Methods ----------------------------------------------------------------

    /**
     * Sets the cross component traversal flag - indicates whether to traverse
     * the graph across connected components.
     *
     * @param crossComponentTraversal if <code>true</code> traverses across
     * connected components.
     */
public:
    void setCrossComponentTraversal(boolean crossComponentTraversal)
    {
        this.crossComponentTraversal = crossComponentTraversal;
    }

    /**
     * Test whether this iterator is set to traverse the graph across connected
     * components.
     *
     * @return <code>true</code> if traverses across connected components,
     * otherwise <code>false</code>.
     */
    boolean isCrossComponentTraversal()
    {
        return crossComponentTraversal;
    }

    //@see GraphIterator#setReuseEvents(boolean)
    void setReuseEvents(boolean reuseEvents)
    {
        this.reuseEvents = reuseEvents;
    }

    //@see GraphIterator#isReuseEvents()
    boolean isReuseEvents()
    {
        return reuseEvents;
    }


     // Adds the specified traversal listener to this iterator.
     // @param l the traversal listener to be added.
    void addTraversalListener(TraversalListener<V, E> l)
    {
        if (!traversalListeners.contains(l)) {
            traversalListeners.add(l);
            nListeners = traversalListeners.size();
        }
    }


     // Unsupported.
     // @throws UnsupportedOperationException
    void remove()
    {
        throw new UnsupportedOperationException();
    }


     // Removes the specified traversal listener from this iterator.
     // @param l the traversal listener to be removed.
    void removeTraversalListener(TraversalListener<V, E> l)
    {
        traversalListeners.remove(l);
        nListeners = traversalListeners.size();
    }

    // Informs all listeners that the traversal of the current connected component finished.
    // @param e the connected component finished event.
protected:
    void fireConnectedComponentFinished(
        ConnectedComponentTraversalEvent e)
    {
        for (int i = 0; i < nListeners; i++) {
            TraversalListener<V, E> l = traversalListeners.get(i);
            l.connectedComponentFinished(e);
        }
    }

    //Informs all listeners that a traversal of a new connected component has started.
    // @param e the connected component started event.
    void fireConnectedComponentStarted(
        ConnectedComponentTraversalEvent e)
    {
        for (int i = 0; i < nListeners; i++) {
            TraversalListener<V, E> l = traversalListeners.get(i);
            l.connectedComponentStarted(e);
        }
    }

     // Informs all listeners that a the specified edge was visited.
     // @param e the edge traversal event.
    void fireEdgeTraversed(EdgeTraversalEvent<V, E> e)
    {
        for (int i = 0; i < nListeners; i++) {
            TraversalListener<V, E> l = traversalListeners.get(i);
            l.edgeTraversed(e);
        }
    }

    // Informs all listeners that a the specified vertex was visited.
    // @param e the vertex traversal event.
    void fireVertexTraversed(VertexTraversalEvent<V> e)
    {
        for (int i = 0; i < nListeners; i++) {
            TraversalListener<V, E> l = traversalListeners.get(i);
            l.vertexTraversed(e);
        }
    }

     //Informs all listeners that a the specified vertex was finished.
     //@param e the vertex traversal event.
    void fireVertexFinished(VertexTraversalEvent<V> e)
    {
        for (int i = 0; i < nListeners; i++) {
            TraversalListener<V, E> l = traversalListeners.get(i);
            l.vertexFinished(e);
        }
    }
};
#endif
