
// TreeCtrlDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "TreeCtrl.h"
#include "TreeCtrlDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


char pszMenuJuiceInfo[2][100]={_T("오렌지로 만든 주스"), _T("사과로 만든 주스")};
char pszMenuCoffeeInfo[2][100]={_T("향이 좋은 Coffee"), _T("달콤한 커피")};
char pszMenuDessertInfo[3][100]={_T("신선한 바닐라 아이스크림"), _T("초코렛이 듬뿍 들어간 쵸코케잌"),
       _T("촉촉하고 부드러운 치즈 케잌 ")};

char pszMenuKoreaInfo[5][100]={_T("오징오징 덮밥"), _T("불꼬기 덮밥"), _T("김치찌개 마싰썽"), _T("된장찌개"), _T("몽글몽글 순두부찌개")};

char pszMenuChinaInfo[5][100]={_T("짜증날때 짜장면"), _T("해물해물 짬뽕"), _T("우리한우 소고기 탕슉"), _T("찹쌀 돼지고기 탕슉"), _T("깐풍기")};


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


// CTreeCtrlDlg 대화 상자




CTreeCtrlDlg::CTreeCtrlDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTreeCtrlDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTreeCtrlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TREE_MENU, m_ctrMenu);
}

BEGIN_MESSAGE_MAP(CTreeCtrlDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_DESSERT, &CTreeCtrlDlg::OnClickedButtonDessert)
	ON_BN_CLICKED(IDC_BUTTON_DRINK, &CTreeCtrlDlg::OnClickedButtonDrink)
	ON_BN_CLICKED(IDC_BUTTON_EXIT, &CTreeCtrlDlg::OnClickedButtonExit)
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE_MENU, &CTreeCtrlDlg::OnTvnSelchangedTreeMenu)
	ON_BN_CLICKED(IDC_BUTTON_KOR, &CTreeCtrlDlg::OnClickedButtonKor)
	ON_BN_CLICKED(IDC_BUTTON_CHN, &CTreeCtrlDlg::OnClickedButtonChn)
END_MESSAGE_MAP()


// CTreeCtrlDlg 메시지 처리기

BOOL CTreeCtrlDlg::OnInitDialog()
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
	TVINSERTSTRUCT tInsert;
	HTREEITEM hDrink;
	HTREEITEM hDrinkCoffee;
	HTREEITEM hHotCold;

	tInsert.hParent = 0;
	tInsert.hInsertAfter = TVI_SORT;
	tInsert.item.mask = TVIF_TEXT;

	tInsert.item.pszText=_T("음료");
	hDrink=m_ctrMenu.InsertItem(&tInsert);
 
	tInsert.hParent=hDrink;
	tInsert.item.pszText=_T("커피");
	hDrinkCoffee=m_ctrMenu.InsertItem(&tInsert);
	
 
	tInsert.hParent=hDrinkCoffee;
	tInsert.item.pszText=_T("아메리카노");
	hHotCold=m_ctrMenu.InsertItem(&tInsert);
 
	tInsert.hParent=hHotCold;
	tInsert.item.pszText=_T("따뜻한 아메리카노");
	m_ctrMenu.InsertItem(&tInsert);
 
	tInsert.hParent=hHotCold;
	tInsert.item.pszText=_T("아이스 아메리카노");
	m_ctrMenu.InsertItem(&tInsert);
 
 
	tInsert.hParent=hDrinkCoffee;
	tInsert.item.pszText=_T("카푸치노");
	m_ctrMenu.InsertItem(&tInsert);


	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CTreeCtrlDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CTreeCtrlDlg::OnPaint()
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
HCURSOR CTreeCtrlDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTreeCtrlDlg::OnClickedButtonDessert()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	TVINSERTSTRUCT tInsert;
	HTREEITEM hDessert;
	HTREEITEM hDessertSort;

	tInsert.hParent = 0;
	tInsert.hInsertAfter = TVI_SORT;
	tInsert.item.mask = TVIF_TEXT;
	tInsert.item.pszText = _T("디저트");
	hDessert = m_ctrMenu.InsertItem(&tInsert);

	tInsert.hParent = hDessert;
	tInsert.item.pszText = _T("케이크");
	hDessertSort = m_ctrMenu.InsertItem(&tInsert);

	tInsert.hParent = hDessertSort;
	tInsert.item.pszText = _T("치즈케이크");
	m_ctrMenu.InsertItem(&tInsert);

	tInsert.hParent = hDessertSort;
	tInsert.item.pszText = _T("초코케이크");
	m_ctrMenu.InsertItem(&tInsert);

	tInsert.hParent = hDessert;
	tInsert.item.pszText = _T("아이스크림");
	hDessertSort = m_ctrMenu.InsertItem(&tInsert);
}


void CTreeCtrlDlg::OnClickedButtonDrink()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	TVINSERTSTRUCT tInsert;
	HTREEITEM hOtherDrink;
	HTREEITEM hDrinkJuice;

	tInsert.hParent = 0;
	tInsert.hInsertAfter = TVI_SORT;
	tInsert.item.mask = TVIF_TEXT;
	tInsert.item.pszText = _T("기타음료");
	hOtherDrink = m_ctrMenu.InsertItem(&tInsert);

	tInsert.hParent = hOtherDrink;
	tInsert.item.pszText = _T("쥬스");
	hDrinkJuice = m_ctrMenu.InsertItem(&tInsert);

	tInsert.hParent = hDrinkJuice;
	tInsert.item.pszText = _T("사과");
	m_ctrMenu.InsertItem(&tInsert);

	tInsert.hParent = hDrinkJuice;
	tInsert.item.pszText = _T("오렌지");
	m_ctrMenu.InsertItem(&tInsert);
}


void CTreeCtrlDlg::OnClickedButtonExit()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	OnOK();
}


void CTreeCtrlDlg::OnTvnSelchangedTreeMenu(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	HTREEITEM hItemParent, hItemCur;
	CString strParent = "";
	CString strChild = "";
 
	hItemCur=pNMTreeView->itemNew.hItem;
	hItemParent=m_ctrMenu.GetParentItem(hItemCur);
	strChild=m_ctrMenu.GetItemText(hItemCur);
    strParent=m_ctrMenu.GetItemText(hItemParent);
 
	if(strParent=="쥬스")
	{
		if(strChild=="오렌지")
		{
		::SetDlgItemTextA(this->m_hWnd, IDC_EDIT_MENUINFO, pszMenuJuiceInfo[0]);
		}
		else if(strChild=="사과")
		{
		::SetDlgItemTextA(this->m_hWnd, IDC_EDIT_MENUINFO, pszMenuJuiceInfo[1]);
		}
	}
 
	if(strParent=="커피")
	{
		if(strChild=="아메리카노")
		{
		::SetDlgItemTextA(this->m_hWnd, IDC_EDIT_MENUINFO, pszMenuCoffeeInfo[0]);
		}
		else if(strChild=="카푸치노")
		{
		::SetDlgItemTextA(this->m_hWnd, IDC_EDIT_MENUINFO, pszMenuCoffeeInfo[1]);
		}
	}
 
	if(strParent=="디저트")
	{
		if(strChild=="아이스크림")
		{
		::SetDlgItemTextA(this->m_hWnd, IDC_EDIT_MENUINFO, pszMenuDessertInfo[0]);
		}
	}
 
	if(strParent=="케이크")
	{
		if(strChild=="초코케이크")
		{
		::SetDlgItemTextA(this->m_hWnd, IDC_EDIT_MENUINFO, pszMenuDessertInfo[1]);
		}
 
		else if(strChild=="치즈케이크")
		{
		::SetDlgItemTextA(this->m_hWnd, IDC_EDIT_MENUINFO, pszMenuDessertInfo[2]);
		}
	}

	if(strParent=="덮밥")
	{
		if(strChild=="오징어덮밥")
		{
		::SetDlgItemTextA(this->m_hWnd, IDC_EDIT_MENUINFO, pszMenuKoreaInfo[0]);
		}
		else if(strChild=="불고기덮밥")
		{
		::SetDlgItemTextA(this->m_hWnd, IDC_EDIT_MENUINFO, pszMenuKoreaInfo[1]);
		}
	}
 
	if(strParent=="찌개")
	{
		if(strChild=="김치찌개")
		{
		::SetDlgItemTextA(this->m_hWnd, IDC_EDIT_MENUINFO, pszMenuKoreaInfo[2]);
		}
 
		else if(strChild=="된장찌개")
		{
		::SetDlgItemTextA(this->m_hWnd, IDC_EDIT_MENUINFO, pszMenuKoreaInfo[3]);
		}
		else if(strChild=="순두부찌개")
		{
		::SetDlgItemTextA(this->m_hWnd, IDC_EDIT_MENUINFO, pszMenuKoreaInfo[4]);
		}
	}

		if(strParent=="탕수육")
	{
		if(strChild=="소고기탕수육")
		{
		::SetDlgItemTextA(this->m_hWnd, IDC_EDIT_MENUINFO, pszMenuChinaInfo[2]);
		}
		else if(strChild=="돼지고기탕수육")
		{
		::SetDlgItemTextA(this->m_hWnd, IDC_EDIT_MENUINFO, pszMenuChinaInfo[3]);
		}
	}

		if(strParent=="요리")
	{
		if(strChild=="깐풍기")
		{
		::SetDlgItemTextA(this->m_hWnd, IDC_EDIT_MENUINFO, pszMenuChinaInfo[4]);
		}
	}
 
	if(strParent=="면")
	{
		if(strChild=="짜장면")
		{
		::SetDlgItemTextA(this->m_hWnd, IDC_EDIT_MENUINFO, pszMenuChinaInfo[0]);
		}
 
		else if(strChild=="짬뽕")
		{
		::SetDlgItemTextA(this->m_hWnd, IDC_EDIT_MENUINFO, pszMenuChinaInfo[1]);
		}
	}


	*pResult = 0;
}

void CTreeCtrlDlg::OnClickedButtonKor()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	TVINSERTSTRUCT tInsert;
	HTREEITEM hKorea;
	HTREEITEM hKoreaSort1, hKoreaSort2;

	tInsert.hParent = 0;
	tInsert.hInsertAfter = TVI_SORT;
	tInsert.item.mask = TVIF_TEXT;
	tInsert.item.pszText = _T("한식");
	hKorea = m_ctrMenu.InsertItem(&tInsert);

	tInsert.hParent = hKorea;
	tInsert.item.pszText = _T("찌개");
	hKoreaSort1 = m_ctrMenu.InsertItem(&tInsert);

	tInsert.hParent = hKoreaSort1;
	tInsert.item.pszText = _T("김치찌개");
	m_ctrMenu.InsertItem(&tInsert);

	tInsert.hParent = hKoreaSort1;
	tInsert.item.pszText = _T("된장찌개");
	m_ctrMenu.InsertItem(&tInsert);

	tInsert.hParent = hKoreaSort1;
	tInsert.item.pszText = _T("순두부찌개");
	m_ctrMenu.InsertItem(&tInsert);

	tInsert.hParent = hKorea;
	tInsert.item.pszText = _T("덮밥");
	hKoreaSort2 = m_ctrMenu.InsertItem(&tInsert);

	tInsert.hParent = hKoreaSort2;
	tInsert.item.pszText = _T("오징어덮밥");
	m_ctrMenu.InsertItem(&tInsert);

	tInsert.hParent = hKoreaSort2;
	tInsert.item.pszText = _T("불고기덮밥");
	m_ctrMenu.InsertItem(&tInsert);

}


void CTreeCtrlDlg::OnClickedButtonChn()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	TVINSERTSTRUCT tInsert;
	HTREEITEM hChina;
	HTREEITEM hChinaSort1, hChinaSort2, hChinaSort3;

	tInsert.hParent = 0;
	tInsert.hInsertAfter = TVI_SORT;
	tInsert.item.mask = TVIF_TEXT;
	tInsert.item.pszText = _T("중식");
	hChina = m_ctrMenu.InsertItem(&tInsert);

	tInsert.hParent = hChina;
	tInsert.item.pszText = _T("요리");
	hChinaSort1 = m_ctrMenu.InsertItem(&tInsert);

	tInsert.hParent = hChinaSort1;
	tInsert.item.pszText = _T("탕수육");
	hChinaSort3 = m_ctrMenu.InsertItem(&tInsert);

	tInsert.hParent = hChinaSort3;
	tInsert.item.pszText = _T("소고기탕수육");
	m_ctrMenu.InsertItem(&tInsert);

	tInsert.hParent = hChinaSort3;
	tInsert.item.pszText = _T("돼지고기탕수육");
	m_ctrMenu.InsertItem(&tInsert);

	tInsert.hParent = hChina;
	tInsert.item.pszText = _T("면");
	hChinaSort2 = m_ctrMenu.InsertItem(&tInsert);

	tInsert.hParent = hChinaSort2;
	tInsert.item.pszText = _T("짜장면");
	m_ctrMenu.InsertItem(&tInsert);

	tInsert.hParent = hChinaSort2;
	tInsert.item.pszText = _T("짬뽕");
	m_ctrMenu.InsertItem(&tInsert);

	tInsert.hParent = hChinaSort1;
	tInsert.item.pszText = _T("깐풍기");
	hChinaSort3 = m_ctrMenu.InsertItem(&tInsert);


}
