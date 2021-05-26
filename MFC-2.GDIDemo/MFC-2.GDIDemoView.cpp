
// MFC-2.GDIDemoView.cpp: CMFC2GDIDemoView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "MFC-2.GDIDemo.h"
#endif

#include "MFC-2.GDIDemoDoc.h"
#include "MFC-2.GDIDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC2GDIDemoView

IMPLEMENT_DYNCREATE(CMFC2GDIDemoView, CView)

BEGIN_MESSAGE_MAP(CMFC2GDIDemoView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CMFC2GDIDemoView 생성/소멸

CMFC2GDIDemoView::CMFC2GDIDemoView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMFC2GDIDemoView::~CMFC2GDIDemoView()
{
}

BOOL CMFC2GDIDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMFC2GDIDemoView 그리기

void CMFC2GDIDemoView::OnDraw(CDC* /*pDC*/)
{
	CMFC2GDIDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CMFC2GDIDemoView 인쇄

BOOL CMFC2GDIDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMFC2GDIDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMFC2GDIDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CMFC2GDIDemoView 진단

#ifdef _DEBUG
void CMFC2GDIDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CMFC2GDIDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC2GDIDemoDoc* CMFC2GDIDemoView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC2GDIDemoDoc)));
	return (CMFC2GDIDemoDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFC2GDIDemoView 메시지 처리기


void CMFC2GDIDemoView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CDC* pDC = GetDC();

	pDC->Rectangle(100, 100, 300, 300);
	RedrawWindow();
	ReleaseDC(pDC);
	CView::OnLButtonDown(nFlags, point);
}


void CMFC2GDIDemoView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
	


	dc.Rectangle(200, 200, 400, 400);
	
	CPen myPen(PS_SOLID, 10, RGB(200, 200, 200));
	CPen* pOldPen = dc.SelectObject(&myPen);
	dc.Rectangle(400, 400, 600, 600);
	dc.Ellipse(400, 400, 600, 600);


	dc.MoveTo(400, 400);
	dc.LineTo(600, 600);
	dc.MoveTo(600, 400);
	dc.LineTo(400, 600);

	dc.SelectObject(pOldPen);
	dc.Rectangle(600, 200, 800, 400);

	//브러쉬
	// 솔리드 브러쉬
	//CBrush myBr(RGB(0, 255, 0)); 

	// 해취 브러쉬
	//CBrush myBr(HS_HASH,RGB(0, 255, 0)); 

	// 패턴 브러쉬
	/*
	CBitmap bmpBHJ;
	bmpBHJ.LoadBitmap(IDB_BHJ);
	CBrush myBr(&bmpBHJ); 
	CBrush* oldBr = dc.SelectObject(&myBr);

	CRect rectView;
	this->GetClientRect(&rectView);
	dc.Rectangle(&rectView);

	dc.SelectObject(oldBr);
	*/

	// 폰트
	/*
	*/
	LOGFONT lf = { 0, };
	lf.lfHeight = 20;
	lf.lfItalic = 1;
	lf.lfUnderline = 1;
	wsprintf(lf.lfFaceName, _T("%s"), _T("궁서체"));

	CFont myFont;
	myFont.CreateFontIndirect(&lf);

	CFont* oldFont = dc.SelectObject(&myFont);
	dc.TextOut(10, 10, _T("응애 집보내줘"));

	dc.SelectObject(oldFont);
	dc.TextOut(200, 10, _T("응애 집보내줘"));
	// 그리기 메시지에 대해서는 CView::OnPaint()을(를) 호출하지 마십시오.
}
