// MFC_assignment04Doc.h: CMFCassignment04Doc 클래스의 인터페이스
//

#pragma once

class CMFCassignment04Doc : public CDocument
{
	DECLARE_DYNCREATE(CMFCassignment04Doc)

public:
	CMFCassignment04Doc() noexcept; // 기본 생성자
	virtual ~CMFCassignment04Doc(); // 소멸자

// 특성 및 작업
public:
	unsigned char* m_InputImage; // 입력 이미지 데이터
	int m_width; // 이미지 너비
	int m_height; // 이미지 높이
	int m_size; // 이미지 크기

	unsigned char* m_OutputImage; // 출력 이미지 데이터
	int m_Re_width; // 보간된 이미지 너비
	int m_Re_height; // 보간된 이미지 높이
	int m_Re_size; // 보간된 이미지 크기

	void OnUpSampling(); // 업샘플링 함수

// 재정의
public:
	virtual BOOL OnNewDocument(); // 새 문서 생성
	virtual void Serialize(CArchive& ar); // 직렬화 지원

#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent(); // 검색 콘텐츠 초기화
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds); // 썸네일 그리기
#endif // SHARED_HANDLERS

#ifdef _DEBUG
	virtual void AssertValid() const; // 유효성 검사
	virtual void Dump(CDumpContext& dc) const; // 디버그 정보 덤프
#endif

protected:
	DECLARE_MESSAGE_MAP() // 메시지 맵

#ifdef SHARED_HANDLERS
	void SetSearchContent(const CString& value); // 검색 콘텐츠 설정
#endif // SHARED_HANDLERS

public:
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName); // 문서 열기
};
