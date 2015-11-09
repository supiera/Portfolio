// NCardListBox.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "NameCard.h"
#include "NCardListBox.h"
#include "NameCardDlg.h"

// CNCardListBox

IMPLEMENT_DYNAMIC(CNCardListBox, CVSListBox)

CNCardListBox::CNCardListBox()
{

}

CNCardListBox::~CNCardListBox()
{
}


BEGIN_MESSAGE_MAP(CNCardListBox, CVSListBox)
END_MESSAGE_MAP()



// CNCardListBox �޽��� ó�����Դϴ�.




void CNCardListBox::OnAfterAddItem(int nIndex)
{
	CNameCardDlg* pParent = (CNameCardDlg*)GetParent();
	pParent->AddNameCard(GetItemText(nIndex));
}


void CNCardListBox::OnSelectionChanged(int nIndex)
{
	int nItem;
	if((nItem = GetSelItem())<0)
		return;
	CNameCardDlg* pParent = (CNameCardDlg*)GetParent();
	pParent->SelectNameCard(nIndex);
}


bool CNCardListBox::OnBeforeRemoveItem(void)
{
	CNameCardDlg* pParent = (CNameCardDlg*)GetParent();
	pParent->DeleteNameCard(GetSelItem());

	return true;
	//return false;
}
