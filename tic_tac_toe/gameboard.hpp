/**
    @file   gameboard.hpp
    @author Hanna Dutkiewicz
*/

#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QObject>
#include <QPixmap>
#include <QGraphicsPixmapItem>

#include <boost/multi_array.hpp>
#include <boost/shared_ptr.hpp>

#include "field.hpp"
#include "TicTacToePlayer.hpp"
#include "BaseGameBoard.hpp"

/**
    @class GameBoard
    @author Hanna Dutkiewicz
    Represents a game board of a "Tic-Tac-Toe" game.
  */
class GameBoard: public QObject, public BaseGameBoard{
    Q_OBJECT


/********* PUBLIC METHODS **********/
public:
	//enum GameBoardState {GAME_NOT_STARTED, GAME_DURING_PLAY, GAME_FINISH_WINNER, GAME_FINISH_REMIS};

	/**
		A default constructor.
	*/
	GameBoard(QObject * parent = 0);

   /**
     A destructor.
     */
    virtual ~GameBoard();

    /**
      Method is called to start a new game. It clears current scene and creates new fields on it.
      */
    void startNewGame();

	/**
      Method is called to start a new game. It clears current scene and creates new fields on it.
    */
    void startFirstGame();

    /**
      Method called when a game is finished to stop the game, actualize game tree and show the winner.
      */
    void endGame();
	void endGame(TicTacToePlayer::PlayerType winner);

	void setGraphicsScene(boost::shared_ptr<QGraphicsScene> scene);

	//GameBoardState makeAmove(std::pair<int,int> coordinates, TicTacToePlayer::PlayerSign sign);

	void wait();
	void stopWaiting();



/********* PUBLIC SLOTS **********/
public slots:
    /**
      Slot connected to signal generated by single field when it was clicked.
      */
    void fieldWasClickedSlot();


signals:
	void playerMadeAmoveSignal(std::pair<int,int> coordinates);


/********* PRIVATE METHODS **********/
private:
    /**
      Clears the scene an deletes all the fields.
      */
    void clear();

	void addFinishElementsToScene(const QPixmap & pixmap);



/********* PRIVATE FIELDS **********/
private:
    /** All the fields on a board game */
	//Field field_[3][3];
	//Field ** field_;

    /** A pointer to a graphics scene */
	boost::shared_ptr<QGraphicsScene> scene_;

	QPixmap winnerImage_;
	QPixmap loserImage_;
	QPixmap remisImage_;
	QPixmap waitImage_;
	QGraphicsPixmapItem * pixItem_;


};

#endif // GAMEBOARD_H
