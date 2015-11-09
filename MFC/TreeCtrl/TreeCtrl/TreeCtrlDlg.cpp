
// TreeCtrlDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "TreeCtrl.h"
#include "TreeCtrlDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


char pszMenuJuiceInfo[2][100]={_T("�������� ���� �ֽ�"), _T("����� ���� �ֽ�")};
char pszMenuCoffeeInfo[2][100]={_T("���� ���� Coffee"), _T("������ Ŀ��")};
char pszMenuDessertInfo[3][100]={_T("�ż��� �ٴҶ� ���̽�ũ��"), _T("���ڷ��� ��� �� �����ɟ�"),
       _T("�����ϰ� �ε巯�� ġ�� �ɟ� ")};

char pszMenuKoreaInfo[5][100]={_T("��¡��¡ ����"), _T("�Ҳ��� ����"), _T("��ġ� �����"), _T("�����"), _T("���۸��� ���κ��")};

char pszMenuChinaInfo[5][100]={_T("¥������ ¥���"), _T("�ع��ع� «��"), _T("�츮�ѿ� �Ұ�� ����"), _T("���� ������� ����"), _T("��ǳ��")};


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


// CTreeCtrlDlg ��ȭ ����




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


// CTreeCtrlDlg �޽��� ó����

BOOL CTreeCtrlDlg::OnInitDialog()
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
	TVINSERTSTRUCT tInsert;
	HTREEITEM hDrink;
	HTREEITEM hDrinkCoffee;
	HTREEITEM hHotCold;

	tInsert.hParent = 0;
	tInsert.hInsertAfter = TVI_SORT;
	tInsert.item.mask = TVIF_TEXT;

	tInsert.item.pszText=_T("����");
	hDrink=m_ctrMenu.InsertItem(&tInsert);
 
	tInsert.hParent=hDrink;
	tInsert.item.pszText=_T("Ŀ��");
	hDrinkCoffee=m_ctrMenu.InsertItem(&tInsert);
	
 
	tInsert.hParent=hDrinkCoffee;
	tInsert.item.pszText=_T("�Ƹ޸�ī��");
	hHotCold=m_ctrMenu.InsertItem(&tInsert);
 
	tInsert.hParent=hHotCold;
	tInsert.item.pszText=_T("������ �Ƹ޸�ī��");
	m_ctrMenu.InsertItem(&tInsert);
 
	tInsert.hParent=hHotCold;
	tInsert.item.pszText=_T("���̽� �Ƹ޸�ī��");
	m_ctrMenu.InsertItem(&tInsert);
 
 
	tInsert.hParent=hDrinkCoffee;
	tInsert.item.pszText=_T("īǪġ��");
	m_ctrMenu.InsertItem(&tInsert);


	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
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

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�. ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CTreeCtrlDlg::OnPaint()
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
HCURSOR CTreeCtrlDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTreeCtrlDlg::OnClickedButtonDessert()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	TVINSERTSTRUCT tInsert;
	HTREEITEM hDessert;
	HTREEITEM hDessertSort;

	tInsert.hParent = 0;
	tInsert.hInsertAfter = TVI_SORT;
	tInsert.item.mask = TVIF_TEXT;
	tInsert.item.pszText = _T("����Ʈ");
	hDessert = m_ctrMenu.InsertItem(&tInsert);

	tInsert.hParent = hDessert;
	tInsert.item.pszText = _T("����ũ");
	hDessertSort = m_ctrMenu.InsertItem(&tInsert);

	tInsert.hParent = hDessertSort;
	tInsert.item.pszText = _T("ġ������ũ");
	m_ctrMenu.InsertItem(&tInsert);

	tInsert.hParent = hDessertSort;
	tInsert.item.pszText = _T("��������ũ");
	m_ctrMenu.InsertItem(&tInsert);

	tInsert.hParent = hDessert;
	tInsert.item.pszText = _T("���̽�ũ��");
	hDessertSort = m_ctrMenu.InsertItem(&tInsert);
}


void CTreeCtrlDlg::OnClickedButtonDrink()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	TVINSERTSTRUCT tInsert;
	HTREEITEM hOtherDrink;
	HTREEITEM hDrinkJuice;

	tInsert.hParent = 0;
	tInsert.hInsertAfter = TVI_SORT;
	tInsert.item.mask = TVIF_TEXT;
	tInsert.item.pszText = _T("��Ÿ����");
	hOtherDrink = m_ctrMenu.InsertItem(&tInsert);

	tInsert.hParent = hOtherDrink;
	tInsert.item.pszText = _T("�꽺");
	hDrinkJuice = m_ctrMenu.InsertItem(&tInsert);

	tInsert.hParent = hDrinkJuice;
	tInsert.item.pszText = _T("���");
	m_ctrMenu.InsertItem(&tInsert);

	tInsert.hParent = hDrinkJuice;
	tInsert.item.pszText = _T("������");
	m_ctrMenu.InsertItem(&tInsert);
}


void CTreeCtrlDlg::OnClickedButtonExit()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	OnOK();
}


void CTreeCtrlDlg::OnTvnSelchangedTreeMenu(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	HTREEITEM hItemParent, hItemCur;
	CString strParent = "";
	CString strChild = "";
 
	hItemCur=pNMTreeView->itemNew.hItem;
	hItemParent=m_ctrMenu.GetParentItem(hItemCur);
	strChild=m_ctrMenu.GetItemText(hItemCur);
    strParent=m_ctrMenu.GetItemText(hItemParent);
 
	if(strParent=="�꽺")
	{
		if(strChild=="������")
		{
		::SetDlgItemTextA(this->m_hWnd, IDC_EDIT_MENUINFO, pszMenuJuiceInfo[0]);
		}
		else if(strChild=="���")
		{
		::SetDlgItemTextA(this->m_hWnd, IDC_EDIT_MENUINFO, pszMenuJuiceInfo[1]);
		}
	}
 
	if(strParent=="Ŀ��")
	{
		if(strChild=="�Ƹ޸�ī��")
		{
		::SetDlgItemTextA(this->m_hWnd, IDC_EDIT_MENUINFO, pszMenuCoffeeInfo[0]);
		}
		else if(strChild=="īǪġ��")
		{
		::SetDlgItemTextA(this->m_hWnd, IDC_EDIT_MENUINFO, pszMenuCoffeeInfo[1]);
		}
	}
 
	if(strParent=="����Ʈ")
	{
		if(strChild=="���̽�ũ��")
		{
		::SetDlgItemTextA(this->m_hWnd, IDC_EDIT_MENUINFO, pszMenuDessertInfo[0]);
		}
	}
 
	if(strParent=="����ũ")
	{
		if(strChild=="��������ũ")
		{
		::SetDlgItemTextA(this->m_hWnd, IDC_EDIT_MENUINFO, pszMenuDessertInfo[1]);
		}
 
		else if(strChild=="ġ������ũ")
		{
		::SetDlgItemTextA(this->m_hWnd, IDC_EDIT_MENUINFO, pszMenuDessertInfo[2]);
		}
	}

	if(strParent=="����")
	{
		if(strChild=="��¡���")
		{
		::SetDlgItemTextA(this->m_hWnd, IDC_EDIT_MENUINFO, pszMenuKoreaInfo[0]);
		}
		else if(strChild=="�Ұ�ⵤ��")
		{
		::SetDlgItemTextA(this->m_hWnd, IDC_EDIT_MENUINFO, pszMenuKoreaInfo[1]);
		}
	}
 
	if(strParent=="�")
	{
		if(strChild=="��ġ�")
		{
		::SetDlgItemTextA(this->m_hWnd, IDC_EDIT_MENUINFO, pszMenuKoreaInfo[2]);
		}
 
		else if(strChild=="�����")
		{
		::SetDlgItemTextA(this->m_hWnd, IDC_EDIT_MENUINFO, pszMenuKoreaInfo[3]);
		}
		else if(strChild=="���κ��")
		{
		::SetDlgItemTextA(this->m_hWnd, IDC_EDIT_MENUINFO, pszMenuKoreaInfo[4]);
		}
	}

		if(strParent=="������")
	{
		if(strChild=="�Ұ��������")
		{
		::SetDlgItemTextA(this->m_hWnd, IDC_EDIT_MENUINFO, pszMenuChinaInfo[2]);
		}
		else if(strChild=="�������������")
		{
		::SetDlgItemTextA(this->m_hWnd, IDC_EDIT_MENUINFO, pszMenuChinaInfo[3]);
		}
	}

		if(strParent=="�丮")
	{
		if(strChild=="��ǳ��")
		{
		::SetDlgItemTextA(this->m_hWnd, IDC_EDIT_MENUINFO, pszMenuChinaInfo[4]);
		}
	}
 
	if(strParent=="��")
	{
		if(strChild=="¥���")
		{
		::SetDlgItemTextA(this->m_hWnd, IDC_EDIT_MENUINFO, pszMenuChinaInfo[0]);
		}
 
		else if(strChild=="«��")
		{
		::SetDlgItemTextA(this->m_hWnd, IDC_EDIT_MENUINFO, pszMenuChinaInfo[1]);
		}
	}


	*pResult = 0;
}

void CTreeCtrlDlg::OnClickedButtonKor()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	TVINSERTSTRUCT tInsert;
	HTREEITEM hKorea;
	HTREEITEM hKoreaSort1, hKoreaSort2;

	tInsert.hParent = 0;
	tInsert.hInsertAfter = TVI_SORT;
	tInsert.item.mask = TVIF_TEXT;
	tInsert.item.pszText = _T("�ѽ�");
	hKorea = m_ctrMenu.InsertItem(&tInsert);

	tInsert.hParent = hKorea;
	tInsert.item.pszText = _T("�");
	hKoreaSort1 = m_ctrMenu.InsertItem(&tInsert);

	tInsert.hParent = hKoreaSort1;
	tInsert.item.pszText = _T("��ġ�");
	m_ctrMenu.InsertItem(&tInsert);

	tInsert.hParent = hKoreaSort1;
	tInsert.item.pszText = _T("�����");
	m_ctrMenu.InsertItem(&tInsert);

	tInsert.hParent = hKoreaSort1;
	tInsert.item.pszText = _T("���κ��");
	m_ctrMenu.InsertItem(&tInsert);

	tInsert.hParent = hKorea;
	tInsert.item.pszText = _T("����");
	hKoreaSort2 = m_ctrMenu.InsertItem(&tInsert);

	tInsert.hParent = hKoreaSort2;
	tInsert.item.pszText = _T("��¡���");
	m_ctrMenu.InsertItem(&tInsert);

	tInsert.hParent = hKoreaSort2;
	tInsert.item.pszText = _T("�Ұ�ⵤ��");
	m_ctrMenu.InsertItem(&tInsert);

}


void CTreeCtrlDlg::OnClickedButtonChn()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	TVINSERTSTRUCT tInsert;
	HTREEITEM hChina;
	HTREEITEM hChinaSort1, hChinaSort2, hChinaSort3;

	tInsert.hParent = 0;
	tInsert.hInsertAfter = TVI_SORT;
	tInsert.item.mask = TVIF_TEXT;
	tInsert.item.pszText = _T("�߽�");
	hChina = m_ctrMenu.InsertItem(&tInsert);

	tInsert.hParent = hChina;
	tInsert.item.pszText = _T("�丮");
	hChinaSort1 = m_ctrMenu.InsertItem(&tInsert);

	tInsert.hParent = hChinaSort1;
	tInsert.item.pszText = _T("������");
	hChinaSort3 = m_ctrMenu.InsertItem(&tInsert);

	tInsert.hParent = hChinaSort3;
	tInsert.item.pszText = _T("�Ұ��������");
	m_ctrMenu.InsertItem(&tInsert);

	tInsert.hParent = hChinaSort3;
	tInsert.item.pszText = _T("�������������");
	m_ctrMenu.InsertItem(&tInsert);

	tInsert.hParent = hChina;
	tInsert.item.pszText = _T("��");
	hChinaSort2 = m_ctrMenu.InsertItem(&tInsert);

	tInsert.hParent = hChinaSort2;
	tInsert.item.pszText = _T("¥���");
	m_ctrMenu.InsertItem(&tInsert);

	tInsert.hParent = hChinaSort2;
	tInsert.item.pszText = _T("«��");
	m_ctrMenu.InsertItem(&tInsert);

	tInsert.hParent = hChinaSort1;
	tInsert.item.pszText = _T("��ǳ��");
	hChinaSort3 = m_ctrMenu.InsertItem(&tInsert);


}
