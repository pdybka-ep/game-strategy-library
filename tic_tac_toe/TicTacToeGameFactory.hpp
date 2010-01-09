/**
  @file TicTacToeGameFactory.hpp
  @author Hanna Dutkiewicz
*/

#ifndef TICTACTOEGAMEFACTORY_H
#define TICTACTOEGAMEFACTORY_H

#include "..\game-strategy-library\AbstractGameFactory.hpp"
#include "..\game-strategy-library\Game.hpp"


class TicTacToeGameFactory: public library::AbstractGameFactory{

public:
	TicTacToeGameFactory();
	virtual ~TicTacToeGameFactory();

	bool canCreate(const std::string & gameName);
	boost::shared_ptr<library::Game> create(const std::string & gameName);
	std::string& serialize(const boost::shared_ptr<library::Game>& game);
	boost::shared_ptr<library::Game> deserialize(const std::string & data);

};


#endif /* TICTACTOEGAMEFACTORY_H */