#include "mainwindow.h"

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

void MainWindow::initializeList(const QSqlQueryModel model){

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

}

void MainWindow::arrangeWindowFields(void){
    hCard = new QHBoxLayout;

    hCard->addWidget(card);
    hCard->addWidget(cardList);
}
