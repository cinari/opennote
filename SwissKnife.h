#ifndef SWISSKNIFE_H_
#define SWISSKNIFE_H_

#include<iostream>
#include<QString>
#include<QTextCodec>
#include<QTextStream>
#include<QByteArray>
#include<QFile>
#include <QDir>

class SwissKnife {
public:
	SwissKnife();
	virtual ~SwissKnife();

	static QString fromHangul(const char* localStr);
	static QString toUnicode(QString str);
	static void printString(QString str);
	static QByteArray fileRead(QString filePath);
	static bool fileSave(QString filePath, QString textToSave);

	static void renameFile(QString& baseDirectory,QString& srcFileName,QString& dstFileName);
	//static QString fileRead(QString filePath);

	//static void showErrorMessage(Qstring errorMessage);
	// debug function!!!!!!!!!!!!!
};

#endif /* SWISSKNIFE_H_ */

