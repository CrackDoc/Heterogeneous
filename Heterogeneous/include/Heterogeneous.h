#ifndef Heterogeneous_h__
#define Heterogeneous_h__

#include "QuiBaseDialog.h"

class QMainWindow;
class CQuiSystray;
class CQuiBaseWndBar;

class  CHeterogeneous : public CQuiBaseDialog
{
    Q_OBJECT
	
public:
    CHeterogeneous(QWidget *parent = Q_NULLPTR);
	~CHeterogeneous();
	
private:

	/**
	 * @fn       Initialize
	 * @author   Crack
	 * @brief    Initialize 
	 * @date     2021/8/2 13:47
	 * @param    
	 * @return   
	*/
	void Initialize();

	/**
 	* @fn       InitializeFrameWorksUi
 	* @author   Crack
 	* @brief       
 	* @date     2021/8/3 9:11
 	* @param    
 	* @return   
	*/
	void InitializeFrameWorksUi();
	/**
	 * @fn       InitializeDockWidgt
	 * @author   Crack
	 * @brief    初始化DockWidget 
	 * @date     2021/8/2 11:33
	 * @param    
	 * @return   
	*/
	void InitializeDockWidgt();
	/**
 	* @fn       InitializeModules
 	* @author   Crack
 	* @brief    初始化模块  
 	* @date     2021/8/3 9:07
 	* @param    
 	* @return   
	*/
	void InitializeModules();

public slots:

	void SlotCloseWindow();

	void SlotShowMaxWindow();

	void SlotShowMinWindow();

private:

	CQuiBaseWndBar* m_pWidgetBar;

	QMainWindow* m_pMainWindow;

	CQuiSystray* m_pQuiSystray;
signals:
	void SignalQuit();
};
#endif // Heterogeneous_h__
