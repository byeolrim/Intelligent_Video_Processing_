// CUpSampleDlg.cpp: 구현 파일

#include "pch.h"
#include "MFC_assignment04.h"
#include "afxdialogex.h"
#include "CUpSampleDlg.h"

// CUpSampleDlg 클래스 구현

IMPLEMENT_DYNAMIC(CUpSampleDlg, CDialog)

CUpSampleDlg::CUpSampleDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG1, pParent)
	, m_UpSampleRate(0) // 샘플링 비율의 기본값을 0으로 초기화
{
}

CUpSampleDlg::~CUpSampleDlg()
{
	// 소멸자
}

void CUpSampleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_UpSampleRate); // 에디트 박스와 멤버 변수 연결
	DDV_MinMaxInt(pDX, m_UpSampleRate, 1, 32); // 유효한 범위 체크
}

BEGIN_MESSAGE_MAP(CUpSampleDlg, CDialog)
	// 메시지 핸들러를 추가
END_MESSAGE_MAP()

// 메시지 처리기 구현
