#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include "card.h"
#include <QLayout>
#include "list.h"
#include "trackersql.h"
#include <QSqlQueryModel>

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void setWindowProperties(void);

    void windowFields(void);
    void createWindowFields(void);
    void setWindowFields(void);
    void arrangeWindowFields(void);

    Card *card;
    List *cardList;
    TrackerSql *sqlModel;

    QHBoxLayout *hCard;

public slots:
    void update(void);    
    void editRecord(void);
};

#endif // MAINWINDOW_H
