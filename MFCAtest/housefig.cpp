#include "pch.h"
#include "housefig.h"

IMPLEMENT_SERIAL(housefig, CObject, 7)

housefig::housefig()
{
}

housefig::housefig(CPoint p1, CPoint p2) :Figure2D(p1, p2)
{
}

void housefig::Draw(CDC * dc) const
{
	CBrush myBrush, *oldBrush;
	CPen pen1, *oldPen;
	pen1.CreatePen(PS_SOLID, this->size_ink, RGB(0, 0, 0));
	oldPen = dc->SelectObject(&pen1);
	myBrush.CreateSolidBrush(this->color_of_fig);
	oldBrush = dc->SelectObject(&myBrush);
	CPoint p1 = getP1();
	CPoint p2 = getP2();
	CPoint parr[] = { p1,CPoint(p1.x + ((p2.x - p1.x) / 2) / 3,p1.y - abs((p2.x - p1.x) / 2)),CPoint(p1.x + (p2.x - p1.x) / (1.5),p2.y - abs((p2.x - p1.x) / 2)),p2,CPoint(p2.x,p2.y + abs((p2.x - p1.x) / 2)),     CPoint(p1.x + ((p2.x - p1.x) / 3),p1.y + abs((p2.x - p1.x) / 2))  ,  CPoint(p1.x,p1.y + abs((p2.x - p1.x) / 2)),  CPoint(p1.x + ((p2.x - p1.x) / 3),p1.y + abs((p2.x - p1.x) / 2)) ,  CPoint(p2.x,p2.y + abs((p2.x - p1.x) / 2)) ,p2 ,CPoint(p1.x + ((p2.x - p1.x) / 3),p1.y),CPoint(p1.x + ((p2.x - p1.x) / 2) / 3,p1.y - abs((p2.x - p1.x) / 2)),CPoint(p1.x + ((p2.x - p1.x) / 3),p1.y),CPoint(p1.x + ((p2.x - p1.x) / 3),p1.y + abs((p2.x - p1.x) / 2)),CPoint(p1.x + ((p2.x - p1.x) / 3),p1.y),p1,CPoint(p1.x,p1.y + abs((p2.x - p1.x) / 2)) };
	dc->Polygon(parr, 17);
	dc->SelectObject(oldBrush);
	dc->SelectObject(oldPen);
	CBrush myBrush1, *oldBrush1;
	myBrush1.CreateSolidBrush(RGB(150, 75, 0));
	oldBrush1 = dc->SelectObject(&myBrush1);
	CPoint darr[] = { CPoint(p1.x + (p1.x + ((p2.x - p1.x) / 3) - p1.x) / 3, p1.y + abs((p2.x - p1.x) / 2)),CPoint(p1.x + 2 * ((p1.x + ((p2.x - p1.x) / 3) - p1.x) / 3),p1.y + abs((p2.x - p1.x) / 2)),CPoint(p1.x + 2 * ((p1.x + ((p2.x - p1.x) / 3) - p1.x) / 3),p1.y + abs((p1.y + abs((p2.x - p1.x) / 2)) - p1.y) / 2),CPoint(p1.x + (p1.x + ((p2.x - p1.x) / 3) - p1.x) / 3,p1.y + abs((p1.y + abs((p2.x - p1.x) / 2)) - p1.y) / 2) };
	dc->Polygon(darr, 4);
	dc->SelectObject(oldBrush1);
	CBrush myBrush2, *oldBrush2;
	myBrush2.CreateSolidBrush(RGB(0, 0, 0));
	oldBrush2 = dc->SelectObject(&myBrush2);
	dc->Ellipse(p1.x + (p1.x + ((p2.x - p1.x) / 3) - p1.x) / 3, p1.y + abs(p1.y + (abs(p2.x - p1.x) / 2) - p1.y) / 1.5, (p1.x + (p1.x + ((p2.x - p1.x) / 3) - p1.x) / 3) + ((p2.x - p1.x) / 20), (p1.y + abs(p1.y + (abs(p2.x - p1.x) / 2) - p1.y) / 1.5) + (abs(p2.x - p1.x) / 20));
	dc->SelectObject(oldBrush2);
}

