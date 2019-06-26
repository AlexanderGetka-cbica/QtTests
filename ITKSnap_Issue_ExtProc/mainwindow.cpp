#include "mainwindow.h"
#include "ui_mainwindow.h"

//vtk
#include <vtkConeSource.h>
#include <vtkPolyData.h>
#include <vtkSmartPointer.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkRenderWindowInteractor.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->StartVTKRendering();

    QObject::connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(startExternalProcess()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::StartVTKRendering()
{
    //Create a cone
    vtkSmartPointer<vtkConeSource> coneSource = vtkSmartPointer<vtkConeSource>::New();
    coneSource->Update();

    //Create a mapper and actor
    vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    mapper->SetInputConnection(coneSource->GetOutputPort());

    vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
    actor->SetMapper(mapper);

    //Create a renderer, render window, and interactor
    vtkSmartPointer<vtkRenderer> renderer = vtkSmartPointer<vtkRenderer>::New();
    vtkSmartPointer<vtkGenericOpenGLRenderWindow> renderWindow = vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();
    ui->qvtkwidget->SetRenderWindow(renderWindow);

    renderWindow->AddRenderer(renderer);
    renderWindow->SetInteractor(ui->qvtkwidget->GetInteractor());

    //Add the actors to the scene
    renderer->AddActor(actor);
    renderer->SetBackground(.3, .2, .1); // Background color dark red

}

int MainWindow::startExternalProcess()
{
  //int returnVal = std::system((application.toStdString() + " " + arguments.join(" ").toStdString()).c_str());
  int returnVal = std::system("C:/Projects/CaPTk/bin/Debug/itksnap.bat -w C:/Users/SinghAs/.CaPTk/1.7.1.RC/tmp_18430746346455574741/testXML.itksnap");
  return returnVal;
}
