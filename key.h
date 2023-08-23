#ifndef KEY_H
#define KEY_H

#include <QPushButton>

class Key : public QPushButton
{
    Q_OBJECT
public:
    enum KEY_TYPE{
        LETTER_KEY,
        BACK_KEY,
        SHIFT_KEY,
        ENTER_KEY
    };
    explicit Key(enum Key::KEY_TYPE type, QWidget *parent = nullptr);
    Key() = default;
    void setType(enum KEY_TYPE type);
    void shift();

private:
    enum KEY_TYPE type_;
signals:

};

#endif // KEY_H
