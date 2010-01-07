/*
 * InvalidPlayerException.hpp
 * Author: Michal Kolodziejski
 */

#ifndef INVALIDPLAYEREXCEPTION_HPP_
#define INVALIDPLAYEREXCEPTION_HPP_

#include <exception>
#include <string>

namespace library {

    class InvalidPlayerException : public std::exception  {
    public:
        InvalidPlayerException();
        virtual ~InvalidPlayerException() throw ();

        virtual std::string toString() const {
            return std::string("Invalid player!");
        }
    };

}

#endif /* INVALIDPLAYEREXCEPTION_HPP_ */
