#pragma once


// CPringDlg 대화 상자

class CPringDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CPringDlg)

public:
	CPringDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CPringDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PRINT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
