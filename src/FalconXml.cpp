// =====================================================================================
// 
//       Filename:  FalconXml.cpp
//
//    Description:  XML 解析
//
//        Version:  1.0
//        Created:  2013年08月23日 21时08分08秒
//       Revision:  none
//       Compiler:  cl
//
//         Author:  Hurley (LiuHuan), liuhuan1992@gmail.com
//        Company:  Class 1107 of Computer Science and Technology
// 
// =====================================================================================

#include <QtGui>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>

#include "FalconXml.h"
#include "FalconType.h"

// 构造控制指令XML包
QByteArray FalconXml::CreaterControlCommandXml(XmlInfoType strType, QString strCmd)
{
	QByteArray strXml;
	QXmlStreamWriter stream(&strXml);

	stream.setAutoFormatting(true);

	stream.writeStartDocument();
	stream.writeStartElement("falcon");
	stream.writeAttribute("type", QString::number(strType));

	stream.writeTextElement("info", strCmd);

	stream.writeEndElement();
	stream.writeEndDocument();

	return strXml;
}

XmlInfoType FalconXml::getXmlInfoType(QByteArray &strXml)
{
	QXmlStreamReader reader(strXml);

	 while (!reader.atEnd()) {
		QXmlStreamReader::TokenType type = reader.readNext();

		if (type == QXmlStreamReader::StartElement) {
			if (reader.name() == "falcon" && reader.attributes().hasAttribute("type")) {
				return (XmlInfoType)(reader.attributes().value("type").toString().toInt());
			}
		}
	}

	if (reader.hasError()) {
		qDebug() << "XML Error:" << reader.errorString() << "\r\n";
	}

	return NoType;
}

/*
<!-- 服务端发送的客户端列表信息XML包 -->
<?xml version="1.0" encoding="UTF-8"?>
<falcon type="具体包的类型">
	<group name="组名1">
		<ip>客户机IP地址 1 </ip>
		<ip>客户机IP地址 2 </ip>
		<ip>客户机IP地址 3 </ip>
		<ip>客户机IP地址 n </ip>
	</group>
	<group name="组名2">
		<ip>客户机IP地址 1 </ip>
		<ip>客户机IP地址 2 </ip>
		<ip>客户机IP地址 3 </ip>
		<ip>客户机IP地址 n </ip>
	</group>
</falcon>
*/
// 解析客户端列表XML包
void FalconXml::ResolvingClientListInfoXml(QByteArray&strXml, QVector<GroupWithClient> &vectClient)
{

}

/*
<?xml version="1.0" encoding="UTF-8"?>
<falcon type="具体包的类型">
	<info>附加信息</info>
</falcon>
*/
// 解析客户端上报处理结果XML包
void FalconXml::ResolvingClientDisposeInfoXml(QByteArray &strXml)
{
	
}

/*

*/
// 解析桌面截图XML包
void FalconXml::ResolvingDesktopScreenXml(QByteArray &strXml)
{
	
}

/*
<?xml version="1.0" encoding="UTF-8"?>
<falcon type="具体包的类型">
	<date>上报日期</date>
	<time>上报时间</time>
    <upload>上传速度</upload>
    <download>下载速度</download>
</falcon>
*/
// 解析客户端网络流量信息XML包
void FalconXml::ResolvingFluxInfoXml(QByteArray &strXml)
{
	
}

/*
<!-- 监控端接收的进程信息XML包 -->
<?xml version="1.0" encoding="UTF-8"?>
<falcon type="具体包的类型">
	<process name="进程名 1 ">
		<pid>进程PID</pid>
		<mem>使用内存</mem>
		<path>映像路径</path>
		<description>/进程描述</description>
	</process>
	<process name="进程名 2 ">
		<pid>进程PID</pid>
		<mem>使用内存</mem>
		<path>映像路径</path>
		<description>/进程描述</description>
	</process>
	<process name="进程名 n ">
		<pid>进程PID</pid>
		<mem>使用内存</mem>
		<path>映像路径</path>
		<description>/进程描述</description>
	</process>
</falcon>
*/
// 解析客户端进程信息XML包
void FalconXml::ResolvingProcessInfoXml(QByteArray &strXml)
{
	
}

/*
<?xml version="1.0" encoding="UTF-8"?>
<falcon type="具体包的类型">
	<os>操作系统</os>
	<hostname>计算机名</hostname>
	<cpu>CPU信息</cpu>
	<mem>内存信息</mem>
	<net>网卡信息</net>
	<harddisk>硬盘信息</harddisk>
	<starttime>开机时间<starttime>
</falcon>
*/
// 解析客户端硬件信息XML包
void FalconXml::ResolvinghardInfoXml(QByteArray &strXml)
{
	
}

/*
<?xml version="1.0" encoding="UTF-8"?>
<falcon type="具体包的类型">
	<info>附加信息</info>
</falcon>
*/
// 解析客户端日志信息XML包
void FalconXml::ResolvingLogInfoXml(QByteArray &strXml)
{
	
}