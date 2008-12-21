#include "SwissKnife.h"
using namespace std;

SwissKnife::SwissKnife() {

}

SwissKnife::~SwissKnife() {

}

QString SwissKnife::fromHangul(const char* localStr)
{
	return QString::fromLocal8Bit(localStr);
}

void SwissKnife::printString(QString str)
{
	cout << "" << str.toAscii().data() << endl;
}

QString SwissKnife::toUnicode(QString str)
{
	QTextCodec * codec = QTextCodec::codecForName("EUC-KR");
	return codec->toUnicode(str.toUtf8());
}

QByteArray SwissKnife::fileRead(QString filePath)
{
	if(!QFile::exists(filePath)) // not exists
	{
		SwissKnife::printString(filePath + ": not exists");
		QByteArray nullData;
		return nullData;
	}

	QFile file(filePath);
	if (!file.open(QFile::ReadOnly))
		return false;

	QByteArray fileData = file.readAll();
	file.close();

	return fileData;
}

bool SwissKnife::fileSave(QString filePath, QString textToSave)
{
	QFile file(filePath);
	if (!file.open(QFile::WriteOnly))
	        return false;

	QTextStream ts(&file);
	ts.setCodec(QTextCodec::codecForName("UTF-8"));
	ts << textToSave;
	ts.flush();

	return true;
}

void SwissKnife::renameFile(QString& baseDirectory,QString& srcFileName,QString& dstFileName)
{
	 QDir dir(baseDirectory);
	 dir.rename(srcFileName,dstFileName);
}

/*
static void SwissKnife::showErrorMessage(Qstring errorMessage)
{
	QErrorMessage* errMsgDialog = new QErrorMessage(this);
	errMsgDialog->showMessage(tr("templates not exists!"));
	return;
}
*/
