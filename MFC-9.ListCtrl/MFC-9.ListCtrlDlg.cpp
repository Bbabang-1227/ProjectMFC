
// MFC-9.ListCtrlDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MFC-9.ListCtrl.h"
#include "MFC-9.ListCtrlDlg.h"
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


// CMFC9ListCtrlDlg 대화 상자



CMFC9ListCtrlDlg::CMFC9ListCtrlDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFC9LISTCTRL_DIALOG, pParent)
	, m_strName(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);


}

void CMFC9ListCtrlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_FRIEND, m_ctrlFriend);
	DDX_Text(pDX, IDC_INSERT_NAME, m_strName);
}

BEGIN_MESSAGE_MAP(CMFC9ListCtrlDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFC9ListCtrlDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFC9ListCtrlDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFC9ListCtrlDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFC9ListCtrlDlg::OnBnClickedButton2)
	ON_NOTIFY(LVN_ENDLABELEDIT, IDC_FRIEND, &CMFC9ListCtrlDlg::OnLvnEndlabeleditFriend)
END_MESSAGE_MAP()


// CMFC9ListCtrlDlg 메시지 처리기

BOOL CMFC9ListCtrlDlg::OnInitDialog()
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


	//컬럼추가
	m_ctrlFriend.InsertColumn(0, _T("이름"), 0, 100, -1);
	m_ctrlFriend.InsertColumn(1, _T("주소"), 0, 200, -1);
	m_ctrlFriend.InsertColumn(2, _T("전화번호"), 0, 200, -1);

	//이미지 리스트 추가
	static CImageList imgListSmall;
	imgListSmall.Create(16, 16, ILC_COLOR32, 5, 0);
	//2. 각 방에 이미지를 추가한다
	//LoadIcon은 App에 있는 함수이다
	imgListSmall.Add(AfxGetApp()->LoadIcon(IDI_ICON1));
	imgListSmall.Add(AfxGetApp()->LoadIcon(IDI_ICON2));
	imgListSmall.Add(AfxGetApp()->LoadIcon(IDI_ICON3));
	imgListSmall.Add(AfxGetApp()->LoadIcon(IDI_ICON4));
	imgListSmall.Add(AfxGetApp()->LoadIcon(IDI_ICON5));
	//3. 컨트롤과 이미지 리스트가 결합한다
	m_ctrlFriend.SetImageList(&imgListSmall, LVSIL_SMALL);
	//--------------------------------------------------------
	//1. 빈 방을 생성한다
	static CImageList imgList;
	imgList.Create(48, 48, ILC_COLOR32, 5, 0);
	//2. 각 방에 이미지를 추가한다
	//LoadIcon은 App에 있는 함수이다
	imgList.Add(AfxGetApp()->LoadIcon(IDI_ICON1));
	imgList.Add(AfxGetApp()->LoadIcon(IDI_ICON2));
	imgList.Add(AfxGetApp()->LoadIcon(IDI_ICON3));
	imgList.Add(AfxGetApp()->LoadIcon(IDI_ICON4));
	imgList.Add(AfxGetApp()->LoadIcon(IDI_ICON5));
	//3. 컨트롤과 이미지 리스트가 결합한다
	m_ctrlFriend.SetImageList(&imgList, LVSIL_NORMAL);
	//4. 컨트롤은 이미지 번호로 사용한다

	//값추가
	m_ctrlFriend.InsertItem(0, _T("방현준"),0);
	m_ctrlFriend.SetItemText(0, 1, _T("산본로"));
	m_ctrlFriend.SetItemText(0, 2, _T("01094146785"));

	m_ctrlFriend.InsertItem(1, _T("이재호"),1);
	m_ctrlFriend.SetItemText(1, 1, _T("레미안"));
	m_ctrlFriend.SetItemText(1, 2, _T("01059486512"));

	m_ctrlFriend.InsertItem(2, _T("김동혁"),2);
	m_ctrlFriend.SetItemText(2, 1, _T("대야미"));
	m_ctrlFriend.SetItemText(2, 2, _T("01012341234"));

	m_ctrlFriend.InsertItem(3, _T("이상호"),3);
	m_ctrlFriend.SetItemText(3, 1, _T("내옆집"));
	m_ctrlFriend.SetItemText(3, 2, _T("01048951562"));

	m_ctrlFriend.InsertItem(4, _T("김정록"),4);
	m_ctrlFriend.SetItemText(4, 1, _T("성대역"));
	m_ctrlFriend.SetItemText(4, 2, _T("01012364598"));

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMFC9ListCtrlDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFC9ListCtrlDlg::OnPaint()
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
HCURSOR CMFC9ListCtrlDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFC9ListCtrlDlg::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	static DWORD dwStyle = LVS_ICON;
	dwStyle++;
	if (dwStyle > LVS_LIST)
		dwStyle = LVS_ICON;
	m_ctrlFriend.ModifyStyle(LVS_TYPEMASK, dwStyle);

}

void CMFC9ListCtrlDlg::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	
	GetDlgItem(IDC_INSERT_NAME)->GetWindowText(m_strName);
	LVFINDINFO info;
	info.flags = LVFI_PARTIAL | LVFI_STRING;
	info.psz = m_strName;
	int nIndex = m_ctrlFriend.FindItem(&info);
	m_ctrlFriend.DeleteItem(nIndex);
	
	
}



void CMFC9ListCtrlDlg::OnBnClickedButton3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	DWORD dwStyle = m_ctrlFriend.GetExtendedStyle();
	m_ctrlFriend.SetExtendedStyle(dwStyle 
		| LVS_EX_FULLROWSELECT 
		| LVS_EX_GRIDLINES 
		| LVS_EX_CHECKBOXES 
		);
}

//////////////////////////////////////////////////////////////////////////////////////////
///////////  ++++삭제코드++++ ////////////////////////////////////////////////////////////
void CMFC9ListCtrlDlg::OnBnClickedButton4()                                           ////
{                                                                                     ////
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.                             ////
												                                      ////
	int nCount = m_ctrlFriend.GetItemCount();                                         ////
	//인덱스를 삭제할때는 역순으로 돌리는게 제일좋음                                  ////
	for (int i = nCount - 1; i >= 0; i--) //삭제해도 인덱스 수정이 일어나지않음       ////
	{                                                                                 ////
		if (m_ctrlFriend.GetCheck(i))                                                 ////
		{                                                                             ////
			m_ctrlFriend.DeleteItem(i);                                               ////
		}                                                                             ////
	}                                                                                 ////
}                                                                                     ////
///////////  ++++삭제코드++++ ////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

void CMFC9ListCtrlDlg::OnLvnEndlabeleditFriend(NMHDR* pNMHDR, LRESULT* pResult)
{
	NMLVDISPINFO* pDispInfo = reinterpret_cast<NMLVDISPINFO*>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CEdit* pEdit = m_ctrlFriend.GetEditControl();
	CString strEdit;
	pEdit->GetWindowText(strEdit);
	
	m_ctrlFriend.SetItemText(pDispInfo->item.iItem, 0 , (strEdit));
	*pResult = 0;
}
