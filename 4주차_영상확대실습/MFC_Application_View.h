// MFC_assignment04View.h: CMFCassignment04View 클래스의 인터페이스
//

#pragma once

class CMFCassignment04View : public CView
{
	DECLARE_DYNCREATE(CMFCassignment04View)

public:
	CMFCassignment04View() noexcept; // 기본 생성자
	virtual ~CMFCassignment04View(); // 소멸자

// 특성
public:
	CMFCassignment04Doc* GetDocument() const; // 문서 접근

// 재정의
public:
	virtual void OnDraw(CDC* pDC);  // 뷰 그리기
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs); // 윈도우 생성 전 준비

protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo); // 인쇄 준비
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo); // 인쇄 시작
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo); // 인쇄 종료

#ifdef _DEBUG
	virtual void AssertValid() const; // 유효성 검사
	virtual void Dump(CDumpContext& dc) const; // 디버그 정보 덤프
#endif

// 구현
protected:
	DECLARE_MESSAGE_MAP() // 메시지 맵

// 생성된 메시지 맵 함수
protected:
	afx_msg void OnFilePrintPreview(); // 인쇄 미리보기
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point); // 우클릭 이벤트
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point); // 컨텍스트 메뉴
public:
	afx_msg void OnUpSampling(); // 업샘플링 함수
};

#ifndef _DEBUG  // MFC_assignment04View.cpp의 디버그 버전
inline CMFCassignment04Doc* CMFCassignment04View::GetDocument() const
{
	return reinterpret_cast<CMFCassignment04Doc*>(m_pDocument); // 문서 캐스팅
}
#endif
