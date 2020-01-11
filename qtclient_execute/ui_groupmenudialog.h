/********************************************************************************
** Form generated from reading UI file 'groupmenudialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GROUPMENUDIALOG_H
#define UI_GROUPMENUDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_GroupMenuDialog
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;

    void setupUi(QDialog *GroupMenuDialog)
    {
        if (GroupMenuDialog->objectName().isEmpty())
            GroupMenuDialog->setObjectName(QStringLiteral("GroupMenuDialog"));
        GroupMenuDialog->resize(594, 494);
        pushButton = new QPushButton(GroupMenuDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(230, 240, 431, 251));
        QFont font;
        font.setPointSize(17);
        pushButton->setFont(font);
        pushButton->setStyleSheet(QString::fromUtf8("background-image: url(:/\346\210\252\345\234\226 2020-01-08 \344\270\213\345\215\2103.33.00.png);"));
        pushButton_2 = new QPushButton(GroupMenuDialog);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(240, -20, 361, 261));
        pushButton_2->setFont(font);
        pushButton_2->setStyleSheet(QString::fromUtf8("background-image: url(:/\346\210\252\345\234\226 2020-01-08 \344\270\213\345\215\2103.28.25.png);"));
        pushButton_3 = new QPushButton(GroupMenuDialog);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(-50, -10, 351, 261));
        pushButton_3->setFont(font);
        pushButton_3->setStyleSheet(QString::fromUtf8("background-image: url(:/\346\210\252\345\234\226 2020-01-08 \344\270\213\345\215\2103.18.30.png);"));
        pushButton_4 = new QPushButton(GroupMenuDialog);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(-140, 240, 441, 301));
        pushButton_4->setFont(font);
        pushButton_4->setStyleSheet(QString::fromUtf8("background-image: url(:/\346\210\252\345\234\226 2020-01-08 \344\270\213\345\215\2103.41.57.png);"));

        retranslateUi(GroupMenuDialog);

        QMetaObject::connectSlotsByName(GroupMenuDialog);
    } // setupUi

    void retranslateUi(QDialog *GroupMenuDialog)
    {
        GroupMenuDialog->setWindowTitle(QApplication::translate("GroupMenuDialog", "Dialog", Q_NULLPTR));
        pushButton->setText(QString());
        pushButton_2->setText(QString());
        pushButton_3->setText(QString());
        pushButton_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class GroupMenuDialog: public Ui_GroupMenuDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GROUPMENUDIALOG_H
