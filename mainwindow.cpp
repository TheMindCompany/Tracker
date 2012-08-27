#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent){
    QWidget *mainW = new QWidget;
    setCentralWidget(mainW);

    windowFields();
    setWindowProperties();

    mainW->setLayout(vCard);
}

MainWindow::~MainWindow(){
    
}

void MainWindow::setWindowProperties(void){
    setWindowTitle("AITP Membership Sign-Up");
    setFocus();

    QIcon icon;
    icon.addFile("C:/Users/MindTopOne/Desktop/Flash Backup/workplace/Tracker/images/favicon114.ico");
    setWindowIcon(icon);

    setFixedHeight(440);
    setFixedWidth(670);
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

    header = new QLabel;
    header->setAlignment(Qt::AlignRight);
    header->setPixmap(QPixmap(QString("C:/Users/MindTopOne/Desktop/Flash Backup/workplace/Tracker/images/aitpLogo.png"),0,Qt::AutoColor));
}

void MainWindow::setWindowFields(void){
    card->setMaximumWidth(460);
    card->setMaximumHeight(450);
    cardList->setMaximumWidth(175);

    connect(card, SIGNAL(newRecord()), this, SLOT(update()));// Refresh list with new entry.
    connect(cardList->theList, SIGNAL(doubleClicked(QModelIndex)), card, SLOT(editFormMapItem(QModelIndex)));// load selected list item to card.
}

void MainWindow::arrangeWindowFields(void){
    hCard = new QHBoxLayout;
    vCard = new QVBoxLayout;
    vCard->setMargin(10);

    hCard->addWidget(card);
    hCard->addWidget(cardList);
    hCard->setAlignment(card, Qt::AlignTop);
    hCard->setAlignment(Qt::AlignLeft);

    vCard->addLayout(hCard);
    vCard->addWidget(header);
}

void MainWindow::update(){
    sqlPersonModel->setCardTableQuery();
    sqlResponseModel->setResponseTableQuery();
}
