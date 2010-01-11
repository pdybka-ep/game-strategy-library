#include "BaseGameBoard.hpp"

using boost::numeric::ublas::matrix;

BaseGameBoard::BaseGameBoard(): boardState_(GAME_DURING_PLAY), field_(3,3){
	for(int i = 0; i < MAX_IN_A_ROW; ++i)
		for(int j = 0; j < MAX_IN_A_ROW; ++j)
			field_(i,j) = NULL;
}

BaseGameBoard::~BaseGameBoard(){
	if(field_(0,0) != NULL){
		for(int i = 0; i < MAX_IN_A_ROW; ++i)
			for(int j = 0; j < MAX_IN_A_ROW; ++j)
				delete field_(i,j);
	}
}

void BaseGameBoard::init(){
	for(int i = 0; i < MAX_IN_A_ROW; ++i)
		for(int j = 0; j < MAX_IN_A_ROW; ++j){
			field_(i,j) = new BaseField;
			field_(i,j)->setCoordinates(std::make_pair<int,int>(i,j) );
		}
}


void BaseGameBoard::startNewGame(){
	boardState_ = GAME_DURING_PLAY;
	for(int i = 0; i < MAX_IN_A_ROW; ++i)
		for(int j = 0; j < MAX_IN_A_ROW; ++j)
			field_(i,j)->setFieldState(BaseField::EMPTY);
	
}
/*
void BaseGameBoard::startFirstGame(){
	startNewGame();
}
*/
void BaseGameBoard::endGame(){
	boardState_ = GAME_FINISH_REMIS;
}

void BaseGameBoard::endGame(TicTacToePlayer::PlayerType ){
	boardState_ = GAME_FINISH_WINNER;
}

BaseGameBoard::GameBoardState BaseGameBoard::makeAmove(std::pair<int,int> coordinates, TicTacToePlayer::PlayerSign sign){

	BaseField::FieldState state = (sign == TicTacToePlayer::CIRCLE ? BaseField::CIRCLE : BaseField::CROSS);
	//field_[coordinates.first][coordinates.second].setFieldState(state);
	field_(coordinates.first,coordinates.second)->setFieldState(state);

	int emptyCounter = 0;

	for(int i = 0; i < MAX_IN_A_ROW; ++i){
		if(*field_(0,i) == *field_(1,i) && *field_(1,i) == *field_(2,i))
			return GAME_FINISH_WINNER;
		else if(*field_(i,0) == *field_(i,1) && *field_(i,1) == *field_(i,2))
			return GAME_FINISH_WINNER;

		for(int j = 0; j < MAX_IN_A_ROW; ++j)
			if(field_(i,j)->isEmpty())
				++emptyCounter;
	}

	if(emptyCounter == 0)
		return GAME_FINISH_REMIS;

	if((*field_(0,0) == *field_(1,1) && *field_(1,1) == *field_(2,2)) ||
		(*field_(0,2) == *field_(1,1) && *field_(1,1) == *field_(2,0)))
		return GAME_FINISH_WINNER;

	return GAME_DURING_PLAY;

}
