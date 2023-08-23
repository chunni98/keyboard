#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <QDialog>
#include <array>
#include "key.h"
class QLineEdit;

class KeyBoard : public QDialog
{
    Q_OBJECT
public:
    explicit KeyBoard(QWidget *parent = nullptr);
    ~KeyBoard() = default;
private:
    static const int key_num = 40;
    QLineEdit *edit_;
    std::array<Key, key_num> keys_;
signals:
    void enter(QString text);
    void shift(void);
};

#endif // KEYBOARD_H
