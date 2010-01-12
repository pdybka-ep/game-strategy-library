

#ifndef TTT_NODE_H_
#define TTT_NODE_H_

#include <list>
#include <ostream>
#include "../game-strategy-library/Node.hpp"

class TicTacToeNode;
bool operator== (const TicTacToeNode&, const TicTacToeNode&);
bool operator!= (const TicTacToeNode&, const TicTacToeNode&);
std::ostream & operator<<(std::ostream & os, const TicTacToeNode & node);

class TicTacToeNode: public library::Node{

public:
    /**
     * Creates a node
     */
    TicTacToeNode();

    /**
     * Copies a node
     * @param node node to be copied
     */
    TicTacToeNode(const TicTacToeNode& node);

    /**
     * Destroys the node
     */
    virtual ~TicTacToeNode();

    TicTacToeNode& operator= (const TicTacToeNode&);

	friend bool operator== (const TicTacToeNode&, const TicTacToeNode&);
    friend bool operator!= (const TicTacToeNode&, const TicTacToeNode&);
	friend std::ostream & operator<<(std::ostream & os, const TicTacToeNode & node);


	std::list<std::pair<int,int> > getNextCoordinatesList() const{
		return nextCoordinates_;
	}

	void setNextCoordinatesList(std::list< std::pair<int,int> > & nextCoordinates){
		nextCoordinates_ = nextCoordinates;
	}

	void clearNextCoordinatesList(){
		nextCoordinates_.clear();
	}

private:
	// used just for building the game tree
	std::list<std::pair<int,int> > nextCoordinates_;

};

#endif