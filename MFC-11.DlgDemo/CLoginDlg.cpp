// CLoginDlg.cpp: 구현 파일
//

#include "pch.h"
#include "MFC-11.DlgDemo.h"
#include "CLoginDlg.h"
#include "afxdialogex.h"


// CLoginDlg 대화 상자

IMPLEMENT_DYNAMIC(CLoginDlg, CDialogEx)

CLoginDlg::CLoginDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LOGIN, pParent)
	, m_strTemp(_T(""))
{

}

CLoginDlg::~CLoginDlg()
{
}

void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_STRING, m_strTemp);
	//DDX_Control(pDX, IDC_EDIT1, m_ctrEdit);
}


BEGIN_MESSAGE_MAP(CLoginDlg, CDialogEx)
	//ON_EN_CHANGE(IDC_EDIT1, &CLoginDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON1, &CLoginDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CLoginDlg 메시지 처리기


void CLoginDlg::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CLoginDlg::OnBnClickedButton1()
{
	
	UpdateData(1);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
