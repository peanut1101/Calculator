// CTest.cpp: 实现文件
//

#include "pch.h"
#include "Calculator.h"
#include "CTest.h"
#include "afxdialogex.h"


// CTest 对话框

IMPLEMENT_DYNAMIC(CTest, CDialog)

CTest::CTest(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_CALCULATOR_DIALOG, pParent)
{

}

CTest::~CTest()
{
}

void CTest::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTest, CDialog)
END_MESSAGE_MAP()


// CTest 消息处理程序
