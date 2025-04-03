// MFC_assignment04Doc.cpp: CMFCassignment04Doc 클래스의 구현
//

#include "pch.h"
#include "framework.h"
#ifndef SHARED_HANDLERS
#include "MFC_assignment04.h"
#endif

#include "MFC_assignment04Doc.h"
#include "CUpSampleDlg.h"
#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMFCassignment04Doc

IMPLEMENT_DYNCREATE(CMFCassignment04Doc, CDocument)

BEGIN_MESSAGE_MAP(CMFCassignment04Doc, CDocument)
END_MESSAGE_MAP()


// CMFCassignment04Doc 생성/소멸

CMFCassignment04Doc::CMFCassignment04Doc() noexcept
{
	// 생성자에서 초기화 작업
}

CMFCassignment04Doc::~CMFCassignment04Doc()
{
	// 소멸자에서 리소스 해제
}

BOOL CMFCassignment04Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// 새 문서 초기화 작업
	return TRUE;
}


// CMFCassignment04Doc 직렬화

void CMFCassignment04Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// 저장 작업
	}
	else
	{
		// 로딩 작업
	}
}

#ifdef SHARED_HANDLERS

// 축소판 그림 그리기
void CMFCassignment04Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));  // 배경색 흰색으로 설정

	CString message = _T("Thumbnail drawing not implemented yet");
	LOGFONT fontSettings;

	CFont* defaultFont = CFont::FromHandle((HFONT)GetStockObject(DEFAULT_GUI_FONT));
	defaultFont->GetLogFont(&fontSettings);
	fontSettings.lfHeight = 36;

	CFont textFont;
	textFont.CreateFontIndirect(&fontSettings);

	CFont* oldFont = dc.SelectObject(&textFont);
	dc.DrawText(message, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(oldFont);
}

// 검색 기능 지원
void CMFCassignment04Doc::InitializeSearchContent()
{
	CString searchContent;
	// 예시로 검색 콘텐츠를 설정
	SetSearchContent(searchContent);
}

void CMFCassignment04Doc::SetSearchContent(const CString& content)
{
	if (content.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl* pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, content, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CMFCassignment04Doc 진단

#ifdef _DEBUG
void CMFCassignment04Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMFCassignment04Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMFCassignment04Doc 명령

BOOL CMFCassignment04Doc::OnOpenDocument(LPCTSTR filePath)
{
	if (!CDocument::OnOpenDocument(filePath))
		return FALSE;

	// 파일 열기 작업
	CFile imageFile;
	imageFile.Open(filePath, CFile::modeRead | CFile::typeBinary);

	// 파일 크기에 따른 이미지 크기 결정
	long fileLength = imageFile.GetLength();
	if (fileLength == 256 * 256) {
		m_imageHeight = 256;
		m_imageWidth = 256;
	}
	else if (fileLength == 512 * 512) {
		m_imageHeight = 512;
		m_imageWidth = 512;
	}
	else if (fileLength == 640 * 480) {
		m_imageHeight = 480;
		m_imageWidth = 640;
	}
	else {
		AfxMessageBox(L"Unsupported image size.");
		return FALSE;
	}

	m_imageSize = m_imageWidth * m_imageHeight;
	m_imageData = new unsigned char[m_imageSize];
	std::fill(m_imageData, m_imageData + m_imageSize, 255);  // 데이터 초기화

	imageFile.Read(m_imageData, m_imageSize);
	imageFile.Close();

	return TRUE;
}

void CMFCassignment04Doc::OnUpSampling()
{
	// 업샘플링 처리
	int i, j;

	CUpSampleDlg sampleDlg;
	if (sampleDlg.DoModal() == IDOK)
	{
		int upSampleRate = sampleDlg.m_UpSampleRate;
		m_rescaledHeight = m_imageHeight * upSampleRate;
		m_rescaledWidth = m_imageWidth * upSampleRate;
		m_rescaledSize = m_rescaledHeight * m_rescaledWidth;

		m_rescaledImageData = new unsigned char[m_rescaledSize];
		std::fill(m_rescaledImageData, m_rescaledImageData + m_rescaledSize, 0);  // 메모리 초기화

		// 기존 이미지의 값을 확대하여 새로운 크기에 맞게 재배치
		for (i = 0; i < m_imageHeight; i++) {
			for (j = 0; j < m_imageWidth; j++) {
				int inputIndex = i * m_imageWidth + j;
				int outputIndex = (i * upSampleRate * m_rescaledWidth) + (j * upSampleRate);
				m_rescaledImageData[outputIndex] = m_imageData[inputIndex];
			}
		}
	}
}
