///////////////////////////////////////////////////////////////////////////////////////
// fDrawingPanel.h
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

#ifndef _fDrawingPanel_h_
#define _fDrawingPanel_h_

#include "ui_fDrawingPanel.h"
#include <QMessageBox>

/**
\class fDrawingPanel

\brief This class controls the elements in the drawing panel of the tab
*/
class fDrawingPanel : public QWidget, private Ui::fDrawingPanel
{
  Q_OBJECT

public:

    enum SHAPE_MODE
    {
      SHAPE_MODE_NONE = 0, SHAPE_MODE_ERASER, SHAPE_MODE_FREE_HAND, SHAPE_MODE_LINE, SHAPE_MODE_RECTANGLE, SHAPE_MODE_CIRCLE, SHAPE_MODE_FILL, SHAPE_MODE_SPHERE
    };

  //! Constructor
  fDrawingPanel(QWidget * parent = 0);

  //! Destructor
  ~fDrawingPanel() {}
  int getSelectedDrawLabel()
  {
    if (labelSelectorBox != NULL)
    {
      return labelSelectorBox->currentIndex()+1;
    }
    return 1;
  }
  int getSelectedDrawSize()
  {
    if (sizeComboBox != NULL)
    {
      return sizeComboBox->currentIndex();
    }
    return 0;
  }
  void enableShapeButton(QPushButton* button)
  {
    for (int i = 0; i < shapeButtons.size(); i++)
    {
      if (shapeButtons[i] == button)
      {
        shapeButtons[i]->setChecked(true);
      }
      else
      {
        shapeButtons[i]->setChecked(false);
      }
    }
  }

  int getCurrentOpacity() { return m_currentOpacity; };

  inline void ShowErrorMessage(const std::string &message, QWidget *boxParent = NULL, const std::string &windowTitle = "Error")
  {
    if (boxParent == NULL)
    {
      QMessageBox *box = new QMessageBox();
      box->setIcon(QMessageBox::Information);
      box->addButton(QMessageBox::Ok);
      box->setText(QString(message.c_str()));
      box->setWindowTitle(QString(windowTitle.c_str()));
      box->setAttribute(Qt::WA_DeleteOnClose); //makes sure the msgbox is deleted automatically when closed
      box->exec();
    }
    else
    {
      QMessageBox *box = new QMessageBox(boxParent);
      box->setIcon(QMessageBox::Information);
      box->addButton(QMessageBox::Ok);
      box->setText(QString(message.c_str()));
      box->setWindowTitle(QString(windowTitle.c_str()));
      box->setAttribute(Qt::WA_DeleteOnClose); //makes sure the msgbox is deleted automatically when closed
      box->exec();
    }
  }

signals :
  void clearMask(int label=-1);
  void UndoButtonClicked();
  void FillButtonClicked(int);
  void shapesButtonClicked(int mode);
  void CurrentBrushSizeChanged(int);
  void CurrentDrawingLabelChanged(int); // multiLabel related change
  void CurrentMaskOpacityChanged(int); // multiLabel related change
  void helpClicked_Interaction(std::string);
  void sig_ChangeLabelValuesClicked(const std::string, const std::string);


public slots :

  //! Enable voxel based erase functionality
  void shapeEraceButtonFunctionality();

  //! Erase selected label
  void clearSelectedLabelButtonFunctionality();
  
  //! Erase all labels
  void clearAllLabelButtonFunctionality();
  
  //! Change in the size of drawing/erasing brush
  void CurrentSizeChanged(int size);

  //! Change the current selected label
  void CurrentLabelChanged(int size);

  //! Change the current mask opacity
  void CurrentOpacityChanged(int size);

  //! Undo drawing actions
  void UndoButtonFunctionality(); 

  //! Fill button action
  void FillButtonFunctionality();

  //! Draw Shapes
  void shapesNoneButtonFunctionality();
  void shapesLineButtonFunctionality();
  void shapeFreeHandButtonFunctionality();
  void shapesRectangleButtonFunctionality();
  void shapesCircleButtonFunctionality();
  void shapesSphereButtonFunctionality();
  void helpClicked();

  void ChangeLabelValuesClicked();

private:
  int m_currentOpacity; // set default to the tenth spinbox selection (1.0 mask opacity)
};


#endif
