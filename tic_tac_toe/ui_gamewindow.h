/********************************************************************************
** Form generated from reading ui file 'gamewindow.ui'
**
** Created: Sat 9. Jan 12:49:12 2010
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_GAMEWINDOW_H
#define UI_GAMEWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGraphicsView>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameWindow
{
public:
    QAction *actionNewGame;
    QAction *actionNew;
    QAction *actionBeginner;
    QAction *actionIntermediate;
    QAction *actionAdvanced;
    QAction *actionSave;
    QAction *actionLoad;
    QAction *actionEnd;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QLabel *label_5;
    QLabel *label;
    QLCDNumber *playerPointsLcd;
    QLabel *label_4;
    QLabel *label_3;
    QLCDNumber *OponentPointsLcd;
    QLabel *label_6;
    QLabel *oponentLevelLabel;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer_3;
    QLabel *playerTypeLabel;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_4;
    QPushButton *exitButton;
    QPushButton *newGameButton;
    QGraphicsView *graphicsView;
    QSpacerItem *horizontalSpacer_2;
    QMenuBar *menuBar;
    QMenu *menuGame;
    QMenu *menuOponent;
    QMenu *menuNewOponent;

    void setupUi(QMainWindow *GameWindow)
    {
        if (GameWindow->objectName().isEmpty())
            GameWindow->setObjectName(QString::fromUtf8("GameWindow"));
        GameWindow->resize(609, 407);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(GameWindow->sizePolicy().hasHeightForWidth());
        GameWindow->setSizePolicy(sizePolicy);
        GameWindow->setMinimumSize(QSize(600, 407));
        QIcon icon;
        icon.addPixmap(QPixmap(QString::fromUtf8(":/res/ttt.ico")), QIcon::Normal, QIcon::Off);
        GameWindow->setWindowIcon(icon);
        actionNewGame = new QAction(GameWindow);
        actionNewGame->setObjectName(QString::fromUtf8("actionNewGame"));
        actionNew = new QAction(GameWindow);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        actionBeginner = new QAction(GameWindow);
        actionBeginner->setObjectName(QString::fromUtf8("actionBeginner"));
        actionIntermediate = new QAction(GameWindow);
        actionIntermediate->setObjectName(QString::fromUtf8("actionIntermediate"));
        actionAdvanced = new QAction(GameWindow);
        actionAdvanced->setObjectName(QString::fromUtf8("actionAdvanced"));
        actionSave = new QAction(GameWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionSave->setEnabled(false);
        actionSave->setVisible(true);
        actionLoad = new QAction(GameWindow);
        actionLoad->setObjectName(QString::fromUtf8("actionLoad"));
        actionEnd = new QAction(GameWindow);
        actionEnd->setObjectName(QString::fromUtf8("actionEnd"));
        centralWidget = new QWidget(GameWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setMargin(11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QFont font;
        font.setBold(true);
        font.setUnderline(true);
        font.setWeight(75);
        label_5->setFont(font);

        gridLayout->addWidget(label_5, 4, 1, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setItalic(true);
        label->setFont(font1);

        gridLayout->addWidget(label, 1, 1, 1, 1);

        playerPointsLcd = new QLCDNumber(centralWidget);
        playerPointsLcd->setObjectName(QString::fromUtf8("playerPointsLcd"));
        playerPointsLcd->setFrameShape(QFrame::StyledPanel);
        playerPointsLcd->setFrameShadow(QFrame::Raised);
        playerPointsLcd->setSmallDecimalPoint(false);
        playerPointsLcd->setSegmentStyle(QLCDNumber::Flat);

        gridLayout->addWidget(playerPointsLcd, 4, 2, 1, 1);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        gridLayout->addWidget(label_4, 5, 1, 1, 1);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font1);

        gridLayout->addWidget(label_3, 3, 1, 1, 2);

        OponentPointsLcd = new QLCDNumber(centralWidget);
        OponentPointsLcd->setObjectName(QString::fromUtf8("OponentPointsLcd"));
        OponentPointsLcd->setFrameShape(QFrame::StyledPanel);
        OponentPointsLcd->setSegmentStyle(QLCDNumber::Flat);

        gridLayout->addWidget(OponentPointsLcd, 5, 2, 1, 1);

        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font1);

        gridLayout->addWidget(label_6, 7, 1, 1, 1);

        oponentLevelLabel = new QLabel(centralWidget);
        oponentLevelLabel->setObjectName(QString::fromUtf8("oponentLevelLabel"));
        QFont font2;
        font2.setBold(true);
        font2.setWeight(75);
        oponentLevelLabel->setFont(font2);
        oponentLevelLabel->setFrameShape(QFrame::StyledPanel);

        gridLayout->addWidget(oponentLevelLabel, 7, 2, 1, 2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(verticalSpacer_2, 0, 1, 1, 2);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(verticalSpacer_3, 8, 1, 1, 2);

        playerTypeLabel = new QLabel(centralWidget);
        playerTypeLabel->setObjectName(QString::fromUtf8("playerTypeLabel"));
        playerTypeLabel->setFont(font2);
        playerTypeLabel->setFrameShape(QFrame::StyledPanel);

        gridLayout->addWidget(playerTypeLabel, 1, 2, 1, 2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(verticalSpacer, 2, 1, 1, 2);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(verticalSpacer_4, 6, 1, 1, 2);

        exitButton = new QPushButton(centralWidget);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));

        gridLayout->addWidget(exitButton, 9, 2, 1, 1);

        newGameButton = new QPushButton(centralWidget);
        newGameButton->setObjectName(QString::fromUtf8("newGameButton"));

        gridLayout->addWidget(newGameButton, 9, 1, 1, 1);

        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy1);
        graphicsView->setMaximumSize(QSize(371, 329));
        graphicsView->setAutoFillBackground(false);
        QBrush brush(QColor(65, 65, 65, 255));
        brush.setStyle(Qt::NoBrush);
        graphicsView->setBackgroundBrush(brush);

        gridLayout->addWidget(graphicsView, 0, 0, 10, 1);

        horizontalSpacer_2 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 9, 3, 1, 1);


        horizontalLayout->addLayout(gridLayout);

        GameWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(GameWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 609, 23));
        menuGame = new QMenu(menuBar);
        menuGame->setObjectName(QString::fromUtf8("menuGame"));
        menuOponent = new QMenu(menuBar);
        menuOponent->setObjectName(QString::fromUtf8("menuOponent"));
        menuNewOponent = new QMenu(menuOponent);
        menuNewOponent->setObjectName(QString::fromUtf8("menuNewOponent"));
        GameWindow->setMenuBar(menuBar);

        menuBar->addAction(menuGame->menuAction());
        menuBar->addAction(menuOponent->menuAction());
        menuGame->addAction(actionNewGame);
        menuGame->addSeparator();
        menuGame->addAction(actionEnd);
        menuOponent->addAction(menuNewOponent->menuAction());
        menuOponent->addAction(actionSave);
        menuOponent->addAction(actionLoad);
        menuOponent->addSeparator();
        menuNewOponent->addAction(actionBeginner);
        menuNewOponent->addAction(actionIntermediate);
        menuNewOponent->addAction(actionAdvanced);

        retranslateUi(GameWindow);
        QObject::connect(exitButton, SIGNAL(clicked()), GameWindow, SLOT(close()));
        QObject::connect(newGameButton, SIGNAL(clicked()), actionNewGame, SLOT(trigger()));

        QMetaObject::connectSlotsByName(GameWindow);
    } // setupUi

    void retranslateUi(QMainWindow *GameWindow)
    {
        GameWindow->setWindowTitle(QApplication::translate("GameWindow", "K\303\263\305\202ko i krzy\305\274yk", 0, QApplication::UnicodeUTF8));
        actionNewGame->setText(QApplication::translate("GameWindow", "Nowe rozdanie", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionNewGame->setToolTip(QApplication::translate("GameWindow", "&Nowe rozdanie", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionNewGame->setShortcut(QApplication::translate("GameWindow", "Ctrl+N", 0, QApplication::UnicodeUTF8));
        actionNew->setText(QApplication::translate("GameWindow", "Nowy...", 0, QApplication::UnicodeUTF8));
        actionBeginner->setText(QApplication::translate("GameWindow", "Pocz\304\205tkuj\304\205cy", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionBeginner->setToolTip(QApplication::translate("GameWindow", "&Pocz\304\205tkuj\304\205cy", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionIntermediate->setText(QApplication::translate("GameWindow", "\305\232redni", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionIntermediate->setToolTip(QApplication::translate("GameWindow", "\305\232&redni", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionAdvanced->setText(QApplication::translate("GameWindow", "Zaawansowany", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionAdvanced->setToolTip(QApplication::translate("GameWindow", "Z&aawansowany", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionSave->setText(QApplication::translate("GameWindow", "Zapisz...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionSave->setToolTip(QApplication::translate("GameWindow", "&Zapisz", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionSave->setShortcut(QApplication::translate("GameWindow", "Ctrl+S", 0, QApplication::UnicodeUTF8));
        actionLoad->setText(QApplication::translate("GameWindow", "Wczytaj...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionLoad->setToolTip(QApplication::translate("GameWindow", "&Wczytaj", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionLoad->setShortcut(QApplication::translate("GameWindow", "Ctrl+O", 0, QApplication::UnicodeUTF8));
        actionEnd->setText(QApplication::translate("GameWindow", "Zako\305\204cz", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionEnd->setToolTip(QApplication::translate("GameWindow", "Za&ko\305\204cz", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_5->setText(QApplication::translate("GameWindow", "Ty:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("GameWindow", "Jeste\305\233:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("GameWindow", "Komputer:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("GameWindow", "Statystyki zwyci\304\231stw w rozgrywce:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("GameWindow", "Poziom przeciwnika:", 0, QApplication::UnicodeUTF8));
        oponentLevelLabel->setText(QString());
        playerTypeLabel->setText(QString());
        exitButton->setText(QApplication::translate("GameWindow", "Koniec", 0, QApplication::UnicodeUTF8));
        newGameButton->setText(QApplication::translate("GameWindow", "Nowe rozdanie", 0, QApplication::UnicodeUTF8));
        menuGame->setTitle(QApplication::translate("GameWindow", "Gra", 0, QApplication::UnicodeUTF8));
        menuOponent->setTitle(QApplication::translate("GameWindow", "Przeciwnik", 0, QApplication::UnicodeUTF8));
        menuNewOponent->setTitle(QApplication::translate("GameWindow", "Nowy", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class GameWindow: public Ui_GameWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEWINDOW_H
