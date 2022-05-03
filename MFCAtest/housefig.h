#pragma once
#include "Figure2D.h"
class housefig :public Figure2D
{
	DECLARE_SERIAL(housefig)
public:
	housefig();
	housefig(CPoint p1, CPoint p2);
	void Draw(CDC* dc) const;

};