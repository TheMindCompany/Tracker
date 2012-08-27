#ifndef CARD_H
#define CARD_H

#include "cardui.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDataWidgetMapper>

class Card : public CardUI
{
    Q_OBJECT
public:
    explicit Card(QSqlQueryModel *personModel, QSqlQueryModel *responseModel, QWidget *parent);

    void setFormPersonMap(QSqlQueryModel *model);
    void setFormResponseMap(QSqlQueryModel *model);
    void setSubmitEdit(void);
    bool readyToSubmit(void);

    QDataWidgetMapper *formPersonMap,
                      *formResponseMap;

signals:
    void newRecord(void);
    void setItemEdit(void);

public slots:
    void addRecord(void);
    void editFormMapItem(const QModelIndex &index);
    void editRecord(void);
    void deleteRecord(void);
    void clearFields(void);
    
};

#endif // CARD_H
