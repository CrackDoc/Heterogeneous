﻿#ifndef TabDockWidget_h__
#define TabDockWidget_h__
#include <QtWidgets/QWidget>
#include <QtWidgets/QDockWidget>
#include <QMouseEvent>

class CTitleBar;
class CTabDockWidget :public QDockWidget
{
	Q_OBJECT
public:
	CTabDockWidget(QWidget* parant = 0, QString strTitle = "");
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

protected:
	void mouseMoveEvent(QMouseEvent* event);

	void mousePressEvent(QMouseEvent* event);
private:
	QString m_strTitleName;

	CTitleBar* m_DocTitleBar;
};
#endif // TabDockWidget_h__

