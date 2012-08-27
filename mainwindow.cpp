#include "mainwindow.h"
#include <QDebug>
#include <QIcon>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent){
    QWidget *mainW = new QWidget;
    setCentralWidget(mainW);

    windowFields();
    setWindowProperties();

    mainW->setLayout(hCard);
}

MainWindow::~MainWindow(){
    
}

void MainWindow::setWindowProperties(void){
    setWindowTitle("AITP Membership Sign-Up");
    setFocus();

    QIcon icon;
    icon.addFile("C:/Users/MindTopOne/Desktop/Flash Backup/workplace/Tracker/images/favicon114.ico");
    setWindowIcon(icon);

    //setFixedHeight(600);
    //setFixedWidth(1024);
}

void MainWindow::windowFields(void){
    createWindowFields();
    setWindowFields();
    arrangeWindowFields();
}

void MainWindow::createWindowFields(void){
    sqlPersonModel = new TrackerSql;
    sqlPersonModel->createConnectionOne();

    sqlResponseModel = new TrackerSql;
    sqlResponseModel->createConnectionTwo();

    card = new Card(sqlPersonModel, sqlResponseModel, this);
    cardList = new List(sqlPersonModel, this);

    card->setMaximumWidth(460);
    card->setMaximumHeight(450);
    cardList->setMaximumWidth(150);
}

void MainWindow::setWindowFields(void){ 
    connect(card, SIGNAL(newRecord()), this, SLOT(update()));// Refresh list with new entry.
    connect(cardList->theList, SIGNAL(doubleClicked(QModelIndex)), card, SLOT(editFormMapItem(QModelIndex)));// load selected list item to card.
}

void MainWindow::arrangeWindowFields(void){
    hCard = new QHBoxLayout;
    hCard->addWidget(card);
    hCard->addWidget(cardList);
    hCard->setAlignment(card, Qt::AlignTop);
    hCard->setAlignment(Qt::AlignLeft);
}

void MainWindow::update(){
    sqlPersonModel->setCardTableQuery();
    sqlResponseModel->setResponseTableQuery();
}
