#pragma once
#include "Figure2D.h"
class Rectanglefig : public Figure2D {
	
	DECLARE_SERIAL(Rectanglefig)   
	
public:
	
	Rectanglefig() {}
	virtual void Draw(CDC *dc)const;
	Rectanglefig(CPoint p1, CPoint p2);
};


