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

Game& TicTacToeGameFactory::create(const std::string & gameName){
	return Game();
}

std::string& TicTacToeGameFactory::serialize(const Game & game){
	return std::string("");
}

Game& TicTacToeGameFactory::deserialize(const std::string & data){
	return Game();
}

