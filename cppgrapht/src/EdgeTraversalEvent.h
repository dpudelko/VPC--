#ifndef EDGETRAVERSALEVENT_H_
#define EDGETRAVERSALEVENT_H_


//package org.jgrapht.event;

//import java.util.*;

/**
 * A traversal event for a graph edge.
 *
 * @author Barak Naveh
 * @since Aug 11, 2003
 *
 */
// java.lang.Object  java.util.EventObject

template <class V, class E>
class EdgeTraversalEvent : EventObject
{
    //~ Static fields/initializers ---------------------------------------------

private:
	static const long serialVersionUID = 4050768173789820979L;

    //~ Instance fields --------------------------------------------------------

    /**
     * The traversed edge.
     */
protected:
	E edge;

    //~ Constructors -----------------------------------------------------------

    /**
     * Creates a new EdgeTraversalEvent.
     *
     * @param eventSource the source of the event.
     * @param edge the traversed edge.
     */
public:
	EdgeTraversalEvent(Object eventSource, E edge)
    {
        super(eventSource);
        this.edge = edge;
    }

    //~ Methods ----------------------------------------------------------------

    /**
     * Returns the traversed edge.
     *
     * @return the traversed edge.
     */
    E getEdge()
    {
        return edge;
    }
};


#endif
