/********************************************************************************
** Form generated from reading UI file 'travel.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRAVEL_H
#define UI_TRAVEL_H

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

class Ui_travel
{
public:
    QPushButton *pushButton;
    QListView *listView;
    QLineEdit *lineEdit;
    QLabel *label;

    void setupUi(QDialog *travel)
    {
        if (travel->objectName().isEmpty())
            travel->setObjectName(QStringLiteral("travel"));
        travel->resize(500, 500);
        pushButton = new QPushButton(travel);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(390, 460, 89, 25));
        listView = new QListView(travel);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setGeometry(QRect(10, 50, 471, 401));
        lineEdit = new QLineEdit(travel);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(10, 460, 361, 25));
        label = new QLabel(travel);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 16, 311, 31));

        retranslateUi(travel);

        QMetaObject::connectSlotsByName(travel);
    } // setupUi

    void retranslateUi(QDialog *travel)
    {
        travel->setWindowTitle(QApplication::translate("travel", "Dialog", Q_NULLPTR));
        pushButton->setText(QApplication::translate("travel", "send", Q_NULLPTR));
        label->setText(QApplication::translate("travel", "Room3 : Travel/ Users:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class travel: public Ui_travel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRAVEL_H
