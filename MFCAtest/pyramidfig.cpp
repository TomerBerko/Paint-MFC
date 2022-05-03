#include "pch.h"
#include "pyramidfig.h"

IMPLEMENT_SERIAL(pyramidfig, CObject, 8)

pyramidfig::pyramidfig()
{
}

pyramidfig::pyramidfig(CPoint p1, CPoint p2):Triangularfig(p1,p2)
{
}

void pyramidfig::Draw(CDC * dc) const
{
	CBrush myBrush, *oldBrush;
	CPen pen1, *oldPen;
	pen1.CreatePen(PS_SOLID, this->size_ink, RGB(0, 0, 0));
	oldPen = dc->SelectObject(&pen1);
	myBrush.CreateSolidBrush(this->color_of_fig);
	oldBrush = dc->SelectObject(&myBrush);
	CPoint p1 = getP1();
	CPoint p2 = getP2();
	
	CPoint parr[] = { p1,p2,CPoint(p2.x + (p2.x - p1.x) / 4,p2.y - abs(p2.x - p1.x) / 3),CPoint(p2.x - (p2.x - p1.x) / 4,p2.y - abs(p2.x - p1.x) / 1.5) };
	dc->Polygon(parr, 4);
	CPoint barr[] = { p2,CPoint(p2.x - (p2.x - p1.x) / 4,p2.y - abs(p2.x - p1.x) / 1.5) };
	dc->Polygon(barr, 2);
	
	dc->SelectObject(oldBrush);
	dc->SelectObject(oldPen);
}
