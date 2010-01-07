/*
 * game_strategy_tests.cpp
 * Author: Michal Kolodziejski
 */

#define BOOST_TEST_MODULE game strategy tests

#include <boost/test/included/unit_test.hpp>
#include <boost/shared_ptr.hpp>
//#include <iostream> // FIXME
#include "GameStrategy.hpp"
#include "Player.hpp"
#include "Game.hpp"
#include "Node.hpp"
#include "Move.hpp"

using namespace boost::unit_test;
using namespace library;


struct GameStrategyFixture{
    GameStrategyFixture(){
//        std::cout << "game strategy fixture SETUP" << std::endl;
        // node 8
        n8 = boost::shared_ptr<Node>(new Node());
        n8->setNodeId(8);

        // node 7
        n7 = boost::shared_ptr<Node>(new Node());
        n7->setNodeId(7);

        // node 6
        n6 = boost::shared_ptr<Node>(new Node());
        n6->setNodeId(6);

        // move 6->7
        m67 = boost::shared_ptr<Move>(new Move());
        m67->setMoveId(67);
        m67->setDestination(n7);
        n6->addAvailableMove(m67);

        // move 6->8
        m68 = boost::shared_ptr<Move>(new Move());
        m68->setMoveId(68);
        m68->setDestination(n8);
        n6->addAvailableMove(m68);

        // node 5
        n5 = boost::shared_ptr<Node>(new Node());
        n5->setNodeId(5);

        // node 4
        n4 = boost::shared_ptr<Node>(new Node());
        n4->setNodeId(4);

        // node 3
        n3 = boost::shared_ptr<Node>(new Node());
        n3->setNodeId(3);

        // move 3->6
        m36 = boost::shared_ptr<Move>(new Move());
        m36->setMoveId(36);
        m36->setDestination(n6);
        n3->addAvailableMove(m36);

        // node 2
        n2 = boost::shared_ptr<Node>(new Node());
        n2->setNodeId(2);

        // move 2->4
        m24 = boost::shared_ptr<Move>(new Move());
        m24->setMoveId(24);
        m24->setDestination(n4);
        n2->addAvailableMove(m24);

        // move 2->5
        m25 = boost::shared_ptr<Move>(new Move());
        m25->setMoveId(25);
        m25->setDestination(n5);
        n2->addAvailableMove(m25);

        // node 1
        n1 = boost::shared_ptr<Node>(new Node());
        n1->setNodeId(1);

        // move 1->2
        m12 = boost::shared_ptr<Move>(new Move());
        m12->setMoveId(12);
        m12->setDestination(n2);
        n1->addAvailableMove(m12);

        // move 1->3
        m13 = boost::shared_ptr<Move>(new Move());
        m13->setMoveId(13);
        m13->setDestination(n3);
        n1->addAvailableMove(m13);

        // Game
        game.setGameId("test_game");
        game.setStartNode(n1);
        game.setTotalNumberOfLeafs(4);

        // Players
        p1 = boost::shared_ptr<Player>(new Player());
        p1->setName("test1");
        p1->setStartingPlayer(true);

        p2 = boost::shared_ptr<Player>(new Player());
        p2->setName("test2");
    }
    ~GameStrategyFixture() {
//        std::cout << "game strategy fixture TEARDOWN" << std::endl;
    }

    GameStrategy gameStrategy;
    Game game;
    boost::shared_ptr<Player> p1, p2;
    boost::shared_ptr<Move> m12, m13, m24, m25, m36, m67, m68;
    boost::shared_ptr<Node> n1, n2, n3, n4, n5, n6, n7, n8;
};


BOOST_FIXTURE_TEST_SUITE( game_strategy_tests, GameStrategyFixture )

BOOST_AUTO_TEST_CASE( game_strategy_test_before_play ){
    gameStrategy.startGame(game, p1, p2);
    BOOST_CHECK( n1->getValue() == 0 );
    BOOST_CHECK( n2->getValue() == 0 );
    BOOST_CHECK( n3->getValue() == 0 );
    BOOST_CHECK( n4->getValue() == 0 );
    BOOST_CHECK( n5->getValue() == 0 );
    BOOST_CHECK( n7->getValue() == 0 );
    BOOST_CHECK( n8->getValue() == 0 );
}


BOOST_AUTO_TEST_CASE( game_strategy_test_game1 ){
    gameStrategy.startGame(game, p1, p2);
    gameStrategy.move(m12);
    BOOST_CHECK( n1->getValue() == 0 );
    BOOST_CHECK( n2->getValue() == 0 );
    BOOST_CHECK( n3->getValue() == 0 );
    BOOST_CHECK( n4->getValue() == 0 );
    BOOST_CHECK( n5->getValue() == 0 );
    BOOST_CHECK( n7->getValue() == 0 );
    BOOST_CHECK( n8->getValue() == 0 );
    gameStrategy.move(m25);
    BOOST_CHECK( n1->getValue() == 0 );
    BOOST_CHECK( n2->getValue() == 0 );
    BOOST_CHECK( n3->getValue() == 0 );
    BOOST_CHECK( n4->getValue() == 0 );
    BOOST_CHECK( n5->getValue() == 0 );
    BOOST_CHECK( n7->getValue() == 0 );
    BOOST_CHECK( n8->getValue() == 0 );
    gameStrategy.endOfGame(p1);
    BOOST_CHECK( n1->getValue() == 0 );
    BOOST_CHECK( n2->getValue() == 0 );
    BOOST_CHECK( n3->getValue() == 0 );
    BOOST_CHECK( n4->getValue() == 0 );
    BOOST_CHECK( n5->getValue() == 1 );
    BOOST_CHECK( n7->getValue() == 0 );
    BOOST_CHECK( n8->getValue() == 0 );
}


BOOST_AUTO_TEST_CASE( game_strategy_test_game2 ){
    // play first game as above
    gameStrategy.startGame(game, p1, p2);
    gameStrategy.move(m12);
    gameStrategy.move(m25);
    gameStrategy.endOfGame(p1);

    // play second game
    gameStrategy.startGame();
    gameStrategy.move(m12);
    gameStrategy.move(m24);
    gameStrategy.endOfGame(p2);
    BOOST_CHECK( n1->getValue() ==  0 );
    BOOST_CHECK( n2->getValue() == -1 );
    BOOST_CHECK( n3->getValue() ==  0 );
    BOOST_CHECK( n4->getValue() == -1 );
    BOOST_CHECK( n5->getValue() ==  1 );
    BOOST_CHECK( n7->getValue() ==  0 );
    BOOST_CHECK( n8->getValue() ==  0 );
}


BOOST_AUTO_TEST_CASE( game_strategy_test_game3 ){
    // play first two games as above
    gameStrategy.startGame(game, p1, p2);
    gameStrategy.move(m12);
    gameStrategy.move(m25);
    gameStrategy.endOfGame(p1);
    gameStrategy.startGame();
    gameStrategy.move(m12);
    gameStrategy.move(m24);
    gameStrategy.endOfGame(p2);

    // play third game
    gameStrategy.startGame();
    gameStrategy.move(m13);
    gameStrategy.move(m36);
    gameStrategy.move(m67);
    gameStrategy.endOfGame(p2);

    BOOST_CHECK( n1->getValue() ==  0 );
    BOOST_CHECK( n2->getValue() == -1 );
    BOOST_CHECK( n3->getValue() ==  0 );
    BOOST_CHECK( n4->getValue() == -1 );
    BOOST_CHECK( n5->getValue() ==  1 );
    BOOST_CHECK( n7->getValue() == -1 );
    BOOST_CHECK( n8->getValue() ==  0 );
}


BOOST_AUTO_TEST_CASE( game_strategy_test_game4 ){
    // play first three games as above
    gameStrategy.startGame(game, p1, p2);
    gameStrategy.move(m12);
    gameStrategy.move(m25);
    gameStrategy.endOfGame(p1);
    gameStrategy.startGame();
    gameStrategy.move(m12);
    gameStrategy.move(m24);
    gameStrategy.endOfGame(p2);
    gameStrategy.startGame();
    gameStrategy.move(m13);
    gameStrategy.move(m36);
    gameStrategy.move(m67);
    gameStrategy.endOfGame(p2);

    // play fourth game
    gameStrategy.startGame();
    gameStrategy.move(m13);
    gameStrategy.move(m36);
    gameStrategy.move(m68);
    gameStrategy.endOfGame(p1);
    BOOST_CHECK( n1->getValue() ==  1 );
    BOOST_CHECK( n2->getValue() == -1 );
    BOOST_CHECK( n3->getValue() ==  1 );
    BOOST_CHECK( n4->getValue() == -1 );
    BOOST_CHECK( n5->getValue() ==  1 );
    BOOST_CHECK( n7->getValue() == -1 );
    BOOST_CHECK( n8->getValue() ==  1 );
}


BOOST_AUTO_TEST_CASE( game_strategy_test_best_moves1 ){
    gameStrategy.startGame(game, p1, p2);
    BOOST_CHECK( *(gameStrategy.findBestMove()) == *m12 );
    gameStrategy.move(m12);
    BOOST_CHECK( *(gameStrategy.findBestMove()) == *m24 );
    gameStrategy.move(m25);
    gameStrategy.endOfGame(p1);

}


BOOST_AUTO_TEST_SUITE_END()






