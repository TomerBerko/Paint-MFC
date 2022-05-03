
// MFCAtestDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "MFCAtest.h"
#include "MFCAtestDlg.h"
#include "afxdialogex.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCAtestDlg dialog



CMFCAtestDlg::CMFCAtestDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCATEST_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCAtestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, savebtn, save);
	DDX_Control(pDX, loadbtn, load);
	DDX_Control(pDX, Rectanglefigbtn, Rectanglefigb);
	DDX_Control(pDX, Ellipsefigbtn, Ellipsefigb);
	DDX_Control(pDX, lineb, linefig);
	DDX_Control(pDX, RoundRectb, RoundRectang);
	DDX_Control(pDX, Triangularb, Triangularbt);
	DDX_Control(pDX, Parallelogrambtn, Parallelogrambt);
	DDX_Control(pDX, clearbtn, clearbt);

	DDX_Control(pDX, combocolor, combocolorbt);
	DDX_Control(pDX, combowidth, combowidthbt);
	DDX_Control(pDX, undobtn, undobt);
	DDX_Control(pDX, sentenslinewidth, statictextline);
	DDX_Control(pDX, staticcolortxt, statictxtcolor);
	DDX_Control(pDX, redobtn, redobt);
	DDX_Control(pDX, housebtn, housebt);
	DDX_Control(pDX, pyramidfigbtn, pyramidfigbt);
}

BEGIN_MESSAGE_MAP(CMFCAtestDlg, CDialogEx)
	
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	
	
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(savebtn, &CMFCAtestDlg::OnBnClickedsavebtn)
	ON_BN_CLICKED(loadbtn, &CMFCAtestDlg::OnBnClickedloadbtn)
	ON_BN_CLICKED(Rectanglefigbtn, &CMFCAtestDlg::OnBnClickedRectanglefigbtn)
	ON_BN_CLICKED(Ellipsefigbtn, &CMFCAtestDlg::OnBnClickedEllipsefigbtn)
	ON_BN_CLICKED(lineb, &CMFCAtestDlg::OnBnClickedlineb)
	ON_BN_CLICKED(RoundRectb, &CMFCAtestDlg::OnBnClickedRoundrectb)
	ON_BN_CLICKED(Triangularb, &CMFCAtestDlg::OnBnClickedTriangularb)
	ON_BN_CLICKED(Parallelogrambtn, &CMFCAtestDlg::OnBnClickedParallelogrambtn)
	ON_BN_CLICKED(clearbtn, &CMFCAtestDlg::OnBnClickedclearbtn)
	
	ON_CBN_SELCHANGE(combocolor, &CMFCAtestDlg::OnCbnSelchangecombocolor)
	ON_CBN_SELCHANGE(combowidth, &CMFCAtestDlg::OnCbnSelchangecombowidth)
	ON_BN_CLICKED(undobtn, &CMFCAtestDlg::OnBnClickedundobtn)
	ON_BN_CLICKED(redobtn, &CMFCAtestDlg::OnBnClickedredobtn)
	ON_BN_CLICKED(housebtn, &CMFCAtestDlg::OnBnClickedhousebtn)
	ON_BN_CLICKED(pyramidfigbtn, &CMFCAtestDlg::OnBnClickedpyramidfigbtn)
END_MESSAGE_MAP()


// CMFCAtestDlg message handlers

BOOL CMFCAtestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCAtestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CPaintDC dc(this);
		int i;// device context for painting
		for ( i = 0; i < figs.GetSize(); i++)
		{
			figs[i]->Draw(&dc);
		}
		
		
		CDialogEx::OnPaint();
	}
}



void CMFCAtestDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	start = point;
	isPressed = true;
	
	switch (futureFigureKind)
	{
	case 0:break;
	case 1:
		figs.Add(new Rectanglefig(start, start));
		figs[(figs.GetSize()) - 1]->setcolor(futurecolor);
		figs[(figs.GetSize()) - 1]->setsizeink(size_of_line);
		temp.RemoveAll();
		break;
	case 2:
		figs.Add(new Ellipsefig(start, start));
		figs[(figs.GetSize()) - 1]->setcolor(futurecolor);
		figs[(figs.GetSize()) - 1]->setsizeink(size_of_line);
		temp.RemoveAll();
		break;

	case 3:
		figs.Add(new Segment(start, start));
		figs[(figs.GetSize()) - 1]->setcolor(futurecolor);
		figs[(figs.GetSize()) - 1]->setsizeink(size_of_line);
		temp.RemoveAll();
		break;
	case 4:
		figs.Add(new RoundRectfig(start, start));
		figs[(figs.GetSize()) - 1]->setcolor(futurecolor);
		figs[(figs.GetSize()) - 1]->setsizeink(size_of_line);
		temp.RemoveAll();
		break;
	case 5:
		figs.Add(new Triangularfig(start, start));
		figs[(figs.GetSize()) - 1]->setcolor(futurecolor);
		figs[(figs.GetSize()) - 1]->setsizeink(size_of_line);
		temp.RemoveAll();
		break;
	case 6:
		figs.Add(new Parallelogramfig(start, start));
		figs[(figs.GetSize()) - 1]->setcolor(futurecolor);
		figs[(figs.GetSize()) - 1]->setsizeink(size_of_line);
		temp.RemoveAll();
		break;	
	case 7:
		figs.Add(new housefig(start, start));
		figs[(figs.GetSize()) - 1]->setcolor(futurecolor);
		figs[(figs.GetSize()) - 1]->setsizeink(size_of_line);
		temp.RemoveAll();
		break;
	case 8:
		figs.Add(new pyramidfig(start, start));
		figs[(figs.GetSize()) - 1]->setcolor(futurecolor);
		figs[(figs.GetSize()) - 1]->setsizeink(size_of_line);
		temp.RemoveAll();
		break;
	}

	
	CDialogEx::OnLButtonDown(nFlags, point);
}


void CMFCAtestDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	if (isPressed)
	{
		end = point;
		isPressed = false;
		figs[figs.GetSize() - 1]->Redefine(start, end);
		Invalidate(); 
	}
	CDialogEx::OnLButtonUp(nFlags, point);
}


void CMFCAtestDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (isPressed)
	{
		end = point;
		figs[figs.GetSize() - 1]->Redefine(start, end);
		Invalidate(); 
	}
	CDialogEx::OnMouseMove(nFlags, point);
}



// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCAtestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCAtestDlg::OnBnClickedsavebtn()
{
	// TODO: Add your control notification handler code here
	CFileDialog dlg(FALSE, _T(".figs"), NULL, 0, _T("Figure2D (*.figs)|*.figs|All Files (*.*)|*.*||"));
	CString filename;
	if (dlg.DoModal() == IDOK)
	{
		filename = dlg.GetPathName(); 
		CFile file(filename, CFile::modeCreate | CFile::modeWrite);
		CArchive ar(&file, CArchive::store);
		figs.Serialize(ar);
		ar.Close();
		file.Close();
	}


	
}


void CMFCAtestDlg::OnBnClickedloadbtn()
{
	// TODO: Add your control notification handler code here
	CFileDialog dlg(TRUE, _T(".figs"), NULL, 0, _T("Figure2D (*.figs)|*.figs|All Files (*.*)|*.*||"));
	CString filename;
	if (dlg.DoModal() == IDOK)
	{
		filename = dlg.GetPathName(); 
		CFile file(filename, CFile::modeRead);
		CArchive ar(&file, CArchive::load);
		figs.Serialize(ar);
		ar.Close();
		file.Close();
		Invalidate();
	}

}


void CMFCAtestDlg::OnBnClickedRectanglefigbtn()
{
	// TODO: Add your control notification handler code here
	futureFigureKind = 1;

}


void CMFCAtestDlg::OnBnClickedEllipsefigbtn()
{
	// TODO: Add your control notification handler code here
	futureFigureKind = 2;
}


void CMFCAtestDlg::OnBnClickedlineb()
{
	// TODO: Add your control notification handler code here
	futureFigureKind = 3;
}


void CMFCAtestDlg::OnBnClickedRoundrectb()
{
	// TODO: Add your control notification handler code here
	futureFigureKind = 4;
}


void CMFCAtestDlg::OnBnClickedTriangularb()
{
	// TODO: Add your control notification handler code here
	futureFigureKind = 5;
	
}


void CMFCAtestDlg::OnBnClickedParallelogrambtn()
{
	// TODO: Add your control notification handler code here
	futureFigureKind = 6;
		
}


void CMFCAtestDlg::OnBnClickedclearbtn()
{
	// TODO: Add your control notification handler code here
	figs.RemoveAll();
	Invalidate();
}





void CMFCAtestDlg::OnCbnSelchangecombocolor()
{
	int idx = combocolorbt.GetCurSel();
	if (idx < 0)
		return;
	CString temp;
	combocolorbt.GetLBText(idx, temp);

	// TODO: Add your control notification handler code here
	if (temp=="blue")
	{
		futurecolor = RGB(0, 0, 255);
	}
	else if (temp=="red")
	{
		futurecolor = RGB(255, 0, 0);
	}
	else if (temp == "black")
	{
		futurecolor = RGB(0, 0, 0);

	}
	else if (temp == "yellow")
	{
		futurecolor = RGB(255, 255, 0);

	}
	else if (temp == "green")
	{
		futurecolor = RGB(0, 255, 0);

	}
	else if (temp == "white")
	{
		futurecolor = RGB(255, 255, 255);
	}
	else if (temp == "pink")
	{
		futurecolor = RGB(255, 192, 203);
	}
	else if (temp == "gray")
	{
		futurecolor = RGB(128, 128, 128);
	}
	else if (temp == "brown")
	{

		futurecolor = RGB(150, 75, 0);
	}


}


void CMFCAtestDlg::OnCbnSelchangecombowidth()
{
	// TODO: Add your control notification handler code here
	int idx = combowidthbt.GetCurSel();
	if (idx < 0)
		return;
	CString temp;
	combowidthbt.GetLBText(idx, temp);

	if (temp == '1')
	{
		size_of_line = 1;
	}
	else if(temp=='2')
	{
		size_of_line = 2;
	}
	else if (temp =='3' )
	{
		size_of_line =3;
	}
	else if (temp == '4')
	{
		size_of_line = 5;
	}
	else if (temp == '5')
	{
		size_of_line = 8;
	}
	else if (temp == '6')
	{
		size_of_line = 10;
	}
	else if (temp == '7')
	{
		size_of_line = 12;
	}
	else if (temp == '8')
	{
		size_of_line = 15;
	}
	else if (temp == '9')
	{
		size_of_line = 17;
	}
}


void CMFCAtestDlg::OnBnClickedundobtn()
{
	// TODO: Add your control notification handler code here
	if (figs.GetSize() != 0)
	{
		temp.Add(figs[figs.GetSize() - 1]);
		figs.RemoveAt((figs.GetSize()) - 1);
		Invalidate();
	}
	else
		return;
}


void CMFCAtestDlg::OnBnClickedredobtn()
{
	// TODO: Add your control notification handler code here

	if (temp.GetSize() != 0)
	{
		figs.Add(temp[temp.GetSize() - 1]);
		temp.RemoveAt((temp.GetSize()) - 1);
		Invalidate();
	}
	else
		return;
}


void CMFCAtestDlg::OnBnClickedhousebtn()
{
	// TODO: Add your control notification handler code here
	futureFigureKind = 7;
}


void CMFCAtestDlg::OnBnClickedpyramidfigbtn()
{
	// TODO: Add your control notification handler code here
	futureFigureKind = 8;
}
