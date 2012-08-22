#ifndef LIST_H
#define LIST_H

#include "listui.h"
#include <QSqlQueryModel>

class List : public ListUI
{
    Q_OBJECT
public:
    explicit List(QSqlQueryModel *model, QWidget *parent); // Initialize with model reference location of model.

    void setListItems(QSqlQueryModel *model);   // Set card list. (currently in debug output mode for test)

    void addListItem(QSqlQueryModel model);
    void updateListItem(QSqlQueryModel model);
    void deleteListItem(QSqlQueryModel model);
signals:

public slots:

};

#endif // LIST_H
