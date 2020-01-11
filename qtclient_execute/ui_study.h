/********************************************************************************
** Form generated from reading UI file 'study.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDY_H
#define UI_STUDY_H

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

class Ui_study
{
public:
    QLabel *label;
    QLineEdit *lineEdit;
    QListView *listView;
    QPushButton *pushButton;

    void setupUi(QDialog *study)
    {
        if (study->objectName().isEmpty())
            study->setObjectName(QStringLiteral("study"));
        study->resize(500, 517);
        label = new QLabel(study);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 30, 161, 21));
        lineEdit = new QLineEdit(study);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(10, 480, 371, 25));
        listView = new QListView(study);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setGeometry(QRect(10, 70, 471, 401));
        pushButton = new QPushButton(study);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(390, 480, 89, 25));

        retranslateUi(study);

        QMetaObject::connectSlotsByName(study);
    } // setupUi

    void retranslateUi(QDialog *study)
    {
        study->setWindowTitle(QApplication::translate("study", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("study", "Room2 : Study / Users :", Q_NULLPTR));
        pushButton->setText(QApplication::translate("study", "send", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class study: public Ui_study {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDY_H
