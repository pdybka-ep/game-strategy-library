/**
    @file   field.cpp
    @author Hanna Dutkiewicz
*/

#include <QPainter>
#include <QPen>
#include <QString>

#include "field.hpp"

/* Represents a single field on a game board. One of GUI classes. */
Field::Field(QObject * parent): QObject(parent), QGraphicsItem(), BaseField(){

    setFlags(QGraphicsItem::ItemIsSelectable);
    setFlags(QGraphicsItem::ItemIsFocusable);
    setAcceptedMouseButtons(Qt::LeftButton);

	coordinates_ = std::make_pair<int,int>(-1,-1);

    circleImage_.load(QString(":/res/circle.png"));
    crossImage_.load(QString(":/res/cross.png"));
}

Field::Field(const Field & field): QObject(), QGraphicsItem(), BaseField(){
	*this = field;
}

Field& Field::operator= (const Field& field){
	if(this == &field)
		return *this;

	setParent(field.parent());

	fieldState_ = field.fieldState_;
	coordinates_ = field.coordinates_;
	size_ = field.size_;
    startPoint_ = field.startPoint_;
	circleImage_ = field.circleImage_;
	crossImage_ = field.crossImage_;

	setFlags(QGraphicsItem::ItemIsSelectable);
    setFlags(QGraphicsItem::ItemIsFocusable);
    setAcceptedMouseButtons(Qt::LeftButton);

	return *this;
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
/*
bool operator== (const Field& f1, const Field& f2){
	return (!f1.isEmpty() && f1.fieldState_ == f2.fieldState_);
}

bool operator!= (const Field& f1, const Field& f2){
	return (f1.fieldState_ != f2.fieldState_);
}
*/
