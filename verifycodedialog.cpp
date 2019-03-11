#include "verifycodedialog.h"
#include "ui_verifycodedialog.h"
#include <QTimer>
#include <QMouseEvent>
#include <QEvent>

VerifyCodeDialog::VerifyCodeDialog(int *ret, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VerifyCodeDialog)
{
    ui->setupUi(this);
    ui->fixLineEdit->setFocusPolicy(Qt::NoFocus);
    ui->inputLineEdit->installEventFilter(this);
    getFixCode();
    setInputEditStyle(NORMAL);
    ui->inputLineEdit->setStyleSheet("QLineEdit{width: 322; height:23;border-radius: 3px;border:1px solid #ada9a5;}"
          "QLineEdit:hover{width: 322; height:23;border-radius: 3px;border:1px solid #ada9a5;}");
}

VerifyCodeDialog::~VerifyCodeDialog()
{
    delete ui;
}

void VerifyCodeDialog::on_cancelButton_clicked()
{
    close();
}

void VerifyCodeDialog::on_sureButton_clicked()
{
    QString fixcode =ui->fixLineEdit->text();

    QString inputcode = ui->inputLineEdit->text();
    if (inputcode.isEmpty())
    {
        ui->warningLabel->setText(QString::fromUtf8("请输入激活码！"));
        setInputEditStyle(HOVER);
        return;
    }

    ui->inputLineEdit->clearFocus();
    int ret/* = cmp(fixcode ,inputcode)*/;

    if (ret == 0)
    {
        //验证通过
        *retvalue = 0;
        close();
    }
    else
    {
        //激活码错误
        ui->warningLabel->setText(QString::fromUtf8("激活码错误！"));
        setInputEditStyle(HOVER);
//        ui->cancelButton->setEnabled(false);
//        ui->sureButton->setEnabled(false);
//        QTimer::singleShot(1500, this,SLOT(singleShotSlot()));
    }

}

void VerifyCodeDialog::singleShotSlot()
{
    ui->warningLabel->setText(QString::fromUtf8(""));
    ui->cancelButton->setEnabled(true);
    ui->sureButton->setEnabled(true);
}

void VerifyCodeDialog::getFixCode()
{
    QString fixCode = "abcd"    /*getFixCodeFunc()*/;
    ui->fixLineEdit->setText(fixCode);
}

void VerifyCodeDialog::setInputEditStyle(STYLETYPE type)
{
    if (type == NORMAL)
    {
        ui->inputLineEdit->setStyleSheet("QLineEdit{width: 322; height:23;border-radius: 3px;border:1px solid #ada9a5;}"
              "QLineEdit:hover{width: 322; height:23;border-radius: 3px;border:1px solid #ada9a5;}");
    }
    else
    {
        ui->inputLineEdit->setStyleSheet("QLineEdit{width: 322; height:23;border-radius: 3px;border:1px solid red;}"
              "QLineEdit:hover{ width: 322; height:23;border-radius: 3px; border:1px solid red;}");
    }
}

bool VerifyCodeDialog::eventFilter(QObject *obj, QEvent *e)
{
    if(obj == ui->inputLineEdit)
    {
        if(e->type() == QEvent::MouseButtonPress)
        {
//            QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(e);
//            if(mouseEvent->buttons() & Qt::LeftButton)
//            {
                ui->warningLabel->setText(QString::fromUtf8(""));
                setInputEditStyle(NORMAL);
//            }
            return true;
        }
    }

    return QWidget::eventFilter(obj, e);
}
