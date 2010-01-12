/**
  @file TicTacToeGameController.hpp
  @author Hanna Dutkiewicz
*/

#ifndef TICTACTOEGAMECONTROLLER_H
#define TICTACTOEGAMECONTROLLER_H

#include <QObject>
#include <QFutureWatcher>

#include <boost/shared_ptr.hpp>
#include <boost/random.hpp>

#include "../game-strategy-library/GameStrategy.hpp"
#include "../game-strategy-library/Player.hpp"
#include "../game-strategy-library/AbstractGameFactory.hpp"

#include "TicTacToeGameFactory.hpp"
#include "gamewindow.hpp"
#include "TicTacToePlayer.hpp"
#include "gameboard.hpp"
#include "TicTacToeMove.hpp"
#include "BaseGameBoard.hpp"


/**
	@class GameController
	Game controller (in MVC model)
	@uthor Hanna Dutkiewicz
*/
class TicTacToeGameController: public QObject{

	Q_OBJECT

public:
	TicTacToeGameController(GameWindow &gameWindow_);

	~TicTacToeGameController();

	void initialize();

public slots:

	void saveGameSlot();

	void loadGameSlot(std::string & filename);

	/**
		Creates just another game in a set of games. Starts the game with the same properties: sign and oponent.
	*/
	void createNewGameSlot();

	void createFirstGameNewPlayerSlot
		(TicTacToePlayer::PlayerSign humanPlayerSign, TicTacToePlayer::PlayerLevel computerPlayerLevel);

	void createFirstGameLoadPlayerSlot
		(TicTacToePlayer::PlayerSign humanPlayerSign, std::string & computerPlayerFilename);

	void playerMadeAmoveSlot(std::pair<int,int> m);

	void gameOponentCreatedSlot();

	void changeSignSlot(TicTacToePlayer::PlayerSign humanPlayerSign);


private:
	void makeComputerMove();

	bool checkEndGame
		(std::pair<int,int> coordinates, boost::shared_ptr<library::Player> player, BaseGameBoard & board, bool notifyWindow);

	void trainComputerPlayer(boost::shared_ptr<library::Game> game);

	boost::shared_ptr<library::Move> getRandMove();
	
	// model
	library::GameStrategy gameStrategy_;

	boost::shared_ptr<library::AbstractGameFactory> factory_;

	// view
	GameWindow &gameWindow_;

	// game elements
	GameBoard gameBoard_;
	boost::shared_ptr<library::Player> playerHuman_;
	boost::shared_ptr<library::Player> playerComp_;

	QFutureWatcher<boost::shared_ptr<library::Game> > watcher_;

	TicTacToePlayer::PlayerLevel computerPlayerLevel_;

	static const int NODES_MEDIUM = 100000;
	static const int NODES_ADVANCED = 300000;

};


#endif /* TICTACTOEGAMECONTROLLER_H */
