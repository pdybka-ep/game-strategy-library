/*
 * InvalidMoveException.hpp
 * Author: Michal Kolodziejski
 */

#ifndef INVALIDMOVEEXCEPTION_HPP_
#define INVALIDMOVEEXCEPTION_HPP_

#include <exception>
#include <string>

namespace library {

    class InvalidMoveException : public std::exception {
    public:
        InvalidMoveException();
        virtual ~InvalidMoveException() throw ();

        virtual std::string toString() const {
            return std::string("Invalid move!");
        }
    };

}

#endif /* INVALIDMOVEEXCEPTION_HPP_ */
