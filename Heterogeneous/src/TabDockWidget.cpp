#include "TabDockWidget.h"
#include <DockTitleBar.h>
#include <QLayout>

CTabDockWidget::CTabDockWidget(QWidget* parant /*= 0*/, QString strTitle)
	:QDockWidget(parant)
	, m_strTitleName(strTitle)
	, m_DocTitleBar(new CDockTitleBar(strTitle,this))
{
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
	m_DocTitleBar->SetDocTitle(strTitle);
}
void CTabDockWidget::SetDockWidget(QWidget* pDocWidget)
{
	this->setWidget(pDocWidget);
}
