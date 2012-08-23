#include "card.h"

Card::Card(QSqlQueryModel *model, QWidget *parent) :  CardUI(parent){
    setFormMap(model);
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

    connect(submitNew, SIGNAL(clicked()), this, SLOT(addRecord()));
}

void Card::clearFields(void){
    fnText->clear();
    miText->clear();
    lnText->clear();
    eaText->clear();
    edText->clear();
    isMember->setChecked(false);
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

    /*
    QString f = fnText->text();
    QString mi = miText->text();
    QString l = lnText->text();
    QString ea = eaText->text();
    QString ed = edText->text();
    bool member = isMember->isChecked();

    TrackerSql::setNewRecord(f,mi,l,ea,ed, member);
    */

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
    newRecord.clear();
    db.close();
    clearFields();
    return;
}

/*

CREATE TABLE `Survey` (
  `surveyID` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(40) DEFAULT NULL,
  `description` varchar(200) DEFAULT NULL,
  PRIMARY KEY (`surveyID`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci AUTO_INCREMENT=1 ;

CREATE TABLE `SurveyPerson` (
  `surveyPersonID` int(11) NOT NULL AUTO_INCREMENT,
  `surveyID` int(11) NOT NULL,
  `firstName` varchar(50) NOT NULL,
  `middleInitial` varchar(2) DEFAULT NULL,
  `lastName` varchar(50) DEFAULT NULL,
  `emailAddress` varchar(64) NOT NULL,
  `emailDomain` varchar(254) NOT NULL,
  `isMember` int(11) NOT NULL,
  PRIMARY KEY (`surveyPersonID`),
  FOREIGN KEY (`surveyID`) REFERENCES `Survey`(`surveyID`) ON UPDATE CASCADE ON DELETE CASCADE
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci AUTO_INCREMENT=1 ;

CREATE TABLE `SurveyResult` (
  `surveyResultID` int(11) NOT NULL AUTO_INCREMENT,
  `surveyPersonID` int(11) NOT NULL,
  `q0` int(11) NOT NULL,
  `q1` int(11) DEFAULT NULL,
  `q2` int(11) DEFAULT NULL,
  `q3` int(11) DEFAULT NULL,
  `q4` int(11) DEFAULT NULL,
  `q5` int(11) DEFAULT NULL,
  PRIMARY KEY (`surveyResultID`),
  FOREIGN KEY (`surveyPersonID`) REFERENCES `SurveyPerson`(`surveyPersonID`) ON UPDATE CASCADE ON DELETE CASCADE
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci AUTO_INCREMENT=1 ;

INSERT INTO `Survey` (`surveyID`, `name`, `description`) VALUES
(NULL, 'Signup Drive (Location: SGMH)', 'AITP Fall 2012 signup drive.  In the SGMH meeting area.'),
(NULL, 'Signup Drive (Location: Center)', 'AITP Fall 2012 signup drive.  In the free speech meeting area.');

INSERT INTO  `themind1_AMS`.`SurveyPerson` (`surveyPersonID` ,`surveyID` ,`firstName` ,`middleInitial` ,`lastName` ,`emailAddress` ,`emailDomain` ,`isMember`) VALUES
(NULL ,  '1',  'Brandon',  'L',  'Clark',  'webmind',  'hotmail.com',  '1'),
(NULL ,  '2',  'Sonia',  'M',  'Ramirez',  'nipigapa',  'aol.com',  '0');

INSERT INTO  `SurveyResult` (`surveyResultID` ,`surveyPersonID` ,`q0` ,`q1` ,`q2` ,`q3` ,`q4` ,`q5`) VALUES
(NULL ,  '1',  '1',  '0',  '1',  '0',  '0',  '0'),
(NULL ,  '2',  '0',  '0',  '1',  '0',  '0',  '0');


*/
