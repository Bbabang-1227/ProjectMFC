
// MFC-1.MouseDemoView.h: CMFC1MouseDemoView 클래스의 인터페이스
//

#pragma once


class CMFC1MouseDemoView : public CView
{
protected: // serialization에서만 만들어집니다.
	CMFC1MouseDemoView() noexcept;
	DECLARE_DYNCREATE(CMFC1MouseDemoView)

// 특성입니다.
public:
	CMFC1MouseDemoDoc* GetDocument() const;

// 작업입니다.
public:
	int m_nX;
	int m_nY;
	BOOL m_bDrag;
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
	virtual ~CMFC1MouseDemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFC-1.MouseDemoView.cpp의 디버그 버전
inline CMFC1MouseDemoDoc* CMFC1MouseDemoView::GetDocument() const
   { return reinterpret_cast<CMFC1MouseDemoDoc*>(m_pDocument); }
#endif

