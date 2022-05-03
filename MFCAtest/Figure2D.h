#pragma once
#include "pch.h"
#include<math.h>
class Figure2D : public CObject {
	
	DECLARE_SERIAL(Figure2D)    
	
	CPoint P1;
	CPoint P2;
	COLORREF color_of_fig;
	int size_ink = 3;
public:
	
	Figure2D() {}
	Figure2D(CPoint point1, CPoint point2) :P1(point1), P2(point2)	{	}
	void Serialize(CArchive& ar);
	virtual void Draw(CDC *dc)const {}
	void setcolor(COLORREF newcolor);
	COLORREF getcolor();
	void setsizeink(int size);
	int getsizeink();
	CPoint getP1() const
	{
		return P1;
	}
	CPoint getP2() const
	{
		return P2;
	}
	virtual void Redefine(CPoint p1, CPoint p2) { P1 = p1; P2 = p2; }

};

