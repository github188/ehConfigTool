// MainFrm.cpp : CMainFrame ���ʵ��
//

#include "stdafx.h"
#include "ehConfigTool.h"

#include "MainFrm.h"
#include "MyTreeView.h"
#include "ehConfigToolView.h"

#include "ehDataBase.h"

#include "GlobalData.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
    ON_COMMAND(ID_ITEM_ADD, OnAdd)
    ON_COMMAND(ID_ITEM_DELETE, OnDelete)
    ON_COMMAND(IDM_FILE_LOAD, &CMainFrame::OnFileLoad)
    ON_COMMAND(IDM_FILE_SAVE, &CMainFrame::OnFileSave)
    ON_COMMAND(IDM_FILE_NEW, &CMainFrame::OnFileNew)
    ON_WM_CLOSE()
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // ״̬��ָʾ��
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};


// CMainFrame ����/����

CMainFrame::CMainFrame()
{
	// TODO: �ڴ���ӳ�Ա��ʼ������
}

CMainFrame::~CMainFrame()
{
}


int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("δ�ܴ���������\n");
		return -1;      // δ�ܴ���
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("δ�ܴ���״̬��\n");
		return -1;      // δ�ܴ���
	}

	// TODO: �������Ҫ��ͣ������������ɾ��������
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return TRUE;
}


// CMainFrame ���

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG


// CMainFrame ��Ϣ�������




BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
    // TODO: �ڴ����ר�ô����/����û���
    if (!m_wndSplitter.CreateStatic(this, 1, 2) ||
        !m_wndSplitter.CreateView(0, 0, RUNTIME_CLASS(CMyTreeView), CSize(180, 0), pContext) ||
        !m_wndSplitter.CreateView(0, 1, RUNTIME_CLASS(CehConfigToolView), CSize(0, 0), pContext))
        return FALSE;

    return TRUE;
}

void CMainFrame::OnAdd()
{
    GetListView()->OnAdd(); 
}

void CMainFrame::OnDelete()
{
    GetListView()->OnDelete(); 
}

CMyTreeView* CMainFrame::GetTreeView()
{
    return (CMyTreeView*)m_wndSplitter.GetPane(0, 0);
}

CehConfigToolView* CMainFrame::GetListView()
{
    return (CehConfigToolView*)m_wndSplitter.GetPane(0, 1);
}



void CMainFrame::OnFileLoad()
{
    // TODO: �ڴ���������������
    //check whether save
    if (!CheckSaved())
        return;

    char szFilter[] = {"json�ļ�(*.json)|*.json|�����ļ� (*.*)|*.*||"};  

    CFileDialog dlg(TRUE,   //TRUE�Ǵ������ļ��Ի���FALSE�򴴽����Ǳ����ļ��Ի��� 
        "json",                                            //Ĭ�ϵĴ��ļ������� 
        NULL,                                               //Ĭ�ϴ򿪵��ļ��� 
        OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,             //��ֻ���ļ� 
        szFilter);    //���п��Դ򿪵��ļ����� 

    if (dlg.DoModal() == IDOK) { 
        CString strFilePath = dlg.GetPathName();
        init_Db(strFilePath.GetBuffer());
        GetTreeView()->OnInitialUpdate();
        GetListView()->UpdateList();
        g_GlobalData.m_bIsSaved = TRUE;

        GetActiveDocument()->SetTitle(strFilePath);
    }
}

void CMainFrame::OnFileSave()
{
    // TODO: �ڴ���������������
    char szFilter[] = {"json�ļ�(*.json)|*.json|�����ļ� (*.*)|*.*||"};  

    CFileDialog dlg(FALSE, "json", NULL,
        OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, 
        szFilter, NULL);  

    if(dlg.DoModal() == IDOK)  
    {  
        save_Db(dlg.GetPathName());
        g_GlobalData.m_bIsSaved = TRUE;
    }
}

void CMainFrame::OnFileNew()
{
    // TODO: �ڴ���������������
    if (!CheckSaved())
        return;

    init_Db();
    GetTreeView()->OnInitialUpdate();
    GetListView()->UpdateList();

    GetActiveDocument()->SetTitle("�ޱ���");

    g_GlobalData.m_bIsSaved = TRUE;
}

int CMainFrame::CheckSaved(void)
{
    if (g_GlobalData.m_bIsSaved)
        return 1;

    int ret = 0;
    ret = MessageBox("��ǰ�����ѱ��޸ģ���δ���棬�Ƿ������", 
        "������ʾ", MB_YESNO);

    return ret == IDYES ? 1 : 0;
}
void CMainFrame::OnClose()
{
    // TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
    if (!CheckSaved())
        return;

    CFrameWnd::OnClose();
}
