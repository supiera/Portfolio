
// TreeCtrlDlg.h : ��� ����
//

#pragma once


// CTreeCtrlDlg ��ȭ ����
class CTreeCtrlDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CTreeCtrlDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_TREECTRL_DIALOG };

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
	CTreeCtrl m_ctrMenu;
	afx_msg void OnClickedButtonDessert();
	afx_msg void OnClickedButtonDrink();
	afx_msg void OnClickedButtonExit();
	afx_msg void OnTvnSelchangedTreeMenu(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnClickedButtonKor();
	afx_msg void OnClickedButtonChn();
};
