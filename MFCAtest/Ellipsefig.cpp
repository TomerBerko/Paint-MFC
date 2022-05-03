#include "pch.h"
#include "Ellipsefig.h"


IMPLEMENT_SERIAL(Ellipsefig, CObject, 2)


Ellipsefig::Ellipsefig(CPoint p1, CPoint p2)
	:Figure2D(p1, p2)
{
}
void Ellipsefig::Draw(CDC* dc) const
{
	CBrush myBrush, * oldBrush;
	CPen pen1, * oldPen;
	pen1.CreatePen(PS_SOLID, this->size_ink, RGB(0,0,0));
	oldPen = dc->SelectObject(&pen1);
		                        
	myBrush.CreateSolidBrush(this->color_of_fig);
	oldBrush = dc->SelectObject(&myBrush);
		
	CPoint p1 = getP1();
	CPoint p2 = getP2();
	dc->Ellipse(p1.x, p1.y, p2.x, p2.y);
	dc->SelectObject(oldBrush);
	dc->SelectObject(oldPen);
	
}
