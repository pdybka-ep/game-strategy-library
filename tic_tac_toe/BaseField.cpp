/**
    @file   BaseField.cpp
    @author Hanna Dutkiewicz
*/

#include <iostream>
#include "BaseField.hpp"


BaseField::BaseField(): fieldState_(EMPTY){
	coordinates_ = std::make_pair<int,int>(-1,-1);
}

bool operator== (const BaseField& f1, const BaseField& f2){
	return (!f1.isEmpty() && f1.fieldState_ == f2.fieldState_);
}

bool operator!= (const BaseField& f1, const BaseField& f2){
	return (f1.fieldState_ != f2.fieldState_);
}