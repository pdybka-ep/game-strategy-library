/**
    @file   field.cpp
    @author Hanna Dutkiewicz
*/

#include <QPainter>
#include <QPen>
#include "field.hpp"

/* Represents a single field on a game board. One of GUI classes. */
Field::Field(QObject * parent): QObject(parent), fieldState_(EMPTY){

    setFlags(QGraphicsItem::ItemIsSelectable);
    setFlags(QGraphicsItem::ItemIsFocusable);
    setAcceptedMouseButtons(Qt::LeftButton);

    circleImage_.load(":/res/circle.png");
    crossImage_.load(":/res/cross.png");
}

/* A destructor. */
Field::~Field(){

}

/* Method ovverides default paint method for QGraphicsItem objects. It paints appropriate image depending on fieldState_. */
void Field::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
/*
    QBrush brush;
    brush.setColor(Qt::blue);
    painter->setBrush(brush);
    painter->setRenderHint(QPainter::Antialiasing, true);

    painter->drawRect(rect);
*/
    QRectF rect(startPoint_.rx(), startPoint_.ry(), size_.width(), size_.height());

    if(fieldState_ == EMPTY)
        return;
    else if(fieldState_ == CIRCLE)
        painter->drawImage(rect, circleImage_);
    else if(fieldState_ == CROSS)
        painter->drawImage(rect, crossImage_);

}

/* Initialize size and top left point of a Field object on a GameBoard.*/
void Field::init(QSizeF size, QPointF startPoint, int x, int y){
    size_ = size;
    startPoint_ = startPoint;
	coordinates_ = std::make_pair<int,int>(x,y);
}

/* Method ovverides default one to handle mouse press events. */
void Field::mousePressEvent (QGraphicsSceneMouseEvent * ){
    if(fieldState_ == EMPTY)
        wasClickedSignal();
}