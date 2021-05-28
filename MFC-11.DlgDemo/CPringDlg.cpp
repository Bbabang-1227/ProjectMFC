// CPringDlg.cpp: 구현 파일
//

#include "pch.h"
#include "MFC-11.DlgDemo.h"
#include "CPringDlg.h"
#include "afxdialogex.h"


// CPringDlg 대화 상자

IMPLEMENT_DYNAMIC(CPringDlg, CDialogEx)

CPringDlg::CPringDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PRINT, pParent)
{

}

CPringDlg::~CPringDlg()
{
}

void CPringDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CPringDlg, CDialogEx)
END_MESSAGE_MAP()


// CPringDlg 메시지 처리기
