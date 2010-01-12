#ifndef SIGNDIALOG_HPP
#define SIGNDIALOG_HPP

#include <QtGui/QDialog>

#include <boost/shared_ptr.hpp>

#include "TicTacToePlayer.hpp"

namespace Ui {
    class SignDialog;
}

class SignDialog : public QDialog {
    Q_OBJECT
    Q_DISABLE_COPY(SignDialog)
public:
    explicit SignDialog(QWidget *parent, TicTacToePlayer::PlayerSign sign);
    virtual ~SignDialog();

signals:
    void okSignal(TicTacToePlayer::PlayerSign sign);

private slots:
    void onOk();

private:
    boost::shared_ptr<Ui::SignDialog> ui_;
};

#endif // SIGNDIALOG_HPP
