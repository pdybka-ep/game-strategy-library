/*
 * NoMoveAvailableException.hpp
 * Author: Michal Kolodziejski
 */

#ifndef NOMOVEAVAILABLEEXCEPTION_HPP_
#define NOMOVEAVAILABLEEXCEPTION_HPP_

#include <exception>
#include <string>

namespace library {

    class NoMoveAvailableException : public std::exception {
    public:
        NoMoveAvailableException();
        virtual ~NoMoveAvailableException() throw();

        virtual std::string toString() const {
            return std::string("No move available!");
        }
    };

}

#endif /* NOMOVEAVAILABLEEXCEPTION_HPP_ */
