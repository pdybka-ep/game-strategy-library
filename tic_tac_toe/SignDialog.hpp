/**
  @file SignDialog.hpp
  @author Hanna Dutkiewicz
*/

#ifndef SIGNDIALOG_HPP
#define SIGNDIALOG_HPP

#include <QtGui/QDialog>

#include <boost/shared_ptr.hpp>

#include "TicTacToePlayer.hpp"

namespace Ui {
    class SignDialog;
}

/**
	@class SignClass
	@author Hanna Dutkiewicz
	Dialog window to change human player sign
*/
class SignDialog : public QDialog {
    Q_OBJECT
    Q_DISABLE_COPY(SignDialog)
	
public:

	/**
		Constructor, fills dialog elements with appropriate data
		@param parent parent to this dialog window
		@param sign current sign of a human player
	*/
    explicit SignDialog(QWidget *parent, TicTacToePlayer::PlayerSign sign);
    
	/**
		Virtual destructor
	*/
	virtual ~SignDialog();

/******** SIGNALS **********/
signals:
	/**
		Signal generated to a game window with a new sign to be set for a human player
		@param sign new human player sign
	*/
    void okSignal(TicTacToePlayer::PlayerSign sign);

/******** SLOTS **********/
private slots:
	/**
		Slot for a signal generated when a dialog box was closed with Ok button
	*/
    void onOk();

private:
	/** User interface element of a SignDIalog */ 
    boost::shared_ptr<Ui::SignDialog> ui_;
};

#endif // SIGNDIALOG_HPP
