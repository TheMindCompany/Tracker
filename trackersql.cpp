#include "trackersql.h"

TrackerSql::TrackerSql(QObject *parent): QSqlQueryModel(parent) {
    setConnection();
}

void TrackerSql::connectSQL(void){
}

void TrackerSql::setConnection(void){
    dbHost = "www.themindspot.com";
    dbName = "themind1_AMS";
    dbUser = "themind1_ams";
    dbPass = "nerdsrule";
    dbPort = 3306;
}

void TrackerSql::createConnectionOne(void){
    db = QSqlDatabase::addDatabase("QMYSQL", "one");
    db.setHostName(dbHost);
    db.setPort(dbPort);
    db.setDatabaseName(dbName);
    db.setUserName(dbUser);
    db.setPassword(dbPass);
    db.open();

    setCardTableQuery();
}

void TrackerSql::createConnectionTwo(void){
    db2 = QSqlDatabase::addDatabase("QMYSQL", "two");
    db2.setHostName(dbHost);
    db2.setPort(dbPort);
    db2.setDatabaseName(dbName);
    db2.setUserName(dbUser);
    db2.setPassword(dbPass);
    db2.open();

    index(0,1);
    setResponseTableQuery();
}

void TrackerSql::setSurveyTableQuery(){
    setQuery("SELECT * FROM Survey", db);
}

void TrackerSql::setCardTableQuery(void){
    setQuery("SELECT * FROM SurveyPerson", db);
}

void TrackerSql::setResponseTableQuery(){
    setQuery("SELECT * FROM SurveyResult", db2);
}

