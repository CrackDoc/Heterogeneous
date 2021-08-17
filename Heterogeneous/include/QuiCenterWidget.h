#ifndef QuiCenterWidget_h__
#define QuiCenterWidget_h__

#include <QtWidgets/QMainWindow>
#include <QPainter>

class QMouseEvent;

class CQuiCenterWidget : public QMainWindow
{
    Q_OBJECT
public:
    CQuiCenterWidget(QWidget *parent = Q_NULLPTR);
	~CQuiCenterWidget();
protected:
	void mousePressEvent(QMouseEvent* event);
	void mouseMoveEvent(QMouseEvent* event);
	void mouseReleaseEvent(QMouseEvent* event);
	void paintEvent(QPaintEvent* event);
};
#endif // QuiCenterWidget_h__
