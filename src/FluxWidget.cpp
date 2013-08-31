// =====================================================================================
// 
//       Filename:  FluxWidget.cpp
//
//    Description:  流量显示
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

#include "FluxWidget.h"

FluxWidget::FluxWidget()
{
	qDebug() << "FluxWidget 控件初始化\r\n";
	QFont legendFont = QFont("微软雅黑");

	this->setBackground(QBrush(QColor(52, 81, 112)));
	this->plotLayout()->insertRow(0);
	QCPPlotTitle *title= new QCPPlotTitle(this, tr("客户端流量变化图"));
	title->setTextColor(QColor("white"));
	legendFont.setPointSize(18);
	title->setFont(legendFont);
	this->plotLayout()->addElement(0, 0, title);

	this->xAxis->setRange(0, 20);
	this->yAxis->setRange(0, 1000);

	this->xAxis->setTickLabelColor(QColor("white"));
	this->xAxis->setLabelColor(QColor("white"));
	this->xAxis->setLabel("时间 / s");
	this->xAxis->setBasePen(QColor("white"));
	this->xAxis->setTickPen(QColor("white"));
	this->xAxis->setSubTickPen(QColor("white"));

	this->yAxis->setTickLabelColor(QColor("white"));
	this->yAxis->setLabelColor(QColor("white"));
	this->yAxis->setLabel("流量 / KB");
	this->yAxis->setBasePen(QColor("white"));
	this->yAxis->setTickPen(QColor("white"));
	this->yAxis->setSubTickPen(QColor("white"));

	this->legend->setVisible(true);
	legendFont.setPointSize(10);
	this->legend->setFont(legendFont);
	this->legend->setSelectedFont(legendFont);
	this->legend->setSelectableParts(QCPLegend::spItems);

	// graph(0) 下载速率
 	this->addGraph();	
	QCPScatterStyle downScatter;
	downScatter.setShape(QCPScatterStyle::ssCircle);
	downScatter.setPen(QPen(QColor(197, 238, 79)));
	downScatter.setBrush(Qt::white);
	downScatter.setSize(8);
	this->graph(0)->setScatterStyle(downScatter);
	this->graph(0)->setName(QString("上传速率"));
	QPen downPen(QColor(197, 238, 79));
	downPen.setWidth(2);
	this->graph(0)->setPen(downPen);

	// graph(1) 上传速率
	this->addGraph();
	QCPScatterStyle upScatter;
	upScatter.setShape(QCPScatterStyle::ssCircle);
	upScatter.setPen(QPen(QColor(240, 173, 7)));
	upScatter.setBrush(Qt::white);
	upScatter.setSize(8);
	this->graph(1)->setScatterStyle(upScatter);
	this->graph(1)->setName(QString("下载速率"));
	QPen upPen(QColor(240, 173, 7));
	upPen.setWidth(2);
	this->graph(1)->setPen(upPen);

	fluxPonitCount = 20;
	for (int i = 0; i < fluxPonitCount; ++i) {
		upLineXVector.push_back(i);
		downLineXVector.push_back(i);
		upLineYVector.push_back(0);
		downLineYVector.push_back(0);
	}

	this->graph(0)->setData(downLineXVector, downLineYVector);
	this->graph(1)->setData(upLineXVector, upLineYVector);
}

FluxWidget::~FluxWidget()
{

}

/*================================================================
*  函 数 名： FluxWidget::addUpSpeedData
*
*  功能描述： 增加一个上传速率数据
*
*  参    数： double upSpeed —— 上传速率
*			  
*			  
*  返 回 值： 无
*
*  作    者：刘欢 2013/8
================================================================*/
void FluxWidget::addUpSpeedData(double upSpeed)
{
	upLineYVector.remove(0);
	upLineYVector.push_back(upSpeed);
	this->graph(1)->setData(upLineXVector, upLineYVector);
	this->replot();
}

/*================================================================
*  函 数 名： FluxWidget::addDownSpeedData
*
*  功能描述： 增加一个下载速率数据
*
*  参    数： double downSpeed —— 下载速率
*			  
*			  
*  返 回 值： 无
*
*  作    者：刘欢 2013/8
================================================================*/
void FluxWidget::addDownSpeedData(double downSpeed)
{
	downLineYVector.remove(0);
	downLineYVector.push_back(downSpeed);
	this->graph(0)->setData(downLineXVector, downLineYVector);
	this->replot();
}

/*================================================================
*  函 数 名： FluxWidget::fluxDataClear
*
*  功能描述： 清空流量统计显示
*
*  参    数： 无
*			  
*  返 回 值： 无
*
*  作    者：刘欢 2013/8
================================================================*/
void FluxWidget::fluxDataClear()
{
	this->graph(0)->clearData();
	this->graph(1)->clearData();
	for (int i = 0; i < fluxPonitCount; ++i) {
		upLineYVector[i] = 0;
		downLineYVector[i] = 0;
	}
	this->replot();	
}
