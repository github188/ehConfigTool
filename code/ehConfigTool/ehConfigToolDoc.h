// ehConfigToolDoc.h : CehConfigToolDoc ��Ľӿ�
//


#pragma once


class CehConfigToolDoc : public CDocument
{
protected: // �������л�����
	CehConfigToolDoc();
	DECLARE_DYNCREATE(CehConfigToolDoc)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// ʵ��
public:
	virtual ~CehConfigToolDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
    virtual void SetTitle(LPCTSTR lpszTitle);
};


