﻿#include "Heterogeneous.h"
#include <QtWidgets/QMainWindow>
#include "QuiWndBarModule.h"
#include <QToolBar>
#include <QIcon>
#include "QuiProjectModule.h"
#include <QGridLayout>
#include "QuiTabDockWidget.h"
#include <QHBoxLayout>
#include <QDesktopWidget>
#include <QApplication>
#include <QStyle>
#include "QuiSystray.h"

CHeterogeneous::CHeterogeneous(QWidget *parent)
    : CQuiBaseWidget(parent)
	, m_pMainWindow(new QMainWindow(this))
	, m_pQuiSystray(new CQuiSystray(this))
{
	this->EnableTitleBar(false);
	this->SetDialogWidget(m_pMainWindow);
	this->EnableDialogStretch(true);
	m_pMainWindow->setCursor(Qt::ArrowCursor);
	resize(1120, 800);

	QString qstrWindowTitle = tr("CC Plane VMC vs BFCC Heterogeneous Union");
	//this->SetDialogTitle(qstrWindowTitle);

	Initialize();
}
CHeterogeneous::~CHeterogeneous()
{
	if (m_pQuiSystray != nullptr)
	{
		delete m_pQuiSystray;
		m_pQuiSystray = nullptr;
	}
	if (m_pMainWindow != nullptr)
	{
		delete m_pMainWindow;
		m_pMainWindow = nullptr;
	}
	
}
void CHeterogeneous::Initialize()
{
	//初始化界面框架
	InitializeFrameWorksUi();
	// 初始化DockWidgt
	InitializeDockWidgt();
	// 初始化模块
	InitializeModules();

}

const QString qStrWndBarStyle =
"QPushButton{"
"	border: 0px solid #9EA0A4;"
"	background - color: #8B8B8B;"
"	border - radius: 0px;"
"	color: rgb(255, 255, 255);"
"}"
"QPushButton:pressed{"
"	padding - right:0px;"
"	padding - bottom:0px;"
"	padding - top:0px;"
"	padding - left:0px;"
"	border: 0px solid #5388f3;"
"	background:#F0F0F0;"
"	color: rgb(255, 255, 255);"
"}"
"QPushButton:!hover{"
"	border: 0px solid #5388f3;"
"	background:#8B8B8B;"
"	color: rgb(255, 255, 255);"
"}"
"QPushButton:hover{"
"	border: 0px solid #5388f3;"
"	background:#F0F0F0;"
"	color: rgb(0, 0, 0);"
"}";
void CHeterogeneous::InitializeFrameWorksUi()
{
	class CTestMenuModule :public IQuiMenuModule
	{
	public:
		CTestMenuModule()
			:m_pQMenu(nullptr)
			, m_pWidget(nullptr) {}
		~CTestMenuModule() {}
	public:

		/**
		 * @fn       GetName
		 * @author   Crack
		 * @brief    获取名称
		 * @date     2021/7/29 9:57
		 * @param
		 * @return
		*/
		virtual std::string GetName() const { return ""; }

		/**
		 * @fn       GetCompany
		 * @author   Crack
		 * @brief    获取公司名称
		 * @date     2021/7/29 9:57
		 * @param
		 * @return
		*/
		virtual std::string GetCompany() const { return ""; }
		/**
		 * @fn       GetVersion
		 * @author   Crack
		 * @brief     获取版本号
		 * @date     2021/7/29 9:57
		 * @param
		 * @return
		*/
		virtual std::string GetVersion() const { return ""; }

		/**
		 * @fn       GetDescription
		 * @author   Crack
		 * @brief    描述信息
		 * @date     2021/7/29 9:58
		 * @param
		 * @return
		*/
		virtual std::string GetDescription() const { return ""; }

		/**
		 * @fn       Initialise
		 * @author   Crack
		 * @brief    初始化
		 * @date     2021/7/29 9:58
		 * @param
		 * @return
		*/

		virtual bool Initialise() { return false; }

		/**
		 * @fn       Uninitialise
		 * @author   Crack
		 * @brief    卸载信息
		 * @date     2021/7/29 9:59
		 * @param
		 * @return
		*/
		virtual bool Uninitialise() { return false; }

		/**
		 * @fn       SetModuleParent
		 * @author   Crack
		 * @brief    设置窗口父对象
		 * @date     2021/7/29 9:59
		 * @param
		 * @return
		*/
		virtual void SetModuleParent(QWidget* widget) {}
		/**
		 * @fn       GetMenu
		 * @author   Crack
		 * @brief       
		 * @date     2021/8/2 10:44
		 * @param    
		 * @return   
		*/
		virtual QMenu* GetMenu() {
			return m_pQMenu;
		}

		/**
 		 * @fn       SetMenu
 		 * @author   Crack
 		 * @brief       
 		 * @date     2021/8/2 10:45
 		 * @param    
 		 * @return   
		*/
		virtual void SetMenu(QMenu* pQMenu) { m_pQMenu = pQMenu; }

		/**
		 * @fn       GetWidget
		 * @author   Crack
		 * @brief       
		 * @date     2021/8/2 10:45
		 * @param    
		 * @return   
		*/
		virtual QWidget* GetWidget() {
			return m_pWidget;
		}

		/**
		 * @fn       SetWidget
		 * @author   Crack
		 * @brief       
		 * @date     2021/8/2 10:46
		 * @param    
		 * @return   
		*/
		virtual void SetWidget(QWidget* widget)
		{
			m_pWidget = widget;
		}
	private:
		QWidget* m_pWidget;
		QMenu* m_pQMenu;
	};
	// 设置MenuBar
	CQuiWndBarModule* pQtWndBar = GetOrCreateQuiWndBarModule();

	pQtWndBar->SetBarBackGroundColor(QColor("#8B8B8B"));
	pQtWndBar->SetBarSyleSheet(qStrWndBarStyle);
	pQtWndBar->Initialise();

	pQtWndBar->SetGeometryWidget(this);

	QWidget* bar = qobject_cast<QWidget*>(pQtWndBar);

	QMenu* pMenu0 = new QMenu(QString::fromLocal8Bit("文件"));
	pMenu0->addAction(QString::fromLocal8Bit("打开"));
	pMenu0->addAction(QString::fromLocal8Bit("关闭"));

	CTestMenuModule* Module0 = new CTestMenuModule();
	Module0->SetMenu(pMenu0);
	pQtWndBar->AppendMenuModule(Module0);

	QMenu* pMenu1 = new QMenu(QString::fromLocal8Bit("编辑"));
	CTestMenuModule* Module1 = new CTestMenuModule();
	Module1->SetMenu(pMenu1);
	pQtWndBar->AppendMenuModule(Module1);
	QMenu* pMenu2 = new QMenu(QString::fromLocal8Bit("源代码"));
	CTestMenuModule* Module2 = new CTestMenuModule();
	Module2->SetMenu(pMenu2);
	pQtWndBar->AppendMenuModule(Module2);

	QMenu* pMenu3 = new QMenu(QString::fromLocal8Bit("重构"));
	CTestMenuModule* Module3 = new CTestMenuModule();
	Module3->SetMenu(pMenu3);
	pQtWndBar->AppendMenuModule(Module3);
	QMenu* pMenu4 = new QMenu(QString::fromLocal8Bit("浏览"));
	CTestMenuModule* Module4 = new CTestMenuModule();
	Module4->SetMenu(pMenu4);
	pQtWndBar->AppendMenuModule(Module4);
	QMenu* pMenu5 = new QMenu(QString::fromLocal8Bit("项目"));
	CTestMenuModule* Module5 = new CTestMenuModule();
	Module5->SetMenu(pMenu5);
	pQtWndBar->AppendMenuModule(Module5);
	QMenu* pMenu6 = new QMenu(QString::fromLocal8Bit("窗口"));
	CTestMenuModule* Module6 = new CTestMenuModule();
	Module6->SetMenu(pMenu6);
	pQtWndBar->AppendMenuModule(Module6);
	QMenu* pMenu7 = new QMenu(QString::fromLocal8Bit("帮助"));
	CTestMenuModule* Module7 = new CTestMenuModule();
	Module7->SetMenu(pMenu7);
	pQtWndBar->AppendMenuModule(Module7);

	m_pMainWindow->setMenuWidget(bar);

	connect(bar, SIGNAL(SignalShowMinWindow()), this, SLOT(SlotShowMinWindow()));
	connect(bar, SIGNAL(SignalShowMaxWindow()), this, SLOT(SlotShowMaxWindow()));
	connect(bar, SIGNAL(SignalCloseWindow()), this, SLOT(SlotCloseWindow()));

}
void CHeterogeneous::InitializeDockWidgt()
{
	CQuiTabDockWidget* pContentWidget = new CQuiTabDockWidget();
	pContentWidget->resize(900, 558);
	QTabWidget* contentTab = new QTabWidget(this);
	pContentWidget->SetDockWidget(contentTab);
	contentTab->setContentsMargins(0, 0, 0, 0);
	contentTab->setObjectName("contentTab");
	QWidget* Tab0 = new QWidget(contentTab);
	contentTab->addTab(Tab0, QString::fromLocal8Bit("项目文件"));
	QWidget* Tab1 = new QWidget(contentTab);
	contentTab->addTab(Tab1, QString::fromLocal8Bit("资源文件"));
	contentTab->setStyleSheet("QTabWidget#contentTab{border:1px solid rgb(139, 139, 139);}");
	contentTab->setTabPosition(QTabWidget::TabPosition::North);

	pContentWidget->SetDockWidget(contentTab);
	pContentWidget->SetDockTitle(QString::fromLocal8Bit("内容"));
	pContentWidget->SetTitleBarEnabled(false);

	pContentWidget->setMinimumWidth(600);
	pContentWidget->setMinimumHeight(600);


	m_pMainWindow->setCentralWidget(pContentWidget);

	CQuiTabDockWidget* pOutputWidget = new CQuiTabDockWidget();
	pOutputWidget->SetDockTitle(QString::fromLocal8Bit("输出"));
	pOutputWidget->resize(900, 200);
	QWidget* outDocWidget = new QWidget(this);
	outDocWidget->setObjectName("outDocWidget");
	outDocWidget->setStyleSheet("QWidget#outDocWidget{border:1px solid rgb(139, 139, 139);}");
	outDocWidget->resize(900, 200);
	pOutputWidget->SetDockWidget(outDocWidget);
	pOutputWidget->setMinimumHeight(150);

	CQuiTabDockWidget* pPorjectWidget = new CQuiTabDockWidget();
	pPorjectWidget->resize(280, 758);
	GetOrCreateQuiProjectModule()->SetWorkSpaceDir("C:/Qt/Qt5.14.2");
	GetOrCreateQuiProjectModule()->FlushWorkSpaceDir();
	pPorjectWidget->SetDockTitle(QString::fromLocal8Bit("解决方案"));
	pPorjectWidget->SetDockWidget(GetOrCreateQuiProjectModule());
	GetOrCreateQuiProjectModule()->setMinimumWidth(200);

	//m_pCenterGridLayout->setRowStretch(0, 1);
	//m_pCenterGridLayout->setRowStretch(3, 1);
// 	m_pCenterGridLayout->setColumnStretch(1, 1);
// 	m_pCenterGridLayout->setColumnStretch(1, 3);

// 	m_pCenterGridLayout->addWidget(pPorjectWidget, 0, 0, 1, 1);
// 	m_pCenterGridLayout->addWidget(pContentWidget, 0, 1, 1, 1);
// 	m_pCenterGridLayout->addWidget(pOutputWidget, 1, 0, 1, 2);
	
	QToolBar* ToolBar = new QToolBar(this);
	ToolBar->setFixedHeight(25);
	ToolBar->addAction(style()->standardIcon(QStyle::SP_DirOpenIcon), QString::fromLocal8Bit("文件"));
	ToolBar->addAction(style()->standardIcon(QStyle::SP_DriveNetIcon), QString::fromLocal8Bit("网络"));
	ToolBar->addAction(style()->standardIcon(QStyle::SP_DialogSaveButton), QString::fromLocal8Bit("保存"));
	ToolBar->addAction(style()->standardIcon(QStyle::SP_ArrowLeft), QString::fromLocal8Bit("前进"));
	ToolBar->addAction(style()->standardIcon(QStyle::SP_ArrowRight), QString::fromLocal8Bit("后退"));
	ToolBar->addAction(style()->standardIcon(QStyle::SP_ArrowUp), QString::fromLocal8Bit("向上"));
	ToolBar->addAction(style()->standardIcon(QStyle::SP_ArrowDown), QString::fromLocal8Bit("向下"));
	m_pMainWindow->addToolBar(ToolBar);
	ToolBar->setMovable(false);

	m_pMainWindow->addDockWidget(Qt::LeftDockWidgetArea, pPorjectWidget);

	m_pMainWindow->splitDockWidget(pPorjectWidget, pContentWidget, Qt::Horizontal);
	m_pMainWindow->splitDockWidget(pContentWidget, pOutputWidget, Qt::Vertical);
    //tabifyDockWidget(pContentWidget, pOutputWidget1);
}
void CHeterogeneous::InitializeModules()
{
}
void CHeterogeneous::SlotCloseWindow()
{
	this->close();
	emit SignalQuit();
}

void CHeterogeneous::SlotShowMaxWindow()
{
	QDesktopWidget* desktopWidget = QApplication::desktop();
	//QRect screenRect = desktopWidget->screenGeometry();  //屏幕区域
	QRect screenRect = desktopWidget->availableGeometry();  //屏幕区域
	int w = screenRect.width() + 18;
	int h = screenRect.height() + 18;
	showMaximized();
	setGeometry(-9, -9, w, h);
}

void CHeterogeneous::SlotShowMinWindow()
{
	this->hide();
}
