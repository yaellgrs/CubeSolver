#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QMainWindow>
#include <QShortcut>
#include <QGraphicsScene>
#include "Model/CubeState.h"
#include "Model/Mouvement.hpp"
#include "Cube/Cube3D.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void DrawSticker(int x, int y, int w, int h, QColor color);

private:
    QGraphicsScene* scene;
    Ui::MainWindow *ui;
    CubeState *m_state;
    Cube3D *m_cube;

    void apply(Mouvement m);
    void drawCube();
    void DrawFace(int face, int xGap, int yGap);

public:
    QGraphicsScene* getScene(){ return this->scene; }
};

#endif // MAINWINDOW_H
