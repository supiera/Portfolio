
// NameCardDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "NameCard.h"
#include "NameCardDlg.h"
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


// CNameCardDlg ��ȭ ����




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


// CNameCardDlg �޽��� ó����

BOOL CNameCardDlg::OnInitDialog()
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

	m_cbtnBackgnd.SetColor(RGB(255,255,255));
	m_cbtnText.SetColor(RGB(0,0,0));

	LOGFONT lf;
	afxGlobalData.fontRegular.GetLogFont(&lf);
	m_fcbText.SelectFont(lf.lfFaceName);

	CRect rectDummy, rc;
	rectDummy.SetRectEmpty();

	if(!m_listNameCard.Create(_T("NameCard"), 
		WS_VISIBLE | WS_CHILD | WM_NOTIFY | LBS_NOTIFY , rectDummy, this, 9)){
		TRACE0("�Ӽ�ǥ�� ������ ���߽��ϴ�.\n");
		return -1;
	}

	m_listNameCard.SetStandardButtons(AFX_VSLISTBOX_BTN_NEW | AFX_VSLISTBOX_BTN_DELETE);

	GetDlgItem(IDC_STATIC_CARDLIST)->GetWindowRect(&rc);
	ScreenToClient(&rc);
	m_listNameCard.MoveWindow(&rc);

	rectDummy.SetRectEmpty();
	if(!m_pGridInfo.Create(WS_VISIBLE | WS_CHILD, rectDummy, this, 2)){
		TRACE0("�Ӽ�ǥ�� ������ ���߽��ϴ�.\n");
		return -1;
	}

	GetDlgItem(IDC_STATIC_PROPERTY)->GetWindowRect(&rc);
	ScreenToClient(&rc);
	m_pGridInfo.MoveWindow(&rc);
	InitializePropGrid(NameCard());

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
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

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�. ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CNameCardDlg::OnPaint()
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
	pGroupInfo->AddSubItem(new CMFCPropertyGridProperty(_T("Company"), card.strCompany, _T("ȸ���̸��� �Է��ϼ���"), 0));

	CMFCPropertyGridProperty* pTitle = new CMFCPropertyGridProperty(_T("Title"), card.strTitle, _T("��å�� �Է��ϼ���"), 1);
	pTitle->AddOption(_T("��ǥ�̻�"));
	pTitle->AddOption(_T("����"));
	pTitle->AddOption(_T("����"));
	pTitle->AddOption(_T("����"));
	pTitle->AddOption(_T("�븮"));
	pTitle->AddOption(_T("���"));
	pTitle->AllowEdit(FALSE);

	pGroupInfo->AddSubItem(new CMFCPropertyGridProperty(_T("Name"), card.strName, _T("�̸��� �Է��ϼ���"), 2));
	pGroupInfo->AddSubItem(new CMFCPropertyGridProperty(_T("Telephone"), card.strTelephone, _T("��ȭ��ȣ�� �Է��ϼ���"), 3));
	pGroupInfo->AddSubItem(new CMFCPropertyGridProperty(_T("Mobile"), card.strMobile, _T("�ڵ�����ȣ�� �Է��ϼ���"),4));
	pGroupInfo->AddSubItem(new CMFCPropertyGridProperty(_T("Email"), card.strEMail, _T("�̸����� �Է��ϼ���"), 5));

	m_pGridInfo.AddProperty(pGroupInfo);


	CMFCPropertyGridProperty* pGroupPrint = new CMFCPropertyGridProperty(_T("Appearences"));
	pGroupPrint->AddSubItem(new CMFCPropertyGridFontProperty(_T("�̸� �۲�"), card.lfName, CF_EFFECTS | CF_SCREENFONTS, _T("ȸ���, ��å, �̸��� �۲��� �����մϴ�."), 6));

	CMFCPropertyGridColorProperty* pColor = new CMFCPropertyGridColorProperty(_T("�ؽ�Ʈ ����"), card.colorText, NULL, _T("����� �ؽ�Ʈ�� �⺻������ �����մϴ�."), 7);

	pColor->EnableOtherButton(_T("��Ÿ"));
	pColor->EnableAutomaticButton(_T("�⺻��"), ::GetSysColor(COLOR_3DFACE));
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

	str.Format(_T("���ڸ��� : %s"), card.strEMail);
	int nHeight = pDC->DrawText(str, &rcMail, DT_RIGHT | DT_BOTTOM | DT_SINGLELINE);

	str.Format(_T("������ȭ : %s"), card.strMobile);
	rcMail.bottom = rcMail.bottom - lf.lfHeight;
	nHeight = pDC->DrawText(str, &rcMail, DT_RIGHT | DT_BOTTOM | DT_SINGLELINE);

	str.Format(_T("��ǥ��ȭ : %s"), card.strTelephone);
	rcMail.bottom = rcMail.bottom - lf.lfHeight;
	nHeight = pDC->DrawText(str, &rcMail, DT_RIGHT | DT_BOTTOM | DT_SINGLELINE);

	pDC->SelectObject(pOldFont);
	font.DeleteObject();
}


void CNameCardDlg::OnClickedMfccolorbuttonBg()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	DrawNameCard(m_pNameCards[m_nSelectedCard]);
}


void CNameCardDlg::OnClickedMfccolorbuttonText()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	DrawNameCard(m_pNameCards[m_nSelectedCard]);
}


void CNameCardDlg::OnSelchangeMfcfontcomboText()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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
			m_pNameCards[m_nSelectedCard].lfName =  *((CMFCPropertyGridFontProperty*)pProperty)->GetLogFont();
			break;

		case 7:
				m_pNameCards[m_nSelectedCard].colorText = ((CMFCPropertyGridFontProperty*)pProperty)->GetColor();
			break;
	}
	DrawNameCard(m_pNameCards[m_nSelectedCard]);
	return 0;

}