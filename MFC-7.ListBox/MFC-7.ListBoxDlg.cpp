
// MFC-7.ListBoxDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MFC-7.ListBox.h"
#include "MFC-7.ListBoxDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFC7ListBoxDlg 대화 상자



CMFC7ListBoxDlg::CMFC7ListBoxDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFC7LISTBOX_DIALOG, pParent)
	, m_strName(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC7ListBoxDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_NAME, m_ctrlNameBox);
	DDX_Text(pDX, IDC_INSERT_NAME, m_strName);
	DDX_Control(pDX, IDC_COMBO_NAME, m_ctrlNameCombo);
}

BEGIN_MESSAGE_MAP(CMFC7ListBoxDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ADD_NAME, &CMFC7ListBoxDlg::OnBnClickedAddName)
	ON_BN_CLICKED(IDC_INSERT_STRING, &CMFC7ListBoxDlg::OnBnClickedInsertString)
	ON_BN_CLICKED(IDC_FIND_STRING, &CMFC7ListBoxDlg::OnBnClickedFindString)
	ON_LBN_SELCHANGE(IDC_LIST_NAME, &CMFC7ListBoxDlg::OnLbnSelchangeListName)
	ON_BN_CLICKED(IDC_CALL, &CMFC7ListBoxDlg::OnBnClickedCall)
	//ON_CBN_SELCHANGE(IDC_COMBO_NAME, &CMFC7ListBoxDlg::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_ADD_COMBO, &CMFC7ListBoxDlg::OnBnClickedAddCombo)
	ON_BN_CLICKED(IDC_DELETE_STRING, &CMFC7ListBoxDlg::OnBnClickedDeleteString)
END_MESSAGE_MAP()


// CMFC7ListBoxDlg 메시지 처리기

BOOL CMFC7ListBoxDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMFC7ListBoxDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMFC7ListBoxDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMFC7ListBoxDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMFC7ListBoxDlg::OnBnClickedAddName()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//UpdateData(1);
	GetDlgItem(IDC_INSERT_NAME)->GetWindowText(m_strName);
	m_ctrlNameBox.AddString(m_strName);

	m_strName = "";
	GetDlgItem(IDC_INSERT_NAME)->SetWindowText(m_strName);
	//UpdateData(0);
}


void CMFC7ListBoxDlg::OnBnClickedInsertString()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	GetDlgItem(IDC_INSERT_NAME)->GetWindowText(m_strName);
	m_ctrlNameBox.InsertString(2,m_strName);

	m_strName = "";
	GetDlgItem(IDC_INSERT_NAME)->SetWindowText(m_strName);
}


void CMFC7ListBoxDlg::OnBnClickedFindString()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	GetDlgItem(IDC_INSERT_NAME)->GetWindowText(m_strName);
	int nIndex = m_ctrlNameBox.FindStringExact(-1, m_strName);
	if (nIndex == LB_ERR)
	{
		AfxMessageBox(_T("Not Found"));
	}
	else
	{
		CString temp;
		m_ctrlNameBox.GetText(nIndex, temp);
		AfxMessageBox(temp);
	}
}

void CMFC7ListBoxDlg::OnLbnSelchangeListName()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//1.현재 선택된 셀렉션
	int nIndex = m_ctrlNameBox.GetCurSel();
	//2.구한 index 글자를 구한다
	if (nIndex == LB_ERR)
	{
		AfxMessageBox(_T("Not Found"));
	}
	else
	{
		CString temp;
		m_ctrlNameBox.GetText(nIndex, temp);
		this->SetWindowText(temp);
	}
}


void CMFC7ListBoxDlg::OnBnClickedCall()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//1.현재 선택된 셀렉션
	int nIndex = m_ctrlNameBox.GetCurSel();
	//2.구한 index 글자를 구한다
	if (nIndex == LB_ERR)
	{
		AfxMessageBox(_T("Not Found"));
	}
	else
	{
		CString temp;
		m_ctrlNameBox.GetText(nIndex, temp);
		AfxMessageBox(_T("Calling...") + temp);
	}
}



void CMFC7ListBoxDlg::OnBnClickedAddCombo()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	GetDlgItem(IDC_COMBO_NAME)->GetWindowText(m_strName);
	m_ctrlNameCombo.AddString(m_strName);
	m_strName = "";
	GetDlgItem(IDC_COMBO_NAME)->SetWindowText(m_strName);
	
	m_ctrlNameCombo.SetEditSel(0, -1);
	m_ctrlNameCombo.Clear();
}


void CMFC7ListBoxDlg::OnBnClickedDeleteString()
{
	
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	GetDlgItem(IDC_INSERT_NAME)->GetWindowText(m_strName);
	int nIndex = m_ctrlNameBox.FindStringExact(-1, m_strName);
	if (nIndex == LB_ERR)
	{
		AfxMessageBox(_T("Not Found"));
	}
	else
	{
		CString temp;
		m_ctrlNameBox.GetText(nIndex, temp);
		m_ctrlNameBox.DeleteString(nIndex);
	}

}


void CMFC7ListBoxDlg::OnNMCustomdrawProgress1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*pResult = 0;
}