#ifndef VIEWERQT_H
#define VIEWERQT_H

#include <QApplication>

#include "View/IViewer.h"
#include "View/qt/mainwindow.h"

class ViewerQT : public IViewer
{
private:
    MainWindow* window;
    QApplication* app;

public:
    ViewerQT(int& argc, char** argv, ICube* cube) : IViewer(cube){
        this->app = new QApplication(argc, argv);
        this->window = new MainWindow();
        this->window->show();
        this->window->showMaximized();


    }

    void Run();
    void Close();

    virtual void drawCube() override;
private:
    void DrawFace(int face, int xGap, int yGap);


};

#endif // VIEWERQT_H
