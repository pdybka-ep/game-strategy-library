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
	library::Game& create(const std::string & gameName);
	std::string& serialize(const library::Game & game);
	library::Game& deserialize(const std::string & data);

};


#endif /* TICTACTOEGAMEFACTORY_H */