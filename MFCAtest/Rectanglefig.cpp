#include "pch.h"
#include "Rectanglefig.h"



IMPLEMENT_SERIAL(Rectanglefig, CObject, 9)


void Rectanglefig::Draw(CDC * dc) const
{
	CBrush myBrush, *oldBrush;
	CPen pen1, *oldPen;
	pen1.CreatePen(PS_SOLID, this->size_ink, RGB(0, 0, 0));
	oldPen = dc->SelectObject(&pen1);
	myBrush.CreateSolidBrush(this->color_of_fig);
	oldBrush = dc->SelectObject(&myBrush);
	dc->Rectangle(P1.x, P1.y, P2.x, P2.y);
	dc->SelectObject(oldBrush);
	dc->SelectObject(oldPen);
}

Rectanglefig::Rectanglefig(CPoint p1, CPoint p2):Figure2D(p1, p2)
{
}
