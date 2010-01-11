/**
  @file TicTacToeGameController.hpp
  @author Hanna Dutkiewicz
*/

#ifndef TICTACTOEGAMECONTROLLER_H
#define TICTACTOEGAMECONTROLLER_H

#include <QObject>
#include <QFutureWatcher>

#include <boost/shared_ptr.hpp>
#include "..\game-strategy-library\GameStrategy.hpp"
#include "..\game-strategy-library\Player.hpp"
#include "..\game-strategy-library\AbstractGameFactory.hpp"

#include "TicTacToeGameFactory.hpp"
#include "GameWindow.hpp"
#include "TicTacToePlayer.hpp"
#include "GameBoard.hpp"
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

	void crateNewOponentSlot(TicTacToePlayer::PlayerLevel level);

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


private:
	void makeComputerMove();
	bool checkEndGame
		(std::pair<int,int> coordinates, boost::shared_ptr<library::Player> player, BaseGameBoard & board, bool notifyWindow = true);

	void trainComputerPlayer(boost::shared_ptr<library::Game> game);
	
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
};


#endif /* TICTACTOEGAMECONTROLLER_H */