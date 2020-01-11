#include <QDebug>
#include <QStringListModel>
#include <QWidget>
#include <QMessageBox>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;

#include "politics.h"
#include "ui_politics.h"
#include "worker.h"

Politics::Politics(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Politics)
{

    model = new QStringListModel(this);
    ui->setupUi(this);
    ui->chatRecords->setEditTriggers(0);                 // set chatRecords to be uneditable
    socket = new QTcpSocket(this);
    // socket->connectToHost("127.0.0.1", 8700); // local
    // socket->connectToHost("192.168.139.131", 2400); // morris' local
    // socket->connectToHost("192.168.22.128", 2400); // wayne' local
    socket->connectToHost("140.112.30.40", 2400); // csies' local

    qDebug() << "socket test: " << socket->error();
    if (socket == nullptr)
        qDebug() << "Fail to connect\n";
    else
        qDebug() << "Linked";

    startWorkInAThread();

    qDebug() << name;
}

void Politics::disJoinServer()
{
    // erase user from server
    qDebug() << "I am quiting~ with status " << socket->write("exit");
    workerThread->stop = true; // stop thread
    workerThread->terminate();
    socket->disconnect();
    socket->disconnectFromHost();
    socket->deleteLater();
    socket->close();
    // Don't need to delete it manually
    // because parent will delete it automatically
    socket = nullptr;
}

Politics::~Politics()
{
    disJoinServer();
    QMessageBox::information(this, "Quit", "Quit Room 1: Politics");
    qDebug() << "Shut up";
    delete ui;
}

void Politics::handleResults()
{
    qDebug() << "-------------------End Thread.";
}

void Politics::startWorkInAThread()
{
    workerThread = new WorkerThread();
    workerThread->setSocket(socket);
    workerThread->setStringListModel(model);
    workerThread->setListView(ui->chatRecords);
    workerThread->setUserInfo(ui->userInfo);
    connect(workerThread, &WorkerThread::resultReady, this, &Politics::handleResults);
    connect(workerThread, &WorkerThread::finished, workerThread, &QObject::deleteLater);
    workerThread->start();
}

void Politics::on_sendBtn_clicked()
{
    // get text from user input
    QStringList list;
    QString text = ui->lineEdit->text();

    // project to chatRecords
    list << text;
    if (text.length() > 0)
    {
        ui->lineEdit->clear();
    }

    // write to server
    string text_str = text.toStdString();
    qDebug() << "sending bytes " << socket->write(text_str.c_str());
}
