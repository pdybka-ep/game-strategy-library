/**
    @file   Field.hpp
    @author Hanna Dutkiewicz
*/

#ifndef FIELD_H
#define FIELD_H

#include <QObject>
#include <QGraphicsItem>

#include "BaseField.hpp"

/**
    @class Field Class
    Represents a single field on a game board, one of the GUI classes, GUI representation of BaseField
    @author Hanna Dutkiewicz
  */
class Field : public QObject, public QGraphicsItem, public BaseField{
    Q_OBJECT

public:
    /**
		A contstructor.
		@param parent field's parent (in this case it should be a GameBoard object)
     */
	Field(QObject * parent = 0);

	Field(const Field & field);
    /**
		A destructor.
	*/
    ~Field();

	/**
		Copy constructor
		@param f field to be copied
		@return copied field
	*/
	Field& operator= (const Field& f);

    /**
		Method ovverides default paint method for QGraphicsItem objects. It paints appropriate image depending on fieldState_.
		@param painter pointer to QPainter object
		@param pointer to QStyleOptionGraphicsItem object
		@param pointer to QWidget object
    */
    void paint(QPainter * painter, const QStyleOptionGraphicsItem *, QWidget *);

    /**
		Initialize size and top left point of a Field object on a GameBoard.
		@param size size of this object
		@param startPoint top left position point
		@param x
		@param y
    */
    void init(QSizeF size, QPointF startPoint, int x, int y);

    /**
		Method ovverides default one to handle mouse press events.
		It generates signal wasClicked.
		@param event pointer to a QGraphicsSceneMouseEvent
		@see wasClicked()
	*/
    void mousePressEvent (QGraphicsSceneMouseEvent * event);

    /**
		It returns a bounding rectangle of an object.
		@return bounding rectangle
    */
    QRectF boundingRect() const{
        return QRectF(startPoint_.x(), startPoint_.y(), size_.width(), size_.height());
    }

	/**
		Sets field state and updates field
		@param newState new state of the field
	*/	
	void setFieldState(FieldState newState) {   
		fieldState_ = newState; update(); 
	}
/*
	friend bool operator== (const Field&, const Field&);
	friend bool operator!= (const Field&, const Field&);
*/
	

/********* SIGNALS *********/
signals:
    /**
		Signal generated when a field was clicked (only if fieldState_ == EMPTY).
		It is generated to notify GameBoard that this particular field was clicked.
		@see mousePressEvent()
    */
    void wasClickedSignal();


private:
    /** Size of a field object. */
    QSizeF size_;
    /** Top left point of object's position. */
    QPointF startPoint_;
    /** Image of a circle field. */
    QImage circleImage_;
    /** Image of a cross field. */
    QImage crossImage_;
};

#endif // FIELD_H
