//#include "widget.h"
#include "keyboard.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Widget w;
    //w.show();
    KeyBoard k;
    k.show();
    return a.exec();
}
