#include "list.h"

List::List(QSqlQueryModel *model, QWidget *parent) :  ListUI(parent){
    addItem(model);
}

void List::setListItems(QSqlQueryModel *model){
    addItem(model);
}
