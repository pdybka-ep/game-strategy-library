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
    Represents a game board of a TicTacToe game, GUI representation of BaseGameBoard
  */
class GameBoard: public QObject, public BaseGameBoard{
    Q_OBJECT


public:

	/**
		A default constructor.
		@param parent pointer to objects parent
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
		Method is called to initialize a game board
    */
	void init();

    /**
		Method called when a game is finished to stop the game
    */
    void endGame();
	
	/**
		Method called when a game is finished to stop the game and show which player won
		@param winner type of winner player
    */
	void endGame(TicTacToePlayer::PlayerType winner);

	/**
		Sets the graphics scene of a board
	*/
	void setGraphicsScene(boost::shared_ptr<QGraphicsScene> scene);

	/**
		Method to indicate a board that computations are being done in 
		a game controller and it should wait for the result.
		@param newGameTree is it computations of a new game tree
	*/
	void wait(bool newGrameTree);
	
	/**
		Method to indicate that computations are finished in
		a game controller, it can stop waiting for it
	*/
	void stopWaiting();


/********* PUBLIC SLOTS **********/
public slots:
    /**
		Slot connected to signal generated by single field when it was clicked,
		generates appropriate signal to a game window
    */
    void fieldWasClickedSlot();

/********** SIGNALS ***********/
signals:
	/**
		Signal generated when player made a move to a game window 
		and then to a game controller
		@param coordinates coordinates of a field which was clicked by the player
	*/
	void playerMadeAmoveSignal(std::pair<int,int> coordinates);


private:
    /**
		Clears the scene and sets all the fields as EMPTY.
    */
    void clear();

	/**
		Adds a pixmap to a scene to show the result of a game
	*/
	void addFinishElementsToScene(const QPixmap & pixmap);


private:

    /** A pointer to a graphics scene */
	boost::shared_ptr<QGraphicsScene> scene_;

	/** Image "You're a winner" */
	QPixmap winnerImage_;
	/** Image "You've lost" */
	QPixmap loserImage_;
	/** Image "Equal result" */
	QPixmap remisImage_;
	/** Image "Computations are being done" */
	QPixmap waitImage_;
	/** Image "Serialization or deserialization" */
	QPixmap deserImage_;
	
	/** Pointer to current pixmap item placed on a board */
	QGraphicsPixmapItem * pixItem_;

	/** Indicates whether board was initialized */
	bool initialized_;
};

#endif // GAMEBOARD_H
