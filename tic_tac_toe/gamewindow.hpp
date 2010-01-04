/**
    gamewindow.h
    Author: Hanna Dutkiewicz
*/

#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QtGui/QMainWindow>
#include "gameboard.hpp"

class GameBoard;

namespace Ui
{
    class GameWindow;
}

class GameWindow : public QMainWindow{
    Q_OBJECT

/******** PRIVATE FIELDS ********/
private:
    /** User interface object for GameWindow */
    Ui::GameWindow *ui_;
    /** A pointer to a game board */
    GameBoard * board_;

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
    void on_actionNewGame_triggered();
    void on_actionBeginner_triggered();
    void on_actionIntermediate_triggered();
    void on_actionAdvanced_triggered();
    void on_actionSave_triggered();
    void on_actionLoad_triggered();
    void on_actionEnd_triggered();
    void on_actionStats_triggered();


/*********** PUBLIC SLOTS ************/
public slots:
    void okClicked();
};

#endif // GAMEWINDOW_H
