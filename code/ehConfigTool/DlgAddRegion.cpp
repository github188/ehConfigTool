// DlgAddRegion.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ehConfigTool.h"
#include "DlgAddRegion.h"


// CDlgAddRegion �Ի���

IMPLEMENT_DYNAMIC(CDlgAddRegion, CDialog)

CDlgAddRegion::CDlgAddRegion(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgAddRegion::IDD, pParent)
{
    m_pData = NULL;
}

CDlgAddRegion::~CDlgAddRegion()
{
}

void CDlgAddRegion::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgAddRegion, CDialog)
END_MESSAGE_MAP()


// CDlgAddRegion ��Ϣ�������

void CDlgAddRegion::OnOK()
{
    // TODO: �ڴ����ר�ô����/����û���
    GetDlgItemText(IDC_EDIT1, *m_pData);

    CDialog::OnOK();
}

BOOL CDlgAddRegion::OnInitDialog()
{
    CDialog::OnInitDialog();

    // TODO:  �ڴ���Ӷ���ĳ�ʼ��
    if (m_iDlgType == DLG_TYPE_DEVICE)
        SetWindowText("����豸");
    else if (m_iDlgType == DLG_TYPE_MODIFY_REGION)
        SetWindowText("�޸�����");
    else if (m_iDlgType == DLG_TYPE_MODIFY_DEVICE)
        SetWindowText("�޸��豸");

    SetDlgItemText(IDC_EDIT1, *m_pData);

    return TRUE;  // return TRUE unless you set the focus to a control
    // �쳣: OCX ����ҳӦ���� FALSE
}
