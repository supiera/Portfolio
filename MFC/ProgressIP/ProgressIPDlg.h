
// ProgressIPDlg.h : 헤더 파일
//

#pragma once


// CProgressIPDlg 대화 상자
class CProgressIPDlg : public CDialogEx
{
// 생성입니다.
public:
	CProgressIPDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_PROGRESSIP_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
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
