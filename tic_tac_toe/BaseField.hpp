/**
    @file   BaseField.hpp
    @author Hanna Dutkiewicz
*/

#ifndef BASEFIELD_H
#define BASEFIELD_H

#include <iostream>

class BaseField;
bool operator== (const BaseField&, const BaseField&);
bool operator!= (const BaseField&, const BaseField&);

/**
	@class BaseField
	@author Hanna Dutkiewicz
	Class of a base field of TicTacToe game
*/
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

	/**
		Default constructor
	*/
	BaseField();

	/**
		Virtual destructor
	*/
	virtual ~BaseField(){}

	/**
		Friend function that compares two BaseFields. 
		Two BaseFields are equal only if they have the same FieldState
		@param b1 first BaseField to compare
		@param b2 second BaseField to compare
		@return <code>true</code> if fields are equal, <code>false</code> otherwhise
	*/
	friend bool operator== (const BaseField& b1, const BaseField& b2);
	
	/**
		Friend function that checks if two BaseFields are not equal
		@param b1 first BaseField to compare
		@param b2 second BaseField to compare
		@return <code>true</code> if fields are NOT equal, <code>false</code> otherwhise
	*/
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

	/**
		Returns coordinates of a field
		@return coordinates of a field
	*/
	std::pair<int,int> getCoordinates() const{
		return coordinates_;
	}

	/**
		Sets coordinates of a field
		@param coordinates coordinates of a field
	*/
	void setCoordinates(const std::pair<int,int> coordinates){
		coordinates_ = coordinates;
	}

	/**
		Checks if a field is empty (has no circle nor cross on it)
		@return <code>true</code> if a field is empty, <code>false</code> otherwhise
	*/
	bool isEmpty() const{
		return (fieldState_ == EMPTY);
	}


protected:
	/** State of the field. */
    FieldState fieldState_;

	/** Coordinates of a field on a game board of TicTacToe game */
	std::pair<int,int> coordinates_;
};


#endif