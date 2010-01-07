/*
 * Move.hpp
 * Author: Michal Kolodziejski
 */

#ifndef MOVE_H_
#define MOVE_H_

#include <boost/shared_ptr.hpp>
#include <iostream>

namespace library {

    // forward declaration
    class Node;

    class Move;
    bool operator== (const Move&, const Move&);
    bool operator!= (const Move&, const Move&);

    class Move {
    public:
        Move();
        Move(const Move &);
        virtual ~Move();

        Move& operator= (const Move&);
        friend bool operator== (const Move&, const Move&);
        friend bool operator!= (const Move&, const Move&);

        boost::shared_ptr<Node> getDestination() const {
            return destination_;
        }

        int getMoveId() const {
            return moveId_;
        }

        void setDestination(const boost::shared_ptr<Node> &destination) {
            this->destination_ = destination;
        }

        void setMoveId(int moveId) {
            this->moveId_ = moveId;
        }

    protected:
        int moveId_;
        boost::shared_ptr<Node> destination_;
    };

}

#endif /* MOVE_H_ */
