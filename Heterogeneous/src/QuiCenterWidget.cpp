#include "QuiCenterWidget.h"
#include <QMouseEvent>

CQuiCenterWidget::CQuiCenterWidget(QWidget *parent)
    : QWidget(parent)
{
    setMouseTracking(true);
}
CQuiCenterWidget::~CQuiCenterWidget()
{
	
}

void CQuiCenterWidget::mousePressEvent(QMouseEvent* event)
{
    QWidget::mousePressEvent(event);
}

void CQuiCenterWidget::mouseMoveEvent(QMouseEvent* event)
{
    QWidget::mouseMoveEvent(event);
}

void CQuiCenterWidget::mouseReleaseEvent(QMouseEvent* event)
{
    QWidget::mouseReleaseEvent(event);
}
