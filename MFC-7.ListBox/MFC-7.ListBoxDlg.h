
// MFC-7.ListBoxDlg.h: 헤더 파일
//

#pragma once


// CMFC7ListBoxDlg 대화 상자
class CMFC7ListBoxDlg : public CDialogEx
{
// 생성입니다.
public:
	CMFC7ListBoxDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC7LISTBOX_DIALOG };
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
	CListBox m_ctrlNameBox;
	afx_msg void OnBnClickedAddName();
	CString m_strName;
	afx_msg void OnBnClickedInsertString();
	afx_msg void OnBnClickedFindString();
	afx_msg void OnLbnSelchangeListName();
	afx_msg void OnNMCustomdrawProgress1(NMHDR* pNMHDR, LRESULT* pResult);
	CProgressCtrl m_ctrlProgress;
	afx_msg void OnBnClickedCall();
	afx_msg void OnCbnSelchangeCombo1();
	CComboBox m_ctrlNameCombo;
	afx_msg void OnBnClickedAddCombo();
	afx_msg void OnBnClickedDeleteString();
};
