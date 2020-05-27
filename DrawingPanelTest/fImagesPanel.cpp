///////////////////////////////////////////////////////////////////////////////////////
// fImagesPanel.cxx
//
// Copyright (c) 2018. All rights reserved.
// Section of Biomedical Image Analysis
// Center for Biomedical Image Computing and Analytics
// Department of Radiology
// Perelman School of Medicine
// University of Pennsylvania
//
// Contact details: software@cbica.upenn.edu
//
// License Agreement: https://www.med.upenn.edu/sbia/software-agreement.html
///////////////////////////////////////////////////////////////////////////////////////

#include "fImagesPanel.h"
//#include "CAPTk.h"
#include "CaPTkEnums.h"
//#include "CaPTkUtils.h"
#include <QFileInfo>
#include <QEvent>
#include <QMouseEvent>
#include <QRadioButton>
#include <QDebug>
#include "myradiobutton.h"
#include "radiobuttontableitem.h"

fImagesPanel::fImagesPanel(QWidget * parent) : QWidget(parent)
{
  setupUi(this);
  m_imagesTable->viewport()->setFocusPolicy(Qt::NoFocus);

  //m_imagesTable->viewport()->installEventFilter(this);
  //connect(m_imagesTable, SIGNAL(itemSelectionChanged()), this, SLOT(ImageTableSelectionChanged()));
  //connect(m_imagesTable, SIGNAL(itemClicked(QTableWidgetItem*)), this, SLOT(ImageTableSelectionChanged(QTableWidgetItem*)));
//  connect(m_imagesTable,
//          SIGNAL(currentItemChanged(QTableWidgetItem *, QTableWidgetItem *)),
//          this, SLOT(OncurrentItemChanged(QTableWidgetItem *, QTableWidgetItem *)));
  //connect(m_imagesTable,SIGNAL(cellClicked(int,int)),this, SLOT(OnCellClicked(int,int)));
  m_overlayChkBox->setEnabled(true);

  connect(m_overlayChkBox, SIGNAL(stateChanged(int)), this, SLOT(overlayUseStateChanged(int)));
  connect(m_overlaySlider, SIGNAL(valueChanged(int)), this, SLOT(overlaySliderChanged(int)));
  connect(m_3dViz, SIGNAL(clicked()), this, SLOT(theiaClicked()));
  connect(m_CompareButton, SIGNAL(toggled(bool)), this, SIGNAL(CompareModeToggled(bool)));
  connect(HelpButton, SIGNAL(clicked()), this, SLOT(helpClicked()));
}

void fImagesPanel::ImageTableSelectionChanged()
{
    qDebug() << "fImagesPanel::ImageTableSelectionChanged()" << endl;

  emit sigImageTableSelectionChanged();
  if (m_overlayChkBox->isChecked() && getSelectedOverlay() != NULL)
  {
    emit overlayChanged();
  }
}
void fImagesPanel::overlayUseStateChanged(int value)
{
  m_overlaySlider->setEnabled(value);
  emit sigOverlayCheckBoxChanged(value);
}
void fImagesPanel::overlayChanged()
{
    qDebug() << "fImagesPanel::overlayChanged()" << endl;

    int r = m_imagesTable->currentRow();
    qDebug() << " current row = " << r << endl;
    //m_imagesTable->blockSignals(true);
  emit sigOverlayChanged();
    //m_imagesTable->blockSignals(false);
}
void fImagesPanel::overlaySliderChanged(int value)
{
    qDebug() << "fImagesPanel::overlaySliderChanged(int value)" << endl;
  emit sigOverlaySliderChanged(value);
}
void fImagesPanel::imageModalityChanged(int value)
{
    qDebug() << "fImagesPanel::imageModalityChanged(int value)" << endl;
  emit sigImageModalityChanged(value);
}

void fImagesPanel::theiaClicked()
{
    emit sigTheiaClicked();
}

void fImagesPanel::OncurrentItemChanged(QTableWidgetItem *current, QTableWidgetItem *previous)
{
    qDebug() << "OncurrentItemChanged(QTableWidgetItem *current, QTableWidgetItem *previous)" << endl;
    qDebug() << " current row = " << m_imagesTable->row(current);
    qDebug() << " previous row = " << m_imagesTable->row(previous);
}

void fImagesPanel::OnCellClicked(int row, int col)
{
    QRadioButton *rb = qobject_cast<QRadioButton*>(m_imagesTable->cellWidget(row, col));
    if(rb)
    {
        qDebug() << " radiobutton clicked at cell = " << row << "," << col << endl;
        rb->click();
    }
}

void fImagesPanel::ImageTableSelectionChanged(QTableWidgetItem*)
{
    qDebug() << "fImagesPanel::ImageTableSelectionChanged(QTableWidgetItem*)" << endl;
}

void fImagesPanel::CompareButtonClick()
{
  this->m_CompareButton->click();
}

void fImagesPanel::NewImageLoaded(QString idstr, const std::string &filename, int rowIndex, const std::string &imageSubTypeStr, const int imgSubtype, const QObject* caller)
{
  m_imagesTable->setRowCount(rowIndex + 1);
  QFileInfo fileinfo(filename.c_str());

  QTableWidgetItem *item1 = new QTableWidgetItem(filename.c_str());
  item1->setData(Qt::UserRole, idstr.toStdString().c_str());
  item1->setFlags(item1->flags() &  ~Qt::ItemIsEditable);

  QTablePushButton* cButton1 = new QTablePushButton;
  cButton1->setItem(item1);
  cButton1->setText(tr("X"));
  connect(cButton1, SIGNAL(clickedInto(QTableWidgetItem*)), caller, SLOT(CloseImage(QTableWidgetItem*)));


  QLabel * label1 = new QLabel;
  label1->setText(QString::fromStdString(imageSubTypeStr));
  m_imagesTable->setCellWidget(rowIndex, IMAGES_COLUMN_CLOSE, cButton1);
  m_imagesTable->setCellWidget(rowIndex, IMAGES_COLUMN_TYPE, label1);
  m_imagesTable->setItem(rowIndex, IMAGES_COLUMN_NAME, item1);

  // TBD: this needs to pick up from ImageModalityType & ImageModalityString from CAPTk.h and not be hard-coded 
  auto modalitySwitcher = new QComboBox;
  modalitySwitcher->setToolTip(QString("Select the Image Modality"));
  for (int i = 0; i < CAPTK::ImageModalityType::IMAGE_TYPE_FEATURES + 1; i++)
  {
    modalitySwitcher->insertItem(i, CAPTK::ImageModalityString[i]);
  }

  //modalitySwitcher->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
  //int buttonWidth = QLabel().fontMetrics().width("----------------");
  //modalitySwitcher->setFixedWidth(buttonWidth);
  if (imgSubtype < modalitySwitcher->count())
  {
    modalitySwitcher->setCurrentIndex(imgSubtype);
  }
  m_imagesTable->setCellWidget(rowIndex, IMAGES_COLUMN_MODALITY, modalitySwitcher);

  RadioButtonTableItem *overlayRB = new RadioButtonTableItem();
  //QRadioButton* overlayRB = new QRadioButton();
  //overlayRB->setFocusPolicy(Qt::NoFocus);
  //MyRadioButton *filter = new MyRadioButton();
  //overlayRB->installEventFilter(this);
  //m_image
  //QCoreApplication::instance()->installEventFilter(this);
  m_imagesTable->setCellWidget(rowIndex, IMAGES_COLUMN_OVERLAY, overlayRB);

  QTableWidgetItem *item2 = new QTableWidgetItem(filename.c_str());
  item2->setData(Qt::UserRole, idstr.toStdString().c_str());

  QTablePushButton* cButton2 = new QTablePushButton;
  cButton2->setItem(item2);
  cButton2->setText(tr("X"));
  cButton2->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);

  connect(cButton2, SIGNAL(clickedInto(QTableWidgetItem*)), caller, SLOT(CloseImage(QTableWidgetItem*)));
  connect(modalitySwitcher, SIGNAL(currentIndexChanged(int)), this, SLOT(imageModalityChanged(int)));
  //m_imagesTable->blockSignals(true);
  connect(overlayRB, SIGNAL(clicked()), this, SLOT(overlayChanged()));
  //m_imagesTable->blockSignals(false);
  connect(m_clearImagesBtn, SIGNAL(clicked()), caller, SLOT(CloseAllImages()));//TBD fix calling everytime
  
  //! tell table to resize to contents after we add stuff into the table
  m_imagesTable->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
  m_imagesTable->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
}

void fImagesPanel::AddDummyItem(QString idstr, const std::string &filename, int rowIndex, const std::string &imageSubTypeStr, const int imgSubtype, const QObject *caller)
{
    m_imagesTable->setRowCount(rowIndex + 1);
    QFileInfo fileinfo(filename.c_str());

//    QTableWidgetItem *item1 = new QTableWidgetItem(filename.c_str());
//    item1->setData(Qt::UserRole, idstr.toStdString().c_str());
//    item1->setFlags(item1->flags() &  ~Qt::ItemIsEditable);

//    QTablePushButton* cButton1 = new QTablePushButton;
//    cButton1->setItem(item1);
//    cButton1->setText(tr("X"));
//    connect(cButton1, SIGNAL(clickedInto(QTableWidgetItem*)), caller, SLOT(CloseImage(QTableWidgetItem*)));

    QTableWidgetItem *item1 = new QTableWidgetItem("Close");
    item1->setData(Qt::UserRole, idstr.toStdString().c_str());
    item1->setFlags(item1->flags() &  ~Qt::ItemIsEditable);


    QTableWidgetItem *item2 = new QTableWidgetItem(imageSubTypeStr.c_str());
    item2->setData(Qt::UserRole, idstr.toStdString().c_str());
    item2->setFlags(item2->flags() &  ~Qt::ItemIsEditable);


    QTableWidgetItem *item3 = new QTableWidgetItem(filename.c_str());
    item3->setData(Qt::UserRole, idstr.toStdString().c_str());
    item3->setFlags(item3->flags() &  ~Qt::ItemIsEditable);

    QTableWidgetItem *item4 = new QTableWidgetItem(CAPTK::ImageModalityString[imgSubtype]);
    item4->setData(Qt::UserRole, idstr.toStdString().c_str());
    item4->setFlags(item4->flags() &  ~Qt::ItemIsEditable);

//    QTableWidgetItem *item5 = new QTableWidgetItem("Overlay" + QString::number(rowIndex));

    RadioButtonTableItem *item5 = new RadioButtonTableItem();
    item5->setFocusPolicy(Qt::NoFocus);
//    item5->setData(Qt::UserRole, idstr.toStdString().c_str());
//    item5->setFlags(item5->flags() &  ~Qt::ItemIsEditable);

    //QRadioButton* item5 = new QRadioButton();

    //QLabel * label1 = new QLabel;
    //label1->setText(QString::fromStdString(imageSubTypeStr));
    m_imagesTable->setItem(rowIndex, IMAGES_COLUMN_CLOSE, item1);
    m_imagesTable->setItem(rowIndex, IMAGES_COLUMN_TYPE, item2);
    m_imagesTable->setItem(rowIndex, IMAGES_COLUMN_NAME, item3);
    m_imagesTable->setItem(rowIndex, IMAGES_COLUMN_MODALITY, item4);
//    m_imagesTable->setCellWidget(rowIndex, IMAGES_COLUMN_OVERLAY, item5);
    m_imagesTable->setCellWidget(rowIndex, IMAGES_COLUMN_OVERLAY, item5);
//    m_imagesTable->setItem(rowIndex, IMAGES_COLUMN_OVERLAY, item5);



    // TBD: this needs to pick up from ImageModalityType & ImageModalityString from CAPTk.h and not be hard-coded
//    auto modalitySwitcher = new QComboBox;
//    modalitySwitcher->setToolTip(QString("Select the Image Modality"));
//    for (int i = 0; i < CAPTK::ImageModalityType::IMAGE_TYPE_FEATURES + 1; i++)
//    {
//      modalitySwitcher->insertItem(i, CAPTK::ImageModalityString[i]);
//    }

//    //modalitySwitcher->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
//    //int buttonWidth = QLabel().fontMetrics().width("----------------");
//    //modalitySwitcher->setFixedWidth(buttonWidth);
//    if (imgSubtype < modalitySwitcher->count())
//    {
//      modalitySwitcher->setCurrentIndex(imgSubtype);
//    }
//    m_imagesTable->setCellWidget(rowIndex, IMAGES_COLUMN_MODALITY, modalitySwitcher);

//    RadioButtonTableItem *overlayRB = new RadioButtonTableItem();
//    //QRadioButton* overlayRB = new QRadioButton();
//    //MyRadioButton *filter = new MyRadioButton();
//    //overlayRB->installEventFilter(this);
//    //m_image
//    //QCoreApplication::instance()->installEventFilter(this);
//    m_imagesTable->setCellWidget(rowIndex, IMAGES_COLUMN_OVERLAY, overlayRB);

//    QTableWidgetItem *item2 = new QTableWidgetItem(filename.c_str());
//    item2->setData(Qt::UserRole, idstr.toStdString().c_str());

//    QTablePushButton* cButton2 = new QTablePushButton;
//    cButton2->setItem(item2);
//    cButton2->setText(tr("X"));
//    cButton2->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);

//    connect(cButton2, SIGNAL(clickedInto(QTableWidgetItem*)), caller, SLOT(CloseImage(QTableWidgetItem*)));
//    connect(modalitySwitcher, SIGNAL(currentIndexChanged(int)), this, SLOT(imageModalityChanged(int)));
//    //m_imagesTable->blockSignals(true);
//    connect(overlayRB, SIGNAL(clicked()), this, SLOT(overlayChanged()));
//    //m_imagesTable->blockSignals(false);
//    connect(m_clearImagesBtn, SIGNAL(clicked()), caller, SLOT(CloseAllImages()));//TBD fix calling everytime

    //! tell table to resize to contents after we add stuff into the table
    m_imagesTable->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    m_imagesTable->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
}

//! images table event filter
//bool fImagesPanel::eventFilter(QObject *object, QEvent *event)
//{
//    //qDebug() << "fImagesPanel::eventFilter" << endl;
//    if(object == m_imagesTable->viewport() && event->type() == QEvent::MouseButtonPress)
//    {
//        QMouseEvent *me = static_cast<QMouseEvent *>(event);
//        if(me->button() == Qt::LeftButton)
//        {
//            QModelIndex i = m_imagesTable->indexAt(me->pos());
//            if(i.column() == 4)
//            {
//                qDebug() << " left mouse button pressed" << endl;
//                int row = i.row();
//                int col = i.column();
//                QRadioButton *rb = qobject_cast<QRadioButton*>(m_imagesTable->cellWidget(row, col));
//                if(rb)
//                {
//                    qDebug() << " radiobutton clicked at cell = " << row << "," << col << endl;
//                    //rb->;
//                }
//                return true;
//            }
//        }
//    }
//    //return false;
//}

//radiobutton event filter
//bool fImagesPanel::eventFilter(QObject *object, QEvent *event)
//{
//    //qDebug() << "fImagesPanel::eventFilter" << endl;
//    if(/*object == m_imagesTable->viewport() && */event->type() == QEvent::MouseButtonPress)
//    {
//        QMouseEvent *me = static_cast<QMouseEvent *>(event);
//        if(me->button() == Qt::LeftButton)
//        {
//            //QRadioButton *rb = qobject_cast<QRadioButton*>(object);
//            QModelIndex i = m_imagesTable->indexAt(me->pos());
//            int row = i.row();
//            int col = i.column();
//            if(i.column() == 4)
//            {
//                qDebug() << " left mouse button pressed" << endl;
//                //int row = i.row();
//                //int col = i.column();
//                //MyRadioButton *rb = qobject_cast<MyRadioButton*>(object);
//                //if(rb)
//                {
//                    //rb->setAttribute(Qt::WA_NoMousePropagation);
//                    //qDebug() << " radiobutton clicked " << endl;
//                    qDebug() << " radiobutton clicked at cell = " << row << "," << col << endl;
//                    //rb->click();
//                }
//                event->accept();
//                return true;
//            }
//        }
//    }
//    return false;
//}

void fImagesPanel::helpClicked()
{
  emit helpClicked_Interaction("Getting_Started.html");
} 
