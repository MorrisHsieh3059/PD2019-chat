# include "worker.h"

void WorkerThread::setSocket(QTcpSocket* s)
{
    socket = s;
}

void WorkerThread::setStringListModel(QStringListModel* slm)
{
    model = slm;
}

void WorkerThread::setListView(QListView* qsv)
{
    chatRecord = qsv;
}

void WorkerThread::setUserInfo(QLabel* label)
{
    userInfo = label;
}

void WorkerThread::run()
{
    QString result;
    stop = false;
    /* ... here is the expensive or blocking operation ... */
    qDebug() << "in thread";

    QByteArray last = "N/A, server is busy";
    QByteArray recv = "N/A, server is busy";
    while (stop == false)
    {
        QStringList list;

        // get from server
        socket->waitForReadyRead();
        recv = socket->readAll();      // raw input

        qDebug() << "Recv message --> " << recv << "w/ length: " << recv.length();

        if (recv.contains("<userCntIn>")) // when new uer add into the room
        {
            // append new user
            QList<QByteArray> temp = recv.split('>'); // parse to [ _, "userCnt", "newUserName"]
            userInfo->setText("Users: " + temp[1]);

            // notification to all (greeting)
            // QByteArray greet = "                                New User: " + temp[2] + " Enter The Room!";
            QByteArray greet = "                          Let's welcome a new user! He/she is " + temp[2];
            list << ( greet );
            list = model->stringList() + list;
            model->setStringList(list);
            chatRecord->setModel(model);
        }
        else if (recv.contains("<userCntOut>")) // when user quit the room
        {
            // append new user
            QList<QByteArray> temp = recv.split('>'); // parse to [ _, "userCnt", "quitUserName"]
            userInfo->setText("Users: " + temp[1]);

            // notification to all (greeting)
            // QByteArray greet = "                                   User: " + temp[2] + " Quit The Room!";
            QByteArray greet = "                                 Oops! We will miss U " + temp[2];
            list << greet;
            list = model->stringList() + list;
            model->setStringList(list);
            chatRecord->setModel(model);
        }
        else                            // receive other messages
        {
            if (recv.contains("<sendee>"))
            {
                // project to chatRecords
                QList<QByteArray> temp = recv.split('<'); // parse to ["msg", "per>userCnt"]
                list << temp[0];
                if (recv.length() > 0 && last != recv)
                {
                    last = recv;
                    list = model->stringList() + list;

                    model->setStringList(list);
                    chatRecord->setModel(model);
                }
            }
            else             // sender
            {
                // project to chatRecords
                QList<QByteArray> temp = recv.split('<'); // parse to ["msg", "per>userCnt"]
                QList<QByteArray> plainTxt = temp[0].split(':');

                // align to the right (56 digit per line)
                int spaceCnt = (64 - 3 - plainTxt[1].length()) * 2;
                char space[MAXSPACE];
                for (int i = 0; i < spaceCnt; i++)
                    space[i] = ' ';
                space[spaceCnt] = '\0';
                strcat(space, "Me:");

                QByteArray msg;
                msg.append(space, strlen(space));
                msg.append(plainTxt[1]);
                list << msg;
                if (recv.length() > 0 && last != recv)
                {
                    last = recv;
                    list = model->stringList() + list;

                    model->setStringList(list);
                    chatRecord->setModel(model);
                }
            }
        }
    }

    emit resultReady(result);
}
