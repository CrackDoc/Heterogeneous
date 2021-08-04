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
	// ����ź����Ӵ��ڹ������ź�,���������ϴ���,�������ĸ�������Ҫ���
	// �źžͼ������Ϸ����ź�
	if (m_DocTitleBar->GetKeepMousePressed() && !this->isFloating())
	{
		this->setFloating(true);
	}
}
