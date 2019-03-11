#include "verifycodedialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    int res = -1;
    VerifyCodeDialog w(&res, 0);
    w.show();

    return a.exec();
}
