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
}

void CDockTitleBar::SetDocTitle(const QString& strTitle)
{
	m_strTilte = strTitle;
	ui->TitleLbl->setText(m_strTilte);
}

void CDockTitleBar::SlotClickedMin()
{
	emit SignalMiniShow();
}

void CDockTitleBar::SlotClickedFloat()
{
	QDockWidget* dw = qobject_cast<QDockWidget*>(parentWidget());
	Q_ASSERT(dw != 0);
	dw->setFloating(true);
}
void CDockTitleBar::mouseMoveEvent(QMouseEvent* event)
{
	// ������ס������Ӧ�¼�
	if (m_bKeepPressed)
	{
		QDockWidget* mWidParent = qobject_cast<QDockWidget*>(parentWidget());
		if (mWidParent)
		{
			// ���������ƶ���������֮ǰ��λ�ü�������ƶ���λ�á�event->globalPos()- mPntStart��
			if (!mWidParent->isFloating())
			{
				mWidParent->setFloating(true);
			}
			mWidParent->move(mWidParent->geometry().topLeft() + event->globalPos() - m_PntStart);
			// ���������Ļ�е�λ���滻Ϊ�µ�λ��
			m_PntStart = event->globalPos();
		}

	}
	QWidget::mouseMoveEvent(event);
}

void CDockTitleBar::mousePressEvent(QMouseEvent* event)
{
	// �����������¼�
	if (event->button() == Qt::LeftButton)
	{
		// ��¼���״̬
		m_bKeepPressed = true;
		// ��¼�������Ļ�е�λ��
		m_PntStart = event->globalPos();
	}
	QWidget::mousePressEvent(event);
}

void CDockTitleBar::mouseReleaseEvent(QMouseEvent* event)
{
	// �������ͷ�
	if (event->button() == Qt::LeftButton)
	{
		// ��¼���״̬
		m_bKeepPressed = false;
	}
	QWidget::mouseReleaseEvent(event);
}

void CDockTitleBar::mouseDoubleClickEvent(QMouseEvent* event)
{
	if (event->button() == Qt::LeftButton)
	{
		QDockWidget* mWidParent = qobject_cast<QDockWidget*>(parentWidget());
		if (mWidParent)
		{
			bool bFloat = mWidParent->isFloating();
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
