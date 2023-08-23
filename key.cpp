#include "key.h"
#include <QChar>

Key::Key(enum Key::KEY_TYPE type, QWidget *parent)
    : QPushButton{parent}
{
    type_ = type;
}

void Key::setType(KEY_TYPE type)
{
    type_ = type;
}

void Key::shift()
{
    if (type_ == KEY_TYPE::LETTER_KEY) {
        auto t = this->text().at(0).toLatin1();
        if (t > 96)
        this->setText(QString(t - ' '));
        else
        this->setText(QString(t + ' '));
    }
}
