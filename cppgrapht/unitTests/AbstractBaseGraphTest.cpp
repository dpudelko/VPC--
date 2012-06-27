

/*
#include "StdAfx.h"
#include <cppunit/config/SourcePrefix.h>
#include <cppunit/extensions/HelperMacros.h>
#include "AbstractBaseGraph.h"
*/
#include "AbstractBaseGraphTest.hpp"
/*
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

#include <iostream>
#include "TestApp.h"
*/

// Registers the fixture into the 'registry'
//CPPUNIT_TEST_SUITE_REGISTRATION( AbstractBaseGraphTest );

// TODO : Undirected Graphs wurden in diesen Tests nicht herangezogen
#if 0
void AbstractBaseGraphTest::setUp()
{
	ef = new ClassBasedEdgeFactory<int, DefaultEdge<int> >();
	dg = new DefaultDirectedGraph<int, DefaultEdge<int> >(ef);
	AbstractBaseGraph<int, DefaultEdge<int> > *abg = new AbstractBaseGraph<int, DefaultEdge<int> >(ef,true,true,true);

}

void AbstractBaseGraphTest::tearDownA()
{
	delete ef;
	delete dg;
	delete abg;
}

//TODO Setup Teardown funktioniert nicht, exceptions werden nicht erkannt
void AbstractBaseGraphTest::testKonstruktor()
{

	AbstractBaseGraph<int,  DefaultEdge<int> > *abgkorrekt;
	AbstractBaseGraph<int,  DefaultEdge<int> > *abgfalsch;
#if 0
	ef = new ClassBasedEdgeFactory<int, DefaultEdge<int> >();
	dg = new DefaultDirectedGraph<int, DefaultEdge<int> >(ef);

	CPPUNIT_ASSERT_THROW((abgfalsch=new AbstractBaseGraph<int,DefaultEdge<int> >(NULL,true,true,true)),std::exception);//invalid_argument
	CPPUNIT_ASSERT(abgfalsch==NULL);

	CPPUNIT_ASSERT_NO_THROW((abgkorrekt=new AbstractBaseGraph<int,DefaultEdge<int> >(ef,true,true,true)));
	CPPUNIT_ASSERT(abgkorrekt!= NULL);
#endif
	CPPUNIT_ASSERT(abg==NULL);
}

#if 0
void  AbstractBaseGraphTest::testAddVertex()
{
	int v1=10;

	CPPUNIT_ASSERT(dg->addVertex(&v1)== true);
}
void AbstractBaseGraphTest::testaddEdge()
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
void AbstractBaseGraphTest::testaddEdgeWithGivenEdge()
{
	int v1=10;
	int v2=20;
	AbstractBaseGraph<int, DefaultEdge<int> > *abgNoLoopsNOMultipleEdges=new AbstractBaseGraph<int, DefaultEdge<int> >(ef,false,false,true);
	EdgeFactory<int, int>* edgeFactory;

	abgNoLoopsNOMultipleEdges->addVertex(&v1);
	abgNoLoopsNOMultipleEdges->addVertex(&v2);
	int *e =edgeFactory->createEdge(&v1,&v2);

	CPPUNIT_ASSERT(abgNoLoopsNOMultipleEdges->addEdge(&v1,&v2,e)==true);
	CPPUNIT_ASSERT(abgNoLoopsNOMultipleEdges->addEdge(&v1,&v2)== NULL);//this add would be a multiple Edge
	CPPUNIT_ASSERT_THROW(abgNoLoopsNOMultipleEdges->addEdge(&v1,&v1),invalid_argument);
	CPPUNIT_ASSERT_THROW(abgNoLoopsNOMultipleEdges->addEdge(&v1,&v2,NULL),invalid_argument);
}

//TODO: Edge Factory ncoh nicht getestet



void AbstractBaseGraphTest::testgetAllEdges()
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

void AbstractBaseGraphTest::testisAllowingLoops()
{
//	AbstractBaseGraph<int, int> *abg = new AbstractBaseGraph<int, int>(ef,true,true,true);
	CPPUNIT_ASSERT(abg->isAllowingLoops()==true);
}

void AbstractBaseGraphTest::testisAllowingMultipleEdges()
{
//	AbstractBaseGraph<int, int> *abg = new AbstractBaseGraph<int, int>(ef,true,true,true);
	CPPUNIT_ASSERT(abg->isAllowingMultipleEdges()==true);
}
void AbstractBaseGraphTest::testgetEdge()
{
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

}
void AbstractBaseGraphTest::testgetEdgeFactory()
{
		CPPUNIT_ASSERT(abg->edgeFactory==abg->getEdgeFactory());
}
void  AbstractBaseGraphTest::testsetEdgeSetFactory()
{
	EdgeSetFactory<int, int>* edgeSetFactory;
	abg->setEdgeSetFactory(edgeSetFactory);
	CPPUNIT_ASSERT(edgeSetFactory==abg->edgeSetFactory);
}
void AbstractBaseGraphTest::testcreateIntrusiveEdge()
{	int v1=1,v2=2;
	IntrusiveEdge<int>* intrusiveEdge;
	EdgeFactory<int, int>* edgeFactory;
	int *e=edgeFactory->createEdge(&v1,&v2);
	abg->addVertex(&v1);
	abg->addVertex(&v2);
	intrusiveEdge=abg->createIntrusiveEdge(NULL,&v1,&v2);
	CPPUNIT_ASSERT(intrusiveEdge!=NULL);
	intrusiveEdge=abg->createIntrusiveEdge(e,&v1,&v2);
	CPPUNIT_ASSERT(((IntrusiveEdge<int>*))e==intrusiveEdge);
}

void AbstractBaseGraphTest::testgetEdgeSource_Target()
{
	int v1=1,v2=2;
	EdgeFactory<int, int>* edgeFactory;
	int *e=edgeFactory->createEdge(&v1,&v2);

	abg->addVertex(&v1);
	abg->addVertex(&v2);
	abg->addEdge(&v1,&v2,e);
	CPPUNIT_ASSERT(abg->getEdgeSource(e)==&v1);
	CPPUNIT_ASSERT(abg->getEdgeTarget(e)==&v2);
}
#endif
#endif
