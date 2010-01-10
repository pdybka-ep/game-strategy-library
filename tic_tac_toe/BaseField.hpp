/**
    @file   field.hpp
    @author Hanna Dutkiewicz
*/

#ifndef BASEFIELD_H
#define BASEFIELD_H

#include <iostream>

class BaseField;
bool operator== (const BaseField&, const BaseField&);
bool operator!= (const BaseField&, const BaseField&);


class BaseField{

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
        CROSS
    };

	BaseField();

	virtual ~BaseField(){}

	friend bool operator== (const BaseField&, const BaseField&);
	friend bool operator!= (const BaseField&, const BaseField&);

	/**
      Getter of a fieldState_ field.
      @return state of the field (a FieldState)
      */
    FieldState getFieldState() const {  return fieldState_; }
    /**
      Setter of a fieldState_ field.
      @param newState new state of the field (eg. when circle was "put" on the field)
      */
    virtual void setFieldState(FieldState newState) {   fieldState_ = newState; }

	std::pair<int,int> getCoordinates() const{
		return coordinates_;
	}

	void setCoordinates(const std::pair<int,int> coordinates){
		coordinates_ = coordinates;
	}

	bool isEmpty() const{
		return (fieldState_ == EMPTY);
	}


protected:
	/** State of the field. */
    FieldState fieldState_;

	std::pair<int,int> coordinates_;

};


#endif