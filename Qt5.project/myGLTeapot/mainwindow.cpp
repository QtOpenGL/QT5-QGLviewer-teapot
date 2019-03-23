#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace qglviewer;
//using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    viewer = new Viewer();

    QLayout *layout = ui->horizontalLayoutQGL;
    layout->addWidget(viewer);

    viewer->setGridIsDrawn();
    viewer->setAxisIsDrawn();

    viewer->frameTeapot = new Frame(Vec(-2,-2,0), Quaternion(Vec(0,0,0), Vec(0,0,1)));

    viewer->camera()->setSceneRadius(4);
    viewer->showEntireScene();
    viewer->mfScale = 0.5f;

    viewer->show();




    if (viewer) {
        int iDegree1 = viewer->mfRotationRad[0]*180.0f/3.14f;
        ui->horizontalSlider1->setRange(-180,180);
        ui->horizontalSlider1->setValue(iDegree1);


        int iDegree2 = viewer->mfRotationRad[1]*180.0f/3.14f;
        ui->horizontalSlider2->setRange(-180,180);
        ui->horizontalSlider2->setValue(iDegree2);

        int iDegree3 = viewer->mfRotationRad[2]*180.0f/3.14f;
        ui->horizontalSlider3->setRange(-180,180);
        ui->horizontalSlider3->setValue(iDegree3);


        }


    //Do some fun
    timer = new QTimer();
    timer->start(100);
    connect(timer, &QTimer::timeout, [=](){
        //Change Axis
        qglviewer::Vec axis;
        if (ui->radioButtonX->isChecked())
            axis = qglviewer::Vec(1.0, 0.0, 0.0);
        else if (ui->radioButtonY->isChecked())
            axis = qglviewer::Vec(0.0, 1.0, 0.0);
        else if (ui->radioButtonZ->isChecked())
            axis = qglviewer::Vec(0.0, 0.0, 1.0);
        //Rotate on Axis
        viewer->frameTeapot->rotate(Quaternion(axis, -0.314));
        viewer->update();
        });

}

MainWindow::~MainWindow()
{
    delete ui;
}


/*
 *  Base on AxisZ
 *
Letter   Description  Escape-Sequence
-------------------------------------
A        Alpha        \u0391
B        Beta         \u0392
Γ        Gamma        \u0393
Δ        Delta        \u0394
Ε        Epsilon      \u0395
Ζ        Zeta         \u0396
Η        Eta          \u0397
Θ        Theta        \u0398
Ι        Iota         \u0399
Κ        Kappa        \u039A
Λ        Lambda       \u039B
Μ        Mu           \u039C
Ν        Nu           \u039D
Ξ        Xi           \u039E
Ο        Omicron      \u039F
Π        Pi           \u03A0
Ρ        Rho          \u03A1
Σ        Sigma        \u03A3
Τ        Tau          \u03A4
Υ        Upsilon      \u03A5
Φ        Phi          \u03A6
Χ        Chi          \u03A7
Ψ        Psi          \u03A8
Ω        Omega        \u03A9
 */
void MainWindow::on_horizontalSlider1_valueChanged(int deg)
{
    qDebug() << Q_FUNC_INFO;
    if (viewer) {
        float fRad = (deg*3.14f)/180.0f;
        viewer->mfRotationRad[0] = fRad;
        viewer->frameTeapot->setRotation(Quaternion(qglviewer::Vec(1.0, 0.0, 0.0),fRad));
        viewer->update();
qDebug() << fRad;
        QString text;
        text.sprintf("%+06.3f,%+4d", fRad, deg);
        ui->labelBase->setText(QString("X(%1,%2):%3°").arg("\u03A0").arg("\u03A6").arg(text) );
        }
}
/*
 * Arm1 on AxisX
 */
void MainWindow::on_horizontalSlider2_valueChanged(int value)
{
    qDebug() << Q_FUNC_INFO;
    if (viewer) {
        float fRad = (value/180.0f)*3.14f;
        viewer->mfRotationRad[0] = fRad;
        viewer->frameTeapot->setRotation(Quaternion(qglviewer::Vec(0.0, 1.0, 0.0), fRad));
        viewer->update();

        QString text;
        text.sprintf("%+06.3f,%+4d", fRad, value);
        ui->labelArm1->setText(QString("Y(%1,%2):%3°").arg("\u03A0").arg("\u03A6").arg(text) );
         }
}
/*
 * Arm2 on AxisX
 */
void MainWindow::on_horizontalSlider3_valueChanged(int value)
{
    qDebug() << Q_FUNC_INFO;
    if (viewer) {
        float fRad = (value/180.0f)*3.14f;
        viewer->mfRotationRad[0] = fRad;
        viewer->frameTeapot->setRotation(Quaternion(qglviewer::Vec(0.0, 0.0, 1.0), fRad));
        viewer->update();

        QString text;
        text.sprintf("%+06.3f,%+4d", fRad, value);
        ui->labelArm2->setText(QString("Z(%1,%2):%3°").arg("\u03A0").arg("\u03A6").arg(text) );
         }
}

