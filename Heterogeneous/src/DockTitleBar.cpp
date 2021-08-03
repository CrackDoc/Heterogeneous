#include "DockTitleBar.h"
#include "ui_DockTitleBar.h"
#include <QDockWidget>
#include <QEvent>
#include <QMouseEvent>

CDockTitleBar::CDockTitleBar(QString strTitle,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DockTitleBarClass)
	, m_bKeepPressed(false)
	, m_strTilte(strTitle)
	, m_bFloat(false)
{
    ui->setupUi(this);

	Initialize();

	connect(ui->MinBtn, &QPushButton::clicked, this, &CDockTitleBar::SlotClickedMin);

	connect(ui->MaxBtn, &QPushButton::clicked, this, &CDockTitleBar::SlotClickedFloat);
	
}
CDockTitleBar::~CDockTitleBar()
{
	
}

QSize CDockTitleBar::minimumSizeHint() const
{
	QDockWidget* dw = qobject_cast<QDockWidget*>(parentWidget());
	Q_ASSERT(dw != 0);
	QSize result(200, 30);
	if (dw->features() & QDockWidget::DockWidgetVerticalTitleBar)
		result.transpose();
	return result;
}

void CDockTitleBar::Initialize()
{
	ui->TitleLbl->setText(m_strTilte);
	ui->MinBtn->setIcon(style()->standardIcon(QStyle::SP_TitleBarMinButton));
	ui->MaxBtn->setIcon(style()->standardIcon(QStyle::SP_TitleBarNormalButton));
	ui->CloseBtn->setIcon(style()->standardIcon(QStyle::SP_TitleBarCloseButton));
}

void CDockTitleBar::SetDocTitle(const QString& strTitle)
{
	m_strTilte = strTitle;
	ui->TitleLbl->setText(m_strTilte);
}

void CDockTitleBar::SlotClickedMin()
{
	QDockWidget* dw = qobject_cast<QDockWidget*>(parentWidget());
	Q_ASSERT(dw != 0);
	dw->setFloating(!dw->isFloating());

	dw->topLevelChanged(true);
	
}

void CDockTitleBar::SlotClickedFloat()
{
	QDockWidget* dw = qobject_cast<QDockWidget*>(parentWidget());
	Q_ASSERT(dw != 0);
	dw->setFloating(!dw->isFloating());
	dw->topLevelChanged(true);
}


void CDockTitleBar::mouseMoveEvent(QMouseEvent* event)
{
	QDockWidget* mWidParent = qobject_cast<QDockWidget*>(parentWidget());
	// 持续按住才做对应事件
	if (m_bKeepPressed)
	{
		// 将父窗体移动到父窗体之前的位置加上鼠标移动的位置【event->globalPos()- mPntStart】
		mWidParent->move(mWidParent->geometry().topLeft() + event->globalPos() - m_PntStart);
		// 将鼠标在屏幕中的位置替换为新的位置
		m_PntStart = event->globalPos();
	}
	QWidget::mouseMoveEvent(event);
}

void CDockTitleBar::mousePressEvent(QMouseEvent* event)
{
	// 鼠标左键按下事件
	if (event->button() == Qt::LeftButton)
	{
		// 记录鼠标状态
		m_bKeepPressed = true;
		// 记录鼠标在屏幕中的位置
		m_PntStart = event->globalPos();
	}

	QWidget::mousePressEvent(event);
}

void CDockTitleBar::mouseReleaseEvent(QMouseEvent* event)
{
	// 鼠标左键释放
	if (event->button() == Qt::LeftButton)
	{
		// 记录鼠标状态
		m_bKeepPressed = false;
	}
	QWidget::mouseReleaseEvent(event);
}