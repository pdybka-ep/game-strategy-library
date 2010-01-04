/**
    gamewindow.cpp
    Author: Hanna Dutkiewicz
*/

#include <QImage>
#include <QBrush>
#include <QGraphicsScene>

#include "gamewindow.hpp"
#include "ui_gamewindow.h"

GameWindow::GameWindow(QWidget *parent)
    : QMainWindow(parent), ui_(new Ui::GameWindow){

    ui_->setupUi(this);

    QGraphicsScene * graphScene = new QGraphicsScene(this);

    board_ = new GameBoard(graphScene, (QObject *)this);
    ui_->graphicsView->setScene(graphScene);

}

GameWindow::~GameWindow(){
    delete ui_;
}

/*** MENU items reactions ***/
void GameWindow::on_actionNewGame_triggered(){
    board_->startNewGame();
}

void GameWindow::on_actionBeginner_triggered(){
}

void GameWindow::on_actionIntermediate_triggered(){
}

void GameWindow::on_actionAdvanced_triggered(){

}

void GameWindow::on_actionSave_triggered(){
}

void GameWindow::on_actionLoad_triggered(){

}

void GameWindow::on_actionEnd_triggered(){
    QCoreApplication::quit();
}

void GameWindow::on_actionStats_triggered(){
}

void GameWindow::okClicked(){
    int x, y, w, h;
    ui_->graphicsView->rect().getRect(&x, &y, &w, &h);
    board_->scene_->setSceneRect(QRect(x, y, w-2, h-2));
    board_->startNewGame();
}
