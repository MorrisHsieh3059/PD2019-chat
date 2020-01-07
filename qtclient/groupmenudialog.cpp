#include <QDesktopWidget>

#include "groupmenudialog.h"
#include "ui_groupmenudialog.h"
#include "politics.h"

GroupMenuDialog::GroupMenuDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GroupMenuDialog)
{
    ui->setupUi(this);
}

GroupMenuDialog::~GroupMenuDialog()
{
    delete ui;
}

void GroupMenuDialog::on_pushButton_clicked()
{
    Politics politics;
    politics.setModal(true);

    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    int x = (screenGeometry.width()-politics.width()) / 2;
    int y = (screenGeometry.height()-politics.height()) / 2;
    politics.move(x, y);
    politics.show();

    politics.exec();
}
