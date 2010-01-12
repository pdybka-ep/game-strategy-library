/**
  @file TicTacToeGameFactory.hpp
  @author Hanna Dutkiewicz
*/

#ifndef TICTACTOEGAMEFACTORY_H
#define TICTACTOEGAMEFACTORY_H

#include <sstream>
#include <map>
#include <list>

#include "../game-strategy-library/AbstractGameFactory.hpp"
#include "../game-strategy-library/Game.hpp"
#include "../game-strategy-library/Node.hpp"
#include "../game-strategy-library/Move.hpp"

#include "TicTacToeNode.hpp"


/**
	@class TicTacToeGameFactory
	@author Hanna Dutkiewicz
	Class of a game factory of TicTacToe Game, used to create a new TicTacToe Game and its serialization/deserialization
*/
class TicTacToeGameFactory: public library::AbstractGameFactory{

public:
	/**
		Default constructor
	*/
	TicTacToeGameFactory();
	
	/**
		Virtual destructor
	*/
	virtual ~TicTacToeGameFactory();

	/**
		Checks if this factory can create game of a given name
		@param gameName name of a game
		@return <code>true</code> if a game can be created by the factory, <code>false</code> otherwhise
	*/
	bool canCreate(const std::string & gameName);

	/**
		Creates new TicTacToe game
		@return pointer to a new TicTacToe game
	*/
	boost::shared_ptr<library::Game> create();

	/**
		Serializes information about the game
		@param game the game
		@return serialized information
	*/
	std::string serialize(const boost::shared_ptr<library::Game>& game);
	
	/**
		Creates a game with use of given serialized data
		@param data serialized data containing information about the game
		@return pointer to the created game
	 */
	boost::shared_ptr<library::Game> deserialize(const std::string & data);

private:
	
/*** METHODS FOR BUILDING A GAME TREE ***/

	/**
		Creates new root node of a game tree
		@return new root node
	*/
	boost::shared_ptr<library::Node> createRootNode();
	
	/**
		Creates new move with given coordinates and with a destination node that has given next coordinates list
		@param coordinates coordinates of a TicTacToeMove
		@param nextCoord list of next coordinates of moves available from destination node of this move
		@return pointer to a new Move
	*/
	boost::shared_ptr<library::Move> createNewMove(std::pair<int,int> coordinates, std::list<std::pair<int,int> > nextCoords);
	
	/**
		Creates new node with given list of next coordinates available from this node
		@param nextCoords list of coordinates available from this node
		@return pointer to a new Node
	*/
	boost::shared_ptr<library::Node> createNewNode(std::list<std::pair<int,int> > & nextCoords);
	
	/**
		Adds all available moves to a given node, according to list of next coordinates of this node
		@param node node to which all available moves will be created and added
	*/
	void addAllAvailableMoves(boost::shared_ptr<library::Node> node);

	/**
		Returns next available move id
		@return next availavle move id
	*/
	int getNextMoveId(){
		return ++moveId;
	}

	/**
		Returns next available node id
		@return next availavle node id
	*/
	int getNextNodeId(){
		return ++nodeId;
	}


/*** SERIALIZATION ***/

	/**
        Serializes all moves available from specific node
        @param stream stream where information about moves should be placed
        @param node pointer to a node which available moves should be serialized
    */
    void serializeAllMoves(std::stringstream &stream, boost::shared_ptr<library::Node> node);

    /**
        Serializes all destination nodes of available moves of a specific node
        @param stream stream where information about nodes should be placed
        @param node pointer to a node
    */
    void serializeAllNodes(std::stringstream &stream, boost::shared_ptr<library::Node> node);


/*** DESERIALIZATION ***/

    /**
        Deserializes all moves
        @param stream stream where information about moves is placed
        @param moves  TODO
        @param movesDestinations  TODO
     */
    void deserializeAllMoves(std::stringstream &stream, std::map<int, boost::shared_ptr<library::Move> >& moves,
            std::map<int, int >& movesDestinations);

    /**
        Deserializes all nodes
        @param stream stream where information about nodes is placed
        @param nodes  TODO
     */
    void deserializeAllNodes(std::stringstream &stream, std::map<int, boost::shared_ptr<library::Node> >& nodes,
            std::map<int, boost::shared_ptr<library::Move> >& moves);


	/* for debugging only */
	//void printTree(boost::shared_ptr<library::Node> node);

	/** Constant name of a game created by this factory */
	const std::string TIC_TAC_TOE_NAME;

	/** Static counter for creating moves ids */
	static int moveId;
	
	/** Static counter for creating nodes ids */
	static int nodeId;
};


#endif /* TICTACTOEGAMEFACTORY_H */
