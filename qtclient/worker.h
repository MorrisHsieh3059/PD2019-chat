# ifndef WORKER_H
# define WORKER_H
# include <QThread>
# include <QObject>
# include <QDebug>
# include <QTcpSocket>
# include <QListView>
# include <QStringListModel>
# include <QList>
# include <QLabel>
# include <QModelIndex>
# include <QAbstractItemModel>
# include <cstring>

const int MAXSPACE = 150;

class WorkerThread : public QThread
{
    Q_OBJECT
    void run() override;

public:
    QTcpSocket* socket;
    QStringListModel* model;
    QListView* chatRecord;
    QLabel* userInfo;
    bool stop;
    void setSocket(QTcpSocket* s);
    void setStringListModel(QStringListModel* slm);
    void setListView(QListView* qsv);
    void setUserInfo(QLabel* label);

signals:
    void resultReady(const QString &s);
};

# endif


