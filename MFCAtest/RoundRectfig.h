#pragma once
#include"Rectanglefig.h"
class RoundRectfig:public Rectanglefig
{
	DECLARE_SERIAL(RoundRectfig)
public:
	RoundRectfig();
	RoundRectfig(CPoint p1, CPoint p2);
	void Draw(CDC* dc) const;


private:

};

