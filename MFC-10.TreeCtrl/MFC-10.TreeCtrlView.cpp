
// MFC-10.TreeCtrlView.cpp: CMFC10TreeCtrlView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "MFC-10.TreeCtrl.h"
#endif

#include "MFC-10.TreeCtrlDoc.h"
#include "MFC-10.TreeCtrlView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC10TreeCtrlView

IMPLEMENT_DYNCREATE(CMFC10TreeCtrlView, CFormView)

BEGIN_MESSAGE_MAP(CMFC10TreeCtrlView, CFormView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CFormView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMFC10TreeCtrlView 생성/소멸

CMFC10TreeCtrlView::CMFC10TreeCtrlView() noexcept
	: CFormView(IDD_MFC10TREECTRL_FORM)
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMFC10TreeCtrlView::~CMFC10TreeCtrlView()
{
}

void CMFC10TreeCtrlView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_FAMILY, m_ctrlFamily);
}

BOOL CMFC10TreeCtrlView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CFormView::PreCreateWindow(cs);
}

void CMFC10TreeCtrlView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	static CImageList imgList;
	imgList.Create(16, 16, ILC_COLOR24, 6, 0);

	CBitmap bmpTree;
	bmpTree.LoadBitmap(IDB_TREE);
	imgList.Add(&bmpTree, RGB(0, 0, 0));

	m_ctrlFamily.SetImageList(&imgList, TVSIL_NORMAL);

	HTREEITEM hGrand = m_ctrlFamily.InsertItem(_T("GrandFather"), 4, 5, TVI_ROOT);

	HTREEITEM hBigFather = m_ctrlFamily.InsertItem(_T("BigFather"), 4, 5, hGrand);

	m_ctrlFamily.InsertItem(_T("사촌형"), 0, 0, hBigFather);
	m_ctrlFamily.InsertItem(_T("사촌누나"), 0, 0, hBigFather);

	HTREEITEM hMyFather = m_ctrlFamily.InsertItem(_T("MyFather"), 4, 5, hGrand);

	m_ctrlFamily.InsertItem(_T("형"), 0, 0, hMyFather);
	m_ctrlFamily.InsertItem(_T("누나"), 0, 0, hMyFather);
	m_ctrlFamily.InsertItem(_T("동생"), 0, 0, hMyFather);

	HTREEITEM hSmallFather = m_ctrlFamily.InsertItem(_T("SmallFather"), 4, 5, hGrand);

	m_ctrlFamily.InsertItem(_T("사촌동생"), 0, 0, hSmallFather);

	m_ctrlFamily.EnsureVisible(hMyFather);
}


// CMFC10TreeCtrlView 인쇄

BOOL CMFC10TreeCtrlView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMFC10TreeCtrlView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMFC10TreeCtrlView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CMFC10TreeCtrlView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: 여기에 사용자 지정 인쇄 코드를 추가합니다.
}


// CMFC10TreeCtrlView 진단

#ifdef _DEBUG
void CMFC10TreeCtrlView::AssertValid() const
{
	CFormView::AssertValid();
}

void CMFC10TreeCtrlView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMFC10TreeCtrlDoc* CMFC10TreeCtrlView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC10TreeCtrlDoc)));
	return (CMFC10TreeCtrlDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFC10TreeCtrlView 메시지 처리기
