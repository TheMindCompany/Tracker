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
    theList = new QListView;
}

void ListUI::arrangeListFields(void){
    listColum = new QVBoxLayout;

    listColum->addWidget(theList);
}

void ListUI::addItem(QSqlQueryModel *model){
     theList->setModel(model);
     theList->setModelColumn(2);
}
