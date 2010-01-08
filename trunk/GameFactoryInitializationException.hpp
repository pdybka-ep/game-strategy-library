/*
 * GameFactoryInitializationException.hpp
 * Author: Michal Kolodziejski
 */

#ifndef GAMEFACTORYINITIALIZATIONEXCEPTION_HPP_
#define GAMEFACTORYINITIALIZATIONEXCEPTION_HPP_

#include <exception>
#include <string>

namespace library {

    /**
     * Exception signalizing that the game factory has not been initialized
     * @author Michał Kołodziejski
     */
    class GameFactoryInitializationException : public std::exception {
    public:
        /**
         * Creates exception
         */
        GameFactoryInitializationException();

        /**
         * Destroys exception
         */
        virtual ~GameFactoryInitializationException() throw ();

        /**
         * Returns exception's description
         * @return exception's description
         */
        virtual std::string toString() const {
            return std::string("GameFactory hasn't been initialized");
        }
    };

}

#endif /* GAMEFACTORYINITIALIZATIONEXCEPTION_HPP_ */
