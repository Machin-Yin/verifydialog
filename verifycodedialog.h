#ifndef VERIFYCODEDIALOG_H
#define VERIFYCODEDIALOG_H

#include <QDialog>

namespace Ui {
class VerifyCodeDialog;
}

class VerifyCodeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit VerifyCodeDialog(int *ret, QWidget *parent = 0);
    ~VerifyCodeDialog();

    enum STYLETYPE{
        NORMAL,
        HOVER
    };

private slots:
    void on_cancelButton_clicked();
    void on_sureButton_clicked();
    void singleShotSlot();

private:
    void getFixCode();
    void setInputEditStyle(STYLETYPE type);
    bool eventFilter(QObject *obj, QEvent *e);

private:
    Ui::VerifyCodeDialog *ui;
    int *retvalue;

};

#endif // VERIFYCODEDIALOG_H
