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

    void setTableQuery(void); // Create `dbQuery`(s).

    Qt::ItemFlags flags(const QModelIndex &index) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);

    bool setFirstName(int personId, const QString &firstName);
    bool setMiddleInitial(int personId, const QString &middleInitial);
    bool setLastName(int personId, const QString &lastName);
    bool setEmailAddress(int personId, const QString &emailAddress);
    bool setEmailDomain(int personId, const QString &emailDomain);
    bool setIsMember(int personId, const QString &isMember);
    virtual void refresh();

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
