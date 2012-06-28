#ifndef GRAPHITERATOR_H_
#define GRAPHITERATOR_H_

//import java.util.*;
//import org.jgrapht.event.*;


// A graph iterator.

using namespace std;

template <class V, class E>
class GraphIterator : public Iterator<V>{
	//JAVACODE: public interface GraphIterator<V, E> extends Iterator<V>

	//~ Methods ----------------------------------------------------------------

    /**
     * Test whether this iterator is set to traverse the grpah across connected
     * components.
     *
     * @return <code>true</code> if traverses across connected components,
     * otherwise <code>false</code>.
     */
public:
    virtual boolean isCrossComponentTraversal() = 0;
    /**
    * Sets a value the <code>reuseEvents</code> flag. If the <code>
    * reuseEvents</code> flag is set to <code>true</code> this class will reuse
    * previously fired events and will not create a new object for each event.
    * This option increases performance but should be used with care,
    * especially in multithreaded environment.
    *
    * @param reuseEvents whether to reuse previously fired event objects
    * instead of creating a new event object for each event.
    */
    virtual void setReuseEvents(boolean reuseEvents) = 0;
    /**
    * Tests whether the <code>reuseEvents</code> flag is set. If the flag is
    * set to <code>true</code> this class will reuse previously fired events
    * and will not create a new object for each event. This option increases
    * performance but should be used with care, especially in multithreaded
    * environment.
    *
    * @return the value of the <code>reuseEvents</code> flag.
    */
    virtual boolean isReuseEvents() = 0;

    // Adds the specified traversal listener to this iterator.
    // @param l the traversal listener to be added.
    virtual void addTraversalListener(TraversalListener<V, E> l) = 0;

    //Unsupported.
    //@throws UnsupportedOperationException
    virtual void remove() = 0;

    // Removes the specified traversal listener from this iterator.
    // @param l the traversal listener to be removed.
    virtual void removeTraversalListener(TraversalListener<V, E> l) = 0;

};
#endif
