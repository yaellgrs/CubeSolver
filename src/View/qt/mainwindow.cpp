#include "View/qt/mainwindow.h"
#include "ui_mainwindow.h"

#include <QGraphicsScene>
#include <QGraphicsRectItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    auto* scene = new QGraphicsScene(this);
    ui->Cube->setScene(scene);

    // un carré rouge avec contour noir
    ui->Cube->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    scene->addRect(0, 50, 50, 50, QPen(Qt::black), QBrush(Qt::red));


}

MainWindow::~MainWindow()
{
    delete ui;
}
