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

    class Node;
    bool operator== (const Node&, const Node&);
    bool operator!= (const Node&, const Node&);

    /**
     * Class representing tree's single node
     * @author Michał Kołodziejski
     */
    class Node {
    public:
        /**
         * Creates a node
         */
        Node();

        /**
         * Copies a node
         * @param node node to be copied
         */
        Node(const Node& node);

        /**
         * Destroys the node
         */
        virtual ~Node();

        Node& operator= (const Node&);

        friend bool operator== (const Node&, const Node&);
        friend bool operator!= (const Node&, const Node&);


        /**
         * Returns available moves
         * @return available moves
         */
        std::list<boost::shared_ptr<Move> > getAvailableMoves() const {
            return availableMoves_;
        }

        /**
         * Sets available moves
         * @param availableMoves available moves
         */
        void setAvailableMoves(std::list<boost::shared_ptr<Move> > availableMoves) {
            this->availableMoves_ = availableMoves;
        }

        /**
         * Adds new move to the list of available moves
         * @param move a move to be added
         */
        void addAvailableMove(const boost::shared_ptr<Move> &move){
            this->availableMoves_.push_back(move);
        }

        /**
         * Returns node ID
         * @return node ID
         */
        int getNodeId() const {
            return nodeId_;
        }

        /**
         * Sets node ID
         * @param nodeId a node ID
         */
        void setNodeId(int nodeId) {
            this->nodeId_ = nodeId;
        }

        /**
         * Returns information if the node is a leaf
         * @return <code>true</code> if the node is a leaf, <code>false</code> otherwise
         */
        bool isLeaf() const {
            return this->availableMoves_.empty();
        }

        /**
         * Returns node's value
         * @return node's value
         */
        int getValue() const {
            return this->value_;
        }

        /**
         * Sets node's value
         * @param value node's value
         */
        void setValue(int value) {
            this->value_ = value;
        }

        /**
         * Returns information if the node has already been visited
         * @return <code>true</code> if the node has already been visited, <code>false</code> otherwise
         */
        bool isVisited() const {
            return this->visited_;
        }

        /**
         * Sets visited flag
         * @param visited a visited flag
         */
        void setVisited(bool visited) {
            this->visited_ = visited;
        }

    protected:
        /**
         * Node's ID
         */
        int nodeId_;

        /**
         * Node's value
         */
        int value_;

        /**
         * Moves available from the node
         */
        std::list<boost::shared_ptr<Move> > availableMoves_;

        /**
         * Visited flag
         */
        bool visited_;
    };

}

#endif /* NODE_H_ */
