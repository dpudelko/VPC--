#ifndef BREADTHFIRSTITERATOR_H_
#define BREADTHFIRSTITERATOR_H_

//import java.util.*;
//import org.jgrapht.*;

//#include <string>
//#include <stdexcept>
//#include <iostream>
#include "CrossComponentIterator.h"

/**
 * A breadth-first iterator for a directed and an undirected graph. For this
 * iterator to work correctly the graph must not be modified during iteration.
 * Currently there are no means to ensure that, nor to fail-fast. The results of
 * such modifications are undefined.
 */
//using namespace std;

template <class V, class E>
class BreadthFirstIterator : CrossComponentIterator<V, E, Object>{
							//objekt import java.lang.Object  java.util.EventObject
    //~ Instance fields --------------------------------------------------------
private:
	Deque<V> *queue = new ArrayDeque<V>();//private Deque<V> queue = new ArrayDeque<V>();

    //~ Constructors -----------------------------------------------------------
public:
    //Creates a new breadth-first iterator for the specified graph.
    BreadthFirstIterator(Graph<V, E> g){
    	this(g, null);
    }

    /**
     * Creates a new breadth-first iterator for the specified graph. Iteration
     * will start at the specified start vertex and will be limited to the
     * connected component that includes that vertex. If the specified start
     * vertex is <code>null</code>, iteration will start at an arbitrary vertex
     * and will not be limited, that is, will be able to traverse all the graph.
     */
    BreadthFirstIterator(Graph<V, E> g, V startVertex){
    	super(g, startVertex);
    }

    //~ Methods ----------------------------------------------------------------
protected:
    // @see CrossComponentIterator#isConnectedComponentExhausted()
    bool isConnectedComponentExhausted(){
    	return queue.isEmpty();
    }

    //@see CrossComponentIterator#encounterVertex(Object, Object)
    void encounterVertex(V vertex, E edge){
    	putSeenData(vertex, null);
    	queue.add(vertex);
    }

    //@see CrossComponentIterator#encounterVertexAgain(Object, Object)
    void encounterVertexAgain(V vertex, E edge){
    };

    // @see CrossComponentIterator#provideNextVertex()
    V provideNextVertex(){
    	return queue.removeFirst();
    }
};
#endif
