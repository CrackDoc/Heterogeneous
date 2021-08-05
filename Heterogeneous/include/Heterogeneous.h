#ifndef Heterogeneous_h__
#define Heterogeneous_h__

#include <QtWidgets/QWidget>
#include <QtWidgets/QMainWindow>
#include <QMouseEvent>
namespace Ui {
	class HeterogeneousClass;
}
class CQuiCenterWidget;
class QGridLayout;

class  CHeterogeneous : public QMainWindow
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
	/**
	 * @fn       CheckingEdge
	 * @author   Crack
	 * @brief    检测鼠标是否接近窗口边缘   
	 * @date     2021/8/2 10:14
	 * @param    
	 * @return   
	*/
	void CheckingEdge(); 
	/**
	 * @fn       DragingEdgeResize
	 * @author   Crack
	 * @brief    拖动边缘改变窗口 
	 * @date     2021/8/2 10:10
	 * @param    
	 * @return   
	*/
	void DragingEdgeResize(QMouseEvent * event,ERESIZE_TYPE type);

protected:
	void mousePressEvent(QMouseEvent* event);
	void mouseMoveEvent(QMouseEvent* event);
	void mouseReleaseEvent(QMouseEvent* event);

	void leaveEvent(QEvent* event);
public slots:

	void SlotCloseWindow();

	void SlotShowMaxWindow();

	void SlotShowMinWindow();

private:
    Ui::HeterogeneousClass *ui;
	//鼠标检测的边缘距离
	int  m_nEdgeMargin;     
	bool m_bMousePress;
	ERESIZE_TYPE m_EResizeDir;

	CQuiCenterWidget* m_pCenterWidget;

	QGridLayout* m_pCenterGridLayout;
};
#endif // Heterogeneous_h__
