/**
  @file TicTacToeGameFactory.hpp
  @author Hanna Dutkiewicz
*/

#ifndef TICTACTOEGAMEFACTORY_H
#define TICTACTOEGAMEFACTORY_H

#include "../game-strategy-library/AbstractGameFactory.hpp"
#include "../game-strategy-library/Game.hpp"
#include "../game-strategy-library/Node.hpp"
#include "TicTacToeNode.hpp"
#include <sstream>


class TicTacToeGameFactory: public library::AbstractGameFactory{

public:
	TicTacToeGameFactory();
	virtual ~TicTacToeGameFactory();

	bool canCreate(const std::string & gameName);

	/**
		Creates new TicTacToe game
	*/
	boost::shared_ptr<library::Game> create();

	std::string serialize(const boost::shared_ptr<library::Game>& game);
	boost::shared_ptr<library::Game> deserialize(const std::string & data);

private:
	
/* methods for building the game tree */
	boost::shared_ptr<library::Node> createRootNode();
	boost::shared_ptr<library::Move> createNewMove(std::pair<int,int> coordinates, std::list<std::pair<int,int> > nextCoords);
	boost::shared_ptr<library::Node> createNewNode(std::list<std::pair<int,int> > & nextCoords);
	void addAllAvailableMoves(boost::shared_ptr<library::Node> node);


	int getNextMoveId(){
		return ++moveId;
	}

	int getNextNodeId(){
		return ++nodeId;
	}

	/* for serialization */
    void serializeAllMoves(std::stringstream &stream, boost::shared_ptr<TicTacToeNode> node);
    void serializeAllNodes(std::stringstream &stream, boost::shared_ptr<TicTacToeNode> node);

/* for debugging only */
	void printTree(boost::shared_ptr<library::Node> node);

	const std::string TIC_TAC_TOE_NAME;

	static int moveId;
	static int nodeId;
};


#endif /* TICTACTOEGAMEFACTORY_H */
