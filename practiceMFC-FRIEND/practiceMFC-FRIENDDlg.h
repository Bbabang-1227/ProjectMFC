
// practiceMFC-FRIENDDlg.h: 헤더 파일
//

#pragma once
#include "CPerson.h"
#include <afx.h>
// CpracticeMFCFRIENDDlg 대화 상자
class CpracticeMFCFRIENDDlg : public CDialogEx
{
// 생성입니다.
public:
	CpracticeMFCFRIENDDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PRACTICEMFCFRIEND_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:

	typedef struct PersonNode {
		int m_nAge;
		CString m_strName;
		BOOL m_bGender;
		PersonNode* pPrev, * pNext;
		PersonNode() {
			pPrev = pNext = NULL;
			m_strName = "";
			m_bGender = FALSE;
		}
		PersonNode(int nAge, CString strName, BOOL bGender, PersonNode* ptr) {
			m_nAge = nAge;
			m_strName = strName;
			m_bGender = bGender;
			pPrev = ptr;
			pNext = ptr->pNext;
			pNext->pPrev = pPrev->pNext = this;
		}
		void fnDeletePerson() {
			pPrev->pNext = pNext;
			pNext->pPrev = pPrev;
			delete this;
		}
	};
	typedef struct DLinkedList {
		PersonNode* phead;
		PersonNode* ptail;
		DLinkedList() {
			phead = new PersonNode();
			ptail = new PersonNode();
			phead->pNext = ptail;
			ptail->pPrev = phead;
		}
		~DLinkedList() {
			while (phead->pNext != ptail)
				phead->pNext->fnDeletePerson();
			delete phead;
			delete ptail;
		}
		void firstInsert(int nAge, CString strName, BOOL bGender)
		{
			new PersonNode(nAge, strName, bGender, phead);
		}
		void endInsert(int nAge, CString strName, BOOL bGender)
		{
			new PersonNode(nAge, strName, bGender, ptail->pPrev);
		}
		void firstDelete()
		{
			if (phead->pNext == ptail) return;
			phead->pNext->fnDeletePerson();
		}
		void endDelete()
		{
			if (ptail->pPrev == phead) return;
			ptail->pPrev->fnDeletePerson();
		}
	};
	
	DLinkedList* m_dlnkPerson;

	int m_nCount;
	CPerson m_pPerson[5];
	PersonNode* m_sPerson;

	int m_nAge;
	CString m_strName;
	BOOL m_bGender;

	CListCtrl m_ctrlPerson;
	CSpinButtonCtrl m_ctrlSpin;


	afx_msg void OnBnClickedButtonDelete();
	afx_msg void OnBnClickedButtonAdd();
	afx_msg void OnBnClickedButtonLoad();
	afx_msg void OnBnClickedButtonSave();
};
