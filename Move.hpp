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

    /**
     * Class representing a single move from one node to another in the game tree.
     * @author Michał Kołodziejski
     */
    class Move {
    public:
        /**
         * Creates a move
         */
        Move();

        /**
         * Copis a move
         * @param move a move to be copied
         */
        Move(const Move &move);

        /**
         * Destroys the move
         */
        virtual ~Move();

        Move& operator= (const Move&);
        friend bool operator== (const Move&, const Move&);
        friend bool operator!= (const Move&, const Move&);


        /**
         * Returns move's destination node
         * @return move's destination node
         */
        boost::shared_ptr<Node> getDestination() const {
            return destination_;
        }

        /**
         * Returns move's ID
         * @return move's ID
         */
        int getMoveId() const {
            return moveId_;
        }

        /**
         * Sets move's destination node
         * @param destination a move's destination node
         */
        void setDestination(const boost::shared_ptr<Node> &destination) {
            this->destination_ = destination;
        }

        /**
         * Sets move's ID
         * @param moveId a move's ID
         */
        void setMoveId(int moveId) {
            this->moveId_ = moveId;
        }

    protected:
        /**
         * Move's ID
         */
        int moveId_;

        /**
         * Move's destination node
         */
        boost::shared_ptr<Node> destination_;
    };

}

#endif /* MOVE_H_ */
