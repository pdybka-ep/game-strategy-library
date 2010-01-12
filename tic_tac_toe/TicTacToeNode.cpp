/**
  @file TicTacToeNode.cpp
  @author Hanna Dutkiewicz
*/

#include <iostream>

#include "TicTacToeNode.hpp"
#include "TicTacToeMove.hpp"

using namespace library;
using std::endl;

TicTacToeNode::TicTacToeNode(): Node(){
}


TicTacToeNode::TicTacToeNode(const TicTacToeNode & node){
	*this = node;
}

TicTacToeNode::~TicTacToeNode(){
	availableMoves_.clear();
	nextCoordinates_.clear();
}

TicTacToeNode& TicTacToeNode::operator= (const TicTacToeNode & node){
	if(this == &node)
        return *this;

    this->nodeId_ = node.nodeId_;
    this->value_ = node.value_;
    this->visited_ = node.visited_;

    std::list<boost::shared_ptr<Move> >::const_iterator it = node.availableMoves_.begin();
    while(it != node.availableMoves_.end()){
        this->availableMoves_.push_back(*it);
        ++it;
    }

	std::list<std::pair<int,int> >::const_iterator itt = node.nextCoordinates_.begin();
	while(itt != node.nextCoordinates_.end()){
		this->nextCoordinates_.push_back(*itt);
		++itt;
	}

    return *this;
}

bool operator== (const TicTacToeNode& n1, const TicTacToeNode& n2){
	if(&n1 == &n2)
            return true;
        if(n1.nodeId_ == n2.nodeId_ && n1.value_ == n2.value_ && n1.visited_ == n2.visited_
                && n1.availableMoves_ == n2.availableMoves_ 
				&& n1.nextCoordinates_ == n2.nextCoordinates_)
            return true;
        return false;
}

bool operator!= (const TicTacToeNode& n1, const TicTacToeNode& n2){
	return !(n1 == n2);
}
/*
std::ostream & operator<<(std::ostream & os, const TicTacToeNode & node){
	os << "---NODE-------------"<<endl;
	os << " id: " << node.nodeId_;
	os << " value: " << node.value_;
	os << " visited: " << node.visited_ << endl;
	os << " next coordinates: " << endl;

	std::list<std::pair<int,int> >::const_iterator itt = node.nextCoordinates_.begin();
	while(itt != node.nextCoordinates_.end()){
		os << "(" << itt->first << "," << itt->second << ") ";
		++itt;
	}

	os << "moves: " << node.availableMoves_.size() << " ids: " << endl;

	std::list<boost::shared_ptr<Move> >::const_iterator it = node.availableMoves_.begin();
    while(it != node.availableMoves_.end()){
        os << (*it)->getMoveId() << " ";
    }
	os << "---END NODE-------------"<<endl;

	it = node.availableMoves_.begin();
    while(it != node.availableMoves_.end()){
		TicTacToeMove * tttmove = static_cast<TicTacToeMove *>( (*it).get() );
        os << *tttmove;
    }

	return os;
}
*/