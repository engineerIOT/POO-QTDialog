#include "finddialog.h"

FindDialog::FindDialog(QWidget *parent)
    : QDialog(parent)
{
    label = new QLabel(tr("Find &what"));
    QLineEdit *qLineEdit = new QLineEdit;//lineEdit = new QLineEdit;
    //lineEdit = new QLine;
    label->setBuddy(qLineEdit);


    caseCheckBox = new QCheckBox(tr("Match &case"));
    backwardCheckBox = new QCheckBox(tr("Search &backward"));

    findButton = new QPushButton(tr("&Find"));
    findButton->setDefault(true);
    findButton->setEnabled(false);

    closeButton = new QPushButton(tr("Close"));

    QHBoxLayout *topLeftLayout = new QHBoxLayout;   //criando um novo objeto dinamicamente do tipo QHBoxLayout
    topLeftLayout->addWidget(label);
    topLeftLayout->addWidget(new QLineEdit);

    QVBoxLayout *leftLayout = new QVBoxLayout;      //criando um novo objeto dinamicamente do tipo QVBoxLayout
    leftLayout->addLayout(topLeftLayout);
    leftLayout->addWidget(caseCheckBox);
    leftLayout->addWidget(backwardCheckBox);

    QVBoxLayout *rightLayout = new QVBoxLayout;     //criando um novo objeto dinamicamente do tipo QVBoxLayout
    rightLayout->addWidget(findButton);
    rightLayout->addWidget(closeButton);
    rightLayout->addStretch();

    QHBoxLayout *mainLayout = new QHBoxLayout;      //criando um novo objeto dinamicamente do tipo QHBoxLayout
    mainLayout->addLayout(leftLayout);
    mainLayout->addLayout(rightLayout);
    setLayout(mainLayout);                    //setando o layout
    setWindowTitle (tr("Find"));
    setFixedHeight(sizeHint().height());
    setFixedWidth(sizeHint().width());


}

void FindDialog::findClicked(){

}

void FindDialog::enableFindButton(const QString &text){

}

FindDialog::~FindDialog()
{
}

