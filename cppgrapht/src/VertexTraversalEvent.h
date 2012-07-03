#ifndef VERTEXTRAVERSALEVENT_H_
#define VERTEXTRAVERSALEVENT_H_


//package org.jgrapht.event;

//import java.util.*;


/**
 * A traversal event for a graph vertex.
 *
 * @author Barak Naveh
 * @since Aug 11, 2003
 */
template <class V>
class VertexTraversalEvent : EventObject
{
    //~ Static fields/initializers ---------------------------------------------

private:
	static const long serialVersionUID = 3688790267213918768L;

    //~ Instance fields --------------------------------------------------------

    /**
     * The traversed vertex.
     */
protected:
	V vertex;

    //~ Constructors -----------------------------------------------------------

    /**
     * Creates a new VertexTraversalEvent.
     *
     * @param eventSource the source of the event.
     * @param vertex the traversed vertex.
     */
public:
	VertexTraversalEvent(Object eventSource, V vertex)
    {
        super(eventSource);
        this.vertex = vertex;
    }

    //~ Methods ----------------------------------------------------------------

    /**
     * Returns the traversed vertex.
     *
     * @return the traversed vertex.
     */
    V getVertex()
    {
        return vertex;
    }
};

// End VertexTraversalEvent.java



#endif /* VERTEXTRAVERSALEVENT_H_ */
