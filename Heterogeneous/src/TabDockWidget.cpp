#include "TabDockWidget.h"
#include <TitleBar.h>
#include <QLayout>

CTabDockWidget::CTabDockWidget(QWidget* parant /*= 0*/, QString strTitle)
	:QDockWidget(parant)
	, m_strTitleName(strTitle)
	, m_DocTitleBar(new CTitleBar(false,strTitle,this))
{
	setMouseTracking(true);
	Initialize();
}
CTabDockWidget::~CTabDockWidget()
{

}

void CTabDockWidget::Initialize()
{
	this->setTitleBarWidget(m_DocTitleBar);
	this->layout()->setContentsMargins(0, 0, 0, 0);
}

void CTabDockWidget::SetDockTitle(const QString& strTitle)
{
	m_DocTitleBar->SetBarTitle(strTitle);
}
void CTabDockWidget::SetDockWidget(QWidget* pDocWidget)
{
	this->setWidget(pDocWidget);
}

void CTabDockWidget::SetTitleBarEnabled(bool bEnable)
{
	m_DocTitleBar->SetTitleBarEnabled(bEnable);
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
