/**
    @file   gamewindow.hpp
    @author Hanna Dutkiewicz
*/

#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QtGui/QMainWindow>
#include <boost/shared_ptr.hpp>

#include "gameboard.hpp"

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
    void okClicked();


/******** PRIVATE FIELDS ********/
private:
    /** User interface object for GameWindow */
	boost::shared_ptr<Ui::GameWindow> ui_;

    /** A pointer to a game board */
	boost::shared_ptr<GameBoard> board_;
};

#endif // GAMEWINDOW_H
