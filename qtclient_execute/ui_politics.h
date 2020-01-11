/********************************************************************************
** Form generated from reading UI file 'politics.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POLITICS_H
#define UI_POLITICS_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Politics
{
public:
    QLineEdit *lineEdit;
    QLabel *roomTitle;
    QLabel *userInfo;
    QPushButton *sendBtn;
    QListView *chatRecords;

    void setupUi(QDialog *Politics)
    {
        if (Politics->objectName().isEmpty())
            Politics->setObjectName(QStringLiteral("Politics"));
        Politics->resize(500, 500);
        lineEdit = new QLineEdit(Politics);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(10, 460, 420, 30));
        lineEdit->setLocale(QLocale(QLocale::Chinese, QLocale::Taiwan));
        roomTitle = new QLabel(Politics);
        roomTitle->setObjectName(QStringLiteral("roomTitle"));
        roomTitle->setGeometry(QRect(10, 10, 230, 40));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        roomTitle->setFont(font);
        userInfo = new QLabel(Politics);
        userInfo->setObjectName(QStringLiteral("userInfo"));
        userInfo->setGeometry(QRect(225, 10, 120, 40));
        userInfo->setFont(font);
        userInfo->setScaledContents(false);
        userInfo->setAlignment(Qt::AlignCenter);
        sendBtn = new QPushButton(Politics);
        sendBtn->setObjectName(QStringLiteral("sendBtn"));
        sendBtn->setGeometry(QRect(440, 460, 50, 30));
        chatRecords = new QListView(Politics);
        chatRecords->setObjectName(QStringLiteral("chatRecords"));
        chatRecords->setGeometry(QRect(10, 50, 480, 400));
        chatRecords->setLayoutDirection(Qt::LeftToRight);
        chatRecords->setLocale(QLocale(QLocale::Chinese, QLocale::Taiwan));
        chatRecords->setEditTriggers(QAbstractItemView::NoEditTriggers);
        chatRecords->setMovement(QListView::Static);

        retranslateUi(Politics);

        QMetaObject::connectSlotsByName(Politics);
    } // setupUi

    void retranslateUi(QDialog *Politics)
    {
        Politics->setWindowTitle(QApplication::translate("Politics", "Dialog", Q_NULLPTR));
        roomTitle->setText(QApplication::translate("Politics", "Room1: Politics / ", Q_NULLPTR));
        userInfo->setText(QApplication::translate("Politics", "Users: 0", Q_NULLPTR));
        sendBtn->setText(QApplication::translate("Politics", "Send", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Politics: public Ui_Politics {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POLITICS_H
