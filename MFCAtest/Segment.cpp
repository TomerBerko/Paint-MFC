#include "pch.h"
#include "Segment.h"

IMPLEMENT_SERIAL(Segment, CObject, 3)
Segment::Segment()
{
}

Segment::Segment(CPoint p1, CPoint p2):Rectanglefig(p1,p2)
{
}

void Segment::Draw(CDC * dc) const
{
	if (color_of_fig == RGB(255, 255, 255))
	{
		CPen pen1, *oldPen;
		pen1.CreatePen(PS_SOLID, this->size_ink, RGB(0,0,0));
		oldPen = dc->SelectObject(&pen1);
		CPoint p1 = getP1();
		CPoint p2 = getP2();
		dc->MoveTo(p1);
		dc->LineTo(p2);
		dc->SelectObject(oldPen);
	}
	else
	{
		CPen pen1, *oldPen;
		pen1.CreatePen(PS_SOLID, this->size_ink, this->color_of_fig);
		oldPen = dc->SelectObject(&pen1);
		CPoint p1 = getP1();
		CPoint p2 = getP2();
		dc->MoveTo(p1);
		dc->LineTo(p2);
		dc->SelectObject(oldPen);
	}
}
