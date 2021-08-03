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

public slots:
	void SlotClickedMin();
	void SlotClickedFloat();
private:
	// ����ϴ��ƶ���ʼʱ�����Ļ��λ��
	QPoint m_PntStart;
	// ����Ƿ��������
	bool m_bKeepPressed;

private:
    Ui::DockTitleBarClass *ui;

	QString m_strTilte;
};
#endif // DockTitleBar_h__
