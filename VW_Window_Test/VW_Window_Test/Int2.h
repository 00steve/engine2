#pragma once
class Int2{
public:
	int x;
	int y;

	Int2(int x,int y);
	~Int2();

	Int2 operator + (const int other);
	Int2 operator - (const int other);

};

