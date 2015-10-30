// MainFrm.h : CMainFrame ��Ľӿ�
//

#include "ehConfigToolView.h"
#include "MyTreeView.h"

#pragma once

class CMainFrame : public CFrameWnd
{
	
protected: // �������л�����
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// ����
public:
    CSplitterWnd m_wndSplitter;

// ����
public:
    CMyTreeView* GetTreeView();
    CehConfigToolView* GetListView();

private:
    int CheckSaved(void);

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// ʵ��
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // �ؼ���Ƕ���Ա
	CStatusBar  m_wndStatusBar;
	CToolBar    m_wndToolBar;

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP()
    virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
    afx_msg void OnAdd();
    afx_msg void OnDelete();

public:
    afx_msg void OnFileLoad();
    afx_msg void OnFileSave();
    afx_msg void OnFileNew();
    afx_msg void OnClose();
};


