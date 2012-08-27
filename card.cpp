#include "card.h"
#include <QDebug>
#include <QSqlError>

Card::Card(QSqlQueryModel *personModel, QSqlQueryModel *responseModel, QWidget *parent) : CardUI(parent){
    setFormPersonMap(personModel);
    setFormResponseMap(responseModel);

    connect(submitNew, SIGNAL(clicked()), this, SLOT(addRecord()));
    connect(submitEdit, SIGNAL(clicked()), this, SLOT(editRecord()));
    connect(submitReset, SIGNAL(clicked()), this, SLOT(clearFields()));
    connect(submitDelete,SIGNAL(clicked()), this, SLOT(deleteRecord()));
}

void Card::setFormPersonMap(QSqlQueryModel *model){
    formPersonMap = new QDataWidgetMapper(this);
    formPersonMap->setModel(model);
    formPersonMap->setSubmitPolicy(QDataWidgetMapper::ManualSubmit);
    formPersonMap->addMapping(cardID, 0);
    formPersonMap->addMapping(fnText, 2);
    formPersonMap->addMapping(miText, 3);
    formPersonMap->addMapping(lnText, 4);
    formPersonMap->addMapping(eaText, 5);
    formPersonMap->addMapping(edText, 6);
    formPersonMap->addMapping(isMember, 7);
}

void Card::setFormResponseMap(QSqlQueryModel *model){
    formResponseMap = new QDataWidgetMapper(this);
    formResponseMap->setModel(model);
    formResponseMap->setSubmitPolicy(QDataWidgetMapper::ManualSubmit);
    formResponseMap->addMapping(q0, 2);
    formResponseMap->addMapping(q1, 3);
    formResponseMap->addMapping(q2, 4);
    formResponseMap->addMapping(q3, 5);
    formResponseMap->addMapping(q4, 6);
    formResponseMap->addMapping(q5, 7);
}

void Card::clearFields(void){
    cardID->clear();
    fnText->clear();
    miText->clear();
    lnText->clear();
    eaText->clear();
    edText->clear();
    isMember->setChecked(false);

    q0->setChecked(true);
    q1->setChecked(false);

    submitEdit->setHidden(true);
    submitDelete->setHidden(true);
    submitNew->setHidden(false);
    missingFirstName->setHidden(true);
    missingLastName->setHidden(true);
    missingEmailAddress->setHidden(true);
    missingEmailDomain->setHidden(true);
}

void Card::setSubmitEdit(void){
    submitNew->setHidden(true);

    submitEdit->setHidden(false);
    submitDelete->setHidden(false);
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

    QSqlDatabase    db;

    db.removeDatabase("qt_sql_default_connection");
    db = QSqlDatabase::addDatabase("QMYSQL");
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
    int spid = record.lastInsertId().toInt();
    record.prepare("INSERT INTO `SurveyResult` (`surveyResultID`, `surveyPersonID`, `q0`, `q1`, `q2`, `q3`, `q4`, `q5`)"
                      "VALUES (:id, :spid, :q0, :q1, :q2, :q3, :q4, :q5)");
    record.bindValue(":id", NULL);
    record.bindValue(":spid", spid);
    record.bindValue(":q0",q0->isChecked());
    record.bindValue(":q1",q1->isChecked());
    record.bindValue(":q2",q2->isChecked());
    record.bindValue(":q3",q3->isChecked());
    record.bindValue(":q4",q4->isChecked());
    record.bindValue(":q5",q5->isChecked());
    record.exec();

    db.close();
    clearFields();

    emit newRecord();
    return;
}


void Card::editFormMapItem(const QModelIndex &index){
    int id = index.row();
    formResponseMap->setCurrentIndex(id);
    formPersonMap->setCurrentIndex(id);
    setSubmitEdit();
}

void Card::editRecord(void){
    if ( readyToSubmit() == false){
        return;
    }

    QSqlDatabase    db;

    db.removeDatabase("qt_sql_default_connection");
    db = QSqlDatabase::addDatabase("QMYSQL");
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

    record.prepare("UPDATE SurveyResult SET q0 = ?, q1 = ?, q2 = ?, q3 = ?, q4 = ?, q5 = ? WHERE surveyPersonID = ?");
    record.addBindValue(q0->isChecked());
    record.addBindValue(q1->isChecked());
    record.addBindValue(q2->isChecked());
    record.addBindValue(q3->isChecked());
    record.addBindValue(q4->isChecked());
    record.addBindValue(q5->isChecked());
    record.addBindValue(cardID->text().toInt());
    record.exec();

    record.clear();
    db.close();
    clearFields();

    emit newRecord();
    return;
}

void Card::deleteRecord(void){
    QSqlDatabase    db;

    db.removeDatabase("qt_sql_default_connection");
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("www.themindspot.com");
    db.setPort(3306);
    db.setDatabaseName("themind1_AMS");
    db.setUserName("themind1_ams");
    db.setPassword("nerdsrule");
    db.open();

    QSqlQuery record;

    record.prepare("DELETE FROM SurveyPerson WHERE surveyPersonID = ?");
    record.addBindValue(cardID->text().toInt());
    record.exec();

    record.clear();
    db.close();
    clearFields();

    emit newRecord();
    return;
}

