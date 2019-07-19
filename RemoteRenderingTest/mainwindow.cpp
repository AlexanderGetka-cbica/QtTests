#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

	connect(ui->pushButtonLeft, SIGNAL(clicked()), this, SLOT(OnLoad3D()));
	connect(ui->pushButtonRight, SIGNAL(clicked()), this, SLOT(OnLoadImage()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SetUp3DViewPipeline()
{
	auto coneSource = vtkSmartPointer<vtkConeSource>::New();
	coneSource->Update();
	
	this->mapper =	vtkSmartPointer<vtkPolyDataMapper>::New();
	mapper->SetInputConnection(coneSource->GetOutputPort());

	this->actor = vtkSmartPointer<vtkActor>::New();
	actor->SetMapper(mapper);

	this->ren3D = vtkSmartPointer<vtkRenderer>::New();
	this->renWin3D = vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();
	this->ui->qvtkWidgetLeft->SetRenderWindow(this->renWin3D);
	this->renWin3D->AddRenderer(this->ren3D);

	this->ren3D->AddActor(actor);

	this->ui->qvtkWidgetLeft->update();
}

void MainWindow::SetupImageViewPipeline()
{

}

void MainWindow::OnLoadImage()
{

}

void MainWindow::OnLoad3D()
{
	this->SetUp3DViewPipeline();
}