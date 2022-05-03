#include "pch.h"
#include "Parallelogramfig.h"

IMPLEMENT_SERIAL(Parallelogramfig, CObject, 6)

Parallelogramfig::Parallelogramfig()
{
}

Parallelogramfig::Parallelogramfig(CPoint p1, CPoint p2):Rectanglefig(p1,p2)
{
}

void Parallelogramfig::Draw(CDC * dc) const
{
	CBrush myBrush, *oldBrush;
	CPen pen1, *oldPen;
	pen1.CreatePen(PS_SOLID, this->size_ink, RGB(0, 0, 0));
	oldPen = dc->SelectObject(&pen1);
	myBrush.CreateSolidBrush(this->color_of_fig);
	oldBrush = dc->SelectObject(&myBrush);
	CPoint p1 = getP1();
	CPoint p2 = getP2();
	if (p2.x >= p1.x) 
	{
	CPoint parr[] = { p1,CPoint(p2.x - sqrt(p2.x * 2),p1.y),p2,CPoint(p1.x + sqrt(p2.x * 2),p2.y) };
	dc->Polygon(parr, 4);
	}
	else
	{
		CPoint parr[] = { p1,CPoint(p2.x - sqrt(p1.x * 2),p1.y),p2,CPoint(p1.x + sqrt(p1.x * 2),p2.y) };
		dc->Polygon(parr, 4);
	}
	dc->SelectObject(oldBrush);
	dc->SelectObject(oldPen);
}
