#include "cardui.h"
#include <QFile>

CardUI::CardUI(QWidget *parent) :  QWidget(parent){
    cardHeader = new QLabel("");
    cardHeader->setPixmap(QPixmap(QString(":images/cardHeader.png"),0,Qt::AutoColor));

    cardID = new QLineEdit;
    cardID->setHidden(true);

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
    //card->addLayout(image);
    infoRequest->addWidget(cardHeader);
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
    missingFirstName = new QLabel("* Missing First Name");
    missingLastName = new QLabel("* Missing Last Name");
}

void CardUI::setNameFields(void){
    fnText->setFixedWidth(190);
    miText->setFixedWidth(50);
    lnText->setFixedWidth(190);

    fnText->setMaxLength(50);
    miText->setMaxLength(2);
    lnText->setMaxLength(50);

    miText->setAlignment(Qt::AlignCenter);

    fnText->setPlaceholderText("First Name");
    miText->setPlaceholderText("MI");
    lnText->setPlaceholderText("Last Name");

    missingFirstName->setStyleSheet("QLabel {font-size:8px;  color:darkred;}");
    missingLastName->setStyleSheet("QLabel {font-size:8px;  color:darkred;}");
    missingFirstName->setHidden(true);
    missingLastName->setHidden(true);
}

void CardUI::arrangeNameFields(void){
    name = new QHBoxLayout;
    firstNameBox = new QVBoxLayout;
    miBox = new QVBoxLayout;
    lastNameBox = new QVBoxLayout;

    name->setAlignment(Qt::AlignBottom);
    firstNameBox->setAlignment(Qt::AlignBottom);
    miBox->setAlignment(Qt::AlignBottom);
    miBox->setAlignment(miText, Qt::AlignCenter);
    lastNameBox->setAlignment(Qt::AlignBottom);

    firstNameBox->addWidget(missingFirstName);
    firstNameBox->addWidget(fnText);
    miBox->addWidget(miText);
    lastNameBox->addWidget(missingLastName);
    lastNameBox->addWidget(lnText);

    name->addLayout(firstNameBox);
    name->addLayout(miBox);
    name->addLayout(lastNameBox);
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

    missingEmailAddress = new QLabel("* Missing Email Address");
    missingEmailDomain = new QLabel("* Missing Email Domain");
}

void CardUI::setEmailFields(void){
    eaText->setFixedWidth(190);
    eAtLabel->setFixedWidth(50);
    edText->setFixedWidth(190);

    eaText->setMaxLength(54);
    edText->setMaxLength(254);

    eAtLabel->setAlignment(Qt::AlignCenter);
    eAtLabel->setStyleSheet("QLabel {font-size:25px;  color:darkgray; margin: 8;}");
    eaText->setPlaceholderText("Email Address");
    edText->setPlaceholderText("Email Domain");

    missingEmailAddress->setStyleSheet("QLabel {font-size:8px;  color:darkred;}");
    missingEmailDomain->setStyleSheet("QLabel {font-size:8px;  color:darkred;}");
    missingEmailAddress->setHidden(true);
    missingEmailDomain->setHidden(true);
}

void CardUI::arrangeEmailFields(void){
    email = new QHBoxLayout;
    emailAddressBox = new QVBoxLayout;
    eAtBox = new QVBoxLayout;
    emailDomainBox = new QVBoxLayout;

    emailAddressBox->addWidget(missingEmailAddress);
    emailAddressBox->addWidget(eaText);
    eAtBox->addWidget(eAtLabel);
    emailDomainBox->addWidget(missingEmailDomain);
    emailDomainBox->addWidget(edText);

    emailAddressBox->setAlignment(Qt::AlignBottom);
    eAtBox->setAlignment(Qt::AlignBottom);
    emailDomainBox->setAlignment(Qt::AlignBottom);
    email->setAlignment(Qt::AlignBottom);

    email->addLayout(emailAddressBox);
    email->addLayout(eAtBox);
    email->addLayout(emailDomainBox);
}

void CardUI::qaFields(void){
    createQAFields();
    setQAFields();
    arrangeQAFields();
}

void CardUI::createQAFields(void){
    q0 = new QCheckBox;
    q1 = new QCheckBox;
    q2 = new QCheckBox;
    q3 = new QCheckBox;
    q4 = new QCheckBox;
    q5 = new QCheckBox;
}

void CardUI::setQAFields(void){
    q0->setText("Send Membership Brochure");
    q1->setText("Send Event Updates");
    q2->setHidden(true);
    q2->setText("");
    q3->setHidden(true);
    q3->setText("");
    q4->setHidden(true);
    q4->setText("");
    q5->setHidden(true);
    q5->setText("");

}

void CardUI::arrangeQAFields(void){
    qaColumOne = new QVBoxLayout;
    qaColumTwo = new QVBoxLayout;
    qa = new QHBoxLayout;

    qa->setMargin(10);
    q0->setChecked(true);

    qaColumOne->addWidget(q0);
    qaColumOne->addWidget(q1);
    qaColumOne->addWidget(q2);

    qaColumTwo->addWidget(q3);
    qaColumTwo->addWidget(q4);
    qaColumTwo->addWidget(q5);

    qa->addLayout(qaColumOne);
    qa->addLayout(qaColumTwo);
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
    submitReset = new QPushButton("Clear");
    submitDelete = new QPushButton("Delete");
    isMember = new QCheckBox;
}

void CardUI::setSubmitFields(void){
    submitNew->setFixedWidth(100);
    submitNew->setFixedHeight(50);
    submitEdit->setFixedWidth(100);
    submitEdit->setFixedHeight(50);
    submitReset->setFixedWidth(100);
    submitReset->setFixedHeight(50);
    submitDelete->setFixedWidth(100);
    submitDelete->setFixedHeight(50);

    submitNew->setAutoDefault(true);
    isMember->setText("Member");
    /*QPalette red;
    QColor setRed;
    setRed.setRed(160);
    red.setColor(QPalette::Button, setRed.toRgb());
    //submitReset->setFlat(true);
    submitReset->setPalette(red);*/

    submitEdit->setHidden(true);
    submitDelete->setHidden(true);
}

void CardUI::arrangeSubmitFields(void){
    submitStatus = new QVBoxLayout;
    submit = new QHBoxLayout;
    editButtons = new QHBoxLayout;

    editButtons->setAlignment(Qt::AlignLeft);
    editButtons->addWidget(submitNew);
    editButtons->addWidget(submitEdit);
    editButtons->addWidget(submitDelete);
    editButtons->addWidget(submitReset);

    submitStatus->addLayout(editButtons);
    submitStatus->addWidget(isMember);

    submit->addLayout(submitStatus);
}

void CardUI::setCardStyle(void){
    QFile stylesheet(":assets/cardDesktopStyle.qss");
    stylesheet.open(QFile::ReadOnly);
    QString setSheet = QLatin1String(stylesheet.readAll());
    setStyleSheet(setSheet);
 }
