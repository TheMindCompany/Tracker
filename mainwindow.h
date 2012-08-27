#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include "card.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
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
    TrackerSql *sqlPersonModel,
                *sqlResponseModel;
    QLabel      *header;
    QVBoxLayout *vCard;
    QHBoxLayout *hCard;

public slots:
    void update(void);
};

#endif // MAINWINDOW_H
