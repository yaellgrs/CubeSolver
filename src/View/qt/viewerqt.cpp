#include "View/qt/viewerqt.h"


void ViewerQT::Run(){

    this->app->exec();
}

void ViewerQT::Close()
{
    // Implémentation
}

void ViewerQT::drawCube()
{
    auto* s = window->getScene();
    s->clear();
    DrawFace(5, 150, 0);
    DrawFace(2, 0, 150);
    DrawFace(1, 150, 150);
    DrawFace(4, 300, 150);
    DrawFace(2, 450, 150);
    DrawFace(0, 150, 300);

//	std::vector<int> faceOrder = { 2, 1, 4, 3 };
}

void ViewerQT::DrawFace(int face, int xGap, int yGap){
    int n = m_cube->getOrder();
    for (int row = 0; row < n; ++row)
    {
        for (int col = 0; col < n; ++col)
        {
            CubeColor color = this->m_cube->getSticker((Face)face, row, col);

            // std::cout << colorToString(color) << " ";
            window->DrawSticker(xGap + 50*col, yGap + 50*row, 50, 50, toQColor(color));
        }

    }
}
