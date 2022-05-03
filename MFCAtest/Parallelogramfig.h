#pragma once
#include"Rectanglefig.h"
class Parallelogramfig:public Rectanglefig
{
	DECLARE_SERIAL(Parallelogramfig)
public:
	Parallelogramfig();
	Parallelogramfig(CPoint p1, CPoint p2);
	void Draw(CDC* dc) const;

	

private:

};

