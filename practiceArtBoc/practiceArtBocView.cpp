
// practiceArtBocView.cpp: CpracticeArtBocView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "practiceArtBoc.h"
#endif

#include "practiceArtBocDoc.h"
#include "practiceArtBocView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CpracticeArtBocView

IMPLEMENT_DYNCREATE(CpracticeArtBocView, CView)

BEGIN_MESSAGE_MAP(CpracticeArtBocView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_WM_PAINT()
	ON_COMMAND(ID_PAINT_STRAIGHT, &CpracticeArtBocView::OnPaintStraight)
	ON_COMMAND(ID_PAINT_RECTANGLE, &CpracticeArtBocView::OnPaintRectangle)
	ON_COMMAND(ID_PAINT_ELLIPSE, &CpracticeArtBocView::OnPaintEllipse)
	ON_COMMAND(ID_PAINT_FILL, &CpracticeArtBocView::OnPaintFill)
	ON_UPDATE_COMMAND_UI(ID_PAINT_STRAIGHT, &CpracticeArtBocView::OnUpdatePaintStraight)
	ON_UPDATE_COMMAND_UI(ID_PAINT_RECTANGLE, &CpracticeArtBocView::OnUpdatePaintRectangle)
	ON_UPDATE_COMMAND_UI(ID_PAINT_ELLIPSE, &CpracticeArtBocView::OnUpdatePaintEllipse)
	ON_UPDATE_COMMAND_UI(ID_PAINT_FILL, &CpracticeArtBocView::OnUpdatePaintFill)
END_MESSAGE_MAP()

// CpracticeArtBocView 생성/소멸

CpracticeArtBocView::CpracticeArtBocView() noexcept
{
	//m_ptStart = NULL;
	//m_ptEnd = NULL;
	m_ArrayNum = 0;
	m_MyStruct = new MyStruct[10];
	m_MyStruct[m_ArrayNum].m_ptStart.x = 0;
	m_MyStruct[m_ArrayNum].m_ptStart.y = 0;
	m_MyStruct[m_ArrayNum].m_ptEnd.x = 0;
	m_MyStruct[m_ArrayNum].m_ptEnd.y = 0;
	m_MyStruct[m_ArrayNum].m_bDrag = FALSE;
	m_MyStruct[m_ArrayNum].m_nShape = STRAIGHT;
	m_MyStruct[m_ArrayNum].m_bFill = FALSE;
	m_MyStruct[m_ArrayNum].m_ptHead = NULL;
	m_MyStruct[m_ArrayNum].m_ptTail = NULL;

	//

	m_ptStart.x = 0;
	m_ptStart.y = 0;
	m_ptEnd.x = 0;
	m_ptEnd.y = 0;

	m_bDrag = FALSE;

	m_nShape = STRAIGHT;
	m_bFill = FALSE;

	// TODO: 여기에 생성 코드를 추가합니다.

}

CpracticeArtBocView::~CpracticeArtBocView()
{
}

BOOL CpracticeArtBocView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CpracticeArtBocView 그리기

void CpracticeArtBocView::OnDraw(CDC* /*pDC*/)
{
	CpracticeArtBocDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CpracticeArtBocView 인쇄

BOOL CpracticeArtBocView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CpracticeArtBocView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CpracticeArtBocView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CpracticeArtBocView 진단

#ifdef _DEBUG
void CpracticeArtBocView::AssertValid() const
{
	CView::AssertValid();
}

void CpracticeArtBocView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CpracticeArtBocDoc* CpracticeArtBocView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CpracticeArtBocDoc)));
	return (CpracticeArtBocDoc*)m_pDocument;
}
#endif //_DEBUG


// CpracticeArtBocView 메시지 처리기


void CpracticeArtBocView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	m_MyStruct[m_ArrayNum].m_ptStart = point;
	m_MyStruct[m_ArrayNum].m_bDrag = TRUE;

	//

	m_ptStart = point;
	m_bDrag = TRUE;

	CView::OnLButtonDown(nFlags, point);
}


void CpracticeArtBocView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (m_bDrag)
	{
		m_MyStruct[m_ArrayNum].m_ptEnd = point;

		//

		m_ptEnd = point;
		RedrawWindow();
	}
	CView::OnMouseMove(nFlags, point);
}


void CpracticeArtBocView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (m_bDrag)
	{
		m_MyStruct[m_ArrayNum].m_ptEnd = point;
		m_MyStruct[m_ArrayNum].m_bDrag = FALSE;

		//

		m_ptEnd = point;
		m_bDrag = FALSE;

		RedrawWindow();
	}

	CView::OnLButtonUp(nFlags, point);
}


void CpracticeArtBocView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CView::OnPaint()을(를) 호출하지 마십시오.
	CBrush myBr(RGB(255, 0, 0));
	CBrush* oldBr = NULL;

	if (m_bFill)
	{
		oldBr = dc.SelectObject(&myBr);
	}

	switch (m_nShape)
	{
	case STRAIGHT: //default 직선
	{
		dc.MoveTo(m_ptStart);
		dc.LineTo(m_ptEnd);
		break;
	}
	case RECTANGLE: //직사각형
	{
		dc.Rectangle(m_ptStart.x, m_ptStart.y, m_ptEnd.x, m_ptEnd.y);
		break;
	}
	case ELLIPSE: //원
	{
		dc.Ellipse(m_ptStart.x, m_ptStart.y, m_ptEnd.x, m_ptEnd.y);
		break;
	}
	default:
		break;
	}

	if (m_bFill)
	{
		dc.SelectObject(oldBr);
	}
}


void CpracticeArtBocView::OnPaintStraight()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_nShape = STRAIGHT;
}


void CpracticeArtBocView::OnPaintRectangle()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_nShape = RECTANGLE;
}


void CpracticeArtBocView::OnPaintEllipse()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_nShape = ELLIPSE;
}


void CpracticeArtBocView::OnPaintFill()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	if (!m_bFill)
	{
		m_bFill = TRUE;
	}
	else
	{
		m_bFill = FALSE;
	}

}


void CpracticeArtBocView::OnUpdatePaintStraight(CCmdUI* pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	if (m_nShape == STRAIGHT)
	{
		pCmdUI->SetCheck(1);
	}
	else
	{
		pCmdUI->SetCheck(0);
	}
}


void CpracticeArtBocView::OnUpdatePaintRectangle(CCmdUI* pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	if (m_nShape == RECTANGLE)
	{
		pCmdUI->SetCheck(1);
	}
	else
	{
		pCmdUI->SetCheck(0);
	}
}


void CpracticeArtBocView::OnUpdatePaintEllipse(CCmdUI* pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	if (m_nShape == ELLIPSE)
	{
		pCmdUI->SetCheck(1);
	}
	else
	{
		pCmdUI->SetCheck(0);
	}
}


void CpracticeArtBocView::OnUpdatePaintFill(CCmdUI* pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	if (m_bFill == TRUE)
	{
		pCmdUI->SetCheck(1);
	}
	else
	{
		pCmdUI->SetCheck(0);
	}
}
