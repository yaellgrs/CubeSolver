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
    for (int row = 0; row < 2; ++row)
    {
        std::cout << "      ";
        for (int col = 0; col < 2; ++col)
        {
            CubeColor color = this->m_cube->getSticker((Face)5, row, col);

            std::cout << colorToString(color) << " ";
        }

        std::cout << '\n';
    }
    std::cout << '\n';
	std::vector<int> faceOrdrer = { 2, 1, 4, 3 };
    for (int i : faceOrdrer)
    {

            for (int col = 0; col < 2; ++col)
            {
                CubeColor color = this->m_cube->getSticker((Face)i, 0, col);

                std::cout << colorToString(color) << " ";
            }
            std::cout << "  ";
    }
    std::cout << '\n';
    for (int i : faceOrdrer)
    {

        for (int col = 0; col < 2; ++col)
        {
            CubeColor color = this->m_cube->getSticker((Face)i, 1, col);

            std::cout << colorToString(color) << " ";
        }
        std::cout << "  ";
    }
    std::cout << '\n';
    std::cout << '\n';
    for (int row = 0; row < 2; ++row)
    {
        std::cout << "      ";
        for (int col = 0; col < 2; ++col)
        {
            CubeColor color = this->m_cube->getSticker((Face)1, row, col);

            std::cout << colorToString(color) << " ";
        }
        std::cout << '\n';
    }
}

