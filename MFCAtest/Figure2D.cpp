#include "pch.h"  //!!! 1st include
#include "Figure2D.h"


IMPLEMENT_SERIAL(Figure2D, CObject, 1)





void Figure2D::Serialize(CArchive& ar)
{
	CObject::Serialize(ar);
	if (ar.IsStoring())
	{
		ar << P1;
		ar << P2;
		ar << color_of_fig;
		ar << size_ink;
	}
	else 
	{
		ar >> P1;
		ar >> P2;
		ar >> color_of_fig;
		ar >> size_ink;

	}
}
void Figure2D::setcolor(COLORREF newcolor) 
{
	this->color_of_fig = newcolor;
}
COLORREF Figure2D::getcolor()
{
	return this->color_of_fig;
}
void Figure2D::setsizeink(int size)
{
	this->size_ink = size;
}
int Figure2D::getsizeink()
{
	return this->size_ink;
}



