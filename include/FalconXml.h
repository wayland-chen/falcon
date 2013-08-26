// =====================================================================================
// 
//       Filename:  FalconXml.h
//
//    Description:  XML 解析
//
//        Version:  1.0
//        Created:  2013年08月23日 21时09分08秒
//       Revision:  none
//       Compiler:  cl
//
//         Author:  Hurley (LiuHuan), liuhuan1992@gmail.com
//        Company:  Class 1107 of Computer Science and Technology
// 
// =====================================================================================

#ifndef FALCONXML_H_
#define FALCONXML_H_

#include "FalconType.h"

class FalconXml
{
public:

	// 构造控制指令XML包
	static QByteArray CreaterControlCommandXml(XmlInfoType strType, QString strIP, QString strCmd = "");

	// 返回一个收到的XML包的类型
	static XmlInfoType getXmlInfoType(QByteArray &strXml);

	// 解析客户端列表XML包
	static void ResolvingClientListInfoXml(QByteArray &strXml, QVector<GroupWithClient> &vectClient);

	// 解析客户端上报处理结果XML包
	static void ResolvingClientDisposeInfoXml(QByteArray &strXml, QString &showInfo);

	// TODO
	// 解析桌面截图XML包
	static void ResolvingDesktopScreenXml(QByteArray &strXml);

	// 解析客户端网络流量信息XML包
	static void ResolvingFluxInfoXml(QByteArray &strXml, ClientFluxInfo &clientFluxInfo);

	// 解析客户端进程信息XML包
	static void ResolvingProcessInfoXml(QByteArray &strXml, QVector<ClientProcessInfo> & vectProcessInfo);

	// 解析客户端cmd处理信息XML包
	static void ResolvingCmdInfoXml(QByteArray &strXml, QString &strCmd);

	// 解析客户端硬件信息XML包
	static void ResolvingHardInfoXml(QByteArray &strXml, QString &strHard);

	// 解析客户端日志信息XML包
	static void ResolvingLogInfoXml(QByteArray &strXml, QString &strLog);

};

#endif	// FALCONXML_H_
