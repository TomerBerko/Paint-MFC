#pragma once
#include "Figure2D.h"
class Triangularfig :public Figure2D
{
	DECLARE_SERIAL(Triangularfig)
	
public:

	Triangularfig();
	Triangularfig(CPoint p1, CPoint p2);
	void Draw(CDC* dc) const;
	

private:

};

