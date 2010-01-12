#include "SignDialog.hpp"
#include "ui_signdialog.h"
#include "gamewindow.hpp"

SignDialog::SignDialog(QWidget *parent, TicTacToePlayer::PlayerSign sign): QDialog(parent), ui_(new Ui::SignDialog){
    ui_->setupUi(this);

    connect( this->ui_->buttonBox, SIGNAL(accepted()), this, SLOT(onOk()));

    ui_->circleRadioButton->setChecked(sign == TicTacToePlayer::CIRCLE);
    ui_->crossRadioButton->setChecked(sign == TicTacToePlayer::CROSS);

    GameWindow *win = (GameWindow*)this->parent();
    connect(this,  SIGNAL( okSignal(TicTacToePlayer::PlayerSign) ), 
			win,   SLOT(changeSignSlot(TicTacToePlayer::PlayerSign) ));

}

SignDialog::~SignDialog(){

}

void SignDialog::onOk(){
    TicTacToePlayer::PlayerSign sign = (ui_->circleRadioButton->isChecked() ? TicTacToePlayer::CIRCLE : TicTacToePlayer::CROSS);
    okSignal(sign);
}
