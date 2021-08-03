#ifndef QuiCenterWidget_h__
#define QuiCenterWidget_h__

#include <QtWidgets/QWidget>

class QMouseEvent;

class CQuiCenterWidget : public QWidget
{
    Q_OBJECT
public:
    CQuiCenterWidget(QWidget *parent = Q_NULLPTR);
	~CQuiCenterWidget();
protected:
	void mousePressEvent(QMouseEvent* event);
	void mouseMoveEvent(QMouseEvent* event);
	void mouseReleaseEvent(QMouseEvent* event);
};
#endif // QuiCenterWidget_h__
