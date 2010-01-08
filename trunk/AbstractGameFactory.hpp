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

    class AbstractGameFactory {
    public:
        AbstractGameFactory();
        virtual ~AbstractGameFactory();

        /* virtual methods */
        virtual bool canCreate(const std::string& gameName) = 0;
        virtual boost::shared_ptr<Game> create(const std::string& gameName) = 0;
        virtual std::string& serialize(const boost::shared_ptr<Game>&) = 0;
        virtual boost::shared_ptr<Game>& deserialize(const std::string& data) = 0;
    };

}

#endif /* ABSTRACTGAMEFACTORY_HPP_ */
