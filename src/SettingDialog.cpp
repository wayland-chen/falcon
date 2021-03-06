// =====================================================================================
// 
//       Filename:  SettingDialog.cpp
//
//    Description:  设置对话框
//
//        Version:  1.0
//        Created:  2013年08月31日 22时03分50秒
//       Revision:  none
//       Compiler:  cl
//
//         Author:  Hurley (LiuHuan), liuhuan1992@gmail.com
//        Company:  Class 1107 of Computer Science and Technology
// 
// =====================================================================================

#include <QtGui>

#include "SettingDialog.h"

SettingDialog::SettingDialog()
{
	setupUi(this);

	setFixedSize(this->width(), this->height());

	QRegExp regExp("((2[0-4]\\d|25[0-5]|[01]?\\d\\d?)\\.){3}(2[0-4]\\d|25[0-5]|[01]?\\d\\d?)");
	editServerIP->setValidator(new QRegExpValidator(regExp, this));
	editServerIP->setMaxLength(15);

	spinServerPort->setRange(1, 65535);

	editFetionPass->setEchoMode(QLineEdit::Password);
	editFetionPass->setStyleSheet("lineedit-password-character: 42");

	lineEdit->setFocusPolicy(Qt::StrongFocus);
	lineEdit->installEventFilter(this);

	connect(btnAddBlacklist, SIGNAL(clicked()), this, SLOT(addProcessToList()));
	connect(btnRecovery, SIGNAL(clicked()), this, SLOT(resetListView()));
	connect(btnDelBlackList, SIGNAL(clicked()), this, SLOT(deleteProcess()));
}

SettingDialog::~SettingDialog()
{

}

// 设置对话框选项信息
void SettingDialog::setDialogSetting(SettingInfo &setInfo)
{
	editServerIP->setText(setInfo.strServerIP);
	spinServerPort->setValue(setInfo.serverPort);

	if (setInfo.isReConn) {
		checkBoxReConn->setCheckState(Qt::Checked);
	} else {
		checkBoxReConn->setCheckState(Qt::Unchecked);
	}
	if (setInfo.isShowTrayInfo) {
		checkBoxTray->setCheckState(Qt::Checked);
	} else {
		checkBoxTray->setCheckState(Qt::Unchecked);
	}
	if (setInfo.isPlaySound) {
		checkBoxSound->setCheckState(Qt::Checked);
	} else {
		checkBoxSound->setCheckState(Qt::Unchecked);
	}
	if (setInfo.isSendPhoneMessage) {
		checkBoxSendMsg->setCheckState(Qt::Checked);
	} else {
		checkBoxSendMsg->setCheckState(Qt::Unchecked);
	}

	editFetionNumber->setText(setInfo.strFetionNumber);
	editFetionPass->setText(setInfo.strFetionPass);

	if (setInfo.strLanguage == "cn") {
		languageBox->setCurrentIndex(0);
	} else {
		languageBox->setCurrentIndex(1);
	}

	upSpeedBox->setValue(setInfo.upSpeedLimit);
	downSpeedBox->setValue(setInfo.downSpeedLimit);
	timeBox->setValue(setInfo.allowTimes);
}

// 获取对话框选项信息
void SettingDialog::getDialogSetting(SettingInfo &setInfo)
{
	setInfo.strServerIP = editServerIP->text();
	setInfo.serverPort = spinServerPort->value();

	if (checkBoxReConn->checkState() == Qt::Checked) {
		setInfo.isReConn = true;
	} else {
		setInfo.isReConn = false;
	}
	if (checkBoxTray->checkState() == Qt::Checked) {
		setInfo.isShowTrayInfo = true;
	} else {
		setInfo.isShowTrayInfo = false;
	}
	if (checkBoxSound->checkState() == Qt::Checked) {
		setInfo.isPlaySound = true;
	} else {
		setInfo.isPlaySound = false;
	}
	if (checkBoxSendMsg->checkState() == Qt::Checked) {
		setInfo.isSendPhoneMessage = true;
	} else {
		setInfo.isSendPhoneMessage = false;
	}

	setInfo.strFetionNumber = editFetionNumber->text();
	setInfo.strFetionPass = editFetionPass->text();

	if (languageBox->currentIndex()  == 0) {
		setInfo.strLanguage = "cn";
	} else {
		setInfo.strLanguage = "en";
	}

	setInfo.upSpeedLimit = upSpeedBox->value();
	setInfo.downSpeedLimit = downSpeedBox->value();
	setInfo.allowTimes = timeBox->value();
}

// 设置黑名单列表
void SettingDialog::setBlackList(QVector<QString> &vectBlackList)
{
	listWidget->clear();
	oldBlackList = vectBlackList;
	QListWidgetItem *listItem;
	QVector<QString>::iterator index = vectBlackList.begin();
	for (; index != vectBlackList.end(); ++index) {
		listItem = new QListWidgetItem(*index);
		listWidget->addItem(listItem);
	}
}

// 获取黑名单列表
void SettingDialog::getBlackList(QVector<QString> &vectBlackList)
{
	vectBlackList.clear();
	for (int i = 0; i < listWidget->count(); ++i) {
		vectBlackList.push_back(listWidget->item(i)->text());
	}
}

// 增加一项黑名单信息
void SettingDialog::addProcessToList()
{
	if (lineEdit->text().size() == 0) {
		return;
	}
	listWidget->addItem(new QListWidgetItem(lineEdit->text()));
	lineEdit->clear();
	lineEdit->setFocus();
}

// 取消黑名单修改
void SettingDialog::resetListView()
{
	listWidget->clear();
	setBlackList(oldBlackList);
}

// 删除一行黑名单记录
void SettingDialog::deleteProcess()
{
	QListWidgetItem *listItem = listWidget->takeItem(listWidget->currentRow());
	delete listItem;
}

bool SettingDialog::eventFilter(QObject *target, QEvent *event)
{
	if (target == lineEdit) {
		if (event->type() == QEvent::KeyPress) {
			QKeyEvent *k = static_cast<QKeyEvent *>(event);
			if (k->key() == Qt::Key_Return || k->key() == Qt::Key_Enter) {
				addProcessToList();
				return true;
			}
		}
	}

	return QWidget::eventFilter(target, event);
}