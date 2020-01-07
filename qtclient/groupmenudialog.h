#ifndef GROUPMENUDIALOG_H
#define GROUPMENUDIALOG_H

#include <QDialog>

namespace Ui {
class GroupMenuDialog;
}

class GroupMenuDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GroupMenuDialog(QWidget *parent = nullptr);
    ~GroupMenuDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::GroupMenuDialog *ui;
};

#endif // GROUPMENUDIALOG_H
