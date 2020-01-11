#ifndef POLITICS_H
#define POLITICS_H

# include <QDialog>
# include <QStringListModel>
# include <QTcpSocket>
# include "worker.h"

namespace Ui {
class Politics;
}

class Politics : public QDialog
{
    Q_OBJECT

public:
    explicit Politics(QWidget *parent = nullptr);
    ~Politics();

private slots:
    void on_sendBtn_clicked();

private:
    QStringListModel* model = new QStringListModel(this);
    Ui::Politics *ui;
    QTcpSocket* socket;
    WorkerThread* workerThread;
    QString name;
    void disJoinServer();
    void startWorkInAThread();
    void handleResults();
};

#endif // POLITICS_H
