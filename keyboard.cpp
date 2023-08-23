#include "keyboard.h"
#include <QLineEdit>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QDebug>

KeyBoard::KeyBoard(QWidget *parent): QDialog(parent)
{
    edit_ = new QLineEdit;

    auto glayout = new QGridLayout;

    for (int i = 0; i < keys_.size() - 4; i++) {
        keys_[i].setType(Key::KEY_TYPE::LETTER_KEY);
        if (i >= 10) {
            keys_[i].setText(QString{i - 10 + 'a'});
            connect(this, &KeyBoard::shift, &keys_[i], [=](){
                keys_[i].shift();
            });
        }else {
            keys_[i].setText(QString::number(i));
        }
        glayout->addWidget(&keys_[i], i / 6, i % 6);
        connect(&keys_[i], &QPushButton::clicked, this, [=](){
            edit_->setText(edit_->text() + keys_[i].text());
        });
    }
    keys_[36].setType(Key::KEY_TYPE::LETTER_KEY);
    keys_[36].setText("_");
    connect(&keys_[36], &QPushButton::clicked, this, [=](){
        edit_->setText(edit_->text() + keys_[36].text());
    });

    keys_[37].setType(Key::KEY_TYPE::SHIFT_KEY);
    keys_[37].setText("Shift");
    connect(&keys_[37], &QPushButton::clicked, this, [=](){
        emit shift();
    });

    keys_[38].setType(Key::KEY_TYPE::ENTER_KEY);
    keys_[38].setText("Enter");
    connect(&keys_[38], &QPushButton::clicked, this, [=](){
        emit enter(edit_->text());
        this->close();
    });

    keys_[39].setType(Key::KEY_TYPE::BACK_KEY);
    keys_[39].setText("Back");
    connect(&keys_[39], &QPushButton::clicked, this, [=](){
        edit_->setText(edit_->text().left(edit_->text().size() - 1));
    });

    glayout->addWidget(&keys_[36], 6, 1);
    glayout->addWidget(&keys_[37], 6, 2);
    glayout->addWidget(&keys_[38], 6, 3);
    glayout->addWidget(&keys_[39], 6, 4);

    auto vlayout = new QVBoxLayout;
    vlayout ->addWidget(edit_);
    vlayout->addLayout(glayout);

    setLayout(vlayout);
    setFixedSize(sizeHint());
}
