#pragma once
#include "Figure2D.h"
class Ellipsefig :public Figure2D {
	
	DECLARE_SERIAL(Ellipsefig)   
	
public:
	
	Ellipsefig() {}
	
	Ellipsefig(CPoint p1, CPoint p2);
	void Draw(CDC* dc) const;
};

