
// ProgressIPDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "ProgressIP.h"
#include "ProgressIPDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CProgressIPDlg ��ȭ ����




CProgressIPDlg::CProgressIPDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CProgressIPDlg::IDD, pParent)
	, m_nRate(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_nData = 0;
}

void CProgressIPDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_DATETIMEPICKER_DATE, m_dateTime);
	DDX_Text(pDX, IDC_EDIT_DATA, m_nData);
	DDX_Control(pDX, IDC_EDIT_RESULT, m_edResult);
	DDX_Control(pDX, IDC_IPADDRESS_RECEIVER, m_ipReceiver);
	DDX_Control(pDX, IDC_IPADDRESS_SENDER, m_ipSender);
	DDX_Control(pDX, IDC_PROGRESS_RATE, m_progRate);
	DDX_Control(pDX, IDC_SPIN_DATA, m_spinData);
}

BEGIN_MESSAGE_MAP(CProgressIPDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_OK, &CProgressIPDlg::OnClickedButtonOk)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CProgressIPDlg �޽��� ó����

BOOL CProgressIPDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// �� ��ȭ ������ �������� �����մϴ�. ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	m_progRate.SetRange(0,100);
	m_progRate.SetPos(0);
	m_spinData.SetRange(-100,100);

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CProgressIPDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�. ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CProgressIPDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CProgressIPDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CProgressIPDlg::OnClickedButtonOk()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_nRate=0;
	SetTimer(1,30,NULL);
	GetDlgItem(IDC_BUTTON_OK)->EnableWindow(FALSE);

}


void CProgressIPDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CString strResult;
 
	if(m_nRate != 100 )
	{
		m_nRate++;
		m_progRate.SetPos(m_nRate);
 
		strResult.Format(_T("������ ���� ���Դϴ�. - %d �ۼ�Ʈ \r\n\r\n ��� ��ٷ��ּ���..."), m_nRate);
		m_edResult.SetWindowText(strResult);
	}
	else
	{
		KillTimer(1);
		GetDlgItem(IDC_BUTTON_OK)->EnableWindow(TRUE);
		UpdateData(TRUE);
 
		CString strTrans;
		m_progRate.SetPos(m_nRate);
		strTrans.Format(_T("������ ���� �Ϸ�. - %d �ۼ�Ʈ  \r\n\r\n "), m_nRate);
 
		BYTE first, second, third, forth;
 
		CString strIPSender, strIPReceiver;
 
		m_ipSender.GetAddress(first, second, third, forth);
		strIPSender.Format(_T("�۽��� �ּ�: %d.%d.%d.%d\t\t"), first, second, third, forth);
 
		m_ipReceiver.GetAddress(first, second, third, forth);
		strIPReceiver.Format(_T("������ �ּ�: %d.%d.%d.%d\r\n\r\n"), first, second, third, forth);
		
		CTime timeTime;
		DWORD dwResult=m_dateTime.GetTime(timeTime);
 
		CString strDate;
		strDate.Format(_T("���� ��¥ : %s \r\n\r\n"), timeTime.Format("%A, %B %d, %Y"));
 
		CString strData;
		strData.Format(_T("���۵� ������ : %d "), m_nData);
 
 
		strResult=strTrans + strIPSender + strIPReceiver + strDate + strData ;
		m_edResult.SetWindowText(strResult);
 
	}
	CDialogEx::OnTimer(nIDEvent);
}
