/**
    @file   gameboard.cpp
    @author Hanna Dutkiewicz
*/

#include <QBrush>
#include <QImage>
#include <QGraphicsScene>
#include <QString>

#include <boost/shared_ptr.hpp>

#include "gameboard.hpp"
#include "field.hpp"
#include "TicTacToePlayer.hpp"


GameBoard::GameBoard(QObject * parent): QObject(parent), BaseGameBoard(), pixItem_(NULL), initialized_(false), waiting_(false){
	winnerImage_.load(QString(":/res/win.png"));
	loserImage_.load(QString(":/res/lose.png"));
	remisImage_.load(QString(":/res/remis.png"));
	waitImage_.load(QString(":/res/make.png"));
	deserImage_.load(":/res/waiting.png");
}


/* A destructor. */
GameBoard::~GameBoard(){

}

void GameBoard::setGraphicsScene(boost::shared_ptr<QGraphicsScene> scene){
	scene_ = scene;
    //QImage backIm(":/res/tlo.bmp");
    scene_->setBackgroundBrush(QBrush(Qt::black));
}

void GameBoard::init(){

	if(initialized_){
		clear();
		return;
	}

	for(int i = 0; i < MAX_IN_A_ROW; ++i)
		for(int j = 0; j < MAX_IN_A_ROW; ++j)
			field_(i,j) = new Field;

    // the smaller size of scene
    qreal allSize = (scene_->sceneRect().height() > scene_->sceneRect().width())
                ? scene_->sceneRect().width()
                : scene_->sceneRect().height();

    qreal margin = 20;
    allSize -= 2*margin;
    qreal oneFieldSize = (allSize)/MAX_IN_A_ROW;

    QPointF startPoint((scene_->sceneRect().width()-allSize)/2, (scene_->sceneRect().height()-allSize)/2);

    QPen rectPen(Qt::white);
    rectPen.setCapStyle(Qt::RoundCap);
    rectPen.setStyle(Qt::SolidLine);
    rectPen.setWidth(10);

    // add fields to a scene
	
    for(int i = 0; i < MAX_IN_A_ROW; ++i){
        if(i > 0){
            scene_->addLine(startPoint.x(), startPoint.y(), startPoint.x()+MAX_IN_A_ROW*oneFieldSize, startPoint.y(), rectPen);
        }
        for(int j = 0; j < MAX_IN_A_ROW; ++j){
            // inits a field object with proper size and position
            static_cast<Field *>( field_(i,j) )->init(QSizeF(oneFieldSize, oneFieldSize), startPoint, i, j);
            scene_->addItem( static_cast<Field *>(field_(i,j)) );

            // connect fields with game board
            connect(static_cast<Field *>(field_(i,j) ), SIGNAL(wasClickedSignal()), this, SLOT(fieldWasClickedSlot()));

            if(j > 0 && i == 0)
                scene_->addLine(startPoint.x(), startPoint.y(), startPoint.x(), startPoint.y()+(MAX_IN_A_ROW)*oneFieldSize, rectPen);
            startPoint.setX(startPoint.x()+oneFieldSize);
        }
        startPoint.setX(startPoint.x()-oneFieldSize*(MAX_IN_A_ROW));
        startPoint.setY(startPoint.y()+oneFieldSize);
    }

	initialized_ = true;

}


void GameBoard::startNewGame(){
	clear();
}

void GameBoard::clear(){
	boardState_ = GAME_DURING_PLAY;
	for(int i = 0; i < MAX_IN_A_ROW; ++i)
		for(int j = 0; j < MAX_IN_A_ROW; ++j)
			field_(i,j)->setFieldState(Field::EMPTY);
	if(pixItem_ != NULL){
		scene_->removeItem(pixItem_);
		pixItem_ = NULL;
	}
}

/* Method called when a game is finished to stop the game, actualize game tree and show the winner. */
void GameBoard::endGame(TicTacToePlayer::PlayerType winner){
	boardState_ = GAME_FINISH_WINNER;
	if(winner == TicTacToePlayer::HUMAN){
		addFinishElementsToScene(winnerImage_);
	} else{
		addFinishElementsToScene(loserImage_);
	}
}

/* for remis */
void GameBoard::endGame(){
	boardState_ = GAME_FINISH_REMIS;
	addFinishElementsToScene(remisImage_);
}

void GameBoard::addFinishElementsToScene(const QPixmap & pixmap){
	pixItem_ = scene_->addPixmap(pixmap);
}

void GameBoard::wait(bool newGrameTree){
	if(pixItem_ != NULL){
		scene_->removeItem(pixItem_);
		pixItem_ = NULL;
	}
	if(newGrameTree)
		pixItem_ = scene_->addPixmap(waitImage_);
	else
		pixItem_ = scene_->addPixmap(deserImage_);
	waiting_ = true;
}

void GameBoard::stopWaiting(){
	if(pixItem_ != NULL){
		scene_->removeItem(pixItem_);
		pixItem_ = NULL;
	}
	waiting_ = false;
}


/* Slot connected to signal generated by single field when it was clicked. */
void GameBoard::fieldWasClickedSlot(){
    // here - check which player is this turn and set fields state to current player's symbol
	if(boardState_ == GAME_DURING_PLAY && !waiting_){
		Field * field = static_cast<Field *> (scene_->focusItem());
		if(field->isEmpty())
			playerMadeAmoveSignal(field->getCoordinates());
	}
}
