#include "card.h"
#include <QDebug>

Card::Card(QSqlQueryModel *model, QWidget *parent) :  CardUI(parent){
    setFormMap(model);
    connect(submitNew, SIGNAL(clicked()), this, SLOT(addRecord()));
}

void Card::setFormMap(QSqlQueryModel *model){

    formMap = new QDataWidgetMapper(this);
    formMap->setModel(model);
    formMap->setSubmitPolicy(QDataWidgetMapper::ManualSubmit);
    formMap->addMapping(cardID, 0);
    formMap->addMapping(fnText, 2);
    formMap->addMapping(miText, 3);
    formMap->addMapping(lnText, 4);
    formMap->addMapping(eaText, 5);
    formMap->addMapping(edText, 6);
    formMap->addMapping(isMember, 7);
}

void Card::clearFields(void){
    fnText->clear();
    miText->clear();
    lnText->clear();
    eaText->clear();
    edText->clear();
    isMember->setChecked(false);
}

void Card::setSubmitEdit(void){
}

void Card::addRecord(){
    if ( fnText->text() == "")
        return;
    else if (lnText->text() == "")
        return;
    else if (eaText->text() == "")
        return;
    else if (edText->text() == "")
        return;
    else if (cardID->text().toInt() < 1){
        qDebug() << "record in place";
        return;
    }

    QSqlDatabase    db;

    db.removeDatabase("Query");
    db = QSqlDatabase::addDatabase("QMYSQL", "Query");
    db.setHostName("www.themindspot.com");
    db.setPort(3306);
    db.setDatabaseName("themind1_AMS");
    db.setUserName("themind1_ams");
    db.setPassword("nerdsrule");
    db.open();

    QSqlQuery newRecord;

    newRecord.prepare("INSERT INTO `SurveyPerson` (`surveyPersonID`, `surveyID`, `firstName`, `middleInitial`, `lastName`, `emailAddress`, `emailDomain`, `isMember`)"
                      "VALUES (:id, :sid, :f, :mi, :l, :ea, :ed, :member)");
    newRecord.bindValue(":id", NULL);
    newRecord.bindValue(":sid", 1);
    newRecord.bindValue(":f",fnText->text());
    newRecord.bindValue(":mi",miText->text());
    newRecord.bindValue(":l",lnText->text());
    newRecord.bindValue(":ea",eaText->text());
    newRecord.bindValue(":ed",edText->text());
    newRecord.bindValue(":member",isMember->isChecked());
    newRecord.exec();
    int insertID = newRecord.lastInsertId().toInt();
    qDebug() << insertID;

    newRecord.clear();
    db.close();
    clearFields();
    return;
}

