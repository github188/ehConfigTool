// MainFrm.h : CMainFrame 类的接口
//

#include "ehConfigToolView.h"
#include "MyTreeView.h"

#pragma once

class CMainFrame : public CFrameWnd
{
	
protected: // 仅从序列化创建
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// 属性
public:
    CSplitterWnd m_wndSplitter;

// 操作
public:
    CMyTreeView* GetTreeView();
    CehConfigToolView* GetListView();

private:
    int CheckSaved(void);

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 实现
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // 控件条嵌入成员
	CStatusBar  m_wndStatusBar;
	CToolBar    m_wndToolBar;

// 生成的消息映射函数
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


