#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QTimer>
#include "gl_viewer.h"

namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Viewer *viewer;

    float x,y,z;
    QTimer *timer;

private:
    Ui::MainWindow *ui;


private slots:
    void on_horizontalSlider1_valueChanged(int value);
    void on_horizontalSlider2_valueChanged(int value);
    void on_horizontalSlider3_valueChanged(int value);

};

#endif // MAINWINDOW_H
