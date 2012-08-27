#ifndef LISTUI_H
#define LISTUI_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QListView>
#include <QSqlQueryModel>

class ListUI : public QWidget
{
    Q_OBJECT
public:
    explicit ListUI(QWidget *parent = 0);

    QLabel      *listHeader,
                *listFooter,
                *listCount;
    QVBoxLayout *listColum;
    QHBoxLayout *listTotal;
    QListView   *theList;


protected:
    void listFields(void);          //
    void createListFields(void);    //
    void arrangeListFields(void);   //

    void addItem(QSqlQueryModel *model);

signals:

public slots:

};

#endif // LISTUI_H
