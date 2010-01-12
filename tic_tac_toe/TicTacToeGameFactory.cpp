/**
  @file TicTacToeGameFactory.cpp
  @author Hanna Dutkiewicz
*/

#include <stack>
#include <list>
#include <iostream>
#include <sstream>

#include <boost/shared_ptr.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/tokenizer.hpp>

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

/* methods for building the game tree */

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


boost::shared_ptr<Node> TicTacToeGameFactory::createNewNode(std::list<std::pair<int,int> > & nextCoords){
	TicTacToeNode * node = new TicTacToeNode;
	node->setNextCoordinatesList(nextCoords);
	node->setNodeId( getNextNodeId() );
	return boost::shared_ptr<Node>(node);
}



std::string TicTacToeGameFactory::serialize(const boost::shared_ptr<Game>& game){
    std::cout << "Starting serialization..." << std::endl;

    std::stringstream strStream;
    // game
    strStream << "GAME" << std::endl
            << game->getGameId() << std::endl
            << game->getStartNode()->getNodeId() << std::endl
            << game->getTotalNumberOfLeafs() << std::endl
            << game->getNumberOfVisitedLeafs() << std::endl;

    std::cout << "Game written, starting with moves..." << std::endl;

    serializeAllMoves(strStream, game->getStartNode());
    strStream << "END_MOVES" << std::endl;

    std::cout << "Moves written, starting with nodes..." << std::endl;

    serializeAllNodes(strStream, game->getStartNode());
    strStream << "END_NODES" << std::endl;

    std::cout << "Nodes written, finished" << std::endl;

	return strStream.str();
}

boost::shared_ptr<Game> TicTacToeGameFactory::deserialize(const std::string & data){
    std::cout << "Starting deserialization..." << std::endl;

    std::map<int, boost::shared_ptr<Move> > moves;
    std::map<int, boost::shared_ptr<Node> > nodes;
    std::map<int, int > movesDestinations;

    boost::shared_ptr<Game> game(new Game());
    int rootNodeId;

    std::stringstream stream(data);
    std::string tempString;
    int tempInt;

    // read game info
    std::cout << "Reading game info..." << std::endl;
    std::getline(stream, tempString);       // GAME
    std::getline(stream, tempString);       // game id
    game->setGameId(tempString);
    std::getline(stream, tempString);       // rootNodeId
    rootNodeId = boost::lexical_cast<int>(tempString);
    std::getline(stream, tempString);       // totalNumberOfLeafs
    tempInt = boost::lexical_cast<int>(tempString);
    game->setTotalNumberOfLeafs(tempInt);
    std::getline(stream, tempString);       // totalNumberOfLeafs
    tempInt = boost::lexical_cast<int>(tempString);
    game->setNumberOfVisitedLeafs(tempInt);

    // read all moves
    std::cout << "Reading moves..." << std::endl;
    deserializeAllMoves(stream, moves, movesDestinations);

    // read all nodes
    std::cout << "Reading nodes..." << std::endl;
    deserializeAllNodes(stream, nodes, moves);
    game->setStartNode(nodes.find(rootNodeId)->second);

    // link moves and nodes
    std::cout << "Linking moves and nodes..." << std::endl;
    std::map<int, int >::iterator it;
    for(it = movesDestinations.begin(); it != movesDestinations.end(); ++it){
        moves.find(it->first)->second->setDestination(nodes.find(it->second)->second);
    }

    std::cout << "Deserialization finished" << std::endl;
	return game;
}



/* for serialization */
void TicTacToeGameFactory::serializeAllMoves(std::stringstream &stream, boost::shared_ptr<Node> node){
    if(node.get() == 0)
        return;
    if(node->isLeaf())
        return;

    std::list<boost::shared_ptr<Move> > avalilableMoves = node->getAvailableMoves();
    std::list<boost::shared_ptr<Move> >::iterator it;
    TicTacToeMove *ttt_move;
    for(it = avalilableMoves.begin(); it != avalilableMoves.end(); ++it){
        ttt_move = dynamic_cast<TicTacToeMove *>((*it).get());
        stream << "MOVE" << std::endl
                << ttt_move->getMoveId() << std::endl
                << ttt_move->getDestination()->getNodeId() << std::endl
                << ttt_move->getCoordinates().first << std::endl
                << ttt_move->getCoordinates().second << std::endl;
        serializeAllMoves(stream, (*it)->getDestination());
    }
}

void TicTacToeGameFactory::serializeAllNodes(std::stringstream &stream, boost::shared_ptr<Node> node){
    if(node.get() == 0)
        return;

    stream << "NODE" << std::endl
            << node->getNodeId() << std::endl
            << node->getValue() << std::endl
            << ((node->isVisited())?"true":"false") << std::endl;

    std::list<boost::shared_ptr<Move> > avalilableMoves = node->getAvailableMoves();
    std::list<boost::shared_ptr<Move> >::iterator it;

    for(it = avalilableMoves.begin(); it != avalilableMoves.end(); ++it){
        if(it != avalilableMoves.begin())
            stream << ",";
        stream << (*it)->getMoveId();
    }
    stream << std::endl;

    for(it = avalilableMoves.begin(); it != avalilableMoves.end(); ++it){
        serializeAllNodes(stream, (*it)->getDestination());
    }

}


void TicTacToeGameFactory::deserializeAllMoves(std::stringstream &stream, std::map<int, boost::shared_ptr<Move> >& moves,
            std::map<int, int >& movesDestinations){

    std::string tempString;
    int tempInt;
    // read game info
    std::getline(stream, tempString);       // "MOVE" or "END_MOVES"

    bool theEnd = (tempString=="END_MOVES");
    while(!theEnd){
        TicTacToeMove *move = new TicTacToeMove();
        std::getline(stream, tempString);       // move id
        tempInt = boost::lexical_cast<int>(tempString);
        move->setMoveId(tempInt);
        std::getline(stream, tempString);       // node id
        tempInt = boost::lexical_cast<int>(tempString);
        movesDestinations.insert(std::make_pair(move->getMoveId(), tempInt));

        std::getline(stream, tempString);       // x
        int x = boost::lexical_cast<int>(tempString);
        std::getline(stream, tempString);       // y
        int y = boost::lexical_cast<int>(tempString);
        move->setCoordinates(x,y);
        boost::shared_ptr<Move> newMove(move);
        moves.insert(std::make_pair(newMove->getMoveId(), newMove));

        std::getline(stream, tempString);
        theEnd = (tempString=="END_MOVES");
    }
}


void TicTacToeGameFactory::deserializeAllNodes(std::stringstream &stream, std::map<int, boost::shared_ptr<Node> >& nodes,
        std::map<int, boost::shared_ptr<Move> >& moves){

    std::string tempString;
    int tempInt;
    // read game info
    std::getline(stream, tempString);       // "NODE" or "END_NODES"

    bool theEnd = (tempString=="END_NODES");
    while(!theEnd){
        TicTacToeNode *node = new TicTacToeNode();
        std::getline(stream, tempString);       // node id
        tempInt = boost::lexical_cast<int>(tempString);
        node->setNodeId(tempInt);

        std::getline(stream, tempString);       // value
        tempInt = boost::lexical_cast<int>(tempString);
        node->setValue(tempInt);

        std::getline(stream, tempString);       // visited
        bool visited = false;
        if(tempString == "true")
            visited = true;
        node->setVisited(visited);

        std::getline(stream, tempString);       // moves
        boost::char_separator<char> sep(",");
        boost::tokenizer<boost::char_separator<char> > tokens(tempString, sep);
        boost::tokenizer<boost::char_separator<char> >::iterator it;
        for(it = tokens.begin(); it != tokens.end(); ++it){
            tempInt = boost::lexical_cast<int>(*it);
            boost::shared_ptr<Move> move = moves.find(tempInt)->second;
            node->addAvailableMove(move);
        }

        boost::shared_ptr<Node> newNode(node);
        nodes.insert(std::make_pair(newNode->getNodeId(), newNode));

        std::getline(stream, tempString);
        theEnd = (tempString=="END_NODES");
    }

}

