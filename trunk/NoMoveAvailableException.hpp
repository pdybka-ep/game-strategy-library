/*
 * NoMoveAvailableException.hpp
 * Author: Michal Kolodziejski
 */

#ifndef NOMOVEAVAILABLEEXCEPTION_HPP_
#define NOMOVEAVAILABLEEXCEPTION_HPP_

#include <exception>
#include <string>

namespace library {

    /**
     * Exception signalizing that there is no move available
     * @author Michał Kołodziejski
     */
    class NoMoveAvailableException : public std::exception {
    public:
        /**
         * Creates exception
         */
        NoMoveAvailableException();

        /**
         * Destroys exception
         */
        virtual ~NoMoveAvailableException() throw();

        /**
         * Returns exception's description
         * @return exception's description
         */
        virtual std::string toString() const {
            return std::string("No move available!");
        }
    };

}

#endif /* NOMOVEAVAILABLEEXCEPTION_HPP_ */
