/*
 * InvalidMoveException.hpp
 * Author: Michal Kolodziejski
 */

#ifndef INVALIDMOVEEXCEPTION_HPP_
#define INVALIDMOVEEXCEPTION_HPP_

#include <exception>
#include <string>

namespace library {

    /**
     * Exception signalizing invalid move
     * @author Michał Kołodziejski
     */
    class InvalidMoveException : public std::exception {
    public:
        /**
         * Creates exception
         */
        InvalidMoveException();

        /**
         * Destroys exception
         */
        virtual ~InvalidMoveException() throw ();

        /**
         * Returns exception's description
         * @return exception's description
         */
        virtual std::string toString() const {
            return std::string("Invalid move!");
        }
    };

}

#endif /* INVALIDMOVEEXCEPTION_HPP_ */
