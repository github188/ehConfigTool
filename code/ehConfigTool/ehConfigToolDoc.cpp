// ehConfigToolDoc.cpp : CehConfigToolDoc ���ʵ��
//

#include "stdafx.h"
#include "ehConfigTool.h"

#include "ehConfigToolDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CehConfigToolDoc

IMPLEMENT_DYNCREATE(CehConfigToolDoc, CDocument)

BEGIN_MESSAGE_MAP(CehConfigToolDoc, CDocument)
END_MESSAGE_MAP()


// CehConfigToolDoc ����/����

CehConfigToolDoc::CehConfigToolDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CehConfigToolDoc::~CehConfigToolDoc()
{
}

BOOL CehConfigToolDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CehConfigToolDoc ���л�

void CehConfigToolDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
}


// CehConfigToolDoc ���

#ifdef _DEBUG
void CehConfigToolDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CehConfigToolDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CehConfigToolDoc ����

void CehConfigToolDoc::SetTitle(LPCTSTR lpszTitle)
{
    // TODO: �ڴ����ר�ô����/����û���

    CDocument::SetTitle(lpszTitle);
}
