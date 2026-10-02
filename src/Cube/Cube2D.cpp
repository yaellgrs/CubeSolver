#include "Cube/Cube2D.h"

CubeColor Cube2D::getSticker(Face face, int row, int col) const
{

	int corner = getCorner(face, row, col);//ULF
	int piece = this->m_cornerPermutation[corner];//5
	int orientation = this->m_cornerOrientation[corner];//0


	return getColor(piece, orientation, (int)face, cornerColors[piece]);
}



