#pragma once


// TW_Edit

class TW_Edit : public CEdit
{
	DECLARE_DYNAMIC(TW_Edit)

public:
	TW_Edit();
	virtual ~TW_Edit();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg HBRUSH CtlColor(CDC* pDC, UINT nCtlColor);
	afx_msg void OnEnKillfocus();

	HBRUSH mh_edit_bk_brush;
	COLORREF m_active_text_color, m_normal_text_color, m_bk_color;

	void ChangeColor(COLORREF a_active_text_color, COLORREF a_normal_text_color, COLORREF a_bk_color);
};


