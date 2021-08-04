#include "Heterogeneous.h"
#include "ui_Heterogeneous.h"
#include "QuiWndBarModule.h"
#include <QToolBar>
#include <QIcon>
#include "QuiProjectModule.h"

CHeterogeneous::CHeterogeneous(QWidget *parent)
    : QMainWindow(parent)
    ,ui(new Ui::HeterogeneousClass)
	, m_nEdgeMargin(2) //设置检测边缘为4
	, m_EResizeDir(nodir) //初始化检测方向为无
	, m_bMousePress(false)
{
    ui->setupUi(this);
	//重设大小
	resize(1120, 800);

    QString qstrWindowTitle = tr("CC Plane VMC vs BFCC Heterogeneous Union");
    this->setWindowTitle(qstrWindowTitle);

	//设置窗体标题栏隐藏并设置位于顶层
	setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint | Qt::Dialog);

	setMouseTracking(true);

    Initialize();
}
CHeterogeneous::~CHeterogeneous()
{
	
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

void CHeterogeneous::InitializeFrameWorksUi()
{

	this->setCentralWidget(ui->CenterWidget);

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

	QWidget* bar = qobject_cast<QWidget*>(pQtWndBar);

	QMenu* pMenu0 = new QMenu(QString::fromLocal8Bit("文件"));
	pMenu0->addAction(QString::fromLocal8Bit("打开"));
	pMenu0->addAction(QString::fromLocal8Bit("关闭"));
	//pMenu0->setFixedWidth(200);

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

	this->setMenuWidget(bar);

	connect(bar, SIGNAL(SignalShowMinWindow()), this, SLOT(SlotShowMinWindow()));
	connect(bar, SIGNAL(SignalShowMaxWindow()), this, SLOT(SlotShowMaxWindow()));
	connect(bar, SIGNAL(SignalCloseWindow()), this, SLOT(SlotCloseWindow()));

	// Hide some Class
	if (1)
	{
		ui->LeftToolBtns->hide();
		//ui->RightToolBtns->hide();
	}
	// 设置ToolBar

	QToolBar* toolBar = this->addToolBar("");
	toolBar->addAction(style()->standardIcon(QStyle::SP_DirOpenIcon), QString::fromLocal8Bit("文件"));
	toolBar->addAction(style()->standardIcon(QStyle::SP_DriveNetIcon), QString::fromLocal8Bit("网络"));
	toolBar->addAction(style()->standardIcon(QStyle::SP_DialogSaveButton), QString::fromLocal8Bit("保存"));
	toolBar->addAction(style()->standardIcon(QStyle::SP_ArrowLeft), QString::fromLocal8Bit("前进"));
	toolBar->addAction(style()->standardIcon(QStyle::SP_ArrowRight), QString::fromLocal8Bit("后退"));
	toolBar->addAction(style()->standardIcon(QStyle::SP_ArrowUp), QString::fromLocal8Bit("向上"));
	toolBar->addAction(style()->standardIcon(QStyle::SP_ArrowDown), QString::fromLocal8Bit("向下"));

	//QToolBar* toolBar1 = this->addToolBar("");

	//QAction* testAction = new QAction(QString::fromLocal8Bit("测试结果"), toolBar1);

	//QAction* resultAction = new QAction(QString::fromLocal8Bit("综合"), toolBar1);

	//toolBar1->addAction(testAction);
	//toolBar1->addAction(resultAction);

	//toolBar1->setAllowedAreas(Qt::RightToolBarArea);

}
void CHeterogeneous::InitializeDockWidgt()
{
	QTabWidget* contentTab = new QTabWidget(ui->ContentTabWidget);
	contentTab->setObjectName("contentTab");
	QWidget* Tab0 = new QWidget(contentTab);
	contentTab->addTab(Tab0, QString::fromLocal8Bit("项目文件"));

	QWidget* Tab1 = new QWidget(contentTab);
	contentTab->addTab(Tab1, QString::fromLocal8Bit("资源文件"));

	ui->ContentTabWidget->SetDockTitle(QString::fromLocal8Bit("内容"));

	ui->ContentTabWidget->SetTitleBarEnabled(false);

	ui->ContentTabWidget->SetDockWidget(contentTab);

	ui->OutPutWidget->SetDockTitle(QString::fromLocal8Bit("输出"));

}
void CHeterogeneous::InitializeModules()
{
	GetOrCreateQuiProjectModule()->SetWorkSpaceDir("C:/Qt/Qt5.9.8");
	GetOrCreateQuiProjectModule()->FlushWorkSpaceDir();
	ui->ProjectWidget->SetDockTitle(QString::fromLocal8Bit("解决方案"));
	ui->ProjectWidget->SetDockWidget(GetOrCreateQuiProjectModule());
}
void CHeterogeneous::SlotCloseWindow()
{
	this->close();
}

void CHeterogeneous::SlotShowMaxWindow()
{
	this->showMaximized();
}

void CHeterogeneous::SlotShowMinWindow()
{
	this->showMinimized();
}

void CHeterogeneous::mousePressEvent(QMouseEvent* event)
{
	event->ignore();
	if (event->buttons() & Qt::LeftButton)
	{
		//setCursor(Qt::ArrowCursor);
		m_bMousePress = true;
	}
	QMainWindow::mousePressEvent(event);
}
void CHeterogeneous::mouseMoveEvent(QMouseEvent* event)
{
	event->ignore();

	if (m_bMousePress)
	{
		if (m_EResizeDir != nodir)
		{
			DragingEdgeResize(event,m_EResizeDir);
		}
	}
	else
	{
		CheckingEdge();   
	}
	QMainWindow::mouseMoveEvent(event);
}
void CHeterogeneous::mouseReleaseEvent(QMouseEvent* event)
{
	event->ignore();
	setCursor(Qt::ArrowCursor);
	m_bMousePress = false;
	QMainWindow::mouseReleaseEvent(event);
}

void CHeterogeneous::leaveEvent(QEvent* event)
{
	event->ignore();
	setCursor(Qt::ArrowCursor);
	m_bMousePress = false;
	QMainWindow::leaveEvent(event);
}

void CHeterogeneous::DragingEdgeResize(QMouseEvent* event, ERESIZE_TYPE type)
{
	int ptop, pbottom, pleft, pright;                   //窗口上下左右的值
	ptop = frameGeometry().top();
	pbottom = frameGeometry().bottom();
	pleft = frameGeometry().left();
	pright = frameGeometry().right();
	if (type & top)
	{                               //检测更改尺寸方向中包含的上下左右分量
		ptop = event->globalY();
	}
	else if (type & bottom) {

		pbottom = event->globalY();

	}
	if (type & left)
	{
		if (event->globalX() < mapToGlobal(this->rect().topLeft()).x())
		{
			pleft = event->globalX();
		}
		//检测左右分量
		if (width() > this->minimumWidth())
		{
			pleft = event->globalX();
		}
	}
	else if (type & right)
	{
		pright = event->globalX();
	}
	setGeometry(QRect(QPoint(pleft, ptop), QPoint(pright, pbottom)));

}
void CHeterogeneous::CheckingEdge()
{
	int diffLeft = abs(cursor().pos().x() - frameGeometry().left());      //计算鼠标距离窗口上下左右有多少距离
	int diffRight = abs(cursor().pos().x() - frameGeometry().right());
	int diffTop = abs(cursor().pos().y() - frameGeometry().top());
	int diffBottom = abs(cursor().pos().y() - frameGeometry().bottom());

	QCursor tempCursor;                                    //获得当前鼠标样式，注意:只能获得当前鼠标样式然后再重新设置鼠标样式
	tempCursor = cursor();                                 //因为获得的不是鼠标指针，所以不能这样用:cursor().setXXXXX

	if (diffTop < m_nEdgeMargin) {                              //根据 边缘距离 分类改变尺寸的方向
		if (diffLeft < m_nEdgeMargin) {
			m_EResizeDir = topLeft;
			tempCursor.setShape(Qt::SizeFDiagCursor);
		}
		else if (diffRight < m_nEdgeMargin) {
			m_EResizeDir = topRight;
			tempCursor.setShape(Qt::SizeBDiagCursor);
		}
		else {
			m_EResizeDir = top;
			tempCursor.setShape(Qt::SizeVerCursor);
		}
	}
	else if (diffBottom < m_nEdgeMargin) {
		if (diffLeft < m_nEdgeMargin) {
			m_EResizeDir = bottomLeft;
			tempCursor.setShape(Qt::SizeBDiagCursor);
		}
		else if (diffRight < m_nEdgeMargin) {
			m_EResizeDir = bottomRight;
			tempCursor.setShape(Qt::SizeFDiagCursor);
		}
		else {
			m_EResizeDir = bottom;
			tempCursor.setShape(Qt::SizeVerCursor);
		}
	}
	else if (diffLeft < m_nEdgeMargin) {
		m_EResizeDir = left;
		tempCursor.setShape(Qt::SizeHorCursor);
	}
	else if (diffRight < m_nEdgeMargin) {
		m_EResizeDir = right;
		tempCursor.setShape(Qt::SizeHorCursor);
	}
	else {
		m_EResizeDir = nodir;
		tempCursor.setShape(Qt::ArrowCursor);
	}
	setCursor(tempCursor);                    //重新设置鼠标,主要是改样式
}
