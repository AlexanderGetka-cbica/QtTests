#include "dialog.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QWheelEvent>
//#include <QWebEngineView>
#include <QWidget>
#include <QCheckBox>
#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QSlider>
#include "ui_dialog.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QCheckBox>
#include <QSpacerItem>
#include <QSizePolicy>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
//    //---
//    verticalLayout = new QVBoxLayout(this);
//    //verticalLayout->setSpacing(6);
//    //verticalLayout->setContentsMargins(11, 11, 11, 11);
//    //verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
//    widget = new QWidget(this);
//    //widget->setObjectName(QStringLiteral("widget"));
//    widget->setStyleSheet(QStringLiteral("background-color: rgb(28, 255, 218);"));

//    verticalLayout->addWidget(widget);

//    horizontalLayout = new QHBoxLayout();
//    //horizontalLayout->setSpacing(7);
//    //horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
//    //horizontalLayout->setSizeConstraint(QLayout::SetMinimumSize);
//    checkBox = new QCheckBox();
//    //checkBox->setObjectName(QStringLiteral("checkBox"));

//    horizontalLayout->addWidget(checkBox);

//    horizontalSpacer = new QSpacerItem(40, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

//    horizontalLayout->addItem(horizontalSpacer);

//    zoomValueLabel = new QLabel();
//    zoomValueLabel->setText("Text");

//    horizontalLayout->addWidget(zoomValueLabel);

//    percentLabel = new QLabel();
//    percentLabel->setText("100");

//    horizontalLayout->addWidget(percentLabel);

//    pushButton = new QPushButton();
//    //pushButton->setObjectName(QStringLiteral("pushButton"));
//    //pushButton->setMaximumSize(QSize(28, 16777215));

//    horizontalLayout->addWidget(pushButton);

//    horizontalSlider = new QSlider();
//    //horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
//    horizontalSlider->setOrientation(Qt::Horizontal);

//    horizontalLayout->addWidget(horizontalSlider);

//    pushButton_2 = new QPushButton();
//    //pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
//    //pushButton_2->setMaximumSize(QSize(28, 16777215));

//    horizontalLayout->addWidget(pushButton_2);


//    verticalLayout->addLayout(horizontalLayout);
//    //---

    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    QHBoxLayout *toolbar = new QHBoxLayout();

     checkBox = new QCheckBox();
     checkBox->setObjectName("confirmationCheckBox");
     checkBox->setText("Never show again");
     checkBox->setChecked(false);

     //m_webView = new QWebEngineView(this);
     widget = new QWidget(this);
     //widget->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
     widget->setStyleSheet("background-color: rgb(255, 215, 135);");
     //m_webView->setBackgroundColor(Qt:);

     this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);

     pushButton = new QPushButton();
     pushButton_2 = new QPushButton();
     horizontalSlider = new QSlider(Qt::Orientation::Horizontal);
     zoomValueLabel = new QLabel();
     zoomValueLabel->setText("100");
     //zoomValueLabel->setMaximumHeight(28);

     percentLabel = new QLabel();

     toolbar->addWidget(checkBox);
     toolbar->addStretch();
     toolbar->addWidget(pushButton);
     toolbar->addWidget(horizontalSlider);
     toolbar->addWidget(pushButton_2);
     toolbar->addWidget(zoomValueLabel);
     //toolbar->addWidget(percentLabel);

     mainLayout->addWidget(widget);
     mainLayout->addLayout(toolbar);
     //this->setLayout(mainLayout);
}

Dialog::~Dialog()
{
    delete ui;
}
