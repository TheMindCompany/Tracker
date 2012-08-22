#ifndef CARD_H
#define CARD_H

#include "cardui.h"
#include <QDataWidgetMapper>

class Card : public CardUI
{
    Q_OBJECT
public:
    explicit Card(QWidget *parent = 0);

    QDataWidgetMapper *formMap;
    
signals:
    
public slots:
    
};

#endif // CARD_H
