// DlgAddOpPoint.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ehConfigTool.h"
#include "DlgAddOpPoint.h"


// CDlgAddOpPoint �Ի���

IMPLEMENT_DYNAMIC(CDlgAddOpPoint, CDialog)

CDlgAddOpPoint::CDlgAddOpPoint(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgAddOpPoint::IDD, pParent)
{
    m_pData = NULL;
    m_iType = OP_DLG_TYPE_ADD;
}

CDlgAddOpPoint::~CDlgAddOpPoint()
{
}

void CDlgAddOpPoint::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgAddOpPoint, CDialog)
    ON_BN_CLICKED(IDOK, &CDlgAddOpPoint::OnBnClickedOk)
END_MESSAGE_MAP()


// CDlgAddOpPoint ��Ϣ�������

BOOL CDlgAddOpPoint::OnInitDialog()
{
    CDialog::OnInitDialog();

    // TODO:  �ڴ���Ӷ���ĳ�ʼ��
    CComboBox* combox = ((CComboBox*) GetDlgItem(IDC_COMBO1));

    while (combox->GetCount() > 0)
        combox->DeleteString(0);

    combox->AddString("����");
    combox->AddString("����");
    combox->SetCurSel(0);

    if (m_iType == OP_DLG_TYPE_MODIFY) {
        SetWindowText("�޸Ĳ�����");
        SetDlgItemText(IDC_EDIT_NAME, m_pData->desc);
        SetDlgItemText(IDC_EDIT_OPADDR, m_pData->opAddr);
        SetDlgItemText(IDC_EDIT_STATUSADDR, m_pData->statusAddr);

        combox->SetCurSel(m_pData->dataType == DEV_TYPE_BOOL ?
            0 : 1);
    }

    return TRUE;  // return TRUE unless you set the focus to a control
    // �쳣: OCX ����ҳӦ���� FALSE
}

void CDlgAddOpPoint::OnBnClickedOk()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    GetDlgItemText(IDC_EDIT_NAME, m_pData->desc, 
        sizeof(m_pData->desc));
    GetDlgItemText(IDC_EDIT_OPADDR, m_pData->opAddr,
        sizeof(m_pData->opAddr));
    GetDlgItemText(IDC_EDIT_STATUSADDR, m_pData->statusAddr, 
        sizeof(m_pData->statusAddr));

    CComboBox* combox = ((CComboBox*) GetDlgItem(IDC_COMBO1));
    m_pData->dataType = combox->GetCurSel() == 0 ? 
        DEV_TYPE_BOOL : DEV_TYPE_BYTE;    

    OnOK();
}
