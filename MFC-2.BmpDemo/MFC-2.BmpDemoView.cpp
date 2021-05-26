
// MFC-2.BmpDemoView.cpp: CMFC2BmpDemoView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "MFC-2.BmpDemo.h"
#endif

#include "MFC-2.BmpDemoDoc.h"
#include "MFC-2.BmpDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC2BmpDemoView

IMPLEMENT_DYNCREATE(CMFC2BmpDemoView, CView)

BEGIN_MESSAGE_MAP(CMFC2BmpDemoView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CMFC2BmpDemoView 생성/소멸

CMFC2BmpDemoView::CMFC2BmpDemoView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.
	
}

CMFC2BmpDemoView::~CMFC2BmpDemoView()
{
}

BOOL CMFC2BmpDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}




// CMFC2BmpDemoView 인쇄

BOOL CMFC2BmpDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMFC2BmpDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMFC2BmpDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CMFC2BmpDemoView 진단

#ifdef _DEBUG
void CMFC2BmpDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CMFC2BmpDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC2BmpDemoDoc* CMFC2BmpDemoView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC2BmpDemoDoc)));
	return (CMFC2BmpDemoDoc*)m_pDocument;
}
#endif //_DEBUG

// CMFC2BmpDemoView 그리기

void CMFC2BmpDemoView::OnDraw(CDC* pDC) //화면 + 인쇄
{
	CMFC2BmpDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	
	if (pDC->IsPrinting() == TRUE)
	{
		pDC->TextOutW(10, 10, _T("쪽번호"));
		pDC->TextOutW(10, 20, _T("%d"), pDoc->m_nKor);
	}
	
}


void CMFC2BmpDemoView::OnPrint(CDC* pDC, CPrintInfo* pInfo)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	
	CView::OnPrint(pDC, pInfo);
}


// CMFC2BmpDemoView 메시지 처리기


void CMFC2BmpDemoView::OnPaint()
{
	
	CPaintDC ViewDC(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CView::OnPaint()을(를) 호출하지 마십시오.
	//SetMapMode(ViewDC,MM_HIMETRIC);
	ViewDC.SetViewportOrg(300, 300);
	
	myBrush.CreateSolidBrush(RGB(255, 0, 0));
	pRgn->CreateEllipticRgn(100,100,300,300);
	ViewDC.FillRgn(pRgn,&myBrush);
	//1. ViewDC와 호환되는 MemDC를 생성한다
	CDC MemDC; //1.0 CDC객채선언
	MemDC.CreateCompatibleDC(&ViewDC); //1.1호환하고자 하는 dc의 주소를 가져다 준다

	//2. MemDC에 BMP를 그린다
	CBitmap bmpBaby;
	bmpBaby.LoadBitmap(IDB_TP);

	BITMAP bmpInfo;
	bmpBaby.GetBitmap(&bmpInfo); // Bitmap 정보를 주는함수

	CBitmap* pOldBmp = MemDC.SelectObject(&bmpBaby);
	//MemDC.Rectangle(100, 100, 400, 400);
	//MemDC.TextOut(10, 10, _T("응애 엄마 집보내줘"));
	

	//3. ViewDCfh MemDC를 내보낸다
	//3.1 BitBlt
	ViewDC.BitBlt(
		0, 0, //ViewDC 어디부터찍을껀지
		bmpInfo.bmWidth, bmpInfo.bmHeight, //ViewDC 얼마나찍을껀지
		&MemDC, //SourceDC
		0, 0, //MemDC 얼마나찍을껀지
		SRCCOPY); //출력스타일

	//3.2 StretchBlt
	ViewDC.StretchBlt(
		0, 100, //ViewDC 어디부터찍을껀지
		bmpInfo.bmWidth, bmpInfo.bmHeight, //기준대비 얼마나 늘리고 줄일건지
		&MemDC, //SourceDC
		0, 0, //MemDC 얼마나찍을껀지
		bmpInfo.bmWidth, bmpInfo.bmHeight, // 기준
		SRCCOPY); //출력스타일

	//3.3 TransParent
	ViewDC.TransparentBlt(
		0, 200, //ViewDC 어디부터찍을껀지
		bmpInfo.bmWidth, bmpInfo.bmHeight, //기준대비 얼마나 늘리고 줄일건지
		&MemDC, //SourceDC
		0, 0, //MemDC 얼마나찍을껀지
		bmpInfo.bmWidth, bmpInfo.bmHeight, // 기준
		RGB(255,0,0)); //해당색깔 무효화

	
	//3.5 AlphaBlend
	BLENDFUNCTION bf = { 0, };
	bf.SourceConstantAlpha = 100;
	ViewDC.AlphaBlend(
		0, 200, //ViewDC 어디부터찍을껀지
		bmpInfo.bmWidth, bmpInfo.bmHeight, //기준대비 얼마나 늘리고 줄일건지
		&MemDC, //SourceDC
		0, 0, //MemDC 얼마나찍을껀지
		bmpInfo.bmWidth, bmpInfo.bmHeight, // 기준
		bf); //해당색깔 무효화
	

	//4. 뒷정리한다
	MemDC.SelectObject(pOldBmp);
	
}
