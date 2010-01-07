/**
  @file optionsdialog.cpp
  @author Hanna Dutkiewicz
*/

#include "optionsdialog.hpp"
#include "ui_optionsdialog.h"
#include "gamewindow.hpp"


/* Constructor of a dialog window. Its parent should be MainWindow. */
OptionsDialog::OptionsDialog(QWidget *parent) : QDialog(parent), m_ui_(new Ui::OptionsDialog){
    m_ui_->setupUi(this);

    connect( this->m_ui_->buttonBox, SIGNAL(accepted()), this, SLOT(onOk()));

    GameWindow *win = (GameWindow*)this->parent();
    connect(this, SIGNAL(Ok()), win, SLOT(okClicked()));
}

/* A destuctor. */
OptionsDialog::~OptionsDialog(){
}

/* Handles situation when load button was clicked to load a specific oponent from a file. */
void OptionsDialog::on_loadOponentButton_clicked(){

}

/* Handles situation when ok button was clicked. */
void OptionsDialog::onOk(){
    Ok();
}
