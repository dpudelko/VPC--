#ifndef CONNECTEDCOMPONENTTRAVERSALEVENT_H_
#define CONNECTEDCOMPONENTTRAVERSALEVENT_H_


//package org.jgrapht.event;

//import java.util.*;


/**
 * A traversal event with respect to a connected component.
 *
 * @author Barak Naveh
 * @since Aug 11, 2003
 */
class ConnectedComponentTraversalEvent : EventObject
{
    //~ Static fields/initializers ---------------------------------------------

private:
	static const long serialVersionUID = 3834311717709822262L;

    /**
     * Connected component traversal started event.
     */
public:
	static const int CONNECTED_COMPONENT_STARTED = 31;

    /**
     * Connected component traversal finished event.
     */
    static const int CONNECTED_COMPONENT_FINISHED = 32;

    //~ Instance fields --------------------------------------------------------

    /**
     * The type of this event.
     */
private:
    int type;

    //~ Constructors -----------------------------------------------------------

    /**
     * Creates a new ConnectedComponentTraversalEvent.
     *
     * @param eventSource the source of the event.
     * @param type the type of event.
     */
public:
    ConnectedComponentTraversalEvent(Object eventSource, int type)
    {
        super(eventSource);
        this.type = type;
    }

    //~ Methods ----------------------------------------------------------------

    /**
     * Returns the event type.
     *
     * @return the event type.
     */
    int getType()
    {
        return type;
    }
};

// End ConnectedComponentTraversalEvent.java



#endif /* CONNECTEDCOMPONENTTRAVERSALEVENT_H_ */
