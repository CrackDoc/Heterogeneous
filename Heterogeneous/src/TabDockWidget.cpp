#include "TabDockWidget.h"
#include <TitleBar.h>
#include <QLayout>

CTabDockWidget::CTabDockWidget(CTitleBar::E_BAR_TYPE type,QString strTitle,QWidget* parant)
	:QDockWidget(parant)
	, m_strTitleName(strTitle)
	, m_DocTitleBar(new CTitleBar(type,false,strTitle,this))
	, m_EmptyWidget(new QWidget(this))
{
	setMouseTracking(true);
	Initialize();
}
CTabDockWidget::~CTabDockWidget()
{
	if (m_EmptyWidget != nullptr)
	{
		delete m_EmptyWidget;
		m_EmptyWidget = nullptr;
	}

	if (m_DocTitleBar != nullptr)
	{
		delete m_DocTitleBar;
		m_DocTitleBar = nullptr;
	}

}

void CTabDockWidget::Initialize()
{
	this->setTitleBarWidget(m_DocTitleBar);
}

void CTabDockWidget::SetDockTitle(const QString& strTitle)
{
	this->setWindowTitle(strTitle);

	m_DocTitleBar->SetBarTitle(strTitle);
}
void CTabDockWidget::SetDockWidget(QWidget* pDocWidget)
{
	this->setWidget(pDocWidget);
}

void CTabDockWidget::SetTitleBarEnabled(bool bEnable)
{
	this->setTitleBarWidget(m_EmptyWidget);
}

void CTabDockWidget::SetWidgetEnabled(bool bEnable)
{
	m_EmptyWidget->setFixedHeight(0);
	this->setWidget(m_EmptyWidget);
}

QPushButton* CTabDockWidget::AppendAction(QIcon InIcon, QString text)
{
	return m_DocTitleBar->AppendAction(InIcon,text);
}

void CTabDockWidget::EnabledMove(bool bMove)
{
	m_DocTitleBar->EnabledMove(bMove);
}

void CTabDockWidget::mouseMoveEvent(QMouseEvent* event)
{
	setCursor(Qt::ArrowCursor);
	QDockWidget::mouseMoveEvent(event);
}

void CTabDockWidget::mousePressEvent(QMouseEvent* event)
{
	// 这个信号重子窗口过来的信号,不继续向上传递,如果外面的父窗口需要这个
	// 信号就继续向上发送信号
	if (m_DocTitleBar->GetKeepMousePressed() && !this->isFloating())
	{
		this->setFloating(true);
	}
}
