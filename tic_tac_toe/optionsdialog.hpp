#ifndef OPTIONSDIALOG_H
#define OPTIONSDIALOG_H

#include <QtGui/QDialog>

namespace Ui {
    class OptionsDialog;
}

class OptionsDialog : public QDialog {
    Q_OBJECT
    Q_DISABLE_COPY(OptionsDialog)
public:
    explicit OptionsDialog(QWidget *parent = 0);
    virtual ~OptionsDialog();

private:
    Ui::OptionsDialog *m_ui_;
    QString filename_;

signals:
     void Ok();

private slots:
    void on_loadOponentButton_clicked();
    void onOk();


};

#endif // OPTIONSDIALOG_H
