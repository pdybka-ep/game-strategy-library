/**
  @file TicTacToeNode.hpp
  @author Hanna Dutkiewicz
*/

#ifndef TTT_NODE_H_
#define TTT_NODE_H_

#include <list>
#include <ostream>

#include "../game-strategy-library/Node.hpp"

class TicTacToeNode;
bool operator== (const TicTacToeNode&, const TicTacToeNode&);
bool operator!= (const TicTacToeNode&, const TicTacToeNode&);
//std::ostream & operator<<(std::ostream & os, const TicTacToeNode & node);

/**
	@class TicTacToeNode
	@author Hanna Dutkiewicz
	Class representing a single node in a game tree in TicTacToe Game.
*/
class TicTacToeNode: public library::Node{

public:
    /**
		Creates a node
     */
    TicTacToeNode();

    /**
		Copies a node
		@param node node to be copied
		@return copied node
     */
    TicTacToeNode(const TicTacToeNode& node);

    /**
		Destroys the node
     */
    virtual ~TicTacToeNode();

	/**
		Copies elements from another node
		@param node to be copied
	*/
    TicTacToeNode& operator= (const TicTacToeNode& node);

	/**
		Friend function that compares two nodes
		@param n1 first node to be compared
		@param n2 second node to be compared
		@return <code>true</code> if n1 is equal to n2, <code>false</code> otherwise
	*/
	friend bool operator== (const TicTacToeNode& n1, const TicTacToeNode& n2);
	
	/**
		Friend function that compares two nodes and says if they are not equal
		@param n1 first node to be compared
		@param n2 second node to be compared
		@return <code>true</code> if n1 is NOT equal to n2, <code>false</code> otherwise
	*/
    friend bool operator!= (const TicTacToeNode& n1, const TicTacToeNode& n2);
	//friend std::ostream & operator<<(std::ostream & os, const TicTacToeNode & node);


	/**
		Returns list of coordinates of available moves from this node.
		@return list of available moves' coordinates
	*/
	std::list<std::pair<int,int> > getNextCoordinatesList() const{
		return nextCoordinates_;
	}

	/**
		Sets list of coordinates of available moves from this node.
		@param nextCoordinates list of available moves' coordinates
	*/
	void setNextCoordinatesList(std::list< std::pair<int,int> > & nextCoordinates){
		nextCoordinates_ = nextCoordinates;
	}

	/**
		Clears list of next coordinates since it's a temporary list used for creating game tree only
	*/
	void clearNextCoordinatesList(){
		nextCoordinates_.clear();
	}

private:
	/** Temporary list of next moves' coordinates used for creating game tree */
	std::list<std::pair<int,int> > nextCoordinates_;

};

#endif