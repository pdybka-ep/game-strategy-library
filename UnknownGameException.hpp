/*
 * UnknownGameException.hpp
 * Author: Michal Kolodziejski
 */

#ifndef UNKNOWNGAMEEXCEPTION_HPP_
#define UNKNOWNGAMEEXCEPTION_HPP_

#include <exception>
#include <string>

namespace library {

    /**
     * Exception signalizing unknown game
     * @author Michał Kołodziejski
     */
    class UnknownGameException : public std::exception {
    public:
        /**
         * Creates exception
         */
        UnknownGameException();

        /**
         * Destroys exception
         */
        virtual ~UnknownGameException() throw();

        /**
         * Returns exception's description
         * @return exception's description
         */
        virtual std::string toString() const {
            return std::string("Unknown game!");
        }
    };

}

#endif /* UNKNOWNGAMEEXCEPTION_HPP_ */
