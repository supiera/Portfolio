
// ProgressIP.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CProgressIPApp:
// �� Ŭ������ ������ ���ؼ��� ProgressIP.cpp�� �����Ͻʽÿ�.
//

class CProgressIPApp : public CWinApp
{
public:
	CProgressIPApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CProgressIPApp theApp;