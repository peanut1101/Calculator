#pragma once


// help 对话框

class help : public CDialog
{
	DECLARE_DYNAMIC(help)

public:
	help(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~help();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
