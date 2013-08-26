// =====================================================================================
// 
//       Filename:  FluxViewWidget.cpp
//
//    Description:  流量列表显示
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

#include "FluxViewWidget.h"
#include "FluxWidget.h"

FluxViewWidget::FluxViewWidget()
{
	qDebug() << "FluxViewWidget 控件初始化\r\n";
	setStyleSheet("QGroupBox {border-width:1px; border-style:solid; border-color:gray;}");
	
	fluxView = new FluxWidget();

	upLabel = new QLabel(tr("上传速度：0 KB/s"));
	downLabel = new QLabel(tr("下载速度: 0 KB/s"));
	hBoxLayout = new QHBoxLayout();

	hBoxLayout->addStretch();
	hBoxLayout->addWidget(downLabel);
	hBoxLayout->addStretch();
	hBoxLayout->addWidget(upLabel);
	hBoxLayout->addStretch();

	vBoxLayout = new QVBoxLayout();
	vBoxLayout->addWidget(fluxView);
	vBoxLayout->addLayout(hBoxLayout);
	vBoxLayout->setStretchFactor(fluxView, 1); 

	setLayout(vBoxLayout);
}

FluxViewWidget::~FluxViewWidget()
{

}

/*================================================================
*  函 数 名： FluxViewWidget::updateFluxData
*
*  功能描述： 更新一次流量显示数据
*
*  参    数： 暂无，以后会有
*			  
*			  
*  返 回 值： 无
*
*  作    者：刘欢 2013/8
================================================================*/
void FluxViewWidget::updateFluxData(double upSpeed, double downSpeed)
{
	fluxView->addUpSpeedData(upSpeed);
	fluxView->addDownSpeedData(downSpeed);

	QString strUpLabel = QString((tr("上传速度：%1 KB/s"))).arg(upSpeed);
	QString strDownLabel = QString((tr("下载速度: %1 KB/s"))).arg(downSpeed);

	upLabel->setText(strUpLabel);
	downLabel->setText(strDownLabel);
}

/*================================================================
*  函 数 名： FluxViewWidget::resetFluxView
*
*  功能描述： 重置流量控件显示
*
*  参    数： 无
*			  
*			  
*  返 回 值： 无
*
*  作    者：刘欢 2013/8
================================================================*/
void FluxViewWidget::resetFluxView()
{
	fluxView->fluxDataClear();
}
