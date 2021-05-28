
// practiceArtBocView.h: CpracticeArtBocView 클래스의 인터페이스
//

#pragma once


class CpracticeArtBocView : public CView
{
protected: // serialization에서만 만들어집니다.
	CpracticeArtBocView() noexcept;
	DECLARE_DYNCREATE(CpracticeArtBocView)

// 특성입니다.
public:
	CpracticeArtBocDoc* GetDocument() const;

// 작업입니다.
public:
	enum Shape
	{
		STRAIGHT = 0,
		RECTANGLE,
		ELLIPSE
	};
	typedef struct MyStruct
	{
		CPoint m_ptStart;
		CPoint m_ptEnd;
		BOOL m_bDrag;

		int m_nShape;
		BOOL m_bFill;
		struct MyStruct* m_ptHead;
		struct MyStruct* m_ptTail;
	};
	int m_ArrayNum;
	MyStruct* m_MyStruct;

	CPoint m_ptStart;
	CPoint m_ptEnd;
	BOOL m_bDrag;

	int m_nShape;
	BOOL m_bFill;
	
// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CpracticeArtBocView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnPaint();
	afx_msg void OnPaintStraight();
	afx_msg void OnPaintRectangle();
	afx_msg void OnPaintEllipse();
	afx_msg void OnPaintFill();
	afx_msg void OnUpdatePaintStraight(CCmdUI* pCmdUI);
	afx_msg void OnUpdatePaintRectangle(CCmdUI* pCmdUI);
	afx_msg void OnUpdatePaintEllipse(CCmdUI* pCmdUI);
	afx_msg void OnUpdatePaintFill(CCmdUI* pCmdUI);
};

#ifndef _DEBUG  // practiceArtBocView.cpp의 디버그 버전
inline CpracticeArtBocDoc* CpracticeArtBocView::GetDocument() const
   { return reinterpret_cast<CpracticeArtBocDoc*>(m_pDocument); }
#endif

