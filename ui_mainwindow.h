/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "canvas.h"
#include "compasswidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionShow_Spectrum;
    QAction *actionShowHeightmap;
    QAction *actionClose;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    QTabWidget *tabWidget;
    QWidget *tabRendering;
    QHBoxLayout *horizontalLayout_6;
    Canvas *canvas;
    QWidget *tabHeightMap;
    QHBoxLayout *horizontalLayout_8;
    QLabel *labelHeightMap;
    QWidget *tapSpectrum;
    QHBoxLayout *horizontalLayout_7;
    QLabel *labelSpectrum;
    QWidget *tab;
    QHBoxLayout *horizontalLayout_9;
    QLabel *labelInitialSpectrum;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    CompassWidget *compass;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QDoubleSpinBox *spinboxSpeed;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QComboBox *comboGridSize;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QSpinBox *spinboxPatchSize;
    QPushButton *btnChange;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1084, 580);
        actionShow_Spectrum = new QAction(MainWindow);
        actionShow_Spectrum->setObjectName(QStringLiteral("actionShow_Spectrum"));
        actionShowHeightmap = new QAction(MainWindow);
        actionShowHeightmap->setObjectName(QStringLiteral("actionShowHeightmap"));
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName(QStringLiteral("actionClose"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        tabRendering = new QWidget();
        tabRendering->setObjectName(QStringLiteral("tabRendering"));
        horizontalLayout_6 = new QHBoxLayout(tabRendering);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        canvas = new Canvas(tabRendering);
        canvas->setObjectName(QStringLiteral("canvas"));
        sizePolicy.setHeightForWidth(canvas->sizePolicy().hasHeightForWidth());
        canvas->setSizePolicy(sizePolicy);
        canvas->setFocusPolicy(Qt::StrongFocus);

        horizontalLayout_6->addWidget(canvas);

        tabWidget->addTab(tabRendering, QString());
        tabHeightMap = new QWidget();
        tabHeightMap->setObjectName(QStringLiteral("tabHeightMap"));
        horizontalLayout_8 = new QHBoxLayout(tabHeightMap);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        labelHeightMap = new QLabel(tabHeightMap);
        labelHeightMap->setObjectName(QStringLiteral("labelHeightMap"));
        sizePolicy.setHeightForWidth(labelHeightMap->sizePolicy().hasHeightForWidth());
        labelHeightMap->setSizePolicy(sizePolicy);
        labelHeightMap->setScaledContents(true);

        horizontalLayout_8->addWidget(labelHeightMap);

        tabWidget->addTab(tabHeightMap, QString());
        tapSpectrum = new QWidget();
        tapSpectrum->setObjectName(QStringLiteral("tapSpectrum"));
        horizontalLayout_7 = new QHBoxLayout(tapSpectrum);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        labelSpectrum = new QLabel(tapSpectrum);
        labelSpectrum->setObjectName(QStringLiteral("labelSpectrum"));
        labelSpectrum->setScaledContents(true);

        horizontalLayout_7->addWidget(labelSpectrum);

        tabWidget->addTab(tapSpectrum, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        horizontalLayout_9 = new QHBoxLayout(tab);
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        labelInitialSpectrum = new QLabel(tab);
        labelInitialSpectrum->setObjectName(QStringLiteral("labelInitialSpectrum"));
        labelInitialSpectrum->setScaledContents(true);

        horizontalLayout_9->addWidget(labelInitialSpectrum);

        tabWidget->addTab(tab, QString());

        horizontalLayout_2->addWidget(tabWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        compass = new CompassWidget(centralWidget);
        compass->setObjectName(QStringLiteral("compass"));

        verticalLayout->addWidget(compass);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_3->addWidget(label);

        spinboxSpeed = new QDoubleSpinBox(centralWidget);
        spinboxSpeed->setObjectName(QStringLiteral("spinboxSpeed"));
        spinboxSpeed->setMinimum(1);
        spinboxSpeed->setMaximum(256);
        spinboxSpeed->setValue(128);

        horizontalLayout_3->addWidget(spinboxSpeed);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_4->addWidget(label_2);

        comboGridSize = new QComboBox(centralWidget);
        comboGridSize->setObjectName(QStringLiteral("comboGridSize"));

        horizontalLayout_4->addWidget(comboGridSize);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_5->addWidget(label_3);

        spinboxPatchSize = new QSpinBox(centralWidget);
        spinboxPatchSize->setObjectName(QStringLiteral("spinboxPatchSize"));
        spinboxPatchSize->setMinimum(1);
        spinboxPatchSize->setMaximum(999999999);
        spinboxPatchSize->setValue(5);

        horizontalLayout_5->addWidget(spinboxPatchSize);


        verticalLayout->addLayout(horizontalLayout_5);

        btnChange = new QPushButton(centralWidget);
        btnChange->setObjectName(QStringLiteral("btnChange"));

        verticalLayout->addWidget(btnChange);


        horizontalLayout->addLayout(verticalLayout);


        horizontalLayout_2->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1084, 27));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionShow_Spectrum);
        menuFile->addAction(actionShowHeightmap);
        menuFile->addAction(actionClose);

        retranslateUi(MainWindow);
        QObject::connect(actionClose, SIGNAL(triggered()), MainWindow, SLOT(close()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionShow_Spectrum->setText(QApplication::translate("MainWindow", "Show Spectrum", 0));
        actionShowHeightmap->setText(QApplication::translate("MainWindow", "ShowHeightmap", 0));
        actionClose->setText(QApplication::translate("MainWindow", "Close", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabRendering), QApplication::translate("MainWindow", "Rendering", 0));
        labelHeightMap->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabHeightMap), QApplication::translate("MainWindow", "HeightMap", 0));
        labelSpectrum->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        tabWidget->setTabText(tabWidget->indexOf(tapSpectrum), QApplication::translate("MainWindow", "Spectrum", 0));
        labelInitialSpectrum->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Initial", 0));
        label->setText(QApplication::translate("MainWindow", "Speed", 0));
        label_2->setText(QApplication::translate("MainWindow", "Grid Size", 0));
        comboGridSize->clear();
        comboGridSize->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "32x32", 0)
         << QApplication::translate("MainWindow", "64x64", 0)
         << QApplication::translate("MainWindow", "128x128", 0)
         << QApplication::translate("MainWindow", "256x256", 0)
         << QApplication::translate("MainWindow", "512x512", 0)
         << QApplication::translate("MainWindow", "1024x1024", 0)
         << QApplication::translate("MainWindow", "2048x2048", 0)
        );
        label_3->setText(QApplication::translate("MainWindow", "Patch Size", 0));
        btnChange->setText(QApplication::translate("MainWindow", "Change", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "Menu", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
