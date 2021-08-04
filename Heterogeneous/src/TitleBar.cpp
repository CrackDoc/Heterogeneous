#include "TitleBar.h"
#include "ui_TitleBar.h"
#include <QEvent>
#include <QMouseEvent>
#include <QStyle>
CTitleBar::CTitleBar(bool bFloatWnd,QString strTitle,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TitleBarClass)
	, m_bKeepPressed(false)
	, m_strTilte(strTitle)
	, m_bFloatWindow(bFloatWnd)
{
    ui->setupUi(this);

	Initialize();

	connect(ui->MinBtn, SIGNAL(clicked()), this, SIGNAL(SignalMiniWindow()));

	connect(ui->ClosBtn, SIGNAL(clicked()), this, SIGNAL(SignalMaxWindow()));

	connect(ui->MaxBtn, SIGNAL(clicked()), this, SIGNAL(SignalCloseWindow()));

}
CTitleBar::~CTitleBar()
{
	
}
void CTitleBar::Initialize()
{
	ui->TitleLbl->setText(m_strTilte);
	ui->MinBtn->setIcon(style()->standardIcon(QStyle::SP_TitleBarMinButton));
	ui->MaxBtn->setIcon(style()->standardIcon(QStyle::SP_TitleBarNormalButton));
	ui->ClosBtn->setIcon(style()->standardIcon(QStyle::SP_TitleBarCloseButton));
}

void CTitleBar::SetBarTitle(const QString& strTitle)
{
	m_strTilte = strTitle;
	ui->TitleLbl->setText(m_strTilte);
}

void CTitleBar::SetFloatWindow(bool bFloat)
{
	m_bFloatWindow = bFloat;
}

void CTitleBar::SetTitleBarEnabled(bool bEnabled)
{
	if (bEnabled)
	{
		ui->CenterWidget->show();
	}
	else 
	{
		ui->CenterWidget->hide();
	}

}

void CTitleBar::mouseMoveEvent(QMouseEvent* event)
{
	// 持续按住才做对应事件
	if (m_bKeepPressed)
	{
		QWidget* mWidParent = qobject_cast<QWidget*>(parentWidget());
		if (mWidParent)
		{
			mWidParent->move(mWidParent->geometry().topLeft() + event->globalPos() - m_PntStart);
			// 将鼠标在屏幕中的位置替换为新的位置
			m_PntStart = event->globalPos();
		}
	}
	QWidget::mouseMoveEvent(event);
}

void CTitleBar::mousePressEvent(QMouseEvent* event)
{
	// 鼠标左键按下事件
	if (event->button() == Qt::LeftButton)
	{
		// 记录鼠标状态
		m_bKeepPressed = true;
		m_bFloatWindow = true;
		// 记录鼠标在屏幕中的位置
		m_PntStart = event->globalPos();
	}
	QWidget::mousePressEvent(event);
}

void CTitleBar::mouseReleaseEvent(QMouseEvent* event)
{
	// 鼠标左键释放
	if (event->button() == Qt::LeftButton)
	{
		// 记录鼠标状态
		m_bKeepPressed = false;
	}
	QWidget::mouseReleaseEvent(event);
}

void CTitleBar::mouseDoubleClickEvent(QMouseEvent* event)
{
	if (event->button() == Qt::LeftButton)
	{
		QWidget* mWidParent = qobject_cast<QWidget*>(parentWidget());
		if (mWidParent)
		{
			bool bFloat = m_bFloatWindow;
			if (bFloat)
			{
				if (mWidParent->isMaximized())
				{
					mWidParent->showNormal();
				}
				else
				{
					mWidParent->showMaximized();
				}
			}
		}
	}
	QWidget::mouseDoubleClickEvent(event);
}
