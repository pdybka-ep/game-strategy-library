/*
 * Node.cpp
 * Author: Michal Kolodziejski
 */

#include "Node.hpp"

namespace library {

    Node::Node() {
        nodeId_ = -1;
        value_ = 0;
    }

    Node::Node(const Node& node) {
        this->nodeId_ = node.nodeId_;
        this->value_ = node.value_;
        std::list<boost::shared_ptr<Move> >::const_iterator it = node.availableMoves_.begin();
        while(it != node.availableMoves_.end()){
            this->availableMoves_.push_back(*it);
            ++it;
        }
    }

    Node::~Node() {
        availableMoves_.clear();
    }


    Node& Node::operator=(const Node& node){
        if(this == &node)
            return *this;

        this->nodeId_ = node.nodeId_;
        this->value_ = node.value_;
        std::list<boost::shared_ptr<Move> >::const_iterator it = node.availableMoves_.begin();
        while(it != node.availableMoves_.end()){
            this->availableMoves_.push_back(*it);
            ++it;
        }
        return *this;
    }

}
