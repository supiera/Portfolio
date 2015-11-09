
// ProgressIPDlg.h : ��� ����
//

#pragma once


// CProgressIPDlg ��ȭ ����
class CProgressIPDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CProgressIPDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_PROGRESSIP_DIALOG };

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
	int m_nRate;
	CDateTimeCtrl m_dateTime;
	int m_nData;
	CEdit m_edResult;
	CIPAddressCtrl m_ipReceiver;
	CIPAddressCtrl m_ipSender;
	CProgressCtrl m_progRate;
	CSpinButtonCtrl m_spinData;
	afx_msg void OnClickedButtonOk();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
