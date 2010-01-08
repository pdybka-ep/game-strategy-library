/*
 * GameNotStartedException.hpp
 * Author: Michal Kolodziejski
 */

#ifndef GAMENOTSTARTEDEXCEPTION_HPP_
#define GAMENOTSTARTEDEXCEPTION_HPP_

#include <exception>
#include <string>

namespace library {

    /**
     * Exception signalizing that a game has not been started where expected to be started
     * @author Michał Kołodziejski
     */
    class GameNotStartedException : public std::exception {
    public:
        /**
         * Creates exception
         */
        GameNotStartedException();

        /**
         * Destroys exception
         */
        virtual ~GameNotStartedException() throw ();

        /**
         * Returns exception's description
         * @return exception's description
         */
        virtual std::string toString() const {
            return std::string("Game hasn't been started");
        }
    };

}

#endif /* GAMENOTSTARTEDEXCEPTION_HPP_ */
