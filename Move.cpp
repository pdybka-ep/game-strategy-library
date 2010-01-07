/*
 * Move.cpp
 * Author: Michal Kolodziejski
 */

#include "Move.hpp"
#include "Node.hpp"

namespace library {

    Move::Move() {
        moveId_ = -1;
    }


    Move::Move(const Move& move){
        this->moveId_ = move.moveId_;
        this->destination_ = move.destination_;
    }

    Move::~Move() {
    }

    Move& Move::operator= (const Move& move){
        if(this == &move)
            return *this;

        this->moveId_ = move.moveId_;
        this->destination_ = move.destination_;
        return *this;
    }


    bool operator== (const Move& m1, const Move& m2){
        if(&m1 == &m2)
            return true;
        if(m1.moveId_ == m2.moveId_ && *(m1.destination_.get()) == *(m2.destination_.get()))
            return true;
        return false;
    }

    bool operator!= (const Move& m1, const Move& m2){
        return !(m1==m2);
    }

}
