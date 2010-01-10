/*
 * AbstractGameFactory.hpp
 * Author: Michal Kolodziejski
 */

#ifndef ABSTRACTGAMEFACTORY_HPP_
#define ABSTRACTGAMEFACTORY_HPP_

#include <string>
#include <boost/shared_ptr.hpp>
#include "Game.hpp"

namespace library {

    /**
     * Abstract factory for Game type
     * @author Michał Kołodziejski
     */
    class AbstractGameFactory {
    public:
        /**
         * Creates game factory
         */
        AbstractGameFactory();
        /**
         * Destroys game factory
         */
        virtual ~AbstractGameFactory();


        /* virtual methods */

        /**
         * Returns information if factory is able to create game with the given name
         * @param gameName name of the game
         * @return <code>true</code> if factory is able to create the game, <code>false</code> otherwise
         */
        virtual bool canCreate(const std::string& gameName) = 0;

        /**
         * Creates game specific to the factory 
         * @return pointer to the created game
         */
        virtual boost::shared_ptr<Game> create() = 0;

        /**
         * Serializes information about the game
         * @param game the game
         * @return serialized information
         */
        virtual std::string& serialize(const boost::shared_ptr<Game>& game) = 0;

        /**
         * Creates a game with use of given serialized data
         * @param data serialized data containing information about the game
         * @return pointer to the created game
         */
        virtual boost::shared_ptr<Game> deserialize(const std::string& data) = 0;
    };

}

#endif /* ABSTRACTGAMEFACTORY_HPP_ */
