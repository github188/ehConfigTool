// ehConfigTool.h : ehConfigTool Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CehConfigToolApp:
// �йش����ʵ�֣������ ehConfigTool.cpp
//

class CehConfigToolApp : public CWinApp
{
public:
	CehConfigToolApp();


// ��д
public:
	virtual BOOL InitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CehConfigToolApp theApp;