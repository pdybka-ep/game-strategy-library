/********************************************************************************
** Form generated from reading ui file 'optionsdialog.ui'
**
** Created: Sun 10. Jan 13:40:40 2010
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_OPTIONSDIALOG_H
#define UI_OPTIONSDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_OptionsDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QRadioButton *circleRadioButton;
    QRadioButton *crossRadioButton;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QRadioButton *newOponentRadioButton;
    QRadioButton *loadOponentRadioButton;
    QFrame *line;
    QPushButton *loadOponentButton;
    QLabel *label;
    QLabel *oponentLevelLabel;
    QFrame *frame;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *beginnerRadioButton;
    QRadioButton *intermediateRadioButton;
    QRadioButton *advancedRadioButton;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *OptionsDialog)
    {
        if (OptionsDialog->objectName().isEmpty())
            OptionsDialog->setObjectName(QString::fromUtf8("OptionsDialog"));
        OptionsDialog->resize(320, 313);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(OptionsDialog->sizePolicy().hasHeightForWidth());
        OptionsDialog->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addPixmap(QPixmap(QString::fromUtf8(":/res/ttt.ico")), QIcon::Normal, QIcon::Off);
        OptionsDialog->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(OptionsDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(OptionsDialog);
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


        verticalLayout->addWidget(groupBox);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        groupBox_2 = new QGroupBox(OptionsDialog);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        newOponentRadioButton = new QRadioButton(groupBox_2);
        newOponentRadioButton->setObjectName(QString::fromUtf8("newOponentRadioButton"));
        newOponentRadioButton->setChecked(true);

        gridLayout->addWidget(newOponentRadioButton, 0, 0, 1, 1);

        loadOponentRadioButton = new QRadioButton(groupBox_2);
        loadOponentRadioButton->setObjectName(QString::fromUtf8("loadOponentRadioButton"));

        gridLayout->addWidget(loadOponentRadioButton, 2, 0, 1, 1);

        line = new QFrame(groupBox_2);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 1, 0, 1, 2);

        loadOponentButton = new QPushButton(groupBox_2);
        loadOponentButton->setObjectName(QString::fromUtf8("loadOponentButton"));
        loadOponentButton->setEnabled(false);

        gridLayout->addWidget(loadOponentButton, 2, 1, 1, 1);

        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setEnabled(false);
        QFont font;
        font.setItalic(true);
        label->setFont(font);

        gridLayout->addWidget(label, 3, 0, 1, 1);

        oponentLevelLabel = new QLabel(groupBox_2);
        oponentLevelLabel->setObjectName(QString::fromUtf8("oponentLevelLabel"));
        oponentLevelLabel->setEnabled(false);

        gridLayout->addWidget(oponentLevelLabel, 3, 1, 1, 1);

        frame = new QFrame(groupBox_2);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        beginnerRadioButton = new QRadioButton(frame);
        beginnerRadioButton->setObjectName(QString::fromUtf8("beginnerRadioButton"));
        beginnerRadioButton->setChecked(true);

        verticalLayout_2->addWidget(beginnerRadioButton);

        intermediateRadioButton = new QRadioButton(frame);
        intermediateRadioButton->setObjectName(QString::fromUtf8("intermediateRadioButton"));

        verticalLayout_2->addWidget(intermediateRadioButton);

        advancedRadioButton = new QRadioButton(frame);
        advancedRadioButton->setObjectName(QString::fromUtf8("advancedRadioButton"));

        verticalLayout_2->addWidget(advancedRadioButton);


        gridLayout->addWidget(frame, 0, 1, 1, 1);


        verticalLayout->addWidget(groupBox_2);

        buttonBox = new QDialogButtonBox(OptionsDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(true);

        verticalLayout->addWidget(buttonBox);

        QWidget::setTabOrder(circleRadioButton, crossRadioButton);
        QWidget::setTabOrder(crossRadioButton, newOponentRadioButton);
        QWidget::setTabOrder(newOponentRadioButton, beginnerRadioButton);
        QWidget::setTabOrder(beginnerRadioButton, intermediateRadioButton);
        QWidget::setTabOrder(intermediateRadioButton, advancedRadioButton);
        QWidget::setTabOrder(advancedRadioButton, loadOponentRadioButton);
        QWidget::setTabOrder(loadOponentRadioButton, loadOponentButton);
        QWidget::setTabOrder(loadOponentButton, buttonBox);

        retranslateUi(OptionsDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), OptionsDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), OptionsDialog, SLOT(reject()));
        QObject::connect(newOponentRadioButton, SIGNAL(toggled(bool)), frame, SLOT(setEnabled(bool)));
        QObject::connect(loadOponentRadioButton, SIGNAL(toggled(bool)), loadOponentButton, SLOT(setEnabled(bool)));

        QMetaObject::connectSlotsByName(OptionsDialog);
    } // setupUi

    void retranslateUi(QDialog *OptionsDialog)
    {
        OptionsDialog->setWindowTitle(QApplication::translate("OptionsDialog", "Nowa gra", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("OptionsDialog", "Nowa rozgrywka", 0, QApplication::UnicodeUTF8));
        circleRadioButton->setText(QApplication::translate("OptionsDialog", "K\303\263\305\202ko", 0, QApplication::UnicodeUTF8));
        crossRadioButton->setText(QApplication::translate("OptionsDialog", "Krzy\305\274yk", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("OptionsDialog", "Przeciwnik", 0, QApplication::UnicodeUTF8));
        newOponentRadioButton->setText(QApplication::translate("OptionsDialog", "Nowy", 0, QApplication::UnicodeUTF8));
        loadOponentRadioButton->setText(QApplication::translate("OptionsDialog", "Wczytaj", 0, QApplication::UnicodeUTF8));
        loadOponentButton->setText(QApplication::translate("OptionsDialog", "Wczytaj przeciwnika...", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("OptionsDialog", "Poziom wczytanego przeciwnika:", 0, QApplication::UnicodeUTF8));
        oponentLevelLabel->setText(QString());
        beginnerRadioButton->setText(QApplication::translate("OptionsDialog", "Pocz\304\205tkuj\304\205cy", 0, QApplication::UnicodeUTF8));
        intermediateRadioButton->setText(QApplication::translate("OptionsDialog", "\305\232redni", 0, QApplication::UnicodeUTF8));
        advancedRadioButton->setText(QApplication::translate("OptionsDialog", "Zaawansowany", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(OptionsDialog);
    } // retranslateUi

};

namespace Ui {
    class OptionsDialog: public Ui_OptionsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIONSDIALOG_H
