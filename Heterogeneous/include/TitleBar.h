#ifndef TitleBar_h__
#define TitleBar_h__

#include <QtWidgets/QWidget>

namespace Ui {
	class TitleBarClass;
}
class CTitleBar : public QWidget
{
    Q_OBJECT

public:
    CTitleBar(bool bFloatWnd = true,QString strTitle = "",QWidget *parent = Q_NULLPTR);

	~CTitleBar();

	void Initialize();
		
	void SetBarTitle(const QString& strTitle);

	bool GetKeepMousePressed() { return m_bKeepPressed;}

	void SetFloatWindow(bool bFloat);

	bool GetFloatWindow() { return m_bFloatWindow; }

	void SetNoneBar();

protected:
	void mousePressEvent(QMouseEvent* event);
	void mouseMoveEvent(QMouseEvent* event);
	void mouseReleaseEvent(QMouseEvent* event);
	void mouseDoubleClickEvent(QMouseEvent* event);

private:
	// 鼠标上次移动开始时相对屏幕的位置
	QPoint m_PntStart;
	// 鼠标是否持续按下
	bool m_bKeepPressed;

signals:
	void SignalMiniWindow();
	void SignalMaxWindow();
	void SignalCloseWindow();

private:
    Ui::TitleBarClass *ui;
	QString m_strTilte;

	bool m_bFloatWindow;
};
#endif // TitleBar_h__
