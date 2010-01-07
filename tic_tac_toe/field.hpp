/**
    @file   field.hpp
    @author Hanna Dutkiewicz
*/

#ifndef FIELD_H
#define FIELD_H

#include <QObject>
#include <QGraphicsItem>

/**
    @class Field Class
    Represents a single field on a game board.
    One of the GUI classes.
    @author Hanna Dutkiewicz
  */
class Field : public QObject, public QGraphicsItem{
    Q_OBJECT
    Q_ENUMS(FieldState)

public:
    /**
      @enum FieldState
      State of the field. It represents what is on the field of a game board.
      */
    enum FieldState {
        /** an empty field */
        EMPTY,
        /** field with a circle on it */
        CIRCLE,
        /** field with a cross on it */
        CROSS,
        /** state of the field after game is finished, a circle crossed because of the victory */
        CIRCLE_FINISH,
        /** state of the field after game is finished, a cross crossed because of the victory */
        CROSS_FINISH
    };


/********* PROPERTIES *********/
private:
    Q_PROPERTY(FieldState fieldState_ READ getFieldState WRITE setFieldState)
public:
    /**
      Getter of a fieldState_ field.
      @return state of the field (a FieldState)
      */
    FieldState getFieldState() const {  return fieldState_; }
    /**
      Setter of a fieldState_ field.
      @param newState new state of the field (eg. when circle was "put" on the field)
      */
    void setFieldState(FieldState newState) {   fieldState_ = newState; update(); }



/********* PUBLIC METHODS *********/
public:
    /**
      A contstructor.
      @param parent field's parent (in this case it should be a GameBoard object)
      */
    Field(QObject * parent = 0);
    /**
      A destructor.
      */
    ~Field();

    /**
      Method ovverides default paint method for QGraphicsItem objects. It paints appropriate image depending on fieldState_.
      @param painter pointer to QPainter object
      @param opt pointer to QStyleOptionGraphicsItem object
      @param w pointer to QWidget object
    */
    void paint(QPainter *, const QStyleOptionGraphicsItem *, QWidget *);

    /**
      Initialize size and top left point of a Field object on a GameBoard.
      @param size size of this object
      @param startPoint top left position point
      */
    void init(QSizeF size, QPointF startPoint);

    /**
      Method ovverides default one to handle mouse press events.
      It generates signal wasClicked.
      @param event pointer to QGraphicsSceneMouseEvent
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



/********* SIGNALS *********/
signals:
    /**
      Signal generated when a field was clicked (only if fieldState_ == EMPTY).
      It is generated to notify GameBoard that this particular field was clicked.
      @see mousePressEvent()
    */
    void wasClicked();



/********* PRIVATE FIELDS *********/
private:
    /** Size of a field object. */
    QSizeF size_;
    /** Top left point of object's position. */
    QPointF startPoint_;
    /** Image of a circle field. */
    QImage circleImage_;
    /** Image of a cross field. */
    QImage crossImage_;
    /** State of the field. */
    FieldState fieldState_;


};

#endif // FIELD_H
