/********************************************************************************
** Form generated from reading UI file 'groupmenudialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GROUPMENUDIALOG_H
#define UI_GROUPMENUDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_GroupMenuDialog
{
public:
    QPushButton *pushButton;
    QLabel *label;

    void setupUi(QDialog *GroupMenuDialog)
    {
        if (GroupMenuDialog->objectName().isEmpty())
            GroupMenuDialog->setObjectName(QString::fromUtf8("GroupMenuDialog"));
        GroupMenuDialog->resize(500, 500);
        pushButton = new QPushButton(GroupMenuDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(150, 220, 200, 70));
        QFont font;
        font.setPointSize(17);
        pushButton->setFont(font);
        label = new QLabel(GroupMenuDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 80, 400, 121));

        retranslateUi(GroupMenuDialog);

        QMetaObject::connectSlotsByName(GroupMenuDialog);
    } // setupUi

    void retranslateUi(QDialog *GroupMenuDialog)
    {
        GroupMenuDialog->setWindowTitle(QApplication::translate("GroupMenuDialog", "Dialog", nullptr));
        pushButton->setText(QApplication::translate("GroupMenuDialog", "Room1: Politics", nullptr));
        label->setText(QApplication::translate("GroupMenuDialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:20pt; font-weight:600;\">Group Chat Menu<br/>Choose one room!</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GroupMenuDialog: public Ui_GroupMenuDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GROUPMENUDIALOG_H
