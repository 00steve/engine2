#include "stdafx.h"
#include "Int2.h"


Int2::Int2(int x,int y) : x(x),y(y) {

}


Int2::~Int2(){
}

Int2 Int2::operator+(const int other){
	return Int2(x + other,y + other);
}

Int2 Int2::operator-(const int other){
	return Int2(x - other,y - other);
}
