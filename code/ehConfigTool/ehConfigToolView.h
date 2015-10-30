// ehConfigToolView.h : CehConfigToolView ��Ľӿ�
//


#pragma once

#define MODY_TREE_TYPE_CUR    1
#define MODY_TREE_TYPE_CHILD  2

class CehConfigToolDoc;

class CehConfigToolView : public CListView
{
protected: // �������л�����
	CehConfigToolView();
	DECLARE_DYNCREATE(CehConfigToolView)

// ����
public:
	CehConfigToolDoc* GetDocument() const;

    //update list view
    void UpdateList(void);

private:

    void Test(void);

    void UpdateRootList(void);
    void UpdateRegionList(void);
    void UpdateDeviceList(void);
    void UpdateOpPointList(void);

    void UpdateListWithCaption(CString strCaption);

    //add operation, return: 0 -- not add, 1 -- add
    int AddRegion(void);
    int AddDevice(void);
    int AddOpPoint(void);    

    //delete operation, return: 0 -- not delete, 1 -- delete
    int DeleteRegion(int iPos);
    int DeleteDeviceInRegion(int iPos);
    int DeleteOpPoint(int iPos);     

    //delete operation, return: 0 -- not delete, 1 -- delete
    int DeleteAllRegion(void);
    int DeleteCurSelectRegion(void);
    int DeleteCurSelectDevice(void);
    int DeleteCurSelectOpPoint(void);
    //int DeleteOpPoint(int iPos);    

    //modify, return: 0 -- not modify, 1 -- modify
    int ModifyRegion(int iPos);
    int ModifyDevice(int iPos);
    int ModifyOpPoint(int iPos, int iTreeType);

    void AddListItem(CString strItemText);

// ����
public:
    void OnAdd();
    void OnDelete();
    void OnDelete2();

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~CehConfigToolView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
    virtual void OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/);
public:
    afx_msg void OnNMDblclk(NMHDR *pNMHDR, LRESULT *pResult);
};

#ifndef _DEBUG  // ehConfigToolView.cpp �еĵ��԰汾
inline CehConfigToolDoc* CehConfigToolView::GetDocument() const
   { return reinterpret_cast<CehConfigToolDoc*>(m_pDocument); }
#endif

