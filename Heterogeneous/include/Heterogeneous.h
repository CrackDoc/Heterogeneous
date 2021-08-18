#ifndef Heterogeneous_h__
#define Heterogeneous_h__

#include "QuiBaseWidget.h"

class QMainWindow;
class CQuiSystray;
class  CHeterogeneous : public CQuiBaseWidget
{
    Q_OBJECT

public:
	enum ERESIZE_TYPE{
		nodir,
		top = 0x01,
		bottom = 0x02,
		left = 0x04,
		right = 0x08,
		topLeft = 0x01 | 0x04,
		topRight = 0x01 | 0x08,
		bottomLeft = 0x02 | 0x04,
		bottomRight = 0x02 | 0x08
	}; //更改尺寸的方向
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

	QMainWindow* m_pMainWindow;

	CQuiSystray* m_pQuiSystray;
};
#endif // Heterogeneous_h__
