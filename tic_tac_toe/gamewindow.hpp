/**
    @file   gamewindow.hpp
    @author Hanna Dutkiewicz
*/

#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QtGui/QMainWindow>
#include <QGraphicsScene>

#include <boost/shared_ptr.hpp>

#include "gameboard.hpp"
#include "TicTacToePlayer.hpp"

class GameBoard;

namespace Ui{
    class GameWindow;
}

/**
	@class GameWindow
	Main window of the game.
	One of the GUI classes.
	@author Hanna Dutkiewicz
*/
class GameWindow : public QMainWindow{
    Q_OBJECT
	Q_DISABLE_COPY( GameWindow )

public:
    /**
		A constructor of GameWindow - the main window of a game,
		its parent should be NULL, initializes ui_
    */
    GameWindow(QWidget *parent = 0);
	
    /**
		A destructor
    */
    ~GameWindow();

	/**
		Sets graphics scene
		@param graphScene a pointer to a graphics scene
	*/
	void setGraphicsScene(boost::shared_ptr<QGraphicsScene> graphScene);

	/**
		Method to indicate that the game was finished without a winner
	*/
	void endGame();
	
	/**
		Method to indicate that the game was finished with a winner of given type
		@param type type of the winner
	*/
	void endGame(TicTacToePlayer::PlayerType type);

	/**
		Method to indicate window that computations are being done in 
		a game controller and it should wait for the result
	*/
	void wait();
	
	/**
		Method to indicate that computations are finished in
		a game controller, it can stop waiting for it
	*/
	void stopWaiting();


/*********** PUBLIC SLOTS ************/
public slots:
    /**
		Slot connected to signal Ok() from OptionsDialog.
		Sets all the parametres before game is started.
		@param humanPlayerSign sign of a human player
		@param computerPlayerLevel chosen level of a computer player
		@param filename name of the file with a game state to be loaded, is empty when oponent should be generated
    */
	void okClickedSlot
		(TicTacToePlayer::PlayerSign humanPlayerSign, TicTacToePlayer::PlayerLevel computerPlayerLevel, QString filename);

	/**
		Slot connected to SignDialog to get a new sign to be set
		@param sing new sign of human player to be set
	*/
	void changeSignSlot(TicTacToePlayer::PlayerSign sign);

/************ SIGNALS **************/
signals:
	/**
		Signal generate to game controller to save the game
	*/
	void saveGameSignal();

	/**
		Signal generate to a game controller to load the game
		@param filename filename with a game state to be loaded
	*/
	void loadGameSignal(std::string filename);

	/**
		Signal generated to a game controller to start new game
	*/
	void createNewGameSignal();

	/**
		Signal generated to a game controller to start new set of games with new generated computer player
		@param humanPlayerSign sign of human player
		@param computerPlayerLevel level of computer player
	*/
	void createFirstGameNewPlayerSignal
		(TicTacToePlayer::PlayerSign humanPlayerSign, TicTacToePlayer::PlayerLevel computerPlayerLevel);

	/**
		Signal generated to a game controller to start new set of games with loaded computer player
		@param humanPlayerSign sign of human player
		@param computerPlayerFilename filename to load the game state
	*/
	void createFirstGameLoadPlayerSignal
		(TicTacToePlayer::PlayerSign humanPlayerSign, std::string computerPlayerFilename);

	/**
		Signal generated to a game controller to change human player sign
		@param sign new human player sign to be set
	*/
	void changeSignSignal(TicTacToePlayer::PlayerSign sign);


/******** PRIVATE SLOTS FOR MENU ITEMS ********/
private slots:

    /** 
		Starts a new game
	*/
    void on_actionNewGame_triggered();

	/**
		Start a new set of games
	*/
	void on_actionTotalNewGame_triggered();

    /** 
		Saves current state of the game
	*/
    void on_actionSave_triggered();

    /** 
		Loads state of the game 
	*/
    void on_actionLoad_triggered();

    /** 
		Closes the game 
	*/
    void on_actionEnd_triggered();

	/**
		Changes the sign of a human player
	*/
	void on_actionChangeSign_triggered();

	
private:
    /** User interface object for GameWindow */
	boost::shared_ptr<Ui::GameWindow> ui_;

	/** Pointer to a graphics scene */
	boost::shared_ptr<QGraphicsScene> scene_;

	/** Holds human player sign */
	TicTacToePlayer::PlayerSign humanPlayerSign_;
};

#endif // GAMEWINDOW_H
