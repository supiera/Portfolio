
// NameCard.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CNameCardApp:
// �� Ŭ������ ������ ���ؼ��� NameCard.cpp�� �����Ͻʽÿ�.
//

class CNameCardApp : public CWinApp
{
public:
	CNameCardApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CNameCardApp theApp;