#include "ViewerTerminal.h"

const char* colorToString(CubeColor color)
{
    switch (color)
    {
    case CubeColor::White:  return "W";
    case CubeColor::Yellow: return "Y";
    case CubeColor::Green:  return "G";
    case CubeColor::Blue:   return "B";
    case CubeColor::Red:    return "R";
    case CubeColor::Orange: return "O";
    }

    return "Unknown";
}


void ViewerTerminal::drawCube()
{
    int n = m_cube->getOrder();
    for (int row = 0; row < n; ++row)
    {
        std::cout << "      ";
        for (int col = 0; col < n; ++col)
        {
            CubeColor color = this->m_cube->getSticker((Face)5, row, col);

            std::cout << colorToString(color) << " ";
        }

        std::cout << '\n';
    }
    std::cout << '\n';
	std::vector<int> faceOrder = { 2, 1, 4, 3 };
    for (int row = 0; row < n; row++) {
        for (int face : faceOrder) 
        {

            for (int col = 0; col < n; ++col)
            {
                CubeColor color = this->m_cube->getSticker((Face)face, row, col);

                std::cout << colorToString(color) << " ";
            }
            std::cout << "  ";
        }
        std::cout << '\n';
    }


    std::cout << '\n';
    std::cout << '\n';
    for (int row = 0; row <n; ++row)
    {
        std::cout << "      ";
        for (int col = 0; col < n; ++col)
        {
            CubeColor color = this->m_cube->getSticker((Face)0, row, col);

            std::cout << colorToString(color) << " ";
        }
        std::cout << '\n';
    }
}

