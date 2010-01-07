/**
  @file optionsdialog.hpp
  @author Hanna Dutkiewicz
*/

#ifndef OPTIONSDIALOG_H
#define OPTIONSDIALOG_H

#include <QtGui/QDialog>
#include <boost/shared_ptr.hpp>

namespace Ui {
    class OptionsDialog;
}

/**
  @class OptionsDialog
  Dialog window with options to be set before playing.
  One of the GUI classes.
  @author Hanna Dutkiewicz
  */
class OptionsDialog : public QDialog {
    Q_OBJECT
    Q_DISABLE_COPY(OptionsDialog)

public:
    /**
      Constructor of a dialog window. Its parent should be MainWindow.
      @param parent pointer to a parent window.
      */
    explicit OptionsDialog(QWidget *parent = 0);

    /**
      A destuctor.
      */
    virtual ~OptionsDialog();


signals:
    /**
      Signal generated after Ok button was clicked.
      Gives all the parametres to the main window of the game.
      @see onOk()
      */
     void Ok();

private slots:
     /**
      Handles situation when load button was clicked to load a specific oponent from a file.
      */
    void on_loadOponentButton_clicked();
    /**
      Handles situation when ok button was clicked.
      Gets all the parametres from options window and generates signal Ok()
      */
    void onOk();

private:
    /** User interface object for OptionsDialog */
	boost::shared_ptr<Ui::OptionsDialog> m_ui_;


};

#endif // OPTIONSDIALOG_H
