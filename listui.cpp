#include "listui.h"
#include <QFile>

ListUI::ListUI(QWidget *parent) : QWidget(parent){
    listFields();

    setLayout(listColum);
}

void ListUI::listFields(void){
    createListFields();
    arrangeListFields();
}

void ListUI::createListFields(void){
    listHeader = new QLabel;
    listFooter = new QLabel;
    listCount = new QLabel;
    theList = new QListView;

    listHeader->setPixmap(QPixmap(QString("C:/Users/MindTopOne/Desktop/Flash Backup/workplace/Tracker/images/listHeader.png"),0,Qt::AutoColor));
    listFooter->setPixmap(QPixmap(QString("C:/Users/MindTopOne/Desktop/Flash Backup/workplace/Tracker/images/totalInterest.png"),0,Qt::AutoColor));
}

void ListUI::arrangeListFields(void){
    listColum = new QVBoxLayout;
    listTotal = new QHBoxLayout;


    listTotal->addWidget(listFooter);
    listTotal->addWidget(listCount);

    listColum->addWidget(listHeader);
    listColum->addWidget(theList);
    //listColum->addLayout(listTotal);
}

void ListUI::addItem(QSqlQueryModel *model){
    listCount->setText("2");
    listCount->setAlignment(Qt::AlignRight);
    listCount->setStyleSheet("QLabel {font-size:40px;  color:#47505a; font-weight:bold;}");
     theList->setModel(model);
     theList->setModelColumn(2);
     theList->setEditTriggers(QAbstractItemView::NoEditTriggers);
}
