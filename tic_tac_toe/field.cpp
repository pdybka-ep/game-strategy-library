/**
    field.cpp
    Author: Hanna Dutkiewicz
*/

#include <QPainter>
#include <QPen>
#include "field.hpp"

Field::Field(QObject * parent): QObject(parent), fieldState_(EMPTY){

    setFlags(QGraphicsItem::ItemIsSelectable);
    setFlags(QGraphicsItem::ItemIsFocusable);
    setAcceptedMouseButtons(Qt::LeftButton);

    circleImage_.load(":/res/circle.png");
    crossImage_.load(":/res/cross.png");
}

Field::~Field(){

}

void Field::paint(QPainter *painter, const QStyleOptionGraphicsItem *opt, QWidget *w){
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

void Field::init(QSizeF size, QPointF startPoint){
    size_ = size;
    startPoint_ = startPoint;
}

void Field::mousePressEvent (QGraphicsSceneMouseEvent * event){
    if(fieldState_ == EMPTY)
        wasClicked();
}
