#pragma once
#include "afxdialogex.h"

// CUpSampleDlg 클래스 선언
class CUpSampleDlg : public CDialog
{
	DECLARE_DYNAMIC(CUpSampleDlg)

public:
	CUpSampleDlg(CWnd* pParent = nullptr);   // 생성자
	virtual ~CUpSampleDlg(); // 소멸자

protected:
	virtual void DoDataExchange(CDataExchange* pDX); // DDX/DDV 지원

	DECLARE_MESSAGE_MAP()

private:
	int m_UpSampleRate; // 샘플링 비율을 저장하는 변수

#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 }; // 대화 상자 ID 정의
#endif
};
