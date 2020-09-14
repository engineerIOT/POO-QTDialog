#include "finddialog.h"

FindDialog::FindDialog(QWidget *parent)
    : QDialog(parent)
{
    label = new QLabel(tr("Find &what"));
    QLineEdit *lineEdit = new QLineEdit;//lineEdit = new QLineEdit;
    //lineEdit = new QLine;
    label->setBuddy(lineEdit);


    caseCheckBox = new QCheckBox(tr("Match &case"));
    backwardCheckBox = new QCheckBox(tr("Search &backward"));

    findButton = new QPushButton(tr("&Find"));
    findButton->setDefault(true);
    findButton->setEnabled(false);

    closeButton = new QPushButton(tr("Close"));

    connect (lineEdit, SIGNAL(textChanged(const QString &)),
             this, SLOT (enableFindButton(const QString &)));

    connect(findButton, SIGNAL(clicked()),
            this, SLOT(findClicked()));

    connect(closeButton, SIGNAL(clicked()),
            this, SLOT(close()));

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
    QString text = lineEdit->text();
    Qt::CaseSensitivity cs = caseCheckBox->isChecked() ? Qt::CaseSensitive
                                                       : Qt::CaseSensitive;
    if (backwardCheckBox->isChecked()){
        emit findPrevious(text, cs);
    } else {
        findNext(text, cs);
    }

}

void FindDialog::enableFindButton(const QString &text){
    findButton->setEnabled(!text.isEmpty());
}

FindDialog::~FindDialog()
{
}

