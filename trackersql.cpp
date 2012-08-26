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

void TrackerSql::setSurveyTableQuery(){
    setQuery("SELECT * FROM Survey", db);
}

void TrackerSql::setCardTableQuery(void){
    setQuery("SELECT * FROM SurveyPerson", db);
}

void TrackerSql::setResponseTableQuery(){
    setQuery("SELECT * FROM SurveyResponse", db);
}

