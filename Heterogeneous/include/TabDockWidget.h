#ifndef TabDockWidget_h__
#define TabDockWidget_h__
#include <QtWidgets/QWidget>
#include <QtWidgets/QDockWidget>
#include <QMouseEvent>
#include "TitleBar.h"
#include <QIcon>
class CTabDockWidget :public QDockWidget
{
	Q_OBJECT
public:
	CTabDockWidget(CTitleBar::E_BAR_TYPE type = CTitleBar::e_DockBar,QString strTitle = "",QWidget* parant = 0);
	~CTabDockWidget();

	/**
	 * @fn       Initialize()
	 * @author   Crack
	 * @brief       
	 * @date     2021/7/27 15:03
	 * @param    
	 * @return   
	*/
	void Initialize();
public:
	/**
	 * @fn       SetProjectName
	 * @author   Crack
	 * @brief    设置工程名称
	 * @date     2021/7/27 14:41
	 * @param    
	 * @return   
	*/
	void SetDockTitle(const QString & strTitle);

	/**
	 * @fn       SetDockWidget
	 * @author   Crack
	 * @brief       
	 * @date     2021/7/27 14:45
	 * @param    
	 * @return   
	*/
	void SetDockWidget(QWidget* pDocWidget);

	/**
	 * @fn       SetTitleBarEnabled
	 * @author   JLC
	 * @brief       
	 * @date     2021/8/4 10:51
	 * @param    
	 * @return   
	*/
	void SetTitleBarEnabled(bool bEnable);
	/**
	 * @fn       SetWidgetEnabled
	 * @author   Crack
	 * @brief       
	 * @date     2021/8/5 13:58
	 * @param    
	 * @return   
	*/

	void SetWidgetEnabled(bool bEnable);

	/**
	 * @fn       AppendAction
	 * @author   Crack
	 * @brief       
	 * @date     2021/8/5 13:55
	 * @param    
	 * @return   
	*/
	QPushButton* AppendAction(QIcon InIcon, QString text);

	void EnabledMove(bool bMove);

protected:
	void mouseMoveEvent(QMouseEvent* event);

	void mousePressEvent(QMouseEvent* event);
private:
	QString m_strTitleName;

	CTitleBar* m_DocTitleBar;

	QWidget* m_EmptyWidget;
};
#endif // TabDockWidget_h__

