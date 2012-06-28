#ifndef DEPTHFIRSTITERATOR_H_
#define DEPTHFIRSTITERATOR_H_


//import org.jgrapht.*;
//import org.jgrapht.util.*;


/**
 * A depth-first iterator for a directed and an undirected graph. For this
 * iterator to work correctly the graph must not be modified during iteration.
 * Currently there are no means to ensure that, nor to fail-fast. The results of
 * such modifications are undefined.
 *
 * @author Liviu Rau
 * @author Barak Naveh
 * @since Jul 29, 2003
 */
template <class V, class E>
class DepthFirstIterator<V, E> :
	public CrossComponentIterator<V, E, CrossComponentIterator.VisitColor>
{
    //~ Static fields/initializers ---------------------------------------------

    /**
     * Sentinel object. Unfortunately, we can't use null, because ArrayDeque
     * won't accept those. And we don't want to rely on the caller to provide a
     * sentinel object for us. So we have to play typecasting games.
     */
public:
	static const Object SENTINEL = new Object();

    //~ Instance fields --------------------------------------------------------

    /**
     * @see #getStack
     */
private:
	Deque<Object> stack = new ArrayDeque<Object>();

   /* transient*/  TypeUtil<V> vertexTypeDecl = null;
transient failed
    //~ Constructors -----------------------------------------------------------

    /**
     * Creates a new depth-first iterator for the specified graph.
     *
     * @param g the graph to be iterated.
     */
public:
    DepthFirstIterator(Graph<V, E> g)
    {
        this(g, null);
    }

    /**
     * Creates a new depth-first iterator for the specified graph. Iteration
     * will start at the specified start vertex and will be limited to the
     * connected component that includes that vertex. If the specified start
     * vertex is <code>null</code>, iteration will start at an arbitrary vertex
     * and will not be limited, that is, will be able to traverse all the graph.
     *
     * @param g the graph to be iterated.
     * @param startVertex the vertex iteration to be started.
     */
    DepthFirstIterator(Graph<V, E> g, V startVertex)
    {
        super(g, startVertex);
    }

    //~ Methods ----------------------------------------------------------------

    /**
     * @see CrossComponentIterator#isConnectedComponentExhausted()
     */
protected:
    boolean isConnectedComponentExhausted()
    {
        for (;;) {
            if (stack.isEmpty()) {
                return true;
            }
            if (stack.getLast() != SENTINEL) {
                // Found a non-sentinel.
                return false;
            }

            // Found a sentinel:  pop it, record the finish time,
            // and then loop to check the rest of the stack.

            // Pop null we peeked at above.
            stack.removeLast();

            // This will pop corresponding vertex to be recorded as finished.
            recordFinish();
        }
    }

    /**
     * @see CrossComponentIterator#encounterVertex(Object, Object)
     */
    void encounterVertex(V vertex, E edge)
    {
        putSeenData(vertex, VisitColor.WHITE);
        stack.addLast(vertex);
    }

    /**
     * @see CrossComponentIterator#encounterVertexAgain(Object, Object)
     */
    void encounterVertexAgain(V vertex, E edge)
    {
        VisitColor color = getSeenData(vertex);
        if (color != VisitColor.WHITE) {
            // We've already visited this vertex; no need to mess with the
            // stack (either it's BLACK and not there at all, or it's GRAY
            // and therefore just a sentinel).
            return;
        }

        // Since we've encountered it before, and it's still WHITE, it
        // *must* be on the stack.  Use removeLastOccurrence on the
        // assumption that for typical topologies and traversals,
        // it's likely to be nearer the top of the stack than
        // the bottom of the stack.
        boolean found = stack.removeLastOccurrence(vertex);
        assert (found);
        stack.addLast(vertex);
    }

    /**
     * @see CrossComponentIterator#provideNextVertex()
     */
    V provideNextVertex()
    {
        V v;
        for (;;) {
            Object o = stack.removeLast();
            if (o == SENTINEL) {
                // This is a finish-time sentinel we previously pushed.
                recordFinish();
                // Now carry on with another pop until we find a non-sentinel
            } else {
                // Got a real vertex to start working on
                v = TypeUtil.uncheckedCast(o, vertexTypeDecl);
                break;
            }
        }

        // Push a sentinel for v onto the stack so that we'll know
        // when we're done with it.
        stack.addLast(v);
        stack.addLast(SENTINEL);
        putSeenData(v, VisitColor.GRAY);
        return v;
    }

private:
    void recordFinish()
    {
        V v = TypeUtil.uncheckedCast(stack.removeLast(), vertexTypeDecl);
        putSeenData(v, VisitColor.BLACK);
        finishVertex(v);
    }

    /**
     * Retrieves the LIFO stack of vertices which have been encountered but not
     * yet visited (WHITE). This stack also contains <em>sentinel</em> entries
     * representing vertices which have been visited but are still GRAY. A
     * sentinel entry is a sequence (v, SENTINEL), whereas a non-sentinel entry
     * is just (v).
     *
     * @return stack
     */
public:
    Deque<Object> getStack()
    {
        return stack;
    }
};
#endif /* DEPTHFIRSTITERATOR_H_ */