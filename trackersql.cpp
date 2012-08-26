#include "trackersql.h"
#include <QDebug>
#include <QSqlError>

TrackerSql::TrackerSql(QObject *parent): QSqlQueryModel(parent) {
    db = QSqlDatabase::addDatabase("QMYSQL");
    connectSQL();
}

void TrackerSql::connectSQL(void){
    setConnection();
    createConnection();
    setTableQuery();
}

void TrackerSql::setConnection(void){
    dbHost = "www.themindspot.com";
    dbName = "themind1_AMS";
    dbUser = "themind1_ams";
    dbPass = "nerdsrule";
    dbPort = 3306;
}

void TrackerSql::createConnection(void){
    db.setHostName(dbHost);
    db.setPort(dbPort);
    db.setDatabaseName(dbName);
    db.setUserName(dbUser);
    db.setPassword(dbPass);
    db.open();
}

void TrackerSql::setTableQuery(void){
    setQuery("SELECT * FROM SurveyPerson");
}

void TrackerSql::refresh(){
    setQuery("select * from SurveyPerson", db);
}

Qt::ItemFlags TrackerSql::flags(const QModelIndex &index) const{
    Qt::ItemFlags flags = QSqlQueryModel::flags(index);
    if (index.column() == 2 || index.column() == 3 || index.column() == 4 || index.column() == 5 || index.column() == 6 || index.column() == 7)
        flags |= Qt::ItemIsEditable;
    return flags;
}

bool TrackerSql::setData(const QModelIndex &index, const QVariant &value, int role){
    QModelIndex primaryKeyIndex = QSqlQueryModel::index(index.row(), 0);

    int id = data(primaryKeyIndex).toInt();
    int colum = index.column();

    clear();

    bool ok;
    switch (colum){
    case 2:{ok = setFirstName(id, value.toString());}
              break;
    case 3:{ok = setMiddleInitial(id, value.toString());}
              break;
    case 4:{ok = setLastName(id, value.toString());}
              break;
    case 5:{ok = setEmailAddress(id, value.toString());}
              break;
    case 6:{ok = setEmailDomain(id, value.toString());}
              break;
    case 7:{ok = setIsMember(id, value.toString());}
              break;
    }

    refresh();
    return ok;
}

bool TrackerSql::setFirstName(int personId, const QString &firstName){
    QSqlQuery query;

    query.prepare("update SurveyPerson set firstName = ? where surveyPersonID = ?");
    query.addBindValue(firstName);
    query.addBindValue(personId);
    return query.exec();
}

bool TrackerSql::setMiddleInitial(int personId, const QString &middleInitial){
    QSqlQuery query;

    query.prepare("update SurveyPerson set lastName = ? where surveyPersonID = ?");
    query.addBindValue(middleInitial);
    query.addBindValue(personId);
    return query.exec();
}

bool TrackerSql::setLastName(int personId, const QString &lastName){
    QSqlQuery query;

    query.prepare("update SurveyPerson set lastName = ? where surveyPersonID = ?");
    query.addBindValue(lastName);
    query.addBindValue(personId);
    return query.exec();
}

bool TrackerSql::setEmailAddress(int personId, const QString &emailAddress){
    QSqlQuery query;

    query.prepare("update SurveyPerson set lastName = ? where surveyPersonID = ?");
    query.addBindValue(emailAddress);
    query.addBindValue(personId);
    return query.exec();
}

bool TrackerSql::setEmailDomain(int personId, const QString &emailDomain){
    QSqlQuery query;

    query.prepare("update SurveyPerson set lastName = ? where surveyPersonID = ?");
    query.addBindValue(emailDomain);
    query.addBindValue(personId);
    return query.exec();
}

bool TrackerSql::setIsMember(int personId, const QString &isMember){
    QSqlQuery query;

    query.prepare("update SurveyPerson set lastName = ? where surveyPersonID = ?");
    query.addBindValue(isMember);
    query.addBindValue(personId);
    return query.exec();
}
