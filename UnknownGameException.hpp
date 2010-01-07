/*
 * UnknownGameException.hpp
 * Author: Michal Kolodziejski
 */

#ifndef UNKNOWNGAMEEXCEPTION_HPP_
#define UNKNOWNGAMEEXCEPTION_HPP_

#include <exception>
#include <string>

namespace library {

    class UnknownGameException : public std::exception {
    public:
        UnknownGameException();
        virtual ~UnknownGameException() throw();

        virtual std::string toString() const {
            return std::string("Unknown game!");
        }
    };

}

#endif /* UNKNOWNGAMEEXCEPTION_HPP_ */
