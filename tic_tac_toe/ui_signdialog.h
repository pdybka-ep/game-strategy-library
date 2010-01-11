/********************************************************************************
** Form generated from reading ui file 'signdialog.ui'
**
** Created: Tue 12. Jan 00:42:10 2010
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_SIGNDIALOG_H
#define UI_SIGNDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QRadioButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SignDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QRadioButton *circleRadioButton;
    QRadioButton *crossRadioButton;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *SignDialog)
    {
        if (SignDialog->objectName().isEmpty())
            SignDialog->setObjectName(QString::fromUtf8("SignDialog"));
        SignDialog->resize(181, 115);
        verticalLayout = new QVBoxLayout(SignDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(SignDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        circleRadioButton = new QRadioButton(groupBox);
        circleRadioButton->setObjectName(QString::fromUtf8("circleRadioButton"));
        circleRadioButton->setChecked(true);

        horizontalLayout->addWidget(circleRadioButton);

        crossRadioButton = new QRadioButton(groupBox);
        crossRadioButton->setObjectName(QString::fromUtf8("crossRadioButton"));

        horizontalLayout->addWidget(crossRadioButton);

        circleRadioButton->raise();
        crossRadioButton->raise();

        verticalLayout->addWidget(groupBox);

        buttonBox = new QDialogButtonBox(SignDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(SignDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), SignDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SignDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(SignDialog);
    } // setupUi

    void retranslateUi(QDialog *SignDialog)
    {
        SignDialog->setWindowTitle(QApplication::translate("SignDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("SignDialog", "Wybierz znak", 0, QApplication::UnicodeUTF8));
        circleRadioButton->setText(QApplication::translate("SignDialog", "K\303\263\305\202ko", 0, QApplication::UnicodeUTF8));
        crossRadioButton->setText(QApplication::translate("SignDialog", "Krzy\305\274yk", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(SignDialog);
    } // retranslateUi

};

namespace Ui {
    class SignDialog: public Ui_SignDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNDIALOG_H
