#include "Cube/Cube3D.h"

CubeColor Cube3D::getSticker(Face face, int row, int col) const
{
	if(isCorner(row, col)){
		int corner = getCorner(face, row, col);//ULF
		int piece = this->m_cornerPermutation[corner];//5
		int orientation = this->m_cornerOrientation[corner];//0


		return getColor(piece, orientation, (int)face, cornerColors[piece]);
	}
	else if (row == 1 && col == 1) {//center
		return (CubeColor)face;
	}
	else {//edges
		int edge = getEdge(face, row, col);//ULF
		int piece = this->m_edgePermutation[edge];//5
		int orientation = this->m_edgeOrientation[edge];//0
		return getColor(piece, orientation, (int)face, edgeColors[piece]);
	}

	

}



bool Cube3D::isCorner(int row, int col) const
{
	if ((row == 0 && col == 0) || (row == 0 && col == 2)) return true;
	if ((row == 2 && col == 0) || (row == 2 && col == 2)) return true;
    return false;
}

int Cube3D::getEdge(Face face, int row, int col) const
{
	switch ((Face)face) {
	case Face::U:
		if (row == 0 && col == 1) return Edges::UB;
		if (row == 1 && col == 0) return Edges::UL;
		if (row == 1 && col == 2) return Edges::UR;
		if (row == 2 && col == 1) return Edges::UF;
		break;
	case Face::D:
		if (row == 0 && col == 1) return Edges::DB;
		if (row == 1 && col == 0) return Edges::DL;
		if (row == 1 && col == 2) return Edges::DR;
		if (row == 2 && col == 1) return Edges::DF;
		break;
	case Face::F:
		if (row == 0 && col == 1) return Edges::UF;
		if (row == 1 && col == 0) return Edges::FL;
		if (row == 1 && col == 2) return Edges::FR;
		if (row == 2 && col == 1) return Edges::DF;
		break;
	case Face::B:
		if (row == 0 && col == 1) return Edges::UB;
		if (row == 1 && col == 0) return Edges::BR;
		if (row == 1 && col == 2) return Edges::BL;
		if (row == 2 && col == 1) return Edges::DB;
		break;
	case Face::L:
		if (row == 0 && col == 1) return Edges::UL;
		if (row == 1 && col == 0) return Edges::BL;
		if (row == 1 && col == 2) return Edges::FL;
		if (row == 2 && col == 1) return Edges::DL;
		break;
	case Face::R:
		if (row == 0 && col == 1) return Edges::UR;
		if (row == 1 && col == 0) return Edges::FR;
		if (row == 1 && col == 2) return Edges::BR;
		if (row == 2 && col == 1) return Edges::DR;
		break;
	}
	return 0;
}


void Cube3D::setFromState(const CubeState& state) {
        for (int i = 0; i < 12; ++i) {
            m_edgePermutation[i] = state.permutation_arrete[i];
            m_edgeOrientation[i] = state.rotation_arrete[i];
        }
        for (int i = 0; i < 8; ++i) {
            m_cornerPermutation[i] = state.permutation_corner[i];
            m_cornerOrientation[i] = state.rotation_corner[i];
        }
    }