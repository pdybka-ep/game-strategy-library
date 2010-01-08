/*
 * GameFactoryInitializationException.hpp
 * Author: Michal Kolodziejski
 */

#ifndef GAMEFACTORYINITIALIZATIONEXCEPTION_HPP_
#define GAMEFACTORYINITIALIZATIONEXCEPTION_HPP_

#include <exception>
#include <string>

namespace library {

    class GameFactoryInitializationException : public std::exception {
    public:
        GameFactoryInitializationException();
        virtual ~GameFactoryInitializationException() throw ();

        virtual std::string toString() const {
            return std::string("GameFactory hasn't been initialized");
        }
    };

}

#endif /* GAMEFACTORYINITIALIZATIONEXCEPTION_HPP_ */
