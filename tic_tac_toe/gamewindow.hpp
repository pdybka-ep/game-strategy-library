/**
    @file   gamewindow.hpp
    @author Hanna Dutkiewicz
*/

#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QtGui/QMainWindow>
#include <boost/shared_ptr.hpp>
#include <QGraphicsScene>

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

/******** PUBLIC METHODS ********/
public:
    /**
      A constructor of GameWindow - the main window of a game.
      Its parent should be NULL.
      It initializes ui_;
      */
    GameWindow(QWidget *parent = 0);
    /**
      A destructor.
      It deletes ui_.
      */
    ~GameWindow();

	void setGraphicsScene(boost::shared_ptr<QGraphicsScene> graphScene);


/******** PRIVATE SLOTS FOR MENU ITEMS ********/
private slots:
    /** Starts a new game. */
    void on_actionNewGame_triggered();

    /** Starts a new game with different oponent: a beginner. */
    void on_actionBeginner_triggered();

    /** Starts a new game with different oponent: an intermediate player. */
    void on_actionIntermediate_triggered();

    /** Starts a new game with different oponent: an advanced player. */
    void on_actionAdvanced_triggered();

    /** Saves current state of game (to be specific: the wisdom of an oponent). */
    void on_actionSave_triggered();

    /** Loads state of game (to be specific: the wisdom of an oponent). */
    void on_actionLoad_triggered();

    /** Closes the game */
    void on_actionEnd_triggered();


/*********** PUBLIC SLOTS ************/
public slots:
    /**
      Slot connected to signal Ok() from OptionsDialog.
      Sets all the parametres before game is started.
      */
	void okClickedSlot
		(TicTacToePlayer::PlayerSign humanPlayerSign, TicTacToePlayer::PlayerLevel computerPlayerLevel, QString filename);

signals:
	void crateNewOponentSignal(TicTacToePlayer::PlayerLevel level);

	void saveGameSignal();

	void loadGameSignal(std::string filename);

	void createNewGameSignal();

	void createFirstGameNewPlayerSignal
		(TicTacToePlayer::PlayerSign humanPlayerSign, TicTacToePlayer::PlayerLevel computerPlayerLevel);

	void createFirstGameLoadPlayerSignal
		(TicTacToePlayer::PlayerSign humanPlayerSign, std::string & computerPlayerFilename);


/******** PRIVATE FIELDS ********/
private:
    /** User interface object for GameWindow */
	boost::shared_ptr<Ui::GameWindow> ui_;
	//Ui::GameWindow * ui_;

	boost::shared_ptr<QGraphicsScene> scene_;
};

#endif // GAMEWINDOW_H
