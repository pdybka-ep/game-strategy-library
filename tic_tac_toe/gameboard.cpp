/**
    gameboard.cpp
    Author: Hanna Dutkiewicz
*/
#include <QBrush>
#include <QImage>
#include <QGraphicsScene>
#include "gameboard.hpp"
#include "field.hpp"

GameBoard::GameBoard(QGraphicsScene * scene, QObject * parent): QObject(parent), field_(NULL), scene_(scene) {
    QImage backIm(":/res/tlo.bmp");
    scene_->setBackgroundBrush(QBrush(Qt::black));
    
}

GameBoard::~GameBoard(){

}

void GameBoard::startNewGame(){

    // clear the game board
    clear();

    // create new fields
    field_ = new Field * [MAX_IN_A_ROW];

    for(int i = 0; i < MAX_IN_A_ROW; ++i)
       field_[i] = new Field[MAX_IN_A_ROW];

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
            field_[i][j].init(QSizeF(oneFieldSize, oneFieldSize), startPoint);
            scene_->addItem(&field_[i][j]);

            // connect fields with game board
            connect((&field_[i][j]), SIGNAL(wasClicked()), this, SLOT(fieldWasClicked()));

            if(j > 0 && i == 0)
                scene_->addLine(startPoint.x(), startPoint.y(), startPoint.x(), startPoint.y()+(MAX_IN_A_ROW)*oneFieldSize, rectPen);
            startPoint.setX(startPoint.x()+oneFieldSize);
        }
        startPoint.setX(startPoint.x()-oneFieldSize*(MAX_IN_A_ROW));
        startPoint.setY(startPoint.y()+oneFieldSize);
    }

}

void GameBoard::endGame(){

}

void GameBoard::fieldWasClicked(){
    // here - check which player is this turn and set fields state to current player's symbol
    Field * field = (Field *)scene_->focusItem();
    field->setFieldState(Field::CROSS);

}

void GameBoard::clear(){

    if(field_ != NULL){
        for(int i = 0; i < MAX_IN_A_ROW; ++i)
            delete [] field_[i];
        delete [] field_;
    }
    scene_->clear();
}
