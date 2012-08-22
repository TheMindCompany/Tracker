#include "cardui.h"
#include <QFile>

CardUI::CardUI(QWidget *parent) :  QWidget(parent){
    cardFields();
    setLayout(card);
}

void CardUI::cardFields(void){
    createCardFields();
    arrangeCardFields();
    setCardStyle();
}

void CardUI::createCardFields(void){
    nameFields();
    emailFields();
    qaFields();
    imageFields();
    submitFields();
}

void CardUI::arrangeCardFields(void){
    infoRequest = new QVBoxLayout;
    card = new QHBoxLayout;

    card->addLayout(image);

    infoRequest->addLayout(name);
    infoRequest->addLayout(email);
    infoRequest->addLayout(qa);
    infoRequest->addLayout(submit);

    card->addLayout(infoRequest);
}

void CardUI::nameFields(void){
    createNameFields();
    setNameFields();
    arrangeNameFields();
}

void CardUI::createNameFields(void){
    fnText = new QLineEdit;
    miText = new QLineEdit;
    lnText = new QLineEdit;
}

void CardUI::setNameFields(void){
    fnText->setMaximumWidth(190);
    miText->setMaximumWidth(50);
    lnText->setMaximumWidth(190);

    miText->setAlignment(Qt::AlignCenter);

    fnText->setPlaceholderText("First Name");
    miText->setPlaceholderText("MI");
    lnText->setPlaceholderText("Last Name");
}

void CardUI::arrangeNameFields(void){
    name = new QHBoxLayout;

    name->addWidget(fnText);
    name->addWidget(miText);
    name->addWidget(lnText);
}

void CardUI::emailFields(void){
    createEmailFields();
    setEmailFields();
    arrangeEmailFields();
}

void CardUI::createEmailFields(void){
    eaText = new QLineEdit;
    eAtLabel = new QLabel("@");
    edText = new QLineEdit;
}

void CardUI::setEmailFields(void){
    eaText->setPlaceholderText("Email Address");
    edText->setPlaceholderText("Email Domain");
}

void CardUI::arrangeEmailFields(void){
    email = new QHBoxLayout;

    email->addWidget(eaText);
    email->addWidget(eAtLabel);
    email->addWidget(edText);
}

void CardUI::qaFields(void){
    createQAFields();
    setQAFields();
    arrangeQAFields();
}

void CardUI::createQAFields(void){
    qaCheckOne = new QCheckBox;
    qaCheckTwo = new QCheckBox;
}

void CardUI::setQAFields(void){
    qaCheckOne->setText("Send Membership Brochure");
    qaCheckTwo->setText("Send Event Updates");
}

void CardUI::arrangeQAFields(void){
    qaColumOne = new QVBoxLayout;
    qa = new QHBoxLayout;

    qaCheckOne->setChecked(true);

    qaColumOne->addWidget(qaCheckOne);
    qaColumOne->addWidget(qaCheckTwo);

    qa->addLayout(qaColumOne);
}

void CardUI::imageFields(void){
    createImageFields();
    setImageFields();
    arrangeImageFields();
}

void CardUI::createImageFields(void){
    cardImage = new QGraphicsView;
}

void CardUI::setImageFields(void){
    cardImage->setFixedWidth(150);
    cardImage->setFixedHeight(200);

    cardImage->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    cardImage->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

void CardUI::arrangeImageFields(void){
    imageColum = new QVBoxLayout;
    image = new QHBoxLayout;

    imageColum->addWidget(cardImage);

    image->addLayout(imageColum);
}

void CardUI::submitFields(void){
    createSubmitFields();
    setSubmitFields();
    arrangeSubmitFields();
}

void CardUI::createSubmitFields(void){
    submitNew = new QPushButton("Add");
    submitEdit = new QPushButton("Edit");
    isMember = new QCheckBox;
}

void CardUI::setSubmitFields(void){
    submitNew->setFixedWidth(100);
    submitNew->setFixedHeight(50);
    isMember->setText("Member");
}

void CardUI::arrangeSubmitFields(void){
    submitStatus = new QVBoxLayout;
    submit = new QHBoxLayout;

    submitStatus->addWidget(submitNew);
    submitStatus->addWidget(isMember);

    submit->addLayout(submitStatus);
}

void CardUI::setCardStyle(void){
    QFile stylesheet("C:/Users/MindTopOne/Desktop/Flash Backup/workplace/amsTracker/assets/cardDesktopStyle.qss");
    stylesheet.open(QFile::ReadOnly);
    QString setSheet = QLatin1String(stylesheet.readAll());
    setStyleSheet(setSheet);
 }
