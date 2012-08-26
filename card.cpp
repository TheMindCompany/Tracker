#include "card.h"
#include <QDebug>
#include <QSqlError>

Card::Card(QSqlQueryModel *model, QWidget *parent) :  CardUI(parent){
    setFormMap(model);
    connect(submitNew, SIGNAL(clicked()), this, SLOT(addRecord()));    
    connect(submitEdit, SIGNAL(clicked()), this, SLOT(editRecord()));
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
    cardID->clear();
    fnText->clear();
    miText->clear();
    lnText->clear();
    eaText->clear();
    edText->clear();
    isMember->setChecked(false);

    submitEdit->setHidden(true);
    submitNew->setHidden(false);
}

void Card::setSubmitEdit(void){
    submitNew->setHidden(true);
    submitEdit->setHidden(false);
}

bool Card::readyToSubmit(void){
    bool ok = true;

    if ( fnText->text() == ""){
        ok = false;
        missingFirstName->setHidden(false);
    } else if (missingFirstName->isHidden() == false){
        missingFirstName->setHidden(true);
    }

    if (lnText->text() == ""){
        ok = false;
        missingLastName->setHidden(false);
    } else if (missingLastName->isHidden() == false){
        missingLastName->setHidden(true);
    }

    if (eaText->text() == ""){
        ok = false;
        missingEmailAddress->setHidden(false);
    } else if (missingEmailAddress->isHidden() == false){
        missingEmailAddress->setHidden(true);
    }

    if (edText->text() == ""){
        ok = false;
        missingEmailDomain->setHidden(false);
    } else if (missingEmailDomain->isHidden() == false){
        missingEmailDomain->setHidden(true);
    }

    return ok;
}

void Card::addRecord(void){
    if ( readyToSubmit() == false){
        return;
    }

    //else if ((cardID->text().toInt()) > 0) { qDebug() << "already exist!";return; }

    QSqlDatabase    db;

    db.removeDatabase("Query");
    db = QSqlDatabase::addDatabase("QMYSQL", "Query");
    db.setHostName("www.themindspot.com");
    db.setPort(3306);
    db.setDatabaseName("themind1_AMS");
    db.setUserName("themind1_ams");
    db.setPassword("nerdsrule");
    db.open();

    QSqlQuery record;

    record.prepare("INSERT INTO `SurveyPerson` (`surveyPersonID`, `surveyID`, `firstName`, `middleInitial`, `lastName`, `emailAddress`, `emailDomain`, `isMember`)"
                      "VALUES (:id, :sid, :f, :mi, :l, :ea, :ed, :member)");
    record.bindValue(":id", NULL);
    record.bindValue(":sid", 1);
    record.bindValue(":f",fnText->text());
    record.bindValue(":mi",miText->text());
    record.bindValue(":l",lnText->text());
    record.bindValue(":ea",eaText->text());
    record.bindValue(":ed",edText->text());
    record.bindValue(":member",isMember->isChecked());
    record.exec();

    //int insertID = record.lastInsertId().toInt();

    record.clear();
    db.close();
    clearFields();

    emit newRecord();
    return;
}

void Card::editFormMapItem(const QModelIndex &index){
    int id = index.row();

    formMap->setCurrentIndex(id);
    setSubmitEdit();
}

void Card::editRecord(void){
    if ( readyToSubmit() == false){
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

    QSqlQuery record;

    record.prepare("UPDATE SurveyPerson SET firstName = ?, middleInitial = ?, lastName = ?, emailAddress = ?, emailDomain = ?, isMember = ? WHERE surveyPersonID = ?");

    record.addBindValue(fnText->text());
    record.addBindValue(miText->text());
    record.addBindValue(lnText->text());
    record.addBindValue(eaText->text());
    record.addBindValue(edText->text());
    record.addBindValue(isMember->isChecked());
    record.addBindValue(cardID->text().toInt());
    record.exec();

    //int insertID = record.lastInsertId().toInt();

    record.clear();
    db.close();
    clearFields();

    emit newRecord();
    return;
}

