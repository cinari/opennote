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

// --> svn co file:///c:/teamnote_svn/teamnote/trunk teamnote
// --> svn ci

// 노트북 추가, 폴더 추가 (by 사용자) ====> 바로 추가 (안되면 pending command list 에 넣어두기)
// Status 창 ===> 가장 최신상태의 파일인지 아닌지 표시되어야 한다.
// 쓰레드(처음시작, +3분, ..) ===> svn update 해서 미반영된 파일들 얻어서 리스트에 추가하고
//                         ===> svn st -q 해서 최신 상태의 파일과 diff 한값 보여주기
//						   ===> pending command list 에 있던 명령 날리자!
//                         !!!! 쓰레드로 업데이트 하는 와중에는 Mutex 등으로 보호하기

#endif /* SYNC_H_ */
