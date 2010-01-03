/*
 * GameNotStartedException.hpp
 * Author: Michal Kolodziejski
 */

#ifndef GAMENOTSTARTEDEXCEPTION_HPP_
#define GAMENOTSTARTEDEXCEPTION_HPP_

#include <exception>
#include <string>

namespace library {

    class GameNotStartedException : public std::exception {
    public:
        GameNotStartedException();
        virtual ~GameNotStartedException() throw ();

        virtual std::string toString() const {
            return std::string("Game hasn't been started");
        }
    };

}

#endif /* GAMENOTSTARTEDEXCEPTION_HPP_ */
