#ifndef SYNC_H_
#define SYNC_H_

#include <QMainWindow>
#include <QMap>
#include <QListWidget>
#include <QTreeWidget>
#include <QPointer>
#include <QTreeView>
#include <QDirModel>
#include <QProcess>

/*
 * TODO: switch from SVN to GIT *
 */

const QString repository_url = "file:///c:/teamnote_svn/teamnote/trunk";

class SubversionController {
public:
	SubversionController(QString workingDir);
	virtual ~SubversionController();

	QByteArray doUpdate();
	void doAdd(QString fileName);
	void doCommit(QString fileName);
	void doMove(QString srcFileName, QString dstFileName);
	QString getDateInfo(QString fileName);

	QString shm;
private:
	QString workingDirectory;
	QProcess *svnProcess;
};

#endif /* SYNC_H_ */
