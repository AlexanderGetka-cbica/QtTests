#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

//vtk
#include "vtkSmartPointer.h"
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include "vtkGenericOpenGLRenderWindow.h"
#include <vtkNew.h>
#include <vtkPolyDataMapper.h>
#include <vtkSphereSource.h>
#include <vtkActor.h>
#include <vtkConeSource.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
	void OnLoadImage();
	void OnLoad3D();

protected:
	void SetUp3DViewPipeline();
	void SetupImageViewPipeline();

private:
    Ui::MainWindow *ui;

	//vtk stuff
	vtkSmartPointer<vtkGenericOpenGLRenderWindow> renWinImage;
	vtkSmartPointer<vtkRenderer> renImage;
	vtkSmartPointer<vtkRenderWindowInteractor> irenImage;

	vtkSmartPointer<vtkGenericOpenGLRenderWindow> renWin3D;
	vtkSmartPointer<vtkRenderer> ren3D;
	vtkSmartPointer<vtkRenderWindowInteractor> iren3D;

	vtkSmartPointer<vtkConeSource> coneSource;
	vtkSmartPointer<vtkPolyDataMapper> mapper;
	vtkSmartPointer<vtkActor> actor;
};

#endif // MAINWINDOW_H
