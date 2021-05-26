
// MFC-1.MouseDemoView.cpp: CMFC1MouseDemoView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "MFC-1.MouseDemo.h"
#endif

#include "MFC-1.MouseDemoDoc.h"
#include "MFC-1.MouseDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC1MouseDemoView

IMPLEMENT_DYNCREATE(CMFC1MouseDemoView, CView)

BEGIN_MESSAGE_MAP(CMFC1MouseDemoView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMFC1MouseDemoView 생성/소멸

CMFC1MouseDemoView::CMFC1MouseDemoView() noexcept
{
	m_nX = 100;
	m_nY = 100;
	m_bDrag = FALSE;
	// TODO: 여기에 생성 코드를 추가합니다.
}

CMFC1MouseDemoView::~CMFC1MouseDemoView()
{
}

BOOL CMFC1MouseDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMFC1MouseDemoView 그리기

void CMFC1MouseDemoView::OnDraw(CDC* /*pDC*/)
{
	CMFC1MouseDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}

// CMFC1MouseDemoView 인쇄

BOOL CMFC1MouseDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMFC1MouseDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMFC1MouseDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CMFC1MouseDemoView 진단

#ifdef _DEBUG
void CMFC1MouseDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CMFC1MouseDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC1MouseDemoDoc* CMFC1MouseDemoView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC1MouseDemoDoc)));
	return (CMFC1MouseDemoDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFC1MouseDemoView 메시지 처리기


void CMFC1MouseDemoView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CView::OnPaint()을(를) 호출하지 마십시오.
	//CString strTemp;
	//strTemp.Format(_T("오늘은 신나는 금요일!! %d , %d 입니다"), m_nX, m_nY);
	dc.TextOut(m_nX, m_nY, _T("내 컴퓨터"));
}


void CMFC1MouseDemoView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if ((m_nX - 30 < point.x) && (point.x < m_nX + 30)
     && (m_nY - 30 < point.y) && (point.y < m_nY + 30))
	{
		m_bDrag = TRUE;
	}
	CView::OnLButtonDown(nFlags, point);
}


void CMFC1MouseDemoView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (m_bDrag == TRUE) // 지금 드래그중??
	{
		m_nX = point.x;
		m_nY = point.y;
		RedrawWindow(0,0,TRUE);
	}
	CView::OnMouseMove(nFlags, point);
}


void CMFC1MouseDemoView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (m_bDrag == TRUE) // 지금 드래그중??
	{
		m_bDrag = FALSE;
		m_nX = point.x;
		m_nY = point.y;
		RedrawWindow();
	}
	CView::OnLButtonUp(nFlags, point);
}
