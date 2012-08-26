#include "mainwindow.h"
#include <QDebug>

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
    setWindowTitle("AMS Tracker");
    setFixedHeight(600);
    setFixedWidth(1024);
}

void MainWindow::windowFields(void){
    createWindowFields();
    setWindowFields();
    arrangeWindowFields();
}

void MainWindow::createWindowFields(void){
    sqlModel = new TrackerSql;
    card = new Card(sqlModel, this);
    cardList = new List(sqlModel, this);
}

void MainWindow::setWindowFields(void){ 
    connect(card, SIGNAL(newRecord()), this, SLOT(update()));// Refresh list with new entry.
    connect(cardList->theList, SIGNAL(doubleClicked(QModelIndex)), card, SLOT(editFormMapItem(QModelIndex)));// load selected list item to card.
}

void MainWindow::arrangeWindowFields(void){
    hCard = new QHBoxLayout;

    hCard->addWidget(card);
    hCard->addWidget(cardList);
}

void MainWindow::update(){
    sqlModel->refresh();
    cardList->setListItems(sqlModel);
    cardList->repaint();
}

void MainWindow::editRecord(void){
    qDebug() << "test";
}
