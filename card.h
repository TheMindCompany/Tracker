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
    explicit Card(QSqlQueryModel *model, QWidget *parent = 0);

    void setFormMap(QSqlQueryModel *model);
    void clearFields(void);
    void setSubmitEdit(void);
    bool readyToSubmit(void);

    QDataWidgetMapper *formMap;

signals:
    void newRecord(void);
    void setItemEdit(void);

public slots:
    void addRecord(void);
    void editFormMapItem(const QModelIndex &index);
    void editRecord(void);
    
};

#endif // CARD_H
