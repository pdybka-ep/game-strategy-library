/*
 * basic_tests.cpp
 * Author: Michal Kolodziejski
 */

#define BOOST_TEST_MODULE basic tests

#include <boost/test/included/unit_test.hpp>
#include <boost/shared_ptr.hpp>
#include "GameStrategy.hpp"
#include "Player.hpp"
#include "Game.hpp"
#include "Node.hpp"
#include "Move.hpp"

using namespace boost::unit_test;
using namespace library;


/************************* PLAYER TESTS  *******************************/
struct PlayerFixture{
    PlayerFixture() {
        p1.setName("name");
        p1.setStartingPlayer(true);
    }
    ~PlayerFixture(){ }

    Player p1;
};

BOOST_AUTO_TEST_SUITE( basic_player_tests )

/* test getters and setters */
BOOST_FIXTURE_TEST_CASE( test_player_getters_setters, PlayerFixture ){
    BOOST_CHECK_EQUAL( p1.getName(), "name" );
    BOOST_CHECK( p1.isStartingPlayer() == true );

    p1.setStartingPlayer(false);

    BOOST_CHECK( p1.isStartingPlayer() == false );
}


/* test copy constructor */
BOOST_FIXTURE_TEST_CASE( test_player_copy_constructor, PlayerFixture ){
    Player p2(p1);
    BOOST_CHECK_EQUAL( p1.getName(), p2.getName() );
    BOOST_CHECK_EQUAL( p1.isStartingPlayer(), p2.isStartingPlayer() );
}


/* test operators */
BOOST_FIXTURE_TEST_CASE( test_player_operators, PlayerFixture ){
    Player p2;
    BOOST_CHECK( p1 != p2);

    p2 = p1;
    BOOST_CHECK_EQUAL( p1.getName(), p2.getName() );
    BOOST_CHECK_EQUAL( p1.isStartingPlayer(), p2.isStartingPlayer() );
    BOOST_CHECK( p1 == p2 );
}

BOOST_AUTO_TEST_SUITE_END()




/************************* NODE TESTS  *******************************/
struct NodeFixture {
    NodeFixture(){
        n1.setNodeId(100);
        n1.setValue(2);
        std::list<boost::shared_ptr<Move> > moves;
        move1 = boost::shared_ptr<Move>(new Move());
        moves.push_back(move1);
        n1.setAvailableMoves(moves);
    }
    ~NodeFixture(){ }

    Node n1;
    boost::shared_ptr<Move> move1;
};

BOOST_AUTO_TEST_SUITE( basic_node_tests )

/* test getters and setters */
BOOST_FIXTURE_TEST_CASE( test_node_getters_setters, NodeFixture ){
    BOOST_CHECK_EQUAL( n1.getNodeId(), 100 );
    BOOST_CHECK_EQUAL( n1.getValue(), 2 );
    BOOST_CHECK_EQUAL( n1.getAvailableMoves().size(), 1 );
    BOOST_CHECK_EQUAL( n1.getAvailableMoves().front(), move1 );
}


/* test copy constructor */
BOOST_FIXTURE_TEST_CASE( test_node_copy_constructor, NodeFixture ){
    Node n2(n1);
    BOOST_CHECK_EQUAL( n1.getNodeId(), n2.getNodeId() );
    BOOST_CHECK_EQUAL( n1.getValue(), n2.getValue() );
    BOOST_CHECK( n1.getAvailableMoves() == n2.getAvailableMoves() );
}


/* test operators */
BOOST_FIXTURE_TEST_CASE( test_node_operators, NodeFixture ){
    Node n2;
    BOOST_CHECK( n1 != n2 );

    n2 = n1;
    BOOST_CHECK_EQUAL( n1.getNodeId(), n2.getNodeId() );
    BOOST_CHECK_EQUAL( n1.getValue(), n2.getValue() );
    BOOST_CHECK( n1.getAvailableMoves() == n2.getAvailableMoves() );
    BOOST_CHECK( n1 == n2 );
}


BOOST_AUTO_TEST_SUITE_END()




/************************* MOVE TESTS  *******************************/
struct MoveFixture {
    MoveFixture(){
        m1.setMoveId(100);
        node1 = boost::shared_ptr<Node>(new Node());
        m1.setDestination(node1);
    }
    ~MoveFixture() { }

    Move m1;
    boost::shared_ptr<Node> node1;
};

BOOST_AUTO_TEST_SUITE( basic_move_tests )

/* test getters and setters */
BOOST_FIXTURE_TEST_CASE( test_move_getters_setters, MoveFixture ){
    BOOST_CHECK_EQUAL( m1.getMoveId(), 100 );
    boost::shared_ptr<Node> newNode(new Node());
    BOOST_CHECK( *(m1.getDestination()) == *(newNode) );
}


/* test copy constructor */
BOOST_FIXTURE_TEST_CASE( test_move_copy_constructor, MoveFixture ){
    Move m2(m1);
    BOOST_CHECK_EQUAL( m1.getMoveId(), m2.getMoveId() );
    BOOST_CHECK_EQUAL( m1.getDestination(), m2.getDestination() );
}


/* test operators */
BOOST_FIXTURE_TEST_CASE( test_move_operators, MoveFixture ){
    Move m2;
    BOOST_CHECK( m1 != m2 );

    m2 = m1;
    BOOST_CHECK_EQUAL( m1.getMoveId(), m2.getMoveId() );
    BOOST_CHECK_EQUAL( m1.getDestination(), m2.getDestination() );
    BOOST_CHECK( m1 == m2 );
}


BOOST_AUTO_TEST_SUITE_END()




/************************* GAME TESTS  *******************************/
struct GameFixture{
    GameFixture(){
        g1.setGameId("game1");
        g1.setTotalNumberOfNodes(100);
        g1.setNumberOfVisitedNodes(55);
        node1 = boost::shared_ptr<Node>(new Node());
        g1.setStartNode(node1);
    }
    ~GameFixture() { }

    Game g1;
    boost::shared_ptr<Node> node1;
};
BOOST_AUTO_TEST_SUITE( basic_game_tests )

/* test getters and setters */
BOOST_FIXTURE_TEST_CASE( test_game_getters_setters, GameFixture ){
    BOOST_CHECK_EQUAL( g1.getGameId(), "game1" );
    BOOST_CHECK_EQUAL( g1.getTotalNumberOfNodes(), 100 );
    BOOST_CHECK_EQUAL( g1.getNumberOfVisitedNodes(), 55 );
    boost::shared_ptr<Node> node2(new Node());
    BOOST_CHECK( *(g1.getStartNode().get()) == *(node2.get()) );
}


/* test copy constructor */
BOOST_FIXTURE_TEST_CASE( test_game_copy_constructor, GameFixture ){
    Game g2(g1);

    BOOST_CHECK_EQUAL( g1.getGameId(), g2.getGameId() );
    BOOST_CHECK_EQUAL( g1.getTotalNumberOfNodes(), g2.getTotalNumberOfNodes() );
    BOOST_CHECK_EQUAL( g1.getNumberOfVisitedNodes(), g2.getNumberOfVisitedNodes() );
    BOOST_CHECK_EQUAL( g1.getStartNode(), g2.getStartNode() );
}


/* test operators */
BOOST_FIXTURE_TEST_CASE( test_game_operators, GameFixture ){
    Game g2;
    BOOST_CHECK( g1 != g2 );

    g2 = g1;
    BOOST_CHECK_EQUAL( g1.getGameId(), g2.getGameId() );
    BOOST_CHECK_EQUAL( g1.getTotalNumberOfNodes(), g2.getTotalNumberOfNodes() );
    BOOST_CHECK_EQUAL( g1.getNumberOfVisitedNodes(), g2.getNumberOfVisitedNodes() );
    BOOST_CHECK_EQUAL( g1.getStartNode(), g2.getStartNode() );
    BOOST_CHECK( g1 == g2 );
}

BOOST_AUTO_TEST_SUITE_END()

