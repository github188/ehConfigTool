#include "ehDataBase.h"

#pragma once

#define OP_DLG_TYPE_ADD      0
#define OP_DLG_TYPE_MODIFY   1


// CDlgAddOpPoint �Ի���

class CDlgAddOpPoint : public CDialog
{
	DECLARE_DYNAMIC(CDlgAddOpPoint)

public:
    TagOpPoint* m_pData;
    int m_iType;

public:
	CDlgAddOpPoint(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgAddOpPoint();

// �Ի�������
	enum { IDD = IDD_DIALOG_ADDOPPOINT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
    virtual BOOL OnInitDialog();
    afx_msg void OnBnClickedOk();
};
