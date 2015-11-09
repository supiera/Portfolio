
// ProgressIPDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "ProgressIP.h"
#include "ProgressIPDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
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


// CProgressIPDlg 대화 상자




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


// CProgressIPDlg 메시지 처리기

BOOL CProgressIPDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
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

	// 이 대화 상자의 아이콘을 설정합니다. 응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	m_progRate.SetRange(0,100);
	m_progRate.SetPos(0);
	m_spinData.SetRange(-100,100);

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다. 문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CProgressIPDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CProgressIPDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CProgressIPDlg::OnClickedButtonOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_nRate=0;
	SetTimer(1,30,NULL);
	GetDlgItem(IDC_BUTTON_OK)->EnableWindow(FALSE);

}


void CProgressIPDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CString strResult;
 
	if(m_nRate != 100 )
	{
		m_nRate++;
		m_progRate.SetPos(m_nRate);
 
		strResult.Format(_T("데이터 전송 중입니다. - %d 퍼센트 \r\n\r\n 잠시 기다려주세요..."), m_nRate);
		m_edResult.SetWindowText(strResult);
	}
	else
	{
		KillTimer(1);
		GetDlgItem(IDC_BUTTON_OK)->EnableWindow(TRUE);
		UpdateData(TRUE);
 
		CString strTrans;
		m_progRate.SetPos(m_nRate);
		strTrans.Format(_T("데이터 전송 완료. - %d 퍼센트  \r\n\r\n "), m_nRate);
 
		BYTE first, second, third, forth;
 
		CString strIPSender, strIPReceiver;
 
		m_ipSender.GetAddress(first, second, third, forth);
		strIPSender.Format(_T("송신측 주소: %d.%d.%d.%d\t\t"), first, second, third, forth);
 
		m_ipReceiver.GetAddress(first, second, third, forth);
		strIPReceiver.Format(_T("수신측 주소: %d.%d.%d.%d\r\n\r\n"), first, second, third, forth);
		
		CTime timeTime;
		DWORD dwResult=m_dateTime.GetTime(timeTime);
 
		CString strDate;
		strDate.Format(_T("전송 날짜 : %s \r\n\r\n"), timeTime.Format("%A, %B %d, %Y"));
 
		CString strData;
		strData.Format(_T("전송된 데이터 : %d "), m_nData);
 
 
		strResult=strTrans + strIPSender + strIPReceiver + strDate + strData ;
		m_edResult.SetWindowText(strResult);
 
	}
	CDialogEx::OnTimer(nIDEvent);
}
