/**
  @file optionsdialog.cpp
  @author Hanna Dutkiewicz
*/

#include <QFileDialog>
#include <QRadioButton>
#include <QLabel>
#include <QMessageBox>

#include "optionsdialog.hpp"
#include "ui_optionsdialog.h"
#include "gamewindow.hpp"


/* Constructor of a dialog window. Its parent should be MainWindow. */
OptionsDialog::OptionsDialog(QWidget *parent) : QDialog(parent), m_ui_(new Ui::OptionsDialog), filename_(""){
    m_ui_->setupUi(this);

    connect( this->m_ui_->buttonBox, SIGNAL(accepted()), this, SLOT(onOk()));

    GameWindow *win = (GameWindow*)this->parent();
	connect(this, 
		SIGNAL(okSignal(TicTacToePlayer::PlayerSign, TicTacToePlayer::PlayerLevel, QString)), win, 
		SLOT(okClickedSlot(TicTacToePlayer::PlayerSign, TicTacToePlayer::PlayerLevel, QString)) );
}

/* A destuctor. */
OptionsDialog::~OptionsDialog(){
}

/* Handles situation when load button was clicked to load a specific oponent from a file. */
void OptionsDialog::on_loadOponentButton_clicked(){
	filename_ = QFileDialog::getOpenFileName(this, tr("Open"), "/", tr("Game Files (*.beg *.int *.adv)"));

	if(filename_.endsWith(".beg")){
		m_ui_->oponentLevelLabel->setText("Poczatkujacy");
		playerLevel_ = TicTacToePlayer::BEGINNER;
	} 
	else if(filename_.endsWith(".int")){
		m_ui_->oponentLevelLabel->setText("Sredni");
		playerLevel_ = TicTacToePlayer::INTERMEDIATE;
	} 
	else if(filename_.endsWith(".adv")){
		m_ui_->oponentLevelLabel->setText("Zaawansowany");
		playerLevel_ = TicTacToePlayer::ADVANCED;
	}
}

/* Handles situation when ok button was clicked. */
void OptionsDialog::onOk(){

	if(m_ui_->loadOponentRadioButton->isChecked() && filename_.isEmpty()){
		// filename wasn't chosen, sinal okSignal won't be generated
		QMessageBox msgBox;
		msgBox.setText("Brak pliku do wczytania przeciwnika. Wybierz plik lub zaznacz \"Nowy przeciwnik\"");
		msgBox.exec();
		return;
	}

	TicTacToePlayer::PlayerSign playerSign = (m_ui_->circleRadioButton->isChecked() ?
		TicTacToePlayer::CIRCLE : TicTacToePlayer::CROSS);
    
	// create a new oponent of specific level
	if(m_ui_->newOponentRadioButton->isChecked()){

		filename_ = ""; // set to default

		if(m_ui_->beginnerRadioButton->isChecked())
			playerLevel_ = TicTacToePlayer::BEGINNER;
		else if(m_ui_->intermediateRadioButton->isChecked())
			playerLevel_ = TicTacToePlayer::INTERMEDIATE;
		else
			playerLevel_ = TicTacToePlayer::ADVANCED;
	}
	// else - all parametres were set in on_loadOponentButton_clicked()

	okSignal(playerSign, playerLevel_, filename_);
}
