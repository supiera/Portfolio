
// NameCardDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "NameCard.h"
#include "NameCardDlg.h"
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


// CNameCardDlg 대화 상자




CNameCardDlg::CNameCardDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CNameCardDlg::IDD, pParent)
	, m_nCount(0)
	, m_nSelectedCard(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CNameCardDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MFCCOLORBUTTON_BG, m_cbtnBackgnd);
	DDX_Control(pDX, IDC_MFCCOLORBUTTON_TEXT, m_cbtnText);
	DDX_Control(pDX, IDC_MFCFONTCOMBO_TEXT, m_fcbText);
}

BEGIN_MESSAGE_MAP(CNameCardDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_MFCCOLORBUTTON_BG, &CNameCardDlg::OnClickedMfccolorbuttonBg)
	ON_BN_CLICKED(IDC_MFCCOLORBUTTON_TEXT, &CNameCardDlg::OnClickedMfccolorbuttonText)
	ON_CBN_SELCHANGE(IDC_MFCFONTCOMBO_TEXT, &CNameCardDlg::OnSelchangeMfcfontcomboText)
	ON_REGISTERED_MESSAGE(AFX_WM_PROPERTY_CHANGED, OnPropertyChanged)
END_MESSAGE_MAP()


// CNameCardDlg 메시지 처리기

BOOL CNameCardDlg::OnInitDialog()
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

	m_cbtnBackgnd.SetColor(RGB(255,255,255));
	m_cbtnText.SetColor(RGB(0,0,0));

	LOGFONT lf;
	afxGlobalData.fontRegular.GetLogFont(&lf);
	m_fcbText.SelectFont(lf.lfFaceName);

	CRect rectDummy, rc;
	rectDummy.SetRectEmpty();

	if(!m_listNameCard.Create(_T("NameCard"), 
		WS_VISIBLE | WS_CHILD | WM_NOTIFY | LBS_NOTIFY , rectDummy, this, 9)){
		TRACE0("속성표를 만들지 못했습니다.\n");
		return -1;
	}

	m_listNameCard.SetStandardButtons(AFX_VSLISTBOX_BTN_NEW | AFX_VSLISTBOX_BTN_DELETE);

	GetDlgItem(IDC_STATIC_CARDLIST)->GetWindowRect(&rc);
	ScreenToClient(&rc);
	m_listNameCard.MoveWindow(&rc);

	rectDummy.SetRectEmpty();
	if(!m_pGridInfo.Create(WS_VISIBLE | WS_CHILD, rectDummy, this, 2)){
		TRACE0("속성표를 만들지 못했습니다.\n");
		return -1;
	}

	GetDlgItem(IDC_STATIC_PROPERTY)->GetWindowRect(&rc);
	ScreenToClient(&rc);
	m_pGridInfo.MoveWindow(&rc);
	InitializePropGrid(NameCard());

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CNameCardDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CNameCardDlg::OnPaint()
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
HCURSOR CNameCardDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CNameCardDlg::AddNameCard(CString strName)
{
	LOGFONT lf;
	NONCLIENTMETRICS info;

	afxGlobalData.fontRegular.GetLogFont(&lf);
	info.cbSize = sizeof(info);
	afxGlobalData.GetNonClientMetrics(info);

	lf.lfHeight = info.lfMenuFont.lfHeight;
	lf.lfWeight = info.lfMenuFont.lfWeight;
	lf.lfItalic = info.lfMenuFont.lfItalic;
	lf.lfHeight = 20;

	NameCard card;
	card.strName = strName;
	card.lfName = lf;
	card.colorText = RGB(0,0,0);

	

	m_pNameCards[m_nCount++] = card;
	DrawNameCard(card);
	InitializePropGrid(card);
}


void CNameCardDlg::SelectNameCard(int nIndex)
{
	m_nSelectedCard = nIndex;
	DrawNameCard(m_pNameCards[nIndex]);
	InitializePropGrid(m_pNameCards[nIndex]);
}


void CNameCardDlg::DeleteNameCard(int nIndex)
{
	if(nIndex != (m_nCount - 1))
		memcpy(&m_pNameCards[nIndex], &m_pNameCards[nIndex+1], sizeof(NameCard)*(m_nCount - nIndex + 1));
	m_nCount--;
}


void CNameCardDlg::InitializePropGrid(NameCard card)
{
	m_pGridInfo.RemoveAll();
	m_pGridInfo.EnableHeaderCtrl(FALSE);
	m_pGridInfo.SetVSDotNetLook();
	m_pGridInfo.EnableDescriptionArea();

	CMFCPropertyGridProperty* pGroupInfo = new CMFCPropertyGridProperty(_T("Information"));
	pGroupInfo->AddSubItem(new CMFCPropertyGridProperty(_T("Company"), card.strCompany, _T("회사이름을 입력하세요"), 0));

	CMFCPropertyGridProperty* pTitle = new CMFCPropertyGridProperty(_T("Title"), card.strTitle, _T("직책을 입력하세요"), 1);
	pTitle->AddOption(_T("대표이사"));
	pTitle->AddOption(_T("부장"));
	pTitle->AddOption(_T("과장"));
	pTitle->AddOption(_T("차장"));
	pTitle->AddOption(_T("대리"));
	pTitle->AddOption(_T("사원"));
	pTitle->AllowEdit(FALSE);

	pGroupInfo->AddSubItem(pTitle);

	pGroupInfo->AddSubItem(new CMFCPropertyGridProperty(_T("Name"), card.strName, _T("이름을 입력하세요"), 2));
	pGroupInfo->AddSubItem(new CMFCPropertyGridProperty(_T("Telephone"), card.strTelephone, _T("전화번호를 입력하세요"), 3));
	pGroupInfo->AddSubItem(new CMFCPropertyGridProperty(_T("Mobile"), card.strMobile, _T("핸드폰번호를 입력하세요"),4));
	pGroupInfo->AddSubItem(new CMFCPropertyGridProperty(_T("Email"), card.strEMail, _T("이메일을 입력하세요"), 5));
	pGroupInfo->AddSubItem(new CMFCPropertyGridProperty(_T("CompanyNum"), card.strCompanyNum, _T("사번을 입력하세요"), 6));


	m_pGridInfo.AddProperty(pGroupInfo);


	CMFCPropertyGridProperty* pGroupPrint = new CMFCPropertyGridProperty(_T("Appearences"));
	pGroupPrint->AddSubItem(new CMFCPropertyGridFontProperty(_T("이름 글꼴"), card.lfName, CF_EFFECTS | CF_SCREENFONTS, _T("회사명, 직책, 이름의 글꼴을 지정합니다."), 7));

	CMFCPropertyGridColorProperty* pColor = new CMFCPropertyGridColorProperty(_T("텍스트 색상"), card.colorText, NULL, _T("출력할 텍스트의 기본색상을 지정합니다."), 8);

	pColor->EnableOtherButton(_T("기타"));
	pColor->EnableAutomaticButton(_T("기본값"), ::GetSysColor(COLOR_3DFACE));
	pGroupPrint->AddSubItem(pColor);

	m_pGridInfo.AddProperty(pGroupPrint);
	m_pGridInfo.UpdateData(FALSE);
}


void CNameCardDlg::DrawNameCard(NameCard card)
{
	CRect rc;
	CFont font, *pOldFont;
	CDC* pDC = GetDlgItem(IDC_STATIC_NAMECARD)->GetDC();
	GetDlgItem(IDC_STATIC_NAMECARD)->GetClientRect(&rc);

	pDC->FillSolidRect(&rc, m_cbtnBackgnd.GetColor());
	
	pDC->SetBkColor(m_cbtnBackgnd.GetColor());
	pDC->SetTextColor(card.colorText);

	font.CreateFontIndirect(&card.lfName);
	pOldFont = pDC->SelectObject(&font);

	pDC->TextOut(15,15,card.strCompany);

	CRect rcTitle(rc);
	rcTitle.right = rc.CenterPoint().x;
	pDC->DrawText(card.strTitle, &rcTitle, DT_RIGHT | DT_VCENTER | DT_SINGLELINE);

	CRect rcName(rc);
	rcName.left = rc.CenterPoint().x;
	pDC->DrawText(card.strName, &rcName, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	pDC->SelectObject(pOldFont);

	font.DeleteObject();

	LOGFONT lf;
	CMFCFontInfo* pInfo = m_fcbText.GetSelFont();
	afxGlobalData.fontRegular.GetLogFont(&lf);

	lf.lfCharSet = pInfo->m_nCharSet;
	lf.lfPitchAndFamily = pInfo->m_nPitchAndFamily;
	lstrcpyn(lf.lfFaceName,  pInfo->m_strName , LF_FACESIZE);
	lf.lfHeight = 15;

	font.CreateFontIndirect(&lf);
	pOldFont = pDC->SelectObject(&font);
	pDC->SetTextColor(m_cbtnText.GetColor());

	CString str;
	CRect rcMail(rc);
	rcMail.right = rcMail.right - 6;
	rcMail.bottom = rcMail.bottom - 6;



	str.Format(_T("전자메일 : %s"), card.strEMail);
	int nHeight = pDC->DrawText(str, &rcMail, DT_RIGHT | DT_BOTTOM | DT_SINGLELINE);

	str.Format(_T("개인전화 : %s"), card.strMobile);
	rcMail.bottom = rcMail.bottom - lf.lfHeight;
	nHeight = pDC->DrawText(str, &rcMail, DT_RIGHT | DT_BOTTOM | DT_SINGLELINE);

	str.Format(_T("대표전화 : %s"), card.strTelephone);
	rcMail.bottom = rcMail.bottom - lf.lfHeight;
	nHeight = pDC->DrawText(str, &rcMail, DT_RIGHT | DT_BOTTOM | DT_SINGLELINE);

	str.Format(_T("사번 : %s"), card.strCompanyNum);
	int nHeight2 = pDC->DrawText(str, &rcMail, DT_RIGHT | DT_TOP | DT_SINGLELINE);

	pDC->SelectObject(pOldFont);
	font.DeleteObject();
}


void CNameCardDlg::OnClickedMfccolorbuttonBg()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	DrawNameCard(m_pNameCards[m_nSelectedCard]);
}


void CNameCardDlg::OnClickedMfccolorbuttonText()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	DrawNameCard(m_pNameCards[m_nSelectedCard]);
}


void CNameCardDlg::OnSelchangeMfcfontcomboText()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	DrawNameCard(m_pNameCards[m_nSelectedCard]);
}

LRESULT CNameCardDlg::OnPropertyChanged(WPARAM wParam, LPARAM lParam){
	CMFCPropertyGridProperty* pProperty = (CMFCPropertyGridProperty*)lParam;

	switch(pProperty->GetData()){
		case 0:
			m_pNameCards[m_nSelectedCard].strCompany = pProperty->GetValue();
			break;

		case 1:
			m_pNameCards[m_nSelectedCard].strTitle = pProperty->GetValue();
			break;

		case 2:
			m_pNameCards[m_nSelectedCard].strName = pProperty->GetValue();
			break;

		case 3:
			m_pNameCards[m_nSelectedCard].strTelephone = pProperty->GetValue();
			break;

		case 4:
			m_pNameCards[m_nSelectedCard].strMobile = pProperty->GetValue();
			break;

		case 5:
			m_pNameCards[m_nSelectedCard].strEMail = pProperty->GetValue();
			break;

		case 6:
			m_pNameCards[m_nSelectedCard].strCompanyNum = pProperty->GetValue();
			break;


		case 7:
			m_pNameCards[m_nSelectedCard].lfName =  *((CMFCPropertyGridFontProperty*)pProperty)->GetLogFont();
			break;

		case 8:
				m_pNameCards[m_nSelectedCard].colorText = ((CMFCPropertyGridColorProperty*)pProperty)->GetColor();
			break;
	}
	DrawNameCard(m_pNameCards[m_nSelectedCard]);
	return 0;

}