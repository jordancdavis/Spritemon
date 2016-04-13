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
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionExport;
    QAction *actionExit;
    QAction *actionInfo;
    QAction *actionSave_As;
    QAction *actionUndo;
    QAction *actionRedo;
    QAction *actionClear_Frame;
    QAction *actionDelete_Frame;
    QAction *actionNew_Frame;
    QAction *actionColor;
    QAction *actionDuplicate_Frame;
    QAction *actionClose;
    QWidget *centralWidget;
    QGroupBox *toolBox;
    QPushButton *paintbrushToolButton;
    QPushButton *darkenToolButton;
    QPushButton *paintbucketToolButton;
    QPushButton *eraseToolButton;
    QPushButton *lightenToolButton;
    QPushButton *mirrorToolButton;
    QPushButton *flipToolButton;
    QPushButton *pencileToolButton;
    QPushButton *smallPixelToolButton;
    QPushButton *mediumPixelToolButton;
    QPushButton *largePixelToolButton;
    QLabel *pixelSizeLabel;
    QGroupBox *colorBox;
    QPushButton *colorPalletToolButton;
    QPushButton *currentColorButton;
    QPushButton *previousColor4Button;
    QPushButton *previousColor5Button;
    QPushButton *previousColor6Button;
    QPushButton *previousColor3Button;
    QPushButton *previousColor1Button;
    QPushButton *previousColor2Button;
    QPushButton *colorDropperButton;
    QFrame *paintFrame;
    QPushButton *redoButton;
    QPushButton *undoButton;
    QPushButton *clearButton;
    QLabel *fpsLabel;
    QLabel *statusLabel;
    QListWidget *framesListWidget;
    QLabel *framesLabel;
    QLabel *label;
    QPushButton *deleteFrameButton;
    QPushButton *duplicateFrameButton;
    QSlider *fpsSlider;
    QLabel *previewLabel;
    QGroupBox *groupBox;
    QPushButton *actualButton;
    QPushButton *enlargeButton;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QMenu *menuEdit;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(750, 700);
        MainWindow->setMinimumSize(QSize(750, 700));
        MainWindow->setMaximumSize(QSize(750, 700));
        MainWindow->setStyleSheet(QLatin1String(" background-color:rgb(255, 255, 255)\n"
""));
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionExport = new QAction(MainWindow);
        actionExport->setObjectName(QStringLiteral("actionExport"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionInfo = new QAction(MainWindow);
        actionInfo->setObjectName(QStringLiteral("actionInfo"));
        actionSave_As = new QAction(MainWindow);
        actionSave_As->setObjectName(QStringLiteral("actionSave_As"));
        actionUndo = new QAction(MainWindow);
        actionUndo->setObjectName(QStringLiteral("actionUndo"));
        actionUndo->setShortcutContext(Qt::WindowShortcut);
        actionRedo = new QAction(MainWindow);
        actionRedo->setObjectName(QStringLiteral("actionRedo"));
        actionClear_Frame = new QAction(MainWindow);
        actionClear_Frame->setObjectName(QStringLiteral("actionClear_Frame"));
        actionDelete_Frame = new QAction(MainWindow);
        actionDelete_Frame->setObjectName(QStringLiteral("actionDelete_Frame"));
        actionNew_Frame = new QAction(MainWindow);
        actionNew_Frame->setObjectName(QStringLiteral("actionNew_Frame"));
        actionColor = new QAction(MainWindow);
        actionColor->setObjectName(QStringLiteral("actionColor"));
        actionDuplicate_Frame = new QAction(MainWindow);
        actionDuplicate_Frame->setObjectName(QStringLiteral("actionDuplicate_Frame"));
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName(QStringLiteral("actionClose"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        toolBox = new QGroupBox(centralWidget);
        toolBox->setObjectName(QStringLiteral("toolBox"));
        toolBox->setGeometry(QRect(20, 70, 100, 221));
        QFont font;
        font.setPointSize(12);
        toolBox->setFont(font);
        toolBox->setStyleSheet(QLatin1String(" background-color:rgb(233, 233, 233);\n"
"border: 1px solid #000000;\n"
"\n"
""));
        paintbrushToolButton = new QPushButton(toolBox);
        paintbrushToolButton->setObjectName(QStringLiteral("paintbrushToolButton"));
        paintbrushToolButton->setGeometry(QRect(10, 30, 31, 31));
        paintbrushToolButton->setToolTipDuration(5000);
        paintbrushToolButton->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	border-image: url(:/toolbar/icons/paint-brush-512.png);\n"
"}\n"
"\n"
"QPushButton:checked\n"
"{\n"
"	color:rgba(0, 145, 255, 128);\n"
"     background-color:rgba(0, 145, 255, 128);\n"
"}\n"
""));
        paintbrushToolButton->setCheckable(true);
        paintbrushToolButton->setChecked(true);
        darkenToolButton = new QPushButton(toolBox);
        darkenToolButton->setObjectName(QStringLiteral("darkenToolButton"));
        darkenToolButton->setGeometry(QRect(10, 180, 31, 31));
        darkenToolButton->setToolTipDuration(5000);
        darkenToolButton->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	border-image: url(:/toolbar/icons/darken.png)\n"
"}\n"
"\n"
"QPushButton:checked\n"
"{\n"
"	color:rgba(0, 145, 255, 128);\n"
"     background-color:rgba(0, 145, 255, 128);\n"
"}\n"
""));
        darkenToolButton->setCheckable(true);
        paintbucketToolButton = new QPushButton(toolBox);
        paintbucketToolButton->setObjectName(QStringLiteral("paintbucketToolButton"));
        paintbucketToolButton->setGeometry(QRect(60, 130, 31, 31));
        paintbucketToolButton->setToolTipDuration(5000);
        paintbucketToolButton->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	border-image: url(:/toolbar/icons/paintbucket1.png)\n"
"}\n"
"\n"
"QPushButton:checked\n"
"{\n"
"	color:rgba(0, 145, 255, 128);\n"
"     background-color:rgba(0, 145, 255, 128);\n"
"}\n"
""));
        paintbucketToolButton->setCheckable(true);
        eraseToolButton = new QPushButton(toolBox);
        eraseToolButton->setObjectName(QStringLiteral("eraseToolButton"));
        eraseToolButton->setGeometry(QRect(60, 30, 31, 31));
        eraseToolButton->setToolTipDuration(5000);
        eraseToolButton->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	border-image: url(:/toolbar/icons/eraser.png)\n"
"}\n"
"\n"
"QPushButton:checked\n"
"{\n"
"	color:rgba(0, 145, 255, 128);\n"
"     background-color:rgba(0, 145, 255, 128);\n"
"}"));
        eraseToolButton->setCheckable(true);
        lightenToolButton = new QPushButton(toolBox);
        lightenToolButton->setObjectName(QStringLiteral("lightenToolButton"));
        lightenToolButton->setGeometry(QRect(60, 180, 31, 31));
        lightenToolButton->setToolTipDuration(5000);
        lightenToolButton->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	border-image: url(:/toolbar/icons/lighten.png)\n"
"}\n"
"\n"
"QPushButton:checked\n"
"{\n"
"	color:rgba(0, 145, 255, 128);\n"
"     background-color:rgba(0, 145, 255, 128);\n"
"}\n"
""));
        lightenToolButton->setCheckable(true);
        mirrorToolButton = new QPushButton(toolBox);
        mirrorToolButton->setObjectName(QStringLiteral("mirrorToolButton"));
        mirrorToolButton->setGeometry(QRect(60, 80, 31, 31));
        mirrorToolButton->setToolTipDuration(5000);
        mirrorToolButton->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	border-image: url(:/toolbar/icons/draw.png)\n"
"}\n"
"\n"
"QPushButton:checked\n"
"{\n"
"	color:rgba(0, 145, 255, 128);\n"
"     background-color:rgba(0, 145, 255, 128);\n"
"}\n"
""));
        mirrorToolButton->setCheckable(true);
        flipToolButton = new QPushButton(toolBox);
        flipToolButton->setObjectName(QStringLiteral("flipToolButton"));
        flipToolButton->setGeometry(QRect(10, 80, 31, 31));
        flipToolButton->setToolTipDuration(5000);
        flipToolButton->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	border-image: url(:/toolbar/icons/flipImmage.png);\n"
"}\n"
"\n"
"QPushButton:checked\n"
"{\n"
"	color:rgba(0, 145, 255, 128);\n"
"     background-color:rgba(0, 145, 255, 128);\n"
"}\n"
""));
        flipToolButton->setCheckable(true);
        pencileToolButton = new QPushButton(toolBox);
        pencileToolButton->setObjectName(QStringLiteral("pencileToolButton"));
        pencileToolButton->setGeometry(QRect(10, 130, 31, 31));
        pencileToolButton->setToolTipDuration(5000);
        pencileToolButton->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	border-image:url(:/toolbar/icons/fillAllColor.png)\n"
"}\n"
"\n"
"QPushButton:checked\n"
"{\n"
"	color:rgba(0, 145, 255, 128);\n"
"     background-color:rgba(0, 145, 255, 128);\n"
"}\n"
""));
        pencileToolButton->setCheckable(true);
        smallPixelToolButton = new QPushButton(centralWidget);
        smallPixelToolButton->setObjectName(QStringLiteral("smallPixelToolButton"));
        smallPixelToolButton->setGeometry(QRect(20, 30, 25, 25));
        smallPixelToolButton->setToolTipDuration(5000);
        smallPixelToolButton->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"     background-color:rgb(255, 255, 255);\n"
"	border: 8px solid #000000;\n"
"}\n"
"\n"
"QPushButton:checked\n"
"{\n"
"	color:rgba(0, 145, 255, 128);\n"
"     background-color:rgba(0, 145, 255, 128);\n"
"}\n"
""));
        smallPixelToolButton->setCheckable(true);
        mediumPixelToolButton = new QPushButton(centralWidget);
        mediumPixelToolButton->setObjectName(QStringLiteral("mediumPixelToolButton"));
        mediumPixelToolButton->setGeometry(QRect(57, 30, 25, 25));
        mediumPixelToolButton->setToolTipDuration(5000);
        mediumPixelToolButton->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"     background-color:rgb(255, 255, 255);\n"
"	border: 5px solid #000000;\n"
"}\n"
"\n"
"QPushButton:checked\n"
"{\n"
"	color:rgba(0, 145, 255, 128);\n"
"     background-color:rgba(0, 145, 255, 128);\n"
"}\n"
""));
        mediumPixelToolButton->setCheckable(true);
        mediumPixelToolButton->setChecked(true);
        largePixelToolButton = new QPushButton(centralWidget);
        largePixelToolButton->setObjectName(QStringLiteral("largePixelToolButton"));
        largePixelToolButton->setGeometry(QRect(95, 30, 25, 25));
        largePixelToolButton->setToolTipDuration(5000);
        largePixelToolButton->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	background-color:rgb(255, 255, 255);\n"
"	border: 2px solid #000000;\n"
"}\n"
"\n"
"QPushButton:checked\n"
"{\n"
"	color:rgba(0, 145, 255, 128);\n"
"     background-color:rgba(0, 145, 255, 128);\n"
"}\n"
""));
        largePixelToolButton->setCheckable(true);
        pixelSizeLabel = new QLabel(centralWidget);
        pixelSizeLabel->setObjectName(QStringLiteral("pixelSizeLabel"));
        pixelSizeLabel->setGeometry(QRect(20, 10, 71, 21));
        pixelSizeLabel->setFont(font);
        colorBox = new QGroupBox(centralWidget);
        colorBox->setObjectName(QStringLiteral("colorBox"));
        colorBox->setGeometry(QRect(20, 300, 100, 200));
        colorBox->setFont(font);
        colorBox->setStyleSheet(QLatin1String(" background-color:rgb(233, 233, 233);\n"
"border: 1px solid #000000;\n"
"\n"
""));
        colorPalletToolButton = new QPushButton(colorBox);
        colorPalletToolButton->setObjectName(QStringLiteral("colorPalletToolButton"));
        colorPalletToolButton->setGeometry(QRect(10, 30, 31, 31));
        colorPalletToolButton->setToolTipDuration(5000);
        colorPalletToolButton->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	border-image: url(:/toolbar/icons/pallet.png)\n"
"}\n"
"\n"
""));
        colorPalletToolButton->setCheckable(true);
        currentColorButton = new QPushButton(colorBox);
        currentColorButton->setObjectName(QStringLiteral("currentColorButton"));
        currentColorButton->setGeometry(QRect(10, 70, 81, 61));
        currentColorButton->setStyleSheet(QLatin1String(" background-color:rgb(0, 0, 0);\n"
"border: 1px solid #000000;\n"
"\n"
""));
        previousColor4Button = new QPushButton(colorBox);
        previousColor4Button->setObjectName(QStringLiteral("previousColor4Button"));
        previousColor4Button->setGeometry(QRect(10, 170, 21, 21));
        previousColor4Button->setStyleSheet(QLatin1String(" background-color:rgb(0, 255, 0);\n"
"border: 1px solid #000000;"));
        previousColor5Button = new QPushButton(colorBox);
        previousColor5Button->setObjectName(QStringLiteral("previousColor5Button"));
        previousColor5Button->setGeometry(QRect(40, 170, 21, 21));
        previousColor5Button->setStyleSheet(QLatin1String(" background-color:rgb(0, 0, 255);\n"
"border: 1px solid #000000;"));
        previousColor6Button = new QPushButton(colorBox);
        previousColor6Button->setObjectName(QStringLiteral("previousColor6Button"));
        previousColor6Button->setGeometry(QRect(70, 170, 21, 21));
        previousColor6Button->setStyleSheet(QLatin1String(" background-color:rgb(255, 0, 0);\n"
"border: 1px solid #000000;"));
        previousColor3Button = new QPushButton(colorBox);
        previousColor3Button->setObjectName(QStringLiteral("previousColor3Button"));
        previousColor3Button->setGeometry(QRect(70, 140, 21, 21));
        previousColor3Button->setStyleSheet(QLatin1String(" background-color:rgb(255, 255, 0);\n"
"border: 1px solid #000000;"));
        previousColor1Button = new QPushButton(colorBox);
        previousColor1Button->setObjectName(QStringLiteral("previousColor1Button"));
        previousColor1Button->setGeometry(QRect(10, 140, 21, 21));
        previousColor1Button->setStyleSheet(QLatin1String(" background-color:rgb(255, 0, 255);\n"
"border: 1px solid #000000;"));
        previousColor2Button = new QPushButton(colorBox);
        previousColor2Button->setObjectName(QStringLiteral("previousColor2Button"));
        previousColor2Button->setGeometry(QRect(40, 140, 21, 21));
        previousColor2Button->setStyleSheet(QLatin1String(" background-color:rgb(0, 255, 255);\n"
"border: 1px solid #000000;"));
        colorDropperButton = new QPushButton(colorBox);
        colorDropperButton->setObjectName(QStringLiteral("colorDropperButton"));
        colorDropperButton->setGeometry(QRect(60, 30, 31, 31));
        colorDropperButton->setCursor(QCursor(Qt::ArrowCursor));
        colorDropperButton->setToolTipDuration(5000);
        colorDropperButton->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
" 	border-image: url(:/toolbar/icons/PaintDropper.png)\n"
"}\n"
"\n"
"QPushButton:checked\n"
"{\n"
"	color:rgba(0, 145, 255, 128);\n"
"     background-color:rgba(0, 145, 255, 128);\n"
"}\n"
""));
        colorDropperButton->setCheckable(true);
        colorDropperButton->setChecked(false);
        paintFrame = new QFrame(centralWidget);
        paintFrame->setObjectName(QStringLiteral("paintFrame"));
        paintFrame->setGeometry(QRect(140, 10, 448, 498));
        paintFrame->setStyleSheet(QLatin1String(" background-color:rgb(233, 233, 233);\n"
"border: 1px solid #000000;\n"
"\n"
"\n"
""));
        paintFrame->setFrameShape(QFrame::StyledPanel);
        paintFrame->setFrameShadow(QFrame::Raised);
        redoButton = new QPushButton(paintFrame);
        redoButton->setObjectName(QStringLiteral("redoButton"));
        redoButton->setGeometry(QRect(50, 10, 31, 31));
        redoButton->setToolTipDuration(5000);
        redoButton->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	border-image: url(:/toolbar/icons/redo.png)\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	color:rgba(0, 145, 255, 128);\n"
"     background-color:rgba(0, 145, 255, 128);\n"
"}"));
        redoButton->setCheckable(false);
        undoButton = new QPushButton(paintFrame);
        undoButton->setObjectName(QStringLiteral("undoButton"));
        undoButton->setGeometry(QRect(10, 10, 31, 31));
        undoButton->setToolTipDuration(5000);
        undoButton->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	border-image: url(:/toolbar/icons/undo.png)\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	color:rgba(0, 145, 255, 128);\n"
"     background-color:rgba(0, 145, 255, 128);\n"
"}\n"
""));
        undoButton->setCheckable(false);
        clearButton = new QPushButton(paintFrame);
        clearButton->setObjectName(QStringLiteral("clearButton"));
        clearButton->setGeometry(QRect(410, 10, 31, 31));
        clearButton->setToolTipDuration(5000);
        clearButton->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	border-image: url(:/toolbar/icons/delete.png)\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	color:rgba(0, 145, 255, 128);\n"
"     background-color:rgba(0, 145, 255, 128);\n"
"}"));
        clearButton->setCheckable(false);
        fpsLabel = new QLabel(centralWidget);
        fpsLabel->setObjectName(QStringLiteral("fpsLabel"));
        fpsLabel->setGeometry(QRect(600, 170, 31, 16));
        fpsLabel->setFont(font);
        statusLabel = new QLabel(centralWidget);
        statusLabel->setObjectName(QStringLiteral("statusLabel"));
        statusLabel->setGeometry(QRect(140, 508, 451, 31));
        QFont font1;
        font1.setPointSize(11);
        statusLabel->setFont(font1);
        statusLabel->setToolTipDuration(5000);
        statusLabel->setWordWrap(true);
        framesListWidget = new QListWidget(centralWidget);
        framesListWidget->setObjectName(QStringLiteral("framesListWidget"));
        framesListWidget->setGeometry(QRect(20, 540, 715, 125));
        framesListWidget->setStyleSheet(QLatin1String("QListWidget {background-color:rgb(233, 233, 233); border: 1px solid #000000;}\n"
"QListWidget::item:selected:active { background: qlineargradient(x1: 1, y1: 0, x2: 0, y2: 3, stop: 0 rgba(110, 187, 255, 128), stop: 1 rgba(110, 187, 255, 128));}"));
        framesListWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        framesListWidget->setDragEnabled(true);
        framesListWidget->setDragDropMode(QAbstractItemView::NoDragDrop);
        framesListWidget->setIconSize(QSize(75, 75));
        framesListWidget->setMovement(QListView::Static);
        framesListWidget->setFlow(QListView::LeftToRight);
        framesListWidget->setSpacing(10);
        framesListWidget->setViewMode(QListView::ListMode);
        framesListWidget->setSortingEnabled(false);
        framesLabel = new QLabel(centralWidget);
        framesLabel->setObjectName(QStringLiteral("framesLabel"));
        framesLabel->setGeometry(QRect(20, 520, 59, 16));
        framesLabel->setFont(font);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(600, 20, 59, 16));
        label->setFont(font);
        deleteFrameButton = new QPushButton(centralWidget);
        deleteFrameButton->setObjectName(QStringLiteral("deleteFrameButton"));
        deleteFrameButton->setGeometry(QRect(700, 550, 21, 31));
        deleteFrameButton->setToolTipDuration(5000);
        deleteFrameButton->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
" 	background-color:rgb(233, 233, 233);\n"
"\n"
" 	border-image: url(:/toolbar/icons/trash.png)\n"
"\n"
"\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	color:rgba(0, 145, 255, 128);\n"
"     background-color:rgba(0, 145, 255, 128);\n"
"}\n"
""));
        deleteFrameButton->setCheckable(false);
        duplicateFrameButton = new QPushButton(centralWidget);
        duplicateFrameButton->setObjectName(QStringLiteral("duplicateFrameButton"));
        duplicateFrameButton->setGeometry(QRect(700, 620, 21, 31));
        duplicateFrameButton->setToolTipDuration(5000);
        duplicateFrameButton->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
" 	background-color:rgb(233, 233, 233);\n"
"\n"
" 	border-image: url(:/toolbar/icons/copy.png)\n"
"\n"
"\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	color:rgba(0, 145, 255, 128);\n"
"     background-color:rgba(0, 145, 255, 128);\n"
"}\n"
""));
        duplicateFrameButton->setCheckable(false);
        fpsSlider = new QSlider(centralWidget);
        fpsSlider->setObjectName(QStringLiteral("fpsSlider"));
        fpsSlider->setGeometry(QRect(601, 190, 125, 22));
        fpsSlider->setToolTipDuration(5000);
        fpsSlider->setStyleSheet(QLatin1String("QSlider::groove:horizontal {\n"
"border: 1px solid #bbb;\n"
"background: white;\n"
"height: 10px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal {\n"
"background: qlineargradient(x1: 0, y1: 0,    x2: 0, y2: 1,\n"
"    stop: 0 #66e, stop: 1 #66e);\n"
"background: qlineargradient(x1: 0, y1: 0.2, x2: 1, y2: 1,\n"
"    stop: 0 rgba(0, 145, 255, 128), stop: 1 rgba(0, 145, 255, 128));\n"
"border: 1px solid #000;\n"
"height: 10px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::add-page:horizontal {\n"
"background: #fff;\n"
"border: 1px solid #000;\n"
"height: 10px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"background: qlineargradient(x1:0, y1:0, x2:1, y2:1,\n"
"    stop:0 #eee, stop:1 #ccc);\n"
"border: 1px solid #000;\n"
"width: 13px;\n"
"margin-top: -2px;\n"
"margin-bottom: -2px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal:hover {\n"
"background: qlineargradient(x1:0, y1:0, x2:1, y2:1,\n"
"    stop:0 #fff, stop:1 #ddd);\n"
"border: 1px solid "
                        "#444;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal:disabled {\n"
"background: #bbb;\n"
"border-color: #999;\n"
"}\n"
"\n"
"QSlider::add-page:horizontal:disabled {\n"
"background: #eee;\n"
"border-color: #999;\n"
"}\n"
"\n"
"QSlider::handle:horizontal:disabled {\n"
"background: #eee;\n"
"border: 1px solid #aaa;\n"
"border-radius: 4px;\n"
"}"));
        fpsSlider->setMaximum(24);
        fpsSlider->setValue(3);
        fpsSlider->setOrientation(Qt::Horizontal);
        previewLabel = new QLabel(centralWidget);
        previewLabel->setObjectName(QStringLiteral("previewLabel"));
        previewLabel->setGeometry(QRect(600, 40, 128, 128));
        previewLabel->setStyleSheet(QLatin1String("border: 1px solid #000000;\n"
""));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(599, 220, 128, 80));
        groupBox->setStyleSheet(QLatin1String(" background-color:rgb(233, 233, 233);\n"
"border: 1px solid #000000;\n"
""));
        actualButton = new QPushButton(groupBox);
        actualButton->setObjectName(QStringLiteral("actualButton"));
        actualButton->setGeometry(QRect(10, 40, 108, 32));
        actualButton->setStyleSheet(QLatin1String("QPushButton:checked\n"
"{\n"
"	color:black;\n"
"     background-color:rgba(0, 145, 255, 128);\n"
"}"));
        actualButton->setCheckable(true);
        enlargeButton = new QPushButton(groupBox);
        enlargeButton->setObjectName(QStringLiteral("enlargeButton"));
        enlargeButton->setGeometry(QRect(10, 10, 108, 32));
        enlargeButton->setStyleSheet(QLatin1String("QPushButton:checked\n"
"{\n"
"	color: black;\n"
"     background-color:rgba(0, 145, 255, 128);\n"
"}"));
        enlargeButton->setCheckable(true);
        enlargeButton->setChecked(true);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 750, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        statusBar->setMouseTracking(false);
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addSeparator();
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_As);
        menuFile->addAction(actionExport);
        menuFile->addSeparator();
        menuFile->addAction(actionClose);
        menuFile->addSeparator();
        menuHelp->addAction(actionInfo);
        menuEdit->addAction(actionUndo);
        menuEdit->addAction(actionRedo);
        menuEdit->addAction(actionClear_Frame);
        menuEdit->addSeparator();
        menuEdit->addAction(actionNew_Frame);
        menuEdit->addAction(actionDuplicate_Frame);
        menuEdit->addAction(actionDelete_Frame);
        menuEdit->addSeparator();
        menuEdit->addAction(actionColor);
        menuEdit->addSeparator();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Spritemon", 0));
        actionNew->setText(QApplication::translate("MainWindow", "New", 0));
        actionNew->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", 0));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", 0));
        actionOpen->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0));
        actionSave->setText(QApplication::translate("MainWindow", "Save", 0));
        actionSave->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0));
        actionExport->setText(QApplication::translate("MainWindow", "Export", 0));
        actionExport->setShortcut(QApplication::translate("MainWindow", "Ctrl+Return", 0));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0));
        actionInfo->setText(QApplication::translate("MainWindow", "Info", 0));
        actionInfo->setShortcut(QApplication::translate("MainWindow", "Ctrl+I", 0));
        actionSave_As->setText(QApplication::translate("MainWindow", "Save As...", 0));
        actionSave_As->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+S", 0));
        actionUndo->setText(QApplication::translate("MainWindow", "Undo", 0));
        actionUndo->setShortcut(QApplication::translate("MainWindow", "Ctrl+Z", 0));
        actionRedo->setText(QApplication::translate("MainWindow", "Redo", 0));
        actionRedo->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+Z", 0));
        actionClear_Frame->setText(QApplication::translate("MainWindow", "Clear Frame", 0));
        actionClear_Frame->setShortcut(QApplication::translate("MainWindow", "Ctrl+R", 0));
        actionDelete_Frame->setText(QApplication::translate("MainWindow", "Delete Frame", 0));
        actionDelete_Frame->setShortcut(QApplication::translate("MainWindow", "Ctrl+-", 0));
        actionNew_Frame->setText(QApplication::translate("MainWindow", "New Frame", 0));
        actionNew_Frame->setShortcut(QApplication::translate("MainWindow", "Ctrl++", 0));
        actionColor->setText(QApplication::translate("MainWindow", "Color ...", 0));
        actionColor->setShortcut(QApplication::translate("MainWindow", "Ctrl+C", 0));
        actionDuplicate_Frame->setText(QApplication::translate("MainWindow", "Duplicate Frame", 0));
        actionDuplicate_Frame->setShortcut(QApplication::translate("MainWindow", "Ctrl+D", 0));
        actionClose->setText(QApplication::translate("MainWindow", "Close", 0));
        actionClose->setShortcut(QApplication::translate("MainWindow", "Esc", 0));
        toolBox->setTitle(QApplication::translate("MainWindow", "Tools", 0));
#ifndef QT_NO_TOOLTIP
        paintbrushToolButton->setToolTip(QApplication::translate("MainWindow", "Brush Tool", 0));
#endif // QT_NO_TOOLTIP
        paintbrushToolButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        darkenToolButton->setToolTip(QApplication::translate("MainWindow", "Darken Tool", 0));
#endif // QT_NO_TOOLTIP
        darkenToolButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        paintbucketToolButton->setToolTip(QApplication::translate("MainWindow", "Fill Group Color", 0));
#endif // QT_NO_TOOLTIP
        paintbucketToolButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        eraseToolButton->setToolTip(QApplication::translate("MainWindow", "Eraser", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        eraseToolButton->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        eraseToolButton->setWhatsThis(QApplication::translate("MainWindow", "Erases pixels", 0));
#endif // QT_NO_WHATSTHIS
        eraseToolButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        lightenToolButton->setToolTip(QApplication::translate("MainWindow", "Lighten Tool", 0));
#endif // QT_NO_TOOLTIP
        lightenToolButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        mirrorToolButton->setToolTip(QApplication::translate("MainWindow", "Mirror Tool", 0));
#endif // QT_NO_TOOLTIP
        mirrorToolButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        flipToolButton->setToolTip(QApplication::translate("MainWindow", "Flip Image", 0));
#endif // QT_NO_TOOLTIP
        flipToolButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        pencileToolButton->setToolTip(QApplication::translate("MainWindow", "Fill All Tool", 0));
#endif // QT_NO_TOOLTIP
        pencileToolButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        smallPixelToolButton->setToolTip(QApplication::translate("MainWindow", "1 Pixel", 0));
#endif // QT_NO_TOOLTIP
        smallPixelToolButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        mediumPixelToolButton->setToolTip(QApplication::translate("MainWindow", "2 Pixels", 0));
#endif // QT_NO_TOOLTIP
        mediumPixelToolButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        largePixelToolButton->setToolTip(QApplication::translate("MainWindow", "3 Pixels", 0));
#endif // QT_NO_TOOLTIP
        largePixelToolButton->setText(QString());
        pixelSizeLabel->setText(QApplication::translate("MainWindow", "Pixel Size", 0));
        colorBox->setTitle(QApplication::translate("MainWindow", "Color", 0));
#ifndef QT_NO_TOOLTIP
        colorPalletToolButton->setToolTip(QApplication::translate("MainWindow", "Color Palette", 0));
#endif // QT_NO_TOOLTIP
        colorPalletToolButton->setText(QString());
        currentColorButton->setText(QString());
        previousColor4Button->setText(QString());
        previousColor5Button->setText(QString());
        previousColor6Button->setText(QString());
        previousColor3Button->setText(QString());
        previousColor1Button->setText(QString());
        previousColor2Button->setText(QString());
#ifndef QT_NO_TOOLTIP
        colorDropperButton->setToolTip(QApplication::translate("MainWindow", "Color Grabber", 0));
#endif // QT_NO_TOOLTIP
        colorDropperButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        redoButton->setToolTip(QApplication::translate("MainWindow", "Redo", 0));
#endif // QT_NO_TOOLTIP
        redoButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        undoButton->setToolTip(QApplication::translate("MainWindow", "Undo", 0));
#endif // QT_NO_TOOLTIP
        undoButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        clearButton->setToolTip(QApplication::translate("MainWindow", "Clear Current Frame", 0));
#endif // QT_NO_TOOLTIP
        clearButton->setText(QString());
        fpsLabel->setText(QApplication::translate("MainWindow", "FPS", 0));
#ifndef QT_NO_TOOLTIP
        statusLabel->setToolTip(QApplication::translate("MainWindow", "Status Bar", 0));
#endif // QT_NO_TOOLTIP
        statusLabel->setText(QString());
        framesLabel->setText(QApplication::translate("MainWindow", "Frames", 0));
        label->setText(QApplication::translate("MainWindow", "Preview", 0));
#ifndef QT_NO_TOOLTIP
        deleteFrameButton->setToolTip(QApplication::translate("MainWindow", "Delete Frame", 0));
#endif // QT_NO_TOOLTIP
        deleteFrameButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        duplicateFrameButton->setToolTip(QApplication::translate("MainWindow", "Copy Frame", 0));
#endif // QT_NO_TOOLTIP
        duplicateFrameButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        fpsSlider->setToolTip(QApplication::translate("MainWindow", "Frames Per Second", 0));
#endif // QT_NO_TOOLTIP
        previewLabel->setText(QString());
        groupBox->setTitle(QString());
        actualButton->setText(QApplication::translate("MainWindow", "Actual Size", 0));
        enlargeButton->setText(QApplication::translate("MainWindow", "Enlarged Size", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
