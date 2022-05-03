
// MFCAtestDlg.h : header file
//

#pragma once
#include "Figure2D.h"
#include "Rectanglefig.h"
#include "Ellipsefig.h"
#include "Segment.h"
#include "RoundRectfig.h"
#include"Triangularfig.h"
#include "Parallelogramfig.h"
#include"housefig.h"
#include "pyramidfig.h"


// CMFCAtestDlg dialog
class CMFCAtestDlg : public CDialogEx
{
// Construction
public:
	CMFCAtestDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCATEST_DIALOG };
#endif
	CPoint start, end;
	bool isPressed = false;
	COLORREF futurecolor=RGB(255,255,255);
	CTypedPtrArray< CObArray, Figure2D*> figs;
	CTypedPtrArray< CObArray, Figure2D*> temp;
	int size_of_line = 3;
	int futureFigureKind =3; 
	

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	CButton save;
	CButton load;
	afx_msg void OnBnClickedsavebtn();
	afx_msg void OnBnClickedloadbtn();
	CButton Rectanglefigb;
	afx_msg void OnBnClickedRectanglefigbtn();
	CButton Ellipsefigb;
	afx_msg void OnBnClickedEllipsefigbtn();
	CButton linefig;
	afx_msg void OnBnClickedlineb();
	CButton RoundRectang;
	afx_msg void OnBnClickedRoundrectb();
	CButton Triangularbt;
	afx_msg void OnBnClickedTriangularb();
	CButton Parallelogrambt;
	afx_msg void OnBnClickedParallelogrambtn();
	CButton clearbt;
	afx_msg void OnBnClickedclearbtn();
	
	CComboBox combocolorbt;
	afx_msg void OnCbnSelchangecombocolor();
	CComboBox combowidthbt;
	afx_msg void OnCbnSelchangecombowidth();
	CButton undobt;
	afx_msg void OnBnClickedundobtn();
	CStatic statictextline;
	CStatic statictxtcolor;
	CButton redobt;
	afx_msg void OnBnClickedredobtn();
	CButton housebt;
	afx_msg void OnBnClickedhousebtn();
	CButton pyramidfigbt;
	afx_msg void OnBnClickedpyramidfigbtn();
};
