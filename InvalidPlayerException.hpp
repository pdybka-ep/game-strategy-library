/*
 * InvalidPlayerException.hpp
 * Author: Michal Kolodziejski
 */

#ifndef INVALIDPLAYEREXCEPTION_HPP_
#define INVALIDPLAYEREXCEPTION_HPP_

#include <exception>
#include <string>

namespace library {

    /**
     * Exception signalizing invalid player
     * @author Michał Kołodziejski
     */
    class InvalidPlayerException : public std::exception  {
    public:
        /**
         * Creates exception
         */
        InvalidPlayerException();

        /**
         * Destroys exception
         */
        virtual ~InvalidPlayerException() throw ();

        /**
         * Returns exception's description
         * @return exception's description
         */
        virtual std::string toString() const {
            return std::string("Invalid player!");
        }
    };

}

#endif /* INVALIDPLAYEREXCEPTION_HPP_ */
