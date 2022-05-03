#pragma once
#include "Triangularfig.h"
class pyramidfig:public Triangularfig
{
	DECLARE_SERIAL(pyramidfig)
public:
	pyramidfig();
	pyramidfig(CPoint p1, CPoint p2);
	void Draw(CDC* dc) const;
	

private:

};

