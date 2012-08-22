#include "list.h"
#include <QDebug>

List::List(QSqlQueryModel *model, QWidget *parent) :  ListUI(parent){
    setListItems(model);
}

void List::setListItems(QSqlQueryModel *model){
        addItem(model);
}
