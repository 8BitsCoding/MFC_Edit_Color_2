// TW_Edit.cpp: 구현 파일
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "TW_Edit.h"


// TW_Edit

IMPLEMENT_DYNAMIC(TW_Edit, CEdit)

TW_Edit::TW_Edit()
{
	m_active_text_color = RGB(255, 0, 0);
	m_normal_text_color = RGB(0, 255, 0);
	m_bk_color = RGB(0, 0, 255);
	mh_edit_bk_brush = ::CreateSolidBrush(m_bk_color);
}

TW_Edit::~TW_Edit()
{
	DeleteObject(mh_edit_bk_brush);
}


BEGIN_MESSAGE_MAP(TW_Edit, CEdit)
	ON_WM_CTLCOLOR_REFLECT()
	ON_CONTROL_REFLECT(EN_KILLFOCUS, &TW_Edit::OnEnKillfocus)
END_MESSAGE_MAP()



// TW_Edit 메시지 처리기


HBRUSH TW_Edit::CtlColor(CDC* pDC, UINT nCtlColor)
{
	pDC->SetTextColor(m_active_text_color);
	HWND cur_focus = ::GetFocus();
	if (cur_focus == m_hWnd) {
		pDC->SetBkColor(m_normal_text_color);
	}
	else
	{
		pDC->SetBkColor(m_bk_color);
	}


	return mh_edit_bk_brush;
}


void TW_Edit::OnEnKillfocus()
{
	Invalidate();
}


void TW_Edit::ChangeColor(COLORREF a_active_text_color, COLORREF a_normal_text_color, COLORREF a_bk_color)
{
	m_active_text_color = a_active_text_color;
	m_normal_text_color = a_normal_text_color;
	m_bk_color = a_bk_color;
}