#include "optionsdialog.hpp"
#include "ui_optionsdialog.h"
#include "gamewindow.hpp"

OptionsDialog::OptionsDialog(QWidget *parent) :
    QDialog(parent),
    m_ui_(new Ui::OptionsDialog){
    m_ui_->setupUi(this);

    connect( this->m_ui_->buttonBox, SIGNAL(accepted()), this, SLOT(onOk()));

    GameWindow *win = (GameWindow*)this->parent();
    connect(this, SIGNAL(Ok()), win, SLOT(okClicked()));
}

OptionsDialog::~OptionsDialog(){
    delete m_ui_;
}

void OptionsDialog::on_loadOponentButton_clicked(){

}

void OptionsDialog::onOk(){
    Ok();
}
