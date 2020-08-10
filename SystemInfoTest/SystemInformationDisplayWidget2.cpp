#include "SystemInformationDisplayWidget2.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QTextEdit>
#include <QPushButton>

SystemInformationDisplayWidget2::SystemInformationDisplayWidget2(QWidget *parent) :
    QWidget(parent)
{
    this->SetupUi();
}

void SystemInformationDisplayWidget2::SetupUi()
{
    this->setWindowTitle("System Information");
    this->setMinimumWidth(550);

    verticalLayout = new QVBoxLayout(this);
    verticalLayout->setObjectName(QStringLiteral("verticalLayout"));

    horizontalLayout = new QHBoxLayout();
    horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));

    CopyToClipboardPushButton = new QPushButton("Copy to clipboard",this);
    CopyToClipboardPushButton->setObjectName(QStringLiteral("CopyToClipboardPushButton"));

    horizontalLayout->addWidget(CopyToClipboardPushButton);

    verticalLayout->addLayout(horizontalLayout);

    textEdit = new QTextEdit(this);
    textEdit->setObjectName(QStringLiteral("textEdit"));
    textEdit->setMinimumHeight(500);

    verticalLayout->addWidget(textEdit);

    label = new QLabel(this);
    label->setObjectName(QStringLiteral("label"));
    label->setText("Please edit the above information as you see fit");

    verticalLayout->addWidget(label);

}

void SystemInformationDisplayWidget2::SetInformation(QStringList sl)
{
    foreach(QString str, sl)
    {
        this->textEdit->append(str);
    }
}
