#include "pch.h"
#include "RoundRectfig.h"
IMPLEMENT_SERIAL(RoundRectfig, CObject, 4)
RoundRectfig::RoundRectfig()
{
}

RoundRectfig::RoundRectfig(CPoint p1, CPoint p2) :Rectanglefig(p1, p2)
{
}

void RoundRectfig::Draw(CDC * dc) const
{
	CBrush myBrush, *oldBrush;
	CPen pen1, *oldPen;
	pen1.CreatePen(PS_SOLID, this->size_ink, RGB(0, 0, 0));
	oldPen = dc->SelectObject(&pen1);
	myBrush.CreateSolidBrush(this->color_of_fig);
	oldBrush = dc->SelectObject(&myBrush);
	CPoint p1 = getP1();
	CPoint p2 = getP2();
	dc->RoundRect(p1.x, p1.y, p2.x, p2.y,40, 40);
	dc->SelectObject(oldBrush);
	dc->SelectObject(oldPen);
}
