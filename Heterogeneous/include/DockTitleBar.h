#ifndef DockTitleBar_h__
#define DockTitleBar_h__

#include <QtWidgets/QWidget>

namespace Ui {
	class DockTitleBarClass;
}
class CDockTitleBar : public QWidget
{
    Q_OBJECT

public:
    CDockTitleBar(QString strTitle = "",QWidget *parent = Q_NULLPTR);
	~CDockTitleBar();
	QSize sizeHint() const { return minimumSizeHint(); }
	QSize minimumSizeHint() const;

	void Initialize();
		
	void SetDocTitle(const QString& strTitle);

protected:
	void mousePressEvent(QMouseEvent* event);
	void mouseMoveEvent(QMouseEvent* event);
	void mouseReleaseEvent(QMouseEvent* event);
	void mouseDoubleClickEvent(QMouseEvent* event);

public slots:
	void SlotClickedMin();
	void SlotClickedFloat();
private:
	// 鼠标上次移动开始时相对屏幕的位置
	QPoint m_PntStart;
	// 鼠标是否持续按下
	bool m_bKeepPressed;

signals:
	void SignalMiniShow();

private:
    Ui::DockTitleBarClass *ui;

	QString m_strTilte;
	// 浮动状态
	bool m_bFloat;
};
#endif // DockTitleBar_h__
