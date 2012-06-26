/*
 * AbstractBaseGraphTest.h
 *
 *  Created on: 16.06.2012
 *      Author: Michael
 */

#ifndef TESTMAIN_H_
#define TESTMAIN_H_
#include <cppunit/extensions/HelperMacros.h>
#include <map>
#include <set>
#include <stdexcept>
#include <typeinfo>
#include "StdAfx.h"
#include <cppunit/config/SourcePrefix.h>
#include <cppunit/extensions/HelperMacros.h>
#include "AbstractBaseGraph.h"

#include <iostream>
#include <exception>
#include "AbstractBaseGraph.h"
#include "AbstractGraph.h"
#include "AsUndirectedGraph.h"
#include "ClassBasedEdgeFactory.h"
#include "ClassBasedVertexFactory.h"
#include "DefaultEdge.h"
#include "DefaultWeightedEdge.h"
#include "DefaultDirectedGraph.h"
#include "DefaultDirectedWeightedGraph.h"
#include "DirectedGraph.h"
#include "DirectedMultigraph.h"
#include "EdgeFactory.h"
#include "EdgeSetFactory.h"
#include "Graph.h"
#include "GraphDelegator.h"
#include "GraphPath.h"
#include "Graphs.h"
#include "IntrusiveEdge.h"
#include "UndirectedGraph.h"
#include "VertexFactory.h"
#include "WeightedGraph.h"
#include "TestApp.h"

class AbstractBaseGraphTest  : public CPPUNIT_NS::TestFixture
{

private:
	ClassBasedEdgeFactory<int, DefaultEdge<int> >* ef;
	DefaultDirectedGraph<int, DefaultEdge<int> >* dg;
	AbstractBaseGraph<int, int> *abg;
public:


	CPPUNIT_TEST_SUITE( AbstractBaseGraphTest );
	CPPUNIT_TEST( testKonstruktor );
	//CPPUNIT_TEST_EXCEPTION(testKonstruktor, exception);
#if 0

	CPPUNIT_TEST( testAddVertex );
	CPPUNIT_TEST( testgetEdge );
	CPPUNIT_TEST( testaddEdge );
	CPPUNIT_TEST( testgetAllEdges );
	CPPUNIT_TEST( testisAllowingLoops );
	CPPUNIT_TEST(testisAllowingMultipleEdges);
	CPPUNIT_TEST(testgetEdge);
	CPPUNIT_TEST(testgetEdgeFactory);
	CPPUNIT_TEST(testsetEdgeSetFactory);
	CPPUNIT_TEST(testaddEdgeWithGivenEdge);
	CPPUNIT_TEST(testcreateIntrusiveEdge);
	CPPUNIT_TEST(testgetEdgeSource_Target);
#endif
	CPPUNIT_TEST_SUITE_END();

	void setUpA();
	void tearDownA();
	void testAddVertex();
	void testgetEdge();
	void testaddEdge();
	void testKonstruktor();
	void testgetAllEdges();
	void testisAllowingLoops();
	void testisAllowingMultipleEdges();
	void testgetEdgeFactory();
	void testsetEdgeSetFactory();
	void testaddEdgeWithGivenEdge();
	void testcreateIntrusiveEdge();
	void testgetEdgeSource_Target();
};



#endif /* TESTMAIN_H_ */
