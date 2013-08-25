// =====================================================================================
// 
//       Filename:  MainListWidget.cpp
//
//    Description:  自动上线主机列表显示
//
//        Version:  1.0
//        Created:  2013年08月20日 11时08分08秒
//       Revision:  none
//       Compiler:  cl
//
//         Author:  Hurley (LiuHuan), liuhuan1992@gmail.com
//        Company:  Class 1107 of Computer Science and Technology
// 
// =====================================================================================

#include <QtGui>

#include "MainListWidget.h"

MainListWidget::MainListWidget()
{
	qDebug() << "MainListWidget 控件初始化\r\n";
	setViewMode(QListView::IconMode);
	setResizeMode(Adjust);
	setMovement(Static);
	setIconSize(QSize(60, 60));
	setGridSize(QSize(100, 100));

	addComputerItem(QString(tr("192.168.1.2")), true);
	addComputerItem(QString(tr("192.168.1.3")), true);
	addComputerItem(QString(tr("192.168.1.4")), false);
	addComputerItem(QString(tr("192.168.1.5")), true);
	addComputerItem(QString(tr("192.168.1.6")), false);
}

MainListWidget::~MainListWidget()
{

}

/*================================================================
*  函 数 名： MainListWidget::addComputerItem
*
*  功能描述： 增加一个在线主机信息到列表显示控件
*
*  参    数： QString &strTitle —— 显示的标题
* 			  bool isOnline —— 是否已连接服务端
*			  			  
*  返 回 值：
*
*  作    者：刘欢 2013/8
================================================================*/
void MainListWidget::addComputerItem(QString strTitle, bool isOnline)
{
	QListWidgetItem *item = new QListWidgetItem(this);
	item->setText(strTitle);
	if (isOnline) {
		item->setIcon(QIcon(":/res/images/computer_online.png"));
	} else {
		item->setIcon(QIcon(":/res/images/computer_offline.png"));
	}
}