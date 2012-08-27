#ifndef TRACKERSQL_H
#define TRACKERSQL_H

#include <QObject>
#include <QSqlQuery>
#include <QSqlQueryModel>

class TrackerSql : public QSqlQueryModel
{
    Q_OBJECT
public:
    TrackerSql(QObject *parent = 0);

    void connectSQL(void);        // Start sql connections and initialize `dbQuery`(s).
    void setConnection(void);     // Set the connection parameters.
    void createConnectionOne(void);  // Start the `db` connection.
    void createConnectionTwo(void);  // Start the `db2` connection.

    void setSurveyTableQuery(void);     // Create
    void setCardTableQuery(void);       // Create
    void setResponseTableQuery(void);   // Create

    QSqlDatabase    db,
                    db2;
    QString         dbHost,
                    dbName,
                    dbUser,
                    dbPass,
                    dbString;
    qint32          dbPort;

private:

};

#endif // TRACKERSQL_H
