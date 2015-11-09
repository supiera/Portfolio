
// NameCardDlg.h : ��� ����
//

#pragma once
#include "ncardlistbox.h"
#include "afxpropertygridctrl.h"


typedef struct NameCard{
	CString strCompany;
	CString strTitle;
	CString strName;
	CString strTelephone;
	CString strMobile;
	CString strEMail;
	CString strCompanyNum;
	LOGFONT lfName;
	COLORREF colorText;
	
	NameCard(){
		afxGlobalData.fontRegular.GetLogFont(&lfName);
		colorText=RGB(0,0,0);
	}

}NameCard;

// CNameCardDlg ��ȭ ����
class CNameCardDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CNameCardDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_NAMECARD_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	NameCard m_pNameCards[20];
	int m_nCount;
	int m_nSelectedCard;
	CMFCColorButton m_cbtnBackgnd;
	CMFCColorButton m_cbtnText;
	CMFCFontComboBox m_fcbText;
	void AddNameCard(CString strName);
	void SelectNameCard(int nIndex);
	void DeleteNameCard(int nIndex);
	CNCardListBox m_listNameCard;
	CMFCPropertyGridCtrl m_pGridInfo;
	void InitializePropGrid(NameCard card);
	void DrawNameCard(NameCard card);
	afx_msg void OnClickedMfccolorbuttonBg();
	afx_msg void OnClickedMfccolorbuttonText();
	afx_msg void OnSelchangeMfcfontcomboText();

	afx_msg LRESULT OnPropertyChanged(WPARAM wParam, LPARAM lParam);
};
