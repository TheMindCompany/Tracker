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
    void createConnection(void);  // Start the `db` connection.

    void setSurveyTableQuery(void);     // Create
    void setCardTableQuery(void);       // Create
    void setResponseTableQuery(void);   // Create

    QSqlDatabase    db;
    QString         dbHost,
                    dbName,
                    dbUser,
                    dbPass,
                    dbString;
    qint32          dbPort;

private:

};

#endif // TRACKERSQL_H
