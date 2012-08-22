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

void TrackerSql::refresh(){
    setQuery("select * from SurveyPerson", db);
}

/*
BELOW ARE THE TABLES USED IN THIS PROGRAM


CREATE TABLE `Tracker` (
 `trackID` int(11) NOT NULL AUTO_INCREMENT,
 `tName` varchar(40) DEFAULT NULL,
 `tDesc` varchar(200) DEFAULT NULL,
 PRIMARY KEY (`trackID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci AUTO_INCREMENT=1 ;

CREATE TABLE `Card` (
 `cardID` int(11) NOT NULL AUTO_INCREMENT,
 `trackID` int(11) NOT NULL,
 `fName` varchar(21) NOT NULL,
 `mName` varchar(1) DEFAULT NULL,
 `lName` varchar(21) DEFAULT NULL,
 `email` varchar(50) NOT NULL,
 `isMember` int(1) NOT NULL,
 PRIMARY KEY (`cardID`),
 FOREIGN KEY (`trackID`) REFERENCES `Tracker`(`trackID`) ON UPDATE CASCADE ON DELETE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci AUTO_INCREMENT=1 ;

CREATE TABLE `Survey` (
 `cardID` int(11) NOT NULL,
 `trackID` int(11) NOT NULL,
 `q0` int(1) NOT NULL,
 `q1` int(1) DEFAULT NULL,
 `q2` int(1) DEFAULT NULL,
 `q3` int(1) DEFAULT NULL,
 `q4` int(1) DEFAULT NULL,
 `q5` int(1) DEFAULT NULL,
 PRIMARY KEY (`cardID`, `trackID`),
 FOREIGN KEY (`trackID`) REFERENCES `Tracker`(`trackID`) ON UPDATE CASCADE,
 FOREIGN KEY (`cardID`) REFERENCES `Card`(`cardID`) ON UPDATE CASCADE ON DELETE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci ;



TEST DATA
INSERT INTO `Card` (`cardID`, `trackID`, `fName`, `mName`, `lName`, `email`, `isMember`) VALUES
(1, 1, 'Brandon', 'L', 'Clark', 'webmind@hotmail.com', 1),
(2, 2, 'Sonia', 'M', 'Ramirez', 'nipiga@hotmail.com', 0);

INSERT INTO `Survey` (`cardID`, `trackID`, `q0`, `q1`, `q2`, `q3`, `q4`, `q5`) VALUES
(1, 1, 1, NULL, NULL, NULL, NULL, NULL),
(2, 2, 0, NULL, NULL, NULL, NULL, NULL);

INSERT INTO `Tracker` (`trackID`, `tName`, `tDesc`) VALUES
(1, 'Signup Drive (Location: SGMH)', 'AITP Fall 2012 signup drive.  In the SGMH meeting area.'),
(2, 'Signup Drive (Location: Center)', 'AITP Fall 2012 signup drive.  In the free speech meeting area.');
*/
