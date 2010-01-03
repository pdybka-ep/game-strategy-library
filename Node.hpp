/*
 * Node.hpp
 * Author: Michal Kolodziejski
 */

#ifndef NODE_H_
#define NODE_H_

#include <list>
#include <boost/shared_ptr.hpp>

#include "Move.hpp"

namespace library {

	class Node {
	public:
		Node();
		Node(const Node&);
		virtual ~Node();

		Node& operator= (const Node&);

		/**
		 * Returns available moves
		 */
	    std::list<boost::shared_ptr<Move> > getAvailableMoves() const {
	        return availableMoves_;
	    }

	    /**
	     * Sets available moves
	     */
	    void setAvailableMoves(std::list<boost::shared_ptr<Move> > availableMoves_) {
	        this->availableMoves_ = availableMoves_;
	    }

	    void addAvailableMove(const Move &move){
	    	boost::shared_ptr<Move> newMove(new Move(move));
	    	this->availableMoves_.push_back(newMove);
	    }

	    /**
		 * Returns node ID
		 */
	    int getNodeId() const {
	        return nodeId_;
	    }

	    /**
	     * Sets node ID
	     */
	    void setNodeId(int nodeId) {
	        this->nodeId_ = nodeId;
	    }

	protected:
		int nodeId_;
		std::list<boost::shared_ptr<Move> > availableMoves_;
	};

}

#endif /* NODE_H_ */
