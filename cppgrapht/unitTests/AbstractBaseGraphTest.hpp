/*
 * AbstractBaseGraphTest.h
 *
 *  Created on: 16.06.2012
 *      Author: Michael
 */

#ifndef TESTMAIN_H_
#define TESTMAIN_H_

#include <map>
#include <set>
#include <stdexcept>
#include <typeinfo>
#include "StdAfx.h"
#include <cppunit/config/SourcePrefix.h>
#include <cppunit/extensions/HelperMacros.h>



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
	AbstractBaseGraph<int, DefaultEdge<int> > *abg;
public:


	void setUp()
	{
		ef = new ClassBasedEdgeFactory<int, DefaultEdge<int> >();
		dg = new DefaultDirectedGraph<int, DefaultEdge<int> >(ef);
		abg = new AbstractBaseGraph<int, DefaultEdge<int> >(ef,true,true,true);
	}

	void tearDown()
	{
		delete ef;
		delete dg;
		delete abg;
	}

	  static CppUnit::Test *suite()
	  {
	    CppUnit::TestSuite *suiteOfTests = new CppUnit::TestSuite( "AbstractBaseGraphTest" );

	    suiteOfTests->addTest( new CppUnit::TestCaller<AbstractBaseGraphTest>("testKonstruktor",&AbstractBaseGraphTest::testKonstruktor ) );
	    suiteOfTests->addTest( new CppUnit::TestCaller<AbstractBaseGraphTest>("testAddVertex",&AbstractBaseGraphTest::testAddVertex ) );
	    suiteOfTests->addTest( new CppUnit::TestCaller<AbstractBaseGraphTest>("testaddEdge",&AbstractBaseGraphTest::testaddEdge ) );
//	    suiteOfTests->addTest( new CppUnit::TestCaller<AbstractBaseGraphTest>("testaddEdgeWithGivenEdge",&AbstractBaseGraphTest::testaddEdgeWithGivenEdge ) );
//	    suiteOfTests->addTest( new CppUnit::TestCaller<AbstractBaseGraphTest>("testgetAllEdges",&AbstractBaseGraphTest::testgetAllEdges ) );
//	    suiteOfTests->addTest( new CppUnit::TestCaller<AbstractBaseGraphTest>("testisAllowingLoops",&AbstractBaseGraphTest::testisAllowingLoops ) );
//	    suiteOfTests->addTest( new CppUnit::TestCaller<AbstractBaseGraphTest>("testisAllowingMultipleEdges",&AbstractBaseGraphTest::testisAllowingMultipleEdges ) );
//	    suiteOfTests->addTest( new CppUnit::TestCaller<AbstractBaseGraphTest>("testgetEdge",&AbstractBaseGraphTest::testgetEdge ) );
//	    suiteOfTests->addTest( new CppUnit::TestCaller<AbstractBaseGraphTest>("testgetEdgeFactory",&AbstractBaseGraphTest::testgetEdgeFactory ) );
//	    suiteOfTests->addTest( new CppUnit::TestCaller<AbstractBaseGraphTest>("testsetEdgeSetFactory",&AbstractBaseGraphTest::testsetEdgeSetFactory ) );
//	    suiteOfTests->addTest( new CppUnit::TestCaller<AbstractBaseGraphTest>("testcreateIntrusiveEdge",&AbstractBaseGraphTest::testcreateIntrusiveEdge ) );
//	    suiteOfTests->addTest( new CppUnit::TestCaller<AbstractBaseGraphTest>("testgetEdgeSource_Target",&AbstractBaseGraphTest::testgetEdgeSource_Target ) );
//	    suiteOfTests->addTest( new CppUnit::TestCaller<AbstractBaseGraphTest>("testisAllowingLoops",&AbstractBaseGraphTest::testisAllowingLoops ) );


//	    suiteOfTests->addTest( new CppUnit::TestCaller<AbstractBaseGraphTest>("testgetEdge",&AbstractBaseGraphTest::testgetEdge ) );
//	    suiteOfTests->addTest( new CppUnit::TestCaller<AbstractBaseGraphTest>("testgetEdgeFactory",&AbstractBaseGraphTest::testgetEdgeFactory ) );

	    return suiteOfTests;
	  }


	void testKonstruktor()
	{
		std::cout <<abg<<"dsaf"<<'\n';

		AbstractBaseGraph<int,  DefaultEdge<int> > *abgkorrekt;
		AbstractBaseGraph<int,  DefaultEdge<int> > *abgfalsch;
//		ef = new ClassBasedEdgeFactory<int, DefaultEdge<int> >();
//		dg = new DefaultDirectedGraph<int, DefaultEdge<int> >(ef);

		CPPUNIT_ASSERT_THROW((abgfalsch=new AbstractBaseGraph<int,DefaultEdge<int> >(NULL,true,true,true)),std::exception);//invalid_argument
		CPPUNIT_ASSERT(abgfalsch==NULL);

		CPPUNIT_ASSERT_NO_THROW((abgkorrekt=new AbstractBaseGraph<int,DefaultEdge<int> >(ef,true,true,true)));
		CPPUNIT_ASSERT(abgkorrekt!= NULL);

		CPPUNIT_ASSERT(ef!=NULL);

	}
	//_______________________________________________

	void   testAddVertex()
	{
		int v1=10;
		CPPUNIT_ASSERT(dg->addVertex(&v1)== true);
	}
	void  testaddEdge()
	{
		int v1=10;
		int v2=20;
	//	ClassBasedEdgeFactory<int, DefaultEdge<int> >* ef = new ClassBasedEdgeFactory<int, DefaultEdge<int> >();
	//	DefaultDirectedGraph<int, DefaultEdge<int> >* dg = new DefaultDirectedGraph<int, DefaultEdge<int> >(ef);
		AbstractBaseGraph<int, DefaultEdge<int> > *abgNoLoopsNOMultipleEdges=new AbstractBaseGraph<int, DefaultEdge<int> >(ef,false,false,true);

		abgNoLoopsNOMultipleEdges->addVertex(&v1);
		abgNoLoopsNOMultipleEdges->addVertex(&v2);


		CPPUNIT_ASSERT(abgNoLoopsNOMultipleEdges->addEdge(&v1,&v2)!= NULL);
		CPPUNIT_ASSERT(abgNoLoopsNOMultipleEdges->addEdge(&v1,&v2)== NULL);//this add would be a multiple Edge
		CPPUNIT_ASSERT_THROW(abgNoLoopsNOMultipleEdges->addEdge(&v1,&v1),invalid_argument);

	}
	void  testaddEdgeWithGivenEdge()
	{
		int v1=10;
		int v2=20;
		AbstractBaseGraph<int, DefaultEdge<int> > *abgNoLoopsNOMultipleEdges=new AbstractBaseGraph<int, DefaultEdge<int> >(ef,false,false,true);
		EdgeFactory<int, int>* edgeFactory;
		std::cout<<'\n'<<abgNoLoopsNOMultipleEdges<<'\n';
//		abgNoLoopsNOMultipleEdges->addVertex(&v1);
//		abgNoLoopsNOMultipleEdges->addVertex(&v2);
		int *e =edgeFactory->createEdge(&v1,&v2);

	//	CPPUNIT_ASSERT(abgNoLoopsNOMultipleEdges->addEdge(&v1,&v2,e)==true);
//		CPPUNIT_ASSERT(abgNoLoopsNOMultipleEdges->addEdge(&v1,&v2)== NULL);//this add would be a multiple Edge
//		CPPUNIT_ASSERT_THROW(abgNoLoopsNOMultipleEdges->addEdge(&v1,&v1),invalid_argument);
//		CPPUNIT_ASSERT_THROW(abgNoLoopsNOMultipleEdges->addEdge(&v1,&v2,NULL),invalid_argument);
	}

	//TODO: Edge Factory ncoh nicht getestet



	void  testgetAllEdges()
	{
	//	ClassBasedEdgeFactory<int, DefaultEdge<int> >* ef = new ClassBasedEdgeFactory<int, DefaultEdge<int> >();
	//	DefaultDirectedGraph<int, DefaultEdge<int> >* g = new DefaultDirectedGraph<int, DefaultEdge<int> >(ef);
	//	AbstractBaseGraph<int, int> *abg = new AbstractBaseGraph<int, int>(ef,true,true,true);
		int v1=10,v2=3,v3=1;
		int v4;
		abg->addVertex(&v1);
		abg->addVertex(&v2);
		abg->addVertex(&v3);

		CPPUNIT_ASSERT(abg->getAllEdges(&v1,&v2)==NULL);

		abg->addEdge(&v1,&v2);
		abg->addEdge(&v1,&v3);

		CPPUNIT_ASSERT(abg->getAllEdges(&v1,&v2)!=NULL);
		CPPUNIT_ASSERT(abg->getAllEdges(&v1,&v4)==NULL);//v4 ist kein Vertex und auch keine Kante
	}

	void  testisAllowingLoops()
	{
	//	AbstractBaseGraph<int, int> *abg = new AbstractBaseGraph<int, int>(ef,true,true,true);
	//	CPPUNIT_ASSERT(abg->isAllowingLoops()==true);

	}

	void  testisAllowingMultipleEdges()
	{
	//	AbstractBaseGraph<int, int> *abg = new AbstractBaseGraph<int, int>(ef,true,true,true);
		CPPUNIT_ASSERT(abg->isAllowingMultipleEdges()==true);
	}
	void  testgetEdge()
	{
#if 0
		EdgeFactory<int, int>* edgeFactory;
		int v1=10,v2=3,v3=1;
		int v4;
		abg->addVertex(&v1);
		abg->addVertex(&v2);
		int *eAdded = abg->addEdge(&v1,&v2);
		CPPUNIT_ASSERT(eAdded!=NULL);
		CPPUNIT_ASSERT(eAdded==abg->getEdge(&v1,&v2));
		CPPUNIT_ASSERT(eAdded==abg->getEdge(&v2,&v1));
		CPPUNIT_ASSERT(eAdded!=abg->getEdge(&v2,&v3));//Vertex doesn't exist
		abg->addVertex(&v3);
		CPPUNIT_ASSERT(eAdded!=abg->getEdge(&v2,&v3));//Edge doesn't exist
# endif
	}
	void  testgetEdgeFactory()
	{
			CPPUNIT_ASSERT(abg->edgeFactory==abg->getEdgeFactory());
	}
	void   testsetEdgeSetFactory()
	{
#if 0
		EdgeSetFactory<int, int>* edgeSetFactory;
		abg->setEdgeSetFactory(edgeSetFactory);
		CPPUNIT_ASSERT(edgeSetFactory==abg->edgeSetFactory);
#endif
	}
	void  testcreateIntrusiveEdge()
	{	int v1=1,v2=2;
		IntrusiveEdge<int>* intrusiveEdge;
		EdgeFactory<int, int>* edgeFactory;
		int *e=edgeFactory->createEdge(&v1,&v2);
		abg->addVertex(&v1);
		abg->addVertex(&v2);
		intrusiveEdge=abg->createIntrusiveEdge(NULL,&v1,&v2);
		CPPUNIT_ASSERT(intrusiveEdge!=NULL);
	//	intrusiveEdge=abg->createIntrusiveEdge(e,&v1,&v2);
	//	CPPUNIT_ASSERT(((IntrusiveEdge<int>*))e==intrusiveEdge);
	}

	void  testgetEdgeSource_Target()
	{
		int v1=1,v2=2;
		EdgeFactory<int, int>* edgeFactory;
		int *e=edgeFactory->createEdge(&v1,&v2);
#if 0
		abg->addVertex(&v1);
		abg->addVertex(&v2);
		abg->addEdge(&v1,&v2,e);
		CPPUNIT_ASSERT(abg->getEdgeSource(e)==&v1);
		CPPUNIT_ASSERT(abg->getEdgeTarget(e)==&v2);
#endif
	}



	//_______________________________________________



#if 0
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


#endif
};



#endif /* TESTMAIN_H_ */
