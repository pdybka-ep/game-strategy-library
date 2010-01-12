/**
  @file TicTacToeGameFactory.cpp
  @author Hanna Dutkiewicz
*/

#include <stack>
#include <list>
#include <iostream>

#include <boost/shared_ptr.hpp>

#include "../game-strategy-library/Node.hpp"
#include "../game-strategy-library/Move.hpp"
#include "../game-strategy-library/Game.hpp"

#include "TicTacToeGameFactory.hpp"
#include "TicTacToeMove.hpp"
#include "TicTacToeNode.hpp"

using namespace library;


int TicTacToeGameFactory::moveId = 0;
int TicTacToeGameFactory::nodeId = 0;


TicTacToeGameFactory::TicTacToeGameFactory(): TIC_TAC_TOE_NAME("TicTacToe Game"){

}

TicTacToeGameFactory::~TicTacToeGameFactory(){
}

bool TicTacToeGameFactory::canCreate(const std::string & gameName){
	return (gameName.compare(TIC_TAC_TOE_NAME) == 0);
}



boost::shared_ptr<Game> TicTacToeGameFactory::create(){
	moveId = 0;
	nodeId = 0;

	Game * newGame = new Game;
	boost::shared_ptr<Game> game = boost::shared_ptr<Game>(newGame);

	game->setGameId(TIC_TAC_TOE_NAME);

	// create root node
	boost::shared_ptr<Node> root = createRootNode();

	// for all nodes addAllAvailableMoves
	std::stack< boost::shared_ptr<Node> > nodesStack;
	nodesStack.push(root);

	int leafs = 0;
	while(!nodesStack.empty()){
		// take one node from the stock
		boost::shared_ptr<Node> currentNode = nodesStack.top();
		nodesStack.pop();

		// according to temporary list of next coordinates add available moves
		// moves are created with its destination node
		addAllAvailableMoves(currentNode);

		// get all available moves
		std::list<boost::shared_ptr<Move> > currentNodeMovesList = currentNode->getAvailableMoves();
		if(currentNodeMovesList.size() == 0){
			++leafs;
			continue;
		}
		
		// for all available moves get destination nodes and add them to the stock
		std::list<boost::shared_ptr<Move> >::const_iterator it = currentNodeMovesList.begin();
		while(it != currentNodeMovesList.end()){
			nodesStack.push( (*it)->getDestination() );
			++it;
		}
	}
	game->setTotalNumberOfLeafs(leafs);

	moveId = 0;
	nodeId = 0;

	game->setStartNode(root);
	return game;
}



boost::shared_ptr<Node> TicTacToeGameFactory::createRootNode(){

	TicTacToeNode * tttnode = new TicTacToeNode;
	tttnode->setNodeId(getNextNodeId());

	std::list<std::pair<int,int> > movesList;

	for(int i = 0; i < 3; ++i)
		for(int j = 0; j < 3; ++j){
			movesList.push_back( std::make_pair<int,int>(j, i) );
		}

	tttnode->setNextCoordinatesList(movesList);

	return boost::shared_ptr<Node>(tttnode);
}

/**
	Creates all available moves for current node
*/
void TicTacToeGameFactory::addAllAvailableMoves(boost::shared_ptr<Node> node){
	TicTacToeNode * tttnode = static_cast<TicTacToeNode *>( node.get() );

	std::list<std::pair<int,int> > coords = tttnode->getNextCoordinatesList();
	std::list<std::pair<int,int> >::const_iterator it = coords.begin();

	while(it != coords.end()){
		boost::shared_ptr<Move> nextMove = createNewMove(*it, coords);
		tttnode->addAvailableMove(nextMove);
		++it;
	}
	tttnode->clearNextCoordinatesList();
}

boost::shared_ptr<Move> TicTacToeGameFactory::createNewMove
(std::pair<int,int> coordinates, std::list<std::pair<int,int> > nextCoords){
	TicTacToeMove * tttmove = new TicTacToeMove;

	tttmove->setMoveId( getNextMoveId() );
	tttmove->setCoordinates(coordinates);

	nextCoords.remove(coordinates);
	
	boost::shared_ptr<Node> destNode = createNewNode(nextCoords);
	tttmove->setDestination(destNode);

	return boost::shared_ptr<Move>(tttmove);
}

/* methods for building the game tree */
boost::shared_ptr<Node> TicTacToeGameFactory::createNewNode(std::list<std::pair<int,int> > & nextCoords){
	TicTacToeNode * node = new TicTacToeNode;
	node->setNextCoordinatesList(nextCoords);
	node->setNodeId( getNextNodeId() );
	return boost::shared_ptr<Node>(node);
}




std::string& TicTacToeGameFactory::serialize(const boost::shared_ptr<Game>& game){
	return std::string("");
}

boost::shared_ptr<Game> TicTacToeGameFactory::deserialize(const std::string & data){
	return boost::shared_ptr<Game>();
}


void TicTacToeGameFactory::printTree(boost::shared_ptr<Node> node){

	TicTacToeNode * tttnode = static_cast<TicTacToeNode *> (node.get());
	std::cout << tttnode;

}