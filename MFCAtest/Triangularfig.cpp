#include "pch.h"
#include "Triangularfig.h"


IMPLEMENT_SERIAL(Triangularfig, CObject,5)
Triangularfig::Triangularfig()
{
}

Triangularfig::Triangularfig(CPoint p1, CPoint p2):Figure2D(p1, p2)
{
}

void Triangularfig::Draw(CDC * dc) const
{
	CBrush myBrush, *oldBrush;
	CPen pen1, *oldPen;
	pen1.CreatePen(PS_SOLID, this->size_ink, RGB(0, 0, 0));
	oldPen = dc->SelectObject(&pen1);
	myBrush.CreateSolidBrush(this->color_of_fig);
	oldBrush = dc->SelectObject(&myBrush);
	CPoint p1 = getP1();
	CPoint p2 = getP2();



	CPoint parr[] = { p1,p2,CPoint(p1.x-(p2.x-p1.x),p2.y) };
		dc->Polygon(parr, 3);
		
	

	dc->SelectObject(oldBrush);
	dc->SelectObject(oldPen);

	
}
