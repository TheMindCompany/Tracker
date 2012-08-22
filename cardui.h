#ifndef CARDUI_H
#define CARDUI_H

#include <QWidget>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QCheckBox>
#include <QPushButton>
#include <QGraphicsView>

class CardUI : public QWidget
{
    Q_OBJECT
public:
    explicit CardUI(QWidget *parent = 0);

    void cardFields(void);          // Create all card fields, formated and arranged.
    void createCardFields(void);    // Create individual card field data sets, formated and arranged.
    void arrangeCardFields(void);   // Arrange field data sets into 'card' layout.

    void nameFields(void);          // Create all card name fields, formated and arranged.
    void createNameFields(void);    // Create field instance.
    void setNameFields(void);       // Set field properties.
    void arrangeNameFields(void);   // Arrange fields into 'name' layout.

    void emailFields(void);         // Create all card email fields, formated and arranged.
    void createEmailFields(void);   // Create field instance.
    void setEmailFields(void);      // Set field properties.
    void arrangeEmailFields(void);  // Arrange fields into 'email' layout.

    void qaFields(void);            // Create all card question and answer fields, formated and arranged.
    void createQAFields(void);      // Create field instance.
    void setQAFields(void);         // Set field properties.
    void arrangeQAFields(void);     // Arrange fields into 'qa' layout.

    void imageFields(void);         // Create all card image fields, formated and arranged.
    void createImageFields(void);   // Create field instance.
    void setImageFields(void);      // Set field properties.
    void arrangeImageFields(void);  // Arrange fields into 'image' layout.

    void submitFields(void);        // Create all card submit fields, formated and arranged.
    void createSubmitFields(void);  // Create field instance.
    void setSubmitFields(void);     // Set field properties.
    void arrangeSubmitFields(void); // Arrange fields into 'submit' layout.

    void setCardStyle(void);

    QLineEdit   *fnText,
                *miText,
                *lnText,
                *eaText,
                *edText;
    QLabel      *eAtLabel;
    QCheckBox   *qaCheckOne,
                *qaCheckTwo,
                *isMember;
    QPushButton *submitNew,
                *submitEdit;
    QHBoxLayout *card,
                *name,
                *email,
                *qa,
                *image,
                *submit;
    QVBoxLayout *qaColumOne,
                *imageColum,
                *submitStatus,
                *infoRequest;
    QGraphicsView *cardImage;

signals:

    
public slots:
    
};

#endif // CARDUI_H
