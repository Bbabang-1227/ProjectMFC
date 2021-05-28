
// MFC-10.TreeCtrlView.h: CMFC10TreeCtrlView 클래스의 인터페이스
//

#pragma once


class CMFC10TreeCtrlView : public CFormView
{
protected: // serialization에서만 만들어집니다.
	CMFC10TreeCtrlView() noexcept;
	DECLARE_DYNCREATE(CMFC10TreeCtrlView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFC10TREECTRL_FORM };
#endif

// 특성입니다.
public:
	CMFC10TreeCtrlDoc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	virtual void OnInitialUpdate(); // 생성 후 처음 호출되었습니다.
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CMFC10TreeCtrlView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	CTreeCtrl m_ctrlFamily;
};

#ifndef _DEBUG  // MFC-10.TreeCtrlView.cpp의 디버그 버전
inline CMFC10TreeCtrlDoc* CMFC10TreeCtrlView::GetDocument() const
   { return reinterpret_cast<CMFC10TreeCtrlDoc*>(m_pDocument); }
#endif

