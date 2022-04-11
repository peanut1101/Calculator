
// CalculatorDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "Calculator.h"
#include "CalculatorDlg.h"
#include "afxdialogex.h"
#include "CTest.h"
#include<string>
#include "help.h"
#include "CRC16.h"
#include "calculate1.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//unsigned char auchCRCLo[] =
//{
//		0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81,
//		0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0,
//		0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01,
//		0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41,
//		0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81,
//		0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0,
//		0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01,
//		0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40,
//		0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81,
//		0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0,
//		0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01,
//		0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
//		0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81,
//		0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0,
//		0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01,
//		0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
//		0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81,
//		0x40
//};
//
//unsigned char auchCRCHi[] =
//{
//		0x00, 0xC0, 0xC1, 0x01, 0xC3, 0x03, 0x02, 0xC2, 0xC6, 0x06, 0x07, 0xC7, 0x05, 0xC5, 0xC4,
//		0x04, 0xCC, 0x0C, 0x0D, 0xCD, 0x0F, 0xCF, 0xCE, 0x0E, 0x0A, 0xCA, 0xCB, 0x0B, 0xC9, 0x09,
//		0x08, 0xC8, 0xD8, 0x18, 0x19, 0xD9, 0x1B, 0xDB, 0xDA, 0x1A, 0x1E, 0xDE, 0xDF, 0x1F, 0xDD,
//		0x1D, 0x1C, 0xDC, 0x14, 0xD4, 0xD5, 0x15, 0xD7, 0x17, 0x16, 0xD6, 0xD2, 0x12, 0x13, 0xD3,
//		0x11, 0xD1, 0xD0, 0x10, 0xF0, 0x30, 0x31, 0xF1, 0x33, 0xF3, 0xF2, 0x32, 0x36, 0xF6, 0xF7,
//		0x37, 0xF5, 0x35, 0x34, 0xF4, 0x3C, 0xFC, 0xFD, 0x3D, 0xFF, 0x3F, 0x3E, 0xFE, 0xFA, 0x3A,
//		0x3B, 0xFB, 0x39, 0xF9, 0xF8, 0x38, 0x28, 0xE8, 0xE9, 0x29, 0xEB, 0x2B, 0x2A, 0xEA, 0xEE,
//		0x2E, 0x2F, 0xEF, 0x2D, 0xED, 0xEC, 0x2C, 0xE4, 0x24, 0x25, 0xE5, 0x27, 0xE7, 0xE6, 0x26,
//		0x22, 0xE2, 0xE3, 0x23, 0xE1, 0x21, 0x20, 0xE0, 0xA0, 0x60, 0x61, 0xA1, 0x63, 0xA3, 0xA2,
//		0x62, 0x66, 0xA6, 0xA7, 0x67, 0xA5, 0x65, 0x64, 0xA4, 0x6C, 0xAC, 0xAD, 0x6D, 0xAF, 0x6F,
//		0x6E, 0xAE, 0xAA, 0x6A, 0x6B, 0xAB, 0x69, 0xA9, 0xA8, 0x68, 0x78, 0xB8, 0xB9, 0x79, 0xBB,
//		0x7B, 0x7A, 0xBA, 0xBE, 0x7E, 0x7F, 0xBF, 0x7D, 0xBD, 0xBC, 0x7C, 0xB4, 0x74, 0x75, 0xB5,
//		0x77, 0xB7, 0xB6, 0x76, 0x72, 0xB2, 0xB3, 0x73, 0xB1, 0x71, 0x70, 0xB0, 0x50, 0x90, 0x91,
//		0x51, 0x93, 0x53, 0x52, 0x92, 0x96, 0x56, 0x57, 0x97, 0x55, 0x95, 0x94, 0x54, 0x9C, 0x5C,
//		0x5D, 0x9D, 0x5F, 0x9F, 0x9E, 0x5E, 0x5A, 0x9A, 0x9B, 0x5B, 0x99, 0x59, 0x58, 0x98, 0x88,
//		0x48, 0x49, 0x89, 0x4B, 0x8B, 0x8A, 0x4A, 0x4E, 0x8E, 0x8F, 0x4F, 0x8D, 0x4D, 0x4C, 0x8C,
//		0x44, 0x84, 0x85, 0x45, 0x87, 0x47, 0x46, 0x86, 0x82, 0x42, 0x43, 0x83, 0x41, 0x81, 0x80,
//		0x40
//};
//
////**************************************************************************
////函数：CRC16
////功能：CRC校验码计算
////**************************************************************************
//unsigned short CRC16(unsigned char* puchMsg, unsigned short usDataLen)
//{
//	unsigned uIndex;
//	unsigned char uchCRCHi = 0xFF;
//	unsigned char uchCRCLo = 0xFF;
//	while (usDataLen--)
//	{
//		uIndex = uchCRCLo ^ *puchMsg++;
//		uchCRCLo = uchCRCHi ^ auchCRCLo[uIndex];
//		uchCRCHi = auchCRCHi[uIndex];
//	}
//	return (uchCRCLo | (uchCRCHi << 8));
//}

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CCalculatorDlg 对话框



CCalculatorDlg::CCalculatorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CALCULATOR_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
}

void CCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//所设置的对话框参数与变量关联
	DDX_Text(pDX, IDC_EDIT1, str1);
	DDX_Text(pDX, IDC_EDIT2, str2);
}

BEGIN_MESSAGE_MAP(CCalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CCalculatorDlg::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT2, &CCalculatorDlg::OnEnChangeEdit2)
	ON_BN_CLICKED(IDCANCEL, &CCalculatorDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON3, &CCalculatorDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON2, &CCalculatorDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON14, &CCalculatorDlg::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_BUTTON33, &CCalculatorDlg::OnBnClickedButton33)
	ON_EN_CHANGE(IDC_EDIT1, &CCalculatorDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON21, &CCalculatorDlg::OnBnClickedButton21)
	ON_BN_CLICKED(IDC_BUTTON22, &CCalculatorDlg::OnBnClickedButton22)
	ON_BN_CLICKED(IDC_BUTTON23, &CCalculatorDlg::OnBnClickedButton23)
	ON_BN_CLICKED(IDC_BUTTON20, &CCalculatorDlg::OnBnClickedButton20)
	ON_BN_CLICKED(IDC_BUTTON25, &CCalculatorDlg::OnBnClickedButton25)
	ON_BN_CLICKED(IDC_BUTTON26, &CCalculatorDlg::OnBnClickedButton26)
	ON_BN_CLICKED(IDC_BUTTON17, &CCalculatorDlg::OnBnClickedButton17)
	ON_BN_CLICKED(IDC_BUTTON28, &CCalculatorDlg::OnBnClickedButton28)
	ON_BN_CLICKED(IDC_BUTTON29, &CCalculatorDlg::OnBnClickedButton29)
	ON_BN_CLICKED(IDC_BUTTON30, &CCalculatorDlg::OnBnClickedButton30)
	ON_BN_CLICKED(IDC_BUTTON27, &CCalculatorDlg::OnBnClickedButton27)
	ON_BN_CLICKED(IDC_BUTTON24, &CCalculatorDlg::OnBnClickedButton24)
	ON_BN_CLICKED(IDC_BUTTON16, &CCalculatorDlg::OnBnClickedButton16)
	ON_BN_CLICKED(IDC_BUTTON31, &CCalculatorDlg::OnBnClickedButton31)
	ON_BN_CLICKED(IDC_BUTTON5, &CCalculatorDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON13, &CCalculatorDlg::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON12, &CCalculatorDlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON18, &CCalculatorDlg::OnBnClickedButton18)
	ON_BN_CLICKED(IDC_BUTTON19, &CCalculatorDlg::OnBnClickedButton19)
	ON_BN_CLICKED(IDC_BUTTON15, &CCalculatorDlg::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON32, &CCalculatorDlg::OnBnClickedButton32)
	ON_BN_CLICKED(IDC_BUTTON8, &CCalculatorDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CCalculatorDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &CCalculatorDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON11, &CCalculatorDlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON4, &CCalculatorDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON34, &CCalculatorDlg::OnBnClickedButton34)
	ON_BN_CLICKED(IDC_BUTTON7, &CCalculatorDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON35, &CCalculatorDlg::OnBnClickedButton35)
	ON_BN_CLICKED(IDC_BUTTON6, &CCalculatorDlg::OnBnClickedButton6)
	ON_COMMAND(ID_32771, &CCalculatorDlg::tanchu)
	ON_BN_CLICKED(IDC_BUTTON36, &CCalculatorDlg::OnBnClickedButton36)
	ON_BN_CLICKED(IDC_BUTTON37, &CCalculatorDlg::OnBnClickedButton37)
	ON_BN_CLICKED(IDC_BUTTON38, &CCalculatorDlg::OnBnClickedButton38)
	ON_BN_CLICKED(IDC_BUTTON39, &CCalculatorDlg::OnBnClickedButton39)
	ON_BN_CLICKED(IDC_BUTTON40, &CCalculatorDlg::OnBnClickedButton40)
	ON_BN_CLICKED(IDC_BUTTON41, &CCalculatorDlg::OnBnClickedButton41)
	ON_BN_CLICKED(IDC_BUTTON42, &CCalculatorDlg::OnBnClickedButton42)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// CCalculatorDlg 消息处理程序

BOOL CCalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。
	//按钮等鼠标悬浮提示初始化
	m_stat.Create(this);
	m_stat.AddTool(GetDlgItem(IDC_BUTTON7), _T("使用CRC16需要在每个十六进制字符间加一个空格")); //IDC_BUTTON为你要添加提示信息的按钮的ID
	//m_stat.AddTool( GetDlgItem(IDC_CHECK_CANRX_EN), "警告：在进行Bootloader下载时请不要打开【CAN接收】的开关！！！" );
	//m_stat.AddTool( GetDlgItem(IDC_STATIC_Version), "作者邮箱:wangpeijin0326@126.com" );
	//m_stat.SetDelayTime(0); //设置延迟，如果为0则不等待，立即显示
	//m_stat.SetTipTextColor(RGB(0, 0, 255)); //设置提示文本的颜色
	//m_stat.AddTool(GetDlgItem(IDC_BUTTON4), _T("使用CRC16需要在每个十六进制字符间加一个空格"));
	//m_stat.SetTipBkColor(RGB(255, 255, 255)); //设置提示框的背景颜色
	//m_stat.SetMaxTipWidth(600);//设置文本框的最大宽度，注意里边的数值单位为像素，所以要通过不断测试来选定最理想的宽度。利用此句可显示多行
	m_stat.Activate(TRUE); //设置是否启用提示
	//按钮等鼠标悬浮提示初始化完毕
	
	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	CRect rect;
	GetWindowRect(&rect);
	m_listRect.AddTail(rect);//对话框的区域  

	CWnd* pWnd = GetWindow(GW_CHILD);//获取子窗体  
	while (pWnd)
	{
		pWnd->GetWindowRect(rect);//子窗体的区域  
		m_listRect.AddTail(rect);           //CList<CRect,CRect> m_listRect成员变量  
		pWnd = pWnd->GetNextWindow();//取下一个子窗体  
	}

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CCalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CCalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCalculatorDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strChat;
	GetDlgItem(IDC_EDIT1)->GetWindowTextW(strChat);//得到原有内容
	strChat.Append(_T("^2"));//追加内容
	GetDlgItem(IDC_EDIT1)->SetWindowTextW(strChat);//显示改变后内容
}


void CCalculatorDlg::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

}


void CCalculatorDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


void CCalculatorDlg::OnBnClickedButton3()
{
	CString strChat;
	GetDlgItem(IDC_EDIT1)->GetWindowTextW(strChat);//得到原有内容
	strChat.Append(_T("0"));//追加内容
	GetDlgItem(IDC_EDIT1)->SetWindowTextW(strChat);//显示改变后内容
	// TODO: 在此添加控件通知处理程序代码
}


void CCalculatorDlg::OnBnClickedButton2()
{
	
	CString strChat,strChat1;
	int b[16],n=0;
//	char str[100] = { '\0' };

	GetDlgItem(IDC_EDIT1)->GetWindowTextW(strChat);//得到原有内容
	strChat1 = strChat;
	//int len;
	//len= strChat.GetLength();
	
	int bin = _wtoi(strChat);
	strChat.Empty();
	for (; bin; bin >>= 1)
		b[n++] = bin & 1;
	for (; n;n--)
	{
		strChat.Format(_T("%s%d"),strChat,b[n-1]);
	}
	//  getchar();
	strChat1.Format(_T("%s(Bin)\r\n%s"), strChat1, strChat);
	GetDlgItem(IDC_EDIT1)->SetWindowTextW(strChat1);//显示改变后内容
	// TODO: 在此添加控件通知处理程序代码
}


void CCalculatorDlg::OnBnClickedButton14()
{
	CString strChat;
	GetDlgItem(IDC_EDIT1)->GetWindowTextW(strChat);//得到原有内容
	strChat.Delete(strChat.GetLength() - 1);
	GetDlgItem(IDC_EDIT1)->SetWindowTextW(strChat);//显示改变后内容
	if (strChat=="")
	{
		GetDlgItem(IDC_BUTTON4)->EnableWindow(TRUE);//得到原有内容
		GetDlgItem(IDC_BUTTON10)->EnableWindow(TRUE);//得到原有内容
		GetDlgItem(IDC_BUTTON9)->EnableWindow(TRUE);//得到原有内容
		GetDlgItem(IDC_BUTTON11)->EnableWindow(TRUE);//得到原有内容
		GetDlgItem(IDC_BUTTON8)->EnableWindow(TRUE);//得到原有内容
		GetDlgItem(IDC_BUTTON6)->EnableWindow(TRUE);//得到原有内容
		GetDlgItem(IDC_BUTTON1)->EnableWindow(TRUE);//得到原有内容
		GetDlgItem(IDC_BUTTON24)->EnableWindow(TRUE);//得到原有内容
		GetDlgItem(IDC_BUTTON27)->EnableWindow(TRUE);//得到原有内容
		GetDlgItem(IDC_BUTTON16)->EnableWindow(TRUE);//得到原有内容
		GetDlgItem(IDC_BUTTON15)->EnableWindow(TRUE);//得到原有内容
		GetDlgItem(IDC_BUTTON12)->EnableWindow(TRUE);//得到原有内容
		GetDlgItem(IDC_BUTTON13)->EnableWindow(TRUE);//得到原有内容
		GetDlgItem(IDC_BUTTON18)->EnableWindow(TRUE);//得到原有内容
		GetDlgItem(IDC_BUTTON31)->EnableWindow(TRUE);//得到原有内容
		GetDlgItem(IDC_BUTTON2)->EnableWindow(TRUE);//得到原有内容
		GetDlgItem(IDC_BUTTON32)->EnableWindow(TRUE);//得到原有内容
		GetDlgItem(IDC_BUTTON19)->EnableWindow(TRUE);//得到原有内容
		GetDlgItem(IDC_BUTTON35)->EnableWindow(TRUE);//得到原有内容
		GetDlgItem(IDC_BUTTON34)->EnableWindow(TRUE);//得到原有内容
		GetDlgItem(IDC_BUTTON30)->EnableWindow(TRUE);//得到原有内容
		GetDlgItem(IDC_BUTTON5)->EnableWindow(TRUE);//得到原有内容
	}
	// TODO: 在此添加控件通知处理程序代码
}


void CCalculatorDlg::OnBnClickedButton33()
{
	//// TODO: 在此添加控件通知处理程序代码
	//UpdateData(TRUE);//刷新控件的值到对应的变量
	//str2 = str2 + _T('\r\n') + str1;
	//str1 = "";
	//UpdateData(FALSE);//拷贝变量值到控件显示
	CString strChat;
	CString strChat2;
	GetDlgItem(IDC_EDIT1)->GetWindowTextW(strChat);//得到原有内容
	GetDlgItem(IDC_EDIT2)->GetWindowTextW(strChat2);
	strChat.Format(_T("%s\r\n%s"),strChat, strChat2);
	GetDlgItem(IDC_EDIT1)->SetWindowTextW(_T(""));//显示改变后内容	
	GetDlgItem(IDC_EDIT2)->SetWindowTextW(strChat);//显示改变后内容
	GetDlgItem(IDC_BUTTON4)->EnableWindow(TRUE);//得到原有内容
	GetDlgItem(IDC_BUTTON10)->EnableWindow(TRUE);//得到原有内容
	GetDlgItem(IDC_BUTTON9)->EnableWindow(TRUE);//得到原有内容
	GetDlgItem(IDC_BUTTON11)->EnableWindow(TRUE);//得到原有内容
	GetDlgItem(IDC_BUTTON8)->EnableWindow(TRUE);//得到原有内容
	GetDlgItem(IDC_BUTTON6)->EnableWindow(TRUE);//得到原有内容
	GetDlgItem(IDC_BUTTON1)->EnableWindow(TRUE);//得到原有内容
	GetDlgItem(IDC_BUTTON24)->EnableWindow(TRUE);//得到原有内容
	GetDlgItem(IDC_BUTTON27)->EnableWindow(TRUE);//得到原有内容
	GetDlgItem(IDC_BUTTON16)->EnableWindow(TRUE);//得到原有内容
	GetDlgItem(IDC_BUTTON15)->EnableWindow(TRUE);//得到原有内容
	GetDlgItem(IDC_BUTTON12)->EnableWindow(TRUE);//得到原有内容
	GetDlgItem(IDC_BUTTON13)->EnableWindow(TRUE);//得到原有内容
	GetDlgItem(IDC_BUTTON18)->EnableWindow(TRUE);//得到原有内容
	GetDlgItem(IDC_BUTTON31)->EnableWindow(TRUE);//得到原有内容
	GetDlgItem(IDC_BUTTON2)->EnableWindow(TRUE);//得到原有内容
	GetDlgItem(IDC_BUTTON32)->EnableWindow(TRUE);//得到原有内容
	GetDlgItem(IDC_BUTTON19)->EnableWindow(TRUE);//得到原有内容
	GetDlgItem(IDC_BUTTON35)->EnableWindow(TRUE);//得到原有内容
	GetDlgItem(IDC_BUTTON34)->EnableWindow(TRUE);//得到原有内容
	GetDlgItem(IDC_BUTTON30)->EnableWindow(TRUE);//得到原有内容
	GetDlgItem(IDC_BUTTON5)->EnableWindow(TRUE);//得到原有内容
}


void CCalculatorDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CCalculatorDlg::OnBnClickedButton21()
{
	CString strChat;
	GetDlgItem(IDC_EDIT1)->GetWindowTextW(strChat);//得到原有内容
	strChat.Append(_T("1"));//追加内容
	GetDlgItem(IDC_EDIT1)->SetWindowTextW(strChat);//显示改变后内容
	// TODO: 在此添加控件通知处理程序代码
}


void CCalculatorDlg::OnBnClickedButton22()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strChat;
	GetDlgItem(IDC_EDIT1)->GetWindowTextW(strChat);//得到原有内容
	strChat.Append(_T("2"));//追加内容
	GetDlgItem(IDC_EDIT1)->SetWindowTextW(strChat);//显示改变后内容
}


void CCalculatorDlg::OnBnClickedButton23()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strChat;
	GetDlgItem(IDC_EDIT1)->GetWindowTextW(strChat);//得到原有内容
	strChat.Append(_T("3"));//追加内容
	GetDlgItem(IDC_EDIT1)->SetWindowTextW(strChat);//显示改变后内容
}


void CCalculatorDlg::OnBnClickedButton20()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strChat;
	GetDlgItem(IDC_EDIT1)->GetWindowTextW(strChat);//得到原有内容
	strChat.Append(_T("4"));//追加内容
	GetDlgItem(IDC_EDIT1)->SetWindowTextW(strChat);//显示改变后内容
}


void CCalculatorDlg::OnBnClickedButton25()
{
	CString strChat;
	GetDlgItem(IDC_EDIT1)->GetWindowTextW(strChat);//得到原有内容
	strChat.Append(_T("5"));//追加内容
	GetDlgItem(IDC_EDIT1)->SetWindowTextW(strChat);//显示改变后内容
	// TODO: 在此添加控件通知处理程序代码
}


void CCalculatorDlg::OnBnClickedButton26()
{
	CString strChat;
	GetDlgItem(IDC_EDIT1)->GetWindowTextW(strChat);//得到原有内容
	strChat.Append(_T("6"));//追加内容
	GetDlgItem(IDC_EDIT1)->SetWindowTextW(strChat);//显示改变后内容
	// TODO: 在此添加控件通知处理程序代码
}


void CCalculatorDlg::OnBnClickedButton17()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strChat;
	GetDlgItem(IDC_EDIT1)->GetWindowTextW(strChat);//得到原有内容
	strChat.Append(_T("7"));//追加内容
	GetDlgItem(IDC_EDIT1)->SetWindowTextW(strChat);//显示改变后内容
}


void CCalculatorDlg::OnBnClickedButton28()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strChat;
	GetDlgItem(IDC_EDIT1)->GetWindowTextW(strChat);//得到原有内容
	strChat.Append(_T("8"));//追加内容
	GetDlgItem(IDC_EDIT1)->SetWindowTextW(strChat);//显示改变后内容
}


void CCalculatorDlg::OnBnClickedButton29()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strChat;
	GetDlgItem(IDC_EDIT1)->GetWindowTextW(strChat);//得到原有内容
	strChat.Append(_T("9"));//追加内容
	GetDlgItem(IDC_EDIT1)->SetWindowTextW(strChat);//显示改变后内容
}


void CCalculatorDlg::OnBnClickedButton30()
{
	CString strChat;
	GetDlgItem(IDC_EDIT1)->GetWindowTextW(strChat);//得到原有内容
	strChat.Append(_T("*"));//追加内容
	GetDlgItem(IDC_EDIT1)->SetWindowTextW(strChat);//显示改变后内容
	// TODO: 在此添加控件通知处理程序代码
}


void CCalculatorDlg::OnBnClickedButton27()
{
	CString strChat;
	GetDlgItem(IDC_EDIT1)->GetWindowTextW(strChat);//得到原有内容
	strChat.Append(_T("-"));//追加内容
	GetDlgItem(IDC_EDIT1)->SetWindowTextW(strChat);//显示改变后内容
	// TODO: 在此添加控件通知处理程序代码
}


void CCalculatorDlg::OnBnClickedButton24()
{
	CString strChat;
	GetDlgItem(IDC_EDIT1)->GetWindowTextW(strChat);//得到原有内容
	strChat.Append(_T("+"));//追加内容
	GetDlgItem(IDC_EDIT1)->SetWindowTextW(strChat);//显示改变后内容
	// TODO: 在此添加控件通知处理程序代码
}


void CCalculatorDlg::OnBnClickedButton16()
{
	CString strChat;
	GetDlgItem(IDC_EDIT1)->GetWindowTextW(strChat);//得到原有内容
	strChat.Append(_T("("));//追加内容
	GetDlgItem(IDC_EDIT1)->SetWindowTextW(strChat);//显示改变后内容
	// TODO: 在此添加控件通知处理程序代码
}


void CCalculatorDlg::OnBnClickedButton31()
{
	CString strChat;
	GetDlgItem(IDC_EDIT1)->GetWindowTextW(strChat);//得到原有内容
	strChat.Append(_T(")"));//追加内容
	GetDlgItem(IDC_EDIT1)->SetWindowTextW(strChat);//显示改变后内容
	// TODO: 在此添加控件通知处理程序代码
}


void CCalculatorDlg::OnBnClickedButton5()
{
	CString strChat;
	GetDlgItem(IDC_EDIT1)->GetWindowTextW(strChat);//得到原有内容
	strChat.Append(_T("."));//追加内容
	GetDlgItem(IDC_EDIT1)->SetWindowTextW(strChat);//显示改变后内容
	// TODO: 在此添加控件通知处理程序代码
}


void CCalculatorDlg::OnBnClickedButton13()
{
	CString strChat;
	GetDlgItem(IDC_EDIT1)->GetWindowTextW(strChat);//得到原有内容
	strChat.Append(_T("e"));//追加内容
	GetDlgItem(IDC_EDIT1)->SetWindowTextW(strChat);//显示改变后内容
	// TODO: 在此添加控件通知处理程序代码
}


void CCalculatorDlg::OnBnClickedButton12()
{
	CString strChat;
	GetDlgItem(IDC_EDIT1)->GetWindowTextW(strChat);//得到原有内容
	strChat.Append(_T("pi"));//追加内容
	GetDlgItem(IDC_EDIT1)->SetWindowTextW(strChat);//显示改变后内容
	// TODO: 在此添加控件通知处理程序代码
}


void CCalculatorDlg::OnBnClickedButton18()
{
	CString strChat;
	GetDlgItem(IDC_EDIT1)->GetWindowTextW(strChat);//得到原有内容
	strChat.Append(_T("Sin"));//追加内容
	GetDlgItem(IDC_EDIT1)->SetWindowTextW(strChat);//显示改变后内容
	// TODO: 在此添加控件通知处理程序代码
}


void CCalculatorDlg::OnBnClickedButton19()
{
	CString strChat;
	GetDlgItem(IDC_EDIT1)->GetWindowTextW(strChat);//得到原有内容
	strChat.Append(_T("Cos"));//追加内容
	GetDlgItem(IDC_EDIT1)->SetWindowTextW(strChat);//显示改变后内容
	// TODO: 在此添加控件通知处理程序代码
}


void CCalculatorDlg::OnBnClickedButton15()
{
	CString strChat;
	GetDlgItem(IDC_EDIT1)->GetWindowTextW(strChat);//得到原有内容
	strChat.Append(_T("1/"));//追加内容
	GetDlgItem(IDC_EDIT1)->SetWindowTextW(strChat);//显示改变后内容
	// TODO: 在此添加控件通知处理程序代码
}


void CCalculatorDlg::OnBnClickedButton32()
{
	CString strChat;
	GetDlgItem(IDC_EDIT1)->GetWindowTextW(strChat);//得到原有内容
	strChat.Append(_T("!"));//追加内容
	GetDlgItem(IDC_EDIT1)->SetWindowTextW(strChat);//显示改变后内容
	// TODO: 在此添加控件通知处理程序代码
}


void CCalculatorDlg::OnBnClickedButton8()
{
	CString strChat;
	GetDlgItem(IDC_EDIT1)->GetWindowTextW(strChat);//得到原有内容
	strChat.Append(_T("^"));//追加内容
	GetDlgItem(IDC_EDIT1)->SetWindowTextW(strChat);//显示改变后内容
	// TODO: 在此添加控件通知处理程序代码
}


void CCalculatorDlg::OnBnClickedButton9()
{
	CString strChat;
	GetDlgItem(IDC_EDIT1)->GetWindowTextW(strChat);//得到原有内容
	strChat.Append(_T("G"));//追加内容
	GetDlgItem(IDC_EDIT1)->SetWindowTextW(strChat);//显示改变后内容
	// TODO: 在此添加控件通知处理程序代码
}


void CCalculatorDlg::OnBnClickedButton10()
{
	CString strChat;
	GetDlgItem(IDC_EDIT1)->GetWindowTextW(strChat);//得到原有内容
	strChat.Append(_T("e^"));//追加内容
	GetDlgItem(IDC_EDIT1)->SetWindowTextW(strChat);//显示改变后内容
	// TODO: 在此添加控件通知处理程序代码
}


void CCalculatorDlg::OnBnClickedButton11()
{
	CString strChat;
	GetDlgItem(IDC_EDIT1)->GetWindowTextW(strChat);//得到原有内容
	strChat.Append(_T("log"));//追加内容
	GetDlgItem(IDC_EDIT1)->SetWindowTextW(strChat);//显示改变后内容
	// TODO: 在此添加控件通知处理程序代码
}


void CCalculatorDlg::OnBnClickedButton4()//=
{
	CString strChat;

	char str[100] = { '\0' };

	GetDlgItem(IDC_EDIT1)->GetWindowTextW(strChat);//得到原有内容

	WideCharToMultiByte(CP_ACP, 0, strChat.GetBuffer(0), strChat.GetLength(), str, 100, 0, 0);


	double result = calculate(str);
	if (result == 557135115.02097678)
	{
		strChat.Format(_T("%s=\r\n%s"), strChat,_T("无效输入"));
	}
	else
	{
		strChat.Format(_T("%s=\r\n%lf"), strChat, result);
	}

	

	GetDlgItem(IDC_EDIT1)->SetWindowTextW(strChat);//显示改变后内容
	// TODO: 在此添加控件通知处理程序代码
}


void CCalculatorDlg::OnBnClickedButton34()
{
	CString strChat;
	GetDlgItem(IDC_EDIT1)->GetWindowTextW(strChat);//得到原有内容
	strChat.Append(_T("/"));//追加内容
	GetDlgItem(IDC_EDIT1)->SetWindowTextW(strChat);//显示改变后内容
	// TODO: 在此添加控件通知处理程序代码
}


void CCalculatorDlg::OnBnClickedButton7()
{

	CString strChat,qp,result1;
	unsigned char a[100];
	unsigned char b[100];
	int len=0,l;
	 int iRes;
	 USHORT Z;
	GetDlgItem(IDC_EDIT1)->GetWindowTextW(strChat);//得到原有内容
	result1 = strChat;
	strChat.Format(_T(" %s"), strChat);
	l = strChat.GetLength();
	for (; l; l--)
	{
		if (strChat[l - 1] == _T(' '))
		{
			qp = strChat.Right(2);
			strChat.Delete(l, 2);
			strChat.TrimRight();
			qp.Format(_T("0x%s"), qp);
			StrToIntEx(qp, STIF_SUPPORT_HEX, &iRes);

			while (iRes != 0)
			{
				a[len] = iRes & 0xFF;
				iRes >>= 8;
				len++;
			}
		}
		//a[3] = a[0];
			//a[0] = a[1];
			//a[1] = a[3];
		
	}
	int j = len-1;
	for (int i = 0; i < len; i++)
	{
		
	
			b[i] = a[j];
			j--;
	}

	Z = CRC16(b, len);

	//result1.Empty();
	result1.Format(_T("%s(CRC16)\r\n%x"),  result1,Z );
	GetDlgItem(IDC_EDIT1)->SetWindowTextW(result1);//显示改变后内容
	// TODO: 在此添加控件通知处理程序代码

}


void CCalculatorDlg::OnBnClickedButton35()
{
	CString strChat;
	GetDlgItem(IDC_EDIT1)->GetWindowTextW(strChat);//得到原有内容
	GetDlgItem(IDC_BUTTON4)->EnableWindow(FALSE);//得到原有内容
	strChat.Append(_T("Tan"));//追加内容
	GetDlgItem(IDC_EDIT1)->SetWindowTextW(strChat);//显示改变后内容
	GetDlgItem(IDC_BUTTON4)->EnableWindow(true);//得到原有内容

	// TODO: 在此添加控件通知处理程序代码
}


void CCalculatorDlg::OnBnClickedButton6()
{
	CString strChat;
	GetDlgItem(IDC_EDIT1)->GetWindowTextW(strChat);//得到原有内容
	strChat.Append(_T(" "));//追加内容
	GetDlgItem(IDC_EDIT1)->SetWindowTextW(strChat);//显示改变后内容
	// TODO: 在此添加控件通知处理程序代码
}  


void CCalculatorDlg::tanchu()
{
	help dlg;
	dlg.DoModal();
	// TODO: 在此添加命令处理程序代码
}


void CCalculatorDlg::OnBnClickedButton36()
{

	CString strChat;
	GetDlgItem(IDC_EDIT1)->GetWindowTextW(strChat);//得到原有内容
	strChat.Append(_T("A"));//追加内容
	GetDlgItem(IDC_EDIT1)->SetWindowTextW(strChat);//显示改变后内容
	GetDlgItem(IDC_BUTTON4)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON10)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON9)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON11)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON8)->EnableWindow(FALSE);//得到原有内容
	//GetDlgItem(IDC_BUTTON6)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON1)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON24)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON27)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON16)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON15)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON12)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON13)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON18)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON31)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON2)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON32)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON19)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON35)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON34)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON30)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON5)->EnableWindow(FALSE);//得到原有内容

	// TODO: 在此添加控件通知处理程序代码
}


void CCalculatorDlg::OnBnClickedButton37()
{
	CString strChat;
	GetDlgItem(IDC_EDIT1)->GetWindowTextW(strChat);//得到原有内容
	strChat.Append(_T("B"));//追加内容
	GetDlgItem(IDC_EDIT1)->SetWindowTextW(strChat);//显示改变后内容
	GetDlgItem(IDC_BUTTON4)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON10)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON9)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON11)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON8)->EnableWindow(FALSE);//得到原有内容
	//GetDlgItem(IDC_BUTTON6)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON1)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON24)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON27)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON16)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON15)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON12)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON13)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON18)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON31)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON2)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON32)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON19)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON35)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON34)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON30)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON5)->EnableWindow(FALSE);//得到原有内容
	// TODO: 在此添加控件通知处理程序代码
}


void CCalculatorDlg::OnBnClickedButton38()
{
	CString strChat;
	GetDlgItem(IDC_EDIT1)->GetWindowTextW(strChat);//得到原有内容
	strChat.Append(_T("C"));//追加内容
	GetDlgItem(IDC_EDIT1)->SetWindowTextW(strChat);//显示改变后内容
	GetDlgItem(IDC_BUTTON4)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON10)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON9)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON11)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON8)->EnableWindow(FALSE);//得到原有内容
	//GetDlgItem(IDC_BUTTON6)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON1)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON24)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON27)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON16)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON15)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON12)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON13)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON18)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON31)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON2)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON32)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON19)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON35)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON34)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON30)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON5)->EnableWindow(FALSE);//得到原有内容
	// TODO: 在此添加控件通知处理程序代码
}


void CCalculatorDlg::OnBnClickedButton39()
{
	CString strChat;
	GetDlgItem(IDC_EDIT1)->GetWindowTextW(strChat);//得到原有内容
	strChat.Append(_T("D"));//追加内容
	GetDlgItem(IDC_EDIT1)->SetWindowTextW(strChat);//显示改变后内容
	GetDlgItem(IDC_BUTTON4)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON10)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON9)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON11)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON8)->EnableWindow(FALSE);//得到原有内容
	//GetDlgItem(IDC_BUTTON6)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON1)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON24)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON27)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON16)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON15)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON12)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON13)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON18)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON31)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON2)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON32)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON19)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON35)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON34)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON30)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON5)->EnableWindow(FALSE);//得到原有内容
	// TODO: 在此添加控件通知处理程序代码
}


void CCalculatorDlg::OnBnClickedButton40()
{
	CString strChat;
	GetDlgItem(IDC_EDIT1)->GetWindowTextW(strChat);//得到原有内容
	strChat.Append(_T("E"));//追加内容
	GetDlgItem(IDC_EDIT1)->SetWindowTextW(strChat);//显示改变后内容
	GetDlgItem(IDC_BUTTON4)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON10)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON9)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON11)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON8)->EnableWindow(FALSE);//得到原有内容
	//GetDlgItem(IDC_BUTTON6)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON1)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON24)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON27)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON16)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON15)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON12)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON13)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON18)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON31)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON2)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON32)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON19)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON35)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON34)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON30)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON5)->EnableWindow(FALSE);//得到原有内容
	// TODO: 在此添加控件通知处理程序代码
}


void CCalculatorDlg::OnBnClickedButton41()
{
	CString strChat;
	GetDlgItem(IDC_EDIT1)->GetWindowTextW(strChat);//得到原有内容
	strChat.Append(_T("F"));//追加内容
	GetDlgItem(IDC_EDIT1)->SetWindowTextW(strChat);//显示改变后内容
	GetDlgItem(IDC_BUTTON4)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON10)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON9)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON11)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON8)->EnableWindow(FALSE);//得到原有内容
	//GetDlgItem(IDC_BUTTON6)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON1)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON24)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON27)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON16)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON15)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON12)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON13)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON18)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON31)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON2)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON32)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON19)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON35)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON34)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON30)->EnableWindow(FALSE);//得到原有内容
	GetDlgItem(IDC_BUTTON5)->EnableWindow(FALSE);//得到原有内容
	// TODO: 在此添加控件通知处理程序代码
}


void CCalculatorDlg::OnBnClickedButton42()
{
	CString strChat, strChat1;
	int b[16], n = 0;
//	for (int j = 0; j < 16; j++)b[j] = 0;
	//	char str[100] = { '\0' };

	GetDlgItem(IDC_EDIT1)->GetWindowTextW(strChat);//得到原有内容
	strChat1 = strChat;//保存原有内容
	//int len;
	//len= strChat.GetLength();
	
	int bin = _ttoi(strChat);
	strChat.Empty();
	while (bin)
	{
		b[n++] = bin % 16;
		bin = bin / 16;
	}
	for (; n > 0; n--)
	{
		switch (b[n-1])
		{
		case 10:strChat.Append(_T("A")); break;
		case 11:strChat.Append(_T("B")); break;
		case 12:strChat.Append(_T("C")); break;
		case 13:strChat.Append(_T("D")); break;
		case 14:strChat.Append(_T("E")); break;
		case 15:strChat.Append(_T("F")); break;
		default:
			strChat.Format(_T("%s%d"), strChat, b[n - 1]);
			break;
		}
	}
	strChat1.Format(_T("%s(Hex)\r\n%s"), strChat1, strChat);
	GetDlgItem(IDC_EDIT1)->SetWindowTextW(strChat1);//显示改变后内容
	// TODO: 在此添加控件通知处理程序代码
}


BOOL CCalculatorDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	m_stat.RelayEvent(pMsg);
	return CDialog::PreTranslateMessage(pMsg);
	return CDialogEx::PreTranslateMessage(pMsg);
}


void CCalculatorDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);
	CDialog::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here  
	if (m_listRect.GetCount() > 0)
	{
		CRect dlgNow;
		GetWindowRect(&dlgNow);
		POSITION pos = m_listRect.GetHeadPosition();//第一个保存的是对话框的Rect  

		CRect dlgSaved;
		dlgSaved = m_listRect.GetNext(pos);
		ScreenToClient(dlgNow);

		float x = dlgNow.Width() * 1.0 / dlgSaved.Width();//根据当前和之前保存的对话框的宽高求比例  
		float y = dlgNow.Height() * 1.0 / dlgSaved.Height();
		ClientToScreen(dlgNow);

		CRect childSaved;

		CWnd* pWnd = GetWindow(GW_CHILD);
		while (pWnd)
		{
			childSaved = m_listRect.GetNext(pos);//依次获取子窗体的Rect  
			childSaved.left = dlgNow.left + (childSaved.left - dlgSaved.left) * x;//根据比例调整控件上下左右距离对话框的距离  
			childSaved.right = dlgNow.right + (childSaved.right - dlgSaved.right) * x;
			childSaved.top = dlgNow.top + (childSaved.top - dlgSaved.top) * y;
			childSaved.bottom = dlgNow.bottom + (childSaved.bottom - dlgSaved.bottom) * y;
			ScreenToClient(childSaved);
			pWnd->MoveWindow(childSaved);
			pWnd = pWnd->GetNextWindow();
		}
	}
	// TODO: 在此处添加消息处理程序代码
}
