/**
  @file TicTacToeGameFactory.cpp
  @author Hanna Dutkiewicz
*/

#include "TicTacToeGameFactory.hpp"

using library::Game;

TicTacToeGameFactory::TicTacToeGameFactory(){

}

TicTacToeGameFactory::~TicTacToeGameFactory(){

}

bool TicTacToeGameFactory::canCreate(const std::string & gameName){
	return false;
}

boost::shared_ptr<Game> TicTacToeGameFactory::create(const std::string & gameName){
	return boost::shared_ptr<Game>();
}

std::string& TicTacToeGameFactory::serialize(const boost::shared_ptr<Game>& game){
	return std::string("");
}

boost::shared_ptr<Game> TicTacToeGameFactory::deserialize(const std::string & data){
	return boost::shared_ptr<Game>();
}

