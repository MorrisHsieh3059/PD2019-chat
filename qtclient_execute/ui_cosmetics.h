/********************************************************************************
** Form generated from reading UI file 'cosmetics.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COSMETICS_H
#define UI_COSMETICS_H

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

class Ui_cosmetics
{
public:
    QListView *listView;
    QPushButton *pushButton;
    QLabel *label;
    QLineEdit *lineEdit;

    void setupUi(QDialog *cosmetics)
    {
        if (cosmetics->objectName().isEmpty())
            cosmetics->setObjectName(QStringLiteral("cosmetics"));
        cosmetics->resize(500, 574);
        listView = new QListView(cosmetics);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setGeometry(QRect(10, 80, 451, 441));
        pushButton = new QPushButton(cosmetics);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(380, 540, 89, 25));
        label = new QLabel(cosmetics);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 40, 281, 21));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        lineEdit = new QLineEdit(cosmetics);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(10, 540, 351, 25));

        retranslateUi(cosmetics);

        QMetaObject::connectSlotsByName(cosmetics);
    } // setupUi

    void retranslateUi(QDialog *cosmetics)
    {
        cosmetics->setWindowTitle(QApplication::translate("cosmetics", "Dialog", Q_NULLPTR));
        pushButton->setText(QApplication::translate("cosmetics", "Send", Q_NULLPTR));
        label->setText(QApplication::translate("cosmetics", "Room 1: Cosmetics / Users:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class cosmetics: public Ui_cosmetics {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COSMETICS_H
