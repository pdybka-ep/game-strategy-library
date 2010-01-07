/*
 * game_tree_tests.cpp
 * Author: Michal Kolodziejski
 */


#define BOOST_TEST_MODULE game tree tests

#include <boost/test/included/unit_test.hpp>
#include <boost/shared_ptr.hpp>
#include "Game.hpp"
#include "Node.hpp"
#include "Move.hpp"

using namespace boost::unit_test;
using namespace library;


struct GameTreeFixture{
    GameTreeFixture(){
        boost::shared_ptr<Node> n1(new Node());
        n1->setNodeId(1);
        n1->setValue(0);
        game.setGameId("game");
        game.setStartNode(n1);
        game.setTotalNumberOfLeafs(1);
    }
    ~GameTreeFixture(){
    }

    Game game;
};


BOOST_AUTO_TEST_SUITE( game_tree_tests )

BOOST_FIXTURE_TEST_CASE( test_adding_nodes, GameTreeFixture ){
    std::list<boost::shared_ptr<Move> > moves;
    std::list<boost::shared_ptr<Move> >::iterator movesIt;

    /* add node 2 and move 1->2 */
    boost::shared_ptr<Node> n2(new Node());
    n2->setNodeId(2);

    boost::shared_ptr<Move> m12(new Move());
    m12->setMoveId(12);
    m12->setDestination(n2);

    game.getStartNode()->addAvailableMove(m12);

    moves = game.getStartNode()->getAvailableMoves();
    movesIt = moves.begin();
    BOOST_CHECK_EQUAL( moves.size(), 1 );
    BOOST_CHECK( *(*movesIt) == *m12 );
    BOOST_CHECK( (*movesIt)->getDestination() == n2 );


    /* add node 3 and move 1->3 */
    boost::shared_ptr<Node> n3(new Node());
    n2->setNodeId(3);

    boost::shared_ptr<Move> m13(new Move());
    m13->setMoveId(13);
    m13->setDestination(n3);

    game.getStartNode()->addAvailableMove(m13);

    moves = game.getStartNode()->getAvailableMoves();
    movesIt = moves.begin();
    BOOST_CHECK_EQUAL( moves.size(), 2 );
    BOOST_CHECK( *(*movesIt) == *m12 );
    BOOST_CHECK( (*movesIt)->getDestination() == n2 );
    ++movesIt;
    BOOST_CHECK( *(*movesIt) == *m13 );
    BOOST_CHECK( (*movesIt)->getDestination() == n3 );

}

BOOST_AUTO_TEST_SUITE_END()
