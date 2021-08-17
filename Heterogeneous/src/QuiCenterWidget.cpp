#include "QuiCenterWidget.h"
#include <QMouseEvent>

CQuiCenterWidget::CQuiCenterWidget(QWidget *parent)
    : QMainWindow(parent)
{
    setMouseTracking(true);
}
CQuiCenterWidget::~CQuiCenterWidget()
{
	
}
void CQuiCenterWidget::mousePressEvent(QMouseEvent* event)
{
    QMainWindow::mousePressEvent(event);
}

void CQuiCenterWidget::mouseMoveEvent(QMouseEvent* event)
{
	setCursor(Qt::ArrowCursor);
    QMainWindow::mouseMoveEvent(event);
}

void CQuiCenterWidget::mouseReleaseEvent(QMouseEvent* event)
{
    QMainWindow::mouseReleaseEvent(event);
}

void CQuiCenterWidget::paintEvent(QPaintEvent* event)
{
	//Q_UNUSED(event);

	//QPainter p(this);

	//p.setPen(Qt::NoPen);

	//p.setBrush(QColor(0, 0, 0));

	//p.drawRect(rect());
}
