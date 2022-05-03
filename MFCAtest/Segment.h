#pragma once
#include "Rectanglefig.h"
class Segment:public Rectanglefig
{
	DECLARE_SERIAL(Segment)
public:
	Segment();
	Segment(CPoint p1, CPoint p2);
	void Draw(CDC* dc) const;
	

private:

};

