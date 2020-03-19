//
// Created by james on 2019-04-28.
//

#include <QApplication>
#include <QDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QDialog *dlg = new QDialog();
    dlg->setWindowTitle("Hello World");
    dlg->show();
    return a.exec();
}