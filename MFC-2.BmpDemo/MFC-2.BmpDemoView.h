
// MFC-2.BmpDemoView.h: CMFC2BmpDemoView 클래스의 인터페이스
//

#pragma once


class CMFC2BmpDemoView : public CView
{
protected: // serialization에서만 만들어집니다.
	CMFC2BmpDemoView() noexcept;
	DECLARE_DYNCREATE(CMFC2BmpDemoView)

// 특성입니다.
public:
	CMFC2BmpDemoDoc* GetDocument() const;
	CRgn* pRgn;
	CBrush myBrush;
// 작업입니다.
public:

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
	virtual ~CMFC2BmpDemoView();
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
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
};

#ifndef _DEBUG  // MFC-2.BmpDemoView.cpp의 디버그 버전
inline CMFC2BmpDemoDoc* CMFC2BmpDemoView::GetDocument() const
   { return reinterpret_cast<CMFC2BmpDemoDoc*>(m_pDocument); }
#endif

