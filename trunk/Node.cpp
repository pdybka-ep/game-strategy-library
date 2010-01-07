/*
 * Node.cpp
 * Author: Michal Kolodziejski
 */

#include "Node.hpp"

namespace library {

    Node::Node() {
        nodeId_ = -1;
        value_ = 0;
        visited_ = false;
    }

    Node::Node(const Node& node) {
        this->nodeId_ = node.nodeId_;
        this->value_ = node.value_;
        this->visited_ = node.visited_;
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
        this->visited_ = node.visited_;
        std::list<boost::shared_ptr<Move> >::const_iterator it = node.availableMoves_.begin();
        while(it != node.availableMoves_.end()){
            this->availableMoves_.push_back(*it);
            ++it;
        }
        return *this;
    }


    bool operator== (const Node& n1, const Node& n2){
        if(&n1 == &n2)
            return true;
        if(n1.nodeId_ == n2.nodeId_ && n1.value_ == n2.value_ && n1.visited_ == n2.visited_
                && n1.availableMoves_ == n2.availableMoves_)
            return true;
        return false;
    }

    bool operator!= (const Node& n1, const Node& n2){
        return !(n1 == n2);
    }

}
